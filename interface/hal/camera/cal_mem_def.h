/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	cal_mem_def.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   This file is intends for defining memory requirement of CAL.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef __CAL_MEM_DEF_H__
#define __CAL_MEM_DEF_H__

#include "isp_mem.h"
#include "jaia_mem.h"
#include "idp_mem_def.h"
#include "jpeg_mem.h"
#include "drv_sw_features_jpeg.h"
#include "pp_mem_def.h"
#include "sensor_capability.h"
#include "lcd_sw_inc.h"
#include "cal_feature_option.h"
#include "mav_mem.h"

#ifndef ISP_IMAGE_BUF_SIZE
    #define ISP_IMAGE_BUF_SIZE 0
#endif

#ifndef ISP_EXT_WORKING_BUF_SIZE
    #define ISP_EXT_WORKING_BUF_SIZE 0
#endif

#ifndef JPEG_ENC_EXT_MIN_MEM_SIZE
    #define JPEG_ENC_EXT_MIN_MEM_SIZE 0
#endif

#ifndef JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE
    #define JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE 0
#endif

#ifndef IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM
    #define IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM 0
#endif

#ifndef IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM
    #define IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM 0
#endif

#ifndef IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM
    #define  IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM 0
#endif

#ifndef IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM
    #define  IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM 0
#endif

#ifndef PP_PREVIEW_EXT_MEM_SIZE
    #define PP_PREVIEW_EXT_MEM_SIZE 0
#endif

#ifndef PP_CAPTURE_EXT_MEM_SIZE
    #define PP_CAPTURE_EXT_MEM_SIZE 0
#endif

#ifndef PP_BG_POSTPROC_EXT_MEM_SIZE
    #define PP_BG_POSTPROC_EXT_MEM_SIZE 0
#endif

#ifndef PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE
    #define PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE 0
#endif

#ifndef PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE
    #define PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE 0
#endif

#ifndef JPEG_DEC_EXT_MIN_MEM_SIZE
    #define JPEG_DEC_EXT_MIN_MEM_SIZE 0
#endif

#ifndef PP_POSTPROC_EXT_MEM_SIZE
    #define PP_POSTPROC_EXT_MEM_SIZE 0
#endif

#ifndef JPEG_ENC_EXT_MAX_MEM_SIZE
    #define JPEG_ENC_EXT_MAX_MEM_SIZE 0
#endif

#ifndef JPEG_SW_ENC_EXT_MIN_MEM_SIZE
    #define JPEG_SW_ENC_EXT_MIN_MEM_SIZE 0
#endif

#if (defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__))
    #define PREVIEW_IMAGE_EFFECT_MEM_SIZE LCD_WIDTH*LCD_HEIGHT*4
#else
    #define PREVIEW_IMAGE_EFFECT_MEM_SIZE 0
#endif

#if defined(__JPEG_SENSOR_SUPPORT__)

        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_VGA   (300*1024)    /* 300KB for VGA */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_1M   (896*1024)    /* 896KB for 1.3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_2M   (1536*1024)   /* 1536KB for 2M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_3M   (2048*1024)   /* 2048KB for 3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_4M   (2560*1024)   /* 2048KB for 3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_5M   (3072*1024)   /* 3072KB for 5M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_8M   (5600*1024)   /* 5600KB for 8M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_OTHER   (896*1024) 

#else // for yuv or raw sensor

        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_VGA   (900*1024)    /* for VGA */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_1M   (1000*1024)    /* for 1.3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_2M   (1200*1024)   /* 1536KB for 2M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_3M   (1400*1024)   /* 2048KB for 3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_4M   (2560*1024)   /* 2048KB for 3M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_5M   (3072*1024)   /* 3072KB for 5M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_8M   (5600*1024)   /* 5600KB for 8M */
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE_OTHER   (900*1024) 

#endif

