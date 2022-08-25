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
 *   VP8SwDecCustomize.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the VP8 Decoder
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

#ifndef VP8_DEC_MAX_NORMAL_WIDTH 
    #define VP8_DEC_MAX_NORMAL_WIDTH 1920
#endif
#ifndef VP8_DEC_MAX_NORMAL_HEIGHT 
    #define VP8_DEC_MAX_NORMAL_HEIGHT 1088
#endif

#define ALIGN_X(VAL, SIZE) \
           ((((VAL)+(SIZE)-1)/(SIZE))*(SIZE))
#define VP8_PADDING 64
#define VP8_DEC_MAX_STD_WIDTH    128
#define VP8_DEC_MAX_STD_HEIGHT   96
#define VP8_DEC_MIN_VSS_WIDTH    640
#define VP8_DEC_MIN_VSS_HEIGHT   368
#define VP8_DEC_MIN_FVSS_WIDTH   1280
#define VP8_DEC_MIN_FVSS_HEIGHT  720

#define SW_VP8_SPEEDY_VSS_RES             ((ALIGN_X((VP8_DEC_MIN_VSS_WIDTH   +VP8_PADDING), 32)*ALIGN_X((VP8_DEC_MIN_VSS_HEIGHT   +VP8_PADDING), 32))-1)
#define SW_VP8_SPEEDY_FVSS_RES            ((ALIGN_X((VP8_DEC_MIN_FVSS_WIDTH  +VP8_PADDING), 32)*ALIGN_X((VP8_DEC_MIN_FVSS_HEIGHT  +VP8_PADDING), 32))-1)
#define SW_VP8_SPEEDY_BOUND_RES_1_DEFAULT  (ALIGN_X((VP8_DEC_MAX_STD_WIDTH   +VP8_PADDING), 32)*ALIGN_X((VP8_DEC_MAX_STD_HEIGHT   +VP8_PADDING), 32))
#define SW_VP8_SPEEDY_BOUND_RES_2_DEFAULT  (ALIGN_X((VP8_DEC_MAX_NORMAL_WIDTH+VP8_PADDING), 32)*ALIGN_X((VP8_DEC_MAX_NORMAL_HEIGHT+VP8_PADDING), 32))

#define SW_VP8_SPEEDY_MODE_0 0x0
#define SW_VP8_SPEEDY_MODE_1 0x1
#define SW_VP8_SPEEDY_MODE_2 0x2

#define SW_VP8_SPEEDY_MODE_OFFSET_0 0x0
#define SW_VP8_SPEEDY_MODE_OFFSET_1 0x1
#define SW_VP8_SPEEDY_MODE_OFFSET_2 0x2
#define SW_VP8_SPEEDY_MODE_OFFSET_3 0x3
#define SW_VP8_SPEEDY_MODE_OFFSET_4 0x4

#if defined(SW_VP8_SPEEDY_CUSTOM_ENABLE)
    #define SW_VP8_SPEEDY_BOUND_RES_1      SW_VP8_SPEEDY_BOUND_RES_1_CUSTOM
    #define SW_VP8_SPEEDY_BOUND_RES_2      SW_VP8_SPEEDY_BOUND_RES_2_CUSTOM
#else /* SW_VP8_SPEEDY_CUSTOM_ENABLE */
    #define SW_VP8_SPEEDY_BOUND_RES_1      SW_VP8_SPEEDY_BOUND_RES_1_DEFAULT
    #define SW_VP8_SPEEDY_BOUND_RES_2      SW_VP8_SPEEDY_BOUND_RES_2_DEFAULT
#endif /* SW_VP8_SPEEDY_CUSTOM_ENABLE */

#if (SW_VP8_SPEEDY_BOUND_RES_1 > SW_VP8_SPEEDY_BOUND_RES_2)
    #error "Invalid SW_VP8_SPEEDY_BOUND_RES_1"
#endif

int SWVP8QuerySpeedyMode(int width, int height, int framerate, int bitrate);
int SWVP8QueryDynamicSwitch(int width, int height, int framerate, int bitrate);
int SWVP8QueryDynamicSwitchSetting(int width, int height, int framerate, int bitrate);
int SWVP8QueryAsyncTolerance(int width, int height, int framerate, int bitrate);
int SWVP8QuerySpeedyModeOffset(int width, int height, int framerate, int bitrate);

#ifdef __cplusplus
    }
#endif
