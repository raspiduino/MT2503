
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE

#include "MMI_include.h"
#include "GlobalDefs.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "GB_WG_Public.h"
#include "GB_WG_SystemInc.h"
#include "GB_WG_MTKPlatver.h"
/*#include "GBMD_Struct.h"*/

#if defined(GB_MTK_10APLAT)
#include "GlobalMenuItems.h"
#include "mmi_rp_app_funandgames_def.h"
#endif //#if defined(GB_MTK_10APLAT)

#include "CallLogSrvGprot.h"
#include "CallLogProt.h"
#include "mmi_rp_app_gb_winguo_def.h"



GB_INT GB_JudgeAppMenuvalid(GB_U16 nMenuId);



/************************************************************************/
/*                      电话簿                                        */
/************************************************************************/
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
#define PHB_OPTIONAL_FIELDS_STRUCT mmi_phb_optional_fields_struct
#define lookUpNumber(p) srv_phb_check_number_exist((U16*)p)
#define PHB_OPTIONAL_FIELDS_STRUCT mmi_phb_optional_fields_struct
//extern U16 srv_phb_datamgr_used_contacts_count(U8 storage);
extern U16 srv_phb_get_used_contact(U8 storage);

#ifdef __MMI_TELEPHONY_SUPPORT__
extern S32 srv_phb_sse_sort_index_to_store_index(U8 storage, U16 sort_index);

extern void srv_phb_datamgr_get_name(U16 index, U16* name, S32 out_len);
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

extern S8* srv_phb_datamgr_get_number(U16 index);

#if defined(GB_MTK_09BPLAT)
#define homeNumber home_number
#define officeNumber office_number
#define faxNumber fax_number
#define emailAddress email_address
#elif defined(GB_MTK_10APLAT)
#define homeNumber opt_num[0].number
#define officeNumber opt_num[1].number
#define faxNumber opt_num[2].number
#define emailAddress email_address
#endif

#else
extern GB_U16 g_phb_name_index[];
extern GB_U16 PhoneBookEntryCount;
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#endif
static PHB_OPTIONAL_FIELDS_STRUCT gbmmi_repot_PhoneBookOptionalFields;




GB_U16 GB_WG_Get_PhoneBook_Size(GB_VOID)
{
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
//	return srv_phb_datamgr_used_contacts_count(PHB_STORAGE_MAX);
	return srv_phb_get_used_contact(PHB_STORAGE_MAX);
#else
	return PhoneBookEntryCount;
#endif
}

GB_U16 GB_WG_Get_PhoneBook_Index(GB_INT index)
{
	if (index<GB_WG_Get_PhoneBook_Size())
	{
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
#ifdef __MMI_TELEPHONY_SUPPORT__
        return srv_phb_sse_sort_index_to_store_index(PHB_STORAGE_MAX, index);
#endif/*__MMI_TELEPHONY_SUPPORT__ */
#else
		return g_phb_name_index[index];
#endif
	}
	return 0;
}

// 用时间循环初始化电话本
static GB_UINT GB_WG_CurrInitPhoneCount = 0;
#define PHONEBOOK_INIT_STEP_COUNT 40
GB_VOID GB_WG_Add_PhoneList_ext(GB_VOID)
{
	GB_INT i = 0;
	if (!gbmmi_GBD_is_Init())
	{
		return;
	}
	for (i = GB_WG_CurrInitPhoneCount; i < GB_WG_CurrInitPhoneCount + PHONEBOOK_INIT_STEP_COUNT; i++)
	{
		if (i < GB_WG_Get_PhoneBook_Size())
		{
			gbmmi_repot_AddAPhoneIndex(GB_WG_Get_PhoneBook_Index(i));
		}
		else
		{
			break;
		}
	}
	GB_WG_CurrInitPhoneCount = i;
	if (GB_WG_CurrInitPhoneCount < GB_WG_Get_PhoneBook_Size())
	{
		StartTimer(GB_WG2_SMD_RELEAS_TIME, 0, GB_WG_Add_PhoneList_ext);
	}
}

GB_VOID GB_WG_Add_PhoneList(GB_VOID)
{
	GB_WG_CurrInitPhoneCount = 0;
	GB_WG_Add_PhoneList_ext();
}

GB_VOID GB_WG_Get_PhoneBook_Name(GB_U16 store_index,GB_U16*pName)
{
	if (pName)
	{
		*pName = 0;
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
#ifdef __MMI_TELEPHONY_SUPPORT__
        srv_phb_datamgr_get_name(store_index, pName, MMI_PHB_NAME_LENGTH);
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 
#else
		if (PhoneBook[store_index].alpha_id.name_length>0)
		{
			GB_MEMCPY((GB_VOID*)pName, (GB_VOID*)PhoneBook[store_index].alpha_id.name,
				PhoneBook[store_index].alpha_id.name_length*sizeof(*pName));
			pName[PhoneBook[store_index].alpha_id.name_length] = 0;
		}
#endif
	}
}
//lzp for 11A
GB_INT GBMD_GetPhoneNumByIndex(GB_U16 type, GB_U16 store_index, GB_U16*pNumber, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pNumber)
	{
		*pNumber = 0;
		if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
		{
            #ifdef __MMI_TELEPHONY_SUPPORT__       

            mmi_phb_optional_fields_struct* optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_index);
            if(type>0 && type <= MMI_PHB_NUMBER_FIELD_COUNT)
            {
                GB_CHAR* telNum = optional_fields_data->num[type-1].number;
                if (telNum[0])
                {
                    mmi_asc_n_to_wcs(pNumber, (GB_CHAR*)telNum, nBuffLen-1);
                    pNumber[nBuffLen-1] = 0;
                    ret = 1;
                }
            }
            #endif/*__MMI_TELEPHONY_SUPPORT__ */            
		}
		else
		{
			if (GBMD_Numtype_Phone >= type)
			{
                #ifdef __MMI_TELEPHONY_SUPPORT__            
				GB_CHAR* telNum = (GB_CHAR*)srv_phb_get_sim_number(store_index, 0, NULL);
				if (telNum)
				{
					mmi_asc_n_to_wcs(pNumber, (GB_CHAR*)telNum, nBuffLen-1);
					pNumber[nBuffLen-1] = 0;
					ret = 1;
				}
                #endif/*__MMI_TELEPHONY_SUPPORT__ */
			}                          
		}
	}
	return ret;
}
//lzp for 11A
GB_INT GBMD_GetPhoneRealType(GB_U16 type, GB_U16 store_index)
{
	GB_INT ret = GBMD_Numtype_Phone;
	if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
    {
#ifdef __MMI_TELEPHONY_SUPPORT__    
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
#endif/*__MMI_TELEPHONY_SUPPORT__ */        
    }
	return ret;
}
 
