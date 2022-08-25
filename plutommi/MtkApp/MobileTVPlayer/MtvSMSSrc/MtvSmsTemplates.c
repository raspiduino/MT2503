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
 *  mtvsmstemplate.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmstemplate.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__

#ifdef __MMI_MESSAGES_TEMPLATE__


/* Include: MMI header file */
/**************************************************************
* Header Files Include
**************************************************************/


#include "mtvsmsiprot.h"
#include "mmi_rp_app_sms_def.h"
#include "SSCStringHandle.h"
#include "FontDcl.h"
#include "GeneralSettingSrvGprot.h"
#include "Lang_interface.h"
/**************************************************************
* MARCO
**************************************************************/
#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
#define NUM_TEMPLATES                   10
#define MAX_TEMPLATE_LENGTH             40

#ifndef NVRAM_SMS_TEMPL_RECORD_SIZE
#define NVRAM_SMS_TEMPL_RECORD_SIZE     84
#endif
#ifndef NVRAM_SMS_RECORD_TOTAL
#define NVRAM_SMS_RECORD_TOTAL          31
#endif
#ifdef _MUTILANG_TEMPLATE_
#define TOTAL_TEMPLATE_LANGUAGE         3
#endif
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
#ifndef NVRAM_SMS_UD_TEMPL_RECORD_SIZE
#define NVRAM_SMS_UD_TEMPL_RECORD_SIZE  324
#endif 
#define NUM_UD_TEMPLATES                10
#define MAX_UD_TEMPLATE_LENGTH          160
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 


#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
#define MAX_TEMPL_RECORD_BUFF_SIZE      (NVRAM_SMS_UD_TEMPL_RECORD_SIZE + ENCODING_LENGTH)   
#else /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
#define MAX_TEMPL_RECORD_BUFF_SIZE      (NVRAM_SMS_TEMPL_RECORD_SIZE + ENCODING_LENGTH)
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    MMI_SMS_TEMPLATE_NONE = 0,
    MMI_SMS_TEMPLATE_USER_DEFINED,
    MMI_SMS_TEMPLATE_DEFAULT,
    MMI_SMS_TEMPLATE_TOTAL
}mmi_mtv_sms_template_type_enum;

typedef enum
{
    MSG_TEMPLATE_LANG_ENGLISH,
    MSG_TEMPLATE_LANG_SIMCHINESE,
    MSG_TEMPLATE_LANG_TRACHINESE
} mmi_mtv_sms_template_lang_enum;

typedef enum
{
    MMI_SMS_LIST_TEMPLATE_USER_DEFINED, /* if suppport user defined template, only list user defined template, if not support, return SMS_GET_TEMPLATE_NULL */
    MMI_SMS_LIST_TEMPLATE_DEFAULT,      /* if suppport predefined template, only list predefined template, if not support, return SMS_GET_TEMPLATE_NULL */
    MMI_SMS_LIST_TEMPLATE_ALL           /* list all the template supported*/
} mmi_mtv_sms_tmpl_list_template_type_enum;



typedef struct
{
    MMI_BOOL is_load;
    S8 record_buff[MAX_TEMPL_RECORD_BUFF_SIZE];
    
    mmi_mtv_sms_template_type_enum template_type;
    mmi_mtv_sms_tmpl_list_template_type_enum list_templ_type;

    U16 list_lsk_str_id;
    U16 list_lsk_icon_id;


#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    U16 userdef_num;
    S8 *userdef_list[NUM_UD_TEMPLATES];
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    S8 *predef_list[NUM_TEMPLATES];
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

    S32 curr_index;
    mmi_mtv_sms_get_template_handle_fuct_t get_template_callback;
}mmi_mtv_sms_template_struct;


extern const U16 gIndexIconsImageList[];

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
#ifdef _MUTILANG_TEMPLATE_
extern pBOOL IsTrChineseSet(void);
extern pBOOL IsSmChineseSet(void);
#endif /* _MUTILANG_TEMPLATE_ */ 

#if (defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__))
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
#endif /* (defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__)) */
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

