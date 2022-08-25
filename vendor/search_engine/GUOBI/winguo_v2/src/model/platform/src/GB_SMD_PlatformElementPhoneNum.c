
#include "MMI_include.h"
#include "PhbSrv.h"
#include "PhbSrvGprot.h"
#include "Wgui_categories_util.h"
#include "mmi_rp_app_gb_winguo_def.h"

#include "..\inc\GB_SMD_PlatformElementPhoneNum.h"
#include "GB_SMD_Element.h"


extern GB_INT GB_SMD_PhoneNumDleletAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);
extern GB_INT GB_SMD_PhoneNumAddAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);


static GB_U32 _GetPhoneBook_Size(GB_VOID)
{
	return srv_phb_get_used_contact(PHB_STORAGE_MAX);
}

GB_U16 _GetPhoneBookIndex(GB_UINT index)
{
	if (index<_GetPhoneBook_Size())
	{
		return srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, index);
	}
	return 0;
}



// 添加一个联系人至引擎索引
GB_INT GB_SMD_PhoneNumAddAPhoneIndex(GB_U16 store_index)
{
	GB_U16 name_unicode[MMI_PHB_NAME_LENGTH + 1] = {0};
	GB_U16 num_unicode[MMI_PHB_NUMBER_LENGTH + 1] = {0};

	if (!GB_SMD_IsInit())
	{
		return 0;
	}

	GB_SMD_Platform_GetPhoneNumByIndex(GBMD_Numtype_Phone, store_index, num_unicode, sizeof(num_unicode)/sizeof(num_unicode[0]));
	GB_SMD_Platform_GetPhoneBookName(store_index, name_unicode, sizeof(name_unicode)/sizeof(name_unicode[0]));

	if (name_unicode[0])
	{
		GB_SMD_PhoneNumAddAStringCach(GBMD_Numtype_Name, store_index, name_unicode);
	}
	if (num_unicode[0])
	{
		GB_SMD_PhoneNumAddAStringCach(GBMD_Numtype_Phone, store_index, num_unicode);
	}

	// 有更多的电话信息
	if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
	{
		GB_INT i =0;
		mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);
		GB_CHAR* telNum = GB_NULL;

		ASSERT(MMI_PHB_NUMBER_FIELD_COUNT <= GBMD_Numtype_Count-GBMD_Numtype_Phone);
		for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
		{
			GB_CHAR* telNum = optional_fields_data->num[i].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(num_unicode, (GB_CHAR*)telNum, MMI_PHB_NUMBER_LENGTH);
				num_unicode[MMI_PHB_NUMBER_LENGTH] = 0;

				GB_SMD_PhoneNumAddAStringCach(i + GBMD_Numtype_Phone, store_index, num_unicode);
			}
		}
	}
	return 1;
}


// 从引擎索引删除一个联系人数据
GB_INT GB_SMD_PhoneNumDeleteAPhoneIndex(GB_U16 store_index)
{
	GB_U16 name_unicode[MMI_PHB_NAME_LENGTH + 1] = {0};
	GB_U16 num_unicode[MMI_PHB_NUMBER_LENGTH + 1] = {0};

	if (!GB_SMD_IsInit())
	{
		return 0;
	}
	GB_SMD_Platform_GetPhoneNumByIndex(GBMD_Numtype_Phone, store_index, num_unicode, sizeof(num_unicode)/sizeof(num_unicode[0]));
	GB_SMD_Platform_GetPhoneBookName(store_index, name_unicode, sizeof(name_unicode)/sizeof(name_unicode[0]));

	if (name_unicode[0])
	{
		GB_SMD_PhoneNumDleletAStringCach(GBMD_Numtype_Name, store_index, name_unicode);
	}
	if (num_unicode[0])
	{
		GB_SMD_PhoneNumDleletAStringCach(GBMD_Numtype_Phone, store_index, num_unicode);
	}

	// 有更多的电话信息
	if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
	{
		GB_INT i =0;
		mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);
		GB_CHAR* telNum = GB_NULL;

		ASSERT(MMI_PHB_NUMBER_FIELD_COUNT <= GBMD_Numtype_Count-GBMD_Numtype_Phone);
		for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
		{
			GB_CHAR* telNum = optional_fields_data->num[i].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(num_unicode, (GB_CHAR*)telNum, MMI_PHB_NUMBER_LENGTH);
				num_unicode[MMI_PHB_NUMBER_LENGTH] = 0;

				GB_SMD_PhoneNumDleletAStringCach(i + GBMD_Numtype_Phone, store_index, num_unicode);
			}
		}
	}
	return 1;
}

