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
 * DictionaryMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Dictionary UI implementation
 *
 * Author:
 * Rajbir Singh
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define __NEWSIMULATOR
#include "MMI_include.h"

#if defined(__MMI_DICTIONARY__) && defined(__MTK_TARGET__)

#include "mmi_rp_app_dictionary_def.h"
#include "fseditorcuigprot.h"
#include "inlinecuigprot.h"
#include "menucuigprot.h"

#include "CommonScreens.h"
#include "ProfilesSrvGProt.h"
#include "DictionaryMain.h"
#include "Custom_mmi_default_value.h"
#include "Mdi_datatype.h"
#include "Mdi_audio.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#endif

#if defined(__MMI_DICT_GV__)
#include "DictionaryCoreGV.h"
#elif defined(__MMI_DICT_MOTECH__ )
#include "DictionaryCoreMOTECH.h"
#elif defined(__MMI_DICT_TRILOGY__ )
#include "DictionaryCoreTRILOGY.h"
#endif 


#define MMI_DICT_WORD_MEMORY_SIZE  ((MAX_SUBMENU_CHARACTERS >MMI_DICT_CORE_WORD_MAX) ? MAX_SUBMENU_CHARACTERS : MMI_DICT_CORE_WORD_MAX)

#undef __NEWSIMULATOR

/*
 * Local Variable
 */
static MMI_BOOL g_dictionary_last_item = MMI_FALSE;
static U16 g_mmi_dictionary_prev_input_mode;
static S32 g_dictionary_prev_index;
static S32 g_dictionary_highlighted_item;
static S32 g_dictionary_first_display_item;

static U8 g_dictionary_input_buffer[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];  					/* Input buffer on main dictionary screen */
static U8 *g_dictionary_wildcard_exact_buffer_p; 	/* input buffer for wildcard,exact and chinese string search */
static U8 *g_dictionary_input_p;
static U8 *g_dictionary_last_word_p;
static U8 *g_dictionary_first_displayed_buffer_p;
static U8 *g_dictionary_search_result_p;
static MMI_BOOL  g_dictionary_background_flag;
static mmi_dictionary_search_type g_dictionary_search_type;    /* Search enum : can be Browse, Exact, Wildcard search */
mmi_dictionary_cntx g_dictionary_cntx;                  /* context stucture to hold various global flags */

#ifdef __MMI_DICTIONARY_TTS__
mmi_dictionary_tts_setting_inline g_dictionary_inline_cntx;
#endif

static mmi_imm_input_mode_enum *g_dictionary_input_mode;   /* Input mode for dictionary screen */
static mmi_imm_input_mode_enum g_dictionary_input_mode_Chinese_set[] = 
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,  
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
#ifndef __MMI_DICT_MOTECH__
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
#endif
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
#if !defined(__MMI_TOUCH_SCREEN__)
    #ifndef __MMI_DICT_MOTECH__
    IMM_INPUT_MODE_TR_BOPOMO,
    IMM_INPUT_MODE_TR_STROKE,
    IMM_INPUT_MODE_HK_STROKE,    
    #endif
    IMM_INPUT_MODE_SM_PINYIN,
    IMM_INPUT_MODE_SM_STROKE,
#endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
    IMM_INPUT_MODE_NONE
};

/*
 * Global Variable
 */
extern InlineItem wgui_inline_items[];

/* Adaptation layer structures */
mmi_dict_id_str_struct g_dict_wildcard_ids[MMI_DICT_ID_FETCH_MAX + 1],
    g_dict_chinese_ids[MMI_DICT_ID_FETCH_MAX + 1];
MMI_DICTIONARY_LANGUAGE g_dict_current_language, g_dictionary_language_main_screen;

#ifdef __MMI_DICTIONARY_TTS__
typedef enum
{
    ITEM_ID_SPEAKING_CAPTION    = CUI_INLINE_ITEM_ID_BASE + 0,
    ITEM_ID_SPEAKING_ITEM       = CUI_INLINE_ITEM_ID_BASE + 1,
    ITEM_ID_SPEAK_SPEED_CAPTION = CUI_INLINE_ITEM_ID_BASE + 2,
    ITEM_ID_SPEAK_SPEED_ITEM    = CUI_INLINE_ITEM_ID_BASE + 3,
    ITEM_ID_VOLUME_CAPTION      = CUI_INLINE_ITEM_ID_BASE + 4,
    ITEM_ID_VOLUME_ITEM         = CUI_INLINE_ITEM_ID_BASE + 5,
    DICT_ITEMS_END,
    DICT_ITEMS_COUNT = DICT_ITEMS_END - ITEM_ID_SPEAKING_CAPTION
}mmi_dict_item;


static const cui_inline_item_caption_struct mmi_dict_tts_speaking_caption = {STR_DICTIOANRY_TTS_SPEAKING};
static const cui_inline_item_caption_struct mmi_dict_tts_speak_speed_caption = {STR_DICTIOANRY_TTS_SPEAK_SPEED};
static const cui_inline_item_caption_struct mmi_dict_tts_volume_caption = {STR_GLOBAL_VOLUME};
static const U16 onoff_str[]= {STR_GLOBAL_ON, STR_GLOBAL_OFF};
static const U16 speak_speed_str[] = {STR_GLOBAL_SLOW, STR_GLOBAL_NORMAL, STR_GLOBAL_FAST};
static const U16 speak_volume_str[] = { STR_GLOBAL_1, 
                                        STR_GLOBAL_2,
                                        STR_GLOBAL_3,
                                        STR_GLOBAL_4,
                                        STR_GLOBAL_5,
                                        STR_GLOBAL_6};

static const cui_inline_item_select_struct dict_setting_onoff_item_struct= 
{
    2, 0, (U16 *)&onoff_str[0]
};

static const cui_inline_item_select_struct dict_setting_speak_speed_item_struct= 
{
    3, 0, (U16 *)&speak_speed_str[0]
};

static const cui_inline_item_select_struct dict_setting_speak_volume_item_struct= 
{
    6, 0, (U16 *)&speak_volume_str[0]
};

static cui_inline_item_softkey_struct dict_inline_softkey = 
{
    {
        {STR_GLOBAL_OK, 0},
        {STR_GLOBAL_BACK, 0},
        {0, IMG_GLOBAL_COMMON_CSK}
    }
};


static const cui_inline_set_item_struct dict_inline_item[] = 
{
    {ITEM_ID_SPEAKING_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1,  (void*)&mmi_dict_tts_speaking_caption},
    {ITEM_ID_SPEAKING_ITEM,     CUI_INLINE_ITEM_TYPE_SELECT, 0,   (void*)&dict_setting_onoff_item_struct},
    {ITEM_ID_SPEAK_SPEED_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2,  (void*)&mmi_dict_tts_speak_speed_caption},
    {ITEM_ID_SPEAK_SPEED_ITEM,      CUI_INLINE_ITEM_TYPE_SELECT, 0,   (void*)&dict_setting_speak_speed_item_struct},
    {ITEM_ID_VOLUME_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3,  (void*)&mmi_dict_tts_volume_caption},
    {ITEM_ID_VOLUME_ITEM,      CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&dict_setting_speak_volume_item_struct},
};

static const cui_inline_struct dcit_inline_screen = 
{
    DICT_ITEMS_COUNT,
    STR_DICTIONARY_TTS_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    &dict_inline_softkey, 
    dict_inline_item 
};
#endif


/*
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    /* Assign input mode for the dictionary */
    g_dictionary_input_mode = g_dictionary_input_mode_Chinese_set;

    /*register ASM*/
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_DICTIONARY,
        STR_DICTIONARY_TITLE,
        IMG_DICTIONARY_EXTRA_MENU_SCREEN,
        mmi_dictionary_app_mem_stop_callback);
}

