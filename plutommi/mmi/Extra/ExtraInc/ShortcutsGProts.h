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
 *  ShortcutsGProts.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ShortcutsGProts.h

   PURPOSE     : Shortcuts application 

   REMARKS     : nil

   AUTHOR      : Yibo Liu

   DATE     : April 25,08

**************************************************************/
#ifndef _MMI_SHORTCUTS_GPROTS_H
#define _MMI_SHORTCUTS_GPROTS_H
#include "MMI_features.h"
#if !defined(__DISABLE_SHORTCUTS_IMPL__) && defined(__PLUTO_MMI_PACKAGE__)
#include "mmi_rp_app_shortcuts_def.h"
#include "ShortcutsDefs.h"
#include "menucuigprot.h"
#ifdef __J2ME__
#include "JavaAgencyGprot.h"
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"

extern void mmi_shct_launch_quick_menu_cfg(void);
extern void mmi_shct_launch_quick_menu_cfg_ext(MMI_ID parent_gid);
extern void mmi_shct_launch_app(MMI_MENU_ID menu_id);
extern mmi_ret mmi_shct_menu_handler(cui_menu_event_struct *event, MMI_ID parent_gid);
extern U32 mmi_shct_get_candidate_list_count(void);
extern MMI_STR_ID mmi_shct_get_str_by_candidate_list_index(S32 index);
extern void mmi_shct_launch_app_by_candidate_list_index(S32 index);
extern void mmi_shct_del_system_maping_files(void);

extern void mmi_shct_dynamic_register(MMI_ID menu_id, MMI_BOOL register_flag);
extern MMI_BOOL mmi_shct_check_dynamic_unreg_menu(MMI_ID menu_id);

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#ifdef __J2ME__
extern void mmi_shct_entry_java_sel(void);
extern void mmi_shct_java_sel_cb(mmi_java_select_mids_info_struct *sel_mids_info);
extern void mmi_shct_java_del_notify(CHAR *java_mid_storage_name);
extern void mmi_shct_java_launch_midlet(MMI_ID java_mid_id);
extern WCHAR *mmi_shct_get_java_midlet_str(MMI_ID java_mid_id);
extern CHAR *mmi_shct_get_java_midlet_icon(MMI_ID java_mid_id);
extern MMI_ID mmi_shct_add_java_mid_id_to_map_file(CHAR *mids_storage_name);
extern void mmi_shct_get_java_storage_name_from_map_file(const MMI_ID java_mid_id, CHAR *mids_storage_name);
extern MMI_ID mmi_shct_get_java_mid_id_from_map_file(CHAR *mids_storage_name);
extern void mmi_shct_del_java_mid_id_in_map_file(MMI_ID mid_id);
#endif /* __J2ME__ */

#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
extern void mmi_shct_entry_brw_bkm_sel(void);
extern mmi_ret mmi_shct_brw_bkm_sel_cb(mmi_event_struct *evt);
MMI_ID mmi_shct_brw_bkm_save(U8 *title, U8 *url);
void mmi_shct_brw_bkm_del_url(MMI_ID brw_bkm_id);
void mmi_shct_brw_bkm_get_title(MMI_ID brw_bkm_id, U8 *title);
void mmi_shct_brw_bkm_get_url(MMI_ID brw_bkm_id, U8 *url);
void mmi_shct_brw_bkm_get_display_str(MMI_ID brw_bkm_id, WCHAR *string);
void mmi_shct_brw_bkm_launch_url(MMI_ID brw_bkm_id);
#endif /* defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) */
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
extern mmi_ret mmi_shct_dedicated_key_menu_handler(cui_menu_event_struct *event, MMI_ID parent_gid);
extern WCHAR* mmi_shct_get_nav_key_str(mmi_shct_nav_key_enum nav_key);
typedef void(*mmi_shct_sel_shct_cb)(mmi_shct_nav_key_enum nav_key);
extern MMI_BOOL mmi_shct_interface_sel_nav_key_shct(mmi_shct_nav_key_enum nav_key, mmi_shct_sel_shct_cb cb_func);
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */
#endif /* __DISABLE_SHORTCUTS_IMPL__ */
#endif /* _MMI_SHORTCUTS_GPROTS_H */

