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
 *  EngineerModeAudio.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode audio header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_AUDIO_H
#define MMI_EM_AUDIO_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void SendGetAudioParamReq(void);
extern void EmUpdateAudioParam(U8 *audp);
extern U8 EngineerModeGetAudioParamRes(void *inMsg);
extern U8 EngineerModeSetAudioParamRes(void *inMsg);

#if defined(__MMI_EM_AUDIO__) 
extern void EntryEmSideTone(void);
extern void EntryEmAudSetMaxSwing(void);
#endif /* #ifdef (__MMI_EM_AUDIO__) */

extern void HighlightEmLoopBack(void);

extern void SendSetVolumeReq(void);
extern void EmSetVolume(void);
extern void SendGetAudioProfileReq(void);
extern void EmUpdateAudioProfile(audio_profile_struct *rsp_p);
extern void EngineerModePlayAudioReq(U8 index);
extern void EngineerModeStopAudioReq(U8 index, U8 type);
extern void EngineerModeSetVolumeReq(U8 volumeType, U8 volumeLevel);
extern void EngineerModeGetAudioProfileReq(U8 mode);
extern U8 EngineerModeGetAudioProfileRes(void *inMsg);
extern void EngineerModeSetAudioProfileReq(void *audioProfile);
extern U8 EngineerModeSetAudioProfileRes(void *inMsg);
extern void EngineerModeSetAudioParamReq(void *audioParam);
extern void EngineerModeGetAudioParamReq(void);

#ifdef __MMI_EM_AUDIO_AUTO_VM__
extern void mmi_em_aud_auto_vm_setting_init(void);
#endif /* __MMI_EM_AUDIO_AUTO_VM__ */

extern void mmi_em_audio_menu_sel_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_audio_menu_entry_event_hdlr(cui_menu_event_struct *evt);
extern void mmi_em_aud_menu_exit_event_hdlr(cui_menu_event_struct *evt);


#endif /* MMI_EM_AUDIO_H */ 


