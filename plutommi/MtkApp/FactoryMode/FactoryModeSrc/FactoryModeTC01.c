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
 * FactoryModeSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_TC01_CAMERA_TEST__

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 

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
#include "FileMgrSrvGProt.h"

/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
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

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
#include "l1audio.h"
#endif

#include "dcl.h"

#if defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)
#include "Msdc_def.h"
#endif 

#include "init.h"
#include "device.h"
#include "custom_em.h"
#ifdef __MMI_FM_KEYPAD_TEST__
#include "custom_fm.h"
#endif
#include "custom_equipment.h"
#include "nvram_data_items.h"
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
#include  "stack_msgs.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "lcd_if.h"
#include "lcd_sw_rnd.h" /* LCD layer enable flag */
#include "mdi_datatype.h"
#include "med_api.h"    /* media task camera module */
#include "MMI_features_camera.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "image_sensor.h"

#include "ATHandlerProt.h"

typedef enum
{
    MMI_FM_TEST_CAM_INIT = 0,
    MMI_FM_TEST_CAM_PREVIEW = 1,
    MMI_FM_TEST_CAM_SHOT = 2,        
    MMI_FM_TEST_CAM_SAVE = 3,
    MMI_FM_TEST_CAM_SHOW_IMAGE = 4,
    MMI_FM_TEST_CAM_DEL_ALL_IMG = 5,
    MMI_FM_TEST_CAM_FLASH_ON = 6,
    MMI_FM_TEST_CAM_FLASH_OFF = 7,
    MMI_FM_TEST_CAM_STROBE_ON = 8,
    MMI_FM_TEST_CAM_STROBE_OFF = 9,
    MMI_FM_TEST_CAM_SWITCH_SENSOR = 10,
    MMI_FM_TEST_CAM_ZOOM_IN = 11,
    MMI_FM_TEST_CAM_ZOOM_OUT = 12,
    MMI_FM_TEST_CAM_END
} mmi_fm_test_cam_enum;


typedef enum
{
    MMI_FM_TEST_AVR_INIT = 0,
    MMI_FM_TEST_AVR_PREVIEW = 1,
    MMI_FM_TEST_AVR_SHOT = 2,        
    MMI_FM_TEST_AVR_SAVE = 3,
    MMI_FM_TEST_AVR_SHOW_VIDEO = 4,
    MMI_FM_TEST_AVR_DEL_ALL_VDO = 5,
    MMI_FM_TEST_AVR_FLASH_ON = 6,
    MMI_FM_TEST_AVR_FLASH_OFF = 7,
    MMI_FM_TEST_AVR_END
} mmi_fm_test_avr_enum;


typedef enum
{
    MMI_FM_CAMERA_TEST_STATE_EXIT,
    MMI_FM_CAMERA_TEST_STATE_AVR_INIT,
    MMI_FM_CAMERA_TEST_STATE_AVR_PREVIEW,
    MMI_FM_CAMERA_TEST_STATE_AVR_RECORD,
    MMI_FM_CAMERA_TEST_STATE_AVR_PLAY,

    MMI_FM_CAMERA_TEST_STATE_CAM_INIT,
    MMI_FM_CAMERA_TEST_STATE_CAM_PREVIEW,
    MMI_FM_CAMERA_TEST_STATE_CAM_SHOW_IMG,
} mmi_fm_camera_test_state_neum;

typedef struct
{
    S8 filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    gdi_handle osd_layer;
    gdi_handle single_layer;
    gdi_handle preview_layer;
    U16 preview_width;
    U16 preview_height;
    S16 off_x;
    S16 off_y;
    U8 state;
    MMI_BOOL is_at_cmd;
    MMI_BOOL is_no_osd;
}mmi_fm_camera_test_cntx_struct;


#define MMI_FM_CAMERA_TEST_CAM_IMAGE_WIDTH      (320)
#define MMI_FM_CAMERA_TEST_CAM_IMAGE_HEIGHT     (240)

#define MMI_FM_CAMERA_TEST_AVR_VIDEO_WIDTH      (176)
#define MMI_FM_CAMERA_TEST_AVR_VIDEO_HEIGHT     (144)

mmi_fm_camera_test_cntx_struct mmi_fm_camera_test_cntx;
extern MMI_ID g_fm_gourp_id;

void mmi_fm_camera_test_stop_preview(void);
void mmi_fm_camera_test_start_preview(void);
void mmi_fm_camera_test_entry_preview_screen(void);
//static void mmi_fm_camera_test_play_video(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_dummy_func
 * DESCRIPTION
 *  display popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_dummy_func(void)
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
 *  mmi_fm_camera_test_popup
 * DESCRIPTION
 *  display popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_popup_display_simple((WCHAR*)GetString(str_id), MMI_EVENT_FAILURE, g_fm_gourp_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_popup_quit
 * DESCRIPTION
 *  display popup and then exit test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_popup_quit(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fm_camera_test_popup(str_id);
    mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_CAMERA_TEST);
}


