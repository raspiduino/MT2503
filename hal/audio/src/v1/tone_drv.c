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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  Tone_Drv.c
 *
 * Project:
 * --------
 *  MTK Feature Phone
 *
 * Description:
 * ------------
 *  DTMF tone driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "dcl.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "common_def.h"
#include "l1audio.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "speech_def.h"
#include "audio_def.h"
#include "afe_def.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "tone_drv.h"

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#include "bt_sco_app.h"
#endif

#pragma arm section code="SECONDARY_ROCODE"

static struct
{
   kal_uint32        uGPT;
   const L1SP_Tones  *pToneList;
   const L1SP_QTMF   *pCurrQtmf;
   kal_uint16        uCurrentNode;
   DTMF_DSP_STATE    uState;
   kal_bool          fIsQTMF;
} DTMF_DSP;

static struct
{
   const L1SP_Tones  *pToneList;
   const L1SP_QTMF   *pCurrQtmf;
   kal_uint16        uAudId;
   kal_uint16        amp;
   void              (*fpHandler)(void);
   kal_bool          fDspToneRunning;
   kal_bool          fMcuToneRunning;
   kal_uint8         volume1;
   kal_int8          digital_gain_index;
} tone;

static struct
{
   L1SP_Tones        dtmf;
   kal_uint16        uAudId;
   kal_uint8         lock;
   kal_uint8         volume1;
   kal_int8          digital_gain_index;
   kal_uint32        gain;
   kal_bool          fDspToneRunning;
   kal_bool          fMcuToneRunning;
} keytone;

#define DSP_TONE_IDLE      0
#define DSP_TONE_START     1
#define DSP_TONE_RUNING    2
#define DSP_TONE_STOP      4

#define DSP_WAIT_TIME                  10 //ms
#define DSP_STOP_AND_WAIT_MAX_TICK     40 //tick
#define DSP_QTMF_FREQ(f1,f2,f3,f4)  {  DSP_TONE_F2A  = (f1);                    \
                                       DSP_TONE_F2B  = (f2);                    \
                                       DSP_TONE_F1A  = (DTMF_DSP.fIsQTMF)?(f3):0; \
                                       DSP_TONE_F1B  = (DTMF_DSP.fIsQTMF)?(f4):0; }

static void dtmf_dsp_PlayOn( void *data );
static void dtmf_dsp_PlayOff( void *data );

static kal_bool dtmf_dsp_DspToneCase()
{
#if defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM ) 
   if(-1!= AM_IsAudioPlaybackOn())
   {
      return KAL_FALSE;
   }
   if(AM_IsAmInSpeechState() || AM_IsConflictState())
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
#else
   return KAL_TRUE;
#endif
}

static const L1SP_QTMF *dtmf_dsp_GetNextTone(const L1SP_Tones *ppToneList, const L1SP_QTMF *pCurrQTMF, kal_bool fIsQTMF)
{
   const L1SP_QTMF *pNextQTMF;
   if(fIsQTMF)
   {
      pNextQTMF = (L1SP_QTMF *)ppToneList + pCurrQTMF->next_tone;
   }
   else
   {
      pNextQTMF = (L1SP_QTMF *)(ppToneList + pCurrQTMF->next_tone);
   }
   return pNextQTMF;
}



