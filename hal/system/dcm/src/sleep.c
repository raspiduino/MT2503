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
 *   sleep.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__
#include "reg_base.h"
#include "config_hw.h"
#include "drv_comm.h"
#include "drvpdn.h"
#include "l1_interface.h"
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "stack_config.h"
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"

#include "sst_sla.h"
#include "system_trc.h"
#include "kal_internal_api.h"
#include "intrCtrl.h"

#include "msdc_def.h"

#if defined(L1D_TEST)
extern kal_int8 L1DTest_L1SM_Is_Slept(void);
#define L1SM_IS_SLEPT() L1DTest_L1SM_Is_Slept()
#else
extern kal_bool L1SM_Is_Slept(void);
#define L1SM_IS_SLEPT() L1SM_Is_Slept()
#endif  /* L1D_TEST */

#if defined(__AUDIO_DSP_LOWPOWER_V2__) && !defined (__L1_STANDALONE__)
extern kal_bool AUDLP_Check_LowPower_Status(void);
#else
__attribute__((weak)) kal_bool AUDLP_Check_LowPower_Status(void)
{
        return KAL_FALSE;
}
#endif

extern void pmu_low_power_setting_before_sleep(void);
extern void pmu_low_power_setting_after_sleep(void);
extern void gpio_external_buck_init(void);   // init function
extern void gpio_external_buck_turn_on(void); // turn on external buck
extern void gpio_external_buck_turn_off(void); // turn off external buck
extern void gpio_strapping_pin_lowpower_set(void);
extern void gpio_strapping_pin_lowpower_restore(void);



#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
volatile static kal_bool OST_ReadyToSlept = KAL_FALSE;
volatile static Sleep_Time allow_sleep_dur;

#pragma arm section code = "INTSRAM_ROCODE"

kal_bool switch_to_sleep(void)
{

        kal_uint32 _savedMask;

        _savedMask = LockIRQ();
        
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
        while (1) {
                RestoreIRQ(_savedMask);

                kal_get_sleep_time(&allow_sleep_dur);
      
                _savedMask = LockIRQ();

                /* Enable nIRQ wake-up event after I-Bit OFF. */
                OSTD_EnableNIRQ();

                /* Get confirm. (return for next while loop if it is invalid sleep time) */
                if(kal_is_valid_sleep_time(&allow_sleep_dur) != 0) 
                        break;

                        /* Disable nIRQ wake-up event before I-Bit ON. */
                        OSTD_DisableNIRQ();
                }

                /* Check & Trigger OST Pause Mode:
                   MUST be called inside of I-Bit protection:
                */
                OST_ReadyToSlept = OSTD_CheckSleep();
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */


        if (OST_ReadyToSlept == KAL_FALSE) {
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
                /* Disable nIRQ wake-up event before I-Bit ON. */
                OSTD_DisableNIRQ();
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
                RestoreIRQ(_savedMask);
                return KAL_FALSE;
        }

#if defined(MT6250)
        /* this workaround the issue that the MSDC drains 12mA in sleep mode */
        if ((OST_ReadyToSlept == KAL_TRUE)
            && (AUDLP_Check_LowPower_Status() == KAL_FALSE))
        {               
                Idle_VMC_OnOff(KAL_FALSE);
        }
          
#elif defined (MT6260)
        /* this workaround the issue that the MSDC drains 12mA in sleep mode */
        if ((OST_ReadyToSlept == KAL_TRUE) 
            && (AUDLP_Check_LowPower_Status() == KAL_FALSE))
        {
                Idle_VMC_OnOff(KAL_FALSE);
        }

#endif

#if defined (MT6261) || defined (MT2502) || defined (MT2501)
        if ((OST_ReadyToSlept == KAL_TRUE) 
            && (AUDLP_Check_LowPower_Status() == KAL_FALSE))
        {
                gpio_strapping_pin_lowpower_set();

#if defined (__EXT_BUCK__)
                pmu_low_power_setting_before_sleep();
                gpio_external_buck_turn_off();
#endif //#if defined (__EXT_BUCK__)
        }
#endif //#if defined (MT6261) 


        arm_enter_standby_mode(OST_ReadyToSlept);      

#if defined (MT6261) || defined (MT2502) || defined (MT2501)
        if ((OST_ReadyToSlept == KAL_TRUE) 
            && (AUDLP_Check_LowPower_Status() == KAL_FALSE))
        {
#if defined (__EXT_BUCK__)
                gpio_external_buck_turn_on();
                pmu_low_power_setting_after_sleep();
#endif //#if defined (__EXT_BUCK__)

                gpio_strapping_pin_lowpower_restore();
        }
#endif //#if defined (MT6261) 


      
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
        /* Disable nIRQ wake-up event before I-Bit ON. */
        OSTD_DisableNIRQ();
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */

        RestoreIRQ(_savedMask);

        return KAL_TRUE;
}

#endif //#ifdef __MTK_TARGET__
