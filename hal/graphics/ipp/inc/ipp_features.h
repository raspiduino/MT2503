/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ipp_features.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of IPP(image post process) APIs.
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #ifndef __IPP_FEATURES_H__
#define __IPP_FEATURES_H__


#undef IPP_STANDALONE
#if defined(IPP_STANDALONE)
   #include "kal_general_types.h"
   #include "stdlib.h"
   #include "stdio.h"
   #include "string.h"
   #include "math.h"
   #include "assert.h"

   #if !defined(ASSERT)
   #define ASSERT assert
   #endif
#endif

/// RHR suggestion
#include "drv_features.h"

#undef   _IPP_PIXEL_EFFECT_GRAYSCALE
#undef   _IPP_PIXEL_EFFECT_SEPIA
#undef   _IPP_PIXEL_EFFECT_SEPIAGREEN
#undef   _IPP_PIXEL_EFFECT_SEPIABLUE
#undef   _IPP_PIXEL_EFFECT_COLORINV
#undef   _IPP_PIXEL_EFFECT_GRAYINV

#undef   _IPP_BLOCK_EFFECT_WATERCOLOR
#undef   _IPP_BLOCK_EFFECT_LIGHTBLUR
#undef   _IPP_BLOCK_EFFECT_BLUR
#undef   _IPP_BLOCK_EFFECT_STRONGBLUR
#undef   _IPP_BLOCK_EFFECT_UNSHARP
#undef   _IPP_BLOCK_EFFECT_SHARPEN
#undef   _IPP_BLOCK_EFFECT_MORESHARPEN
#undef   _IPP_BLOCK_EFFECT_MEDIAN
#undef   _IPP_BLOCK_EFFECT_DILATION
#undef   _IPP_BLOCK_EFFECT_EROSION



#ifdef DRV_PIXEL_EFFECT_SUPPORT

   #if defined(MT6236) || defined(MT6236B)
   #define   _IPP_PIXEL_EFFECT_GRAYSCALE
   #define   _IPP_PIXEL_EFFECT_SEPIA
   #define   _IPP_PIXEL_EFFECT_SEPIAGREEN
   #define   _IPP_PIXEL_EFFECT_SEPIABLUE
   #define   _IPP_PIXEL_EFFECT_COLORINV
   #define   _IPP_PIXEL_EFFECT_GRAYINV
   #endif
   
   #if defined(MT6268)
   #define   _IPP_PIXEL_EFFECT_GRAYSCALE
   #define   _IPP_PIXEL_EFFECT_SEPIA
   #define   _IPP_PIXEL_EFFECT_SEPIAGREEN
   #define   _IPP_PIXEL_EFFECT_SEPIABLUE
   #define   _IPP_PIXEL_EFFECT_COLORINV
   #define   _IPP_PIXEL_EFFECT_GRAYINV
   #endif

#endif /// DRV_PIXEL_EFFECT_SUPPORT



/// For Block effect
#ifdef DRV_BLOCK_EFFECT_SUPPORT

   #define   _IPP_BLOCK_EFFECT_WATERCOLOR
   #define   _IPP_BLOCK_EFFECT_LIGHTBLUR
   #define   _IPP_BLOCK_EFFECT_BLUR
   #define   _IPP_BLOCK_EFFECT_STRONGBLUR
   #define   _IPP_BLOCK_EFFECT_UNSHARP
   #define   _IPP_BLOCK_EFFECT_SHARPEN
   #define   _IPP_BLOCK_EFFECT_MORESHARPEN
   #define   _IPP_BLOCK_EFFECT_MEDIAN
   #define   _IPP_BLOCK_EFFECT_DILATION
   #define   _IPP_BLOCK_EFFECT_EROSION

   #if defined(DRV_IDP_6253_SERIES)
   #undef   _IPP_BLOCK_EFFECT_WATERCOLOR
   #undef   _IPP_BLOCK_EFFECT_MEDIAN
   #undef   _IPP_BLOCK_EFFECT_DILATION
   #undef   _IPP_BLOCK_EFFECT_EROSION
   #endif

#endif /// DRV_PIXEL_EFFECT_SUPPORT

#endif /// __IPP_FEATURES_H__
