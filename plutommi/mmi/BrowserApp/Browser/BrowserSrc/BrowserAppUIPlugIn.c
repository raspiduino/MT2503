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
 * BrowserUIPlugIn.c
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPUIPLUGIN_C
#define MMI_BROWSERAPPUIPLUGIN_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "BrowserAppInterface.h"
#include "BrowserAppDMgr.h"
#include "BrowserAppUICallback.h"
#include "InlineCuiGprot.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserAppScrHdlr.h"

/* To be removed */
#include "ServiceDefs.h"

#include "mmi_rp_app_browser_def.h"
#include "GlobalResDef.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "FileMgrSrvGProt.h"
#include "BrowserSrvProts.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_search.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "BrowserSrvInterface.h"
#include "BrowserSrvConfig.h"
#include "CustDataRes.h"
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "app_buff_alloc.h"
#include "string.h"
/* RHR activity */

/* Structure for Inline CUI */
cui_inline_item_caption_struct brw_bkm_inline_cui_title_caption_struct = {STR_ID_BRW_NAME};

cui_inline_item_caption_struct brw_bkm_inline_cui_address_caption_struct = {STR_GLOBAL_ADDRESS};

cui_inline_item_fullscreen_edit_struct  brw_bkm_inline_cui_title_full_edit_struct = {0,
                                                                                     STR_GLOBAL_EDIT, 
                                                                                     STR_GLOBAL_EDIT, 
                                                                                     SERVICES_WAP_IMAGE_ID, 
                                                                                     INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                     (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_ONE_LESS_CHARACTER),
                                                                                     SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1, 
                                                                                     NULL};


cui_inline_item_fullscreen_edit_struct  brw_bkm_inline_cui_address_full_edit_struct = {0,
                                                                                       STR_GLOBAL_EDIT, 
                                                                                       STR_GLOBAL_EDIT, 
                                                                                       SERVICES_WAP_IMAGE_ID, 
                                                                                       INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                       IMM_INPUT_TYPE_URL,
                                                                                       SRV_BRW_MAX_URL_LENGTH + 1, 
                                                                                       NULL};

cui_inline_item_display_only_struct  brw_bkm_inline_cui_title_display_struct = {0};

cui_inline_item_display_only_struct  brw_bkm_inline_cui_address_display_struct = {0};


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
cui_inline_item_fullscreen_edit_struct  brw_edit_shortcut_title_value_struct = {0,
                                                                                         STR_GLOBAL_EDIT, 
                                                                                         STR_ID_BRW_TITLE, 
                                                                                         SERVICES_WAP_IMAGE_ID, 
                                                                                         INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                         IMM_INPUT_TYPE_SENTENCE,
                                                                                         SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1,
                                                                                         NULL};
#endif

const cui_inline_set_item_struct brw_bkm_view_bookmark[] = 
{     
    {BRW_INLINE_TITLE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,          IMG_GLOBAL_L1, (void *)&brw_bkm_inline_cui_title_caption_struct},        
    {BRW_INLINE_TITLE,              CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_bkm_inline_cui_title_display_struct},      
    {BRW_INLINE_ADDRESS_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION ,         IMG_GLOBAL_L2, (void *)&brw_bkm_inline_cui_address_caption_struct},
    {BRW_INLINE_URL,                CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_bkm_inline_cui_address_display_struct},
};

