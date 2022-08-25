#ifndef GBSYSTEM_PALT_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H
#define GBSYSTEM_PALT_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H


#include "GB_DataTypeDef.h"

// 更多信息的机能
//#define GB_WG_MOREINFORMATION_FUN 

typedef enum 
{
	e_GB_WG_TIME_Tick = 0,
	e_GB_WG_TIME_Write_Done,
	e_GB_WG_TIME_SMD_forward_releas,
	e_GB_WG_TIME_Count
}GB_WG_E_TIME_ID;
extern GB_VOID GB_WgStartTimer(GB_WG_E_TIME_ID timerid, GB_UINT delay, GB_WG_FuncPtr funcPtr);
extern GB_VOID GB_WgStopTimer(GB_WG_E_TIME_ID timerid);
extern GB_INT GB_WgTimerIsStart(GB_WG_E_TIME_ID timerid);

extern GB_CHAR* GB_WgGetHwVer(GB_VOID);


/////////////////////////////////////////////网络方面的内容
GB_VOID GB_cbm_register_disconnect_notify(GB_U8 app_id);

///////////////////////////////
typedef enum
{
	GBCBM_SIM_ID_SIM1,
		GBCBM_SIM_ID_SIM2,
		GBCBM_SIM_ID_TOTAL
}GBCbm_sim_id_enum;

// BEARER_TYPE
#define GBDATA_ACCOUNT_BEARER_GPRS 0x02
#define GBDATA_ACCOUNT_BEARER_WIFI 0x04

typedef enum
{
    GB_GPRS_DEFAULT=0,
		GB_GPRS_CU,////中国联通
		GB_GPRS_CM,////中国移动
		GB_GPRS_CT   /////中国电信
} GB_gprs_operators_enum;

//////
typedef enum
{
	GBAPN_NONE = 0,
		GBAPN_NET,
		GBAPN_WAP,
		GBMAX_APN
}GBAPN;

//////
typedef enum
{
	GBACCOUNTTYPE_NONE = 0,
		GBACCOUNTTYPE_CMNET = 0x01,
		GBACCOUNTTYPE_CMWAP = 0x02,
		GBACCOUNTTYPE_UNNET = 0x04,
		GBACCOUNTTYPE_UNWAP = 0x08,
		GBMAX_ACCOUNTTYPE	= 4
}GBACCOUNTTYPE;

typedef enum
{
	GB_GPRS_ENABLEACCOUNTTYPE_NOME = 0,
	GB_GPRS_ENABLEACCOUNTTYPE_CU   = 0x01,// 联通账号
	GB_GPRS_ENABLEACCOUNTTYPE_CM   = 0x02,// 移动账号
	GB_GPRS_ENABLEACCOUNTTYPE_CT   = 0x04,// 电信账号
	GB_GPRS_ENABLEACCOUNTTYPE_MAX	
}GB_GPRS_ENABLEACCOUNTTYPE;// 账号可用类型
/* Data Account WLAN bearer status enum */
typedef enum
{
	GB_WLAN_STATUS_NONE			 = 0x00,
	GB_WLAN_STATUS_INACTIVE      = 0x01, /* inactive state */
	GB_WLAN_STATUS_ACTIVE        = 0x02, /* active state */
	GB_WLAN_STATUS_CONNECTED     = 0x04, /* connected state */
	GB_WLAN_STATUS_INVALID_MAC   = 0x08, /* current MAC address isn't valid, OR'd with ACTIVE and CONNECTED status */
	GB_WLAN_STATUS_TOTAL         = 0xFF

} GB_WLAN_STATUS_ENUM;

// 发送状态
typedef enum
{
	GB_SMS_SENDING_FLAT = 1,
	GB_SMS_SEND_DONE,
}GB_SMS_SEND_FLAT_Type;

extern GB_U16 MOD_ID_GB_wg;

extern GB_VOID GB_WgOutput(const GB_CHAR* data);
extern GB_VOID GB_WgOutputW(const GB_CHAR* data);

//////////////////////////////////字符串处理哈

/* ------------------------------------------------- */
typedef enum
{
	SKIN_BLACK = 0,
		SKIN_BLUE,
		SKIN_OUTDOOR,
		SKIN_DREAMWORLD,
		SKIN_NIGHTMODE,
		MAX_SKIN_SETS
};
// 默认皮肤接口
GB_INT GB_WG_GetDefaultSkin(GB_VOID);
/////////////////////////////////皮肤

extern GB_VOID GB_WG_get_time(GB_TIME_STRUCT *t);
extern GB_TIME_STRUCT *GB_WG_get_time_difference(
									GB_TIME_STRUCT *t1,
									GB_TIME_STRUCT *t2,
									GB_TIME_STRUCT *result);
GB_U8 GB_WG_TimeIsValidate(GB_TIME_STRUCT *t);

