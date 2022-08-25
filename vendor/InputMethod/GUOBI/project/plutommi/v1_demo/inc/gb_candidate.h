/***************************************************************************
 * \file        :  gb_candidate.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Purpose      :  国笔输入法候选框显示模块头文件
 * Version      :  V1.0
 * Last Changed List
 * Name         |   date   |  Discription
 ****************************************************************************/
#ifndef __GB_CANDIDATE_H__
#define __GB_CANDIDATE_H__

#include "Gbtype.h"
//#include "mmi_include.h"
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief 配置候选行数(包括: 传统的单行候选 和 新增的多行候选)
 */
#define SL_INPUT_CAND_ROW_COUNT	 	1 ///<必须小于 <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define SL_ASSOCIATE_CAND_ROW_COUNT 2 ///<必须小于 <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define ML_INPUT_CAND_ROW_COUNT	 	2 ///<必须小于 <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define ML_ASSOCIATE_CAND_ROW_COUNT 3 ///<必须小于 <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT

/*!
 * \brief UI相关的宏定义 , 下面部分非常重要，界面微调将重点修改此处
 * \note 需要根据LCD尺寸来调整输入法UI
 */

 #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
		#define UP_DOWN_TIPS_HEIGHT				4 ///<上下方向箭头的高度
		#define UP_DOWN_TIPS_WIDTH				8 ///<上下方向箭头的宽度
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<左右方向箭头的高度
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<左右方向箭头的宽度
		#define UP_DOWN_TIPS_INTERVAL				2 ///<上下方向箭头之间的间隔(单行候选时使用)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<左右方向箭头之间的间隔
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<一行中文候选字的个数,计算方法: (屏幕的宽度-图标-其它数字索引)/单个汉字的宽度
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<一行中文符号显示个数,建议和候选字数一样
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<一行英文字显示个数,计算方法和中文一样(等宽计算)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<一行英文最多可显示的字符的个数

		#define CHINESE_FONT_HEIGHT				20
		#define CAND_FONT_PADDING					5  ///<字符需要垂直居中显示，上下留出间隙
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<国笔候选框每一栏的高度(音节栏和候选栏等高)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height-1) ///<从输入界面内容区底部开始画国笔候选框
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<候选框顶部	

		#define CAND_LEFT							0
		#define CAND_RIGHT							(UI_DEVICE_WIDTH) ///<国笔候选框的右边位置		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<国笔候选框的总显示宽度【※】

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<国笔输入栏宽度(留出2个提示箭头的位置)【※】
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<国笔输入栏高度【※】
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<国笔候选栏宽度【※】

		#define SELECTOR_WIDTH						8  ///<国笔索引数字的宽度
		#define SELECTOR_HEIGHT					12 ///<国笔所以数字的高度
		#define COMP_WIDTH							16 ///<国笔部首的宽度
		#define COMP_HEIGHT						16 ///<国笔部首的高度

#elif defined(__MMI_MAINLCD_176X220__) //LCD 176宽x220高
		#define UP_DOWN_TIPS_HEIGHT				4 ///<上下方向箭头的高度
		#define UP_DOWN_TIPS_WIDTH				8 ///<上下方向箭头的宽度
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<左右方向箭头的高度
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<左右方向箭头的宽度
		#define UP_DOWN_TIPS_INTERVAL				2 ///<上下方向箭头之间的间隔(单行候选时使用)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<左右方向箭头之间的间隔
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<一行中文候选字的个数,计算方法: (屏幕的宽度-图标-其它数字索引)/单个汉字的宽度
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<一行中文符号显示个数,建议和候选字数一样
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<一行英文字显示个数,计算方法和中文一样(等宽计算)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<一行英文最多可显示的字符的个数

		#define CHINESE_FONT_HEIGHT				16
		#define CAND_FONT_PADDING					3  ///<字符需要垂直居中显示，上下留出间隙
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<国笔候选框每一栏的高度(音节栏和候选栏等高)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height - 1) ///<从输入界面内容区底部开始画国笔候选框
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<候选框顶部	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<国笔候选框的右边位置		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<国笔候选框的总显示宽度【※】

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<国笔输入栏宽度(留出2个提示箭头的位置)【※】
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<国笔输入栏高度【※】
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<国笔候选栏宽度【※】

		#define SELECTOR_WIDTH						8  ///<国笔索引数字的宽度
		#define SELECTOR_HEIGHT					12 ///<国笔所以数字的高度
		#define COMP_WIDTH							16 ///<国笔部首的宽度
		#define COMP_HEIGHT						16 ///<国笔部首的高度