const cui_inline_set_item_struct brw_bkm_add_bookmark[] = 
{     
    {BRW_INLINE_TITLE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,                 IMG_GLOBAL_L1, (void *)&brw_bkm_inline_cui_title_caption_struct},        
    {BRW_INLINE_TITLE,              CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT,     0, (void *)&brw_bkm_inline_cui_title_full_edit_struct},      
    {BRW_INLINE_ADDRESS_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION ,                IMG_GLOBAL_L2, (void *)&brw_bkm_inline_cui_address_caption_struct},
    {BRW_INLINE_URL,                CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT,     0, (void *)&brw_bkm_inline_cui_address_full_edit_struct},
};


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
const cui_inline_set_item_struct brw_edit_shortcut[] = 
{     
    {BRW_INLINE_TITLE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,                 IMG_GLOBAL_L1, (void *)&brw_bkm_inline_cui_title_caption_struct},        
    {BRW_INLINE_TITLE,              CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT,     0, (void *)&brw_edit_shortcut_title_value_struct},      
    {BRW_INLINE_ADDRESS_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION ,                IMG_GLOBAL_L2, (void *)&brw_bkm_inline_cui_address_caption_struct},
    {BRW_INLINE_URL,                CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT,     0, (void *)&brw_bkm_inline_cui_address_full_edit_struct},
};
#endif

const cui_inline_struct g_brw_bkm_initial_data_view_bookmark = 
{
    4,
    STR_GLOBAL_VIEW,
    SERVICES_WAP_IMAGE_ID,
    CUI_INLINE_SCREEN_DISABLE_DONE ,//| CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    brw_bkm_view_bookmark
};

const cui_inline_struct g_brw_bkm_initial_data_add_bookmark = 
{
    4,///
    STR_ID_BRW_ADD_BOOKMARK,
    SERVICES_WAP_IMAGE_ID, 
    CUI_INLINE_SCREEN_LOOP, //| CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    brw_bkm_add_bookmark
};

const cui_inline_struct g_brw_bkm_initial_data_edit_bookmark = 
{
    4,///
    STR_GLOBAL_EDIT,
    SERVICES_WAP_IMAGE_ID, 
    CUI_INLINE_SCREEN_LOOP, //| CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    brw_bkm_add_bookmark
};

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
const cui_inline_struct g_brw_initial_data_edit_shortcut = 
{
    4,///
    STR_GLOBAL_EDIT,
    SERVICES_WAP_IMAGE_ID, 
    CUI_INLINE_SCREEN_LOOP, //| CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    brw_edit_shortcut
};
#endif

#ifdef OBIGO_Q05A
cui_inline_item_caption_struct brw_obj_properties_name_caption_struct = {STR_ID_BRW_NAME};

cui_inline_item_caption_struct brw_obj_properties_address_caption_struct = {STR_GLOBAL_ADDRESS};

cui_inline_item_caption_struct brw_obj_properties_size_caption_struct = {STR_ID_BRW_CONTENT_SIZE};

cui_inline_item_caption_struct brw_obj_properties_date_caption_struct = {STR_GLOBAL_DATE};

cui_inline_item_display_only_struct brw_obj_properties_name_value_struct = {0};

cui_inline_item_display_only_struct brw_obj_properties_address_value_struct = {0};

cui_inline_item_display_only_struct brw_obj_properties_size_value_struct = {0};

cui_inline_item_display_only_struct brw_obj_properties_date_value_struct = {0};

const cui_inline_set_item_struct brw_obj_properties[] = 
{     
    {BRW_INLINE_NAME_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,          IMG_GLOBAL_L1, (void *)&brw_obj_properties_name_caption_struct},        
    {BRW_INLINE_NAME,                CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_obj_properties_name_value_struct},      
    {BRW_INLINE_URL_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION ,         IMG_GLOBAL_L2, (void *)&brw_obj_properties_address_caption_struct},
    {BRW_INLINE_ADDRESS,             CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_obj_properties_address_value_struct},
    {BRW_INLINE_SIZE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,          IMG_GLOBAL_L3, (void *)&brw_obj_properties_size_caption_struct},        
    {BRW_INLINE_SIZE,                CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_obj_properties_size_value_struct},      
    {BRW_INLINE_DATE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION ,         IMG_GLOBAL_L4, (void *)&brw_obj_properties_date_caption_struct},
    {BRW_INLINE_DATE,                CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0, (void *)&brw_obj_properties_date_value_struct},
    
};

const cui_inline_item_softkey_struct brw_obj_properties_softkeys =
{
    {
     {0, 0}, /* MMI_LEFT_SOFTKEY */
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, /* MMI_RIGHT_SOFTKEY */
     {0, 0}  /* MMI_CENTER_SOFTKEY */
     }
};

