AVK_ADD_ITEM(AVK_PLUTO_KEY_AUTO,L"Auto case",AVK_PLUTO_KEY);
AVK_ADD_ITEM(AVK_PLUTO_KEY_MANU,L"Manual case",AVK_PLUTO_KEY);

static void vs_fw_key_001_keyinfo_keyhandler_1(void);
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_001_keyinfo_keyhandler
 * DESCRIPTION
 *  group keys event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_key_001_keyinfo_keyhandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 code, type;
	wchar_t *keytype[] = {L" down!", 	L" up!", 	L" long press!", 	L" repeat!", 	L" half press down!", 	L" half press up!"};
	wchar_t *keycode[] = 
	{
		L"KEY_0", 			L"KEY_1", 			L"KEY_2", 			L"KEY_3", 			L"KEY_4", 			L"KEY_5",
		L"KEY_6", 			L"KEY_7", 			L"KEY_8", 			L"KEY_9", 			L"KEY_LSK",         L"KEY_RSK", 
		L"KEY_CSK",			L"KEY_UP_ARROW",	L"KEY_DOWN_ARROW", 	L"KEY_LEFT_ARROW", 	L"KEY_RIGHT_ARROW", L"KEY_SEND",  
		L"KEY_END",         L"KEY_CLEAR",		L"KEY_STAR", 		L"KEY_POUND", 		L"KEY_VOL_UP", 		L"KEY_VOL_DOWN",		
		L"KEY_QUICK_ACS",	L"KEY_ENTER",		L"KEY_EXTRA_1", 	L"KEY_EXTRA_2", 	L"KEY_PLAY_STOP", 	L"KEY_FWD", 		
		L"KEY_BACK",        L"KEY_POWER",		L"KEY_EXTRA_A", 	L"KEY_EXTRA_B"
		#ifdef __SENDKEY2_SUPPORT__
		, L"KEY_SEND1", 	L"KEY_SEND2"
		#endif
	};
	U32 input_style;
	U8 key_state;

	CHAR str_a[10];
	CHAR str_temp[5];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Query key code and key type */
    GetkeyInfo(&code, &type);

    gdi_layer_clear(GDI_COLOR_WHITE);

    /* Draw title and soft key button */
