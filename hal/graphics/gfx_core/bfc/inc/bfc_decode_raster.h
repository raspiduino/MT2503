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
 *   bmp_font_raster.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Bitmap font decoder interfaces
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BFC_DECODE_RASTER_H__
#define __BFC_DECODE_RASTER_H__

#include "bfc_decode_structure.h"
#include "bfc_enum.h"

#include "kal_general_types.h"

#if defined(WIN32)
#include "assert.h"
#define ASSERT assert
#else
#include "kal_public_api.h"
#endif

#ifndef MIN
#define MIN(x, y)   (((x) <= (y))? (x): (y))
#endif  // MIN

#ifndef MAX
#define MAX(x, y)   (((x) <= (y))? (y): (x))
#endif  // MIN

extern const kal_int32 tiltTable[];

#define BFC_CHECK_BITS(count)                                                    \
{                                                                                \
   if (bitCount < count) {                                                       \
      do {                                                                       \
         bitBuffer <<= 8;                                                        \
         bitBuffer |= pSrcData[byteIndex++];                                     \
         bitCount  += 8;                                                         \
      } while(bitCount < 24);                                                    \
   }                                                                             \
}

#define BFC_GET_BITS(count)                                                      \
   (((bitBuffer >> (bitCount -= (count)))) & ((1 << (count)) - 1))

#define BFC_SET_PIXEL_NO_CLIP() {                                                \
   if (canvasBPP != 1)                                                           \
   {                                                                             \
      if (pattern & 0x0FF)                                                       \
      {                                                                          \
         if ((fontStyle == BFC_STYLE_ITALIC) ||                                  \
             (fontStyle == BFC_STYLE_BOLD_ITALIC))                               \
         {                                                                       \
            setPixel(pLine0, pitch, pattern, color, glyphHeight);                \
         } else {                                                                \
            setPixel(pLine0, pitch, pattern, color, border);                     \
         }                                                                       \
      }                                                                          \
                                                                                 \
      pLine0 += ((canvasBPP >> 3) << 1);  /* Advance to next two pixel */        \
   }                                                                             \
   else                                                                          \
   {                                                                             \
      if (pattern & 0x0FF)                                                       \
      {                                                                          \
         setPixel(pLine0, pitch, pattern, select, glyphHeight);                  \
      }                                                                          \
                                                                                 \
      pLine0 += ((select + 2) >> 3);  /* Advance to next byte */                 \
   }                                                                             \
}

