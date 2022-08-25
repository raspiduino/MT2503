
#ifndef __GB_SMD_ELEMENTCALLLOG_H__
#define __GB_SMD_ELEMENTCALLLOG_H__

#include "GB_WG_Common.h"

// 根据CallLog的ID，获取CallLog字符串
GB_INT GB_SMD_CallLogGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

//根据CallLog的ID，比较CallLog大小（排序时使用）
GB_INT GB_SMD_CallLogCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// 初始化通话记录模块
GB_VOID GB_SMD_CallLogElementInit(GB_VOID);

// 释放通话记录模块
GB_VOID GB_SMD_CallLogElementRelease(GB_VOID);

// 根据输入串，搜索与其匹配的callLog
GB_INT GB_SMD_CallLogSearchString(GB_U16* pSearch);

// 根据CallLog的ID，获取显示资料
GB_INT GB_SMD_CallLogGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// 获取指定CallLog Id的电话号码
GB_INT GB_SMD_CallLogGetPhoneNumByIndex(GB_U32 nId, GB_U16 *pNumBuff, GB_U16 nBuffLen);

#endif // __GB_SMD_ELEMENTCALLLOG_H__


