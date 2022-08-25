/*------------------------------------------------------------
  Copyright (c) 2006-2007 汉王科技股份有限公司
  
  文件名称:
		HWAPI.h

  创建人：
		秦建辉 jhqin@hanwang.com.cn

  更新日期:
		2007年1月23日

  关键字:
		汉王笔 马蹄莲 OEM
------------------------------------------------------------*/
#ifndef __MTL_HWAPI_H
#define __MTL_HWAPI_H

//#define HANWANG_INTEGRATED_DICT			// 是否代码字典集成
#if !defined(HANWANG_LITTLEENDIAN)
#define HANWANG_LITTLEENDIAN		1	// LittleEndian or BigEndian
#endif
#define HANWANG_DEMO		//是否演示版本
/* -------------------识别字符集------------------------ */
#define ALC_LATIN_LOWERCASE				0x00000001	// 小写拉丁字母
#define ALC_LATIN_UPPERCASE				0x00000002	// 大写拉丁字母

#define ALC_GREEK_LOWERCASE				0x00000004	// 小写希腊字母
#define ALC_GREEK_UPPERCASE				0x00000008  // 大写希腊字母

#define ALC_CYRILLIC_LOWERCASE			0x00000010	// 小写西里尔字母
#define ALC_CYRILLIC_UPPERCASE			0x00000020	// 大写西里尔字母

#define ALC_COMMON_PUNCTUATION			0x00000040	// 常用标点
#define ALC_EXTEND_PUNCTUATION			0x00000080	// 扩展标点

#define ALC_COMMON_SYMBOLS				0x00000100	// 常用符号
#define ALC_EXTEND_SYMBOLS				0x00000200	// 扩展符号

#define ALC_COMMON_NUMERALS				0x00000400	// 常用数字
#define ALC_EXTEND_NUMERALS				0x00000800	// 扩展数字

#if !defined(ALC_GESTURE)
#define ALC_GESTURE						0x00001000	// Gesture 
#endif
#define ALC_EDITCOMMAND					0x00002000	// 编辑命令（复制 剪切 粘贴 撤销）

/* ----------------输出自动转换-------------------------- */
#define	OUT_INVERT						0x10000000	// Not used 
#if !defined(OUT_UPPERCASE)
#define OUT_UPPERCASE					0x20000000	// output Uppercase character 
#endif
#if !defined(OUT_LOWERCASE)
#define OUT_LOWERCASE					0x40000000	// output Lowercase character 
#endif
#define OUT_FULLWIDTH					0x80000000	// output SBC case 

#define ALC_LATIN		(ALC_LATIN_LOWERCASE | ALC_LATIN_UPPERCASE)			// 拉丁字母
#define ALC_GREEK		(ALC_GREEK_LOWERCASE | ALC_GREEK_UPPERCASE)			// 希腊字母
#define ALC_CYRILLIC	(ALC_CYRILLIC_LOWERCASE | ALC_CYRILLIC_UPPERCASE)	// 西里尔字母

#define ALC_ALPHABET	(ALC_LATIN | ALC_GREEK | ALC_CYRILLIC)
#define ALC_UPPER_ALPHA (ALC_LATIN_UPPERCASE | ALC_GREEK_UPPERCASE | ALC_CYRILLIC_UPPERCASE) // 大写字母
#define ALC_LOWER_ALPHA (ALC_LATIN_LOWERCASE | ALC_GREEK_LOWERCASE | ALC_CYRILLIC_LOWERCASE) // 小写字母

/* ----------------define Gesture ---------------------- */
#if !defined(CODE_BACKSPACE)
#define CODE_BACKSPACE		0x0008	//BackSpace 
#endif
#if !defined(CODE_TAB)
#define CODE_TAB			0x0009	//Tab
#endif
#if !defined(CODE_RETURN)
#define CODE_RETURN			0x000D	//Return 
#endif
#if !defined(CODE_SPACE)
#define CODE_SPACE			0x0020	//Space 
#endif

#define CODE_SHIFT			0x0010	// Shift 内部改变当前字符的大小写状态，外部可用于切换识别范围
#define CODE_CAPSLOCK		0x000A	// Caps Lock 永久改变后续字符的大小写状态

/* ---------------编辑命令编码输出控制--------------------- */
#define COMMAND_UNDO		0x1201	// 撤消 CTRL+Z
#define COMMAND_COPY		0x1202	// 拷贝 CTRL+C
#define COMMAND_PASTE		0x1203	// 粘帖 CTRL+V
#define COMMAND_CUT			0x1204	// 剪切 CTRL+X

//---------------常量定义----------------------------
#define HWMAXCANDNUM		10			// 可提供的最大候选个数

#if !defined(__HWAPI_H_S)
#define HWRERAMSIZE			(14*1024)
#endif

//------------笔迹结构定义-------------------
#define STROKEENDMARK		(-1)		// 定义笔画结束标记值
#if !defined(__HWAPI_H) && !defined(__HWAPI_H_S)
typedef struct tagTHWPoint
{
	short x;//笔迹 X 坐标
	short y;//笔迹 Y 坐标
} THWPoint;
#endif

//------------书写框结构定义-------------------
typedef struct tagE_THWFrame{
	short left;		// X of top left coner of handwriting frame 
	short top;		// Y of top left coner of handwriting frame 
	short width;	// width of handwriting frame 
	short height;	// Height of handwriting frame 
} E_THWFrame;

//------------输入状态定义------------------
#define MODE_SINGLECHAR		1	// 单字识别

//------------识别属性定义------------------
#ifdef HANWANG_INTEGRATED_DICT
	typedef struct tagE_THWAttribute
	{
		unsigned short	wMode;		
		unsigned short	wLanguage;	
		unsigned long	dwRange; 
		int				iCandidateNum;	
		unsigned char*	pRam;	
		E_THWFrame		*pFrame;	
		unsigned short	*pCharSet;	
	} E_THWAttribute;
#else
	typedef struct tagE_THWAttribute
	{
		unsigned short	wMode;		// only MODE_SINGLECHAR is valid   
		unsigned short	wLanguage;	// Language which you want to recognize 
		unsigned long	dwRange; // Range,  ALC_ALPHABET is not approved because of similar 
		int				iCandidateNum;	// the number of candidate to be returned  	
		unsigned char*	pRam;	// address of RAM needed by recognition engine ,Four-byte alignment is required 
		unsigned char*	pRom;	// address of dictionary ,Four-byte alignment is required  
		E_THWFrame		*pFrame;	// handwriting frame ,set to NULL when not use frame
		unsigned short	*pCharSet;	// extended Range for current language 
	} E_THWAttribute;
#endif

//----------------导出函数定义-----------------------
#ifdef __cplusplus
extern "C" {
#endif

/*
功能：笔迹识别
参数说明：
	pTrace：笔迹数据，其格式为(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,(STROKEENDMARK,0),
			(STROKEENDMARK,STROKEENDMARK)，其中(STROKEENDMARK,0)为笔画结束标志，
			(STROKEENDMARK,STROKEENDMARK)为字结束标志。
	pAttr：识别属性。
	pResult：识别结果存放区。大小为 2*HWMAXCANDNUM。每个候选字占2个字节。	
返回值：
	-2：语言未被授权
	-1：参数错误
	 0：拒识
    >0：候选字个数	
*/
int MTL_HWRecognize( const THWPoint* pTrace, const E_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