GB_BOOL GB_WG_PhoneBook_IsHasOptionalField(GB_U16 store_index)
{
#ifdef __MMI_TELEPHONY_SUPPORT__

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
	if (store_index < MAX_PB_PHONE_ENTRIES)
	{
		GB_S16 pError;
		ReadRecord(
			NVRAM_EF_PHB_FIELDS_LID,
			(GB_U16) (store_index + 1),
			(GB_VOID*)&gbmmi_repot_PhoneBookOptionalFields,
			OPTIONAL_FIELDS_RECORD_SIZE,
			&pError);
		return GB_TRUE;
	}
#endif // #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
#endif
	return GB_FALSE;
}

#ifdef __COSMOS_MMI_PACKAGE__
GB_U32 mmi_bit2idx(GB_U32 bit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GB_U32 idx = 0;                                                    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
                                                                
    while ((idx < sizeof(GB_U32) * 8) && !((0x01 << idx) & bit))    
    {                                                           
        idx++;                                                  
    }                                                           
   return idx;     
}

#define MMI_CLOG_BIT2IDX(bit)                        (mmi_bit2idx(bit))

#endif

/************************************************************************/
/*                      通话记录                                        */
/************************************************************************/
void gbmmi_repot_add_recentcall(U16 * key_input)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_clog_get_list_log_ids_req_struct req_data;
	srv_clog_get_list_log_ids_cnf_struct cnf_data;
	srv_clog_log_struct log;
	unsigned short CachType = 0;
	unsigned short index_type = 0;
	unsigned short Index = 0;
	U16 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (gb_wg_wcslen((GB_U16*)key_input) < 1)
	{
		return;
	}
#ifdef __MMI_TELEPHONY_SUPPORT__
	srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
	srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);
#else
        return;
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

	req_data.start_by = SRV_CLOG_BY_ID;
	req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;

	while(1)
	{
		req_data.start_elm = cnf_data.next_start_elm;
        #ifdef __MMI_TELEPHONY_SUPPORT__        
		if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
        #endif/*__MMI_TELEPHONY_SUPPORT__ */             
		{
			break;
		}
		for (i = 0; i < cnf_data.log_num; i++)
		{
            #ifdef __MMI_TELEPHONY_SUPPORT__       
            srv_clog_get_log_by_id(0, cnf_data.log_ids[i], SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_CID, &log);
            #endif/*__MMI_TELEPHONY_SUPPORT__ */ 

			if(!lookUpNumber((GB_CHAR*)log.data.call_log.cid)
			    && mmi_wcsstr(log.data.call_log.cid, key_input))
			{
				Index = cnf_data.log_ids[i];
				if(MMI_CLOG_BIT2IDX(log.data.call_log.sim_id) == SRV_CLOG_SIM_IDX_SIM1)
				{
					CachType = GBMD_CachType_Recalled;
				}
				else
				{
					CachType = GBMD_CachType_Recalled2;
				}
				if (log.data.call_log.log_type == SRV_CLOG_CLT_DIALED)
				{
					index_type = GBMD_Numtype_DialedNum;
				}
				else if (log.data.call_log.log_type == SRV_CLOG_CLT_MISSED)
				{
					index_type = GBMD_Numtype_MissedNum;
				}
				else if (log.data.call_log.log_type == SRV_CLOG_CLT_RECVED)
				{
					index_type = GBMD_Numtype_ReceivedNum;
				}
				GB_WG_AddKeyToTarget(CachType, index_type, Index);  
			}
		}
		if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
		{
			break;
		} 
	}
	return;
}
GB_VOID gbmmi_repot_start_read_recentcall(GB_VOID)
{
	
}

GB_WG_Phone_Mode GB_WG_Get_Phone_Mode(GB_VOID)
{
	GB_WG_Phone_Mode nmode = e_GB_WG_SMD_PHONE_NORMAL;
	if (GB_WG_CheckUsbmode())
	{
		nmode = e_GB_WG_PHONE_MODE_USB;
	}
#ifdef __MMI_TELEPHONY_SUPPORT__    
	else if(srv_mode_switch_is_network_service_available() == MMI_FALSE)
	{
		nmode = e_GB_WG_PHONE_MODE_FLIGHT;
	}
#endif/*__MMI_TELEPHONY_SUPPORT__ */      
	else
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
#endif
/* under construction !*/
#else
	if (!mmi_bootup_is_sim_valid())
#endif
	{
		nmode = e_GB_WG_PHONE_MODE_NOSIM;
	}
	return nmode;
}




/************************************************************************/
/*                     本地功能                                        */
/************************************************************************/

#include "mmi_rp_all_defs.h"
#include "GlobalMenuItems.h"
typedef struct 
{
	GB_BOOL winguo_state;  //根据状态来对一些条件进行处理，比如在双卡状态下等等；
	GB_USHORT winguo_menuid;
    
}winguo_item_struct;

#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)

#include "appmgrsrvgprot.h"

//static mmi_app_package_name_struct gb_wg_AppNmeList[100] = {0};
//static GB_UINT gb_wg_nAppCount = 0;
#define GB_WG_DEFAULTAPP_MAX_COUNT  8
#define GB_WG_APPNMELIST_MAX_COUNT  100
typedef struct
{
	GB_U32                      ndefaultAppCount;
	mmi_app_package_name_struct defaultApp[GB_WG_DEFAULTAPP_MAX_COUNT];
	GB_U32                      nappNmeLisCount;
	mmi_app_package_name_struct appNmeList[GB_WG_APPNMELIST_MAX_COUNT];
}GB_WG_AppInfo;
static GB_WG_AppInfo *gb_wg_AppInfo = GB_NULL;

const unsigned short GBMD_Winguo_FunList[] = {0};
const winguo_item_struct GBMD_FlaotAPP_FunList[]={0};

#else

