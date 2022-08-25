/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAL_TASK_MSG_IF_H__
#define __CAL_TASK_MSG_IF_H__

#include "kal_release.h"
#include "app_ltlcom.h"
#include "stack_timer.h"
#include "mm_comm_def.h"
#include "cal_api.h"
#include "iul_csc_y2r.h"
#include "jpeg_encode_wrapper.h"

//include G2D api
#include "drv_features_g2d.h"
#include "g2d_enum.h"
#include "g2d_common_api.h"
#include "g2d_lt_api.h"
#include "g2d_bitblt_api.h"
#include "g2d_font_api.h"
#include "g2d_rectfill_api.h"

#include "pp_feature_def.h" /* to access the define of __POSTPROC_SUPPORT__ */

#define CAL_STACK_TIMER_INDEX_STILL_CAPTURE_TIMEOUT     1

typedef struct
{
    LOCAL_PARA_HDR

} CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT, *P_CAL_JPEG_SENSOR_PARSE_REQ_MSG_STRUCT;

typedef struct 
{
    kal_uint8  *ImageSrcBuffer;  // source encoded jpeg buffer address to be clip
    kal_uint32 ImageSrcBufferSize;   // source encoded jpeg buffer size to be clip   
    kal_uint32 SrcWidth;               // source encoded jpeg image size
    kal_uint32 SrcHeight;
    kal_uint32 SrcRoiX;               // start point x of ROI of source image
    kal_uint32 SrcRoiY;               // start point y of ROI of source image
    kal_uint32 RoiWidth;                   // width of ROI
    kal_uint32 RoiHeight;                   // height of ROI
    kal_uint8  *ImageDstBuffer;  // dest decoded jpeg buffer to clip to, RGB565
    MM_IMAGE_FORMAT_ENUM  ImageSrcFormat;     // src color format (JPEG/YUV420)
    MM_IMAGE_FORMAT_ENUM  ImageDstFormat;     // dst color format (RGB565/YUV420/Y8)
    kal_uint32 DstWidth;               // dest decoded jpeg image size
    kal_uint32 DstHeight;                  
    kal_uint32 DstRoiX;               // start point x of ROI of dest image
    kal_uint32 DstRoiY;               // start point y of ROI of dest image
    kal_bool IsSwitchCachable;
    kal_uint32 ExtMemAddr;         // external working memory
    kal_uint32 ExtMemSize;
} CAL_JPEG_DECODE_STRUCT, *P_CAL_JPEG_DECODE_STRUCT;


//MSG_ID_CAL_INFORM_MDP_FRAME_RATE_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 CurrentPreiodAvgFrames; //  1 base 
    kal_uint32 CurrentFrameTime; //  1 base 
    kal_uint32 CurrentFrameRate; //  1 base 
} CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT, *P_CAL_INFORM_MDP_FRAME_RATE_REQ_MSG_STRUCT;

// for MSG_ID_CAL_JAIA_MERGE_REQ
typedef struct
{
    LOCAL_PARA_HDR

    CAL_CALLBACK_ID_ENUM JaiaCbId;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pCalStillCapPara;

    kal_uint32 MainImageStartAddr;
    kal_uint32 MainImageSize;

    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
    kal_bool ExifWholeInfoAttach;//add for jpeg sensor use jaia to attach whole exif header
} CAL_JAIA_MERGE_REQ_MSG_STRUCT, *P_CAL_JAIA_MERGE_REQ_MSG_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR
    
    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
    
    kal_uint32 MainImageBuffAddr;
    kal_uint32 MainImageBuffAddrU;
    kal_uint32 MainImageBuffAddrV;
    CAL_CALLBACK_ID_ENUM QuickViewImageResizeCbId;
    CAL_CALLBACK_ID_ENUM ThumbnailImageResizeCbId;
    P_CAL_MDP_STILL_CAPTURE_STRUCT pCalStillCapPara;
	kal_bool IsSrcClip;
	iul_rect *pSrcWindow;
} CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT, *P_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    MM_IMAGE_FORMAT_ENUM ImageDataFormat;
    MM_IMAGE_ROTATE_ENUM ImageRotAngle;
    CAL_CALLBACK_ID_ENUM ImageRotCbId;

    kal_uint32 SrcImageYBuffAddr;
    kal_uint32 SrcImageUBuffAddr;
    kal_uint32 SrcImageVBuffAddr;

    kal_uint32 DestImageYBuffAddr;
    kal_uint32 DestImageUBuffAddr;
    kal_uint32 DestImageVBuffAddr;

    kal_uint16 SrcImageWidth;
    kal_uint16 SrcImageHeight;

    kal_uint32 ImageYBuffSize;
    kal_uint32 ImageUBuffSize;
    kal_uint32 ImageVBuffSize;

    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
} CAL_ROTATE_IMAGE_REQ_STRUCT, *P_CAL_ROTATE_IMAGE_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    MM_IMAGE_FORMAT_ENUM ImageDataFormat;
    MM_IMAGE_ROTATE_ENUM ImageRotateAngle;
    CAL_CAMERA_IMAGE_EFFECT_ENUM      ImageEffectId;
    CAL_CALLBACK_ID_ENUM ImageEffectCbId;
    kal_uint32 SrcImageYBuffAddr;
    kal_uint32 SrcImageUBuffAddr;
    kal_uint32 SrcImageVBuffAddr;

    kal_uint32 DestImageYBuffAddr;
    kal_uint32 DestImageUBuffAddr;
    kal_uint32 DestImageVBuffAddr;

    kal_uint16 SrcImageWidth;
    kal_uint16 SrcImageHeight;

    kal_uint32 ImageYBuffSize;
    kal_uint32 ImageUBuffSize;
    kal_uint32 ImageVBuffSize;
} CAL_IMAGE_EFFECT_REQ_STRUCT, *P_CAL_IMAGE_EFFECT_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    MM_IMAGE_FORMAT_ENUM SrcImageDataFormat;
    CAL_CALLBACK_ID_ENUM GetPreviewImageCbId;
    kal_uint16 SrcImageWidth;
    kal_uint16 SrcImageHeight;
    kal_uint32 SrcImageBuffAddr;
    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
    P_CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT pGetPreviewImagePara;
} CAL_GET_PREVIEW_IMAGE_STRUCT, *P_CAL_GET_PREVIEW_IMAGE_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 ImageWidth;
    kal_uint16 ImageHeight;
    kal_uint32 ImageBuffAddr;
} CAL_IMAGE_Y2R_DITHERING_STRUCT, *P_CAL_IMAGE_Y2R_DITHERING_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR
    CAL_SCENARIO_ENUM ScenarioId;       ///record the scenario ID when this encode request is send out, webcam scenario need this scenario ID do control encode flow
    JPEG_WRAPPER *pJpegWrapperPara;
}CAL_SW_JPEG_ENCODE_REQ_STRUCT, *P_CAL_SW_JPEG_ENCODE_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR
    CAL_SCENARIO_ENUM ScenarioId;       ///record the scenario ID when this encode request is send out, webcam scenario need this scenario ID do control encode flow
    P_CAL_JPEG_DECODE_STRUCT pJpegDecoderPara;
}CAL_JPEG_DECODE_REQ_STRUCT, *P_CAL_JPEG_DECODE_REQ_STRUCT;

