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
 *   color_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition for COLOR.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#ifndef __COLOR_STRUCTURE_H__
#define __COLOR_STRUCTURE_H__

#ifdef FPGA
   #include "typedefs.h"
#else
   #include "kal_general_types.h"
#endif

#include "color_enum.h"


#define COLOR_CUSTOM_SHARPNESS_TABLE_NUM  10
#define COLOR_CUSTOM_CONTRAST_TABLE_NUM  10
#define COLOR_CUSTOM_SATURATION_TABLE_NUM  10

typedef struct _COLOR_CUSTOM_TABLE_T
{
   kal_uint8  Sharpness;
   kal_uint8  Contrast;
   kal_uint8  Saturation;

} COLOR_CUSTOM_TABLE_T;

typedef struct _COLOR_SHARPNESS_T
{
   kal_uint8  Gain;
   kal_uint8  SoftRatio;
   kal_uint8  Limit;
   kal_uint8  Bound;

} COLOR_SHARPNESS_T;


typedef struct _COLOR_CONTRAST_T
{
   kal_uint8  Point0;
   kal_uint8  Point1;
   kal_uint8  Gain0;
   kal_uint8  Gain1;
   kal_uint8  Gain2;

} COLOR_CONTRAST_T;


typedef struct _COLOR_SATURATION_T
{
   kal_uint16  ConPoint;
   kal_uint8   CoefA;
   kal_uint8   Gain;

} COLOR_SATURATION_T;


typedef struct _COLOR_HANDLE_T
{
   COLOR_SCENARIO_ENUM  applyScenario;
   COLOR_STATE_ENUM   colorState;
   COLOR_STATUS_ENUM   lastStatus;

   COLOR_SHARPNESS_T  effectSharpness;
   COLOR_CONTRAST_T  effectContrast;
   COLOR_SATURATION_T  effectSaturation;

   kal_bool  updateConfig;
   kal_uint32  bypassConfig;
   
} COLOR_HANDLE_T;


typedef COLOR_HANDLE_T*   COLOR_HANDLE;


#endif  // __COLOR_STRUCTURE_H__

