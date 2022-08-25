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
 * 
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
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

#include "MMI_include.h"

#ifdef __MMI_WEBCAM__

#include "CommonScreens.h"  /* DisplayPopup */
#include "UcmsrvGprot.h"
#include "PhonesetupGprots.h"
#include "GpioSrvGprot.h"    /* led pattern */

#include "mdi_datatype.h"
#include "mdi_webcam.h"
#include "mdi_camera.h"
#include "mdi_include.h"
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
#include "CustWebcamImgData.h"
#pragma arm section code, rodata
#include "CommonScreensResDef.h"
#include "GlobalResDef.h"

#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#elif defined (__MMI_CAMERA__)&& !defined(__MMI_CAMCORDER__)
#include "CameraApp.h"
#endif

#include "USBsrvGprot.h"

#include "mmi_cb_mgr_gprot.h"
#include "ConnectivityResDef.h"
#include "webcamProt.h"
#include "mmi_rp_app_usbmmi_def.h"
#include "ScrLockerGprot.h"
/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    MMI_WEBCAM_DISCONNECT,
    MMI_WEBCAM_CONNECTED,
    MMI_WEBCAM_LISTENING,
    MMI_WEBCAM_PAUSE_LISTENING,
    MMI_WEBCAM_RUNNING,
    MMI_WEBCAM_PAUSE
} MMI_USB_WEBCAM_STATE;

typedef struct
{
    U16  state;
    BOOL is_sub_display;
    BOOL is_clam_close;
    BOOL is_usb_webcam_done;
    MMI_ID gid;
} MMI_WEBCAM_CONTEXT;


#if defined(SENSOR_ROTATE_0)
#define MAIN_SENSOR_ROTATE  (MDI_WEBCAM_PREVIEW_ROTATE_0)
#elif defined(SENSOR_ROTATE_90)
#define MAIN_SENSOR_ROTATE  (MDI_WEBCAM_PREVIEW_ROTATE_90)
#elif defined(SENSOR_ROTATE_180)
#define MAIN_SENSOR_ROTATE  (MDI_WEBCAM_PREVIEW_ROTATE_180)
#elif defined(SENSOR_ROTATE_270)
#define MAIN_SENSOR_ROTATE  (MDI_WEBCAM_PREVIEW_ROTATE_270)
#else
#define MAIN_SENSOR_ROTATE  (MDI_WEBCAM_PREVIEW_ROTATE_0)
#endif

#ifdef HORIZONTAL_CAMERA
    #if defined(SENSOR_ON_BODY)
    #define WEBCAM_CLAM_OPEN_ROTATE     ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4)
    #define WEBCAM_CLAM_CLOSE_ROTATE    ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4)
    #elif defined(SENSOR_ON_COVER)
    #define WEBCAM_CLAM_OPEN_ROTATE     ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define WEBCAM_CLAM_CLOSE_ROTATE    ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_90)%4 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #elif defined(SENSOR_INSIDE_CLAM)
    #define WEBCAM_CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define WEBCAM_CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #else 
    #define WEBCAM_CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define WEBCAM_CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #endif
#else
    #if defined(SENSOR_ON_BODY)
    #define WEBCAM_CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define WEBCAM_CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #elif defined(SENSOR_ON_COVER)
    #define WEBCAM_CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define WEBCAM_CLAM_CLOSE_ROTATE    (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #elif defined(SENSOR_INSIDE_CLAM)
    #define WEBCAM_CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define WEBCAM_CLAM_CLOSE_ROTATE    (MAIN_SENSOR_ROTATE - MDI_WEBCAM_PREVIEW_ROTATE_180 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #else 
    #define WEBCAM_CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define WEBCAM_CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #endif
#endif

