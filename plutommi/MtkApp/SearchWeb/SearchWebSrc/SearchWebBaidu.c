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
 *  SearchWebBaidu.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Main procedures of Baidu Search.
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
#include "Menucuigprot.h"           /* For options menu */
#include "common_nvram_editor_data_item.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "SearchWebGProt.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "MMI_common_app_trc.h"
#include "SearchWebProt.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "stdlib.h"
#include "stack_config.h"
#include "custom_mmi_default_value.h"
#include "Unicodexdcl.h"
#include "browser_api.h"
#include "mmi_rp_app_search_web_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "wgui_categories_text_viewer.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "wgui_categories_inputs.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "ImeGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * Context structure of Baidu search bar.
 */
typedef struct
{
    /*
     * Input history.
     * If history can be shared with all implementations in the future,
     * we can move it to common context.
     */
    nvram_ef_search_web_history_struct history;

    /* The default search category of current setting */
    mmi_search_web_baidu_category_enum default_category;
    
    /* Cache of UID */
    CHAR uid[MMI_SEARCH_WEB_BAIDU_MAX_UID_LEN + 1];

    /* Cache of the value of from parameter */
    CHAR from_value[10];

    /* Parameters to the entry function of Search bar */
    U16 input_buffer[MMI_SEARCH_WEB_BAIDU_MAX_INPUT_LEN + 1];

    /*
     * If set to MMI_TRUE, the entry function of Search bar will reset input_buffer
     * to the first entry in the history (depend on reserve_input_buffer).
     * Whole text will be selected.
     */
    MMI_BOOL reset_input;

    /*
     * Useful only if reset_input = MMI_TRUE. If reserve_input_buffer == MMI_TRUE,
     * it will keep the content in input_buffer. Otherwise input_buffer
     * will be reset to the first entry of the history.
     */
    MMI_BOOL reserve_input_buffer;
    
    /* Current highlight index of history list */
    U16 highlight_index_of_history_list;

    /* ID of menu CUI of Options */
    MMI_ID options_cui_id;
} mmi_sweb_baidu_context_struct;


/****************************************************************************
 * External Variables
 ****************************************************************************/

/*
 * The buffer space for temporary use.
 * DO NOT use this buffer cross applications. That is, this buffer will be
 * automatically invalidated if new application's UI launched or interrupted.
 */
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
MMI_BOOL pre_search_null_cntx = FALSE; 


/****************************************************************************
 * Global Variables
 ****************************************************************************/

/* Hot key setting */
static mmi_search_web_hot_key_enum g_mmi_sweb_baidu_hot_key = MMI_SEARCH_WEB_BAIDU_DEFAULT_HOT_KEY;

/* Context of Baidu search */
static mmi_sweb_baidu_context_struct *g_mmi_sweb_baidu_cntx = NULL;


/****************************************************************************
 * Local Functions
 ****************************************************************************/

static void mmi_sweb_baidu_options_do_selected_item(U32 menu_item_id);
static void mmi_sweb_baidu_options_close(void);
static void mmi_sweb_baidu_close_search_bar(void);
static MMI_BOOL mmi_sweb_baidu_put_history_into_input_buffer(U32 index);