/*
 * Local Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_app_mem_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free(g_dictionary_cntx.app_mem_pool);
    g_dictionary_cntx.app_mem_pool = NULL;
    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_DICTIONARY, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_main_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Dictionary menu in Extra menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_main_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
    SetLeftSoftkeyFunction(mmi_dictionary_entry_welcome_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dictionary_entry_welcome_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_welcome_screen
 * DESCRIPTION
 *  Welcome screen, when user enter first time in this screen,a customer logo is shown.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_welcome_screen(void)
{
#ifdef __MMI_DICTIONARY_WELCOME_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DICT_WELCOME, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_DICT_WELCOME, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_frm_scrn_enter(
	    GRP_ID_DICT_WELCOME, 
	    SCR_DICTIONARY_WELCOME_SCREEN, 
	    NULL, 
	    mmi_dictionary_entry_welcome_screen, 
	    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_WELCOME, SCR_CUI_TONE_SELECTOR_LIST);

    ShowCategory129Screen(
        (U8*) get_string(STR_DICTIONARY_TITLE),
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_DICTIONARY_LOGO,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_dictionary_pre_entry_main_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else /* __MMI_DICTIONARY_WELCOME_SCREEN__ */ 
    mmi_dictionary_pre_entry_main_screen();
#endif /* __MMI_DICTIONARY_WELCOME_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_pre_entry_main_screen
 * DESCRIPTION
 *  initialize dictionary database
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_pre_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL dictResult;
#ifdef __MMI_DICTIONARY_TTS__    
    S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void));
    
    /*ASM alloc,adm create*/
    if(g_dictionary_cntx.app_mem_pool == NULL)
    {
        g_dictionary_cntx.app_mem_pool = 
            applib_mem_ap_alloc(APPLIB_MEM_AP_ID_DICTIONARY, DICTIONARY_APP_TOTAL_SIZE);
        if(g_dictionary_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_DICTIONARY,
                IMG_DICTIONARY_EXTRA_MENU_SCREEN,
                DICTIONARY_APP_TOTAL_SIZE,
                mmi_dictionary_pre_entry_main_screen);
            return;
        }
        mmi_dictionary_create_adm_resource();
    }
    
    /*engine init*/
    dictResult = mmi_dict_init();
    g_dictionary_background_flag = MMI_FALSE;
    if (dictResult == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_DICTIONARY_TTS__    
    ReadValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemonoff == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemonoff = DICTIONARY_TTS_STATE_ON;
        WriteValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    }
    
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemspeakspeed == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemspeakspeed = DICTIONARY_TTS_SPEAK_NORMAL;
        WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    }

    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME,&g_dictionary_inline_cntx.HighligtItemspeakvolume, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemspeakvolume == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemspeakvolume = DICTIONARY_TTS_SPEAK_VOLUME_4;
        WriteValue(
            NVRAM_DICTIANRY_TTS_SPEAK_VOLUME,
            &g_dictionary_inline_cntx.HighligtItemspeakvolume,
            DS_BYTE,
            &error);
    }
    mdi_audio_suspend_background_play();    /*this line is used to suspend audio player*/
    g_dictionary_background_flag = MMI_TRUE;