void mmi_webcam_entry_app_scr_init(void);
static void mmi_webcam_exit_app_scr(void);
static void mmi_webcam_event_hdlr(MDI_RESULT ret, BOOL camera_workable, void* user_data);
static U8 mmi_webcam_del_screen_id_hdlr(void *ptr);
static void mmi_webcam_rsk_release(void);
static void mmi_webcam_capture_key_press(void);
static void mmi_webcam_plug_out(void);
static void mmi_webcam_entry_app_scr(void);

#ifdef __MMI_SUBLCD__
static void mmi_webcam_entry_sublcd_scr(void);
static void mmi_webcam_exit_sublcd_scr(void);
#endif /* __MMI_SUBLCD__ */ 


mmi_ret mmi_webcam_gpio_event_hdlr(mmi_event_struct *evt);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_WEBCAM_CONTEXT g_mmi_webcam_cntx;
MMI_WEBCAM_CONTEXT *mmi_webcam_ptr = &g_mmi_webcam_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_init_context
 * DESCRIPTION
 *  This function is to initialize the mmi webcam context.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void mmi_webcam_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    mmi_webcam_ptr->is_sub_display = FALSE;
    mmi_webcam_ptr->is_clam_close = FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_enter
 * DESCRIPTION
 *  Enter webcam screen
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void mmi_webcam_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;
    mmi_webcam_entry_app_scr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_exit
 * DESCRIPTION
 *  Exit webcam screen
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void mmi_webcam_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_webcam_plug_out();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_usb_config_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_webcam_usb_config_rsp_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = *(U8*)evt->user_data;
    srv_usb_config_result_struct *result = (srv_usb_config_result_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == DEVUSB_CFG_ACTION_WEBCAM && result->suc == MMI_TRUE)
        mmi_webcam_ptr->is_usb_webcam_done = TRUE;
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_entry_app_scr
 * DESCRIPTION
 *  entry of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_webcam_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_frm_group_close(mmi_webcam_ptr->gid);
            break;

        case EVT_ID_POPUP_QUIT:
        {
            mmi_frm_scrn_close(mmi_webcam_ptr->gid, SCR_ID_USB_WEBCAM);
            mmi_frm_group_close(mmi_webcam_ptr->gid);

            break;
        }    
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_leave_scrn_proc
 * DESCRIPTION
 *  webcam leave proc function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_webcam_leave_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            mmi_webcam_del_screen_id_hdlr(NULL);
            break;
            
        default:
            return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;
}
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_notify_screen_lock_hdlr
 * DESCRIPTION
 *  webcam handle screen lock funxtion
 * PARAMETERS
 *  evt     [IN]        The event for lock screen
 * RETURNS
 *  mmi_ret event handle result
 *****************************************************************************/
mmi_ret mmi_webcam_notify_screen_lock_hdlr(mmi_event_struct * evt)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
			if(mmi_webcam_ptr->state != MMI_WEBCAM_DISCONNECT)
        	  return MMI_RET_ERR;
        	  break;
       default:
       	    return MMI_RET_OK;
    }
    return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_entry_app_scr
 * DESCRIPTION
 *  entry of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_webcam_entry_app_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_webcam_ptr->gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_webcam_proc, NULL)) == GRP_ID_INVALID)
        return;

    mmi_frm_group_enter(mmi_webcam_ptr->gid, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    
    mmi_webcam_entry_app_scr_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_entry_app_scr_init
 * DESCRIPTION
 *  entry of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_webcam_entry_app_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    U16 banding;
    MDI_RESULT ret;

    S32 pause_jpeg_count;
    S32 jpeg_file_len = 0;
    S32 jpeg_image_width, jpeg_image_height;
    S32 drv_image_width, drv_image_height;
    S32 i;
    PU8 jpeg_file_ptr = NULL;
    MMI_ID_TYPE str_id = 0;
    mmi_event_notify_enum err_type = MMI_EVENT_DEFAULT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(mmi_webcam_ptr->gid, SCR_ID_USB_WEBCAM, mmi_webcam_exit_app_scr, mmi_webcam_entry_app_scr_init, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        mmi_webcam_ptr->gid,
        SCR_ID_USB_WEBCAM,
        mmi_webcam_leave_scrn_proc);
    
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_ENTRY_APP_SCR);
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_STATE, mmi_webcam_ptr->state); 
    mmi_frm_start_scenario(MMI_SCENARIO_ID_USB_WEBCAM);
    
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* eanble keypad tone, since this might enter from idle when key pad is locked */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* disable partial screen saver */
    mmi_phnset_disable_partial_ss();

