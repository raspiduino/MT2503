/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   webcam_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of webcam module.
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "app_ltlcom.h" /* Task message communiction */

/* global includes */

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"

#include "cal_comm_def.h"
#include "cal_api.h"
#include "cal_mem_def.h"
#include "mm_comm_def.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#ifdef __WEBCAM_TRACE_ON__
#include "med_trc.h"
#endif 

#include "usbvideo_if.h"
#include "webcam_main.h"
#include "dcl.h"

#ifdef __MED_WEBCAM_MOD__
#define WEBCAM_FREE_USB_BUFFER()                                    \
do {                                                                \
    if (webcam_context_p->buffer_addr)                              \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->buffer_addr);   \
        webcam_context_p->buffer_addr = NULL;                       \
    }                                                               \
} while(0);


#define WEBCAM_FREE_JPG_YUV_BUFFER()                                \
do {                                                                \
    if (webcam_context_p->jpeg_y_buf_p)                             \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->jpeg_y_buf_p);  \
        webcam_context_p->jpeg_y_buf_p = NULL;                      \
    }                                                               \
    if (webcam_context_p->jpeg_u_buf_p)                             \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->jpeg_u_buf_p);  \
        webcam_context_p->jpeg_u_buf_p = NULL;                      \
    }                                                               \
    if (webcam_context_p->jpeg_v_buf_p)                             \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->jpeg_v_buf_p);  \
        webcam_context_p->jpeg_v_buf_p = NULL;                      \
    }                                                               \
} while(0);


#define WEBCAM_FREE_JPG_WORK_BUFFER()                                    \
do {                                                                \
    if (webcam_context_p->jpeg_work_addr)                              \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->jpeg_work_addr);   \
        webcam_context_p->jpeg_work_addr = NULL;                       \
    }                                                               \
} while(0);


#define WEBCAM_FREE_JPG_ROTATE_WORK_BUFFER()                                    \
do {                                                                \
    if (webcam_context_p->buffer_rotate_working_buf_p)                              \
    {                                                               \
        med_free_asm_mem(webcam_context_p->app_id, (void**)&webcam_context_p->buffer_rotate_working_buf_p);   \
        webcam_context_p->buffer_rotate_working_buf_p = NULL;                       \
    }                                                               \
} while(0);


CAL_CAMERA_WEBCAM_PROCESS_STRUCT MedWebcamProcessStruct;
CAL_SCENARIO_CTRL_STRUCT MedCalScenarioControlStruct;
CAL_FEATURE_CTRL_STRUCT MedCalFeatureControlStruct;

/*==== FUNCTIONS ===========*/


MM_ERROR_CODE_ENUM MedWebcamCallback(CAL_CALLBACK_ID_ENUM CbId, void *pCallbackPara, kal_uint16 CallbackParaLen) 
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
    P_CAL_WEBCAM_CB_STRUCT pWebcamCbStruct = (P_CAL_WEBCAM_CB_STRUCT)pCallbackPara;
    
    DCL_HANDLE usb_hdlr;
    usb_hdlr = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
                            
    switch(CbId)
    {
        case CAL_CBID_WEBCAM_GET_VIDEO_BUFF:
        {
            USB_VIDEO_CTRL_FUNC3_T usb_data;
            DclUSB_DRV_Control(usb_hdlr,USB_Video_CMD_Get_Video_Buffer,(DCL_CTRL_DATA_T *)&usb_data);
            pWebcamCbStruct->BuffAddr = (kal_uint32)usb_data.u2Retresult;
            
            break;
        }    
        case CAL_CBID_WEBCAM_GET_STILL_BUFF:
        {
            USB_VIDEO_CTRL_FUNC3_T usb_data;
            DclUSB_DRV_Control(usb_hdlr,USB_Video_CMD_Get_Still_Buffer,(DCL_CTRL_DATA_T *)&usb_data);
            pWebcamCbStruct->BuffAddr = (kal_uint32)usb_data.u2Retresult;                       

            break;   
        } 
        case CAL_CBID_WEBCAM_COMPLETE_VIDEO_BUFF:
        {
            USB_VIDEO_CTRL_FUNC2_T usb_data;
            usb_data.uaddr = (DCL_UINT8*)pWebcamCbStruct->BuffAddr;
            usb_data.u4size = (DCL_UINT32)pWebcamCbStruct->BuffSize;
            usb_data.u4time = (DCL_UINT32)pWebcamCbStruct->VideoTime;
            usb_data.u4size_type = (DCL_UINT8)pWebcamCbStruct->VideoType;           
            DclUSB_DRV_Control(usb_hdlr,USB_Video_CMD_Complete_Video_Buffer,(DCL_CTRL_DATA_T *)&usb_data);
            
            break;   
        }    
        case CAL_CBID_WEBCAM_COMPLETE_STILL_BUFF:
        {
            USB_VIDEO_CTRL_FUNC2_T usb_data;
            usb_data.uaddr = (DCL_UINT8*)(pWebcamCbStruct->BuffAddr);
            usb_data.u4size = (DCL_UINT32)pWebcamCbStruct->BuffSize;
            usb_data.u4time = (DCL_UINT32)pWebcamCbStruct->VideoTime;
            usb_data.u4size_type = (DCL_UINT8)pWebcamCbStruct->VideoType;           
            DclUSB_DRV_Control(usb_hdlr,USB_Video_CMD_Complete_Still_Buffer,(DCL_CTRL_DATA_T *)&usb_data);  

            break; 
         }  
    }
    
        DclUSB_DRV_Close(usb_hdlr);
        
    return ErrorCode;
}


