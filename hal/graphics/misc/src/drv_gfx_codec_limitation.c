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
 *   drv_gfx_codec_limitation.c
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
 * 08 01 2013 sophie.chen
 * removed!
 * .
 *
 * 01 29 2013 sophie.chen
 * removed!
 * .
 *
 * 03 16 2012 ashish.yadav
 * removed!
 * Changing the limitation for the BMP,WBMP,PNG and GIF images.
 *
 * 02 17 2012 chenhung.yang
 * removed!
 * .
 *
 * 02 16 2012 robin.huang
 * removed!
 * .modify PNG limitation table
 *
 * 02 16 2012 helena.li
 * removed!
 * .
 *
 * 02 16 2012 sophie.chen
 * removed!
 * .
 *
 * 12 14 2011 sophie.chen
 * removed!
 * .
 *
 * 11 08 2011 sophie.chen
 * removed!
 * .
 *
 * 09 28 2011 sophie.chen
 * removed!
 * Limitation Table
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
//#if defined (__MTK_TARGET__)
#include "kal_public_api.h"
#include "kal_trace.h"
//#endif
//#include "fsal.h"
#include "lcd_sw_inc.h"
#include "drv_gfx_codec_limitation.h"

/*
 * size     : Kbyte
 * width    : pixel
 * height   : pixel
 */
#define GFX_BMP_LIMIT(size,width,height)   GFX_IMAGE_TYPE_BMP_FILE,size,width,height
#define GFX_JPG_LIMIT(size,width,height)   GFX_IMAGE_TYPE_JPG_FILE,size,width,height
#define GFX_GIF_LIMIT(size,width,height)   GFX_IMAGE_TYPE_GIF_FILE,size,width,height
#define GFX_WBMP_LIMIT(size,width,height)  GFX_IMAGE_TYPE_WBMP_FILE,size,width,height
#define GFX_PNG_LIMIT(size,width,height)   GFX_IMAGE_TYPE_PNG_FILE,size,width,height
#define GFX_M3D_LIMIT(size,width,height)   GFX_IMAGE_TYPE_M3D_FILE,size,width,height
#ifdef SVG12_SUPPORT
#define GFX_SVG_LIMIT(size,width,height)   GFX_IMAGE_TYPE_SVG_FILE,0,0,0
#else
#define GFX_SVG_LIMIT(size,width,height)   GFX_IMAGE_TYPE_SVG_FILE,size,width,height
#endif

// (type,size,width,height)
#define GFX_CODEC_LIMITATION_ENTRY_SIZE    4

#define END_LIMIT     GFX_IMAGE_TYPE_INVALID

//#define VDO_3GP_LIMIT_ITEM(size,duration,width,height)      GDI_IMAGE_TYPE_3GP_FILE,size,duration,width,height
//#define VDO_MP4_LIMIT_ITEM(size,duration,width,height)      GDI_IMAGE_TYPE_MP4_FILE,size,duration,width,height
//#define VDO_AVI_LIMIT_ITEM(size,duration,width,height)      GDI_IMAGE_TYPE_AVI_FILE,size,duration,width,height
//#define VDO_SWFLASH_LIMIT_ITEM(size,duration,width,height)  GDI_IMAGE_TYPE_SWFLASH_FILE,size,duration,width,height

/****************************************************************************
* Static Variable
*****************************************************************************/

