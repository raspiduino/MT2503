


#include "mmi_features.h"

#ifdef __MMI_GB_WINGUO_ULTRA__//__GB_WINGUO_4_U__

#include "MMI_include.h"
#include "IdleAppProt.h"
#include "Browser_api.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"

#include "CommonScreensResDef.h"
#include "BrowserAppTypes.h"
#ifdef BROWSER_SUPPORT
#include "mmi_rp_app_browser_def.h"
#endif
#include "wap_adp.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvInterface.h"
#include "BrowserAppMain.h"

#include "mmi_rp_app_gb_winguo_def.h"
#include "GB_WG_ultra_app.h"




#define GB_WG_MMI_SEARCH_WEB_WINGUO_MAX_INPUT_LEN (32)

/*#define MMI_SEARCH_WEB_WINGUO_DEFAULT_HOT_KEY        (MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY)*/

/*extern U16* GB_WG_GetWinguoAccessUrl(U16 *inputString);*/

mmi_id GB_WG_Search_Web_Launch(void);

extern WCH16 *GB_WG_DefaultHomePage(void);


U16 *g_p_winguo_request_input_buffer = NULL;

//不需要每次都弹出设为主页的提示
int g_gb_wg_set_home_page_flag = 0;

#include "SearchWebGProt.h"
#ifdef BROWSER_SUPPORT
#define MMI_SEARCH_WEB_WINGUO_DEFAULT_HOT_KEY        (MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY)
static mmi_search_web_hot_key_enum g_gb_wg_hot_key = MMI_SEARCH_WEB_WINGUO_DEFAULT_HOT_KEY;
#endif

static void GB_WG_Search_Web_Init(void)
{
	if (g_p_winguo_request_input_buffer == NULL)
	{
		g_p_winguo_request_input_buffer = (U16*)OslMalloc((GB_WG_MMI_SEARCH_WEB_WINGUO_MAX_INPUT_LEN+1)*sizeof(U16));
		memset(g_p_winguo_request_input_buffer, 0, (GB_WG_MMI_SEARCH_WEB_WINGUO_MAX_INPUT_LEN+1)*sizeof(U16));
	}	
}

static void GB_WG_Search_Web_Release(void)
{
	if (g_p_winguo_request_input_buffer != NULL)
	{
		OslMfree(g_p_winguo_request_input_buffer);
		g_p_winguo_request_input_buffer = NULL;
	}
}

static void GB_WG_Search_Web_Close(void)
{
	if (mmi_frm_group_get_active_id() == GRP_GB_WINGUO_SCREEN)
	{
		mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);
	}	
}

static void GB_WG_Search_Web_RequestEx(U16* pInputBuff)
{
	if (pInputBuff)
	{
		GB_WG_SeachString(pInputBuff);
	}
}

void GB_WG_Search_Web_Request(void)
{
	GB_WG_Search_Web_RequestEx(g_p_winguo_request_input_buffer);
}

// static void GB_WG_Search_Web_Set_Key_Handlers(void)
// {
// 	if (mmi_frm_scrn_get_active_id() == SCR_GB_WINGUO_SCREEN)
// 	{
// 		SetKeyHandler(GB_WG_Search_Web_Request, KEY_LSK, KEY_EVENT_DOWN);
// 	}
// }

