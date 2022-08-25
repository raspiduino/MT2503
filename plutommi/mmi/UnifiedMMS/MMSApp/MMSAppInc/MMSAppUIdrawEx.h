
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
 * Filename:
 * ---------
 * MMSAppUIdrawEx.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_UI_DRAWEX_H
#define MMS_APP_UI_DRAWEX_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMSAppUICommon.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"

extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_dyncmic_list_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_progress_screen_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_confirm_screen(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_viewer_screen(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_inline_selection_list_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_property_status_screen_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_ui_radio_selection_list_draw_func(U16 scr_id);
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
extern MMI_UMMS_ERROR mmi_umms_ui_chkbox_selection_list_draw_func(U16 scr_id);
#endif
extern MMI_UMMS_ERROR mmi_umms_ui_show_new_message_popup_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_dyncmic_list_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_popup_screen(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_callback_popup_screen(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_infinite_time_list_draw_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_display_progress_screen_with_no_history(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_inline_cui_selection_list_draw_func(U16 scr_id);
extern MMI_BOOL mmi_umms_msg_entry_new_msg_popup_entry_hdlr(mmi_scenario_id scene_id, void *arg);
extern MMI_BOOL mmi_umms_app_ui_infinite_time_list_draw_func_hdlr(mmi_scenario_id scene_id, void *arg);

#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_UI_DRAWEX_H */ 

