#ifndef GBHW_PALT_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H
#define GBHW_PALT_FOR_PLATFORM_KNIGHTNIU_2010_05_12_H

#include "GB_DataTypeDef.h"


GB_LONG GB_WG_GetScrW(GB_VOID);

GB_LONG GB_WG_GetScrH(GB_VOID);

GB_VOID GB_WG_pen_register_down_handler(GB_VOID* pen_fp);

GB_VOID GB_WG_pen_register_move_handler(GB_VOID* pen_fp);

GB_VOID GB_WG_pen_register_up_handler(GB_VOID* pen_fp);

GB_VOID GB_WG_pen_register_long_tap_handler(GB_VOID* pen_fp);/////change bill

GB_INT GB_WG_SysKeyTransform(GB_INT key);

GB_INT GB_WG_SysKeyEventTransform(GB_INT KeyEvent);

GB_INT GB_WG_SysPenEventTransform(GB_INT penEvent);


GB_INT GB_WG_WinguoKeyToSys(GB_INT wg_key);

GB_INT GB_WG_WinguoKeyEventToSys(GB_INT wg_keyEvent);

typedef enum
{
	E_PhoneHW_COMPANY = 0,
	E_PhoneHW_PSTYLE,
	E_PhoneHW_ROM,
//	E_PhoneHW_PLATFORM,
	E_PhoneHW_LICENSE
}GB_WG_E_PhoneHW_Info;

GB_CHAR *GB_WG_Get_PhoneHW_Info(GB_WG_E_PhoneHW_Info einfo);


#endif
