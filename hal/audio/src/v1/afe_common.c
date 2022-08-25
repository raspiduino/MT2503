/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * afe_common.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Front End common driver
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *******************************************************************************/

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#include "afe.h"
#include "l1audio.h"

#pragma arm section code="SECONDARY_ROCODE"
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Global Variables
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
AFE_STRUCT_T afe;

//=============================================================================================
//                  AFE Unit Test
//=============================================================================================
#if UNIT_TEST_AFE2
kal_uint16 digital_gain_ut[129];
float digital_gain_ut_diff[128];
kal_uint16 get_digital_gain(kal_int8 index)
{
   AFE_SetOutputVolume(0, 0, index);
   return afe.aud[0].digital_gain;
}
void afe2_unit_test( void )
{
   kal_int8 digital_gain_index;

   for(digital_gain_index=-128; digital_gain_index<=0; digital_gain_index++) {
      digital_gain_ut[digital_gain_index+128] = get_digital_gain(digital_gain_index);
   }

   /// python cmd: 20 * math.log10(0x8000/21.0) = 63.86dB
   ASSERT(digital_gain_ut[0] == 21);
   ASSERT(digital_gain_ut[128] == 0x8000);

   for(digital_gain_index=-128; digital_gain_index<=-1; digital_gain_index++) {
      digital_gain_ut_diff[digital_gain_index+128] =
         digital_gain_ut[digital_gain_index+128+1] * 1.0F /
         digital_gain_ut[digital_gain_index+128];
      /// perfect value is math.pow(10.0, 0.5/20.0) = 1.05925
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] >= 1.035F);
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] <= 1.084F);
   }

   /// shall assert here
   get_digital_gain(1);
}
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Internal Utility Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if __AFE_MD2G_PWDN_LOCK__

void _AFE_MD2GLockNum_Update(kal_bool inc)   //1: inc, 0: dec
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   
   if(inc)
      afe.md2glock_num++;
   else
      afe.md2glock_num--;
   
   RestoreIRQMask(savedMask);
}
void _AFE_SetAudioFlag(void)
{
//MT6260 has one HW bug when using CPD, should lock MCU sleep mode to force EPLL on, then DSP has clock
//but this will make AUDLP useless, so we still use SetFlag_MD2G, but make sure at this time, MCU is alive, or task will
//switch to 26Mhz
   if(!L1Audio_CheckFlag_MD2G(afe.aud_id))
      L1Audio_SetFlag_MD2G(afe.aud_id);
   kal_brief_trace(TRACE_STATE, AFE_SET_AUDIOFLAG, 1, afe.md2glock_num, afe.fgIdleOffTimerSet);
}

void _AFE_ClearAudioFlag(void)
{
   if( (!afe.fgIdleOffTimerSet)&& (afe.md2glock_num == 1) && (L1Audio_CheckFlag_MD2G(afe.aud_id)) ){
   #if __AFE_PA_DELAY_OFF__
      if(afe.pa_delay == -1)
   #endif
         L1Audio_ClearFlag_MD2G(afe.aud_id);
   }
   kal_brief_trace(TRACE_STATE, AFE_SET_AUDIOFLAG, 0, afe.md2glock_num);
}

#endif


/* ========================================================================= */
/*   AFE Event Handler                                                  */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
static void AFE_Event_Handler( void *data )
{
   ASSERT(!kal_if_hisr());
   
#if __AFE_MD2G_PWDN_LOCK__
   _AFE_SetAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_TRUE);
#endif
   AFE_Chip_Event_Handler(data);
#if __AFE_MD2G_PWDN_LOCK__
   afe.md2glock_checking = KAL_TRUE;
   _AFE_ClearAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_FALSE);
   afe.md2glock_checking = KAL_FALSE;
#endif
#if __CTIRQ_SLEEP_PLATFORM__
   if( (!kal_get_remaining_time(afe.timer)) )
   {
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);
   }
#endif
}

#if __CTIRQ_SLEEP_PLATFORM__
void AFE_Timer_Handler( void *data)
{
   AFE_Manager();
}
#endif

void AFE_Init_status(kal_bool flag)
{
   afe.afe_init = flag;
}

//=============================================================================================
//                  AFE Init
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_Init
* DESCRIPTION
*   This function is to initialize the AFE module.
*
* PARAMETERS
*  None
* RETURNS
*  None
* CALLER
*  L1Audio_Task, L1Audio_ResetDevice
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Init( void )
{
   static kal_bool afe_initialized = KAL_FALSE;
   int I;

   RB_INIT( afe.regq );

   afe.refresh          = KAL_FALSE;
   afe.mic_src          = 0;
   afe.sidetone_volume  = 127;
   afe.sp_flag          = 0;
   afe.fir_flag         = 0;
   afe.mic_flag         = 0;
   afe.mic_volume       = 7;
   afe.mic_mute         = KAL_FALSE;
   afe.sidetone_disable = KAL_FALSE;
   afe.accessory_flag   = KAL_FALSE;
   afe.ext_op_on        = KAL_FALSE;
   afe.ext_op_delay     = 0;
   afe.mute             = KAL_FALSE;
   afe.loopback         = KAL_FALSE;
   afe.agc_reset_flag   = KAL_FALSE;
#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_HARDWARE_AGC__)
   afe.agc_flag         = KAL_FALSE;
#else
   afe.agc_flag         = KAL_TRUE;
#endif
   afe.bt_flag          = KAL_FALSE;
   afe.audio_fs         = 0;  //32K
#if __AFE_PA_DELAY_OFF__
   afe.pa_delay         = 0;
#endif

#if defined(EXT_DAC_SUPPORT)
   afe.ext_dac_i2s_on   = KAL_FALSE;
   afe.ext_dac_add_st   = KAL_FALSE;
   afe.ext_dac_aud_func = -1;
   afe.ext_dac_level_gain  = 0x8000;
   EXT_DAC_Init();   
#endif       
   for( I = 0; I < L1SP_MAX_AUDIO; I++ ) {
      afe.aud[I].out_dev      = 0;
      afe.aud[I].volume       = 0x77;
      afe.aud[I].digital_gain = 0x8000;  // (in 1.15 fixed-point) 0 dB
      afe.aud[I].digital_gain_index = 0;
      afe.aud[I].digital_gain_level = 100;
      afe.aud[I].mute         = KAL_FALSE;
#if defined(__GAIN_TABLE_SUPPORT__)
      afe.aud[I].total_gain   = 0;
#endif
   }
#if defined(__GAIN_TABLE_SUPPORT__)
   afe.mic_total_gain = 0x0;
   afe.dual_path_loud_spk_gain = 0x0;
#endif

#if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__) 
   //afe.a_spk_pre = KAL_FALSE;
   //afe.a_spk = KAL_FALSE;
   afe.dcl_aux_handle = DclAUX_Open(DCL_AUX,FLAGS_NONE);
   afe.aux_Audio_on = KAL_FALSE;
#endif

   afe.audioplay                 = KAL_FALSE;
   afe.fastramp                  = KAL_FALSE;
   afe.aClk_on_request           = KAL_FALSE;
   afe.afe_state                 = AFE_STATE_OFF;
   afe.afe_hw_mute               = KAL_FALSE;
   afe.afe_event_handler_hw_mute = KAL_FALSE;
   afe.afe_audio_clk_hw_mute     = KAL_FALSE;
   afe.dis_idleOff_delay         = KAL_FALSE;
   afe.v8k_off_request           = KAL_FALSE;
   afe.aClk_off_request          = KAL_FALSE;
   afe.toneLoopbackRec           = KAL_FALSE;

#if __AFE_AudVoice_SingleClkSrc__
   afe.audio_clk_ena = KAL_FALSE;
   afe.voice_clk_ena = KAL_FALSE;
#endif
   afe.audio_dl_ena    = KAL_FALSE;
   afe.voice_dl_ena    = KAL_FALSE;
   afe.system_poweroff = KAL_FALSE;
   if (KAL_FALSE == afe_initialized) {
      afe.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( afe.aud_id, AFE_Event_Handler );
      afe_initialized = KAL_TRUE;      
   }
#if __CTIRQ_SLEEP_PLATFORM__
   afe.timer = kal_create_timer("AFE");
#endif

#if __AFE_MD2G_PWDN_LOCK__
   afe.md2glock_num = 0;
   afe.md2glock_checking = KAL_FALSE;
   //_AFE_SetAudioFlag();
#endif

#if UNIT_TEST_AFE2
   {
      afe2_unit_test();
   }
#endif

#if (__AFE_KARAOK_SUPPORT__)
   afe.KaraokMode = KAL_FALSE;
#endif

#if defined(__DATA_CARD_SPEECH__)
   *VAUDN_CON0 &= ~0x1;
   *VAUDP_CON0 &= ~0x1;
   *VAUDP_CON2 &= ~0x100;
   *VAUDP_CON1 = 0x0000;
#endif
#ifdef __VIBRATION_SPEAKER_SUPPORT__
   afe.vibrate = KAL_TRUE;
#endif
   
#if (__AFE_AUDIO_DELAY_OFF__)
   afe.Audio_gpt_init = KAL_FALSE;
   if(!afe.Audio_gpt_init)
   {
      afe.Audio_gpt  = DclSGPT_Open( DCL_GPT_CB, 0);
      afe.Audio_gpt_init = KAL_TRUE;
   }
   afe.Audio_gpt_on      = KAL_FALSE;
   afe.Audio_close_delay = 0;
   afe.AUDIOCLOSEDELAY   = AUDIO_CLOSE_DELAY;
   afe.fgIdleOffTimerSet = KAL_FALSE;
#endif

   afe.Audio_close_delay_expired = KAL_FALSE;
   afe.Pre_OutDev = 0;
   afe.Pre_aFunc  = -1;
#if HW_MUTE_SUPPORT_PLATFORM
   afe.hw_mute_sleep = true;
#endif
   AFE_Chip_Init();
#if (__AFE_HW_PREDIST__)
   *AFE_AMCU_CON2 |= HW_PREDIST_ENBIT;
   *AFE_AMCU_CON3 = 0x0FE9;
#endif

   afe.pDC_Calibration_CallBack = NULL;
#if __AFE_MULTIEPLE_DIE__
   afe.die2die_status = AFE_DIE2DIE_NONE;
#endif
#if defined(__CLASSK_CP_SUPPORT__)
   afe.cp_state     = CP_STATE_OFF;
   afe.cp_disable = 0;
   afe.spk_vol      = 0x77;
   afe.cp_th_high   = KAL_FALSE;
#if __AFE_CLASSK_SUPPORT_INTERNAL__
   //#if defined(MT6260)
   EINT_Set_HW_Debounce(THERMAL_EINT, 3);
   EINT_Registration(THERMAL_EINT, KAL_FALSE, KAL_FALSE, AFE_Force_Turnoff_CP, KAL_TRUE ); //auto unmask
   //#endif
#endif   
#endif
#if (__AFE_ENABLE_HW_AGC__)
   AFE_TurnOffAGC();
#endif
#if __AFE_MD2G_PWDN_LOCK__
   //_AFE_ClearAudioFlag();
#endif
}