/*****************************************************************************
 * FUNCTION
 *  webcam_set_camera_id_req_hdlr
 * DESCRIPTION
 *  This function is to select main/sub sensor.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_set_camera_id_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_set_camera_id_req_struct* req_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(WEBCAM_IN_STATE(WEBCAM_IDLE) || WEBCAM_IN_STATE(WEBCAM_PAUSED));
        
    req_p = (media_webcam_set_camera_id_req_struct*)ilm_ptr->local_para_ptr;

    // Select main or sub sensor
    MedCalFeatureControlStruct.FeatureId = CAL_FEATURE_CAMERA_SOURCE_SELECT;
    MedCalFeatureControlStruct.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    MedCalFeatureControlStruct.FeatureSetValue = (kal_uint32)req_p->cam_id;
    MedCalFeatureControlStruct.FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    camera_result = CalCtrl(CAL_FEATURE_CTRL, (void*)&MedCalFeatureControlStruct, NULL, 0, NULL);

    if (camera_result == MM_ERROR_NONE)
        webcam_set_result(MED_RES_OK);
    else
        webcam_set_result(MED_RES_FAIL);
    
    WEBCAM_SET_EVENT(WEBCAM_EVT_SET_CAMID);    
}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_req_hdlr
 * DESCRIPTION
 *  This function is to start webcam preview and transmit the image to USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWWEBCAM_ROCODE", rodata = "DYNAMIC_CODE_MWWEBCAM_RODATA"
void webcam_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_req_struct *req_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 
    USBVideo_Attr_Value     set_attr_value; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_start_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;
    webcam_context_p->seq_num = req_p->seq_num;
    webcam_context_p->app_id = req_p->app_id;

    if (WEBCAM_IN_STATE(WEBCAM_IDLE))
    {
        usbvideo_video_req_struct start;
        webcam_context_p->banding = req_p->banding;
        webcam_context_p->image_rotate = (MM_IMAGE_ROTATE_ENUM)req_p->rotate;
        webcam_context_p->buffer_size = CAL_WEBCAM_JPEG_BUFFER_SIZE;
        webcam_context_p->buffer_addr = (kal_uint8*) med_alloc_asm_mem_framebuffer(webcam_context_p->app_id, webcam_context_p->buffer_size);

        webcam_context_p->banding = req_p->banding;
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
#endif
        if (!webcam_context_p->buffer_addr)
        {
            /* insufficent memory */
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_SET_EVENT(WEBCAM_EVT_START);
            return;
        }

        // Bin: allocate WEBCAM external working memory
        // Bin added, temprory to use jpeg_work_addr for WEBCAM EXT working memory
        webcam_context_p->jpeg_work_size = CAL_WEBCAM_EXT_MEM_SIZE;
		
        webcam_context_p->jpeg_work_addr = (kal_uint8*) med_alloc_asm_mem_framebuffer(webcam_context_p->app_id, webcam_context_p->jpeg_work_size);
        MedWebcamProcessStruct.ExtmemStartAddress = (kal_uint32)(webcam_context_p->jpeg_work_addr); // non-cacheable for MDP
        
        webcam_context_p->jpeg_work_addr = (kal_uint8*)med_alloc_asm_mem_cacheable(webcam_context_p->app_id, webcam_context_p->jpeg_work_size);
        MedWebcamProcessStruct.ExtmemStartAddress2 = (kal_uint32)(webcam_context_p->jpeg_work_addr); // cacheable for JPEG
        
        MedWebcamProcessStruct.ExtmemSize = webcam_context_p->jpeg_work_size;

        if (!webcam_context_p->jpeg_work_addr)
        {
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_FREE_USB_BUFFER();
            WEBCAM_SET_EVENT(WEBCAM_EVT_START);
            return;
        }

        if (webcam_context_p->buffer_addr)
        {
            start.buffer_addr = webcam_context_p->buffer_addr;
            start.buffer_size = webcam_context_p->buffer_size;
            webcam_send_usb_start_video_req((void*)&start);
            WEBCAM_ENTER_STATE(WEBCAM_START_PREVIEW);
            webcam_set_result(MED_RES_OK);
            WEBCAM_SET_EVENT(WEBCAM_EVT_START);

        }
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_START);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video start confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    USBVideo_Attr_Value set_attr_value; // gellmann

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        if (msg_p->result == CONFIG_OK)
        {
        
            do{             
                camera_result = CalOpen(MedWebcamCallback);
                if(camera_result != MM_ERROR_NONE)
                {
                    break;
                }

                /// Bin: set banding through CAL feature ctrl // // gellmann
                set_attr_value.req_type = USBVIDEO_REQUEST_INIT;
                set_attr_value.type = USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY;
                set_attr_value.value = webcam_context_p->banding;
                set_attr_value.subtype = 0;
                MedCalFeatureControlStruct.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
                MedCalFeatureControlStruct.FeatureId = CAL_FEATURE_WEBCAM_SET_ATTR;
                MedCalFeatureControlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &(set_attr_value);
                camera_result = CalCtrl(CAL_FEATURE_CTRL, &MedCalFeatureControlStruct, NULL, 0, NULL);
                ASSERT(camera_result == MM_ERROR_NONE);
                
            
                MedWebcamProcessStruct.TargetSize = msg_p->video_size_type;
                MedWebcamProcessStruct.TargetCompression = msg_p->video_compression_type;
                MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;

                MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
                MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
                MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
                MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
                camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
                if(camera_result != MM_ERROR_NONE)
                {
                    CalClose();
                    break;
                }
                webcam_send_start_cnf(MED_RES_OK, KAL_TRUE);
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
            } while(0);
                
            if(camera_result != MM_ERROR_NONE)
            {
                webcam_send_start_cnf(MED_RES_FAIL, KAL_FALSE);                
                
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING);              
            }
        }
        else
        {
            if (msg_p->result == CONFIG_FAIL)
                webcam_send_start_cnf(MED_RES_FAIL, KAL_TRUE);
            else
                webcam_send_start_cnf(MED_RES_ERROR, KAL_TRUE);
            
            WEBCAM_FREE_USB_BUFFER();
            WEBCAM_FREE_JPG_WORK_BUFFER();
            WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop tv output.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        CalClose();

        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        CalClose();

        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PAUSED) ||
             WEBCAM_IN_STATE(WEBCAM_PAUSE_CONNECT))
    {
        webcam_send_usb_stop_video_req(NULL);
        WEBCAM_ENTER_STATE(WEBCAM_STOPPING);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_STOP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_stop_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the stop confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_stop_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_STOPPING))
    {
        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
        }
        else
        {
            ASSERT(msg_p->result);
        }
        WEBCAM_FREE_USB_BUFFER();
        WEBCAM_FREE_JPG_WORK_BUFFER();
       
        WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        WEBCAM_SET_EVENT(WEBCAM_EVT_STOP);

        webcam_context_p->app_id = 0;

    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_pause_req_hdlr
 * DESCRIPTION
 *  This function is to pause webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_pause_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        CalClose();

        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);

    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        CalClose();

        webcam_send_usb_pause_req(req_p);
        WEBCAM_ENTER_STATE(WEBCAM_PAUSING);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_PAUSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_pause_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the pause confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_pause_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PAUSING))
    {

        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
            WEBCAM_ENTER_STATE(WEBCAM_PAUSED);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            WEBCAM_ENTER_STATE(WEBCAM_IDLE);
        }
        WEBCAM_FREE_USB_BUFFER();
        WEBCAM_FREE_JPG_WORK_BUFFER();
        
        WEBCAM_SET_EVENT(WEBCAM_EVT_PAUSE);

    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_resume_req_hdlr
 * DESCRIPTION
 *  This function is to resume webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_resume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_resume_req_struct*) ilm_ptr->local_para_ptr;

    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_PAUSED))
    {
        usbvideo_video_req_struct start;

        webcam_context_p->image_rotate = (MM_IMAGE_ROTATE_ENUM)req_p->rotate;
        webcam_context_p->buffer_size = CAL_WEBCAM_JPEG_BUFFER_SIZE;
        webcam_context_p->buffer_addr = (kal_uint8*) med_alloc_asm_mem_framebuffer(webcam_context_p->app_id, webcam_context_p->buffer_size);

        if (!webcam_context_p->buffer_addr)
        {
            /* insufficent memory */
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
            return;
        }

        // Bin: allocate external working memory
        // Bin added
        webcam_context_p->jpeg_work_size = CAL_WEBCAM_EXT_MEM_SIZE;
        webcam_context_p->jpeg_work_addr = (kal_uint8*) med_alloc_asm_mem(webcam_context_p->app_id, webcam_context_p->jpeg_work_size);
        
        MedWebcamProcessStruct.ExtmemStartAddress = (kal_uint32)(webcam_context_p->jpeg_work_addr);
        MedWebcamProcessStruct.ExtmemSize = webcam_context_p->jpeg_work_size;
        
        if (!webcam_context_p->jpeg_work_addr)
        {
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_FREE_USB_BUFFER();
            WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
            return;
        }
        
        if (webcam_context_p->buffer_addr)
        {
            start.buffer_addr = webcam_context_p->buffer_addr;
            start.buffer_size = webcam_context_p->buffer_size;
            webcam_send_usb_resume_req((void*)&start);
            WEBCAM_ENTER_STATE(WEBCAM_START_PREVIEW);
        }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_resume_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video resume confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_resume_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        if (msg_p->result)
        {
            do {
                camera_result = CalOpen(MedWebcamCallback);
                if(camera_result != MM_ERROR_NONE)
                {                   
                    break;
                }

                MedWebcamProcessStruct.TargetSize = msg_p->video_size_type;
                MedWebcamProcessStruct.TargetCompression = msg_p->video_compression_type;
                MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;

                MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
                MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
                MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
                MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
                camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
                if(camera_result != MM_ERROR_NONE)
                {
                    CalClose();
                    break;
                }
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
                webcam_set_result(MED_RES_OK);
                WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
                
            } while(0);
            
            if(camera_result != MM_ERROR_NONE)
            {
                webcam_set_result(MED_RES_FAIL);             
                WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);   
                /* Webcam is still in WEBCAM_START_PREVIEW state */
            }
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            WEBCAM_SET_EVENT(WEBCAM_EVT_RESUME);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_capture_req_hdlr
 * DESCRIPTION
 *  This function is to inform host to start capture.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_capture_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    webcam_context_p->src_mod = ilm_ptr->src_mod_id;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        webcam_send_usb_still_capture_req(NULL);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_CAPTURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_capture_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the video capture confirm from USB task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_capture_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_result_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_result_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW) || WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        if (msg_p->result)
        {
            webcam_set_result(MED_RES_OK);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
        }
    }
    WEBCAM_SET_EVENT(WEBCAM_EVT_CAPTURE);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_pause_connect_req_hdlr
 * DESCRIPTION
 *  This function is to handle the pause connect with PC from MMI task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_pause_connect_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WEBCAM_STATE_TRACE(webcam_context_p->state);
    
    if (WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_send_usb_pause_connect_req();
        WEBCAM_ENTER_STATE(WEBCAM_PAUSE_CONNECT);

        WEBCAM_FREE_USB_BUFFER();
        WEBCAM_FREE_JPG_WORK_BUFFER();
        webcam_set_result(MED_RES_OK);
    }        
    else
        webcam_set_result(MED_RES_FAIL);
        
    WEBCAM_SET_EVENT(WEBCAM_EVT_CONNECT);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_resume_connect_req_hdlr
 * DESCRIPTION
 *  This function is to handle the resume connect with PC from MMI task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_resume_connect_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WEBCAM_STATE_TRACE(webcam_context_p->state);
    
    if (WEBCAM_IN_STATE(WEBCAM_PAUSE_CONNECT))
    {
        usbvideo_video_req_struct connect;
        
        webcam_context_p->buffer_size = CAL_WEBCAM_JPEG_BUFFER_SIZE;
        webcam_context_p->buffer_addr = (kal_uint8*) med_alloc_asm_mem_framebuffer(webcam_context_p->app_id, webcam_context_p->buffer_size);

        if (!webcam_context_p->buffer_addr)
        {
            /* insufficent memory */
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_SET_EVENT(WEBCAM_EVT_CONNECT);
            return;
        }

        webcam_context_p->jpeg_work_size = CAL_WEBCAM_EXT_MEM_SIZE;
        webcam_context_p->jpeg_work_addr = (kal_uint8*) med_alloc_asm_mem_framebuffer(webcam_context_p->app_id, webcam_context_p->jpeg_work_size);
        
        MedWebcamProcessStruct.ExtmemStartAddress = (kal_uint32)(webcam_context_p->jpeg_work_addr);
        MedWebcamProcessStruct.ExtmemSize = webcam_context_p->jpeg_work_size;

        if (!webcam_context_p->jpeg_work_addr)
        {
            webcam_set_result(MED_RES_MEM_INSUFFICIENT);
            WEBCAM_FREE_USB_BUFFER();
            WEBCAM_SET_EVENT(WEBCAM_EVT_CONNECT);
            return;
        }

        if (webcam_context_p->buffer_addr)
        {
            connect.buffer_addr = webcam_context_p->buffer_addr;
            connect.buffer_size = webcam_context_p->buffer_size;
            webcam_send_usb_resume_connect_req((void*)&connect);
            WEBCAM_ENTER_STATE(WEBCAM_START_PREVIEW);
            webcam_set_result(MED_RES_OK);
            WEBCAM_SET_EVENT(WEBCAM_EVT_CONNECT);
        }
    }
    
    WEBCAM_SET_EVENT(WEBCAM_EVT_CONNECT);
}


