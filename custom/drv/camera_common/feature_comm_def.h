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
 *   feature_comm_def.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   Camera Features header file
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

#ifndef __FEATURE_COMM_DEF_H__
#define __FEATURE_COMM_DEF_H__

#include "drv_features_isp.h"

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    #if (defined(__MMI_MAINLCD_480X800__)||defined(__MMI_MAINLCD_800X480__))
    #define PANORAMA_MAX_INPUT_IMAGE_SIZE_1M
    #if (defined(__AUTOCAP_PANORAMA_MODE_3__))
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (2800)
    #else
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (4)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (3800)
    #endif
    #else
    #define PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA
    #if (defined(__AUTOCAP_PANORAMA_MODE_3__))
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (1800)
    #elif (defined(__AUTOCAP_PANORAMA_MODE_4__))
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (4)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (2000)
    #elif (defined(__AUTOCAP_PANORAMA_MODE_5__)) // RAM: 5.4MB
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (5)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (2000)
    #elif (defined(__AUTOCAP_PANORAMA_MODE_6__)) // RAM: 7MB
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (6)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (3230)
    #elif (defined(__AUTOCAP_PANORAMA_MODE_7__))
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (7)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (3600)
    #elif (defined(__AUTOCAP_PANORAMA_MODE_8__)) // RAM:9.4MB
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (8)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (3800)
    #else
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (8)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (3800)
    #endif
    #endif
    
    #define PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420
    #define PANORAMA_INPUT_IMAGE_FORMAT_YUV420
    #define PANO_MAX_OUTPUT_IMG_WIDTH PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH

    #if (defined(MT6235))
        #define AUTOCAP_SOURCE_IMAGE_FROM_CRZ
    #else /* others)*/
        #define AUTOCAP_SOURCE_IMAGE_FROM_PRZ
    #endif
#else
#if (defined(DRV_ISP_6235_SERIES))
    #define PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (1832)
    #define PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420
    #define PANORAMA_INPUT_IMAGE_FORMAT_YUV420
#elif (defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES))
    #if (defined(DRV_ISP_MT6268_HW_SUPPORT))
        #define PANORAMA_MAX_INPUT_IMAGE_SIZE_2M
        #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
        #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (4095)
        #define PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_RGB565
        #define PANORAMA_INPUT_IMAGE_FORMAT_JPEG
    #else /*(defined(MT6236) || defined(MT6276))*/
        #define PANORAMA_MAX_INPUT_IMAGE_SIZE_2M
        #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
        #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (4095)
        #define PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420
        #define PANORAMA_INPUT_IMAGE_FORMAT_JPEG
    #endif
#else /* others */
    #define PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA
    #define PANORAMA_MAX_INPUT_IMAGE_NUM        (3)
    #define PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH   (1832)
    #define PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420
    #define PANORAMA_INPUT_IMAGE_FORMAT_JPEG
#endif
#endif

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#define MAV_MAX_SUPPORT_IMAGE_NUM 9    // It can be set at most to 15
#elif defined(__3D_IMAGE_SUPPORT__)
#define MAV_MAX_SUPPORT_IMAGE_NUM 2    // left and right eyes
#else
#define MAV_MAX_SUPPORT_IMAGE_NUM 1
#endif

#if (defined(MT6235))
    #define FD_SOURCE_IMAGE_FROM_CRZ
#else /* others)*/
    #define FD_SOURCE_IMAGE_FROM_PRZ
#endif


#endif /* __FEATURE_COMM_DEF_H__ */
