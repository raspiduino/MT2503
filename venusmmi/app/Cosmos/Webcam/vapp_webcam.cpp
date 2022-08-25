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
 *  vapp_webcam.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_WEBCAM__
#include "vapp_webcam.h"
#include "../xml/vfx_xml_loader.h"
#include "mmi_rp_vapp_webcam_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#if defined(__LOW_COST_SUPPORT_COMMON__)
#include "vapp_camco_express_gprot.h"
#else
#include "vapp_camco_gprot.h"
#endif  
#include "vapp_screen_lock_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "gdi_include.h"
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "mdi_webcam.h"
#include "mdi_camera.h"
#include "mdi_include.h"
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
#include "CustWebcamImgData.h"
#pragma arm section code, rodata
#include "UcmsrvGprot.h"
#include "gpiosrvgprot.h"

#include "USBsrvGprot.h"

#include "GlobalResDef.h"
#include "GpioSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "KeyBrd.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
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
    #define CLAM_OPEN_ROTATE     ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4)
    #define CLAM_CLOSE_ROTATE    ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4)
    #elif defined(SENSOR_ON_COVER)
    #define CLAM_OPEN_ROTATE     ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_270)%4 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define CLAM_CLOSE_ROTATE    ((MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_90)%4 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #elif defined(SENSOR_INSIDE_CLAM)
    #define CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #else 
    #define CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #endif
#else
    #if defined(SENSOR_ON_BODY)
    #define CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #elif defined(SENSOR_ON_COVER)
    #define CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define CLAM_CLOSE_ROTATE    (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #elif defined(SENSOR_INSIDE_CLAM)
    #define CLAM_OPEN_ROTATE     (MAIN_SENSOR_ROTATE + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #define CLAM_CLOSE_ROTATE    (MAIN_SENSOR_ROTATE - MDI_WEBCAM_PREVIEW_ROTATE_180 + MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR)
    #else 
    #define CLAM_OPEN_ROTATE     MAIN_SENSOR_ROTATE
    #define CLAM_CLOSE_ROTATE    MAIN_SENSOR_ROTATE
    #endif
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    void* webcamScr;
    void* webcamApp;
    mmi_id appInstanceID;
    VfxBool is_plugout;
    VfxBool is_usb_webcam_done;
}webcamContextStruct;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxU8 VappWebcamScreen::m_state = VappWebcamScreen::STATE_DISCONNECT;
webcamContextStruct gWebcamContext;

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" void vapp_webcam_launch(void)
{   
    VfxAppLauncher::launch( 
        VAPP_WEBCAM,
        VFX_OBJ_CLASS_INFO(VappWebcamApp),
        GRP_ID_ROOT);

}

extern "C" void vapp_webcam_enter(void)
{
    gWebcamContext.is_plugout = VFX_FALSE;
    
    vapp_webcam_launch();
}


extern "C" void vapp_webcam_exit(void)
{   
    gWebcamContext.is_plugout = VFX_TRUE;
    VappWebcamApp::cablePlugOut();
}


extern "C" void mmi_webcam_init_context(void)
{

}


extern "C" void mmi_webcam_enter(void)
{
    vapp_webcam_enter();
}


extern "C" void mmi_webcam_exit(void)
{
    vapp_webcam_exit();
}


extern "C" mmi_ret vapp_webcam_usb_config_rsp_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU8 mode = *(VfxU8*)evt->user_data;
    srv_usb_config_result_struct *result = (srv_usb_config_result_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == DEVUSB_CFG_ACTION_WEBCAM && result->suc == MMI_TRUE)
        gWebcamContext.is_usb_webcam_done = VFX_TRUE;
    
    return MMI_RET_OK;
}


extern "C" MMI_BOOL mmi_usb_webcam_is_active(void)
{
    VappWebcamApp* app_ptr;

    app_ptr = (VappWebcamApp*)gWebcamContext.webcamApp;

    if (gWebcamContext.webcamApp && 
        app_ptr->isValid() && 
        app_ptr->isActive())
    {
        return MMI_TRUE;
    }
    else
        return MMI_FALSE;
}


VFX_IMPLEMENT_CLASS("VappWebcamApp", VappWebcamApp, VfxApp);

void VappWebcamApp::onDeinit()
{
    gWebcamContext.webcamApp = NULL;
    gWebcamContext.is_usb_webcam_done = VFX_FALSE;
    VfxApp::onDeinit();
}


void VappWebcamApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    gWebcamContext.appInstanceID = getGroupId();
    // create and display main screen 
    VFX_OBJ_CREATE(m_scr, VappWebcamScreen, this);
    m_scr->show();

    gWebcamContext.webcamApp = (void*)this;
}


