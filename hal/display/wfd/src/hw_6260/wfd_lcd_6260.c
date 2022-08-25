/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    wfd_lcd_6256.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the body of MT6256 LCD HW driver.
 *    This file is only for target.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_display.h"
#if defined(DRV_LCD_MT6260_SERIES)
#if defined(__MTK_TARGET__)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_hisr.h"
#include "intrCtrl.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd_common.h"
#include "wfd\inc\wfd_lcd_internal.h"
#include "wfd\inc\hw_6250\wfd_lcd_6250.h"
#include "lcd_if_manager.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfdplatform.h"
#include "mm_power_ctrl.h"
#include "reg_base.h"
#include "kal_release.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "common/owftypes.h"
#include "common/owfimage.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "nli_arb.h"        ///for NLI_ARB driver

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/

static WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM
__wfd_lcd_CnvtFormatToHwDef6250
(OWF_IMAGE_FORMAT *format)
{
  switch (format->pixelFormat)
  {
     // MT6260 do not support 8bpp index color
     case OWF_IMAGE_L8:      { return WFD_LCD_LAYER_FORMAT_8BPP_INDEX; }

     case OWF_IMAGE_RGB565:  { return WFD_LCD_LAYER_FORMAT_RGB565; }

     case OWF_IMAGE_UYVY:    { return WFD_LCD_LAYER_FORMAT_UYVY422; }

     case OWF_IMAGE_RGB888:  { return WFD_LCD_LAYER_FORMAT_RGB888; }

     case OWF_IMAGE_ARGB8888:
     {
        if (format->premultiplied) { return WFD_LCD_LAYER_FORMAT_PARGB8888; }
        return WFD_LCD_LAYER_FORMAT_ARGB8888;
     }
     case OWF_IMAGE_ARGB6666:  
     {
        if (format->premultiplied) { return WFD_LCD_LAYER_FORMAT_PARGB6666; }
        return WFD_LCD_LAYER_FORMAT_ARGB6666;
     }

     default:
     {
        WFD_ASSERT_CHECK(&_wfd_lcd_primitives, 0, WFD_ERROR_ILLEGAL_ARGUMENT, LCD_LAYER_MONO);
        return WFD_LCD_LAYER_FORMAT_RSD;
     }
  }

  //return WFD_LCD_LAYER_FORMAT_RSD;
}



kal_uint32 dbi_high_threshold = 0x80;
kal_uint32 dbi_low_threshold = 0x40;
kal_uint32 gmc_high_threshold = 0x80;
kal_uint32 gmc_low_threshold = 0x40;
float video_frame_freq = 30;


static void
__wfd_lcd_ConfigPerformancePara6250(WFD_PORT* port, LCD_IOCTRL_DEVICE_IF_T* if_mgr_setting)
{
       float  temp1, temp2;
       WFDint val;
       WFDint lcd_clock_freq = 104000000; //default value
       WFD_PORT_CONFIG* pPortCfg = &(port->config);
	   NLI_ARB_SET_QUERY_FAVOR_STRUCT nli_arb_struct;
   
       temp1 = (((pPortCfg->nativeResolution[0] * pPortCfg->nativeResolution[1] * pPortCfg->refreshRate) * 32) / lcd_clock_freq) * 32; /*(2048 >> 1)*/ // to avoid overflow 32 bits

       if (pPortCfg->refreshRate > video_frame_freq)
       {
          WFDint tempMul, tempSubtra;

          tempSubtra = pPortCfg->refreshRate - video_frame_freq;
          tempMul = pPortCfg->refreshRate * video_frame_freq;
          if (tempSubtra)
          {
            temp2 = (((pPortCfg->nativeResolution[0] * pPortCfg->nativeResolution[1] * tempMul / tempSubtra) * 64) / lcd_clock_freq) * 32; /*(2048 >> 1)*/ // to avoid overflow 32 bits
            if (temp2 > temp1)
            {
              temp1 = temp2;
            }
          }
       }
       val = (WFDint) temp1;
       SET_LCD_CONSUME_RATE(val);
       SET_LCD_DBI_ULTRA_HIGH_THRESHOLD(dbi_low_threshold, (val+10)); // the threshlod value is just recommended.
       SET_LCD_GMC_ULTRA_HIGH_THRESHOLD(gmc_low_threshold, (val+10)); // the threshlod value is just recommended.
	   nli_arb_struct.enable = KAL_FALSE;
	   NLI_ARB_IOCtrl(NLI_ARB_USER_LCD, NLI_ARB_SET_FAVOR_NORMAL, (void *)&nli_arb_struct);
	   NLI_ARB_IOCtrl(NLI_ARB_USER_LCD, NLI_ARB_SET_FAVOR_ULTRA, (void *)&nli_arb_struct);

       ENABLE_DBI_ULTRA_HIGH();
       //ENABLE_GMC_ULTRA_HIGH();
}


WFDuint  __wfd_lcd_CnvtW2memFormatToHwDef6250(OWF_IMAGE_FORMAT *format)
{
    switch (format->pixelFormat)
    {
        case OWF_IMAGE_RGB565:
            return WFD_LCD_WMEM_COLOR_RGB565;

        case OWF_IMAGE_RGB888:
            return WFD_LCD_WMEM_COLOR_RGB888;

        case OWF_IMAGE_ARGB8888:
            if (format->premultiplied)
                return WFD_LCD_WMEM_COLOR_ARGB8888_PIXEL_ALPHA;
            else
                return WFD_LCD_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA;
                
        case OWF_IMAGE_ARGB6666:
            if (format->premultiplied)
                 return WFD_LCD_WMEM_COLOR_PARGB6666_PIXEL_ALPHA;
            else
                return WFD_LCD_WMEM_COLOR_PARGB6666_CONSTANT_ALPHA;
                
 //       case OWF_IMAGE_PARGB6666:
 //                return WFD_LCD_WMEM_COLOR_PARGB6666_PIXEL_ALPHA;
                 
 //       case OWF_IMAGE_PARGB6666_WITH_CONST_ALPHA:
 //                return WFD_LCD_WMEM_COLOR_PARGB6666_CONSTANT_ALPHA;

        default:
            ASSERT(0);
            return WFD_LCD_WMEM_COLOR_RSVD;
    }
}


/*!
 *  Overwrite internal common-used utilities functions as specific chip dependent function.
 *
 *  \param plcd_utilities   internal used utility function table
 *
 *  \return                 Error code...
 *  \note                   common-used utilities are defined in wfd_lcd_common.c. But sometimes
 *                          you might need to implement a specific function which is not suppported
 *                          in common-used utilities. You can replace the function pointer
 *                          in this function.
 */
WFDErrorCode wfd_lcd_hook_internal_utility(WFDHWDeviceInternalUtilityMTK *plcd_utilities)
{
   if (NULL == plcd_utilities)
   {
      ASSERT(0);
   }

   
   plcd_utilities->_wfd_CnvtImgFormatToHwDef = (WFDuint (*)(OWF_IMAGE_FORMAT *))__wfd_lcd_CnvtFormatToHwDef6250;
   plcd_utilities->_wfd_ConfigPerformancePara = (void (*)(WFD_PORT* , LCD_IOCTRL_DEVICE_IF_T* ))__wfd_lcd_ConfigPerformancePara6250;
   plcd_utilities->_wfd_CnvtW2memFormatToHwDef = __wfd_lcd_CnvtW2memFormatToHwDef6250;
   return WFD_ERROR_NONE;
}

#ifdef __cplusplus
}
#endif

#endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(DRV_LCD_MT6260_SERIES)