//    vs_tfw_draw_title(STR_ID_VS_FW_KEY_INFO);
    AVK_DRAW_SOFTKEY(KEY_RSK, STR_GLOBAL_CLEAR);
    ChangeLeftSoftkeyByString((UI_string_type)L" ", NULL);
	key_state = mmi_frm_query_mmi_key_state(code);
	input_style =(U8) mmi_query_input_style();
	mmi_frm_is_key_event();
    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(20, 160);
    gui_print_text((U16*)keycode[code]);
    gui_move_text_cursor(50, 200);
    gui_print_text((U16*)keytype[type]);
	gui_move_text_cursor(20, 240);
    gui_print_text((UI_string_type)L"KEY state --- input style");
	gui_move_text_cursor(50, 280);
	sprintf(str_temp,(CHAR*)"%d",key_state);
	mmi_asc_to_ucs2(str_a,str_temp);
    gui_print_text((U16*)str_a);
	gui_move_text_cursor(100, 280);
	sprintf((CHAR*)str_temp,(CHAR*)"%d",input_style);
	mmi_asc_to_ucs2(str_a,str_temp);
    gui_print_text((U16*)str_a);
    
    SetRightSoftkeyFunction(NULL,KEY_EVENT_UP);
	SetRightSoftkeyFunction(vs_fw_key_001_keyinfo_keyhandler_1, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_001_keyinfo_keyhandler_1
 * DESCRIPTION
 *  group keys event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_key_001_keyinfo_keyhandler_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 code = 0, type = 0;
	wchar_t *keytype[] = {L" down!", 	L" up!", 	L" long press!", 	L" repeat!", 	L" half press down!", 	L" half press up!", L" no type"};
    U16 current_keymap[] = 
	{
		KEY_0, 			KEY_1,			KEY_2, 				KEY_3, 			KEY_4, 			KEY_5, 
		KEY_6, 			KEY_7, 			KEY_8, 				KEY_9,			KEY_CSK, 		KEY_UP_ARROW, 
		KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, 	KEY_SEND, 		KEY_CLEAR,		KEY_STAR, 	
		KEY_POUND, 		KEY_VOL_UP, 	KEY_VOL_DOWN, 		KEY_QUICK_ACS, 	KEY_CAMERA, 	KEY_ENTER, 
		KEY_WAP,		KEY_IP, 		KEY_EXTRA_1, 		KEY_EXTRA_2, 	KEY_PLAY_STOP, 	KEY_FWD, 
		KEY_BACK, 		KEY_EXTRA_A,	KEY_EXTRA_B
	#ifdef __SENDKEY2_SUPPORT__
		, KEY_SEND1, KEY_SEND2
	#endif
	};
		wchar_t *keycode[] = 
	{
		L"KEY_0", 			L"KEY_1", 			L"KEY_2", 			L"KEY_3", 			L"KEY_4", 			L"KEY_5",
		L"KEY_6", 			L"KEY_7", 			L"KEY_8", 			L"KEY_9", 			L"KEY_LSK",         L"KEY_RSK", 
		L"KEY_CSK",			L"KEY_UP_ARROW",	L"KEY_DOWN_ARROW", 	L"KEY_LEFT_ARROW", 	L"KEY_RIGHT_ARROW", L"KEY_SEND",  
		L"KEY_END",         L"KEY_CLEAR",		L"KEY_STAR", 		L"KEY_POUND", 		L"KEY_VOL_UP", 		L"KEY_VOL_DOWN",		
		L"KEY_QUICK_ACS",	L"KEY_ENTER",		L"KEY_EXTRA_1", 	L"KEY_EXTRA_2", 	L"KEY_PLAY_STOP", 	L"KEY_FWD", 		
		L"KEY_BACK",        L"KEY_POWER",		L"KEY_EXTRA_A", 	L"KEY_EXTRA_B"
		#ifdef __SENDKEY2_SUPPORT__
		, L"KEY_SEND1", 	L"KEY_SEND2"
		#endif
	};
	
	U8 current_key_count = sizeof(current_keymap) / sizeof(U16);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Query key code and key type */

	SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_EVENT_DOWN);
    SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_EVENT_UP);
    SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_LONG_PRESS);
    SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_REPEAT);
    
	AVK_LOG_NORMAL(mmi_frm_clear_all_key_handler());
	AVK_LOG_MANUAL_NORMAL(GetkeyInfo(&code, &type));
    gdi_layer_clear(GDI_COLOR_WHITE);

    /* Draw title and soft key button */
//    vs_tfw_draw_title(STR_ID_VS_FW_KEY_INFO);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(20, 160);
    gui_print_text((U16*)keycode[code]);
    gui_move_text_cursor(70, 200);
    gui_print_text((U16*)keytype[type]);
	gui_move_text_cursor(20, 240);
    gui_print_text((UI_string_type)L"Press any key now");
	gui_move_text_cursor(20, 280);
    gui_print_text((UI_string_type)L"is it working");

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_001_keyinfo
 * DESCRIPTION
 *  Getkeyinfo() test case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_001_keyinfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 *info = (U16*)L"Please press a key!";
	U16 *info2 = (U16*)L"(LSK and RSK except)";
    U16 current_keymap[] = 
	{
		KEY_0, 			KEY_1,			KEY_2, 				KEY_3, 			KEY_4, 			KEY_5, 
		KEY_6, 			KEY_7, 			KEY_8, 				KEY_9,			KEY_CSK, 		KEY_UP_ARROW, 
		KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, 	KEY_SEND, 		KEY_CLEAR,		KEY_STAR, 	
		KEY_POUND, 		KEY_VOL_UP, 	KEY_VOL_DOWN, 		KEY_QUICK_ACS, 	KEY_CAMERA, 	KEY_ENTER, 
		KEY_WAP,		KEY_IP, 		KEY_EXTRA_1, 		KEY_EXTRA_2, 	KEY_PLAY_STOP, 	KEY_FWD, 
		KEY_BACK, 		KEY_EXTRA_A,	KEY_EXTRA_B
		#ifdef __SENDKEY2_SUPPORT__
		, KEY_SEND1, KEY_SEND2
		#endif
	};
	U8 current_key_count = sizeof(current_keymap) / sizeof(U16);
        MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
  
    ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_001_keyinfo, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE)
        return;
    gdi_layer_clear(GDI_COLOR_WHITE);
	
    /* Draw title */
