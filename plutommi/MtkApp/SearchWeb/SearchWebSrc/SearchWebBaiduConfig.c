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
 *  SearchBaiduConfig.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Configuration for Baidu Search.
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
 
/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SEARCH_WEB_BAIDU__

#include "SearchWebBaiduProt.h"
#include "SearchWebBaiduConfig.h"
#include "MMIDataType.h"
#include "mmi_rp_app_search_web_def.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "string.h"
#include "SearchWebProt.h"
#include "stdio.h"
#include "Conversions.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_SEARCH_WEB_BAIDU_INTERNET_URL   "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_IMAGE_URL      "http://wap.baidu.com/img"
#define MMI_SEARCH_WEB_BAIDU_NEWS_URL       "http://wap.baidu.com/news"
#define MMI_SEARCH_WEB_BAIDU_FORUM_URL      "http://wapp.baidu.com/f"
#define MMI_SEARCH_WEB_BAIDU_KNOWLEDGE_URL  "http://wapiknow.baidu.com/index"
#define MMI_SEARCH_WEB_BAIDU_WEATHER_URL    "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_SPACE_URL      "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_MAP_URL        "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_DICTIONARY_URL "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_OTHERS_URL     "http://wap.baidu.com/s"
#define MMI_SEARCH_WEB_BAIDU_WEB_HELP_URL \
    "http://wapp.baidu.com/f?kw=%E7%99%BE%E5%BA%A6%E6%89%8B%E6%9C%BA%E6%90%9C%E7%B4%A2%E5%B8%AE%E5%8A%A9"


/****************************************************************************
 * Function Declarations
 ****************************************************************************/

static CHAR *mmi_sweb_baidu_generate_url_internet(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_image(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_news(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_forum(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_knowledge(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_weather(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_space(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_dictionary(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_map(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_others(const U16 *input, CHAR *url, U32 url_buffer_size);
static CHAR *mmi_sweb_baidu_generate_url_web_help(const U16 *input, CHAR *url, U32 url_buffer_size);


/****************************************************************************
 * Configurations
 ****************************************************************************/

/*
 * The category configurations. Baidu search will look up this table to know
 * the logo image ID, the browing type, the URL generating function.
 */
static const mmi_sweb_baidu_category_struct mmi_sweb_baidu_category_list[] =
{
    /* Internet */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        IMG_ID_SEARCH_WEB_BAIDU_INTERNET,
        mmi_sweb_baidu_generate_url_internet
    },
    /* Image */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_IMAGE,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        IMG_ID_SEARCH_WEB_BAIDU_IMAGE,
        mmi_sweb_baidu_generate_url_image
    },
    /* News */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_NEWS,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        IMG_ID_SEARCH_WEB_BAIDU_NEWS,
        mmi_sweb_baidu_generate_url_news
    },
    /* Forum */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_FORUM,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        IMG_ID_SEARCH_WEB_BAIDU_FORUM,
        mmi_sweb_baidu_generate_url_forum
    },
    /* Knowledge */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_KNOWLEDGE,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        IMG_ID_SEARCH_WEB_BAIDU_KNOWLEDGE,
        mmi_sweb_baidu_generate_url_knowledge
    },
    /* Weather */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_WEATHER,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        0,
        mmi_sweb_baidu_generate_url_weather
    },
    /* Dictionary */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_DICTIONARY,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        0,
        mmi_sweb_baidu_generate_url_dictionary
    },
    /* Space */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_SPACE,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        0,
        mmi_sweb_baidu_generate_url_space
    },
    /* Map */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_MAP,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        0,
        mmi_sweb_baidu_generate_url_map
    },
    /* Others */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_OTHERS,
        MMI_SEARCH_WEB_BAIDU_QUERY,
        0,
        mmi_sweb_baidu_generate_url_others
    },
    /* Web help */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_WEB_HELP,
        MMI_SEARCH_WEB_BAIDU_VISIT,
        0,
        mmi_sweb_baidu_generate_url_web_help
    },
    /* -- Please add new category before this marker -- */
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM,
        MMI_SEARCH_WEB_BAIDU_BROWSING_TYPE_END_OF_ENUM,
        0,
        NULL
    }
};

