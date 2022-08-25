/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    drv_sw_features_display.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This header file defines the options for being used in SW modules 
 *    outside of display driver.
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
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 * 10 16 2012 chrono.wu
 * removed!
 * .
 *
 * 06 11 2012 dong.guo
 * removed!
 * .
 *
 * 06 08 2012 haitao.shang
 * removed!
 * .
 *
 * 05 22 2012 haitao.shang
 * removed!
 * .
 *
 * 05 07 2012 xiaoyong.ye
 * removed!
 * 
 * Define __GOVL_SUPPORT__ only when G2D_HW_SHARE_WITH_GOVL_SUPPORT for MT6250.
 *
 * 04 17 2012 dong.guo
 * removed!
 * .
 *
 * 03 21 2012 xiaoyong.ye
 * removed!
 * Check in MT6250 G2D low light flatten driver.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 11 29 2011 haitao.shang
 * removed!
 * removed!
 * [MT6255]GOVL support check in
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 * 08 04 2011 zifeng.qiu
 * removed!
 * For lcmmi use v1 option.
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 07 12 2011 bin.han
 * removed!
 * .
 *
 * 03 17 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 bin.han
 * removed!
 * .MT6256 LCD driver code first check in
 *
 * 03 03 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 22 2011 chelun.tsai
 * removed!
 * lcd drv feature, sw feature, mutual include remove.
 *
 * 01 28 2011 sophie.chen
 * removed!
 * .
 *
 * 01 27 2011 chelun.tsai
 * removed!
 * modify 6268 layer format for GDI.
 *
 * 01 25 2011 chelun.tsai
 * removed!
 * .
 *
 * 01 06 2011 chelun.tsai
 * removed!
 * .
 *
 * 01 04 2011 chelun.tsai
 * removed!
 * .
 *
 * 01 04 2011 chelun.tsai
 * removed!
 * move LCD_WMEM_XXX & LCD_LAYER_SOURCE_COLOR_XXX to drv_sw_features_display.h.
 *
 * 12 24 2010 chelun.tsai
 * removed!
 * .
 *
 * 12 24 2010 chelun.tsai
 * removed!
 * MT6251 use DDv1.
 *
 * 12 23 2010 tianshu.qiu
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 11 24 2010 ct.fang
 * removed!
 * .
 *
 * 11 23 2010 chelun.tsai
 * removed!
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_SW_FEATURES_DISPLAY_H__
#define __DRV_SW_FEATURES_DISPLAY_H__

#include "drv_features_chip_select.h"
#include "drv_features_g2d.h"

// TODO: review which options are to be used outside of display driver.

#ifdef __MTK_TARGET__
/**
 *  \def DRV_DISPLAY_DRIVER_V1
 *  If this is defined, DDv1 API is working, so please display driver users 
 *  use DDv1 API. This is for external use.
 *  \remark This macro should be mutual exclusive to DRV_DISPLAY_DRIVER_V2...
 */
  #undef DRV_DISPLAY_DRIVER_V1

/**
 *  \def DRV_DISPLAY_DRIVER_V2
 *  If this is defined, DDv2 API is working, so please display driver users 
 *  use DDv2 API. This is for external use.
 *  \remark This macro should be mutual exclusive to DRV_DISPLAY_DRIVER_V1
 */
  #define DRV_DISPLAY_DRIVER_V2

#else /* __MTK_TARGET__ */

  #ifdef NEPTUNE_MMI
      #define DRV_DISPLAY_DRIVER_V1
      #undef  DRV_DISPLAY_DRIVER_V2
  #else //#ifdef NEPTUNE_MMI
      #undef  DRV_DISPLAY_DRIVER_V1
      #define DRV_DISPLAY_DRIVER_V2
  #endif //#ifdef NEPTUNE_MMI

#endif /* __MTK_TARGET__ */

/**
 *  \def LCD_WMEM_xxx 
 *  Feature options for GDI to know LCD support w2m output format. 
 *  Do not do any define if LCD not support.
 *  \remark These macros are bit mapping to LCD register.
 */   
   #undef LCD_WMEM_RGB565
   #undef LCD_WMEM_RGB888
   #undef LCD_WMEM_ARGB8888
   #undef LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA

