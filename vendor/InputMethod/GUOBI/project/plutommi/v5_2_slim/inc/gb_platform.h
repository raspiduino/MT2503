/***************************************************************************
 * \file        :  Gb_platform.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Author       :  weizhiping
 * Date         :  2010-1-5
 * Purpose      :  国笔输入法与目标移植平台紧密关联的代码实现
 * Version      :  V0.1
 * Last Changed List
 * Name         |   date   |  Discription
 * weizhiping    2010-1-5    将GBV5引擎移植层代码划分为平台相关和平台无关两部分
 ****************************************************************************/
#ifndef __GB_PLATFORM_H__
#define __GB_PLATFORM_H__

#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "IMERes.h"
#include "ImeGprot.h"
#include "Word_engine.h"  
#include "Imc_symbol.h"
#include "Imc_config.h"
#include "ImmProt.h"
#include "PixtelDataTypes.h"
#include "MMI_features.h"
#include "oslmemory.h"
#include "GlobalConstants.h"
#include "Eventsdef.h"
#include "Frameworkstruct.h"
#include "EventsDef.h"
#include "Wgui.h"
#include "Timerevents.h"
#include "DebugInitDef.h"
#include "CustDataRes.h"
#include "MessagesResourceData.h"
#include "GlobalDefs.h"
#include "Gui_config.h"
#include "gdi_lcd_config.h"
#include "gui_ems.h"
#include "wgui_categories_inputs.h"
#include "gui.h"
#include "gui_themes.h"
#include "Wgui_softkeys.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_util.h"
#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "MMI_features.h"
#include "imc.h"
#include "CommonScreens.h"
#include "Multitap_engine.h"
#include "GBEngine.h"
#include "gb_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GB_SYSTEM_PATH      L"c:\\@gb\\" // 国笔系统文件夹

/*!
 * \brief 映射平台的文件系统接口供国笔封装实现调用
 */
#define FILE_HANDLE          	FS_HANDLE
#define PFS_READ           		FS_READ_ONLY
#define PFS_WRITE          		FS_READ_WRITE|FS_CREATE_ALWAYS
#define pfopen(x,y)        		FS_Open((U16 *)x,y)
#define pfclose(x)         		{ FS_Commit(x); FS_Close(x); }
#define pfwrite(x1,x2,x3,x4,x5) FS_Write(x4,x1,x3,(U32 *)x5)
#define pfread(x1,x2,x3,x4,x5)  FS_Read(x4,x1,x3,(U32 *)x5)

// 字符串接口
#define GBStrLen 				wcslen

#define ARRAY_DIM(a)			(sizeof(a) / sizeof((a)[0])) ///<获取数组元素数目

/*!
 * \brief 国笔按键类型定义
 */
enum KeyType {
	gbKeyNum = 1,
	gbKeyArrow = 2,
	gbKeyStar = 4,
	gbKeyPound = 8,
	gbKeyStarPound = gbKeyStar + gbKeyPound,
	gbKeyOK = 16,
	gbKeyAll = (U16)-1
};

/*!
 * \brief 清除映射的国笔按键处理函数
 * \param type 参见KeyType
 * \return
 * \note
 * \author weizhiping
 * \date 2009年12月11日
 */
extern void GBClearKeyHandler(U16 type);

/*!
 * \brief 清除国笔设置的按键处理函数
 * \param 
 * \return 
 * \note 
 * \author weizhiping
 * \date 2009年12月11日
 */
extern void GBClearAllKeyHandler(void);

/*!
 * \brief 重置国笔按键、软键盘状态(恢复为系统默认状态)
 * \param 
 * \return 
 * \note 
 * \author weizhiping
 * \date 2009年12月16日
 */
extern void GBResetFuncKey(void);

// 国笔触摸点击区域
#ifdef __MMI_TOUCH_SCREEN__
#define GB_MAX_REGION_COUNT 32

/*!
 * \brief 国笔触摸区操作返回值枚举 
 */
typedef enum
{
	GBTOUCH_REGION_INVALID
	,GBTOUCH_REGION_PEN_DOWN
	,GBTOUCH_REGION_PEN_UP
}GBTouchRegionRet;