void AFE_Set_AudPlay_Flag(bool enable)
{
   if(enable)
      afe.audioplay = KAL_TRUE;
   else
      afe.audioplay = KAL_FALSE;
}

void AFE_AUDIO_BUF_PDN(void)
{
//   *AFE_AAPDN_CON = *AFE_AAPDN_CON & (~AAPDN_MASK);
}

kal_uint8 AFE_GetAfeSate(void)
{
   return afe.afe_state;
}

void SearchSpkFlag( kal_int16 *v_lowest, kal_int16 *a_lowest )
{
   kal_int16 I, val;
   
   if(afe.mute)
   {
      *v_lowest = -1; 
      *a_lowest = -1;  
      return;
   }   
   
   for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
      if( afe.sp_flag & (1<<I) ) {
         val = (kal_uint16)afe.aud[I].out_dev;
         if( val & (L1SP_BUFFER_0|L1SP_BUFFER_1) )
            *v_lowest = I;
         if( val & L1SP_BUFFER_ST )
            *a_lowest = I;
      }
   }
   
   // move _update_digital_gain here for APM 
   _update_digital_gain(*v_lowest, *a_lowest); 
   
   if( *a_lowest >= 0 )
   {
      if( afe.aud[*a_lowest].volume == 0 || afe.aud[*a_lowest].mute == KAL_TRUE )
      {
         *a_lowest = -1;
         if(!DTMF_MCU_IsPlaying())
         {
            PcmSink_SetGain(0);
         }
         *DP_VOL_OUT_PCM = 0; 
      }
   }
   if( *v_lowest >= 0 )
      if( afe.aud[*v_lowest].volume == 0 || afe.aud[*v_lowest].mute == KAL_TRUE )
         *v_lowest = -1;
   if (!kal_if_lisr())
      kal_trace(TRACE_STATE, AFE_DIGI_GAIN, *DP_VOL_OUT_PCM, PcmSink_GetGain());
}

void AFE_SetRefresh( void )
{
   afe.refresh = KAL_TRUE;
#if __CTIRQ_SLEEP_PLATFORM__
   if (kal_if_lisr())
      L1Audio_LSetEvent(afe.aud_id, NULL);
   else
      L1Audio_SetEvent(afe.aud_id, NULL);
#endif
}

void AFE_DELAY(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Digital/Analog Gain Related
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [Gain] Digital Gain Convert
//=============================================================================================

/// the value of the table is in 1.15 fixed-point
/// -64 dB = 20 log x => x = math.pow(10.0, -64.0/20) * 0x8000
static const kal_uint16 digital_gain_8db_table[8] = {
     21, /// -64 dB
     52, /// -56 dB
    130, /// -48 dB
    328, /// -40 dB
    823, /// -32 dB
   2068, /// -24 dB
   5193, /// -16 dB
  13045  ///  -8 dB
};

/// the value of the table is in 1.14 fixed-point
/// 0.5 dB = 20 log x => x = math.pow(10.0, 0.5/20) * 0x4000
static const kal_uint16 digital_gain_halfdb_table[15] = {
  17355, /// 0.5 dB
  18383, /// 1.0 dB
  19472, /// 1.5 dB
  20626, /// 2.0 dB
  21848, /// 2.5 dB
  23143, /// 3.0 dB
  24514, /// 3.5 dB
  25967, /// 4.0 dB
  27506, /// 4.5 dB
  29135, /// 5.0 dB
  30862, /// 5.5 dB
  32690, /// 6.0 dB
  34627, /// 6.5 dB
  36679, /// 7.0 dB
  38853  /// 7.5 dB
};

#if defined(__GAIN_TABLE_SUPPORT__)
static const kal_uint16 digital_gain_4db_table[17] = 
{
   32767,   /* 0     dB */
   20675,   /* -4    dB */
   13044,   /* -8    dB */
   8231,    /* -12   dB */
   5193,    /* -16   dB */
   3277,    /* -20   dB */
   2068,    /* -24   dB */
   1305 ,   /* -28   dB */
   823,     /* -32   dB */
   519,     /* -36   dB */
   328,     /* -40   dB */
   207,     /* -44   dB */
   130,     /* -48   dB */
   82,      /* -52   dB */
   52,      /* -56   dB */
   33,      /* -60   dB */
   21       /* -64   dB */
};
#endif

/// digital_gain_index: 0:0dB, -1:-0.5dB, ..., -128:-64dB
const kal_uint16 digital_gain_table[17] = 
{
   32767,   /* 0     dB */
   31838,   /* -0.25 dB */
   30934,   /* -0.5  dB */
   30057,   /* -0.75 dB */
   29204,   /* -1    dB */
   28375,   /* -1.25 dB */
   27570,   /* -1.5  dB */
   26788,   /* -1.75 dB */
   26028,   /* -2    dB */
   25290,   /* -2.25 dB */
   24572,   /* -2.5  dB */
   23875,   /* -2.75 dB */
   23197,   /* -3    dB */
   22539,   /* -3.25 dB */
   21900,   /* -3.5  dB */
   21278,   /* -3.75 dB */
   20675    /* -4    dB */
};

kal_uint16 _converted_digital_gain(kal_int8 digital_gain_index)
{
   kal_int8 converted_gain_index;
   kal_uint16 digital_gain; /// 1.15 fixed-point
   
   /// Uncomment the following to make sure MMI code is ready.
   ///ASSERT(digital_gain_index <= 0);
   converted_gain_index = digital_gain_index;
   if (0 == converted_gain_index) {
      digital_gain = 0x8000; /// 0 dB, special case
   } else {
      converted_gain_index = digital_gain_index + 128;
      /// Uncomment the following to make sure MMI code is ready.
      ///ASSERT(converted_gain_index >= 0);
      /// converted_gain_index: 0:-64dB, 1:-63.5dB, 127:-0.5dB
      digital_gain = digital_gain_8db_table[converted_gain_index>>4];
      if ((converted_gain_index&0x0F) > 0) {
         digital_gain = ((kal_uint32)digital_gain * digital_gain_halfdb_table[(converted_gain_index&0x0F)-1]) >> 14;
      }
   }
   return digital_gain;      
}

#if defined(__CLASSAB_VOLUME_PROTECTION__)
static kal_uint16 AFE_lowBatteryGainConvert(kal_uint8 aud_func, kal_uint16 org_vol)
{
   if(0==afe.spk_driver_mode)
      return org_vol;

   if((afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) && afe.low_battery )
      return (org_vol > MAX_PGA_GAIN_LOW_BAT) ? MAX_PGA_GAIN_LOW_BAT : org_vol;
   else
      return org_vol;
}
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
static kal_uint16 AFE_Vibr_AGainRangeConvert(kal_uint16 org_vol)
{
#if __AFE_ANALOG_GAIN_UPPER_BOUND__
   return (org_vol > MAX_PGA_GAIN << 1) ? MAX_PGA_GAIN << 1 : org_vol;
#else
   return org_vol;
#endif
}
#endif

static void _update_digital_gain_imp(kal_int16 aud_func)
{
   kal_uint16 digital_gain = afe.aud[aud_func].digital_gain;
   kal_uint32 level_gain;

   level_gain = ((uint32)afe.aud[aud_func].digital_gain_level * 0x8000) / 100;
   switch (aud_func) {
      case L1SP_KEYTONE:
      case L1SP_TONE:
         if(DTMF_MCU_IsPlaying()) //MCU DTMF
         {
            if( (afe.aud[aud_func].mute == KAL_TRUE) || (afe.aud[aud_func].volume == 0) )
               PcmSink_SetGain(0);
            else
               PcmSink_SetGain(((((kal_uint32)DG_DAF * digital_gain) >> 15) * level_gain) >> 15);
            break;
         }
      /// Speech
      case L1SP_SPEECH:
      case L1SP_SND_EFFECT:
      case L1SP_VOICE:
      #if (defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST) ) 
          return;
      #endif          	
      #if __AFE_AudVoice_SingleClkSrc__
         if( AM_IsAudioPlaybackOn() != -1 )
         {
            if( (afe.aud[aud_func].mute == KAL_TRUE) || (afe.aud[aud_func].volume == 0) )
               PcmSink_SetGain(0);
            else
               PcmSink_SetGain(((((kal_uint32)DG_DAF * digital_gain) >> 15) * level_gain) >> 15);
         }
         else
      #endif
         {
            if( (afe.aud[aud_func].mute == KAL_TRUE) || (afe.aud[aud_func].volume == 0) )
            {
               *DP_VOL_OUT_PCM = 0;
            }
            else
            {
               *DP_VOL_OUT_PCM = ((((kal_uint32)DG_DL_Speech * digital_gain) >> 15) * level_gain) >> 15;
            }
         }
         break;
      case L1SP_AUDIO:   // Audio (DAF, AAC, WMA, WAV), MIDI, multi-channel wave, tone
         {
            kal_uint16 dsp_gain;
            if( afe.aud[aud_func].mute == KAL_TRUE )
               dsp_gain = 0;
            else
            {
            #ifdef __VIBRATION_SPEAKER_SUPPORT__
               if(afe.vibrate)
               if( afe.vibrate&& (afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) )
               {
                  kal_uint16 amp_gain, new_amp_gain;
                  kal_uint16 new_digi_gain;
                  amp_gain = afe.aud[aud_func].volume>>3;
                  amp_gain = AFE_Vibr_AGainRangeConvert(amp_gain);
                  VIBR_Vibration_GetNewGain(afe.class_d_gain, amp_gain, &new_amp_gain, &new_digi_gain);
                  digital_gain = (((kal_uint32)afe.aud[aud_func].digital_gain) * new_digi_gain)>>15;
                  afe.vib_ampgain = new_amp_gain;
               }
            #endif
               dsp_gain = ((((kal_uint32) DG_DAF * digital_gain) >> 15) * level_gain) >> 15;
            }
            PcmSink_SetGain(dsp_gain);
         }
         break;
      case L1SP_DAI:   // not really an audio function
         break;
      
      case L1SP_LINEIN:   // can't apply digital gain
         break;
      default:
         ASSERT(0);
   }
}


static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest)
{
#if defined(__BT_SUPPORT__)
   if(AM_IsBluetoothOn()) // for the case of bluetooth use
   {
      if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
         PcmSink_SetGain(0);
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
         kal_uint32 level_gain;

         level_gain = ((uint32)afe.aud[L1SP_AUDIO].digital_gain_level * 0x8000) / 100;
         PcmSink_SetGain(((((kal_uint32) DG_DAF * afe.aud[L1SP_AUDIO].digital_gain) >> 15) * level_gain) >> 15);
      #else
         PcmSink_SetGain(AFE_GetAudioDigiGain(KAL_FALSE));
      #endif
      }
      if( afe.aud[L1SP_VOICE].mute == KAL_TRUE || afe.aud[L1SP_SPEECH].mute == KAL_TRUE )
         *DP_VOL_OUT_PCM = 0;
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
         *DP_VOL_OUT_PCM = (((kal_uint32)DG_DL_Speech * afe.aud[L1SP_SPEECH].digital_gain) >> 15);
      #else
         #if !defined(__CVSD_CODEC_SUPPORT__) && !defined(__PCM_INTERFACE_SUPPORT__)
         *DP_VOL_OUT_PCM = default_bt_pcm_out_vol;
         #else
         *DP_VOL_OUT_PCM = 0x1400;  ////0x1000 is DL default setting 0dB
         #endif
      #endif
      }

      if( afe.aud[L1SP_LINEIN].mute == KAL_TRUE && AM_IsBTCordlessMode())
         *DP_VOL_IN_PCM = 0;
      else
         *DP_VOL_IN_PCM = DG_Microphone;
      return;
   }