/**************************************************************
* Static Variables Defination
**************************************************************/
#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
static const U16 template_str[] = 
{
    STR_ID_SMS_TEMPLATE_1,
    STR_ID_SMS_TEMPLATE_2,
    STR_ID_SMS_TEMPLATE_3,
    STR_ID_SMS_TEMPLATE_4,
    STR_ID_SMS_TEMPLATE_5,
    STR_ID_SMS_TEMPLATE_6,
    STR_ID_SMS_TEMPLATE_7,
    STR_ID_SMS_TEMPLATE_8,
    STR_ID_SMS_TEMPLATE_9,
    STR_ID_SMS_TEMPLATE_10
};

#if defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__)
static U8 curr_lang[SSC_SIZE];
#endif /* _MUTILANG_TEMPLATE_, __MMI_MESSAGES_SIMCHINESE_TEMPLATE__ */

#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

static mmi_mtv_sms_template_struct template_data;



static void mmi_mtv_sms_entry_template_list_item(void);
static pBOOL mmi_mtv_sms_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_mtv_sms_get_template_index(S32 nIndex);
static U8 mmi_mtv_sms_init_templates(void);
static void mmi_mtv_sms_deInit_templates(void);
static void mmi_mtv_sms_load_templates_in_displaylist(void);
static void mmi_mtv_sms_templ_insert_template(void);

#if defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
static MMI_BOOL mmi_mtv_sms_write_default_template_to_nvram(void);
static MMI_BOOL mmi_mtv_sms_write_template_to_nvram(U16 index);
static U16 mmi_mtv_sms_cal_template_base(void);
static void mmi_mtv_sms_read_template_from_nvram(U16 index);

#if defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__)
static void mmi_mtv_sms_set_template_language(U8 langtype);
static void mmi_mtv_sms_unset_template_language(void);

#endif 
#endif /*__MMI_MESSAGES_PREDEFINED_TEMPLATE__ */

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
static void mmi_mtv_sms_read_ud_template_from_nvram(U16 index);
static MMI_BOOL mmi_mtv_sms_write_ud_template_to_nvram(U16 index);
static MMI_BOOL mmi_mtv_sms_write_ud_default_template_to_nvram(void);

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_register_get_template_callback
 * DESCRIPTION
 *  Entry template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_register_get_template_callback(mmi_mtv_sms_get_template_handle_fuct_t call_back)
{
    template_data.get_template_callback = call_back;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_template_list
 * DESCRIPTION
 *  Entry template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
    template_data.template_type = MMI_SMS_TEMPLATE_NONE;
    DeleteScreenIfPresent(SCR_ID_MTV_SMS_TEMPLATE_LIST);
    DeleteScreenIfPresent(SCR_ID_MTV_SMS_TEMPLATE_LIST_SELECT);
#else /* defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__) */ 
    DeleteScreenIfPresent(SCR_ID_MTV_SMS_TEMPLATE_LIST);
#endif /* defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__) */ 
    mmi_mtv_sms_entry_template_list_item();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_template_list_item
 * DESCRIPTION
 *  Entry template list items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_template_list_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    U16 lsk_str_id = 0;
    S32 maxItem = 0;
    U16 screen_id;
    U8  set_csk = MMI_TRUE;
    lsk_str_id = STR_GLOBAL_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_id = SCR_ID_MTV_SMS_TEMPLATE_LIST;
    if (mmi_mtv_sms_init_templates() == FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_GLOBAL_NOT_SUPPORTED),
            MMI_MTV_SMS_NOTIFY_FAILURE);
        return;
    }

    mmi_mtv_sms_load_templates_in_displaylist();

#if defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined (__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
     template_data.template_type = MMI_SMS_TEMPLATE_TOTAL;
     maxItem = template_data.userdef_num + NUM_TEMPLATES;
#elif defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
    template_data.template_type = MMI_SMS_TEMPLATE_USER_DEFINED;
    maxItem = template_data.userdef_num;
#elif defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__)
    template_data.template_type = MMI_SMS_TEMPLATE_DEFAULT;
    maxItem = NUM_TEMPLATES;