#ifdef __MMI_SUBLCD__
    if (!mmi_webcam_ptr->is_sub_display)
    {
        ForceSubLCDScreen(mmi_webcam_entry_sublcd_scr);
    }
#endif /* __MMI_SUBLCD__ */ 

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    /* avoid status bar */
    entry_full_screen();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop LED patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
    
#ifdef  __MMI_BACKGROUND_CALL__    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||       
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)    
        //mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) > 0)
    {
        /* draw bg */
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_image_get_dimension_id(IMG_ID_WEBCAM_BG_INCALL, &image_width, &image_height);

        gdi_image_draw_animation_id(
            (UI_device_width - image_width) >> 1,
            (UI_device_height - image_height) >> 1,
            IMG_ID_WEBCAM_BG_INCALL,
            NULL);

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        
        SetKeyHandler(mmi_webcam_rsk_release, KEY_RSK, KEY_EVENT_UP);

        srv_usb_set_status(SRV_USBSTATUS_WEBCAM);

        return;
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */
    {
    #ifdef HORIZONTAL_CAMERA
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(UI_device_height, UI_device_width);

        /* draw bg */
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_image_get_dimension_id(IMG_ID_WEBCAM_BG, &image_width, &image_height);
        gdi_image_draw_id(
            (UI_device_height - image_width) >> 1,
            (UI_device_width - image_height) >> 1,
            IMG_ID_WEBCAM_BG);

        gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
    #else /* HORIZONTAL_CAMERA */ 
        /* draw bg */
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_image_get_dimension_id(IMG_ID_WEBCAM_BG, &image_width, &image_height);
        gdi_image_draw_id(
            (UI_device_width - image_width) >> 1,
            (UI_device_height - image_height) >> 1,
            IMG_ID_WEBCAM_BG);

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    #endif /* HORIZONTAL_CAMERA */ 
    }
    SetKeyHandler(mmi_webcam_rsk_release, KEY_RSK, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CAMERA))
    {
        SetKeyHandler(mmi_webcam_capture_key_press, KEY_CAMERA, KEY_EVENT_DOWN);
    }
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetKeyHandler(mmi_webcam_capture_key_press, KEY_CSK, KEY_EVENT_DOWN);
    }
    
    if (mmi_webcam_ptr->state == MMI_WEBCAM_CONNECTED)
    {
        if (mdi_webcam_set_camera_id(MDI_WEBCAM_MAIN) != MDI_RES_WEBCAM_SUCCEED)
        {
            MMI_ASSERT(0);
        }
    
        /* set pause jpeg file size limit */
        pause_jpeg_count = mdi_webcam_get_pause_jpeg_count();

        for (i = 0; i < pause_jpeg_count; i++)
        {
            switch (i)
            {
                case 0:
                    jpeg_file_len = sizeof(webcam_pause_img_0);
                    gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG,(PU8) webcam_pause_img_0, jpeg_file_len, &jpeg_image_width, &jpeg_image_height);
                    jpeg_file_ptr = (PU8)webcam_pause_img_0;
                    break;

                case 1:
                    jpeg_file_len = sizeof(webcam_pause_img_1);
                    gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, (PU8) webcam_pause_img_1, jpeg_file_len, &jpeg_image_width, &jpeg_image_height);               
                    jpeg_file_ptr = (PU8)webcam_pause_img_1;
                    break;

                case 2:
                    jpeg_file_len = sizeof(webcam_pause_img_2);
                    gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, (PU8) webcam_pause_img_2, jpeg_file_len, &jpeg_image_width, &jpeg_image_height);
                    jpeg_file_ptr = (PU8)webcam_pause_img_2;
                    break;

                default:
                    MMI_ASSERT(0);
                    break;
            }
            mdi_webcam_get_pause_jpeg_info(i, &drv_image_width, &drv_image_height);
            mdi_webcam_set_pause_jpeg_file(i, (PU8) jpeg_file_ptr, jpeg_file_len, jpeg_image_width, jpeg_image_height);
        }        
        /* set mmi usb state and notify driver to set state */

        srv_usb_set_status(SRV_USBSTATUS_WEBCAM);
        if (!mmi_webcam_ptr->is_usb_webcam_done)
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_WEBCAM);
        
        banding = mmi_camera_get_camera_banding();
        
        /* start webcam */
        if (srv_clam_is_close())
        {
            ret = mdi_webcam_start(0, WEBCAM_CLAM_CLOSE_ROTATE, banding, mmi_webcam_event_hdlr, NULL);
        }
        else
        {
            ret = mdi_webcam_start(0, WEBCAM_CLAM_OPEN_ROTATE, banding, mmi_webcam_event_hdlr, NULL);
        }

        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cant start correctly */
            mdi_webcam_stop();
            mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            mmi_popup_display_simple((WCHAR*)GetString(str_id), err_type, mmi_webcam_ptr->gid, NULL);
        }
        else
        {
            mmi_webcam_ptr->state = MMI_WEBCAM_LISTENING;
        }

    }
    else if (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE_LISTENING)
    {
        ret = mdi_webcam_resume_connect();
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;            

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            mmi_popup_display_simple((WCHAR*)GetString(str_id), err_type, mmi_webcam_ptr->gid, NULL);
        }
        else
            mmi_webcam_ptr->state = MMI_WEBCAM_LISTENING;
    }
    else if (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE)
    {
        /* resume webcam */
        if (srv_clam_is_close())
        {
            ret = mdi_webcam_resume(WEBCAM_CLAM_CLOSE_ROTATE);
        }
        else
        {
            ret = mdi_webcam_resume(WEBCAM_CLAM_OPEN_ROTATE);
        }
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            mmi_popup_display_simple((WCHAR*)GetString(str_id), err_type, mmi_webcam_ptr->gid, NULL);
        }
        else
        {
            mmi_webcam_ptr->state = MMI_WEBCAM_RUNNING;
        }
    }
    else if (mmi_webcam_ptr->state == MMI_WEBCAM_DISCONNECT)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_USB_NOTIFY_WEBCAM_ERROR), 
            MMI_EVENT_FAILURE, 
            mmi_webcam_ptr->gid, 
            NULL);
    }
    else
    {
        MMI_ASSERT(0);  /* shall not enter here */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_exit_app_scr
 * DESCRIPTION
 *  exit of webcam screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_webcam_exit_app_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_EXIT_APP_SCR);
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_STATE, mmi_webcam_ptr->state);   
    mmi_frm_end_scenario(MMI_SCENARIO_ID_USB_WEBCAM);
