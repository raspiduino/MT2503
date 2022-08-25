#ifndef _madpconfig_h
#define _madpconfig_h

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#include "MAdpType.h"


//[some features for customize]
//__CFG_YES__,__CFG_NO__
#ifdef __MCARE_OVERSEA__
#define MCR_REGION_OVERSEA  __CFG_YES__ 
#else
#define MCR_REGION_OVERSEA  __CFG_NO__ 
#endif

//MTK Version
#define MCR_MTK_VER			MTK_VER_1210

//////////////////////////////////////////////////////////////////////////
/////////////////////////固话ROM配置////////////////////
//////////////////////////////////////////////////////////////////////////
//加载层
#define MCR_USE_ROM_LOADEDLAYER		__CFG_TMZ__

//QB
#if MCR_REGION_OVERSEA == __CFG_YES__
#define MCR_USE_ROM_QQB				__CFG_TMC__
#else
#define MCR_USE_ROM_QQB				__CFG_NONE__
#endif

//QQ
#define MCR_USE_ROM_QQ				__CFG_NONE__



//////////////////////////////////////////////////////////////////////////
/////////////////////////内存配置////////////////////
//////////////////////////////////////////////////////////////////////////
#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__))) //by purple

#if (MCR_MTK_VER >= MTK_VER_1210)
//主内存内存类型 - media、asm、static
#define MCR_MEM_MAIN			MCR_MEMTYPE_ASM

//核心备用内存内存类型 - media、asm、static（例如加载层代码段以及运行内存）
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_ASM

//应用备用内存内存类型 - media、asm、static(例如QQ挂机内存)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_ASM

#else
//主内存内存类型 - media、asm、static
#define MCR_MEM_MAIN			MCR_MEMTYPE_STATIC

//核心备用内存内存类型 - media、asm、static（例如加载层代码段以及运行内存）
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_STATIC

//应用备用内存内存类型 - media、asm、static(例如QQ挂机内存)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_STATIC
#endif

#else

#if (MCR_MTK_VER >= MTK_VER_1210)
//主内存内存类型 - media、asm、static
#define MCR_MEM_MAIN			MCR_MEMTYPE_ASM

//核心备用内存内存类型 - media、asm、static（例如加载层代码段以及运行内存）
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_ASM

//应用备用内存内存类型 - media、asm、static(例如QQ挂机内存)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_ASM

#else
//主内存内存类型 - media、asm、static
#define MCR_MEM_MAIN			MCR_MEMTYPE_MEDIA

//核心备用内存内存类型 - media、asm、static（例如加载层代码段以及运行内存）
#define MCR_MEM_KERNRESER		MCR_MEMTYPE_MEDIA

//应用备用内存内存类型 - media、asm、static(例如QQ挂机内存)
#define MCR_MEM_APPRESER		MCR_MEMTYPE_MEDIA
#endif

#endif


#ifdef MSHELL_DEBUG
#define MDEBUG_EXTRA_MEM_SIZE   (100*1024)
#else
#define MDEBUG_EXTRA_MEM_SIZE   (0)
#endif

#if MCR_REGION_OVERSEA == __CFG_YES__
#define MKERN_MEM_SIZE 	(60 * 1024 + MDEBUG_EXTRA_MEM_SIZE)
#else
#define MKERN_MEM_SIZE 	(100 * 1024 + MDEBUG_EXTRA_MEM_SIZE)
#endif

//////////////////////////////////////////////////////////////////////////
/////////////////////////静态内存配置////////////////////
//////////////////////////////////////////////////////////////////////////
#if MCR_MEM_MAIN == MCR_MEMTYPE_STATIC
#define MCR_MEM_MAIN_STATIC_SIZE			(800*1024)
#else
#define MCR_MEM_MAIN_STATIC_SIZE			(0)
#endif

#if MCR_MEM_KERNRESER == MCR_MEMTYPE_STATIC
#define MCR_MEM_KERN_STATIC_SIZE		    (MKERN_MEM_SIZE)
#else
#define MCR_MEM_KERN_STATIC_SIZE			(0)
#endif

