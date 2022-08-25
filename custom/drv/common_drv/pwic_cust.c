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
 *    pwic_cust.c
 *
 * Project:
 * --------
 *   MAUI, Bootloader
 *
 * Description:
 * ------------
 *   This Module is used for boot time PMIC settings
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "drv_comm.h"
#include	"dcl_pmic_features.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "stack_timer.h"     /*Timer*/
#include    "reg_base.h"
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "rtc_hw.h"
#include    "rtc_sw.h"
#include    "intrCtrl.h"
#include    "adc.h"
#include    "bmt.h"
#include    "keypad_hw.h"
#include    "keypad_sw.h"
#include    "eint.h"
#include    "custom_hw_default.h"
#include		"drvsignals.h"
#include		"init.h"
#include "usb_drv.h"
#include	"dcl.h"
#include	"device.h"
#include	"dcl_pwm.h"
#if !defined(MT6236PMU) && !defined(MT6326) && !defined(MT6250PMU) && !defined(MT6255PMU) && !defined(MT6256PMU) && !defined(MT6276PMU)
#include   "pwm_drv.h"
#endif


/* Define this project doesn't support backlight level */
#define BL_LEVEL_DEFAULT            5

#define PWM_CHANNEL_NONE			0
#define PWM_CHANNEL_1				1
#define PWM_CHANNEL_2				2
#define PWM_CHANNEL_3				3

// A routine to be called at very early stage (Can NOT use generic API, ex: SaveAndSetIRQMask ...), 
// Can NOT trust other variables) because event region init is NOT performed
// This is chip bug fix, we must make sure the settings are same in custom folder

extern DCL_HANDLE DclPWM_Open(DCL_DEV dev, DCL_FLAGS flags);
extern DCL_STATUS DclPWM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DclPWM_Close(DCL_HANDLE handle);