const cui_inline_struct g_brw_initial_data_obj_properties = 
{
    8,///
    STR_ID_BRW_PROPERTIES,
    SERVICES_WAP_IMAGE_ID, 
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    &brw_obj_properties_softkeys,
    brw_obj_properties
};
#endif

cui_inline_item_caption_struct brw_ren_page_inline_cui_username_caption_struct = {STR_GLOBAL_USERNAME};

cui_inline_item_caption_struct brw_ren_page_inline_cui_password_caption_struct = {STR_GLOBAL_PASSWORD};

#ifdef OBIGO_Q05A

cui_inline_item_caption_struct brw_ren_page_inline_cui_save_options_caption_struct = {STR_GLOBAL_OPTIONS};

#endif /* OBIGO_Q05A */


cui_inline_item_fullscreen_edit_struct  brw_ren_page_inline_cui_username_value_struct = {0,
                                                                                         STR_GLOBAL_EDIT, 
                                                                                         STR_GLOBAL_USERNAME, 
                                                                                         SERVICES_WAP_IMAGE_ID, 
                                                                                         INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                         IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE,
                                                                                         WAP_BAM_MAX_USER_PASSWD_LENGTH + 1,
                                                                                         NULL};


cui_inline_item_fullscreen_edit_struct  brw_ren_page_inline_cui_password_value_struct = {0,
                                                                                         STR_GLOBAL_EDIT, 
                                                                                         STR_GLOBAL_PASSWORD, 
                                                                                         SERVICES_WAP_IMAGE_ID, 
                                                                                         INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                         (IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD),
                                                                                         WAP_BAM_MAX_USER_PASSWD_LENGTH + 1, 
                                                                                         NULL};

#ifdef OBIGO_Q05A

cui_inline_item_select_struct  brw_ren_page_inline_cui_save_options_value_struct = {0,NULL, NULL};

#endif /* OBIGO_Q05A */

const cui_inline_set_item_struct brw_ren_page_auth[] = 
{     
    {BRW_AUTH_DLG_INLINE_USERNAME_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,            IMG_GLOBAL_L1, (void *)&brw_ren_page_inline_cui_username_caption_struct},        
    {BRW_AUTH_DLG_INLINE_USERNAME,                  CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,    0, (void *)&brw_ren_page_inline_cui_username_value_struct},      
    {BRW_AUTH_DLG_INLINE_PASSWORD_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION ,           IMG_GLOBAL_L2, (void *)&brw_ren_page_inline_cui_password_caption_struct},
    {BRW_AUTH_DLG_INLINE_PASSWORD,                  CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,    0, (void *)&brw_ren_page_inline_cui_password_value_struct},
#ifdef OBIGO_Q05A
    {BRW_AUTH_DLG_INLINE_SAVE_OPTION_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,            IMG_GLOBAL_L3, (void *)&brw_ren_page_inline_cui_save_options_caption_struct},        
    {BRW_AUTH_DLG_INLINE_SAVE_OPTION,               CUI_INLINE_ITEM_TYPE_SELECT,             0, (void *)&brw_ren_page_inline_cui_password_value_struct},      
#endif /* OBIGO_Q05A */
};

const cui_inline_struct g_brw_ren_initial_data_auth = 
{
    BRW_AUTH_DLG_INLINE_TOTAL - CUI_INLINE_ITEM_ID_BASE,
    STR_GLOBAL_AUTHENTICATION,
    SERVICES_WAP_IMAGE_ID, 
#ifdef OBIGO_Q05A
    CUI_INLINE_SCREEN_DISABLE_DONE |
#endif
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    brw_ren_page_auth
};




cui_inline_item_caption_struct brw_settings_inline_cui_pref_timeout_caption_struct = {STR_ID_BRW_TIMEOUT};

cui_inline_item_caption_struct brw_settings_inline_cui_pref_image_caption_struct = {STR_ID_BRW_SHOW_IMAGES};

