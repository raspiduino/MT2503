/***************************************************************************
 * File Name    :  gbdef.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Author       :  chenbinghui
 * Date         :  2009-6-18
 * Purpose      :  v5 GB API 对外公布的所有宏定义
 * Version      :  V1.0
 * Last Changed List
 * Name         |   date   |  Discription
 ****************************************************************************/

#ifndef __GBIM_H__
#define __GBIM_H__

#include "gbdef.h"
#include "gbtype.h"

//remove start[2010-4-15 zhj]
//typedef GBU16							GBLANG;
//typedef GBU16							GBSUBLANG;
//typedef GBINT							GBEVENT;
//remove end[2010-4-15 zhj]

/*!
 * \defgroup Output	对外的结构体和枚举定义
 */
/*@{*/
/** 
 * \brief 引擎InputStruct使用的私有空间 16KB 
 * \note 这个值根据引擎的配置不一样可以由用户修改
 * - GB_ENGINE_PRIVATE_BUFFER_SIZE = max(Latin, Chn) + Syntax + Mars + 内部buf
 * - Latin = 1344
 * - Chn = 3752
 * - Syntax = 6240
 * - Mars = 2480

 * - 内部buf = 基本 + MMI + 火星文 + 整句
 * - 基本 = 1360
 * - MMI = 704
 * - 火星文 = 4
 * - 整句 =  4

 * - GB_ENGINE_PRIVATE_BUFFER_SIZE 8位对齐
 */
#define GB_ENGINE_PRIVATE_BUFFER_SIZE		(11960)//(6 * 1024)	

/** 
 * \brief 中英文引擎的交换区域所使用的空间，1.5KB，
 * \note 如果只使用Alphabetic，这个区域可以改为256，
		但是OEM厂商不能修改只能由国笔公司修改并且重新编译引擎
 */
//#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(1024 + 512)
//#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(256)//latin
#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(1024 + 512)//chn+latin