#endif /* __MMI_DICTIONARY_TTS__ */ 
    memset(g_dictionary_input_buffer, 0, ENCODING_LENGTH);
    mmi_dictionary_entry_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_create_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dictionary_create_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_dictionary_cntx.app_mem_id 
        = kal_adm_create((void*)g_dictionary_cntx.app_mem_pool, DICTIONARY_APP_TOTAL_SIZE, NULL, MMI_FALSE);
	ASSERT(g_dictionary_cntx.app_mem_id != NULL);

	g_dictionary_wildcard_exact_buffer_p 
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_wildcard_exact_buffer_p != NULL);
	g_dictionary_input_p 
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_WORD_MEMORY_SIZE + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_input_p != NULL);
	g_dictionary_last_word_p
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_WORD_MEMORY_SIZE + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_last_word_p != NULL);
	g_dictionary_first_displayed_buffer_p
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_WORD_MEMORY_SIZE + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_first_displayed_buffer_p != NULL);
    g_dictionary_search_result_p = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, DICTIONARY_RESULT_LENGTH);
	ASSERT(g_dictionary_search_result_p != NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_group_proc
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dictionary_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_dictionary_exit_engine();
            break;
        }
        
        /****************************menu CUI****************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == DICTIONARY_OPTION_MENU)
            {
                cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_OK));
                cui_menu_set_currlist_right_softkey(menu_evt->sender_id, (UI_string_type)GetString(STR_GLOBAL_BACK));
                cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            }
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            if (menu_evt->highlighted_menu_id == DICTIONARY_OPTION_SHOW_MEANING_MENU)
            {
                g_dictionary_search_type = DICTIONARY_BROWSE;
            #ifdef __MMI_DICTIONARY_SMALL_SCREEN__
                g_dict_current_language = DICTIONARY_ENGLISH;
            #else 
                g_dict_current_language = g_dictionary_language_main_screen;
            #endif 
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case DICTIONARY_OPTION_SHOW_MEANING_MENU:
                {
                    mmi_dictionary_entry_result_screen();
                    break;
                }
            #ifdef __MMI_DICTIONARY_WILDCARD_SEARCH__ 
                case DICTIONARY_OPTION_WILDCARD_SEARCH_MENU:
                {
                    g_dictionary_search_type = DICTIONARY_WILDCARD_SEARCH;
                    mmi_dictionary_entry_wildcard_exact_editor_screen();
                    break;
                }
            #endif
                case DICTIONARY_OPTION_EXACT_SEARCH_MENU:
                {
                    g_dictionary_search_type = DICTIONARY_EXACT_SEARCH;
                    mmi_dictionary_entry_wildcard_exact_editor_screen();
                    break;
                }
            #ifdef __MMI_DICTIONARY_TTS__
                case DICTIONARY_OPTION_TTS_SETTING_MENU:
                {
                    mmi_dictionary_entry_setting_screen();
                    break;
                }
            #endif
                default:
                    break;
            }
            break;
        }    

        /****************************edit CUI****************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_get_text(editor_evt->sender_id, (WCHAR *)g_dictionary_wildcard_exact_buffer_p, (DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH);
            mmi_dictionary_entry_search();
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_INPUT_METHOD_CHANGE:
        {
            if (mmi_dictionary_flush_exact_wild_editor_buffer())
            {
                g_dictionary_wildcard_exact_buffer_p[0] = 0;
                g_dictionary_wildcard_exact_buffer_p[1] = 0;
                cui_fseditor_set_text(editor_evt->sender_id, (WCHAR *)g_dictionary_wildcard_exact_buffer_p, (DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH, DICTIONARY_INPUT_LENGTH);
            }
        }
        /****************************inline CUI****************************/
    #ifdef __MMI_DICTIONARY_TTS__
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
            if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
                g_dictionary_inline_cntx.highlight_item_id = inline_evt->item_id;
            }
            else if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                switch(g_dictionary_inline_cntx.highlight_item_id)
                {
                    case ITEM_ID_SPEAKING_ITEM:
                    {
                        g_dictionary_inline_cntx.onoffbuffer = inline_evt->param;
                        break;
                    }
                    case ITEM_ID_SPEAK_SPEED_ITEM:
                    {
                        g_dictionary_inline_cntx.speedbuffer = inline_evt->param;
                        break;
                    }
                    case ITEM_ID_VOLUME_ITEM:
                    {
                        g_dictionary_inline_cntx.volumebuffer = inline_evt->param;
                        break;
                    }
                }
            }
           break;
        }
        
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_dictionary_save_speak_setting();
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    #endif /*__MMI_DICTIONARY_TTS__*/
    }

    if(cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, GRP_ID_DICT_MAIN);
    }
 
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_main_screen
 * DESCRIPTION
 *  Entry function for main dictionary screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 cnt;
    MMI_DICTIONARY_LANGUAGE currentLanguage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DICT_MAIN, mmi_dictionary_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_DICT_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (!mmi_frm_scrn_enter(
	    GRP_ID_DICT_MAIN, 
	    SCR_DICTIONARY_MAIN, 
	    mmi_dictionary_exit_main_screen, 
	    mmi_dictionary_entry_main_screen, 
	    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    g_dictionary_search_type = DICTIONARY_BROWSE;
    g_dictionary_prev_index = -1;

    if (g_dictionary_background_flag)
    {
        mdi_audio_suspend_background_play();
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_MAIN);
    RegisterCat200SearchFunction(mmi_dictionary_find_entry);
    RegisterHighlightHandler(mmi_dictionary_word_hdlr);

    if (guiBuffer == NULL)
    {
        memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
        g_dictionary_cntx.current_selected_index = 0;

        /* Default language is English for first time entry */
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        g_dict_current_language = mmi_dictionary_check_input_family_bymode(mmi_imm_get_prefer_input_mode());
#else
        g_dict_current_language = mmi_dictionary_check_input_family_bymode(g_dictionary_input_mode[0]);
#endif

        g_dictionary_language_main_screen = g_dict_current_language;
        switch(g_dict_current_language)
        {
        case DICTIONARY_ENGLISH:
            {
        mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
        cnt = mmi_dict_exact_search_id(
                    (PS8) g_dictionary_input_p,
                    (U8) g_dict_current_language,
                    (U8) ! g_dict_current_language);
        g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
        g_dictionary_cntx.starting_index = cnt;
            }
            break;

        case DICTIONARY_CHINESE:
            {
                g_dictionary_cntx.total_browse_entry = 0;
                g_dictionary_cntx.starting_index = 0;
            }
            break;

        default:
            {
                g_dict_current_language = DICTIONARY_ENGLISH;
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                g_dictionary_cntx.starting_index = cnt;
            }
            break;
        }

        ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        memset(g_dictionary_last_word_p, 0, ENCODING_LENGTH);

        /*
         *  Previous input method is just set to any member of previous family. Here Family is important to know.
         *  the assigned mode can be any mode from a family
         */
        g_dict_current_language = g_dictionary_language_main_screen;
        switch (g_dict_current_language)
        {
            case DICTIONARY_ENGLISH:
                g_mmi_dictionary_prev_input_mode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
                break;
            case DICTIONARY_CHINESE:
                g_mmi_dictionary_prev_input_mode = IMM_INPUT_MODE_TR_MULTITAP_BOPOMO;
                break;
            default:
                g_mmi_dictionary_prev_input_mode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        }

        if (mmi_imm_get_user_desired_input_mode() != IMM_INPUT_MODE_NONE)
        {
            currentLanguage = mmi_dictionary_check_input_family_bymode(mmi_imm_get_user_desired_input_mode());

            if (currentLanguage != g_dict_current_language)
            {
                switch (currentLanguage)
                {
                    case DICTIONARY_ENGLISH:
                        mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
                        cnt = mmi_dict_exact_search_id(
                                (PS8) g_dictionary_input_p,
                                (U8) currentLanguage,
                                (U8) ! currentLanguage);
                        g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                        g_dictionary_cntx.starting_index = cnt;
                        break;
                    case DICTIONARY_CHINESE:
                        g_dictionary_cntx.total_browse_entry = 0;
                        g_dictionary_cntx.starting_index = 0;
                        break;
                    default:
                        g_dictionary_cntx.total_browse_entry = 0;
                        g_dictionary_cntx.starting_index = 0;
                }

            }
        }
    }

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif 
    Register_pound_key_buffer_flush_test_function(mmi_dictionary_flush_editor_buffer);
    Register_appl_present_function(isFromDictionary);

#ifdef __MMI_DICTIONARY_SMALL_SCREEN__
    ShowCategory200Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dictionary_cntx.total_browse_entry,
        mmi_dictionary_list_get_item,
        NULL,
        0,
        IMG_DICTIONARY_SEARCH,
        (U8*) g_dictionary_input_buffer,
        DICTIONARY_INPUT_LENGTH + 1,
        guiBuffer);

    SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

#else /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 

    wgui_set_e_dictionary_test_clear_inputbox_buffer_funcptr(dictionary_dummy_function);
    wgui_cat201_register_language_changed_indicator(IsDictionaryLanguageChanged);
    ShowCategory201Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dictionary_cntx.total_browse_entry,
        mmi_dictionary_list_get_item,
        NULL,
        0,
        IMG_DICTIONARY_SEARCH,
        (U8*) g_dictionary_input_buffer,
        DICTIONARY_INPUT_LENGTH + 1,
        IMM_INPUT_TYPE_USER_SPECIFIC,
        guiBuffer,
        g_dictionary_input_mode);

    wgui_cat201_set_right_softkey_function(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    RegisterCat200SearchFunction(mmi_dictionary_find_entry);

#endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 

    g_mmi_dictionary_prev_input_mode = mmi_imm_get_curr_input_mode();
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(mmi_dictionary_entry_main_option_screen);
#endif
    SetCategory200LeftSoftkeyFunction(mmi_dictionary_entry_main_option_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_dictionary_entry_main_option_screen, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_dictionary_entry_result_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_main_screen
 * DESCRIPTION
 *  Exit function for main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_exit_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DICTIONARY_TTS__)
    StopTimer(DICTIONARY_TTS_TIMER);
    mdi_audio_resume_background_play(); 
#endif
    if(g_dictionary_last_word_p != NULL && g_dictionary_first_displayed_buffer_p != NULL)
    {
        memset(g_dictionary_last_word_p, 0, ENCODING_LENGTH);
        memset(g_dictionary_first_displayed_buffer_p, 0, ENCODING_LENGTH);
    }
    if(g_dictionary_cntx.app_mem_id != NULL)
    {
        g_dictionary_language_main_screen = g_dict_current_language;
        if (g_dictionary_cntx.total_browse_entry > 0)
        {
            g_dictionary_highlighted_item = DynamicListGetHighlightedItem((U8*) g_dictionary_last_word_p);
            g_dictionary_first_display_item = DynamicGetFirstDisplayedItem((U8*) g_dictionary_first_displayed_buffer_p);
        }
        g_dictionary_prev_index = -1;
    }
#ifdef __MMI_TOUCH_SCREEN__
	wgui_register_list_item_selected_callback_all(NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dictionary_dummy_function
 * DESCRIPTION
 *  dummy function assigned
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL dictionary_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IsDictionaryLanguageChanged
 * DESCRIPTION
 *  This function tell the GUI layer if language has been changes while coming back from history
 * PARAMETERS
 *  input_type      [IN]        changed input type
 * RETURNS
 *  BOOL TRUE : language has been changed.
 *  FALSE : language is not changed
 *****************************************************************************/
BOOL IsDictionaryLanguageChanged(U8 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE currentLanguage;
    MMI_BOOL languageChanged = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentLanguage = mmi_dictionary_check_input_family_bymode(input_type);

    if (g_dict_current_language != currentLanguage)
    {
        languageChanged = MMI_TRUE;
    }
    else
    {
        languageChanged = MMI_FALSE;
    }
    g_dict_current_language = currentLanguage;
    
    return languageChanged;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_engine
 * DESCRIPTION
 *  Exit function dictionary. Deinitilize dictionary memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_exit_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_disconnect();
    mmi_dict_exit();
    mmi_dictionary_del_adm_resource();
    applib_mem_ap_free(g_dictionary_cntx.app_mem_pool);
    g_dictionary_cntx.app_mem_pool = NULL;
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_del_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_del_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_wildcard_exact_buffer_p);
    g_dictionary_wildcard_exact_buffer_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_input_p);
    g_dictionary_input_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_last_word_p);
    g_dictionary_last_word_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_first_displayed_buffer_p);
    g_dictionary_first_displayed_buffer_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_search_result_p);
    g_dictionary_search_result_p = NULL;

    kal_adm_delete(g_dictionary_cntx.app_mem_id);
    g_dictionary_cntx.app_mem_id = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_word_hdlr
 * DESCRIPTION
 *  General highlight handler for word list in main dictionary screen
 * PARAMETERS
 *  index       [IN]        UI index of current selected word.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_word_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 dynamicItems;
    U8 g_dictionary_output[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_cntx.current_selected_index = index;
    g_dictionary_prev_index = index;
    memset(g_dictionary_input_p, 0, ENCODING_LENGTH);
    DynamicListGetHighlightedItem((U8*) g_dictionary_last_word_p);
    dynamicItems = DynamicListGetItems(NULL, 0);
#ifdef __MMI_DICTIONARY_TTS__
    if(g_dictionary_inline_cntx.HighligtItemonoff == DICTIONARY_TTS_STATE_ON && 
        srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED &&
        !mmi_imc_is_ime_state())
    {
        StopTimer(DICTIONARY_TTS_TIMER);
        StartTimer(DICTIONARY_TTS_TIMER, 500, mmi_dictionary_tts_word_speak);
    }
#endif /* __MMI_DICTIONARY_TTS__ */ 
    if (index <= 0)
    {
        ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
        if (!mmi_imc_is_ime_state())
        {
            ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        }
        return;
    }
    else
    {
        SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    }

    if (g_dict_current_language == DICTIONARY_ENGLISH)
    {

        if (g_dictionary_last_item || dynamicItems < 6)
        {
            return;
        }

        if (index >= (S32) (dynamicItems - 1))
        {
            /* this function is called to find out :whether further words exist in the word list */
            result = mmi_dict_get_word_by_indx(
                        (U8) g_dict_current_language,
                        (U16) (g_dictionary_cntx.starting_index + index + 1),
                        (S8*) g_dictionary_output);
        #ifdef __MMI_DICT_GV__ 
            while((result == MMI_TRUE) &&
                (mmi_ucs2cmp((S8*) g_dictionary_last_word_p,(S8*) g_dictionary_output) == 0))
            {
                g_dictionary_cntx.starting_index ++;
                result = mmi_dict_get_word_by_indx(
                            (U8) g_dict_current_language,
                            (U16) (g_dictionary_cntx.starting_index + index + 1),
                            (S8*) g_dictionary_output);
                if (result == FALSE)
                {
                    result = TRUE;
                }
            }
        #endif

            if (result == MMI_TRUE)
            {
                g_dictionary_cntx.total_browse_entry++;
                DynamicListIncreaseItem((S16) 1);
                g_dictionary_last_item = MMI_FALSE;
            }
            else
            {
                g_dictionary_last_item = MMI_TRUE;
            }
    
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_list_get_item
 * DESCRIPTION
 *  Fill the UI list for display, on request from UI.
 *  mmi_dict_exact_search_id/mmi_dict_exact_search_prev_id/mmi_dict_exact_search_next_id : set the focus to the word,
 *  mmi_dict_get_word_by_indx : get the focused word
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dictionary_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 g_dictionary_output[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    MMI_BOOL result, bufferCheck;
    S32 index = 0;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_MAIN);
    memset(g_dictionary_input_p, 0, ENCODING_LENGTH);

    if (g_dictionary_language_main_screen != g_dict_current_language)
    {
        if (mmi_frm_scrn_is_present(GRP_ID_DICT_MAIN, SCR_DICTIONARY_MAIN, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_clean_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_MAIN);
        }
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_MAIN);
        g_dictionary_language_main_screen = g_dict_current_language;
    }

    if (g_dict_current_language == DICTIONARY_ENGLISH)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        /* While coming back from history, and UI gets the items to display */
        if (guiBuffer && (item_index == g_dictionary_first_display_item && item_index != 0))
        {          
            mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_first_displayed_buffer_p);
            bufferCheck = mmi_dictionary_check_input_buffer((U8*) g_dictionary_input_p, (U8) g_dict_current_language);

            if (bufferCheck == MMI_TRUE)
            {
                index = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
            else
            {
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                index = mmi_dict_exact_search_id(
					(PS8) g_dictionary_input_p,
					(U8) g_dict_current_language,
					(U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
        }
        else if (item_index == 0)
        {
            mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_input_buffer);
            bufferCheck = mmi_dictionary_check_input_buffer((U8*) g_dictionary_input_p, (U8) g_dict_current_language);

            if (bufferCheck == MMI_TRUE)
            {
                index = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
            else
            {
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                index = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
        }
        else if (g_dictionary_prev_index > item_index)
        {
            /* get the dynamic element from UI. */
            DynamicListGetItems((U8*) g_dictionary_input_p, (U16) (item_index + 1));

            /* for MAUI_01093791 */
            result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);

            if (result == FALSE)
            {
                mmi_ucs2cpy((S8*) str_buff,"error");
                *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
                g_dictionary_prev_index = item_index;
                return MMI_TRUE;                
            }
            index = mmi_dict_exact_search_prev_id(
                        (PS8) g_dictionary_input_p,
                        1,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
        }
        else if (g_dictionary_prev_index < item_index)
        {
            /* get the dynamic element from UI. */
            DynamicListGetItems((U8*) g_dictionary_input_p, (U16) (item_index - 1));
            /* for MAUI_01093791 */
            result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);

            if (result == FALSE)
            {
                mmi_ucs2cpy((S8*) str_buff,"error");
                *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
                g_dictionary_prev_index = item_index;
                return MMI_TRUE;                
            }
            index = mmi_dict_exact_search_next_id(
                        (PS8) g_dictionary_input_p,
                        1,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
        }

        memset(g_dictionary_output, 0, ENCODING_LENGTH);
        result = mmi_dict_get_word_by_indx((U8) g_dict_current_language, (U16) (index), (S8*) g_dictionary_output);
        mmi_ucs2ncpy((S8*) str_buff, (S8*) g_dictionary_output, MMI_DICT_CORE_WORD_MAX  * ENCODING_LENGTH);
        *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);

        g_dictionary_prev_index = item_index;

        return MMI_TRUE;
    }

#ifndef __MMI_DICTIONARY_SMALL_SCREEN__
    if (g_dict_current_language == DICTIONARY_CHINESE)
    {
        if (item_index < g_dictionary_cntx.total_browse_entry)
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) g_dict_chinese_ids[item_index].dict_word, MMI_DICT_CORE_WORD_MAX  * ENCODING_LENGTH);
            *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
            return MMI_TRUE;

        }
        return MMI_TRUE;
    }
#endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_find_entry
 * DESCRIPTION
 *  Find the entries in dictionary based upon the input buffer.
 * PARAMETERS
 *  keyword     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dictionary_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stringLength, cnt = 0;
    MMI_BOOL bufferCheck;

#ifndef __MMI_DICTIONARY_SMALL_SCREEN__
    U16 resultCount;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_last_item = MMI_FALSE;
    g_dictionary_prev_index = 0;

    switch (mmi_imm_get_curr_input_mode())
    {
    #ifndef __MMI_DICTIONARY_SMALL_SCREEN__
        case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
        case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #else /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
        case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
    #endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
        {
            stringLength = mmi_ucs2strlen((S8*) keyword);
            g_dict_current_language = DICTIONARY_ENGLISH;
            memset(g_dictionary_input_p, 0, ENCODING_LENGTH);

            if (stringLength > 0)
            {
                mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) keyword);
                bufferCheck = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (bufferCheck == MMI_FALSE)
                {
                    /* First character  is not alphabet */
                    g_dictionary_cntx.starting_index = 0;
                    mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                    cnt = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                    g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((S8*) g_dictionary_input_p);
                    break;
                }

                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = cnt;
                g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                break;
            }
            else
            {
                g_dict_current_language = DICTIONARY_ENGLISH;
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = cnt;
                g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                break;
            }
            break;
        }

    #ifndef __MMI_DICTIONARY_SMALL_SCREEN__
        case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
        case IMM_INPUT_MODE_TR_STROKE:
        case IMM_INPUT_MODE_HK_STROKE:            
        case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
        case IMM_INPUT_MODE_SM_STROKE:
        case IMM_INPUT_MODE_SM_PINYIN:
        case IMM_INPUT_MODE_TR_BOPOMO:

            g_dict_current_language = DICTIONARY_CHINESE;
            stringLength = mmi_ucs2strlen((S8*) keyword);
            memset(g_dictionary_input_p, 0, ENCODING_LENGTH);
            memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
            g_dictionary_cntx.current_selected_index = 0;
            if (stringLength != 0)
            {
                mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) keyword);
                bufferCheck = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (bufferCheck == MMI_FALSE)
                {
                    /* First character  is not chinese character */
                    g_dictionary_cntx.starting_index = 0;
                    g_dictionary_cntx.total_browse_entry = 0;
                    break;

                }

                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*)g_dict_chinese_ids);
                g_dictionary_cntx.starting_index = 0;
                g_dictionary_cntx.total_browse_entry = resultCount;
                break;
            }
            else
            {
                memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                g_dictionary_cntx.starting_index = 0;
                g_dictionary_cntx.total_browse_entry = 0;
                break;
            }

            break;
    #endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ /* ifndef  __MMI_DICTIONARY_SMALL_SCREEN__ */
        default:
            g_dict_current_language = DICTIONARY_NONE;
            g_dictionary_cntx.starting_index = 0;
            g_dictionary_cntx.total_browse_entry = 0;
            break;
    }

    return g_dictionary_cntx.total_browse_entry;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_result_screen
 * DESCRIPTION
 *  Entry screen for result screen. Shows the meaning of word to the user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_result_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 *guibuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
	    GRP_ID_DICT_MAIN, 
	    SCR_DICTIONARY_RESULT, 
	    NULL, 
	    mmi_dictionary_entry_result_screen, 
	    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guibuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_RESULT);

    switch (g_dictionary_search_type)
    {
        case DICTIONARY_BROWSE:
            if (g_dict_current_language == DICTIONARY_ENGLISH)
            {
                result = mmi_dict_exact_search(
                            (S8*) g_dictionary_last_word_p,
                            (U8) g_dict_current_language,
                            (U8) (!g_dict_current_language),
                            MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                            g_dictionary_search_result_p);
            }
            else if (g_dict_current_language == DICTIONARY_CHINESE)
            {
                if (mmi_ucs2strlen((S8*) g_dict_chinese_ids[g_dictionary_cntx.current_selected_index].dict_word))
                {
                    result = mmi_dict_exact_search(
                                (S8*) g_dict_chinese_ids[g_dictionary_cntx.current_selected_index]. dict_word,
                                (U8) g_dict_current_language,
                                (U8) (!g_dict_current_language),
                                MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                                g_dictionary_search_result_p);
                }
                else
                {
                    mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_input_buffer);
					if (mmi_ucs2strlen((S8*)g_dictionary_input_p))
					{
						result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
						if (result == MMI_FALSE)
						{
							break;
						}
						result = mmi_dict_exact_search(
							(S8*) g_dictionary_input_p,
							(U8) g_dict_current_language,
							(U8) (!g_dict_current_language),
							MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                        g_dictionary_search_result_p);
					}
					else
					{
                        mmi_popup_display_simple(get_string(STR_GLOBAL_EMPTY), 
                                                 MMI_EVENT_FAILURE, 
                                                 GRP_ID_DICT_MAIN, 
                                                 NULL);
                        mmi_frm_scrn_close (GRP_ID_DICT_MAIN, SCR_DICTIONARY_RESULT);
                        result = MMI_FALSE;
					    return;
                    }
                }
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
        case DICTIONARY_WILDCARD_SEARCH:
            result = mmi_dict_exact_search(
                        (S8*) g_dict_wildcard_ids[g_dictionary_cntx.current_wildcard_search_index]. dict_word,
                        (U8) g_dict_current_language,
                        (U8) (!g_dict_current_language),
                        MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                        g_dictionary_search_result_p);
            break;
        case DICTIONARY_EXACT_SEARCH:
            result = mmi_dict_exact_search(
                        (S8*) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) (!g_dict_current_language),
                        MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                        g_dictionary_search_result_p);
            break;
    }

    if (result == MMI_FALSE)
    {
        mmi_popup_display_simple(get_string(STR_DICTIONARY_NO_MATCH_FOUND), 
                         MMI_EVENT_FAILURE, 
                         GRP_ID_DICT_MAIN, 
                         NULL);

        mmi_frm_scrn_close (GRP_ID_DICT_MAIN, SCR_DICTIONARY_RESULT);
        return;
    }

    ShowCategory78Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) g_dictionary_search_result_p,
        mmi_ucs2strlen((S8*) g_dictionary_search_result_p),
        guibuffer /* guiBuffer */ );
    
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_main_option_screen
 * DESCRIPTION
 *  Entry screen for dictionary option  screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_main_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                GRP_ID_DICT_MAIN, 
                CUI_MENU_SRC_TYPE_RESOURCE, 
                CUI_MENU_TYPE_OPTION, 
                DICTIONARY_OPTION_MENU, 
                MMI_TRUE, 
                NULL);
    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(menu_gid, get_image(GetRootTitleIcon(EXTRA_DICTIONARY_MENU)));
        cui_menu_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_wildcard_exact_editor_screen
 * DESCRIPTION
 *  Entry screen for wildcard, exact and chinese string search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_wildcard_exact_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strID = 0;
    mmi_id editor_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_dictionary_search_type)
    {
        case DICTIONARY_WILDCARD_SEARCH:
    #ifdef __MMI_DICT_GV__
            strID = STR_DICTIONARY_WILDCARD_SEARCH;
    #endif 

            break;
        case DICTIONARY_EXACT_SEARCH:
            strID = STR_DICTIONARY_EXACT_SEARCH;
            break;
    }
    editor_gid = cui_fseditor_create(GRP_ID_DICT_MAIN);
    if (editor_gid != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(editor_gid, strID, GetRootTitleIcon(EXTRA_DICTIONARY_MENU));
        cui_fseditor_set_default_options_menu(editor_gid, STR_DICTIONARY_EXACT_SEARCH, STR_GLOBAL_CANCEL);
        g_dictionary_wildcard_exact_buffer_p[0] = 0;
        g_dictionary_wildcard_exact_buffer_p[1] = 0;
        cui_fseditor_set_text(editor_gid, (WCHAR *)g_dictionary_wildcard_exact_buffer_p, (DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH, DICTIONARY_INPUT_LENGTH);
        cui_fseditor_set_input_method(editor_gid, IMM_INPUT_TYPE_USER_SPECIFIC, g_dictionary_input_mode, 0);
        cui_fseditor_run(editor_gid);
        g_mmi_dictionary_prev_input_mode = mmi_imm_get_curr_input_mode();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_wildcard_exact_editor_screen
 * DESCRIPTION
 *  Exit function for exact/wildcard buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_exit_wildcard_exact_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_search
 * DESCRIPTION
 *  This function search the database according to input in wildcard/exact search buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dictionary_entry_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resultCount = 0;
    U8 length;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((S8*) g_dictionary_wildcard_exact_buffer_p);

    length = length * 2;
    if (length == 0)
    {
        mmi_popup_display_simple(get_string(STR_GLOBAL_EMPTY), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);
        
        return MMI_FALSE;
    }
    mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_wildcard_exact_buffer_p);

    if (g_dictionary_search_type == DICTIONARY_WILDCARD_SEARCH)
    {
        switch (mmi_imm_get_curr_input_mode())
        {
            case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
            case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
            case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
            case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
                /* clean the string .check: for english string only */

                g_dict_current_language = DICTIONARY_ENGLISH;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }

                memset(g_dict_wildcard_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*)g_dict_wildcard_ids);
                if (resultCount != 0)
                {
                    g_dictionary_cntx.wildcard_results = resultCount;
                    mmi_dictionary_entry_wildcard_result_list_screen();
                }
                break;

            case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
            case IMM_INPUT_MODE_TR_STROKE:
            case IMM_INPUT_MODE_HK_STROKE:                
            case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
            case IMM_INPUT_MODE_SM_STROKE:
            case IMM_INPUT_MODE_SM_PINYIN:
            case IMM_INPUT_MODE_TR_BOPOMO:
                /* clean the string .check: for chinese string only  */
                g_dict_current_language = DICTIONARY_CHINESE;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }

                memset(g_dict_wildcard_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*) /* g_dict_chinese_ids */ g_dict_wildcard_ids);
                if (resultCount != 0)
                {
                    g_dictionary_cntx.wildcard_results = resultCount;
                    mmi_dictionary_entry_wildcard_result_list_screen();

                }
                break;

            default:
                mmi_popup_display_simple(get_string(STR_DICTIONARY_LANGUAGE_NOT_SUPPORTED), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);
                break;

        }
        if (resultCount == 0)
        {
            mmi_popup_display_simple(get_string(STR_DICTIONARY_NO_MATCH_FOUND), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);

        }
        else if (result == MMI_FALSE)
        {
            mmi_popup_display_simple(get_string(STR_DICTIONARY_NO_MATCH_FOUND), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);

        }
    }
    else if (g_dictionary_search_type == DICTIONARY_EXACT_SEARCH)
    {
        switch (mmi_imm_get_curr_input_mode())
        {
            case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
            case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
            case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
            case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
                /* clean the string  */
                g_dict_current_language = DICTIONARY_ENGLISH;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                mmi_dictionary_entry_result_screen();
                break;
            case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
            case IMM_INPUT_MODE_TR_STROKE:
            case IMM_INPUT_MODE_HK_STROKE:                
            case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
            case IMM_INPUT_MODE_SM_STROKE:
            case IMM_INPUT_MODE_SM_PINYIN:
            case IMM_INPUT_MODE_TR_BOPOMO:
                /* clean the string */
                g_dict_current_language = DICTIONARY_CHINESE;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                mmi_dictionary_entry_result_screen();
                break;
            default:
                mmi_popup_display_simple(get_string(STR_DICTIONARY_LANGUAGE_NOT_SUPPORTED), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);

                break;
        }

        /* result popup */
        if (result == MMI_FALSE)
        {
            mmi_popup_display_simple(get_string(STR_DICTIONARY_NO_MATCH_FOUND), 
                                 MMI_EVENT_FAILURE, 
                                 GRP_ID_DICT_MAIN, 
                                 NULL);
        }
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_check_input_buffer
 * DESCRIPTION
 *  This function check the input buffer according to language passed
 * PARAMETERS
 *  inputBuffer     [?]         
 *  language        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dictionary_check_input_buffer(U8 *inputBuffer, U8 language)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length,i, cnt = 0;
    S16 end_cnt;
    U8 tempBuf[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    U16 chineseCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filter out any space in the beginning */
    mmi_ucs2cpy((S8*) tempBuf, (S8*) inputBuffer);
    length = mmi_ucs2strlen((S8*) inputBuffer);
    length = length * ENCODING_LENGTH;
    while (length > cnt)
    {
        if ((tempBuf[cnt] == 0x20 || tempBuf[cnt] == 0x0A || tempBuf[cnt] == 0x0D) && (tempBuf[cnt + 1] == 0x00))       /* if first character is space */
        {
            cnt = cnt + 2;
            continue;
        }
        else
        {
            break;
        }
    }

    if (cnt == length)
    {
        /* user has entered only spaces in editor screen */
        return MMI_FALSE;
    }

    /* filter out any space in the end */
    end_cnt = length - 1;
    while (end_cnt > 0)
    {
        if ((tempBuf[end_cnt - 1] == 0x20) && (tempBuf[end_cnt] == 0x00))
        {
            end_cnt = end_cnt - 2;
        }
        else
        {
            break;
        }
    }
    memset(&tempBuf[end_cnt + 1], 0, 2);

    if (cnt != length)
    {
        mmi_ucs2cpy((S8*) inputBuffer, (S8*) & tempBuf[cnt]);    /* copy after intitial space */

        switch (language)
        {
            case DICTIONARY_ENGLISH:

                /* first char have to be  english alphabet only */
                if (!((inputBuffer[0] >= 65) && (inputBuffer[0] <= 90))
                    && !((inputBuffer[0] >= 97) && (inputBuffer[0] <= 122)))
                {
                    return MMI_FALSE;
                }
                for (i = 1; i < length; i += 2)
                {
				    chineseCode = ((UI_character_type) inputBuffer[i] << 8) | ((0xff)&&((UI_character_type) inputBuffer[i - 1]));
				    if ((chineseCode >= 0x4e00) && (chineseCode <= 0x9fa5))
                    {
						memset(&chineseCode,0,ENCODING_LENGTH);
                        return MMI_FALSE;
                    }
				}
   
                break;

            case DICTIONARY_CHINESE:

                memcpy(&chineseCode, &inputBuffer[0], 2);
                if ((chineseCode < 0x4e00) || (chineseCode > 0x9fa5))
                {
                    /* First character  is not chinese character */
                    return MMI_FALSE;
                }

                break;

        }

    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_wildcard_result_list_screen
 * DESCRIPTION
 *  This function shows the search result of wildcard and chinese search strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_wildcard_result_list_screen(void)
{
#ifdef __MMI_DICT_GV__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
	    GRP_ID_DICT_MAIN, 
	    SCR_DICTIONARY_WILDCARD_RESULT_LIST, 
	    NULL, 
	    mmi_dictionary_entry_wildcard_result_list_screen, 
	    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_DICT_MAIN, SCR_DICTIONARY_WILDCARD_RESULT_LIST);

    RegisterHighlightHandler(mmi_dictionary_wildcard_word_list_hdlr);
    ShowCategory184Screen(
                             STR_DICTIONARY_WILDCARD_SEARCH,
                             GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK, g_dictionary_cntx.wildcard_results, mmi_dictionary_wildcard_list_get_item,
                             /* HintPtr */ 0,
                             0, guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_dictionary_entry_result_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_result_screen, KEY_ENTER, KEY_EVENT_DOWN);
#endif /* __MMI_DICT_GV__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_wildcard_list_get_item
 * DESCRIPTION
 *  This function is to pass the wildcard and chinese strings to the UI to display
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dictionary_wildcard_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < g_dictionary_cntx.wildcard_results)
    {

        mmi_ucs2cpy((S8*) str_buff, (S8*) g_dict_wildcard_ids[item_index].dict_word);
        *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_wildcard_word_list_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for words in wildcard and chinese search list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_wildcard_word_list_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_cntx.current_wildcard_search_index = index;
    return;
}


#ifdef __MMI_DICTIONARY_TTS__

U8 g_dictionary_result_phonic[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];
U8 g_dictionary_is_speaking = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_setting_screen
 * DESCRIPTION
 *  entry tts setting screen
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_id = cui_inline_create(GRP_ID_DICT_MAIN, &dcit_inline_screen);

    if (inline_id != GRP_ID_INVALID)
    {
        g_dictionary_inline_cntx.inline_gid = inline_id;
        mmi_dictionary_set_inline_item();
        cui_inline_set_title_icon(inline_id, GetRootTitleIcon(EXTRA_DICTIONARY_MENU));
        cui_inline_run(inline_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_set_inline_item
 * DESCRIPTION
 *  Highlight handler for the set on menu in Dictionary setting menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_set_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.onoffbuffer, DS_BYTE, &error);
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.speedbuffer, DS_BYTE, &error);
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME, &g_dictionary_inline_cntx.volumebuffer, DS_BYTE, &error);
    cui_inline_set_value(g_dictionary_inline_cntx.inline_gid, 
                         ITEM_ID_SPEAKING_ITEM, 
                         (void *)g_dictionary_inline_cntx.onoffbuffer);
    cui_inline_set_value(g_dictionary_inline_cntx.inline_gid, 
                         ITEM_ID_SPEAK_SPEED_ITEM, 
                         (void *)g_dictionary_inline_cntx.speedbuffer);
    cui_inline_set_value(g_dictionary_inline_cntx.inline_gid, 
                         ITEM_ID_VOLUME_ITEM, 
                         (void *)g_dictionary_inline_cntx.volumebuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_save_speak_setting
 * DESCRIPTION
 *  speak the word by tts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_save_speak_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_inline_cntx.HighligtItemonoff = g_dictionary_inline_cntx.onoffbuffer;
    g_dictionary_inline_cntx.HighligtItemspeakspeed = g_dictionary_inline_cntx.speedbuffer;
    g_dictionary_inline_cntx.HighligtItemspeakvolume = g_dictionary_inline_cntx.volumebuffer;
    WriteValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME, &g_dictionary_inline_cntx.HighligtItemspeakvolume, DS_BYTE, &error);
    mmi_popup_display_simple(get_string(STR_GLOBAL_DONE), 
                             MMI_EVENT_SUCCESS, 
                             GRP_ID_DICT_MAIN, 
                             NULL);

    cui_inline_close(g_dictionary_inline_cntx.inline_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_tts_word_speak
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_tts_word_speak(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out_phonic[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];
    S8 *input_word;
    U8  tts_volume;
    U8  tts_speed;
    mdi_audio_tts_struct tts_play;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_is_ime_state())
    {
        return;
    }
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        return;
    } 
#endif 
    input_word = (S8 *)g_dictionary_last_word_p;
    memset(out_phonic, 0, ENCODING_LENGTH);
    if(!mmi_dict_get_word_phonic(input_word, g_dict_current_language, out_phonic))
    {
        return;
    }

    memset(g_dictionary_result_phonic, 0, ENCODING_LENGTH);
    mmi_dictionary_tts_phonic_switch((U16 *)out_phonic, (U16 *)g_dictionary_result_phonic);

    if(g_dictionary_is_speaking == 1)
    {
        mdi_audio_tts_stop();
    }
    
    tts_volume = mmi_dictionary_get_tts_volume();
    tts_speed = mmi_dictionary_get_tts_speed();
    tts_play.text_string = (U16 *)g_dictionary_result_phonic;
    tts_play.str_type = MDI_TTS_STR_PHN_SBL;
    tts_play.lang = MDI_TTS_LANG_ENG;
    tts_play.app_type = MDI_TTS_TYPE_DIC;
    tts_play.gander = MDI_TTS_GENDER_MALE;
    tts_play.volume = tts_volume;
    tts_play.path = MDI_DEVICE_SPEAKER2;
    tts_play.pitch = 50;
    tts_play.speed = tts_speed;
    tts_play.callback = mmi_dict_play_tts_finish_ind;

    result = mdi_audio_tts_play(tts_play);
    if(result == MDI_AUDIO_SUCCESS)
    {
        g_dictionary_is_speaking = 1;
    }
    else
    {
        g_dictionary_is_speaking = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_get_tts_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_get_tts_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tts_speed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_dictionary_inline_cntx.HighligtItemspeakspeed)
        {
        case DICTIONARY_TTS_SPEAK_SLOW:
        tts_speed = DICTIONARY_TTS_SLOW;
        break;
        
        case DICTIONARY_TTS_SPEAK_NORMAL:
        tts_speed = DICTIONARY_TTS_NORMAL;
        break;
        
        case DICTIONARY_TTS_SPEAK_FAST:
        tts_speed = DICTIONARY_TTS_FAST;
        break;
        
        default:
        tts_speed = DICTIONARY_TTS_NORMAL;
        break;
        }
    return tts_speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_get_tts_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_get_tts_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tts_volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_dictionary_inline_cntx.HighligtItemspeakvolume)
    {
    case DICTIONARY_TTS_SPEAK_VOLUME_0:
    case DICTIONARY_TTS_SPEAK_VOLUME_1:
    case DICTIONARY_TTS_SPEAK_VOLUME_2:
    case DICTIONARY_TTS_SPEAK_VOLUME_3:
    case DICTIONARY_TTS_SPEAK_VOLUME_4:
    case DICTIONARY_TTS_SPEAK_VOLUME_5:
    case DICTIONARY_TTS_SPEAK_VOLUME_6:
        tts_volume = g_dictionary_inline_cntx.HighligtItemspeakvolume;
        break;
    
    default:
        tts_volume = DICTIONARY_TTS_SPEAK_VOLUME_4;
        break;
    }
        return tts_volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_play_tts_finish_ind
 * DESCRIPTION
 *  call back function for mdi_audio_tts_play
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dict_play_tts_finish_ind(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == MDI_AUDIO_SUCCESS)
    {
        g_dictionary_is_speaking = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_tts_phonic_switch
 * DESCRIPTION
 *  switch the phonic 
 * PARAMETERS
 *  in_phonic [in]
 *  result_phonic[out]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_tts_phonic_switch(U16 *in_phonic, U16 *result_phonic)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_mark, out_mark;
    S32 input_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_len = mmi_ucs2strlen((S8 *)in_phonic);
    if(input_len <= 0)
    {
        return;
    }
#ifdef __MMI_DICT_MOTECH__
    if (input_len >= 2)
    {
        if (in_phonic[input_len - 2] == 0x0283 && in_phonic[input_len - 1] == 0x006E)
        {
            in_phonic[input_len - 1] = 0x0259;
            in_phonic[input_len] = 0x006E;
            in_phonic[input_len + 1] = 0x0000;
            input_len += 1;
        }
    }
#endif
    in_mark = 0;
    out_mark = 0;
    while(in_mark < input_len)
    {
        switch(in_phonic[in_mark])
        {
        case 0x0065:
            {
                if((in_phonic[in_mark + 1] == 0x0049 ||in_phonic[in_mark + 1] == 0x0069) && in_phonic[in_mark + 2] != 0x003A)
                {
                    result_phonic[out_mark] = 0x0065;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x005A;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0069:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0069;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0049;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0075:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0075;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x004A;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x00E6:
            {
                result_phonic[out_mark] = 0x0041;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0251:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0042;
                    in_mark += 2;
                    out_mark++;
                }  
            }
            break;

        case 0x0259:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x005B;
                    in_mark += 2;
                    out_mark++;
                }
                else if(in_phonic[in_mark + 1] == 0x0075)
                {
                    result_phonic[out_mark] = 0x006F;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0044;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0283:
            {
                result_phonic[out_mark] = 0x0046;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x014B:
            {
                result_phonic[out_mark] = 0x004E;
                in_mark++;
                out_mark++;    
            }
            break;

        case 0x028C:
            {
                result_phonic[out_mark] = 0x0051;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0254:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0052;
                    in_mark += 2;
                    out_mark++;
                }
                else if(in_phonic[in_mark + 1] == 0x0069)
                {
                    result_phonic[out_mark] = 0x0052;
                    in_mark++;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0053;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x00F0:
            {
                result_phonic[out_mark] = 0x0054;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0292:
            {
                result_phonic[out_mark] = 0x0056;
                in_mark++;
                out_mark++;
            }
            break;

        case 0xF403:
            {
                result_phonic[out_mark] = 0x0057;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x02CF:
        case 0x02CC:
            {
                result_phonic[out_mark] = 0x0037;
                in_mark++;
                out_mark++;
            } 
            break;

        case 0x0027:
        case 0x0060:
            {
                result_phonic[out_mark] = 0x0035;
                in_mark++;
                out_mark++;
            }
            break;
            
        case 0x0061:
            {
                result_phonic[out_mark] = 0x0061;
                if(in_phonic[in_mark + 1] == 0x0069 || in_phonic[in_mark + 1] == 0x0049)
                {
                    result_phonic[out_mark + 1] = 0x0049;
                }
                else if(in_phonic[in_mark + 1] == 0x0075)
                {
                    result_phonic[out_mark + 1] = 0x004A;
                }
                in_mark += 2;
                out_mark += 2;
            }
            break;

        case 0x025B:
            {
                result_phonic[out_mark] = 0x005A;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0028:/* ( ) - */
        case 0x0029:
        case 0x002D:
            {
                in_mark++;
            }
            break;
            
        case 0x0062:
        case 0x0063:
        case 0x0064:
        case 0x0066:
        case 0x0067:
        case 0x0068:
        case 0x006A:
        case 0x006B:
        case 0x006C:
        case 0x006D:
        case 0x006E:
        case 0x0070:
        case 0x0071:
        case 0x0072:
        case 0x0073:
        case 0x0074:
        case 0x0076:
        case 0x0077:
        case 0x0078:
        case 0x0079:
        case 0x007A:
            {
                result_phonic[out_mark] = in_phonic[in_mark];
                in_mark++;
                out_mark++;
            }
            break;

        default:
            in_mark = input_len;
            break;
        }
    }
    memset(&result_phonic[out_mark], 0, 2);
}
#endif /*__MMI_DICTIONARY_TTS__*/


/*****************************************************************************
 * FUNCTION
 *  isFromDictionary
 * DESCRIPTION
 *  This function returns to the UI whether control has come from dictionary or not
 *  vice versa
 * PARAMETERS
 *  max_number      [?]     
 * RETURNS
 *  pBOOL : TRUE :From dictionary
 *  FALSE : Not from the dictionary
 *****************************************************************************/
BOOL isFromDictionary(S32 *max_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_DICT_MAIN))
    {
        *max_number = DICTIONARY_MAX_WORDS;
        return MMI_TRUE;

    }
    else
    {
        *max_number = 0;
        return MMI_FALSE;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_flush_editor_buffer
 * DESCRIPTION
 *  This function is  to flush buffer when user change input method, from english family to chinese
 *  vice versa
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL : TRUE :Family has been changed. Flush the buffer
 *  FALSE : Need to flush the output.
 *****************************************************************************/
BOOL mmi_dictionary_flush_editor_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL isOldFamily, scrPresent;
    U16 activeScrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activeScrID = GetActiveScreenId();
    scrPresent = IsScreenPresent(SCR_DICTIONARY_MAIN);

    if (activeScrID == SCR_INPUT_METHOD_LIST)
    {
        if (!scrPresent)
        {
            return MMI_FALSE;
        }

    }
    else if (!(activeScrID == SCR_DICTIONARY_WILDCARD_EXACT_EDITOR || activeScrID == SCR_DICTIONARY_MAIN))
    {
        return MMI_FALSE;
    }

    switch (g_mmi_dictionary_prev_input_mode)
    {
        case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
        case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
            switch (mmi_imm_get_curr_input_mode())
            {
                case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
                case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
                case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
                case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
                case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
                case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
                    isOldFamily = MMI_TRUE;
                    break;
                default:
                    isOldFamily = MMI_FALSE;

            }
            break;
        case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
        case IMM_INPUT_MODE_TR_STROKE:
        case IMM_INPUT_MODE_HK_STROKE:            
        case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
        case IMM_INPUT_MODE_SM_STROKE:
        case IMM_INPUT_MODE_SM_PINYIN:
        case IMM_INPUT_MODE_TR_BOPOMO:
            switch (mmi_imm_get_curr_input_mode())
            {
                case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
                case IMM_INPUT_MODE_TR_STROKE:
                case IMM_INPUT_MODE_HK_STROKE:                    
                case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
                case IMM_INPUT_MODE_SM_STROKE:
                case IMM_INPUT_MODE_SM_PINYIN:
                case IMM_INPUT_MODE_TR_BOPOMO:
                    isOldFamily = MMI_TRUE;
                    break;
                default:
                    isOldFamily = MMI_FALSE;

            }
            break;
        default:
            isOldFamily = MMI_FALSE;
    }

    g_mmi_dictionary_prev_input_mode = mmi_imm_get_curr_input_mode();

    if (isOldFamily)
    {
        return MMI_FALSE;
    }
    else
    {
        g_dict_current_language = mmi_dictionary_check_input_family_bymode(mmi_imm_get_curr_input_mode());
        return MMI_TRUE;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_check_input_family_bymode
 * DESCRIPTION
 *  This function is  return the input family type
 * PARAMETERS
 *  inputmode           [IN]            
 * RETURNS
 *  MMI_DICTIONARY_LANGUAGE : english/chinese/none
 *****************************************************************************/
MMI_DICTIONARY_LANGUAGE mmi_dictionary_check_input_family_bymode(U16 inputmode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE family;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(inputmode)
    {
        case IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_UPPERCASE_ABC:
        case IMM_INPUT_MODE_SMART_LOWERCASE_ABC:
        case IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
            family = DICTIONARY_ENGLISH;
            break;

    #ifndef __MMI_DICT_MOTECH__
        case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
    #endif        
        case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
            
    #if !defined(__MMI_TOUCH_SCREEN__)
     #ifndef __MMI_DICT_MOTECH__  
        case IMM_INPUT_MODE_TR_STROKE:
        case IMM_INPUT_MODE_HK_STROKE:            
        case IMM_INPUT_MODE_TR_BOPOMO:
     #endif       
        case IMM_INPUT_MODE_SM_STROKE:
        case IMM_INPUT_MODE_SM_PINYIN:
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
            family = DICTIONARY_CHINESE;
            break;

        default:
            family = DICTIONARY_ENGLISH;
        }
    return family;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_flush_exact_wild_editor_buffer
 * DESCRIPTION
 *  This function is  called when  input method is changed from exact/wildcard editor -> option->input method
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL TRUE : language has been changed
 *  FALSE : language is not changed
 *****************************************************************************/
BOOL mmi_dictionary_flush_exact_wild_editor_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE currentLanguage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imm_get_user_desired_input_mode() != IMM_INPUT_MODE_NONE)
    {
        currentLanguage = mmi_dictionary_check_input_family_bymode(mmi_imm_get_user_desired_input_mode());
        if (currentLanguage != g_dict_current_language)
        {
            g_dict_current_language = currentLanguage;
            return MMI_TRUE;
        }
    }
    else
    {
        currentLanguage = mmi_dictionary_check_input_family_bymode(mmi_imm_get_curr_input_mode());
        if (currentLanguage != g_dict_current_language)
        {
            g_dict_current_language = currentLanguage;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}
#elif defined(__MMI_DICTIONARY__)

#include "CommonScreens.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_main_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/* for simulator after modify sethilitehandler*/

#endif /* defined(__MMI_DICTIONARY__) */

