/*! @file
********************************************************************************
<PRE>
模块名       : 
文件名       : DataTypeDefine.h
相关文件     : 
文件实现功能 : 基本数据类型定义、基础函数定义、代码配置信息定义，用于跨平台。
作者         : Knight
版本         : 1.0
--------------------------------------------------------------------------------
备注         : 
--------------------------------------------------------------------------------
修改记录 : 
日 期        版本     修改人			修改内容
2008/08/01   1.1      anlanyu			添加注释，整理排版
</PRE>
*******************************************************************************/
#ifndef DATA_TYPE_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H
#define DATA_TYPE_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H

#include<stdio.h>
#include<string.h>
#include<Stdlib.h>


typedef char                        GB_CHAR;
typedef unsigned char               GB_BYTE;
typedef signed short                GB_SHORT;
typedef unsigned short              GB_USHORT;
typedef signed long					GB_LONG;
typedef unsigned long				GB_ULONG;
typedef int                         GB_INT;
typedef unsigned int                GB_UINT;
typedef unsigned char*              GB_PU8;

typedef unsigned int 				GB_U32;
typedef unsigned short              GB_U16;
typedef unsigned char               GB_U8;
typedef int                         GB_BOOL;
typedef void                        GB_VOID;
typedef signed char                 GB_S8;
typedef signed short                GB_S16;
typedef signed char*                GB_PS8;
typedef signed char                 GB_INT8;
typedef GB_INT                      GBRETURN ;
typedef unsigned short              GB_WCHAR;
typedef const GB_WCHAR*             GB_CPWSTR;
typedef GB_WCHAR                    GB_CHARTYPE;
typedef GB_WCHAR*                   GB_STRTYPE;

typedef GB_LONG                     GB_COLOR;
typedef GB_VOID*                    GB_WG_GDIHANDLE;
typedef GB_VOID(*GB_WG_FuncPtr)(GB_VOID);
//  [3/1/2012 liangchuanhui]
//typedef GB_VOID(*GB_WG_MenuHandleFuncPtr)(GB_U16* pNumber, GB_U16* pContent,GB_INT storeIndex);
typedef GB_VOID (*GB_WG_MENUFUNC)(GB_VOID* pUser, GB_VOID *pData, GB_LONG command);

#define GB_MEMCPY                   memcpy
#define GB_MEMCMP                   memcmp
#define GB_MEMSET                   memset
#define GB_MEMMOVE                  memmove
#define GB_STRSTR                   strstr
#define GB_STRLEN                   strlen
#define GB_STRCPY                   strcpy
#define GB_STRNCPY                  strncpy
#define GB_STRCHR                   strchr
#define GB_STRRCHR                  strrchr
#define GB_STRCMP                   strcmp
#define GB_ATOI                     atoi
#define GB_ITOA                     itoa
#define	GB_ATOL                     atol
#define GB_SPRINTF                  sprintf
#define GB_STRCAT                   strcat
#define GB_VSPRINT                  vsprintf
#define GB_ATOI                     atoi
#define GB_WG_Srand                 srand
#define GB_WG_Rand                  rand
#define GB_MEMCMP					memcmp


#define GB_WG_UI_MakeColor(r,g,b)	((GB_COLOR)(((r)<<16)+((g)<<8)+(b)))

#define GB_WG_UI_COLOR_LIGHT_GREY	GB_WG_UI_MakeColor(120,120,120)
#define GB_WG_UI_COLOR_WHITE		GB_WG_UI_MakeColor(255,255,255)
#define GB_WG_UI_COLOR_DARK_GREY	GB_WG_UI_MakeColor(64,64,64)
#define GB_WG_UI_COLOR_BLACK		GB_WG_UI_MakeColor(0,0,0)
#define GB_WG_UI_COLOR_RED			GB_WG_UI_MakeColor(255,0,0)
#define GB_WG_UI_COLOR_GREY			GB_WG_UI_MakeColor(192,192,192)
#define GB_WG_UI_COLOR_GREEN		GB_WG_UI_MakeColor(0,255,0)
#define GB_WG_UI_COLOR_BLUE			GB_WG_UI_MakeColor(0,0,255)

typedef enum
{
	GB_MMI_large_font = 0,
	GB_MMI_medium_font,
	GB_MMI_small_font,
	GB_MMI_dialer_font
}GB_WG_FONT;

typedef enum
{
	e_GB_WG_LANGUAGE_CN = 0,
	e_GB_WG_LANGUAGE_EN,
	e_GB_WG_LANGUAGE_OTHER
}GB_WG_LANGUAGE;

#define GB_NULL					((void*)0)
#define GB_FALSE  				0
#define GB_TRUE  				1
#define GB_WG_HAND_OK			1
#define GB_WG_HAND_FAIL			0

#define EmumToFlag(n) (1<<n)
				
typedef struct _GB_RECT
{
	GB_INT xPos;
	GB_INT yPos;
	GB_INT width;
	GB_INT height;
}GB_Rect;

typedef struct  
{
	GB_SHORT x;
	GB_SHORT y;
}GB_POINT; 

typedef struct _GBBROWSERLISTENER
{
	GB_VOID *pParent;
	GB_VOID *pChild;
}GBBrowserListener;

typedef struct  
{
	GB_INT keyEvent;
	GB_INT keyValue;
}GB_WG_KeyEventStr;

typedef struct  
{
	GB_INT pen_event;
	GB_INT x;
	GB_INT y;
}GB_WG_PenEventStr;

typedef struct  
{
	GB_U16 nYear;   /* 年 */
    GB_U8 nMonth;   /* 月 */
    GB_U8 nDay;     /* 日 */
    GB_U8 nHour;    /* 时 */
    GB_U8 nMin;     /* 分 */
    GB_U8 nSec;     /* 秒 */
    GB_U8 DayIndex; /* 周 0=Sunday */
}GB_TIME_STRUCT;

/************************************************************************/
/* 宏定义                                                               */
/************************************************************************/
//#define GB_WINGUO_DEBUG
#define GBWG_VIRTUAL_KEY

#define GB_WG_SYS_SEND_MESSAGE // 使用系统的短信接口 [12/1/2011 liangchuanhui]
//#define GB_WINGUO_NEW_SMS			// 新短信
//#define GB_WINGUO_IMGSKIN

#ifndef GBMD_DYNAMIC_MEM
#define GBMD_DYNAMIC_MEM
#endif

// #ifndef GB_WINGUO_DEBUGTIME
// #define GB_WINGUO_DEBUGTIME
// #endif

//#define __GB_WINGUO_XML_SLOWTEST__

											    			
#endif // #ifndef DATA_TYPE_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H
