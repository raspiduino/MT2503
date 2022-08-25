/***************************************************************************
* File Name    :  GBEngine.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  
*                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Purpose      :  封装国笔输入法引擎
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/
#ifndef __GBENGINE_H_
#define __GBENGINE_H_

#include "gbapi.h"
#include "gbdef.h"
#include "gbim.h"
#include "gbtype.h"
#include "GBIMEDef.h"

/*! 当前输入状态 */
typedef enum 
{
	GBStatus_Normal
	,GBStatus_Shift
	,GBStatus_Caplock
}GBShiftCapStatus;

/*!
 * \brief 国笔引擎全局数据
 */
typedef struct __tagGBEngine
{
	GBInputStruct		g_gbis;					///输入法状态保存以及数据交换区域
	GBAuxInfo			g_aux;					///辅助输出结构体
	GBLDB				g_ldbs[GBIME_MAX_DB_COUNT];	///<语言数据
	GBU16				g_nDataCount;			///<语言数据个数
	GBBOOL				engine_opened;			///<引擎是否打开
	GBBOOL				input_mode_is_valid;	///<输入模式是否合法(合法则表示允许输入了)	
//	GBBOOL				isSwitchNextInputMode;	///<是否切换到下一个输入模式

	// UDB 相关
	GBI32				master_udb_id;			///<主UDB ID
	GBI32				slave_udb_id;			///<从UDB ID
	GBBOOL				master_udb_loaded;		///<主UDB是否加载
	GBBOOL				slave_udb_loaded;		///<从UDB是否加载
} CGBEngine, *PCGBEngine;

#ifndef GBIME_CFG_STATIC_DB // 外部数据文件路径
	#define GBIME_DB_FILE_EN "./Engine/gb_en.ebd"
	#define GBIME_DB_FILE_SC "./Engine/gb_sc.ebd"
#endif // GBIME_CFG_STATIC_DB

/*!
 * \brief 获取国笔引擎实例对象句柄
 * \return 
 */
PCGBEngine GBEngine_GetEnineInstance(void);

/*!
 * \brief 获取国笔引擎输入实例对象句柄
 * \return 
 */
pGBInputStruct GBEngine_GetEnineInputStruct(void);


/*!
 * \brief 设置国笔引擎页面配置
 * \param pEngine
 * \return see GBRETURN
 * \note 
 */
GBRETURN GBEngine_SetPageOption(PCGBEngine pEngine, GBBOOL isFtePage);


/*!
 * \brief 初始化国笔输入法引擎
 * \param pEngine 
 * \return 
 * \note 调用任何国笔引擎API之前必须先执行该函数
 *\example

 */

GBRETURN GBEngine_Initialize(PCGBEngine pEngine);

/*!
 * \brief 关闭国笔输入法引擎，所有绑定到引擎的MDB, UDB将被断开 
 * \param pEngine 
 * \return 
 * \note 如果需要继续调用引擎API，需要重新调用GBEngine_Initialize
 *\example
 */
GBRETURN GBEngine_Terminate(PCGBEngine pEngine);

/*!
 * \brief 国笔输入法引擎GBMMI状态重置
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBRETURN GBEngine_Reset(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎是否打开
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_IsOpened(PCGBEngine pEngine);

/*!
 * \brief 切换国笔输入法引擎输入模式及语言环境
 * \param pEngine
 * \param input_mode 
 * \param nLangID 
 * \param nSubLangID 
 * \return 
 * \note 
 *\example
 */
GBRETURN GBEngine_SwitchInputMode(PCGBEngine pEngine, GBINT input_mode, GBINT nLangID, GBINT nSubLangID);

/*!
 * \brief 判断引擎是否准备好接收用户输入了
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_IsReadyInput(PCGBEngine pEngine);

/*!
 * \brief 发送按键消息给引擎处理
 * \param pEngine 
 * \param evt 
 * \param param 
 * \return 
 * \note 
 *\example
 */
GBU32 GBEngine_SendKeyEvent(PCGBEngine pEngine, GBINT evt, GBU32 param );


