
#ifndef __GB_SMD_ELEMENTAPP_H__
#define __GB_SMD_ELEMENTAPP_H__

#include "GB_WG_Common.h"

// 根据App的ID，获取App字符串
GB_INT GB_SMD_AppGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// 根据App的ID，比较ID大小（排序时使用）
GB_INT GB_SMD_AppCachIdCompare(GB_UINT nId1, GB_UINT nId2);


// 将App加入搜索数据
GB_VOID GB_SMD_AppAddSearchData(GB_VOID);


// 根据App的ID，获取显示资料
GB_INT GB_SMD_AppGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);


// 将最近使用的APP加入到搜索结果当中去
GB_INT GB_SMD_AppAddDefaultItem(GB_VOID);

// 初始化App搜索的环境
GB_VOID GB_SMD_AppElementInit(GB_VOID);

// 释放App搜索的环境
GB_VOID GB_SMD_AppElementRelease(GB_VOID);

// 运行知道ID的App
GB_VOID GB_SMD_RunApp(GB_U32 nId);

#endif // __GB_SMD_ELEMENTAPP_H__


