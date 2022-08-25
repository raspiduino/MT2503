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
 *   color_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of COLOR(picture quality tuning) interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#ifdef FPGA
   #include "typedefs.h"
   #include "maui_to_fpga.h"
#else
   #include "kal_general_types.h"
   #include "kal_public_api.h"
   #include "kal_public_defs.h"
   #include "string.h"
#endif

#include "color_enum.h"
#include "color_structure.h"
#include "color_api.h"
#include "color_drv_api.h"
#include "ex_public.h"

#if defined(__DRV_COLOR_HW_SUPPORT__)
   #include "lcd_if_hw.h"
   #include "mmsys_pq_path.h"

   static kal_uint8 colorCustomSharpnessTableIndex = 0xFF;
   static kal_uint8 colorCustomContrastTableIndex = 0xFF;
   static kal_uint8 colorCustomSaturationTableIndex = 0xFF;
   static kal_uint8 colorCustomEnable = 0xFF;
   static COLOR_HANDLE_T _color_handle;
   static kal_uint8 colorCurrSharpnessTableIndex = 0;
   static kal_uint8 colorCurrContrastTableIndex = 0;
   static kal_uint8 colorCurrSaturationTableIndex = 0;
   static kal_uint8 colorTargetSharpnessTableIndex = 0;
   static kal_uint8 colorTargetContrastTableIndex = 0;
   static kal_uint8 colorTargetSaturationTableIndex = 0;
   static kal_uint8 SharpnessStep = 0;
   static kal_uint8 ContrastStep = 0;
   static kal_uint8 SaturationStep = 0;

   static kal_uint8 COLOR_STEP_DIVSOR = 2;
   static kal_bool UseMDPPath = KAL_FALSE;
   static kal_bool SystemInitial = KAL_FALSE;

   extern COLOR_PATH_ENUM colorCustomPathTable[MAX_COLOR_SCENARIO];
   extern COLOR_CUSTOM_TABLE_T colorCustomTableIndex[MAX_COLOR_SCENARIO];
   extern COLOR_SHARPNESS_T colorCustomSharpnessTable[COLOR_CUSTOM_SHARPNESS_TABLE_NUM+1];
   extern COLOR_CONTRAST_T colorCustomContrastTable[COLOR_CUSTOM_CONTRAST_TABLE_NUM+1];
   extern COLOR_SATURATION_T colorCustomSaturationTable[COLOR_CUSTOM_SATURATION_TABLE_NUM+1];
   kal_mutexid pq_state_mutex = NULL;
   kal_mutexid pq_setting_mutex = NULL;
  #if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
/* under construction !*/
  #endif
#endif

//#define COLOR_STEP_DIVSOR 2

