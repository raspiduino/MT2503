
#ifndef __GB_WG_PLATFORMSTRING_H__
#define __GB_WG_PLATFORMSTRING_H__

#include "GB_WG_DataTypeDef.h"

extern GB_WCHAR* GB_WG_platform_wcsncpy(GB_WCHAR *str_dst, const GB_WCHAR* str_src, GB_INT count);
extern GB_WCHAR* GB_WG_platform_wcscpy(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* GB_WG_platform_wcsncat(GB_WCHAR *str_dst, const GB_WCHAR *str_src, GB_INT count);
extern GB_WCHAR* GB_WG_platform_wcscat(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* GB_WG_platform_wcsstr(GB_WCHAR *string, const GB_WCHAR *str_char_set);
extern GB_INT GB_WG_platform_wcslen(const GB_WCHAR *string);
extern GB_INT GB_WG_platform_wcscmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);
extern GB_INT GB_WG_platform_wcsicmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);
extern GB_UINT GB_WG_platform_asc_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer);
extern GB_UINT GB_WG_platform_wcs_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer);

#endif // __GB_WG_PLATFORMSTRING_H__
