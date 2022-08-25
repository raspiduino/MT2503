/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  mdi_camera.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access camera related functions.
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by P4 VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

#include "gdi_include.h"        /* include data type */
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "med_api.h"    /* media task */
#include "GlobalDefs.h"

#include "mdi_camera.h" /* include camera related define */

#include "gdi_lcd.h"  /*include for gdi_lcd_lock_mutex */

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"
#include <stdlib.h> /* for qsort() */

#if defined(ISP_SUPPORT)
   /* for visual effect */
#ifdef __MTK_TARGET__

#include "drv_sw_features_mdp.h"
#include "image_effect_post.h"

#endif /* __MTK_TARGET__ */ /* ISP_SUPPORT */
#endif /* defined(ISP_SUPPORT) */ 

#include "mmi_trc.h"            /* Debug Info */
#include "ConnectManageGProt.h"
#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "MMIDataType.h"
#include "cal_comm_def.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "FileMgrResDef.h"
#include "mmi_rp_srv_mdi_def.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "kal_active_module.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "lcd_sw_inc.h"
#include "img_common_enum.h"
#include "gdi_const.h"
#include "mm_comm_def.h"
#include "stack_msgs.h"
#include "image_effect_struct.h"
#include "gdi_lcd_config.h"
#include "jpeg_enum.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_media_app_trc.h"
#include "stack_config.h"
#include "cal_api.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "mav_comm_def.h"
#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

#include "drv_sw_features_color.h"

#ifdef __COLOR_HW_SUPPORTED__
#include "color_enum.h"
#include "color_api.h"
#include "color_structure.h"

COLOR_HANDLE g_mdi_camera_colorHandle;
#endif

extern void gdi_lcd_lock_mutex(void);
extern void gdi_lcd_unlock_mutex(void);

/***************************************************************************** 
* Typedef
*****************************************************************************/
/* camera state machine */
typedef enum
{
    CAMERA_STATE_POWER_OFF = 0,
    CAMERA_STATE_IDLE,
    CAMERA_STATE_PREVIEWING,
    CAMERA_STATE_STITCH_PANORAMA,
    CAMERA_STATE_HDR_PROCESSING,
    CAMERA_STATE_MAV_PROCESSING,
    CAMERA_STATE_DCM_LOADED
} mdi_camera_state_enum;
    
/***************************************************************************** 
* Define
*****************************************************************************/
#define CAM_LCD_RESOLUTION_SIZE     (LCD_WIDTH*LCD_HEIGHT)
#define CAM_QVGA_RESOLUTION_SIZE    (320*240)
#define CAM_VGA_RESOLUTION_SIZE     (640*480)
#define CAM_1M_RESOLUTION_SIZE      (1280*960)
#define CAM_2M_RESOLUTION_SIZE      (1600*1200)
#define CAM_3M_RESOLUTION_SIZE      (2048*1536)
#define CAM_4M_RESOLUTION_SIZE      (2304*1728)
#define CAM_5M_RESOLUTION_SIZE      (2592*1944)
#define CAM_8M_RESOLUTION_SIZE      (3264*2488)

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_camera_context_struct g_mdi_camera_cntx;
mdi_camera_context_struct *mdi_camera_p = &g_mdi_camera_cntx;
mdi_camera_setting_struct *camera_setting_p = &g_mdi_camera_cntx.setting;
mdi_camera_preview_struct *camera_preview_p = &g_mdi_camera_cntx.preview;
mdi_camera_overlay_struct *camera_overlay_p = NULL;

#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
static mdi_camera_panorama_stitch_result_callback g_mdi_camera_panorama_stitch_result_callback;
static mdi_camera_panorama_stitch_quickview_callback g_mdi_camera_panorama_stitch_quickview_callback;
#endif

#if defined(__MDI_CAMERA_HDR_SUPPORT__)
static mdi_camera_hdr_callback  g_mdi_camera_hdr_callback;
#endif

#ifdef __MDI_CAMERA_MAV_SUPPORT__
static mdi_camera_mav_result_callback  g_mdi_camera_mav_result_callback;
static mdi_camera_mav_capture_callback  g_mdi_camera_mav_capture_callback;
#endif

static mdi_camera_af_ind_callback g_mdi_camera_af_callback;
#if defined(__MDI_CAMERA_FD_SUPPORT__)
static mdi_camera_fd_callback g_mdi_camera_fd_callback;
static mdi_camera_on_sd_event_cb g_mdi_camera_sd_callback;
#endif
/* callback function */
void (*mdi_camera_non_block_burst_shot_result_callback) (MDI_RESULT, U16, void*) = NULL;

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    void (*mdi_xenon_flash_status_callback) (MDI_RESULT, void*) = NULL;
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
static MDI_RESULT mdi_camera_preview_start_internal(void);
static void mdi_camera_af_finish_ind(void *inMsg);
static void mdi_camera_panorama_result_ind(void *inMsg);
static void mdi_camera_panorama_quickview_result_ind(void *inMsg);

static void  mdi_camera_hdr_shot_result_hdlr(void *msg_ptr);

static void mdi_camera_non_block_burst_capture_result_hdlr(void *msg_ptr);
static void mdi_camera_fill_overlay_data(media_cam_capture_req_struct* capture_data);

static void mdi_camera_non_block_mav_capture_hdlr(void *msg_ptr);
static void mdi_camera_non_block_mav_result_hdlr(void *msg_ptr);

#if defined(__MDI_CAMERA_FD_SUPPORT__)
static void mdi_camera_fd_result_ind(void *inMsg);
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
static void mdi_camera_xenon_flash_ind(void *inMsg);
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_xenon_flash_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_camera_xenon_flash_ind(void *inMsg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_xenon_flash_ind_struct *msg_p = (media_cam_xenon_flash_ind_struct*) inMsg;
    U16 status = msg_p->status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_CAMERA_XENON_FLASH_STATUS,status);
    
    if (mdi_xenon_flash_status_callback)
    {   
        switch (status)
        {
            case CAM_XENON_FLASH_READY:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_SUCCEED, g_mdi_camera_cntx.user_data);
                break;
            case CAM_XENON_FLASH_CHARGING:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_XENONFLASH_CHARGING, g_mdi_camera_cntx.user_data);
                break;
            case CAM_XENON_FLASH_TIMEOUT:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT, g_mdi_camera_cntx.user_data);
                break;
            case CAM_XENON_FLASH_LOW_BATTERY:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY, g_mdi_camera_cntx.user_data);
                break;
        }
    }
#endif /* __MTK_TARGET__ */ 
}
#endif /* __MDI_CAMERA_XENON_FLASH_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   [IN]     Error code got from MDI APIs
 *  popup_type   [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
MMI_ID_TYPE mdi_camera_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
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
        case MDI_RES_CAMERA_ERR_FAILED:
            string_id = STR_GLOBAL_ERROR;
            break;
        case MDI_RES_CAMERA_ERR_DISK_FULL:
            string_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
            string_id = STR_ID_MDI_COMMON_WRITE_PROTECTION;
            break;
        case MDI_RES_CAMERA_ERR_NO_DISK:
            string_id = FMGR_FS_DRIVE_NOT_FOUND_TEXT;
            break;             
        case MDI_RES_CAMERA_ERR_HW_NOT_READY:
            string_id = STR_ID_MDI_COMMON_HW_NOT_READY;
            break;
        case MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_RES_CAMERA_ERR_PREVIEW_FAILED:
            string_id = STR_ID_MDI_CAMERA_PREVIEW_FAILED;
            break;
        case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
            string_id = STR_ID_MDI_CAMERA_CAPTURE_FAILED;
            break;
        case MDI_RES_CAMERA_ERR_ROOT_DIR_FULL:
            string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT:
            string_id = STR_ID_MDI_CAMERA_XENONFLASH_TIMEOUT;
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY:
            string_id = STR_ID_MDI_CAMERA_XENONFLASH_LOW_BATTERY;
            break;
        case MDI_RES_CAMERA_ERR_CBM_BEARER_ERROR:
            srv_cbm_get_nwk_srv_error_info(SRV_CBM_ERROR, &string_id, popup_type);
            break;
        case MDI_RES_CAMERA_ERR_SAVE_FAILED:
            string_id = STR_GLOBAL_FAILED_TO_SAVE;
            break;
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_init
 * DESCRIPTION
 *  Init MDI camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED  Success
 *****************************************************************************/
MDI_RESULT mdi_camera_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    mdi_camera_p->seq_num = 0;
    mdi_camera_p->stitch_seq_num = 0;
    mdi_camera_p->burst_cap_count = 0;
    #if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
    mdi_camera_p->hw_rotate = MDI_CAMERA_PREVIEW_ROTATE_0;
    #endif
    mdi_camera_p->cam_id = MDI_CAMERA_MAIN;

    return MDI_RES_CAMERA_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor
 * PARAMETERS
 *  camera_id       [IN]    Camera id [main or sub]
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_set_camera_id(U16 camera_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_camera_id_req_struct cam_id_data;
    kal_int32 ret = 0;
#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
        is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
        if (!is_loaded){
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
    }
    #endif 

    cam_id_data.cam_id = camera_id;
    ret = media_cam_set_cam_id(stack_get_active_module_id(), &cam_id_data);
    
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        if (!is_loaded){
            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        }
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
    }
    #endif
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_capture_rotation(U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_camera_cntx.capture_rotate = value;
   
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_quickview_rotation
 * DESCRIPTION
 *  Set UI rotation value
 * PARAMETERS
 *  value           [IN]    rotation value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_quickview_rotation(U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_camera_cntx.quickview_rotate = value;
   
}

#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
static MDI_RESULT mdi_camera_power_on_internal(U16 app_id)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_cam_power_up_req_struct cam_powerup_data;
#if defined(__MDI_CAMERA_BLOCK_GPRS__)
    srv_cbm_result_error_enum cbm_result;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MDI_CAMERA_BLOCK_GPRS__)
    cbm_result = cbm_register_app_id(&mdi_camera_p->cbm_app_id);
    if (cbm_result != 0)
    {
        /* shoult not reach here */
        ASSERT(0);
        return MDI_RES_CAMERA_ERR_CBM_BEARER_ERROR;
    }
    cbm_result = srv_cbm_disallow_nwk_srv(SRV_CBM_BEARER_GPRS, mdi_camera_p->cbm_app_id);
    if (cbm_result != 0)
    {
        return MDI_RES_CAMERA_ERR_CBM_BEARER_ERROR;
    }
#endif
    /* check if state is right */
    ASSERT(mdi_camera_p->state == CAMERA_STATE_POWER_OFF);
#ifdef MDP_SUPPORT_HW_OVERLAP
    ASSERT(camera_overlay_p == NULL);
#endif

#ifdef __MDI_CAMERA_HW_ROTATOR_SUPPORT__
    mdi_camera_p->hw_rotate = MDI_CAMERA_PREVIEW_ROTATE_0;
#endif

    mdi_camera_p->app_id = app_id;
    cam_powerup_data.seq_num = mdi_camera_p->seq_num;
    cam_powerup_data.cam_id = mdi_camera_p->cam_id;
    cam_powerup_data.app_id = mdi_camera_p->app_id;

    #ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    #endif

    ret = media_cam_power_up(stack_get_active_module_id(), (void*)&cam_powerup_data);

    if (ret == MED_RES_OK)
    {
        /* Power On succeed */
        mdi_camera_p->state = CAMERA_STATE_IDLE;
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        #ifdef __MM_DCM_SUPPORT__
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
        #endif  

        mdi_camera_p->cam_id = MDI_CAMERA_MAIN;
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MTK_TARGET__ */ 
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}


static MDI_RESULT mdi_camera_power_off_internal(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_power_down(stack_get_active_module_id(), 100);

    #ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
    #endif  
        
    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    mdi_camera_p->seq_num++;

#if defined(__MDI_CAMERA_BLOCK_GPRS__)
    srv_cbm_allow_nwk_srv(SRV_CBM_BEARER_GPRS, mdi_camera_p->cbm_app_id);
    cbm_deregister_app_id(mdi_camera_p->cbm_app_id);
#endif

#ifdef MDP_SUPPORT_HW_OVERLAP
    if (camera_overlay_p!=NULL)
    {
        OslMfree((S8*)camera_overlay_p);
        camera_overlay_p = NULL;
    }
#endif
    mdi_camera_p->cam_id = MDI_CAMERA_MAIN;
    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    mdi_camera_p->cam_id = MDI_CAMERA_MAIN;
    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 

}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_on
 * DESCRIPTION
 *  Power on the camera module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_power_on(U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_MDICAM, NULL, NULL);
#endif

    result = mdi_camera_power_on_internal(app_id);

#ifdef __MM_DCM_SUPPORT__
    if (result != MDI_RES_CAMERA_SUCCEED)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MDICAM);
    }
#endif

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_off
 * DESCRIPTION
 *  Power off the camera module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *****************************************************************************/
MDI_RESULT mdi_camera_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_camera_power_off_internal();

#ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MDICAM);
#endif

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start_with_capmode
 * DESCRIPTION
 *  Start camera preview with capture mode.
 *  Zero shutter delay or auto scene detection capture mode needs to be known 
 *  when previewing.
 * PARAMETERS
 *  preview_p                   [IN]        Preview data
 *  setting_p                   [IN]        Setting data
 *  capture_mode                [IN]        Capture mode
 *  user_data                   [IN]        User data
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
MDI_RESULT mdi_camera_preview_start_with_capmode(
            mdi_camera_preview_struct *preview_p,
            mdi_camera_setting_struct *setting_p,
            U8 capture_mode,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    ASSERT(preview_p->preview_layer_flag > 0);

    g_mdi_camera_cntx.is_tvout = preview_p->is_tvout;
    g_mdi_camera_cntx.user_data = user_data;
    g_mdi_camera_cntx.capture_mode = capture_mode;
    /* 
     * Note, src_key_color in camera_preview_p only needs for MT6218 with backend, for MT6218,
     * we only support 16 bit color depth, so, U16 is enoguth 
     */
     
    /* init camera parameters */
    memcpy(camera_preview_p, preview_p, sizeof(mdi_camera_preview_struct));
    memcpy(camera_setting_p, setting_p, sizeof(mdi_camera_setting_struct));

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    mdi_xenon_flash_status_callback = setting_p->xenon_flash_status_callback;
    SetProtocolEventHandler(mdi_camera_xenon_flash_ind, MSG_ID_MEDIA_CAM_XENON_FLASH_STATUS_IND);
#endif

    mdi_camera_update_para_image_size(camera_setting_p->image_width, camera_setting_p->image_height);

    if (mdi_camera_p->state == CAMERA_STATE_IDLE)
    {
        ret = mdi_camera_preview_start_internal();

        if (ret >= 0)
        {
            /* preview successfully */
            mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        }

        return ret;
    }
    else
    {
        /* start preview at wrong state */
    #ifndef __MTK_TARGET__  /* MNT Simulator */
        /* on MNT, direct call internal function for debugging */
        mdi_camera_preview_start_internal();
        return MDI_RES_CAMERA_SUCCEED;

    #else /* __MTK_TARGET__ */ 
        /* Target */
        return MDI_RES_CAMERA_ERR_FAILED;
    #endif /* __MTK_TARGET__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start
 * DESCRIPTION
 *  Start camera preview
 * PARAMETERS
 *  preview_p                   [IN]        Preview data
 *  setting_p                   [IN]        Setting data
 *  user_data                   [IN]        User data
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_preview_start(
            mdi_camera_preview_struct *preview_p,
            mdi_camera_setting_struct *setting_p,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_camera_preview_start_with_capmode(
                preview_p, 
                setting_p, 
                MDI_CAMERA_CAP_MODE_NORMAL, 
                user_data);
}


static void mdi_camera_fillin_preview_data(media_cam_preview_req_struct* cam_preview_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf_ptr1 = NULL;
    U8 *buf_ptr2 = NULL;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    gdi_color_format layer_format;
    U8 layer_rotate;
    U8 physical_rotate; 
    S32 lcd_width;
    S32 lcd_height;
    S32 clip_x1,clip_x2,clip_y1,clip_y2;
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get layer info */
    gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);
    
    gdi_layer_get_buffer_ptr(&buf_ptr1);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gdi_layer_get_clip(&clip_x1,&clip_y1,&clip_x2,&clip_y2);
    layer_rotate = gdi_layer_get_rotate();
    gdi_layer_get_color_format(&layer_format);
    
    if (gdi_layer_is_double(camera_preview_p->preview_layer_handle))
    {
        gdi_layer_toggle_double();
        gdi_layer_get_buffer_ptr(&buf_ptr2);
    }
    else
    {
        buf_ptr2 = buf_ptr1;
    }
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_layer_element(
        camera_preview_p->preview_layer_flag,
        &layer_element,
        &blt_ctx,
        &blt_dev);

    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    if (layer_format != GDI_COLOR_FORMAT_UYVY422 && 
        camera_preview_p->preview_layer_handle)
    {
        gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
        gdi_layer_get_color_format(&layer_format);
        gdi_layer_pop_and_restore_active();
    }
    #endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */

    /* preview on whihc lcm */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_MAINLCD)
    {
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        lcd_width = LCD_WIDTH;
        lcd_height = LCD_HEIGHT;
    }
    else
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    }

    cam_preview_data->preview_offset_x = (layer_offset_x < 0) ? 0 : layer_offset_x;
    cam_preview_data->preview_offset_y = (layer_offset_y < 0) ? 0 : layer_offset_y;
    cam_preview_data->preview_width = camera_setting_p->preview_width;
    cam_preview_data->preview_height = camera_setting_p->preview_height;
  
    cam_preview_data->lcd_update = (kal_bool)camera_preview_p->is_lcd_update;

    cam_preview_data->frame_buffer1_address = (kal_uint32)buf_ptr1;
    cam_preview_data->frame_buffer2_address = (kal_uint32)buf_ptr2;
    cam_preview_data->frame_buffer_size =
                        (kal_uint32) (( camera_setting_p->preview_width * 
                                        camera_setting_p->preview_height *
                                        GDI_LAYER.act_bit_per_pixel) >> 3);    

    cam_preview_data->layer_element = layer_element;
    cam_preview_data->blt_ctx = blt_ctx;
    cam_preview_data->blt_dev = blt_dev;
    
    cam_preview_data->image_width = (kal_uint16) camera_setting_p->image_width;
    cam_preview_data->image_height = (kal_uint16) camera_setting_p->image_height;

    /* set settings parameters */
    cam_preview_data->effect = (kal_uint16) camera_setting_p->effect;
    cam_preview_data->WB = (kal_uint16) camera_setting_p->wb;
    cam_preview_data->exposure = (kal_uint16) camera_setting_p->ev;
    cam_preview_data->zoom_step = (kal_uint16) camera_setting_p->zoom;
    cam_preview_data->banding_freq = (kal_uint8) camera_setting_p->banding;
    cam_preview_data->flash_mode = (kal_uint16) camera_setting_p->flash;

    cam_preview_data->sharpness_level = (kal_uint8) camera_setting_p->sharpness;
    cam_preview_data->contrast = (kal_uint16) camera_setting_p->contrast;
    cam_preview_data->saturation = (kal_uint16) camera_setting_p->saturation;
    cam_preview_data->hue = (kal_uint16) camera_setting_p->hue;

    /* ISP Setting */
    cam_preview_data->ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data->af_operation_mode = (kal_uint16) camera_setting_p->af_operation_mode;
    cam_preview_data->af_range = (kal_uint8) camera_setting_p->af_range;

    /*
     *  To switch ISO mode to DSC mode.
     *  When ISO >= 800, need to enable binning mode.
     */
    cam_preview_data->binning_mode = MMI_FALSE; 
    if (camera_setting_p->iso == MDI_CAMERA_ISO_AUTO)
    {
        cam_preview_data->scene_mode = (kal_uint8) camera_setting_p->scene_mode;
    }
    else
    {
        switch (camera_setting_p->iso)
        {
            case MDI_CAMERA_ISO_100:
                cam_preview_data->scene_mode = CAM_ISO100;
                break;
            case MDI_CAMERA_ISO_200:
                cam_preview_data->scene_mode = CAM_ISO200;
                break;
            case MDI_CAMERA_ISO_400:
                cam_preview_data->scene_mode = CAM_ISO400;
                break;
            case MDI_CAMERA_ISO_800:
                cam_preview_data->scene_mode = CAM_ISO800;
                break;                
            case MDI_CAMERA_ISO_1600:
                cam_preview_data->scene_mode = CAM_ISO1600;
                break;
            default:
                break;
        }
        
        if (cam_preview_data->scene_mode == CAM_ISO800 || 
            cam_preview_data->scene_mode == CAM_ISO1600 )
            cam_preview_data->binning_mode = MMI_TRUE;
    }
    /* IDP Setting */
    cam_preview_data->image_data_format = camera_setting_p->preview_format = IMG_COLOR_FMT_RGB565;
    cam_preview_data->capture_mode = g_mdi_camera_cntx.capture_mode;

    cam_preview_data->overlay_frame_mode = (kal_bool)camera_setting_p->overlay_frame_mode;
    cam_preview_data->overlay_color_depth = camera_setting_p->overlay_frame_depth;
    cam_preview_data->overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    cam_preview_data->overlay_frame_width = camera_setting_p->overlay_frame_width;
    cam_preview_data->overlay_frame_height = camera_setting_p->overlay_frame_height;
    cam_preview_data->overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
    cam_preview_data->overlay_palette_size = camera_setting_p->overlay_palette_size;
    cam_preview_data->overlay_palette_addr = camera_setting_p->overlay_palette_addr;

    if (layer_format == GDI_COLOR_FORMAT_UYVY422)
    {
        cam_preview_data->image_data_format = camera_setting_p->preview_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
    }
    else
    {
        cam_preview_data->image_data_format = camera_setting_p->preview_format = MM_IMAGE_FORMAT_RGB565;
    }

    /* rotate */
    physical_rotate = layer_rotate;
    gdi_layer_get_actual_rotate_value(camera_preview_p->preview_layer_handle, &physical_rotate);
    cam_preview_data->ui_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);
    g_mdi_camera_cntx.capture_rotate = cam_preview_data->ui_rotate;
    g_mdi_camera_cntx.quickview_rotate = cam_preview_data->ui_rotate;
    /* fixed para */
    cam_preview_data->gamma = 0;

    gdi_layer_get_blt_layer_flag(&camera_preview_p->blt_layer_flag);
    ASSERT(camera_preview_p->blt_layer_flag > 0);
    cam_preview_data->update_layer = camera_preview_p->blt_layer_flag;
    cam_preview_data->hw_update_layer = camera_preview_p->preview_layer_flag;
    cam_preview_data->src_key_color = camera_preview_p->src_key_color;   /* GDI_COLOR_TRANSPARENT */
    cam_preview_data->roi_background_color = GDI_COLOR_BLACK;

#if defined(__MDI_CAMERA_FD_SUPPORT__)
    cam_preview_data->fd_enable = (kal_bool)camera_setting_p->fd_enable;
#endif

    cam_preview_data->tv_output = KAL_FALSE;

    g_mdi_camera_cntx.lcd_id = camera_setting_p->lcm;
    g_mdi_camera_cntx.frame_buf_size = cam_preview_data->frame_buffer_size;
    g_mdi_camera_cntx.frame_buf1_ptr = (kal_uint8*) cam_preview_data->frame_buffer1_address;
    g_mdi_camera_cntx.frame_buf2_ptr = (kal_uint8*) cam_preview_data->frame_buffer2_address;
    g_mdi_camera_cntx.tv_output_offset_x = cam_preview_data->tv_output_offset_x;
    g_mdi_camera_cntx.tv_output_offset_y = cam_preview_data->tv_output_offset_y;

    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_FALSE);

    gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);
    gdi_lcd_lock_mutex();
    gdi_waiting_blt_finish();
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_unlock_mutex();
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_set_blt_layer_previous(); // Flush layer setting which is modified by app
    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start_internal
 * DESCRIPTION
 *  init MDI Camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static MDI_RESULT mdi_camera_preview_start_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct cam_preview_data = {0};
    // under construction 
    // media_cam_preview_req_struct cam_preview_data2;
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* fillin preview data from camera_preview_p and camera_setting_p global vars */
    mdi_camera_fillin_preview_data(&cam_preview_data);

    // under construction 
    //mdi_camera_fillin_preview_data_v2(&cam_preview_data2);

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    mdi_xenon_flash_status_callback = camera_setting_p->xenon_flash_status_callback;
    SetProtocolEventHandler(mdi_camera_xenon_flash_ind, MSG_ID_MEDIA_CAM_XENON_FLASH_STATUS_IND);
#endif

#if defined(__MDI_CAMERA_FD_SUPPORT__)
    g_mdi_camera_fd_callback = camera_setting_p->fd_callback;
    SetProtocolEventHandler(mdi_camera_fd_result_ind, MSG_ID_MEDIA_CAM_FD_RESULT_IND);
#endif

    mdi_camera_p->is_preview_stopped = FALSE;

    if (camera_preview_p->is_lcd_update)
        gdi_lcd_set_hw_update(KAL_TRUE);
    
#ifdef __MTK_TARGET__
    ret = media_cam_preview(stack_get_active_module_id(), &cam_preview_data);

    if (ret != MED_RES_OK)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
        if (ret == MED_RES_MEM_INSUFFICIENT)
            return MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH;
        else    
            return MDI_RES_CAMERA_ERR_HW_NOT_READY;
    }
    else
    {
        mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        return MDI_RES_CAMERA_SUCCEED;
    }
#else /* __MTK_TARGET__ */ 
    ret = MED_RES_OK;
    return ret;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_stop
 * DESCRIPTION
 *  Stop camera preview
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *****************************************************************************/
MDI_RESULT mdi_camera_preview_stop(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->is_preview_stopped == FALSE)
    {
        media_cam_stop(stack_get_active_module_id());
    }
    gdi_lcd_set_hw_update(KAL_FALSE);

#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__)
    // Because the preview buffer maybe is replaced by MED double buffer, need to set again to LCD for bltting next
    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_FALSE);    
    gdi_layer_set_blt_layer_previous();
    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_TRUE);
#endif

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    mdi_xenon_flash_status_callback = NULL;
#endif

    /* already powered off */
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    mdi_camera_p->is_preview_stopped = TRUE;

    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    gdi_lcd_set_hw_update(KAL_FALSE);
    mdi_camera_p->state = CAMERA_STATE_IDLE;
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}
#pragma arm section code, rodata

