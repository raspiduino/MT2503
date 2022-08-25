#ifndef _mcfstdlib_h_
#define _mcfstdlib_h_
#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#include "McfCommon.h"
#include "stdarg.h"



MUINT	McfStdC_strlen(const MCHAR *pStr);
MINT	McfStdC_strcmp(const MCHAR *pStr0,  const MCHAR *pStr1);
MINT	McfStdC_stricmp(const MCHAR *pStr0,  const MCHAR *pStr1);
MCHAR*	McfStdC_strcat(MCHAR *pStr0,  const MCHAR *pStr1);
MCHAR*	McfStdC_strcpy(MCHAR *pStr0,  const MCHAR *pStr1);
MCHAR*	McfStdC_strncpy(MCHAR *pStr,  const MCHAR *pStr1, MUINT nSize);
MCHAR*	McfStdC_strchr(const MCHAR *pStr,  MINT chr);
MCHAR*	McfStdC_strrchr(const MCHAR* pDest, MINT nChr);
MCHAR*	McfStdC_strstr(const MCHAR *pStr, const MCHAR *pStrSearch);
MINT	McfStdC_atoi(const MCHAR *pStr);
MCHAR*	McfStdC_strlwr(MCHAR *pStr);
MCHAR*	McfStdC_strupr(MCHAR *pStr);


MUINT	McfStdC_wcslen(const MWCHAR* pwstr);
MINT	McfStdC_wcscmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1);
MINT 	McfStdC_wcsicmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1);
MWCHAR*	McfStdC_wcscat(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc);
MWCHAR*	McfStdC_wcscpy(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc);
MWCHAR*	McfStdC_wcschr(const MWCHAR* pwstr,MWCHAR wchar);
MINT	McfStdC_wcsicmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1);
MINT	McfStdC_wcsncmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1,MINT icount);
MWCHAR*	McfStdC_wcsncpy(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc,MINT icount);
MWCHAR*	McfStdC_wcsncat(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc,MINT icount);
MWCHAR*	McfStdC_wcsstr(const MWCHAR* pStr,const MWCHAR* pStrSearch);
MWCHAR*	McfStdC_wcslwr(MWCHAR* pwstrDest);
MWCHAR*	McfStdC_wcsupr(MWCHAR* pwstrDest);



MWCHAR*	McfStdC_strtowstr(MWCHAR* pwstrDest,const MCHAR* pstrSrc);
MCHAR*	McfStdC_wstrtostr(MCHAR* pstrDest,const MWCHAR* pwstrSrc);
MINT	McfStdC_wsprintf(MWCHAR* pwstrDest,const MCHAR* pstrFmt,...);
MINT	McfStdC_sprintf(MCHAR* pstrDest,const MCHAR* pstrFmt,...);
MINT	McfStdC_nsprintf(MCHAR* pstrDest,MINT ilengthDest,const MCHAR* pstrFmt,...);
MINT	McfStdC_vsnprintf(MCHAR* pstrDest,MUINT nSize, const MCHAR* pstrFmt, va_list aList);

MINT	McfStdC_memcmp(const MVOID* buf1, const MVOID* buf2, MUINT  count);
MVOID* 	McfStdC_memcpy(MVOID* dst, const MVOID* src, MUINT  count);
MVOID*	McfStdC_memset(MVOID* buf1, MINT value, MUINT  count);
MVOID*	McfStdC_memchr(const MVOID* buf1, MINT chr, MUINT  count);
MVOID*	McfStdC_memmove(MVOID* buf1, const MVOID* buf2, MUINT  count);

MVOID	McfStdC_srand (MUINT seed); 
MINT	McfStdC_rand(MVOID);



#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif//#ifndef MCRSTDLIB_H

