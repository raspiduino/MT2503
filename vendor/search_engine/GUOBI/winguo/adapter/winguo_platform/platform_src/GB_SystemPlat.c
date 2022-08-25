
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE


#include "MMI_include.h"
#include "Abm_api.h"

#include "abm_soc_enums.h"
#include "cbm_api.h"
#include "custom_data_account.h"
//  [7/29/2011 lzp]#include "DataAccountCommon.h"
//  [7/29/2011 lzp]#include#include "DataAccountStruct.h"
#include "mmi_rp_app_gb_winguo_def.h"
#include "GB_WG_MTKPlatver.h"
#include "GB_SystemPlat.h"

#include "ImeiSrvGprot.h"

//begin modify by zhangchenglong
#ifdef __COSMOS_MMI_PACKAGE__
#include "vcui_phb_gprot.h "//保存号码  [8/31/2011 liangchuanhui]
#endif
//end modify by zhangchenglong
#ifdef GB_MTK_09APLAT
#include "PhoneSetupGprots.h"
#include "PhoneBookGprot.h"
#include "PhoneBookResDef.h"
#endif

#ifdef GB_MTK_09BPLAT
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#endif


#include "CallLogSrvGprot.h"


//  [7/29/2011 lzp]#include#include "Mtpnp_pfal_master_def.h"
//  [7/29/2011 lzp]#include#include "Mtpnp_ad_master_common_def.h"
//  [7/29/2011 lzp]#include#include "mtpnp_ad_master_if.h"

//  [7/29/2011 lzp]#include#include "mtpnp_pfal_cc.h"

//#include "SmsAppGprot.h"

//#include "IndicRuleEngine.h"


#include "GB_WG_Public.h"
#include "GB_WG_SystemInc.h"


#if defined(GB_MTK_10APLAT)
#include "SmsCuiGprot.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "wapadp.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif 
#include "UcSrvGprot.h"
#include "UcAppGprot.h"
//#include "UcAppProt.h"
#endif
// static MMI_BOOL wgmsg_flag = MMI_FALSE; // 用于区分winguo短信和系统短信的标志位
// extern mmi_uc_context_struct g_uc_cntx; /* global context of uc */
// extern mmi_uc_context_struct *g_uc_p;
// //  [4/12/2011 tangpeng modify for WG Msg end]

#ifdef GB_MTK_10APLAT
#include "NwInfoSrvGprot.h"
//#include "mmi_rp_app_unifiedcomposer_def.h"
#endif



#endif
////////////////////////消息层处理
////////////////////////////////网络系统

////////////////////////////////////////////////////////////////////////
// mass storage mod
////////////////////////////////////////////////////////////////////////
// 屏幕进入设为1，物理键盘进入设置为0，代替宏GBWG_VIRTUAL_KEY [6/2/2012 liangchuanhui]
static GB_BOOL g_gbwg_virtual_key = 1;
GB_VOID GB_WG_Set_isVirtual_key(GB_BOOL isVirtual)
{
	g_gbwg_virtual_key = isVirtual;
}

GB_BOOL GB_WG_Get_isVirtual_key(GB_VOID)
{
	return g_gbwg_virtual_key;
}

GB_BYTE GB_WG_CheckUsbmode(GB_VOID)
{
#ifdef __USB_IN_NORMAL_MODE__
	#ifdef __COSMOS_MMI_PACKAGE__
	if (mmi_usb_is_in_mass_storage_mode())
	#else
	if(srv_usb_is_in_mass_storage_mode())//modify by zhangchenglong
	#endif
	{ 
		return 1; 
	} 
#endif /* __USB_IN_NORMAL_MODE__ */ 
	return 0;
}

GB_BOOL GB_WG_Support_C_Key()
{
#ifdef __MMI_WITH_C_KEY__
	return GB_TRUE;
#else
	return GB_FALSE;
#endif
}

GB_BOOL is_virtualkey = GB_FALSE;

GB_VOID GB_WG_Set_Is_VirtualKey(GB_BOOL flag)
{
	is_virtualkey = flag;
}

GB_BOOL GB_WG_Get_Is_VirtualKey()
{
	return is_virtualkey;
}

GB_BOOL GB_WG_IS_Support_VirtualKeyboard()
{
	//  [6/2/2012 liangchuanhui]
	if (GB_WG_Get_isVirtual_key())
	{
		return GB_TRUE;
	}
	else
	{
		return GB_FALSE;
	}
// #ifdef GBWG_VIRTUAL_KEY
// 	return GB_TRUE;
// #else
// 	return GB_FALSE;
// #endif
}

static GB_VOID GB_force_disc(U32 result)
{
}
GB_VOID GB_cbm_register_disconnect_notify(GB_U8 app_id)
{
#if !defined(GB_MTK_10APLAT)
extern GB_INT mmi_cbm_register_disconnect_notify(GB_U8 app_id, FuncPtrCMBearerDisc callback);
	mmi_cbm_register_disconnect_notify(app_id,GB_force_disc);
#endif
}
//////////////////////////////////////////////////

#include"GB_HWPlat.h"
///////////////////////////////////////////////
extern  GDI_RESULT gdi_layer_get_base_handle(gdi_handle *handle_ptr);
extern  GB_VOID gdi_layer_set_active(gdi_handle handle);
//extern  GB_VOID gdi_layer_lock_frame_buffer(GB_VOID);

extern  GDI_RESULT gdi_layer_set_source_key(BOOL source_key_enable, gdi_color source_key_value);
extern  GB_VOID gdi_layer_set_clip(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2);
extern gd_color_from_rgb_func gdi_act_color_from_rgb;

//extern GB_VOID gdi_layer_unlock_frame_buffer(GB_VOID);

void GB_WG_BEGIN_DRAW(GB_VOID)
{
	GDI_HANDLE handle;
	gdi_layer_get_base_handle(&handle);
	gdi_layer_set_active(handle); 
	gdi_layer_lock_frame_buffer(); 
	GB_WG_PUSH_CLIP;
	gb_wg_gui_set_clip(0,0,GB_WG_GetScrW(),GB_WG_GetScrH()); 
	gdi_layer_set_source_key(TRUE, gdi_act_color_from_rgb(255,255,0,255));
}

GB_VOID GB_WG_END_DRAW(GB_VOID)
{
	GDI_HANDLE handle;
	gdi_layer_get_base_handle(&handle);
	GB_WG_POP_CLIP;
	gdi_layer_unlock_frame_buffer();
//	gdi_layer_blt(handle,0,0,0,0,0,GB_WG_GetScrW(),GB_WG_GetScrH());
	gb_wg_gui_BLT_double_buffer(0, 0, GB_WG_GetScrW(),GB_WG_GetScrH());
}	



GB_VOID GB_WG_SendMsg(GB_U16 id,GB_VOID* local_param_ptr)
{	
	MYQUEUE Message;
	
	Message.oslSrcId	=	MOD_MMI;
	Message.oslDestId	=	MOD_MMI;
	Message.oslMsgId	=	id;
	Message.oslDataPtr = (oslParaType *)local_param_ptr;
	Message.oslPeerBuffPtr = NULL;
	OslMsgSendExtQueue(&Message);
}

GB_VOID GB_WG_get_time(GB_TIME_STRUCT *t)
{
	applib_dt_get_date_time((applib_time_struct *)t);
}
extern GB_TIME_STRUCT *GB_WG_get_time_difference(
									GB_TIME_STRUCT *t1,
									GB_TIME_STRUCT *t2,
									GB_TIME_STRUCT *result)
{
	return (GB_TIME_STRUCT*)applib_get_time_difference((applib_time_struct*)t1, 
										(applib_time_struct*)t2, 
										(applib_time_struct*)result);
}

GB_U8 GB_WG_TimeIsValidate(GB_TIME_STRUCT *t){
	if(t->nYear==0)return 0;
	return 1;
}

GB_VOID GB_WG_Decrement_Time(GB_TIME_STRUCT *tNow,GB_INT hour,GB_TIME_STRUCT *tReturn){
	GB_TIME_STRUCT time ={0};
	if(hour<0){
		time.nHour=(kal_uint8)hour;
		applib_dt_increase_time((applib_time_struct*)&tNow, (applib_time_struct*)&time, (applib_time_struct*)tReturn);
	}else{
		time.nHour=(kal_uint8)(0-hour);
		applib_dt_decrease_time((applib_time_struct*)&tNow, (applib_time_struct*)&time, (applib_time_struct*)tReturn);
	}
}
GB_VOID GB_WG_Decrement_Day(GB_TIME_STRUCT *tNow,GB_INT day,GB_TIME_STRUCT *tReturn){
	GB_TIME_STRUCT time ={0};
	if(day<0){
		time.nDay=(kal_uint8)day;
		applib_dt_increase_time((applib_time_struct*)&tNow, (applib_time_struct*)&time, (applib_time_struct*)tReturn);
	}else{
		time.nDay=(kal_uint8)(0-day);
		applib_dt_decrease_time((applib_time_struct*)&tNow, (applib_time_struct*)&time, (applib_time_struct*)tReturn);
	}
}

GB_INT  GB_WG_Compare_time(GB_TIME_STRUCT *t1,GB_TIME_STRUCT *t2){
	 return applib_dt_compare_time((applib_time_struct*)t1,(applib_time_struct*)t2,NULL);	 
}

GB_VOID GB_WG_Alter_Hour_Time(GB_TIME_STRUCT *tNow,GB_INT hour,GB_TIME_STRUCT *tReturn)
{
	if (tNow && tReturn)
	{
		applib_time_struct time ={0};
		if(hour<0){
			time.nHour=(kal_uint8)(0-hour);
			applib_dt_decrease_time((applib_time_struct*)tNow,&time,(applib_time_struct*)tReturn);
		}else{
			time.nHour=(kal_uint8)hour;
			applib_dt_increase_time((applib_time_struct*)tNow,&time,(applib_time_struct*)tReturn);
		}
	}
}
GB_VOID GB_WG_Alter_Day_Time(GB_TIME_STRUCT *tNow,GB_INT day,GB_TIME_STRUCT *tReturn)
{
	if (tNow && tReturn)
	{
		applib_time_struct time ={0};
		if(day<0){
			time.nDay=(kal_uint8)(0-day);
			applib_dt_decrease_time((applib_time_struct*)tNow, &time, (applib_time_struct*)tReturn);
		}else{
			time.nDay=(kal_uint8)day;
			applib_dt_increase_time((applib_time_struct*)tNow, &time, (applib_time_struct*)tReturn);
		}
	}
}

GB_BOOL GB_WG_TransformSecTorTimestruct(GB_TIME_STRUCT* timeStruct,GB_INT seconds)
{
	GB_BOOL ret = GB_FALSE;

	if (timeStruct && seconds > 0)
	{
		GB_INT tempSec = GB_ABS(seconds);

		timeStruct->nSec = seconds > 0 ? tempSec % 60 : -(tempSec % 60);

		tempSec -= timeStruct->nSec;

		if (tempSec <= 0)
		{
			goto END;
		}

		timeStruct->nMin = seconds > 0 ? (tempSec / 60 ) % 60 : -((tempSec / 60 ) % 60);

		tempSec -= timeStruct->nMin * 60;

		if (tempSec <= 0)
		{
			goto END;
		}

		timeStruct->nHour= seconds > 0 ? (tempSec / 3600) % 24 : -((tempSec / 3600) % 24);

		tempSec -= timeStruct->nHour * 3600;
			
		if (tempSec <= 0)
		{
			goto END;
		}
		
		timeStruct->nDay = seconds > 0 ? tempSec / (3600 * 24) : -(tempSec / (3600 * 24));
END:
		ret = GB_TRUE;
	}

	return ret;
}