#define UTILITIES /* ------------------------------------------------ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_generate_uid
 * DESCRIPTION
 *  Generate UID by random values. If an UID is already in NVRAM, it read UID
 *  from NVRAM directly. Otherwise it will generate a new one and write it to
 *  NVRAM for the user of next time.
 * PARAMETERS
 *  uid          [OUT] UID buffer
 *  buffer_size  [IN]  Buffer size, including the '\0'
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_generate_uid(CHAR* uid, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    static const CHAR MTK_BEGIN[] = { 'm', 't', 'k', '_' };

    U32 digit_range;
    U32 upper_case_range;
    U32 random_range;
    nvram_ef_search_web_baidu_uid_struct *uid_record;
    kal_uint8 *nvram_uid;
    S16 error;
    U32 seed;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(buffer_size > sizeof(MTK_BEGIN));

    uid_record = (nvram_ef_search_web_baidu_uid_struct*)OslMalloc(sizeof(nvram_ef_search_web_baidu_uid_struct));

    ReadRecord(NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID, 1, uid_record, sizeof(nvram_ef_search_web_baidu_uid_struct), &error);
    
    if (error < 0 || memcmp(uid_record->uid, MTK_BEGIN, sizeof(MTK_BEGIN)) != 0)
    {
        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_GENERATE_UID, 0, error, buffer_size);
    
        digit_range      = ('9' - '0' + 1);
        upper_case_range = digit_range + ('Z' - 'A' + 1);
        random_range     = upper_case_range + ('z' - 'a' + 1);

        nvram_uid = uid_record->uid;
        memcpy(nvram_uid, MTK_BEGIN, sizeof(MTK_BEGIN));
    
        kal_get_time(&seed);
        srand(seed);

        for (i = sizeof(MTK_BEGIN); i < NVRAM_EF_SEARCH_WEB_BAIDU_UID_MAX_LEN; i++)
        {
            U32 r_val;

            r_val = rand() % random_range;

            if (r_val < digit_range)
            {
                nvram_uid[i] = (CHAR)('0' + r_val);
            }
            else if (r_val < upper_case_range)
            {
                nvram_uid[i] = (CHAR)('A' + r_val - digit_range);
            }
            else
            {
                nvram_uid[i] = (CHAR)('a' + r_val - upper_case_range);
            }
        }

        nvram_uid[NVRAM_EF_SEARCH_WEB_BAIDU_UID_MAX_LEN] = '\0';

        WriteRecord(NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID, 1, uid_record, sizeof(nvram_ef_search_web_baidu_uid_struct), &error);
    }
    else
    {
        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_GENERATE_UID, 1, error, buffer_size);
    }

    memcpy(uid, uid_record->uid, buffer_size - 1);
    uid[buffer_size - 1] = '\0';
    
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_SEARCH_WEB_TRACE_GROUP, "[SWeb] Baidu uid: %s", uid);

    OslMfree(uid_record);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_static_buffer
 * DESCRIPTION
 *  Get a large, static buffer. User should make sure there will never 2
 *  users are using the buffer at the same time. This buffer will become
 *  invalid if another foreground application is launched or interrupted.
 * PARAMETERS
 *  buffer_size  [OUT] The size of the static buffer. Pass NULL if
 *                     user don't need to know the size when only a small
 *                     space is required.
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_sweb_baidu_get_static_buffer(U32 *buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buffer;
    U8 *buffer_end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (U8*)subMenuData;
    buffer_end = buffer + sizeof(subMenuData);
    buffer = (U8*)(((U32)buffer + 3) & ~0x3); /* Align to 4-byte */
    
    if (buffer_size != NULL)
    {
        *buffer_size = (U32)(buffer_end - buffer);
    }
    
    return (void*)buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_history
 * DESCRIPTION
 *  Get the history data used by Baidu Search.
 * PARAMETERS
 *  void
 * RETURNS
 *  Pointer of history data: nvram_ef_search_web_history_struct*
 *****************************************************************************/
#define mmi_sweb_baidu_get_history() (&(g_mmi_sweb_baidu_cntx->history))


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_history_entry
 * DESCRIPTION
 *  Get the history entry of Baidu Search.
 * PARAMETERS
 *  index       [IN] The index of the entry required
 * RETURNS
 *  Pointer of history data: nvram_ef_search_web_history_entry_struct*.
 *  If the entry is empty or not initialized, this function returns NULL.
 *****************************************************************************/
const nvram_ef_search_web_history_entry_struct* mmi_sweb_baidu_get_history_entry(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_init_cntx();

    return mmi_sweb_get_history_entry(mmi_sweb_baidu_get_history(), index);
}


#define USER_INTERFACE /* --------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_init
 * DESCRIPTION
 *  Read the hot key setting from NVRAM. Called during system initialization.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hot_key;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SEARCH_WEB_BAIDU_HOT_KEY_SETTING, &hot_key, sizeof(hot_key), &error);

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_INIT_HOT_KEY, hot_key, error, MMI_SEARCH_WEB_BAIDU_DEFAULT_HOT_KEY);

    if (error < 0 || hot_key > 0x7fff)
    {
        hot_key = MMI_SEARCH_WEB_BAIDU_DEFAULT_HOT_KEY;
    }

    g_mmi_sweb_baidu_hot_key = (mmi_search_web_hot_key_enum)hot_key;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_hot_key_is_enabled
 * DESCRIPTION
 *  Test if Baidu search enabled and is accepting the hot key.
 * PARAMETERS
 *  hot_key     [IN] Hot key
 * RETURNS
 *  MMI_TRUE if enabled
 *****************************************************************************/
MMI_BOOL mmi_sweb_baidu_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_LAUNCHER_KEY__)
		/* We provide hint on key_launcher projects */
    if(hot_key == MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT)
    {
        if(g_mmi_sweb_baidu_hot_key == MMI_SEARCH_WEB_HOT_KEY_NONE ||g_mmi_sweb_baidu_hot_key == MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR)
        {
        	return MMI_FALSE;
        }
	else
	{
    	return MMI_TRUE;
    }
    }
    else
    {
    	return (g_mmi_sweb_baidu_hot_key == hot_key);
    }    		
#elif defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__)

    /* We don't provide hot key on Baidu widget projects */
    return MMI_FALSE;  		