#ifdef OBIGO_Q05A
cui_inline_item_caption_struct brw_settings_inline_cui_pref_vedio_caption_struct = {STR_ID_BRW_SHOW_VIDEOS};

cui_inline_item_caption_struct brw_settings_inline_cui_pref_sounds_caption_struct = {STR_ID_BRW_PLAY_SOUNDS};

cui_inline_item_caption_struct brw_settings_inline_cui_pref_unknown_media_caption_struct = {STR_ID_BRW_LOAD_UNKNOWN_MEDIA};

cui_inline_item_caption_struct brw_settings_inline_cui_pref_css_caption_struct = {STR_ID_BRW_CSS};

cui_inline_item_caption_struct brw_settings_inline_cui_pref_script_caption_struct = {STR_ID_BRW_SCRIPT};
#endif /* OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
cui_inline_item_caption_struct brw_settings_inline_cui_pref_cache_caption_struct = {STR_ID_BRW_CACHE};
#endif

cui_inline_item_caption_struct brw_settings_inline_cui_pref_cookies_caption_struct = {STR_ID_BRW_COOKIE};

#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
cui_inline_item_caption_struct brw_settings_inline_cui_pref_shortcut_caption_struct = {STR_ID_BRW_SHORTCUTS};
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
cui_inline_item_caption_struct brw_settings_inline_cui_pref_security_warning_caption_struct = {STR_ID_BRW_SECURITY_WARNINGS};
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
cui_inline_item_caption_struct brw_settings_inline_cui_pref_send_device_id_caption_struct = {STR_ID_BRW_SEND_DEVICE_ID};
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
cui_inline_item_caption_struct brw_settings_inline_cui_pref_session_info_caption_struct = {STR_ID_BRW_POST_SESSION_INFO};
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 



cui_inline_item_text_edit_struct brw_settings_inline_cui_pref_timeout_value_struct = {0,
                                                                                      0,
                                                                                      BRW_TIME_OUT_LEN + 1,
                                                                                      IMM_INPUT_TYPE_NUMERIC,
                                                                                      INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                                                                      NULL};
//TODO check why need to pass 123 input mode

cui_inline_item_select_struct brw_settings_inline_cui_pref_image_value_struct =  {0, 0, NULL };

#ifdef OBIGO_Q05A
cui_inline_item_select_struct brw_settings_inline_cui_pref_vedio_value_struct = {0,NULL, NULL};

cui_inline_item_select_struct brw_settings_inline_cui_pref_sounds_value_struct = {0,NULL, NULL};

cui_inline_item_select_struct brw_settings_inline_cui_pref_unknown_media_value_struct = {0,NULL, NULL};

cui_inline_item_select_struct brw_settings_inline_cui_pref_css_value_struct = {0,NULL, NULL};

cui_inline_item_select_struct brw_settings_inline_cui_pref_script_value_struct = {0,NULL, NULL};

#endif /* OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
cui_inline_item_select_struct brw_settings_inline_cui_pref_cache_value_struct = {0,NULL, NULL};
#endif

cui_inline_item_select_struct brw_settings_inline_cui_pref_cookies_value_struct = {0,NULL, NULL};

#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
cui_inline_item_select_struct brw_settings_inline_cui_pref_shortcut_value_struct = {0,NULL, NULL};

#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
cui_inline_item_select_struct brw_settings_inline_cui_pref_security_warning_value_struct = {0,NULL, NULL};

#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
cui_inline_item_select_struct brw_settings_inline_cui_pref_send_device_id_value_struct = {0,NULL, NULL};

#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
cui_inline_item_select_struct brw_settings_inline_cui_pref_session_info_value_struct = {0,NULL, NULL};

#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 


