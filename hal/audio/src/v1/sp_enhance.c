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
 * sp_enhance.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   speech enhancement functions (moved from am.c)  
 *
 * Author:
 * -------
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
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"

#include "l1audio.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "speech_def.h"
#include "am.h"
#include "media.h"
//#include "afe.h"
#include "audcoeff_default.h"

#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0,     0,     0,    1,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(BT_DIALER_SPE_FOR_LOUDSPEAKER)
const unsigned short Speech_Common_Para[12] = { 
     0, 55997, 31000, 8192, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif  // defined(BT_DIALER_SPE_FOR_LOUDSPEAKER)
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif
#endif

#if defined(__AUDIO_AT_CMD__)
	extern SPE_ECNRPARAM_STRUCT_T ecnrparam;
#endif



/* ========================================================================= */
/*   SBSD control Functions     (Old feature, which is phas out.)                                       */
/* ========================================================================= */

void SPE_SetSBSD( bool state )
{
   if ( state )       
      *DP_SBSD_CTRL |= 0x12;   
   else
      *DP_SBSD_CTRL &= ~0x12;
}

/* ========================================================================= */


/* ========================================================================= */
/*   EC/AEC/EES control Functions                                            */
/* ========================================================================= */
#define  FLAG_EC_SUPP         1
#define  FLAG_DDL_UL_ENTRY    2
#define  FLAG_DDL_DL_ENTRY    4

#define  SPE_IDLE_STATE       0  /* MCU: 0 -> 1 */ 
#define  SPE_READY_STATE      1  /* DSP: 1 -> 2 */    
#define  SPE_WORKING_STATE    2  /* MCU: 2 -> 3 */ 
#define  SPE_STOP_STATE       3  /* DSP: 3 -> 0 */  

//when mask = 0, means _CTRL_REGISTER = STATE

#define _set_state_( _CTRL_REGISTER, STATE, MASK )  \
   _CTRL_REGISTER = ((_CTRL_REGISTER & MASK) | STATE);

//when mask = 0xFFFF, means _CTRL_REGISTER == STATE
#define _wait_state_change_( _CTRL_REGISTER, STATE, MASK )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( (_CTRL_REGISTER & MASK) == STATE )  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( 2 );  \
   }  \
}

#define _check_state_( _CTRL_REGISTER, STATE, MASK )  \
	( ((_CTRL_REGISTER) & MASK) == STATE )

kal_bool setCommonPara = KAL_FALSE;
uint16 commonPara_0 = 0;

void SPE_LoadSpeechPara(uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS])
{
    uint16 *para;
    volatile uint16* dsp_ptr;
    int I;

    if (c_para)
    {
#if defined( NEW_BLOCK_FILTER_SUPPORT )
        AM_SwitchCompFilter(c_para[4] & 0x2);
#endif
        para = c_para;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        dsp_ptr = Pseudo_SAL_CommonPar_GetBuf();
#else   // chip compile option
        dsp_ptr = DSP_CPARA_ADDR;
#endif  // chip compile option
        for (I = NUM_COMMON_PARAS; I > 0; I--)
        {
            *dsp_ptr++ = *para++;
        }
    }
    
    if (setCommonPara)
    {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        dsp_ptr = Pseudo_SAL_CommonPar_GetBuf();
#else   // chip compile option
        dsp_ptr = DSP_CPARA_ADDR;
#endif  // chip compile option
        *dsp_ptr = commonPara_0;
    }
    
    if (L1SP_GetSpeechMode() == SPH_MODE_AUX2)
    {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        dsp_ptr = Pseudo_SAL_CommonPar_GetBuf();
#else   // chip compile option
        dsp_ptr = DSP_CPARA_ADDR;
#endif  // chip compile option
        dsp_ptr += 3;
        *dsp_ptr = 4096;
    }
    
    if (m_para)
    {
        para = m_para;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        dsp_ptr = Pseudo_SAL_ModePar_GetBuf();
#else   // chip compile option
        dsp_ptr = DSP_MPARA_ADDR;
#endif  // chip compile option
        for (I = NUM_MODE_PARAS; I > 0; I--)
        {
            *dsp_ptr++ = *para++;
        }
    }
    
    if (v_para)
    {
        para = v_para;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        dsp_ptr = Pseudo_SAL_VolPar_GetBuf();
#else   // chip compile option
        dsp_ptr = DSP_VPARA_ADDR;
#endif  // chip compile option
        for (I = NUM_VOL_PARAS; I > 0; I--)
        {
            *dsp_ptr++ = *para++;
        }
    }
}