#if MCR_MEM_APPRESER == MCR_MEMTYPE_STATIC
#define MCR_MEM_APP_STATIC_SIZE				(1024*100)
#else
#define MCR_MEM_APP_STATIC_SIZE				(0)
#endif

#define MCR_MEM_STATIC_TOTAL    (MCR_MEM_MAIN_STATIC_SIZE+MCR_MEM_KERN_STATIC_SIZE+MCR_MEM_APP_STATIC_SIZE)





//////////////////////////////////////////////////////////////////////////
/////////////////////////基本配置////////////////////
//////////////////////////////////////////////////////////////////////////
//固化层版本号
#define MCR_FIRMVERSION_OVERSEA		("003.03.04.013075")//海外版本

#define MCR_FIRMVERSION		("000.03.04.018483")//国内版本

//厂商
#define MCR_VENDOR			("mediatec")//("HK")

//机型
#define MCR_TERMINALTYPE    ("6255")//("hd101")

//porting id removed and add it to file MHelperFunc

//平台
#define MCR_PLATFORMID		PLATFORMID_MCARE_MTK6235


//键盘类型
#define MCR_KEYTYPE			MKEYTYPE_NORMAL_KEYPAD

//触屏类型
#define MCR_TOUCHTYPE		MTOUCHSCREEN_YES


//主存存储类型
#if defined(WIN32) || (MCR_PLATFORMID == PLATFORMID_MCARE_MTK6225) || (MCR_PLATFORMID == PLATFORMID_MCARE_MTK6252) 
#define MCR_STORAGE_TYPE    MCR_STORAGE_CARD
#else
#define MCR_STORAGE_TYPE    MCR_STORAGE_CARD
#endif

//mcare 文件夹是否隐藏，默认隐藏 
#define IS_MCARE_FILE_HIDDEN __CFG_YES__

//最低存储要求
#define MCR_FS_REQ           (1024 * 1024)


//平台Ram内存 - 如果低于这个值需要修改一下
#define MCR_MEM_SIZE		 (1100 * 1024)


//3、4卡、wifi支持;如果手机支持相应项目，请标识为__CFG_YES__
#define MCR_SIM3_SUPPORT    __CFG_NO__
#define MCR_SIM4_SUPPORT    __CFG_NO__

#ifdef __WIFI_SUPPORT__
#define MCR_WIFI_SUPPORT    __CFG_YES__
#else
#define MCR_WIFI_SUPPORT    __CFG_NO__
#endif

//QQ来消息是否点亮屏
#define MCR_BLACKLIGHT_TURNON   __CFG_YES__

#if MCR_MTK_VER >= MTK_VER_1032
#define _MCR_MMI_RESOURCE_XML_GEN_
#endif


//UI配色方案
//Mcare平台的配色方案，目前支持3中颜色:    UI_THEME_BLUE,UI_THEME_PINK,UI_THEME_BROWN
#define UI_SYS_THEME_COLOR   (UI_THEME_BLUE)


//#if MCR_MTK_VER >= MTK_VER_952
//#define USE_SYSTEM_ZLIB    //whether to use system zlib..prefer to use to reduce rom space
//#endif

#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__))) //by purple
#define MCR_CAMERA_SUPPORT      __CFG_NO__
#elif defined __MMI_CAMERA__ || defined __MMI_CAMCORDER__
#define MCR_CAMERA_SUPPORT      __CFG_YES__
#else
#define MCR_CAMERA_SUPPORT      __CFG_NO__
#endif
#define MCR_SUPPORT_WAP_BROWSER     __CFG_NO__

#if MCR_REGION_OVERSEA == __CFG_YES__
#define USE_SYSBRW_DTCNT   //whether to use system browser's data account profile instead

#define __MCR_LANG_ENGLISH__            __CFG_YES__
#define __MCR_LANG_HINDI__              __CFG_NO__
#define __MCR_LANG_VIETNAMESE__         __CFG_NO__
#define __MCR_LANG_INDONESIAN__         __CFG_NO__
#define __MCR_LANG_THAI__               __CFG_NO__

//#define USE_SPLASH_LOGO  //whether to put splash logo on when entering to mcare
#else
//#define USE_SYSBRW_DTCNT   //
#define USE_SPLASH_LOGO  //
#endif



#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif // _madpconfig_h