const cui_inline_set_item_struct brw_settings_pref[] = 
{     
    {BRW_PREFERENCES_INLINE_TIMEOUT_CAPTION,               CUI_INLINE_ITEM_TYPE_CAPTION,            0, (void *)&brw_settings_inline_cui_pref_timeout_caption_struct},        
    {BRW_PREFERENCES_INLINE_TIMEOUT_EDIT,                  CUI_INLINE_ITEM_TYPE_TEXT_EDIT,    0, (void *)&brw_settings_inline_cui_pref_timeout_value_struct},      
    {BRW_PREFERENCES_INLINE_SHOW_IMAGES_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_image_caption_struct},
    {BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT,            CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_image_value_struct},


#ifdef OBIGO_Q05A
    {BRW_PREFERENCES_INLINE_SHOW_VIDEOS_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION,            0, (void *)&brw_settings_inline_cui_pref_vedio_caption_struct},        
    {BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT,            CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_vedio_value_struct},      
    {BRW_PREFERENCES_INLINE_PLAY_SOUNDS_CAPTION,           CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_sounds_caption_struct},
    {BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT,            CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_sounds_value_struct},
    {BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,            0, (void *)&brw_settings_inline_cui_pref_unknown_media_caption_struct},        
    {BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_unknown_media_value_struct},      
    {BRW_PREFERENCES_INLINE_CSS_CAPTION,                   CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_css_caption_struct},
    {BRW_PREFERENCES_INLINE_CSS_SELECT,                    CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_css_value_struct},
    {BRW_PREFERENCES_INLINE_SCRIPT_CAPTION,                CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_script_caption_struct},
    {BRW_PREFERENCES_INLINE_SCRIPT_SELECT,                 CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_script_value_struct},
#endif /* OBIGO_Q05A */
#ifndef SLIM_WAP_MMS
    {BRW_PREFERENCES_INLINE_CACHE_CAPTION,                 CUI_INLINE_ITEM_TYPE_CAPTION,            0, (void *)&brw_settings_inline_cui_pref_cache_caption_struct},        
    {BRW_PREFERENCES_INLINE_CACHE_SELECT,                  CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_cache_value_struct},      
#endif
    {BRW_PREFERENCES_INLINE_COOKIE_CAPTION,                CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_cookies_caption_struct},
    {BRW_PREFERENCES_INLINE_COOKIE_SELECT,                 CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_cookies_value_struct},

#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    {BRW_PREFERENCES_INLINE_SHORTCUTS_CAPTION,             CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_shortcut_caption_struct},
    {BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT,             CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_shortcut_value_struct},
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    {BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_security_warning_caption_struct},
    {BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT,      CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_security_warning_value_struct},
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    {BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_send_device_id_caption_struct},
    {BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_send_device_id_value_struct},
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
    {BRW_PREFERENCES_INLINE_POST_SESSION_INFO_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION ,           0, (void *)&brw_settings_inline_cui_pref_session_info_caption_struct},
    {BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT,       CUI_INLINE_ITEM_TYPE_SELECT,    0, (void *)&brw_settings_inline_cui_pref_session_info_value_struct},
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 

};

const cui_inline_struct g_brw_settings_pref = 
{
    (BROWSER_PREFERENCES_ITEM_COUNT - (CUI_INLINE_ITEM_ID_BASE)),
    STR_ID_BRW_PREFERENCES,
    SERVICES_WAP_IMAGE_ID, 
    CUI_INLINE_SCREEN_LOOP, //| CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    brw_settings_pref
};


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_bookmarks_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of the Bookmarks list screen
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_bookmarks_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_cntx.sel_file_index = index;
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
#ifndef __MMI_OP12_BRW_DEFAULT_BOOKMARKS_EDITABLE__
    if(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[index].actual_index].type == SRV_BRW_BKM_TYPE_DEFAULT_FILE)
        wgui_icon_bar_set_item_enable_state(2,MMI_FALSE);
    else
        wgui_icon_bar_set_item_enable_state(2,MMI_TRUE);
    wgui_icon_bar_update();
#endif
#endif
#endif
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if (g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[index].actual_index].type != SRV_BRW_BKM_TYPE_FOLDER)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
    }
    else
