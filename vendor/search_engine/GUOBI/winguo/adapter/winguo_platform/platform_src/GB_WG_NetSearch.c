
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#include "MMI_include.h"

#include "GB_ConfigDef.h"
#include "GB_WG_Public.h"
#include "Browser_api.h"
#ifdef __WINGUO_USE_ASM_2_0__
#include "mmi_frm_app_launcher_gprot.h"
#endif

/****************************************************/
//add net search scf

#if !defined(__COSMOS_MMI_PACKAGE__)
#include "IdleAppProt.h"
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
#endif

#include "mmi_rp_app_gb_winguo_def.h"
#include "mmi_rp_app_gb_winguo_net_def.h"

/****************************************************/

#define GB_WG_MAX_URL_LEN 400
#define WINGUOSEARCHURL "http://winguo.com:8080/winguo4/winguo!search.do"
#define WINGUOHOMEPAGEURL "http://winguo.com:8080/winguo4/winguo!defaultPage.do"

/****************************************************/
//add net search scf

#define GB_WG_MMI_SEARCH_WEB_WINGUO_MAX_INPUT_LEN (32)
mmi_id GB_WG_Search_Web_Launch_Init(void);
U16 *g_p_winguo_request_input_buffer = NULL;

#if !defined(__COSMOS_MMI_PACKAGE__)
//不需要每次都弹出设为主页的提示
int g_gb_wg_set_home_page_flag = 0;

//热键
#include "SearchWebGProt.h"
#define MMI_SEARCH_WEB_WINGUO_DEFAULT_HOT_KEY        (MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY)
static mmi_search_web_hot_key_enum g_gb_wg_hot_key = MMI_SEARCH_WEB_WINGUO_DEFAULT_HOT_KEY;
#endif

/****************************************************/

GB_INT GB_WG_NetSearchGetWinguoAccessUrl(GB_CHAR *pUrlBuff, GB_UINT nUrlBuffLen, GB_U16 *pSearchString);
extern GB_CHAR* GB_WgGetHwVer(GB_VOID);
extern GB_INT GB_WG_GetCurrentSysLanguageStr(GB_CHAR* pLanguageStr, GB_INT n);
extern GB_INT GB_WG_GetIMEI(GB_CHAR *pIMEI, GB_UINT nBuffLen);
extern GB_INT GB_WG_GetIMSI(GB_CHAR *pIMSI, GB_UINT nBuffLen);
extern GB_CHAR* GB_WG_Plat_ScreenSize(GB_VOID);


// MMI_ID vapp_winguo_search_net_launch_int()
// {
// 	CHAR *pAsciiUrl;
// 	WCH16 *pUcs2Url;
// 
// 	pAsciiUrl = (CHAR*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(CHAR));
// 	pUcs2Url = (WCH16*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(WCH16));
// 
// 	memset(pAsciiUrl, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(CHAR));
// 	memset(pUcs2Url, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(WCH16));
// 
// 	GB_WG_NetSearchGetWinguoAccessUrl(pAsciiUrl, GB_WG_MAX_URL_LEN, NULL);
// 
// 	mmi_asc_to_wcs(pUcs2Url, pAsciiUrl);
// 	wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*)pUcs2Url);
// 
// 	OslMfree(pAsciiUrl);
// 	OslMfree(pUcs2Url);
// 	return 1;
// }
#ifdef __WINGUO_USE_ASM_2_0__
MMI_RET mmi_winguo_search_net_register_proc(mmi_event_struct *evt)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MMI_ID app_id =	GET_APP_ID(evt);
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	switch (evt->evt_id)
	{
	case EVT_ID_APP_ENTER:
		{
			mmi_event_struct event;
			MMI_FRM_INIT_EVENT(&event, 0);
			MMI_FRM_POST_EVENT(&event, GB_WG_Search_Web_Launch_Init, NULL);
			mmi_frm_app_close(APP_GB_WINGUO_NET);
			break;
		}

	case EVT_ID_APP_TOP_ACTIVE:
		{
			break;
		}

	case EVT_ID_APP_TOP_INACTIVE:

		break;

	case EVT_ID_APP_DEINIT:
		break;
	}
	return MMI_RET_OK;

}