/*****************************************************************************
* FUNCTION
*  mmi_fm_camera_test_print_align_text
* DESCRIPTION
*  draw osd string
* PARAMETERS
*  file_buf_p      [IN]        
*  a(?)            [OUT]       Next filename
* RETURNS
*  void
*****************************************************************************/
static void mmi_fm_camera_test_print_align_text(U8 align, U8 top, PS8 string1, PS8 string2, PS8 string3, PS8 string4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height;
    PS8 m_str_array[5];
    S32 layer_width, layer_height;
    S32 str_x = 0, str_y = 0;
    U32 i = 0, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    m_str_array[0] = string1;
    m_str_array[1] = string2;
    m_str_array[2] = string3;
    m_str_array[3] = string4;
    m_str_array[4] = NULL;
    if (string1 == NULL && string2 == NULL && string3== NULL && string4 == NULL)
    {
        return;
    }
    gui_set_text_color(gui_color(255,255,255));
    gui_set_text_border_color(gui_color(0,0,0));
    gui_reset_text_clip();
    gui_set_font(&MMI_small_font);
    while(NULL != m_str_array[count])
    {
        count++;
    }
    gdi_layer_get_dimension(&layer_width, &layer_height);
    for (i = 0; i < count; i++)
    {
        gui_measure_string((UI_string_type)m_str_array[i], &str_width, &str_height);
        switch (align)
        {
        case 0:
            str_x = 2; break;
        case 1:
            str_x = (layer_width - str_width)/2; break;
        case 2:
            str_x = layer_width - str_width - 2; break;
        }
        switch (top)
        {
        case 0:
            str_y = (str_height + 2) * i; break;
        case 1:
            str_y = (layer_height - (str_height + 2) * (count))/2 + (str_height + 2) * i; break;
        case 2:
            str_y = (layer_height - (str_height + 2) * (count - i)); break;
        }
        gui_move_text_cursor(str_x,str_y);
        gui_print_bordered_text((UI_string_type)m_str_array[i]);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_fm_camera_test_draw_text
* DESCRIPTION
*  draw osd
* PARAMETERS
*  file_buf_p      [IN]        
*  a(?)            [OUT]       Next filename
*  align           [IN]        0 left 1 center 2 right
*  top             [IN]        0 top  1 center 2 bottom
* RETURNS
*  void
*****************************************************************************/
static void mmi_fm_camera_test_draw_text(U8 align, U8 top, PS8 string1, PS8 string2, PS8 string3, PS8 string4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.osd_layer);
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    mmi_fm_camera_test_print_align_text(align, top, string1, string2, string3, string4);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_next_filename
* DESCRIPTION
*  get next file name for jpeg image
* PARAMETERS
*  file_buf_p      [IN]        
*  a(?)            [OUT]       Next filename
* RETURNS
*  void
*****************************************************************************/
static void mmi_fm_camera_test_get_next_filename(PS8 file_buf_p, mmi_fmgr_filetype_enum ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    sprintf(drv_buf, "%c:\\", (U8)SRV_FMGR_CARD_DRV);
    mmi_asc_to_ucs2(file_buf_p, drv_buf);
    mmi_ucs2cat((PS8) file_buf_p, (PS8) L"Photos\\");
    fs_ret = FS_CreateDir((U16*) file_buf_p);
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera create card folder err=%d",fs_ret);
    if (fs_ret < 0 && fs_ret != FS_FILE_EXISTS)
    {
        sprintf(drv_buf, "%c:\\", (U8)SRV_FMGR_PUBLIC_DRV);
        mmi_asc_to_ucs2(file_buf_p, drv_buf);
        mmi_ucs2cat((PS8) file_buf_p, (PS8) L"Photos\\");
        fs_ret = FS_CreateDir((U16*) file_buf_p);
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera create phone folder err=%d",fs_ret);
    }
    mdi_get_ucs2_filename(file_buf_p,(SRV_FMGR_PATH_MAX_LEN+1),file_buf_p,MDI_NAMING_TYPE_DDMMYY_HHMM,ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_get_preview_dimension
 * DESCRIPTION
 *  create preview layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_get_preview_dimension(S32 scr_width, S32 scr_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_util_fit_box(
        GDI_UTIL_MODE_LONG_SIDE_FIT,
        LCD_WIDTH,
        LCD_HEIGHT,
        scr_width,
        scr_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    mmi_fm_camera_test_cntx.off_x = resized_offset_x;
    mmi_fm_camera_test_cntx.off_y = resized_offset_y;
    mmi_fm_camera_test_cntx.preview_width  = resized_width; 
    mmi_fm_camera_test_cntx.preview_height = resized_height;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_create_preview_layer
 * DESCRIPTION
 *  create preview layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_create_preview_layer(U16 preview_width, U16 preview_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_util_create_hw_layer_extmemory_in_struct layer_in;
    mdi_util_create_hw_layer_out_struct layer_out;
    U8 *base_layer_buf_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_fm_camera_test_cntx.preview_layer != NULL)
    {
        mdi_util_hw_layer_free(mmi_fm_camera_test_cntx.preview_layer);
        mmi_fm_camera_test_cntx.preview_layer = NULL;
    }

    mmi_fm_camera_test_get_preview_dimension(preview_width, preview_height);

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_get_buffer_ptr(&base_layer_buf_p);
    gdi_layer_pop_and_restore_active();

    layer_in.buffer      = base_layer_buf_p;
    layer_in.buffer_size = mmi_fm_camera_test_cntx.preview_width * mmi_fm_camera_test_cntx.preview_height * 2;
    layer_in.offset_x    = mmi_fm_camera_test_cntx.off_x;
    layer_in.offset_y    = mmi_fm_camera_test_cntx.off_y;
    layer_in.width       = mmi_fm_camera_test_cntx.preview_width;
    layer_in.height      = mmi_fm_camera_test_cntx.preview_height;
    layer_in.scenario_id = MDI_MULTIMEDIA_CAMERA;
    mmi_fm_camera_test_cntx.preview_layer = mdi_util_hw_layer_create_with_extmemory(&layer_in, &layer_out);

    mmi_fm_camera_test_cntx.off_x = layer_out.offset_x;
    mmi_fm_camera_test_cntx.off_y = layer_out.offset_y;
    mmi_fm_camera_test_cntx.preview_width  = layer_out.width;
    mmi_fm_camera_test_cntx.preview_height = layer_out.height;

    gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.preview_layer);
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_VIDEO_RECORDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_play_finish_hdlr
 * DESCRIPTION
 *  play video callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_play_finish_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera play finished cb ret=%d",result);
    if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_PLAY)
    {
        mmi_fm_camera_test_draw_text(0, 2, (PS8)L"Delete Video File & Prepared Next Function", (PS8)L"Press OK Key!", NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        mdi_video_ply_close_file();
        FS_Delete((WCHAR*)mmi_fm_camera_test_cntx.filepath);
        /* flush key event */
        ClearKeyEvents();
        SetKeyDownHandler(mmi_fm_camera_test_stop_preview, KEY_ENTER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_at_play_finish_hdlr
 * DESCRIPTION
 *  auto test play video callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_at_play_finish_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera play finished cb ret=%d",result);
    if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_PLAY)
    {
        mmi_fm_camera_test_draw_text(0, 2, (PS8)L"Play finished", NULL, NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        mdi_video_ply_close_file();
        /* flush key event */
        ClearKeyEvents();
        SetKeyDownHandler(mmi_fm_camera_test_stop_preview, KEY_ENTER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_play_open_done_hdlr
 * DESCRIPTION
 *  function to be called when file is opened.
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  vdo_clip        [IN]        Video info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_play_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* check if already exit player screen */
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera play open cb ret=%d",result);
    if (mmi_fm_camera_test_cntx.state != MMI_FM_CAMERA_TEST_STATE_AVR_PLAY)
    {    
        return;
    }
    /* if open sucessfully */
    if (result >= 0)
    {
        mmi_fm_camera_test_create_preview_layer(MMI_FM_CAMERA_TEST_AVR_VIDEO_WIDTH, MMI_FM_CAMERA_TEST_AVR_VIDEO_HEIGHT);

        mmi_fm_camera_test_draw_text(0, 2, (PS8)L"Video Playing", NULL, NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        /* have enough buffer, can enter idle state */
        mdi_video_ply_seek(0);
        if (mmi_fm_camera_test_cntx.is_at_cmd == MMI_FALSE)
        {
            last_error = mdi_video_ply_play(
                mmi_fm_camera_test_cntx.preview_layer,                      /* play layer handle */
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,   /* blt layer */
                GDI_LAYER_ENABLE_LAYER_0,                              /* play_layer_flag */
                1,                                  /* repeat */
                MMI_TRUE,                           /* visual update */
                MMI_TRUE,                           /* play aud */
                MDI_DEVICE_SPEAKER2,                /* audio path */
                MDI_VIDEO_LCD_ROTATE_0,             /* rotate */
                100,                                /* speed factor */
                mmi_fm_camera_test_play_finish_hdlr,
                0);/* play layer */
        }
        else
        {
            last_error = mdi_video_ply_play(
                mmi_fm_camera_test_cntx.preview_layer,                      /* play layer handle */
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,   /* blt layer */
                GDI_LAYER_ENABLE_LAYER_0,                              /* play_layer_flag */
                1,                                  /* repeat */
                MMI_TRUE,                           /* visual update */
                MMI_TRUE,                           /* play aud */
                MDI_DEVICE_SPEAKER2,                /* audio path */
                MDI_VIDEO_LCD_ROTATE_0,             /* rotate */
                100,                                /* speed factor */
                mmi_fm_camera_test_at_play_finish_hdlr,
                0); /* play layer */
        }
        
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera play start ret=%d",last_error);
        if (last_error < 0)
        {
            mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_play_video
 * DESCRIPTION
 *  play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_play_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT last_error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_AVR_PLAY;
    last_error = mdi_video_ply_open_file(0, mmi_fm_camera_test_cntx.filepath, mmi_fm_camera_test_play_open_done_hdlr, 0);

    if (last_error < 0)
    {
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
    }
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera play open file ret=%d",last_error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_record_result_hdlr_callback
 * DESCRIPTION
 *  record video callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_record_result_hdlr_callback(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera rec cb result=%d",result);
    switch (result)
    {
    case MDI_RES_VDOREC_DISK_FULL:
        mmi_fm_camera_test_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY);
        break;
    case MDI_RES_VDOREC_REACH_SIZE_LIMIT:
        mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_OK), 
                MMI_EVENT_SUCCESS, 
                g_fm_gourp_id, 
                NULL);
        break;
    case MDI_RES_VDOREC_ERR_FAILED:
    case MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW:
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
        break;
    default:
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
        break;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_save_result_hdlr_callback
 * DESCRIPTION
 *  save video callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_save_result_hdlr_callback(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera video save cb result=%d",result);
    if (result < 0)
    {
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
    }        
    else
    {
        mmi_fm_camera_test_draw_text(0, 2, (PS8)L"Video File Saved", (PS8)L"Press OK Key to play!", NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        /* flush key event */
        ClearKeyEvents();
        SetKeyDownHandler(mmi_fm_camera_test_play_video, KEY_ENTER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_record_save_video
 * DESCRIPTION
 *  save video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_camera_test_record_save_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT last_error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_RECORD)
    {
        last_error = mdi_video_rec_record_stop();
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera stop ret=%d",last_error);
        if (last_error < 0)
        {
            mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
            return;
        }

        mmi_fm_camera_test_draw_text(0, 2, (PS8)L"Saving ...", NULL, NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        
        last_error = mdi_video_rec_save_file(mmi_fm_camera_test_cntx.filepath, mmi_fm_camera_test_save_result_hdlr_callback, NULL);
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera save ret=%d",last_error);
        /* shut down camera */
        mdi_video_rec_power_off();

        if (last_error < 0) 
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(mmi_fm_camera_test_cntx.filepath);
            mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
            return;
        }
        
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_capture_video
 * DESCRIPTION
 *  record video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_capture_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT last_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #if defined(MP4_ENCODE)
    mmi_fm_camera_test_get_next_filename((PS8)mmi_fm_camera_test_cntx.filepath, FMGR_TYPE_3GP);
    #elif defined(MJPG_ENCODE)
    mmi_fm_camera_test_get_next_filename((PS8)mmi_fm_camera_test_cntx.filepath, FMGR_TYPE_AVI);
    #endif
    
    last_error = mdi_video_rec_record_start(mmi_fm_camera_test_cntx.filepath, mmi_fm_camera_test_record_result_hdlr_callback, NULL);
    if (last_error != MDI_RES_VDOREC_SUCCEED)
    {
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera record err=%d",last_error);
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_AVR_RECORD;
        mmi_fm_camera_test_draw_text(0, 2, (PS8)L" Video Recoding...", NULL, NULL, NULL);
        gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
        /* flush key event */
        ClearKeyEvents();
        ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
        //SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_ENTER, KEY_EVENT_DOWN);
        if (mmi_fm_camera_test_cntx.is_at_cmd == MMI_FALSE)
        {
            gui_start_timer(3000,mmi_fm_camera_test_record_save_video);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_start_avr_preview
 * DESCRIPTION
 *  start video test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_start_avr_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 blt_layer_flag = 0;
    U32 preview_layer_flag;
    mdi_video_setting_struct video_preview_data = {0};
    MDI_RESULT last_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            
    last_error = mdi_video_rec_power_on(0);
    
    if (last_error != MDI_RES_VDOREC_SUCCEED)
    {
        mmi_fm_camera_test_popup_quit(STR_GLOBAL_ERROR);
        return;
    }

    //QCIF
    mmi_fm_camera_test_create_preview_layer(MMI_FM_CAMERA_TEST_AVR_VIDEO_WIDTH, MMI_FM_CAMERA_TEST_AVR_VIDEO_HEIGHT);
    
    gdi_layer_set_blt_layer(mmi_fm_camera_test_cntx.preview_layer, mmi_fm_camera_test_cntx.osd_layer, 0, 0);
    
    mdi_video_rec_load_default_setting(&video_preview_data);
    video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
    video_preview_data.video_qty = MDI_VIDEO_REC_QTY_NORMAL;
    #if defined(MP4_ENCODE)
    video_preview_data.video_format = MDI_VIDEO_VIDEO_FORMAT_MP4;
    #elif defined(MJPG_ENCODE)
    video_preview_data.video_format = MDI_VIDEO_VIDEO_FORMAT_MJPEG;
    #endif
    video_preview_data.user_def_width = 0;
    video_preview_data.user_def_height = 0;
    video_preview_data.zoom = 0;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_0;
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
    video_preview_data.time_limit = 0;
    video_preview_data.size_limit = 0;
    video_preview_data.record_aud = TRUE;
    /*config the video layer*/
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;

    last_error = mdi_video_rec_preview_start(
            mmi_fm_camera_test_cntx.preview_layer,
            blt_layer_flag,
            preview_layer_flag,
            MMI_TRUE,
            &video_preview_data);

    if (last_error != MDI_RES_VDOREC_SUCCEED)
    {
        mmi_fm_camera_test_popup_quit(STR_GLOBAL_ERROR);
        return;
    }

    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_AVR_PREVIEW;
    
#if defined(__CAMERA_FEATURE_STORAGE__)
    if (mmi_fm_camera_test_cntx.is_at_cmd == MMI_FALSE)
    {
        /* memory card not mount*/
        if (FS_NO_ERROR != FS_GetDevStatus(SRV_FMGR_CARD_DRV ,FS_MOUNT_STATE_ENUM))
        {
            mmi_fm_camera_test_popup_quit(STR_GLOBAL_INSERT_MEMORY_CARD);
            return;
        }
    }
#endif

    if (mmi_fm_camera_test_cntx.is_no_osd != MMI_TRUE)
    {
        mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Video preview", (PS8)L"Press OK key to Record!", NULL, NULL);
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    SetKeyDownHandler(mmi_fm_camera_test_capture_video, KEY_ENTER);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_delete_image
 * DESCRIPTION
 *  delete image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_delete_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_RECORDER__    
    mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Delete saved image and", (PS8)L"prepare video preview...", NULL, NULL);
#else
    mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Delete saved image...", NULL, NULL, NULL);
#endif
    gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
    
    FS_Delete((WCHAR*)mmi_fm_camera_test_cntx.filepath);

    kal_sleep_task(200);
#ifdef __MMI_VIDEO_RECORDER__
    mmi_fm_camera_test_start_avr_preview();
#else
    mmi_fm_camera_test_stop_preview();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_capture_and_save_image
 * DESCRIPTION
 *  capture and save image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_capture_and_save_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT last_error;
    PU8 quickview_buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fm_camera_test_get_next_filename((PS8)mmi_fm_camera_test_cntx.filepath, FMGR_TYPE_JPG);
    //last_error = mdi_camera_capture_to_file(mmi_fm_camera_test_cntx.filepath, MMI_FALSE);
    
    gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.preview_layer);
    gdi_layer_get_buffer_ptr(&quickview_buf);
    gdi_layer_pop_and_restore_active();
    
    last_error = mdi_camera_capture_with_quickview(
                    (U32)quickview_buf,
                    mmi_fm_camera_test_cntx.preview_width * mmi_fm_camera_test_cntx.preview_height * 2,
                    mmi_fm_camera_test_cntx.preview_width,
                    mmi_fm_camera_test_cntx.preview_height,
                    mmi_fm_camera_test_cntx.filepath);
    if (last_error != MDI_RES_CAMERA_SUCCEED)
    {
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera capture err=%d",last_error);
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        last_error = mdi_camera_save_captured_image();
        if (last_error != MDI_RES_CAMERA_SUCCEED)
        {
            //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera save err=%d",last_error);
            mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
        }
        else
        {
            mdi_camera_preview_stop();
            mdi_camera_power_off();
            
            mdi_util_hw_layer_switch_to_sw_layer(mmi_fm_camera_test_cntx.preview_layer);
            gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.preview_layer);
            gdi_layer_set_color_format(mdi_camera_get_quickview_color_format());
            gdi_layer_pop_and_restore_active();
            
            //gdi_image_draw_file(0, 0, mmi_fm_camera_test_cntx.filepath);
            mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Image Captured", (PS8)L"Press OK key!", NULL, NULL);
            gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
            SetKeyDownHandler(mmi_fm_camera_test_delete_image, KEY_ENTER);
            mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_CAM_SHOW_IMG;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_start_cam_preview
 * DESCRIPTION
 *  start factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_start_cam_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data = {0};
    mdi_camera_preview_struct camera_preview_data = {0};
    S32 last_error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    last_error = mdi_camera_power_on(0);

    if (last_error != MDI_RES_VDOREC_SUCCEED)
    {
        mmi_fm_camera_test_popup_quit(STR_GLOBAL_ERROR);
        return;
    }

    mmi_fm_camera_test_create_preview_layer(MMI_FM_CAMERA_TEST_CAM_IMAGE_WIDTH, MMI_FM_CAMERA_TEST_CAM_IMAGE_HEIGHT);
    
    gdi_layer_set_blt_layer(mmi_fm_camera_test_cntx.preview_layer, mmi_fm_camera_test_cntx.osd_layer, 0, 0);

    mdi_camera_load_default_setting(&camera_setting_data);
    camera_setting_data.preview_width   = mmi_fm_camera_test_cntx.preview_width;
    camera_setting_data.preview_height  = mmi_fm_camera_test_cntx.preview_height;
    camera_setting_data.image_width     = MMI_FM_CAMERA_TEST_CAM_IMAGE_WIDTH;
    camera_setting_data.image_height    = MMI_FM_CAMERA_TEST_CAM_IMAGE_HEIGHT;
    camera_setting_data.lcm             = MDI_CAMERA_PREVIEW_LCM_MAINLCD;

    camera_preview_data.preview_layer_handle = mmi_fm_camera_test_cntx.preview_layer;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = 0;
    camera_preview_data.is_tvout = FALSE;
    camera_setting_data.xenon_flash_status_callback = NULL;

    last_error = mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data,
        NULL);
        
    if (last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_fm_camera_test_popup_quit(STR_GLOBAL_ERROR);
        return;
    }
    
    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_CAM_PREVIEW;
        
#if defined(__CAMERA_FEATURE_STORAGE__)
    if (mmi_fm_camera_test_cntx.is_at_cmd == MMI_FALSE)
    {
        /* memory card not mount*/
        if (FS_NO_ERROR != FS_GetDevStatus(SRV_FMGR_CARD_DRV ,FS_MOUNT_STATE_ENUM))
        {
            mmi_fm_camera_test_popup_quit(STR_GLOBAL_INSERT_MEMORY_CARD);
            return;
        }
    }
#endif

    if (mmi_fm_camera_test_cntx.is_no_osd != MMI_TRUE)
    {
        mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Camera Preview start", (PS8)L"Press OK key to Capture!", NULL, NULL);
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    SetKeyDownHandler(mmi_fm_camera_test_capture_and_save_image, KEY_ENTER);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_exit_preview_screen
 * DESCRIPTION
 *  exit factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if 0    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
/* under construction !*/
#endif
#endif

    switch (mmi_fm_camera_test_cntx.state)
    {
    #ifdef __MMI_VIDEO_RECORDER__
        case MMI_FM_CAMERA_TEST_STATE_AVR_RECORD:
            mdi_video_rec_record_stop();
            mdi_video_rec_preview_stop();
            mdi_video_rec_power_off();
            break;
        case MMI_FM_CAMERA_TEST_STATE_AVR_PREVIEW:
            mdi_video_rec_preview_stop();
            mdi_video_rec_power_off();
            break;
        case MMI_FM_CAMERA_TEST_STATE_AVR_PLAY:
            mdi_video_ply_stop();
            mdi_video_ply_close_file();
            break;
    #endif
        case MMI_FM_CAMERA_TEST_STATE_CAM_PREVIEW:
            mdi_camera_preview_stop();
            mdi_camera_power_off();
            break;
        case MMI_FM_CAMERA_TEST_STATE_CAM_SHOW_IMG:
            break;
    }

    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_EXIT;

    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();

    if (mmi_fm_camera_test_cntx.preview_layer != NULL)
    {
        mdi_util_hw_layer_free(mmi_fm_camera_test_cntx.preview_layer);
        mmi_fm_camera_test_cntx.preview_layer = NULL;
    }
    if (mmi_fm_camera_test_cntx.osd_layer != NULL)
    {
        gdi_layer_free(mmi_fm_camera_test_cntx.osd_layer);
        mmi_fm_camera_test_cntx.osd_layer = NULL;
    }
    if (mmi_fm_camera_test_cntx.single_layer != NULL)
    {
        gdi_layer_free(mmi_fm_camera_test_cntx.single_layer);
        mmi_fm_camera_test_cntx.single_layer = NULL;
    }

    /* resume LCD patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    GoBackSubLCDHistory();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_entry_preview_screen
 * DESCRIPTION
 *  exit factory mode camera preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_entry_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter
       (g_fm_gourp_id, 
        SCR_ID_FM_CAMERA_TEST, 
        mmi_fm_camera_test_exit_preview_screen, 
        mmi_fm_camera_test_entry_preview_screen, 
        MMI_FRM_FULL_SCRN);

    entry_full_screen();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* stop MMI sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    /* stop LCD patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);

    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* clear background */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_layer_clear(GDI_COLOR_BLACK);

    SetKeyUpHandler(mmi_fm_camera_test_dummy_func, KEY_LSK);
    SetKeyUpHandler(mmi_frm_scrn_close_active_id, KEY_RSK);
    
    if (mmi_fm_camera_test_cntx.osd_layer == NULL)
    {
        S32 width,height;
        U8 *buf_ptr = NULL;
        
        width = (LCD_WIDTH);
        height = (LCD_HEIGHT/2);
        /*temp solution avoid gdi free wrong buffer pointer*/
        gdi_layer_create(0, 0, width, height * 2,&mmi_fm_camera_test_cntx.single_layer);
        gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.single_layer);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_pop_and_restore_active();

        gdi_layer_create_double_using_outside_memory(
            0,
            ((LCD_HEIGHT - height)/2),
            width, 
            height,
            &mmi_fm_camera_test_cntx.osd_layer,
            (PU8)buf_ptr,
            width * height * 4);
        gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.osd_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_toggle_double();
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

#ifdef __MMI_VIDEO_RECORDER__
    if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_INIT)
    {
        mmi_fm_camera_test_start_avr_preview();
    }
    else //if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_CAM_INIT)
#endif
    {
        mmi_fm_camera_test_start_cam_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_stop_preview
 * DESCRIPTION
 *  stop preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_stop_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(g_fm_gourp_id, SCR_ID_FM_CAMERA_TEST_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_entry_cam_test
 * DESCRIPTION
 *  enter camera test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_entry_cam_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fm_camera_test_cntx.is_at_cmd = MMI_FALSE;
    mmi_fm_camera_test_cntx.is_no_osd = MMI_FALSE;
    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_CAM_INIT;
    mmi_fm_camera_test_entry_preview_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_entry_avr_test
 * DESCRIPTION
 *  enter video recorder test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__ 
void mmi_fm_camera_test_entry_avr_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fm_camera_test_cntx.is_at_cmd = MMI_FALSE;
    mmi_fm_camera_test_cntx.is_no_osd = MMI_FALSE;
    mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_AVR_INIT;
    mmi_fm_camera_test_entry_preview_screen();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_capture_image
 * DESCRIPTION
 *  capture image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_capture_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT last_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fm_camera_test_get_next_filename((PS8)mmi_fm_camera_test_cntx.filepath, FMGR_TYPE_JPG);
    last_error = mdi_camera_capture_to_file(mmi_fm_camera_test_cntx.filepath, MMI_FALSE);
    if (last_error != MDI_RES_CAMERA_SUCCEED)
    {
        //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera capture err=%d",last_error);
        mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        last_error = mdi_camera_save_captured_image();
        if (last_error != MDI_RES_CAMERA_SUCCEED)
        {
            //kal_print_string_trace(MOD_MMI_MEDIA_APP,TRACE_GROUP_2,"FM Camera save err=%d",last_error);
            mmi_fm_camera_test_popup(STR_GLOBAL_ERROR);
        }
        else
        {
            mmi_fm_camera_test_stop_preview();
            //mmi_fm_camera_test_entry_preview_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_cam_cmd_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fm_cam_cmd_req_hdlr(U32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 2;/*2 not support*/
    S32 err_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fm_camera_test_cntx.is_at_cmd = MMI_TRUE;
    mmi_fm_camera_test_cntx.is_no_osd = MMI_FALSE;
    switch (cmd)
    {
    case MMI_FM_TEST_CAM_INIT:
        mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_CAM_INIT;
        result = MMI_TRUE;
        break;
    case MMI_FM_TEST_CAM_PREVIEW:
        if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_CAM_INIT)
        {
            mmi_fm_camera_test_entry_preview_screen();
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
        break;
    case MMI_FM_TEST_CAM_SHOT:
        if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_CAM_PREVIEW)
        {
            mmi_fm_camera_test_capture_image();
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
        break;
    case MMI_FM_TEST_CAM_SAVE:
        result = MMI_TRUE;
        break;
    case MMI_FM_TEST_CAM_SHOW_IMAGE:
        result = MMI_FALSE;
        if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_CAM_PREVIEW)
        {
            mdi_util_hw_layer_switch_to_sw_layer(mmi_fm_camera_test_cntx.preview_layer);
            gdi_layer_push_and_set_active(mmi_fm_camera_test_cntx.preview_layer);
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
            gdi_layer_clear(GDI_COLOR_BLACK);
            err_code = gdi_image_draw_file(0, 0, mmi_fm_camera_test_cntx.filepath);
            gdi_layer_pop_and_restore_active();
            
            //err_code = gdi_image_draw_file(0, 0, mmi_fm_camera_test_cntx.filepath);
            
            mmi_fm_camera_test_draw_text(1, 1, (PS8)L"Image Captured", (PS8)L"Press OK key!", NULL, NULL);
            gdi_layer_blt_previous(0, 0, LCD_WIDTH, LCD_HEIGHT);
            
            if (err_code >= 0)
            {
                mdi_camera_preview_stop();
                mdi_camera_power_off();
                mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_CAM_SHOW_IMG;
                result = MMI_TRUE;
            }
        }
        break;
    case MMI_FM_TEST_CAM_FLASH_ON:
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        custom_start_flashlight(1, 1, 1, 90);
        result = MMI_TRUE;
        #endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
        break;
    case MMI_FM_TEST_CAM_FLASH_OFF:
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        custom_stop_flashlight();
        result = MMI_TRUE;
        #endif
        break;
    case MMI_FM_TEST_CAM_STROBE_ON:
        break;
    case MMI_FM_TEST_CAM_STROBE_OFF:
        break;
    case MMI_FM_TEST_CAM_SWITCH_SENSOR:
        break;
    case MMI_FM_TEST_CAM_DEL_ALL_IMG:
        FS_Delete((WCHAR*)mmi_fm_camera_test_cntx.filepath);
        result = MMI_TRUE;
        break;
    default:
        break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_at_cam_hdlr
 * DESCRIPTION
 *  This function is to handle AT command for cam testing
 * PARAMETERS
 *  ind        [IN]        message data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_at_cam_hdlr(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_cam_res_req_struct *rsp_msg;
    mmi_eq_set_cam_req_ind_struct *msg = (mmi_eq_set_cam_req_ind_struct*)ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_eq_set_cam_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_cam_res_req_struct));
    rsp_msg->mode = msg->mode;
    rsp_msg->result = mmi_fm_cam_cmd_req_hdlr((U32)msg->mode);
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_CAM_RES_REQ, (oslParaType*) rsp_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_avr_cmd_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
U8 mmi_fm_avr_cmd_req_hdlr(S32 cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 2;/*2 not support*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fm_camera_test_cntx.is_at_cmd = MMI_TRUE;
    mmi_fm_camera_test_cntx.is_no_osd = MMI_FALSE;
    switch (cmd)
    {
    case MMI_FM_TEST_AVR_INIT:
        mmi_fm_camera_test_cntx.state = MMI_FM_CAMERA_TEST_STATE_AVR_INIT;
        result = MMI_TRUE;
        break;
    case MMI_FM_TEST_AVR_PREVIEW:
        if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_INIT)
        {
            mmi_fm_camera_test_entry_preview_screen();
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
        break;
    case MMI_FM_TEST_AVR_SHOT:
        if (mmi_fm_camera_test_cntx.state == MMI_FM_CAMERA_TEST_STATE_AVR_PREVIEW)
        {
            mmi_fm_camera_test_capture_video();
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
        break;
    case MMI_FM_TEST_AVR_SAVE:
        mmi_fm_camera_test_record_save_video();
        result = MMI_TRUE;
        break;
    case MMI_FM_TEST_AVR_SHOW_VIDEO:
        mmi_fm_camera_test_play_video();
        result = MMI_TRUE;
        break;
    case MMI_FM_TEST_AVR_FLASH_ON:
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        custom_start_flashlight(1, 1, 1, 90);
        result = MMI_TRUE;
        #endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
        break;
    case MMI_FM_TEST_AVR_FLASH_OFF:
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        custom_stop_flashlight();
        result = MMI_TRUE;
        #endif
        break;
    case MMI_FM_TEST_AVR_DEL_ALL_VDO:
        FS_Delete((WCHAR*)mmi_fm_camera_test_cntx.filepath);
        result = MMI_TRUE;
        break;
    default:
        break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_camera_test_at_avr_hdlr
 * DESCRIPTION
 *  This function is to handle AT command for avr testing
 * PARAMETERS
 *  ind        [IN]        message data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_camera_test_at_avr_hdlr(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_avr_res_req_struct *rsp_msg;
    mmi_eq_set_avr_req_ind_struct *msg = (mmi_eq_set_avr_req_ind_struct*)ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_eq_set_avr_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_avr_res_req_struct));
    rsp_msg->mode = msg->mode;
    rsp_msg->result = mmi_fm_avr_cmd_req_hdlr((U32)msg->mode);
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_AVR_RES_REQ, (oslParaType*) rsp_msg, NULL);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_cam_tc01_init
 * DESCRIPTION
 *  This function is to handle AT command
 * PARAMETERS
 *  ind        [IN]        message data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_cam_tc01_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetProtocolEventHandler(mmi_fm_camera_test_at_cam_hdlr, MSG_ID_MMI_EQ_SET_CAM_REQ_IND);
#ifdef __MMI_VIDEO_RECORDER__
    SetProtocolEventHandler(mmi_fm_camera_test_at_avr_hdlr, MSG_ID_MMI_EQ_SET_AVR_REQ_IND);
#endif    
}



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
/* under construction !*/
/* under construction !*/
#endif

#endif  /*__MMI_FM_TC01_CAMERA_TEST__*/