typedef struct __GB_Touch_Region
{
	GBU16 left, top, right, bottom;
    GBINT gbEvent;
    GBU32 param;
}GBTouchRegion;

typedef struct __GB_Touch_Regions
{
	GBTouchRegion regions[GB_MAX_REGION_COUNT];
	GBINT regionsCount;
	GBBOOL bInvertCandidateFlag; ///<候选反显
	GBINT pressCandidateRow; ///<反显候选行下标
	GBINT pressCandidateCol; ///<反显候选列下标
}GBTouchRegions;

/*!
 * \brief 插入一个国笔触摸区
 * \param 
 * \return GBTrue: 成功；GBFalse: 失败
 * \note 只有触摸区空间不够才会返回失败, 请检查GB_MAX_REGION_COUNT大小
 * \author weizhiping
 * \date 2010年3月3日
 */
extern GBBOOL GBTouchRegion_Insert(GBU16 left, GBU16 top, GBU16 right, GBU16 bottom, GBINT gbEvent, GBU32 param);

/*!
 * \brief 国笔触摸区点击检测函数
 * \param point: 测试点
 * \param pHittedRegion: 如果单击成功则将被点击区域信息保存在此输出参数
 * \return 是否点击成功
 * \note 如果点击测试失败，pHittedRegion的输出值无效，请勿使用
 */
extern GBTouchRegionRet GBTouchRegion_HitTest(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point, GBTouchRegion * pHittedRegion);

/*!
 * \brief 清空国笔触摸区
 * \param 
 * \return 
 * \note 

 */
extern void GBTouchRegion_ResetRegionData(void);

/*!
 * \brief 重置国笔触摸区反显候选标记
 * \param 
 * \return 
 * \note 

 */
extern void GBTouchRegion_ResetInvertCandidateFlag(void);

/*!
 * \brief 获取触摸区反显候选标记
 * \param oid 
 * \return 
 * \note 
 *\example
 */
extern GBBOOL GBTouchRegion_GetInvertCandidateFlag(void);

/*!
 * \brief 获取触摸区反显候选行索引
 * \param void 
 * \return 
 * \note 
 *\example

 */
extern GBINT GBTouchRegion_GetPressCandidateRow(void);

/*!
 * \brief 获取触摸区反显候选列索引
 * \param void 
 * \return 
 * \note 
 *\example

 */
extern GBINT GBTouchRegion_GetPressCandidateCol(void);

#define Point_Is_In_Region(x, y, pRegion) \
	((x) >= (pRegion)->left && (x) <= (pRegion)->right \
	&& (y) >= (pRegion)->top && (y) <= (pRegion)->bottom)

	extern void mmi_pen_editor_handler_before_show_guobi(void);
	extern int mmi_pen_guobi_is_handle_writing(void);
	extern int mmi_pen_guobi_is_multiblock_hw(void);
	extern void mmi_pen_editor_guobi_touch_cand_show(void);
	extern int mmi_pen_guobi_is_vk_show(void);
	extern void mmi_pen_editor_guobi_vk_hide(void);
	extern int  mmi_pen_guobi_is_in_vk_cand(void);
#endif
	extern void wgui_hide_right_softkey(void);
	extern mmi_imm_input_mode_enum g_mmi_imm_current_input_mode;
	extern void (*g_imc_key_inputbox_LSK_function) (void);
#if defined(UI_EMS_SUPPORT)
	extern UI_EMS_input_box MMI_EMS_inputbox;
#endif
extern single_line_input_box MMI_inline_singleline_inputbox;
extern void wgui_set_EMS_inputbox_RSK(void);
extern void register_EMS_inputbox_keys(void);
extern void wgui_hide_left_softkey(void);
extern MMI_BOOL EMS_inputbox_multitap_input(UI_character_type c);
extern void EMS_inputbox_multitap_input_complete(void);
extern void redraw_EMS_inputbox(void);

/*!
 * \brief 计算 char 类型的字符串占多少点宽度
 * \param str 源字符串
 * \return 此Ascii字符串的像素宽度
 * \note

 */