#endif //defined(__BT_SUPPORT__)

   if (v_lowest >= 0) 
   {
      _update_digital_gain_imp(v_lowest);
      if(a_lowest >= 0 && a_lowest < v_lowest)
      {
         _update_digital_gain_imp(a_lowest);
      } 
   } 
   else if (a_lowest >= 0)   // Voice Amp OFF && Audio Amp ON
   {
      _update_digital_gain_imp(a_lowest);
   } 
   else  // Voice Amp OFF && Audio Amp OFF; Restore the values to default value (for Bluetooth)
   {
      *DP_VOL_OUT_PCM = DG_DL_Speech;
   #if defined(EXT_DAC_SUPPORT)
      if(afe.ext_dac_aud_func == -1)
   #endif
         PcmSink_SetGain(DG_DAF);
   }
}

//=============================================================================================
//                  Section: [Gain] Digital Gain Setting  (Set/Get/Mute)
//=============================================================================================
void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level )
{
   ASSERT(level<=100);
   kal_trace(TRACE_STATE, AFE_SET_GIDI_GAIN, aud_func, level);
#if defined(__BT_SUPPORT__)
   if(AM_IsBluetoothOn()) {
      /// for the case of bluetooth use 
      return;
   }
#endif
   afe.aud[aud_func].digital_gain_level = level;
#if defined(EXT_DAC_SUPPORT)
   if( aud_func == L1SP_AUDIO )
      afe.ext_dac_level_gain = ((kal_uint32)level * 0x8000) / 100;
#endif
   AFE_SetRefresh();
}

kal_uint16 AFE_GetDigiGain()
{
   kal_uint16 gain;
   
   if( AM_IsAudioPlaybackOn() != -1)
      gain = PcmSink_GetGain();
   else
   {
      gain = *DP_VOL_OUT_PCM;
      gain = ( gain >= 0x1000 )? 0x7FFF : (gain << 3);
   }
   return gain;
}

kal_uint16 AFE_GetAudioDigiGain( kal_bool isAPM)
{
   kal_uint32 level_gain;
   kal_uint16 digital_gain;
   
   if(isAPM)
   {
   #if defined(__BT_SUPPORT__)
      if(AM_IsBluetoothOn()) // for the case of bluetooth use
      {
         if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
            return 0;
         else
            return 0x7FFF;
      }
   #endif
   }
   
   digital_gain = afe.aud[L1SP_AUDIO].digital_gain;
   level_gain = ((uint32)afe.aud[L1SP_AUDIO].digital_gain_level * 0x8000) / 100;
   {
      kal_uint16 dsp_gain;
      if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
         dsp_gain = 0;
      else
      {
      #ifdef __VIBRATION_SPEAKER_SUPPORT__ 
         if(afe.vibrate)
         {
            kal_uint16 amp_gain, new_amp_gain;
            kal_uint16 new_digi_gain;
            amp_gain = afe.aud[L1SP_AUDIO].volume>>3;
            amp_gain = AFE_Vibr_AGainRangeConvert(amp_gain);
            VIBR_Vibration_GetNewGain(afe.class_d_gain, amp_gain, &new_amp_gain, &new_digi_gain);
            digital_gain = (((kal_uint32)afe.aud[L1SP_AUDIO].digital_gain) * new_digi_gain)>>15;
         }
      #endif
         dsp_gain = ((((kal_uint32) DG_DAF * digital_gain) >> 15) * level_gain) >> 15;
      }
      return dsp_gain;
   }
}

void AFE_SetDigitalMute( kal_bool mute )
{
   DelayCmd dc;
   
  dc.addr = AFE_AMCU_CON1;
   if(mute == KAL_TRUE) {
     dc.val = (*AFE_AMCU_CON1 & ~(0xC)) | (0xC);
   }
   else {
      dc.val = (*AFE_AMCU_CON1 & ~(0xC)) | (0x0);
   }
  RB_PUT( afe.regq, dc );
}

//=============================================================================================
//                  Section: [Gain] Analog Gain Related
//=============================================================================================
kal_uint16 AFE_AGainRangeConvert(kal_uint16 org_vol)
{
#if __AFE_ANALOG_GAIN_UPPER_BOUND__
   return (org_vol > MAX_PGA_GAIN) ? MAX_PGA_GAIN : org_vol;
#else
   return org_vol;
#endif
}

void AFE_SetGainFastRamp(kal_bool enable)
{
   afe.fastramp = enable;
}

void _AfeRampDownAudBuf(kal_uint16 u2RampTickCnt)
{ 
//   kal_int32 I;
//   kal_int16 i2Gain;
//   kal_uint16 OrgValue;
//
//   if (u2RampTickCnt == 0)
//   {
//   }
//    
//   i2Gain = (kal_int16)(*AFE_AAG_CON & 0xF);
//   OrgValue = *AFE_AAG_CON;
//    
//   for (I=i2Gain; I>=0; I--)
//   {
//      *AFE_AAG_CON = (I) | (I<<4) | (OrgValue & ~0xff);
//#if defined(__VIBRATION_SPEAKER_SUPPORT__)
//      VIBR_Vibration_UpdateGain(I, afe.class_d_gain);
//#endif
//      if(!afe.fastramp)
//         kal_sleep_task(u2RampTickCnt);
//      afe_prompt_trace( MOD_L1SP, "Buff gain ramp-down (%d) + delay (%d *4.6) ms ", I, u2RampTickCnt);
//   }
}