MMI_ID GB_WG_Search_Net_Launch(void* args, U32 argSize)
{
	mmi_frm_app_launch(APP_GB_WINGUO_NET, 0, 0, mmi_winguo_search_net_register_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
	return MMI_RET_OK;
}
#else
MMI_ID GB_WG_Search_Net_Launch(void* args, U32 argSize)
{
	GB_WG_Search_Web_Launch_Init();
	return MMI_RET_OK;
}
#endif

S32 GB_WG_Get_CacheSec(CHAR *pCacheSec, U32 nBuffLen)
{
	U32 temp_utc = 0;
	applib_time_struct t;
	if (!pCacheSec || nBuffLen<12)
	{
		return 0;
	}

	applib_dt_get_date_time(&t);
	temp_utc = applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);
	sprintf(pCacheSec, "%ld", temp_utc);
	return 1;
}

#define GB_WINGUO_PLATFORM "4"
#define GB_WINGUO_HW_PSTYLE "winguo"
#define GB_WINGUO_HW_COMPANY "guobi"
#define GB_WINGUO_PROTOCOL_VERSION "4.0"
#define GB_WG_MAX_SOFTVER_LEN 50
#define GB_WG_MAX_LANID_LEN 8
#define	GB_WG_MAX_IMEI_LEN  18
#define	GB_WG_MAX_IMSI_LEN  18
#define	GB_WG_MAX_CACHESEC_LEN  20

GB_INT GB_WG_GetPlatformArgument(GB_CHAR* pUrlBuff, GB_UINT nBuffLen)
{
	GB_CHAR *pSoftver = GB_NULL;
	GB_CHAR pIMEI[GB_WG_MAX_IMEI_LEN+1] = {0};
	GB_CHAR pIMSI[GB_WG_MAX_IMSI_LEN+1] = {0};
	GB_CHAR pLanguageStr[GB_WG_MAX_LANID_LEN+1] = {0};
	GB_CHAR pCacheSec[GB_WG_MAX_CACHESEC_LEN+1] = {0};

	pSoftver = GB_WgGetHwVer();
	GB_WG_GetCurrentSysLanguageStr(pLanguageStr, GB_WG_MAX_LANID_LEN);
	GB_WG_GetIMEI(pIMEI, GB_WG_MAX_IMEI_LEN);
	GB_WG_GetIMSI(pIMSI, GB_WG_MAX_IMSI_LEN);
	GB_WG_Get_CacheSec(pCacheSec, GB_WG_MAX_CACHESEC_LEN);


	sprintf(pUrlBuff, "?pt=%s&pstyle=%s&softver=%s&company=%s&pv=%s&imei=%s&imsi=%s&locale=%s", 
		GB_WINGUO_PLATFORM, GB_WINGUO_HW_PSTYLE, pSoftver, GB_WINGUO_HW_COMPANY, GB_WINGUO_PROTOCOL_VERSION, pIMEI, pIMSI, pLanguageStr);
	sprintf(pUrlBuff+strlen(pUrlBuff), "&lcd=%s&cachetime=%s", GB_WG_Plat_ScreenSize(), pCacheSec);
	return 1;
}


GB_INT GB_WG_NetSearchGetWinguoAccessUrl(GB_CHAR *pUrlBuff, GB_UINT nUrlBuffLen, GB_U16 *pSearchString)
{
	GB_INT nSerchStringLen = 0;
	GB_UINT nUrlLen = 0;

	if(!pUrlBuff || nUrlBuffLen < 200)
	{
		return 0;
	}
	memset(pUrlBuff, 0, nUrlBuffLen*sizeof(*pUrlBuff));

	if (pSearchString && pSearchString[0] > 0)
	{
		strcpy(pUrlBuff, WINGUOSEARCHURL);
	}
	else
	{
		strcpy(pUrlBuff, WINGUOHOMEPAGEURL);
	}
	nUrlLen = strlen(pUrlBuff);
	GB_WG_GetPlatformArgument(pUrlBuff + nUrlLen, nUrlBuffLen-nUrlLen);
	nUrlLen = strlen(pUrlBuff);
	return 1;
}

