#ifdef __MCAREV31__

#include "McfPlatform.h"
#include "MAdpConfig.h"
#include "McfCommon.h"

//平台类型
MCHAR MAdpConfig_GetPlatForm(MVOID)
{
	return MCR_PLATFORMID;
}

//内存类型
MCHAR MAdpConfig_GetMemoryType(MVOID)
{
	return MCR_MEM_MAIN;
}

//内存大小
MUINT MAdpConfig_GetMemorySize(MVOID)
{
	return MCR_MEM_SIZE;
}

//键盘类型
MCHAR MAdpConfig_GetKeyBoardType(MVOID)
{
	return MCR_KEYTYPE;
}

//获得触屏类型
MCHAR MAdpConfig_GetTouchScreenType(MVOID)
{
	return MCR_TOUCHTYPE;
}

//获得厂商
MCHAR* MAdpConfig_GetVendor(MVOID)
{
	return MCR_VENDOR;
}

//获得机型
MCHAR* MAdpConfig_GetTerminalType(MVOID)
{
	return MCR_TERMINALTYPE;
}


//获得固化层版本号
MCHAR* MAdpConfig_GetFrimVersion(MVOID)
{
	#if MCR_REGION_OVERSEA == __CFG_YES__
	return MCR_FIRMVERSION_OVERSEA;
	#else
	return MCR_FIRMVERSION;
	#endif
}

//获得UI配色方案
MINT MAdpConfig_GetUIStyle(MVOID)
{
	return UI_SYS_THEME_COLOR;
}
const MUINT mCfgKernMemSize = MKERN_MEM_SIZE;

MINT MAdpConfig_GetScrnWidth(MVOID)
{
    return MAIN_LCD_DEVICE_WIDTH;
}

MINT MAdpConfig_GetScrnHeight(MVOID)
{
    return MAIN_LCD_DEVICE_HEIGHT;
}

//by jessy 2012.3.8
MINT MAdpConfig_GetIsFileHidden(MVOID)
{
    return IS_MCARE_FILE_HIDDEN;
}


#ifdef USE_SPLASH_LOGO
const MBOOL MCR_USE_SPLASH_LOGO = MTRUE;
#else
const MBOOL MCR_USE_SPLASH_LOGO = MFALSE;
#endif

#endif
