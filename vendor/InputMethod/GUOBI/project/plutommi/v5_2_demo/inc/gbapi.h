/***************************************************************************
 * \file        :  gbapi.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Author       :  chenbinghui
 * Date         :  2009年6月18
 * Purpose      :  v5 GB API 外部使用头文件，包括所有API的声明
 * Version      :  V0.1
 * Last Changed List
 * Name  fanbo       |   date  2010-03-16 |  Discription 规范注释内容
 ****************************************************************************/

#ifndef __GB_API_H__
#define __GB_API_H__

#include "gbdef.h"
#include "gbtype.h"
#include "gbim.h"

#ifndef GBAPI
#ifdef GBIMPORT
#define GBAPI  __declspec(dllimport)
#elif defined(Win32_DLL)
#define GBAPI  __declspec(dllexport)
#else
#define GBAPI	extern
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*!
	 * \defgroup Initialization 引擎初始化
	 */
	/*@{*/
	
	/*! \example GBInputStructGetPrivateBufferUsedSize
	 */
	/*!
	 * \brief 检查引擎中pGBIS->engine_private_buffer中需要的长度（in byte）
	 * \return pGBIS->engine_private_buffer中需要字节长度
	 * \note 注意：pGBIS->engine_private_buffer为unsigned long类型，设置此数组长度时应该将字节长度除以4
	 * \author chenbinghui
	 * \date 2009年11月19日
	 */
	GBAPI GBINT GBInputStructGetPrivateBufferUsedSize(void);
	
	/*! \example GBInitialize
	 */
	/*!
	 * \brief 启动Guobi输入法引擎，必须在调用功能API接口前被调用，运行中仅须调用一次
	 * \param pGBIS (in)不能为NULL，会检查其中的engine_private_buffer以及outputInfo，如果不符合要求将返回失败
	 * \param pLDBs (in)不能为NULL，但GBInitialize不会检查每一个LDB指向的数据的内容是否有效
	 * \param nLDBCount (in)不能超过GB_LDB_MAX_COUNT，也不能小于等于0
	 * \return 
		- GBOK：成功初始化
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：参数错误
		- GBE_API_ALREADY_INIT：重复初始化
		- GBE_API_ENGINE_BUFFER_NOT_ENOUGH：空间不够
	 * \note 仅需要启动输入法引擎一次，并且在所有功能API使用前被调用
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBInitialize(pGBInputStruct pGBIS, lpcGBLDB pLDBs, GBINT nLDBCount);

	/*! \example GBIsInited
	 */
	/*!
	 * \brief 检测国笔引擎是否启动成功
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：已经初始化
		- GB_Failed：没有初始化
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBIsInited(pGBInputStruct pGBIS);

	/*! \example GBTerminate
	 */
	/*!
	 * \brief 关闭国笔输入法引擎。调用此接口后，如果不重新启动国笔引擎，所有API接口将不可用
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBOK：成功关闭
		- GBE_API_GBIS_IS_NULL：pGBIS为空
	 * \note 关闭国笔引擎时，把有细胞词库(MDB)、自造词库(UDB)将被移除，启动引擎后必须重新被加载
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBTerminate(pGBInputStruct pGBIS);

	/*! \example GBReset
	 */
	/*!
	 * \brief 重置国笔输入法引擎内部状态，卸载无缝切换包装器，恢复默认候选方式
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功返回
	 * \note 仅重置引擎API层次的状态，对GBMMI层的状态无效
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBReset(pGBInputStruct pGBIS);

	/*! \example GBSetCurLanguage
	 */
	/*!
	 * \brief 设置国笔输入法引擎当前使用语言
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nLangID (in)需要设置的语言，语言类型参考gbim.h文件中GBLanguageEnum定义
	 * \param nSubLangID (in)需要设置的语言区域，目前只有中文需要设置语言区域，语言区域参考gbim.h文件中GBSubLanguageEnum定义
	 * \return
		- GBOK：成功设置当前使用语言
		- other：参考gbdef.h文件中GBReturnEnum定义
	 * \note nSubLangID默认值为0，表示不需要设置语言区域
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetCurLanguage(pGBInputStruct pGBIS, GBINT nLangID, GBINT nSubLangID);

	/*! \example GBSetInputMode
	 */
	/*!
	 * \brief 设置国笔输入法引擎当前使用的输入模式,如果有GBMMI层，会同步GBMMI状态
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nInputMode (in)设置当前输入模式，输入模式类型参考gbim.h文件中GBInputModeEnum定义
	 * \note 对于MultiTap输入法，请将pGBIS->nCandType设置为正确的方式，再调用此函数设置InputMode为相应的键盘输入模式，如：
		  - 设置NumPad键盘先小写后大写的输入法方式 
		  - pGBIS->nCandType = GBCT_MultiTap_Lower_Cap;
		  - GBSetInputMode(pGBIS, GBIM_Predictive);
		  - 如果调用顺序不对，会导致GBMMI不正确
	 * \return
		 - GBOK：success
		 - GB_NO_LDB：语言列表中没有不存在该nLangID的语言
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetInputMode(pGBInputStruct pGBIS, GBINT nInputMode);

	/*! \example GBMMISetInputMode
	 */
	/*!
	 * \brief 设置国笔输入法引擎当前使用的输入模式。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nInputMode (in)设置当前输入模式，输入模式类型参考gbim.h文件中GBInputModeEnum定义
	 * \note 这个接口仅限GBMMI使用
		  - 对于MultiTap输入法，请将pGBIS->nCandType设置为正确的方式，再调用此函数设置InputMode为相应的键盘输入模式，如：
		  - 设置NumPad键盘先小写后大写的输入法方式 
		  - pGBIS->nCandType = GBCT_MultiTap_Lower_Cap;
		  - GBSetInputMode(pGBIS, GBIM_Predictive);
		  - 如果调用顺序不对，会导致GBMMI不正确
	 * \return
		 - GBOK：success
		 - GB_NO_LDB：语言列表中没有不存在该nLangID的语言
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author huanjin
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBMMISetInputMode(pGBInputStruct pGBIS, GBINT nInputMode);


	/*@}*/

	/*!
	 * \defgroup Configuration	API引擎配置
	 */
	/*@{*/
	/*! \example GBSetCandidateMaxCount
	 */
	/*!
	 * \brief 设置国笔输入法引擎最大候选数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nCandidateMaxConut (in)设置最大返回候选数，与指定给国笔引擎的候选缓冲区相关
	 * \note 调用GBGetCandidatesCount()将返回当前引擎实际匹配候选数，默认为100，指定的最大候选数不能大于候选缓冲区，否则会产生溢出异常
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功设置最大候选数
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetCandidateMaxCount(pGBInputStruct pGBIS, GBINT nCandidateMaxConut);

	/*! \example GBGetCandidateMaxCount
	 */
	/*!
	 * \brief 获取国笔输入法引擎最大候选数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCandidateMaxConut (out)返回最大返回候选数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：pCandidateMaxConut为空
		- GBOK：成功返回
	 * \note 调用GBGetCandidatesCount()将返回当前引擎实际匹配候选数，默认为100
	 * \author chenbinghui
	 * \date 2009年7月17日
	*/
	GBAPI GBRETURN GBGetCandidateMaxCount(pGBInputStruct pGBIS, GBINT * pCandidateMaxConut);

	/*! \example GBSetLanguageSymbols
	 */
	/*!
	 * \brief 设置国笔输入法引擎当前语言标点符号
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pOEMSymobls (in)OEM自定义的标点符号，应该指向一个全局有效的地址，不能是局部地址
	 * \return 
	 	- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前语言不支持的函数
		- EB_OK：成功设置标点符号
	 * \note pOEMSymobls是一个全局标点符号列表，每一个字符为一个标点符号，标点符号之间没有分割符。
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetLanguageSymbols(pGBInputStruct pGBIS, GBLPCWCHAR pOEMSymobls);

	/*! \example GBSetPageOption
	 */
	/*!
	 * \brief 设置国笔输入法引擎分页参数，可设置拼音注音、候选、Alphabetic的每页返回候选数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pOptions (in)用户的分页设置
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_GET_STR_WIDTH_FP：字符串宽度获取函数有误
		- GBE_API_INVALID_ALP_PO：Alphabetic候选分页选项无效
		- GBE_API_INVALID_CHN_PO：中文候选分页选项无效
		- GBOK：成功设置分页参数
	 * \note 默认中文引擎一页返回6个候选，Alphabetic一页返回1个候选，拼音注音等返回2个候选。如果只需要修改部分设置，可以先使用GBGetPageOption获取当前的设置
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetPageOption(pGBInputStruct pGBIS, const GBGlobalPageOption * pOptions);

	/*! \example GBGetPageOption
	 */
	/*!
	 * \brief 获取国笔输入法引擎当前分页参数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pOptions (out)当前分页参数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：success
	 * \sa GBSetPageOption
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBGetPageOption(pGBInputStruct pGBIS, GBGlobalPageOption * pOptions);

	/*! \example GBSetMaxTotalPages
	 */
	/*!
	 * \brief 设置国笔输入法引擎最大候选页数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nMaxPageCount (in)最大的翻页个数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功设置
	 * \note 设置GBGetCandPageCount()函数返回的最大值，默认为0，表示返回所有的页计数。需要注意的是，如果在启用GBMMI的多行候选功能，这个函数实际返回的是行总数。
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetMaxTotalPages(pGBInputStruct pGBIS, GBINT nMaxPageCount);

	/*! \example GBGetMaxTotalPages
	 */
	/*!
	 * \brief 获取国笔输入法引擎当前最大候选页数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pMaxPageCount (out)最大的翻页个数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：参数有误
		- GBOK：成功返回
	 * \note 默认为0，表示返回所有的页计数。
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBGetMaxTotalPages(pGBInputStruct pGBIS, GBINT * pMaxPageCount);

	/*! \example GBSetCandidateMaxWordLength
	 */
	/*!
	 * \brief 设置国笔输入法引擎当前语言候选词的最大长度
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nMaxWordLength (in)当前语言候选词最大长度
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_LANG_DIDNOT_SUPPORT_API：无效函数接口
		- GBOK：成功设置
	 * \note 中文候选的最大长度不超过10，Alphabetic的最大长度不会超过31。如果设置值比这两者大，实际上为无效的设置。
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSetCandidateMaxWordLength(pGBInputStruct pGBIS, GBINT nMaxWordLength);

	/*! \example GBSetInputString
	 */
	/*!
	 * \brief 直接设置引擎输入串并获取相应候选
	 * \param pGBIS (in)pGBInputStruct对象 
	 * \param pInputString (in)输入串
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBIS为空
		- GBE_API_INVALID_PARAM: 存在一个无效参数,可能pInputString为空，或pInputString输入串长度为0
		- GBE_API_INPUT_STRING_TO_LONG: 输入串长度已经达到最大值
		- Othors: 请参考gbdef.h文件中的GBReturnEnum定义
	 * \author weizhiping
	 * \date 2010-6-21 11:45:23
	 */
	GBAPI GBRETURN GBSetInputString(pGBInputStruct pGBIS, GBLPCWCHAR pInputString);

	/*! \example GBHelperAddInputChar
	 */
	/*!
	 * \brief 添加一个输入字符
	 * \param pGBIS (in) pGBInputStruct对象
	 * \param chr (in) 输入字符
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBIS为空
		- GBE_API_INVALID_PARAM: chr是一个无效参数
		- GBE_API_INPUT_STRING_TO_LONG: 输入串长度已经达到最大值
		- GBOK: 添加字符成功
	 * \note 
	 * \sa GBNextPageCandidate
	 * \author huanjin
	 * \date 2010-7-21
	 */
	GBAPI GBRETURN GBHelperAddInputChar(pGBInputStruct pGBIS, GBWCHAR chr);

	/*! \example GBHelperAddInputString
	 */
	/*!
	 * \brief 追加输入字符串
	 * \param pGBIS (in) pGBInputStruct对象
	 * \param pInputString (in) 输入串
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBIS为空
		- GBE_API_INVALID_PARAM: 存在一个无效参数,可能pInputString为空，或pInputString输入串长度为0
		- GBE_API_INPUT_STRING_TO_LONG: 输入串长度已经达到最大值
		- GBOK: 设置输入字符串成功
	 * \note 此API只设置输入字符串工作，如果需要获取新的候选，需要调用GBNextPageCandidate
	 * \sa GBNextPageCandidate
	 * \author huanjin
	 * \date 2010-7-21
	 */
	GBAPI GBRETURN GBHelperAddInputString(pGBInputStruct pGBIS, GBLPCWCHAR pInputString);

	/*! \example GBGetWordsSpellCorrection
	 */
	/*!
	 * \brief 通过选择的词获取该词的纠错数据，暂只支持外语言
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pClickWords 用户点击的词	 
	 * \param nMatchType 匹配类型，参见enum GB_WORDS_SPELL_CORRECTION_MATCH_TYPE
	 * \note 此接口处理3类纠错，分别是漏按、多按和错按，针对点击单词除头尾字母外的纠错，
	 *		比如luk-luck（漏按），lucck-luck（多按），luek-luck（错按）
	 *		nMatchType可以为多种类型组合，0为匹配全部
	 *		必需设置正确语言后才能使用，比如英文，当前是中文时，需要先切换到英文
	 *		该接口会使用GBNextPageCandidate获取一页候选
	 * \sa GBNextPageCandidate
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBOK：成功返回
	 * \author Zhaokun
	 * \date 2012年3月28日
	 */
	GBAPI GBRETURN GBGetWordsSpellCorrection(pGBInputStruct pGBIS, GBLPCWCHAR pClickWords, GBUINT32 nMatchType);

	/*@}*/

	/*!
	 * \defgroup Chinese 中文专门的函数
	 */
	/*@{*/
	/*! \example GBGetAllSyllableCount
	 */
	/*!
	 * \brief 获得国笔输入法引擎Ambiguous中文输入模式（包括Ambiguous拼音、注音、粤拼等）下面拼音的个数。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pSyllableCount (out)当前音节个数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：参数有误
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBOK：成功获取音节个数
	 * \note 如果输入串已经更新，请调用GBUpdateSyllable更新拼音列表之后，再调用此函数获得拼音的个数
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBGetAllSyllableCount(pGBInputStruct pGBIS, GBINT * pSyllableCount);

	/*! \example GBGetSyllable
	 */
	/*!
	 * \brief 获取国笔输入法引擎音节列表中指定索引的音节
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nSyllableIndex (in)需要返回音节的索引，必须不大于GBGetAllSyllableCount返回的最大音节数，有效值为（1-音节个数）
	 * \param pSyllable (out)存储返回音节的缓冲区，不能为NULL
	 * \param nSyllableBufferLen (in)音节缓冲区长度
	 * \note 仅返回当前音节列表中指定下标的某一个音节
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_INVALID_SYLLABLE_INDEX：当前音节下标不在有效范围内
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBOK：成功获取指定索引的音节
	 * \author chenbinghui
	 * \date 2009年7月16日
	 */
	GBAPI GBRETURN GBGetSyllable(pGBInputStruct pGBIS, GBINT nSyllableIndex, GBWCHAR * pSyllable, GBINT nSyllableBufferLen);

	/*! \example GBSelectSyllable
	 */
	/*!
	 * \brief 选择国笔输入法引擎当前指定索引的音节，要求当前为Ambiguous Chinese模式
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nSyllableIndex (in)当前需要选择音节的索引，0表示模糊匹配所有的音节，某一音节有效值为（1-音节个数）
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 需要调用GBUpdateOutputInfo更新音节信息，后继调用GBGetCandidate 或者GBGetCandidateEx等获取候选的函数可以更新对应的候选列表
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009年7月17日
	 */
	GBAPI GBRETURN GBSelectSyllable(pGBInputStruct pGBIS, GBINT nSyllableIndex);

	/*! \example GBSelectSyllableEx
	*/
	/*!
	 * \brief 选择国笔输入法引擎当前指定的音节，要求当前为Ambiguous Chinese模式
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pSyllable (in)当前指定的音节字符串，NULL表示不选择任何拼音，当前输入串对应音节的候选都会显示
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_UNSUPPORT_LANGUAGE：此版本不支持中文输入
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 后继调用GBGetCandidate或者GBGetCandidateEx等获取候选的函数可以更新对应的候选列表
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009年9月29日
	 */
	GBAPI GBRETURN GBSelectSyllableEx(pGBInputStruct pGBIS, GBLPCWCHAR pSyllable);

	/*! \example GBGetSyllables
	 */
	/*!
	 * \brief 获取国笔输入法引擎Ambiguous中文输入模式（包括Ambiguous拼音、注音、粤拼等）下面的拼音列表。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStartIndex (in)获取音节的开始下标，一般默认为0
	 * \param ppSyllables (out)音节列表缓冲区，存储引擎返回的音节列表，不能为NULL
	 * \param nArrayLength (in)音节列表缓冲区的长度
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_INVALID_SYLLABLE_INDEX：当前音节下标不在有效范围内
		- GBOK：成功返回
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009年7月16日
	 */
	GBAPI GBRETURN GBGetSyllables(pGBInputStruct pGBIS, GBINT nStartIndex, GBWCHAR ** ppSyllables,GBINT nArrayLength);

	/*! \example GBUpdateSyllable
	 */
	/*!
	 * \brief 更新国笔输入法引擎的音节候选，输入串改变后调用
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return
	 	- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 用户可以通过两个途径来更新音节的候选，除了GBUpdateSyllable之外，
	 - 调用GBGetCandidate也可以更新音节的列表。每一次用户输入按键的时候，请首先把当前音节的选择下标设置为0，
	 - 否则可能返回GBE_CHN_INVALID_SYLLABLE_INDEX；另外，GBUpdateSyllable函数会把当前音节下标设置为0。
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBUpdateSyllable(pGBInputStruct pGBIS);

	/*! \example GBGeSyllablePageCount
	*/
	/*!
	 * \brief 获得所有匹配的音节的页数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPageCount (in/out)音节的页数
	 * \return
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM： 函数的参数至少包含一个无效参数
		- GBE_API_NOT_CHINESE：当前的功能是中文语言的功能，但是当前的语言不是中文
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author zhonghuajin
	 * \date 2010年9月6日
	 */
	GBAPI GBRETURN GBGeSyllablePageCount(pGBInputStruct pGBIS,  GBINT * pPageCount);

	/*! \example GBGetCurrentSyllablePageIndex
	*/
	/*!
	 * \brief 返回当前音节页的索引
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPageIndex (in/out)页的索引
	 * \return
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM： 函数的参数至少包含一个无效参数
		- GBE_API_NOT_CHINESE：当前的功能是中文语言的功能，但是当前的语言不是中文
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 只有在曾经获取过候选的前提下，使用这个接口才有意义
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author zhonghuajin
	 * \date 2010年9月6日
	 */
	GBAPI GBRETURN GBGetCurrentSyllablePageIndex(pGBInputStruct pGBIS, GBINT * pPageIndex);

	/*! \example GBSetFuzzy
	 */
	/*!
	 * \brief 设置国笔输入法引擎模糊拼音的功能
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param config (in)可选择一个或者多个配置项，通过（|）叠加多个配置项，可参考GBChnConfigEnum
	 * \param on (in)1表示开启，0表示关闭
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NOT_CHINESE：当前的功能是中文语言的功能，但是当前的语言不是中文
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBOK：成功返回
	 * \note
		- GBCFG_PINYIN_FUZZY_H_F = 0x0008,	//拼音的h和f的模糊匹配(*)
		- GBCFG_PINYIN_FUZZY_N_L = 0x0010,	//拼音的n和l的模糊匹配(*)
		- GBCFG_PINYIN_FUZZY_NG_N = 0x0020,	//拼音的前鼻音和后鼻音的模糊匹配(*)
		- GBCFG_PINYIN_FUZZY_XH_X = 0x0040,	//拼音的平卷舌的模糊匹配(*)
		- GBCFG_PINYIN_FUZZY_K_G = 0x0080,	//拼音的k和g的模糊匹配(*)
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBSetFuzzy(pGBInputStruct pGBIS, GBU32 config, GBINT on);

	/*! \example GBWord2CodesByInputmod
	 */
	/*!
	 * \brief 选择国笔输入法模式，将一个输入字转换为编码输出
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nInputmod (in)当前输入模式，如：GBIM_Pinyin,可参考GBInputModeEnum
	 * \param isn (in)输入字的Unicode编码
	 * \param indexMulPron 指示返回第几个多音字音节,参数只对音码输入法有效，形码输入法缺省为0。
	 * \param pBuff (out)输出缓冲区，用户需要保证缓冲区不少于32个字节的空间
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空	
		- GBE_API_UNSUPPORT_LANGUAGE：不支持该语言
		- EB_INPUTSTRUCT_IS_NULL：INPUTSTRUCT为空
		- EB_NOTINIT：没有调用EBStartup
		- EB_METHOD_INVALID：输入法类型错误
		- GBOK：表示成功。
	 * \note 要求当前为Ambiguous Chinese模式
		- 在注音输入法（EB_INPUT_METHOD_BPMF和EB_INPUT_METHOD_EXP_BPMF），此Buffer应该为unsigned short 的数组，长度至少为6，输出的为Unicode 注音字符串，不输出音调
		- 在笔画输入法，输出为1-5的数字序列
		- 仓颉输入法，输出为a-z的字母序列
		- 拼音输入法和粤音输入法，为a-z的字母序列，不输出音调。
		- 韩文输入法，输出为1-9的字母序列
	 * \author lijingping
	 * \date 2009年9月28日
	 */
	GBAPI GBRETURN GBWord2CodesByInputmod(pGBInputStruct pGBIS, GBINT nInputmod, unsigned short isn,
											GBINT indexMulPron, GBPWCHAR pBuff);


	/*! \example GBTranslateInputStringToSyllable
	 */
	/*!
	 * \brief 获取国笔输入法引擎Ambiguous模式下面的输入串翻译成对应的拼音\注音\粤音
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pTranslateBuffer (out)输出缓冲区，存储返回的转换结果，不能为NULL
	 * \param nBufferLen (in)输出缓冲区的有效长度
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空	
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_API_NOT_CHINESE：当前的功能是中文语言的功能，但是当前的语言不是中文
		- EB_FAILED：失败
		- EB_OK：成功
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBTranslateInputStringToSyllable(pGBInputStruct pGBIS, 
		GBLPWCHAR pTranslateBuffer, 
		GBI32 nBufferLen);

	/*! \example GBChnGetAfterChar
	 */
	/*!
	 * \brief 将根据前面输入的拼音字符返回可能继续输入的内容
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nInputMode (in)当前输入模式，请参考GBInputModeEnum
	 * \param pPreString (in)已经输入的字符，a-z或者注音字母的组合。
	 * \param pAfterChars (out)可能输出的组合字符，如拼音输入zh，可能出现 a o u e i，那么pAfterChars返回"aouei"
	 * \param nBufferLen (in)输出缓冲区有效长度
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空	
		- GBOK：成功
		- GBE_API_NOT_CHINESE：当前的功能是中文语言的功能，但是当前的语言不是中文
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
	 * \note 此函数仅用于Qwerty的拼音、粤音和Explicit的注音。
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBChnGetAfterChar(pGBInputStruct pGBIS, 
		GBINT nInputMode,
		GBLPCWCHAR pPreString, 
		GBLPWCHAR pAfterChars, 
		GBINT nBufferLen);

	/*! \example GBSetEngineOption
	 */
	/*!
	 * \brief 设置国笔输入法引擎的配置
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param engine_id (in)引擎配置模块，请参考gbdef.h文件中EngineIDEnum定义
	 * \param config (in)引擎配置项，与当前配置模块相关，请参考gbdef.h文件中GBChnConfigEnum、GBChnCharset、GBAlp_Config、GBS_Config、GB_Function_Option等
	 * \param option (in)引擎配置参数，与当前配置项相关，可能的值类型是布尔型、字符型、字符串型等，详细请参考相关说明文档
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_API_UNSUPPORT_SYNTAX：不支持整句引擎
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
	 * \note option如果是布尔型（BOOL），可以使用或（|）操作将多个配置项组合给引擎。必须在语言、输入模式设置完成后再调用，否则是无效的调用；
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBSetEngineOption(pGBInputStruct pGBIS, GBINT engine_id, GBU32 config, GBU32 option);

	/*! \example GBGetEngineOption
	 */
	/*!
	 * \brief 获取国笔输入法引擎指定配置项的设置值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param engine_id (in)引擎配置模块，请参考EngineIDEnum
	 * \param config (in)引擎配置项，与当前配置模块相关，请参考gbdef.h文件中GBChnConfigEnum、GBChnCharset、GBAlp_Config、GBS_Config、GB_Function_Option等
	 * \param option (out)获取当前配置选项的设置值，返回值的类型与所选的配置项相关
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功返回
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_API_UNSUPPORT_SYNTAX：不支持整句引擎
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
	 * \note 需要明确当前配置项的值类型，如果类型是BOOL型，返回值为0或非0值。请参考国笔提供的详细说明文档
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBGetEngineOption(pGBInputStruct pGBIS, GBINT engine_id, GBU32 config, GBU32 *option);

	enum GB_Syllable_Page_Enum {
		GBPS_CURRENT_PAGE,	///<当前页
		GBPS_PREV_PAGE,		///<上一页
		GBPS_NEXT_PAGE,		///<下一页
		GBPS_FIRST_PAGE		///<第一页
	};

	/*! \example GBGetPagedSyllable
	 */
	/*!
	 * \brief 获取国笔输入法引擎指定页面的拼音候选
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nWhichPage (in)需要返回那一页的拼音候选，请参考GB_Syllable_Page_Enum
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_AUX_INFO_IS_NULL：tagGBInputStruct::pAuxInfo 为空
		- GBE_API_PREV_NOT_EXISTS：不存在上一页
		- GBE_API_NEXT_NOT_EXISTS：不存在下一页
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBOK：成功返回
		- GB_API_NOT_MORE_PAGE：没有其他页的候选
		- GBE_API_SYLLABLE_NOT_EXISTS：当前状态不存在音节
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
	 * \note 这个函数并不会改变拼音的选择，设置某一个拼音，请调用\ref GBSelectSyllable 这个函数的返回结果与GBFO_Chn_Up_To_Input_Key_Sequence 配置有关，如果打开了这个配置，那么输入串将作为第一个拼音显示。
	 * \author chenbinghui
	 * \date 2009年7月23日
	 */
	GBAPI GBRETURN GBGetPagedSyllable(pGBInputStruct pGBIS, GBINT nWhichPage);

	/*! \example GBChnGetComponents
	 */
	/*!
	 * \brief 获取国笔输入法引擎当前状态下的部首列表，部首数据存放在pGBInputStruct对象的pAuxInfo字段中
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功
		- GBE_API_AUX_INFO_IS_NULL：tagGBInputStruct::pAuxInfo 为空
		- GBE_API_COMPONENTS_NOT_EXISTS：当前状态不存在部首
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
	 * \note pGBInputStruct对象的pAuxInfo字段需要有启动国笔引擎前指定，由用户自已分配空间，但不能为临时变量，一般为定义为全局变量；获取部首列表也可以通过调用GBUpdateOutputInfo，引擎自动返回部首值
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBRETURN GBChnGetComponents(pGBInputStruct pGBIS);

   /*! \example GBSetAssocWord
    */
   /*!
	* \brief 设置国笔输入法引擎的联想字符串(目前只支持中文)
	* \param pGBIS (in)pGBInputStruct对象
	* \param pConfirmedWord (in)当前已经上屏的字符
	* \param bReset (in)在调用此函数前，是否清除之前的联想词
	* \return 
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- EB_OK：成功返回
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
	* \note  如果GBSetAssocWord(pGBIS, L"奥", GBTrue)之后，调用GBSetAssocWord(pGBIS, L"林", GBFalse)，引擎会把“奥林”两个字一起查找联想，联想会出来“匹克”，而调用GBSetAssocWord(pGBIS, L"林", GBTure)，则只用“林”进行联想，那么结果就可能是“立”等。
	* \author chenbinghui
	* \date 2009年7月25日
	*/
	GBAPI GBRETURN GBSetAssocWord(pGBInputStruct pGBIS, GBLPCWCHAR pConfirmedWord, GBBOOL bReset);

	/*! \example GBGetAssocWord
	*/
	/*!
	 * \brief 获取联想字符串(目前只支持中文)
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pConfirmedWord 已经上屏的字符
	 * \param bReset 是否清除调用此函数之前的联想词
	 * \note 此接口对GBSetAssocWord进行了封装，并负责更新引擎状态和输出联想候选词[希望通过GBAPI接口实现联想功能请调用此新接口]
	 * \return 
	 * \author weizhiping
	 * \date 2010年6月2日
	 */
	GBAPI GBRETURN GBGetAssocWord(pGBInputStruct pGBIS, GBLPCWCHAR pConfirmedWord, GBBOOL bReset);

	/*! \example GBSetSyllableTone
	*/
	/*!
	* \brief 设置音调
	* \param pGBIS (in)pGBInputStruct对象
	* \param tone 有效值:GB_CHN_TONE_NULL-GB_CHN_TONE_6
	* \note	
	* \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NOT_CHINESE：当前的语言不是中文
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_CHN_INVALID_TONE：非法的音调
	* \author Zhaokun
	* \date 2010年11月29日
	*/
	GBAPI GBRETURN GBSetSyllableTone(pGBInputStruct pGBIS, GBU8 tone);
	
	/*! \example GBSetQwertyBopomofoMap
	*/
	/*!
	* \brief 设置注音Qwerty键盘的映射
	* \param pGBIS (in)pGBInputStruct对象
	* \param pQwertyBopomofoMap (in)键盘映射
	* \note	映射的范围GBKEY_BPMF_B - GBKEY_BPMF_IU（0x3105 至 0x3105 +36）
	* \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NOT_CHINESE：当前的语言不是中文
		- GBE_API_UNSUPPORT_CHINESE：此版本不支持中文输入
		- GBE_CHN_UNSUPPORT_INPUT_METHOD：非法的音调
	* \author Zhaokun
	* \date 2010年11月29日
	*/
	GBAPI GBRETURN GBSetQwertyBopomofoMap(pGBInputStruct pGBIS, GBLPCACHAR pQwertyBopomofoMap);

	/*@}*/

	/*!
	 * \defgroup Alphabetic Alphabetic专门的函数
	 */
	/*@{*/
	/*! \example GBGetDesireOutput
	 */
    /*!
	 * \brief 将国笔输入法引擎当前候选的字符串大小写方式改变，仅对alphabetic语言有效
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param option (in)用户指定的输出字母类型，请参考GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBE_API_ALP_NOT_SUPPORT：Alphabetic不支持此功能
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBOK：成功返回
	 * \note 调用该接口之前，需要首先调用相应API接口获取候选，如果该接口先被调用，实际上为无效的调用
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBRETURN GBGetDesireOutput(pGBInputStruct pGBIS, GBU32 option);

	/*! \example GBConvertChar
	 */
	/*!
	 * \brief 将国笔输入法引擎的当前候选的字母大小写方式改变，仅对alphabetic语言有效
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param chr (out)字母输出缓冲区
	 * \param nConvertOption (in)用户指定的输出字母类型，请参考GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBE_API_ALP_NOT_SUPPORT：Alphabetic不支持此功能
		- GBOK：成功返回
	 * \note 调用该接口之前，需要首先调用相应API接口获取候选，如果该接口先被调用，实际上为无效的调用
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBRETURN GBConvertChar(pGBInputStruct pGBIS, GBWCHAR * chr, GBI32 nConvertOption);

	/*! \example GBConvertString
	 */
	/*!
	 * \brief 将国笔输入法引擎的当前候选的字符串大小写方式改变，仅对alphabetic语言有效
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pWString (out)字符串输出缓冲区
	 * \param nConvertOption (in)用户指定的输出字母类型，请参考GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBE_API_ALP_NOT_SUPPORT：Alphabetic不支持此功能
		- GBOK：成功返回
	 * \note 调用该接口之前，需要首先调用相应API接口获取候选，如果该接口先被调用，实际上为无效的调用
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBRETURN GBConvertString(pGBInputStruct pGBIS, GBWCHAR * pWString, GBINT nConvertOption);

	/*! \example GBConvertStringToNumPadKeySequence
	 */
	/*!
	 * \brief 将国笔输入法引擎当前语言字符串转化为对应的数字键盘按键序列，仅对alphabetic语言有效
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pWString (in)当前语言输入的字符串
	 * \param pKeySequence (out)返回数字键盘按键字列
	 * \param nBufferLen (in)缓冲区大小
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBE_API_ALP_NOT_SUPPORT：Alphabetic不支持此功能
		- GBOK：成功返回
	 * \note 
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBRETURN GBConvertStringToNumPadKeySequence(pGBInputStruct pGBIS, 
		GBLPCWCHAR pWString, 
		GBLPWCHAR pKeySequence,
		GBINT nBufferLen);

	/*! \example GBTransform
	 */
	/*!
	 * \brief 将国笔输入法引擎的词语转化为对应的显示模式
	 * \param languageID (in)当前可以选用的语言，请参考文件gbim.h中GBLanguageEnum定义
	 * \param words 
	 * \param forms 
	 * \param bufLen 
	 * \return 
	 * \note 目前支持越南语和维吾尔语。
			在越南语里面，此函数负责把越南语的音标符号和字母合并为一个Unicode。如0x0041+ 0x0300 -> 0x00C0
	 		在维吾尔语里面，此函数负责把维吾尔的组合字母拆开为两个Unicode。如 0xFBEA -> 0x0626 + 0x0627
	 		目前支持0xFBEA, 0xFBEE, 0xFBF9, 0xFBF2, 0xFBF0, 0xFBF4, 0xFBF6, 0xFBEC等字符。
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBINT GBTransform(GBINT languageID,
					GBLPCWCHAR words,
					GBLPWCHAR forms,
					GBUINT bufLen);

	/*! \example GBTransformReverse
	 */
	/*!
	 * \brief \ref GBTransform函数的逆过程
	 * \param languageID
	 * \param forms
	 * \param words
	 * \param bufLen
	 * \return words里面输出的字符个数
	 * \note 目前支持越南语和维吾尔语。
	 在越南语里面，此函数负责把越南语合并字符分拆为字母+音标， 如0x00C0 -> 0x0041+ 0x0300
	 在维吾尔语里面，此函数负责把维吾尔的组合字母合并。 如 0x0626 + 0x0627 -> 0xFBEA
	 目前支持0xFBEA, 0xFBEE, 0xFBF9, 0xFBF2, 0xFBF0, 0xFBF4, 0xFBF6, 0xFBEC等字符。
	 * \author chenbinghui
	 * \date 2009年7月25日
	 */
	GBAPI GBINT GBTransformReverse(GBINT languageID,
		GBLPCWCHAR forms,
		GBLPWCHAR words,
		GBUINT bufLen);


	/*! \example GBSetShiftCap
	 */
	/*!
	 * \brief 设置国笔输入法引擎的控制键状态，仅对alphabetic语言有效
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param bShiftDown (in)是否Shift键被按下
	 * \param bCapsLockToggle (in)是否CapsLock键处于有效状态
	 * \return 成功返回GBOK，其它返回参考GBReturnEnum
	 * \note Shift和CapsLock会影响Alphabetic引擎的输出，Shift有效的时候，单词为首字母大写，
			CapsLock有效的时候，单词为大写状态，如果CapsLock和Shift同时有效，单词为大写状态
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBSetShiftCap(pGBInputStruct pGBIS, GBINT bShiftDown, GBINT bCapsLockToggle);

	/*! \example GBAlpGetValidInputStr
	 */
	/*!
	 * \brief 获取外语言指定输入模式在指定候选类型下的有效输入序列
	 * \param pGBIS 
	 * \param nInputMethod (in）输入模式， 参见GBInputModeEnum
	 * \param nCandType (in）候选类型，参见GBCandTypeEnum
	 * \param validStr (in/out）有效输入序列
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author Zhaokun
	 * \date 2011-03-04
	 */
	GBAPI GBRETURN GBAlpGetValidInputStr(pGBInputStruct pGBIS, GBUINT8 nInputMethod, GBUINT8 nCandType, GBLPCCHAR *validStr);

	/*! \example GBAlpGetValidInputStr
	 */
	/*!
	 * \brief 获取可独立作为一个单词字母字符串
	 * \param pGBIS 
	 * \param ppPreferenceChars (out)可独立作为一个单词字母字符串
	 * \note
	 * \return 
	 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
	 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
	 - GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
	 - GBOK：成功返回
	 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author haj
	 * \date 2011-9-16
	 */
	GBAPI GBRETURN GBAlpGetPreferenceChars(pGBInputStruct pGBIS, GBLPCCHAR * ppPreferenceChars);

	/*@}*/


	/*!
	* \defgroup Candidate 获取候选的API
	*/
	/*@{*/

	/*! \example GBHaveNextPage
	 */
	/*!
	 * \brief 判断国笔输入法引擎是否有下一页候选
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBOK：有下一页候选
		- GB_Failed：没有下一页候选
	 * \note 是否有下一页也可以通过宏GBIS_HaveNextPage判断
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBHaveNextPage(pGBInputStruct pGBIS);

	/*! \example GBHavePrevPage
	 */
	/*!
	 * \brief 判断国笔输入法引擎是否有上一页候选
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBOK：有上一页候选
		 - GB_Failed：没有上一页候选
	 * \note 是否有上一页也可以通过宏GBIS_HavePrevPage判断
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBHavePrevPage(pGBInputStruct pGBIS);

	/*! \example GBNextPageCandidate
	 */
	/*!
	 * \brief 获取国笔输入法引擎的候选，使用该API，引擎会填充pGBInputStruct对象的outputInfo字段的候选列表
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStartIndex (in)指定候选填充的开始位置，将候选填充到outputInfo字段的候选列表中
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NEED_TO_CALL_FIRST_PAGE：调用GBGetACand函数之前，需要首先成功调用GBFirstPage
		- GBE_API_PREV_NOT_EXISTS：不存在上一页
		- GBE_API_INPUT_STRING_TO_LONG：输入串长度太长
		- GBOK：成功返回
		- GBE_API_NULL_FUNCTION_POINTER：空函数指针
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 获得第一页候选的时候，设置nStartIndex为0，获得下一页的开始位置为nStartIndex = pGBIS->outputInfo.nCandNum + pGBIS->outputInfo.nFirstCandIndex
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBNextPageCandidate(pGBInputStruct pGBIS, GBINT nStartIndex);

   /*! \example GBNextPageCandidateEx	
    */
   /*!
	* \brief 获取国笔输入法引擎的候选，使用该API，引擎会填充pGBInputStruct对象的outputInfo字段的候选列表
	* \param pGBIS (in)pGBInputStruct对象
	* \param nStartIndex (in)指定候选填充的开始位置，将候选填充到outputInfo字段的候选列表中
	* \param bAppendToCandList 是否在现有的候选后面添加
	* \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NEED_TO_CALL_FIRST_PAGE：调用GBGetACand函数之前，需要首先成功调用GBFirstPage
		- GBE_API_PREV_NOT_EXISTS：不存在上一页
		- GBE_API_INPUT_STRING_TO_LONG：输入串长度太长
		- GBOK：成功返回
		- GBE_API_NULL_FUNCTION_POINTER：空函数指针
		- other：参考gbdef.h文件中的GBReturnEnum定义
	* \note 获得第一页候选的时候，设置nStartIndex为0，获得下一页的开始位置为nStartIndex = pGBIS->outputInfo.nCandNum + pGBIS->outputInfo.nFirstCandIndex
	* \author chenbinghui
	* \date 2009年9月10
	*/
	GBAPI GBRETURN GBNextPageCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBINT bAppendToCandList);

	/*! \example GBPrevPageCandidate
	 */
	/*!
	 * \brief  获取国笔输入法引擎的上一页候选，使用该API，引擎会填充pGBInputStruct对象的outputInfo字段的候选列表
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStartIndex (in)指向的候选为获得候选的最后一个候选
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NEED_TO_CALL_FIRST_PAGE：需要首先调用GBFirstPage
		- GBE_API_PREV_NOT_EXISTS：不存在上一页
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 引擎如果存在上一页，设置nStartIndex = pGBIS->outputInfo.nFirstCandIndex - 1
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBPrevPageCandidate(pGBInputStruct pGBIS, GBINT nStartIndex);

	/*! \example GBCurPageCandidateEx
	 */
	/*!
	* \brief 根据当前的翻页设置, 从nStartCandIndex开始来获得当前页的候选，
	* \param pGBIS (in)pGBInputStruct对象
	* \param nStartIndex (in)
	* - 获得第一页候选的时候, nStartIndex 为 0;
	* - 获得下一页的开始位置为nStartIndex = pGBIS->outputInfo.nFirstCandIndex
	* \param bAppendToCandList (in)是否在现有的候选后面添加
	* \note  候选的信息存放于outputInfo字段中
	* \author fanbo
	* \date 2010-03-05
	*/
	GBAPI GBRETURN GBCurPageCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBINT bAppendToCandList);

	/*! \example GBCurPageCandidate
	 */
	/*!
	* \brief 根据当前的翻页设置来获得当前页的候选，当向下翻页到没有候选后，往回翻页时，采用此函数
	* \param pGBIS (in)pGBInputStruct对象
	* \param nStartIndex (in)指向的候选为获得候选的最后一个候选。一般来说，nStartIndex = pGBIS->outputInfo.nCandStartIndex; 候选的信息存放于pGBIS->outputInfo
	* \note 
	* \author fanbo
	* \date 2010-03-05
	*/
	GBAPI GBRETURN GBCurPageCandidate(pGBInputStruct pGBIS, 
		GBINT nStartIndex);

	/*! \example GBSelectCandidate
	 */
	/*!
	 * \brief 选择国笔输入法引擎的一个候选，一般在自造词过程中使用
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCand (in)用户选择的字符串
	 * \return 
	 - GBE_API_GBIS_IS_NULL：pGBIS为空
	 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
	 - GBE_API_INVALID_LANGUAGE：无效的语言
	 - GBOK：成功返回
	 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 在中文状态，判断用户是否在自造词状态，如果在自造词状态且用户自造还没有完成的话，
	 - 返回GBR_UAW_CONTINUE，引擎会同时更新pGBInputStruct对象的候选；
	 - 中文自造词状态下，自造完成，引擎会自动调用GBUDBAddPhrase函数加入自造词同时会修改pGBInputStruct对象的outputInfo里面的pUpScreenStr；
	 - 在中文直接选词语上屏或者自造词完成之后，会根据前面的输入更新联想词语，并且调用GBAddUsedWord函数进行调频；
	 - 在Alphabetic状态下面，GBSelectCandidate会调用GBAddUsedWord函数进行调频
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBSelectCandidate(pGBInputStruct pGBIS, GBLPCWCHAR pCand);

	/*! \example GBSelectCandidateEx
	 */
	/*!
	* \brief 选择国笔输入法引擎的一个候选，一般在自造词过程中使用
	* \param pGBIS (in)pGBInputStruct对象
	* \param pCand (in)用户选择的字符串
	* \param nInputLen (in)候选对应的输入长度，0表示整个输入串
	* \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBE_API_INVALID_LANGUAGE：无效的语言
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	* \note 在中文状态，判断用户是否在自造词状态，如果在自造词状态且用户自造还没有完成的话，
	- 返回GBR_UAW_CONTINUE，引擎会同时更新pGBInputStruct对象的候选；
	- 中文自造词状态下，自造完成，引擎会自动调用GBUDBAddPhrase函数加入自造词同时会修改pGBInputStruct对象的outputInfo里面的pUpScreenStr；
	- 在中文直接选词语上屏或者自造词完成之后，会根据前面的输入更新联想词语，并且调用GBAddUsedWord函数进行调频；
	- 在Alphabetic状态下面，GBSelectCandidate会调用GBAddUsedWord函数进行调频
	* \author chenbinghui
	* \date 2009年9月10
	*/
	GBAPI GBRETURN GBSelectCandidateEx(pGBInputStruct pGBIS, GBLPCWCHAR pCand, GBINT nInputLen);

	/*! \example GBCancelSelectCandidate
	 */
	/*!
	 * \brief 取消当前用户选择，仅在中文自造词过程中使用。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_LANGUAGE：无效的语言
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 在上一次GBSelectCandidate的返回GB_UAW_CONTINUE之后，可以调用GBCancelSelectCandidate来取消选择。
	 * \author chenbinghui
	 * \date 2009年9月10
	 */
	GBAPI GBRETURN GBCancelSelectCandidate(pGBInputStruct pGBIS);

	/*! \example GBSetCandBuffer
	 */
	/*!
	 * \brief 设置国笔输入法引擎自定义的候选缓冲区，内置缓冲区空间为128个WCHAR
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pBuffer (in)用户指定的候选缓冲区空间
	 * \param nBufferLen (in)用户指定的候选缓冲区大小
	 * \return
		 - GBE_API_GBIS_IS_NULL：pGBIS为空
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBSetCandBuffer(pGBInputStruct pGBIS, GBWCHAR * pBuffer, GBI32 nBufferLen);

	/*! \example GBGetCandBufferLen
	 */
	/*!
	 * \brief 获取国笔输入法引擎候选缓冲区的大小，计算单位为WCHAR
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pBufferLen (out)返回缓冲区的大小
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBOK：成功返回
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数 
	 * \note 
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBGetCandBufferLen(pGBInputStruct pGBIS, GBI32 * pBufferLen);

	/*! \example GBGetCandidate
	*/
	/*!
	* \brief 获取国笔输入法引擎的候选，此函数使用GBSetCandBuffer设置的Buffer来存放候选，获得的候选放置在pGBInputStruct对象outputInfo字段的候选列表里面。
	- 如果没有调用GBSetCandBuffer，那么引擎使用128个WCHAR的Buffer来存放候选数据。
	* \param pGBIS (in)pGBInputStruct对象
	* \param nStartIndex (in)候选的开始位置
	* \param nWantCount (in)需要得到的候选个数
	* \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数 
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	* \note 返回的候选个数放在pGBInputStruct对象outputInfo字段的nCandNum中，同时设置pGBInputStruct对象outputInfo字段nFirstCandIndex值；
	- GBCT_Associate在GBV5的引擎中只支持中文，此函数最多能得到32个候选，要想得到更多的候选，请用GBGetCandidateEx
	* \author chenbinghui
	* \date 2009年7月22日
	*/
	GBAPI GBRETURN GBGetCandidate(pGBInputStruct pGBIS, GBINT nStartIndex, GBINT nWantCount);

	/*! \example GBGetCandidateEx
	 */
	/*!
	 * \brief 获取国笔输入法引擎的候选，此函数使用GBSetCandBuffer设置的Buffer来存放候选，获得的候选放置在pGBInputStruct对象outputInfo字段的候选列表里面。
	 - 如果没有调用GBSetCandBuffer，那么引擎使用128个WCHAR的Buffer来存放候选数据。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStartIndex (in)候选的开始位置
	 * \param pBuffer (out)候选的存放的Buffer，每两个候选之间使用\0分割，这个数组如果不够大，可能会限制返回候选的个数；用户应该使用pCandArray这个数组来得到各个候选的指针，而不是这个数组。
	 * \param nBufferLen (in)Buffer的有效长度
	 * \param pCandInfos (out)返回各个候选对应输入串长度，在中文时候使用， 数组要保证至少有nWantCandCount个元素。
	 * \param pCandArray (out)返回各个候选的指针，pCandArray数组要保证至少有nWantCandCount个元素。
	 * \param nWantCandCount (in)用户需要的候选个数，如果pBuffer空间不够或者候选不足，返回的候选个数可能要比这个值少。
	 * \return 
		 - GBE_API_GBIS_IS_NULL：pGBIS为空
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数 
		 - GBOK：成功返回
		 - GBE_API_INPUT_STRING_TO_LONG：输入串长度太长
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 实际返回的候选个数放在pGBInputStruct对象outputInfo字段的nCandNum中
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBGetCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBWCHAR * pBuffer, 
		GBI32 nBufferLen,
		GBU8 * pCandInfos, 
		GBWCHAR * * pCandArray,
		GBI32 nWantCandCount);

	/*! \example GBGetCandidatesCount
	 */
	/*!
	 * \brief 获得国笔输入法引擎所有匹配的候选的个数。默认最大值为100，可以通过GBSetCandidateMaxCount修改此默认值。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCandidateCount (out)实际返回的候选数
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数 
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBGetCandidatesCount(pGBInputStruct pGBIS, GBINT * pCandidateCount);

	/*! \example GBGetCandidatePageCount
	 */
	/*!
	 * \brief 获得国笔输入法引擎所有匹配的候选的页数，分页信息可以通过GBSetPageOption函数设置，默认中文一页6个候选，Alphabetic一页1个候选。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPageCount (out)实际返回的候选页数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：pGBIS为空
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数 
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBGetCandidatePageCount(pGBInputStruct pGBIS, GBINT * pPageCount);

	/*! \example GBGetCurrentCandidatePageIndex
	 */
	/*!
	 * \brief 返回国笔输入法引擎当前页下标。调用GBGetCurrentCandidatePageIndex之前必须调用候选翻页函数才能正确返回当前的页下标。否则，返回-1。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPageIndex (out)实际返回的页下标
	 * \return 
		- GBE_API_GBIS_IS_NULL：pGBIS为空
		- GBE_API_NO_PAGE_INVOLVE：没有调用GBGet***PageCandiate函数
		- GBOK：成功返回
	 * \note 如果使用了GBMMI的多行候选功能，这个函数返回每一页的最后一行在所有候选行中的下标，如果每一页需要3行候选，翻到第二页的时候这个函数返回5。
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBGetCurrentCandidatePageIndex(pGBInputStruct pGBIS, GBINT * pPageIndex);
	
   /*! \example GBUpscreenChar
	*/
   /*!
	* \brief 将国笔输入法引擎的一个候选字符上屏，影响pGBInputStruct对象outputInfo字段pUpScreenStr值
	* \param pGBIS (in)pGBInputStruct对象
	* \param cCand (in)需要上屏的字符
	* \return
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	* \note 一般在GBMMI内部使用
	* \author chenbinghui
	* \date 2009年12月2
	*/
    GBAPI GBRETURN  GBUpscreenChar(pGBInputStruct pGBIS, GBINT cCand);

	/*! \example GBTransFormat
	*/
	/*!
	 * \brief 根据当前的SHIFT CAPLOCK标志转换候选格式(仅对Alp引擎有效)
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCand (in & out)需要转换及转换后输出的候选
	 * \return 
	 * \note 仅对Alp引擎有效
	 * \author 钟华锦
	 * \date 2010-4-27
	 */
	GBAPI GBRETURN GBTransFormat(pGBInputStruct pGBIS, GBLPWCHAR pCand);

	/*! \example GBUpscreenString
	 */
	/*!
	 * \brief 将国笔输入法引擎的一个候选字符串上屏，影响pGBInputStruct对象outputInfo字段pUpScreenStr值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCand (in)需要上屏的字符串
	 * \return 
		- GBE_API_UPSCREEN_STRING_POINT_NULL：上屏指针为空
		- GBOK：成功返回
		- GBE_API_UPSCREEN_STRING_FULL：上屏Buffer已满
	 * \note 一般在GBMMI内部使用
	 * \author chenbinghui
	 * \date 2009年12月2
	*/
	GBAPI GBRETURN GBUpscreenString(pGBInputStruct pGBIS, GBLPCWCHAR pCand);

	
	/*! \example GBAlpGetEmbeddedInterpunctionKey
	 */
	/*!
	 * \brief 获取国笔输入法引擎内嵌标点符号按键键值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pEmbeddedInterpunctionKey (out)内嵌标点符号键值 
	 * \return 
		 - GBIngore：忽略，不处理
		 - GBOK：成功返回
	 * \note 常用的内嵌键值为0或1
	 * \author chenbinghui
	 * \date 2009年12月2
	 */
	GBAPI GBRETURN GBAlpGetEmbeddedInterpunctionKey(pGBInputStruct pGBIS,GBCHAR *pEmbeddedInterpunctionKey);

	/*! \example GBChnControlChar
	 */
	/*!
	 * \brief  获取国笔输入法引擎中文的词语分隔符以及通配符
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPhraseInput (out)中文词语分隔符
	 * \param pWildCard (out)中文通配符
	 * \return 
		- GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年12月2
	 */
	GBAPI GBRETURN GBChnControlChar(pGBInputStruct pGBIS,GBWCHAR * pPhraseInput,GBWCHAR * pWildCard);

	/*! \example GBInputResetNoHook
	 */
	/*!
	 * \brief 恢复国笔输入法引擎为默认状态，卸载无缝切换包装器
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBOK：成功返回
	 * \note 一般在GBMMI内部使用
	 * \author chenbinghui
	 * \date 2009年12月2
	 */
	GBAPI GBRETURN GBInputResetNoHook(pGBInputStruct pGBIS);

   /*! \example GBSetCandType
	*/
   /*!
	* \brief 设置国笔输入法引擎的候选类型，会影响用户输出候选的方式
	* \param pGBIS (in)pGBInputStruct对象
	* \param CandType (in)需要设置的候选类型，请参考GBCandTypeEnum
	* \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBOK：成功返回
	* \author lijingping
	* \date 2009年12月3日
	*/
	GBAPI GBRETURN GBSetCandType(pGBInputStruct pGBIS,GBINT CandType);

	/*! \example GBUpdateOutputInfo
	 */
	/*!
	 * \brief 更新国笔输入法引擎的所有输出信息，主要影响pGBInputStruct对象outputInfo字段
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
		 - GBE_API_LANG_DIDNOT_SUPPORT_API：当前的语言不支持此API
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBUpdateOutputInfo(pGBInputStruct pGBIS);
	
	/*! \example GBGetFullInputString
	 */
	/*!
	 * \brief 返回引擎完整输入串
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param ppFullInputString (out) 完整输入串
	 * \return 
		 - GBOK：成功返回
	 * \note 
	 * \author Zhaokun
	 * \date 2011年4月26日
	 */
	GBAPI GBRETURN GBGetFullInputString(pGBInputStruct pGBIS, GBLPCWCHAR* ppFullInputString);
	/*@}*/