#define CUSTOM_LANGUGE_ID		0xE000
/** \enum GBLanguage
\brief language codes supported
*/	
#ifndef _C166
enum GBLanguageEnum
{
	GBL_NULL					     = 0x00,
	GBL_Afrikaans                    = 0x36,    ///< Afrikaans       南非荷兰语
	GBL_Albanian                     = 0x1C,    ///< Albanian        阿尔巴尼亚语
	GBL_Arabic                       = 0x01,    ///< Arabic          阿拉伯语
	GBL_Bengali                      = 0x0445,  ///< Bengali 孟加拉语
	GBL_Basque                       = 0x2D,    ///< Basque          巴斯克语
	GBL_Belarusian                   = 0x23,    ///< Belarusian/Belorussian      白俄罗斯语
	GBL_Bulgarian                    = 0x02,    ///< Bulgarian       保加利亚语
	GBL_Catalan                      = 0x03,    ///< Catalan         加泰罗尼亚语
	GBL_Chinese                      = 0x04,    ///< Chinese         简体中文
	GBL_Croatian                     = 0x041a,  ///< haj chg 和数据生成器保持一致 0x1A,    ///< Croatian        克罗地亚语
	GBL_Czech                        = 0x05,    ///< Czech           捷克语
	GBL_Danish                       = 0x06,    ///< Danish          丹麦语
	GBL_Dutch                        = 0x13,    ///< Dutch           荷兰语
	GBL_English                      = 0x09,    ///< English         英语
	GBL_Estonian                     = 0x25,    ///< Estonian        爱沙尼亚语
	GBL_Faeroese                     = 0x38,    ///< Faeroese        法罗语
	GBL_Farsi                        = 0x29,    ///< Farsi/Persian 波斯语
	GBL_Finnish                      = 0x0B,    ///< Finnish         芬兰语
	GBL_French                       = 0x0C,    ///< French          法语
	GBL_Gaelic                       = 0x3C,    ///< Gaelic          盖尔语
	GBL_German                       = 0x07,    ///< German          德语
	GBL_Greek                        = 0x08,    ///< Greek           希腊语
	GBL_Gujarati                     = 0x0447,  ///< Gujarati 古吉拉特语
	GBL_Hebrew                       = 0x0D,    ///< Hebrew          希伯来语
	GBL_Hindi                        = 0x39,    ///< Hindi           印地语
	GBL_Hungarian                    = 0x0E,    ///< Hungarian       匈牙利语
	GBL_Icelandic                    = 0x0F,    ///< Icelandic       冰岛语
	GBL_Indonesian                   = 0x21,    ///< Indonesian      印度尼西亚语
	GBL_Italian                      = 0x10,    ///< Italian         意大利语
	GBL_Kannada                      = 0x044b,  ///< Kannada 卡纳达语
	GBL_Japanese                     = 0x11,    ///< Japanese        日本语
	GBL_Korean                       = 0x12,    ///< Korean          韩语
	GBL_Khmer                        = 0x0453,  ///< Khmer 高棉语/柬埔寨语
	GBL_Kirgiz                       = 0x1001,//0x0440,  ///< Kirgiz 柯尔克孜语(阿拉伯字母)
	GBL_Kyrgyz                       = 0x0440,//CUSTOM_LANGUGE_ID + 1,  ///< Kyrgyz 吉尔吉斯语(俄文字母)
	GBL_Lao                          = 0x0454,  ///< Lao 老挝语
	GBL_Latvian                      = 0x26,    ///< Latvian         拉脱维亚语
	GBL_Lithuanian                   = 0x27,    ///< Lithuanian      立陶宛语
	GBL_Macedonian                   = 0x2F,    ///< Macedonian      马其顿语
	GBL_Malayalam                    = 0x044c,  ///< Malayalam 马拉雅拉姆语
	GBL_Malaysian                    = 0x3E,    ///< Malaysian       马来语
	GBL_Marathi                      = 0x044e,  ///< Marathi 马拉地语
	GBL_Myanmar                      = 0x0455,  ///< Myanmar/Burmese 缅甸语
	GBL_Maltese                      = 0x3A,    ///< Maltese         马耳他语
	GBL_Norwegian                    = 0x14,    ///< Norwegian       挪威语
	GBL_Pashto                       = 0x0463,  ///< Pashto 普什图语
	GBL_Polish                       = 0x15,    ///< Polish          波兰语
	GBL_Portuguese                   = 0x16,    ///< Portuguese      葡萄牙语
	GBL_Portuguese_SA                = 0x0416,  ///< Portuguese(South America) 南美葡萄牙语
	GBL_Punjabi                      = 0x0446,  ///< Punjabi 旁遮普语
	GBL_Romanian                     = 0x18,    ///< Romanian        罗马尼亚语
	GBL_Russian                      = 0x19,    ///< Russian         俄语
	GBL_Serbian                      = 0x081a,  ///< haj chg 和数据生成器保持一致0x1A,    ///< Serbian         塞尔维亚语
	GBL_Slovak                       = 0x1B,    ///< Slovak          斯洛伐克语
	GBL_Slovenian                    = 0x24,    ///< Slovenian       斯洛文尼亚语
	GBL_Sorbian                      = 0x2E,    ///< Sorbian         索布语
	GBL_Spanish                      = 0x0A,    ///< Spanish         西班牙语
	GBL_Spanish_SA                   = 0x2c0a,  ///< Spanish(South America) 南美西班牙语
	GBL_Sutu                         = 0x30,    ///< Sutu            
	GBL_Swahili                      = 0x0441,  ///< Swahili 斯瓦西里语,坦桑尼亚的官方语言
	GBL_Swedish                      = 0x1D,    ///< Swedish         瑞典语
	GBL_Tagalog                      = 0x3409,  ///< Tagalog/Philipino 菲律宾语
	GBL_Tamil                        = 0x0449,  ///< Tamil 泰米尔语
	GBL_Telugu                       = 0x044a,  ///< Telugu 泰卢固语
	GBL_Thai                         = 0x1E,    ///< Thai            泰语
	GBL_Tibetan                      = 0x0451,  ///< Tibetan 藏语
	GBL_Traditional_Chinese          = 0x0404,  ///< Traditional Chinese 繁体中文(台湾)
	GBL_Tsonga                       = 0x31,    ///< Tsonga/Xitsonga      齐聪加语
	GBL_Tswana                       = 0x32,    ///< Tswana          茨瓦纳语
	GBL_Turkish                      = 0x1F,    ///< Turkish         土耳其语
	GBL_Uighur                       = 0x0480,  ///< Uighur 维吾尔语
	GBL_Ukrainian                    = 0x22,    ///< Ukrainian       乌克兰语
	GBL_Urdu                         = 0x20,    ///< Urdu            乌尔都语
	GBL_Vietnamese                   = 0x2A,    ///< Vietnamese      越南语
	GBL_Xhosa                        = 0x34,    ///< Xhosa           科萨语
	GBL_Yiddish                      = 0x3D,    ///< Yiddish         意第绪语
	GBL_Zulu                         = 0x35,    ///< Zulu            祖鲁语
	GBL_Hausa                        = 0x0468,  ///< Hausa 豪萨语
	GBL_Uzbek                        = 0x0443,  ///< Uzbek 乌兹别克语(Latin字母)
	GBL_Yi                           = 0x0478,  ///< Yi 彝语
	GBL_Zhuang                       = 0x1000,//CUSTOM_LANGUGE_ID,  ///< Zhuang 壮语
	GBL_Traditional_Chinese_HK       = 0x0C04,  ///< Traditional Chinese 繁体中文(香港)
	GBL_Singapore_Chinese			 = 0x1004,  ///< Singapore Chinese 简体中文(新加坡)
	///<add haj 来自数据生成器
	GBL_Oriya						= 0x0448,  ///< Oriya 奥里雅语
	GBL_Assamese                    = 0x044D,  ///< Assamese 阿萨姆语
	GBL_Kazakh						= 0x043f,	///< 哈萨克语(斯拉夫字符)	Kazakh(Cyrillic)	
	GBL_Irish                       = 0x083c, ///< 爱尔兰语	Irish / Gaelic
	GBL_Galician                    = 0x0456, ///< 加里西亚语	Galician
	GBL_Nepali                      = 0x0461, ///< 尼泊尔语	Nepali
	GBL_MongolianCyrl               = 0x0450, ///< 蒙古语(斯拉夫字符)	Mongolian
	GBL_MongolianMong               = 0x0850, ///< 蒙古语(蒙古文)
	GBL_Armenian                    = 0x042b, ///< 亚美尼亚语	Armenian
	GBL_Bosnian						= (CUSTOM_LANGUGE_ID+2),	///<波斯尼亚语
	GBL_Hinglish					= (CUSTOM_LANGUGE_ID+3),	///<印地英语
	GBL_Kazakh_Arabic				= (CUSTOM_LANGUGE_ID+4),	///<哈萨克语（阿拉伯字符）	
	GBL_Mars         				= (CUSTOM_LANGUGE_ID+5),	///<火星文	
	///<end haj 来自数据生成器
	// start add [2011-8-10 Zhaokun]
	GBL_Oromo				= (CUSTOM_LANGUGE_ID+6), ///<奥罗莫语
	GBL_Kurdish_Latin		= (CUSTOM_LANGUGE_ID+7), ///<库尔德语
	GBL_Kurdish_Arabic		= (CUSTOM_LANGUGE_ID+8), ///<库尔德语
	GBL_Malagasy			= (CUSTOM_LANGUGE_ID+9), ///<马拉加斯语
	GBL_Twi					= (CUSTOM_LANGUGE_ID+10), ///<契维语
	GBL_Kongo				= (CUSTOM_LANGUGE_ID+11), ///<刚果语
	GBL_Luganda				= (CUSTOM_LANGUGE_ID+12), ///<卢干达语
	GBL_Sindhi				= (CUSTOM_LANGUGE_ID+13), ///<信德语
	GBL_Azerbaijan_Latin	= 0x042c, ///<阿塞拜疆语
	GBL_Igbo				= 0x0470, ///<伊博语
	GBL_Amharic				= 0x045e, ///<阿姆哈拉语
	GBL_Turkmen				= 0x0442, ///<土库曼语
	GBL_Yoruba				= 0x046a, ///<约鲁巴语
	GBL_Quechua_Bolivia		= 0x046b, ///<克丘亚語
	GBL_Quechua_Ecuador		= 0x086b, ///<克丘亚語
	GBL_Kinyarwanda			= 0x0487, ///<卢旺达语
	// end add [2011-8-10 Zhaokun]

	
	GBL_Last						 = CUSTOM_LANGUGE_ID + 0xFFF
};
#else
#define GBL_NULL					     0x00
#define GBL_Afrikaans                    0x36    ///< Afrikaans       南非荷兰语
#define GBL_Albanian                     0x1C    ///< Albanian        阿尔巴尼亚语
#define GBL_Arabic                       0x01    ///< Arabic          阿拉伯语
#define GBL_Bengali                      0x0445  ///< Bengali 孟加拉语
#define GBL_Basque                       0x2D    ///< Basque          巴斯克语
#define GBL_Belarusian                   0x23    ///< Belarusian/Belorussian      白俄罗斯语
#define GBL_Bulgarian                    0x02    ///< Bulgarian       保加利亚语
#define GBL_Catalan                      0x03    ///< Catalan         加泰罗尼亚语
#define GBL_Chinese                      0x04    ///< Chinese         简体中文
#define GBL_Croatian                     0x041a  ///< haj chg 和数据生成器保持一致 0x1A    ///< Croatian        克罗地亚语
#define GBL_Czech                        0x05    ///< Czech           捷克语
#define GBL_Danish                       0x06    ///< Danish          丹麦语
#define GBL_Dutch                        0x13    ///< Dutch           荷兰语
#define GBL_English                      0x09    ///< English         英语
#define GBL_Estonian                     0x25    ///< Estonian        爱沙尼亚语
#define GBL_Faeroese                     0x38    ///< Faeroese        法罗语
#define GBL_Farsi                        0x29    ///< Farsi/Persian 波斯语
#define GBL_Finnish                      0x0B    ///< Finnish         芬兰语
#define GBL_French                       0x0C    ///< French          法语
#define GBL_Gaelic                       0x3C    ///< Gaelic          盖尔语
#define GBL_German                       0x07    ///< German          德语
#define GBL_Greek                        0x08    ///< Greek           希腊语
#define GBL_Gujarati                     0x0447  ///< Gujarati 古吉拉特语
#define GBL_Hebrew                       0x0D    ///< Hebrew          希伯来语
#define GBL_Hindi                        0x39    ///< Hindi           印地语
#define GBL_Hungarian                    0x0E    ///< Hungarian       匈牙利语
#define GBL_Icelandic                    0x0F    ///< Icelandic       冰岛语
#define GBL_Indonesian                   0x21    ///< Indonesian      印度尼西亚语
#define GBL_Italian                      0x10    ///< Italian         意大利语
#define GBL_Kannada                      0x044b  ///< Kannada 卡纳达语
#define GBL_Japanese                     0x11    ///< Japanese        日本语
#define GBL_Korean                       0x12    ///< Korean          韩语
#define GBL_Khmer                        0x0453  ///< Khmer 高棉语/柬埔寨语
#define GBL_Kirgiz                       0x1001//0x0440  ///< Kirgiz 柯尔克孜语(阿拉伯字母)
#define GBL_Kyrgyz                       0x0440//CUSTOM_LANGUGE_ID + 1  ///< Kyrgyz 吉尔吉斯语(俄文字母)
#define GBL_Lao                          0x0454  ///< Lao 老挝语
#define GBL_Latvian                      0x26    ///< Latvian         拉脱维亚语
#define GBL_Lithuanian                   0x27    ///< Lithuanian      立陶宛语
#define GBL_Macedonian                   0x2F    ///< Macedonian      马其顿语
#define GBL_Malayalam                    0x044c  ///< Malayalam 马拉雅拉姆语
#define GBL_Malaysian                    0x3E    ///< Malaysian       马来语
#define GBL_Marathi                      0x044e  ///< Marathi 马拉地语
#define GBL_Myanmar                      0x0455  ///< Myanmar/Burmese 缅甸语
#define GBL_Maltese                      0x3A    ///< Maltese         马耳他语
#define GBL_Norwegian                    0x14    ///< Norwegian       挪威语
#define GBL_Pashto                       0x0463  ///< Pashto 普什图语
#define GBL_Polish                       0x15    ///< Polish          波兰语
#define GBL_Portuguese                   0x16    ///< Portuguese      葡萄牙语
#define GBL_Portuguese_SA                0x0416  ///< Portuguese(South America) 南美葡萄牙语
#define GBL_Punjabi                      0x0446  ///< Punjabi 旁遮普语
#define GBL_Romanian                     0x18    ///< Romanian        罗马尼亚语
#define GBL_Russian                      0x19    ///< Russian         俄语
#define GBL_Serbian                      0x081a  ///< haj chg 和数据生成器保持一致0x1A    ///< Serbian         塞尔维亚语
#define GBL_Slovak                       0x1B    ///< Slovak          斯洛伐克语
#define GBL_Slovenian                    0x24    ///< Slovenian       斯洛文尼亚语
#define GBL_Sorbian                      0x2E    ///< Sorbian         索布语
#define GBL_Spanish                      0x0A    ///< Spanish         西班牙语
#define GBL_Spanish_SA                   0x2c0a  ///< Spanish(South America) 南美西班牙语
#define GBL_Sutu                         0x30    ///< Sutu            
#define GBL_Swahili                      0x0441  ///< Swahili 斯瓦西里语坦桑尼亚的官方语言
#define GBL_Swedish                      0x1D    ///< Swedish         瑞典语
#define GBL_Tagalog                      0x3409  ///< Tagalog/Philipino 菲律宾语
#define GBL_Tamil                        0x0449  ///< Tamil 泰米尔语
#define GBL_Telugu                       0x044a  ///< Telugu 泰卢固语
#define GBL_Thai                         0x1E    ///< Thai            泰语
#define GBL_Tibetan                      0x0451  ///< Tibetan 藏语
#define GBL_Traditional_Chinese          0x0404  ///< Traditional Chinese 繁体中文(台湾)
#define GBL_Tsonga                       0x31    ///< Tsonga/Xitsonga      齐聪加语
#define GBL_Tswana                       0x32    ///< Tswana          茨瓦纳语
#define GBL_Turkish                      0x1F    ///< Turkish         土耳其语
#define GBL_Uighur                       0x0480  ///< Uighur 维吾尔语
#define GBL_Ukrainian                    0x22    ///< Ukrainian       乌克兰语
#define GBL_Urdu                         0x20    ///< Urdu            乌尔都语
#define GBL_Vietnamese                   0x2A    ///< Vietnamese      越南语
#define GBL_Xhosa                        0x34    ///< Xhosa           科萨语
#define GBL_Yiddish                      0x3D    ///< Yiddish         意第绪语
#define GBL_Zulu                         0x35    ///< Zulu            祖鲁语
#define GBL_Hausa                        0x0468  ///< Hausa 豪萨语
#define GBL_Uzbek                        0x0443  ///< Uzbek 乌兹别克语(Latin字母)
#define GBL_Yi                           0x0478  ///< Yi 彝语
#define GBL_Zhuang                       0x1000//CUSTOM_LANGUGE_ID  ///< Zhuang 壮语
#define GBL_Traditional_Chinese_HK       0x0C04  ///< Traditional Chinese 繁体中文(香港)
#define GBL_Singapore_Chinese			 0x1004  ///< Singapore Chinese 简体中文(新加坡)
#define GBL_Oriya						0x0448  ///< Oriya 奥里雅语
#define GBL_Assamese                    0x044D  ///< Assamese 阿萨姆语
#define GBL_Kazakh						0x043f	///< 哈萨克语(斯拉夫字符)	Kazakh(Cyrillic)	
#define GBL_Irish                       0x083c ///< 爱尔兰语	Irish / Gaelic
#define GBL_Galician                    0x0456 ///< 加里西亚语	Galician
#define GBL_Nepali                      0x0461 ///< 尼泊尔语	Nepali
#define GBL_MongolianCyrl               0x0450 ///< 蒙古语(斯拉夫字符)	Mongolian
#define GBL_MongolianMong               0x0850 ///< 蒙古语(蒙古文)
#define GBL_Armenian                    0x042b ///< 亚美尼亚语	Armenian
#define GBL_Bosnian						(CUSTOM_LANGUGE_ID+2)	///<波斯尼亚语
#define GBL_Hinglish					(CUSTOM_LANGUGE_ID+3)	///<印地英语
#define GBL_Kazakh_Arabic				(CUSTOM_LANGUGE_ID+4)	///<哈萨克语（阿拉伯字符）	
#define GBL_Mars         				(CUSTOM_LANGUGE_ID+5)	///<火星文
// start add [2011-8-10 Zhaokun]
#define GBL_Oromo				(CUSTOM_LANGUGE_ID+6) ///<奥罗莫语
#define GBL_Kurdish_Latin		(CUSTOM_LANGUGE_ID+7) ///<库尔德语
#define GBL_Kurdish_Arabic		(CUSTOM_LANGUGE_ID+8) ///<库尔德语
#define GBL_Malagasy			(CUSTOM_LANGUGE_ID+9) ///<马拉加斯语
#define GBL_Twi					(CUSTOM_LANGUGE_ID+10) ///<契维语
#define GBL_Kongo				(CUSTOM_LANGUGE_ID+11) ///<刚果语
#define GBL_Luganda				(CUSTOM_LANGUGE_ID+12) ///<卢干达语
#define GBL_Sindhi				(CUSTOM_LANGUGE_ID+13) ///<信德语
#define GBL_Azerbaijan_Latin	0x042c///<阿塞拜疆语
#define GBL_Igbo				0x0470///<伊博语
#define GBL_Amharic				0x045e///<阿姆哈拉语
#define GBL_Turkmen				0x0442///<
#define GBL_Yoruba				0x046a///<约鲁巴语
#define GBL_Quechua_Bolivia		0x046b///<克丘亚語
#define GBL_Quechua_Ecuador		0x086b///<克丘亚語
#define GBL_Kinyarwanda			0x0487///<卢旺达语
// end add [2011-8-10 Zhaokun]

