// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__31E3F20A_71F3_403B_9100_F827AC8102AC__INCLUDED_)
#define AFX_STDAFX_H__31E3F20A_71F3_403B_9100_F827AC8102AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <stdio.h>

//#define Test_ON_PC

#ifdef     Test_ON_PC

#pragma comment(lib,"libforfont.lib")
#if defined(_MSC_VER)
#pragma comment(lib, "Dev_BFCEnc.lib")// no need change to .a when you debug on PC
#else
#pragma comment(lib, "libbfenc.lib")
#endif
#pragma comment(lib, "LzmaLib.lib")


/*  Must delete when use resgen. */
#define __MMI_LANG_ENGLISH__
#define __MMI_LANG_SPANISH__
#define __MMI_LANG_TR_CHINESE__
#define __MMI_LANG_SM_CHINESE__
#define __MMI_CHAR_SET_GB2312__
#define __MMI_CHAR_SET_BIG5__

#define __MMI_LANG_THAI__
#define __MMI_LANG_HINDI__
#define __MMI_LANG_ARABIC__

#define __MMI_LANG_RUSSIAN__
#define __MMI_LANG_GREEK__
#define __MMI_LANG_HEBREW__


#define __MMI_LANG_HK_CHINESE__
#define __MMI_LANG_PERSIAN__
#define __MMI_LANG_KHMER__
#define __MMI_LANG_MYANMAR__
#define __MMI_LANG_LAO__
#define __MMI_LANG_TAMIL__
#define __MMI_LANG_BENGALI__
#define __MMI_LANG_GUJARATI__
#define __MMI_LANG_PUNJABI__
#define __MMI_LANG_TELUGU__
#define __MMI_LANG_KANNADA__
#define __MMI_LANG_MALAYALAM__
#define __MMI_LANG_ORIYA__
#define __MMI_LANG_ARMENIAN__
#define __MMI_LANG_GEORGIAN__

#define __MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__


//#define __MMI_FONT_COMPRESSION__
//#define __MMI_BDF_SW_COMPRESSION__
//#define __MMI_FONT_GROUP_COMPRESSION__

/************************************************/

//#define TEST_DECODE

#define __MMI_MAINLCD_320X480__
//#define __MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__
//#define __MMI_16X16_CHINESE_FONT__
//#define __MMI_CHINESE_WITH_SMALL_FONT__

#else 

#include "mmi_features.h"

#endif

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__31E3F20A_71F3_403B_9100_F827AC8102AC__INCLUDED_)
