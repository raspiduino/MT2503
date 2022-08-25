/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_misc_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of JPEG codec unified interface.
 *   Notice that these API are for internal use only.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "string.h"

#include "jpeg_enum.h"
#include "jpeg_misc_api.h"

#if defined(JPEG_CODEC_STANDALONE)
   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"
   
   #if defined(__MTK_TARGET__)
      #include "idp_jpeg_decode.h"
      #include "img_common_enum.h"
   #endif
#endif



/// Return the bytes-per-pixel according to the given format.
kal_int32 _jpeg_get_bpp_by_rgb_format(JPEG_RGB_FORMAT_ENUM format)
{
   switch (format) {
   case JPEG_RGB_FORMAT_UNSUPPORTED:
      return 0;

   case JPEG_RGB_FORMAT_GRAYLEVEL:
      return 1;

   case JPEG_RGB_FORMAT_RGB565:
      return 2;

   case JPEG_RGB_FORMAT_RGB888:
   case JPEG_RGB_FORMAT_BGR888:
      return 3;

   case JPEG_RGB_FORMAT_ARGB8888:
      return 4;

   default:
      ASSERT(0);
      return 0;
   }
}



/// Return the bytes-per-pixel according to the given format.
kal_int32 _jpeg_get_bpp_by_yuv_format(JPEG_YUV_FORMAT_ENUM format)
{
   switch (format) {
   case JPEG_YUV_FORMAT_UNSUPPORTED:
      return 0;

   case JPEG_YUV_FORMAT_YUV444:
   case JPEG_YUV_FORMAT_YUV422:
   case JPEG_YUV_FORMAT_YUV411:
   case JPEG_YUV_FORMAT_YUV420:
   case JPEG_YUV_FORMAT_GRAYLEVEL:
      return 1;

   case JPEG_YUV_FORMAT_PACKED_UYVY422:
      return 2;
      
   default:
      ASSERT(0);
      return 0;
   }
}



kal_int32 _jpeg_get_jpeg_yuv_format_enum(kal_int32 format)
{
#if defined(__MTK_TARGET__)
   switch (format)
   {
   case IMG_COLOR_FMT_YUV444:
      return JPEG_YUV_FORMAT_YUV444;

   case IMG_COLOR_FMT_YUV422:
      return JPEG_YUV_FORMAT_YUV422;

   case IMG_COLOR_FMT_YUV420:
      return JPEG_YUV_FORMAT_YUV420;

   case IMG_COLOR_FMT_YUV411:
      return JPEG_YUV_FORMAT_YUV411;

   case IMG_COLOR_FMT_YUV400:
      return JPEG_YUV_FORMAT_GRAYLEVEL;

   default:
      ASSERT(0);
      return JPEG_YUV_FORMAT_UNSUPPORTED;
   }
#else
   ASSERT(0);
   return 0;
#endif
}



kal_int32 _jpeg_get_idp_yuv_format_enum(JPEG_YUV_FORMAT_ENUM format)
{
#if defined(__MTK_TARGET__)
   switch (format)
   {
   case JPEG_YUV_FORMAT_YUV444:
      return IMG_COLOR_FMT_YUV444;

   case JPEG_YUV_FORMAT_YUV422:
      return IMG_COLOR_FMT_YUV422;

   case JPEG_YUV_FORMAT_YUV420:
      return IMG_COLOR_FMT_YUV420;

   case JPEG_YUV_FORMAT_YUV411:
      return IMG_COLOR_FMT_YUV411;

   case JPEG_YUV_FORMAT_GRAYLEVEL:
      return IMG_COLOR_FMT_YUV400;

   case JPEG_YUV_FORMAT_PACKED_UYVY422:
      return IMG_COLOR_FMT_PACKET_YUYV422;

   default:
      ASSERT(0);
   }
#else
   ASSERT(0);
#endif
   return 0;
}




kal_int32 _jpeg_get_idp_rgb_format_enum(JPEG_RGB_FORMAT_ENUM format)
{
#if defined(__MTK_TARGET__)
   switch (format) {
   case JPEG_RGB_FORMAT_RGB565:
      return IMG_COLOR_FMT_RGB565;

   case JPEG_RGB_FORMAT_RGB888:
      return IMG_COLOR_FMT_RGB888;

   case JPEG_RGB_FORMAT_BGR888:
      return IMG_COLOR_FMT_BGR888;

   case JPEG_RGB_FORMAT_ARGB8888:
      return IMG_COLOR_FMT_ARGB8888;

   default:
      ASSERT(0);
   }
#else
   ASSERT(0);
#endif
   return 0;
}



kal_int32 _jpeg_rect_align_coordinate(MY_RECTANGLE *rect1, MY_RECTANGLE *rect2, MY_RECTANGLE *dstRect)
{
   if ((!rect1) || (!rect2) || (!dstRect)) {
      return 0;
   }

   dstRect->x = rect2->x - rect1->x;
   dstRect->y = rect2->y - rect1->y;
   dstRect->w = rect2->w;
   dstRect->h = rect2->h;

   return 1;
}



kal_int32 _jpeg_rect_get_intersection(MY_RECTANGLE *rect1, MY_RECTANGLE *rect2, MY_RECTANGLE *dstRect)
{
   kal_int32 x1 = rect2->x;
   kal_int32 y1 = rect2->y;
   kal_int32 x2 = x1 + rect2->w;
   kal_int32 y2 = y1 + rect2->h;


   if (x1 < rect1->x) {
      x1 = rect1->x;
   }

   if (x2 > (rect1->x + (kal_int32)rect1->w)) {
      x2 = (rect1->x + rect1->w);
   }

   if (x2 > x1) {
      dstRect->w = (kal_uint32)(x2 - x1);
   } else {
      memset(dstRect, 0, sizeof(MY_RECTANGLE));
      return 0;
   }

   if (y1 < rect1->y) {
      y1 = rect1->y;
   }

   if (y2 > (rect1->y + (kal_int32)rect1->h)) {
      y2 = (rect1->y + rect1->h);
   }

   if (y2 > y1) {
      dstRect->h = (kal_uint32)(y2 - y1);
   } else {
      memset(dstRect, 0, sizeof(MY_RECTANGLE));
      return 0;
   }

   dstRect->x = x1;
   dstRect->y = y1;

   return 1;
}



kal_int32 _jpeg_rect_check_intersection(MY_RECTANGLE *rect1, MY_RECTANGLE *rect2)
{
   MY_RECTANGLE instersection;

   return _jpeg_rect_get_intersection(rect1, rect2, &instersection);
}