const unsigned short GBMD_Winguo_FunList[]={
	MITEM101_PBOOK_SEARCH_ENTRY,//姓名查找
	MITEM102_PBOOK_NEW_ENTRY,//添加号码

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
#if defined ( __MMI_PHB_CALLERGROUP__ )
	MITEM109_PBOOK_CALLER_GROUPS,
#endif	
	MITEM1101_PBOOK_MEMORY_STATUS,//pbook内存状态
#elif defined(GB_MTK_10APLAT)
	0,
	0,
#endif

//	MENU9146_WELCOME_TEXT,
	MENU_VOLUME_LEVEL,//音量大小
#ifndef GB_MTK_10APLAT
	MENU_SETTING_PREFERED_INPUT_METHOD,//预设输入法
#endif
//	MENU_SETTING_WALLPAPER,
#ifdef __MMI_SETTING_SCREEN_SAVER__
	MENU_SETTING_SCR_SVR,
#endif
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
	MENU_SETTING_SCHEDULE_POWER,//定时开关机
#endif	
	0,
	0,
//	MENU9165_PHONE_LOCK,//手机锁
//	MENU3101_THEMES,//主题
	MAIN_MENU_PROFILES_MENUID,//情景模式
	MENU_MT_CALL_ALERT_TYPE,
	MENU_TONE_SETUP,
#ifdef __MMI_CALENDAR__	
	ORGANIZER_CALENDER_MENU,//日历
#endif	
#if defined(__MMI_TODOLIST__)
	ORGANIZER_TODOLIST_MENU,//任务
#endif	
	ORGANIZER_ALARM_MENU,//闹钟
	EXTRA_CALCULATOR_MENU,//计算器
//	EXTRA_CURRENCYCONVERTOR_MENU,//汇率换算
	0,
#if defined (__MMI_WORLD_CLOCK__)	
	MITEM_WORLDCLOCK_BROWSECITY,
#endif	
	MESSAGES_MENU_WMESSAGE_MENU_ID,
	MESSAGES_MENU_INBOX_MENUID,
	MESSAGES_MENU_OUTBOX_MENUID,

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	AUDIO_PLAYER_MAIN_MENUID,//音乐播放器
#elif defined(GB_MTK_10APLAT)
	0,
#endif

	MENU_CONN_BT_MAIN,//蓝牙
	SERVICES_WAP_MENU_ID,//无线上网
	MESSAGES_MENU_MMS_MENUID,//彩信

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	MENU_ID_VDOREC_APP,//摄像机
#elif defined(GB_MTK_10APLAT)
#if defined(__MMI_CAMCORDER__)
	MENU_ID_CAMCORDER_APP,
#else
	0,
#endif
#endif

#ifdef __MMI_VIDEO_PLAYER__
	MENU_ID_VDOPLY_APP,//视频播放器
#endif
#if (defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_NEW__))	
	MENU_ID_SNDREC_MAIN,//录音
#endif	
#if defined(__MMI_IMAGE_VIEWER_EX__)
	MENU_ID_IMGVIEW_APP,//相册
#endif
#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
	MENU_ID_CAMERA_APP,//照相机
#endif	
#elif defined(GB_MTK_10APLAT)
#if defined(__MMI_CAMCORDER__)
	MENU_ID_CAMCORDER_APP,
#else
	0,
#endif
#endif
#ifdef __MMI_EBOOK_READER__
	MAIN_MENU_EBOOK_MENUID//电子书
#else
	0
#endif
};

