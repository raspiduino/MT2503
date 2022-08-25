
#ifndef __GB_SMD_PLATFORMELEMENTPHONENUM_H__
#define __GB_SMD_PLATFORMELEMENTPHONENUM_H__

#include "GB_WG_DataTypeDef.h"

enum __GBMD_PhoneBook_IndexType__
{
	GBMD_Numtype_Name,
	GBMD_Numtype_Phone,
	GBMD_Numtype_homeNumber,
	GBMD_Numtype_officeNumber,
	GBMD_Numtype_faxNumber,
	GBMD_Numtype_emailAddress, 
	GBMD_Numtype_Count
};

// 获取电话号码图标
extern GB_INT GB_SMD_Platform_GetPhoneNumIcon(GB_U16 index_type, GB_U32 index, GB_PU8 *img_buff_p);

// 获取指定phone ID及type的电话号码
extern GB_INT GB_SMD_Platform_GetPhoneNumByIndex(GB_U16 type, GB_U32 store_index, GB_U16*pNumber, GB_U16 nBuffLen);

// 获取指定phone ID及type的电话号码个数
extern GB_INT GB_SMD_Platform_GetPhoneNumCountByIndex(GB_U16 nType, GB_U32 store_index);

// 获取指定phone ID的联系人名字
extern GB_INT GB_SMD_Platform_GetPhoneBookName(GB_U32 store_index, GB_U16*pNameBuff, GB_U16 nBuffLen);

// 平台层添加电话本至搜索引擎
extern GB_VOID GB_SMD_Platform_AddPhoneList(GB_VOID);

#endif // __GB_SMD_PLATFORMELEMENTPHONENUM_H__