//    vs_tfw_draw_title(STR_ID_VS_FW_KEY_INFO);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(20, 160);
    gui_print_text(info);
    gui_move_text_cursor(20, 200);
    gui_print_text(info2);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    AVK_LOG_NORMAL(ClearKeyEvents());
    
    /* Set key event handler */
    AVK_LOG_NORMAL(SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_EVENT_DOWN));
    AVK_LOG_NORMAL(SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_EVENT_UP));
    AVK_LOG_NORMAL(SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_LONG_PRESS));
    AVK_LOG_NORMAL(SetGroupKeyHandler(vs_fw_key_001_keyinfo_keyhandler, (PU16) current_keymap, current_key_count, KEY_REPEAT));
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_001,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"1.Press any key then its state(up or down) will be shown on screen with key no.\
    2.->then press clear \
    3.-> then no key will work if its is happening then pass",vs_fw_key_001_keyinfo);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_002_keytone_get
 * DESCRIPTION
 *  mmi_frm_kbd_get_key_tone_state test case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_key_002_keytone_get(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wchar_t *info = L"The Current Key tone state is:";
	U16 info2[50] = {0};
      MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
   	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_002_keytone_get, MMI_FRM_FULL_SCRN);

	if(ret == MMI_FALSE)
		return;

    gdi_layer_clear(GDI_COLOR_WHITE);

	switch(AVK_LOG(mmi_frm_kbd_get_key_tone_state()))
    {
        case MMI_KEY_TONE_ENABLED:
    		mmi_wcscpy(info2, (WCHAR*)L"TONE_ENABLED");
    		break;
    	case MMI_KEY_VOL_TONE_DISABLED:
    		mmi_wcscpy(info2, (WCHAR*)L"VOL_TONE_DISABLED");
    		break;
    	case MMI_KEY_VOL_UP_DOWN_TONE_DISABLED:
    		mmi_wcscpy(info2, (WCHAR*)L"VOL_UP_DOWN_TONE_DISABLED");
    		break;
    	case MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED:
    		mmi_wcscpy(info2, (WCHAR*)L"RIGHT_LEFT_ARROW_TONE_DISABLED");
    		break;
    	case MMI_KEY_TONE_DISABLED:
    		mmi_wcscpy(info2, (WCHAR*)L"TONE_DISABLED");
    		break;
    	default :
    		break;
    }

    /* Draw title and soft key button */
//    vs_tfw_draw_title(STR_ID_VS_FW_KEY_TONE);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(20, 160);
    gui_set_font(&MMI_small_font);
    gui_print_text((U16*)info);
    gui_move_text_cursor(20, 200);
    gui_print_text(info2);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif    
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_002,AVK_PLUTO_KEY_MANU)
{
    vs_fw_key_002_keytone_get();
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_002_keytone_set
 * DESCRIPTION
 *  mmi_frm_kbd_get_key_tone_state test case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_fw_key_002_keytone_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *info = NULL;
#ifndef __COSMOS_MMI_PACKAGE__
	U16 *info1 = (U16 *)L"Key Tone Enable, Please try it.";
#endif
	U16 *info2 = (U16 *)L"Key Tone Disable, Please try it.";
    
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
 	ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_002_keytone_set, MMI_FRM_FULL_SCRN);

	if(ret == MMI_FALSE)
		return;

	if (AVK_LOG(mmi_frm_kbd_get_key_tone_state()) == MMI_KEY_TONE_DISABLED)
    {
#ifdef __COSMOS_MMI_PACKAGE__
	info = info2;
#else
        AVK_LOG_NORMAL(mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED));
        info = info1;
#endif
    }
    else
    {
        AVK_LOG_NORMAL(mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED));
        info = info2;
    }	

    gdi_layer_clear(GDI_COLOR_WHITE);
    /* Draw title and soft key button */
//    vs_tfw_draw_title(STR_ID_VS_FW_KEY_TONE);
    AVK_DRAW_SOFTKEY(KEY_RSK, AVK_STR_FAIL);
    AVK_DRAW_SOFTKEY(KEY_LSK, AVK_STR_PASS);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(20, 160);
    gui_set_font(&MMI_small_font);
    gui_print_text(info);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    
    /* Set key event handler */
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif    
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_003,AVK_PLUTO_KEY_MANU)
{
    vs_fw_key_002_keytone_set();
}