#if defined(GB_MTK_10APLAT)
#ifndef __MMI_DUAL_SIM_MASTER__
const winguo_item_struct GBMD_FlaotAPP_FunList[]={
	{0,MAIN_MENU_PHONEBOOK_MENUID},//电话簿
	//{0,MENU_ID_PHB_QUICK_SEARCH},//快速查找
	{0,MITEM101_PBOOK_SEARCH_ENTRY},//姓名查找
	{0,MITEM102_PBOOK_NEW_ENTRY},//添加号码、
	{0,MAIN_MENU_MESSAGES_MENUID},//信息中心
	{0,MENU_ID_UM_WRITE_MSG},//新建信息

#ifdef __UM_SUPPORT__
	{0,MENU_ID_UM_INBOX},//收件箱
	{0,MENU_ID_UM_DRAFT},//草稿箱
	{0,MENU_ID_UM_UNSENT},//发件箱
	{0,MENU_ID_UM_SENT},//已发信息
//	{0,MENU_ID_UM_ARCHIVE},//文件夹
//	{0,MENU_ID_UM_DELETE_FOLDER},//删除信息
//	{0,MENU_ID_EMAIL_MAIN},//电子邮件
	{0,MENU_ID_UM_SETTING},//信息设置
#endif /*__UM_SUPPORT__ */
//	{0,MENU_ID_UM_CB_MAIN},//小区广播
//	{0,MENU_ID_UM_SETTING_SMS},//短信
//	{0,MENU_ID_UM_SETTING_MMS},//彩信
//	{0,MENU_ID_UM_SETTING_PUSH},//服务信息
    #ifdef __MMI_TELEPHONY_SUPPORT__
	{0,MAIN_MENU_CALL_CENTER},//通话中心
	 #endif
	{0,MAIN_MENU_CALL_LOG},//通话记录
	{0,MENU_ID_CLOG_MISSED_CALL},//未接电话
	{0,MENU_ID_CLOG_DIALED_CALL},//已拨电话
	{0,MENU_ID_CLOG_RECVED_CALL},//已接电话
//	{0,MENU_ID_CLOG_DELETE_BOX},//删除通话记录
#ifdef __MMI_CLOG_CALL_TIME__
	{0,MENU_ID_CLOG_CALL_TIME},//通话计时
#endif
#ifdef __MMI_CLOG_CALL_COST__
	{0,MENU_ID_CLOG_CALL_COST},//通话计费
#endif
#ifdef __MMI_CLOG_SMS_COUNT__
	{0,MENU_ID_CLOG_SMS_COUNT},//短信计数器
#endif

	{0,MAIN_MENU_FUNANDGAMES_MENUID},//应用和娱乐
//	{0,MAIN_MENU_VRE_MENUID},//娱乐中心

	{0,MAIN_MENU_MULTIMEDIA_MENUID},//多媒体
#if defined(__MMI_CAMCORDER__)	
	{0,MENU_ID_CAMCORDER_APP},//摄录像?
#endif
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
	{0,MENU_ID_CAMERA_APP},//照相机
#endif	
#if defined(__MMI_IMAGE_VIEWER_EX__)
	{0,MENU_ID_IMGVIEW_APP},//相册
#endif	
	//{0,MENU_ID_MEDPLY_MAIN},//媒体播放器
//	{0,MENU_ID_PHOEDT_APP},//照片编辑器
#if (defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_NEW__))
	{0,MENU_ID_SNDREC_MAIN},//录音
#endif	
#ifdef __MMI_FM_RADIO__
	{0,MENU_ID_FMRDO_MAIN},//调频广播
#endif	
	//{0,MENU3103_RINGTONE_COMPOSER},//自编铃声
	//{0,MENU_ID_SLIDSHOW_APP},//幻灯片

	{0,MAIN_MENU_FILE_MNGR_MENUID},//我的资料

#if  defined(__MMI_OP02_MAINMENU_9MATRIX__)||defined(__MMI_OP02_MAINMENU_12MATRIX__)||defined(__MMI_OP01_MENU_9MATRIX__)||defined(__MMI_OP01_MENU_12MATRIX__)    
		{0,MAIN_MENU_SERVICES_MENUID},//网络服务
#endif
	{0,SERVICES_WAP_MENU_ID},//无线上网
#ifdef __MMI_SEARCH_WEB_BAIDU__	
	{0,MENU_ID_SEARCH_WEB_BAIDU_ENTRY},//百度搜索
#endif	
#ifdef __MMI_RMGR__
	{0,MENU_ID_RMGR},//权限管理
#endif
#if (defined(__TCPIP__) && !defined(__COSMOS_MMI_PACKAGE__))
		{0,SERVICES_DATA_CONNECT_MAIN_MENU_ID},//数据帐户
#endif	
	{0,MAIN_MENU_PROFILES_MENUID},//情景模式
	{0,MAIN_MENU_PROFILES_GENERAL},//一般模式
	{0,MAIN_MENU_PROFILES_MEETING},//会议模式
	{0,MAIN_MENU_PROFILES_OUTDOOR},//户外模式
	{0,MAIN_MENU_PROFILES_INDOOR},//室内模式
	{0,MAIN_MENU_PROFILES_HEADSET},//耳机模式
	{0,MAIN_MENU_PROFILES_BT},//蓝牙模式
	{0,MAIN_MENU_ORGANIZER_MENUID},//工具箱

	{0,ORGANIZER_CALENDER_MENU},//日历
#if defined(__MMI_TODOLIST__)
	{0,ORGANIZER_TODOLIST_MENU},//任务
#endif	
	{0,ORGANIZER_ALARM_MENU},//闹钟
#ifdef __MMI_AZAAN_ALARM__
	{0,MENU_ID_AZAAN_ALARM},//祈祷闹钟
#endif
#ifdef __MMI_WORLD_CLOCK__
	{0,ORGANIZER_WORLDCLOCK_MENU},//世界时间
#endif	
//	{0,MENU_ID_NOTE_APP_MAIN},//备注
//	{0,MENU_ID_SYNCML_MAIN},//同步
//	{0,MENU_ID_SYNCML_DEV_MAIN},//手机同步
	//{0,MENU_STOPWATCH},//秒表

	{0,MAIN_MENU_SETTINGS_MENUID},//设置
//	{0,MENU_ID_MODE_SWITCH_TYPE},//模式设置方式
#if (MMI_MAX_SIM_NUM >= 2)
	{0,MENU_ID_MODE_SWITCH_SETTING},//模式设置
#endif
#if defined(__MMI_TOUCH_SCREEN__)
	{0,MENU_SETTING_CALIBRATION},//触屏校准
#endif
	{0,MENU9102_INITIAL_SETUP},//手机设置

#ifdef __MMI_TELEPHONY_SUPPORT__
	{0,MENU_ID_NETSET_MAIN},//网络设置
#endif
	//{0,MENU_MTPNP_DM_SECURITY_SETTING},//安全设置
//	{0,MENU9165_PHONE_LOCK},//手机锁
//	{0,MENU9170_CHANGE_PASSWORD},//更改密码
	{0,MENU_ID_CONNECTIVITY},//外部连接
	{0,MENU_CONN_BT_MAIN},//蓝牙
	{0,MENU_SETTING_RESTORE},//恢复出场设置
#ifdef __MMI_SOUND_EFFECT__
	{0,MENU_SETTING_SOUND_EFFECT},//音效
#endif	
	{0,MENU_IDLE_SCR_DISP},//显示设置
	{0,MENU9141_TIME_AND_DATE},//时间与日期
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
	{0,MENU_SETTING_SCHEDULE_POWER},//定时开关机
#endif	
	{0,MENU_SETTING_LANGUAGE},//语言选择
	//{0,MENU_ID_PHNSET_PREFERED_WRITING_LANG},
	//{0,MENU_SETTING_PREFERED_INPUT_METHOD},//预设输入法
#if defined(__MMI_SET_DEF_ENCODING_TYPE__)
	{0,MENU_SETTING_DEF_ENCODING_TYPE},//编码方式
#endif
	{0,MENU_IDLE_SCR_DISP},//待机菜单显示
#if defined (__MMI_THEMES_APPLICATION__) && !defined (__MMI_THEME_COUNT_ONE__)	
	{0,MENU3101_THEMES},//主题
#endif	
#ifdef SHORTCUTS_APP
	{0,EXTRA_SHORTCUTS_MENUID},//快捷功
#endif
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
	{0,MENU_SETTING_DEDICATED_KEYS},//指定功能键
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif	
	//{0,MENU_ID_UCM_CALL_SETTING},//通话设置
	{0,MENU_SETTING_SPEED_DIAL},//快速拨号
	{0,MENU_CONNECT_NOTICE},//接通震动
	//{0,MENU_MTPNP_DM_NETWORK_SETUP},//网络设置


	//		{0,MENU_SETTING_PRIVACY},//信息加密
	//		{0,MENU_ID_REMOTE_TRACK},//防盗追踪

	{0,MAIN_MENU_EXTRA_MENUID},//附加功能
	{0,EXTRA_CALCULATOR_MENU},//计算器
//	{0,EXTRA_UNITCONVERTOR_MENU},//单位换算
//	{0,EXTRA_CURRENCYCONVERTOR_MENU},//汇率换算
//	{0,MENU_STOPWATCH},//码表
#ifdef __MMI_EBOOK_READER__
		{0,MAIN_MENU_EBOOK_MENUID},//电子书
#endif
#if defined(__MMI_AUTO_ANSWER_MACHINE__)
	{0,MENU_ID_AUTOAM_MAIN},//答录机
#endif
#if defined(__MMI_GAME__)
	{0,MENU3105_GAMES},//游戏
#endif

//	{0,MENU_ID_ZAKAT_CALCULATOR}//天课计算器
};
#else // __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UM_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UM_SUPPORT__
/* under construction !*/
#endif /* __UM_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_CALL_TIME__
/* under construction !*/
#endif
#ifdef __MMI_CLOG_CALL_COST__
/* under construction !*/
#endif
#ifdef __MMI_CLOG_SMS_COUNT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_CAMCORDER__)
/* under construction !*/
#endif
/* under construction !*/
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
/* under construction !*/
#endif	
#if defined(__MMI_IMAGE_VIEWER_EX__)
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
#if (defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_NEW__))
/* under construction !*/
#endif	
#ifdef __MMI_FM_RADIO__
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if  defined(__MMI_OP02_MAINMENU_9MATRIX__)||defined(__MMI_OP02_MAINMENU_12MATRIX__)||defined(__MMI_OP01_MENU_9MATRIX__)||defined(__MMI_OP01_MENU_12MATRIX__)    
/* under construction !*/
#endif	
/* under construction !*/
#ifdef __MMI_SEARCH_WEB_BAIDU__	
/* under construction !*/
#endif	
#ifdef __MMI_RMGR__
/* under construction !*/
#endif
#if (defined(__TCPIP__) && !defined(__COSMOS_MMI_PACKAGE__))
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_TODOLIST__)
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_AZAAN_ALARM__	
/* under construction !*/
#endif
#ifdef __MMI_WORLD_CLOCK__
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
#endif
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SOUND_EFFECT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_SET_DEF_ENCODING_TYPE__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef SHORTCUTS_APP
/* under construction !*/
#endif
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
/* under construction !*/
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_EBOOK_READER__
/* under construction !*/
#endif
#if defined(__MMI_AUTO_ANSWER_MACHINE__)
/* under construction !*/
#endif
#if defined(__MMI_GAME__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __MMI_DUAL_SIM_MASTER__

