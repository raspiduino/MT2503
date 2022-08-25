/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   lcd_interface_manager.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD interface manager for external device usage
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
 * 04 23 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 04 14 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 03 31 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 10 14 2013 chrono.wu
 * removed!
 * .
 *
 * 01 29 2013 ricky.lin
 * removed!
 * .
 *
 * 01 21 2013 ricky.lin
 * removed!
 * .
 *
 * 11 26 2012 joey.pan
 * removed!
 * Remove LCD build warnings.
 *
 * 11 13 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 * 07 24 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 05 22 2012 dong.guo
 * removed!
 * .
 *
 * 04 17 2012 xiaoyong.ye
 * removed!
 * include custom_EMI_release.h.
 *
 * 04 12 2012 xiaoyong.ye
 * removed!
 * Enhance EMI 130MHz clock judgy by MT6250 option.
 *
 * 04 11 2012 xiaoyong.ye
 * removed!
 * Improve lcd_if_manager query lcd  clock for differenct EMI clock 130/104Mhz.
 *
 * 03 29 2012 xiaoyong.ye
 * removed!
 * 
 * Fix some problem.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 12 01 2011 haitao.shang
 * removed!
 * .
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 10 25 2011 haitao.shang
 * removed!
 * .
 *
 * 10 20 2011 sixian.wang
 * removed!
 * .
 *
 * 10 13 2011 bin.han
 * removed!
 * .
 *
 * 09 13 2011 dong.guo
 * removed!
 * IF changes check in
 *
 * 09 13 2011 dong.guo
 * removed!
 * IF changes check in
 *
 * 08 25 2011 bin.han
 * removed!
 * .
 *
 * 08 23 2011 bin.han
 * removed!
 * .
 *
 * 08 18 2011 bin.han
 * removed!
 * .
 *
 * 08 17 2011 matthew.chen
 * removed!
 * Remove MT6256_S00 for display driver
 *
 * 08 11 2011 bin.han
 * removed!
 * .
 *
 * 07 27 2011 bin.han
 * removed!
 * .
 *
 * 07 26 2011 bin.han
 * removed!
 * .
 *
 * 07 15 2011 bin.han
 * removed!
 * .
 *
 * 07 04 2011 bin.han
 * removed!
 * .
 *
 * 06 29 2011 zifeng.qiu
 * removed!
 * .
 *
 * 06 27 2011 bin.han
 * removed!
 * Fix build warning
 *
 * 05 27 2011 bin.han
 * removed!
 * .
 *
 * 05 18 2011 tianshu.qiu
 * removed!
 * .
 *
 * 05 11 2011 zifeng.qiu
 * removed!
 * 6235 IF Manager Slim Check in.
 *
 * 05 04 2011 zifeng.qiu
 * removed!
 * Code size shrink.
 *
 * 04 22 2011 zifeng.qiu
 * removed!
 * IF Manager Code Size Shrink.
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 17 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 17 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 13 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 sophie.chen
 * removed!
 * .
 *
 * 02 11 2011 sophie.chen
 * removed!
 * .
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 13 2011 sophie.chen
 * removed!
 * .
 *
 * 12 31 2010 chelun.tsai
 * removed!
 * remove lcd_trace.
 *
 * 12 30 2010 chelun.tsai
 * removed!
 * modify lcd_if_manager.
 *
 * 12 30 2010 tristan.su
 * removed!
 * remove MT6253D option.
 *
 * 12 24 2010 tristan.su
 * removed!
 * 6235 if manager revise.
 *
 * 12 24 2010 sophie.chen
 * removed!
 * .
 *
 * 12 24 2010 tristan.su
 * removed!
 * fix 6252 cs driving current for wifi.
 *
 * 12 23 2010 tristan.su
 * removed!
 * rename serial if macro.
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 12 22 2010 marvin.tsai
 * removed!
 * .
 *
 * 12 14 2010 tristan.su
 * removed!
 * .
 *
 * 12 14 2010 tristan.su
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "lcd_if_hw.h"
#include "lcd_if.h"
#include "lcd_if_manager.h"
#include "custom_EMI_release.h"
#include "nld_central_ctrl.h"

#if (defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H))
  #define LCD_IOCTRL_MT6252_SERIES
#elif (defined(MT6253))
  #define LCD_IOCTRL_MT6253_SERIES
#elif defined(MT6236)
// || defined(MT6256) || defined(MT6276))
  #define LCD_IOCTRL_MT6236_SERIES
#elif defined(MT6276)
  #define LCD_IOCTRL_MT6276_SERIES
#elif defined(MT6256)
  #define LCD_IOCTRL_MT6256_SERIES  
#elif defined(MT6255)
  #define LCD_IOCTRL_MT6255_SERIES
#elif defined(MT6250)
  #define LCD_IOCTRL_MT6250_SERIES  
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
  #define LCD_IOCTRL_MT6260_SERIES  
#elif defined(MT6268)
  #define LCD_IOCTRL_MT6268_SERIES
#elif (defined(MT6235) || defined(MT6235B))
  #define LCD_IOCTRL_MT6235_SERIES
#else
  #define LCD_IOCTRL_LEGACY_SERIES
#endif


typedef enum 
{
   // query
   LCD_IOCTRL_INTERN_QUERY,

   //config
   LCD_IOCTRL_INTERN_CONFIG,

   LCD_IOCTRL_INTERN_ACT_MAX_ENUM
}LCD_IOCTRL_IF_INTERNAL_ACT_E;


typedef struct
{
    kal_bool internal_init;
    kal_bool is_dev_mounted[LCD_IF_USER_MAX_ENUM];
    kal_uint32 total_mounted_dev_number;
}
LCD_IOCTRL_CNTL_BLOCK_T;

// Local static function declaration
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu);
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu);

// Local static variable declaration
static volatile LCD_IOCTRL_CNTL_BLOCK_T lcd_ioctrl_block;


kal_uint32 lcd_get_ioctrl_device_if_handle(LCD_IF_USER_ENUM user)
{
    if(user ==  LCD_IF_USER_UNKNOWN || user > LCD_IF_USER_EXT4)
    {
        ASSERT(0);
        return 0;
    }

    if(lcd_ioctrl_block.internal_init == KAL_FALSE)
    {
        int i;
        lcd_ioctrl_block.internal_init = KAL_TRUE;
        lcd_ioctrl_block.total_mounted_dev_number = 0;
        for(i=0; i<LCD_IF_USER_MAX_ENUM; i++)
        {
            lcd_ioctrl_block.is_dev_mounted[i] = KAL_FALSE;
        }
    }

    //ToDo: could consider to return control block address for debugging purpose
    return (kal_uint32) user;
}


LCD_IOCTRL_RESULT_E lcd_ioctrl_device_if_settings(kal_uint32 handle, LCD_IOCTRL_IF_ACTION_E action, void *p_argu, kal_uint32 argu_size)
{
    LCD_IF_USER_ENUM user;
    LCD_IOCTRL_IF_INTERNAL_ACT_E act;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    // if use control block address as handle, must check address
    user = (LCD_IF_USER_ENUM)handle;
    if(user ==  LCD_IF_USER_UNKNOWN || user > LCD_IF_USER_EXT4)
    {
        rtn_code = LCD_IOCTRL_ERR_INVALID_HANDLE;
        goto Exit;
    }

    if(p_argu == NULL)
    {
        rtn_code = LCD_IOCTRL_ERR_NULL_ARGU_PTR;
        goto Exit;
    }


    if(action == LCD_IOCTRL_QUERY_MAIN_LCD_IF || action == LCD_IOCTRL_QUERY_SUB_LCD_IF || action == LCD_IOCTRL_QUERY_DEVICE_IF || action == LCD_IOCTRL_QUERY_TOTAL_MOUNTED_DEVICE_NUMBER)
    {
        act = LCD_IOCTRL_INTERN_QUERY;
    }
    else
    {
        act = LCD_IOCTRL_INTERN_CONFIG;
        if(lcd_ioctrl_block.is_dev_mounted[user] == KAL_FALSE)
        {
            lcd_ioctrl_block.is_dev_mounted[user] = KAL_TRUE;
            lcd_ioctrl_block.total_mounted_dev_number++;
        }
    }


    switch(action)
    {
        case LCD_IOCTRL_QUERY_MAIN_LCD_IF:
        case LCD_IOCTRL_QUERY_SUB_LCD_IF:
        case LCD_IOCTRL_CONFIG_MAIN_LCD_IF:
        case LCD_IOCTRL_CONFIG_SUB_LCD_IF:
        {
            LCD_IOCTRL_LCD_SETTING_T *p_lcd_argu = (LCD_IOCTRL_LCD_SETTING_T *) p_argu;

            if(argu_size < sizeof(LCD_IOCTRL_LCD_SETTING_T))
            {
                rtn_code = LCD_IOCTRL_ERR_NOT_ENOUGH_ARGU_SIZE;
                goto Exit;
            }

            if(action == LCD_IOCTRL_QUERY_MAIN_LCD_IF)
            {
               #if defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__)
               p_lcd_argu->l_ui_on_p_lcm = KAL_TRUE;
               #else
               p_lcd_argu->l_ui_on_p_lcm = KAL_FALSE;
               #endif
               #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
                   p_lcd_argu->lcm_width = LCD_HEIGHT;
                   p_lcd_argu->lcm_height = LCD_WIDTH;
               #else
               p_lcd_argu->lcm_width = LCD_WIDTH;
               p_lcd_argu->lcm_height = LCD_HEIGHT;
               #endif 
               #if ((MAIN_LCD_DATA_ADDR == LCD_PARALLEL0_A0_HIGH_ADDR) || (MAIN_LCD_DATA_ADDR == LCD_PARALLEL0_A0_LOW_ADDR))
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
               p_lcd_argu->lcd_if_setting.if_cs_no = 0;
               #elif ((MAIN_LCD_DATA_ADDR == LCD_PARALLEL1_A0_HIGH_ADDR) || (MAIN_LCD_DATA_ADDR == LCD_PARALLEL1_A0_LOW_ADDR))
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
               p_lcd_argu->lcd_if_setting.if_cs_no = 1;
               #elif ((MAIN_LCD_DATA_ADDR == LCD_PARALLEL2_A0_HIGH_ADDR) || (MAIN_LCD_DATA_ADDR == LCD_PARALLEL2_A0_LOW_ADDR))
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
               p_lcd_argu->lcd_if_setting.if_cs_no = 2;
               #elif ((MAIN_LCD_DATA_ADDR == LCD_SERIAL0_A0_HIGH_ADDR) || (MAIN_LCD_DATA_ADDR == LCD_SERIAL0_A0_LOW_ADDR))
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_SERIAL;
               p_lcd_argu->lcd_if_setting.if_cs_no = 0;
               #elif ((MAIN_LCD_DATA_ADDR == LCD_SERIAL1_A0_HIGH_ADDR) || (MAIN_LCD_DATA_ADDR == LCD_SERIAL1_A0_LOW_ADDR))
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_SERIAL;
               p_lcd_argu->lcd_if_setting.if_cs_no = 1;
               #else
               //ASSERT(0);
               //ToDo: handle page mode LCD share EMI pins for MT6252H
               p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_UNKNOWN;
               #endif

            }
            else if(action == LCD_IOCTRL_QUERY_SUB_LCD_IF)
            {
                #if !defined(DUAL_LCD)
                    rtn_code = LCD_IOCTRL_ERR_DEVICE_IF_NOT_SUPPORTED;
                    goto Exit;
                #else
                   #if 0//defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__)// sub lcd not support L UI on P LCM
/* under construction !*/
                   #else
                   p_lcd_argu->l_ui_on_p_lcm = KAL_FALSE;
                   #endif
               #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
                   p_lcd_argu->lcm_width = SUBLCD_HEIGHT;
                   p_lcd_argu->lcm_height = SUBLCD_WIDTH;
               #else
                   p_lcd_argu->lcm_width = SUBLCD_WIDTH;
                   p_lcd_argu->lcm_height = SUBLCD_HEIGHT;
               #endif 

                   #if ((SUB_LCD_DATA_ADDR == LCD_PARALLEL0_A0_HIGH_ADDR) || (SUB_LCD_DATA_ADDR == LCD_PARALLEL0_A0_LOW_ADDR))
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
                   p_lcd_argu->lcd_if_setting.if_cs_no = 0;
                   #elif ((SUB_LCD_DATA_ADDR == LCD_PARALLEL1_A0_HIGH_ADDR) || (SUB_LCD_DATA_ADDR == LCD_PARALLEL1_A0_LOW_ADDR))
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
                   p_lcd_argu->lcd_if_setting.if_cs_no = 1;
                   #elif ((SUB_LCD_DATA_ADDR == LCD_PARALLEL2_A0_HIGH_ADDR) || (SUB_LCD_DATA_ADDR == LCD_PARALLEL2_A0_LOW_ADDR))
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
                   p_lcd_argu->lcd_if_setting.if_cs_no = 2;
                   #elif ((SUB_LCD_DATA_ADDR == LCD_SERIAL0_A0_HIGH_ADDR) || (SUB_LCD_DATA_ADDR == LCD_SERIAL0_A0_LOW_ADDR))
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_SERIAL;
                   p_lcd_argu->lcd_if_setting.if_cs_no = 0;
                   #elif ((SUB_LCD_DATA_ADDR == LCD_SERIAL1_A0_HIGH_ADDR) || (SUB_LCD_DATA_ADDR == LCD_SERIAL1_A0_LOW_ADDR))
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_DBI_SERIAL;
                   p_lcd_argu->lcd_if_setting.if_cs_no = 1;
                   #else
                   //ASSERT(0);
                   //ToDo: handle page mode LCD share EMI pins for MT6252H
                   p_lcd_argu->lcd_if_setting.if_type = LCD_IF_TYPE_UNKNOWN;
                   #endif

                #endif
            }


            if(p_lcd_argu->lcd_if_setting.if_type == LCD_IF_TYPE_DBI_PARALLEL)
            {
                p_lcd_argu->lcd_if_setting.if_settings.dbi_parallel_if.if_cs_no = p_lcd_argu->lcd_if_setting.if_cs_no;
                rtn_code = _lcd_ioctrl_device_dbi_parallel_if(act, &(p_lcd_argu->lcd_if_setting.if_settings.dbi_parallel_if));
            }
            else if(p_lcd_argu->lcd_if_setting.if_type == LCD_IF_TYPE_DBI_SERIAL)
            {
                p_lcd_argu->lcd_if_setting.if_settings.dbi_serial_if.if_cs_no = p_lcd_argu->lcd_if_setting.if_cs_no;
                rtn_code = _lcd_ioctrl_device_dbi_serial_if(act, &(p_lcd_argu->lcd_if_setting.if_settings.dbi_serial_if));
            }
            else if(p_lcd_argu->lcd_if_setting.if_type == LCD_IF_TYPE_UNKNOWN)
            {
                rtn_code = LCD_IOCTRL_ERR_DEVICE_IF_NOT_SUPPORTED;
            }
            else
            {
                //ToDo:  not support yet
                //ASSERT(0);
            }

        }
        break;

        case LCD_IOCTRL_QUERY_DEVICE_IF:
        case LCD_IOCTRL_CONFIG_DEVICE_IF:
        {
            LCD_IOCTRL_DEVICE_IF_T *p_dev_if_argu = (LCD_IOCTRL_DEVICE_IF_T *) p_argu;

            if(argu_size < sizeof(LCD_IOCTRL_DEVICE_IF_T))
            {
                rtn_code = LCD_IOCTRL_ERR_NOT_ENOUGH_ARGU_SIZE;
                goto Exit;
            }

            if(p_dev_if_argu->if_type == LCD_IF_TYPE_DBI_PARALLEL)
            {
                p_dev_if_argu->if_settings.dbi_parallel_if.if_cs_no = p_dev_if_argu->if_cs_no;
                rtn_code = _lcd_ioctrl_device_dbi_parallel_if(act, &(p_dev_if_argu->if_settings.dbi_parallel_if));
            }
            else if(p_dev_if_argu->if_type == LCD_IF_TYPE_DBI_SERIAL)
            {
                p_dev_if_argu->if_settings.dbi_serial_if.if_cs_no = p_dev_if_argu->if_cs_no;
                rtn_code = _lcd_ioctrl_device_dbi_serial_if(act, &(p_dev_if_argu->if_settings.dbi_serial_if));
            }
            else
            {
                //ToDo:  not support yet
                //ASSERT(0);
                rtn_code = LCD_IOCTRL_ERR_DEVICE_IF_NOT_SUPPORTED;
                goto Exit;
            }

        }
        break;

        case LCD_IOCTRL_QUERY_TOTAL_MOUNTED_DEVICE_NUMBER:
        {
            if(argu_size < 4)
            {
                rtn_code = LCD_IOCTRL_ERR_NOT_ENOUGH_ARGU_SIZE;
                goto Exit;
            }

            *((kal_uint32*)p_argu) = lcd_ioctrl_block.total_mounted_dev_number;
        }
        break;

        default:
            rtn_code = LCD_IOCTRL_ERR_INVALID_ACTION;
        goto Exit;

    }

Exit:
    return rtn_code;

}


