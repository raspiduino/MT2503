extern "C"
{
#include "FSEditorCuiGprot.h"
}
static const mmi_imm_input_mode_enum g_avk_pluto_cui_input_modes[] = {
        IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
        IMM_INPUT_MODE_123_SYMBOLS,
        IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
        IMM_INPUT_MODE_NONE   };
static const wchar_t g_avk_pluto_cui_characters_list[] = L"\t\n";
static MMI_ID g_avk_pluto_cui_editor_id = GRP_ID_INVALID;

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_cui_editor_proc
 * DESCRIPTION
 *  Test editor CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_cui_editor_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type buffer;
    U32 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        AVK_LOG(length = cui_fseditor_get_text_len(g_avk_pluto_cui_editor_id));
        buffer = (UI_string_type)AVK_MALLOC((length + 1) * ENCODING_LENGTH);
        if (buffer)
        {
            AVK_LOG_EX(length == cui_fseditor_get_text(g_avk_pluto_cui_editor_id, buffer, length));
        }
        AVK_FREE(buffer);
    case EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED:
        if (g_avk_pluto_cui_editor_id != GRP_ID_INVALID)
        {
            AVK_LOG_NORMAL(cui_fseditor_close(g_avk_pluto_cui_editor_id));
            g_avk_pluto_cui_editor_id = GRP_ID_INVALID;
        }        
        AVK_CASE_RESULT(AVK_PASS);
        AVK_ASYN_DONE();
		break;
    case EVT_ID_CUI_FSEDITOR_ABORT:
    case EVT_ID_GROUP_DELETE_REQ:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        if (g_avk_pluto_cui_editor_id != GRP_ID_INVALID)
        {
            AVK_LOG_NORMAL(cui_fseditor_close(g_avk_pluto_cui_editor_id));
            g_avk_pluto_cui_editor_id = GRP_ID_INVALID;
        }
        
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_cui_editor_case_001
 * DESCRIPTION
 *  Test editor CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_cui_editor_case_001(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wchar_t buffer[] = L"Case 001: disable cancels after all tests pass";
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_cui_editor_id = cui_fseditor_create(AVK_GRP_ID_1);
    if (g_avk_pluto_cui_editor_id != GRP_ID_INVALID)
    {
        AVK_LOG_NORMAL(cui_fseditor_set_title(g_avk_pluto_cui_editor_id, 0, 0));
        AVK_LOG_NORMAL(cui_fseditor_set_input_method(
            g_avk_pluto_cui_editor_id,
            IMM_INPUT_TYPE_ENGLISH_SENTENCE,
            g_avk_pluto_cui_input_modes,
            0));
        length = mmi_ucs2strlen((const CHAR *)buffer);
        AVK_LOG_NORMAL(cui_fseditor_set_text(g_avk_pluto_cui_editor_id, (WCHAR *)buffer, length, length));
        AVK_LOG_NORMAL(cui_fseditor_set_softkey_text(
            g_avk_pluto_cui_editor_id,
            MMI_LEFT_SOFTKEY,
            AVK_STR_PASS));
        cui_fseditor_set_softkey_text(
            g_avk_pluto_cui_editor_id,
            MMI_RIGHT_SOFTKEY,
            AVK_STR_FAIL);
        AVK_LOG_NORMAL(cui_fseditor_set_softkey_icon(g_avk_pluto_cui_editor_id, MMI_LEFT_SOFTKEY, 0));
        cui_fseditor_set_softkey_icon(g_avk_pluto_cui_editor_id, MMI_RIGHT_SOFTKEY, 0);
        AVK_LOG_NORMAL(cui_fseditor_set_characters_filter(
            g_avk_pluto_cui_editor_id,
            MMI_FALSE,
            (WCHAR *)g_avk_pluto_cui_characters_list));
        AVK_LOG_NORMAL(cui_fseditor_set_default_options_menu(
            g_avk_pluto_cui_editor_id,
            AVK_STR_PASS,
            AVK_STR_FAIL));
        AVK_LOG_NORMAL(cui_fseditor_disable_cancel_options_item(g_avk_pluto_cui_editor_id, MMI_TRUE));
        AVK_LOG_NORMAL(cui_fseditor_run(g_avk_pluto_cui_editor_id));
    }
    
}

AVK_MANUAL_CASE(AVK_CUI_EDT_001,AVK_CUI_EDT)
{
    mmi_frm_group_create(GRP_ID_ROOT, AVK_GRP_ID_1, avk_pluto_cui_editor_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_1, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_display_dummy_screen();
    avk_pluto_cui_editor_case_001();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_cui_editor_case_002
 * DESCRIPTION
 *  Test editor CUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_cui_editor_case_002(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type buffer[160];
    cui_fseditor_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_cui_editor_id = cui_fseditor_create(AVK_GRP_ID_1);
    if (g_avk_pluto_cui_editor_id != GRP_ID_INVALID)
    {
        CUI_FSEDITOR_STRUCT_INIT(&property);
        mmi_ucs2cpy((CHAR*)buffer, (const CHAR*)L"Case 002: Check options menu: Done means pass, cancel means fail");
        property.buffer = buffer;
        property.buffer_size = 60;
        property.edit_length = mmi_ucs2strlen((const CHAR*)buffer);
        property.input_type = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
        AVK_LOG_NORMAL(cui_fseditor_set_property(g_avk_pluto_cui_editor_id, &property));
        AVK_LOG_NORMAL(cui_fseditor_set_title_string(g_avk_pluto_cui_editor_id, 0));
        AVK_LOG_NORMAL(cui_fseditor_set_title_icon(g_avk_pluto_cui_editor_id, 0));
/*        cui_fseditor_set_custom_options_menu(
            g_avk_pluto_cui_editor_id,
            MMI_TRUE,
            (PU16)g_avk_pluto_cui_menu_list,
            1);*/
        AVK_LOG_NORMAL(cui_fseditor_get_parent_data(g_avk_pluto_cui_editor_id));
        AVK_LOG_NORMAL(cui_fseditor_set_parent_data(g_avk_pluto_cui_editor_id, 0xDEADDEAD));
        if (AVK_LOG(cui_fseditor_get_parent_data(g_avk_pluto_cui_editor_id) != 0xDEADDEAD))
        {
            cui_fseditor_set_softkey_text(g_avk_pluto_cui_editor_id, MMI_LEFT_SOFTKEY, 0);
        }
        cui_fseditor_set_softkey_text(g_avk_pluto_cui_editor_id, MMI_RIGHT_SOFTKEY, AVK_STR_FAIL);
        AVK_LOG_NORMAL(cui_fseditor_set_title_in_header(g_avk_pluto_cui_editor_id, MMI_TRUE));
        AVK_LOG_NORMAL(cui_fseditor_set_cursor_first_pos(g_avk_pluto_cui_editor_id, MMI_TRUE));
        AVK_LOG_NORMAL(cui_fseditor_run(g_avk_pluto_cui_editor_id));
        AVK_LOG_NORMAL(cui_fseditor_append_text(g_avk_pluto_cui_editor_id, get_string(AVK_STR_PASS)));
    }
}

AVK_MANUAL_CASE(AVK_CUI_EDT_002,AVK_CUI_EDT)
{
    mmi_frm_group_create(GRP_ID_ROOT, AVK_GRP_ID_1, avk_pluto_cui_editor_proc, NULL);
    mmi_frm_group_enter(AVK_GRP_ID_1, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_display_dummy_screen();
    avk_pluto_cui_editor_case_002();
}

