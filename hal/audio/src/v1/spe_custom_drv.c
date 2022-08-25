/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   spe_customer_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Customer speech enhancement/post-processing manager 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "media.h"
#include "pcm4way.h"
#include "l1sp_trc.h"
#include "med_utility.h"
#include "bt_sco_app.h"
 
#if defined( __VOICE_CHANGER_SUPPORT__ )
#include "dcmgr.h"
#endif

#define PCM_BUFFER_NUM 2
#define PCM_BUFFER_LENGTH 160

#define SPE_STATE_IDLE    0
#define SPE_STATE_WORKING 1

#pragma arm section code="SECONDARY_ROCODE"

//#define __INTERNAL_SPE_ENGINE__
#if defined(__INTERNAL_SPE_ENGINE__)

#define PAR_NUM     28
typedef struct 
{
   kal_uint32 enhance_pars[PAR_NUM];
   kal_uint32 error_flag;
} SPH_ENH_ctrl_struct;


/* API declaration */
kal_uint32 ENH_API_Get_Memory( SPH_ENH_ctrl_struct *Sph_Enh_ctrl )
{ return 0; }
kal_int16 ENH_API_Alloc( SPH_ENH_ctrl_struct *Sph_Enh_ctrl, kal_uint32 *aec_mem_ptr )
{ return 0; }
kal_int16 ENH_API_Init( SPH_ENH_ctrl_struct *Sph_Enh_ctrl,kal_int16 *aec_com_rx, kal_int16 *aec_com_tx )
{ return 0; }
kal_int16 ENH_API_Process( SPH_ENH_ctrl_struct *Sph_Enh_ctrl, kal_int16 *se_ptr, kal_int16 *sd_ptr, kal_int16 * se_ptr2, kal_int16 *debug1_ptr, kal_int16 *debug2_ptr, kal_int16 *debug3_ptr, kal_int16 *debug4_ptr)
{
   int i;
   for(i = 0; i<160; i++){
      *sd_ptr = *sd_ptr >> 1;
      sd_ptr++;
      *se_ptr = *se_ptr >> 1;
      se_ptr++;
   }
   return 0; 
}
kal_int16 ENH_API_Free(void)
{ return 0; }

#endif

#if defined( __VOICE_CHANGER_SUPPORT__ ) 
extern Media_Status VCHG_Open( kal_uint32 samplerate, SPH_VOICE_CHANGER_MODE mode );
extern Media_Status VCHG_Close( void );
extern kal_uint32 VCHG_Process(char* voicein, char* voiceout);
static kal_bool VCHIsDcmLoad = KAL_FALSE;
#endif

#if defined(__CUSTOM_SPE_ENGINE__)
//#define __CUSTOM_SPE_ENGINE_DEBUG__
typedef struct
{
#if defined(__INTERNAL_SPE_ENGINE__)
   SPH_ENH_ctrl_struct Sph_Enh_ctrl;
#endif
   kal_uint8 *working_buffer;
   kal_int16 dl_pcm[PCM_BUFFER_NUM][PCM_BUFFER_LENGTH];
   kal_int16 ul_pcm[PCM_BUFFER_NUM][PCM_BUFFER_LENGTH];
#if defined(__CUSTOM_SPE_ENGINE_DEBUG__)
   kal_int16 dl_pcm_debug[PCM_BUFFER_LENGTH];
   kal_int16 ul_pcm_debug[PCM_BUFFER_LENGTH];
#endif
   kal_uint16 aud_id;
   kal_uint16 buf_read;  // buf_read == buf_write , means buffer empty 
   kal_uint16 buf_write; // buffer could be filled at most (BUF_LEN - 1) data 
   kal_uint16 buf_to_process; // buffer could be filled at most (BUF_LEN - 1) data 
   kal_uint8 state;

}SPE_CUSTOM_STRUCT;

static SPE_CUSTOM_STRUCT *spe_custom = NULL;

void spe_custom_get_pcm(kal_uint8 *buf, kal_uint16 position)
{
#if defined(__CUSTOM_SPE_ENGINE_DEBUG__)
   int i = 0, idx;
   kal_int16 *temp_buf = (kal_int16 *)buf;
   idx = spe_custom->buf_to_process - 1;
   if(idx < 0)
      idx = PCM_BUFFER_NUM -1;
   if(position == 0) {
      for(i = 0; i < PCM_BUFFER_LENGTH ; i++){
         *temp_buf++ = spe_custom->ul_pcm_debug[i];
         *temp_buf++ = spe_custom->ul_pcm[idx][i];
      }
   } 
   else if(position == 1)
   {
      for(i = 0; i < PCM_BUFFER_LENGTH ; i++){
         *temp_buf++ = spe_custom->dl_pcm_debug[i];
         *temp_buf++ = spe_custom->dl_pcm[idx][i];
      }
   }
#else
   int i = 0;
   kal_int16 *temp_buf = (kal_int16 *)buf;
   for(i = 0; i < PCM_BUFFER_LENGTH ; i++){
      *temp_buf++ = spe_custom->ul_pcm[spe_custom->buf_read][i];
      *temp_buf++ = spe_custom->dl_pcm[spe_custom->buf_read][i];
   }
#endif
}

