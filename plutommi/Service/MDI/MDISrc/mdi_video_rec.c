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
 *  mdi_video_rec.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's video functions 
    * - For Target, call media's video functions.
    */
#define MDI_VIDEO_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

#include "lcd_if.h"             /* lcd interface */
#include "gdi_include.h"        /* include data type */
#include "med_struct.h"
#include "med_api.h"            /* media task */
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_video.h"
#include "mdi_camera.h"
#include "mdi_video_internal.h"

#include "reg_base.h"
#include "IntrCtrl.h"
#include "drv_comm.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "fat_fs.h"

#include "img_common_enum.h"
#include "image_effect_struct.h"

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#include "gui.h"
#endif

#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "stack_config.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "gdi_features.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_mdi_def.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_api.h"
#include "gdi_const.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "gui_resource_type.h"
#include "mmi_frm_queue_gprot.h"


#include "custom_video_enc_if.h"
#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_VIDEO_ABS(val) (((val) < 0) ? -(val) : (val))
#define MDI_VIDEO_DUMMY_BITRATE (100000)

#if defined(__LOW_COST_SUPPORT_COMMON__)
#define __MDI_VIDEO_RECORD_LOW_COST_SUPPORT_COMMON__
#endif


/***************************************************************************** 
* Typedef
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
extern mdi_video_context_struct *mdi_video_p;
extern mdi_video_setting_struct *video_setting_p;
extern module_type mdi_video_get_module_id(void);

/* callback function */
void (*mdi_video_rec_save_result_callback)(MDI_RESULT result, void* user_data) = NULL;
void (*mdi_video_rec_record_result_callback)(MDI_RESULT result, void* user_data) = NULL;
#if defined(AF_SUPPORT)
static mdi_video_rec_af_ind_callback g_mdi_video_rec_af_callback;
static void mdi_video_rec_af_finish_ind(void *inMsg);
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
void mdi_video_rec_save_result_hdlr(void *msg_ptr);
void mdi_video_rec_record_result_hdlr(void *msg_ptr);

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
/* drvier not availabe, mdi simulate non-block mechanism */
static void mdi_video_rec_dummy_save_file_result_hdlr(void);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 



/***************************************************************************** 
* Extern Variable
*****************************************************************************/
/****************************************************************************
*
* RECORDER                                                                 
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_error_info
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 * error_code : [IN] error code got from MDI APIs
 * popup_type : [OUT] popup_type of this error_code
 * RETURNS
 *  string_id in MMI_ID_TYPE correspounding error enum.
 *****************************************************************************/