//MDB 
	/*!
	* \defgroup MDB 细胞数据库（MDB）
	*/
	/*@{*/

	/*! \example fpGBMDBReadData_t
	 */
   /*!
	* \brief 类似fread的函数指针，在一个MDB/细胞词库里面读入一部分数据
	* \param buffer (out)存放读取到的数据
	* \param size (in)读取单元的长度
	* \param count (in)读取单元的个数
	* \param hFileHandle (in)在GBMDBAttachFile函数传入的hFileHandle
	* \return 
		- 返回实际读入的单元个数，如果发生错误或在到达文件尾时还没有达到参数count值，该实际读入单元个数将小于参数count值
	* \author chenbinghui
	* \date 2009年7月27日
	*/
	typedef GBU32 (* fpGBMDBReadData_t)(void * buffer, GBU32 size, GBU32 count, void * hFileHandle);

	/*! \example fpGBMDBFileSeek_t
	 */
	/*!
	 * \brief 类似fseek的函数指针，定位MDB/细胞词库中的位置
	 * \param hFileHandle (in)文件指针
	 * \param offset (in)移动的偏移值
	 * \param origin (in)相对的原点
	 * \return 
		- 0 表示成功，
		- !0 表示失败
	 * \note 
		- origin取值：
		- 0 ///< like SEEK_SET， 位置从头开始
		- 1 ///< like SEEK_CUR，从当前的位置开始
		- 2 ///< like SEEK_END，从结束的位置开始
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBINT (* fpGBMDBFileSeek_t)(GBLPVOID hFileHandle, GBI32 offset, GBINT origin);

	/*! \example fpGBMDBWriteData_t
	 */
	/*!
	* \brief 类似fwrite的函数指针，将数据写入到MDB/细胞词库中
	* \param buffer (in)指向需要写入的数据
	* \param size (in)写入单元的长度
	* \param count (in)写入单元的最大个数
	* \param hFileHandle (in)句柄
	* \return 
		- 返回实际写入MDB/细胞词库中的单元个数，如果出现错误时，该值可能会小于参数count值
	* \author chenbinghui
	* \date 2009年10月12日
	*/
	typedef GBU32 (* fpGBMDBWriteData_t)(const void * buffer, GBU32 size, GBU32 count, GBLPVOID hFileHandle);

	/*! \example GBMDBInit
	 */
	/*!
	 * \brief 国笔输入法引擎细胞词库初始化，使用细胞词库API前先调用该接口，否则将为无效的调用
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pRamBuffer (in)设置MDB功能所需要的RAM空间
	 * \param nRamBufferLen (in)所需要缓冲区大小
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 如果不需要GBMDBAttachFile功能，此空间可以为NULL，这时候可以使用GBMDBAttach来使用MDB/细胞词库功能。如果需要GBMDBAttachFile功能，此空间为48KB，否则可能导致GBMDBAttachFile失败。Alphabetic语言不支持GBMDBAttachFile功能，仅支持GBMDBAttach
	 * \author chenbinghui
	 * \date 2009年7月27日
	 */
	GBAPI GBRETURN GBMDBInit(pGBInputStruct pGBIS, GBLPVOID pRamBuffer, GBU32 nRamBufferLen);

	/*! \example GBMDBAttach
	 */
	/*!
	 * \brief 安装国笔输入法引擎的细胞词库数据
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pMDBData (in)细胞词库的数据
	 * \param nLang (in)细胞词库数据的语言，请参考GBLanguageEnum
	 * \param nMDBDataLen (in)数据的大小
	 * \param pID (out)返回一个MDB/细胞词库的ID，此ID可以用于GBMDBDetach，该ID可能为NULL，表示不输出MDB/细胞词库的ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 目前最多支持5个(GB_MDB_MAX_COUNT)MDB/细胞词库
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBMDBAttach(pGBInputStruct pGBIS, 
		GBLPCVOID pMDBData, 
		GBU32 nLang,
		GBU32 nMDBDataLen, 
		GBINT * pID);

	/*! \example GBMDBAttachFile
	 */
	/*!
	 * \brief 安装国笔输入法引擎的MDB细胞词库文件
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param hFileHandle (in)细胞词库文件句柄
	 * \param nLang (in)(in)细胞词库数据的语言，请参考GBLanguageEnum
	 * \param fpRead (in)读取文件内容的回调函数，具体实现与平台相关，Win32平台直接使用fread
	 * \param fpSeek (in)定位文件内容的回调函数，具体实现与平台相关，Win32平台直接使用fseek
	 * \param pID (out)返回一个MDB/细胞词库的ID，此ID可以用于GBMDBDetach，该ID可能为NULL，表示不输出MDB/细胞词库的ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 目前只有中文引擎支持此功能，最多支持5个(GB_MDB_MAX_COUNT)MDB/MDB/细胞词库。退出时，用户应该首先调用GBMDBDetach函数，然后再关闭打开的文件。
	 * \author chenbinghui
	 * \date 2009年7月27日
	 */
	GBAPI GBRETURN GBMDBAttachFile(pGBInputStruct pGBIS, 
		GBLPVOID hFileHandle, 
		GBU32 nLang,
		fpGBMDBReadData_t fpRead, 
		fpGBMDBFileSeek_t fpSeek, 
		GBINT * pID);

 	/*! \example GBMDBDetach
	 */
	/*!
	 * \brief 卸载国笔输入法引擎细胞词库
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nID (in)MDB/细胞词库的ID，此ID应该为GBMDBAttach/GBMDBAttachFile传出的值
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_NULL_FUNCTION_POINTER：空函数指针
		 - GBOK：成功返回
		 - GBE_API_MDB_INVALID_ID：MDB的ID无效
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 改变语言的时候，并不会Detach对应语言的MDB，之前已经设置好的MDB会继续存在
	 * \author chenbinghui
	 * \date 2009年7月22日
	 */
	GBAPI GBRETURN GBMDBDetach(pGBInputStruct pGBIS, GBINT nID);

	/*! \example GBMDBCheckPhrase
	 */
	/*!
	 * \brief 检查一个MDB里面是否存在某词语
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nMDBID (in)MDB/细胞词库的ID，此ID应该为GBMDBAttach/GBMDBAttachFile传出的值
	 * \param phrase (in)需要检查的语词字符串
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GB_Failed：失败
		 - GBOK：成功返回
		 - GBE_API_MDB_INVALID_ID：MDB的ID无效
		 - GBE_API_UNSUPPORT_LANGUAGE：不支持该语言
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 目前只支持中文词语，此函数必须在中文模式下面调用
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	GBAPI GBRETURN GBMDBCheckPhrase(pGBInputStruct pGBIS, 
		GBINT nMDBID,
		GBLPCWCHAR phrase);

	/*! \example GBMDBAddPhrase
	 */
	/*!
	 * \brief 往国笔输入法引擎绑定的MDB数据文件中增加一个词语
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param fp (in)已经打开的文件句柄
	 * \param fpSeek (in)定位文件内容的回调函数，具体实现与平台相关，Win32平台直接使用fseek
	 * \param fpWrite (in)写文件内容的回调函数，具体实现与平台相关，Win32平台直接使用fwrite
	 * \param fpRead (in)读取文件内容的回调函数，具体实现与平台相关，Win32平台直接使用fread
	 * \param phrase (in)需要写到MDB文件的词语字符串
	 * \param syllable (in)词语对应的音节字符串
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBE_API_UNSUPPORT_LANGUAGE：不支持该语言
		 - GBOK：成功返回
  		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 这个函数需要300字节左右的Stack空间，需要更新MDB时必须先Detch该MDB，然后使用r+b模式重新打开文件，再调用GBMDBAddPhrase，再Attach MDB，此函数必须在中文模式下面调用
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	GBAPI GBRETURN GBMDBAddPhrase(pGBInputStruct pGBIS, 
		GBLPVOID fp,
		fpGBMDBFileSeek_t fpSeek,
		fpGBMDBWriteData_t fpWrite,
		fpGBMDBReadData_t fpRead,
		GBLPCWCHAR phrase,
		GBLPCWCHAR syllable);
	/*@}*/

	/*!
	 * \defgroup UDB 用户自造词函数
	 */
	/*@{*/
	/*
	 * \brief 检查某一个词语是否在当前的LDB和UDB里面。
	 */