/****************************************************/
//add net search scf
#if !defined(__COSMOS_MMI_PACKAGE__)
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

MMI_BOOL GB_WG_Net_get_idle_hint_config(const U8 **icon_data, const WCHAR **string)
{
	if (!GB_WG_Net_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT))
	{
		*icon_data = NULL;
		*string = NULL;

		return MMI_FALSE;
	}

	*icon_data = get_image(IMG_WG_WINGUO_LOGO_OUT);
	
	*string = get_string(STR_GB_WINGUO_NET_PRESS_UP);

	return MMI_TRUE;
}

void GB_WG_Native_Search_By_key_Down(void)
{
	GB_WG_Search_Web_Launch_Init();
}
#endif

static GB_INT _GB_WCHAR2UTF8 (GB_CHAR *utf8, GB_WCHAR ucs2)
{
	GB_INT count;
	GB_WCHAR tmpVal = (GB_WCHAR)ucs2;	

	if (tmpVal < 0x80) {
		count = 1;
		utf8[0] = (GB_BYTE) tmpVal;
	}
	else if (tmpVal < 0x0800) {
		count = 2;
		utf8[0] = (GB_BYTE) ( ( (tmpVal >> 6) & 0x1F) | 0xC0);
		utf8[1] = (GB_BYTE) ( (tmpVal & 0x3F) | 0x80);
	}
	else if (tmpVal < 0x010000) {
		count = 3;
		utf8[0] = (GB_BYTE) ( ( (tmpVal >> 12) & 0x0F) | 0xE0);
		utf8[1] = (GB_BYTE) ( ( (tmpVal >> 6) & 0x3F) | 0x80);
		utf8[2] = (GB_BYTE) ( (tmpVal & 0x3F) | 0x80);
	}
	return count;
}

static  _GBGet_HBYTE(GB_CHAR ch){
	GB_CHAR data = ((ch>>4)&0x0F);
	if(data>9){
		return (GB_CHAR)(data-10+'A');
	}else{
		return (GB_CHAR)(data+'0');
	}
}

static GB_CHAR _GBGet_LBYTE(GB_CHAR ch)
{
	GB_CHAR data = (ch&0x0F);
	if(data>9){
		return (GB_CHAR)(data-10+'A');
	}else{
		return (GB_CHAR)(data+'0');
	}
}

