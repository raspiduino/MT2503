
#ifndef __GB_SMD_PLATFORMELEMENTCALLLOG_H__
#define __GB_SMD_PLATFORMELEMENTCALLLOG_H__

#include "GB_WG_DataTypeDef.h"


// 根据输入串，搜索与其匹配的callLog
extern GB_INT GB_SMD_Platform_SearchCallLogByString(GB_U16 * key_input);

// 获取CallLog的Icon
extern GB_INT GB_SMD_Platform_GetCallLogIcon(GB_U32 index, GB_PU8 *img_buff_p);

// 根据ID获取CallLog的号码
extern GB_INT GB_SMD_Platform_GetCallLogNumByIndex(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen);

// 获取CallLog的注释信息
extern GB_INT GB_SMD_Platform_GetCallLogNote(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen);


#endif // __GB_SMD_PLATFORMELEMENTCALLLOG_H__