#define GB_CURRENT_UDB_ID		(-1)

	/*! \example GBAddUsedWord
	 */
	/*!
	 * \brief 增加国笔输入法引擎自造词库的词语，引擎自动调整候选输出的出现次序。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nUDBID (in)有效的自造词ID
	 * \param pPhrase (in)需要增加的词语字符串
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 如果使用了GBSelectCandidate或者GBSelectCandidateEx函数，引擎会自动调用这个函数，无需手工调用。
	 * \author chenbinghui
	 * \date 2009年7月27日
	 */
	GBAPI GBRETURN GBAddUsedWord(pGBInputStruct pGBIS, GBI32 nUDBID, GBLPCWCHAR pPhrase);

	/*! \example fpGBUDBUpdate_t
	 */
	/*!
	 * \brief 更新UDB的回调函数。
	 * \param nUDBID UDB ID
	 * \param pData UDB数据
	 * \param len 数据长度
	 * \param pOEMUpdateParam pOEMUpdateParam是OEM移植代码在GBUDBAttach传入的addin参数
	 * \author chenbinghui
	 * \date 2009年7月27日
	 */
	typedef void _gb_far (* fpGBUDBUpdate_t)(GBI32 nUDBID, GBLPVOID pData, GBU32 len, GBLPVOID pOEMUpdateParam);

	/*! \example GBUDBAttach
	 */
	/*!
	 * \brief 为国笔输入法引擎指定语言启用UDB功能，一个语言只支持一个UDB
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pUDBBuffer (in)自造词所需的缓冲区：中文最小需要5KB的空间；Alphabetic语言需要2KB以上的空间。
	 * \param nUDBBufferLen (in)自造词缓冲区大小（byte）
	 * \param lang (in)UDB对应的语言，请参考GBLanguageEnum
	 * \param subLang (in)UDB对应的地区方言类型，请参考GBSubLanguageEnum
	 * \param pUDBID (out)如果启用成功，将返回对应的ID，根据此ID，用户可以进行GBUDBDataReset和GBUDBDetach等操作。
	 * \return 成功返回GBOK，启用超过两种语言的UDB返回GBE_API_To_Many_UDB，其它返回参考GBReturnEnum
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBOK：成功返回
		- GBE_API_To_Many_UDB：UDB的个数超出了限制
		- GBE_API_LANG_UDB_EXISTS：该语言的UDB已经存在
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 1. 一般在设置引擎当前语言成功后，再启用UDB功能；
	 *       2. 国笔输入法引擎V5版本仅支持不大于2种语言的UDB，如果超过2个，则需要首先Detach一个UDB，然后再Attach；
	 *		 3. GBSetCurLanguage函数不会自动把对应的语言的UDB Detach；
	 *		 4. 用户需要完整支持无缝切换功能，需要同时启用相关两种语言（一般为中文和英文）的UDB功能，否则无缝切换后进行的自造词将不被保存。
	 * \author chenbinghui
	 * \date 2009年7月27日
	 */
	GBAPI GBRETURN GBUDBAttach(pGBInputStruct pGBIS, 
		GBLPVOID pUDBBuffer, 
		GBU32 nUDBBufferLen,
		GBINT lang,
		GBINT subLang,
		GBI32 * pUDBID);

	/*! \example GBChnUDBAttach
	 */
	/*!
	 * \brief 为国笔输入法引擎指定语言启用UDB功能，一个语言只支持一个UDB。
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pUDBBuffer (in)自造词所需的缓冲区：中文最小需要5KB的空间；Alphabetic语言需要2KB以上的空间。
	 * \param nUDBBufferLen (in)自造词缓冲区大小（byte）
	 * \param pUpContentBuffer (in)“上屏字词内容联想记忆字词”功能所需的缓冲区：最小需要256B的空间。
	 * \param nUpContentBufferLen (in)“上屏字词内容联想记忆字词”功能缓冲区大小（byte）
	 * \param lang (in)UDB对应的语言，请参考GBLanguageEnum
	 * \param subLang (in)UDB对应的地区方言类型，请参考GBSubLanguageEnum
	 * \param pUDBID (out)如果启用成功，将返回对应的ID，根据此ID，用户可以进行GBUDBDataReset和GBUDBDetach等操作。
	 * \return 成功返回GBOK，启用超过两种语言的UDB返回GBE_API_To_Many_UDB，其它返回参考GBReturnEnum
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBOK：成功返回
		- GBE_API_To_Many_UDB：UDB的个数超出了限制
		- GBE_API_LANG_UDB_EXISTS：该语言的UDB已经存在
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 1. 一般在设置引擎当前语言成功后，再启用UDB功能；
	 *       2. 国笔输入法引擎V5版本仅支持不大于2种语言的UDB，如果超过2个，则需要首先Detach一个UDB，然后再Attach；
	 *		 3. GBSetCurLanguage函数不会自动把对应的语言的UDB Detach；
	 *		 4. 用户需要完整支持无缝切换功能，需要同时启用相关两种语言（一般为中文和英文）的UDB功能，否则无缝切换后进行的自造词将不被保存。
	 *       5. “上屏字词内容联想记忆字词”功能仅适用于中文引擎，所以非中文引擎pUpContentBuffer可以为空
	 * \author huanjin
	 * \date 2010年10月14日
	 */
	GBAPI GBRETURN GBChnUDBAttach(pGBInputStruct pGBIS, 
		GBLPVOID pUDBBuffer, 
		GBU32 nUDBBufferLen,
		GBLPVOID pUpContentBuffer, 
		GBU32 nUpContentBufferLen,
		GBINT lang,
		GBINT subLang,
		GBI32 * pUDBID);

	/*! \example GBChnUDBDetach
	 */
	/*!
	 * \brief 卸载国笔输入法引擎的UDB及“上屏字词内容联想记忆字词”数据
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nUDBID (in)有效启用UDB后返回的ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_UDB_ID：无效的UDB ID
		 - GBOK：成功返回
	 * \note 如果通过GBUDBSetUpdateParam函数设置了更新函数，那么GBUDBDetach会自动检查对应的UDB，如果UDB被修改了，会自动调用对应的更新函数；
	 *       如果没有设置更新函数，那么在GBUDBDetach之前需要调用GBUDBGetModifiedCount，函数检查UDB是否有更新，如果被更新过，请显式保存对应的UDB数据。
	 * \author huanjin
	 * \date 2010年10月15日
	 */
	GBAPI GBRETURN GBChnUDBDetach(pGBInputStruct pGBIS, GBI32 nUDBID);

	/*! \example GBChnUDBDataReset
	 */
	/*!
	 * \brief 清空国笔输入法引擎当前的所有自造词及“上屏字词内容联想记忆字词”数据
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author huanjin
	 * \date 2010年10月15日
	 */
	GBAPI GBRETURN GBChnUDBDataReset(pGBInputStruct pGBIS);

	/*! \example GBChnUDBSetUpdateParam
	 */
	/*!
	 * \brief 设置UDB 数据更新的策略
	 * \param pGBIS 
	 * \param nUDBID 有效的UDB ID
	 * \param nUpdateFreq 更新的频率，数据的修改次数大于这个值得时候，引擎就会调用fpUpdateFunction，一般来说这个值建议为10。
	 * \param fpUpdateFunction 更新的回调函数
	 * \param fpUpContentUpdateFunction 联想自造词更新回调
	 * \param pOEMUpdateParam OEM指定的一个参数，在回调函数里面回传给OEM移植代码
	 * \return 
	 * \note 如果厂商只需要实现在退出的时候保存自造词，那么请使用\ref GBUDBGetModifiedCount来检查UDB是否被修改过
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBChnUDBSetUpdateParam(pGBInputStruct pGBIS, 
										  GBI32 nUDBID,
										  GBINT nUpdateFreq,
										  fpGBUDBUpdate_t fpUDBUpdateFunction,
										  fpGBUDBUpdate_t fpUpContentUpdateFunction,
										  GBLPVOID pOEMUDBUpdateParam);

	/*! \example GBUDBSetUpdateParam
	 */
	/*!
	 * \brief 设置国笔输入法引擎UDB数据更新策略
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nUDBID (in)有效启用UDB后返回的ID
	 * \param nUpdateFreq (in)更新的频率，数据的修改次数大于这个值得时候，引擎就会调用fpUpdateFunction，一般来说这个值建议为10。
	 * \param fpUpdateFunction (in)更新的回调函数
	 * \param pOEMUpdateParam (in)OEM指定的一个参数，在回调函数里面回传给OEM移植代码
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_UDB_ID：无效的UDB ID
		 - GBOK：成功返回
	 * \note 如果厂商只需要实现在退出的时候保存自造词，那么请使用GBUDBGetModifiedCount来检查UDB是否被修改过
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBSetUpdateParam(pGBInputStruct pGBIS, 
		GBI32 nUDBID,
		GBINT nUpdateFreq,
		fpGBUDBUpdate_t fpUpdateFunction,
		GBLPVOID pOEMUpdateParam);

	/*! \example GBUDBGetModifiedCount
	 */
	/*!
	 * \brief 检查某一个UDB在使用过程中被修改过多少次
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nUDBID (in)有效启用UDB后返回的ID
	 * \param pModifiedCount (out)被修改的次数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBE_API_INVALID_UDB_ID：无效的UDB ID
		 - GBOK：成功返回
	 * \sa GBUDBSetUpdateParam GBUDBDataReset GBUDBDetach
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBGetModifiedCount(pGBInputStruct pGBIS, 
		GBI32 nUDBID,
		GBINT * pModifiedCount);

	/*! \example GBUDBDataReset
	 */
	/*!
	 * \brief 清空国笔输入法引擎当前的所有自造词
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBDataReset(pGBInputStruct pGBIS);

	/*! \example GBUDBDetach
	 */
	/*!
	 * \brief 卸载国笔输入法引擎的UDB
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nUDBID (in)有效启用UDB后返回的ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_UDB_ID：无效的UDB ID
		 - GBOK：成功返回
	 * \note 如果通过GBUDBSetUpdateParam函数设置了更新函数，那么GBUDBDetach会自动检查对应的UDB，如果UDB被修改了，会自动调用对应的更新函数；
	 *       如果没有设置更新函数，那么在GBUDBDetach之前需要调用GBUDBGetModifiedCount，函数检查UDB是否有更新，如果被更新过，请显式保存对应的UDB数据。
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBDetach(pGBInputStruct pGBIS, GBI32 nUDBID);

	/*! \example GBUDBAddPhrase
	 */
	/*!
	 * \brief 往国笔输入法引擎UDB加入一个自造词
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pWord (in)需要加入自造词库的词语字符串
	 * \param syllable_together (in) Ambiguous中文的时候使用，用于区分中文的多音字。在其他情况下面，此参数应该为NULL。
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBAddPhrase(pGBInputStruct pGBIS, 
		GBLPCWCHAR pWord, 
		GBLPCWCHAR syllable_together);

	/*! \example GBUDBDeletePhrase
	 */
	/*!
	 * \brief 删除国笔输入法引擎UDB中的一个自造词
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param phrase (in)用户指定的词语字符串
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBDeletePhrase(pGBInputStruct pGBIS, GBLPCWCHAR phrase);

	/*! \example GBUDBGetNextPhrase
	 */
	/*!
	 * \brief 枚举国笔输入法引擎中的自造词
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pParamItem (in/out) 第一次的时候pParamItem须由OEM设置为0，此后引擎会自动设置
	 * \param pBuffer (out)存放获得词语的缓冲区，Buffer的长度应该不小于GB_INPUT_BUFFER_LEN。
	 * \param nBuffLen (in)缓冲区的大小
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBUDBGetNextPhrase(pGBInputStruct pGBIS, GBUINT32 * pParamItem, GBLPWCHAR pBuffer, GBINT nBuffLen);
	/*@}*/

	/*!
	 * \defgroup Auxiliary	辅助API
	 */
	/*@{*/

	/*! \example GBIsInDatabase
	 */
	/*!
	 * \brief 检查国笔输入法引擎里的LDB和UDB是否存在指定的词语
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pPhrase (in)需要检查的词语字符串
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBE_API_INVALID_LANGUAGE：无效的语言
		 - GBOK：成功返回
		 - other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 中文引擎只查找UDB数据
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBIsInDatabase(pGBInputStruct pGBIS, GBLPCWCHAR pPhrase);

	/*! \example GBGetLastError
	 */
	/*!
	 * \brief 如果调用国笔输入法引擎调用API函数发生错误，获取最后一次失败的值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		- GB_API_GET_LAST_ERROR_NULL_PARAM：参数为NULL
		- other：引擎内部记录的错误值
	 * \note 能够返回的错误值都是引擎可控的
	 * \author chenbinghui
	 * \date 2009年7月28日
	 */
	GBAPI GBRETURN GBGetLastError(pGBInputStruct pGBIS);

	/*! \example GBSetLastError
	 */
	/*!
	 * \brief 设置国笔输入法引擎发生最后一次错误时的值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param error (in)引擎错误代码，请参考GBReturnEnum
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 设置的error值只有小于0，才可能被GBGetLastError返回；
	     - 如果是Debug版本，在Win32平台VS2005环境下当前错误信息直接输出到Output对话框中，否则以printf方式输入错误信息；
		 - 如果用户通过GBAttachLogRecorder接口增加自定义日志记录器，并且已经启用了GBFO_API_Stop_Log配置，错误信息将通过记录器输出；
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBSetLastError(pGBInputStruct pGBIS, GBRETURN error);

	/*! \example GBSetLastErrorEx
	 */
	/*!
	 * \brief 设置国笔输入法引擎发生最后一次错误时的值
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param file (in)当前调用的文件
	 * \param line (in)使用该接口所处源码的行号
	 * \param pErr (in)错语简单说明
	 * \param error (in)错误代号
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 设置的error值只有小于0，才可能被GBGetLastError返回；
		 - 如果是Debug版本，在Win32平台VS2005环境下当前错误信息直接输出到Output对话框中，否则以printf方式输入错误信息；
		 - 如果用户通过GBAttachLogRecorder接口增加自定义日志记录器，并且已经启用了GBFO_API_Stop_Log配置，错误信息将通过记录器输出；
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBSetLastErrorEx(pGBInputStruct pGBIS, 
		const char * file, 
		GBINT line, 
		const char * pErr, 
		GBRETURN error);

	/*! \example GBWriteLog1Param
	 */
	/*!
	 * \brief 国笔输入法引擎提供的一个输入Log信息的函数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param file (in)当前调用的文件
	 * \param line (in)使用该接口所处源码的行号
	 * \param msg (in)输出消息字符串
	 * \param value (in)输出的数值
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 设置的error值只有小于0，才可能被GBGetLastError返回；
		 - 如果是Debug版本，在Win32平台VS2005环境下当前错误信息直接输出到Output对话框中，否则以printf方式输入错误信息；
		 - 如果用户通过GBAttachLogRecorder接口增加自定义日志记录器，并且已经启用了GBFO_API_Stop_Log配置，错误信息将通过记录器输出；
	 * \author chenbinghui
	 * \date 2009年7月21日
	 */
	GBAPI GBRETURN GBWriteLog1Param(pGBInputStruct pGBIS, 
		const char * file, 
		GBINT line,	
		const char * msg, 
		GBU32 value);

	/*! \example fpLogRecorder_t
	 */
	/*!
	 * \brief 增加一个Log的记录器回调函数
	 * \param pOEMData OEM定义参数，会在fpLogRecorder_t对应的回调函数回传给OEM。
	 * \param format 格式函数，类似printf的函数的格式
	 * \param p1 输出的第1个参数
	 * \param p2 输出的第2个参数 
	 * \param p3 输出的第3个参数 
	 * \param p4 输出的第4个参数 
	 * \return 忽略
	 * \author chenbinghui
	 * \date 2009年7月23日
	 */