GB_VOID GB_WG_Alter_Sec_Time(GB_TIME_STRUCT *tNow,GB_INT seconds,GB_TIME_STRUCT *tReturn)
{
	if (tNow && tReturn)
	{
		
		GB_ULONG temp_utc = applib_dt_mytime_2_utc_sec((applib_time_struct*)tNow,GB_FALSE);

		temp_utc += seconds;
		 
		applib_dt_utc_sec_2_mytime(temp_utc,(applib_time_struct*)tReturn,GB_FALSE);
//		applib_time_struct time ={0};
// 		if (GB_ABS(seconds) > 60)
// 		{
// 			// 转换为time
// 			GB_WG_TransformSecTorTimestruct((GB_TIME_STRUCT*)&time,seconds);
// 		}
// 		else
// 		{
// 			if(seconds<0){
// 				time.nSec=(kal_uint8)(0-seconds);
// 			}else{
// 				time.nSec=(kal_uint8)seconds;
// 			}	
// 		}
// 		if(seconds<0){
// 			applib_dt_decrease_time((applib_time_struct*)tNow, &time, (applib_time_struct*)tReturn);
// 		}else{
// 			applib_dt_increase_time((applib_time_struct*)tNow, &time, (applib_time_struct*)tReturn);
// 		}
	}
}

//根据时间获取秒数
GB_ULONG GB_WG_Get_Time_To_Sec(GB_TIME_STRUCT *tNow)
{
	GB_ULONG temp_utc = 0;
	temp_utc = applib_dt_mytime_2_utc_sec((applib_time_struct*)tNow,GB_FALSE);
	return temp_utc;
}

//change get IMEI and IMSI API

GB_INT GB_WG_GetIMEI(GB_CHAR *pIMEI, GB_UINT nBuffLen)
{
	srv_imei_get_imei(MMI_SIM1, pIMEI, nBuffLen);
	return 1;
}

GB_INT GB_WG_GetIMSI(GB_CHAR *pIMSI, GB_UINT nBuffLen)
{
	GB_INT ret = MMI_FALSE;
    #ifdef __MMI_TELEPHONY_SUPPORT__    
	ret = srv_sim_ctrl_get_imsi(MMI_SIM1, pIMSI, nBuffLen);
    #endif/*__MMI_TELEPHONY_SUPPORT__ */  

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
        #endif/*__MMI_TELEPHONY_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
#endif
	return ret;
}


//内存管理方面

GB_VOID *InitWGMem(){
	

	return NULL;
}

GB_VOID FreeWGMem(){

}

///////////////////////////
#ifdef GBUSE_ASM_MEM
GB_VOID *g_GB_wg_Memory_Pool = NULL;
KAL_ADM_ID  g_GBwgMemPoolID = 0;

void *GB_WG_MEMORY_MALLOC(GB_ULONG size)
{
	if(size>0)
	{
 		return (void*)kal_adm_alloc(g_GBwgMemPoolID,size);
	}
	return NULL;
}

GB_VOID GB_WG_MEMORY_FREE(GB_VOID* p)
{
	if(p!=0 && g_GBwgMemPoolID)
	{
		kal_adm_free(g_GBwgMemPoolID,p);
	}
}
#endif /* #ifdef GBUSE_ASM_MEM*/
/////////////////////////////////
#if defined(GBUSE_MEDIA_MEM)
#include "med_smalloc.h"
#endif

///////////////////////////////////////////


/************************************************************************************************/
/*                         按键处理                                                             */
/************************************************************************************************/
extern void IdleDialPadSavePhoneBook(void);
#ifdef GB_MTK_09BPLAT
extern void mmi_idle_dialer_handle_center_key(void);
#else
extern void IdleDialPadCall(void);
#endif
extern void EntryScrEmergencyCallDialing(void);


/**********************************************************************
* 函数名称： GB_WG_judge_phone_mode
* 功能描述： 判断是否为飞行模式
* 输入参数： 无
* 输出参数：模式
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                       20100817                      创建
***********************************************************************/
GB_BOOL GB_WG_judge_phone_mode(GB_VOID)
{
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#if defined(GB_MTK_10APLAT)
    #ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif/*__MMI_TELEPHONY_SUPPORT__ */ 
#else
/* under construction !*/
/* under construction !*/
#endif
#endif	
#ifdef __MMI_WLAN_FEATURES__
	// wifi
	if (GB_WLAN_STATUS_CONNECTED == GB_WG_GetWlanStatus())
	{
		return TRUE;
	}
	else
#endif
	if(
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
		mmi_bootup_is_sim_valid() == MMI_TRUE
#endif
		)
	{	
#ifdef __MMI_DUAL_SIM_MASTER__
#if defined(GB_MTK_10APLAT)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#if defined(GB_MTK_10APLAT)
        #ifdef __MMI_TELEPHONY_SUPPORT__
		if(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
        #else
        if(0)
        #endif/*__MMI_TELEPHONY_SUPPORT__ */ 
#else
		if(g_pwr_context.CurrentServiceType == FULL_SERVICE)
#endif
		{
			return TRUE;
		}
#endif
	}
	else
	{
		return FALSE;
	}
	
	return FALSE;
}

GB_BOOL GB_WG_GetIsTouchScreen()
{
#ifdef __MMI_TOUCH_SCREEN__ 
	return GB_TRUE;
#endif
	return GB_FALSE;
}
//begin modify by zhangchenglong
#if defined(__COSMOS_MMI_PACKAGE__) && !defined(GB_MTK_11B6255)
//#include "SimDetectionDef.h"	 //add by yyk
#endif
//  [7/29/2011 lzp]#include "SSCStringHandle.h"
#if defined(GB_MTK_10APLAT)
#else
extern pwr_context_struct g_pwr_context;
#endif
//end modify by zhangchenglong


GB_VOID GB_WG_SynchronousSysDialNum(GB_U16 *pNumber)
{
// 	GB_INT len;
// 	GB_MEMSET(g_idle_context.DialPadCallBuffer, 0, sizeof(g_idle_context.DialPadCallBuffer));
// 	if (pNumber)
// 	{
// 		len = gb_wg_wcslen(pNumber);
// 		len = GB_MIN(len, sizeof(g_idle_context.DialPadCallBuffer)/sizeof(GB_U16) - 1);
// 		gb_wg_wcsncpy((GB_U16 *)g_idle_context.DialPadCallBuffer, pNumber, len);
// 	}
}

GB_BOOL GB_WG_Is_DiallingSpecial_Handle(GB_U16 *pNumber)
{
	if (pNumber)
	{
		GB_INT len = 0;
		len = gb_wg_wcslen(pNumber);
		if (pNumber[len-1]=='#')
		{
			return GB_TRUE;
		}
	}
	return GB_FALSE;
}
GB_BOOL GB_WG_Is_Ssc_Handle(GB_WCHAR* pNumber)
{
	if ((pNumber[0] >= '0') && (pNumber[0] <= '9'))
	{
		return GB_FALSE;
	}
	return GB_TRUE;
}

GB_BOOL GB_WG_Is_SimEntry_Handle()
{
// 	GB_U8 count = 0;
// 	while (g_idle_context.DialPadCallBuffer[count]!='\0')
// 	{
// 		if(g_idle_context.DialPadCallBuffer[count]=='#')
// 		{
// 			return GB_TRUE;
// 		}
// 		count++;
// 	}
	return GB_FALSE;
}
GB_BOOL GB_WG_Get_PhbIndex(GB_U16 *pNumber, GB_U16*index)
{
	GB_U16 tempbuffer[20] = {0};
	GB_U8 count, i = 0;

	for (count = 0; pNumber[count] != '#' && pNumber[count] ; count++)
	{
		if (count >= (sizeof(tempbuffer)/sizeof(tempbuffer[0]) - 1) ||
			pNumber[count] == '*' ||
			pNumber[count] == '+' ||
			pNumber[count] == 'p' ||
			pNumber[count] == 'w')
		{
			return GB_FALSE;
		}
		tempbuffer[i] = pNumber[count];
		i++;
	}
	*index = (GB_U16) gui_atoi((GB_U16*) tempbuffer);
	return GB_TRUE;
}

/**********************************************************************
* 函数名称： GB_WG_DiallingSpecial
* 功能描述： 拨号框特殊功能处理接口
* 输入参数： pNumber：拨号框中输入字符串；
* 返 回 值： 
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
lenny           20110705						创建
***********************************************************************/
#ifndef __COSMOS_MMI_PACKAGE__
extern U8 mmi_phb_get_sim_entry_by_location(U16 entryNum);
#endif

GB_VOID GB_WG_DiallingSpecial(GB_U16 *pNumber)
{
	//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
	if (!GB_WG_Get_isVirtual_key())
	{
#ifndef __COSMOS_MMI_PACKAGE__
		GB_BOOL result = GB_FALSE;
		if (GB_WG_Is_DiallingSpecial_Handle(pNumber))
		{
			if (GB_WG_Is_Ssc_Handle(pNumber))
			{
                #ifdef __MMI_TELEPHONY_SUPPORT__
				if (!mmi_ssc_sim_string_pass(pNumber))
				{
					mmi_ssc_phone_string_pass(pNumber);
					result = GB_TRUE;
				}             
                #endif/*__MMI_TELEPHONY_SUPPORT__ */ 
			}
			else
			{
				GB_U16 index = 0;
				GB_BOOL ret = GB_WG_Get_PhbIndex(pNumber, &index);
				if (ret)
				{
					result = mmi_phb_get_sim_entry_by_location(index); 
				}
			}
			if (!GB_WG_Is_In_Winguo())
			{
				mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);//DeleteScreenIfPresent(SCR_GB_WINGUO_SCREEN);
			}
		}
#endif

	}

	
//#endif
}
// 下面是选择发送卡相关函数
/**********************************************************************
* 函数名称： GB_WG_SMS_SelectSIMOKHdlr、GB_WG_SMS_SelectSIMHighlightHdlr、
GB_WG_SMS_SelectSendSIMScreen、GB_WG_mmi_uc_pre_entry_sim_option_csk
* 功能描述： 短信发送选卡页面操作
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
liangchuanhui         20110919                       创建
***********************************************************************/
//#include"GB_Data_Account.h"
// data account select type
typedef enum
{
	GB_DTCNT_SELECT_NONE = 0x00,
	GB_DTCNT_SELECT_SIM1 = 0x01,
	GB_DTCNT_SELECT_SIM2 = 0x02,
	GB_DTCNT_SELECT_WIFI = 0x04,
	// TODO: 添加其它BEAR类型
	GB_DTCNT_SELECT_SIM  = GB_DTCNT_SELECT_SIM1|GB_DTCNT_SELECT_SIM2|GB_DTCNT_SELECT_WIFI,
	// TODO: 添加其它BEAR类型
	GB_DTCNT_SELECT_MAX
}GB_DTCNT_Select_Type;

#include "UcmGProt.h"//打电话 liangchuanhui 20110822 
static GB_U16 GB_WG_G_Number[SRV_UCM_MAX_NUM_URI_LEN+1];
static mmi_ucm_make_call_para_struct make_call_para;
void GB_WG_SelectSIMOKHdlr(void)
{	
	
//	GoBackHistory();


	
    if(gb_wg_wcslen(GB_WG_G_Number)>0)
	{
		make_call_para.ucs2_num_uri = (U16*)GB_WG_G_Number;
	}
	mmi_ucm_call_launch(0, &make_call_para);

//	DeleteHistory(SCR_GB_WINGUO_SELECT_SIM, 1, 1, SCR_GB_WINGUO_SELECT_SIM, 1);
// 	GB_WG_SMS_SendMessageReq();
// 	GB_WG_ShowSmsTip(GB_WG_SMS_SENDING);
}

void GB_WG_SelectSIMHighlightHdlr(S32 index)
{
	mmi_ucm_init_call_para(&make_call_para);

	if(0 == index)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
	}
	else if(1 == index)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
	}

	SetLeftSoftkeyFunction(GB_WG_SelectSIMOKHdlr, KEY_EVENT_UP);
	SetKeyHandler(GB_WG_SelectSIMOKHdlr, KEY_ENTER, KEY_EVENT_UP);

}