/*!
 * \brief 获取引擎当前输入语言
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_GetCurLang(PCGBEngine pEngine);

/*!
 * \brief 获取引擎当前输入模式
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_GetInputMode(PCGBEngine pEngine);

/*!
 * \brief 是否常规按键
 * \param pEngine 
 * \param event 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_IsNormalKey(PCGBEngine pEngine, GBINT event);

/*!
 * \brief 当前状态下面是否应该处理上下左右OK和删除等功能按键【判断国笔候选框是否激活】
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_IsActive(PCGBEngine pEngine);

/*!
 * \brief 是否可以上屏
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_CanUpScreen(PCGBEngine pEngine);


///////////////////////////////////////////////////////////////////////////////////////////////////
// 以下操作仅针对INPUT_MODE_IS_AMB_CHN( 处于这种输入模式下才可能有多个音节候选)
///////////////////////////////////////////////////////////////////////////////////////////////////

/*!
 * \brief 输入模式是否是模糊的中文输入法，模糊的中文输入法才存在拼音的候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_Is_AMB_Chn(PCGBEngine pEngine);

/*!
 * \brief 当前状态下是否可能存在音节候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_HaveSyllable(PCGBEngine pEngine);

/*!
* \brief 获取当前页拼音音节的个数，拼音会根据GBSetPageOption
*  里面拼音的分页信息来分页， 如果需要返回所有的拼音候选，
*  则只需要把GBSetPageOption 中拼音的分页设置为返回GB_MAX_SYLLABLES个拼音即可
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_GetSyllableNum(PCGBEngine pEngine);

/*!
 * \brief 获取拼音音节buffer
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBPCWCHAR * GBEngine_GetSyllableBuffer(PCGBEngine pEngine);

/*!
 * \brief 存在上一页音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HavePrevSyllPage(PCGBEngine pEngine);

/*!
 * \brief 存在下一页音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HaveNextSyllPage(PCGBEngine pEngine);

/*!
 * \brief 获取上一页音节
 * \param pEngine 
 * \return 
 * \note 
 * \date 2010-7-22 16:48:17
 */
void GBEngine_GetPrevSyllPage(PCGBEngine pEngine);

/*!
 * \brief 获取下一页音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetNextSyllPage(PCGBEngine pEngine);

/*!
 * \brief 存在上一个音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HavePrevSyllable(PCGBEngine pEngine);

/*!
 * \brief 存在下一个音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HaveNextSyllable(PCGBEngine pEngine);

/*!
 * \brief 获取上一个音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetPrevSyllable(PCGBEngine pEngine);

/*!
 * \brief 获取下一个音节
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetNextSyllable(PCGBEngine pEngine);

/*!
 * \brief 选中指定索引的拼音音节
 * \param pEngine 
 * \param idx 
 * \return 
 * \note 
 *\example
 */
void GBEngine_select_syll_in_page(PCGBEngine pEngine, GBU16 idx );

/*!
 * \brief 获取当前音节索引
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_GetCurrentSyllableIndex(PCGBEngine pEngine);

///////////////////////////////////////////////////////////////////////////////////////////////////
// 以下操作仅针对候选
///////////////////////////////////////////////////////////////////////////////////////////////////

/*!
 * \brief 存在候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_HaveCandidate(PCGBEngine pEngine);

/*!
 * \brief 获取候选总个数
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU16 GBEngine_GetCandNum(PCGBEngine pEngine);

/*!
 * \brief 获取候选字Buffer
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBPCWCHAR * GBEngine_GetCandidateBuffer(PCGBEngine pEngine);

/*!
 * \brief 是否存在上一页候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HavePrevCandPage(PCGBEngine pEngine);

/*!
 * \brief 是否存在下一页候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU8 GBEngine_HaveNextCandPage(PCGBEngine pEngine);

/*!
 * \brief 获取上一页候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetPrevPageCandidate(PCGBEngine pEngine);

/*!
 * \brief 获取下一页候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetNextPageCandidate(PCGBEngine pEngine);

/*!
 * \brief 存在上一个候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_HavePrevCandidate(PCGBEngine pEngine);

/*!
 * \brief 获取上一页联想字
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetPrevPageAssociates(PCGBEngine pEngine);


/*!
 * \brief 获取下一页联想字
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetNextPageAssociates(PCGBEngine pEngine);


/*!
 * \brief 存在下一个候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_HaveNextCandidate(PCGBEngine pEngine);

/*!
 * \brief 获取上一个候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetPrevCandidate(PCGBEngine pEngine);

/*!
 * \brief 获取下一个候选
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_GetNextCandidate(PCGBEngine pEngine);

/*!
 * \brief 选择当前候选分页中的指定下标的候选
 * \param pEngine
 * \param idx 
 * \return 
 * \note 
 *\example
 */