void pmic_adpt_boot_init(void){
	
	
#if defined(MT6235PMU)
	unsigned short PmicSettings;
	unsigned short delay;
	unsigned short efuse;

	ECO_VERSION chip_ver = ECO_E1;
	/* We get chip ver directly w/o using INT_ecoVersion() to avoid modifying bootloader's scat to link init.o. */
	/* To GuoXin, you can call INT_ecoVersion() to get the eco version instead of hardcode here. */   
	if(*(volatile unsigned short*)(0x80010008) == 0x6235 && *(volatile unsigned short*)(0x80010000) == 0x8A01)
	{
		chip_ver = ECO_E2;
	}   
	else if (*(volatile unsigned short*)(0x80010008) == 0x6235 && (0x8A02 == *(volatile unsigned short*)(0x80010000) || 0x8A03 == *(unsigned short*)(0x80010000)))
	{	  
		// There is two versions of E4 (E4 and E4ECO), decided by 0x8000F018[1]
		// Need to check the version and set VM according to version
		efuse = *(volatile unsigned short*)(0x8000F018);
		efuse &= 0x2;	// 0x8000F018[1] decides the E4 or E4ECO chip
		
		if (efuse == 0){
		  chip_ver = ECO_E4;
		}
		else{
		  chip_ver = ECO_E4_R;
		}		  	  		
	}
	else
	{
		chip_ver =  MT6235_latest_chip;
	}

	if (chip_ver == ECO_E2)
	{
		PmicSettings = *(volatile unsigned short*)(0x83010808);	
		PmicSettings = (PmicSettings & 0x0FFF )| (0xd << 12);
		*(volatile unsigned short*)(0x83010808) = PmicSettings;	   
		for(delay=0;delay<256;delay++);
   
		PmicSettings = *(volatile unsigned short*)(0x83010824);	
		PmicSettings = (PmicSettings & 0xFFF0 )| (0x9);
		*(volatile unsigned short*)(0x83010824) = PmicSettings;	   
		for(delay=0;delay<256;delay++);
	}
	else if (chip_ver == ECO_E4)
	{
		// E4
		PmicSettings = *(volatile unsigned short*)(0x83010808);
		PmicSettings = (PmicSettings & 0x0FFF )| (0xe << 12);
		*(volatile unsigned short*)(0x83010808) = PmicSettings;	   
		for(delay=0;delay<256;delay++);
	}
	else
	{
		// Other ECO version settings
		PmicSettings = *(volatile unsigned short*)(0x83010808);
		PmicSettings = (PmicSettings & 0x0FFF )| (0x0 << 12);
		*(volatile unsigned short*)(0x83010808) = PmicSettings;
		for(delay=0;delay<256;delay++);
	}

#elif defined(MT6238PMU)
	unsigned short PmicSettings;
	unsigned short delay;
	ECO_VERSION chip_ver = ENG_E1;
	//HW_VER = 0x80010000.
	//HW_CODE = 0x80010008.

	#if defined(MT6238)
		if ( 0x20070329 == *(volatile UINT32P)(0x840b0274)  && *(volatile unsigned short*)(0x80010008) == 0x6238 && *(volatile unsigned short*)(0x80010000) == 0x8A00 ) {
			chip_ver =  ENG_E1;
		} 
		else if (0x20070918 == *(volatile UINT32P)(0x840b0274) && *(volatile unsigned short*)(0x80010008) == 0x6238 && *(volatile unsigned short*)(0x80010000) == 0x8A00 ) {
			chip_ver =  ENG_E2; 
		}
		else if (*(volatile unsigned short*)(0x80010008) == 0x6238 && *(volatile unsigned short*)(0x80010000) == 0x8A01) {
			chip_ver =  ECO_E3;
		}
		else
		{
			chip_ver = MT6238_latest_chip;
		}

	#elif  defined(MT6239)
		if ( 0x20070329 == *(volatile UINT32P)(0x840b0274)  && *(volatile unsigned short*)(0x80010008) == 0x6239 && *(volatile unsigned short*)(0x80010000) == 0x8A00 ) {
			chip_ver =  ENG_E1;
		} 
		else if (0x20070918 == *(volatile UINT32P)(0x840b0274) && *(volatile unsigned short*)(0x80010008) == 0x6239 && *(volatile unsigned short*)(0x80010000) == 0x8A00 ) {
			chip_ver =  ENG_E2; 
		}
		else if (*(volatile unsigned short*)(0x80010008) == 0x6239 && *(volatile unsigned short*)(0x80010000) == 0x8A01) {
			chip_ver =  ECO_E3;
		}
		else
		{
			chip_ver = MT6239_latest_chip;
		}
	#endif
	
	if (chip_ver == ENG_E1 || chip_ver == ENG_E2){
		// ENG_E1/ENG_E2 settings
		// VM setting (1.9V)
		// Other ECO version settings
		// VM setting
		PmicSettings = *(volatile unsigned short*)(0x83010808);	
		PmicSettings = (PmicSettings & 0x0FFF )| (0xb << 12);
		*(volatile unsigned short*)(0x83010808) = PmicSettings;	   
	}else{
		// Other ECO version settings
		// VM setting (1.8V)
		PmicSettings = *(volatile unsigned short*)(0x83010808);	
		PmicSettings = (PmicSettings & 0x0FFF )| (0x3 << 12);
		*(volatile unsigned short*)(0x83010808) = PmicSettings;	
		
		// VFBADJ setting (1.2V) (VCORE target voltage)
		PmicSettings = *(volatile unsigned short*)(0x83010824);
		PmicSettings = (PmicSettings & 0xFFF0 )| (0x8 << 0);
		*(volatile unsigned short*)(0x83010824) = PmicSettings;	
	}
	
	for(delay=0;delay<256;delay++);
#endif // #if defined(MT6235PMU)

}

#if defined(MT6236PMU) || defined(MT6326) || defined(MT6250PMU) || defined(MT6255PMU) || defined(MT6256PMU) || defined(MT6276PMU)
kal_uint32 custom_bl_level_support_query(void)
{
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)    
#if defined(EXTERNAL_BL_DRIVER_SOURCE)

    return EXTERNAL_BL_DRIVER_STEPS;

#elif defined(INTERNAL_BL_DRIVER_SOURCE)

