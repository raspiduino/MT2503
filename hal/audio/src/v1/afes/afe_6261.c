/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014 
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
 * afe_6261.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   AFE Driver for 6261/2501/2502
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#include "afe.h"
#include "dcl.h"
#if defined(__AUDIO_AT_CMD__)
AFE_PCMIF_STRUCT_T pcmif;
#endif

static void AFE_SwitchHSon(void);
static void AFE_SwitchHSoff(void);
static void AFE_SwitchHPon(void);
static void AFE_SwitchHPoff(void);

//==============================================
//   SPK Related
//==============================================
extern kal_bool L1Audio_IsInitiated(void);
static void _AFE_Switch_IntAmp(kal_bool on)  // 1: turn on, 0: turn off
{
   kal_uint16 restore;
   if(extPA_underHP)
   {
   	  return;
   }
   if(on)   	  	   
   {
#if !defined(__CLASSK_CP_SUPPORT__)        
        //off -> bypass
        //spk initial setting
        *SPK_CON3  = 0x4800;           
        *SPK_CON6  = 0x0988; //bypass mode 
        *SPK_CON7  = 0x0180; //vcm fast startup
	 	 	 	AFE_DELAY(2000);     //wait 2ms
	 	 	 	*SPK_CON7  = 0x0100;                       
#endif
        *ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP; //HS buffer power on
        AFE_DELAY(10);
        *ABBA_AUDIODL_CON1  |= 0x0004; // spk mode
        // for adjust gain with ramp 
        *ABBA_AUDIODL_CON12 &= (~audzcdenable);
        
        //set to 0dB
        restore =  *ABBA_AUDIODL_CON13;
        *ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000;  // Default 0dB => [14:10] = 01000

#if __SPK_DC_COMPENSATION__	
        //enable compensation
        {
          *AFE_AMCU_CON2 |= 0x8000;  
          *AFE_VMCU_CON2 |= 0x8000;
          *AFE_AMCU_CON6 = afe.spk_dc_compensate_value;
          *AFE_AMCU_CON7 = afe.spk_dc_compensate_value;
          *AFE_VMCU_CON4 = afe.spk_dc_compensate_value;
        }
#endif        
        *SPK_CON7 |= 0x0080;    // fast VCM track
        *SPK_CON0 |= 0x0001;    // enable spk
        AFE_DELAY(2000);
        *SPK_CON3 |= 0x4000; 
        *SPK_CON7 &= (~0x0080); // vcm high PSRR mode
        
        {
            kal_int16 targ_gain = (kal_int16)(restore & 0x7C00);
      	    kal_int16 curr_gain = (kal_int16)(*ABBA_AUDIODL_CON13 & 0x7C00);
      	    kal_int16 gain_step = targ_gain >= curr_gain ? 0x0400 : -0x0400;
            while (curr_gain != targ_gain)
            {
               curr_gain += gain_step;
               *ABBA_AUDIODL_CON13 = (kal_uint16)curr_gain | (restore & ~0x7C00);
               AFE_DELAY(500);
            }
        }
       *ABBA_AUDIODL_CON1  |= 0x6000; // ZCD: handset mode 
       *ABBA_AUDIODL_CON12 |= (audzcdenable);
   }
   else
   {
   	  *ABBA_AUDIODL_CON1 &= (~0x0004);  
   	  *SPK_CON3 |= 0x0800;
   	  *SPK_CON0 &= (~0x0001);
      *SPK_CON3 &= (~0x4000);
      *SPK_CON7 &= (~0x0400);
#if __SPK_DC_COMPENSATION__	
      //disable compensation
      {
        *AFE_AMCU_CON2 &= ~0x8000;
        *AFE_VMCU_CON2 &= ~0x8000;
      }
#endif      
   }
   #if __AFE_CLASSK_SUPPORT_INTERNAL__
   if(L1Audio_IsInitiated())
      audio_send_vbat_detect_rate(on);
   #endif
}

static void _AFE_Switch_TurnOn_Amp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( !afe.gpio_lock ) {
      if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
      {
         // Turn on the external amplifier                        
         if (Ext_op_on_delay == 0) {
            #if defined(__CLASSK_CP_SUPPORT__)
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            if(Check_CP_available())
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
            else
            	 _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);
            #else
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);	    
            #endif
            #endif
            _AFE_Switch_IntAmp(KAL_TRUE);
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
            // Reset the ext_op_delay timer to indicate the completion of current operation
            afe.ext_op_delay = 0;
         } else {
            // The latest command will replace the un-executed command
            afe.ext_op_delay = (int16)Ext_op_on_delay;
         }
      }
   }
}

static void _AFE_Switch_TurnOff_Amp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( !afe.gpio_lock ) 
   {
      if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) || 
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
      {
      } 
      else 
      {
         // Turn off the external amplifier
         // Not in delay off or device change
         if (Ext_op_off_delay == 0) 
         {
            AVolumeRampDown();
            _AFE_Switch_IntAmp(KAL_FALSE);
            AFE_SwitchExtAmplifier( false );
            #if defined(__CLASSK_CP_SUPPORT__)
            _AFE_Switch_ChargePump(KAL_FALSE, CP_STATE_OFF);
            afe.cp_th_high = KAL_FALSE;
            #endif
            afe.ext_op_on = KAL_FALSE;
            /// Reset the ext_op_delay timer to indicate the completion of current operation
            afe.ext_op_delay = 0;
            AFE_SetRefresh();
         }
         else 
         {
            // The latest command will replace the un-executed command
            afe.ext_op_delay = -(int16)Ext_op_off_delay;
         }
      }
   }
}


//==============================================
//   VAPDN Related
//==============================================
static void UpdateVAPDN(kal_uint8 device)
{
   if( afe.mic_mute||afe.mic_flag==0 ||afe.mute ) 
   {
      if(afe.accessory_flag)
      {
         *ABBA_VBITX_CON1 &= (~RG_VPWDB_ADC);
         *ABBA_VBITX_CON0 &= (~RG_VPWDB_PGA);
         *ABBA_VBITX_CON4 |= (RG_VPWDB_MBIAS);
         *ABBA_VBITX_CON0 |= (RG_VCFG_1); //avoid cross-talk
         *ABBA_VBITX_CON1 |= (RG_VREF24_EN|RG_VCM14_EN);         
      }
      else 
      {        
         *ABBA_VBITX_CON1 &= (~RG_VPWDB_ADC);
         *ABBA_VBITX_CON1 &= (~(RG_VREF24_EN|RG_VCM14_EN));
         *ABBA_VBITX_CON0 &= (~RG_VPWDB_PGA);
         //bypass to workaroud for accdet EINT at E1
         if(INT_SW_SecVersion()!=SW_SEC_0) //not E1
         {
            *ABBA_VBITX_CON4 &= (~RG_VPWDB_MBIAS);         
         }
         *ABBA_VBITX_CON0 |= (RG_VCFG_1);
      }
      afe.voice_ul_ena = KAL_FALSE;
      return;
   }
   *ABBA_VBITX_CON4 |= (RG_VPWDB_MBIAS);
   *ABBA_VBITX_CON1 |= (RG_VPWDB_ADC | RG_VREF24_EN | RG_VCM14_EN);
   *ABBA_VBITX_CON0 |= (RG_VPWDB_PGA);
   
   *ABBA_VBITX_CON0 &= ~(RG_VCFG_1);
   afe.voice_ul_ena = KAL_TRUE;
}

static void _apply_mic_setting(kal_int16 a_lowest, kal_int16 v_lowest)
{

   if( afe.mic_src==L1SP_LNA_1 ) 
   {/* Headset Mode (mic1)*/
    #if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif   
       {
          if(mic1_type_sel==0)	 
          {
            *ABBA_VBITX_CON0 &= 0xFFEF;
          }
          else
          {
            *ABBA_VBITX_CON0 |= 0x0010;
          }
       }   
       *ABBA_VBITX_CON0  = (*ABBA_VBITX_CON0 & MIC_SETTING_MASK) | MIC_SETTING_HEADSET; /* Switch input source to headset microphone */      
   }
   else 
   {/* Normal Mode (mic0)*/
    #if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
       {
          if(mic0_type_sel==0)	
          { 
             *ABBA_VBITX_CON0 &= 0xFFEF;
          }
          else
          {
             *ABBA_VBITX_CON0 |= 0x0010;
          }   
       }     
      *ABBA_VBITX_CON0 = (*ABBA_VBITX_CON0 & MIC_SETTING_MASK) | MIC_SETTING_NORMAL;  /* Switch input source to normal microphone */
   }
}

//==============================================
//       Loopback usage
//==============================================
void AFE_TurnOnLoopback( void )
{
   *AFE_VLB_CON |= 0x0022;     // for digital loopback
   *AFE_VLB_CON |= 0x0008;

   afe.loopback = KAL_TRUE;
   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '+');
}

void AFE_TurnOffLoopback( void )
{
   *AFE_VLB_CON &= (~0x62);    // for digital loopback
   *AFE_VLB_CON &= (~0x0008);
   afe.loopback = KAL_FALSE;

   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '-');
}

//dir UL-->DL
void AFE_PCMIFLoopbackEn( kal_bool enable )
{
   if(enable)
   {
     *AFE_VDB_CON |= 0x1000;
   }
   else
   {
   	 *AFE_VDB_CON &= (~0x1000);
   }
   afe.pcmifloopback = enable; 
#if defined(__AUDIO_AT_CMD__)
   pcmif.LPK_U2D = enable;
#endif     
   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_SET_PCMIFLPK, enable);
}

//==============================================
//       Clock related
//==============================================
extern kal_uint8 AM_GetDLULPath(void);
void _AFE_DCLK_CtrlSeq(kal_bool turnon, kal_bool audio)
{
	 kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();

   if( turnon )
   {
   	  *(volatile uint16 *)(0xA001022C) = (*(volatile uint16 *)(0xA001022C) | 0x0013);
   	  *ABBA_AUDIODL_CON8 |= (RG_LCLDO_TBST_EN);
      *ABBA_AUDIODL_CON10 = 0x1406; //LDO:2.4v    	  
#ifdef __LINE_IN_SUPPORT__
   	  if(afe.sp_flag & (1<<L1SP_LINEIN))
      {
      	 *ABBA_AUDIODL_CON10 |= 0x0010; // set aux in again to prevent clear setting  
      }
#endif      
   	  *ABBA_AUDIODL_CON9  |= 0x0001;
   	  *ABBA_AUDIODL_CON11 |= 0x0003;
   	  AFE_DELAY(1);
   	  if(audio)
   	  {
   	  	 *ABBA_AUDIODL_CON7 |= 0x0003;
   	  }
   	  else
   	  {
   	  	 *ABBA_AUDIODL_CON7 |= 0x0002;
   	  }
   	  *ABBA_AUDIODL_CON0 |= (RG_AUDDACRPWRUP|RG_AUDDACLPWRUP);
   	  *ABBA_AUDIODL_CON15  = 0x11A1;
   	  *ABBA_AUDIODL_CON14 |= 0x0001;
   	  *MD2GSYS_CG_CLR2     = PDN_CON2_AAFE; //equal PDN_CON2_VAFE 
   	  
   	  if(audio)
   	  {   	  	 
   	  	 
   	  	 if(AFE_IsKaraok())  //dl + ul
         {         	 
         	  *AFE_MCU_CON1 |= 0x000F;
         }
         else
         {
   	  	    *AFE_MCU_CON1   |= 0x000C; 
         }
         *AFE_AMCU_CON0  |= 0x0001;
         
   	  }
   	  else
   	  {   	  	
   	  	 if(AFE_IsKaraok() || (AM_GetDLULPath()== DL_UL_BOTH_PATH) || afe.loopback || afe.pcmifloopback)  //dl + ul   	  	
         {         	 
         	  *AFE_MCU_CON1 |= 0x000F;
         }
		     else if(AM_GetDLULPath()== DL_PATH)
		     {
		     	  *AFE_MCU_CON1   |= 0x000C; 
		     }
         else //ul only
         {         	  
         	  *AFE_MCU_CON1 |= 0x0003;
         }
         *AFE_VMCU_CON0 |= 0x0001;
   	  }   	  
   	  *AFE_MCU_CON0 = 0x0001;
   }
   else
   {   	  
   	  *ABBA_AUDIODL_CON0  &= (~(RG_AUDDACRPWRUP|RG_AUDDACLPWRUP));
      *ABBA_AUDIODL_CON7  &= (~0x0003);
      *ABBA_AUDIODL_CON11 &= (~0x0003);
   	  *AFE_MCU_CON0 &= (~0x0001);
   	  if(audio)
   	  {
   	  	 *AFE_AMCU_CON0  &= (~0x0001);
   	  }
   	  else
   	  {
   	  	 *AFE_VMCU_CON0  &= (~0x0001);
   	  }
   	  *AFE_MCU_CON1 &= (~0x000F);
   	  *MD2GSYS_CG_SET2     = PDN_CON2_VAFE;   //equal PDN_CON2_AAFE 
   	  *ABBA_AUDIODL_CON14 &= (~0x0001);
   	  *ABBA_AUDIODL_CON15  = 0x1021;
   	  *ABBA_AUDIODL_CON9  &= (~0x0001);
   	  *(volatile uint16 *)(0xA001022C) = (*(volatile uint16 *)(0xA001022C) & (~0x0010));
   }
   RestoreIRQMask(savedMask);
}


