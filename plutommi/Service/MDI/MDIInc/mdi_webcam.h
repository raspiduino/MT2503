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
 *  mdi_webcam.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Webcam related interface header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_WEBCAM_H_
#define _MDI_WEBCAM_H_
#include "MMI_features.h"

#ifdef __MMI_WEBCAM__
#include "mdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "cal_comm_def.h"

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's webcam functions 
    * - For Target, call media's cam functions.
    */
#define MDI_WEBCAM_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
#include "med_global.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/

/* Preview rotate value */
#define MDI_WEBCAM_PREVIEW_ROTATE_0             MM_IMAGE_ROTATE_0               /* rotate 0 */
#define MDI_WEBCAM_PREVIEW_ROTATE_90            MM_IMAGE_ROTATE_90              /* rotate 90 */
#define MDI_WEBCAM_PREVIEW_ROTATE_180           MM_IMAGE_ROTATE_180             /* rotate 180 */
#define MDI_WEBCAM_PREVIEW_ROTATE_270           MM_IMAGE_ROTATE_270             /* rotate 270 */
#define MDI_WEBCAM_PREVIEW_ROTATE_0_MIRROR      MM_IMAGE_H_MIRROR               /* rotate 0 mirror */
#define MDI_WEBCAM_PREVIEW_ROTATE_90_MIRROR     MM_IMAGE_H_MIRROR_ROTATE_90     /* rotate 90 mirror */
#define MDI_WEBCAM_PREVIEW_ROTATE_180_MIRROR    MM_IMAGE_H_MIRROR_ROTATE_180    /* rotate 180 mirror */
#define MDI_WEBCAM_PREVIEW_ROTATE_270_MIRROR    MM_IMAGE_H_MIRROR_ROTATE_270    /* rotate 270 mirror */

#define MDI_WEBCAM_MAIN     CAL_CAMERA_SOURCE_MAIN     /* Main camera sensor */
#define MDI_WEBCAM_SUB      CAL_CAMERA_SOURCE_SUB      /* Sub camera sensor */
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* Video size enum */
typedef enum
{
    MDI_WEBCAM_JPG_160x120,     /* 160*120 video size */
    MDI_WEBCAM_JPG_320x240,     /* 320*240 video size */
    MDI_WEBCAM_JPG_640x480,     /* 640*480 video size */

    MDI_WEBCAM_JPG_COUNT        /* video size count */
} mdi_webcam_jpg_enum;


/*****************************************************************************
 * <GROUP  CallBackFunctions>		
 *
 * FUNCTION
 *  mdi_webcam_event_callback
 * DESCRIPTION
 *  Webcam event callback
 * PARAMETERS
 *  ret                 : [IN]      result
 *  camera_workable     : [IN]      camera module workable
 * RETURN VALUES
 *  void
 * <code>
 * </code>
 *****************************************************************************/
typedef void (*mdi_webcam_event_callback) (MDI_RESULT, BOOL, void*);

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_init
 * DESCRIPTION
 *  Webcam initializtion
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED  : Success
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_init(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_set_pause_jpeg_file
 * DESCRIPTION
 *  Set jpeg files which will be used when webcam pauses.
 * PARAMETERS
 *  idx                 : [IN]        Index
 *  jpeg_file_ptr       : [IN]        JPEG file data pointer
 *  file_length         : [IN]        File length
 *  width               : [IN]        Image width
 *  height              : [IN]        Image height
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED  : success
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_set_pause_jpeg_file(U16 idx, PU8 jpeg_file_ptr, U32 file_length, S32 width, S32 height);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_set_camera_id
 * DESCRIPTION
 *  Choose the camera sensor
 * PARAMETERS
 *  camera_id       : [IN]    Camera id [main or sub]
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      Success
 *  MDI_RES_WEBCAM_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_set_camera_id(U16 camera_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_start
 * DESCRIPTION
 *  Start webcam
 * PARAMETERS
 *  rotate              : [IN]        Preview rotate
 *  banding             : [IN]        Banding
 *  event_callback      : [IN]        Webcam event callback
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_start(U16 app_id, U16 rotate, U16 banding, mdi_webcam_event_callback event_callback, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_stop
 * DESCRIPTION
 *  Stop webcam
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_stop(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_pause
 * DESCRIPTION
 *  Pause webcam
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_pause(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_resume
 * DESCRIPTION
 *  Resume webcam
 * PARAMETERS
 *  rotate      : [IN]    Preview rotate
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_resume(U16 rotate);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_capture
 * DESCRIPTION
 *  Notify PC to capture the image
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_capture(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_rotate
 * DESCRIPTION
 *  Rotate webcam preview
 * PARAMETERS
 *  rotate      : [IN]    Preview rotate
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_rotate(U16 rotate);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_pause_connect
 * DESCRIPTION
 *  Pause webcam connect
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_pause_connect(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_resume_connect
 * DESCRIPTION
 *  Resume webcam connect
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *  MDI_RES_WEBCAM_ERR_FAILED   : Failure
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_resume_connect(void);


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
extern U16 mdi_webcam_get_pause_jpeg_count(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_pause_jpeg_info
 * DESCRIPTION
 *  Get pause jpeg file count
 * PARAMETERS
 *  idx                 : [IN]        Index
 *  image_width         : [OUT]       Image width
 *  image_height        : [OUT]       Image height
 * RETURN VALUES
 *  MDI_RES_WEBCAM_SUCCEED      : Success
 *****************************************************************************/
extern MDI_RESULT mdi_webcam_get_pause_jpeg_info(U16 idx, S32 *image_width, S32 *image_height);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   : [IN]     Error code got from MDI APIs
 *  popup_type   : [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
extern MMI_ID_TYPE mdi_webcam_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);
#endif /* __MMI_WEBCAM__ */ /* __MMI_WEBCAM_APP__ */
#endif /* _MDI_WEBCAM_H_ */ 