void GBEngine_SelCandidateByIndex(PCGBEngine pEngine, GBU32 idx);

/*!
 * \brief 获取联想字符串(目前只支持中文)
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBRETURN GBEngine_GetAssocWord(PCGBEngine pEngine, GBLPCWCHAR pConfirmedWord );

/*!
 * \brief 获取笔画区内码串
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBWCHAR * GBEngine_GetStorkeString(PCGBEngine pEngine);

/*!
 * \brief 获取部首区内码串
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBWCHAR * GBEngine_GetComponentsString(PCGBEngine pEngine);

///////////////////////////////////////////////////////////////////////////////////////////////////
// 引擎交互缓冲区访问
///////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \brief 获取需要上屏的字符串
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBWCHAR * GBEngine_GetUpScreenString(PCGBEngine pEngine);

/*!
 * \brief 清空需要上屏的字符串
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
void GBEngine_ClearUpScreenString(PCGBEngine pEngine);

/*!
 * \brief 获取输出串（中文输入法自造词的时候已经选择了的词语以及后面的输入串）
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBPCWCHAR GBEngine_GetOutputString(PCGBEngine pEngine);

/*!
 * \brief 获取输入序列
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBPCWCHAR GBEngine_GetInputString(PCGBEngine pEngine);

/*!
 * \brief 获取输入模式的具体状态,在GBMMI的API里面输出
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBU16 GBEngine_GetCurStatus(PCGBEngine pEngine);

/*!
 * \brief 是否可按上键上屏
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetUpScreenArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示候选上箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetCandUpArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示候选下箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetCandDownArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示候选左箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetCandLeftArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示候选右箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetCandRightArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示音节左箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetSyllableLeftArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 是否显示音节右箭头
 * \param pEngine 
 * \return 
 * \note 
 *\example
 */
GBBOOL GBEngine_GetSyllableRightArrowFlag(PCGBEngine pEngine);

/*!
 * \brief 设置国笔输入法引擎的候选类型，会影响用户输出候选的方式
 * \param pEngine 
 * \param nCandType 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_SetCandType(PCGBEngine pEngine, GBINT nCandType);

/*!
 * \brief 设置引擎配置
 * \param pEngine 
 * \param engine_id 
 * \param config 
 * \param option 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_SetEngineOption(PCGBEngine pEngine, GBINT engine_id, GBU32 config, GBU32 option);

/*!
 * \brief 重新绑定UDB(在切换语言和输入法时调用)
 * \param pEngine
 * \return
 * \note 如果之前UDB Buffer已经设置为其他的语言，那么需要保存之前数据，
 * 同时将同一个UDB Buffer使用到新的语言的自造上面，
 * 这样做法会节约RAM空间，但是会导致一个副作用，就是在无缝切换之后
 * 切换到的语言没有自造词里面的候选。
 * 也可以申请两个UDB Buffer，给主语言以及切换的语言分别一个UDB Buffer。这样可以
 * 解决上面的问题，但是会增加RAM空间。
 */
GBRETURN GBEngine_LoadUDB(PCGBEngine pEngine);

