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
 *  SearchWebGoogleProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface definition of Google Search
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

#ifndef __MMI_SEARCH_WEB_GOOGLE_PROT_H__
#define __MMI_SEARCH_WEB_GOOGLE_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "SearchWebGprot.h"


#ifdef __MMI_SEARCH_WEB_GOOGLE__

#ifdef WAP_SEC_SUPPORT
#define __MMI_GOOGLE_SHCU_SUPPORT__
#endif

typedef struct
{
    U16 nvram_hint_setting_id;
    
    MMI_ID search_bar_grp_id;
    MMI_ID search_bar_scr_id;
    
    MMI_ID str_app_name;
    MMI_ID str_idle_hint_text;
    MMI_ID str_hint_setting;
    MMI_ID str_request_search;
    
    MMI_ID img_setting_menu_title;
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    MMI_ID img_search_button;
    MMI_ID img_search_button_pressed;
#endif

    MMI_MENU_ID menu_options;
    MMI_MENU_ID menu_search;
    MMI_MENU_ID menu_setting_entry;
    MMI_MENU_ID menu_setting_main;
    MMI_MENU_ID menu_setting_hint_off;
    MMI_MENU_ID menu_setting_hint_on;
    
    U16 evt_menu_entry;
    U16 evt_item_selected;
    U16 evt_menu_close;
} mmi_sweb_google_dvalues_struct;


const mmi_sweb_google_dvalues_struct* mmi_sweb_google_get_dvalues(void);


MMI_BOOL mmi_sweb_google_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key);

void mmi_search_web_google_open_search_bar(void);

MMI_BOOL mmi_sweb_google_get_idle_hint_config(const U8 **icon_data, const WCHAR **string);

const WCHAR* mmi_sweb_google_get_app_name(void);


const U8* mmi_sweb_google_get_hint_icon(void);

const U8* mmi_sweb_google_get_logo(void);

#endif /* __MMI_SEARCH_WEB_GOOGLE__ */


#endif /* __MMI_SEARCH_WEB_GOOGLE_PROT_H__ */

