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
 * audlp2_drv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is for audio low power V2.
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
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#if defined(__AUDIO_DSP_LOWPOWER_V2__)

#include "kal_trace.h"
#include "kal_public_api.h"
#include "l1sp_trc.h"
#include "reg_base.h"
#include "l1audio.h"
#include "audio_def.h"
#include "audlp2_drv.h"
#include "audio_sherif_bit_def.h"
#include "PostProcess.h"
//#include "dcl.h"
#if defined(__TINY_SYS__)
#include "AP_BtSS.h"
#endif
#if defined( __CENTRALIZED_SLEEP_MANAGER__ ) && (defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502))
#include "RM_public.h"
#endif


//----------------------------------------------------------------
//  Local compile option
//----------------------------------------------------------------
//#define AUDLP_DEBUG_SET_EVB_TEST                 //only enable for debugging


//----------------------------------------------------------------
//  Local global variables
//----------------------------------------------------------------
static AUDLP2_Handle audlphdl;

#if (defined(MT6256_S01) || defined(MT6255))
static kal_timerid audlp_kal_timer = NULL;
#endif
//----------------------------------------------------------------
//  Referred functions
//----------------------------------------------------------------
extern kal_uint8 L1D_MD2G_PWD_GetHandle( void );
extern      void L1D_MD2G_PWD_Disable( kal_uint8 handle );
extern      void L1D_MD2G_PWD_Enable( kal_uint8 handle );
extern void L1SM_EnterFPM(kal_bool isFPM, kal_uint8 module);

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);

#if defined(MT6250)
extern void Audio_SW_CPD_Eevent_ChangeMode(kal_bool flag);
#endif

//----------------------------------------------------------------
#if (defined(MT6256_S01) || defined(MT6255))
#define CLKSQ_CON1_AUD                ((APBADDR)(PLL_base+0x0004))
#else

#define MODEM2G_TOPSM_SW_CLK_FORCE_ON_FLAG       ((APBADDR32)(MODEM2G_TOPSM_base+0x0A00))  //32bit
#define MODEM2G_TOPSM_SW_CLK_FORCE_ON_SET        ((APBADDR32)(MODEM2G_TOPSM_base+0x0A04))  //32bit
#define MODEM2G_TOPSM_SW_CLK_FORCE_ON_CLR        ((APBADDR32)(MODEM2G_TOPSM_base+0x0A08))  //32bit
#define MODEM2G_TOPSM_PROTECT_ACK_MASK           ((APBADDR32)(MODEM2G_TOPSM_base+0x0A38))  //32bit

#define MODEM_SLV_SM_WAKUP_REQ                   ((APBADDR32)(MDCONFIG_base+0x0500))  //32bit
#define MODEM_SLV_SM_WAKUP_RDY                   ((APBADDR32)(MDCONFIG_base+0x0504))  //32bit
#define MODEM_ALLOW_26M_CLKSW                    ((APBADDR32)(MDCONFIG_base+0x0508))  //32bit


#define SHREG_DSP2CTL                            ((APBADDR)(SHAREG2_base+0x0000))   //16bit

#endif


kal_bool AUDLP_Check_LowPower_Status(void)
{
   return audlphdl.fAudLP_Enable;
}


#if (defined(MT6256_S01) || defined(MT6255))
static void AUDLP_Set_SleepAudio_Clock(kal_bool flag)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   {
      kal_uint16  reg_value;
      reg_value  = *CLKSQ_CON1_AUD ;
      if(flag)
         reg_value |= (0x1 << 8);
      else
         reg_value &= ~(0x1 << 8);
      *CLKSQ_CON1_AUD = reg_value;
   }
   RestoreIRQMask( savedMask );
}


static void AUDLP_SW_LPAUD_ChangeMode(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint16  reg_value;

   savedMask = SaveAndSetIRQMask();
   reg_value  = *PLL_CON1;                  // switch DSP Clock source

   if(flag)
      reg_value |= (0x1 << 13);           //SW_LPAUD : switch to DSP 
   else
      reg_value &= ~(0x1 << 13);
   *PLL_CON1 = reg_value;
   RestoreIRQMask( savedMask );
}