static MDI_RESULT mdi_camera_get_error_code(S32 med_result)
{
    if (med_result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (med_result == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (med_result == MED_RES_OPEN_FILE_FAIL)
    {
        return MDI_RES_CAMERA_ERR_SAVE_FAILED;
    }
    else if (med_result == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (med_result == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else if (med_result == MED_RES_NOT_ENOUGH_SPACE ||
             med_result == MED_RES_MEM_INSUFFICIENT)
    {
        return MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_CAPTURE_FAILED;
    }    
}

#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
static void mdi_camera_fillin_capture_data(media_cam_capture_req_struct* capture_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 physical_rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capture_data_p->image_width = camera_setting_p->image_width;
    capture_data_p->image_height = camera_setting_p->image_height;

    capture_data_p->image_quality = (U8) camera_setting_p->image_qty;
    capture_data_p->source_device = CAM_SRC_ISP;   /* ISP */
    capture_data_p->flash_mode = (kal_uint16) camera_setting_p->flash;  

    capture_data_p->image_data_format = camera_setting_p->preview_format;

    capture_data_p->display = KAL_FALSE;
    capture_data_p->tv_output = KAL_FALSE;
    capture_data_p->update_layer = camera_preview_p->blt_layer_flag;
    capture_data_p->hw_update_layer = camera_preview_p->preview_layer_flag;
    capture_data_p->ui_rotate = g_mdi_camera_cntx.capture_rotate;
    capture_data_p->quickview_lcd_rotate = g_mdi_camera_cntx.quickview_rotate;
    //gdi_layer_get_actual_rotate_value(camera_preview_p->preview_layer_handle, &physical_rotate);
    //capture_data_p->quickview_lcd_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);
#ifdef __CAMERA_CAPTURE_USING_APP_MEMORY__
    capture_data_p->capture_y_buffer_address = g_mdi_camera_cntx.capture_yuv_buffer.y_buffer_address;
    capture_data_p->capture_y_buffer_size = g_mdi_camera_cntx.capture_yuv_buffer.y_buffer_size;
    capture_data_p->capture_u_buffer_address = g_mdi_camera_cntx.capture_yuv_buffer.u_buffer_address;
    capture_data_p->capture_u_buffer_size = g_mdi_camera_cntx.capture_yuv_buffer.u_buffer_size;
    capture_data_p->capture_v_buffer_address = g_mdi_camera_cntx.capture_yuv_buffer.v_buffer_address;
    capture_data_p->capture_v_buffer_size = g_mdi_camera_cntx.capture_yuv_buffer.v_buffer_size;
#endif
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_quickview_extra_buffer
 * DESCRIPTION
 *  Set quickview extra for saving MED quickview buffer memory
 * PARAMETERS
 *  buf_addr          [IN]          MED quick view image buffer address
 *  buf_size          [IN]          MED quick view image buffer address size
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_quickview_extra_buffer(U32 buf_addr, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_set_extra_qvi_buffer(stack_get_active_module_id(), buf_addr, buf_size);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_yuv_buffer
 * DESCRIPTION
 *  Set quickview extra for saving MED quickview buffer memory
 * PARAMETERS
 *  capture_yuv_buffer          [IN]          MED capture yuv buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_capture_yuv_buffer(mdi_camera_capture_yuv_buffer_struct* capture_yuv_buffer)
{
#ifdef __CAMERA_CAPTURE_USING_APP_MEMORY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_p->capture_yuv_buffer.y_buffer_address = capture_yuv_buffer->y_buffer_address;
    mdi_camera_p->capture_yuv_buffer.y_buffer_size = capture_yuv_buffer->y_buffer_size;
    mdi_camera_p->capture_yuv_buffer.u_buffer_address = capture_yuv_buffer->u_buffer_address;
    mdi_camera_p->capture_yuv_buffer.u_buffer_size = capture_yuv_buffer->u_buffer_size;
    mdi_camera_p->capture_yuv_buffer.v_buffer_address = capture_yuv_buffer->v_buffer_address;
    mdi_camera_p->capture_yuv_buffer.v_buffer_size = capture_yuv_buffer->v_buffer_size;    
#endif
}

#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
static S32 mdi_camera_med_capture(media_cam_capture_req_struct* capture_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MDI_RES_CAMERA_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_stop_preview(stack_get_active_module_id());
#endif    
    // Internal memory concurrency issue, stop hw updating before capturing.
    if (capture_data_p->capture_mode != CAM_STILL_CAPTURE_ZSD &&
        capture_data_p->capture_mode != CAM_STILL_CAPTURE_MAV &&
        capture_data_p->capture_mode != CAM_STILL_CAPTURE_3D_IMAGE)
        gdi_lcd_set_hw_update(KAL_FALSE);
#ifdef __MTK_TARGET__
    /* capture jpeg */
    result = media_cam_capture(stack_get_active_module_id(), (void*)capture_data_p);
#endif
    if (capture_data_p->capture_mode == CAM_STILL_CAPTURE_ZSD)
        gdi_lcd_set_hw_update(KAL_FALSE);
    else if ((capture_data_p->capture_mode == CAM_STILL_CAPTURE_MAV || 
              capture_data_p->capture_mode == CAM_STILL_CAPTURE_3D_IMAGE) &&
             result != MED_RES_OK)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
    }
#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT) && defined(__MTK_TARGET__)
    // Because the preview buffer maybe is replaced by MED double buffer, need to set again to LCD for bltting next
    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_FALSE);    
    gdi_layer_set_blt_layer_previous();
    gdi_layer_set_hw_update_layer(camera_preview_p->preview_layer_handle, KAL_TRUE);
#endif

#ifdef MDP_SUPPORT_HW_OVERLAP
    /* free overlay relate cntx. */
    if (camera_overlay_p != NULL)
    {
        OslMfree((S8*)camera_overlay_p);
        camera_overlay_p = NULL;
    }
#endif    

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;
#ifdef __CAMERA_CAPTURE_USING_APP_MEMORY__
    memset((void*)&mdi_camera_p->capture_yuv_buffer, 0, sizeof(mdi_camera_capture_yuv_buffer_struct));
#endif
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture
 * DESCRIPTION
 *  Capture a jpeg image
 * PARAMETERS
 *  filename            [IN]        Filename buffer pointer
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_camera_capture_with_quickview(NULL, 0, 0, 0, filename);
}



/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_with_quickview
 * DESCRIPTION
 *  Capture jpeg to a memory
 * PARAMETERS
 *  quickview_buf_addr          [IN]          Quick view image buffer address
 *  quickview_buf_size          [IN]          Quick view image buffer address size
 *  quickview_width             [IN]          Width of quick view image buffer
 *  quickview_height            [IN]          Height of quick view image buffer
 *  filename                    [IN]          File name
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_with_quickview(
    U32 quickview_buf_addr, 
    U32 quickview_buf_size, 
    U16 quickview_width, 
    U16 quickview_height,
    S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.snapshot_number = 1; 
    capture_data.filename_p = (void*)filename;
    capture_data.continue_capture = FALSE;
    capture_data.capture_mode = g_mdi_camera_cntx.capture_mode;
    
    mdi_camera_fill_overlay_data(&capture_data);

    if (quickview_buf_addr)
        capture_data.quickview_output = KAL_TRUE;
    else
        capture_data.quickview_output = KAL_FALSE;
    
    capture_data.quickview_output_width = quickview_width;
    capture_data.quickview_output_height = quickview_height;
    capture_data.quickview_output_buffer_address = quickview_buf_addr;
    capture_data.quickview_output_buffer_size = quickview_buf_size;
    
    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);

}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_continuous_shot
 * DESCRIPTION
 *  Continue capture
 * PARAMETERS
 *  file_name       [IN]    The pointer of filename buffer array
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_continuous_shot(S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_camera_capture_continuous_shot_with_quickview(NULL, 0, 0, 0, filename);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_continuous_shot_with_quickview
 * DESCRIPTION
 *  Capture jpeg to a memory
 * PARAMETERS
 *  buf_pp              [OUT]       Pointer to a buffer pointer for jpeg file
 *  captured_size       [OUT]       Captured size
 *  dc_buf_addr         [IN]        Captured image layer address
 *  buf_size            [IN]        Captured image layer buffer length
 *  width               [IN]        Width of captured image image
 *  height              [OUT]       Height of captured image image
 *  filename            [IN]        File name
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_continuous_shot_with_quickview(
    U32 quickview_buf_addr, 
    U32 quickview_buf_size, 
    U16 quickview_width, 
    U16 quickview_height,
    S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.snapshot_number = 1;
    capture_data.filename_p = (void*)filename;
    capture_data.continue_capture = TRUE;
    capture_data.capture_mode = CAM_STILL_CAPTURE_CONT_SHOT;
    
    mdi_camera_fill_overlay_data(&capture_data);

    if (quickview_buf_addr)
        capture_data.quickview_output = KAL_TRUE;
    else
        capture_data.quickview_output = KAL_FALSE;

    capture_data.quickview_output_width = quickview_width;
    capture_data.quickview_output_height = quickview_height;
    capture_data.quickview_output_buffer_address = quickview_buf_addr;
    capture_data.quickview_output_buffer_size = quickview_buf_size;

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_burst_shot
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS
 *  capture_count       [IN]        Capture number
 *  jpgs_ptr            [OUT]       Captured jpeg info        
 *  callback            [IN]        Capture result callback
 *  buffer              [IN]        Burstshot buffer address
 *  buffer_size         [IN]        Burstshot buffer length
 *  user_data           [IN]        User data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_burst_shot(U32 capture_count, 
                                                   mdi_camera_jpegs_struct *jpgs_ptr, 
                                                   capture_result_callback callback, 
                                                   U8* buffer, 
                                                   S32 buffer_size,
                                                   void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_camera_capture_to_memory_burst_shot_with_quickview(
                                                    capture_count,
                                                    jpgs_ptr,
                                                    callback,
                                                    buffer,
                                                    buffer_size,
                                                    NULL,
                                                    0,
                                                    0,
                                                    0,
                                                    user_data); 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_burst_shot_with_quickview
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS
 *  capture_count       [IN]        Capture number
 *  jpgs_ptr            [OUT]       Captured jpeg info        
 *  callback            [IN]        Capture result callback
 *  buffer              [IN]        Burstshot buffer address
 *  buffer_size         [IN]        Burstshot buffer length
 *  quickview_buf_addr  [IN]        Quick view image buffer address
 *  quickview_buf_size  [IN]        Quick view image buffer address size
 *  quickview_width     [IN]        Width of quick view image buffer
 *  quickview_height    [IN]        Height of quick view image buffer
 *  user_data           [IN]        User data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_burst_shot_with_quickview(
                                                    U32 capture_count, 
                                                    mdi_camera_jpegs_struct *jpgs_ptr, 
                                                    capture_result_callback callback, 
                                                    U8* buffer, 
                                                    S32 buffer_size,
                                                    U32 quickview_buf_addr, 
                                                    U32 quickview_buf_size, 
                                                    U16 quickview_width, 
                                                    U16 quickview_height,
                                                    void* user_data)
{
#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result = MDI_RES_CAMERA_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    ASSERT(callback != NULL);

    g_mdi_camera_cntx.burst_cap_count = capture_count;

    g_mdi_camera_cntx.user_data = user_data;
    mdi_camera_non_block_burst_shot_result_callback = callback;
    SetProtocolEventHandler(mdi_camera_non_block_burst_capture_result_hdlr, MSG_ID_MEDIA_CAM_CAPTURE_EVENT_IND);

    mdi_camera_fillin_capture_data(&capture_data);
    capture_data.media_mode = MED_MODE_ARRAY;
    capture_data.app_capture_buffer_size = buffer_size;
    capture_data.app_capture_buffer_p = buffer;

    capture_data.snapshot_number = capture_count;
    capture_data.continue_capture = TRUE;
    capture_data.jpegs_p = (media_jpegs_struct*) jpgs_ptr;
    capture_data.capture_mode = CAM_STILL_CAPTURE_BURST_SHOT;

    if (quickview_buf_addr)
        capture_data.quickview_output = KAL_TRUE;
    else
        capture_data.quickview_output = KAL_FALSE;
    
    capture_data.quickview_output_width = quickview_width;
    capture_data.quickview_output_height = quickview_height;
    capture_data.quickview_output_buffer_address = quickview_buf_addr;
    capture_data.quickview_output_buffer_size = quickview_buf_size;
    
    mdi_camera_fill_overlay_data(&capture_data);

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);
#else
    //gdi_lcd_set_hw_update(KAL_FALSE);
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* (__MDI_CAMERA_BURSTSHOT_SUPPORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_block_burst_capture
 * DESCRIPTION
 *  Stop non blocking burst capture
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED  Success
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_non_block_burst_capture(void)
{
    
#ifdef __MDI_CAMERA_BURSTSHOT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MTK_TARGET__
    media_cam_stop(stack_get_active_module_id());
    #endif

#endif /* __MDI_CAMERA_BURSTSHOT_SUPPORT__ */ 

    return MDI_RES_CAMERA_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_non_block_burst_capture_result_hdlr
 * DESCRIPTION
 *  burst capture result handler
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void mdi_camera_non_block_burst_capture_result_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_capture_event_ind_struct*) msg_ptr;

    /* note:capture count start from 1 */

    if ((ind_p->result != MED_RES_OK) ||
        ((ind_p->result == MED_RES_OK) && ((ind_p->count) == g_mdi_camera_cntx.burst_cap_count)))
    {
        /* if failed, or if it is last capture - will enter here */

        g_mdi_camera_cntx.burst_cap_count = 0;

    }

    /* successful save file */
    if (ind_p->result == MED_RES_OK)
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_SUCCEED, ind_p->count, g_mdi_camera_cntx.user_data);
    }
    else if (ind_p->result == MED_RES_BUFFER_INSUFFICIENT)
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH, ind_p->count, g_mdi_camera_cntx.user_data);
    }
    else
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_ERR_CAPTURE_FAILED, ind_p->count, g_mdi_camera_cntx.user_data);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_bracketing
 * DESCRIPTION
 *  EV bracketing capture and this is a blocking function
 * PARAMETERS
 *  jpgs_ptr    [IN]    The pointer for storing captured jpeg info structure 
 *  buffer      [IN]    The buffer address
 *  buffer_size [IN]    The buffer size
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_bracketing(mdi_camera_jpegs_struct *jpgs_ptr,U8* buffer, S32 buffer_size)
{
#ifdef __MDI_CAMERA_EV_BRACKETING_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_ARRAY;
    capture_data.app_capture_buffer_p = buffer;
    capture_data.app_capture_buffer_size = buffer_size;
    capture_data.snapshot_number = 3;

    capture_data.capture_mode = CAM_STILL_CAPTURE_EV_BRACKETING;
    capture_data.continue_capture = TRUE;
    capture_data.jpegs_p = (media_jpegs_struct*) jpgs_ptr;
    
    mdi_camera_fill_overlay_data(&capture_data);

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);

#else
    gdi_lcd_set_hw_update(KAL_FALSE);
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_EV_BRACKETING_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_best_shot
 * DESCRIPTION
 *  EV bracketing capture and this is a blocking function
 * PARAMETERS
 *  buf_pp          [OUT]       The pointer to pointer for get capture buffer address
 *  captured_size   [OUT]       The pointer of capture size
 *  buffer          [IN]        The buffer address
 *  buffer_size     [IN]        The buffer size
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_best_shot(U8** buf_pp, U32 *captured_size, U8* buffer, S32 buffer_size)
{
#ifdef __MDI_CAMERA_EV_BRACKETING_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }
    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_ARRAY;

    capture_data.capture_buffer_p = (void **)buf_pp;
    capture_data.file_size_p = (kal_uint32*) captured_size;
    capture_data.app_capture_buffer_p = buffer;
    capture_data.app_capture_buffer_size = buffer_size;
    capture_data.snapshot_number = 3;
    capture_data.continue_capture = TRUE;
    capture_data.capture_mode = CAM_STILL_CAPTURE_BEST_SHOT;

    mdi_camera_fill_overlay_data(&capture_data);
    capture_data.tv_output = FALSE;

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_EV_BRACKETING_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_panorama_with_quickview
 * DESCRIPTION
 *  Capture one of panorama images and direct couple the captured raw image append to captured data. 
 * PARAMETERS
 *  buffer                      [IN]        Capture buffer address (MT6235: in yuv420 planar format)(MT6238 series: in jpeg format)
 *  buffer_size                 [IN]        Capture buffer size
 *  captured_buffer_pp          [OUT]       Captured image buffer address
 *  captured_buffer_size_p      [OUT]       Captured image size 
 *  shot_num                    [IN]        The capture image index
 *  direction                   [IN]        Panorama stitch direction
 *  quickview_buf_addr          [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          [IN]        Quick view image buffer address size
 *  quickview_width             [IN]        Width of quick view image buffer
 *  quickview_height            [IN]        Height of quick view image buffer
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_panorama_with_quickview(
                                                 U8  *buffer, 
                                                 U32 buffer_size,
                                                 U8  **captured_buffer_pp,
                                                 U32 *captured_buffer_size_p,
                                                 U8  shot_num,
                                                 U8  direction,
                                                 U32 quickview_buf_addr, 
                                                 U32 quickview_buf_size, 
                                                 U16 quickview_width, 
                                                 U16 quickview_height)                                                 
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_ARRAY;
    capture_data.app_capture_buffer_p = buffer;
    capture_data.app_capture_buffer_size = buffer_size;
    capture_data.file_size_p = captured_buffer_size_p;
    capture_data.capture_buffer_p = (void**)captured_buffer_pp;
    capture_data.snapshot_number = 1;
    capture_data.current_shot_number = shot_num;
    capture_data.direction = direction;
    capture_data.continue_capture = FALSE;
    capture_data.capture_mode = CAM_STILL_CAPTURE_PANO_VIEW;

    if (quickview_buf_addr != NULL && 
        quickview_width > 0 && 
        quickview_height > 0)
    {
        capture_data.quickview_output = KAL_TRUE;
        capture_data.quickview_output_width = quickview_width;
        capture_data.quickview_output_height = quickview_height;
        capture_data.quickview_output_buffer_address = quickview_buf_addr; 
        capture_data.quickview_output_buffer_size = quickview_buf_size; 
    }
    else
    {
        capture_data.quickview_output = KAL_FALSE;
    }

    mdi_camera_fill_overlay_data(&capture_data);

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);
#else
    gdi_lcd_set_hw_update(KAL_FALSE);
    return MDI_RES_CAMERA_ERR_CAPTURE_FAILED;

#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_panorama
 * DESCRIPTION
 *  Capture one of panorama images
 * PARAMETERS
 *  buffer                      [IN]        Capture buffer address       
 *  buffer_size                 [OUT]       Capture buffer size
 *  captured_buffer_size_p      [IN]        Capture image size 
 *  shot_num                    [IN]        The capture image index
 *  direction                   [IN]        Panorama stitch direction
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_panorama(U8  *buffer, 
                                                 U32 buffer_size,
                                                 U8  **captured_buffer_pp,                                                 
                                                 U32 *captured_buffer_size_p,
                                                 U8  shot_num,
                                                 U8  direction)
{
    return mdi_camera_capture_to_memory_panorama_with_quickview(buffer,buffer_size, captured_buffer_pp, captured_buffer_size_p, shot_num, direction, NULL,0, 0,0);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_stitching_panorama_with_quickview
 * DESCRIPTION
 *  Start stitching panorama process
 * PARAMETERS
 *  data                        [IN]        Panorama capture image information
 *  quickview_callback          [IN]        Stitch quickview callback
 *  stitch_callback             [IN]        Stitch result callbcak
 *  quickview_buf_addr          [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          [IN]        Quick view image buffer address size
 *  quickview_width             [IN]        Width of quick view image buffer
 *  quickview_height            [IN]        Height of quick view image buffer
 *  is_quickview_resized_by_buf [IN]        Decide the quickview resized by buffer size or dimension
 *  user_data                   [IN]        user data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_start_stitching_panorama_with_quickview(
                                                mdi_camera_panorama_struct* data,
                                                mdi_camera_panorama_stitch_quickview_callback quickview_callback,
                                                mdi_camera_panorama_stitch_result_callback stitch_callback, 
                                                U32 quickview_buf_addr, 
                                                U32 quickview_buf_size, 
                                                U16 quickview_width, 
                                                U16 quickview_height,
                                                MMI_BOOL is_quickview_resized_by_buf,
                                                void* user_data)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_start_stitch_req_struct panorama_data = {0};
    MDI_RESULT result;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mdi_camera_p->state == CAMERA_STATE_IDLE);
    
    mdi_camera_p->user_data = user_data;
    SetProtocolEventHandler(mdi_camera_panorama_result_ind, MSG_ID_MEDIA_CAM_STITCH_RESULT_IND);
    SetProtocolEventHandler(mdi_camera_panorama_quickview_result_ind, MSG_ID_MEDIA_CAM_STITCH_QUICK_VIEW_IND);

    panorama_data.direction = data->direction;
    panorama_data.num_of_jpegs = data->image_num;

    while(i < data->image_num)
    {
        panorama_data.jpeg_buffer_p[i] = data->src_jpeg_buffer_address[i];
        panorama_data.jpeg_buffer_size[i] = data->src_jpeg_buffer_size[i];
        i++;
    }
    
    panorama_data.source_height = camera_setting_p->image_height;
    panorama_data.source_width = camera_setting_p->image_width;

    panorama_data.target_buffer_size = data->dest_jpeg_buffer_size;
    panorama_data.target_buffer_address = data->dest_jpeg_buffer_address;

    panorama_data.seq_no = mdi_camera_p->stitch_seq_num;

    if (quickview_buf_addr != NULL)
    {
        panorama_data.quickview_output = KAL_TRUE;
        panorama_data.quickview_output_width = quickview_width;
        panorama_data.quickview_output_height = quickview_height;
        panorama_data.quickview_output_buffer_address = quickview_buf_addr; 
        panorama_data.quickview_output_buffer_size = quickview_buf_size;
        panorama_data.quickview_output_resize_by_buffer_size_enable = is_quickview_resized_by_buf;
    }
    else
    {
        panorama_data.quickview_output = KAL_FALSE;
    }
    
    g_mdi_camera_panorama_stitch_result_callback = stitch_callback;
    g_mdi_camera_panorama_stitch_quickview_callback = quickview_callback;

    result = media_cam_stitch_panorama(stack_get_active_module_id(), &panorama_data);

    mdi_camera_p->state = CAMERA_STATE_STITCH_PANORAMA;

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    ASSERT(0);
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_stitching_panorama
 * DESCRIPTION
 *  Start stitching panorama process
 * PARAMETERS
 *  data            [IN]        Panorama capture image information
 *  callback        [IN]        Stitch result callbcak
 *  user_data       [IN]        user data 
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_start_stitching_panorama(mdi_camera_panorama_struct* data, mdi_camera_panorama_stitch_result_callback callback, void* user_data)
{
    return mdi_camera_start_stitching_panorama_with_quickview(data, NULL, callback, NULL, 0, 0, 0, MMI_FALSE, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_hdr_shot_with_quickview
 * DESCRIPTION
 *  HDR capture and this is a non-blocking function
 * PARAMETERS
 *  quickview_buf_addr          [IN]        Quick view image buffer address_p (if NULL, we will not do this)
 *  quickview_buf_size          [IN]        Quick view image buffer address size
 *  quickview_width             [IN]        Width of quick view image buffer
 *  quickview_height            [IN]        Height of quick view image buffer
 *  callback                    [IN]        capture result callbcak
 *  user_data                   [IN]        user data 
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_hdr_shot_with_quickview(
                                    U32 quickview_buf_addr, 
                                    U32 quickview_buf_size, 
                                    U16 quickview_width,
                                    U16 quickview_height,
                                    mdi_camera_hdr_callback callback, 
                                    void* user_data)
{
#if defined(__MDI_CAMERA_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }
    mdi_camera_p->user_data = user_data;
    SetProtocolEventHandler(mdi_camera_hdr_shot_result_hdlr, MSG_ID_MEDIA_CAM_HDR_EVENT_IND);

    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.snapshot_number = 1; 
    capture_data.continue_capture = FALSE;
    capture_data.capture_mode = CAM_STILL_CAPTURE_HDR;
    
    mdi_camera_fill_overlay_data(&capture_data);

    if (quickview_buf_addr)
        capture_data.quickview_output = KAL_TRUE;
    else
        capture_data.quickview_output = KAL_FALSE;
    
    capture_data.quickview_output_width = quickview_width;
    capture_data.quickview_output_height = quickview_height;
    capture_data.quickview_output_buffer_address = quickview_buf_addr;
    capture_data.quickview_output_buffer_size = quickview_buf_size;

    g_mdi_camera_hdr_callback = callback;
        
    result = mdi_camera_med_capture(&capture_data);

    mdi_camera_p->state = CAMERA_STATE_HDR_PROCESSING;

    return mdi_camera_get_error_code(result);
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_blocking_hdr_shot
 * DESCRIPTION
 *  Stop HDR process
 * PARAMETERS
 *  captured_filename             [IN]        filepath for saving the captured image (no HDR enhanced file)
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_non_blocking_hdr_shot(S8* captured_filename)
{
#if defined(__MDI_CAMERA_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_stop_hdr(stack_get_active_module_id(), (kal_wchar*)captured_filename);

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    
    if (result == MED_RES_OK)
        return MDI_RES_CAMERA_SUCCEED;
    else
        return MDI_RES_CAMERA_ERR_FAILED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_hdr_shot_result_hdlr
 * DESCRIPTION
 *  Stop HDR process
 * PARAMETERS
 *  msg_ptr             [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void  mdi_camera_hdr_shot_result_hdlr(void *msg_ptr)
{
#if defined(__MDI_CAMERA_HDR_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_hdr_result_ind_struct *msg_p = (media_cam_hdr_result_ind_struct*) msg_ptr;
    mdi_camera_hdr_result_struct result_ind = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_HDR_PROCESSING)
    {
        if (msg_p->buffer_type == CAM_HDR_PROCESSED_MAINIMAGE_JPEG || msg_p->result != MED_RES_OK)
            mdi_camera_p->state = CAMERA_STATE_IDLE;

        result_ind.buffer_type = msg_p->buffer_type;
        result_ind.result = msg_p->result;
        result_ind.buffer_address = msg_p->buffer_address;
        result_ind.buffer_size = msg_p->buffer_size;

        if (g_mdi_camera_hdr_callback)
            g_mdi_camera_hdr_callback(&result_ind, mdi_camera_p->user_data);

        if (mdi_camera_p->state == CAMERA_STATE_IDLE)
            g_mdi_camera_hdr_callback = NULL;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_save_captured_hdr_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  captured_filename       [IN]    capture image file name
 *  hdr_filename            [IN]    hdr file name 
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Failed
 *****************************************************************************/
S32 mdi_camera_save_hdr_images(S8* captured_filename, S8* hdr_filename)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MDI_RES_CAMERA_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MDI_CAMERA_HDR_SUPPORT__)
    result = media_cam_save_hdr_images(
                stack_get_active_module_id(),
                (kal_wchar*)captured_filename, 
                (kal_wchar*)hdr_filename);

    return mdi_camera_get_error_code(result);
#else
    return result;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_mav
 * DESCRIPTION
 *  Non-blocking burstshot capture
 * PARAMETERS      
 *  filename            [IN]        file name
 *  capture_callback    [IN]        Capture result callback
 *  result_callback     [IN]        Finish result callback
 *  user_data           [IN]        User data
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_mav_shot(
                                CHAR* filename,
                                mdi_camera_mav_capture_callback capture_callback,
                                mdi_camera_mav_result_callback result_callback,
                                void* user_data)
{
#if defined(__MDI_CAMERA_MAV_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result = MDI_RES_CAMERA_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    SetProtocolEventHandler(mdi_camera_non_block_mav_capture_hdlr, MSG_ID_MEDIA_CAM_MAV_CAPTURE_IMAGE_IND);
    SetProtocolEventHandler(mdi_camera_non_block_mav_result_hdlr, MSG_ID_MEDIA_CAM_MAV_RESULT_IND);
    
    g_mdi_camera_mav_capture_callback = capture_callback;
    g_mdi_camera_mav_result_callback = result_callback;
    g_mdi_camera_cntx.user_data = user_data;
    
    mdi_camera_fillin_capture_data(&capture_data);
    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.mav_seq_num = mdi_camera_p->stitch_seq_num;

    if (g_mdi_camera_cntx.capture_mode == MDI_CAMERA_CAP_MODE_MAV)
        capture_data.snapshot_number = MAV_IMAGE_NUM;
    else if (g_mdi_camera_cntx.capture_mode == MDI_CAMERA_CAP_MODE_3D_IMAGE)
        capture_data.snapshot_number = 2;
    else
        return mdi_camera_get_error_code(result);
    
    capture_data.continue_capture = TRUE;
    capture_data.capture_mode = g_mdi_camera_cntx.capture_mode;
    capture_data.filename_p = (void*)filename;

    mdi_camera_fill_overlay_data(&capture_data);

    result = mdi_camera_med_capture(&capture_data);

    mdi_camera_p->state = CAMERA_STATE_MAV_PROCESSING;
        
    return mdi_camera_get_error_code(result);    
#else
    gdi_lcd_set_hw_update(KAL_FALSE);
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_blocking_mav_shot
 * DESCRIPTION
 *  Stop HDR process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_non_blocking_mav_shot(void)
{
#if defined(__MDI_CAMERA_MAV_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MTK_TARGET__
    media_cam_stop(stack_get_active_module_id());
    #endif
    mdi_camera_p->stitch_seq_num++;

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    gdi_lcd_set_hw_update(KAL_FALSE);
#endif
    return MDI_RES_CAMERA_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_non_block_mav_capture_hdlr
 * DESCRIPTION
 *  mav capture handler
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void mdi_camera_non_block_mav_capture_hdlr(void *msg_ptr)
{
#if defined(__MDI_CAMERA_MAV_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_mav_capture_image_ind_struct *ind_p;
    mdi_camera_mav_capture_struct cap_info = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_mav_capture_image_ind_struct*) msg_ptr;

    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI, 
        MDI_TRC_CAMERA_MAV_CAP_RESULT, 
        ind_p->captured_number, 
        ind_p->total_number);

    cap_info.capture_count = ind_p->captured_number;
    cap_info.total_count = ind_p->total_number;
    
    if ((mdi_camera_p->state != CAMERA_STATE_MAV_PROCESSING) ||
        (mdi_camera_p->stitch_seq_num != ind_p->seq_num))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_CAMERA_MAV_CAP_SKIP);
        return;
    }
    
    if (cap_info.capture_count == cap_info.total_count)
        gdi_lcd_set_hw_update(KAL_FALSE);

    if (g_mdi_camera_mav_capture_callback)
    {
        g_mdi_camera_mav_capture_callback(&cap_info, g_mdi_camera_cntx.user_data);
    }

    #ifdef __MTK_TARGET__    
    if (cap_info.capture_count == cap_info.total_count)
    {
        media_cam_stitch_mav(stack_get_active_module_id());
    }
    #endif    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_non_block_mav_result_hdlr
 * DESCRIPTION
 *  mav result handler
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void mdi_camera_non_block_mav_result_hdlr(void *msg_ptr)
{
#if defined(__MDI_CAMERA_MAV_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_mav_result_ind_struct *ind_p;
    mdi_camera_mav_result_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_mav_result_ind_struct*) msg_ptr;
    info.result = ind_p->result;
    info.buffer_address = ind_p->buffer_address;
    info.buffer_size = ind_p->buffer_size;

    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI, 
        MDI_TRC_CAMERA_MAV_STITCH_RESULT, 
        mdi_camera_p->state, 
        mdi_camera_p->stitch_seq_num,
        ind_p->seq_num);
    
    if (mdi_camera_p->state == CAMERA_STATE_MAV_PROCESSING && 
        mdi_camera_p->stitch_seq_num == ind_p->seq_num)
    {
        mdi_camera_p->state = CAMERA_STATE_IDLE;
        
        if (g_mdi_camera_mav_result_callback)
            g_mdi_camera_mav_result_callback(&info, g_mdi_camera_cntx.user_data);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_save_captured_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Failed
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
S32 mdi_camera_save_captured_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_save_image(stack_get_active_module_id(),NULL);
    return mdi_camera_get_error_code(result);
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_is_ready_to_capture
 * DESCRIPTION
 *  Check hw module is ready to capture 
 *  (some module requires some time to power on and init)
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE        Ready
 *  FALSE       Not ready
 *****************************************************************************/
BOOL mdi_camera_is_ready_to_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_encode_captured_image
 * DESCRIPTION
 *  According to the passed file name, MED saves the capture result to the file
 * PARAMETERS
 *  
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  : Success
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
S32 mdi_camera_encode_capture_image(U8 **buf_pp, U32 *buf_size_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    ret = media_cam_encode_capture_image(stack_get_active_module_id(), buf_pp, buf_size_p);
#endif
    return ret;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_banding
 * DESCRIPTION
 *  Update banding value
 * PARAMETERS
 *  cam_para        [IN]        Banding value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_banding(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->banding = cam_para;   
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_BANDING_FREQ, cam_para);
  
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ev
 * DESCRIPTION
 *  Update ev setting value
 * PARAMETERS
 *  cam_para        [IN]        EV setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_ev(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_EV_COUNT);

    camera_setting_p->ev = cam_para;
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_EV_VALUE, cam_para);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_zoom
 * DESCRIPTION
 *  Update zoom step value
 * PARAMETERS
 *  cam_para        [IN]        Zoom step value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_zoom(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->zoom = cam_para;
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_DIGITAL_ZOOM, cam_para);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_effect
 * DESCRIPTION
 *  Update effect setting value
 * PARAMETERS
 *  cam_para        [IN]        Effect setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_effect(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_EFFECT_COUNT);

    camera_setting_p->effect = cam_para;
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_IMAGE_EFFECT, cam_para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_wb
 * DESCRIPTION
 *  Update wb setting value
 * PARAMETERS
 *  cam_para        [IN]        WB setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_wb(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_WB_COUNT);

    camera_setting_p->wb = cam_para;
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_WB, cam_para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_saturation
 * DESCRIPTION
 *  Update saturation setting value
 * PARAMETERS
 *  cam_para        [IN]        Saturation setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_saturation(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->saturation = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SATURATION, cam_para);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_contrast
 * DESCRIPTION
 *  Update contrast setting value
 * PARAMETERS
 *  cam_para        [IN]        Contrast setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_contrast(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->contrast = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_CONTRAST, cam_para);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_sharpness
 * DESCRIPTION
 *  Update sharpness setting value
 * PARAMETERS
 *  cam_para        [IN]        Sharpness setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_sharpness(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->sharpness = cam_para;

    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SHARPNESS, cam_para);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_hue
 * DESCRIPTION
 *  Update hue setting value
 * PARAMETERS
 *  cam_para        [IN]        Hue setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_hue(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->hue = cam_para;
    // doesn't support now
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_night
 * DESCRIPTION
 *  Update night mode setting value
 * PARAMETERS
 *  cam_para        [IN]        Night mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_night(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cam_para == KAL_TRUE)
        camera_setting_p->scene_mode = CAM_NIGHTSCENE;
    else
        camera_setting_p->scene_mode = CAM_AUTO_DSC;

    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SCENE_MODE, cam_para);
    }
 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_qty
 * DESCRIPTION
 *  Update image quality setting value
 * PARAMETERS
 *  cam_para        [IN]        Image qty setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_image_qty(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_JPG_QTY_COUNT);
    camera_setting_p->image_qty = cam_para;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_size
 * DESCRIPTION
 *  Update image size setting value
 * PARAMETERS
 *  image_width         [IN]        Captured image width
 *  image_height        [IN]        Captured image height
 * RETURNS
 *  void
 *****************************************************************************/
//#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
void mdi_camera_update_para_image_size(U16 image_width, U16 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_sensor_capture_resolution_info cap_res_info;
    media_cam_cap_resolution_struct cap_size;
    kal_uint32 index = 0;
#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);

        is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
        if (!is_loaded){
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
        mdi_camera_p->state = CAMERA_STATE_DCM_LOADED;
    }
    #endif 
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPSIZE_WITH_DIMENSION, (void *)&cap_res_info);
    
    camera_setting_p->image_resolution = MDI_CAMERA_CAP_SIZE_OTHER;
    
    camera_setting_p->image_width = image_width;
    camera_setting_p->image_height = image_height;

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
#else
    for (index = 0; index < cap_res_info.item_count; index++)
    {
        if ((cap_res_info.image_size[index].image_width == camera_setting_p->image_width && 
             cap_res_info.image_size[index].image_height == camera_setting_p->image_height) ||
            (cap_res_info.image_size[index].image_height == camera_setting_p->image_width &&
             cap_res_info.image_size[index].image_width == camera_setting_p->image_height))
        {
            camera_setting_p->image_resolution = cap_res_info.support_item[index];
            break;
        }
    }
#endif
	if (camera_setting_p->image_width == LCD_WIDTH && camera_setting_p->image_height == LCD_HEIGHT)
			camera_setting_p->image_resolution = MDI_CAMERA_CAP_SIZE_WALLPAPER;
	
    cap_size.image_resolution = camera_setting_p->image_resolution;
    cap_size.image_width = camera_setting_p->image_width = image_width;
    cap_size.image_height = camera_setting_p->image_height = image_height;
    #ifdef __MTK_TARGET__
    media_cam_set_cap_resolution(stack_get_active_module_id(), &cap_size);
    #endif
    
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_DCM_LOADED)
    {
        if (!is_loaded){
            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        }
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
        mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    }
    #endif 


}
//#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_flash
 * DESCRIPTION
 *  Update flash setting value
 * PARAMETERS
 *  cam_para        [IN]        Flash setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_flash(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->flash = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_FLASH_MODE, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_iso
 * DESCRIPTION
 *  Update iso setting value
 * PARAMETERS
 *  cam_para        [IN]        ISO setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_iso(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->iso = cam_para;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ae_meter
 * DESCRIPTION
 *  Update ae meter setting value
 * PARAMETERS
 *  cam_para        [IN]        AE meter setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_ae_meter(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->ae_meter = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AE_METERING_MODE, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_scene_mode
 * DESCRIPTION
 *  Update scene(DSC) mode value
 * PARAMETERS
 *  cam_para        [IN]        Scene mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_scene_mode(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->scene_mode = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SCENE_MODE, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_key
 * DESCRIPTION
 *  Update af key value
 * PARAMETERS
 *  cam_para        [IN]        AF key
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_key(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AF_KEY, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_mode
 * DESCRIPTION
 *  Update af mode value
 * PARAMETERS
 *  cam_para        [IN]        AF mode
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_mode(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_update_para_af_range(cam_para); 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_metering
 * DESCRIPTION
 *  Update af metering value
 * PARAMETERS
 *  cam_para        [IN]        AF metering
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_metering(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_update_para_af_operation_mode(cam_para);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_range
 * DESCRIPTION
 *  Update af range value
 * PARAMETERS
 *  cam_para        [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_range(U16 cam_para)
{
    camera_setting_p->af_range = cam_para;

    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AF_RANGE_CONTROL, cam_para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_operation_mode
 * DESCRIPTION
 *  Update af operation mode value
 * PARAMETERS
 *  cam_para        [IN]        AF range value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_operation_mode(U16 cam_para)
{
    camera_setting_p->af_operation_mode = cam_para;

    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AF_OPERATION_MODE, cam_para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_ev
 * DESCRIPTION
 *  Return the current ev value
 * PARAMETERS
 *  void
 * RETURNS
 * Camera EV value
 *****************************************************************************/
U16 mdi_camera_get_para_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->ev;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_zoom
 * DESCRIPTION
 *  Return the current zoom step value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam zoom value 
 *****************************************************************************/
U16 mdi_camera_get_para_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->zoom;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_zoom_factor
 * DESCRIPTION
 *  Return the current zoom factor value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam zoom value 
 *****************************************************************************/
U32 mdi_camera_get_para_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 factor = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_get_zoom_step_factor(stack_get_active_module_id(), &factor, NULL);
#endif

    return factor;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_banding
 * DESCRIPTION
 *  Return the current banding value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam banding value
 *****************************************************************************/
U16 mdi_camera_get_para_banding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->banding;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_effect
 * DESCRIPTION
 *  Return the current effect value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam effect value
 *****************************************************************************/
U16 mdi_camera_get_para_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->effect;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_wb
 * DESCRIPTION
 *  Return the current wb value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam WB value
 *****************************************************************************/
U16 mdi_camera_get_para_wb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->wb;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_sharpness
 * DESCRIPTION
 *  Return the current sharpness value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam brightness value
 *****************************************************************************/
U16 mdi_camera_get_para_sharpness(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->sharpness;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_saturation
 * DESCRIPTION
 *  Return the current saturation value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam saturation value
 *****************************************************************************/
U16 mdi_camera_get_para_saturation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->saturation;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_contrast
 * DESCRIPTION
 *  Return the current contrast value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam contrast value
 *****************************************************************************/
U16 mdi_camera_get_para_contrast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->contrast;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_hue
 * DESCRIPTION
 *  Return the current hue value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam hue value
 *****************************************************************************/
U16 mdi_camera_get_para_hue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->hue;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_night
 * DESCRIPTION
 *  Return the current night mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam night mode value
 *****************************************************************************/
U16 mdi_camera_get_para_night(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (camera_setting_p->scene_mode == CAM_NIGHTSCENE) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_image_qty
 * DESCRIPTION
 *  Return the current image quality value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam image quality value
 *****************************************************************************/
U16 mdi_camera_get_para_image_qty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->image_qty;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_image_size
 * DESCRIPTION
 *  Return current image size value
 * PARAMETERS
 *  image width         [OUT]       Current image width
 *  image height        [OUT]       Current image height
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_get_para_image_size(U16* image_width_ptr, U16* image_height_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *image_width_ptr = camera_setting_p->image_width;
    *image_height_ptr = camera_setting_p->image_height;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_flash
 * DESCRIPTION
 *  Return the current flash value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam flash value
 *****************************************************************************/
U16 mdi_camera_get_para_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->flash;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_iso
 * DESCRIPTION
 *  Return the current iso value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam ISO value
 *****************************************************************************/
U16 mdi_camera_get_para_iso(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->iso;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_ae_meter
 * DESCRIPTION
 *  Return the current ae meter value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam AE meter value
 *****************************************************************************/
U16 mdi_camera_get_para_ae_meter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->ae_meter;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_scene_mode
 * DESCRIPTION
 *  Return the current dsc mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam dsc mode value
 *****************************************************************************/
U16 mdi_camera_get_para_scene_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->scene_mode;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_af_mode
 * DESCRIPTION
 *  Return the current af mode value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam AF mode value
 *****************************************************************************/
U16 mdi_camera_get_para_af_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->af_range;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_para_dsc_mode
 * DESCRIPTION
 *  Return the current scene value
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam AF mode value
 *****************************************************************************/
U16 mdi_camera_get_para_dsc_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return camera_setting_p->scene_mode;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_detected_scene_mode
 * DESCRIPTION
 *  Get scene detect result
 * PARAMETERS
 *  void
 * RETURNS
 *  Cam detected scene mode
 *****************************************************************************/
U16 mdi_camera_get_detected_scene_mode(void)
{
#ifdef __AUTO_SCENE_DETECT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_fd_result_struct fd_result;
    U16 scene_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_get_fd_result(stack_get_active_module_id(), &fd_result);
    
    scene_mode = (U16)fd_result.camera_scene_detected_mode;

    return scene_mode;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_is_camera_avaliable
 * DESCRIPTION
 *  Check if camera is avaliable
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE        Avaliable
 *  FALSE       Not avaliable
 *****************************************************************************/
BOOL mdi_camera_is_camera_avaliable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    BOOL is_avaliable = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_camera_power_on(0);
    if (ret == MDI_RES_CAMERA_SUCCEED)
    {
        mdi_camera_power_off();
        is_avaliable = TRUE;
    }

    return is_avaliable;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_autofocus_process
 * DESCRIPTION
 *  Stop auto focus process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
void mdi_camera_stop_autofocus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AF_KEY, CAM_AF_RELEASE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_autofocus_process
 * DESCRIPTION
 *  Start to do auto focus process
 * PARAMETERS
 *  handler         [IN]        Auto focus finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_start_autofocus_process(mdi_camera_af_ind_callback handler, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_AF_KEY, CAM_AF_ONE_TIME);
#endif 
    g_mdi_camera_af_callback = handler;
    mdi_camera_p->user_data = user_data;
    
    SetProtocolEventHandler(mdi_camera_af_finish_ind, MSG_ID_MEDIA_CAM_AF_PROCESS_DONE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_af_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_af_finish_ind(void *inMsg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_af_ind_struct *msg_p = (media_cam_af_ind_struct*) inMsg;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_camera_af_callback)
    {
        #if 1
        mdi_camera_af_result_struct af_result;
        af_result.af_result = (mdi_af_result_enum) msg_p->af_search_result;
        af_result.af_success_zone = msg_p->af_success_zone;
        g_mdi_camera_af_callback(af_result, mdi_camera_p->user_data);       
        #else
/* under construction !*/
        #endif
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MTK_TARGET__ */ 
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_layer_to_jpeg
 * DESCRIPTION
 *  Encode a layer and save the encode result as a file
 * PARAMETERS
 *  layer_handle        [IN]        Layer handle
 *  file_name           [IN]        Filename for the jpeg file
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_ROOT_DIR_FULL        Root directory full
 *  MDI_RES_CAMERA_ERR_FAILED               Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name)
{
    return MDI_RES_CAMERA_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_effect
 * DESCRIPTION
 *  Add effect to one of layers
 * PARAMETERS
 *  app id              [IN]        id  
 *  layer_handle        [IN]        Layer handle 
 *  effect_id           [IN]        Effect index
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_add_post_effect(U16 app_id, gdi_handle layer_handle, U16 effect_id)
{
#if defined(MDP_SUPPORT_IMAGE_EFFECT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    PU8 buf_ptr;
    S32 buf_size = 0;
    S32 media_buf_size = 0;
    PU8 work_buf_ptr_1 = NULL;
    PU8 work_buf_ptr_2 = NULL;
    U8 layer_vcf;
    IMAGE_EFFECT_DEC_STRUCT effect_data;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();



    /* NOTE: only some effect needs two buffer, like "water paint", etc */   
    layer_vcf = (U8)((gdi_layer_struct *)layer_handle)->vcf;
    /* TODO: fix when support 888 format */
    switch (layer_vcf)
    {
        case GDI_COLOR_FORMAT_16:
            buf_size = (layer_width * layer_height * 16) >> 3;
            media_buf_size = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 16) >> 3);
        #if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB565;
            effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
        #else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB565;
            effect_data.dest_color_fmt = IMG_COLOR_FMT_RGB565;
        #endif
            break;
        case GDI_COLOR_FORMAT_24:
            buf_size = (layer_width * layer_height * 24) >> 3;
            media_buf_size = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 24) >> 3);
        #if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB888;
            effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB888;
        #else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB888;
            effect_data.dest_color_fmt = IMG_COLOR_FMT_RGB888;
        #endif
            break;
        default:
            ASSERT(0);
    }


    /* allocate from media task */
    media_get_asm_buffer(
        app_id,
        stack_get_active_module_id(),
        (void **)&work_buf_ptr_1,
        media_buf_size);

    media_get_asm_buffer(
        app_id,        
        stack_get_active_module_id(),
        (void **)&work_buf_ptr_2,
        media_buf_size);

    
#if defined(DRV_IDP_OLD_DESIGN)
    effect_data.data_order = IBR1_ORDER_BGR888; /* not used - just give it a value */
#endif
    effect_data.source_buffer_address = (kal_uint32) buf_ptr;
    effect_data.dest1_buffer_address = (kal_uint32) work_buf_ptr_1;
    effect_data.dest2_buffer_address = (kal_uint32) work_buf_ptr_2;
    effect_data.image_width = layer_width;
    effect_data.image_height = layer_height;
    effect_data.effect_index = effect_id;
    effect_data.adj_level = 0;                  /* not used */
    effect_data.image_effect_dec_cb = NULL;     /* not used */

    image_effect_dec_process(&effect_data);

    /* copy result to soruce layer */
    memcpy(buf_ptr, work_buf_ptr_1, buf_size);

    /* free buffer */
    media_free_asm_buffer(app_id, stack_get_active_module_id(), (void **)&work_buf_ptr_1);
    media_free_asm_buffer(app_id, stack_get_active_module_id(), (void **)&work_buf_ptr_2);

#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_adjustment
 * DESCRIPTION
 *  Image adjustment
 * PARAMETERS
 *  app id              [IN]        id   
 *  layer_handle        [IN]        Layer handle
 *  adjustment_id       [IN]        Adjustment index
 *  value               [IN]        Value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_add_post_adjustment(U16 app_id, gdi_handle layer_handle, U16 adjustment_id, S32 value)
{
#if defined(MDP_SUPPORT_IMAGE_EFFECT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    PU8 buf_ptr;
    S32 buf_size = 0;
    S32 media_buf_size = 0;    
    PU8 work_buf_ptr_1 = NULL;
    PU8 work_buf_ptr_2 = NULL;
    U8 layer_vcf;
    IMAGE_EFFECT_DEC_STRUCT effect_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();

    layer_vcf = (U8)((gdi_layer_struct *)layer_handle)->vcf;
    /* TODO: fix when support 888 format */
    switch (layer_vcf)
    {
        case GDI_COLOR_FORMAT_16:
            buf_size = (layer_width * layer_height * 16) >> 3;
            media_buf_size = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 16) >> 3);
        #if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB565;
            effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
        #else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB565;
            effect_data.dest_color_fmt = IMG_COLOR_FMT_RGB565;
        #endif
            break;
        case GDI_COLOR_FORMAT_24:
            buf_size = (layer_width * layer_height * 24) >> 3;
            media_buf_size = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 24) >> 3);
        #if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB888;
            effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB888;
        #else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB888;
            effect_data.dest_color_fmt = IMG_COLOR_FMT_RGB888;
        #endif
            break;
        default:
            ASSERT(0);
    }

    /* allocate from media task */
    media_get_asm_buffer(
        app_id,
        stack_get_active_module_id(),
        (void **)&work_buf_ptr_1,
        media_buf_size);

    media_get_asm_buffer(
        app_id,
        stack_get_active_module_id(),
        (void **)&work_buf_ptr_2,
        media_buf_size);

    /* TEMP: HW BUGS on MT6219 - source cant be internal SRAM */
    memcpy(work_buf_ptr_2, buf_ptr, buf_size);
    memset(work_buf_ptr_1, 0, buf_size);

#if defined(DRV_IDP_OLD_DESIGN)
    effect_data.data_order = IBR1_ORDER_BGR888; /* not used - just give it a value */
#endif

    effect_data.source_buffer_address = (kal_uint32) work_buf_ptr_2;
    effect_data.dest1_buffer_address = (kal_uint32) work_buf_ptr_1;
    effect_data.dest2_buffer_address = (kal_uint32) NULL;   /* not used */
    effect_data.image_width = layer_width;
    effect_data.image_height = layer_height;
    effect_data.effect_index = adjustment_id;
    effect_data.adj_level = value;
    effect_data.image_effect_dec_cb = NULL;                 /* not used */

    image_adj_dec_process(&effect_data);

    /* copy result to soruce layer */
    memcpy(buf_ptr, work_buf_ptr_1, buf_size);

    /* free buffer */
    media_free_asm_buffer(app_id, stack_get_active_module_id(), (void **)&work_buf_ptr_1);
    media_free_asm_buffer(app_id, stack_get_active_module_id(), (void **)&work_buf_ptr_2);

#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
}
/*******************************************************************************
 * Fast zoomin                                                                 *
 * zoom_limit: MAX ZOOM FACTOR ==> 8x zoom should fill in 80.                  *
 * zoom_step: how many zoom step to be operated per zoomin/zoomout operation.  *
 * zoom_speed: how many frame to be inserted in each zoomin/zoomout zoom step. *
********************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_fast_zoom
 * DESCRIPTION
 *  Start fast zoom [smooth zoom]
 * PARAMETERS
 *  zoom_in         [IN]        Zoom in/out
 *  zoom_limit      [IN]        Max zoom step.
 *  zoom_step       [IN]        How many zoom step to be operated per zoomin/zoomout operation.
 *  zoom_speed      [IN]        How many frame to be inserted in each zoomin/zoomout zoom step.
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
void mdi_camera_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_start_fast_zoom(stack_get_active_module_id(), (kal_bool)zoom_in, zoom_limit, zoom_step, zoom_speed);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_fast_zoom
 * DESCRIPTION
 *  Stop fast zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_stop_fast_zoom(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_stop_fast_zoom(stack_get_active_module_id());
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fast_zoom_step
 * DESCRIPTION
 *  Get current zoom step
 * PARAMETERS
 *  step        [OUT]   Zoom step    
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_get_fast_zoom_step(U32 *step)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    media_cam_get_zoom_step_factor(stack_get_active_module_id(), NULL, step);
#endif /* __MTK_TARGET__ */ 
}



#pragma arm section code, rodata
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fast_zoom_factor
 * DESCRIPTION
 *  Get current zoom factor
 * PARAMETERS
 *  factor      [OUT]   Zoom factor     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_get_fast_zoom_factor(U32 *factor)
{
#ifdef __MTK_TARGET__
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
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
        is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);        
        if (!is_loaded){
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
    }
    #endif 
    media_cam_get_zoom_step_factor(stack_get_active_module_id(), factor, NULL);
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        if (!is_loaded){
            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        }
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);
    }
    #endif 
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_max_zoom_factor
 * DESCRIPTION
 *  Get max zoom factor
 * PARAMETERS
 *  image_width         [IN]        Image width      
 *  image_height        [IN]        Image height
 * RETURNS
 *  Zoom factor value
 *****************************************************************************/
U16 mdi_camera_get_max_zoom_factor(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_resolution;
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((image_width <= LCD_WIDTH && image_height <= LCD_HEIGHT) ||
        (image_height <= LCD_WIDTH && image_height <= LCD_HEIGHT))
        image_resolution = MDI_CAMERA_CAP_SIZE_WALLPAPER;
    else if ((image_width <= 320 && image_height <= 240) ||
             (image_width <= 240 && image_height <= 320))
        image_resolution = MDI_CAMERA_CAP_SIZE_QVGA;
    else if ((image_width <= 640 && image_height <= 480) ||
             (image_width <= 480 && image_height <= 640))
        image_resolution = MDI_CAMERA_CAP_SIZE_VGA;
    else if ((image_width <= 1280 && image_height <= 960) ||
             (image_width <= 960 && image_height <= 1280))
        image_resolution = MDI_CAMERA_CAP_SIZE_1M;
    else if ((image_width <= 1600 && image_height <= 1200) ||
             (image_width <= 1200 && image_height <= 1600))
        image_resolution = MDI_CAMERA_CAP_SIZE_2M;
    else if ((image_width <= 2048 && image_height <= 1536) ||
             (image_width <= 1536 && image_height <= 2048))
        image_resolution = MDI_CAMERA_CAP_SIZE_3M;
    else if ((image_width <= 2304 && image_height <= 1728) ||
             (image_width <= 1728 && image_height <= 2304))
        image_resolution = MDI_CAMERA_CAP_SIZE_4M;
    else if ((image_width <= 3264 && image_height <= 2488) ||
             (image_width <= 2488 && image_height <= 3264))
        image_resolution = MDI_CAMERA_CAP_SIZE_8M;
    else
        image_resolution = MDI_CAMERA_CAP_SIZE_OTHER;

    zoom.image_size = image_resolution;
    zoom.result_p = &result;

    media_cam_sensor_query_zoom_info(stack_get_active_module_id(), &zoom);

    return result.MaxZoomFactor;  

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_load_default_setting
 * DESCRIPTION
 *  Get camera default setting
 * PARAMETERS        
 *  camera_setting_data     [OUT]       Camera setting structure
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_load_default_setting(mdi_camera_setting_struct *camera_setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* preview parametes */
    camera_setting_data->wb = MDI_CAMERA_WB_AUTO;
    camera_setting_data->ev = MDI_CAMERA_EV_0;
    camera_setting_data->banding = MDI_CAMERA_BANDING_50HZ;
    camera_setting_data->flash = MDI_CAMERA_FLASH_AUTO;

    camera_setting_data->iso = MDI_CAMERA_ISO_AUTO;
    camera_setting_data->ae_meter = MDI_CAMERA_AE_METER_AUTO;
    camera_setting_data->scene_mode = MDI_CAMERA_SCENE_MODE_AUTO;

#if defined(__MDI_CAMERA_FD_SUPPORT__)
    camera_setting_data->fd_enable = FALSE;
#endif

    camera_setting_data->zoom = 0; /* 1x */
    camera_setting_data->af_operation_mode = CAM_AF_OFF;
    camera_setting_data->af_range = CAM_AF_RANGE_AUTO;
    camera_setting_data->sharpness = MDI_CAMERA_SHARPNESS_MEDIUM;
    camera_setting_data->saturation = MDI_CAMERA_SATURATION_MEDIUM;
    camera_setting_data->contrast = MDI_CAMERA_CONTRAST_MEDIUM;  

    /* default effect */
    camera_setting_data->effect = MDI_CAMERA_EFFECT_NOMRAL;
    camera_setting_data->hue = 0;

    camera_setting_data->overlay_frame_mode = FALSE;
    camera_setting_data->overlay_frame_depth = 0;
    camera_setting_data->overlay_frame_width = 0;
    camera_setting_data->overlay_frame_height = 0;
    camera_setting_data->overlay_frame_source_key = 0;
    camera_setting_data->overlay_frame_buffer_address = 0;
    camera_setting_data->overlay_palette_addr = NULL;
    camera_setting_data->overlay_palette_size = 0;

    /* capture parameters */
    camera_setting_data->image_qty = MDI_CAMERA_JPG_QTY_NORMAL;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_flash_setting
 * DESCRIPTION
 *  Turn on/off LED flash light
 * PARAMETERS
 *  is_on       [IN]    On/off 
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_flash_setting(BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_FLASH_MODE, (kal_int16)is_on);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_focus_zone
 * DESCRIPTION
 *  Get camera driver AF zone location and 
 *  the location coordinate is the preview layer not LCD 
 * PARAMETERS
 *  zone            [OUT]       AF zone structure        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_get_focus_zone(mdi_camera_af_window_struct* zone)
{
#if defined(AF_SUPPORT)
#ifdef __MTK_TARGET__
    {
        media_cam_af_zone_para_struct af_zone;
        U8 i = 0;

        #ifdef __MM_DCM_SUPPORT__
        if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
        {
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
        #endif 

        media_cam_get_focus_zone(stack_get_active_module_id(), &af_zone);

        zone->af_active_zone = af_zone.af_active_zone;

        for (;i<MDI_CAMERA_AF_ZONE_MAX_NO; i++)
        {
            zone->af_zone[i].af_zone_h = af_zone.af_zone[i].af_zone_h;
            zone->af_zone[i].af_zone_w = af_zone.af_zone[i].af_zone_w;
            zone->af_zone[i].af_zone_x = af_zone.af_zone[i].af_zone_x;
            zone->af_zone[i].af_zone_y = af_zone.af_zone[i].af_zone_y;
        }

    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);        
    }
    #endif

    }
#endif 

#else
    ASSERT(0);
#endif /* AF_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_overlay_data
 * DESCRIPTION
 *  Update overlay struct
 * PARAMETERS
 *  overlay        [IN]        Overlay structure pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_overlay_data(mdi_camera_overlay_struct *overlay)
{
#ifdef MDP_SUPPORT_HW_OVERLAP

    if (overlay == NULL)
    {
        if (camera_overlay_p != NULL)
        {
            OslMfree((S8*)camera_overlay_p);
            camera_overlay_p = NULL;
        }
        return;
    }

    if (camera_overlay_p == NULL)
    {
        camera_overlay_p = (mdi_camera_overlay_struct*)OslMalloc(sizeof(mdi_camera_overlay_struct));       
    }

    camera_overlay_p->overlay_frame_mode = overlay->overlay_frame_mode;

    camera_overlay_p->overlay_frame_width = overlay->overlay_frame_width;
    camera_overlay_p->overlay_frame_height = overlay->overlay_frame_height;
    camera_overlay_p->overlay_frame_buffer_address = overlay->overlay_frame_buffer_address;
    camera_overlay_p->overlay_frame_source_key = overlay->overlay_frame_source_key;
    camera_overlay_p->overlay_frame_depth = overlay->overlay_frame_depth;
    camera_overlay_p->overlay_palette_addr = overlay->overlay_palette_addr;
    camera_overlay_p->overlay_palette_size = overlay->overlay_palette_size;
#else
    ASSERT(0);
#endif

}


static void mdi_camera_fill_overlay_data(media_cam_capture_req_struct* capture_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDP_SUPPORT_HW_OVERLAP
    if (camera_overlay_p == NULL)
    {
        capture_data->overlay_frame_mode = (kal_bool)camera_setting_p->overlay_frame_mode;
        capture_data->overlay_color_depth = camera_setting_p->overlay_frame_depth;
        capture_data->overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
        capture_data->overlay_frame_width = camera_setting_p->overlay_frame_width;
        capture_data->overlay_frame_height = camera_setting_p->overlay_frame_height;
        capture_data->overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
        capture_data->overlay_palette_addr = camera_setting_p->overlay_palette_addr;
        capture_data->overlay_palette_size = camera_setting_p->overlay_palette_size;
    }
    else
    {
        capture_data->overlay_frame_mode = (kal_bool)camera_overlay_p->overlay_frame_mode;
        capture_data->overlay_color_depth = camera_overlay_p->overlay_frame_depth;
        capture_data->overlay_frame_source_key = camera_overlay_p->overlay_frame_source_key;
        capture_data->overlay_frame_width = camera_overlay_p->overlay_frame_width;
        capture_data->overlay_frame_height = camera_overlay_p->overlay_frame_height;
        capture_data->overlay_frame_buffer_address = camera_overlay_p->overlay_frame_buffer_address;
        capture_data->overlay_palette_addr = camera_overlay_p->overlay_palette_addr;
        capture_data->overlay_palette_size = camera_overlay_p->overlay_palette_size;
    }
#else
    capture_data->overlay_frame_mode = KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_support_info
 * DESCRIPTION
 *  Query camera sensor function capability
 * PARAMETERS
 *  mdi_setting_type        [IN]        Function type
 *  p_info                  [OUT]       Function support information structure 
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_query_support_info(U32 mdi_setting_type, void *p_info)
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
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
        is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
        if (!is_loaded){
           DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
    }
    #endif 

    query.camera_mode = CAL_CAMERA_MODE_CAMERA;
    query.item_id = mdi_setting_type;
    query.struct_p = p_info;

    media_cam_sensor_query_capability(stack_get_active_module_id(), &query);

    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        if (!is_loaded){
            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        }
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);        
    }
    #endif 
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_zoom_info
 * DESCRIPTION
 *  Query the zoom information
 * PARAMETERS
 *  p_info          [OUT]        The current zoom capability
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_query_zoom_info(mdi_camera_zoom_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;
#ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
#endif  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMMED, NULL, NULL);
        is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
        if (!is_loaded){
            DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);  
        }
    }
    #endif 
    
    zoom.camera_mode = CAL_CAMERA_MODE_CAMERA;
    zoom.image_size = camera_setting_p->image_resolution;
    zoom.result_p = &result;

    media_cam_sensor_query_zoom_info(stack_get_active_module_id(), &zoom);

    p_info->zoom_support_type = result.DzType;
    p_info->max_zoom_factor = result.MaxZoomFactor;
    p_info->zoom_steps = result.TotalZoomSteps;
    
    #ifdef __MM_DCM_SUPPORT__
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        if (!is_loaded){
            DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        }
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMMED);        
    }
    #endif     
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_fd_process
 * DESCRIPTION
 *  Start face detection process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_start_fd_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_CAMERA_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_fd_process
 * DESCRIPTION
 *  Stop face detection process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_fd_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_CAMERA_ERR_FAILED;
}


MDI_RESULT mdi_camera_set_focus_zone_by_fd_id(U32 fd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MDI_CAMERA_FD_SUPPORT__)
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        ret = media_cam_set_fd_id(stack_get_active_module_id(),fd_id);
    }    
#endif
    return ret;
}


MDI_RESULT mdi_camera_unset_fd_focus_zone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MDI_CAMERA_FD_SUPPORT__)
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        ret = media_cam_unset_fd_id(stack_get_active_module_id());
    }    
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fd_result
 * DESCRIPTION
 *  Get face detection result
 * PARAMETERS
 *  fd_result_p     [OUT]       Face detection result
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_get_fd_result(mdi_camera_fd_result_struct *fd_result_p)
{
#if defined(__MDI_CAMERA_FD_SUPPORT__) && defined(__MTK_TARGET__)
    media_cam_fd_result_struct fd_result;
    U8 i = 0;
    media_cam_get_fd_result(stack_get_active_module_id(), &fd_result);

    if (fd_result.face_no == 0)
        fd_result_p->fd_result = MDI_RES_CAMERA_ERR_FAILED;
    else
        fd_result_p->fd_result = MDI_RES_CAMERA_SUCCEED;

    fd_result_p->fd_searched_num = fd_result.face_no;

#if defined(__SMILE_SHUTTER_SUPPORT__)
    fd_result_p->sd_searched_num = fd_result.smile_detected_no;
    fd_result_p->sd_end_flag = fd_result.sd_end_flag;
#endif

    for(i=0;i<fd_result_p->fd_searched_num;i++)
    {
        fd_result_p->fd_zone[i].fd_zone_x = (fd_result.rect_x0[i] + fd_result.rect_x1[i])/2;
        fd_result_p->fd_zone[i].fd_zone_y = (fd_result.rect_y0[i] + fd_result.rect_y1[i])/2;
        fd_result_p->fd_zone[i].fd_zone_w = fd_result.rect_x1[i] - fd_result.rect_x0[i];
        fd_result_p->fd_zone[i].fd_zone_h = fd_result.rect_y1[i] - fd_result.rect_y0[i];
    #if defined(__SMILE_SHUTTER_SUPPORT__)
        fd_result_p->fd_zone[i].sd_zone_x = (fd_result.sd_rect_x0[i] + fd_result.sd_rect_x1[i])/2;
        fd_result_p->fd_zone[i].sd_zone_y = (fd_result.sd_rect_y0[i] + fd_result.sd_rect_y1[i])/2;
        fd_result_p->fd_zone[i].sd_zone_w = fd_result.sd_rect_x1[i] - fd_result.sd_rect_x0[i];
        fd_result_p->fd_zone[i].sd_zone_h = fd_result.sd_rect_y1[i] - fd_result.sd_rect_y0[i];
    #endif        
    }
#elif defined(__MDI_CAMERA_FD_SUPPORT__) && !defined(__MTK_TARGET__)

    fd_result_p->fd_result = MDI_RES_CAMERA_ERR_FAILED;

#if defined(__SMILE_SHUTTER_SUPPORT__)
    fd_result_p->sd_searched_num = 0;
    fd_result_p->sd_end_flag = MMI_FALSE;
#endif

#endif /* defined(__MDI_CAMERA_FD_SUPPORT__) && defined(__MTK_TARGET__) */
    return MDI_RES_CAMERA_SUCCEED;

}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_af_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_fd_result_ind(void *inMsg)
{
#if defined(__MDI_CAMERA_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_fd_result_ind_struct *msg_p = (media_cam_fd_result_ind_struct*) inMsg;
    mdi_camera_fd_result_ind_struct result_ind;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        if (g_mdi_camera_fd_callback)
        {
            if (msg_p->fd_result.face_no > 0)
            {
                result_ind.fd_result = MDI_RES_CAMERA_SUCCEED;
                result_ind.fd_searched_num = msg_p->fd_result.face_no;

                for(i=0;i<result_ind.fd_searched_num;i++)
                {
                //    result_ind.fd_zone[i].fd_id = msg_p->fd_result.id[i];
                //    result_ind.fd_zone[i].fd_priority = msg_p->fd_result.priority[i];
                    result_ind.fd_zone[i].fd_zone_x = (msg_p->fd_result.rect_x0[i] + msg_p->fd_result.rect_x1[i])/2;
                    result_ind.fd_zone[i].fd_zone_y = (msg_p->fd_result.rect_y0[i] + msg_p->fd_result.rect_y1[i])/2;
                    result_ind.fd_zone[i].fd_zone_w = msg_p->fd_result.rect_x1[i] - msg_p->fd_result.rect_x0[i];
                    result_ind.fd_zone[i].fd_zone_h = msg_p->fd_result.rect_y1[i] - msg_p->fd_result.rect_y0[i];;                
                }
            }
            else
            {
                result_ind.fd_result = MDI_RES_CAMERA_ERR_FAILED;
            }

            g_mdi_camera_fd_callback(&result_ind, mdi_camera_p->user_data);
        }
        else
        {
            ASSERT(0);
        }
    }
#endif /* __MDI_CAMERA_FD_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_query_panorama_zoom_info
 * DESCRIPTION
 *  Query the panorama zoom information
 * PARAMETERS
 *  p_info          [OUT]        The current zoom capability
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_query_panorama_zoom_info(mdi_camera_zoom_info *p_info)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zoom.camera_mode = CAL_CAMERA_MODE_AUTORAMA;
    zoom.image_size = camera_setting_p->image_resolution;
    zoom.result_p = &result;

    media_cam_sensor_query_zoom_info(stack_get_active_module_id(), &zoom);

    p_info->zoom_support_type = result.DzType;
    p_info->max_zoom_factor = result.MaxZoomFactor;
    p_info->zoom_steps = result.TotalZoomSteps;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_pause_stitching_panorama
 * DESCRIPTION
 *  Pause stitching panorama process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_pause_stitching_panorama(void)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_pause_panorama(stack_get_active_module_id());

    if (result == MED_RES_OK)
    {
        mdi_camera_p->state = CAMERA_STATE_IDLE;
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_resume_stitching_panorama
 * DESCRIPTION
 *  Resume stitching panorama process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_resume_stitching_panorama(void)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_resume_panorama(stack_get_active_module_id());

    if (result == MED_RES_OK)
    {
        mdi_camera_p->state = CAMERA_STATE_STITCH_PANORAMA;
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_stitching_panorama
 * DESCRIPTION
 *  Stop stitching panorama process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_stitching_panorama(void)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_abort_panorama(stack_get_active_module_id());
   
    mdi_camera_p->stitch_seq_num++;
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
    
#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */

    /* not supported on !__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    ASSERT(0);    
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_panorama_result_ind
 * DESCRIPTION
 *  Panorama finish indication mesg which is from media task.
 * PARAMETERS
 *  inMsg           [IN]        stitch result     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_camera_panorama_result_ind(void *inMsg)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_stitch_result_ind_struct *msg_p = (media_cam_stitch_result_ind_struct*) inMsg;
    mdi_camera_panorama_stitch_result_struct result_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI, 
        MDI_TRC_CAMERA_PANORAMA_STITCH_RESULT, 
        mdi_camera_p->state, 
        mdi_camera_p->stitch_seq_num);
    
    memset(&result_ind,0x0,sizeof(mdi_camera_panorama_stitch_result_struct));

    if (mdi_camera_p->stitch_seq_num == msg_p->seq_no)
    {
        if (msg_p->result == MED_RES_OK)
        {
            result_ind.result = MDI_RES_CAMERA_SUCCEED;
        
            result_ind.jpeg_buffer_address = msg_p->jpeg_file_address;
            result_ind.jpeg_buffer_size = msg_p->jpeg_file_size;
            result_ind.jpeg_image_width = msg_p->jpeg_file_width;
            result_ind.jpeg_image_height = msg_p->jpeg_file_height;
        }
        else
        {
            result_ind.result = MDI_RES_CAMERA_ERR_FAILED;
        }

        g_mdi_camera_panorama_stitch_result_callback(&result_ind, mdi_camera_p->user_data);

        if (mdi_camera_p->state == CAMERA_STATE_STITCH_PANORAMA)
        {
            mdi_camera_p->state = CAMERA_STATE_IDLE;
        }
    }

#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */

    /* not supported on !__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    ASSERT(0);    

#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_panorama_quickview_result_ind
 * DESCRIPTION
 *  Panorama quickview finish indication mesg which is from media task.
 * PARAMETERS
 *  inMsg           [IN]        stitch result     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_camera_panorama_quickview_result_ind(void *inMsg)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_panorama_stitch_quickview_struct quickview_info;
    media_cam_panorama_quickview_ind_struct *msg_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    msg_p = (media_cam_panorama_quickview_ind_struct*)inMsg;

    quickview_info.result = msg_p->result;
    quickview_info.quickview_start_x = msg_p->quickview_content_start_x;
    quickview_info.quickview_start_y = msg_p->quickview_content_start_y;
    quickview_info.quickview_width = msg_p->quickview_content_width;
    quickview_info.quickview_height = msg_p->quickview_content_height;

    if (g_mdi_camera_panorama_stitch_quickview_callback)
        g_mdi_camera_panorama_stitch_quickview_callback(&quickview_info, mdi_camera_p->user_data);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_reset_panorama_3a
 * DESCRIPTION
 *  Resets 3A when terminating panorama process.
 * PARAMETERS
 *  void     
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_reset_panorama_3a(void)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_cam_reset_panorama_3a(stack_get_active_module_id());

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_stitch_memory
 * DESCRIPTION
 *  Set stitch memory before panorama capture
 * PARAMETERS
 *  void     
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_set_panorama_stitch_memory(U8* buffer, U32 buffer_size)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    media_cam_set_stitch_mem_req_struct stitch_data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_IDLE && 
        mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

    stitch_data.buffer_address = (kal_uint32)buffer;
    stitch_data.buffer_size = (kal_uint32)buffer_size;
    
    result = media_cam_set_panorama_stitch_memory(stack_get_active_module_id(), &stitch_data);
    
    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
    
#else /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* __MDI_CAMERA_PANORAMA_VIEW_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_panorama_cap_info
 * DESCRIPTION
 *  Get auto capture tracking infomation
 * PARAMETERS
 *  cap_result_p        [OUT]       Panorama cap tracking info
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_get_panorama_cap_info(mdi_camera_panorama_cap_info_struct *cap_info_p)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_autocap_result_struct capture_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_get_autocap_result(stack_get_active_module_id(), &capture_info);

    cap_info_p->ready_to_shot = capture_info.ready_to_shot;
    cap_info_p->mv_x = capture_info.mv_x;
    cap_info_p->mv_y = capture_info.mv_y;
    cap_info_p->overlap_ratio = capture_info.overlap_ratio;
    cap_info_p->stitch_dir = capture_info.stitch_dir;
    cap_info_p->move_hint_dir = capture_info.move_hint_dir;

#elif defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__) && !defined(__MTK_TARGET__)
    cap_info_p->ready_to_shot = KAL_FALSE;
#endif /* defined(__MDI_CAMERA_FD_SUPPORT__) && defined(__MTK_TARGET__) */
    return MDI_RES_CAMERA_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_panorama_stitch_image
 * DESCRIPTION
 *  Encode stitch image with the clip information
 * PARAMETERS
 *  encode_info_p        [IN]       Panorama encode info
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_encode_panorama_stitch_image(mdi_camera_panorama_stitch_encode_struct *encode_info_p)
{
#if defined(__MDI_CAMERA_PANORAMA_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_panorama_encode_req_struct encode_req;
    U32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    encode_req.quickview_roi_x = encode_info_p->quickview_roi_x;
    encode_req.quickview_roi_y = encode_info_p->quickview_roi_y;
    encode_req.quickview_roi_width = encode_info_p->quickview_roi_width;
    encode_req.quickview_roi_height = encode_info_p->quickview_roi_height;
    encode_req.is_jaia_qvi_buf_aligned = (kal_bool)encode_info_p->is_quickview_centred;

    #if defined(__MTK_TARGET__)
    ret = media_cam_encode_panorama(stack_get_active_module_id(), &encode_req);
    #endif

    if (ret == MED_RES_OK)
        return MDI_RES_CAMERA_SUCCEED;
    else
        return MDI_RES_CAMERA_ERR_FAILED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}


static void mdi_camera_sd_event_ind_hdlr(void *inMsg)
{
#if defined(__MDI_CAMERA_FD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_sd_event_ind_struct *msg_p = (media_cam_sd_event_ind_struct *) inMsg;
    mdi_camera_sd_event_struct result_ind;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_CAMERA_SD_EVENT, msg_p->result);
        
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        if (g_mdi_camera_sd_callback!=NULL)
        {
            if (msg_p->result == KAL_TRUE)
            {
                result_ind.event = MDI_CAMERA_SD_ON_READY_TO_CAPTURE;
                result_ind.fd_searched_num = msg_p->fd_result.face_no;
                result_ind.smile_detected_num = msg_p->fd_result.smile_detected_no;

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_CAMERA_SD_RESULT, msg_p->fd_result.face_no,msg_p->fd_result.smile_detected_no);
                
                for(i=0;i<result_ind.smile_detected_num ;i++)
                {                
                 //   result_ind.fd_zone[i].fd_id = msg_p->fd_result.id[i];
                 //   result_ind.fd_zone[i].fd_priority = msg_p->fd_result.priority[i];
                    result_ind.fd_zone[i].fd_zone_x = (msg_p->fd_result.rect_x0[i] + msg_p->fd_result.rect_x1[i])/2;
                    result_ind.fd_zone[i].fd_zone_y = (msg_p->fd_result.rect_y0[i] + msg_p->fd_result.rect_y1[i])/2;
                    result_ind.fd_zone[i].fd_zone_w = msg_p->fd_result.rect_x1[i] - msg_p->fd_result.rect_x0[i];
                    result_ind.fd_zone[i].fd_zone_h = msg_p->fd_result.rect_y1[i] - msg_p->fd_result.rect_y0[i];
    #if defined(__SMILE_SHUTTER_SUPPORT__)
                    result_ind.fd_zone[i].sd_zone_x = (msg_p->fd_result.sd_rect_x0[i] + msg_p->fd_result.sd_rect_x1[i])/2;
                    result_ind.fd_zone[i].sd_zone_y = (msg_p->fd_result.sd_rect_y0[i] + msg_p->fd_result.sd_rect_y1[i])/2;
                    result_ind.fd_zone[i].sd_zone_w = msg_p->fd_result.sd_rect_x1[i] - msg_p->fd_result.sd_rect_x0[i];
                    result_ind.fd_zone[i].sd_zone_h = msg_p->fd_result.sd_rect_y1[i] - msg_p->fd_result.sd_rect_y0[i];
    #endif /* defined(__SMILE_SHUTTER_SUPPORT__) */
                }
            }
            else
            {
                result_ind.event = MDI_CAMERA_SD_ON_FAILED;
            }

            g_mdi_camera_sd_callback(&result_ind, mdi_camera_p->user_data);
            g_mdi_camera_sd_callback = NULL;
        }
        else
        {
            ASSERT(0);
        }
    }
#endif /* __MDI_CAMERA_FD_SUPPORT__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_sd
 * DESCRIPTION
 *  Start smile detection.
 * PARAMETERS
 *  on_sd_event_cb          : [IN]        Smile Detect event callback function ptr.
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_start_sd(mdi_camera_on_sd_event_cb on_sd_event_cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SMILE_SHUTTER_SUPPORT__)
    SetProtocolEventHandler(mdi_camera_sd_event_ind_hdlr, MSG_ID_MEDIA_CAM_SD_EVENT_IND);

    ASSERT(on_sd_event_cb!=NULL);

    g_mdi_camera_sd_callback = on_sd_event_cb;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_CAMERA_SD_START);
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SMILE_DETECT_START, KAL_TRUE);
#endif /* __MTK_TARGET__ */ 

    return MDI_RES_CAMERA_SUCCEED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_sd
 * DESCRIPTION
 *  Stop smile detection.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_sd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SMILE_SHUTTER_SUPPORT__)

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_CAMERA_SD_STOP);
    g_mdi_camera_sd_callback = NULL;
    
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_SMILE_DETECT_START, KAL_FALSE);
#endif /* __MTK_TARGET__ */ 

    return MDI_RES_CAMERA_SUCCEED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_pause_preview_post_process
 * DESCRIPTION
 *  Pause post process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_pause_preview_post_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MDI_RES_CAMERA_ERR_FAILED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    result = media_cam_pause_preview_postproc(stack_get_active_module_id());
