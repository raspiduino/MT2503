
extern "C" void avk_pluto_rotation_entry(void);

AVK_MANUAL_CASE(AVK_PLUTO_ROTATION_AUTO_001,AVK_PLUTO_ROTATION)
{
    avk_pluto_rotation_entry();

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
void avk_pluto_rotation_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 list_of_items[] = {STR_GLOBAL_1,
		                   STR_GLOBAL_2};
	U16 list_of_icons[] = {IMG_GLOBAL_L1,
		                   IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_rotation_entry, MMI_FRM_FULL_SCRN))
	{
		return;
	}
    #ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    #endif
    ShowCategory52Screen(0,
                         0,
                         AVK_STR_PASS,
                         0,
                         AVK_STR_FAIL,
                         0,
                         1,
                         list_of_items,
                         list_of_icons,
                         NULL,
                         1,
                         0,
                         NULL);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