#define GBL_Last						 CUSTOM_LANGUGE_ID + 0xFFF
#endif

/** \brief 方言枚举 */
enum GBSubLanguageEnum{
	GBL_Sub_Not_Spec							///<不是方言数据
	, GBL_Sub_Chinese							///<大陆地区子数据
	, GBL_Sub_Chinese_TW						///<中文台湾地区子数据
	, GBL_Sub_Chinese_HK						///<中文香港地区子数据
	, GBL_Sub_Chinese_Singapore					///<新加坡地区数据
	, GBL_Sub_Chinese_App						///<为某个应用指定的方言数据
	, GBL_Sub_Alphabetic_MDB = 0x40				///<Alphabetic的MDB
	, GBL_Sub_Chinese_Syntax = 0x80				///<特殊的数据：简体整句输入法数据
};

#ifndef __GBInputModeEnum__
#define __GBInputModeEnum__
/*!
* \brief 输入法模式
*/
enum GBInputModeEnum 
{
	GBIM_Null
	, GBIM_Pinyin = 1							///<数字键盘拼音输入法
	, GBIM_Stroke = 2							///<笔画输入法
	, GBIM_Cangjie = 3							///<Qwerty键盘的仓颉输入法
	, GBIM_Bopomofo = 4							///<数字键盘注音输入法
	, GBIM_Jyutping = 5							///<数字键盘粤音输入法
	, GBIM_Qwerty_Pinyin						///<Qwerty键盘的拼音输入法
	, GBIM_Explicit_Bopomofo					///<按键为注音字母的注音输入法
	, GBIM_Qwerty_Jyutping						///<Qwerty键盘的粤音输入法
	, GBIM_Syntax_Amb_Pinyin					///<数字键盘的整句拼音
	, GBIM_Syntax_Exp_Pinyin					///<全键盘的整句拼音
	, GBIM_Half_Qwerty_Pinyin					///<Half Qwerty键盘的拼音输入法
	, GBIM_Qwerty_Bopomofo						///<Qwerty键盘的注音输入法
	, GBIM_Chn_reserved1
	, GBIM_Chn_reserved2
	, GBIM_Chn_reserved3
	, GBIM_Chn_reserved4	
	, GBIM_Predictive							///<Numpad Predictive Alphabetic
	, GBIM_Explicit_Alphabetic					///<Explicit Alphabetic
	, GBIM_Qwerty_Alphabetic					///<Qwerty Alphabetic
	, GBIM_Half_Qwerty_Alphabetic				///<Half Qwerty Alphabetic, add by zhj 2009-8-21
	, GBIM_Alp_reserved1
	, GBIM_Alp_reserved2
	, GBIM_Alp_reserved3
	, GBIM_Alp_reserved4
	, GBIM_Alp_reserved5
	, GBIM_Number

