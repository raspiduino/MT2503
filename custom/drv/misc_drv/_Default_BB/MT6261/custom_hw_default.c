/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   custom_hw_default.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
**   Includes
*/


#include "kal_release.h"
#include "custom_hw_default.h"
#include "pwm_sw.h"
#ifndef __L1_STANDALONE__

#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "custom_nvram_editor_data_item.h"

#endif /* __L1_STANDALONE__ */

#ifdef MMI_ON_HARDWARE_P
#include "Pmic6318_sw.h"
#endif

#include "pwm_drv.h"
#if defined (__GPS_TRACK__)

/*电池电压等级划分 定义  */
/*NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT 是不参与编译的*/

#define BAT_LOW_POWEROFF_VOL  3200000
#define BAT_LOW_TX_PROHIBIT_VOL  3500000
#define BAT_LOW_WARNING_VOL  3698671
#define BAT_LEVEL_0_VOL  3801801
#define BAT_LEVEL_1_VOL  4003424
#define BAT_LEVEL_2_VOL  9999999
#define BAT_LEVEL_3_VOL  9999999
#define BAT_LEVEL_4_VOL  9999999
#define BAT_LEVEL_5_VOL  9999999
#define BAT_LEVEL_6_VOL  9999999

#endif /* __GPS_TRACK__ */

/* 
**   Globol Varibales 
*/
#if 0
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_1)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // End of #if defined(MULTI_LEVEL_BACKLIGHT_SUPPORT) && defined(LED_MAINLCD_USE_PWM_1)
/* under construction !*/
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // End of #if defined(MULTI_LEVEL_BACKLIGHT_SUPPORT) && defined(LED_MAINLCD_USE_PWM_2)
/* under construction !*/
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_3)
#endif
/*-------------------------------------------------------------------
* below is added for MT6261
*-------------------------------------------------------------------*/
#if defined(PWM1_MAX_LEVEL)
kal_uint32 PWM1_Level_Info[][2] = 
{
	/*Freq,duty*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY1_VAL}, 	/*Level 1*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY2_VAL},    /*Level 2*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY3_VAL},    /*Level 3*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY4_VAL},    /*Level 4*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY5_VAL}	/*Level 5*/
#if (PWM1_MAX_LEVEL > 5)
	,{PWM_1_FREQ_VAL,PWM_1_DUTY6_VAL},    /*Level 6*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY7_VAL},    /*Level 7*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY8_VAL},    /*Level 8*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY9_VAL},    /*Level 9*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY10_VAL},    /*Level 10*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY11_VAL},    /*Level 11*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY12_VAL},    /*Level 12*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY13_VAL},    /*Level 13*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY14_VAL},    /*Level 14*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY15_VAL},    /*Level 15*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY16_VAL},    /*Level 16*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY17_VAL},    /*Level 17*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY18_VAL},    /*Level 18*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY19_VAL},    /*Level 19*/
	{PWM_1_FREQ_VAL,PWM_1_DUTY20_VAL}    /*Level 20*/  
#endif
};
#endif


#if defined(PWM2_MAX_LEVEL)
kal_uint32 PWM2_Level_Info[][2] = 
{
	/*Freq,duty*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY1_VAL}, 	/*Level 1*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY2_VAL},    /*Level 2*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY3_VAL},    /*Level 3*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY4_VAL},    /*Level 4*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY5_VAL}	/*Level 5*/
#if (PWM2_MAX_LEVEL > 5)
	,{PWM_2_FREQ_VAL,PWM_2_DUTY6_VAL},    /*Level 6*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY7_VAL},    /*Level 7*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY8_VAL},    /*Level 8*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY9_VAL},    /*Level 9*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY10_VAL},    /*Level 10*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY11_VAL},    /*Level 11*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY12_VAL},    /*Level 12*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY13_VAL},    /*Level 13*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY14_VAL},    /*Level 14*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY15_VAL},    /*Level 15*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY16_VAL},    /*Level 16*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY17_VAL},    /*Level 17*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY18_VAL},    /*Level 18*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY19_VAL},    /*Level 19*/
	{PWM_2_FREQ_VAL,PWM_2_DUTY20_VAL}    /*Level 20*/  
#endif
};
#endif


