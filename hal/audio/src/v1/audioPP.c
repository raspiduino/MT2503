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
 *   AudioPP.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  Audio Post Processing includes Time Stretch
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "fsal.h"
#include "kal_trace.h"
#include "audio_def.h"
#include "speech_def.h"
#include "afe_def.h"
#include "l1audio.h"
#include "l1sp_trc.h"
#include "am.h"

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
#include "BesSurround_exp.h"
#include "BesHeadPhone_exp.h"
#endif

#if defined(__BES_LOUDNESS_SUPPORT__)
#include "BesLoudness_exp.h"
#endif

#if defined(__BES_LIVE_SUPPORT__)
#include "BesLive_exp.h"
#endif

#if defined(__BES_BASS_SUPPORT__)
#include "BesBass_exp.h"
#endif

#if defined(__BES_TS_SUPPORT__)

// define the state machine of Time Stretch
#define AUDIO_PP_IDLE          0x00
#define AUDIO_PP_TS_INIT       0x23
#define AUDIO_PP_TS_ON         0x21


#define AUDIO_PP_MASK          0x003F
#define AUDIO_PP_MASK_IDLE     0x003E
#define AUDIO_PP_STATE_OFF     0x0001

// define the ID of each Post Process
#define AUDIO_PP_NONE          0
#define AUDIO_PP_TS            1

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );

#if defined( DSP_WT_SYN )
extern Media_Handle *TS_Midi_Handle;
extern Media_Handle *TS_Imy_Handle;
#endif

static struct ts_struct {
   kal_bool audioPP_disableFlag;
   kal_bool audioPP_TS_Wait;
   uint16 audioPP_TS_Ratio;
   Media_Format audioPP_Format;
} TS_Control;

// Get Time Stretch Setting Speed Rate (50 ~ 160) for Midi
kal_int32 AudioPP_GetTSRate( void )
{
   int32 rate;

   switch (TS_Control.audioPP_TS_Ratio) {
      case 1:  rate =  50;  break;
      case 2:  rate =  80;  break;
      case 3:  rate = 128;  break;
      case 4:  rate = 160;  break;
      default:
         rate = 100;
   }

   return rate;
}


void AudioPP_SetMediaFormat(Media_Format eFormat) {
   TS_Control.audioPP_Format = eFormat;
}


/*
 * Description
 * -----------
 *  Set the initial value for Time Stretch 
 *
 * Syntax
 * ------------
 *  void AudioPP_TS_Iniy(void);
 *
 * Return Value
 * ------------
 *  None
 */
void AudioPP_TS_Init(void) {
   TS_Control.audioPP_TS_Wait = KAL_FALSE;
   TS_Control.audioPP_TS_Ratio = 0;
   TS_Control.audioPP_disableFlag = KAL_FALSE;
   TS_Control.audioPP_Format = MEDIA_FORMAT_DAF;
}


/*
 * Description
 * -----------
 *  Keep the speed_mode in local variable.
 *  If DSP is on, then MCU sets the mode (call AudioPP_TS_Activate)
 *
 * Syntax
 * ------------
 *  Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode);
 *
 *  where:
 *     speed_mode     controls the TS ratio
 *
 * Return Value
 * ------------
 *  Return MEDIA_SUCCESS when the operation is complete.
 *  Return MEDIA_FAIL when argument or state is wrong.
 */