/*****************************************************************************
 * FUNCTION
 *  webcam_rotate_req_hdlr
 * DESCRIPTION
 *  This function is to rotate webcam.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_rotate_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_rotate_req_struct *req_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_webcam_rotate_req_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        webcam_context_p->image_rotate = (MM_IMAGE_ROTATE_ENUM)req_p->rotate;
        /* 1. stop camera preview */
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        /* 2. change the rotate value */
        MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;
        /* 3. restart the preview */
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        if(camera_result == MM_ERROR_NONE)
        {
            webcam_set_result(MED_RES_OK);
            WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
        }
        else
        {
            webcam_set_result(MED_RES_FAIL);
            MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
            CalClose();
                    
            WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);            
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE) || WEBCAM_IN_STATE(WEBCAM_START_PREVIEW))
    {
        webcam_context_p->image_rotate = (MM_IMAGE_ROTATE_ENUM)req_p->rotate;
        MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;
        webcam_set_result(MED_RES_OK);
        WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
    }
    else
    {
        webcam_set_result(MED_RES_BUSY);
        WEBCAM_SET_EVENT(WEBCAM_EVT_ROTATE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_set_camera_attr_req_hdlr
 * DESCRIPTION
 *  This function is to handle set camera attributes from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_set_camera_attr_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_attr_msg_struct *req_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (usbvideo_attr_msg_struct*) ilm_ptr->local_para_ptr;

    /* set camera to camera driver */
    MedCalFeatureControlStruct.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
    MedCalFeatureControlStruct.FeatureId = CAL_FEATURE_WEBCAM_SET_ATTR;
    MedCalFeatureControlStruct.FeatureInfo.FeatureStructured.pWebCamAttr = &(req_p->attr_value);
    camera_result = CalCtrl(CAL_FEATURE_CTRL, &MedCalFeatureControlStruct, NULL, 0, NULL);
    ASSERT(camera_result == MM_ERROR_NONE);
    
    /* send confirm msg to USB task */
    webcam_send_usb_set_camera_attr_cnf((void*)req_p);

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_still_ind_hdlr
 * DESCRIPTION
 *  This function is to handle start still capture indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_still_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_still_size_struct *msg_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_still_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        /* stop camera preview */
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);

        MedWebcamProcessStruct.TargetSize = (USBVIDEO_VIDEO_SIZE_TYPE)msg_p->still_size_type;
        MedWebcamProcessStruct.TargetCompression = msg_p->still_compression_type;
        MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;  
        
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
        MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
        MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        if(camera_result == MM_ERROR_NONE)
        {
            WEBCAM_ENTER_STATE(WEBCAM_CAPTURE);
        }
        else
        {
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
            CalClose();
               
            webcam_send_usb_stop_video_req(NULL);
            WEBCAM_ENTER_STATE(WEBCAM_STOPPING);                           
            webcam_set_result(MED_RES_FAIL);
            webcam_send_abort_ind();
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        /* stop camera capture */
        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);

        MedWebcamProcessStruct.TargetSize = (USBVIDEO_VIDEO_SIZE_TYPE)msg_p->still_size_type;
        MedWebcamProcessStruct.TargetCompression = msg_p->still_compression_type;
        MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;

        MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
        MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
        MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
        MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
        
        camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
        if(camera_result == MM_ERROR_NONE)
        {
            WEBCAM_ENTER_STATE(WEBCAM_CAPTURE);
        }
        else
        {
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
            CalClose();
               
            webcam_send_usb_stop_video_req(NULL);
            WEBCAM_ENTER_STATE(WEBCAM_STOPPING);                         
            webcam_set_result(MED_RES_FAIL);
            webcam_send_abort_ind();
        }
    }
    else if (WEBCAM_IN_STATE(WEBCAM_PAUSING))
    {
        /* already send pause command to usb driver, ignore this action */
    }
    else if (WEBCAM_IN_STATE(WEBCAM_STOPPING))
    {
        /* already send stop command to usb driver, ignore this action */
    }
    else
    {
        ASSERT(WEBCAM_IN_STATE(WEBCAM_PREVIEW));
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_start_video_ind_hdlr
 * DESCRIPTION
 *  This function is to handle start video indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_start_video_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_CAPTURE))
    {
        if (msg_p->result)
        {
            /* stop camera still capture */
            MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_CAPTURE;
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);

            MedWebcamProcessStruct.TargetSize = msg_p->video_size_type;
            MedWebcamProcessStruct.TargetCompression = msg_p->video_compression_type;
            MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;
            
            MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
            MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
            MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
            if(camera_result == MM_ERROR_NONE)
            {
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
            }
            else
            {
                webcam_set_result(MED_RES_FAIL);
                MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
                camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
                CalClose();
               
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING); 
                webcam_send_abort_ind();
            }
        }
        else
        {
            ASSERT(msg_p->result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  webcam_change_video_ind_hdlr
 * DESCRIPTION
 *  This function is to handle change video size indication from USB.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_change_video_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usbvideo_video_size_struct *msg_p;
    MM_ERROR_CODE_ENUM camera_result = MM_ERROR_NONE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (usbvideo_video_size_struct*) ilm_ptr->local_para_ptr;

    if (WEBCAM_IN_STATE(WEBCAM_PREVIEW))
    {
        if (msg_p->result)
        {
            /* stop camera a preview */
            MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);

            MedWebcamProcessStruct.TargetSize = msg_p->video_size_type;
            MedWebcamProcessStruct.TargetCompression = msg_p->video_compression_type;
            MedWebcamProcessStruct.ImageRotate = webcam_context_p->image_rotate;
            
            MedCalScenarioControlStruct.ScenarioId = CAL_SCENARIO_WEBCAM_PREVIEW;
            MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_START;
            MedCalScenarioControlStruct.ScenarioCtrlParaLen = sizeof(CAL_CAMERA_WEBCAM_PROCESS_STRUCT);
            MedCalScenarioControlStruct.pScenarioCtrlPara = &MedWebcamProcessStruct;
            camera_result = CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
            if(camera_result == MM_ERROR_NONE)
            {
                WEBCAM_ENTER_STATE(WEBCAM_PREVIEW);
            }
            else
            {
                webcam_set_result(MED_RES_FAIL);
                MedCalScenarioControlStruct.ScenarioCtrlCode = CAL_CTRL_CODE_STOP;
                CalCtrl(CAL_SCENARIO_CTRL, &MedCalScenarioControlStruct, NULL, 0, NULL);
                CalClose();
             
                webcam_send_usb_stop_video_req(NULL);
                WEBCAM_ENTER_STATE(WEBCAM_STOPPING);  
                webcam_send_abort_ind();                
            }
        }
        else
        {
            ASSERT(msg_p->result);
        }
    }
    else
    {
        ASSERT(WEBCAM_IN_STATE(WEBCAM_PREVIEW));
    }

}


/*****************************************************************************
 * FUNCTION
 *  webcam_drv_abort_ind_hdlr
 * DESCRIPTION
 *  This function is to handle drvier aboart, but the cable didnt plugout.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void webcam_drv_abort_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WEBCAM_IN_STATE(WEBCAM_IDLE))
    {
        webcam_send_abort_ind();
    }
}
#pragma arm section code, rodata

#endif /* __MED_WEBCAM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