static void dtmf_dsp_SetTimer(kal_uint32 uMsec, void(*fpCallback)( void *pData ))
{
   kal_uint16 uDur = uMsec / 10;
   if(uDur)
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = uDur;
      start.pfCallback = fpCallback;
      start.vPara = NULL;
      DclSGPT_Control( DTMF_DSP.uGPT, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
}

static void dtmf_dsp_StopTimer()
{
   DclSGPT_Control(DTMF_DSP.uGPT ,SGPT_CMD_STOP, 0);
}

static void dtmf_dsp_TurnOffDSP(kal_uint32 arg1, void* arg2)
{
   if(DTMF_DSP.uState != DTMF_DSP_STATE_ENDING)
   {
      return;
   }
   if(keytone.fDspToneRunning)
   {
      AM_KeyToneOff();
      DP_KT_ATT = 0;
      keytone.fDspToneRunning = KAL_FALSE;
      L1Audio_ClearFlag( keytone.uAudId );
   }
   else if(tone.fDspToneRunning)
   {
      AM_ToneOff();
      DP_KT_ATT = 0;
      tone.fDspToneRunning = KAL_FALSE;
      L1Audio_ClearFlag( tone.uAudId );
   }
   DTMF_DSP.uState = DTMF_DSP_STATE_IDLE;
}

static void dtmf_dsp_end( void *fWait )
{
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   dtmf_dsp_StopTimer();
   if(*DSP_TONE_CTRL1 == DSP_TONE_RUNING)
   {
      *DSP_TONE_CTRL1 = DSP_TONE_STOP;
   }
   if(*DSP_TONE_CTRL2 == DSP_TONE_RUNING)
   {
      *DSP_TONE_CTRL2 = DSP_TONE_STOP;
   }
   if(*DSP_TONE_CTRL1 != DSP_TONE_IDLE || *DSP_TONE_CTRL2 != DSP_TONE_IDLE)
   {
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_end);
   }
   else
   {
      DTMF_DSP.uState = DTMF_DSP_STATE_ENDING;
   }

   if(fWait) //in task, stop and wait
   {  
      kal_int32 I =0;
      while(DTMF_DSP.uState != DTMF_DSP_STATE_ENDING && DTMF_DSP.uState != DTMF_DSP_STATE_IDLE )
      {
         kal_uint16 TONE_CTRL1, TONE_CTRL2;
         TONE_CTRL1 = *DSP_TONE_CTRL1;
         TONE_CTRL2 = *DSP_TONE_CTRL2;
         kal_sleep_task(1);
         //kal_prompt_trace(MOD_L1SP,"dtmf_dsp_end, TONE_CTRL1[%d]: %d, TONE_CTRL2[%d]: %d", (kal_uint32)DSP_TONE_CTRL1, TONE_CTRL1, (kal_uint32)DSP_TONE_CTRL2, TONE_CTRL2 );
         ASSERT(I < DSP_STOP_AND_WAIT_MAX_TICK);
         I++;
      }
      dtmf_dsp_TurnOffDSP(NULL, NULL);
   }
   else if(DTMF_DSP.uState == DTMF_DSP_STATE_ENDING) // in timer isr
   {
      L1Audio_InProcCall(dtmf_dsp_TurnOffDSP, NULL, NULL);
   }
}

static void dtmf_dsp_PlayOn( void *data )
{
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   DTMF_DSP.pCurrQtmf = dtmf_dsp_GetNextTone( DTMF_DSP.pToneList, DTMF_DSP.pCurrQtmf, DTMF_DSP.fIsQTMF);
   if(*DSP_TONE_CTRL1 == DSP_TONE_IDLE && *DSP_TONE_CTRL2 == DSP_TONE_IDLE)
   {
      DSP_QTMF_FREQ( DTMF_DSP.pCurrQtmf->freq1, DTMF_DSP.pCurrQtmf->freq2, DTMF_DSP.pCurrQtmf->freq3, DTMF_DSP.pCurrQtmf->freq4 );
      *DSP_TONE_CTRL1 = DSP_TONE_START;
      *DSP_TONE_CTRL2 = DSP_TONE_START;
      dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->on_duration, dtmf_dsp_PlayOff);
   }
   else
   {
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_PlayOn);
   }
}

static void dtmf_dsp_PlayOff( void *data )
{
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   if(*DSP_TONE_CTRL1 == DSP_TONE_RUNING && *DSP_TONE_CTRL2 == DSP_TONE_RUNING)
   {
      *DSP_TONE_CTRL1 = DSP_TONE_STOP;
      *DSP_TONE_CTRL2 = DSP_TONE_STOP;
      if(DTMF_DSP.pCurrQtmf->off_duration)
      {
         dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->off_duration, dtmf_dsp_PlayOn);
         DTMF_DSP.uCurrentNode = DTMF_DSP.pCurrQtmf->next_tone;
      }
      else
      {
         dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_end);
      }
   }
   else
   {
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_PlayOff);
   }
}

static void dtmf_dsp_Start()
{
   dtmf_dsp_StopTimer();
   ASSERT(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE);
   DTMF_DSP.uState = DTMF_DSP_STATE_PLAYING;
   DTMF_DSP.uCurrentNode = 0;
   DSP_QTMF_FREQ( DTMF_DSP.pCurrQtmf->freq1, DTMF_DSP.pCurrQtmf->freq2, DTMF_DSP.pCurrQtmf->freq3, DTMF_DSP.pCurrQtmf->freq4 );
   *DSP_TONE_CTRL1 = DSP_TONE_START;
   *DSP_TONE_CTRL2 = DSP_TONE_START;
   dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->on_duration, dtmf_dsp_PlayOff);
}

static void dtmf_dsp_EnableScoCodec()
{
#if defined(__CVSD_CODEC_SUPPORT__) 
   {
      kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
      if(( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT ) && BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_DISABLE)
      {
         BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH_BTUL);
      }
   }