GB_VOID GB_WG_Decrement_Day(GB_TIME_STRUCT *tNow,GB_INT day,GB_TIME_STRUCT *tReturn);
GB_VOID GB_WG_Decrement_Time(GB_TIME_STRUCT *tNow,GB_INT hour,GB_TIME_STRUCT *tReturn);
//GB_VOID GB_WG_Decrement_Day(GB_TIME_STRUCT *tNow,GB_INT day,GB_TIME_STRUCT *tReturn);
GB_INT  GB_WG_Compare_time(GB_TIME_STRUCT *t1,GB_TIME_STRUCT *t2);
GB_VOID GB_WG_Alter_Hour_Time(GB_TIME_STRUCT *tNow,int hour,GB_TIME_STRUCT *tReturn);
GB_VOID GB_WG_Alter_Day_Time(GB_TIME_STRUCT *tNow,int day,GB_TIME_STRUCT *tReturn);
GB_VOID GB_WG_Alter_Sec_Time(GB_TIME_STRUCT *tNow,int seconds,GB_TIME_STRUCT *tReturn);

//根据时间获取秒数
GB_ULONG GB_WG_Get_Time_To_Sec(GB_TIME_STRUCT *tNow);

/////////////////////////////////////显示
GB_VOID GB_WG_BEGIN_DRAW(GB_VOID);


GB_VOID GB_WG_END_DRAW(GB_VOID);



////////////////////////////////////内存方面的处理
GB_VOID *InitWGMem();

GB_VOID FreeWGMem();


#ifdef GBUSE_ASM_MEM
#define APPMEM_WINGUO_MEM_POLL_SIZE (300*1024)
extern GB_VOID *g_GB_wg_Memory_Pool;
extern KAL_ADM_ID  g_GBwgMemPoolID;
void *GB_WG_MEMORY_MALLOC(GB_ULONG size);
GB_VOID GB_WG_MEMORY_FREE(GB_VOID* p);
#endif



#define  MIN_WINGUO_MEM_SIZE 4*1024 //最少内存

GB_VOID *GB_WG_MALLOC(unsigned long size);
GB_VOID GB_WG_FREE(GB_VOID* p);

GB_VOID GB_WG_SetMallocFun(GB_VOID* mallocFun);
GB_VOID GB_WG_SetFreeFun(GB_VOID* freeFun);
/////////////////////////

extern GB_VOID gbmmi_repot_add_recentcall(GB_U16 *pInputStr);

extern GB_VOID gbmmi_Winguo_Run_Fun(GB_U16 id);

extern GB_VOID GB_WG_Get_SMSDataMsg(GB_U16 *pData, GB_CHAR *pPhoneList[], GB_U16 nPhoneNum);

extern GB_VOID GB_WG_SendMessage(GB_VOID);

extern GB_VOID GB_WG_Save_to_Drafts(GB_VOID);

GB_VOID GB_WG_SynchronousSysDialNum(GB_U16 *pNumber);

// 拨号框系统特殊功能 [3/26/2011 lzp]
GB_VOID GB_WG_DiallingSpecial(GB_U16 *pNumber);

GB_VOID GB_WG_MakeCall_Handle(GB_U16 *pNumber, GB_INT keyValue);

GB_VOID gbmmi_repot_set_active_list(GB_VOID*pUser);

GB_VOID Winguo_Send_MMessage(GB_U16 *sNumber);

//GB_PBOOL gbmmi_repot_search_get_item(GB_VOID *pData, GB_INT item_index, GB_STRTYPE str_buff, GB_PU8 *img_buff_p, GB_U16 *pnPosCount, GB_U16 *pnPos);

//GB_VOID GBMD_Set_Winguo_Active(GB_VOID);

//GB_VOID GBMD_Set_Winguo_UnActive(GB_VOID);

//GB_VOID GBMD_WinGuo_finish(GB_VOID);

//GB_INT GBMD_CleanRecordUseTarget(GB_VOID);

GB_INT GB_SIM_Judge(GB_VOID);

//GB_BOOL GB_WG_CleanRichDataFile(GB_VOID);
//GB_VOID GBMD_CreatEmptyDataFile(GB_VOID);

GB_BOOL GB_WG_Support_C_Key();

GB_BYTE GB_WG_CheckUsbmode(GB_VOID);

GB_BOOL GB_WG_judge_phone_mode(GB_VOID);

GB_INT GB_WG_IsUpdatePhrData(GB_VOID);

GB_VOID gbmmi_repot_load_smd(GB_VOID);

typedef enum  
{
	e_GB_WG_SMD_PHONE_NORMAL, // 正常
	e_GB_WG_SMD_PHONE_WIFI,		// wifi
	e_GB_WG_PHONE_MODE_VAIN,   // 无效卡
	e_GB_WG_PHONE_MODE_NOSIM,  // 无SIM卡
	e_GB_WG_PHONE_MODE_FLIGHT, // 飞行模式
	e_GB_WG_PHONE_MODE_ENCRYPT,  //通讯录加密
	e_GB_WG_PHONE_MODE_USB,    // usb模式
}GB_WG_Phone_Mode;
GB_WG_Phone_Mode GB_WG_Get_Phone_Mode(GB_VOID);

