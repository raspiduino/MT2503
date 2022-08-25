
#ifndef __GB_SMDSYSPORT_H__
#define __GB_SMDSYSPORT_H__

#include "GB_DataTypeDef.h"

GB_INT GBMD_GetIconForSmd(GB_U16 CachType, GB_U16 index_type, GB_U16 index, GB_PU8 *img_buff_p);
GB_INT GBMD_GetCallLogNumByIndex(GB_INT SimType, GB_U16 Logtype, GB_U16 id, GB_U16* pstrBuf, GB_INT bufLen);
GB_INT GBMD_GetPhoneNameByIndex(GB_U16 store_index,  GB_U16* pstrBuf, GB_U16 nBuflen);
GB_INT GBMD_GetPhoneNumByIndex(GB_U16 type, GB_U16 store_index, GB_U16*pNumber, GB_U16 nBuffLen);
GB_INT GBMD_GetPhoneRealType(GB_U16 type, GB_U16 store_index);
GB_INT GB_WG_RunApp(GB_U16 usIndex,GB_BOOL isSmartDail);
GB_WCHAR* gbmmi_repot_getApp_Name(GB_U16 menu_id, GB_WCHAR *pstrBuff, GB_U16 nBuffLen);
GB_INT GB_JudgeAppMenuvalid(GB_U16 nMenuId);
GB_U16 GB_WG_Get_PhoneBook_Size(GB_VOID);
GB_U16 GB_WG_Get_PhoneBook_Index(GB_INT index);
GB_VOID GB_WG_Add_PhoneList(GB_VOID);
GB_VOID GB_WG_Get_PhoneBook_Number(GB_U16 store_index,GB_U16*pNumber);
GB_VOID GB_WG_Get_PhoneBook_Name(GB_U16 store_index,GB_U16*pName);
GB_VOID GB_WG_Get_PhoneBook_HomeNumber(GB_U16 store_index,GB_U16 *homeNumber_unicode);
GB_VOID GB_WG_Get_PhoneBook_OfficeNumber(GB_U16 store_index,GB_U16 *officeNumber_unicode);
GB_VOID GB_WG_Get_PhoneBook_FaxNumber(GB_U16 store_index,GB_U16 *faxNumber_unicode);
GB_BOOL GB_WG_PhoneBook_IsHasOptionalField(GB_U16 store_index);
GB_U16 GB_WG_Get_LocalFunList_MenuID_ByIndex(GB_INT index);
GB_INT GB_WG_Get_LocalFunList_Size();
GB_INT GB_WG_GetWinguoFunListID(GB_INT menuID);
// 获取winguo 导航支持的本地功能列表
GB_INT GB_WG_Get_WinguoLocalFunList_Size();
GB_WG_FuncPtr GB_WG_mmi_frm_get_hilite_hdlr(GB_USHORT menuID);
GB_INT GB_WG_Get_WinguoFunList_Size();
const GB_U16* GB_WG_Get_WinguoFunList_Name_ByIndex(GB_INT index);

GB_BOOL GB_WG_Is_Encypt_Mode();


GB_INT GB_WG_SetDefaultApp(GB_U16 menu_id);
GB_INT GB_WG_GetDefaultAppCount(GB_VOID);
GB_INT GB_WG_GetDefaultApp(GB_U16 Index);
GB_INT GB_WG_DefaultAppCmp(GB_U16 Index1, GB_U16 Index2);

GB_VOID GB_WG_SmdInitCallBack(GB_VOID);
GB_VOID GB_WG_SmdReleaseCallBack(GB_VOID);

GB_VOID GB_WG_show_phone_image_by_Hash_key(GB_U16 pData,GB_INT x,GB_INT y,GB_INT iwidth,GB_INT iheight);
GB_VOID gbmmi_app_Init_AppList(GB_VOID);
#endif // #ifndef __GB_SMDSYSPORT_H__

