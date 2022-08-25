
#ifndef __GB_WG_COMMONFUN_H__
#define __GB_WG_COMMONFUN_H__

#include "GB_WG_CommonConfig.h"
#include "GB_WG_CommonString.h"

/* 标准C函数 */
#define GB_MEMCPY                   memcpy
#define GB_MEMCMP                   memcmp
#define GB_MEMSET                   memset
#define GB_MEMMOVE                  memmove

#define GB_STRSTR                   strstr
#define GB_STRLEN                   strlen
#define GB_STRCPY                   strcpy
#define GB_STRNCPY                  strncpy
#define GB_STRCHR                   strchr
#define GB_STRRCHR                  strrchr
#define GB_STRCMP                   strcmp
#define GB_STRCAT                   strcat

#define GB_ATOI                     atoi
#define GB_ITOA                     itoa
#define	GB_ATOL                     atol

#define GB_SPRINTF                  sprintf
#define GB_VSPRINT                  vsprintf

#define GB_WG_Srand                 srand
#define GB_WG_Rand                  rand

// 常用运算
#define GB_MIN(a,b)  ((a)<=(b)?(a):(b))
#define GB_MAX(a,b)  ((a)>=(b)?(a):(b))
#define GB_MED(a,b)  (((a)-(b))/2)
#define GB_ABS(a)     ((a)>=0?(a):-(a))
#define GB_POW2(a)    ((a)*(a))


extern GB_VOID *GB_WG_MallocFun(GB_ULONG size);
extern GB_VOID GB_WG_FreeFun(GB_VOID* p);

#ifndef GB_WINGUO_DEBUG
#define  GB_WG_Malloc(nSize)    GB_WG_MallocFun(nSize)
#define  GB_WG_Free(p)			GB_WG_FreeFun(p)

#else // GB_WINGUO_DEBUG
extern GB_VOID *GB_WG_MallocFun_ext(GB_ULONG size, GB_CHAR *pFileName,GB_INT line);
extern GB_VOID GB_WG_FreeFun_ext(GB_VOID* p);
#define  GB_WG_Malloc(nSize)    GB_WG_MallocFun_ext(nSize, __FILE__, __LINE__)
#define  GB_WG_Free(p)			GB_WG_FreeFun_ext(p)
#endif // GB_WINGUO_DEBUG



#endif // __GB_WG_COMMONFUN_H__