static GB_INT GBEscWBuffer(GB_CHAR* pEscBuffer, GB_UINT nBuffLen, GB_WCHAR * pWChar)
//GB_CHAR* GBEscWBuffer(GB_WCHAR * pWChar, GB_INT len)
{
	GB_INT i =0;
	GB_UINT nEscLen = 0;
	for(i = 0; nEscLen < nBuffLen-1 && pWChar[i] > 0; i++)
	{
		if(pWChar[i]>='a'&&pWChar[i]<='z')
		{
			pEscBuffer[nEscLen++] = (GB_BYTE)pWChar[i];
			continue;
		}

		if(pWChar[i]>='A'&&pWChar[i]<='Z')
		{			
			pEscBuffer[nEscLen++] = (GB_BYTE)pWChar[i];
			continue;
		}

		if(pWChar[i]>='0'&&pWChar[i]<='9')
		{			
			//GBByteBuffer_AddByte( &buffer,  (GB_BYTE)pWChar[i]);
			pEscBuffer[nEscLen++] = (GB_BYTE)pWChar[i];
			continue;
		}		

		switch(pWChar[i])
		{
		case '.':
		case '-':
		case '*':
		case '_':
			//GBByteBuffer_AddByte( &buffer, (GB_BYTE)pWChar[i]);
			pEscBuffer[nEscLen++] = (GB_BYTE)pWChar[i];
			break;		
			break;
		case ' ':
			//GBByteBuffer_AddByte( &buffer,'+');
			pEscBuffer[nEscLen++] = '+';
			break;
		default:///
			{
				GB_CHAR utfBuff[4];
				GB_INT j=0;

				GB_INT count=_GB_WCHAR2UTF8((GB_CHAR*)utfBuff,pWChar[i]);					
				for(j=0;j<count;j++)
				{	
					//GB_CHAR sz[4];
					//sz[0]='%';
					//sz[1]=GBGet_HBYTE(utfBuff[j]);
					//sz[2]=GBGet_LBYTE(utfBuff[j]);
					//sz[3]=0; 					
					//GBByteBuffer_AddDataEx( &buffer,sz,3);
					pEscBuffer[nEscLen++] = '%';
					pEscBuffer[nEscLen++] = _GBGet_HBYTE(utfBuff[j]);
					pEscBuffer[nEscLen++] = _GBGet_LBYTE(utfBuff[j]);
				}
			}
			break;
		}
	}
	pEscBuffer[nEscLen] = 0;
	return 0;
}

static GB_WCHAR* GB_WG_SeachString(U16 *pString,GB_BOOL bFlag)
{
#ifdef BROWSER_SUPPORT	
	GB_CHAR *pAsciiUrl;
	GB_WCHAR *pUcs2Url;

	pAsciiUrl = (GB_CHAR*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(GB_CHAR));
	pUcs2Url = (GB_WCHAR*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(GB_WCHAR));

	memset(pAsciiUrl, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(GB_CHAR));
	memset(pUcs2Url, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(GB_WCHAR));

	GB_WG_NetSearchGetWinguoAccessUrl(pAsciiUrl, GB_WG_MAX_URL_LEN, pString);

	if (pString && pString[0] > 0)
	{
		GB_INT nUrlLen = 0;
		nUrlLen = strlen(pAsciiUrl);
		strcpy(pAsciiUrl + nUrlLen, "&kw=");
		nUrlLen = strlen(pAsciiUrl);
		GBEscWBuffer(pAsciiUrl + nUrlLen, nUrlLen, pString);
	}
	else
	{
		if (!bFlag)
		{
			mmi_asc_to_wcs(pUcs2Url, pAsciiUrl);
			OslMfree(pAsciiUrl);
			return pUcs2Url;
		}
	}

	mmi_asc_to_wcs(pUcs2Url, pAsciiUrl);
	wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*)pUcs2Url);

	OslMfree(pAsciiUrl);
	OslMfree(pUcs2Url);
#endif	
	return NULL;
}

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
	if (mmi_frm_group_get_active_id() == GRP_GB_WINGUO_NET_SCREEN)
	{
		mmi_frm_group_close(GRP_GB_WINGUO_NET_SCREEN);
	}	
}

static void GB_WG_Search_Web_RequestEx(U16* pInputBuff)
{
	if (pInputBuff)
	{

		GB_WCHAR *pTemp = GB_WG_SeachString(pInputBuff,GB_TRUE);
		if (pTemp)
		{
			OslMfree(pTemp);
		}
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

static void GB_WG_Search_Web_Set_Key_Handlers()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_get_active_id() == SCR_GB_WINGUO_NET_SCREEN)
    {
         	SetKeyHandler(GB_WG_Search_Web_Request, KEY_ENTER, KEY_EVENT_UP);
    }
}