const signed int gfx_codec_image_viewer_limit_arry[] =
{
#if defined(MT6225)
    GFX_JPG_LIMIT(1230, 0, 0),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(6656, 0, 0),
    GFX_GIF_LIMIT(0, 1280, 1280),
    GFX_PNG_LIMIT(0, 640, 480),
    GFX_SVG_LIMIT(0, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
    GFX_JPG_LIMIT(2253, 0, 0),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(1230, 0, 0),
    GFX_GIF_LIMIT(0, 640, 640),
    GFX_PNG_LIMIT(0, 480, 320),
    GFX_SVG_LIMIT(0, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B)
    GFX_JPG_LIMIT(3175, 0, 0),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(16384, 0, 0),
    GFX_GIF_LIMIT(0, 1280, 1280),
    GFX_PNG_LIMIT(0, 1024, 768),
    GFX_SVG_LIMIT(125, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#elif defined(MT6238) || defined(MT6239) || defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B)|| defined(MT6276) || defined(MT6256)
    GFX_JPG_LIMIT(12000, 4095, 4095),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(25000, 50000, 40000),
    GFX_GIF_LIMIT(0, 2300, 2300),
    GFX_PNG_LIMIT(0, 2047, 2047),
    GFX_SVG_LIMIT(125, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#elif defined(MT6253) || defined(MT6253T)
    GFX_JPG_LIMIT(1000, 0, 0),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(1500, 50000, 40000),
    GFX_GIF_LIMIT(0, 1200, 1200),
    GFX_PNG_LIMIT(0, 700, 700),
    GFX_SVG_LIMIT(125, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#elif defined(MT6252)
    GFX_JPG_LIMIT(1024, 0, 0),           /// 2048x1536, 1024KB YUV422, 2800ms to decode
    GFX_WBMP_LIMIT(1536, 2048, 2048),    /// 2048x1536, 390KB, 1521ms to decode
    GFX_BMP_LIMIT(2400, 50000, 40000),           /// 1024x768, 2400KB, 1375ms to decode
    GFX_GIF_LIMIT(0, 640, 640),          /// 800x600, 284KB, 1348ms to decode
    GFX_PNG_LIMIT(0, 640, 640),          /// 640x480, 590KB, 1914ms to decode
    GFX_SVG_LIMIT(200,0,0),
    GFX_M3D_LIMIT(200,0,0),
#elif defined(MT6255)
    GFX_JPG_LIMIT(12000, 4095, 4095),
    GFX_WBMP_LIMIT(1536, 2048, 2048),
    GFX_BMP_LIMIT(25000, 50000, 40000),
    GFX_GIF_LIMIT(0, 2048, 2048),
    GFX_PNG_LIMIT(0, 2047, 2047),
    GFX_SVG_LIMIT(125, 0, 0),
    GFX_M3D_LIMIT(200, 0, 0),
#else
    GFX_JPG_LIMIT(0, 0, 0),
    GFX_WBMP_LIMIT(512, 1536, 1536),
    GFX_BMP_LIMIT(512, 1536, 1536),
    GFX_GIF_LIMIT(0, 640, 640),
    GFX_PNG_LIMIT(0, 640, 640),
    GFX_SVG_LIMIT(200,0,0),
    GFX_M3D_LIMIT(200,0,0),
#endif
    END_LIMIT
};



#if 1
const signed int gfx_codec_wallpaper_limit_arry[] =
{
    GFX_BMP_LIMIT(2500, 0, 0),

#if defined(MT6260)
    GFX_JPG_LIMIT(2000, 1500, 1200),
#else
    GFX_JPG_LIMIT(2000, 0, 0),
#endif

    GFX_GIF_LIMIT(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    GFX_PNG_LIMIT(0, 1280, 960),
    GFX_SVG_LIMIT(20,0,0),
    GFX_M3D_LIMIT(20,0,0),
    END_LIMIT
};


#if (defined(DUAL_LCD) && defined(COLOR_SUBLCD))
const signed int gfx_codec_sub_wallpaper_limit_arry[] =
{
    GFX_BMP_LIMIT(2500, 0, 0),
    GFX_JPG_LIMIT(2000, 0, 0),
    GFX_GIF_LIMIT(0, SUBLCD_WIDTH, SUBLCD_HEIGHT),
    GFX_PNG_LIMIT(0, 1280, 960),
    GFX_SVG_LIMIT(20,0,0),
    GFX_M3D_LIMIT(20,0,0),
    END_LIMIT
};
#endif /*(defined(DUAL_LCD) && defined(COLOR_SUBLCD)) */

const signed int gfx_codec_screensaver_limit_arry[] =
{
    GFX_BMP_LIMIT(7000, 0, 0),
    GFX_JPG_LIMIT(3500, 0, 0),
    GFX_GIF_LIMIT(0, 1280, 960),
    GFX_PNG_LIMIT(0, 1600, 1200),
    GFX_SVG_LIMIT(20,0,0),
    GFX_M3D_LIMIT(20,0,0),
    END_LIMIT
};

const signed int gfx_codec_power_on_off_disp_limit_arry[] =
{
    GFX_BMP_LIMIT(1500, 0, 0),
    GFX_JPG_LIMIT(1800, 0, 0),
    GFX_GIF_LIMIT(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    GFX_PNG_LIMIT(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    GFX_SVG_LIMIT(20,0,0),
    GFX_M3D_LIMIT(20,0,0),
    END_LIMIT
};


//#ifdef __MMI_VIDEO_TELEPHONY__
const signed int gfx_codec_vt_img_limit_arry[] =
{
    GFX_BMP_LIMIT(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    GFX_JPG_LIMIT(896, 0, 0),
    GFX_GIF_LIMIT(896, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    GFX_PNG_LIMIT(0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT),
    END_LIMIT
};
//#endif /*__MMI_VIDEO_TELEPHONY__*/


const signed int gfx_codec_caller_picture_limit_arry[] =
{
    GFX_BMP_LIMIT(20, 0, 0),
    GFX_JPG_LIMIT(20, 0, 0),
    GFX_GIF_LIMIT(20, 0, 0),
    GFX_PNG_LIMIT(20, 0, 0),
    GFX_PNG_LIMIT(20, 0, 0),
    GFX_M3D_LIMIT(100, 0, 0),
    GFX_SVG_LIMIT(20, 0, 0),
    END_LIMIT
};


/*const signed int g_fmgr_caller_video_limit_arry[] =
{
    VDO_3GP_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_MP4_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_AVI_LIMIT_ITEM(50000, 0, 0, 0),
    VDO_SWFLASH_LIMIT_ITEM(50000, 0, 0, 0),
    END_LIMIT
};*/

const signed int gfx_codec_mms_category_limit_arry[] =
{
#if defined(MT6255)
    GFX_JPG_LIMIT(0, 2592, 1944),
#else
    GFX_JPG_LIMIT(0, 2048, 2048),
#endif
#if defined(MT6255) || defined(MT6236) || defined(MT6921)
    GFX_WBMP_LIMIT(1024, 1536, 1536),
    GFX_BMP_LIMIT(1024, 1536, 1536),
#else
    GFX_WBMP_LIMIT(512, 1536, 1536),
    GFX_BMP_LIMIT(512, 1536, 1536),
#endif
#if defined(MT6223) || defined(MT6223P) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
    GFX_GIF_LIMIT(0, 640, 640),
#else
    GFX_GIF_LIMIT(0, 800, 800),
#endif
#if defined(MT6255) || defined(MT6236) || defined(MT6921)
    GFX_PNG_LIMIT(0, 800, 1024),
#else
    GFX_PNG_LIMIT(0, 640, 640),
#endif
    GFX_SVG_LIMIT(20,0,0),
    GFX_M3D_LIMIT(200,0,0),
    END_LIMIT
};

const signed int* _get_gfx_codec_limitation_table(GFX_USER_APP_ENUM app_type)
{
   switch(app_type)
   {
     case  GFX_USER_IMAGE_VIEWER:
        return  gfx_codec_image_viewer_limit_arry;

     case  GFX_USER_WALLPAPER:
        return gfx_codec_wallpaper_limit_arry;

#if (defined(DUAL_LCD) && defined(COLOR_SUBLCD))

     case  GFX_USER_SUB_WALLPAPER:
         return gfx_codec_sub_wallpaper_limit_arry;
#endif

     case  GFX_USER_SCREEN_SAVER:
         return gfx_codec_screensaver_limit_arry;

     case  GFX_USER_POWER_ON_OFF_DISPLAY:
         return gfx_codec_power_on_off_disp_limit_arry;

     case  GFX_USER_VT_IMAGE:
         return gfx_codec_vt_img_limit_arry;

     case  GFX_USER_CALLER_PICTURE:
         return gfx_codec_caller_picture_limit_arry;

     //case  GFX_USER_CALLER_VIDEO:
     //    return gfx_codec_caller_video_limit_arry;

     case  GFX_USER_MMS_CATEGORY:
         return gfx_codec_mms_category_limit_arry;

     default:
       return NULL;
   }

   //return NULL;
}



GFX_CODEC_LIMITATION_STATUS_ENUM gfx_codec_performance_query(
   GFX_USER_APP_ENUM app_type,
   GFX_IMAGE_TYPE_ENUM type,
   signed int width,
   signed int height,
   signed int file_len,
   kal_uint32 max_operation_time) //second
{
   signed int *plimitation_table;
   signed int *check_start_ptr;

   //Currently, the max operation time shall equal to 3 because we only have related database for 3 seconds now.
   //We leave the interface for the furture to support this functionality.
   if (max_operation_time != 3)
   {
     return GFX_CODEC_LIMITATION_ERROR_MAX_OPERATION_TIME_SHALL_EQUAL_3;
   }

   if (app_type >= GFX_USER_RSVD)
   {
      return GFX_CODEC_LIMITATION_ERROR_INVALID_APP_TYPE;
   }

   if ((width == 0) || (height == 0))
   {
      return GFX_CODEC_LIMITATION_ERROR_INVALID_IMAGE_SIZE; //errcode = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
   }


   // Get limitation table
   plimitation_table = (signed int *)_get_gfx_codec_limitation_table(app_type);
   if (NULL == plimitation_table)
   {
      ASSERT(0);
   }
   check_start_ptr = plimitation_table;

   // Get resource type's information
   while (1)
   {
      if (*check_start_ptr == type)
      {
         /* find limit */
         check_start_ptr++;
         break;
      }

      check_start_ptr += GFX_CODEC_LIMITATION_ENTRY_SIZE;
      if (END_LIMIT == *check_start_ptr)
      {
         return GFX_CODEC_LIMITATION_OK; //GFX_CODEC_LIMITATION_ERROR_INVALID_RESOURCE_TYPE;
      }
   };


  // Check limitation
  {
     signed int limit_file_size = *check_start_ptr++;
     signed int limit_image_width = *check_start_ptr++;
     signed int limit_image_height = *check_start_ptr++;

     if (file_len == 0)
     {
         return GFX_CODEC_LIMITATION_ERROR_INVALID_FILE_FORMAT;
     }

    if (((limit_file_size != 0) && (file_len > (limit_file_size * 1024))) ||
         ((limit_image_width != 0) && (width > limit_image_width)) ||
         ((limit_image_height != 0) && (height > limit_image_height)))
     {
         return GFX_CODEC_LIMITATION_ERROR_IMAGE_TOO_LARGE;
     }
  }
  return GFX_CODEC_LIMITATION_OK;
}

#else //The following is 10A definition
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6225)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6238) || defined(MT6268)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
#if defined(MT6225)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6238) || defined(MT6268)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUB_WALLPAPER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6225)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6238) || defined(MT6268)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6225)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6238) || defined(MT6268)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6225)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#if defined(MT6223) || defined(MT6223P) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