void AFE_TurnOnAudioClock( kal_uint8 clock )
{
   kal_uint16 SampleRate;
   kal_uint32 u4SavedMask = 0;

   if(!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   
   if( (afe.audio_clk_ena) && (afe.aClk_off_request) )
      afe.aClk_off_request = KAL_FALSE;
   if(!afe.audio_clk_ena )
   {
      afe.aClk_off_request = KAL_FALSE;
      switch (clock) {
         case ASP_FS_8K:  SampleRate = 0;  break;
         case ASP_FS_11K: SampleRate = 1;  break;
         case ASP_FS_12K: SampleRate = 2;  break;
         case ASP_FS_16K: SampleRate = 4;  break;
         case ASP_FS_22K: SampleRate = 5;  break;
         case ASP_FS_24K: SampleRate = 6;  break;
         case ASP_FS_32K: SampleRate = 8;  break;
         case ASP_FS_44K: SampleRate = 9;  break;
         case ASP_FS_48K: SampleRate = 10; break;
         default        : SampleRate = 0;  break;
      }
      //SampleRate = (clock&3) + 8; //8: 32kHz, 9: 44kHz, 10: 48kHz
      *AFE_AMCU_CON1 = ((*AFE_AMCU_CON1) & (~0x03C0)) | (SampleRate<<6);
      afe.audio_fs = (kal_uint32)clock;
      
      _AFE_DCLK_CtrlSeq(KAL_TRUE,KAL_TRUE);
      afe.audio_clk_ena = KAL_TRUE;           
   }
   if(!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
}

void AFE_TurnOffAudioClock( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   afe.aClk_off_request = KAL_TRUE;
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}

// The coefficient can be written into register only when the power is on
void AFE_TurnOnAudioPower( void )
{
   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
}

void AFE_TurnOffAudioPower( void )
{
   if(!afe.voice_clk_ena)
      *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
}

void AFE_TurnOn8K( void )
{
   kal_uint32 u4SavedMask = 0;
#ifdef L1D_TEST
   extern  int  PollLoopbackMode(void);
   if( PollLoopbackMode() !=1 )
#endif
   {
      if (!kal_if_lisr())
         u4SavedMask = SaveAndSetIRQMask();
      if( (afe.voice_clk_ena) && (afe.v8k_off_request) )
         afe.v8k_off_request = KAL_FALSE;
                  
      if(!afe.voice_clk_ena )
      {
         afe.v8k_off_request = KAL_FALSE;
         if( ((*AFE_AMCU_CON0&0x0001)==0))
         {
            *AFE_VMCU_CON3 |= 0x0020;
         }         
         _AFE_DCLK_CtrlSeq(KAL_TRUE,KAL_FALSE);
         afe.voice_clk_ena = KAL_TRUE;
      }

      *DP_8K_LIMITER_CTRL &= (~0x1);  //Long ago, when HQA, limiter must be closed,But now no this limitation; After MT6256_S01, this setting means initial bit which causes DSP'init, and DSP turn it into 1
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   //turn on filter
   *DP_8K_LIMITER_CTRL |= 0x200; 
   *DP_8K_LIMITER_CTRL &= ~0x800; 
#endif //__VIBRATION_SPEAKER_SUPPORT__
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
}

void AFE_TurnOff8K( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   afe.v8k_off_request = KAL_TRUE;
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}

void AFE_TurnOff8K_Direct( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   if(afe.voice_clk_ena)
   {    
      *AFE_MCU_CON0    = 0x0000;
      *AFE_VMCU_CON0  &= (~0x0001);
      *AFE_MCU_CON1   &= (~0x000F);      
      if(!afe.audio_clk_ena)
      {
         *MD2GSYS_CG_SET2   |= PDN_CON2_VAFE;
      }
      afe.voice_clk_ena = KAL_FALSE;
   }
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}


//==============================================
//       Else
//==============================================
void AFE_SetSamplingRate( uint32 freq )
{
   kal_uint16 SampleRate;
#if defined(EXT_DAC_SUPPORT) 
   switch (freq) {
      case 0x00: 
      case 0x20:
      case 0x40:     
         afe.ext_dac_freq = 32000;     
         break;
      case 0x11:
      case 0x21:  
      case 0x41:
         afe.ext_dac_freq = 44100;
         break;
      case 0x12: 
      case 0x22:  
      case 0x42: 
         afe.ext_dac_freq = 48000;
         break;
   }
#endif
   switch (freq) {
      case ASP_FS_8K:  SampleRate = 0;  break;
      case ASP_FS_11K: SampleRate = 1;  break;
      case ASP_FS_12K: SampleRate = 2;  break;
      case ASP_FS_16K: SampleRate = 4;  break;
      case ASP_FS_22K: SampleRate = 5;  break;
      case ASP_FS_24K: SampleRate = 6;  break;
      case ASP_FS_32K: SampleRate = 8;  break;
      case ASP_FS_44K: SampleRate = 9;  break;
      case ASP_FS_48K: SampleRate = 10; break;
      default        : SampleRate = 0;  break;
   }
   *AFE_AMCU_CON1 = ((*AFE_AMCU_CON1) & (~0x03C0)) | (SampleRate<<6);
   afe.audio_fs = freq;
}

void _AfeRegisterBackupByChip(void){}

void _AfeRegisterStoreByChip(void){}

//==============================================
//  __GAIN_TABLE_SUPPORT__ Specific Functions
//==============================================
#if defined(__GAIN_TABLE_SUPPORT__)
void _AfeGetExtAmpPathUsage(kal_uint8 *ext_dac, kal_uint16 *ctrl_point)
{
   *ctrl_point = 2;
   *ext_dac = L1SP_BUFFER_EXT;
}

void _AfeGetExtPgaInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number)
{
   if (ctrl_point == 0){ //Class AB
      *total_level = 4;
      *bit_number = 3;
   } 
   else 
   {
      *total_level = 0;
      *bit_number = 0;
   }
}

void _AfeGetExtPgaGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map)
{
   kal_uint16 i;
   if (ctrl_point == 0) //Class AB
   {
      ASSERT(total_level >= 4);
      gain_map[0] = -6;
      gain_map[1] = -3;
      gain_map[2] = 6;
      gain_map[3] = 12;
   } 
   else 
   {
      ASSERT(0);
   }  
}
#endif


//==============================================
//  SWIP Common Functions Related
//==============================================
#if defined(__IPS_SUPPORT__)
void _AfeForceTurnOnAudioClock(void)
{
   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;  
   *AFE_MCU_CON1  |= 0x000C; 
   *AFE_AMCU_CON0 |= 0x0001;
   *AFE_MCU_CON0   = 0x0001;
}

void _AfeForceTurnOffAudioClock(void)
{
   *AFE_MCU_CON0   =  0x0000;   
   *AFE_AMCU_CON0 &= (~0x0001);
   *AFE_MCU_CON1  &= (~0x000C);
   *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
}
#endif // defined(__IPS_SUPPORT__)


//==============================================
//  Chip Specific AFE Init
//==============================================
void AFE_Chip_Init( void )
{
   //Digital part Initialization
   *AFE_AMCU_CON1   = 0x0E00;
   *AFE_AMCU_CON5   = 0x0002;
   *AFE_VMCU_CON3   = 0x0002;
   *AFE_VMCU_CON2   = 0x083C;
   *AFE_AMCU_CON2   = 0x003C;
   *AFE_VMCU_CON1   = 0x0080;
   
   //Uplink PGA Gain : 6dB
   *ABBA_VBITX_CON0 |=  (0x2<<6);
   
   //Analog part Initialization and power-on control sequence
   *ABBA_AUDIODL_CON8 |= (RG_LCLDO_TBST_EN);
   *ABBA_AUDIODL_CON4  =0x01B9;
   AFE_DELAY(10);
   *ABBA_AUDIODL_CON4 |=0x0040;
   // should wait 2s~3s to charge cap
   *ABBA_AUDIODL_CON10 = 0x1406; //LDO:2.4v
   //*ABBA_AUDIODL_CON9  |= 0x0001;
   
   //Speaker Amp setting
   *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );

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
      else //dcc ecm
         *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xD9FF) | 0x2400;  
   }  
   afe.class_d_gain  = SpkAmpGain;
   *DP_VOL_IN_PCM    = DG_Microphone;
   *DP_VOL_OUT_PCM   = DG_DL_Speech;
   PcmSink_SetGain(DG_DAF);
   PcmSink_InitDigitalGain();

   *DP_AUDIO_16K_TX_VOL = DG_Microphone;
   *DP_AUDIO_16K_RX_VOL = DG_DL_Speech;   // 16K WB DownLink path digital gain
     
   afe.dc_calibrate_writeback = KAL_FALSE;
   afe.bReceiverOut = KAL_FALSE;
   afe.dc_cali_new_callback = KAL_FALSE;
   afe.retrieved_dc_data = 0;
#if __AFE_CURRENT_SENSOR_ENABLE__    
   afe.cali_cf_data = 0;
   afe.vib_cali_done = KAL_FALSE;
   afe.vib_first_cali = KAL_TRUE;
#endif    
   afe.bPowerDown = KAL_TRUE;
   afe.KaraokMode = KAL_FALSE;
   afe.powerOffWait = -1;
}

//==============================================
// Wavetable Data Transfer Unit DMA  (no use)
//==============================================
void AFE_TurnOnWTDMA( void ){}

void AFE_TurnOffWTDMA( void ){}


//==============================================
// HW Mute Control
//==============================================
void _AfeHardwareMuteCtrl(void)
{
   kal_bool fgMute;

#if __AFE_MD2G_PWDN_LOCK__
   _AFE_SetAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_TRUE);
#endif

   fgMute = (kal_bool)(afe.afe_hw_mute || afe.afe_event_handler_hw_mute || afe.afe_audio_clk_hw_mute);
   
   if(fgMute) 
   {   
      *AFE_AMCU_CON1 |= 0x3C;
   }
   else
   {
      *AFE_AMCU_CON1 &= ~0x0C;
   }
   
#if __AFE_MD2G_PWDN_LOCK__
   _AFE_ClearAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_FALSE);
#endif
}

void AFE_SetHardwareMute(bool mute)
{
#if HW_MUTE_SUPPORT_PLATFORM
   if(mute) 
   {
   	  if(afe.afe_hw_mute)
   	  {
   	  	return;
   	  }
   #if defined(EXT_DAC_SUPPORT)
      afe.ext_dac_mute = true;
      AFE_SetRefresh();
   #endif
      afe.afe_hw_mute = mute; 
      _AfeHardwareMuteCtrl();
      
      if (afe.hw_mute_sleep)
      {
         kal_uint8 mute_sleepcnt;
         switch(afe.audio_fs)
         {
            case ASP_FS_8K:  mute_sleepcnt = 15;  break;
            case ASP_FS_11K: mute_sleepcnt = 12;  break;
            case ASP_FS_12K: mute_sleepcnt = 11;  break;
            case ASP_FS_16K: mute_sleepcnt =  8;  break;
            case ASP_FS_22K: mute_sleepcnt =  7;  break;
            case ASP_FS_24K: mute_sleepcnt =  6;  break;
            case ASP_FS_32K: mute_sleepcnt =  5;  break;
            case ASP_FS_44K: mute_sleepcnt =  4;  break;
            case ASP_FS_48K: mute_sleepcnt =  4;  break;
            default        : mute_sleepcnt =  4;  break;
         }
         kal_sleep_task(mute_sleepcnt);
      }
   }
   else
   { 
   #if defined(EXT_DAC_SUPPORT)      
      afe.ext_dac_mute = false;
      AFE_SetRefresh(); 
   #endif

      afe.afe_hw_mute = mute; 
      _AfeHardwareMuteCtrl();
   }
#endif //HW_MUTE_SUPPORT_PLATFORM
}

//==============================================
//       DC Calibration/Compensation
//==============================================
#define DC_CALI_BUF_LEN     120
#define DC_CALI_CHANNEL     9
#define DC_CALI_TIMES       3
#define DC_CALI_AUXADC_MAX  1023
#define DC_CALI_AUXADC_MIN  0
#define DC_CALI_SUM_MAX     (DC_CALI_AUXADC_MAX * DC_CALI_BUF_LEN)
#define BOUNDED(in,up,lo) ((in) > (up) ? (up) : (in) < (lo) ? (lo) : (in))
#define DC_CALI_SHIFT       8	// to minimize quantization err. DC_offset_val:Q8

