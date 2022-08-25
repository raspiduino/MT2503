

#include "kmx_input_config.h"

#include "MMIDataType.h"
#include "Mmi_frm_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MenuCuiGprot.h"
#include "Mmi_rp_app_komoxo_def.h"
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "wgui_categories_util.h"
#include "wgui_include.h"

#include "csk2api.h"
#include "cstar_ime.h"

#ifdef __MMI_KMX_TOUCH_INPUT__
#include "kmximmapi.h"
#include "kmxsip_config.h"
#include "Kmxsip_user_data.h"
#endif

#include "GlobalResDef.h"
#include "mmi_rp_all_defs.h"

#ifdef __MMI_KOMOXO__
mmi_ret mmi_kmx_ime_setting_proc(mmi_event_struct *evt);

static MMI_ID g_kmx_ime_setting_gid;
static MMI_ID g_kmx_ime_menu_gid;

static void mmi_kmx_setting_entry_hdlr(cui_menu_event_struct *evt);
static void mmi_kmx_setting_highlight_hdlr(cui_menu_event_struct *evt);
static void mmi_kmx_setting_select_hdlr(cui_menu_event_struct *evt);

#if defined(__MMI_KOMOXO__) && defined(__MMI_CSTAR_SM_CHINESE__)
static void KmxEntryFuzzySet(void);
#if !defined(__MMI_KMX_NO_KEYPAD__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static void KmxEntryPinyinSelectSet(void);
#endif
static void KmxEntryCandModeSet(void);

#ifdef __MMI_KMX_MARTIAN_SCRIPT__
static void mmi_kmx_highlight_martian_script_setting(void);
static void mmi_kmx_set_martian_script_input_with_sg(MMI_ID sender_id);
static void mmi_kmx_update_hint_martian_script_input_with_sg(MMI_ID sender_id);
#endif

#ifdef __MMI_KMX_UPDATE_USER_WORD__
extern void mmi_kmx_ask_user_word_update_check(void);
#endif

#endif

#if defined(__MMI_KMX_TOUCH_INPUT__)
static void mmi_kmx_update_hint_keypad_setting_with_sg(MMI_ID sender_id);
static void mmi_kmx_entry_keypad_setting(void);
#endif

static void mmi_kmx_show_about_info(void);

void mmi_input_method_setting_callback(MMI_ID parent_gid)
{    
    g_kmx_ime_setting_gid = mmi_frm_group_create(    //create a screen group to manage menu CUI(common UI)
                        parent_gid,
                        GRP_ID_AUTO_GEN,
                        mmi_kmx_ime_setting_proc,
                        (void*)NULL);
                        
    mmi_frm_group_enter(g_kmx_ime_setting_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);  //like that entering new screen

    g_kmx_ime_menu_gid = cui_menu_create(    //create a menu CUI to manage the menu indicated in resource file
                    g_kmx_ime_setting_gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_APPMAIN,
                    MENU_ID_KMX_INPUT_METHOD_SETTING,
                    MMI_TRUE,
                    NULL);
                        
    cui_menu_run(g_kmx_ime_menu_gid);  //let the menu cui to run (show menu)
}

#ifdef _MSC_VER
#define KMX_BEGIN_TRANSLATE_TABLE(id) switch(id) { default: break
#define KMX_END_TRANSLATE_TABLE() }
#define KMX_TRANSLATE_ENTRY(e)  case e: return #e

static const char* kmx_translate_menu_event_name(unsigned int event_id)
{
    KMX_BEGIN_TRANSLATE_TABLE(event_id);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_LIST_ENTRY);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_LIST_EXIT);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_ITEM_HILITE);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_ITEM_SELECT);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_ITEM_TAP);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_ITEM_CSK_SELECT);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_CLOSE_REQUEST);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE);
    KMX_TRANSLATE_ENTRY(EVT_ID_CUI_MENU_EVENT_ALL);
    KMX_END_TRANSLATE_TABLE();

    return NULL;
}
#endif

/* Handle Menu Items events and dispatch menu events to corresponding sub menus. */
mmi_ret mmi_kmx_ime_setting_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:  
            mmi_kmx_setting_entry_hdlr(menu_evt);                        
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_kmx_setting_highlight_hdlr(menu_evt);
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_kmx_setting_select_hdlr(menu_evt);
            break;            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    #ifdef _MSC_VER
    {
        const char* name;
        name = kmx_translate_menu_event_name(menu_evt->evt_id);
        if (name)
        {
            printf("!!!!!!!!!!!!! Menu evnet %s, id: %d \r\n", name, menu_evt->evt_id);
        }
        else
        {
            printf("!!!!!!!!!!!!! Menu evnet Unknown, id: %d \r\n", menu_evt->evt_id);
        }
    }    
    #endif
    return MMI_RET_OK;
}