/*
 * Number of entries of the category configuration table.
 * This value will be calculated by compiler, do not need to modify this variable.
 */
static const U32 mmi_sweb_baidu_category_config_num =
    sizeof(mmi_sweb_baidu_category_list)/sizeof(mmi_sweb_baidu_category_struct) - 1;


/*
 * Configuration of the cascading menu of Options.
 * The menu items are listed by pre-order here. We only support 2-level cascading menu,
 * so the level shall not be larger tan 2.
 * MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA indicates the history data and will be
 * generated dynamically. History data items should be put in 2nd level of menu.
 */
static const mmi_sweb_baidu_menu_config_struct mmi_sweb_baidu_menu_config[] =
{
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_REQUEST_SEARCH,        1, STR_ID_SEARCH_WEB_REQUEST_SEARCH },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY,               1, STR_ID_SEARCH_WEB_HISTORY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA,          2, 0 }, /* Dynamic data */
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CLEAR_HISTORY,         2, STR_ID_SEARCH_WEB_CLEAR_HISTORY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DEFAULT_CATEGORY,      1, STR_ID_SEARCH_WEB_BAIDU_DEFAULT_CATEGORY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_INTERNET,     2, STR_ID_SEARCH_WEB_BAIDU_INTERNET },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_IMAGE,        2, STR_ID_SEARCH_WEB_IMAGE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_NEWS,         2, STR_ID_SEARCH_WEB_NEWS },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_FORUM,        2, STR_ID_SEARCH_WEB_BAIDU_FORUM },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_KNOWLEDGE,    2, STR_ID_SEARCH_WEB_BAIDU_KNOWLEDGE },
#if !defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__) /* We don't provide hot key on Baidu widget projects */
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY,               1, STR_ID_SEARCH_WEB_HOT_KEY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DOWN_KEY,              2, STR_ID_SEARCH_WEB_DOWN_KEY },
#if !defined(__MMI_REDUCED_KEYPAD__)
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_LONG_PRESS_STAR,       2, STR_ID_SEARCH_WEB_LONG_PRESS_STAR },
#endif
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY_DISABLED,      2, STR_ID_SEARCH_WEB_DISABLE },
#endif /* !defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__) */
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_MORE,                  1, STR_ID_SEARCH_WEB_MORE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_WEATHER,         2, STR_ID_SEARCH_WEB_BAIDU_WEATHER },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_DICTIONARY,      2, STR_ID_SEARCH_WEB_BAIDU_DICTIONARY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_SPACE,           2, STR_ID_SEARCH_WEB_BAIDU_SPACE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_MAP,             2, STR_ID_SEARCH_WEB_BAIDU_MAP},
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_OTHERS,                2, STR_ID_SEARCH_WEB_OTHERS },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HELP,                  1, STR_GLOBAL_HELP },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_EXIT,                  1, STR_GLOBAL_EXIT },
    
    /* -- Please configure menu items before this marker -- */
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM,           0, 0 }
};


/*
 * The table maps menu item ID to category.
 * If you added an new menu item for new category, please also add a new entry here.
 */
static const struct {
    mmi_search_web_baidu_menu_item_enum menu_item_id;
    mmi_search_web_baidu_category_enum  category;
} mmi_sweb_baidu_menu_category_table[] =
{
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_INTERNET, MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_IMAGE,    MMI_SEARCH_WEB_BAIDU_CATEGORY_IMAGE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_NEWS,     MMI_SEARCH_WEB_BAIDU_CATEGORY_NEWS },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_FORUM,    MMI_SEARCH_WEB_BAIDU_CATEGORY_FORUM },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_KNOWLEDGE, MMI_SEARCH_WEB_BAIDU_CATEGORY_KNOWLEDGE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_WEATHER,     MMI_SEARCH_WEB_BAIDU_CATEGORY_WEATHER },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_DICTIONARY,  MMI_SEARCH_WEB_BAIDU_CATEGORY_DICTIONARY },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_SPACE,       MMI_SEARCH_WEB_BAIDU_CATEGORY_SPACE },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_MAP,         MMI_SEARCH_WEB_BAIDU_CATEGORY_MAP },
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_OTHERS,            MMI_SEARCH_WEB_BAIDU_CATEGORY_OTHERS },
    /* -- Please add new mapping before this marker -- */
    { MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM,       0 }
};