static kal_int32 Convert_DC_offset_sum_to_DC_offset_val(kal_int32 DC_offset_sum, kal_int32 cali_times, kal_int32 pre_offset_val)
{
    kal_int32 DC_offset_val = 0;
    
    if (cali_times > 0)
    {
        kal_int32 DC_offset_diff = (DC_offset_sum << DC_CALI_SHIFT) / cali_times;
        DC_offset_val = pre_offset_val + DC_offset_diff;
    }
    
    return DC_offset_val;
}

// Set the regression line : y = a * x
// y : digital AFE compensation value
// x : DC offset value
// x * 5600 / 1024 * 1000 / (1.4 * 1000000 / 65536(code range) * 4(12dB) * 2(Vpp))
// = 32 * x
#define DC_CALI_REGRESSION_COEF_A_12dB 32
#define DC_CALI_REGRESSION_COEF_A_6dB  (DC_CALI_REGRESSION_COEF_A_12dB << 1)

static kal_uint16 Convert_DC_offset_val_to_DC_comp_val(kal_int32 curr_DC_offset_val)
{
    kal_int32 coef_a;
    kal_int32 curr_DC_comp_val;
    kal_int16 final_DC_comp_val;
    
    if ((*SPK_CON0 & 0x0030) == 0x30)
    {   // SPK +12dB
        coef_a = DC_CALI_REGRESSION_COEF_A_12dB;
    }
    else
    {   // SPK +6dB
        coef_a = DC_CALI_REGRESSION_COEF_A_6dB;
    }
    
    curr_DC_comp_val = curr_DC_offset_val * coef_a;
    
    final_DC_comp_val = (kal_int16)BOUNDED(curr_DC_comp_val>>DC_CALI_SHIFT, 32767, -32768);
    
    return (kal_uint16)final_DC_comp_val;
}

// for debug
// AuxADC digital value resolution: 10 bits --> 0 ~ 1023
// AuxADC digital value 1024 map to 5600 mV
// DC offset mV = DC offset value * 5600 / 1024
//              = DC offset value *  175 /   32
//              = DC offset value *  175 >>   5
static kal_int16 Convert_DC_offset_val_to_DC_offset_mV(kal_int32 DC_offset_val)
{
    kal_int16 DC_offset_mV = (kal_int16)(DC_offset_val * 175 >> (5+DC_CALI_SHIFT));
    return DC_offset_mV;
}


static kal_int32 Sum_AuxADC_Value(kal_uint16 *p_buf, kal_int32 count)
{
    kal_int32 total_sum = 0;
    
    if (count > 0)
    {
        kal_int32 i;
        
        for (i = 0; i < count; i++)
        {
            total_sum += (kal_int32)(*p_buf++);
        }
    }
    
    return total_sum;
}