void UpdateAGainRampUp( kal_uint8 aud_func )
{
//   kal_int32 I;  
//   kal_int16 i2Gain;
//   kal_uint16 OrgValue;
//   const kal_uint16 vol = afe.aud[aud_func].volume;
//   kal_uint16 amp_gain = (vol>>4);
//   
//#if defined(__CLASSAB_VOLUME_PROTECTION__)
//   amp_gain = AFE_AGainRangeConvert(amp_gain);
//   amp_gain = AFE_lowBatteryGainConvert(aud_func, amp_gain);
//#endif
//   
//#ifdef __VIBRATION_SPEAKER_SUPPORT__
//   if(afe.vibrate)
//   {
//      kal_int16 new_digi_gain, new_amp_gain;
//      amp_gain = vol>>4;
//      amp_gain = AFE_AGainRangeConvert(amp_gain); //max 17db
//      VIBR_Vibration_GetNewGain(afe.class_d_gain, amp_gain, &new_amp_gain, &new_digi_gain);
//      amp_gain = new_amp_gain;
//   }
//#endif
//
//   i2Gain = (kal_int16)(*AFE_AAG_CON & 0xF);
//   OrgValue = *AFE_AAG_CON;
//
//   if (i2Gain < amp_gain)
//   {
//      for(I=i2Gain; I<=amp_gain ; I++)
//      {
//         *AFE_AAG_CON = (I) | (I<<4) | (OrgValue & ~0xff);
//      #if defined(__VIBRATION_SPEAKER_SUPPORT__)
//         VIBR_Vibration_UpdateGain(I, afe.class_d_gain);
//      #endif
//         kal_sleep_task(1);
//         afe_prompt_trace( MOD_L1SP, "Buff gain ramp-up (%d)", I);
//      }
//      if (I != amp_gain)
//      {
//         *AFE_AAG_CON = (amp_gain) | (amp_gain<<4) | (OrgValue & ~0xff);
//      #if defined(__VIBRATION_SPEAKER_SUPPORT__)
//         VIBR_Vibration_UpdateGain(amp_gain, afe.class_d_gain);
//      #endif
//         afe_prompt_trace( MOD_L1SP, "Buff gain ramp-up (%d)", I);
//      }
//
//   #if defined(__VIBRATION_SPEAKER_SUPPORT__)
//      VIBR_Vibration_UpdateGain(amp_gain, afe.class_d_gain);
//   #endif
//   }
//   if( (aud_func == L1SP_SPEECH) )
//      UpdateSidetone( (kal_int8)(vol >> 4) );
//   else
//      *DP_SIDETONE_VOL = 0;
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainInfo
* DESCRIPTION
*  Get PGA gain information
*
* PARAMETERS
*  eBuffer       - AFE buffer type
*  pi2MaxGain    - Maximum gain in dB (ex. 22 means +22dB)
*  pu2Step       - Gain step in dB (ex. 2 means +2dB)
*  pu2TotalLevel - Totoal gain level (ex. 16 means there are 16 levels could 
*                  be applied)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainInfo(AFE_BUFFER_T eBuffer, kal_int16 *pi2MaxGain, 
                        kal_uint16 *pu2Step, kal_uint16 *pu2TotalLevel)
{

    ASSERT((pi2MaxGain != NULL) && (pu2Step != NULL) || (pu2TotalLevel != NULL));
    ASSERT(eBuffer < AFE_BUFFER_MAX);
    
    switch(eBuffer)
    {
      case AFE_BUFFER_NONE:
         *pi2MaxGain    = 0;
         *pu2Step       = 0;
         *pu2TotalLevel = 0;
         break;
      case AFE_BUFFER_AUDIO:
         *pu2TotalLevel = AUDIO_BUFFER_TOTAL_LEVEL;
         *pi2MaxGain    = AUDIO_BUFFER_MAX_GAIN;
         *pu2Step       = AUDIO_BUFFER_STEP;
         break;
      case AFE_BUFFER_VOICE:
         *pu2TotalLevel = VOICE_BUFFER_TOTAL_LEVEL;
         *pi2MaxGain    = VOICE_BUFFER_MAX_GAIN;
         *pu2Step       = VOICE_BUFFER_STEP;
         break;
      case AFE_BUFFER_MIC:
         *pu2TotalLevel = MIC_TOTAL_LEVEL;
         *pi2MaxGain    = MIC_MAX_GAIN;
         *pu2Step       = MIC_STEP;
         break;
   
      default:
         break;
    }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc  - L1SP_KEYTONE/L1SP_TONE/L1SP_SPEECH/L1SP_SND_EFFECT/L1SP_AUDIO/..
*  ePhoneMode - Phone mode
*  epBuffer   - AFE buffer type
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPathUsage(kal_uint8 u1AudFunc, PHONE_MODE_T ePhoneMode, AFE_BUFFER_T *peBuffer)
{
    ASSERT(peBuffer != NULL);
    ASSERT(ePhoneMode < PHONE_MODE_MAX);

    {
        switch (ePhoneMode)
        {
        case PHONE_MODE_HANDSET:
            if (L1SP_SPEAKER1 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER1 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HEADSET:
            if (L1SP_SPEAKER2 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER2 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HANDFREE:
            if (L1SP_LOUD_SPEAKER & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_LOUD_SPEAKER & L1SP_BUFFER_ST)
            {
#if __AFE_VOICE_AMP_AS_LOUDSPK__
                *peBuffer =  AFE_BUFFER_VOICE;
#else
                *peBuffer =  AFE_BUFFER_AUDIO;
#endif
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_BT_EARPHONE:
            *peBuffer = AFE_BUFFER_NONE;
            break;
        default:
            break;

        }
    }
}


/*****************************************************************************
* FUNCTION
*  AFE_GetNVRAMDigitalGainSupport
* DESCRIPTION
*  This function return if support digital setting from NVRAM data
*
* PARAMETERS
*  None
* RETURNS
*  KAL_TRUE   - Support digital gain
*  KAL_FALSE  - Not support digital gain
* CALLER
*  Task
*****************************************************************************/
kal_bool AFE_GetNVRAMDigitalGainSupport(void)
{
#ifdef __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif
}

//=============================================================================================
//                  Section: [Gain] ClassAB Volume Protection
//=============================================================================================
#if defined(__CLASSAB_VOLUME_PROTECTION__)
void AFE_EnableVolumeProtection(kal_bool enable)
{
   kal_uint32 savedMask;
   if(0==afe.spk_driver_mode) // 0: class-D, 1: class-AB
      return;
   
   savedMask = SaveAndSetIRQMask();   
   if(enable)
   {
      _AfeSetClassDGain(afe.class_ab_gain_low_battery); 
      afe.low_battery = KAL_TRUE;
   }
   else
   {
      _AfeSetClassDGain(afe.class_d_gain); 
      afe.low_battery = KAL_FALSE;
   }
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_VOLUME_PROTECT, enable);
}
#endif

//=============================================================================================
//                  Section: [Gain] Sidetone Gain Functions
//=============================================================================================
void AFE_SetSidetoneVolume( kal_uint8 sidetone_volume )
{
   afe.sidetone_volume   = sidetone_volume;

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_SIDETONE_VOLUME, sidetone_volume);
}

kal_uint8 AFE_GetSidetoneVolume( void )
{
   return afe.sidetone_volume;
}

//=============================================================================================
//                  Section: [Gain] __GAIN_TABLE_SUPPORT__ Specific Functions
//=============================================================================================
#if defined(__GAIN_TABLE_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputGainControl
* DESCRIPTION
*  This function set detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_SetOutputGainControl(uint8 aud_func, uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.aud[aud_func].total_gain = total_gain;
#if __AFE_ANALOG_GAIN_REVERSE_ORDER__
   afe.aud[aud_func].volume = (uint8)( (MINIMUM_AGAIN_SETTING - (total_gain >> 26)) << 2);
#else
   afe.aud[aud_func].volume = (uint8)((total_gain >> 26) << 4);// ( >>26 ) << 2  to be 8 bits, which fulfill afe.aud[aud_func].volume design
#endif
   gain_index = (kal_uint8)((total_gain << 6) >> 24);

#if __AFE_ANALOG_GAIN_LOWER_BOUND__
   { 
      kal_uint8 digital_gain_index;
      kal_uint8 volume;

      volume = afe.aud[aud_func].volume;
      digital_gain_index = gain_index;
       
      if(volume<AGAIN_LOWBOUND_SETTING) 
      { 
         kal_uint16 tmp_gain_index;
         tmp_gain_index = (kal_uint16)digital_gain_index;
         tmp_gain_index += (((AGAIN_LOWBOUND_SETTING-volume)>>2)<<2); //unit is 0.25db
   
         if(tmp_gain_index<256)
            digital_gain_index = (kal_uint8)tmp_gain_index;
         else
            digital_gain_index = 255;

         gain_index = digital_gain_index;
      }
   }
#endif
   
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   afe.aud[aud_func].digital_gain = digi_gain;
   afe_prompt_trace(MOD_L1SP, "afe set gain control func %d dev %x sp_flag %x",aud_func, afe.aud[aud_func].out_dev, afe.sp_flag);
   afe_prompt_trace(MOD_L1SP, "AFE set func %d gain_ctrl Ana %d Dig %d(%d) Ext %x", aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_GAIN_CONTROL, aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   AFE_SetRefresh();
}

/*****************************************************************************
* FUNCTION
*  AFE_SetMicGainControl
* DESCRIPTION
*  This function set detail gain value to mic :internal analog gain, digital gain, external device gain
*
* PARAMETERS
*  mic_gain  - containes analog gain[26:31], digital gain[18:25], external amp gain[0:17]
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_SetMicGainControl(uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.mic_total_gain = total_gain;
   afe.mic_volume = (uint8)(total_gain >> 26);

   gain_index = (kal_uint8)((total_gain << 6) >> 24);
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   *DP_VOL_IN_PCM = ( digi_gain * DG_Microphone ) >> 15;
   kal_trace(TRACE_STATE, AFE_SET_MIC_GAIN_CONTROL, total_gain >> 26, gain_index, digi_gain );
   AFE_SetRefresh();
}


/*****************************************************************************
* FUNCTION
*  AFE_GetAllPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc[in]  - AUD_VOLUME_CTN = 0, tone
*   AUD_VOLUME_KEY,              1: keytone 
*   AUD_VOLUME_MIC,              2: microphone 
*   AUD_VOLUME_FMR,              3: FM Radio 
*   AUD_VOLUME_SPH,              4: Speech 
*   AUD_VOLUME_SID,              5: Side-tone 
*   AUD_VOLUME_MEDIA,            6: Multi-Media 
*   AUD_VOLUME_TVO,              7: TV-OUT 
*
*  u1Path[in] -  AUD_PATH_RECEIVER,          -speaker
*                AUD_PATH_HEADSET,           -Headset
*                AUD_PATH_SPEAKER,           -Loudspeaker
*                AUD_DUAL                    -headset and loudspeaker
*
*  epBuffer[out]   - AFE buffer type
*  pu2TotalLevel[out] - total level number of epBuffer
*  digigain[out]   - true: support digital gain
*                    false: not support
*  ext_dac[out]    - NULL
*                    L1SP_EXT_DAC_BUF0
*                    L1SP_EXT_DAC_BUF1
*  ctrl_point[out] - numbers of control point of ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetAllPathUsage(aud_volume_enum u1AudFunc, aud_path_enum u1Path,
                        AFE_BUFFER_T *peBuffer, kal_uint16 *pu2TotalLevel,
                        kal_bool *digital_gain,
                        kal_uint8 *ext_dac, kal_uint16 *ctrl_point)
{
   if(u1AudFunc == AUD_VOLUME_SID){
      *peBuffer = AFE_BUFFER_NONE;
      *pu2TotalLevel = 0;
      *digital_gain = KAL_FALSE;
      *ctrl_point = 0;
      *ext_dac = 0;
      return;
   }
   switch (u1Path) {
      case AUD_PATH_RECEIVER:
         if(u1AudFunc == AUD_VOLUME_KEY || u1AudFunc == AUD_VOLUME_CTN || u1AudFunc == AUD_VOLUME_SPH){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;

         } else  if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
         }
         else{
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_FALSE;
         }
         *ext_dac = 0;
         *ctrl_point = 0;
         break;      

      case AUD_PATH_HEADSET:
      case AUD_PATH_DUAL:
      #if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
      #endif
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAIN_LEVEL;
#if defined(__FMRADIO_I2S_SUPPORT__)
            *digital_gain = KAL_TRUE;
#else
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
#endif
         #if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
         #else
            *ctrl_point = 0;
         #endif
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;              
      case AUD_PATH_SPEAKER:
      #if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH  || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
      #endif
         if(u1AudFunc != AUD_VOLUME_MIC){
#if __AFE_VOICE_AMP_AS_LOUDSPK__
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAIN_LEVEL;
#else
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAIN_LEVEL;
#endif
#if defined(__FMRADIO_I2S_SUPPORT__)
            *digital_gain = KAL_TRUE;
#else
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
#endif
      #if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
      #else
            _AfeGetExtAmpPathUsage(ctrl_point, ext_dac);
      #endif
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      case AUD_PATH_BT:
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;         
      case AUD_PATH_UNKNOWN:
         //only for FM microphone setting
         if(u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAIN_LEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      default:
         ASSERT(0);
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[out] - numbers of level of this ext_dac
*  bit_number[out]  - numbers of bits of this ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointBitLevel(ext_dac, ctrl_point, total_level, bit_number);
#else
   _AfeGetExtPgaInfo(ext_dac, ctrl_point, total_level, bit_number);
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[in]  - numbers of level of this ext_dac to be copied
*  gain_map[out]    - the array to store actual gain of this control_point, ex:gain_map[0]=-65, gain_map[1]=-55
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointGainMap(ext_dac, ctrl_point, gain_map);
#else
   _AfeGetExtPgaGainMap(ext_dac, ctrl_point, total_level, gain_map);
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainMap
* DESCRIPTION
*  This function is to get gain map of AFE buffer
*
* PARAMETERS
*  eBuffer[in] - AFE buffer type
*  u2TotalLevel[in] - numbers of level of this afe_buffer to be copied
*  gain_map[out]    - the array to store actual gain of AFE buffer
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainMap(AFE_BUFFER_T eBuffer, kal_uint16 u2TotalLevel, kal_int8 *pPGA_Map)
{
   kal_uint32 i = 0;
   switch (eBuffer) {
      case AFE_BUFFER_AUDIO:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = AFE_BUFFER_AUD_BASE_GAIN + i * AFE_BUFFER_AUD_GAIN_STEP;
         break;
      case AFE_BUFFER_VOICE:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = AFE_BUFFER_VOICE_BASE_GAIN + i * AFE_BUFFER_VOICE_GAIN_STEP;
         break;
      case AFE_BUFFER_MIC:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = AFE_BUFFER_MIC_BASE_GAIN + AFE_BUFFER_MIC_GAIN_STEP;
         break;
      default:
         break;
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetOutputGainControl
* DESCRIPTION
*  This function get detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
* RETURNS
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* CALLER
*  Task
*****************************************************************************/
kal_uint32 AFE_GetOutputGainControl(kal_uint8 aud_func)
{
   return afe.aud[aud_func].total_gain;
}

void AFE_SetOutputGainControlDualPath( kal_uint8 aud_func, kal_uint32 ext_amp_gain )
{
#if defined(LG_EXT_AMP_SUPPORT) 
   afe.dual_path_loud_spk_gain = (ext_amp_gain & 0x3FFFF);
   kal_trace(TRACE_STATE, AFE_SET_DUAL_PATH_GAIN, afe.dual_path_loud_spk_gain);
#endif
}

#endif // __GAIN_TABLE_SUPPORT__

//=============================================================================================
//                  Section: [Gain] HW Mute Control
//=============================================================================================

void _AfeSetHardwareMute(bool mute)
{
   afe.afe_event_handler_hw_mute = mute;
   _AfeHardwareMuteCtrl();
   afe_prompt_trace( MOD_L1SP, "_AfeSetHardwareMute (%d)", mute);
}

void _AfeAclkSetHardwareMute(bool mute)
{
   afe.afe_audio_clk_hw_mute = mute;
   _AfeHardwareMuteCtrl();
   
   if (!kal_if_lisr())
      kal_brief_trace(TRACE_STATE, AFE_ACLK_SET_HARDWARE_MUTE, mute);
}


void AFE_EnableHardwareMuteSleep(bool isEnable)
{
#if HW_MUTE_SUPPORT_PLATFORM
   afe.hw_mute_sleep = isEnable;
   kal_trace(TRACE_STATE, AFE_SWITCH_HW_MUTE_SLEEP, isEnable);
#endif //HW_MUTE_SUPPORT_PLATFORM
}

//=============================================================================================
//                  Section: [Gain] Device Gain (Mute/Output Volume)
//=============================================================================================
void AFE_SetMicrophoneVolume( kal_uint8 mic_volume )
{
#if __AFE_MIC_VOLUME_LOWER_BOUND__
   afe.mic_volume = ((mic_volume >> 2) > AFE_MICVOLUME_LOWBOUND) ? (mic_volume >> 2) : AFE_MICVOLUME_LOWBOUND; 
#else
   afe.mic_volume = mic_volume >> 2; /* Totally 6 bits for VUPG control */
#endif
   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_MIC_VOLUME, mic_volume);
}

kal_uint8 AFE_GetMicrophoneVolume( void )
{
   return afe.mic_volume << 2;  /* Totally 6 bits for VUPG control */
}

/*****************************************************************************
* FUNCTION
*  AFE_MuteMicrophone
* DESCRIPTION
*   This function is to mute the microphone.
*
* PARAMETERS
*  mute - true : mute ; false : unmute ¡@¡@
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_MuteMicrophone( kal_bool mute )
{
   afe.mic_mute = mute;
   AFE_SetRefresh();
}

kal_bool AFE_IsMicrophoneMuted( void )
{
   return afe.mic_mute;
}

/*****************************************************************************
* FUNCTION
*  AFE_Mute
* DESCRIPTION
*   This function is to mute both microphone and speaker.
*
* PARAMETERS
*  mute - true : mute ; false : unmute ¡@¡@
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Mute( kal_bool mute )
{
   afe.mute = mute;
   AFE_SetRefresh();
}

void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute )
{
   afe.aud[aud_func].mute = mute;
   kal_trace(TRACE_STATE, AFE_MUTE_SPEAKER, aud_func, mute);
   AFE_SetRefresh();
}

kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func)
{
   return afe.aud[aud_func].mute;
}

void  AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index )
{
   *volume1 = afe.aud[aud_func].volume;
   *digital_gain_index = afe.aud[aud_func].digital_gain_index;
}


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Path/Device Control
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                 Section: [Path] Speaker Functions
//=============================================================================================

/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOn
* DESCRIPTION
*   This function is to turn on the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOnSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */  
   afe.sp_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}

/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOff
* DESCRIPTION
*   This function is to turn off the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task, L1Audio_HISR(via AM_AudioPlaybackOff)
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOffSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */
   afe.sp_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}

void AFE_FastCloseSpk(void)
{
   afe.system_poweroff = KAL_TRUE;
#if (__AFE_AUDIO_DELAY_OFF__)
   afe.AUDIOCLOSEDELAY = 0;
#endif
}

//=============================================================================================
//                  Section: [Path] Microphone Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnMicrophoneOn
* DESCRIPTION
*   This function is to turn on the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOnMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    // Disable interrupt to prevent race condition
   afe.mic_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
#if defined(__DUAL_MIC_SUPPORT__)
   *DSP_DUALMIC_CTRL |= 1;
#endif
   afe.agc_reset_flag = KAL_TRUE;

   if(!afe.loopback)
     AFE_TurnOnAGC();

   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}