#else // #if defined(GB_MTK_10APLAT)
#error no body
#endif // #if defined(GB_MTK_10APLAT)

#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)





GB_VOID gbmmi_app_Init_AppList(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		gb_wg_AppInfo->nappNmeLisCount = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
		srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, gb_wg_AppInfo->appNmeList, sizeof(gb_wg_AppInfo->appNmeList)/sizeof(gb_wg_AppInfo->appNmeList[0]));
	}
#endif
}


GB_WCHAR* gbmmi_repot_getApp_Name(GB_U16 menu_id, GB_WCHAR *pstrBuff, GB_U16 nBuffLen)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (pstrBuff && nBuffLen)
	{
		if (gb_wg_AppInfo)
		{
			if (menu_id < gb_wg_AppInfo->nappNmeLisCount)
			{
				mmi_app_package_name_struct tempAppNmeABuff;
				if (GB_STRCMP(gb_wg_AppInfo->appNmeList[menu_id], "native.mtk.cosmos_mainmenu") == 0)
				{
					return GB_NULL;
				}
				srv_appmgr_get_app_package_name((mmi_app_package_char*)gb_wg_AppInfo->appNmeList[menu_id], (WCHAR*)tempAppNmeABuff);
				pstrBuff[nBuffLen-1] = 0;
				gb_wg_wcsncpy(pstrBuff, (const GB_WCHAR*)tempAppNmeABuff, nBuffLen-1);
				return pstrBuff;
			}
		}
	}
	return GB_NULL;
#else
	return (GB_WCHAR*)get_string(GetStringIdOfItem(menu_id));
#endif
}

GB_INT GB_WG_SetDefaultApp(GB_U16 menu_id)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		if (menu_id < gb_wg_AppInfo->nappNmeLisCount)
		{
			GB_INT i;
			GB_INT pos = -1;
			for (i = 0; i < gb_wg_AppInfo->ndefaultAppCount; i++)
			{
				if (GB_STRCMP(gb_wg_AppInfo->appNmeList[menu_id], gb_wg_AppInfo->defaultApp[i]) == 0)
				{
					pos = i;
					break;
				}
			}
			if (pos < 0)
			{
				gb_wg_AppInfo->ndefaultAppCount++;
				gb_wg_AppInfo->ndefaultAppCount = GB_MIN(gb_wg_AppInfo->ndefaultAppCount, GB_WG_DEFAULTAPP_MAX_COUNT);
				pos = GB_MIN(gb_wg_AppInfo->ndefaultAppCount, GB_WG_DEFAULTAPP_MAX_COUNT);
			}
			pos = GB_MIN(pos, GB_WG_DEFAULTAPP_MAX_COUNT-1);
			if (pos > 0)
			{
				GB_MEMMOVE(&gb_wg_AppInfo->defaultApp[1], &gb_wg_AppInfo->defaultApp[0], pos*sizeof(gb_wg_AppInfo->defaultApp[0]));
			}
			GB_MEMCPY(gb_wg_AppInfo->defaultApp[0], gb_wg_AppInfo->appNmeList[menu_id], sizeof(gb_wg_AppInfo->defaultApp[0]));
		}
	}
#endif
	return 1;
}

GB_INT GB_WG_GetDefaultAppCount(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		return gb_wg_AppInfo->ndefaultAppCount;
	}
#endif
	return 0;
}

GB_INT GB_WG_GetDefaultApp(GB_U16 Index)
{
	GB_INT ret = -1;
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	while(gb_wg_AppInfo)
	{
		GB_INT i;
		if (Index > gb_wg_AppInfo->ndefaultAppCount)
		{
			break;
		}
		for (i = 0; i < gb_wg_AppInfo->nappNmeLisCount; i++)
		{
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[i], gb_wg_AppInfo->defaultApp[Index]) == 0)
			{
				ret = i;
				break;
			}
		}
		break;
	};
#endif
	return ret;
}

GB_INT GB_WG_DefaultAppCmp(GB_U16 Index1, GB_U16 Index2)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (Index1 != Index2 && gb_wg_AppInfo)
	{
		GB_INT i;
		for(i = 0; i < gb_wg_AppInfo->ndefaultAppCount; i++)
		{
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[Index1], gb_wg_AppInfo->defaultApp[i]) == 0)
			{
				return -1;
			}
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[Index2], gb_wg_AppInfo->defaultApp[i]) == 0)
			{
				return 1;
			}
		}
	}
#endif
	return 0;
}
#define GB_WG_APP_DATA_SAVE_PATH             "c:\\guobi\\"
#define	GB_WG_APP_DATA_INFO			"c:\\guobi\\gb_wg_appinfo"