void AFE_DC_Calibration_WriteBack(void)
{
   if( !afe.dc_calibrate_writeback && afe.dc_calibrate_finish )
   {
      afe.dc_calibrate_writeback = KAL_TRUE;   
      if(afe.Pre_DC_OFFSET != afe.DC_OFFSET)
         afe.pDC_Calibration_CallBack(&afe.Callback_DCOffset); 
   }
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

// For SDM gain 60 / 64, audio buffer gain 0dB, 
// compensation value 65536 --> DC offset 2000mV
// DC comp value =  DC offset mV * 65536 / 2000
//               = (DC offset mV << 12) / 125 
// DC comp value = (DC offset value * 7 << 6) / 5

kal_uint16 Convert_HP_DC_offset_val_to_HP_DC_comp_val(kal_int32 DC_offset_sum, kal_int32 count)
{
    kal_int32 DC_comp_val;
    kal_int16 final_val;
    
    DC_comp_val = (DC_offset_sum * 7 << 6) / 5 / count;
    DC_comp_val = BOUNDED(DC_comp_val, 32767, -32768);
    final_val = (kal_int16)DC_comp_val;
    
    return (kal_uint16)final_val;
}

#define HP_CALI_BUF_LEN     DC_CALI_BUF_LEN
#define HP_CALI_L_CHANNEL   7
#define HP_CALI_R_CHANNEL   8
#define HP_CALI_SWITCH      2
#define HP_CALI_TIMES       4
#define HP_CALI_CH          2

static void Earphone_DC_Calibration(void)
{
#if __AFE_HP_DC_CALIBRATION__	
   
   kal_uint16 aux_adc_buf[DC_CALI_BUF_LEN];
   DCL_HANDLE dcl_hadc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T GetImmDataOnBooting;   
   
   GetImmDataOnBooting.u4MeaCount = (DCL_UINT32)DC_CALI_BUF_LEN;
   GetImmDataOnBooting.u2ADCData  = (DCL_UINT16 *)aux_adc_buf;
   
    // Turn on digital AFE
    _AFE_DCLK_CtrlSeq(KAL_TRUE, KAL_TRUE); 
      
	 // Generate silence
   *AFE_AMCU_CON1 |= 0x003c;   // Mute
   *AFE_DAC_TEST  |= 0x6000;   // Generate audio sine tone
     
	 *AFE_AMCU_CON1 &= ~0x4000;  // Disable mono mode   

   {
        kal_int32 temp_value;
        kal_int32 sum_AuxADC_val[HP_CALI_SWITCH][HP_CALI_CH] = {0};
        kal_int32 DC_read_val[HP_CALI_CH][HP_CALI_TIMES] = {0};
        kal_int32 sw_idx; // switch index
        kal_int32 it_idx; // iteration index
        kal_int32 ch_idx; // channel index
        
        for (sw_idx = 0; sw_idx < HP_CALI_SWITCH; sw_idx++)
        {
            if (sw_idx == 0)
            {   // HP off
                // Already off, do nothing
                kal_uint32 i=0;
                while(i<HP_CHARGE_DELAY)
                {
                   AFE_DELAY(1000);
                   i++;
                }
            }
            else
            {   // HP on
                *ABBA_AUDIODL_CON13 = (*ABBA_AUDIODL_CON13 & ~0x03FF) | 0x02F7;  // Default 0dB => [4:0] = 10111'b for L, [9:5] = 10111'b for R
                AFE_SwitchHPon();
            }
            
            for (it_idx = 0; it_idx < HP_CALI_TIMES; it_idx++)
            {
                for (ch_idx = 0; ch_idx < HP_CALI_CH; ch_idx++)
                {
                    if (ch_idx == 0)
                    {   // L channel
                        GetImmDataOnBooting.u4Channel = (DCL_UINT32)HP_CALI_L_CHANNEL;
                    }
                    else
                    {   // R channel
                        GetImmDataOnBooting.u4Channel = (DCL_UINT32)HP_CALI_R_CHANNEL;
                    }
                    
                    DclSADC_Control(dcl_hadc_handle, ADC_CMD_GET_IMM_DATA_ON_BOOTING, (DCL_CTRL_DATA_T *)&GetImmDataOnBooting);
                    
                    // Calculate the value summation
                    temp_value = Sum_AuxADC_Value(aux_adc_buf, HP_CALI_BUF_LEN);
                    if (sw_idx == 0)
                    {
                        DC_read_val[ch_idx][it_idx] -= temp_value;
                    }
                    else
                    {
                        DC_read_val[ch_idx][it_idx] += temp_value;
                    }
                    sum_AuxADC_val[sw_idx][ch_idx] += temp_value;
                }
                
                AFE_DELAY(1000);
            }
        }
        
        for (ch_idx = 0; ch_idx < HP_CALI_CH; ch_idx++)
        {
            kal_int32  DC_offset_sum = sum_AuxADC_val[1][ch_idx] - sum_AuxADC_val[0][ch_idx]; // on - off
            kal_uint16 DC_comp_val   = Convert_HP_DC_offset_val_to_HP_DC_comp_val (DC_offset_sum, HP_CALI_TIMES * HP_CALI_BUF_LEN);
            if (ch_idx == 0)
            {
                afe.hp_dc_compensate_value_l = DC_comp_val;
            }
            else
            {
                afe.hp_dc_compensate_value_r = DC_comp_val;
            }
        }
    }
    DclSADC_Close(dcl_hadc_handle);
    AFE_SwitchHPoff();
        
    // Turn off DAC tone
    *AFE_DAC_TEST  &= ~0x6000;
    *AFE_AMCU_CON1 &= ~0x000c;
        
    // Turn off digital AFE
    _AFE_DCLK_CtrlSeq(KAL_FALSE, KAL_TRUE);

#endif   
}


void DC_Calibration(void)
{
#if __SPK_DC_COMPENSATION__	
    // Update AFE static control status
    {
        afe.spk_dc_compensate_value = Convert_DC_offset_val_to_DC_comp_val((kal_int32)afe.Pre_DC_OFFSET);
    }
    
    // AFE related control flow
    {
        // Turn on digital afe
        _AFE_DCLK_CtrlSeq(KAL_TRUE, KAL_TRUE); 
        
        // Disable mono mode
        *AFE_AMCU_CON1 &= ~0x4000; 
        
        // Generate silence
        *AFE_AMCU_CON1 |= 0x003c;   // Mute
        *AFE_DAC_TEST  |= 0x6000;   // Audio sine tone gen
        
        // Turn on hs DAC & buffer
        AFE_SwitchHSon();
         
        *ABBA_AUDIODL_CON13 = (*ABBA_AUDIODL_CON13 & ~0x7C00) | 0x2000;  // Default 0dB => [14:10] = 01000b
#if defined(__CLASSK_CP_SUPPORT__)
        //change to bypass mode        
        while(1) //polling power good state
        {
           if((*VSBST_CON0 & VSBST_VIO28_PG_STATUS)) 
          		break;
        } 
        *VSBST_CON0 |= QI_VSBST_EN;
        AFE_DELAY(1000); //delay 1ms
        while(1)
        {
          	if((*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
          		break;
        } 
#endif        
        *SPK_CON3 = 0x4800;
#if defined(__CLASSK_CP_SUPPORT__)         
        *VSBST_CON0 |= RG_VSBST_BP;
#endif         
        AFE_DELAY(1000);
        *SPK_CON6  = 0x0988; //bypass mode   
        *SPK_CON7  = 0x0180; //vcm fast startup
        AFE_DELAY(2000);     //wait 2ms
        *SPK_CON7  = 0x0100;       
                
        _AFE_Switch_IntAmp(KAL_TRUE);
        *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );
        AFE_DELAY(1000);
        
        // Enable DC compensation
        *AFE_AMCU_CON2 |= 0x8000;
        *AFE_AMCU_CON7 = afe.spk_dc_compensate_value;
    }
    
    {
        kal_uint16 aux_adc_buf[DC_CALI_BUF_LEN];
        kal_int32 K, L;
        kal_int32 DC_offset_sum = 0;
        kal_int32 DC_offset_val[DC_CALI_TIMES]; // for debug
        DCL_HANDLE dcl_hadc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
        ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T GetImmDataOnBooting;
        
        // Setup AuxADC
        {
            GetImmDataOnBooting.u4Channel  = (DCL_UINT32)DC_CALI_CHANNEL;
            GetImmDataOnBooting.u4MeaCount = (DCL_UINT32)DC_CALI_BUF_LEN;
            GetImmDataOnBooting.u2ADCData  = (DCL_UINT16 *)aux_adc_buf;
        }
        
        for (L = 0; L < DC_CALI_TIMES; L++)
        {
            kal_int32 sum_AuxADC_val[2];
            
            for (K = 0; K < 2; K++)
            {
                if (K == 0)
                {   // SPKP
                    *SPK_CON8 |= 0x0200;
                }
                else
                {   // SPKN
                    *SPK_CON8 &= (~0x0200);
                }
                
                // Enable DC calibration
                *SPK_CON8 |= 0x0040;
                
                DclSADC_Control(dcl_hadc_handle, ADC_CMD_GET_IMM_DATA_ON_BOOTING, (DCL_CTRL_DATA_T *)&GetImmDataOnBooting);
                
                // Calculate the value summation
                sum_AuxADC_val[K] = Sum_AuxADC_Value(aux_adc_buf, DC_CALI_BUF_LEN);
                
                // Disable DC calibration
                *SPK_CON8 &= ~0x0040;
            }
            
            // Accumulate DC offset results
            DC_offset_sum   +=  sum_AuxADC_val[0] - sum_AuxADC_val[1];
            DC_offset_val[L] = (sum_AuxADC_val[0] - sum_AuxADC_val[1]) / DC_CALI_BUF_LEN; // for debug
            
            AFE_DELAY(1000);
        }
        
        DclSADC_Close(dcl_hadc_handle);
        
        // Convert DC offset value to mV & compensation value
        {
            afe.Pre_offset_val = (kal_int32)afe.Pre_DC_OFFSET;
            afe.DC_offset_val  = Convert_DC_offset_sum_to_DC_offset_val(DC_offset_sum, DC_CALI_TIMES * DC_CALI_BUF_LEN, afe.Pre_offset_val);
            afe.DC_comp_val    = Convert_DC_offset_val_to_DC_comp_val  (afe.DC_offset_val);
            afe.DC_offset_mV   = Convert_DC_offset_val_to_DC_offset_mV (afe.DC_offset_val);     // for debug
            afe.Pre_offset_mV  = Convert_DC_offset_val_to_DC_offset_mV (afe.Pre_offset_val);    // for debug
            afe.DC_OFFSET      = (kal_int16)afe.DC_offset_val;
        }
    }
    
    // AFE related control flow
    {
        _AFE_Switch_IntAmp(KAL_FALSE);
        AFE_SwitchExtAmplifier(false);

#if defined(__CLASSK_CP_SUPPORT__)         
        //enter boost mode first then close boost function
        *SPK_CON7= 0x0180;                  
        *VSBST_CON0 &= (~RG_VSBST_BP);   
        while(1)
        {
         if((*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
        	 break;
        } 
        *SPK_CON6  = 0x098C; //change to boost
        AFE_DELAY(2000);
        *SPK_CON7  = 0x0100; //vcm high PSRR mode      
        
        *VSBST_CON0 &= (~QI_VSBST_EN);
        while(1)
        {
           if(!(*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
            	break;
        }               
#endif
        // Disable DC compensation
        *AFE_AMCU_CON2 &= ~0x8000;
        *AFE_AMCU_CON7  = 0;
        
        // Turn off hs DAC & buffer        
        AFE_SwitchHSoff();
        
        afe.audio_dl_ena  = KAL_FALSE;
        *AFE_DAC_TEST    &= ~0x6000;
        *AFE_AMCU_CON1   &= ~0x000c;
        
        _AFE_DCLK_CtrlSeq(KAL_FALSE, KAL_TRUE);
    }
#endif    
    // Update AFE static control status
    {
        afe.Callback_DCOffset       = (kal_uint16)afe.DC_OFFSET;
        afe.dc_calibrate_finish     = KAL_TRUE;
        afe.spk_dc_compensate_value = afe.DC_comp_val;
    } 
    
    
    Earphone_DC_Calibration();
  
    
}


#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

kal_int16 AFE_GetDCOffSet(void)
{
   return afe.DC_OFFSET; //mv
}

//==============================================
//             ClassK related
//==============================================
#if defined(__CLASSK_CP_SUPPORT__)
void _AFE_Switch_ChargePump(kal_bool on, AFE_VCP_T mode)
{
   kal_uint16 i = 0;
   //for test usage
   
   if(!L1Audio_IsInitiated())
   {
   	 return;
   }
#if __AFE_CURRENT_SENSOR_ENABLE__
  if(VIBR_Is_In_Calibration())
  {
  	 return;
  }
#endif   	     
#if __AFE_CLASSK_SUPPORT_INTERNAL__ 	     
   {
      kal_uint16 testflag;
      testflag = L1Audio_GetDebugInfo(AUDIO_DEBUG_MISC);
      if (testflag == AUDIO_DBG_VCP_FDISABLE)
      {
         afe.cp_state = CP_STATE_OFF;
         return;
      }
      else if (testflag == AUDIO_DBG_VCP_FENABLE)
      {
      	 kal_uint32  vbat_val  = audio_query_vbat_value() ;
      	 if( vbat_val < 4000000 && on)
      	 {
      	 	  mode = CP_STATE_ON_BOOST;
      	 }	
      }
   }
#endif
#if !__AFE_CLASSK_SUPPORT_INTERNAL__ 
   if(mode == CP_STATE_ON_BOOST)
   {
     // shouldn't reach here
   	   mode = CP_STATE_ON_BYPASS;
   }
#endif
	 if(afe.cp_state == mode)
	 {
	 	 return;
	 }
	 if(on)
	 {
       // off -> boost / bypass
       if(afe.cp_state == CP_STATE_OFF)
       {        
          i=0;
          while(1) //polling power good state
          {
          	if((*VSBST_CON0 & VSBST_VIO28_PG_STATUS)) 
          		break;
          	i++;	
          	ASSERT( i < 40 );
            AFE_DELAY(1000);          		
          } 
          *VSBST_CON0 |= QI_VSBST_EN;
          AFE_DELAY(1000); //delay 1ms
          i=0;
          while(1)
          {
          	if((*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
          		break;
          	i++;	
          	ASSERT( i < 40 );
            AFE_DELAY(1000);
          } 
          *SPK_CON3 = 0x4800;
          if(mode== CP_STATE_ON_BYPASS) 
          {
          	  *VSBST_CON0 |= RG_VSBST_BP;  
          	  AFE_DELAY(1000);       	    
          	  *SPK_CON6  = 0x0988; //bypass mode   
          }
          else if(mode==CP_STATE_ON_BOOST)  
          {
          	 	*SPK_CON6  = 0x098C; //boost mode   
          }          		                
          *SPK_CON7  = 0x0180; //vcm fast startup
	 	 	 	  AFE_DELAY(2000);     //wait 2ms
	 	 	 	  *SPK_CON7  = 0x0100;
       }
       if((afe.cp_state == CP_STATE_ON_BOOST) && (mode== CP_STATE_ON_BYPASS))
       {    	   
       	   *SPK_CON7= 0x0180;
       	   *VSBST_CON0 |= RG_VSBST_BP;    
           AFE_DELAY(1000);       	   
      	 	 *SPK_CON6  = 0x0988; //change to bypass
      	 	 AFE_DELAY(2000);
      	 	 *SPK_CON7  = 0x0100; //vcm high PSRR mode
       }       
       else if((afe.cp_state == CP_STATE_ON_BYPASS) && (mode== CP_STATE_ON_BOOST))
	 	 	 {           
           *SPK_CON7= 0x0180;           
           *VSBST_CON0 &= (~RG_VSBST_BP);   
           i=0;
           while(1)
           {
          	 if((*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
          		 break;
          	 i++;
          	 ASSERT( i < 40 );
             AFE_DELAY(1000);		 
           } 
      	 	 *SPK_CON6  = 0x098C; //change to boost
      	 	 AFE_DELAY(2000);
      	 	 *SPK_CON7  = 0x0100; //vcm high PSRR mode
	 	 	 }      
	 }
	 else
	 {
      //enter boost mode firt then close boost function
      *SPK_CON7= 0x0180;           
      *VSBST_CON0 &= (~RG_VSBST_BP);   
      i=0;
      while(1)
      {
       if((*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
      	 break;
       i++;	
       ASSERT( i < 40 );
       AFE_DELAY(1000);      	 
      } 
      *SPK_CON6  = 0x098C; //change to boost
      AFE_DELAY(2000);
      *SPK_CON7  = 0x0100; //vcm high PSRR mode            
      *VSBST_CON0 &= (~QI_VSBST_EN);
      i=0;
      while(1)
      {
         if(!(*VSBST_CON4 & QI_VSBST_PG_STATUS)) 
          	break;
         i++;
         ASSERT( i < 40 );
         AFE_DELAY(1000);	 	
      } 
	 }
	 afe.cp_state = mode;
}

void AFE_Force_Turnoff_CP()
{
#if __AFE_CLASSK_SUPPORT_INTERNAL__
    if(!afe.cp_th_high && (afe.cp_state != CP_STATE_OFF))
    {	
       _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);
       afe.cp_th_high = KAL_TRUE;    
    }
#endif	 
}

#ifdef __ATV_SUPPORT__
extern kal_bool mATV_Class_K_Implementation(void); //hostlib.h
#endif
kal_bool Check_CP_available(void)
{
#if __AFE_CLASSK_SUPPORT_INTERNAL__	
#ifdef __ATV_SUPPORT__
	kal_bool    atv_result= mATV_Class_K_Implementation();
#else
  kal_bool    atv_result= KAL_TRUE;	
#endif	
	kal_bool    bt_result = KAL_TRUE;
	kal_bool    l1_result = KAL_TRUE;
	kal_uint32  vbat_val  = audio_query_vbat_value();
	kal_uint16  spk_gain  = afe.spk_vol;
	if(atv_result&&bt_result&&l1_result&&(!afe.cp_th_high))
	{
		 //vbat < 4v and spk gain >= 8 dB
		 //if( (vbat_val < 4000000) && (spk_gain >= 144) )
		 if(spk_gain >= 144) // discard battery
		 {
		 	 return KAL_TRUE;
		 }	
	}
#endif		
	return KAL_FALSE;
}
#endif //__CLASSK_CP_SUPPORT__


//==============================================
//             Current sensor
//==============================================
#if __AFE_CURRENT_SENSOR_ENABLE__
extern void VIBR_SetInitCoef(kal_uint16 vs_cf, kal_uint16 vs_df, kal_uint16 vs_mf, kal_bool restore);

void AFE_Retrieve_VIB_CF_Data(kal_int32 data)
{  
   afe.retrieved_cf_data = (kal_uint16)data;
   afe.vib_cali_wait = KAL_FALSE;
}

void AFE_Adc_MsgSend(kal_uint32 msg_name, void *data)
{  
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    va_list varpars;

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_L1SP);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL; 
	 switch (msg_name)
    {
        case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
        {
            bmt_adc_add_item_req_struct *parm_stream;
            parm_stream =
                (bmt_adc_add_item_req_struct*) construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
            parm_stream->adc_handle = (DCL_HANDLE)data;
            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
        {
            bmt_adc_remove_item_req_struct *parm_stream;
            parm_stream = (bmt_adc_remove_item_req_struct*) construct_local_para(sizeof(bmt_adc_remove_item_req_struct), TD_CTRL);
            parm_stream->adc_handle = (DCL_HANDLE)data;
            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        default:
            ASSERT(0);
    }
    SEND_ILM(MOD_L1SP, MOD_BMT, DRIVER_PS_SAP, ilm_ptr);
}

kal_bool AFE_Is_VIBR_Calibration()
{
	 afe.vib_cali_done = VIBR_NVRAM_DATA.VIBR_NVRAM_CALI_DONE;
	 return afe.vib_cali_done;
}

extern void Set_Vibr_Center_Freq(kal_uint16 vibr_center_freq);

static void AFE_Vibrate_Init()
{
	  #define vib_Channel  10
    ADC_CTRL_CREATE_OBJECT_T  adc_measure_cf;
      
	  afe.dcl_cursensor_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);	 
	  adc_measure_cf.u1OwnerId = MOD_MED;
    adc_measure_cf.u1AdcChannel = (DCL_UINT32)vib_Channel;
    adc_measure_cf.u4Period= 1;
    adc_measure_cf.u1EvaluateCount = 1;
    adc_measure_cf.fgSendPrimitive= KAL_TRUE;
    adc_measure_cf.u4Sapid= NULL;
    DclSADC_Control(afe.dcl_cursensor_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_measure_cf);  	
}

kal_uint16 AFE_Vibrate_Calibration()
{ 
	 kal_uint16 CF     = AFE_VS_START_FREQ; 
	 kal_uint16 end_CF = AFE_VS_END_FREQ;
	 kal_uint16 vib_step   = AFE_VS_CALI_STEP;
	 kal_uint16 v_temp  = 0xFFFF;
	 kal_uint16 cf_temp = 0;	  	 
	 
	 Media_SetCalibrationType(MEDIA_CALI_VIB);	 	          
   
   if(afe.vib_first_cali)
   {
   	  AFE_Vibrate_Init(); 
   	  afe.vib_first_cali = KAL_FALSE; 
   }	
    	 
	 //Enable and init current sensor
	 *SPK_CON9 |= 0x9300;
	 *SPK_CON6 &= (~0x0010);	
	 
    VIBR_SetInitCoef(CF,0,0,KAL_FALSE);
    Media_SpkVibration_Enable_Cal(KAL_TRUE);
	 
	 for( ;CF<(end_CF+1); CF+=vib_step)
	 {
	 	  kal_int16 I = 0;
	 	  kal_uint16 I1=0;
      kal_int32 delay = 2 * 1000000 / CF; // Unit: us, Sleep 2 sine wave cycle for current sensor peak chasing
	 	  afe.vib_cali_wait = KAL_TRUE;
	 	  
	 	  Set_Vibr_Center_Freq(CF);
	 	  
      kal_sleep_task(1);
      *SPK_CON6 |=0x0010;
      AFE_DELAY(1000);
      *SPK_CON6 &= (~0x0010);
      AFE_DELAY(delay);
      // auxadc read data.
      AFE_Adc_MsgSend(MSG_ID_BMT_ADC_ADD_ITEM_REQ, (void *)afe.dcl_cursensor_handle);
      
      while(afe.vib_cali_wait == KAL_TRUE)
      {
		      kal_sleep_task(1);
		      I++;
		  }
		  //compare retrieve cf value: replace with min one
		  if (v_temp > afe.retrieved_cf_data)
		  {
		  	 v_temp  = afe.retrieved_cf_data;
		  	 cf_temp = CF;
		  }	
		   	
      AFE_Adc_MsgSend(MSG_ID_BMT_ADC_REMOVE_ITEM_REQ, (void *)afe.dcl_cursensor_handle);     
	 }	 
	 //disable current sensor
	 *SPK_CON9 &= (~0x9300);
	 //center frequency of vib.
	 afe.cali_cf_data = cf_temp;
	 afe.vib_cali_done = KAL_TRUE;
	 VIBR_SetInitCoef(0,0,0,KAL_TRUE);
	 Media_SpkVibration_Enable_Cal(KAL_FALSE);
	 Media_SetCalibrationType(MEDIA_CALI_NONE);
	 return afe.cali_cf_data;
}
#endif //__AFE_CURRENT_SENSOR_ENABLE__


//==============================================
//      Set volume / gain control
//==============================================
static const kal_uint16 SwAgc_Gain_Map[42] =
{
    23, 22, 21, 20, 19, 18, 17, 16, 15,
    14, 13, 12, 11, 10 , 9,
    14, 13, 12, 11, 10 , 9,
    14, 13, 12, 11, 10 , 9,
    14, 13, 12, 11, 10 , 9,
    8, 7, 6, 5, 4, 3, 2, 1, 0
};

static const kal_uint16 HwPga_Gain_Map[4] =
{
    3,  //+18dB
    2,  //+12dB
    1,  //+6dB
    0   //0dB
};

static void UpdateAGCGain(kal_uint16 vol)
{
   kal_uint8  agc_ul_gain, pga_ul_gain = 0;
   kal_int16   i,j;   
      
   i = afe.mic_volume + 10;
   j = 63-i;
   if(j>41) j=41;
      
   if(i>48)
     pga_ul_gain = HwPga_Gain_Map[0];
   else if(i>42)   
   	 pga_ul_gain = HwPga_Gain_Map[1];
   else if(i>36)   
   	 pga_ul_gain = HwPga_Gain_Map[2];
   else
   	 pga_ul_gain = HwPga_Gain_Map[3];	                

   agc_ul_gain = SwAgc_Gain_Map[j];      
   *DSP_AGC_GAIN = agc_ul_gain;      
   
   vol = pga_ul_gain;
   afe_prompt_trace(MOD_L1SP, "UpdateAGCGain (PGA=%d, AGC=%d) \r\n", pga_ul_gain*6, agc_ul_gain);
   
   //6261: *ABBA_VBITX_CON0[8:6]: 0db~+18db, 6db per step 
   *ABBA_VBITX_CON0 = ((*ABBA_VBITX_CON0&(~0x01C0)) | (vol<<6));
   afe.agc_reset_flag = KAL_FALSE;
}

static void UpdateSPKGain()
{
	 kal_int16 I, v_lowest;
   kal_uint16 val, gainflag;
   
   v_lowest = -1;

   for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
      if( afe.sp_flag & (1<<I) ) {
         val = (kal_uint16)afe.aud[I].out_dev;
         if( val & (L1SP_BUFFER_0|L1SP_BUFFER_1) )
            v_lowest = I;
      }
   }
   gainflag = 0;
   if( v_lowest >= 0)
   {
      if( (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) //RCV=SPK 
         gainflag = 1;
   }
   if (gainflag)
      *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(0x0<<4) );         // -6dB
   else
      *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );  // 12dB
}

static void UpdatePGAGain( kal_uint8 aud_func )
{
   kal_uint16 volume    = afe.aud[aud_func].volume;
   kal_bool HS_gain     = KAL_FALSE;  // FALSE: HP Gain, TRUE: HS Gain
   kal_bool HP_gain_adj = KAL_FALSE;
   kal_uint16 amp_gain;
   
   UpdateVAPDN(0);

   if((afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) )
   {
      if((afe.aud[aud_func].out_dev & L1SP_BUFFER_ST) )
         HP_gain_adj = KAL_TRUE;	

   #if !HP_EN_UNDERSPK
      if((afe.aud[aud_func].out_dev & L1SP_STEREO2MONO) )
         HP_gain_adj = KAL_FALSE;
   #endif
   }
   
   if( (afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) || (afe.voice_dl_ena) )
   {
#ifdef __LINE_IN_SUPPORT__
      if(extPA_underHP && (aud_func == L1SP_LINEIN)) 
      {
         HS_gain = KAL_FALSE;       
      }
      else
#endif   	
      HS_gain = KAL_TRUE;
   }
   
   if(HS_gain)
   {
      kal_uint16 again_lowerbound;
      if(volume > VGAIN_UPBOUND_SETTING) // 240 upper bound
         volume = VGAIN_UPBOUND_SETTING;

      if(HP_gain_adj)
         again_lowerbound = VGAIN_DUALSPEAKER_LOWBOUND_SETTING;
      else
         again_lowerbound = VGAIN_LOWBOUND_SETTING;
      if(volume < again_lowerbound) // 128 or 0 lower bound
         volume = again_lowerbound;
      amp_gain = MINIMUM_VGAIN_SETTING - (kal_uint8)(volume>>3);
   #ifdef __VIBRATION_SPEAKER_SUPPORT__
      if( (afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) && (aud_func == L1SP_AUDIO) && afe.vibrate ){
         amp_gain = afe.vib_ampgain;
         VIBR_Vibration_UpdateGain(amp_gain, afe.class_d_gain);
      }
   #endif
      
      *ABBA_AUDIODL_CON13 = (*ABBA_AUDIODL_CON13 & 0x83FF) | (kal_uint16)(amp_gain<<10);
      if(HP_gain_adj)
      {
#ifdef __VIBRATION_SPEAKER_SUPPORT__
        amp_gain = amp_gain > MINIMUM_AGAIN_SETTING ? MINIMUM_AGAIN_SETTING : amp_gain;
#endif
        *ABBA_AUDIODL_CON13 = (*ABBA_AUDIODL_CON13&0xFC21) | (kal_uint16)(amp_gain<<1) | (kal_uint16)(amp_gain<<6);  
      }
   }
   else
   {
      amp_gain = AFE_AGainRangeConvert(volume >> 4);
      if(volume > AGAIN_UPBOUND_SETTING) // 160 upper bound
         volume = AGAIN_UPBOUND_SETTING;
      if(volume < AGAIN_LOWBOUND_SETTING) // 104 lower bound
         volume = AGAIN_LOWBOUND_SETTING;
      amp_gain = MINIMUM_AGAIN_SETTING - (kal_uint8)((volume-AGAIN_LOWBOUND_SETTING)>>2);   
      *ABBA_AUDIODL_CON13 = (*ABBA_AUDIODL_CON13&0xFC21) | (kal_uint16)(amp_gain<<1) | (kal_uint16)(amp_gain<<6);
   }
#if __AFE_CLASSK_SUPPORT_INTERNAL__
   afe.spk_vol = volume;
#endif   
   UpdateSPKGain();

   if( afe.mic_flag && !afe.mic_mute && !afe.mute) {
      //Normal recording
      UpdateAGCGain((kal_uint16)afe.mic_volume);
   } 

   if( (aud_func == L1SP_SPEECH) )
      UpdateSidetone( (kal_int8)(volume >> 4) );
   else
      *DP_SIDETONE_VOL = 0;
   
}


static const kal_uint16 SideToneTable[] = {
   32767, 26027, 20674, 16422, 13044, 10361, 8230, 6537,       /* 2 dB per step */
    5193,  4125,  3276,  2602,  2066,  1641, 1304, 1035,
     822,   653,   519,   412,   327,   260,  206,  164
};


void UpdateSidetone( kal_int8 vol )
{
   kal_int8 J;
   kal_uint32 R;
   kal_uint16 sidetone_vol;

   if(afe.sidetone_disable || afe.sidetone_volume == 0) {
      *DP_SIDETONE_VOL = 0;
      return;
   }
   sidetone_vol = afe.sidetone_volume;

   {
      kal_int16 i,j;
      kal_uint8  agc_ul_gain = 0;
      
      i = afe.mic_volume + 10;
      j = 63-i;
      if(j>41) j=41;
         
      agc_ul_gain = SwAgc_Gain_Map[j];    
         
      i = agc_ul_gain;
      i = i << 3;
      sidetone_vol += i;   
         
      kal_prompt_trace(MOD_L1SP,"sidetone %d %d", afe.sidetone_volume, sidetone_vol);
      if(sidetone_vol > 255 )
         sidetone_vol = 255;    
   }          

   R = (kal_uint32)(sidetone_vol & 0xF);
   vol = vol + 1 - (kal_int8)(sidetone_vol >> 4);

   if( vol < 0 )
      vol = 0;

   if(vol > 23) vol = 23;
   J = ( vol == 0 )? 0: vol-1;
   *DP_SIDETONE_VOL = (kal_uint16)(((kal_uint32)SideToneTable[vol]*(16-R) + (kal_uint32)SideToneTable[J]*R) >> 4);
}

static void AVolumeRampDown()
{
	 kal_int32 I;
   kal_int16 i2Gain;
   kal_uint16 OrgValue;
   
   i2Gain = (kal_int16)(*ABBA_AUDIODL_CON13 & ~0xFFE1); //R gain = L gain ; extract one
   i2Gain = i2Gain>>1; //LSB ignore
   OrgValue = *ABBA_AUDIODL_CON13&0xFC21;               //get original ADUIO_CON2 setting
   
   for (I=i2Gain; I<=MINIMUM_AGAIN_SETTING; I++)
   {
      *ABBA_AUDIODL_CON13 = (I<<1) | (I<<6) | (OrgValue & 0xFC21);  //R mod_gain | L mod_gain | original
       AFE_DELAY(500);
   }
   
   i2Gain = (kal_int16)((*ABBA_AUDIODL_CON13 & (~0x83FF))>>10);
   OrgValue = *ABBA_AUDIODL_CON13&0x83FF;
   
   if((!afe.loopback) && (!afe.pcmifloopback))
   {
      for (I=i2Gain; I<=MINIMUM_VGAIN_SETTING; I++)
      {
         *ABBA_AUDIODL_CON13 = (I<<10) | (OrgValue & 0x83FF);
         AFE_DELAY(500);          
      }
   }   
   
   *ABBA_AUDIODL_CON16 |= (RG_AMUTER|RG_AMUTEL); // mute R and L at digital
}

static void AFE_CalculateVolume(kal_uint8 aud_func)
{
   if( (afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1|L1SP_BUFFER_ST|L1SP_BUFFER_EXT) ) )
   {
      kal_int16 again_lowerbound = VGAIN_LOWBOUND_SETTING;
      kal_int8 digital_gain_index = afe.aud[aud_func].digital_gain_index;
      kal_uint16 volume           = afe.aud[aud_func].volume;
      
      
      if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_EXT) ))
      {
         if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_ST) ))
            again_lowerbound = VGAIN_DUALSPEAKER_LOWBOUND_SETTING;
      #if !HP_EN_UNDERSPK
         if((afe.aud[aud_func].out_dev & L1SP_STEREO2MONO) )
            again_lowerbound = VGAIN_LOWBOUND_SETTING;
      #endif
      }
      else
      {
         if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1) ))
            again_lowerbound = VGAIN_LOWBOUND_SETTING;
         else
            again_lowerbound = AGAIN_LOWBOUND_SETTING;
      }

      if(volume<again_lowerbound) //lower bound is 104
      { 
         kal_int16 tmp_gain_index;
         tmp_gain_index = (kal_int16)digital_gain_index;
         tmp_gain_index -= (((again_lowerbound-volume)>>2)<<1);
   
         if(tmp_gain_index>-128)
            digital_gain_index = (kal_int8)tmp_gain_index;
         else
            digital_gain_index = -128;
   
         afe.aud[aud_func].volume = volume;
         afe.aud[aud_func].digital_gain_index = digital_gain_index;
         afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index);
       }
   }
}