#endif /* __MTK_TARGET__ */ 
    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else 
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_resume_preview_post_process
 * DESCRIPTION
 *  Resume preview post process
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED      Success
 *  MDI_RES_CAMERA_ERR_FAILED   Failed
 *****************************************************************************/
MDI_RESULT mdi_camera_resume_preview_post_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    ret = media_cam_resume_preview_postproc(stack_get_active_module_id()); 
#endif
    if (ret == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else 
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_hw_layer_get_content
 * DESCRIPTION
 *  Get preview buffer content.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/

MDI_RESULT mdi_camera_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size)
{
#ifdef __MDI_CAMERA_GET_BUFFER_CONTENT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_buff_content_req_struct req;
    MDI_RESULT ret = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING && 
        layer_handle == camera_preview_p->preview_layer_handle)
    {
         req.buffer_width = camera_setting_p->preview_width;
         req.buffer_height = camera_setting_p->preview_height;
         req.buffer_address = (kal_uint32)dst_buff_p;
         req.buffer_size = dst_buff_size;
         ret = (MDI_RESULT)media_cam_get_buffer_content(stack_get_active_module_id(), (void*)&req);

         return ret;
    }
    else
#endif /* __MDI_CAMERA_GET_BUFFER_CONTENT_SUPPORT__ */
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_predicted_image_size
 * DESCRIPTION
 *  Get predicted capture size.
 * PARAMETERS
 *  image_qty       [IN]        image quality
 *  image_width     [IN]        image width
 *  image_height    [IN]        image height
 *  image_size_p    [OUT]       image size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
