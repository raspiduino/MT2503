
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__
#undef GB_PACKAGE

#include "MMI_include.h"
//#include "frameworkProt.h"
#include "IdleAppProt.h"
//  [7/29/2011 lzp]#include "SSCResDef.h"

#include "GB_ConfigDef.h"
#include "mmi_rp_app_gb_winguo_def.h"
#include "GB_WG_Public.h"
#include "GB_WG_MTKPlatver.h"
#include "GB_WG_SYSApp.h"			//modify by zhangchenglong 2011_11_10


#include "GB_SystemPlat.h" 
#include "gui_effect_oem.h"
#ifdef __WINGUO_USE_ASM_2_0__
#include "mmi_frm_app_launcher_gprot.h"
#endif

#ifdef GBUSE_ASM_MEM
#ifdef __WINGUO_USE_ASM_2_0__
static MMI_RET mmi_winguo_register_proc(mmi_event_struct *evt);
static MMI_ID vapp_winguo_launch_int();
static void mmi_winguo_app_exit(void);
static void mmi_winguo_app_memory_prepare(void);
static void mmi_winguo_app_memory_unprepare(void);
#endif
#ifdef __WINGUO_USE_ASM_1_0__
static MMI_BOOL mmi_winguo_memory_prepare(void);
static void mmi_winguo_asm_stop_cb(void);
static void mmi_winguo_alloc_mem_cb(void);
static MMI_BOOL mmi_winguo_is_asm_enough();
MMI_BOOL mmi_winguo_memory_prepare(void);
#endif
#endif


static GB_VOID GB_WG_SelfMsg_CallBack(GB_VOID * pData);

GB_BOOL GB_WG_Is_In_Winguo(GB_VOID)
{
	return (mmi_frm_scrn_get_active_id() == SCR_GB_WINGUO_SCREEN);
}


GB_BOOL GB_WG_Is_In_SSC(GB_VOID)
{
//  [7/29/2011 lzp]	return (GetActiveScreenId() == SCR_ENTER_SSC);
	return 0;
}

GB_VOID GB_WG_Handle_In_SSC(GB_VOID)
{
	if (GB_WG_Is_In_SSC())
	{
		mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);//DeleteScreenIfPresent(SCR_GB_WINGUO_SCREEN);
	}
}

#include "mmi_frm_scenario_prot.h"  //by yyk

GB_BOOL GB_WG_Is_In_Idle(GB_VOID)
{
//	return (GB_BOOL)mmi_idle_is_on_idle_screen();
//	return GetActiveScreenId() == GetIdleScrnId();
	return (mmi_frm_group_get_active_id() == shell.scenario_root.m_head->id);
}


//////注册函数，然后，可以通过回调，然后进行调度，不过必要性没那么强
GB_VOID GB_WG_HandlePenDown(mmi_pen_point_struct pos)
{
	GB_WG_HandlePen_Win(GBPEN_DOWN,pos.x,pos.y);
}

GB_VOID GB_WG_HandlePenMove(mmi_pen_point_struct pos)
{
	GB_WG_HandlePen_Win(GBPEN_MOVE,pos.x,pos.y);
}

GB_VOID GB_WG_HandlePenUp(mmi_pen_point_struct pos)
{
	GB_WG_HandlePen_Win(GBPEN_UP,pos.x,pos.y);
}

GB_VOID GB_WG_HandlePenLongTap(mmi_pen_point_struct pos)
{
	GB_WG_HandlePen_Win(GBPEN_LONGTAP,pos.x,pos.y);
}

/////////////////////////////////////////////
static GB_USHORT GB_WG_PreDownKeyCode = KEY_INVALID;		//modify by zhangchenglong 2011_11_10
GB_VOID GB_WG_HandleKey(GB_VOID)
{
	GB_USHORT keyCode,keyType;
	GetkeyInfo(&keyCode, &keyType);
	
	switch(keyCode){
	case KEY_VOL_UP:
		keyCode = KEY_UP_ARROW;
		break;
	case KEY_VOL_DOWN:
		keyCode = KEY_DOWN_ARROW;
		break;
	}
	if (keyType == KEY_EVENT_DOWN)		
	{
		GB_WG_PreDownKeyCode = keyCode;
	}
	if (GB_WG_PreDownKeyCode != keyCode)
	{
		return;
	}
#ifdef __COSMOS_MMI_PACKAGE__
	if (keyCode == KEY_END)
	{
		return;
	}
#endif	
	GB_WG_HandleKey_Win(GetKeyEventFromPlat(keyType),GetKeyValueFromPlat(keyCode));	
	if(keyType == KEY_EVENT_UP)
	{
		GB_WG_PreDownKeyCode = KEY_INVALID;
	}
}

