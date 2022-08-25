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
 * MMSAppComposerUILE.h
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
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MMS_APP_UI_UC_LE_H
#define MMS_APP_UI_UC_LE_H
#include "MMI_features.h"
#if defined (__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)

/* File Include */
#include "MmsSrvGprot.h"
#include "mma_struct.h"
#include "mma_api.h"
#include "MmsContextSrvLE.h"
#include "MMSAppInterfaceProt.h"
/* Function Declarations */

typedef enum
{
    MMI_UMMS_APP_UI_PLUG_IN_CREATE,
    MMI_UMMS_APP_UI_PLUG_IN_SAVE,
    MMI_UMMS_APP_UI_PLUG_IN_SEND
} mmi_umms_app_ui_plug_in_status_action_enum;
#if defined(__MMI_FTE_SUPPORT__)
extern void mmi_umms_app_if_slim_send (void) ;
extern void mmi_umms_app_slim_insert_object (void) ;
#endif
extern void mmi_umms_slim_decide_before_send(void);
extern void mmi_umms_uc_launch_phb_for_recipient(void);

extern void mmi_umms_uc_launch_subject_editor(void);

extern void mmi_umms_uc_enter_recipient_manual(mmi_id menu_id);

extern void mmi_umms_uc_edit_mms_text_content(void);

extern MMI_BOOL mmi_umms_uc_enter_recipient_done(void);

extern void mmi_umms_uc_entry_delete_addr(void);

extern void mmi_umms_uc_input_method_and_done_go_back_to_option(void);

extern void mmi_umms_uc_entry_insert_slide(void);

extern void mmi_umms_uc_entry_write_msg_with_content(srv_mms_state_enum type, mmi_umms_uc_entry_write_struct *data);

extern void mmi_umms_uc_process_entry_write_msg(U8 mode);

extern void mmi_umms_uc_show_error_and_exit(mma_insert_check_struct *check_result);

extern MMI_BOOL mmi_umms_uc_add_recipient_done(void);

extern void mmi_umms_app_ui_plug_in_remove_address_from_list(void);

extern void mmi_umms_app_ui_plug_in_delete_attachmant_data(void);

extern void mmi_umms_app_ui_plug_in_handle_saving_sending_mms(mmi_id menu_id);

extern void mmi_umms_app_ui_plug_in_launch_slim(U8 mode);

extern MMI_BOOL mmi_mms_make_uc_start_context(mmi_umms_uc_entry_write_struct *data);

extern mmi_umms_uc_entry_write_struct *mmi_mms_get_uc_start_context(void);

extern void mmi_mms_reset_uc_start_context(void);

extern mmi_ret mmi_umms_uc_sd_card_plug_out_hdlr_cb (mmi_event_struct *param);


#endif /* defined (__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) */ 
#endif /* MMS_APP_UI_UC_LE_H */ 

