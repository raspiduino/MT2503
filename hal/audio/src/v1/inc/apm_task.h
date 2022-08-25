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
 *   APM_Task.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Definition of external APM Task interface
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef APM_TASK_DOT_H
#define APM_TASK_DOT_H
 
#include "audio_def.h"

#if APM_SUPPORT

#include "l1audio.h"
#include "BesSound_exp.h"

typedef struct APM_TaskParaStruct {
   APM_TaskID apm_Id;
   kal_uint16 property;
   kal_uint16 level;
   kal_uint32 tcmSize;
   void (*Init)(APM_TCM *tcm);
   void (*Activate)(APM_Info *info);
   void (*Deactivate)(void);
   kal_bool (*Process)(APM_Buffer *buf, APM_Info *info);
   int (*SetHandle)(BS_Handle *pHandle);
} APM_TASK_PARA;

// Reverberation
#if defined(__BES_LIVE_SUPPORT__)
extern int BLIVE_SetHandle(BS_Handle *pHandle);
#endif
// 3D Surround
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
extern int BSRD_SetHandle(BS_Handle *pHandle);
extern int BHDP_SetHandle(BS_Handle *phandle);
#endif
//Bass Enhancement
#if defined( __BES_BASS_SUPPORT__ )
extern int BBAS_SetHandle(BS_Handle *phandle);
#endif

// Equalizer
#if defined(__BES_EQ_SUPPORT__)
extern int BEQ_SetHandle(BS_Handle *phandle);
#endif

// Automatic Gain Control
#if defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__) 
extern int BLOUD_SetHandle(BS_Handle *phandle);
#endif

#if defined(__BES_CF_SUPPORT__)
extern int BCF_SetHandle(BS_Handle *pHandle);
#endif

// AvBT
#if defined( __BT_AUDIO_VIA_SCO__ )
extern void avb_Init(APM_TCM *tcm);
extern void avb_Activate(APM_Info *info);
extern void avb_Deactivate(void);
extern kal_bool avb_Process(APM_Buffer *buf, APM_Info *info);
#endif

// Spectrum display
extern void spt_Init(APM_TCM *tcm);
extern void spt_Activate(APM_Info *info);
extern void spt_Deactivate(void);
extern kal_bool spt_Process(APM_Buffer *buf, APM_Info *info);

// Recording via I2S
#if defined(__I2S_INPUT_MODE_SUPPORT__)
extern void I2S_Record_Init(APM_TCM *tcm);
extern void I2S_Record_Activate(APM_Info *info);
extern void I2S_Record_Deactivate(void);
extern kal_bool I2S_Record_Process(APM_Buffer *buf, APM_Info *info);
#endif

#if defined(__I2S_INPUT_MODE_SUPPORT__)
extern void I2S_Source_Init(APM_TCM *tcm);
extern void I2S_Source_Activate(APM_Info *info);
extern void I2S_Source_Deactivate(void);
extern kal_bool I2S_Source_Process(APM_Buffer *buf, APM_Info *info);
#endif

#if defined(LGE_BT_SYSTEM)
extern void AudioPP_AVM_Init(APM_TCM *tcm);
extern void AudioPP_AVM_Activate(APM_Info *info);
extern void AudioPP_AVM_Deactivate(void);
extern kal_bool AudioPP_AVM_Process(APM_Buffer *buf, APM_Info *info);
#endif

#if defined(__TC01_OAEP_SUPPORT__)
extern void AudioPP_OAEP_Init(APM_TCM *tcm);
extern void AudioPP_OAEP_Activate(APM_Info *info);
extern void AudioPP_OAEP_Deactivate(void);
extern kal_bool AudioPP_OAEP_Process(APM_Buffer *buf, APM_Info *info);
#endif

#if defined(__KARAOKE_SUPPORT__)
extern void AudioPP_Remix_Init(APM_TCM *tcm);
extern void AudioPP_Remix_Activate(APM_Info *info);
extern void AudioPP_Remix_Deactivate(void);
extern kal_bool AudioPP_Remix_Process(APM_Buffer *buf, APM_Info *info);
#endif

#endif   // end APM_TASK_DOT_H
#endif   // end APM_SUPPORT