enum __MD_Lang_Enum__
{
	MD_Lang_Name_Arabic, 
	MD_Lang_Name_Bulgarian, 
	MD_Lang_Name_Danish, 
	MD_Lang_Name_Dutch, 
	MD_Lang_Name_Farsi, 
	MD_Lang_Name_French, 
	MD_Lang_Name_German, 
	MD_Lang_Name_Greek, 
	MD_Lang_Name_Hebrew, 
	MD_Lang_Name_Hindi, 
	MD_Lang_Name_Hungarian, 
	MD_Lang_Name_Indonesia, 
	MD_Lang_Name_Italian, 
	MD_Lang_Name_Malay, 
	MD_Lang_Name_Philipino, 
	MD_Lang_Name_Polish, 
	MD_Lang_Name_Potuguese, 
	MD_Lang_Name_Russian, 
	MD_Lang_Name_Spanish, 
	MD_Lang_Name_Swahili, 
	MD_Lang_Name_Thai, 
	MD_Lang_Name_Tibetan, 
	MD_Lang_Name_Turkish, 
	MD_Lang_Name_Uyghur, 
	MD_Lang_Name_Vietnam, 
	MD_Lang_Name_Bengali, 
	MD_Lang_Name_COUNT
};

GB_VOID GB_WG_SmdLanguageAdd(GB_VOID)
{
#ifdef __MMI_LANG_ARABIC__
	GBMD_AddLangKeyMap(MD_Lang_Name_Arabic); 
#endif
#ifdef __MMI_LANG_BULGARIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Bulgarian); 
#endif
#ifdef __MMI_LANG_DANISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Danish); 
#endif
#ifdef __MMI_LANG_DUTCH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Dutch); 
#endif
#ifdef __MMI_LANG_PERSIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Farsi); 
#endif
#ifdef __MMI_LANG_FRENCH__
	GBMD_AddLangKeyMap(MD_Lang_Name_French); 
#endif
#ifdef __MMI_LANG_GERMAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_German); 
#endif
#ifdef __MMI_LANG_GREEK__
	GBMD_AddLangKeyMap(MD_Lang_Name_Greek); 
#endif
#ifdef __MMI_LANG_HEBREW__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hebrew); 
#endif
#ifdef __MMI_LANG_HINDI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hindi); 
#endif
#ifdef __MMI_LANG_HUNGARIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hungarian); 
#endif
#ifdef __MMI_LANG_INDONESIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Indonesia); 
#endif
#ifdef __MMI_LANG_ITALIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Italian); 
#endif
#ifdef __MMI_LANG_MALAY__
	GBMD_AddLangKeyMap(MD_Lang_Name_Malay); 
#endif
#ifdef __MMI_LANG_FILIPINO__
	GBMD_AddLangKeyMap(MD_Lang_Name_Philipino); 
#endif
#ifdef __MMI_LANG_POLISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Polish); 
#endif
#ifdef __MMI_LANG_PORTUGUESE__
	GBMD_AddLangKeyMap(MD_Lang_Name_Potuguese); 
#endif
#ifdef __MMI_LANG_RUSSIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Russian); 
#endif
#ifdef __MMI_LANG_SPANISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Spanish); 
#endif
#ifdef __MMI_LANG_SWAHILI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Swahili); 
#endif
#ifdef __MMI_LANG_THAI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Thai); 
#endif
#ifdef __MMI_LANG_TIBETAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Tibetan); 
#endif
#ifdef __MMI_LANG_TURKISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Turkish); 
#endif
#ifdef __MMI_LANG_UYGHUR__
	GBMD_AddLangKeyMap(MD_Lang_Name_Uyghur); 
#endif
#ifdef __MMI_LANG_VIETNAMESE__
	GBMD_AddLangKeyMap(MD_Lang_Name_Vietnam); 
#endif
#ifdef __MMI_LANG_BENGALI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Bengali); 
#endif
}

GB_VOID GB_WG_SmdInitCallBack(GB_VOID)
{
	// 对多语言的支持
	GB_WG_SmdLanguageAdd();
	// 获取用户常用的app
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (!gb_wg_AppInfo)
	{
		gb_wg_AppInfo = (GB_WG_AppInfo*)GB_WG_Malloc(sizeof(GB_WG_AppInfo));
		GB_MEMSET(gb_wg_AppInfo, 0, (GB_UINT)&((GB_WG_AppInfo*)0)->nappNmeLisCount);
	}
	if (!gb_wg_AppInfo)
	{
		return;
	}
	GB_file_read_dataExEx(GB_WG_APP_DATA_INFO, GB_WG_GetSmartdailDrive(), (GB_VOID*)gb_wg_AppInfo,sizeof(*gb_wg_AppInfo));
#endif
}
GB_VOID GB_WG_SmdReleaseCallBack(GB_VOID)
{
	// 释放默认的app，需要存放到文件
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		GB_file_init_pathEx(GB_WG_APP_DATA_SAVE_PATH, GB_WG_GetSmartdailDrive());
		GB_file_write_ex(GB_WG_APP_DATA_INFO, GB_WG_GetSmartdailDrive(),(GB_VOID*)gb_wg_AppInfo,sizeof(*gb_wg_AppInfo), 0);

		GB_WG_Free(gb_wg_AppInfo);
		gb_wg_AppInfo = GB_NULL;
	}
#endif
}

GB_WG_FuncPtr GB_WG_mmi_frm_get_hilite_hdlr(GB_USHORT menuID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	return (GB_WG_FuncPtr)1;
#else
	return mmi_frm_get_hilite_hdlr(menuID);
#endif
}

GB_INT GB_WG_Get_LocalFunList_Size()
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		return gb_wg_AppInfo->nappNmeLisCount;
	}
#else
	return sizeof(GBMD_FlaotAPP_FunList)/sizeof(GBMD_FlaotAPP_FunList[0]);
#endif
}

GB_INT GB_WG_Get_WinguoLocalFunList_Size()
{
	return sizeof(GBMD_Winguo_FunList)/sizeof(GBMD_Winguo_FunList[0]);
}

GB_U16 GB_WG_Get_LocalFunList_MenuID_ByIndex(GB_INT index)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	return index;
#else
	if (index<GB_WG_Get_LocalFunList_Size())
	{
		return GBMD_FlaotAPP_FunList[index].winguo_menuid;
	}
	return 0;
#endif
}

GB_INT GB_GetAppMenuCardFlog(GB_U16 nMenuId)
{
	GB_INT i;
	for(i = 0; i < sizeof(GBMD_FlaotAPP_FunList)/sizeof(GBMD_FlaotAPP_FunList[0]) 
								&& GBMD_FlaotAPP_FunList[i].winguo_state > 0 ; i++)
	{
		if(nMenuId == GBMD_FlaotAPP_FunList[i].winguo_menuid)
		{
			return GBMD_FlaotAPP_FunList[i].winguo_state;
		}
	}
	return 0;
}

#if defined(GB_MTK_09APLAT)
extern S32 ShctCheckItemCanbeExecuted(U16 selitem);
#endif