#endif

    if (maxItem == 0)
    {
        set_csk = MMI_FALSE;
    }
    EntryNewScreen(screen_id, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry_template_list_item, NULL);

    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);

    g_mtv_sms_scrn_cntx.current_scrn = screen_id;

    guiBuffer = GetCurrGuiBuffer(screen_id);
    if (guiBuffer != NULL)
    {
        hiliteitem = (template_data.curr_index < maxItem) ? template_data.curr_index : 0;
    }
    RegisterHighlightHandler(mmi_mtv_sms_get_template_index);

    if (set_csk == MMI_TRUE)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    wgui_cat1011_show(
        get_string(STR_ID_MTV_SMS_TEMPLATE_TITLE),
        0,
        get_string(lsk_str_id),
        0,
        get_string(STR_GLOBAL_BACK),
        0,
        maxItem == 0 ? 1 : maxItem,
        mmi_mtv_sms_template_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);
    SetRightSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);

    
    
    if (maxItem == 0)
    {
        SetLeftSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);
        if (set_csk == MMI_TRUE)
        {
            SetCenterSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);
        }
    }
    else
    {
        if (set_csk == MMI_TRUE)
        {
            SetCenterSoftkeyFunction(mmi_mtv_sms_templ_insert_template, KEY_EVENT_UP);
        }
        SetLeftSoftkeyFunction(mmi_mtv_sms_templ_insert_template,KEY_EVENT_UP );
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_template_list_get_item
 * DESCRIPTION
 *  Get template list item
 * PARAMETERS
 *  item_index                [IN]            Item index
 *  str_buff                  [IN/OUT]        String buffer
 *  img_buff_p                [IN/OUT]        Image buffer
 *  str_img_mask              [IN/OUT]        String image mask
 * RETURNS
 * TRUE
 *****************************************************************************/
static pBOOL mmi_mtv_sms_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;
    S32 defaultItemIndex = item_index;
    mmi_mtv_sms_template_type_enum multiTmplate = MMI_SMS_TEMPLATE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) && defined (__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
    if (template_data.get_template_callback)
    {
        switch (template_data.template_type)
        {
            case MMI_SMS_TEMPLATE_USER_DEFINED:
                multiTmplate = MMI_SMS_TEMPLATE_USER_DEFINED;
                numItems = template_data.userdef_num;
                break;
            case MMI_SMS_TEMPLATE_DEFAULT:
                multiTmplate = MMI_SMS_TEMPLATE_DEFAULT;
                numItems = NUM_TEMPLATES;
                break;
            case MMI_SMS_TEMPLATE_TOTAL:
            default:
                multiTmplate = MMI_SMS_TEMPLATE_TOTAL;
                numItems = NUM_TEMPLATES + template_data.userdef_num;
        }
    }
#elif defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__)
    multiTmplate = MMI_SMS_TEMPLATE_DEFAULT;
    numItems = NUM_TEMPLATES;
#elif defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__)
    multiTmplate = MMI_SMS_TEMPLATE_USER_DEFINED;
    numItems = template_data.userdef_num == 0 ? 1 : template_data.userdef_num;
#endif 

    if ((item_index < 0) || (item_index >= numItems))
    {
        return FALSE;
    }

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    if (multiTmplate != MMI_SMS_TEMPLATE_DEFAULT && item_index < template_data.userdef_num)
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*) template_data.userdef_list[item_index], MAX_SUBMENU_CHARACTERS);
    }
    else if (template_data.userdef_num == 0 && item_index == 0 && multiTmplate == MMI_SMS_TEMPLATE_USER_DEFINED)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

    if (multiTmplate == MMI_SMS_TEMPLATE_TOTAL)
    {
        defaultItemIndex = item_index - template_data.userdef_num;
    }
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    if (multiTmplate != MMI_SMS_TEMPLATE_USER_DEFINED && defaultItemIndex >= 0)
    {
        if (mmi_ucs2strlen(template_data.predef_list[defaultItemIndex]) == 0)
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) template_data.predef_list[defaultItemIndex]);
        }
    }
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_template_index
 * DESCRIPTION
 *  Get current highlight index in template list
 * PARAMETERS
 *  nIndex      [IN]        
 *  a(?)        [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_template_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    template_data.curr_index = nIndex;
}