#endif
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__ 
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    }
    SetCenterSoftkeyFunction(mmi_brw_app_ui_callback_bookmarks_list_csk_hdlr, KEY_EVENT_UP);
}

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_matched_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Auto completion screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_matched_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 input_type = IMM_INPUT_TYPE_URL;
    S32 addr_list_items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;

    if (index == CAT103_INVALID_HIGHLIGHT)
    {
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, (S8*) g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url);
    }
    else
    {
    #ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        addr_list_items = mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items();
        if(index < addr_list_items)
        {
            mmi_asc_to_ucs2(
                (S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url,
                (S8*) srv_brw_address_list_get_matched_item(index));
        }
        else
    #endif
        {
        #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
            if((index - addr_list_items) < mmi_brw_app_ui_callback_get_number_of_search_list_matched_items())
            {
                mmi_chset_utf8_to_ucs2_string((CHAR*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, (SRV_BRW_SEARCH_ITEM_LENGTH + 1) * ENCODING_LENGTH, 
                        (CHAR*)srv_brw_search_list_get_matched_item(index - addr_list_items));
            }
        #endif
        }
    }
    input_type = IMM_INPUT_TYPE_SENTENCE;
    wgui_cat103_refresh_input_area(g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, SRV_BRW_MAX_URL_LEN + 1, input_type);
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_bookmark_browse_path_hilite_handler
 * DESCRIPTION
 *  Highlight handler of the Bookmarks Browse path list screen
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_bookmark_browse_path_hilite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index = item_index;
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level && g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index == BRW_BKM_EXTERNAL_MEMORY_MENU_ITEM_INDEX)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCenterSoftkeyFunction(mmi_brw_app_if_browse_path_open_folder, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */ 
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetCenterSoftkeyFunction(mmi_brw_app_ui_callback_bookmarks_browse_path_list_csk_hdlr, KEY_EVENT_UP);
    }
    SetLeftSoftkeyFunction(mmi_brw_app_sh_browse_path_lsk_func, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_select_bookmark_hilite_handler
 * DESCRIPTION
 *  Highlight handler of the Insert Bookmark list screen
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_select_bookmark_hilite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_bkm_sel_bkm_cntx.sel_file_index = item_index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if (g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[item_index].actual_index].type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPEN, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_brw_app_dmgr_select_bookmark_open_folder, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_brw_app_dmgr_select_bookmark_open_folder, KEY_EVENT_UP);
    }
    else
#endif
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_brw_app_dmgr_select_bookmark_done, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_brw_app_dmgr_select_bookmark_done, KEY_EVENT_UP);
    }
}
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_recent_pages_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of Recent pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_recent_pages_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
	ChangeCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
#endif
	SetCenterSoftkeyFunction(mmi_brw_app_dmgr_launch_recent_pages_url, KEY_EVENT_UP);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_trusted_certificate_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of Trusted certificate list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_trusted_certificate_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
	SetCenterSoftkeyFunction(mmi_brw_app_ui_callback_trusted_certificate_csk_hdlr, KEY_EVENT_UP);
}


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_stored_pages_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of Stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_stored_pages_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
	ChangeCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
#endif
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_page_actions_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_page_actions_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetCenterSoftkeyFunction(mmi_brw_app_sh_page_actions_list_lsk_func, KEY_EVENT_UP);
}
#endif

#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_recent_pages_host_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_recent_pages_host_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_brw_app_dmgr_open_recent_page_host, KEY_EVENT_UP);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_stored_pages_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of Stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_page_objects_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = srv_brw_page_objects_get_actual_index(index);
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_brw_app_dmgr_pre_entry_page_object_options, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_page_object_types_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_page_object_types_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCenterSoftkeyFunction(mmi_brw_app_sh_page_object_types_lsk_func, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_encoding_method_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the encoding
 * method menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_encoding_method_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString((U16) g_brw_app_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].name_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_screen_size_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the screen
 * size menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_screen_size_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.screen_size_status)
    {
		return GetString(STR_ID_BRW_FULL);
    }
    else
    {
        return GetString(STR_GLOBAL_NORMAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_thumbnail_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the thumbnail
 * menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_thumbnail_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.thumbnail_status == wap_bam_setting_val_thumb_enable)
    {
        return GetString(STR_GLOBAL_ON);
    }
    else
    {
        return GetString(STR_GLOBAL_OFF);
    }
}