// 如果是smartdail，取的是funapp数组，否则就是与后台对应的数据页面
GB_INT GB_WG_RunApp(GB_U16 usIndex,GB_BOOL isSmartDail)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	mmi_app_package_name_struct tempappNmeList;
	if (isSmartDail && gb_wg_AppInfo)
	{
		if (usIndex < gb_wg_AppInfo->nappNmeLisCount)
		{
			GB_WG_SetDefaultApp(usIndex);

			strcpy(tempappNmeList, gb_wg_AppInfo->appNmeList[usIndex]);
			GB_WG_FreeWin();
			GB_WG_ExitApp();
			
			if (strncmp(tempappNmeList, "native.mtk.home", MMI_APP_NAME_MAX_LEN) == 0 ||
				strncmp(tempappNmeList, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
			{
				GB_WG_GotoIdleScreen();
			}
			else
			{
				srv_appmgr_launch(tempappNmeList);
			}
			
			return 1;
		}
	}
#else // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	GB_U16 nMenuId = 0;
	if (isSmartDail)
	{
		nMenuId = GB_WG_Get_LocalFunList_MenuID_ByIndex(usIndex);
	}
	else
	{
		nMenuId = GB_WG_GetWinguoFunListID(usIndex);
	}
#if defined(GB_MTK_09APLAT)
	if (ShctCheckItemCanbeExecuted(nMenuId) == 0)
#else
	if (mmi_frm_get_hilite_hdlr(nMenuId))
#endif
	{
		GB_WG_FuncPtr pFun;
		// 没运行APP之前锁屏 [lzp 2012-1-6]
		gui_lock_double_buffer();
		(mmi_frm_get_hilite_hdlr(nMenuId))();
		pFun = (GB_WG_FuncPtr)get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
		gui_unlock_double_buffer();
		if (pFun)
		{
			pFun();
			return 1;
		}
	}
#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	return 0;
}

GB_INT GB_JudgeAppMenuvalid(GB_U16 usIndex)
{
	int CardFlog;
	if(!(
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
#endif
#else // __MMI_DUAL_SIM_MASTER__
		mmi_bootup_is_sim_valid() == MMI_TRUE
#endif
		))
	{
		return 0;
	}
	CardFlog = GB_GetAppMenuCardFlog(GB_WG_Get_LocalFunList_MenuID_ByIndex(usIndex));
	//当有AB卡时，要区分它们的有效性
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	return 1;
}


#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_09APLAT) || defined(GB_MTK_10APLAT)

#define IMG_GB_SMARTWINGUO_PHB_STORAGE_HANDSET  IMG_WG_SMARTDAIL_MOBILEPHONE//IMG_STORAGE_HANDSET
#define IMG_GB_SMARTWINGUO_PHB_HOME_NUMBER IMG_WG_SMARTDAIL_HOME_PHONE//IMG_HOME_NUMBER
#define IMG_GB_SMARTWINGUO_PHB_OFFICE_NUMBER IMG_WG_SMARTDAIL_OFFICE//IMG_OFFICE_NUMBER
#define IMG_GB_SMARTWINGUO_PHB_FAX_NUMBER IMG_WG_SMARTDAIL_FAX//IMG_FAX_NUMBER
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else // __MMI_DUAL_SIM_MASTER__
#define IMG_GB_SMARTWINGUO_PHB_STORAGE_SIM1 IMG_WG_SMARTDAIL_CONTACT//IMG_STORAGE_SIM
#define IMG_GB_SMARTWINGUO_DIALED_CALLS_SIM1 IMG_WG_SMARTDAIL_CALL_OUT//IMG_MENU_DIALED_CALLS
#define IMG_GB_SMARTWINGUO_MISSED_CALLS_SIM1 IMG_WG_SMARTDAIL_MISSCALL//IMG_MENU_MISSED_CALLS
#define IMG_GB_SMARTWINGUO_RECEIVED_CALLS_SIM1 IMG_WG_SMARTDAIL_CALL_IN//IMG_MENU_RECEIVED_CALLS
#endif

#endif

GB_INT GBMD_GetIconForSmd(GB_U16 CachType, GB_U16 index_type, GB_U16 index, GB_PU8 *img_buff_p)
{
	if(CachType == GBMD_CachType_Recalled)
	{
#if defined(GB_MTK_10APLAT)
		{
			srv_clog_log_struct log;
			srv_clog_log_identity_struct idt;
            #ifdef __MMI_TELEPHONY_SUPPORT__            
			srv_clog_get_log_by_id(0, index, SRV_CLOG_LOG_FIELD_IDENTITY | SRV_CLOG_LOG_FIELD_CID, &log);             
            #endif/*__MMI_TELEPHONY_SUPPORT__ */  

			idt.cate = log.data.call_log.cate;
			idt.sim_id = log.data.call_log.sim_id;
			idt.log_type = log.data.call_log.log_type;
			idt.sub_type = log.data.call_log.sub_type;
			//*img_buff_p = (GB_PU8)get_image(mmi_clog_get_log_icon(&idt));
			if(idt.log_type == SRV_CLOG_CLT_DIALED)
			{
				*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_DIALED_CALLS_SIM1);
			}
			else if (idt.log_type == SRV_CLOG_CLT_MISSED)
			{
				*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_MISSED_CALLS_SIM1);
			}
			else if (idt.log_type == SRV_CLOG_CLT_RECVED)
			{
				*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_RECEIVED_CALLS_SIM1);
			}

		}
#else // #if defined(GB_MTK_10APLAT)
		if(index_type == GBMD_Numtype_DialedNum)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_DIALED_CALLS_SIM1);
		}
		else if (index_type == GBMD_Numtype_MissedNum)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_MISSED_CALLS_SIM1);
		}
		else if (index_type == GBMD_Numtype_ReceivedNum)
		{
			*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_RECEIVED_CALLS_SIM1);
		}
#endif
	}
	else if(CachType == GBMD_CachType_Recalled2)
	{
#ifdef __MMI_DUAL_SIM_MASTER__
#if defined(GB_MTK_10APLAT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
             #ifdef __MMI_TELEPHONY_SUPPORT__            
/* under construction !*/
             #endif/*__MMI_TELEPHONY_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else // #if defined(GB_MTK_10APLAT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
		*img_buff_p  = 0;
		return 0;
#endif
	}
	else if(CachType == GBMD_CachType_PhoneBook)
	{
		if (index_type == GBMD_Numtype_Name || index_type == GBMD_Numtype_Phone)
		{
			if (index >= MAX_PB_PHONE_ENTRIES)
			{
#ifdef __MMI_DUAL_SIM_MASTER__
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#else
				*img_buff_p = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_PHB_STORAGE_SIM1);
				#endif
			}
			else
			{
				*img_buff_p = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_PHB_STORAGE_HANDSET);
			}
		}
		else if (index_type == GBMD_Numtype_homeNumber)
		{
			*img_buff_p = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_PHB_HOME_NUMBER);
		}