#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_write_default_template_to_nvram
 * DESCRIPTION
 *  Write default template to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_write_default_template_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_TEMPLATES; i++)
    {
        U16 templateindex = i + mmi_mtv_sms_cal_template_base();
        S8 *tmpl_str;

        tmpl_str = GetString(template_str[i]);

        if (tmpl_str != NULL)
        {
            memcpy(template_data.record_buff, tmpl_str, (mmi_ucs2strlen(tmpl_str) + 1) * ENCODING_LENGTH);
        }
        else
        {
            memset(template_data.record_buff, 0, MAX_TEMPL_RECORD_BUFF_SIZE);
        }

        if (mmi_mtv_sms_write_template_to_nvram(templateindex) == MMI_FALSE)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_write_template_to_nvram
 * DESCRIPTION
 *  Write template to NVRAM
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Index
 * RETURNS
 *  TRUE: write success, FALSE: write fail
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_write_template_to_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < NVRAM_SMS_RECORD_TOTAL)
    {
        /*  1. The first record index of the LID is 1;
         *  2. And the first record is used to as a mark to 
         *     indicate the intialization status;
         *  So, the record index of the first template is 2;
         */
        if (WriteRecord(NVRAM_EF_SMS_LID, (index + 2), template_data.record_buff,
                NVRAM_SMS_TEMPL_RECORD_SIZE, &error) != NVRAM_SMS_TEMPL_RECORD_SIZE)
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_init_templates
 * DESCRIPTION
 *  Init templates
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: init success, FALSE: init fail
 *****************************************************************************/
U8 mmi_mtv_sms_init_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int initDone = 0;
    S16 error;

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    static S8 templateSignature[MAX_TEMPLATE_LENGTH + 1] = "AAA";
    S8 buffer[NVRAM_SMS_TEMPL_RECORD_SIZE];

#ifdef _MUTILANG_TEMPLATE_
    int i;
#endif 
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    static S8 udTemplateSignature[MAX_UD_TEMPLATE_LENGTH + 1] = "BBB";
    S8 udBuffer[NVRAM_SMS_UD_TEMPL_RECORD_SIZE];
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (initDone)
    {
        return TRUE;
    }

    initDone = MMI_FALSE;
	template_data.is_load = MMI_FALSE;

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    if (ReadRecord(NVRAM_EF_SMS_LID, 1, buffer, NVRAM_SMS_TEMPL_RECORD_SIZE, &error) < 0)
    {
        buffer[0] = '\0';
    }

    if (buffer[0] == 'A')
    {
        return TRUE;
    }

#if defined (_MUTILANG_TEMPLATE_) || defined (__MMI_MESSAGES_SIMCHINESE_TEMPLATE__)
    memset(curr_lang, 0, SSC_SIZE);
    memcpy(curr_lang, (PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SIZE);

#ifdef _MUTILANG_TEMPLATE_
    for (i = 0; i < TOTAL_TEMPLATE_LANGUAGE; i++)
    {
        mmi_mtv_sms_set_template_language((U8) i);
        if (mmi_mtv_sms_write_default_template_to_nvram() == MMI_FALSE)
        {
            return FALSE;
        }
    }
#else /* _MUTILANG_TEMPLATE_ */ 
    mmi_mtv_sms_set_template_language(MSG_TEMPLATE_LANG_SIMCHINESE);
    if (mmi_sms_write_default_template_to_nvram() == MMI_FALSE)
    {
        return FALSE;
    }
#endif /* _MUTILANG_TEMPLATE_ */ 

    mmi_mtv_sms_unset_template_language();
#else /* defined (_MUTILANG_TEMPLATE_) || defined (__MMI_MESSAGES_SIMCHINESE_TEMPLATE__) */ 
    if (mmi_sms_write_default_template_to_nvram() == MMI_FALSE)
    {
        return FALSE;
    }
#endif /* defined (_MUTILANG_TEMPLATE_) || defined (__MMI_MESSAGES_SIMCHINESE_TEMPLATE__) */ 

    if (WriteRecord(NVRAM_EF_SMS_LID, 1, templateSignature,
            NVRAM_SMS_TEMPL_RECORD_SIZE, &error) < NVRAM_SMS_TEMPL_RECORD_SIZE)
    {
        return FALSE;
    }
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    if (ReadRecord(NVRAM_EF_SMS_UD_TMEP_LID, 1, udBuffer, NVRAM_SMS_UD_TEMPL_RECORD_SIZE, &error) < 0)
    {
        udBuffer[0] = '\0';
    }

    if (udBuffer[0] == 'B')
    {
        return TRUE;
    }

    if (mmi_mtv_sms_write_ud_default_template_to_nvram() == MMI_FALSE)
    {
        return FALSE;
    }

    if (WriteRecord(NVRAM_EF_SMS_UD_TMEP_LID, 1, udTemplateSignature, NVRAM_SMS_UD_TEMPL_RECORD_SIZE, &error) <
        NVRAM_SMS_UD_TEMPL_RECORD_SIZE)
    {
        return FALSE;
    }
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 

    return TRUE;
}

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
#if defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_template_language
 * DESCRIPTION
 *  Set template language
 * PARAMETERS
 *  langtype        [IN]        
 *  a(?)            [IN]        Language type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_set_template_language(U8 langtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S8 tempLang[SSC_SIZE];
    S16 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempLang, 0, SSC_SIZE);
    switch (langtype)
    {
        case MSG_TEMPLATE_LANG_ENGLISH:
            memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
            break;
        case MSG_TEMPLATE_LANG_SIMCHINESE:
            memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
            break;
        case MSG_TEMPLATE_LANG_TRACHINESE:
            memcpy(tempLang, SSC_TCHINESE, SSC_SIZE);
            break;
    }
	
           
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__ 
				srv_setting_set_language_ext((U8*)tempLang);
#else
	temp = mmi_lang_support(tempLang);
    if (temp >= 0)
    {
				srv_setting_set_language_ext(temp);
	}
#endif

  
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_unset_template_language
 * DESCRIPTION
 *  Unset template language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_unset_template_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

         
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__ 
				srv_setting_set_language_ext((U8*)curr_lang);
#else
		temp = mmi_lang_support((PS8) curr_lang);
    if (temp >= 0)
    {
				srv_setting_set_language_ext(temp);
	}
#endif

    
    
}
#endif /* defined(_MUTILANG_TEMPLATE_) || defined(__MMI_MESSAGES_SIMCHINESE_TEMPLATE__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_cal_template_base
 * DESCRIPTION
 *  Calculate template base
 * PARAMETERS
 *  void
 * RETURNS
 *  template base
 *****************************************************************************/
