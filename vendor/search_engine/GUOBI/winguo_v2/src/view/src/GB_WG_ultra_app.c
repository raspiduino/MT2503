
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "Browser_api.h"
#include "Unicodexdcl.h"
#include "ImeiSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "Wgui_include.h"

#define GB_WG_MAX_URL_LEN 450

extern S32 GB_WG_U_GetWinguoAccessUrl(CHAR *pUrlBuff, U32 nUrlBuffLen, WCH16 *pSearchString);
/****************************************************************************

  FUNCTION:
   GB_WG_SeachString
   
  DESCRIPTION:
   搜索指定的字符串

  PARAMS:
   pString:需搜索的字符串

  RETURNS:
   S32,0 or 1

*****************************************************************************/
S32 GB_WG_SeachString(WCH16 *pString)
{
	CHAR *pAsciiUrl;
	WCH16 *pUcs2Url;

	pAsciiUrl = (CHAR*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(CHAR));
	pUcs2Url = (WCH16*)OslMalloc((GB_WG_MAX_URL_LEN+1)*sizeof(WCH16));

	memset(pAsciiUrl, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(CHAR));
	memset(pUcs2Url, 0, (GB_WG_MAX_URL_LEN+1)*sizeof(WCH16));

	GB_WG_U_GetWinguoAccessUrl(pAsciiUrl, GB_WG_MAX_URL_LEN, pString);

	mmi_asc_to_wcs(pUcs2Url, pAsciiUrl);
	#ifdef BROWSER_SUPPORT
	// 用浏览器打开指定的url，在browser不同的工程中，需要替换此调用
	wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*)pUcs2Url);
	#endif
	OslMfree(pUcs2Url);
	OslMfree(pAsciiUrl);
	return 1;
}


extern char *release_hw_ver(void);
/****************************************************************************

  FUNCTION:
   GB_WG_GetSoftver
   
  DESCRIPTION:
   获取工程的软件版本号

  PARAMS:
   pSoftver:传入的获取版本号的buffer
   BuffLen：传入buffer的长度

  RETURNS:
   S32,0 or 1

*****************************************************************************/
S32 GB_WG_GetSoftver(CHAR* pSoftver, U32 BuffLen)
{
	CHAR *phw_ver = (CHAR*)release_hw_ver();
	if (phw_ver)
	{
		strncpy(pSoftver, phw_ver, BuffLen);
		return 1;
	}
	return 0;
}

extern char *release_hw_ver(void);
char* GB_WgGetHwVer(void)
{
	return release_hw_ver();
}

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
/****************************************************************************

  FUNCTION:
   GB_WG_Get_CurrentSysLanguageStr
   
  DESCRIPTION:
   获取平台当前的语言

  PARAMS:
   pLanguageStr:传入用来存储获取语言的buffer
   n：          buffer的长度

  RETURNS:
   S32,0 or 1

*****************************************************************************/
S32 GB_WG_Get_CurrentSysLanguageStr(CHAR* pLanguageStr, S32 n)
{
	S32 len = 0;
	if (!pLanguageStr || n <= 0)
	{
		return 0;
	}
	while (len < n)
	{
		// '-'换成'_'
		if (gLanguageArray[gCurrLangIndex].aLangCountryCode[len] == '-')
		{
			pLanguageStr[len] = '_';
		}
		else
		{
			pLanguageStr[len] = gLanguageArray[gCurrLangIndex].aLangCountryCode[len];
		}
		len++;
	}
	return len;
}


/****************************************************************************

  FUNCTION:
   GB_WG_Get_IMEI
   
  DESCRIPTION:
   获取手机的IMEI号

  PARAMS:
   pIMEI:    传入用来存储获取IMEI的buffer
   nBuffLen：buffer的长度

  RETURNS:
   S32,0 or 1

*****************************************************************************/
S32 GB_WG_Get_IMEI(CHAR *pIMEI, U32 nBuffLen)
{
	srv_imei_get_imei(MMI_SIM1, pIMEI, nBuffLen);
	return 1;
}

/****************************************************************************

  FUNCTION:
   GB_WG_Get_IMSI
   
  DESCRIPTION:
   获取手机的IMSI号

  PARAMS:
   pIMSI:    传入用来存储获取IMSI的buffer
   nBuffLen：buffer的长度

  RETURNS:
   S32,0 or 1

*****************************************************************************/
S32 GB_WG_Get_IMSI(CHAR *pIMSI, U32 nBuffLen)
{
	S32 ret = MMI_FALSE;
	ret = srv_sim_ctrl_get_imsi(MMI_SIM1, pIMSI, nBuffLen);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	return ret;
}

/****************************************************************************

  FUNCTION:
   GB_WG_Get_CacheSec
   
  DESCRIPTION:
   获取手机的当前时间

  PARAMS:
   pCacheSec: 传入用来存储获取当前时间的buffer
   nBuffLen： buffer的长度

  RETURNS:
   S32,0 or 1

*****************************************************************************/
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

/****************************************************************************

  FUNCTION:
   GB_WG_Get_ScreenSize
   
  DESCRIPTION:
   获取手机屏幕像素大小

  PARAMS:
   void

  RETURNS:
   CHAR* ，手机屏幕高宽的字符串值

*****************************************************************************/
CHAR* GB_WG_Get_ScreenSize(void)
{
#ifdef __MMI_MAINLCD_480X800__
	return "480X800";
#elif __MMI_MAINLCD_320X480__
	return "320X480";
#elif __MMI_MAINLCD_240X400__
	return "240X400";
#elif __MMI_MAINLCD_320X240__
	return "320X240";
#elif __MMI_MAINLCD_240X320__
	return "240X320";
#elif __MMI_MAINLCD_176X220__
	return "176X220";
#elif __MMI_MAINLCD_128X160__
	return "128X160";
#else
	return "128X128";
#endif
}

