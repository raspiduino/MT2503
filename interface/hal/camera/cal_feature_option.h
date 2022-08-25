/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAL_FEATURE_OPTION_H__
#define __CAL_FEATURE_OPTION_H__

#include "isp_hw_feature_def.h"

#undef __CAL_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#undef __CAL_CAPTURE_MODE_BSS_SUPPORT__
#undef __CAL_CAPTURE_MODE_ZSD_SUPPORT__
#undef __CAL_CAPTURE_MODE_ASD_SUPPORT__
#undef __CAL_VIDEO_MJPEG_DIRECT_COUPLE_SUPPORT__

#ifdef __ISP_CAPTURE_MODE_EV_BRACKET_SUPPORT__
    #define __CAL_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#endif

#ifdef __ISP_CAPTURE_MODE_BEST_SHOT_SUPPORT__
    #define __CAL_CAPTURE_MODE_BSS_SUPPORT__
#endif

#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
    #define __CAL_CAPTURE_MODE_ZSD_SUPPORT__
#endif

#ifdef __AUTO_SCENE_DETECT_SUPPORT__
    #define __CAL_CAPTURE_MODE_ASD_SUPPORT__
#endif

#if !(defined(MT6268)||defined(MT6235)||defined(MT6253)||defined(MT6253D)||defined(MT6253T)||defined(MT6253PMU)||defined(MT6236)||defined(__JPEG_SENSOR_SUPPORT__)||defined(__LOW_COST_SUPPORT_COMMON__)||defined(__MMI_MAINLCD_480X800__)||defined(__MMI_MAINLCD_800X480__))
    #define __CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__
#endif

#if (defined(MT6256) && defined(__MJPEG_ENC_SUPPORT__))
    #define __CAL_VIDEO_MJPEG_DIRECT_COUPLE_SUPPORT__
#endif

#if defined(MT6250)||defined(MT6260)||defined(MT6261)||defined(MT2501)||defined(MT2502)
    #define __CAL_DISABLE_JAIA_SUPPORT__
#endif

#endif /* __CAL_FEATURE_OPTION_H__ */

