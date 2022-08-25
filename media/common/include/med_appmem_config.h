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
 * med_appmem_config.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes applications requiring MED memory definitions.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if !defined(MED_MEM_CHECK)
#include "kal_release.h"
#include "kal_general_types.h"
#endif

#include "lcd_Sw_inc.h"
#include "mmi_features.h"

#if !defined(NEPTUNE_MMI)
#if defined(JPG_DECODE) || defined(JPG_ENCODE)
#include "gdi_const.h"
#endif
#endif

/******************************************************
 * 1. JPEG DECODE
 ******************************************************/
#if !defined(NEPTUNE_MMI)
    #if defined(JPG_DECODE)
        #define MAX_JPEG_DEC_EXT_MEM_SIZE (GDI_MED_MEM_SIZE)
    #else
        #define MAX_JPEG_DEC_EXT_MEM_SIZE (0)
    #endif
#else
    #define MAX_JPEG_DEC_EXT_MEM_SIZE (0)
#endif


/******************************************************
 * 2. JPEG ENCODE
 ******************************************************/
#if !defined(NEPTUNE_MMI)
    #if defined(JPG_ENCODE)
        #define MAX_MED_JPG_ENC_EXT_MEM_SIZE (GDI_MED_MEM_SIZE)
    #else
        #define MAX_MED_JPG_ENC_EXT_MEM_SIZE (0)
    #endif
#else
    #define MAX_MED_JPG_ENC_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 3. PNG Decode
 **************************************************************/
#if !defined(NEPTUNE_MMI)
    #if defined(USE_HW_PNG_DECODER) || defined(USE_SW_PNG_DECODER)
        #include "png_memory_usage.h"
        #define MAX_PNG_MAX_EXT_MEM_SIZE  PNG_MAX_EXT_MEM_SIZE
        #define MAX_PNG_MAX_INT_MEM_SIZE  PNG_MAX_INT_MEM_SIZE        
    #else
        #define MAX_PNG_MAX_EXT_MEM_SIZE  0
        #define MAX_PNG_MAX_INT_MEM_SIZE  0        
    #endif
#else
    #define MAX_PNG_MAX_EXT_MEM_SIZE  0
    #define MAX_PNG_MAX_INT_MEM_SIZE  0        
#endif

#if MAX_PNG_MAX_EXT_MEM_SIZE > MAX_JPEG_DEC_EXT_MEM_SIZE 
    #define MAX_MED_JPG_DEC_EXT_MEM_SIZE (MAX_PNG_MAX_EXT_MEM_SIZE)
#else
    #define MAX_MED_JPG_DEC_EXT_MEM_SIZE (MAX_JPEG_DEC_EXT_MEM_SIZE)
#endif


/**************************************************************
 * 4. MMS Resize image
 **************************************************************/
#if defined (MMS_SUPPORT)
#if defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __160x120__)
    #define MMS_RESIZE_BUF_SIZE (160*120*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (160*120*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
#elif defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__)
    #define MMS_RESIZE_BUF_SIZE (320*240*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (320*240*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
#else /* default: __640x480__ */
    #define MMS_RESIZE_BUF_SIZE (640*480*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (640*480*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
    
    
#endif
    #define MAX_IMG_ENC_FILE_BUFFER_LEN   (LCD_WIDTH*LCD_HEIGHT)    /* File buffer size for JPG encode. */
    
    #if MAX_IMG_ENC_FILE_BUFFER_LEN < 300*1024
        #undef MAX_IMG_ENC_FILE_BUFFER_LEN
        #define MAX_IMG_ENC_FILE_BUFFER_LEN 300*1024
    #endif
    #define MMS_ENC_EXT_MEM_SIZE (MAX_IMG_ENC_FILE_BUFFER_LEN+MMS_ENCODE_YUV_SIZE)
    
    #if MAX_MED_JPG_DEC_EXT_MEM_SIZE > MMS_ENC_EXT_MEM_SIZE
        #define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (MMS_RESIZE_BUF_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE)
    #else
        #define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (MMS_RESIZE_BUF_SIZE + MMS_ENC_EXT_MEM_SIZE)
    #endif
#else
#define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (0)
#endif


/**************************************************************
 * 5. Image Viewer
 **************************************************************/
