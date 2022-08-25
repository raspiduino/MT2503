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
 *   webcam_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of webcam module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"

/* global includes */

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_context.h"

#ifdef __WEBCAM_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_WEBCAM_MOD__
#include "webcam_main.h"
#include "dcl.h"
#include "cal_comm_def.h"
#include "cal_api.h"
#include "mm_comm_def.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

static kal_int32 webcam_result;

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  webcam_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WEBCAM_RESULT_TRACE(result, webcam_context_p->state, webcam_context_p->seq_num) webcam_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_set_default_jpeg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  max_size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_webcam_set_default_jpeg_size(kal_uint8 index, kal_uint32 max_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCL_HANDLE usb_hdlr;
    USB_VIDEO_CTRL_FUNC1_T usb_data;
    
    usb_data.uindex = index;
    usb_data.u4max_size = max_size; 
    
    usb_hdlr = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
    DclUSB_DRV_Control(usb_hdlr,USB_Video_CMD_Set_Default_JPEG_Max_Size,(DCL_CTRL_DATA_T *)&usb_data);
    DclUSB_DRV_Close(usb_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_set_cam_id
 * DESCRIPTION
 *  This function is to set camera id.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  cam_id          [IN]        
 * RETURNS
 *  result          [OUT]
 *****************************************************************************/
kal_int32 media_webcam_set_cam_id(module_type src_mod_id, void *cam_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_set_camera_id_req(src_mod_id, cam_id);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_SET_CAMID);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  start           [?]         
 * RETURNS
 *  
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWWEBCAM_ROCODE", rodata = "DYNAMIC_CODE_MWWEBCAM_RODATA"
kal_int32 media_webcam_start(module_type src_mod_id, void *start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_start_req(src_mod_id, start);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_START);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_webcam_stop(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_send_stop_req(src_mod_id);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  pause           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_pause(module_type src_mod_id, void *pause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_pause_req(src_mod_id, pause);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_PAUSE);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  resume          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_resume(module_type src_mod_id, void *resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_resume_req(src_mod_id, resume);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_RESUME);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_capture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_capture(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_capture_req(src_mod_id);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_CAPTURE);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  rotate          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_rotate(module_type src_mod_id, void *rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_rotate_req(src_mod_id, rotate);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_ROTATE);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_pause_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  pause           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_pause_connect(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_pause_connect_req(src_mod_id);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_CONNECT);
    return webcam_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_resume_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  resume          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_webcam_resume_connect(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_result = MED_RES_OK;
    webcam_send_resume_connect_req(src_mod_id);
    WEBCAM_WAIT_EVENT(WEBCAM_EVT_CONNECT);
    return webcam_result;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  media_webcam_get_resolution_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 media_webcam_get_resolution_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM result;
    
    CAL_FEATURE_CTRL_STRUCT FeatureCtrlStruct;
    CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT WebcamVideoSize;

    FeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    FeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE;
    FeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamVideoSize = &WebcamVideoSize;
    result = CalCtrl(CAL_FEATURE_CTRL, &FeatureCtrlStruct, NULL, 0, NULL);
    ASSERT(result == MM_ERROR_NONE);
    
    return WebcamVideoSize.WebCamVideoSizeInfoNum;
}


/*****************************************************************************
 * FUNCTION
 *  media_webcam_get_resolution_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  pwidth      [?]         
 *  pheight     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_webcam_get_resolution_dimension(kal_uint8 index, kal_uint16 *pwidth, kal_uint16 *pheight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM result;
    
    CAL_FEATURE_CTRL_STRUCT FeatureCtrlStruct;
    CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT WebcamVideoSize;

    FeatureCtrlStruct.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
    FeatureCtrlStruct.FeatureId = CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE;
    FeatureCtrlStruct.FeatureInfo.FeatureStructured.pWebCamVideoSize = &WebcamVideoSize;
    result = CalCtrl(CAL_FEATURE_CTRL, &FeatureCtrlStruct, NULL, 0, NULL);
    ASSERT(result == MM_ERROR_NONE);

    EXT_ASSERT(index < WebcamVideoSize.WebCamVideoSizeInfoNum, index, WebcamVideoSize.WebCamVideoSizeInfoNum, 0);
    *pwidth = WebcamVideoSize.pWebCamVideoSizeInfo[index].width;
    *pheight = WebcamVideoSize.pWebCamVideoSizeInfo[index].height;
    
}

#endif /* __MED_WEBCAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