void GB_WG_RegisterKeyHandle(GB_BOOL bCareEnd)
{
	ClearAllKeyHandler();
	SetGroupKeyHandler(
        GB_WG_HandleKey, 
        (PU16)PresentAllKeys, 
        (U8)TOTAL_KEYS, 
        (U16)KEY_EVENT_DOWN);
	SetGroupKeyHandler(
        GB_WG_HandleKey, 
        (PU16)PresentAllKeys, 
        (U8)TOTAL_KEYS, 
        (U16)KEY_EVENT_UP);
	SetGroupKeyHandler(
        GB_WG_HandleKey, 
        (PU16)PresentAllKeys, 
        (U8)TOTAL_KEYS, 
        (U16)KEY_LONG_PRESS);

	mmi_frm_set_power_end_key_handler();
	SetKeyHandler(GB_WG_HandleKey, KEY_BACK, KEY_EVENT_DOWN); // add [8/19/2011 Leijinfu]
	SetKeyHandler(GB_WG_HandleKey, KEY_BACK, KEY_LONG_PRESS); // add [8/19/2011 Leijinfu]
	SetKeyHandler(GB_WG_HandleKey, KEY_BACK, KEY_EVENT_UP);   // add [8/19/2011 Leijinfu]
	
	/////////////////
	GB_WG_pen_register_down_handler((GB_VOID*)GB_WG_HandlePenDown);
	GB_WG_pen_register_move_handler((GB_VOID*)GB_WG_HandlePenMove);
	GB_WG_pen_register_long_tap_handler((GB_VOID*)GB_WG_HandlePenLongTap);
	GB_WG_pen_register_up_handler((GB_VOID*)GB_WG_HandlePenUp);
	//////////////////////////////////////////////////////
	SetProtocolEventHandler(GB_WG_SelfMsg_CallBack, MSG_ID_GB_WG2_MSG);	
}


#define GB_CLEARKeyAllHandler(key)   ClearKeyHandler(key, KEY_EVENT_DOWN); \
									 ClearKeyHandler(key, KEY_EVENT_UP); \
									 ClearKeyHandler(key, KEY_LONG_PRESS)
#define GB_SetKeyAllHandler(key, f)  SetKeyHandler(f, key, KEY_EVENT_DOWN); \
									 SetKeyHandler(f, key, KEY_EVENT_UP);   \
									 SetKeyHandler(f, key, KEY_LONG_PRESS); 
void GB_WG_RegisterControlKeyHandle(void)
{
	GB_CLEARKeyAllHandler(KEY_RIGHT_ARROW);
	GB_CLEARKeyAllHandler(KEY_LEFT_ARROW);
	GB_CLEARKeyAllHandler(KEY_DOWN_ARROW);
	GB_CLEARKeyAllHandler(KEY_UP_ARROW);
	GB_CLEARKeyAllHandler(KEY_LSK);
	GB_CLEARKeyAllHandler(KEY_RSK);
	GB_CLEARKeyAllHandler(KEY_CSK);
	GB_CLEARKeyAllHandler(KEY_ENTER);
	GB_CLEARKeyAllHandler(KEY_CLEAR);

	GB_SetKeyAllHandler(KEY_RIGHT_ARROW, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_LEFT_ARROW, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_DOWN_ARROW, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_UP_ARROW, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_LSK, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_RSK, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_CSK, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_ENTER, GB_WG_HandleKey);
	GB_SetKeyAllHandler(KEY_CLEAR, GB_WG_HandleKey);
}

GB_VOID GB_WG_ExitApp(GB_VOID)
{
	GoBackHistory();
}


GB_VOID GB_WG_Screen_Exit(GB_VOID)
{
	GB_WG_Exit_Win();

// #ifdef __MMI_TOUCH_SCREEN__ //触摸屏清除手写层
// 	GB_WG_HandWrite_FreeNewLayer();
// #endif
	GB_WG_Handle_In_SSC();	
	GBWinManager_Free_InIdleScreen();
}

GB_VOID GB_VOIDGB_WG_Entry_Screen_ex(GB_VOID)
{
	
}