static void GB_WG_Search_Web_Entry(void)
{
#ifdef BROWSER_SUPPORT
	U8 *gui_buffer = NULL;

	if (!mmi_frm_scrn_enter(
		GRP_GB_WINGUO_SCREEN,
		SCR_GB_WINGUO_SCREEN,
		NULL,
		(FuncPtr)GB_WG_Search_Web_Entry,
		MMI_FRM_SMALL_SCRN))
	{
		return;
	}

	//set_softkey_icon((PU8)get_image(IMG_WG_WINGUO_LOGO_OUT), MMI_CENTER_SOFTKEY);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
	wgui_cat2001_setup_search_button(
		(PU8)get_image(IMG_GB_WINGUO_SKINWHITE_SEARCH),
		(PU8)get_image(IMG_GB_WINGUO_SKINWHITE_SEARCH),
		GB_WG_Search_Web_Request);
#endif

	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_GB_WINGUO_SCREEN,SCR_GB_WINGUO_SCREEN);

	wgui_cat2001_show(
		(PU8)get_image(IMG_WG_WINGUO_LOGO_OUT),
		(UI_string_type)get_string(STR_GB_WINGUO_SEARCH),
		get_image(IMG_GLOBAL_OPTIONS),
		(UI_string_type)get_string(STR_GLOBAL_BACK),
		get_image(IMG_GLOBAL_BACK),
		IMM_INPUT_TYPE_SENTENCE,
		(U8*)g_p_winguo_request_input_buffer,
		(GB_WG_MMI_SEARCH_WEB_WINGUO_MAX_INPUT_LEN+1)*2,/*sizeof(g_p_winguo_request_input_buffer),*/
		gui_buffer,
		NULL,
		0);

 	SetLeftSoftkeyFunction(GB_WG_Search_Web_Request, KEY_EVENT_UP);
 	wgui_cat2001_set_rsk_function(GB_WG_Search_Web_Close, KEY_EVENT_UP);
 	SetKeyHandler(GB_WG_Search_Web_Request, KEY_ENTER, KEY_EVENT_UP);
// 	SetCenterSoftkeyFunction(GB_WG_Search_Web_Request, KEY_EVENT_UP);
//	register_center_softkey_to_enter_key();
// 	GB_WG_Search_Web_Set_Key_Handlers();
// 	wgui_cat2001_set_special_key_function(GB_WG_Search_Web_Set_Key_Handlers);
#endif
}


