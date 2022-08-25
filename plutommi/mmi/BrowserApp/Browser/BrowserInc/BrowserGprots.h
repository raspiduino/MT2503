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
 * BrowserGprots.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains declaration of interfacing functions for external modules.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERGPROTS_H
#define BROWSERGPROTS_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "kal_general_types.h"

/* Interfaces for external modules */
extern mmi_ret mmi_brw_app_if_browser_app_init(mmi_event_struct *evt);
extern MMI_ID mmi_brw_pre_entry_internet_services(void);
extern MMI_BOOL mmi_brw_is_in_transaction(void);
extern U16 mmi_brw_get_error_string_id(void);
extern MMI_ID mmi_browser_app_launch_func(void* param, U32 param_size);

extern void mmi_brw_active_profile_changed(void);
extern void mmi_brw_active_profile_changed_without_ui(void);
extern void mmi_brw_set_as_homepage(U8 *url_p);
#ifdef OBIGO_Q05A
extern void mmi_brw_open_file_callback(void *fullname, int is_short);
#endif /* OBIGO_Q05A */
extern void mmi_brw_app_deinit(void);

#ifdef __MMI_VBOOKMARK__
extern S16 mmi_brw_add_to_bookmark(U8 *title_p, U8 *url_p);
extern void mmi_brw_bookmarks_recv_file_view(kal_uint8 *file_path, kal_uint8 *file_name);
extern void mmi_brw_bookmarks_recv_file_save_to_bookmark(kal_uint8 *file_path, kal_uint8 *file_name, kal_uint8 *file_extn);
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr(kal_uint8 *file_path, kal_uint8 *file_name, kal_uint8 *file_extn);
extern void mmi_brw_bookmarks_goto_from_fmgr(void *fullname, int is_short);
extern void mmi_brw_bookmarks_open_from_fmgr(void *fullname, int is_short);
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
#endif /* __MMI_VBOOKMARK__ */ 
extern void mmi_brw_start_browser_action(U8 option, U8 *url);
extern U16 mmi_brw_get_screen_id(void);
#ifdef OBIGO_Q05A 
extern void mmi_brw_open_file_from_fmgr(void *fullname, int is_short);
#endif /* OBIGO_Q05A */
extern void mmi_brw_memory_card_plug_out_hdlr(void);
extern void mmi_brw_wait_user_action_handler(
                int enable_positive_sk,
                const char *positive_label,
                int positive_label_len,
                int enable_negative_sk,
                const char *negative_label,
                int negative_label_len);

extern void mmi_brw_deinit_browser(void);
extern MMI_BOOL mmi_brw_is_wap_screen_present_between(U16 start_scr_id, U16 end_scr_id);
extern U16 mmi_brw_get_select_bookmark_screen_id(void);
extern MMI_BOOL mmi_brw_is_rendered_page_active(void);

/* Interfaces for external modules */

/* Interfaces of external modules */
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

extern void mms_content_insert_hdlr(char *content_source);
extern kal_uint16 wap_get_screen_id(void);
extern void resetAppMemPool(void);
extern void setAppMemPool(void *memory_addr);
extern void mmi_frm_appmem_prompt_to_release_mem(MMI_ID_TYPE app_name,
                                                 MMI_ID_TYPE app_icon,
                                                 U32 required_size, void (*success_callback) (void));

extern pBOOL mmi_bootup_is_sim_valid(void);
#if 0
/* under construction !*/
#endif //0
extern int FS_Rename(const WCHAR *FileName, const WCHAR *NewName);
extern void mmi_java_start_infusio_eureka_client(kal_char *command);
extern S32 mmi_brw_get_asm_memory_pool_size(void);

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 
/* Interfaces of external modules */
extern MMI_BOOL mmi_brw_is_rendered_page_present(void);
#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERGPROTS_H */ 