/****************************************************************************
 * Configuration Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_screen_size
 * DESCRIPTION
 *  Get the screen size of device.
 * PARAMETERS
 *  width   [OUT] Screen width
 *  height  [OUT] Screen height
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_get_screen_size(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S32 UI_device_width;
    extern S32 UI_device_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = UI_device_width;
    *height = UI_device_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_append_vit
 * DESCRIPTION
 *  Append vit parameter to the URL.
 * PARAMETERS
 *  url             [IN/OUT] Target URL
 *  first_param     [OUT]    Whether it is the first parameter of the URL.
 *                           If MMI_TRUE, '?' will be concatenated before the
 *                           parameter. Otherwise '&' will be concatenated.
 * RETURNS
 *  The position of the null terminator '\0' of the result URL string.
 *****************************************************************************/
#define mmi_sweb_baidu_append_vit(url, first_param) \
    mmi_sweb_append_url_param(url, first_param, "vit", "union")


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_append_common_param
 * DESCRIPTION
 *  Append common parameters. It will append "from", "uid", and "ua".
 * PARAMETERS
 *  url             [IN/OUT] Target URL
 *  first_param     [OUT]    Whether it is the first parameter of the URL.
 *                           If MMI_TRUE, '?' will be concatenated before the
 *                           parameter. Otherwise '&' will be concatenated.
 * RETURNS
 *  The position of the null terminator '\0' of the result URL string.
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_append_common_param(CHAR *url, MMI_BOOL first_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;
    S32 dev_width, dev_height;
    CHAR buffer[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_tail = url + strlen(url);

    /* "from" */
    url_tail = mmi_sweb_append_url_param(url_tail, first_param, "from", mmi_sweb_baidu_get_from_param_value());

    /* "uid" */
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "uid", mmi_sweb_baidu_get_uid());

    /* "ua" */
    mmi_sweb_baidu_get_screen_size(&dev_width, &dev_height);
    sprintf(buffer, "mtk_%d_%d", dev_width, dev_height);
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "ua", buffer);

    return url_tail;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_append_bd_page_type
 * DESCRIPTION
 *  Append parameter "bg_page_type", which control the output format of Baidu's
 *  webpage. The "bg_page_type" is configurated by
 *  MMI_SEARCH_WEB_BAIDU_DEFAULT_BD_PAGE_TYPE.
 * PARAMETERS
 *  url             [IN/OUT] Target URL
 *  first_param     [OUT]    Whether it is the first parameter of the URL.
 *                           If MMI_TRUE, '?' will be concatenated before the
 *                           parameter. Otherwise '&' will be concatenated.
 * RETURNS
 *  The position of the null terminator '\0' of the result URL string.
 * SEE ALSO
 *  mmi_sweb_baidu_bd_page_type_enum
 *****************************************************************************/