static mmi_ret GB_WG_GroupScreenProc(mmi_event_struct *evt) 
{
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
			GB_WG_Search_Web_Release();
			break;
	}
	return MMI_RET_OK;
}
void GB_WG_Search_Web_Highlight_Hdlr(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(GB_WG_Search_Web_Launch, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(GB_WG_Search_Web_Launch, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

mmi_id GB_WG_Search_Web_LaunchEx(void)
{
	if (mmi_frm_group_is_present(GRP_GB_WINGUO_SCREEN))
	{
		mmi_popup_display(
			get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
			MMI_EVENT_FAILURE,
			NULL);
		return GRP_ID_INVALID;
	}

	GB_WG_Search_Web_Init();

	mmi_frm_group_create(GRP_ID_ROOT, GRP_GB_WINGUO_SCREEN, GB_WG_GroupScreenProc,NULL);
	mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_scrn_first_enter(
		GRP_GB_WINGUO_SCREEN,
		SCR_GB_WINGUO_SCREEN,
		(FuncPtr)GB_WG_Search_Web_Entry,
		NULL);


	return GRP_GB_WINGUO_SCREEN;
}

void GB_WG_Set_Url_As_Homepage_OK(void)
{
#ifdef BROWSER_SUPPORT
	U16 *pHomePage = (U16*)GB_WG_DefaultHomePage();

	srv_brw_set_as_homepage((U8*)pHomePage);

	mmi_frm_scrn_close_active_id();

	GB_WG_Search_Web_LaunchEx();

	if (pHomePage)
	{
		OslMfree(pHomePage);
		pHomePage = NULL;
	}

	g_gb_wg_set_home_page_flag = 1;
#endif
}

void GB_WG_Set_Url_As_Homepage_Cancel(void)
{
	mmi_frm_scrn_close_active_id();

	GB_WG_Search_Web_LaunchEx();

	g_gb_wg_set_home_page_flag = 1;
}

mmi_ret GB_WG_Set_SearchWeb_Homepage()
{
#ifdef BROWSER_SUPPORT
	U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

	mmi_ucs2cpy((S8*) msgStr, (S8*) get_string(STR_GB_WINGUO_HOMEPAGE));
	
 	if(g_brw_app_cntx.brw_scr_group_id != GRP_ID_INVALID)
 	{
		mmi_frm_group_close(g_brw_app_cntx.brw_scr_group_id);
		g_brw_app_cntx.brw_scr_group_id = GRP_ID_INVALID;
 		mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, GB_WG_Set_Url_As_Homepage_OK, GB_WG_Set_Url_As_Homepage_Cancel, MMI_FALSE);
 	}
 	else
 	{
 		mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, GB_WG_Set_Url_As_Homepage_OK, GB_WG_Set_Url_As_Homepage_Cancel, MMI_FALSE);
 	}
#endif
	return MMI_RET_OK;
}

mmi_id GB_WG_Search_Web_Launch(void)
{
#ifdef BROWSER_SUPPORT
	U8 *pUrl_ascii = NULL;
	WCH16 *pHomePage = NULL;
	U8 *pHome = NULL;
	U8 *pTemp = NULL;
	unsigned int lens = 0;

	pUrl_ascii = (U8*) OslMalloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	memset(pUrl_ascii, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	//srv_brw_get_user_defined_homepage(pUrl_ascii);
	srv_brw_get_homepage(pUrl_ascii);

	pHomePage = (WCH16*)GB_WG_DefaultHomePage();

	pHome = (U8*) OslMalloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	memset(pHome, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);

	mmi_wcs_to_asc(pHome,pHomePage);

	if (strstr(pHome,"cachetime"))
	{
		pTemp = strstr(pHome,"cachetime");
		lens = pTemp - pHome;
	}

	if (lens > 0)
	{
		if (strncmp(pUrl_ascii,pHome,lens) == 0)
		{
			goto ENDLAUNCH;
		}	
	}
	else
	{
		if (strncmp(pUrl_ascii,pHome,strlen(pHome)) == 0)
		{
			goto ENDLAUNCH;
		}
	}

	if (g_gb_wg_set_home_page_flag == 0)
	{
		OslMfree(pUrl_ascii);
		OslMfree(pHome);
		OslMfree(pHomePage);
		GB_WG_Set_SearchWeb_Homepage();	
	}
	else
	{
		goto ENDLAUNCH;
	}
#endif
	return 1;
#ifdef BROWSER_SUPPORT
ENDLAUNCH:
	OslMfree(pUrl_ascii);
	OslMfree(pHome);
	OslMfree(pHomePage);
	return GB_WG_Search_Web_LaunchEx();
#endif
}

#ifdef BROWSER_SUPPORT
MMI_BOOL GB_WG_Net_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key)
{
#if defined(__MMI_VUI_LAUNCHER_KEY__)
	/* We provide hint on key_launcher projects */
	if(hot_key == MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT)
	{
		if(g_gb_wg_hot_key == MMI_SEARCH_WEB_HOT_KEY_NONE || g_gb_wg_hot_key == MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR)
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
		return (g_gb_wg_hot_key == hot_key);
	}    			
#else

	return (g_gb_wg_hot_key == hot_key);

#endif
}
#endif

MMI_BOOL GB_WG_Net_get_idle_hint_config(const U8 **icon_data, const WCHAR **string)
{
#ifdef BROWSER_SUPPORT
	if (!GB_WG_Net_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT))
	{
		*icon_data = NULL;
		*string = NULL;

		return MMI_FALSE;
	}

	*icon_data = get_image(IMG_WG_WINGUO_LOGO_OUT);

	*string = get_string(STR_GB_WINGUO_NET_PRESS_UP);
#endif
	return MMI_TRUE;
}

void GB_WG_Native_Search_By_key_Down(void)
{
	GB_WG_Search_Web_Launch();
}

#endif /* __MMI_GB_WINGUO_ULTRA__//__GB_WINGUO_4_U__  */