/**********************************************************************
* 函数名称： GB_GetSMSSelectSIMItems
* 功能描述： 提示用户显示A B 卡
***********************************************************************/
#define GB_SIM_NAME_LENGTH		(8)
#define GB_SIM_NAME_DIMENSION	(2)
#define GB_WG_SIM_COUNT	(2)
unsigned short GB_WG_SIM_NAME[GB_SIM_NAME_DIMENSION][GB_SIM_NAME_LENGTH] = {0};

pBOOL GB_GetCallSelectSIMItems(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, GB_U8 str_img_mask)
{
	unsigned short* type_a = GB_NULL;
    unsigned short* type_b = GB_NULL;


	// TODO: 添加其它BEAR类型

	GB_USHORT* szName = GB_NULL;
	GB_INT nBearCount = GB_WG_SIM_COUNT;

	type_a = (unsigned short*)get_string(STR_GB_WINGUO_SIM1);//sim卡1

	type_b = (unsigned short*)get_string(STR_GB_WINGUO_SIM2);//sim卡2

	*img_buff_p = NULL;
	UI_UNUSED_PARAMETER(str_img_mask);

	if (item_index > (nBearCount - 1) || item_index < GB_DTCNT_SELECT_NONE)
	{
		return FALSE;
	}

	if(0 == item_index)
	{
		szName = type_a;
	}
	else if(1 == item_index)
	{
		szName = type_b;
	}

	if(0 == item_index)
	{
		*img_buff_p = (PU8)GetImage(IMG_GLOBAL_L1);
	}
	else if(1 == item_index)
	{
		*img_buff_p = (PU8)GetImage(IMG_GLOBAL_L2);
	}

	memset(GB_WG_SIM_NAME[item_index], 0, sizeof(GB_WG_SIM_NAME[item_index]));
	mmi_ucs2cat((S8*)GB_WG_SIM_NAME[item_index], (PS8)szName);

	mmi_ucs2cpy((S8*)str_buff, (S8*)GB_WG_SIM_NAME[item_index]);

	return GB_TRUE;
}
void GB_WG_CancelCallSelectSim(void)
{
	//GB_WG_G_Info_Free(); // 先释放开辟的信息内存
	GoBackHistory();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__COSMOS_MMI_PACKAGE__) //&& defined(GB_MTK_11B6255) // by yyk
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

GB_VOID GB_WG_SelectSendSIMScreen(GB_VOID)
{
	GB_U8 *guiBuffer;
	U16 title[] = {0x0000};
	S32 count = GB_WG_SIM_COUNT;

	//count = GB_GetBearCount(GB_TRUE);

	if(!mmi_frm_scrn_enter(GRP_GB_WINGUO_SCREEN,SCR_GB_WINGUO_SELECT_SIM,GB_NULL,GB_WG_SelectSendSIMScreen,MMI_FRM_FULL_SCRN))
	{
		return;
	}
	mmi_frm_scrn_clear_attribute(GRP_GB_WINGUO_SCREEN,SCR_GB_WINGUO_SELECT_SIM,MMI_SCRN_ATTRIB_ADD_HISTORY);
	guiBuffer = mmi_frm_scrn_get_active_gui_buf();

	RegisterHighlightHandler(GB_WG_SelectSIMHighlightHdlr);

	ShowCategory183Screen(
		(UI_string_type)title,
		NULL,
		(UI_string_type)get_string(STR_GLOBAL_OK),
		(PU8)get_image(IMG_GLOBAL_OK),
		(UI_string_type)get_string(STR_GLOBAL_BACK),
		(PU8)get_image(IMG_GLOBAL_BACK),
		count,
		GB_GetCallSelectSIMItems,
		NULL,
		0,
		GB_FALSE,
		UI_dummy_function,
		guiBuffer);

	SetRightSoftkeyFunction(GB_WG_CancelCallSelectSim, KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


GB_VOID GB_WG_MakeCall_Handle(GB_U16 *pNumber, GB_INT keyValue)
{
 	mmi_ucm_make_call_para_struct make_call_para;
// 	GB_U16 tempNumber[SRV_UCM_MAX_NUM_URI_LEN] = {0};

	//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
	if (!GB_WG_Get_isVirtual_key())
	{
		if (mmi_ssc_lauguage_string_pass(pNumber))
		{
			return ;
		}
	}
//#endif	
 	mmi_ucm_init_call_para(&make_call_para);
	make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
	memset(GB_WG_G_Number,0,sizeof(GB_WG_G_Number));
    //39个数字才能打
	if (gb_wg_wcslen(pNumber)>SRV_UCM_MAX_NUM_URI_LEN-1)
	{
		gb_wg_wcsncpy(GB_WG_G_Number,pNumber,SRV_UCM_MAX_NUM_URI_LEN-1);
	}
	else if(gb_wg_wcslen(pNumber)>0)
	{
		gb_wg_wcsncpy(GB_WG_G_Number,pNumber,gb_wg_wcslen(pNumber));

	}
	//GB_WG_SelectSendSIMScreen();//测试选卡
	make_call_para.ucs2_num_uri = (U16*)GB_WG_G_Number;

	if (GB_WG_KEY_SEND1 == keyValue)
	{
		 make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
	}
	else if(GB_WG_KEY_SEND2 == keyValue)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
	}
#if !defined(__COSMOS_MMI_PACKAGE__)
	mmi_ucm_call_launch(0, &make_call_para);
#else
	else if (GB_WG_KEY_SEND == keyValue)
	{
		mmi_sim_enum sim_type = srv_setting_get_primary_card();

        if (srv_nw_usab_is_usable(MMI_SIM1) && srv_nw_usab_is_usable(MMI_SIM2))
        {		
			GB_WG_SelectSendSIMScreen();
// 			if (sim_type == MMI_SIM1)//srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
// 			{
// 				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
// 			}
// 			else if (sim_type == MMI_SIM2)//srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
// 			{
// 				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
// 			}
// 			else
// 			{
// 				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
// 			}
        }
		else if(srv_nw_usab_is_usable(MMI_SIM1) || srv_nw_usab_is_usable(MMI_SIM2))
		{
			if (srv_nw_usab_is_usable(MMI_SIM1))
			{
				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
			}
			else if (srv_nw_usab_is_usable(MMI_SIM2))
			{
				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
			}
			else
			{
				make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
			}	

			make_call_para.ucs2_num_uri = (U16*)GB_WG_G_Number;
			mmi_ucm_call_launch(0, &make_call_para);
		}
	}
#endif
 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_DUAL_SIM_MASTER__		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
/* under construction !*/
#else
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
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
/* under construction !*/
		#else
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(GB_MTK_09BPLAT) || defined(GB_MTK_10APLAT)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
}

#ifndef  __COSMOS_MMI_PACKAGE__
#if defined(GB_MTK_10APLAT) || defined(GB_MTK_09BPLAT)
#include "phbcuigprot.h"

static mmi_ret GB_WG_dialer_do_save_contact_evt_hdlr(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	cui_phb_save_contact_result_struct *evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(event);

	evt = (cui_phb_save_contact_result_struct *)event;

	switch (evt->evt_id)
	{
	case EVT_ID_PHB_SAVE_CONTACT:   /* fall-throught */
	case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
		cui_phb_save_contact_close(evt->sender_id);
		break;

	default:
		break;
	}

	return MMI_RET_OK;
}
#endif
#endif //test scf 20120424


//extern mmi_ret vfxSetCuiCallerScr(mmi_id cuiId, GB_WCHAR* scr);

static mmi_ret GB_WG_SavePhoneBook_proc(mmi_event_struct *evt)
{
//begin modify by zhangchenglong
#ifdef __COSMOS_MMI_PACKAGE__
	switch (evt->evt_id)
	{
	case EVT_ID_CUI_PHB_SAVE_RESULT:
		{
			vcui_phb_contact_saver_close(((vcui_phb_contact_save_result_event_struct*) evt)->sender_id);
			return MMI_RET_OK;
		}
	default:
		break;
	}
#endif
//end modify by zhangchenglong

return MMI_RET_DONT_CARE;
}
GB_VOID GB_WG_IdleDialPadSavePhoneBook(GB_U16 *pSaveNumber)
{
	if (pSaveNumber==GB_NULL)
	{
		return;
	}
	else
	{
//begin modify by zhangchenglong
#ifdef __COSMOS_MMI_PACKAGE__
 		mmi_id cui_id = vcui_phb_contact_saver_create(mmi_frm_group_get_active_id());
 		if (cui_id == GRP_ID_INVALID)
 		{
 			return;
 		}
 		mmi_frm_group_set_caller_proc(cui_id, GB_WG_SavePhoneBook_proc, NULL);
 		//vfxSetCuiCallerScr(cui_id, m_scr);
 		vcui_phb_contact_saver_set_number(cui_id, pSaveNumber, mmi_wcslen(pSaveNumber));
 		vcui_phb_contact_saver_run(cui_id);
#else


//下面先不用，测试一下保存号码liangchuanhui 20110822
#if defined(GB_MTK_10APLAT)|| defined(GB_MTK_09BPLAT)
	mmi_id parent_gid, child_gid;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	parent_gid = mmi_frm_group_create(
		//GRP_ID_ROOT,
		mmi_frm_group_get_active_id(),
		GRP_ID_AUTO_GEN,
		GB_WG_dialer_do_save_contact_evt_hdlr,
		NULL);

	mmi_frm_group_enter(parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	//parent_gid = mmi_frm_group_get_active_id();

	child_gid = cui_phb_save_contact_create(parent_gid);

	if (child_gid == GRP_ID_INVALID)
	{
		return;
	}
	cui_phb_save_contact_set_number(child_gid, pSaveNumber);
	cui_phb_save_contact_run(child_gid);
//#elif defined(GB_MTK_09BPLAT) 
//	IdleDialPadSavePhoneBook();
#else
#ifdef __MMI_VOIP__
    if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR)) 
    {        
        if (mmi_ucs2strlen((S8*)pSaveNumber))
        {
            mmi_phb_save_entry_for_service_field(NULL, (S8*)pSaveNumber, MMI_PHB_ENTER_FROM_VOIP);
        }
        else
        {
            mmi_display_popup(
                get_string(STR_ID_VOIP_EMPTY_USERNAME), 
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID); 
        }        
    }
    else
#endif 
    {
        SaveNumberFromIdleScrn((S8*)pSaveNumber, 0);
    }    
#endif

#endif
//end modify by zhangchenglong
	}

}


#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
#include "MessagesMiscell.h"
#include "GlobalDefs.h"
#include "mms_api.h"
//#include "SettingProfileEnum.h"
#include "CommonScreens.h"

//////////////////////////测试 彩信 liangchuanhui 20110818
// #include "vfx_page.h "
// #include "vfx_app.h "
//#include "vfx_app_scr.h"
//#include "vfx_app.h"
//
//begin modify by zhangchenglong
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_uc_gprot.h"
#else
#ifdef __MMI_MMS_2__
#include "mmi_rp_app_umms_mms_def.h"	
#endif
#endif

#ifdef __COSMOS_MMI_PACKAGE__
//在11A的COSMOS_MMI情况下，短信和彩信都走这个接口
GB_VOID Winguo_Send_COSMOS_MMessage(GB_U16 *sNumber)
{
	GB_U16 number[40+1];
       GB_UINT name_length = 0;
	VappUcEntryStruct ucEntry;
 	mmi_id cuiId;
	srv_uc_addr_struct addr;
	if (!sNumber)
	{
		return;
	}

	//ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

	// set uc type
	memset(&ucEntry, 0, sizeof(VappUcEntryStruct));
	ucEntry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
	ucEntry.type = SRV_UC_STATE_WRITE_NEW_MSG;


	GB_MEMSET(number, 0, sizeof(number));
	mmi_wcsncpy(number, sNumber, sizeof(number)/sizeof(number[0])-1);
		// set address
	if (0 != mmi_wcslen(number) && GB_WG_String_IsNumSymbol(number))
	{		
		addr.next = NULL;
		addr.previous = NULL;
		addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
		addr.addr = (kal_uint8*)number;
		addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
		ucEntry.addr_num = 1;
		ucEntry.addr = &addr;

	}
	else
	{
		ucEntry.text_buffer = (U8*)number;
		ucEntry.text_num = mmi_ucs2strlen((S8*)number);
	}


// 	cuiId = vcui_unifiedcomposer_create(mmi_frm_group_get_active_id(),&ucEntry);
// 	if (cuiId != GRP_ID_INVALID)
// 	{
// 		//vfxSetCuiCallerScr(cuiId, getMainScr());
// 		vcui_unifiedcomposer_run(cuiId);
// 	}
       vappUcAppLauncher(&ucEntry);	
}

