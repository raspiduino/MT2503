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
 *   iul_sd_macros.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: macros for SW spatial dithering
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_SD_MACROS_H__
#define __IUL_SD_MACROS_H__

#include "iul_rng.h"


/**
 * @brief   Macro to saturate a value to zero.
 */
#define IUL_SD_SATURATE_ZERO(value)     (~((signed int)(value) >> 31) & (value))



/**
 * @brief   Initialization for spatial dithering.
 * @remarks Invoke this macro right after the variable declaration of the function.
 */
#define IUL_SD_INITIALIZE()                              \
   unsigned int sd_noise = 0;                            \
   int sd_noise_bit = -1;                                \
   IUL_RNG_MWC_INITIALIZE();                             \



/**
 * @brief               Convert a RGB888 pixel into RGB565 format with dithering.
 * @param r             R component.
 * @param g             G component.
 * @param b             B component.
 * @param pDst          pointer to the output RGB565 data.
 * @remarks             the pDst pointer will not be advanced in the macro.
 */
#define IUL_SD_RGB888_TO_RGB565(r, g, b, pDst)           \
do {                                                     \
   int noise;                                            \
   int out0, out1, out2;                                 \
   if (--sd_noise_bit < 0)                               \
   {                                                     \
      sd_noise_bit = 10;                                 \
      IUL_RNG_MWC_GENERATE(sd_noise);                    \
   }                                                     \
   noise = sd_noise & 7;                                 \
   sd_noise >>= 3;                                       \
   out0 = ((signed)(r) - noise) >> 3;                    \
   out0 = IUL_SD_SATURATE_ZERO(out0);                    \
   out2 = ((signed)(b) - noise) >> 3;                    \
   out2 = IUL_SD_SATURATE_ZERO(out2);                    \
   out1 = ((signed)(g) - (noise >> 1)) >> 2;             \
   out1 = IUL_SD_SATURATE_ZERO(out1);                    \
   *(pDst) = (out0 << 11) | (out1 << 5) | out2;          \
} while (0)



/**
 * @brief               Convert a RGB888 pixel into RGB565 format with dithering.
 * @param r             R component.
 * @param g             G component.
 * @param b             B component.
 * @param srcKey        Source key color
 * @param pDst          pointer to the output RGB565 data.
 * @remarks             the pDst pointer will not be advanced in the macro.
 */
#define IUL_SD_RGB888_TO_RGB565_WITH_SRCKEY(r, g, b, srcKey, pDst)      \
do {                                                                    \
   unsigned short packed_output;                                        \
   int noise;                                                           \
   int out0, out1, out2;                                                \
   if (--sd_noise_bit < 0)                                              \
   {                                                                    \
      sd_noise_bit = 10;                                                \
      IUL_RNG_MWC_GENERATE(sd_noise);                                   \
   }                                                                    \
   noise = sd_noise & 7;                                                \
   sd_noise >>= 3;                                                      \
   out0 = ((signed)(r) - noise) >> 3;                                   \
   out0 = IUL_SD_SATURATE_ZERO(out0);                                   \
   out2 = ((signed)(b) - noise) >> 3;                                   \
   out2 = IUL_SD_SATURATE_ZERO(out2);                                   \
   out1 = ((signed)(g) - (noise >> 1)) >> 2;                            \
   out1 = IUL_SD_SATURATE_ZERO(out1);                                   \
   packed_output = (out0 << 11) | (out1 << 5) | out2;                   \
   if (srcKey == packed_output)                                         \
   {                                                                    \
      packed_output ^= 1;                                               \
   }                                                                    \
   *(pDst) = packed_output;                                             \
} while (0)



/**
 * @brief               Add 2-bits dithering to a RGB888 pixel.
 * @param c0            the 1st color component.
 * @param c1            the 2nd color component.
 * @param c2            the 3rd color component.
 * @param pDst          pointer to the output RGB888 data.
 * @remarks             the pDst pointer will not be advanced in the macro.
 */
#define IUL_SD_RGB888_2BITS_DITHERING(c0, c1, c2, pDst)        \
do {                                                           \
   int noise;                                                  \
   int out0, out1, out2;                                       \
   if (--sd_noise_bit < 0)                                     \
   {                                                           \
      sd_noise_bit = 16;                                       \
      IUL_RNG_MWC_GENERATE(sd_noise);                          \
   }                                                           \
   noise = sd_noise & 3;                                       \
   sd_noise >>= 2;                                             \
   out0 = (signed)(c0) - noise;                                \
   out0 = IUL_SD_SATURATE_ZERO(out0);                          \
   out1 = (signed)(c1) - noise;                                \
   out1 = IUL_SD_SATURATE_ZERO(out1);                          \
   out2 = (signed)(c2) - noise;                                \
   out2 = IUL_SD_SATURATE_ZERO(out2);                          \
   (pDst)[0] = out0;                                           \
   (pDst)[1] = out1;                                           \
   (pDst)[2] = out2;                                           \
} while (0)



/**
 * @brief               Add 2-bits dithering to a RGB888 pixel.
 * @param c0            the 1st color component.
 * @param c1            the 2nd color component.
 * @param c2            the 3rd color component.
 * @param srcKey0       the 1st color component of source key color
 * @param srcKey1       the 2nd color component of source key color
 * @param srcKey2       the 3rd color component of source key color
 * @param pDst          pointer to the output RGB888 data.
 * @remarks             the pDst pointer will not be advanced in the macro.
 */
#define IUL_SD_RGB888_2BITS_DITHERING_WITH_SRCKEY(c0, c1, c2, srcKey0, srcKey1, srcKey2, pDst)  \
do {                                                           \
   int noise;                                                  \
   int out0, out1, out2;                                       \
   if (--sd_noise_bit < 0)                                     \
   {                                                           \
      sd_noise_bit = 16;                                       \
      IUL_RNG_MWC_GENERATE(sd_noise);                          \
   }                                                           \
   noise = sd_noise & 3;                                       \
   sd_noise >>= 2;                                             \
   out0 = (signed)(c0) - noise;                                \
   out0 = IUL_SD_SATURATE_ZERO(out0);                          \
   out1 = (signed)(c1) - noise;                                \
   out1 = IUL_SD_SATURATE_ZERO(out1);                          \
   out2 = (signed)(c2) - noise;                                \
   out2 = IUL_SD_SATURATE_ZERO(out2);                          \
   if (out0 == srcKey0 && out1 == srcKey1 && out2 == srcKey2)  \
   {                                                           \
      out1 ^= 1;                                               \
   }                                                           \
   (pDst)[0] = out0;                                           \
   (pDst)[1] = out1;                                           \
   (pDst)[2] = out2;                                           \
} while (0)


#endif /// __IUL_SD_MACROS_H__
