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
 *  SearchWebGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global interface definition.
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

#ifndef __MMI_SEARCH_WEB_GPROT_H__
#define __MMI_SEARCH_WEB_GPROT_H__
 
/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "menucuigprot.h"

#ifdef __MMI_SEARCH_WEB__

/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * Possible hot keys.
 */
typedef enum
{
    MMI_SEARCH_WEB_HOT_KEY_NONE             = 0,    /* No hot key is enabled */
    MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY         = 0x1,  /* Down arrow key */
    MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR  = 0x2,  /* Long pressing * (star key) */
    MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT       = 0x10, /* Touch the hint */

    MMI_SEARCH_WEB_HOT_KEY_LONG_END_OF_ENUM
} mmi_search_web_hot_key_enum;


/****************************************************************************
 * Global Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_init
 * DESCRIPTION
 *  Initialize search module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_hot_key_is_enabled
 * DESCRIPTION
 *  Check whether the hot key is enabled.
 * PARAMETERS
 *  hot_key     : [IN] Hot key type
 * RETURNS
 *  MMI_TRUE if enabled.
 *****************************************************************************/
extern MMI_BOOL mmi_search_web_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_hot_key
 * DESCRIPTION
 *  Trigger search application. After called the search application corresponding
 *  to the hot key will be launched.
 * PARAMETERS
 *  hot_key     : [IN] Hot key type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_trigger_by_hot_key(mmi_search_web_hot_key_enum hot_key);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_down_key
 * DESCRIPTION
 *  Trigger search application when DOWN key is pressed. After called the search
 *  application which enables DOWN key will be launched.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_trigger_by_down_key(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_down_key
 * DESCRIPTION
 *  Trigger search application when star key is long pressed. After called
 *  the search application which enables LOND_PRESS_STAR will be launched.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_trigger_by_long_pressing_star(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_get_application_name
 * DESCRIPTION
 *  Get the application name for the hot key.
 * PARAMETERS
 *  hoy_key     [IN] Hot key
 * RETURNS
 *  Application name
 *****************************************************************************/
extern const U16 *mmi_search_web_get_application_name(mmi_search_web_hot_key_enum hot_key);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_entry_dedicated_key_setting
 * DESCRIPTION
 *  User tries to modify the dedicated key setting. Show message to prompt user.
 * PARAMETERS
 *  hoy_key     [IN] Hot key
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_entry_dedicated_key_setting(mmi_search_web_hot_key_enum hot_key);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_get_idle_hint
 * DESCRIPTION
 *  Get the hint icon & string on idle screen.
 * PARAMETERS
 *  icon_data   [OUT] Pointer of the icon image data
 *  string      [OUT] Pointer of the string content
 * RETURN VALUES
 *  MMI_TRUE  : if the configuration is available & hint should be shown.
 *  MMI_FALSE : Do not show hint on idle, the return values are invalid.
 *****************************************************************************/
extern MMI_BOOL mmi_search_web_get_idle_hint(const U8 **icon_data, const WCHAR **string);


#ifdef __MMI_SEARCH_WEB_BAIDU__
/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_baidu_open_search_bar
 * DESCRIPTION
 *  The entry point of Baidu search bar. Launch Baidu search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_baidu_open_search_bar(void);
#endif

#ifdef __MMI_SEARCH_WEB_GOOGLE__

/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_google_set_menu_hint
 * DESCRIPTION
 *  Set the hint of Google search setting.
 *  This function is called by setting menu.
 * PARAMETERS
 *  menu_cui_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_search_web_google_set_menu_hint(MMI_ID menu_cui_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_google_sub_menu_handler
 * DESCRIPTION
 *  Menu proc for setting menu.
 * PARAMETERS
 *  param           [IN]
 *  parent_gid      [IN]
 * RETURNS
 *  MMI_RET_DONT_CARE if not processed
 *****************************************************************************/
extern mmi_ret mmi_search_web_google_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);

#endif


#endif /* __MMI_SEARCH_WEB__ */

#endif /* __MMI_SEARCH_WEB_GPROT_H__ */