/*!
 * \brief 卸载UDB
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_UnLoadUDB(PCGBEngine pEngine);

/*!
 * \brief 设置国笔输入法引擎标点符号输入选项
 * \param pEngine 
 * \param cKey 
 * \param pSymbols 
 * \param cSplit 
 * \param nCandListType 
 * \param nCandDesireRow 
 * \param nCandCountPerRow 
 * \param nOption 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_RegisterInterpunctionKeyEx(PCGBEngine pEngine,
							GBINT cKey,
							GBLPCWCHAR pSymbols,
							GBINT cSplit,
							GBINT nCandListType,
							GBINT nCandDesireRow,
							GBINT nCandCountPerRow,
							GBUINT nOption);

/*!
 * \brief 注销国笔输入法引擎标点符号功能键
 * \param pEngine 
 * \param cKey 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_UnregisterInterpunctionKey(PCGBEngine pEngine, GBINT cKey);



/*!
 * \brief 判断国笔输入法引擎当前是否处于中文输入模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsChineseInputMode(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于Alp输入模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpInputMode(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于MultiTap输入模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsMultiTapStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否使用标点符号输入框类型
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsSymbolCandType(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于初始化状态(刚进入编辑器或每次输入结束时候的状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsInitialStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于输入状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsInputStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于候选择状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsSelectedStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于联想模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAssociateStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsChnUAWStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpUAWStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词开始状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpUAWBeginStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词过程状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpUAWProcessingStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词没有其他候选的时候按下翻状态
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpUAWNoMoreCandStatus(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于外文自造词结束，用户确认加入，这个状态可以关闭
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsAlpUAWConfirmStatus(PCGBEngine pEngine);

/*!
 * \brief 
 * \param pGBIS 
 * \param nInputmod 
 * \param isn 
 * \param indexMulPron 
 * \param pBuff 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_Word2CodesByInputmod(PCGBEngine pEngine, int nInputmod, unsigned short isn,
											GBINT indexMulPron, GBPWCHAR pBuff);

/*!
 * \brief 直接更新输入串获取候选
 * \param pEngine 
 * \param pInputString 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_SetInputString(PCGBEngine pEngine, GBLPCWCHAR pInputString);

/*!
 * \brief 获取行索引起始位置指针 GBMMI使用
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBPBYTE GBEngine_GetRowStart(PCGBEngine pEngine);

/*!
 * \brief 获取当前选择的列 GBMMI使用
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBI8 GBEngine_GetSelCol(PCGBEngine pEngine);

/*!
 * \brief 获取当前选择的行 GBMMI使用
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBI8 GBEngine_GetSelRow(PCGBEngine pEngine);

/*!
 * \brief 获取当前页有效的行数 GBMMI使用
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBU8 GBEngine_GetRowCount(PCGBEngine pEngine);

/*!
 * \brief 判断国笔输入法引擎当前是否处于MultiTap输入模式
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBBOOL GBEngine_IsMultiTapInputMode(PCGBEngine pEngine);

/*!
 * \brief 返回引擎大小写状态标记
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBShiftCapStatus GBEngine_GetShiftCapStatus(PCGBEngine pEngine);

/*!
 * \brief 退出选择状态[数字上屏时需要确保输入栏处于焦点选择状态]
 * \param pEngine 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_ExitSelectedStatus(PCGBEngine pEngine);

/*!
 * \brief 设置国笔输入法引擎的控制键状态，仅对alphabetic语言有效
 * \param pEngine 
 * \param nCandType 
 * \return 
 * \note 
 * \example
*/
GBRETURN GBEngine_SetShiftCap(PCGBEngine pEngine, GBINT bShiftDown, GBINT bCapsLockToggle);

/*!
 * \brief 设置国笔引擎页面配置的显示页面宽度
 * \param pEngine
 * \return see GBRETURN
 * \note 
 */
GBRETURN GBEngine_SetPageToalWidthOption(PCGBEngine pEngine, GBU16 nTotalWidth);

/*!
 * \brief 判断是否是可以切换输入模式状态
 * \param pEngine 
 * \return 
 * \note 用于物理键盘
 * \example
*/
GBBOOL GBEngine_IsNeedSwitchInputModeState(PCGBEngine pEngine);

/*!
* \brief 获取国笔候选框实际显示行数(由联想状态下的行数决定)
* \param void
* \return 候选候选框实际显示行数
*/
GBINT GBEngine_GetCandDisplayAssociateRowCount(PCGBEngine pEngine);


/*!
* \brief 获取国笔候选框实际显示行数(输入状态候选栏行数+1)
* \param void
* \return 候选候选框实际显示行数
*/
GBINT GBEngine_GetCandDisplayInputRowCount(PCGBEngine pEngine);

#endif //__GBENGINE_H_