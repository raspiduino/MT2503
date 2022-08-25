/*=========================================================================
×  版权声明：
*  --------------------
* 版权所有广东国笔科技股份有限公司，未经授权禁止个人和任何组织拷贝和使用，违反必究。
*
*
*
*
*  ---------国笔科技股份有限公司-----------
*
*文件说明: gb_wrapper.h
*国笔输入法与MTK平台对接的MMI代码
*
*=============================================================================*/


#ifndef __GB_WRAPPER_H__
#define __GB_WRAPPER_H__

#include "gbtype.h"
#include "gui_data_types.h"
#include "wgui_include.h"
#if defined(__MMI_TOUCH_SCREEN__)
#include "TouchScreenGprot_Int.h"
#endif
/*===============输入法功能配置===================================*/

//开启:左键 和Ok键支持选字, 关闭：仅 Ok键支持选字  
#define  __GB_INPUTMETHOD_SELECT_CANDIDATE_USE_LEFT_SORFKEY__


/*国笔输入法候选内容支持"左软键"选择 */
#ifdef  __GB_INPUTMETHOD_SELECT_CANDIDATE_USE_LEFT_SORFKEY__
    #define   __GB_LEFT_SOFTKEY_SELECT_CANDIDATE__ 
#endif
/*end*/
extern void (*g_imc_key_inputbox_LSK_function) (void);

#if defined(__MMI_WGUI_CSK_ENABLE__)
	extern void (*g_imc_key_inputbox_CSK_function) (void);
#endif

extern void wgui_set_EMS_inputbox_RSK(void);
extern void register_EMS_inputbox_keys(void);

extern void GBChangeInputModeForInputBox(int inputMethod);
extern void GBClearAllKeyHandler(void); 
extern void GBInputMethodReset(void); 
extern void GBSetAllKeyHandler(void); 
extern void GBInputMethodInit(void); 
extern void GBInputMethodExit(void); 
extern void GBCloseCand(void);
extern void GBCheckCandWnd(void);
extern void GBDrawCandWnd(void);
extern int   GbIsInputEmpty(void);
extern void GBKeyPoundPressHandlerForInputBox(void);

extern void GBUpdateSoftkey(void);
extern void GBSetFuncKey(void);

extern void GBUpScreen(void);
extern int GBEventHandler(GBINT evtType, GBINT param);
extern int GBGetCharInfo(unsigned short  wc, unsigned short * pCharInfoBuffer, unsigned char MaxInfoBuffer,unsigned short inputMode);
extern void GBHandleTouchEvent(U16 x, U16 y, mmi_pen_event_type_enum pen_event);
extern void GBSetAllArrowHandler(void);
extern int IsGbInputMode();


//记录系统左右软键图标，用于恢复时使用
extern UI_string_type Old_left_softkey_label;
extern UI_string_type Old_right_softkey_label;

#endif
