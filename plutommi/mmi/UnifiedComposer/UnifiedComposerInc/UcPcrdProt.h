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
 * UcPcrdProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements generic handling of screen controler, resource controller, Db handling, key handling for Unified Composer application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//suggested add
#include "MMI_features.h"
    #include "MMIDataType.h"
    #include "wgui_inline_edit.h"
    //#include "kal_general_types.h"
//end
#ifndef _UC_POSTCARD_PROT_H
#define _UC_POSTCARD_PROT_H
#ifdef __MMI_MMS_POSTCARD__
extern void mmi_postcard_delete_one_recipient(void);
extern void mmi_postcard_reset_all_recipients(void);
extern void mmi_postcard_validate_recipient_address_data(void);
extern void mmi_uc_frm_app_set_data_for_multiple_recipient_option_in_postcard(U16 instance_hash_id);
extern wgui_inline_item *mmi_uc_frm_app_callback_recipient_address_editor_item_list(void);
extern void mmi_postcard_validate_recipient_address_data(void);
extern void mmi_uc_frm_app_set_data_for_multiple_recipient_option_in_postcard(U16 instance_hash_id);
extern void mmi_postcard_delete_one_recipient_without_popup(void);
extern void mmi_postcard_reset_all_recipients(void);
extern void mmi_postcard_entry_import_manual(void);
extern void mmi_postcard_entry_import_phonebook(void);
extern void mmi_frm_sh_postcard_exit_recipient_address_editor(void);
extern void mmi_postcard_entry_to_option_edit(void);
extern void mmi_postcard_set_recipient_address_custom_function(void);
extern U16 mmi_postcard_return_menu_root_icon(void);
extern void mmi_postcard_entry_to_option_save(void);
extern const kal_uint8 *mmi_postcard_get_mms_postcard_server_addr(void);
#endif /* __MMI_MMS_POSTCARD__ */ 
#endif /* _UC_POSTCARD_PROT_H */ 
