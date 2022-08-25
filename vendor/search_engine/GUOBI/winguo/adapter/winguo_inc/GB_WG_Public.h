

#ifndef __GB_WG_PUBLIC_H__ 
#define __GB_WG_PUBLIC_H__

#include "GB_DataTypeDef.h"
#include "GB_Math.h"
#include "GB_EventFactory.h"
#include "GB_App.h"
#include "GB_WG_fun.h"


// 窗口的各种事件
typedef enum _GBWINEVNENT_
{
	GBWINEVENT_NONE = 0,
		GBWINEVENT_UPGRADESTART,		// 通信开始
		GBWINEVENT_UPGRADEEND,			// 通信结束
		GBWINEVENT_POPUPCANDIDATEBOX,	// 弹出候选框
		GBWINEVENT_PACKUPCANDIDATEBOX,	// 收起候选框
		GBWINEVENT_CLEARPENDOWN,		// 手写完毕需要清理pendown的无效事件
		GBWINEVENT_PACKUPPOPMENU,		// 收起菜单
		GBWINEVENT_VKHIDE
}GBWINEVENT;

#endif //#ifndef __GB_WG_PUBLIC_H__ 