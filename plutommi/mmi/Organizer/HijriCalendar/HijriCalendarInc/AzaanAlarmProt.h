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
 * AzaanAlarmProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm application related screens.
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_AZAANALARMPROT_H
#define __MMI_AZAANALARMPROT_H

//RHR add begin

#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
    
//RHR add end

extern void mmi_azaan_highlight_azaan_alarm(void);
extern void mmi_azaan_entry_main_menu(void);
extern void mmi_azaan_prepare_inline(void);
extern void mmi_azaan_higlight_alm_index(S32 nIndex);
extern void mmi_azaan_entry_azaan_alm_edit(void);
extern void mmi_azaan_inline_edit_highlight_handler(S32 index);
extern void mmi_azaan_time_editor_callback(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag);
extern void mmi_azaan_fill_inline(void);
extern void mmi_azaan_save_confirm(void);
extern void mmi_azaan_exit_alm_screen(void);
extern void mmi_azaan_save_inline(void);
extern BOOL mmi_azaan_is_inline_editor_changed(S32 index);
extern void mmi_azaan_save_to_nvram(void);
extern void mmi_azaan_alm_init_cb(void);
extern void mmi_azaan_alm_expiry_time_callback(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME *preReminder);
extern U8 mmi_azaan_alm_expiry_callback(U8 index, U16 *period, BOOL power_on);
extern void mmi_azaan_alm_init_nvram(void);
extern void mmi_azaan_alm_reinit_queue_callback(void);
extern void mmi_azaan_alm_stop_handler(void);
extern void mmi_azaan_indication_screen(void);
extern void mmi_azaan_go_back_main_menu(void);
extern void mmi_azaan_exit_indication_screen(void);
extern void mmi_exit_azaan_ind_screen(void);

extern void mmi_azaan_play_azaan_tone(void);
extern void mmi_azaan_stop_azaan_tone(void);

extern void mmi_azaan_handle_end_key(void);
extern U8 mmi_azaan_stop_alarm_by_delete_screen(void);
extern void mmi_azaan_pre_entry_poweron_confirmation(void);
extern void mmi_azaan_entry_tone_selector(void);
extern mmi_ret mmi_azaan_group_proc(mmi_event_struct* evt);
//extern MMI_BOOL mmi_azaan_alm_expiry_entry(mmi_scenario_id scen_id, void *arg);
extern mmi_ret mmi_azaan_play_vib(void *param);
extern mmi_ret mmi_azaan_alm_init_cb_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_azaan_tone_notify_hdlr(mmi_event_struct *event);
#endif /* __MMI_AZAANALARMPROT_H */