#ifdef __MMI_VECTOR_FONT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_font_size_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the font size
 * menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_font_size_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.font_size)
    {
        case BRW_FONT_SIZE_SMALL:
        {
            return GetString(STR_ID_BRW_SMALL);
            break;
        }
        case BRW_FONT_SIZE_LARGE:
        {
            return GetString(STR_ID_BRW_LARGE);
            break;
        }
        case BRW_FONT_SIZE_MEDIUM:
        default:
        {
            return GetString(STR_GLOBAL_MEDIUM);
            break;
        }
    }
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_navigation_mode_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the navigation
 * mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_navigation_mode_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.navigation_mode)
    {
        case wap_bam_setting_val_nav_2_way:
        {
            return GetString(STR_ID_BRW_TWO_WAY);
            break;
        }
        case wap_bam_setting_val_nav_scroll:
        {
            return  GetString(STR_ID_BRW_SCROLLING);
            break;
        }
        case wap_bam_setting_val_nav_4_way:
        default:
        {
            return GetString(STR_ID_BRW_FOUR_WAY);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_rendering_mode_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the rendering
 * mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_rendering_mode_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.rendering_mode)
    {
        case wap_bam_setting_val_rend_wrap:
        {
            return GetString(STR_ID_BRW_TEXT_WRAP);
            break;
        }
        case wap_bam_setting_val_rend_narrow:
        {
            return GetString(STR_ID_BRW_SCREEN_OPTIMIZED);
            break;
        }
        case wap_bam_setting_val_rend_text:
        {
            return GetString(STR_ID_BRW_TEXT_ONLY);
            break;
        }
        case wap_bam_setting_val_rend_normal:
        default:
        {
            return GetString(STR_ID_BRW_STANDARD);
            break;
        }
    }
}
#endif /* OBIGO_Q05A */
#ifdef __BAIDU_TRANSCODING_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_baidu_proxy_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the encoding
 * method menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* mmi_brw_app_ui_plugin_get_baidu_proxy_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.baidu_proxy_status)
    {
        return GetString(STR_GLOBAL_ON);
    }
    else
    {
        return GetString(STR_GLOBAL_OFF);
    }
}
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_shortcuts_list_hilite_handler
 * DESCRIPTION
 *  Highlight handler of shortcuts list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_plugin_shortcuts_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    if(srv_brw_shortcut_list_is_item_empty(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item))
    {
		ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    }
    else
    {
	    ChangeCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
    }
#endif
	SetCenterSoftkeyFunction(mmi_brw_app_ui_callback_shortcuts_list_csk_hdlr, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_nine_way_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the nine way
 * mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_nine_way_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_app_cntx.nine_way_mode)
    {
        return GetString(STR_GLOBAL_ON);
    }
    else
    {
        return GetString(STR_GLOBAL_OFF);
    }
}
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_homepage_setting_hint
 * DESCRIPTION
 *  This function is to get the hint string to be displayed in the nine way
 * mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_brw_app_ui_plugin_get_homepage_setting_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* url_ascii;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.homepage_setting == SRV_BRW_HOMEPAGE_SETTING_DEFAULT)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if(g_brw_app_cntx.brw_dynamic_cntx_p->is_using_wifi)
        {
            url_ascii = (CHAR*)srv_wap_prof_get_homepage(srv_brw_convert_sim_setting_to_profile_sim_id(SRV_BRW_ACTIVE_SIM_SETTING_WLAN), SRV_WAP_PROF_APPID_BRW, (U8) - 1);
        }
        else
    #endif
        {
            url_ascii = (CHAR*)srv_wap_prof_get_homepage(srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id), SRV_WAP_PROF_APPID_BRW, (U8) - 1);
        }
        mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*) url_ascii);
        OslMfree(url_ascii);
    }
    else
    {
        url_ascii = (U8*) srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
        memset(url_ascii, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
        srv_brw_get_user_defined_homepage(url_ascii);
        mmi_asc_n_to_ucs2((S8*) g_brw_current_url, (S8*) url_ascii, SRV_BRW_MAX_URL_LEN);
        srv_brw_free(url_ascii);
    }
    return ((S8*)g_brw_current_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_highlighted_homepage_setting
 * DESCRIPTION
 *  This function is to get the index of the menu item that should be selected
 * in the Homepage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_ui_plugin_get_highlighted_homepage_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.homepage_setting == SRV_BRW_HOMEPAGE_SETTING_DEFAULT)
    {
        return(MENU_ID_BRW_SETTING_HOMEPAGE_DEFAULT);
    }
    else
    {
        return(MENU_ID_BRW_SETTING_HOMEPAGE_USER_DEFINED);
    }
}
#endif