#if defined(LCD_IOCTRL_MT6252_SERIES)

#if defined(__NLD_CENTRAL_CTRL__)
  
  void set_lcd_driving_current(kal_uint8 current)
  {
  }
  
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif   
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
   kal_uint32 save_irq_mask;
   kal_uint16 current_value=0;
   #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
   EMIShareIOSetting EMI_IOsetting;
   memset(&EMI_IOsetting, 0 , sizeof(EMI_IOsetting));
   #endif

   switch (current) {
   case LCD_DRIVING_2MA:
      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_2MA;
      #endif
      break;
   case LCD_DRIVING_4MA:
      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_4MA;
      #endif
      break;
   case LCD_DRIVING_6MA:
      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_6MA;
      #endif
      break;
   case LCD_DRIVING_8MA:
      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_8MA;
      #endif
      break;
   case LCD_DRIVING_10MA:
      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_10MA;
      #endif
      break;
   case LCD_DRIVING_12MA:
      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_12MA;
      #endif
      break;
   case LCD_DRIVING_14MA:
      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
      EMI_IOsetting.EMI_Drv = EMI_DRV_14MA;
      #endif
      break;
   default:
      return;
      break;
   }

   #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
   if(custom_ShareIOControl(&EMI_IOsetting) == KAL_FALSE)
   {
    ASSERT(0);
   }
   #endif

   save_irq_mask=SaveAndSetIRQMask();

//ToDo: need to consider dual LCM case in the future

//To Check: needs to consider special case's CS pin driver current after SB
#if defined(__EMI_DEVICE_MODE_PAGE__)

  #if defined( __SERIAL_LCM__ )
    CONFIG_LCD_DRIVING_CURRNET_FOR_PAGE_MODE_SERIAL(current_value);
  #endif

#else //#elif defined(__EMI_DEVICE_MODE_BURST__)

  #if !defined( __SERIAL_LCM__ )

   #if (defined(MT6252_S00) || defined(MT6252H_S00))
   // To Check: On E3, it still need to adjust chip-select pin driving current via ACIF_CON2, for 16bits, ACIF_CONF0, ACIF_CON1, EMI_IOC etc. check mail & final ver. of functional spec
    #if !defined(MAIN_LCD_16BIT_MODE)
        // most common used, 53EVB, Lion53 phone use this case
        CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_PARALLEL_8BITS(current_value);
    #else //MAIN_LCD_16BIT_MODE
        CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_PARALLEL_16BITS(current_value);
    #endif

   #else // CHIP_VER != S00

    // No need to configure EMI_IOC register after E3, EMI_IOC is configured inside above custom_ShareIOControl() function calls
    CONFIG_LCD_CHIP_SELECT_DRIVING_CURRNET_FOR_BURST_MODE(current_value);

   #endif

  #else // __SERIAL_LCM__

    CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_SERIAL(current_value);

  #endif

#endif

   RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	   #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	   EMIShareIOSetting EMI_IOsetting;
	   memset(&EMI_IOsetting, 0 , sizeof(EMI_IOsetting));
	   #endif
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_2MA;
	      #endif
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_4MA;
	      #endif
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_6MA;
	      #endif
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_8MA;
	      #endif
	      break;
	   case LCD_DRIVING_10MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_10MA;
	      #endif
	      break;
	   case LCD_DRIVING_12MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_12MA;
	      #endif
	      break;
	   case LCD_DRIVING_14MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
	      #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	      EMI_IOsetting.EMI_Drv = EMI_DRV_14MA;
	      #endif
	      break;
	   default:
	      return;
	      break;
	   }
	
	   #if (!defined(MT6252_S00) && !defined(MT6252H_S00) && !defined(__FUE__) && !defined(__UBL__))
	   if(custom_ShareIOControl(&EMI_IOsetting) == KAL_FALSE)
	   {
	    ASSERT(0);
	   }
	   #endif
	
	   save_irq_mask=SaveAndSetIRQMask();
	
	//ToDo: need to consider dual LCM case in the future
	
	//To Check: needs to consider special case's CS pin driver current after SB
	#if defined(__EMI_DEVICE_MODE_PAGE__)
	
	  #if defined( __SERIAL_LCM__ )
	    CONFIG_LCD_DRIVING_CURRNET_FOR_PAGE_MODE_SERIAL(current_value);
	  #endif
	
	#else //#elif defined(__EMI_DEVICE_MODE_BURST__)
	
	  #if !defined( __SERIAL_LCM__ )
	
	   #if (defined(MT6252_S00) || defined(MT6252H_S00))
	   // To Check: On E3, it still need to adjust chip-select pin driving current via ACIF_CON2, for 16bits, ACIF_CONF0, ACIF_CON1, EMI_IOC etc. check mail & final ver. of functional spec
	    #if !defined(MAIN_LCD_16BIT_MODE)
	        // most common used, 53EVB, Lion53 phone use this case
	        CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_PARALLEL_8BITS(current_value);
	    #else //MAIN_LCD_16BIT_MODE
	        CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_PARALLEL_16BITS(current_value);
	    #endif
	
	   #else // CHIP_VER != S00
	
	    // No need to configure EMI_IOC register after E3, EMI_IOC is configured inside above custom_ShareIOControl() function calls
	    CONFIG_LCD_CHIP_SELECT_DRIVING_CURRNET_FOR_BURST_MODE(current_value);
	
	   #endif
	
	  #else // __SERIAL_LCM__
	
	    CONFIG_LCD_DRIVING_CURRNET_FOR_BURST_MODE_SERIAL(current_value);
	
	  #endif
	
	#endif
	
	   RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif

#define MT6252_LCD_PARALLEL_IF_ADDR(cs_num) (LCD_PARALLEL_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (cs_num))
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6252_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) MT6252_LCD_PARALLEL_IF_ADDR(p_argu->if_cs_no);
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 bus_width;

        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT;
        p_argu->if_c2rh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_SHIFT_BIT;

        p_argu->if_set_common_period = KAL_FALSE;
        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_c2wh > p_argu->if_period)? (p_argu->if_wst + p_argu->if_c2wh + 3): (p_argu->if_wst + p_argu->if_period + 3);
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + (p_argu->if_period) + (p_argu->if_c2rh) + 3;

        //bus_width:
        bus_width = (p_argu->if_cs_no == 0)? (REG_LCD_PARALLEL_DATA_WIDTH & LCD_PARALLEL_DATA_WIDTH_P0_MASK): ((REG_LCD_PARALLEL_DATA_WIDTH & LCD_PARALLEL_DATA_WIDTH_P1_MASK)>>4);
        p_argu->if_bus_width = (bus_width < 2)? (8 + bus_width): (16);

        //clk_freq
        p_argu->if_clk_freq = 52*1000*1000;//52MHz

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF; //not support
        p_argu->if_gamma_g_lut_id = 0xFF; //not support
        p_argu->if_gamma_b_lut_id = 0xFF; //not support
        p_argu->p_if_gamma_lut_addr = NULL; //not support
        p_argu->if_gamma_lut_size = 0;//not support
        p_argu->if_gamma_lut_entity_bit_num = 0;//not support
        p_argu->if_gamma_lut_entity_bit_shift = 0;//not support

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
                REG_LCD_PARALLEL_DATA_WIDTH = p_argu->__if_reg_2;
        }
        else
        {
            kal_uint32 width_mask, width;

            conf_reg_value = 0;
    
            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK); 
   
            //bus_width
            width = (p_argu->if_bus_width < 16)? (p_argu->if_bus_width - 8): (2);
            width_mask = (p_argu->if_cs_no == 0)? (LCD_PARALLEL_DATA_WIDTH_P0_MASK): (LCD_PARALLEL_DATA_WIDTH_P1_MASK);
            width = (p_argu->if_cs_no == 0)? (width): (width<<4);
            REG_LCD_PARALLEL_DATA_WIDTH &= ~width_mask;
            REG_LCD_PARALLEL_DATA_WIDTH |= width;
    
            //p_argu->if_clk_freq // not support
            //p_argu->if_gamma_r_lut_id //not support
            //p_argu->if_gamma_g_lut_id //not support
            //p_argu->if_gamma_b_lut_id //not support

            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;
            p_argu->__if_reg_2 = REG_LCD_PARALLEL_DATA_WIDTH;

    	}

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}




static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6252_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_SERIAL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) LCD_SERIAL_CONFIG_REG; // not separate cs0 or cs1
    p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 if_size;

        conf_reg_value = *conf_reg_addr;

        // not support
        p_argu->if_clk_polarity = KAL_FALSE;
        p_argu->if_clk_phase = KAL_FALSE;
        p_argu->if_cs_polarity = KAL_FALSE;
        p_argu->if_non_dbi_mode = KAL_FALSE;

        p_argu->if_3wire_mode = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_3_WIRE_BIT) >> LCD_SERIAL_CONFIG_3_WIRE_BIT_SHIFT);
        p_argu->if_sdi = (kal_bool)((conf_reg_value & LCD_SERIAL_CONFIG_SDI_BIT) >> LCD_SERIAL_CONFIG_SDI_BIT_SHIFT);

        //trans_length
        if_size = ((conf_reg_value & LCD_SERIAL_CONFIG_IF_SIZE_MASK)>>12);
        if (if_size & 0x1)
        {
            p_argu->if_each_trans_length = (if_size == 1)? (9): (18 + (if_size - 3)*7);
        }
        else
        {
            p_argu->if_each_trans_length = (if_size == 0)? (8): (16 + (if_size - 2)*4);
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_TRUE;
        p_argu->scl_wt_low_count = (REG_LCD_SERIAL_WRITE_TIMING & LCD_SERIAL_WRITE_SCL_LOW_CYCLE_BIT) >> LCD_SERIAL_WRITE_SCL_LOW_CYCLE_BIT_SHIFT;
        p_argu->scl_wt_high_count = (REG_LCD_SERIAL_WRITE_TIMING & LCD_SERIAL_WRITE_SCL_HIGH_CYCLE_BIT) >> LCD_SERIAL_WRITE_SCL_HIGH_CYCLE_BIT_SHIFT;
        p_argu->scl_rd_low_count = (REG_LCD_SERIAL_READ_TIMING & LCD_SERIAL_READ_SCL_LOW_CYCLE_BIT) >> LCD_SERIAL_READ_SCL_LOW_CYCLE_BIT_SHIFT;
        p_argu->scl_rd_high_count = (REG_LCD_SERIAL_READ_TIMING & LCD_SERIAL_READ_SCL_HIGH_CYCLE_BIT) >> LCD_SERIAL_READ_SCL_HIGH_CYCLE_BIT_SHIFT;

        p_argu->if_clk_freq = 52*1000*1000;//at least 52MHz not 104M because high/low one T of 104M means clock is 52M
        p_argu->if_clk_divider = 0;

        p_argu->if_gamma_r_lut_id = 0xFF; //not support
        p_argu->if_gamma_g_lut_id = 0xFF; //not support
        p_argu->if_gamma_b_lut_id = 0xFF; //not support
        p_argu->p_if_gamma_lut_addr = NULL; //not support
        p_argu->if_gamma_lut_size = 0;//not support
        p_argu->if_gamma_lut_entity_bit_num = 0;//not support
        p_argu->if_gamma_lut_entity_bit_shift = 0;//not support

        p_argu->if_is_sw_cs_ctrl = KAL_TRUE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = LCD_SERIAL_CHIP_SEL_REG;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        p_argu->if_sw_cs_ctrl_reg_bit = (p_argu->if_cs_no == 0)? (LCD_SERIAL_CHIP_SEL_CS0_BIT): (LCD_SERIAL_CHIP_SEL_CS1_BIT);

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
            REG_LCD_SERIAL_WRITE_TIMING = p_argu->__if_reg_2;
            REG_LCD_SERIAL_READ_TIMING = p_argu->__if_reg_3;
        }
        else
        {
            kal_uint32 if_size;

            conf_reg_value = 0;

            conf_reg_value = (p_argu->if_3wire_mode)? (conf_reg_value | LCD_SERIAL_CONFIG_3_WIRE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_3_WIRE_BIT);
            conf_reg_value = (p_argu->if_sdi)? (conf_reg_value | LCD_SERIAL_CONFIG_SDI_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_SDI_BIT);
            if (((p_argu->if_each_trans_length) % 8) != 0)
            {
                if_size = (p_argu->if_each_trans_length == 9)? (1): ((p_argu->if_each_trans_length - 18)/7 + 3);
            }
            else
            {
                if_size = (p_argu->if_each_trans_length == 8)? (0): ((p_argu->if_each_trans_length - 16)>>2 + 2);
            }
            conf_reg_value |= ((if_size<<12)&LCD_SERIAL_CONFIG_IF_SIZE_MASK);
            
            if(p_argu->if_is_set_clk_by_scl_counts)
            {
                REG_LCD_SERIAL_WRITE_TIMING = ((p_argu->scl_wt_low_count<<16)|(p_argu->scl_wt_high_count));
                REG_LCD_SERIAL_READ_TIMING = ((p_argu->scl_rd_low_count<<16)|(p_argu->scl_rd_high_count));
            }
            else
            {
                kal_uint32 clock_divider = (52*1000*1000 / p_argu->if_clk_freq);
                REG_LCD_SERIAL_WRITE_TIMING = ((clock_divider << 16) | clock_divider);
                REG_LCD_SERIAL_READ_TIMING = ((clock_divider << 16) | clock_divider);
            }


            *conf_reg_addr = conf_reg_value;
            // no matter cs0 or cs1
            p_argu->__if_reg_1 = conf_reg_value;
            p_argu->__if_reg_2 = REG_LCD_SERIAL_WRITE_TIMING;
            p_argu->__if_reg_3 = REG_LCD_SERIAL_READ_TIMING;
        }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;


}

#elif defined(LCD_IOCTRL_MT6253_SERIES)

#if defined(__NLD_CENTRAL_CTRL__)
	void set_lcd_driving_current(kal_uint8 current)
	{
	}
	
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 	
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
   kal_uint32 save_irq_mask;
   kal_uint16 current_value=0;

   switch (current) {
   case LCD_DRIVING_2MA:
      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
      break;
   case LCD_DRIVING_4MA:
      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
      break;
   case LCD_DRIVING_6MA:
      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
      break;
   case LCD_DRIVING_8MA:
      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      break;
   case LCD_DRIVING_12MA:
      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
      break;
   default:
      return;
      break;
   }
   save_irq_mask=SaveAndSetIRQMask();
   CONFIG_LCD_DRIVING_CURRNET(current_value);
   RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      break;
	   case LCD_DRIVING_12MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
	      break;
	   default:
	      return;
	      break;
	   }
	   save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_DRIVING_CURRNET(current_value);
	   RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif

#define MT6253_LCD_PARALLEL_IF_ADDR(cs_num) (LCD_PARALLEL_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (cs_num))
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6253_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) MT6253_LCD_PARALLEL_IF_ADDR(p_argu->if_cs_no);
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 bus_width, clk_freq;
        kal_uint32 slow_factor = 1;
        conf_reg_value = *conf_reg_addr;
        
        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT;
        p_argu->if_c2rh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_SHIFT_BIT;

        p_argu->if_set_common_period = KAL_FALSE;
        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_PARALLEL_CLOCK_RATE_MASK) >> 14);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (52*1000*1000): (13*1000*1000*clk_freq);

        //chip dependent:
        if((clk_freq == 0) || (clk_freq == 3))
            slow_factor = 1;
        else if(clk_freq == 2)
            slow_factor = 2;
        else if(clk_freq == 1)
            slow_factor = 4;

        p_argu->if_total_write_cycles = (p_argu->if_wst + p_argu->if_c2wh + 3) + (p_argu->if_period + 1) / slow_factor;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + (p_argu->if_period) + 4;

        //each chip may be different
        p_argu->if_bus_width = 8;

        //bus_width:
        bus_width = (conf_reg_value & LCD_PARALLEL_BUS_WIDTH_MASK);
        p_argu->if_bus_width = (bus_width == LCD_PARALLEL_BUS_WIDTH_8BIT)? (8): (9);


        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF; 
        p_argu->if_gamma_b_lut_id = 0xFF; 
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        if(p_argu->if_cs_no == 0)
        {
            kal_uint32 gamma_table_id;
            
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE<<2))
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_g_lut_id = gamma_table_id  >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE>>2))
            {
                p_argu->if_gamma_b_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT;
            }

        }
        else// if(p_argu->if_cs_no == 1)
        {
            kal_uint32 gamma_table_id;
            //Chip-select 1 only has one gamma table for all R, G, B.
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {

            kal_uint32 width, clock;

            conf_reg_value = 0;
    
            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK);    
    
            //bus_width
            width = (p_argu->if_bus_width == 8)? (0<<16): (1<<16);
            conf_reg_value |= width;
    
            //clk_freq
            clock = (p_argu->if_clk_freq == 52*1000*1000)? (0): (p_argu->if_clk_freq / (13*1000*1000));
            conf_reg_value |= ((clock << 14) & LCD_PARALLEL_CLOCK_RATE_MASK);
    
            //gamma
            if(p_argu->if_cs_no == 0)
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE << 2);
                }
    
                if(p_argu->if_gamma_g_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_g_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
    
                if(p_argu->if_gamma_b_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_b_lut_id << LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE >> 2);
                }
    
            }
            else// if(p_argu->if_cs_no == 1)
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
            }

            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

    	}

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}


static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6253_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_SERIAL_INTERFACE_COUNT - 1))
    {
        // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) LCD_SERIAL_CONFIG_REG; // not separate cs0 or cs1
    p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 clk_freq, clk_div, gamma_id;

        conf_reg_value = *conf_reg_addr;

        p_argu->if_clk_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT_SHIFT);
        p_argu->if_clk_phase = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT) >> LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT_SHIFT);
        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_cs_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CS0_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CS0_POLARITY_BIT_SHIFT);
        }
        else// if(p_argu->if_cs_no == 1)
        {
            p_argu->if_cs_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CS1_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CS1_POLARITY_BIT_SHIFT);
        }

        p_argu->if_3wire_mode = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_9_BIT_MODE_BIT) >> LCD_SERIAL_CONFIG_9_BIT_MODE_BIT_SHIFT);
        p_argu->if_sdi = KAL_FALSE;
        p_argu->if_non_dbi_mode = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_NON_DBI_BIT) >> LCD_SERIAL_CONFIG_NON_DBI_BIT_SHIFT);
        if(p_argu->if_non_dbi_mode)
        {
            //ASSERT("Not implement yet" && 0); // ToDo...
            rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
            goto Exit;
        }
        else
        {
            p_argu->if_each_trans_length = (p_argu->if_3wire_mode == KAL_TRUE)? 9:8;
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_SERIAL_CONFIG_CLK_MASK)>>14);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (52*1000*1000): (13*1000*1000*clk_freq);

        //clk_div
        clk_div = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK) >> LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK_SHIFT;
        p_argu->if_clk_divider = (2 << clk_div);

        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF;
        p_argu->if_gamma_b_lut_id = 0xFF;
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        gamma_id = (conf_reg_value & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
        if(gamma_id != LCD_SERIAL_GAMMA_DISABLE)
        {
            p_argu->if_gamma_r_lut_id = gamma_id >> LCD_SERIAL_CONFIG_GAMMA_MASK_SHIFT;
        }

        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = 0;
        p_argu->if_sw_cs_ctrl_reg_bit = 0;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 clk_div, div_mask = 0;

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 clock;

            conf_reg_value = 0;
    
            conf_reg_value = (p_argu->if_clk_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT);
            conf_reg_value = (p_argu->if_clk_phase)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT);
    
            if(p_argu->if_cs_no == 0)
            {
                conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS0_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS0_POLARITY_BIT);
                REG_LCD_IO_CONFIG |= LCD_IO_CONFIG_CS0_FOR_SERIAL_BIT;
            }
            else// if(p_argu->if_cs_no == 1)
                {
                conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS1_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS1_POLARITY_BIT);
                REG_LCD_IO_CONFIG |= LCD_IO_CONFIG_CS1_FOR_SERIAL_BIT;
            }
    
            if(p_argu->if_non_dbi_mode)
            {
                if(p_argu->if_each_trans_length == 8)
                {
                    conf_reg_value &= ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 9)
                {
                    conf_reg_value |= LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 16)
                {
                    //SET_LCD_SERIAL_16_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
                else if(p_argu->if_each_trans_length == 18)
                {
                    //SET_LCD_SERIAL_18_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
            }
            else
            {
                conf_reg_value = (p_argu->if_3wire_mode)? (conf_reg_value | LCD_SERIAL_CONFIG_9_BIT_MODE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT);
            }
    
            ASSERT(!p_argu->if_is_set_clk_by_scl_counts);
    
            //clk_freq
            clock = (p_argu->if_clk_freq == 52*1000*1000)? (0): (p_argu->if_clk_freq / (13*1000*1000));
            conf_reg_value |= ((clock << 14) & LCD_SERIAL_CONFIG_CLK_MASK);
    
            clk_div = p_argu->if_clk_divider;
            // 16 (11b), 8 (10b), 4(01b), 2(00b),  1(x), 0(x)
            do
            {
                clk_div = clk_div/2;
                div_mask++;
            }while(clk_div);
    
            // 16 maps to 11b mask (3 in decimal, but div 5 times to 0)
            // 8 maps to 10b mask (2 in decimal, but div 4 times to 0)
            // 4 .....
            if(div_mask > 2)
            {
                div_mask -= 2;
            }
            else
            {
                div_mask = 0;
            }
            conf_reg_value |= (((div_mask)<<2) & ~LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK);
    
            if(p_argu->if_gamma_r_lut_id != 0xFF)
            {
                conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_SERIAL_CONFIG_GAMMA_MASK_SHIFT) & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
            }
            else
            {
                conf_reg_value |= (LCD_SERIAL_GAMMA_DISABLE);
            }

            // no matter cs0 or cs1
            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

        }

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;


}


#elif defined(LCD_IOCTRL_MT6236_SERIES)