#ifndef FPLOGRECORDER_T_DEF
#define FPLOGRECORDER_T_DEF
	typedef GBINT (* fpLogRecorder_t)(GBLPVOID pOEMData, const char * format, unsigned long p1, unsigned long p2, unsigned long p3, unsigned long p4);
#endif

	/*! \example GBAttachLogRecorder
	 */
	/*!
	 * \brief 为国笔输入法引擎安装一个Log的观察者，这样引擎在出错的时候可以给出详细的出错信息
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param viewer (in)日志输出的回调函数
	 * \param pOEMData (in)OME传入到回调函数里所需要的参数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
	 * \note Debug版本的引擎能够输出详细的信息，在VC版本的库中，引擎会自动把信息输出到Output子窗口里面。
	 * \author chenbinghui
	 * \date 2009年11月19日
	 */
	GBAPI GBRETURN GBAttachLogRecorder(pGBInputStruct pGBIS, fpLogRecorder_t viewer, GBLPVOID pOEMData);

	/*! \example GBGetDataLanguage
	 */
	/*!
	 * \brief 获取国笔输入法数据里的语言信息
	 * \param pData (in)对应语言数据，数据文件必须包含256个字节的语言信息
	 * \param pLang (out)返回数据中的语言ID，请参考GBLanguageEnum
	 * \param pSubLang (out)返回数据中的地区，请参考GBSubLanguageEnum
	 * \param pSize (out)返回语言数据的大小
	 * \return 
		 - GB_Failed：失败
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009-09-08
	 */
	GBAPI GBRETURN GBGetDataLanguage(GBLPCVOID pData, GBLANG * pLang, GBSUBLANG * pSubLang, GBU32 * pSize);
	
	/*@}*/