static void mmi_kmx_setting_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /* Use numbered icon */
    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    #if defined(__MMI_KMX_TOUCH_INPUT__)
    mmi_kmx_update_hint_keypad_setting_with_sg(menu_evt->sender_id);
    #endif

    #ifdef __MMI_KMX_MARTIAN_SCRIPT__    
    mmi_kmx_update_hint_martian_script_input_with_sg(menu_evt->sender_id);    
    #endif    
}

static void mmi_kmx_setting_highlight_hdlr(cui_menu_event_struct *menu_evt)
{
    switch (menu_evt->highlighted_menu_id)
    {
        default:
            cui_menu_change_left_softkey_string(mmi_frm_group_get_active_id(), (WCHAR*)GetString(STR_GLOBAL_OK));            
        break;
        #ifdef __MMI_KMX_MARTIAN_SCRIPT__
        case MENU_ID_KMX_INPUT_METHOD_SET_MARTIAN_SCRIPT:        
            mmi_kmx_highlight_martian_script_setting();
            break;
        #endif
    }
}

static void mmi_kmx_setting_select_hdlr(cui_menu_event_struct *menu_evt)
{
    switch (menu_evt->highlighted_menu_id)
    {
        
        #if defined(__MMI_KMX_TOUCH_INPUT__)
        case MENU_ID_KMX_INPUT_METHOD_KEYPAD_OPTION:
            mmi_kmx_entry_keypad_setting();
            break;
        #endif

        #if defined(__MMI_KOMOXO__) && defined(__MMI_CSTAR_SM_CHINESE__)
        case MENU_ID_KMX_INPUT_METHOD_FUZZY_SETTING:
            KmxEntryFuzzySet();
            break;
	    #if !defined(__MMI_KMX_NO_KEYPAD__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        case MENU_ID_KMX_INPUT_METHOD_PINYIN_SELECTING_SETTING:
            KmxEntryPinyinSelectSet();
            break;
	    #endif /* #if !defined(__MMI_KMX_NO_KEYPAD__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
	
        case MENU_ID_KMX_INPUT_METHOD_PINYIN_CAND_MODE_SETTING:
            KmxEntryCandModeSet();
		    break;
	    #ifdef __MMI_KMX_UPDATE_USER_WORD__
        case MENU_ID_KMX_INPUT_METHOD_UPDATE_USER_WORD:
            mmi_kmx_ask_user_word_update_check();
            break;
	    #endif
	
	    #ifdef __MMI_KMX_MARTIAN_SCRIPT__
        case MENU_ID_KMX_INPUT_METHOD_SET_MARTIAN_SCRIPT:
            mmi_kmx_set_martian_script_input_with_sg(menu_evt->sender_id);
            break;
	    #endif

        #endif /* #if defined(__MMI_KOMOXO__) && defined(__MMI_CSTAR_SM_CHINESE__) */
        
        case MENU_ID_KMX_INPUT_METHOD_ABOUT:
            mmi_kmx_show_about_info();
            break;
    }
}


#if defined(__MMI_CSTAR_SM_CHINESE__)
/* Pinyin setting */
#define KMX_CHECK_MAX       10
static unsigned char        g_check_box_state[KMX_CHECK_MAX];
static int                  g_active_item = 0;
static unsigned char        g_item_changed = 0;
static void (*KmxSaveSettingFunc)(void) = 0;

static void KmxSetCheckItemIndex(int index)
{
    g_active_item = index;
}

static void KmxSetRadioItemIndex(int index)
{
    if(g_active_item == index)
        return;

    g_active_item = index;
}

static void KmxCheckItem(void)
{
    if(g_check_box_state[g_active_item])
    {
        g_check_box_state[g_active_item] = 0;
    }
    else
    {
        g_check_box_state[g_active_item] = 1;
    }
    standard_check_list_handle_item_select(g_active_item);

    if(!g_item_changed)
    {
        set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_DONE));
        SetRightSoftkeyFunction(KmxSaveSettingFunc, KEY_EVENT_UP);
        redraw_right_softkey();
    }

    g_item_changed = 1;
}