	, GBIM_Korean							///<数字键盘韩文输入法
	//start[2010-7-27 zhj]
	, GBIM_Explicit_Korean					///<Explicit Korean
	, GBIM_Qwerty_Korean					///<Qwerty Korean
	, GBIM_Half_Qwerty_Korean				///<Half Qwerty Korean
	, GBIM_Korean_reserved1
	, GBIM_Korean_reserved2
	//end[2010-7-27 zhj]
	// Start  [2011-5-25 haj]
	, GBIM_Mars             				///<火星文输入法
	, GBIM_Mars_reserved1
	, GBIM_Mars_reserved2
	// end [2011-5-25 haj]
	, GBIM_Max
};
#endif

/*!
 * \brief 候选框中箭头的指示标记位定义
 */
enum GBTipArrow
{
	GBTA_Down					= 1			///<显示 下 箭头
	, GBTA_Up					= 2			///<显示 上 箭头
	, GBTA_Left					= 4			///<显示 左 箭头
	, GBTA_Right				= 8			///<显示 右 箭头
	, GBTA_Syllable_Left		= 0x10		///<Ambiguous Chinese only, 拼音翻页显示左箭头
	, GBTA_Syllable_Right		= 0x20		///<Ambiguous Chinese only, 拼音翻页显示右箭头
//	, GBTA_Show_Syllable_Arrow	= 0x40		///<Ambiguous Chinese only, 目前拼音候选个数大于1
	//start[2010-9-7 zhj]
	, GBTA_Syllable_Up		= 0x40		///<Ambiguous Chinese only, 拼音翻页显示上箭头
	, GBTA_Syllable_Down		= 0x80		///<Ambiguous Chinese only, 拼音翻页显下右箭头
	//end[2010-9-7 zhj]
};

/*! 当前输入状态 */
enum InputModeStatusFlag
{
	GBSF_Selected		= 1				///<(GBMMI)目前在选择下标状态，API层不输出此标记
	, GBSF_Shift		= 2				///<当前Shift键被按下，
	, GBSF_Caplock		= 4				///<当前Caplock键被按下，
	, GBSF_OpenCand		= 8				///<当前候选窗口打开，API层不输出此标记
	, GBSF_MoreCand		= 0x10			///<还有更多的候选
	, GBSF_MoreSyllable = (1 << 5)		///<还有更多拼音，在GBGetPagedSyllable API设置
	, GBSF_MultiTap		= (1 << 6)		///<当前处于MultiTap状态
	, GBSF_Switch_Lang  = (1 << 7)      ///<当前处于无缝切换状态 ljp

	////start[2010-4-26 zhj]
	//, GBSF_Keep_Shift_When_Input = (1<<8)		///<翻页过程保持首字母大写状态
	//, GBSF_Keep_Cap_When_Input =  (1<<9)		///<翻页过程中保持全大写状态
	////end[2010-4-26 zhj]
};

#ifndef __GBCandTypeEnum__
#define __GBCandTypeEnum__
enum GBCandTypeEnum{
	GBCT_Normal			///<根据按键序列得到的候选
	, GBCT_Associate	///<联想词语，
	, GBCT_Symbol		///<标点符号
	, GBCT_MultiTap_Lower_Cap	///<MultiTap 小写、大写字母候选
	, GBCT_MultiTap_Cap			///<大写的字母候选
	, GBCT_MultiTap_Lower		///<小写的字母候选
};
#endif

/*!
 * \brief Struct to output necessary information to OEM.
 * \note After each event function invoke, engine automatically update pOutputInfo.
 */
typedef struct tagGBOutputInfo
{
	GBU16							size;			///< 结构体的大小
	GBU16							nFirstCandIndex;///< 候选对应的第一个候选在所有候选的下标, 为0xFFFF表示非法值
	GBU16 							nCandNum;		/**< 候选项的个数 */
	/**< 需要上屏的字符串, 指向空字符串的时候表示没有需要上屏的字符, 
	用户上屏完成之后负责清空此字符串 */
	GBWCHAR	*						pUpScreenStr;	
	GBU32							nStatusFlag;	///<保存当前的状态,  com	
	GBLPCWCHAR 						pCandidates[GB_MAX_CANDIDATES];/** (output)候选字词*/
} GBOutputInfo, *pGBOutputInfo;
typedef GBOutputInfo _gb_far * lpGBOutputInfo;


/*!
 * \brief 辅助输出信息的结构体 
 */
typedef struct tagGBAuxInfo
{
	GBU16							size;		///< 结构体的大小
	GBU8 							nSyllableNum;/**< 当前页拼音音节的个数，拼音会根据GBSetPageOption
												 里面拼音的分页信息来分页， 如果需要返回所有的拼音候选，
												 则只需要把GBSetPageOption 中拼音的分页设置为返回GB_MAX_SYLLABLES个拼音即可*/	
	GBU8 							nSyllableIndex;			/**< 为选中的拼音音节的全局索引, 当前选择拼音的下标为nSyllableIndex - nSyllablePageStartIndex */	
	GBU8 							nSyllablePageStartIndex;/**< 当前页的拼音开始位置, 1表示第一个拼音，0表示模糊匹配，最大的有效值为音节个数  */	
	GBU8							nUnselectedInputStringLen; ///<中文还没有对应候选的输入串长度，等于gb_wcslen(pUnselectedInputString)
	GBU8							nStatus ;		///< 输入模式的具体状态,在GBMMI的API里面输出
	GBLPCWCHAR						pSyllables[GB_MAX_SYLLABLES];/**< (GBMMI)拼音音节 只是根据翻页信息, (GBAPI)所有可能的拼音*/
	GBWCHAR 						wStroke[GB_INPUT_BUFFER_LEN];/**< 笔画区内码串 */
	GBWCHAR 						wComponents[GB_COMPONET_BUFFER_LEN];/**< 部首区内码串 */
	GBLPCWCHAR						pOutputString;			///<中文输入法自造词的时候已经选择了的词语以及后面的输入串
	GBLPCWCHAR						pUnselectedInputString;	///<中文输入法自造词的时候还没有选择词语的输入串
	///(GBMMI)应当显示为Inline Edit的候选, 一般在MultiTap、MultiTap Symbols以及无候选框的Alphabetic模式有效
	GBLPCWCHAR						pCompStr;	
															///<等于pAuxInfo->pOutputString + pAuxInfo->nSelZiCount;

	GBU32							nArrowFlags; ///<标记根据当前的配置那个Arrow可以显示 一个或者多个\ref GBTipArrow的值。

	//以下输出仅限于多行候选的情况, 如全屏标点符号
	///每行行候选的开始位置, pRowStart 指向一个长度为GB_CAND_MAX_LINE_COUNT + 1的Byte数组\ref GB_CAND_MAX_LINE_COUNT
	GBPBYTE							pRowStart; //GBMMI使用	
	GBI8							nSelCol;		///<当前选择的列 GBMMI使用
	GBI8							nSelRow;		///<当前选择的行 GBMMI使用
	GBU8							nRowCount;		///<当前页有效的行数 GBMMI使用

	GBU8							nCandInputLen[GB_MAX_CANDIDATES];	///<中文候选的对应的按键序列长度
	GBU8							nSelZiCount;    ///<中文输入法自造词的时候已经选择了的词语的字数，也就是pOutputString字符串汉字部分的长度

	//start[2010-6-17 zhj]
	  GBU8							nExitSelectedStatus;	///<进入选择状态之前是什么状态
	//end[2010-6-17 zhj]
	  //start[2010-8-16 zhj]
	  GBI16							mCurSyllableRowIndex;		///<记录当前已经从引擎获取多少行音节
	  //end[2010-8-16 zhj]
	  // Start  [2011-4-26 haj]
	  GBLPCWCHAR						pszOutQwertyMap;        ///< Qwerty键盘存储把输入序列转换后的字符序列		  
	  // end [2011-4-26 haj]
}GBAuxInfo, *pGBAuxInfo;
typedef GBAuxInfo _gb_far * lpGBAuxInfo;

/*!
 * \brief A necessary parameter to almost all GB API.
 */
typedef struct tagGBInputStruct 
{
	GBLANG					nLang;			///<(out)当前操作的语言. 这个成员需要通过函数\ref GBSetCurLanguage设置，
	                                        /// 在绝大部分的函数调用之前都需要设置好语言的信息。否则会导致不确定的效果
	GBSUBLANG				nSubLang;		///<(out)当前的地区 
	GBWCHAR					inputString[GB_INPUT_BUFFER_LEN];	///<(in)输入序列
	GBU8					inputStringLen;	///<(in)输入序列的长度
	GBU8					nInputMode;		///<(out)当前输入模式
	GBU8					nCandType;		///<(in)需要的候选类型
	GBLPVOID				private_data;	///<(internal use)引擎内部的Buffer，用户无须关心
	GBU32					is_private_buffer[GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE / sizeof(GBU32)];
	GBU16					flags;			///<输入标记位
	GBU16					engine_private_buffer_size;		///<(in)engine_private_buffer实际的字节大小
	GBOutputInfo 			outputInfo;	///<(out)basic output info
	lpGBAuxInfo				pAuxInfo;		///<(out)GBMMI and Chinese additional output information.
	GBU32					engine_private_buffer[GB_ENGINE_PRIVATE_BUFFER_SIZE / sizeof(GBU32)];
} GBInputStruct;
typedef struct tagGBInputStruct _gb_far * pGBInputStruct;

//  [6/16/2009 abing]

/*!
 * \brief (回调函数)计算字符串点阵宽度的函数
 * \param pParam 用户定义参数，在GBSetPageOption函数中传入
 * \param pWString 需要计算字符串宽度的字符串
 * \return 字符串的宽度，0或者小于零表示失败
 * \author chenbinghui
 * \date 2009年7月20日
 */
typedef GBINT (* fpGetWStringWidth_t)(void * pParam, GBLPCWCHAR pWString);

/*!
 * \brief 存放某一类分页相关参数
 */
typedef struct tagGBPageOption 
{
	GBU16					nTotalWidthInPixel;		///<总共显示区域的宽度
	GBU8					nCharWidthInPixel;		///<字符宽度，当同时存在fpGetWStringWidth和nTotalWidthInPixel的限制，
													///<以及fpGetWStringWidth和nCharWidthInPixel两个限制条件的时候，优先使用fpGetWStringWidth。
	GBU8					nSplitWidthInPixel;		///<分隔符的宽度
	GBU16					nMaxCandCountPerPage;   ///<每一页候选的最大个数
}GBPageOption;
typedef GBPageOption _gb_far * lpGBPageOption;
typedef const GBPageOption _gb_far * lpcGBPageOption;

/*!
 * \brief 存放所有与分页有关的参数
 * \note 当参数为0的时候，表示该参数无效，分页的时候将不考虑该参数
 */
typedef struct tagGBGlobalPageOption 
{
	fpGetWStringWidth_t		fpGetWStringWidth;				///<计算字符串宽度的函数指针
	GBPVOID					pGetStringWidthParam;			///<计算字符串宽度的函数指针对应的第一个参数的值，用户自己定义   
	GBPageOption			mPageOption;					///<Alphabetic分页设置
	GBPageOption			mChnCandPageOption;				///<中文分页设置, 只在支持中文的版本有效
	GBPageOption			mSyllablePageOption;			///<Ambiguous中文音节分页设置, 只在支持中文的版本有效
}GBGlobalPageOption;
typedef GBGlobalPageOption _gb_far * lpGBGlobalPageOption;

/*!
 * \brief GBHandleEvent函数的参数之一
 */
typedef GBU32 GBEventParam;

/*!
 * \brief 表示一个语言数据. 当nSubLang 不是0的时候，说明这个数据需要依赖于
 *        nLang 对应的语言数据。
 */
typedef struct tagGBLDB
{
	GBLANG				nLang;		///<lang id
	GBSUBLANG			nSubLang;	///<sub lang id
	GBLPCVOID			pData;		///<data pointer
}GBLDB;

typedef GBLDB * pGBLDB;
typedef const GBLDB * pcGBLDB;
typedef const GBLDB _gb_far * lpcGBLDB;

/*!
 * \brief GB统一的版本号，为4个2位的整数。
 */
typedef struct tagGBVersion
{
	GBU8				v1;		///<版本号的第1个数字
	GBU8				v2;		///<版本号的第2个数字
	GBU8				v3;		///<版本号的第3个数字
	GBU8				v4;		///<版本号的第4个数字
}GBVersion;

/** \brief 各个语言的自造词提示符 */
typedef struct tagGBAlpUAWTip
{
	GBLANG				nLang;				///<Tips的语言
	GBLPCWCHAR			pszOKToSpell;		///<提示用户是否开始拼写单词，长度不能超过31个Unicode
	GBLPCWCHAR			pszAddConfirm;		///<用户拼完单词，提示用户是否添加，长度不能超过31个Unicode
} GBAlpUAWTip;
typedef GBAlpUAWTip _gb_far * lpGBAlpUAWTip;
typedef const GBAlpUAWTip _gb_far * lpcGBAlpUAWTip;

//change start[2010-7-12 zhj]
///** \brief 语言是否使用中文引擎 */
//#define LANG_USE_CHINESE_ENGINE(l)		\
//	((l) == GBL_Chinese || (l) == GBL_Traditional_Chinese \
//	|| (l) == GBL_Korean || (l) == GBL_Traditional_Chinese_HK || (l) == GBL_Singapore_Chinese)