/**
 *  \def LCD_LAYER_SOURCE_COLOR_xxx
 *  Feature options for GDI to know LCD support layer input format.
 *  Do not do any define if LCD not support.
 *  \remark These macros are bit mapping to LCD register.
 */   
   #undef LCD_LAYER_SOURCE_COLOR_8BPP_INDEX
   #undef LCD_LAYER_SOURCE_COLOR_RGB565
   #undef LCD_LAYER_SOURCE_COLOR_YUYV422
   #undef LCD_LAYER_SOURCE_COLOR_UYVY422
   #undef LCD_LAYER_SOURCE_COLOR_RGB888
   #undef LCD_LAYER_SOURCE_COLOR_ARGB8888
   #undef LCD_LAYER_SOURCE_COLOR_PARGB8888
   #undef LCD_LAYER_SOURCE_COLOR_XRGB8888
   #undef LCD_LAYER_SOURCE_MONO


#ifdef __MTK_TARGET__

/* MT6235 */
#if defined(DRV_LCD_MT6235_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_MONO              (4)
  
  #define LCD_LAYER_MAX_WIDTH                (0x3FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x3FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x3FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x3FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (6)
  #define DRV_PALETTE_COUNT	                 (1)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif //end of DRV_LCD_MT6235_SERIES


/* MT6236 */
#if defined(DRV_LCD_MT6236_SERIES)  
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_MONO              (6)
  #define __GOVL_SUPPORT__
  
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (0)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif //end of DRV_LCD_MT6236_SERIES
  
  
/* MT6250 */
#if defined(DRV_LCD_MT6250_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4) //alpha is a contant value
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6) //wrong definition, should be LCD_WMEM_PARGB8888, keep this due to HAL rule
  #define LCD_WMEM_PARGB8888                  
  #define LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA  //the same as LCD_WMEM_PARGB8888
  #define LCD_WMEM_ARGB6666                  
  #define LCD_WMEM_PARGB6666             
  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_COLOR_ARGB6666    (6)
  #define LCD_LAYER_SOURCE_COLOR_PARGB6666   (7)
  #define LCD_LAYER_SOURCE_MONO              (8)
      
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)
  
  #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
  #define __GOVL_SUPPORT__
  #define DRV_DISPLAY_DRIVER_CONSTANT_VALUE_SUPPORT
  #define FLATTEN_DRIVER_CONTEXT_DITHER_SUPPORT
  #endif
      
  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
    
  #define FLATTEN_WMEM_ARGB6666                  
  #define FLATTEN_WMEM_PARGB6666 
  
  #define FLATTEN_LAYER_SOURCE_COLOR_ARGB6666 
  #define FLATTEN_LAYER_SOURCE_COLOR_PARGB6666  
  
    
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (1)
      
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #define DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB6666_SUPPORT
  
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6250_SERIES  

  
/* MT6260 */
#if defined(DRV_LCD_MT6260_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4) //alpha is a contant value
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6) //wrong definition, should be LCD_WMEM_PARGB8888, keep this due to HAL rule
  #define LCD_WMEM_PARGB8888                  
  #define LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA  //the same as LCD_WMEM_PARGB8888
  #define LCD_WMEM_ARGB6666                  
  #define LCD_WMEM_PARGB6666             
  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_COLOR_ARGB6666    (6)
  #define LCD_LAYER_SOURCE_COLOR_PARGB6666   (7)
  #define LCD_LAYER_SOURCE_MONO              (8)
      
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)
  
  #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
  #define __GOVL_SUPPORT__
  #define DRV_DISPLAY_DRIVER_CONSTANT_VALUE_SUPPORT
  #define FLATTEN_DRIVER_CONTEXT_DITHER_SUPPORT
  #endif
      
  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
    
  #define FLATTEN_WMEM_ARGB6666                  
  #define FLATTEN_WMEM_PARGB6666 
  
  #define FLATTEN_LAYER_SOURCE_COLOR_ARGB6666 
  #define FLATTEN_LAYER_SOURCE_COLOR_PARGB6666  
  
    
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (1)
      
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #define DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB6666_SUPPORT
  
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6260_SERIES  
  