#elif (defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__))    //LCD 128宽x160高 LCD 128X128  
		#define UP_DOWN_TIPS_HEIGHT				4 ///<上下方向箭头的高度
		#define UP_DOWN_TIPS_WIDTH				8 ///<上下方向箭头的宽度
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<左右方向箭头的高度
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<左右方向箭头的宽度
		#define UP_DOWN_TIPS_INTERVAL				2 ///<上下方向箭头之间的间隔(单行候选时使用)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<左右方向箭头之间的间隔
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<一行中文候选字的个数,计算方法: (屏幕的宽度-图标-其它数字索引)/单个汉字的宽度
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<一行中文符号显示个数,建议和候选字数一样
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<一行英文字显示个数,计算方法和中文一样(等宽计算)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<一行英文最多可显示的字符的个数

		#define CHINESE_FONT_HEIGHT				14
		#define CAND_FONT_PADDING					3  ///<字符需要垂直居中显示，上下留出间隙
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<国笔候选框每一栏的高度(音节栏和候选栏等高)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height - 1) ///<从输入界面内容区底部开始画国笔候选框
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<候选框顶部	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<国笔候选框的右边位置		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<国笔候选框的总显示宽度【※】

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<国笔输入栏宽度(留出2个提示箭头的位置)【※】
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<国笔输入栏高度【※】
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<国笔候选栏宽度【※】

		#define SELECTOR_WIDTH						8  ///<国笔索引数字的宽度
		#define SELECTOR_HEIGHT					12 ///<国笔所以数字的高度
		#define COMP_WIDTH							14 ///<国笔部首的宽度
		#define COMP_HEIGHT						14 ///<国笔部首的高度
#else //其他LCD size 模式 如果平台的makefile中MAIN_LCD_SIZE宏一定要定义好
		#define UP_DOWN_TIPS_HEIGHT				4 ///<上下方向箭头的高度
		#define UP_DOWN_TIPS_WIDTH				8 ///<上下方向箭头的宽度
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<左右方向箭头的高度
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<左右方向箭头的宽度
		#define UP_DOWN_TIPS_INTERVAL				2 ///<上下方向箭头之间的间隔(单行候选时使用)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<左右方向箭头之间的间隔
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<一行中文候选字的个数,计算方法: (屏幕的宽度-图标-其它数字索引)/单个汉字的宽度
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<一行中文符号显示个数,建议和候选字数一样
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<一行英文字显示个数,计算方法和中文一样(等宽计算)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<一行英文最多可显示的字符的个数

		#define CHINESE_FONT_HEIGHT				20
		#define CAND_FONT_PADDING					5  ///<字符需要垂直居中显示，上下留出间隙
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<国笔候选框每一栏的高度(音节栏和候选栏等高)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height ) ///<从输入界面内容区底部开始画国笔候选框
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<候选框顶部	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<国笔候选框的右边位置		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<国笔候选框的总显示宽度【※】

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<国笔输入栏宽度(留出2个提示箭头的位置)【※】
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<国笔输入栏高度【※】
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<国笔候选栏宽度【※】

		#define SELECTOR_WIDTH						8  ///<国笔索引数字的宽度
		#define SELECTOR_HEIGHT					12 ///<国笔所以数字的高度
		#define COMP_WIDTH							16 ///<国笔部首的宽度
		#define COMP_HEIGHT						16 ///<国笔部首的高度
#endif //end  __MMI_MAINLCD_240x320__



#define CAND_LINE_SPLIT_WIDTH 					(SELECTOR_WIDTH + 2) ///<候选栏字间隔
#define ALL_COMP_COUNT							29 ///<国笔部首的个数
#define GB_VKBD_CAND_HEIGHT					(CAND_LINE_HEIGHT * 2) ///<国笔候选窗口高度(传给MTK平台),在绘制的时候会根据实际高度调整content的高度