//GB Event API

	/*!
	 * \defgroup GBMMI	GBMMI函数
	 */
	/*@{*/
	/*! \example GBMMIHandleKeyEvent
	 */
	/*!
	 * \brief 处理键盘消息的MMI函数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param evt (in)事件处理类型，请参考GBEventEnum
	 * \param param (in) 消息的参数
	 * \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBE_API_AUX_INFO_IS_NULL：tagGBInputStruct::pAuxInfo 为空
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBOK：成功返回
		- other：参考gbdef.h文件中的GBReturnEnum定义
	 * \note 调用此函数之前请首先GBInitialize，GBSetCurLanguage，GBSetInputMode，如果引擎出错，可以使用GBGetLastError获知出错的类型。
	 * \sa GBInitialize GBSetCurLanguage GBSetInputMode GBGetLastError
	 * \author chenbinghui
	 * \date 2009年8月5日
	 */
	GBAPI GBRETURN GBMMIHandleKeyEvent(pGBInputStruct pGBIS, GBINT evt, GBU32 param);

	/*! \example GBMMISetCandRowCount
	 */
	/*!
	 * \brief 设置国笔输入法引擎候选行数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStatus (in)需要设置的状态，为GBInputModeStatusEnum中的值
	 * \param nRowCount (in)候选行数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年11月13日
	 */
	GBAPI GBRETURN GBMMISetCandRowCount(pGBInputStruct pGBIS, GBINT nStatus, GBINT nRowCount);
	

	/*! \example GBMMIGetCandRowCount
	 */
	/*!
	 * \brief 获取各个状态候选的行数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nStatus (in)当前状态，为GBInputModeStatusEnum中的值
	 * \param pCandRowCount (out)返回候选行数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
	 * \note pRowCountForEachStatus 一个长度为GBIMS_STATUS_COUNT的数组，数组的每一个元素表示对应输入状态的候选行数，0表示在该状态下面关闭候选框
	 * \sa GBInputModeStatusEnum
	 * \author chenbinghui
	 * \date 2009年11月13日
	*/
	GBAPI GBRETURN GBMMIGetCandRowCount(pGBInputStruct pGBIS, GBINT nStatus,GBINT *pCandRowCount);

	/** \brief 标点符号输入的功能选项 */
	enum GBInterpunctionKeyOption
	{
		///当前存在候选的情况，GBMMI会上屏当前选择候选，然后开始标点符号输入
		GBIKO_Input_Status_Confirm_Candidate = 1		
	};

	/*! \example GBMMIRegisterInterpunctionKeyEx
	 */
	/*!
	 * \brief 设置国笔输入法引擎标点符号输入选项
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param cKey (in)触发的按键，参考GBEventEnum
	 * \param pSymbols (in)标点符号，必须需要是全局变量，可以单个Unicode的标点符号，也可以为多个Unicode的标点符号
					- 设置单个Unicode的标点符号，把所有的标点符号作为一个字符串，cSplit参数设置为0即可
					- 设置多个Unicode的标点符号，如:-( :-)等，不同的符号之间使用分隔符号分隔，然后把分隔符通过cSplit传入
					- NULL的时候表示使用当前语言的默认标点符号
	 * \param cSplit (in)表示pSymbols符号中的分隔符。如果分隔符为0，表示标点符号都是单个字母的标点。
	 * \param nCandListType (in)候选列表的种类，可以采取以下候选列表类型，参考GBCandListType
					- GBCL_MULTITAP 采取MultiTap的方式输入标点符号
					- GBCL_ROW_MULTITAP 多行候选(支持键盘)，nCandDesireRow参数可以设置候选的行数
					- GBCL_ROW_TCH_SCR 多行候选(触摸屏)，nCandDesireRow参数可以设置候选的行数
	 * \param nCandDesireRow (in)当候选框设置为GBCL_ROW_KEYBD或者GBCL_ROW_TCH_SCR时，每一页需要候选行数
	 * \param nCandCountPerRow (in)当候选框设置为GBCL_ROW_KEYBD或者GBCL_ROW_TCH_SCR时，每一行需要候选个数
	 * \param nOption (in)设置标点符号输入的选项
					- 0 表示只有在联想状态或者初始化状态按对应的按键才可以开始标点输入
					- GBIKO_Input_Status_Confirm_Candidate 表示当前存在候选的情况，GBMMI会上屏当前选择候选，然后开始标点符号输入
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		 - GBOK：成功返回
		 - GBE_MMI_TOO_MANY_MULTITAP_KEY：当前输入模式下面已经设置了太多的MultiTap按键
	 * \sa GBMMIRegisterInterpunctionKey
	 * \author chenbinghui
	 * \date 2009年11月17日
	*/
	GBAPI GBRETURN GBMMIRegisterInterpunctionKeyEx(pGBInputStruct pGBIS, 
		GBINT cKey,
		GBLPCWCHAR pSymbols,
		GBINT cSplit,
		GBINT nCandListType,
		GBINT nCandDesireRow,
		GBINT nCandCountPerRow,
		GBUINT nOption);

	/*! \example GBMMIRegisterInterpunctionKey
	 */
	/*!
	* \brief 设置国笔输入法引擎标点符号输入选项
	* \param pGBIS (in)pGBInputStruct对象
	* \param cKey (in)触发的按键，参考GBEventEnum
	* \param pSymbols (in)标点符号，必须需要是全局变量，可以单个Unicode的标点符号，也可以为多个Unicode的标点符号
		- 设置单个Unicode的标点符号，把所有的标点符号作为一个字符串，cSplit参数设置为0即可。
		- 设置多个Unicode的标点符号，如:-( :-)等，不同的符号之间使用分隔符号分隔，然后把分隔符通过cSplit传入
		- NULL的时候表示使用当前语言的默认标点符号
	* \param nCandDesireCount (in)每一行需要候选个数	
	* \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
		- GBOK：成功返回
		- GBE_MMI_TOO_MANY_MULTITAP_KEY：当前输入模式下面已经设置了太多的MultiTap按键
	* \sa GBMMIRegisterInterpunctionKey
	* \author chenbinghui
	* \date 2009年11月17日
	*/

	GBAPI GBRETURN GBMMIRegisterInterpunctionKey(pGBInputStruct pGBIS, 
		GBINT cKey,
		GBLPCWCHAR pSymbols,
		GBINT nCandDesireCount);

	/*! \example GBMMIUnregisterInterpunctionKey
	 */
	/*!
	 * \brief 取消Interpunction Key的设置
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param cKey (in)触发的按键，参考GBEventEnum，如果cKey为0，则取消所有的key设置
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年11月17日
	*/
	GBAPI GBRETURN GBMMIUnregisterInterpunctionKey(pGBInputStruct pGBIS, GBINT cKey);


	/*! \example GBMMISetAlphabeticUAWTips
	 */
	/*!
	 * \brief 设置用户自造词的提示
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pUAWTips (in)提示用户自造词的文本
	 * \param count (in)自造词提示的有效个数
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 在打开Alphabetic 自造词流程的情况下，用户输入没有对应候选
	 * \sa GB_Function_Option GBSetEngineOption
	 * \author chenbinghui
	 * \date 2009年10月13日
	 */
	GBAPI GBRETURN GBMMISetAlphabeticUAWTips(pGBInputStruct pGBIS, 
		lpcGBAlpUAWTip pUAWTips,
		GBINT count);

	/*! \example GBMMIGetInputModeBeforeSwitchLang
	 */
	/*!
	* \brief 返回无缝切换中第一个入栈的输入法模式
	* \param pGBIS (in)pGBInputStruct对象
	* \param inputMode (out)输入模式
	* \return 
		- GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		- GBE_MMI_NOT_SWITCH_LANG_STATUS：当前并没有处于无缝切换状态
		- GBOK：成功返回
		* \note 
	* \author zhj
	* \date 2010年3月2日
	*/
	GBAPI GBRETURN GBMMIGetInputModeBeforeSwitchLang(pGBInputStruct pGBIS, GBINT *inputMode);

	/*! \example GBMMIReset
	 */
	/*!
	* \brief GBMMI层reset接口
	* \param pGBIS (in)pGBInputStruct对象
	* \return 
	- GBE_API_GBIS_IS_NULL:  pGBIS 为空
	- GBOK: 成功
	* \note 把输入法设置为Initial状态; 把输入串清空; 并且会初始化AuxInfo; 如果支持无缝切换功能且处于无缝切换状态，会还原到切换之前的状态。
	* 		  如果不是GBL_Chinese语言，会设置Shift和CapsLock状态为0
	* \author zhonghuajin
	* \date	2010年3月4日
	*/
	GBAPI GBRETURN GBMMIReset(pGBInputStruct pGBIS);

	/*! \example fpFirstPage_t
	 */
	/*!
	 * \brief 根据当前输入按键序列获取第一页的候选
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBRETURN (* fpFirstPage_t)(pGBInputStruct pGBIS);	

	/*! \example fpGetACand_t
	 */
	/*!
	 * \brief 获取一个候选，调用之前必须成功调用fpGBFirstPage
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param index 候选的下标
	 * \param pCand (out) 指向候选的指针
	 * \param pInputLen (in)输入串长度
	 * \param pMoreCand (out) 是否有更多的候选
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBRETURN (* fpGetACand_t)(pGBInputStruct pGBIS, GBINT index, GBWCHAR * * pCand, GBU8 * pInputLen, GBBOOL * pMoreCand);

	/*! \example fpGetCandidateIndex_t
	 */
	/*!
	 * \brief 获得引擎当前的候选下标，Alphabetic引擎为精确的，中文引擎为当前页的第一个候选的Index
	 * \param pGBIS (in) pGBInputStruct对象
	 * \param pIndex (out) 候选下标
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBRETURN (* fpGetCandidateIndex_t)(pGBInputStruct pGBIS, GBINT * pIndex);

	/*! \example fpSelectCandidate_t
	 */
	/*!
	 * \brief 选择一个候选
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pCand (in)选择的候选
	 * \param nInputLen (in)输入串长度
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBRETURN (* fpSelectCandidate_t)(pGBInputStruct pGBIS, GBLPCWCHAR pCand, GBINT nInputLen);

	/*! \example fpNormalHandler_t
	 */
	/*!
	 * \brief 取消一个候选选择
	 * \param pGBIS (in)pGBInputStruct对象
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月12日
	 */
	typedef GBRETURN (* fpNormalHandler_t)(pGBInputStruct pGBIS);

	/** \brief 引擎Wrapper，用于临时改变引擎的候选获得和处理方式，任何项都可以为NULL，表示不替换对应的值 */
	    
	typedef struct tagGBEngineWrapper
	{
		///根据当前输入按键序列获取第一页的候选
		fpFirstPage_t				fpFirstPage;
		///获取一个候选，调用之前必须成功调用fpGBFirstPage
		fpGetACand_t				fpGetACand;
		///获得引擎当前的候选下标，Alphabetic引擎为精确的，中文引擎为当前页的第一个候选的Index
		fpGetCandidateIndex_t		fpGetCandidateIndex;
		///选择一个候选
		fpSelectCandidate_t			fpSelectCandidate;
		///取消一个候选选择, 一般只需要返回GB_API_NO_MORE_SELECTION即可
		fpNormalHandler_t			fpCancelSelectCandidate;
		///Wrapper Flag
		//start[2010-3-15 zhj]
		//配合GBFO_Chn_All_Num_Can_Continuously_Input所做的改动
		fpNormalHandler_t			fpUpateOutputInfo;
		//end[2010-3-15 zhj]	

		GBU32						lWrapperFlag;
		GBPageOption *				pPageOption;
	} GBEngineWrapper;

	/*! \example GBInstallEngineWrapper
	 */
	/*!
	 * \brief 安装引擎Wrapper，用于临时改变引擎的候选获得和处理方式
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pWrapper (in)引擎Wrapper，为NULL的时候表示Reset所有的函数指针
	 * \param pOldFunc (out, optional)引擎之前使用函数指针，可以为NULL
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 需要卸载的时候，只需要调用GBInstallEngineWrapper(pGBIS, NULL, NULL)就可以了
	 * \sa GBEngineWrapper GBSetInputMode
	 * \author chenbinghui
	 * \date 2009年10月13日
	*/
	GBAPI GBRETURN GBInstallEngineWrapper(pGBInputStruct pGBIS, 
		const GBEngineWrapper * pWrapper, 
		GBEngineWrapper * pOldFunc);