static U16 mmi_mtv_sms_cal_template_base(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef _MUTILANG_TEMPLATE_
    U8 lang_offset = 0;
    U16 temp_base = 0;
#endif /* _MUTILANG_TEMPLATE_ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef _MUTILANG_TEMPLATE_
    if (IsTrChineseSet())
    {
        lang_offset = (U8)MSG_TEMPLATE_LANG_TRACHINESE;
    }
    else if (IsSmChineseSet())
    {
        lang_offset = (U8)MSG_TEMPLATE_LANG_SIMCHINESE;
    }
    else
    {
        lang_offset = (U8)MSG_TEMPLATE_LANG_ENGLISH;
    }

    temp_base = lang_offset * NUM_TEMPLATES;

    return temp_base;
    
#else /* _MUTILANG_TEMPLATE_ */ 
        return 0;
#endif /* _MUTILANG_TEMPLATE_ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_read_template_from_nvram
 * DESCRIPTION
 *  Read template from NVRAM
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_read_template_from_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < NVRAM_SMS_RECORD_TOTAL)
    {
        /*  1. The first record index of the LID is 1;
         *  2. And the first record is used to as a mark to 
         *     indicate the intialization status;
         *  So, the record index of the first template is 2;
         */
        if (ReadRecord(NVRAM_EF_SMS_LID, (index + 2), template_data.record_buff,
                NVRAM_SMS_TEMPL_RECORD_SIZE, &error) < 0)
        {
            template_data.record_buff[0] = '\0';
            template_data.record_buff[1] = '\0';
        }
    }
    else
    {
        template_data.record_buff[0] = '\0';
        template_data.record_buff[1] = '\0';
    }
}