static void AUDLP_HW_LPAUD_ChangeMode(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint16  reg_value;
   
   savedMask = SaveAndSetIRQMask();
   reg_value  = *PLL_CON1;                  // switch DSP Clock source
   if(flag)
      reg_value |= (0x1 << 12);           //HW_LPAUD : switch to DSP dependent on Sleep mode
   else
      reg_value &= ~(0x1 << 12);
   *PLL_CON1 = reg_value;
   RestoreIRQMask( savedMask );
}
#endif

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
kal_bool AUDLP_Check_ClkSwitch26M_Flag(void)
{
   return audlphdl.f_clk_switch_26M;
}

void AUDLP_Set_ClkSwitch26M_Flag(kal_bool flag)
{
   audlphdl.f_clk_switch_26M = flag;
}

void AUDLP_SetClkSwitch_26M(kal_bool flag)
{
   if (flag)
   {
      if( !audlphdl.f_clk_switch_26M & AUDLP_Check_LowPower_Status() )
      {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
         RM_Resource_Control (RM_MODEM_DSP_1, KAL_FALSE);
#else
         Audio_SW_CPD_Eevent_ChangeMode(KAL_FALSE);
#endif
         audlphdl.f_clk_switch_26M = KAL_TRUE;
         kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_26M_CLK_SWITCH, flag, audlphdl.f_clk_switch_26M);
      }
   }
	 else
	 {
      if( audlphdl.f_clk_switch_26M & AUDLP_Check_LowPower_Status() )
      {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      RM_Resource_Control (RM_MODEM_DSP_1, KAL_TRUE);
#else
         Audio_SW_CPD_Eevent_ChangeMode(KAL_TRUE);
#endif
         audlphdl.f_clk_switch_26M = KAL_FALSE;
         kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_26M_CLK_SWITCH, flag, audlphdl.f_clk_switch_26M);
      }
	 }
}

void AUDLP_Set_ClkSwitchMode(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint32  reg_value;

   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_SET_SWEVENT_CLK, flag);
   savedMask = SaveAndSetIRQMask();
   reg_value  = *MODEM_ALLOW_26M_CLKSW;
   if(flag)
   {
      *MODEM2G_TOPSM_SW_CLK_FORCE_ON_SET = ((unsigned int)0x1 << 31);
       reg_value |= (0x1 << 0);
   }
   else
   {
      *MODEM2G_TOPSM_SW_CLK_FORCE_ON_CLR = ((unsigned int)0x1 << 31);
      reg_value &= ~(0x1 << 0);
   }
   *MODEM_ALLOW_26M_CLKSW = reg_value;
   RestoreIRQMask( savedMask );
}

void AUDLP_SW_Trigger_Event_Setting(kal_bool flag)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_ENABLE_SWEVENT, flag);
   if(flag)
      RM_Resource_Control (RM_MODEM_DSP_2, flag);
   else
      RM_Resource_Control (RM_MODEM_DSP_2, flag);
#else
   kal_uint32 savedMask;
   kal_uint32  reg_value;
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_ENABLE_SWEVENT, flag);
   
   if(flag){
      savedMask = SaveAndSetIRQMask();
      reg_value  = *MODEM_SLV_SM_WAKUP_REQ;
      reg_value |= (0x1 << 0);
      *MODEM_SLV_SM_WAKUP_REQ = reg_value;
      RestoreIRQMask( savedMask );

      while(!(*MODEM_SLV_SM_WAKUP_RDY & 0x00000001));

      savedMask = SaveAndSetIRQMask();
      reg_value  = *MODEM2G_TOPSM_PROTECT_ACK_MASK;
      reg_value |= (0x1 << 0);
      *MODEM2G_TOPSM_PROTECT_ACK_MASK = reg_value;
      RestoreIRQMask( savedMask );
   }
   else{
      savedMask = SaveAndSetIRQMask();
      reg_value  = *MODEM_SLV_SM_WAKUP_REQ;
      reg_value &= ~(0x1 << 0);
      *MODEM_SLV_SM_WAKUP_REQ = reg_value;

      reg_value  = *MODEM2G_TOPSM_PROTECT_ACK_MASK;
      reg_value &= ~(0x1 << 0);
      *MODEM2G_TOPSM_PROTECT_ACK_MASK = reg_value;
      RestoreIRQMask( savedMask );
   }