kal_bool SPE_GetCustomProcessState(void)
{
	  if(spe_custom->state == SPE_STATE_WORKING)
	  {
	  	  return KAL_TRUE;
	  }	
	  else
	  {
	  	  return KAL_FALSE;
 	  }
}

static void spe_custom_task(void *data)
{
   if(spe_custom == NULL)
      return;
   if(spe_custom->state != SPE_STATE_WORKING)
      return;
   while(spe_custom->buf_write != spe_custom->buf_to_process)
   {
#if defined(__CUSTOM_SPE_ENGINE_DEBUG__)
      memcpy((void *)spe_custom->dl_pcm_debug, (void *)spe_custom->dl_pcm[spe_custom->buf_to_process], sizeof(kal_uint16)*PCM_BUFFER_LENGTH);
      memcpy((void *)spe_custom->ul_pcm_debug, (void *)spe_custom->ul_pcm[spe_custom->buf_to_process], sizeof(kal_uint16)*PCM_BUFFER_LENGTH);
#endif
#if defined(__INTERNAL_SPE_ENGINE__)
      //ENH_API_Process( SPH_ENH_ctrl_struct *Sph_Enh_ctrl, kal_int16 *se_ptr, kal_int16 *sd_ptr, kal_int16 * se_ptr2, kal_int16 *debug1_ptr, kal_int16 *debug2_ptr, kal_int16 *debug3_ptr, kal_int16 *debug4_ptr);
      //kal_prompt_trace(MOD_L1SP,"SPE Custom task, %d", spe_custom->buf_to_process);
      ENH_API_Process( &spe_custom->Sph_Enh_ctrl, spe_custom->ul_pcm[spe_custom->buf_to_process], spe_custom->dl_pcm[spe_custom->buf_to_process], 
                        NULL, NULL, NULL, NULL, NULL);
#elif defined( __VOICE_CHANGER_SUPPORT__ )                  
      /* 
         Custom SPE engine should be done here, it's 20ms frames(160 signed short ineteger samples of 8KHz PCM) per processing.
         The UL/DL PCM that could be access is spe_custom->ul_pcm[spe_custom->buf_to_process], spe_custom->dl_pcm[spe_custom->buf_to_process].
         After this function, this frame of UL/DL PCM could be send to SE or Speaker ,respectively.
      */
      memcpy(spe_custom->working_buffer, (kal_uint8 *)spe_custom->ul_pcm[spe_custom->buf_to_process], (PCM_BUFFER_LENGTH)*2*sizeof(kal_uint8));
      VCHG_Process(spe_custom->working_buffer,(kal_uint8 *)spe_custom->ul_pcm[spe_custom->buf_to_process]);
      
#endif
      spe_custom->buf_to_process++;
      if(spe_custom->buf_to_process == PCM_BUFFER_NUM)
         spe_custom->buf_to_process = 0;
   }
}

static void spe_custom_hisr_hdlr(void)
{
   if(spe_custom == NULL)
      return;
   if(spe_custom->state != SPE_STATE_WORKING)
      return;
   if(spe_custom->buf_read != spe_custom->buf_to_process){
   	  PCM4WAY_PutToSpk((const uint16 *)spe_custom->dl_pcm[spe_custom->buf_read]);
      PCM4WAY_PutToSE((const uint16 *)spe_custom->ul_pcm[spe_custom->buf_read]);
	  #ifdef __VOICE_CHANGER_SUPPORT__
	  #if defined(__CVSD_CODEC_SUPPORT__)
	  if(BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_SPEECH)
	  	BT_SCO_Dedicate_TX_HISR((kal_uint16 *)spe_custom->dl_pcm[spe_custom->buf_read], PCM_BUFFER_LENGTH);
	  #endif
	  #endif
      spe_custom->buf_read++;
      if( spe_custom->buf_read == PCM_BUFFER_NUM )
         spe_custom->buf_read = 0;
   } else {     
   	  PCM4WAY_FillSpk(0);
      PCM4WAY_FillSE(0);
   }
   PCM4WAY_GetFromSD((uint16 *)spe_custom->dl_pcm[spe_custom->buf_write]);
#ifdef __VOICE_CHANGER_SUPPORT__
#if defined(__CVSD_CODEC_SUPPORT__)
   if(BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_SPEECH)
	 BT_SCO_Dedicate_RX_HISR((kal_uint16 *)spe_custom->ul_pcm[spe_custom->buf_write]);
   else
#endif
#endif
   PCM4WAY_GetFromMic((uint16 *)spe_custom->ul_pcm[spe_custom->buf_write]);
   spe_custom->buf_write++;
   if( spe_custom->buf_write == PCM_BUFFER_NUM )
      spe_custom->buf_write = 0;
   
   L1Audio_SetEvent(spe_custom->aud_id, 0);
}