GB_VOID GB_WG_Entry_Screen(GB_VOID)
{
	/////调用进入函数了哈；
	GB_U8 *guiBuffer = GB_NULL;
	//	gdi_handle besLayout;
	////////////进入某个屏幕了哈；	
//	EntryNewScreen(GRP_GB_WINGUO_SCREEN, GB_WG_Screen_Exit, GB_WG_Entry_Screen, GB_NULL);
	mmi_frm_scrn_enter(GRP_GB_WINGUO_SCREEN, SCR_GB_WINGUO_SCREEN, GB_WG_Screen_Exit, GB_WG_Entry_Screen, MMI_FRM_FULL_SCRN);
    
    /* reset  global variable: cursor_force_stop */
    gui_inputs_register_cursor_callback();

	mmi_frm_event_set_switch_screen_flag(0);
	//	gdi_layer_get_active(&besLayout);

	// #ifdef __MMI_TOUCH_SCREEN__ //触摸屏创建手写层
	// 	GB_WG_HandWrite_CreateNewLayer(besLayout);
	// #endif

	//guiBuffer = (GB_U8*)GetCurrGuiBuffer(SCR_GB_WINGUO_SCREEN);	//test scf 20120424	
	entry_full_screen();
	// 窗口入口
	{
		GB_WG_ENTRYFUN pEntryFun = (GB_WG_ENTRYFUN)GB_WG_APP_GetEntryFun();
		if (pEntryFun)
		{
			pEntryFun();
			gui_sse_setup_scenario(GUI_SSE_SCENARIO_NONE);
		}
	}
}
mmi_ret GB_WG_GroupScreenProc(mmi_event_struct *evt);
extern GB_VOID GB_WG_Entry_WinguoWin(GB_VOID);
/*extern GB_VOID GB_WG_Entry_SMSWin(GB_VOID);*/

// 直接进入winguo的接口
GB_VOID GB_WG_Entry_Winguo(GB_VOID)
{
	if(!GB_WG_Is_In_Winguo())
	{
		mmi_frm_group_create(GRP_ID_ROOT, GRP_GB_WINGUO_SCREEN, GB_WG_GroupScreenProc, NULL);
		mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		GB_WG_Init();
		GB_WG_APP_SetEntryFun(GB_WG_Entry_WinguoWin);
		GB_WG_Entry_Screen();
	}
	else
	{
		GB_WG_Entry_WinguoWin();
	}
}

//extern GB_BOOL GB_WG_Winguo_Init_InputBox(GB_U16 *inputString);

//extern GB_VOID WinguoWin_GB_WG_SMD_AccessUrl(GB_U16 *inputString);
//GB_VOID GB_WG_Entry_Winguo_ext(unsigned short *inputstr)
//{
//	GB_WG_BEGIN_DRAW();
//	GB_WG_Entry_Winguo();
//	GB_WG_Winguo_Init_InputBox(inputstr);
//	GB_WG_END_DRAW();
//}

// 直接进入winguo短信的接口
// GB_VOID GB_WG_Entry_SMS(GB_VOID)
// {
// 	GB_WG_Init();
// 	GB_WG_APP_SetEntryFun(GB_WG_Entry_SMSWin);
// 	GB_WG_Entry_Screen();
// }

#include"imui.h"
GB_VOID GB_WG_Entry(GB_U16 Keycode, GB_U16 Keytype)
{
	GB_WG_Init();
	GB_WG_APP_SetEntryFun(GB_WG_Entry_Win);
	GB_WG_Entry_Screen();
	if(Keycode != KEY_INVALID)
	{
		GB_WG_SetPhoneNumInputmod();
		mmi_imc_key_group_key_down_int(Keycode, KEY_EVENT_DOWN);
	}
}


typedef struct _GB_WG_msg_sturct_sys_
{
	LOCAL_PARA_HDR
		GB_WG_msg_sturct msg;
}GB_WG_msg_sturct_sys;

