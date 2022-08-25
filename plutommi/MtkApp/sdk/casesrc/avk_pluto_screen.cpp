
#ifdef __MMI_FRM_HISTORY__

extern "C" void avk_pluto_screen_001_test(void);
extern "C" void avk_pluto_screen_001(void);
extern "C" void *mmi_frm_get_active_scrn_arg(void);
extern "C" void avk_pluto_screen_entry(void);


AVK_CASE(AVK_PLUTO_SCRN_AUTO_001,AVK_PLUTO_SCRN)
{
    avk_pluto_screen_entry();
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001_exit
 * DESCRIPTION
 *  Exit function pointer test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001_exit(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_generic_exit_inline_scrn(0, (entry_func_ptr)avk_pluto_screen_001);
    AVK_LOG_FUN(mmi_frm_generic_exit_inline_scrn, AVK_LOG(mmi_frm_in_exit_hdlr_proc()));
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001_highlight
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001_test
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_curr_exit_hdlr(avk_pluto_screen_001_exit);
	AVK_LOG_FUN(mmi_frm_set_curr_exit_hdlr, AVK_LOG(mmi_frm_get_curr_exit_hdlr() == avk_pluto_screen_001_exit));
	
    AVK_LOG(mmi_frm_entry_new_screen(
        AVK_SCR_ID_3,
        NULL,
        NULL,
        NULL));
        
	mmi_frm_replace_new_scrn_hdlr(AVK_SCR_ID_3,
		                          NULL,
		                          (entry_func_ptr)MMI_dummy_function);
    AVK_LOG_FUN(mmi_frm_replace_new_scrn_hdlr,
                AVK_LOG(mmi_frm_get_curr_entry_hdlr() == (entry_func_ptr)MMI_dummy_function));    

	mmi_frm_scrn_close_active_id();
	mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 inline_icon_list[] = { IMG_GLOBAL_L1,
                               0,
    	                       IMG_GLOBAL_L2,
    	                       0,
    	                     };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_entry_new_screen(
        AVK_SCR_ID_2,
        NULL,
        NULL,
        NULL);

   

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    InitializeCategory57Screen();

    SetInlineItemActivation(
        &(wgui_inline_items[0]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(&wgui_inline_items[0], (PU8)L"123");

    inputBuffer = GetCurrNInputBuffer(0, &inputBufferSize);		/* added for inline edit history */

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 1, inputBuffer);
    }
    RegisterHighlightHandler(avk_pluto_screen_001_highlight);

    ShowCategory57Screen(
        0,
        0,
		0,
		0,
		STR_GLOBAL_BACK,
		0,
		1,
		inline_icon_list,
		wgui_inline_items,
		0,
		guiBuffer);

    SetCategory57RightSoftkeyFunctions(avk_pluto_screen_001_test, GoBackHistory);
    if (!mmi_frm_is_in_backward_scenario())
    {
        if (GetExitScrnID() != AVK_SCR_ID_2)
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
        AVK_LOG(mmi_frm_get_exit_scrn_arg());
        StartTimer(0x1234,0,avk_pluto_screen_001_test);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001_create_check
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001_create_check(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//	mmi_frm_set_active_scrn_arg(NULL);
	avk_pluto_screen_001();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_001_pre_entry
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_001_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_active_scrn_arg((void*)0xC0DE);
    AVK_LOG_FUN(mmi_frm_set_active_scrn_arg,(void*)mmi_frm_get_active_scrn_arg() == (void*)0xC0DE);
    
	AVK_LOG(mmi_frm_create_new_screen(avk_pluto_screen_001_create_check, (void*)0xDEAD));
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_entry_highlight
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_entry_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetLeftSoftkeyFunction(avk_pluto_screen_001_pre_entry, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_exit
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_exit(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AVK_LOG_NORMAL(mmi_frm_generic_exit_scrn(AVK_SCR_ID_1, (entry_func_ptr)avk_pluto_screen_entry));
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_screen_entry
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 list_of_items[] = {0,
		                   0};
	U16 list_of_icons[] = {IMG_GLOBAL_L1,
		                   IMG_GLOBAL_L2};
	PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_entry_new_screen(
        AVK_SCR_ID_1,
        avk_pluto_screen_exit,
        NULL,
        NULL);
        
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(avk_pluto_screen_entry_highlight);
    SetHiliteHandler(0x1234, avk_pluto_screen_001_pre_entry);
    ShowCategory52Screen(0,
                         0,
                         STR_GLOBAL_OK,
                         0,
                         STR_GLOBAL_BACK,
                         0,
                         1,
                         list_of_items,
                         list_of_icons,
                         NULL,
                         1,
                         0,
                         gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (!mmi_frm_is_in_backward_scenario())
    {
        ExecuteItemHiliteHandler(0x1234);
    }
}
#endif