MMI_ID_TYPE mdi_video_rec_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;

    switch (error_code)
    {
        case MDI_RES_VDOREC_ERR_DISK_FULL:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
            string_id = STR_ID_MDI_COMMON_WRITE_PROTECTION;
            break;
        case MDI_RES_VDOREC_ERR_NO_DISK:
            string_id = STR_GLOBAL_NO_MEMORY_CARD;
            break;
        case MDI_RES_VDOREC_ERR_HW_NOT_READY:
            string_id = STR_ID_MDI_COMMON_HW_NOT_READY;
            break;
        case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
            string_id = STR_GLOBAL_FAILED_TO_SAVE;
            break;
        case MDI_RES_VDOREC_ERR_RECORD_FAILED:
            string_id = STR_ID_MDI_COMMON_RECORD_FAIL;
            break;
        case MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW:
            string_id = STR_ID_MDI_VIDEO_REC_STORAGE_TOO_SLOW;
            break;
        case MDI_RES_VDOREC_ERR_MEMORY_INSUFFICIENT:
            string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
            break;
        case MDI_RES_VDOREC_ERR_STORAGE_INSUFFICIENT:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_RES_STREAM_REC_ERR_DISK_FULL:
            string_id = STR_GLOBAL_MEMORY_FULL;
            break;
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_init
 * DESCRIPTION
 *  Initialize mdi video recorder.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to initialize video recorder.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to initialize video recorder.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
    mdi_video_p->is_recording = FALSE;            
    mdi_video_p->is_poweron = FALSE;            

    mdi_video_p->record_seq_num = 0;
    mdi_video_p->merge_seq_num = 0;
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_recording
 * DESCRIPTION
 *  Toc check video recorder is currently recording or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : Video is recording now.
 *  MMI_FALSE : Video is not recording now.
 *****************************************************************************/
BOOL mdi_video_is_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_video_p->is_recording;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor.
 * PARAMETERS
 *  camera_id : [IN] Camera sensor id [main or sub]
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
MDI_RESULT mdi_video_set_camera_id(U16 camera_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->cam_id = camera_id;
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_set_record_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_set_record_rotation(U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->encode_rotate = value;
   
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_detect_sensor_id
 * DESCRIPTION
 *  Dectect sensor module id.
 * PARAMETERS
 *  cam_id : [IM] Main/Sub camera sensor id.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to detect camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to detect camera id.
 *****************************************************************************/
MDI_RESULT mdi_video_detect_sensor_id(U8 cam_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     return MDI_RES_VDOREC_SUCCEED;
}

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
static MDI_RESULT mdi_video_rec_power_on_internal(const U16 app_id)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    media_vid_power_up_req_struct vid_powerup_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_p->force_ui_rotate = MDI_VIDEO_PREVIEW_ROTATE_RESET;
#endif
    mdi_video_p->is_enable_partial_display = FALSE;


    vid_powerup_data.seq_num = 0;
    vid_powerup_data.cam_id = mdi_video_p->cam_id;
    vid_powerup_data.app_id = mdi_video_p->app_id = app_id;

    #ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    #endif
    ret = media_vid_power_up(module_id, (void*)&vid_powerup_data);

    if (ret != MED_RES_OK)
    {
        #ifdef __MM_DCM_SUPPORT__
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        #endif 
        mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
        return MDI_RES_VDOREC_ERR_POWER_ON_FAILED;
    }
    mdi_video_p->is_poweron = TRUE;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


static MDI_RESULT mdi_video_rec_power_off_internal(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_power_down(module_id);

    #ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    #endif 
    mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;


#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    /* power off alwyas return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_on
 * DESCRIPTION
 *  To power on recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to power on camera module.
 *  MDI_RES_VDOREC_ERR_POWER_ON_FAILED : Fail to power on camera module.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_power_on(const U16 app_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_MWREC, NULL, NULL);
#endif
    result =  mdi_video_rec_power_on_internal(app_id);

#ifdef __MM_DCM_SUPPORT__
    if (result == MDI_RES_VDOREC_ERR_POWER_ON_FAILED)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);
    }
#endif

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_power_off
 * DESCRIPTION
 *  To power off recorder hw.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to power off camera module.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to power off camera module.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* power off alwyas return succeed */
    result =  mdi_video_rec_power_off_internal();
#ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);
#endif    
    mdi_video_p->is_poweron = FALSE;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_start
 * DESCRIPTION
 *  To start preview for video recorder.
 * PARAMETERS
 *  preview_layer_handle : [IN]Layer handle of preview layer.
 *  blt_layer_flag :[IN]Blt out layer flag.
 *  preview_layer_flag : [IN]Preview layer flag.
 *  is_lcd_update : [IN]Update lcd or not.
 *  setting_p : [IN]Setting data.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to start preview.
 *  MDI_RES_VDOREC_ERR_HW_NOT_READY : Fail to start preview.
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
MDI_RESULT mdi_video_rec_preview_start(
            gdi_handle preview_layer_handle,
            U32 blt_layer_flag,
            U32 preview_layer_flag,
            MMI_BOOL is_lcd_update,
            mdi_video_setting_struct *setting_p)       /* video setting */
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_preview_req_struct preview_data;
    MDI_RESULT ret;
    mdi_blt_para_struct blt_data;
    module_type module_id = mdi_video_get_module_id();
    kal_uint32 layer_element;
    gdi_color_format layer_format;    
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    U8 physical_rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* store video's parameters */
    memcpy(video_setting_p, setting_p, sizeof(mdi_video_setting_struct));

    gdi_lcd_get_active(&mdi_video_p->lcd_handle);

    /* call this function before calling mdi_calc_blt_para() */
    mdi_video_p->hw_update_layer_handle = preview_layer_handle;

    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    gdi_layer_push_and_set_active(mdi_video_p->hw_update_layer_handle);
    gdi_layer_get_color_format(&layer_format);
    if (layer_format != GDI_COLOR_FORMAT_UYVY422 && 
        mdi_video_p->hw_update_layer_handle)
    {
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422); 
    }
    gdi_layer_pop_and_restore_active();
    #endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */

   /* calc blt paramters */
    mdi_calc_blt_para(
        preview_layer_handle,
        setting_p->lcm_rotate,
        mdi_video_p->lcd_handle,
        MMI_FALSE, 
        &blt_data);

    gdi_layer_get_layer_element(
        preview_layer_flag,
        &layer_element,
        &blt_ctx,
        &blt_dev);

    preview_data.layer_element = layer_element;
    preview_data.blt_ctx = blt_ctx;
    preview_data.blt_dev = blt_dev;

    if (mdi_video_p->lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        preview_data.lcd_id = MAIN_LCD;
    }
    else if (mdi_video_p->lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        preview_data.lcd_id = SUB_LCD;
    }

    preview_data.frame_buffer_addr1 = (kal_uint32)blt_data.image_buffer_p;
    preview_data.frame_buffer_addr2 = (kal_uint32)blt_data.image_buffer_p_2;
    preview_data.frame_buffer_size = blt_data.image_buffer_size;

    /* lcd / preview related */
    preview_data.preview_width = blt_data.display_width;
    preview_data.preview_height = blt_data.display_height;

    /* set settings parameters */
    preview_data.WB = video_setting_p->wb;
    preview_data.exposure = video_setting_p->ev;
    preview_data.banding_freq = (U8) video_setting_p->banding;
    preview_data.effect = video_setting_p->effect;
    preview_data.zoom_step = video_setting_p->zoom;

    /* other para */
    preview_data.brightness = video_setting_p->brightness;
    preview_data.contrast = video_setting_p->contrast;
    preview_data.saturation = video_setting_p->saturation;
    preview_data.hue = video_setting_p->hue;
    preview_data.gamma = 0;
    preview_data.night_mode = (video_setting_p->night==0)? MMI_FALSE:MMI_TRUE;

    /* Old interface support night_mode flag, so once night mode is on, we will force scene mode to be set as night mode. */
    if (preview_data.night_mode == MMI_TRUE)
        video_setting_p->dsc_mode = CAM_VIDEO_NIGHT;

    /* lcd */
    preview_data.force_lcd_hw_trigger = (kal_bool)mdi_video_p->is_enable_partial_display;
    mdi_video_p->is_lcd_update = is_lcd_update;
    preview_data.lcd_update = (kal_bool)is_lcd_update;
    preview_data.sharpness = video_setting_p->sharpness;
    preview_data.scene_mode = video_setting_p->dsc_mode;
    preview_data.af_operation_mode = video_setting_p->af_operation_mode;
    preview_data.af_range = video_setting_p->af_range;

    if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
    {
        preview_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
    }
    else
    {
        preview_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
    }

    preview_data.storage = video_setting_p->storage;
    switch (video_setting_p->video_size)
    {
        case MDI_VIDEO_VIDEO_SIZE_SQCIF:
            preview_data.image_width = 128;
            preview_data.image_height = 96;
            break;

        case MDI_VIDEO_VIDEO_SIZE_QQVGA:
            preview_data.image_width = 160;
            preview_data.image_height = 120;
            break;

        case MDI_VIDEO_VIDEO_SIZE_QCIF:
            preview_data.image_width = 176;
            preview_data.image_height = 144;
            break;

        case MDI_VIDEO_VIDEO_SIZE_QVGA:
            preview_data.image_width = 320;
            preview_data.image_height = 240;
            break;

        case MDI_VIDEO_VIDEO_SIZE_CIF:
            preview_data.image_width = 352;
            preview_data.image_height = 288;
            break;

        case MDI_VIDEO_VIDEO_SIZE_WQVGA:
            preview_data.image_width = 400;
            preview_data.image_height = 240;
            break;

        case MDI_VIDEO_VIDEO_SIZE_VGA:
            preview_data.image_width = 640;
            preview_data.image_height = 480;
            break;

        case MDI_VIDEO_VIDEO_SIZE_HVGA:
            preview_data.image_width = 480;
            preview_data.image_height = 320;
            break;

        case MDI_VIDEO_VIDEO_SIZE_D1:
            preview_data.image_width = 720;
            preview_data.image_height = 480;
            break;

        case MDI_VIDEO_VIDEO_SIZE_NHD:
            preview_data.image_width = 640;
            preview_data.image_height = 368;
            break;

        case MDI_VIDEO_VIDEO_SIZE_WVGA:
            preview_data.image_width = 800;
            preview_data.image_height = 480;
            break;

        case MDI_VIDEO_VIDEO_SIZE_CIF_2:
            preview_data.image_width = 432;
            preview_data.image_height = 240;
            break;

        case MDI_VIDEO_VIDEO_SIZE_WVGA_2:
            preview_data.image_width = 848;
            preview_data.image_height = 480;
            break;

        case MDI_VIDEO_VIDEO_SIZE_D1_2:
            preview_data.image_width = 720;
            preview_data.image_height = 576;
            break;

        case MDI_VIDEO_VIDEO_SIZE_SVGA:
            preview_data.image_width = 800;
            preview_data.image_height = 608;
            break;

        case MDI_VIDEO_VIDEO_SIZE_XGA:
            preview_data.image_width = 1024;
            preview_data.image_height = 768;
            break;

        case MDI_VIDEO_VIDEO_SIZE_720P:
            preview_data.image_width = 1280;
            preview_data.image_height = 720;
            break;

        case MDI_VIDEO_VIDEO_SIZE_4VGA:
            preview_data.image_width = 1280;
            preview_data.image_height = 960;
            break;

        case MDI_VIDEO_VIDEO_SIZE_SXGA:
            preview_data.image_width = 1280;
            preview_data.image_height = 1024;
            break;

        case MDI_VIDEO_VIDEO_SIZE_16CIF:
            preview_data.image_width = 1408;
            preview_data.image_height = 1152;
            break;

        case MDI_VIDEO_VIDEO_SIZE_4SVGA:
            preview_data.image_width = 1600;
            preview_data.image_height = 1200;
            break;

        case MDI_VIDEO_VIDEO_SIZE_FHD:
            preview_data.image_width = 1920;
            preview_data.image_height = 1088;
            break;
        case MDI_VIDEO_VIDEO_SIZE_4CIF:
            preview_data.image_width = 704;
            preview_data.image_height = 576;
            break;
        case MDI_VIDEO_VIDEO_SIZE_FWVGA:
            preview_data.image_width = 864;
            preview_data.image_height = 480;
            break;

        case MDI_VIDEO_VIDEO_SIZE_WP_QCIF:
            preview_data.image_width = 176;
            preview_data.image_height = 208;
            break;
            
        case MDI_VIDEO_VIDEO_SIZE_WP_QVGA:
            preview_data.image_width = 240;
            preview_data.image_height = 320;
            break;
            
        case MDI_VIDEO_VIDEO_SIZE_WP_WQVGA:
            preview_data.image_width = 240;
            preview_data.image_height = 400;
            break;
            
        case MDI_VIDEO_VIDEO_SIZE_WP_HVGA:
            preview_data.image_width = 320;
            preview_data.image_height = 480;
            break;
            
        case MDI_VIDEO_VIDEO_SIZE_WP_WVGA:
            preview_data.image_width = 480;
            preview_data.image_height = 800;
            break;

        case MDI_VIDEO_VIDEO_SIZE_USER_DEFINE:
            preview_data.image_width = video_setting_p->user_def_width;
            preview_data.image_height = video_setting_p->user_def_height;
            break;
    }

    preview_data.encode_quality = (U8) video_setting_p->video_qty;
    preview_data.bit_stream_type = (U8) video_setting_p->video_format;
    preview_data.encode_one_frame_duration = video_setting_p->encode_one_frame_duration;

    mdi_video_p->image_width = preview_data.image_width;
    mdi_video_p->image_height = preview_data.image_height;

    preview_data.seq_num = 0;

    gdi_layer_get_actual_rotate_value(preview_layer_handle, &physical_rotate);
    preview_data.ui_rot_angle = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);
    mdi_video_p->encode_rotate = preview_data.ui_rot_angle;