/** \brief 语言是否使用中文引擎 */
#define LANG_USE_CHINESE_ENGINE(l)		\
	((l) == GBL_Chinese || (l) == GBL_Traditional_Chinese \
	|| (l) == GBL_Traditional_Chinese_HK || (l) == GBL_Singapore_Chinese)
//change end[2010-7-12 zhj]

//start[2010-7-12 zhj]
/** \brief 语言是否使用韩文引擎 */
#define LANG_USE_KOREAN_ENGINE(l)		\
	((l) == GBL_Korean)
//end[2010-7-12 zhj]

// Start add [2011-5-25 haj]
/** \brief 语言是否使用火星文引擎 */
#define LANG_USE_MARS_ENGINE(l)		\
	((l) == GBL_Mars)
// end [2011-5-25 haj]

/** \brief 语言是否使用Alphabetic引擎 */
//change start[2010-7-12 zhj]
//#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l))
// Start modify [2011-5-25 haj]
//#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l) && !LANG_USE_KOREAN_ENGINE(l))
#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l) && !LANG_USE_KOREAN_ENGINE(l) && !LANG_USE_MARS_ENGINE(l))
// end [2011-5-25 haj]
//change end[2010-7-12 zhj]

/** \brief 输入模式是否使用Alphabetic引擎 */
#define INPUT_MODE_USE_ALP_ENGINE(im)	\
	((im) == GBIM_Predictive || (im) == GBIM_Explicit_Alphabetic \
	 || (im) == GBIM_Qwerty_Alphabetic ||(im) == GBIM_Half_Qwerty_Alphabetic)

/** \brief 输入模式是否使用中文引擎 */
#define INPUT_MODE_USE_CHN_ENGINE(im)	\
	((im) == GBIM_Pinyin || (im) == GBIM_Stroke || (im) == GBIM_Cangjie \
	 || (im) == GBIM_Bopomofo || (im) == GBIM_Jyutping /* haj del 20110622|| (im) == GBIM_Korean*/ \
	 || (im) == GBIM_Qwerty_Pinyin || (im) == GBIM_Explicit_Bopomofo || (im) == GBIM_Qwerty_Jyutping \
	 || (im) == GBIM_Syntax_Exp_Pinyin || (im) == GBIM_Half_Qwerty_Pinyin \
	 || (im) == GBIM_Qwerty_Bopomofo \
	 || (im) == GBIM_Syntax_Amb_Pinyin /*!haj add 20110622*/)

/** \brief 输入模式是否是模糊的中文输入法，模糊的中文输入法才存在拼音的候选 */
#define INPUT_MODE_IS_AMB_CHN(im)	\
	((im) == GBIM_Pinyin || (im) == GBIM_Bopomofo || (im) == GBIM_Jyutping \
	|| (im) == GBIM_Syntax_Amb_Pinyin || (im) == GBIM_Half_Qwerty_Pinyin \
	|| (im) == GBIM_Qwerty_Bopomofo)

/** \brief 输入模式是否是QWERTY的中文输入法，QWERTY的中文输入法需要显示fullOutputString内容 */
#define INPUT_MODE_IS_QWERTY_CHN(im)	\
	((im) == GBIM_Cangjie || (im) == GBIM_Syntax_Exp_Pinyin || (im) == GBIM_Qwerty_Pinyin \
	|| (im) == GBIM_Explicit_Bopomofo || (im) == GBIM_Qwerty_Jyutping || (im) == GBIM_Qwerty_Bopomofo)

/** \brief 输入模式是否是qwerty或者explicit */
#define INPUT_MODE_IS_QWERTY_OR_EXPLICIT(im)	\
	(INPUT_MODE_IS_QWERTY_CHN(im) \
	|| (im) == GBIM_Qwerty_Alphabetic || (im) == GBIM_Explicit_Alphabetic)

/** \brief 当前的pGBIS里面的语言以及输入模式是否是使用Alphabetic引擎 */
#define GBIS_USE_ALP_ENGINE(p)		\
	(LANG_USE_ALP_ENGINE((p)->nLang) && INPUT_MODE_USE_ALP_ENGINE((p)->nInputMode))

/** \brief 当前的pGBIS里面的语言以及输入模式是否是使用Chinese引擎 */
#define GBIS_USE_CHN_ENGINE(p)		\
	(LANG_USE_CHINESE_ENGINE((p)->nLang) && INPUT_MODE_USE_CHN_ENGINE((p)->nInputMode))

/** \brief 当前状态下面往后查找是否有更多候选 */
#define GBIS_HAVE_MORE_CAND(p)	\
	((p)->outputInfo.nStatusFlag & GBSF_MoreCand)

/** \brief 输入法是否使用整句引擎 */
#define GBIS_USE_SYNTAX_ENGINE(im)	\
	((im) == GBIM_Syntax_Amb_Pinyin || (im) == GBIM_Syntax_Exp_Pinyin)


/** \brief 普通的字符按键 */
#define EVENT_IS_NORMAL_CHAR_KEY(e)	\
	(((e) >= GBKEY_0 && (e) <= GBKEY_9) \
	|| ((e) >= GBKEY_A && (e) <= GBKEY_Z) \
	|| ((e) >= GBKEY_BPMF_B && (e) <= GBKEY_BPMF_IU))


/** \brief 当前状态下是否可能存在音节候选 */
#define GBIS_HaveSyllableSelection(p) \
	((p)->nCandType == GBCT_Normal && (p)->inputStringLen > 0 && INPUT_MODE_IS_AMB_CHN((p)->nInputMode))

/** \brief 输入串是否已经更新 */
#define GBIS_InputStringUpdated(p)		((p)->flags & GBIS_INPUT_STRING_UPDATED)

/** \brief 设置GBIS的Updated Flags，更改pGBIS->inputString需要调用 */
#define GBIS_SetInputStringUpdated(p)	((p)->flags |= GBIS_INPUT_STRING_UPDATED)

/** \brief 清除GBIS的Updated Flags */
#define GBIS_ClearInputStringUpdated(p)	((p)->flags &= ~(GBU16)GBIS_INPUT_STRING_UPDATED)

/** \brief 用户使用SelectSyllable更新了音标的选择 */
#define GBIS_SyllableIndexUpdated(p)	((p)->flags & GBIS_SYLLABLE_INDEX_UPDATED)