Media_Status AudioPP_TS_SetSpeed(kal_uint16 speed_mode) {
   uint16 audioPP_state;

   // Check the speed mode
   if ( (speed_mode < 1) || (speed_mode > 4) )
      return MEDIA_FAIL;

#if !defined(__AUDIO_COMPONENT_SUPPORT__)   
   // Check whether 3D effect is running
   audioPP_state = (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK);
   if ( ((audioPP_state & AUDIO_PP_MASK_IDLE) != AUDIO_PP_IDLE) &&
        (audioPP_state != AUDIO_PP_TS_INIT) &&
        (audioPP_state != AUDIO_PP_TS_ON) )
      return MEDIA_FAIL;
#endif

   // Check reentry
   if (TS_Control.audioPP_TS_Wait)
      return MEDIA_FAIL;

   TS_Control.audioPP_TS_Ratio = speed_mode;

#if defined(__AUDIO_COMPONENT_SUPPORT__)   
   HOST_APM_Register(APM_TASKID_TS);
#endif

   kal_trace(TRACE_FUNC, L1AUDIO_PP_SET_TS, speed_mode);
   if (AM_IsAudioPlaybackOn()!=-1)
   {
      TS_Control.audioPP_TS_Wait = true;
      AudioPP_TS_Activate(false);
      TS_Control.audioPP_TS_Wait = false;
   }

   return MEDIA_SUCCESS;
}


/*
 * Description
 * -----------
 *  Close the Time Stretch.
 *  The speed will be set to NORMAL.
 *
 * Syntax
 * ------------
 *  void AudioPP_CloseTS(void);
 *
 * Return Value
 * ------------
 *  None
 */
 
#if !defined(__AUDIO_COMPONENT_SUPPORT__) 
/*
 * Description
 * -----------
 *  Activate time stretch
 *  Follow the TS state machine 
 *
 * Syntax
 * ------------
 *  void AudioPP_TS_Activate(void);
 *
 * Return Value
 * ------------
 *  None
 */
void AudioPP_TS_Activate(bool voice_init) {
   int32 I;
   uint16 asp_type;
   (void) voice_init;

   if ( (TS_Control.audioPP_TS_Ratio == 0) || (TS_Control.audioPP_disableFlag) )
      return;

   // KH: Audio is MIDI
   if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
#if defined( DSP_WT_SYN )
      JMidi_SetTSRate(TS_Midi_Handle, rate);
#endif
      return;
   } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
#if defined( DSP_WT_SYN )
      JImy_SetTSRate(TS_Imy_Handle, rate);
#endif
      return;
   }

   if (AM_IsAudioPlaybackOn()!=-1) {
      *AFE_AMCU_CON1 |= 0x0C;  // Hardware mute
#if !defined( MED_LOW )
      kal_sleep_task(30);
#endif
      APM_ClearBuffer();
   }
   //Doug
   asp_type = *DP_ASP_TYPE;
   if( asp_type == ASP_TYPE_PCM_HI)
      *DP_ASP_DEL_M = ASP_DELM_PCM_HIGFS; 

   *DP2_DP2_AUDIO_PP_TS_SPEED = TS_Control.audioPP_TS_Ratio;
   AM_SetPostProcessCtrl( AUDIO_PP_MASK_IDLE, AUDIO_PP_TS_INIT);
   kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_TS_INIT);

   if (AM_IsAudioPlaybackOn()!=-1) {
      for (I = 0; ; I++) {
         if ( ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON) ||
         	    ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK_IDLE) == AUDIO_PP_IDLE))
            break;
         ASSERT_REBOOT( I < 80 );
         kal_sleep_task( 2 );
      }
#if !defined( MED_LOW )
      kal_sleep_task(30); 
#endif
      *AFE_AMCU_CON1 &= ~0x0C;  // Release hardware mute
   }

   if ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON )
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_TS_ON);
   else
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_IDLE);
}

