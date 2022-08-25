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
 *  SearchWebGoogle.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Google search: idle shortcut bar
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SEARCH_WEB_GOOGLE__

#include "SearchWebGoogleProt.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_mainmenu_def.h"         /* MAIN_MENU_TITLE_SETTINGS_ICON */
#include "mmi_rp_app_search_web_def.h"
#include "mmi_rp_app_phonesetting_new_def.h" /* MENU_ID_SETTING_GOOGLE_HINT_ENTRY */


static const mmi_sweb_google_dvalues_struct g_mmi_sweb_google_dvalues =
{
    NVRAM_SEARCH_WEB_GOOGLE_HINT_SETTING,
    
    GRP_ID_SEARCH_WEB_GOOGLE,
    SCR_ID_SEARCH_WEB_GOOGLE_SEARCH_BAR,
    
    STR_ID_SEARCH_WEB_GOOGLE_APP_NAME,
    STR_ID_SEARCH_WEB_GOOGLE_IDLE_HINT_TEXT,
    STR_ID_SEARCH_WEB_GOOGLE_HINT_SETTING,
    STR_ID_SEARCH_WEB_REQUEST_SEARCH,
    
    MAIN_MENU_TITLE_SETTINGS_ICON,
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    IMG_ID_SEARCH_WEB_SEARCH_BUTTON,
    IMG_ID_SEARCH_WEB_SEARCH_BUTTON_PRESSED,
#endif

    MENU_ID_SEARCH_WEB_GOOGLE_OPTIONS,
    MENU_ID_SEARCH_WEB_GOOGLE_SEARCH,
    MENU_ID_SETTING_GOOGLE_HINT_ENTRY,
    MENU_ID_SEARCH_WEB_GOOGLE_HINT_SETTING,
    MENU_ID_SEARCH_WEB_GOOGLE_HINT_OFF,
    MENU_ID_SEARCH_WEB_GOOGLE_HINT_ON,
    
    EVT_ID_CUI_MENU_LIST_ENTRY,
    EVT_ID_CUI_MENU_ITEM_SELECT,
    EVT_ID_CUI_MENU_CLOSE_REQUEST
};


const mmi_sweb_google_dvalues_struct* mmi_sweb_google_get_dvalues(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (&g_mmi_sweb_google_dvalues);
}


#endif /* __MMI_SEARCH_WEB_GOOGLE__ */
