/***************************************************************************
* File Name    :  GBIMEDef.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  
*                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Author       :  weizhiping
* Date         :  2010-06-08
* Purpose      :  输入法框架外部常量定义
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/
#ifndef __GBIME_DEF_H_
#define __GBIME_DEF_H_

#include "gbtype.h"
#include "gbdef.h"
#include "mmi_include.h"
#include "mmi_features.h"

#define GBIME_CFG_STATIC_DB					1	// 使用静态数据
#define GBIME_CFG_UDB_SUPPORT					1	// UDB自造词数据模块<
//#define GBIME_USE_GBK_DB						1    // 使用GBK字符集数据


#define __GB_0KEY_SPACE__


#ifndef GB_MICRO_OPTIMIZATION
#define GB_MICRO_OPTIMIZATION       1
#endif

#ifndef GBIMEAPI
#ifdef GBIMPORT
#define GBIMEAPI  __declspec(dllimport)
#else
#define GBIMEAPI	extern
#endif
#endif

/*!
 * \brief 编译单元内部使用的函数
 */
#define GBIMELOCAL		static
/*!
 * \brief 全局使用，但不对外公布的函数
 */
#define GBIMEGLOBAL 
/*!
 * \brief 对外公布的函数
 */
#define GBIMEEXPORT 

#define GBIME_MAX_DB_COUNT							50	///<最大语言数据个数
#define GBIME_DEF_MAX_CAND_WORD				    		9	///<默认最大候选词个数 < GB_MAX_CANDIDATES
#define GBIME_DEF_CHN_MAX_CAND_WORD				9	///<默认最大候选词个数 < GB_MAX_CANDIDATES
#define GBIME_DEF_SYLLABLE_MAX_CAND_WORD			9	///<默认最大候选词个数 < GB_MAX_CANDIDATES
#define GBIME_DEF_ENGINSH_MAX_CAND_WORD			9	///<默认最大候选词个数 < GB_MAX_CANDIDATES
	
///<输入法引擎参数配置(重要)
#ifdef GBIME_CFG_UDB_SUPPORT
	#define GBIME_UDB_UPDATE_FREQ		 				20 ///<更新频率，数据的修改次数大于这个值得时候，引擎就会调用fpUpdateFunction，一般来说这个值建议为10
#endif/*GBIME_CFG_UDB_SUPPORT*/

#define GBIME_FILENAME_LEN 							256

/*!
 * \brief GB功能配置选项宏定义
 */
#define GBIME_SWITCH_KEY								GBKEY_AMB_SPECIAL_B ///<GB无缝切换按键
#define GBIME_INTERPUNCTION_KEY						GBKEY_AMB_SPECIAL_A ///<GB标点符号按键
#define GBIME_INTERPUNCTION_CAND_DESIRE_ROW		2 ///<GB标点符号键候选行数
#define GBIME_INTERPUNCTION_CAND_COUNT_PER_ROW	(GBIME_DEF_MAX_CAND_WORD - 1) ///<GB标点符号键每行候选个数

#endif //__GBIME_DEF_H_