void AudioPP_TS_Close(void) {
   uint16 audioPP_state;
   uint16 asp_type, asp_fs, del_m = 0;
   audioPP_state = (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK);
   if ( ((audioPP_state & AUDIO_PP_MASK_IDLE) == AUDIO_PP_IDLE) ||
        (audioPP_state == AUDIO_PP_TS_ON) ||
        (audioPP_state == AUDIO_PP_TS_INIT) )
   {
   	  //Doug
   	  asp_type = *DP_ASP_TYPE;
      if( asp_type == ASP_TYPE_PCM_HI){
         asp_fs = *DP_ASP_FS;
         if((asp_fs&0xFF)<=ASP_FS_12K)
            del_m = ASP_DELM_PCM_LOWFS;
         else if((asp_fs&0xFF)<=ASP_FS_24K)
            del_m = ASP_DELM_PCM_MEDFS;
         else
         	  del_m = ASP_DELM_PCM_HIGFS;
         *DP_ASP_DEL_M = del_m;
      }
      
      *DSP_AUDIO_CTRL2 &= ~0x0800;                    // Disable AMR time stretch

      TS_Control.audioPP_TS_Ratio = 0;

      // KH: Audio is MIDI
      if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {    
         *DP2_AUDIO_PP_TS_SPEED = 0;
#if defined( DSP_WT_SYN )
         JMidi_SetTSRate( TS_Midi_Handle, 100);
#endif
         return;
      } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
         *DP2_AUDIO_PP_TS_SPEED = 0;
#if defined( DSP_WT_SYN )
         JImy_SetTSRate( TS_Imy_Handle, 100);
#endif
         return;
      } else {
         if (AM_IsAudioPlaybackOn()!=-1) {
            *AFE_AMCU_CON1 |= 0x0C;   // Hardware mute
#if !defined( MED_LOW )
            kal_sleep_task(30); 
#endif
            APM_ClearBuffer();
         }
         *DP2_AUDIO_PP_TS_SPEED = 0;
      }

      AM_ClearPostProcessCtrl( AUDIO_PP_MASK_IDLE );
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_IDLE);

      if (AM_IsAudioPlaybackOn()!=-1) 
      {
#if !defined( MED_LOW )
         kal_sleep_task(30); 
#endif
         *AFE_AMCU_CON1 &= ~0x0C;  // Release hardware mute
      }
   }
}

// Get Current Time Stretch Speed mode (0 ~ 4)
kal_uint16 AudioPP_TS_GetSpeed(void) {
   if ( (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) || (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) ) {
      return TS_Control.audioPP_TS_Ratio;
   }

   if ( ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_INIT ) ||
   	    ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON) )
      return *DP2_AUDIO_PP_TS_SPEED;
   else
      return 0;
}

kal_bool AudioPP_TS_IsEnable(void) {
   if ( (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) || (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) ) {
      if ( AM_IsAudioPlaybackOn() != -1 )
         return (TS_Control.audioPP_TS_Ratio != 0);
      else
         return 0;
   } else {
      return ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON);
   }
}

#else

void AudioPP_TS_Activate(bool voice_init) {
   
   kal_uint16 asp_type;
   (void) voice_init;
   
   if ( (TS_Control.audioPP_TS_Ratio == 0) || (TS_Control.audioPP_disableFlag) )
      return;

   // KH: Audio is MIDI
   if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
      JMidi_SetTSRate(TS_Midi_Handle, rate);
      return;
   } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
      int32 rate;
      
      rate = AudioPP_GetTSRate();
      JImy_SetTSRate(TS_Imy_Handle, rate);
      return;
   }
   
   if (Media_IsDSPDec()){
        	 
	   asp_type = *DP_ASP_TYPE;
     if( asp_type == ASP_TYPE_PCM_HI)
        *DP_ASP_DEL_M = ASP_DELM_PCM_HIGFS; 
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
     {
        kal_uint16 isr_cycle = 0;
        kal_uint8 uSDInterruptNumber = 1;
        kal_int32 rate = AudioPP_GetTSRate();
        Media_Format format = Media_GetAudioFormat();
        kal_uint32 samplerate  = Media_GetSampleRate();  
        
        //AAC only
        if(format==MEDIA_FORMAT_AAC || format==MEDIA_FORMAT_AAC_PLUS)
        {
           isr_cycle = ASP_DELM_AAC;
           if(samplerate<=12000)
           {
              uSDInterruptNumber <<= 2;
              isr_cycle = isr_cycle>>2;
           }
           else if(samplerate<=24000)
           {
              uSDInterruptNumber <<= 1;
              isr_cycle = isr_cycle>>1;
           }  
           if(rate < 100)
           {
              uSDInterruptNumber <<= 1;
              isr_cycle = isr_cycle>>1;
           }   
          *AUDIO_ISR_CYCLE  = isr_cycle;   	
           PcmRut_SetInterruptNumberPerFrame(uSDInterruptNumber);
        }
     }
#endif   
     *DP2_AUDIO_PP_TS_SPEED = TS_Control.audioPP_TS_Ratio;
     AM_SetPostProcessCtrl( AUDIO_PP_MASK_IDLE, AUDIO_PP_TS_INIT);
     kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_TS_INIT);
   }
   
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   APM_TS_SetParam();
#endif
}