//在11A的COSMOS_MMI情况下，短信和彩信都走这个接口
GB_VOID Winguo_Send_COSMOS_BusinessCard(GB_U16 *businessCard)
{
	/*GB_U16 number[40+1];*///在分享页面输入很多内容时点击发送短信发现截取问题 [scf 20120514]
       GB_UINT name_length = 0;
	VappUcEntryStruct ucEntry;
 	mmi_id cuiId;
	srv_uc_addr_struct addr;
	if (!businessCard)
	{
		return;
	}

	//ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

	// set uc type
	memset(&ucEntry, 0, sizeof(VappUcEntryStruct));
	ucEntry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
	ucEntry.type = SRV_UC_STATE_WRITE_NEW_MSG;


// 	GB_MEMSET(number, 0, sizeof(number));
// 	mmi_wcsncpy(number, businessCard, sizeof(number)/sizeof(number[0])-1);
		// set address

// 	ucEntry.text_buffer = (U8*)number;
// 	ucEntry.text_num = mmi_ucs2strlen((S8*)number);

	ucEntry.text_buffer = (U8*)businessCard;
	ucEntry.text_num = gb_wg_wcslen(businessCard);

// 	cuiId = vcui_unifiedcomposer_create(mmi_frm_group_get_active_id(),&ucEntry);
// 	if (cuiId != GRP_ID_INVALID)
// 	{
// 		//vfxSetCuiCallerScr(cuiId, getMainScr());
// 		vcui_unifiedcomposer_run(cuiId);
// 	}
       vappUcAppLauncher(&ucEntry);	
}
#endif
extern GB_BOOL GB_WG_String_IsNumSymbol(const GB_U16 *str);
//进入mtk系统彩信
GB_VOID Winguo_Send_MMessage(GB_U16 *sNumber)
{
#ifdef __COSMOS_MMI_PACKAGE__
	Winguo_Send_COSMOS_MMessage(sNumber);
#else
#ifdef __MMI_MMS_2__
	if (sNumber==NULL)
	{
		return;	
	}	
	
	if (IsMessagesReEntering())
	{
	    DisplayPopup(
	        (GB_PU8) get_string(STR_SMS_MSG_NOT_READY_YET),
	        IMG_GLOBAL_UNFINISHED,
	        1,
	        MESSAGES_POPUP_TIME_OUT,
	        (GB_U8) ERROR_TONE);
	    return;
	}
	//mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

	if(0 != mmi_wcslen(sNumber) && GB_WG_String_IsNumSymbol(sNumber))
	{
		mms_address_insert_hdlr((GB_CHAR*)sNumber);
	}
	else
	{
		mms_text_insert_hdlr(NULL, 0, (GB_CHAR *)sNumber,mmi_wcslen(sNumber));
	}
#endif	
#endif
}

#ifndef __COSMOS_MMI_PACKAGE__
//进入mtk系统短信
#include "SmsAppGprot.h"
GB_VOID Winguo_Send_Message(GB_U16 *sNumber)
{
	S8 ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
	mmi_sms_write_msg_para_struct sendData;

	if (sNumber==NULL)
	{
		return;	
	}	

	mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

	memset(ascii_number, 0, sizeof(ascii_number));
	memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

	if(0 != mmi_wcslen(sNumber) && GB_WG_String_IsNumSymbol(sNumber))
	{
		mmi_ucs2_n_to_asc((PS8)ascii_number, (PS8)sNumber, MMI_PHB_NUMBER_LENGTH + 1);
		sendData.ascii_addr = (U8*) ascii_number;
	}
	else
	{
		sendData.string = (S8 *)sNumber;
		sendData.stringlength = mmi_wcslen(sNumber);	
	}	
	sendData.dcs = 0;
	sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;

	mmi_sms_write_msg_lanch(0, &sendData);	 
}

GB_VOID Winguo_Send_SMS_BusinessCard(GB_U16 *businessCard)
{
	S8 ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
	mmi_sms_write_msg_para_struct sendData;

	if (businessCard==NULL)
	{
		return;	
	}	

	mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

	memset(ascii_number, 0, sizeof(ascii_number));
	memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

	sendData.string = (S8 *)businessCard;
	sendData.stringlength = mmi_wcslen(businessCard);	

	sendData.dcs = 0;
	sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;

	mmi_sms_write_msg_lanch(0, &sendData);	 
}
#endif

GB_VOID Winguo_Send_SMSMessage(GB_U16 *sNumber)
{
#ifdef __COSMOS_MMI_PACKAGE__
	Winguo_Send_COSMOS_MMessage(sNumber);
#else
	Winguo_Send_Message(sNumber);
#endif 
}

GB_VOID Winguo_Send_BusinessCard(GB_U16 *businessCard)
{
#ifdef __COSMOS_MMI_PACKAGE__
	Winguo_Send_COSMOS_BusinessCard(businessCard);
#else
	Winguo_Send_SMS_BusinessCard(businessCard);
#endif 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "browser_api.h"

static GB_U16 *BrowserUrlStr = GB_NULL;
GB_VOID GB_WG_Wap_Start_Browser_ext(GB_VOID)
{
#ifdef BROWSER_SUPPORT	
	if (BrowserUrlStr)
	{
		GB_WG_FreeWin();
		if (mmi_frm_group_get_active_id() == GRP_GB_WINGUO_SCREEN)
		{
			mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);//DeleteScreenIfPresent(SCR_GB_WINGUO_SCREEN);
		}
		wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*)BrowserUrlStr);
		OslMfree(BrowserUrlStr);
		BrowserUrlStr = GB_NULL;
	}
#endif	
}
GB_VOID GB_WG_Wap_Start_Browser(GB_U16 *GBMD_UrlBuff)
{
	if (GBMD_UrlBuff)
	{
		if (BrowserUrlStr)
		{
			OslMfree(BrowserUrlStr);
			BrowserUrlStr = GB_NULL;
		}
		BrowserUrlStr = (GB_U16*)OslMalloc((gb_wg_wcslen(GBMD_UrlBuff)+1)*sizeof(*GBMD_UrlBuff));
		if (BrowserUrlStr)
		{
			gb_wg_wcscpy(BrowserUrlStr, GBMD_UrlBuff);
			GB_WgStartTimer(e_GB_WG_TIME_Write_Done, 0, GB_WG_Wap_Start_Browser_ext);
		}
	}
}
//11A 用的是mtk_gLanguageArray来保存各种语言标记 liangchuanhui 20110830
extern const sLanguageDetails mtk_gLanguageArray[];
#define gLanguageArray  mtk_gLanguageArray 
extern U16 gCurrLangIndex;
GB_WG_LANGUAGE GB_WG_GetCurrentSysLanguage(GB_VOID)
{

	if(strncmp((GB_CHAR*)gLanguageArray[gCurrLangIndex].aLangCountryCode,"en", 2) == 0)
	{
		return e_GB_WG_LANGUAGE_EN;
	}
	else if (strncmp((GB_CHAR*)gLanguageArray[gCurrLangIndex].aLangCountryCode,"zh", 2) == 0)
	{
		return e_GB_WG_LANGUAGE_CN;
	}
	else
	{
		return e_GB_WG_LANGUAGE_OTHER;
	}

}
// 5/28/2012 liangchuanhui]
#ifdef __GB_WINGUO_MULTI_LANGUAGE__
GB_INT GB_WG_GetCurrentSysLanguageStr(GB_CHAR* pLanguageStr, GB_INT n)
{
	GB_INT len = 0;
	if (!pLanguageStr || n <= 0)
	{
		return GB_FALSE;
	}
	while (len < n)
	{
		// '-'换成'_'
		if (gLanguageArray[gCurrLangIndex].aLangCountryCode[len] == '-')
		{
			pLanguageStr[len] = '_';
		}
		else
		{
			pLanguageStr[len] = gLanguageArray[gCurrLangIndex].aLangCountryCode[len];
		}
		len++;
	}
	return len;
}
#endif


