/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * audlp2_drv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is for DSP low power used.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#ifndef __AUDIO_LP2_DRIVER__
#define __AUDIO_LP2_DRIVER__
#include "kal_general_types.h"

typedef struct audlp2_hdl{
	 kal_uint32           audlp_timer_count;
	 kal_uint32           timer_period;
   kal_uint32           audlp_gpt;
   kal_uint16           audlp_mcu_buffer_threshold;
   kal_uint8            audlp_md2g_pwd_handle;
   kal_uint8            audlp_md2g_pwd_count;
   kal_uint8            audlp_sleep_id;

   kal_bool             fAudLP_Enable;
   kal_bool             f_timer_gethandle;
   kal_bool             f_timer_enable;
   kal_bool             f_used_idma;
   kal_bool             f_sleep_disable;
   kal_bool             f_clk_switch_26M;
}AUDLP2_Handle;

// GPT timer : 1unit = 10ms
// Kal timer : 1unit = 1 tick = 4.615ms
#if defined(MT6256_S01)
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_48K      25
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_44K      28
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_32K      38
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_24K      51
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_22K      55
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_16K      75
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_12K     100
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_11K     109
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_8K      150
   #define AUDIOLP_MCU_BUFFER_SIZE            1024*12
#else
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_48K      11
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_44K      12
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_32K      17
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_24K      23
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_22K      25
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_16K      34
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_12K      48
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_11K      52
   #define AUDIOLP_TIME_EXPIRE_WAKEUP_8K       72
   //#define AUDIOLP_MCU_BUFFER_SIZE             (1024*8.5 - 2304)
    //1280: Speech WB buffer length, 16: working of PCM, 1152 : PCM new output buffer length
    //1152: DSP wav output buffer size
    //16  : Wav play working buffer size
    //50  : Reduce for DSP VIBRATION feature
   #if defined(MT6255)
      #define AUDIOLP_MCU_BUFFER_SIZE             (1024*8.5 - 1152 - 16 - 1280)
   #else
      #define AUDIOLP_MCU_BUFFER_SIZE             (1024*12 - 1152 - 16 - 1280 - 50)
   #endif
#endif
#define AUDIOLP_MCU_BUFFER_THRESHOLD_SHORT    (AUDIOLP_MCU_BUFFER_SIZE - 576 + 1)

#if defined(MT6256_S01) || defined(MT6255)
   #define AUDIOLP_MCU_BUFFER_THRESHOLD       576*4
#else
   #define AUDIOLP_MCU_BUFFER_THRESHOLD       576*3
#endif


int AUDLP_Mode(kal_bool true_false, kal_uint16 type_dspclk_switch);
void AUDLP_SetPCMPlay_LargerBuffer(kal_bool true_false);
void AUDLP_SetDSPBufferThreshold_Short(kal_bool flag);

#if (defined(MT6256_S01) || defined(MT6255))
void AUDLP_SetTimerPeriod(kal_uint32 SamplerateIndex);
void AUDLP_StartTimer(void);
#endif

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void AUDLP_Set_ClkSwitchMode(kal_bool flag);
kal_bool AUDLP_Check_ClkSwitch26M_Flag(void);
void AUDLP_Set_ClkSwitch26M_Flag(kal_bool flag);
void AUDLP_SetClkSwitch_26M(kal_bool flag);
#endif //defined(MT6250)

#endif //__AUDIO_LP2_DRIVER__
