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
 *   apm_TaskDef.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Defination of hooked process for Audio Post Process Manager
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
 * removed!
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

#ifndef __MAUI_BASIC__

#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "APM_Task.h"

#if APM_SUPPORT

#if defined(__KARAOKE_SUPPORT__)
// Remix
const APM_TASK_PARA REMIX_func = {
   APM_TASKID_REMIX,
   APM_PROPERTY_READ_WRITE,
   1,
   0,
   AudioPP_Remix_Init,
   AudioPP_Remix_Activate,
   AudioPP_Remix_Deactivate,
   AudioPP_Remix_Process,
   NULL
};
#endif

#if defined(__I2S_INPUT_MODE_SUPPORT__)
#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
const APM_TASK_PARA I2S_SOURCE = {
   APM_TASKID_I2S_SOURCE,
   APM_PROPERTY_READ_ONLY,
   1,
   0,
   I2S_Source_Init,
   I2S_Source_Activate,
   I2S_Source_Deactivate,
   I2S_Source_Process,
   NULL
};
#else
const APM_TASK_PARA I2S_RECORD = {
   APM_TASKID_I2S_RECORD,
   APM_PROPERTY_READ_ONLY,
   1,
   0,
   I2S_Record_Init,
   I2S_Record_Activate,
   I2S_Record_Deactivate,
   I2S_Record_Process,
   NULL//to do
};
#endif
#endif

#if defined(__BES_LIVE_SUPPORT__)
const APM_TASK_PARA BLIVE = {
   APM_TASKID_REVERB,
   APM_PROPERTY_READ_WRITE,
   2,
   16724,
   NULL,
   NULL,
   NULL,
   NULL,
   BLIVE_SetHandle
};
#endif
#if defined(__BES_SURROUND_LSPK__)
const APM_TASK_PARA BSRD = {
   APM_TASKID_SURROUND_LSPK,
   APM_PROPERTY_READ_WRITE,
   2,
   16720,
   NULL,
   NULL,
   NULL,
   NULL,
   BSRD_SetHandle
};
#endif

#if defined(__BES_SURROUND_EARP__)
const APM_TASK_PARA BHDP = {
   APM_TASKID_SURROUND_EARP,
   APM_PROPERTY_READ_WRITE,
   2,
   16720,
   NULL,
   NULL,
   NULL,
   NULL,
   BHDP_SetHandle
};
#endif

#if defined(__BES_EQ_SUPPORT__)
const APM_TASK_PARA BEQ = {
   APM_TASKID_EQ,
   APM_PROPERTY_READ_WRITE,
   2,
   16720,
   NULL,
   NULL,
   NULL,
   NULL,
   BEQ_SetHandle
};
#endif

#if defined(__TC01_OAEP_SUPPORT__)
const APM_TASK_PARA OAEP_Func = {
   APM_TASKID_OAEP,
   APM_PROPERTY_READ_WRITE,
   2,
   16720,
   AudioPP_OAEP_Init,
   AudioPP_OAEP_Activate,
   AudioPP_OAEP_Deactivate,
   AudioPP_OAEP_Process,
   NULL
};
#endif

#if defined(__BES_BASS_SUPPORT__)
const APM_TASK_PARA BBAS = {
   APM_TASKID_BASS,
   APM_PROPERTY_READ_WRITE,
   3,
   0,
   NULL,
   NULL,
   NULL,
   NULL,
   BBAS_SetHandle
};
#endif

#if defined(__BES_LOUDNESS_SUPPORT__) || defined(__BES_LOUDNESS_ON_I2S__)
const APM_TASK_PARA AudioGainControl = {
   APM_TASKID_LOUDNESS,
   APM_PROPERTY_READ_WRITE,
   4,
   0,
   NULL,
   NULL,
   NULL,
   NULL,
   BLOUD_SetHandle
};
#endif

#if defined(LGE_BT_SYSTEM)
const APM_TASK_PARA AVM_Func = {
   APM_TASKID_AVM,
   APM_PROPERTY_READ_ONLY,
   5,
   0,
   AudioPP_AVM_Init,
   AudioPP_AVM_Activate,
   AudioPP_AVM_Deactivate,
   AudioPP_AVM_Process,
   NULL
};
#endif

#if defined(__SPECTRUM_DISPLAY_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
const APM_TASK_PARA SPT_Analyzer = {
   APM_TASKID_SPT,
   APM_PROPERTY_READ_ONLY,
   6,
   0,
   NULL,
   spt_Activate,
   spt_Deactivate,
   spt_Process,
   NULL
};
#endif

#if defined(__BES_CF_SUPPORT__)
const APM_TASK_PARA BCF = {
   APM_TASKID_CF,
   APM_PROPERTY_READ_WRITE,
   7,
   0,
   NULL,
   NULL,
   NULL,
   NULL,
   BCF_SetHandle
};
#endif

// The order of process is as the sequence of Task list
// The first task will be processed at first
const APM_TASK_PARA *apmTaskList[] = {
#if defined(__KARAOKE_SUPPORT__)
   &REMIX_func,
#endif
#if defined(__I2S_INPUT_MODE_SUPPORT__)
   #if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   &I2S_SOURCE,
   #else
   &I2S_RECORD,
   #endif
#endif
#if defined(__BES_LIVE_SUPPORT__)
   &BLIVE,
#endif
#if defined(__BES_SURROUND_LSPK__)
   &BSRD,
#endif   
#if defined(__BES_SURROUND_EARP__)
   &BHDP,
#endif
#if defined(__BES_EQ_SUPPORT__) 
   &BEQ,
#endif
#if defined(__TC01_OAEP_SUPPORT__)
   &OAEP_Func,
#endif
#if defined(__BES_BASS_SUPPORT__)
   &BBAS,
#endif
#if defined(__BES_LOUDNESS_SUPPORT__) || defined(__BES_LOUDNESS_ON_I2S__) 
   &AudioGainControl,
#endif
#if defined(LGE_BT_SYSTEM)
   &AVM_Func,
#endif
#if defined(__SPECTRUM_DISPLAY_SUPPORT__) && !defined(__SMART_PHONE_MODEM__)
   &SPT_Analyzer,
#endif
#if defined(__BES_CF_SUPPORT__)
   &BCF,
#endif
   NULL
};
#endif

#endif