AVK_CASE(AVK_PLUTO_KEY_AUTO_001,AVK_PLUTO_KEY_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	U16 keyCode;
	U16 keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_NORMAL(mmi_frm_set_key_info(KEY_1,KEY_EVENT_DOWN));
	AVK_LOG_NORMAL(mmi_frm_get_key_info(&keyCode,&keyType));

	AVK_CASE_RESULT(keyCode == KEY_1 && keyType == KEY_EVENT_DOWN);	
}



void vs_fw_key_004_dummy_fn(void)
{
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_004_get_keyhndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_KEY_AUTO_002,AVK_PLUTO_KEY_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*fun_ptr)(void)=NULL;
    void (*fun_ptr_1)(void)=NULL;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fun_ptr_1 = vs_fw_key_004_dummy_fn;
    AVK_LOG_NORMAL(mmi_frm_set_key_handler(vs_fw_key_004_dummy_fn,KEY_1,KEY_EVENT_DOWN));
	AVK_LOG_ASYN(fun_ptr = mmi_frm_get_key_handler(KEY_1,KEY_EVENT_DOWN));

	
	AVK_CASE_RESULT(fun_ptr == fun_ptr_1) ;
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_005_get_keyhndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_005_get_devkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 dev_key_code = 0;
	MMI_BOOL screen_ret;
	CHAR str_a[10];
	CHAR str_temp[5];
	PU16 screen_asmp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_005_get_devkey, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
    screen_asmp = (U16*) AVK_MALLOC(1024);

    AVK_LOG_MANUAL(dev_key_code = mmi_frm_get_dev_key_code(KEY_STAR));
    mmi_wcscpy(screen_asmp, (WCHAR *)L"The device key code of KEY_STAR =");
    sprintf((CHAR*)str_temp,(CHAR*)"%d",dev_key_code);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_ucs2cat((CHAR *)screen_asmp,(CHAR *) str_a);
    
    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) screen_asmp,
        mmi_wcslen(screen_asmp),
        NULL);
		
	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(screen_asmp);
	
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_004,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If see value of key_star then pass",vs_fw_key_005_get_devkey);
}


/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_006
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_006(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret;
	PU16 screen_asmp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_006, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
	screen_asmp = (U16*) AVK_MALLOC(1024);

    mmi_wcscpy(screen_asmp, (WCHAR *)L"1. Key_tone for key 1 down =DTMF \n 2. Key_tone for key 1 down =MAX");

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) screen_asmp,
        mmi_wcslen(screen_asmp),
        NULL);

    AVK_LOG_NORMAL(mmi_frm_key_tone_player(KEY_1,KEY_EVENT_DOWN));
    AVK_LOG_NORMAL(mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF));
    mmi_frm_key_tone_player(KEY_1,KEY_EVENT_DOWN);
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_MAX);

    AVK_FREE(screen_asmp);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    	
	
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_005,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Properties of key_tone for is shown then pass",vs_fw_key_006);
}


void vs_fw_key_007_dummy_fn(U16 hndlr_result)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static U16 static_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	if(hndlr_result>static_result)
	{
		static_result = hndlr_result;
	}
	if(static_result == 5)
	{
		AVK_CASE_RESULT(AVK_PASS);
	}
	else if(hndlr_result == 2)
	{
		AVK_CASE_RESULT(AVK_FAIL);
	}
	
}
void vs_fw_key_007_key_1_hdlr(void)
{
	vs_fw_key_007_dummy_fn(1);
}
void vs_fw_key_007_key_2_hdlr(void)
{
	vs_fw_key_007_dummy_fn(5);
}

AVK_CASE(AVK_PLUTO_KEY_AUTO_003,AVK_PLUTO_KEY_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_NORMAL(SetKeyHandler(vs_fw_key_007_key_1_hdlr,KEY_1,KEY_EVENT_DOWN));
    SetKeyHandler(vs_fw_key_007_key_2_hdlr,KEY_2,KEY_EVENT_DOWN);
    AVK_LOG_NORMAL(mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER));
    AVK_LOG_NORMAL(mmi_frm_exec_key_handler(KEY_1,KEY_EVENT_DOWN));
    mmi_frm_exec_key_handler(KEY_2,KEY_EVENT_DOWN);
    vs_fw_key_007_dummy_fn(2);		
}

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)

