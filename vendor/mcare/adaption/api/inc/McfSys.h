#ifndef _mcfsys_h_
#define _mcfsys_h_

#include "McfCommon.h"

#define MCARE_SCREEN_BASE   (APP_TENCENT_MCARE_BASE)
#define MCARE_SCREEN_HOME   (APP_TENCENT_MCARE_BASE+1)
#define MCARE_SCREEN_EDITOR (APP_TENCENT_MCARE_BASE+2)    

typedef MVOID (*pfnFunc)(MVOID);
typedef MBYTE (*pfnDelFunc)(MVOID*);

//说明：进入mcare UI前需要执行的东西。例如MTK里的EntryNewScreen、其他平台可保存inactive、resume、进ui前的一些准备等实现。
MINT McfSys_Init(pfnFunc inactiveFunc, pfnFunc deepInactiveFunc, pfnFunc resumeFunc, pfnFunc exitFunc);

//固话层调用。退出Mcare UI需要调用的函数，
//nExitType – 退出标志，返回上次的位置还是退出到idle。
MINT McfSys_DeInit(MINT nExitType);


//说明：固化层调用，后台挂机需要执行的操作。 
//nExitType – 退出标志，返回上次的位置还是退出到idle。
MINT McfSys_Background(MINT nExitType);


//============================= 外部调用函数 =====================================
//说明：可供其他平台在外部调用，挂机恢复前需要执行的操作。
MINT McfSys_Foreground(MVOID);

//说明：直接调用固化层的Suspend的导出函数。其他平台发suspend消息可调用。
MINT McfSys_Suspend(MVOID);

//说明：直接调用挂画层Resume的导出函数。其他平台收到resume消息可调用
MINT McfSys_Resume(MVOID);
//====================================================================

MVOID McfSys_InvalidateCpuCache(MBYTE *start, MUINT size);


#endif
