/* ------------------------------------------------------------
  Copyright (C) 汉王科技股份有限公司, 2006
  
  File:       HWAPI.h

  创建者：秦建辉 jhqin@hanwang.com.cn

  日期：2006年8月8日

  关键字：英文＋泰文版 UNICODE编码 代码字典集成
------------------------------------------------------------ */

#ifndef __THAI_HWAPI_H
#define __THAI_HWAPI_H
//#define HANWANG_DICINTEGRATION				//字典集成
#define HANWANG_DEMO  

/* -----------识别范围--------------- */
#define ALC_THAICON			0x00000001     // Thai Consonant 0x0E01 ~ 0x0E2E
#define ALC_THAIVOW			0x00000002     // Thai Vowel     0x0E30 ~ 0x0E3A, 0X0E40 ~0x0E44, 0x0E47
#define ALC_THAISIGN		0x00000004     // Thai Sign      0x0E2F, 0x0E45, 0x0E46, 0x0E5A, 0x0E5B, 0x0E4C ~ 0x0E4F
#define ALC_THAIDIGI		0x00000008     // Thai Digit     0x0E50 ~ 0x0E59
#define ALC_THAITONE		0x00000010     // Thai ToneMark  0x0E48 ~ 0x0E4B 
#define ALC_THAICUR			0x00000020     // Thai Currency  0x0E3F

#if !defined(ALC_UCALPHA)
#define ALC_UCALPHA			0x00000040		//Uppercase Latin characters ( A-Z ) 
#endif
#if !defined(ALC_LCALPHA)
#define ALC_LCALPHA			0x00000080		//Lowercase Latin characters ( a-z ) 	
#endif

#if !defined(ALC_NUMERIC)
#define ALC_NUMERIC			0x00000100		//Number ( 0-9 ) 	
#endif

#define ALC_PUNCTUATION		0x00000200		/* punctuation marks 
                                                !	0021	Exclamation（感叹号）
                                                "	0022	Double Quotation Marks（双引号）
                                                ,	002C	Comma（逗号）
                                                ：	003A	Colon（冒号）
                                                ；	003B	Semicolon（分号）
                                                ?	003F	Question Mark（问号）
                                                '	0027	Single Quotation Marks（单引号）
                                                (	0028	Left Bracket（左圆括号）
                                                )	0029	Right Bracket（右圆括号）
                                                */
#define ALC_SYMBOL          0x00000400      /* Symbols
                                                #	0023	Number（井号）
                                                $	0024	Dollar（美元符号）
                                                %	0025	Percent Sign （百分比符号）
                                                &	0026	Ampersand（与符号）
                                                *	002A	Asterisk （星号）
                                                +	002B	Plus Sign（加号）
                                                -	002D	Subtraction Sign（减号）
                                                .	002E	Dot（点）
                                                /	002F	Virgule（斜线号）
                                                <	003C	Is less than Sign（小于号）
                                                =	003D	Is less than（等于号）
                                                >	003E	Is more than（大于号）
                                                @	0040	AT（单价号）
                                                ［	005B	Left square brackets（左方括号）
                                                ］	005D	Right square brackets（右方括号）
                                                \	005C	Backlash（反斜线）
                                                _	005F	Underline（下划线）
                                                `	0060	Apostrophe（所有格符号）
                                                ｛	007B	（左大括号）
                                                ｝	007D	（右大括号）
                                                |	007C	
                                                ~	007E	Swung dash（代字号）
                                                */
#if !defined(ALC_GESTURE)                                                
#define	ALC_GESTURE			0x00000800		/* Control gesture
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Toggle 0x0010	*/
#endif

//-----------------输出自动转换-------------------------------------
#if !defined(OUT_LOWERCASE)
#define OUT_LOWERCASE		0x20000000	//output Lowercase character 
#endif
#if !defined(OUT_UPPERCASE)
#define OUT_UPPERCASE		0x40000000	//output Uppercase character 
#endif
#if !defined(OUT_FULLWIDTH)
#define OUT_FULLWIDTH		0x80000000	//output SBC case 
#endif
#if !defined(OUT_ASSISTANT)
#define OUT_ASSISTANT		(OUT_LOWERCASE | OUT_UPPERCASE | OUT_FULLWIDTH)
#endif

//-----------------常用组合-----------------------------------------
#if !defined(CHARSET_ENGLISH)
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)			//Latin characters 
#endif
#define CHARSET_THAILAND		(ALC_THAICON | ALC_THAIVOW | ALC_THAISIGN | ALC_THAIDIGI | ALC_THAITONE | ALC_THAICUR) //Thai characters 

/* ----------------定义手势编码值------------------------------- */
#if !defined(CODE_BACKSPACE)
#define CODE_BACKSPACE			0x0008	//Backspace 
#endif
#if !defined(CODE_TOGGLE)
#define CODE_TOGGLE				0x0010	//Toggle 
#endif
#if !defined(CODE_RETURN)
#define CODE_RETURN				0x000D	//Return 
#endif
#if !defined(CODE_SPACE)
#define CODE_SPACE				0x0020	//Space 
#endif

//---------------常量定义----------------------------
#if !defined(MAXCANDNUM)
#define MAXCANDNUM				10			// maximal number of candidates 
#endif
#if !defined(HWRERAMSIZE)
#define HWRERAMSIZE				(14*1024)	// RAM needed by recognition engine for running 
#endif

//------------笔迹结构定义-------------------
#define STROKEENDMARK			(-1)		// 定义笔画结束标记值
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//------------识别属性定义------------------
typedef struct Thai_tagTHWAttribute
{
	unsigned long	dwRange;	// Range of Recognize 
	int	iCandidateNum;	// number of candidates to be returned 
	int	iBoxWidth;		// Width of handwriting frame,set a value less than or equal to Zero if not use.
	int	iBoxHeight;		// Height of handwriting frame,set a value less than or equal to Zero if not use.
	unsigned char*	pRam;		// RAM needed by recognition engine for running. It may be HWRERAMSIZE Bytes ,and align by 4 bytes .
	unsigned char*  pRom;		//address of dictionary, align by 4 bytes.
} Thai_THWAttribute;

#ifdef __cplusplus
extern "C" {
#endif

/*
功能：笔迹识别
参数说明：
	pTrace：笔迹数据，其格式为(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,
	        (STROKEENDMARK,0),(STROKEENDMARK,STROKEENDMARK)，
			其中(STROKEENDMARK,0)为笔画结束标志，
			(STROKEENDMARK,STROKEENDMARK)为字结束标志。
	pAttr：识别属性。
	pResult：识别结果。其缓冲区大小为 HWRESULTBUFSIZE。	
返回值：
	=-1:错误的运算空间
	= 0:拒识
	> 0:候选字个数
*/
int THAI_HWRecognize( const THWPoint* pTrace, const Thai_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