// 		else if (index_type == GBMD_Numtype_emailAddress)
// 		{
// 		}
		else if (index_type == GBMD_Numtype_officeNumber)
		{
			*img_buff_p = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_PHB_OFFICE_NUMBER);
		}
		else if (index_type == GBMD_Numtype_faxNumber)
		{
			*img_buff_p = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_PHB_FAX_NUMBER);
		}
	}
	else if(CachType == GBMD_CachType_App)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
	}
	else if(CachType == GBMD_CachType_WinguoFunction)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
	}
	else if(CachType == GBMD_CachType_Encrypt)
	{
		*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
	}
	else
	{
		*img_buff_p = NULL;
		return 0;
	}
	return 1;
}

GB_INT GBMD_GetCallLogNumByIndex(GB_INT SimType, GB_U16 Logtype, GB_U16 id, GB_U16* pstrBuf, GB_INT bufLen)
{
	if (!pstrBuf || bufLen<=0)
	{
		return 0;
	}
	GB_MEMSET(pstrBuf, 0, bufLen*sizeof(*pstrBuf));
#if defined(GB_MTK_10APLAT)
	{
	srv_clog_log_struct log;
     #ifdef __MMI_TELEPHONY_SUPPORT__     
	srv_clog_get_log_by_id(0, id, SRV_CLOG_LOG_FIELD_CID, &log);
     #endif/*__MMI_TELEPHONY_SUPPORT__ */     
	if (log.data.call_log.cid[0])
	{
		GB_MEMCPY(pstrBuf, log.data.call_log.cid, (bufLen-1)*sizeof(*pstrBuf));
		pstrBuf[bufLen-1] = 0;
	}
	}
#else
	if (0 == SimType)
	{
		GB_U16 numlen;
		GB_U16 *ptempstr = pstrBuf;
		if(Logtype == GBMD_Numtype_DialedNum)
		{
			numlen = gb_wg_wcslen((GB_WCHAR*)chis_p->dialedCalls[id].number);	
			GB_MEMCPY(ptempstr, chis_p->dialedCalls[id].number, sizeof(GB_U16)*(numlen+1));
			ptempstr += numlen;
			*ptempstr = 0;
		}
		else if(Logtype == GBMD_Numtype_MissedNum)
		{
			numlen = gb_wg_wcslen((GB_WCHAR*)chis_p->missedCalls[id].number);	
			GB_MEMCPY(ptempstr, chis_p->missedCalls[id].number, sizeof(GB_U16)*(numlen+1));
			ptempstr += numlen;
			*ptempstr = 0;
		}
		else if(Logtype == GBMD_Numtype_ReceivedNum)
		{
			numlen = gb_wg_wcslen((GB_WCHAR*)chis_p->recvdCalls[id].number);	
			GB_MEMCPY(ptempstr, chis_p->recvdCalls[id].number, sizeof(GB_U16)*(numlen+1));
			ptempstr += numlen;
			*ptempstr = 0;
		}
	}
	else if (1 == SimType)
	{
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 
		return 0;
#endif
	}
#endif  // #if defined(GB_MTK_10APLAT)
	return 0;
}

GB_INT GBMD_GetPhoneNameByIndex(GB_U16 store_index,  GB_U16* pstrBuf, GB_U16 nBuflen)
{
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
#ifdef __MMI_TELEPHONY_SUPPORT__
    srv_phb_datamgr_get_name(store_index, pstrBuf, MMI_PHB_NAME_LENGTH);
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

#else
	gb_wg_wcsncpy((GB_U16*)pstrBuf, (GB_U16*)PhoneBook[store_index].alpha_id.name, nBuflen);
#endif // #ifdef  GB_MTK_09BPLAT
	return 1;
}


GB_BOOL GB_WG_Is_Encypt_Mode()
{
	// begin:需要客户提供的加密接口
	return 0/*!PhnsetReadPRIVACYSetting_Index(SETTING_PRIVACY_PHONEBOOK)*/;
}

GB_INT GB_WG_GetWinguoFunListID(GB_INT menuID)
{
	if (menuID >= 0 && menuID < GB_WG_Get_WinguoLocalFunList_Size())
	{
		return GBMD_Winguo_FunList[menuID];
	}
	else
	{
		return 0;
	}
}

// 测试联系人头像 [11/9/2011 liangchuanhui]

GB_VOID GB_WG_show_phone_image_by_Hash_key(GB_U16 pData,GB_INT x,GB_INT y,GB_INT iwidth,GB_INT iheight)
{
	//mmi_phb_contact_id id = index;//（typedef kal_uint16 mmi_phb_contact_id;）
	srv_phb_contact contact = GB_NULL;//（typedef void* srv_phb_contact;）
	srv_phb_field_filter filter = GB_NULL;//（typedef void* srv_phb_field_filter;）
	srv_phb_res_struct* res = GB_NULL;
	GB_U16 CachType = 0;
	GB_U16 index_type = 0;
	GB_U16 store_index = 0;

	if (filter == GB_NULL)
    {
#ifdef __MMI_TELEPHONY_SUPPORT__
    filter = srv_phb_create_field_filter();
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

    }
    GBMD_TransHashKey((unsigned short)pData, &CachType, &index_type, &store_index);
    
    #ifdef __MMI_TELEPHONY_SUPPORT__    
    srv_phb_filed_filter_set_field(filter, MMI_PHB_CONTACT_FIELD_IMAGE);
    contact = srv_phb_read_contact(store_index, filter, contact);
    res = srv_phb_contact_get_image(contact);
    #endif/*__MMI_TELEPHONY_SUPPORT__ */ 

	if (res)
	{
		gdi_image_draw_resized_file(x,y,iwidth,iheight,(PS8)res->res_path);
	}
    
	if (filter)
	{
#ifdef __MMI_TELEPHONY_SUPPORT__
        srv_phb_free_field_filter(filter);
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

		filter = NULL;
	}
	if (contact)
	{
#ifdef __MMI_TELEPHONY_SUPPORT__
        srv_phb_free_contact(contact);
#endif/*__MMI_TELEPHONY_SUPPORT__ */ 

        contact = GB_NULL;
	}
}
//测试结束

#endif /* #ifdef __MMI_GB_WINGUO__ */