/* MT6251 */
#if defined(DRV_LCD_MT6251_SERIES)
  #define DRV_DISPLAY_DRIVER_V1  // MT6251 use DDv1
  #undef  DRV_DISPLAY_DRIVER_V2
  
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)
  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  
  #define  LCD_LAYER_MAX_WIDTH               (0x3FF)
  #define  LCD_LAYER_MAX_HEIGHT              (0x3FF)
  #define  LCD_LAYER_MAX_OFFSETX             (0x3FF)
  #define  LCD_LAYER_MAX_OFFSETY             (0x3FF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (2)
  #define DRV_PALETTE_COUNT	                 (1)
  
  #define DRV_LAYER_COLOR_FORMAT	           /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE							     /* support LCD layer rotate or not */
  #define DRV_PALETTE_RGB_565						     /* support color palette up to RGB565 */
  #undef  DRV_PALETTE_RGB_888	               /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  
  #undef DRV_LCD_MEMORY_OUTPUT  
  #if (defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST))
    #define DRV_LCD_MEMORY_OUTPUT
  #endif
  
  #undef DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #undef DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6251_SERIES

/* MT6252 */
#if defined(DRV_LCD_MT6252_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)
  #define LCD_WMEM_PARGB8888                 (0x6)

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_COLOR_XRGB8888    (6)
  #define LCD_LAYER_SOURCE_MONO              (7)
  
  #define LCD_LAYER_MAX_WIDTH                (0x3FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x3FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x3FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x3FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (1)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6252_SERIES

/* MT6253 */
#if defined(DRV_LCD_MT6253_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)      

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_MONO              (4)
  
  #define LCD_LAYER_MAX_WIDTH                (0x3FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x3FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x3FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x3FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (1)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6253_SERIES


/* MT6268 */
#if defined(DRV_LCD_MT6268_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)      

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  
  #define LCD_LAYER_MAX_WIDTH                (0x3FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x3FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x3FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x3FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (6)
  #define DRV_PALETTE_COUNT	                 (1)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  
  #if defined(MT6268) || defined(MT6268A)
    #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #elif defined(MT6268H) || defined(MT6268T)
    #undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #else   // default case
    #undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #endif  // chip options
  
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6268_SERIES


/* MT6276 */
#if defined(DRV_LCD_MT6276_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_MONO              (6)
  #define __GOVL_SUPPORT__
  #define DRV_DISPLAY_DRIVER_CONSTANT_VALUE_SUPPORT
  
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)

  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (0)
  
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6276_SERIES


  /* MT6256 */
#if defined(DRV_LCD_MT6256_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)
  #define LCD_WMEM_PARGB8888                  (LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA)

  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_MONO              (6)
    
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)
  
  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (0)
    
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #undef DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6256_SERIES

  /* MT6255 */
#if defined(DRV_LCD_MT6255_SERIES)
  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)
  #define LCD_WMEM_PARGB8888                  (LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA)

  
  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_MONO              (6)
    
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #if defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT)
  #define __GOVL_SUPPORT__
  #define DRV_DISPLAY_DRIVER_CONSTANT_VALUE_SUPPORT
  #endif

  
  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)
  
  
  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (0)
    
  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #undef DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6255_SERIES

  /* MT6516 */
#if defined(DRV_LCD_MT6516_SERIES)
  #define LCD_LAYER_MAX_WIDTH                (0x3FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x3FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x3FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x3FF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x3FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x3FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x3FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)

  #define DRV_LAYER_TOTAL_COUNT              (6)
  #define DRV_PALETTE_COUNT	                 (1)
  #define DRV_LAYER_COLOR_FORMAT					   /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE							     /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565							   /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888						     /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
#endif  //end of DRV_LCD_MT6516_SERIES


  /* MT6573 */
#if defined(DRV_LCD_MT6573_SERIES)
  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)

  #define DRV_LAYER_TOTAL_COUNT              (4)
  #define DRV_PALETTE_COUNT	                 (0)
  #define DRV_LAYER_COLOR_FORMAT					   /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE							     /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565							   /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888						     /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN
