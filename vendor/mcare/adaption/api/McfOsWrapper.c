#pragma diag_remark 188
#pragma diag_remark 223
#pragma diag_remark 167
#pragma diag_remark 513
#pragma diag_remark 940
#pragma diag_remark 111
#pragma diag_remark 177
#pragma diag_remark 550
#pragma diag_remark 186

#ifdef __MCAREV31__
#include "MAdpConfig.h"
#include "McfPlatform.h"
#include "McfWrapper.h"
#include "McfCommon.h"
#include "McfAudio.h"
#include "McfEditor.h"
#include "McfIdle.h"
#include "McfKey.h"
#include "McfMemory.h"
#include "McfMisc.h"
#include "McfPen.h"
#include "McfSys.h"
#include "McfSim.h"
#include "McfSms.h"
#include "McfStdLib.h"
#include "McfTelephone.h"
#include "McfTime.h"
#include "McfTrace.h"
#include "McfUcs2.h"
#include "McfUsb.h"
#include "McfVibrate.h"
#include "McfDtcnt.h"
#include "McfChset.h"
#include "McfBrowser.h"
#include "McfFs.h"

#include "McfZlib.h"

#include "MAdpMenuDef.h"


#if MCR_MTK_VER < MTK_VER_1032 //add by purple
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "nwinfosrvgprot.h"
#include "simctrlsrvgprot.h"
#include "ProfilesAppGprot.h"
#endif
#if (MCR_MTK_VER>=MTK_VER_828)
#include "ImeGprot.h"
#endif
#if MCR_MTK_VER < MTK_VER_1032
#include "MTPNP_AD_master_header.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1132 //by rico 1144

#else
#if MCR_MTK_VER >= MTK_VER_1108
#include "MTPNP_AD_master_if.h"
#endif
#endif

#if MCR_MTK_VER >= MTK_VER_1132  //purple
extern MMI_ID mmi_frm_group_create (MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data);
extern MMI_ID mmi_frm_group_enter (MMI_ID group_id, mmi_group_enter_flag flag);
extern MMI_BOOL mmi_frm_scrn_enter (MMI_ID parent_id, MMI_ID scrn_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_scrn_type_enum scrn_type);
extern void mmi_frm_scrn_close_active_id (void);
extern  U8* mmi_frm_scrn_get_active_gui_buf (void);
extern MMI_ID mmi_frm_group_get_active_id(void);
extern mmi_ret mmi_frm_scrn_close (MMI_ID parent_id, MMI_ID scrn_id);
extern mmi_ret mmi_frm_scrn_set_leave_proc (MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc);
extern void mmi_frm_display_desktop(void);//by charmenli 2012-6-8

MMI_ID McfGroupIdCreate(MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data)
{      
        return mmi_frm_group_create(parent_id, group_id, proc,user_data);
}

MMI_ID McfGroupIdEnter (MMI_ID group_id, mmi_group_enter_flag flag)
{
        return mmi_frm_group_enter(group_id, flag);
}

MBOOL McfScrnEnter (MMI_ID parent_id, MMI_ID scrn_id, FuncPtr exit_proc, FuncPtr entry_proc)
{
        return (MBOOL)mmi_frm_scrn_enter(parent_id, scrn_id,exit_proc,entry_proc,MMI_FRM_FULL_SCRN);
}

MVOID McfScrnDisplayDesktop(MVOID) //add by charmenli 2012-6-11
{
	mmi_frm_display_desktop();
}

void McfScrnCloseActiveId(void)
{
        mmi_frm_scrn_close_active_id();
}

MMI_RET McfScrnCloseById(MMI_ID parent_id, MMI_ID scrn_id)
{
         return mmi_frm_scrn_close (parent_id, scrn_id);
}

U8* McfScrnGetActiveGuiBuff (void)
{
        return mmi_frm_scrn_get_active_gui_buf();
}

MMI_ID McfGetActiveGroupId(void)
{
        return mmi_frm_group_get_active_id();
}

MMI_RET McfGroupCreateProc(mmi_event_struct* param)
{
    switch(param->evt_id)
    {
        //创建一个mcare group的时候,在进入这个group的时候会激发这里的case
        case EVT_ID_GROUP_ENTER:
			
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
		break;
        case EVT_ID_GROUP_DEINIT:
		//maomaolin add
		mmi_frm_group_close( GRP_ID_MCARE_LIST );
		//mmi_frm_app_close(APP_TENCENT_MCARE);
		//McfSys_DeInit()
		//MKernPool_DestroyPool();    
		//McfMem_Deinit();
		
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

//设置删除指定屏幕的回调函数
MMI_RET McfSetDelScrCallBackFunc(MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc)
{
        return  mmi_frm_scrn_set_leave_proc(parent_id, scrn_id, proc);
}

//清除删除指定屏幕的回调函数
MMI_RET McfClearDelScrCallBackFunc(MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc)
{
        return  mmi_frm_scrn_set_leave_proc(parent_id, scrn_id, NULL);
}
#endif
extern kal_int32 in_mcare;
MVOID McfGoBackHistory(MVOID) //by purple
{
#if MCR_MTK_VER >= MTK_VER_1132
        McfScrnCloseActiveId();
#else
        GoBackHistory();
#endif
}

MVOID McfGoBackHistory2(MVOID) //by purple
{
#if MCR_MTK_VER >= MTK_VER_1132
        McfScrnCloseActiveId();
        in_mcare = 0;
#else
        GoBackHistory();
#endif
}

#ifdef MCR_MEM_DEBUG
extern MVOID* MKernPool_MallocDebug(MUINT nMemSize, MCHAR *pFileName, MINT nLineNo);
extern MVOID MKernPool_FreeDebug(MVOID* pMem, MCHAR *pFileName, MINT nLineNo);
#define MKernPool_Malloc(nSize)     MKernPool_MallocDebug(nSize,__FILE__,__LINE__)
#define MKernPool_Free(pBuffer)     MKernPool_FreeDebug(pBuffer,__FILE__,__LINE__)
#else
extern MVOID* MKernPool_Malloc(MUINT nMemSize);
extern MVOID MKernPool_Free(MVOID* pMem);
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#if MCR_MTK_VER < MTK_VER_1108
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif	

MUINT McfGetMcrModId(MVOID)
{
    return (MUINT)MOD_MMI;
}

MUINT McfGetNetModId(MVOID)   
{
#ifdef __MCARE_SEPERATE_NET_TASK__
    return (MUINT)MOD_MCARE;
#else//
    return (MUINT)MOD_MMI;
#endif//
}



MVOID McfPhbNotifyCallback(MVOID)
{//TODOLITE
}

/*=================================  GDI =====================================*/

const MBYTE MADP_SMALL_FONT = SMALL_FONT;
const MBYTE MADP_MEDIUM_FONT = MEDIUM_FONT;
const MBYTE MADP_LARGE_FONT  = LARGE_FONT;
const MBYTE MADP_GRADIENT_RECT_HOR = GDI_GRADIENT_RECT_HOR;
const MBYTE MADP_GRADIENT_RECT_VER = GDI_GRADIENT_RECT_VER;

#if(MCR_MTK_VER >= MTK_VER_952)	
extern color UI_get_text_color(void);
#endif


#if (MCR_MTK_VER < MTK_VER_652)
#define MCR_PIXTEL_UI_XXX
#else
#define MCR_GUI_XXX
#endif


MINT McfGdi_GetScrWidth(MVOID)
{//MAIN_LCD_DEVICE_WIDTH
	MINT nWidth = 0;
	MINT nHeight = 0;
	gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
	gdi_lcd_get_dimension(&nWidth, &nHeight);
	return (MUSHORT)nWidth;
}

MINT McfGdi_GetScrHeight(MVOID)
{//MAIN_LCD_DEVICE_HEIGHT
	MINT nWidth = 0;
	MINT nHeight = 0;
	gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
	gdi_lcd_get_dimension(&nWidth, &nHeight);
	return (MUSHORT)nHeight;
}

#if MCR_MTK_VER >= MTK_VER_1210 //purple for in screen edit
MVOID McfEditor_Set_Clip(MVOID);
MVOID McfEditor_Reset_Clip(MVOID);
MBYTE active_flag = 0;
#endif

MVOID McfGdi_BeginDraw(MVOID)
{
	MINT nBaseLayerHandle;
	
#if MCR_MTK_VER >= MTK_VER_1032 //by purple
        mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
#endif
	gdi_layer_get_base_handle((gdi_handle*)&nBaseLayerHandle);
	gdi_layer_set_active(nBaseLayerHandle);

#if MCR_MTK_VER >= MTK_VER_1210 //purple for in screen edit
    if( 1 == active_flag )
    {
        McfEditor_Set_Clip();
    }
    else
    {
        McfEditor_Reset_Clip();
    }
#endif	

#ifndef UI_DOUBLE_BUFFER_SUPPORT
	gui_lock_double_buffer();
#else
	gdi_layer_lock_frame_buffer(); 
	gdi_layer_set_source_key(MTRUE, gdi_act_color_from_rgb(255, 255, 0, 255));
#endif
}

#ifdef MCR_MEM_MONITOR
void McfMonitorMemoryInfo(void)
{
	MUINT nTotal,nUsed;
	MINT nWidth,nHeight,nSW;
	MWCHAR text[64];
	
    McfMemDebug_ReportMemPoolInfo(&nTotal,&nUsed);
    McfGdi_SetTextColor(0xff,0,0);
    kal_wsprintf(text, "Total:%d", nTotal); 
    nSW = McfGdi_GetScrWidth();
    McfGdi_GetTextWidthHeight(text,&nWidth,&nHeight);
    McfGdi_DrawText(nSW-nWidth,0,text);    
    kal_wsprintf(text, "Used:%d",nUsed); 
    McfGdi_GetTextWidthHeight(text,&nWidth,&nHeight);
    McfGdi_DrawText(nSW-nWidth,nHeight+4,text);    
}
#endif

MVOID McfGdi_EndDraw(MVOID)
{
	MINT nBaseLayerHandle;
	
    #ifdef MCR_MEM_MONITOR
    McfMonitorMemoryInfo();
    #endif
	gdi_layer_get_base_handle((gdi_handle*)&nBaseLayerHandle);
#ifndef UI_DOUBLE_BUFFER_SUPPORT
	gui_unlock_double_buffer();
	gui_BLT_double_buffer(0, 0, McfGdi_GetScrWidth(), McfGdi_GetScrHeight());
#else
	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt(nBaseLayerHandle, 0, 0, 0, 0, 0, McfGdi_GetScrWidth(), McfGdi_GetScrHeight());
#endif	

}

MINT McfGdi_GetCharWidth(MVOID)
{
	MINT nRet = 0;

#ifdef MCR_PIXTEL_UI_XXX
	nRet = (MUSHORT)pixtel_UI_get_character_width();
#else
	nRet = (MUSHORT)gui_get_character_width('V');
#endif

	return nRet;
}


MINT McfGdi_GetCharHeight(MVOID)
{
	MINT ret = 0;

#ifdef MCR_PIXTEL_UI_XXX
	ret = (MUSHORT)pixtel_UI_get_character_height();
#else
	ret = (MUSHORT)gui_get_character_height();
#endif

	return ret;
}

MVOID McfGetCurrTextColor(MBYTE *pR, MBYTE *pG, MBYTE *pB)
{
	color textColor;
	{
#if (MCR_MTK_VER >= MTK_VER_932)
		extern color UI_get_text_color(void);
		textColor = UI_get_text_color();
#else
		extern color UI_current_text_color;
		textColor = UI_current_text_color;
#endif
	}

	*pR = textColor.r;
	*pG = textColor.g;
	*pB = textColor.b;
}

MVOID McfSetTextColor( MBYTE r, MBYTE g, MBYTE b)
{
	color c;
	//c =UI_color(r,g,b);
	c.r = r;
	c.b = b;
	c.g = g;
	c.alpha = 100;

#ifdef MCR_PIXTEL_UI_XXX 
	pixtel_UI_set_text_color(c);
#else
	gui_set_text_color(c);
#endif
}
MVOID McfGuiSetFont(MBYTE nFontSize,MBYTE nBold,MBYTE nItalic,MBYTE nUnderline);
MVOID McfGuiMeasureString(const MWCHAR *pcwszStr,MINT nLen,MINT *pWidth,MINT *pHeight)
{
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_fe_get_string_info_param_struct query;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	#if (MCR_MTK_VER >= MTK_VER_1210) //by rico 1144
    McfGuiSetFont(MADP_MEDIUM_FONT,0,0,0);  //add by purple 1112 cosmos   
    #endif
	memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
	query.String = (U8*)pcwszStr;
	query.n = nLen;
	query.enableTruncated = MMI_FALSE;
	query.w = 0;
	mmi_fe_get_string_widthheight(&query);

	*pWidth = query.adv_w;
	*pHeight = query.adv_h;
#else
	gui_measure_string_n((UI_string_type)pcwszStr, nLen, pWidth, pHeight);
#endif
}
#ifdef __MMI_VECTOR_FONT_SUPPORT__
S32 __QueryBaseline(const MWCHAR *pcwszStr,MINT nLen)
{
	mmi_fe_get_string_info_param_struct query;

	query.String = (U8*)pcwszStr;
	query.n = nLen;
	query.enableTruncated = MMI_FALSE;
	query.w = 0;

	mmi_fe_get_string_widthheight(&query);	
	return query.baseline;
}
#endif

static MINT gbaseline =-1;
static MINT glastfontsz = -1;
MVOID McfGuiPrintText(MINT nX, MINT nY,const MWCHAR*pcwszStr,MINT nLen)
{
	if(nLen >0)
	{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
		gui_move_text_cursor(nX, nY);
		gui_print_text_n((UI_string_type)pcwszStr,nLen);
#endif
	}
}



MVOID McfGuiSetFont(MBYTE nFontSize,MBYTE nBold,MBYTE nItalic,MBYTE nUnderline)
{
	stFontAttribute sFontAttr={0};
	#if (MCR_MTK_VER == MTK_VER_1210 ) //by rico 1144
	sFontAttr.size = (MBYTE)MADP_MEDIUM_FONT; //nFontSize; 
	#else
	sFontAttr.size = nFontSize; //nFontSize; 
	#endif
	sFontAttr.bold = nBold;
	sFontAttr.italic = nItalic;
	sFontAttr.underline = nUnderline;

#ifdef MCR_PIXTEL_UI_XXX
	pixtel_UI_set_font((stFontAttribute *)(&sFontAttr));
#else
	gui_set_font((stFontAttribute *)(&sFontAttr));
#endif
    if(glastfontsz != sFontAttr.size)
    {
        gbaseline = -1;
    }
    glastfontsz = sFontAttr.size;
}


MBOOL McfGdi_IsTouchScreen(MVOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	return MTRUE;
#else
	return MFALSE;
#endif	
}

MVOID McfGdi_DisplayWarnning(MWCHAR *pMessage)
{
#ifdef __COSMOS_MMI_PACKAGE__
    #ifdef __MMI_VUI_ENGINE__ //MTK.mtk01963
    vapp_mcare_display_warning((WCHAR*)pMessage);
    #endif // MTK.mtk01963
#else
	ClearAllKeyHandler();
	DisplayConfirm(0,0, STR_GLOBAL_BACK,0, (UI_string_type)pMessage,IMG_GLOBAL_INFO, 0);
	SetRightSoftkeyFunction(McfGoBackHistory2, KEY_EVENT_DOWN);	//by purple
#endif
	mmi_frm_app_close(APP_TENCENT_MCARE);
}
MVOID McfGdi_DisplayPopupCallback(MVOID)
{
    in_mcare = 0;
}

MVOID McfGdi_DisplayPopUp(MWCHAR *pMessage, MINT nTime)
{
#ifdef __COSMOS_MMI_PACKAGE__
    #ifdef __MMI_VUI_ENGINE__ //MTK.mtk01963
    vapp_mcare_display_popup((WCHAR*)pMessage);
    #endif // MTK.mtk01963
#else
	DisplayPopupCallBack((U8*)pMessage, 0, 0, nTime, 0, McfGdi_DisplayPopupCallback);
#endif
	mmi_frm_app_close(APP_TENCENT_MCARE);
}

MVOID McfGdi_StopDisplayPopUp(MVOID)
{
#ifdef __MMI_SCREEN_ROTATE__ //by purple
	//ExitDisplayPopup();//by  rico  1144
#endif	
}


/*=================================  SOCKET ==================================*/

const MINT MADP_SOC_SUCCESS =    SOC_SUCCESS;
const MINT MADP_SOC_ERROR   =   SOC_ERROR;
const MINT MADP_SOC_WOULDBLOCK  =   SOC_WOULDBLOCK;
const MINT MADP_SOC_INVALID_SOCK =   SOC_INVALID_SOCKET;

#if (MCR_MTK_VER < MTK_VER_828)
const MINT MADP_SOC_STREAM  =  SOCK_STREAM;
#else
const MINT MADP_SOC_STREAM  =  SOC_SOCK_STREAM;
#endif

#if (MCR_MTK_VER < MTK_VER_828)
const MINT MADP_SOC_DGRAM =   SOCK_DGRAM;
#else
const MINT MADP_SOC_DGRAM  =  SOC_SOCK_DGRAM;
#endif

#if (MCR_MTK_VER < MTK_VER_828)
const MINT MADP_SOC_SMS  =  SOCK_SMS;
#else
const MINT MADP_SOC_SMS  =  SOC_SOCK_SMS;
#endif

#if (MCR_MTK_VER < MTK_VER_828)
const MINT MADP_SOC_RAW =   SOCK_RAW;
#else
const MINT MADP_SOC_RAW =   SOC_SOCK_RAW;
#endif

#if (MCR_MTK_VER < MTK_VER_828)
const MINT MADP_PF_INET =   PF_INET;
#else
const MINT MADP_PF_INET  =  SOC_PF_INET;
#endif

const MINT MADP_SOC_NBIO =  SOC_NBIO;
const MINT MADP_SOC_ASYNC = SOC_ASYNC;

const MINT MADP_SOC_READ   =    SOC_READ;
const MINT MADP_SOC_WRITE  =    SOC_WRITE;
const MINT MADP_SOC_ACCEPT =    SOC_ACCEPT;
const MINT MADP_SOC_CONNECT =    SOC_CONNECT;
const MINT MADP_SOC_CLOSE   =   SOC_CLOSE;


extern MVOID __McfHandleSocNotify(MINT socHd, MINT evtType, MINT result);
extern MVOID __McfHandleDnsNotify(MINT requestId,MBOOL result,MINT*pIpEntrys,MINT entryCnt);

MINT McfSocConnect(MINT socHd,const MINT addr,MUSHORT port)
{//connet by ip address
	MINT ret;
	sockaddr_struct sockaddr;

	memset(&sockaddr,0,sizeof(sockaddr));
	memcpy(sockaddr.addr, &addr, 4);
	sockaddr.addr_len = 4;
	sockaddr.port = port;
	sockaddr.sock_type = MADP_SOC_STREAM;	
	ret = soc_connect((kal_int8)socHd, &sockaddr);
	return ret;
}

MINT McfHandleSocNotify(MVOID *pInfo)
{
	app_soc_notify_ind_struct *pNotify = (app_soc_notify_ind_struct*)pInfo;
	if(pNotify == MNULL || !MCR_IsRunning())
	{
		return 0;
	}
	__McfHandleSocNotify(pNotify->socket_id, pNotify->event_type, pNotify->result);

	MCR_HandleDelayedWork();
	return 0;
}

MINT McfHandleDnsNotify(MVOID *pInfo)
{
	app_soc_get_host_by_name_ind_struct *pNotify = (app_soc_get_host_by_name_ind_struct*)pInfo;
	MINT ipEntry[SOC_MAX_A_ENTRY];

	MCFSOC_TRACE(__MCR_FUNCTION__" entry"); 

	if(pNotify == MNULL || !MCR_IsRunning())
	{
		return 0;
	}
	memcpy(ipEntry,pNotify->entry,SOC_MAX_A_ENTRY*sizeof(MINT));//type ..crash fix...arlo
	__McfHandleDnsNotify(pNotify->request_id,pNotify->result,ipEntry,pNotify->num_entry);

	MCR_HandleDelayedWork();

	MCFSOC_TRACE(__MCR_FUNCTION__" Leave"); 
	
	return 0;
}





//======================Socket Task====================

MVOID McfPostMessage(MUINT src,MUINT dst,MUINT msgId, McfLocalParam* pLocalParam)
{
	MYQUEUE Message;

	Message.oslSrcId = src;
	Message.oslDestId = dst;
	Message.oslMsgId = msgId;

	Message.oslDataPtr = (oslParaType *)pLocalParam;
	Message.oslPeerBuffPtr = MNULL;
	OslMsgSendExtQueue(&Message);	
}


MVOID __set_protocol_event_handler(_fPsFuncPtr funcPtr, MUSHORT eventID, MUINT isMultiHandler)
{
#if (MCR_MTK_VER >= MTK_VER_916)
	mmi_frm_set_protocol_event_handler((U16)eventID, (PsIntFuncPtr)funcPtr, (MMI_BOOL)isMultiHandler);
#elif (MCR_MTK_VER > MTK_VER_832)
	mmi_frm_set_protocol_event_handler((U16)eventID, (PsFuncPtr)funcPtr, (MMI_BOOL)isMultiHandler);
#else
	mmi_frm_set_protocol_event_handler((PsFuncPtr)funcPtr, (U16)eventID);
#endif
}

MVOID __clear_protocol_event_handler(MUSHORT eventID, _fPsFuncPtr funcPtr)
{
#if (MCR_MTK_VER>=MTK_VER_916)
	mmi_frm_clear_protocol_event_handler((U16)eventID, (PsIntFuncPtr)funcPtr);
#elif (MCR_MTK_VER > MTK_VER_832)
	mmi_frm_clear_protocol_event_handler((U16)eventID, (PsFuncPtr)funcPtr);
#else
	mmi_frm_clear_protocol_event_handler((U16)eventID);
#endif

} 
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#if MCR_MTK_VER >=MTK_VER_1032
  #ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
/* under construction !*/
  #else
/* under construction !*/
  #endif
#elif (MCR_MTK_VER == MTK_VER_1012) || (MCR_MTK_VER == MTK_VER_936) ||(MCR_MTK_VER == MTK_VER_952)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if MCR_MTK_VER >= MTK_VER_1032
    #ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
/* under construction !*/
    #else
/* under construction !*/
    #endif
#elif (MCR_MTK_VER == MTK_VER_1012) || (MCR_MTK_VER == MTK_VER_936) ||(MCR_MTK_VER == MTK_VER_952)
/* under construction !*/
#elif MCR_MTK_VER > MTK_VER_816
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif


#ifdef __MCARE_SEPERATE_NET_TASK__

static MVOID McfSocket_TaskMessageHandler(ilm_struct *ilm_ptr);

static MVOID McfSocket_TaskMain(task_entry_struct * task_entry_ptr)
{
	ilm_struct current_ilm;
	kal_uint32 my_index = 0;

	kal_get_my_task_index(&my_index);
	while (1) 
	{
		receive_msg_ext_q( task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
		stack_set_active_module_id( my_index, current_ilm.dest_mod_id );
		McfSocket_TaskMessageHandler((void *) &current_ilm);
		free_ilm( &current_ilm);
	}
} 

//kal_bool mcare_net_task_create(comptask_handler_struct **handle)
MBOOL McfSocket_TaskCreate(comptask_handler_struct **handle)
{
	static const comptask_handler_struct mcare_net_task_handler_info =
	{
		McfSocket_TaskMain,  /* task entry function */
			NULL,  /* task initialization function */
			NULL,  /* task configuration function */
			NULL,  /* task reset handler */
			NULL,  /* task termination handler */
	};

	*handle = (comptask_handler_struct *)&mcare_net_task_handler_info;
	return MTRUE;
}

MBYTE McfSocket_HandleSocMessage(MVOID* inMsg);
MBYTE McfSocket_HandleDnsMessage(MVOID* inMsg);

static MVOID McfSocket_TaskMessageHandler(ilm_struct *ilm_ptr)
{    
	if (MCR_IsRunning())
	{
		if(ilm_ptr->msg_id == MSG_ID_APP_SOC_NOTIFY_IND)
		{
			McfSocket_HandleSocMessage(ilm_ptr->local_para_ptr);
		}
		else if(ilm_ptr->msg_id == MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND)
		{
			McfSocket_HandleDnsMessage(ilm_ptr->local_para_ptr);
		}
#if (MCR_MTK_VER >MTK_VER_812)
		else if(ilm_ptr->msg_id == MSG_ID_APP_CBM_BEARER_INFO_IND)
		{
            /* app_cbm_bearer_info_ind_struct *bearer_info;
            *what if bearer is deactived,to close all sockets or release bearer since
            *we have hold it before??
            *todo..
            */
		}
#endif
		else
		{

		}
	}
	else
	{

	}
}


MBYTE McfSocket_HandleSocMessage(MVOID* inMsg)
{
	app_soc_notify_ind_struct *msgReq = MNULL;
	MUINT src,dst;


	msgReq =(app_soc_notify_ind_struct *)inMsg;
	if (MNULL == msgReq)
	{
		return MFALSE;
	}

	msgReq = (app_soc_notify_ind_struct*)OslConstructDataPtr(sizeof(app_soc_notify_ind_struct));
	memcpy(msgReq, inMsg, sizeof(app_soc_notify_ind_struct));
	src= McfGetNetModId();
	dst =McfGetMcrModId();

	switch(msgReq->event_type)
	{
	case SOC_CONNECT:
		if (MFALSE != msgReq->result)
		{
			McfDtcnt_HoldNetworkBearer(McfDtcnt_GetDataAcctInfo());
		}
		McfPostMessage(src,dst,PRT_MCARE_NET_EVENT_ID_CONNECT_IND, (McfLocalParam*)msgReq);    
		break;

	case SOC_WRITE:
		McfPostMessage(src,dst,PRT_MCARE_NET_EVENT_ID_SEND_IND, (McfLocalParam*)msgReq);  
		break;

	case SOC_READ:
		McfPostMessage(src,dst,PRT_MCARE_NET_EVENT_ID_RECEIVE_IND, (McfLocalParam*)msgReq);  
		break;

	case SOC_CLOSE:
		McfPostMessage(src,dst,PRT_MCARE_NET_EVENT_ID_CLOSE_IND, (McfLocalParam*)msgReq); 
		break;

	}

	return MTRUE;
}


MBYTE McfSocket_HandleDnsMessage(MVOID* inMsg)
{
	app_soc_get_host_by_name_ind_struct *msgReq = MNULL;


	msgReq = (app_soc_get_host_by_name_ind_struct*)OslConstructDataPtr(sizeof(app_soc_get_host_by_name_ind_struct));
	if (MNULL == msgReq)
	{
		return MFALSE;
	}

	memcpy(msgReq, inMsg, sizeof(app_soc_get_host_by_name_ind_struct));
	McfPostMessage(McfGetNetModId(),McfGetMcrModId(),PRT_MCARE_NET_EVENT_ID_GETHOSTBYNAME_IND, (McfLocalParam*)msgReq);  
	if (MTRUE == msgReq->result)
	{
		McfDtcnt_HoldNetworkBearer(McfDtcnt_GetDataAcctInfo());
	}

	return MTRUE;
}

MVOID McfSocket_ProtocolEventHandler(_fPsFuncPtr socHandler,_fPsFuncPtr dnsHandler)
{
	if(socHandler)
	{
		__set_protocol_event_handler(socHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_CONNECT_IND),MFALSE);
		__set_protocol_event_handler(socHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_SEND_IND),MFALSE);
		__set_protocol_event_handler(socHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_RECEIVE_IND),MFALSE);
		__set_protocol_event_handler(socHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_CLOSE_IND),MFALSE);
		__set_protocol_event_handler(socHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_CLOSEDEX),MFALSE); 
	}
	else
	{
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_CONNECT_IND),MNULL);
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_SEND_IND),MNULL);
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_RECEIVE_IND),MNULL);
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_CLOSE_IND),MNULL);
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_CLOSEDEX),MNULL); 		        
	}

	if(dnsHandler)
	{
		__set_protocol_event_handler(dnsHandler, (MUSHORT)(PRT_MCARE_NET_EVENT_ID_GETHOSTBYNAME_IND),MFALSE);	
	}
	else
	{
		__clear_protocol_event_handler((MUSHORT)(PRT_MCARE_NET_EVENT_ID_GETHOSTBYNAME_IND),MNULL);	
	}
}
#else //modify start 修正1212使用mmi task退出时死机 by charmenli 2012-4-14

_fPsFuncPtr g_socHandler = MNULL;
_fPsFuncPtr g_dnsHandler = MNULL;

MVOID McfSocket_ProtocolEventHandler(_fPsFuncPtr socHandler,_fPsFuncPtr dnsHandler)
{
	if(socHandler)
	{
	    g_socHandler = socHandler;
		__set_protocol_event_handler(socHandler, MSG_ID_APP_SOC_NOTIFY_IND, MTRUE);
	}
	else
	{
		__clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,g_socHandler);
	}

	if(dnsHandler)
	{
	    g_dnsHandler = dnsHandler;
		__set_protocol_event_handler(dnsHandler, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, MTRUE);
	}
	else
	{
		__clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND,g_dnsHandler);	
	}
}

#endif//modify end






/*=================================  FS  =====================================*/

const MSHORT MADP_FS_NO_ERROR = FS_NO_ERROR;
const MSHORT MADP_FS_PARAM_ERROR= FS_PARAM_ERROR;
const MSHORT MADP_FS_INVALID_FILENAME = FS_INVALID_FILENAME;
const MSHORT MADP_FS_FILE_NOT_FOUND=FS_FILE_NOT_FOUND;
const MSHORT MADP_FS_PATH_NOT_FOUND =FS_PATH_NOT_FOUND;
const MSHORT MADP_FS_ACCESS_DENIED =FS_ACCESS_DENIED;
const MSHORT MADP_FS_OUT_OF_BUFFERS=FS_OUT_OF_BUFFERS;
const MSHORT MADP_FS_STRING_BUFFER_TOO_SMALL=FS_STRING_BUFFER_TOO_SMALL;
const MSHORT MADP_FS_DISK_FULL=FS_DISK_FULL;
const MSHORT MADP_FS_DATA_ERROR=FS_DATA_ERROR;
const MSHORT MADP_FS_DRIVE_NOT_READY=FS_DRIVE_NOT_READY;
const MSHORT MADP_FS_FILE_EXISTS =FS_FILE_EXISTS;
const MUINT MADP_FS_READ_ONLY =FS_READ_ONLY; 
const MUINT MADP_FS_READ_WRITE =FS_READ_WRITE;
const MUINT MADP_FS_CREATE_ALWAYS = FS_CREATE_ALWAYS;
const MUINT MADP_FS_MOVE_COPY = FS_MOVE_COPY;
const MUINT MADP_FS_MOVE_KILL = FS_MOVE_KILL;
const MUINT MADP_FS_MOVE_OVERWRITE = FS_MOVE_OVERWRITE;
const MUINT MADP_FS_FILE_TYPE =FS_FILE_TYPE;
const MUINT MADP_FS_DIR_TYPE = FS_DIR_TYPE;
const MUINT MADP_FS_RECURSIVE_TYPE=FS_RECURSIVE_TYPE;
const MUINT MADP_FS_DI_BASIC_INFO =FS_DI_BASIC_INFO;         
const MUINT MADP_FS_DI_FREE_SPACE =FS_DI_FREE_SPACE ;       
const MBYTE MADP_FS_MOUNT_STATE_ENUM  =FS_MOUNT_STATE_ENUM;



MVOID __McfDosTimeToMcfTime(MTime_DateTime* o, FS_DOSDateTime* i)
{
	if (o && i)
	{
		o->m_nYear = i->Year1980;
		o->m_nMonth = i->Month;
		o->m_nDay = i->Day;
		o->m_nHour = i->Hour;
		o->m_nMinute = i->Minute;
		o->m_nSecond = i->Second2;
		o->m_nWeekday = 0; // 忽略此值
	}
}

MVOID __McfFileInfoConvert(FS_FileInfo *pFsFileInfo, MFileInfo* pFileInfo)
{
	if(pFsFileInfo && pFileInfo)
	{
		pFileInfo->m_nAttr = pFsFileInfo->DirEntry->Attributes;
		pFileInfo->m_nPos = pFsFileInfo->FilePos;
		pFileInfo->m_nSize = pFsFileInfo->DirEntry->FileSize;

		if( pFileInfo->m_wszFileFullName && McfStdC_wcslen((MWCHAR*)pFsFileInfo->FullName) != 0)
		{
			memset(pFileInfo->m_wszFileFullName, 0, sizeof(pFileInfo->m_wszFileFullName));
			McfStdC_wcscpy(pFileInfo->m_wszFileFullName, (const MWCHAR*)(pFsFileInfo->FullName));
		}

		__McfDosTimeToMcfTime(&pFileInfo->m_Time, &((FS_DOSDirEntry*)pFsFileInfo->DirEntry)->CreateDateTime);
	}
}



MWCHAR McfFile_GetCardDrv(MVOID)
{
    //MMI_CARD_DRV,below 1032
    return FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
}


MWCHAR McfFile_GetPublicDrv(MVOID)
{
    //MMI_PUBLIC_DRV, below 1032    
    return FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);
}

MWCHAR McfFile_GetPrivateDrv(MVOID)
{
    //MMI_PRIVATE_DRV, below 1032
    return FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_ONLY_ALT_SERIAL );
}


MINT McfFileFindFirst(const MWCHAR* namePattern, MWCHAR* pwFileName, MUINT nMaxLen)
{
	MINT nRet = -1;
	FS_DOSDirEntry dirInfo;

	if(namePattern && pwFileName && nMaxLen > 0)
	{
		nRet = FS_FindFirst(namePattern, 0, 0, &dirInfo,pwFileName, nMaxLen);
	}

	return nRet;
}


MINT McfFileFindNext(MFd fd, MWCHAR* pwFileName, MUINT nMaxLen)
{
	MINT nRet = -1;
	FS_DOSDirEntry dirInfo;

	if(fd >= 0 && pwFileName && nMaxLen > 0)
	{
		nRet = FS_FindNext(fd, &dirInfo, pwFileName, nMaxLen);
	}
	return nRet;
}


MINT McfFileGetFileInfo(MFd fd, MFileInfo* pFileInfo)
{
	MINT nRet = -1;

	if(fd >= 0 && pFileInfo)
	{
		FS_FileInfo fileInfo;
		nRet = FS_GetFileInfo(fd, &fileInfo);
		if(nRet >= 0)
		{
			__McfFileInfoConvert(&fileInfo, pFileInfo);
		}
	}
	return nRet;
}

MINT McfGetDiskInfo(const MWCHAR disk, McfDiskInfo* pDiskInfo, MINT Flags)
{
	MINT ret;
	FS_DiskInfo disk_info;
	MWCHAR wszDisk[4] = {0};
	MU64 size;

	if( pDiskInfo==MNULL)
	{
		return -1;
	}

	wszDisk[0] = (MWCHAR)disk;
	wszDisk[1] = (MWCHAR)':';
	wszDisk[2] = (MWCHAR)'\\';
	wszDisk[3] = (MWCHAR)'\0';

	ret = (MINT)FS_GetDiskInfo((const WCHAR *)wszDisk, &disk_info, (int)Flags);

	pDiskInfo->m_nFiles =disk_info.Files;
	size = ((MU64)(disk_info.TotalClusters) * disk_info.SectorsPerCluster * disk_info.BytesPerSector);

	pDiskInfo->m_nTotalSpace = size;
	size = ((MU64)(disk_info.FreeClusters) * disk_info.SectorsPerCluster * disk_info.BytesPerSector);
	pDiskInfo->m_nFreeSpace = size;

	return ret;
}

#if MCR_MTK_VER >= 1132 || ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__)))
mmi_id g_FileSelectID = 0;
mmi_id g_GrpID = 0;
#endif


#if MCR_MTK_VER >= 1132 || ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__)))

#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__)))
#include "vapp_fmgr_cui_gprot.h"
#elif MCR_MTK_VER >= MTK_VER_1132
#include "FileMgrCuiGProt.h"

#define vcui_file_selector_create	cui_file_selector_create
#define VCUI_FILE_SELECTOR_STYLE_FILE_ONLY	CUI_FILE_SELECTOR_STYLE_FILE_ONLY
#define VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL	CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL
#define vcui_file_selector_run	cui_file_selector_run
#define EVT_ID_VCUI_FILE_SELECTOR_RESULT	EVT_ID_CUI_FILE_SELECTOR_RESULT
#define vcui_file_selector_result_event_struct	cui_file_selector_result_event_struct
#define vcui_file_selector_get_selected_filepath	cui_file_selector_get_selected_filepath
#define vcui_file_selector_close	cui_file_selector_close

#endif

#include "mmi_rp_app_tencent_mcare_def.h"


mmi_ret McfFileSelectorCallBack(mmi_event_struct *evt)
{
    //#if 0
    PsExtFuncPtr callback;
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
            vcui_file_selector_result_event_struct *result = (vcui_file_selector_result_event_struct*) evt;
	     if (result->result <= 0)
	     {
	     		callback = (PsExtFuncPtr)(result->user_data);
	     		callback(NULL, 0);
	     	       vcui_file_selector_close(g_FileSelectID);
		       //mmi_frm_group_close(g_GrpID);//估计问题在这里!
	     }
	     else
	     {
			WCHAR path[256] = {0};
			vcui_file_selector_get_selected_filepath(g_FileSelectID,
													NULL,
													path,
													256);
			callback = (PsExtFuncPtr)(result->user_data);
			callback(path, MTRUE);
			vcui_file_selector_close(g_FileSelectID);
    			//mmi_frm_group_close(g_GrpID);
	     }
        }
        break;
        default:
        break;
    }
    return 0;
    //#endif
}
#endif


MINT McfSelectPathAndEnter(pfnMcfSelPathCb callback, MWCHAR *pPath)
{
	MBYTE sel_type = FMGR_SELECT_FILE | FMGR_SELECT_REPEAT;
	FMGR_FILTER filter;

	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET_ALL(&filter);

#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__)))
	{
	    //mmi_id fsCuiId = 0;
	    mmi_id appid = 0;

	    mmi_id appidnew = 0;
		
	    //g_GrpID = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MCARE_LIST, McfFileSelectorCallBack, (void*)callback);
		g_GrpID = mmi_frm_group_create(APP_TENCENT_MCARE, GRP_ID_MCARE_LIST, McfFileSelectorCallBack, (void*)callback);
	    mmi_frm_group_enter(APP_TENCENT_MCARE, 1/*MMI_FRM_NODE_SMART_CLOSE_FLAG*/);
     

        g_FileSelectID = vcui_file_selector_create(
                    g_GrpID/*12473*/,
                    pPath,
                    &filter,
                    0,//VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                    0);//VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
		if (0 != g_FileSelectID)
		{
 
		    //mmi_frm_group_set_caller_proc(fsCuiId, McfFileSelectorCallBack, (void *)callback);
 			mmi_frm_group_set_caller_proc (g_FileSelectID, McfFileSelectorCallBack, (void*)callback);
			vcui_file_selector_run(g_FileSelectID);

	        }
    }
#elif MCR_MTK_VER >= MTK_VER_1132 
    {
            MMI_ID select_parent_grp_id;
			g_FileSelectID = GRP_ID_INVALID;
            select_parent_grp_id = McfGetActiveGroupId();
            g_GrpID = McfGroupIdCreate(select_parent_grp_id, GRP_ID_MCARE_LIST, McfGroupCreateProc, NULL);
            McfGroupIdEnter(g_GrpID, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_FileSelectID = cui_file_selector_create(
                                    g_GrpID,
                                    (WCHAR*) L"root",
                                    &filter,
                                    CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                    CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

            if (g_FileSelectID > GRP_ID_INVALID)
            {
                    //cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(MENU_MCAREV30_MAIN));
                    mmi_frm_group_set_caller_proc (g_FileSelectID, McfFileSelectorCallBack, (void*)callback);
                    cui_file_selector_run(g_FileSelectID);
            }
    }
#else
	//mmi_fmgr_select_path_and_enter((U8)app_id, (U8)sel_type, filter, (PS8)start_path, (PsExtFuncPtr)callback);
	mmi_fmgr_select_path_and_enter(0,  sel_type, filter,(S8*)pPath, (_fPsExtFuncPtr)callback);

#endif

	return 0;
}
MWCHAR McfFile_GetStorageDrv(MVOID)
{
	MWCHAR wchDrv = 0;

/*	if(McfFile_IsTCardReady())    //modify by charmenli 2012-5-28
		wchDrv = McfFile_GetCardDrv();
	else
		wchDrv = McfFile_GetPublicDrv();
*/


#if MCR_STORAGE_TYPE == MCR_STORAGE_PUBLIC
	wchDrv = McfFile_GetPublicDrv();
#elif MCR_STORAGE_TYPE == MCR_STORAGE_CARD
	wchDrv = McfFile_GetCardDrv();
#endif


	return wchDrv;
}

MUINT McfFile_GetStorageFreeSpace(MVOID)
{
	MUINT nSize = 0;

/*	if(McfFile_IsTCardReady())     //modify by charmenli 2012-5-28
		nSize = McfFile_GetTCardFreeSpace();
	else
		nSize = McfFile_GetPublicDrvFreeSpace();
*/


#if MCR_STORAGE_TYPE == MCR_STORAGE_PUBLIC
	nSize = McfFile_GetPublicDrvFreeSpace();
#elif MCR_STORAGE_TYPE == MCR_STORAGE_CARD
	nSize = McfFile_GetTCardFreeSpace();
#endif 


	return nSize;
}

MUINT McfFile_GetFsSizeReq(MVOID)
{
	return MCR_FS_REQ;
}




/*==================================  接入点 ==============================*/
#include "McfPlatform.h"
#include "DataAccountDef.h"

#if (MCR_MTK_VER >= MTK_VER_912)
#include "DataAccountEnum.h"
#endif
#include "DataAccountStruct.h"
#include "abm_soc_enums.h"
#if (MCR_MTK_VER > MTK_VER_812)
#include "abm2soc_struct.h"
#endif
#include "McfSim.h"
#include "McfDtcnt.h"
#include "McfMisc.h"
#include "MAdpConfig.h"


#ifdef HT_FEATURE_CDMA_WAP
#include "ABM_UTIL.H"
#include "HT_BootFunc.h"
#endif

#if MCR_WIFI_SUPPORT == __CFG_YES__
#include "ABM_SOC_ENUMS.H"
#endif


#if MCR_MTK_VER < MTK_VER_1032//
extern U8 gPLMN[];
extern S8 gHomePLMNNum[];
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
/* under construction !*/
/* under construction !*/
#endif

extern GPRSDataAccountNode g_GPRS_DataAccount[];
extern DataAccountNodeDisplay g_DataAccount_Display;
extern void DTCNTGPRSSetAccountReq(U8 ItemNum);
#elif MCR_MTK_VER >=MTK_VER_1032//
#include "DtcntSrv.h"
#include "Servicedefs.h"
#include "cbm_api.h"
#include "dtcntsrvintstruct.h"
#ifdef __TCPIP__
#if (MCR_MTK_VER >= MTK_VER_1112) && defined (__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_vapp_data_account_wlan_def.h"//jason
#else
#include "mmi_rp_app_dataaccount_def.h"
#endif


#if (MCR_MTK_VER >= MTK_VER_1112) && defined (__COSMOS_MMI_PACKAGE__)
srv_dtcnt_prof_gprs_struct g_data_account_gprs_profile_srv = {0};
#else
extern srv_dtcnt_prof_gprs_struct g_data_account_gprs_profile_srv;
#endif

extern srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;
extern U32 g_mmi_dtcnt_acct_num;
#endif /* __TCPIP__ */

#else//
#include "DataAccountDef.h"
#if (MCR_MTK_VER >= MTK_VER_912)
#include "DataAccountEnum.h"
#endif
#include "DataAccountStruct.h"
#include "abm_soc_enums.h"
#endif

//未知接入点
const static MWCHAR unknownapn[]={0x672a,0x77e5,0x63a5,0x5165,0x70b9,0x0};

//接入点列表
#define MCF_APN_CMWAP		L"cmwap"
#define MCF_APN_CMNET		L"cmnet"
#define MCF_APN_UNIWAP		L"uniwap"
#define MCF_APN_UNINET		L"uninet"
#define MCF_APN_CTWAP		L"ctwap"
#define MCF_APN_CTNET		L"ctnet"
#define MCF_APN_WIFI		L"wifi"
#define MCF_APN_UNKNOWN     (MWCHAR*)unknownapn

//卡名称
#define MCF_CARDNAME_CARD1		L"Card1"
#define MCF_CARDNAME_CARD2		L"Card2"
#define MCF_CARDNAME_CARD3		L"Card3"
#define MCF_CARDNAME_CARD4		L"Card4"
#define MCF_CARDNAME_WIFI		L"WIFI NET"


static McfDtcntInfo gDtcntInfo;
static MINT gMcrCbmAppId;

static MBYTE __McrSimIdToCbm(MBYTE simId)
{
	#if( MCR_MTK_VER>MTK_VER_812)
	MBYTE cbmSimId= CBM_SIM_ID_TOTAL;
	#else
	MBYTE cbmSimId = ALWAYS_ASK_SIM_INFO_TOTAL;
	#endif
	if (simId ==MSIM_CARD1 )
	{
        #if( MCR_MTK_VER > MTK_VER_812)
        cbmSimId = CBM_SIM_ID_SIM1;
		#else
        cbmSimId = ALWAYS_ASK_SIM_INFO_SIM1;
		#endif
	}
	else if (simId == MSIM_CARD2)
	{
        #if( MCR_MTK_VER > MTK_VER_812)
        cbmSimId = CBM_SIM_ID_SIM2;
		#else
        cbmSimId = ALWAYS_ASK_SIM_INFO_SIM2;
		#endif
	}

#if MCR_SIM3_SUPPORT == __CFG_YES__
	if(simId == MSIM_CARD3)
	{
		//todo..maybe: cbmSimId = SRV_DTCNT_SIM_TYPE_3;
	}
#endif

#if MCR_SIM4_SUPPORT == __CFG_YES__
	if(simId == MSIM_CARD4)
	{
		//todo..maybe: cbmSimId = SRV_DTCNT_SIM_TYPE_4;
	}
#endif

#if MCR_WIFI_SUPPORT == __CFG_YES__
	if(simId == MSIM_VWIFI)
	{
		//todo..maybe: cbmSimId = SRV_DTCNT_SIM_TYPE_4;
		cbmSimId = 0;  //purple  fixed wifi problem
	}
#endif

	return cbmSimId;

}

MINT __DtcntRegCbmAppId(MVOID)
{
	#if MCR_MTK_VER >= MTK_VER_828
	if(gMcrCbmAppId ==0)
	{
        #if MCR_MTK_VER >= MTK_VER_1032
        if (cbm_register_app_id((kal_uint8*)&gMcrCbmAppId) != CBM_OK)
        {
            //assert;
        }
        #else
		gMcrCbmAppId = cbm_register_app_id(TENCENT_MCARE_BASE+1, TENCENT_MCARE_BASE+1);
        #endif	
	}
	#endif

	return gMcrCbmAppId;
}

#ifndef USE_SYSBRW_DTCNT

#if MCR_MTK_VER >= MTK_VER_1032

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
void mmi_dtcnt_add_disp_list(U32 acct_id, U8 bearer_type, srv_dtcnt_prof_acc_type_enum account_type, U8 conn_type, U8 sim_info, U8 read_only)
{

}

void mmi_dtcnt_ok_popup(void)
{

}

void mmi_dtcnt_update_disp_list(U32 acct_id, U8 bearer_type, srv_dtcnt_prof_acc_type_enum account_type, U8 conn_type, U8 sim_info, U8 read_only)
{

}
#endif


#define MAX_ASC_APN_LEN (19)
MVOID __PrepareGprsProfSrvData(MINT simId,MINT apnType,MUSHORT *pAcctName,MCHAR *pApn)
{
    U8 simInfo;
    U8 ascApn[MAX_ASC_APN_LEN+1]={0};

    if(simId ==MSIM_CARD2)
    {
        simInfo = SRV_DTCNT_SIM_TYPE_2;
    }
    #if MCR_SIM3_SUPPORT == __CFG_YES__
    if(simId == MSIM_CARD3)
    {
        //todo..maybe: simInfo = SRV_DTCNT_SIM_TYPE_3;
    }
    else
    #endif
    #if MCR_SIM4_SUPPORT == __CFG_YES__
    if(simId == MSIM_CARD4)
    {
        //todo..maybe: simInfo = SRV_DTCNT_SIM_TYPE_4;
    }
    else
    #endif
    else
    {
        simInfo = SRV_DTCNT_SIM_TYPE_1;
    }

    memset(&g_data_account_gprs_profile_srv, 0, sizeof(g_data_account_gprs_profile_srv));

    g_data_account_gprs_profile_srv.prof_common_header.AccountName = (const U8*)pAcctName;//
    g_data_account_gprs_profile_srv.prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF; 
    g_data_account_gprs_profile_srv.prof_common_header.acc_id = 0;
    g_data_account_gprs_profile_srv.APN = (const S8*)pApn;//
    g_data_account_gprs_profile_srv.prof_common_header.Auth_info.AuthType = SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL;

    if(apnType == MAPN_WAP)
    {
        g_data_account_gprs_profile_srv.prof_common_header.use_proxy = 1;
        g_data_account_gprs_profile_srv.prof_common_header.px_port =80;
        g_data_account_gprs_profile_srv.prof_common_header.px_addr[0] = 10;
        g_data_account_gprs_profile_srv.prof_common_header.px_addr[1] = 0;
        g_data_account_gprs_profile_srv.prof_common_header.px_addr[2] = 0;
        g_data_account_gprs_profile_srv.prof_common_header.px_addr[3] = 172;
    }
    g_data_account_gprs_profile_srv.prof_common_header.sim_info = simInfo;
    g_data_account_gprs_profile_srv.prof_common_header.read_only = 0;
    g_data_account_gprs_profile_srv.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
}
MINT __DtcntGenAccountByApn(MINT simId,MINT apnType,MUSHORT *pAcctName,MUSHORT *pApn)
{
    srv_dtcnt_store_prof_data_struct prof_info;
    U8 i;
    U32 acct_id;
    srv_dtcnt_result_enum result;
    U8 genAction = 0;//0 --add ,1 --edit, 2 --sacrifice and update,0xff--invalid
    srv_dtcnt_prof_str_info_qry_struct infoQry;
    S8 QryApn[24];//string in ucs2
	U8 conn_type=1;//http conn
	U8 not_in_use=0;
    U8 ascApn[MAX_ASC_APN_LEN+1]={0};


    infoQry.dest =QryApn;
    infoQry.dest_len = sizeof(QryApn);
    for(i=0;i<SRV_DTCNT_PROF_MAX_ACCOUNT_NUM;i++)
    {
    	/*
    	*modify by raymownei,2011/05/04
    	*fix:
    	*36版本选卡1登录QQ后，退出，选择卡2无法登录的问题
    	*/
		if(g_srv_dtcnt_store_ctx.acc_list[i].in_use && simId == g_srv_dtcnt_store_ctx.acc_list[i].sim_info
			&& MMI_TRUE == srv_dtcnt_get_apn(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,&infoQry,SRV_DTCNT_ACCOUNT_PRIMARY)
            && mmi_ucs2cmp((const CHAR*)QryApn,(const CHAR*)pApn)==0)
       {//found
           return g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
       }
       if(g_srv_dtcnt_store_ctx.acc_list[i].in_use && mmi_ucs2cmp((const CHAR*) g_srv_dtcnt_store_ctx.acc_list[i].acc_name,(const CHAR*)pAcctName)==0)
       {
           genAction =1;
           acct_id=g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
           break;
       }

       if(not_in_use ==0 && g_srv_dtcnt_store_ctx.acc_list[i].in_use == 0)
       {
         not_in_use = 1;
       }

    }
    
    if(not_in_use ==0 && genAction ==0)
    {//no empty,reached max,sacrifice the last account..tricky.
        genAction = 2;
        acct_id=g_srv_dtcnt_store_ctx.acc_list[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM-1].acc_id;
    }
    
    if(apnType == MAPN_WAP ||apnType==MAPN_NET)
    {
        //step 1 :: prepare account gprs profile data
        if(genAction ==0 || genAction == 2)
        {
            prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;
            prof_info.prof_data = &g_data_account_gprs_profile_srv;
            prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

            mmi_ucs2_n_to_asc((CHAR *)ascApn, (CHAR *)pApn, MAX_ASC_APN_LEN);
            __PrepareGprsProfSrvData(simId, apnType, pAcctName, (MCHAR*)ascApn);
        }
        else if(genAction ==1)
        {
            U8 simInfo;

            
            memset(&g_data_account_gprs_profile_srv, 0, sizeof(g_data_account_gprs_profile_srv));
            
            prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;
            prof_info.prof_data = &g_data_account_gprs_profile_srv;
            prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_SIM_TYPE|SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;

            if(simId ==MSIM_CARD2)
            {
                simInfo =SRV_DTCNT_SIM_TYPE_2;
            }
            #if MCR_SIM3_SUPPORT == __CFG_YES__
            if(simId == MSIM_CARD3)
            {
                //todo..maybe: simInfo = SRV_DTCNT_SIM_TYPE_3;
            }
            else
            #endif
            #if MCR_SIM4_SUPPORT == __CFG_YES__
            if(simId == MSIM_CARD4)
            {
                //todo..maybe: simInfo = SRV_DTCNT_SIM_TYPE_4;
            }
            else
            #endif
            else
            {
                simInfo =SRV_DTCNT_SIM_TYPE_1;
            }

            g_data_account_gprs_profile_srv.prof_common_header.AccountName=(const U8*)pAcctName;
            mmi_ucs2_n_to_asc((CHAR *)ascApn, (CHAR *)pApn, MAX_ASC_APN_LEN);
            g_data_account_gprs_profile_srv.APN = (const S8*)ascApn;
            g_data_account_gprs_profile_srv.prof_common_header.sim_info = simInfo;
            g_data_account_gprs_profile_srv.prof_common_header.read_only =0;
        }

        //step 2:: commit to storage and update disp list
        if(genAction ==0)
        {//add new profile
            result = srv_dtcnt_store_add_prof(&prof_info, (U32 *)&acct_id);
            if (result == SRV_DTCNT_RESULT_SUCCESS)
            {
/*
*modify by charmenli 2012-2-20
*修正1112cosmos编译问题
*/
#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))
	#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
#elif MCR_MTK_VER >= MTK_VER_1132
                mmi_dtcnt_add_disp_list(acct_id, 
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        SRV_DTCNT_PROF_TYPE_USER_CONF,
                                        conn_type,
                                        g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                         g_data_account_gprs_profile_srv.prof_common_header.read_only);

                if (1 == g_mmi_dtcnt_acct_num)
                {
                    mmi_dtcnt_set_account_default_app_type(acct_id, MMI_FALSE);
                }           
                mmi_dtcnt_ok_popup();


#else
                mmi_dtcnt_add_disp_list(acct_id, 
                                        g_data_account_gprs_profile_srv.prof_common_header.AccountName,
                                        g_data_account_gprs_profile_srv.APN,
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        DTCNT_USER_CONFIGURED_ACCT,
                                        conn_type,
                                        g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                        g_data_account_gprs_profile_srv.prof_common_header.read_only);
                                        
                if (1 == g_mmi_dtcnt_acct_num)
                {
                    mmi_dtcnt_set_account_default_app_type(acct_id, MMI_FALSE);
                }    

                mmi_dtcnt_add_ok_popup();
                        
#endif
/*                 end                  */
            


            }

        }
        else if(genAction ==1 || genAction ==2)
        {//update profile data
            result = srv_dtcnt_store_update_prof(acct_id, &prof_info);
            if (result == SRV_DTCNT_RESULT_SUCCESS)
            {

#if ((MCR_MTK_VER ==MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))
                vapp_dtcnt_update_disp_list(acct_id, 
                                           g_data_account_gprs_profile_srv.prof_common_header.AccountName,
                                           g_data_account_gprs_profile_srv.APN,
                                           DATA_ACCOUNT_BEARER_GPRS,
                                           DTCNT_USER_CONFIGURED_ACCT,
                                           conn_type,
                                           g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                           g_data_account_gprs_profile_srv.prof_common_header.read_only);
#elif ((MCR_MTK_VER ==MTK_VER_1144) && (defined  (__COSMOS_MMI_PACKAGE__))) //by rico 1144
                vapp_dtcnt_update_disp_list(acct_id, 
                                           g_data_account_gprs_profile_srv.prof_common_header.AccountName,
                                           g_data_account_gprs_profile_srv.APN,
                                           DATA_ACCOUNT_BEARER_GPRS,
                                           SRV_DTCNT_PROF_TYPE_USER_CONF,
                                           conn_type,
                                           g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                           g_data_account_gprs_profile_srv.prof_common_header.read_only);

#elif  MCR_MTK_VER >= MTK_VER_1132
                mmi_dtcnt_update_disp_list(acct_id, 
                                        DATA_ACCOUNT_BEARER_GPRS,
                                        SRV_DTCNT_PROF_TYPE_USER_CONF,
                                        conn_type,
                                        g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                         g_data_account_gprs_profile_srv.prof_common_header.read_only);
                mmi_dtcnt_ok_popup();
#else
                mmi_dtcnt_update_disp_list(acct_id, 
                                           g_data_account_gprs_profile_srv.prof_common_header.AccountName,
                                           g_data_account_gprs_profile_srv.APN,
                                           DATA_ACCOUNT_BEARER_GPRS,
                                           DTCNT_USER_CONFIGURED_ACCT,
                                           conn_type,
                                           g_data_account_gprs_profile_srv.prof_common_header.sim_info,
                                           g_data_account_gprs_profile_srv.prof_common_header.read_only);	
        	    mmi_dtcnt_save_ok_popup();
#endif

            }
        }

    }
    else if(apnType ==MAPN_WIFI)
    {
        //todo
    }

    return acct_id;

}
#else
U8 mmi_dtcnt_GPRS_allocate_acct_id(void);
void mmi_dtctn_org_id_init(int maxCnt)
{
#if MCR_MTK_VER >= MTK_VER_936
	int idx;
	g_DataAccount_Display.GPRS_acct_num = 0;
	for(idx=0;idx<maxCnt;idx++)
	{
		if(mmi_ucs2strlen((const CHAR *)g_GPRS_DataAccount[idx].APN)>0)
		{
			g_GPRS_DataAccount[idx].org_acct_id = idx;
			g_GPRS_DataAccount[idx].Present = 'P';
			g_DataAccount_Display.GPRS_acct_num++;
		}
		else
		{
			g_GPRS_DataAccount[idx].Present = 'E';
		}
	}
#endif
}

#if MCR_MTK_VER >= MTK_VER_936
void __DtcntGenAccountRsp(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

#ifdef __MMI_GPRS_FEATURES__

	mmi_ps_set_gprs_data_account_rsp_struct *localPtr;
	//OSWRAPPER_TRACEANDLOG((L"[__DtcntGenAccountRsp]\r\n"));

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;
	if (localPtr->result == KAL_TRUE /* OK */ )
	{
		//OSWRAPPER_TRACEANDLOG((L"[__DtcntGenAccountRsp] ok !!!!!!!!!!\r\n"));

		g_DataAccount_Display.GPRS_acct_num++;
		mmi_dtcnt_arrange_acct_list(NULL, g_GPRS_DataAccount, ARRANGE_ACCT_TYPE_ALPHABET);
	}

#endif /* __MMI_GPRS_FEATURES__ */ 
}
#endif

MINT __DtcntLookupApn(MUSHORT *apn)
{
	int idx;
	int maxCnt;

#if MCR_MTK_VER >= MTK_VER_936
	maxCnt = g_DataAccount_Display.GPRS_acct_num;
#else
	maxCnt = MAX_DATA_ACCOUNT_GPRS_LIMIT;
#endif
	if(apn)
	{
		for(idx = 0;idx <maxCnt;idx++)
		{
			if(g_GPRS_DataAccount[idx].Present=='P' && mmi_ucs2icmp((const S8 *) apn, (const S8 *) g_GPRS_DataAccount[idx].APN)==0)
			{
#if MCR_MTK_VER >= MTK_VER_936
				return g_GPRS_DataAccount[idx].org_acct_id;
#else
				return idx;
#endif
			}
		}
	}

	return -1;
}

MVOID RestoreAdpKeyHandler(MVOID);
MVOID RestoreAdpPenHandler(MVOID);
MINT __DtcntGenAccountByApn(MUSHORT *pAcctName,MUSHORT *pApn)
{//apn not exist in current gprs data account list
	MINT idx,i;
	MBOOL sacrificeLast = MFALSE;

	if(pAcctName ==NULL || pApn ==NULL)
	{
		return -1;
	}

	for(idx = 0;idx <MAX_DATA_ACCOUNT_GPRS_LIMIT;idx++)
	{
		if(mmi_ucs2strlen((const S8 *) g_GPRS_DataAccount[idx].APN)==0)
		{
			break;
		}
	}

	if(idx ==MAX_DATA_ACCOUNT_GPRS_LIMIT)
	{//sacrifice the last account
#if MCR_MTK_VER >= MTK_VER_936
		g_DataAccount_Display.GPRS_acct_num--;
		idx = g_DataAccount_Display.GPRS_acct_num;        
		sacrificeLast = MTRUE;
#else
		idx =MAX_DATA_ACCOUNT_GPRS_LIMIT -1;
#endif
	}

	g_GPRS_DataAccount[idx].AuthType= 0;
	mmi_ucs2cpy((PS8) g_GPRS_DataAccount[idx].DataAccountName,(const PS8)pAcctName);
	g_GPRS_DataAccount[idx].iFdcs = 0;
	mmi_ucs2cpy((PS8) g_GPRS_DataAccount[idx].APN,(const PS8)pApn);
	g_GPRS_DataAccount[idx].UserName[0] = 0;
	g_GPRS_DataAccount[idx].Passwd[0] = 0;
#if MCR_MTK_VER >= MTK_VER_936
	if(sacrificeLast == MFALSE)
	{
		g_GPRS_DataAccount[idx].org_acct_id = 0xff;//invalid it first
		g_GPRS_DataAccount[idx].org_acct_id = mmi_dtcnt_GPRS_allocate_acct_id();
	}
#endif
	for (i = 0; i < 4; i++)
	{
		g_GPRS_DataAccount[idx].DnsAddress[i]=0;
#if MCR_MTK_VER > MTK_VER_816
        g_GPRS_DataAccount[idx].ViceDnsAddress[i]=0;
#endif
	}

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_GPRS_DataAccount[idx].provurl_hash_val[0] = 0;
	g_GPRS_DataAccount[idx].napid_hash_val[0] = 0;
	g_GPRS_DataAccount[idx].acct_type=0;
#endif 
#if MCR_MTK_VER > MTK_VER_816
    g_GPRS_DataAccount[idx].readonly =0;
#endif
	g_GPRS_DataAccount[idx].Present ='P';

	//fixme: if we use net immediately we will face error.
#if MCR_MTK_VER >= MTK_VER_936
	mmi_dtcnt_add_GPRS_account_req(g_GPRS_DataAccount[idx].org_acct_id,idx);
	RestoreAdpKeyHandler();//need re-reg cause inside mmi_dtcnt_add_GPRS_account_req would clear key & pen event handler,arlo
	RestoreAdpPenHandler();
	__set_protocol_event_handler(__DtcntGenAccountRsp, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP,MFALSE);
	return g_GPRS_DataAccount[idx].org_acct_id;
#else
	DTCNTGPRSSetAccountReq(idx);
	RestoreAdpKeyHandler();
	RestoreAdpPenHandler();
	__set_protocol_event_handler(NULL, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP,MFALSE);
	return idx;
#endif

	return idx;
}

#endif
MUINT McfCustConfigDtcnt(MINT simId,MINT optr,MINT apnType)
{//用户自行配置数据账号ID
	//返回合适的account id供创建socket使用
#ifdef HT_FEATURE_CDMA_WAP
	if(optr== MSIM_OPR_TELCOM)
	{
		//dump_printf_log("McfCustConfigDtcnt:cdma:HT_ABM_CDMA1_NWACC_ID\r\n");
		mcf_cdma_net_flag = TRUE;
		return HT_ABM_CDMA1_NWACC_ID;//此ID可能不同公司不同，由具体情况而定
	}
#endif

	/*建议通过形如cbm_encode_data_account_id(id, CBM_SIM_ID_SIM1, gMcrCbmAppId, 0);
	* 返回dataaccount id
	*/
    #ifdef WIN32
    if(optr== MSIM_OPR_TELCOM)
    {//test case only
        return 0x08003e0e;//sim1 cmnet
    }
    else if(simId == MSIM_VWIFI)
    {//test case only
        return 0x08003e0e;
    }
    #endif
	#ifdef HT_FEATURE_CDMA_WAP
	mcf_cdma_net_flag = FALSE;
    #endif
    return 0;
}

static MWCHAR *__GetOptionalApn(MINT simId,MINT apnType)
{//根据sim卡判断运营商候选一个默认的apn
    MINT simOpr;
    MWCHAR *pApn = MNULL;
	simOpr= McfSim_GetSimOperator(simId);
    McfTrace_TraceFormatA( __MCR_FUNCTION__ "simId:%d,apnType:%d,simOpr:%d",simId,apnType,simOpr);

	////china mobile
	if(simOpr ==MSIM_OPR_CMCC)
	{
		if(apnType == MAPN_WAP)
		{
			pApn = MCF_APN_CMWAP;
		}
		else if(apnType == MAPN_NET)
		{
			pApn= MCF_APN_CMNET;
		}
	}

	//china unicom
	else if(simOpr == MSIM_OPR_UNICOM)
	{
		if(apnType == MAPN_WAP)
		{
			pApn = MCF_APN_UNIWAP;
		}
		else if(apnType == MAPN_NET)
		{
			pApn= MCF_APN_UNINET;
		}
	}

	//china telcom
	else if(simOpr == MSIM_OPR_TELCOM)
	{
		if(apnType == MAPN_WAP)
		{
			pApn = MCF_APN_CTWAP;
		}
		else if(apnType == MAPN_NET)
		{
			pApn= MCF_APN_CTNET;
		}
	}

	//WIFI
	else if(simOpr == MSIM_OPR_WIFI)
	{
		pApn = MCF_APN_WIFI;
	}
	else
	{
		pApn = MCF_APN_CMWAP;
	}

	return pApn;
}

static MUINT __DtcntSelectByApn(MINT simId,MINT apnType,MCHAR *pApnName)
{
	MUSHORT *pApn=MNULL,*pAltApn=MNULL;//
	MCHAR *pPlmn=MNULL;
	MINT idx = -1;
	MUINT accountId = 0;
	MINT cbmSimId = 0;
	MINT simOpr = 0;
	MUSHORT wszApnName[MAPN_NAME_SIZE] = {0};

    mmi_asc_n_to_ucs2((CHAR *) wszApnName, pApnName, MAPN_NAME_SIZE-1);
    pApn = wszApnName;

    //CASE 1:customer-self config account id,for CDMA
    accountId=McfCustConfigDtcnt(simId,simOpr,apnType);
    if(accountId >0)
    {
        return accountId;
    }

    //CASE 2:for WIFI
    #if MCR_WIFI_SUPPORT == __CFG_YES__
    if(simId == MSIM_VWIFI)
    {
        kal_uint32 id;
      #if MCR_MTK_VER >= MTK_VER_1032
        id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, __McrSimIdToCbm(simId), gMcrCbmAppId, 0);
      #else
        abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 0, &id);
	    #if MCR_MTK_VER <= MTK_VER_812
	     id = always_ask_encode_data_account_id(id, 0, 0, 0);
	    #else
         id = cbm_encode_data_account_id(id, 0, 0, 0);
	    #endif
      #endif
	#ifdef __MCARE_SEPERATE_NET_TASK__
        kal_prompt_trace(MOD_MCARE, __MCR_FUNCTION__ " wifi id = %d, app_id() = %d",  id, gMcrCbmAppId);
	#endif
        return id;
    }
    #endif

    //CASE 3: not customer config
	// check if given apn exist in gprs data account list or not
	#if MCR_MTK_VER >= MTK_VER_1032
    idx =__DtcntGenAccountByApn(simId,apnType,pApn,pApn);//acct id got
	#else
	idx =__DtcntLookupApn(pApn);
	if(idx <0)
	{
		idx =__DtcntLookupApn(pAltApn);
		if(idx >=0)
		{//use alternate apn
			pApn = pAltApn;
		}
	}

	if(idx <0)
	{//not exist ,generate an account to satisfy me.
		idx = __DtcntGenAccountByApn(pApn,pApn);
	}
    #endif
    
	if(idx >=0)
	{//
		cbmSimId = __McrSimIdToCbm(simId);

        #if MCR_MTK_VER >= MTK_VER_1032
        accountId = idx;//idx is profile account id already.
        #else
		//bearer not used now...gprs only ..todo..arlo
		abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_GPRS, idx + 1, &accountId);
		#endif
		#if MCR_MTK_VER <= 812
		accountId = always_ask_encode_data_account_id(accountId, cbmSimId, gMcrCbmAppId, 0);
		#else
		accountId = cbm_encode_data_account_id(accountId, cbmSimId, gMcrCbmAppId, 0);
		#endif
	}

	McfTrace_TraceFormatA(__MCR_FUNCTION__"cbm app id:%d,ori idx:%d,return accountId:%d",gMcrCbmAppId,idx,accountId);

	return accountId;
}

MUINT __DtcntMakeDataAcctId(McfDtcntInfo*pDataAcct)
{
	MUINT acctId;

	if(pDataAcct ==MNULL)
	{
		return 0;
	}

	McfTrace_TraceFormatA(__MCR_FUNCTION__" gMcrCbmAppId:%d",gMcrCbmAppId);
	
    __DtcntRegCbmAppId();
    
    if(pDataAcct->apnName[0] == '\0')
    {
        MWCHAR *optapn;
        
		//尝试根据sim卡的运营商取默认的apn来设置
        optapn = __GetOptionalApn(pDataAcct->simId,pDataAcct->apnType);
        mmi_ucs2_n_to_asc(pDataAcct->apnName,(CHAR*)optapn,MAPN_NAME_SIZE-1);
    }
	acctId = __DtcntSelectByApn(pDataAcct->simId,pDataAcct->apnType,pDataAcct->apnName);
	pDataAcct->acctId = acctId;

    if(acctId > 0 && acctId != gDtcntInfo.acctId)
    {
        McfDtcnt_CloseNetworkBearer(&gDtcntInfo);
	    memcpy(&gDtcntInfo,pDataAcct,sizeof(McfDtcntInfo));
    }

	return acctId;
}

/**********************************
* McfDtcnt_GetProxyInfo ,get proxy info of current data account
*@pProxy --[out] proxy host server ip/name
*@nLen --[in]buffer len of pProxy
*@pPort --[out] proxy port number
*#return 1-- yes,use proxy
        0 -- no,connect through
        -1 --error
*/
MINT McfDtcnt_GetProxyInfo(MCHAR *pProxy,MINT nLen,MUSHORT *pPort)
{
    MINT nRet = -1;
    MINT nOptr;

    nOptr = McfSim_GetSimOperator(gDtcntInfo.simId);
    
    if(gDtcntInfo.apnType == MAPN_WAP)
    {
        /*if(nOptr== MSIM_OPR_CMCC ||nOptr == MSIM_OPR_UNICOM)
        {
            if(pProxy) strncpy(pProxy,"10.0.0.172",nLen);
        }
        else */if(nOptr== MSIM_OPR_TELCOM)
        {
            if(pProxy) strncpy(pProxy,"10.0.0.200",nLen);
        }
        else
        {
            if(pProxy) strncpy(pProxy,"10.0.0.172",nLen);
        }
        
        if(pPort) *pPort = 80;

        nRet = 1;
    }
    else
    {
        nRet = 0;
    }
    
    return nRet;
}
MINT McfDtcnt_EntrySelection(MVOID *pParam)
{
    return 1;
}
MINT McfResetApnInfo(MINT nFlag)
{
    return 0;
}
#else
#include "WAPProfileType.h"
#include "WAPProfileProt.h"
#include "WAPProfResDef.h"
#include "DataAccountResDef.h"

#ifndef __MMI_WAP_PROF__
#error "[error]We MUST turn on __MMI_WAP_PROF__ to support USE_SYSBRW_DTCNT"
#endif

static MCHAR gActProxy[20];
static MUSHORT gActProxyPort;
static MBOOL gUseProxy;//MTRUE--use proxy ,MFALSE -- not use proxy
static MBOOL gIsSelctingApn;
static MUSHORT gDtcntSimItems[8];

static MINT __McrSimIdToProf(MINT nSimId)
{
    MINT nProfSim = MMI_WAP_PROF_SIMID_SIM1;

    #ifdef __MMI_WAP_DUAL_SIM__
    if(nSimId == MSIM_CARD2)
    {
       nProfSim = MMI_WAP_PROF_SIMID_SIM2;
    }
    #endif 
    #if defined (__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)
    else if(nSimId == MSIM_VWIFI)
    {
      nProfSim = MMI_WAP_PROF_SIMID_WLAN;
    }
    #endif 

    return nProfSim;
}

static MBYTE __ProfSimIdToMcr(MBYTE simId)
{
	MBYTE nMcrSimId= MSIM_NONE;

	if (simId ==MMI_WAP_PROF_SIMID_SIM1 )
	{
        nMcrSimId = MSIM_CARD1;
	}
#ifdef __MMI_WAP_DUAL_SIM__
	else if (simId == MMI_WAP_PROF_SIMID_SIM2)
	{
        nMcrSimId = MSIM_CARD2;
	}
#endif
#if MCR_WIFI_SUPPORT == __CFG_YES__
	else if(simId == MMI_WAP_PROF_SIMID_WLAN)
	{
		nMcrSimId = MSIM_VWIFI;
	}
#endif

	return nMcrSimId;

}

MVOID __SetProxyInfo(MBYTE ip[4],MUSHORT port,MBOOL bUseProxy)
{
	sprintf(gActProxy,"%u.%u.%u.%u",ip[0],ip[1],ip[2],ip[3]);
	gActProxyPort = port;
	gUseProxy = bUseProxy;
}

MVOID __SetAcctInfo(McfDtcntInfo *pDataAcct,MUINT nAcctId,MBOOL bUseProxy)
{

    if(nAcctId > 0)
    {
        if (nAcctId != gDtcntInfo.acctId)
        {
			McfDtcnt_CloseNetworkBearer(&gDtcntInfo);
        }
        gDtcntInfo.acctId = nAcctId;
        if(bUseProxy) {
            gDtcntInfo.apnType = MAPN_WAP;
            strncpy(gDtcntInfo.apnName,"apnwap",MAPN_NAME_SIZE-1);
            strncpy(pDataAcct->apnName,"apnwap",MAPN_NAME_SIZE-1);
        }
        else {
            gDtcntInfo.apnType = MAPN_NET;
            strncpy(gDtcntInfo.apnName,"apnnet",MAPN_NAME_SIZE-1);
            strncpy(pDataAcct->apnName,"apnnet",MAPN_NAME_SIZE-1);
        }
        gDtcntInfo.simId = pDataAcct->simId;
    }      
	pDataAcct->acctId = nAcctId;
	pDataAcct->apnType = gDtcntInfo.apnType;
}

#if MCR_MTK_VER >= MTK_VER_1032
#include "dtcntsrvgprot.h"
#include "ConnectManageResDef.h"
MUINT __DtcntMakeDataAcctId(McfDtcntInfo*pDataAcct)
{
    MINT nProfSimId,nAcctId;
    MINT nSimId;
	MBOOL bUseProxy;
    srv_dtcnt_prof_proxy_info_struct proxyInfo;

    if(pDataAcct == MNULL)
    {
        return 0;
    }
    
    nAcctId = mmi_wap_prof_get_active_dtcnt_index(MMI_WAP_PROF_SIMID_DEFAULT, MMI_WAP_PROF_APPID_BRW);

    srv_dtcnt_get_proxy_info( nAcctId,&proxyInfo,SRV_DTCNT_ACCOUNT_PRIMARY);
    
    nProfSimId = __McrSimIdToProf(pDataAcct->simId);

    __DtcntRegCbmAppId();
    nSimId = __McrSimIdToCbm(pDataAcct->simId);
	bUseProxy = (proxyInfo.use_proxy);
	__SetProxyInfo(proxyInfo.px_addr,proxyInfo.px_port,bUseProxy);

    __SetAcctInfo(pDataAcct,nAcctId,bUseProxy);
    gIsSelctingApn = MFALSE;
  
    return nAcctId;
}

#else
MUINT __DtcntMakeDataAcctId(McfDtcntInfo*pDataAcct)
{
    nvram_wap_prof_profile_content_struct *pProfCont;
    MINT nProfSimId,nAcctId;
    MINT nSimId;
	MBOOL bUseProxy;

    if(pDataAcct == MNULL)
    {
        return 0;
    }
    
    nProfSimId = __McrSimIdToProf(pDataAcct->simId);
    pProfCont = mmi_wap_prof_get_active_profile_content_value(nProfSimId,MMI_WAP_PROF_APPID_BRW);


    nAcctId = pProfCont->data_account_primary_id;

    __DtcntRegCbmAppId();
    nSimId = __McrSimIdToCbm(pDataAcct->simId);
	#if MCR_MTK_VER <= MTK_VER_812
		nAcctId = always_ask_encode_data_account_id(nAcctId, nSimId, gMcrCbmAppId, 0);
	#else
		nAcctId = cbm_encode_data_account_id(nAcctId, nSimId, gMcrCbmAppId, 0);
	#endif
	bUseProxy = (pProfCont->use_proxy_status == MMI_WAP_PROF_USE_PROXY_YES);
	__SetProxyInfo(pProfCont->proxy_ip,pProfCont->proxy_port,bUseProxy);

    __SetAcctInfo(pDataAcct,nAcctId,bUseProxy);
    gIsSelctingApn = MFALSE;
  
    return nAcctId;
}
#endif
/**********************************
* McfDtcnt_GetProxyInfo ,get proxy info of current data account
*@pProxy --[out] proxy host server ip/name
*@nLen --[in]buffer len of pProxy
*@pPort --[out] proxy port number
*#return 1-- yes,use proxy
        0 -- no,connect through
        -1 --error
*/
MINT McfDtcnt_GetProxyInfo(MCHAR *pProxy,MINT nLen,MUSHORT *pPort)
{
    MINT nRet = -1;
    
    if(gUseProxy)
    {
        if(pProxy) 
        {
            strncpy(pProxy,gActProxy,nLen);
        }
        
        if(pPort)
        {
            *pPort = gActProxyPort;
        }
        nRet = 1;
    }
    else
    {
        nRet = 0;
    }

    return nRet;
}

MINT McfResetApnInfo(MINT nFlag)
{
    MINT nProfSim;

    if(gIsSelctingApn)
    {
        nProfSim = g_mmi_wap_prof_cntx.sim_id;
        MApn_SetApnInfo(__ProfSimIdToMcr(nProfSim),0,MNULL);
		gIsSelctingApn = MFALSE;
        if(nFlag) 
        {
#if MCR_MTK_VER < MTK_VER_1132
          GoBackToHistory(MCARE_SCREEN_HOME);
#endif
        }
    }
    return 0;
}


MVOID __DtcntSelectionLsk(MVOID)
{
    U16 i;
    int nProfSim;

    i = GetCurrHiliteID();

    nProfSim = __McrSimIdToProf(gDtcntSimItems[i]);
    mmi_wap_prof_display_profile_list(nProfSim,MMI_WAP_PROF_APPID_BRW,
                                    GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}

MINT __GetHighlightSimItem(MINT nSimId)
{
    MINT i;
    for(i = 0 ;i < 8 ;i++)
    {
        if(gDtcntSimItems[i] == nSimId)
        {
            return i;
        }
    }

    return 0;
}
MVOID __Dtcnt_EntrySelection(MVOID)
{
    MINT nSim;
    U8 *guiBuffer;
    U16 nStrItemList[8];
    U16 nNumofItem;

    
    nSim = McfSim_GetValidSim();
    nNumofItem = 0;
    if(nSim & MSIM_VWIFI)
    {
        #if MCR_MTK_VER >= MTK_VER_1032
        nStrItemList[nNumofItem] = STR_ID_CBM_DETAIL_TYPE_WIFI;
        #else
        nStrItemList[nNumofItem] = STR_ID_DTCNT_WIFI_SEARCH;
        #endif
        gDtcntSimItems[nNumofItem] = MSIM_VWIFI;
        nNumofItem++;
    }
    
    if(nSim & MSIM_CARD1)
    {
        nStrItemList[nNumofItem] = STR_ID_DTCNT_SIM1;
        gDtcntSimItems[nNumofItem] = MSIM_CARD1;
        nNumofItem++;
    }
    
    if(nSim & MSIM_CARD2)
    {
        nStrItemList[nNumofItem] = STR_ID_DTCNT_SIM2;
        gDtcntSimItems[nNumofItem] = MSIM_CARD2;
        nNumofItem++;
    }
    
    if(nNumofItem > 1)
    {
        EntryNewScreen(SCR_ID_DTCNT_LIST, NULL, __Dtcnt_EntrySelection, NULL);

#if MCR_MTK_VER >= MTK_VER_1132 //by purple
        //return (MUINT8*)mmi_frm_scrn_get_gui_buf (GRP_ID_MCARE_LIST, (MMI_ID) scrid);
        guiBuffer = mmi_frm_scrn_get_gui_buf (GRP_ID_MCARE_LIST, (MMI_ID) SCR_ID_DTCNT_LIST);
#else
        guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_LIST);
#endif
        
        SetParentHandler(NULL);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            STR_GLOBAL_DATA_ACCOUNT,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            __GetHighlightSimItem(gDtcntInfo.simId),
            guiBuffer);

        SetLeftSoftkeyFunction(__DtcntSelectionLsk, KEY_EVENT_UP);
        SetRightSoftkeyFunction(McfGoBackHistory, KEY_EVENT_UP);//by purple
        SetKeyHandler(McfGoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN); //by purple
    }
    else
    {
        MINT nProfSim;
        
        nProfSim = __McrSimIdToProf(gDtcntSimItems[0]);
        mmi_wap_prof_display_profile_list(nProfSim,MMI_WAP_PROF_APPID_BRW,
                                    GetRootTitleIcon(SERVICES_WAP_MENU_ID),GRP_ID_ROOT);
    }

}
MINT McfDtcnt_EntrySelection(MVOID *pParam)
{
    __Dtcnt_EntrySelection();
    gIsSelctingApn = MTRUE;
    /*
    mmi_dtcnt_select_account_option(McfSelectDtcntCb, 
                            MENU_ID_PROF_DATA_ACCOUNT, 
                            DATA_ACCOUNT_BEARER_GPRS|DATA_ACCOUNT_BEARER_WIFI, 
                            DTCNT_SELECT_SIM, 
                            nCbmAppId);
    */

    return 0;

} 

void mmi_dtctn_org_id_init(int maxCnt)
{
    //nothing todo.
}
#endif

MBOOL McfDtcnt_OpenNetworkBearer(McfDtcntInfo *pDataAcct)
{
#if MCR_MTK_VER >= MTK_VER_828
	module_type modId;
	kal_int8 err = CBM_OK;

	modId = McfGetNetModId();

	if(pDataAcct ==MNULL)
	{
		return 0;
	}

	if(pDataAcct->acctId==0)
	{
		//modified by davidye
		__DtcntMakeDataAcctId(pDataAcct);
	}

	if(pDataAcct->acctId)
	{
	    
	    /*#if MCR_MTK_VER < MTK_VER_1032
        cbm_open_bearer(modId, pDataAcct->acctId);
        #else
        cbm_open_bearer(pDataAcct->acctId);
        #endif*/
          
		return MTRUE;
	}
	else
	{
		return MFALSE;
	}
#else
    return MTRUE;
#endif
}

MBOOL McfDtcnt_HoldNetworkBearer(McfDtcntInfo *pDataAcct)
{
#if MCR_MTK_VER >= MTK_VER_828
	module_type modId;
	kal_uint8 appId;
	kal_int8 err = CBM_OK;

	modId = McfGetNetModId();
	if(pDataAcct ==MNULL || pDataAcct->acctId==0)
	{
		return MFALSE;
	}

	cbm_decode_data_account_id((kal_uint32)pDataAcct->acctId, MNULL, &appId, MNULL, MNULL);
    #if MCR_MTK_VER < MTK_VER_1032
    cbm_hold_bearer(modId, appId);
    #else
    cbm_hold_bearer(appId);
    #endif    

	if(err ==CBM_OK || err == CBM_WOULDBLOCK)
	{
		return MTRUE;
	}
	else 
	{
		return MFALSE;
	}
#else
    return MTRUE;
#endif
}

MBOOL McfDtcnt_CloseNetworkBearer(McfDtcntInfo *pDataAcct)
{
	module_type modId;
	kal_int8 err;

	if(pDataAcct ==MNULL ||pDataAcct->acctId ==0)
	{
		return 0;
	}
	
#if MCR_MTK_VER >= MTK_VER_828
    err=CBM_OK;
	modId = McfGetNetModId();

    McfSoc_CloseAll();
    
	//don't have to deactivate_req, when we hold bearer before, we call release_bearer.arlo
	//soc_send_deactivate_req_to_abm(modId,pDataAcct->acctId,0,0, ABM_APP_NON_AUTO_DEACT);
  #if MCR_MTK_VER < MTK_VER_1032
    err = cbm_release_bearer(modId, gMcrCbmAppId);
  #else
    err = cbm_release_bearer(gMcrCbmAppId);
  #endif

	if(err ==CBM_OK || err == CBM_WOULDBLOCK)
	{
		return MTRUE;
	}
	else 
	{
		return MFALSE;
	}
#else
	soc_close_nwk_account_by_id((MUSHORT)McfGetNetModId(), pDataAcct->acctId);

    return MTRUE;
#endif
}


McfDtcntInfo *McfDtcnt_GetDataAcctInfo(MVOID)
{
	return &gDtcntInfo;
}


MINT McfDtcnt_IsNetworkReady(MVOID)
{
	int ret =0;
	int sim1Removed =1;

/*
 *add by charmenli 
 *适配老平台少于0952使用WIFI
 *2012-1-13
*/	 
#if (MCR_WIFI_SUPPORT ==  __CFG_YES__) && (MCR_MTK_VER <= MTK_VER_952)
	extern mmi_wlan_display_struct g_wlan_display_context;
#endif
//end add

#if MCR_MTK_VER >= MTK_VER_1032
	ret = srv_bootup_is_completed();
#else
	if(!mmi_bootup_is_sim_removed())
	{
		sim1Removed = 0;
		ret = mmi_bootup_is_network_searching_complete();
	}

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif
		//入口处检测C网是否ready, 否则单插c卡进入会提示网络未就绪
#ifdef HT_FEATURE_CDMA_WAP
	else if(IS_STATUS_NONE_UIM() == TRUE)
	{
		ret = TRUE;
	}
#endif

	if(ret && McfSim_GetSimOperator(MSIM_CARD1)== MSIM_OPR_NONE
		&& McfSim_GetSimOperator(MSIM_CARD2)== MSIM_OPR_NONE
#if MCR_SIM3_SUPPORT == __CFG_YES__
		&& McfSim_GetSimOperator(MSIM_CARD3)== MSIM_OPR_NONE
#endif
#if MCR_SIM4_SUPPORT == __CFG_YES__
		&& McfSim_GetSimOperator(MSIM_CARD4)== MSIM_OPR_NONE
#endif
	   )
	{
		ret = 0;
	}
/*
 *add by charmenli 
 *适配平台使用WIFI
 *2012-1-13
*/	 
#if (MCR_WIFI_SUPPORT ==  __CFG_YES__)
	#if (MCR_MTK_VER <= MTK_VER_952)//老平台的判断写法
	if (WLAN_STATE_CONNECTED ==  g_wlan_display_context.state)
	#else//新平台的写法
	if(srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED)
	#endif
	{
		ret = 1;
	}
#endif
//end add


	return ret;
}

MINT McfGetOptr_byApnName(MCHAR *pApnName)
{
		
    if(!McfStdC_strcmp(pApnName,"cmwap") || !McfStdC_strcmp(pApnName,"cmnet") )
   	{
   		return MSIM_OPR_CMCC;
   	}
   	else if(!McfStdC_strcmp(pApnName,"uniwap") || !McfStdC_strcmp(pApnName,"uninet"))
   	{
   		return MSIM_OPR_UNICOM;
  	}
  	else if(!McfStdC_strcmp(pApnName,"ctwap") || !McfStdC_strcmp(pApnName,"ctnet"))
  	{
  		return MSIM_OPR_TELCOM;
  	}
  	else
  	{
  		return -1;
  	}
}

/*add by rico 2011-12-30 判断是否切换了运营商*/
MBOOL McfOperator_IsChanged(MINT SimId, MCHAR *pApnName) 
{
	MINT prev_optr = 0;
    MINT curr_optr = 0;
	MBOOL nRet = MFALSE;

	curr_optr = McfSim_GetSimOperator(SimId);
   	
	prev_optr = McfGetOptr_byApnName(pApnName);
   	
	if(prev_optr < 0)
	{
		McfTrace_TraceFormatA( __MCR_FUNCTION__ "McfGetOptr_byApnName return valid value!");
	}
   	
	if(prev_optr != curr_optr)
	{
		nRet = MTRUE;
	}
  	
  	
	return nRet;
}
		
static MVOID _SetApnInfo(MApnInfo *pApnInfo,MINT simId,MINT optr)
{
	if(pApnInfo)
	{
		pApnInfo->nSimId = simId;
		pApnInfo->nSimOptr = optr;
		pApnInfo->nToSelApn = 1;//

		if(optr == MSIM_OPR_CMCC)
		{
			pApnInfo->nBearer = MBEARER_GPRS;
			pApnInfo->nApnCount = 2;
			pApnInfo->pApnName[0]= MCF_APN_CMWAP;
			pApnInfo->pApnName[1]= MCF_APN_CMNET;
			pApnInfo->apnType[0]= MAPN_WAP;
			pApnInfo->apnType[1]= MAPN_NET;
		}
		else if(optr == MSIM_OPR_UNICOM)
		{
			pApnInfo->nBearer = MBEARER_GPRS;
			pApnInfo->nApnCount = 2;
			pApnInfo->pApnName[0]= MCF_APN_UNIWAP;
			pApnInfo->pApnName[1]= MCF_APN_UNINET;
			pApnInfo->apnType[0]= MAPN_WAP;
			pApnInfo->apnType[1]= MAPN_NET;
		}
		else if(optr == MSIM_OPR_TELCOM)
		{//cdma: 选择C卡后下面显示的接入点列表
			pApnInfo->nBearer = MBEARER_CDMA;
			pApnInfo->nApnCount = 2;
			pApnInfo->pApnName[0]= MCF_APN_CTWAP;
			pApnInfo->pApnName[1]= MCF_APN_CTNET;
			pApnInfo->apnType[0]= MAPN_WAP;
			pApnInfo->apnType[1]= MAPN_NET;
		}
		else if(optr == MSIM_OPR_WIFI)
		{
			pApnInfo->nBearer = MBEARER_WIFI;
			pApnInfo->nApnCount = 1;
			pApnInfo->pApnName[0]= MCF_APN_WIFI;
			pApnInfo->apnType[0]= MAPN_WIFI;
			pApnInfo->nToSelApn = 0;//
		}
		else
		{
			pApnInfo->nBearer = MBEARER_GPRS;
			pApnInfo->nApnCount = 1;
			pApnInfo->pApnName[0]= MCF_APN_UNKNOWN;
			pApnInfo->apnType[0]= MAPN_TOTAL;
		}
	}
}
/*McfGetApnInfo
*@pApnInfo --[out] net info
*@simId   --[in] sim id
*#return MTRUE if valid,else MFALSE
*/
MBOOL McfDtcnt_GetApnInfo(MApnInfo *pApnInfo,MINT simId)
{
	MBOOL ret = MFALSE;
	MINT optr;
	MINT validSim;

	validSim = McfSim_CheckValidSim(MFALSE);
	optr = McfSim_GetSimOperator(simId);

	switch(simId)
	{
	case MSIM_CARD1:
		if((validSim & MSIM_CARD1) == MSIM_CARD1)
		{
			pApnInfo->pName = MCF_CARDNAME_CARD1;
			ret = MTRUE;
		}
		break;

	case MSIM_CARD2:
		if((validSim & MSIM_CARD2) == MSIM_CARD2)
		{
			pApnInfo->pName = MCF_CARDNAME_CARD2;
			ret = MTRUE;
		}
		break;

	case MSIM_CARD3:
		if((validSim & MSIM_CARD3) == MSIM_CARD3)
		{
			pApnInfo->pName = MCF_CARDNAME_CARD3;
			ret = MTRUE;
		}
		break;

	case MSIM_CARD4:
		if((validSim & MSIM_CARD4) == MSIM_CARD4)
		{
			pApnInfo->pName = MCF_CARDNAME_CARD4;
			ret = MTRUE;
		}
		break;

	case MSIM_VWIFI:
		if((validSim & MSIM_VWIFI) == MSIM_VWIFI)
		{
			pApnInfo->pName = MCF_CARDNAME_WIFI;
			optr = MSIM_OPR_WIFI;
			ret = MTRUE;
		}
		break;
	}

	if(ret)
	{
		_SetApnInfo(pApnInfo,simId,optr);
	}

	return ret;
}





/*=============================  SIM ===================================*/
#include "McfSim.h"
#include "McfPlatform.h"

extern U8 gPLMN[];
extern S8 gHomePLMNNum[];
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
/* under construction !*/
/* under construction !*/
#endif


MINT McfGetOperatorByPlmn(MCHAR *pPlmn)
{
	if(pPlmn)
	{
		if(memcmp(pPlmn,"46000",5)==0 || memcmp(pPlmn,"46002",5)==0 || memcmp(pPlmn,"46007",5)==0)
		{//china mobile
			return MSIM_OPR_CMCC;
		}
		else if(memcmp(pPlmn,"46001",5)==0 || memcmp(pPlmn,"46006",5)==0)
		{//china unicom
			return MSIM_OPR_UNICOM;
		}
		else if(memcmp(pPlmn,"46003",5)==0 || memcmp(pPlmn,"46005",5)==0)
		{//china telcom
			return MSIM_OPR_TELCOM;
		}
		else
		{
          #ifdef WIN32
			return MSIM_OPR_CMCC;
		  #else
			return MSIM_OPR_UNKOWN;
          #endif
		}
        
	}
	return MSIM_OPR_NONE;
}


#if MCR_MTK_VER >= MTK_VER_1032
MINT McfSim_CheckValidSim(MINT bChkNwAvail)
{
    srv_nw_info_service_availability_enum sim1NwAvail;
    MMI_BOOL sim1Inserted;
    //#ifdef __MMI_DUAL_SIM_MASTER__
    srv_nw_info_service_availability_enum sim2NwAvail;
    MMI_BOOL sim2Inserted;
    //#endif
    MINT ret = 0;//

    sim1Inserted =srv_sim_ctrl_is_inserted(MMI_SIM1);
    sim1NwAvail = srv_nw_info_get_service_availability(MMI_SIM1);
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
    #endif

#ifdef WIN32
	return 1;
#endif
	
#ifdef __MCARE_SEPERATE_NET_TASK__
    kal_prompt_trace(MOD_MCARE,"[McfGetValidSim]sim1Inserted:%d,sim2Inserted:%d,sim1NwAvail:%d,sim1NwAvail:%d",
            sim1Inserted,sim2Inserted,sim1NwAvail,sim2NwAvail);
    #endif
    if(sim1Inserted)
    {
        if(!bChkNwAvail || sim1NwAvail ==SRV_NW_INFO_SA_LIMITED_SERVICE || sim1NwAvail==SRV_NW_INFO_SA_FULL_SERVICE)
      {
          ret |= MSIM_CARD1;
        }
    }

    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #if MCR_SIM3_SUPPORT == __CFG_YES__
    //todo..
    sim1Inserted =srv_sim_ctrl_is_inserted(MMI_SIM3);
    sim1NwAvail = srv_nw_info_get_service_availability(MMI_SIM3);
    if(sim1Inserted )
    {
        if(!bChkNwAvail || sim1NwAvail ==SRV_NW_INFO_SA_LIMITED_SERVICE || sim1NwAvail==SRV_NW_INFO_SA_FULL_SERVICE)
        {
          ret |= MSIM_CARD3;
        }
    }
    #endif
    #if MCR_SIM4_SUPPORT == __CFG_YES__
    //todo..
    sim1Inserted =srv_sim_ctrl_is_inserted(MMI_SIM4);
    sim1NwAvail = srv_nw_info_get_service_availability(MMI_SIM4);
    if(sim1Inserted && sim1NwAvail ==SRV_NW_INFO_SA_LIMITED_SERVICE || sim1NwAvail==SRV_NW_INFO_SA_FULL_SERVICE)
    {
        if(!bChkNwAvail || sim1NwAvail ==SRV_NW_INFO_SA_LIMITED_SERVICE || sim1NwAvail==SRV_NW_INFO_SA_FULL_SERVICE)
        {
          ret |= MSIM_CARD4;
        }
    }
    #endif

#if MCR_WIFI_SUPPORT ==  __CFG_YES__
    if(srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED) //判断wifi是否连接，接口不同可以调整 purple
    {
        ret |= MSIM_VWIFI;
    }
#endif

    return ret;
}

#else
MINT McfSim_CheckValidSim(MINT bChkNwAvail)
{//
	MINT nValidSim = MSIM_NONE;
	/*
	 *add by charmenli 
	 *适配平台使用WIFI
	 *2012-1-13
	*/	 
#if (MCR_WIFI_SUPPORT == __CFG_YES__) && (MCR_MTK_VER <= MTK_VER_952)
	extern mmi_wlan_display_struct g_wlan_display_context;
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if MCR_SIM3_SUPPORT == __CFG_YES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if MCR_SIM4_SUPPORT == __CFG_YES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if (MCR_WIFI_SUPPORT == __CFG_YES__)&&(MCR_MTK_VER <= MTK_VER_952)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
	if(!mmi_bootup_is_sim_removed())
	{ 
	    if(!bChkNwAvail || mmi_bootup_is_sim_valid())
	    {
		  nValidSim |=MSIM_CARD1;
		}
	}
#endif
/*
 *add by charmenli 
 *适配平台使用WIFI
 *2012-1-13
*/
#if (MCR_WIFI_SUPPORT == __CFG_YES__) && (MCR_MTK_VER <= MTK_VER_952)
	if(WLAN_STATE_CONNECTED == g_wlan_display_context.state)//todo..
	{
		nValidSim |= MSIM_VWIFI;
	}
#endif/* #if (MCR_WIFI_SUPPORT == __CFG_YES__) && (MCR_MTK_VER <= MTK_VER_952)  end*/

#ifdef __MCARE_SEPERATE_NET_TASK__
	kal_prompt_trace(MOD_MCARE, "[McfSim_CheckValidSim] nValidSim = %d", nValidSim);
#endif
	return nValidSim;
}
#endif

MINT McfSim_GetValidSim(MVOID)
{
    return McfSim_CheckValidSim(MTRUE);
}



#if MCR_MTK_VER >= MTK_VER_1032
MINT McfSim_GetSimOperator(MINT simId)
{
    MCHAR plmn[8]={0};
    MINT mmiSim = MMI_SIM1;
    
    #if MCR_WIFI_SUPPORT == __CFG_YES__
    if(simId == MSIM_VWIFI)
    {
 #ifdef __MCARE_SEPERATE_NET_TASK__
        kal_prompt_trace(MOD_MCARE, "McfGetSimOperator WIFI ");

  #endif
        return MSIM_OPR_WIFI;
    }
    else
    #endif
    #if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if MCR_SIM3_SUPPORT == __CFG_YES__
    if(simId == MSIM_CARD3)
    {
        //todo..maybe: mmiSim = MMI_SIM3;
    }
    else
    #endif
    #if MCR_SIM4_SUPPORT == __CFG_YES__
    if(simId == MSIM_CARD4)
    {
        //todo..maybe: mmiSim = MMI_SIM4;
    }
    else
    #endif
    if(simId != MSIM_NONE)
    {
        mmiSim =MMI_SIM1;
    }
    if(MMI_FALSE==srv_nw_info_get_nw_plmn(mmiSim, (CHAR *) plmn, sizeof(plmn)))
    {
        srv_sim_ctrl_get_home_plmn(mmiSim, (CHAR *) plmn, sizeof(plmn));
    }

    return McfGetOperatorByPlmn(plmn);
}
#else
MINT McfSim_GetSimOperator(MINT simId)
{//EMcfSimOperator
	MCHAR *pPlmn=MNULL;

	//step 1: tag plmn ,cbm sim id according to simId
	if(simId == MSIM_CARD1)
	{
		if(gPLMN[0]!=0)
		{
			pPlmn = (MCHAR*)gPLMN;
		}
		else
		{
			pPlmn = (MCHAR*)gHomePLMNNum;
		}
	}
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if MCR_SIM3_SUPPORT == __CFG_YES__
	else if(simId ==MSIM_CARD3)
	{
		//todo..maybe:  pPlmn = 
	}
#endif

#if MCR_SIM4_SUPPORT == __CFG_YES__
	else if(simId ==MSIM_CARD4)
	{
		//todo..maybe:  pPlmn = 
	}
#endif

#if MCR_WIFI_SUPPORT == __CFG_YES__/*modify by charmenli 2012-1-13 适配老版本不能使用WIFI*/
	else if(simId ==MSIM_VWIFI )/* && (IS_STATUS_SIM1_UIM() == TRUE) || (IS_STATUS_NONE_UIM() == TRUE))*/
	{
		//pPlmn = (MCHAR*)HT_IdleAT_GetUimImsi();
#ifdef __MCARE_SEPERATE_NET_TASK__
		kal_prompt_trace(MOD_MCARE, "McfGetSimOperator WIFI ");
#endif
        return MSIM_OPR_WIFI;
	}
#endif

	else
	{
		return MSIM_OPR_UNKOWN;
	}

	//step 2: check plmn to select apn 
	return McfGetOperatorByPlmn(pPlmn);

}
#endif

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
#include "ProfilesSrvGprot.h"
#endif

MINT McfSim_IsInFlightMode(MVOID)
{
	MINT ret = MFALSE;

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
	if (!srv_mode_switch_is_network_service_available())//add by jessyzhang 原来判断有误2012-3-9
	{
		ret = MTRUE;
	}
#else
	if (mmi_bootup_get_active_flight_mode())
	{
		ret = MTRUE;
	}

#endif	

#ifdef WIN32
    ret = MFALSE;
#endif

	return ret;
}




/*=============================== SMS ==================================*/

#include "McfSms.h"
#include "McfMisc.h"
#include "McfMemory.h"
#include "MessagesResourceData.h"
#include "McfPlatform.h"

#if(MCR_MTK_VER == MTK_VER_952)	
#include "GlobalDefs.h"
#endif



#define MSMS_CALLOC(size)   MKernPool_Malloc(size)
#define MSMS_FREE(ptr)      MKernPool_Free(ptr)

static pfnMcfSmsSendCb s_pfnCallback = MNULL;
static MVOID *s_pUser = MNULL;
static MINT s_nOption = MSMS_OPT_POP;//add by rico 2011-12-31用来区分是否弹消息发送成功/失败框

#define MAX_RECIPIENT_CNT  (20)

void *__ConstructRecipients(U16 **pRecipList,char *pNumber,int *pCount)
{
    U16 *pRecipData,*pdst;
    U8 *psrc;
    U16 count;
    int i;

    if(pRecipList == MNULL ||pNumber ==MNULL ||pCount == MNULL)
    {
        return MNULL;
    }
    
    if(*pCount> MAX_RECIPIENT_CNT){
        count = MAX_RECIPIENT_CNT;
        *pCount = MAX_RECIPIENT_CNT;
    }
    else{
        count = *pCount;
    }
    
    
    pRecipData = OslMalloc((MPHB_NUMBER_LENGTH*2+2)*MAX_RECIPIENT_CNT);
    pdst = pRecipData;
    psrc = (U8*)pNumber;
    for(i=0;i<count;i++)
    {
        mmi_asc_to_ucs2((CHAR *) pdst, (CHAR *) psrc);
        pRecipList[i] = pdst;
        pdst += MPHB_NUMBER_LENGTH+1;
        psrc += MPHB_NUMBER_LENGTH+1;
    }
    return pRecipData;
}

#if MCR_MTK_VER < MTK_VER_1012

MVOID McfSmsShowResultInfo(MINT nResult)
{
	MINT nStringId = 0;
	switch(nResult)
	{
	case MMI_FRM_SMS_OK:
		//string=(MUINT8*)tmpSucc;
#if (MCR_MTK_VER >= MTK_VER_932)            
		nStringId = STR_GLOBAL_SENT;
#else
		nStringId = STR_SMS_SEND_SUCCESS;
#endif            
		break;

	case MMI_FRM_SMS_ABORT:
		//string=(MUINT8*)tmpAbort;
#if (MCR_MTK_VER >= MTK_VER_932)            
		nStringId = STR_ID_SMS_CANCELLED;
#else
		nStringId = STR_ABORT_SENDING_SMS;
#endif                         
		break;

	default:
		//string=(MUINT8*)tmpError;
		nStringId = STR_SMS_SEND_FAILED;
		break;		
	}

    if( MSMS_OPT_POP == s_nOption ) //by rico
    {
        DisplayPopup((PU8)GetString(nStringId), 0, 0, 2000, 0);
    }

	//DisplayPopup((PU8)GetString(nStringId), 0, 0, 2000, 0);
	mmi_frm_sms_delete_screen_history();        
}


MVOID McfHandleSmsEvent(MVOID* pPhoneNumber, module_type mod, MUSHORT nResult)
{
	if (!MCR_IsRunning())
	{
		return;
	}
	if(s_pfnCallback)
	{
		s_pfnCallback(s_pUser,nResult);
	}

	McfSmsShowResultInfo(nResult);

	MCR_HandleDelayedWork();
}

MINT McfSms_SendSms(MVOID *pUser,MINT nSimId,MINT nOption,const MCHAR *pNumber,
					const MCHAR*pData,MINT nDataSize,MINT  nEncodeType, 
					pfnMcfSmsSendCb sendSmsCb)
{
	mmi_frm_sms_send_struct *pSendData = MNULL;
	//mmi_sms_uc_data_struct uc_data;

	U32 nLength = 0;

	MCFAPI_SMS_PRINT(ALOG_INFO,MLOG_SDKSMS,"MSms_SendSms entry pNumber[0x%x]pData[0x%x]sendSmsCb[0x%x]pUser[0x%x]", pNumber, pData, sendSmsCb, pUser);

	s_pfnCallback = sendSmsCb;
	s_pUser = pUser;
	s_nOption = nOption; 

	if (MNULL == pNumber || MNULL == pData )
	{
		return MFALSE;
	}

	pSendData = (mmi_frm_sms_send_struct*)MSMS_CALLOC(sizeof(mmi_frm_sms_send_struct));
	if(MNULL == pSendData)
	{
		MCFAPI_SMS_PRINT(ALOG_INFO,MLOG_SDKSMS,"!!!MSms_SendSms not enough memory!");
		return MFALSE;
	}
	memset(pSendData, 0, sizeof(mmi_frm_sms_send_struct));

	/* do not display sending screen */
	pSendData->sendcheck |= MMI_FRM_SMS_SCR;	
	// 拷贝目标号码
	strncpy((char*)pSendData->number, (const char*)pNumber, strlen(pNumber));

	// 拷贝sms内容
	if(nEncodeType == MENCODE_UCS2)
	{
		nLength = mmi_ucs2strlen((char*)pData);
		pSendData->stringlength = nLength;
		pSendData->string = (S8*)OslMalloc( (nLength + 1) * 2 );//Don't free the string buffer,MUST use OslMalloc
		pSendData->dcs = SMSAL_UCS2_DCS;	
		mmi_ucs2cpy((char*)pSendData->string, (char*)pData);
	}
	else if(nEncodeType == MENCODE_ASCII)
	{
		nLength = strlen((char*)pData);
		pSendData->stringlength = nLength;
		pSendData->string = (S8*)OslMalloc( (nLength+1)*2 );//MUST use OslMalloc
		pSendData->dcs = SMSAL_DEFAULT_DCS;	
		mmi_asc_to_ucs2((S8 *) pSendData->string, (S8 *) pData);
	}
	else
	{//
		nLength = 0; 
		MCFAPI_SMS_PRINT(ALOG_INFO,MLOG_SDKSMS,"!!!MSms_SendSms unknown dcs!");
	}

	if(MNULL != pSendData->string && pSendData->stringlength > 0)
	{
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

		//mmi_frm_sms_send_sms_for_other_app(HANDLE_SmsEvent, MOD_MMI, sendData);		
		mmi_frm_sms_send_sms(McfHandleSmsEvent, MOD_MMI, pSendData);		
	}   
	else
	{
		MCFAPI_SMS_PRINT(ALOG_INFO,MLOG_SDKSMS,"!!!MSms_SendSms not enough memory2!");
	}

	MSMS_FREE(pSendData);	
	return MTRUE;
}

/*************************************
* McfSms_WriteMsg
* @pNumber --[in]destination number
* @pContent --[in]msg default content,not support now@0909,arlo
* @nSize --[in]size of msg default content,not support now
* #return none
*/
MVOID McfSms_WriteMsg(MCHAR *pNumber,MINT nNumberCnt,MWCHAR *pContent,MINT nSize)
{
    //S8 ascii_number[MAX_PB_NUMBER_LENGTH + 1 + 1];
    mmi_frm_sms_api_entry_write_struct sendData;

    if (strlen((PS8) pNumber) == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        //memset(ascii_number, 0, sizeof(ascii_number));
        memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

        //mmi_ucs2_n_to_asc((PS8)ascii_number, (PS8)number, MAX_PB_NUMBER_LENGTH + 1);
        sendData.string = NULL;
        sendData.stringlength = 0;
        sendData.dcs = 0;
        sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) pNumber;

        mmi_frm_sms_api_entry_write_msg(&sendData);
    }
}

#else


MVOID McfHandleSmsEvent(srv_sms_callback_struct* pCallbackData)
{
	MINT nStatus = -1;

	MWCHAR szSucc[]={0x53d1 ,0x9001 ,0x6210 ,0x529f ,0xff01 ,0};
	MWCHAR szError[]={0x53d1 ,0x9001 ,0x5931 ,0x8d25 ,0xff01 ,0};
	MWCHAR szAbort[]={0x653e ,0x5f03 ,0x53d1 ,0x9001 ,0xff01 ,0};	
	MWCHAR* szString =MNULL;

	if (!MCR_IsRunning())
	{
		return;
	}

	if(!pCallbackData)
	{
		return;	
	}

	MCFAPI_SMS_PRINT(ALOG_INFO,MLOG_SDKSMS, "[McfHandleSmsEvent]result %d cause %d\r\n", pCallbackData->result, pCallbackData->cause);

	if (pCallbackData->result == MMI_TRUE)
	{
		nStatus = 0;
		szString = (MWCHAR*)szSucc;

	}
	else
	{
		switch(pCallbackData->cause)
		{
		case SRV_SMS_CAUSE_SEND_ABORT:
			szString = (MWCHAR*)szAbort;
			break;

		case SRV_SMS_CAUSE_SEND_BUSY:
		case SRV_SMS_CAUSE_NOT_READY:                
		case SRV_SMS_CAUSE_MEM_FULL:
		case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
		case SRV_SMS_CAUSE_DATA_INVALID:
		case SRV_SMS_CAUSE_DATA_EXCEED:
		case SRV_SMS_CAUSE_NUMBER_EMPTY:
		case SRV_SMS_CAUSE_NUMBER_INVALID:
		case SRV_SMS_CAUSE_SC_EMPTY:
		case SRV_SMS_CAUSE_SC_INVALID:
		case SRV_SMS_CAUSE_FDL_FAIL:
		case SRV_SMS_CAUSE_AT_CONFLICT:
		case SRV_SMS_CAUSE_OP_CONFLICT:
		case SRV_SMS_CAUSE_EMAIL_NO_SPACE:
		case SRV_SMS_CAUSE_UNKNOWN_ERROR:
		default:
			szString = (MWCHAR*)szError;
			break;
		}
	}


    if( MSMS_OPT_POP == s_nOption)
    {
        DisplayPopup((U8*)szString, 0, 0, 2000, 0);
    }

	//DisplayPopup((U8*)szString, 0, 0, 2000, 0);

	if (s_pfnCallback != MNULL)
	{
		s_pfnCallback(s_pUser, nStatus);
		s_pfnCallback = MNULL;
	}

	MCR_HandleDelayedWork();
}


#define MCR_SMS_MAX_ADDR_LEN     21
void __SrvSmsSendUcs2TextMsg(S8 no_sending_icon,
        S8 *ucs2_content,
        S8 *ucs2_number,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;
    U16 content_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_handle = srv_sms_get_send_handle();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_UCS2_TEXT_MSG, sms_handle);

    srv_sms_set_address(sms_handle, ucs2_number);

    srv_sms_set_sim_id(sms_handle, sim_id);

    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_UCS2);

    content_size = mmi_ucs2strlen(ucs2_content) *ENCODING_LENGTH;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_UCS2_TEXT_MSG_1, content_size);
    srv_sms_set_content(sms_handle, ucs2_content, content_size);

    if(no_sending_icon)
    {
        srv_sms_set_no_sending_icon(sms_handle);
    }

    srv_sms_send_msg(sms_handle, callback_func, user_data);
}

MINT McfSms_SendSms(MVOID *pUser,MINT nSimId,MINT nOption,const MCHAR *pNumber,
					const MCHAR*pData,MINT nDataSize,MINT  nEncodeType, 
					pfnMcfSmsSendCb sendSmsCb)
{

	MINT nSrvSimId = SRV_SMS_SIM_1;
	MCHAR szUsc2Number[(MCR_SMS_MAX_ADDR_LEN + 1) * 2];

	if (MNULL == pNumber || MNULL == pData )
	{
		return MFALSE;
	}

	s_pfnCallback = sendSmsCb;
	s_pUser = pUser;
	s_nOption = nOption; 

	switch (nSimId)
	{
	case MSIM_CARD1:
		nSrvSimId =SRV_SMS_SIM_1;
		break;
	case MSIM_CARD2:
		nSrvSimId =SRV_SMS_SIM_2;
		break;
	case MSIM_CARD3:
		//todo..maybe :eSim = SRV_SMS_SIM_3;
		break;
	case MSIM_CARD4:
		//todo..maybe :eSim = SRV_SMS_SIM_4;
		break;
	}

	memset(szUsc2Number, 0, sizeof(szUsc2Number));
	mmi_asc_to_ucs2((MCHAR*)szUsc2Number, (MCHAR*)pNumber);

    if(nEncodeType==MENCODE_ASCII)
    {
        S8 *pUcs2Data;
        pUcs2Data = gui_malloc(1024);
        if(pUcs2Data)
        {
          mmi_asc_to_ucs2((CHAR *) pUcs2Data, (CHAR *) pData);
	      __SrvSmsSendUcs2TextMsg(MTRUE,(S8 *)pUcs2Data, (S8 *)szUsc2Number, nSrvSimId, McfHandleSmsEvent, MNULL);
          gui_free(pUcs2Data);
        }
	    //srv_sms_send_asc_text_msg((S8 *)pData, (S8 *)pNumber, nSrvSimId, McfHandleSmsEvent, MNULL);
    }
    else
    {
        __SrvSmsSendUcs2TextMsg(MTRUE,(S8 *)pData, (S8 *)szUsc2Number, nSrvSimId, McfHandleSmsEvent, MNULL);
    }


	return MTRUE;
}

#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))//purple
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcSrvGprot.h"
#include "vapp_uc_gprot.h"
#endif

#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_gprot.h"
mmi_ret McfSms_WriteMsg_onProc(mmi_event_struct * evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
            /* just close it */
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
            vcui_sms_composer_close(ucEvt->sender_id);        
            break;
        }
    }
    return MMI_RET_OK;
}
#endif
#endif

MVOID McfSms_WriteMsg(MCHAR *pNumber,MINT nNumberCnt,MWCHAR *pContent,MINT nSize)
{
    U16 *recipient[MAX_RECIPIENT_CNT];
    void *recipData;

    recipData= __ConstructRecipients(recipient, pNumber, &nNumberCnt);
    if(recipData)
    {
      #if MCR_MTK_VER >= MTK_VER_1032
       #if ((MCR_MTK_VER >=MTK_VER_1112) && (defined (__COSMOS_MMI_PACKAGE__)))   //maomaolin
    #ifdef __MMI_SMS_COMPOSER__
        mmi_id smsComposerCui = 0;
        VcuiSmsComposerEntryStruct entryData = {0};
        //VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
        //vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );
    
        // set address
        VcuiSmsComposerAddrStruct address;
        address.next = NULL;
        address.previous = NULL;
        address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
        address.addr = (VfxWChar*)pNumber; //(VfxChar*)(number.getBuf());  
        entryData.addr_num = 1;
        entryData.addr = &address;
    
        // set text
        entryData.text_buffer = (VfxWChar *)pContent;   //m_shareUrl;
        entryData.text_num = nSize; //mmi_ucs2strlen((CHAR*)m_shareUrl);
       
    	
        smsComposerCui = vcui_sms_composer_create(GRP_ID_MCARE_LIST);   //MCARE group id, refer to __EntryScreen
        if(smsComposerCui !=  GRP_ID_INVALID)
        {
            mmi_ret result;
            mmi_group_node_struct cuiInfo;
            VfxU32 userdata;

            result = mmi_frm_group_get_info(smsComposerCui, &cuiInfo);
            
            // make sure cui / scr has the same parent
            if(GRP_ID_MCARE_LIST != cuiInfo.parent)
            {
                return;
            }

            userdata = ((GRP_ID_MCARE_LIST << 16) | MCARE_SCREEN_HOME);

            mmi_frm_group_set_caller_proc(smsComposerCui, McfSms_WriteMsg_onProc, (void*)userdata);

            vcui_sms_composer_set_entry_data(smsComposerCui, &entryData);        
            //vfxSetCuiCallerScr(smsComposerCui, getMainScr());
            vcui_sms_composer_run(smsComposerCui);
        }
    #else
    
        {
            VappUcEntryStruct uc_data;
            srv_uc_addr_struct addr;
            MUSHORT Num[20] = {0};
            MUSHORT *pNum = NULL;

            pNum = Num;

            memset(&uc_data, 0, sizeof(VappUcEntryStruct));
            McfUcs2_AscToUcs2(pNum,pNumber);

            addr.next = NULL;
            addr.previous = NULL;
            addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
            addr.addr = (kal_uint8 *)pNum;
            addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;

            uc_data.addr = &addr;

            uc_data.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            uc_data.info_type = SRV_UC_INFO_TYPE_SMS;
            uc_data.operation = UC_OPERATION_WRITE_NEW_MSG;
            uc_data.type = SRV_UC_STATE_WRITE_NEW_MSG ;
            uc_data.addr_num = 1;
            uc_data.text_buffer = (U8*)pContent;
            uc_data.text_num = nSize;

            vappUcAppLauncher(&uc_data);
        }
    #endif /* __MMI_SMS_COMPOSER__ */

       #else
         mmi_sms_entry_write_sms(GRP_ID_ROOT,(S8**)recipient,nNumberCnt,pContent);
       #endif
      #else
      mmi_sms_entry_write_text_msg((S8**)recipient,nNumberCnt,pContent);
      #endif
      OslMfree(recipData);
    }
}

#endif




/*================================== Audio =====================================*/
#include "McfCommon.h"
#include "McfAudio.h"
#include "McfPlatform.h"
#include "ProfilesSrv.h" //add by charmenli


/* MMI header file */
#include "MMI_include.h"
/* MDI header file */
#include "mdi_datatype.h"
#include "mdi_audio.h"
/* Profile service header file */
#include "ProfilesSrvGprot.h"
//
/* The maximum volume level */
#ifdef __COSMOS_MMI_PACKAGE__
#define MCARE_SYS_MULTIMEDIA_MAX_VOLUME_LEVEL 16
#else
#define MCARE_SYS_MULTIMEDIA_MAX_VOLUME_LEVEL 7
#endif


typedef enum
{
  MCARE_SYS_MULTIMEDIA_STATE_READY = 0,
  MCARE_SYS_MULTIMEDIA_STATE_TERMINATED
} mcare_sys_multimedia_state_enum;

/* Multimedia context structure */
typedef struct
{
  U8 state;
  U8 volume;
} mcare_sys_multimedia_context_struct;


#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_vol_dialog_gprot.h"
#endif

#ifndef __COSMOS_MMI_PACKAGE__
static mcare_sys_multimedia_context_struct g_mcare_sys_multimedia_context;
#endif

static MBOOL g_mcare_is_playing;



typedef struct
{
	MVOID *pUser;
	pfnMcfAudFunc callback;
}MAudio;

static MAudio gMAudio;
#define MAUD_USER()     (gMAudio.pUser) 
#define MAUD_CALLBACK()  (gMAudio.callback) //
#define MAUD_VALID_HD   (0x000000ff)

#define SET_MAUD_USER(user,handler) do{ \
	MAUD_USER()=user;\
	MAUD_CALLBACK()=(handler);\
}while(0)


MVOID McfAud_MultiMediaInit(MVOID);
MVOID McfAud_MultiMediaResetData(MVOID);
U8 McfAud_MultiMediaGetCurVolume(MVOID);
MVOID McfAud_MultiMediaAdjustVolume(MMI_BOOL volume_up);
MVOID McfAud_MultiMediaVolUp(MVOID);
MVOID McfAud_MultiMediaVolDown(MVOID);
MBOOL McfAud_IsPlayingAudio(MVOID);



static MBYTE __ConvertAudVolume(MBYTE nVolume);

static MBYTE __ConvertPlayStyle(MBYTE nPlayStyle)
{
    nPlayStyle &= 0x3f;//low 6 bits are used as play mode
	switch(nPlayStyle)
	{
	case MAUD_PLAY_FOREVER:
		nPlayStyle = MDI_AUDIO_PLAY_INFINITE;
		break;

	case MAUD_PLAY_ONCE:
		nPlayStyle = MDI_AUDIO_PLAY_ONCE;
		break;

	default:
		nPlayStyle = MDI_AUDIO_PLAY_ONCE; 
		break;
	}

	return nPlayStyle;
}

static MINT __ConvertResult(MINT nRet)
{    
	switch(nRet)
	{
	case MDI_AUDIO_SUCCESS:
		nRet = MAUD_SUCCESS;
		break;

	case MDI_AUDIO_BUSY:
		nRet = MAUD_BUSY;
		break;

	case MDI_AUDIO_FAIL:
		nRet = MAUD_FAIL;
		break;

	case MDI_AUDIO_OPEN_FILE_FAIL:
		nRet = MAUD_OPEN_FILE_FAIL;
		break;

	case MDI_AUDIO_END_OF_FILE:
		nRet = MAUD_FINISH;
		break;

	case MDI_AUDIO_TERMINATED:
		nRet = MAUD_TERMINATED;
		break;

	case MDI_AUDIO_BAD_FORMAT:
		nRet = MAUD_BAD_FORMAT;
		break;

	default:
		nRet = MAUD_FAIL;
		break;
	}

	return nRet ;
}

static MINT __ConvertAudFormat(MINT nFmt)
{
    switch(nFmt)
    {
     case MAUD_MIDI:
        return MDI_FORMAT_SMF;
     case MAUD_WAV:
        return MDI_FORMAT_WAV;
     case MAUD_AMR:
        return MDI_FORMAT_AMR;
    }

    return MDI_FORMAT_NONE;
}

static MVOID __AudResultCb(MINT nRet)
{
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry,result:%d",nRet); 
	nRet = __ConvertResult(nRet);

	if(MAUD_CALLBACK())
	{
		((pfnMcfAudFunc)MAUD_CALLBACK())(MAUD_USER(),nRet);
	}

	if(nRet != MAUD_SUCCESS) 
	{
		SET_MAUD_USER(MNULL, MNULL);
	}

	MCR_HandleDelayedWork();

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave"); 
}


static MBYTE __ConvertAudVolume(MBYTE nVolume)
{
	return LEVEL1 +(nVolume - MAUD_VOL_LEVEL1);
}

MINT McfIsSilentModeActivated(MVOID)
{
#if MCR_MTK_VER < MTK_VER_1032
	return (MUINT)IsSilentModeActivated();
#else
	return (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT);
#endif
}

MINT McfIsMeetingModeActivated(MVOID)
{
#if MCR_MTK_VER < MTK_VER_1032
	return (MUINT)IsMeetingModeActivated();
#else
	return(srv_prof_get_activated_profile() == MMI_PROFILE_MEETING);
#endif
}

MBOOL __IsAudioReady(MBYTE nPlayStyle)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	//modify by charmenli  2012-5-29 新方案，只在静音、会议模式下才不播放
	if((McfIsSilentModeActivated()
		|| McfIsMeetingModeActivated()) &&((nPlayStyle & MAUD_NO_SILENT) ==0))
	{
		g_mcare_is_playing = MFALSE;
        return MFALSE;
	}
	return MTRUE;
}



/*MAud_PlayStream
*@pUser --[in]
*@pAudioData --[in]
*@len --[in] length of audio data
*@format --[in] audio data type ,EMAudType
*@playStyle --[in] 0 --once ,1 --repeat
*@handler -- [in] callback 
*# >=0 --success,audio handle if support multi instances
<0 --error
*/
MINT  McfAud_PlayStream(MVOID *pUser,MVOID *pAudioData,MUINT nLen,MBYTE nFormat,MBYTE nPlayStyle, pfnMcfAudFunc handler)
{
	MINT nRet;

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry,pUser:0x%x,pAudioData:0x%x,len:%d,format:%d",
		pUser,pAudioData,nLen, nFormat); 
	

	if(!__IsAudioReady(nPlayStyle))
	{
		return MAUD_BUSY;
	}

	//charmenli add 2012-5-29
	mdi_audio_suspend_background_play();
	//charmenli add 2012-6-8
	g_mcare_is_playing = MTRUE;
	
	//audio data format check..
	SET_MAUD_USER(pUser,handler);

	if(nFormat == MAUD_WAV)
	{
		nFormat = MDI_FORMAT_WAV;
	}
	else if(nFormat == MAUD_MIDI)
	{
		nFormat = MDI_FORMAT_SMF;
	}
	nPlayStyle =__ConvertPlayStyle(nPlayStyle);
#if MCR_MTK_VER >= MTK_VER_1112
    nRet = mdi_audio_play_string(pAudioData, nLen, nFormat, nPlayStyle, __AudResultCb, MNULL);
#else
    nRet = mdi_audio_play_string(pAudioData, nLen, nFormat, nPlayStyle, MNULL, __AudResultCb);
#endif
	

	if(nRet == MDI_AUDIO_SUCCESS)
	{
		nRet = MAUD_VALID_HD;
	}
	else
	{
		nRet = __ConvertResult(nRet);
	}

	//charmenli add 2012-5-29
	mdi_audio_resume_background_play();
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d", nRet); 
	
	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MFALSE;
	}
	
	return nRet;
}

MINT  McfAud_StopStream (MINT nAudHd)
{
	MINT nRet;

	//UNUSED_PARAM(audHd);
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry"); 
	if(nAudHd != MAUD_VALID_HD)
	{
		return MAUD_FAIL;
	}

	g_mcare_is_playing = MTRUE;

	SET_MAUD_USER(MNULL,MNULL);
	nRet = mdi_audio_stop_string();

	nRet = __ConvertResult(nRet);

	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MFALSE;
	}

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d",nRet); 

	return nRet;
}   

MINT McfAud_PlayFile(MVOID *pUser,MSHORT *pFile,MBYTE nPlayStyle, pfnMcfAudFunc handler)
{
	MINT nRet;

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry,pUser:0x%x,pFile:0x%x",pUser,pFile); 

	if(!__IsAudioReady(nPlayStyle))
	{
		return MAUD_BUSY;
	}

	//charmenli add 2012-5-29
	mdi_audio_suspend_background_play();
	
	//charmenli
	g_mcare_is_playing = MTRUE;

	SET_MAUD_USER(pUser,handler);

	nPlayStyle =__ConvertPlayStyle(nPlayStyle);
#if MCR_MTK_VER >= MTK_VER_1112
	nRet =mdi_audio_play_file(pFile, nPlayStyle, MNULL, __AudResultCb, MNULL);
#else
    nRet =mdi_audio_play_file(pFile, nPlayStyle, MNULL, __AudResultCb);
#endif
	if(nRet == MDI_AUDIO_SUCCESS)
	{
		nRet =  MAUD_VALID_HD;
	}
	else
	{
		nRet = __ConvertResult(nRet);
	}
	//charmenli add 2012-5-29
	mdi_audio_resume_background_play();

	
	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MFALSE;
	}

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d", nRet); 

	return nRet;

}
MINT  McfAud_StopFile(MINT nAudHd)
{
	MINT nRet ;

	//UNUSED_PARAM(audHd);
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry"); 
	if(nAudHd != MAUD_VALID_HD)
	{
		return MAUD_FAIL;
	}

	SET_MAUD_USER(MNULL,MNULL);
	nRet = mdi_audio_stop_file();
	nRet = __ConvertResult(nRet);

	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MFALSE;
	}

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d", nRet); 
	return nRet;
}
MINT  McfAud_Pause(MINT nAudHd,MVOID *pUser,pfnMcfAudFunc handler)
{
	MINT nRet = MAUD_FAIL;

	//UNUSED_PARAM(audHd);//
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry,pUser:0x%x",pUser); 
	if(nAudHd != MAUD_VALID_HD)
	{
		return MAUD_FAIL;
	}

	if(pUser != MAUD_USER())
	{
		if(handler) handler(pUser, MAUD_FAIL);
	}
	else
	{
		SET_MAUD_USER(pUser, handler);
#if MCR_MTK_VER >= MTK_VER_1112        
		nRet = mdi_audio_pause(__AudResultCb, 0);
#else
        nRet = mdi_audio_pause(0, __AudResultCb);
#endif
	}

	nRet = __ConvertResult(nRet);

	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MFALSE;
	}

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d",nRet); 
	return nRet;

}
MINT  McfAud_Resume(MINT nAudHd,MVOID *pUser, pfnMcfAudFunc handler)
{
	MINT nRet = MAUD_FAIL;

	//UNUSED_PARAM(audHd);//
	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" entry,pUser:0x%x",pUser); 
	if(nAudHd != MAUD_VALID_HD)
	{
		return MAUD_FAIL;
	}

	if(pUser != MAUD_USER())
	{
		if(handler) handler(pUser,MAUD_FAIL);
	}
	else
	{
		SET_MAUD_USER(pUser,handler);
#if MCR_MTK_VER >= MTK_VER_1112         
		nRet =mdi_audio_resume(__AudResultCb, 0);
#else
        nRet =mdi_audio_resume(0, __AudResultCb);
#endif
	}

	nRet = __ConvertResult(nRet);

	//charmenli add 2012-6-8
	if (MAUD_SUCCESS == nRet)
	{
		g_mcare_is_playing = MTRUE;
	}

	MCFAPI_AUDIO_PRINT(ALOG_INFO, MLOG_SDKAUDIO,__MCR_FUNCTION__" leave,ret:%d", nRet); 

	return nRet;
}

MVOID McfAud_SetVolume(MINT nAudHd ,MBYTE nVolume)
{
	//UNUSED_PARAM(audHd);//
	if(nAudHd != MAUD_VALID_HD)
	{
		return;
	}

	if(nVolume == MAUD_VOL_MUTE)
	{
		mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
	}
	else
	{
		nVolume = __ConvertAudVolume(nVolume);
		mdi_audio_set_volume(MDI_VOLUME_MEDIA, nVolume);
	}
}

MVOID McfAud_StopAll(MVOID)
{
	mdi_audio_stop_all();
}

/***********************************
* McfAud_StartRecord
*@pUser --[in]
*@pRecord --[in] record info,such as target format,filename, size ,time limit
*@fnAudRecd --[in]callback function to notify user
*#return 
*/
MINT McfAud_StartRecord(MVOID *pUser,McfAudRecord *pRecord,pfnAudFunc fnAudRecd)
{
    MINT nFmt;
    
    nFmt = __ConvertAudFormat(pRecord->nFormat);
#if MCR_MTK_VER < MTK_VER_1112    
    if(MDI_AUDIO_SUCCESS== mdi_audio_start_record_with_limit(pRecord->pFilename, nFmt, pRecord->nQuality, MNULL,
                                    __AudResultCb, pRecord->nSizeLmt, pRecord->nTimeLmt))
#else
    if(MDI_AUDIO_SUCCESS== mdi_audio_start_record_with_limit(pRecord->pFilename, nFmt, pRecord->nQuality,
                                    __AudResultCb, MNULL, pRecord->nSizeLmt, pRecord->nTimeLmt))
#endif
    {
    	SET_MAUD_USER(pUser,fnAudRecd);
        return 0;
    }
    else
    {
        return MAUD_FAIL;
    }
}

MINT McfAud_StopRecord(MINT nHd)
{
    MINT nRet = 0;
    SET_MAUD_USER(MNULL,MNULL);
    nRet = mdi_audio_stop_record();

    return __ConvertResult(nRet);
}


/*************************************************
* MAud_GetDuration
* @pDuration --[out]media duration,in seconds
* @nType --[in] MAUD_SRC_FILE-source is filename,MAUD_SRC_BUFFER--source is audio data
* @pSource --[in]maybe source filename or data,depends on nType
* @nFormat --[in]source audio format,valid when nType is MAUD_SRC_BUFFER
* @nLen --[in]source audio data len,valid when nType is MAUD_SRC_BUFFER 
* #return MAUD_SUCCESS --get the media duration
MAUD_FAIL       --cannot get 
*/
MINT McfAud_GetDuration(MUINT *pDuration, MINT nType,MVOID *pSource,MINT nFormat,MINT nLen)
{
    U32 nDuration = 0;
    MINT nFmt;
	MINT nRet = MCR_FAIL;
   
	if(pDuration)
	{
		//file name type
		if(nType == MAUD_SRC_FILE)
		{
			nRet = mdi_audio_get_duration(pSource, pDuration);
		}
		//buffer type
		else
		{
			nFmt = __ConvertAudFormat(nFormat);
			nRet = mdi_audio_get_duration_by_string((kal_uint8 *)pSource, nLen, (U8) nFmt, pDuration);
		}
	}

    return nRet;
}

MVOID McfAud_MultiMediaInit(MVOID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    memset(&g_mcare_sys_multimedia_context, 0, sizeof(mcare_sys_multimedia_context_struct));
#endif
    McfAud_MultiMediaResetData();
}


/*****************************************************************************
 * FUNCTION
 *  McfAud_MultiMediaResetData
 * DESCRIPTION
 *  Reset context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MVOID McfAud_MultiMediaResetData(MVOID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    g_mcare_sys_multimedia_context.state = MCARE_SYS_MULTIMEDIA_STATE_TERMINATED;
    g_mcare_sys_multimedia_context.volume = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  McfAud_MultiMediaGetCurVolume
 * DESCRIPTION
 *  This interface is used to get current volume and should be called in MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current volume
 *****************************************************************************/
U8 McfAud_MultiMediaGetCurVolume(MVOID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__

    return MDI_AUD_VOL_EX_MUTE(MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol()));

#else

    if (g_mcare_sys_multimedia_context.state == MCARE_SYS_MULTIMEDIA_STATE_TERMINATED)
    {
        g_mcare_sys_multimedia_context.state = MCARE_SYS_MULTIMEDIA_STATE_READY;
        g_mcare_sys_multimedia_context.volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
    }

    return MDI_AUD_VOL_MUTE(g_mcare_sys_multimedia_context.volume);

#endif /* __COSMOS_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  McfAud_MultiMediaAdjustVolume
 * DESCRIPTION
 *  This interface is used to adjust volume and should be called in MMI task.
 *  When user presses side key, Opera should always call this API to check and
 *  adjust volume.
 * PARAMETERS
 *  volume_up   [IN]        MMI_TRUE: volume up; MMI_FALSE: volume down
 * RETURNS
 *  void
 *****************************************************************************/
MVOID McfAud_MultiMediaAdjustVolume(MMI_BOOL volume_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL update = MMI_FALSE;
#ifdef __COSMOS_MMI_PACKAGE__
    srv_prof_setting_struct setting;
    U8 volume;
	MMI_BOOL app_is_playing;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__

    volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());

    if (volume_up)
    {
        if (volume < MCARE_SYS_MULTIMEDIA_MAX_VOLUME_LEVEL)
        {
            volume++;
            update = MMI_TRUE;
        }
    }
    else
    {
        if (volume > 0)
        {
            volume--;
            update = MMI_TRUE;
        }
    }

    app_is_playing = vapp_volume_dialog_is_media_type();

    if (update && (app_is_playing || McfAud_IsPlayingAudio()))
    {
        srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &setting);
        setting.media_vol = (srv_prof_volume_level)volume;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &setting);
 
        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &setting);
        setting.media_vol = (srv_prof_volume_level)volume;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &setting);

        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(volume));

        if (app_is_playing)
        {
            mdi_audio_set_volume(MDI_VOLUME_FMR, MDI_AUD_VOL_EX_MUTE(volume));
        }
    }

#else /* __COSMOS_MMI_PACKAGE__ */

    if (McfAud_IsPlayingAudio())
    {
        if (volume_up)
        {
            if (g_mcare_sys_multimedia_context.volume < MCARE_SYS_MULTIMEDIA_MAX_VOLUME_LEVEL)
            {
                g_mcare_sys_multimedia_context.volume++;
                update = MMI_TRUE;
            }
        }
        else
        {
            if (g_mcare_sys_multimedia_context.volume > 0)
            {
                g_mcare_sys_multimedia_context.volume--;
                update = MMI_TRUE;
            }
        }

        if (update)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(g_mcare_sys_multimedia_context.volume));
        }
    }

#endif /* __COSMOS_MMI_PACKAGE__ */
}


MVOID McfAud_MultiMediaVolUp(MVOID)
{
	McfAud_MultiMediaAdjustVolume(MTRUE);
}
MVOID McfAud_MultiMediaVolDown(MVOID)
{
	McfAud_MultiMediaAdjustVolume(MFALSE);
}

MBOOL McfAud_IsPlayingAudio(MVOID)
{
	return g_mcare_is_playing;
}





/*================================ UnZip ======================================*/
#include "McfCommon.h"
#include "McfGZip.h"
#include "McfMemory.h"
#include "McfPlatform.h"
//#include "../../util/app_zlib.h"

#define UnzipIntMalloc(size)		MKernPool_Malloc(size)
#define UnzipIntSafeFree(p)			MKernPool_Free(p)


#define Unzip_Decompressor_BufferSize (5*1024)		// 解压缓存大小

//内部结果码
#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_VERSION_ERROR (-6)
#define Z_DEFLATED   8

#define Z_NO_FLUSH      0

#define ASCII_FLAG   0x01 /* bit 0 set: file probably ascii text */
#define HEAD_CRC     0x02 /* bit 1 set: header CRC present */
#define EXTRA_FIELD  0x04 /* bit 2 set: extra field present */
#define ORIG_NAME    0x08 /* bit 3 set: original file name present */
#define COMMENT      0x10 /* bit 4 set: file comment present */
#define RESERVED     0xE0 /* bits 5..7: reserved */


#ifndef MAX_WBITS
#define MAX_WBITS   15 /* 32K LZ77 window */
#endif
#define ZLIB_VERSION "1.1.3"

//#define inflateInit(strm)   mcf_inflateInit__((strm),ZLIB_VERSION, sizeof(mcf_z_stream)) 
//#define inflateInit2(strm)   mcf_inflateInit2__((strm),-MAX_WBITS ,ZLIB_VERSION, sizeof(mcf_z_stream))


static const MCHAR gz_magic[2] = {0x1f, 0x8b}; /* gzip magic header */

extern int mcf_inflateInit__(mcf_z_streamp z,const char *version,int stream_size);
extern int mcf_inflate_(mcf_z_streamp z, int f);
extern int mcf_inflateInit2__(mcf_z_streamp z,int w,const char *version,int stream_size);
extern int mcf_inflateReset_(mcf_z_streamp z);
extern int mcf_inflateEnd_(mcf_z_streamp z);
extern int mcf_appzlib_register_(_alloc_func alloc_hdlr, _free_func free_hdlr);


typedef struct
{
	mcf_z_stream	m_stream;
	MINT		m_mode; //压缩方式
	MCHAR*		m_pOutBuffer;		// 存放解压后数据的缓存
	MCHAR*		m_RemainData;		// 上一次没解压完的数据 或 未完整接收的GZip头
	MCHAR*		m_CombineBuffer;	//用于合并 m_RemainData 和 本次需要解压的数据

	MINT		m_pOutBufferLen;	// 存放解压后数据的大小

	MINT		m_RemainDataLen;	// m_RemainData中的数据大小	
	MINT		m_CombineBufferSize;

	MBOOL		m_bIdle;			
	MBOOL		m_bGZipHeadGot;		// GZip头已完整接收到
	MBOOL		m_bGZipBodyGot;		// GZip中的数据已全部解压

	funzip_alloc_func		funzip_Malloc;//分配函数
	funzip_free_func		funzip_Free;//释放函数

}_Unzip_Decompressor;



static MINT __CheckHead(MCHAR* pBuff, MINT bufLen, MCHAR**ppTar, MINT* realDataLen)
{
	MCHAR* p = pBuff;
	MCHAR method = 0;
	MCHAR flags = 0;
	MUINT remainLen = bufLen;

	if (remainLen<10)
		return 2;

	if (p[0] != gz_magic[0] ||
		p[1] != gz_magic[1] )
		return 1;
	p += 2;

	method = *p++;
	flags = *p++;
	if (method != Z_DEFLATED || (flags & RESERVED) != 0)
		return 1;

	/* Discard time, xflags and OS code: */
	p += 6;
	remainLen -= 10;

	if ((flags & EXTRA_FIELD) != 0)
	{	/* skip the extra field */
		MINT low=0,high=0,len=0;
		if (remainLen<2)
			return 2;
		remainLen -= 2;
		low = *p++;
		high = *p++;
		len = (high<<8) + low;
		p+=len;
		remainLen -= len;
		if ( remainLen < 0 )
			return 2;
	}
	if ((flags & ORIG_NAME) != 0)
	{	/* skip the original file name */
		while (*p != 0)
		{
			++p;
			--remainLen;
			if ( 0 == remainLen )
			{
				return 2;
			}
		}
		++p;
		--remainLen;
	}
	if ((flags & COMMENT) != 0)
	{   /* skip the .gz file comment */
		while (*p != 0)
		{
			++p;
			--remainLen;
			if ( 0 == remainLen )
			{
				return 2;
			}
		}
		++p;
		--remainLen;
	}
	if ((flags & HEAD_CRC) != 0)
	{  /* skip the header crc */
		if (remainLen<2)
		{
			return 2;
		}
		p += 2;
		remainLen -= 2;
	}

	*ppTar = p;
	*realDataLen = bufLen-(p-pBuff);

	return 0;
}

static MINT __Uninit(MVOID* pDecompressor)
{
	_Unzip_Decompressor* pthis=(_Unzip_Decompressor*)pDecompressor;
	if (pthis->m_bIdle)
		return MFALSE;

	mcf_inflateEnd_(&(pthis->m_stream));
	memset( &(pthis->m_stream), 0, sizeof(mcf_z_stream) );

	((funzip_free_func)(pthis->funzip_Free))(pthis->m_RemainData);
	pthis->m_RemainDataLen = 0;
	((funzip_free_func)(pthis->funzip_Free))(pthis->m_CombineBuffer);
	pthis->m_CombineBufferSize = 0;
	pthis->m_bGZipHeadGot = MFALSE;
	pthis->m_bGZipBodyGot = MFALSE;
	pthis->m_bIdle = MTRUE;
	return MTRUE;
}


static MINT __Init(MVOID* pDecompressor, MINT mode)
{
	MINT err = 0;
	_Unzip_Decompressor* pthis=(_Unzip_Decompressor*)pDecompressor;

	if ( MNULL == pthis)
		return MFALSE;

	__Uninit(pthis);

	pthis->m_mode = mode;
	if ( Unzip_DMode_Deflate == mode)
	{
		err = mcf_inflateInit__(&pthis->m_stream, ZLIB_VERSION, sizeof(mcf_z_stream)) ;
	}
	else if ( Unzip_DMode_GZip == mode )
	{
		err = mcf_inflateInit2__(&pthis->m_stream, -MAX_WBITS ,ZLIB_VERSION, sizeof(mcf_z_stream));
	}
	else
	{
		return MFALSE;
	}
	if ( Z_OK != err )
	{
		memset(&pthis->m_stream,0,sizeof(mcf_z_stream));
		return MFALSE;
	}
	pthis->m_bIdle = MFALSE;
	return MTRUE;
}



MVOID* McfUnzip_Create(funzip_alloc_func allocFunc, funzip_free_func freeFunc , MINT nBufferSize)
{
	MCHAR* pBuffer = MNULL;
	_Unzip_Decompressor* pDecompressor = MNULL;
		
	if(allocFunc == MNULL || freeFunc == MNULL)
	{
		return MNULL;
	}

	pDecompressor = (_Unzip_Decompressor*)UnzipIntMalloc(sizeof(_Unzip_Decompressor));
	if ( MNULL == pDecompressor)
	{
		return MNULL;
	}

	memset(pDecompressor, 0, sizeof(_Unzip_Decompressor));
	mcf_appzlib_register_(allocFunc, freeFunc);

	pDecompressor->m_pOutBufferLen= Unzip_Decompressor_BufferSize;
	pDecompressor->funzip_Malloc = allocFunc;
	pDecompressor->funzip_Free = freeFunc;

	if (nBufferSize>0)
	{
		pDecompressor->m_pOutBufferLen= nBufferSize;
	}

	pBuffer = (MCHAR*)((funzip_alloc_func)(pDecompressor->funzip_Malloc))(pDecompressor->m_pOutBufferLen);
	if (MNULL == pBuffer)
	{
		UnzipIntSafeFree(pDecompressor);
		return MNULL;
	}

	memset(pBuffer,0,pDecompressor->m_pOutBufferLen);
	pDecompressor->m_pOutBuffer = pBuffer;

	if(MTRUE != __Init(pDecompressor, Unzip_DMode_GZip))
	{
		McfUnzip_Destroy(pDecompressor);
		return MNULL;
	}

	return (_Unzip_Decompressor*)pDecompressor;
}



MINT McfUnzip_SetData(MVOID* pUnZipInfo, MCHAR* pData, MINT nDataLen)
{
	_Unzip_Decompressor* pthis=(_Unzip_Decompressor*)pUnZipInfo;
	if (MNULL==pthis || MNULL==pData|| nDataLen<=0 || MNULL==pthis->m_pOutBuffer)
		__Uninit(pthis);

	if ( pthis->m_bIdle )
		return MFALSE;

	((funzip_free_func)(pthis->funzip_Free))(pthis->m_CombineBuffer);
	pthis->m_CombineBufferSize = 0;

	// 合并缓存
	if ( pthis->m_RemainData && pthis->m_RemainDataLen>0 )
	{
		pthis->m_CombineBufferSize = pthis->m_RemainDataLen + nDataLen;
		pthis->m_CombineBuffer =(MCHAR*) ((funzip_alloc_func)(pthis->funzip_Malloc))(pthis->m_CombineBufferSize);
		if ( MNULL == pthis->m_CombineBuffer )
		{
			__Uninit(pthis);
			return MFALSE;
		}
		memcpy(pthis->m_CombineBuffer, pthis->m_RemainData, pthis->m_RemainDataLen);
		memcpy(pthis->m_CombineBuffer+pthis->m_RemainDataLen, pData, nDataLen);

		((funzip_free_func)(pthis->funzip_Free))(pthis->m_RemainData);
		pthis->m_RemainData = MNULL;
		pthis->m_RemainDataLen = 0;

		pData = pthis->m_CombineBuffer;  //这块原来的内存释放问题需要检查
		nDataLen = pthis->m_CombineBufferSize;
	}

	// 检查GZip头
	if ( Unzip_DMode_GZip==pthis->m_mode && !pthis->m_bGZipHeadGot )
	{
		MCHAR* pRealData = MNULL;
		MINT realDataLen = 0;
		MINT result = __CheckHead(pData, nDataLen, &pRealData, &realDataLen);
		if ( 1 == result )	// 数据错误
		{
			__Uninit(pthis);
			return MFALSE;
		}
		if ( 2 == result )	// 数据不够
		{
			if (pthis->m_CombineBuffer)
			{
				pthis->m_RemainData = pthis->m_CombineBuffer;
				pthis->m_RemainDataLen = pthis->m_CombineBufferSize;
				pthis->m_CombineBuffer = MNULL;
				pthis->m_CombineBufferSize = 0;
			}
			else
			{
				pthis->m_RemainData = (MCHAR*)((funzip_alloc_func)(pthis->funzip_Malloc))(nDataLen);
				if ( MNULL == pthis->m_RemainData )
				{
					__Uninit(pthis);
					return MFALSE;
				}
			}
		}
		else	// 成功
		{
			pthis->m_bGZipHeadGot = MTRUE;
			pData = pRealData;
			nDataLen = realDataLen;
		}
	}

	pthis->m_stream.next_in = (MBYTE*)pData;
	pthis->m_stream.avail_in = nDataLen;

	return MTRUE;
}


MINT McfUnzip_Uncompress(MVOID* pUnZipInfo, MCHAR** ppData, MINT* pDataLen)
{
	MINT oldTotalOut = 0;
	MINT oldAvailIn = 0;
	MINT ret = 0;
	MINT code = Unzip_DCoder_Success_CallAgain;
	_Unzip_Decompressor* pthis=(_Unzip_Decompressor*)pUnZipInfo;

	if (MNULL==pthis || MNULL==ppData || MNULL==pDataLen || MNULL==pthis->m_pOutBuffer )
		__Uninit(pthis);

	if ( pthis->m_bIdle )
		return Unzip_DCoder_Fail_Data;

	if ( Unzip_DMode_GZip == pthis->m_mode && !pthis->m_bGZipHeadGot)
	{
		return Unzip_DCoder_Success_Ok;
	}

	oldTotalOut = pthis->m_stream.total_out;
	oldAvailIn = pthis->m_stream.avail_in;
	pthis->m_stream.next_out = (MBYTE*)pthis->m_pOutBuffer;
	pthis->m_stream.avail_out = pthis->m_pOutBufferLen - 4;		//末尾留0，以便外部处理

	ret = mcf_inflate_( &pthis->m_stream, Z_NO_FLUSH);			//解压
	*ppData = pthis->m_pOutBuffer;
	*pDataLen = pthis->m_stream.total_out - oldTotalOut;

	if ( Z_STREAM_END == ret )
	{
		// 解压结束
		__Uninit(pthis);
		code = Unzip_DCoder_Success_StreamEnd;
	}
	else if ( ret < 0 )
	{
		if ( Z_BUF_ERROR == ret )
		{
			code = Unzip_DCoder_Success_Ok;	// 需要新数据
		}
		else
		{
			// 解压失败
			__Uninit(pthis);
			if ( Z_MEM_ERROR == ret )
				code = Unzip_DCoder_Fail_Memory;
			else
				code = Unzip_DCoder_Fail_Data;
		}
	}
	else if ( Z_OK == ret )
	{
		if ( pthis->m_stream.avail_in==oldAvailIn &&
			pthis->m_stream.total_out==oldTotalOut)
		{
			code = Unzip_DCoder_Success_Ok;	
		}
		else	// 一次SetData的数据已经解完
		{
			code = Unzip_DCoder_Success_CallAgain;
		}
	}

	if ( Unzip_DCoder_Success_Ok == code )
	{
		if (pthis->m_stream.avail_in )			// 需要新数据才能解压，保存遗留数据
		{
			((funzip_free_func)(pthis->funzip_Free))(pthis->m_RemainData);
			pthis->m_RemainData = (MCHAR*)((funzip_alloc_func)(pthis->funzip_Malloc))(pthis->m_stream.avail_in );
			if ( MNULL == pthis->m_RemainData )
			{
				__Uninit(pthis);
				code = Unzip_DCoder_Fail_Memory;
			}
			pthis->m_RemainDataLen = pthis->m_stream.avail_in;
			memcpy( pthis->m_RemainData, pthis->m_stream.next_in, pthis->m_stream.avail_in );
		}
	}

	return code;
}


MINT McfUnzip_Destroy(MVOID* pUnZipInfo)
{
	MINT ret = MCR_FAIL;
	_Unzip_Decompressor* pThis=(_Unzip_Decompressor*)pUnZipInfo;

	if (MNULL == pThis)
		return ret;

	__Uninit(pThis);

	((funzip_free_func)(pThis->funzip_Free))(pThis->m_pOutBuffer);
	UnzipIntSafeFree(pThis);

	ret = MCR_SUCCESS; 
	return ret;
}






/*============================= Idle ====================================*/
#include "McfIdle.h"
#include "McfPlatform.h"


#define MICON_MALLOC(size)   MKernPool_Malloc(size)
#define MICON_FREE(ptr)      MKernPool_Free(ptr)


#ifdef __MMI_TOUCH_SCREEN__
static pfnIconFunc s_pFunc;
#endif  


static MSHORT __GetStatusIconById(MSHORT nIconId)
{
	switch(nIconId)
	{
	case MIDLE_ICON_QQ_ONLINE:
		return STATUS_ICON_QQ_ONLINE;

	case MIDLE_ICON_QQ_OFFLINE:
		return STATUS_ICON_QQ_OFFLINE;

	case MIDLE_ICON_QQ_AWAYLINE:
		return STATUS_ICON_QQ_AWAYLINE;

	case MIDLE_ICON_QQ_INVISBLE:
		return STATUS_ICON_QQ_INVISBLE;

	case MIDLE_ICON_QQ_HAVEMSG:
		return STATUS_ICON_QQ_HAVEMSG;

	case MIDLE_ICON_CONTACT:
		return STATUS_ICON_CONTACT_ON;

	default:
		return STATUS_ICON_MCARE;
	}
}


#define ICON_STACK_MAXSIZE		(10)

typedef struct
{
	MINT nIconId;
	MINT nIconStatus;//显示或闪烁！！
}IconStruct;

typedef struct
{
	MVOID*		stackPtr[ICON_STACK_MAXSIZE];
	MINT		stackTop;
}IconMgr;

static IconMgr *pIconMgr = MNULL;

MINT McfIdle_Init(MVOID)
{
	if(MNULL != pIconMgr)
	{
		MICON_FREE(pIconMgr);
		pIconMgr = MNULL;
	}

	pIconMgr = (IconMgr *)MICON_MALLOC(sizeof(IconMgr));
	if(pIconMgr)
	{
		memset(pIconMgr, 0, sizeof(IconMgr));
	}
}

MVOID McfIdle_Deinit(MVOID)
{
	MINT i = 0;

	if(MNULL != pIconMgr)
	{
		for(i = 0; i < pIconMgr->stackTop; i++)
		{
			IconStruct *pIconStruct = (IconStruct*)pIconMgr->stackPtr[i];
			if(pIconStruct)
			{
				MICON_FREE(pIconStruct);
				pIconStruct = MNULL;
			}
		}

		pIconMgr->stackTop = 0;

		MICON_FREE(pIconMgr);
		pIconMgr = MNULL;
	}
}

static MBOOL __IconStackPush(MVOID* p)
{
	if(MNULL == pIconMgr || pIconMgr->stackTop >= ICON_STACK_MAXSIZE)
	{
		return MFALSE;
	}

	pIconMgr->stackPtr[pIconMgr->stackTop] = p;
	pIconMgr->stackTop++;

	return MTRUE;	
}

static MVOID* __IconStackTop(MVOID)
{

	if(pIconMgr && pIconMgr->stackTop > 0)
	{
		return pIconMgr->stackPtr[pIconMgr->stackTop - 1];
	}
	return MNULL;
}

static MVOID __IconStackRemoveId(MINT nIconId)
{
	MINT i = 0, j = 0, sum = 0;
	IconStruct *pIconStruct = MNULL;

	for(i = 0; i < pIconMgr->stackTop; i++)
	{
		pIconStruct = (IconStruct *)pIconMgr->stackPtr[i];
		if(pIconStruct && pIconStruct->nIconId == nIconId)
		{
			MICON_FREE(pIconStruct);
			pIconStruct = MNULL;
			pIconMgr->stackPtr[i] = MNULL;

			for(j = i; j < pIconMgr->stackTop - 1; j++)
			{
				pIconMgr->stackPtr[j] = pIconMgr->stackPtr[j + 1];	
			}

			pIconMgr->stackTop--;
			
			//重新从0开始检查，检查重复的问题！
			i = -1;
		}
	}
}


MVOID *__IconMaloc(MINT nIconId, MINT nFlag)
{
	//把ICON状态压栈！
	IconStruct *pIcon = (IconStruct *)MICON_MALLOC(sizeof(IconStruct));
	if(pIcon)
	{
		memset(pIcon, 0, sizeof(IconStruct));
		pIcon->nIconId = nIconId;
		pIcon->nIconStatus = nFlag;
	}

	return pIcon;
}

//add by rico
static MSHORT g_icon = 0;

MVOID McfIdle_SetStatusIcon(MSHORT nIconId,MINT nFlag)
{
	/*
	 *add by charmenli 2012-2-21
	 *修复点击平台的后退，comos下拉状态栏不显示QQ的问题
	*/
	if (0 == nIconId)
	{
		return;
	}
	/*************   add end  ***********/
    g_icon  = nIconId;  //vivexu
	nIconId = __GetStatusIconById(nIconId);

	if(nFlag == MIDLE_ICON_SHOW)
	{
		if(nIconId != STATUS_ICON_CONTACT_ON)  //add by jessy
		{
		//先隐藏原来的！！！
		IconStruct *pIcon = (IconStruct *)__IconStackTop();
		if(pIcon)
		{
			HideStatusIcon(pIcon->nIconId);
		}

		//把新ICON状态压栈！
		pIcon = __IconMaloc(nIconId, nFlag);
		if(pIcon)
		{
			__IconStackPush(pIcon);
		}

#if (MCR_MTK_VER >=1112)//purple
        McrNcenterStateChange(MTRUE); 
#endif
		}

		ShowStatusIcon(nIconId);
		
	}
	else if(nFlag == MIDLE_ICON_HIDE)
	{
		IconStruct *pIcon = MNULL;

		HideStatusIcon(nIconId);

		if(nIconId != STATUS_ICON_CONTACT_ON)  //add by jessy
		{
		//出栈！！！
		__IconStackRemoveId(nIconId);

		//获取栈顶icon状态以及显示！！！
		pIcon = (IconStruct *)__IconStackTop();
		if(pIcon)
		{
			if(pIcon->nIconStatus == MIDLE_ICON_SHOW)
			{
				ShowStatusIcon(pIcon->nIconId);
			}
			else if(pIcon->nIconStatus == MIDLE_ICON_BLINK)
			{
				BlinkStatusIcon(pIcon->nIconId);
			}
		}

#if (MCR_MTK_VER >=1112)
        McrNcenterStateChange(MFALSE); 
#endif
		}
		
	}
	else if(nFlag == MIDLE_ICON_BLINK)
	{
		if(nIconId != STATUS_ICON_CONTACT_ON)	//add by jessy
		{
			//先隐藏原来的！！！
			IconStruct *pIcon = (IconStruct *)__IconStackTop();
			if(pIcon)
			{
				HideStatusIcon(pIcon->nIconId);
			}
	
			//把ICON状态压栈！
			pIcon = __IconMaloc(nIconId, nFlag);
			if(pIcon)
			{
				__IconStackPush(pIcon);
			}

#if (MCR_MTK_VER >=1112)  //purple
        	McrNcenterStateChange(MTRUE);
#endif		
		}

#if (MCR_BLACKLIGHT_TURNON == __CFG_YES__)

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
    srv_backlight_turn_on(1);
#else
	TurnOnBacklight(1);
#endif
#endif

#if MCR_MTK_VER >= 1012  // by purple
        ShowStatusIcon(nIconId);
#endif
		BlinkStatusIcon(nIconId);
		
	}
	//add by charmenli 2012-6-5 设完ICON后刷新
	McfIdle_UpdateStatusIcons();
}

MVOID McfIdle_UpdateStatusIcons(MVOID)
{
	UpdateStatusIcons();
}

static MVOID __HandleIconCb(MVOID)
{
#if (0)
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}

#if (MCR_MTK_VER >=MTK_VER_1112)
static MINT g_eIcon = 0;

MINT McfStatusIcon_getIconId(MVOID)
{
#if (MCR_MTK_VER == MTK_VER_1144)//add by charmenli 修正由于添加1144适配导致1112版本，下拉显示不正常 2012-3-9
     g_eIcon = g_icon ;
#endif
    return g_eIcon;
}

extern U16 mmi_frm_group_get_active_id(void);
extern MMI_BOOL mmi_frm_group_is_present (U16 group_id);
MVOID McfStatusIcon_PressedTimerEventProc(MVOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	if(MCR_PreEntryCheck() == 0)//charmenli add 2012-6-8
	{
		mcare_cnf_exit();
		McfScrnDisplayDesktop();
		return;
	}
	while(mmi_frm_group_is_present(GRP_ID_MCARE_LIST) && (GRP_ID_MCARE_LIST != mmi_frm_group_get_active_id()))//add by charmenli2012-05-28
	{
		mmi_frm_group_hide(mmi_frm_group_get_active_id());
	}
    if (MNULL != s_pFunc)
	{
		(s_pFunc)(McfStatusIcon_getIconId());
	}
#endif
}

MUINT McfIsStatusIconShow(MSHORT nIconId)
{
	MUINT nFlag;
	nIconId = __GetStatusIconById(nIconId);//cvt to plat icon 
	nFlag = get_status_icon_flag(nIconId);

	return (nFlag & GUI_STATUS_ICON_BAR_ICON_DISPLAY);   
}

#endif

/*
*modify by charmenli 2012-2-20 修正36 comos下拉图标显示不正常问题
*/
#if (MCR_MTK_VER >= 1012)
#define MCR_ICON_DISPLAY 	GUI_STATUS_ICON_BAR_ICON_DISPLAY
#define MCR_ICON_BLINK		GUI_STATUS_ICON_BAR_ICON_BLINK
#define McrStatusIconReisterPenEventHandler wgui_status_icon_bar_register_pen_event_handler
#else
#define MCR_ICON_DISPLAY 	STATUS_ICON_DISPLAY
#define MCR_ICON_BLINK		STATUS_ICON_BLINK
#define McrStatusIconReisterPenEventHandler 	wgui_register_status_icon_pen_event_hdlr

#endif      

MVOID McfIdle_RegIconPenEventHdlr(pfnIconFunc pFunc)
{
#ifdef __MMI_TOUCH_SCREEN__

	MUINT nFlag;
	MINT i= 0;
	MINT nIconId;

	if(!pFunc)
	{
		return;
	}

	for(i = MIDLE_ICON_MCARE; i < MIDLE_ICON_TOTAL-1; i++) //modified by jessy
	{
		nIconId = __GetStatusIconById(i);//cvt to plat icon 
		nFlag = get_status_icon_flag(nIconId);

		if((nFlag & MCR_ICON_DISPLAY) ||(nFlag & MCR_ICON_BLINK))
		{

#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))
	     g_eIcon = i;  //by vivexu
#endif		
         s_pFunc = pFunc;
		 McrStatusIconReisterPenEventHandler((S16)nIconId, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, (FuncPtr)__HandleIconCb);

        }
        else
        {
            s_pFunc = pFunc;
            McrStatusIconReisterPenEventHandler((S16)nIconId, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, (FuncPtr)__HandleIconCb);
        }
	}
#endif
}
/************************************* 修正36 comos下拉图标显示不正常问题 end*********************************************/
MVOID McfIdleRegistePressIconCb(MVOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	if(s_pFunc)
	{	
		McfIdle_RegIconPenEventHdlr(s_pFunc);	
	}
#endif
}

MBOOL McfIdle_IsStatusIconShow(MSHORT nIconId)
{
	MUINT nFlag;
	nIconId = __GetStatusIconById(nIconId);//cvt to plat icon 
	nFlag = get_status_icon_flag(nIconId);

#if (MCR_MTK_VER >= MTK_VER_1012)
	return (nFlag & GUI_STATUS_ICON_BAR_ICON_DISPLAY);   
#else
	return (nFlag & STATUS_ICON_DISPLAY);
#endif
}


MBOOL McfIdle_IsStatusIconBlink(MSHORT nIconId)
{
	MUINT nFlag;
	nIconId = __GetStatusIconById(nIconId);//cvt to plat icon 
	nFlag = get_status_icon_flag(nIconId);

#if (MCR_MTK_VER >= MTK_VER_1012)
	return (nFlag & GUI_STATUS_ICON_BAR_ICON_BLINK);
#else
	return (nFlag & STATUS_ICON_BLINK);
#endif	
}



/*=================================== Memory =======================================*/
#include "McfMemory.h"
#include "MAdpConfig.h"
#include "McfPlatform.h"
#include "McfTrace.h"
//#include "McfMemDebug.h"
#include "MAdpConfig.h"


static MUINT g_nStaticSize = 0;
static MUINT g_nStaticMemId = 0;
static MVOID *g_pStaticMemBaseBuffer = MNULL;

#ifdef MCR_MEM_DEBUG
extern MUINT McfMemDebug_PoolCreate(MVOID* pMem, MUINT nSize);
extern MINT McfMemDebug_PoolDelete(MUINT nPoolId);
extern MVOID* McfMemDebug_PoolMalloc(MUINT nPoolId, MUINT nSize, MCHAR *pFilename, MINT nLineno);
extern MVOID McfMemDebug_PoolFree(MUINT nPoolId, MVOID *pMem, MCHAR *pFilename, MINT nLineno);
extern MUINT McfMemDebug_PoolGetMaxAllocSize(MUINT nPoolId);
#endif

//主存使用静态内存
#if ( (MCR_MEM_MAIN == MCR_MEMTYPE_STATIC) || (MCR_MEM_KERNRESER == MCR_MEMTYPE_STATIC) || (MCR_MEM_APPRESER == MCR_MEMTYPE_STATIC))
static MUINT g_staticMemBuf[MCR_MEM_STATIC_TOTAL>>2];
#endif

//内存初始化
static MINT __MediaInit(MVOID)
{
	return MCR_SUCCESS;
}

static MVOID __StopCallback(MVOID)
{
	//vive for memory 
	MCR_ExitTencentMCare();
}

#include "MAdpMenuDef.h"
static MINT __AsmInit(MVOID)
{
#if (MCR_MTK_VER <  MTK_VER_1210)
#if ((MCR_MEM_MAIN == MCR_MEMTYPE_ASM)||(MCR_MEM_KERNRESER == MCR_MEMTYPE_ASM)||(MCR_MEM_APPRESER == MCR_MEMTYPE_ASM))
	applib_mem_ap_register(APPLIB_MEM_AP_ID_MCARE, STR_MCARE_MAIN, IMG_GLOBAL_L1, __StopCallback);
#endif
 #endif
	return MCR_SUCCESS;
}

static MINT __StaticInit(MVOID)
{
	MINT nReuslt = MCR_FAIL;

#if ((MCR_MEM_MAIN == MCR_MEMTYPE_STATIC) || (MCR_MEM_KERNRESER == MCR_MEMTYPE_STATIC)|| (MCR_MEM_APPRESER == MCR_MEMTYPE_STATIC))

	MLONG* pMemBase = MNULL;
	MULONG nMemLen = 0;

	pMemBase = (long*)g_staticMemBuf;
	nMemLen = sizeof(g_staticMemBuf);

	if(pMemBase)
	{
		//memset(pMemBase, 0, nMemLen);
		g_nStaticSize = nMemLen;
		g_pStaticMemBaseBuffer  = pMemBase;

		g_nStaticMemId = McfMem_PoolCreate(g_pStaticMemBaseBuffer, g_nStaticSize);
		if(g_nStaticMemId != 0)
		{
			nReuslt = MCR_SUCCESS;
		}
	}
#endif

	return nReuslt;
}


//内存初始化
static MINT __MediaDeinit(MVOID)
{
	return MCR_SUCCESS;
}

static MINT __AsmDeinit(MVOID)
{
#if (MCR_MTK_VER <  MTK_VER_1210)
#if ((MCR_MEM_MAIN == MCR_MEMTYPE_ASM) || (MCR_MEM_KERNRESER == MCR_MEMTYPE_ASM) || (MCR_MEM_APPRESER == MCR_MEMTYPE_ASM))
	applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MCARE, MTRUE);
#endif
#endif

	return MCR_SUCCESS;
}

static MINT __StaticDeinit(MVOID)
{
	MINT nReuslt = MCR_FAIL;

#if ((MCR_MEM_MAIN == MCR_MEMTYPE_STATIC) || (MCR_MEM_KERNRESER == MCR_MEMTYPE_STATIC)|| (MCR_MEM_APPRESER == MCR_MEMTYPE_STATIC))

	if(g_nStaticMemId != 0)
	{
		McfMem_PoolDelete(g_nStaticMemId);
		g_nStaticMemId = 0;
	}
#endif


	return nReuslt;
}


static MINT __MCareGetMemType(MINT nMemStyle)
{
	MINT nMemType = 0;

	switch(nMemStyle)
	{
	case MMEM_MAIN:
		nMemType = MCR_MEM_MAIN;
		break;

	case MMEM_KERN:
		nMemType = MCR_MEM_KERNRESER;
		break;

	case MMEM_APP:
		nMemType = MCR_MEM_APPRESER;
		break;

	default:
		break;
	}

	return nMemType;
}


static MVOID * __MCareMalloc(MINT nMemType, MINT nSize)
{
	MVOID* pBuffer = MNULL;
	switch(nMemType)
	{
	case MCR_MEMTYPE_MEDIA:
		pBuffer = (MVOID*)med_alloc_ext_mem(nSize);

		break;

	case MCR_MEMTYPE_ASM:
    #if (MCR_MTK_VER >= MTK_VER_1210)
		//pBuffer = mmi_frm_asm_alloc_r(GRP_ID_MCARE_LIST,nSize);
		pBuffer = mmi_frm_asm_alloc_r(APP_TENCENT_MCARE,nSize);
    #else
		pBuffer = (MVOID*)applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MCARE, nSize);
    #endif
		break;

	case MCR_MEMTYPE_STATIC:
		if(g_nStaticMemId != 0)
		{
			pBuffer = (MVOID*)McfMem_PoolMalloc(g_nStaticMemId, nSize);
		}
		break;

	default:
		break;
	}

	if(pBuffer)
	{
		memset(pBuffer, 0, nSize);
	}

	return pBuffer;
}

static MVOID __MCareFree(MINT nMemType, MVOID * pMem)
{
	MVOID* pBuffer = MNULL;

	if(MNULL == pMem)
	{
		return;
	}

	switch(nMemType)
	{
	case MCR_MEMTYPE_MEDIA:
		med_free_ext_mem(&pMem);
		break;

	case MCR_MEMTYPE_ASM:

    #if (MCR_MTK_VER >= MTK_VER_1210)
		//mmi_frm_asm_free_r(GRP_ID_MCARE_LIST,pMem);
		mmi_frm_asm_free_r(APP_TENCENT_MCARE,pMem);
    #else
		applib_mem_ap_free(pMem);
    #endif

		break;

	case MCR_MEMTYPE_STATIC:
		if(g_nStaticMemId != 0)
		{
			McfMem_PoolFree(g_nStaticMemId, pMem);
		}
		break;

	default:
		break;
	}
	

	return;
}

//内存初始化
MINT McfMem_Init(MVOID)
{
	__MediaInit();
	__AsmInit();
	__StaticInit();

	return MCR_SUCCESS;
}


MINT McfMem_Deinit(MVOID)
{
	__MediaDeinit();
	__AsmDeinit();
	__StaticDeinit();

	return MCR_SUCCESS;
}

//内存申请
MVOID *McfMem_Malloc(MINT nMemStyle, MUINT nSize)
{
	MBYTE *pBuffer = MNULL;
	MINT nMemType = 0;

	nMemType = __MCareGetMemType(nMemStyle);
	pBuffer = __MCareMalloc(nMemType, nSize);

	return pBuffer;
}

//主存释放
MVOID McfMem_Free(MINT nMemStyle, MVOID * pMem)
{
	MINT nMemType = 0;

	nMemType = __MCareGetMemType(nMemStyle);
	__MCareFree(nMemType, pMem);
}


MUINT McfMem_PoolCreate(MVOID* pMem, MUINT nSize)
{
#ifdef MCR_MEM_DEBUG
	return (MUINT)McfMemDebug_PoolCreate((MVOID *)pMem, nSize);
#else	
	return (MUINT)kal_adm_create((MVOID *)pMem, (kal_uint32)nSize, MNULL, MFALSE);
#endif
}

MINT McfMem_PoolDelete(MUINT nPoolId)
{
#ifdef MCR_MEM_DEBUG
	return McfMemDebug_PoolDelete(nPoolId);
#else
	return (MINT)kal_adm_delete((KAL_ADM_ID)nPoolId);	
#endif
}

MVOID* McfMem_PoolMalloc(MUINT nPoolId, MUINT nSize)
{
	return McfMem_PoolMallocDebug(nPoolId,  nSize,  MNULL, 0);
}


MVOID* McfMem_PoolMallocDebug(MUINT nPoolId, MUINT nSize, MCHAR *pFileName, MINT nLineNo)
{
#ifdef MCR_MEM_DEBUG
	return McfMemDebug_PoolMalloc(nPoolId, nSize, pFileName, nLineNo);
#else

	MVOID* pMem = MNULL;

	pMem = (MVOID*)kal_adm_internal_alloc((KAL_ADM_ID)nPoolId, (kal_uint32)nSize, MNULL, 0);
	if(pMem)
	{
		memset(pMem, 0, nSize);
	}
	MCFAPI_MEMORY_PRINT(ALOG_INFO,MLOG_SDKMEMORY,__MCR_FUNCTION__"OUT McfMem_PoolMalloc");
	//////////////////////////////////////////////////////////////////////////
	return pMem;
#endif
}

MVOID McfMem_PoolFree(MUINT nPoolId, MVOID *pMem)
{
	McfMem_PoolFreeDebug(nPoolId, pMem, MNULL, 0);
}

MVOID McfMem_PoolFreeDebug(MUINT nPoolId, MVOID *pMem, MCHAR *pFileName, MINT nLineNo)
{
#ifdef MCR_MEM_DEBUG
	McfMemDebug_PoolFree(nPoolId, pMem, pFileName, nLineNo);
#else
	kal_adm_free((KAL_ADM_ID)nPoolId, (MVOID *)pMem);
#endif
}


MUINT McfMem_PoolGetTotalLeftSize(MUINT nPoolId)
{
#ifdef MCR_MEM_DEBUG
	return (MUINT)McfMemDebug_PoolGetTotalLeftSize(nPoolId);
#else
	return (MUINT)kal_adm_get_total_left_size((KAL_ADM_ID)nPoolId);	
#endif
}

MUINT McfMem_PoolGetMaxAllocSize(MUINT nPoolId)
{
#ifdef MCR_MEM_DEBUG
	return (MUINT)McfMemDebug_PoolGetMaxAllocSize(nPoolId);
#else
	return (MUINT)kal_adm_get_max_alloc_size((KAL_ADM_ID)nPoolId);
#endif
}





/*=========================== Editor ===============================*/
#include "McfEditor.h"
#include "McfSys.h"
#include "McfMemory.h"
#include "McfKey.h"
#include "McfPlatform.h"
#include "McfTrace.h"


typedef struct _EditorInfo
{
	MVOID  *pUser;
	MWCHAR *pBuffer;
	MINT    nSize;
	MWCHAR *pDefaultTxt;
	pfnMcfInputCb callback;
	MUINT   nInputType;
	MINT	nScrId;
	MBOOL	bIsLocked;
}sEditorInfo;

static sEditorInfo gEditorInfo;

#define MCF_EDITOR_CALLOC(size)    MKernPool_Malloc(size)
#define MCF_EDITOR_FREE(ptr)	   MKernPool_Free(ptr)

#if (MCR_MTK_VER>=MTK_VER_1210)
MINT g_InputMode = 0;
MINT g_ShowEdit = 0;
#endif

MINT __SetInputType(MINT nInputType)
{
	MINT nRet = MCR_FAIL;
	switch(nInputType)
	{
	case MEDITOR_TYPE_PASSWORD:
#if (MCR_MTK_VER < MTK_VER_828)
		nRet = INPUT_TYPE_ALPHANUMERIC_PASSWORD|INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
#else
		nRet = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
#endif
		break;

	case MEDITOR_TYPE_NUMBERS:
#if (MCR_MTK_VER < MTK_VER_828)
		nRet = INPUT_TYPE_NUMERIC;
#else
		nRet = IMM_INPUT_TYPE_NUMERIC;
#endif		
		break;

	case MEDITOR_TYPE_LETTER:
#if (MCR_MTK_VER < MTK_VER_840)
		nRet = INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
#else
		nRet = IMM_INPUT_TYPE_URL;
#endif
		break;

	case MEDITOR_TYPE_UNKOWN:
#if (MCR_MTK_VER < MTK_VER_840)
		nRet = INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
#else
		nRet = IMM_INPUT_TYPE_URL;
#endif
		break;

	case MEDITOR_TYPE_CHARACTER:
#if (MCR_MTK_VER<MTK_VER_828)
		nRet = INPUT_TYPE_SM_PINYIN;
#else
		nRet = IMM_INPUT_TYPE_SENTENCE;
#endif
		break;

	default:
#if (MCR_MTK_VER<MTK_VER_828)
		nRet = INPUT_TYPE_SM_PINYIN;
#else
		nRet = IMM_INPUT_TYPE_SENTENCE;
#endif
		break;
	}

#if (MCR_MTK_VER>=MTK_VER_1210)
   if( MEDITOR_TYPE_NUMBERS == nInputType )
   {
        nRet = IMM_INPUT_TYPE_NUMERIC;
        g_InputMode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
   }
   else if( MEDITOR_TYPE_CHARACTER == nInputType )
   {
        nRet = IMM_INPUT_TYPE_SENTENCE;
        g_InputMode = IMM_INPUT_MODE_SM_PINYIN;
   }
   else if ( MEDITOR_TYPE_MTKEDIT == nInputType )
   {
        nRet = IMM_INPUT_TYPE_SENTENCE;
        g_InputMode = IMM_INPUT_MODE_SM_PINYIN;
        g_ShowEdit = 1;
   }
   else
   {
        nRet = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        g_InputMode = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
   }
#endif
	

	return nRet;
}


MINT __SetInputTypeEx(MINT nInputType, MINT nPorperty)
{
	MINT nRet = MCR_SUCCESS;//MCR_FAIL;   //maomaolin mofify 2012-01-05

	if(nInputType & MEDITOR_SYMBOLS)   //maomaolin
	{
#if (MCR_MTK_VER < MTK_VER_840)
		nRet |= INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
#else
		nRet |= IMM_INPUT_TYPE_URL;
#endif
	}

	if(nInputType & MEDITOR_LETTERS)
	{
#if (MCR_MTK_VER < MTK_VER_840)
		nRet |= INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
#else
		nRet |= IMM_INPUT_TYPE_URL;
#endif
	}

	if(nInputType & MEDITOR_NUMBERS)
	{
#if (MCR_MTK_VER < MTK_VER_840)
		nRet |= INPUT_TYPE_NUMERIC;
#else
		nRet |= IMM_INPUT_TYPE_NUMERIC;
#endif
	}

	if(nInputType & MEDITOR_PINYIN)
	{
#if (MCR_MTK_VER < MTK_VER_840)
		nRet |= INPUT_TYPE_SM_PINYIN;
#else
		nRet |= IMM_INPUT_TYPE_SENTENCE;
#endif
	}

	if(nInputType & MEDITOR_STROKE)
	{
#if (MCR_MTK_VER < MTK_VER_840)
		nRet |= INPUT_TYPE_SM_PINYIN;
#else
		nRet |=IMM_INPUT_TYPE_SENTENCE;
#endif
	}


	if(nPorperty == MEDITOR_PROPERTY_PASSWORD)
	{
		#if (MCR_MTK_VER < MTK_VER_828)
		nRet = INPUT_TYPE_ALPHANUMERIC_PASSWORD|INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
		#else
		nRet = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
		#endif
	}

	return nRet;
}

MVOID McfKey_EndKeyDownHandle(MVOID);
MVOID McfEditor_HandleHomeKeyEvent(MVOID);
MVOID McfEditor_HandleRightSoftEvent(MVOID);


MBOOL g_mcare_is_in_editor = MFALSE;
static MBYTE McfEditor_HistoryDel(MVOID* p)
{
	U16 nKeyCode, nKeyType;
	GetkeyInfo(&nKeyCode, &nKeyType);

	if( g_mcare_is_in_editor && KEY_EVENT_DOWN == nKeyType && (
		KEY_END == nKeyCode
		#ifdef __COSMOS_MMI_PACKAGE__
		|| KEY_HOME == nKeyCode
		#endif
		))
	{
		McfEditor_HandleRightSoftEvent();
		McfKey_EndKeyDownHandle();
		//McfEditor_HandleHomeKeyEvent();
	}
		
#if MCR_MTK_VER >= MTK_VER_1132 //purple
	McfClearDelScrCallBackFunc(GRP_ID_MCARE_LIST, gEditorInfo.nScrId, McfEditor_HistoryDel);
#else
	ClearDelScrnIDCallbackHandler(gEditorInfo.nScrId, McfEditor_HistoryDel);
#endif

	MCF_EDITOR_FREE(gEditorInfo.pBuffer);
	memset(&gEditorInfo,0,sizeof(sEditorInfo));	
	g_mcare_is_in_editor = MFALSE;
	return 0;
}

static MVOID McfEditor_HandleLeftSoftEvent(MVOID)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");
	if(MNULL != gEditorInfo.callback)
	{
		gEditorInfo.callback(gEditorInfo.pUser, gEditorInfo.pBuffer, mmi_ucs2strlen((const S8*)(gEditorInfo.pBuffer)), MKEY_SOFT1);
	}

	MCF_EDITOR_FREE(gEditorInfo.pBuffer);
	memset(&gEditorInfo, 0, sizeof(sEditorInfo));	
	//gMCF_EDITORInfo.isLocked = MFALSE;
	McfGoBackHistory(); //by purple

	//goback will trigger resume routine,and go into MCR_HandleDelayedWork,
	//so no need MCR_HandleDelayedWork(); here...

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");
}

static MVOID McfEditor_HandleRightSoftEvent(MVOID)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");

	if(MNULL != gEditorInfo.callback)
	{
		gEditorInfo.callback(gEditorInfo.pUser, gEditorInfo.pDefaultTxt, mmi_ucs2strlen((const S8*)(gEditorInfo.pDefaultTxt)), MKEY_SOFT2);
	}
	MCF_EDITOR_FREE(gEditorInfo.pBuffer);
	memset(&gEditorInfo,0,sizeof(sEditorInfo));	

	g_mcare_is_in_editor = MFALSE;
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" GoBackHistory before");

	//gMCF_EDITORInfo.isLocked = MFALSE;
	McfGoBackHistory(); //by purple

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" GoBackHistory after");

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");
}


MINT active_editor_x;
MINT active_editor_y;
MINT active_editor_width;
MINT active_editor_height;

#if MCR_MTK_VER >= MTK_VER_1210 
wgui_editor_struct *g_EditPtr = MNULL;
MINT app_height = 0;
MINT g_IMUIHeight = 0;
MBOOL g_IsFloat = MFALSE;
MINT g_IMUIHeight_n = 0;
MINT appheight_n = 0;
MINT g_ResizeHight = 0;

extern pfnPenHandler gMcrHandlePenEvt;
//wgui_editor_history_struct singleline_editor_history;

MVOID __resumeFunc(MVOID);
MVOID __inactiveFunc(MVOID);

#ifdef __MMI_TOUCH_SCREEN__
void __PenDown(mmi_pen_point_struct sPos);
void __PenUp(mmi_pen_point_struct sPos);
void __PenMove(mmi_pen_point_struct sPos);
#endif
MINT McfGdi_GetCharHeight(MVOID);


#define MCF_MTKEDIT_HEIGHT 16
//#define MCF_RESIZE_HEIGHT  (McfGdi_GetCharHeight()*3+2)


MVOID RestoreAdpKeyHandler(MVOID);

MVOID McfEditor_Reset_Handle(MVOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	if(gMcrHandlePenEvt )
	{
    	mmi_pen_register_down_handler((mmi_pen_hdlr)__PenDown);
    	mmi_pen_register_up_handler((mmi_pen_hdlr)__PenUp);
    	mmi_pen_register_move_handler((mmi_pen_hdlr)__PenMove);
	}
#endif
RestoreAdpKeyHandler();
}

MVOID McfEditor_Reset_Data(MVOID)
{
    active_flag = 0;//reset active flag
    g_IMUIHeight = 0;
    app_height = 0;
    g_IMUIHeight_n = 0;
    appheight_n = 0;

	g_ResizeHight = 0;
	g_ShowEdit = 0;
}

MVOID McfEditor_IMUI_Exit(MVOID)
{
    if(MNULL != g_EditPtr )
    {
        kal_prompt_trace(MOD_SMS,"mcare wgui_editor_close \n");
        wgui_editor_close((wgui_editor_struct *)g_EditPtr);

		MCF_EDITOR_FREE(g_EditPtr);
		g_EditPtr=MNULL;

        McfEditor_Reset_Data();
        McfEditor_Reset_Handle();
    }
}

MVOID McfEditor_Exit(MVOID)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");
    kal_prompt_trace(MOD_SMS,"mcare McfEditor_Exit \n");
	active_flag = 0;//reset active flag
	if(MNULL != gEditorInfo.callback)
	{
		gEditorInfo.callback(gEditorInfo.pUser, gEditorInfo.pBuffer, mmi_ucs2strlen((const S8*)(gEditorInfo.pBuffer)), MEDITOR_MSG_EXIT);
	}

	MCF_EDITOR_FREE(gEditorInfo.pBuffer);
	memset(&gEditorInfo, 0, sizeof(sEditorInfo));	
	
    McfEditor_Reset_Data();
	
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");
}

MVOID McfEditor_Free(MVOID)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");
	if(MNULL != gEditorInfo.pBuffer)
	{
    	MCF_EDITOR_FREE(gEditorInfo.pBuffer);
    	memset(&gEditorInfo, 0, sizeof(sEditorInfo));	
	}

    g_ShowEdit = 0;
   
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");

}


MVOID McfEditor_Input(MVOID)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");
	if(MNULL != gEditorInfo.callback)
	{
		gEditorInfo.callback(gEditorInfo.pUser, gEditorInfo.pBuffer, mmi_ucs2strlen((const S8*)(gEditorInfo.pBuffer)), MEDITOR_MSG_INPUT);
	}
	
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");
}


MVOID McfEditor_UI_Update(MEditRangeInfo* pRInfo)
{
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Entry");
	if(MNULL != gEditorInfo.callback)
	{
		gEditorInfo.callback(gEditorInfo.pUser, pRInfo, mmi_ucs2strlen((const S8*)(gEditorInfo.pBuffer)), MEDITOR_MSG_UIUPDATE);
	}
	
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" Leave");
}


MVOID McfEditor_Set_Clip(MVOID)
{
    gdi_layer_set_clip(0, 0, UI_device_width, app_height);
}

MVOID McfEditor_Reset_Clip(MVOID)
{
    gdi_layer_set_clip(0, 0, UI_device_width, UI_device_height);
}

MVOID McfEditor_Update_FloatUI(MVOID)
{
    MINT edit_height = 0;
    edit_height = MCF_MTKEDIT_HEIGHT + McfGdi_GetCharHeight();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	app_height = app_height + edit_height; 
	McfEditor_Input();
	app_height = app_height - edit_height; 

}

MVOID McfEditor_Redraw_FloatUI(MVOID)
{
	//gdi_lcd_freeze(TRUE);
	if(g_ShowEdit)
	{
		McfEditor_Reset_Clip();
		wgui_editor_show(g_EditPtr);
	}

	if( IMM_INPUT_MODE_SM_PINYIN == g_InputMode
	&& g_IsFloat == MTRUE )
	{
		McfEditor_Update_FloatUI();
	}
	//gdi_lcd_freeze(FALSE);
}

static MUINT McfEditor_msg_call_back(void *input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    MUINT nResult = 0;

    kal_prompt_trace(MOD_SMS,"mcare McfEditor_msg_call_back in\n");
    kal_prompt_trace(MOD_SMS,"mcare McfEditor_msg_call_back message_id =%d\n",msg_ptr->message_id);

    switch (msg_ptr->message_id)
    {
        case MMI_IMC_MESSAGE_REDRAW:
			McfEditor_Redraw_FloatUI();
            break;
        case MMI_IMC_MESSAGE_SET_KEY:
            if( 0 != g_IMUIHeight )
            {
			    McfEditor_Input();
			}
            break;
        case MMI_IMC_MESSAGE_ACTIVATE:
            break;
        case MMI_IMC_MESSAGE_DEACTIVATE:
            break;
        case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
			{

				MINT imui_height = ((mmi_imc_rect*)msg_ptr->param_1)->height;
                MEditRangeInfo nR;
                MINT edit_height = 0;
                
                /* app height */
                app_height = UI_device_height - imui_height-1;
                /* relayout screen compoents */
                edit_height = MCF_MTKEDIT_HEIGHT + McfGdi_GetCharHeight();
                //g_IMUIHeight_n = imui_height;
				appheight_n = 0; //if app_height is changed,no need add the clip;

                if ( g_ShowEdit && 0!=imui_height )
                {
                    app_height = app_height-edit_height;
					wgui_editor_set_pos(g_EditPtr,0,app_height+1);
					wgui_editor_set_size(g_EditPtr,UI_device_width,edit_height);
					McfEditor_Reset_Clip();
	                wgui_editor_show(g_EditPtr);			
                }
                else
                {
                    if( IMM_INPUT_MODE_SM_PINYIN == g_InputMode 
                        && imui_height > g_IMUIHeight_n 
                        && 0 != g_IMUIHeight)
                    {
						g_IsFloat = MTRUE;
                        app_height = app_height - edit_height; //foat height is nearly as edit height
                    }
					else
					{
						g_IsFloat = MFALSE;
					}
                }

                nR.m_nX = 0;
                nR.m_nY = app_height;
                nR.m_nWidth = UI_device_width;
                nR.m_nHeight = imui_height;

				if( 0==imui_height )
				{
					active_flag = 0;
					McfEditor_Exit();
					gui_start_timer(30,McfEditor_IMUI_Exit);
					//__inactiveFunc();
					//__resumeFunc();

				}
				else
				{	
				    if( 0 == g_IMUIHeight )
				    {
                        g_IMUIHeight = imui_height;
                    }
                    g_IMUIHeight_n = imui_height;
                    McfEditor_UI_Update(&nR);
					McfEditor_Redraw_FloatUI();
				}


				nResult=1;

			}
            break;
      #ifdef __MMI_TOUCH_SCREEN__
        case MMI_IMC_MESSAGE_PEN_EVENT:
			{
				if (active_flag &&
					PEN_CHECK_BOUND(
								((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
								((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
								active_editor_x,
								active_editor_y,
								active_editor_width,
								active_editor_height))
				{

					return 1;
				}
			}
			#endif
        default:
            return nResult;
    }

    kal_prompt_trace(MOD_SMS,"mcare McfEditor_msg_call_back out\n");
    
    return  nResult;

}

void McfEditor_pen_down_handler(mmi_pen_point_struct pos)
{ /* pass pen event to editor/ime first */ 
	McfEditor_Reset_Clip();

	if( 0 != g_IMUIHeight && g_IMUIHeight_n == g_IMUIHeight )
	{
		app_height = app_height - g_ResizeHight;
		appheight_n = 1;
	}
#ifdef __MMI_TOUCH_SCREEN__
	if (wgui_editor_process_pen(pos, MMI_PEN_EVENT_DOWN))
	{
		return; 
	}
	else
	{
	    __PenDown(pos);
	}
#endif
}

void McfEditor_pen_move_handler(mmi_pen_point_struct pos)
{ /* pass pen event to editor/ime first */ 
#ifdef __MMI_TOUCH_SCREEN__
	if (wgui_editor_process_pen(pos,MMI_PEN_EVENT_MOVE ))
	{
		return; 
	}
	else
	{
	    __PenMove(pos);
	}
#endif
}

void McfEditor_pen_long_tap_handler(mmi_pen_point_struct pos)
{ /* pass pen event to editor/ime first */ 
#ifdef __MMI_TOUCH_SCREEN__
	if (wgui_editor_process_pen(pos,MMI_PEN_EVENT_LONG_TAP ))
	{
		return; 
	}
#endif
}

void McfEditor_pen_up_handler(mmi_pen_point_struct pos) 
{ 
	McfEditor_Reset_Clip();

	if( appheight_n )
	{
		app_height = app_height + g_ResizeHight;
	}
	appheight_n = 0;

#ifdef __MMI_TOUCH_SCREEN__
	if (wgui_editor_process_pen(pos, MMI_PEN_EVENT_UP)) 
	{
		McfEditor_Input();
		return; 
	}
	else
	{
        if(MNULL != g_EditPtr&&1==active_flag)
        {
            wgui_editor_deactivate(g_EditPtr);
            McfEditor_Exit();
            McfEditor_IMUI_Exit();
            //__inactiveFunc();
            //__resumeFunc();
        }

		__PenUp(pos);
	}
#endif
}

void McfEditor_draw_imui_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
      /* draw imui background here*/
      gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(255, 82, 81, 82));
}

#ifdef MMI_IME_V3_SUPPORT
#define MCR_GUI_VKBD_PEN_V3_SUPPORT
#endif

static MVOID McfEditorInScr_Entry(MVOID)
{
#if MCR_MTK_VER >= MTK_VER_1210 
{
    MUINT nSize = 0;
    wgui_editor_struct *editor_ptr = MNULL;
    //mmi_imm_input_type_enum input_type = 0;
    
#if defined( __MMI_TOUCH_SCREEN__ ) && defined( MCR_GUI_VKBD_PEN_V3_SUPPORT ) //add for disable navgation key
	mmi_imm_allowed_character_list_struct list = {0};
	int i = 0;
#endif
	

    kal_prompt_trace(MOD_SMS,"mcare McfEditorInScr_Entry in\n");
	McfEditor_IMUI_Exit();

	mmi_pen_register_down_handler(McfEditor_pen_down_handler);
	mmi_pen_register_up_handler(McfEditor_pen_up_handler);
	mmi_pen_register_move_handler(McfEditor_pen_move_handler);
	mmi_pen_register_long_tap_handler(McfEditor_pen_long_tap_handler);

    nSize = wgui_editor_get_memory_size(WGUI_EDITOR_SINGLELINE);
    editor_ptr = (wgui_editor_struct*)MCF_EDITOR_CALLOC(nSize);

    wgui_editor_create(
                editor_ptr,
                WGUI_EDITOR_SINGLELINE,
                0,
                0,
                0,
                0,
                (UI_string_type)gEditorInfo.pBuffer,
                gEditorInfo.nSize,
        MMI_TRUE,
                GDI_NULL_HANDLE
                );
	wgui_editor_set_is_draw_ime_floating_indicator(MMI_FALSE);
	wgui_editor_set_imui_background_filler(McfEditor_draw_imui_background);
	



    g_EditPtr = editor_ptr;  
    active_flag = 1;   
	g_ResizeHight = (McfGdi_GetCharHeight()*3+10);
    wgui_editor_set_IME(editor_ptr,gEditorInfo.nInputType, 0, NULL,g_InputMode, McfEditor_msg_call_back);
#if defined( __MMI_TOUCH_SCREEN__ ) && defined( MCR_GUI_VKBD_PEN_V3_SUPPORT )//add for disable navgation key
	for(i = 0; i< MMI_IMM_MAX_DISABLE_CHARACTER_NUM; i++)
	{
	 list.disabled_events[i] = GUI_VKBD_PEN_NONE;
	 list.allowed_events[i] = GUI_VKBD_PEN_NONE;
	}
	list.disabled_events[0] = GUI_VKBD_PEN_V3_MOVE_LEFT;
	list.disabled_events[1] = GUI_VKBD_PEN_V3_MOVE_RIGHT;
	mmi_imm_set_disabled_and_allowed_character_list((mmi_imm_allowed_character_list_struct_p)&list);
	mmi_imm_set_allowed_and_disabled_list_vk(MMI_TRUE);
#endif
	wgui_editor_activate(editor_ptr, MMI_TRUE);
#if defined( __MMI_TOUCH_SCREEN__ ) && defined( MCR_GUI_VKBD_PEN_V3_SUPPORT )//add for disable navgation key
	mmi_imm_set_allowed_and_disabled_list_vk(MMI_FALSE);
#endif

    kal_prompt_trace(MOD_SMS,"mcare McfEditorInScr_Entry out\n");

}
#endif

}

#endif

extern pBOOL IsBackHistory;
extern MINT __EntryScreen(U16 scrnId, pfnFunc exitFunc, pfnDelFunc deleteFunc, pfnFunc entryFunc, MVOID * flag);


MVOID McfEditor_HandleHomeKeyEvent(MVOID)
{
	McfEditor_HandleRightSoftEvent();
	mmi_idle_display();
}
static MVOID McfEditor_Entry(MVOID)
{
	MBYTE* guiBuffer = MNULL;

	if(mmi_is_redrawing_bk_screens()==1)
	{
		color c;

		c.r = 0;
		c.g = 0;
		c.b = 0;
		c.alpha = 100;
		clear_screen_with_color(c);
		return;	
	}

#if MCR_MTK_VER >= MTK_VER_1132 //by purple
        //return (MUINT8*)mmi_frm_scrn_get_gui_buf (GRP_ID_MCARE_LIST, (MMI_ID) scrid);
	guiBuffer = (MBYTE*)mmi_frm_scrn_get_gui_buf (GRP_ID_MCARE_LIST, (MMI_ID) gEditorInfo.nScrId);	
#else
	if(IsBackHistory)
	{
		guiBuffer = (MBYTE*)GetCurrGuiBuffer(gEditorInfo.nScrId);	
	
	}
#endif
	

	gEditorInfo.nScrId = __EntryScreen(MCARE_SCREEN_EDITOR, MNULL,McfEditor_HistoryDel,(pfnFunc)McfEditor_Entry, MNULL);

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" gEditorInfo.nScrId = %d", gEditorInfo.nScrId);

	ShowCategory5Screen(0,0,STR_GLOBAL_OK,0,STR_GLOBAL_BACK,0,
		gEditorInfo.nInputType,(U8*)gEditorInfo.pBuffer, (gEditorInfo.nSize / 2), guiBuffer);

	//add by charmenli 
	g_mcare_is_in_editor = MTRUE;
	SetLeftSoftkeyFunction(McfEditor_HandleLeftSoftEvent, KEY_EVENT_UP);
	SetCategory5RightSoftkeyFunction(McfEditor_HandleRightSoftEvent, KEY_EVENT_UP);	 //todo
	//SetKeyHandler(McfEditor_HandleRightSoftEvent, KEY_END, KEY_EVENT_DOWN);
	SetKeyHandler(McfEditor_HandleHomeKeyEvent, KEY_END, KEY_EVENT_DOWN);
	SetKeyHandler(McfEditor_HandleHomeKeyEvent, KEY_HOME, KEY_EVENT_DOWN);
}

MINT McfEditor_EnterEditor(IN MVOID *pUser,IN MINT nInputType,IN MUSHORT nMaxNum,IN MWCHAR* pDefstr,IN pfnMcfInputCb handler)
{

	if(0 == nMaxNum|| gEditorInfo.bIsLocked)
	{
		return MCR_FAIL;
	}
	else
	{
		if(gEditorInfo.pBuffer)
		{
			MCF_EDITOR_FREE(gEditorInfo.pBuffer);
		}

		gEditorInfo.nSize = (nMaxNum+1)*2;
		gEditorInfo.pBuffer = MCF_EDITOR_CALLOC(gEditorInfo.nSize * 2);
		memset( gEditorInfo.pBuffer, 0, gEditorInfo.nSize * 2);

		gEditorInfo.pDefaultTxt= (MWCHAR*)((MCHAR*)(gEditorInfo.pBuffer) + gEditorInfo.nSize);//
		if(gEditorInfo.pBuffer ==MNULL)
		{
			return MCR_FAIL;
		}
		gEditorInfo.bIsLocked = MTRUE;
		gEditorInfo.callback = handler;
		gEditorInfo.pUser = pUser;
		gEditorInfo.nInputType = __SetInputType(nInputType);

		//memset(gMCF_EDITORInfo.pBuffer,0,gMCF_EDITORInfo.pBuffer);

		if(pDefstr!=MNULL)
		{
			mmi_ucs2ncpy((char*)gEditorInfo.pBuffer,(char*)pDefstr, nMaxNum);
			mmi_ucs2ncpy((char*)gEditorInfo.pDefaultTxt,(char*)pDefstr, nMaxNum);
		}


		McfEditor_Entry();
	}

	return MCR_SUCCESS;
}



MINT McfEditor_EnterEditorEx(MVOID *pUser, MINT nInputType, MINT nPorperty, MUSHORT nMaxNum, MWCHAR* pDefstr, pfnMcfInputCb handler)
{
	if(0 == nMaxNum|| gEditorInfo.bIsLocked)
	{
		return MCR_FAIL;
	}
	else
	{
		if(gEditorInfo.pBuffer)
		{
			MCF_EDITOR_FREE(gEditorInfo.pBuffer);
		}

		gEditorInfo.nSize = (nMaxNum+1)*2;
		gEditorInfo.pBuffer = MCF_EDITOR_CALLOC(gEditorInfo.nSize * 2);
		memset( gEditorInfo.pBuffer, 0, gEditorInfo.nSize * 2);

		gEditorInfo.pDefaultTxt= (MWCHAR*)((MCHAR*)(gEditorInfo.pBuffer) + gEditorInfo.nSize);//
		if(gEditorInfo.pBuffer ==MNULL)
		{
			return MCR_FAIL;
		}
		gEditorInfo.bIsLocked = MTRUE;
		gEditorInfo.callback = handler;
		gEditorInfo.pUser = pUser;
		gEditorInfo.nInputType = __SetInputTypeEx(nInputType, nPorperty);

		//memset(gMCF_EDITORInfo.pBuffer,0,gMCF_EDITORInfo.pBuffer);

		if(pDefstr!=MNULL)
		{
			mmi_ucs2ncpy((char*)gEditorInfo.pBuffer,(char*)pDefstr, nMaxNum);
			mmi_ucs2ncpy((char*)gEditorInfo.pDefaultTxt,(char*)pDefstr, nMaxNum);
		}

		McfEditor_Entry();
	}

	return MCR_SUCCESS;
}


MINT McfEditorInScr_EnterEditor(IN MVOID *pUser,IN MINT nInputType,IN MUSHORT nMaxNum,IN MWCHAR* pDefstr,IN pfnMcfInputCb handler)
{
#if MCR_MTK_VER >= MTK_VER_1210 
	McfEditor_Free();
#endif

  if( MEDITOR_MSG_CLOSEEDIT == nInputType )
  {
    McfEditor_IMUI_Exit(); //exit the imui
    return MCR_SUCCESS;
  }

    if( MEDITOR_MSG_EDITRANGE == nInputType
       && MNULL != pUser )
    {
        MEditRangeInfo *pR = (MEditRangeInfo *)pUser;
        active_editor_x= pR->m_nX ;
        active_editor_y= pR->m_nY;
        active_editor_width = pR->m_nWidth;
        active_editor_height = pR->m_nHeight;

        return MCR_SUCCESS;
    }

	if(0 == nMaxNum|| gEditorInfo.bIsLocked)
	{
		return MCR_FAIL;
	}
	else
	{
		if(gEditorInfo.pBuffer)
		{
			MCF_EDITOR_FREE(gEditorInfo.pBuffer);
		}

		gEditorInfo.nSize = (nMaxNum+1)*2;
		gEditorInfo.pBuffer = MCF_EDITOR_CALLOC(gEditorInfo.nSize * 2);
		memset( gEditorInfo.pBuffer, 0, gEditorInfo.nSize * 2);

		gEditorInfo.pDefaultTxt= (MWCHAR*)((MCHAR*)(gEditorInfo.pBuffer) + gEditorInfo.nSize);//
		if(gEditorInfo.pBuffer ==MNULL)
		{
			return MCR_FAIL;
		}
		gEditorInfo.bIsLocked = MTRUE;
		gEditorInfo.callback = handler;
		gEditorInfo.pUser = pUser;
		gEditorInfo.nInputType = __SetInputType(nInputType);

		//memset(gMCF_EDITORInfo.pBuffer,0,gMCF_EDITORInfo.pBuffer);

		if(pDefstr!=MNULL)
		{
			mmi_ucs2ncpy((char*)gEditorInfo.pBuffer,(char*)pDefstr, nMaxNum);
			mmi_ucs2ncpy((char*)gEditorInfo.pDefaultTxt,(char*)pDefstr, nMaxNum);
		}

#if MCR_MTK_VER >= MTK_VER_1210 
		McfEditorInScr_Entry();
#endif		
	}

	return MCR_SUCCESS;
}

//add by charmenli
MBOOL McfIsRunningFront(MVOID)
{
	U16 curScrnID = GetActiveScreenId();
	if( (MCARE_SCREEN_BASE==curScrnID) || (MCARE_SCREEN_EDITOR==curScrnID) || (MCARE_SCREEN_HOME==curScrnID) || g_mcare_is_in_editor )
	{
		return MTRUE;
	}
	return MFALSE;
}

/*==============================Browser===============================*/
#include "McfBrowser.h"
#include "McfPlatform.h"

#define MBRW_CALLOC(size)	MKernPool_Malloc(size)
#define MBRW_FREE(ptr)		MKernPool_Free(ptr)
#define MBRW_LOG(x) 


MINT McfBrw_StartWapReq(MCHAR *pUrl)
{
#if MCR_SUPPORT_WAP_BROWSER == __CFG_YES__
	MCHAR *pBuffer = MNULL;
	MINT nLen = 0;
	MINT nRet = MCR_FAIL;

	if(pUrl==MNULL)
	{
		return MCR_FAIL;
	}
	MBRW_LOG(("[MBrw_StartWapReq],pUrl:%s",pUrl));

	nLen = strlen(pUrl);
	pBuffer = (MCHAR *)MBRW_CALLOC( (nLen+1)*2 );

	if(pBuffer)
	{
		memset(pBuffer, 0, nLen + 1);
		mmi_asc_to_ucs2((S8*)pBuffer, (S8*)pUrl);

#if MCR_MTK_VER >= MTK_VER_1132
        nRet = wap_start_browser(2, (kal_uint8*)pBuffer);
#else
		nRet = wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*)pBuffer);
#endif

		
		MBRW_FREE(pBuffer);
	}
	return nRet;
#else
	return MCR_FAIL;
#endif//    

}


#if 0// MCR_MTK_VER >= MTK_VER_1132 by rico 1144
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


MCHAR * McfBrw_GetUaHeader(MCHAR *pUaHeader,MINT nSize)
{
	MCHAR *pResult = MNULL;
    MINT nLen;
	if(!pUaHeader || nSize <= 0)
	{
		return MNULL;
	}
    #if MCR_MTK_VER < 1032
	pResult = (MCHAR*)wap_custom_get_ua_header();
	#else
	pResult = "mtk os";
	#endif
	if(pResult)
	{
	    nLen = strlen(pResult);
	    if(nSize < nLen+1)
	    {
	        nLen = nSize -1;
	    }
		strncpy(pUaHeader, pResult, nLen);
		return pUaHeader;
	}
	else
	{
		return MNULL;
	}
}



/*============================ Key ==============================*/
#include "McfKey.h"
#include "McfPlatform.h"

#define	MCF_KEY_MAX      (sizeof(gPlatKeyToMcrMap)/sizeof(McfValueMap))//键个数最大个数
#define	MCF_KEY_EVT_MAX		(8) //键事件类型最大个数8

typedef struct _valuemap
{
	MSHORT nId;
	MINT nValue;
}McfValueMap;


static const McfValueMap gPlatKeyToMcrMap[]=
{
	{KEY_0 ,MKEY_0},            
	{KEY_1 ,MKEY_1},                                                                                      
	{KEY_2 ,MKEY_2},                                                                                 
	{KEY_3 ,MKEY_3},                                                                                        
	{KEY_4 ,MKEY_4},                                                                                        
	{KEY_5 ,MKEY_5},                                                                                        
	{KEY_6 ,MKEY_6},                                                                                        
	{KEY_7 ,MKEY_7},                                                                                        
	{KEY_8 ,MKEY_8},                                                                                        
	{KEY_9 ,MKEY_9},                                                                                        
	{KEY_LSK ,MKEY_SOFT1},  
#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))  //purple
	{KEY_BACK ,MKEY_SOFT2},    
#else	
	{KEY_RSK ,MKEY_SOFT2},    
#endif	

	{KEY_CSK ,MKEY_SELECT},                                                                                     
	{KEY_UP_ARROW ,MKEY_UP},                                                                                
	{KEY_DOWN_ARROW ,MKEY_DOWN},                                                                              
	{KEY_LEFT_ARROW ,MKEY_LEFT},                                                                            
	{KEY_RIGHT_ARROW ,MKEY_RIGHT},                                                                             
	{KEY_SEND ,MKEY_SEND}, 
#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))  //purple
	{KEY_HOME , MKEY_END}, 
#else
	{KEY_END , MKEY_END}, 
#endif	
	//{KEY_CLEAR ,MKEY_MAX},                                                                                   
	{KEY_STAR ,MKEY_STAR},               
	{KEY_POUND ,MKEY_POUND},               
	{KEY_VOL_UP ,MKEY_VOLUME_UP},       //charmenli open                                                                           
	{KEY_VOL_DOWN ,MKEY_VOLUME_DOWN},   //charmenli open                                                                
	//{KEY_QUICK_ACS ,MKEY_MAX},//                                                                     
	{KEY_ENTER ,MKEY_SELECT},          
	//{KEY_EXTRA_1 ,MKEY_MAX},                                                                                
	//{KEY_EXTRA_2 ,MKEY_MAX},                                                                                 
	//{KEY_PLAY_STOP ,MKEY_MAX},                                                                               
	//{KEY_FWD ,MKEY_MAX},                                                                                     
	//{KEY_BACK ,MKEY_MAX},        
#if (MCR_MTK_VER >= MTK_VER_1210)	
	//{KEY_POWER ,MKEY_END},   //for mtk 5255         
#endif	
	//{KEY_EXTRA_A ,MKEY_MAX},                                                                                 
	//{KEY_EXTRA_B ,MKEY_MAX},                                                                                 
#ifdef __SENDKEY2_SUPPORT__                                                                     
	{KEY_SEND1 ,MKEY_SEND},
	{KEY_SEND2 ,MKEY_SEND},                                                                               
#endif
    {KEY_INVALID,MKEY_NONE}
};

static const McfValueMap gPlatKeyTypeToMcrMap[MCF_KEY_EVT_MAX]=
{
	{KEY_EVENT_DOWN, MEVTKEY_PRESS},
	{KEY_EVENT_UP ,MEVTKEY_RELEASE},
	{KEY_LONG_PRESS ,MEVTKEY_LONGPRESS},
};

static pfnKeyHandler gMcrHandleKeyEvt;
extern const U16 PresentAllKeys[];
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];


static MSHORT __ValueMapLookup(const McfValueMap *pValueMap,MINT nCount,MSHORT nId)
{
	MINT nValue =0xff;
	MINT i=0;

	if(pValueMap ==MNULL)
	{
		return nValue;
	}
	for(i=0; i < nCount;i++)
	{
		if(pValueMap->nId == nId)
		{
			nValue = pValueMap->nValue;
			break;
		}
		pValueMap++;
	}

	return nValue;    
}

static MVOID __KeyHandle(MVOID)
{
	U16 nKeyCode, nKeyType;

	GetkeyInfo(&nKeyCode, &nKeyType);
	
#if (MCR_MTK_VER >= MTK_VER_1210)
    if( KEY_BACK == nKeyCode || KEY_RSK == nKeyCode )
    {
        if(MNULL != g_EditPtr&&1==active_flag)
        {
            wgui_editor_deactivate(g_EditPtr);
            McfEditor_Exit();
            McfEditor_IMUI_Exit();
			//__inactiveFunc();
			//__resumeFunc();
            return;
        }
    }
	else if ( (KEY_VOL_UP == nKeyCode) && (KEY_EVENT_DOWN == nKeyType) )//charmenli add 修复按音量键无法调节声音问题2012-6-6
	{
		McfAud_MultiMediaVolUp();
		return;
	}
	else if ( (KEY_VOL_DOWN== nKeyCode) && (KEY_EVENT_DOWN == nKeyType) )//charmenli add 修复按音量键无法调节声音问题2012-6-6
	{
		McfAud_MultiMediaVolDown();
		return;
	}
	
#endif	

	nKeyCode = __ValueMapLookup(gPlatKeyToMcrMap, MCF_KEY_MAX, nKeyCode);
	nKeyType = __ValueMapLookup(gPlatKeyTypeToMcrMap, MCF_KEY_EVT_MAX, nKeyType);

	if(nKeyCode < MKEY_NONE && nKeyType < MEVTKEY_NONE)
	{
		if(gMcrHandleKeyEvt) //
		{
			gMcrHandleKeyEvt(nKeyCode, nKeyType);
		}
	}
}

MVOID McfKey_EndKeyDownHandle(MVOID)
{
	if(McfIsMcrRunning() && gMcrHandleKeyEvt)
	{
		//McfEvent_HandleAppEvent(MKEY_END, MEVTKEY_PRESS);
		McfEvent_HandleAppEvent(MEVTKEY_PRESS, MKEY_END, MNULL);
		__OnLoseFocus();
	}
}
static MINT McfKey_GetRegTotalKeyCount(MVOID)
{
	MINT totalKeyCount = 0;
	MINT totalKeySize = 0;
	MINT singleKeySize = 0;
	totalKeySize = sizeof(gPlatKeyToMcrMap);
	if (totalKeySize > 0)
	{
		singleKeySize = sizeof(gPlatKeyToMcrMap[0]);
		totalKeyCount = totalKeySize / singleKeySize;
	}
	return totalKeyCount-1;
}

MVOID McfKey_RegKeyHandler(pfnKeyHandler pFunc)
{
	MINT count;

	gMcrHandleKeyEvt = pFunc;
	count = McfKey_GetRegTotalKeyCount();

	for (count = count - 1; count >= 0; count--)
	{
		SetKeyHandler(__KeyHandle,gPlatKeyToMcrMap[count].nId,KEY_EVENT_DOWN);
	    SetKeyHandler(__KeyHandle,gPlatKeyToMcrMap[count].nId,KEY_EVENT_UP);
	    SetKeyHandler(__KeyHandle,gPlatKeyToMcrMap[count].nId,KEY_LONG_PRESS);
	}
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
#if ((MCR_MTK_VER >= MTK_VER_1112) && (defined(__COSMOS_MMI_PACKAGE__))) //by purple 
	    SetKeyHandler(__KeyHandle,KEY_HOME,KEY_EVENT_DOWN);
	    SetKeyHandler(__KeyHandle,KEY_HOME,KEY_EVENT_UP);
	    SetKeyHandler(__KeyHandle,KEY_HOME,KEY_LONG_PRESS);
#endif

#if (MCR_MTK_VER >= MTK_VER_1210)
	    SetKeyHandler(__KeyHandle,KEY_BACK,KEY_EVENT_DOWN);
	    SetKeyHandler(__KeyHandle,KEY_BACK,KEY_EVENT_UP);
	    SetKeyHandler(__KeyHandle,KEY_BACK,KEY_LONG_PRESS);
//modify by charmenli 2012-05-28 修正按power死机
	    //SetKeyHandler(__KeyHandle,KEY_POWER,KEY_EVENT_DOWN);
	    //SetKeyHandler(__KeyHandle,KEY_POWER,KEY_EVENT_UP);
	   // SetKeyHandler(__KeyHandle,KEY_POWER,KEY_LONG_PRESS);
#endif
	
}

MVOID McfKey_UnregKeyHandler(MVOID)
{
	gMcrHandleKeyEvt = MNULL;
	ClearAllKeyHandler();
}

MVOID RestoreAdpKeyHandler(MVOID)
{
	if(gMcrHandleKeyEvt)
	{
		McfKey_RegKeyHandler(gMcrHandleKeyEvt);
	}
}


/*============================= Pen ===================================*/
#include "McfPen.h"
#include "McfPlatform.h"

static pfnPenHandler gMcrHandlePenEvt;

#ifdef __MMI_TOUCH_SCREEN__

static void __PenDown(mmi_pen_point_struct sPos)
{
	MUINT nPoint = 0; 
	nPoint =  ((sPos.x & 0x0000ffff) << 16) | (sPos.y & 0x0000ffff);

	if(gMcrHandlePenEvt ) //
	{
		gMcrHandlePenEvt(MEVTPEN_DOWN, nPoint);
	}
}
static void __PenUp(mmi_pen_point_struct sPos)
{
	MUINT nPoint;
	nPoint =  ((sPos.x & 0x0000ffff) << 16) | (sPos.y & 0x0000ffff);

	if(gMcrHandlePenEvt ) //
	{
		gMcrHandlePenEvt(MEVTPEN_UP, nPoint);
	}
}
static void __PenMove(mmi_pen_point_struct sPos)
{
	MUINT nPoint;
	nPoint =  ((sPos.x & 0x0000ffff) << 16) | (sPos.y & 0x0000ffff);

	if(gMcrHandlePenEvt ) //
	{
		gMcrHandlePenEvt(MEVTPEN_MOVE, nPoint);
	}
}
#endif

MVOID McfTp_RegPenHandler(pfnPenHandler pFunc)
{//EMTpEvtTyep
#ifdef __MMI_TOUCH_SCREEN__
	gMcrHandlePenEvt = pFunc;
	mmi_pen_register_down_handler((mmi_pen_hdlr)__PenDown);
	mmi_pen_register_up_handler((mmi_pen_hdlr)__PenUp);
	mmi_pen_register_move_handler((mmi_pen_hdlr)__PenMove);
#endif
}

MVOID McfTp_UnregPenHandler(MVOID)
{
#ifdef __MMI_TOUCH_SCREEN__
	gMcrHandlePenEvt = MNULL;
	mmi_pen_register_down_handler(MNULL);
	mmi_pen_register_up_handler(MNULL);
	mmi_pen_register_move_handler(MNULL);
#endif
}

MVOID RestoreAdpPenHandler(MVOID)
{
	if(gMcrHandlePenEvt)
	{
		McfTp_RegPenHandler(gMcrHandlePenEvt);
	}
}


/*============================== Misc ===================================*/

#include "McfPlatform.h"
#include "McfTime.h"
#include "McfMisc.h"
#include "McfSim.h"
#include "McfDtcnt.h"

#define DUMMY_IMEI  "012345678901234"

#if MCR_MTK_VER < MTK_VER_1032 //by purple

 #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
 #else
 extern U8* mmi_bootup_get_imei_value(void);
 #endif

void __read_imei(MINT nSimId,MCHAR *pImei,MINT nLen)
{
#if (MCR_MTK_VER <= MTK_VER_852)
    kal_uint8 imei_buf[20] ={0};
    int i;
    int j;
    
    nvram_get_imei_value(sizeof(imei_buf), &imei_buf);
    j = nLen >>1;
    for (i=0; i < j; i++)
    {
        pImei[i*2] = 0x30 + (imei_buf[i] & 0x0F);
        pImei[(i * 2) + 1] = 0x30 + (imei_buf[i] >> 4);
    }
    /* add terminated character. */
    pImei[(i * 2)-1] = 0;
#else//
   sim_interface_enum eSim = SIM1;
   #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
	strncpy (pImei, (const char*)mmi_bootup_get_imei_value(), nLen);
   #endif

#endif
}

#endif

MVOID McfMisc_GetImei(MINT nSimId, MCHAR *pImei,MINT nLen)
{
#if MCR_MTK_VER >= MTK_VER_1032
    mmi_sim_enum sim = MMI_SIM1;
    
    if(pImei==MNULL || nLen <=0)
    {
        return;
    }
    memset(pImei, 0x00, nLen);
  #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif
    srv_imei_get_imei(sim,pImei,nLen);
#else
	sim_interface_enum eSim = SIM1;
	
    if(pImei==MNULL || nLen <=0)
    {
        return;
    }
	memset(pImei, 0x00, nLen);

	if(nLen >16) nLen =16;
    __read_imei(nSimId,pImei,nLen);
#endif

    if (strlen(pImei) == 0)
    {
        strncpy (pImei, (const char*)DUMMY_IMEI, nLen);
    }

}

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

/**********************************
* McfMisc_GetCurLangCode,get current system language code
* @pLangCode --[out]lang code buffer
* @nSize --[in]buffer size of pLangCode
* #none
*/
MVOID McfMisc_GetCurLangCode(MCHAR *pLangCode,MINT nSize)
{    
    if(pLangCode && nSize > 0)
    {
      strncpy(pLangCode,(const char*)(gLanguageArray[gCurrLangIndex].aLangCountryCode),nSize-1);    
    }
}

#if MCR_MTK_VER > MTK_VER_816
MINT McfMisc_GetCharPinyin(MUSHORT ucs2Char, MCHAR* pPinyin, MINT nSize)
{
    U8 i, out = 0;
    U16 charInfoBuffer[16];
    UI_character_type code = 0;

    if(pPinyin == MNULL)
    {
        return 0;
    }

    code = ucs2Char;
    if ((code >= 0x4e00) && (code <= 0x9fa5))
    {//chinese character
        if(mmi_imc_get_char_info(code, (U16*) charInfoBuffer, sizeof(charInfoBuffer), IMM_INPUT_MODE_QUICK_SEARCH_PINYIN))
        {
            i = 0;
            while ((charInfoBuffer[i] != 0x0000) && (out < nSize-1))
            {
                pPinyin[out++] = (MCHAR)charInfoBuffer[i++];               
            }
        }
    }
    else
    {
        pPinyin[out++] = (MCHAR)code;
    }

    if(out < nSize)
    {
      pPinyin[out] = '\0';
    }
    
    return out;
}
#else
MINT McfMisc_GetCharPinyin(MUSHORT ucs2Char, MCHAR* pPinyin, MINT nSize)
{

}

#endif


/**********************************
* McfMisc_SetBacklight,set backlight
* @nInterval --[in]interval time of lightout, unit as second,MBKL_TIME_DEFAULT
* @nLevel --[in]brightness level
* #none
*/
MINT McfMisc_SetBacklight(MINT nInterval,MINT nLevel)
{
    if(nInterval == MBKL_TIME_DEFAULT)
    {//restore to default
        
#if MCR_MTK_VER >= MTK_VER_1132  //by purple
        srv_backlight_turn_off();
#else
        TurnOffBacklight();
#endif
        
    }
    else if(nInterval == MBKL_TIME_PERMANENT)
    {//permanent

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
#else
        TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
#endif

        }
    else
    {//customer
    }

    //todo

    return 0;
}

static MCHAR g_abyImsi1[__MCR_MAX_IMEI_IMSI_LENGTH__] = {0};


static void McfGetImsiRsp1(MVOID* pBuf)
{
	mmi_smu_get_imsi_rsp_struct* pImsi = (mmi_smu_get_imsi_rsp_struct *) pBuf;
	McfTrace_TraceFormatA("[McfGetImsiRsp1] result %d %s\r\n", pImsi->result, pImsi->imsi);

	if (pImsi && pImsi->result == ST_SUCCESS)
	{
		memset(g_abyImsi1, 0x00, sizeof(g_abyImsi1));
		memcpy(g_abyImsi1, pImsi->imsi+1, sizeof(pImsi->imsi));//MTK,ignore first byte of '9'

		__clear_protocol_event_handler(PRT_GET_IMSI_RSP,MNULL);    
	}
}

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if MCR_MTK_VER >= MTK_VER_1032
MVOID McfMisc_GetImsiRequst(MVOID)
{
    MCHAR *pImsi=MNULL;
    MCHAR imsi[20] ={0};
    
    if (srv_sim_ctrl_is_inserted(MMI_SIM1))
    {
        if (g_abyImsi1[0] ==0)
        {
           srv_sim_ctrl_get_imsi(MMI_SIM1, (CHAR *) imsi, __MCR_MAX_IMEI_IMSI_LENGTH__);
           strncpy((CHAR*)g_abyImsi1,&imsi[1],__MCR_MAX_IMEI_IMSI_LENGTH__-1);//remove prefix '9'
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if MCR_SIM3_SUPPORT == __CFG_YES__
    //todo.. get imsi for sim3,save to gMcrImsi[2]
#endif
#if MCR_SIM4_SUPPORT == __CFG_YES__
    //todo.. get imsi for sim4,save to gMcrImsi[3]
#endif
    if(g_abyImsi1[0] == 0
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
        #endif
        )
    {
		gui_start_timer(1000, McfMisc_GetImsiRequst);        
    }

}

#else
MVOID McfMisc_GetImsiRequst(MVOID)
{
	MYQUEUE	message;
	MBOOL bShouldCheck = MFALSE;

	message.oslMsgId = PRT_GET_IMSI_REQ;
	message.oslDataPtr = NULL;
	message.oslPeerBuffPtr= NULL;
	message.oslSrcId = MOD_MMI;

	McfTrace_TraceFormatA("[fnMcfMisc_GetImsiRequst] \r\n");

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
	if (!mmi_bootup_is_sim_removed() && (g_abyImsi1[0] == 0 ||g_abyImsi1[0]=='0'))
	{
		message.oslDestId = MOD_L4C;
		OslMsgSendExtQueue(&message);
		__set_protocol_event_handler(McfGetImsiRsp1, PRT_GET_IMSI_RSP,MFALSE);
		bShouldCheck = MTRUE;        
	}
#endif

	if (bShouldCheck)
	{
		McfTrace_TraceFormatA( "[fnMcfMisc_GetImsiRequst] bShouldCheck\r\n");  
		gui_start_timer(1000, McfMisc_GetImsiRequst);        
	}
}
#endif

MVOID McfMisc_GetImsi(MINT nSimId,MCHAR *pImsi,MINT nLen)
{
	//assert pImsi != MNULL
	if (nSimId == MSIM_CARD1 )
	{
		memcpy(pImsi, g_abyImsi1, nLen);
	}
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

MVOID McfMisc_GetSimImsi(MINT simId, MCHAR * pImsi, MINT nSize)
{
	if(pImsi)
	{
		memset(pImsi,0,nSize);
     
		if(simId == MSIM_CARD2)
		{
#ifdef __MMI_DUAL_SIM_MASTER__   		
/* under construction !*/
#endif
		}
		else if(simId ==MSIM_CARD3)
		{
		}
		else if(simId ==MSIM_CARD4)
		{
		}
		else
		{
			strncpy(pImsi,g_abyImsi1,nSize-1);
		}
	}
}


/*================================ TIME ===================================*/
#include "McfPlatform.h"
#include "McfTime.h"

MVOID McfTime_GetSysTimes(MTime_DateTime *pDateTime)
{
	if(pDateTime)
	{
#if (MCR_MTK_VER > MTK_VER_652)
	applib_time_struct stTmp;

    memset(pDateTime, 0, sizeof(MTime_DateTime));
	applib_dt_get_date_time(&stTmp);
	pDateTime->m_nYear = stTmp.nYear;
	pDateTime->m_nMonth = stTmp.nMonth;
	pDateTime->m_nDay = stTmp.nDay;
	pDateTime->m_nHour = stTmp.nHour;
	pDateTime->m_nMinute = stTmp.nMin;
	pDateTime->m_nSecond = stTmp.nSec;
	pDateTime->m_nWeekday = stTmp.DayIndex;

#else

	MYTIME t;

    memset(pDateTime, 0, sizeof(MTime_DateTime));
	GetDateTime(&t);
	pDateTime->m_nYear = t.nYear;
	pDateTime->m_nMonth = t.nMonth;
	pDateTime->m_nDay = t.nDay;
	pDateTime->m_nHour = t.nHour;	
	pDateTime->m_nMinute = t.nMin;
	pDateTime->m_nSecond = t.nSec;
	pDateTime->m_nWeekday = t.DayIndex;
#endif
	}
}

MUINT McfTime_GetSysTimeMs(MVOID)
{
	MUINT nTicks = 0;
	kal_get_time(&nTicks);
	return kal_ticks_to_milli_secs(nTicks);
}

/************************************TIMER*****************************************/
static stack_timer_struct gBaseStackTimer;
MVOID *McfInitBaseTimer(MVOID)
{
    stack_init_timer((stack_timer_struct *)&gBaseStackTimer, "McfTimer", MOD_MMI);
    return (MVOID*)&gBaseStackTimer;
}
MVOID McfStartBaseTimer(MVOID *pBaseTimer,MUINT init_time)
{
    if(pBaseTimer)
    {
        stack_start_timer(pBaseTimer, 0, kal_milli_secs_to_ticks(init_time));
    }
}
MVOID McfStopBaseTimer(MVOID *pBaseTimer)
{
    if(pBaseTimer)
    {
        stack_stop_timer(pBaseTimer);
    }
}


extern MVOID McfTimeoutDispatch(MVOID);
MVOID McfBaseTimerExpireProcess(MVOID *basetimer)
{//adapt to MTK,this function invoked in EvshedMMITimerHandler

    if(basetimer==(MVOID*)&gBaseStackTimer)
	{
	    if(stack_is_time_out_valid(&gBaseStackTimer))
	    {

            McfTimeoutDispatch();
    
        }
	    stack_process_time_out(&gBaseStackTimer);
	}
}

MUINT McfGetTimerBaseId(MVOID)
{
    //we don't use mmi timer anymore,use stack timer instead.arlo
	return 0;//(MUINT)MCARE_TIMER_BASE;
}

/*================================ STDLIB ===================================*/

#include "McfStdLib.h"
#include "McfUcs2.h"
#include "McfPlatform.h"

MUINT McfStdC_strlen(const MCHAR *pStr)
{
	return (MUINT)strlen(pStr);
}

MINT McfStdC_strcmp(const MCHAR *pStr0,  const MCHAR *pStr1)
{
	return strcmp(pStr0, pStr1);
}

MCHAR*	McfStdC_strcat(MCHAR *pStr0,  const MCHAR *pStr1)
{
	return (MCHAR*)strcat(pStr0, pStr1);
}

MCHAR*	McfStdC_strcpy(MCHAR *pStr0,  const MCHAR *pStr1)
{
	return (MCHAR*)strcpy(pStr0, pStr1);
}

MCHAR*	McfStdC_strncpy(MCHAR *pStr,  const MCHAR *pStr1, MUINT nSize)
{
	return (MCHAR*)strncpy(pStr, pStr1, nSize);
}

MCHAR*	McfStdC_strchr(const MCHAR *pStr,  MINT chr)
{
	return (MCHAR*)strchr(pStr, chr);
}

MCHAR*	McfStdC_strrchr(const MCHAR* pDest, MINT nChr)
{
	return (MCHAR*)strrchr(pDest, nChr);
}

MCHAR*	McfStdC_strstr(const MCHAR *pStr, const MCHAR *pStrSearch)
{
	return (MCHAR*)strstr(pStr, pStrSearch);
}

MINT	McfStdC_atoi(const MCHAR *pStr)
{
	return atoi(pStr);
}


MINT McfStdC_stricmp(const MCHAR *dst, const MCHAR *src)
{
	MINT ch1, ch2;

	do 
	{
		if (((ch1 = (unsigned char)(*(dst++))) >= 'A') &&(ch1 <= 'Z'))
		{
			ch1 += 0x20;
		}

		if (((ch2 = (unsigned char)(*(src++))) >= 'A') &&(ch2 <= 'Z'))
		{
			ch2 += 0x20;
		}
	}while(ch1 && (ch1 == ch2));

	return (ch1 - ch2);
}


MCHAR* McfStdC_strlwr(MCHAR *str)
{
	MCHAR *p = str;

	while (*p != '\0')
	{
		if(*p >= 'A' && *p <= 'Z')
		{
			*p = (*p) + 0x20;
		}

		p++;
	}

	return str;
}

MCHAR* McfStdC_strupr(MCHAR *str)
{
	MCHAR *p = str;

	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p -= 0x20;
		}

		p++;
	}

	return str;
}

MUINT McfStdC_wcslen(const MWCHAR* pwstr)
{
	return mmi_wcslen((const U16*)pwstr);
}

MINT McfStdC_wcscmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1)
{
	return mmi_wcscmp((const U16*)pwstr0, (const U16*)pwstr1);
}

MINT McfStdC_wcsncmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1,MINT icount)
{
	return mmi_wcsncmp((const U16*)pwstr0, (const U16*)pwstr1, (U32)icount);
}

MWCHAR* McfStdC_wcscpy(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc)
{
	return mmi_wcscpy((U16*)pwstrDest, (const U16*)pwstrSrc);
}

MWCHAR* McfStdC_wcsncpy(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc,MINT icount)
{
	return mmi_wcsncpy((U16*)pwstrDest, (const U16*)pwstrSrc, (U32)icount);
}

MWCHAR* McfStdC_wcscat(MUSHORT *str_dst, const MUSHORT *str_src)
{
	return mmi_wcscat((U16*)str_dst, (const U16*)str_src);
}

MWCHAR*	McfStdC_wcsncat(MWCHAR* pwstrDest,const MWCHAR* pwstrSrc,MINT icount)
{
	return mmi_wcsncat((U16*)pwstrDest, (const U16*)pwstrSrc, (U32)icount);
}

MWCHAR*	McfStdC_wcsstr(const MWCHAR* pStr,const MWCHAR* pStrSearch)
{
	return mmi_wcsstr((U16*)pStr, (const U16*)pStrSearch);
}

MWCHAR*	McfStdC_wcschr(const MWCHAR* pwstr,MWCHAR wchar)
{
	return mmi_wcschr((const U16*)pwstr, (U16)wchar);
}

MINT McfStdC_wcsicmp(const MWCHAR* pwstr0,const MWCHAR* pwstr1)
{
	return mmi_wcsicmp((const U16*)pwstr0, (const U16*)pwstr1);
}

MWCHAR*	McfStdC_wcslwr(MWCHAR* pwstrDest)
{
	return mmi_wcslwr((U16*)pwstrDest);
}

MWCHAR*	McfStdC_wcsupr(MWCHAR* pwstrDest)
{
	return mmi_wcsupr((U16*)pwstrDest);
}


MWCHAR*	McfStdC_strtowstr(MWCHAR* pwstrDest,const MCHAR* pstrSrc)
{
	mmi_asc_to_ucs2((S8 *) pwstrDest, (S8 *)pstrSrc);
	return pwstrDest;
}

MCHAR*	McfStdC_wstrtostr(MCHAR* pstrDest,const MWCHAR* pwstrSrc)
{
	mmi_ucs2_to_asc((S8 *) pstrDest, (S8 *) pwstrSrc);
	return pstrDest;
}


extern MINT _vsnwprintf_MCR(MWCHAR *buf, MUINT cnt, const MWCHAR *fmt, va_list args);

MINT McfStdC_wsprintf(MWCHAR* pwstrDest,const  MCHAR* pstrFmt,...)
{
	MWCHAR *pwstrFmt;
	va_list argList;
	MINT ret;

	pwstrFmt= (MWCHAR *)MKernPool_Malloc((strlen(pstrFmt)+1)*2);

	McfUcs2_AscToUcs2((MUSHORT *) pwstrFmt, pstrFmt);
	va_start(argList,pstrFmt);
	ret =_vsnwprintf_MCR(pwstrDest,0xff,pwstrFmt,argList);
	va_end(argList);

	MKernPool_Free( pwstrFmt);
	return ret;
}

MINT McfStdC_sprintf(MCHAR* pstrDest,const MCHAR* pstrFmt,...)
{
	MINT ret = MCR_FAIL;
	va_list argList;

	va_start(argList, pstrFmt);
	ret = vsprintf(pstrDest, pstrFmt, argList);
	va_end(argList);
	return ret;
}

MINT	McfStdC_nsprintf(MCHAR* pstrDest,MINT ilengthDest,const MCHAR* pstrFmt,...)
{
	MINT ret = MCR_FAIL;
	va_list argList;

	va_start(argList, pstrFmt);
	ret = _vsnprintf(pstrDest, ilengthDest, pstrFmt, argList);
	va_end(argList);

	return ret;
}

MINT	McfStdC_vsnprintf(MCHAR* pstrDest,MUINT nSize, const MCHAR* pstrFmt, va_list aList)
{
	return _vsnprintf(pstrDest, nSize, pstrFmt, aList);
}


MINT McfStdC_memcmp(const MVOID* buf1, const MVOID* buf2, MUINT  nCount)
{
	return memcmp(buf1, buf2, nCount);
}

MVOID* 	McfStdC_memcpy(MVOID* dst, const MVOID* src, MUINT  nCount)
{
	return memcpy(dst, src, nCount);	
}

MVOID*	McfStdC_memset(MVOID* buf1, MINT nValue, MUINT  nCount)
{
	return memset(buf1, nValue, nCount);
}

MVOID*	McfStdC_memchr(const MVOID* buf1, MINT nChr, MUINT  nCount)
{
	return memchr(buf1, nChr, nCount);
}

MVOID*	McfStdC_memmove(MVOID* buf1, const MVOID* buf2, MUINT  nCount)
{
	return memmove(buf1, buf2, nCount);
}

MVOID	McfStdC_srand (MUINT nSeed)
{
	srand(nSeed);
}

MINT	McfStdC_rand(MVOID)
{
	return rand();
}


MUSHORT McfUcs2_AscToUcs2(MUSHORT *pOutBuf, const MCHAR *pInBuf)
{
	return mmi_asc_to_ucs2((S8 *) pOutBuf, (S8 *)pInBuf);
}

MUSHORT McfUcs2_AscNToUcs2(MUSHORT *pOutBuf, const MCHAR *pInBuf, MUINT count)
{
	return mmi_asc_n_to_ucs2((S8 *) pOutBuf, (S8 *) pInBuf,count);
}

MUSHORT McfUcs2_Ucs2ToAsc(MCHAR *pOutBuf, const MUSHORT *pInBuf)
{
	return mmi_ucs2_to_asc((S8 *) pOutBuf, (S8 *) pInBuf);
}

MUSHORT McfUcs2_Ucs2NToAsc(MCHAR *pOutBuf, const MUSHORT *pInBuf, MUINT count)
{
	return mmi_ucs2_n_to_asc((S8 *) pOutBuf, (S8 *) pInBuf,count<<1);
}

MINT McfChset_utf8_to_ucs2(MUSHORT* pDest, MINT size, MCHAR *pSrc)
{
	return mmi_chset_utf8_to_ucs2_string((kal_uint8*)pDest, size,(kal_uint8*)pSrc);
}

MINT McfChset_ucs2_to_utf8(MCHAR* pDest, MINT size, MUSHORT *pSrc)
{
	return mmi_chset_ucs2_to_utf8_string((kal_uint8*)pDest, size,(kal_uint8*)pSrc);
}


/*================================ Sys =================================*/
#include "McfSys.h"
#include "McfPlatform.h"
#include "McfTrace.h"


typedef struct __sysStruct
{
	MVOID *pData;
	pfnFunc inactiveFunc;
	pfnFunc deepInactiveFunc;
	pfnFunc resumeFunc;
	pfnFunc exitFunc;

	MINT nMCareScrId;
}MSysGlobal;

static MSysGlobal sMSysGlobal;

#if MCR_MTK_VER >= MTK_VER_1132
_fFuncPtr  NewExitHandler_new=NULL;
_fFuncPtr  NewEntryHandler_new = NULL;

_fFuncPtr  NewExitHandler_org=NULL;
_fFuncPtr  NewEntryHandler_org = NULL;

MVOID SetExitHandler_ext(MVOID)
{
	if(NewExitHandler_new)
	{
            NewExitHandler_new();
            //NewExitHandler_new = NULL;
	}
	else
	{
            NewExitHandler_org();
            //NewExitHandler_org = NULL;
	}
	
}

MVOID SetEntryHandler_ext(MVOID )
{
	if(NewEntryHandler_new)
	{
        	NewEntryHandler_new();
        	//NewEntryHandler_new = NULL;
	}
	else
	{
        	NewEntryHandler_org();
        	//NewEntryHandler_org = NULL;
	}

}
#endif



FuncPtr g_test;

MMI_RET _mcf_screenDel_proc(mmi_event_struct *post_evt)
{
    if(post_evt == MNULL) 
        return MMI_RET_ERR;
    
//    kal_prompt_trace(MOD_SMS, "_mcf_screenDel_proc post_evt->evt_id = %d", post_evt->evt_id);
//    kal_prompt_trace(MOD_SMS, "_mcf_screenDel_proc EVT_ID_SCRN_GOBACK = %d", EVT_ID_SCRN_GOBACK);
 
#if MCR_MTK_VER >= MTK_VER_1210
    switch (post_evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_SCRN_DEINIT:
            if(g_test != MNULL)
            {
                //kal_prompt_trace(MOD_SMS, "_mcf_screenDel_proc CALL g_test NOT NULL");
             g_test();
         }
         else
         {
                //kal_prompt_trace(MOD_SMS, "_mcf_screenDel_proc CALL g_test IS NULL");
         }
            break;
 
        default:
            return MMI_RET_ERR;
    }
#else
g_test();
#endif
 
return MMI_RET_OK;
}

MINT __EntryScreen(U16 scrnId,pfnFunc exitFunc,pfnDelFunc deleteFunc, pfnFunc entryFunc, MVOID *flag)
{

#if MCR_MTK_VER >= MTK_VER_1132 //purple

        mmi_frm_group_create(APP_TENCENT_MCARE/*APP_TENCENT_MCARE*/, GRP_ID_MCARE_LIST, McfGroupCreateProc, NULL);
        mmi_frm_group_enter(GRP_ID_MCARE_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);

       if(!McfScrnEnter(GRP_ID_MCARE_LIST, scrnId, (FuncPtr)exitFunc, (FuncPtr)entryFunc))
       {
       }
       g_test = deleteFunc;
       McfSetDelScrCallBackFunc(GRP_ID_MCARE_LIST,scrnId,(FuncPtr)_mcf_screenDel_proc);
	   //McfSetDelScrCallBackFunc(GRP_ID_MCARE_LIST,scrnId,NULL);
#else
	EntryNewScreen(scrnId, (FuncPtr)exitFunc, (FuncPtr)entryFunc,MNULL);
	SetDelScrnIDCallbackHandler(scrnId, deleteFunc);
#endif


	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" scrnId = %d", scrnId);

	return scrnId;
}

#if (MCR_MTK_VER >= MTK_VER_1210)
void srv_shutdown_normal_start(MMI_ID trigger_man_app_id);
#endif

MVOID __ExitScreen(MINT nType)
{
	switch(nType)
	{
	case MSYS_EXIT_IDLE:

#if  MCR_MTK_VER >= MTK_VER_1132  
        mmi_idle_display();
#else
        DisplayIdleScreen();
#endif	

#if (MCR_MTK_VER >= MTK_VER_1210)
    {
    	U16 nKeyCode, nKeyType;
    	GetkeyInfo(&nKeyCode, &nKeyType);

        if( KEY_POWER == nKeyCode &&
           KEY_LONG_PRESS == nKeyType )
        {
            MCR_ExitTencentMCare();  //exit mcare
            srv_shutdown_normal_start(0); //power off
        }
    }
#endif
		break;

	case MSYS_EXIT_GOBACK:
		McfGoBackHistory(); //by purple
		break;
	default:
		break;
	}
}

static MVOID __inactiveFunc(MVOID)
{
#if MCR_MTK_VER >= MTK_VER_1210  //must before the mem deinit
    if(MNULL != g_EditPtr&&1==active_flag)
    {    
        wgui_editor_deactivate(g_EditPtr);
        McfEditor_Exit();
        McfEditor_IMUI_Exit();   
        McfEditor_Reset_Clip();
    }
#endif

    if(sMSysGlobal.inactiveFunc)
    {
	 ((pfnFunc)sMSysGlobal.inactiveFunc)();
	}
	#ifdef USE_SYSBRW_DTCNT
    gIsSelctingApn = MFALSE;
    #endif
}

static MBYTE __deepInactiveFunc(MVOID*pArg)
{
    if(sMSysGlobal.deepInactiveFunc)
    {
	  ((pfnFunc)sMSysGlobal.deepInactiveFunc)();
	}
	#ifdef USE_SYSBRW_DTCNT
    gIsSelctingApn = MFALSE;
    #endif

	return MMI_HIST_ALLOW_DELETING;
}

extern int MCR_PreEntryCheck(void);
extern MINT MApn_Init(MVOID);//add by charmenli to fix apn status not update!
static MVOID __resumeFunc(MVOID)
{
	
	if(0 == MCR_PreEntryCheck())//charmenli add 2012-5-28
	{
		U16 curScreenId = GetActiveScreenId();
		MCR_ExitTencentMCare();	
    	MCR_CloseScreen();  //20111020 oyshengquan modify 
    	if (MCARE_SCREEN_HOME == curScreenId || MCARE_SCREEN_EDITOR == curScreenId)
    	{
			McfGoBackHistory();
		}
		return;
	}
	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" __resumeFunc1 sMSysGlobal.resumeFunc = 0x%x", sMSysGlobal.resumeFunc);
	MApn_Init();//add by charmenli to fix apn status not update!
	#if (MCR_MTK_VER >= MTK_VER_1210)
    McfGuiSetFont(MADP_MEDIUM_FONT,0,0,0);  //add by purple 1112 cosmos   
    #endif
    
	__EntryScreen(MCARE_SCREEN_HOME,__inactiveFunc,__deepInactiveFunc,__resumeFunc, MNULL);

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__" __resumeFunc2 sMSysGlobal.resumeFunc = 0x%x", sMSysGlobal.resumeFunc);

    if(sMSysGlobal.resumeFunc)
    {
	 ((pfnFunc)sMSysGlobal.resumeFunc)();
    }

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__":resumeFunc after");
}


//说明：进入mcare UI前需要执行的东西。例如MTK里的EntryNewScreen、其他平台可保存inactive、resume、进ui前的一些准备等实现。
MINT McfSys_Init(pfnFunc inactiveFunc, pfnFunc deepInactiveFunc, pfnFunc resumeFunc, pfnFunc exitFunc)
{
	//初始化api
	McfTraceInit();
	McfMem_Init();

	if(!MKernPool_CreatePool())
	{
		return MCR_FAIL;
	}

	//McfHandleMgr_Init();

	McfInitTimer();
	McfSocketInit();
	McfIdle_Init();

	sMSysGlobal.inactiveFunc = inactiveFunc;
	sMSysGlobal.resumeFunc = resumeFunc;
	sMSysGlobal.exitFunc = exitFunc;
	sMSysGlobal.deepInactiveFunc = deepInactiveFunc;
	sMSysGlobal.nMCareScrId = MCARE_SCREEN_HOME;

	//__EntryScreen(MCARE_SCREEN_HOME,__inactiveFunc,__deepInactiveFunc,__resumeFunc, MNULL);

	McfLog_Print(MLOG_INFO, MLOG_FIRMFLOW,   __MCR_FUNCTION__":sMSysGlobal.resumeFunc = 0x%x", sMSysGlobal.resumeFunc);

	return MCR_SUCCESS;
}

//固话层调用。退出Mcare UI需要调用的函数，
//nExitType – 退出标志，返回上次的位置还是退出到idle。
MINT McfSys_DeInit(MINT nExitType)
{	
    //unreg key or pen first!!!check me frike 2011-5-3
    if (MSYS_EXIT_NONE != nExitType)
    {
        McfTp_UnregPenHandler();
        McfKey_UnregKeyHandler();
    }
    else
    {
        MCFLOGIC_FLOW_PRINT(MLOG_INFO, MLOG_FIRMFLOW,
            "g_GblVars.m_nExitFlag = [%d] no need unreg key and pen",MSYS_EXIT_NONE);    
    }
#if MCR_MTK_VER >= MTK_VER_1210  //must before the mem deinit
    if(MNULL != g_EditPtr&&1==active_flag)
    {
        wgui_editor_deactivate(g_EditPtr);
        McfEditor_Free();
        McfEditor_IMUI_Exit();
        //gui_start_timer(600,McfEditor_IMUI_Exit);
    }
#endif
    
    McfDtcnt_CloseNetworkBearer(&gDtcntInfo);
	McfSocketDeinit();
	McfDeInitTimer();   
	McfIdle_Deinit();

	//McfHandleMgr_Deinit();

	MKernPool_DestroyPool();    
	McfMem_Deinit();

	//((pfnFunc)sMSysGlobal.exitFunc)();
	__ExitScreen(nExitType);

	memset(&sMSysGlobal,0,sizeof(sMSysGlobal));

	McfTraceDeinit();
  mmi_frm_asm_base_shrink_size(APP_TENCENT_MCARE, 0);
	return MCR_SUCCESS;
}


//说明：固化层调用，后台挂机需要执行的操作。 
//nExitType – 退出标志，返回上次的位置还是退出到idle。
MINT McfSys_Background(MINT nExitType)
{
#if MCR_MTK_VER >= MTK_VER_1210 
    if(MNULL != g_EditPtr&&1==active_flag)
    {
        wgui_editor_deactivate(g_EditPtr);
        McfEditor_Free();
        McfEditor_IMUI_Exit();
    }
#endif
	__ExitScreen(nExitType);
	return MCR_SUCCESS;
}

//============================= 外部调用函数 =====================================
//说明：可供其他平台在外部调用，挂机恢复前需要执行的操作。
MINT McfSys_Foreground(MVOID)
{
	__EntryScreen(MCARE_SCREEN_HOME,__inactiveFunc,__deepInactiveFunc,__resumeFunc, MNULL);
	return MCR_SUCCESS;
}

//说明：直接调用固化层的Suspend的导出函数。其他平台发suspend消息可调用。
MINT McfSys_Suspend(MVOID)
{
	return MCR_SUCCESS;
}

//说明：直接调用挂画层Resume的导出函数。其他平台收到resume消息可调用
MINT McfSys_Resume(MVOID)
{
	return MCR_SUCCESS;	
}

/*****************************************************************************/
#include "cache_sw.h"
MVOID McfSys_InvalidateCpuCache(MBYTE *start, MUINT size)
{
#ifndef WIN32
   #if defined(__ARM9_MMU__)
    kal_uint32 *invalidPtr;
    kal_uint32 length = size;

	//start address and size MUST align to CPU_CACHE_LINE_SIZE
    invalidPtr = (kal_uint32*) ((kal_int32) start & (~CPU_CACHE_LINE_SIZE_MASK));
    length >>= CPU_CACHE_LINE_BIT_OFFSET;

    if (start != (unsigned char *)invalidPtr)
    {
        length += 2;
    }
    else
    {
        length++;
    }		
    invalidate_arm9_icache((kal_uint32)invalidPtr, (length<<CPU_CACHE_LINE_BIT_OFFSET));  
    clean_arm9_dcache((kal_uint32)invalidPtr, (length<<CPU_CACHE_LINE_BIT_OFFSET));
    invalidate_arm9_dcache((kal_uint32)invalidPtr, (length<<CPU_CACHE_LINE_BIT_OFFSET));
  #else
   //don't care
  #endif
#endif
}



/*======================= Telephone =========================*/
#include "McfTelephone.h"
#include "McfPlatform.h"

#if MCR_MTK_VER >= MTK_VER_1108
#include "UCMGProt.h"
MINT McfTel_MakeCall(MINT nSimId,const MCHAR* pcszNum)
{
	MINT calltype;
  mmi_ucm_make_call_para_struct make_call_para;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(nSimId == MSIM_CARD2)
	{
		calltype =MMI_UCM_SIM2_CALL_TYPE_ALL;
	}
	/*
	*case sim3 /sim4 ...
	*/
	else
	{
		calltype =MMI_UCM_SIM1_CALL_TYPE_ALL;
	}
 	//mmi_ucm_app_make_call(calltype,(U8 *)pcszNum);
  mmi_ucm_init_call_para(&make_call_para);  
  make_call_para.dial_type = (srv_ucm_call_type_enum)calltype;
  make_call_para.ucs2_num_uri = (U16*)pcszNum;
  mmi_ucm_call_launch(0, &make_call_para);
    return MCR_SUCCESS;
}
#else
MINT McfTel_MakeCall(MINT nSimId,const MCHAR *pNumber)
{
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	MakeCall((char*)pNumber);
	return MCR_SUCCESS;
}
#endif



/*======================== Trace ==========================*/

#include "McfTrace.h"
#include "McfUsb.h"
#include "McfMisc.h"
#include "McfFs.h"
#include "stdarg.h"
#include "McfCommon.h"
#include "McfStdLib.h"
#include "McfPlatform.h"
#include "MAdpConfig.h"


static MCHAR logbuf[512];
static MWCHAR logTempBuf[256];
static MWCHAR logFullPath[__MCR_MAX_PATH_LENGTH__] = {0};
static MINT logFh = -1;
static MINT nIsFirst = -1;
static MTrace m_trace;

extern MINT _vsnwprintf_MCR(MWCHAR *buf, MUINT cnt, const MWCHAR *fmt, va_list args);
#define McfVsnwprintf _vsnwprintf_MCR

MVOID McfTrace_LogFormatA(const MCHAR *format, ...)
{
#ifdef MCR_LOG_DEBUG

	if(logFh == -1)
	{
		McfTraceInit();
	}

	if(logFh>0)
	{
		va_list arg_list;
		MINT nLen;
		MUINT nWrite;

		memset(logbuf, 0, sizeof(logbuf));
		va_start(arg_list, format);
		//vsprintf(logbuf, format, arg_list);
		_vsnprintf(logbuf, 512, format, arg_list);
		va_end(arg_list);

		nLen =strlen(logbuf);
		logbuf[nLen]='\n';
		nLen+=1;
		logbuf[nLen]='\0';
#if (USE_TRACE == 0)		
    	FS_Seek(logFh,0, MFILE_SEEK_END);
    	FS_Write(logFh,logbuf,nLen, &nWrite); 
    	FS_Commit(logFh);
#else
        McfTrace_TraceFormatA("%s", logbuf);
#endif
	}

#endif//MCR_LOG_DEBUG
}


MVOID McfTrace_LogFormat(const MWCHAR* format, ...)
{
#ifdef MCR_LOG_DEBUG

	if(logFh == -1)
	{
		McfTraceInit();
	}

	if(logFh > 0)
	{
		va_list arg_list;
		MINT nLen;
		MUINT nWrite;

		memset(logbuf,0,sizeof(logbuf));
		va_start(arg_list ,format);
		McfVsnwprintf((MWCHAR*)logbuf, 0xff, (const MWCHAR*)format, arg_list);
		va_end(arg_list);
		//mmi_ucs2_to_asc((S8 *) logbuf,(S8*)logTempBuf);
		nLen =mmi_wcslen((MWCHAR*)logbuf);
		logbuf[nLen*2]='\n';
		nLen+=1;
		logbuf[nLen*2]='\0';
#if (USE_TRACE == 0)
		FS_Seek(logFh,0, MFILE_SEEK_END);
		FS_Write(logFh,logbuf,nLen*2, &nWrite); 
		FS_Commit(logFh);
#else
        McfTrace_TraceFormat(L"%s", logbuf);
#endif
	}

#endif//MCR_LOG_DEBUG
}

MVOID McfTraceInit(MVOID)
{
	if(!McfUsb_IsInMassStorageMode())
	{
		if(logFh < 0)
		{
			memset(logFullPath, 0, __MCR_MAX_PATH_LENGTH__ * sizeof(MWCHAR));
			//McfStdC_wcscpy(logFullPath, McfGetRootLocate()); // ""
			//McfStdC_wcsncpy(logFullPath, McfFile_GetCardDrv(),1); // e:
			logFullPath[0]= McfFile_GetStorageDrv();
			logFullPath[1]= ':';
			logFullPath[2]= 0;

			McfStdC_wcscat(logFullPath, LOG_STR_Slash); // 
			McfStdC_wcscat(logFullPath, LOG_DIR_NAME);

			McfFile_CreateDir(logFullPath);
			McfStdC_wcscat(logFullPath, LOG_STR_Slash); // 
			McfStdC_wcscat(logFullPath,	LOG_FILE_NAME);

			FS_Delete(logFullPath);
			logFh = FS_Open(logFullPath, FS_CREATE | FS_READ_WRITE);
			nIsFirst = 1;
		}
	}
	else
	{
		logFh = -1;
		nIsFirst = -1;
	}
}

MVOID McfTraceDeinit(MVOID)
{
	if(logFh >=0 )
	{
		FS_Close(logFh);
		logFh = -1;
		nIsFirst = -2;
	}
}
MVOID McfTrace_TraceFormatA(const MCHAR *format, ...)
{
	module_type modId;
	va_list arg_list;

	modId = MCF_TRACE_MOD;//
    memset((MCHAR*)logTempBuf, 0, 512);
	sprintf((MCHAR*)logTempBuf, "[MCARE]");
	va_start(arg_list ,format);
	//vsprintf(logbuf+strlen(logbuf), format, arg_list);
	_vsnprintf((MCHAR*)logTempBuf+strlen((MCHAR*)logTempBuf), 
	            512 - strlen((MCHAR*)logTempBuf), format, arg_list);
	va_end(arg_list);

#ifdef WIN32
	kal_printf("%s\r\n", (MCHAR*)logTempBuf);
#else
	kal_prompt_trace(modId,"%s", (MCHAR*)logTempBuf);
#endif
}

MVOID McfTrace_TraceFormat(const MWCHAR* format, ...)
{
	module_type modId;
	va_list arg_list;

	modId = MCF_TRACE_MOD;
	va_start(arg_list ,format);
	memset((MCHAR*)logTempBuf, 0, 512);
	McfVsnwprintf(logTempBuf, 0xff, (const MWCHAR*)format,arg_list);
	va_end(arg_list);
	memset(logbuf, 0, 512);
	mmi_ucs2_to_asc((S8 *) logbuf,(S8*)logTempBuf);

#ifdef WIN32
	kal_printf("%s", logbuf);
#else
	kal_prompt_trace(modId,"%s",logbuf);
#endif
}


MVOID McfTrace_AssertFail(MCHAR* pExpr, MCHAR* pFileName, MINT nLine)
{
#if defined(DEBUG_KAL) //by purple
	#ifdef __KAL_ASSERT_LEVEL0__
		kal_assert_fail();
	#else
		kal_assert_fail(pExpr, pFileName, nLine, MFALSE, 0, 0, 0, MNULL);
	#endif
#endif
}

#ifdef MCR_LOG_DEBUG
#define APPM_LOG_MAX_PATH     (128)
#define MLOG_FILE_SET ("mcarev31_log_set.txt")

static const MCHAR channelconst[TRACE_CHANNEL_NUM][TRACE_MAX_NAME_LENGTH] = 
{
	"NONE",      // 0
	"SDKMEMORY", // 1
	"SDKFILE",   // 2
	"SDKAPP",            // 3
	"SDKGDI",           //4
	"SDKAUDIO",//5
	"SDKSOCKET",//6
	"SDKSMS",//7
	"SDKTEL",//8
	"SDKPHB",//9
	"SDKMISC",//10
	"SDKLOG",//11
	"SDKINPUT",//12
	"SDKUNZIP",//13
	"MGRKERN",//14
	"MGRNET",//15
	"MGRTMC",//16
	"MGRUI",//17
	"APPLICATION",//18
	"FIRMFLOW",//19
	"FIRMHTTP",//20
};


static const MCHAR levelconst[4][6] = 
{
	"NONE",           // 0
	"INFO",           // 1
	"WARN",           // 2
	"ERROR"           // 3
};


static MUINT ReadLcFile(void)
{
	MWCHAR path[64];    
	MCHAR a_path[64];    
	MINT nFilesize = 0;    
	MCHAR * pFilebuf = MNULL;
	MCHAR * pPos = MNULL;
	MLONG i = 0;

	MINT nChannelBit  = 0;
	MINT nLevelBit = 0;
	MCHAR channel_name[40];         
	MUINT nRwnum = 0;
	MLONG nFoundChannelFlag = 0; 

	MUINT nResult = MFALSE;
	MCHAR drive   = 0;   
	MFd fd = -1;

	FS_FileInfo fileInfo;
	do
	{
		//获取加载层所在位置的盘符   
		drive = (MCHAR)McfFile_GetStorageDrv();
		memset(a_path, 0, sizeof(a_path));
		sprintf(a_path, "%c:\\%s", (MBYTE)drive, (MBYTE *)MLOG_FILE_SET);
		mmi_asc_to_ucs2((S8 *)path, (S8 *)a_path);        

		fd = FS_Open(path, FS_READ_ONLY);

		if (fd < 0)
		{
			fd = FS_Open(path, FS_CREATE | FS_READ_WRITE);
			if (fd < 0)
			{
				break;
			}

			for (i = 0; i < TRACE_CHANNEL_NUM; i++) 
			{
				MINT len = 0;

//如果开了trace debug,那么默认打开全部log通道，否则默认全部关闭				，
//使用者根据需要打开
#ifdef MCR_TRACE_DEBUG
				len = _snprintf((MCHAR*)m_trace.m_pTmpBuf, 256, "%-50s\t\t%d\t\t%d\r\n", 
					channelconst[i], 1, ALOG_INFO);
#else//MCR_TRACE_DEBUG
				len = _snprintf((MCHAR*)m_trace.m_pTmpBuf, 256, "%-50s\t\t%d\t\t%d\r\n", 
					channelconst[i], 0, ALOG_INFO);
#endif//MCR_TRACE_DEBUG

				FS_Write(fd, (MCHAR*)m_trace.m_pTmpBuf, len, &nRwnum);

				if (len != nRwnum)
				{
					break;
				}
			}            
		}

		FS_Close(fd);        
		fd = -1;
		fd = FS_Open(path, FS_READ_ONLY);

		if (fd < 0)
		{
			break;
		}

		if(FS_GetFileInfo(fd, &fileInfo) >= 0)
		{
			nFilesize = fileInfo.DirEntry->FileSize;
		}

		if (nFilesize <= 0)
		{
			break;
		}        

		pFilebuf = (MCHAR *)med_ext_smalloc(nFilesize);

		if(MNULL == pFilebuf)
		{
			break;
		}

		nRwnum = 0;
		FS_Read(fd, pFilebuf, nFilesize, &nRwnum);

		if (nRwnum != nFilesize)
		{
			break;
		}

		pPos = pFilebuf;

		while (pPos < pFilebuf + nFilesize) 
		{
			sscanf(pPos, "%s%d%d\n", &channel_name, &nChannelBit, &nLevelBit);
			pPos = strchr(pPos, '\n');
			if (MNULL == pPos)
			{
				pPos = pFilebuf + nFilesize;
			}
			else
			{
				pPos += 1;
			}
			if(nChannelBit == 1)
			{
				nFoundChannelFlag = 0;
				for (i = 0; i < TRACE_CHANNEL_NUM; ++i) 
				{
					if (strcmp(channelconst[i], channel_name) == 0)
					{
						m_trace.m_ChannelControl[i] = 1;
						m_trace.m_ChannelLevel[i] = nLevelBit;
						nFoundChannelFlag = 1;
					}
				}
				if(0 == nFoundChannelFlag)
				{
					break;
				}
			}
		}    


		m_trace.m_bIsInitialized = MTRUE;
		nResult = MTRUE;

	}while(0);

	if (MNULL != pFilebuf)
	{
		med_ext_sfree((MBYTE *)pFilebuf);
		pFilebuf = MNULL;
	}

	if (fd >= 0)
	{
		FS_Close(fd);
		fd = -1;
	}    

	return nResult;
}

MVOID McfLog_PrintMethod(MCHAR level, MCHAR channel,const MCHAR *format, ...)
{
	{
		va_list arg_list;  
		MUINT nTimeMs = -1;

		do
		{ 
			if(MFALSE == m_trace.m_bIsInitialized)
			{
				if(ReadLcFile() != MTRUE)
				{
					break;
				}
			}

			if(0 == m_trace.m_ChannelControl[channel])
			{            
				break;
			}

			if(m_trace.m_ChannelLevel[channel] > level)
			{            
				break;
			}

			memset(m_trace.m_pTmpBuf, 0, TRACE_MAX_LOG_LENGTH);  

			kal_get_time(&nTimeMs);
			_snprintf(m_trace.m_pTmpBuf, TRACE_MAX_LOG_LENGTH, "[%s][%s][%d]", levelconst[level], channelconst[channel], nTimeMs);

			va_start(arg_list, format);
			{
				MINT nStrLen = strlen(m_trace.m_pTmpBuf);   
				if (nStrLen < TRACE_MAX_LOG_LENGTH)
				{
					memset(m_trace.m_pTmpBuf + nStrLen, ' ', TRACE_MAX_LOG_LENGTH - nStrLen);        
				}
				_vsnprintf(((MCHAR*)m_trace.m_pTmpBuf) + ATRACE_MAX_CHANNEL_INFO_STR_LENGTH, 
					TRACE_MAX_LOG_LENGTH - ATRACE_MAX_CHANNEL_INFO_STR_LENGTH, 
					(const MCHAR *)format, arg_list);

				MTRACEANDLOG8(("%s", m_trace.m_pTmpBuf));
			}                       
			va_end(arg_list);

		}while(0);
	}

}


#else


MVOID McfLog_PrintMethod(MCHAR level, MCHAR channel,const MCHAR *format, ...)
{
}

#endif






/*====================== USB =========================*/
#include "McfUsb.h"
#include "McfPlatform.h"


MBOOL McfUsb_IsInMassStorageMode(MVOID)
{

	MBOOL ret = MFALSE;
#ifdef __USB_IN_NORMAL_MODE__

#if MCR_MTK_VER >= MTK_VER_1132  //by purple
	ret = (MUINT)srv_usb_is_in_mass_storage_mode();
#else
	ret = (MUINT)mmi_usb_is_in_mass_storage_mode();
#endif

#endif
	return ret;
}

//charmenli add 2012-5-29 fixed USB/MTP环境下，提示语与MTK一致
MUINT16 McfUsb_GetMassStorageModeWarningStrId(MVOID)
{
	MUINT16 string_id = 0;
	mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
	#ifndef WIN32
	#ifdef __COSMOS_MMI_PACKAGE__
	string_id = vapp_usb_get_error_info (SRV_USB_ERROR_UNAVAILABLE, &event_type);
    #else
	string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
    #endif
	#endif
	return string_id;
}



/*=================== Vibrate =================*/
#include "McfVibrate.h"
#include "McfPlatform.h"

MVOID McfVib_PlayVibratorOnce(MVOID)
{
#if MCR_MTK_VER >= MTK_VER_1112 
    srv_vibrator_play_sms_once();
#else
	PlayVibratorOnce();
#endif
}

static MINT g_isPhbBusy = MFALSE;
static pfnPhbNotifyCb g_fnPhbNotifyFunc=MNULL;
static MVOID *g_pPhbUser=MNULL;

#if MCR_MTK_VER >= MTK_VER_1012
/*phonebook basic interface get/add/update/delete
* contact id,[1~sim1存储的电话数目]
                   [1~phone存储的电话数]
                   [1~sim2存储的电话数]
  storage 
  (id,storage)确定一条联系人
* arlo
*/
#include "phbsrvgprot.h"
static srv_phb_sdk_contact_struct g_sdkContact;
static srv_phb_sdk_contact_struct * g_pPhbContact = (srv_phb_sdk_contact_struct *)&g_sdkContact;
extern MMI_BOOL srv_phb_sdk_is_phb_ready(void);

static MINT __SrvStorageToMcf(phb_storage_enum eSrvStorage)
{
    MINT nStorage;
    
	switch (eSrvStorage)
	{
	case PHB_STORAGE_SIM:
	    nStorage = MPHB_ST_SIM1;
    	break;
	case PHB_STORAGE_SIM2:
	    nStorage = MPHB_ST_SIM2;	
    	break;
    case PHB_STORAGE_NONE:
	    nStorage = MPHB_ST_NONE;	    
        break;
    case PHB_STORAGE_MAX:
        nStorage = MPHB_ST_ALL;	    
        break;
	case PHB_STORAGE_NVRAM:
	default:
        nStorage = MPHB_ST_PHONE;
    	break;
	}

	return nStorage;
}


static phb_storage_enum __McfStorageToSrv(MINT nStorage)
{
	phb_storage_enum eSrvStorage = PHB_STORAGE_NVRAM;
	
	switch (nStorage)
	{
	case MPHB_ST_SIM1:
		eSrvStorage = PHB_STORAGE_SIM;
		break;
	case MPHB_ST_SIM2:
		eSrvStorage = PHB_STORAGE_SIM2;
		break;
	case MPHB_ST_PHONE:
		eSrvStorage = PHB_STORAGE_NVRAM;
		break;
	case MPHB_ST_ALL:
		eSrvStorage = PHB_STORAGE_MAX;
		break;				
	case MPHB_ST_NONE:
		eSrvStorage = PHB_STORAGE_NONE;
		break;
	default:
		break;
	}

	return eSrvStorage;
	
}

static void __PhbEntryToSrvContact(srv_phb_sdk_contact_struct *pContact, const McfPhbEntry *pEntry)
{//convert entry-struct to contact-struct
	if(pEntry && pContact)
	{
        pContact->pos.index = (U16)pEntry->id;
        pContact->pos.storage =(U8) __McfStorageToSrv(pEntry->storage);
    	mmi_wcsncpy((U16 *)pContact->name, (const U16 *)pEntry->name, MMI_PHB_NAME_LENGTH);
    	mmi_wcsncpy((U16 *)pContact->number, (const U16 *)pEntry->number, MMI_PHB_NUMBER_LENGTH);
    	//pContact->group_mask = pEntry->groupIdx;
    #if (defined(__MMI_PHB_OPTIONAL_FIELD__))
    	mmi_wcsncpy((U16 *)pContact->home_number, (const U16 *)pEntry->homeNumber, MMI_PHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pContact->office_number, (const U16 *)pEntry->officeNumber, MMI_PHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pContact->fax_number, (const U16 *)pEntry->faxNumber, MMI_PHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pContact->email_address, (const U16 *)pEntry->emailAddr, MMI_PHB_EMAIL_LENGTH);
    	mmi_wcsncpy((U16 *)pContact->company_name, (const U16 *)pEntry->companyName, MMI_PHB_COMPANY_LENGTH);
      #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_wcsncpy((U16 *)pContact->email_address2, (const U16 *)pEntry->emailAddr2, MMI_PHB_EMAIL_LENGTH);
      #endif  
    #endif 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        pContact->birth_day = pEntry->birthDay;
        pContact->birth_mon = pEntry->birthMon;
        pContact->birth_year = pEntry->birthYear;
    #endif


    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_wcsncpy((U16 *)pContact->title, (const U16 *)pEntry->title, MMI_PHB_TITLE_LENGTH);
        mmi_wcsncpy((U16 *)pContact->url, (const U16 *)pEntry->url, MMI_PHB_URL_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_pobox, (const U16 *)pEntry->adrPobox, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_extension, (const U16 *)pEntry->adrExtension, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_street, (const U16 *)pEntry->adrStreet, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_city, (const U16 *)pEntry->adrCity, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_state, (const U16 *)pEntry->adrState, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_postal_code, (const U16 *)pEntry->adrPostalCode, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->adr_country, (const U16 *)pEntry->adrCountry, MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16 *)pContact->note, (const U16 *)pEntry->note, MMI_PHB_NOTE_LENGTH);
    #endif
    }
	
}


static void __SrvContactToPhbEntry(McfPhbEntry *pEntry, const srv_phb_sdk_contact_struct *pContact)
{//convert contact-struct to entry-struct
	if(pEntry && pContact)
	{
        pEntry->id = pContact->pos.index;
    	pEntry->storage = __SrvStorageToMcf(pContact->pos.storage);
    	
    	mmi_wcsncpy(( U16 *)pEntry->name, (const U16 *)pContact->name,  MPHB_NAME_LENGTH);
    	mmi_wcsncpy(( U16 *)pEntry->number, (const U16 *)pContact->number, MPHB_NUMBER_LENGTH);
    	//pEntry->groupIdx = pContact->group_mask;
    #if (defined(__MMI_PHB_OPTIONAL_FIELD__))
    	mmi_wcsncpy((U16 *)pEntry->homeNumber, (const U16 *)pContact->home_number, MPHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pEntry->officeNumber, (const U16 *)pContact->office_number, MPHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pEntry->faxNumber, (const U16 *)pContact->fax_number, MPHB_NUMBER_LENGTH);
    	mmi_wcsncpy((U16 *)pEntry->emailAddr, (const U16 *)pContact->email_address, MPHB_EMAIL_LENGTH);
    	mmi_wcsncpy((U16 *)pEntry->companyName, (const U16 *)pContact->company_name, MPHB_COMPANY_LENGTH);
      #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_wcsncpy((U16 *)pEntry->emailAddr2, (const U16 *)pContact->email_address2, MPHB_EMAIL_LENGTH);
      #endif  
    #endif 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        pEntry->birthDay= pContact->birth_day;
        pEntry->birthMon= pContact->birth_mon;
        pEntry->birthYear= pContact->birth_year;
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_wcsncpy(pEntry->title,(U16 *)pContact->title, MPHB_TITLE_LENGTH);
        mmi_wcsncpy(pEntry->url,(U16 *)pContact->url, MPHB_URL_LENGTH);
        mmi_wcsncpy(pEntry->adrPobox,(U16 *)pContact->adr_pobox, MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrExtension,(U16 *)pContact->adr_extension, MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrStreet,(U16 *)pContact->adr_street,MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrCity,(U16 *)pContact->adr_city,MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrState,(U16 *)pContact->adr_state,MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrPostalCode,(U16 *)pContact->adr_postal_code, MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->adrCountry,(U16 *)pContact->adr_country,MPHB_ADDRESS_LENGTH);
        mmi_wcsncpy(pEntry->note,(U16 *)pContact->note, MPHB_NOTE_LENGTH);
    #endif
	}
	
}

static MINT __CvtSrvError(MINT nError)
{
    MINT nRet;

    switch(nError)
    {
    case SRV_PHB_NO_ERROR:
        nRet = MPHB_SUCCESS;
        break;
    case SRV_PHB_NOT_FOUND:
        nRet = MPHB_NOT_FOUND;
        break;
    case SRV_PHB_STORAGE_FULL:

#if MCR_MTK_VER < MTK_VER_1132  //by purple
    case SRV_PHB_PHONE_STORAGE_FULL:
    case SRV_PHB_SIM_STORAGE_FULL:
    case SRV_PHB_SIM2_STORAGE_FULL:
#endif    
    case SRV_PHB_STORAGE_EMPTY:

#if MCR_MTK_VER < MTK_VER_1132  //by purple    
    case SRV_PHB_PHONE_STORAGE_EMPTY:
    case SRV_PHB_SIM_STORAGE_EMPTY:
    case SRV_PHB_SIM2_STORAGE_EMPTY :
#endif
        nRet = MPHB_STORAGE_FULL;
        break;
    default:
        nRet = MPHB_ERROR;
        break;
    }

    return nRet;
}
 
static void __SrvOpPhbCallback(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{//internal func,operate phonebook callback
    pfnPhbNotifyCb fnPhbNotifyFunc=MNULL;
    MVOID *pPhbUser=MNULL;

    pPhbUser = g_pPhbUser;
    fnPhbNotifyFunc = g_fnPhbNotifyFunc;
    
    g_fnPhbNotifyFunc = MNULL;
    g_pPhbUser = MNULL;
	g_isPhbBusy = MFALSE;
    if(fnPhbNotifyFunc != MNULL)
    {
        result = __CvtSrvError(result);
        if (contact_ptr != MNULL)
        {
            fnPhbNotifyFunc(pPhbUser, result, contact_ptr->pos.index, __SrvStorageToMcf(contact_ptr->pos.storage));
        }
        else
        {
            fnPhbNotifyFunc(pPhbUser, result, -1, MPHB_ST_NONE);        
        }
    }
}

/****************************************************
* McfPhb_GetEntry
* @pUser --[in]
* @pEntry --[out]contact entry info
* @fnGetCb --[in]if it's an async request,callback function
* #return MPHB_SUCCESS -- success,found contact entry
        MPHB_WAIT async add req,result will be pass back through callback func(fnGetCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error,not found or else
*/
MINT McfPhb_GetEntry(McfPhbEntry *pEntry)
{
	srv_phb_sdk_contact_struct *    pContact;
	srv_phb_sdk_get_req_struct      reqInfo;
	S32 nResult = 0;
	MINT nStorage =PHB_STORAGE_NONE;
	U16 nRecordIdx = 0;

    //g_pPhbUser = pUser;
    //g_fnPhbNotifyFunc = fnGetCb;
	if (pEntry == MNULL)
	{
		return MPHB_ERROR;
	}
    
	pContact = (srv_phb_sdk_contact_struct *)g_pPhbContact;
	memset(pContact, 0, sizeof(srv_phb_sdk_contact_struct));

	nRecordIdx = pEntry->id;
	nStorage = __McfStorageToSrv(pEntry->storage);
	reqInfo.pos.index = nRecordIdx;
	reqInfo.pos.storage = nStorage;
	reqInfo.contact_ptr = pContact;

	nResult = srv_phb_sdk_get_contact(&reqInfo);
	if (nResult == SRV_PHB_NO_ERROR)
	{
	    pContact->pos.index = nRecordIdx;
	    pContact->pos.storage = nStorage;
		__SrvContactToPhbEntry(pEntry, pContact);
	}

    nResult = __CvtSrvError(nResult);

	return nResult;

}


/*************************************
* McfPhb_AddEntry
* @pUser --[in]
* @pEntry --[in] contact info to be added
* @fnAddCb --[in] callback function after add
* #return >0 --entry id [1,n]
        MPHB_WAIT -- async add req,result will be pass back through callback func(fnAddCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/
MINT McfPhb_AddEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnAddCb)
{
	MINT nRet = MPHB_ERROR;
	srv_phb_sdk_contact_struct * pContact;
	srv_phb_sdk_add_req_struct reqInfo;

	if(g_isPhbBusy)
	{
	    return MPHB_BUSY;
	}
	g_isPhbBusy = MTRUE;

	if (pEntry != NULL)
	{
		g_fnPhbNotifyFunc = fnAddCb;
		g_pPhbUser = pUser;

		memset((void *)&reqInfo, 0, sizeof(srv_phb_sdk_add_req_struct));

		pContact = (srv_phb_sdk_contact_struct *)g_pPhbContact;
		memset(pContact, 0, sizeof(srv_phb_sdk_contact_struct));
		__PhbEntryToSrvContact(pContact, pEntry);

		reqInfo.contact_ptr = pContact;
		reqInfo.storage = __McfStorageToSrv(pEntry->storage);

		srv_phb_sdk_add_contact(&reqInfo, __SrvOpPhbCallback);	
		nRet = MPHB_WAIT;
	}

	return nRet;

}

/*************************************
* McfPhb_UpdateEntry
* @pUser --[in]
* @pEntry --[in] contact info to be updated
* @fnUpdateCb --[in] callback function after update
* #return MPHB_SUCCESS ok
        MPHB_WAIT async add req,result will be pass back through callback func(fnUpdateCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/
MINT McfPhb_UpdateEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnUpdateCb)
{
	MINT nRet = MPHB_ERROR;
	srv_phb_sdk_contact_struct *    pContact;
	srv_phb_sdk_update_req_struct   reqInfo;

	if(g_isPhbBusy)
	{
	    return MPHB_BUSY;
	}
	g_isPhbBusy = MTRUE;
	
	if (pEntry != NULL)
	{
		g_pPhbUser = pUser;
		g_fnPhbNotifyFunc = fnUpdateCb;

		memset((void *)&reqInfo, 0, sizeof(srv_phb_sdk_update_req_struct));

		pContact = (srv_phb_sdk_contact_struct *)g_pPhbContact;
		memset(pContact, 0, sizeof(srv_phb_sdk_contact_struct));

		__PhbEntryToSrvContact(pContact, pEntry);

        reqInfo.pos.index = pContact->pos.index;
        reqInfo.pos.storage = pContact->pos.storage;
		reqInfo.contact_ptr = pContact;

		srv_phb_sdk_update_contact(&reqInfo, __SrvOpPhbCallback);

		nRet = MPHB_WAIT;
	}

	return nRet;

}


/*************************************
* McfPhb_DelEntry
* @pUser --[in]
* @nId --[in] contact id
* @nStorage [in]storage
* @fnDelCb --[in] callback function after update
* #return MPHB_SUCCESS ok
        MPHB_WAIT async add req,result will be pass back through callback func(fnDelCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/

MINT McfPhb_DelEntry(MVOID *pUser,MINT nId,MINT nStorage,pfnPhbNotifyCb fnDelCb)
{
	MINT nRet = MPHB_ERROR;

	srv_phb_sdk_delete_req_struct reqInfo;
	
	if(g_isPhbBusy)
	{
	    return MPHB_BUSY;
	}
	g_isPhbBusy = MTRUE;
	
	if( nId >0 )
	{        
		g_pPhbUser = pUser;
		g_fnPhbNotifyFunc = fnDelCb;

		srv_phb_store_index_to_record_index(nId-1, &(reqInfo.pos.storage), &(reqInfo.pos.index));
        reqInfo.pos.index = nId;
        reqInfo.pos.storage = __McfStorageToSrv(nStorage);
		srv_phb_sdk_delete_contact(&reqInfo, __SrvOpPhbCallback);
		nRet = MPHB_WAIT;		
	}

	return nRet;
}

/*****************************************
* McfPhb_QueryStatus
* query storage status
* @nStorage --[in]contact storage
* @pTotalCount --[out] total contact count allowed
* @pUsedCount --[out] used contact count already
* #return 
*/
MINT McfPhb_QueryStatus(MINT nStorage, MUSHORT *pTotalCount,MUSHORT *pUsedCount)
{
    phb_storage_enum ePhbStorage;

    if(srv_phb_sdk_is_phb_ready() == MFALSE)
    {
        return MPHB_BUSY;
    }
    
    ePhbStorage = __McfStorageToSrv(nStorage);
	if( pTotalCount != NULL)
	{
		*pTotalCount = srv_phb_get_total_contact(ePhbStorage);
	}
	
	if(pUsedCount != NULL)
	{
		*pUsedCount = srv_phb_get_used_contact(ePhbStorage);	
	}

	return MPHB_SUCCESS;
}
#else
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

#define McfPhbCalloc(n,s)    gui_malloc((n)*(s))
#define McfPhbFree(p)      gui_free(p)

/*<!--external-------*/
extern mmi_phb_context_struct g_phb_cntx;
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#if defined(__MMI_PHB_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 
#if defined(__MMI_PHB_INFO_FIELD__)
extern PHB_INFO_FIELDS_STRUCT PhoneBookInfoFields;
#endif
#if MCR_MTK_VER > MTK_VER_816
extern U8 mmi_phb_get_storage(U16 stroe_index);
#else
U8 mmi_phb_get_storage(U16 stroe_index)
{
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (stroe_index < MAX_PB_PHONE_ENTRIES)
    {
        return MMI_NVRAM;
    }
    else
    {
        return MMI_SIM;
    }
}
#endif

extern void mmi_phb_convert_get_ucs2_number(S8 *pString, U16 index);
extern BOOL mmi_phb_util_check_entry_exist(U16 store_index);

#define PHB_OP_ADD      (0)
#define PHB_OP_UPDATE   (1)
#define PHB_OP_DEL      (2)

static McfPhbEntry gPhbEntry;


static U16 __SrvEntryIdToStoreIndex(MINT nStorage, MINT nId)
{
#if MCR_MTK_VER>=MTK_VER_1012
    if (nStorage == MPHB_ST_PHONE)
    {
        if (nId <= MMI_PHB_PHONE_ENTRIES)
        {
            return nId - 1;
        }
    }
    else if (nStorage == MPHB_ST_SIM1)
    {
        if (nId <= MMI_PHB_SIM_ENTRIES)
        {
            return nId + MMI_PHB_PHONE_ENTRIES - 1;
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#else
 if (nStorage == MPHB_ST_PHONE)
    {
        if (nId <= MAX_PB_PHONE_ENTRIES)
        {
            return nId - 1;
        }
    }
    else if (nStorage == MPHB_ST_SIM1)
    {
        if (nId <= MAX_PB_SIM_ENTRIES)
        {
            return nId + MAX_PB_PHONE_ENTRIES - 1;
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif
}

static MINT __SrvStoreIndexToEntryId(U16 store_index)
{
#if MCR_MTK_VER>=MTK_VER_1012
    if (store_index >= MAX_PB_ENTRIES)
    {
        return -1;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        //*storage = PHB_STORAGE_SIM;
        return store_index - MAX_PB_PHONE_ENTRIES + 1;
    }
    else
    {
        //*storage = PHB_STORAGE_NVRAM;
        return store_index + 1;
    }
#else
  if (store_index >= MAX_PB_ENTRIES)
    {
        return -1;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        //*storage = PHB_STORAGE_SIM;
        return store_index - MAX_PB_PHONE_ENTRIES + 1;
    }
    else
    {
        //*storage = PHB_STORAGE_NVRAM;
        return store_index + 1;
    }
#endif
}

static MINT __McfStorageToSrv(MINT nStorage)
{
    MINT nRet;
    switch(nStorage)
    {
        case MPHB_ST_SIM1:
            nRet = MMI_SIM;
            break;
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        case MPHB_ST_PHONE:
            nRet = MMI_NVRAM;
            break;
       case MPHB_ST_ALL:
            nRet = MMI_STORAGE_BOTH;
            break;
       default:
            nRet = MMI_STORAGE_NONE;
            break;
    }
    return nRet;
}

static MINT __SrvStorageToMcf(MINT nStorage)
{
    MINT nRet;

	switch(nStorage)
	{
	case MMI_SIM:
		nRet = MPHB_ST_SIM1;
		break;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	case MMI_NVRAM:
		nRet = MPHB_ST_PHONE;
		break;
	case MMI_STORAGE_BOTH:
		nRet = MPHB_ST_ALL;
		break;
	default:
		nRet = MPHB_ST_PHONE;
		break;
	}

	return nRet;

}


void __SrvUpdateOptionalField(U16 store_index, U8 storage, U8 type,McfPhbEntry *pEntry)
{
    S16 pError;
    U8 optid_record;
    U8 optid_index;

    /* U8 grpIndex; */
    PHB_OPTIONAL_IDS_STRUCT tempIDs={0};
    PHB_OPTIONAL_IDS_STRUCT PhbOptIDs[OPTIONAL_IDS_RECORD_TOTAL];

    if(pEntry == MNULL)
    {
        return ;

    }

#if defined(__MMI_PHB_OPTIONAL_FIELD__)
    if (mmi_ucs2strlen((const S8*)pEntry->homeNumber))
    {
        mmi_phb_number_remove_invalid_character((S8*)pEntry->homeNumber);
    }
    if (mmi_ucs2strlen((const S8*)pEntry->officeNumber))
    {
        mmi_phb_number_remove_invalid_character((S8*)pEntry->officeNumber);
    }
    if (mmi_ucs2strlen((const S8*)pEntry->faxNumber))
    {
        mmi_phb_number_remove_invalid_character((S8*)pEntry->faxNumber);
    }
    
    if (storage == MMI_NVRAM)
    {
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.homeNumber, (PS8)pEntry->homeNumber);
        mmi_ucs2cpy((PS8) PhoneBookOptionalFields.companyName, (const PS8)pEntry->companyName);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.emailAddress, (PS8)pEntry->emailAddr);
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.emailAddress2, (PS8)pEntry->emailAddr2);
    #endif
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.officeNumber, (PS8)pEntry->officeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.faxNumber, (PS8)pEntry->faxNumber);

        WriteRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 

    /*
     *  Update optional selection field (id), and caller group counter
     */
    /* Read out related optional id record */
    optid_record = (store_index / OPTIONAL_IDS_RECORD_TOTAL) + 1;
    optid_index = store_index - (optid_record - 1) * OPTIONAL_IDS_RECORD_TOTAL;
    ReadRecord(NVRAM_EF_PHB_IDS_LID, optid_record, (void*)PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);

    /* Update associate id and write it back */
    memcpy(&PhbOptIDs[optid_index], &tempIDs, sizeof(PHB_OPTIONAL_IDS_STRUCT));
    WriteRecord(NVRAM_EF_PHB_IDS_LID, optid_record, PhbOptIDs, OPTIONAL_IDS_RECORD_SIZE, &pError);
}

void __SrvUpdateInfoField(U16 store_index,McfPhbEntry *pEntry)
{
#if defined(__MMI_PHB_INFO_FIELD__)
    S16 pError;
    U8 info_occupied_status = 0;
    
    /* Update information fields. */
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.title, (const S8*)pEntry->title);
    mmi_ucs2_to_asc((PS8) PhoneBookInfoFields.url, (PS8)pEntry->url);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.pobox, (const S8*)pEntry->adrPobox);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.extension, (const S8*)pEntry->adrExtension);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.street, (const S8*)pEntry->adrStreet);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.city, (const S8*)pEntry->adrCity);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.state, (const S8*)pEntry->adrState);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.postalcode, (const S8*)pEntry->adrPostalCode);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address.country, (const S8*)pEntry->adrCountry);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.note, (const S8*)pEntry->note);
    if (mmi_ucs2strlen((const S8*)pEntry->adrPobox) 
        || mmi_ucs2strlen((const S8*)pEntry->adrExtension) 
        || mmi_ucs2strlen((const S8*)pEntry->adrStreet) 
        || mmi_ucs2strlen((const S8*)pEntry->adrCity) 
        || mmi_ucs2strlen((const S8*)pEntry->adrState) 
        || mmi_ucs2strlen((const S8*)pEntry->adrPostalCode) 
        || mmi_ucs2strlen((const S8*)pEntry->adrCountry))
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_ADDRESS;
        info_occupied_status = 1;
    }
    else
    {
        PhoneBook[store_index].field &= ~MMI_PHB_ENTRY_FIELD_ADDRESS;
    }
    WriteRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookInfoFields,
        MMI_PHB_INFO_RECORD_SIZE,
        &pError);
    WriteRecord(
        NVRAM_EF_PHB_INFO_OCCUPIED_LID,
        (U16) (store_index + 1),
        (void*)&info_occupied_status,
        NVRAM_EF_PHB_INFO_OCCUPIED_SIZE,
        &pError);
 #endif
}

static MVOID __SrvOpPhbCallback(MINT nResult, MINT nId,MINT nStorage)
{//internal func,operate phonebook callback
    pfnPhbNotifyCb fnPhbNotifyFunc=MNULL;
    MVOID *pPhbUser=MNULL;

    pPhbUser = g_pPhbUser;
    fnPhbNotifyFunc = g_fnPhbNotifyFunc;
    g_fnPhbNotifyFunc = MNULL;
    g_pPhbUser = MNULL;
	g_isPhbBusy = MFALSE;
    
    if(fnPhbNotifyFunc != MNULL)
    {
        fnPhbNotifyFunc(pPhbUser, nResult, nId, nStorage);      //murphy 
    }

	memset(&gPhbEntry,0,sizeof(McfPhbEntry));
}

U16 __SrvUpdateEntry(int op,mmi_phb_set_entry_rsp_struct*info,McfPhbEntry *entry)
{/* Set Entry Success */
    MINT nResult = MPHB_SUCCESS;
    U16 store_index;
    U16 deletedCnt = 0;      //murphy
    U8 flag = 0;
    S8 *pHomeNum,*pOfficeNum,*pFaxNum,*pEmailAddr;

    pHomeNum = pOfficeNum = pFaxNum = pEmailAddr = MNULL;    
    store_index = __SrvEntryIdToStoreIndex(entry->storage,entry->id);//info->list[0].index;
    
    if (info->list[0].storage == MMI_NVRAM)
    {
        __SrvUpdateOptionalField(store_index, MMI_NVRAM, 1,entry);

      #if defined(__MMI_PHB_OPTIONAL_FIELD__)
        pHomeNum = (S8*) PhoneBookOptionalFields.homeNumber;
        pFaxNum = (S8*) PhoneBookOptionalFields.faxNumber;
        pOfficeNum = (S8*) PhoneBookOptionalFields.officeNumber;
        pEmailAddr = (S8*)PhoneBookOptionalFields.emailAddress;
      #endif
    }
    else    
    {/* in MMI_SIM,Associate caller group in SIM card entry */
      #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     
       mmi_phb_op_update_optional_field(store_index, MMI_SIM, 1);
      #endif 
    }

    /* Populate Number Field */
   // if(op == PHB_OP_UPDATE){    //murphy
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);
   // }
    flag = mmi_phb_op_increase_lookup_table(store_index, (S8*) info->list[0].tel.number, 
                                                        pFaxNum, pHomeNum, pOfficeNum);
    if (deletedCnt || flag)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    mmi_phb_op_set_entry_rsp_name_number(&info->list[0], store_index);

    mmi_phb_op_update_field_flag(store_index, (S8*) info->list[0].tel.number, 
                                         pHomeNum, pOfficeNum,pFaxNum,pEmailAddr,MTRUE);
    if (info->list[0].storage == MMI_NVRAM)
    {
      #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_phb_op_update_email2_field_flag(
            store_index,
            (S8*) PhoneBookOptionalFields.emailAddress2,
            TRUE);
      #endif 
      #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
      {/* Save birthday field */
        S8 year[12],mon[6],day[6];
        kal_wsprintf((unsigned short *)year, "%u",entry->birthYear);
        kal_wsprintf((unsigned short *)mon, "%u",entry->birthMon);
        kal_wsprintf((unsigned short *)day, "%u",entry->birthDay);
        mmi_phb_bday_update_field(store_index, (S8*) year, (S8*) mon, (S8*) day);
      }
      #endif 
      
      #if defined(__MMI_PHB_INFO_FIELD__)
        __SrvUpdateInfoField(store_index,entry);
      #endif 
      
      #if defined(__MMI_IMPS__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
        mmi_phb_service_update_field(store_index);
      #endif 
      
      #if defined(__MMI_PHB_EMAIL_SORT__)
      if (g_phb_email_sorted == 1)
      {/* Insert email to email mapping table */
          if(op == PHB_OP_UPDATE){
            mmi_phb_sort_email_delete_index(store_index);
          }
          mmi_phb_sort_email_insert_index(store_index);
      }
      #endif 
   }
        
    if (PhoneBook[store_index].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        mmi_phb_og_reset_default_number(store_index);
        mmi_phb_update_default_number(store_index);
    #endif
    
    /* Update Pinyin Cache for sort */
    #if defined(__MMI_PHB_PINYIN_SORT__)
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

    /* Insert name to name mapping table. */
    if(op == PHB_OP_UPDATE){
        mmi_phb_op_delete_update_index(store_index);
    }
    mmi_phb_sort_insert_name_index(store_index);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    
}

void __SrvOpAddEntryRsp(void *info)
{
    MINT nResult;
    U16 store_index;
    mmi_phb_set_entry_rsp_struct *localPtr;

    localPtr = (mmi_phb_set_entry_rsp_struct*) info;

    if (localPtr->result.flag == 0) 
    {
        nResult = MPHB_SUCCESS;
        store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);
        gPhbEntry.id = __SrvStoreIndexToEntryId(store_index);
        __SrvUpdateEntry(PHB_OP_ADD,localPtr, &gPhbEntry);
    }
    else    
    {/* Set Record Fail. */
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
        {
            nResult = MPHB_STORAGE_FULL;
        }
        else
        {
            nResult = MPHB_ERROR;
        }
    }

    __SrvOpPhbCallback(nResult,gPhbEntry.id,__SrvStorageToMcf(localPtr->list[0].storage));
}


void __SrvOpEditEntryRsp(void *info)
{
    MINT nResult;
    mmi_phb_set_entry_rsp_struct *localPtr;
    U16 store_index;
    U16 record_index;
    U8 storage;    

    localPtr = (mmi_phb_set_entry_rsp_struct*) info;

#if MCR_MTK_VER>MTK_VER_812
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_OP_EDIT_ENTRY_RSP);
#endif

    if (localPtr->result.flag == 0) 
    {/* Edit Entry OK */
        nResult = MPHB_SUCCESS;
        store_index =__SrvEntryIdToStoreIndex(gPhbEntry.storage, gPhbEntry.id);
        storage = mmi_phb_get_storage(store_index);
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_ENTRY_FIELD_NUMBER, (U8*)gPhbEntry.name, (U8*) gPhbEntry.number);
    #if defined(__MMI_PHB_OPTIONAL_FIELD__)
        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_ENTRY_FIELD_HOME, (U8*) gPhbEntry.name, (U8*) gPhbEntry.homeNumber);
        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_ENTRY_FIELD_OFFICE, (U8*) gPhbEntry.name, (U8*) gPhbEntry.officeNumber);
        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_ENTRY_FIELD_FAX, (U8*) gPhbEntry.name, (U8*) gPhbEntry.faxNumber);
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

        __SrvUpdateEntry(PHB_OP_UPDATE, localPtr, &gPhbEntry);
        
    }
    else
    {
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
        {
            nResult = MPHB_STORAGE_FULL;
        }
        else
        {
            nResult = MPHB_ERROR;
        }
    }
    __SrvOpPhbCallback(nResult,gPhbEntry.id,__SrvStorageToMcf(localPtr->list[0].storage));
}


void __SrvOpDeleteEntryRsp(void *info)
{
    MINT nResult ;
    mmi_phb_del_entry_rsp_struct *localPtr;
    U16 deletedCnt = 0;
    U16 store_index;
    U16 record_index;
    U8 storage;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)    
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB_CALLER_GROUP_STRUCT* callerGroups; */

    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;

#if MCR_MTK_VER>MTK_VER_812
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_OP_DELETE_ENTRY_RSP);
#endif

    if (localPtr->result.flag == 0 /* OK */ )
    {
        nResult = MPHB_SUCCESS;
        store_index = __SrvEntryIdToStoreIndex(gPhbEntry.storage, gPhbEntry.id);
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_ENTRY_FIELD_ALL_NUMBER, NULL, NULL);

        if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
        #if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */ 
        }
        else
        {
            g_phb_cntx.phone_used--;
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            /* Delete image file in file folder */
            mmi_phb_read_optional_ids(store_index);
            opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

            if ((opt_ids->pictureTagID == 1)
            #ifdef __MMI_AVATAR__
                || (opt_ids->pictureTagID == 2)
            #endif
                )
            {
                mmi_phb_image_delete_by_index(record_index);
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
            /* Delete incoming call video */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
        #endif 
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            mmi_phb_bday_delete_field(store_index);	
        #endif 

            /* Remove email entry from email sort mapping table */
        #if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, store_index);
        #endif
        }

        /* Remove lookup table entry */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

        if (deletedCnt)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

    #if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(store_index);
    #endif /* defined(__MMI_VRSD_DIAL__) */ 

    #if defined(__MMI_VRSI__)
        /* remove voice dial tag if exists. */
        mmi_vrsi_ndial_central_delete_single(store_index);
    #endif /* defined(__MMI_VRSI__) */ 

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(store_index);
        /* add tdl query screen into history */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
	#if MCR_MTK_VER > MTK_VER_812
           mmi_tdl_bday_reminder_delete_query(MMI_FALSE, store_index);
	#else
	   mmi_phb_bday_delete_field( store_index );
	#endif
        #endif 
    }
    else
    {
        nResult = MPHB_ERROR;
    }


    __SrvOpPhbCallback(nResult,gPhbEntry.id,__SrvStorageToMcf(localPtr->list[0].storage));

}

/****************************************************
* McfPhb_GetEntry
* @pUser --[in]
* @pEntry --[out]contact entry info
* @fnGetCb --[in]if it's an async request,callback function
* #return MPHB_SUCCESS -- success,found contact entry
        MPHB_WAIT async add req,result will be pass back through callback func(fnGetCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error,not found or else
*/
MINT McfPhb_GetEntry(McfPhbEntry *pEntry)
{
    MINT i;
    MBOOL bFound = MFALSE;
    MINT nLen=0;
    S16 error;
    MUINT8 nStorage;
    U16 nStoreIdx;
    

    //do nothing if phonebook is not ready or busy
    if(!mmi_phb_check_ready(MFALSE) ||pEntry == MNULL)
    {
        return MPHB_ERROR;
    }

    nStoreIdx = __SrvEntryIdToStoreIndex(pEntry->storage,pEntry->id);
    if(!mmi_phb_util_check_entry_exist(nStoreIdx))
    {
        return MPHB_NOT_FOUND;
    }

    nStorage = __McfStorageToSrv(pEntry->storage);
    nLen = PhoneBook[nStoreIdx].alpha_id.name_length;
    if(nLen > MPHB_NAME_LENGTH)
    {
        nLen = MPHB_NAME_LENGTH;
    }
    mmi_ucs2ncpy((S8*)(pEntry->name), (const S8*)(PhoneBook[nStoreIdx].alpha_id.name), nLen);
    //nLen = PhoneBook[nStoreIdx].tel.length;
    //if(nLen > MPHB_NUMBER_MAX_LEN)
    //{
    //    nLen =MPHB_NUMBER_MAX_LEN;
    //}
    mmi_phb_convert_get_ucs2_number((S8 *)(pEntry->number), nStoreIdx);

    if (nStorage==MMI_NVRAM)        
    {//storage nvram           
  #if defined(__MMI_PHB_OPTIONAL_FIELD__)
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        MUSHORT bday_record, bday_index;
        MMI_PHB_BDAY_STRUCT *bday_data = McfPhbCalloc(1,sizeof(MMI_PHB_BDAY_STRUCT) * NVRAM_EF_PHB_BIRTHDAY_COUNT);
        #endif

       #if defined(__MMI_PHB_OPTIONAL_FIELD__)//optional field info
        ReadRecord(NVRAM_EF_PHB_FIELDS_LID,(U16) nStoreIdx+1,&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,&error);
            
        mmi_asc_to_ucs2((S8 *)pEntry->homeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_asc_to_ucs2((S8 *)pEntry->officeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2((S8 *)pEntry->faxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
        mmi_ucs2cpy((S8 *)pEntry->companyName, (PS8) PhoneBookOptionalFields.companyName);
        mmi_asc_to_ucs2((S8*)pEntry->emailAddr, (PS8)PhoneBookOptionalFields.emailAddress);
       #endif /* */
    
      #if defined(__MMI_PHB_BIRTHDAY_FIELD__)//birthday field info
        if (bday_data)
        {
            bday_record = (nStoreIdx / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
            bday_index = nStoreIdx % NVRAM_EF_PHB_BIRTHDAY_COUNT;
            
            ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &error);
            
            /* Year */
            if (bday_data[bday_index].bYear <= MMI_PHB_BDAY_MAX_YEAR_INT)
            {
                pEntry->birthYear = bday_data[bday_index].bYear;
            }
            
            /* Month */
            if (bday_data[bday_index].bMonth <= 12)
            {
                #if (MCR_MTK_VER >= MTK_VER_912)
                pEntry->birthMon = bday_data[bday_index].bMonth;
                #else
                pEntry->birthMon = bday_data[bday_index].bMon;
                #endif
            }
            
            /* Day */
            if (bday_data[bday_index].bDay <= 31)
            {
                pEntry->birthDay= bday_data[bday_index].bDay;
            }

            McfPhbFree(bday_data);
        }
      #endif
  #endif
    #if defined(__MMI_PHB_INFO_FIELD__)
                /* Information Fields */
        ReadRecord(NVRAM_EF_PHB_INFO_LID,(U16) (nStoreIdx+ 1),
                        (void*)&PhoneBookInfoFields,
                        MMI_PHB_INFO_RECORD_SIZE,&error);
        mmi_ucs2cpy( (PS8) pEntry->title,(const S8*)PhoneBookInfoFields.title);
        mmi_asc_to_ucs2( (PS8) pEntry->url,(S8*)PhoneBookInfoFields.url);
        mmi_ucs2cpy( (PS8)pEntry->adrPobox ,(const S8*)PhoneBookInfoFields.address.pobox);
        mmi_ucs2cpy( (PS8)pEntry->adrExtension, (const S8*)PhoneBookInfoFields.address.extension);
        mmi_ucs2cpy( (PS8) pEntry->adrStreet,(const S8*)PhoneBookInfoFields.address.street);
        mmi_ucs2cpy( (PS8)pEntry->adrCity, (const S8*)PhoneBookInfoFields.address.city);
        mmi_ucs2cpy( (PS8) pEntry->adrState,(const S8*)PhoneBookInfoFields.address.state);
        mmi_ucs2cpy( (PS8) pEntry->adrPostalCode,(const S8*)PhoneBookInfoFields.address.postalcode);
        mmi_ucs2cpy( (PS8) pEntry->adrCountry,(const S8*)PhoneBookInfoFields.address.country);
        mmi_ucs2cpy( (PS8)pEntry->note ,(const S8*)PhoneBookInfoFields.note);
    #endif
    }
    return MPHB_SUCCESS;
}

/*************************************
* McfPhb_AddEntry
* @pUser --[in]
* @pEntry --[in] contact info to be added
* @fnAddCb --[in] callback function after add
* #return >0 --entry id [1,n]
        MPHB_WAIT -- async add req,result will be pass back through callback func(fnAddCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/
MINT McfPhb_AddEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnAddCb)
{
    MUSHORT total, used;
    
     //do nothing if phonebook is not ready or busy
    if(!mmi_phb_check_ready(MFALSE) || g_phb_cntx.current_op !=MMI_PHB_OP_NONE ||pEntry == MNULL)
    {
        return MPHB_ERROR;
    }

    if(g_isPhbBusy)
	{
	    return MPHB_BUSY;
	}
	g_isPhbBusy = MTRUE;

    memcpy(&gPhbEntry,pEntry,sizeof(McfPhbEntry));
    
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        mmi_phb_set_entry_req_struct *myMsgPtr;
        MYQUEUE Message;
        myMsgPtr = (mmi_phb_set_entry_req_struct*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;
        myMsgPtr->list.storage = __McfStorageToSrv(pEntry->storage);
        myMsgPtr->list.index = 0xFFFF;
        myMsgPtr->list.record_index = 0xFFFF;

        mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, (S8*)pEntry->name, (S8*)pEntry->number);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;

        SetProtocolEventHandler(__SrvOpAddEntryRsp, PRT_PHB_SET_ENTRY_RSP);
        OslMsgSendExtQueue(&Message);
    }
    
    //keep callback function
    g_pPhbUser = pUser;
    g_fnPhbNotifyFunc = fnAddCb;
    return MPHB_WAIT;
}

/*************************************
* McfPhb_UpdateEntry
* @pUser --[in]
* @pEntry --[in] contact info to be updated
* @fnUpdateCb --[in] callback function after update
* #return MPHB_SUCCESS ok
        MPHB_WAIT async add req,result will be pass back through callback func(fnUpdateCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/
MINT McfPhb_UpdateEntry(MVOID *pUser, McfPhbEntry * pEntry,pfnPhbNotifyCb fnUpdateCb)
{
    MINT nStoreIdx;
    mmi_phb_set_entry_req_struct *myMsgPtr;
    MYQUEUE Message;
    U16 store_index = 0;
    U8 storage;
     //do nothing if phonebook is not ready or busy
    if(!mmi_phb_check_ready(MFALSE) || g_phb_cntx.current_op !=MMI_PHB_OP_NONE || pEntry == MNULL)
    {
        return MPHB_ERROR;
    }
    
    if(g_isPhbBusy)
	{
	    return MPHB_BUSY;
	}
	g_isPhbBusy = MTRUE;

    nStoreIdx = __SrvEntryIdToStoreIndex(pEntry->storage, pEntry->id);
    if(pEntry==MNULL ||!mmi_phb_util_check_entry_exist(nStoreIdx))
    {
        return MPHB_NOT_FOUND;
    }
    
    memcpy(&gPhbEntry,pEntry,sizeof(McfPhbEntry));
    
    //invoke request

    myMsgPtr = (mmi_phb_set_entry_req_struct*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    storage = __McfStorageToSrv(pEntry->storage);
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = storage;
    myMsgPtr->list.index = 0xffff;
    myMsgPtr->list.record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, (S8*)pEntry->name, (S8*)pEntry->number);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(__SrvOpEditEntryRsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
    //keep callback function
    g_pPhbUser = pUser;
    g_fnPhbNotifyFunc = fnUpdateCb;
    g_isPhbBusy = MTRUE;
    
    return MPHB_WAIT;

}

/*************************************
* McfPhb_DelEntry
* @pUser --[in]
* @nId --[in] contact id
* @nStorage --[in] storage
* @fnDelCb --[in] callback function after update
* #return MPHB_SUCCESS ok
        MPHB_WAIT async add req,result will be pass back through callback func(fnDelCb)
        MPHB_ERROR,MPHB_NOT_FOUND,MPHB_STORAGE_FULL --error
*/
MINT McfPhb_DelEntry(MVOID *pUser, MINT nId,MINT nStorage,pfnPhbNotifyCb fnDelCb)
{
    MUSHORT nStoreIdx = 0xffff;/* index is storage location in array, begin from 0. */
    mmi_phb_del_entry_req_struct *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U16 record_index;
    U8 storage;

    
     //do nothing if phonebook is not ready or busy
    if(!mmi_phb_check_ready(MFALSE) || g_phb_cntx.current_op !=MMI_PHB_OP_NONE)
    {
        return MPHB_ERROR;
    }

  //  if(g_isPhbBusy)                   //murphy
	//{
	    //return MPHB_BUSY;
	//}
	//g_isPhbBusy = MTRUE;

    gPhbEntry.id = nId;
	gPhbEntry.storage = nStorage;  //murphy
    nStoreIdx = __SrvEntryIdToStoreIndex(nStorage, nId);
    storage = __McfStorageToSrv(nStorage);
    if(!mmi_phb_util_check_entry_exist(nStoreIdx))// murphy
    {
        return MPHB_NOT_FOUND;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    {
        myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

        myMsgPtr->storage = storage;
        myMsgPtr->del_all = MMI_FALSE;
        myMsgPtr->no_data = 1;
        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        /*
         *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
         * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
         */
        myMsgPtr->index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;

        SetProtocolEventHandler(__SrvOpDeleteEntryRsp, PRT_PHB_DEL_ENTRY_RSP);
        OslMsgSendExtQueue(&Message);
    }
	  g_pPhbUser = pUser;         //murphy
	  g_fnPhbNotifyFunc = fnDelCb;

    return MPHB_WAIT;
}



/*****************************************
* McfPhb_QueryStatus
* query storage status
* @nStorage --[in]contact storage
* @pTotalCount --[out] total contact count allowed
* @pUsedCount --[out] used contact count already
* #return 
*/
MINT McfPhb_QueryStatus(MINT nStorage, MUSHORT *pTotalCount,MUSHORT *pUsedCount)
{
    MUSHORT total,used;
    
     //do nothing if phonebook is not ready or busy
    if(!mmi_phb_check_ready(MFALSE))
    {
        return MPHB_BUSY;
    }

	total = used = 0;
	switch(nStorage)
	{
		case MPHB_ST_PHONE:
			total = g_phb_cntx.phone_total;
			used = g_phb_cntx.phone_used;
			break;
		case MPHB_ST_SIM1:
			total= g_phb_cntx.sim_total;
			used = g_phb_cntx.sim_used;
			break;
		case MPHB_ST_SIM2:
		#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
	    #endif
			break;
		case MPHB_ST_ALL:
			total= g_phb_cntx.phone_total + g_phb_cntx.sim_total;
			used = g_phb_cntx.phone_used + g_phb_cntx.sim_used;
           #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
	       #endif
			break;	
		default:
			break;
	}	

    //feedback to caller
	if(pTotalCount)
	{
	  *pTotalCount = total;
	}
	if(pUsedCount)
	{
	  *pUsedCount = used;
	}
	
	return MPHB_SUCCESS;
}

MVOID McfPhbNotifyCallback(MINT result, MINT storeIdx, MINT storage)
{
    //dummy func,not used any more
}
#endif

MINT McfPhb_CancelOperation(MVOID *pUser,pfnPhbNotifyCb func)
{
	MINT nRet = MCR_FAIL;

    if(g_isPhbBusy && pUser == g_pPhbUser && func ==g_fnPhbNotifyFunc)
    {
        g_isPhbBusy = MFALSE;
        g_pPhbUser = MNULL;
        g_fnPhbNotifyFunc = MNULL;
		nRet = MCR_SUCCESS;
    }

	return nRet;
}

MINT McfPhb_QueryProperty(McfPhbProp *pProp)
{
    if(pProp)
    {
        MUINT mask = 0;
        
        mask |= MPHB_FILED_NAME|MPHB_FILED_NUMBER;
        #if defined(__MMI_PHB_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
         mask |= MPHB_FILED_HOMENUM;
         mask |= MPHB_FILED_OFFICENUM;
         mask |= MPHB_FILED_FAXNUM;
         mask |= MPHB_FILED_COMPANYNAME;
         mask |= MPHB_FILED_EMAIL;
         #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
          mask |= MPHB_FILED_EMAIL2;
         #endif
         #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
          mask |= MPHB_FILED_BIRTH;
         #endif
        #endif

        #if defined(__MMI_PHB_INFO_FIELD__)
          mask |= MPHB_FILED_TITLE;
          mask |= MPHB_FILED_URL;
          mask |= MPHB_FILED_ADR_POBOX;
          mask |= MPHB_FILED_ADR_EXT;
          mask |= MPHB_FILED_ADR_STREET;
          mask |= MPHB_FILED_ADR_CITY;
          mask |= MPHB_FILED_ADR_STATE;
          mask |= MPHB_FILED_ADR_POSTCODE;
          mask |= MPHB_FILED_ADR_COUNTRY;
          mask |= MPHB_FILED_NOTE;
        #endif
        
        pProp->mask = mask;
        #if MCR_MTK_VER >= MTK_VER_1012
        pProp->maxNameLen = MMI_PHB_NAME_LENGTH;
        pProp->maxNumLen = MMI_PHB_NUMBER_LENGTH;
        pProp->reserved1 = 0;
        pProp->reserved2 = 0;
        #else 
        pProp->maxNameLen = MAX_PB_NAME_LENGTH;
        pProp->maxNumLen = MAX_PB_NUMBER_LENGTH;
        pProp->reserved1 = 0;
        pProp->reserved2 = 0;
        #endif
    }
    return MPHB_SUCCESS;
}

typedef struct _McfPhbHandle
{
	MINT	nPhbHandle;
	MBOOL	bIsUsed;
	MINT	nIndex;
	MINT	nStorage;
}McfPhbHandle;

static McfPhbHandle g_phbHandle;


MINT McfPhb_FindFirst(MINT nStorage,McfPhbEntry *pEntry)
{
	McfPhbHandle* pHandle = MNULL;
	MINT nHd = MPHB_ERROR;

	if(MNULL == pEntry || g_phbHandle.bIsUsed)
	{
		return MPHB_ERROR;
	}

	pHandle = &g_phbHandle;
	if(pHandle)
	{
		MUSHORT nTotal;
		MINT nId;

		McfPhb_QueryStatus(nStorage, &nTotal, MNULL);
		for(nId = 1; nId<= nTotal; nId++)
		{
			pEntry->id = nId;
			pEntry->storage = nStorage;

			if(MPHB_SUCCESS == McfPhb_GetEntry(pEntry))
			{
				pHandle->nIndex = nId;
				pHandle->bIsUsed = MTRUE;
				pHandle->nPhbHandle = 1;
				nHd = pHandle->nPhbHandle;
				pHandle->nStorage = nStorage;
				break;
			}
		}
	}

	return nHd;
}

MINT McfPhb_FindNext(MINT nPhbHandle,McfPhbEntry *pEntry)
{
	McfPhbHandle* pHandle = MNULL;
	MINT nRet = MPHB_ERROR;

	if(MNULL == pEntry || nPhbHandle != g_phbHandle.nPhbHandle || nPhbHandle < 0)
	{
		return MPHB_ERROR;
	}

	pHandle = &g_phbHandle;
	if(pHandle && pHandle->bIsUsed)
	{
		MUSHORT nTotal;
		MINT nId;
		MINT nIndex = pHandle->nIndex + 1;

		McfPhb_QueryStatus(pHandle->nStorage, &nTotal, MNULL);
		if(nIndex < nTotal)
		{
			for(nId = nIndex; nId<= nTotal; nId++)
			{
				pEntry->id = nId;
				pEntry->storage = pHandle->nStorage;

				if(MPHB_SUCCESS == McfPhb_GetEntry(pEntry))
				{
					pHandle->nIndex = nId;
					nRet = MPHB_SUCCESS;
					break;
				}
			}
		}
	}

	return nRet;
}

MINT McfPhb_FindClose(MINT nPhbHandle)
{
	McfPhbHandle* pHandle = MNULL;
	MINT nRet = MPHB_SUCCESS;

	if(nPhbHandle != g_phbHandle.nPhbHandle || nPhbHandle < 0)
	{
		return MPHB_ERROR;
	}

	pHandle = &g_phbHandle;
	if(pHandle)
	{
	    //g_phbHandle.bIsUsed = MFALSE;
		memset(pHandle, 0, sizeof(McfPhbHandle));
		nRet = MPHB_SUCCESS;
	}

	return nRet;
}


#if MCR_CAMERA_SUPPORT == __CFG_YES__
#if !defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#error please disable MCR_CAMERA_SUPPORT  or enable  __MMI_CAMERA__ or __MMI_CAMCORDER__
#endif

#include "mdi_camera.h"
#include "CameraGprot.h"
static pfnCamNotify g_fnCamNotify;
static MVOID *g_pCamUser;
U16 __CvtCamId(MINT nCamId)
{
    if(nCamId == MCAM_ID_FRONT)
    {
        return MDI_CAMERA_SUB;
    }
    else
    {
        return MDI_CAMERA_MAIN;
    }
}

MINT __CvtCamErr(MINT nErr)
{
    McfTrace_TraceFormatA("[__CvtCamErr]error:%d",nErr);
    switch(nErr)
    {
     case MDI_RES_CAMERA_SUCCEED:
        return MCAM_SUCCESS;
     case MDI_RES_CAMERA_ERR_NO_DISK:
        return MCAM_NO_DISK;
     case MDI_RES_CAMERA_ERR_DISK_FULL:
        return MCAM_DISK_FULL;
     default:
        //if(nErr < 0 ) 
        //{
        //    return MCAM_ERROR;
        //}
        //else
        {
            return nErr;
        }
    }
}

void __CamResultCb(MMI_BOOL result, S8 *filepath)
{
    pfnCamNotify fnCamNotify;

    fnCamNotify = g_fnCamNotify;
    g_fnCamNotify = MNULL;
    if(fnCamNotify)
    {
        fnCamNotify(g_pCamUser,MCAM_STATUS_CAPTURE,result,filepath);
    }
}

#if defined(__MMI_CAMCORDER__)    
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#include "CamcorderResDef.h"
#include "CamcorderCuiGprot.h"
#include "CamcorderApp.h"
#include "CameraCuiGprot.h"

static mmi_id g_CamGid =0;
static void __CuiCamoClose(mmi_id cui_gid)
{  
    mmi_frm_group_close(cui_gid);
    mmi_frm_group_close(APPLIB_MEM_AP_ID_CAMCO);
}

static mmi_ret __CuiCamoGroupProc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	case CUI_CAMERA_EVENT_RESULT_SUCCESS:		
		__CamResultCb(MMI_TRUE, (PS8)((cui_camera_event_struct*)evt)->file_path);	
        __CuiCamoClose(g_CamGid);		
    	g_CamGid = 0;
		break; 
	case CUI_CAMERA_EVENT_RESULT_FAILED:		
		__CamResultCb(MMI_FALSE, NULL);
        __CuiCamoClose(g_CamGid);		
    	g_CamGid = 0;
		break;
	case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:		
        __CuiCamoClose(g_CamGid);		
    	g_CamGid = 0;
		break;
    case EVT_ID_MEM_FREE_ASM:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        __CuiCamoClose(g_CamGid);		
    	g_CamGid = 0;
        break;
	}
	return MMI_RET_OK;
}

static void __CuiCamoLaunch(mmi_proc_func fnCamProc)
{
    cui_camera_run_struct camera_struct;

    /* check if can launch or not */
    if (cui_camco_check_and_display_popup()) 
    {
        /* init param */
        cui_camera_struct_init(&camera_struct);

        /* create camcorder App screen group */
        /* attach proc mmi_camco_app_group_proc */
        mmi_frm_group_close(APPLIB_MEM_AP_ID_CAMCO);
        mmi_frm_group_create(GRP_ID_ROOT, APPLIB_MEM_AP_ID_CAMCO, fnCamProc, NULL);

        /* enter camcorder App screen group */
        mmi_frm_group_enter(APPLIB_MEM_AP_ID_CAMCO, 0);

        /* create camcorder CUI */
        g_CamGid =  cui_camera_create(APPLIB_MEM_AP_ID_CAMCO);

        /* excute camcorder CUI */
        cui_camera_run(g_CamGid, &camera_struct);
    }
}
#endif 


#endif

MINT McfCam_Open(MVOID *pUser,MINT nCamId,MINT nMode,pfnCamNotify fnCamNotify)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    MINT nRet;

    if(nMode == MCAM_MODE_USER)
    {
        nRet = mdi_camera_set_camera_id(__CvtCamId(nCamId));
        if(nRet == MDI_RES_CAMERA_SUCCEED)
        {
#if MCR_MTK_VER >= MTK_VER_1132  //by purple        
          nRet = mdi_camera_power_on(0);
#else
          nRet = mdi_camera_power_on();
#endif
          
        }
    }
    else
    {
        #ifdef __MMI_CAMCORDER__
        __CuiCamoLaunch(__CuiCamoGroupProc);
        nRet = MCAM_SUCCESS;
        #elif defined(__MMI_CAMERA__)
        nRet = MCAM_ERROR;//mmi_camera_entry_for_external_request(__CamResultCb);
        #endif
    }

    g_fnCamNotify = fnCamNotify;
    g_pCamUser = pUser;

    return __CvtCamErr(nRet);
#else
    return MCAM_ERROR;
#endif
}

MINT McfCam_Close(MINT nCamId,MINT nMode)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    MINT nRet;

    if(nMode == MCAM_MODE_USER)
    {
      nRet = mdi_camera_power_off();
    }
    else
    {
      nRet = MCAM_SUCCESS;
    }
    
    g_fnCamNotify = MNULL;
    g_pCamUser = MNULL;
    return __CvtCamErr(nRet);
#else
    return MCAM_ERROR;
#endif
}

MINT McfCam_StartPreview(McfCamParam *pParam)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    //not support now..@20111102
	return MCAM_ERROR;
#else
    return MCAM_ERROR;
#endif
}

MINT McfCam_StopPreview(MVOID)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    //not support now..@20111102
	return MCAM_ERROR;
#else
    return MCAM_ERROR;
#endif
}

MINT McfCam_CaptureToFile(MWCHAR *pFilepath,MINT *pImgFmt)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    //not support now..@20111102
	return MCAM_ERROR;
#else
    return MCAM_ERROR;
#endif
}

MINT McfCam_CaptureToMem(MBYTE **ppBuffer, MUINT *pSize,MINT *pImgFmt)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    //not support now..@20111102
	return MCAM_ERROR;
#else
    return MCAM_ERROR;
#endif
}


MINT McfCam_QueryProperty(McfCamProp *pProp)
{
#if MCR_CAMERA_SUPPORT == __CFG_YES__
    //not support now..@20111102
	return MCAM_ERROR;
#else
    return MCAM_ERROR;
#endif
}



static pfnCellInfoFunc g_fnCellRequestCb;
static int g_CellSelIdx;
static MVOID *g_CellUser;
#include "SimCtrlSrvGprot.h"
static MVOID __SendRequestCellInfo(MINT nDstMod)
{
	MYQUEUE Message;
	mmi_em_update_req_struct *em_start_req;

	U8 i=0;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        nDstMod = MOD_L4C;
    }

	Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;

	em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));

	for (i=0;i<EM_INFO_REQ_NUM;i++)
	{
	      em_start_req->info_request[i] = EM_NC;
	}

	em_start_req->info_request[RR_EM_LAI_INFO]=EM_ON;   
	Message.oslDataPtr = (oslParaType*) em_start_req;
	Message.oslPeerBuffPtr = NULL;
	Message.oslSrcId = MOD_MMI;
    Message.oslDestId = nDstMod;

	OslMsgSendExtQueue(&Message);
}

static MVOID __EmStatusEventHandler(MVOID *info)
{
	mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;
	pfnCellInfoFunc fnReqCb;
	McfCellInfo cellInfo = {0};
	
	McfTrace_TraceFormatA(__MCR_FUNCTION__"enter msg->em_info:%d",msg->em_info);

	if(g_CellSelIdx < 0)
	{
        return;
	}

	if(msg->em_info == RR_EM_LAI_INFO)
	{
		rr_em_lai_info_struct *data_ptr;
		
		kal_uint16 mm_pdu_len;
				
		data_ptr = (rr_em_lai_info_struct*) get_pdu_ptr(msg->info, &mm_pdu_len);
		
		McfTrace_TraceFormatA("cell id is 0x%x,LAC is 0x%02x%02x,MCC is 0x%02x%02x%02x,MNC is 0x%02x%02x%02x",
			data_ptr->cell_id,
			data_ptr->lac[0],data_ptr->lac[1],
			data_ptr->mcc[0],data_ptr->mcc[1],data_ptr->mcc[2],
			data_ptr->mnc[0],data_ptr->mnc[1],data_ptr->mnc[2]); 

	    cellInfo.cellId = data_ptr->cell_id;
	    memcpy(cellInfo.mcc,data_ptr->mcc,3); 
	    memcpy(cellInfo.mnc,data_ptr->mnc,3); 
	    memcpy(cellInfo.lac,data_ptr->lac,2); 

		fnReqCb = g_fnCellRequestCb;
		g_fnCellRequestCb = MNULL;
		if (fnReqCb != MNULL)
		{
			fnReqCb(g_CellUser, (McfCellInfo *)&cellInfo);
		}
	}
}

/***********************************************************************
* McfMisc_RequestCellInfo
    McfCellInfo cellInfo;
    //Cell Id 0x0f3c
    cellInfo.cellId= 0x0f3c

    //MCC 460
    cellInfo.mcc[0] =4;
    cellInfo.mcc[1] =6;
    cellInfo.mcc[2] =0;

    //MNC 01
    cellInfo.mnc[0]=0;
    cellInfo.mnc[1]=1;
    cellInfo.mnc[2]=0xf;

    //or MNC 470
    cellInfo.mnc[0]=4;
    cellInfo.mnc[1]=7;
    cellInfo.mnc[2]=0;

    //LAC 0x2623
    cellInfo.lac[0]=0x26;
    cellInfo.lac[1]=0x23;
    
*/
MINT McfMisc_RequestCellInfo(MINT nSimId, MVOID *pUser, pfnCellInfoFunc fnRequestCb)
{
    MINT nDstMod;

    if(nSimId == MSIM_NONE)
    {
        return MFALSE;
    }
    
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	{
      nDstMod = MOD_L4C;
      __clear_protocol_event_handler(MSG_ID_MMI_EM_UPDATE_RSP,NULL);


      __set_protocol_event_handler(__EmStatusEventHandler,MSG_ID_MMI_EM_STATUS_IND,MFALSE);

	  g_fnCellRequestCb = fnRequestCb;
	  g_CellUser = pUser; 
	  g_CellSelIdx = 0;
	}

    __SendRequestCellInfo(nDstMod);

    return MTRUE;
}



MVOID McfMisc_CancelCellInfo(MVOID * pUser, pfnCellInfoFunc fnRequestCb) /*(MINT nSimId)*/
{

	if(g_CellUser == pUser && g_fnCellRequestCb == fnRequestCb)
	{
		g_fnCellRequestCb = MNULL;
		g_CellUser = MNULL;
		g_CellSelIdx = -1;
	}
}

MINT McfMisc_DeliverMessage(MINT nAppId,MINT nEvtId,MVOID *pData,MINT nSize)
{//communicate between inner app and outer app, inner --> outer
	#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
    return MTRUE;
}

#if MCR_MTK_VER >= MTK_VER_1132

#undef  gdi_image_bmp_draw

#if MCR_MTK_VER<MTK_VER_1210//maomaolin add
#undef  gdi_layer_pop_clip
#undef  gdi_layer_push_clip


#ifndef GDI_SLIM_SUPPORT
extern void gdi_layer_pop_clip_ext(char* file_p, long line_p);
extern void gdi_layer_push_clip_ext(char* file_p, long line_p);
#else
extern void  gdi_layer_pop_clip_ext();
extern void  gdi_layer_push_clip_ext();
#endif

void gdi_layer_pop_clip(void)
{
#ifndef GDI_SLIM_SUPPORT
    gdi_layer_pop_clip_ext(__FILE__, __LINE__);
#else
    gdi_layer_pop_clip_ext();
#endif
}

void gdi_layer_push_clip(void)
{
#ifndef GDI_SLIM_SUPPORT
    gdi_layer_push_clip_ext(__FILE__, __LINE__);
#else
    gdi_layer_push_clip_ext();
#endif
}
#endif //maomaolin add
S32 gdi_image_bmp_draw(S32       offset_x, S32 offset_y, U8 * BMP_src,  U32 size)
{
    return gdi_image_bmp_draw_handler(0, 0, offset_x, offset_y, 0, 0, BMP_src, size);
}

#endif
#endif/*__MCAREV31__*/