GB_VOID gbmmi_repot_start_read_recentcall(GB_VOID);

GB_WG_LANGUAGE GB_WG_GetCurrentSysLanguage(GB_VOID);

#ifdef __GB_WINGUO_MULTI_LANGUAGE__
GB_INT GB_WG_GetCurrentSysLanguageStr(GB_CHAR* pLanguageStr, GB_INT n);
#endif

GB_VOID GB_WG_IdleDialPadSavePhoneBook(GB_U16 *pSaveNumber);

GB_VOID GB_WG_SetSearchFlag(GB_INT flag);

GB_INT GB_WG_GetSearchFlag(GB_VOID);

GB_VOID GB_WG_Wap_Start_Browser(GB_U16 *GBMD_UrlBuff);

//GB_VOID GB_get_account_req(GB_VOID);

GB_VOID GB_WG_Get_IMEI_REQ(GB_VOID(*fpGetCallback)(GB_CHAR *pstr));

//GB_VOID GB_WG_SetAccount(GB_VOID* dataCenter);

GB_VOID MemReportEx();
GB_VOID MemReportDataEx();

GB_BOOL GB_WG_Decyption_PhoneBook_Password_IsOK(GB_U16*pwd);

GB_BOOL GB_WG_Plat_SupportTouch(GB_VOID);
GB_CHAR* GB_WG_Plat_ScreenSize(GB_VOID);

GB_BOOL GB_WG_Dial_LongPress_Handle(GB_U16 *str,GB_UINT keyValue);
GB_VOID GB_WG_Dial_LongPress_Handle_ext(GB_U16 *str,GB_UINT keyValue);
GB_BOOL GB_WG_Clam_Is_Close();

GB_BOOL GB_WG_GetIsTouchScreen();

// 播放系统提示音
GB_VOID GB_WG_PlayTone(GB_VOID);

// GB_BOOL GB_WG_IsSupportUseSysSms(GB_VOID);
// #if defined(GB_MTK_10APLAT)
// 
// #if defined(__MMI_MMS_STANDALONE_COMPOSER__)
// mmi_ret GB_WG_Sms_Send_Msg_Proc(mmi_event_struct *evt);
// #endif
// 
// GB_VOID GB_WG_Message_10A_SaveToDrafts();
// #endif

//GB_VOID GB_WG_Imc_vk_hide();  // 隐藏系统虚拟键盘接口
/*GB_INT GB_WG_Get_MaxNumberLength();*/

//GB_VOID Winguo_Send_Message(GB_CHAR *sNumber,GB_CHAR* content,GB_WG_OPERATOR opt);
/* ------------------------------------------------- */
typedef enum
{
	E_GB_WG_DIALBOX = 1,
	E_GB_WG_SMD,
	E_GB_WG_ADDRESSBOX,
	E_GB_WG_CONTENTBOX,
	E_GB_WG_WINGUOBOX,
	E_GB_WG_WINGUODATE,
};

#define GB_WG_PARAM_PHONENUMBER		1
#define GB_WG_PARAM_CONTENT			2

typedef struct 
{
	GB_INT selectTag;//添加菜单控件
	GB_CPWSTR pString; //菜单字符串
	GB_INT position;//菜单项添加到原菜单中的位置，从1开始
	GB_WG_MENUFUNC pfun;//菜单处理函数
}GB_WINGUO_Menu_Map;

GB_INT GB_WG_Add_Menu_Fun(GB_WINGUO_Menu_Map *pMenuArry, GB_INT selectType , GB_INT countMax,GB_INT paramType);

GB_VOID GB_WG_Clear_SpecialFlag();

/* ----------------------------------------------------------------- */
// 是否支持wifi
/*GB_BOOL GB_WG_IsSupportWifi(GB_VOID);*/
// 获取wlan的当前状态
GB_WLAN_STATUS_ENUM GB_WG_GetWlanStatus(GB_VOID);

// 设置短信状态
/*GB_VOID GB_WG_SMS_SetSendFlat(GB_SMS_SEND_FLAT_Type sendFlat);*/
// 获取短信状态
/*GB_SMS_SEND_FLAT_Type GB_WG_SMS_GetSendFlat(GB_VOID);*/

/* ----------------------------------------------------------------- */

//  [2/21/2012 获取时间]
GB_U32 GB_WG_GetTime();

#ifdef GB_WINGUO_DEBUGTIME
GB_VOID GBTrace_get_time_print_begin(const GB_CHAR *psz,GB_U32* begin_tick);
GB_VOID GBTrace_get_time_print_end(const GB_CHAR *psz,GB_U32* begin_tick,GB_U32* end_tick);
#endif

GB_VOID GBTrace_print(const GB_CHAR *psz,...);

//  [6/2/2012 liangchuanhui]
GB_VOID GB_WG_Set_isVirtual_key(GB_BOOL isVirtual);
GB_BOOL GB_WG_Get_isVirtual_key(GB_VOID);

#endif

