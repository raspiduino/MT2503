
#if !defined(MMI_FONT_DATA_STRUCT_H)
#define MMI_FONT_DATA_STRUCT_H

#include "StdAfx.h"
#include <string>
#include <vector>
using namespace std;

#include "bmp_font_encode.h"

#if 0 
/* under construction !*/
/* under construction !*/
#endif


#define __T(x)      x
#define _T(x)       __T(x)

typedef unsigned char U8;
typedef char          S8;
typedef short S16;
typedef unsigned short U16 ;
typedef unsigned int U32;
typedef int S32;

typedef unsigned long       ULONG;
typedef unsigned __int64    U64;


#define MCT_LANGUAGE_NAME 			100
#define MCT_FONT_DATA_NAME 			100

#define MCT_FONT_RANGE_INFO_NAME 	100
#define MCT_FONT_RANGE_DATA_NAME 	100

#define MCT_FONT_GROUP_INFO_NAME 	100
#define MCT_FONT_GROUP_DATA_NAME 	100

#define	MCT_SSC_SIZE        10
#define	MCT_LCC_SIZE		50


#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#define	MCT_MAX_FONT_TYPES	            9

/* MCT_LANG_TYPE_ALPHA  */
typedef enum {
    MCT_ALPHA_SMALL_FONT = 0,
    MCT_ALPHA_MEDIUM_FONT,
    MCT_ALPHA_LARGE_FONT,
    MCT_ALPHA_SUBLCD_FONT,
    MCT_ALPHA_DIALER_FONT,
    MCT_ALPHA_NUMBER1_FONT,
    MCT_ALPHA_NUMBER2_FONT,
    MCT_ALPHA_TOUCH_SCREEN_FONT,
    MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT
}ALPHA_FONT_TYPE;

#else
#define	MCT_MAX_FONT_TYPES	            6

/* MCT_LANG_TYPE_ALPHA  */
typedef enum {
    MCT_ALPHA_SMALL_FONT = 0,
    MCT_ALPHA_MEDIUM_FONT,
    MCT_ALPHA_LARGE_FONT,
    MCT_ALPHA_SUBLCD_FONT,
    MCT_ALPHA_DIALER_FONT,
    MCT_ALPHA_TOUCH_SCREEN_FONT,
    MCT_ALPHA_NUMBER1_FONT,
    MCT_ALPHA_NUMBER2_FONT,
    MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT
}ALPHA_FONT_TYPE;

#endif

#define	MCT_SMALL_FONT				(1 << MCT_ALPHA_SMALL_FONT)
#define	MCT_MEDIUM_FONT				(1 << MCT_ALPHA_MEDIUM_FONT)
#define	MCT_LARGE_FONT				(1 << MCT_ALPHA_LARGE_FONT)
#define	MCT_SUBLCD_FONT				(1 << MCT_ALPHA_SUBLCD_FONT)
#define	MCT_DIALER_FONT				(1 << MCT_ALPHA_DIALER_FONT)
#define MCT_VIRTUAL_KEYBOARD_FONT	(1 << MCT_ALPHA_TOUCH_SCREEN_FONT)	
#define MCT_NUMBER1_FONT			(1 << MCT_ALPHA_NUMBER1_FONT)	
#define MCT_NUMBER2_FONT			(1 << MCT_ALPHA_NUMBER2_FONT)	
#define MCT_TOUCH_SCREEN_LARGE		(1 << MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT)	


/* File name */
#define FONT_RES_FILENAME			_T("FontRes.c")
#define FONT_DATA_FILENAME          _T("FontData.c")
#define FONT_COMPRESSION_INFO_NAME  _T("temp_CompressInfo.h")
#define FONT_LANGUAGE_TABLE_FILENAME ("FontConstTable.txt")


#define MAX_NUM_CHARS   40005

#define FONT_LINE_CHAR   400

#define FONT_ENGINE_DATA_BLOCK_SIZE     (256)



typedef struct MCTRange
{
	U32	nMin;
	U32	nMax;
}sMCTRangeData;


typedef struct MCTGroup
{
	U32	nOffset;
	U32	nSize;
}sMCTGroupData;


typedef struct MCTRangeInfo
{
	U8	 rangeInfoName[MCT_FONT_RANGE_INFO_NAME];
	U8	 rangeDataName[MCT_FONT_RANGE_DATA_NAME];
	U8	 rangeOffsetName[MCT_FONT_RANGE_DATA_NAME];
	///new added
	U8   fontRangeOffsetStructName[MCT_FONT_RANGE_DATA_NAME];
	U8   fontRangeBlockIndexArrayName[MCT_FONT_RANGE_DATA_NAME];    /* Name of block array */
        ///new added
        U8   groupInfoName[MCT_FONT_GROUP_INFO_NAME];
        U8   groupDataName[MCT_FONT_GROUP_DATA_NAME];
	///
	U32 nNoOfRanges;	            /* Number of range */
	sMCTRangeData*	pRangeData;
	
        U32 nNoOfGroup;	            /* Number of range */
	sMCTGroupData*	pGroupData;
	
}sMCTRangeDetails;