void AudioPP_TS_ClearDSPreg(void){
	 kal_uint16 asp_type, asp_fs, del_m = 0; 
	 asp_type = *DP_ASP_TYPE;               
   if( asp_type == ASP_TYPE_PCM_HI){      
      asp_fs = *DP_ASP_FS;                
      if((asp_fs&0xFF)<=ASP_FS_12K)       
         del_m = ASP_DELM_PCM_LOWFS;      
      else if((asp_fs&0xFF)<=ASP_FS_24K)  
         del_m = ASP_DELM_PCM_MEDFS;      
      else                                
      	  del_m = ASP_DELM_PCM_HIGFS;
      *DP_ASP_DEL_M = del_m;              
   }             
   
   
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      {
         kal_uint8 uSDInterruptNumber = 1;
         kal_uint16 isr_cycle = 0;
         kal_int32 rate = AudioPP_GetTSRate();
         Media_Format format = Media_GetAudioFormat();
         kal_uint32 samplerate  = Media_GetSampleRate();  
         if(format==MEDIA_FORMAT_AAC || format==MEDIA_FORMAT_AAC_PLUS)//AAC only
         {
            isr_cycle = ASP_DELM_AAC;
            if(samplerate<=12000)
            {
               uSDInterruptNumber <<= 2;
               isr_cycle >>= 2;
            }
            else if(samplerate<=24000)
            {
               uSDInterruptNumber <<= 1;
               isr_cycle >>= 1;
            }
            *AUDIO_ISR_CYCLE  = isr_cycle;
            PcmRut_SetInterruptNumberPerFrame(uSDInterruptNumber);
         }
      }
#endif      
   *DP2_AUDIO_PP_TS_SPEED = 0;                                 
}

void AudioPP_TS_Close(void) {
   TS_Control.audioPP_TS_Ratio = 0;
   
   HOST_APM_UnRegister(APM_TASKID_TS);

   // KH: Audio is MIDI
   if (TS_Control.audioPP_Format == MEDIA_FORMAT_SMF) {
      JMidi_SetTSRate( TS_Midi_Handle, 100);
      return;
   } else if (TS_Control.audioPP_Format == MEDIA_FORMAT_IMELODY) {
      JImy_SetTSRate( TS_Imy_Handle, 100);
      return;
   }

   if (Media_IsDSPDec()){
      AudioPP_TS_ClearDSPreg();
      AM_ClearPostProcessCtrl( AUDIO_PP_MASK_IDLE );
      kal_trace(TRACE_STATE, L1AUDIO_PP_TS_STATE, AUDIO_PP_IDLE);
   }

   if (AM_IsAudioPlaybackOn()!=-1) {
      APM_TS_SetParam();
   }
}