#if defined(__IMAGE_VIEWER_EX__) || defined(__IMAGE_VIEWER_EX_DB__) || defined(__IMAGE_VIEWER_STANDARD__)
    #if defined(MMI_MAIN_LCD_DEFAULT_FORMAT)
        #if (MMI_MAIN_LCD_DEFAULT_FORMAT == 24 || (defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24))
            #define MAINLCD_BYTE_PER_PIXEL 3
        #elif (MMI_MAIN_LCD_DEFAULT_FORMAT == 32)
            #define MAINLCD_BYTE_PER_PIXEL 4
        #elif (MMI_MAIN_LCD_DEFAULT_FORMAT == 16)
            #define MAINLCD_BYTE_PER_PIXEL 2
        #else
            #error "please check MMI_MAIN_LCD_DEFAULT_FORMAT value"
        #endif
    #else /* defined(MMI_MAIN_LCD_DEFAULT_FORMAT) */
        #define MAINLCD_BYTE_PER_PIXEL 2
    #endif /* defined(MMI_MAIN_LCD_DEFAULT_FORMAT) */
#endif /* defined(__IMAGE_VIEWER_EX__) || defined(__IMAGE_VIEWER_EX_DB__) || defined(__IMAGE_VIEWER_STANDARD__) */

#ifndef __MED_IN_ASM__
#if defined(__IMAGE_VIEWER_EX__) || defined(__IMAGE_VIEWER_EX_DB__)
#if (__MMI_IMAGE_VIEWER_EX_MEM_SRC__ == MMI_IMAGE_VIEWER_EX_MEM_SRC_ASM)
    #define MAX_IVEX_MEM_SIZE (0)
#else
    #if defined(__IMAGE_VIEWER_EX_MEM_SLIM__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        #define MAX_IVEX_LCD_CACHE_NUM      1
        #define MAX_IVEX_LARGE_CACHE_NUM    4
    #else
        #define MAX_IVEX_LCD_CACHE_NUM      3
        #define MAX_IVEX_LARGE_CACHE_NUM    9
    #endif

    #if (__MMI_IMAGE_VIEWER_EX_MEM_SRC__ == MMI_IMAGE_VIEWER_EX_MEM_SRC_MED)

        #ifdef __MMI_IMGVIEWEX_DB__
            #if defined(__MMI_SRV_MEDIA_CACHE_USE_SRV_IES__) && defined(__MMI_SRV_IES_META_DB__)
                #define IVEX_DB_BUFFER_EXT_SIZE      (680 * 1024)
            #else
                #define IVEX_DB_BUFFER_EXT_SIZE      (0)
            #endif

            #define IVEX_DB_BUFFER_SIZE     (320*1024 + 4 + LCD_WIDTH * LCD_HEIGHT* MAINLCD_BYTE_PER_PIXEL * 2 \
                                               + IVEX_DB_BUFFER_EXT_SIZE)
        #else
            #define IVEX_DB_BUFFER_SIZE     (0)
        #endif

        #define MAX_IVEX_MEM_SIZE \
        (LCD_WIDTH * LCD_HEIGHT* MAINLCD_BYTE_PER_PIXEL * (MAX_IVEX_LARGE_CACHE_NUM + MAX_IVEX_LCD_CACHE_NUM)\
           + IVEX_DB_BUFFER_SIZE + 300)
    #else
        #define MAX_IVEX_MEM_SIZE (LCD_WIDTH * LCD_HEIGHT* MAINLCD_BYTE_PER_PIXEL * MAX_IVEX_LARGE_CACHE_NUM + 300)
    #endif

    #endif
#elif defined(__IMAGE_VIEWER_STANDARD__)
    #define MMI_IV_CACHE_UNIT_SIZE      (LCD_WIDTH * LCD_HEIGHT * MAINLCD_BYTE_PER_PIXEL)
    #if defined(__MMI_IMGVIEW_CACHE__)
        #define MMI_IV_CACHE_MULTIPLE   (6)
    #else
        #define MMI_IV_CACHE_MULTIPLE   (4)
    #endif
    #define MMI_IV_CACHE_SIZE           (MMI_IV_CACHE_UNIT_SIZE * MMI_IV_CACHE_MULTIPLE)
    #define MAX_IVEX_MEM_SIZE           (MMI_IV_CACHE_SIZE)
#else
    #define MAX_IVEX_MEM_SIZE (0)
#endif
#else /* __MED_IN_ASM__ */
    #define MAX_IVEX_MEM_SIZE (0)
#endif /* __MED_IN_ASM__ */


/**************************************************************
 * 6. MRE(CVM) 
 **************************************************************/