#if (defined(__YUVCAM_INTERPOLATION_SW__) || defined(__YUVCAM_INTERPOLATION_HW__))
    #if defined(__IMAGE_SENSOR_01M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (300*1024)    /* 300KB for 0.3M */
    #elif defined(__IMAGE_SENSOR_03M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (896*1024)    /* 896KB for 1.3M */
    #elif defined(__IMAGE_SENSOR_1M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (1536*1024)   /* 1536KB for 2M */
    #elif defined(__IMAGE_SENSOR_2M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (2048*1024)   /* 2048KB for 3M */
    #elif defined(__IMAGE_SENSOR_3M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (3072*1024)   /* 3072KB for 5M */
    #elif defined(__IMAGE_SENSOR_5M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (5600*1024)   /* 5600KB for 8M */
    #elif defined(__IMAGE_SENSOR_8M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (5600*1024)   /* 5600KB for 8M */
    #else
        //#error "Please define max resolution of sensor in image_sensor.h"
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (1*1024)   /* a dummy buffer if no sensor is selected */
    #endif

    // the address offset between raw image and JPEG image buffer while overlap these two buffers
    // it is to minimize the requirement of memory while capture a picture
    #if (defined(__IMAGE_SENSOR_03M__)||defined(__IMAGE_SENSOR_01M__))
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (88320)
    #elif defined(__IMAGE_SENSOR_1M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (93440)
    #elif defined(__IMAGE_SENSOR_2M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (100608)
    #elif defined(__IMAGE_SENSOR_3M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (109312)
    #elif defined(__IMAGE_SENSOR_5M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (109312)
    #elif defined(__IMAGE_SENSOR_8M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (109312)
    #else
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (1024)	/* dummy buffer if no sensor is selcted */
    #endif
#else
    #if defined(__IMAGE_SENSOR_01M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (100*1024 + 0x10000)    /* 100KB for CIF and 0x10000 is the JAIA offset*/
    #elif defined(__IMAGE_SENSOR_03M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (300*1024)    /* 300KB for VGA */
    #elif defined(__IMAGE_SENSOR_1M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (896*1024)    /* 896KB for 1.3M */
    #elif defined(__IMAGE_SENSOR_2M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (1536*1024)   /* 1536KB for 2M */
    #elif defined(__IMAGE_SENSOR_3M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (2048*1024)   /* 2048KB for 3M */
    #elif defined(__IMAGE_SENSOR_5M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (3072*1024)   /* 3072KB for 5M */
    #elif defined(__IMAGE_SENSOR_8M__)
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (5600*1024)   /* 5600KB for 8M */
    #else
        //#error "Please define max resolution of sensor in image_sensor.h"
        #define MAX_STILL_CAPTURE_JPEG_BUFF_SIZE   (1*1024)   /* a dummy buffer if no sensor is selected */    
    #endif

    // the address offset between raw image and JPEG image buffer while overlap these two buffers
    // it is to minimize the requirement of memory while capture a picture
    #if (defined(__IMAGE_SENSOR_03M__)||defined(__IMAGE_SENSOR_01M__))
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (78080)
    #elif defined(__IMAGE_SENSOR_1M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (88320)
    #elif defined(__IMAGE_SENSOR_2M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (93440)
    #elif defined(__IMAGE_SENSOR_3M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (100608)
    #elif defined(__IMAGE_SENSOR_5M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (109312)
    #elif defined(__IMAGE_SENSOR_8M__)
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (109312)
    #else
        #define CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET  (1024)	/* dummy buffer if no sensor is selcted */
    #endif
#endif

//#if ((defined(MT6252) || defined(MT6255)) && (defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)||defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)))
#if ((defined(MT6252) || defined(MT6255)|| defined(MT6250)|| defined(MT6256)|| defined(MT6260)) && !defined(__CAMCO_QUICK_VIEW_ROTATE_SHRAE_APP_MEM__) && !defined(__CAMERA_NO_NEED_QUICK_VIEW_ROTATE__)) /* QVI rotate buffer from APP to reduce memory usage */
    #define CAL_QVI_ROT_WORKING_BUFF_SIZE                       LCD_WIDTH*LCD_HEIGHT*2
#else
    #define CAL_QVI_ROT_WORKING_BUFF_SIZE   0
