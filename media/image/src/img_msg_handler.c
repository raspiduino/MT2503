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
 *   img_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of image module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* DRM_REPLACE */
#include "drm_gprot.h"

#include "drv_features.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "img_main.h"

#ifdef __MED_IMG_MOD__ 
/*****************************************************************************
 * FUNCTION
 *  img_open_image_file
 * DESCRIPTION
 *  This function is to open image file for encode.
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 img_open_image_file(kal_wchar *file_name)
{
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  img_close_image_file
 * DESCRIPTION
 *  This function is to close image file for encode.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 img_close_image_file(kal_int32 size)
{
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  img_release_memory
 * DESCRIPTION
 *  This function is to release memory for image decoding/encoding.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void img_release_memory(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_get_decode_res
 * DESCRIPTION
 *  This function is to get the decode result.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 img_get_decode_res(kal_uint8 cause)
{
     return 0;
}


/*****************************************************************************
 * FUNCTION
 *  img_get_encode_res
 * DESCRIPTION
 *  This function is to get the encode result.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 img_get_encode_res(kal_uint8 cause)
{
    return MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_callback
 * DESCRIPTION
 *  This function is the callback function of decoding.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_callback(kal_uint8 cause)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_restart
 * DESCRIPTION
 *  This function is to restart decode process for retrying.
 * PARAMETERS
 *  void
 *  kal_uint8 cause(?)
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_restart(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_codec_retry_handler
 * DESCRIPTION
 *  This function is to handle image codec timeout.
 * PARAMETERS
 *  arg     [?]     
 *  kal_uint8 cause(?)
 * RETURNS
 *  void
 *****************************************************************************/
void img_codec_retry_handler(void *arg)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_decode_event_ind_hdlr
 * DESCRIPTION
 *  This function is the event handler for decoding.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_cal_work_buffer_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_ratio           [?]         
 *  wb_dest_x           [?]         
 *  wb_dest_y           [?]         
 *  wb_width            [?]         
 *  wb_height           [?]         
 *  wb_pixel_size       [IN]        
 *  img_w               [IN]        
 *  img_h               [IN]        
 *  dest_x              [IN]        
 *  dest_y              [IN]        
 *  expect_w            [IN]        
 *  expect_h            [IN]        
 *  clipx1              [IN]        
 *  clipy1              [IN]        
 *  clipx2              [IN]        
 *  clipy2              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_cal_work_buffer_info(
        kal_uint8 *ret_ratio,
        kal_int16 *wb_dest_x,
        kal_int16 *wb_dest_y,
        kal_uint16 *wb_width,
        kal_uint16 *wb_height,
        kal_uint32 wb_pixel_size,
        kal_uint16 img_w,
        kal_uint16 img_h,
        kal_int16 dest_x,
        kal_int16 dest_y,
        kal_uint16 expect_w,
        kal_uint16 expect_h,
        kal_int16 clipx1,
        kal_int16 clipy1,
        kal_int16 clipx2,
        kal_int16 clipy2)
{
    ASSERT(0);
}

#ifdef JPG_DECODE


/*****************************************************************************
 * FUNCTION
 *  image_decoder_jpeg_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 image_decoder_jpeg_req_hdlr(media_img_decode_req_struct *req_p)
{
    ASSERT(0);
    return 0;
}
#endif /* JPG_DECODE */ 


/*****************************************************************************
 * FUNCTION
 *  img_decode_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd decode request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_decode_req_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_encode_callback
 * DESCRIPTION
 *  This function is the callback function of encoding.
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_callback(kal_uint8 cause)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_encode_event_ind_hdlr
 * DESCRIPTION
 *  This function is the event handler for encoding.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}

#if defined (__JPEG_ENCODER_UNIFIED_INTERFACE__)
/*****************************************************************************
 * FUNCTION
 *  img_encode_jpeg_v2
 * DESCRIPTION
 *  image encode by jpeg v2 interface.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 img_encode_jpeg_v2(media_img_encode_req_struct* req_p)
{
    ASSERT(0);
}

#else
/*****************************************************************************
 * FUNCTION
 *  img_encode_jpeg_v1
 * DESCRIPTION
 *  image encode by jpeg v1 interface.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 img_encode_jpeg_v1(media_img_encode_req_struct* req_p)
{
    ASSERT(0);
}

#endif /* __JPEG_ENCODER_UNIFIED_INTERFACE__ */

/*****************************************************************************
 * FUNCTION
 *  img_encode_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd encode request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_encode_req_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  img_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop all processes
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_resize_req_hdlr
 * DESCRIPTION
 *  This function is to handle thd resize request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_resize_req_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  img_exif_decode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void img_exif_decode_req_hdlr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}

#endif /* __MED_IMG_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