#else

    return (g_mmi_sweb_baidu_hot_key == hot_key);
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_hot_key_set
 * DESCRIPTION
 *  Update the hot key setting of Baidu search.
 * PARAMETERS
 *  hot_key     [IN] Hot key to set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_hot_key_set(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 t_hot_keys;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t_hot_keys = (U16)hot_key;
    WriteValue(NVRAM_SEARCH_WEB_BAIDU_HOT_KEY_SETTING, &t_hot_keys, sizeof(t_hot_keys), &error);

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_HOT_KEY_SET, hot_key, error);

    if (error != -1)
    {
        g_mmi_sweb_baidu_hot_key = hot_key;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_hot_key_is_off
 * DESCRIPTION
 *  Check whether all hot keys are disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if no hot key is enabled.
 *****************************************************************************/
#define mmi_sweb_baidu_hot_key_is_off() \
    ((g_mmi_sweb_baidu_hot_key == MMI_SEARCH_WEB_HOT_KEY_NONE) ? MMI_TRUE : MMI_FALSE)


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_init_cntx
 * DESCRIPTION
 *  Initialize the context before accessing Baidu data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 default_category;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_sweb_baidu_cntx == NULL)
    {    
        g_mmi_sweb_baidu_cntx = (mmi_sweb_baidu_context_struct*)OslMalloc(sizeof(mmi_sweb_baidu_context_struct));

        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_INIT_CNTX, (U32)g_mmi_sweb_baidu_cntx);

        /* Read default category setting from MMI cache */
        ReadValue(NVRAM_SEARCH_WEB_BAIDU_DEFAULT_CATEGORY, &default_category, sizeof(default_category), &error);
        
        if (error < 0 || default_category >= MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM)
        {
            default_category = (U16)MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET;
        }

        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_READ_DEFAULT_CATEGORY, default_category, error);
        
        g_mmi_sweb_baidu_cntx->default_category = (mmi_search_web_baidu_category_enum)default_category;

        /* Generate unique UID */
        mmi_sweb_baidu_generate_uid(g_mmi_sweb_baidu_cntx->uid, sizeof(g_mmi_sweb_baidu_cntx->uid));

        g_mmi_sweb_baidu_cntx->from_value[0] = '\0';
        g_mmi_sweb_baidu_cntx->reset_input = MMI_TRUE;
        g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_FALSE;
        g_mmi_sweb_baidu_cntx->input_buffer[0] = L'\0';
        g_mmi_sweb_baidu_cntx->highlight_index_of_history_list = 0;
        g_mmi_sweb_baidu_cntx->options_cui_id = 0;

        mmi_sweb_read_common_history(mmi_sweb_baidu_get_history());
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_release_cntx
 * DESCRIPTION
 *  Deinitialize the context after the search bar is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_release_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_sweb_baidu_cntx != NULL)
    {
        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_RELEASE_CNTX, (U32)g_mmi_sweb_baidu_cntx);

        OslMfree(g_mmi_sweb_baidu_cntx);
        g_mmi_sweb_baidu_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_default_category
 * DESCRIPTION
 *  Get the default search category of Baidu Search.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_search_web_baidu_category_enum
 *****************************************************************************/