#endif


// CAL_PREVIEW_EXT_MEMORY_SIZE : the external working memory for camera preview only scenario
// CAL_STILL_CAPTURE_EXT_MEMORY_SIZE : the external working memory for still capture only scenario
// CAL_VIDEO_EXT_MEMORY_SIZE : the external working memory for video only scenario
// CAL_PP_PREVIEW_EXT_MEMORY_SIZE : additional external working memory if FD/SD is enable during camera preview
// CAL_PP_STILL_CAPTURE_EXT_MEMORY_SIZE : addition external working memory if Panorama is enable during camera still capture
// CAL_PP_BG_EXT_MEMORY_SIZE : the external working memory for post process backgournd stitch. It will exist during the panorama capture.
// CAL_PP_SCENARIO_EXT_MEMORY_SIZE : the external working memory for post process scenario
// CAL_WEB_CAM_PREVIEW_EXT_MEM_SIZE : the external working memory for web camera preview scenario
// CAL_WEB_CAM_STILL_CAPTURE_EXT_MEM_SIZE : the external working memory for web camera still capture scenario
// CAL_STILL_CAPTURE_RAW_IMAGE_BUFF_SIZE : the raw image buffer for still capture scenario.

// the address offset from JPEG start address for JAIA merge
#define CAL_JAIA_MEMORY_OFFSET                      0x10000

#define CAL_MAX_EXT_MEM(A,B)         ( ((A)>(B)) ? (A) : (B))
#define CAL_JAIA_EXT_MEM_SIZE(RawBuffSize, JaiaBuffSize) (((RawBuffSize)>(JaiaBuffSize)) ? 0 : JaiaBuffSize)

#define MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE      (LCD_WIDTH*LCD_HEIGHT+CAL_JAIA_MEMORY_OFFSET)

#define IMAGE_SENSOR_BAYER_FULL_SIZE                    (IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT)
#define USE_LCD_SIZE_RESOLUTION                         (ISP_IMAGE_BUF_SIZE ? ((LCD_WIDTH*LCD_HEIGHT*4>ISP_IMAGE_BUF_SIZE)? 0 : 1) : (((LCD_WIDTH*LCD_HEIGHT*4)>(IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT*2))? 0 : 1) )

#define USE_VGA_SIZE_RESOLUTION                         (ISP_IMAGE_BUF_SIZE ? ((640*480*4>ISP_IMAGE_BUF_SIZE)? 0 : 1) : (((640*480*4)>(IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT*2))? 0 : 1) )

#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
#define STILL_CAPTURE_PRE_IMAGE_EXT_MEM_SIZE            0
#else
#define STILL_CAPTURE_PRE_IMAGE_EXT_MEM_SIZE            ((JPEG_ENC_EXT_MIN_MEM_SIZE+31)&0xFFFFFFE0)
#endif

#define STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE           (((CAL_MAX_EXT_MEM((LCD_WIDTH*LCD_HEIGHT*4)+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET,(MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+CAL_QVI_ROT_WORKING_BUFF_SIZE+31)&0xFFFFFFE0)+10240)

#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
#define STILL_CAPTURE_VGA_IMAGE_EXT_MEM_SIZE            0
#else
#define STILL_CAPTURE_VGA_IMAGE_EXT_MEM_SIZE            ((JPEG_ENC_EXT_MIN_MEM_SIZE+31)&0xFFFFFFE0)
#endif

#define STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE           (((CAL_MAX_EXT_MEM((640*480*4)+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET,(640*480+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+CAL_QVI_ROT_WORKING_BUFF_SIZE+31)&0xFFFFFFE0)+10240)

#define CAL_PREVIEW_EXT_MEMORY_SIZE                 ((PREVIEW_IMAGE_EFFECT_MEM_SIZE+IDP_MEM_CONSUME_CAMERA_PREVIEW_EXTMEM+31)&0xFFFFFFE0)
//#define CAL_STILL_CAPTURE_EXT_MEMORY_SIZE           (CAL_MAX_EXT_MEM((ISP_EXT_WORKING_BUF_SIZE + IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM + JPEG_ENC_EXT_MIN_MEM_SIZE), CAL_JAIA_EXT_MEM_SIZE(ISP_IMAGE_BUF_SIZE,JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+31)&0xFFFFFFE0


