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
 *   color_drv_6260_series.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of COLOR driver for MT6260 series chip.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#if defined(__DRV_COLOR_MT6260_SERIES__) && defined(__DRV_COLOR_HW_SUPPORT__)

#ifdef FPGA
   #include "typedefs.h"
#else
   #include "kal_general_types.h"
   #include "kal_public_api.h"
#endif

#include "color_drv_api.h"
#include "color_drv_6260_series.h"



/**
 * Call this function to power on COLOR.
 */
static kal_uint32 _color_drv_power_on(void)
{
#if defined(__MTK_TARGET__)
   #if defined(DRV_FEATURE__MM_POWER_CTRL_IF) || defined(__CLKG_DEFINE__)
      mm_enable_power(MMCG_COLOR_BIT);
   #else
      /// power on COLOR.
      REG_MMCG_CLR |= MMCG_COLOR_BIT;
   #endif
#endif

   return 1;
}



/**
 * Call this function to power off COLOR.
 */
static kal_uint32 _color_drv_power_off(void)
{
#if defined(__MTK_TARGET__)
   #if defined(DRV_FEATURE__MM_POWER_CTRL_IF) || defined(__CLKG_DEFINE__)
      mm_disable_power(MMCG_COLOR_BIT);
   #else
      /// power on COLOR.
      REG_MMCG_CLR |= MMCG_COLOR_BIT;
   #endif
#endif

   return 1;
}



/**
 * Call this function to power on COLOR.
 */
kal_uint32 color_drv_power_on(void)
{
   _color_drv_power_on();

   return 1;
}



/**
 * Call this function to power off COLOR.
 */
kal_uint32 color_drv_power_off(void)
{
   _color_drv_power_off();

   return 1;
}



/**
 * Call this function to set the sharpness of COLOR.
 */
kal_uint32 color_drv_set_sharpness(kal_uint32 gain, kal_uint32 soft_ratio, kal_uint32 limit, kal_uint32 bound)
{
   kal_uint32 sharp_control = REG_COLOR_SHARP_CON;

   sharp_control = (sharp_control & (~0xFF)) | gain;
   sharp_control = (sharp_control & (~0x3F00)) | (bound << 8);
   sharp_control = (sharp_control & (~0x3F0000)) | (limit << 16);
   sharp_control = (sharp_control & (~0xF000000)) | (soft_ratio << 24);
   REG_COLOR_SHARP_CON = sharp_control;

   return 1;
}



/**
 * Call this function to set the contrast point of COLOR.
 */
kal_uint32 color_drv_set_contrast_point(kal_uint32 point0, kal_uint32 point1)
{
   kal_uint32 contrast_point = REG_COLOR_CONTRAST_POINT;

   contrast_point = (contrast_point & (~0xFF)) | point0;
   contrast_point = (contrast_point & (~0xFF00)) | (point1 << 8);
   REG_COLOR_CONTRAST_POINT = contrast_point;

   return 1;
}



/**
 * Call this function to set the contrast gain of COLOR.
 */
kal_uint32 color_drv_set_contrast_gain(kal_uint32 gain0, kal_uint32 gain1, kal_uint32 gain2)
{
   kal_uint32 contrast_gain = REG_COLOR_CONTRAST_GAIN;

   contrast_gain = (contrast_gain & (~0xFF)) | gain0;
   contrast_gain = (contrast_gain & (~0xFF00)) | (gain1 << 8);
   contrast_gain = (contrast_gain & (~0xFF0000)) | (gain2 << 16);
   REG_COLOR_CONTRAST_GAIN = contrast_gain;

   return 1;
}



/**
 * Call this function to set the contrast offset of COLOR.
 */
kal_uint32 color_drv_set_contrast_offset(kal_uint32 offset0, kal_uint32 offset1)
{
   kal_uint32 contrast_offset = REG_COLOR_CONTRAST_OFFSET;

   contrast_offset = (contrast_offset & (~0xFFFF)) | offset0;
   contrast_offset = (contrast_offset & (~0xFFFF0000)) | (offset1 << 16);
   REG_COLOR_CONTRAST_OFFSET = contrast_offset;

   return 1;
}



/**
 * Call this function to set the saturation point of COLOR.
 */
kal_uint32 color_drv_set_saturation_point(kal_uint32 con_point, kal_uint32 coef_a, kal_uint32 coef_b)
{
   kal_uint32 saturation_point = REG_COLOR_SAT_POINT;

   saturation_point = (saturation_point & (~0xFF)) | coef_b;
   saturation_point = (saturation_point & (~0xFF00)) | (coef_a << 8);
   saturation_point = (saturation_point & (~0xFFF0000)) | (con_point << 16);
   REG_COLOR_SAT_POINT = saturation_point;

   return 1;
}



/**
 * Call this function to set the saturation gain of COLOR.
 */
kal_uint32 color_drv_set_saturation_gain(kal_uint32 gain)
{
   kal_uint32 saturation_gain = REG_COLOR_SAT_GAIN;

   saturation_gain = (saturation_gain & (~0xFF)) | gain;
   REG_COLOR_SAT_GAIN = saturation_gain;

   return 1;
}



/**
 * Call this function to set the source size of COLOR.
 */
kal_uint32 color_drv_set_source_size(kal_uint32 src_w)
{
   kal_uint32 source_size = REG_COLOR_SRC_SIZE;

   source_size = (source_size & (~0x7FF)) | src_w;
   REG_COLOR_SRC_SIZE = source_size;

   return 1;
}



/**
 * Call this function to set the bypass of COLOR.
 */
kal_uint32 color_drv_set_bypass(kal_uint32 bypass_config)
{
   kal_uint32 bypass = REG_COLOR_BYPASS;

   bypass = (bypass & (~0x11F)) | bypass_config;
   REG_COLOR_BYPASS = bypass;

   return 1;
}



/**
 * Call this function to set the bypass of COLOR.
 */
kal_uint32 color_drv_set_enable(kal_uint32 enable)
{
   kal_uint32 en = REG_COLOR_EN;

   en = (en & (~0x1)) | enable;
   REG_COLOR_EN = en;

   return 1;
}


#endif  // __DRV_COLOR_MT6260_SERIES__

