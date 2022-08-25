
#ifndef __GB_PLATIME_H__
#define __GB_PLATIME_H__

#include "GB_DataTypeDef.h"


GB_VOID GB_WG_R_ImeInit(GB_VOID);
GB_VOID GB_WG_R_Release(GB_VOID);
GB_VOID GB_WG_R_ImeConnect(GB_INT editorType, GB_INT inputType, GB_INT inputmodData);
GB_VOID GB_WG_R_ImeDisconnect(GB_VOID);
GB_VOID GB_WG_R_ImeShow(GB_VOID);
GB_BOOL GB_WG_R_ImeCanShow(GB_VOID);
// ²âÊÔº¯Êý [4/18/2012 liangchuanhui]
GB_INT GB_WG_R_ImeGetRectEx(GB_Rect *rect);
GB_BOOL GB_WG_R_IsImeGetRectOK(GB_Rect *rect);
//GB_INT GB_WG_R_ImeGetRect(GB_Rect *rect);
unsigned short* ime_get_editerText(void);

GB_INT GB_WG_R_ImeKeyInput(GB_INT keyEvent,GB_INT keyValue);

GB_BOOL GB_WG_R_IsInImeRect(GB_INT x, GB_INT y);
GB_BOOL GB_WG_R_ImeGetCandRect(GB_Rect *rect);
GB_VOID GB_WG_R_ImeDrawImeIcon(GB_INT x, GB_INT y,GB_INT width,GB_INT height);
GB_BOOL GB_WG_R_ImeVKIsShowState(GB_VOID);
GB_INT GB_WG_R_ImeSetCandInputString(GB_WCHAR *pInputString);
GB_VOID GB_WG_R_SetVKDefaltShow(GB_BOOL isShow);
GB_VOID GB_WG_ShowSMDCandWnd(GB_VOID);

GB_VOID GB_WB_CheckInputString(const GB_WCHAR* srcinputstring, GB_WCHAR* destinputstring, GB_INT destinputbufferlength);

GB_BOOL GB_WG_PlatIme_is_vk_disabled(GB_VOID);
GB_BOOL GB_WG_InputBoxCursorLoop(GB_INT InputBoxType);

#endif // #ifndef __GB_PLATIME_H__