#ifdef __COSMOS_MMI_PACKAGE__
    if (mdi_video_p->force_ui_rotate != MDI_VIDEO_PREVIEW_ROTATE_RESET)
    {
        U16 rot_angle_diff;

        rot_angle_diff = MDI_VIDEO_ABS(preview_data.ui_rot_angle - mdi_video_p->force_ui_rotate);
        preview_data.ui_rot_angle = mdi_video_p->force_ui_rotate;
        
        /* lcd / preview related */
        if (rot_angle_diff == MDI_VIDEO_PREVIEW_ROTATE_90 || rot_angle_diff == MDI_VIDEO_PREVIEW_ROTATE_270)
        {
            preview_data.preview_width = blt_data.display_height;
            preview_data.preview_height = blt_data.display_width;
        }
    }
#endif

    gdi_layer_set_hw_update_layer(preview_layer_handle, KAL_FALSE);
    gdi_layer_set_blt_layer_previous();

    if (is_lcd_update == TRUE)
    {
        gdi_layer_set_hw_update_layer(preview_layer_handle,KAL_TRUE);
        gdi_lcd_set_hw_update(KAL_TRUE);
    }

    ret = media_vid_preview(module_id, &preview_data);

#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_p->force_ui_rotate = MDI_VIDEO_PREVIEW_ROTATE_RESET;
#endif
    if (ret != MED_RES_OK)
    {
        if (mdi_video_p->is_lcd_update == TRUE)
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
        }

        if (ret == MED_RES_MEM_INSUFFICIENT)
        {
            return MDI_RES_VDOREC_ERR_MEMORY_INSUFFICIENT;
        }
        else
        {
            return MDI_RES_VDOREC_ERR_HW_NOT_READY;
        }
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_preview_stop
 * DESCRIPTION
 *  To stop preview or recorder.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop preview.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop preview.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_preview_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    media_vid_rec_stop(module_id);

    if (mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    /* stop alywas return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_start
 * DESCRIPTION
 *  To start recording.
 * PARAMETERS
 *  filename : [IN]Video clip's filename.
 *  record_result_callback :[IN]Record result callback function ptr.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to start recording.
 *  MDI_RES_VDOREC_ERR_DISK_FULL : Fail to start recording due to disk is full.
 *  MDI_RES_VDOREC_ERR_WRITE_PROTECTION : Fail to start recording due to disk is in write protection mode.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to start recording due to open file fail.
 *  MDI_RES_VDOREC_ERR_RECORD_FAILED : Fail to start recording.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_start(S8 *filename, mdi_record_result_callback record_result_callback,void *user_data)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_req_struct record;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(record_result_callback != NULL);

    mdi_video_rec_record_result_callback = record_result_callback;

    SetProtocolEventHandler(mdi_video_rec_record_result_hdlr, MSG_ID_MEDIA_VID_RECORD_FINISH_IND);

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_CAMCORDER_STATE_CHANGED,(void*) TRUE);
#endif


    record.media_mode = MED_MODE_FILE;
    record.data = (void*)filename;
    record.record_audio = (U8) video_setting_p->record_aud;
    record.file_size_limit = (U32) (video_setting_p->size_limit * 1024); /* K */ ;
    record.time_limit = (U32)video_setting_p->time_limit;
    record.seq_num = mdi_video_p->record_seq_num;
    record.encode_quality = (U8) video_setting_p->video_qty;
    record.encode_rotate = mdi_video_p->encode_rotate;
    record.image_width = mdi_video_p->image_width;
    record.image_height = mdi_video_p->image_height;

    mdi_video_p->rec_user_data = user_data;

    ret = media_vid_record(module_id, &record);

    if (ret != MED_RES_OK)
    {
        if (mdi_video_p->is_lcd_update == TRUE)
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
        }

        switch (ret)
        {
            case MED_RES_DISC_FULL:
                return MDI_RES_VDOREC_ERR_DISK_FULL;
            case MED_RES_OPEN_FILE_FAIL:
                return MDI_RES_VDOREC_ERR_FAILED;
            case MED_RES_WRITE_PROTECTION:
                return MDI_RES_VDOREC_ERR_WRITE_PROTECTION;
            case MED_RES_MEM_INSUFFICIENT:
                return MDI_RES_VDOREC_ERR_MEMORY_INSUFFICIENT;
            case MED_RES_BUFFER_INSUFFICIENT:
                return MDI_RES_VDOREC_ERR_STORAGE_INSUFFICIENT;
            default:
                return MDI_RES_VDOREC_ERR_RECORD_FAILED;
        }
    }