#endif
}

#endif //defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

int AUDLP_Mode(kal_bool true_false, kal_uint16 type_dspclk_switch)
{
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_ENABLE_DISABLE, true_false, type_dspclk_switch);
   
   // If set AudioLP magic number in Engineer mode, disable AUDLP mode
   // If Karaoke mode, audio playback don't enter low power mode.
   {
      uint16 checkflag;
      checkflag = L1Audio_GetDebugInfo(AUDIO_DEBUG_MISC);
      if ((checkflag & AUDIO_DBG_INFOVAL_AUDLP_DISABLE) || Media_IsKaraoke())
      {
         kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_ENABLE_BYPASS);
         audlphdl.fAudLP_Enable = KAL_FALSE;
         return 0;
      }
   }

   audlphdl.fAudLP_Enable = true_false;

#ifdef AUDLP_DEBUG_SET_EVB_TEST
/* these register setup are for GPIO debug of DA_UPLL_ENA pin */
   {
#define   HW_MISC     (CONFIG_base + 0x0100)
#define   GPIO_debug1 (GPIO_base   + 0x06C0)
#define   GPIO_debug2 (GPIO_base   + 0x06D0)
      kal_uint16 register_value;
   register_value = *(volatile unsigned int *)(HW_MISC);     //[7;4]=0x7
   register_value &= 0xFF0F;
   register_value |= 0x0070;
   *(volatile unsigned int *)(HW_MISC) = register_value;
   register_value = *(volatile unsigned int *)(GPIO_debug1);     //[15:12]=0x4
   register_value &= 0x0FFF;
   register_value |= 0x4000;
   *(volatile unsigned int *)(GPIO_debug1) = register_value;
   register_value = *(volatile unsigned int *)(GPIO_debug2);     //[7:4]=0x4
   register_value &= 0xFF0F;
   register_value |= 0x0040;
   *(volatile unsigned int *)(GPIO_debug2) = register_value;
   //*(volatile unsigned int *)(0x701B0840) |= 0x0021;
   }
#endif /* AUDLP_DEBUG_SET_EVB_TEST */


   audlphdl.audlp_timer_count = 0;
#if (defined(MT6256_S01) || defined(MT6255))
   if(true_false)
   {
      
      AUDLP_Set_SleepAudio_Clock(KAL_TRUE);
      if(type_dspclk_switch)
         AUDLP_HW_LPAUD_ChangeMode(KAL_TRUE);
      else
         AUDLP_SW_LPAUD_ChangeMode(KAL_TRUE);

      L1D_MD2G_PWD_Disable(audlphdl.audlp_md2g_pwd_handle);
      audlphdl.audlp_md2g_pwd_count++;
      L1SM_EnterFPM(KAL_TRUE, 1);
   }
   else
   {
      AUDLP_Set_SleepAudio_Clock(KAL_FALSE);
      if(type_dspclk_switch)
         AUDLP_HW_LPAUD_ChangeMode(KAL_FALSE);
      else
         AUDLP_SW_LPAUD_ChangeMode(KAL_FALSE);

      if(audlphdl.audlp_md2g_pwd_count)
      {
         L1D_MD2G_PWD_Enable(audlphdl.audlp_md2g_pwd_handle);
         audlphdl.audlp_md2g_pwd_count = 0;
      }
//      else
//         ASSERT(KAL_FALSE);
      L1SM_EnterFPM(KAL_FALSE, 1);

      if((audlphdl.f_timer_enable) && (audlp_kal_timer != NULL))
      {
         audlphdl.f_timer_enable = false;
         kal_cancel_timer(audlp_kal_timer);
      }

      if(audlphdl.audlp_sleep_id)
      {
         audlphdl.f_sleep_disable = KAL_FALSE;
         L1SM_SleepEnable( audlphdl.audlp_sleep_id );
      }
   }
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   if(true_false)
   {
#if defined(__TINY_SYS__) 
      AP_BtSS_mode_block(SUSPEND, AP_BTSS_MODE_BLOCKER_AUDIO);
      AP_BtSS_mode_block(HIBERNATION, AP_BTSS_MODE_BLOCKER_AUDIO);  	
#endif
      L1SM_EnterFPM(KAL_TRUE, 1);
   }
   else
   {
   	  L1SM_EnterFPM(KAL_FALSE, 1);
#if defined(__TINY_SYS__)  
      AP_BtSS_mode_unblock(SUSPEND, AP_BTSS_MODE_BLOCKER_AUDIO);
      AP_BtSS_mode_unblock(HIBERNATION, AP_BTSS_MODE_BLOCKER_AUDIO);
#endif   	 
   }
