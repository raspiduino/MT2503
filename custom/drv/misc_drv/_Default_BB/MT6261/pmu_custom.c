/* This file can be deleted */
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
 *    pmu_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines the pmu customization settings.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "dcl.h"
#include "init.h"

// BACKLIGHT
#define PMU_BACKLIGHT_MODE    BL_ISINK_MODE         
/* BL_ISINK_MODE */



#if defined( __GPS_TRACK__)
#define ISINK0_STEP 		    ISINK_STEP_04_MA  /* ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA, ISINK_STEP_16_MA, ISINK_STEP_20_MA, 
				  			 ISINK_STEP_24_MA, ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA */
#define ISINK1_STEP                 ISINK_STEP_04_MA  /* ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA, ISINK_STEP_16_MA, ISINK_STEP_20_MA,
							 ISINK_STEP_24_MA, ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA */	
#else

#define ISINK0_STEP 		    ISINK_STEP_24_MA  /* ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA, ISINK_STEP_16_MA, ISINK_STEP_20_MA, 
				  			 ISINK_STEP_24_MA, ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA */
#define ISINK1_STEP                 ISINK_STEP_24_MA  /* ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA, ISINK_STEP_16_MA, ISINK_STEP_20_MA, 
							 ISINK_STEP_24_MA, ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA */	
#endif /* __GPS_TRACK__ */

							/* ISINK_STEP_24_MA, ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA */	
#define ISINK0_EN                   DCL_TRUE	/*DCL_TRUE, DCL_FALSE */
#define ISINK1_EN                   DCL_TRUE	/*DCL_TRUE, DCL_FALSE */

// KPLED
//#define PMU_KPLED_SEL		KPLED_SEL_4_SWITCH                
/* 	KPLED_SEL_1_SWITCH, KPLED_SEL_2_SWITCH, 
	KPLED_SEL_3_SWITCH, KPLED_SEL_4_SWITCH, 
	KPLED_SEL_5_SWITCH, KPLED_SEL_6_SWITCH, 
	KPLED_SEL_7_SWITCH, KPLED_SEL_8_SWITCH  */
#if defined(__GPS_TRACK__)
#define PMU_KPLED_MODE		KPLED_REGISTER_CTRL_MODE          /* KPLED_PWM_MODE, KPLED_REGISTER_CONTROL_MODE */
#else
#define PMU_KPLED_MODE		KPLED_PWM_MODE          /* KPLED_PWM_MODE, KPLED_REGISTER_CONTROL_MODE */
#endif
// Class-D/AB volume control
#define PMU_SPK_VOL         PMU_SPK_VOL_12_00_dB
/* PMU_SPK_VOL_MINUS_06_00_dB,	PMU_SPK_VOL_MINUS_03_00_dB,	PMU_SPK_VOL_06_00_dB,	PMU_SPK_VOL_12_00_dB */

void pmu6261_customization_init(void)
{
	
	DCL_HANDLE handle;
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	// KPLED
	{
		PMU_CTRL_KPLED_SET_SEL kpledSetSel;
		PMU_CTRL_KPLED_SET_MODE kpledSetMode;

		//kpledSetSel.sel = PMU_KPLED_SEL;
		//DclPMU_Control(handle, KPLED_SET_SEL, (DCL_CTRL_DATA_T *)&kpledSetSel);		

		kpledSetMode.mode=PMU_KPLED_MODE;
		DclPMU_Control(handle, KPLED_SET_MODE, (DCL_CTRL_DATA_T *)&kpledSetMode);
	}

	// Class-D/AB volume control
	{
		PMU_CTRL_SPK_SET_VOL spkSetVol;
		spkSetVol.dbm = PMU_SPK_VOL;
		DclPMU_Control(handle, SPK_SET_VOL, (DCL_CTRL_DATA_T *)&spkSetVol);
		
	}

	// BACKLIGHT
	{
		PMU_CTRL_ISINK_SET_STEP isinkCtrl;
		PMU_CTRL_ISINK_SET_MODE isinkCtrlMode;
        
             PMU_CTRL_ISINK_SET_EN isink_en; 

		//isinks to set pwm/register mode
		isinkCtrlMode.isink = ISINKS;
#if defined( __GPS_TRACK__)
		isinkCtrlMode.mode = ISINK_REGISTER_CTRL_MODE/* wangqi 20150205*/;
#else
		isinkCtrlMode.mode = ISINK_PWM_MODE;
#endif /* __GPS_TRACK__ */
		DclPMU_Control(handle, ISINK_SET_MODE, (DCL_CTRL_DATA_T *)&isinkCtrl);
#if  0
		//isink 0 
		isinkCtrl.isink = ISINK0;
		isinkCtrl.step = ISINK0_STEP;
		DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isinkCtrl);

		//isink 1
		isinkCtrl.isink = ISINK1;
		isinkCtrl.step = ISINK1_STEP;
		DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isinkCtrl);