void vs_fw_key_008_cb(U32 special_key_flag, U32 special_key_lock_flag)
{
    CHAR str_a[10];
    CHAR str_temp[5];

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(0,120);
    gdi_draw_solid_rect(0, 120, 320, 200, GDI_COLOR_WHITE);
    gui_print_text((UI_string_type)L"Special Key");
    gui_move_text_cursor(0,160);
    sprintf((CHAR*)str_temp,(CHAR*)"%d",special_key_flag);
    mmi_asc_to_ucs2(str_a,str_temp);
    gui_print_text((UI_string_type)str_a);
    gdi_layer_blt_previous(0, 160, 320, 200);
}

void vs_fw_key_008_clear_key()
{
	mmi_frm_qwerty_clear_customized_special_key_flag_change_callback();
}
#endif
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_008
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_fw_key_008 (void)
{
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables												 */
    /*----------------------------------------------------------------*/
    MMI_BOOL screen_ret;

    /*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/	   
    screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_008, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;	  
    }	   
	
    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);		  
	   
    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(0,80);
    gui_print_text((UI_string_type)L"Press 1 to clear special key");

    AVK_LOG_NORMAL(mmi_frm_qwerty_register_customized_special_key_flag_change_callback(vs_fw_key_008_cb));
    SetKeyHandler(vs_fw_key_008_clear_key, KEY_1,KEY_EVENT_DOWN);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#else 
    AVK_LOG_FUN_UNSUPPORTED(mmi_frm_qwerty_register_customized_special_key_flag_change_callback);
    AVK_ASYN_DONE();
#endif    

}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_006,AVK_PLUTO_KEY_MANU)
{
    vs_fw_key_008();
}


MMI_BOOL vs_fw_key_009_key_hndlr(S16 key_code, S16 key_type, U16 ucs2_value, U32 key_flag);
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_009_key_hndlr_star
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_009_key_hndlr_star(void)
{
	mmi_frm_set_app_translate_key_handler(vs_fw_key_009_key_hndlr);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_009_key_hndlr_pound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_009_key_hndlr_pound(void)
{
    mmi_frm_clear_app_translate_key_handler(vs_fw_key_009_key_hndlr);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_009_key_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vs_fw_key_009_key_hndlr(S16 key_code, S16 key_type, U16 ucs2_value, U32 key_flag)
{

	wchar_t *keycode[] = 
	{
		L"KEY_0", 			L"KEY_1", 			L"KEY_2", 			L"KEY_3", 			L"KEY_4", 			L"KEY_5",
		L"KEY_6", 			L"KEY_7", 			L"KEY_8", 			L"KEY_9", 			L"KEY_LSK",         L"KEY_RSK", 
		L"KEY_CSK",			L"KEY_UP_ARROW",	L"KEY_DOWN_ARROW", 	L"KEY_LEFT_ARROW", 	L"KEY_RIGHT_ARROW", L"KEY_SEND",  
		L"KEY_END",         L"KEY_CLEAR",		L"KEY_STAR", 		L"KEY_POUND", 		L"KEY_VOL_UP", 		L"KEY_VOL_DOWN",		
		L"KEY_QUICK_ACS",	L"KEY_ENTER",		L"KEY_EXTRA_1", 	L"KEY_EXTRA_2", 	L"KEY_PLAY_STOP", 	L"KEY_FWD", 		
		L"KEY_BACK",        L"KEY_POWER",		L"KEY_EXTRA_A", 	L"KEY_EXTRA_B"
		#ifdef __SENDKEY2_SUPPORT__
		, L"KEY_SEND1", 	L"KEY_SEND2"
		#endif
	};
	gui_set_text_color(gui_color(0, 0, 0));
	gui_move_text_cursor(0,80);
	gdi_draw_solid_rect(0, 80, 320, 120, GDI_COLOR_WHITE);
	gui_print_text((UI_string_type)keycode[key_code]);
	gdi_layer_blt_previous(0, 80, 320, 120);
	if((key_code == KEY_STAR) || (key_code == KEY_POUND))
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_009
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_009(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_009, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
	
    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);

    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(0,80);
    gui_print_text((UI_string_type)L"No Event");
#ifndef REDUCED_KEYPAD
    gui_move_text_cursor(0, 120);
    gui_print_text((UI_string_type)L"press # to clear key handler");
    gui_move_text_cursor(0, 160);
    gui_print_text((UI_string_type)L"press * to set key handlers again");
#endif
    AVK_LOG_NORMAL(mmi_frm_set_app_translate_key_handler((mmi_frm_translate_keyhandler_func_ptr)vs_fw_key_009_key_hndlr));
    SetKeyHandler(vs_fw_key_009_key_hndlr_star,KEY_STAR,KEY_EVENT_UP);
    SetKeyHandler(vs_fw_key_009_key_hndlr_pound,KEY_POUND,KEY_EVENT_UP);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_007,AVK_PLUTO_KEY_MANU)
{   
#ifdef REDUCED_KEYPAD
	AVK_MANU_SHOW_TIPS(L"Press any key:-its value will be shown on screen."
            ,vs_fw_key_009);	

#else
    AVK_MANU_SHOW_TIPS(L"1.Press any key:-its value will be shown on screen:-press # to clear keys(keys will not work)\
            2.And press * to reset keys(keys will start working)",vs_fw_key_009);
#endif


}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_010
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

AVK_CASE(AVK_PLUTO_KEY_AUTO_004,AVK_PLUTO_KEY_AUTO)
{
#ifdef __MMI_TOUCH_SCREEN__

	void (*mmi_pen_hdlr_temp) (mmi_pen_point_struct);
	mmi_pen_hdlr_temp = NULL; 
	AVK_LOG_NORMAL(mmi_pen_register_down_handler(mmi_pen_dummy_hdlr));

	AVK_LOG(mmi_pen_hdlr_temp = mmi_pen_get_pen_handler(MMI_PEN_EVENT_DOWN));
	
	AVK_CASE_RESULT(mmi_pen_hdlr_temp == mmi_pen_dummy_hdlr);	
#else 
	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_down_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_get_pen_handler);
#endif
		
}

#ifdef __MMI_TOUCH_SCREEN__    
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_011_down_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_fw_key_011_down_hndlr(mmi_pen_point_struct pos)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_pen_event_type_enum pen_type;
	mmi_pen_stroke_type_enum stroke_type;
	wchar_t *pen_type_arr[] =
		{
		 L"MMI_PEN_EVENT_DOWN" ,		L"MMI_PEN_EVENT_UP",			L"MMI_PEN_EVENT_LONG_TAP",  
   		 L"MMI_PEN_EVENT_REPEAT",		L"MMI_PEN_EVENT_MOVE",			L"MMI_PEN_EVENT_ABORT",
         L"MMI_PEN_EVENT_DOUBLE_CLICK", L"MMI_PEN_EVENT_NONE"
         };
	wchar_t *stroke_type_arr[] = 
		{
		 L"MMI_PEN_STROKE_DOWN",		L"MMI_PEN_STROKE_UP",		  L"MMI_PEN_STROKE_MOVE",
         L"MMI_PEN_STROKE_LONGTAP",		L"MMI_PEN_STROKE_NONE"
         };
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	/*lsk*/
	if ((pos.x < AVK_FRAMEWORK_SOFTKEY_WIDTH) &&(pos.x > 0)
		&&(pos.y > LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_LEFT_SOFTKEY);
		return;
	}

	/*rsk*/
	else if ((pos.x < LCD_WIDTH)&& (pos.x > LCD_WIDTH - AVK_FRAMEWORK_SOFTKEY_WIDTH)&&
		(pos.y >LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_RIGHT_SOFTKEY);
		return;
	}
	else 
	{
		mmi_pen_get_info(&pen_type,&stroke_type);
		
	   	gui_set_text_color(gui_color(0, 0, 0));
		gui_move_text_cursor(0,80);
		gdi_draw_solid_rect(0, 80, 320, 240, GDI_COLOR_WHITE);
		gui_print_text((UI_string_type)L"Pen Type");
		gui_move_text_cursor(0,120);
		gui_print_text((UI_string_type)pen_type_arr[pen_type]);
		gui_move_text_cursor(0,160);
		gui_print_text((UI_string_type)L"Stroke Type");
		gui_move_text_cursor(0,200);
		gui_print_text((UI_string_type)stroke_type_arr[stroke_type]);
		gdi_layer_blt_previous(0, 80, 320, 240);
	}

}
#endif /*__MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_011
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_011(void)
{
#ifdef __MMI_TOUCH_SCREEN__   
     /*----------------------------------------------------------------*/
    /* Local Variables                                            					   	     */
    /*---------------------------------------------------------------- */
	MMI_BOOL screen_ret;
	mmi_pen_event_type_enum pen_type;
	mmi_pen_stroke_type_enum stroke_type;
	wchar_t *pen_type_arr[] =
		{
		 L"MMI_PEN_EVENT_DOWN" ,		L"MMI_PEN_EVENT_UP",			L"MMI_PEN_EVENT_LONG_TAP",  
   		 L"MMI_PEN_EVENT_REPEAT",		L"MMI_PEN_EVENT_MOVE",			L"MMI_PEN_EVENT_ABORT",
         L"MMI_PEN_EVENT_DOUBLE_CLICK", L"MMI_PEN_EVENT_NONE"
         };
	wchar_t *stroke_type_arr[] = 
		{
		 L"MMI_PEN_STROKE_DOWN",		L"MMI_PEN_STROKE_UP",		  L"MMI_PEN_STROKE_MOVE",
         L"MMI_PEN_STROKE_LONGTAP",		L"MMI_PEN_STROKE_NONE"
         };


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_011, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }	

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);

	mmi_pen_get_info(&pen_type,&stroke_type);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(0,80);
    gui_print_text((UI_string_type)L"Pen Type");
    gui_move_text_cursor(0,120);
    gui_print_text((UI_string_type)pen_type_arr[pen_type]);
    gui_move_text_cursor(0,160);
    gui_print_text((UI_string_type)L"Stroke Type");
    gui_move_text_cursor(0,200);
    gui_print_text((UI_string_type)stroke_type_arr[stroke_type]);
    AVK_LOG_NORMAL(mmi_pen_register_down_handler(vs_fw_key_011_down_hndlr));
    AVK_LOG_NORMAL(mmi_pen_register_up_handler(vs_fw_key_011_down_hndlr));
    
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL); 
#else 
	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_down_handler);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_up_handler);
    AVK_ASYN_DONE();