// Get Current Time Stretch Speed mode (0 ~ 4)
kal_uint16 AudioPP_TS_GetSpeed(void) {
   if ( Media_IsDSPDec() ) {
      if ( ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_INIT ) ||
   	       ( (*DP2_AUDIO_PP_CONTROL & AUDIO_PP_MASK) == AUDIO_PP_TS_ON) )
         return *DP2_AUDIO_PP_TS_SPEED;
      else
         return 0;
   } else {
      return TS_Control.audioPP_TS_Ratio;
   }
}

kal_bool AudioPP_TS_IsEnable(void) {
   if ( AM_IsAudioPlaybackOn() != -1 )
      return (kal_bool)(TS_Control.audioPP_TS_Ratio != 0);
   else
      return KAL_FALSE;
}

#endif

void AudioPP_Close(void) {
   AM_ClearPostProcessCtrl( AUDIO_PP_MASK_IDLE );
   kal_brief_trace (TRACE_STATE, L1AUDIO_PP_IN_IDLE);
}


/*
 * Description
 * -----------
 *  Determine whether TS supports the file
 *
 * Syntax
 * ------------
 *  kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL);
 *
 *  where:
 *    eFormat     is the file type
 *    *pstFSAL    is the file pointer
 *
 * Return Value
 * ------------
 *  Return true when TS supports the file
 */
kal_bool AudioPP_TS_IsSupport(Media_Format eFormat, STFSAL *pstFSAL) {

   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
#if AMR_AWB_AUDIO_PATH_SUPPORT
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
#endif // #if AMR_AWB_AUDIO_PATH_SUPPORT
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_IMELODY:
      case MEDIA_FORMAT_MMF:
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
#if defined(MT6256) || defined(MT6255)	
      case MEDIA_FORMAT_APE:
      case MEDIA_FORMAT_COOK:
      case MEDIA_FORMAT_VORBIS:
      case MEDIA_FORMAT_FLAC:
#endif
         return true;
      case MEDIA_FORMAT_WAV:
         return WAV_IsPPSupport(pstFSAL);
      case MEDIA_FORMAT_AAC:
#if defined(AAC_PLUS_DECODE)
         if (pstFSAL == NULL)
            return true;
         else
            return AAC_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      default:
         return false;
   }
}

/*
 * Description
 * -----------
 *  Determine whether 3D-effect supports the file
 *
 * Syntax
 * ------------
 *  kal_bool AudioPP_Is3DSupport(Media_Format eFormat, STFSAL *pstFSAL);
 *
 *  where:
 *    eFormat     is the file type
 *    *pstFSAL    is the file pointer
 *
 * Return Value
 * ------------
 *  Return true when 3D-effect supports the file
 */
kal_bool AudioPP_Is3DSupport(Media_Format eFormat, STFSAL *pstFSAL) {

   switch (eFormat) {
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_IMELODY:
      case MEDIA_FORMAT_MMF:
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
#if defined(MT6256) || defined(MT6255)	
      case MEDIA_FORMAT_APE:
      case MEDIA_FORMAT_COOK:
      case MEDIA_FORMAT_VORBIS:
      case MEDIA_FORMAT_FLAC:
#endif
         return true;
      case MEDIA_FORMAT_AAC:
#if defined(AAC_PLUS_DECODE)
         if (pstFSAL == NULL)
            return true;
         else
            return AAC_IsPPSupport(pstFSAL);
#else
         return true;
#endif
      default:
         return false;;
   }
}

/*
 * Internal Use.
 * To enable or disable the functionality of 3D effect.
 * When disable 3D, user cannot use 3D effect even if AudioPP_TurnOn3D is called 
 */
void AudioPP_Disable(void) {
   TS_Control.audioPP_disableFlag = true;
}

void AudioPP_Enable(void) {
   TS_Control.audioPP_disableFlag = false;
}


#endif  // __BES_TS_SUPPORT__

/* Reverb */
#if defined(__BES_LIVE_SUPPORT__)
BLIVE_RuntimeParam BLiveParam;