// #if defined(GB_MTK_09BPLAT)
// 
// #ifndef __MMI_UNIFIED_COMPOSER__
// 
// extern mmi_ret mmi_sms_send_msg_proc(mmi_event_struct *evt);
// 
// mmi_id GB_WG_Sms_Send_Pre_Init()
// {
// 	mmi_id mmi_sms_send_child_gid = GRP_ID_INVALID;
// 	mmi_id mmi_sms_send_parent_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_sms_send_msg_proc, NULL);
//     mmi_frm_group_enter(mmi_sms_send_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//     mmi_sms_send_child_gid = cui_sms_send_create(mmi_sms_send_parent_gid);
// 	mmi_frm_group_enter(mmi_sms_send_child_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
// 	return mmi_sms_send_child_gid;
// }
// #endif
// 
// #endif
// #ifndef GB_WG_SYS_SEND_MESSAGE
// 
// #if defined(GB_MTK_09APLAT)
// #ifndef __MMI_UNIFIED_COMPOSER__
// #include "SmsAppGprot.h"
// #include "SmsAppProt.h "
// extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
// #else
// #include "wapadp.h"
// #include "xml_def.h"
// #include "mma_struct.h"
// #include "mmsadp.h"
// #include "UMGprot.h"
// #include "custom_wap_config.h"
// #include "custom_uc_config.h"
// #include "UnifiedComposerResDef.h"
// #include "UnifiedComposerGProt.h"
// #include "UnifiedComposerProt.h"
// 
// static MMI_BOOL wgmsg_flag = MMI_FALSE; // 用于区分winguo短信和系统短信的标志位
// GB_VOID GB_WG_MSG_FLAG_SET(MMI_BOOL flag)
// {
// 	wgmsg_flag = flag;
// }
// 
// MMI_BOOL GB_WG_MSG_FLAG_GET()
// {
// 	return wgmsg_flag;
// }
// #endif
// #endif
// 
// 
// #if defined(GB_MTK_09BPLAT)
// #include "SmsAppGprot.h"
// #include "SmsAppProt.h "
// 
// #ifdef __MMI_UNIFIED_COMPOSER__
// #include "wapadp.h"
// #ifdef __MMI_MMS_2__
// #include "MmsSrvGprot.h"
// #endif 
// 
// #include "UcSrvGprot.h"
// #include "UcAppGprot.h"
// #include "UcAppProt.h"
// extern mmi_uc_context_struct *g_uc_p;
// static MMI_BOOL wgmsg_flag = MMI_FALSE; // 用于区分winguo短信和系统短信的标志位
// #endif
// 
// 
// #endif
// GB_INT GB_WG_Get_MaxNumberLength()
// {
// #if defined(GB_MTK_09APLAT)
// #ifdef __MMI_UNIFIED_COMPOSER__
// 	return (MMI_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH);
// #else
// 	return MMI_SMS_MAX_ADDR_LEN;
// #endif
// #elif defined(GB_MTK_10APLAT)
// #if defined(__MMI_MMS_STANDALONE_COMPOSER__)
// 	return CUI_SMS_MAX_ADDR_LEN;
// #else
// 	return (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH);
// #endif
// #elif defined(GB_MTK_09BPLAT)
// #ifndef __MMI_UNIFIED_COMPOSER__
// 	return 100;
// #else
// #ifdef __MMI_UNIFIED_COMPOSER_20__
// 	return (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH);
// #else
// 	return (MMI_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH);
// #endif
// #endif
// 
// #else
// 	return 100;
// #endif
// 
// 
// }
// //将短信界面的发送号码和数据存储到系统
// GB_VOID GB_WG_Get_SMSDataMsg(GB_U16 *pData, GB_CHAR *pPhoneList[], GB_U16 nPhoneNum)
// {
// #if defined(GB_MTK_09APLAT)
// 
// #ifdef __MMI_UNIFIED_COMPOSER__
// 	GB_INT i = 0, buffer_len = 0;
// 	if (*pPhoneList == GB_NULL || nPhoneNum == 0)
// 	{
// 		return;	
// 	}
// 	if (pData == GB_NULL)
// 	{
// 		pData = L"";
// 	}
// 	
// 	buffer_len =  gb_wg_wcslen(pData);
// 	
// 	// 清除所有发送地址
// 	mmi_uc_delete_all_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO);
// 	
// 	for (i = 0; i<nPhoneNum; i++)
// 	{
// 		mmi_uc_add_address(pPhoneList[i],
// 			MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,MMI_UC_ADDRESS_GROUP_TYPE_TO);
// 	}
// 	
// 	mmi_uc_reset_text_buffer();
// 	if (buffer_len <= (MMI_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1)
// 	{
// 		// 用wg
// 		mmi_ucs2ncpy((S8*) g_uc_p->main.text_buffer, (S8*) pData, buffer_len);
// 	}
// 	else
// 	{
// 		mmi_ucs2ncpy(
// 			g_uc_p->main.text_buffer,
// 			(S8*) pData,
// 			(MMI_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
// 	}
// 	
// 	if (g_uc_p->msg.current_slide == GB_NULL)
// 	{
// 		g_uc_p->msg.current_slide = mmi_uc_insert_slide(NULL);
// 		g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;
// 		g_uc_p->msg.current_slide->duration = g_uc_p->msg.slide_timing;
// 		g_uc_p->msg.current_slide->text.char_count = buffer_len;
// 	}
// #else
// 	GB_INT i;
// 	GB_INT strlen;
// 	EMSData *psmsData = NULL;
// 
// 	// 考虑到保存的时候可以为空
// // 	if (*pPhoneList == NULL || nPhoneNum == 0)
// // 	{
// // 		return;	
// // 	}
// 	if (pData==NULL)
// 	{
// 		pData = L"";
// 	}
// 	
// 	mmi_sms_remove_all_recipient();
// 	
// 	for (i = 0; i<nPhoneNum; i++)
// 	{
// 		mmi_sms_append_recipient(pPhoneList[i]); //  添加短信号码至系统
// 	}
// 	strlen = gb_wg_wcslen(pData);
// 	psmsData = GetEMSDataForEdit(NULL, 0);
// 	EMSSetDCS(psmsData, SMSAL_UCS2_DCS);
// 	AddString(psmsData,(GB_U8*)pData, (GB_U16)strlen, NULL);  
// #endif
// 
// #elif defined(GB_MTK_10APLAT) || defined(GB_MTK_09BPLAT)
// 	GB_WG_SMS_Init_GlobalInfo(pData, pPhoneList, nPhoneNum);  // 11A新短信修改 [8/9/2011 Leijinfu]
// 
// #else
// #error no body
// #endif
// }
// 
// 
// GB_VOID GB_WG_SendMessage(GB_VOID)
// {
// #if defined(GB_MTK_09APLAT)
// 	#ifdef __MMI_DUAL_SIM_MASTER__
// 	mmi_sms_set_prefer_sim_type(SMS_SIM_UNSPECIFIC);
// 	#endif
// 	// 发送系统短信
// #ifdef __MMI_UNIFIED_COMPOSER__
// 	wgmsg_flag = MMI_TRUE;
// 	g_uc_p->msg_type.curr_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
// 	mmi_uc_process_send();
// #else
// 	gb_wg_gui_lock_double_buffer();
// 	mmi_sms_highlight_send();
// 	execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
// 	gb_wg_gui_unlock_double_buffer();
// #endif
// 	
// #elif defined(GB_MTK_10APLAT) || defined(GB_MTK_09BPLAT)
// 	GB_WG_SmsSendMessageStart(); // 11A新短信修改 [8/9/2011 Leijinfu]
// 	
// #else
// #error no body
// #endif
// }
// 
// #include "SmsAppResDef.h"
// #ifndef __COSMOS_MMI_PACKAGE__
// #include "SmsSrvGProt.h"	//add by zhangchenglong
// #endif
// //短信界面保存到草稿箱的接口函数
// GB_VOID GB_WG_Save_to_Drafts(GB_VOID)
// {
// #if defined(GB_MTK_09APLAT)
// 
// 	#ifndef __MMI_UNIFIED_COMPOSER__
// 	// 增强安全判断，是否短信已经准备完毕 add by zhangwei-jerry 20110627
// 	if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
//     {
//         mmi_sms_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION, STR_GLOBAL_LOADING, STR_GLOBAL_BACK);
//         mmi_sms_entry_processing_generic();
//         /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_inbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
//     }
//     /* disallow re-entering SMS application when there is a pending SMS job running in the background */
//     else if (mmi_frm_sms_check_action_pending())
//     {
//         mmi_display_popup((UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET), MMI_EVENT_FAILURE);
//     }
// 	#else// def __MMI_UNIFIED_COMPOSER__
// 	if (!(mmi_uc_is_uc_ready()) || mmi_uc_is_uc_reenter())
// 	{
// 		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
// 		return ;
// 	}
// 	#endif// def __MMI_UNIFIED_COMPOSER__
// 	else
// 	{
// 		#ifdef __MMI_DUAL_SIM_MASTER__
// 		mmi_sms_set_prefer_sim_type(SMS_SIM_UNSPECIFIC);
// 		#endif 
// 		
// 		#ifndef __MMI_UNIFIED_COMPOSER__
// 		gb_wg_gui_lock_double_buffer();
// 		
// 		// 用到了系统的东西，只能这么做了，先设定再change的话不会显示乱菜单 add by zhangwei-jerry 20110627
// 		set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_OK));
// 		set_left_softkey_icon((PU8)GetImage(IMG_GLOBAL_OK));
// 		set_right_softkey_label((UI_string_type)GetString(STR_GLOBAL_BACK));
// 		set_right_softkey_icon((PU8)GetImage(IMG_GLOBAL_BACK));
// 
// 		mmi_sms_highlight_ed_save_to_drafts();
// 		
// 		execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
// 		gb_wg_gui_unlock_double_buffer();
// 		#else
// 		wgmsg_flag = MMI_TRUE;
// 		g_uc_p->msg_type.curr_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
// 		mmi_uc_pre_process_save();
// 		#endif
// 	}
// 	
// #elif defined(GB_MTK_09BPLAT)
// 	if(GB_WG_G_pSmsInfo != GB_NULL)
// 	{
// 		GB_WG_SMS_save_after_send(SRV_SMS_STATUS_DRAFT, GB_WG_G_pSmsInfo->m_pPhoneList[0]);  // 11A保存草稿 [8/19/2011 Leijinfu] 
// 	}
// #elif defined(GB_MTK_10APLAT)
// 	if(GB_WG_G_pSmsInfo != GB_NULL)
// 	{
// 		GB_WG_SMS_save_after_send(SRV_SMS_STATUS_DRAFT, GB_WG_G_pSmsInfo->m_pPhoneList[0]);  // 11A保存草稿 [8/19/2011 Leijinfu] 
// 	}
// 
// #else
// #error no body
// #endif
// }
// 
// 
// #endif

GB_BOOL GB_WG_Decyption_PhoneBook_Password_IsOK(GB_U16*pwd)
{
	if (pwd)
	{
		if(gb_wg_wcscmp(pwd,L"123456")==0)
		{
			return GB_TRUE;
		}
		else
		{
			return GB_FALSE;
		}
	}
	return GB_FALSE;
}

GB_WCHAR* gb_wg_wcsncpy(GB_WCHAR *str_dst, const GB_WCHAR* str_src, GB_INT count)
{
	return mmi_wcsncpy(str_dst, str_src, count);
}
GB_WCHAR* gb_wg_wcscpy(GB_WCHAR *str_dst, const GB_WCHAR *str_src)
{
	return mmi_wcscpy(str_dst, str_src);
}
GB_INT gb_wg_wcslen(const GB_WCHAR *string)
{	
	return mmi_wcslen(string);
}
GB_WCHAR* gb_wg_wcsncat(GB_WCHAR *str_dst, const GB_WCHAR *str_src, GB_INT count)
{
	return mmi_wcsncat(str_dst, str_src, count);
}
GB_WCHAR* gb_wg_wcscat(GB_WCHAR *str_dst, const GB_WCHAR *str_src)
{
	return mmi_wcscat(str_dst, str_src);
}
GB_WCHAR* gb_wg_wcsstr(GB_WCHAR *string, const GB_WCHAR *str_char_set)
{
	return mmi_wcsstr(string, str_char_set);
}
GB_INT gb_wg_wcscmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst)
{
	return mmi_wcscmp(str_src, str_dst);
}
GB_INT gb_wg_wcsicmp(const GB_WCHAR *str_src, const GB_WCHAR *str_dst)
{
	return mmi_wcsicmp(str_src, str_dst);
}
GB_UINT gb_wg_asc_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer)
{
	return mmi_asc_to_wcs(pOutBuffer, pInBuffer);
}
// GB_UINT gb_wg_asc_n_to_wcs(GB_WCHAR *pOutBuffer, GB_CHAR *pInBuffer, GB_INT len)
// {
// 	return mmi_asc_n_to_wcs(pOutBuffer, pInBuffer, len);
// }
GB_UINT gb_wg_wcs_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer)
{
	return mmi_wcs_to_asc(pOutBuffer, pInBuffer);
}
// GB_UINT gb_wg_wcs_n_to_asc(GB_CHAR *pOutBuffer, GB_WCHAR *pInBuffer, GB_INT len)
// {
// 	return mmi_wcs_n_to_asc(pOutBuffer, pInBuffer, len);
// }
GB_INT GB_WgTransformTimerID(GB_WG_E_TIME_ID timerid)
{
	GB_INT systimeID = 0;
	switch(timerid)
	{
	case e_GB_WG_TIME_Tick:
		systimeID = GB_WG2_TIME;
		break;
	case e_GB_WG_TIME_Write_Done:
		systimeID = GB_WG2_HW_TIME;
		break;
	case e_GB_WG_TIME_SMD_forward_releas:
		systimeID = GB_WG2_SMD_RELEAS_TIME;
		break;
	default:
		ASSERT(0);
	}
	return systimeID;
}
GB_VOID GB_WgStartTimer(GB_WG_E_TIME_ID timerid, GB_UINT delay, GB_WG_FuncPtr funcPtr)
{
	StartTimer(GB_WgTransformTimerID(timerid), delay, funcPtr);
}

GB_INT GB_WgTimerIsStart(GB_WG_E_TIME_ID timerid)
{
	return (IsMyTimerExist(GB_WgTransformTimerID(timerid)) != 0);
}

GB_VOID GB_WgStopTimer(GB_WG_E_TIME_ID timerid)
{
	StopTimer(GB_WgTransformTimerID(timerid));
}


GB_VOID GB_WINGUO_ASSERT(GB_CHAR* expr, GB_CHAR* file, GB_UINT line, GB_INT n)
{
	if(!n)
	{
#if defined(WIN32)
		kal_assert_fail(expr, file, line, KAL_FALSE, 0, 0, 0, NULL);
#else
		ASSERT(n);
#endif
	}
}

GB_U16 MOD_ID_GB_wg = MOD_MMI;		//MGB task 的枚举,这里要改的