#if defined(PWM3_MAX_LEVEL)
kal_uint32 PWM3_Level_Info[][2] = 
{
	/*Freq,duty*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY1_VAL}, 	/*Level 1*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY2_VAL},    /*Level 2*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY3_VAL},    /*Level 3*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY4_VAL},    /*Level 4*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY5_VAL}	/*Level 5*/
#if (PWM3_MAX_LEVEL > 5)
	,{PWM_3_FREQ_VAL,PWM_3_DUTY6_VAL},    /*Level 6*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY7_VAL},    /*Level 7*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY8_VAL},    /*Level 8*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY9_VAL},    /*Level 9*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY10_VAL},    /*Level 10*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY11_VAL},    /*Level 11*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY12_VAL},    /*Level 12*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY13_VAL},    /*Level 13*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY14_VAL},    /*Level 14*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY15_VAL},    /*Level 15*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY16_VAL},    /*Level 16*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY17_VAL},    /*Level 17*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY18_VAL},    /*Level 18*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY19_VAL},    /*Level 19*/
	{PWM_3_FREQ_VAL,PWM_3_DUTY20_VAL}    /*Level 20*/  
#endif
};
#endif


#if defined(PWM4_MAX_LEVEL)
kal_uint32 PWM4_Level_Info[][2] = 
{
	/*Freq,duty*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY1_VAL}, 	/*Level 1*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY2_VAL},    /*Level 2*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY3_VAL},    /*Level 3*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY4_VAL},    /*Level 4*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY5_VAL}	/*Level 5*/
#if (PWM4_MAX_LEVEL > 5)
	,{PWM_4_FREQ_VAL,PWM_4_DUTY6_VAL},    /*Level 6*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY7_VAL},    /*Level 7*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY8_VAL},    /*Level 8*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY9_VAL},    /*Level 9*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY10_VAL},    /*Level 10*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY11_VAL},    /*Level 11*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY12_VAL},    /*Level 12*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY13_VAL},    /*Level 13*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY14_VAL},    /*Level 14*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY15_VAL},    /*Level 15*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY16_VAL},    /*Level 16*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY17_VAL},    /*Level 17*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY18_VAL},    /*Level 18*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY19_VAL},    /*Level 19*/
	{PWM_4_FREQ_VAL,PWM_4_DUTY20_VAL}    /*Level 20*/  
#endif
};
#endif
/*-------------------------------------------------------------------*/


kal_uint32 Alter_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

#if defined(MT6318)
kal_uint32 PMIC6318_PWM_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

kal_uint16 pmic_custom_get_bl_pmw_type(void)
{
   // Choose BL_LED or KP_LED. If no use, just return 0.
   return BL_LED;
}
#endif

const kal_uint8 DEFAULT_HARDWARE_YEAR = 15; //2004
const kal_uint8 DEFAULT_HARDWARE_MON = 1;
const kal_uint8 DEFAULT_HARDWARE_DAY = 1;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//50ms * 10 = 0.5 sec
const kal_uint32 ADC_BOOTUP_EVAL_PERIOD  =  KAL_TICKS_50_MSEC;  
const kal_uint32 ADC_BOOTUP_EVAL_COUNT   =  10;

//10sec * 6 = 1min
const kal_uint32 ADC_IDLE_EVAL_PERIOD  =  (2*KAL_TICKS_5_SEC);
const kal_uint32 ADC_IDLE_EVAL_COUNT   =   6;

//5sec * 6 = 30sec
const kal_uint32 ADC_TALKING_EVAL_PERIOD  = (KAL_TICKS_5_SEC);
const kal_uint32 ADC_TALKING_EVAL_COUNT   =  6;

//150 * 10 ms = 1.5 sec  (unit : 10ms )
const kal_uint32 KPD_LONGPRESS_PERIOD  = 60;

//50 * 10ms = 0.5 sec  (unit : 10ms )
const kal_uint32 KPD_REPEAT_PERIOD     = 50;

#ifndef __L1_STANDALONE__

kal_uint8   MainLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   MainLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
   
#ifdef DUAL_LCD
kal_uint8   SubLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   SubLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
#endif

kal_uint32   Battery_Level_Info[BATTERY_MAX_LEVEL];

