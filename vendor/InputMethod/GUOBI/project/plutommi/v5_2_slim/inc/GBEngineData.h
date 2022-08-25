#ifndef __GBENGINE_DATA_H
#define __GBENGINE_DATA_H
#include "gbtype.h"
#include "gbdef.h"
#include "GBIMEDef.h"

/*
  * 	国笔数据文件
  *
  *	将数据根据对应国笔开启输入法宏进行职能加载，不必在修改国笔模块的脚本
  */
// 语言数据
#ifdef GBIME_CFG_STATIC_DB // 使用静态数据
	#ifndef _C166
	#define _huge
	#endif //_C166

#ifdef GBIME_USE_GBK_DB
	extern const unsigned long prv_gbkDataArray[];
#else
	#ifdef __MMI_GB_SM_CHINESE__   //简体中文数据
		extern const unsigned long prv_scDataArray[];
	#endif

	#ifdef __MMI_GB_TR_CHINESE__  //繁体中文数据
		extern const unsigned long prv_bpmf_dataArray[];
	#endif
#endif

#ifdef __MMI_GB_ENGLISH__  // 英文数据
	extern const unsigned long prv_enDataArray[];
#endif

#ifdef  __MMI_GB_ARABIC__  // 阿拉伯语数据
	extern const unsigned long prv_arDataArray[];
#endif

#ifdef  __MMI_GB_THAI__    //  泰语数据
	extern const unsigned long prv_thDataArray[];
#endif

#ifdef  __MMI_GB_GREEK__  	// 希腊语数据
	extern const unsigned long prv_elDataArray[];
#endif

#ifdef  __MMI_GB_TURKISH__ // 土耳其语数据
	extern const unsigned long  prv_trDataArray[];
#endif

#ifdef  __MMI_GB_VIETNAMESE__ 	// 越南语数据
	extern const unsigned long  prv_viDataArray[];
#endif

#ifdef  __MMI_GB_FRENCH__	 //法语数据
	extern const unsigned long  prv_frDataArray[];
#endif

#ifdef  __MMI_GB_RUSSIAN__	// 俄语数据
	extern const unsigned long  prv_ruDataArray[];
#endif

#ifdef  __MMI_GB_KAZAKH__	// 哈萨克数据
	extern const unsigned long  prv_kk_arDataArray[];
#endif

#ifdef  __MMI_GB_SPANISH__	// 西班牙语数据
	extern const unsigned long  prv_esDataArray[];
#endif

#ifdef  __MMI_GB_PORTUGUESE__	// 葡萄牙语数据
	extern const unsigned long  prv_ptDataArray[];
#endif

#ifdef  __MMI_GB_SA_SPANISH__	//南美 西班牙语数据
	extern const unsigned long  prv_essDataArray[];
#endif

#ifdef  __MMI_GB_SA_PORTUGUESE__	//南美 葡萄牙语数据
	extern const unsigned long  prv_ptsDataArray[];
#endif

#ifdef  __MMI_GB_GERMAN__	// 德语数据
	extern const unsigned long  prv_deDataArray[];
#endif

#ifdef  __MMI_GB_PERSIAN__	// 波斯语数据
	extern const unsigned long  prv_faDataArray[];
#endif

#ifdef  __MMI_GB_ITALIAN__	// 意大利语数据
	extern const unsigned long  prv_itDataArray[];
#endif

#ifdef  __MMI_GB_KOREAN__	// 韩语数据
	extern const unsigned long  prv_korean_DataArray[];
#endif

#ifdef __MMI_GB_HINDI__		//印地语数据
	extern const unsigned long  prv_hiDataArray[];
#endif

#ifdef __MMI_GB_BENGALI__		//孟加拉语数据
	extern const unsigned long  prv_bnDataArray[];
#endif

#ifdef __MMI_GB_TAMIL__		//泰米尔语数据
	extern const unsigned long  prv_tmDataArray[];
#endif


#ifdef __MMI_GB_MALAY__	//马来西亚语数据
	extern const unsigned long  prv_msDataArray[];
#endif

#ifdef __MMI_GB_BULGARIAN__	//保加利亚语数据
	extern const unsigned long  prv_bgDataArray[];
#endif

#ifdef __MMI_GB_INDONESIAN__	//印度尼西亚语数据
	extern const unsigned long  prv_idDataArray[];
#endif

#ifdef  __MMI_GB_CROATIAN__		// 克罗地亚语
	extern const unsigned long  prv_hrDataArray[];
#endif

#ifdef  __MMI_GB_CZECH__		// 捷克语
	extern const unsigned long prv_csDataArray[];
#endif

#ifdef  __MMI_GB_DANISH__		// 丹麦语
	extern const unsigned long  prv_daDataArray[];
#endif

#ifdef  __MMI_GB_DUTCH__		// 荷兰语
	extern const unsigned long  prv_nlDataArray[];
#endif

#ifdef  __MMI_GB_ESTONIAN__		// 爱沙尼亚语
	extern const unsigned long  prv_etDataArray[];
#endif

#ifdef  __MMI_GB_HUNGARIAN__	// 匈牙利语
	extern const unsigned long  prv_huDataArray[];
#endif

#ifdef  __MMI_GB_LATVIAN__		// 拉脱维亚语
	extern const unsigned long  prv_lvDataArray[];
#endif

#ifdef  __MMI_GB_LITHUANIAN__	// 立陶宛语
	extern const unsigned long  prv_ltDataArray[];
#endif

#ifdef  __MMI_GB_NORWEGIAN__	// 挪威语
	extern const unsigned long  prv_noDataArray[];
#endif

#ifdef  __MMI_GB_POLISH__		// 波兰语
	extern const unsigned long  prv_psDataArray[];
#endif

#ifdef  __MMI_GB_PUNJABI__		// 旁遮普语
	extern const unsigned long  prv_paDataArray[];
#endif

#ifdef  __MMI_GB_ROMANIAN__		// 罗马尼亚语
	extern const unsigned long  prv_roDataArray[];
#endif

#ifdef  __MMI_GB_SERBIAN__		// 塞尔维亚语
	extern const unsigned long  prv_srDataArray[];
#endif

#ifdef  __MMI_GB_SLOVAK__		// 斯诺伐克语
	extern const unsigned long  prv_skDataArray[];
#endif

#ifdef  __MMI_GB_SWAHILI__		// 斯瓦西里语
	extern const unsigned long  prv_swDataArray[];
#endif

#ifdef  __MMI_GB_SWEDISH__		// 瑞典语
	extern const unsigned long  prv_svDataArray[];
#endif

#ifdef  __MMI_GB_FILIPINO__		// 菲律宾语
	extern const unsigned long  prv_phDataArray[];
#endif

#ifdef  __MMI_GB_URDU__			// 乌尔都语
	extern const unsigned long  prv_urDataArray[];
#endif

#ifdef  __MMI_GB_HEBREW__		// 希伯来语
	extern const unsigned long  prv_heDataArray[];
#endif

#ifdef  __MMI_GB_UKRAINIAN__		// 乌克兰语
	extern const unsigned long  prv_ukDataArray[];
#endif

#ifdef  __MMI_GB_TELUGU__		// 泰卢固语
	extern const unsigned long  prv_teDataArray[];
#endif

#ifdef  __MMI_GB_FINNISH__		// 芬兰语
	extern const unsigned long  prv_fiDataArray[];
#endif

#ifdef  __MMI_GB_SLOVENIAN__	// 斯诺文尼亚语
	extern const unsigned long  prv_slDataArray[];
#endif

#ifdef  __MMI_GB_ALBANIAN__		// 阿尔巴尼亚语
	extern const unsigned long  prv_sqDataArray[];
#endif

#ifdef  __MMI_GB_ICELANDIC__		// 冰岛语
	extern const unsigned long  prv_isDataArray[];
#endif

#ifdef  __MMI_GB_GUJARATI__		// 古吉拉特语
	extern const unsigned long  prv_guDataArray[];
#endif

#ifdef  __MMI_GB_AZERBAIJANI__	// 阿塞拜疆语
	extern const unsigned long  prv_azDataArray[];
#endif

#ifdef  __MMI_GB_MACEDONIAN__	// 马其顿语
	extern const unsigned long  prv_mkDataArray[];
#endif

#ifdef  __MMI_GB_MARATHI__		// 马拉地语
	extern const unsigned long  prv_mrDataArray[];
#endif

#ifdef  __MMI_GB_AFRIKAANS__	// 南非语(布尔语)
	extern const unsigned long  prv_afDataArray[];
#endif

#ifdef  __MMI_GB_BASQUE__		// 巴斯克语
	extern const unsigned long  prv_euDataArray[];
#endif
//other language database....

/*
  *....................继续添加其他多语言数据，可参考上代码
  *
  */
#endif // GBIME_CFG_STATIC_DB

/*!
 * \brief 获取主UDB数据指针
 * \return 
 */
GBLPCVOID GBEngineData_GetMasterUDBData(void);

/*!
 * \brief 获取辅UDB数据指针
 * \return 
 */
GBLPCVOID GBEngineData_GetSlaveUDBData(void);

/*!
 * \brief 获取主UDB数据大小
 * \return 
 */
unsigned long GBEngineData_GetMasterUDBDataSize(void);

/*!
 * \brief 获取辅UDB数据大小
 * \return 
 */
unsigned long GBEngineData_GetSlaveUDBDataSize(void);

#endif //__GBENGINE_DATA_H