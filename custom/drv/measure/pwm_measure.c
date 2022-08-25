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
 *  gpio_measure.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This fie is created to solve HAL High issue on 11BW11.44MP.
 *
 *  This file is a wrapper of driver layer global variables and should be maintained
 *  be the related driver owner because it's bad design that low layer to extern global variable to 
 *  upper layer, low layer should provide this wrapper interface, the context of these global variable
 *  is also maintained and only can be modified by the related driver layer owner who has the
 *  domain knowleage wholly.
 *
 *  But due to history reasion and a bad design when it born, Driver owner don't want to 
 *  take it back to home even after great discussion, but we have to solve the 4N HAL high
 *  issue and have to create this file, and just let it dead in the long time in the future.
 *
 *  This file it not belongs to the creater but really created by the creater, so announce here:
 *  NO ONE IS ALLOW TO MODIFY IT UNLESS YOU WANT TO BE THE OWNER OF THIS FILE.
 *  
 *  
 * Author:
 * -------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/
 
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "kal_general_types.h"
#include "custom_hw_default.h"
#include "pwm_measure.h"
#include "device.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static kal_uint32*  pwm_measure_get_pwm(pwm_measure_type_enum pwm_type);

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Extern Global Variable                                                     */
/*----------------------------------------------------------------------------*/
  
//extern kal_uint32 PWM1_Level_Info[PWM_MAX_LEVEL][2];
//extern kal_uint32 PWM2_Level_Info[PWM_MAX_LEVEL][2];

//extern kal_uint32 Alter_Level_Info[PWM_MAX_LEVEL][2];


/* Need double confirm the compile options */
#if 0
#if defined(__PWM3_FOR_MMI__) ||defined(DRV_PWM_PWM3)
#ifdef __MMI_EM_DEV_BACKLIGHT__
/* under construction !*/
#endif
#endif
#endif

/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/


#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_uint32 pwm_measure_get_max_level(pwm_measure_type_enum pwm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint32 pwm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pwm = custom_uem_get_pwm_bl_mode(GPIO_DEV_LED_MAINLCD);
	if (!pwm)
	    return PWM_MAX_LEVEL;
	
	if ((pwm - 1) == pwm_type)
		return pwm_measure_backlight_get_max_level();
	
	return PWM_MAX_LEVEL;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_uint32 pwm_measure_backlight_get_max_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
    return PWM_MAX_BACKLIGHT_LEVEL;
#else
    return PWM_MAX_LEVEL;
#endif
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_bool pwm_measure_get_level_info(pwm_measure_type_enum pwm_type, kal_uint32 level, pwm_measure_level_info_struct *level_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32* pwm_array = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (!level_info)
        return KAL_FALSE;

    if (level >= pwm_measure_get_max_level(pwm_type))
        return KAL_FALSE;

    pwm_array = pwm_measure_get_pwm(pwm_type);
    if (!pwm_array)
        return KAL_FALSE;

    level_info->freq = *(pwm_array + level * 2); // pwm_array[level][0];
    level_info->duty = *(pwm_array + level * 2 + 1); //pwm_array[level][1];
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_bool pwm_measure_set_level_info(pwm_measure_type_enum pwm_type, kal_uint32 level, pwm_measure_level_info_struct *level_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32* pwm_array = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (!level_info)
        return KAL_FALSE;

    if (level >= pwm_measure_get_max_level(pwm_type))
        return KAL_FALSE;

    pwm_array = pwm_measure_get_pwm(pwm_type);
    if (!pwm_array)
        return KAL_FALSE;

    //pwm_array[level][0] = level_info->freq;
    *(pwm_array + level * 2) = level_info->freq;
    //pwm_array[level][1] = level_info->duty;
    *(pwm_array + level * 2 + 1) = level_info->duty;
    return KAL_TRUE;
}



/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static kal_uint32*  pwm_measure_get_pwm(pwm_measure_type_enum pwm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32* pwm_array = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pwm_type)
    {
    case PWM_MEASURE_TYPE_PWM1:
        pwm_array = (kal_uint32*)PWM1_Level_Info;
        break;

    case PWM_MEASURE_TYPE_PWM2:
        pwm_array = (kal_uint32*)PWM2_Level_Info;
        break;


#ifdef LED_MAINLCD_USE_PWM_3
    case PWM_MEASURE_TYPE_PWM3:
        pwm_array = (kal_uint32*)PWM3_Level_Info;
        break;
#endif

    case PWM_MEASURE_TYPE_ALTER:
        pwm_array = (kal_uint32*)Alter_Level_Info;
        break;


    default:
        break;

    }
    return pwm_array;
}




#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */


