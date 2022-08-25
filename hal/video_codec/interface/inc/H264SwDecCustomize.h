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
 *   H264SwDecCustomize.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the H.264 Decoder
 *
 * Author:
 * -------
 * -------
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
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
    {
#endif

// customization
#if defined(__MTK_TARGET__)
#include "sw_video_decode_custom.h"
#include "hal_custom_video_codec.h"
#endif

#ifndef H264_DEC_MAX_NORMAL_WIDTH_BP 
    #define H264_DEC_MAX_NORMAL_WIDTH_BP 1920
#endif
#ifndef H264_DEC_MAX_NORMAL_HEIGHT_BP 
    #define H264_DEC_MAX_NORMAL_HEIGHT_BP 1088
#endif
#ifndef H264_DEC_MAX_NORMAL_WIDTH_MPHP 
    #define H264_DEC_MAX_NORMAL_WIDTH_MPHP 1920
#endif
#ifndef H264_DEC_MAX_NORMAL_HEIGHT_MPHP 
    #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP 1088
#endif

#if defined(MT6236) || defined(MT6236B) 
    #if defined(MT6921)
        #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (128*96)
        #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (128*96)
    #else
        #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (320*240)
        #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (320*240)    
    #endif    
#elif defined(MT6255)
    #if defined(MT6922) && !defined(NAND_SUPPORT)
        #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (176*144)
        #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (176*144)    
    #else
        #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (320*240)
        #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (320*240)    
    #endif
#elif (defined(MT6276) || defined(MT6256))&& defined(__H264_DEC_SW_SLIM__)
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (480*320)	
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (320*240)	
#elif defined(MT6276) || defined(MT6256) 
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (640*480)	
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (320*240)	
#elif defined(MT6575)
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (1920*1088)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (1920*1088)
#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) 
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (176*144)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (128*96)
#elif (defined(MT6252H) || defined(MT6252)) && defined(__H264_DEC_SW_SLIM__)    
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (176*144)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (128*96)    
#elif defined(MT6252H) || defined(MT6252)    
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (240*192)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (128*96)
#elif defined(MT6235B) || defined(MT6235)      
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (240*192)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (240*192)
#elif defined(MT6250)      
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (240*192)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (240*192)    
#else 
    #define SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT        (128*96)
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT      (128*96)
#endif

#define SW_H264_SPEEDY_BOUND_RES_2_BP_DEFAULT            (H264_DEC_MAX_NORMAL_WIDTH_BP  *H264_DEC_MAX_NORMAL_HEIGHT_BP)
#define SW_H264_SPEEDY_BOUND_RES_2_MPHP_DEFAULT          (H264_DEC_MAX_NORMAL_WIDTH_MPHP*H264_DEC_MAX_NORMAL_HEIGHT_MPHP)

/* Definition of SW_H264_CONCEAL_MODE_SETTING */
/* 0: try to output the "correct" frame only */
/* 1: try to output the all the "conceal" frame w   checking the frame number continuity */
/* 2: try to output the all the "conceal" frame w/o checking the frame number continuity */
#define SW_H264_CONCEAL_MODE_SETTING_DEFAULT            1

#define SW_H264_SPEEDY_MODE_0 0x0
#define SW_H264_SPEEDY_MODE_1 0x1
#define SW_H264_SPEEDY_MODE_2 0x2

#if defined(SW_H264_SPEEDY_CUSTOM_ENABLE)
    #define SW_H264_SPEEDY_BOUND_RES_1_BP      SW_H264_SPEEDY_BOUND_RES_1_BP_CUSTOM
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP    SW_H264_SPEEDY_BOUND_RES_1_MPHP_CUSTOM
    #define SW_H264_SPEEDY_BOUND_RES_2_BP      SW_H264_SPEEDY_BOUND_RES_2_BP_CUSTOM
    #define SW_H264_SPEEDY_BOUND_RES_2_MPHP    SW_H264_SPEEDY_BOUND_RES_2_MPHP_CUSTOM
    #define SW_H264_CONCEAL_MODE_SETTING       SW_H264_CONCEAL_MODE_SETTING_CUSTOM
#else /* SW_H264_SPEEDY_CUSTOM_ENABLE */
    #define SW_H264_SPEEDY_BOUND_RES_1_BP      SW_H264_SPEEDY_BOUND_RES_1_BP_DEFAULT
    #define SW_H264_SPEEDY_BOUND_RES_1_MPHP    SW_H264_SPEEDY_BOUND_RES_1_MPHP_DEFAULT
    #define SW_H264_SPEEDY_BOUND_RES_2_BP      SW_H264_SPEEDY_BOUND_RES_2_BP_DEFAULT
    #define SW_H264_SPEEDY_BOUND_RES_2_MPHP    SW_H264_SPEEDY_BOUND_RES_2_MPHP_DEFAULT
    #define SW_H264_CONCEAL_MODE_SETTING       SW_H264_CONCEAL_MODE_SETTING_DEFAULT
#endif /* SW_H264_SPEEDY_CUSTOM_ENABLE */

#if (SW_H264_SPEEDY_BOUND_RES_1_BP > SW_H264_SPEEDY_BOUND_RES_2_BP)
    #error "Invalid SW_H264_SPEEDY_BOUND_RES_1_BP"
#endif

#if (SW_H264_SPEEDY_BOUND_RES_1_MPHP > SW_H264_SPEEDY_BOUND_RES_2_MPHP)
    #error "Invalid SW_H264_SPEEDY_BOUND_RES_1_MPHP"
#endif


int SWH264QuerySkipScalability();
int SWH264QuerySpeedyMode(int width, int height, int isBaselineProfile);
int SWH264QueryDynamicSwitch(int width, int height, int isBaselineProfile);
void SWH264QueryDynamicSwitchSetting(int *p01);
void SWH264QueryConcealSetting(unsigned int *mode);
int SWH264QueryAsyncTolerance(int width, int height, int fps, int bitrate);
int SWH264QuerySpeedyModeOffset(int offset);
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
int SWH264PredictDecTime(unsigned int w, unsigned int h, unsigned int fps, unsigned int bitrate);
#endif /* __CONTOUR_IMPROVEMENT_SUPPORT__ */

#ifdef __cplusplus
    }
#endif