#if defined(__NLD_CENTRAL_CTRL__)
  void set_lcd_driving_current(kal_uint8 current)
  {
  }

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	   //kal_uint32 save_irq_mask;
	
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_CTRL_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_DATA_PIN_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
  void set_lcd_driving_current(kal_uint8 current)
	{
	   //kal_uint32 save_irq_mask;
	
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_CTRL_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_DATA_PIN_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif
#define MT6236_LCD_PARALLEL_IF_ADDR(cs_num) (LCD_PARALLEL0_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (cs_num))
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6236_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) MT6236_LCD_PARALLEL_IF_ADDR(p_argu->if_cs_no);
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 bus_width, clk_freq;
        kal_uint32 slow_factor = 1;
        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT;
        p_argu->if_c2rh = 0;

        p_argu->if_set_common_period = KAL_FALSE;
        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> LCD_ROI_CTRL_PERIOD_OFFSET;

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_PARALLEL_CLOCK_RATE_MASK) >> LCD_PARALLEL_CLOCK_RATE_SHIFT_BIT);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (104*1000*1000): (26*1000*1000*clk_freq);

        //chip dependent:
        if((clk_freq == 0) || (clk_freq == 3))
            slow_factor = 1;
        else if(clk_freq == 2)
            slow_factor = 2;
        else if(clk_freq == 1)
            slow_factor = 4;

        p_argu->if_total_write_cycles = (p_argu->if_wst + p_argu->if_c2wh + 3) + (p_argu->if_period + 1) / slow_factor;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + (p_argu->if_period) + 4;

        //bus_width:
        bus_width = ((conf_reg_value & LCD_PARALLEL_BUS_WIDTH_MASK) >> LCD_PARALLEL_BUS_WIDTH_SHIFT_BIT);
        p_argu->if_bus_width = (bus_width < 2)? (8 + bus_width): ((8 + bus_width - 2) * 2);

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF; 
        p_argu->if_gamma_b_lut_id = 0xFF; 
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        if(p_argu->if_cs_no == 0)
        {
            kal_uint32 gamma_table_id;
            
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE<<2))
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_g_lut_id = gamma_table_id  >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE>>2))
            {
                p_argu->if_gamma_b_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT;
            }

        }
        else
        {
            kal_uint32 gamma_table_id;
            //Chip-select 1,2 only has one gamma table for all R, G, B.
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }


        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 width, clock;

            conf_reg_value = 0;

            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK);

            //bus_width
            width = (p_argu->if_bus_width < 16)? (p_argu->if_bus_width - 8): (p_argu->if_bus_width / 2 - 6);
            conf_reg_value |= ((width << LCD_PARALLEL_BUS_WIDTH_SHIFT_BIT) & LCD_PARALLEL_BUS_WIDTH_MASK);

            //clk_freq
            clock = (p_argu->if_clk_freq == 104*1000*1000)? (0): (p_argu->if_clk_freq / (26*1000*1000));
            conf_reg_value |= ((clock << LCD_PARALLEL_CLOCK_RATE_SHIFT_BIT) & LCD_PARALLEL_CLOCK_RATE_MASK);
            
            //gamma            
            if(p_argu->if_cs_no == 0)
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE << 2);
                }
    
                if(p_argu->if_gamma_g_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_g_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
    
                if(p_argu->if_gamma_b_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_b_lut_id << LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE >> 2);
                }
    
            }
            else
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
            }

            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

    	}

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6236_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    conf_reg_addr = (volatile kal_uint32*) LCD_SERIAL_CONFIG_REG; // not separate cs0 or cs1
    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 clk_freq, clk_div, gamma_id;

        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_clk_polarity = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_clk_phase = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_3wire_mode = (conf_reg_value & LCD_SERIAL_CONFIG_9_BIT_MODE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_non_dbi_mode = (conf_reg_value & LCD_SERIAL_CONFIG_NON_DBI_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_cs_polarity = (conf_reg_value & LCD_SERIAL_CONFIG_CS0_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;

        if(p_argu->if_non_dbi_mode)
        {
            //ASSERT("Not implement yet" && 0); // ToDo...
            rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
            goto Exit;
        }
        else
        {
            p_argu->if_each_trans_length = (p_argu->if_3wire_mode == KAL_TRUE)? 9:8;
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;

        //clk_freq
        clk_freq = (conf_reg_value & LCD_SERIAL_CONFIG_CLK_MASK) >> LCD_SERIAL_CLOCK_RATE_SHIFT_BIT;
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (104*1000*1000): (26*1000*1000*clk_freq);

        //clk_div
        clk_div = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK) >> LCD_SERIAL_CONFIG_CLOCK_DIVIDE_SHIFT_BIT;
        p_argu->if_clk_divider = (2 << clk_div);

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF;
        p_argu->if_gamma_b_lut_id = 0xFF;
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        gamma_id = (conf_reg_value & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
        if(gamma_id != LCD_SERIAL_GAMMA_DISABLE)
        {
            p_argu->if_gamma_r_lut_id = gamma_id >> LCD_SERIAL_GAMMA_ID_SHIFT_BIT;
        }

        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = 0;
        p_argu->if_sw_cs_ctrl_reg_bit = 0;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> LCD_ROI_CTRL_PERIOD_OFFSET;

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 clk_div, div_mask = 0;

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 clock;

            conf_reg_value = 0;
    
            conf_reg_value = (p_argu->if_clk_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT);
            conf_reg_value = (p_argu->if_clk_phase)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT);
            conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS0_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS0_POLARITY_BIT);
    
            if(p_argu->if_non_dbi_mode)
            {
                if(p_argu->if_each_trans_length == 8)
                {
                    conf_reg_value &= ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 9)
                {
                    conf_reg_value |= LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 16)
                {
                    //SET_LCD_SERIAL_16_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
                else if(p_argu->if_each_trans_length == 18)
                {
                    //SET_LCD_SERIAL_18_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
            }
            else
            {
                conf_reg_value = (p_argu->if_3wire_mode)? (conf_reg_value | LCD_SERIAL_CONFIG_9_BIT_MODE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT);
            }
    
            ASSERT(!p_argu->if_is_set_clk_by_scl_counts);
    
            //clk_freq
            clock = (p_argu->if_clk_freq == 104*1000*1000)? (0): (p_argu->if_clk_freq / (26*1000*1000));
            conf_reg_value |= ((clock << LCD_SERIAL_CLOCK_RATE_SHIFT_BIT) & LCD_SERIAL_CONFIG_CLK_MASK);
    
            //clk_div
            clk_div = p_argu->if_clk_divider;
            // 16 (11b), 8 (10b), 4(01b), 2(00b),  1(x), 0(x)
            do
            {
                clk_div = clk_div/2;
                div_mask++;
            }while(clk_div);
    
            // 16 maps to 11b mask (3 in decimal, but div 5 times to 0)
            // 8 maps to 10b mask (2 in decimal, but div 4 times to 0)
            // 4 .....
            if(div_mask > 2)
            {
                div_mask -= 2;
            }
            else
            {
                div_mask = 0;
            }
            conf_reg_value |= (((div_mask)<<2) & ~LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK);
    
            //gamma
            if(p_argu->if_gamma_r_lut_id != 0xFF)
            {
                conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_SERIAL_GAMMA_ID_SHIFT_BIT) & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
            }
            else
            {
                conf_reg_value |= (LCD_SERIAL_GAMMA_DISABLE);
            }

            // no matter cs0 or cs1
            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

        }

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

#elif defined(LCD_IOCTRL_MT6276_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
  void set_lcd_driving_current(kal_uint8 current)
  {
  }
  
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
  
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	   //kal_uint32 save_irq_mask;
	
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_CTRL_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_WRB_A0_RDB_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_NLD_DRIVING_CURRNET(current);
	
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	   //kal_uint32 save_irq_mask;
	
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_CTRL_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_WRB_A0_RDB_PIN_DRIVING_CURRNET(current);
	   CONFIG_LCD_NLD_DRIVING_CURRNET(current);
	
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */

#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6276_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = ((volatile kal_uint32 *) (LCD_PARALLEL0_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (p_argu->if_cs_no)));
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {   
        kal_uint32 bus_width;

        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET;
        p_argu->if_c2rh = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> LCD_ROI_CTRL_PERIOD_OFFSET;
        p_argu->if_set_common_period = KAL_FALSE;

        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 3;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + p_argu->if_c2rh + (p_argu->if_period) + 3;

        //bus_width:
        bus_width = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_BUS_WIDTH_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(p_argu->if_cs_no);
        p_argu->if_bus_width = (bus_width < 2)? (8 + bus_width): ((8 + bus_width - 2) * 2);

        // HW clock rate is: 122.88 MHz. It can't be configured.
        p_argu->if_clk_freq = 122880000;

        // gamma table
        {         
           //76E2 does not have Gamma
           //kal_uint32 gamma_table_id;
           //kal_uint32 reg_gamcon = REG_LCD_GAMMA_CON;
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = (kal_uint32 *)0;
           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 width;

            conf_reg_value = 0;

            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET) & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET) & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET) & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rh) << LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET) & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK);

            *conf_reg_addr = conf_reg_value;
    
            //bus_width
            width = (p_argu->if_bus_width < 16)? (p_argu->if_bus_width - 8): (p_argu->if_bus_width / 2 - 6);
            SET_LCD_PARALLEL_DATA_BUS(p_argu->if_cs_no, width);
    
            // gamma table
            //76E2 does not have Gamma            

            p_argu->__if_reg_1 = conf_reg_value;
    	  }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6276_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else if(p_argu->if_cs_no == 1)
    {
        //p_argu->if_data_port_addr = LCD_SERIAL1_A0_HIGH_ADDR;
        //p_argu->if_cmd_port_addr = LCD_SERIAL1_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 reg_config = GET_LCD_SERIAL_IF_REG(p_argu->if_cs_no);
        kal_uint32 timing_reg_config=GET_LCD_SERIAL_IF_TIMING_REG;
        kal_uint32 clk_freq, clk_div, gamma_id;

        p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_3wire_mode = (reg_config & LCD_SCNF_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_non_dbi_mode = (reg_config & LCD_SERIAL_CONFIG_NON_DBI_BIT)? KAL_TRUE: KAL_FALSE;

        if(p_argu->if_cs_no == 0)
        {
           p_argu->if_cs_polarity = (reg_config & LCD_SERIAL_CONFIG_CS0_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;
        }
        else
        {
           p_argu->if_cs_polarity = (reg_config & LCD_SERIAL_CONFIG_CS1_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;
        }

        if(p_argu->if_non_dbi_mode)
        {
            //ASSERT("Not implement yet" && 0); // ToDo...
            rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
            goto Exit;
        }
        else
        {
            p_argu->if_each_trans_length = (p_argu->if_3wire_mode == KAL_TRUE)? 9:8;
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;

        clk_freq = (reg_config & LCD_SERIAL_CONFIG_CLK_MASK);
        
        if(clk_freq == LCD_SERIAL_CONFIG_104MHZ_CLK)
        {
            p_argu->if_clk_freq = 104*1000*1000;
        }
        else if(clk_freq == LCD_SERIAL_CONFIG_52MHZ_CLK)
        {
            p_argu->if_clk_freq = 52*1000*1000;
        }
        else if(clk_freq == LCD_SERIAL_CONFIG_26MHZ_CLK)
        {
            p_argu->if_clk_freq = 26*1000*1000;
        }
        else
        {
            ASSERT(0);
        }

        clk_div = (reg_config & LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK) >> LCD_SERIAL_CONFIG_CLOCK_DIVIDE_SHIFT_BIT;
        p_argu->if_clk_divider = (2 << clk_div);

        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF;
        p_argu->if_gamma_b_lut_id = 0xFF;
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        gamma_id = (reg_config & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
        if(gamma_id != LCD_SERIAL_GAMMA_DISABLE)
        {
            p_argu->if_gamma_r_lut_id = gamma_id >> LCD_SERIAL_GAMMA_ID_SHIFT_BIT;
        }

        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = 0;
        p_argu->if_sw_cs_ctrl_reg_bit = 0;

        p_argu->__if_reg_fast_mode = KAL_FALSE;
        p_argu->scl_wr_1st_count = (timing_reg_config & SCL_WR_LOW_MASK) >> SCL_WR_LOW_OFFSET;
        p_argu->scl_wr_2nd_count = (timing_reg_config & SCL_WR_HIGH_MASK) >> SCL_WR_HIGH_OFFSET;
        p_argu->scl_rd_1st_count = (timing_reg_config & SCL_RD_LOW_MASK) >> SCL_RD_LOW_OFFSET;
        p_argu->scl_rd_2nd_count = (timing_reg_config & SCL_RD_HIGH_MASK) >> SCL_RD_HIGH_OFFSET;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 clk_div, div_mask = 0;

        if(p_argu->__if_reg_fast_mode)
        {
            REG_LCD_SERIAL_CONFIG = p_argu->__if_reg_1;
        }
        else
        {
            SET_LCD_SCNF_RD_LOW_COUNT( p_argu->scl_rd_1st_count);
            SET_LCD_SCNF_RD_HIGH_COUNT(p_argu->scl_rd_2nd_count);
            SET_LCD_SCNF_WR_LOW_COUNT(p_argu->scl_wr_1st_count);
            SET_LCD_SCNF_WR_HIGH_COUNT(p_argu->scl_wr_2nd_count);

            if(p_argu->if_clk_polarity)
            {
                //SET_LCD_SERIAL_CLOCK_POLARITY_HIGH;
            }
            else
            {
                //SET_LCD_SERIAL_CLOCK_POLARITY_LOW;
            }
    
            if(p_argu->if_clk_phase)
            {
                //SET_LCD_SERIAL_CLOCK_PHASE_HIGH;
            }
            else
            {
                //SET_LCD_SERIAL_CLOCK_PHASE_LOW;
            }
    
            if(p_argu->if_cs_polarity)
            {
                //SET_LCD_SERIAL_CS0_POLARITY_HIGH;
            }
            else
            {
                //SET_LCD_SERIAL_CS0_POLARITY_LOW;
            }
    
            if(p_argu->if_non_dbi_mode)
            {
                if(p_argu->if_each_trans_length == 8)
                {
                    SET_LCD_SERIAL_8_BIT_MODE;
                }
                else if(p_argu->if_each_trans_length == 9)
                {
                    SET_LCD_SERIAL_9_BIT_MODE;
                }
                else if(p_argu->if_each_trans_length == 16)
                {
                    SET_LCD_SERIAL_16_BIT_MODE;
                }
                else if(p_argu->if_each_trans_length == 18)
                {
                    SET_LCD_SERIAL_18_BIT_MODE;
                }
            }
            else
            {
                if(p_argu->if_3wire_mode)
                {
                    SET_LCD_SERIAL_9_BIT_MODE;
                }
                else
                {
                    SET_LCD_SERIAL_8_BIT_MODE;
                }
            }
    
            ASSERT(!p_argu->if_is_set_clk_by_scl_counts);
    
    
            if(p_argu->if_clk_freq == 104*1000*1000)
            {
                //SET_LCD_SERIAL_CLOCK(LCD_SERIAL_CONFIG_104MHZ_CLK);
            }
            else if(p_argu->if_clk_freq == 52*1000*1000)
            {
                //SET_LCD_SERIAL_CLOCK(LCD_SERIAL_CONFIG_52MHZ_CLK);
            }
            else if(p_argu->if_clk_freq == 26*1000*1000)
            {
                //SET_LCD_SERIAL_CLOCK(LCD_SERIAL_CONFIG_26MHZ_CLK);
            }
            else
            {
                ASSERT(0);
            }
    
            clk_div = p_argu->if_clk_divider;
            // clk    reg
            //  16 -> 11b = 3
            //   8 -> 10b = 2
            //   4 -> 01b = 1
            //   2 -> 00b = 0

            // 16 = 10000b -> 4 zeros
            //  8 =  1000b -> 3 zeros
            //  4 =   100b -> 2 zeros
            //  2 =    10b -> 1 zeros

            // reg = #zero - 1
            do
            {
                clk_div = clk_div >> 1;
                div_mask++;
            }while(1 != clk_div);
    
            //SET_LCD_SERIAL_DIVIDER(div_mask); // this macro will minus 1 automatically

            if(p_argu->if_gamma_r_lut_id != 0xFF)
            {
                SET_LCD_SERIAL_GAMMA_TABLE(p_argu->if_gamma_r_lut_id << LCD_SERIAL_GAMMA_ID_SHIFT_BIT);
            }
            else
            {
                SET_LCD_SERIAL_GAMMA_TABLE(LCD_SERIAL_GAMMA_DISABLE);
            }

            // no matter cs0 or cs1
            p_argu->__if_reg_1 = REG_LCD_SERIAL_CONFIG;

        }

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

#elif defined(LCD_IOCTRL_MT6255_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
  void set_lcd_driving_current(kal_uint8 current)
  {
  }
  
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
		kal_uint8 tempCurrent;
		CONFIG_LCD_NLD_PIN_DRIVING_CURRNET_IO_DRV2(current);
		switch(current)
		{
			case 0:
			case 1:tempCurrent = 0;break;
			case 2:
			case 3:tempCurrent = 1;break;
			case 4:
			case 5:tempCurrent = 2;break;
			case 6:
			case 7:tempCurrent = 3;break;
			default:tempCurrent = 1;
		}
		CONFIG_LCD_NLD_PIN_DRIVING_CURRNET_IO_DRV1(tempCurrent);
	    CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(tempCurrent);
	    CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(tempCurrent);
    
	}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
void set_lcd_driving_current(kal_uint8 current)
{
	kal_uint8 tempCurrent;
	CONFIG_LCD_NLD_PIN_DRIVING_CURRNET_IO_DRV2(current);
	switch(current)
	{
		case 0:
		case 1:tempCurrent = 0;break;
		case 2:
		case 3:tempCurrent = 1;break;
		case 4:
		case 5:tempCurrent = 2;break;
		case 6:
		case 7:tempCurrent = 3;break;
		default:tempCurrent = 1;
	}
	CONFIG_LCD_NLD_PIN_DRIVING_CURRNET_IO_DRV1(tempCurrent);
    CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(tempCurrent);
    CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(tempCurrent);
    
}  /* set_lcd_driving_current() */
#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6255_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > DRV_PARALLEL_INTERFACE_COUNT)
    {
       // by chips to judge if HW support such many chip-selects
       ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    switch (p_argu->if_cs_no)
    {
       case 0:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR;
         break;
       }
       case 1:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL1_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL1_A0_LOW_ADDR;
         break;
       }
       case 2:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL2_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL2_A0_LOW_ADDR;
         break;
       }
       default:
       {
         ASSERT(0);
       }
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {   
        kal_uint32 reg_config = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
        kal_uint32 bus_width;

        p_argu->if_c2ws = (reg_config & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET;
        p_argu->if_wst = (reg_config & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET;
        p_argu->if_c2wh = (reg_config & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET;
        p_argu->if_c2rs = (reg_config & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET;
        p_argu->if_rlt = (reg_config & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET;
        p_argu->if_c2rh = (reg_config & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET;

        ///Note: different with MT6276E2, MT6256E2 has dedicated period setting for each parallel interface
        p_argu->if_period = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_CHW_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_CHW_OFFSET(p_argu->if_cs_no);
        
        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 2;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + p_argu->if_c2rh + (p_argu->if_period) + 2;

        bus_width = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_BUS_WIDTH_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(p_argu->if_cs_no);
        switch (bus_width)
        {
           case LCD_PARALLEL_BUS_WIDTH_8BIT:
           {
              p_argu->if_bus_width = 8;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_9BIT:
           {
              p_argu->if_bus_width = 9;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_16BIT:
           {
              p_argu->if_bus_width = 16;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_18BIT:
           {
              p_argu->if_bus_width = 18;
              break;
           }

           default:
           {
              ASSERT(0);
              p_argu->if_bus_width = 18;
              break;
           }
        }

        // HW clock rate is: 104 MHz. It can't be configured.
        p_argu->if_clk_freq = 104000000;      

        // gamma table
        {         
           ///For MT6256E2, GAMMA is disabled
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = NULL;           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            SET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no, p_argu->__if_reg_1);
        }
        else
        {
            SET_LCD_PARALLEL_IF_TIMING(p_argu->if_cs_no, 0, p_argu->if_c2wh, p_argu->if_c2ws,
               p_argu->if_wst, p_argu->if_c2rh, p_argu->if_c2rs, p_argu->if_rlt, p_argu->if_period);

            {
               kal_uint32 width = 0;
               switch(p_argu->if_bus_width)
               {
                  case 18:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_18BIT;
                     break;
                  }
                  case 16:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_16BIT;
                     break;
                  }
                  case 9:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_9BIT;
                     break;
                  }
                  case 8:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_8BIT;
                     break;
                  }

                  default:
                  {
                     ASSERT(0);
                  }
               }
               SET_LCD_PARALLEL_DATA_BUS(p_argu->if_cs_no, width);
            }
            p_argu->__if_reg_1 = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
    	  }
    }
    else
    {
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6255_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;
    
    ///ONLY for E2, and E2 apply new serial interface
    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else if(p_argu->if_cs_no == 1)
    {
        p_argu->if_data_port_addr = LCD_SERIAL1_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL1_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        // MT6256E2 support two serial interface
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 reg_config = GET_LCD_SERIAL_IF_REG(p_argu->if_cs_no);
        kal_uint32 timing_reg_config;

        p_argu->__if_reg_fast_mode = KAL_FALSE;
        p_argu->if_clk_freq = 104000000;
        p_argu->if_clk_divider = 1;     ///always 1
        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;     
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_TRUE;
        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;   ///not necessary SW control
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;  //default we do not SW control here
        p_argu->if_cs_polarity = KAL_TRUE;      ///MT6256E2 not support set CS polarity

        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
            switch((reg_config & LCD_SERIAL_CONFIG_SIF0_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }
        }
        else if(p_argu->if_cs_no == 1)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
            switch((reg_config & LCD_SERIAL_CONFIG_SIF1_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }            
        }

        timing_reg_config = GET_LCD_SERIAL_IF_TIMING_REG(p_argu->if_cs_no);
        p_argu->if_css_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSS_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET;
        p_argu->if_csh_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSH_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET;;
        
        p_argu->scl_wr_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET;
        p_argu->scl_wr_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET;
        p_argu->scl_rd_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET;
        p_argu->scl_rd_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET;

        p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
        p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
        p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
        p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            REG_LCD_SIF0_TIMING_REG = p_argu->__if_reg_1;
            REG_LCD_SIF1_TIMING_REG = p_argu->__if_reg_2;
            REG_LCD_SIF_CON_REG = p_argu->__if_reg_3;
            REG_LCD_SIF_CS_REG = p_argu->__if_reg_4;
        }
        else
        {

            SET_LCD_SERIAL_IF_CSS(p_argu->if_cs_no, p_argu->if_css_time);
            SET_LCD_SERIAL_IF_CSH(p_argu->if_cs_no, p_argu->if_csh_time);
            SET_LCD_SERIAL_IF_RD_1ST(p_argu->if_cs_no, p_argu->scl_rd_1st_count);
            SET_LCD_SERIAL_IF_RD_2ND(p_argu->if_cs_no, p_argu->scl_rd_2nd_count);
            SET_LCD_SERIAL_IF_WR_1ST(p_argu->if_cs_no, p_argu->scl_wr_1st_count);
            SET_LCD_SERIAL_IF_WR_2ND(p_argu->if_cs_no, p_argu->scl_wr_2nd_count);

            if(p_argu->if_cs_no == 0)
            {
        
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL0_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL0_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SDI;
                }

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL0_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL0_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL0_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL0_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL0_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL0_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }     
            }
            else if(p_argu->if_cs_no == 1)
            {
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL1_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL1_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SDI;
                }

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL1_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL1_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL1_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL1_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL1_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL1_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }     
            }

            // no matter cs0 or cs1
            p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
            p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
            p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
            p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
        }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:
    return rtn_code;
}


#elif defined(LCD_IOCTRL_MT6256_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
	void set_lcd_driving_current(kal_uint8 current)
	{
	}
	
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 	
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	#if defined(MT6256)
	          CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
	          CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
	          CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
	#endif //defined(MT6256)
	}  /* set_lcd_driving_current() */
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	#if defined(MT6256)
	          CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
	          CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
	          CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
	#endif //defined(MT6256)
	}  /* set_lcd_driving_current() */
#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6256_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > DRV_PARALLEL_INTERFACE_COUNT)
    {
       // by chips to judge if HW support such many chip-selects
       ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    switch (p_argu->if_cs_no)
    {
       case 0:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR;
         break;
       }
       case 1:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL1_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL1_A0_LOW_ADDR;
         break;
       }
       case 2:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL2_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL2_A0_LOW_ADDR;
         break;
       }
       default:
       {
         ASSERT(0);
       }
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {   
        kal_uint32 reg_config = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
        kal_uint32 bus_width;

        p_argu->if_c2ws = (reg_config & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET;
        p_argu->if_wst = (reg_config & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET;
        p_argu->if_c2wh = (reg_config & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET;
        p_argu->if_c2rs = (reg_config & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET;
        p_argu->if_rlt = (reg_config & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET;
        p_argu->if_c2rh = (reg_config & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET;

        ///Note: different with MT6276E2, MT6256E2 has dedicated period setting for each parallel interface
        p_argu->if_period = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_CHW_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_CHW_OFFSET(p_argu->if_cs_no);
        
        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 2;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + p_argu->if_c2rh + (p_argu->if_period) + 2;

        bus_width = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_BUS_WIDTH_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(p_argu->if_cs_no);
        switch (bus_width)
        {
           case LCD_PARALLEL_BUS_WIDTH_8BIT:
           {
              p_argu->if_bus_width = 8;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_9BIT:
           {
              p_argu->if_bus_width = 9;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_16BIT:
           {
              p_argu->if_bus_width = 16;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_18BIT:
           {
              p_argu->if_bus_width = 18;
              break;
           }

           default:
           {
              ASSERT(0);
              p_argu->if_bus_width = 18;
              break;
           }
        }

        // HW clock rate is: 104 MHz. It can't be configured.
        p_argu->if_clk_freq = 104000000;      

        // gamma table
        {         
           ///For MT6256E2, GAMMA is disabled
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = NULL;           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            SET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no, p_argu->__if_reg_1);
        }
        else
        {
            SET_LCD_PARALLEL_IF_TIMING(p_argu->if_cs_no, 0, p_argu->if_c2wh, p_argu->if_c2ws,
               p_argu->if_wst, p_argu->if_c2rh, p_argu->if_c2rs, p_argu->if_rlt, p_argu->if_period);

            {
               kal_uint32 width = 0;
               switch(p_argu->if_bus_width)
               {
                  case 18:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_18BIT;
                     break;
                  }
                  case 16:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_16BIT;
                     break;
                  }
                  case 9:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_9BIT;
                     break;
                  }
                  case 8:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_8BIT;
                     break;
                  }

                  default:
                  {
                     ASSERT(0);
                  }
               }
               SET_LCD_PARALLEL_DATA_BUS(p_argu->if_cs_no, width);
            }
            p_argu->__if_reg_1 = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
    	  }
    }
    else
    {
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6256_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;
    
    ///ONLY for E2, and E2 apply new serial interface
    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else if(p_argu->if_cs_no == 1)
    {
        p_argu->if_data_port_addr = LCD_SERIAL1_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL1_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        // MT6256E2 support two serial interface
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 reg_config = GET_LCD_SERIAL_IF_REG(p_argu->if_cs_no);
        kal_uint32 timing_reg_config;

        p_argu->__if_reg_fast_mode = KAL_FALSE;
        p_argu->if_clk_freq = 104000000;
        p_argu->if_clk_divider = 1;     ///always 1
        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;     
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_TRUE;
        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;   ///not necessary SW control
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;  //default we do not SW control here
        p_argu->if_cs_polarity = KAL_TRUE;      ///MT6256E2 not support set CS polarity

        // gamma table
        {         
           //56E2 does not have Gamma
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = (kal_uint32 *)0;
           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
            switch((reg_config & LCD_SERIAL_CONFIG_SIF0_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }
        }
        else if(p_argu->if_cs_no == 1)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
            switch((reg_config & LCD_SERIAL_CONFIG_SIF1_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }            
        }

        timing_reg_config = GET_LCD_SERIAL_IF_TIMING_REG(p_argu->if_cs_no);
        p_argu->if_css_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSS_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET;
        p_argu->if_csh_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSH_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET;;
        
        p_argu->scl_wr_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET;
        p_argu->scl_wr_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET;
        p_argu->scl_rd_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET;
        p_argu->scl_rd_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET;

        p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
        p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
        p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
        p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            REG_LCD_SIF0_TIMING_REG = p_argu->__if_reg_1;
            REG_LCD_SIF1_TIMING_REG = p_argu->__if_reg_2;
            REG_LCD_SIF_CON_REG = p_argu->__if_reg_3;
            REG_LCD_SIF_CS_REG = p_argu->__if_reg_4;
        }
        else
        {

            SET_LCD_SERIAL_IF_CSS(p_argu->if_cs_no, p_argu->if_css_time);
            SET_LCD_SERIAL_IF_CSH(p_argu->if_cs_no, p_argu->if_csh_time);
            SET_LCD_SERIAL_IF_RD_1ST(p_argu->if_cs_no, p_argu->scl_rd_1st_count);
            SET_LCD_SERIAL_IF_RD_2ND(p_argu->if_cs_no, p_argu->scl_rd_2nd_count);
            SET_LCD_SERIAL_IF_WR_1ST(p_argu->if_cs_no, p_argu->scl_wr_1st_count);
            SET_LCD_SERIAL_IF_WR_2ND(p_argu->if_cs_no, p_argu->scl_wr_2nd_count);

            if(p_argu->if_cs_no == 0)
            {
        
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL0_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL0_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SDI;
                }

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL0_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL0_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL0_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL0_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL0_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL0_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }     
            }
            else if(p_argu->if_cs_no == 1)
            {
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL1_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL1_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SDI;
                }

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL1_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL1_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL1_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL1_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL1_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL1_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }     
            }

            // no matter cs0 or cs1
            p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
            p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
            p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
            p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
        }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:
    return rtn_code;
}

#elif defined(LCD_IOCTRL_MT6250_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
  void set_lcd_driving_current(kal_uint8 current)
  {
  }
  
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif   
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
    kal_uint32 save_irq_mask;
    /*kal_uint16 current_value=0;

   switch (current) {
   case LCD_DRIVING_2MA:
      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
      break;
   case LCD_DRIVING_4MA:
      current_value=LCD_DRIVING_CURRENT_ADD_2MA;
      break;
   case LCD_DRIVING_6MA:
      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
      break;
   case LCD_DRIVING_8MA:
      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
      break;
   case LCD_DRIVING_10MA:
      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      break;	  
   case LCD_DRIVING_12MA:
      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
      break;
   case LCD_DRIVING_14MA:
      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
      break;	  
   case LCD_DRIVING_16MA:
      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
      break;	  
   default:
	  current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      return;
   }*/
    save_irq_mask=SaveAndSetIRQMask();
    CONFIG_LCD_DRIVING_CURRNET(current);
    RestoreIRQMask(save_irq_mask);
      //CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
      //CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
      //CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	    kal_uint32 save_irq_mask;
	    /*kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_2MA;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
	      break;
	   case LCD_DRIVING_10MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      break;	  
	   case LCD_DRIVING_12MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
	      break;
	   case LCD_DRIVING_14MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
	      break;	  
	   case LCD_DRIVING_16MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
	      break;	  
	   default:
		  current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      return;
	   }*/
	    save_irq_mask=SaveAndSetIRQMask();
	    CONFIG_LCD_DRIVING_CURRNET(current);
	    RestoreIRQMask(save_irq_mask);
	      //CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
	      //CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
	      //CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
	}  /* set_lcd_driving_current() */
#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6250_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > DRV_PARALLEL_INTERFACE_COUNT)
    {
       // by chips to judge if HW support such many chip-selects
       ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    switch (p_argu->if_cs_no)
    {
       case 0:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR;
         break;
       }
       case 1:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL1_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL1_A0_LOW_ADDR;
         break;
       }
       case 2:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL2_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL2_A0_LOW_ADDR;
         break;
       }
       default:
       {
         ASSERT(0);
       }
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {   
        kal_uint32 reg_config = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
        kal_uint32 bus_width;

        p_argu->if_c2ws = (reg_config & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET;
        p_argu->if_wst = (reg_config & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET;
        p_argu->if_c2wh = (reg_config & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET;
        p_argu->if_c2rs = (reg_config & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET;
        p_argu->if_rlt = (reg_config & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET;
        p_argu->if_c2rh = (reg_config & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET;

        p_argu->if_period = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_CHW_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_CHW_OFFSET(p_argu->if_cs_no);
        
        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 2;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + p_argu->if_c2rh + (p_argu->if_period) + 2;

        bus_width = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_BUS_WIDTH_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(p_argu->if_cs_no);
        switch (bus_width)
        {
           case LCD_PARALLEL_BUS_WIDTH_8BIT:
           {
              p_argu->if_bus_width = 8;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_9BIT:
           {
              p_argu->if_bus_width = 9;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_16BIT:
           {
              p_argu->if_bus_width = 16;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_18BIT:
           {
              p_argu->if_bus_width = 18;
              break;
           }

           default:
           {
              ASSERT(0);
              p_argu->if_bus_width = 18;
              break;
           }
        }

        // HW clock rate is: 104 MHz. It can't be configured.
	#if((defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__EMI_CLK_130MHZ__))//since 11BW1212, MT6250 support 130MHz EMI and 104MHz EMI, which will lead lcd HW clock change to 130Mhz
	p_argu->if_clk_freq = 130000000;    
	#else//default 104Mhz
        p_argu->if_clk_freq = 104000000;      
	#endif

        // gamma table
        {         
           ///For MT6250, GAMMA is disabled
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = NULL;           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            SET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no, p_argu->__if_reg_1);
        }
        else
        {
            SET_LCD_PARALLEL_IF_TIMING(p_argu->if_cs_no, 0, p_argu->if_c2wh, p_argu->if_c2ws,
               p_argu->if_wst, p_argu->if_c2rh, p_argu->if_c2rs, p_argu->if_rlt, p_argu->if_period);

            {
               kal_uint32 width = 0;
               switch(p_argu->if_bus_width)
               {
                  case 18:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_18BIT;
                     break;
                  }
                  case 16:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_16BIT;
                     break;
                  }
                  case 9:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_9BIT;
                     break;
                  }
                  case 8:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_8BIT;
                     break;
                  }

                  default:
                  {
                     ASSERT(0);
                  }
               }
               SET_LCD_PARALLEL_DATA_BUS(p_argu->if_cs_no, width);
            }
            p_argu->__if_reg_1 = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
    	  }
    }
    else
    {
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6250_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;
    
    ///ONLY for E2, and E2 apply new serial interface
    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else if(p_argu->if_cs_no == 1)
    {
        p_argu->if_data_port_addr = LCD_SERIAL1_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL1_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 reg_config = GET_LCD_SERIAL_IF_REG(p_argu->if_cs_no);
	    kal_uint32 reg_pix_config = GET_LCD_SERIAL_PIX_CON_REG(p_argu->if_cs_no);
	    kal_uint32 reg_str_byte_config = GET_LCD_SERIAL_STR_BYTE_CON_REG(p_argu->if_cs_no);
        kal_uint32 timing_reg_config;
    	kal_uint32 clk_freq; 
        
        p_argu->__if_reg_fast_mode = KAL_FALSE;
        p_argu->if_clk_divider = 1;     ///always 1
        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;     
        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_cs_polarity = KAL_TRUE;     

		clk_freq=GET_LCD_SERIAL_CLOCK(0);
		switch (clk_freq) //no matter which serial lcd if_num(0,1),they are the same clock source slection
		{
		case LCD_SERIAL_CLOCK_156MHZ: p_argu->if_clk_freq = 156000000;break;
		case LCD_SERIAL_CLOCK_130MHZ: p_argu->if_clk_freq = 130000000;break;
		case LCD_SERIAL_CLOCK_104MHZ: p_argu->if_clk_freq = 104000000;break;		
		case LCD_SERIAL_CLOCK_78MHZ: p_argu->if_clk_freq = 78000000;break;
		case LCD_SERIAL_CLOCK_52MHZ: p_argu->if_clk_freq = 52000000;break;	
		default: ASSERT(0);
		}
		
        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_2data_lane_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_PIX_2PIN_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_single_a0_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_SINGLE_A0_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_cs_stay_low_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_CS_STAY_LOW_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_start_byte_mode= (reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF0_STR_BYTE_MODE_BIT)? KAL_TRUE: KAL_FALSE;
					   

			switch((reg_config & LCD_SERIAL_CONFIG_SIF0_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }
			if (p_argu->if_2data_lane_mode == KAL_TRUE)
			{
				switch((reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_MASK)>>LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_2PIN_WIDTH_12:
	                    p_argu->if_2data_lane_each_trans_length = 12; 
						break;
	                case LCD_SCNF_IF_2PIN_WIDTH_16:
	                    p_argu->if_2data_lane_each_trans_length = 16; 
						break;
					case LCD_SCNF_IF_2PIN_WIDTH_18:
	                    p_argu->if_2data_lane_each_trans_length = 18; 					
	                    break;
	                case LCD_SCNF_IF_2PIN_WIDTH_24:
	                    p_argu->if_2data_lane_each_trans_length = 24;           
	                    break;
	                default:
	                    ASSERT(0);
	                    break;
	            }
			}
			if (p_argu->if_start_byte_mode == KAL_TRUE)
			{	
				switch((reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_MASK)>>LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8:
	                    p_argu->if_str_byte_each_trans_length = 8; 
						break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9:
	                    p_argu->if_str_byte_each_trans_length = 9;                 
	                    break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16:
	                    p_argu->if_str_byte_each_trans_length = 16;                 
	                    break;	
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18:
	                    p_argu->if_str_byte_each_trans_length = 18;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24:
	                    p_argu->if_str_byte_each_trans_length = 24;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32:
	                    p_argu->if_str_byte_each_trans_length = 32;                 
	                    break;						
	                default:
	                    ASSERT(0);
	                    break;
	            }
        	}
        }
        else if(p_argu->if_cs_no == 1)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_2data_lane_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_PIX_2PIN_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_single_a0_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_SINGLE_A0_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_cs_stay_low_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_CS_STAY_LOW_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_start_byte_mode= (reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF1_STR_BYTE_MODE_BIT)? KAL_TRUE: KAL_FALSE;
	

            switch((reg_config & LCD_SERIAL_CONFIG_SIF1_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            } 
			if (p_argu->if_2data_lane_mode == KAL_TRUE)
			{	
					switch((reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_MASK)>>LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_2PIN_WIDTH_12:
	                    p_argu->if_2data_lane_each_trans_length = 12; 
						break;
	                case LCD_SCNF_IF_2PIN_WIDTH_16:
	                    p_argu->if_2data_lane_each_trans_length = 16; 
						break;
					case LCD_SCNF_IF_2PIN_WIDTH_18:
	                    p_argu->if_2data_lane_each_trans_length = 18; 					
	                    break;
	                case LCD_SCNF_IF_2PIN_WIDTH_24:
	                    p_argu->if_2data_lane_each_trans_length = 24;           
	                    break;
	                default:
	                    ASSERT(0);
	                    break;
	            }
			}
			if (p_argu->if_start_byte_mode == KAL_TRUE)
			{				
				switch((reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_MASK)>>LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8:
	                    p_argu->if_str_byte_each_trans_length = 8; 
						break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9:
	                    p_argu->if_str_byte_each_trans_length = 9;                 
	                    break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16:
	                    p_argu->if_str_byte_each_trans_length = 16;                 
	                    break;	
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18:
	                    p_argu->if_str_byte_each_trans_length = 18;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24:
	                    p_argu->if_str_byte_each_trans_length = 24;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32:
	                    p_argu->if_str_byte_each_trans_length = 32;                 
	                    break;						
	                default:
	                    ASSERT(0);
	                    break;
	            }
        	}
        }

        timing_reg_config = GET_LCD_SERIAL_IF_TIMING_REG(p_argu->if_cs_no);
        p_argu->if_css_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSS_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET;
        p_argu->if_csh_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSH_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET;;
        
        p_argu->scl_wr_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET;
        p_argu->scl_wr_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET;
        p_argu->scl_rd_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET;
        p_argu->scl_rd_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET;

        p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
        p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
        p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
        p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;        
		p_argu->__if_reg_5 = REG_LCD_SIF_PIX_CON_REG;
		p_argu->__if_reg_6 = REG_LCD_SIF_STR_BYTE_CON_REG;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            REG_LCD_SIF0_TIMING_REG = p_argu->__if_reg_1;
            REG_LCD_SIF1_TIMING_REG = p_argu->__if_reg_2;
            REG_LCD_SIF_CON_REG = p_argu->__if_reg_3;
            REG_LCD_SIF_CS_REG = p_argu->__if_reg_4;
			REG_LCD_SIF_PIX_CON_REG = p_argu->__if_reg_5;
			REG_LCD_SIF_STR_BYTE_CON_REG = p_argu->__if_reg_6;
        }
        else
        {

            SET_LCD_SERIAL_IF_CSS(p_argu->if_cs_no, p_argu->if_css_time);
            SET_LCD_SERIAL_IF_CSH(p_argu->if_cs_no, p_argu->if_csh_time);
            SET_LCD_SERIAL_IF_RD_1ST(p_argu->if_cs_no, p_argu->scl_rd_1st_count);
            SET_LCD_SERIAL_IF_RD_2ND(p_argu->if_cs_no, p_argu->scl_rd_2nd_count);
            SET_LCD_SERIAL_IF_WR_1ST(p_argu->if_cs_no, p_argu->scl_wr_1st_count);
            SET_LCD_SERIAL_IF_WR_2ND(p_argu->if_cs_no, p_argu->scl_wr_2nd_count);

			switch (p_argu->if_clk_freq) //no matter which serial lcd if_num(0,1),they are the same clock source slection
			{
			case 156000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_156MHZ);break;
			case 130000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_130MHZ);break;
			case 104000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_104MHZ);break;		
			case 78000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_78MHZ);break;
			case 52000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_52MHZ);break;
			default: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_104MHZ);
			}
			
            if(p_argu->if_cs_no == 0)
            {
        
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL0_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL0_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SDI;
                }
				if(p_argu->if_2data_lane_mode)
                {
                    ENABLE_LCD_SERIAL0_2PIN;
	                    switch(p_argu->if_2data_lane_each_trans_length)
	                {
	                    case 12:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_12);
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);      
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_24);    
	                        break;
	                    default:
	                        ASSERT(0);
	                        break;
	                } 
                }
                else
                {
                    DISABLE_LCD_SERIAL0_2PIN;
                }
				if(p_argu->if_single_a0_mode)
                {
                    ENABLE_LCD_SERIAL0_SINGLE_A0;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SINGLE_A0;
                }
				if(p_argu->if_cs_stay_low_mode)
                {
                    ENABLE_LCD_SERIAL0_CS_STAY_LOW;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_CS_STAY_LOW;
                }
				if(p_argu->if_start_byte_mode)
                {
                    ENABLE_LCD_SERIAL0_STR_BYTE;
	                	switch(p_argu->if_str_byte_each_trans_length)
	                {
	                    case 8:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8);
	                        break;
	                    case 9:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9);      
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16);
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18);    
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24);    
	                        break;
	                    case 32:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32);    
	                        break;							
	                    default:
	                        ASSERT(0);
	                        break;
	                }  
                }
                else
                {
                    DISABLE_LCD_SERIAL0_STR_BYTE;
                }
				

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL0_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL0_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL0_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL0_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL0_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL0_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }   


            }
            else if(p_argu->if_cs_no == 1)
            {
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL1_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL1_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SDI;
                }
                
				if(p_argu->if_2data_lane_mode)
                {
                    ENABLE_LCD_SERIAL1_2PIN;
	                    switch(p_argu->if_2data_lane_each_trans_length)
	                {
	                    case 12:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_12);
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);      
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_24);    
	                        break;
	                    default:
	                        ASSERT(0);
	                        break;
	                } 
                }
                else
                {
                    DISABLE_LCD_SERIAL1_2PIN;
                }
				if(p_argu->if_single_a0_mode)
                {
                    ENABLE_LCD_SERIAL1_SINGLE_A0;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SINGLE_A0;
                }
				if(p_argu->if_cs_stay_low_mode)
                {
                    ENABLE_LCD_SERIAL1_CS_STAY_LOW;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_CS_STAY_LOW;
                }
				if(p_argu->if_start_byte_mode)
                {
                    ENABLE_LCD_SERIAL1_STR_BYTE;
	                	switch(p_argu->if_str_byte_each_trans_length)
	                {
	                    case 8:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8);
	                        break;
	                    case 9:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9);      
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16);
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18);    
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24);    
	                        break;
	                    case 32:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32);    
	                        break;							
	                    default:
	                        ASSERT(0);
	                        break;
	                }  
                }
                else
                {
                    DISABLE_LCD_SERIAL1_STR_BYTE;
                }
                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL1_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL1_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL1_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL1_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL1_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL1_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }				

            }

            // no matter cs0 or cs1
            p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
            p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
            p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
            p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
			p_argu->__if_reg_5 = REG_LCD_SIF_PIX_CON_REG;
			p_argu->__if_reg_6 = REG_LCD_SIF_STR_BYTE_CON_REG;
        }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:
    return rtn_code;
}