#else
    mdi_video_p->rec_user_data = user_data;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    mdi_video_p->is_recording = TRUE;
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_stop
 * DESCRIPTION
 *  To stop recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop recording.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop recording.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->record_seq_num++;
    media_vid_rec_stop(module_id);

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_CAMCORDER_STATE_CHANGED, (void*)FALSE);
#endif

    if (mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    mdi_video_p->is_recording = FALSE;

    /* stop always return succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_pause
 * DESCRIPTION
 *  To pause recording.
 * PARAMETERS
 *  stop_preview : [IN] To stop preview or not.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to pause recording.
 *  MDI_RES_VDOREC_RECORD_ALREADY_STOP : Fail to pause recording due to it is already stopped.
 *  MDI_RES_VDOREC_REACH_SIZE_LIMIT : Fail to pause recording due to due to it is reached record size limitation (already stopped).
 *  MDI_RES_VDOREC_ERR_DISK_FULL : Fail to pause recording due to disk is full (already stopped).
 *  MDI_RES_VDOREC_ERR_PAUSE_FAILED : Fail to pause recording.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_pause(MMI_BOOL stop_preview)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_pause_req_struct pause_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    pause_data.stop_preview = (kal_bool)stop_preview;

    ret = media_vid_pause(module_id, &pause_data);

    if ((stop_preview == MMI_TRUE || ret != MED_RES_OK)&& mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }

    mdi_video_p->is_recording = FALSE;

    if (ret == MED_RES_BUSY)
    {
        /*
         * ret ==  MED_RES_BUSY many happend at one cirtical situation.
         * When driver recorde almost reach time limit, and user keep pause-resume,
         *
         * So the driver will send play finish msg to MDI as follow timing.
         *
         * ResumeA   PauseA   ResumeB  PauseB
         * |         |        |        |
         * --|----x----|--------|---x----|--------
         * |                 |
         * finish msg--------->
         * MMI receive msg here
         *
         * so the PauseA and ResumeB will return MED_RES_BUSY and shall ignore.
         */

        /* increase the flag, will ignore recrod finish hdlr from media */
        mdi_video_p->record_seq_num++;

        /*
         * mmi see this return shall enter saving handling procedure, since
         * the record finish callback will not be called
         */
        return MDI_RES_VDOREC_RECORD_ALREADY_STOP;

    }
    else if (ret == MED_RES_END_OF_FILE)
    {
        return MDI_RES_VDOREC_REACH_SIZE_LIMIT;
    }
    else if (ret == MED_RES_STOP_TIME_REACHED)
    {
        return MDI_RES_VDOREC_REACH_TIME_LIMIT;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        return MDI_RES_VDOREC_DISK_FULL;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_PAUSE_FAILED;
    }
    else
    {
        return MDI_RES_VDOREC_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    mdi_video_p->is_recording = FALSE;
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_resume
 * DESCRIPTION
 *  To resume recording.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to resume recording.
 *  MDI_RES_VDOREC_RECORD_ALREADY_STOP : Fail to resume recording due to it is already stopped.
 *  MDI_RES_VDOREC_ERR_RESUME_FAILED : Fail to resume recording.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_record_resume(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_resume(module_id);

    if (ret != MED_RES_OK && mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }
    
    if (ret == MED_RES_BUSY)
    {
        /*
         * ret ==  MED_RES_BUSY many happend at one cirtical situation.
         * When driver recorde almost reach time limit, and user keep pause-resume,
         *
         * So the driver will send play finish msg to MDI as follow timing.
         *
         * ResumeA   PauseA   ResumeB  PauseC
         * |         |        |        |
         * --|----x----|--------|---x----|--------
         * |                 |
         * finish msg--------->
         * MMI receive msg here
         *
         * so the PauseA and ResumeB will return MED_RES_BUSY and shall ignore.
         */

        /* increase the flag, will ignore recrod finish hdlr from media */
        mdi_video_p->record_seq_num++;

        /*
         * mmi see this return shall enter saving handling procedure, since
         * the record finish callback will not be called
         */
        return MDI_RES_VDOREC_RECORD_ALREADY_STOP;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        return MDI_RES_VDOREC_DISK_FULL;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_RESUME_FAILED;
    }
    else
    {
        mdi_video_p->is_recording = TRUE;
        return MDI_RES_VDOREC_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    mdi_video_p->is_recording = TRUE;        
    return MDI_RES_VDOREC_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_cur_record_time
 * DESCRIPTION
 *  To get current recorded time.
 * PARAMETERS
 *  cur_record_time : [OUT]Current recorded time.
 * RETURNS
 *  void
 ****************************************************************************/
void mdi_video_rec_get_cur_record_time(U64 *cur_record_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* time scale is [ms] */
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_get_current_record_time(module_id, cur_record_time);
#else
    *cur_record_time += 1000;
#endif
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_record_frame_num
 * DESCRIPTION
 *  To get current recorded frame num.
 * PARAMETERS
 *  cur_record_num : [OUT] Current recorded frame num.
 * RETURNS
 *  void
 ****************************************************************************/
void mdi_video_rec_get_record_frame_num(U64 *cur_record_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* time scale is [ms] */
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_get_current_record_frame_num(module_id, cur_record_num);
#else
    *cur_record_num += 1;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_has_unsaved_file
 * DESCRIPTION
 *  To check if there is an unsaved video clip.
 * PARAMETERS
 *  filepath : [IN]Path to check.
 * RETURN VALUES
 *  MMI_TRUE : There is unsaved video clip.
 *  MMI_FALSE : There is no unsaved video clip.
 *****************************************************************************/
BOOL mdi_video_rec_has_unsaved_file(S8 *filepath)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id ;
#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif

#ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_MWREC);

    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_MWREC, NULL, NULL);
    }
#endif

    module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_check_unfinished_file(module_id, (kal_wchar*)filepath);

#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);
    }
#endif


    return ret;
#else
    return FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_delete_unsaved_file
 * DESCRIPTION
 *  To delete unsaved video file.
 * PARAMETERS
 *  filepath : [IN]Path of unsaved video temp file to be deleted.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_delete_unsaved_file(S8 *filepath)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif

#ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_MWREC);

    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_MWREC, NULL, NULL);
    }
#endif
    media_vid_clean_temp_files(module_id);
#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);
    }
#endif

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_save_file
 * DESCRIPTION
 *  To merge and save file in non-blocking mode.
 * PARAMETERS
 *  filepath : [IN]Path to merge file.
 *  save_result_callback : [IN]Callback function for this operation.
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to send save request to media task.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to send save request to media task.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_save_file(S8 *filepath, mdi_save_result_callback save_result_callback, void* user_data)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_req_struct merge_data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(save_result_callback != NULL);

    mdi_video_rec_save_result_callback = save_result_callback;
    mdi_video_p->rec_user_data = user_data;

    SetProtocolEventHandler(mdi_video_rec_save_result_hdlr, MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND);

    merge_data.file_path = (kal_wchar*)filepath;
    media_vid_file_merge(module_id, &merge_data);