/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__)"
*/
void SPE_LoadDmnrCoeffs(kal_int16 dmnr_para[NUM_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__)
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support dual microphone feature
#else   // chip compile option
	int i;
	volatile uint16* dsp_ptr;
	
#if defined(MT6256_S01)
	dsp_ptr = DSP_PM_ADDR(2, 0x1100);
#else
	#error Need DSP guys give the dmnr coefficient address
#endif

	for( i = 0; i<NUM_DMNR_PARAM; i++) {
		*dsp_ptr++ = dmnr_para[i];
	}
	
	*DP_DMNR_CONTROL |= 0x0020; //bit5 of NB
#endif  // chip compile option
#endif //__DUAL_MIC_SUPPORT__
}


/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__) &&  defined(__AMRWB_LINK_SUPPORT__)"
*/
void SPE_LoadWbDmnrCoeffs(kal_int16 wb_dmnr_para[NUM_WB_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__) &&  defined(__AMRWB_LINK_SUPPORT__)
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support neither dual microphone feature nor AMR-WB link feature
#else   // chip compile option
	int i;
	volatile uint16* dsp_ptr;
		
#if defined(MT6256_S01)
		dsp_ptr = DSP_PM_ADDR(2, 0x112C);
#else
	#error Need DSP guys give the dmnr coefficient address
#endif
	
	for( i = 0; i<NUM_WB_DMNR_PARAM; i++) {
		*dsp_ptr++ = wb_dmnr_para[i];
	}

	*DP_DMNR_CONTROL |= 0x0040; //bit5 of WB
#endif  // chip compile option
#endif //__DUAL_MIC_SUPPORT__ &&  __AMRWB_LINK_SUPPORT__
}



/* ========================================================================= */
extern const unsigned short Speech_Normal_Mode_Para[16];
extern const unsigned short Speech_Vol_Para[4];
void SPE_Init( void )
{
   *DP_EC_SUPP = 0;
   *DP_SPE_DL_DLL_ENTRY = 0; 

   SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para );
}

void SPE_TurnOnProcess(uint8 on_state)
{
	kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 1, on_state);
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
	*DSP_UL_COMFORT_NOISE_THRESHOLD = 32;
	*DSP_UL_COMFORT_NOISE_SHIFT = (uint16)-12;
#endif
	
    if (on_state & (SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_TDDNC_FLAG))
    {   // Enable UL enhancement
#if defined(__AUDIO_AT_CMD__)
			if((ecnrparam.EC_On|ecnrparam.UL_NR_On)||on_state & (SPE_TDDNC_FLAG)){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_EnableULSE);
				//kal_prompt_trace(MOD_L1SP,"Enable UL speech enhancement");
				*DP_EC_SUPP |= FLAG_DDL_UL_ENTRY;
			}
#else
        	*DP_EC_SUPP |= FLAG_DDL_UL_ENTRY;
#endif
    }
    
    if (on_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG))
    {   // Enable DL enhancement
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.EC_On |ecnrparam.DL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_EnableDLSE);

				//kal_prompt_trace(MOD_L1SP,"Enable DL speech enhancement");
				*DP_SPE_DL_DLL_ENTRY |= FLAG_DDL_DL_ENTRY;
			}
#else
        		*DP_SPE_DL_DLL_ENTRY |= FLAG_DDL_DL_ENTRY;
#endif
    }
    
    if (on_state & SPE_UL_NR_FLAG)
    {   // Enable UL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.UL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetULNRStatusReady );
				//kal_prompt_trace(MOD_L1SP,"Set UL speech noise reduction to READY_STATE");
				_set_state_(*DSP_UL_NR_CTRL , SPE_READY_STATE, 0x0);
			}
#else
        		_set_state_(*DSP_UL_NR_CTRL , SPE_READY_STATE, 0x0);
#endif
    }
    
    if (on_state & SPE_DL_NR_FLAG)
    {   // Enable DL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.DL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetDLNRStatusReady );
				//kal_prompt_trace(MOD_L1SP,"Set DL speech noise reduction to READY_STATE");
				_set_state_(*DSP_DL_NR_CTRL , SPE_READY_STATE, 0x0);
			}
#else
        	_set_state_(*DSP_DL_NR_CTRL , SPE_READY_STATE, 0x0);
#endif
    }
    
#if TDDNC_SUPPORT
    if (on_state & SPE_TDDNC_FLAG)
    {   // Enable TDDNC
    		//kal_prompt_trace(MOD_L1SP,"Enable TDDNC to READY_STATE");
        _set_state_(*DP_TDDNC_CTRL , SPE_READY_STATE, 0x0);
    }
#endif 
      
#if defined(__DUAL_MIC_SUPPORT__)
	//REMIND: DMNR should enable before AEC, because it's part of AEC,
	//AEC will do DMNR initialization when DMNR control is set
	//DMNR will run, base on AEC is running!!!
    if(on_state & SPE_DMNR_FLAG)
    {   // Enable DMNR
    		//kal_prompt_trace(MOD_L1SP,"Enable DMNR to READY_STATE");
        _set_state_(*DP_DMNR_CONTROL , SPE_READY_STATE, 0xFFFC);
    }