void AudioPP_Reverb_SetMode( kal_uint32 reverb_mode )
{
   ASSERT( reverb_mode < 6 );
   BLiveParam.Mode = reverb_mode;
   APM_SetPP_Param( APM_TASKID_REVERB, sizeof( BLIVE_RuntimeParam ), &BLiveParam, 0, 0 );
}
void AudioPP_Reverb_SetCoeff(short *ReverbCoeff){
   //To do: should modify the API with MED
   BLiveParam.Mode++;
   if( BLiveParam.Mode > 5 )
      BLiveParam.Mode = 0;
   APM_SetPP_Param( APM_TASKID_REVERB, sizeof( BLIVE_RuntimeParam ), &BLiveParam, 0, 0 );
}

Media_Status AudioPP_Reverb_TurnOn()
{
	HOST_APM_Register(APM_TASKID_REVERB);
	return MEDIA_SUCCESS;
}
void AudioPP_Reverb_TurnOff()
{
	HOST_APM_UnRegister(APM_TASKID_REVERB);
}
#endif //#if defined(__BES_LIVE_SUPPORT__)

extern kal_bool AFE_IsAudioLoudSpk( void );

/* Surround */
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)

APM_TaskID historySurround;

void AudioPP_Surround_Enable()
{
#if defined(__BES_SURROUND_LSPK__)
   if( AFE_IsAudioLoudSpk() ){
	   HOST_APM_Register(APM_TASKID_SURROUND_LSPK);
	   historySurround = APM_TASKID_SURROUND_LSPK;
	}else
#endif
	{
#if defined(__BES_SURROUND_EARP__)
	   HOST_APM_Register(APM_TASKID_SURROUND_EARP);
	   historySurround = APM_TASKID_SURROUND_EARP;
#endif
	}
}
void AudioPP_Surround_Disable()
{
   if( historySurround == APM_TASKID_SURROUND_EARP || historySurround == APM_TASKID_SURROUND_LSPK )
	   HOST_APM_UnRegister( historySurround );
}
#if defined(__BES_SURROUND_LSPK__)
BSRD_RuntimeParam  BSRD_RTParam;
void AudioPP_Surround_ModeSelect(int mode)
{
   BSRD_RTParam.BandSelect = mode;
   APM_SetPP_Param( APM_TASKID_SURROUND_LSPK, sizeof( BSRD_RuntimeParam ), &BSRD_RTParam, 0 ,0 );
}
#else
void AudioPP_Surround_ModeSelect(int mode)
{
   return;
}
#endif

#endif // #if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)

/*Bass*/
#if defined(__BES_BASS_SUPPORT__)
BBAS_RuntimeParam BBAS_RTParam;
void AudioPP_BassEnhance_Enable( void )
{
   HOST_APM_Register( APM_TASKID_BASS );
}

void AudioPP_BassEnhance_Disable( void )
{
   HOST_APM_UnRegister( APM_TASKID_BASS );
}

void AudioPP_BassEnhance_Registry( void )
{
   if( AFE_IsAudioLoudSpk() )
      BBAS_RTParam.IsVB = 1;
   else
      BBAS_RTParam.IsVB = 0;
   APM_SetPP_Param( APM_TASKID_BASS, sizeof( BBAS_RuntimeParam ), &BBAS_RTParam, 0 ,0 );
}
#endif

#if defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)

kal_bool BesLoudness_Ringtone_Activate = KAL_FALSE;
extern const unsigned char Loudness_Ringtone_Mode;
extern const unsigned char Loudness_NonRingtone_Mode;

kal_uint32 AudioPP_Loudness_GetMode( void )
{
#if defined(__BES_LOUDNESS_ON_I2S__) && !(defined(MT6250) || defined(MT6255) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   if(I2S_is_I2S_open())
   {
      if(AFE_IsAudioLoudSpk())
      {
         return BESLOUDNESS_I2S_MODE_LOUDSPEAKER;
      }
      else
      {
         return BESLOUDNESS_I2S_MODE_EARPHONE;
      }
   }
   else
#endif
#if defined( __BES_LOUDNESS_SUPPORT__ )
   if (BesLoudness_Ringtone_Activate)
   {
      return Loudness_Ringtone_Mode;
   }
   else
   {
      return Loudness_NonRingtone_Mode;
   }
#endif
   return 6;
}