GB_VOID GB_WG_send_msg(GB_INT MSG_ID, GB_VOID *Param)
{
	ilm_struct *send_ilm;
	GB_WG_msg_sturct_sys *local_para = construct_local_para(sizeof(GB_WG_msg_sturct_sys), TD_CTRL);
	if (!local_para)
	{
		return;
	}
	local_para->msg.msg_ID = MSG_ID;
	local_para->msg.parma = Param;
	send_ilm = allocate_ilm(MOD_MMI);
	send_ilm->src_mod_id = MOD_MMI;
	send_ilm->dest_mod_id = MOD_MMI;
	send_ilm->local_para_ptr = (local_para_struct *)local_para;
	send_ilm->peer_buff_ptr = NULL;
	send_ilm->msg_id = MSG_ID_GB_WG2_MSG;
	send_ilm->sap_id = MOD_MMI;
	msg_send_ext_queue(send_ilm);
}

GB_VOID GB_WG_GotoIdleScreen(GB_VOID)
{
#if defined(__COSMOS_MMI_PACKAGE__) && !defined(GB_MTK_11B6255)
	mmi_idle_display(); 
#else
	mmi_idle_display();
#endif
}

GB_VOID GB_WG_SelfMsg_CallBack(GB_VOID * pData)
{
	GB_WG_msg_sturct *pmsg = NULL;
	if (pData)
	{
		pmsg = (&((GB_WG_msg_sturct_sys*)pData)->msg);
	}
	GB_WG_Msg_Handle(pmsg);
}

// 在系统页面进入我们的winguo页面 [5/30/2011 scf]
GB_VOID GB_WG_mmi_entry_Winguo_highlight_hdlr(GB_VOID)
{    
    SetLeftSoftkeyFunction(GB_WG_Entry_Winguo, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(GB_WG_Entry_Winguo, KEY_EVENT_UP);
}


//extern void GB_WG_show_handwriting_by_point_data(mmi_pen_point_struct* pPointData, U32 nPointCount);
// 判断进入winguo还是smartdial [5/15/2012 liangchuanhui]
// static GB_BOOL GB_WG_IS_WIDGET = GB_FALSE;
// GB_BOOL GB_WG_IS_Widget(GB_VOID)
// {
// 	return GB_WG_IS_WIDGET;
// }
// static GB_BOOL GB_WG_IS_INPUTDATA = GB_FALSE;
// GB_BOOL GB_WG_IS_InputData(GB_VOID)
// {
// 	return GB_WG_IS_INPUTDATA;
// }

#ifndef GBUSE_ASM_MEM
MMI_ID vapp_winguo_launch(void* args, U32 argSize)
{
	GB_POINT* pPointData = (GB_POINT*)args;
	GB_UINT nPointCount = (GB_UINT)argSize;
	GB_POINT *tempArry = GB_NULL;
	if (pPointData && nPointCount)
	{
		tempArry = (GB_POINT*)GB_WG_Malloc(nPointCount * sizeof(*pPointData));
		if (tempArry)
		{
			GB_MEMCPY(tempArry, pPointData, nPointCount * sizeof(*pPointData));
		}
		//标记有手写数据 [5/29/2012 liangchuanhui]
		//GB_WG_IS_INPUTDATA = GB_TRUE;
		GB_WG_R_SetVKDefaltShow(GB_TRUE);  //显示虚拟键盘
	}//  [5/29/2012 liangchuanhui]
	else
	{
		GB_WG_R_SetVKDefaltShow(GB_FALSE);  //不显示虚拟键盘
		// GB_WG_IS_INPUTDATA = GB_FALSE;
	}

	// 从手写进nPointCount,就算没有数据，也被设置成了1 [5/15/2012 liangchuanhui]
// 	if (!nPointCount && GB_WG_Get_isVirtual_key())
// 	{
//        GB_WG_WinguoSearchScreen();
// 	   return MMI_RET_OK;
// 	}

	GB_WG_GroupScreenCreat(KEY_INVALID, 0);
	if (tempArry)
	{
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
#ifdef __MMI_TOUCH_SCREEN__
		//GB_WG_show_handwriting_by_point_data((mmi_pen_point_struct*)tempArry, nPointCount); // bu yyk
#endif
#endif

		GB_WG_Free(tempArry);
		tempArry = GB_NULL;
	}
	return MMI_RET_OK;
}


#else

#ifdef __WINGUO_USE_ASM_2_0__ // Use ASM2.0 after 1224MP, Use Asm1.0 in1132SP.

void vapp_winguo_launch(void* args, U32 argSize)
{

	mmi_frm_app_launch(APP_GB_WINGUO,0,0,mmi_winguo_register_proc,NULL,MMI_FRM_APP_SKIP_PREPARE);
}

MMI_RET mmi_winguo_register_proc(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID app_id =	GET_APP_ID(evt);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
		{
			mmi_event_struct event;
			MMI_FRM_INIT_EVENT(&event, 0);
			MMI_FRM_POST_EVENT(&event, vapp_winguo_launch_int, NULL);
			break;
		}

		case EVT_ID_APP_TOP_ACTIVE:
		{
			break;
		}

		case EVT_ID_APP_TOP_INACTIVE:
			
			break;

		case EVT_ID_APP_DEINIT:
			mmi_winguo_app_exit();
			break;
	}
	return MMI_RET_OK;

}


