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
 * AudioCF.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Compensation Filter Controller
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(AUDIO_COMPENSATION_ENABLE)

#include "l1audio.h"
#include "l1audio_def.h"
#include "l1audio_trace.h"
#include "am.h"
#include "afe.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

#define FIR_TAP_NUMBER         45
#define EQ_READY_BIT           0x1
#define EQ_WAITING_TIME        100000000 //2~3us

static Media_Aud_Comp_Mode ACF_MODE = MEDIA_AUD_COMP_LOUDSPEAKER;
static kal_int16 ACF_COEFF_NO_SR[3][FIR_TAP_NUMBER];

void Media_SelectAudioCompensation(Media_Aud_Comp_Mode mode)  //for MED
{ 
   kal_trace(TRACE_FUNC, L1AUDIO_ACF_SELECT, mode);
   ACF_MODE = (kal_int32)mode;
}

void Media_SetAudioCompensation(Media_Aud_Comp_Mode mode, const kal_int16 *coeff)  //for MED
{
   kal_uint32 savedMask;
   ASSERT(mode<3);
   savedMask = SaveAndSetIRQMask();
   memcpy(ACF_COEFF_NO_SR[mode], coeff, FIR_TAP_NUMBER*sizeof(kal_int16));
   RestoreIRQMask(savedMask);
}

MEDIA_ACF_Filter_Type ACF_GetFilterType() //for META
{
   return MEDIA_ACF_HW_FIR;
}

void ACF_SetFilterCoeff(kal_int16 *coeff, MEDIA_ACF_OUTPUT_MODE mode) //for META
{   
   ASSERT(mode<3);
   memcpy(ACF_COEFF_NO_SR[mode], coeff, FIR_TAP_NUMBER*sizeof(kal_int16));
   
   Media_SelectAudioCompensation(mode);
   Audio_Compensation_Activate(0);
}

void Audio_Compensation_Activate( kal_uint16 uSampleRate )
{
   kal_int32 I;
   volatile kal_int32 J, K, M;
   volatile kal_uint32 uCurStatus, uPrevStatus;
   kal_int16 *buf;
   kal_trace(TRACE_FUNC, L1AUDIO_ACF_ACTIVATE, ACF_MODE);
   ASSERT(ACF_MODE<3);
   if (AM_IsAudioPlaybackOn()!= -1)
   {
      AFE_SetHardwareMute(true);
   }
   AFE_TurnOnAudioPower();
   uCurStatus = uPrevStatus = *AFE_STATUS & EQ_READY_BIT;
   *(AFE_EQCOEF) = ACF_COEFF_NO_SR[ACF_MODE][0];
   for(I=0;I<45;I++)
   {
      J=0;
      do
      {
         uCurStatus = *AFE_STATUS & EQ_READY_BIT;
         ASSERT(J++ < EQ_WAITING_TIME); 
      }while(uCurStatus==uPrevStatus);
      uPrevStatus = uCurStatus;
      *(AFE_EQCOEF+2*I) = ACF_COEFF_NO_SR[ACF_MODE][I];   
   }
   if (AM_IsAudioPlaybackOn()!= -1)
   {
      AFE_SetHardwareMute(false);
   }
} 

#endif
 