#else

#error : please choose correct chip compile option

#endif //(defined(MT6256_S01) || defined(MT6255))
   return 0;
}


void AUDLP_SetPCMPlay_LargerBuffer(kal_bool true_false)
{
   kal_uint16 dsp_flag;
   
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_PCMSETBUFFER, true_false);
   *AUDLP_D2M_COUNT  = 0;
   if(true_false)
   {
      kal_uint16 audlp_dsp_buffer_size;
      audlp_dsp_buffer_size = AUDIOLP_MCU_BUFFER_SIZE;
      if (audlp_dsp_buffer_size > (LOW_POWER_PCM_SINK_THRESHOLD>>1) )
         audlp_dsp_buffer_size = (LOW_POWER_PCM_SINK_THRESHOLD>>1);
      *AUDLP_MCUBUFF_SIZE = audlp_dsp_buffer_size;

      *AUDLP_MCUBUFF_THRESHOLD = audlphdl.audlp_mcu_buffer_threshold;

      dsp_flag = *DP2_AUDIO_ASP_COMMON_FLAG_1;
      dsp_flag |= (1<<AUD_BIT_COMFLG1_AUDLP_ENABLE);
#if defined(__CACHED_BASE_DSP__)
      if(!audlphdl.f_used_idma)
         dsp_flag |= (1<<AUD_BIT_COMFLG1_DSPMEM_NEED_CACHE_INVALID);
#endif
      *DP2_AUDIO_ASP_COMMON_FLAG_1 = dsp_flag;
   }
   else
   {
      *AUDLP_MCUBUFF_SIZE = 0;
      *AUDLP_MCUBUFF_THRESHOLD = 0;
      dsp_flag = *DP2_AUDIO_ASP_COMMON_FLAG_1;
      dsp_flag &= ~(1<<AUD_BIT_COMFLG1_AUDLP_ENABLE);
      dsp_flag &= ~(1<<AUD_BIT_COMFLG1_DSPMEM_NEED_CACHE_INVALID);
      *DP2_AUDIO_ASP_COMMON_FLAG_1 = dsp_flag;
   }
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void AUDLP_Init(void)
{
    kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_INIT);

    audlphdl.fAudLP_Enable = KAL_FALSE;
    audlphdl.audlp_mcu_buffer_threshold = AUDIOLP_MCU_BUFFER_THRESHOLD;

#if (defined(MT6256_S01) || defined(MT6255))
    audlphdl.audlp_md2g_pwd_handle = L1D_MD2G_PWD_GetHandle();
    audlphdl.audlp_sleep_id = L1SM_GetHandle();
    audlphdl.f_used_idma = KAL_TRUE;
    audlphdl.audlp_md2g_pwd_count = 0;
    audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_44K;
    audlphdl.f_sleep_disable = KAL_FALSE;
    if (audlp_kal_timer == NULL)
    {
        audlp_kal_timer = kal_create_timer("AUDLP_TIMER");
        audlphdl.f_timer_gethandle = true;
    }
#endif

}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

void AUDLP_SetDSPBufferThreshold_Short(kal_bool flag)
{
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_SETDSPBUFFER_SHORT, audlphdl.fAudLP_Enable, flag);
   if(audlphdl.fAudLP_Enable)
   {
      if(flag)
         *AUDLP_MCUBUFF_THRESHOLD = AUDIOLP_MCU_BUFFER_THRESHOLD_SHORT;
      else
         *AUDLP_MCUBUFF_THRESHOLD = audlphdl.audlp_mcu_buffer_threshold;
   }
}