#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_resize(UI_device_width, UI_device_height);
    gdi_layer_clear(GDI_COLOR_WHITE);
#endif /* HORIZONTAL_CAMERA */ 

    /* restore partial screen saver */
    mmi_phnset_enable_partial_ss();

    /* stop bg drawing */
    gdi_image_stop_animation_all();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* resume LCD patten */
    srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWRON, SRV_GPIO_PATN_PLAY_STOP);

    if (mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING ||
        mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING)
    {
        /* pause webcam */
        if (mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING)
            ret = mdi_webcam_pause();
        else
            ret = mdi_webcam_pause_connect();
        
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cannot start correctly */
            mdi_webcam_stop(); 
            mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;
        }
        else
        {
            if (mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING)
                mmi_webcam_ptr->state = MMI_WEBCAM_PAUSE;
            else
                mmi_webcam_ptr->state = MMI_WEBCAM_PAUSE_LISTENING;
        }
    }

#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (mmi_webcam_ptr->is_sub_display)
    {
        if (!srv_clam_is_close())
        {
            GoBackSubLCDHistory();
        }
        mmi_webcam_ptr->is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

    /* clear all key handler - restore to default key handling for end key */
    ClearInputEventHandler(MMI_DEVICE_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_is_active
 * DESCRIPTION
 *  is webcam active or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_usb_webcam_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_webcam_ptr->state == MMI_WEBCAM_DISCONNECT ||
        mmi_webcam_ptr->state == MMI_WEBCAM_CONNECTED)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_event_hdlr
 * DESCRIPTION
 *  callback function when webcam screen start has some problem
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_webcam_event_hdlr(MDI_RESULT ret, BOOL camera_workable, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_EVENT_HDLR, ret);    
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, MMI_TRC_WEBCAM_STATE, mmi_webcam_ptr->state); 

    switch (ret)
    {
        case MDI_RES_WEBCAM_SUCCEED:
            /* start successful */
            if(mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING)
            {
                mmi_webcam_ptr->state = MMI_WEBCAM_RUNNING;
            }
            break;

        case MDI_RES_WEBCAM_CONFIG_FAILED:
            if(mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING)
            {
                mdi_webcam_stop();
                mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
                mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
                    MMI_EVENT_FAILURE, 
                    mmi_webcam_ptr->gid, 
                    NULL);
            }
            break;            
        case MDI_RES_WEBCAM_ERR_FAILED:
            if(mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING)
            {
                mdi_webcam_stop();
                mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;

                if(!camera_workable)
                {
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(STR_ID_USB_NOTIFY_WEBCAM_CAM_ERROR), 
                        MMI_EVENT_FAILURE, 
                        mmi_webcam_ptr->gid, 
                        NULL);
                }
                else
                {
                    /* If camera is workable, the fail is due to cable plug out or com part error.   */ 
                    /* So, don't display pop up or it will have a conflict with "USB plug out popup" */
                    mmi_frm_scrn_close(mmi_webcam_ptr->gid, SCR_ID_USB_WEBCAM);
                    mmi_frm_group_close(mmi_webcam_ptr->gid);                    
                }
            }
            break;

        case MDI_RES_WEBCAM_DRV_ABORT:
            if (mmi_webcam_ptr->state != MMI_WEBCAM_DISCONNECT)
            {
                mdi_webcam_stop();
                mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;

                mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_ID_USB_WEBCAM_STOPPED), 
                    MMI_EVENT_FAILURE, 
                    mmi_webcam_ptr->gid, 
                    NULL);
            }
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_del_screen_id_hdlr
 * DESCRIPTION
 *  callback function when webcam screen removed from history webcam screen
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_webcam_del_screen_id_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit by other screens */
    if ((mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE_LISTENING))
    {
        /* close webcam */
        mdi_webcam_stop();
        mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    }
    else if (mmi_webcam_ptr->state == MMI_WEBCAM_CONNECTED)
    {
        mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    }
    mmi_webcam_ptr->is_usb_webcam_done = FALSE;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_gpio_event_hdlr
 * DESCRIPTION
 *  clam handler
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_webcam_gpio_event_hdlr(mmi_event_struct *evt)
{
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    MMI_ID_TYPE str_id = 0;
    mmi_event_notify_enum err_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GPIO_CLAM_CLOSE)
    {
        mmi_webcam_ptr->is_clam_close = TRUE;
        ret = mdi_webcam_rotate(WEBCAM_CLAM_CLOSE_ROTATE);        
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            /* USB is connected, but camera part cant start correctly */
            if (mmi_webcam_ptr->state != MMI_WEBCAM_DISCONNECT)
                mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);

            mmi_popup_display_simple(
                (WCHAR*)GetString(str_id), 
                err_type, 
                mmi_webcam_ptr->gid, 
                NULL);

            return FALSE;
        }
        srv_clam_set_state(EXT_DEV_CLAM_CLOSE);
        srv_gpio_detect_send_ack(EXT_DEV_CLAM_CLOSE);            
        /* return TRUE means will block this interrut from passing default handler */
        return TRUE;
    }
    else if (evt->evt_id == EVT_ID_GPIO_CLAM_OPEN)
    {
        mmi_webcam_ptr->is_clam_close = FALSE;
        ret = mdi_webcam_rotate(WEBCAM_CLAM_OPEN_ROTATE);
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            /* USB is connected, but camera part cant start correctly */
            if (mmi_webcam_ptr->state != MMI_WEBCAM_DISCONNECT)
                mmi_webcam_ptr->state = MMI_WEBCAM_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            mmi_popup_display_simple(
                (WCHAR*)GetString(str_id), 
                err_type, 
                mmi_webcam_ptr->gid, 
                NULL);

            return FALSE;
        }
        srv_clam_set_state(EXT_DEV_CLAM_OPEN);
        srv_gpio_detect_send_ack(EXT_DEV_CLAM_OPEN);
        /* return TRUE means will block this interrut from passing default handler */
        return TRUE;
    }

    return FALSE;
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_rsk_release
 * DESCRIPTION
 *  rsk release handler, will stop webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_webcam_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE_LISTENING))
    {
        /* close webcam */
        mdi_webcam_stop();
        mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    }
