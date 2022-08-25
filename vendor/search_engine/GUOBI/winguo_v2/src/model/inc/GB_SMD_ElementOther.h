
#ifndef __GB_SMD_ELEMENTOTHER_H__
#define __GB_SMD_ELEMENTOTHER_H__

#include "GB_WG_Common.h"

/**************** 问果自身应用搜索  *******************/

// 根据WinguoFun的ID，获取WinguoFun字符串
GB_INT GB_SMD_WinguoFunGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

//根据WinguoFun的ID，比较WinguoFun大小（排序时使用）
GB_INT GB_SMD_WinguoFunCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// 将WinguoFun加入搜索数据
GB_VOID GB_SMD_WinguoFunAddSearchData(GB_VOID);

// 根据WinguoFun的ID，获取显示资料
GB_INT GB_SMD_WinguoFunGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// 运行WinguoFun
GB_VOID GB_SMD_WinguoFunRun(GB_U16 id);





/**************** 电话簿解密提示  *******************/

// 获得密码输入框的提示
GB_INT GB_SMD_EncyptGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// 密码输入框的比较
GB_INT GB_SMD_EncyptCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// 将输入密码提示加入候选
GB_INT GB_SMD_EncyptSearchString(GB_U16* pSearch);

// 根据WinguoFun的ID，获取显示资料
GB_INT GB_SMD_EncyptGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// 运行密码提示
GB_VOID GB_SMD_EncyptFunRun(GB_VOID);


#endif // __GB_SMD_ELEMENTOTHER_H__