void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index )
{
   kal_uint8 digital_gain_index1 = digital_gain_index;
   kal_uint8 volume = volume1;

   if (AFE_GetNVRAMDigitalGainSupport())
   {
      digital_gain_index1 = volume1 & 0x0F;
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = digital_gain_table[digital_gain_index1];
      afe_prompt_trace(MOD_L1SP, "vol, digital_index, digital_gain = (0x%x, 0x%x, 0x%x) \r\n", volume, digital_gain_index1, afe.aud[aud_func].digital_gain);
   }
   else
   {
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index1);
   }
   
   AFE_CalculateVolume(aud_func);
   
#if defined(EXT_DAC_SUPPORT) 
   // Note : extrenal DAC is used as earphone or TV-out only 
   // case 1 : play amr with melody volume (7-level case)  
   if(aud_func == L1SP_VOICE && (afe.aud[L1SP_VOICE].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      kal_uint32 i, type;
      if(!(afe.aud[L1SP_VOICE].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // for play both case : apply AFE gain is OK 
      {
      #if defined(TV_OUT_SUPPORT)   
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {
            // find the closest level
            if(aud_get_volume_gain(VOL_HEADSET, type, i) > volume1) 
               break;
         }
         if(i > 0) i--;
         afe.aud[aud_func].volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, i); // apply speech volume       
      }    
   }
   
   // case 2 : play Audio both on earphone and LoudSpk 
   if(aud_func == L1SP_AUDIO && (afe.aud[L1SP_AUDIO].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      if((afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // play both 
      {
         kal_uint32 i, type;
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {              
            //  find the closest level 
            if(aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MEDIA, i) > volume1)
               break;            
         }          
         if(i > 0) i--;
      #if defined(TV_OUT_SUPPORT)
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         afe.ext_dac_aud_vol = aud_get_volume_gain(VOL_HEADSET, type, i);
      }
      else 
         afe.ext_dac_aud_vol = volume1;  
   }
   
   if(afe.ext_dac_i2s_on)
   { 
      if(((SND_SRC_MAP>>aud_func*2)&3) == SRC_AUDIO_DAC) 
      {            
         EXT_DAC_SetVolume(afe.aud[aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);  
      }
   }
#endif
   
   AFE_SetRefresh();
   if(kal_if_hisr())
      kal_dev_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
   else
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);	
}

void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
   kal_uint8 vol_step, vol_step_unit;
   kal_uint8 a_gain, a_atten, d_atten;
   kal_trace(TRACE_STATE, AFE_SET_LEVEL_VOLUME, aud_func, MaxAnalogGain, step, level);
#if defined(EXT_DAC_SUPPORT)
   {
      kal_uint8 out_dev;
      // Note : extrenal DAC is used as earphone or TV-out only 
      // case 1 : play amr with melody volume (7-level case)  
      if(aud_func == L1SP_VOICE && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         if(!(out_dev & L1SP_BUFFER_EXT)) // for play both case : apply AFE gain is OK 
         {
            // use AFE gain 
            aud_get_melody_volume_setting(VOL_NORMAL, &MaxAnalogGain, &step);
         }
      }
   
      // case 2 : play Audio both on earphone and LoudSpk 
      if(aud_func == L1SP_AUDIO && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         uint8 ext_dac_max_vol, ext_dac_step;
         if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) // play both 
         {
         #if defined(TV_OUT_SUPPORT)
            if(audio_tv_cable_in)
               aud_get_melody_volume_setting(VOL_TV_OUT, &ext_dac_max_vol, &ext_dac_step);
            else 
         #endif    
               aud_get_melody_volume_setting(VOL_HEADSET,&ext_dac_max_vol, &ext_dac_step);
         }
         else 
         {
            ext_dac_max_vol = MaxAnalogGain;  
            ext_dac_step = step;
         }
         a_gain = ext_dac_max_vol / L1SP_EXT_DAC_STEP;

         a_atten = (ext_dac_step * level) / L1SP_EXT_DAC_STEP_UNIT; 
         d_atten = (ext_dac_step * level) % L1SP_EXT_DAC_STEP_UNIT; 
         ASSERT(d_atten == 0); // For current EXT_DAC interface, this must be 0.
      
         if(a_gain >= a_atten)  
            a_gain -= a_atten;
         else 
         {
            a_atten -= a_gain;
            a_gain = 0;
            d_atten += a_atten * L1SP_EXT_DAC_STEP_UNIT;
            if(d_atten > 128)
               d_atten = 128;
         }
         afe.ext_dac_aud_vol = a_gain * L1SP_EXT_DAC_STEP;  

         if(afe.ext_dac_i2s_on)                        
            EXT_DAC_SetVolume(out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);
      }
   }
#endif 
   vol_step = 4;   
   vol_step_unit = 2; // 1dB = 2 * 0.5dB

   a_gain = MaxAnalogGain / vol_step;

   a_atten = (step * level) / vol_step_unit; 
   d_atten = (step * level) % vol_step_unit; 

   if(a_gain >= a_atten)  
      a_gain -= a_atten;
   else 
   {
      a_atten -= a_gain;
      a_gain = 0;
      d_atten += a_atten * vol_step_unit;
      if(d_atten > 128)
         d_atten = 128;
   }

   if(a_gain == 0)
      afe.aud[aud_func].volume = a_gain * vol_step + 1;   // plus 1 to avoid volume == 0 (this will turn off speaker)
   else
      afe.aud[aud_func].volume = a_gain * vol_step;
   afe.aud[aud_func].digital_gain_index = 0 - d_atten; 
   afe.aud[aud_func].digital_gain = _converted_digital_gain( 0-d_atten);       
   
   AFE_CalculateVolume(aud_func);
   AFE_SetRefresh();
}


//==============================================
//       Over current detect
//==============================================
kal_bool AFE_SPKAMP_OCDetect(void)
{
#if __AFE_OC_DETECTION__
   kal_bool oc_flag = KAL_FALSE;
   uint8 oc_enabled = 0;
   uint8 oc_autoffed =0;
   kal_uint16 aud_temp_id;
 
   aud_temp_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_temp_id );
   
   kal_sleep_task(10);
   //enable OC detection
   if( (*SPK_CON0 & SPK_OC_AUTOFF) == 0x0000 )
      *SPK_CON0 |= SPK_OC_AUTOFF;
   else
      oc_autoffed = 1;
   if( (*SPK_CON7 & SPK_CLASSAB_OC_EN) == 0x0000 )
      *SPK_CON7 |= SPK_CLASSAB_OC_EN;
   else
      oc_enabled = 1;
   kal_sleep_task(20);
   //Check OC flag
   if( (*SPK_CON0&SPK_OC_FLAG) )
      oc_flag = KAL_TRUE;
   if(!oc_enabled)
      *SPK_CON7 &= (~SPK_CLASSAB_OC_EN);
   if(!oc_autoffed)
      *SPK_CON0 &= (~SPK_OC_AUTOFF);
   
   L1Audio_ClearFlag( aud_temp_id );
   L1Audio_FreeAudioID( aud_temp_id );

   return oc_flag;
#else
   return KAL_FALSE;
#endif //__AFE_OC_DETECTION__	 
}