/* Fuzzy Setting Menu */
static void __inline KmxGetFuzzyState(unsigned long fuzzy)
{
    g_check_box_state[0] = (unsigned char)((fuzzy & CS_FUZZY_Z_ZH) != 0);
    g_check_box_state[1] = (unsigned char)((fuzzy & CS_FUZZY_C_CH) != 0);
    g_check_box_state[2] = (unsigned char)((fuzzy & CS_FUZZY_S_SH) != 0);
    g_check_box_state[3] = (unsigned char)((fuzzy & CS_FUZZY_H_F) != 0);
    g_check_box_state[4] = (unsigned char)((fuzzy & CS_FUZZY_N_L) != 0);
    g_check_box_state[5] = (unsigned char)((fuzzy & CS_FUZZY_IN_ING) != 0);
    g_check_box_state[6] = (unsigned char)((fuzzy & CS_FUZZY_EN_ENG) != 0);
    g_check_box_state[7] = (unsigned char)((fuzzy & CS_FUZZY_AN_ANG) != 0);
}

static unsigned long __inline KmxSetFuzzyState(void)
{
    unsigned long fuzzy = 0;

    if(g_check_box_state[0])
        fuzzy |= CS_FUZZY_Z_ZH;
    if(g_check_box_state[1])
        fuzzy |= CS_FUZZY_C_CH;
    if(g_check_box_state[2])
        fuzzy |= CS_FUZZY_S_SH;
    if(g_check_box_state[3])
        fuzzy |= CS_FUZZY_H_F;
    if(g_check_box_state[4])
        fuzzy |= CS_FUZZY_N_L;
    if(g_check_box_state[5])
        fuzzy |= CS_FUZZY_IN_ING;
    if(g_check_box_state[6])
        fuzzy |= CS_FUZZY_EN_ENG;
    if(g_check_box_state[7])
    {
        fuzzy |= CS_FUZZY_AN_ANG;
        fuzzy |= CS_FUZZY_IAN_IANG;
        fuzzy |= CS_FUZZY_UAN_UANG;
    }
    return fuzzy;
}

static void KmxSaveFuzzySetting(void)
{
    unsigned long fuzzy;

    fuzzy = KmxSetFuzzyState();
    cstar_ime_set_fuzzy(fuzzy);
    
    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    g_item_changed = 0;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
}

