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
 *  VoIPInc.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines imported prototypes.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VOIP_INC_H
#define VOIP_INC_H

extern void mmi_voip_highlight_main_menu(void);
extern void mmi_voip_highlight_status(void);
extern void mmi_voip_highlight_summary(void);
extern void mmi_voip_highlight_prof_setting(void);
extern void mmi_voip_highlight_prof_setting_option_activate(void);
extern void mmi_voip_highlight_prof_setting_option_edit(void);
extern void mmi_voip_highlight_prof_edit_common(void);
extern void mmi_voip_highlight_prof_edit_account(void);
extern void mmi_voip_highlight_prof_edit_outbound(void);
extern void mmi_voip_highlight_prof_edit_register(void);
extern void mmi_voip_highlight_prof_edit_nat(void);
extern void mmi_voip_highlight_full_screen_editor(void);
extern void mmi_voip_highlight_done(void);
extern void mmi_voip_highlight_input_method_in_menu(void);
extern void mmi_voip_highlight_call_setting(void);
extern void mmi_voip_highlight_auto_answer(void);
extern void mmi_voip_highlight_auto_reject(void);
extern void mmi_voip_highlight_auto_redial(void);
extern void mmi_voip_highlight_hide_caller_id(void);
extern void mmi_voip_highlight_dtmf_in_menu(void);
extern void mmi_voip_highlight_secure_rtp(void);
extern void mmi_voip_highlight_comfort_noise(void);
extern void mmi_voip_highlight_set_codec_order(void);
extern void mmi_voip_hint_auto_answer(U16 index);
extern void mmi_voip_hint_auto_reject(U16 index);
extern void mmi_voip_hint_auto_redial(U16 index);
extern void mmi_voip_hint_hide_caller_id(U16 index);
extern void mmi_voip_hint_dtmf_in_menu(U16 index);
extern void mmi_voip_hint_secure_rtp(U16 index);
extern void mmi_voip_hint_comfort_noise(U16 index);
#ifdef SIP_CONFORMANCE_TEST
extern void mmi_voip_highlight_option_query(void);
#endif

#endif /* VOIP_INC_H */

