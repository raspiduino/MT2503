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
 *  SearchWebBaiduProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface definition of Baidu Search
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_SEARCH_WEB_BAIDU_PROT_H__
#define __MMI_SEARCH_WEB_BAIDU_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "SearchWebProt.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "kal_general_types.h"
#include "SearchWebGProt.h"
#include "common_nvram_editor_data_item.h"

#ifdef __MMI_SEARCH_WEB_BAIDU__

/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_SEARCH_WEB_BAIDU_VERSION                "1.00"


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET = 0,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_IMAGE,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_NEWS,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_FORUM,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_KNOWLEDGE,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_WEATHER,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_DICTIONARY,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_SPACE,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_MAP,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_OTHERS,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_WEB_HELP,

    MMI_SEARCH_WEB_BAIDU_CATEGORY_TOTAL,
    MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM = MMI_SEARCH_WEB_BAIDU_CATEGORY_TOTAL
} mmi_search_web_baidu_category_enum;

typedef enum
{
    MMI_SEARCH_WEB_BAIDU_QUERY,
    MMI_SEARCH_WEB_BAIDU_VISIT,

    MMI_SEARCH_WEB_BAIDU_BROWSING_TYPE_END_OF_ENUM
} mmi_search_web_baidu_browsing_type_enum;

typedef struct
{
    mmi_search_web_baidu_category_enum category;
    mmi_search_web_baidu_browsing_type_enum browsing_type;
    U16 logo_icon_id;
    CHAR* (*generate_url)(const U16 *input, CHAR *url, U32 url_buffer_size);
} mmi_sweb_baidu_category_struct;

/*
 * Because the menu contains dynamic data, each item of them should be allocated
 * an unique menu ID. In order to control the ranges of menu ID, we declare them
 * here instead of in GLOBALMENUITEMSID.
 */
typedef enum
{
    MMI_SEARCH_WEB_BAIDU_MENU_ROOT                  = 0,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_REQUEST_SEARCH   = 0x10,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY          = 0x20,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CLEAR_HISTORY,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DEFAULT_CATEGORY = 0x30,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_INTERNET,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_IMAGE,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_NEWS,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_FORUM,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_KNOWLEDGE,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY          = 0x40,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DOWN_KEY,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_LONG_PRESS_STAR,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY_DISABLED,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_MORE             = 0x50,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_WEATHER,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_DICTIONARY,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_SPACE,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_MAP,
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_OTHERS,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HELP             = 0x60,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_EXIT             = 0x70,

    /* ID for dynamic items */
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN = 0x80,
    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_END   =
        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN + MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM,

    MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM
} mmi_search_web_baidu_menu_item_enum;

typedef struct
{
    mmi_search_web_baidu_menu_item_enum menu_item_id;
    U8 level;
    U16 string_id;
} mmi_sweb_baidu_menu_config_struct;

typedef struct mmi_sweb_baidu_menu_iter_struct_s
{
    /* PRIVATE */
    U32 index;
    /* PUBLIC */
    MMI_BOOL (*is_valid)(const struct mmi_sweb_baidu_menu_iter_struct_s *iter);
    const mmi_sweb_baidu_menu_config_struct* (*get_data)(const struct mmi_sweb_baidu_menu_iter_struct_s *iter);
    void (*next)(struct mmi_sweb_baidu_menu_iter_struct_s *iter);
} mmi_sweb_baidu_menu_iter_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

extern void mmi_sweb_baidu_init(void);
extern MMI_BOOL mmi_sweb_baidu_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key);

/* Following function are required by Baidu widget */
extern void mmi_sweb_baidu_init_cntx(void);
extern void mmi_sweb_baidu_release_cntx(void);
extern void mmi_sweb_baidu_request_browsing(
    mmi_search_web_baidu_category_enum category,
    const U16 *input);
extern mmi_search_web_baidu_category_enum mmi_sweb_baidu_get_default_category(void);
extern void mmi_sweb_baidu_set_default_category(mmi_search_web_baidu_category_enum category);
extern const nvram_ef_search_web_history_entry_struct* mmi_sweb_baidu_get_history_entry(U32 index);

extern const mmi_sweb_baidu_category_struct*
    mmi_sweb_baidu_get_category_config(mmi_search_web_baidu_category_enum category);
extern void mmi_sweb_baidu_menu_iter_init(mmi_sweb_baidu_menu_iter_struct *iter);
extern mmi_search_web_baidu_category_enum mmi_sweb_baidu_menu_id_to_category(
    mmi_search_web_baidu_menu_item_enum menu_item_id);

extern const CHAR *mmi_sweb_baidu_get_uid(void);
extern const CHAR *mmi_sweb_baidu_get_from_param_value(void);
extern MMI_BOOL mmi_sweb_baidu_get_idle_hint_config(const U8 **icon_data, const WCHAR **string);

#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#endif /* __MMI_SEARCH_WEB_BAIDU_PROT_H__ */