extern long GB_GetAsciiStringWidth(char * str);

/*!
 * \brief 计算 Unicode  类型的字符串占多少点宽度
 * \param pParam 参见GBGlobalPageOption.pGetStringWidthParam的设置
 * \param str 源字符串
 * \return 此Unicode字符串的像素宽度
 * \note 调用范例
 	GBGlobalPageOption pageOption;
 	GBGetPageOption(pGbis, &pageOption);
	pageOption.fpGetWStringWidth = GB_GetWStringWidth;
	GBSetPageOption(pGbis, &pageOption);

 */
extern int GB_GetWStringWidth(void * pParam, GBLPCWCHAR str);

/*!
 * \brief 给MTK 平台IMC发送按键消息
 * \param msg_id: 消息id
 * \param param_0: 参数1, 通常为长度
 * \param param_1: 参数2, 通常为字符或字符串头指针地址
 * \return
 * \note

 */
extern U32  GB_imc_key_send_message(U8 msg_id, U32 param_0, U32 param_1);


/*!
 * \brief 国笔输入框类型
 */
enum GBInputBoxType
{
	GBSinglineInputBox,
	GBMultilineInputBox,
	GBEMSInputBox,
	GBInlineInputBox
};

/*!
 * \brief 国笔输入框
 */
typedef struct __IInputBox {
	MMI_BOOL (*pfUpscreen)(UI_character_type c); ///<上屏回调
	void (*pfSetRSK)(void); ///<设置RSK响应函数的回调(右软键)
	void (*pfSetArrowKey)(void); ///<设置方向键响应函数的回调
	void (*pfDeleteAll)(void); ///<内容清空回调
	U8 (*pfInputBoxIsEmtpy)(void); ///<判断输入框是否空的回调
	void (*pfChangeInputMode)(void); ///<输入法切换回调
	enum GBInputBoxType type;
} GBIInputBox;
extern GBIInputBox gbCurInputBox;

/*!
 * \brief 设置国笔输入框
 * \param pIInputBox 国笔输入框结构体
 * \return
 * \note

 */
extern void GBSetCurInputBox(const GBIInputBox * pIInputBox);

/*!
 * \brief 判断单行文本输入框内容是否为空
 * \param
 * \return
 * \note

 */
extern BOOL GBSinglineInputBoxIsEmpty(void);

/*!
 * \brief 判断短信文本输入框内容是否为空
 * \param
 * \return
 * \note

 */
extern BOOL GBEMSInputBoxIsEmpty(void);

/*!
 * \brief 判断Inline输入框内容是否为空
 * \param void 
 * \return 
 * \note 
 *\example

 */
 #ifndef __MMI_INLINE_SLIM__
extern BOOL GBInlineInputBoxIsEmpty(void);
#endif

/*!
 * \brief 国笔输入法默认的上屏函数(将输出信息结构体中的上屏字符串直接显示到平台输入框)
 * \param 
 * \return 
 * \note

 */
void GBInputBox_UpScreen(void);

/*!
 * \brief 检测文件夹是否存在，如果不存在则创建之
 * \param
 * \return
 * \note 

 */
GBBOOL GB_check_folder(GBPCWCHAR pFoldPath);

/*!
 * \brief 使能可视化显示空格、回车等符号功能
 * \param void 
 * \return 
 * \note 
 *\example

 */
void GB_EnableProprietarySymbolDisplay(void);

/*!
 * \brief 禁用可视化显示空格、回车等符号功能
 * \param void 
 * \return 
 * \note 
 *\example

 */
void GB_DisableProprietarySymbolDisplay(void);

/*!
 * \brief 对特殊字符的切换，主要针对空格、回车、笔画
 * \param pOldStr 原字符串
 * \param pNewStr 
 * \param font 字体大小
 * \return 返回该字符串的宽度
 * \note 该函数不对传入参数进行字节检查，传入时需要注意,pOldStr必须是字符串。pNewStr空间必须足够
 *\example

 */
GBINT GB_ProprietarySymbolSwitch(GBPCWCHAR pOldStr, GBPWCHAR pNewStr);

#ifdef __cplusplus
};
#endif

#endif