#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
#define CAL_STILL_CAPTURE_EXT_MEMORY_SIZE           0
#else
#define CAL_STILL_CAPTURE_EXT_MEMORY_SIZE           ((ISP_EXT_WORKING_BUF_SIZE + IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM + JPEG_ENC_EXT_MIN_MEM_SIZE+31)&0xFFFFFFE0)
#endif

#if defined(__JPEG_SENSOR_SUPPORT__)
    #if defined(MT6255)
        #define CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE      ((CAL_MAX_EXT_MEM((ISP_IMAGE_BUF_SIZE+IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM),(MAX_STILL_CAPTURE_JPEG_BUFF_SIZE+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET+31+CAL_QVI_ROT_WORKING_BUFF_SIZE)&0xFFFFFFE0)
    #elif defined(MT6256)
        #define CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE      ((CAL_MAX_EXT_MEM(MAX_STILL_CAPTURE_JPEG_BUFF_SIZE,IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM)+CAL_MAX_EXT_MEM(JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE,ISP_EXT_WORKING_BUF_SIZE)+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET+31+CAL_QVI_ROT_WORKING_BUFF_SIZE)&0xFFFFFFE0)
    #else
        #define CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE      ((CAL_MAX_EXT_MEM(ISP_IMAGE_BUF_SIZE+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET,(MAX_STILL_CAPTURE_JPEG_BUFF_SIZE+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET))+31+CAL_QVI_ROT_WORKING_BUFF_SIZE)&0xFFFFFFE0)
    #endif
#else // yuv sensor
    #define CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE      ((CAL_MAX_EXT_MEM(ISP_IMAGE_BUF_SIZE+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET,(MAX_STILL_CAPTURE_JPEG_BUFF_SIZE+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+31+CAL_QVI_ROT_WORKING_BUFF_SIZE)&0xFFFFFFE0)
#endif

#define CAL_VIDEO_EXT_MEMORY_SIZE                   ((IDP_MEM_CONSUME_VIDEO_ENCODE_EXTMEM+31)&0xFFFFFFE0)
#define CAL_VT_EXT_MEMORY_SIZE                      ((IDP_MEM_CONSUME_VIDEO_CALL_ENCODE_EXTMEM+31)&0xFFFFFFE0)
#define CAL_PP_PREVIEW_EXT_MEMORY_SIZE              ((PP_PREVIEW_EXT_MEM_SIZE+31)&0xFFFFFFE0)
#define CAL_PP_STILL_CAPTURE_EXT_MEMORY_SIZE        ((PP_CAPTURE_EXT_MEM_SIZE+31)&0xFFFFFFE0)
#define CAL_PP_BG_EXT_MEMORY_SIZE                   ((PP_BG_POSTPROC_EXT_MEM_SIZE+31)&0xFFFFFFE0)


#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
    // CAL hdr post-processing result image buffer (before encode) ; contained jaia working buffer
    // CAL hdr post-processing working mem ; pp_working || jpeg_enc_working || jpeg_dec_working || lcd_size yuv420 tmp buffer for dithering
    #define CAL_PP_HDR_SCENARIO_EXT_IMAGE_SIZE      ( (CAL_MAX_EXT_MEM((PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE+CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+CAL_JAIA_MEMORY_OFFSET),(MAX_STILL_CAPTURE_JPEG_BUFF_SIZE+JAIA_WORKING_BUF_SIZE_FOR_CAMERA_CAPTURE))+31)&0xFFFFFFE0 )
    #if (defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)||defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__))
        #define CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE ( (CAL_MAX_EXT_MEM(CAL_MAX_EXT_MEM(PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE, LCD_WIDTH*LCD_HEIGHT*2)+JPEG_ENC_EXT_MIN_MEM_SIZE, CAL_MAX_EXT_MEM(JPEG_ENC_EXT_MIN_MEM_SIZE, JPEG_DEC_EXT_MIN_MEM_SIZE)) + 31)&0xFFFFFFE0 )
    #else
        #define CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE ( (CAL_MAX_EXT_MEM(CAL_MAX_EXT_MEM(PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE, LCD_WIDTH*LCD_HEIGHT*3/2), CAL_MAX_EXT_MEM(JPEG_ENC_EXT_MIN_MEM_SIZE, JPEG_DEC_EXT_MIN_MEM_SIZE)) + 31)&0xFFFFFFE0 )
    #endif