MMI_ID vapp_winguo_launch_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_winguo_app_memory_prepare();
	GB_WG_R_SetVKDefaltShow(GB_TRUE);
	GB_WG_GroupScreenCreat(KEY_INVALID, 0);
	return MMI_RET_OK;
}

void mmi_winguo_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_winguo_app_memory_unprepare();
}


void mmi_winguo_app_memory_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   if (g_GB_wg_Memory_Pool == NULL)
    {
	    g_GB_wg_Memory_Pool = mmi_frm_asm_alloc_r(APP_GB_WINGUO, APPMEM_WINGUO_MEM_POLL_SIZE);
    }

    MMI_ASSERT(g_GB_wg_Memory_Pool!=NULL);
    kal_mem_set(g_GB_wg_Memory_Pool, 0, APPMEM_WINGUO_MEM_POLL_SIZE);

    g_GBwgMemPoolID = kal_adm_create(g_GB_wg_Memory_Pool, APPMEM_WINGUO_MEM_POLL_SIZE, NULL, KAL_FALSE);
    MMI_ASSERT(g_GBwgMemPoolID != NULL);    
}

void mmi_winguo_app_memory_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_GBwgMemPoolID)
    {
        kal_adm_delete(g_GBwgMemPoolID);
        g_GBwgMemPoolID = NULL;
    }

    if (g_GB_wg_Memory_Pool != NULL)
    {
        mmi_frm_asm_free_r(APP_GB_WINGUO, g_GB_wg_Memory_Pool);
        g_GB_wg_Memory_Pool = NULL;
    }    
}

#else //use ASM1.0

void vapp_winguo_launch(void* args, U32 argSize)
{

    GB_WG_R_SetVKDefaltShow(GB_TRUE);
    GB_WG_GroupScreenCreat(KEY_INVALID, 0);
	if (!mmi_winguo_memory_prepare())
	{
		mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);
		return;
	}

	GB_WG_Entry(KEY_INVALID,0);
}

//stop callback
void mmi_winguo_asm_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_GB_WINGUO_SCREEN);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_GB_WINGUO, KAL_TRUE);
}

//success callback
void mmi_winguo_alloc_mem_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_winguo_launch(NULL,0);
}

MMI_BOOL mmi_winguo_is_asm_enough()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 memory_size;
    void *memory_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Memory size */
    memory_size = APPMEM_WINGUO_MEM_POLL_SIZE;

    /* application registeration & stop callback */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_GB_WINGUO, STR_GB_WINGUO_SMARTSEARCH, IMG_WG_WINGUO_NATIVE_ICON, mmi_winguo_asm_stop_cb);

    /* allocate memory */
    memory_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_GB_WINGUO, memory_size);
    if (memory_ptr == NULL)
    {
        /* register callback */
        mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_GB_WINGUO, 0, memory_size, mmi_winguo_alloc_mem_cb);
        return MMI_FALSE;
    }
    else
    {
        applib_mem_ap_free(memory_ptr);
    }

    return MMI_TRUE;
}

MMI_BOOL mmi_winguo_memory_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_winguo_is_asm_enough())
    {
        return MMI_FALSE;
    }

    /* application registeration & stop callback */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_GB_WINGUO, STR_GB_WINGUO_SMARTSEARCH, IMG_WG_WINGUO_NATIVE_ICON, mmi_winguo_asm_stop_cb);

    /* allocate memory */
     if (g_GB_wg_Memory_Pool == NULL)
     {
         g_GB_wg_Memory_Pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_GB_WINGUO, APPMEM_WINGUO_MEM_POLL_SIZE);

         if (g_GB_wg_Memory_Pool == NULL)
         {
             /* register callback */
			 mmi_frm_appmem_prompt_to_release_mem(
             APPLIB_MEM_AP_ID_GB_WINGUO,
             0,
             APPMEM_WINGUO_MEM_POLL_SIZE,
             mmi_winguo_alloc_mem_cb);

             return MMI_FALSE;
         }
    }
    kal_mem_set(g_GB_wg_Memory_Pool, 0, APPMEM_WINGUO_MEM_POLL_SIZE);

    g_GBwgMemPoolID = kal_adm_create(g_GB_wg_Memory_Pool, APPMEM_WINGUO_MEM_POLL_SIZE, NULL, KAL_FALSE);
    MMI_ASSERT(g_GBwgMemPoolID != NULL);  
	
	return MMI_TRUE;
}