#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    FS_HANDLE file_h;

    file_h = FS_Open((U16*)filepath, FS_CREATE);

    if (file_h > 0)
    {
        FS_Close(file_h);
    }

    mdi_video_rec_save_result_callback = save_result_callback;
    mdi_video_p->rec_user_data = user_data;

    gui_start_timer(100, mdi_video_rec_dummy_save_file_result_hdlr);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_save
 * DESCRIPTION
 *  To stop record saving
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to stop save operation.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop save operation.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_stop_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /* stop saving */
    media_vid_rec_stop(module_id);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_flash_setting
 * DESCRIPTION
 *  Turn on/off LED flash light
 * PARAMETERS
 *  is_on       [IN]    On/off 
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_flash_setting(BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->flash = (is_on==KAL_FALSE)? 0:1;
    
    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_FLASH_MODE, video_setting_p->flash);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_saturation
 * DESCRIPTION
 *  Update saturation setting value
 * PARAMETERS
 *  cam_para        [IN]        Saturation setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_saturation(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->saturation = cam_para;

    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_SATURATION, cam_para);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_contrast
 * DESCRIPTION
 *  Update contrast setting value
 * PARAMETERS
 *  cam_para        [IN]        Contrast setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_contrast(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->contrast = cam_para;

    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_CONTRAST, cam_para);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_sharpness
 * DESCRIPTION
 *  Update sharpness setting value
 * PARAMETERS
 *  cam_para        [IN]        Sharpness setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_sharpness(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->sharpness = cam_para;

    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_SHARPNESS, cam_para);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_hue
 * DESCRIPTION
 *  Update hue setting value
 * PARAMETERS
 *  cam_para        [IN]        Hue setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_hue(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->hue = cam_para;
    // doesn't support now
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_ev
 * DESCRIPTION
 *  To update ev setting value.
 * PARAMETERS
 *  para : [IN]Ev setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
void mdi_video_rec_update_para_ev(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->setting.ev = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_EV_VALUE, para);
#endif

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_effect
 * DESCRIPTION
 *  To update effect setting value.
 * PARAMETERS
 *  para : [IN]Effect setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_effect(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->effect = para;
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_IMAGE_EFFECT, para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_wb
 * DESCRIPTION
 *  To update wb setting value.
 * PARAMETERS
 *  para : [IN]White balance setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_wb(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->wb = para;
 
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_WB, para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_night
 * DESCRIPTION
 *  To update night mode setting value
 * PARAMETERS
 *  para : [IN]Night mode setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_night(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    video_setting_p->night = para;
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    if (video_setting_p->night)
    {
        value = CAM_NIGHTSCENE;
    }
    else
    {
        value = CAM_AUTO_DSC;
    }

    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_SCENE_MODE, value);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_zoom
 * DESCRIPTION
 *  To update zoom setting value
 * PARAMETERS
 *  para : [IN]Zoom setting parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_zoom(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);

    if (mdi_video_p->is_poweron == FALSE)
        DCM_Load(DYNAMIC_CODE_COMPRESS_MWREC, NULL, NULL);

    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
#endif

    mdi_video_p->setting.zoom = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_DIGITAL_ZOOM, para);
#endif

#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }
    if (mdi_video_p->is_poweron == FALSE)
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);
#endif


}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_rec_size
 * DESCRIPTION
 *  To update rec width & height
 * PARAMETERS
 *  image_width     [IN]        record image width
 *  image_height    [IN]        record image height
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_rec_size(U16 image_width, U16 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->image_width = image_width;
    mdi_video_p->image_height = image_height;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_load_default_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT]Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_load_default_setting(mdi_video_setting_struct *setting_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_rec_spec_struct spec_entry_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_rec_query_entry_num_of_video_spec_table();
    mdi_video_rec_get_video_spec_by_index(0, &spec_entry_struct, sizeof(spec_entry_struct));
    setting_p->wb = MDI_VIDEO_WB_AUTO;
    setting_p->ev = MDI_VIDEO_EV_0;
    setting_p->banding = MDI_VIDEO_BANDING_60HZ; /* TW: 60, CN: 50 */
    setting_p->effect = MDI_VIDEO_EFFECT_NOMRAL;
    setting_p->zoom = 0;
    setting_p->brightness = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->contrast = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->saturation = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->hue = 0;
    setting_p->preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_0;
    setting_p->lcm_rotate = MDI_LCD_ROTATE_0;

    setting_p->night = 0;

    setting_p->video_size = (U16) spec_entry_struct.video_size;
    setting_p->video_qty = MDI_VIDEO_REC_QTY_NORMAL;
    setting_p->size_limit = 0;
    setting_p->time_limit = 0;
    setting_p->record_aud = 1; /* TRUE */
    setting_p->video_format = spec_entry_struct.video_format;
    setting_p->user_def_width = 0;
    setting_p->user_def_height = 0;

    setting_p->dsc_mode = MDI_VIDEO_SCENE_MODE_AUTO;
    setting_p->af_operation_mode = MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE;
    setting_p->af_range = MDI_VIDEO_AF_RANGE_AUTO;
    setting_p->sharpness = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->storage = MDI_VIDEO_REC_STORAGE_PHONE;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_record_file_size
 * DESCRIPTION
 *  To get current record file size
 * PARAMETERS
*   void
 * RETURNS
 *  Current file size of the recording.
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
U64 mdi_video_rec_get_record_file_size(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_get_current_record_size(mdi_video_get_module_id(), &file_size);

    return file_size;
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return 0;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_pause
 * DESCRIPTION
 *  Pause for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume();
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : Succeed to pause to update blt layers.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to pause.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_update_blt_pause(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_pause_req_struct pause_data;
    MDI_RESULT ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_update_blt_pause(module_id, &pause_data);

    if (mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_blt_resume
 * DESCRIPTION
 *  Resume for update blt parameters, special function for Java use only; This function should be pariled with mdi_video_rec_resume_for_update_blt_para().
 * EXAMPLE
 *  mdi_video_rec_update_blt_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_rec_update_blt_resume();
 * PARAMETERS
 *  preview_layer_handle : [IN]Layer for preview.
 *  blt_layer_flag : [IN]Blt out layer flag.
 *  preview_layer_flag : [IN]Preview layer flag.
 *  is_lcd_update : [IN]Update lcd or not.
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to resume after updating blt layers.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to resume.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_update_blt_resume(
            gdi_handle preview_layer_handle,
            U32 blt_layer_flag,
            U32 preview_layer_flag,
            MMI_BOOL is_lcd_update)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_resume_req_struct update_data;
    MDI_RESULT ret;
    mdi_blt_para_struct blt_data;
    module_type module_id = mdi_video_get_module_id();
    kal_uint32 layer_element;
    gdi_color_format layer_format;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    U8 physical_rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_lcd_update == TRUE)
    {
        gdi_layer_set_hw_update_layer(preview_layer_handle, KAL_FALSE);
        gdi_layer_set_blt_layer_previous();

        gdi_layer_set_hw_update_layer(preview_layer_handle,KAL_TRUE);
        gdi_lcd_set_hw_update(KAL_TRUE);
    }

    /* call this function before calling mdi_calc_blt_para() */
    mdi_video_p->hw_update_layer_handle = preview_layer_handle;

    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    gdi_layer_push_and_set_active(mdi_video_p->hw_update_layer_handle);
    gdi_layer_get_color_format(&layer_format);
    if (layer_format != GDI_COLOR_FORMAT_UYVY422 && 
        mdi_video_p->hw_update_layer_handle)
    {
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);    
    }
    gdi_layer_pop_and_restore_active();
    #endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */
    
    mdi_calc_blt_para(
        preview_layer_handle,
        video_setting_p->lcm_rotate,
        mdi_video_p->lcd_handle,
        MMI_FALSE, 
        &blt_data);

    update_data.frame_buffer_addr1 = (kal_uint32)blt_data.image_buffer_p;
    update_data.frame_buffer_addr2 = (kal_uint32)blt_data.image_buffer_p_2;
    update_data.frame_buffer_size = blt_data.image_buffer_size;

    gdi_layer_get_actual_rotate_value(preview_layer_handle, &physical_rotate);
    update_data.ui_rot_angle = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);


    if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
    {
        update_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
    }
    else
    {
        update_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
    }

    update_data.lcd_id = MAIN_LCD;
    update_data.preview_offset_x = 0;  /* offset from lcd_offset_x, set as 0 */
    update_data.preview_offset_y = 0;  /* offset from lcd_offset_x, set as 0 */
    mdi_video_p->is_lcd_update = is_lcd_update;
    update_data.lcd_update = (kal_bool)is_lcd_update;

    /* lcd / preview related */
    update_data.buffer_width = blt_data.display_width;
    update_data.buffer_height = blt_data.display_height;
    update_data.preview_width = blt_data.display_width;
    update_data.preview_height = blt_data.display_height;

    gdi_layer_get_layer_element(
        preview_layer_flag,
        &layer_element,
        &blt_ctx,
        &blt_dev);

    update_data.layer_element = layer_element;
    update_data.blt_ctx = blt_ctx;
    update_data.blt_dev = blt_dev;

    ret = media_vid_update_blt_resume(module_id, &update_data);

    if (ret != MED_RES_OK && is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }
    
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOREC_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_save_result_hdlr
 * DESCRIPTION
 *  save result message hdlr
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_save_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_done_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_file_merge_done_ind_struct*) msg_ptr;

    if (ind_p->result == MED_RES_OK)
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_SUCCEED,mdi_video_p->rec_user_data);
    }
    else if (ind_p->result == MED_RES_DISC_FULL)
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_ERR_DISK_FULL,mdi_video_p->rec_user_data);
    }
    else if (ind_p->result == MED_RES_VIDEO_NO_FRAME_ENCODED)
    {   
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_ERR_NO_FRAME_ENCODED,mdi_video_p->rec_user_data);
    }
    else
    {
        mdi_video_rec_save_result_callback(MDI_RES_VDOREC_ERR_FAILED,mdi_video_p->rec_user_data);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_enable_partial_display
 * DESCRIPTION
 *  To enable video to preview outside lcd region
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOREC_SUCCEED : To enable partially display record preview data.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partially display record preview data.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_enable_partial_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->is_enable_partial_display = TRUE;

    /* always succeed */
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_dummy_save_file_result_hdlr
 * DESCRIPTION
 *  dummy save file result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_rec_dummy_save_file_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_rec_save_result_callback(MDI_RES_VDOREC_SUCCEED, mdi_video_p->rec_user_data);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_record_result_hdlr
 * DESCRIPTION
 *  record result message hdlr
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_record_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_finish_ind_struct *ind_p;
    MDI_RESULT ret = MDI_RES_VDOREC_ERR_FAILED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ind_p = (media_vid_record_finish_ind_struct*) msg_ptr;

    /* seq number not match, measn it is already stopped, ignore this message */
    if (mdi_video_p->record_seq_num != ind_p->seq_num)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    if (mdi_video_p->is_lcd_update == TRUE)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_CAMCORDER_STATE_CHANGED, (void*)TRUE);