typedef struct MCTFontInfo
{
	U32*		pWidthArray;
	U32*        pDWidthArray;
	U32*		pIndexArray;        /* Data Offset */
	U8*		    pFontData;
	U32         nFontDataCompressionSize;
	U8*		    pFontDataCompression; 
	U32*        pBlockIndexArrayCompression;  //200 is enough /* block array notes the character index end the array */
	U32         nBlockIndexArrayCompressionSize;  /* block count from 0. */
	///
	U32*		pUnicodeData;
	U32*		pBBX1;
	U32*		pBBX2;
	U32*		pBBX3;
	U32*		pBBX4;
	U16		    nWidth;         /* Font finally correct width. */
	U16		    nHeight;
	U32		    nTotalChars;    /* Font total glyph count. */
	U32		    nSize;          /* Total byte of raw data(not concisely.) */
	//U8		    nEquiDistant;

    U32*        range ;         /* Range Offset table */
    sMCTRangeDetails*  rangeDetails;

    
}MCTFontInfo;


typedef struct _MCTCustFontData
{
	U8			name[MCT_FONT_DATA_NAME];
	string		strFilePath;
	string		strfilename;
    
	U16		    nHeight;
	U16		    nWidth;

	//Ascent and desecent for baseline
	U16		    nAscent;
	U16		    nDescent;

	U16		    nBoxMaxWidth;
	bool		nEquiDistant;   /* font is fixed or variable */       
	U8			nCharBytes;     /* For fixed width, this is char count of each character. */
	U16			nMaxChars;
	U8			fontWidthName[MCT_FONT_RANGE_DATA_NAME];
	U8			fontDWidthName[MCT_FONT_RANGE_DATA_NAME];
	U8			fontOffsetName[MCT_FONT_RANGE_DATA_NAME];

	U8			fontDataName[MCT_FONT_RANGE_DATA_NAME];

	U8          fontCompressedDataName[MCT_FONT_RANGE_DATA_NAME];
	U32*		pWidthArray;
	U32*		pDWidthArray;
	U32*		pOffsetArray;                       /* Data offset array table */

	U32*        pOffsetArrayCompression; 

	U8*			pDataArrayCompression;


	U8*			pDataArray;                         /* Data array */
	U32*		pRange;                             /* Range Offset table */
	U32			nDataArraySize ;                    /* Data array size */


	U32         nDataArrayCompressionSize;
	U32*        pBlockIndexArrayCompression;        /* Block array */
	U32         nBlockIndexArrayCompressionSize;    /* Number of block, from 0 */


	U32			m_nTotalChars ;                     /* equal to nTotalChars, Font total glyph count. */
	sMCTRangeDetails*	pRangeDetails;
	U32*		pUnicodeData;
	U32*		pBBX1;
	U32*		pBBX2;
	U32*		pBBX3;
	U32*		pBBX4;

    U8          font_size;
    S32         Language_flags;
    string      gen_hfile_name;
    U8          is_dwidth;

    U8          *pHWCompressionData;            /*  HW compress data table */
    U32         nHWCompressionDataSize;         /*  HW compress data byte size */

    U32          *pHWCompressionDataOffset;

    S32         nSize;
    
}sMCTCustFontData;


typedef struct _MCTLanguageDetails
{
	U8			name[MCT_LANGUAGE_NAME];
	U8		    aLangSSC[MCT_SSC_SIZE];
	U8			nLangCountryCode[MCT_LCC_SIZE];
}sMCTLanguageDetails;

typedef struct _MCTLanguageList{
	sMCTLanguageDetails language;
	_MCTLanguageList *previous;
	_MCTLanguageList *next;
} sMCTLanguageList;


typedef struct
{
    string font_data_name;
    string strFilePath;
    string strfilename;
    string gen_hfile_name;
    U8 font_size;    
}FontData_Info;


typedef struct
{
    U16 nTotalFonts;
    vector<FontData_Info> fontData_contain;
}font_group_struct;

bool IsUseFontCompression(void);
bool IsUseHWFontCompression(void);
bool IsUseFontGroupCompression(void);


#define MAX_LANGUAGES 30