//    #define CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE ( (CAL_MAX_EXT_MEM(PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE, CAL_MAX_EXT_MEM(JPEG_ENC_EXT_MIN_MEM_SIZE, JPEG_DEC_EXT_MIN_MEM_SIZE)) + 31)&0xFFFFFFE0 )
#else
    #define CAL_PP_HDR_SCENARIO_EXT_IMAGE_SIZE      (0)
    #define CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE (0)
#endif
#define CAL_PP_HDR_SCENARIO_EXT_MEMORY_SIZE (CAL_PP_HDR_SCENARIO_EXT_IMAGE_SIZE+CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE)

#if defined(__PANORAMA_VIEW_SUPPORT__)
    #define CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE      (PP_POSTPROC_EXT_MEM_SIZE) // tmp
    #define CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE (0)                                             // tmp
#elif defined(__AUTOCAP_PANORAMA_SUPPORT__)
    #define CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE      (PP_POSTPROC_PANO_EXT_IMAGE_MEM_SIZE) // tmp
    #define CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE (PP_POSTPROC_PANO_EXT_WORKING_MEM_SIZE)
#else
    #define CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE      (0)
    #define CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE (0)
#endif
#define CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE (CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE+CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE)


// cal postproc scenario external memory usage
#if ( CAL_PP_HDR_SCENARIO_EXT_MEMORY_SIZE > CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE )
    #define CAL_PP_SCENARIO_EXT_MEMORY_SIZE     ((CAL_PP_HDR_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0)
#else
    #define CAL_PP_SCENARIO_EXT_MEMORY_SIZE     ((CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+31)&0xFFFFFFE0)
#endif

// cal mav scenario external memory usage
#if ( PP_POSTPROC_MAV_EXT_WORKING_MEM_SIZE > (MAV_ENC_MAX_WORKING_BUF_SIZE+MAV_ENC_MAX_DESTINATION_BUF_SIZE) )
#define CAL_PP_MAV_SCENARIO_EXT_MEMORY_SIZE ((LCD_WIDTH*LCD_HEIGHT*3*MAV_IMAGE_NUM/2+PP_POSTPROC_MAV_EXT_WORKING_MEM_SIZE+31)&0xFFFFFFE0) 
#else
#define CAL_PP_MAV_SCENARIO_EXT_MEMORY_SIZE ((LCD_WIDTH*LCD_HEIGHT*3*MAV_IMAGE_NUM/2+MAV_ENC_MAX_WORKING_BUF_SIZE+MAV_ENC_MAX_DESTINATION_BUF_SIZE+31)&0xFFFFFFE0) 
#endif

// Camera gyro
// cal camera-motion scenario external memory usage (same with mavcap only)
#define CAL_PP_CAMERA_GYRO_SCENARIO_EXT_MEMORY_SIZE ((MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*3+PP_PREVIEW_CAMERA_GYRO_EXT_WORKING_MEM_SIZE+31)&0xFFFFFFE0) 


