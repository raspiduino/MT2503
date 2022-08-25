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
 *  mdi_webcam.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Webcam sensor related interface
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
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_WEBCAM__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdC.h"       /* standard inc */
#include "mmi_platform.h"
#include "mmi_frm_gprot.h"

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_webcam.h"
#include "GlobalDefs.h"
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "mmi_rp_srv_mdi_def.h"
#include "GlobalResDef.h"
#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_WEBCAM_JPG_COUNT     (5)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    void* user_data;
    S32 start_seq_num;
    BOOL is_pause_jpeg_size_set;
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    webcam_default_jpeg_file_info jpg_file_info[MDI_WEBCAM_JPG_COUNT];
#endif 
} mdi_webcam_cntx_struct;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_webcam_cntx_struct g_mdi_webcam_cntx;
void (*mdi_webcam_event_callback_funcptr) (MDI_RESULT, BOOL, void*) = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mdi_webcam_start_result_hdlr(void *msg_ptr);
static void mdi_webcam_abort_indication_hdlr(void *msg_ptr);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_init
 * DESCRIPTION
 *  Webcam initializtion
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED  Success
 *****************************************************************************/
MDI_RESULT mdi_webcam_init(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MDI_WEBCAM_JPG_COUNT; i++)
    {
        g_mdi_webcam_cntx.jpg_file_info[i].start_addr = NULL;
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    g_mdi_webcam_cntx.start_seq_num = 0;
    g_mdi_webcam_cntx.is_pause_jpeg_size_set = FALSE;

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_set_pause_jpeg_file
 * DESCRIPTION
 *  Set jpeg files which will be used when webcam pauses.
 * PARAMETERS
 *  idx                 [IN]        Index
 *  jpeg_file_ptr       [IN]        JPEG file data pointer
 *  file_length         [IN]        File length
 *  width               [IN]        Image width
 *  height              [IN]        Image height
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      success
 *****************************************************************************/
MDI_RESULT mdi_webcam_set_pause_jpeg_file(U16 idx, PU8 jpeg_file_ptr, U32 file_length, S32 width, S32 height)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_webcam_cntx.is_pause_jpeg_size_set = TRUE;

    ASSERT(MDI_WEBCAM_JPG_COUNT > idx); /* id exceed entry slot */

    g_mdi_webcam_cntx.jpg_file_info[idx].start_addr = jpeg_file_ptr;
    g_mdi_webcam_cntx.jpg_file_info[idx].size = file_length;
    g_mdi_webcam_cntx.jpg_file_info[idx].width = width;
    g_mdi_webcam_cntx.jpg_file_info[idx].height = height;

    media_webcam_set_default_jpeg_size(idx, file_length);
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor
 * PARAMETERS
 *  camera_id       [IN]    Camera id [main or sub]
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_set_camera_id(U16 camera_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_set_camera_id_req_struct cam_id_data;
    kal_int32 ret = 0;
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
    #endif /* __MM_DCM_SUPPORT__ */
    
    cam_id_data.cam_id = camera_id;
    ret = media_webcam_set_cam_id(stack_get_active_module_id(), (void*)&cam_id_data);

    #ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }
    #endif

    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
    
}

#pragma arm section code = "DYNAMIC_CODE_MWWEBCAM_ROCODE", rodata = "DYNAMIC_CODE_MWWEBCAM_RODATA"
static MDI_RESULT mdi_webcam_start_internal(U16 app_id, U16 rotate, U16 banding, mdi_webcam_event_callback event_callback, void* user_data)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_req_struct start_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_START);  

    /* check if size is set or not */
    MMI_ASSERT(g_mdi_webcam_cntx.is_pause_jpeg_size_set);
    MMI_ASSERT(event_callback != NULL);

    SetProtocolEventHandler(mdi_webcam_start_result_hdlr, MSG_ID_MEDIA_WEBCAM_START_CNF);
    SetProtocolEventHandler(mdi_webcam_abort_indication_hdlr, MSG_ID_MEDIA_WEBCAM_ABORT_IND);

    start_data.banding = banding;
    start_data.rotate = rotate + CAM_IMAGE_NORMAL;
    start_data.seq_num = g_mdi_webcam_cntx.start_seq_num;
    start_data.app_id = app_id;

    g_mdi_webcam_cntx.user_data = user_data;
    
    mdi_webcam_event_callback_funcptr = event_callback;

    #ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    #endif

    ret = media_webcam_start(MOD_MMI, &start_data);
    if (ret != MED_RES_OK)
    {
        #ifdef __MM_DCM_SUPPORT__
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
        #endif

        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#else 
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


static MDI_RESULT mdi_webcam_stop_internal(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_STOP); 

    g_mdi_webcam_cntx.start_seq_num++;
    media_webcam_stop(MOD_MMI);

    #ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    #endif
        
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_start
 * DESCRIPTION
 *  Start webcam
 * PARAMETERS
 *  rotate              [IN]        Preview rotate
 *  banding             [IN]        Banding
 *  event_callback      [IN]        Webcam event callback
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_start(U16 app_id, U16 rotate, U16 banding, mdi_webcam_event_callback event_callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_MWWEBCAM, NULL, NULL);
#endif

    result = mdi_webcam_start_internal(app_id, rotate, banding, event_callback, user_data);

#ifdef __MM_DCM_SUPPORT__
    if (result != MDI_RES_WEBCAM_SUCCEED)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_MWWEBCAM);
    }