#endif
}

static void dtmf_dsp_DisableScoCodec(  )
{
#if defined(__CVSD_CODEC_SUPPORT__)
   if(!AM_IsAmInSpeechState())
   {
      BT_SCO_Disable_All_APP();
   }
#endif  
}

static void DTMF_DSP_Play( const L1SP_Tones *pToneList, kal_bool fIsQtmf, kal_bool fIsKeytone )
{
   KT_StopAndWait();
   TONE_StopAndWait();
   DTMF_DSP.fIsQTMF = fIsQtmf;
   DTMF_DSP.pCurrQtmf = (const L1SP_QTMF *)pToneList;
   if(fIsKeytone)
   {
      L1Audio_SetFlag( keytone.uAudId );
   }
   else
   {
      L1Audio_SetFlag( tone.uAudId );
   }   

    if (AM_IsSpeechOn())
    {
        kal_uint8 volume_sph = 0;
        kal_uint8 digi_gain_idx_sph = 0;
        
        AFE_GetOutputVolume(L1SP_SPEECH, &volume_sph, &digi_gain_idx_sph);
        
        if (AFE_IsSpeakerMuted(L1SP_SPEECH) || volume_sph == 0)
        {
            DP_KT_ATT = 0;
        }
        else
        {
            DP_KT_ATT = 0x7FFF;
        }
    }

#if defined(__BT_SUPPORT__)
   dtmf_dsp_EnableScoCodec();
   if( L1SP_IsBluetoothOn() )
   {
      DSP_TONE_AMP1 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
      DSP_TONE_AMP2 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
      *DP_VSBT_CTRL |= 0x1;                               // output to both BT and voice DAC
   }
   else
#endif
   {
      DSP_TONE_AMP1 = tone.amp;
      DSP_TONE_AMP2 = tone.amp;
   }
   if(fIsKeytone)
   {
      keytone.fDspToneRunning = KAL_TRUE;
      AM_KeyToneOn();
   }
   else
   {
      tone.fDspToneRunning = KAL_TRUE;
      AM_ToneOn();
   }
   dtmf_dsp_Start();
}

static void DTMF_DSP_Stop( kal_bool fWait)
{
   dtmf_dsp_end( (void*)fWait );
}

void toneInit( uint16 uAudId )
{
   DTMF_DSP.uGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
   tone.uAudId  = uAudId;
   tone.amp = TONE_INIT_AMP;
   DP_KT_ATT      = 0;
   *DSP_TONE_CTRL1 = 0;
   *DSP_TONE_CTRL2 = 0;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   *DSP_TONE_CTRL1_AUD = 0;
   *DSP_TONE_CTRL2_AUD = 0;
#endif
   AFE_TurnOnFIR( L1SP_TONE );
}

void ktInit( uint16 uAudId )
{
   keytone.uAudId = uAudId;
   keytone.lock   = 0;
   keytone.volume1 = 160;
   keytone.gain = 0;
   keytone.digital_gain_index = 0;
   DSP_TONE_AMP2  = KT_INIT_AMP;
   AFE_TurnOnFIR( L1SP_KEYTONE );
}

void ktLock( void )
{
   kal_uint32 savedMask;
   ASSERT( keytone.lock < DTMF_KEYTONE_LOCK_MAX_COUNT );
   savedMask = SaveAndSetIRQMask();
   keytone.lock++;
   RestoreIRQMask(savedMask);
}

void ktUnlock( void )
{
   uint32 savedMask;
   ASSERT( keytone.lock > 0 );
   savedMask = SaveAndSetIRQMask();
   keytone.lock--;
   RestoreIRQMask(savedMask);
}

void TONE_SetOutputDevice( uint8 device )
{
   //DTMF_MCU_StopAndWait();
   KT_StopAndWait();
#if defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM ) 
   if(PcmSink_IsKeytoneRuning())
   {
      DTMF_MCU_StopAndWait();
   }
#endif   
   AFE_SetOutputDevice( L1SP_TONE, device );
}

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{  
   tone.volume1 = volume1;
   tone.digital_gain_index = digital_gain_index;
}

void TONE_SetOutputGainControl( uint32 gain )
{
#if defined(__GAIN_TABLE_SUPPORT__)
   AFE_SetOutputGainControl( L1SP_TONE, gain );
#endif
}

kal_bool TONE_DspPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support DAI process
   if(AM_IsAVsyncOn() || AM_IsAudioPlaybackOn() != -1)
#else   // chip compile option
   if(AM_IsAVsyncOn() || AM_IsDAIMode() || AM_IsAudioPlaybackOn() != -1)
