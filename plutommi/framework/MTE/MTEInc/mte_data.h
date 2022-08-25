//
// DO NOT MODIFY ME!!!
//

#define	MMI_MTE_THEME_COMPONENT_NUM	488
#define	MMI_MTE_THEME_COMPONENT_GROUP_NUM	35


typedef struct
{
    unsigned int num;
    int component_id[MMI_MTE_THEME_COMPONENT_NUM];    
} mmi_mte_control_set_group_struct;

typedef struct
{
    unsigned int num;
    int dm_group_id[DM_CONTROL_TOTAL];
} mmi_mte_control_set_discard_dm_struct;

typedef struct
{
    int   screen_id;
    int   category_id;
    mmi_mte_control_set_group_struct component_set;
    mmi_mte_control_set_discard_dm_struct discard_dm;
} mmi_mte_current_screen_filter_struct;


static S32 mmi_mte_category_filter_1[] = {MMI_CATEGORY142_ID, MMI_CATEGORY142_STATUS_ICON_ID, -1};
static S32 mmi_mte_category_filter_2[] = {MMI_CATEGORY142_ID, MMI_CATEGORY142_STATUS_ICON_ID, -1};
static S32 mmi_mte_category_filter_38[] = {MMI_CATEGORY72_ID, -1};
static S32 mmi_mte_category_filter_42[] = {MMI_CATEGORY306_ID, -1};
static S32 mmi_mte_category_filter_43[] = {MMI_CATEGORY306_ID, -1};
static S32 mmi_mte_category_filter_115[] = {MMI_CATEGORY264_ID, -1};
static S32 mmi_mte_category_filter_172[] = {MMI_CATEGORY12_ID, MMI_CATEGORY140_ID, MMI_CATEGORY186_ID, MMI_CATEGORY384_ID, -1};
static S32 mmi_mte_category_filter_173[] = {MMI_CATEGORY12_ID, MMI_CATEGORY140_ID, MMI_CATEGORY186_ID, MMI_CATEGORY384_ID, -1};
static S32 mmi_mte_category_filter_174[] = {MMI_CATEGORY36_ID, MMI_CATEGORY109_ID, MMI_CATEGORY172_ID, -1};
static S32 mmi_mte_category_filter_175[] = {MMI_CATEGORY36_ID, MMI_CATEGORY109_ID, MMI_CATEGORY172_ID, -1};
static S32 mmi_mte_category_filter_202[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_203[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_204[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_205[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_206[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_207[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_208[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_209[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_210[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_211[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_212[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_213[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_214[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_215[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_216[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_219[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_220[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_221[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_232[] = {MMI_CATEGORY165_ID, -1};
static S32 mmi_mte_category_filter_233[] = {MMI_CATEGORY414_ID, MMI_CATEGORY14_LIST_ID, MMI_CATEGORY14_MATRIX_ID, MMI_CATEGORY14_CIRCULAR_ID, MMI_CATEGORY14_ROTATE_ID, -1};
static S32 mmi_mte_category_filter_234[] = {MMI_CATEGORY414_ID, MMI_CATEGORY14_LIST_ID, MMI_CATEGORY14_MATRIX_ID, MMI_CATEGORY14_CIRCULAR_ID, MMI_CATEGORY14_ROTATE_ID, -1};
static S32 mmi_mte_category_filter_305[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_306[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_308[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};
static S32 mmi_mte_category_filter_478[] = {MMI_CATEGORY33_ID, MMI_CATEGORY34_ID, -1};


/* theme component info structure */
static mmi_mte_theme_component_struct g_mmi_mte_theme_component_info[MMI_MTE_THEME_COMPONENT_NUM] =
{
    {"inputbox_filler", 0, 0, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {0, 0, "", {0}, NULL}},
#if !defined(UI_SCROLLBAR_STYLE_5) && !defined(UI_SCROLLBAR_STYLE_8) && !defined(UI_SCROLLBAR_STYLE_7)
    {"scrollbar_background_filler", 1, 1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {4, 0, "", {0}, mmi_mte_category_filter_1}},
#else
    {"scrollbar_background_filler", 1, 1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {4, 0, "", {0}, mmi_mte_category_filter_1}},
#endif
#if !defined(UI_SCROLLBAR_STYLE_5) && !defined(UI_SCROLLBAR_STYLE_8) && !defined(UI_SCROLLBAR_STYLE_7)
    {"scrollbar_indicator_filler", 2, 1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {8, 0, "", {0}, mmi_mte_category_filter_2}},
#else
    {"scrollbar_indicator_filler", 2, 1, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {8, 0, "", {0}, mmi_mte_category_filter_2}},
#endif
    {"title_filler", 3, 2, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {12, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(__MMI_MAINLCD_128X128__)
    {"list_background_filler", 4, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {16, 0, "", {0}, NULL}},
#else
    {"list_background_filler", 4, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {16, 0, "", {0}, NULL}},
#endif
    {"list_normal_item_filler", 5, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {20, 0, "", {0}, NULL}},
    {"list_selected_item_filler", 6, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {24, 0, "", {0}, NULL}},
    {"list_disabled_item_filler", 7, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {28, 0, "", {0}, NULL}},
    {"matrix_selected_item_filler", 8, 4, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {32, 0, "", {0}, NULL}},
    {"formatted_inputbox_normal_filler", 9, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {36, 0, "", {0}, NULL}},
    {"formatted_inputbox_selected_filler", 10, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {40, 0, "", {0}, NULL}},
    {"list_main_menu_normal_item_filler", 11, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {44, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_selected_item_filler", 12, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {48, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH, MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"list_main_menu_selected_item_filler", 12, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {48, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"list_main_menu_disabled_item_filler", 13, 6, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {52, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"matrix_main_menu_selected_item_filler", 14, 7, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {56, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_selected_item_filler", 14, 7, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {56, 0, "", {0}, NULL}},
#endif
    {"general_background_filler", 15, 8, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {60, 0, "", {0}, NULL}},
    {"popup_description_background_filler", 16, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {64, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if !defined(__GDI_MEMORY_PROFILE_2__)
    {"inline_list_normal_item_filler", 17, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {68, 0, "", {0}, NULL}},
#else
    {"inline_list_normal_item_filler", 17, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {68, 0, "", {0}, NULL}},
#endif
    {"inline_list_selected_item_filler", 18, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {72, 0, "", {0}, NULL}},
    {"inline_list_disabled_item_filler", 19, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {76, 0, "", {0}, NULL}},
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_edit_focussed_filler", 20, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {80, 0, "", {0}, NULL}},
#else
    {"inline_edit_focussed_filler", 20, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {80, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_edit_unfocussed_filler", 21, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {84, 0, "", {0}, NULL}},
#else
    {"inline_edit_unfocussed_filler", 21, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {84, 0, "", {0}, NULL}},
#endif
    {"inline_edit_noboundary_filler", 22, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {88, 0, "", {0}, NULL}},
#if !defined(__MMI_FTE_SUPPORT__)
    {"PIN_inputbox_background_filler", 23, 9, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {92, 0, "", {0}, NULL}},
#else
    {"PIN_inputbox_background_filler", 23, 9, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {92, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"PIN_screen_background_filler", 24, 9, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {96, 0, "", {0}, NULL}},
#else
    {"PIN_screen_background_filler", 24, 9, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {96, 0, "", {0}, NULL}},
#endif
    {"network_screen_background_filler", 25, 10, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {100, 0, "", {0}, NULL}},
#if !defined(WGUI_CATCALL_STYLE_2)
    {"CM_screen_background_filler", 26, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {104, 0, "", {0}, NULL}},
#else
    {"CM_screen_background_filler", 26, 11, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {104, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_COLOR_DIALLING_FONT__)
    {"dialer_inputbox_background_filler", 27, 12, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {108, 0, "", {0}, NULL}},
#else
    {"dialer_inputbox_background_filler", 27, 12, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {108, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_key_down_filler", 28, 13, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {112, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_down_filler", 28, 13, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {112, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__)
    {"small_list_menu_normal_filler", 29, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {116, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"small_list_menu_normal_filler", 29, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {116, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__)
    {"small_list_screen_border_filler", 30, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {120, 0, "", {0}, NULL}},
#else
    {"small_list_screen_border_filler", 30, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {120, 0, "", {0}, NULL}},
#endif
    {"lite_disp_scr_bg_color", 31, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {124, 0, "", {0}, NULL}},
    {"LSK_up_text_color", 32, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {128, 0, "", {0}, NULL}},
    {"LSK_down_text_color", 33, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {132, 0, "", {0}, NULL}},
    {"LSK_disabled_text_color", 34, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {136, 0, "", {0}, NULL}},
    {"RSK_up_text_color", 35, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {140, 0, "", {0}, NULL}},
    {"RSK_down_text_color", 36, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {144, 0, "", {0}, NULL}},
    {"RSK_disabled_text_color", 37, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {148, 0, "", {0}, NULL}},
    {"inputbox_normal_text_color", 38, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {152, 0, "", {0}, mmi_mte_category_filter_38}},
    {"inputbox_selected_text_color", 39, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {156, 0, "", {0}, NULL}},
    {"inputbox_selector_color", 40, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {160, 0, "", {0}, NULL}},
    {"inputbox_cursor_color", 41, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {164, 0, "", {0}, NULL}},
    {"title_text_color", 42, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {168, 0, "", {0}, mmi_mte_category_filter_42}},
    {"title_text_border_color", 43, 2, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {172, 0, "", {0}, mmi_mte_category_filter_43}},
    {"title_shortcut_text_color", 44, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {176, 0, "", {0}, NULL}},
    {"list_normal_text_color", 45, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {180, 0, "", {0}, NULL}},
    {"list_selected_text_color", 46, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {184, 0, "", {0}, NULL}},
    {"list_disabled_text_color", 47, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {188, 0, "", {0}, NULL}},
    {"matrix_normal_text_color", 48, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {192, 0, "", {0}, NULL}},
    {"matrix_selected_text_color", 49, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {196, 0, "", {0}, NULL}},
    {"matrix_disabled_text_color", 50, 4, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {200, 0, "", {0}, NULL}},
    {"formatted_inputbox_cursor_color", 51, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {204, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_normal_text_color", 52, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {208, 0, "", {0}, NULL}},
#else
    {"list_main_menu_normal_text_color", 52, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {208, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"list_main_menu_selected_text_color", 53, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {212, 0, "", {0}, NULL}},
#else
    {"list_main_menu_selected_text_color", 53, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {212, 0, "", {0}, NULL}},
#endif
    {"list_main_menu_disabled_text_color", 54, 6, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {216, 0, "", {0}, NULL}},
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"matrix_main_menu_normal_text_color", 55, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {220, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_normal_text_color", 55, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {220, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_MAINMENU_MATRIX_SUPPORT__) || defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)) && !defined(__MMI_MAINLCD_320X480__)
    {"matrix_main_menu_selected_text_color", 56, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {224, 0, "", {0}, NULL}},
#else
    {"matrix_main_menu_selected_text_color", 56, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {224, 0, "", {0}, NULL}},
#endif
    {"matrix_main_menu_disabled_text_color", 57, 7, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {228, 0, "", {0}, NULL}},
    {"popup_description_text_color", 58, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {232, 0, "", {0}, NULL}},
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"CM_screen_text_color", 59, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {236, 0, "", {0}, NULL}},
#else
    {"CM_screen_text_color", 59, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {236, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"datetime_bar_background_color", 60, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {240, 0, "", {0}, NULL}},
#else
    {"datetime_bar_background_color", 60, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {240, 0, "", {0}, NULL}},
#endif
    {"datetime_bar_duration_background_color", 61, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {244, 0, "", {0}, NULL}},
    {"datetime_bar_date_text_color", 62, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {248, 0, "", {0}, NULL}},
    {"datetime_bar_time_text_color", 63, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {252, 0, "", {0}, NULL}},
    {"datetime_bar_duration_text_color", 64, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {256, 0, "", {0}, NULL}},
    {"datetime_bar_AOC_text_color", 65, 11, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {260, 0, "", {0}, NULL}},
#if !defined(__MMI_FTE_SUPPORT__)
    {"information_bar_color", 66, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {264, 0, "", {0}, NULL}},
#else
    {"information_bar_color", 66, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {264, 0, "", {0}, NULL}},
#endif
    {"input_method_text_color", 67, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {268, 0, "", {0}, NULL}},
    {"remaining_length_text_color", 68, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {272, 0, "", {0}, NULL}},
    {"inline_edit_focussed_text_color", 69, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {276, 0, "", {0}, NULL}},
    {"inline_edit_unfocussed_text_color", 70, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {280, 0, "", {0}, NULL}},
    {"inline_edit_selected_text_color", 71, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {284, 0, "", {0}, NULL}},
    {"inline_edit_selector_color", 72, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {288, 0, "", {0}, NULL}},
    {"inline_edit_cursor_color", 73, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {292, 0, "", {0}, NULL}},
    {"inline_list_normal_text_color", 74, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {296, 0, "", {0}, NULL}},
    {"inline_list_selected_text_color", 75, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {300, 0, "", {0}, NULL}},
    {"inline_list_disabled_text_color", 76, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {304, 0, "", {0}, NULL}},
    {"PIN_inputbox_normal_text_color", 77, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {308, 0, "", {0}, NULL}},
    {"PIN_inputbox_selected_text_color", 78, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {312, 0, "", {0}, NULL}},
    {"PIN_inputbox_selector_color", 79, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {316, 0, "", {0}, NULL}},
    {"PIN_inputbox_cursor_color", 80, 9, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {320, 0, "", {0}, NULL}},
    {"dialer_inputbox_normal_text_color", 81, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {324, 0, "", {0}, NULL}},
    {"dialer_inputbox_selected_text_color", 82, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {328, 0, "", {0}, NULL}},
    {"dialer_inputbox_selector_color", 83, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {332, 0, "", {0}, NULL}},
    {"dialer_inputbox_cursor_color", 84, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {336, 0, "", {0}, NULL}},
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_key_down_text_color", 85, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {340, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_down_text_color", 85, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {340, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_key_up_text_color", 86, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {344, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_up_text_color", 86, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {344, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_dead_key_down_text_color", 87, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {348, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_dead_key_down_text_color", 87, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {348, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_dead_key_up_text_color", 88, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {352, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_dead_key_up_text_color", 88, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {352, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_disp_area_text_color", 89, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {356, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_disp_area_text_color", 89, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {356, 0, "", {0}, NULL}},
#endif
    {"idle_scr_date_color", 90, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {360, 0, "", {0}, NULL}},
#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) || !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
    {"idle_scr_time_color", 91, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {364, 0, "", {0}, NULL}},
#else
    {"idle_scr_time_color", 91, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {364, 0, "", {0}, NULL}},
#endif
    {"idle_scr_date_border_color", 92, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {368, 0, "", {0}, NULL}},
#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) || !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
    {"idle_scr_time_border_color", 93, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {372, 0, "", {0}, NULL}},
#else
    {"idle_scr_time_border_color", 93, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {372, 0, "", {0}, NULL}},
#endif
    {"idle_scr_network_name_color", 94, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {376, 0, "", {0}, NULL}},
    {"idle_scr_network_name_border_color", 95, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {380, 0, "", {0}, NULL}},
    {"idle_scr_network_status_color", 96, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {384, 0, "", {0}, NULL}},
    {"idle_scr_network_status_border_color", 97, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {388, 0, "", {0}, NULL}},
    {"idle_scr_network_extra_color", 98, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {392, 0, "", {0}, NULL}},
    {"idle_scr_network_extra_border_color", 99, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {396, 0, "", {0}, NULL}},
    {"scrollbar_size", 100, 1, MMI_MTE_THEME_DATA_TYPE_SYMBOL, NULL, 0, 0, 0, 0, 0, {400, 0, "UI_SCROLLBAR_WIDTH", {0}, NULL}},
    {"bg_opacity_full", 101, 16, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {404, 0, "", {0}, NULL}},
    {"bg_opacity_high", 102, 16, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {408, 0, "", {0}, NULL}},
    {"bg_opacity_medium", 103, 16, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 255, 0, {412, 0, "", {0}, NULL}},
    {"bg_opacity_low", 104, 16, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 255, 0, {416, 0, "", {0}, NULL}},
    {"menuitem_single_line_highlight_filler", 105, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {420, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_two_line_highlight_filler", 106, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {424, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MENUITEM_HEIGHT*2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_multirow_highlight_filler", 107, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {428, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MULTIROW_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"menuitem_thick_highlight_filler", 108, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {432, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 30}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 39}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 39}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 39}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 60}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 60}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 76}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 63}, }, NULL}},
    {"menuitem_thick_with_tab_highlight_filler", 109, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {436, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 33}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 33}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 35}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 55}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 50}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 47}, {LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, 58}, }, NULL}},
    {"symbol_picker_highlight_filler", 110, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {440, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {16, 16}, {16, 16}, {18, 18}, {22, 22}, {22, 22}, {22, 22}, {22, 22}, }, NULL}},
    {"matrix_highlight_filler", 111, 17, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {444, 0, "", {0}, NULL}},
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"main_menu_bkg_filler", 112, 16, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {448, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"main_menu_bkg_filler", 112, 16, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {448, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {"sub_menu_bkg_filler", 113, 16, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {452, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"sub_menu_bkg_filler", 113, 16, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {452, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"idle_bkg_filler", 114, 16, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {456, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"popup_text_color", 115, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {460, 0, "", {0}, mmi_mte_category_filter_115}},
    {"idle_scr_weekday_color", 116, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {464, 0, "", {0}, NULL}},
    {"idle_scr_weekday_border_color", 117, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {468, 0, "", {0}, NULL}},
    {"date_text_color", 118, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {472, 0, "", {0}, NULL}},
    {"date_text_border_color", 119, 19, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {476, 0, "", {0}, NULL}},
    {"time_text_color", 120, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {480, 0, "", {0}, NULL}},
    {"time_text_border_color", 121, 19, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {484, 0, "", {0}, NULL}},
#if defined(__MMI_ANALOG_CLOCK__)
    {"analog_hand_hour_color", 122, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {488, 0, "", {0}, NULL}},
#else
    {"analog_hand_hour_color", 122, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {488, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ANALOG_CLOCK__)
    {"analog_hand_min_color", 123, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {492, 0, "", {0}, NULL}},
#else
    {"analog_hand_min_color", 123, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {492, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ANALOG_CLOCK__) && (!defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) || (defined(__MMI_SUBLCD_SHOW_ANALOG_CLOCK__) && defined(__MMI_SUBLCD_COLOR__)))
    {"analog_axis_color", 124, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {496, 0, "", {0}, NULL}},
#else
    {"analog_axis_color", 124, 19, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {496, 0, "", {0}, NULL}},
#endif
    {"softkey_text_border_color", 125, 15, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {500, 0, "", {0}, NULL}},
    {"softkey_bar_bkg_filler", 126, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {504, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, MMI_BUTTON_BAR_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_filler", 127, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {508, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_HORIZONTAL_TAB_BAR_WIDTH, MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_title_filler", 127, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {508, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_text_color", 128, 20, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {512, 0, "", {0}, NULL}},
#else
    {"tab_title_text_color", 128, 20, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {512, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_text_border_color", 129, 20, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {516, 0, "", {0}, NULL}},
#else
    {"tab_title_text_border_color", 129, 20, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {516, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_title_shortcut_text_color", 130, 20, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {520, 0, "", {0}, NULL}},
#else
    {"tab_title_shortcut_text_color", 130, 20, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {520, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_title_text_color", 131, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {524, 0, "", {0}, NULL}},
#else
    {"calendar_title_text_color", 131, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {524, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_horizontal_text_color", 132, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {528, 0, "", {0}, NULL}},
#else
    {"calendar_horizontal_text_color", 132, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {528, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_horizontal_border_color", 133, 21, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {532, 0, "", {0}, NULL}},
#else
    {"calendar_horizontal_border_color", 133, 21, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {532, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_vertical_text_color", 134, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {536, 0, "", {0}, NULL}},
#else
    {"calendar_vertical_text_color", 134, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {536, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_horizontal_string_text_color", 135, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {540, 0, "", {0}, NULL}},
#else
    {"calendar_horizontal_string_text_color", 135, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {540, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_one_task_color", 136, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {544, 0, "", {0}, NULL}},
#else
    {"calendar_one_task_color", 136, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {544, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_multi_task_color", 137, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {548, 0, "", {0}, NULL}},
#else
    {"calendar_multi_task_color", 137, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {548, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MENSTRUAL__)
    {"calendar_menstrual_color", 138, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {552, 0, "", {0}, NULL}},
#else
    {"calendar_menstrual_color", 138, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {552, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MENSTRUAL__)
    {"calendar_PP_color", 139, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {556, 0, "", {0}, NULL}},
#else
    {"calendar_PP_color", 139, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {556, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MENSTRUAL__)
    {"calendar_danger_color", 140, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {560, 0, "", {0}, NULL}},
#else
    {"calendar_danger_color", 140, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {560, 0, "", {0}, NULL}},
#endif
    {"calendar_invalid_color", 141, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {564, 0, "", {0}, NULL}},
#if defined(__MMI_CALENDAR__)
    {"calendar_valid_text_color", 142, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {568, 0, "", {0}, NULL}},
#else
    {"calendar_valid_text_color", 142, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {568, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_invalid_text_color", 143, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {572, 0, "", {0}, NULL}},
#else
    {"calendar_invalid_text_color", 143, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {572, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_highlight_color", 144, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {576, 0, "", {0}, NULL}},
#else
    {"calendar_highlight_color", 144, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {576, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CLNDR_EVENT_INFO__) && defined(__MMI_CALENDAR__)
    {"calendar_infobox_bg_color", 145, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {580, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_bg_color", 145, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {580, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CLNDR_EVENT_INFO__) && defined(__MMI_CALENDAR__)
    {"calendar_infobox_entry_bg_color", 146, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {584, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_entry_bg_color", 146, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {584, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CLNDR_EVENT_INFO__) && defined(__MMI_CALENDAR__)
    {"calendar_infobox_text_color", 147, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {588, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_text_color", 147, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {588, 0, "", {0}, NULL}},
#endif
    {"status_icon_bar_filler", 148, 22, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {592, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_BMP << 16), "", {{LCD_WIDTH, MMI_STATUS_BAR_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_filler", 149, 2, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {596, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, MMI_THICK_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"thick_title_filler", 149, 2, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {596, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_text_color", 150, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {600, 0, "", {0}, NULL}},
#else
    {"thick_title_text_color", 150, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {600, 0, "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_text_border_color", 151, 2, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {604, 0, "", {0}, NULL}},
#else
    {"thick_title_text_border_color", 151, 2, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {604, 0, "", {0}, NULL}},
#endif
#if defined(GUI_MAINMENU_USE_THICK_TITLE) || defined(GUI_SUBMENU_USE_THICK_TITLE) || defined(GUI_COMMON_USE_THICK_TITLE) || defined(GUI_DEFAULT_USE_THICK_TITLE)
    {"thick_title_shortcut_text_color", 152, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {608, 0, "", {0}, NULL}},
#else
    {"thick_title_shortcut_text_color", 152, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {608, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SCREEN_ROTATE__)&&  !defined(__MMI_MAINLCD_320X240__)
    {"rotated_bkg_filler", 153, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {612, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_HEIGHT, LCD_WIDTH}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_bkg_filler", 153, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {612, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)&& defined(MMI_ROTATED_TITLE_WIDTH) && defined(MMI_ROTATED_TITLE_HEIGHT)
    {"rotated_title_filler", 154, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {616, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_ROTATED_TITLE_WIDTH, MMI_ROTATED_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_title_filler", 154, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {616, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__)
    {"small_screen_title_filler", 155, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {620, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{(UI_DEVICE_WIDTH-2*MMI_SMALL_SCREEN_X_OFFSET), MMI_TITLE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"small_screen_title_filler", 155, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {620, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_normal_tab_filler", 156, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {624, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH, MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_normal_tab_filler", 156, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {624, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_highlight_tab_filler", 157, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {628, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 19}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 19}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 19}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 27}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 35}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 33}, {MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH, 37}, }, NULL}},
#else
    {"tab_highlight_tab_filler", 157, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {628, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_blink_tab_filler", 158, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {632, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH, MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_blink_tab_filler", 158, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {632, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"main_menu_bidegree_tab_highlight_filler", 159, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {636, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {40, 44}, {65, 65}, {36, 53}, {45, 92}, {50, 106}, }, NULL}},
#else
    {"main_menu_bidegree_tab_highlight_filler", 159, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {636, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
    {"matrix_main_menu_highlight_image", 160, 7, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH, MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"matrix_main_menu_highlight_image", 160, 7, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    {"main_menu_bidegree_tab_background_filler", 161, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {40, 44}, {65, 65}, {36, 53}, {45, 92}, {50, 106}, }, NULL}},
#else
    {"main_menu_bidegree_tab_background_filler", 161, 24, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"list_separator_color", 162, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {648, 0, "", {0}, NULL}},
    {"cascade_menu_separator_color", 163, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {652, 0, "", {0}, NULL}},
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_normal_text_color", 164, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {656, 0, "", {0}, NULL}},
#else
    {"cascade_menu_normal_text_color", 164, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {656, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_selected_text_color", 165, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {660, 0, "", {0}, NULL}},
#else
    {"cascade_menu_selected_text_color", 165, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {660, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_disabled_text_color", 166, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {664, 0, "", {0}, NULL}},
#else
    {"cascade_menu_disabled_text_color", 166, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {664, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_border_color", 167, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {668, 0, "", {0}, NULL}},
#else
    {"cascade_menu_border_color", 167, 25, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {668, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_background_filler", 168, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {672, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"cascade_menu_background_filler", 168, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {672, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_highlight_filler", 169, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {676, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"cascade_menu_highlight_filler", 169, 25, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {676, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_left_arrow_image", 170, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {680, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_left_arrow_image", 170, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {680, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_right_arrow_image", 171, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {684, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_right_arrow_image", 171, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {684, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
    {"list_check_selected_image", 172, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {688, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {18, 18}, {26, 26}, {26, 26}, }, mmi_mte_category_filter_172}},
    {"list_check_unselected_image", 173, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {692, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {18, 18}, {26, 26}, {26, 26}, }, mmi_mte_category_filter_173}},
    {"list_radio_selected_image", 174, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {696, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {18, 18}, {26, 26}, {26, 26}, }, mmi_mte_category_filter_174}},
    {"list_radio_unselected_image", 175, 3, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {700, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {26, 26}, {18, 18}, {26, 26}, {26, 26}, }, mmi_mte_category_filter_175}},
    {"inline_edit_left_arrow_image", 176, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {704, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{INLINE_FTE_SELECTOR_ARROW_WIDTH, INLINE_FTE_SELECTOR_ARROW_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"inline_edit_right_arrow_image", 177, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {708, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{INLINE_FTE_SELECTOR_ARROW_WIDTH, INLINE_FTE_SELECTOR_ARROW_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"inputbox_base_line_color", 178, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {712, 0, "", {0}, NULL}},
    {"inputbox_ems_cr_base_line_color", 179, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {716, 0, "", {0}, NULL}},
#if !defined(__MMI_COLOR_DIALLING_FONT__)
    {"dialer_inputbox_text_color", 180, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {720, 0, "", {0}, NULL}},
#else
    {"dialer_inputbox_text_color", 180, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {720, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_COLOR_DIALLING_FONT__)
    {"dialer_inputbox_text_border_color", 181, 12, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {724, 0, "", {0}, NULL}},
#else
    {"dialer_inputbox_text_border_color", 181, 12, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {724, 0, "", {0}, NULL}},
#endif
    {"softkey_lsk_down_filler", 182, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {728, 0, "", {0}, NULL}},
    {"softkey_lsk_up_filler", 183, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {732, 0, "", {0}, NULL}},
    {"softkey_rsk_down_filler", 184, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {736, 0, "", {0}, NULL}},
    {"softkey_rsk_up_filler", 185, 15, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {740, 0, "", {0}, NULL}},
#if defined(__MMI_CALENDAR__) && !defined(__MMI_FTE_SUPPORT__)
    {"calendar_title_bg_color", 186, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {744, 0, "", {0}, NULL}},
#else
    {"calendar_title_bg_color", 186, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {744, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__) && !defined(__MMI_FTE_SUPPORT__)
    {"calendar_horizontal_string_bg_color", 187, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {748, 0, "", {0}, NULL}},
#else
    {"calendar_horizontal_string_bg_color", 187, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {748, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_vertical_select_bg_color", 188, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {752, 0, "", {0}, NULL}},
#else
    {"calendar_vertical_select_bg_color", 188, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {752, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_cell_array_bg_color", 189, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {756, 0, "", {0}, NULL}},
#else
    {"calendar_cell_array_bg_color", 189, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {756, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_frame_line_color", 190, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {760, 0, "", {0}, NULL}},
#else
    {"calendar_frame_line_color", 190, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {760, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_cell_line_color", 191, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {764, 0, "", {0}, NULL}},
#else
    {"calendar_cell_line_color", 191, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {764, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_cell_current_text_color", 192, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {768, 0, "", {0}, NULL}},
#else
    {"calendar_cell_current_text_color", 192, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {768, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_INDICAL__)) && defined(__MMI_CALENDAR__)
    {"calendar_popup_text_color", 193, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {772, 0, "", {0}, NULL}},
#else
    {"calendar_popup_text_color", 193, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {772, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_INDICAL__)) && defined(__MMI_CALENDAR__)
    {"calendar_popup_bg_color", 194, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {776, 0, "", {0}, NULL}},
#else
    {"calendar_popup_bg_color", 194, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {776, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_INDICAL__)) && defined(__MMI_CALENDAR__)
    {"calendar_popup_border_color", 195, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {780, 0, "", {0}, NULL}},
#else
    {"calendar_popup_border_color", 195, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {780, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CLNDR_EVENT_INFO__) && defined(__MMI_CALENDAR__)
    {"calendar_infobox_bg_alpha", 196, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {784, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_bg_alpha", 196, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {784, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__) && !defined(__MMI_FTE_SUPPORT__)
    {"calendar_title_bg_alpha", 197, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {788, 0, "", {0}, NULL}},
#else
    {"calendar_title_bg_alpha", 197, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {788, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__) && !defined(__MMI_FTE_SUPPORT__)
    {"calendar_horizontal_string_bg_alpha", 198, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {792, 0, "", {0}, NULL}},
#else
    {"calendar_horizontal_string_bg_alpha", 198, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {792, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_vertical_select_bg_alpha", 199, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {796, 0, "", {0}, NULL}},
#else
    {"calendar_vertical_select_bg_alpha", 199, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {796, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_cell_array_bg_alpha", 200, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {800, 0, "", {0}, NULL}},
#else
    {"calendar_cell_array_bg_alpha", 200, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {800, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_frame_line_alpha", 201, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {804, 0, "", {0}, NULL}},
#else
    {"calendar_frame_line_alpha", 201, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {804, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    {"calendar_horizontal_string_text_for_idle_color", 202, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {808, 0, "", {0}, mmi_mte_category_filter_202}},
#else
    {"calendar_horizontal_string_text_for_idle_color", 202, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {808, 0, "", {0}, mmi_mte_category_filter_202}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_horizontal_string_bg_for_idle_color", 203, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {812, 0, "", {0}, mmi_mte_category_filter_203}},
#else
    {"calendar_horizontal_string_bg_for_idle_color", 203, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {812, 0, "", {0}, mmi_mte_category_filter_203}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    {"calendar_cell_valid_text_for_idle_color", 204, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {816, 0, "", {0}, mmi_mte_category_filter_204}},
#else
    {"calendar_cell_valid_text_for_idle_color", 204, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {816, 0, "", {0}, mmi_mte_category_filter_204}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    {"calendar_cell_invalid_text_for_idle_color", 205, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {820, 0, "", {0}, mmi_mte_category_filter_205}},
#else
    {"calendar_cell_invalid_text_for_idle_color", 205, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {820, 0, "", {0}, mmi_mte_category_filter_205}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_array_bg_for_idle_color", 206, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {824, 0, "", {0}, mmi_mte_category_filter_206}},
#else
    {"calendar_cell_array_bg_for_idle_color", 206, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {824, 0, "", {0}, mmi_mte_category_filter_206}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    {"calendar_cell_current_text_for_idle_color", 207, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {828, 0, "", {0}, mmi_mte_category_filter_207}},
#else
    {"calendar_cell_current_text_for_idle_color", 207, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {828, 0, "", {0}, mmi_mte_category_filter_207}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_highlight_for_idle_color", 208, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {832, 0, "", {0}, mmi_mte_category_filter_208}},
#else
    {"calendar_cell_highlight_for_idle_color", 208, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {832, 0, "", {0}, mmi_mte_category_filter_208}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_frame_line_for_idle_color", 209, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {836, 0, "", {0}, mmi_mte_category_filter_209}},
#else
    {"calendar_frame_line_for_idle_color", 209, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {836, 0, "", {0}, mmi_mte_category_filter_209}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_line_for_idle_color", 210, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {840, 0, "", {0}, mmi_mte_category_filter_210}},
#else
    {"calendar_cell_line_for_idle_color", 210, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {840, 0, "", {0}, mmi_mte_category_filter_210}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_horizontal_string_bg_for_idle_alpha", 211, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {844, 0, "", {0}, mmi_mte_category_filter_211}},
#else
    {"calendar_horizontal_string_bg_for_idle_alpha", 211, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {844, 0, "", {0}, mmi_mte_category_filter_211}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_array_bg_for_idle_alpha", 212, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {848, 0, "", {0}, mmi_mte_category_filter_212}},
#else
    {"calendar_cell_array_bg_for_idle_alpha", 212, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {848, 0, "", {0}, mmi_mte_category_filter_212}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_current_bg_for_idle_alpha", 213, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {852, 0, "", {0}, mmi_mte_category_filter_213}},
#else
    {"calendar_cell_current_bg_for_idle_alpha", 213, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {852, 0, "", {0}, mmi_mte_category_filter_213}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_highlight_for_idle_alpha", 214, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {856, 0, "", {0}, mmi_mte_category_filter_214}},
#else
    {"calendar_cell_highlight_for_idle_alpha", 214, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {856, 0, "", {0}, mmi_mte_category_filter_214}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_frame_line_for_idle_alpha", 215, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {860, 0, "", {0}, mmi_mte_category_filter_215}},
#else
    {"calendar_frame_line_for_idle_alpha", 215, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {860, 0, "", {0}, mmi_mte_category_filter_215}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X240__)
    {"calendar_cell_line_for_idle_alpha", 216, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {864, 0, "", {0}, mmi_mte_category_filter_216}},
#else
    {"calendar_cell_line_for_idle_alpha", 216, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {864, 0, "", {0}, mmi_mte_category_filter_216}},
#endif
    {"arrow_indication_color", 217, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {868, 0, "", {0}, NULL}},
    {"arrow_indication_border_color", 218, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {872, 0, "", {0}, NULL}},
#if defined(__MMI_OP01_DCD__)
    {"dcd_idle_bkg_filler", 219, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {876, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {176, 52}, {240, 74}, {0, 0}, {240, 74}, {0, 0}, }, mmi_mte_category_filter_219}},
#else
    {"dcd_idle_bkg_filler", 219, 26, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {876, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, mmi_mte_category_filter_219}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_idle_read_text_color", 220, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {880, 0, "", {0}, mmi_mte_category_filter_220}},
#else
    {"dcd_idle_read_text_color", 220, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {880, 0, "", {0}, mmi_mte_category_filter_220}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_idle_unread_text_color", 221, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {884, 0, "", {0}, mmi_mte_category_filter_221}},
#else
    {"dcd_idle_unread_text_color", 221, 26, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {884, 0, "", {0}, mmi_mte_category_filter_221}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_channel_list_highlight_filler", 222, 27, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {888, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {0, 0}, {0, 0}, {168, 52}, {227, 60}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"dcd_channel_list_highlight_filler", 222, 27, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {888, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_story_text_color", 223, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {892, 0, "", {0}, NULL}},
#else
    {"dcd_story_text_color", 223, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {892, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_story_visited_text_color", 224, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {896, 0, "", {0}, NULL}},
#else
    {"dcd_story_visited_text_color", 224, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {896, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_story_unvisited_text_color", 225, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {900, 0, "", {0}, NULL}},
#else
    {"dcd_story_unvisited_text_color", 225, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {900, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_OP01_DCD__)
    {"dcd_story_highlight_bar_color", 226, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {904, 0, "", {0}, NULL}},
#else
    {"dcd_story_highlight_bar_color", 226, 28, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {904, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#else
    {"idle_scr_sim2_network_name_color", 227, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {908, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#else
    {"idle_scr_sim2_network_name_border_color", 228, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {912, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#else
    {"idle_scr_sim2_network_status_color", 229, 10, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {916, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#else
    {"idle_scr_sim2_network_status_border_color", 230, 10, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 0, 0, 0, 0, 0, {920, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
    {"popup_full_height_screen_bg_filler", 231, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {924, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{0, 0}, {108, 101}, {108, 132}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"popup_full_height_screen_bg_filler", 231, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {924, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
    {"popup_content_text_color", 232, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {928, 0, "", {0}, mmi_mte_category_filter_232}},
    {"main_menu_title_color", 233, 2, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {932, 0, "", {0}, mmi_mte_category_filter_233}},
    {"main_menu_title_border_color", 234, 2, MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR, NULL, 1, 0, 0, 0, 0, {936, 0, "", {0}, mmi_mte_category_filter_234}},
#if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) && defined(__MMI_CSTAR_SM_CHINESE__) && !defined(__MMI_FTE_SUPPORT__)
    {"ime_underline_color", 235, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {940, 0, "", {0}, NULL}},
#else
    {"ime_underline_color", 235, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {940, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) && defined(__MMI_CSTAR_SM_CHINESE__) && !defined(__MMI_FTE_SUPPORT__)
    {"ime_indicator_color", 236, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {944, 0, "", {0}, NULL}},
#else
    {"ime_indicator_color", 236, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {944, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_focused_background_filler", 237, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {948, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {128, 20}, {128, 20}, {176, 20}, {240, 50}, {320, 50}, {240, 50}, {320, 50}, }, NULL}},
#else
    {"ime_focused_background_filler", 237, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {948, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_background_filler", 238, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {952, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {128, 20}, {128, 20}, {176, 20}, {240, 50}, {320, 50}, {240, 50}, {320, 50}, }, NULL}},
#else
    {"ime_background_filler", 238, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {952, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_focused_border_color", 239, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {956, 0, "", {0}, NULL}},
#else
    {"ime_focused_border_color", 239, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {956, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_border_color", 240, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {960, 0, "", {0}, NULL}},
#else
    {"ime_border_color", 240, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {960, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_separator_width", 241, 29, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 2, 0, {964, 0, "", {0}, NULL}},
#else
    {"ime_separator_width", 241, 29, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 2, 0, {964, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_separator_normal_color", 242, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {968, 0, "", {0}, NULL}},
#else
    {"ime_separator_normal_color", 242, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {968, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_focused_separator_color", 243, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {972, 0, "", {0}, NULL}},
#else
    {"ime_focused_separator_color", 243, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {972, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
    {"ime_text_space", 244, 29, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 1, 4, 0, {976, 0, "", {0}, NULL}},
#else
    {"ime_text_space", 244, 29, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 1, 4, 0, {976, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__))&& !defined(__MMI_FTE_SUPPORT__)
    {"ime_label_color", 245, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {980, 0, "", {0}, NULL}},
#else
    {"ime_label_color", 245, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {980, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__) && !defined(__MMI_FTE_SUPPORT__)
    {"ime_cursor_color", 246, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {984, 0, "", {0}, NULL}},
#else
    {"ime_cursor_color", 246, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {984, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_arrow_disable_color", 247, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {988, 0, "", {0}, NULL}},
#else
    {"ime_arrow_disable_color", 247, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {988, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_arrow_down_color", 248, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {992, 0, "", {0}, NULL}},
#else
    {"ime_arrow_down_color", 248, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {992, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_arrow_up_color", 249, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {996, 0, "", {0}, NULL}},
#else
    {"ime_arrow_up_color", 249, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {996, 0, "", {0}, NULL}},
#endif
    {"ime_cand_text_color", 250, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1000, 0, "", {0}, NULL}},
    {"ime_cand_highlighted_text_color", 251, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1004, 0, "", {0}, NULL}},
#if !defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_highlight_color", 252, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1008, 0, "", {0}, NULL}},
#else
    {"ime_cand_highlight_color", 252, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1008, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
    {"ime_comp_text_color", 253, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1012, 0, "", {0}, NULL}},
#else
    {"ime_comp_text_color", 253, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1012, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
    {"ime_comp_highlighted_text_color", 254, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1016, 0, "", {0}, NULL}},
#else
    {"ime_comp_highlighted_text_color", 254, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1016, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_ZI_TR_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)) && !defined(__MMI_FTE_SUPPORT__)
    {"ime_comp_highlight_color", 255, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1020, 0, "", {0}, NULL}},
#else
    {"ime_comp_highlight_color", 255, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1020, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__)&& !defined(__MMI_FTE_SUPPORT__)
    {"ime_input_text_color", 256, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1024, 0, "", {0}, NULL}},
#else
    {"ime_input_text_color", 256, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1024, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__)&& !defined(__MMI_FTE_SUPPORT__)
    {"ime_input_highlighted_text_color", 257, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1028, 0, "", {0}, NULL}},
#else
    {"ime_input_highlighted_text_color", 257, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1028, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CSTAR__)&& !defined(__MMI_FTE_SUPPORT__)
    {"ime_input_highlight_color", 258, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1032, 0, "", {0}, NULL}},
#else
    {"ime_input_highlight_color", 258, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1032, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ZI_STROKE_INPUT__)
    {"ime_stroke_color", 259, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1036, 0, "", {0}, NULL}},
#else
    {"ime_stroke_color", 259, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1036, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ZI_STROKE_INPUT__)
    {"ime_highlighted_stroke_color", 260, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1040, 0, "", {0}, NULL}},
#else
    {"ime_highlighted_stroke_color", 260, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1040, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_ZI_STROKE_INPUT__) && !defined(__MMI_FTE_SUPPORT__)
    {"ime_stroke_highlight_color", 261, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1044, 0, "", {0}, NULL}},
#else
    {"ime_stroke_highlight_color", 261, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1044, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
    {"tab_special_filler", 262, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1048, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH, MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_special_filler", 262, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1048, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"mini_indicator_bg_color", 263, 30, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1052, 0, "", {0}, NULL}},
    {"mini_indicator_normal_color", 264, 30, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1056, 0, "", {0}, NULL}},
    {"mini_indicator_tab_color", 265, 30, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1060, 0, "", {0}, NULL}},
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__)
    {"media_player_content_text_color", 266, 31, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1064, 0, "", {0}, NULL}},
#else
    {"media_player_content_text_color", 266, 31, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1064, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__)
    {"media_player_content_text_border_color", 267, 31, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1068, 0, "", {0}, NULL}},
#else
    {"media_player_content_text_border_color", 267, 31, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1068, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"two_line_first_line_text_color", 268, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1072, 0, "", {0}, NULL}},
#else
    {"two_line_first_line_text_color", 268, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1072, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"two_line_first_line_highlight_text_color", 269, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1076, 0, "", {0}, NULL}},
#else
    {"two_line_first_line_highlight_text_color", 269, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1076, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
    {"two_line_second_line_text_color", 270, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1080, 0, "", {0}, NULL}},
#else
    {"two_line_second_line_text_color", 270, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1080, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
    {"two_line_second_line_highlight_text_color", 271, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1084, 0, "", {0}, NULL}},
#else
    {"two_line_second_line_highlight_text_color", 271, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1084, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"two_line_second_line_selector_filler", 272, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1088, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - UI_SCROLLBAR_WIDTH, MMI_MENUITEM_HEIGHT*2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"two_line_second_line_selector_filler", 272, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL | MMI_MTE_FILLER_ALLOW_BORDER, {1088, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"two_line_second_line_selector_text_color", 273, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1092, 0, "", {0}, NULL}},
#else
    {"two_line_second_line_selector_text_color", 273, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1092, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_first_line_text_color", 274, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1096, 0, "", {0}, NULL}},
#else
    {"multirow_first_line_text_color", 274, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1096, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_first_line_highlight_text_color", 275, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1100, 0, "", {0}, NULL}},
#else
    {"multirow_first_line_highlight_text_color", 275, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1100, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_second_line_text_color", 276, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1104, 0, "", {0}, NULL}},
#else
    {"multirow_second_line_text_color", 276, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1104, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_second_line_highlight_text_color", 277, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1108, 0, "", {0}, NULL}},
#else
    {"multirow_second_line_highlight_text_color", 277, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1108, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_third_line_text_color", 278, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1112, 0, "", {0}, NULL}},
#else
    {"multirow_third_line_text_color", 278, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1112, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"multirow_third_line_highlight_text_color", 279, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1116, 0, "", {0}, NULL}},
#else
    {"multirow_third_line_highlight_text_color", 279, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1116, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
    {"list_grid_line_color", 280, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1120, 0, "", {0}, NULL}},
#else
    {"list_grid_line_color", 280, 3, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1120, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
    {"list_grid_line_alpha", 281, 3, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {1124, 0, "", {0}, NULL}},
#else
    {"list_grid_line_alpha", 281, 3, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1124, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"menuitem_single_line_highlight_without_scroll_filler", 282, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1128, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{(LCD_WIDTH-4), MMI_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"menuitem_single_line_highlight_without_scroll_filler", 282, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1128, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"menuitem_two_line_highlight_without_scroll_filler", 283, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1132, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{(LCD_WIDTH-4), MMI_MENUITEM_HEIGHT*2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"menuitem_two_line_highlight_without_scroll_filler", 283, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1132, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"menuitem_multirow_highlight_without_scroll_filler", 284, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1136, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{(LCD_WIDTH-4), MMI_MULTIROW_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"menuitem_multirow_highlight_without_scroll_filler", 284, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1136, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"menuitem_thick_highlight_without_scroll_filler", 285, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1140, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{(LCD_WIDTH-4), 30}, {(LCD_WIDTH-4), 30}, {(LCD_WIDTH-4), 30}, {(LCD_WIDTH-4), 39}, {(LCD_WIDTH-4), 60}, {(LCD_WIDTH-4), 60}, {(LCD_WIDTH-4), 76}, {(LCD_WIDTH-4), 63}, }, NULL}},
#else
    {"menuitem_thick_highlight_without_scroll_filler", 285, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1140, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"menuitem_thick_with_tab_highlight_without_scroll_filler", 286, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1144, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{(LCD_WIDTH-4), 55}, {(LCD_WIDTH-4), 55}, {(LCD_WIDTH-4), 33}, {(LCD_WIDTH-4), 35}, {(LCD_WIDTH-4), 55}, {(LCD_WIDTH-4), 50}, {(LCD_WIDTH-4), 47}, {(LCD_WIDTH-4), 58}, }, NULL}},
#else
    {"menuitem_thick_with_tab_highlight_without_scroll_filler", 286, 3, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1144, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"dialing_screen_bg_image", 287, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1148, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {320, 480}, }, NULL}},
#else
    {"dialing_screen_bg_image", 287, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1148, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"dialing_screen_skey_up_image", 288, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1152, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {96, 60}, }, NULL}},
#else
    {"dialing_screen_skey_up_image", 288, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1152, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"dialing_screen_skey_down_image", 289, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1156, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {96, 60}, }, NULL}},
#else
    {"dialing_screen_skey_down_image", 289, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1156, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    {"dialing_screen_lkey_up_image", 290, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1160, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {MMI_DIALING_FUNC_KEY_WIDTH, MMI_DIALING_FUNC_KEY_HEIGHT}, }, NULL}},
#else
    {"dialing_screen_lkey_up_image", 290, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1160, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    {"dialing_screen_lkey_down_image", 291, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1164, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {MMI_DIALING_FUNC_KEY_WIDTH, MMI_DIALING_FUNC_KEY_HEIGHT}, }, NULL}},
#else
    {"dialing_screen_lkey_down_image", 291, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1164, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"voip_dialer_editor_text_color", 292, 12, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1168, 0, "", {0}, NULL}},
    {"header_information_text_color", 293, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1172, 0, "", {0}, NULL}},
#if defined(__MMI_MAINLCD_320X480__)
    {"CM_screen_popup_bkg_image", 294, 11, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1176, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {290, 290}, }, NULL}},
#else
    {"CM_screen_popup_bkg_image", 294, 11, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1176, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_lsk_normal_up_filler", 295, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1180, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {105, 45}, }, NULL}},
#else
    {"popup_embedded_lsk_normal_up_filler", 295, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1180, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_lsk_normal_down_filler", 296, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1184, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {105, 45}, }, NULL}},
#else
    {"popup_embedded_lsk_normal_down_filler", 296, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1184, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_rsk_normal_up_filler", 297, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1188, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {105, 45}, }, NULL}},
#else
    {"popup_embedded_rsk_normal_up_filler", 297, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1188, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_rsk_normal_down_filler", 298, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1192, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {105, 45}, }, NULL}},
#else
    {"popup_embedded_rsk_normal_down_filler", 298, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1192, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_softkey_text_color", 299, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1196, 0, "", {0}, NULL}},
#else
    {"popup_embedded_softkey_text_color", 299, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1196, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_MAINLCD_320X480__)
    {"popup_embedded_softkey_text_border_color", 300, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1200, 0, "", {0}, NULL}},
#else
    {"popup_embedded_softkey_text_border_color", 300, 18, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1200, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_MAINLCD_320X480__)&& !defined(__MMI_MAINLCD_128X128__)
    {"popup_softkey_bar_filler", 301, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1204, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, MMI_BUTTON_BAR_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"popup_softkey_bar_filler", 301, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1204, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__) && defined(__MMI_FTE_SUPPORT__)
    {"small_list_menu_highlight_filler", 302, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1208, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {125, 22}, {173, 30}, {219, 29}, {173, 38}, {233, 47}, }, NULL}},
#else
    {"small_list_menu_highlight_filler", 302, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1208, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_PNG_SEQUENCE | MMI_MTE_IMAGE_BMP_SEQUENCE | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__)
    {"small_list_menu_highlight_text_color", 303, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1212, 0, "", {0}, NULL}},
#else
    {"small_list_menu_highlight_text_color", 303, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1212, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__)
    {"small_list_menu_text_color", 304, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1216, 0, "", {0}, NULL}},
#else
    {"small_list_menu_text_color", 304, 14, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1216, 0, "", {0}, NULL}},
#endif
    {"calendar_idle_large_current_day_text_color", 305, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1220, 0, "", {0}, mmi_mte_category_filter_305}},
    {"calendar_idle_large_current_date_text_color", 306, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1224, 0, "", {0}, mmi_mte_category_filter_306}},
#if defined(__MMI_CLNDR_EVENT_INFO__) && defined(__MMI_CALENDAR__)
    {"calendar_infobox_entry_alpha", 307, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {1228, 0, "", {0}, NULL}},
#else
    {"calendar_infobox_entry_alpha", 307, 21, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1228, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) 
    {"calendar_idle_bg_image", 308, 21, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1232, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {156, 133}, {156, 133}, {156, 133}, {182, 154}, }, mmi_mte_category_filter_308}},
#else
    {"calendar_idle_bg_image", 308, 21, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1232, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, mmi_mte_category_filter_308}},
#endif
    {"icon_bar_hint_text_color", 309, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1236, 0, "", {0}, NULL}},
    {"icon_bar_hint_filler", 310, 32, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1240, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"alphabet_bar_highlight_color", 311, 33, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1244, 0, "", {0}, NULL}},
    {"alphabet_bar_highlight_alpha", 312, 33, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1248, 0, "", {0}, NULL}},
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_key_disabled_bg_color", 313, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1252, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_disabled_bg_color", 313, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1252, 0, "", {0}, NULL}},
#endif
    {"virtual_keyboard_key_disabled_bg_alpha", 314, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1256, 0, "", {0}, NULL}},
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
    {"virtual_keyboard_key_disabled_text_color", 315, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1260, 0, "", {0}, NULL}},
#else
    {"virtual_keyboard_key_disabled_text_color", 315, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1260, 0, "", {0}, NULL}},
#endif
#if (defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))&&(defined(__MMI_VIRTUAL_KEYBOARD__)) &&(defined(__MMI_VK_POPUP_HINT__)) && !(defined(__MMI_FTE_SUPPORT__))
    {"virtual_keyboard_key_large_icon_left_image", 316, 13, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1264, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {43, 55}, {0, 0}, {43, 55}, {65, 75}, }, NULL}},
#else
    {"virtual_keyboard_key_large_icon_left_image", 316, 13, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1264, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))&&(defined(__MMI_VIRTUAL_KEYBOARD__)) &&(defined(__MMI_VK_POPUP_HINT__)) && !(defined(__MMI_FTE_SUPPORT__))
    {"virtual_keyboard_key_large_icon_right_image", 317, 13, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1268, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {43, 55}, {0, 0}, {43, 55}, {65, 75}, }, NULL}},
#else
    {"virtual_keyboard_key_large_icon_right_image", 317, 13, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1268, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"information_bar_alpha", 318, 0, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {1272, 0, "", {0}, NULL}},
#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__)
    {"special_screen_bkg_filler", 319, 34, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1276, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {{LCD_WIDTH, LCD_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"special_screen_bkg_filler", 319, 34, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1276, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | (MMI_MTE_IMAGE_JPG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_LIST_SCREEN__) && !defined(__MMI_FTE_SUPPORT__)
    {"small_list_menu_highlight_without_scrollbar_filler", 320, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1280, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{(((MAIN_LCD_DEVICE_WIDTH*3)/4)-5), MMI_MENUITEM_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"small_list_menu_highlight_without_scrollbar_filler", 320, 14, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1280, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"virtual_keyboard_bg_color", 321, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1284, 0, "", {0}, NULL}},
    {"virtual_keyboard_bg_alpha", 322, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1288, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_bg_color", 323, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1292, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_bg_alpha", 324, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1296, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_border_color", 325, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1300, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_border_alpha", 326, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1304, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_disable_color", 327, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1308, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_disable_alpha", 328, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1312, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_disable_border_color", 329, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1316, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_disable_border_alpha", 330, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1320, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_highlight_bg_color", 331, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1324, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_highlight_bg_alpha", 332, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1328, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_highlight_border_color", 333, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1332, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_highlight_border_alpha", 334, 13, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1336, 0, "", {0}, NULL}},
    {"virtual_keyboard_key_popup_hint_text_color", 335, 13, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1340, 0, "", {0}, NULL}},
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    {"dialing_screen_lkey_disable_image", 336, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1344, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {MMI_DIALING_FUNC_KEY_WIDTH, MMI_DIALING_FUNC_KEY_HEIGHT}, }, NULL}},
#else
    {"dialing_screen_lkey_disable_image", 336, 12, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1344, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_TOUCH_SCREEN__) 
    {"ime_information_bar_background_filler", 337, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1348, 0, "", {0}, NULL}},
#else
    {"ime_information_bar_background_filler", 337, 29, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1348, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_datetime_focussed_filler", 338, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1352, 0, "", {0}, NULL}},
#else
    {"inline_datetime_focussed_filler", 338, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1352, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_datetime_unfocussed_filler", 339, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1356, 0, "", {0}, NULL}},
#else
    {"inline_datetime_unfocussed_filler", 339, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_BORDER, {1356, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_highlight_left_arrow_image", 340, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1360, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_highlight_left_arrow_image", 340, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1360, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_highlight_right_arrow_image", 341, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1364, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_highlight_right_arrow_image", 341, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1364, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__)
    {"uce_screen_subject_color", 342, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1368, 0, "", {0}, NULL}},
#else
    {"uce_screen_subject_color", 342, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1368, 0, "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_FTE_SUPPORT__)
    {"inline_multiline_readonly_bg_alpha", 343, 5, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {1372, 0, "", {0}, NULL}},
#else
    {"inline_multiline_readonly_bg_alpha", 343, 5, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1372, 0, "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_FTE_SUPPORT__)
    {"inline_multiline_readonly_bg_color", 344, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1376, 0, "", {0}, NULL}},
#else
    {"inline_multiline_readonly_bg_color", 344, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1376, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_disabled_left_arrow_image", 345, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1380, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_disabled_left_arrow_image", 345, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1380, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CASCADE_MENU__)
    {"cascade_menu_submenu_disabled_right_arrow_image", 346, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1384, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, {15, 15}, }, NULL}},
#else
    {"cascade_menu_submenu_disabled_right_arrow_image", 346, 25, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1384, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_BASIC_UI_STYLE__)
    {"UCE_screen_pre_button_image", 347, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1388, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {10, 10}, {10, 10}, {10, 10}, {20, 20}, {10, 10}, {20, 20}, {20, 20}, }, NULL}},
#else
    {"UCE_screen_pre_button_image", 347, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1388, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_BASIC_UI_STYLE__)
    {"UCE_screen_pre_button_disabled_image", 348, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1392, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {10, 10}, {10, 10}, {10, 10}, {20, 20}, {10, 10}, {20, 20}, {20, 20}, }, NULL}},
#else
    {"UCE_screen_pre_button_disabled_image", 348, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1392, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_BASIC_UI_STYLE__)
    {"UCE_screen_next_button_image", 349, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1396, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {10, 10}, {10, 10}, {10, 10}, {20, 20}, {10, 10}, {20, 20}, {20, 20}, }, NULL}},
#else
    {"UCE_screen_next_button_image", 349, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1396, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && !defined(__MMI_BASIC_UI_STYLE__)
    {"UCE_screen_next_button_disabled_image", 350, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1400, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{0, 0}, {10, 10}, {10, 10}, {10, 10}, {20, 20}, {10, 10}, {20, 20}, {20, 20}, }, NULL}},
#else
    {"UCE_screen_next_button_disabled_image", 350, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1400, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_normal_l_tab_filler", 351, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1404, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_normal_l_tab_filler", 351, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1404, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_normal_r_tab_filler", 352, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1408, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_normal_r_tab_filler", 352, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1408, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_highlight_l_tab_filler", 353, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1412, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_highlight_l_tab_filler", 353, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1412, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_highlight_r_tab_filler", 354, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1416, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_highlight_r_tab_filler", 354, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1416, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_blink_l_tab_filler", 355, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1420, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_blink_l_tab_filler", 355, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1420, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if (defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)) && !defined(__MMI_FTE_SUPPORT__)
    {"tab_blink_r_tab_filler", 356, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1424, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH, GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"tab_blink_r_tab_filler", 356, 20, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, MMI_MTE_FILLER_ALLOW_NULL, {1424, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_text_normal_color", 357, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1428, 0, "", {0}, NULL}},
#else
    {"icon_bar_item_text_normal_color", 357, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1428, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_text_disable_color", 358, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1432, 0, "", {0}, NULL}},
#else
    {"icon_bar_item_text_disable_color", 358, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1432, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_normal_left_background", 359, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1436, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {13, 38}, {0, 0}, {13, 42}, {13, 51}, }, NULL}},
#else
    {"icon_bar_item_normal_left_background", 359, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1436, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_pressed_left_background", 360, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1440, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {13, 38}, {0, 0}, {13, 42}, {13, 51}, }, NULL}},
#else
    {"icon_bar_item_pressed_left_background", 360, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1440, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_normal_right_background", 361, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1444, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {13, 38}, {0, 0}, {13, 42}, {13, 51}, }, NULL}},
#else
    {"icon_bar_item_normal_right_background", 361, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1444, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_pressed_right_background", 362, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1448, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {13, 38}, {0, 0}, {13, 42}, {13, 51}, }, NULL}},
#else
    {"icon_bar_item_pressed_right_background", 362, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1448, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_normal_left_right_background", 363, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1452, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {24, 38}, {0, 0}, {24, 42}, {24, 51}, }, NULL}},
#else
    {"icon_bar_item_normal_left_right_background", 363, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1452, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_pressed_left_right_background", 364, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1456, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {24, 38}, {0, 0}, {24, 42}, {24, 51}, }, NULL}},
#else
    {"icon_bar_item_pressed_left_right_background", 364, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1456, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_normal_center_background", 365, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1460, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {5, 38}, {0, 0}, {5, 42}, {5, 51}, }, NULL}},
#else
    {"icon_bar_item_normal_center_background", 365, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1460, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_pressed_center_background", 366, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1464, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {5, 38}, {0, 0}, {5, 42}, {5, 51}, }, NULL}},
#else
    {"icon_bar_item_pressed_center_background", 366, 32, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1464, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"calendar_title_text_color_for_idle", 367, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1468, 0, "", {0}, NULL}},
    {"calendar_cell_event_text_color_for_idle", 368, 21, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1472, 0, "", {0}, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"DOW_normal_background_filler", 369, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1476, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {225, 35}, {0, 0}, {225, 35}, {300, 40}, }, NULL}},
#else
    {"DOW_normal_background_filler", 369, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1476, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"DOW_highlight_background_filler", 370, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1480, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {225, 35}, {0, 0}, {225, 35}, {300, 40}, }, NULL}},
#else
    {"DOW_highlight_background_filler", 370, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1480, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"DOW_cell_normal_selected_filler", 371, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1484, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 35}, {0, 0}, {28, 35}, {30, 40}, }, NULL}},
#else
    {"DOW_cell_normal_selected_filler", 371, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1484, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"DOW_cell_focus_selected_filler", 372, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1488, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 35}, {0, 0}, {28, 35}, {30, 40}, }, NULL}},
#else
    {"DOW_cell_focus_selected_filler", 372, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1488, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"DOW_cell_highlight_filler", 373, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1492, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 35}, {0, 0}, {28, 35}, {30, 40}, }, NULL}},
#else
    {"DOW_cell_highlight_filler", 373, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1492, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"popup_cell_normal_background", 374, 21, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1496, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {43, 55}, {0, 0}, {43, 55}, {65, 75}, }, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_color_select_highlighted_index_image", 375, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1500, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {7, 35}, {0, 0}, {7, 35}, {6, 40}, }, NULL}},
#else
    {"inline_item_color_select_highlighted_index_image", 375, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1500, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_color_select_highlighted_bg_image", 376, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1504, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {90, 35}, {0, 0}, {90, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_color_select_highlighted_bg_image", 376, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1504, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_color_select_unhighlighted_bg_image", 377, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1508, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {90, 35}, {0, 0}, {90, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_color_select_unhighlighted_bg_image", 377, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1508, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_select_left_arrow_push_image", 378, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1512, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{INLINE_FTE_SELECTOR_ARROW_WIDTH, INLINE_FTE_SELECTOR_ARROW_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"inline_item_select_left_arrow_push_image", 378, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1512, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_select_right_arrow_push_image", 379, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1516, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {{INLINE_FTE_SELECTOR_ARROW_WIDTH, INLINE_FTE_SELECTOR_ARROW_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"inline_item_select_right_arrow_push_image", 379, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1516, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | (MMI_MTE_IMAGE_BMP << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_background_small", 380, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1520, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 28}, {0, 0}, {228, 32}, {228, 32}, }, NULL}},
#else
    {"ime_cand_background_small", 380, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1520, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_background_medium", 381, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1524, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 34}, {0, 0}, {228, 38}, {228, 38}, }, NULL}},
#else
    {"ime_cand_background_medium", 381, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1524, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_background_large", 382, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1528, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 40}, {0, 0}, {228, 46}, {228, 46}, }, NULL}},
#else
    {"ime_cand_background_large", 382, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1528, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_focus_frame_small", 383, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1532, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 28}, {0, 0}, {228, 32}, {228, 32}, }, NULL}},
#else
    {"ime_cand_focus_frame_small", 383, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1532, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_focus_frame_medium", 384, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1536, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 34}, {0, 0}, {228, 38}, {228, 38}, }, NULL}},
#else
    {"ime_cand_focus_frame_medium", 384, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1536, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_focus_frame_large", 385, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1540, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {228, 40}, {0, 0}, {228, 46}, {228, 46}, }, NULL}},
#else
    {"ime_cand_focus_frame_large", 385, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1540, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_separator_small", 386, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1544, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 22}, {0, 0}, {1, 26}, {1, 26}, }, NULL}},
#else
    {"ime_cand_separator_small", 386, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1544, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_separator_medium", 387, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1548, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 28}, {0, 0}, {1, 32}, {1, 32}, }, NULL}},
#else
    {"ime_cand_separator_medium", 387, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1548, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_separator_large", 388, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1552, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 34}, {0, 0}, {1, 40}, {1, 40}, }, NULL}},
#else
    {"ime_cand_separator_large", 388, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1552, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_down_small", 389, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1556, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_left_arrow_down_small", 389, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1556, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_down_medium", 390, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1560, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_left_arrow_down_medium", 390, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1560, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_down_large", 391, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1564, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_left_arrow_down_large", 391, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1564, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_up_small", 392, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1568, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_left_arrow_up_small", 392, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1568, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_up_medium", 393, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1572, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_left_arrow_up_medium", 393, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1572, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_up_large", 394, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1576, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_left_arrow_up_large", 394, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1576, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_disable_small", 395, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1580, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_left_arrow_disable_small", 395, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1580, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_disable_medium", 396, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1584, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_left_arrow_disable_medium", 396, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1584, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_left_arrow_disable_large", 397, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1588, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_left_arrow_disable_large", 397, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1588, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_down_small", 398, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1592, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_right_arrow_down_small", 398, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1592, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_down_medium", 399, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1596, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_right_arrow_down_medium", 399, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1596, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_down_large", 400, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1600, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_right_arrow_down_large", 400, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1600, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_up_small", 401, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1604, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_right_arrow_up_small", 401, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1604, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_up_medium", 402, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1608, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_right_arrow_up_medium", 402, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1608, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_up_large", 403, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1612, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_right_arrow_up_large", 403, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1612, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_disable_small", 404, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1616, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_right_arrow_disable_small", 404, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1616, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_disable_medium", 405, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1620, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_right_arrow_disable_medium", 405, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1620, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_right_arrow_disable_large", 406, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1624, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_right_arrow_disable_large", 406, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1624, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_highlight_small", 407, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1628, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_highlight_small", 407, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1628, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_highlight_medium", 408, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1632, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_highlight_medium", 408, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1632, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_highlight_large", 409, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1636, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_highlight_large", 409, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1636, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_dull_highlight_small", 410, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 22}, {0, 0}, {30, 26}, {32, 26}, }, NULL}},
#else
    {"ime_cand_dull_highlight_small", 410, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1640, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_dull_highlight_medium", 411, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 28}, {0, 0}, {30, 32}, {32, 32}, }, NULL}},
#else
    {"ime_cand_dull_highlight_medium", 411, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1644, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_dull_highlight_large", 412, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1648, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {28, 34}, {0, 0}, {30, 40}, {32, 40}, }, NULL}},
#else
    {"ime_cand_dull_highlight_large", 412, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1648, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_input_background_small", 413, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1652, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {18, 28}, {0, 0}, {18, 32}, {18, 32}, }, NULL}},
#else
    {"ime_input_background_small", 413, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1652, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_input_background_medium", 414, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1656, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {18, 34}, {0, 0}, {18, 38}, {18, 38}, }, NULL}},
#else
    {"ime_input_background_medium", 414, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1656, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_input_background_large", 415, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1660, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {18, 40}, {0, 0}, {18, 46}, {18, 46}, }, NULL}},
#else
    {"ime_input_background_large", 415, 29, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1660, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"scrollbar_v_scroll_button_image", 416, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1664, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {6, 8}, {0, 0}, {6, 8}, {6, 8}, }, NULL}},
#else
    {"scrollbar_v_scroll_button_image", 416, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1664, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"scrollbar_h_scroll_button_image", 417, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1668, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {8, 6}, {0, 0}, {8, 6}, {8, 6}, }, NULL}},
#else
    {"scrollbar_h_scroll_button_image", 417, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1668, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"wider_scrollbar_v_top_button_image", 418, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1672, 0, "", {0}, NULL}},
    {"wider_scrollbar_v_top_clicked_button_image", 419, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1676, 0, "", {0}, NULL}},
    {"wider_scrollbar_v_bottom_button_image", 420, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1680, 0, "", {0}, NULL}},
    {"wider_scrollbar_v_bottom_clicked_button_image", 421, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1684, 0, "", {0}, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"wider_scrollbar_v_background_button_image", 422, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1688, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {22, 100}, {0, 0}, {24, 100}, {28, 100}, }, NULL}},
#else
    {"wider_scrollbar_v_background_button_image", 422, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1688, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"wider_scrollbar_v_scroll_button_image", 423, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1692, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {22, 17}, {0, 0}, {24, 17}, {28, 17}, }, NULL}},
#else
    {"wider_scrollbar_v_scroll_button_image", 423, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1692, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"wider_scrollbar_v_scroll_clicked_button_image", 424, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1696, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {22, 17}, {0, 0}, {24, 17}, {28, 17}, }, NULL}},
    {"wider_scrollbar_h_left_button_image", 425, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1700, 0, "", {0}, NULL}},
    {"wider_scrollbar_h_left_clicked_button_image", 426, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1704, 0, "", {0}, NULL}},
    {"wider_scrollbar_h_right_button_image", 427, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1708, 0, "", {0}, NULL}},
    {"wider_scrollbar_h_right_clicked_button_image", 428, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1712, 0, "", {0}, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"wider_scrollbar_h_background_button_image", 429, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1716, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {100, 22}, {0, 0}, {100, 24}, {100, 28}, }, NULL}},
#else
    {"wider_scrollbar_h_background_button_image", 429, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1716, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"wider_scrollbar_h_scroll_button_image", 430, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1720, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {17, 22}, {0, 0}, {17, 24}, {17, 28}, }, NULL}},
#else
    {"wider_scrollbar_h_scroll_button_image", 430, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1720, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
    {"wider_scrollbar_h_scroll_clicked_button_image", 431, 1, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1724, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {17, 22}, {0, 0}, {17, 24}, {17, 28}, }, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"slide_bar_background_image", 432, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1728, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {41, 35}, {0, 0}, {41, 35}, {41, 40}, }, NULL}},
#else
    {"slide_bar_background_image", 432, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1728, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"slide_bar_indicator_image", 433, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1732, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {16, 16}, {0, 0}, {16, 16}, {20, 20}, }, NULL}},
#else
    {"slide_bar_indicator_image", 433, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1732, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"tab_bar_left_indicator_image", 434, 20, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1736, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {9, 12}, {0, 0}, {12, 12}, {12, 12}, }, NULL}},
#else
    {"tab_bar_left_indicator_image", 434, 20, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1736, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"tab_bar_right_indicator_image", 435, 20, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1740, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {9, 12}, {0, 0}, {12, 12}, {12, 12}, }, NULL}},
#else
    {"tab_bar_right_indicator_image", 435, 20, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1740, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inputbox_default_text_color", 436, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1744, 0, "", {0}, NULL}},
#else
    {"inputbox_default_text_color", 436, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1744, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_1_menu_button_normal_bg", 437, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1748, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {20, 37}, {0, 0}, {20, 37}, {20, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_1_menu_button_normal_bg", 437, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1748, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_1_menu_button_pressed_bg", 438, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1752, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {20, 37}, {0, 0}, {20, 37}, {20, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_1_menu_button_pressed_bg", 438, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1752, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_2_menu_left_button_normal_bg", 439, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1756, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_2_menu_left_button_normal_bg", 439, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1756, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_2_menu_left_button_pressed_bg", 440, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1760, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_2_menu_left_button_pressed_bg", 440, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1760, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_2_menu_right_button_normal_bg", 441, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1764, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_2_menu_right_button_normal_bg", 441, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1764, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_2_menu_right_button_pressed_bg", 442, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1768, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_2_menu_right_button_pressed_bg", 442, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1768, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_3_menu_middle_button_normal_bg", 443, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1772, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_3_menu_middle_button_normal_bg", 443, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1772, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_3_menu_middle_button_pressed_bg", 444, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1776, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {14, 37}, {0, 0}, {14, 37}, {14, 37}, }, NULL}},
#else
    {"clipboard_floating_menu_3_menu_middle_button_pressed_bg", 444, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1776, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_down_arrow_button_normal_bg", 445, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1780, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {34, 16}, {0, 0}, {34, 16}, {34, 16}, }, NULL}},
#else
    {"clipboard_floating_menu_down_arrow_button_normal_bg", 445, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1780, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_down_arrow_button_pressed_bg", 446, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1784, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {34, 16}, {0, 0}, {34, 16}, {34, 16}, }, NULL}},
#else
    {"clipboard_floating_menu_down_arrow_button_pressed_bg", 446, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1784, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_text_color", 447, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1788, 0, "", {0}, NULL}},
#else
    {"clipboard_floating_menu_text_color", 447, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1788, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inputbox_remaining_counter_bg", 448, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1792, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {7, 5}, {0, 0}, {7, 5}, {7, 5}, }, NULL}},
#else
    {"inputbox_remaining_counter_bg", 448, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1792, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inputbox_highlighter_alpha", 449, 0, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 1, 0, 0, 100, 0, {1796, 0, "", {0}, NULL}},
#else
    {"inputbox_highlighter_alpha", 449, 0, MMI_MTE_THEME_DATA_TYPE_INTEGER, NULL, 0, 0, 0, 100, 0, {1796, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_text_border_normal_color", 450, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1800, 0, "", {0}, NULL}},
#else
    {"icon_bar_item_text_border_normal_color", 450, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1800, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"icon_bar_item_text_border_disable_color", 451, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1804, 0, "", {0}, NULL}},
#else
    {"icon_bar_item_text_border_disable_color", 451, 32, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1804, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"softkey_down_text_border_color", 452, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1808, 0, "", {0}, NULL}},
#else
    {"softkey_down_text_border_color", 452, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1808, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"softkey_disabled_text_border_color", 453, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1812, 0, "", {0}, NULL}},
#else
    {"softkey_disabled_text_border_color", 453, 15, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1812, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"CM_screen_text_border_color", 454, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1816, 0, "", {0}, NULL}},
#else
    {"CM_screen_text_border_color", 454, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1816, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"ime_cand_dull_highlighted_text_color", 455, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1820, 0, "", {0}, NULL}},
#else
    {"ime_cand_dull_highlighted_text_color", 455, 29, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1820, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"slide_bar_focused_bg_image", 456, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1824, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {41, 35}, {0, 0}, {41, 35}, {41, 40}, }, NULL}},
#else
    {"slide_bar_focused_bg_image", 456, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1824, MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"slide_bar_focused_indicator_image", 457, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1828, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {16, 16}, {0, 0}, {16, 16}, {20, 20}, }, NULL}},
#else
    {"slide_bar_focused_indicator_image", 457, 5, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1828, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"horizontal_select_bg_filler", 458, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1832, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {89, 35}, {0, 0}, {89, 35}, {107, 40}, }, NULL}},
#else
    {"horizontal_select_bg_filler", 458, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1832, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"horizontal_select_focused_bg_filler", 459, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1836, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {89, 35}, {0, 0}, {89, 35}, {107, 40}, }, NULL}},
#else
    {"horizontal_select_focused_bg_filler", 459, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1836, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_item_progress_bar_highlight_bg_filler", 460, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1840, 0, "", {0}, NULL}},
#else
    {"inline_item_progress_bar_highlight_bg_filler", 460, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1840, 0, "", {0}, NULL}},
#endif
    {"inline_item_progress_bar_unhighlight_bg_filler", 461, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1844, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"inline_item_progress_bar_gradient_progress_filler", 462, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1848, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_item_progress_bar_normal_progress_filler", 463, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1852, 0, "", {0}, NULL}},
#else
    {"inline_item_progress_bar_normal_progress_filler", 463, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1852, 0, "", {0}, NULL}},
#endif
#if !defined(__MMI_FTE_SUPPORT__)
    {"inline_item_progress_bar_step_filler", 464, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1856, 0, "", {0}, NULL}},
#else
    {"inline_item_progress_bar_step_filler", 464, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1856, 0, "", {0}, NULL}},
#endif
    {"inline_item_progress_bar_button_pressed_filler", 465, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1860, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"inline_item_progress_bar_button_normal_filler", 466, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1864, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
    {"inline_item_progress_bar_text_color", 467, 5, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1868, 0, "", {0}, NULL}},
    {"inline_item_displayonly_rdonly_style_bg_filler", 468, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1872, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_button_highlighted_pressed_bg_filler", 469, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1876, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_button_highlighted_pressed_bg_filler", 469, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1876, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_button_highlighted_normal_bg_filler", 470, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1880, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_button_highlighted_normal_bg_filler", 470, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1880, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_button_unhighlighted_pressed_bg_filler", 471, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1884, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_button_unhighlighted_pressed_bg_filler", 471, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1884, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_button_unhighlighted_normal_bg_filler", 472, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1888, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_button_unhighlighted_normal_bg_filler", 472, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1888, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_textedit_highlighted_bg_filler", 473, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1892, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_textedit_highlighted_bg_filler", 473, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1892, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"inline_item_textedit_unhighlighted_bg_filler", 474, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1896, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {78, 35}, {0, 0}, {78, 35}, {150, 40}, }, NULL}},
#else
    {"inline_item_textedit_unhighlighted_bg_filler", 474, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1896, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_up_arrow_button_normal_bg_image", 475, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1900, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {34, 16}, {0, 0}, {34, 16}, {34, 16}, }, NULL}},
#else
    {"clipboard_floating_menu_up_arrow_button_normal_bg_image", 475, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1900, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"clipboard_floating_menu_up_arrow_button_pressed_bg_image", 476, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1904, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {34, 16}, {0, 0}, {34, 16}, {34, 16}, }, NULL}},
#else
    {"clipboard_floating_menu_up_arrow_button_pressed_bg_image", 476, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1904, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR__)
    {"calendar_current_bg_filler", 477, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1908, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{((GUI_CALENDAR_HORIZONTAL_STRING_WIDTH-6)/7), ((GUI_CALENDAR_CELL_ARRAY_HEIGHT-5)/6)}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"calendar_current_bg_filler", 477, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1908, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    {"calendar_current_bg_for_idle_filler", 478, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1912, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {20, 13}, {20, 13}, {20, 13}, {24, 15}, }, mmi_mte_category_filter_478}},
#else
    {"calendar_current_bg_for_idle_filler", 478, 21, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1912, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_JPG | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, mmi_mte_category_filter_478}},
#endif
    {"popup_screen_bg_filler", 479, 18, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1916, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(__MMI_SCREEN_ROTATE__) &&  !defined(__MMI_MAINLCD_320X240__)&& defined(MMI_ROTATED_POP_UP_DIALOG_WIDTH) && defined(MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT) && !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
    {"rotated_popup_screen_bg_filler", 480, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1920, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {{MMI_ROTATED_POP_UP_DIALOG_WIDTH, MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#else
    {"rotated_popup_screen_bg_filler", 480, 23, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 0, 0, 0, 0, 0, {1920, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_GIF | MMI_MTE_IMAGE_9SLICE | (MMI_MTE_IMAGE_9SLICE << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_SMALL_EDIT_SCREEN__)
    {"editor_small_screen_border_color", 481, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1924, 0, "", {0}, NULL}},
#else
    {"editor_small_screen_border_color", 481, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1924, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"editor_recipient_button_image", 482, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1928, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {40, 25}, {0, 0}, {40, 25}, {42, 27}, }, NULL}},
#else
    {"editor_recipient_button_image", 482, 0, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1928, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {0}, NULL}},
#endif
#if defined(__MMI_FTE_SUPPORT__)
    {"editor_recipient_button_text_color", 483, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1932, 0, "", {0}, NULL}},
#else
    {"editor_recipient_button_text_color", 483, 0, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1932, 0, "", {0}, NULL}},
#endif
    {"singleline_editor_bg_filler", 484, 5, MMI_MTE_THEME_DATA_TYPE_FILLER, NULL, 1, 0, 0, 0, 0, {1936, MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG | (MMI_MTE_IMAGE_PNG << 16), "", {{LCD_WIDTH, (WGUI_SINGLELINE_INFO_BAR_HEIGHT+MMI_SINGLELINE_INPUTBOX_HEIGHT+2)}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, }, NULL}},
#if defined(__MMI_STOPWATCH__)
    {"stopwatch_active_timer_text_color", 485, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1940, 0, "", {0}, NULL}},
#else
    {"stopwatch_active_timer_text_color", 485, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1940, 0, "", {0}, NULL}},
#endif
#if defined(__MMI_STOPWATCH__)
    {"stopwatch_inactive_timer_text_color", 486, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 1, 0, 0, 0, 0, {1944, 0, "", {0}, NULL}},
#else
    {"stopwatch_inactive_timer_text_color", 486, 8, MMI_MTE_THEME_DATA_TYPE_COLOR, NULL, 0, 0, 0, 0, 0, {1944, 0, "", {0}, NULL}},
#endif
#if defined(__UI_MMS_VIEWER_CATEGORY__) && !defined(__MMI_FTE_SUPPORT__)
    {"mms_viewer_progress_bar_img", 487, 8, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 1, 0, 0, 0, 0, {1948, MMI_MTE_IMAGE_BMP, "", {{0, 0}, {128, 12}, {128, 22}, {166, 22}, {240, 36}, {320, 34}, {240, 36}, {320, 36}, }, NULL}},
#else
    {"mms_viewer_progress_bar_img", 487, 8, MMI_MTE_THEME_DATA_TYPE_IMAGE, NULL, 0, 0, 0, 0, 0, {1948, MMI_MTE_IMAGE_BMP, "", {0}, NULL}},
#endif
};


/* theme component English description */
static const wchar_t *g_mmi_mte_theme_component_description_EN[MMI_MTE_THEME_COMPONENT_NUM] =
{
    L"Inputbox background filler",
    L"Scrollbar background filler",
    L"Scrollbar button background filler",
    L"Title background filler",
    L"List menu background filler (128x128 only)",
    L"Normal list menu item background filler (rarely used)",
    L"Highlighted list menu item background filler (if the menuitem_xxx_filler is an image and the image dimension does not fit well in the current menu. )",
    L"Disabled list menu item background filler (rarely used)",
    L"Highlighted matrix menu item background filler",
    L"Normal date and time inputbox background filler",
    L"Highlighted date and time inputbox background filler",
    L"Normal list main menu item background filler",
    L"Highlighted list main menu item background filler",
    L"Disabled list main menu item background filler (rarely used)",
    L"Highlighted matrix main menu item background filler",
    L"General background filler, background of text and picture, usually is white color.",
    L"List menu hint description background filler",
    L"Normal inline list menu item background filler",
    L"Highlighted inline list menu item background filler",
    L"Disabled inline list menu item background filler (rarely used)",
    L"Highlighted inline single line editor background filler",
    L"Normal inline single line editor background filler",
    L"Inline single line editor without boundary background filler",
    L"PIN input editor background filler",
    L"PIN input screen background filler",
    L"Date time and status bar 1 background filler",
    L"Call manager screen background filler",
    L"Dialer input box background filler",
    L"Virtual keyboard key down background filler",
    L"Normal small list screen background filler",
    L"Small list screen background border filler",
    L"Lite display screen background color, used when the SCR BG image is absent. (Ex: WAP, Java)",
    L"Text color of normal left softkey",
    L"Text color of down left softkey",
    L"Text color of disabled left softkey (rarely used)",
    L"Text color of normal right softkey",
    L"Text color of down right softkey",
    L"Text color of disabled right softkey (rarely used)",
    L"Inputbox normal text color",
    L"Inputbox highlighted text color",
    L"Inputbox highlighted background color",
    L"Inputbox cursor color",
    L"Title text color",
    L"Title text border color",
    L"Text color of shortcut",
    L"Text color of the normal (unhighlighted) list menu item",
    L"Text color of the highlighted list menu item",
    L"Text color of the disabled list menu item (rarely used)",
    L"Text color of the normal matrix menu item",
    L"Text color of the highlighted matrix menu item",
    L"Text color of the disabled matrix menu item (rarely used)",
    L"Formatted inputbox cursor color",
    L"Text color of the normal (unhighlighted) list main menu item",
    L"Text color of the highlighted list main menu item",
    L"Text color of the disabled list main menu item (rarely used)",
    L"Text color of the normal (unhighlighted) matrix main menu item",
    L"Text color of the highlighted matrix main menu item",
    L"Text color of the disabled matrix main menu item (rarely used)",
    L"List menu hint description text color",
    L"Call manager screen text color",
    L"Call manager screen date and time background color",
    L"Call manager screen time duration background color",
    L"Call manager screen date text color",
    L"Call manager screen time text color",
    L"Call manager screen duration text color",
    L"Advice Of Charge text color",
    L"Information bar background color",
    L"IME text color",
    L"The message remaining length text color",
    L"Inline single line editor text color",
    L"Inline single line editor unfocussed text color",
    L"Inline single line editor selected text color",
    L"Inline single line editor selector color",
    L"Inline single line editor cursor color",
    L"Inline list menu item normal text color",
    L"Inline list menu item highlighted text color",
    L"Inline list menu item disabled text color (rarely used)",
    L"PIN input editor text color",
    L"PIN input editor selected text color",
    L"PIN input editor selector color",
    L"PIN input editor cursor color",
    L"The dialer input box text color",
    L"The dialer input box selected text color",
    L"The dialer input box selector color",
    L"The dialer input box cursor color",
    L"Text color of virtual keyboard key when it is selected",
    L"Text color of virtual keyboard key when it is not selected",
    L"Text color of virtual keyboard dead key when it is selected",
    L"Text color of virtual keyboard dead key when it is not selected",
    L"Text color of virtual keyboard display area",
    L"Idle screen date text color",
    L"Idle screen time text color",
    L"Idle screen date text border color",
    L"Idle screen time text border color",
    L"Idle screen network name text color",
    L"Idle screen network name text border color",
    L"Idle screen network status text color",
    L"Idle screen network status text border color",
    L"Idle screen network extra text color, such as MP3 song name in play.",
    L"Idle screen network extra text border color,  such as MP3 song name in play.",
    L"Width of vertical scroll bar or height of horizontal scroll bar",
    L"Full opacity of screen",
    L"High opacity of screen (not used)",
    L"Medium opacity of screen (not used)",
    L"Low opacity of screen (used in Editor)",
    L"Single-line highlighted menu item background filler (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Two-line highlighted menu item background filler (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Multi-row highlighted menu item background filler (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Thick highlighted menu item background filler (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Thick with tab menu item background filler (category 425 only. The image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Symbol picker highlight filler",
    L"Matrix menu highlight filler",
    L"Main menu background filler",
    L"Sub menu background filler",
    L"Idle screen background filler (set the wallpaper to 'Theme Image' to see it)",
    L"Popup text color",
    L"Idle screen weekday text color",
    L"Idle screen weekday text border color",
    L"Clock component: Text color of date text for digital clock in main lcd",
    L"Clock component: Text border color of date text for digital clock in main lcd",
    L"Clock component: Text color of time text for digital clock in main lcd",
    L"Clock component: Text border color of time text for digital clock in main lcd",
    L"Clock component: Hour hand color of analog clock in main lcd",
    L"Clock component: Minute hand color of analog clock in main lcd",
    L"Clock component: Analog axis color (set the wallpaper to 'Analog Clock' to see this.)",
    L"Softkey bar text border color",
    L"Softkey bar background filler",
    L"Tab title background filler",
    L"Tab title text color",
    L"Tab title text border color",
    L"Tab title shortcut text color",
    L"Calendar title text color",
    L"Calendar horizontal select's text color",
    L"Calendar horizontal select's text border color",
    L"Calendar week number text color",
    L"Calendar weekday text color",
    L"Calendar one task state cell background color",
    L"Calendar multi task state cell background color",
    L"Calendar menstrual state cell background color",
    L"Calendar PP state cell background color",
    L"Calendar danger state cell background color",
    L"Calendar invalid state cell background color",
    L"Calendar valid state cell text color",
    L"Calendar invalid state cell text color",
    L"Calendar highlight state cell background color",
    L"Calendar info box background color",
    L"Calendar info box item background color",
    L"Calendar info box text color",
    L"Status icon bar background filler",
    L"Thick title background filler",
    L"Thick title text color",
    L"Thick title text border color",
    L"Thick title shortcut text color",
    L"Rotated screen background filler",
    L"Rotated screen title background filler",
    L"Small list screen title background filler",
    L"Tab bar normal background filler",
    L"Tab bar highlighted background filler",
    L"Tab bar blinking background filler",
    L"Bidegree main menu tab highlight filler",
    L"Matrix main menu highlight image",
    L"Bidegree main menu tab normal background filler",
    L"List menu separator color",
    L"Cascade menu separator color",
    L"Cascade menu normal text color",
    L"Cascade menu selected text color",
    L"Cascade menu disabled text color",
    L"Cascade menu border color",
    L"Cascade menu background filler",
    L"Cascade menu item highlight filler",
    L"Cascade menu left arrow image",
    L"Cascade menu right arrow image",
    L"List menu check box selected icon image",
    L"List menu check box unselected icon image",
    L"List menu radio box selected icon image",
    L"List menu radio box unselected icon image",
    L"Inline horizontal select left arrow image",
    L"Inline horizontal select right arrow image",
    L"Inputbox base line color",
    L"EMS control character base line color",
    L"Dialer inputbox text color",
    L"Dialer inputbox text border color",
    L"Left softkey down filler",
    L"Left softkey up filler",
    L"Right softkey down filler",
    L"Right softkey up filler",
    L"Color of title background rectangle",
    L"Color of horizontal string background rectangle",
    L"Color of vertical select background rectangle",
    L"Color of cell array background rectangle",
    L"Color of frame line",
    L"Color of cell frame line",
    L"Text color of current date's cell",
    L"Text color of popup",
    L"Color of popup background rectangle",
    L"Color of popup border",
    L"Alpha value of infobox's background",
    L"Alpha value of title's background",
    L"Alpha value of horizontal string's background",
    L"Alpha value of vertical select's background",
    L"Alpha value of cell array background",
    L"Alpha value of frame line",
    L"Text color of horizontal string for static calendar on idle screen",
    L"Color of horizontal string background rectangle for static calendar on idle screen",
    L"Text color of cell valid date for static calendar on idle screen",
    L"Text color of cell invalid date for static calendar on idle screen",
    L"Color of cell array background rectangle for static calendar on idle screen",
    L"Text of cell current date for static calendar on idle screen",
    L"Color of cell current date's rectangle border for static calendar on idle screen",
    L"Color of frame line for static calendar on idle screen",
    L"Color of cell line for static calendar on idle screen",
    L"Alpha value of horizontal string rectangle background for static calendar on idle screen",
    L"Alpha value of cell array rectangle background for static calendar on idle screen",
    L"Alpha value of current date's rectangle background for static calendar on idle screen",
    L"Alpha value of cell current date's border for static calendar on idle screen",
    L"Alpha value of frame line for static calendar on idle screen",
    L"Alpha value of cell line for static calendar on idle screen",
    L"Color of arrow direction",
    L"Border color of arrow direction",
    L"DCD area's background on idle screen",
    L"DCD area's font color which has been read on idle screen",
    L"DCD area's font color which is not yet read on idle screen",
    L"DCD channel list's highlight background on DCD channel list screen",
    L"DCD story content's text color on DCD story viewer screen",
    L"Visited URL text color on DCD story viewer screen",
    L"Unvisited URL text color on DCD story viewer screen",
    L"URL bar background color on DCD story viewer screen",
    L"Color of SIM2 network name text color",
    L"Color of SIM2 network name border color",
    L"Color of SIM2 network status text color",
    L"Color of SIM2 network status border color",
    L"Full height filler of popup background",
    L"Color of popup content text",
    L"Text color of title in main menu",
    L"Border  color of title in main menu",
    L"IME under line color",
    L"IME indicator color",
    L"Background filler of focused area",
    L"Background filler of not focused area",
    L"Width of separator in candidate box",
    L"Border color of not focused candidate box",
    L"Width of separator in candidate box",
    L"Color of separator of not focused candidate box",
    L"Color of separator of  focused candidate box",
    L"Candidate space of candidate box",
    L"Color of label",
    L"Color of cursor",
    L"Color of disabled arrow",
    L"Color of pressed down arrow",
    L"Color of normal arrow",
    L"Color of normal candidate in candidate box",
    L"Color of highlighted candidate in candidate box",
    L"Color of highlight rectangle in candidate box",
    L"Color of normal candidate in composition box",
    L"Color of highlighted candidate in composition box",
    L"Color of highlight rectangle in composition box",
    L"Color of normal candidate in input box",
    L"Color of highlighted candidate in input box",
    L"Color of highlight rectangle in input box",
    L"Color of normal stroke in candidate box",
    L"Color of highlighted stroke in candidate box",
    L"Color of highlight rectangle of stroke in candidate box",
    L"Filler of special tab",
    L"Color of background in mini indicator",
    L"Color of normal indicator",
    L"Color of tab indicator",
    L"Color of media player content",
    L"Color of media player content border",
    L"Color of first line in two line",
    L"Color of first line highlight in two line",
    L"Color of second line  in two line",
    L"Color of second line highlight in two line",
    L"Filler of second line selector in two line",
    L"Color of second line selector in two line",
    L"Color of first line in multirow",
    L"Color of first line  highlight in multirow",
    L"Color of second line in multirow",
    L"Color of second line highlight in multirow",
    L"Color of third line in multirow",
    L"Color of third line highlight in multirow",
    L"Color of grid line",
    L"Alpha of grid line",
    L"Single-line highlighted menu item background filler without scroll bar (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Two-line highlighted menu item background filler without scroll bar (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Multi-row highlighted menu item background filler without scroll bar (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Thick highlighted menu item background filler without scroll bar (the image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Thick with tab menu item background filler without scroll bar (category 425 only. The image dimension must be the same to the recommended dimension if using an image not of 9slice.)",
    L"Dialing screen background image",
    L"Dialing screen small key up image",
    L"Dialing screen small key down image",
    L"Dialing screen large key up image",
    L"Dialing screen large key down image",
    L"Color of voip dialer editor text",
    L"Color of header information text",
    L"Filler of background in calling popup ",
    L"Filler of left softkey in popup",
    L"Filler of down left softkey in popup",
    L"Filler of right softkey in popup",
    L"Filler of down right softkey in popup",
    L"Color of softkey in popup",
    L"Color of softkey border in popup",
    L"Filler of softkey bar in popup",
    L"Filler of highlight in small list menu",
    L"Color of highlight text in small list menu",
    L"Color of text in small list menu",
    L"Color of current day text in calendar",
    L"Color of current date text in calendar",
    L"Alpha of entry infobox in calendar",
    L"Background image in idle calendar",
    L"Color of hint in icon bar",
    L"Filler of hint in icon bar",
    L"Color of highlight in alphabet bar",
    L"Alpha of highlight in alphabet bar",
    L"Color of disabled background in virtual keyboard",
    L"Alpha of disabled background in virtual keyboard",
    L"Color of disabled text in virtual keyboard",
    L"Left image of large icon in virtual keyboard. Please do operation(for example, delete or add image) to item virtual_keyboard_key_large_icon_left_image and virtual_keyboard_key_large_icon_right_image at the same time. Or it will not display the large icon of VK popup hint.",
    L"Right image of large icon in virtual keyboard. Please do operation(for example, delete or add image) to item virtual_keyboard_key_large_icon_left_image and virtual_keyboard_key_large_icon_right_image at the same time. Or it will not display the large icon of VK popup hint.",
    L"Alpha of information bar",
    L"Filler of background in special screen",
    L"Highlight filler without scroll bar for small screen",
    L"Background color for virtual keyboard",
    L"Background alpha in virtual keyboard",
    L"Key background color in virtual keyboard",
    L"Key background alpha in virtual keyboard",
    L"Key border background color in virtual keyboard",
    L"Key border background alpha in virtual keyboard",
    L"Disabled key background color in virtual keyboard",
    L"Disabled key background alpha in virtual keyboard",
    L"Disabled key border background color in virtual keyboard",
    L"Disabled key border background alpha in virtual keyboard",
    L"Highlight key background color in virtual keyboard",
    L"Highlight key background alpha in virtual keyboard",
    L"Highlight key border background color in virtual keyboard",
    L"Highlight key border background alpha in virtual keyboard",
    L"Text color for popup hint in virtual keyboard",
    L"Disable image of large key in dialing screen",
    L"Information bar background filler",
    L"Date and time focussed filler in inline",
    L"Date and time unfocussed filler in inline",
    L"Cascade menu highlight left arrow image",
    L"Cascade menu highlight right arrow image",
    L"Subject color in UCE screen",
    L"Alpha for the background of readonly inline multiline",
    L"Color for the background of readonly inline multiline",
    L"Disabled left arrow image for cascading menu",
    L"Disabled right arrow image for cascading menu",
    L"The image of pre button in UCE screen",
    L"The disabled image of pre button in UCE screen",
    L"The image of next button in UCE screen",
    L"The disabled image of next button in UCE screen",
    L"Left area filler for normal tab",
    L"Right area filler for normal tab",
    L"Left area filler for highlight tab",
    L"Right area filler for highlight tab",
    L"Left area filler for blink tab",
    L"Right area filler for blink tab",
    L"Color for the icon bar item's text in its normal state",
    L"Color for the icon bar item's text in its disabled state",
    L"The image of icon bar left round corner item's background in its normal up state",
    L"The image of icon bar left round corner item's background in its press down state",
    L"The image of icon bar right round corner item's background in its normal up state",
    L"The image of icon bar right round corner item's background in its press down state",
    L"The image of icon bar left-right round corner item's background in its normal up state",
    L"The image of icon bar left-right round corner item's  background in its press down state",
    L"The image of icon bar no round corner item's background in its normal up state",
    L"The image of icon bar no round corner item's background in its press down state",
    L"The title text color of idle calendar",
    L"Idle calendar's cell text color for those cells that have event. ",
    L"The area filler of DOW normal background",
    L"The area filler of DOW highlight background",
    L"The area filler of DOW cell selected background when DOW is in normal state",
    L"The area filler of DOW cell selected background when DOW is in focus state",
    L"The area filler of DOW cell highlight background when DOW is in focus state",
    L"The background image of FTE popup cell. It now is used in calendar date cell.",
    L"Image of selected index of color select item",
    L"Background image of color select item when it is highlighted",
    L"Background image of color select item when it is unhighlighted",
    L"Left arrow image when it is pressed down",
    L"Right arrow image when it is pressed down",
    L"The candidate box background of small size",
    L"The candidate box background of medium size",
    L"The candidate box background of large size",
    L"The candidate box focus frame of small size",
    L"The candidate box focus frame of medium size",
    L"The candidate box focus frame of large size",
    L"The candidates separator line of small size",
    L"The candidates separator line of medium size",
    L"The candidates separator line of large size",
    L"The pressed left arrow of small size",
    L"The pressed left arrow of medium size",
    L"The pressed left arrow of large size",
    L"The normal left arrow of small size",
    L"The normal left arrow of medium size",
    L"The normal left arrow of large size",
    L"The disabled left arrow of small size",
    L"The disabled left arrow of medium size",
    L"The disabled left arrow of large size",
    L"The pressed right arrow of small size",
    L"The pressed right arrow of medium size",
    L"The pressed right arrow of large size",
    L"The normal right arrow of small size",
    L"The normal right arrow of medium size",
    L"The normal right arrow of large size",
    L"The disabled right arrow of small size",
    L"The disabled right arrow of medium size",
    L"The disabled right arrow of large size",
    L"The focused candidate highlight background of small size",
    L"The focused candidate highlight background of medium size",
    L"The focused candidate highlight background of large size",
    L"The unfocused candidate highlight background of small size",
    L"The unfocused candidate highlight background of medium size",
    L"The unfocused candidate highlight background of large size",
    L"The input box background of small size",
    L"The input box background of medium size",
    L"The input box background of large size",
    L"Thin vertical scrollbar image",
    L"Thin horizontal scrollbar image",
    L"Wider vertical scrollbar top button image",
    L"Wider vertical scrollbar top clicked button image",
    L"Wider vertical scrollbar bottom button image",
    L"Wider vertical scrollbar bottom clicked button image",
    L"Wider vertical scrollbar middle background image",
    L"Wider vertical scrollbar scroll button image",
    L"Wider vertical scrollbar scroll clicked button image",
    L"Wider horizontal scrollbar left button image",
    L"Wider horizontal scrollbar left clicked button image",
    L"Wider horizontal scrollbar right button image",
    L"Wider horizontal scrollbar right clicked button image",
    L"Wider horizontal scrollbar middle background image",
    L"Wider horizontal scrollbar scroll button image",
    L"Wider horizontal scrollbar scroll clicked button image",
    L"Slide bar background image",
    L"Slide bar indicator image",
    L"Tab bar left button image",
    L"Tab bar right button image",
    L"All Editor default text color",
    L"Clipboard floating menu 1 button normal image normal background(Unpressed) ",
    L"Clipboard floating menu 1 button normal image press down background ",
    L"Clipboard floating menu left button of 2 button normal image background (Unpressed)",
    L"Clipboard floating menu left button of 2 button pressed down image background",
    L"Clipboard floating menu right button of 2 button normal image background (Unpressed)",
    L"Clipboard floating menu right button of 2 button pressed down image background",
    L"Clipboard floating menu middle button of 3 button normal image background (Unpressed)",
    L"Clipboard floating menu middle button of 3 button pressed down image background",
    L"Clipboard floating menu down arrow normal image background",
    L"Clipboard floating menu down arrow pressed down image background",
    L"Clipboard floating menu text color",
    L"Editor remaining counter background",
    L"All Editor highlighter alpha",
    L"Color for the icon bar item's text border in its normal state",
    L"Color for the icon bar item's text border in its disabled state",
    L"Text border color of down softkey",
    L"Text border color of disabled softkey",
    L"Call manager screen text border color",
    L"The text color of the highlight item of the unfocused candidate box",
    L"Slide bar focused background image",
    L"Slide bar focused indicator image",
    L"Horizontal select normal background filler",
    L"Horizontal select focused background filler",
    L"Progress bar highlight background filler",
    L"Progress bar unhighlight background filler",
    L"Progress bar foreground filler when using gradient style",
    L"Progress bar foreground filler when using non-gradient style",
    L"Progress bar step filler",
    L"Progress bar slider pressed filler",
    L"Progress bar slider normal filler",
    L"Progress bar text color ",
    L"Display only item's background when showed as read only item",
    L"Button's highlighted filler when button item in its pressed down state",
    L"Button's highlighted filler when button item in its normal state",
    L"Button's unhighlighted filler when button item in its pressed down state",
    L"Button's unhighlighted filler when button item in its normal state",
    L"Text edit background filler showed when text edit item is highlighted",
    L"Text edit background filler showed when text edit item is not highlighted",
    L"Clipboard floating menu up arrow normal image background",
    L"Clipboard floating menu up arrow pressed down image background",
    L"Background filler of current date cell in calendar",
    L"Background filler of current date cell in idle calendar",
    L"Popup background filler",
    L"Rotated screen popup background filler",
    L"Small screen editor border color",
    L"In the message editor screen, the background of the add recipient button",
    L"In the message editor screen, the text color of the add recipient button",
    L"Single line editor background filler.",
    L"In the stopwatch screen, the active timer text color",
    L"In the stopwatch screen, the inactive timer text color",
    L"Progress bar to show the slide progress",
};


/* theme component GB description */
static const wchar_t *g_mmi_mte_theme_component_description_GB[MMI_MTE_THEME_COMPONENT_NUM] =
{
    L"\x8F93\x5165\x6846\x80CC\x666F\x586B\x5145",
    L"\x6EDA\x52A8\x6761\x80CC\x666F\x586B\x5145",
    L"\x6EDA\x52A8\x6761\x6ED1\x5757\x80CC\x666F\x586B\x5145",
    L"\x6807\x9898\x680F\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145\xFF08\x4EC5\x9650\x0031\x0032\x0038\x0078\x0031\x0032\x0038\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x82E5\x9AD8\x4EAE\x80CC\x666F\x56FE\x957F\x5BBD\x4E0D\x7B26\x5408\x76EE\x524D\x83DC\x5355\x663E\x793A\x9700\x6C42\x0029",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x65E5\x671F\x65F6\x95F4\x8F93\x5165\x6846\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x65E5\x671F\x65F6\x95F4\x8F93\x5165\x6846\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x901A\x7528\x80CC\x666F\x586B\x5145\xFF0C\x7528\x4E8E\x6587\x672C\x548C\x56FE\x7247\x7684\x80CC\x666F\xFF0C\x901A\x5E38\x4E3A\x767D\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x63D0\x793A\x5B57\x4E32\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x80CC\x666F\x586B\x5145\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x65E0\x8FB9\x6846\x80CC\x666F\x586B\x5145",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x7F16\x8F91\x6846\x80CC\x666F\x586B\x5145",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x754C\x9762\x80CC\x666F\x586B\x5145",
    L"\x65E5\x671F\x65F6\x95F4\x548C\x72B6\x6001\x680F\x0031\x7684\x80CC\x666F\x586B\x5145",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x80CC\x666F\x586B\x5145",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x80CC\x666F\x586B\x5145",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x754C\x9762\x6807\x51C6\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x754C\x9762\x80CC\x666F\x8FB9\x6846\x586B\x5145",
    L"\x663E\x793A\x754C\x9762\x7684\x6D45\x80CC\x666F\x8272\xFF0C\x7528\x4E8E\x6CA1\x6709\x80CC\x666F\x56FE\x7247\x7684\x60C5\x51B5\xFF08\x5982\xFF1A\x0057\x0041\x0050\xFF0C\x004A\x0061\x0076\x0061\xFF09",
    L"\x5DE6\x8F6F\x952E\x6807\x51C6\x72B6\x6001\x6587\x672C\x8272",
    L"\x5DE6\x8F6F\x952E\x6309\x4E0B\x72B6\x6001\x6587\x672C\x8272",
    L"\x5DE6\x8F6F\x952E\x7981\x7528\x72B6\x6001\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x53F3\x8F6F\x952E\x6807\x51C6\x72B6\x6001\x6587\x672C\x8272",
    L"\x53F3\x8F6F\x952E\x6309\x4E0B\x72B6\x6001\x6587\x672C\x8272",
    L"\x53F3\x8F6F\x952E\x7981\x7528\x72B6\x6001\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x8F93\x5165\x6846\x6807\x51C6\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x9AD8\x4EAE\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x6807\x9898\x6587\x672C\x8272",
    L"\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x6807\x51C6\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x683C\x5F0F\x5316\x8F93\x5165\x6846\x5149\x6807\x989C\x8272",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C",
    L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x6807\x51C6\xFF08\x975E\x9AD8\x4EAE\xFF09\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x7981\x7528\x83DC\x5355\x9879\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x5217\x8868\x5F0F\x83DC\x5355\x63D0\x793A\x6587\x672C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x6587\x672C\x989C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65E5\x671F\x65F6\x95F4\x80CC\x666F\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x901A\x8BDD\x65F6\x95F4\x80CC\x666F\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65E5\x671F\x6587\x672C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x65F6\x95F4\x6587\x672C\x8272",
    L"\x901A\x8BDD\x8BB0\x5F55\x754C\x9762\x901A\x8BDD\x65F6\x95F4\x6587\x672C\x8272",
    L"\x8BA1\x8D39\x4FE1\x606F\x7684\x6587\x672C\x8272",
    L"\x4FE1\x606F\x680F\x80CC\x666F\x8272",
    L"\x8F93\x5165\x6CD5\x6587\x672C\x8272",
    L"\x8F93\x5165\x6846\x7684\x5269\x4F59\x5B57\x6570\x7EDF\x8BA1\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x975E\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x53EF\x7F16\x8F91\x5355\x884C\x5217\x8868\x9879\x5149\x6807\x586B\x5145\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x6807\x51C6\x6587\x672C\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x9AD8\x4EAE\x6587\x672C\x8272",
    L"\x53EF\x8F93\x5165\x5217\x8868\x5F0F\x83DC\x5355\x83DC\x5355\x9879\x7981\x7528\x6587\x672C\x8272\xFF08\x8F83\x5C11\x4F7F\x7528\xFF09",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x6587\x672C\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x0050\x0049\x004E\x0020\x7801\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x6587\x672C\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x88AB\x9009\x4E2D\x6587\x672C\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x9009\x4E2D\x9AD8\x4EAE\x8272",
    L"\x62E8\x53F7\x8F93\x5165\x6846\x5149\x6807\x586B\x5145\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x88AB\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x672A\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x53D8\x97F3\x7B26\x53F7\x88AB\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x53D8\x97F3\x7B26\x53F7\x672A\x9009\x4E2D\x65F6\x7684\x6587\x672C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x663E\x793A\x533A\x57DF\x7684\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x671F\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65F6\x95F4\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x671F\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x65F6\x95F4\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x540D\x79F0\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x540D\x79F0\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x72B6\x6001\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x72B6\x6001\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x5176\x4F59\x6587\x672C\x8272\xFF0C\x5982\x6B63\x5728\x64AD\x653E\x7684\x0020\x004D\x0050\x0033\x0020\x6B4C\x66F2\x540D\x79F0",
    L"\x5F85\x673A\x754C\x9762\x7F51\x7EDC\x5176\x4F59\x6587\x672C\x8FB9\x6846\x8272\xFF0C\x5982\x6B63\x5728\x64AD\x653E\x7684\x0020\x004D\x0050\x0033\x0020\x6B4C\x66F2\x540D\x79F0",
    L"\x5782\x76F4\x6EDA\x52A8\x6761\x7684\x5BBD\x5EA6\x6216\x8005\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x9AD8\x5EA6",
    L"\x753B\x9762\x7684\x5168\x4E0D\x900F\x660E\x5EA6",
    L"\x753B\x9762\x7684\x9AD8\x4E0D\x900F\x660E\x5EA6\xFF08\x672A\x4F7F\x7528\xFF09",
    L"\x753B\x9762\x7684\x4E2D\x4E0D\x900F\x660E\x5EA6\xFF08\x672A\x4F7F\x7528\xFF09",
    L"\x753B\x9762\x7684\x4F4E\x4E0D\x900F\x660E\x5EA6\xFF08\x5728\x7F16\x8F91\x5668\x91CC\x4F7F\x7528\xFF09",
    L"\x5355\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x53CC\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x591A\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x5BBD\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x6709\x6807\x7B7E\x9875\x7684\x5BBD\x83DC\x5355\x9879\x7684\x80CC\x666F\x586B\x5145\xFF08\x53EA\x5728\x0020\x0034\x0032\x0035\x0020\x53F7\x7C7B\x522B\x6709\x6548\xFF0C\x0020\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x7B26\x53F7\x9009\x62E9\x753B\x9762\x9AD8\x4EAE\x7684\x586B\x5145",
    L"\x77E9\x9635\x83DC\x5355\x80CC\x666F\x586B\x5145",
    L"\x4E3B\x83DC\x5355\x7684\x80CC\x666F\x586B\x5145",
    L"\x5B50\x83DC\x5355\x7684\x80CC\x666F\x586B\x5145",
    L"\x5F85\x673A\x754C\x9762\x7684\x80CC\x666F\x586B\x5145\xFF08\x5C06\x5899\x7EB8\x8BBE\x4E3A\x4E3B\x9898\x56FE\x7247\x4EE5\x663E\x793A\xFF09",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65E5\x671F\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6570\x5B57\x65F6\x949F\x65F6\x95F4\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x5C0F\x65F6\x6307\x9488\x7684\x989C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x5206\x949F\x6307\x9488\x7684\x989C\x8272",
    L"\x65F6\x949F\x7EC4\x4EF6\xFF1A\x4E3B\x5C4F\x6A21\x62DF\x65F6\x949F\x8F74\x7EBF\x7684\x989C\x8272\xFF08\x5C06\x5899\x7EB8\x8BBE\x4E3A\x6A21\x62DF\x65F6\x949F\x4EE5\x663E\x793A\xFF09",
    L"\x8F6F\x952E\x533A\x6587\x672C\x8FB9\x6846\x8272",
    L"\x8F6F\x952E\x533A\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x6807\x9898\x6587\x672C\x8272",
    L"\x6807\x7B7E\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x6807\x7B7E\x6807\x9898\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x65E5\x5386\x6807\x9898\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5E74\x4EFD\x002F\x6708\x4EFD\x9009\x62E9\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5E74\x4EFD\x002F\x6708\x4EFD\x9009\x62E9\x5BF9\x5E94\x6587\x672C\x8FB9\x6846\x8272",
    L"\x65E5\x5386\x4E2D\x7B2C\x51E0\x5468\xFF08\x6708\x89C6\x56FE\xFF09\x002F\x7B2C\x51E0\x5C0F\x65F6\xFF08\x5468\x89C6\x56FE\xFF09\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x661F\x671F\x51E0\x5BF9\x5E94\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x5355\x4EFB\x52A1\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x591A\x4EFB\x52A1\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x751F\x7406\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x53D7\x5B55\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x5371\x9669\x671F\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x65E0\x5371\x9669\x5BF9\x5E94\x5355\x5143\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4E2D\x6709\x6548\x5355\x5143\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x65E0\x6548\x5355\x5143\x6587\x672C\x8272",
    L"\x65E5\x5386\x4E2D\x9AD8\x4EAE\x6846\x7684\x989C\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x4E2D\x6BCF\x9879\x7684\x80CC\x666F\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x6587\x672C\x8272",
    L"\x72B6\x6001\x680F\x80CC\x666F\x586B\x5145",
    L"\x5927\x6807\x9898\x80CC\x666F\x586B\x5145",
    L"\x5927\x6807\x9898\x6587\x672C\x8272",
    L"\x5927\x6807\x9898\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5927\x6807\x9898\x5FEB\x6377\x65B9\x5F0F\x6587\x672C\x8272",
    L"\x65CB\x8F6C\x540E\x753B\x9762\x7684\x80CC\x666F\x586B\x5145",
    L"\x65CB\x8F6C\x540E\x753B\x9762\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x5217\x8868\x754C\x9762\x6807\x9898\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x680F\x6B63\x5E38\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x680F\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145",
    L"\x6807\x7B7E\x680F\x95EA\x70C1\x7684\x80CC\x666F\x586B\x5145",
    L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355\x6807\x7B7E\x7684\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355\x9AD8\x4EAE\x7684\x56FE\x7247",
    L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355\x6807\x7B7E\x7684\x6B63\x5E38\x80CC\x666F\x586B\x5145",
    L"\x5217\x8868\x6846\x5206\x9694\x7EBF\x7684\x989C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x5206\x9694\x7EBF\x7684\x989C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x6B63\x5E38\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x65E0\x6548\x83DC\x5355\x9879\x6587\x672C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x8FB9\x6846\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x80CC\x666F\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x83DC\x5355\x9879\x7684\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x5DE6\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x53F3\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x591A\x9009\x5217\x8868\x91CC\x8868\x793A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x591A\x9009\x5217\x8868\x91CC\x8868\x793A\x672A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x5355\x9009\x5217\x8868\x91CC\x8868\x793A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x5355\x9009\x5217\x8868\x91CC\x8868\x793A\x672A\x88AB\x9009\x4E2D\x7684\x56FE\x6807",
    L"\x6C34\x5E73\x9009\x62E9\x7EC4\x4EF6\x5DE6\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x6C34\x5E73\x9009\x62E9\x7EC4\x4EF6\x53F3\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x7F16\x8F91\x5668\x57FA\x7EBF\x7684\x7EBF\x6761\x989C\x8272",
    L"\x0045\x004D\x0053\x0020\x7F16\x8F91\x5668\x6587\x5B57\x57FA\x7EBF\x7684\x7EBF\x6761\x989C\x8272",
    L"\x62E8\x53F7\x7F16\x8F91\x5668\x6587\x672C\x8272",
    L"\x62E8\x53F7\x7F16\x8F91\x5668\x6587\x672C\x8FB9\x6846\x8272",
    L"\x5DE6\x8F6F\x952E\x6309\x4E0B\x65F6\x7684\x586B\x5145",
    L"\x5DE6\x8F6F\x952E\x5F39\x8D77\x65F6\x7684\x586B\x5145",
    L"\x53F3\x8F6F\x952E\x6309\x4E0B\x65F6\x7684\x586B\x5145",
    L"\x53F3\x8F6F\x952E\x5F39\x8D77\x65F6\x7684\x586B\x5145",
    L"\x65E5\x5386\x65E5\x671F\x5B57\x4E32\x80CC\x666F\x8272",
    L"\x65E5\x5386\x661F\x671F\x5B57\x4E32\x80CC\x666F\x8272",
    L"\x65E5\x5386\x5C0F\x65F6\x5B57\x4E32\x80CC\x666F\x8272",
    L"\x65E5\x5386\x65E5\x671F\x6570\x636E\x80CC\x666F\x8272",
    L"\x65E5\x5386\x65E5\x671F\x533A\x57DF\x5916\x8FB9\x6846\x8272",
    L"\x65E5\x5386\x65E5\x671F\x533A\x57DF\x5206\x9694\x7EBF\x8272",
    L"\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x6587\x672C\x8272",
    L"\x65E5\x5386\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x6587\x672C\x8272",
    L"\x65E5\x5386\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x80CC\x666F\x8272",
    L"\x65E5\x5386\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x8FB9\x6846\x8272",
    L"\x65E5\x5386\x4FE1\x606F\x6846\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x65E5\x5386\x65E5\x671F\x5B57\x4E32\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x65E5\x5386\x661F\x671F\x5B57\x4E32\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x65E5\x5386\x5C0F\x65F6\x5B57\x4E32\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x65E5\x5386\x65E5\x671F\x6570\x636E\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x65E5\x5386\x65E5\x671F\x533A\x57DF\x6846\x7EBF\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x5B57\x4E32\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x5B57\x4E32\x80CC\x666F\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x6708\x6709\x6548\x65E5\x671F\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x6708\x65E0\x6548\x65E5\x671F\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x663E\x793A\x533A\x57DF\x80CC\x666F\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x6587\x672C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x8FB9\x6846\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x533A\x57DF\x5916\x8FB9\x6846\x7EBF\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x533A\x57DF\x65E5\x671F\x5206\x9694\x7EBF\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x661F\x671F\x5B57\x4E32\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x663E\x793A\x533A\x57DF\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x80CC\x666F\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x8FB9\x6846\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x533A\x57DF\x5916\x8FB9\x6846\x7EBF\x900F\x660E\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x65E5\x671F\x533A\x57DF\x65E5\x671F\x5206\x9694\x7EBF\x900F\x660E\x5EA6",
    L"\x6307\x793A\x7BAD\x5934\x7684\x989C\x8272",
    L"\x6307\x793A\x7BAD\x5934\x7684\x8FB9\x6846\x989C\x8272",
    L"\x5F85\x673A\x754C\x9762\x4E0A\x0020\x0044\x0043\x0044\x0020\x533A\x57DF\x7684\x80CC\x666F\x56FE\x7247",
    L"\x5F85\x673A\x754C\x9762\x4E0A\x0020\x0044\x0043\x0044\x0020\x533A\x57DF\x4E2D\x5DF2\x7ECF\x88AB\x8BFB\x8FC7\x7684\x6761\x76EE\x7684\x5B57\x4F53\x989C\x8272",
    L"\x5F85\x673A\x754C\x9762\x4E0A\x0020\x0044\x0043\x0044\x0020\x533A\x57DF\x4E2D\x672A\x88AB\x8BFB\x8FC7\x7684\x6761\x76EE\x7684\x5B57\x4F53\x989C\x8272",
    L"\x0044\x0043\x0044\x0020\x9891\x9053\x5217\x8868\x754C\x9762\x4E2D\x88AB\x9009\x4E2D\x7684\x9891\x9053\x9879\x7684\x80CC\x666F\x56FE\x7247",
    L"\x0044\x0043\x0044\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762\x4E2D\x9891\x9053\x9879\x5185\x5BB9\x7684\x5B57\x4F53\x989C\x8272",
    L"\x0044\x0043\x0044\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762\x4E2D\x6D4F\x89C8\x8FC7\x7684\x0055\x0052\x004C\x7684\x5B57\x4F53\x989C\x8272",
    L"\x0044\x0043\x0044\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762\x4E2D\x672A\x6D4F\x89C8\x8FC7\x7684\x0055\x0052\x004C\x7684\x5B57\x4F53\x989C\x8272",
    L"\x0044\x0043\x0044\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762\x4E2D\x88AB\x9009\x4E2D\x7684\x0055\x0052\x004C\x7684\x80CC\x666F\x989C\x8272",
    L"\x0053\x0049\x004D\x0032\x0020\x7F51\x7EDC\x540D\x5B57\x4F53\x989C\x8272",
    L"\x0053\x0049\x004D\x0032\x0020\x7F51\x7EDC\x540D\x8FB9\x6846\x989C\x8272",
    L"\x0053\x0049\x004D\x0032\x0020\x7F51\x7EDC\x72B6\x6001\x5B57\x4F53\x989C\x8272",
    L"\x0053\x0049\x004D\x0032\x0020\x7F51\x7EDC\x72B6\x6001\x8FB9\x6846\x989C\x8272",
    L"\x5168\x9AD8\x5EA6\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x80CC\x666F\x586B\x5145",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x5185\x5BB9\x63D0\x793A\x5B57\x4F53\x989C\x8272",
    L"\x4E3B\x83DC\x5355\x4E2D\x6807\x9898\x680F\x7684\x6587\x672C\x989C\x8272",
    L"\x4E3B\x83DC\x5355\x4E2D\x6807\x9898\x680F\x7684\x8FB9\x6846\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x4E0B\x5212\x7EBF\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x62FC\x97F3\x6B67\x4E49\x6807\x8BC6\x7684\x989C\x8272",
    L"\x7126\x70B9\x533A\x57DF\x80CC\x666F",
    L"\x975E\x7126\x70B9\x533A\x57DF\x80CC\x666F",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x7126\x70B9\x533A\x57DF\x8FB9\x6846\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x975E\x7126\x70B9\x533A\x57DF\x8FB9\x6846\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x5206\x9694\x7EBF\x5BBD\x5EA6",
    L"\x975E\x7126\x70B9\x5019\x9009\x5B57\x533A\x57DF\x5206\x9694\x7EBF\x989C\x8272",
    L"\x7126\x70B9\x5019\x9009\x5B57\x533A\x57DF\x5206\x9694\x7EBF\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x5019\x9009\x5B57\x95F4\x9694",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x5019\x9009\x5B57\x6807\x53F7\x7684\x989C\x8272",
    L"\x8F93\x5165\x6CD5\x7F16\x8F91\x5668\x4E2D\x5149\x6807\x7684\x989C\x8272",
    L"\x7981\x7528\x7684\x7BAD\x5934\x989C\x8272",
    L"\x6309\x4E0B\x7684\x7BAD\x5934\x989C\x8272",
    L"\x666E\x901A\x72B6\x6001\x4E0B\x7684\x7BAD\x5934\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x666E\x901A\x5019\x9009\x5B57\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x9AD8\x4EAE\x5019\x9009\x5B57\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x9AD8\x4EAE\x77E9\x5F62\x533A\x57DF\x989C\x8272",
    L"\x62FC\x97F3\x002F\x6CE8\x97F3\x533A\x57DF\x666E\x901A\x5019\x9009\x5B57\x989C\x8272",
    L"\x62FC\x97F3\x002F\x6CE8\x97F3\x533A\x57DF\x9AD8\x4EAE\x5019\x9009\x5B57\x989C\x8272",
    L"\x62FC\x97F3\x002F\x6CE8\x97F3\x533A\x57DF\x9AD8\x4EAE\x77E9\x5F62\x533A\x57DF\x989C\x8272",
    L"\x8F93\x5165\x533A\x57DF\x666E\x901A\x5B57\x7B26\x989C\x8272",
    L"\x8F93\x5165\x533A\x57DF\x9AD8\x4EAE\x5B57\x7B26\x989C\x8272",
    L"\x8F93\x5165\x533A\x57DF\x9AD8\x4EAE\x77E9\x5F62\x533A\x57DF\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x666E\x901A\x90E8\x9996\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x9AD8\x4EAE\x90E8\x9996\x989C\x8272",
    L"\x5019\x9009\x5B57\x533A\x57DF\x90E8\x9996\x9AD8\x4EAE\x77E9\x5F62\x533A\x57DF\x989C\x8272",
    L"\x7279\x6B8A\x6807\x7B7E\x9875\x7684\x80CC\x666F",
    L"\x5C0F\x6307\x793A\x9875\x80CC\x666F\x989C\x8272",
    L"\x5C0F\x6307\x793A\x9875\x989C\x8272",
    L"\x5C0F\x6307\x793A\x9875\x9AD8\x4EAE\x989C\x8272",
    L"\x5A92\x4F53\x64AD\x653E\x5668\x6587\x672C\x989C\x8272",
    L"\x5A92\x4F53\x64AD\x653E\x5668\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x4E24\x884C\x5217\x8868\x7B2C\x4E00\x884C\x6587\x672C\x989C\x8272",
    L"\x4E24\x884C\x5217\x8868\x7B2C\x4E00\x884C\x6587\x672C\x9AD8\x4EAE\x989C\x8272",
    L"\x4E24\x884C\x5217\x8868\x7B2C\x4E8C\x884C\x6587\x672C\x989C\x8272",
    L"\x4E24\x884C\x5217\x8868\x7B2C\x4E8C\x884C\x6587\x672C\x9AD8\x4EAE\x989C\x8272",
    L"\x4E24\x884C\x9009\x62E9\x5217\x8868\x7B2C\x4E8C\x884C\x80CC\x666F",
    L"\x4E24\x884C\x9009\x62E9\x5217\x8868\x7B2C\x4E8C\x884C\x6587\x672C\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E00\x884C\x6587\x672C\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E00\x884C\x6587\x672C\x9AD8\x4EAE\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E8C\x884C\x6587\x672C\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E8C\x884C\x6587\x672C\x9AD8\x4EAE\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E09\x884C\x6587\x672C\x989C\x8272",
    L"\x591A\x884C\x5217\x8868\x7B2C\x4E09\x884C\x6587\x672C\x9AD8\x4EAE\x989C\x8272",
    L"\x5217\x8868\x5206\x5272\x7EBF\x989C\x8272",
    L"\x5217\x8868\x5206\x5272\x7EBF\x901A\x900F\x5EA6",
    L"\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x5355\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x53CC\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x591A\x884C\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x5BBD\x83DC\x5355\x9879\x9AD8\x4EAE\x7684\x80CC\x666F\x586B\x5145\xFF08\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x6709\x6807\x7B7E\x9875\x7684\x5BBD\x83DC\x5355\x9879\x7684\x80CC\x666F\x586B\x5145\xFF08\x53EA\x5728\x0020\x0034\x0032\x0035\x0020\x53F7\x7C7B\x522B\x6709\x6548\xFF0C\x0020\x82E5\x4F7F\x7528\x56FE\xFF0C\x56FE\x7684\x957F\x5BBD\x5FC5\x987B\x4E0E\x63A8\x8350\x957F\x5BBD\x4E00\x81F4\xFF0C\x0039\x0073\x006C\x0069\x0063\x0065\x9664\x5916\xFF09",
    L"\x62E8\x53F7\x754C\x9762\x80CC\x666F",
    L"\x62E8\x53F7\x754C\x9762\x5C0F\x6309\x952E\x56FE\x7247",
    L"\x62E8\x53F7\x754C\x9762\x5C0F\x6309\x952E\x6309\x4E0B\x56FE\x7247",
    L"\x62E8\x53F7\x754C\x9762\x5927\x6309\x952E\x56FE\x7247",
    L"\x62E8\x53F7\x754C\x9762\x5927\x6309\x952E\x6309\x4E0B\x56FE\x7247",
    L"\x7F51\x7EDC\x7535\x8BDD\x62E8\x53F7\x754C\x9762\x7F16\x8F91\x6846\x6587\x672C\x989C\x8272",
    L"\x9876\x90E8\x4FE1\x606F\x6846\x6587\x672C\x989C\x8272",
    L"\x5F39\x51FA\x5F0F\x7535\x8BDD\x754C\x9762\x80CC\x666F",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x5DE6\x8F6F\x952E\x80CC\x666F",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x6309\x4E0B\x5DE6\x8F6F\x952E\x80CC\x666F",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x53F3\x8F6F\x952E\x80CC\x666F",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x6309\x4E0B\x53F3\x8F6F\x952E\x80CC\x666F",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x8F6F\x952E\x989C\x8272",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x8F6F\x952E\x8FB9\x6846\x989C\x8272",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x8F6F\x952E\x80CC\x666F",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x7684\x9AD8\x4EAE\x80CC\x666F",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x7684\x9AD8\x4EAE\x6587\x672C\x989C\x8272",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x7684\x6587\x672C\x989C\x8272",
    L"\x65E5\x7A0B\x4E2D\x5F53\x524D\x5929\x989C\x8272",
    L"\x65E5\x7A0B\x4E2D\x5F53\x524D\x65E5\x671F\x989C\x8272",
    L"\x65E5\x7A0B\x4FE1\x606F\x680F\x4E2D\x6761\x76EE\x7684\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x5F85\x673A\x754C\x9762\x65E5\x7A0B\x80CC\x666F",
    L"\x56FE\x6807\x680F\x63D0\x793A\x989C\x8272",
    L"\x56FE\x6807\x680F\x63D0\x793A\x80CC\x666F",
    L"\x5B57\x6BCD\x8868\x680F\x9AD8\x4EAE\x989C\x8272",
    L"\x5B57\x6BCD\x8868\x680F\x9AD8\x4EAE\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x7F6E\x7070\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x7F6E\x7070\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x7F6E\x7070\x6587\x672C\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x5DE6\x5927\x56FE\x6807\x0028\x8BF7\x540C\x65F6\x4FEE\x6539\x0076\x0069\x0072\x0074\x0075\x0061\x006C\x005F\x006B\x0065\x0079\x0062\x006F\x0061\x0072\x0064\x005F\x006B\x0065\x0079\x005F\x006C\x0061\x0072\x0067\x0065\x005F\x0069\x0063\x006F\x006E\x005F\x006C\x0065\x0066\x0074\x005F\x0069\x006D\x0061\x0067\x0065\x548C\x0076\x0069\x0072\x0074\x0075\x0061\x006C\x005F\x006B\x0065\x0079\x0062\x006F\x0061\x0072\x0064\x005F\x006B\x0065\x0079\x005F\x006C\x0061\x0072\x0067\x0065\x005F\x0069\x0063\x006F\x006E\x005F\x0072\x0069\x0067\x0068\x0074\x005F\x0069\x006D\x0061\x0067\x0065\xFF0C\x5426\x5219\x5927\x56FE\x6807\x65E0\x6CD5\x663E\x793A\x0029",
    L"\x865A\x62DF\x952E\x76D8\x53F3\x5927\x56FE\x6807\x0028\x8BF7\x540C\x65F6\x4FEE\x6539\x0076\x0069\x0072\x0074\x0075\x0061\x006C\x005F\x006B\x0065\x0079\x0062\x006F\x0061\x0072\x0064\x005F\x006B\x0065\x0079\x005F\x006C\x0061\x0072\x0067\x0065\x005F\x0069\x0063\x006F\x006E\x005F\x006C\x0065\x0066\x0074\x005F\x0069\x006D\x0061\x0067\x0065\x548C\x0076\x0069\x0072\x0074\x0075\x0061\x006C\x005F\x006B\x0065\x0079\x0062\x006F\x0061\x0072\x0064\x005F\x006B\x0065\x0079\x005F\x006C\x0061\x0072\x0067\x0065\x005F\x0069\x0063\x006F\x006E\x005F\x0072\x0069\x0067\x0068\x0074\x005F\x0069\x006D\x0061\x0067\x0065\xFF0C\x5426\x5219\x5927\x56FE\x6807\x65E0\x6CD5\x663E\x793A\x0029",
    L"\x4FE1\x606F\x680F\x901A\x900F\x5EA6",
    L"\x7279\x6B8A\x754C\x9762\x80CC\x666F",
    L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355\x6CA1\x6709\x6EDA\x52A8\x6761\x7684\x9AD8\x4EAE\x80CC\x666F",
    L"\x865A\x62DF\x952E\x76D8\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x8FB9\x6846\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x6309\x952E\x8FB9\x6846\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x65E0\x6548\x6309\x952E\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x65E0\x6548\x6309\x952E\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x65E0\x6548\x6309\x952E\x8FB9\x6846\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x65E0\x6548\x6309\x952E\x8FB9\x6846\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x9AD8\x4EAE\x6309\x952E\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x9AD8\x4EAE\x6309\x952E\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x9AD8\x4EAE\x6309\x952E\x8FB9\x6846\x80CC\x666F\x989C\x8272",
    L"\x865A\x62DF\x952E\x76D8\x9AD8\x4EAE\x6309\x952E\x8FB9\x6846\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x865A\x62DF\x952E\x76D8\x5F39\x51FA\x63D0\x793A\x6587\x672C\x989C\x8272",
    L"\x62E8\x53F7\x754C\x9762\x5927\x6309\x952E\x65E0\x6548\x56FE\x6807",
    L"\x8F93\x5165\x6CD5\x63D0\x793A\x4FE1\x606F\x80CC\x666F",
    L"\x65F6\x95F4\x65E5\x671F\x7126\x70B9\x586B\x5145",
    L"\x65F6\x95F4\x65E5\x671F\x975E\x7126\x70B9\x586B\x5145",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x5DE6\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x9AD8\x4EAE\x53F3\x7BAD\x5934\x7684\x56FE\x7247",
    L"\x0055\x0043\x0045\x4E2D\x6807\x9898\x6587\x672C\x989C\x8272",
    L"\x5728\x4F4D\x7F16\x8F91\x591A\x884C\x53EA\x8BFB\x6587\x672C\x6846\x80CC\x666F\x901A\x900F\x5EA6",
    L"\x5728\x4F4D\x7F16\x8F91\x591A\x884C\x53EA\x8BFB\x6587\x672C\x6846\x80CC\x666F\x989C\x8272",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x65E0\x6548\x5DE6\x7BAD\x5934\x56FE",
    L"\x5C42\x53E0\x5F0F\x83DC\x5355\x65E0\x6548\x53F3\x7BAD\x5934\x56FE",
    L"\x0055\x0043\x0045\x4E2D\x5411\x524D\x6309\x94AE\x56FE",
    L"\x0055\x0043\x0045\x4E2D\x65E0\x6548\x5411\x524D\x6309\x94AE\x56FE",
    L"\x0055\x0043\x0045\x4E2D\x5411\x540E\x6309\x94AE\x56FE",
    L"\x0055\x0043\x0045\x4E2D\x65E0\x6548\x5411\x540E\x6309\x94AE\x56FE",
    L"\x6807\x7B7E\x680F\x5DE6\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x6807\x7B7E\x680F\x53F3\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x9AD8\x4EAE\x6807\x7B7E\x680F\x5DE6\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x9AD8\x4EAE\x6807\x7B7E\x680F\x53F3\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x95EA\x70C1\x6807\x7B7E\x680F\x5DE6\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x95EA\x70C1\x6807\x7B7E\x680F\x53F3\x4FA7\x533A\x57DF\x80CC\x666F",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x6587\x672C\x989C\x8272",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x7981\x7528\x72B6\x6001\x6587\x672C\x989C\x8272",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x5DE6\x90E8\x5706\x89D2\x6309\x94AE\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x5DE6\x90E8\x5706\x89D2\x6309\x94AE\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x53F3\x90E8\x5706\x89D2\x6309\x94AE\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x53F3\x90E8\x5706\x89D2\x6309\x94AE\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x5DE6\x53F3\x5706\x89D2\x6309\x94AE\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x5DE6\x53F3\x5706\x89D2\x6309\x94AE\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x65E0\x5706\x89D2\x6309\x94AE\x80CC\x666F\x56FE\x7247",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x65E0\x5706\x89D2\x6309\x94AE\x6309\x4E0B\x72B6\x6001\x80CC\x666F\x56FE\x7247",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x7684\x6807\x9898\x6587\x672C\x989C\x8272",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x91CC\x6709\x4E8B\x4EF6\x65E5\x671F\x7684\x6587\x672C\x989C\x8272",
    L"\x0044\x004F\x0057\x80CC\x666F\x586B\x5145",
    L"\x0044\x004F\x0057\x83B7\x5F97\x7126\x70B9\x65F6\x7684\x80CC\x666F\x586B\x5145",
    L"\x0044\x004F\x0057\x6BCF\x65E5\x5728\x9009\x4E2D\x72B6\x6001\x4E0B\x80CC\x666F\x586B\x5145",
    L"\x0044\x004F\x0057\x83B7\x5F97\x7126\x70B9\x65F6\x6BCF\x65E5\x5728\x9009\x4E2D\x72B6\x6001\x4E0B\x80CC\x666F\x586B\x5145",
    L"\x0044\x004F\x0057\x83B7\x5F97\x7126\x70B9\x65F6\x6BCF\x65E5\x5728\x9AD8\x4EAE\x72B6\x6001\x4E0B\x80CC\x666F\x586B\x5145",
    L"\x6309\x952E\x653E\x5927\x6548\x679C\x7684\x80CC\x666F\x56FE\xFF0C\x76EE\x524D\x7528\x4E8E\x0063\x0061\x006C\x0065\x006E\x0064\x0061\x0072\x65E5\x671F\x7684\x653E\x5927",
    L"\x0063\x006F\x006C\x006F\x0072\x0020\x0073\x0065\x006C\x0065\x0063\x0074\x63A7\x4EF6\x9009\x4E2D\x7684\x5185\x5BB9\x7684\x56FE\x7247",
    L"\x0063\x006F\x006C\x006F\x0072\x0020\x0073\x0065\x006C\x0065\x0063\x0074\x63A7\x4EF6\x9AD8\x4EAE\x65F6\x7684\x80CC\x666F\x56FE\x7247",
    L"\x0063\x006F\x006C\x006F\x0072\x0020\x0073\x0065\x006C\x0065\x0063\x0074\x63A7\x4EF6\x975E\x9AD8\x4EAE\x65F6\x7684\x80CC\x666F\x56FE\x7247",
    L"\x0073\x0065\x006C\x0065\x0063\x0074\x63A7\x4EF6\x5DE6\x9009\x62E9\x6309\x94AE\x6309\x4E0B\x65F6\x7684\x56FE\x7247",
    L"\x0073\x0065\x006C\x0065\x0063\x0074\x63A7\x4EF6\x53F3\x9009\x62E9\x6309\x94AE\x6309\x4E0B\x65F6\x7684\x56FE\x7247",
    L"\x5C0F\x5C3A\x5BF8\x5019\x9009\x6846\x80CC\x666F",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x5019\x9009\x6846\x80CC\x666F",
    L"\x5927\x5C3A\x5BF8\x5019\x9009\x6846\x80CC\x666F",
    L"\x5C0F\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x8FB9\x6846",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x8FB9\x6846",
    L"\x5927\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x8FB9\x6846",
    L"\x5C0F\x5C3A\x5BF8\x5019\x9009\x5B57\x5206\x5272\x7EBF",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x5019\x9009\x5B57\x5206\x5272\x7EBF",
    L"\x5927\x5C3A\x5BF8\x5019\x9009\x5B57\x5206\x5272\x7EBF",
    L"\x6309\x4E0B\x7684\x5C0F\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6309\x4E0B\x7684\x4E2D\x7B49\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6309\x4E0B\x7684\x5927\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x5C0F\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x4E2D\x7B49\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x5927\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x7981\x7528\x7684\x5C0F\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x7981\x7528\x7684\x4E2D\x7B49\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x7981\x7528\x7684\x5927\x5C3A\x5BF8\x5DE6\x7BAD\x5934",
    L"\x6309\x4E0B\x7684\x5C0F\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x6309\x4E0B\x7684\x4E2D\x7B49\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x6309\x4E0B\x7684\x5927\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x5C0F\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x4E2D\x7B49\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x6B63\x5E38\x7684\x5927\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x7981\x7528\x7684\x5C0F\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x7981\x7528\x7684\x4E2D\x7B49\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x7981\x7528\x7684\x5927\x5C3A\x5BF8\x53F3\x7BAD\x5934",
    L"\x5C0F\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x5927\x5C3A\x5BF8\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x5C0F\x5C3A\x5BF8\x975E\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x975E\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x5927\x5C3A\x5BF8\x975E\x7126\x70B9\x5019\x9009\x6846\x5019\x9009\x5B57\x9AD8\x4EAE\x80CC\x666F",
    L"\x5C0F\x5C3A\x5BF8\x8F93\x5165\x6846\x80CC\x666F",
    L"\x4E2D\x7B49\x5C3A\x5BF8\x8F93\x5165\x6846\x80CC\x666F",
    L"\x5927\x5C3A\x5BF8\x8F93\x5165\x6846\x80CC\x666F",
    L"\x7EC6\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x7684\x56FE\x7247",
    L"\x7EC6\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x7684\x4E0A\x7BAD\x5934\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x7684\x4E0A\x7BAD\x5934\x88AB\x70B9\x51FB\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x7684\x4E0B\x7BAD\x5934\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x7684\x4E0B\x7BAD\x5934\x88AB\x70B9\x51FB\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x4E2D\x95F4\x90E8\x5206\x7684\x80CC\x666F\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x6EDA\x52A8\x6309\x94AE\x56FE\x7247",
    L"\x7C97\x7684\x7AD6\x76F4\x6EDA\x52A8\x6761\x6EDA\x52A8\x6309\x94AE\x88AB\x70B9\x51FB\x7684\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x5DE6\x7BAD\x5934\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x5DE6\x7BAD\x5934\x88AB\x70B9\x51FB\x7684\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x53F3\x7BAD\x5934\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x7684\x53F3\x7BAD\x5934\x88AB\x70B9\x51FB\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x4E2D\x95F4\x90E8\x5206\x7684\x80CC\x666F\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x6EDA\x52A8\x6309\x94AE\x7684\x56FE\x7247",
    L"\x7C97\x7684\x6C34\x5E73\x6EDA\x52A8\x6761\x6EDA\x52A8\x6309\x94AE\x88AB\x70B9\x51FB\x7684\x56FE\x7247",
    L"\x6ED1\x5757\x7684\x80CC\x666F\x56FE\x7247",
    L"\x5C0F\x6ED1\x5757\x7684\x56FE\x7247",
    L"\x6807\x7B7E\x7684\x5DE6\x7BAD\x5934\x56FE\x7247",
    L"\x6807\x7B7E\x7684\x53F3\x7BAD\x5934\x56FE\x7247",
    L"\x6240\x6709\x7F16\x8F91\x5668\x9ED8\x8BA4\x6587\x672C\x7684\x989C\x8272",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0031\x4E2A\x6309\x94AE\x7684\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0031\x4E2A\x6309\x94AE\x7684\x6309\x4E0B\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0032\x4E2A\x6309\x94AE\x4E2D\x5DE6\x8FB9\x6309\x94AE\x7684\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0032\x4E2A\x6309\x94AE\x4E2D\x5DE6\x8FB9\x6309\x94AE\x7684\x6309\x4E0B\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0032\x4E2A\x6309\x94AE\x4E2D\x53F3\x8FB9\x6309\x94AE\x7684\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0032\x4E2A\x6309\x94AE\x4E2D\x53F3\x8FB9\x6309\x94AE\x7684\x6309\x4E0B\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0033\x4E2A\x6309\x94AE\x4E2D\x4E2D\x95F4\x6309\x94AE\x7684\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x0033\x4E2A\x6309\x94AE\x4E2D\x4E2D\x95F4\x6309\x94AE\x7684\x6309\x4E0B\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x4E0B\x7BAD\x5934\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x4E0B\x7BAD\x5934\x6309\x4E0B\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x6309\x94AE\x4E0A\x7684\x6587\x672C\x989C\x8272",
    L"\x7F16\x8F91\x5668\x6D6E\x52A8\x5269\x4F59\x5B57\x7B26\x7684\x80CC\x666F",
    L"\x6240\x6709\x7F16\x8F91\x5668\x7684\x9AD8\x4EAE\x900F\x660E\x5EA6",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x0069\x0063\x006F\x006E\x0020\x0062\x0061\x0072\x7981\x7528\x72B6\x6001\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x0073\x006F\x0066\x0074\x006B\x0065\x0079\x6309\x4E0B\x72B6\x6001\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x0073\x006F\x0066\x0074\x006B\x0065\x0079\x7981\x7528\x72B6\x6001\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x0063\x0061\x006C\x006C\x0020\x006D\x0061\x006E\x0061\x0067\x0065\x0072\x753B\x9762\x6587\x672C\x8FB9\x6846\x989C\x8272",
    L"\x975E\x7126\x70B9\x5019\x9009\x6846\x9AD8\x4EAE\x6587\x672C\x989C\x8272",
    L"\x83B7\x53D6\x7126\x70B9\x6ED1\x5757\x7684\x80CC\x666F\x56FE\x7247",
    L"\x88AB\x7B14\x70B9\x51FB\x65F6\x5C0F\x6ED1\x5757\x7684\x56FE\x7247",
    L"\x4E00\x822C\x9009\x62E9\x6846\x7684\x80CC\x666F\x586B\x5145",
    L"\x83B7\x53D6\x7126\x70B9\x7684\x9009\x62E9\x6846\x7684\x80CC\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x7684\x9AD8\x4EAE\x80CC\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x7684\x80CC\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x6E10\x53D8\x6761\x98CE\x683C\x4E0B\x7684\x524D\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x975E\x6E10\x53D8\x6761\x98CE\x683C\x4E0B\x7684\x524D\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x7684\x8FDB\x5EA6\x5757\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x6ED1\x52A8\x6309\x94AE\x6309\x4E0B\x72B6\x6001\x4E0B\x7684\x80CC\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x6ED1\x52A8\x6309\x94AE\x6B63\x5E38\x72B6\x6001\x4E0B\x7684\x80CC\x666F\x586B\x5145",
    L"\x8FDB\x5EA6\x6761\x63A7\x4EF6\x6587\x672C\x989C\x8272",
    L"\x0044\x0069\x0073\x0070\x006C\x0061\x0079\x006F\x006E\x006C\x0079\x0020\x63A7\x4EF6\x53EA\x8BFB\x72B6\x6001\x4E0B\x7684\x80CC\x666F\x586B\x5145",
    L"\x0062\x0075\x0074\x0074\x006F\x006E\x63A7\x4EF6\x9AD8\x4EAE\x65F6\x7684\x6309\x4E0B\x72B6\x6001\x586B\x5145",
    L"\x0062\x0075\x0074\x0074\x006F\x006E\x63A7\x4EF6\x9AD8\x4EAE\x65F6\x7684\x975E\x6309\x4E0B\x72B6\x6001\x586B\x5145",
    L"\x0062\x0075\x0074\x0074\x006F\x006E\x63A7\x4EF6\x975E\x9AD8\x4EAE\x65F6\x7684\x6309\x4E0B\x72B6\x6001\x586B\x5145",
    L"\x0062\x0075\x0074\x0074\x006F\x006E\x63A7\x4EF6\x975E\x9AD8\x4EAE\x65F6\x7684\x975E\x6309\x4E0B\x72B6\x6001\x586B\x5145",
    L"\x0069\x006E\x006C\x0069\x006E\x0065\x5355\x884C\x7F16\x8F91\x6846\x9AD8\x4EAE\x65F6\x7684\x80CC\x666F\x586B\x5145",
    L"\x0069\x006E\x006C\x0069\x006E\x0065\x5355\x884C\x7F16\x8F91\x6846\x975E\x9AD8\x4EAE\x65F6\x7684\x80CC\x666F\x586B\x5145",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x4E0A\x7BAD\x5934\x80CC\x666F",
    L"\x526A\x5207\x677F\x6D6E\x52A8\x83DC\x5355\x4E0A\x7BAD\x5934\x6309\x4E0B\x80CC\x666F",
    L"\x65E5\x5386\x5F53\x65E5\x65E5\x671F\x80CC\x666F\x586B\x5145",
    L"\x5F85\x673A\x754C\x9762\x65E5\x5386\x4E2D\x5F53\x65E5\x65E5\x671F\x7684\x80CC\x666F\x586B\x5145",
    L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x7684\x80CC\x666F\x586B\x5145",
    L"\x65CB\x8F6C\x540E\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x753B\x9762\x7684\x80CC\x666F\x586B\x5145",
    L"\x975E\x5168\x5C4F\x7F16\x8F91\x753B\x9762\x8FB9\x6846\x989C\x8272",
    L"\x4FE1\x606F\x7F16\x8F91\x753B\x9762\xFF0C\x6DFB\x52A0\x6536\x4EF6\x4EBA\x6309\x94AE\x7684\x80CC\x666F\x56FE",
    L"\x4FE1\x606F\x7F16\x8F91\x753B\x9762\xFF0C\x6DFB\x52A0\x6536\x4EF6\x4EBA\x6309\x94AE\x4E0A\x7684\x6587\x5B57\x989C\x8272",
    L"\x5355\x884C\x8F93\x5165\x6846\x7684\x80CC\x666F\x586B\x5145",
    L"\x79D2\x8868\x753B\x9762\xFF0C\x6FC0\x6D3B\x72B6\x6001\x7684\x8BA1\x65F6\x5668\x6587\x5B57\x989C\x8272",
    L"\x79D2\x8868\x753B\x9762\xFF0C\x975E\x6FC0\x6D3B\x72B6\x6001\x7684\x8BA1\x65F6\x5668\x6587\x5B57\x989C\x8272",
    L"\x004D\x004D\x0053\x0020\x0056\x0069\x0065\x0077\x0065\x0072\x754C\x9762\xFF0C\x0073\x006C\x0069\x0064\x0065\x7684\x8FDB\x5EA6\x6761\x56FE\x7247",
};


/* Example screen enumeration */
enum
{
	MMI_MTE_EXAMPLE_SCREEN_IDLE,
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU,
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_PAGE_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_3D_CIRCULAR_MAIN_MENU,
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATE_MAIN_MENU,
#endif
	MMI_MTE_EXAMPLE_SCREEN_LIST,
	MMI_MTE_EXAMPLE_SCREEN_TWOLINE_LIST,
	MMI_MTE_EXAMPLE_SCREEN_MULTIROW_LIST,
	MMI_MTE_EXAMPLE_SCREEN_RADIO_LIST,
	MMI_MTE_EXAMPLE_SCREEN_CHECK_LIST,
#if defined(__MMI_SMALL_LIST_SCREEN__)
	MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST,
#endif
	MMI_MTE_EXAMPLE_SCREEN_POPUP,
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATED_POPUP,
#endif
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST,
#endif
	MMI_MTE_EXAMPLE_SCREEN_INLINE,
	MMI_MTE_EXAMPLE_SCREEN_EDITOR,
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	MMI_MTE_EXAMPLE_SCREEN_TAB_LIST,
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	MMI_MTE_EXAMPLE_SCREEN_TAB_LIST_WITHOUT_TAB,
#endif
#if defined(__MMI_CASCADE_MENU__)
	MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU,
#endif
	MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER,
	MMI_MTE_EXAMPLE_SCREEN_CALL,
	MMI_MTE_EXAMPLE_SCREEN_DIALER,
#if defined(__MMI_CALENDAR__)
	MMI_MTE_EXAMPLE_SCREEN_CALENDAR,
#endif
	MMI_MTE_EXAMPLE_SCREEN_PIN,
#if defined(__MMI_OP01_DCD__)
	MMI_MTE_EXAMPLE_SCREEN_DCD_IDLE,
#endif
#if defined(__MMI_OP01_DCD__)
	MMI_MTE_EXAMPLE_SCREEN_DCD_STORY_VIEWER,
#endif
#if defined(__MMI_OP01_DCD__)
	MMI_MTE_EXAMPLE_SCREEN_DCD_CHANNEL_LIST,
#endif
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
	MMI_MTE_EXAMPLE_SCREEN_MEDIA_PLAYER,
#endif
	MMI_MTE_EXAMPLE_SCREEN_NUM
} mmi_mte_example_screen_enum;

/* English example screen name */
static const wchar_t *g_mmi_mte_example_screen_name_EN[MMI_MTE_EXAMPLE_SCREEN_NUM] =
{
	L"Idle",
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Matrix Main Menu",
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Bi-degree Main Menu",
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"List Main Menu",
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Page Main Menu",
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"3D Circular Main Menu",
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"Rotate Main Menu",
#endif
	L"List",
	L"Two-line List",
	L"Multirow List",
	L"Radio List",
	L"Check List",
#if defined(__MMI_SMALL_LIST_SCREEN__)
	L"Small List",
#endif
	L"Popup",
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	L"Rotated Popup",
#endif
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	L"Rotated List",
#endif
	L"List-inline Editor",
	L"Editor",
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"Tab List",
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"Tab List Without tab",
#endif
#if defined(__MMI_CASCADE_MENU__)
	L"Cascading Menu",
#endif
	L"Symbol Picker",
	L"App - Call",
	L"App - Dialer",
#if defined(__MMI_CALENDAR__)
	L"App - Calendar",
#endif
	L"App - PIN",
#if defined(__MMI_OP01_DCD__)
	L"DCD - Idle",
#endif
#if defined(__MMI_OP01_DCD__)
	L"DCD - Story Viewer",
#endif
#if defined(__MMI_OP01_DCD__)
	L"DCD - Channel List",
#endif
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
	L"Media player",
#endif
};

/* GB example screen name */
static const wchar_t *g_mmi_mte_example_screen_name_GB[MMI_MTE_EXAMPLE_SCREEN_NUM] =
{
	L"\x5F85\x673A\x754C\x9762",
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x9875\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x0033\x0044\x0020\x5FAA\x73AF\x5F0F\x4E3B\x83DC\x5355",
#endif
#if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	L"\x65CB\x8F6C\x5F0F\x4E3B\x83DC\x5355",
#endif
	L"\x5B50\x83DC\x5355",
	L"\x53CC\x884C\x5B50\x83DC\x5355",
	L"\x591A\x884C\x5B50\x83DC\x5355",
	L"\x5355\x9009\x5B50\x83DC\x5355",
	L"\x591A\x9009\x5B50\x83DC\x5355",
#if defined(__MMI_SMALL_LIST_SCREEN__)
	L"\x975E\x5168\x5C4F\x5217\x8868\x5F0F\x83DC\x5355",
#endif
	L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846",
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	L"\x65CB\x8F6C\x540E\x5F39\x51FA\x5F0F\x63D0\x793A\x6846",
#endif
#if defined(__MMI_SCREEN_ROTATE__) && !defined(__MMI_MAINLCD_320X240__)
	L"\x65CB\x8F6C\x540E\x5B50\x83DC\x5355",
#endif
	L"\x5355\x884C\x7F16\x8F91\x83DC\x5355",
	L"\x7F16\x8F91\x5668",
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"\x6807\x7B7E\x5B50\x83DC\x5355",
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
	L"\x6CA1\x6709\x6807\x7B7E\x7684\x6807\x7B7E\x5B50\x83DC\x5355",
#endif
#if defined(__MMI_CASCADE_MENU__)
	L"\x5C42\x53E0\x5F0F\x83DC\x5355",
#endif
	L"\x7B26\x53F7\x9009\x62E9\x753B\x9762",
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x62E8\x53F7\x4E2D",
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x62E8\x53F7",
#if defined(__MMI_CALENDAR__)
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x65E5\x5386",
#endif
	L"\x5E94\x7528\x7A0B\x5F0F\x0020\x002D\x0020\x0050\x0049\x004E",
#if defined(__MMI_OP01_DCD__)
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x5F85\x673A\x754C\x9762",
#endif
#if defined(__MMI_OP01_DCD__)
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762",
#endif
#if defined(__MMI_OP01_DCD__)
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x9891\x9053\x5217\x8868\x754C\x9762",
#endif
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
	L"\x591A\x5A92\x4F53\x754C\x9762",
#endif
};

/* English component group name */
static const wchar_t *g_mmi_mte_theme_component_group_name_EN[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =
{
	L"Inputbox", // 0
	L"Scrollbar", // 1
	L"Title", // 2
	L"Submenu - List", // 3
	L"Submenu - Matrix", // 4
	L"Inline Editor", // 5
	L"Main Menu - List", // 6
	L"Main Menu - Matrix", // 7
	L"Common", // 8
	L"Screen - PIN input", // 9
	L"Screen - Idle", // 10
	L"Screen - Calling", // 11
	L"Screen - Dialer", // 12
	L"Inputbox - Keyboard", // 13
	L"Screen - Small Menu", // 14
	L"Softkey", // 15
	L"Wallpaper", // 16
	L"Screen - Symbol Picker", // 17
	L"Screen - Popup", // 18
	L"Clock", // 19
	L"Tab", // 20
	L"Calendar", // 21
	L"Status Icons", // 22
	L"Screen - Rotated", // 23
	L"Main Menu - Bidegree", // 24
	L"Submenu - Cascade", // 25
	L"DCD - Idle", // 26
	L"DCD - Channel List", // 27
	L"DCD - Story Viewer", // 28
	L"Inputbox - IME", // 29
	L"Indicator", // 30
	L"Media Player", // 31
	L"Icon Bar", // 32
	L"Alphabet Bar", // 33
	L"Special Screen", // 34
};

typedef enum
{
	MMI_MTE_GROUP_INPUTBOX,
	MMI_MTE_GROUP_SCROLLBAR,
	MMI_MTE_GROUP_TITLE,
	MMI_MTE_GROUP_SUBMENU_LIST,
	MMI_MTE_GROUP_SUBMENU_MATRIX,
	MMI_MTE_GROUP_INLINE_EDITOR,
	MMI_MTE_GROUP_MAIN_MENU_LIST,
	MMI_MTE_GROUP_MAIN_MENU_MATRIX,
	MMI_MTE_GROUP_COMMON,
	MMI_MTE_GROUP_SCREEN_PIN_INPUT,
	MMI_MTE_GROUP_SCREEN_IDLE,
	MMI_MTE_GROUP_SCREEN_CALLING,
	MMI_MTE_GROUP_SCREEN_DIALER,
	MMI_MTE_GROUP_INPUTBOX_KEYBOARD,
	MMI_MTE_GROUP_SCREEN_SMALL_MENU,
	MMI_MTE_GROUP_SOFTKEY,
	MMI_MTE_GROUP_WALLPAPER,
	MMI_MTE_GROUP_SCREEN_SYMBOL_PICKER,
	MMI_MTE_GROUP_SCREEN_POPUP,
	MMI_MTE_GROUP_CLOCK,
	MMI_MTE_GROUP_TAB,
	MMI_MTE_GROUP_CALENDAR,
	MMI_MTE_GROUP_STATUS_ICONS,
	MMI_MTE_GROUP_SCREEN_ROTATED,
	MMI_MTE_GROUP_MAIN_MENU_BIDEGREE,
	MMI_MTE_GROUP_SUBMENU_CASCADE,
	MMI_MTE_GROUP_DCD_IDLE,
	MMI_MTE_GROUP_CHANNEL_LIST,
	MMI_MTE_GROUP_STORY_VIEWER,
	MMI_MTE_GROUP_INPUTBOX_IME,
	MMI_MTE_GROUP_INDICATOR,
	MMI_MTE_GROUP_MEDIA_PLAYER,
	MMI_MTE_GROUP_ICON_BAR,
	MMI_MTE_GROUP_ALPHABET_BAR,
	MMI_MTE_GROUP_SPECIAL_SCREEN
} mmi_mte_group_enum;

/* GB component group name */
static const wchar_t *g_mmi_mte_theme_component_group_name_GB[MMI_MTE_THEME_COMPONENT_GROUP_NUM] =
{
	L"\x8F93\x5165\x6846", // 0
	L"\x6EDA\x52A8\x6761", // 1
	L"\x6807\x9898\x680F", // 2
	L"\x5217\x8868\x5F0F\x5B50\x83DC\x5355", // 3
	L"\x77E9\x9635\x5F0F\x5B50\x83DC\x5355", // 4
	L"\x5355\x884C\x7F16\x8F91\x5668", // 5
	L"\x5217\x8868\x5F0F\x4E3B\x83DC\x5355", // 6
	L"\x77E9\x9635\x5F0F\x4E3B\x83DC\x5355", // 7
	L"\x4E00\x822C", // 8
	L"\x0050\x0049\x004E\x0020\x8F93\x5165\x753B\x9762", // 9
	L"\x5F85\x673A\x753B\x9762", // 10
	L"\x62E8\x53F7\x4E2D\x753B\x9762", // 11
	L"\x62E8\x53F7\x753B\x9762", // 12
	L"\x865A\x62DF\x952E\x76D8", // 13
	L"\x975E\x5168\x5C4F\x753B\x9762", // 14
	L"\x8F6F\x952E", // 15
	L"\x5899\x7EB8", // 16
	L"\x7B26\x53F7\x9009\x62E9\x753B\x9762", // 17
	L"\x5F39\x51FA\x5F0F\x63D0\x793A\x6846\x753B\x9762", // 18
	L"\x65F6\x949F", // 19
	L"\x6807\x7B7E", // 20
	L"\x65E5\x5386", // 21
	L"\x72B6\x6001\x680F", // 22
	L"\x65CB\x8F6C\x540E\x753B\x9762", // 23
	L"\x53CC\x5217\x5F0F\x4E3B\x83DC\x5355", // 24
	L"\x5C42\x53E0\x5F0F\x83DC\x5355", // 25
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x5F85\x673A\x754C\x9762", // 26
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x9891\x9053\x5217\x8868\x754C\x9762", // 27
	L"\x0044\x0043\x0044\x0020\x002D\x0020\x9891\x9053\x9879\x5185\x5BB9\x754C\x9762", // 28
	L"\x8F93\x5165\x6CD5", // 29
	L"\x6307\x793A\x680F", // 30
	L"\x5A92\x4F53\x64AD\x653E\x5668", // 31
	L"\x56FE\x6807\x680F", // 32
	L"\x5B57\x6BCD\x8868\x680F", // 33
	L"\x7279\x6B8A\x754C\x9762", // 34
};

/* MTE theme components to DM control sets */
static const mmi_mte_control_set_group_struct g_mmi_mte_control_set_group[] =
{
	{0, {0}}, // DM_BASE_LAYER_START
	{0, {0}}, // DM_BASE_LAYER_END
	{0, {0}}, // DM_NEW_LAYER_START
	{0, {0}}, // DM_NEW_LAYER_END
	{0, {0}}, // DM_SCR_BG
	{0, {0}}, // DM_BASE_CONTROL_SET1
	{0, {0}}, // DM_BASE_CONTROL_SET2
	{0, {0}}, // DM_BASE_CONTROL_SET_SUBMENU
	{0, {0}}, // DM_BASE_CONTROL_SET_COMMON
	{0, {0}}, // DM_CIRCULAR_MENU1
	{48, {1, 2, 4, 5, 6, 7, 16, 45, 46, 47, 58, 100, 105, 106, 107, 108, 109, 153, 162, 172, 173, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 416, 417, 422, 423, 424, 429, 430, 431}}, // DM_LIST1
	{0, {0}}, // DM_ROTATE_MENU1
	{108, {1, 2, 4, 6, 9, 10, 17, 18, 19, 20, 21, 22, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 85, 86, 87, 88, 89, 100, 104, 176, 177, 280, 281, 313, 314, 315, 316, 317, 318, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 338, 339, 369, 370, 371, 372, 373, 375, 376, 377, 378, 379, 416, 417, 422, 423, 424, 429, 430, 431, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 482, 483, 484}}, // DM_INLINE_FIXED_LIST1
	{10, {8, 48, 49, 50, 422, 423, 424, 429, 430, 431}}, // DM_MATRIX_MENU1
	{48, {1, 2, 4, 5, 6, 7, 16, 45, 46, 47, 58, 100, 105, 106, 107, 108, 109, 153, 162, 172, 173, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 416, 417, 422, 423, 424, 429, 430, 431}}, // DM_DYNAMIC_LIST1
	{0, {0}}, // DM_DYNAMIC_MATRIX1
	{48, {1, 2, 4, 5, 6, 7, 16, 45, 46, 47, 58, 100, 105, 106, 107, 108, 109, 153, 162, 172, 173, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 416, 417, 422, 423, 424, 429, 430, 431}}, // DM_ASYNCDYNAMIC_LIST1
	{0, {0}}, // DM_ASYNCDYNAMIC_MATRIX1
	{98, {0, 28, 38, 39, 40, 41, 85, 86, 87, 88, 89, 178, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 313, 314, 315, 316, 317, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 337, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 436, 455}}, // DM_SINGLELINE_INPUTBOX1
	{139, {0, 1, 2, 28, 38, 39, 40, 41, 66, 67, 68, 85, 86, 87, 88, 89, 100, 104, 178, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 313, 314, 315, 316, 317, 318, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 337, 342, 343, 344, 347, 348, 349, 350, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 422, 423, 424, 429, 430, 431, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 454, 455, 475, 476, 482, 483}}, // DM_MULTILINE_INPUTBOX1
	{140, {0, 1, 2, 28, 38, 39, 40, 41, 66, 67, 68, 85, 86, 87, 88, 89, 100, 104, 178, 179, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 313, 314, 315, 316, 317, 318, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 337, 342, 343, 344, 347, 348, 349, 350, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 422, 423, 424, 429, 430, 431, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 454, 455, 475, 476, 482, 483}}, // DM_EMS_INPUTBOX1
	{13, {27, 81, 82, 83, 84, 180, 181, 287, 288, 289, 290, 291, 336}}, // DM_DIALER_INPUT_BOX1
	{0, {0}}, // DM_TAB_CONTROL
	{16, {127, 128, 129, 130, 156, 157, 158, 262, 351, 352, 353, 354, 355, 356, 434, 435}}, // DM_HORIZONTAL_TAB_BAR
	{4, {118, 119, 120, 121}}, // DM_DATE_TIME_DISPLAY
	{9, {3, 42, 43, 44, 149, 150, 151, 152, 154}}, // DM_TITLE1
	{1, {148}}, // DM_STATUS_BAR1
	{0, {0}}, // DM_LSK
	{0, {0}}, // DM_RSK
	{0, {0}}, // DM_CSK
	{14, {32, 33, 34, 35, 36, 37, 125, 126, 182, 183, 184, 185, 452, 453}}, // DM_BUTTON_BAR1
	{0, {0}}, // DM_BUTTON
	{38, {131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 307, 367, 368, 374, 477}}, // DM_CALENDAR
	{0, {0}}, // DM_ALIGNED_AREA_START
	{0, {0}}, // DM_ALIGNED_AREA_END
	{0, {0}}, // DM_STRING
	{0, {0}}, // DM_IMAGE
	{0, {0}}, // DM_BACK_FILL_AREA
	{0, {0}}, // DM_RECTANGLE
	{0, {0}}, // DM_LINE
	{7, {16, 45, 58, 432, 433, 456, 457}}, // DM_SLIDE_CONTROL
	{0, {0}}, // DM_CATEGORY_CONTROLLED_AREA
	{0, {0}}, // DM_CATEGORY_CONTROLLED_AREA2
	{12, {153, 231, 232, 295, 296, 297, 298, 299, 300, 301, 479, 480}}, // DM_POPUP_BACKGROUND
	{0, {0}}, // DM_NWAY_STOPWATCH
	{0, {0}}, // DM_TYPICAL_STOPWATCH
	{0, {0}}, // DM_WALL_PAPER
	{0, {0}}, // DM_SCROLL_TEXT
	{0, {0}}, // DM_PERCENTAGE_BAR
	{0, {0}}, // DM_PANEL
	{14, {309, 310, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 450, 451}}, // DM_ICON_BAR
};

#define	MMI_MTE_CURRENT_SCREEN_FILTER_NUM	42

/*
 * screen filter
 */
/* filter dependencies */
#if defined(__IOT__)
#ifdef IDLE_SCREEN_ID
#undef IDLE_SCREEN_ID
#endif
#define IDLE_SCREEN_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_OP11_CAT433_SUPPORT__)
#define SCREEN_FILTER_MMI_CATEGORY433_ID MMI_CATEGORY433_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY433_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_OP01_DCD__)
#define SCREEN_FILTER_1_INLINE_EDIT_LEFT_ARROW_IMAGE 176
#define SCREEN_FILTER_1_INLINE_EDIT_RIGHT_ARROW_IMAGE 177
#else
#define SCREEN_FILTER_1_INLINE_EDIT_LEFT_ARROW_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_1_INLINE_EDIT_RIGHT_ARROW_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_MAINLCD_320X480__)
#define SCREEN_FILTER_4_MATRIX_MAIN_MENU_NORMAL_TEXT_COLOR 55
#else
#define SCREEN_FILTER_4_MATRIX_MAIN_MENU_NORMAL_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_MAINLCD_176X220__)
#define SCREEN_FILTER_4_SCROLLBAR_BACKGROUND_FILLER 1
#define SCREEN_FILTER_4_SCROLLBAR_INDICATOR_FILLER 2
#else
#define SCREEN_FILTER_4_SCROLLBAR_BACKGROUND_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_4_SCROLLBAR_INDICATOR_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_320X480__)
#define SCREEN_FILTER_6_MATRIX_MAIN_MENU_SELECTED_TEXT_COLOR 56
#else
#define SCREEN_FILTER_6_MATRIX_MAIN_MENU_SELECTED_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(WGUI_CATCALL_STYLE_2)
#define SCREEN_FILTER_10_CM_SCREEN_BACKGROUND_FILLER 26
#else
#define SCREEN_FILTER_10_CM_SCREEN_BACKGROUND_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_IDLE_FULL_SCREEN__) && !defined(__MMI_TOUCH_DIAL_SCREEN__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)) && defined(__GDI_MEMORY_PROFILE_2__) && !defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
#define SCREEN_FILTER_10_STATUS_ICON_BAR_FILLER -148
#else
#define SCREEN_FILTER_10_STATUS_ICON_BAR_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !(((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)) && defined(__GDI_MEMORY_PROFILE_2__)) && !defined(__MMI_UI_DALMATIAN_IDLESCREEN__)) && !defined(__MMI_TOUCH_DIAL_SCREEN__)
#define SCREEN_FILTER_10_DATETIME_BAR_DATE_TEXT_COLOR 62
#define SCREEN_FILTER_10_DATETIME_BAR_TIME_TEXT_COLOR 63
#define SCREEN_FILTER_10_DATETIME_BAR_BACKGROUND_COLOR 60
#else
#define SCREEN_FILTER_10_DATETIME_BAR_DATE_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_10_DATETIME_BAR_TIME_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_10_DATETIME_BAR_BACKGROUND_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_320X480__)
#define SCREEN_FILTER_11_STATUS_ICON_BAR_FILLER 148
#else
#define SCREEN_FILTER_11_STATUS_ICON_BAR_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_320X480__)
#define SCREEN_FILTER_11_LIST_NORMAL_TEXT_COLOR 45
#else
#define SCREEN_FILTER_11_LIST_NORMAL_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(WGUI_CATCALL_STYLE_2)
#define SCREEN_FILTER_11_CM_SCREEN_BACKGROUND_FILLER 26
#else
#define SCREEN_FILTER_11_CM_SCREEN_BACKGROUND_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !(((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)) && defined(__GDI_MEMORY_PROFILE_2__)) && !defined(__MMI_UI_DALMATIAN_IDLESCREEN__)) && !defined(__MMI_TOUCH_DIAL_SCREEN__)
#define SCREEN_FILTER_11_DATETIME_BAR_DATE_TEXT_COLOR 62
#define SCREEN_FILTER_11_DATETIME_BAR_TIME_TEXT_COLOR 63
#define SCREEN_FILTER_11_DATETIME_BAR_BACKGROUND_COLOR 60
#else
#define SCREEN_FILTER_11_DATETIME_BAR_DATE_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_11_DATETIME_BAR_TIME_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_11_DATETIME_BAR_BACKGROUND_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_MAINLCD_320X480__)
#define SCREEN_FILTER_11_SUB_MENU_BKG_FILLER 113
#else
#define SCREEN_FILTER_11_SUB_MENU_BKG_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
#define SCREEN_FILTER_11_CM_SCREEN_TEXT_COLOR 59
#else
#define SCREEN_FILTER_11_CM_SCREEN_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)) && (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__))
#define SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE 316
#define SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE 317
#else
#define SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)) && (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__))
#define SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE 316
#define SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE 317
#else
#define SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_OP01_DCD__)
#define SCREEN_FILTER_MMI_CATEGORY182_ID MMI_CATEGORY182_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY182_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_OP01_DCD__)
#define SCREEN_FILTER_MMI_CATEGORY432_ID MMI_CATEGORY432_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY432_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_WC_TZ_SUPPORT__)
#define SCREEN_FILTER_MMI_CATEGORY_WCLOCK MMI_CATEGORY_WCLOCK
#else
#define SCREEN_FILTER_MMI_CATEGORY_WCLOCK MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
#define SCREEN_FILTER_19_STATUS_ICON_BAR_FILLER 148
#else
#define SCREEN_FILTER_19_STATUS_ICON_BAR_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__)
#define SCREEN_FILTER_19_TITLE_TEXT_COLOR 42
#define SCREEN_FILTER_19_TITLE_TEXT_BORDER_COLOR 43
#define SCREEN_FILTER_19_TITLE_FILLER 3
#else
#define SCREEN_FILTER_19_TITLE_TEXT_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_19_TITLE_TEXT_BORDER_COLOR MMI_MTE_INVALID_FILTER_COMPONENT
#define SCREEN_FILTER_19_TITLE_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
#define SCREEN_FILTER_21_INPUTBOX_FILLER 0
#else
#define SCREEN_FILTER_21_INPUTBOX_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
#define SCREEN_FILTER_22_STATUS_ICON_BAR_FILLER 148
#else
#define SCREEN_FILTER_22_STATUS_ICON_BAR_FILLER MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_SMALL_PIN_EDIT_SCREEN__)
#define SCREEN_FILTER_MMI_CATEGORY112_ID MMI_CATEGORY112_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY112_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__MMI_MAINLCD_128X128__)
#define SCREEN_FILTER_MMI_CATEGORY426_ID MMI_CATEGORY426_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY426_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__COSMOS_MMI__) && !defined(__IOT__)
#define SCREEN_FILTER_SCR_ID_ALM_LIST SCR_ID_ALM_LIST
#else
#define SCREEN_FILTER_SCR_ID_ALM_LIST MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if !defined(__DISABLE_SHORTCUTS_MENU__) && !defined(__COSMOS_MMI__)
#define SCREEN_FILTER_SCR_ID_SHCT_MAIN_MENU SCR_ID_SHCT_MAIN_MENU
#else
#define SCREEN_FILTER_SCR_ID_SHCT_MAIN_MENU MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__COSMOS_MMI__)
#define SCREEN_FILTER_SCR_ID_MEDPLY_MAIN_SCREEN SCR_ID_MEDPLY_MAIN_SCREEN
#else
#define SCREEN_FILTER_SCR_ID_MEDPLY_MAIN_SCREEN MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(UI_SMALL_CATEGORY_EDITOR)
#define SCREEN_FILTER_MMI_CATEGORY100_ID MMI_CATEGORY100_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY100_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_FTE_SUPPORT__)
#define SCREEN_FILTER_MMI_CATEGORY28_ID MMI_CATEGORY28_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY28_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__)
#define SCREEN_FILTER_MMI_CATEGORY280_ID MMI_CATEGORY280_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY280_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__MMI_STOPWATCH__)
#define SCREEN_FILTER_MMI_CATEGORY306_ID MMI_CATEGORY306_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY306_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif
#if defined(__UI_MMS_VIEWER_CATEGORY__) && !defined(__MMI_FTE_SUPPORT__)
#define SCREEN_FILTER_MMI_CATEGORY630_ID MMI_CATEGORY630_ID
#else
#define SCREEN_FILTER_MMI_CATEGORY630_ID MMI_MTE_INVALID_FILTER_COMPONENT
#endif

static const mmi_mte_current_screen_filter_struct g_mmi_mte_current_screen_filter[MMI_MTE_CURRENT_SCREEN_FILTER_NUM] =
{
	{0, SCREEN_FILTER_MMI_CATEGORY433_ID, 3, {45, 46, 114, }, {0, {0}}},
	{IDLE_SCREEN_ID, 0, 21, {114, 116, 117, 90, 92, 91, 93, 116, 117, 94, 95, 96, 97, 98, 99, 227, 228, 229, 230, SCREEN_FILTER_1_INLINE_EDIT_LEFT_ARROW_IMAGE, SCREEN_FILTER_1_INLINE_EDIT_RIGHT_ARROW_IMAGE, }, {0, {0}}},
	{0, MMI_CATEGORY14_CIRCULAR_ID, 2, {3, 44, }, {1, {DM_TITLE1, }}},
	{0, MMI_CATEGORY14_ROTATE_ID, 2, {3, 44, }, {1, {DM_TITLE1, }}},
	{0, MMI_CATEGORY14_MATRIX_ID, 7, {112, 160, SCREEN_FILTER_4_MATRIX_MAIN_MENU_NORMAL_TEXT_COLOR, SCREEN_FILTER_4_SCROLLBAR_BACKGROUND_FILLER, SCREEN_FILTER_4_SCROLLBAR_INDICATOR_FILLER, 3, 44, }, {2, {DM_MATRIX_MENU1, DM_TITLE1, }}},
	{0, MMI_CATEGORY14_MATRIX_PAGE_ID, 6, {112, 160, 233, 234, 3, 44, }, {2, {DM_MATRIX_MENU1, DM_TITLE1, }}},
	{0, MMI_CATEGORY414_ID, 8, {112, 14, 159, 161, 3, 44, 55, SCREEN_FILTER_6_MATRIX_MAIN_MENU_SELECTED_TEXT_COLOR, }, {2, {DM_LIST1, DM_TITLE1, }}},
	{0, MMI_CATEGORY14_LIST_ID, 8, {112, 12, 52, 1, 2, 53, 3, 44, }, {2, {DM_LIST1, DM_TITLE1, }}},
	{0, MMI_CATEGORY_CASCADING_MENU_ID, 20, {167, 168, 164, 165, 169, 166, 280, 281, 416, 417, 170, 171, 340, 341, 345, 346, 1, 2, 174, 175, }, {1, {DM_LIST1, }}},
	{0, MMI_CATEGORY22_ID, 1, {110, }, {0, {0}}},
	{0, MMI_CATEGORY16_ID, 11, {27, 84, 180, 181, SCREEN_FILTER_10_CM_SCREEN_BACKGROUND_FILLER, SCREEN_FILTER_10_STATUS_ICON_BAR_FILLER, SCREEN_FILTER_10_DATETIME_BAR_DATE_TEXT_COLOR, SCREEN_FILTER_10_DATETIME_BAR_TIME_TEXT_COLOR, SCREEN_FILTER_10_DATETIME_BAR_BACKGROUND_COLOR, 82, 83, }, {0, {0}}},
	{0, MMI_CATEGORY18_ID, 9, {SCREEN_FILTER_11_STATUS_ICON_BAR_FILLER, SCREEN_FILTER_11_LIST_NORMAL_TEXT_COLOR, SCREEN_FILTER_11_CM_SCREEN_BACKGROUND_FILLER, SCREEN_FILTER_11_DATETIME_BAR_DATE_TEXT_COLOR, SCREEN_FILTER_11_DATETIME_BAR_TIME_TEXT_COLOR, SCREEN_FILTER_11_DATETIME_BAR_BACKGROUND_COLOR, 294, SCREEN_FILTER_11_SUB_MENU_BKG_FILLER, SCREEN_FILTER_11_CM_SCREEN_TEXT_COLOR, }, {0, {0}}},
	{0, MMI_CATEGORY83_ID, 1, {113, }, {0, {0}}},
	{0, MMI_CATEGORY111_ID, 13, {23, 24, 77, 78, 79, 80, 28, 85, 86, SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE, SCREEN_FILTER_13_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE, 45, 67, }, {2, {DM_MULTILINE_INPUTBOX1, DM_SINGLELINE_INPUTBOX1, }}},
	{0, MMI_CATEGORY69_ID, 12, {23, 24, 77, 78, 79, 80, 28, 85, 86, SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_LEFT_IMAGE, SCREEN_FILTER_14_VIRTUAL_KEYBOARD_KEY_LARGE_ICON_RIGHT_IMAGE, 45, }, {2, {DM_MULTILINE_INPUTBOX1, DM_SINGLELINE_INPUTBOX1, }}},
	{0, MMI_CATEGORY9_ID+1, 8, {1, 2, 29, 302, 30, 303, 304, 320, }, {1, {DM_LIST1, }}},
	{0, MMI_CATEGORY86_ID, 3, {122, 123, 124, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY182_ID, 1, {222, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY432_ID, 4, {223, 224, 225, 226, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY_WCLOCK, 4, {SCREEN_FILTER_19_STATUS_ICON_BAR_FILLER, SCREEN_FILTER_19_TITLE_TEXT_COLOR, SCREEN_FILTER_19_TITLE_TEXT_BORDER_COLOR, SCREEN_FILTER_19_TITLE_FILLER, }, {0, {0}}},
	{0, MMI_CATEGORY200_ID, 3, {66, 68, 67, }, {2, {-DM_DYNAMIC_LIST1, DM_SINGLELINE_INPUTBOX1, }}},
	{0, MMI_CATEGORY435_ID, 4, {SCREEN_FILTER_21_INPUTBOX_FILLER, 38, 1, 2, }, {0, {0}}},
	{0, MMI_CATEGORY223_ID, 3, {SCREEN_FILTER_22_STATUS_ICON_BAR_FILLER, 64, 61, }, {1, {-DM_TITLE1, }}},
	{0, MMI_CATEGORY307_ID, 0, {0}, {1, {-DM_LIST1, }}},
	{0, MMI_CATEGORY403_ID, 1, {64, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY112_ID, 7, {28, 85, 86, 23, 24, 77, 80, }, {2, {DM_MULTILINE_INPUTBOX1, DM_SINGLELINE_INPUTBOX1, }}},
	{0, MMI_CATEGORY221_ID, 0, {0}, {2, {-DM_TITLE1, -DM_STATUS_BAR1, }}},
	{0, MMI_CATEGORY213_ID, 0, {0}, {1, {-DM_LIST1, }}},
	{0, SCREEN_FILTER_MMI_CATEGORY426_ID, 2, {172, 173, }, {0, {0}}},
	{SCREEN_FILTER_SCR_ID_ALM_LIST, 0, 2, {172, 173, }, {0, {0}}},
	{0, MMI_CATEGORY214_ID, 15, {45, 6, 4, 418, 419, 420, 421, 422, 423, 424, 1, 2, 416, 1, 2, }, {0, {0}}},
	{0, MMI_CATEGORY407_ID, 1, {38, }, {0, {0}}},
	{0, MMI_CATEGORY144_ID, 2, {1, 2, }, {0, {0}}},
	{SCREEN_FILTER_SCR_ID_SHCT_MAIN_MENU, 0, 2, {172, 173, }, {0, {0}}},
	{SCREEN_FILTER_SCR_ID_MEDPLY_MAIN_SCREEN, 0, 3, {319, 266, 267, }, {0, {0}}},
	{0, MMI_CATEGORY404_ID, 2, {-126, 292, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY100_ID, 1, {481, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY28_ID, 2, {482, 483, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY280_ID, 2, {482, 483, }, {0, {0}}},
	{0, MMI_CAT2001_ID, 1, {484, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY306_ID, 2, {485, 486, }, {0, {0}}},
	{0, SCREEN_FILTER_MMI_CATEGORY630_ID, 1, {487, }, {0, {0}}},
};

#define MMI_MTE_VER(major, minor)    (((major) << 16) | ((minor) & 0xFFFF))
#define MMI_MTE_GET_MAJOR_VER(ver)   (((ver) >> 16) & 0xFFFF)
#define MMI_MTE_GET_MINOR_VER(ver)   ((ver) & 0xFFFF)
#define MMI_MTE_BRANCH_NUM 3

static const int g_mmi_mte_branch_ver[MMI_MTE_BRANCH_NUM] = 
{
MMI_MTE_VER(1, 0), // 07B
MMI_MTE_VER(2, 0), // 08A
MMI_MTE_VER(3, 0), // 08B
};

#define MMI_MTE_BACKWARD_COMPATIBILITY_COMPONENT_NUM   98
static const char *g_mmi_mte_backward_component[MMI_MTE_BACKWARD_COMPATIBILITY_COMPONENT_NUM * MMI_MTE_BRANCH_NUM] =
{
"window_title_font", "", "DELETE", 
"calendar_title_fg_color", "calendar_title_text_color", "RENAME", 
"calendar_horizontal_fg_color", "calendar_horizontal_text_color", "RENAME", 
"calendar_vertical_fg_color", "calendar_vertical_text_color", "RENAME", 
"calendar_horizontal_string_fg_color", "calendar_horizontal_string_text_color", "RENAME", 
"calendar_valid_fg_color", "calendar_valid_text_color", "RENAME", 
"calendar_invalid_fg_color", "calendar_invalid_text_color", "RENAME", 
"calendar_infobox_fg_color", "calendar_infobox_text_color", "RENAME", 
"ime_focused_background_color", "", "DELETE, TO FILLER", 
"ime_background_color", "", "DELETE, TO FILLER", 
"ime_text_color", "", "DELETE", 
"ime_lable_color", "ime_label_color", "RENAME", 
"ime_lable_font", "ime_label_font", "RENAME", 
"ime_hilite_color", "", "DELETE", 
"ime_hilite_text_color", "", "DELETE", 
"ime_arrow_color", "", "DELETE, splited to ime_arrow_up_color and ime_arrow_down_color", 
"", "multitap_filler", "DELETE", 
"", "multitap_selector_color", "DELETE", 
"", "multitap_normal_text_color", "DELETE", 
"", "multitap_selected_text_color", "DELETE", 
"", "multitap_font", "DELETE", 
"", "main_menu_icon1", "DELETE", 
"", "main_menu_icon2", "DELETE", 
"", "main_menu_icon3", "DELETE", 
"", "main_menu_icon4", "DELETE", 
"", "main_menu_icon5", "DELETE", 
"", "main_menu_icon6", "DELETE", 
"", "main_menu_icon7", "DELETE", 
"", "main_menu_icon8", "DELETE", 
"", "main_menu_icon9", "DELETE", 
"", "main_menu_icon10", "DELETE", 
"", "main_menu_icon11", "DELETE", 
"", "main_menu_icon12", "DELETE", 
"", "main_menu_icon13", "DELETE", 
"", "main_menu_icon14", "DELETE", 
"", "main_menu_icon15", "DELETE", 
"", "aphorism_screen_background_filler", "DELETE", 
"", "progress_screen_background_filler", "DELETE", 
"", "alarm_background_filler", "DELETE", 
"", "alarm_text_color", "DELETE", 
"", "formatted_inputbox_selector_color", "DELETE", 
"", "formatted_inputbox_normal_text_color", "DELETE", 
"", "formatted_inputbox_disabled_text_color", "DELETE", 
"", "formatted_inputbox_selected_text_color", "DELETE", 
"", "calculator_color", "DELETE", 
"", "matrix_background_filler", "DELETE", 
"", "matrix_normal_item_filler", "DELETE", 
"", "matrix_disabled_item_filler", "DELETE", 
"", "main_menu_background_filler", "DELETE", 
"", "matrix_main_menu_normal_item_filler", "DELETE", 
"", "matrix_main_menu_disabled_item_filler", "DELETE", 
"", "inline_list_background_filler", "DELETE", 
"", "inline_list_default_text_item_filler", "DELETE", 
"", "UI_black_color", "DELETE", 
"", "UI_white_color", "DELETE", 
"", "menubar_index_background_color", "DELETE", 
"", "menubar_item_background_color", "DELETE", 
"", "menubar_index_text_color", "DELETE", 
"", "menubar_item_text_color", "DELETE", 
"", "menu_bar_index_font", "DELETE", 
"", "menu_bar_item_font", "DELETE", 
"", "drop_down_control_font", "DELETE", 
"", "drop_down_normal_text_color", "DELETE", 
"", "drop_down_disabled_text_color", "DELETE", 
"", "drop_down_focussed_text_color", "DELETE", 
"", "circular_main_menu_normal_text_color", "DELETE", 
"", "circular_main_menu_selected_text_color", "DELETE", 
"", "circular_main_menu_disabled_text_color", "DELETE", 
"", "dialer_inputbox_touch_background_filler", "DELETE", 
"", "date_text_color_sub_lcd", "DELETE", 
"", "date_text_border_color_sub_lcd", "DELETE", 
"", "time_text_color_sub_lcd", "DELETE", 
"", "time_text_border_color_sub_lcd", "DELETE", 
"", "list_second_line_text_color", "DELETE", 
"", "list_second_line_focused_text_color", "DELETE", 
"", "media_player_bg_image", "DELETE", 
"", "button_font", "DELETE", 
"", "inputbox_font", "DELETE", 
"", "list_menu_font", "DELETE", 
"", "matrix_menu_font", "DELETE", 
"", "shortcut_indicator_font", "DELETE", 
"", "title_text_font;", "DELETE", 
"", "list_main_menu_font", "DELETE", 
"", "matrix_main_menu_font", "DELETE", 
"", "virtual_keyboard_font", "DELETE", 
"", "date_text_font", "DELETE", 
"", "time_text_font", "DELETE", 
"", "date_text_font_sub_lcd", "DELETE", 
"", "time_text_font_sub_lcd", "DELETE", 
"", "tab_title_text_font", "DELETE", 
"", "calendar_infobox_font", "DELETE", 
"", "calendar_horizontal_string_font", "DELETE", 
"", "calendar_cell_font", "DELETE", 
"", "calendar_horizontal_string_for_idle_font", "DELETE", 
"", "calendar_cell_for_idle_font", "DELETE", 
"", "dcd_idle_font", "DELETE", 
"", "ime_text_font", "DELETE", 
"", "ime_label_font", "DELETE", 
};