#if defined (__GPS_TRACK__)
static kal_uint32 battery_voltage_grade[BATTERY_MAX_LEVEL]=
{
    BAT_LOW_POWEROFF_VOL ,
    BAT_LOW_TX_PROHIBIT_VOL,
    BAT_LOW_WARNING_VOL,
    BAT_LEVEL_0_VOL,
    BAT_LEVEL_1_VOL,
    BAT_LEVEL_2_VOL,
    BAT_LEVEL_3_VOL,
    BAT_LEVEL_4_VOL,
    BAT_LEVEL_5_VOL,
    BAT_LEVEL_6_VOL
};


/******************************************************************************
 *  Function    -  track_drv_battery_voltage_grade
 * 
 *  Purpose     -  填充电池电量等级标准
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 01-02-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint32  track_drv_battery_voltage_grade(kal_uint8 index)
{
    return battery_voltage_grade[index];
}
#endif /* __GPS_TRACK__ */

void  custom_init_hardware_level(void *hw_level_struct)
{
    kal_uint8 i, j;

   custom_hw_level_struct *hw_level = (custom_hw_level_struct *)hw_level_struct;

    for( i=0; i< LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        MainLCD_Contrast_Level_Info[i]= hw_level->MainLCD_Contrast[i];
#ifdef DUAL_LCD        
        SubLCD_Contrast_Level_Info[i]= hw_level->SubLCD_Contrast[i];
#endif        
    }

    for( i=0; i< LCD_PARAM_MAX_LEVEL; i++ )
    {
        MainLCD_Bias_Level_Info[i]= hw_level->MainLCD_Bias[i];
        MainLCD_Linerate_Level_Info[i]= hw_level->MainLCD_Linerate[i];
        MainLCD_Temp_Level_Info[i] =  hw_level->MainLCD_Temp[i];
#ifdef DUAL_LCD
        SubLCD_Bias_Level_Info[i]= hw_level->SubLCD_Bias[i];
        SubLCD_Linerate_Level_Info[i]= hw_level->SubLCD_Linerate[i];
        SubLCD_Temp_Level_Info[i] =  hw_level->SubLCD_Temp[i];
#endif        
    }

    for( i=0; i< BATTERY_MAX_LEVEL; i++ )
#if defined (__GPS_TRACK__)
      Battery_Level_Info[i]=track_drv_battery_voltage_grade(i);
#else
      Battery_Level_Info[i] = hw_level->BatteryLevel[i];
#endif /* __GPS_TRACK__ */


#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#if !defined(LED_MAINLCD_USE_PWM_NONE)      
    for( i = 0; i< PWM_MAX_BACKLIGHT_LEVEL; i++ )
        for( j = 0; j < 2; j++ )
        {
#if defined(LED_MAINLCD_USE_PWM_1)            
            PWM1_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#elif defined(LED_MAINLCD_USE_PWM_2)            
            PWM2_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#elif defined(LED_MAINLCD_USE_PWM_3)            
            PWM3_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#endif // End of #if defined(LED_MAINLCD_USE_PWM_1)    
         }
#endif // End of #if !defined(LED_MAINLCD_USE_PWM_NONE)       

   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
#if !defined(LED_MAINLCD_USE_PWM_1)             
               PWM1_Level_Info[i][j] = hw_level->PWM1[i][j];
#endif

#if !defined(LED_MAINLCD_USE_PWM_2)             
               PWM2_Level_Info[i][j] = hw_level->PWM2[i][j];
#endif

               Alter_Level_Info[i][j] = hw_level->PWM3[i][j];
         }

#else
   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
               PWM1_Level_Info[i][j] = hw_level->PWM1[i][j];
               PWM2_Level_Info[i][j] = hw_level->PWM2[i][j];
               Alter_Level_Info[i][j] = hw_level->PWM3[i][j];
         }
#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)  
      
#if defined(MT6318)   
   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
             PMIC6318_PWM_Level_Info[i][j] = hw_level->PMIC6318BLPWM[i][j];
         }
#endif      

#if defined(DRV_PWM_AFFECT_RF) && defined(__MTK_TARGET__) && !defined(__UBL__)

//added for 6250 E1 RF desense issue
	Set_Level_of_backlight(PWM3_Level_Info);
#endif

}

#endif /* __L1_STANDALONE__ */


