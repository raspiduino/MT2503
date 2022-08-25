/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  mdi_video_clip.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video clipper related functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MDI_VIDEO_CLIP_H_
#define _MDI_VIDEO_CLIP_H_

#include "med_vid_clip_features.h"
#include "mdi_datatype.h"
#include "MMIDataType.h"
#include "mpl_clipper.h"
#include "mmi_frm_events_gprot.h"

#ifdef __MED_VID_CLIP_MOD__
#define __MDI_VIDEO_CLIP_SUPPORT__
#endif

#define MDI_VIDEO_CLIP_PARAM_PROCESS_RATIO MPL_CLIPPER_PARAM_CURR_PROGRESS


/* MDI video clip start structure */
typedef struct
{
    kal_uint32 start_time;      // start point to clip of source file, unit is ms
    kal_uint32 end_time;        // end point to clip of source file, unit is ms
    WCHAR*      src_filepath;    // source file path
    WCHAR*      dst_filepath;    // destination file path
}mdi_video_clip_prepare_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_video_clip_prepare_callback
 * DESCRIPTION
 *  video clip prepare callback
 * PARAMETERS
 *  result          : [IN]     result
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_video_clip_prepare_callback) (MDI_RESULT result, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>       
 *
 * FUNCTION
 *  mdi_video_clip_result_callback
 * DESCRIPTION
 *  video clip finish callback
 * PARAMETERS
 *  result          : [IN]     result
 *  user_data       : [IN]     user data
 * RETURN VALUE
 *  void
 *****************************************************************************/
typedef void (*mdi_video_clip_result_callback) (MDI_RESULT result, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_open
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  user_data       : [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_clip_open(U16 app_id);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_prepare
 * DESCRIPTION
 *  Prepare to clip a video file
 * PARAMETERS
 *  setting_p       : [IN]        setting structure
 *  callback        : [IN]        callback function pointer
 *  user_data       : [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_clip_prepare(mdi_video_clip_prepare_struct* setting_p, mdi_video_clip_prepare_callback callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_start
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  callback        : [IN]        callback function pointer
 *  user_data       : [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_clip_start(mdi_video_clip_result_callback callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_stop
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_clip_stop(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_close
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
extern MDI_RESULT mdi_video_clip_close(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_get_processing_ratio
 * DESCRIPTION
 *  Get the percentage of clipping process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Percentage value
 *****************************************************************************/
extern U32 mdi_video_clip_get_processing_ratio(void);


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   : [IN]     Error code got from MDI APIs
 *  popup_type   : [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
extern MMI_ID_TYPE mdi_video_clip_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

#endif /* _MDI_VIDEO_CLIP_H_ */