MDI_RESULT mdi_camera_get_predicted_image_size(U16 image_qty, U32 image_width, U32 image_height, U32* image_size_p)
{
#ifdef __MDI_CAMERA_GET_PREDICT_IMGSIZE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_get_predicted_image_size_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.image_qty = image_qty;
    req.image_width = image_width;
    req.image_height = image_height;
    req.image_size_p = image_size_p;

    media_cam_get_predicted_image_size(stack_get_active_module_id(), (void*)&req);
    
    return MDI_RES_CAMERA_SUCCEED;
#else
    return MDI_RES_CAMERA_ERR_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_quickview_color_format
 * DESCRIPTION
 *  Get predicted capture size.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  color format
 *****************************************************************************/
U32 mdi_camera_get_quickview_color_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__    
    return GDI_COLOR_FORMAT_UYVY422;
#else
    return GDI_COLOR_FORMAT_16;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory_with_raw_data
 * DESCRIPTION
 *  Capture an image with raw data.
 * PARAMETERS
 *  color_format        [IN]    The color format of raw data 
 *  buffer              [IN]    The buffer address
 *  buffer_size         [IN]    The buffer size
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
MDI_RESULT mdi_camera_capture_to_memory_with_raw_data(mdi_camera_raw_data_format_enum color_format, U8* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data = {0};
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    // RAW capture resolution upper bound
    if (camera_setting_p->image_width > 1264 && camera_setting_p->image_height > 948)
    {
        return MDI_RES_CAMERA_ERR_CAPTURE_FAILED;
    }

    mdi_camera_fillin_capture_data(&capture_data);

    capture_data.media_mode = MED_MODE_ARRAY;
    capture_data.app_capture_buffer_p = buffer;
    capture_data.app_capture_buffer_size = buffer_size;
    capture_data.snapshot_number = 1;
    if (color_format == MDI_CAMERA_RAWDATA_RGB565)
        capture_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
    else if (color_format == MDI_CAMERA_RAWDATA_YUV420)
        capture_data.image_data_format = MM_IMAGE_FORMAT_YUV420;

    capture_data.capture_mode = CAM_STILL_CAPTURE_RAW_DATA;
    capture_data.continue_capture = FALSE;
    
    mdi_camera_fill_overlay_data(&capture_data);

    result = mdi_camera_med_capture(&capture_data);

    return mdi_camera_get_error_code(result);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_capture_disable_jaia
 * DESCRIPTION
 *  Enable/disable capture with JAIA 
 * PARAMETERS
 *  is_disable          [IN]        enable[FALSE]/disable[TRUE]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_capture_disable_jaia(MMI_BOOL is_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_set_param(stack_get_active_module_id(), CAL_FEATURE_CAMERA_JAIA_DISABLE, (kal_int16)is_disable);
}
#pragma arm section code, rodata

#if defined(__MTK_INTERNAL__)
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
#ifdef __MDI_CAMERA_PROFILING_SUPPORT__
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
#ifdef __MDI_CAMERA_PROFILING_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MDI_CAMERA_PROFILING_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MDI_CAMERA_PROFILING_SUPPORT__
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
#endif /* __MDI_CAMERA_PROFILING_SUPPORT__ */
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
#ifdef __MDI_CAMERA_PROFILING_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_layer_to_file
 * DESCRIPTION
 *  Capture from one of layers to a jpeg file
 * PARAMETERS
 *  capture_layer_flag      [IN]        Layer configuration
 *  file_name               [IN]        File_name buffer pointer
 *  offset_x                [IN]        Capture region's offset x
 *  offset_y                [IN]        Capture region's offset y
 *  width                   [IN]        Capture region's width
 *  height                  [IN]        Capture region's height
 *  continue_capture        [IN]        Continue capture flag
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_layer_to_file(
            U32 capture_layer_flag,
            S8 *file_name,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            U8 continue_capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->image_width = width;
    camera_setting_p->image_height = height;
    return mdi_camera_capture(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory
 * DESCRIPTION
 *  Capture a jpeg image and store the image in memory [old interface, not recommendable]
 * PARAMETERS
 *  buf_pp              [OUT]       Pointer to a buffer pointer for jpeg file
 *  captured_size       [OUT]       Captured size
 *  file_name           [IN]        Filename buffer pointer
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MDICAM_ROCODE", rodata = "DYNAMIC_CODE_MDICAM_RODATA"
MDI_RESULT mdi_camera_capture_to_memory(U8 **buf_pp, U32 *captured_size,S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_camera_capture(file_name);

    if (ret == MDI_RES_CAMERA_SUCCEED)
        ret = mdi_camera_encode_capture_image(buf_pp, captured_size);

    return ret;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_file
 * DESCRIPTION
 *  Capture one jpeg file
 * PARAMETERS
 *  file_name               [IN]        Filename buffer pointer         
 *  continue_capture        [IN]        Continue capture flag
 * RETURNS
 *  MDI_RES_CAMERA_SUCCEED                  Success
 *  MDI_RES_CAMERA_ERR_DISK_FULL            Disk full
 *  MDI_RES_CAMERA_ERR_WRITE_PROTECTION     Disk write protection
 *  MDI_RES_CAMERA_ERR_NO_DISK              No disk
 *  MDI_RES_CAMERA_ERR_CAPTURE_FAILED       Capture failed
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_file(S8 *file_name, U8 continue_capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_CAMERA_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_camera_capture(file_name);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_open
 * DESCRIPTION
 *  Open MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_color_engine_open()
{
#ifdef __COLOR_HW_SUPPORTED__
    COLOR_STATUS_ENUM color_status = COLOR_STATUS_OK;
    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;
    
    color_status = colorWrapperOpen(&g_mdi_camera_colorHandle, COLOR_SCENARIO_CAMERA_QUICKVIEW);
    if (color_status == COLOR_STATUS_OK )
    {
        ret = MDI_RES_CAMERA_SUCCEED;
    }
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_enable
 * DESCRIPTION
 *  Enable MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_color_engine_enable()
{
#ifdef __COLOR_HW_SUPPORTED__
    COLOR_STATUS_ENUM color_status = COLOR_STATUS_OK;
    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;
    
    color_status = colorWrapperEnable(g_mdi_camera_colorHandle, 0);
    if (color_status == COLOR_STATUS_OK )
    { 
        ret = MDI_RES_CAMERA_SUCCEED;
    }
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_disable
 * DESCRIPTION
 *  Disable MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_color_engine_disable()
{
#ifdef __COLOR_HW_SUPPORTED__
    COLOR_STATUS_ENUM color_status = COLOR_STATUS_OK;
    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;
    
    color_status = colorWrapperDisable(g_mdi_camera_colorHandle);
    if (color_status == COLOR_STATUS_OK )
    {
        ret = MDI_RES_CAMERA_SUCCEED;
    }
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_color_engine_close
 * DESCRIPTION
 *  Close MM color Engine
 * PARAMETERS   
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_color_engine_close()
{
#ifdef __COLOR_HW_SUPPORTED__
    COLOR_STATUS_ENUM color_status = COLOR_STATUS_OK;
    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;
    
    color_status = colorWrapperClose(g_mdi_camera_colorHandle);
    if (color_status == COLOR_STATUS_OK )
    {
        ret = MDI_RES_CAMERA_SUCCEED;
    }
    return ret;
#else
    return MDI_RES_CAMERA_SUCCEED;
#endif     
}


#endif /* __MMI_CAMERA__ */ 

