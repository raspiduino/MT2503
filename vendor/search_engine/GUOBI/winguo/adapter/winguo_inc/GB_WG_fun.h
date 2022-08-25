
#ifndef __GB_WG_FUN_H__
#define __GB_WG_FUN_H__

#include "GB_DataTypeDef.h"

enum __GBMD_CachType__
{
	GBMD_CachType_PhoneBook,
	GBMD_CachType_Recalled,
	GBMD_CachType_Recalled2,
	GBMD_CachType_App,
	GBMD_CachType_WinguoFunction,
	GBMD_CachType_Encrypt,
	GBMD_CachType_CountNum
};
enum __GBMD_PhoneBook_IndexType__
{
	GBMD_Numtype_Name,
	GBMD_Numtype_Phone,
	GBMD_Numtype_homeNumber,
	GBMD_Numtype_officeNumber,
	GBMD_Numtype_faxNumber,
	GBMD_Numtype_emailAddress
};
enum __GBMD_Recalled_IndexType__
{
	GBMD_Numtype_DialedNum,
	GBMD_Numtype_MissedNum,
	GBMD_Numtype_ReceivedNum
};

extern GB_USHORT* WinguoWin_GB_WG_GetAboutContent(GB_VOID);
extern GB_VOID GB_WG_AddKeyToTarget(GB_U16 CachType, GB_U16 index_type, GB_U16 Index);
extern GB_VOID GB_WG_InputMode_HandwritEnd(GB_VOID);
GB_INT gbmmi_repot_AddAPhoneIndex(GB_U16 store_index);
GB_VOID gbmmi_repot_delete_Index(GB_U16 store_index);

extern GB_VOID GB_WG_Trace(const GB_CHAR * format,...);

#endif // #ifndef __GB_WG_FUN_H__
