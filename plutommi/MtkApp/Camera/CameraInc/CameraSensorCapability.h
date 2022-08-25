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
 *  CameraSensorCapability.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define Camera Sensor Capability
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_SENSOR_CAPABILITY_H_
#define _CAMERA_SENSOR_CAPABILITY_H_
    #if defined(YUV_SENSOR_SUPPORT)
        #if defined(MC501CB_YUV)
            #define __CAMERA_SENSOR_EFFECT_NORMAL__
            #define __CAMERA_SENSOR_EFFECT_GRAYSCALE__
            #define __CAMERA_SENSOR_EFFECT_SEPIA__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_GREEN__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_BLUE__
            #define __CAMERA_SENSOR_EFFECT_COLOR_INVERT__
            #define __CAMERA_SENSOR_EFFECT_GRAY_INVERT__
            #define __CAMERA_SENSOR_EFFECT_BLACKBOARD__
            #define __CAMERA_SENSOR_EFFECT_WHITEBOARD__
            #define __CAMERA_SENSOR_EFFECT_COPPER_CARVING__
            #define __CAMERA_SENSOR_EFFECT_EMBOSSMENT__
            #define __CAMERA_SENSOR_EFFECT_BLUE_CARVING__
            #define __CAMERA_SENSOR_EFFECT_SKETCH__
        #elif defined(OV2650_YUV) || defined(OV6680_YUV) || defined(OV7670_YUV)
            #define __CAMERA_SENSOR_EFFECT_NORMAL__
            #define __CAMERA_SENSOR_EFFECT_GRAYSCALE__
            #define __CAMERA_SENSOR_EFFECT_SEPIA__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_GREEN__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_BLUE__
            #define __CAMERA_SENSOR_EFFECT_COLOR_INVERT__
        /*#elif defined(OV2640_YUV) OV2640 at MT6228 is RAW*/
        /*#elif defined(MT9D011_YUV) MT9D011 at MT6229 is RAW*/
        #elif defined(SIC320A_SERIAL_YUV)
            #define __CAMERA_SENSOR_EFFECT_NORMAL__
            #define __CAMERA_SENSOR_EFFECT_GRAYSCALE__
            #define __CAMERA_SENSOR_EFFECT_SEPIA__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_GREEN__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_BLUE__
            //#define __CAMERA_SENSOR_EFFECT_COLOR_INVERT__
        #else
            #define __CAMERA_SENSOR_EFFECT_NORMAL__
            #define __CAMERA_SENSOR_EFFECT_GRAYSCALE__
            #define __CAMERA_SENSOR_EFFECT_SEPIA__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_GREEN__
            #define __CAMERA_SENSOR_EFFECT_SEPIA_BLUE__
            #define __CAMERA_SENSOR_EFFECT_COLOR_INVERT__
        #endif
    #else
        /* RAW_SENSOR_SUPPORT */
        #define __CAMERA_SENSOR_EFFECT_NORMAL__
        #define __CAMERA_SENSOR_EFFECT_GRAYSCALE__
        #define __CAMERA_SENSOR_EFFECT_SEPIA__
        #define __CAMERA_SENSOR_EFFECT_SEPIA_GREEN__
        #define __CAMERA_SENSOR_EFFECT_SEPIA_BLUE__
        #define __CAMERA_SENSOR_EFFECT_COLOR_INVERT__
        #define __CAMERA_SENSOR_EFFECT_GRAY_INVERT__
        #define __CAMERA_SENSOR_EFFECT_BLACKBOARD__
        #define __CAMERA_SENSOR_EFFECT_WHITEBOARD__
        #define __CAMERA_SENSOR_EFFECT_COPPER_CARVING__
        #define __CAMERA_SENSOR_EFFECT_EMBOSSMENT__
        #define __CAMERA_SENSOR_EFFECT_BLUE_CARVING__
        #define __CAMERA_SENSOR_EFFECT_JEAN__
        #define __CAMERA_SENSOR_EFFECT_SKETCH__
        #define __CAMERA_SENSOR_EFFECT_OIL__
    #endif /* YUV_SENSOR_SUPPORT */
#endif /* _CAMERA_SENSOR_CAPABILITY_H_*/ 