//==============================================
//       AMP/DAC  control
//==============================================
static void AFE_SwitchHPon(void)
{
#ifdef __LINE_IN_SUPPORT__
    if((afe.sp_flag & (1<<L1SP_LINEIN)) && (!afe.linein_on))
    {      
       *ABBA_AUDIODL_CON11|= 0x0003;
       *ABBA_AUDIODL_CON0 |= RG_AUDHSPWRUP; //HS buffer power on [must]
   	   AFE_DELAY(10);
       *ABBA_AUDIODL_CON5 |= 0x0001; 
       AFE_DELAY(10); 
       *ABBA_AUDIODL_CON0 |= 0x0001;
       AFE_DELAY(10); 
       *ABBA_AUDIODL_CON2 |= 0x0001;   
       *ABBA_AUDIODL_CON0  = 0x001D;
       *ABBA_AUDIODL_CON2 &=(~0x0001);
       AFE_DELAY(5); 
       *ABBA_AUDIODL_CON5 &=(~0x0001); 
       *ABBA_AUDIODL_CON0  = 0x000D;
       *ABBA_AUDIODL_CON1 |= 0x4240;   
       *ABBA_AUDIODL_CON4  = 0x0139;	
       *ABBA_AUDIODL_CON10|= 0x0010;
       afe.linein_on =  KAL_TRUE;
    }
    else
#endif    	
    {
       kal_uint16 restore, tmp;
       *ABBA_AUDIODL_CON11 |= 0x0003;
       *ABBA_AUDIODL_CON7  |= 0x0003;
       *ABBA_AUDIODL_CON0  |= (RG_AUDDACRPWRUP|RG_AUDDACLPWRUP);
       *ABBA_AUDIODL_CON1  &=(~0x6000);
       *ABBA_AUDIODL_CON1  |= 0x4000;  // enable HP zcd
       restore =  *ABBA_AUDIODL_CON13;
       *ABBA_AUDIODL_CON13 = (restore & ~0x03FF) | 0x02F7;  // set to 0dB and enable zcd
       *ABBA_AUDIODL_CON12 |=(audzcdenable);
#if __AFE_HP_DC_CALIBRATION__
       //enable compensation
       {
         *AFE_AMCU_CON2 |= 0x8000;  
         *AFE_VMCU_CON2 |= 0x8000;
         *AFE_AMCU_CON6 = afe.hp_dc_compensate_value_r;
         *AFE_AMCU_CON7 = afe.hp_dc_compensate_value_l;
         *AFE_VMCU_CON4 = afe.hp_dc_compensate_value_l;
       }
#endif    
       *ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP; //HS buffer power on [must]
   	   AFE_DELAY(10);
       *ABBA_AUDIODL_CON5 |= 0x0001; 
       AFE_DELAY(10); 
       *ABBA_AUDIODL_CON0 |= 0x0001;
       AFE_DELAY(10); 
       *ABBA_AUDIODL_CON2 |= 0x0001;                     
       *ABBA_AUDIODL_CON0 |= 0x000C; 
       *ABBA_AUDIODL_CON2 &=(~0x0001);
       //AFE_DELAY(5);       
       tmp  = *ABBA_AUDIODL_CON1 & (~0x1FF0); // to avoid set path pop
       *ABBA_AUDIODL_CON1 = tmp | 0x0120;      
       *ABBA_AUDIODL_CON5 &= (~0x0001); 
       *ABBA_AUDIODL_CON0 &= (~RG_AUDHSPWRUP);
       *ABBA_AUDIODL_CON4 &= (~(RG_ADEPOP_EN|RG_DEPOP_VCM_EN));
       *ABBA_AUDIODL_CON13 = restore;	
    }
    afe.hp_on = KAL_TRUE;
}

static void AFE_SwitchHPoff(void)
{ 
#ifdef __LINE_IN_SUPPORT__
	  if(afe.linein_on)
    {
    	 *ABBA_AUDIODL_CON0  &= (~0x000D);
       AFE_DELAY(10);   
       *ABBA_AUDIODL_CON1  &= (~0x03F0);      
	     *ABBA_AUDIODL_CON4  |= (RG_DEPOP_VCM_EN);
       AFE_DELAY(10);
       *ABBA_AUDIODL_CON4  |= (RG_ADEPOP_EN);
       AFE_DELAY(10);
       *ABBA_AUDIODL_CON10 &= (~0x0010); 
       afe.linein_on =  KAL_FALSE;   
    }
    else
#endif    	
    {	  
	     kal_uint16 OrgValue = *ABBA_AUDIODL_CON13;
	     *ABBA_AUDIODL_CON4  |= (RG_DEPOP_VCM_EN);
       AFE_DELAY(10);
       *ABBA_AUDIODL_CON4  |= (RG_ADEPOP_EN);
       AFE_DELAY(10);
       *ABBA_AUDIODL_CON12 &= (~audzcdenable);
       *ABBA_AUDIODL_CON13  = (MINIMUM_AGAIN_SETTING<<1) | (MINIMUM_AGAIN_SETTING<<6) | (OrgValue & 0xFC21);
       *ABBA_AUDIODL_CON0  &= (~(RG_AUDIBIASPWRUP|RG_AUDHPRPWRUP|RG_AUDHPLPWRUP));
       *ABBA_AUDIODL_CON1  &= (~0x03F0); 
#if __AFE_HP_DC_CALIBRATION__
        //disable compensation
        {
          *AFE_AMCU_CON2 &= ~0x8000;
          *AFE_VMCU_CON2 &= ~0x8000;
        }
#endif    
     }
    afe.hp_on = KAL_FALSE;
}

static void AFE_SwitchHSon(void)
{
	  kal_uint16 restore;
	  *ABBA_AUDIODL_CON11 |= 0x0003;
	  *ABBA_AUDIODL_CON7  |= 0x0003;
	  *ABBA_AUDIODL_CON0 |= (RG_AUDDACRPWRUP|RG_AUDDACLPWRUP);
	  *ABBA_AUDIODL_CON1 &=(~0x6000);
    *ABBA_AUDIODL_CON1 |= 0x6000;  // enable HS zcd
    restore =  *ABBA_AUDIODL_CON13; 
    *ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000; // set to 0dB and enable zcd
	  *ABBA_AUDIODL_CON12 |=(audzcdenable);
    *ABBA_AUDIODL_CON13 = restore;
	  *ABBA_AUDIODL_CON1 &= (~0x1FF0);
    *ABBA_AUDIODL_CON1 |= 0x0800;
    *ABBA_AUDIODL_CON0 |= RG_AUDHSPWRUP; //HS buffer power on
#if HP_EN_UNDERSPK
    if(afe.dc_calibrate_finish)
    // force to turn on earphone under spk
    { 
    	*ABBA_AUDIODL_CON2 |= 0x0001;          
    	*ABBA_AUDIODL_CON0 |= 0x000D; 
    	AFE_DELAY(1);  
    	*ABBA_AUDIODL_CON2 &=(~0x0001);
      *ABBA_AUDIODL_CON1 |= 0x0090;   
    }
#endif            
    afe.hs_on = KAL_TRUE;
}