#define GBUninstallEngineWrapper(pGBIS)		GBInstallEngineWrapper((pGBIS), NULL, NULL)

	/*! \example GBMMISetDefaultCandListType
	 */
	/*!
	 * \brief 设置当前输入状态的候选框方式
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nCandListType (in)只能是GBCL_ROW_KEYBD/GBCL_ROW_TCH_SCR/GBCL_SINGLE_CAND的一个
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBE_MMI_INVALID_CAND_LIST_TYPE：当前的状态下不能使用这个输入模式
		 - GBOK：成功返回
	 * \note 此函数需要在输入之前调用，一般在\ref GBSetInputMode之后调用，中文输入法可以选择GBCL_ROW_KEYBD和GBCL_Row_Touchscr Alphabetic可以选择GBCL_ROW_KEYBD和GBCL_Row_Touchscr和GBCL_SINGLE_CAND Alphabetic选择了GBCL_SINGLE_CAND之后，分页选项会变成每一页只需要1个候选
	 * \author chenbinghui
	 * \date 2009年10月15日
	*/
	GBAPI GBRETURN GBMMISetDefaultCandListType(pGBInputStruct pGBIS, GBINT nCandListType);

	/*! \example GBMMISetSwitchOption
	 */
	/*!
	 * \brief 设置无缝切换的参数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param nGBKey (in) 无缝切换的触发按键
	 * \param nLang (in)目标输入法的语言类型，参考GBLanguageEnum，默认为GBL_English
	 * \param nSubLang (in)目标输入法的地区，参考GBSubLanguageEnum
	 * \param nInputMode (in)目标输入模式，GBInputModeEnum
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年10月21日
	 */
	GBAPI GBRETURN GBMMISetSwitchOption(pGBInputStruct pGBIS, 
		GBINT nGBKey, 
		GBINT nLang, 
		GBINT nSubLang, 
		GBINT nInputMode);


	/*! \example GBMMISetSpecialKeyMapping
	 */
	/*!
	 * \brief 设置GBKEY_SPECIAL_A 等键对应的KeyMapping
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param cSpecialAKey (in)当引擎按键GBKEY_AMB_SPECIAL_A对应的平台按键被按下时，应该加入到inputstring的字符,通常为‘#’
	 * \param cSPecialBKey (in)当引擎按键GBKEY_AMB_SPECIAL_B对应的平台按键被按下时，应该加入到inputstring的字符,通常为‘*’
	 * \param cSPecialCKey (in)当引擎按键GBKEY_AMB_SPECIAL_C对应的平台按键被按下时，应该加入到inputstring的字符
	 * \param cSPecialDKey (in)当引擎按键GBKEY_AMB_SPECIAL_D对应的平台按键被按下时，应该加入到inputstring的字符
	 * \return 
		 - GBE_API_GBIS_IS_NULL：参数pGBIS为NULL
		 - GBOK：成功返回
	 * \note 这个函数只有在Alphabetic语言的KeyMapping中那些*或者#键有字母情况下才需要使用，设置了Mapping之后，这些键的原来的按键意义将会失效，可以将对应的参数设置为0来关闭此功能
	 * \author chenbinghui
	 * \date 2009年11月4日
	 */
	GBAPI GBRETURN GBMMISetSpecialKeyMapping(pGBInputStruct pGBIS, 
		GBINT cSpecialAKey,
		GBINT cSPecialBKey,
		GBINT cSPecialCKey,
		GBINT cSPecialDKey);

	/*! \example GBMMISetQwertyMapArray
	 */
	/*!
	 * \brief 设置Qwerty键盘映射数组
	 * \param pGBIS 引擎对外交互数据
	 * \param ppcQwertyMapArray （in）Qwerty键盘按键映射2维数组
	 * \param cQwertyMapNum （in）Qwerty键盘按键映射2维数组元素个数
	 * \return 
		 - GBOK 设置成功
		 - GBE_API_GBIS_IS_NULL 函数的参数pGBIS为NULL
	 * \note
		 - ppcQwertyMapArray[0] 为Qwerty输入字符串，通常为“a-z"
		 - ppcQwertyMapArray[1] 为输入字符串对应的字符串，通常为“0-9"，也可以包含任何对应的字符
	 * \author haj
	 * \date 2011-4-25
	 */
	GBAPI GBRETURN GBMMISetQwertyMapArray(pGBInputStruct pGBIS, GBLPCWCHAR * ppcQwertyMapArray,	const GBU32 cQwertyMapNum);


	/*@}*/

	/*!
	 * \defgroup Version 国笔版本号相关函数
	 */
	/*@{*/

	/*! \example GBGetOEMID
	 */
	/*!
	 * \brief  获得此引擎的OEMID编号，该编号唯一指定了每一个OEM
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pOEMID (out)获取OEM ID
	 * \return 
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年11月4日
	 */
	GBAPI GBRETURN GBGetOEMID(pGBInputStruct pGBIS, GBI32 * pOEMID);

	/*! \example GBGetBuildID
	 */
	/*!
	 * \brief 获得此引擎的Build编号，该编号唯一指定了每一个Release
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pBuildID (out)获取Build ID
	 * \return 
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年11月4日
	 */
	GBAPI GBRETURN GBGetBuildID(pGBInputStruct pGBIS, GBI32 * pBuildID);

	/*! \example GBGetEngineVersion
	 */
	/*!
	 * \brief 获得此引擎的功能版本
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param pEnginVersion (out)获取版本号
	 * \return 
		 - GBOK：成功返回
	 * \author chenbinghui
	 * \date 2009年11月4日
	 */
	GBAPI GBRETURN GBGetEngineVersion(pGBInputStruct pGBIS, GBVersion * pEnginVersion);
	/*@}*/


	/*!
	* \defgroup Timer	MultiTap定时器
	*/
	/*@{*/

	enum GBTimerTypeEnum 
	{
		GBTT_MultiTap = 100		///<MultiTap
	};

	/*! \example fpGBRequestTimer_t
	 */
	/*!
	 * \brief OEM提供的一个设置一个Timer的功能的回调函数。
	 * \param nTimerType Timer的类型，为GBTimerTypeEnum中的一个
	 * \param pOEMPrivateData \ref GBMMIAttachTimerFunction函数对应
	 * \return 一个32位的整数，表示这个Timer，此ID会作为killTimer的参数使用
	 * \note 引擎在MultiTap开始的时候将会调用此函数设置一个Timer，该Timer触发的时候，
	 *       OEM需要通过GBMMIHandleKeyEvent函数给GBMMI发送一个GBKEY_Ok的消息，以便
	 *       MultiTap输入模式正常工作。函数的pOEMPrivateData为OEM调用\ref GBMMIAttachTimerFunction
	 *       函数中pOEMPrivateData参数的值，OEM自己设置、维护。
	 * \author chenbinghui
	 * \date 2009年7月31日
	 */
	typedef GBU32 (* fpGBRequestTimer_t)(GBLPVOID pOEMPrivateData, GBINT nTimerType);

	/*! \example fpGBRequestKillTimer_t
	*/
	/*!
	 * \brief OEM提供的一个回调函数，该函数提供取消Timer的功能。
	 * \param nTimerID fpGBRequestTimer的函数返回值
	 * \param pOEMPrivateData \ref GBMMIAttachTimerFunction函数的传入的参数
	 * \return 1表示成功，0表示失败。
	 * \note 函数的pOEMPrivateData为OEM调用\ref GBMMIAttachTimerFunction
	 *       函数中pOEMPrivateData参数的值，OEM自己设置、维护。
	 *       返回1的时候表示成功，返回0的失败
	 * \author chenbinghui
	 * \date 2009年7月31日
	 */
	typedef GBU32 (* fpGBRequestKillTimer_t)(GBLPVOID pOEMPrivateData, GBU32 nTimerID);


	/*! \example GBMMIAttachTimerFunction
	 */
	/*!
	 * \brief OEM为引擎设置Timer相关的函数和参数
	 * \param pGBIS (in)pGBInputStruct对象
	 * \param requestTimer (in)用户指定timer回调函数，与平台相关
	 * \param killTimer (in)用户销毁timer回调函数，与平台相关
	 * \param pOEMPrivateData (in)用户自定义数据类型
	 * \return 
		- GBOK：成功返回
		- GBE_API_GBIS_IS_NULL：pGBIS为NULL
		- GBE_API_INVALID_PARAM：函数的参数至少包含一个无效参数
	 * \note 定时器触发的时候，用户需要调用GBMMIHandleKeyEvent传入一个OK键的按下消息。以完成MultiTap动作
	 * \author chenbinghui
	 * \date 2009年7月31日
	 */
	GBAPI GBRETURN GBMMIAttachTimerFunction(pGBInputStruct pGBIS, 
		fpGBRequestTimer_t requestTimer,
		fpGBRequestKillTimer_t killTimer,
		GBLPVOID pOEMPrivateData);

	/*! \example GBALPSetAbbreviateWordTreeEnable
	*/
	/*!
	* \brief 设置是否搜索缩写词表树
	* \param pGBIS (in) pGBInputStruct对象
	* \param enable (in) 0:不搜索缩写词表树；1：搜索缩写词表树
	* \return 
	* \note return 0表示成功，否则表示失败。
		-在无缝切换的时候应该搜索，其它的时候则不搜索
	* \author zhonghuajin
	* \date 2010-10-14
	*/
	GBAPI GBRETURN GBALPSetAbbreviateWordTreeEnable(pGBInputStruct pGBIS, GBINT enable);
#ifdef __cplusplus
};
#endif

#endif