void mmi_winguo_memory_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_GBwgMemPoolID)
    {
        kal_adm_delete(g_GBwgMemPoolID);
        g_GBwgMemPoolID = NULL;
    }

    if (g_GB_wg_Memory_Pool != NULL)
    {
        applib_mem_ap_free(g_GB_wg_Memory_Pool);
        g_GB_wg_Memory_Pool = NULL;
    }    
}
#endif /*#ifdef __WINGUO_USE_ASM_2_0_ */

#endif /*#ifndef GBUSE_ASM_MEM */
//////////////////////////////////////////////////////////////////////////

// 使用 group


mmi_ret GB_WG_GroupScreenProc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	case EVT_ID_GROUP_DEINIT:
		GB_WG_FreeWin();
#ifdef __WINGUO_USE_ASM_1_0__
		mmi_winguo_memory_unprepare();
#endif
		break;
	}
	return MMI_RET_OK;
}

#ifndef GBUSE_ASM_MEM
GB_VOID GB_WG_GroupScreenCreat(GB_U16 Keycode, GB_U16 Keytype)
{
	if (GB_WG_WinManagerIsFree())
	{
		// 屏幕进入设为1，物理键盘进入设置为0，代替宏GBWG_VIRTUAL_KEY [6/2/2012 liangchuanhui]
		if(Keycode == KEY_INVALID)
		{
			GB_WG_Set_isVirtual_key(GB_TRUE);
		}
		else
		{
			GB_WG_Set_isVirtual_key(GB_FALSE);
		}
		mmi_frm_group_create(GRP_ID_ROOT, GRP_GB_WINGUO_SCREEN, GB_WG_GroupScreenProc, NULL);
		mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		GB_WG_Entry(Keycode, Keytype);
	}	
}

#else
#ifdef __WINGUO_USE_ASM_2_0__
GB_VOID GB_WG_GroupScreenCreat(GB_U16 Keycode, GB_U16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (GB_WG_WinManagerIsFree())
	{
		// 屏幕进入设为1，物理键盘进入设置为0，代替宏GBWG_VIRTUAL_KEY [6/2/2012 liangchuanhui]
		if(Keycode == KEY_INVALID)
		{
			GB_WG_Set_isVirtual_key(GB_TRUE);
		}
		else
		{
			GB_WG_Set_isVirtual_key(GB_FALSE);
		}
		mmi_frm_group_create(APP_GB_WINGUO, GRP_GB_WINGUO_SCREEN, GB_WG_GroupScreenProc, NULL);
		mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		GB_WG_Entry(Keycode, Keytype);
	}	
}
#else //use Asm 1.0
GB_VOID GB_WG_GroupScreenCreat(GB_U16 Keycode, GB_U16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (GB_WG_WinManagerIsFree())
	{
		// 屏幕进入设为1，物理键盘进入设置为0，代替宏GBWG_VIRTUAL_KEY [6/2/2012 liangchuanhui]
		if(Keycode == KEY_INVALID)
		{
			GB_WG_Set_isVirtual_key(GB_TRUE);
		}
		else
		{
			GB_WG_Set_isVirtual_key(GB_FALSE);
		}
		mmi_frm_group_create(GRP_ID_ROOT, GRP_GB_WINGUO_SCREEN, GB_WG_GroupScreenProc, NULL);
		mmi_frm_group_enter(GRP_GB_WINGUO_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	}	
}

#endif /* #ifdef __WINGUO_USE_ASM_2_0_ */

#endif /* #ifndef GBUSE_ASM_MEM */
GB_VOID GB_WG_ReDrawScreen(GB_Rect *RedrawRect)
{
	GB_WG_DrawScreen(RedrawRect);
//	GB_WG_WinguoWidgetInvalidate(RedrawRect);
}

#endif /* #ifdef __MMI_GB_WINGUO__ */