#if APM_SUPPORT
void AudioPP_Loudness_Registry( void )
{
   kal_int32 iTurnOnLoudness = 0;
   if((L1Audio_GetDebugInfo(APM_DEBUG_INFO)&(1<<APM_TASKID_LOUDNESS)) || 6==AudioPP_Loudness_GetMode())
   {
      //set factory: audio debug info 4 to 32767, to disable besloudness
      iTurnOnLoudness = 0;
   }
#if defined( __BES_LOUDNESS_SUPPORT__ )
   else if(AFE_IsAudioLoudSpk())
   {
      iTurnOnLoudness = 1;
   }
#endif
#if defined(__BES_LOUDNESS_ON_I2S__) && !(defined(MT6250) || defined(MT6255) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   else if(I2S_is_I2S_open())
   {
      iTurnOnLoudness = 1;
   }
#endif
   kal_brief_trace(TRACE_FUNC, L1AUDIO_LOUDNESS_REGISTRY, iTurnOnLoudness);
   if(iTurnOnLoudness)
   {
      HOST_APM_Register( APM_TASKID_LOUDNESS );
   }
   else
   {
      HOST_APM_UnRegister( APM_TASKID_LOUDNESS );
   }
}
#endif

void AudioPP_Loudness_Enable( void )
{
   BesLoudness_Ringtone_Activate = KAL_TRUE;
   Media_AllowPostProcessingOnMidi(BesLoudness_Ringtone_Activate);
   AudioPP_Loudness_Registry();
}

void AudioPP_Loudness_Disable( void )
{
   BesLoudness_Ringtone_Activate = KAL_FALSE;
   Media_AllowPostProcessingOnMidi(BesLoudness_Ringtone_Activate);
   AudioPP_Loudness_Registry();
}

#else
// Add dummy function to support Loudness switch from On to Off
kal_uint32 AudioPP_Loudness_GetMode( void )
{
   return 0;
}
#endif

#if defined(LGE_BT_SYSTEM)
void AudioPP_AVM_Enable( void )
{
   HOST_APM_Register(APM_TASKID_AVM);
}

void AudioPP_AVM_Disable( void )
{
   HOST_APM_UnRegister(APM_TASKID_AVM);
}


void AudioPP_AVM_Init(APM_TCM *tcm)
{
   
}

void AudioPP_AVM_Activate(APM_Info *info)
{
   
}

void AudioPP_AVM_Deactivate(void)
{
   
}

kal_bool AudioPP_AVM_Process(APM_Buffer *buf, APM_Info *info)
{
   uint32 channelNum, consumeLen;;
   
   BTAPP_AVM_PutSrcData( (void *)buf->inBuf, buf->inBufLen * sizeof(kal_int16), true);
   
   buf->outBufLen = buf->inBufLen;
   
   return true;
}
#endif

#if defined(__TC01_OAEP_SUPPORT__)

#include "OAEP_typedef.h"
#define OAEP_FRAME_LENGTH_PER_CHANNEL 1024

static struct {
   kal_uint32 eEfectMode;
   kal_uint32 eAudioOutType;
} OAEP_Control;

#if (!defined(USE_LM_ONLY)) && defined(OAEP_EXTERNAL_MALLOC)
static int32 OAEP_WorkingBuffer[MAX_FRAMELENGTHPERCH/2];
#endif

void AudioPP_OAEP_Enable( void )
{
   HOST_APM_Register(APM_TASKID_OAEP);
}

void AudioPP_OAEP_Disable( void )
{
   HOST_APM_UnRegister(APM_TASKID_OAEP);
}