typedef struct
{
    JPEG_STATUS_ENUM JpegStatus;
    kal_uint8 *pJpegDataAddr;
    kal_uint32 JpegDataSize;
} CAL_JPEG_ENCODE_CB_STRUCT, *P_CAL_JPEG_ENCODE_CB_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 Param;
}CAL_WEBCAM_FRAME_READY_REQ_STRUCT, *P_CAL_WEBCAM_FRAME_READY_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    MM_IMAGE_FORMAT_ENUM ImageDataFormat;
    kal_bool IsCopyEnable;
    kal_bool IsResizeEnable;
    
    kal_uint32 SrcImageBuffAddr;
    kal_uint32 SrcImageBuffSize;
    kal_uint32 CopyImageBuffAddr;
    kal_uint32 CopyImageBuffSize;
    kal_uint32 ResizeImageBuffAddr;
    kal_uint32 ResizeImageBuffSize;

    kal_uint16 SrcImageWidth;
    kal_uint16 SrcImageHeight;

    kal_uint16 ResizeImageWidth;
    kal_uint16 ResizeImageHeight;
} CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT, *P_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ_STRUCT;

typedef struct
{
    LOCAL_PARA_HDR

    MM_IMAGE_FORMAT_ENUM ImageDataFormat;
    MM_IMAGE_ROTATE_ENUM ImageRotAngle;
    CAL_CALLBACK_ID_ENUM ImageRotCbId;
    kal_uint8 ImageCount;

    kal_uint32 SrcImageYBuffAddr;   // must be continuous memory
    kal_uint32 SrcImageUBuffAddr;
    kal_uint32 SrcImageVBuffAddr;

    kal_uint32 DestImageYBuffAddr;  // must be continuous memory
    kal_uint32 DestImageUBuffAddr;
    kal_uint32 DestImageVBuffAddr;

    kal_uint16 SrcImageWidth;
    kal_uint16 SrcImageHeight;

    kal_uint32 ImageYBuffSize;
    kal_uint32 ImageUBuffSize;
    kal_uint32 ImageVBuffSize;

    kal_uint32 WorkingBuffAddr;
    kal_uint32 WorkingBuffSize;
} CAL_ROTATE_IMAGE_LIST_REQ_STRUCT, *P_CAL_ROTATE_IMAGE_LIST_REQ_STRUCT;

#if (defined(__POSTPROC_SUPPORT__) && defined(G2D_SUPPORT) && (defined(MT6250)||defined(MT6260)||defined(MT6261)||defined(MT2501)||defined(MT2502)))
typedef kal_bool (*idp_g2d_cb_func_t)(void *);

typedef struct
{
    //LOCAL_PARA_HDR
    MM_IMAGE_COLOR_FORMAT_ENUM      mem_in_color_fmt1;
    kal_uint32                      src_buff_y_addr;
    kal_uint32                      src_buff_u_addr;
    kal_uint32                      src_buff_v_addr;
    kal_uint16                      src_height;
    kal_uint16                      src_width;

    MM_IMAGE_COLOR_FORMAT_ENUM      yuv_color_fmt; /**< output yuv format */
    kal_uint16                      tar_height;
    kal_uint16                      tar_width;
    kal_uint32                      y_dest_start_addr;
    kal_uint32                      u_dest_start_addr;
    kal_uint32                      v_dest_start_addr;

    img_rot_angle_enum_t            rot_angle; /**< rotate direction */

    idp_g2d_cb_func_t               cb_func;
    void * exec_param;

} CAL_G2D_REQ_STRUCT, *P_CAL_G2D_REQ_STRUCT ;
#endif

extern stack_timer_struct CalTaskStackTimer;
extern CAL_JAIA_MERGE_REQ_MSG_STRUCT JaiaMergePara;

void ImageRotHandle(ilm_struct *pIlmPtr);

#endif /* __CAL_TASK_MSG_IF_H__ */
