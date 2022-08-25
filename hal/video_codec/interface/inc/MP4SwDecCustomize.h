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
 *   MP4SwDecCustomize.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the MPEG4 Decoder
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
 ****************************************************************************/

// customization
#ifndef MP4SWDECCUSTOMIZE_H
#define MP4SWDECCUSTOMIZE_H
#ifdef __cplusplus
extern "C"
    {
#endif

#include "drv_features_vcodec.h"

  #if defined(__MTK_TARGET__)
#include "sw_video_decode_custom.h"
#include "video_codec_mem_v2.h"
#include "hal_custom_video_codec.h"
  #endif 


#ifndef MPEG4_DEC_MAX_NORMAL_WIDTH_SP 
  #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP 848
#endif
#ifndef MPEG4_DEC_MAX_NORMAL_HEIGHT_SP 
  #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP 480
#endif
#ifndef MPEG4_DEC_MAX_WIDTH_SP 
  #define MPEG4_DEC_MAX_WIDTH_SP 1920
#endif
#ifndef MPEG4_DEC_MAX_HEIGHT_SP 
  #define MPEG4_DEC_MAX_HEIGHT_SP 1088
#endif
#if !defined(MPEG4_DEC_MAX_WIDTH_1_TO_4_SP)
#define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP MPEG4_DEC_MAX_NORMAL_WIDTH_SP*2
#endif
#if !defined(MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP)
#define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP MPEG4_DEC_MAX_NORMAL_HEIGHT_SP*2
#endif


#if (SW_MP4_SPEEDY_BOUND_RES_0 > (MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP))
    #error "Invalid SW_MP4_SPEEDY_BOUND_RES_0"
#endif

// static
#if 1//def __VIDEO_ARCHI_V2__
#define SW_MP4_SPEEDY_BOUND_RES_3_DEFAULT        MPEG4_DEC_MAX_WIDTH_1_TO_4_SP*MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP
#define SW_MP4_SPEEDY_BOUND_RES_2_DEFAULT        MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP
    #if (480*320) > (MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP)
#define SW_MP4_SPEEDY_BOUND_RES_1_DEFAULT        MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP
    #else
#define SW_MP4_SPEEDY_BOUND_RES_1_DEFAULT        MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP*3/4
    #endif
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* VIDEO_ARCHI_V2 */

#if defined(SW_MP4_SPEEDY_CUSTOM_ENABLE)
#define SW_MP4_SPEEDY_BOUND_RES_3 SW_MP4_SPEEDY_BOUND_RES_3_CUSTOM
#define SW_MP4_SPEEDY_BOUND_RES_2 SW_MP4_SPEEDY_BOUND_RES_2_CUSTOM
#define SW_MP4_SPEEDY_BOUND_RES_1 SW_MP4_SPEEDY_BOUND_RES_1_CUSTOM
#else
#define SW_MP4_SPEEDY_BOUND_RES_3 SW_MP4_SPEEDY_BOUND_RES_3_DEFAULT
#define SW_MP4_SPEEDY_BOUND_RES_2 SW_MP4_SPEEDY_BOUND_RES_2_DEFAULT
#define SW_MP4_SPEEDY_BOUND_RES_1 SW_MP4_SPEEDY_BOUND_RES_1_DEFAULT
#endif

#define SW_MP4_SPEEDY_MODE_0 0x0
#define SW_MP4_SPEEDY_MODE_1 0x1
#define SW_MP4_SPEEDY_MODE_2 0x2
#define SW_MP4_SPEEDY_MODE_3 0x3


// dynamic
#if 1//def __VIDEO_ARCHI_V2__
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3_DEFAULT MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP*4
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2_DEFAULT MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP
#else /* VIDEO_ARCHI_V2 */
/* under construction !*/
/* under construction !*/
#endif /* VIDEO_ARCHI_V2 */
#if 1//def __VIDEO_ARCHI_V2__
    #if (MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP<352*288)
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1_DEFAULT 176*144
    #else
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1_DEFAULT MPEG4_DEC_MAX_NORMAL_WIDTH_SP*MPEG4_DEC_MAX_NORMAL_HEIGHT_SP/4
    #endif
#else
/* under construction !*/
#endif /* VIDEO_ARCHI_V2 */

#if defined(SW_MP4_SPEEDY_CUSTOM_ENABLE)
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3_CUSTOM
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2_CUSTOM
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1_CUSTOM
#else
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3_DEFAULT
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2_DEFAULT
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1 SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1_DEFAULT
#endif

int SWMP4QuerySpeedyMode(int width, int height, int fps, int bitrate);
int SWMP4QueryDynamicSwitch(int width, int height, int fps, int bitrate);
unsigned int SWMP4QueryDynamicSwitchSetting(int width, int height, int fps, int bitrate);
unsigned int SWMP4QuerySkipScalability(int width, int height, int fps, int bitrate);
unsigned int SWMP4QuerySkipBScalability();
int SWMP4QueryAsyncTolerance(int width, int height, int fps, int bitrate);

/////////////////////////////////////////////////////////////////////////
#if 1//def __VIDEO_ARCHI_V2__
#if (SW_MP4_SPEEDY_BOUND_RES_2>MPEG4_DEC_MAX_WIDTH_SP*MPEG4_DEC_MAX_HEIGHT_SP)
#error "Invalid SW_MP4_SPEEDY_BOUND_RES_2"
#endif
#if (SW_MP4_SPEEDY_BOUND_RES_1>MPEG4_DEC_MAX_WIDTH_SP*MPEG4_DEC_MAX_HEIGHT_SP)
#error "Invalid SW_MP4_SPEEDY_BOUND_RES_1"
#endif
#endif
/////////////////////////////////////////////////////////////////////////

#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
int SWMP4PredictDecTime(unsigned int, unsigned int, unsigned int, unsigned int);
#endif /* CONTOUR_SUPPORT */

#ifdef __cplusplus
    }
#endif
#endif
