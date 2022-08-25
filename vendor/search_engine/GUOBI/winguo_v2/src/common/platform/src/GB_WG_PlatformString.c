
/*********  平台头文件 ********/
#include "Unicodexdcl.h"


/*********  内部头文件 ********/
#include "GB_WG_DataTypeDef.h"

/*****************************/
/*****************************/

GB_WCHAR* GB_WG_platform_wcsncpy(GB_WCHAR *str_dst, const GB_WCHAR* str_src, GB_INT count)
{ 
	return mmi_wcsncpy(str_dst, str_src, count);
}

GB_WCHAR* GB_WG_platform_wcscpy(GB_WCHAR *str_dst, const GB_WCHAR *str_src)
{
	return mmi_wcscpy(str_dst, str_src);
}

GB_WCHAR* GB_WG_platform_wcsncat(GB_WCHAR *str_dst, const GB_WCHAR *str_src, GB_INT count)
{
	return mmi_wcsncat(str_dst, str_src, count);
}

GB_WCHAR* GB_WG_platform_wcscat(GB_WCHAR *str_dst, const GB_WCHAR *str_src)
{
	return mmi_wcscat(str_dst, str_src);
}

GB_WCHAR* GB_WG_platform_wcsstr(GB_WCHAR *string, const GB_WCHAR *str_char_set)
{
	return mmi_wcsstr(string, str_char_set);
}

GB_INT GB_WG_platform_wcslen(const GB_WCHAR *string)
{
	return mmi_wcslen(string);
}

GB_INT GB_WG_platform_wcscmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst)
{
	return mmi_wcscmp(str_src, str_dst);
}

GB_INT GB_WG_platform_wcsicmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst)
{
	return mmi_wcsicmp(str_src, str_dst);
}

GB_UINT GB_WG_platform_asc_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer)
{
	return mmi_asc_to_wcs(pOutBuffer, pInBuffer);
}

GB_UINT GB_WG_platform_wcs_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer)
{
	return mmi_wcs_to_asc(pOutBuffer, pInBuffer);
}