#define mmi_sweb_baidu_append_bd_page_type(url, first_param) \
    mmi_sweb_append_url_param_int(url, first_param, "bd_page_type", MMI_SEARCH_WEB_BAIDU_DEFAULT_BD_PAGE_TYPE)


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_append_input
 * DESCRIPTION
 *  Append input string to the URL. It will encode the input to escaped UTF-8
 *  before appending.
 * PARAMETERS
 *  url             [IN/OUT] Target URL
 *  first_param     [OUT]    Whether it is the first parameter of the URL.
 *                           If MMI_TRUE, '?' will be concatenated before the
 *                           parameter. Otherwise '&' will be concatenated.
 *  param_name      [IN]     The name of parameter
 *  input           [IN]     UCS-2 string of input. It will be encoded to escaped
 *                           UTF-8 before appending.
 *  url_buffer_size [IN]     Maximum appending length of url including the '\0'
 * RETURNS
 *  The position of the null terminator '\0' of the result URL string.
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_append_input(
    CHAR *url,
    MMI_BOOL first_param,
    const CHAR *param_name,
    const U16 *input,
    U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_tail = url;
    
    if (input != NULL && input[0] != L'\0') /* Length(input) > 0 */
    {
        url_tail = mmi_sweb_append_url_param_ucs2(
            url_tail,
            first_param,
            param_name,
            input,
            MMI_SEARCH_WEB_BAIDU_DEFAULT_URL_ENCODING,
            url_buffer_size,
            NULL);
    }

    return url_tail;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_internet
 * DESCRIPTION
 *  Generate the URL to search web pages.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_internet(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_INTERNET_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_bd_page_type(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    input, url_buffer_size - (url_tail - url));

    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_image
 * DESCRIPTION
 *  Generate the URL to search images.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_image(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_IMAGE_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_bd_page_type(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "tn", "bdwis");
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    input, url_buffer_size - (url_tail - url));
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_news
 * DESCRIPTION
 *  Generate the URL to search news.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_news(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_NEWS_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_bd_page_type(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "tn", "bdwns");
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    input, url_buffer_size - (url_tail - url));
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_forum
 * DESCRIPTION
 *  Generate the URL to search Baidu Forum.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_forum(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_FORUM_URL);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "tn", "bdKSW");
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    input, url_buffer_size - (url_tail - url));
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_knowledge
 * DESCRIPTION
 *  Generate the URL to search Baidu Knowledge.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_knowledge(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_KNOWLEDGE_URL);
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_TRUE, "ptid", "17");
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "iksearch", "1");
    url_tail = mmi_sweb_append_url_param(url_tail, MMI_FALSE, "pword", "ikaslist");
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    input, url_buffer_size - (url_tail - url));
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_weather
 * DESCRIPTION
 *  Generate the URL to search Baidu Weather.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_weather(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_WEATHER_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
	url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    (U16*)get_string(STR_ID_SEARCH_WEB_BAIDU_WEATHER), url_buffer_size - (url_tail - url));
    /*url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "area",
                    input, url_buffer_size - (url_tail - url));*/
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_dictionary
 * DESCRIPTION
 *  Generate the URL to search Baidu Dictionary.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_dictionary(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_DICTIONARY_URL);
	url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    (U16*)get_string(STR_ID_SEARCH_WEB_BAIDU_DICTIONARY), url_buffer_size - (url_tail - url));
                    
    return url; /* NOTE: returns the head of buffer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_space
 * DESCRIPTION
 *  Generate the URL to visit Baidu Space.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_space(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_SPACE_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
	url_tail = 	url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    (U16*)get_string(STR_ID_SEARCH_WEB_BAIDU_SPACE), url_buffer_size - (url_tail - url));
    
    return url;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_map
 * DESCRIPTION
 *  Generate the URL to visit Baidu Map.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_map(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_MAP_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
	url_tail = 	url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    (U16*)get_string(STR_ID_SEARCH_WEB_BAIDU_MAP), url_buffer_size - (url_tail - url));
    
    return url;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_web_help
 * DESCRIPTION
 *  Generate the URL to visit Baidu's web help page.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_web_help(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_WEB_HELP_URL);
    /* NOTE: MMI_SEARCH_WEB_BAIDU_WEB_HELP_URL includes one parameter: "kw" */
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
    
    return url;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_url_others
 * DESCRIPTION
 *  Generate the URL to visit the more page of Baidu's services.
 * PARAMETERS
 *  input           [IN]  UCS-2 string of input.
 *  url             [OUT] Output URL
 *  url_buffer_size [IN]  Maximum URL length including the '\0'
 * RETURNS
 *  The begin position of the result URL string
 *****************************************************************************/
static CHAR *mmi_sweb_baidu_generate_url_others(const U16 *input, CHAR *url, U32 url_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url_tail;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url[0] = '\0';

    url_tail = mmi_sweb_strcat(url, MMI_SEARCH_WEB_BAIDU_OTHERS_URL);
    url_tail = mmi_sweb_baidu_append_vit(url_tail, MMI_TRUE);
    url_tail = mmi_sweb_baidu_append_common_param(url_tail, MMI_FALSE);
	url_tail = 	url_tail = mmi_sweb_baidu_append_input(url_tail, MMI_FALSE, "word",
                    (U16*)get_string(STR_ID_SEARCH_WEB_OTHERS), url_buffer_size - (url_tail - url));
    
    return url;
}