#elif defined(LCD_IOCTRL_MT6260_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
  void set_lcd_driving_current(kal_uint8 current)
  {
  }
#if 0		// Remove temperoraily
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
/* under construction !*/
/* under construction !*/
#endif 
#endif
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
    kal_uint32 save_irq_mask;
    /*kal_uint16 current_value=0;

   switch (current) {
   case LCD_DRIVING_2MA:
      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
      break;
   case LCD_DRIVING_4MA:
      current_value=LCD_DRIVING_CURRENT_ADD_2MA;
      break;
   case LCD_DRIVING_6MA:
      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
      break;
   case LCD_DRIVING_8MA:
      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
      break;
   case LCD_DRIVING_10MA:
      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      break;	  
   case LCD_DRIVING_12MA:
      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
      break;
   case LCD_DRIVING_14MA:
      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
      break;	  
   case LCD_DRIVING_16MA:
      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
      break;	  
   default:
	  current_value=LCD_DRIVING_CURRENT_ADD_8MA;
      return;
   }*/
    save_irq_mask=SaveAndSetIRQMask();
    CONFIG_LCD_DRIVING_CURRNET(current);
    RestoreIRQMask(save_irq_mask);
      //CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
      //CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
      //CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	    kal_uint32 save_irq_mask;
	    /*kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_0MA;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_2MA;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_4MA;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_6MA;
	      break;
	   case LCD_DRIVING_10MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      break;	  
	   case LCD_DRIVING_12MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_10MA;
	      break;
	   case LCD_DRIVING_14MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_12MA;
	      break;	  
	   case LCD_DRIVING_16MA:
	      current_value=LCD_DRIVING_CURRENT_ADD_14MA;
	      break;	  
	   default:
		  current_value=LCD_DRIVING_CURRENT_ADD_8MA;
	      return;
	   }*/
	    save_irq_mask=SaveAndSetIRQMask();
	    CONFIG_LCD_DRIVING_CURRNET(current);
	    RestoreIRQMask(save_irq_mask);
	      //CONFIG_LCD_CONTROL_PIN_DRIVING_CURRNET(current);
	      //CONFIG_LCD_CTRL_LSCE0B_PIN_DRIVING_CURRNET(current);
	      //CONFIG_LCD_NLD_PIN_DRIVING_CURRNET(current);
	}  /* set_lcd_driving_current() */

