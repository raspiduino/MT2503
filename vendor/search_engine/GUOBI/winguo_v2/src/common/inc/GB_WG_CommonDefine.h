
#ifndef __GB_WG_COMMONDEFINE_H__
#define __GB_WG_COMMONDEFINE_H__

#include "GB_WG_CommonConfig.h"
#include "GB_WG_DataTypeDef.h"

// 电话所处的模式
typedef enum  
{
	e_GB_WG_SMD_PHONE_NORMAL, // 正常
	e_GB_WG_SMD_PHONE_WIFI,		// wifi
	e_GB_WG_PHONE_MODE_VAIN,   // 无效卡
	e_GB_WG_PHONE_MODE_NOSIM,  // 无SIM卡
	e_GB_WG_PHONE_MODE_FLIGHT, // 飞行模式
	e_GB_WG_PHONE_MODE_ENCRYPT,  //通讯录加密
	e_GB_WG_PHONE_MODE_USB,    // usb模式
}GB_WG_Phone_Mode;


typedef GB_VOID (*GB_WG_FuncPtr)(GB_VOID);

#define EmumToFlag(n) (1<<n)

#define GB_WG_SEARCH_WEB_MAX_INPUT_LEN (25)

#endif // __GB_WG_COMMONDEFINE_H__