const sMCTLanguageDetails mtk_gLanguageArray[MAX_LANGUAGES] =
{
#if defined(__MMI_LANG_ENGLISH__)
{
 {(char)0x45,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
  "*#0044#",//SSC string name
 "en-US"
},
#endif

#if defined(__MMI_LANG_FRENCH__)
{
{(char)0x46,(char)0x0,(char)0x72,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0xe7,(char)0x0,(char)0x61,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x00},//Language Name
"*#0033#",
 "fr-FR"
},
#endif

#if defined(__MMI_LANG_SPANISH__)
{
{(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x70,(char)0x0,(char)0x61,(char)0x0,(char)0xf1,(char)0x0,(char)0x6f,(char)0x0,(char)0x6c,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0034#",
 "es-ES"
},
#endif

#if defined(__MMI_LANG_DANISH__)
{
{(char)0x44,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0},//Language Name
"*#0045#",
 "da-DK"
},
#endif

#if defined(__MMI_LANG_POLISH__)
{
{(char)0x6A,(char)0x00 , (char)0x19,(char)0x01,  (char)0x7A,(char)0x00,  (char)0x79,(char)0x00,  (char)0x6B,(char)0x00 , (char)0x00,(char)0x20, (char)0x70,(char)0x00 , (char)0x6F,(char)0x00,  (char)0x6C,(char)0x00,  (char)0x73,(char)0x00, (char)0x6B,(char)0x00,  (char)0x69,(char)0x00 ,(char)0x00,(char)0x00},//Language Name
"*#0048#",
 "pl-PL"
},
#endif

#if defined(__MMI_LANG_PORTUGUESE__)
{
 {(char)0x50, (char)0x0, (char)0x6f, (char)0x0, (char)0x72, (char)0x0, (char)0x74, (char)0x0, (char)0x75, (char)0x0, (char)0x67, (char)0x0, (char)0x75, (char)0x0, (char)0xea, (char)0x0, (char)0x73, (char)0x0, (char)0x00, (char)0x0},//Language Name
  "*#0351#",//SSC string name
 "pt-PT"
},
#endif

#if defined(__MMI_LANG_ALBANIAN__)
{
{(char)0x41,(char)0x0,(char)0x6c,(char)0x0,(char)0x62,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0},//Language Name
  "*#0355#",//SSC string name
 "sq-SQ"
},
#endif

//English
#if defined(__MMI_LANG_UK_ENGLISH__)
{
 {(char)0x55,(char)0x0,(char)0x4B,(char)0x0,(char)0x20,(char)0x0,(char)0x45,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
  "*#0441#",//SSC string name
 "en-UK"
},
#endif

#if defined(__MMI_LANG_CA_FRENCH__)
{
{(char)0x43,(char)0x0,(char)0x41,(char)0x0,(char)0x20,(char)0x0,(char)0x46,(char)0x0,(char)0x72,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0xe7,(char)0x0,(char)0x61,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x00},//Language Name
"*#0001#",
 "fr-CA"
},
#endif

#if defined(__MMI_LANG_SA_SPANISH__)
{
{(char)0x4C,(char)0x0,(char)0x41,(char)0x0,(char)0x20,(char)0x0,(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x70,(char)0x0,(char)0x61,(char)0x0,(char)0xf1,(char)0x0,(char)0x6f,(char)0x0,(char)0x6c,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0054#",
 "es-SA"
},
#endif

#if defined(__MMI_LANG_SA_PORTUGUESE__)
{
 {(char)0x42,(char)0x0,(char)0x5A,(char)0x0,(char)0x20,(char)0x0,(char)0x50, (char)0x0, (char)0x6f, (char)0x0, (char)0x72, (char)0x0, (char)0x74, (char)0x0, (char)0x75, (char)0x0, (char)0x67, (char)0x0, (char)0x75, (char)0x0, (char)0xea, (char)0x0, (char)0x73, (char)0x0, (char)0x00, (char)0x0},//Language Name
  "*#0055#",//SSC string name
 "pt-BZ"
},
#endif

#if defined(__MMI_LANG_ICELANDIC__)
{
{(char)0xCD,(char)0x0,(char)0x73,(char)0x0,(char)0x6C,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0354#",
 "is-IS"
},
#endif

#if defined(__MMI_LANG_SERBIAN__)
{
{(char)0x41,(char)0x04,(char)0x40,(char)0x04,(char)0x3F,(char)0x04,(char)0x41,(char)0x04,(char)0x3A,(char)0x04,(char)0x38,(char)0x04,(char)0x00,(char)0x00},//Language Name
"*#0381#",
 "sr-SR"
},
#endif

#if defined (__MMI_LANG_KOREAN__)
{
{ (char)0x5C, (char)0xD5, (char)0x6D, (char)0xAD, (char)0xB4, (char)0xC5, (char)0x00, (char)0x00 },
"*#0082#",
"ko" 
},  
#endif

#if defined(__MMI_LANG_AZERBAIJANI__)
{
{(char)0x41, (char)0x00, (char)0x7A, (char)0x00, (char)0x59, (char)0x02, (char)0x72,  (char)0x00, (char)0x62, (char)0x00, (char)0x61,  (char)0x00,  (char)0x79, (char)0x00,  (char)0x63, (char)0x00,  (char)0x61, (char)0x00,  (char)0x6E, (char)0x00,  (char)0x64, (char)0x00,  (char)0x69, (char)0x00,  (char)0x6C, (char)0x00,  (char)0x69, (char)0x00, (char)0x00,(char)0x00},//Language Name
"*#0994#",
 "az-AZ"
},
#endif

#if defined(__MMI_LANG_CATALAN__)
{
{(char)0x63 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x74 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x6C ,(char)0x0  ,(char)0xE0,(char)0x0,(char)0x00,(char)0x00 },//Language Name
"*#0376#",
 "ca-CA"
},
#endif

#if defined(__MMI_LANG_HAUSA__)
{
{(char)0x48 ,(char)0x0  ,(char)0x61 ,(char)0x0  ,(char)0x75 ,(char)0x0  ,(char)0x73 ,(char)0x0  ,(char)0x61 ,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#2342#",
 "ha-HA"
},
#endif


#if defined(__MMI_LANG_KAZAKH__)
{
{(char)0x9A ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x37 ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x9B ,(char)0x04 ,(char)0x20 ,(char)0x0,(char)0x42 ,(char)0x04 ,(char)0x56 ,(char)0x04 ,(char)0x3B ,(char)0x04 ,(char)0x56 ,(char)0x04,(char)0x00,(char)0x00},//Language Name
"*#0007#",

 "kk-KK"
},
#endif

#if defined(__MMI_LANG_GALICIAN__)
{
{(char)0x47,(char)0x00,(char)0x61,(char)0x00,(char)0x6C,(char)0x00,(char)0x65,(char)0x00,(char)0x67,(char)0x00,(char)0x6F,(char)0x00,(char)0x00,(char)0x00},//Language Name
"*#3498#",

  "gl-ES",
 },
#endif

#if defined(__MMI_LANG_BASQUE__)
{
{(char)0x45,(char)0x00,(char)0x75,(char)0x00,(char)0x73,(char)0x00,(char)0x6B,(char)0x00,(char)0x61,(char)0x00,(char)0x72,(char)0x00,(char)0x61,(char)0x00,(char)0x00,(char)0x00},//Language Name
"*#3495#",

    "eu-ES",
},
#endif

#if defined(__MMI_LANG_IGBO__)
{
{(char)0x41,(char)0x00,(char)0x73,(char)0x00,(char)0x1EE5,(char)0x00,(char)0x73,(char)0x00,(char)0x1EE5,(char)0x00,(char)0x20,(char)0x00,(char)0x49,(char)0x00,(char)0x67,(char)0x00,(char)0x62,(char)0x00,(char)0x6F,(char)0x00,(char)0x00,(char)0x00},//Language Name
 "*#2343#",

   "ig-NG",
},
#endif

#if defined(__MMI_LANG_FILIPINO__)
{
{(char)0x46,(char)0x00,(char)0x69,(char)0x00,(char)0x6C,(char)0x00,(char)0x69,(char)0x00,(char)0x70,(char)0x00,(char)0x69,(char)0x00,(char)0x6E,(char)0x00,(char)0x6F ,(char)0x00,(char)0x00},//Language Name
"*#0063#",
"fil-PH",
},
#endif

#if defined(__MMI_LANG_IRISH__)
{
{(char)0x47,(char)0x00,(char)0x61,(char)0x00,(char)0x65,(char)0x00,(char)0x69,(char)0x00,(char)0x6C,(char)0x00,(char)0x67 ,(char)0x00,(char)0x65,(char)0x00,(char)0x00},//Language Name
"*#0353#",
"ga-IE",
},
#endif



#if defined(__MMI_LANG_MACEDONIAN__)
{
{(char)0x1C ,(char)0x04 ,(char)0x30 ,(char)0x04 ,(char)0x3A ,(char)0x04 ,(char)0x35 ,(char)0x04 ,(char)0x34 ,(char)0x04 ,(char)0x3E ,(char)0x04 ,(char)0x3D ,(char)0x04 ,(char)0x41 ,(char)0x04 ,(char)0x3A ,(char)0x04 ,(char)0x38 ,(char)0x04

,(char)0x00,(char)0x00},//Language Name
"*#0389#",

 "mk-MK"
},
#endif

#if defined(__MMI_LANG_SESOTHO__)
{
{(char)0x73, (char)0x00,  (char)0x65, (char)0x00,  (char)0x53, (char)0x00, (char)0x6F, (char)0x00, (char)0x74, (char)0x00, (char)0x68, (char)0x00,  (char)0x6F, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#0266#",

 "st-ST"
},
#endif


#if defined(__MMI_LANG_TAGALOG__)
{
{(char)0x54, (char)0x00,   (char)0x61, (char)0x00,   (char)0x67, (char)0x00,   (char)0x61, (char)0x00,   (char)0x6C, (char)0x00,   (char)0x6F, (char)0x00,   (char)0x67, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#0631#",

 "tl-TL"
},
#endif

#if defined(__MMI_LANG_YORUBA__)
{
{(char)0xE8, (char)0x00,  (char)0x64, (char)0x00,  (char)0xE8, (char)0x00,  (char)0x59, (char)0x00,  (char)0x6F, (char)0x00,  (char)0x72,  (char)0x00,  (char)0xF9, (char)0x00,  (char)0x62,  (char)0x00,  (char)0xE1, (char)0x00,(char)0x00,(char)0x00},//Language Name
"*#2341#",

 "yo-YO"
},
#endif


#if defined(__MMI_LANG_ITALIAN__)
{
{(char)0x49,(char)0x0,(char)0x74,(char)0x0,(char)0x61,(char)0x0,(char)0x6c,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x6f,(char)0x00},//Language Name
"*#0039#",

 "it-IT"
},
#endif

#if defined(__MMI_LANG_GERMAN__)
{
{(char)0x44,(char)0x0,(char)0x65,(char)0x0,(char)0x75,(char)0x0,(char)0x74,(char)0x0,(char)0x73,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x0,(char)0x00,(char)0x00},//Language Name
"*#0049#",

 "de-DE"
},
#endif

#if defined(__MMI_LANG_MALAY__)
{
{(char)0x42,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0,(char)0x20,(char)0x0,(char)0x4d,(char)0x00,(char)0x65,(char)0x00,(char)0x6c,(char)0x00,(char)0x61,(char)0x00,(char)0x79,(char)0x00,(char)0x75,(char)0x00},//Language Name
"*#0060#",

 "ms-MY"
},
#endif

#if defined(__MMI_LANG_INDONESIAN__)
{
{(char)0x42,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x61,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0,(char)0x20,(char)0x0,(char)0x49,(char)0x00,(char)0x6e,(char)0x00,(char)0x64,(char)0x00,(char)0x6f,(char)0x00,(char)0x6e,(char)0x00,(char)0x65,(char)0x00,(char)0x73,(char)0x00,(char)0x69,(char)0x00,(char)0x61,(char)0x00},//Language Name
"*#0062#",

 "id-ID"
},
#endif

#if defined(__MMI_LANG_CZECH__)
{
{(char)0x43,(char)0x0,(char)0x7A,(char)0x0,(char)0x65,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x0},//Language Name
"*#0420#",

 "cs-CZ"
},
#endif

#if defined(__MMI_LANG_NORWEGIAN__)
{
{(char)0x4E,(char)0x0,(char)0x6F,(char)0x0,(char)0x72,(char)0x0,(char)0x77,(char)0x0,(char)0x65,(char)0x0,(char)0x67,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x00},//Language Name
"*#0047#",

 "nb-NO"
},
#endif
//Norwegian end

#if defined(__MMI_LANG_SLOVAK__)
{
{(char)0x53,(char)0x0,(char)0x6C,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x61,(char)0x0,(char)0x6B,(char)0x00},//Language Name
"*#0421#",

 "sk-SK"
},
#endif

#if defined(__MMI_LANG_DUTCH__)
{
{(char)0x44,(char)0x0,(char)0x75,(char)0x0,(char)0x74,(char)0x0,(char)0x63,(char)0x0,(char)0x68,(char)0x00},
"*#0031#",

 "nl-NL"
},
#endif
#if defined(__MMI_LANG_FINNISH__)
{
{(char)0x46,(char)0x0,(char)0x69,(char)0x0,(char)0x6E,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x00},//Language Name
"*#0358#",

 "fi-FI"
},
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
{
{(char)0x48,(char)0x0,(char)0x75,(char)0x0,(char)0x6E,(char)0x0,(char)0x67,(char)0x0,(char)0x61,(char)0x0,(char)0x72,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
"*#0036#",

 "hu-HU"
},
#endif

#if defined(__MMI_LANG_VIETNAMESE__)
{
{(char)0x54,(char)0x0,(char)0x69,(char)0x0,(char)0xbf,(char)0x1e,(char)0x6e,(char)0x0,(char)0x67,(char)0x0,(char)0x20,(char)0x0,(char)0x56,(char)0x0,(char)0x69,(char)0x00,(char)0xc7,(char)0x1e,(char)0x74,(char)0x00},//Language Name
"*#0084#",

 "vi-VN"
},
#endif

#if defined(__MMI_LANG_TURKISH__)
{
{(char)0x54, (char)0x0, (char)0xfc, (char)0x0, (char)0x72, (char)0x0, (char)0x6b, (char)0x0, (char)0xe7, (char)0x0, (char)0x65, (char)0x0, (char)0x00, (char)0x0},//Language Name
"*#0090#",

 "tr-TR"
},
#endif

#if defined(__MMI_LANG_RUSSIAN__)
{
{(char)0x20,(char)0x04,(char)0x43,(char)0x04,(char)0x41,(char)0x04,(char)0x41,(char)0x04,(char)0x3a,(char)0x04,(char)0x38,(char)0x04,(char)0x39,(char)0x04,(char)0x20,(char)0x00,(char)0x4f,(char)0x04,(char)0x37,(char)0x04,(char)0x4b,(char)0x04,(char)0x3a,(char)0x04},//Language Name
"*#0007#",

 "ru-RU"
},
#endif

#if defined(__MMI_LANG_BULGARIAN__)
{
{(char)0x11,(char)0x04,(char)0x4A,(char)0x04,(char)0x3B,(char)0x04,(char)0x33,(char)0x04,(char)0x30,(char)0x04,(char)0x40,(char)0x04,(char)0x38,(char)0x04,(char)0x4F,(char)0x04},//Language Name
"*#0359#",

 "bg-BG"
},
#endif

#if defined(__MMI_LANG_UKRAINIAN__)
{
{(char)0x43,(char)0x04,  (char)0x3A,(char)0x04,  (char)0x40,(char)0x04,  (char)0x30,(char)0x04,  (char)0x57,(char)0x04,  (char)0x01,(char)0x03 , (char)0x3D,(char)0x04,  (char)0x41,(char)0x04,  (char)0x4C,(char)0x04,  (char)0x3A,(char)0x04,  (char)0x30,(char)0x04 , (char)0x00,(char)0x20, (char)0x3C,(char)0x04,  (char)0x3E,(char)0x04,  (char)0x01,(char)0x03,  (char)0x32,(char)0x04,  (char)0x30,(char)0x04 ,(char)0x00,(char)0x00},//Language Name
"*#0380#",

 "uk-UA"
},
#endif

//Arabic language
#if defined(__MMI_LANG_ARABIC__)
{
{(char)0x27,(char)0x06,(char)0xDF,(char)0xFE,(char)0xCC,(char)0xFE,(char)0xAD,(char)0xFE,(char)0x91,(char)0xFE,(char)0xF4,(char)0xFE,(char)0x94,(char)0xFE,(char)0x00,(char)0x00},
"*#0966#",

"ar-SA"
},
#endif

#if defined(__MMI_LANG_PERSIAN__)
{
{(char)0x50, (char)0x0, (char)0x65, (char)0x0, (char)0x72, (char)0x0,(char)0x73,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},
"*#0098#",

"ps-IR"
},
#endif
#if defined(__MMI_LANG_URDU__)
{
{(char)0x55, (char)0x0, (char)0x72, (char)0x0, (char)0x64, (char)0x0,(char)0x75,(char)0x0},
"*#0092#",

"ur-PK"
},
#endif
#if defined(__MMI_LANG_HEBREW__)
{
{ (char)0x48, (char)0x0, (char)0x65, (char)0x0, (char)0x62, (char)0x0, (char)0x72, (char)0x0, (char)0x65, (char)0x0, (char)0x77, (char)0x0},
"*#0972#",

"he-IL"
}, 
#endif

//Thai language
#if defined(__MMI_LANG_THAI__)
{
{(char)0x44,(char)0x0E,(char)0x17,(char)0x0E,(char)0x22,(char)0x0E,(char)0x00,(char)0x00},
"*#0066#",

"th-TH"
},
#endif

//Greek
#if defined(__MMI_LANG_GREEK__)
{
{ (char)0x47, (char)0x0, (char)0x72, (char)0x0, (char)0x65, (char)0x0, (char)0x65, (char)0x0, (char)0x6b, (char)0x0,},//Language Name
"*#0030#",

 "el-GR"
},
#endif

//Traditional Chinese
#if defined(__MMI_LANG_TR_CHINESE__)
{
{(char)0x41,(char)0x7E,(char)0xD4,(char)0x9A,(char)0x2D,(char)0x4E,(char)0x87,(char)0x65,(char)0x00,(char)0x00},//Language Name
 "*#0886#",//SSC string name

 "zh-TW"
},
#endif

#if defined(__MMI_LANG_HK_CHINESE__)
{{ (char)0xE3, (char)0x5E, (char)0x71, (char)0x67, (char)0x71, (char)0x8A, (char)0x00, (char)0x0,},
"*#0852#",

"zh-HK"
},  
#endif /* defined(__MMI_LANG_HK_CHINESE__) */

//Simplified Chinese
#if defined(__MMI_LANG_SM_CHINESE__)
{
{(char)0x80,(char)0x7B,(char)0x53,(char)0x4F,(char)0x2D,(char)0x4E,(char)0x87,(char)0x65,(char)0x00,(char)0x00},//Language Name
 "*#0086#",//SSC string name
 
 "zh-CN"
},
#endif

#if defined(__MMI_LANG_SWEDISH__)
{
{(char)0x53,(char)0x0,(char)0x77,(char)0x0,(char)0x65,(char)0x0,(char)0x64,(char)0x0,(char)0x69,(char)0x0,(char)0x73,(char)0x0,(char)0x68,(char)0x00},//Language Name
"*#0046#",

 "sv-SE"
},
#endif

#if defined(__MMI_LANG_CROATIAN__)
{
{(char)0x43,(char)0x0,(char)0x72,(char)0x0,(char)0x6F,(char)0x0,(char)0x61,(char)0x0,(char)0x74,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x00},//Language Name
"*#0385#",

 "hr-HR"
},
#endif

#if defined(__MMI_LANG_ROMANIAN__)
{
{(char)0x52,(char)0x0,(char)0x6f,(char)0x0,(char)0x6d,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6e,(char)0x00},//Language Name
"*#0040#",

 "ro-RO"
},
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
{
{(char)0x53,(char)0x0,(char)0x6C,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x00,(char)0x69,(char)0x00,(char)0x61,(char)0x00,(char)0x6E,(char)0x00},//Language Name
"*#0386#",

 "sl-SI"
},
#endif

#if defined(__MMI_LANG_HINDI__)
{
{(char)0x39, (char)0x09, (char)0x3F, (char)0x09, (char)0x28, (char)0x09, (char)0x4D, (char)0x09, (char)0x26, (char)0x09, (char)0x40, (char)0x09},
 "*#0091#",

 "hi-IN"
},
#endif


#if defined(__MMI_LANG_MARATHI__)  
{
{(char)0x2E, (char)0x09, (char)0x30, (char)0x09, (char)0x3E, (char)0x09, (char)0x20, (char)0x09, (char)0x40, (char)0x09},
 "*#9122#",

 "mr-IN"
},
#endif
#if defined(__MMI_LANG_TAMIL__)
{
{ (char)0xA4, (char)0x0B, (char)0xAE, (char)0x0B, (char)0xBF, (char)0x0B, (char)0xB4, (char)0x0B, (char)0xCD, (char)0x0B,},
"*#9144#",

"ta-IN"
},
#endif

#if defined(__MMI_LANG_GUJARATI__)
{
{ (char)0x97, (char)0x0A, (char)0xC1, (char)0x0A, (char)0x9C, (char)0x0A, (char)0xB0, (char)0x0A, (char)0xBE, (char)0x0A, (char)0xA4, (char)0x0A, (char)0xC0, (char)0x0A,},
"*#9127#",

"gu-IN"
},
#endif
#if defined(__MMI_LANG_BENGALI__)
{
{ (char)0xac, (char)0x09, (char)0xbe, (char)0x09, (char)0x82, (char)0x09, (char)0xb2, (char)0x09, (char)0xbe, (char)0x09, (char)0x0,},
 "*#9133#",

 "be-IN"
},
#endif
#if defined(__MMI_LANG_ASSAMESE__)
{
{ (char)0x85, (char)0x09, (char)0xb8, (char)0x09, (char)0xae, (char)0x09, (char)0xc0, (char)0x09, (char)0xdf, (char)0x09, (char)0xbe, (char)0x09, (char)0x0,},
 "*#9161#",

 "as-IN"
},
#endif
#if defined(__MMI_LANG_PUNJABI__)
{
{ (char)0x2A, (char)0x0A, (char)0x02, (char)0x0A, (char)0x1C, (char)0x0A, (char)0x3E, (char)0x0A, (char)0x2C, (char)0x0A,(char)0x40, (char)0x0A,},
"*#9172#",

"pa-IN"
},
#endif
#if defined(__MMI_LANG_TELUGU__)
{
{ (char)0x24, (char)0x0C, (char)0x32, (char)0x0C, (char)0x41, (char)0x0C, (char)0x17, (char)0x0C, (char)0x41, (char)0x0C},
"*#9140#",

"te-IN"
},
#endif
#if defined(__MMI_LANG_KANNADA__)
{
{ (char)0x95, (char)0x0C, (char)0xA8, (char)0x0C, (char)0xCD, (char)0x0C, (char)0xA8, (char)0x0C, (char)0xA1, (char)0x0C},
"*#9180#",

"kn-IN"
},
#endif
#if defined(__MMI_LANG_MALAYALAM__)
{
{ (char)0x2E, (char)0x0D, (char)0x32, (char)0x0D, (char)0x2F, (char)0x0D, (char)0x3E, (char)0x0D, (char)0x33, (char)0x0D, (char)0x2E, (char)0x0D, (char)0x4D, (char)0x0D},
"*#9171#",

"ml-IN"
},
#endif
#if defined(__MMI_LANG_LAO__)
{
{ (char)0xC0, (char)0x0E, (char)0xA1, (char)0x0E, (char)0xB7, (char)0x0E, (char)0xAD, (char)0x0E, (char)0x87, (char)0x0E, (char)0xA5, (char)0x0E, (char)0xB2, (char)0x0E, (char)0xA7, (char)0x0E},
"*#0856#",
"lo-IN"
},
#endif
#if defined(__MMI_LANG_KHMER__)
{
{ (char)0x97, (char)0x17, (char)0xB6, (char)0x17, (char)0x9F, (char)0x17, (char)0xB6, (char)0x17, (char)0x81, (char)0x17, (char)0xD2, (char)0x17, (char)0x98, (char)0x17, (char)0xC2, (char)0x17, (char)0x9A, (char)0x17 },
"*#0855#",
"km-IN"
},
#endif
#if defined(__MMI_LANG_MYANMAR__)
{
{ (char)0x19, (char)0x10, (char)0x3C, (char)0x10, (char)0x14, (char)0x10, (char)0x3A, (char)0x10, (char)0x19, (char)0x10, (char)0x2C, (char)0x10},
"*#0095#",
"my-IN"
},
#endif
#if defined(__MMI_LANG_ORIYA__)
{
{ (char)0x13, (char)0x0B, (char)0x21, (char)0x0B, (char)0x3F, (char)0x0B, (char)0x06, (char)0x0B,},
"*#9174#",

"or-IN"
},
#endif
#if defined(__MMI_LANG_XHOSA__)
{
 {(char)0x58,(char)0x0,(char)0x68,(char)0x0,(char)0x6F,(char)0x0,(char)0x73,(char)0x0,(char)0x61,(char)0x0},//Language Name
  "*#0027#",//SSC string name

 "xh-ZA"
},
#endif
#if defined(__MMI_LANG_SWAHILI__)
{
 {(char)0x53,(char)0x0,(char)0x77,(char)0x0,(char)0x61,(char)0x0,(char)0x68,(char)0x0,(char)0x69,(char)0x0,(char)0x6C,(char)0x0,(char)0x69,(char)0x0},//Language Name
  "*#0255#",//SSC string name

 "sw-TZ"
},
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
{
 {(char)0x41,(char)0x0,(char)0x66,(char)0x0,(char)0x72,(char)0x0,(char)0x69,(char)0x0,(char)0x6B,(char)0x0,(char)0x61,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x73,(char)0x0},//Language Name
  "*#0264#",//SSC string name
 
 "af-NA"
},
#endif
#if defined(__MMI_LANG_ZULU__)
{
 {(char)0x5A,(char)0x0,(char)0x75,(char)0x0,(char)0x6C,(char)0x0,(char)0x75,(char)0x0},//Language Name
  "*#0268#",//SSC string name

 "zu-SZ"
},
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
{
 {(char)0x4C,(char)0x0,(char)0x69,(char)0x0,(char)0x74,(char)0x0,(char)0x68,(char)0x0,(char)0x75,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0370#",//SSC string name

 "lt-LT"
},
#endif
#if defined(__MMI_LANG_LATVIAN__)
{
 {(char)0x4C,(char)0x0,(char)0x61,(char)0x0,(char)0x74,(char)0x0,(char)0x76,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0371#",//SSC string name
 
 "lv-LV"
},
#endif
#if defined(__MMI_LANG_ESTONIAN__)
{
 {(char)0x45,(char)0x0,(char)0x73,(char)0x0,(char)0x74,(char)0x0,(char)0x6F,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0372#",//SSC string name

 "et-EE"
},
#endif
#if defined(__MMI_LANG_ARMENIAN__)
{
 {(char)0x41,(char)0x0,(char)0x72,(char)0x0,(char)0x6D,(char)0x0,(char)0x65,(char)0x0,(char)0x6E,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0374#",//SSC string name

 "hy-AM"
},
#endif
#if defined(__MMI_LANG_GEORGIAN__)
{
 {(char)0x47,(char)0x0,(char)0x65,(char)0x0,(char)0x6F,(char)0x0,(char)0x72,(char)0x0,(char)0x67,(char)0x0,(char)0x69,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0995#",//SSC string name

 "ka-GE"
},
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
{
 {(char)0x4D,(char)0x0,(char)0x6F,(char)0x0,(char)0x6C,(char)0x0,(char)0x64,(char)0x0,(char)0x6F,(char)0x0,(char)0x76,(char)0x0,(char)0x61,(char)0x0,(char)0x6E,(char)0x0},//Language Name
  "*#0373#",//SSC string name

 "mo-MD"
},
#endif



};




#endif
