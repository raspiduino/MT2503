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
 *  EngineerModeVOIP.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intend for engineer mode VOIP.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_VOIP_H
#define MMI_EM_VOIP_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
#if defined(__VOIP__)
extern void HighlightEmVOIP(void);
extern void EntryEmVOIP(void);
extern void HighlightEmVOIPSetting(void);
extern void EntryEmVOIPSetting(void);
extern void EmGetVOIPSettingInfo(void);
extern void ExitEmVOIPSettingScreen(void);
extern void HighlightHdlrVOIPSettingsInline(S32 index);
extern void EmSetVOIPSettingInfo(void);
extern void HighlightEmVOIPSIPSupported(void);
extern void EntryEmVOIPSIPSupported(void);
extern void LSKEmVOIPSetSIPSupportedHandler(void);
extern void HighlightEmVOIPSIPRequire(void);
extern void EntryEmVOIPSIPRequire(void);
extern void LSKEmVOIPSetSIPRequireHandler(void);

extern void HighlightEmVOIPLog(void);
extern void EntryEmVOIPLog(void);
extern void HighlightEmVOIPLogSetting(void);
extern void EntryEmVOIPLogSetting(void);
extern void ExitEmVOIPLogSettingScreen(void);
extern void HighlightHdlrVOIPLogInline(S32 index);
extern void EmSetVOIPLogInfo(void);
extern void HighlightEmVOIPLogView(void);
extern void EntryEmVOIPLogOption(void);
extern void EntryEMVOIPLogSelected(void *path, int is_short);
extern void EMVOIPLogDisplayOption(void);
extern void HighlightEmVOIPLogOptionView(void);
extern void EntryEmVOIPLogOptionView(void);
extern void HighlightEmVOIPLogOptionDelete(void);
extern void HighlightEmVOIPLogOptionDeleteAll(void);
extern void entry_em_voip_log_delete_confirm(void);
extern void em_voip_log_delete_all_file(void);
extern void em_voip_log_delete_file(void);
extern void em_voip_log_delete_rsp_hdlr(void *info);
extern void entry_em_voip_delete_animation(void);
extern void exit_em_voip_delete_animation(void);
extern U8   em_voip_delete_animation_callback(void *param);

extern void em_voip_log_init(void);
extern MMI_BOOL em_voip_log_check_activate_status(void);
extern void em_voip_log_change_id(void* ori_id, void* new_id);
extern void em_voip_log_save(void* id, void *buf, S32 buf_len);
extern void em_voip_log_call_start( void* id, MMI_BOOL mdir);
extern void em_voip_log_call_end( void* id);
//extern MMI_BOOL em_voip_log_check_disk_space(void);
extern void em_voip_log_check_and_delete( void);
#endif  /*  __VOIP__ */

#endif /* MMI_EM_VOIP_H */ 