/*****************************************************************************
* FUNCTION
*  AFE_TurnOffMicrophone
* DESCRIPTION
*   This function is to turn off the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOffMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.mic_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   if(afe.mic_flag==0)
      AFE_TurnOffAGC();

   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}

kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.mic_flag & (1<<aud_func)) != 0);
}


void AFE_Mic_Init_Set(void)
{
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   {
      //main mic
      if(mic0_type_sel==0)	//acc
       *ABBA_VBITX_CON4 &= 0xA7FF;  
      else if(mic0_type_sel==1) //dcc mems
         *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xA7FF) | 0x4000;  
      else  //dcc ecm
         *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xA7FF) | 0x4800;   
      
      //ear-mic
      if(mic1_type_sel==0)	//acc
         *ABBA_VBITX_CON4 &= 0xD9FF; 
      else if(mic1_type_sel==1) //dcc mems  
      	 *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xD9FF) | 0x2000;  
      else //dcc ecm
         *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xD9FF) | 0x2400;  
   }
#endif	  
}


//=============================================================================================
//                  Section: [Path] BT Functions
//=============================================================================================
void AFE_TurnOnBluetooth( kal_uint16 param )
{
#if defined(__AUDIO_AT_CMD__)
   AFE_PCMIF_STRUCT_T pcmif;
#endif
    
   ASSERT( (*AFE_VDB_CON & 0x0020) == 0 );   /* To make sure that BT and DAI are not turned simultaneously */
   *AFE_VDB_CON    |= (0x0010 | param );
   afe.bt_flag = KAL_TRUE;