#endif

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
void set_lcd_driving_current_serial0_1v8(kal_uint8 current)
{
	kal_uint32 save_irq_mask;
	save_irq_mask=SaveAndSetIRQMask();
	CONFIG_LCD_DRIVING_CURRNET_SERIAL0_1V8(current);
	RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */

void set_lcd_driving_current_serial0_2v8(kal_uint8 current)
{
	kal_uint32 save_irq_mask;
	save_irq_mask=SaveAndSetIRQMask();
	CONFIG_LCD_DRIVING_CURRNET_SERIAL0_2V8(current);
	RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */

void set_lcd_driving_current_serial1_1v8(kal_uint8 current)
{
	kal_uint32 save_irq_mask;
	save_irq_mask=SaveAndSetIRQMask();
	CONFIG_LCD_DRIVING_CURRNET_SERIAL1_1V8(current);
	RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */

void set_lcd_driving_current_serial1_2v8(kal_uint8 current)
{
	kal_uint32 save_irq_mask;
	save_irq_mask=SaveAndSetIRQMask();
	CONFIG_LCD_DRIVING_CURRNET_SERIAL1_2V8(current);
	RestoreIRQMask(save_irq_mask);
}  /* set_lcd_driving_current() */
#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6260_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > DRV_PARALLEL_INTERFACE_COUNT)
    {
       // by chips to judge if HW support such many chip-selects
       ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    switch (p_argu->if_cs_no)
    {
       case 0:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR;
         break;
       }
       case 1:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL1_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL1_A0_LOW_ADDR;
         break;
       }
       case 2:
       {
         p_argu->if_data_port_addr = LCD_PARALLEL2_A0_HIGH_ADDR;
         p_argu->if_cmd_port_addr = LCD_PARALLEL2_A0_LOW_ADDR;
         break;
       }
       default:
       {
         ASSERT(0);
       }
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {   
        kal_uint32 reg_config = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
        kal_uint32 bus_width;

        p_argu->if_c2ws = (reg_config & LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_SETUP_TIME_OFFSET;
        p_argu->if_wst = (reg_config & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_OFFSET;
        p_argu->if_c2wh = (reg_config & LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_WRITE_HOLD_TIME_OFFSET;
        p_argu->if_c2rs = (reg_config & LCD_PARALLEL_CONFIG_READ_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_SETUP_TIME_OFFSET;
        p_argu->if_rlt = (reg_config & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_OFFSET;
        p_argu->if_c2rh = (reg_config & LCD_PARALLEL_CONFIG_READ_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_HOLD_TIME_OFFSET;

        p_argu->if_period = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_CHW_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_CHW_OFFSET(p_argu->if_cs_no);
        
        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 2;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + p_argu->if_c2rh + (p_argu->if_period) + 2;

        bus_width = (REG_LCD_PARALLEL_PDW & LCD_PARALLEL_IF_BUS_WIDTH_MASK(p_argu->if_cs_no)) >> LCD_PARALLEL_IF_BUS_WIDTH_OFFSET(p_argu->if_cs_no);
        switch (bus_width)
        {
           case LCD_PARALLEL_BUS_WIDTH_8BIT:
           {
              p_argu->if_bus_width = 8;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_9BIT:
           {
              p_argu->if_bus_width = 9;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_16BIT:
           {
              p_argu->if_bus_width = 16;
              break;
           }

           case LCD_PARALLEL_BUS_WIDTH_18BIT:
           {
              p_argu->if_bus_width = 18;
              break;
           }

           default:
           {
              ASSERT(0);
              p_argu->if_bus_width = 18;
              break;
           }
        }

        // HW clock rate is: 104 MHz. It can't be configured.
	#if((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__EMI_CLK_130MHZ__))//since 11BW1212, MT6260 support 130MHz EMI and 104MHz EMI, which will lead lcd HW clock change to 130Mhz
	p_argu->if_clk_freq = 130000000;    
	#elif((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__EMI_CLK_166MHZ__))//since 11BW1212, MT6260 support 130MHz EMI and 104MHz EMI, which will lead lcd HW clock change to 130Mhz
	p_argu->if_clk_freq = 166000000;
	#else//default 104Mhz
        p_argu->if_clk_freq = 104000000;      
	#endif

        // gamma table
        {         
           ///For MT6260, GAMMA is disabled
           p_argu->if_gamma_r_lut_id = 0xFF;
           p_argu->if_gamma_g_lut_id = 0xFF; 
           p_argu->if_gamma_b_lut_id = 0xFF; 
           p_argu->p_if_gamma_lut_addr = NULL;           
           p_argu->if_gamma_lut_size = 0;
           p_argu->if_gamma_lut_entity_bit_num = 0;
           p_argu->if_gamma_lut_entity_bit_shift = 0;
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            SET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no, p_argu->__if_reg_1);
        }
        else
        {
            SET_LCD_PARALLEL_IF_TIMING(p_argu->if_cs_no, 0, p_argu->if_c2wh, p_argu->if_c2ws,
               p_argu->if_wst, p_argu->if_c2rh, p_argu->if_c2rs, p_argu->if_rlt, p_argu->if_period);

            {
               kal_uint32 width = 0;
               switch(p_argu->if_bus_width)
               {
                  case 18:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_18BIT;
                     break;
                  }
                  case 16:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_16BIT;
                     break;
                  }
                  case 9:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_9BIT;
                     break;
                  }
                  case 8:
                  {
                     width = LCD_PARALLEL_BUS_WIDTH_8BIT;
                     break;
                  }

                  default:
                  {
                     ASSERT(0);
                  }
               }
               SET_LCD_PARALLEL_DATA_BUS(p_argu->if_cs_no, width);
            }
            p_argu->__if_reg_1 = GET_LCD_PARALLEL_IF_REG(p_argu->if_cs_no);
    	  }
    }
    else
    {
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6260_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;
    
    ///ONLY for E2, and E2 apply new serial interface
    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else if(p_argu->if_cs_no == 1)
    {
        p_argu->if_data_port_addr = LCD_SERIAL1_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL1_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 reg_config = GET_LCD_SERIAL_IF_REG(p_argu->if_cs_no);
	    kal_uint32 reg_pix_config = GET_LCD_SERIAL_PIX_CON_REG(p_argu->if_cs_no);
	    kal_uint32 reg_str_byte_config = GET_LCD_SERIAL_STR_BYTE_CON_REG(p_argu->if_cs_no);
        kal_uint32 timing_reg_config;
    	kal_uint32 clk_freq; 
        
        p_argu->__if_reg_fast_mode = KAL_FALSE;
        p_argu->if_clk_divider = 1;     ///always 1
        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;     
        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_cs_polarity = KAL_TRUE;     

		clk_freq=GET_LCD_SERIAL_CLOCK(0);
		switch (clk_freq) //no matter which serial lcd if_num(0,1),they are the same clock source slection
		{
		case LCD_SERIAL_CLOCK_132MHZ: p_argu->if_clk_freq = 132000000;break;
		case LCD_SERIAL_CLOCK_104MHZ: p_argu->if_clk_freq = 104000000;break;
		case LCD_SERIAL_CLOCK_91MHZ: p_argu->if_clk_freq = 91000000;break;		
		case LCD_SERIAL_CLOCK_26MHZ: p_argu->if_clk_freq = 26000000;break;
		default: ASSERT(0);
		}
		
        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF0_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF0_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF0_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_2data_lane_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_PIX_2PIN_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_single_a0_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_SINGLE_A0_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_cs_stay_low_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_CS_STAY_LOW_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_start_byte_mode= (reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF0_STR_BYTE_MODE_BIT)? KAL_TRUE: KAL_FALSE;
					   

			switch((reg_config & LCD_SERIAL_CONFIG_SIF0_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF0_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            }
			if (p_argu->if_2data_lane_mode == KAL_TRUE)
			{
				switch((reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_MASK)>>LCD_SERIAL_PIX_CONFIG_SIF0_2PIN_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_2PIN_WIDTH_12:
	                    p_argu->if_2data_lane_each_trans_length = 12; 
						break;
	                case LCD_SCNF_IF_2PIN_WIDTH_16:
	                    p_argu->if_2data_lane_each_trans_length = 16; 
						break;
					case LCD_SCNF_IF_2PIN_WIDTH_18:
	                    p_argu->if_2data_lane_each_trans_length = 18; 					
	                    break;
	                case LCD_SCNF_IF_2PIN_WIDTH_24:
	                    p_argu->if_2data_lane_each_trans_length = 24;           
	                    break;
	                default:
	                    ASSERT(0);
	                    break;
	            }
			}
			if (p_argu->if_start_byte_mode == KAL_TRUE)
			{	
				switch((reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_MASK)>>LCD_SERIAL_STR_BYTE_CONFIG_SIF0_PIX_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8:
	                    p_argu->if_str_byte_each_trans_length = 8; 
						break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9:
	                    p_argu->if_str_byte_each_trans_length = 9;                 
	                    break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16:
	                    p_argu->if_str_byte_each_trans_length = 16;                 
	                    break;	
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18:
	                    p_argu->if_str_byte_each_trans_length = 18;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24:
	                    p_argu->if_str_byte_each_trans_length = 24;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32:
	                    p_argu->if_str_byte_each_trans_length = 32;                 
	                    break;						
	                default:
	                    ASSERT(0);
	                    break;
	            }
        	}
        }
        else if(p_argu->if_cs_no == 1)
        {
            p_argu->if_clk_polarity = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_DEF_LEVEL_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_clk_phase = (reg_config & LCD_SERIAL_CONFIG_SIF1_LSCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_3wire_mode = (reg_config & LCD_SERIAL_CONFIG_SIF1_3WIRE_BIT)? KAL_TRUE: KAL_FALSE;
            p_argu->if_sdi = (reg_config & LCD_SERIAL_CONFIG_SIF1_SDI_ENABLE_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_2data_lane_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_PIX_2PIN_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_single_a0_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_SINGLE_A0_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_cs_stay_low_mode = (reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_CS_STAY_LOW_BIT)? KAL_TRUE: KAL_FALSE;
			p_argu->if_start_byte_mode= (reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF1_STR_BYTE_MODE_BIT)? KAL_TRUE: KAL_FALSE;
	

            switch((reg_config & LCD_SERIAL_CONFIG_SIF1_SIZE_MASK)>>LCD_SERIAL_CONFIG_SIF1_SIZE_OFFSET)
            {
                case 0:
                    p_argu->if_each_trans_length = 8;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 1:
                    p_argu->if_each_trans_length = 9;
                    p_argu->if_non_dbi_mode = KAL_FALSE;        
                    break;
                case 2:
                    p_argu->if_each_trans_length = 16;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 3:
                    p_argu->if_each_trans_length = 18;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 4:
                    p_argu->if_each_trans_length = 24;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                case 5:
                    p_argu->if_each_trans_length = 32;
                    p_argu->if_non_dbi_mode = KAL_TRUE;        
                    break;
                default:
                    ASSERT(0);
                    break;
            } 
			if (p_argu->if_2data_lane_mode == KAL_TRUE)
			{	
					switch((reg_pix_config & LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_MASK)>>LCD_SERIAL_PIX_CONFIG_SIF1_2PIN_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_2PIN_WIDTH_12:
	                    p_argu->if_2data_lane_each_trans_length = 12; 
						break;
	                case LCD_SCNF_IF_2PIN_WIDTH_16:
	                    p_argu->if_2data_lane_each_trans_length = 16; 
						break;
					case LCD_SCNF_IF_2PIN_WIDTH_18:
	                    p_argu->if_2data_lane_each_trans_length = 18; 					
	                    break;
	                case LCD_SCNF_IF_2PIN_WIDTH_24:
	                    p_argu->if_2data_lane_each_trans_length = 24;           
	                    break;
	                default:
	                    ASSERT(0);
	                    break;
	            }
			}
			if (p_argu->if_start_byte_mode == KAL_TRUE)
			{				
				switch((reg_str_byte_config & LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_MASK)>>LCD_SERIAL_STR_BYTE_CONFIG_SIF1_PIX_SIZE_OFFSET)
	            {
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8:
	                    p_argu->if_str_byte_each_trans_length = 8; 
						break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9:
	                    p_argu->if_str_byte_each_trans_length = 9;                 
	                    break;
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16:
	                    p_argu->if_str_byte_each_trans_length = 16;                 
	                    break;	
	                case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18:
	                    p_argu->if_str_byte_each_trans_length = 18;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24:
	                    p_argu->if_str_byte_each_trans_length = 24;                 
	                    break;
					case LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32:
	                    p_argu->if_str_byte_each_trans_length = 32;                 
	                    break;						
	                default:
	                    ASSERT(0);
	                    break;
	            }
        	}
        }

        timing_reg_config = GET_LCD_SERIAL_IF_TIMING_REG(p_argu->if_cs_no);
        p_argu->if_css_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSS_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSS_OFFSET;
        p_argu->if_csh_time = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_CSH_MASK) >> LCD_SERIAL_TIMING_CONFIG_CSH_OFFSET;;
        
        p_argu->scl_wr_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_1ST_OFFSET;
        p_argu->scl_wr_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_WR_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_WR_2ND_OFFSET;
        p_argu->scl_rd_1st_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_1ST_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_1ST_OFFSET;
        p_argu->scl_rd_2nd_count = (timing_reg_config & LCD_SERIAL_TIMING_CONFIG_RD_2ND_MASK) >> LCD_SERIAL_TIMING_CONFIG_RD_2ND_OFFSET;

        p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
        p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
        p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
        p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;        
		p_argu->__if_reg_5 = REG_LCD_SIF_PIX_CON_REG;
		p_argu->__if_reg_6 = REG_LCD_SIF_STR_BYTE_CON_REG;
    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        if(p_argu->__if_reg_fast_mode)
        {
            REG_LCD_SIF0_TIMING_REG = p_argu->__if_reg_1;
            REG_LCD_SIF1_TIMING_REG = p_argu->__if_reg_2;
            REG_LCD_SIF_CON_REG = p_argu->__if_reg_3;
            REG_LCD_SIF_CS_REG = p_argu->__if_reg_4;
			REG_LCD_SIF_PIX_CON_REG = p_argu->__if_reg_5;
			REG_LCD_SIF_STR_BYTE_CON_REG = p_argu->__if_reg_6;
        }
        else
        {

            SET_LCD_SERIAL_IF_CSS(p_argu->if_cs_no, p_argu->if_css_time);
            SET_LCD_SERIAL_IF_CSH(p_argu->if_cs_no, p_argu->if_csh_time);
            SET_LCD_SERIAL_IF_RD_1ST(p_argu->if_cs_no, p_argu->scl_rd_1st_count);
            SET_LCD_SERIAL_IF_RD_2ND(p_argu->if_cs_no, p_argu->scl_rd_2nd_count);
            SET_LCD_SERIAL_IF_WR_1ST(p_argu->if_cs_no, p_argu->scl_wr_1st_count);
            SET_LCD_SERIAL_IF_WR_2ND(p_argu->if_cs_no, p_argu->scl_wr_2nd_count);

			switch (p_argu->if_clk_freq) //no matter which serial lcd if_num(0,1),they are the same clock source slection
			{
			case 132000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_132MHZ);break;
			case 104000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_104MHZ);break;
			case 91000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_91MHZ);break;		
			case 26000000: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_26MHZ);break;
			default: SET_LCD_SERIAL_CLOCK(0,LCD_SERIAL_CLOCK_104MHZ);
			}
			
            if(p_argu->if_cs_no == 0)
            {
        
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL0_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL0_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL0_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SDI;
                }
				if(p_argu->if_2data_lane_mode)
                {
                    ENABLE_LCD_SERIAL0_2PIN;
	                    switch(p_argu->if_2data_lane_each_trans_length)
	                {
	                    case 12:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_12);
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);      
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_24);    
	                        break;
	                    default:
	                        ASSERT(0);
	                        break;
	                } 
                }
                else
                {
                    DISABLE_LCD_SERIAL0_2PIN;
                }
				if(p_argu->if_single_a0_mode)
                {
                    ENABLE_LCD_SERIAL0_SINGLE_A0;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_SINGLE_A0;
                }
				if(p_argu->if_cs_stay_low_mode)
                {
                    ENABLE_LCD_SERIAL0_CS_STAY_LOW;
                }
                else
                {
                    DISABLE_LCD_SERIAL0_CS_STAY_LOW;
                }
				if(p_argu->if_start_byte_mode)
                {
                    ENABLE_LCD_SERIAL0_STR_BYTE;
	                	switch(p_argu->if_str_byte_each_trans_length)
	                {
	                    case 8:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8);
	                        break;
	                    case 9:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9);      
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16);
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18);    
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24);    
	                        break;
	                    case 32:
	                        SET_LCD_SERIAL0_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32);    
	                        break;							
	                    default:
	                        ASSERT(0);
	                        break;
	                }  
                }
                else
                {
                    DISABLE_LCD_SERIAL0_STR_BYTE;
                }
				

                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL0_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL0_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL0_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL0_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL0_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL0_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }   


            }
            else if(p_argu->if_cs_no == 1)
            {
                if(p_argu->if_clk_polarity)
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_DEF_LOW;
                }
    
                if(p_argu->if_clk_phase)
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_HIGH;
                }
                else
                {
                    SET_LCD_SERIAL1_CLOCK_PHASE_LOW;
                }

                if(p_argu->if_3wire_mode)
                {
                    ENABLE_LCD_SERIAL1_3WIRE;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_3WIRE;
                }

                if(p_argu->if_sdi)
                {
                    ENABLE_LCD_SERIAL1_SDI;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SDI;
                }
                
				if(p_argu->if_2data_lane_mode)
                {
                    ENABLE_LCD_SERIAL1_2PIN;
	                    switch(p_argu->if_2data_lane_each_trans_length)
	                {
	                    case 12:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_12);
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);      
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL1_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_24);    
	                        break;
	                    default:
	                        ASSERT(0);
	                        break;
	                } 
                }
                else
                {
                    DISABLE_LCD_SERIAL1_2PIN;
                }
				if(p_argu->if_single_a0_mode)
                {
                    ENABLE_LCD_SERIAL1_SINGLE_A0;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_SINGLE_A0;
                }
				if(p_argu->if_cs_stay_low_mode)
                {
                    ENABLE_LCD_SERIAL1_CS_STAY_LOW;
                }
                else
                {
                    DISABLE_LCD_SERIAL1_CS_STAY_LOW;
                }
				if(p_argu->if_start_byte_mode)
                {
                    ENABLE_LCD_SERIAL1_STR_BYTE;
	                	switch(p_argu->if_str_byte_each_trans_length)
	                {
	                    case 8:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_8);
	                        break;
	                    case 9:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_9);      
	                        break;
	                    case 16:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_16);
	                        break;
	                    case 18:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_18);    
	                        break;
	                    case 24:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_24);    
	                        break;
	                    case 32:
	                        SET_LCD_SERIAL1_IF_STR_BYTE_PIX_SIZE(LCD_SCNF_IF_STR_BYTE_PIX_WIDTH_32);    
	                        break;							
	                    default:
	                        ASSERT(0);
	                        break;
	                }  
                }
                else
                {
                    DISABLE_LCD_SERIAL1_STR_BYTE;
                }
                switch(p_argu->if_each_trans_length)
                {
                    case 8:
                        SET_LCD_SERIAL1_IF_SIZE(0);
                        break;
                    case 9:
                        SET_LCD_SERIAL1_IF_SIZE(1);      
                        break;
                    case 16:
                        SET_LCD_SERIAL1_IF_SIZE(2);
                        break;
                    case 18:
                        SET_LCD_SERIAL1_IF_SIZE(3);       
                        break;
                    case 24:
                        SET_LCD_SERIAL1_IF_SIZE(4);    
                        break;
                    case 32:
                        SET_LCD_SERIAL1_IF_SIZE(5);        
                        break;
                    default:
                        ASSERT(0);
                        break;
                }				

            }

            // no matter cs0 or cs1
            p_argu->__if_reg_1 = REG_LCD_SIF0_TIMING_REG;
            p_argu->__if_reg_2 = REG_LCD_SIF1_TIMING_REG;
            p_argu->__if_reg_3 = REG_LCD_SIF_CON_REG;
            p_argu->__if_reg_4 = REG_LCD_SIF_CS_REG;
			p_argu->__if_reg_5 = REG_LCD_SIF_PIX_CON_REG;
			p_argu->__if_reg_6 = REG_LCD_SIF_STR_BYTE_CON_REG;
        }
    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:
    return rtn_code;
}