#endif

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_stop
 * DESCRIPTION
 *  Stop webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *****************************************************************************/
MDI_RESULT mdi_webcam_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_webcam_stop_internal();

#ifdef __MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MWWEBCAM);
#endif

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_pause
 * DESCRIPTION
 *  Pause webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWWEBCAM_ROCODE", rodata = "DYNAMIC_CODE_MWWEBCAM_RODATA"
MDI_RESULT mdi_webcam_pause(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct data;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_PAUSE);  

    data.no_of_jpeg_files = 0;
    for (i = 0; i < MDI_WEBCAM_JPG_COUNT; i++)
    {
        if (g_mdi_webcam_cntx.jpg_file_info[i].start_addr != NULL)
        {
            data.no_of_jpeg_files++;
        }
    }

    data.file_info = (webcam_default_jpeg_file_info*) g_mdi_webcam_cntx.jpg_file_info;

    ret = media_webcam_pause(MOD_MMI, (void*)&data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_resume
 * DESCRIPTION
 *  Resume webcam
 * PARAMETERS
 *  rotate      [IN]    Preview rotate
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_resume(U16 rotate)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_resume_req_struct resume_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_RESUME); 

    resume_data.rotate = rotate + CAM_IMAGE_NORMAL;
    ret = media_webcam_resume(MOD_MMI, &resume_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }    
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_rotate
 * DESCRIPTION
 *  Rotate webcam preview
 * PARAMETERS
 *  rotate      [IN]    Preview rotate
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_rotate(U16 rotate)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_rotate_req_struct rotate_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rotate_data.rotate = rotate + CAM_IMAGE_NORMAL;
    ret = media_webcam_rotate(MOD_MMI, &rotate_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }    
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_capture
 * DESCRIPTION
 *  Notify PC to capture the image
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    ret = media_webcam_capture(MOD_MMI);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_pause_connect
 * DESCRIPTION
 *  Pause webcam connect
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_pause_connect(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_PAUSE_CONNECT);  

    ret = media_webcam_pause_connect(MOD_MMI);
    
    if (ret != MED_RES_OK)
        return MDI_RES_WEBCAM_ERR_FAILED;
    else
        return MDI_RES_WEBCAM_SUCCEED;
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_resume_connect
 * DESCRIPTION
 *  Resume webcam connect
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_webcam_resume_connect(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct data;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_RESUME_CONNECT);  

    ret = media_webcam_resume_connect(MOD_MMI);
    
    if (ret != MED_RES_OK)
        return MDI_RES_WEBCAM_ERR_FAILED;
    else
        return MDI_RES_WEBCAM_SUCCEED;
