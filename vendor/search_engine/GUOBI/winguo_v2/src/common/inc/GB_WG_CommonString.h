
#ifndef __GB_WG_COMMONSTRING_H__
#define __GB_WG_COMMONSTRING_H__

#include "GB_WG_CommonConfig.h"
#include "GB_WG_DataTypeDef.h"

extern GB_WCHAR* gb_wg_wcsncpy(GB_WCHAR *str_dst, const GB_WCHAR* str_src, GB_INT count);
extern GB_WCHAR* gb_wg_wcscpy(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* gb_wg_wcsncat(GB_WCHAR *str_dst, const GB_WCHAR *str_src, GB_INT count);
extern GB_WCHAR* gb_wg_wcscat(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* gb_wg_wcsstr(GB_WCHAR *string, const GB_WCHAR *str_char_set);
extern GB_INT gb_wg_wcslen(const GB_WCHAR *string);
extern GB_INT gb_wg_wcscmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);
extern GB_INT gb_wg_wcsicmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);
extern GB_UINT gb_wg_asc_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer);
extern GB_UINT gb_wg_wcs_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer);

extern GB_BOOL GB_WG_String_IsAscii(const GB_U16 *str);
extern GB_BOOL GB_WG_String_IsNumSymbol(const GB_U16 *str);
extern GB_BOOL GB_WG_String_IsNum(const GB_U16 *str);

#endif // __GB_WG_COMMONSTRING_H__