#endif

    mdi_video_p->is_recording = FALSE;

    switch(ind_p->result)
    {
        case MED_RES_END_OF_FILE:
            ret = MDI_RES_VDOREC_REACH_SIZE_LIMIT;
            break;
        case MED_RES_STOP_TIME_REACHED:
            ret = MDI_RES_VDOREC_REACH_TIME_LIMIT;
            break;
        case MED_RES_DISC_FULL:
            ret = MDI_RES_VDOREC_DISK_FULL;
            break;  
        case MED_RES_BUSY:
            ret = MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW;
            break;  
    }

    mdi_video_rec_record_result_callback(ret,mdi_video_p->rec_user_data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_force_set_ui_rotate
 * DESCRIPTION
 *  [for COSMOS camcorder use] set the UI as portrait when preview is portrait but OSD is landscape.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to reset ui rotate.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_force_set_ui_rotate(U16 rotate)
{
#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_p->force_ui_rotate = rotate;
#endif    
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_reset_ui_rotate
 * DESCRIPTION
 *  [for COSMOS camcorder use] set UI rotate as reset value.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to reset ui rotate.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_reset_ui_rotate(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
    mdi_video_p->force_ui_rotate = MDI_VIDEO_PREVIEW_ROTATE_RESET;
#endif    
    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_start_fast_zoom
 * DESCRIPTION
 *  Start fast zoom [smooth zoom]
 * PARAMETERS
 *  zoom_in         [IN]        Zoom in/out
 *  zoom_limit      [IN]        MAX ZOOM FACTOR ==> 8x zoom should fill in 80.
 *  zoom_step       [IN]        How many zoom step to be operated per zoomin/zoomout operation.
 *  zoom_speed      [IN]        How many frame to be inserted in each zoomin/zoomout zoom step.
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
void mdi_video_rec_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_start_fast_zoom(mdi_video_get_module_id(),(kal_bool) zoom_in, zoom_limit, zoom_step, zoom_speed);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_fast_zoom
 * DESCRIPTION
 *  Stop fast zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_stop_fast_zoom(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_stop_fast_zoom(mdi_video_get_module_id());
#endif /* __MTK_TARGET__ */
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_fast_zoom_factor
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  factor      [OUT]   Zoom factor
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_get_fast_zoom_factor(U32 *factor)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    kal_bool is_loaded2 = KAL_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    if (mdi_video_p->is_poweron == FALSE)
    DCM_Load(DYNAMIC_CODE_COMPRESS_MWREC, NULL, NULL);
    
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
#endif

    media_vid_get_fast_zoom_factor(mdi_video_get_module_id(), factor, NULL);
#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }

    if (mdi_video_p->is_poweron == FALSE)
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWREC);    
#endif
    
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_reserved_buf_size
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  step        [OUT]   Zoom step
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_get_reserved_disc_size(U32 *size)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_get_reserved_disc_size(mdi_video_get_module_id(), size);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_fast_zoom_step
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  step        [OUT]   Zoom step
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_get_fast_zoom_step(U32 *step)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_get_fast_zoom_factor(mdi_video_get_module_id(), NULL, step);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_max_zoom_factor
 * DESCRIPTION
 *  Get max zoom factor
 * PARAMETERS
 *  image_width         [IN]        Image width
 *  image_height        [IN]        Image height
 * RETURNS
 *  Zoom factor value
 *****************************************************************************/
U16 mdi_video_rec_get_max_zoom_factor(S32 image_width, S32 image_height)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_resolution;
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((image_width <= LCD_WIDTH && image_height <= LCD_HEIGHT) ||
        (image_height <= LCD_WIDTH && image_height <= LCD_HEIGHT))
        image_resolution = MDI_CAMERA_CAP_SIZE_WALLPAPER;
    else if (image_width <= 320 && image_height <= 240)
        image_resolution = MDI_CAMERA_CAP_SIZE_QVGA;
    else if (image_width <= 640 && image_height <= 480)
        image_resolution = MDI_CAMERA_CAP_SIZE_VGA;
    else if (image_width <= 1280 && image_height <= 960)
        image_resolution = MDI_CAMERA_CAP_SIZE_1M;
    else if (image_width <= 1600 && image_height <= 1200)
        image_resolution = MDI_CAMERA_CAP_SIZE_2M;
    else if (image_width <= 2048 && image_height <= 1536)
        image_resolution = MDI_CAMERA_CAP_SIZE_3M;
    else if (image_width <= 2304 && image_height <= 1728)
        image_resolution = MDI_CAMERA_CAP_SIZE_4M;
    else if (image_width <= 3264 && image_height <= 2488)
        image_resolution = MDI_CAMERA_CAP_SIZE_8M;
    else
        image_resolution = MDI_CAMERA_CAP_SIZE_OTHER;

    zoom.image_size = image_resolution;
    zoom.result_p = &result;

#ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);

    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
#endif

    media_cam_sensor_query_zoom_info(mdi_video_get_module_id(), &zoom);

#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }

    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
#endif

    return result.MaxZoomFactor;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */ 
    return 40;  /* 4x zooming */
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_query_entry_num_of_video_spec_table
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  void
 * RETURNS
 *  row number of frame rate table in U16.
 *****************************************************************************/
U32 mdi_video_rec_query_entry_num_of_video_spec_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CUSTOM_VENC_ERROR_T eError;
    CUSTOM_VENC_USER_T eUser;
    kal_uint32 num_of_entry = 0;
    kal_uint32 temp_num = 0;
    CUSTOM_VENC_USER_T *user_table_p;
    kal_uint32 num_of_users = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    eError = CustomVenc_Ctrl_Get_NumOf_Recorder_Users(&user_table_p, &num_of_users);
    if (eError != CUSTOM_VENC_ERROR_NONE){ASSERT(0);}
    if (num_of_users<1){ASSERT(0);}    

    do{
        eUser = *(user_table_p);
        eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER,&eUser, sizeof(eUser), NULL, 0);
        eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES, NULL, 0, &temp_num, sizeof(temp_num));
        ASSERT(eError == CUSTOM_VENC_ERROR_NONE);

        num_of_entry += temp_num;
        user_table_p++;        
    }while(--num_of_users);
    
    return num_of_entry;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_query_bitrate
 * DESCRIPTION
 *  To get current recording's bitrate. this should be called after preview started.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to get bitrate.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to get correct bitrate.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_query_bitrate(mdi_video_rec_query_bitrate_struct* spec, U32* bitrate_p)
{

    MDI_RESULT ret = MDI_RES_VDOREC_SUCCEED ;
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    *bitrate_p = media_vid_recorder_get_bitrate();

    if ((*bitrate_p) == 0)
            ret = MDI_RES_VDOREC_ERR_FAILED;
#else
    *bitrate_p = MDI_VIDEO_DUMMY_BITRATE;
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_frame_rate_table_query_num_of_entry
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOREC_SUCCEED : Succeed to set camera id.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set camera id.
 *****************************************************************************/
MDI_RESULT mdi_video_rec_get_video_spec_by_index(U32 idx, mdi_video_rec_spec_struct * p_spec_entry_struct, U32 spec_struct_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CUSTOM_VENC_ERROR_T eError;
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;
    CUSTOM_VENC_USER_T eUser;
    kal_uint32 temp_num = 0;
    CUSTOM_VENC_USER_T *user_table_p;
    kal_uint32 num_of_users = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    eError = CustomVenc_Ctrl_Get_NumOf_Recorder_Users(&user_table_p, &num_of_users);
    if (eError != CUSTOM_VENC_ERROR_NONE){ASSERT(0);}
    if (num_of_users<1){ASSERT(0);}    

    do{
        eUser = *(user_table_p);
        eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER,&eUser, sizeof(eUser), NULL, 0);
        eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES, NULL, 0, &temp_num, sizeof(temp_num));
        if (eError != CUSTOM_VENC_ERROR_NONE) { ASSERT(0);}

        if(idx >= temp_num)
        {
            idx -= temp_num;   
        }
        else
        {
            break;
        }
        user_table_p++;        
    }while(1);

    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ONE_ENTRY, &idx, sizeof(idx), &rUpperTable, sizeof(rUpperTable));
    ASSERT(eError == CUSTOM_VENC_ERROR_NONE);

    switch(rUpperTable.eQuality)
    {
        case CUSTOM_VENC_QUALITY_LOW:
            p_spec_entry_struct->quality = (U16) MDI_VIDEO_REC_QTY_LOW;
            break;
        case CUSTOM_VENC_QUALITY_NORMAL:
            p_spec_entry_struct->quality = (U16) MDI_VIDEO_REC_QTY_NORMAL;
            break;
        case CUSTOM_VENC_QUALITY_GOOD:
            p_spec_entry_struct->quality = (U16) MDI_VIDEO_REC_QTY_HIGH;
            break;
        case CUSTOM_VENC_QUALITY_FINE:
            p_spec_entry_struct->quality = (U16) MDI_VIDEO_REC_QTY_FINE;
            break;
        case CUSTOM_VENC_QUALITY_ALL:
            p_spec_entry_struct->quality = (U16) MDI_VIDEO_REC_QTY_ALL;
            break;
    }

    switch(rUpperTable.eStorage)
    {
        case CUSTOM_VENC_STORAGE_SD:
            p_spec_entry_struct->storage = (U16) MDI_VIDEO_REC_STORAGE_SD;
            break;
        case CUSTOM_VENC_STORAGE_PHONE:
            p_spec_entry_struct->storage = (U16) MDI_VIDEO_REC_STORAGE_PHONE;
            break;
        case CUSTOM_VENC_STORAGE_ALL:
            p_spec_entry_struct->storage = (U16) MDI_VIDEO_REC_STORAGE_ALL;
            break;
    }

    switch(rUpperTable.eCodec)
    {
        case CUSTOM_VENC_CODEC_H263:
            p_spec_entry_struct->video_format = (U16) MDI_VIDEO_VIDEO_FORMAT_3GP;
            break;
        case CUSTOM_VENC_CODEC_MPEG4:
            p_spec_entry_struct->video_format = (U16) MDI_VIDEO_VIDEO_FORMAT_MP4;
            break;
        case CUSTOM_VENC_CODEC_MJPEG:
            p_spec_entry_struct->video_format = (U16) MDI_VIDEO_VIDEO_FORMAT_MJPEG;
            break;
        case CUSTOM_VENC_CODEC_H264:
            p_spec_entry_struct->video_format = (U16) MDI_VIDEO_VIDEO_FORMAT_H264;
            break;            

    }

    switch(rUpperTable.eResolution)
    {
        case CUSTOM_VENC_RESOLUTION_128x96:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_128x96;
            break;
        case CUSTOM_VENC_RESOLUTION_160x120:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_160x120;
            break;
        case CUSTOM_VENC_RESOLUTION_176x144:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_176x144;
            break;
        case CUSTOM_VENC_RESOLUTION_320x240:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_320x240;
            break;
        case CUSTOM_VENC_RESOLUTION_400x240:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_400x240;
            break;
        case CUSTOM_VENC_RESOLUTION_352x288:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_352x288;
            break;
        case CUSTOM_VENC_RESOLUTION_432x240:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_432x240;
            break;
        case CUSTOM_VENC_RESOLUTION_480x320:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x320;
            break;
        case CUSTOM_VENC_RESOLUTION_640x368:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_640x368;
            break;
        case CUSTOM_VENC_RESOLUTION_640x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_640x480;
            break;
        case CUSTOM_VENC_RESOLUTION_720x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_720x480;
            break;
        case CUSTOM_VENC_RESOLUTION_800x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_800x480;
            break;
        case CUSTOM_VENC_RESOLUTION_848x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_848x480;
            break;
        case CUSTOM_VENC_RESOLUTION_720x576:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_720x576;
            break;
        case CUSTOM_VENC_RESOLUTION_800x608:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_800x608;
            break;
        case CUSTOM_VENC_RESOLUTION_1024x768:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1024x768;
            break;
        case CUSTOM_VENC_RESOLUTION_1280x720:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1280x720;
            break;
        case CUSTOM_VENC_RESOLUTION_1280x960:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1280x960;
            break;
        case CUSTOM_VENC_RESOLUTION_1280x1024:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1280x1024;
            break;
        case CUSTOM_VENC_RESOLUTION_1408x1152:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1408x1152;
            break;
        case CUSTOM_VENC_RESOLUTION_1600x1200:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1600x1200;
            break;
        case CUSTOM_VENC_RESOLUTION_1920x1088:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1920x1088;
            break;
        case CUSTOM_VENC_RESOLUTION_704x576:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_704x576;
            break;
        case CUSTOM_VENC_RESOLUTION_864x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_864x480;
            break;

        case CUSTOM_VENC_RESOLUTION_96x128:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_96x128;
            break;
        case CUSTOM_VENC_RESOLUTION_120x160:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_120x160;
            break;
        case CUSTOM_VENC_RESOLUTION_144x176:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_144x176;
            break;
        case CUSTOM_VENC_RESOLUTION_240x320:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_240x320;
            break;
        case CUSTOM_VENC_RESOLUTION_240x400:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_240x400;
            break;
        case CUSTOM_VENC_RESOLUTION_288x352:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_288x352;
            break;
        case CUSTOM_VENC_RESOLUTION_240x432:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_240x432;
            break;
        case CUSTOM_VENC_RESOLUTION_320x480:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_320x480;
            break;
        case CUSTOM_VENC_RESOLUTION_368x640:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_368x640;
            break;
        case CUSTOM_VENC_RESOLUTION_480x640:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x640;
            break;
        case CUSTOM_VENC_RESOLUTION_480x720:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x720;
            break;
        case CUSTOM_VENC_RESOLUTION_480x800:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x800;
            break;
        case CUSTOM_VENC_RESOLUTION_480x848:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x848;
            break;
        case CUSTOM_VENC_RESOLUTION_576x720:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_576x720;
            break;
        case CUSTOM_VENC_RESOLUTION_608x800:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_608x800;
            break;
        case CUSTOM_VENC_RESOLUTION_768x1024:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_768x1024;
            break;
        case CUSTOM_VENC_RESOLUTION_720x1280:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_720x1280;
            break;
        case CUSTOM_VENC_RESOLUTION_960x1280:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_960x1280;
            break;
        case CUSTOM_VENC_RESOLUTION_1024x1280:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1024x1280;
            break;
        case CUSTOM_VENC_RESOLUTION_1152x1408:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1152x1408;
            break;
        case CUSTOM_VENC_RESOLUTION_1200x1600:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1200x1600;
            break;
        case CUSTOM_VENC_RESOLUTION_1088x1920:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_1088x1920;
            break;
        case CUSTOM_VENC_RESOLUTION_576x704:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_576x704;
            break;
        case CUSTOM_VENC_RESOLUTION_480x864:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_480x864;
            break;            
        case CUSTOM_VENC_RESOLUTION_176x208:
            p_spec_entry_struct->video_size = MDI_VIDEO_REC_RESOLUTION_176x208;
            break;
    }

    return MDI_RES_VDOREC_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_query_support_info
 * DESCRIPTION
 *  To query sensor info
 * PARAMETERS
 *  U32     info type
 *  void*   return info
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mdi_video_rec_query_support_info(U32 mdi_setting_type, void *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_sensor_query_capability_req_struct query;
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query.camera_mode = CAL_CAMERA_MODE_VIDEO;
    query.item_id = mdi_setting_type;
    query.struct_p = p_info;

#ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);

    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
#endif

    media_cam_sensor_query_capability(mdi_video_get_module_id(), &query);

#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    } 
    
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_query_zoom_info
 * DESCRIPTION
 *  To query zoom info
 * PARAMETERS
 *  mdi_camera_zoom_info*  return zoom info
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mdi_video_rec_query_zoom_info(mdi_camera_zoom_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    kal_bool is_loaded_CAMMED = KAL_FALSE;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zoom.image_size = 0; // don't care
    zoom.result_p = &result;
    zoom.camera_mode = CAL_CAMERA_MODE_VIDEO;

#ifdef __MM_DCM_SUPPORT__
    is_loaded_CAMMED = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMMED);

    if (!is_loaded_CAMMED)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
    }

    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);

    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
