
#include "MMI_include.h"
#include "Wgui_categories_util.h"
#include "mmi_rp_app_gb_winguo_def.h"

#include "GB_WG_Common.h"


GB_VOID GB_SMD_Platform_GetWinguoFunctionIcon(GB_U32 index, GB_PU8 *img_buff_p)
{
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
}

GB_VOID GB_SMD_Platform_GetEncryptIcon(GB_U32 index, GB_PU8 *img_buff_p)
{
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
}

GB_BOOL GB_SMD_IsEncyptMode(GB_VOID)
{
	return GB_FALSE/*!PhnsetReadPRIVACYSetting_Index(SETTING_PRIVACY_PHONEBOOK)*/;
}


// 获取WinguoFun的注释信息
GB_INT GB_SMD_Platform_GetWinguoFunNote(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pstrBuff && nBuffLen)
	{
		const GB_WCHAR* pString = (const GB_WCHAR*)get_string(STR_GB_WINGUO_APP);
		if (pString)
		{
			pstrBuff[nBuffLen-1] = 0;
			gb_wg_wcsncpy(pstrBuff, pString, nBuffLen-1);
			ret = 1;
		}
	}
	return ret;
}

GB_INT GB_SMD_Platform_GetWinguoFunIcon(GB_U32 nAppId, GB_PU8 *img_buff_p)
{
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
	return 1;
}


GB_INT GB_SMD_Platform_GetEncyptFunIcon(GB_U32 nAppId, GB_PU8 *img_buff_p)
{
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
	return 1;
}