#else
    return MDI_RES_WEBCAM_SUCCEED;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_pause_jpeg_count
 * DESCRIPTION
 *  Get pause jpeg file count
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of USBVideoClass support resolutions
 *****************************************************************************/
U16 mdi_webcam_get_pause_jpeg_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    #endif
    U16    returnValue = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    #ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
    #endif /* __MM_DCM_SUPPORT__ */

    returnValue =(U16) media_webcam_get_resolution_num();

    #ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }
    #endif

    return returnValue;
#else 
    return returnValue;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_pause_jpeg_info
 * DESCRIPTION
 *  Get pause jpeg file count
 * PARAMETERS
 *  idx                 [IN]        Index
 *  image_width         [OUT]       Image width
 *  image_height        [OUT]       Image height
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *****************************************************************************/
MDI_RESULT mdi_webcam_get_pause_jpeg_info(U16 idx, S32 *image_width, S32 *image_height)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 drv_img_width;
    U16 drv_img_height;
    #ifdef __MM_DCM_SUPPORT__
    kal_bool is_loaded = KAL_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MM_DCM_SUPPORT__
    is_loaded = DCM_Isloaded(DYNAMIC_CODE_COMPRESS_CAMCAL);
    if (!is_loaded)
    {
        DCM_Load(DYNAMIC_CODE_COMPRESS_CAMCAL, NULL, NULL);
    }
    #endif /* __MM_DCM_SUPPORT__ */
    
    media_webcam_get_resolution_dimension(idx, (U16*) & drv_img_width, (U16*) & drv_img_height);

    #ifdef __MM_DCM_SUPPORT__
    if (!is_loaded)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_CAMCAL);
    }
    #endif
    
    *image_width = drv_img_width;
    *image_height = drv_img_height;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_start_result_hdlr
 * DESCRIPTION
 *  Webcam start result handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWWEBCAM_ROCODE", rodata = "DYNAMIC_CODE_MWWEBCAM_RODATA"
static void mdi_webcam_start_result_hdlr(void *msg_ptr)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_cnf_struct *start_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_START_RESULT_HALR); 

    start_data_ptr = (media_webcam_start_cnf_struct*) msg_ptr;

    if (start_data_ptr->seq_num != g_mdi_webcam_cntx.start_seq_num)
    {
        /* cant match, means already stopped */
        return;
    }

    if (mdi_webcam_event_callback_funcptr != NULL)
    {
        if (start_data_ptr->result == MED_RES_OK)
        {
            mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_SUCCEED, start_data_ptr->camera_workable, g_mdi_webcam_cntx.user_data);
        }
        else if (start_data_ptr->result == MED_RES_ERROR)
        {
            mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_CONFIG_FAILED, start_data_ptr->camera_workable, g_mdi_webcam_cntx.user_data);
        }
        else
        {
            mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_ERR_FAILED, start_data_ptr->camera_workable, g_mdi_webcam_cntx.user_data);
        }
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_abort_indication_hdlr
 * DESCRIPTION
 *  webcam abort indication from driver
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_webcam_abort_indication_hdlr(void *msg_ptr)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_abort_ind_struct *abort_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_WEBCAM_ABORT_IND_HALR); 

    abort_data_ptr = (media_webcam_abort_ind_struct*) msg_ptr;

    if (abort_data_ptr->seq_num != g_mdi_webcam_cntx.start_seq_num)
    {
        /* cant match, means already stopped */
        return;
    }

    if (mdi_webcam_event_callback_funcptr != NULL)
    {
        mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_DRV_ABORT, KAL_TRUE, g_mdi_webcam_cntx.user_data);
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   [IN]     Error code got from MDI APIs
 *  popup_type   [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
MMI_ID_TYPE mdi_webcam_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
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
        case MDI_RES_WEBCAM_ERR_FAILED:
            string_id = STR_ID_MDI_WEBCAM_USB_NOTIFY_ERROR;
            break;
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}
#endif /* __MMI_WEBCAM__ */ 

