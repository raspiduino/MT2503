/*! @file
********************************************************************************
<PRE>
模块名       : 
文件名       : DataTypeDefine.h
相关文件     : 
文件实现功能 : 基本数据类型定义、基础函数定义、代码配置信息定义，用于跨平台。
作者         : Kingnight
版本         : 1.0
--------------------------------------------------------------------------------
备注         : 
--------------------------------------------------------------------------------
修改记录 : 
日 期        版本     修改人			修改内容
2008/08/01   1.1      anlanyu			添加注释，整理排版
</PRE>
*******************************************************************************/
#ifndef GB_CONFIG_DEF_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H
#define GB_CONFIG_DEF_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H

#include "GB_DataTypeDef.h"

#ifdef GBMD_DYNAMIC_MEM
#define  	GBUSE_ASM_MEM		//使用多媒体的内存
#define __WINGUO_USE_ASM_2_0__  //Use ASM2.0 after 1224MP, ASM1.0 in 1132SP
#else
#define   GBUSE_STATIC_MEM  //使用静态内存
#endif


#ifdef WIN32
#define GB_WINGUO_ADM_TESTMEM 

#ifdef GB_WINGUO_ADM_TESTMEM
#define __GB_WINGUO_SELFMEM_TEST__
#endif
#endif


#ifdef GB_WINGUO_ADM_TESTMEM
// extern void* GB_WG_MALLOCEx(GB_ULONG size,GB_CHAR *pFileName,int line);
// extern void  GB_WG_FREEEx(void* p);
// #define  GB_WG_Malloc(nSize)    GB_WG_MALLOCEx(nSize,__FILE__,__LINE__)
// #define  GB_WG_Free(p)			GB_WG_FREEEx(p)
extern GB_VOID* GB_WG_MallocFunEx(GB_ULONG size,GB_CHAR *pFileName,GB_INT line);
extern GB_VOID  GB_WG_FreeFunEx(void* p);
#define  GB_WG_Malloc(nSize)    GB_WG_MallocFunEx(nSize,__FILE__,__LINE__)
#define  GB_WG_Free(p)			GB_WG_FreeFunEx(p)

#else

// extern void *GB_WG_MALLOC(unsigned long size);
// extern void GB_WG_FREE(void* p);
// #define  GB_WG_Malloc(nSize)    GB_WG_MALLOC(nSize)
// #define  GB_WG_Free(p)			GB_WG_FREE(p)
extern GB_VOID *GB_WG_MallocFun(GB_ULONG size);
extern GB_VOID GB_WG_FreeFun(GB_VOID* p);
#define  GB_WG_Malloc(nSize)    GB_WG_MallocFun(nSize)
#define  GB_WG_Free(p)			GB_WG_FreeFun(p)

#endif

extern void *GB_WG_MEMORY_MALLOC(unsigned long size);
extern void GB_WG_MEMORY_FREE(void* p);


// 内存自我管理
//#define __GB_WINGUO_SELFMEM__
#ifdef __GB_WINGUO_SELFMEM__
#define __GB_WINGUO_SELFMEMSIZE__	(256*1024)
#endif

#if defined __GB_WINGUO_SELFMEM_TEST__// || defined GB_WINGUO_ADM_TESTMEM
extern GB_VOID *GB_WG_MemManagerMallocEx(GB_ULONG size,GB_CHAR *pFileName,GB_INT line);
extern GB_VOID GB_WG_MemManagerFreeEx(GB_VOID* p);
typedef GB_VOID* (*FUNGB_WG_MALLOC)(GB_ULONG size,GB_CHAR *pFileName,GB_INT line);
typedef GB_VOID (*FUNGB_WG_FREE)(GB_VOID* p);
#else
extern GB_VOID *GB_WG_MemManagerMalloc(GB_UINT size);
extern GB_VOID GB_WG_MemManagerFree(GB_VOID* p);
typedef GB_VOID* (*FUNGB_WG_MALLOC)(GB_UINT size);
typedef GB_VOID (*FUNGB_WG_FREE)(GB_VOID* p);
#endif // __GB_WINGUO_SELFMEM_TEST__