#if defined(__BT_SUPPORT__) || defined(__PCM_INTERFACE_SUPPORT__) || defined(__AUDIO_AT_CMD__)
   // Frame Sync
#if defined(__AUDIO_AT_CMD__)
   AFE_GetPCMBitClk(&pcmif);
   if (pcmif.VBTSYNC) {
#elif defined(__PCM_INTERFACE_SUPPORT__)
   if ( 0 ) { // 1:long sync, 0:short sync
#else   
   if ( !BtRadio_Get_PCM_ShortSync() ) {
#endif
      // Long Sync
      *AFE_VDB_CON |= 0x0008;
   }
   AFE_SetRefresh();
#endif //defined(__BT_SUPPORT__)
}

void AFE_TurnOffBluetooth( void )
{
   *AFE_VDB_CON    &= ~0x0018;
   afe.bt_flag = KAL_FALSE;
   {
      kal_int16 v_lowest = -1, a_lowest = -1;
      if( afe.sp_flag ){
         SearchSpkFlag( &v_lowest, &a_lowest );
      }
   }
   AFE_SetRefresh();
}

//=============================================================================================
//                  Section: [Path] DAI Related Functions
//=============================================================================================
void AFE_TurnOnDAI( void )
{
   *AFE_VDB_CON |= 0x0020;
   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(1) );
}

void AFE_TurnOffDAI( void )
{
   *AFE_VDB_CON &= ~0x0020;
   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(1) );
}

//=============================================================================================
//                  Section: [Path] External DAC Interface Related Functions
//=============================================================================================
/// External DAC Interface / fmt: 1 = I2S, 0 = EIAJ / cycle: 32 or 16
void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle )
{   
   kal_bool slave_mode = (kal_bool)Media_I2S_SLAVE_MODE;
   kal_uint16 en2 = 0;
   ASSERT( fmt < 2 );
   ASSERT( cycle == 16 || cycle == 32 );
   if(dir)
   {
      // DSP workaround for I2S HW issue, audio clock 8K->16K
      *AFE_VAM_SET &= ~0x07;
      *AFE_VAM_SET |= 0x02;
   #if defined(MT6255) || defined(MT6250) || defined(MT6260)   
      *AFE_VDB_CON &= ~0x0040;
   #endif   
   #if defined(__INTERAL_FM_VIA_I2S__)
      if(I2S_is_FM())
      {
      #if defined(MT6250)
         slave_mode = KAL_FALSE;
      #else
         slave_mode = KAL_TRUE;
      #endif
         if(*AFE_EDI_CON & 0x0001)
            en2 = 1;
      }
   #endif
   #if __AFE_I2S_FOC_SUPPORT__
      if(slave_mode)
      {
         *AFE_FOC_CON  = 0x5A06;
         *AFE_FOC_CON |= 0x0001;
      }
   #endif
   }
   else
   {
   #if defined(MT6255) || defined(MT6250) || defined(MT6260)
      *AFE_VDB_CON |= 0x0040;
   #endif
   #if defined(__INTERAL_FM_VIA_I2S__)
      if(I2S_is_FM())
      {  //FM i2s in, i2s out;
      #if defined(MT6250)
         slave_mode = KAL_FALSE;
      #else
         slave_mode = KAL_TRUE;
      #endif
         dir = 1;
         en2 = 1;
      }
   #endif
   }
   *AFE_EDI_CON = ( (en2<<15) | (dir<<8) | (slave_mode<<7) | ((cycle-1)<<2) | (fmt<<1) | 1);
   kal_trace( TRACE_STATE, AFE_SET_EDI, dir, cycle, fmt );
}

void AFE_TurnOffEDI( void )
{
   *AFE_EDI_CON &= ~0x8001;
#if defined(MT6255) || defined(MT6250) || defined(MT6260)   
   *AFE_VDB_CON &= ~0x0040;
#endif
#if __AFE_EDI_DATA_SELECT__
   *AFE_AMCU_CON2  &= ~0x40;
#endif
#if __AFE_I2S_FOC_SUPPORT__
      *AFE_FOC_CON = 0;
#endif
   // DSP workaround for I2S HW issue, audio clock 16K->8K
   *AFE_VAM_SET &= ~0x07;
   *AFE_VAM_SET |= 0x05;
}

kal_bool AFE_IsEDIOn( void )
{
#if defined(MT6255) || defined(MT6250) || defined(MT6260)  	
   if (*AFE_VDB_CON & 0x0040)
#else
   if (*AFE_EDI_CON & 0x8000)
#endif   	
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

//=============================================================================================
//                  Section: [Path] MicBias Functions (for accessory detection use)
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnMicBias , AFE_TurnOffMicBias
*       : Add for accessory detection use
* CALLER
*  AUX_EINT_HISR
*****************************************************************************/
kal_uint8 AFE_TurnOnMicBias( void )
{
   kal_uint32 savedMask;
   if( afe.accessory_flag == KAL_TRUE )
      return 0;
#if __AFE_MD2G_PWDN_LOCK__
   _AFE_SetAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_TRUE);
#endif      
   afe.accessory_flag = KAL_TRUE;
   savedMask = SaveAndSetIRQMask();
#if __AFE_2ndG_DC_COUPLE__
   *VOICE_CON3 |= 0x10;
#elif __AFE_MULTIEPLE_DIE__
   *ABBA_VOICE_CON3 |= 0x20;
#elif defined(MT6261) || defined(MT2501) ||  defined(MT2502)
   *ABBA_VBITX_CON4 |= (RG_VPWDB_MBIAS);
#else
   *AFE_VAPDN_CON |= 0x20;
#endif //__AFE_2ndG_DC_COUPLE__
   RestoreIRQMask(savedMask);

#if __AFE_MD2G_PWDN_LOCK__
   _AFE_ClearAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_FALSE);
#endif
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(4) );

   return (afe.mic_src==L1SP_LNA_1);
}

void AFE_TurnOffMicBias(void)
{
   if( afe.accessory_flag == KAL_FALSE )
      return;
   
   afe.accessory_flag = KAL_FALSE;
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(4) );
}