#else
             
            isink_en.isink = ISINK1;
            isink_en.enable = ISINK1_EN;
            DclPMU_Control(handle, ISINK_SET_EN,(DCL_CTRL_DATA_T *)&isink_en);

            isinkCtrl.isink = ISINK1;
            isinkCtrl.step = ISINK1_STEP;
            DclPMU_Control(handle, ISINK_SET_STEP,(DCL_CTRL_DATA_T *)&isinkCtrl);
#endif /* 0 */

#if defined( __GPS_TRACK__)
#if 0
        // ISINK0 
        isink_en.isink = ISINK0;
        isink_en.enable = ISINK0_EN;
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
s
        // ISINK1
        isink_en.isink = ISINKS;
        isink_en.enable = ISINK0_EN;
        
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
#endif
#endif /* __GPS_TRACK__ */

	}
	
	DclPMU_Close(handle);
}

void Backlight_Enable(kal_bool enable)
{
    if(enable)
    {
        
        DCL_HANDLE handle; 
        PMU_CTRL_ISINK_SET_EN isink_en;		
        
        handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
        
        // ISINK0 
        isink_en.isink = ISINK0;
        isink_en.enable = ISINK0_EN;
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
        
        // ISINK1
        isink_en.isink = ISINK1;
        isink_en.enable = ISINK1_EN;
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
        
        
        DclPMU_Close(handle);
    }
    else
    {
        DCL_HANDLE handle; 
        PMU_CTRL_ISINK_SET_EN isink_en;		
        
        handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
        
        // ISINK0
        isink_en.isink = ISINK0;
        isink_en.enable = DCL_FALSE;
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
        
        // ISINK1
        isink_en.isink = ISINK1;
        isink_en.enable = DCL_FALSE;
        DclPMU_Control(handle, ISINK_SET_EN, (DCL_CTRL_DATA_T *)&isink_en);
        
        
        DclPMU_Close(handle);
    }
}
#if defined (__GPS_TRACK__)
#include "device.h"
#include "pwm_drv.h"
void pmu_drv_keypad_blink(kal_bool enable)
{

    DCL_HANDLE pwm_handle;
    PWM_LEVEL_T level;

    DCL_HANDLE led_handle;
    PMU_CTRL_KPLED_SET_EN val_led;

    //kal_prompt_trace(MOD_TST,"=====pmu_drv_keypad_blink %d",enable);
    
    level.pwm_level = (enable ? LED_LIGHT_LEVEL1 : LED_LIGHT_LEVEL0);
    pwm_handle = DclPWM_Open(DCL_LED_KP, MOD_UEM);
    DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL, (DCL_CTRL_DATA_T*)&level);
    DclPWM_Close(pwm_handle);

    led_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    val_led.enable = enable;

    DclPMU_Control(led_handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val_led);
    DclPMU_Close(led_handle);
}
#if 0
void LED_LCD_On(void)
{
//    pmu_drv_bl_isink(ISINK3,KAL_TRUE);
	    DCL_HANDLE pwm_handle;
	    PWM_LEVEL_T level;
	    level.pwm_level = 5;
	    pwm_handle= DclPWM_Open(DCL_PWM3, MOD_UEM);
	   DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL,(DCL_CTRL_DATA_T*)&level);
	   DclPWM_Close(pwm_handle);  
	 Backlight_Enable(KAL_TRUE);
}
void LED_LCD_Off(void)
{
    //pmu_drv_bl_isink(ISINK3,KAL_FALSE);
	    DCL_HANDLE pwm_handle;
	    PWM_LEVEL_T level;
	    level.pwm_level = 0;
	    pwm_handle= DclPWM_Open(DCL_PWM3, MOD_UEM);
	   DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL,(DCL_CTRL_DATA_T*)&level);
	   DclPWM_Close(pwm_handle);  
	 Backlight_Enable(KAL_FALSE);
}
#endif
/******************************************************************************
 *  Function    -  pmu_drv_bl_isink
 *  Purpose     -  ISINK端口控制LED
 *  Description -   
 * modification history
 * ----------------------------------------
 * v1.0  , 20150205,  wangqi  written
 * ----------------------------------------
 ******************************************************************************/
void pmu_drv_bl_isink(PMU_ISINK_LIST_ENUM isink,kal_bool enable)
{
    //kal_prompt_trace(MOD_TST,"=====pmu_drv_bl_isink %d %d", isink, enable);

#if defined(MT6261)

    if(ISINK0 == isink)
    {
        pmu6250_bl_isink(ISINKS, enable);
    }
    else if(ISINK1 == isink)
    {
        //Backlight_Enable(enable);不能单独控要和pmu6250_bl_isink结合
        //首次要执行pmu6250_bl_isink(ISINKS, enable);???
    }
    else if(ISINK2 == isink)
    {
        pmu_drv_keypad_blink(enable);//
    }
#else
#error "pmu_drv_bl_isink"
#endif

}


#endif /* __GPS_TRACK__ */

