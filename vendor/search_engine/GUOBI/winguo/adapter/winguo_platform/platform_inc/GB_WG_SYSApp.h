
#ifndef __GB_WG_SYSAPP_H__
#define __GB_WG_SYSAPP_H__

#include "GB_DataTypeDef.h"

/************************************************************************************/
/* 接口说明：																		*/
/*																					*/
/*    供外部使用WINGUO短信王														*/
/*																					*/
/* 使用例子：																		*/
/*	void mmi_um_highlight_write_msg(void)											*/
/*	{																				*/
/*		...																			*/
/*		#ifdef __GB_WINGUO_4__														*/
/*		SetLeftSoftkeyFunction(GB_WG_Entry_SMS, KEY_EVENT_UP);						*/
/*		SetCenterSoftkeyFunction(GB_WG_Entry_SMS, KEY_EVENT_UP);					*/
/*		#else																		*/
/*		SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);			*/
/*		SetKeyHandler(mmi_uc_pre_entry_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	*/
/*		#endif																		*/
/*		...																			*/
/*	}																				*/
/*																					*/
/************************************************************************************/
/*GB_VOID GB_WG_Entry_SMS(GB_VOID);*/

/************************************************************************************/
/* 接口说明：																		*/
/*																					*/
/*    供外部添加“国笔问果”本地菜单												*/
/*																					*/
/* 使用方法：																		*/
/*																					*/
/*	1、先在GlobalMenuItems.h定义MENU_ID_GB_WG菜单ID									*/
/*	2、把MENU_ID_GB_WG加到某个菜单组下面											*/
/*	3、ADD_APPLICATION_MENUITEM((MENU_ID_GB_WG, MAIN_MENU_SERVICES_MENUID, 0,		*/
/*					SHOW, NONMOVEABLE, 1, STR_GB_WINGUO, IMG_WG_WINGUO_LOGO_OUT));	*/
/*	ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_GB_WG,							*/
/*					GB_WG_mmi_entry_Winguo_highlight_hdlr);							*/
/*																					*/
/* 注意地方：																		*/
/*																					*/
/*	其中菜单名称和图标必须使用STR_GB_WINGUO和IMG_WG_WINGUO_LOGO_OUT					*/
/*																					*/
/************************************************************************************/
GB_VOID GB_WG_mmi_entry_Winguo_highlight_hdlr(GB_VOID);

// 用于SMARTDIAL应用菜单 [6/8/2011 yaobicai]
GB_VOID GB_WG_Entry_Winguo(GB_VOID);

extern GB_VOID GB_WG_ExitApp(GB_VOID);
extern GB_VOID GB_WG_RegisterKeyHandle(GB_BOOL bCareEnd);
// 通知系统，绘画指定区域
extern GB_VOID GB_WG_ReDrawScreen(GB_Rect *RedrawRect);

extern GB_VOID GB_WG_RegisterControlKeyHandle(void);			//modify by zhangchenglong 2011_11_10
extern GB_VOID GB_WG_HandleKey(GB_VOID);						//modify by zhangchenglong 2011_11_10

extern GB_BOOL GB_WG_Is_In_Winguo(GB_VOID);
extern GB_BOOL GB_WG_Is_In_Idle(GB_VOID);
extern GB_BOOL GB_WG_Is_In_SSC(GB_VOID);
extern GB_BOOL GB_WG_Is_Calling();

// 判断是否是桌面的widget进来的 [5/15/2012 liangchuanhui]
// #ifdef GBWG_VIRTUAL_KEY
// GB_BOOL GB_WG_IS_Widget(GB_VOID);
// GB_BOOL GB_WG_IS_InputData(GB_VOID);
// #endif


GB_VOID GB_WG_Handle_In_SSC(GB_VOID);

// 发送广播消息
extern GB_BOOL GBBroadcaset_SendMessage(GB_INT event,GB_VOID* param);

GB_VOID GB_WG_send_msg(GB_INT MSG_ID, GB_VOID *Prama);
GB_VOID GB_WG_Entry(GB_U16 Keycode, GB_U16 Keytype);
GB_VOID GB_WG_GotoIdleScreen(GB_VOID);

GB_VOID GB_WG_GroupScreenCreat(GB_U16 Keycode, GB_U16 Keytype);	//modify by zhangchenglong 2011_11_18

#endif