#endif
		
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_008,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Touch the screen when it is touching the screen it will show down state otherwise up state: then pass",vs_fw_key_011);
}

#ifdef __MMI_TOUCH_SCREEN__ 

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_012_down_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


void vs_fw_key_012_down_hndlr(mmi_pen_point_struct pos)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	kal_bool is_enabled,is_pen_down;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	/*lsk*/
	if ((pos.x < AVK_FRAMEWORK_SOFTKEY_WIDTH) &&(pos.x > 0)
		&&(pos.y > LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_LEFT_SOFTKEY);
		mmi_pen_reset();
		return;
	}

	/*rsk*/
	else if ((pos.x < LCD_WIDTH)&& (pos.x > LCD_WIDTH - AVK_FRAMEWORK_SOFTKEY_WIDTH)&&
		(pos.y >LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_RIGHT_SOFTKEY);
		mmi_pen_reset();
		return;
	}
	else 
	{		
	   	gui_set_text_color(gui_color(0, 0, 0));
		gui_move_text_cursor(0,80);
		gdi_draw_solid_rect(0, 80, 320, 160, GDI_COLOR_WHITE);
		mmi_pen_get_state(&is_enabled,&is_pen_down);
		if(is_enabled)
			gui_print_text((UI_string_type)L"PEN Enabled");
		else
			gui_print_text((UI_string_type)L"PEN Disabled");

		gui_move_text_cursor(0,120);

		if(is_pen_down)
			gui_print_text((UI_string_type)L"PEN DOWN");
		else
			gui_print_text((UI_string_type)L"PEN UP");
		gdi_layer_blt_previous(0, 80, 320, 240);
	}

}
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_012_double_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void vs_fw_key_012_double_hndlr(void)
{
	mmi_display_popup((UI_string_type)L"Double Click Handler",MMI_EVENT_INFO);
}

