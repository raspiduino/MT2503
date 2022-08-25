/*! @file
********************************************************************************
<PRE>
模块名       : 
文件名       : GB_WinStack.h 
相关文件     : 
文件实现功能 : 窗口栈，方便窗口状态的返回
作者         : Knight
版本         : 1.0
--------------------------------------------------------------------------------
备注         : 
--------------------------------------------------------------------------------
修改记录 : 
*******************************************************************************/


#ifndef GB_WG_APP_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_01_10_H
#define GB_WG_APP_DEFINE_FOR_PLATFORM_KNIGHTNIU_2010_01_10_H

#include "GB_DataTypeDef.h"
#include "GB_EventFactory.h"

/////////////////////////////////
typedef struct _SysApp{
	////
	////
	GB_INT classId;///
}SysApp;


////消息
typedef struct
{
	GB_INT	msg_ID;
	GB_VOID *parma;
}GB_WG_msg_sturct;

// 入口的函数指定
typedef GB_VOID (*GB_WG_ENTRYFUN)(GB_VOID);

SysApp * GB_WG_GetSysApp();


GB_VOID  GB_WG_Msg_Handle(GB_WG_msg_sturct *local_para);

// add by zhangwei-jerry
extern GB_VOID GB_WG_APP_SetEntryFun(GB_WG_ENTRYFUN pFun);
extern GB_WG_ENTRYFUN GB_WG_APP_GetEntryFun(GB_VOID);

//////////////////////////////////
// 启动时初始化
extern GB_VOID GB_WG_BootupInit(GB_VOID);

GB_VOID GB_WG_Init(GB_VOID);
GB_VOID GB_WG_Entry_Win(GB_VOID);
GB_VOID GB_WG_Exit_Win(GB_VOID);
GB_VOID GB_WG_FreeWin(GB_VOID);  //将窗口全部释放
GB_VOID GB_WG_WinguoSearchScreen(GB_VOID); // 直接进入winguo搜索界面

GB_BOOL GB_WG_HandleKey_Win(GBKeyEvent keyEvent, GBKeyValue keyValue);
GB_BOOL GB_WG_HandlePen_Win(GBPenEvent penEvent,GB_INT xPos,GB_INT yPos);
GB_VOID GB_WG_DrawScreen(GB_Rect *rect);

GB_VOID GB_WG_Save_account(GB_ULONG account,GB_INT apn,GB_INT selSim,GB_BYTE* imsi);

//GB_UINT GBGetWinguoVerificationCode(GB_UINT inWinguoVerify);

//GB_ULONG GB_WG_GetAccount();

//////////////////



#endif