//=============================================================================================
//                  Section: [Path] Input/Output Source/Device Related
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputDevice
* DESCRIPTION
*   This function is to set the output device of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
*  device - be L1SP_SPEAKER1, L1SP_SPEAKER2, or L1SP_LOUDSPEAKER
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device )
{
#if defined(EXT_DAC_SUPPORT)   
   if(device & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1))
   {
      if(!(device & L1SP_BUFFER_ST))
      {
         switch((SND_SRC_MAP>>aud_func*2)&3) 
         { 
            case SRC_AUDIO_DAC:
               afe.ext_dac_add_st = KAL_TRUE;
            case SRC_VOICE_DAC:   
            case SRC_EXT_INPUT:
               device |= L1SP_BUFFER_ST;
               break;
         }
      }
      else
         afe.ext_dac_add_st = KAL_FALSE;
   }
#endif

#if __AFE_KARAOK_SUPPORT__
#if defined(MT6255) || defined(MT6250) || defined(MT6260)
   if(AFE_IsKaraok())
   {
      if( (aud_func == L1SP_AUDIO) && (device == L1SP_BUFFER_ST) )
         device |= L1SP_STEREO2MONO;
   }
#endif
#endif

   afe.aud[aud_func].out_dev = device;   
   AFE_SetRefresh();
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_DEVICE, aud_func, device);
}

kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func )
{
   return afe.aud[aud_func].out_dev;
}

void AFE_SetInputSource( kal_uint8 src )
{
#if __AFE_DIGITAL_MIC_SUPPORT__
   if( src == L1SP_LNA_0 && L1SP_MICROPHONE1 == L1SP_LNA_DIGITAL )
      src = L1SP_LNA_DIGITAL;
#endif
   afe.mic_src = src;
   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_INPUT_SRC, src);
}

kal_uint8 AFE_GetInputSource( void )
{
   return afe.mic_src;
}

kal_bool AFE_IsAudioLoudSpk( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT)
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}

kal_bool AFE_IsAudioEarphone( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_ST) //earphone
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Audio/Speech Rleated Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [AUD/SPH] FIR Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnFIR
* DESCRIPTION
*   This function is to turn on the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOnFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '+', aud_func);
}