/* ========================================================================= */
/*   SPE_CustomProcess_On                                                    */
/*   This function runs under the context of MED Task                        */
/*   Start SPE custom process                                                */
/* ========================================================================= */
void SPE_CustomProcess_On(kal_uint16 sph_mode, SPE_Par_Struct *SPE_PAR, kal_uint8 *state)
{

#if defined( __VOICE_CHANGER_SUPPORT__ )    
   SPH_VOICE_CHANGER_MODE mode = 0;
   kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
   // Apply VCH only in speech
      // Apply VCH only in speech
   if(!AM_IsSpeechOn()|| ((uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT)&&(L1SP_GetVoiceChangerMode() == SPH_VC_NORMAL)))
   {
   	   return;
   }
   
   #if defined(__CVSD_CODEC_SUPPORT__)
   if(BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_SPEECH)
   {
      DACA_Stop(DACA_APP_TYPE_ACTIVE_UL_DL_NB);/*BT_SCO_APP.uDACAType*/
   }
   #endif
   
   if (!VCHIsDcmLoad)
   {
   	   DCM_Load(DYNAMIC_CODE_COMPRESS_VCH , 0, 0);
   	   VCHIsDcmLoad = KAL_TRUE;
   }
   kal_trace( TRACE_GROUP_AUD_SPE_CSUT, SPEECH_VCH_PROCESS, 1, VCHIsDcmLoad);
#endif  
   
   spe_custom = audio_alloc_mem_cacheable(sizeof(SPE_CUSTOM_STRUCT));
   memset(spe_custom, 0, sizeof(SPE_CUSTOM_STRUCT));
   /*Copy the actual parameters to control structure*/
   spe_custom->aud_id = L1Audio_GetAudioID();
#if defined(__INTERNAL_SPE_ENGINE__)
   {
      kal_uint16 i;
      kal_uint32 aec_mem_size;
      for(i=0;i<16;i++)
         spe_custom->Sph_Enh_ctrl.enhance_pars[i] = SPE_PAR->mode_par[i];
      for(i=0;i<12;i++)
         spe_custom->Sph_Enh_ctrl.enhance_pars[i+16] = SPE_PAR->common_par[i];   
      aec_mem_size = ENH_API_Get_Memory(&spe_custom->Sph_Enh_ctrl);
      if(aec_mem_size > 0) {
         spe_custom->working_buffer = audio_alloc_mem_cacheable( aec_mem_size * sizeof(kal_int8) );
         memset(spe_custom->working_buffer, 0, aec_mem_size * sizeof(kal_int8));
         ENH_API_Alloc(&spe_custom->Sph_Enh_ctrl, (kal_uint32 *)spe_custom->working_buffer);
      } else
         spe_custom->working_buffer = NULL;
      
      ENH_API_Init(&spe_custom->Sph_Enh_ctrl, SPE_PAR->out_fir, SPE_PAR->in_fir);
   }
#elif defined( __VOICE_CHANGER_SUPPORT__ )    
   spe_custom->working_buffer = audio_alloc_mem_cacheable( PCM_BUFFER_LENGTH*2*sizeof(kal_uint8));
   if(spe_custom->working_buffer != NULL)
   {
       memset(spe_custom->working_buffer, 0, PCM_BUFFER_LENGTH*2*sizeof(kal_uint8));
   }
#endif   
   L1Audio_SetEventHandler(spe_custom->aud_id , spe_custom_task);
   L1Audio_SetFlag(spe_custom->aud_id);
   spe_custom->state = SPE_STATE_WORKING;
#if defined( __VOICE_CHANGER_SUPPORT__ )   
   mode = L1SP_GetVoiceChangerMode();  
   VCHG_Open(8,mode);
#endif   
#if 1
   PCM4WAY_Start(spe_custom_hisr_hdlr, 0);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/* ========================================================================= */
/*   SPE_CustomProcess_Off                                                   */
/*   This function runs under the context of MED Task                        */
/*   Stop SPE custom process                                                 */
/* ========================================================================= */
void SPE_CustomProcess_Off()
{
   if(spe_custom->state != SPE_STATE_WORKING)
      return;
   spe_custom->state = SPE_STATE_IDLE;
#if 1
   PCM4WAY_Stop(0);
#else
/* under construction !*/
#endif 
#if defined(__INTERNAL_SPE_ENGINE__)
   ENH_API_Free();
#elif defined( __VOICE_CHANGER_SUPPORT__ )
   VCHG_Close();
   if(VCHIsDcmLoad)
   {      	
      DCM_Unload(DYNAMIC_CODE_COMPRESS_VCH);
      VCHIsDcmLoad = KAL_FALSE;
   }
   
   #if defined(__CVSD_CODEC_SUPPORT__)
   if(BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_SPEECH)
   {
      DACA_Start(BT_SCO_Speech_TX_HISR, BT_SCO_Speech_RX_HISR,DACA_APP_TYPE_ACTIVE_UL_DL_NB);/*BT_SCO_APP.uDACAType*/
   }
   #endif
   
   kal_trace( TRACE_GROUP_AUD_SPE_CSUT, SPEECH_VCH_PROCESS, 0, VCHIsDcmLoad);  
#endif  
   L1Audio_ClearFlag(spe_custom->aud_id); 
   L1Audio_FreeAudioID(spe_custom->aud_id);
   if(spe_custom->working_buffer != NULL)
      audio_free_mem((void **)&(spe_custom->working_buffer));   
   audio_free_mem((void **)&spe_custom);
   spe_custom = NULL;
}
#endif //defined(__CUSTOM_SPE_ENGINE__)

/* ========================================================================= */
/*   SPE_CustomProcess                                                       */
/*   This function runs under the context of MED Task                        */
/*   enable[in]: enable or disable custom process                            */
/*   sph_mode[in]: speech mode                                               */
/*   SPE_PAR[in/out]: mode_par, common_par, in_fir, out_fir pointers         */
/*   state[in/out]: enhancement state                                        */
/* ========================================================================= */

void SPE_CustomProcess(kal_bool enable, kal_uint16 sph_mode, SPE_Par_Struct *SPE_PAR, kal_uint8 *next_state)
{
   
   if(enable == KAL_TRUE)
   {
#if defined(__CUSTOM_SPE_ENGINE__)
      {
         if( spe_custom != NULL ){
            return;
         }
         /*==================Part1. Start Custom Process function   ========================*/
         SPE_CustomProcess_On(sph_mode, SPE_PAR, next_state);
      
         
         /*==================Part2. Update DSP SPE parameters       ========================*/
         /* Update parameters to DSP here if certain DSP enhancement need to be turned off or modified from speech enhancement parameters */
         
         /*==================Part3. Turn Off DSP SPE control word   ========================*/
         /* 
         ex:
         l1sp_updateSpeUsrMask(SPE_AEC_FLAG+SPE_UL_NR_FLAG+SPE_DL_NR_FLAG, false);
         */
      
      }
#elif defined(__TWOMICNR_SUPPORT__)
      if ( sph_mode == SPH_MODE_LOUDSPK ){
         *next_state &= ~(SPE_AEC_FLAG + SPE_UL_NR_FLAG);
         Two_Mic_NR_chip_Handfree_mode();
         kal_trace( TRACE_STATE, L1SP_2MIC_STATE, sph_mode, *next_state);
      }else if ( sph_mode == SPH_MODE_NORMAL )
      {
         *next_state &= ~SPE_AEC_FLAG;
         Two_Mic_NR_chip_Handset_mode();
         kal_trace( TRACE_STATE, L1SP_2MIC_STATE, sph_mode, *next_state);
      }else{
         Two_Mic_NR_chip_Bypass_mode();
         kal_trace(TRACE_STATE, L1SP_2MIC_ENTER_BYPASS);
      }
#elif defined(__TC01_VOICE_ENGINE__)
      if( sph_mode == SPH_MODE_NORMAL ){
         if(VS_IsStart())
            VS_Stop();
         VC_Start();
         *next_state &= ~SPE_DL_NR_FLAG;
      }
      else if( sph_mode == SPH_MODE_LOUDSPK ){
         if(VC_IsStart())
            VC_Stop();
         VS_Start();
         *next_state &= ~SPE_DL_NR_FLAG;
      }
#endif
   
   }
   else //Turn off custom process
   {
#if defined(__CUSTOM_SPE_ENGINE__)
      if( spe_custom == NULL ){
            return;
      }
      SPE_CustomProcess_Off();
#elif defined(__TWOMICNR_SUPPORT__)
      if ( sph_mode == SPH_MODE_LOUDSPK || sph_mode == SPH_MODE_NORMAL )
      {
         Two_Mic_NR_chip_Sleep();
         kal_trace(TRACE_STATE, L1SP_2MIC_SLEEP);
      }
      else{
         Two_Mic_NR_chip_exit_Bypass_mode();
         kal_trace(TRACE_STATE, L1SP_2MIC_EXIT_BYPASS);
      }
#elif defined(__TC01_VOICE_ENGINE__)
      VC_Stop();
      VS_Stop();
#endif
   }
}

#pragma arm section