// 系统添加电话号码时的处理函数
mmi_ret GB_SMD_PhoneNumAddNotification(mmi_event_struct* param)
{
	srv_phb_op_evt_struct *evt = (srv_phb_op_evt_struct*)param;

	GB_SMD_PhoneNumAddAPhoneIndex(evt->store_index);

	return MMI_RET_OK;
}

// 系统删除电话号码时的处理函数
mmi_ret GB_SMD_PhoneNumDeleteNotification(mmi_event_struct* param)
{
	srv_phb_op_evt_struct *evt = (srv_phb_op_evt_struct*)param;

	GB_SMD_PhoneNumDeleteAPhoneIndex(evt->store_index);

	return MMI_RET_OK;
}

//系统更新电话号码时的处理函数
mmi_ret GB_SMD_PhoneNumUpdateNotification(mmi_event_struct* param)
{
	srv_phb_op_evt_struct *evt = (srv_phb_op_evt_struct*)param;

	GB_SMD_PhoneNumAddAPhoneIndex(evt->store_index);

	return MMI_RET_OK;
}


// 用时间循环初始化电话本
static GB_UINT GB_WG_CurrInitPhoneCount = 0;
#define PHONEBOOK_INIT_STEP_COUNT 40
static GB_VOID _AddPhoneList(GB_VOID)
{
	GB_UINT i = 0;
	if (!GB_SMD_IsInit())
	{
		return;
	}
	for (i = GB_WG_CurrInitPhoneCount; i < GB_WG_CurrInitPhoneCount + PHONEBOOK_INIT_STEP_COUNT; i++)
	{
		if (i < _GetPhoneBook_Size())
		{
			GB_SMD_PhoneNumAddAPhoneIndex(_GetPhoneBookIndex(i));
		}
		else
		{
			break;
		}
	}
	GB_WG_CurrInitPhoneCount = i;
	if (GB_WG_CurrInitPhoneCount < _GetPhoneBook_Size())
	{
		StartTimer(GB_WG2_SMD_RELEAS_TIME, 0, _AddPhoneList);
	}
}


GB_VOID GB_SMD_Platform_AddPhoneList(GB_VOID)
{
	GB_WG_CurrInitPhoneCount = 0;
	_AddPhoneList();
}

GB_INT GB_SMD_Platform_GetPhoneBookName(GB_U32 store_index, GB_U16*pNameBuff, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pNameBuff)
	{
		*pNameBuff = 0;
		srv_phb_datamgr_get_name(store_index, pNameBuff, nBuffLen);

		//如果联系人名为空就用未命名代替
// 		if(*pNameBuff == '\0')
// 		{
// 			GB_U16 defaultName[4] = {0x672A,0x547D,0x540D,0x0000}; 
// 			gb_wg_wcscpy(pNameBuff, defaultName);
// 		}
		ret = 1;
	}
	return ret;
}

// 获取指定phone ID及type的电话号码
GB_INT GB_SMD_Platform_GetPhoneNumByIndex(GB_U16 type, GB_U32 store_index, GB_U16*pNumber, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pNumber)
	{
		*pNumber = 0;
		if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
		{
			mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);
			if (type == GBMD_Numtype_Name)
			{
				GB_INT i;
				for (i = GBMD_Numtype_Phone; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
				{
					GB_CHAR* telNum = optional_fields_data->num[i - GBMD_Numtype_Phone].number;
					if (telNum[0])
					{
						mmi_asc_n_to_wcs(pNumber, (GB_CHAR*)telNum, nBuffLen-1);
						pNumber[nBuffLen-1] = 0;
						ret = 1;
						break;
					}
				}
			}
			else if(type >= GBMD_Numtype_Phone && type <= MMI_PHB_NUMBER_FIELD_COUNT)
			{
				GB_CHAR* telNum = optional_fields_data->num[type - GBMD_Numtype_Phone].number;
				if (telNum[0])
				{
					mmi_asc_n_to_wcs(pNumber, (GB_CHAR*)telNum, nBuffLen-1);
					pNumber[nBuffLen-1] = 0;
					ret = 1;
				}
			}
		}
		else
		{
			if (GBMD_Numtype_Phone >= type)
			{
				GB_CHAR* telNum = (GB_CHAR*)srv_phb_get_sim_number(store_index, 0, NULL);
				if (telNum)
				{
					mmi_asc_n_to_wcs(pNumber, (GB_CHAR*)telNum, nBuffLen-1);
					pNumber[nBuffLen-1] = 0;
					ret = 1;
				}
			}
		}

// 		if(*pNumber == '\0')
// 		{
// 			GB_U16 defaultNum[4] = {0x65E0,0x53F7,0x7801,0x0000}; 
// 			gb_wg_wcscpy(pNumber, defaultNum);
// 		}
	}
	return ret;
}