/*****************************************************************************
* FUNCTION
*  AFE_TurnFirOff
* DESCRIPTION
*   This function is to turn off the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_TurnOffFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '-', aud_func);
}

kal_bool AFE_IsFIROn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.fir_flag & (1<<aud_func)) != 0);
}

//=============================================================================================
//                  Section: [AUD/SPH] Side Tone Functions
//=============================================================================================
void AFE_SetSidetone( kal_bool ec )
{
   afe.sidetone_disable = (kal_bool)(ec == KAL_FALSE);
   AFE_SetRefresh();
}

//=============================================================================================
//                  Section: [AUD/SPH] AGC (for speech) Functions
//=============================================================================================
void AFE_TurnOnAGC(void)
{
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
    return;
#else	
   *AFE_VAGC_CON0 = *AFE_VAGC_CON0 | AGC_CTRL_ENABLE;
   *AFE_VAGC_CON1 = *AFE_VAGC_CON1 | AGC_COMP_ENABLE;

#if defined(__DUAL_MIC_SUPPORT__)
   *AFE_VAGC2_CON0 = *AFE_VAGC2_CON0 | AGC_CTRL_ENABLE;
   *AFE_VAGC2_CON1 = *AFE_VAGC2_CON1 | AGC_COMP_ENABLE;
#endif
   afe.agc_flag = KAL_TRUE;
#endif
}

void AFE_TurnOffAGC(void)
{
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
    return;
#else		
   *AFE_VAGC_CON0 = *AFE_VAGC_CON0 & ~AGC_CTRL_ENABLE;
   *AFE_VAGC_CON1 = *AFE_VAGC_CON1 & ~AGC_COMP_ENABLE;
#if defined(__DUAL_MIC_SUPPORT__)
   *AFE_VAGC2_CON0 = *AFE_VAGC2_CON0 & ~AGC_CTRL_ENABLE;
   *AFE_VAGC2_CON1 = *AFE_VAGC2_CON1 & ~AGC_COMP_ENABLE;
#endif
   afe.agc_flag = KAL_FALSE;
#endif   
}

kal_bool AFE_IsAGCOn(void)
{
   return afe.agc_flag;
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: AFE Related Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if !__AFE_CURRENT_SENSOR_ENABLE__
void AFE_Retrieve_VIB_CF_Data(kal_int32 data)
{  
}
#endif

//=============================================================================================
//                 Section: [AFE Feature] DC Calibration Functions
//=============================================================================================
#if __AFE_HW_DC_COMPENSATION__
void AFE_Retrieve_DC_Cali_Data(kal_int32 data)
{  
   kal_trace(TRACE_INFO, AFE_RETREIVE_DC_CALI_ADC_VALUE, (kal_int16)data);
   afe.retrieved_dc_data = (kal_int16)data;
   afe.dc_cali_wait = KAL_FALSE;
}


void AFE_DC_Calibration_Register_Callback( void(*DC_Calibration_CallBack2)(kal_uint32 msg_name, void *data))
{
   afe.dc_cali_new_callback = KAL_TRUE;
}

#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void AFE_DC_Calibration_In_Initial(void)
{
#if __AFE_HW_DC_COMPENSATION__
   kal_uint16 dc_temp;
   nvram_external_read_data(NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 1, &dc_temp, sizeof(kal_uint16));
   AFE_Chip_Init();
   afe.DC_OFFSET = afe.Pre_DC_OFFSET = dc_temp;
   DC_Calibration();
#endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

void AFE_DC_Calibration(kal_uint16* pwdc_offset, void(*DC_Calibration_CallBack)(kal_uint16 *pwdc_offset))
{
#if __AFE_HW_DC_COMPENSATION__
   afe.pDC_Calibration_CallBack = DC_Calibration_CallBack;

   if(stack_query_boot_mode() != FACTORY_BOOT) 
   {
      kal_brief_trace(TRACE_STATE, AFE_DC_CALIBRATION,afe.DC_OFFSET, (kal_int16)(*pwdc_offset));
   #if defined(EXT_DAC_SUPPORT)
      afe.dc_calibrate_finish = KAL_TRUE;
      AFE_SetRefresh(); 
   #else
      if( afe.dc_calibrate_finish == KAL_TRUE ){
         //already finish in AFE_DC_Calibration_In_Initial
         AFE_DC_Calibration_WriteBack();
      } else 
         afe.dc_calibrate_finish = KAL_TRUE;
      
   #endif
   }
#endif  //__AFE_HW_DC_COMPENSATION__
}

//=============================================================================================
//                 Section: [AFE Feature] Karaoke
//=============================================================================================
void AFE_SetKaraoke(kal_bool enable) 
{
#if __AFE_KARAOK_SUPPORT__

#if defined(MT6255) || defined(MT6250) || defined(MT6260)
 kal_uint8 outdevice;

 #if __AFE_MD2G_PWDN_LOCK__
   _AFE_SetAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_TRUE);
 #endif
   outdevice = AFE_GetOutputDevice(L1SP_AUDIO);
   if(enable)
   {
      AFE_SetOutputDevice(L1SP_AUDIO, outdevice|L1SP_STEREO2MONO);
      *AFE_AMCU_CON2 |= 0x0080;
      *AFE_VMCU_CON3 |= 0x0020;
#if defined(EXT_DAC_SUPPORT)      
	    *AFE_AMCU_CON1 |= 0x1000;
#endif	    
      afe.KaraokMode = KAL_TRUE;
   }
   else{
      AFE_SetOutputDevice(L1SP_AUDIO, outdevice&(~L1SP_STEREO2MONO));
      *AFE_AMCU_CON2 &= ~0x0080;
      *AFE_VMCU_CON3 &= ~0x0020;
#if defined(EXT_DAC_SUPPORT)      
	    *AFE_AMCU_CON1 &= ~0x1000;
#endif	
      afe.KaraokMode = KAL_FALSE;
   }
 #if __AFE_MD2G_PWDN_LOCK__
   _AFE_ClearAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_FALSE);
 #endif
    
#else
   if(enable)
   {
      afe.KaraokMode = KAL_TRUE;
   }
   else
   {
   	  afe.KaraokMode = KAL_FALSE;
   }
#endif // defined(MT6255) || defined(MT6250) || defined(MT6260)

#endif
}

kal_bool AFE_IsKaraok(void) 
{
#if __AFE_KARAOK_SUPPORT__
   return afe.KaraokMode;
#else
   return KAL_FALSE;
#endif
}

//=============================================================================================
//                 Section: [AFE Feature] Delay Off
//=============================================================================================
kal_bool AFE_IsInDelayOff(void)
{
#if (__AFE_AUDIO_DELAY_OFF__) || (__AFE_PA_DELAY_OFF__)
   if (AFE_GetAfeSate()==AFE_STATE_IDLE_OFF)
      return KAL_TRUE;
 #if (__AFE_PA_DELAY_OFF__)
   if(afe.pa_delay != -1)
      return KAL_TRUE;
 #endif   
   return KAL_FALSE;
#else
   return KAL_FALSE;
#endif
}

kal_uint8 AFE_Disable_IdleOffDelay(void)
{
#if (__AFE_AUDIO_DELAY_OFF__)
   if(afe.Audio_close_delay>0)
   {
      if(afe.Audio_gpt_on)
      { 
         DclSGPT_Control( afe.Audio_gpt, SGPT_CMD_STOP, 0);
         afe.Audio_gpt_on = KAL_FALSE;
      }       
      afe.Audio_close_delay = 0;
      afe.Audio_close_delay_expired = KAL_TRUE;
    
      afe.dis_idleOff_delay = KAL_TRUE;
   }
#endif
   AFE_SetRefresh();
   return 0;
}

#if (__AFE_AUDIO_DELAY_OFF__)
void Audio_DelayCloseHandler(void* para)
{
   afe.Audio_close_delay = 0;
   afe.Audio_close_delay_expired = KAL_TRUE;
   afe.Audio_gpt_on = KAL_FALSE;   
   if (kal_if_lisr())
      L1Audio_LSetEvent(afe.aud_id, NULL);
   else
      L1Audio_SetEvent(afe.aud_id, NULL);
}
#endif

void AFE_Stop_and_Wait_DelayOff(kal_uint8 aud_func, kal_uint32 asp_fs)
{
#if __AFE_AudVoice_SingleClkSrc__
 #if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   kal_uint32 savedMask;
   kal_bool stop_and_wait = KAL_FALSE;
   kal_bool in_delayoff = KAL_FALSE;

   savedMask = SaveAndSetIRQMask();
   
   if(AFE_IsInDelayOff() )
      in_delayoff = KAL_TRUE;
   RestoreIRQMask(savedMask);
   
   switch(aud_func)
   {
   case L1SP_SPEECH:
      if( (afe.audio_dl_ena) && (afe.aud[L1SP_SPEECH].out_dev&(L1SP_BUFFER_0|L1SP_BUFFER_1)) )
         in_delayoff = KAL_TRUE;
      if( (afe.voice_dl_ena) && (afe.aud[L1SP_SPEECH].out_dev&L1SP_BUFFER_ST) )
         in_delayoff = KAL_TRUE;
   case L1SP_SND_EFFECT:
   case L1SP_VOICE:
      if( in_delayoff )
      {
         stop_and_wait = KAL_TRUE;
         if(*AFE_VMCU_CON&0x0001)
            AFE_TurnOff8K();
         if(*AFE_AMCU_CON0&0x0001)
            AFE_TurnOffAudioClock();
      }
      break;
   case L1SP_AUDIO:
      if( (!AFE_IsKaraok()) && (*AFE_VMCU_CON&0x0001) )
      {
         AFE_TurnOff8K();
         stop_and_wait = KAL_TRUE;
      }
      else if(in_delayoff)
      {
         if( AFE_IsKaraok() )
            stop_and_wait = KAL_TRUE;
    #if __AFE_MULTIEPLE_DIE__         
         else if(afe.die2die_status == AFE_DIE2DIE_UPLINK)
            stop_and_wait = KAL_TRUE;
    #endif         
         #if defined(MT6250)           
         else if( (afe.die2die_status == AFE_DIE2DIE_DOWNLINK) && (afe.audio_fs != asp_fs) )         
            stop_and_wait = KAL_TRUE;
         #endif   	
      }
   	  break;
   case L1SP_KEYTONE:
   case L1SP_TONE:
   	  #if __AFE_MULTIEPLE_DIE__ 
      if( (afe.die2die_status == AFE_DIE2DIE_DOWNLINK) && (in_delayoff) && (AM_IsAudioPlaybackOn() == -1) )
         stop_and_wait = KAL_TRUE;
      #else   
      if( (in_delayoff) && (AM_IsAudioPlaybackOn() == -1) )
         stop_and_wait = KAL_TRUE;
      #endif    
      break;
   }

      if(stop_and_wait)
      {
   #if __AFE_PA_DELAY_OFF__
      afe.pa_delay  = 0;
   #endif
         AFE_Disable_IdleOffDelay();
         while(afe.audio_clk_ena||afe.voice_clk_ena)
            kal_sleep_task(1);
         
   }
 #endif
#else
   return;
#endif
}

//=============================================================================================
//                  Section: [AFE Feature] Vibration Speaker Functions
//=============================================================================================
#ifdef __VIBRATION_SPEAKER_SUPPORT__
void AFE_Vibrate(bool enable)
{
   if(enable)
      afe.vibrate = KAL_TRUE;
   else
      afe.vibrate = KAL_FALSE;
      
   AFE_SetRefresh();
}
#endif


//=============================================================================================
//                 Section: [AFE Feature] VCP 
//=============================================================================================
#ifdef __CLASSK_CP_SUPPORT__

void AFE_SetChargePump(bool enable, Media_VCP_DS_Module module)
{
#if __AFE_CLASSK_SUPPORT_INTERNAL__
   if(enable)
   	  afe.cp_disable &= (~(1<<module));
   else
      afe.cp_disable |= (1<<module);    
   AFE_SetRefresh();
#endif
}


kal_bool AFE_IsCPEnable(void)
{
   if(afe.cp_state == CP_STATE_ON_BOOST)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

#endif
//=============================================================================================
//                  Section: [AFE Feature] ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================
void AFE_RegisterBackup(void)
{
#if defined(DSP_DEBUG_LOG_AND_DUMP)
   sherif_assert_dump();
#endif
#if __RELOAD_HW_COEFF__
   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(1) );
   afe.regbak.VMCU_CON  = *AFE_VMCU_CON;
   afe.regbak.VDB_CON   = *AFE_VDB_CON;
   afe.regbak.VLB_CON   = *AFE_VLB_CON;
   afe.regbak.AMCU_CON0 = *AFE_AMCU_CON0;
   afe.regbak.AMCU_CON1 = *AFE_AMCU_CON1;
   afe.regbak.EDI_CON   = *AFE_EDI_CON;
   afe.regbak.AMCU_CON2 = *AFE_AMCU_CON2;
   afe.regbak.DAC_TEST  = *AFE_DAC_TEST;
   afe.regbak.VMCU_CON1 = *AFE_VMCU_CON1;
   afe.regbak.VMCU_CON2 = *AFE_VMCU_CON2;

   _AfeRegisterBackupByChip();

#if defined(__DUAL_MIC_SUPPORT__)
   afe.regbak.VAGC2_CON0 = *AFE_VAGC2_CON0;
   afe.regbak.VAGC2_CON1 = *AFE_VAGC2_CON1;
   afe.regbak.VAGC2_CON2 = *AFE_VAGC2_CON2;
   afe.regbak.VAGC2_CON3 = *AFE_VAGC2_CON3;
   afe.regbak.VAGC2_CON4 = *AFE_VAGC2_CON4;
   afe.regbak.VAGC2_CON5 = *AFE_VAGC2_CON5;
   afe.regbak.VAGC2_CON6 = *AFE_VAGC2_CON6;
#endif
#endif
}

void AFE_RegisterStore(void)
{
#if defined(__AUDIO_POWERON_RESET_DSP__)
   if (!afe.afe_init)
      return;
#endif
#if __RELOAD_HW_COEFF__
   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(0) );
   *AFE_VMCU_CON  = afe.regbak.VMCU_CON;  
   *AFE_VDB_CON   = afe.regbak.VDB_CON; 
   *AFE_VLB_CON   = afe.regbak.VLB_CON;   
   *AFE_AMCU_CON0 = afe.regbak.AMCU_CON0;
   *AFE_AMCU_CON1 = afe.regbak.AMCU_CON1; 
   *AFE_EDI_CON   = afe.regbak.EDI_CON;   
   *AFE_AMCU_CON2 = afe.regbak.AMCU_CON2; 
   *AFE_DAC_TEST  = afe.regbak.DAC_TEST;  
   *AFE_VMCU_CON1 = afe.regbak.VMCU_CON1; 
   *AFE_VMCU_CON2 = afe.regbak.VMCU_CON2; 

   _AfeRegisterStoreByChip();

#if defined(__DUAL_MIC_SUPPORT__)
   *AFE_VAGC2_CON0 = afe.regbak.VAGC2_CON0;
   *AFE_VAGC2_CON1 = afe.regbak.VAGC2_CON1; 
   *AFE_VAGC2_CON2 = afe.regbak.VAGC2_CON2; 
   *AFE_VAGC2_CON3 = afe.regbak.VAGC2_CON3; 
   *AFE_VAGC2_CON4 = afe.regbak.VAGC2_CON4; 
   *AFE_VAGC2_CON5 = afe.regbak.VAGC2_CON5; 
   *AFE_VAGC2_CON6 = afe.regbak.VAGC2_CON6; 
#endif 
#endif
}

//=============================================================================================
//                  Section: [AFE Feature] AFE Loop back
//=============================================================================================
void AFE_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      afe.toneLoopbackRec = KAL_TRUE;
   else
      afe.toneLoopbackRec = KAL_FALSE;
}

kal_bool AFE_GetLoopbackStatus( void )
{
   return afe.loopback;
}

void AFE_WaitReleaseVoltage(void)
{
#if __AFE_2ndG_AC_COUPLE__
   while(afe.system_poweroff){
      if(afe.audio_dl_ena  == KAL_FALSE)
         break;
      kal_sleep_task(1);
   }
#else
   return;
#endif
}

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
kal_bool AFE_IsInOffState(void)
{
    kal_bool result;
    
    if ((!afe.voice_clk_ena || afe.v8k_off_request) && (!afe.audio_clk_ena || afe.aClk_off_request))
    {
        result = KAL_TRUE;
    }
    else
    {
        result = KAL_FALSE;
    }
    
    return result;
}
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#pragma arm section