#if !defined(__FUE__) && !defined(__UBL__)
    DCL_HANDLE pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    PMU_CTRL_BL_GET_SUPPORT_LEVEL val;
    
    DclPMU_Control(pmu_handle, BL_GET_SUPPORT_LEVEL, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(pmu_handle);

    //EXT_ASSERT(0, val.blSupportLevel, 0, 0);
    return val.blSupportLevel;
#else
	return BL_LEVEL_DEFAULT;
#endif

#endif // #if defined(__EXTERNAL_BL_DRIVER_SOURCE__)

#else
    return BL_LEVEL_DEFAULT;
#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
}

kal_uint32 custom_use_pwm_channel_query(kal_uint8 gpio_dev_type)
{
    kal_uint32 pwm_channel = PWM_CHANNEL_NONE;
    
    switch(gpio_dev_type)
    {
        case GPIO_DEV_LED_MAINLCD:        
#if defined(LED_MAINLCD_USE_PWM_1)
            pwm_channel = PWM_CHANNEL_1;
#elif defined(LED_MAINLCD_USE_PWM_2)
            pwm_channel = PWM_CHANNEL_2;
#elif defined(LED_MAINLCD_USE_PWM_3)
            pwm_channel = PWM_CHANNEL_3;
#else
            pwm_channel = PWM_CHANNEL_NONE;
#endif
            break;
        default:
            /* error undefine */
            pwm_channel = PWM_CHANNEL_NONE;            
    }

    return pwm_channel;
}

void custom_pwm_configure(kal_uint8 gpio_dev_type, kal_uint32 level, kal_uint32 freq, kal_uint32 duty)
{   
    switch(gpio_dev_type)
    {
        case GPIO_DEV_LED_MAINLCD:        
#if defined(LED_MAINLCD_USE_PWM_1)
            PWM1_Level_Info[level - 1][0] = freq;
            PWM1_Level_Info[level - 1][1] = duty;
#elif defined(LED_MAINLCD_USE_PWM_2)
            PWM2_Level_Info[level - 1][0] = freq;
            PWM2_Level_Info[level - 1][1] = duty;
#elif defined(LED_MAINLCD_USE_PWM_3)
            PWM3_Level_Info[level - 1][0] = freq;
            PWM3_Level_Info[level - 1][1] = duty;
#endif
            break;
        default:
            /* error undefine */
            ASSERT(0);          
    }    
    
}

#else

kal_uint32 custom_bl_level_support_query(void)
{
#if defined(__MTK_TARGET__)
	DCL_HANDLE pwm_handle;
	PWM_LEVEL_T level;

	pwm_handle = DclPWM_Open(DCL_MAIN_LCD_BL, MOD_UEM);
	DclPWM_Control(pwm_handle, PWM_CMD_GET_MAX_LEVEL, (DCL_CTRL_DATA_T*)&level);
	DclPWM_Close(pwm_handle);	
	
	return level.pwm_level;
#else
	return BL_LEVEL_DEFAULT;
#endif
}

void custom_pwm_configure(kal_uint8 gpio_dev_type, kal_uint32 level, kal_uint32 freq, kal_uint32 duty)
{   
	DCL_HANDLE pwm_handle;
	PWM_DATA_T pwm_data;

    switch(gpio_dev_type)
    {
        case GPIO_DEV_LED_MAINLCD:
        	pwm_handle= DclPWM_Open(DCL_MAIN_LCD_BL, MOD_UEM);
        	pwm_data.pwm_level = level;
        	pwm_data.pwm_duty = duty;
        	pwm_data.pwm_freq = freq;
        	DclPWM_Control(pwm_handle, PWM_CMD_SET_FREQ_BY_LEVEL, (DCL_CTRL_DATA_T*)&pwm_data);
			DclPWM_Control(pwm_handle, PWM_CMD_SET_DUTY_BY_LEVEL, (DCL_CTRL_DATA_T*)&pwm_data);
			DclPWM_Close(pwm_handle);	

            break;
        default:
            /* error undefine */
            ASSERT(0);          
    }    


}
#endif // End of #if defined(MT6236PMU) || defined(MT6326) || defined(MT6250PMU) || defined(MT6255PMU) || defined(MT6256PMU) || defined(MT6276PMU)