#endif /*__MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_012
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_012(void)
{
   #ifdef __MMI_TOUCH_SCREEN__   
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret;
	kal_bool is_enabled,is_pen_down;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_012, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
	

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);
   
	mmi_pen_get_state(&is_enabled,&is_pen_down);
	gui_set_text_color(gui_color(0, 0, 0));
	gui_move_text_cursor(0,80);
	if(is_enabled)
		gui_print_text((UI_string_type)L"PEN Enabled");
	else
		gui_print_text((UI_string_type)L"PEN Disabled");

	gui_move_text_cursor(0,120);

	if(is_pen_down)
		gui_print_text((UI_string_type)L"PEN DOWN");
	else
		gui_print_text((UI_string_type)L"PEN UP");
	
	AVK_LOG_NORMAL(mmi_pen_register_down_handler(vs_fw_key_012_down_hndlr));
	AVK_LOG_NORMAL(mmi_pen_register_up_handler(vs_fw_key_012_down_hndlr));
	AVK_LOG_NORMAL(mmi_pen_register_double_click_handler(vs_fw_key_012_down_hndlr));

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);		
#else 
	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_double_click_handler);
	AVK_ASYN_DONE();
#endif
		
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_009,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Touch the screen when it is touching the screen it will show down state otherwise up state: then pass",vs_fw_key_012);
}