/*!
* \brief UI相关(可能根据不同项目需要调整)
*/
#define GB_SYLLABLE_SPACE						10 ///<国笔音节之间的间隔
#define GB_FONT_COLOR_HOT						UI_COLOR_BLACK ///<HOT时字体颜色
#define GB_BG_COLOR_HOT						gui_color(147, 147, 147)//gui_color(200, 200, 255) ///<HOT时背景颜色
#define GB_FONT_COLOR_SELECTED				UI_COLOR_WHITE ///<选中时字体颜色
#define GB_BG_COLOR_SELECTED					UI_COLOR_BLACK	//gui_color(0, 128, 255) ///<选中时背景颜色
#define GB_FONT_COLOR_NORMAL					UI_COLOR_BLACK ///<未选中时字体颜色
#define GB_BG_COLOR_NORMAL					UI_COLOR_WHITE ///<未选中时背景颜色
#define	GB_ARROW_COLOR						gdi_act_color_from_rgb(255, 0, 0, 0)//gdi_act_color_from_rgb(255, 180, 180, 180)//方向箭头颜色

/*!
* \brief 辅助功能宏定义
*/
#define INDEX_TO_CHAR(i)		('0' + ((i) + 1) % 10) 
#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif

/*!
 * \brief 国笔箭头方向类型定义
 */
typedef enum
{
	GBARROW_UP
	,GBARROW_DOWN
	,GBARROW_LEFT
	,GBARROW_RIGHT
}GBArrowDirType;

/*!
 * \brief 国笔候选框坐标信息(根据候选行数动态计算)
 */
typedef struct tagGBRECT {
	GBINT left;
	GBINT top;
	GBINT right;
	GBINT bottom;
} GBRECT;

typedef struct tagGBCandCoordInfo {	
	GBRECT candWin; 			///<候选窗口主体
	GBINT candWinHeight;		///<候选窗口主体高度
	GBINT backupCandWinHeight;	///<备份候选窗口高度, 当高度变小时需要刷新多余的无效显示区域	
	GBRECT inputArea;			///<输入区(当前用户输入的显示区域，这个区域可能显示按键对应的笔画序列、拼音序列或者按键序列)
	GBRECT candArea;			///<候选区(显示用户按键对应的文本候选)
	GBINT candAreaHeight;		///<候选区高度
	GBRECT leftArrow;			///<←
	GBRECT rightArrow;			///<→
	GBRECT upArrow;				///<↑
	GBRECT downArrow;			///<↓
} GBCandCoordInfo;

/*!
 * \brief 清除国笔候选窗口坐标信息
 * \param
 * \return
 * \note
 */
extern void GBResetCandCoordInfo(void);

/*!
 * \brief 国笔输入框是否处于激活状态
 * \param 
 * \return
 * \note
 */
extern GBBOOL GBCand_IsActive(void);

/*!
 * \brief 用于切换输入法之后检查我们的Virtual Keyboard有没有显示出来
 * \param 
 * \return
 * \note
 */
extern void GBCheckCandWnd(void);

/*!
 * \brief 显示国笔输入法候选框
 * \param 
 * \return
 * \note
 */
extern void GBDrawCandWnd(void);

/*!
 * \brief 关闭国笔输入法候选框
 * \param 
 * \return
 * \note
 */
extern void GBCloseCand(void);

/*!
 * \brief 获取国笔候选窗口高度
 * \param 
 * \return g_CandCoordInfo.candWinHeight
 * \note
 */
extern GBINT GB_GetCandWinHeight(void);

/*!
 * \brief 获取国笔候选窗口top位置
 * \param 
 * \return g_CandCoordInfo.candWin.top
 * \note
 */
extern GBINT GB_GetCandWinTop(void);

/*!
 * \brief 获取候选窗口高度校准差值
 * \param void
 * \return 
 */
GBINT GB_GetCandWinAjustHeight(void);

/*!
 * \brief 重新调整内容显示区域尺寸
 * \param changed_height 调整高度: > 0 增加内容区高度；< 0减少内容区高度
 * \return 
 * \note changed by xyg 080312 for lefrkeys disappeared
 */
void GBResizeContentArea(int changed_height);

/*!
 * \brief 国笔打印字符串的函数,支持矢量字库，系统的gui_print_text会出现对齐问题
 * \param void
 * \
 */

extern void GB_print_text(S32 x, S32 y, const UI_string_type str_ptr);

/*!
 * \brief 从右向左排版标记
 * \param void 
 * \return 
 * \note 
 *\example
 */
 extern BOOL r2lMMIFlag;

extern GBBOOL GB_GetR2LCompositionFlag(void);


/*!
 * \brief 从右向左排版标记的国笔输入法模式
 * \param void 
 * \return 
 * \note 
 *\example
 */
extern GBBOOL GB_IsR2LInputmode(void);


#ifdef __cplusplus
};
#endif

#endif