#endif

    media_cam_sensor_query_zoom_info(mdi_video_get_module_id(), &zoom);

#ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    } 

    if (!is_loaded_CAMMED)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
    }
#endif

    p_info->zoom_support_type = result.DzType;
    p_info->max_zoom_factor = result.MaxZoomFactor;
    p_info->zoom_steps = result.TotalZoomSteps;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_get_focus_zone
 * DESCRIPTION
 *  Get video_rec driver AF zone location for 6238 series and
 *  the location coordinate is the preview layer not LCD
 * PARAMETERS
 *  zone            [OUT]       AF zone structure
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_get_focus_zone(mdi_video_rec_af_window_struct* zone)
{
#if defined(AF_SUPPORT) && defined(__MTK_TARGET__)
    media_vid_af_zone_para_struct af_zone;
    U8 i = 0;
    media_vid_get_focus_zone(mdi_video_get_module_id(), &af_zone);

    zone->af_active_zone = af_zone.af_active_zone;

    for (;i<MDI_VIDEO_REC_AF_ZONE_MAX_NO; i++)
    {
        zone->af_zone[i].af_zone_h = af_zone.af_zone[i].af_zone_h;
        zone->af_zone[i].af_zone_w = af_zone.af_zone[i].af_zone_w;
        zone->af_zone[i].af_zone_x = af_zone.af_zone[i].af_zone_x;
        zone->af_zone[i].af_zone_y = af_zone.af_zone[i].af_zone_y;
    }
#endif /* AF_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_start_autofocus_process
 * DESCRIPTION
 *  Start to do auto focus process
 * PARAMETERS
 *  handler         [IN]        Auto focus finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_start_autofocus_process(mdi_video_rec_af_ind_callback handler, void* user_data)
{
#if defined(AF_SUPPORT) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_AF_KEY, CAM_AF_ONE_TIME);
    g_mdi_video_rec_af_callback = handler;
    mdi_video_p->user_data = user_data;

    SetProtocolEventHandler(mdi_video_rec_af_finish_ind, MSG_ID_MEDIA_VID_AF_PROCESS_DONE_IND);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_stop_autofocus_process
 * DESCRIPTION
 *  Stop auto focus process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_stop_autofocus_process(void)
{
#if defined(AF_SUPPORT) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_AF_KEY, CAM_AF_RELEASE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_af_finish_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  inMsg       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_af_finish_ind(void *inMsg)
{
#if defined(AF_SUPPORT) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_af_ind_struct *msg_p = (media_vid_af_ind_struct*) inMsg;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_video_rec_af_callback)
    {
        mdi_video_rec_af_result_struct af_result;
        af_result.af_result = (mdi_af_result_enum) msg_p->af_search_result;
        af_result.af_success_zone = msg_p->af_success_zone;
        g_mdi_video_rec_af_callback(af_result, mdi_video_p->user_data);
    }
#endif /* __MTK_TARGET__ */

}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_key
 * DESCRIPTION
 *  Update af key value
 * PARAMETERS
 *  cam_para        [IN]        AF key
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_af_key(U16 cam_para)
{
#if defined(AF_SUPPORT) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_AF_KEY, cam_para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_range
 * DESCRIPTION
 *  Update af range value
 * PARAMETERS
 *  cam_para        [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_af_range(U16 cam_para)
{
#if defined(AF_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->af_range = cam_para;
    media_vid_rec_set_param(mdi_video_get_module_id(), CAL_FEATURE_CAMERA_AF_RANGE_CONTROL, cam_para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_operation_mode
 * DESCRIPTION
 *  Update af operation mode value
 * PARAMETERS
 *  cam_para        [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_af_operation_mode(U16 cam_para)
{
#if defined(AF_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_setting_p->af_operation_mode = cam_para;

    media_vid_rec_set_param(mdi_video_get_module_id(),CAL_FEATURE_CAMERA_AF_OPERATION_MODE, cam_para);
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_mode
 * DESCRIPTION
 *  Update af mode value
 * PARAMETERS
 *  cam_para        [IN]        AF mode
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_af_mode(U16 cam_para)
{
#if defined(AF_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_rec_update_para_af_range(cam_para);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_update_para_af_metering
 * DESCRIPTION
 *  Update af metering value
 * PARAMETERS
 *  cam_para        [IN]        AF metering
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_update_para_af_metering(U16 cam_para)
{
#if defined(AF_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_rec_update_para_af_operation_mode(cam_para);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_rec_set_record_yuv
 * DESCRIPTION
 *  set to record YUV data
 * PARAMETERS
 *  is_yuv        [IN]        TRUE or FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_rec_set_record_yuv(MMI_BOOL is_yuv)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LOW_COST_SUPPORT_COMMON__
    media_vid_set_record_yuv(mdi_video_get_module_id(), (kal_bool)is_yuv);
#endif
}


#endif /* defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)*/ 