#ifdef __GB_WINGUO_SELFMEM__
#if defined __GB_WINGUO_SELFMEM_TEST__// || defined GB_WINGUO_ADM_TESTMEM
#define  GB_WG_SelfMalloc(nSize)    GB_WG_MemManagerMallocEx(nSize,__FILE__,__LINE__)
#define  GB_WG_SelfFree(p)			GB_WG_MemManagerFreeEx(p)
#define  GB_WG_SelfMallocFun    GB_WG_MemManagerMallocEx
#define  GB_WG_SelfFreeFun		GB_WG_MemManagerFreeEx
#else
#define  GB_WG_SelfMalloc(nSize)    GB_WG_MemManagerMalloc(nSize)
#define  GB_WG_SelfFree(p)			GB_WG_MemManagerFree(p)
#define  GB_WG_SelfMallocFun    GB_WG_MemManagerMalloc
#define  GB_WG_SelfFreeFun		GB_WG_MemManagerFree
#endif // __GB_WINGUO_SELFMEM_TEST__


#else
#define  GB_WG_SelfMalloc(nSize)    GB_WG_Malloc(nSize)
#define  GB_WG_SelfFree(p)			GB_WG_Free(p)
#ifdef GB_WINGUO_ADM_TESTMEM
#define  GB_WG_SelfMallocFun    GB_WG_MallocFunEx
#define  GB_WG_SelfFreeFun		GB_WG_FreeFunEx
#else // GB_WINGUO_ADM_TESTMEM
#define  GB_WG_SelfMallocFun    GB_WG_MallocFun
#define  GB_WG_SelfFreeFun		GB_WG_FreeFun
#endif // GB_WINGUO_ADM_TESTMEM


#endif // __GB_WINGUO_SELFMEM__

#define	GBPOWER2(a)	((a)*(a))

#define GB_GETDISTANCE(x0,y0,x1,y1)			(GBPOWER2((x0) - (x1))) + (GBPOWER2((y0) - (y1)))



extern GB_WCHAR* gb_wg_wcsncpy(GB_WCHAR *str_dst, const GB_WCHAR* str_src, GB_INT count);
extern GB_WCHAR* gb_wg_wcscpy(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* gb_wg_wcsncat(GB_WCHAR *str_dst, const GB_WCHAR *str_src, GB_INT count);
extern GB_WCHAR* gb_wg_wcscat(GB_WCHAR *str_dst, const GB_WCHAR *str_src);
extern GB_WCHAR* gb_wg_wcsstr(GB_WCHAR *string, const GB_WCHAR *str_char_set);
extern GB_INT gb_wg_wcslen(const GB_WCHAR *string);
extern GB_INT gb_wg_wcscmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);
extern GB_INT gb_wg_wcsicmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst);

extern GB_UINT gb_wg_asc_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer);
//extern GB_UINT gb_wg_asc_n_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer, GB_INT len);
extern GB_UINT gb_wg_wcs_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer);
//extern GB_UINT gb_wg_wcs_n_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer, GB_INT len);

#if defined(WIN32) || defined(GB_WINGUO_DEBUG)
#if !defined(ASSERT)
extern GB_VOID GB_WINGUO_ASSERT(GB_CHAR* expr, GB_CHAR* file, GB_UINT line, GB_INT n);
#define  ASSERT(n)  GB_WINGUO_ASSERT((GB_CHAR*)#n, (GB_CHAR *)__FILE__, __LINE__, (GB_INT)(n))
#endif
#else
#if !defined(ASSERT)
#define ASSERT(n)	((void)0)
#endif
#endif

// 这里边暂时放配置信息吧
//#define GB_WINGUO_DOUBLEDIALER		// 双行拨号框

//#define GB_WINGUO_NEEDBST			// 获取基站信息
#define __GB_WINGUO_NEEDGPRMC__		// 需要定位信息
//#define GB_WINGUO_USESYSSMS		// 系统的短信


#define GB_WINGUO_USESYSSMS			// 用系统短息

//#define __GB_WINGUO_OPEN_SKIN__
// test for multi language [5/28/2012 liangchuanhui]
#define  __GB_WINGUO_MULTI_LANGUAGE__

#endif