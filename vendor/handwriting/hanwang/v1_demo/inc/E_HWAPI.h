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
#ifndef __E_HWAPI_H
#define __E_HWAPI_H

#define HANWANG_INTEGRATED_DICT		0	// Dictionary is integrated or not
#if !defined(HANWANG_LITTLEENDIAN)
#define HANWANG_LITTLEENDIAN		1	// LittleEndian or BigEndian
#endif
#define HANWANG_DEMO
/* -------------------Range---------------------------------- */
#define ALC_LATIN_LOWERCASE				0x00000001	// Lowercase Latin characters ( a-z )
#define ALC_LATIN_UPPERCASE				0x00000002	// Uppercase Latin characters ( A-Z )

#define ALC_GREEK_LOWERCASE				0x00000004	// Lowercase Greek characters 
#define ALC_GREEK_UPPERCASE				0x00000008  // Uppercase Greek characters 

#define ALC_CYRILLIC_LOWERCASE			0x00000010	// Lowercase Cyrillic characters 
#define ALC_CYRILLIC_UPPERCASE			0x00000020	// Uppercase Cyrillic characters 

#define ALC_COMMON_PUNCTUATION			0x00000040	// Punctuation in common use 
#define ALC_EXTEND_PUNCTUATION			0x00000080	// Punctuation extended 

#define ALC_COMMON_SYMBOLS				0x00000100	// Symbol in common use 
#define ALC_EXTEND_SYMBOLS				0x00000200	// Symbol extended 

#define ALC_COMMON_NUMERALS				0x00000400	// number in common use
#define ALC_EXTEND_NUMERALS				0x00000800	// Number extended 

#if !defined(ALC_GESTURE)
#define ALC_GESTURE						0x00001000	// Gesture 
#endif
#define ALC_EDITCOMMAND					0x00002000	// Edit Command 

/* ----------------Transform output -------------------------- */
#define	OUT_INVERT						0x10000000	// Not used 
#if !defined(OUT_UPPERCASE)
#define OUT_UPPERCASE					0x20000000	// output Uppercase character 
#endif
#if !defined(OUT_LOWERCASE)
#define OUT_LOWERCASE					0x40000000	// output Lowercase character 
#endif
#define OUT_FULLWIDTH					0x80000000	// output SBC case 

#define ALC_LATIN		(ALC_LATIN_LOWERCASE | ALC_LATIN_UPPERCASE)			// Latin characters 
#define ALC_GREEK		(ALC_GREEK_LOWERCASE | ALC_GREEK_UPPERCASE)			// Greek characters 
#define ALC_CYRILLIC	(ALC_CYRILLIC_LOWERCASE | ALC_CYRILLIC_UPPERCASE)	// Cyrillic characters

#define ALC_ALPHABET	(ALC_LATIN | ALC_GREEK | ALC_CYRILLIC)
#define ALC_UPPER_ALPHA (ALC_LATIN_UPPERCASE | ALC_GREEK_UPPERCASE | ALC_CYRILLIC_UPPERCASE) // Uppercase character 
#define ALC_LOWER_ALPHA (ALC_LATIN_LOWERCASE | ALC_GREEK_LOWERCASE | ALC_CYRILLIC_LOWERCASE) // Lowercase character 

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

/* ---------------Edit Command --------------------- */
#define COMMAND_UNDO		0x1201	// CTRL+Z  
#define COMMAND_COPY		0x1202	// CTRL+C  
#define COMMAND_PASTE		0x1203	// CTRL+V  
#define COMMAND_CUT			0x1204	// CTRL+X  

//---------------define constant ----------------------------
#define HWMAXCANDNUM		10			// maximal number of candidate 
#define HWRERAMSIZE			(14*1024)	//HWRERAMSIZE bytes RAM needed by recognition engine ,Four-byte alignment is required 

//------------define structure of pen trace -------------------
#define STROKEENDMARK		(-1)		// end mark 
#if !defined(__HWAPI_H)
typedef struct tagTHWPoint
{
	short x;//X
	short y;//Y
} THWPoint; //one point data
#endif
//------------handwriting frame-----------------------------------
typedef struct tagTHWFrame{
	short left;		// X of top left coner of handwriting frame 
	short top;		// Y of top left coner of handwriting frame 
	short width;	// width of handwriting frame 
	short height;	// Height of handwriting frame 
} E_THWFrame;

//------------Input mode ------------------------------------------
#define MODE_SINGLECHAR		1	// recognize single character 

//------------attribute -------------------------------------------
#if HANWANG_INTEGRATED_DICT
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

//----------------Function define -------------------------------
#ifdef __cplusplus
extern "C" {
#endif

/*
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
	=-2:Language is not allowed  
	=-1:wrong parameter 
	= 0:invalid handwriting data
	> 0:the number of candidate
*/
int MTL_HWRecognize( const THWPoint* pTrace, const E_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
