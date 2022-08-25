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
 *   drv_gfx_codec_limitation.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 28 2011 sophie.chen
 * removed!
 * Limitation Table
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_GFX_CODEC_LIMITATION_H__
#define __DRV_GFX_CODEC_LIMITATION_H__

#include "kal_general_types.h"
#if defined (__MTK_TARGET__)
#include "kal_public_api.h"
#endif
//#include "fsal.h"


extern const int g_fmgr_image_viewer_limit_arry[];
extern const int g_fmgr_wallpaper_limit_arry[];
extern const int g_fmgr_sub_wallpaper_limit_arry[];
extern const int g_fmgr_screensaver_limit_arry[];
extern const int g_fmgr_power_on_off_disp_limit_arry[];
extern const int g_fmgr_caller_picture_limit_arry[];
//#ifdef __MMI_VIDEO_TELEPHONY__
extern const int g_fmgr_vt_img_limit_arry[];
//#endif /*__MMI_VIDEO_TELEPHONY__*/
extern const int g_fmgr_caller_video_limit_arry[];
extern const int g_fmgr_mms_category_limit_arry[];


typedef enum
{
  GFX_IMAGE_TYPE_INVALID                  ,//0
  GFX_IMAGE_TYPE_BMP                      ,// 1
  GFX_IMAGE_TYPE_BMP_SEQUENCE             ,// 2
  GFX_IMAGE_TYPE_GIF                      ,// 3
  GFX_IMAGE_TYPE_DEVICE_BITMAP            ,// 4
  GFX_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE   ,//5
  GFX_IMAGE_TYPE_BMP_FILE                 ,//6
  GFX_IMAGE_TYPE_GIF_FILE                 ,//7
  GFX_IMAGE_TYPE_WBMP_FILE                ,//8
  GFX_IMAGE_TYPE_JPG                      ,//9
  GFX_IMAGE_TYPE_JPG_FILE                 ,//10
  GFX_IMAGE_TYPE_WBMP                     ,//11
  GFX_IMAGE_TYPE_AVI                      ,//12
  GFX_IMAGE_TYPE_AVI_FILE                 ,//13
  GFX_IMAGE_TYPE_3GP                      ,//14
  GFX_IMAGE_TYPE_3GP_FILE                 ,//15
  GFX_IMAGE_TYPE_MP4                      ,//16
  GFX_IMAGE_TYPE_MP4_FILE                 ,//17
  GFX_IMAGE_TYPE_JPG_SEQUENCE             ,//18
  GFX_IMAGE_TYPE_PNG                      ,//19
  GFX_IMAGE_TYPE_PNG_FILE                 ,//20
  GFX_IMAGE_TYPE_PNG_SEQUENCE             ,//21
  GFX_IMAGE_TYPE_DEVICE_BMP_FILE          ,//22
  GFX_IMAGE_TYPE_BMP_FILE_OFFSET          ,//23
  GFX_IMAGE_TYPE_GIF_FILE_OFFSET          ,//24
  GFX_IMAGE_TYPE_M3D                      ,//25
  GFX_IMAGE_TYPE_M3D_FILE                 ,//26
  GFX_IMAGE_TYPE_SVG                      ,//27
  GFX_IMAGE_TYPE_SVG_FILE                 ,//28
  GFX_IMAGE_TYPE_RSVD                     ,//29
}GFX_IMAGE_TYPE_ENUM;



typedef enum
{
 GFX_USER_NONE = 0,

 GFX_USER_IMAGE_VIEWER,
 GFX_USER_WALLPAPER,
 GFX_USER_SUB_WALLPAPER,
 GFX_USER_SCREEN_SAVER,
 GFX_USER_POWER_ON_OFF_DISPLAY,
 GFX_USER_VT_IMAGE,

 GFX_USER_CALLER_PICTURE,
 GFX_USER_CALLER_VIDEO, // not support in GFX driver

 GFX_USER_MMS_CATEGORY,

 GFX_USER_RSVD
}GFX_USER_APP_ENUM;


typedef enum
{
  GFX_CODEC_LIMITATION_OK = 0,
  GFX_CODEC_LIMITATION_ERROR_INVALID_RESOURCE_TYPE,
  GFX_CODEC_LIMITATION_ERROR_INVALID_APP_TYPE,
  GFX_CODEC_LIMITATION_ERROR_INVALID_IMAGE_SIZE,
  GFX_CODEC_LIMITATION_ERROR_INVALID_FILE_FORMAT,
  GFX_CODEC_LIMITATION_ERROR_IMAGE_TOO_LARGE,

  GFX_CODEC_LIMITATION_ERROR_MAX_OPERATION_TIME_SHALL_EQUAL_3,
  GFX_CODEC_LIMITATION_RSVD,
}GFX_CODEC_LIMITATION_STATUS_ENUM;


GFX_CODEC_LIMITATION_STATUS_ENUM gfx_codec_performance_query(
   GFX_USER_APP_ENUM app_type,
   GFX_IMAGE_TYPE_ENUM type,
   signed int width,
   signed int height,
   signed int file_len,
   kal_uint32 max_operation_time); //second

#endif //__DRV_GFX_CODEC_LIMITATION_H__