#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
#define CAL_STILL_CAPTURE_LCD_IMAGE_EXT_MEMORY_SIZE 0
#else
#define CAL_STILL_CAPTURE_LCD_IMAGE_EXT_MEMORY_SIZE (USE_LCD_SIZE_RESOLUTION ? STILL_CAPTURE_PRE_IMAGE_EXT_MEM_SIZE : CAL_STILL_CAPTURE_EXT_MEMORY_SIZE)
#endif
// if ISP raw capture is disabled (6276), Then use preview image buffer is enough since the LCD size image will be captured.
// if ISP raw capture is enabled (6236/6268), then check whether the the max capture size less then preview size to decide request
// full image size buffer or not.
#define CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_SIZE       (ISP_IMAGE_BUF_SIZE ? (USE_LCD_SIZE_RESOLUTION ? STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE :CAL_MAX_EXT_MEM(CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE,STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE)) : STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE)

// If AP just need capture LCD size(like MRE) and without thumbnial and quickview for JAIA.
// CAL alloc only 2 YUV420 capture(LCD size) buffer (lcd_w * lcd_h * 1.5 * 2).
// 1. If capture need rotate, capture to top YUV420 buffer(1st buffer), and rotate to below YUV420 buffer(2nd buffer).
// 2. If capture need not rotate, capture to below YUV420 buffer(2nd buffer).
// 3. Rotate below YUV420 buffer(2nd buffer) to top YUV420 buffer(1st buffer), for QVI rotate.
// 4. Resize top YUV420 buffer(1st buffer) to destination display QVI buffer.
// 5. Encode below YUV420 buffer(2nd buffer) to jpeg which position is top YUV420 buffer(1st buffer)
#define CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_MIN_SIZE   (LCD_WIDTH*LCD_HEIGHT*3)

#if ((defined(MT6255) || defined(MT6256)) && defined(__JPEG_SENSOR_SUPPORT__))
#define CAL_STILL_CAPTURE_VGA_IMAGE_EXT_MEMORY_SIZE 0
#else
#define CAL_STILL_CAPTURE_VGA_IMAGE_EXT_MEMORY_SIZE (USE_VGA_SIZE_RESOLUTION ? STILL_CAPTURE_VGA_IMAGE_EXT_MEM_SIZE : CAL_STILL_CAPTURE_EXT_MEMORY_SIZE)
#endif
#define CAL_STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE       (ISP_IMAGE_BUF_SIZE ? (USE_VGA_SIZE_RESOLUTION ? STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE :CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE) : STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE)

////  WEBCAM external memory //////
#define WEBCAM_MAX_WIDTH                    (640)       ///Bin: TODO:  should can be customized ??
#define WEBCAM_MAX_HEIGHT                   (480)

#ifdef __JPEG_ENC_HW_SUPPORTED__
#define CAL_WEBCAM_JPEG_BUFFER_SIZE           (300*1024)  ///WEBCAM JPEG bitstream buffer (triple buffer for USB)
#define WEBCAM_YUV_IMAGE_BUFFER_SIZE          (0)     ///For YUV420
#else
#define CAL_WEBCAM_JPEG_BUFFER_SIZE           (145*1024)  /// (0xC000+12)*3 - Make sure sync with webcam 
#define WEBCAM_YUV_IMAGE_BUFFER_SIZE          (WEBCAM_MAX_WIDTH*WEBCAM_MAX_WIDTH*3/2)
#endif

#define CAL_WEBCAM_EXT_MEM_SIZE                 ((WEBCAM_YUV_IMAGE_BUFFER_SIZE+IDP_MEM_CONSUME_CAMERA_CAPTURE_TO_JPEG_EXTMEM+JPEG_ENC_EXT_MAX_MEM_SIZE+31)&0xFFFFFFE0)
////   WEBCAM end   ////


#define CAL_STILL_CAPTURE_RAW_IMAGE_BUFF_SIZE   ((ISP_IMAGE_BUF_SIZE+31)&0xFFFFFFE0)