//#if defined(__MRE_MEDIA_BUF__)
//      #include "vmopt.h"
//      #define MAX_MRE_EXT_MEM_SIZE    (MRE_SYS_MED_MEMPOOL_SIZE)
//#else
//    #define MAX_MRE_EXT_MEM_SIZE    (0)
//#endif
#define MAX_MRE_EXT_MEM_SIZE    (0)


/**************************************************************
 * 7. Venus UI Engine
 **************************************************************/
#if defined(__VENUS_UI_ENGINE__)
    #include "vfx_sys_config.h"
    #define MAX_VRT_EXT_MEM_SIZE (VFX_SYS_MEM_VRT_SIZE)
#else     
    #define MAX_VRT_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 8. Gadget
 **************************************************************/
#if defined(__GADGET_SUPPORT__)
    /* Idle screen +GADGET, Need to concurrent with VRT and MED audio */
    #define GADGET_IDLE_SCREEN_MEM_SIZE (1*1024*1024)
    /* Full screen +GADGET, Need to concurrent with MED video */
    #if defined(__MED_VID_MOD__)
    /* LCD size * 32bit layer * 2 + Video (LCD_SIZE / 2 * 16 bit * 2) + Cario (LCD_SIZE * 16 bit) */
        #define GADGET_FULL_SCREEN_MEM_SIZE ((LCD_WIDTH*LCD_HEIGHT*4*2) + (LCD_WIDTH*LCD_HEIGHT*4)) 
    #else
        #define GADGET_FULL_SCREEN_MEM_SIZE (LCD_WIDTH*LCD_HEIGHT*4*2) /* 32bit layer * 2 */
    #endif

#else
    #define GADGET_IDLE_SCREEN_MEM_SIZE (0)
    #define GADGET_FULL_SCREEN_MEM_SIZE (0)
#endif


/******************************************************
 * 9. Media cache IES buffer 
 ******************************************************/
#if defined(__SCALADO_SUPPORT__)
    #if defined(__MMI_SRV_MEDIACACHE__) && !defined(OPERA_BROWSER)
        #if defined(__MMI_SRV_IES_META__)
            #define MEDIACACHE_IES_MEM_SIZE (9437184)  // 9 MB
        #else
            #define MEDIACACHE_IES_MEM_SIZE (7061385)  // 6.7 MB
        #endif
    #else
        #define MEDIACACHE_IES_MEM_SIZE (0)
    #endif /* defined(__MMI_SRV_MEDIACACHE__) */
#else
    #define MEDIACACHE_IES_MEM_SIZE (0)
#endif
#define MAX_MED_MEDIACACHE_IES_EXT_MEM_SIZE (MEDIACACHE_IES_MEM_SIZE)

/******************************************************
 * 10. Video Live Wallpaper
 ******************************************************/
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined(__MED_IN_ASM__)
    #define VIDEO_LIVE_WALLPAPER_MEM_SIZE (LCD_WIDTH * LCD_HEIGHT * 2)
#else
    #define VIDEO_LIVE_WALLPAPER_MEM_SIZE (0)
#endif
#define MAX_MED_VIDEO_LIVE_WALLPAPER_EXT_MEM_SIZE (VIDEO_LIVE_WALLPAPER_MEM_SIZE)

/**************************************************************
 * 11. MUST Put at the LAST. Java Shares Media External Buffer
 **************************************************************/
#if 0 /* for pluto memory 2.0 */
#if defined(__J2ME__) && defined(J2ME_SHARE_MED_EXT_MEM)
/* under construction !*/
#if defined(JPG_DECODE) || defined(JPG_ENCODE)
/* under construction !*/
#else
    #ifndef JPEG_SW_DEC_EXT_MIN_MEM_SIZE
/* under construction !*/
    #endif
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef J2ME_SLIM_MEMORY_SUPPORT
/* under construction !*/
    #else
/* under construction !*/
    #endif /* J2ME_SLIM_MEMORY_SUPPORT */
#else
/* under construction !*/
#endif
#endif

/**************************************************************
 * 12. Widget Key - Image Viewer
 **************************************************************/
#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)
    #include "..\..\..\venusmmi\app\pluto_variation\LauncherKey\widget\ImageViewer\vapp_widget_key_image_viewer_mem_cfg.h"
    #define MAX_WIDGET_KEY_IMAGE_VIEWER_MEM_SIZE (VAPP_WIDGET_KEY_IMAGE_VIEWER_MED_MEM_SIZE)
#else
    #define MAX_WIDGET_KEY_IMAGE_VIEWER_MEM_SIZE (0)
#endif