void AudioPP_OAEP_SetEffectMode( kal_uint32 mode, void *param )
{
   OAEP_Control.eEfectMode = mode;
}

void AudioPP_OAEP_SetOutputType( kal_uint32 eType )
{
   OAEP_Control.eAudioOutType = eType;
}

void AudioPP_OAEP_Init(APM_TCM *tcm)
{
   
}

void AudioPP_OAEP_Activate(APM_Info *info)
{
   OAEP_Return_type result;
   uint32 channelNum;
   
   result = OAEP_SetFrameLengthperCh(OAEP_FRAME_LENGTH_PER_CHANNEL);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_SetAudioOutMode(OAEP_Control.eAudioOutType);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_SetPCMSampleType(INTERLACED);
   ASSERT(result == OAEP_SUCCESS);
   
   if (info->isStereo)
      channelNum = 2;
   else
      channelNum = 1;
   result = OAEP_SetNumChannel(channelNum);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_SetSampleRate(info->sampleFreq);
   ASSERT(result == OAEP_SUCCESS);
   
#if defined(USE_DOLBYMOBILE)
   // Can use AM AV sync state 
   result = OAEP_SetPlayingMode(MUSIC);
   ASSERT(result == OAEP_SUCCESS);
#endif

#ifdef USE_LOUDNESS_MAXIMIZER
   result = OAEP_LM_SetMaxSample (20000);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_LM_SetBoostLevel(LM_MAX_BOOST);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_LM_SetMediaType(LM_MUSIC_PLAYER);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_LM_SetEscalateSound(1);
   ASSERT(result == OAEP_SUCCESS);
#endif
   
#if defined(USE_LM_ONLY)
   result = OAEP_Init(OAEP_ALL);
#elif defined(OAEP_EXTERNAL_MALLOC)
   result = OAEP_Init( (kal_uint16 *)OAEP_WorkingBuffer);
#else
   result = OAEP_Init();
#endif
   ASSERT(result == OAEP_SUCCESS);
}

void AudioPP_OAEP_Deactivate(void)
{
   OAEP_Finish();
}

kal_bool AudioPP_OAEP_Process(APM_Buffer *buf, APM_Info *info)
{
   OAEP_Return_type result;
   uint32 channelNum, consumeLen;;
   
   if (info->isStereo)
      channelNum = 2;
   else
      channelNum = 1;
   consumeLen = OAEP_FRAME_LENGTH_PER_CHANNEL * channelNum;

   if (buf->inBufLen < consumeLen) {
      buf->inBufLen = buf->outBufLen = 0;
      return true;
   }
   
#ifdef USE_DOLBYMOBILE
   result = OAEP_SetDolbyExtVolume (255,255); // only for Dolby
   ASSERT(result == OAEP_SUCCESS);
#endif
   
   result = OAEP_SetAudioOutMode( OAEP_Control.eAudioOutType );
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_SetEffectMode( OAEP_Control.eEfectMode );
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_MapProcessingBuffer(buf->inBuf);
   ASSERT(result == OAEP_SUCCESS);
   
   result = OAEP_ProcessReq();
   ASSERT(result == OAEP_SUCCESS);
   
   memcpy(buf->outBuf, buf->inBuf, consumeLen*sizeof(kal_int16));
   buf->inBufLen = buf->outBufLen = consumeLen;
   
   return true;
}

#endif

kal_bool AudioPP_IsDisableInVideo( APM_TaskID uTaskID )
{
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(uTaskID == APM_TASKID_SURROUND_EARP || uTaskID == APM_TASKID_SURROUND_LSPK)
   {
      return KAL_FALSE;
   }
   else
#endif
   {
      return KAL_TRUE;
   }
}

// dummy function
#if !defined(__BES_TS_SUPPORT__)
kal_int32 AudioPP_GetTSRate( void ){
	return 100;	 
}
#endif