static void KmxEntryFuzzySet(void)
{
    static U16 nStrItemList[] = {
        STR_ID_KMX_FUZZY_Z_ZH,
        STR_ID_KMX_FUZZY_C_CH,
        STR_ID_KMX_FUZZY_S_SH,
        STR_ID_KMX_FUZZY_H_F,
        STR_ID_KMX_FUZZY_N_L,
        STR_ID_KMX_FUZZY_IN_ING,
        STR_ID_KMX_FUZZY_EN_ENG,
        STR_ID_KMX_FUZZY_AN_ANG
    };
    U16 nNumofItem = sizeof(nStrItemList) / sizeof(U16);
    U8 *guiBuffer;
    unsigned long fuzzy;

    fuzzy = cstar_ime_get_fuzzy();
    KmxGetFuzzyState(fuzzy);
    g_active_item = 0;
    g_item_changed = 0;
    
    EntryNewScreen(SCR_KMX_IME_PINYIN_FUZZY_SETTING, NULL, KmxEntryFuzzySet, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_KMX_IME_PINYIN_FUZZY_SETTING); 
    
    RegisterHighlightHandler(KmxSetCheckItemIndex);

    ShowCategory13Screen(
        STR_ID_KMX_FUZZY_SETTING,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        g_check_box_state,
        0,
        guiBuffer);

    KmxSaveSettingFunc = KmxSaveFuzzySetting;

    SetLeftSoftkeyFunction(KmxCheckItem, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#if !defined(__MMI_KMX_NO_KEYPAD__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/* Pinyin Selecting Menu */

static int __inline KmxGetPinyinModeState(unsigned long mode)
{
    switch (mode)
    {
    case CS_PINYIN_MODE_1:
        return 0;
    case CS_PINYIN_MODE_2:
        return 1;
    case CS_PINYIN_MODE_3:
        return 2;
    }
    return 0;
}

static unsigned long __inline KmxSetPinyinModeState(void)
{
    switch(g_active_item)
    {
    default:
    case 0:
        return CS_PINYIN_MODE_1;
    case 1:
        return CS_PINYIN_MODE_2;
    case 2:
        return CS_PINYIN_MODE_3;
    }
}

static void KmxSavePinyinModeSetting(void)
{
    unsigned long mode;

    mode = KmxSetPinyinModeState();
    cstar_ime_set_pinyin_mode(mode);
    
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    #ifdef __MMI_IME_FTE_ENHANCE__
    DeleteNHistory(1);
    #endif
}

static void KmxEntryPinyinSelectSet(void)
{
    static U16 nStrItemList[] = {
        STR_ID_KMX_PINYIN_SELECTING_MODE1,
        STR_ID_KMX_PINYIN_SELECTING_MODE2,
        STR_ID_KMX_PINYIN_SELECTING_MODE3
    };
    U16 nNumofItem = sizeof(nStrItemList) / sizeof(U16);
    U8 *guiBuffer;
    unsigned long mode;

    mode = cstar_ime_get_pinyin_mode();
    g_active_item = KmxGetPinyinModeState(mode);
    
    EntryNewScreen(SCR_KMX_IME_PINYIN_SELECTING_SETTING, NULL, KmxEntryPinyinSelectSet, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_KMX_IME_PINYIN_SELECTING_SETTING); 
    
    RegisterHighlightHandler(KmxSetRadioItemIndex);

    ShowCategory11Screen(
        STR_ID_KMX_PINYIN_SELECTING_SETTING,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16)g_active_item,
        guiBuffer);

    SetLeftSoftkeyFunction(KmxSavePinyinModeSetting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* #if !defined(__MMI_KMX_NO_KEYPAD__) */
/* Pinyin Candidate Mode Menu */

static int __inline KmxGetPinyinCandModeState(unsigned long mode)
{
    if((unsigned char)((mode & CS_CANDIDATE_MODE_1) != 0))
        return 0;

    if((unsigned char)((mode & CS_CANDIDATE_MODE_2) != 0))
        return 1;

    return 0;
}

static unsigned long __inline KmxSetPinyinCandModeState(void)
{
    switch(g_active_item)
    {
    default:
    case 0:
        return CS_CANDIDATE_MODE_1;
    case 1:
        return CS_CANDIDATE_MODE_2;
    }
}

static void KmxSavePinyinCandModeSetting(void)
{
    unsigned long mode;

    mode = KmxSetPinyinCandModeState();
    cstar_ime_set_candidate_mode(mode);
    
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    #ifdef __MMI_IME_FTE_ENHANCE__
    DeleteNHistory(1);
    #endif
}

static void KmxEntryCandModeSet(void)
{
    static U16 nStrItemList[] = {
        STR_ID_KMX_PINYIN_CAND_MODE1,
        STR_ID_KMX_PINYIN_CAND_MODE2
    };
    U16 nNumofItem = sizeof(nStrItemList) / sizeof(U16);
    U8 *guiBuffer;
    unsigned long mode;

    mode = cstar_ime_get_candidate_mode();
    g_active_item = KmxGetPinyinCandModeState(mode);
    
    EntryNewScreen(SCR_KMX_IME_PINYIN_CAND_SETTING, NULL, KmxEntryCandModeSet, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_KMX_IME_PINYIN_CAND_SETTING); 
    
    RegisterHighlightHandler(KmxSetRadioItemIndex);

    ShowCategory11Screen(
        STR_ID_KMX_PINYIN_CAND_MODE_SETTING,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16)g_active_item,
        guiBuffer);

    SetLeftSoftkeyFunction(KmxSavePinyinCandModeSetting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#if defined(__MMI_KMX_MARTIAN_SCRIPT__)

void mmi_kmx_update_hint_martian_script_input_with_sg(MMI_ID sender_id)
{   
    
    if (cstar_ime_get_martian_script_option())
        cui_menu_set_item_hint(sender_id, 
                               MENU_ID_KMX_INPUT_METHOD_SET_MARTIAN_SCRIPT,
                               (UI_string_type)GetString(STR_GLOBAL_ON));                
    else
        cui_menu_set_item_hint(sender_id, 
                               MENU_ID_KMX_INPUT_METHOD_SET_MARTIAN_SCRIPT,
                               (UI_string_type)GetString(STR_GLOBAL_OFF));                        
}

static void mmi_kmx_set_martian_script_input_with_sg(MMI_ID sender_id)
{        
    unsigned int status;

    status = cstar_ime_get_martian_script_option();
    status = ~status & 1;
    cstar_ime_set_martian_script_option(status);
    gdi_layer_lock_frame_buffer();
    if (status)
    {        
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {        
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    mmi_kmx_update_hint_martian_script_input_with_sg(sender_id);
    gdi_layer_unlock_frame_buffer();
    RedrawCategoryFunction();
}

static void mmi_kmx_highlight_martian_script_setting(void)
{
    if (cstar_ime_get_martian_script_option())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_KMX_MARTIAN_SCRIPT__ */

#endif /* __MMI_CSTAR_SM_CHINESE__ */

#if defined(__MMI_KMX_TOUCH_INPUT__)
extern KMX_USER_PROFILE kmx_user_profile;
static int g_kmx_selected_item;
static unsigned char g_kmx_keypad_item_map[] = {KMX_KEYBOARD_TYPE_DIGIT, KMX_KEYBOARD_TYPE_QWERTY};

#ifdef KMX_ARRAY_SIZE
#undef KMX_ARRAY_SIZE
#endif

#define KMX_ARRAY_SIZE(a) (sizeof((a)) / sizeof((a)[0]))

static void mmi_kmx_higlight_selected_item(S32 index)
{
    g_kmx_selected_item = (int)index;
}

static void mmi_kmx_update_hint_keypad_setting_with_sg(MMI_ID sender_id)
{
    load_ime_user_setting();
    if(kmx_user_profile.softkeyboard_type == KMX_KEYBOARD_TYPE_DIGIT)
    {
        cui_menu_set_item_hint(sender_id, 
                               MENU_ID_KMX_INPUT_METHOD_KEYPAD_OPTION,
                               (UI_string_type)GetString(STR_ID_KMX_DIGIT_KEYPAD));  
    }
    else
    {
        cui_menu_set_item_hint(sender_id, 
                               MENU_ID_KMX_INPUT_METHOD_KEYPAD_OPTION,
                               (UI_string_type)GetString(STR_ID_KMX_QWERTY_KEYPAD));  
    }
}

static void mmi_kmx_save_keypad_setting(void)
{  
    /* What if kmx touch keypad is disabled? hide this menuitem? */
    if (!kmx_user_profile.enable_touch_keypad || g_kmx_selected_item >= KMX_ARRAY_SIZE(g_kmx_keypad_item_map))
    {
        goto Exit;
    }

    if (kmx_user_profile.softkeyboard_type == g_kmx_keypad_item_map[g_kmx_selected_item])
    {
        /* Setting not changed! */
        goto Exit;
    }

    kmx_user_profile.softkeyboard_type = g_kmx_keypad_item_map[g_kmx_selected_item];                  

    save_ime_user_setting();

Exit:
    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
}   

static int mmi_kmx_get_keypad_setting_item_by_keyboard_type(unsigned char keyboard_type)
{
    int i;
    for(i = 0; i < KMX_ARRAY_SIZE(g_kmx_keypad_item_map); i++)
    {
        if (keyboard_type == g_kmx_keypad_item_map[i])
            return i;
    }
    /* Should not arrive here, keyboard type is invalid */
    return 0;
}

#ifdef __COSMOS_MMI_PACKAGE__
    #ifndef MAIN_MENU_TITLE_SETTINGS_ICON
    #define MAIN_MENU_TITLE_SETTINGS_ICON 0
    #endif
#endif

static void mmi_kmx_entry_keypad_setting(void)
{
    U8 * pGuiBuffer = 0;
    S32 keypad_set_number = KMX_ARRAY_SIZE(g_kmx_keypad_item_map);        
    int i;

    EntryNewScreen(SCR_KMX_KEYPAD_OPTION, NULL, mmi_kmx_entry_keypad_setting,NULL);
    
    for (i = 0; i < keypad_set_number; i++)
    {
        /* !! STR ID must in asc order and no gap!! */
        subMenuDataPtrs[i] = (PU8)GetString((U16)(STR_ID_KMX_DIGIT_KEYPAD + i));
    }
        
    load_ime_user_setting();
    
    g_kmx_selected_item = mmi_kmx_get_keypad_setting_item_by_keyboard_type(kmx_user_profile.softkeyboard_type);

    RegisterHighlightHandler(mmi_kmx_higlight_selected_item);
    
    pGuiBuffer = GetCurrGuiBuffer(SCR_KMX_KEYPAD_OPTION);

    ShowCategory36Screen(
        STR_MENU_KMX_KEYPAD_OPTION,        
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        keypad_set_number,
        (U8 **) subMenuDataPtrs,
        g_kmx_selected_item,
        pGuiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_kmx_save_keypad_setting, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_KMX_TOUCH_INPUT__ */

static void mmi_kmx_show_about_info(void)
{
    DisplayPopup((PU8) GetString(STR_ID_KMX_INPUT_METHOD_ABOUT_DETAIL), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION * 2, SUCCESS_TONE);    
}

#endif /* __MMI_KOMOXO__ */