void VappWebcamApp::cablePlugOut()
{
    VappWebcamApp* this_ptr = (VappWebcamApp*) gWebcamContext.webcamApp;

    if (gWebcamContext.webcamApp && this_ptr->isValid())
    {
        if (this_ptr->m_scr->isValid())
            this_ptr->m_scr->terminate();

        this_ptr->exit();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappWebcamScreen", VappWebcamScreen, VfxMainScr);

void VappWebcamScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappWebcamPage *page;
    VFX_OBJ_CREATE(page, VappWebcamPage, this);
    pushPage(0, page);

    if (m_state == STATE_DISCONNECT)
        m_state = STATE_CONNECTED;

    m_isInCall = VFX_FALSE;
    VFX_OBJ_CREATE(m_popup, VcpConfirmPopup, this);
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
}

void VappWebcamScreen::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);

#ifdef  __MMI_BACKGROUND_CALL__ 
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||       
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        m_isInCall = VFX_TRUE;
    }
    else
    {
        m_isInCall = VFX_FALSE;
    }
#endif
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, cbEventHandler, this);
	mmi_frm_cb_reg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, cbEventHandler, this);

    enterScr();
}


void VappWebcamScreen::onExit(VfxBool isBackward)
{   
    exitScr(isBackward);

    mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, cbEventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, cbEventHandler, this);
	
    srv_backlight_turn_off();

    if (m_popup->isValid())
        m_popup->hide(VFX_FALSE);
    
    VfxMainScr::onExit(isBackward);
}

void VappWebcamScreen::onDeinit()
{
    if ((m_state == STATE_RUNNING) ||
        (m_state == STATE_LISTENING) ||
        (m_state == STATE_PAUSE) ||
        (m_state == STATE_PAUSE_LISTENING))
    {
    #ifdef MDI_WEBCAM_DRIVER_AVAIALBE    
        /* close webcam */
        mdi_webcam_stop();
    #endif
        m_state = STATE_DISCONNECT;
    }
    else if (m_state == STATE_CONNECTED)
    {
        m_state = STATE_DISCONNECT;
    }    
    
    VfxMainScr::onDeinit();
}

void VappWebcamScreen::getPauseImages()
{
    S32 pause_jpeg_count;
    S32 jpeg_file_len = 0;
    S32 jpeg_image_width, jpeg_image_height;
    S32 drv_image_width, drv_image_height;
    S32 i;
    PU8 jpeg_file_ptr = NULL;

#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
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

    #ifdef MDI_WEBCAM_DRIVER_AVAIALBE
        mdi_webcam_get_pause_jpeg_info(i, &drv_image_width, &drv_image_height);
        mdi_webcam_set_pause_jpeg_file(i, (PU8) jpeg_file_ptr, jpeg_file_len, jpeg_image_width, jpeg_image_height);
    #endif    
    }        
#endif
    /* set mmi usb state and notify driver to set state */    
}


void VappWebcamScreen::enterScr()
{
    MDI_RESULT ret = 0;
    VfxU16 banding = 0;
    MMI_ID_TYPE str_id = 0;
    mmi_event_notify_enum err_type;

    gWebcamContext.webcamScr = this;

    if (m_isInCall)
    {
        srv_usb_set_status(SRV_USBSTATUS_WEBCAM);
        displayPopup(VCP_POPUP_TYPE_FAILURE, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
        return;
    }
    
    #ifdef MDI_WEBCAM_DRIVER_AVAIALBE            
    if (m_state == STATE_CONNECTED)
    {
        if (mdi_webcam_set_camera_id(MDI_WEBCAM_MAIN) != MDI_RES_WEBCAM_SUCCEED)
        {
            //MMI_ASSERT(0);
        	displayPopup(VCP_POPUP_TYPE_FAILURE, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
            return;
        }
    
        getPauseImages();

        srv_usb_set_status(SRV_USBSTATUS_WEBCAM);
        if (!gWebcamContext.is_usb_webcam_done)
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_WEBCAM);

        /* start webcam */
        banding = vapp_camco_setting_get_banding();
        
        if (srv_clam_is_close())
            ret = mdi_webcam_start(gWebcamContext.appInstanceID, CLAM_CLOSE_ROTATE, banding, eventHdlr, (void*)this);
        else
            ret = mdi_webcam_start(gWebcamContext.appInstanceID, CLAM_OPEN_ROTATE, banding, eventHdlr, (void*)this);

        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cant start correctly */
            mdi_webcam_stop();
            m_state = STATE_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            displayPopup(VCP_POPUP_TYPE_FAILURE, (VfxU32)str_id);
        }
        else
        {
            m_state = STATE_LISTENING;
        }
    }
    else if (m_state == STATE_PAUSE_LISTENING)
    {
        ret = mdi_webcam_resume_connect();
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            m_state = STATE_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            displayPopup(VCP_POPUP_TYPE_FAILURE, (VfxU32)str_id);            
        }
        else
            m_state = STATE_LISTENING;
        
    }
    else if (m_state == STATE_PAUSE)
    {
        /* resume webcam */
        if (srv_clam_is_close())
        {
            ret = mdi_webcam_resume(CLAM_CLOSE_ROTATE);
        }
        else
        {
            ret = mdi_webcam_resume(CLAM_OPEN_ROTATE);
        }
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            mdi_webcam_stop();
            m_state = STATE_CONNECTED;

            str_id = mdi_util_get_mdi_error_info(ret, &err_type);
            displayPopup(VCP_POPUP_TYPE_FAILURE, (VfxU32)str_id);
        }
        else
        {
            m_state = STATE_RUNNING;
        }
    }
    else if (m_state == STATE_DISCONNECT)
    {
        displayPopup(VCP_POPUP_TYPE_FAILURE, STR_ID_VAPP_WEBCAM_NOTIFY_ERROR);
    }
    else
    {
        VFX_ASSERT(0);  /* shall not enter here */
    }
    #endif /* MDI_WEBCAM_DRIVER_AVAIALBE */
    
}