//Add by ZhaoKun at 2011/1/12 9:31:05 [Start]
/** \brief 设置音调更新 */
#define GBIS_SetSyllableToneUpdated(p)	((p)->flags |= GBIS_SYLLABLE_TONE_UPDATED)
//Add by ZhaoKun at 2011/1/12 9:31:05 [End]

#define GBIS_UpdateFlags (GBIS_INPUT_STRING_UPDATED | GBIS_SYLLABLE_INDEX_UPDATED | GBIS_SELECTED_CANDIDATE | GBIS_SYLLABLE_TONE_UPDATED)
#define GBIS_ClearUpdatedFlags(p)		\
	((p)->flags &= ~(GBU16)GBIS_UpdateFlags)

#define GBIS_HaveUpdateFlag(p)	((p)->flags & GBIS_UpdateFlags)

/** \brief 音节下标是否已经被更新 */
#define GBIS_HaveUpdateSyllableFlag(p)		((p)->flags & (GBIS_INPUT_STRING_UPDATED | GBIS_SELECTED_CANDIDATE))

/** \brief 当前是否MultiTap输入法 */
#define GBIS_IsMultiTapInputMode(p)			((p)->nCandType == GBCT_MultiTap_Lower_Cap \
		|| (p)->nCandType == GBCT_MultiTap_Cap \
		|| (p)->nCandType == GBCT_MultiTap_Lower)
/** \brief 是否存在更多的候选 */
#define GBIS_HaveMoreCand(p)		((p)->outputInfo.nStatusFlag & GBSF_MoreCand)
/** \brief 是否存在更多的音节 */
#define GBIS_HaveMoreSyllable(p)	((p)->outputInfo.nStatusFlag & GBSF_MoreSyllable)
/** \brief 用于GBNextPageCandidate的第二个参数 */
#define GBIS_GetNextPageStart(p)	((p)->outputInfo.nFirstCandIndex + (p)->outputInfo.nCandNum)
/** \brief 用于GBPrevPageCandidate的第二个参数 */
#define GBIS_GetPrevPageEnd(p)		((p)->outputInfo.nFirstCandIndex - 1)

/** \brief 当前状态是否能够下翻页 */
#define GBIS_HaveNextPage(p)			GBIS_HaveMoreCand(p)
/** \brief 当前状态是否能够上翻页 */
#define GBIS_HavePrevPage(p)			((p)->outputInfo.nFirstCandIndex > 0 && (p)->outputInfo.nFirstCandIndex != 0xFFFF)

/** \brief 中文输入模式 */
#define GBIS_Is_Chn_IM(p)			((p)->nInputMode >= GBIM_Pinyin && (p)->nInputMode <= GBIM_Chn_reserved4)

/** \brief Alphabetic输入模式 */
#define GBIS_Is_Alp_IM(p)			((p)->nInputMode >= GBIM_Predictive && (p)->nInputMode <= GBIM_Alp_reserved5)

/** \brief Alphabetic输入模式 */
#define GBIS_Is_Korean_IM(p)			((p)->nInputMode >= GBIM_Korean && (p)->nInputMode <= GBIM_Half_Qwerty_Korean)

/** \brief 当前状态是否显示候选框 */
#define GBIS_IS_CAND_OPEN(p)		((p)->outputInfo.nStatusFlag & GBSF_OpenCand)

/** \brief 候选是否处于选择状态 */
#define GBIS_IS_CAND_SELECTED(p) ((p)->outputInfo.nStatusFlag & GBSF_Selected)

/** \brief 判断当前按键是否是注音音调按键 Zhaokun 2011-1-12 add */
#define IS_BPMF_TONE_KEY(evt)	((evt) == GBKEY_BPMF_TONE_NULL \
	|| (evt) == GBKEY_BPMF_TONE_1 \
	|| (evt) == GBKEY_BPMF_TONE_2 \
	|| (evt) == GBKEY_BPMF_TONE_3 \
	|| (evt) == GBKEY_BPMF_TONE_4 \
	|| (evt) == GBKEY_BPMF_TONE_5)

// start add [ 2011-3-8 haj for Alpha GBCT_Associate]
/** \brief 判断当前是否是Alpha输入法联想状态下*/
#define GBIS_IS_ALP_ASSOCIATE(p) \
	(GBIS_USE_ALP_ENGINE((p)) && GBCT_Associate == (p)->nCandType)

/** \brief 判断当前是否是Alpha输入法联想功能是否打开*/
#define GBIS_ALP_ASSOCIATE_OPEN(p) \
	(GBIS_USE_ALP_ENGINE((p)) && HAVE_OPTION((p), GBFO_Alp_Open_Associat))

/** \brief 清楚输入串内容 */
#define GBIS_CLEAR_INPUT_STRING(p) \
	(p)->inputString[0] = 0; \
	(p)->inputStringLen = 0;	
// end add [ 2011-3-8 haj ]
// start add [2011-5-10 haj]
/*!
  * \brief 是否需要Alpha单字母候选配置
  * \brief 因为Explicit候选中不存在单个字母候选大小写同时存在的情况，不应受GBFO_Alp_Get_Only_Lower 和 GBFO_Alp_Get_Only_Cap配置控制
  */
	// start add [2011-3-10 haj for Alpha GBCT_Associate]
	// start GBIM_Explicit_Alphabetic 输入串长度为1和大于1都应该允许大小写切换 [2011-5-10 haj]
#define GBIS_IS_NEED_ALP_ONLY_CONFIG(p) \
	(!GBIS_IS_ALP_ASSOCIATE(p) \
	&& (p)->nInputMode != GBIM_Explicit_Alphabetic \
	&& (p)->inputStringLen == 1)
	// end add [2011-3-10 haj]
	// end  [2011-5-10 haj]
// end [2011-5-10 haj]
// Start add [2011-5-31 haj]
/** \brief 判断当前是否是Alpha输入法联想功能是否打开*/
#define GBIS_IS_OPEN_CHN_2_MARS(p) \
	(INPUT_MODE_USE_CHN_ENGINE((p)->nInputMode) && (HAVE_OPTION((p), GBFO_Open_Chn_2_Mars)))
// end [2011-5-31 haj]
// Start Add [2011-8-2 haj]
/** \brief 清楚outputInfo.pUpScreenStr 内容，同事清楚EHF_UPSCREEN标志 */
#define GBIS_CLEAN_UPSCREENSTR(p) \
	(p)->outputInfo.pUpScreenStr = NULL; \
	IMS(p)->nEventHandleFlag &= ~EHF_UPSCREEN;
// end [2011-8-2 haj]
/*@}*/

#endif