#if defined(__MTK_TARGET__)
EX_BBREG_DUMP pq_dump;
const kal_uint32 pq_dump_regions[] = {
#if defined(MT6260) || defined(MT6261) || defined(MT2501)|| defined(MT2502)
   0xA0470000, 0x160, 4
#else
   0, 0, 0
#endif
};
#endif /* __MTK_TARGET__ */


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
static COLOR_STATUS_ENUM _colorGetHandle(COLOR_HANDLE *handle_ptr, COLOR_SCENARIO_ENUM scenario)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   if (KAL_TRUE != INT_QueryExceptionStatus())
   {
      while(1)
      {
         kal_take_mutex(pq_state_mutex);
         if(COLOR_STATE_FREE != (_color_handle.colorState))
         {
            kal_give_mutex(pq_state_mutex);
            continue;
         }
         else
         {
            _color_handle.colorState = COLOR_STATE_IDLE;
            _color_handle.applyScenario = scenario;
            *handle_ptr = (COLOR_HANDLE)&_color_handle;
            kal_give_mutex(pq_state_mutex);
            break;
         }
      }
   }
   else
   {
      while(1)
      {
         if(COLOR_STATE_FREE != (_color_handle.colorState))
         {
            continue;
         }
         else
         {
            break;
         }
      }
      _color_handle.colorState = COLOR_STATE_IDLE;
      _color_handle.applyScenario = scenario;
      *handle_ptr = (COLOR_HANDLE)&_color_handle;
   }
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
static COLOR_STATUS_ENUM _colorReleaseHandle(COLOR_HANDLE handle)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   if (KAL_TRUE != INT_QueryExceptionStatus())
   {
      kal_take_mutex(pq_state_mutex);
      _color_handle.colorState = COLOR_STATE_FREE;
      _color_handle.applyScenario = COLOR_SCENARIO_DEFAULT;
      kal_give_mutex(pq_state_mutex);
   }
   else
   {
      _color_handle.colorState = COLOR_STATE_FREE;
      _color_handle.applyScenario = COLOR_SCENARIO_DEFAULT;
   }
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
static COLOR_STATUS_ENUM _colorSetSharpness(COLOR_HANDLE handle, COLOR_SHARPNESS_T *sharpness)
{
#if defined(__DRV_COLOR_HW_SUPPORT__) && defined(__DRV_COLOR_SUPPORT_SHARPNESS__)
   kal_uint32 colorBypass;
   COLOR_STATUS_ENUM colorStatus;
   COLOR_SHARPNESS_T  *effectSharpness;
   
   if (NULL == sharpness)
   {
      ASSERT(0);
   }

   colorBypass = handle->bypassConfig & (~COLOR_BYPASS_SHARP);
   if ((0xFF == sharpness->Gain) 
        && (0xFF == sharpness->SoftRatio) 
        && (0xFF == sharpness->Limit)
        && (0xFF == sharpness->Bound)
        )
   {
      colorBypass |= COLOR_BYPASS_SHARP;
      //handle->bypassConfig = colorBypass;
   }
   handle->bypassConfig = colorBypass;
   effectSharpness = &(handle->effectSharpness);
   memcpy(effectSharpness, sharpness, sizeof(COLOR_SHARPNESS_T));

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNSUPPORTED_EFFECT;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
static COLOR_STATUS_ENUM _colorSetContrast(COLOR_HANDLE handle, COLOR_CONTRAST_T *contrast)
{
#if defined(__DRV_COLOR_HW_SUPPORT__) && defined(__DRV_COLOR_SUPPORT_CONTRAST__)
   kal_uint32 colorBypass;
   COLOR_CONTRAST_T  *effectContrast;
   
   if (NULL == contrast)
   {
      ASSERT(0);
   }

   colorBypass = handle->bypassConfig & (~COLOR_BYPASS_CONTRAST);
   if ((0xFF == contrast->Point0) 
        && (0xFF == contrast->Point1) 
        && (0xFF == contrast->Gain0)
        && (0xFF == contrast->Gain1)
        && (0xFF == contrast->Gain2)
        )
   {
      colorBypass |= COLOR_BYPASS_CONTRAST;
      //handle->bypassConfig = colorBypass;
   }
   handle->bypassConfig = colorBypass;
   effectContrast = &(handle->effectContrast);
   memcpy(effectContrast, contrast, sizeof(COLOR_CONTRAST_T));

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNSUPPORTED_EFFECT;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
static COLOR_STATUS_ENUM _colorSetSaturation(COLOR_HANDLE handle, COLOR_SATURATION_T *saturation)
{
#if defined(__DRV_COLOR_HW_SUPPORT__) && defined(__DRV_COLOR_SUPPORT_SATURATION__)
   kal_uint32 colorBypass;
   COLOR_SATURATION_T  *effectSaturation;
   
   if (NULL == saturation)
   {
      ASSERT(0);
   }

   colorBypass = handle->bypassConfig & (~COLOR_BYPASS_SAT);
   if ((0xFFFF == saturation->ConPoint) 
        && (0xFF == saturation->CoefA) 
        && (0xFF == saturation->Gain)
        )
   {
      colorBypass |= COLOR_BYPASS_SAT;
      //handle->bypassConfig = colorBypass;
   }
   handle->bypassConfig = colorBypass;
   effectSaturation = &(handle->effectSaturation);
   memcpy(effectSaturation, saturation, sizeof(COLOR_SATURATION_T));

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNSUPPORTED_EFFECT;

#endif
}


COLOR_STATUS_ENUM _colorUpdateParameter(COLOR_SHARPNESS_T *sharpnessTable, COLOR_CONTRAST_T *contrastTable, COLOR_SATURATION_T *saturationTable)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   kal_uint32 colorBypass = COLOR_BYPASS_STALL;
   COLOR_HANDLE handle = (COLOR_HANDLE)&_color_handle;
   
   _colorSetSharpness(handle, sharpnessTable);
   _colorSetContrast(handle, contrastTable);
   _colorSetSaturation(handle, saturationTable);
   return COLOR_STATUS_OK;
#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorInit(void)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_SHARPNESS_T *sharpnessTable;
   COLOR_CONTRAST_T *contrastTable;
   COLOR_SATURATION_T *saturationTable;

   COLOR_SHARPNESS_T  *effectSharpness;
   COLOR_CONTRAST_T  *effectContrast;
   COLOR_SATURATION_T  *effectSaturation;

   _color_handle.applyScenario = COLOR_SCENARIO_DEFAULT;
   _color_handle.colorState = COLOR_STATE_FREE;
   _color_handle.lastStatus = COLOR_STATUS_OK;
   _color_handle.bypassConfig = 0;
   UseMDPPath = KAL_FALSE;

   sharpnessTable = &(colorCustomSharpnessTable[colorGetCustomSharpnessIndex(_color_handle.applyScenario)]);
   contrastTable = &(colorCustomContrastTable[colorGetCustomContrastIndex(_color_handle.applyScenario)]);
   saturationTable = &(colorCustomSaturationTable[colorGetCustomSaturationIndex(_color_handle.applyScenario)]);

   colorCurrSharpnessTableIndex = colorGetCustomSharpnessIndex(_color_handle.applyScenario);
   colorCurrContrastTableIndex = colorGetCustomContrastIndex(_color_handle.applyScenario);
   colorCurrSaturationTableIndex = colorGetCustomSaturationIndex(_color_handle.applyScenario);
   colorTargetSharpnessTableIndex = colorCurrSharpnessTableIndex;
   colorTargetContrastTableIndex = colorCurrContrastTableIndex;
   colorTargetSaturationTableIndex = colorCurrSaturationTableIndex;

   _colorUpdateParameter(sharpnessTable, contrastTable, saturationTable);
   _color_handle.updateConfig = KAL_FALSE;

#if defined(__MTK_TARGET__)
   if (NULL == pq_state_mutex)
   {
      pq_state_mutex = kal_create_mutex("PQ State");
      ASSERT(pq_state_mutex != NULL);
   }
   if (NULL == pq_setting_mutex)
   {
      pq_setting_mutex = kal_create_mutex("PQ Set");
      ASSERT(pq_setting_mutex != NULL);
   }
#endif

#if defined(__MTK_TARGET__)
      /* register bb reg dump */
      pq_dump.regions = (kal_uint32*)pq_dump_regions;
      pq_dump.num = sizeof(pq_dump_regions) / (sizeof(kal_uint32) * 3);
      pq_dump.bbreg_dump_callback = NULL;
      EX_REGISTER_BBREG_DUMP(&pq_dump);
#endif /* __MTK_TARGET__ */


   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}
void _colorCalculateStep()
{
#if defined(__DRV_COLOR_HW_SUPPORT__)

   if (!((0xFF == colorCustomSharpnessTableIndex) &&
       (0xFF == colorCustomContrastTableIndex) && 
       (0xFF == colorCustomSaturationTableIndex)))
   {
     //Engineering Mode
     return;
   }

   //SharpnessTableIndex
   if (colorCurrSharpnessTableIndex < colorTargetSharpnessTableIndex)
   {
      SharpnessStep = ((colorTargetSharpnessTableIndex - colorCurrSharpnessTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
   else if (colorCurrSharpnessTableIndex > colorTargetSharpnessTableIndex )
   {
      SharpnessStep = ((colorCurrSharpnessTableIndex - colorTargetSharpnessTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
   //ContrastTableIndex
   if (colorCurrContrastTableIndex  < colorTargetContrastTableIndex )
   {
      ContrastStep = ((colorTargetContrastTableIndex - colorCurrContrastTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
   else if (colorCurrContrastTableIndex  > colorTargetContrastTableIndex  )
   {
      ContrastStep = ((colorCurrContrastTableIndex - colorTargetContrastTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
   //SatuartionTableIndex
   if (colorCurrSaturationTableIndex  < colorTargetSaturationTableIndex )
   {
      SaturationStep = ((colorTargetSaturationTableIndex - colorCurrSaturationTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
   else if (colorCurrSaturationTableIndex  > colorTargetSaturationTableIndex)
   {
      SaturationStep = ((colorCurrSaturationTableIndex - colorTargetSaturationTableIndex)/COLOR_STEP_DIVSOR) + 1;
   }
#endif
}
void _colorAdjustFunction()
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_SHARPNESS_T *sharpnessTable;
   COLOR_CONTRAST_T *contrastTable;
   COLOR_SATURATION_T *saturationTable;

   if (!((0xFF == colorCustomSharpnessTableIndex) &&
       (0xFF == colorCustomContrastTableIndex) && 
       (0xFF == colorCustomSaturationTableIndex)))
   {
     return;
   }
   //SharpnessTableIndex
   if (colorCurrSharpnessTableIndex < colorTargetSharpnessTableIndex)
   {
      if ((colorCurrSharpnessTableIndex+SharpnessStep) <= colorTargetSharpnessTableIndex)
      {
         colorCurrSharpnessTableIndex+= SharpnessStep;
      }
      else
      {
         colorCurrSharpnessTableIndex = colorTargetSharpnessTableIndex;
      }
   }
   else if (colorCurrSharpnessTableIndex > colorTargetSharpnessTableIndex )
   {
      if (((colorCurrSharpnessTableIndex-SharpnessStep) >= colorTargetSharpnessTableIndex) && ((colorCurrSharpnessTableIndex-SharpnessStep) >= 0))
      {
         colorCurrSharpnessTableIndex-= SharpnessStep;
      }
      else
      {
         colorCurrSharpnessTableIndex = colorTargetSharpnessTableIndex;
      }
   }
   //ContrastTableIndex
   if (colorCurrContrastTableIndex  < colorTargetContrastTableIndex )
   {
      if ((colorCurrContrastTableIndex+ContrastStep) <= colorTargetContrastTableIndex)
      {
         colorCurrContrastTableIndex+= ContrastStep;
      }
      else
      {
         colorCurrContrastTableIndex = colorTargetContrastTableIndex;
      }
   }
   else if (colorCurrContrastTableIndex  > colorTargetContrastTableIndex  )
   {
      if (((colorCurrContrastTableIndex-ContrastStep) >= colorTargetContrastTableIndex) && ((colorCurrSharpnessTableIndex-SharpnessStep) >= 0))
      {
         colorCurrContrastTableIndex-= ContrastStep;
      }
      else
      {
         colorCurrContrastTableIndex = colorTargetContrastTableIndex;
      }

   }
   //SatuartionTableIndex
   if (colorCurrSaturationTableIndex  < colorTargetSaturationTableIndex )
   {
      if ((colorCurrSaturationTableIndex+SaturationStep) <= colorTargetSaturationTableIndex)
      {
         colorCurrSaturationTableIndex+= SaturationStep;
      }
      else
      {
         colorCurrSaturationTableIndex = colorTargetSaturationTableIndex;
      }
   }
   else if (colorCurrSaturationTableIndex  > colorTargetSaturationTableIndex)
   {
      if (((colorCurrSaturationTableIndex-SaturationStep) >= colorTargetSaturationTableIndex) && ((colorCurrSharpnessTableIndex-SharpnessStep) >= 0))
      {
         colorCurrSaturationTableIndex-= SaturationStep;
      }
      else
      {
         colorCurrSaturationTableIndex = colorTargetSaturationTableIndex;
      }
   }

   sharpnessTable = &(colorCustomSharpnessTable[colorCurrSharpnessTableIndex]);
   contrastTable = &(colorCustomContrastTable[colorCurrContrastTableIndex]);
   saturationTable = &(colorCustomSaturationTable[colorCurrSaturationTableIndex]);
   _colorUpdateParameter(sharpnessTable, contrastTable, saturationTable);
#endif
}

/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM PQInternalConfig(COLOR_PATH_ENUM path, kal_uint32 src_width)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)

   if (0 == colorCustomEnable)
   {
      // setup power
      color_drv_power_off();

      // setup path, bypass, and enable
      mm_color_for_lcd();
      SET_LCD_DITHER_PQ(0);
      SET_LCD_ROI_CTRL_COLOR_EN(0);

      color_drv_set_bypass(COLOR_BYPASS_ALL);
      color_drv_set_enable(KAL_FALSE);
   }
   else
   {
      // setup power
      SystemInitial = kal_query_systemInit();
      if (KAL_FALSE == SystemInitial)
      {
         if (KAL_FALSE== kal_if_hisr())
         {
            kal_take_mutex(pq_setting_mutex);
         }
         else
         {
            if (KAL_TRUE == _color_handle.updateConfig)
            {
               // wait for config update finished
               return COLOR_STATUS_OK;
            }
         }
      }

      color_drv_power_on();

      _colorAdjustFunction();
      
      // setup sharpness
      if (0 == (_color_handle.bypassConfig & COLOR_BYPASS_SHARP))
      {
         COLOR_SHARPNESS_T *sharpnessTable;
         sharpnessTable = &(_color_handle.effectSharpness);
         color_drv_set_sharpness(sharpnessTable->Gain, sharpnessTable->SoftRatio, sharpnessTable->Limit, sharpnessTable->Bound);
      }
      
      // setup contrast
      if (0 == (_color_handle.bypassConfig & COLOR_BYPASS_CONTRAST))
      {
         kal_uint16  Offset0, Offset1;
         COLOR_CONTRAST_T *contrastTable;
         contrastTable = &(_color_handle.effectContrast);
   
         Offset0 = (kal_uint16)contrastTable->Point0 * (kal_uint16)contrastTable->Gain0;
         Offset1 = Offset0 + ((kal_uint16)contrastTable->Point1 - (kal_uint16)contrastTable->Point0) * (kal_uint16)contrastTable->Gain1;
   
         color_drv_set_contrast_point(contrastTable->Point0, contrastTable->Point1);
         color_drv_set_contrast_gain(contrastTable->Gain0, contrastTable->Gain1, contrastTable->Gain2);
         color_drv_set_contrast_offset(Offset0, Offset1);
      }
   
      // setup saturation
      if (0 == (_color_handle.bypassConfig & COLOR_BYPASS_SAT))
      {
         kal_uint32  SquarePoint, CoefB;
         COLOR_SATURATION_T *saturationTable;
         saturationTable = &(_color_handle.effectSaturation);

         SquarePoint = ((kal_uint32)saturationTable->ConPoint * (kal_uint32)saturationTable->ConPoint + (1<<3)) >> 4;
         CoefB = (kal_uint32)saturationTable->Gain + (((kal_uint32)saturationTable->CoefA * SquarePoint + (1<<10)) >> 11);
   
         color_drv_set_saturation_point(SquarePoint, saturationTable->CoefA, CoefB);
         color_drv_set_saturation_gain(saturationTable->Gain);
      }
   
      // setup path
      if (COLOR_PATH_MDP == path)   
      {
         _color_handle.bypassConfig |= (COLOR_BYPASS_Y2R | COLOR_BYPASS_R2Y);

         // setup path
         mm_color_for_mdp();
         SET_LCD_DITHER_PQ(0);
         SET_LCD_ROI_CTRL_COLOR_EN(0);
         UseMDPPath = KAL_TRUE;
      }
      else
      {
         _color_handle.bypassConfig &= ~(COLOR_BYPASS_Y2R | COLOR_BYPASS_R2Y);
         mm_color_for_lcd();
         SET_LCD_DITHER_PQ(1);
         SET_LCD_ROI_CTRL_COLOR_EN(1);
         UseMDPPath = KAL_FALSE;
      }

      // setup source width
      color_drv_set_source_size(src_width);

      // setup bypass and enable
      color_drv_set_bypass(_color_handle.bypassConfig);
      color_drv_set_enable(KAL_TRUE);   
      if (KAL_FALSE == SystemInitial)
      {
         if (KAL_FALSE== kal_if_hisr())
         {
            kal_give_mutex(pq_setting_mutex);
         }
      }
   }
return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif


}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorUpdateConfig(COLOR_PATH_ENUM path, kal_uint32 src_width)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)

   if (KAL_TRUE == UseMDPPath)
   {
       return COLOR_STATUS_OK;
   }
   PQInternalConfig(path, src_width);
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorWrapperOpen(COLOR_HANDLE *handle, COLOR_SCENARIO_ENUM scenario)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   if (MAX_COLOR_SCENARIO <= scenario)
   {
      ASSERT(0);
   }
   if (NULL == handle)
   {
      ASSERT(0);
   }

   _colorGetHandle(handle, scenario);

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorPowerEnable(kal_bool enable)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   // wait for config update finished
   while (KAL_TRUE == _color_handle.updateConfig) ; 
   
   if (KAL_FALSE == enable)
   {
      color_drv_power_off();
   }
   else
   {
      color_drv_power_on();
   }

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorWrapperEnable(COLOR_HANDLE handle, kal_uint32 src_width)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_PATH_ENUM pathTable = colorCustomPathTable[handle->applyScenario];
   COLOR_SHARPNESS_T *sharpnessTable;
   COLOR_CONTRAST_T *contrastTable;
   COLOR_SATURATION_T *saturationTable;

   if (((0xFF != colorCustomSharpnessTableIndex) && (colorCustomSharpnessTableIndex <= COLOR_CUSTOM_SHARPNESS_TABLE_NUM)) ||
        ((0xFF != colorCustomContrastTableIndex) && (colorCustomContrastTableIndex <= COLOR_CUSTOM_CONTRAST_TABLE_NUM)) ||
        ((0xFF != colorCustomSaturationTableIndex) && (colorCustomSaturationTableIndex <= COLOR_CUSTOM_SATURATION_TABLE_NUM))
        )
   {
      if (COLOR_PATH_MDP == pathTable)
      {
         // wait for LCD idle
         while (LCD_IS_RUNNING) ;
         PQInternalConfig(COLOR_PATH_MDP, src_width);
      }

  }
   else
   {
      kal_take_mutex(pq_setting_mutex);
      handle->updateConfig = KAL_TRUE;
      colorTargetSharpnessTableIndex = colorGetCustomSharpnessIndex(handle->applyScenario);
      colorTargetContrastTableIndex = colorGetCustomContrastIndex(handle->applyScenario);
      colorTargetSaturationTableIndex = colorGetCustomSaturationIndex(handle->applyScenario);
      COLOR_STEP_DIVSOR = 2;
      _colorCalculateStep();
      if (COLOR_PATH_MDP == pathTable)
      {
         sharpnessTable = &(colorCustomSharpnessTable[colorGetCustomSharpnessIndex(handle->applyScenario)]);
         contrastTable = &(colorCustomContrastTable[colorGetCustomContrastIndex(handle->applyScenario)]);
         saturationTable = &(colorCustomSaturationTable[colorGetCustomSaturationIndex(handle->applyScenario)]);
         colorCurrSharpnessTableIndex = colorTargetSharpnessTableIndex;
         colorCurrContrastTableIndex = colorTargetContrastTableIndex;
         colorCurrSaturationTableIndex = colorTargetSaturationTableIndex;
         _colorUpdateParameter(sharpnessTable, contrastTable, saturationTable);
      }      
      handle->updateConfig = KAL_FALSE;
      kal_give_mutex(pq_setting_mutex);

      if (COLOR_PATH_MDP == pathTable)
      {
         // wait for LCD idle
         while (LCD_IS_RUNNING) ;
         PQInternalConfig(COLOR_PATH_MDP, src_width);
      }

   }

   
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorWrapperDisable(COLOR_HANDLE handle)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_SHARPNESS_T *sharpnessTable;
   COLOR_CONTRAST_T *contrastTable;
   COLOR_SATURATION_T *saturationTable;

  kal_take_mutex(pq_setting_mutex);
  handle->updateConfig = KAL_TRUE;
  UseMDPPath = KAL_FALSE;
  
  if ((0xFF == colorCustomSharpnessTableIndex) &&
      (0xFF == colorCustomContrastTableIndex) && 
      (0xFF == colorCustomSaturationTableIndex))
   {
      sharpnessTable = &(colorCustomSharpnessTable[colorGetCustomSharpnessIndex(COLOR_SCENARIO_DEFAULT)]);
      contrastTable = &(colorCustomContrastTable[colorGetCustomContrastIndex(COLOR_SCENARIO_DEFAULT)]);
      saturationTable = &(colorCustomSaturationTable[colorGetCustomSaturationIndex(COLOR_SCENARIO_DEFAULT)]);

      colorTargetSharpnessTableIndex = colorGetCustomSharpnessIndex(COLOR_SCENARIO_DEFAULT);
      colorTargetContrastTableIndex = colorGetCustomContrastIndex(COLOR_SCENARIO_DEFAULT);
      colorTargetSaturationTableIndex = colorGetCustomSaturationIndex(COLOR_SCENARIO_DEFAULT);
      if ((COLOR_SCENARIO_IMAGE_PLAYBACK == handle->applyScenario) || (COLOR_SCENARIO_VIDEO_ENCODE == handle->applyScenario))
      {
         COLOR_STEP_DIVSOR = 3;
      }
      else if (COLOR_SCENARIO_CAMERA_PREVIEW == handle->applyScenario)
      {
         colorCurrSharpnessTableIndex = colorTargetSharpnessTableIndex;
         colorCurrContrastTableIndex = colorTargetContrastTableIndex;
         colorCurrSaturationTableIndex = colorTargetSaturationTableIndex;
      }
      else
      {
         COLOR_STEP_DIVSOR = 2;
      }
      _colorCalculateStep();

   }
   handle->updateConfig = KAL_FALSE;
   kal_give_mutex(pq_setting_mutex);
   
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorWrapperClose(COLOR_HANDLE handle)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   if ((NULL == handle) || (handle != &_color_handle))
   {
      ASSERT(0);
   }

   colorWrapperDisable(handle);
   _colorReleaseHandle(handle);

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
kal_uint32 colorGetCustomSharpnessIndex(COLOR_SCENARIO_ENUM scenario)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_CUSTOM_TABLE_T *customTable;

   if (MAX_COLOR_SCENARIO <= scenario)
   {
      ASSERT(0);
   }

   customTable = &(colorCustomTableIndex[scenario]);
   
   return customTable->Sharpness;

#else
   return 0;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
kal_uint32 colorGetCustomContrastIndex(COLOR_SCENARIO_ENUM scenario)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_CUSTOM_TABLE_T *customTable;

   if (MAX_COLOR_SCENARIO <= scenario)
   {
      ASSERT(0);
   }

   customTable = &(colorCustomTableIndex[scenario]);
   
   return customTable->Contrast;

#else
   return 0;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
kal_uint32 colorGetCustomSaturationIndex(COLOR_SCENARIO_ENUM scenario)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_CUSTOM_TABLE_T *customTable;

   if (MAX_COLOR_SCENARIO <= scenario)
   {
      ASSERT(0);
   }

   customTable = &(colorCustomTableIndex[scenario]);
   
   return customTable->Saturation;

#else
   return 0;

#endif
}

/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorSetCustomSharpnessTableIndex(kal_uint32 index)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_SHARPNESS_T *sharpnessTable;
   COLOR_HANDLE handle = (COLOR_HANDLE)&_color_handle;

   if (COLOR_CUSTOM_SHARPNESS_TABLE_NUM < index)
   {
      ASSERT(0);
   }

#if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
/* under construction !*/
#endif
   kal_take_mutex(pq_setting_mutex);

   colorCustomSharpnessTableIndex = index;
   sharpnessTable = &(colorCustomSharpnessTable[index]);
   _colorSetSharpness(handle, sharpnessTable);

   kal_give_mutex(pq_setting_mutex);
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorSetCustomContrastTableIndex(kal_uint32 index)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_CONTRAST_T *contrastTable;
   COLOR_HANDLE handle = (COLOR_HANDLE)&_color_handle;

   if (COLOR_CUSTOM_CONTRAST_TABLE_NUM < index)
   {
      ASSERT(0);
   }

   kal_take_mutex(pq_setting_mutex);

   colorCustomContrastTableIndex = index;
   contrastTable = &(colorCustomContrastTable[index]);
   _colorSetContrast(handle, contrastTable);

   kal_give_mutex(pq_setting_mutex);

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorSetCustomSaturationTableIndex(kal_uint32 index)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   COLOR_SATURATION_T *saturationTable;
   COLOR_HANDLE handle = (COLOR_HANDLE)&_color_handle;

   if (COLOR_CUSTOM_SATURATION_TABLE_NUM < index)
   {
      ASSERT(0);
   }

   kal_take_mutex(pq_setting_mutex);
   
   colorCustomSaturationTableIndex = index;
   saturationTable = &(colorCustomSaturationTable[index]);
   _colorSetSaturation(handle, saturationTable);

   kal_give_mutex(pq_setting_mutex);
   
   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorSetCustomEnable(kal_bool enable)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   _color_handle.updateConfig = KAL_TRUE;
   colorCustomEnable = (kal_uint8)enable;
   _color_handle.updateConfig = KAL_FALSE;

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


/** DESCRIPTION :
 *     Set information of the destination image. \n
 *  @param[in] handle The returned value of swippGetHandle
 *  @param[in] dst_addr Address to store the processed image.
 *  @param[in] color_format color format of the destination image.
 *  @return Return IPP_STATUS_OK if success. \n
 *          Return IPP_STATUS_ERROR_INVALID_DST_SIZE if the destination buffer size is wrong.
 *          Return IPP_STATUS_ERROR_AT_PAUSE_CHANGE_DST_INFO when changing information under pause atate.
 */
COLOR_STATUS_ENUM colorGetCustomEnable(kal_bool* enable)
{
#if defined(__DRV_COLOR_HW_SUPPORT__)
   if (NULL == enable)
   {
      ASSERT(0);
   }

   if (0xFF == colorCustomEnable)
   {
      // default turn on
      *enable = KAL_TRUE;
   }
   else
   {
      *enable = (kal_bool)colorCustomEnable;
   }

   return COLOR_STATUS_OK;

#else
   return COLOR_STATUS_UNAVAILABLE;

#endif
}


