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
 *   yuv_rotator_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   YUV Rotator
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
#ifndef __YUV_ROTATOR_STRUCTURE_H__
#define __YUV_ROTATOR_STRUCTURE_H__

#include "kal_general_types.h"

#include "rotator_enum.h"

#include "gfx_cache_switch_behavior_enum.h"

typedef struct YUV_ROTATOR_WINDOW_STRUCT_T
{
   kal_int32 startX;          /// x of the buffer
   kal_int32 startY;          /// y of the buffer
   kal_uint32 width;          /// the width of the buffer
   kal_uint32  height;        /// the height of the buffer
} YUV_ROTATOR_WINDOW_STRUCT;



typedef struct YUV_ROTATOR_HANDLE_STRUCT_T
{
   ROTATOR_STATE_ENUM state;
   ROTATOR_TYPE_ENUM type;
   ROTATOR_MODE_ENUM mode;

   ROTATOR_COLOR_FORMAT_ENUM srcColorFormat;
   void *srcBuffer[3];
   kal_uint32 srcBufferSize[3];

   kal_uint32 srcWidth;
   kal_uint32 srcHeight;
   YUV_ROTATOR_WINDOW_STRUCT srcWindow;

   ROTATOR_COLOR_FORMAT_ENUM dstColorFormat;
   void *dstBuffer[3];
   kal_uint32 dstBufferSize[3];

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
      GFX_CACHE_SWITCH_BEHAVIOR_ENUM srcBufferCacheSwitchBehavior;
      GFX_CACHE_SWITCH_BEHAVIOR_ENUM dstBufferCacheSwitchBehavior;
      ROTATOR_MEMORY_TYPE_ENUM srcCanvasType;
      ROTATOR_MEMORY_TYPE_ENUM dstCanvasType;
   #endif

   kal_uint32 dstWidth;
   kal_uint32 dstHeight;
   YUV_ROTATOR_WINDOW_STRUCT dstWindow;

   ROTATOR_CW_ROTATE_ANGLE_ENUM rotation;

   void *intMemoryAddr;
   void *extMemoryAddr;
   kal_uint32 intMemorySize;
   kal_uint32 extMemorySize;

   kal_uint32 intMemorySizeMinimum;
   kal_uint32 extMemorySizeMinimum;
   kal_uint32 intMemorySizeBest;
   kal_uint32 extMemorySizeBest;

   /// abort function
   kal_int32 (*checkAbortFunc)(void);

   ROTATOR_CALLBACK_FUNC_PTR yuvRotatorCallback;

} YUV_ROTATOR_HANDLE_STRUCT;

#endif