#ifdef __MMI_TOUCH_SCREEN__ 
/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_013_down_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


void vs_fw_key_013_down_hndlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	CHAR str_a[50];
	CHAR str_temp[25];
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	/*lsk*/
	if ((pos.x < AVK_FRAMEWORK_SOFTKEY_WIDTH) &&(pos.x > 0)
		&&(pos.y > LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_LEFT_SOFTKEY);
		return;
	}

	/*rsk*/
	else if ((pos.x < LCD_WIDTH)&& (pos.x > LCD_WIDTH - AVK_FRAMEWORK_SOFTKEY_WIDTH)&&
		(pos.y >LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
	{
		execute_softkey_function(1,MMI_RIGHT_SOFTKEY);
		return;
	}
	else 
	{	
		return;	
	}
	
}
#endif /*__MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_013
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_fw_key_013(void)
{
   #ifdef __MMI_TOUCH_SCREEN__   
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	screen_ret = mmi_frm_scrn_enter(GRP_ID_AVK, AVK_SCR_ID_1, NULL, vs_fw_key_012, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
	
    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);
	   
	
	gui_set_text_color(gui_color(0, 0, 0));
	gui_move_text_cursor(0,80);
	gui_print_text((UI_string_type)L"Touch on screen");

	mmi_pen_register_down_handler(vs_fw_key_013_down_hndlr);
	mmi_pen_register_up_handler(vs_fw_key_013_down_hndlr);

	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
#else 
	AVK_LOG_FUN_UNSUPPORTED(mmi_pen_register_double_click_handler);
	AVK_ASYN_DONE();
#endif		
}

AVK_MANUAL_CASE(AVK_PLUTO_KEY_MANU_010,AVK_PLUTO_KEY_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Touch on the screen then values of stated variables will be shown for the pen event and previous pen event",vs_fw_key_013);
}

/*****************************************************************************
 * FUNCTION
 *  vs_fw_key_014
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_KEY_AUTO_005,AVK_PLUTO_KEY_AUTO)
{
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_calibration_struct calibration_data,calibration_data_set,ori_data;

	calibration_data_set.data[0]=5;
	calibration_data_set.data[1]=7.5;
	calibration_data_set.data[2]=3.2;
	calibration_data_set.data[3]=4.9;
	
	/*mmi_pen_start_calibration(3,pen_point);*/
	mmi_pen_read_calibration_data(&ori_data);
	AVK_LOG_ASYN_NORMAL(mmi_pen_set_calibration_data(&calibration_data_set));
	AVK_LOG_ASYN_NORMAL(mmi_pen_read_calibration_data(&calibration_data));
	mmi_pen_set_calibration_data(&ori_data);
	if(
		calibration_data_set.data[0]==calibration_data.data[0]&&
		calibration_data_set.data[1]==calibration_data.data[1]&&
		calibration_data_set.data[2]==calibration_data.data[2]&&
		calibration_data_set.data[3]==calibration_data.data[3]
	  )
	{
		AVK_CASE_RESULT(AVK_PASS);
	}
	else
	{
		AVK_CASE_RESULT(AVK_FAIL);	
	}
#else 
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_set_calibration_data);
    AVK_LOG_FUN_UNSUPPORTED(mmi_pen_read_calibration_data);
#endif
}

