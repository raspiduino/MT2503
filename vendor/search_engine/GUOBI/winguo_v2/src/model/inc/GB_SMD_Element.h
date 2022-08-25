
#ifndef __GB_SMD_ELEMENT_H__
#define __GB_SMD_ELEMENT_H__

#include "GB_WG_Common.h"



enum __GB_SMD_CachType__
{
	GBMD_CachType_PhoneBook,
	GBMD_CachType_Recalled,
	GBMD_CachType_App,
	GBMD_CachType_WinguoFunction,
	GBMD_CachType_Encrypt,
	GBMD_CachType_CountNum
};

#define GB_SMD_INFOSTING_MAXLEN 40
typedef struct  
{
	GB_WCHAR InfoString[GB_SMD_INFOSTING_MAXLEN+1];
	GB_WCHAR *pHighlightStart;
	GB_U32 nHighlightLen;
	GB_U32 point;
}GB_SMD_ElementStringInfoStr;

typedef struct  
{
	GB_SMD_ElementStringInfoStr subject; // item的主题显示
	GB_SMD_ElementStringInfoStr explain; // item的注释显示
	GB_U8                       *pimg;   // Item的Icon
}GB_SMD_ElementShowInfoStr;

// smd mode的初始化函数
extern GB_INT GB_SMD_Init();

// smd mode的释放函数
extern GB_VOID GB_SMD_Release(GB_VOID);

// smd mode是否已初始化
extern GB_BOOL GB_SMD_IsInit(GB_VOID);

// 设定搜索为初始状态
extern GB_INT GB_SMD_ResetSearch(GB_VOID);

// 搜索指定的字符串
extern GB_INT GB_SMD_SearchString(GB_U16 *str);

// 获取指定index的CachType及其id
extern GB_INT GB_SMD_GetCachDataByIndex(GB_U32 Index, GB_U16 *CachType, GB_U32 *nId);

// 获取指定index的显示信息
extern GB_INT GB_SMD_GetCachShowDataByIndex(GB_U32 Index, GB_SMD_ElementShowInfoStr *pShowInfo);

enum __GB_SMD_SearchFlag__
{
	e_SearchFlag_ALL,
	e_SearchFlag_NoPhoneBook,
	e_SearchFlag_NoNum,
	e_SearchFlag_NoApp,
	e_SearchFlag_OnlyApp
};
extern GB_VOID GB_SMD_SetSearchFlag(GB_U32 flag);

#endif // __GB_SMD_ELEMENT_H__