GB_VOID GB_WgOutput(const GB_CHAR* data)
{
#ifdef  __MTK_TARGET__
	kal_prompt_trace(MOD_MMI_COMMON_APP,(GB_CHAR *)data);
#else
	kal_print((GB_CHAR *)data);
#endif
}
GB_VOID GB_WgOutputW(const GB_CHAR* data)
{
#ifdef  __MTK_TARGET__
	kal_prompt_trace(MOD_MMI,(GB_CHAR *)data);
#else
	kal_print((GB_CHAR *)data);
#endif
}

extern char *release_hw_ver(void);
GB_CHAR* GB_WgGetHwVer(GB_VOID)
{
	return release_hw_ver();
}

#ifdef WIN32
#ifdef GB_WINGUO_ADM_TESTMEM
#define GB_WG_MEM_CHECK_TEST
#endif
#endif
#ifdef GB_WG_MEM_CHECK_TEST
static struct  
{
	void *p;
	int size;
	char *fileName;
	int line;
}gb_checkmem[1500]; // 以后如果因为内存引起黑屏问题，有可能是这里分配不够，先检查测试
static int checkmemcount = 0;
#define MEMTEST_CHECK_CHARCOUNT 16
#endif

#ifdef GB_WINGUO_ADM_TESTMEM
#define  MAX_MEMNODE_LEN 20000
typedef struct _MEMNODE
{
	char fileName[256];	
	int  line;
	int  size;
	int  age;
	void *p;
}GBMemNode;
typedef struct _MEMMANAGER{
	GBMemNode memNodes[MAX_MEMNODE_LEN];
	GB_INT    curUsed;
}MemManager;

MemManager memContainer;
static unsigned int nMemCount =0;

void MemAddPoint(MemManager*pMemContainer,void* pPoint,char* pFile,int line,int size);
void MemDelPoint(MemManager*pMemContainer,void *pPoint);
void MemReport(MemManager*pMemContainer,GB_BOOL bReportData);

typedef GB_VOID* (*pFUNGB_WG_MALLOC)(GB_ULONG size,GB_CHAR *pFileName,int line);
typedef GB_VOID (*pFUNGB_WG_FREE)(GB_VOID* p);

void* GB_WG_MALLOCEx(GB_ULONG size,GB_CHAR *pFileName,int line)
{
	void * result =NULL;
		
#if defined(GBUSE_MEDIA_MEM)

	{
		#ifdef GB_WG_MEM_CHECK_TEST
		{
//			int GB_WG_size = 0;//测试内存大小用
			GB_CHAR *p = GB_NULL;
			GB_INT i = 0;
			GB_CHAR t[MEMTEST_CHECK_CHARCOUNT];
			if (size < 0)
			{
				ASSERT(0);
			}
			memset(t, 0x99, sizeof(t));
			for (i=0; i<checkmemcount; i++)
			{
	
				if (memcmp(((GB_CHAR*)gb_checkmem[i].p)-MEMTEST_CHECK_CHARCOUNT, t, MEMTEST_CHECK_CHARCOUNT) != 0)
				{
					ASSERT(0);
				}
				if (memcmp(((GB_CHAR*)gb_checkmem[i].p)+gb_checkmem[i].size,t, MEMTEST_CHECK_CHARCOUNT) != 0)
				{
					ASSERT(0);
				}
// 				{//测试内存大小
// 					
// 					GB_WG_size +=gb_checkmem[i].size;
// 					printf("\n malloc GB_WG_size = %d", GB_WG_size);
// 				}
			}
			// 			{//测试内存大小
			// 				static int GB_WG_MAX_size = 0;
			// 				if (GB_WG_size>GB_WG_MAX_size)
			// 				{
			// 					GB_WG_MAX_size = GB_WG_size;
			// 				}
			// 				printf("\n malloc GB_WG_MAX_size = %d", GB_WG_MAX_size);
			// 			}
			p = (GB_CHAR *)med_ext_smalloc(size+MEMTEST_CHECK_CHARCOUNT*2); //med_ext_smalloc(size+8);
			if (p == GB_NULL)
			{
				MemReport(&memContainer,FALSE);
				return p;
			}
			MemAddPoint(&memContainer,p,pFileName,line,size);
			memset(p, 0x99, MEMTEST_CHECK_CHARCOUNT);
			memset(p+MEMTEST_CHECK_CHARCOUNT+size, 0x99, MEMTEST_CHECK_CHARCOUNT);
			gb_checkmem[checkmemcount].p = (GB_VOID*)((GB_CHAR*)p+MEMTEST_CHECK_CHARCOUNT);
			gb_checkmem[checkmemcount].size = size;
			gb_checkmem[checkmemcount].fileName = pFileName;
			gb_checkmem[checkmemcount].line = line;
			checkmemcount++;
			printf("\n malloc checkmemcount = %d, adr=%x____________", checkmemcount, (GB_INT)p);
			result = (GB_VOID *)(p+MEMTEST_CHECK_CHARCOUNT);
			return result;
		}
		#else

		result = (GB_VOID *)med_ext_smalloc(size);
		if (result == GB_NULL)
		{
			MemReport(&memContainer,FALSE);
			return result;
		}

		MemAddPoint(&memContainer,result,pFileName,line,size);
		return result;
		#endif
	}
#endif
}

void GB_WG_FREEEx(void* p)
{
	if(p!=0)
	{
#if defined(GBUSE_MEDIA_MEM)

		#ifdef GB_WG_MEM_CHECK_TEST
		{
			int i;
			char t[MEMTEST_CHECK_CHARCOUNT];
			memset(t, 0x99, sizeof(t));
			for (i=0; i<checkmemcount; i++)
			{
				if (memcmp(((char*)gb_checkmem[i].p)-MEMTEST_CHECK_CHARCOUNT, t, MEMTEST_CHECK_CHARCOUNT) != 0)
				{
					ASSERT(0);
				}
				if (memcmp(((char*)gb_checkmem[i].p)+gb_checkmem[i].size,t, MEMTEST_CHECK_CHARCOUNT) != 0)
				{
					ASSERT(0);
				}
			}
			for (i = 0; i<checkmemcount; i++)
			{
				if (gb_checkmem[i].p == p)
				{
					break;
				}
			}
			if (i==checkmemcount)
			{
				ASSERT(0);
			}
			if (memcmp(((char*)p)-MEMTEST_CHECK_CHARCOUNT, t, MEMTEST_CHECK_CHARCOUNT) != 0)
			{
				ASSERT(0);
			}
			if (memcmp(((char*)p)+gb_checkmem[i].size,t, MEMTEST_CHECK_CHARCOUNT) != 0)
			{
				ASSERT(0);
			}
			med_ext_sfree(((char*)p)-MEMTEST_CHECK_CHARCOUNT);
			MemDelPoint(&memContainer,((char*)p)-MEMTEST_CHECK_CHARCOUNT);
			memmove(gb_checkmem+i, gb_checkmem+i+1, (checkmemcount-i)*sizeof(gb_checkmem[0]));
			checkmemcount--;
			
			printf("\n free checkmemcount = %d, adr=%x____________", checkmemcount, (int)(((char*)p)-MEMTEST_CHECK_CHARCOUNT));
		}
		#else
		med_ext_sfree(p);

		MemDelPoint(&memContainer,p);
		#endif
#endif

	}
}

pFUNGB_WG_MALLOC g_GB_WG_MallocFun = GB_WG_MEMORY_MALLOC;
pFUNGB_WG_FREE g_GB_WG_FreeFun = GB_WG_MEMORY_FREE;


GB_VOID GB_WG_FreeFunEx(GB_VOID* p)
{
	if (g_GB_WG_FreeFun)
	{
		g_GB_WG_FreeFun(p);
	}
	else
	{
		GB_WG_FREEEx(p);
	}
}

GB_VOID* GB_WG_MallocFunEx(GB_ULONG size,GB_CHAR *pFileName,int line)
{
	if (g_GB_WG_MallocFun)
	{
		return g_GB_WG_MallocFun(size,pFileName,line);
	}
	else
	{
		return GB_WG_MALLOCEx(size,pFileName,line);
	}
}

void MemInit(MemManager*pMemContainer,int size)
{
	int index =0;
	if(pMemContainer==NULL)return ;
	for (index =0;index<MAX_MEMNODE_LEN;index++)
	{
		pMemContainer->memNodes[index].p =NULL;
	}
	pMemContainer->curUsed =0;
}
void MemAddPoint(MemManager*pMemContainer,void* pPoint,char* pFile,int line,int size)
{
	int index =0;
	if(pMemContainer==NULL||pPoint==NULL)return ;
	if(pMemContainer->curUsed==0)MemInit(pMemContainer,0);
	
	for (index =0;index<MAX_MEMNODE_LEN;index++)
	{
		if(pMemContainer->memNodes[index].p==NULL)
		{
			pMemContainer->memNodes[index].p =pPoint;
			memset(pMemContainer->memNodes[index].fileName,0,256);	
			if(pFile!=NULL){//如果这里大于256呢，，我们是测试代码，请使用者注意
				memcpy(pMemContainer->memNodes[index].fileName,pFile,strlen(pFile));
			}
			pMemContainer->memNodes[index].line =line;
			pMemContainer->memNodes[index].size =size;
			pMemContainer->curUsed ++;
			
			pMemContainer->memNodes[index].age=nMemCount++;
			break;
		}	
	}
}

void MemDelPoint(MemManager*pMemContainer,void *pPoint)
{
	int index =0;
	if(pMemContainer==NULL||pPoint==NULL)return ;
	for (index =0;index<MAX_MEMNODE_LEN;index++){
		if(pMemContainer->memNodes[index].p==pPoint){
			pMemContainer->memNodes[index].p =NULL;
			pMemContainer->curUsed --;
			break;
		}	
	}
}

void MemReport(MemManager*pMemContainer,GB_BOOL bReportData)
{
	GB_FILEHANDLE fd; 
	int index =0;
	if(pMemContainer==NULL)return ;
	
	GB_file_init_path("d:\\mtkBrowser\\log\\");
	GB_file_delete("d:\\mtkBrowser\\log\\test-Gb_test.txt");
	fd = GB_file_open("d:\\mtkBrowser\\log\\test-Gb_test.txt","w");
	if(fd==0)return;
	GB_file_write_chars(fd,"\n\nanthor time\n\n");
	
	for (index =0;index<MAX_MEMNODE_LEN;index++)
	{
		if(pMemContainer->memNodes[index].p!=NULL)
		{	
			char *pfileName = strrchr(pMemContainer->memNodes[index].fileName,'\\');
			char szdata[512];
			memset(szdata,0,512);
			if(pfileName==NULL){
				sprintf(szdata,"%d %s %d %d %d,%d\n",
					index,
					pMemContainer->memNodes[index].fileName,
					pMemContainer->memNodes[index].line,
					pMemContainer->memNodes[index].size,
					pMemContainer->memNodes[index].age,
					pMemContainer->memNodes[index].p);
			}else{
				sprintf(szdata,"%d %s %d %d %d,%d\n",
					index,
					pfileName+1,
					pMemContainer->memNodes[index].line,
					pMemContainer->memNodes[index].size,
					pMemContainer->memNodes[index].age,
					pMemContainer->memNodes[index].p);
			}
			
			GB_file_write_chars(fd,szdata);
			
			if(bReportData)
				{
				GB_file_write(fd,pMemContainer->memNodes[index].p,pMemContainer->memNodes[index].size);
				GB_file_write_chars(fd,"\n\n");
			}
		}	
	}
	GB_file_close(fd);
}

GB_VOID MemReportEx()
{
	MemReport(&memContainer,FALSE);
}
GB_VOID MemReportDataEx()
{
	MemReport(&memContainer,TRUE);
}

#else // #ifdef GB_WINGUO_ADM_TESTMEM