#endif  // chip compile option
      return KAL_FALSE;
   if(tone.fDspToneRunning)
      return KAL_FALSE;
   AFE_GetOutputVolume(L1SP_TONE, &uVolume, &iDigiGainIndex); 
   if(0 == uVolume || tone.volume1 == 0)
      return KAL_FALSE;
   return KAL_TRUE;
}

void TONE_Play( const L1SP_Tones *pToneList )
{
#if defined(CHIP_BACK_BYPASS)
   return;
#endif 	
	
#if defined(__AUDIO_NOT_SUPPORTED__)
   return;
#endif

#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke()) return;      
#endif
#if __AFE_CURRENT_SENSOR_ENABLE__
   if(VIBR_Is_In_Calibration()) return;
#endif
   if(AM_IsAfeOn()) return;
   kal_trace( TRACE_INFO, TONEPLAY, 0);
   AFE_SetOutputVolume( L1SP_TONE, tone.volume1, tone.digital_gain_index );
   if(dtmf_dsp_DspToneCase())
   {  
      kal_trace( TRACE_INFO, TONEPLAY, 1);
      if(!TONE_DspPlayable())
      {
         kal_trace( TRACE_INFO, TONEPLAY, 2);
         return;
      }
      DTMF_DSP.uCurrentNode = 0;
      DTMF_DSP.pToneList = pToneList;
      DTMF_DSP_Play((const L1SP_Tones *)pToneList, DTMF_DSP.fIsQTMF, KAL_FALSE);
      kal_trace( TRACE_INFO, TONEPLAY, 3);
   }
   else
   {
      if(AM_IsAVsyncOn())
      {
        kal_trace( TRACE_INFO, TONEPLAY, 4);
        return;
      }
      kal_trace( TRACE_INFO, TONEPLAY, 5);
      tone.fMcuToneRunning = KAL_TRUE;
      DTMF_MCU_Play((const L1SP_Tones *)pToneList, DTMF_DSP.fIsQTMF, KAL_FALSE);
      kal_trace( TRACE_INFO, TONEPLAY, 6);
   }
}

void TONE_PlayQTMF( const L1SP_QTMF *pToneList )
{
   DTMF_DSP.fIsQTMF = KAL_TRUE;
   TONE_Play((const L1SP_Tones *)pToneList);
}


void TONE_Stop()
{
   kal_trace( TRACE_INFO, TONESTOP, 3);
   if(tone.fDspToneRunning)
   {
      DTMF_DSP_Stop(KAL_FALSE);
   }
   else if(tone.fMcuToneRunning)
   {
      DTMF_MCU_Stop(KAL_FALSE);
      tone.fMcuToneRunning = KAL_FALSE;
   }
}

void TONE_StopAndWait( void )
{
   kal_int32 I;
   if(!tone.fDspToneRunning)
   {
      return;
   }
   dtmf_dsp_DisableScoCodec();
   AM_FlushQFunction();
   DTMF_DSP_Stop(KAL_TRUE);
}

void TONE_SetAmplitude( int16 amp )
{
   tone.amp = (uint16)amp;
}

void TONE_SetFIR( bool enable )
{
   if( enable )
   {
      AFE_TurnOnFIR( L1SP_TONE );
   }
   else
   {
      AFE_TurnOffFIR( L1SP_TONE );
   }
}

void TONE_SetHandler( void (*fpHandler)(void) )
{
   tone.fpHandler = fpHandler; //callback when tone stop done
}

kal_bool KT_DspPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support DAI process
   if(AM_IsAVsyncOn() || AM_IsAudioPlaybackOn() != -1)
#else   // chip compile option
   if(AM_IsAVsyncOn() || AM_IsDAIMode() || AM_IsAudioPlaybackOn() != -1)
#endif  // chip compile option
      return KAL_FALSE;
   if(tone.fDspToneRunning || keytone.fDspToneRunning )
      return KAL_FALSE;
   if(keytone.lock)
      return KAL_FALSE;
   AFE_GetOutputVolume(L1SP_KEYTONE, &uVolume, &iDigiGainIndex); 
   if(0 == uVolume || keytone.volume1 == 0)
      return KAL_FALSE;
   return KAL_TRUE;
}

void KT_SetOutputDevice( uint8 device )
{
   KT_StopAndWait();
   if(DTMF_MCU_IsKeytonePlaying() && device != AFE_GetOutputDevice(L1SP_KEYTONE))
   {
      DTMF_MCU_StopAndWait();
   }
   AFE_SetOutputDevice( L1SP_KEYTONE, device);
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   keytone.volume1 = volume1;
   keytone.digital_gain_index = digital_gain_index;
}

