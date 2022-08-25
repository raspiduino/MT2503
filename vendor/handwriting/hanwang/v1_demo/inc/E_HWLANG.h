/*------------------------------------------------------------
  Copyright (c) 2006-2007 汉王科技股份有限公司
  
  模块名称:
		HWLANG.h

  创建人：
		秦建辉 jhqin@hanwang.com.cn

  产品名称:
		汉王笔 马蹄莲
------------------------------------------------------------*/

#ifndef __HWLANG_H
#define __HWLANG_H

#define HWLANG_LANGNUM	30	// 语言种类数目

/* -------Latin----------- */
#define HWLANG_Basic_Latin			0x0100	// 基本拉丁语

// 基于CodePage 1252
#define HWLANG_English				0x0101	// 英语
#define HWLANG_French				0x0102	// 法语
#define HWLANG_German				0x0103	// 德语
#define HWLANG_Italian				0x0104	// 意大利语
#define HWLANG_Dutch				0x0105	// 荷兰语
#define HWLANG_Luxembourgish		0x0106	// 卢森堡语
#define HWLANG_Danish				0x0107	// 丹麦语
#define HWLANG_Norwegian			0x0108	// 挪威语
#define HWLANG_Irish				0x0109	// 爱尔兰语
#define HWLANG_Portuguese			0x010A	// 葡萄牙语
#define HWLANG_Spanish				0x010B	// 西班牙语
#define HWLANG_Swedish				0x010C	// 瑞典语
#define HWLANG_Finnish				0x010D	// 芬兰语

// 基于CodePage 1250
#define HWLANG_Polish				0x0141	// 波兰语
#define HWLANG_Hungarian			0x0142	// 匈牙利语
#define HWLANG_Czech				0x0143	// 捷克语
#define HWLANG_Slovakian			0x0144	// 斯洛伐克语
#define HWLANG_Slovenian			0x0145	// 斯洛文尼亚语
#define HWLANG_Estonian				0x0146	// 爱沙尼亚语
#define HWLANG_Romanian				0x0147	// 罗马尼亚语
#define HWLANG_Croatian				0x0148	// 克罗地亚语

// 基于CodePage 1257
#define HWLANG_Latvian				0x0161	// 拉脱维亚语
#define HWLANG_Lithuanian			0x0162	// 立陶宛语

// 基于CodePage 1254
#define HWLANG_Turkish				0x0171	// 土耳其语

// 基于CodePage ISO 8859-3
#define HWLANG_Maltese				0x0181	// 马耳他语

/* ------------Cyrillic-------------- */
#define HWLANG_Basic_Cyrillic		0x0200	// 基本西里尔语

// 基于CodePage 1251
#define HWLANG_Russian				0x0201	// 俄语
#define HWLANG_Ukrainian			0x0202	// 乌克兰语
#define HWLANG_Belarusian			0x0203	// 白俄罗斯语
#define HWLANG_Bulgarian			0x0204	// 保加利亚语

/* ------------Greek--------------- */
#define HWLANG_Basic_Greek			0x0400	// 基本希腊语

// 基于CodePage 1253
#define HWLANG_Greek				0x0401	// 希腊语

#endif 