void VappWebcamScreen::exitScr(VfxBool isBackward)
{
    MDI_RESULT ret;
    gWebcamContext.webcamScr = NULL;

    if (isBackward) // terminate app not interrupt, terminate in onDeinit()
        return;
    
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    if (m_state == STATE_RUNNING ||
        m_state == STATE_LISTENING)
    {
        /* pause webcam */
        if (m_state == STATE_RUNNING)
            ret = mdi_webcam_pause();
        else
            ret = mdi_webcam_pause_connect();
        
        if (ret == MDI_RES_WEBCAM_ERR_FAILED)
        {
            /* USB is connected, but camera part cannot start correctly */
            mdi_webcam_stop(); 
            m_state = STATE_CONNECTED;
        }
        else
        {
            if (m_state == STATE_RUNNING)
                m_state = STATE_PAUSE;
            else
                m_state = STATE_PAUSE_LISTENING;
        }
    }
#endif
    
}


void VappWebcamScreen::terminate()
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    if ((m_state == STATE_RUNNING) ||
        (m_state == STATE_LISTENING) ||
        (m_state == STATE_CONNECTED) || 
        (m_state == STATE_PAUSE))
    {
        /* stop webcam */
        mdi_webcam_stop();
        m_state = STATE_DISCONNECT;
    }    
#endif
    exit();
}


void VappWebcamScreen::eventHdlr(VfxS32 ret, BOOL camera_workable, void* user_data)
{
    if (gWebcamContext.webcamScr == NULL)
        return;
    
    VappWebcamScreen* this_ptr = (VappWebcamScreen*) gWebcamContext.webcamScr;
    
    switch (ret)
    {
        case MDI_RES_WEBCAM_SUCCEED:
            /* start successful */
            if(m_state == STATE_LISTENING)
            {
                m_state = STATE_RUNNING;
            }
            break;

        case MDI_RES_WEBCAM_CONFIG_FAILED:
            if(m_state == STATE_LISTENING)
            {
            #ifdef MDI_WEBCAM_DRIVER_AVAIALBE
                mdi_webcam_stop();
            #endif
                m_state = STATE_DISCONNECT;
                if (this_ptr->isValid())
                    this_ptr->displayPopup(VCP_POPUP_TYPE_FAILURE, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
            }
            break;
            
        case MDI_RES_WEBCAM_ERR_FAILED:
            if(m_state == STATE_LISTENING)
            {
            #ifdef MDI_WEBCAM_DRIVER_AVAIALBE
                mdi_webcam_stop();
            #endif
                m_state = STATE_DISCONNECT;

                if(!camera_workable)
                {
                    if (this_ptr->isValid())
                    {
                        this_ptr->displayPopup(VCP_POPUP_TYPE_FAILURE, STR_ID_VAPP_WEBCAM_NOTIFY_CAM_ERROR);
                        
                        if (gWebcamContext.is_plugout)
                        {
                            VfxTimer *timer;
                            VFX_OBJ_CREATE(timer, VfxTimer, this_ptr);
                            timer->setStartDelay(300);
                            timer->setDuration(0);
                            timer->m_signalTick.connect(this_ptr, &VappWebcamScreen::onTimerTick);
                            timer->start();
                        }
                    }
                }
                else
                {
                    /* If camera is workable, the fail is due to cable plug out or com port error.   */ 
                    /* So, don't display pop up or it will have a conflict with "USB plug out popup" */
                    if (this_ptr->isValid())
                        this_ptr->exit();
                }
            }
            break;

        case MDI_RES_WEBCAM_DRV_ABORT:
            if (m_state != STATE_DISCONNECT)
            {
            #ifdef MDI_WEBCAM_DRIVER_AVAIALBE
                mdi_webcam_stop();
            #endif
                m_state = STATE_DISCONNECT;
                if (this_ptr->isValid())
                    this_ptr->displayPopup(VCP_POPUP_TYPE_FAILURE, STR_ID_VAPP_WEBCAM_STOPPED);
            }
            break;

        default:
            /* shall not enter here */
            VFX_ASSERT(0);
            break;
    }    
}

void VappWebcamScreen::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
    //if (id != VCP_POPUP_BUTTON_NO_PRESSED)
        exit();
}