// 获取指定phone ID及type的电话号码个数
GB_INT GB_SMD_Platform_GetPhoneNumCountByIndex(GB_U16 nType, GB_U32 store_index)
{
	GB_INT nCount = 0;
	if(nType == GBMD_Numtype_Name)
	{
		if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
		{
			GB_INT i = 0;
			mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);

			while(i < MMI_PHB_NUMBER_FIELD_COUNT)
			{
				GB_CHAR* telNum = optional_fields_data->num[i].number;
				if (telNum[0])
				{
					nCount ++;
				}
				i++;
			}
// 			if(i = 0 && i < MMI_PHB_NUMBER_FIELD_COUNT)
// 			{
// 				GB_CHAR* telNum = optional_fields_data->num[i].number;
// 				if (telNum[0])
// 				{
// 					nCount ++;
// 				}
// 			}
		}
	}
	else
	{
		nCount = 1;
	}
	return nCount;
}

// 获取真实的类型
static GB_U16 _GetPhoneNumRealType(GB_U16 type, GB_U32 store_index)
{
	GB_U16 ret = GBMD_Numtype_Phone;
	if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
	{
		mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);
		if(type>0 && type <= MMI_PHB_NUMBER_FIELD_COUNT)
		{
			GB_INT realtype = optional_fields_data->num[type-1].type;
			switch(realtype)
			{
			case MMI_PHB_NUM_TYPE_MOBILE:
				ret = GBMD_Numtype_Phone;
				break;
			case MMI_PHB_NUM_TYPE_HOME:
				ret = GBMD_Numtype_homeNumber;
				break;
			case MMI_PHB_NUM_TYPE_OFFICE:
				ret = GBMD_Numtype_officeNumber;
				break;
			case MMI_PHB_NUM_TYPE_FAX:
				ret = GBMD_Numtype_faxNumber;
				break;
			}
		}
	}
	return ret;
}


GB_INT GB_SMD_Platform_GetPhoneNumIcon(GB_U16 index_type, GB_U32 index, GB_PU8 *img_buff_p)
{
	// 如果是号码，需要转变成其真实的电话类型
	if(index_type != GBMD_Numtype_Name)
	{
		index_type = _GetPhoneNumRealType(index_type, index);
	}
	if (index_type == GBMD_Numtype_Name || index_type == GBMD_Numtype_Phone)
	{
		if (index >= MMI_PHB_PHONE_ENTRIES)
		{

#if (MMI_MAX_SIM_NUM >= 4)
			if(index >= MMI_PHB_PHONE_ENTRIES + 3*MMI_PHB_SIM_ENTRIES)
			{
				*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CONTACT_SIM4);
			}
			else
#endif
#if (MMI_MAX_SIM_NUM >= 3)
				if(index >= MMI_PHB_PHONE_ENTRIES + 2*MMI_PHB_SIM_ENTRIES)
				{
					*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CONTACT_SIM3);
				}
				else
#endif
#if (MMI_MAX_SIM_NUM >= 2)
					if(index >= MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES)
					{
						*img_buff_p  = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CONTACT_SIM2);
					}
					else
					{
						*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CONTACT_SIM1);
					}
#else // #if (MMI_MAX_SIM_NUM >= 2)
					// 单卡情况下
					*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_CONTACT);
#endif
		}
		else
		{
			*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_MOBILEPHONE);
		}
	}
	else if (index_type == GBMD_Numtype_homeNumber)
	{
		*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_HOME_PHONE);
	}
	// 		else if (index_type == GBMD_Numtype_emailAddress)
	// 		{
	// 		}
	else if (index_type == GBMD_Numtype_officeNumber)
	{
		*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_OFFICE);
	}
	else if (index_type == GBMD_Numtype_faxNumber)
	{
		*img_buff_p = (GB_PU8)get_image(IMG_WG_SMARTDAIL_FAX);
	}
	return 1;
}