static void GB_WG_Search_Web_Entry(void)
{
	U8 *gui_buffer = NULL;

	if (!mmi_frm_scrn_enter(
		GRP_GB_WINGUO_NET_SCREEN,
		SCR_GB_WINGUO_NET_SCREEN,
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

	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_GB_WINGUO_NET_SCREEN,SCR_GB_WINGUO_NET_SCREEN);

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
	SetKeyHandler(GB_WG_Search_Web_Close, KEY_BACK, KEY_EVENT_DOWN);
 	GB_WG_Search_Web_Set_Key_Handlers();
 	wgui_cat2001_set_special_key_function(GB_WG_Search_Web_Set_Key_Handlers);
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
#if !defined(__COSMOS_MMI_PACKAGE__)
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(GB_WG_Search_Web_Launch_Init, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(GB_WG_Search_Web_Launch_Init, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}

mmi_id GB_WG_Search_Web_LaunchEx(void)
{
	if (mmi_frm_group_is_present(GRP_GB_WINGUO_NET_SCREEN))
	{
		mmi_popup_display(
			get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
			MMI_EVENT_FAILURE,
			NULL);
		return GRP_ID_INVALID;
	}

	GB_WG_Search_Web_Init();

	mmi_frm_group_create(GRP_ID_ROOT, GRP_GB_WINGUO_NET_SCREEN, GB_WG_GroupScreenProc,NULL);
	mmi_frm_group_enter(GRP_GB_WINGUO_NET_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_scrn_first_enter(
		GRP_GB_WINGUO_NET_SCREEN,
		SCR_GB_WINGUO_NET_SCREEN,
		(FuncPtr)GB_WG_Search_Web_Entry,
		NULL);


	return GRP_GB_WINGUO_NET_SCREEN;
}
#if !defined(__COSMOS_MMI_PACKAGE__)
void GB_WG_Set_Url_As_Homepage_OK(void)
{
#ifdef __MMI_BROWSER_2__
	U16 *pHomePage = (U16*)GB_WG_SeachString(NULL,GB_FALSE);

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
#ifdef __MMI_BROWSER_2__
	U8 msgStr[BRW_CONFIRM_DLG_MSG_LEN];

	mmi_ucs2cpy((S8*) msgStr, (S8*) get_string(STR_GB_WINGUO_HOMEPAGE));
	
 	if(g_brw_app_cntx.brw_scr_group_id != GRP_ID_INVALID)
 	{
		mmi_frm_group_close(g_brw_app_cntx.brw_scr_group_id);
		g_brw_app_cntx.brw_scr_group_id = GRP_ID_INVALID;
 		//mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, GB_WG_Set_Url_As_Homepage_OK, GB_WG_Set_Url_As_Homepage_Cancel, MMI_FALSE);
 	}
 	
 	mmi_brw_app_ui_draw_display_confirm((UI_string_type) msgStr, GB_WG_Set_Url_As_Homepage_OK, GB_WG_Set_Url_As_Homepage_Cancel, MMI_FALSE);
#endif
	return MMI_RET_OK;
}

#endif

mmi_id GB_WG_Search_Web_Launch_Init(void)
{
//cosmos 的浏览器不设置主页
#ifdef __MMI_BROWSER_2__
#if !defined(__COSMOS_MMI_PACKAGE__)
	U8 *pUrl_ascii = NULL;
	U16 *pHomePage = NULL;
	U8 *pHome = NULL;
	U8 *pTemp = NULL;
	unsigned int lens = 0;

	pUrl_ascii = (U8*) OslMalloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	memset(pUrl_ascii, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	//srv_brw_get_user_defined_homepage(pUrl_ascii);
	srv_brw_get_homepage(pUrl_ascii);

	pHomePage = (U16*)GB_WG_SeachString(NULL,GB_FALSE);

	pHome = (U8*) OslMalloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
	memset(pHome, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);

	if (pHomePage)
	{
		mmi_wcs_to_asc(pHome,pHomePage);
	}

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
		return 1;
	}

ENDLAUNCH:
	OslMfree(pUrl_ascii);
	OslMfree(pHome);
	OslMfree(pHomePage);
#endif
#endif
	return GB_WG_Search_Web_LaunchEx();
}
/****************************************************/
#endif /*#ifdef __MMI_GB_WINGUO__*/
