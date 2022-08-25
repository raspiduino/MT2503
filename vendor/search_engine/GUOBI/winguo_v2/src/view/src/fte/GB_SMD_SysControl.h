#ifndef __GB_SMD_SYSCONTROL__
#define __GB_SMD_SYSCONTROL__

#include "MMI_features.h"
#include "CustThemesRes.h"
#include "GB_WG_DataTypeDef.h"
//#include "GB_WG_fun.h"

#define GB_WG_LIST_MENU_MAX_BUFF_LEN              (40)

// typedef struct
// {
// 	GB_U8 point;
// 	GB_U8 len;
// }GBMD_CmpStrInfoEx;

typedef GB_VOID (*GB_FuncPtr) (GB_VOID);
extern MMI_theme *current_MMI_theme;
extern fixed_list_menu MMI_fixed_list_menu;

GB_VOID GB_WG_SMD_Control_CreateInputBox(GB_U16 *pusInputBuff,GB_U16 usInputMaxLen,GB_PU8 left_softkey,
										 GB_PU8 right_softkey,GB_U16 inputbox_width,GB_PU8 pHisBuff);
GB_VOID GB_WG_SMD_Control_CreateButton();
GB_VOID GB_WG_SMD_Control_Set_Search_Button(GB_PU8 up_image, GB_PU8 down_image, GB_FuncPtr search_function);
GB_VOID GB_WG_SMD_Control_CreateList(GB_U16 usCount,GB_INT hightItem,GB_PU8 pHisBuff);
GB_U16 GB_WG_SMD_Control_Get_Input_Data(GB_U16 *pusInputStr);
//GB_VOID GB_WG_SMD_Control_Resize_And_Draw(GB_INT virtual_keyboard_h);
GB_VOID GB_WG_SMD_Control_Register_InputBox_Event_Callback(GB_VOID);
GB_VOID GB_WG_SMD_Control_Register_InputBox_Change_Callback(GB_VOID);
GB_VOID GB_WG_SMD_Control_Release(GB_VOID);
GB_VOID GB_WG_SMD_Control_Resize_And_DrawEx();
GB_VOID GB_WG_SMD_Control_Set_List_Menu_Focus_State(GB_BOOL active);
GB_VOID GB_WG_SMD_Control_Set_InputBox_Focus_State(GB_BOOL active);
GB_BOOL GB_WG_SMD_Control_Is_List_Menu_Active(GB_VOID);
GB_BOOL GB_WG_SMD_Control_Is_InputBox_Active(GB_VOID);

#endif