void VappWebcamScreen::displayPopup(VcpPopupTypeEnum type, VfxU32 stringID)
{
    m_popup->m_signalButtonClicked.connect(this, &VappWebcamScreen::onPopupButtonClicked);
    m_popup->setInfoType(type);
    m_popup->setText(VFX_WSTR_RES(stringID));
    m_popup->show(VFX_TRUE);
}
    

mmi_ret VappWebcamScreen::cbEventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    switch (evt->evt_id)
    {
		case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
			return !MMI_RET_OK;
			break;
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            return MMI_RET_OK;
            break;
        default:
            break;
    }    
    
    return MMI_RET_OK;
}

VfxBool VappWebcamScreen::onKeyInput(VfxKeyEvent &event)
{
    if ( event.type == VFX_KEY_EVENT_TYPE_DOWN && 
        (event.keyCode == VFX_KEY_CODE_CAMERA || 
         event.keyCode == VFX_KEY_CODE_CSK))
    {
        if (m_state == STATE_RUNNING)
            mdi_webcam_capture();
    }
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
    #endif /* __MTK_INTERNAL__ */

    VfxMainScr::onKeyInput(event);
}


void VappWebcamScreen::onTimerTick(VfxTimer *source)
{
    exit();
}
    
//////////////////////////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappWebcamPage", VappWebcamPage, VfxPage);
VappWebcamPage::VappWebcamPage() : m_image(NULL), m_bg(NULL), m_string(NULL)
{
}

void VappWebcamPage::onInit()
{
    VfxPage::onInit(); // call base class

    hideAllBars(VFX_TRUE);

    setBgColor(VFX_COLOR_WHITE);
    
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_string, VfxTextFrame, this);
    
    m_bg->setResId(IMG_COSMOS_GRID_BG);    
	
#ifndef LOW_COST_SUPPORT
    m_image->setResId(IMG_ID_WEBCAM_BG);
#endif
    
    m_string->setString(VFX_WSTR_RES(STR_ID_VAPP_USB_CONFIG_WEBCAM));
    m_string->setColor(VFX_COLOR_WHITE);
    m_string->setAutoResized(VFX_TRUE);
}

void VappWebcamPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
#ifdef HORIZONTAL_CAMERA
    //return VFX_SCR_ROTATE_TYPE_270;
    param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
#else
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;

    //return VFX_SCR_ROTATE_TYPE_0;
#endif
}

void VappWebcamPage::setBounds(const VfxRect &value)
{
    VfxPage::setBounds(value);

    if (m_bg)
    {
        m_bg->setBounds(value);
        m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }

#ifndef LOW_COST_SUPPORT
    if (m_image)
    {
        m_image->setAnchor(0.5f, 0.5f);
        m_image->setPos(getBounds().getMidX(), getBounds().getMidY());
        if (m_string)
        {
            m_string->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_string->setAnchor(0.5f, 0.5f);
            m_string->setPos(getBounds().getMidX(), m_image->getPos().y + m_image->getSize().height/2 + INTERVAL_IMAGE_AND_STRING);
        }
    }
#else
	if (m_string)
    {
        m_string->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_string->setAnchor(0.5f, 0.5f);
		m_string->setPos(getBounds().getMidX(), getBounds().getMidY());
    }
#endif

}
#else
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#ifdef __cplusplus
}
#endif

extern "C" mmi_ret vapp_webcam_usb_config_rsp_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}    
#endif /* __MMI_WEBCAM__ */