#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_highlighted_sort_option
 * DESCRIPTION
 *  This function is to get the index of the menu item that should be selected
 * in the rednering mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_ui_plugin_get_highlighted_sort_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.sorting_method)
    {
        case WAP_BAM_RECENT_PAGE_SORT_OPTION_FREQ:
        {
            return MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED;
            break;
        }
        case WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST:
        {
            return MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE;
            break;
        }
        case WAP_BAM_RECENT_PAGE_SORT_OPTION_LAST:
        default:
        {
            return MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED;
            break;
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_highlighted_rendering_mode
 * DESCRIPTION
 *  This function is to get the index of the menu item that should be selected
 * in the rednering mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_ui_plugin_get_highlighted_rendering_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.rendering_mode)
    {
        case wap_bam_setting_val_rend_wrap:
        {
            return(MENU_ID_BRW_RENDERING_MODES_TEXT_WRAP);
            break;
        }
        case wap_bam_setting_val_rend_narrow:
        {
            return(MENU_ID_BRW_RENDERING_MODES_SCREEN_OPTIMIZED);
            break;
        }
        case wap_bam_setting_val_rend_text:
        {
            return(MENU_ID_BRW_RENDERING_MODES_TEXT_ONLY);
            break;
        }
        case wap_bam_setting_val_rend_normal:
        default:
        {
            return(MENU_ID_BRW_RENDERING_MODES_STANDARD);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_highlighted_navigation_mode
 * DESCRIPTION
 *  This function is to get the index of the menu item that should be selected
 * in the navigation mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_ui_plugin_get_highlighted_navigation_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.navigation_mode)
    {
        case wap_bam_setting_val_nav_2_way:
        {
            return(MENU_ID_BRW_NAVIGATION_MODES_TWO_WAY);
            break;
        }
        case wap_bam_setting_val_nav_scroll:
        {
            return(MENU_ID_BRW_NAVIGATION_MODES_SCROLLING);
            break;
        }
        case wap_bam_setting_val_nav_4_way:
        default:
        {
            return(MENU_ID_BRW_NAVIGATION_MODES_FOUR_WAY);
            break;
        }
    }
}


#ifdef __MMI_VECTOR_FONT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_plugin_get_highlighted_font_size
 * DESCRIPTION
 *  This function is to get the index of the menu item that should be selected
 * in the font size screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_brw_app_ui_plugin_get_highlighted_font_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_brw_cntx.font_size)
    {
        case BRW_FONT_SIZE_SMALL:
        {
            return(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_SMALL);
            break;
        }
        case BRW_FONT_SIZE_LARGE:
        {
            return(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_LARGE);
            break;
        }
        case BRW_FONT_SIZE_MEDIUM:
        default:
        {
            return(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_MEDIUM);
            break;
        }
    }
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

#endif /* OBIGO_Q05A */

#endif /* __MMI_BROWSER_2__ */
#endif /* MMI_BROWSERAPPUIPLUGIN_C */