#ifdef  __MMI_BACKGROUND_CALL__ 
    else if (mmi_webcam_ptr->state == MMI_WEBCAM_CONNECTED)
    {
        mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    }
#endif
    else
    {
        MMI_ASSERT(0);
    }

    mmi_frm_scrn_close(mmi_webcam_ptr->gid, SCR_ID_USB_WEBCAM);
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_capture_key_press
 * DESCRIPTION
 *  capture key is pressed, will capture an image to PC side
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_webcam_capture_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING)
    {
        mdi_webcam_capture();

        /* flush all key event */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_plug_out
 * DESCRIPTION
 *  webcam calbe plug out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_webcam_plug_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop webcam if it is running */
    if ((mmi_webcam_ptr->state == MMI_WEBCAM_RUNNING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_LISTENING) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_CONNECTED) || 
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE) ||
        (mmi_webcam_ptr->state == MMI_WEBCAM_PAUSE_LISTENING))
    {
        /* stop webcam */
        mdi_webcam_stop();
        mmi_webcam_ptr->state = MMI_WEBCAM_DISCONNECT;
    }

    mmi_frm_scrn_close(mmi_webcam_ptr->gid, SCR_ID_USB_WEBCAM);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_entry_sublcd_scr
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_SUBLCD__)
static void mmi_webcam_entry_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width;
    S32 lcd_height;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_webcam_exit_sublcd_scr);

    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_BLACK);

    gdi_image_get_dimension_id(IMG_ID_WEBCAM_SUB_BG, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_WEBCAM_SUB_BG);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    mmi_webcam_ptr->is_sub_display = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_webcam_exit_sublcd_scr
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_webcam_exit_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    SubLCDHistory.entryFuncPtr = mmi_webcam_entry_sublcd_scr;
    AddSubLCDHistory(&SubLCDHistory);

    mmi_webcam_ptr->is_sub_display = FALSE;
}
#endif /* defined(__MMI_SUBLCD__) */ 
#else
mmi_ret mmi_webcam_gpio_event_hdlr(mmi_event_struct *evt)
{
    return 0;
}


#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
mmi_ret mmi_webcam_notify_screen_lock_hdlr(mmi_event_struct * evt)
{
	return 0;
}
#endif
mmi_ret mmi_webcam_usb_config_rsp_callback(mmi_event_struct *evt)
{
    return 0;
}
#endif /* __MMI_WEBCAM__ */ 
