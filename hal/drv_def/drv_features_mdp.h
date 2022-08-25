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
 *    drv_features_mdp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver features.
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2014 chrono.wu
 * removed!
 * 	.
 *
 * 03 25 2013 chrono.wu
 * removed!
 * MT6260 WVGA Camera features support full screen.
 *
 * 12 13 2012 peter.wang
 * removed!
 * .
 * 
 * 09 27 2012 peter.wang
 * removed!
 * .
 * 
 * 09 24 2012 peter.wang
 * removed!
 * .
 * 
 * 04 20 2012 peter.wang
 * removed!
 * .
 *
 * 02 24 2012 peter.wang
 * removed!
 * .
 *
 * 02 23 2012 peter.wang
 * removed!
 * .
 *
 * 02 23 2012 peter.wang
 * removed!
 * .
 *
 * 02 16 2012 peter.wang
 * removed!
 * .
 *
 * 01 05 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 30 2011 chelun.tsai
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 24 2011 chelun.tsai
 * removed!
 * .
 *
 * 10 27 2011 chrono.wu
 * removed!
 * .
 *
 * 10 14 2011 chelun.tsai
 * removed!
 * .
 *
 * 09 21 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 25 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 18 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 18 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 08 17 2011 peter.wang
 * removed!
 * .
 *
 * 08 08 2011 peter.wang
 * removed!
 * .
 *
 * 08 05 2011 chrono.wu
 * removed!
 * .
 *
 * 06 16 2011 chrono.wu
 * removed!
 * .
 *
 * 03 30 2011 chrono.wu
 * removed!
 * .
 *
 * 03 16 2011 chelun.tsai
 * removed!
 * add MT6256 E1, E2 chip features.
 *
 * 03 09 2011 chrono.wu
 * removed!
 * .
 *
 * 01 26 2011 cm.huang
 * removed!
 * .
 *
 * 01 19 2011 cm.huang
 * removed!
 * .
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 27 2010 cm.huang
 * removed!
 * .
 *
 * 12 24 2010 cm.huang
 * removed!
 * .
 *
 * 12 13 2010 chrono.wu
 * removed!
 * .
 *
 * 11 29 2010 cm.huang
 * removed!
 * .
 *
 * 11 24 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 18 2010 cm.huang
 * removed!
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 ****************************************************************************/


#ifndef __DRV_FEATURES_MDP_H__
#define __DRV_FEATURES_MDP_H__

#include "drv_features_chip_select.h"
#include "lcd_sw_inc.h"
#include "sensor_capability.h"

/**********************************
 * Chip-independent IDP driver definition section
 **********************************/
#undef DRV_RGB_RESIZE_SUPPORT
#undef DRV_BLOCK_EFFECT_SUPPORT
#undef DRV_PIXEL_EFFECT_SUPPORT

/**
 *  \def MDP_SUPPORT_FAST_POWER_ON_OFF
 *  If this is defined, it means video renderer will power on/off mdp engines
 *  when mdp frame start/end to save power
 */
#undef MDP_SUPPORT_FAST_POWER_ON_OFF

/**
 *  \def MDP_SUPPORT_VP_EMI_BW_SWITCH
 *  If this is defined, it means video renderer will switch EMI BW 
 *  when renderer start/stop to release EMI BW to other modules.
 */
#undef MDP_SUPPORT_VP_EMI_BW_SWITCH

#if defined(DRV_IDP_6235_SERIES)
#define DRV_IDP_SUPPORT      
#if defined(__MTK_TARGET__)
/**
 *  \def DRV_IDP_CRZ_HW_LIMITATION_1500_992
 *  If this is defined, it means this project's CRZ HW has the a special HW limitation. 
 *  When down sizing, source size over 1500, and ratio overs 0.992, the result 
 *  will have problems.
 */
#define DRV_IDP_CRZ_HW_LIMITATION_1500_992
#endif  // #if defined(__MTK_TARGET__)
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
#define CONTOUR_IMPROVEMENT_MT6235
#endif

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#undef USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL
#undef MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#undef MDP_SUPPORT_HW_OVERLAP_INTERNAL

#endif // #if defined(DRV_IDP_6235_SERIES)


#if defined(DRV_IDP_MT6236_SERIES)
#define DRV_IDP_SUPPORT

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT

#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF

#if defined(__MTK_TARGET__)
/**
 *  \def DRV_IDP_THUMBNAIL_COLOR_FORMAT_BGR888
 *  This option describes the thumbnail color format supported by IDP is BGR888. 
 *  B in high byte. This or DRV_IDP_THUMBNAIL_COLOR_FORMAT_RGB888 must be 
 *  defined in any chip IDP supports JPEG encoding.
 */
#define DRV_IDP_THUMBNAIL_COLOR_FORMAT_BGR888
#endif  // #if defined(__MTK_TARGET__)

/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
 *  When this option is defined, MDP driver supports rotation and mirror 
 *  functions on display output path. In MT6236, it needs resource manager.
 */
#if defined(__RESOURCE_MANAGER__)
#define DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
#else   // #if defined(__RESOURCE_MANAGER__)
#undef DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
#endif  // #if defined(__RESOURCE_MANAGER__)