static void AFE_SwitchHSoff(void)
{ 
	 kal_uint16 OrgValue = *ABBA_AUDIODL_CON13;	 
	 *ABBA_AUDIODL_CON12 &= (~audzcdenable);
	 *ABBA_AUDIODL_CON13  = (MINIMUM_VGAIN_SETTING<<10) | (OrgValue & 0x83FF); 
   *ABBA_AUDIODL_CON1  &= (~0x1C00);
   *ABBA_AUDIODL_CON0  &= (~RG_AUDHSPWRUP);
#if HP_EN_UNDERSPK
    // force to turn off earphone under spk
    *ABBA_AUDIODL_CON0 &= (~0x000D); 
    *ABBA_AUDIODL_CON1 &= (~0x0090); 	  
#endif
   afe.hs_on = KAL_FALSE;
}

static void AFE_Switch_No_VoiceAudAmp()
{
   // If there is no aud function which wants to output through
   // Voice Amp-0 or Voice Amp-1 or Audio Amp.
   // Update MIC volume here for the scenario that microphone is turned on with no speaker on 
   if( afe.mic_flag && !afe.mic_mute && !afe.mute) 
   {
      UpdateAGCGain((kal_uint16)afe.mic_volume);
   }
   UpdateVAPDN( 0 );

#if __AFE_AUDIO_DELAY_OFF__
   if( (afe.Audio_close_delay<0) && (afe.Audio_close_delay_expired==KAL_FALSE) )
      afe.Audio_close_delay = afe.AUDIOCLOSEDELAY; 
                 
   if(AUDIO_CLOSE_DELAY==0 || afe.Audio_close_delay==0)
      afe.Audio_close_delay_expired = KAL_TRUE;
      
 #ifdef BGSND_ENABLE
   if( (!afe.Pre_OutDev) || (AFE_IsKaraok()) || (afe.sp_flag) || (AM_IsBgsndOn()) ) //voice out
 #else
   if( (!afe.Pre_OutDev) || (AFE_IsKaraok()) || (afe.sp_flag) ) //voice out
 #endif 
   {
      if( (afe.sp_flag == (1 << L1SP_AUDIO)) && ( afe.aud[L1SP_AUDIO].volume == 0 || afe.aud[L1SP_AUDIO].mute == KAL_TRUE) )
      {
      }
      else{
         afe.Audio_close_delay = 0;
         afe.Audio_close_delay_expired = KAL_TRUE;
      }
   }
   else //audio out
   {
      if(afe.Pre_InSrc==SRC_EXT_INPUT) //SRC_AUDIO_DAC, SRC_VOICE_DAC
      {
         afe.Audio_close_delay = 0;
         afe.Audio_close_delay_expired = KAL_TRUE;
      }
   }

#if defined(__VAD_SUPPORT__)
   if( VAD_IsEnable() ) // force turn off clock
   {
      afe.Audio_close_delay = 0;
      afe.Audio_close_delay_expired = KAL_TRUE;
   }
#endif
#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
   if ( PCM_CLK_Is_Enabled() )
   {
      afe.Audio_close_delay = 0;
      afe.Audio_close_delay_expired = KAL_TRUE;
   }
#endif
#ifdef __LINE_IN_SUPPORT__
   if(extPA_underHP) // force turn off clock
   {
      afe.Audio_close_delay = 0;
      afe.Audio_close_delay_expired = KAL_TRUE;
   }
#endif
   if( (afe.Audio_gpt_on==KAL_FALSE) && (afe.Audio_close_delay>0) )
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = afe.Audio_close_delay;
      start.pfCallback = Audio_DelayCloseHandler;
      start.vPara = 0;
      DclSGPT_Control(afe.Audio_gpt,  SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
      afe.Audio_gpt_on = KAL_TRUE;
   
      _AfeSetHardwareMute(true);
      afe.afe_state = AFE_STATE_IDLE_OFF;
   }
#else
   afe.Audio_close_delay_expired = KAL_TRUE;
#endif
   afe_prompt_trace(MOD_L1SP,"AFE noAVamp:delayoff_%x; pre_%x; karaok_%x; sp_%x",afe.Audio_close_delay_expired,afe.Pre_OutDev,AFE_IsKaraok(),afe.sp_flag);   

#if __AFE_PA_DELAY_OFF__
   if(afe.pa_delay == -1 && (afe.afe_state != AFE_STATE_OFF))
   {
      if(!L1SP_IsBluetoothOn())
      {
         afe.pa_delay = AFE_PA_DELAY_NUM;
         AFE_SetRefresh();
      }
   }
#endif

#if __AFE_PA_DELAY_OFF__
   if(afe.Audio_close_delay_expired && afe.pa_delay==0)
#else
   if(afe.Audio_close_delay_expired)
#endif
   {
      kal_uint16 OrgValue = *ABBA_AUDIODL_CON13;
      AVolumeRampDown();
      
      if(afe.powerOffWait > 0 ){
         return;
      }
      else if(afe.powerOffWait == 0){
         *ABBA_AUDIODL_CON4 &=(~RG_ADEPOP_EN);
         *ABBA_AUDIODL_CON4 &=(~RG_DEPOP_VCM_EN);
         *ABBA_AUDIODL_CON8 &=(~RG_LCLDO_TBST_EN);
      }
      
      if(afe.audio_dl_ena)
      {
         if( (afe.system_poweroff) && (afe.Pre_InSrc == SRC_AUDIO_DAC) && (afe.powerOffWait == -1) && (afe.audio_fs == ASP_FS_32K) )
         {
            *ABBA_AUDIODL_CON4 &=(~RG_DEPOP_CHARGEOPTION);
            afe.powerOffWait = 250;
            return;
         }
         if(afe.hp_on)
         {
            AFE_SwitchHPoff();         
         }
         if(afe.hs_on)
         {
         	  AFE_SwitchHSoff();
         }
         if(!afe.audio_clk_ena)
         {	
             *ABBA_AUDIODL_CON0  &= (~(RG_AUDDACRPWRUP|RG_AUDDACLPWRUP));
             *ABBA_AUDIODL_CON7  &= (~0x0003);
             *ABBA_AUDIODL_CON11 &= (~0x0003);     
         }
         afe.audio_dl_ena = KAL_FALSE;
         afe.powerOffWait = -1;
      }
      if(afe.voice_dl_ena)
      {
         AFE_SwitchHSoff();  
         if(!afe.voice_clk_ena)
         {
             *ABBA_AUDIODL_CON0  &= (~(RG_AUDDACRPWRUP|RG_AUDDACLPWRUP));
             *ABBA_AUDIODL_CON7  &= (~0x0003);
             *ABBA_AUDIODL_CON11 &= (~0x0003);       
         }
         afe.voice_dl_ena = KAL_FALSE;
      }     
      *AFE_AMCU_CON1 &= (~0x4000);     
      #if __AFE_PA_DELAY_OFF__
         afe.pa_delay = -1;
      #endif
      afe.afe_state = AFE_STATE_OFF;
   }
   
}
   
static void AFE_Switch_VoiceDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{      
   if(!afe.audio_dl_ena)
   {      
      // audio DL via spk using voice path in 6261
      if( (( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) )) && (!extPA_underHP) )
      {
      	  AFE_SwitchHSon();  	  
      }
      else
      {
          AFE_SwitchHPon();
      }
      afe.audio_dl_ena = KAL_TRUE;
      afe.voice_dl_ena = KAL_FALSE;
   }
   else //hp and hs switch during playback
   {
   	   kal_bool hp_on ;  
   	   if( (( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) )) && (!extPA_underHP) )
       {
       	  hp_on = KAL_FALSE;
       }	  
       else
       {
       	  hp_on = KAL_TRUE;
       } 
   	   
   	   if(afe.hs_on)
   	   {
           if(hp_on)
           {	
   	   	      AFE_SwitchHSoff(); //turn off HS first
   	   	      AFE_SwitchHPon();  //then HP on 	
   	   	   }   	      	   	    
   	   }
   	   else if(afe.hp_on)
   	   {
           if(!hp_on)
           {
              AFE_SwitchHPoff();  //turn off HP first 
              AFE_SwitchHSon();   //then HS on
           }
#ifdef __LINE_IN_SUPPORT__
           else if(hp_on && (afe.sp_flag & (1<<L1SP_LINEIN)) &&(!afe.linein_on))
           {
           	  AFE_SwitchHPoff();  //turn off HP first 
           	  AFE_SwitchHPon();   //then HP line-in on
           }
#endif           
   	   }
   	   else if(!afe.hs_on && !afe.hp_on)
   	   {
   	   	  if(hp_on)
   	   	  {
   	   	  	 AFE_SwitchHPon();
   	   	  }
   	   	  else
   	   	  {
   	   	  	 AFE_SwitchHSon();
   	   	  }
   	   }	   	   
   }	
}

static void AFE_Switch_VoiceDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
	 *AFE_AMCU_CON1 &= (~0x4000);
	 if(!afe.voice_dl_ena)
   {                        
      AFE_SwitchHSon();
      afe.voice_dl_ena = KAL_TRUE;
      afe.audio_dl_ena = KAL_FALSE;
   }
}

static void AFE_Switch_AudDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( (afe.aud[a_lowest].out_dev&L1SP_STEREO2MONO) ) 
      *AFE_AMCU_CON1 |= 0x4000;
   else
      *AFE_AMCU_CON1 &= (~0x4000);

   AFE_Switch_VoiceDAC_AudAMP(v_lowest, a_lowest);
}

static void AFE_Switch_AudDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   AFE_Switch_VoiceDAC_VoiceAMP(v_lowest, a_lowest);
}

static void AFE_Switch_AudAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(L1SP_TONE == a_lowest || L1SP_KEYTONE == a_lowest){
      afe.Pre_InSrc = (DTMF_MCU_IsPlaying()) ? SRC_AUDIO_DAC : SRC_VOICE_DAC;
   }else{
      afe.Pre_InSrc = (SND_SRC_MAP>>a_lowest*2)&3;
   } 
   
   switch(afe.Pre_InSrc) {
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         if( afe.fir_flag & (1<<a_lowest) ){
            *COMPEN_BLOCK_FLT_PAR_PTR |= 3;
         }else if (!afe.toneLoopbackRec){
            *COMPEN_BLOCK_FLT_PAR_PTR &= (~3);
         }
         //// turn on only BIAS & DAC
         AFE_Switch_VoiceDAC_AudAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
	  case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x), SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_AudAMP(v_lowest, a_lowest);
         break;
      
         //afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         //break;
   }
   
   UpdatePGAGain( a_lowest );
}

static void AFE_Switch_VoiceAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(L1SP_TONE == v_lowest || L1SP_KEYTONE == v_lowest){         
      afe.Pre_InSrc = (DTMF_MCU_IsPlaying()) ? SRC_AUDIO_DAC : SRC_VOICE_DAC;
   }else{
      afe.Pre_InSrc = (SND_SRC_MAP>>v_lowest*2)&3;
   } 
   
   switch(afe.Pre_InSrc) {
      /// determine the source for the aud function v_lowest
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         if( afe.fir_flag & (1<<v_lowest) ){
            *COMPEN_BLOCK_FLT_PAR_PTR |= 3;
         }else if (!afe.toneLoopbackRec){
            *COMPEN_BLOCK_FLT_PAR_PTR &= (~3);
         }
         AFE_Switch_VoiceDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         break;
   }
   
   UpdatePGAGain( v_lowest );
}


