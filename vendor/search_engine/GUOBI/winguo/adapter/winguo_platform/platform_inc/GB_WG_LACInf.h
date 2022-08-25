#ifndef __GB_WG_LACINF_H_BY_FOR_GETLAC_ZHANGWEI_JERRY_20110831__
#define __GB_WG_LACINF_H_BY_FOR_GETLAC_ZHANGWEI_JERRY_20110831__

#include "GB_DataTypeDef.h"

// 测试专用
//#define __GB_WG_LACINF_DEBUG__

// 获取基站信息
typedef enum __GB_WG_LACINF_STATE__
{
	GB_WG_LACINF_STATE_NONE = 0,
		GB_WG_LACINF_STATE_SUCCESS,	// 获取成功
		GB_WG_LACINF_STATE_FAILURE,	// 获取失败
		GB_WG_LACINF_STATE_END		
}GB_WG_LACINF_STATE;

typedef GB_VOID (*GB_WG_LACINF_FUNCALLBACK)(GB_WG_LACINF_STATE state,GB_CHAR* cell_id,GB_VOID* pUser);

// 获取状态
//GB_WG_LACINF_STATE GB_WG_GetLacState(GB_VOID);
// 设置状态
//GB_VOID GB_WG_SetLacState(GB_WG_LACINF_STATE state);
// 取得基站信息
GB_CHAR* GB_WG_Get_Cell_id(GB_VOID);
// 启动获取基站信息的消息
//GB_VOID GB_WG_Get_Cell_Msg(GB_VOID);
GB_VOID GB_WG_Get_Cell(GB_WG_LACINF_FUNCALLBACK pLacFunCallback,GB_VOID* pUser);


#endif
