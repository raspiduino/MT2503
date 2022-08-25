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
 *  BootupAppProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface of bootup application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BOOTUP_APP_PROT_H__
#define __BOOTUP_APP_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupSrvIprot.h"
#include "ProcedureGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "SimCtrlGprot.h" /* mmi_sim_ctrl_get_str */


#define MMI_BOOTUP_TRC_GROUP MMI_COMMON_TRC_G3_BOOTUP


/****************************************************************************
 * Global functions
 ****************************************************************************/

/* Adaptors */

extern mmi_frm_proc_result_enum mmi_bootup_wait_for_gpio(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
    
extern MMI_BOOL mmi_bootup_is_ultra_low_power(void);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_bootup_needs_pen_calibration(void);

extern mmi_frm_proc_result_enum mmi_bootup_flow_pen_calibration(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

extern void mmi_bootup_show_pen_calibration(
                mmi_id grp_id,
                void (*completed_callback)(void *user_data),
                void *user_data);
#endif

extern mmi_frm_proc_result_enum mmi_bootup_flow_battery_check(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

extern mmi_frm_proc_ctrl_enum mmi_bootup_ani_notify_completion_info(
            void *user_data,
            const mmi_frm_proc_set_status_struct *set_status);


/* Initializations */

extern void mmi_bootup_early_init(void);

extern mmi_frm_proc_result_enum mmi_bootup_normal_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

extern void mmi_bootup_notify_before_idle(void);    

extern void mmi_bootup_notify_completed(void);

/* Disk check */

typedef void (*mmi_bootup_disk_check_result_callback)(void *user_data, S32 error_code);

extern void mmi_bootup_check_disk(
                mmi_id parent_id,
                mmi_bootup_disk_check_result_callback completed_callback,
                void *user_data);


/* Mode decision */

extern mmi_frm_proc_result_enum mmi_bootup_flow_init_sim_module(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
#ifdef __MMI_TELEPHONY_SUPPORT__
extern mmi_frm_proc_result_enum mmi_bootup_decide_mode(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
#endif
extern mmi_frm_proc_result_enum mmi_bootup_boot_protocol(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

typedef void *mmi_bootup_sim_selection_handle;

typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_bootup_sim_selection_handle handle;
    srv_bootup_protocol_mode_enum mode;
} mmi_bootup_sim_selected_event_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_bootup_sim_selection_handle handle;
} mmi_bootup_sim_sel_negative_event_struct;

extern mmi_bootup_sim_selection_handle mmi_bootup_sim_selection_show(
    mmi_id grp_id,
    U16 title_str_id,
    U16 title_icon_id,
    void *user_data,
    U16 select_str_id,
    mmi_proc_func selected_proc,
    U16 cancel_str_id,
    mmi_proc_func neg_proc);

extern void mmi_bootup_sim_selection_close(mmi_bootup_sim_selection_handle handle);

#if 0 // slim_unused_api
/* under construction !*/
#endif


/* Animation */
#ifndef __MMI_BTBOX_NOLCD__
extern mmi_frm_proc_result_enum mmi_bootup_play_animation(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
#else

extern mmi_frm_proc_result_enum mmi_bootup_play_tone(
	                        void *arg,
                            const mmi_frm_proc_id_info_struct id_info);
#endif


/* Security */
#ifdef __MMI_TELEPHONY_SUPPORT__
extern mmi_frm_proc_result_enum mmi_bootup_flow_security(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
                                    
extern WCHAR* mmi_bootup_sec_get_input_prompt(
        mmi_sim_enum sim,
        srv_bootup_verification_type_enum veri_type,
        WCHAR *out_buffer,
        S32 max_n_chars);

extern WCHAR* mmi_bootup_sec_get_message_of_result(
        const srv_bootup_verify_result_struct *result,
        WCHAR *out_buffer,
        S32 max_n_chars);
#endif

/* Welcome */
extern mmi_frm_proc_result_enum mmi_bootup_flow_welcome_screen_show(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);


/* Widget pre-installation */
#ifdef __GADGET_SUPPORT__
extern mmi_frm_proc_result_enum mmi_wgtmgr_preinstall_widget(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
#endif


/* Sub-LCD */
#ifdef __MMI_SUBLCD__
extern void mmi_bootup_sublcd_entry(void);
#endif /* #if defined(__MMI_SUBLCD__) */

#endif /* __BOOTUP_APP_PROT_H__ */