/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR
 *  If defined, MDP driver supports rotation and mirror functions on video 
 *  frame buffer output.
 */
//#define DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR
#endif // #if defined(DRV_IDP_MT6236_SERIES)


#if defined(DRV_IDP_6238_SERIES)
/***** MT6238 series MDP COMMON START *****************************************/
#define DRV_IDP_SUPPORT       

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT

#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#if defined(DRV_BLOCK_EFFECT_SUPPORT)
#define DRV_BLOCK_EFFECT_SW_SUPPORT
#endif  // #if defined(DRV_BLOCK_EFFECT_SUPPORT)

/**
 *  \def DRV_IDP_THUMBNAIL_COLOR_FORMAT_RGB888
 *  This option describes the thumbnail color format supported by IDP is RGB888. 
 *  R in high byte. This or DRV_IDP_THUMBNAIL_COLOR_FORMAT_BGR888 must be 
 *  defined in any chip IDP supports JPEG encoding.
 */
#define DRV_IDP_THUMBNAIL_COLOR_FORMAT_RGB888

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#undef USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL

/***** MT6238 series MDP COMMON END *******************************************/

#if defined(MT6268) 
#if defined(__MTK_TARGET__)

/**
 *  \def DRV_IDP_FEATURE__HW_FRAME_SYNC
 *  When defined, MDP HW frame sync function is supported.
 */
#define DRV_IDP_FEATURE__HW_FRAME_SYNC

#endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(MT6268) 


#if defined(MT6268) || defined(MT6268A)
#if defined(__MTK_TARGET__)
/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
 *  When this option is defined, MDP driver supports rotation and mirror 
 *  functions on display output path.
 */
//#define DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR

/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR
 *  If defined, MDP driver supports rotation and mirror functions on video 
 *  frame buffer output.
 */
//#define DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR

#endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(MT6268) || defined(MT6268A)
#endif // #if defined(DRV_IDP_6238_SERIES)


#if defined(DRV_IDP_6252_SERIES)
#define DRV_IDP_SUPPORT
//#define MDP_FW_TRIGGER_LCD    //DDV1, no use now

#undef DRV_RGB_RESIZE_SUPPORT
#undef DRV_BLOCK_EFFECT_SUPPORT
#undef DRV_PIXEL_EFFECT_SUPPORT

#undef MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#undef MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#undef MDP_SUPPORT_HW_OVERLAP_INTERNAL
#define MDP_SUPPORT_FAST_POWER_ON_OFF

/* USE 2 pass to break ROTDMA 90 degree source width cannot > 320(MT6252) or 480(MT6250) */
#if defined(MT6252H) || defined(MT6252)
  #if (LCD_HEIGHT > 320) || (LCD_WIDTH > 320)
    #define IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK
  #endif
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
  #if (LCD_HEIGHT > 480) || (LCD_WIDTH > 480)
    #define IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK
  #endif
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
  #if defined(__IMAGE_SENSOR_2M__) || defined(__IMAGE_SENSOR_1M__) || (LCD_HEIGHT > 480) || (LCD_WIDTH > 480)
    #define IDP_TILE_MODE_SUPPORT
    #if (LCD_HEIGHT > 480) || (LCD_WIDTH > 480)
      #define IDP_CAM_PREVIEW_TILEMODE_2PASS_SUPPORT
    #endif
  #endif
  #if defined(__DRV_COLOR_MT6260_SERIES__)
    #define IDP_MM_COLOR_SUPPORT
  #endif
#endif

#endif // #if defined(DRV_IDP_6252_SERIES)


#if defined(DRV_IDP_6253_SERIES)
#define DRV_IDP_SUPPORT
//#define MDP_FW_TRIGGER_LCD    //DDV1, no use now

#undef DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
#undef DRV_PIXEL_EFFECT_SUPPORT

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#undef USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL
#undef MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#undef MDP_SUPPORT_HW_OVERLAP_INTERNAL

#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
#define CONTOUR_IMPROVEMENT_MT6253
#define CONTOUR_IMPROVEMENT_MT6253_SLIM  //use 1 lcd frmae buffer + 1 working buffer
#endif

#endif // #if defined(DRV_IDP_6253_SERIES)


#if defined(DRV_IDP_MT6256_SERIES)

#if defined(MT6256_S00)             // E1 series
  #define DRV_IDP_MT6256_E1_SERIES
#else                               // E2 and later series 
  #define DRV_IDP_MT6256_E2_SERIES
#endif

#define DRV_IDP_SUPPORT    

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL
#define MDP_SUPPORT_FAST_POWER_ON_OFF
#define MDP_SUPPORT_VP_EMI_BW_SWITCH

#endif // #if defined(DRV_IDP_MT6256_SERIES)


#if defined(DRV_IDP_MT6255_SERIES)

#define DRV_IDP_SUPPORT    

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF
#endif // #if defined(DRV_IDP_MT6255_SERIES)



#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)
#define DRV_IDP_SUPPORT         

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define  MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF

#endif // #if defined(DRV_IDP_MT6276_SERIES)

#endif   /*End __DRV_FEATURES_MDP_H__*/