#endif
    
    if (on_state & SPE_AEC_FLAG)
    {   // Enable AEC
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.EC_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetECStatusReady );
				//kal_prompt_trace(MOD_L1SP,"Set speech echo cancellation to READY_STATE");
				_set_state_(*DP_AEC2_CONTROL , SPE_READY_STATE, 0x0);
			}
#else
        		_set_state_(*DP_AEC2_CONTROL , SPE_READY_STATE, 0x0);
#endif
    }
    
    if (on_state & SPE_UL_NR_FLAG)
    {   // Wait UL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.UL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetULNRStatusWork);
				//kal_prompt_trace(MOD_L1SP,"Set UL speech noise reduction to WORKING_STATE");
				_wait_state_change_(*DSP_UL_NR_CTRL , SPE_WORKING_STATE, 0xFFFF);
			}
			
#else
        	_wait_state_change_(*DSP_UL_NR_CTRL , SPE_WORKING_STATE, 0xFFFF);
#endif
    }
    
    if (on_state & SPE_DL_NR_FLAG)
    {   // Wait DL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.DL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetDLNRStatusWork);

				//kal_prompt_trace(MOD_L1SP,"Set DL speech noise reduction to WORKING_STATE");
				_wait_state_change_(*DSP_DL_NR_CTRL , SPE_WORKING_STATE, 0xFFFF);
			}
#else
        		_wait_state_change_(*DSP_DL_NR_CTRL , SPE_WORKING_STATE, 0xFFFF);
#endif
    }
    
#if TDDNC_SUPPORT
    if (on_state & SPE_TDDNC_FLAG)
    {   // Wait TDDNC
 		//kal_prompt_trace(MOD_L1SP,"Set TDDNC to WORKING_STATE");
        _wait_state_change_(*DP_TDDNC_CTRL , SPE_WORKING_STATE, 0xFFFF);
    }
#endif    
    
    if (on_state & SPE_AEC_FLAG)
    {   // Wait AEC
#if defined(__AUDIO_AT_CMD__)
	  if(ecnrparam.EC_On){
		  kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetECStatusWork );

		//kal_prompt_trace(MOD_L1SP,"Set Echo Cancellation to WORKING_STATE");
        _wait_state_change_(*DP_AEC2_CONTROL , SPE_WORKING_STATE, 0xFFFF);
      }
#else
      _wait_state_change_(*DP_AEC2_CONTROL , SPE_WORKING_STATE, 0xFFFF);
#endif
    }
    
#if defined(__DUAL_MIC_SUPPORT__)
    //REMIND: DMNR depends on the running of AEC
    if (on_state & SPE_DMNR_FLAG)
    {   // Wait DMNR
    	//kal_prompt_trace(MOD_L1SP,"Set DMNR to WORKING_STATE");
        _wait_state_change_(*DP_DMNR_CONTROL , SPE_WORKING_STATE, 0x3);
    }
#endif
    
    if (on_state & SPE_AGC_FLAG)
    {   // Set AGC
    		//kal_prompt_trace(MOD_L1SP,"Set AGC");
        *DSP_AGC_CTRL = 0xB82A;
    }
    
    return;
}

void SPE_TurnOffProcess(uint8 off_state)
{
    kal_trace(TRACE_INFO, L1SP_ENHANCE_ON_OFF, 0, off_state);
    
    if (off_state & SPE_UL_NR_FLAG)
    {   // Disable UL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.UL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetULNRStatusStop );

				//kal_prompt_trace(MOD_L1SP,"Set UL NR to STOP_STAT");
				_set_state_(*DSP_UL_NR_CTRL , SPE_STOP_STATE, 0x0);
			}
#else
        	_set_state_(*DSP_UL_NR_CTRL , SPE_STOP_STATE, 0x0);

#endif
    }
    
    if (off_state & SPE_DL_NR_FLAG)
    {   // Disable DL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.DL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetDLNRStatusStop );
				//kal_prompt_trace(MOD_L1SP,"Set DL NR to STOP_STAT");
				 _set_state_(*DSP_DL_NR_CTRL , SPE_STOP_STATE, 0x0);
			}
#else
        	 _set_state_(*DSP_DL_NR_CTRL , SPE_STOP_STATE, 0x0);

#endif
    }
    
#if TDDNC_SUPPORT
    if (off_state & SPE_TDDNC_FLAG)
    {   // Disable TDDNC
    		kal_prompt_trace(MOD_L1SP,"Disable TDDNC");
        _set_state_(*DP_TDDNC_CTRL , SPE_STOP_STATE, 0x0);
    }
#endif 
    