void KT_SetOutputGainControl( uint32 gain )
{
#if defined(__GAIN_TABLE_SUPPORT__)
   keytone.gain = gain;
   AFE_SetOutputGainControl(L1SP_KEYTONE, gain);
#endif
}

void KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration ) //duration in msec
{
   kal_trace( TRACE_INFO, KTPLAY, 0);
#if defined(KEYTONE_DEBUG)   
   Keytone_Debug_Entry(freq1, freq2);
   return;
#endif   
#if defined(CHIP_BACK_BYPASS)
   return;
#endif 
#if defined(__AUDIO_NOT_SUPPORTED__)
   return;
#endif
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke()) return;      
#endif
#if __AFE_CURRENT_SENSOR_ENABLE__
   if(VIBR_Is_In_Calibration()) return;
#endif
#if defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM ) 
   if(PcmSink_IsAudioRuning() || DTMF_MCU_IsTonePlaying() || AM_IsAfeOn())
   {  
      return; //disable keytone during audio playback
   }
#if defined( DSP_WT_SYN )
   if(MelodyComp_PlayerActivate()) return;
#endif  //defined( DSP_WT_SYN )
#endif  //defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM ) 
#if defined(__AUDIO_MIXER_SUPPORT__) 
   if( PcmMixer_IsRunning() )
   {  
      kal_trace( TRACE_INFO, KTPLAY, 1);
      return; //disable keytone during audio playback
   }
#endif
   kal_trace( TRACE_INFO, KTPLAY, 2);
   keytone.dtmf.freq1 = freq1;
   keytone.dtmf.freq2 = freq2;
   keytone.dtmf.on_duration = duration;
   keytone.dtmf.off_duration = 0;
   AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
   if(dtmf_dsp_DspToneCase())
   {  
      if(!KT_DspPlayable())
      {
         kal_trace( TRACE_INFO, KTPLAY, 3);
         return;
      }
      kal_trace( TRACE_INFO, KTPLAY, 4);
      DTMF_DSP_Play((const L1SP_Tones *)&keytone.dtmf, KAL_FALSE, KAL_TRUE);
      kal_trace( TRACE_INFO, KTPLAY, 5);
   }
   else
   {
      if(AM_IsAVsyncOn())
      {
        kal_trace( TRACE_INFO, KTPLAY, 6);
        return;
      }
      kal_trace( TRACE_INFO, KTPLAY, 7);
      keytone.fMcuToneRunning = KAL_TRUE;
      DTMF_MCU_Play((const L1SP_Tones *)&keytone.dtmf, KAL_FALSE, KAL_TRUE);
      kal_trace( TRACE_INFO, KTPLAY, 8);
   }
}

void KT_Stop()
{
   kal_trace( TRACE_INFO, KTSTOP);
   if(keytone.fDspToneRunning)
   {
      DTMF_DSP_Stop(KAL_FALSE);
   }
   else if(keytone.fMcuToneRunning)
   {
      DTMF_MCU_Stop(KAL_TRUE);
      keytone.fMcuToneRunning = KAL_FALSE;
   }
   else
   {
      return;
   }
}

void KT_StopAndWait()
{
   kal_int32 I;
   if(!keytone.fDspToneRunning)
   {
      return;
   }
   dtmf_dsp_DisableScoCodec();
   AM_FlushQFunction();
   DTMF_DSP_Stop(KAL_TRUE);
}

void KT_SetAmplitude( int16 amp )
{
   DSP_TONE_AMP2   = amp;
}

void KT_SetFIR( bool enable )
{
   if( enable )
   {
      AFE_TurnOnFIR( L1SP_KEYTONE );
   }
   else
   {
      AFE_TurnOffFIR( L1SP_KEYTONE);
   }
}

kal_bool KT_IsPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;
   if(dtmf_dsp_DspToneCase())
   {
      return KT_DspPlayable();
   }
   else
   {
#if defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM )    	
      if(PcmSink_IsAudioRuning() || tone.fDspToneRunning || keytone.fDspToneRunning)
      {  
         return KAL_FALSE; //disable keytone during audio playback
      }
#if defined( DSP_WT_SYN )
      if(MelodyComp_PlayerActivate()) return KAL_FALSE;
#endif  //defined( DSP_WT_SYN )
#endif      
      AFE_GetOutputVolume(L1SP_KEYTONE, &uVolume, &iDigiGainIndex); 
      if(0 == uVolume || keytone.volume1 == 0)
      {
         return KAL_FALSE;
      }
   }
}

#pragma arm section