#include "Vfx_sys_memory.h"
#if defined(__COSMOS_MMI_PACKAGE__) && defined(GB_MTK_11B6255)
#include "app_mem_med.h" //test scf 20120424
#endif
GB_VOID *GB_WG_MALLOC(GB_ULONG size)
{
	GB_VOID * result =NULL;
	if(size>0)
	{
#if defined(GBUSE_MEDIA_MEM)
 		// [7/2/2011 lzp]	return (GB_VOID *)med_ext_smalloc(size);
// 		return vfx_sys_mem_alloc(VFX_SYS_MEM_POOL_ID_GLOBAL, size);
		return (GB_VOID*)applib_asm_alloc_anonymous(size); // [scf 20120409]
		//return med_ext_smalloc(size);
// 		return mmi_frm_asm_alloc_anonymous_nc(size);
// 		media_get_asm_buffer(size); 链接出错
// 		return gdi_alloc_ext_mem(size);
// 		med_alloc_asm_mem(size);
// 		return med_alloc_aud_mem(size);
#endif
	}
	return 0;
}


GB_VOID GB_WG_FREE(GB_VOID* p)
{
	if(p!=0)
	{
		#if defined(GBUSE_MEDIA_MEM)	
//		med_ext_sfree(p);
//		vfx_sys_mem_free(p);
		applib_asm_free_anonymous(p);// [scf 20120409]
//		med_ext_sfree(p);
//		mmi_frm_asm_free_anonymous(p);
//		gdi_free_ext_mem(p);
//		med_free_aud_mem(p);
		#endif
	}
}


typedef GB_VOID* (*pFUNGB_WG_MALLOC)(GB_ULONG size);
typedef GB_VOID (*pFUNGB_WG_FREE)(GB_VOID* p);

pFUNGB_WG_MALLOC g_GB_WG_MallocFun = GB_WG_MEMORY_MALLOC; 
pFUNGB_WG_FREE g_GB_WG_FreeFun = GB_WG_MEMORY_FREE;

GB_VOID GB_WG_FreeFun(GB_VOID* p)
{
	if (g_GB_WG_FreeFun)
	{
		g_GB_WG_FreeFun(p);
	}
	else
	{
		GB_WG_FREE(p);
	}
}

GB_VOID* GB_WG_MallocFun(GB_ULONG size)
{
	if (g_GB_WG_MallocFun)
	{
		return g_GB_WG_MallocFun(size);
	}
	else
	{
		return GB_WG_MALLOC(size);
	}
}
#endif // #ifdef GB_WINGUO_ADM_TESTMEM

GB_VOID GB_WG_SetMallocFun(GB_VOID* mallocFun)
{
	if (mallocFun)
	{
		g_GB_WG_MallocFun = (pFUNGB_WG_MALLOC)mallocFun;
	}
}

GB_VOID GB_WG_SetFreeFun(GB_VOID* freeFun)
{
	if (freeFun)
	{
		g_GB_WG_FreeFun = (pFUNGB_WG_FREE)freeFun;
	}
}

GB_BOOL GB_WG_Plat_SupportTouch(GB_VOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	return GB_TRUE;
#else
	return GB_FALSE;
#endif
}

GB_CHAR* GB_WG_Plat_ScreenSize(GB_VOID)
{
#ifdef __MMI_MAINLCD_480X800__
	return "480X800";
#elif __MMI_MAINLCD_320X480__
	return "320X480";
#elif __MMI_MAINLCD_240X400__
	return "240X400";
#elif __MMI_MAINLCD_320X240__
	return "320X240";
#elif __MMI_MAINLCD_240X320__
	return "240X320";
#elif __MMI_MAINLCD_176X220__
	return "176X220";
#elif __MMI_MAINLCD_128X160__
	return "128X160";
#else
	return "128X128";
#endif
}

#ifdef GB_MTK_10APLAT
extern MMI_BOOL srv_clam_is_close(void);
#elif defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
extern MMI_BOOL IsClamClose(void);
#endif

GB_BOOL GB_WG_Clam_Is_Close()
{
#ifdef GB_MTK_10APLAT
	return srv_clam_is_close();
#elif defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	return IsClamClose();
#endif
	return GB_FALSE;
}

/**********************************************************************
* 函数名称： GB_WG_Dial_LongPress_Handle
* 功能描述： 拨号框长按事件处理接口
* 输入参数： keyValue,长按的键值;str:之前拨号框中字符串；
* 返 回 值： GB_TRUE:系统处理该键值的长按事件；GB_FALSE:系统没有处理
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
lenny           20110623						创建
***********************************************************************/
//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
#include "DialerCuiGprot.h"
//#endif
static GB_WCHAR *GB_WG_pDial_LongPressStr = GB_NULL;
static GB_UINT GB_WG_Dial_LongPressKey = GB_WG_KEY_INVALID;
GB_VOID GB_WG_Run_Dial_LongPress_Handle_Timer(GB_VOID)
{
	if (GB_WG_pDial_LongPressStr && GB_WG_Dial_LongPressKey != GB_WG_KEY_INVALID)
	{
		GB_WG_Dial_LongPress_Handle(GB_WG_pDial_LongPressStr, GB_WG_Dial_LongPressKey);
	}
	GB_WG_Dial_LongPressKey = GB_WG_KEY_INVALID;
	if(GB_WG_pDial_LongPressStr)
	{
		GB_WG_Free(GB_WG_pDial_LongPressStr);
		GB_WG_pDial_LongPressStr = GB_NULL;
	}
}

GB_VOID GB_WG_Dial_LongPress_Handle_ext(GB_U16 *str,GB_UINT keyValue)
{
	if (!str || keyValue == GB_WG_KEY_INVALID)
	{
		return;
	}
	if (GB_WG_pDial_LongPressStr)
	{
		GB_WG_Free(GB_WG_pDial_LongPressStr);
		GB_WG_pDial_LongPressStr = GB_NULL;
	}
	GB_WG_pDial_LongPressStr = GB_WG_Malloc((gb_wg_wcslen(str)+1)*sizeof(GB_WCHAR));
	gb_wg_wcscpy(GB_WG_pDial_LongPressStr, str);
	GB_WG_Dial_LongPressKey = keyValue;
	GB_WgStartTimer(e_GB_WG_TIME_Write_Done, 0, GB_WG_Run_Dial_LongPress_Handle_Timer);
}

GB_BOOL GB_WG_Dial_LongPress_Handle(GB_U16 *str,GB_UINT keyValue)
{
	GB_BOOL result = GB_FALSE;
	GB_INT len = 0;
	if (!str)
	{
		return result;
	}
	len =gb_wg_wcslen(str);
	if (len!=1)
	{
		return result;
	}
	switch(keyValue)
	{
	case GB_WG_KEY_0:
		//0键的长按处理事件
		result = GB_TRUE;
		break;
	case GB_WG_KEY_1:
		//mark by yyk
		#ifdef GB_MTK_10APLAT
		{
//还是打开长按功能键
			//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
			if (!GB_WG_Get_isVirtual_key())
			{
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifndef __COSMOS_MMI_PACKAGE__

				mmi_id cui_id = 0;
// 				mmi_id rp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL);
// 				mmi_frm_group_enter(rp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
				mmi_id rp_id = mmi_frm_group_get_active_id();
				cui_id = cui_dialer_create_ex(rp_id,CUI_DIALER_TYPE_UNSPECIFIED);
				mmi_frm_group_enter(cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
				cui_dialer_set_dial_string(cui_id,str);
				cui_dialer_do_voice_mail_dial();
                
#endif
#endif/*__MMI_TELEPHONY_SUPPORT__ */
			}
			
//#endif
		}
		#else
		DialVoiceMail();
		#endif
		break;
	case GB_WG_KEY_2:
	case GB_WG_KEY_3:
	case GB_WG_KEY_4:
	case GB_WG_KEY_5:
	case GB_WG_KEY_6:
	case GB_WG_KEY_7:
	case GB_WG_KEY_8:
	case GB_WG_KEY_9:
		#ifndef GB_MTK_10APLAT
		#ifdef GB_MTK_09APLAT
		if (PhbGetSpeedDialStatus() == MMI_TRUE)
		#else  
		if (mmi_phb_get_speed_dial_status() == MMI_TRUE)
		#endif
		{
			IdleCallSpeedDialOnLongPress();
		}
		#else
		{
			//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
			if (!GB_WG_Get_isVirtual_key())
			{
                #ifndef __COSMOS_MMI_PACKAGE__

				if (mmi_phb_get_speed_dial_status())
				{
					mmi_id cui_id = 0;
// 					mmi_id rp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL);
// 					mmi_frm_group_enter(rp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
					mmi_id rp_id = mmi_frm_group_get_active_id();
					cui_id = cui_dialer_create_ex(rp_id,CUI_DIALER_TYPE_UNSPECIFIED);
					mmi_frm_group_enter(cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
					cui_dialer_set_dial_string(cui_id,str);
					cui_dialer_do_speed_dial();
				}
				#endif

			}
			
//#endif
		}
		
		#endif
	    break;
	case GB_WG_KEY_STAR:
	    break;
	case GB_WG_KEY_POUND:
		#ifndef GB_MTK_10APLAT
		IdleToggleProfile();
		#else
		{
//还是打开长按功能键
			//  [6/2/2012 liangchuanhui]
//#ifndef GBWG_VIRTUAL_KEY
			if (!GB_WG_Get_isVirtual_key())
			{
				#ifndef __COSMOS_MMI_PACKAGE__
				mmi_id cui_id = 0;
// 				mmi_id rp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL);
// 				mmi_frm_group_enter(rp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
				mmi_id rp_id = mmi_frm_group_get_active_id();
				cui_id = cui_dialer_create_ex(rp_id,CUI_DIALER_TYPE_UNSPECIFIED);
				mmi_frm_group_enter(cui_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
				cui_dialer_set_dial_string(cui_id,str);
				cui_dialer_do_toggle_silent_profile();
				#endif
			}
			
//#endif
		}
		#endif

	    break;
	default:
	    break;
	}

	if (!GB_WG_Is_In_Winguo())
    {
		mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);//DeleteScreenIfPresent(SCR_GB_WINGUO_SCREEN);
    }
	return result;
}

/* ---------------------------------------------------------------------------- */

GB_BOOL GB_WG_Is_Support_WeiBo()
{
#ifdef __MDP_SUPPORT__
	return GB_TRUE;
#endif
	return GB_FALSE;
}

#ifdef __MDP_SUPPORT__
extern void ARTBlogV3_Deliver_Article(GB_U16* msg_str, GB_U16* pic_path);
#endif

GB_VOID GB_WG_Share_To_WeiBo(GB_U16 *content)
{
	GB_INT flag = GB_FALSE;
	if (content)
	{
#ifdef __MDP_SUPPORT__
		ARTBlogV3_Deliver_Article(content,GB_NULL);
#endif
	}
}/* 

/**********************************************************************
* 函数名称： GB_WG_HandleMenu
* 功能描述： 外部菜单处理函数
* 输入参数： smartdial界面：	如果焦点在拨号框或者选中通话记录 pNumber为当前选中或者输入电话号码;pContent:为空,storeIndex:为-1；
								如果选中时电话簿中联系人 pNumber为当前选中联系人电话号码;pContent:为空，storeIndex为当前选中联系人在电话簿中位置索引值；
*			 短信界面：			pNumber为当前输入电话号码;pContent:短信内容；storeIndex:为-1；
*            winguo导航界面：	pNumber为空;pContent:用户输入内容；storeIndex:为-1；
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
lenny           20110713						创建
***********************************************************************/
GB_VOID GB_WG_HandleMenu_ShareToWeibo(GB_U16* pUser, GB_U16* pData,GB_LONG command)
{
	GB_INT sum = 0;
	GB_WG_Share_To_WeiBo(pData);
}


GB_WINGUO_Menu_Map GB_winguo_MenuFunction_list[4] = {0};

/*--------------------------------------------------------------------
*
参数说明：
pMenuArry：添加菜单项类表，外部已分配内存；
selectType：添加菜单项时的选中类型。GB_WG_DIALBOX：拨号框；GB_WG_SMD：smartdial控件；GB_WG_ADDRESSBOX：短信地址框；
									GB_WG_CONTENTBOX:短信编辑框；GB_WG_WINGUOBOX:winguo输入框；GB_WG_WINGUODATE：winguo数据区。
countMax：最多添加菜单个数。
paramType：参数类型。GB_WG_PARAM_PHONENUMBER:电话号码；GB_WG_PARAM_CONTENT:输入框中内容

*
*----------------------------------------------------------------------*/
GB_INT GB_WG_Add_Menu_Fun(GB_WINGUO_Menu_Map *pMenuArry, GB_INT selectType , GB_INT countMax,GB_INT paramType)
{
	GB_INT MenuCount = 0;//实际的菜单项个数
	if (!pMenuArry)
	{
		return MenuCount;
	}
	switch(selectType)
	{
	case E_GB_WG_DIALBOX:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO_HIDE);
		pMenuArry[MenuCount].position = 5;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	case E_GB_WG_SMD:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO);
		pMenuArry[MenuCount].position = 4;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	case E_GB_WG_ADDRESSBOX:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO);
		pMenuArry[MenuCount].position = 4;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	case E_GB_WG_CONTENTBOX:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO_HIDE);
		pMenuArry[MenuCount].position = 4;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	case E_GB_WG_WINGUOBOX:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO_YES);
		pMenuArry[MenuCount].position = 1;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO_NO);
		pMenuArry[MenuCount].position = 4;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	case E_GB_WG_WINGUODATE:
		pMenuArry[MenuCount].selectTag = selectType;
		pMenuArry[MenuCount].pString = (GB_CPWSTR)get_string(STR_GB_WINGUO_NO);
		pMenuArry[MenuCount].position = 4;
		pMenuArry[MenuCount].pfun = GB_WG_HandleMenu_ShareToWeibo;
		MenuCount++;
		break;
	default:
		break;
	}
	if (MenuCount>countMax)
	{
		MenuCount = 0;
	}

	MenuCount = 0;

	return MenuCount;
}

