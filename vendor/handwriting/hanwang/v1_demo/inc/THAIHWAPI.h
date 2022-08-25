/* ------------------------------------------------------------
  Copyright (C) 汉王科技股份有限公司, 2006
  
  File:       HWAPI.h

  创建者：秦建辉 jhqin@hanwang.com.cn

  日期：2006年8月8日

  关键字：英文＋泰文版 UNICODE编码 代码字典集成
------------------------------------------------------------ */

#ifndef __HWAPI_THAI_H
#define __HWAPI_THAI_H
//#define HANWANG_DICINTEGRATION				//Dictionary integration  
/* ----------------Range of Recognition --------------- */
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
                                                !	0021	Exclamation
                                                "	0022	Double Quotation Marks
                                                ,	002C	Comma
                                                ：	003A	Colon
                                                ；	003B	Semicolon
                                                ?	003F	Question Mark
                                                '	0027	Single Quotation Marks
                                                (	0028	Left Bracket
                                                )	0029	Right Bracket
                                                */
#define ALC_SYMBOL          0x00000400      /* Symbols
                                                #	0023	Number
                                                $	0024	Dollar
                                                %	0025	Percent Sign 
                                                &	0026	Ampersand
                                                *	002A	Asterisk 
                                                +	002B	Plus Sign
                                                -	002D	Subtraction Sign
                                                .	002E	Dot
                                                /	002F	Virgule
                                                <	003C	Is less than Sign
                                                =	003D	Is less than
                                                >	003E	Is more than
                                                @	0040	AT
                                                ?	005B	Left square brackets
                                                ?	005D	Right square brackets
                                                \	005C	Backlash
                                                _	005F	Underline
                                                `	0060	Apostrophe
                                                ?	007B	
                                                ?	007D	
                                                |	007C	
                                                ~	007E	Swung dash
                                                */
#if !defined(ALC_GESTURE)                                                
#define	ALC_GESTURE			0x00000800		/* Control gesture
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Toggle 0x0010	*/
#endif

//-----------------Transform output -------------------------------------
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

//-----------------Combination in common use -----------------------------------------
#if !defined(CHARSET_ENGLISH)
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)			//Latin characters 
#endif
#define CHARSET_THAILAND		(ALC_THAICON | ALC_THAIVOW | ALC_THAISIGN | ALC_THAIDIGI | ALC_THAITONE | ALC_THAICUR) //Thai characters 

/* ----------------define Gesture ------------------------------- */
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

//---------------define constant ---------------------------------------
#if !defined(MAXCANDNUM)
#define MAXCANDNUM				10			// maximal number of candidates 
#endif
#if !defined(HWRERAMSIZE)
#define HWRERAMSIZE				(14*1024)	// RAM needed by recognition engine for running 
#endif

//---------------define structure of pen trace -------------------
#define STROKEENDMARK			(-1)		// end mark of stroke 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//------------ attribute ------------------
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
function：recognize
parameter：
	pTrace：handwriting data.
			the data format is (x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,(STROKEENDMARK,0),(STROKEENDMARK,STROKEENDMARK).
			(STROKEENDMARK,0) is end mark of stroke，
			(STROKEENDMARK,STROKEENDMARK) is end mark of handwriting。
	pAttr：attribute。
	pResult：buffer of candidates returned.	
return：
	=-1:wrong parameter 
	= 0:invalid handwriting data
	> 0:number of candidates
*/
int THAI_HWRecognize( const THWPoint* pTrace, const Thai_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