void AUDLP_SetTimerPeriod(kal_uint32 SamplerateIndex)
{
#if (defined(MT6256_S01) || defined(MT6255))
   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_SET_SAMPLERATE, SamplerateIndex);
   switch(SamplerateIndex){
      case 48000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_48K;
         break;
      case 44100:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_44K;
         break;
      case 32000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_32K;
         break;
      case 24000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_24K;
         break;
      case 22050:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_22K;
         break;
      case 16000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_16K;
         break;
      case 12000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_12K;
         break;
      case 11025:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_11K;
         break;
      case 8000:
         audlphdl.timer_period = AUDIOLP_TIME_EXPIRE_WAKEUP_8K;
         break;
      default:
         break;  //when EOF will run to here
   }
#endif
}

void AUDLP_Time_Expire_function(void)
{
#if (defined(MT6256_S01) || defined(MT6255))
   kal_uint16 dsp_r_addr,dsp_w_addr,dsp_count;
   int dataleft;
   
   do {
      dsp_r_addr = (kal_uint16)*DSP_PCM_R;
   } while( dsp_r_addr != (kal_uint16)*DSP_PCM_R );
   dsp_w_addr = (kal_uint16)*DSP_PCM_W;
   
   dsp_count = (kal_uint16)*AUDLP_D2M_COUNT;
   dataleft  = (int)dsp_w_addr - (int)dsp_r_addr;
   if (dataleft < 0)
      dataleft += AUDIOLP_MCU_BUFFER_SIZE;

   if(audlphdl.audlp_sleep_id)
   {
      audlphdl.f_sleep_disable = KAL_TRUE;
      L1SM_SleepDisable( audlphdl.audlp_sleep_id );
   }

   kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_TIMEREXPIRE,dsp_r_addr,dsp_w_addr,dataleft,dsp_count,(int)audlphdl.f_sleep_disable);

   audlphdl.f_timer_enable = false;
   audlphdl.audlp_timer_count++;
#endif
}

void AUDLP_StartTimer(void)
{
#if (defined(MT6256_S01) || defined(MT6255))
   if((audlphdl.audlp_sleep_id != 0) && (audlphdl.f_sleep_disable))
   {
      audlphdl.f_sleep_disable = KAL_FALSE;
      L1SM_SleepEnable( audlphdl.audlp_sleep_id );
   }

   if(audlphdl.fAudLP_Enable)
   {

       //SGPT_CTRL_START_T gpt_start;
   	   if (audlphdl.f_timer_enable)
   	   {
   	      //DclSGPT_Control(audlphdl.audlp_gpt ,SGPT_CMD_STOP, 0);
   	      kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_STOPTIMER);
   	      kal_cancel_timer(audlp_kal_timer);
   	   }

       //gpt_start.u2Tick = AUDIOLP_TIME_EXPIRE_WAKEUP; 
       //gpt_start.pfCallback = AUDLP_Time_Expire_function;
       //gpt_start.vPara = 0;

       //GPTI_StartItem( audlphdl.audlp_gpt, AUDIOLP_TIME_EXPIRE_WAKEUP, AUDLP_Time_Expire_function, NULL );
       //DclSGPT_Control( audlphdl.audlp_gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&gpt_start);
       if(audlp_kal_timer != NULL)
       {
          kal_brief_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_V2_STARTTIMER,(int)audlphdl.f_sleep_disable);
          audlphdl.f_timer_enable = true;
          kal_set_timer(audlp_kal_timer, AUDLP_Time_Expire_function, NULL, audlphdl.timer_period, 0);
       }

       //kal_trace( TRACE_GROUP_AUDIOLP, L1AUDLP_STARTTIMER );
   }
   else
   {
   	  if((audlphdl.f_timer_enable) && (audlp_kal_timer != NULL))
   	  {
        audlphdl.f_timer_enable = false;
        //DclSGPT_Control(audlphdl.audlp_gpt ,SGPT_CMD_STOP, 0);
        kal_cancel_timer(audlp_kal_timer);
      }
   }
#endif
}

#endif // (__AUDIO_DSP_LOWPOWER_V2__)


