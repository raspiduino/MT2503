
#ifndef __GB_SMD_ELEMENTPHONENUM_H__
#define __GB_SMD_ELEMENTPHONENUM_H__

#include "GB_WG_Common.h"
#include "GB_SMD_Element.h"

// 设置是否搜索电话号码（只搜索联系人名字）
GB_VOID GB_SMD_PhoneNumSetSearchNoNum(GB_BOOL Flag);

// 根据PhoneNum的ID，获取PhoneNum字符串
GB_INT GB_SMD_PhoneNumGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// 比较电话号码ID的大小（排序时使用）
GB_INT GB_SMD_PhoneNumCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// 获取指定电话PhoneNum ID的显示信息
GB_INT GB_SMD_PhoneNumGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// 获取指定Id的电话号码
GB_INT GB_SMD_PhoneNumGetNumById(GB_U32 nId, GB_U16 *pNumBuff, GB_U16 nBuffLen);

// 获取指定Id的电话号码个数
GB_INT GB_SMD_PhoneNumGetCountById(GB_U32 nId);

// 从引擎索引数据中删除指定Phone Id 
GB_INT GB_SMD_PhoneNumDleletAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);

// 添加指定的Phone Id 至引擎索引数据
GB_INT GB_SMD_PhoneNumAddAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);


// 添加电话簿至引擎数据
GB_VOID GB_SMD_PhoneNumAddSearchData(GB_VOID);

// 获取电话号码的真实ID，传入的参数应该是nId，GB_SMD_GetCachDataByIndex调用后使用
GB_U32 GB_SMD_PhoneNumGetRealId(GB_U32 nId);



#endif // __GB_SMD_ELEMENTPHONENUM_H__


