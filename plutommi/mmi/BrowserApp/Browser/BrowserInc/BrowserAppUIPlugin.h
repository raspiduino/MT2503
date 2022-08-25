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
 * BrowserAppUIPlugin.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPUIPLUGIN_H
#define MMI_BROWSERAPPUIPLUGIN_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"



extern void mmi_brw_app_ui_plugin_bookmarks_list_hilite_handler(S32 index);
extern void mmi_brw_app_ui_plugin_address_list_hilite_handler(S32 index);
extern void mmi_brw_app_ui_plugin_matched_list_highlight_hdlr(S32 index);
extern void mmi_brw_app_ui_plugin_bookmark_browse_path_hilite_handler(S32 item_index);
extern void mmi_brw_app_ui_plugin_select_bookmark_hilite_handler(S32 item_index);
extern void mmi_brw_app_ui_plugin_save_to_bookmark_screen_hilite_handler(U32 item_index);
extern void mmi_brw_app_ui_plugin_input_address_hilite_hdlr(void);

extern void mmi_brw_app_ui_plugin_recent_pages_list_hilite_handler(S32 index);
extern void mmi_brw_app_ui_plugin_trusted_certificate_list_hilite_handler(S32 index);
extern void mmi_brw_app_ui_plugin_stored_pages_list_hilite_handler(S32 index);
extern void mmi_brw_app_ui_plugin_page_objects_highlight_hdlr(S32 index);
extern void mmi_brw_app_ui_plugin_page_object_types_highlight_hdlr(S32 index);
extern void mmi_brw_app_ui_plugin_recent_pages_host_highlight_hdlr(S32 index);
extern void mmi_brw_app_ui_plugin_page_actions_highlight_hdlr(S32 index);
extern void mmi_brw_app_ui_plugin_shortcuts_list_hilite_handler(S32 index);


extern S8* mmi_brw_app_ui_plugin_get_encoding_method_hint(void);
#ifdef __BAIDU_TRANSCODING_SUPPORT__
extern CHAR* mmi_brw_app_ui_plugin_get_baidu_proxy_hint(void);
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
extern S8* mmi_brw_app_ui_plugin_get_screen_size_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_thumbnail_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_font_size_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_navigation_mode_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_rendering_mode_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_nine_way_hint(void);
extern S8* mmi_brw_app_ui_plugin_get_homepage_setting_hint(void);
extern U16 mmi_brw_app_ui_plugin_get_highlighted_rendering_mode(void);
extern U16 mmi_brw_app_ui_plugin_get_highlighted_navigation_mode(void);
extern U16 mmi_brw_app_ui_plugin_get_highlighted_font_size(void);
extern U16 mmi_brw_app_ui_plugin_get_highlighted_homepage_setting(void);


#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPUIPLUGIN_H */