mmi_search_web_baidu_category_enum mmi_sweb_baidu_get_default_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_init_cntx();

    return (g_mmi_sweb_baidu_cntx->default_category);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_set_default_category
 * DESCRIPTION
 *  Set the default search category of Baidu Search.
 * PARAMETERS
 *  category    [IN] Category
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_set_default_category(mmi_search_web_baidu_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 default_category;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_init_cntx();
    
    g_mmi_sweb_baidu_cntx->default_category = category;
    
    default_category = (U16)g_mmi_sweb_baidu_cntx->default_category;
    WriteValue(NVRAM_SEARCH_WEB_BAIDU_DEFAULT_CATEGORY,
        &default_category,
        sizeof(default_category),
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_request_browsing
 * DESCRIPTION
 *  Open browser to connect to Baidu's webpage of the given category.
 *  Use the input as a parameter. The input will be trimmed first and be put
 *  into the history after requested.
 * PARAMETERS
 *  category    [IN] Category
 *  input       [IN] Parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_baidu_request_browsing(
    mmi_search_web_baidu_category_enum category,
    const U16 *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *param = NULL;
    
    const mmi_sweb_baidu_category_struct *category_config;
    CHAR PAR_NAME[10];
    U16 *trimmed_input;
    CHAR *url;
    U16 *url_in_ucs2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_init_cntx();
    
    PAR_NAME[0] = 'f';
    category_config = mmi_sweb_baidu_get_category_config(category);

    PAR_NAME[1] = 'r';
    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_REQUEST_BROWSING, category, (U32)category_config);

    PAR_NAME[2] = 'o';
    if (category_config == NULL || PAR_NAME[1] != 'r')
    {
        return;
    }

    PAR_NAME[3] = 'm';
    
    /*
     * Why "+ 2" here? Because the generate_url() may be written by customers,
     * we should do more carefully, allocate one char extra to store the null
     * char if misunderstanding.
     */
    url = (CHAR*)OslMalloc(MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN + 2);
    url_in_ucs2 = (U16*)OslMalloc((MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN + 2) * sizeof(U16));

    PAR_NAME[4] = '=';
    
    /* Initialize the output of URL generating function first */
    url[0] = '\0';
    PAR_NAME[5] = '\0';
    
    if (category_config->browsing_type == MMI_SEARCH_WEB_BAIDU_QUERY)
    {
        /* Trim the input */
        trimmed_input = (U16*)OslMalloc((MMI_SEARCH_WEB_BAIDU_MAX_INPUT_LEN + 1) * sizeof(U16));
        mmi_sweb_trim(input, trimmed_input);
    
        if (trimmed_input[0] != L'\0') /* Length(trimmed_input) > 0 */
        {
            mmi_sweb_put_into_history(mmi_sweb_baidu_get_history(), trimmed_input);
            mmi_sweb_write_common_history(mmi_sweb_baidu_get_history());
			pre_search_null_cntx = FALSE;
			g_mmi_sweb_baidu_cntx->reset_input = MMI_TRUE;
			g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_FALSE;
        }
		else
		{
			pre_search_null_cntx = TRUE;
			g_mmi_sweb_baidu_cntx->reset_input = MMI_FALSE;
        g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_FALSE;
		}
        g_mmi_sweb_baidu_cntx->input_buffer[0] = L'\0';

        category_config->generate_url(trimmed_input, url, MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN + 1);

        OslMfree(trimmed_input);
    }
    else
    {
        category_config->generate_url(input, url, MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN + 1);
    }
    
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_SEARCH_WEB_TRACE_GROUP, "[SWeb] URL: %s", url);

    param = strstr(url, PAR_NAME);
    if (param != NULL && (*(param - 1) == '&' || *(param - 1) == '?'))
    {
        param[7] = '0';
        param[5] = (CHAR)(param[7] + (1 << 3));
        param[6] = (CHAR)(param[5] - 3);
    }
    
    mmi_asc_n_to_wcs(url_in_ucs2, url, MMI_SEARCH_WEB_BAIDU_MAX_URL_LEN);

    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)url_in_ucs2);

    OslMfree(url);
    OslMfree(url_in_ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_request_browsing_default_category
 * DESCRIPTION
 *  Open browser to connect to Baidu's webpage of the default category.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_request_browsing_default_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_request_browsing(
        mmi_sweb_baidu_get_default_category(),
        g_mmi_sweb_baidu_cntx->input_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_open_web_help
 * DESCRIPTION
 *  Launch browser to open Baidu's web help.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_open_web_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_request_browsing(
        MMI_SEARCH_WEB_BAIDU_CATEGORY_WEB_HELP,
        g_mmi_sweb_baidu_cntx->input_buffer);
        
    /* By FRS, close the help screen if user connects to the web help page */
    mmi_frm_scrn_close(GRP_ID_SEARCH_WEB_BAIDU, SCR_ID_SEARCH_WEB_BAIDU_HELP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_entry_help_text
 * DESCRIPTION
 *  Show the help text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_entry_help_text(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *desc_buffer;
    U32 buffer_size;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    desc_buffer = (U16*)mmi_sweb_baidu_get_static_buffer(&buffer_size);

    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            NULL,
            (FuncPtr)mmi_sweb_baidu_entry_help_text,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(es_data->group_id, es_data->scrn_id);

    kal_wsprintf(desc_buffer,
        "%w\n\n%w\n\n%w\n\n%w\n%w %s",
        get_string(STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_USAGE),
        get_string(STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_CHARGE),
        get_string(STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_FEEDBACK),
        get_string(STR_ID_SEARCH_WEB_BAIDU_SEARCH_APP_NAME),
        get_string(STR_ID_SEARCH_WEB_VERSION),
        MMI_SEARCH_WEB_BAIDU_VERSION);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        GetRootTitleIcon(MENU_ID_SEARCH_WEB_BAIDU_ENTRY),
        STR_ID_SEARCH_WEB_BAIDU_WEB_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)desc_buffer,
        buffer_size,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_sweb_baidu_open_web_help, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sweb_baidu_open_web_help, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_menu_item_is_selected
 * DESCRIPTION
 *  To check whether a menu item should be selected.
 * PARAMETERS
 *  menu_item_id    [IN] Menu item ID
 * RETURNS
 *  If menu_item_id is category menu ID, returns MMI_TRUE if it is the default
 *  category. If menu_item_id is hot key menu ID, returns MMI_TRUE if it is
 *  enabled. Otherwise returns MMI_FALSE as well as normal menu items.
 *****************************************************************************/
static MMI_BOOL mmi_sweb_baidu_menu_item_is_selected(
    mmi_search_web_baidu_menu_item_enum menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selected = MMI_FALSE;
    
    switch (menu_item_id)
    {
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_INTERNET:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_IMAGE:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_NEWS:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_FORUM:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_KNOWLEDGE:
            if (mmi_sweb_baidu_get_default_category() ==
                mmi_sweb_baidu_menu_id_to_category(menu_item_id))
            {
                selected = MMI_TRUE;
            }
            break;

        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DOWN_KEY:
            selected = mmi_sweb_baidu_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_LONG_PRESS_STAR:
            selected = mmi_sweb_baidu_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR);
            break;

        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY_DISABLED:
            selected = mmi_sweb_baidu_hot_key_is_off();
            break;
    
        default:
            break;
    }

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_options_get_submenu
 * DESCRIPTION
 *  Get sub menu for the required item.
 * PARAMETERS
 *  required_menu   [IN] mmi_search_web_baidu_menu_item_enum
 *  menu_arr        [OUT] Menu array to be filled in
 *  n_menu_arr_max  [IN] Maximum number of entries in menu_arr
 * RETURNS
 *  If menu_item_id is category menu ID, returns MMI_TRUE if it is the default
 *  category. If menu_item_id is hot key menu ID, returns MMI_TRUE if it is
 *  enabled. Otherwise returns MMI_FALSE as well as normal menu items.
 *****************************************************************************/
static S32 mmi_sweb_baidu_options_get_submenu(
                mmi_search_web_baidu_menu_item_enum required_menu,
                MMI_MENU_ID *menu_arr,
                S32 n_menu_arr_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    mmi_sweb_baidu_menu_iter_struct iter;
    const mmi_sweb_baidu_menu_config_struct *menu_config;
    S32 required_level;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    n_items = 0;
    required_level = 0;

    if (required_menu == MMI_SEARCH_WEB_BAIDU_MENU_ROOT)
    {
        required_level = 1;
    }
    
    for (mmi_sweb_baidu_menu_iter_init(&iter); iter.is_valid(&iter); iter.next(&iter))
    {
        menu_config = iter.get_data(&iter);
    
        if (menu_config->level == required_level)
        {
            if (menu_config->menu_item_id == MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA)
            {
                for (i = 0; i < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM; i++)
                {
                    if (mmi_sweb_baidu_get_history_entry(i) == NULL)
                    {
                        break;
                    }
                    if (menu_arr != NULL && n_items < n_menu_arr_max)
                    {
                        menu_arr[n_items] = MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN + i;
                    }
                    n_items++;
                }
            }
            else
            {
                if (menu_arr != NULL && n_items < n_menu_arr_max)
                {
                    menu_arr[n_items] = menu_config->menu_item_id;
                }
                n_items++;
            }
        }
        else if (menu_config->level < required_level)
        {
            /* Menu end */
            break;
        }
        else /* menu_config->level > required_level */
        {
            /* Sub items, ignore */
        }

        if (required_menu == menu_config->menu_item_id)
        {
            required_level = menu_config->level + 1;
        }
    }

    return n_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_options_set_items
 * DESCRIPTION
 *  Set properties of menu_arr[] to options_menu.
 * PARAMETERS
 *  cui_options_id      [IN] CUI ID of option menu
 *  menu_arr            [IN] Menu ID array of current sub menu
 *  n_items             [IN] Number if items in menu_arr[]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_options_set_items(
                MMI_ID options_cui_id,
                const MMI_MENU_ID menu_arr[],
                S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_MENU_ID menu_item;
    mmi_sweb_baidu_menu_iter_struct config_iter;
    mmi_search_web_baidu_menu_item_enum parent_menu;
    const mmi_sweb_baidu_menu_config_struct *menu_config;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist(options_cui_id, n_items, (MMI_MENU_ID*)menu_arr);

    /*
     * Init the iter only once here, we assume items in menu_arr[] is
     * from top to bottom.
     */
    mmi_sweb_baidu_menu_iter_init(&config_iter);
    parent_menu = MMI_SEARCH_WEB_BAIDU_MENU_ROOT;
    
    for (i = 0; i < n_items; i++)
    {
        menu_item = menu_arr[i];
        
        if (menu_item >= MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN &&
            menu_item < MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_END)
        {
            /* History data */
            const nvram_ef_search_web_history_entry_struct* history_entry;
            
            history_entry = mmi_sweb_baidu_get_history_entry(
                menu_item - MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN);
            cui_menu_set_item_string(options_cui_id, menu_item, (UI_string_type)history_entry->string);
        }
        else
        {
            menu_config = NULL;
        
            /* Find corresponding item */
            while (config_iter.is_valid(&config_iter))
            {
                menu_config = config_iter.get_data(&config_iter);
                if (menu_config->level == 1)
                {
                    parent_menu = menu_config->menu_item_id;
                }
                if (menu_config->menu_item_id == menu_item)
                {
                    break;
                }
                config_iter.next(&config_iter);
            }

            MMI_ASSERT(menu_config != NULL);
            cui_menu_set_item_string(options_cui_id, menu_item, get_string(menu_config->string_id));

            if ((parent_menu == MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DEFAULT_CATEGORY ||
                 parent_menu == MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY) &&
                (menu_config->level == 2))
            {
                cui_menu_set_currlist_flags(options_cui_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if (mmi_sweb_baidu_menu_item_is_selected(menu_item))
                {
                    cui_menu_set_radio_list_item(options_cui_id, menu_item);
                }
            }

            /* Get next item to judge whether current item is a non-leaf item */
            if (config_iter.is_valid(&config_iter))
            {
                const mmi_sweb_baidu_menu_config_struct *next_menu_config;
                
                config_iter.next(&config_iter);
                if (config_iter.is_valid(&config_iter))
                {
                    next_menu_config = config_iter.get_data(&config_iter);
                    if (next_menu_config->level > menu_config->level)
                    {
                        cui_menu_set_non_leaf_item(options_cui_id, menu_item, MMI_TRUE);
                    }
                }
                else /* the last item */
                {
                    /* Leaf */
                }
            }

            if (menu_item == MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY)
            {
                if (mmi_sweb_baidu_get_history_entry(0) == NULL) /* No history entry */
                {
                    cui_menu_set_item_disabled(
                        options_cui_id,
                        MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY,
                        MMI_TRUE);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_options_menu_proc
 * DESCRIPTION
 *  Event proc for options menu
 * PARAMETERS
 *  evt     [IN] cui_menu_event_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_sweb_baidu_options_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    MMI_MENU_ID *menu_arr;
    S32 n_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    menu_evt = (cui_menu_event_struct*)evt;
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* Calculate n_items to know the size required */
            n_items = mmi_sweb_baidu_options_get_submenu(menu_evt->parent_menu_id, NULL, 0);
            menu_arr = (MMI_MENU_ID*)OslMalloc(sizeof(MMI_MENU_ID) * n_items);
            /* Generate the array of menu items */
            mmi_sweb_baidu_options_get_submenu(menu_evt->parent_menu_id, menu_arr, n_items);
            /* Set properties for the menu items */
            mmi_sweb_baidu_options_set_items(menu_evt->sender_id, menu_arr, n_items);
            OslMfree(menu_arr);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_sweb_baidu_options_do_selected_item(menu_evt->highlighted_menu_id);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_sweb_baidu_options_close();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_options_do_selected_item
 * DESCRIPTION
 *  Command handler of the Options menu.
 * PARAMETERS
 *  menu_item_id     [IN] Menu ID
 * RETURNS
 *  Accepted and completed the handling of menu item.
 *****************************************************************************/
static void mmi_sweb_baidu_options_do_selected_item(U32 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL close_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    close_menu = MMI_TRUE;
    
    switch (menu_item_id)
    {
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_REQUEST_SEARCH:
            mmi_sweb_baidu_request_browsing_default_category();
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CLEAR_HISTORY:
            mmi_sweb_clear_history(mmi_sweb_baidu_get_history());
            mmi_sweb_write_common_history(mmi_sweb_baidu_get_history());
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_INTERNET:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_IMAGE:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_NEWS:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_FORUM:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_CATEGORY_KNOWLEDGE:
            mmi_sweb_baidu_set_default_category(mmi_sweb_baidu_menu_id_to_category(menu_item_id));
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_DOWN_KEY:
            mmi_sweb_baidu_hot_key_set(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_LONG_PRESS_STAR:
            mmi_sweb_baidu_hot_key_set(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HOT_KEY_DISABLED:
            mmi_sweb_baidu_hot_key_set(MMI_SEARCH_WEB_HOT_KEY_NONE);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_WEATHER:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_DICTIONARY:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_SPACE:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_BAIDU_MAP:
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_OTHERS:
            mmi_sweb_baidu_request_browsing(
                mmi_sweb_baidu_menu_id_to_category(menu_item_id),
                g_mmi_sweb_baidu_cntx->input_buffer);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HELP:
            mmi_frm_scrn_first_enter(
                GRP_ID_SEARCH_WEB_BAIDU,
                SCR_ID_SEARCH_WEB_BAIDU_HELP,
                (FuncPtr)mmi_sweb_baidu_entry_help_text,
                g_mmi_sweb_baidu_cntx);
            break;
            
        case MMI_SEARCH_WEB_BAIDU_MENU_ITEM_EXIT:
            mmi_sweb_baidu_close_search_bar();
            /*
             * The group was closed by mmi_sweb_baidu_close_search_bar() and the,
             * context has been freed, we shall not call mmi_sweb_baidu_options_close().
             */
            close_menu = MMI_FALSE;
            break;

        default:
            if (menu_item_id >= MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN &&
                menu_item_id <  MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_END)
            {
                mmi_sweb_baidu_put_history_into_input_buffer(
                    menu_item_id - MMI_SEARCH_WEB_BAIDU_MENU_ITEM_HISTORY_DATA_BEGIN);
				pre_search_null_cntx = FALSE;
                g_mmi_sweb_baidu_cntx->reset_input = MMI_TRUE;
                g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_TRUE;
            }
            else
            {
                close_menu = MMI_FALSE;
            }
            break;
    }

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_MENU_SELECTED, menu_item_id, close_menu, 0);

    if (close_menu)
    {
        mmi_sweb_baidu_options_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_display_options
 * DESCRIPTION
 *  Show the cascading menu of Options.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_options_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_sweb_baidu_cntx;
    MMI_ASSERT(cntx != NULL);
    
    cntx->options_cui_id = cui_menu_create(
        GRP_ID_SEARCH_WEB_BAIDU,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_OPTION,
        MMI_SEARCH_WEB_BAIDU_MENU_ROOT,
        MMI_TRUE,
        cntx);

    if (cntx->options_cui_id == 0)
    {
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_INSUFFICIENT_MEMORY),
            MMI_EVENT_FAILURE,
            GRP_ID_SEARCH_WEB_BAIDU,
            NULL);
        return;
    }

    cui_menu_enable_cascading_option_menu(cntx->options_cui_id);
    cui_menu_run(cntx->options_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_options_close
 * DESCRIPTION
 *  Close options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_options_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_sweb_baidu_cntx;
    if (cntx != NULL && cntx->options_cui_id != 0)
    {
        cui_menu_close(cntx->options_cui_id);
        cntx->options_cui_id = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_close_search_bar
 * DESCRIPTION
 *  Close Baidu search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_close_search_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_sweb_baidu_cntx != NULL)
    {
        g_mmi_sweb_baidu_cntx->reset_input = MMI_TRUE;
        g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_FALSE;
        
        mmi_frm_group_close(GRP_ID_SEARCH_WEB_BAIDU);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_put_history_into_input_buffer
 * DESCRIPTION
 *  Copy the history entry into the input buffer.
 * PARAMETERS
 *  index       [IN] The index of history entry to be copied
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sweb_baidu_put_history_into_input_buffer(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const nvram_ef_search_web_history_entry_struct *history_entry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    history_entry = mmi_sweb_baidu_get_history_entry(index);
    if (history_entry != NULL)
    {
        mmi_wcsncpy(g_mmi_sweb_baidu_cntx->input_buffer, history_entry->string, MMI_SEARCH_WEB_BAIDU_MAX_INPUT_LEN);
    }
    else
    {
        g_mmi_sweb_baidu_cntx->input_buffer[0] = L'\0';
    }

    return (history_entry != NULL) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_history_list_highlight_hdlr
 * DESCRIPTION
 *  Store the highlight index of history list.
 * PARAMETERS
 *  index   [IN] Index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_history_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0 && index >= MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM)
    {
        return;
    }

    g_mmi_sweb_baidu_cntx->highlight_index_of_history_list = (U16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_history_list_selected_hdlr
 * DESCRIPTION
 *  Put the selected history into the input box and go back to the search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_history_list_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_put_history_into_input_buffer(g_mmi_sweb_baidu_cntx->highlight_index_of_history_list);
	pre_search_null_cntx = FALSE;
    g_mmi_sweb_baidu_cntx->reset_input = MMI_TRUE;
    g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_TRUE;

    mmi_frm_scrn_close(GRP_ID_SEARCH_WEB_BAIDU, SCR_ID_SEARCH_WEB_BAIDU_HISTORY_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_entry_history_list
 * DESCRIPTION
 *  Display history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_entry_history_list(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const nvram_ef_search_web_history_entry_struct *history_entry;
    const U16 *history_list[MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM];
    S32 num_of_entries;
    wgui_cat_inputbox_coordinate_struct inputbox_coord;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_cat2001_get_inputbox_coordinate(&inputbox_coord);

    if (!mmi_frm_scrn_enter(
            GRP_ID_SEARCH_WEB_BAIDU,
            SCR_ID_SEARCH_WEB_BAIDU_HISTORY_LIST,
            NULL,
            NULL,
            MMI_FRM_SMALL_SCRN))
    {
        return;
    }

    num_of_entries = 0;

    for (i = 0; i < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM; i++)
    {
        history_entry = mmi_sweb_baidu_get_history_entry(i);
        if (history_entry != NULL)
        {
            history_list[i] = history_entry->string;
            num_of_entries++;
        }
        else
        {
            break;
        }
    }

    g_mmi_sweb_baidu_cntx->highlight_index_of_history_list = 0;
    RegisterHighlightHandler(mmi_sweb_baidu_history_list_highlight_hdlr);
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1001_show(
        get_string(STR_GLOBAL_SELECT),
        NULL,
        get_string(STR_GLOBAL_CANCEL),
        NULL,
        num_of_entries,
        (U8**)history_list,
        NULL,
        &inputbox_coord,
        (S32)g_mmi_sweb_baidu_cntx->highlight_index_of_history_list,
        NULL);

    SetLeftSoftkeyFunction(mmi_sweb_baidu_history_list_selected_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sweb_baidu_history_list_selected_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_display_history_list
 * DESCRIPTION
 *  Display history list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_display_history_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_SEARCH_WEB_BAIDU,
        SCR_ID_SEARCH_WEB_BAIDU_HISTORY_LIST,
        (FuncPtr)mmi_sweb_baidu_entry_history_list,
        &g_mmi_sweb_baidu_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_grp_proc
 * DESCRIPTION
 *  Group proc of Baidu Search.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_sweb_baidu_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            return mmi_sweb_baidu_options_menu_proc(evt);
        
        case EVT_ID_GROUP_DEINIT:
            MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_DELETE_SEARCH_BAR, (U32)g_mmi_sweb_baidu_cntx);
        
            /*
             * Free context if search bar is closed.
             * If search bar is launched again, g_mmi_sweb_baidu_cntx will be reallocated and initialized.
             * We should make sure all information in g_mmi_sweb_baidu_cntx can be restored, either from
             * NVRAM or predefined.
             */
            mmi_sweb_baidu_release_cntx();
            
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_search_bar_set_key_handlers
 * DESCRIPTION
 *  Set the key handlers on the search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_search_bar_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const nvram_ef_search_web_history_entry_struct *history_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_get_active_id() == SCR_ID_SEARCH_WEB_BAIDU_SEARCH_BAR)
    {
        history_entry = mmi_sweb_get_history_entry(mmi_sweb_baidu_get_history(), 0);

        SetKeyHandler(mmi_sweb_baidu_request_browsing_default_category, KEY_SEND, KEY_EVENT_DOWN);
        if (history_entry != NULL)
        {
            SetKeyHandler(mmi_sweb_baidu_display_history_list, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_sweb_baidu_display_history_list, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_entry_search_bar
 * DESCRIPTION
 *  The entry function of Search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sweb_baidu_entry_search_bar(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    const mmi_sweb_baidu_category_struct *category_config;
    U32 category_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
            es_data->group_id,
            es_data->scrn_id,
            NULL,
            (FuncPtr)mmi_sweb_baidu_entry_search_bar,
            MMI_FRM_SMALL_SCRN))
    {
        return;
    }
        
    category_flag = WGUI_CAT2001_NO_FLAGS;

	if(pre_search_null_cntx == TRUE)
	{
		g_mmi_sweb_baidu_cntx->reset_input = MMI_FALSE;
	}

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_BAIDU_ENTRY_SEARCH_BAR,
        g_mmi_sweb_baidu_cntx->reset_input, g_mmi_sweb_baidu_cntx->reserve_input_buffer);

    if (g_mmi_sweb_baidu_cntx->reset_input)
    {
        if (!g_mmi_sweb_baidu_cntx->reserve_input_buffer)
        {
            mmi_sweb_baidu_put_history_into_input_buffer(0);
        }

        category_flag = WGUI_CAT2001_HIGHLIGHT_TEXT;
    }

    g_mmi_sweb_baidu_cntx->reserve_input_buffer = MMI_FALSE;
    g_mmi_sweb_baidu_cntx->reset_input = MMI_FALSE;

    category_config = mmi_sweb_baidu_get_category_config(mmi_sweb_baidu_get_default_category());
    MMI_ASSERT(category_config != NULL);

    set_softkey_icon(get_image(IMG_GLOBAL_SEARCH_CSK), MMI_CENTER_SOFTKEY);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_cat2001_setup_search_button(
        get_image(IMG_ID_SEARCH_WEB_SEARCH_BUTTON),
        get_image(IMG_ID_SEARCH_WEB_SEARCH_BUTTON_PRESSED),
        mmi_sweb_baidu_request_browsing_default_category);
#endif

    gui_buffer = mmi_frm_scrn_get_gui_buf(es_data->group_id, es_data->scrn_id);

    wgui_cat2001_show(
        get_image(category_config->logo_icon_id),
        get_string(STR_GLOBAL_OPTIONS),
        get_image(IMG_GLOBAL_OPTIONS),
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        IMM_INPUT_TYPE_SENTENCE,
        (U8*)g_mmi_sweb_baidu_cntx->input_buffer,
        sizeof(g_mmi_sweb_baidu_cntx->input_buffer),
        gui_buffer,
        NULL,
        category_flag);

    SetLeftSoftkeyFunction(mmi_sweb_baidu_options_display, KEY_EVENT_UP);
    wgui_cat2001_set_rsk_function(mmi_sweb_baidu_close_search_bar, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_sweb_baidu_request_browsing_default_category, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();

    mmi_sweb_baidu_search_bar_set_key_handlers();

    /*
     * IME may register some key handlers. This callback is to restore the original key
     * handlers after IME closed.
     */
    wgui_cat2001_set_special_key_function(mmi_sweb_baidu_search_bar_set_key_handlers);
}


/****************************************************************************
 * Global Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_uid
 * DESCRIPTION
 *  Get UID.
 * PARAMETERS
 *  void
 * RETURNS
 *  The UID string terminated by '\0'.
 *****************************************************************************/
const CHAR *mmi_sweb_baidu_get_uid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_mmi_sweb_baidu_cntx->uid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_from_param_value
 * DESCRIPTION
 *  Generate from value by customer ID.
 * PARAMETERS
 *  void
 * RETURNS
 *  The union ID string terminated by '\0'.
 *****************************************************************************/
const CHAR *mmi_sweb_baidu_get_from_param_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 hash_value;
    const CHAR *cu_p;
    U32 result[4];
    CHAR *from_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_sweb_baidu_cntx->from_value[0] == '\0') /* Not initialized */
    {
        /*
         * Generate UID by Bai-hash algorithm, do not modify unless you
         * know want you do.
         */
        hash_value = 0;
        for (cu_p = MMI_SEARCH_WEB_BAIDU_CUSTOMER_ID; *cu_p; cu_p++)
        {
            hash_value += (*cu_p << 2) | (*cu_p >> 1);
        }
        hash_value = hash_value & 0xffff; /* Only reserve 16 bits */

        /* Shuffle */
        result[3] = (hash_value & 0xff);
        result[2] = (hash_value ^ (U32)result[3]);
        result[1] = (hash_value ^ (U32)result[3]) + (1 << 3);
        result[0] = (hash_value ^ (U32)result[1]);
        result[1] ^= result[0] ^= result[1] ^= result[0];
        result[1] ^= hash_value;
        result[1] -= 3;
        /* Trim */
        result[0] &= 0xf;
        result[1] &= 0xf;
        result[2] &= 0xf;
        /* Check sum */
        result[3] = (result[0] + result[1] + result[2] - 1) & 0xf;

        from_value = g_mmi_sweb_baidu_cntx->from_value;
        from_value[0] = mmi_sweb_to_hex_char(result[0]);
        from_value[1] = mmi_sweb_to_hex_char(result[1]);
        from_value[2] = mmi_sweb_to_hex_char(result[2]);
        memcpy(from_value + 3, MMI_SEARCH_WEB_BAIDU_CUSTOMER_ID, 4);
        from_value[7] = (CHAR)(mmi_sweb_to_hex_char(result[3]) ^ ('a' ^ 'A'));
        from_value[8] = '\0';
    }

    return g_mmi_sweb_baidu_cntx->from_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_baidu_entry_highlight_hdlr
 * DESCRIPTION
 *  The highlight handler of the entry item in Service menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_search_web_baidu_entry_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_search_web_baidu_open_search_bar, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_search_web_baidu_open_search_bar, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_baidu_open_search_bar
 * DESCRIPTION
 *  Open Baidu search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_search_web_baidu_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* We don't allow multiple instance */
    if (mmi_frm_group_is_present(GRP_ID_SEARCH_WEB_BAIDU))
    {
        mmi_popup_display(
            get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            NULL);
        return GRP_ID_INVALID;
    }

    mmi_sweb_baidu_init_cntx();

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_SEARCH_WEB_BAIDU,
        mmi_sweb_baidu_grp_proc,
        &g_mmi_sweb_baidu_cntx);
    mmi_frm_group_enter(GRP_ID_SEARCH_WEB_BAIDU, MMI_FRM_NODE_NONE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_SEARCH_WEB_BAIDU,
        SCR_ID_SEARCH_WEB_BAIDU_SEARCH_BAR,
        (FuncPtr)mmi_sweb_baidu_entry_search_bar,
        &g_mmi_sweb_baidu_cntx);

    return GRP_ID_SEARCH_WEB_BAIDU;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_baidu_open_search_bar
 * DESCRIPTION
 *  Open Baidu search bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_search_web_baidu_open_search_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mmi_search_web_baidu_launch() != GRP_ID_INVALID)
    {
        /*
         * [MAUI_02174762]
         * Symbol picker will be launched on key-up. ClearKeyEvents() can prevent
         * it from being launched on star key-up.
         */
        ClearKeyEvents();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_baidu_launch_from_mainmenu
 * DESCRIPTION
 *  Launch Baidu Search from main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_search_web_baidu_launch_from_mainmenu(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_search_web_baidu_launch();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_baidu_get_idle_hint_config
 * DESCRIPTION
 *  get baidu hint image and string of idle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:if success, return MMI_TRUE,else return MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_sweb_baidu_get_idle_hint_config(const U8 **icon_data, const WCHAR **string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sweb_baidu_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT))
    {
        *icon_data = NULL;
        *string = NULL;
        
        return MMI_FALSE;
    }

    *icon_data = get_image(IMG_ID_SEARCH_WEB_BAIDU_IDLE_LOGO);
    *string = get_string(STR_ID_SEARCH_WEB_BAIDU_IDLE_HINT_TEXT);

    return MMI_TRUE;
}
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