#elif defined(LCD_IOCTRL_MT6268_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
	void set_lcd_driving_current(kal_uint8 current)
	{
	}
	
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	    kal_uint32 save_irq_mask;
	
	    save_irq_mask=SaveAndSetIRQMask();
	    CONFIG_LCD_DRIVING_CURRNET(current);
	    RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	    kal_uint32 save_irq_mask;
	
	    save_irq_mask=SaveAndSetIRQMask();
	    CONFIG_LCD_DRIVING_CURRNET(current);
	    RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6268_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;    

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = ((volatile unsigned int *) (LCD_PARALLEL_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (p_argu->if_cs_no)));
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 bus_width, clk_freq;
        kal_uint32 slow_factor = 1;
        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT;
        p_argu->if_c2rh = 0;

        p_argu->if_set_common_period = KAL_FALSE;
        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> LCD_ROI_CTRL_PERIOD_OFFSET;

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_PARALLEL_CLOCK_RATE_MASK) >> LCD_PARALLEL_CLOCK_RATE_SHIFT_BIT);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (122*1000*1000): ((30*clk_freq + clk_freq - 1)*1000*1000);

        //chip dependent:
        if((clk_freq == 0) || (clk_freq == 3))
            slow_factor = 1;
        else if(clk_freq == 2)
            slow_factor = 2;
        else if(clk_freq == 1)
            slow_factor = 4;

        p_argu->if_total_write_cycles = (p_argu->if_wst + p_argu->if_c2wh + 3) + (p_argu->if_period + 1) / slow_factor;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + (p_argu->if_period) + 4;

        //bus_width:
        bus_width = ((conf_reg_value & LCD_PARALLEL_BUS_WIDTH_MASK) >> LCD_PARALLEL_BUS_WIDTH_SHIFT_BIT);
        p_argu->if_bus_width = (bus_width < 2)? (8 + bus_width): ((8 + bus_width - 2) * 2);

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF; 
        p_argu->if_gamma_b_lut_id = 0xFF; 
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;

        if(p_argu->if_cs_no == 0)
        {
            kal_uint32 gamma_table_id;
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE<<2))
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_g_lut_id = gamma_table_id  >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE>>2))
            {
                p_argu->if_gamma_b_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT;
            }

        }
        else //if(p_argu->if_cs_no == 1, 2)
        {
            kal_uint32 gamma_table_id;
            //Chip-select 1,2 only has one gamma table for all R, G, B.
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }


        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {

            kal_uint32 width, clock;

            conf_reg_value = 0;

            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK);             

            //bus_width
            width = (p_argu->if_bus_width < 16)? (p_argu->if_bus_width - 8): (p_argu->if_bus_width / 2 - 6);
            conf_reg_value |= ((width << LCD_PARALLEL_BUS_WIDTH_SHIFT_BIT) & LCD_PARALLEL_BUS_WIDTH_MASK);

            //clk_freq
            clock = (p_argu->if_clk_freq == 122*1000*1000)? (0): (((p_argu->if_clk_freq/(1000*1000))+1)/31);
            conf_reg_value |= ((clock << LCD_PARALLEL_CLOCK_RATE_SHIFT_BIT) & LCD_PARALLEL_CLOCK_RATE_MASK);
            
            //gamma            
            if(p_argu->if_cs_no == 0)
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE << 2);
                }
    
                if(p_argu->if_gamma_g_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_g_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
    
                if(p_argu->if_gamma_b_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_b_lut_id << LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE >> 2);
                }
    
            }
            else
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
            }

            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

    	}

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6268_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    conf_reg_addr = (volatile kal_uint32*) LCD_SERIAL_CONFIG_REG; // not separate cs0 or cs1

    if(p_argu->if_cs_no == 0)
    {
        p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR;
        p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR;
    }
    else
    {
        // by chips to judge if HW support such many chip-selects
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
        goto Exit;
    }

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {    
        kal_uint32 clk_freq, clk_div, gamma_id;

        conf_reg_value = *conf_reg_addr;
        
        //timing
        p_argu->if_clk_polarity = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_clk_phase = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_3wire_mode = (conf_reg_value & LCD_SERIAL_CONFIG_9_BIT_MODE_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_non_dbi_mode = (conf_reg_value & LCD_SERIAL_CONFIG_NON_DBI_BIT)? KAL_TRUE: KAL_FALSE;
        p_argu->if_cs_polarity = (conf_reg_value & LCD_SERIAL_CONFIG_CS0_POLARITY_BIT)? KAL_TRUE: KAL_FALSE;

        if(p_argu->if_non_dbi_mode)
        {
            //ASSERT("Not implement yet" && 0); // ToDo...
            rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
            goto Exit;
        }
        else
        {
            p_argu->if_each_trans_length = (p_argu->if_3wire_mode == KAL_TRUE)? 9:8;
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;

        //clk_freq
        clk_freq = (conf_reg_value & LCD_SERIAL_CONFIG_CLK_MASK) >> LCD_SERIAL_CLOCK_RATE_SHIFT_BIT;
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (122*1000*1000): ((30*clk_freq + clk_freq - 1)*1000*1000);        
        
        //clk_div
        clk_div = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK) >> LCD_SERIAL_CONFIG_CLOCK_DIVIDE_SHIFT_BIT;
        p_argu->if_clk_divider = (2 << clk_div);

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF;
        p_argu->if_gamma_b_lut_id = 0xFF;
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        gamma_id = (conf_reg_value & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
        if(gamma_id != LCD_SERIAL_GAMMA_DISABLE)
        {
            p_argu->if_gamma_r_lut_id = gamma_id >> LCD_SERIAL_GAMMA_ID_SHIFT_BIT;
        }

        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = 0;
        p_argu->if_sw_cs_ctrl_reg_bit = 0;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> LCD_ROI_CTRL_PERIOD_OFFSET;

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 clk_div, div_mask = 0;

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 clock;

            conf_reg_value = 0;
    
            conf_reg_value = (p_argu->if_clk_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT);
            conf_reg_value = (p_argu->if_clk_phase)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT);
            conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS0_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS0_POLARITY_BIT);
    
            if(p_argu->if_non_dbi_mode)
            {
                if(p_argu->if_each_trans_length == 8)
                {
                    conf_reg_value &= ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 9)
                {
                    conf_reg_value |= LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 16)
                {
                    //SET_LCD_SERIAL_16_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
                else if(p_argu->if_each_trans_length == 18)
                {
                    //SET_LCD_SERIAL_18_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
            }
            else
            {
                conf_reg_value = (p_argu->if_3wire_mode)? (conf_reg_value | LCD_SERIAL_CONFIG_9_BIT_MODE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT);
            }
    
            ASSERT(!p_argu->if_is_set_clk_by_scl_counts);
    
    
            //clk_freq
            clock = (p_argu->if_clk_freq == 122*1000*1000)? (0): (((p_argu->if_clk_freq/(1000*1000))+1)/31);
            conf_reg_value |= ((clock << LCD_SERIAL_CLOCK_RATE_SHIFT_BIT) & LCD_SERIAL_CONFIG_CLK_MASK);
    
            //clk_div
            clk_div = p_argu->if_clk_divider;
            // clk    reg
            //  16 -> 11b = 3
            //   8 -> 10b = 2
            //   4 -> 01b = 1
            //   2 -> 00b = 0

            // 16 = 10000b -> 4 zeros
            //  8 =  1000b -> 3 zeros
            //  4 =   100b -> 2 zeros
            //  2 =    10b -> 1 zeros

            // reg = #zero - 1
            do
            {
                clk_div = clk_div >> 1;
                div_mask++;
            }while(1 != clk_div);
            conf_reg_value |= (((div_mask - 1)<<2) & ~LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK);
    
            //gamma
            if(p_argu->if_gamma_r_lut_id != 0xFF)
            {
                conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_SERIAL_GAMMA_ID_SHIFT_BIT) & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
            }
            else
            {
                conf_reg_value |= (LCD_SERIAL_GAMMA_DISABLE);
            }

            // no matter cs0 or cs1
            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

        }

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}