#endif  //end of DRV_LCD_MT6573_SERIES

/* Modis */
#else   //#ifdef __MTK_TARGET__

  #define LCD_WMEM_RGB565                    (0x0)
  #define LCD_WMEM_RGB888                    (0x2)
  #define LCD_WMEM_ARGB8888                  (0x4)    //alpha is a contant value
  #define LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA (0x6)    //wrong definition, should be LCD_WMEM_PARGB8888, keep this due to HAL rule

  #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX  (0)
  #define LCD_LAYER_SOURCE_COLOR_RGB565      (1)
  #define LCD_LAYER_SOURCE_COLOR_YUYV422     (2)
  #define LCD_LAYER_SOURCE_COLOR_UYVY422     (2)
  #define LCD_LAYER_SOURCE_COLOR_RGB888      (3)
  #define LCD_LAYER_SOURCE_COLOR_ARGB8888    (4)
  #define LCD_LAYER_SOURCE_COLOR_PARGB8888   (5)
  #define LCD_LAYER_SOURCE_MONO              (6)

  #define LCD_LAYER_MAX_WIDTH                (0x7FF)
  #define LCD_LAYER_MAX_HEIGHT               (0x7FF)
  #define LCD_LAYER_MAX_OFFSETX              (0x7FF)
  #define LCD_LAYER_MAX_OFFSETY              (0x7FF)
  #define LCD_LAYER_MAX_ALPHA                (0xFF)

  #define FLATTEN_LAYER_MAX_WIDTH            (0x7FF)
  #define FLATTEN_LAYER_MAX_HEIGHT           (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETX          (0x7FF)
  #define FLATTEN_LAYER_MAX_OFFSETY          (0x7FF)
  #define FLATTEN_LAYER_MAX_ALPHA            (0xFF)

  #define DRV_LAYER_TOTAL_COUNT              (6)
  #define DRV_PALETTE_COUNT                  (0)

  #define DRV_LAYER_COLOR_FORMAT             /* support RGB888/ARGB8888 or not */
  #define DRV_LAYER_ROTATE                   /* support LCD layer rotate or not */
  #undef DRV_PALETTE_RGB_565                 /* support color palette up to RGB565 */
  #define DRV_PALETTE_RGB_888                /* support color palette up to RGB888 */
  #define DRV_LCD_ROI_BACKGROUND_COLOR
  #define DRV_LCD_MEMORY_OUTPUT
  #define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
  #define DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
  #define DRV_LCD_4_BYTES_ALIGN

#if defined(DRV_LCD_MT6250_SERIES)
  
  #define LCD_WMEM_PARGB8888                  
  #define LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA  //the same as LCD_WMEM_PARGB8888
  #define LCD_WMEM_ARGB6666                  //alpha is a contant value
  #define LCD_WMEM_PARGB6666                 //alpha is pixel alpha

  
  #define LCD_LAYER_SOURCE_COLOR_ARGB6666    (6)
  #define LCD_LAYER_SOURCE_COLOR_PARGB6666   (7)   

  #define DRV_LCD_MEMORY_OUTPUT_PARGB6666_SUPPORT
  

#endif  //end of DRV_LCD_MT6250_SERIES  

#if defined(DRV_LCD_MT6260_SERIES)
  
  #define LCD_WMEM_PARGB8888                  
  #define LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA  //the same as LCD_WMEM_PARGB8888
  #define LCD_WMEM_ARGB6666                  //alpha is a contant value
  #define LCD_WMEM_PARGB6666                 //alpha is pixel alpha

  
  #define LCD_LAYER_SOURCE_COLOR_ARGB6666    (6)
  #define LCD_LAYER_SOURCE_COLOR_PARGB6666   (7)   

  #define DRV_LCD_MEMORY_OUTPUT_PARGB6666_SUPPORT
  

#endif  //end of DRV_LCD_MT6260_SERIES  

#endif

#endif  /* End __DRV_SW_FEATURES_DISPLAY_H__ */