#define BFC_SET_PIXEL_WITH_CLIP()                                                \
{                                                                                \
   kal_int32 left;                                                               \
   kal_int32 right;                                                              \
   kal_int32 top;                                                                \
   kal_int32 bottom;                                                             \
   kal_int32 width;                                                              \
   kal_int32 height;                                                             \
                                                                                 \
   if (pattern & 0x0FF)                                                          \
   {                                                                             \
      left   = xStart;                                                           \
      if (fontStyle == BFC_STYLE_BORDER)                                         \
      {                                                                          \
         left--;                                                                 \
      }                                                                          \
                                                                                 \
      right  = xStart + 1;                                                       \
      if ((fontStyle == BFC_STYLE_BOLD) ||                                       \
          (fontStyle == BFC_STYLE_BORDER))                                       \
      {                                                                          \
         right ++;                                                               \
      }                                                                          \
      else if (fontStyle == BFC_STYLE_ITALIC)                                    \
      {                                                                          \
         right += tiltTable[glyphHeight - 1];                                    \
      }                                                                          \
      else if (fontStyle == BFC_STYLE_BOLD_ITALIC)                               \
      {                                                                          \
         right += tiltTable[glyphHeight - 1] + 1;                                \
      }                                                                          \
                                                                                 \
      top    = yStart;                                                           \
      if (fontStyle == BFC_STYLE_BORDER)                                         \
      {                                                                          \
         top--;                                                                  \
      }                                                                          \
                                                                                 \
      bottom = yStart + 3;                                                       \
      if (fontStyle == BFC_STYLE_BORDER)                                         \
      {                                                                          \
         bottom ++;                                                              \
      }                                                                          \
                                                                                 \
      if (left < clipLeft)                                                       \
      {                                                                          \
         left = clipLeft;                                                        \
      }                                                                          \
                                                                                 \
      if (right > clipRight)                                                     \
      {                                                                          \
         right = clipRight;                                                      \
      }                                                                          \
                                                                                 \
      if (top < clipTop)                                                         \
      {                                                                          \
         top = clipTop;                                                          \
      }                                                                          \
                                                                                 \
      if (bottom > clipBottom)                                                   \
      {                                                                          \
         bottom = clipBottom;                                                    \
      }                                                                          \
                                                                                 \
      width  = right - left + 1;                                                 \
      left   = left - xStart;                                                    \
      height = bottom - top + 1;                                                 \
      top    = top  - yStart;                                                    \
                                                                                 \
      if ((left < 3) && (width > 0) && (top < 5) && (height > 0))                \
      {                                                                          \
         if (canvasBPP != 1)                                                     \
         {                                                                       \
            if ((fontStyle == BFC_STYLE_ITALIC) ||                               \
                (fontStyle == BFC_STYLE_BOLD_ITALIC))                            \
            {                                                                    \
               setPixel(pLine0,                                                  \
                        pitch,                                                   \
                        pattern,                                                 \
                        color,                                                   \
                        glyphHeight,                                             \
                        left,                                                    \
                        top,                                                     \
                        width,                                                   \
                        height);                                                 \
            }                                                                    \
            else                                                                 \
            {                                                                    \
               setPixel(pLine0,                                                  \
                        pitch,                                                   \
                        pattern,                                                 \
                        color,                                                   \
                        border,                                                  \
                        left,                                                    \
                        top,                                                     \
                        width,                                                   \
                        height);                                                 \
           }                                                                     \
         }                                                                       \
         else                                                                    \
         {                                                                       \
            setPixel(pLine0,                                                     \
                     pitch,                                                      \
                     pattern,                                                    \
                     select,                                                     \
                     glyphHeight,                                                \
                     left,                                                       \
                     top,                                                        \
                     width,                                                      \
                     height);                                                    \
         }                                                                       \
      }                                                                          \
   }                                                                             \
   if (canvasBPP != 1)                                                           \
   {                                                                             \
      pLine0 += ((canvasBPP >> 3) << 1);  /* Advance to next two pixel */        \
   }                                                                             \
   else                                                                          \
   {                                                                             \
      pLine0 += ((select + 2) >> 3);  /* Advance to next byte */                 \
   }                                                                             \
}

#define BFC_INSIDE_CLIP(x, y)                   								         \
   ((((kal_uint32)(x - left)) < (kal_uint32)width) &&          						\
    (((kal_uint32)(y - top)) < (kal_uint32)height))

typedef void (*SetPixelFuncNoClip)(kal_uint8  *pBuffer,
                                   kal_int32  pitch,
                                   kal_uint32 pattern,
                                   kal_uint32 color,
                                   kal_uint32 extra);

typedef void (*SetPixelFuncWithClip)(kal_uint8  *pBuffer,
                                     kal_int32  pitch,
                                     kal_uint32 pattern,
                                     kal_uint32 color,
                                     kal_uint32 extra,
                                     kal_int32  left,
                                     kal_int32  top,
                                     kal_int32  width,
                                     kal_int32  height);

static kal_uint32 firstLine(kal_uint32 pattern)
{
#if defined(__arm) && !defined(__thumb)
   kal_uint32 temp;
   kal_uint32 count;

   __asm
   {
      MOV temp, pattern, LSL 24;
      CLZ count, temp;
   }
   return (count >> 1);
#else
   return 0;
#endif
}

#ifdef __cplusplus
extern "C" {
#endif

BFC_STATUS_ENUM drawGlyphCore(BFC_DECODER_HANDLE handle,
                              const kal_uint8    *pSrcData,
                              kal_int32          glyphWidth,
                              kal_int32          glyphHeight,
                              kal_int32          xPosition,
                              kal_int32          yPosition);

#ifdef __cplusplus
}
#endif

#endif  // __BFC_DECODE_RASTER_H__