#elif defined(LCD_IOCTRL_MT6235_SERIES)

#if defined(__NLD_CENTRAL_CTRL__)
	void set_lcd_driving_current(kal_uint8 current)
	{
	}
	
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 	
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=0;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=0x06;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=0x05;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=0x07;
	      break;
	   }
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=0;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=0x06;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=0x05;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=0x07;
	      break;
	   }
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif

#define MT6235_LCD_PARALLEL_IF_ADDR(cs_num) (LCD_PARALLEL_CONFIG_REG + LCD_PARALLEL_IF_OFFSET * (cs_num))
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_6235_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_PARALLEL_INTERFACE_COUNT - 1))
    {
       // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) MT6235_LCD_PARALLEL_IF_ADDR(p_argu->if_cs_no);
    p_argu->if_data_port_addr = LCD_PARALLEL0_A0_HIGH_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_PARALLEL0_A0_LOW_ADDR + LCD_PARALLEL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 bus_width, clk_freq;

        conf_reg_value = *conf_reg_addr;

        //timing
        p_argu->if_c2ws = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT;
        p_argu->if_wst = (conf_reg_value & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK) >> LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT;
        p_argu->if_c2wh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT;
        p_argu->if_c2rs = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT;
        p_argu->if_rlt = (conf_reg_value & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK) >> LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT;
        p_argu->if_c2rh = (conf_reg_value & LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_MASK) >> LCD_PARALLEL_CONFIG_CE2RD_HOLD_TIME_SHIFT_BIT;

        p_argu->if_set_common_period = KAL_FALSE;
        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        //chip dependent:
        p_argu->if_total_write_cycles = (p_argu->if_wst) + (p_argu->if_c2wh) + (p_argu->if_period) + 4;
        p_argu->if_total_read_cycles = (p_argu->if_rlt) + (p_argu->if_period) + 4;

        //bus_width:
        bus_width = ((conf_reg_value & LCD_PARALLEL_BUS_WIDTH_MASK) >> 16);
        p_argu->if_bus_width = (bus_width < 2)? (8 + bus_width): ((8 + bus_width - 2) * 2);

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_PARALLEL_CLOCK_RATE_MASK) >> 14);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (104*1000*1000): (26*1000*1000*clk_freq);

        //gamma
        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF; 
        p_argu->if_gamma_b_lut_id = 0xFF; 
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        if(p_argu->if_cs_no == 0)
        {
            kal_uint32 gamma_table_id;
            
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE<<2))
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_g_lut_id = gamma_table_id  >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }

            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
            if(gamma_table_id != (LCD_PARALLEL_GAMMA_DISABLE>>2))
            {
                p_argu->if_gamma_b_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT;
            }

        }
        else
        {
            kal_uint32 gamma_table_id;
            //Chip-select 1,2 only has one gamma table for all R, G, B.
            gamma_table_id = (conf_reg_value & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
            if(gamma_table_id != LCD_PARALLEL_GAMMA_DISABLE)
            {
                p_argu->if_gamma_r_lut_id = gamma_table_id >> LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT;
            }
        }

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 savedMask;
        if(p_argu->if_set_common_period)
        {
            savedMask = SaveAndSetIRQMask();
            SET_LCD_ROI_CTRL_CMD_LATENCY(p_argu->if_period);
            RestoreIRQMask(savedMask);
        }

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 width, clock;

            conf_reg_value = 0;

            //timing
            conf_reg_value |= (((p_argu->if_c2ws) << LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2wh) << LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK);
            conf_reg_value |= (((p_argu->if_wst) << LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_SHIFT_BIT) & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK);
            conf_reg_value |= (((p_argu->if_rlt) << LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
            conf_reg_value |= (((p_argu->if_c2rs) << LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_SHIFT_BIT) & LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK);

            //bus_width
            width = (p_argu->if_bus_width < 16)? (p_argu->if_bus_width - 8): (p_argu->if_bus_width / 2 - 6);
            conf_reg_value |= ((width << 16) & LCD_PARALLEL_BUS_WIDTH_MASK);

            //clk_freq
            clock = (p_argu->if_clk_freq == 104*1000*1000)? (0): (p_argu->if_clk_freq / (26*1000*1000));
            conf_reg_value |= ((clock << 14) & LCD_PARALLEL_CLOCK_RATE_MASK);
            
            //gamma            
            if(p_argu->if_cs_no == 0)
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_R_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_R_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE << 2);
                }
    
                if(p_argu->if_gamma_g_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_g_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
    
                if(p_argu->if_gamma_b_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_b_lut_id << LCD_PARALLEL_GAMMA_TABLE_B_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_B_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE >> 2);
                }
    
            }
            else
            {
                if(p_argu->if_gamma_r_lut_id != 0xFF)
                {
                    conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_PARALLEL_GAMMA_TABLE_G_SHIFT_BIT) & LCD_PARALLEL_GAMMA_TABLE_G_MASK);
                }
                else
                {
                    conf_reg_value |= (LCD_PARALLEL_GAMMA_DISABLE);
                }
            }

            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;

    	}

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;
}


static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_6235_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
    volatile kal_uint32* conf_reg_addr;
    kal_uint32 conf_reg_value;
    LCD_IOCTRL_RESULT_E rtn_code = LCD_IOCTRL_OK;

    if(p_argu->if_cs_no > (DRV_SERIAL_INTERFACE_COUNT - 1))
    {
        // by chips to judge if HW support such many chip-selects
       //ASSERT(0);
       rtn_code = LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT;
       goto Exit;
    }

    conf_reg_addr = (volatile kal_uint32*) LCD_SERIAL_CONFIG_REG; // not separate cs0 or cs1
    p_argu->if_data_port_addr = LCD_SERIAL0_A0_HIGH_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);
    p_argu->if_cmd_port_addr = LCD_SERIAL0_A0_LOW_ADDR + LCD_SERIAL_ADDR_OFFSET * (p_argu->if_cs_no);

    if(act == LCD_IOCTRL_INTERN_QUERY)
    {
        kal_uint32 clk_freq, clk_div, gamma_id;

        conf_reg_value = *conf_reg_addr;

        p_argu->if_clk_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT_SHIFT);
        p_argu->if_clk_phase = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT) >> LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT_SHIFT);
        if(p_argu->if_cs_no == 0)
        {
            p_argu->if_cs_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CS0_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CS0_POLARITY_BIT_SHIFT);
        }
        else// if(p_argu->if_cs_no == 1)
        {
            p_argu->if_cs_polarity = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_CS1_POLARITY_BIT) >> LCD_SERIAL_CONFIG_CS1_POLARITY_BIT_SHIFT);
        }

        p_argu->if_3wire_mode = (kal_bool) ((conf_reg_value & LCD_SERIAL_CONFIG_9_BIT_MODE_BIT) >> LCD_SERIAL_CONFIG_9_BIT_MODE_BIT_SHIFT);
        p_argu->if_sdi = KAL_FALSE;
        //6235 not support p_argu->if_non_dbi_mode = (kal_bool) ((*conf_reg_addr & LCD_SERIAL_CONFIG_NON_DBI_BIT) >> LCD_SERIAL_CONFIG_NON_DBI_BIT_SHIFT);
        if(p_argu->if_non_dbi_mode)
        {
            //ASSERT("Not implement yet" && 0); // ToDo...
            rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
            goto Exit;
        }
        else
        {
            p_argu->if_each_trans_length = (p_argu->if_3wire_mode == KAL_TRUE)? 9:8;
        }

        p_argu->if_is_set_clk_by_scl_counts = KAL_FALSE;

        //clk_freq
        clk_freq = ((conf_reg_value & LCD_SERIAL_CONFIG_CLK_MASK)>>14);
        p_argu->if_clk_freq = ((clk_freq == 0) || (clk_freq == 3))? (104*1000*1000): (26*1000*1000*clk_freq);

        //clk_div
        clk_div = (conf_reg_value & LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK) >> LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK_SHIFT;
        p_argu->if_clk_divider = (2 << clk_div);

        p_argu->if_gamma_r_lut_id = 0xFF;
        p_argu->if_gamma_g_lut_id = 0xFF;
        p_argu->if_gamma_b_lut_id = 0xFF;
        p_argu->p_if_gamma_lut_addr = (kal_uint32 *)LCD_GAMMA_TABLE_ADDR;
        p_argu->if_gamma_lut_size = LCD_GAMMA_TABLE_TOTAL_SIZE;
        p_argu->if_gamma_lut_entity_bit_num = LCD_GAMMA_TABLE_ENTITY_BIT_NUMBER;
        p_argu->if_gamma_lut_entity_bit_shift = LCD_GAMMA_TABLE_ENTITY_BIT_SHIFT;
        gamma_id = (conf_reg_value & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
        if(gamma_id != LCD_SERIAL_GAMMA_DISABLE)
        {
            p_argu->if_gamma_r_lut_id = gamma_id >> LCD_SERIAL_CONFIG_GAMMA_MASK_SHIFT;
        }

        p_argu->if_is_sw_cs_ctrl = KAL_FALSE;
        p_argu->if_is_cs_ctrl_mode_configurable = KAL_FALSE;
        p_argu->if_config_cs_ctrl_as_sw_mode = KAL_FALSE;
        p_argu->if_sw_cs_ctrl_reg_addr = 0;
        p_argu->if_sw_cs_ctrl_reg_bit = 0;

        p_argu->if_period = (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_PERIOD_MASK) >> 16;

        p_argu->__if_reg_fast_mode = KAL_FALSE;

    }
    else if(act == LCD_IOCTRL_INTERN_CONFIG)
    {
        kal_uint32 clk_div, div_mask = 0;

        if(p_argu->__if_reg_fast_mode)
        {
            *conf_reg_addr = p_argu->__if_reg_1;
        }
        else
        {
            kal_uint32 clock;

            conf_reg_value = 0;
    
            conf_reg_value = (p_argu->if_clk_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT);
            conf_reg_value = (p_argu->if_clk_phase)? (conf_reg_value | LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT);
        
            if(p_argu->if_cs_no == 0)
            {
                conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS0_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS0_POLARITY_BIT);
            }
            else// if(p_argu->if_cs_no == 1)
            {
                conf_reg_value = (p_argu->if_cs_polarity)? (conf_reg_value | LCD_SERIAL_CONFIG_CS1_POLARITY_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_CS1_POLARITY_BIT);
            }
    
            if(p_argu->if_non_dbi_mode)
            {
                if(p_argu->if_each_trans_length == 8)
                {
                    conf_reg_value &= ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 9)
                {
                    conf_reg_value |= LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
                }
                else if(p_argu->if_each_trans_length == 16)
                {
                    //SET_LCD_SERIAL_16_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
                else if(p_argu->if_each_trans_length == 18)
                {
                    //SET_LCD_SERIAL_18_BIT_MODE;
                    //ASSERT("Not implement yet" && 0); // ToDo...
                    rtn_code = LCD_IOCTRL_ERR_NOT_IMPLEMENT;
                    goto Exit;
                }
            }
            else
            {
                conf_reg_value = (p_argu->if_3wire_mode)? (conf_reg_value | LCD_SERIAL_CONFIG_9_BIT_MODE_BIT): (conf_reg_value & ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT);
            }
    
            ASSERT(!p_argu->if_is_set_clk_by_scl_counts);
    
            //clk_freq
            clock = (p_argu->if_clk_freq == 104*1000*1000)? (0): (p_argu->if_clk_freq / (26*1000*1000));
            conf_reg_value |= ((clock << 14) & LCD_SERIAL_CONFIG_CLK_MASK);
            
            clk_div = p_argu->if_clk_divider;
            // 16 (11b), 8 (10b), 4(01b), 2(00b),  1(x), 0(x)
            do
            {
                clk_div = clk_div/2;
                div_mask++;
            }while(clk_div);
    
            // 16 maps to 11b mask (3 in decimal, but div 5 times to 0)
            // 8 maps to 10b mask (2 in decimal, but div 4 times to 0)
            // 4 .....
            if(div_mask > 2)
            {
                div_mask -= 2;
            }
            else
            {
                div_mask = 0;
            }
            conf_reg_value |= (((div_mask)<<2) & ~LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK);
    
            if(p_argu->if_gamma_r_lut_id != 0xFF)
            {
                conf_reg_value |= ((p_argu->if_gamma_r_lut_id << LCD_SERIAL_CONFIG_GAMMA_MASK_SHIFT) & LCD_SERIAL_GAMMA_TABLE_SEL_MASK);
            }
            else
            {
                conf_reg_value |= (LCD_SERIAL_GAMMA_DISABLE);
            }

            // no matter cs0 or cs1
            *conf_reg_addr = conf_reg_value;
            p_argu->__if_reg_1 = conf_reg_value;


        }

    }
    else
    {
        //ASSERT(0);
        rtn_code = LCD_IOCTRL_ERR_MANAGER_INTERNAL;
    }

Exit:

    return rtn_code;


}


#elif defined(LCD_IOCTRL_LEGACY_SERIES)
#if defined(__NLD_CENTRAL_CTRL__)
	void set_lcd_driving_current(kal_uint8 current)
	{
	}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
	void set_lcd_driving_current_centralize(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=0;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=0x06;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=0x05;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=0x07;
	      break;
	   }
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#else
	void set_lcd_driving_current(kal_uint8 current)
	{
	   kal_uint32 save_irq_mask;
	   kal_uint16 current_value=0;
	
	   switch (current) {
	   case LCD_DRIVING_2MA:
	      current_value=0;
	      break;
	   case LCD_DRIVING_4MA:
	      current_value=0x06;
	      break;
	   case LCD_DRIVING_6MA:
	      current_value=0x05;
	      break;
	   case LCD_DRIVING_8MA:
	      current_value=0x07;
	      break;
	   }
	   //save_irq_mask=SaveAndSetIRQMask();
	   CONFIG_LCD_DRIVING_CURRNET(current);
	   //RestoreIRQMask(save_irq_mask);
	}  /* set_lcd_driving_current() */
#endif

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if_legacy_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
   return LCD_IOCTRL_OK;
}
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if_legacy_series(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
   return LCD_IOCTRL_OK;
}
#endif

// can separate into chip-dependent files
static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_parallel_if(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_PARALLEL_IF_T *p_argu)
{
  #if defined(LCD_IOCTRL_MT6252_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6252_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6253_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6253_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6236_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6236_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6276_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6276_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6255_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6255_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6256_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6256_series(act, p_argu);
 #elif defined(LCD_IOCTRL_MT6250_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6250_series(act, p_argu);
 #elif defined(LCD_IOCTRL_MT6260_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6260_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6268_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6268_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6235_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_6235_series(act, p_argu);
  #elif defined(LCD_IOCTRL_LEGACY_SERIES)
      return _lcd_ioctrl_device_dbi_parallel_if_legacy_series(act, p_argu);
  #else
      #error "Not supported chip for dbi parallel if setting"
  #endif
}

static LCD_IOCTRL_RESULT_E _lcd_ioctrl_device_dbi_serial_if(LCD_IOCTRL_IF_INTERNAL_ACT_E act, LCD_IOCTRL_DBI_SERIAL_IF_T *p_argu)
{
  #if defined(LCD_IOCTRL_MT6252_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6252_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6253_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6253_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6236_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6236_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6276_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6276_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6255_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6255_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6256_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6256_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6250_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6250_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6260_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6260_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6268_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6268_series(act, p_argu);
  #elif defined(LCD_IOCTRL_MT6235_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_6235_series(act, p_argu);
  #elif defined(LCD_IOCTRL_LEGACY_SERIES)
      return _lcd_ioctrl_device_dbi_serial_if_legacy_series(act, p_argu);
  #else
      #error "Not supported chip for dbi serial if setting" 
  #endif
}


