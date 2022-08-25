
#ifndef __GB_SMD_PLATFORMELEMENTAPP_H__
#define __GB_SMD_PLATFORMELEMENTAPP_H__

#include "GB_WG_DataTypeDef.h"


// 获取App的名字
extern GB_INT GB_SMD_Platform_GetAppName(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen);

// 获取App的注释信息
extern GB_INT GB_SMD_Platform_GetAppNote(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen);

// 获取App的Icon
extern GB_INT GB_SMD_Platform_GetAppIcon(GB_U32 nAppId, GB_PU8 *img_buff_p);

// 检测此app的Id是否有效
extern GB_BOOL GB_SMD_Platform_CheckAppId(GB_U32 nAppId);

// 获取App的个数
extern GB_U32 GB_SMD_Platform_GetLocalAppListSize(GB_VOID);

// 比较两个历史使用过的app的ID
extern GB_INT GB_SMD_Platform_DefaultAppCmp(GB_U32 Index1, GB_U32 Index2);

// 获取历史使用过的app的个数
extern GB_U32 GB_SMD_Platform_GetDefaultAppCount(GB_VOID);

// 获取指定index历史使用过的app ID
extern GB_INT GB_SMD_Platform_GetDefaultApp(GB_U32 Index);

// 初始化App搜索的环境
extern GB_VOID GB_SMD_Platform_AppElementInit(GB_VOID);

// 释放App搜索的环境
extern GB_VOID GB_SMD_Platform_AppElementRelease(GB_VOID);

// 运行指定的App, 如果是smartdail，取的是funapp数组，否则就是与后台对应的数据页面
extern GB_INT GB_SMD_Platform_RunApp(GB_U32 usIndex,GB_BOOL isSmartDail);

#endif // __GB_SMD_PLATFORMELEMENTAPP_H__