#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_deInit_templates
 * DESCRIPTION
 *  Deinit templates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_deInit_templates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    for (i = 0; i < NUM_TEMPLATES; i++)
    {
        if (template_data.predef_list[i])
        {
            OslMfree(template_data.predef_list[i]);
            template_data.predef_list[i] = NULL;
        }
    }
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    for (i = 0; i < NUM_UD_TEMPLATES; i++)
    {
        if (template_data.userdef_list[i])
        {
            OslMfree(template_data.userdef_list[i]);
            template_data.userdef_list[i] = NULL;
        }
    }
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
   template_data.is_load = MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_load_templates_in_displaylist
 * DESCRIPTION
 *  Load templates to display list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_load_templates_in_displaylist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (template_data.is_load == MMI_TRUE)
    {
        return;
    }    
    mmi_mtv_sms_deInit_templates();

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    for (i = 0; i < NUM_TEMPLATES; i++)
    {
        U16 templateindex = i + mmi_mtv_sms_cal_template_base();

        mmi_mtv_sms_read_template_from_nvram(templateindex);

        template_data.predef_list[i] = OslMalloc((mmi_ucs2strlen(template_data.record_buff) + 1) * ENCODING_LENGTH);

        mmi_ucs2cpy(template_data.predef_list[i], template_data.record_buff);
    }
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    for (i = 0; i < NUM_UD_TEMPLATES; i++)
    {
        mmi_mtv_sms_read_ud_template_from_nvram(i);

        if (mmi_ucs2strlen(template_data.record_buff))
        {
            template_data.userdef_list[i] = OslMalloc((mmi_ucs2strlen(template_data.record_buff) + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy(template_data.userdef_list[i], template_data.record_buff);
        }
        else
        {
            break;
        }
    }

    template_data.userdef_num = i;
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */
    template_data.is_load = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_templ_insert_template
 * DESCRIPTION
 *  Insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_templ_insert_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ = NULL;
    S32 defaultItemIndex = template_data.curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    if (template_data.curr_index < template_data.userdef_num)
    {
        templ = template_data.userdef_list[template_data.curr_index];
    }

    defaultItemIndex = template_data.curr_index - template_data.userdef_num;
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */ 

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    if (defaultItemIndex >= 0)
    {
        templ = template_data.predef_list[defaultItemIndex];
    }
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */ 

    if(template_data.get_template_callback)
    {   
        template_data.get_template_callback((S8*)templ);
    }

    mmi_mtv_sms_deInit_templates();
}



#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_read_ud_template_from_nvram
 * DESCRIPTION
 *  Read user defined template from NVRAM
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_read_ud_template_from_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index < NVRAM_SMS_UD_RECORD_TOTAL)
    {
        /*  1. The first record index of the LID is 1;
         *  2. And the first record is used to as a mark to 
         *     indicate the intialization status;
         *  So, the record index of the first template is 2;
         */
        if (ReadRecord(NVRAM_EF_SMS_UD_TMEP_LID, (index + 2), template_data.record_buff,
                NVRAM_SMS_UD_TEMPL_RECORD_SIZE, &error) < 0)
        {
            template_data.record_buff[0] = '\0';
            template_data.record_buff[1] = '\0';
        }
    }
    else
    {
        template_data.record_buff[0] = '\0';
        template_data.record_buff[1] = '\0';
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_write_ud_default_template_to_nvram
 * DESCRIPTION
 *  Write user defined default template to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_write_ud_default_template_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(template_data.record_buff, 0, MAX_TEMPL_RECORD_BUFF_SIZE);

    for (i = 0; i < NUM_UD_TEMPLATES; i++)
    {
        if (mmi_mtv_sms_write_ud_template_to_nvram(i) == MMI_FALSE)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_write_ud_template_to_nvram
 * DESCRIPTION
 *  Write user defined template to NVRAM
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  TRUE: write success, FALSE: write fail
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_write_ud_template_to_nvram(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < NVRAM_SMS_UD_RECORD_TOTAL)
    {
        /*  1. The first record index of the LID is 1;
         *  2. And the first record is used to as a mark to 
         *     indicate the intialization status;
         *  So, the record index of the first template is 2;
         */
        if (WriteRecord(NVRAM_EF_SMS_UD_TMEP_LID, (U16)(index + 2), template_data.record_buff,
                NVRAM_SMS_UD_TEMPL_RECORD_SIZE, &error) != NVRAM_SMS_UD_TEMPL_RECORD_SIZE)
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}

#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */



#endif /* __MMI_MESSAGES_TEMPLATE__ */
#endif /* __MMI_ATV_SMS_SUPPORT__ */ 