//==============================================
//   AFE Event Handler  (under audio task)
//==============================================
void AFE_Chip_Event_Handler( void *data )
{
	  kal_int16 v_lowest = -1, a_lowest = -1;
	  afe_prompt_trace(MOD_L1SP,"AFE EventHdlr:spflag:%x",afe.sp_flag);
    if( afe.sp_flag ) 
    {
    	 SearchSpkFlag( &v_lowest, &a_lowest );
       afe_prompt_trace(MOD_L1SP,"AFE EventHdlrSPEnable:a_%x, v_%x",a_lowest,v_lowest);
       if(v_lowest >=0 || a_lowest >=0 )
       {
          *ABBA_AUDIODL_CON16 &= (~(RG_AMUTER|RG_AMUTEL));
       }
#if defined(__BT_SUPPORT__)
         if (((a_lowest < 0) && (v_lowest < 0) && AM_IsBluetoothOn()) || ((a_lowest < 0) && (v_lowest < 0) && afe.bt_flag))
         {
             if(afe.afe_state==AFE_STATE_IDLE_OFF)
             {
               #if __AFE_AUDIO_DELAY_OFF__
                  if(afe.Audio_close_delay>0)
                  {
                     if(afe.Audio_gpt_on)
                     { 
                        DclSGPT_Control( afe.Audio_gpt, SGPT_CMD_STOP, 0);
                        afe.Audio_gpt_on = KAL_FALSE;
                     }       
                     afe.Audio_close_delay = 0;
                     afe.Audio_close_delay_expired = KAL_TRUE;
                     AFE_SetRefresh();
                  }
               #endif
             }
         }
#endif       
    }
    L1Audio_Msg_AFE_SpkSelect( v_lowest, a_lowest, afe.fir_flag, afe.mic_flag, afe.mic_volume );
#if defined(EXT_DAC_SUPPORT)
    if(a_lowest != -1 && !afe.ext_dac_mute && (afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1)))
    {
         if(afe.ext_dac_aud_func != a_lowest)
         {
            kal_uint8 out_spk;  
            
            afe.ext_dac_aud_func = a_lowest;                   
            out_spk = afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);       
            
            switch((SND_SRC_MAP>>a_lowest*2)&3) 
            {            
               case SRC_AUDIO_DAC:
                  EXT_DAC_SetPlaybackFreq(afe.ext_dac_freq);
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_I2S , out_spk );    
                  AFE_TurnOnEDI(0, 1, L1SP_EXT_DAC_I2S_BCLK_SCALE >> 1); 
                  EXT_DAC_SetVolume(out_spk , afe.ext_dac_aud_vol);
                  afe.ext_dac_i2s_on = KAL_TRUE;
                  if(afe.ext_dac_add_st)
                     a_lowest = -1;  // Turn Off Audio Stereo Buffer When using EXT_DAC only    
                  break;
               case SRC_VOICE_DAC:   
               case SRC_EXT_INPUT:
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_LINEIN , out_spk); 
                  EXT_DAC_FixedLineInGain(out_spk);
                  break;
            }
         }
         else 
         {
            if(((SND_SRC_MAP>>a_lowest*2)&3) == SRC_AUDIO_DAC && afe.ext_dac_add_st)
               a_lowest = -1;
         }
         if(afe.ext_dac_aud_func == L1SP_AUDIO)
            PcmSink_SetGain(((kal_uint32) DG_DAF * afe.ext_dac_level_gain) >> 15);
     }  
     else 
     {
         if(afe.ext_dac_aud_func != -1)
         {
            kal_uint8 out_spk;  
            out_spk = afe.aud[afe.ext_dac_aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);
            afe.ext_dac_aud_func = -1; 
            if(afe.ext_dac_i2s_on)
            {           
               AFE_TurnOffEDI(); 
               afe.ext_dac_i2s_on = KAL_FALSE;             
            }                        
            EXT_DAC_TurnOffSpeaker(out_spk);
         }   
     }
#endif
     if(v_lowest >=0 && a_lowest >=0 ) // only allow a path output
     {
         if(v_lowest <= a_lowest)
            a_lowest = -1;
         else
            v_lowest = -1;
     }
     if( v_lowest >= 0 || a_lowest >=0 || (afe.mic_flag && !afe.mic_mute && !afe.mute))
     {
         afe.bPowerDown = KAL_FALSE;
     #if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
         if(!afe.aux_Audio_on)
         {
            AUX_CTRL_SET_AUDIO_STATUS_T sta;
            sta.eAudioStatus = DCL_AUX_AUDIO_STATUS_OPEN;
            DclAUX_Control( afe.dcl_aux_handle, AUX_CMD_SET_AUDIO_STATUS, (DCL_CTRL_DATA_T *)&sta );
            afe.aux_Audio_on = KAL_TRUE;
         }
     #endif
     }
     
     if(a_lowest >=0 || v_lowest >=0)
     {
     #if __AFE_PA_DELAY_OFF__
        afe.pa_delay = -1;
     #endif
     #if __AFE_AUDIO_DELAY_OFF__
        if(afe.Audio_gpt_on)
        {
           DclSGPT_Control( afe.Audio_gpt, SGPT_CMD_STOP, 0);
           afe.Audio_gpt_on = KAL_FALSE;
        }
   
        afe.Audio_close_delay = -1;
        afe.Audio_close_delay_expired = KAL_FALSE;
     #endif

        if(v_lowest>=0)
        {
           afe.Pre_OutDev = 0;
        }
        else
        {
           afe.Pre_OutDev = 1;
           afe.Pre_aFunc = a_lowest;
        }
        _AfeSetHardwareMute(false);
        afe.afe_state = AFE_STATE_ON;
     }
     // Switch amplifier
     if(afe.ext_op_on)
       _AFE_Switch_TurnOff_Amp(v_lowest, a_lowest);
     if( v_lowest >= 0 ) {
         AFE_Switch_VoiceAmp(v_lowest, a_lowest);
     }
     else if( a_lowest >= 0 ) {
         AFE_Switch_AudAmp(v_lowest, a_lowest);
     }
     else {
        AFE_Switch_No_VoiceAudAmp();
     }
     kal_brief_trace(TRACE_STATE, AFE_STATE_INFO, afe.afe_state, v_lowest, v_lowest, a_lowest, a_lowest); 
     afe.bPowerDown = KAL_TRUE;
     if( v_lowest >= 0 || a_lowest >=0 )
     {
         kal_brief_trace(TRACE_STATE, AFE_GAIN, *ABBA_AUDIODL_CON13, 0, *DP_SIDETONE_VOL);
     }
     // Switch amplifier
     if(!afe.ext_op_on)
         _AFE_Switch_TurnOn_Amp(v_lowest, a_lowest);
#ifdef EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
     //external audio amplifer route path config.
     if ((v_lowest < L1SP_MAX_AUDIO) && (a_lowest < L1SP_MAX_AUDIO)) 
     {
         AFE_SetOutputDeviceExtAmp(v_lowest, (v_lowest >= 0) ? afe.aud[v_lowest].out_dev : 0, 
                                   a_lowest, (a_lowest >= 0) ? afe.aud[a_lowest].out_dev : 0);
     }
#endif
#if defined(__CLASSK_CP_SUPPORT__)
  
     if(afe.ext_op_on)
     {
#if __AFE_CLASSK_SUPPORT_INTERNAL__       	
      	 if(afe.cp_disable && AFE_IsCPEnable())
      	 {
      	 	  _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS); 
      	 }
      	 else if(!afe.cp_disable)               
      	 {
      	 	 if(Check_CP_available())
      	 	 {
      	 	    _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
      	 	 }
      	 	 else
      	 	 {
      	 	   _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS); 
      	 	 }   
      	 }
#else     
         _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);      	 
#endif      	 
     }
#endif 
     _apply_mic_setting(a_lowest, v_lowest);
   
}

//=======================================================
//                  Section: PCM BitClk
//========================================================
#if defined(__AUDIO_AT_CMD__)

void AFE_GetPCMBitClk(AFE_PCMIF_STRUCT_T *pcmcfg)
{
	pcmcfg->PCM_CK_MODE = pcmif.PCM_CK_MODE;
	pcmcfg->VBTON       = pcmif.VBTON      ;
	pcmcfg->VBTSYNC     = pcmif.VBTSYNC    ;	
	pcmcfg->LPK_U2D     = pcmif.LPK_U2D    ;
}
#endif

#if defined(__AUDIO_AT_CMD__)
kal_bool AFE_SetPCMBitClk(AFE_PCMIF_STRUCT_T *pcmcfg)
{
    pcmif.PCM_CK_MODE = pcmcfg->PCM_CK_MODE;
    pcmif.VBTON       = pcmcfg->VBTON;
    pcmif.VBTSYNC     = pcmcfg->VBTSYNC;
    pcmif.LPK_U2D     = pcmcfg->LPK_U2D;

    kal_prompt_trace(MOD_L1SP,"pcmif.PCM_CK_MODE %d pcmif.VBTON %d pcmif.VBTSYNC %d", pcmif.PCM_CK_MODE, pcmif.VBTON,pcmif.VBTSYNC);
    if(pcmif.PCM_CK_MODE > 3)
    {
         return KAL_FALSE;
    } 

    if(pcmcfg->VBTON==KAL_TRUE)
    {
      if(Media_PCM_Clock_Enable(true)==MEDIA_SUCCESS)
          return KAL_TRUE;
      else
          return KAL_FALSE;
    }
    else
    {
      if(Media_PCM_Clock_Enable(false)==MEDIA_SUCCESS)
          return KAL_TRUE;
      else
          return KAL_FALSE;
    }
}
#endif

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
void AFE_SetSwitchPCMBitClk(kal_bool b_BT_on)
{
    if (b_BT_on)
    {
        *AFE_VDB_CON = (*AFE_VDB_CON & ~0xC01F) | 0x0017;   // VBT on, fixed to short sync
    #if defined(__AUDIO_AT_CMD__)
        *AFE_VDB_CON = (*AFE_VDB_CON & (~0xC000))|(pcmif.PCM_CK_MODE<<14); // set clk
        *AFE_VDB_CON = (*AFE_VDB_CON & (~0x0008))|((kal_uint8)pcmif.VBTSYNC<<3); // set long/short sync  
        if(pcmif.LPK_U2D)
        {
            *AFE_VDB_CON |= 0x1000;
        }
        afe.pcmifloopback = pcmif.LPK_U2D;
        #endif
    }
    else
    {
        *AFE_VDB_CON &= (~0x001F);
    #if defined(__AUDIO_AT_CMD__)
        *AFE_VDB_CON &= (~0x1000);
        afe.pcmifloopback = KAL_FALSE;
    #endif
    }

    return;
}
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)

//==============================================
//       AFE Manager  (under HISR)
//==============================================
void AFE_Manager( void )
{
	DelayCmd dc;
   if( afe.ext_op_delay != 0 ) {
      if( afe.ext_op_delay > 0 ) {
         if( --afe.ext_op_delay == 0 ) {
            #if defined(__CLASSK_CP_SUPPORT__)
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            if(Check_CP_available())
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
            else
            	 _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);
            #else
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);	    	    
            #endif
            #endif
            _AFE_Switch_IntAmp(KAL_TRUE);
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
         }
      }
      else { /* afe.ext_op_delay < 0 */
         if( ++afe.ext_op_delay == 0 ) {
            *ABBA_AUDIODL_CON16 |= (RG_AMUTER|RG_AMUTEL);
            _AFE_Switch_IntAmp(KAL_FALSE);
            AFE_SwitchExtAmplifier( false );
            #if defined(__CLASSK_CP_SUPPORT__)
            _AFE_Switch_ChargePump(KAL_FALSE, CP_STATE_OFF);
            afe.cp_th_high = KAL_FALSE;
            #endif
            afe.ext_op_on = KAL_FALSE;
            AFE_SetRefresh();
         }
      }
   }
#if __AFE_PA_DELAY_OFF__
   if(afe.pa_delay > 0){
      afe.pa_delay--;
      if(afe.pa_delay == 0)
         AFE_SetRefresh();
   }
#endif
        
   if(afe.powerOffWait > 0)
      afe.powerOffWait--;
   if(afe.powerOffWait == 0)
      AFE_SetRefresh();
  
  if(afe.md2glock_checking){
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);   //to avoid race condition
      return;
  }
  if( !RB_EMPTY( afe.regq ) ) {
      RB_GET( afe.regq, dc );
      *dc.addr = dc.val;
  }
  if(afe.v8k_off_request)
  {
      if( (!afe.voice_dl_ena) && (afe.bPowerDown))
      {
         if( !((afe.audio_clk_ena == KAL_FALSE) && (afe.audio_dl_ena == KAL_TRUE) ) )
         {
            if(afe.audio_clk_ena){
               *AFE_VMCU_CON0 = 0;
            }
            else{
               _AFE_DCLK_CtrlSeq(KAL_FALSE, KAL_FALSE);
               *AFE_VMCU_CON3 &= (~0x0020);
            }
           
            afe.voice_clk_ena = KAL_FALSE;
            afe.v8k_off_request = KAL_FALSE;
         }
      }
   }
   
   if(afe.aClk_off_request)
   {
      if( (!afe.audio_dl_ena) && (afe.bPowerDown) )
      {
         if(afe.voice_clk_ena){
            *AFE_AMCU_CON0 = 0;
         }
         else{
             _AFE_DCLK_CtrlSeq(KAL_FALSE, KAL_TRUE);
             *AFE_VMCU_CON3 &= (~0x0020);
         }
         afe.audio_clk_ena = KAL_FALSE;
         afe.aClk_off_request = KAL_FALSE;
      }
   }
#if __AFE_MD2G_PWDN_LOCK__
   if(afe.voice_clk_ena || afe.audio_clk_ena || afe.sp_flag)
   {
      if(!afe.fgIdleOffTimerSet)
      {
         afe.fgIdleOffTimerSet = KAL_TRUE;
         AFE_SetRefresh();
      }
   }
   else
   {
      if(afe.fgIdleOffTimerSet)
      {
         afe.fgIdleOffTimerSet = KAL_FALSE;
         AFE_SetRefresh();
      }
   }
#endif

#if __CTIRQ_SLEEP_PLATFORM__
   if( (afe.ext_op_delay != 0) || !RB_EMPTY( afe.regq ) || (afe.powerOffWait >= 0) )
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);
 #if __AFE_PA_DELAY_OFF__
   else if(afe.pa_delay > 0)
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);
 #endif
#endif 
}

#endif //defined(MT6261) || defined(MT2501) || defined(MT2502)