typedef union
{
    kal_uint8 _CAL_JAIA_MEMORY_OFFSET[CAL_JAIA_MEMORY_OFFSET+4];
    kal_uint8 _CAL_PP_BG_EXT_MEMORY_SIZE[CAL_PP_BG_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PP_HDR_SCENARIO_EXT_IMAGE_SIZE[CAL_PP_HDR_SCENARIO_EXT_IMAGE_SIZE+4];
    kal_uint8 _CAL_PP_HDR_SCENARIO_EXT_MEMORY_SIZE[CAL_PP_HDR_SCENARIO_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE[CAL_PP_HDR_SCENARIO_EXT_WORKING_SIZE+4];
    kal_uint8 _CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE[CAL_PP_PANO_SCENARIO_EXT_IMAGE_SIZE+4];
    kal_uint8 _CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE[CAL_PP_PANO_SCENARIO_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE[CAL_PP_PANO_SCENARIO_EXT_WORKING_SIZE+4];
    kal_uint8 _CAL_PP_PREVIEW_EXT_MEMORY_SIZE[CAL_PP_PREVIEW_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PP_SCENARIO_EXT_MEMORY_SIZE[CAL_PP_SCENARIO_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PP_STILL_CAPTURE_EXT_MEMORY_SIZE[CAL_PP_STILL_CAPTURE_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_PREVIEW_EXT_MEMORY_SIZE[CAL_PREVIEW_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET[CAL_RAW_IMAGE_JPEG_OVERLAP_OFFSET+4];
    kal_uint8 _CAL_STILL_CAPTURE_EXT_MEMORY_SIZE[CAL_STILL_CAPTURE_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_SIZE[CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_MIN_SIZE[CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_MIN_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_LCD_IMAGE_EXT_MEMORY_SIZE[CAL_STILL_CAPTURE_LCD_IMAGE_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE[CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_RAW_IMAGE_BUFF_SIZE[CAL_STILL_CAPTURE_RAW_IMAGE_BUFF_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE[CAL_STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE+4];
    kal_uint8 _CAL_STILL_CAPTURE_VGA_IMAGE_EXT_MEMORY_SIZE[CAL_STILL_CAPTURE_VGA_IMAGE_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_VIDEO_EXT_MEMORY_SIZE[CAL_VIDEO_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_VT_EXT_MEMORY_SIZE[CAL_VT_EXT_MEMORY_SIZE+4];
    kal_uint8 _CAL_WEBCAM_EXT_MEM_SIZE[CAL_WEBCAM_EXT_MEM_SIZE+4];
    kal_uint8 _CAL_WEBCAM_JPEG_BUFFER_SIZE[CAL_WEBCAM_JPEG_BUFFER_SIZE+4];
    kal_uint8 _IMAGE_SENSOR_BAYER_FULL_SIZE[IMAGE_SENSOR_BAYER_FULL_SIZE+4];
    kal_uint8 _MAX_STILL_CAPTURE_JPEG_BUFF_SIZE[MAX_STILL_CAPTURE_JPEG_BUFF_SIZE+4];
    kal_uint8 _MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE[MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE+4];
    kal_uint8 _STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE[STILL_CAPTURE_PRE_IMAGE_BUFF_SIZE+4];
    kal_uint8 _STILL_CAPTURE_PRE_IMAGE_EXT_MEM_SIZE[STILL_CAPTURE_PRE_IMAGE_EXT_MEM_SIZE+4];
    kal_uint8 _STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE[STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE+4];
    kal_uint8 _STILL_CAPTURE_VGA_IMAGE_EXT_MEM_SIZE[STILL_CAPTURE_VGA_IMAGE_EXT_MEM_SIZE+4];
    kal_uint8 _USE_LCD_SIZE_RESOLUTION[USE_LCD_SIZE_RESOLUTION+4];
    kal_uint8 _USE_VGA_SIZE_RESOLUTION[USE_VGA_SIZE_RESOLUTION+4];
    kal_uint8 _WEBCAM_MAX_HEIGHT[WEBCAM_MAX_HEIGHT+4];
    kal_uint8 _WEBCAM_MAX_WIDTH[WEBCAM_MAX_WIDTH+4];
    kal_uint8 _WEBCAM_YUV_IMAGE_BUFFER_SIZE[WEBCAM_YUV_IMAGE_BUFFER_SIZE+4];
} CAL_EXT_MEM_UNION;

#endif /* __CAL_MEM_DEF_H__ */