/* ---------------------------------------------------------------------------- */
// GB_VOID GB_WG_Imc_vk_hide()  // 隐藏系统虚拟键盘接口
// {
// #ifdef __MMI_TOUCH_SCREEN__
// 	mmi_imc_pen_vk_hide();
// #endif
// }
// GB_BOOL GB_WG_IsSupportUseSysSms(GB_VOID)
// {
// #ifdef GB_WINGUO_USESYSSMS
// 	return GB_TRUE;
// #else
// 	return GB_FALSE;
// #endif
// }

// 判断是否中文短信
// GB_BOOL GB_WG_Is_Chinese_Sms(GB_U16 *pData)
// {
// 	GB_U16 buffer_len = 0;
// 	GB_U16 i = 0;
// 	if (pData)
// 	{
// 		buffer_len =  gb_wg_wcslen(pData);
// 		for (i = 0; i < buffer_len; i++)
// 		{
// 			if (pData[i] >= 0xFF)
// 			{
// 				return GB_TRUE;
// 			}
// 		}
// 		return GB_FALSE;
// 	}
// 	return GB_TRUE;
// }

// 判断短信多行是否可以继续输入文字 [9/9/2011 Leijinfu]   SRV_UC_TEXT_BUFFER_SIZE   
// OUT: *addContentLen  传入引用参数
// #ifdef GB_MTK_09APLAT
// 	#define GB_CN_TEXT_MAX_LEN (67 * MMI_SMS_MAX_MSG_SEG)
// 	#define GB_EN_TEXT_MAX_LEN ((MMI_SMS_MAX_MSG_SEG>5)?(153 * (MMI_SMS_MAX_MSG_SEG/2)):(153 * MMI_SMS_MAX_MSG_SEG))
// #else
// 	#include "smsprotsrv.h"
// 	#define GB_CN_TEXT_MAX_LEN (67 * SRV_SMS_MAX_SEND_SEG)
// 	#define GB_EN_TEXT_MAX_LEN ((SRV_SMS_MAX_SEND_SEG>5)?(153 * (SRV_SMS_MAX_SEND_SEG/2)):(153 * SRV_SMS_MAX_SEND_SEG))
// #endif
// 
// GB_BOOL GB_WG_Sms_Can_Continue_Input(GB_USHORT *pContent, GB_INT contentLen, 
// 										   GB_USHORT *pAddContent, GB_INT *addContentLen)
// {
// 	if (pContent && pAddContent && addContentLen)
// 	{
// 		GB_INT addTextLen = 0;
// 		addTextLen = *addContentLen;
// 		if (GB_WG_Is_Chinese_Sms(pAddContent)) // 添加的是中文
// 		{
// 			if (contentLen >= GB_CN_TEXT_MAX_LEN)
// 			{
// 				return GB_FALSE;
// 			}
// 			else if (contentLen + addTextLen > GB_CN_TEXT_MAX_LEN) //[2011/12/13 Liyong] 如果超出字符就返回FALSE
// 			{	
// 				// 如果超过限定字符，就需要计算截取长度
// 				*addContentLen = GB_CN_TEXT_MAX_LEN - contentLen;
// 				return GB_FALSE;
// 
// 			}
// 		}
// 		else  // 添加的是英文
// 		{
// 			if (GB_WG_Is_Chinese_Sms(pContent))  // 判断之前是否有中文
// 			{
// 				if (contentLen >= GB_CN_TEXT_MAX_LEN)
// 				{
// 					return GB_FALSE;
// 				}
// 				else if(contentLen + addTextLen > GB_CN_TEXT_MAX_LEN) 
// 				{
// 					// 如果超过限定字符，就需要计算截取长度
// 					*addContentLen = GB_CN_TEXT_MAX_LEN - contentLen;
// 					return GB_FALSE;    //[2011/12/13 Liyong]
// 				}
// 			}
// 			else
// 			{
// 				if (contentLen >= GB_EN_TEXT_MAX_LEN)	// 612需要根据平台替换
// 				{
// 					return GB_FALSE;
// 				}
// 				else if(contentLen + addTextLen > GB_EN_TEXT_MAX_LEN) 
// 				{
// 					// 如果超过限定字符，就需要计算截取长度
// 					*addContentLen = GB_EN_TEXT_MAX_LEN - contentLen;
// 					return GB_FALSE;//[2011/12/13 Liyong]
// 				}
// 			}
// 		}
// 	}
// 	return GB_TRUE;
// }

// GB_BOOL GB_WG_IsSupportWifi(GB_VOID)
// {
// #ifdef __MMI_WLAN_FEATURES__
// 	return GB_TRUE;
// #else
// 	return GB_FALSE;
// #endif
// }

// 获取wlan的当前状态
GB_WLAN_STATUS_ENUM GB_WG_GetWlanStatus(GB_VOID)
{
	GB_WLAN_STATUS_ENUM retStatus = GB_WLAN_STATUS_NONE;

	#ifdef __MMI_WLAN_FEATURES__
//	srv_dtcnt_wlan_status_enum  wlan_status = srv_dtcnt_wlan_status();
//	switch (wlan_status)
//	{
//		// 处于非激活的状态
// 	case SRV_DTCNT_WLAN_STATUS_INACTIVE:
// 		retStatus = GB_WLAN_STATUS_INACTIVE;
// 		break;
// 		// wifi被打开处于激活状态
// 	case SRV_DTCNT_WLAN_STATUS_ACTIVE:
// 		retStatus = GB_WLAN_STATUS_ACTIVE;
// 		break;
// 		// 无效的mac地址
// 	case SRV_DTCNT_WLAN_STATUS_INVALID_MAC:
// 		retStatus = GB_WLAN_STATUS_INVALID_MAC;
// 		break;
// 		// 已经链接到了热点
// 	case SRV_DTCNT_WLAN_STATUS_CONNECTED:
// 		retStatus = GB_WLAN_STATUS_CONNECTED;
// 		break;
// 	default:
// 		break;		
//	}
	#endif

	retStatus = GB_WLAN_STATUS_CONNECTED;
	return retStatus;
}

// 默认皮肤
GB_INT GB_WG_GetDefaultSkin(GB_VOID)
{
	return SKIN_BLUE;
}

//GB_USHORT GB_WG_g_SendSmsFlat = GB_SMS_SEND_DONE; // 记录发送短信状态
// 获取短信状态
// GB_SMS_SEND_FLAT_Type GB_WG_SMS_GetSendFlat(GB_VOID)
// {
// 	return GB_WG_g_SendSmsFlat;
// }
// 设置短信状态
// GB_VOID GB_WG_SMS_SetSendFlat(GB_SMS_SEND_FLAT_Type sendFlat)
// {
// 	GB_WG_g_SendSmsFlat = sendFlat;
// }

// 播放系统提示音
//#include "mmi_rp_vapp_sound_settings_def.h"
GB_VOID GB_WG_PlayTone(GB_VOID)
{
	srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);
// 	if(mdi_audio_is_resource_available(MDI_AUDIO_PLAY_STRING,NULL))
// 	{
// 		U8 *audio_data;
// 		U8 audio_type;
// 		U32 audio_len;
// 
// 		audio_data = (U8 *)get_audio(AUD_ID_VAPP_SND_SET_PREVIEW, &audio_type, &audio_len);
// 
// 		ASSERT(audio_data != NULL);
// 
// 		mdi_audio_play_string_with_vol_path(
// 			(void*)audio_data,
// 			audio_len,
// 			audio_type,
// 			MDI_AUDIO_PLAY_ONCE,
// 			NULL,
// 			NULL,
// 			MDI_AUD_VOL_MUTE(5),
// 			MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2)
// 			);
// 
// 	}

//	playRequestedTone(WARNING_TONE);
}

// 获取时间
GB_U32 GB_WG_GetTime()
{
	GB_U32 time;
	kal_get_time(&time);
	return time;
}


GB_VOID GBTrace_print(const GB_CHAR *psz,...)
{
	//#ifdef WIN32
	#ifdef GB_WINGUO_DEBUGTIME
	//#ifdef GB_WINGUO_DEBUG
	GB_CHAR tmp[512];
	va_list marker;
	GB_MEMSET(tmp,0,sizeof(tmp));
	va_start(marker, psz);   
	_vsnprintf(tmp,(sizeof(tmp)-3),psz,marker);
	tmp[GB_STRLEN(tmp)] = '\r';
	tmp[GB_STRLEN(tmp)] = 0x0a;	
	va_end(marker);
	// #ifdef WIN32
	// 	kal_print(tmp);
	// #else
	kal_prompt_trace(MOD_AUX,tmp);
	GB_file_write_append_chars("D:\\gb_log.txt", tmp);
	//#endif // WIN32
	//#endif // GB_WINGUO_DEBUG
	#endif
}



#ifdef GB_WINGUO_DEBUGTIME
// GB_U32 begin_tick = 0;
// GB_U32 end_tick = 0; 
GB_VOID GBTrace_get_time_print_begin(const GB_CHAR *psz,GB_U32* begin_tick)
{
	if (begin_tick)
	{
		*begin_tick = 0;
		kal_get_time(begin_tick);
		GBTrace_print("****************%s:begin_tick = %d", psz, *begin_tick);
	}
}
GB_VOID GBTrace_get_time_print_end(const GB_CHAR *psz,GB_U32* begin_tick,GB_U32* end_tick)
{
	if(begin_tick && end_tick)
	{
		GB_U32 lost_time = 0;
		*end_tick = 0;
		kal_get_time(end_tick);
		lost_time = *end_tick - *begin_tick;
		lost_time = kal_ticks_to_milli_secs(lost_time);
		GBTrace_print("________________%s:end_tick = %d, lost_time = %d milli_secs", psz, *end_tick, lost_time);
	}
}
#endif
#endif /* #ifdef __MMI_GB_WINGUO__ */