/****************************************************************************
 * Local Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_iter_is_valid
 * DESCRIPTION
 *  Test the data is available for the menu iterator.
 * PARAMETERS
 *  iter        [IN] Iterator
 * RETURNS
 *  MMI_TRUE if there is next item
 *****************************************************************************/
static MMI_BOOL mmi_sweb_baidu_menu_iter_is_valid(const mmi_sweb_baidu_menu_iter_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_sweb_baidu_menu_config[iter->index].menu_item_id < MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_iter_get_data
 * DESCRIPTION
 *  Get the configuration entry of the iterator currently points to.
 * PARAMETERS
 *  iter        [IN] Iterator
 * RETURNS
 *  The menu item configuration.
 *  Returns NULL if the iterator has ran out.
 *****************************************************************************/
static const mmi_sweb_baidu_menu_config_struct *mmi_sweb_baidu_menu_iter_get_data(
    const mmi_sweb_baidu_menu_iter_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_sweb_baidu_menu_config_struct *menu_config;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_config = &(mmi_sweb_baidu_menu_config[iter->index]);
    if (menu_config->menu_item_id >= MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM)
    {
        menu_config = NULL;
    }
    
    return menu_config;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_iter_next
 * DESCRIPTION
 *  Move the iterator to point to next entry in the menu configuration.
 * PARAMETERS
 *  iter        [IN/OUT] Iterator
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_menu_iter_next(mmi_sweb_baidu_menu_iter_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sweb_baidu_menu_config[iter->index].menu_item_id < MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM)
    {
        iter->index++;
    }
}


/****************************************************************************
 * Global Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_category_config
 * DESCRIPTION
 *  Get the configuration of the category.
 * PARAMETERS
 *  category    [IN] Category
 * RETURNS
 *  The configuration.
 *****************************************************************************/
const mmi_sweb_baidu_category_struct*
    mmi_sweb_baidu_get_category_config(mmi_search_web_baidu_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(category < MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM);

    if (mmi_sweb_baidu_category_config_num == MMI_SEARCH_WEB_BAIDU_CATEGORY_TOTAL)
    {
        if (mmi_sweb_baidu_category_list[category].category == category)
        {
            return &(mmi_sweb_baidu_category_list[category]);
        }
    }
    
    for (i = 0; mmi_sweb_baidu_category_list[i].category != MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM; i++)
    {
        if (mmi_sweb_baidu_category_list[i].category == category)
        {
            return &(mmi_sweb_baidu_category_list[i]);
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_iter_init
 * DESCRIPTION
 *  Initialize a menu iterator. User can use iter->has_next(iter),
 *  iter->get_data(iter), iter->next(iter) to manipulate the iterator.
 * PARAMETERS
 *  iter        [OUT] Iterator
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_menu_iter_init(mmi_sweb_baidu_menu_iter_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter->index = 0;
    iter->is_valid = mmi_sweb_baidu_menu_iter_is_valid;
    iter->get_data = mmi_sweb_baidu_menu_iter_get_data;
    iter->next     = mmi_sweb_baidu_menu_iter_next;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_id_to_category
 * DESCRIPTION
 *  Map menu item ID to category.
 * PARAMETERS
 *  menu_item_id    [IN] Menu item ID
 * RETURNS
 *  Category; if no mapping, that is, it is not a category menu ID, returns
 *  MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM
 *****************************************************************************/
mmi_search_web_baidu_category_enum mmi_sweb_baidu_menu_id_to_category(
    mmi_search_web_baidu_menu_item_enum menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; mmi_sweb_baidu_menu_category_table[i].menu_item_id !=
                            MMI_SEARCH_WEB_BAIDU_MENU_ITEM_END_OF_ENUM; i++)
    {
        if (mmi_sweb_baidu_menu_category_table[i].menu_item_id == menu_item_id)
        {
            return mmi_sweb_baidu_menu_category_table[i].category;
        }
    }

    return MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM;
}


#endif /* __MMI_SEARCH_WEB_BAIDU__ */