#if defined(__DUAL_MIC_SUPPORT__)
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if (off_state & SPE_DMNR_FLAG)
    {   // Disable DMNR
    		//kal_prompt_trace(MOD_L1SP,"Stop DMNR");
        _set_state_(*DP_DMNR_CONTROL , SPE_STOP_STATE, 0xFFFC);
	}
#endif
    
    if (off_state & SPE_AEC_FLAG)
    {   // Disable AEC
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.EC_On){
				   kal_brief_trace(TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetECStatusStop );
				 //kal_prompt_trace(MOD_L1SP,"Set echo cancellation to STOP_STAT");
				 _set_state_(*DP_AEC2_CONTROL , SPE_STOP_STATE, 0x0);
			}
#else
        	_set_state_(*DP_AEC2_CONTROL , SPE_STOP_STATE, 0x0);
#endif
    }
                                             
    if (off_state & SPE_UL_NR_FLAG)
    {   // Wait UL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.UL_NR_On){
				  kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetULNRStatusIdle );
				 //kal_prompt_trace(MOD_L1SP,"Set UL NR to IDLE_STAT");
				 _wait_state_change_(*DSP_UL_NR_CTRL , SPE_IDLE_STATE, 0xFFFF);
			}
#else
        	_wait_state_change_(*DSP_UL_NR_CTRL , SPE_IDLE_STATE, 0xFFFF);
#endif
    }
    
    if (off_state & SPE_DL_NR_FLAG)
    {   // Wait DL NR
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.DL_NR_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetDLNRStatusIdle );

				//kal_prompt_trace(MOD_L1SP,"Set DL NR to IDLE_STAT");
				 _wait_state_change_(*DSP_DL_NR_CTRL , SPE_IDLE_STATE, 0xFFFF);
			}
#else
        	_wait_state_change_(*DSP_DL_NR_CTRL , SPE_IDLE_STATE, 0xFFFF);
#endif
    }
    
#if TDDNC_SUPPORT
    if (off_state & SPE_TDDNC_FLAG)
    {   // Wait TDDNC
    		//kal_prompt_trace(MOD_L1SP,"Set TDDNC to IDLE_STAT");
        _wait_state_change_(*DP_TDDNC_CTRL , SPE_IDLE_STATE, 0xFFFF);
    }
#endif 
    
#if defined(__DUAL_MIC_SUPPORT__)
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if (off_state & SPE_DMNR_FLAG)
    {   // Wait DMNR
  			//kal_prompt_trace(MOD_L1SP,"Set DMNR to IDLE_STAT");
        _wait_state_change_(*DP_DMNR_CONTROL , SPE_IDLE_STATE, 0x3);
	}
#endif
    
    if (off_state & SPE_AEC_FLAG)
    {   // Wait AEC
#if defined(__AUDIO_AT_CMD__)
			if(ecnrparam.EC_On){
				kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_SetECStatusIdle );

				 //kal_prompt_trace(MOD_L1SP,"Set Echo Cancellation to IDLE_STAT");
				 _wait_state_change_(*DP_AEC2_CONTROL , SPE_IDLE_STATE, 0xFFFF);
			}
#else
        	_wait_state_change_(*DP_AEC2_CONTROL , SPE_IDLE_STATE, 0xFFFF);
#endif
    }
    
    if (off_state & SPE_AGC_FLAG)
    {   // Clear AGC
    	  //kal_prompt_trace(MOD_L1SP,"Clear AGC");
        *DSP_AGC_CTRL = 0;
    }

    return;
}

void SPE_Clear_DLL_Entry(uint8 cur_state)
{
    if (!(cur_state & (SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_TDDNC_FLAG)))
    {
#if defined(__AUDIO_AT_CMD__)
			if(!(cur_state &(ecnrparam.EC_On|ecnrparam.UL_NR_On))&&!(cur_state &(SPE_TDDNC_FLAG))){
					kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_DisableULSE);
				 //kal_prompt_trace(MOD_L1SP,"Close Speech Enhancement UL Path");
				 *DP_EC_SUPP &= ~FLAG_DDL_UL_ENTRY;

			}
#else
        *DP_EC_SUPP &= ~FLAG_DDL_UL_ENTRY;
#endif
    }
    
    if (!(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG)))
    {
#if defined(__AUDIO_AT_CMD__)
			if(!(cur_state &(ecnrparam.EC_On|ecnrparam.DL_NR_On))){
				 kal_brief_trace( TRACE_GROUP_M2M_AT, SPH_M2M_AT_DisableDLSE);
				 //kal_prompt_trace(MOD_L1SP,"Close Speech Enhancement DL Path");
				 *DP_SPE_DL_DLL_ENTRY &= ~FLAG_DDL_DL_ENTRY;
			}
#else
        *DP_SPE_DL_DLL_ENTRY &= ~FLAG_DDL_DL_ENTRY;
#endif
    }
    
    return;
}
