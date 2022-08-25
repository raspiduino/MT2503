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
#include "MCommonDef.h"
#if (MCR_MTK_VER >= MTK_VER_912)
#include "MMI_features.h"
#endif

#include "kal_non_specific_general_types.h"
#include "stack_config.h"
#include "Soc_api.h"
#include "Gui_Setting.h"

#if (MCR_MTK_VER <= MTK_VER_912)
#include "FileManagerGProt.h"
#endif

#include "ProtocolEvents.h"

#if (MCR_MTK_VER < MTK_VER_1112) //purple
#include "TouchScreenGprot.h"
#endif

#include "AudioInc.h"
#include "gpioInc.h"
#include "gdi_include.h"
#include "GlobalDefs.h"
#include "wgui_categories_inputs.h" // ShowCategory5Screen
#include "wap_ps_struct.h" 

#if (MCR_MTK_VER > MTK_VER_652)
#include "app_datetime.h"
#else
#include "DateTimeGprot.h"
#endif

#include "DateTimeType.h"
#include "TimerEvents.h"

#include "GlobalMenuItems.h"

#include "SSCResDef.h"
#if MCR_MTK_VER < MTK_VER_1032
#include "SATResDef.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "bootupsrvgprot.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1108
#include "GlobalResDef.h"
#endif
#include "mmi_frm_app_launcher_gprot.h"
#include "McfCommon.h"
#include "MAdpMenuDef.h"
#include "McfPlatform.h"
#include "McfIdle.h"
#include "McfTrace.h"
#include "McfMisc.h"
#include "McfSys.h"

typedef struct _SModeParam
{//internal usage only..
    MINT               mode;
    MWCHAR             name[MPHB_NAME_LENGTH+1];
    MCHAR              number[MPHB_NUMBER_LENGTH+1];
    MINT               qmsgon;
}SModeParam;


//if you want add an not existed wap  version app
//please contact PM first!!
//DO NOT ADD app id yourself!!!!!
// QQ牧场	10031001	wap版		http://fwd.z.qq.com:8080/forward.jsp?bid=227	moshenyang	2011-05-10	slomylan	2011-07-04	有效
// QQ农场	10031000	wap版		http://fwd.z.qq.com:8080/forward.jsp?bid=206	moshenyang	2011-05-10	slomylan	2011-07-04	有效
// QQ空间	10031002	wap版		http://fwd.z.qq.com:8080/forward.jsp?bid=186	nicolawu	2011-06-15	slomylan	2011-07-04	有效
// QQ家园	10250000	wap版		http://fwd.3g.qq.com:8080/forward.jsp?bid=512	sophyli	2011-05-03	slomylan	2011-07-05	有效
// QQ股票	10130000	wap版		http://fwd.3g.qq.com:8080/forward.jsp?bid=358	slomy
// QQ书城	10030000	wap版		http://fwd.3g.qq.com:8080/forward.jsp?bid=357	slomylan	2011-07-04	slomylan	2011-07-04	有效
// 腾讯微博	10031006	wap版		http://fwd.3g.qq.com:8080/forward.jsp?bid=356	nicolawu	2011-06-15	slomylan	2011-07-04	有效
// QQ邮箱	10031003	wap版		http://fwd.3g.qq.com:8080/forward.jsp?bid=187	nicolawu

/************************************************************************/
extern MVOID McfGoBackHistory(MVOID); //by purple
extern MINT __EntryScreen(U16 scrnId, pfnFunc exitFunc, pfnDelFunc deleteFunc, pfnFunc entryFunc, MVOID * flag); //by purple

extern MCHAR* MHelper_MakeQQBbuffer(MCHAR* purl,MINT linkTypeId,MINT* pbufferLength);
typedef void (*FuncPtr) (void);
void mcare_cnf_exit(void)
{
    MCR_ExitTencentMCare();
    McfGoBackHistory();  //by purple
}
int mcare_exit_confirm(FuncPtr callback)
{
    UNUSED_PARAM(callback);
    
#if (MCR_MEM_KERNRESER == MCR_MEMTYPE_MEDIA) ||(MCR_MEM_APPRESER == MCR_MEMTYPE_MEDIA)
    if(McfIsMcrRunning())
    {
        if(McfIdle_IsStatusIconShow(MIDLE_ICON_MCARE))
        {
		    DisplayConfirm(STR_GLOBAL_OK,0,STR_GLOBAL_ABORT,0,(UI_string_type)get_string(STR_MCARE_RUNNING), IMG_GLOBAL_INFO, SUCCESS_TONE);
        }
        else
        {
            DisplayConfirm(STR_GLOBAL_OK,0,STR_GLOBAL_ABORT,0,(UI_string_type)get_string(STR_MCARE_QQ_RUNNING), IMG_GLOBAL_INFO, SUCCESS_TONE);
        }
	 
        SetLeftSoftkeyFunction(mcare_cnf_exit, KEY_EVENT_UP);
        SetRightSoftkeyFunction(McfGoBackHistory, KEY_EVENT_UP); //by purple
        return 1;
    }
    return 0;
#else
    return 0;
#endif
}

#if (MCR_MTK_VER >=1112)
#if (MCR_MTK_VER>=MTK_VER_1210) && !defined (__MMI_FRM_HISTORY__)
void DeleteScreenIfPresent( U16 scrn_id)
{
    McfScrnCloseById(GRP_ID_MCARE_LIST, scrn_id);

}
#endif
void mcare_ncenter_exit(void)
{
    DeleteScreenIfPresent(MCARE_SCREEN_HOME);
    DeleteScreenIfPresent(MCARE_SCREEN_EDITOR);
	MCR_ExitTencentMCare();
}
#endif


static void __SetSelectFunc(FuncPtr func)
{
	SetLeftSoftkeyFunction(func, KEY_EVENT_UP);
	#if(MCR_MTK_VER >= MTK_VER_1032)
	SetCenterSoftkeyFunction(func,KEY_EVENT_UP); //purple
	SetKeyHandler(func, KEY_ENTER, KEY_EVENT_UP);	
	#endif
}
/*
*modify by charmenli 2012-2-20
*1112cosmos获取imsi号问题修改
*/
kal_int32 in_mcare=0;
kal_int32 mcf_from_menu = 0;
#ifdef __MMI_NCENTER_SUPPORT__
#include "vapp_ncenter_gprot.h"
#endif
static MMI_RET mcf_mcare_app_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_ASM_PREPARED:
		{
			if(!mcf_from_menu)
			{
				McfIdleRegistePressIconCb(); 
				McfStatusIcon_PressedTimerEventProc( );
			}
			else
			{
				MCR_EntryTencentMCare(MNULL, MNULL, MNULL, 0);
			}
            mcf_from_menu = 0;
			in_mcare = 1;
		}
		break;

		case EVT_ID_APP_POST_UNHIDE:
		case EVT_ID_APP_POST_ENTER:
		{
 			kal_uint32 mem_size = mmi_frm_app_get_base_mem_size(APP_TENCENT_MCARE) + mmi_frm_app_get_fg_mem_size(APP_TENCENT_MCARE);
			if(in_mcare == 0)
			{
				mmi_frm_asm_prepare(APP_TENCENT_MCARE, mem_size, mcf_mcare_app_proc, NULL, MMI_FRM_ASM_F_NONE);
			}
		}
		break;

		case EVT_ID_APP_NO_CHILD:
        {
            if(McfIsMcrRunning())
            {
			    mmi_frm_asm_base_shrink_size(APP_TENCENT_MCARE, 330*1024);
			}
			mmi_frm_app_set_hidden(APP_TENCENT_MCARE,MMI_TRUE,0);
			in_mcare = 0;
			return MMI_APP_NO_CHILD_HANDLED_BY_APP;
        }
        break;
		case EVT_ID_APP_CLOSE_REQ:
		{
            if(McfIsMcrRunning())
            {
			    mmi_frm_asm_base_shrink_size(APP_TENCENT_MCARE, 330*1024);
			}
			else
            {
			    mmi_frm_asm_base_shrink_size(APP_TENCENT_MCARE, 0);
			}
			mmi_frm_group_close(GRP_ID_MCARE_LIST);
			in_mcare = 0;
			return MMI_APP_CLOSE_ANSWER_HIDE;
		}
		break;
		case EVT_ID_APP_FORCE_CLOSE:
		{
			mcare_ncenter_exit();
			in_mcare = 0;
			mmi_frm_app_close(APP_TENCENT_MCARE);
		}
		break;
    #ifdef __MMI_NCENTER_SUPPORT__
		case EVT_ID_VAPP_NCENTER_DRAG:
		{
			if(mmi_frm_group_is_in_top_scope(APP_TENCENT_MCARE))
				return MMI_RET_ERR;
		}
		break;
    #endif
	}
	return MMI_RET_OK;
}


MVOID MCR_Entry(MVOID)
{
#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))
	McfMisc_GetImsiRequst();
#endif
#ifdef __MMI_NCENTER_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_VAPP_NCENTER_DRAG, mcf_mcare_app_proc, NULL);
#endif
    mcf_from_menu = 1;
	if(mmi_frm_app_is_hidden(APP_TENCENT_MCARE))
	{
		mmi_frm_app_set_hidden(APP_TENCENT_MCARE,MMI_FALSE,0);
	}
	else
	{
    	mmi_frm_app_launch(APP_TENCENT_MCARE, 0, 0, mcf_mcare_app_proc, NULL, 0);
	}
	//MCR_EntryTencentMCare(MNULL, MNULL, MNULL, 0);
}
/////////////////     end        ////////////////////

MVOID MCR_HiliteMenu(MVOID)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    __SetSelectFunc(MCR_Entry);
}


#ifdef __MCARE_QQBROWSER__
MVOID MCR_EntryQQBrowser(MVOID)
{	
	MCR_EntryTencentMCare(10020000, "mbr", NULL, 0);
}


MVOID MCR_HiliteQQBrowser(MVOID)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    __SetSelectFunc(MCR_EntryQQBrowser);
}

#endif


#ifdef __MCARE_QQFARM__

//other urls please see the header of this file
#define URL_QQ_FARM "http://fwd.z.qq.com:8080/forward.jsp?bid=206"
#define ID_QQ_FARM  (10031000)

MVOID MCR_EntryQQFarm(MVOID)
{
    MINT   nbufferSize = 0;
    MCHAR* pBuffer     = (MCHAR*)MHelper_MakeQQBbuffer(URL_QQ_FARM,ID_QQ_FARM,&nbufferSize);
    if (pBuffer)
    {
        MCR_EntryTencentMCareEx(ID_QQ_FARM,10020000, "mbr", (MVOID*)pBuffer, nbufferSize);
    }
}

MVOID MCR_HiliteQQFarm(MVOID)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    __SetSelectFunc(MCR_EntryQQFarm);
}

#endif        

#ifdef __MCARE_QQPASTURE__
//此buf由浏览器那边提供

//other urls please see the header of this file
#define URL_QQ_PASTURE "http://fwd.z.qq.com:8080/forward.jsp?bid=227"
#define ID_QQ_PASTURE  (10031001)
MVOID MCR_EntryQQPasture(MVOID)
{
    MINT   nbufferSize = 0;
    MCHAR* pBuffer     = (MCHAR*)MHelper_MakeQQBbuffer(URL_QQ_PASTURE,ID_QQ_PASTURE,&nbufferSize);
    if (pBuffer)
    {
        MCR_EntryTencentMCareEx(ID_QQ_PASTURE,10020000, "mbr", (MVOID*)pBuffer, nbufferSize);
    }
}


MVOID MCR_HiliteQQPasture(MVOID)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    __SetSelectFunc(MCR_EntryQQPasture);
}
#endif

#if MCR_MTK_VER >= MTK_VER_1032
void mmi_mcare_menu_init(void);
 mmi_ret mmi_mcare_ready_init(mmi_event_struct* evt)
 {
    mmi_mcare_menu_init();
 }
#endif

MVOID MCR_CloseScreen(MVOID)
{
    U16 actScrn;

    actScrn = GetActiveScreenId();
    if(actScrn == MCARE_SCREEN_HOME ||actScrn ==MCARE_SCREEN_EDITOR)
    {
#if MCR_MTK_VER >= MTK_VER_1132

#else
      ReplaceNewScreenHandler(actScrn,MNULL,MNULL);//make it not added into history
#endif
    
      //
    }
    else
    {
#if MCR_MTK_VER >= MTK_VER_1132
    McfScrnCloseById(GRP_ID_MCARE_LIST, MCARE_SCREEN_HOME);
    McfScrnCloseById(GRP_ID_MCARE_LIST, MCARE_SCREEN_EDITOR);
	mmi_frm_app_close(APP_TENCENT_MCARE);
#else
    DeleteScreenIfPresent(MCARE_SCREEN_HOME);
    DeleteScreenIfPresent(MCARE_SCREEN_EDITOR);
 #endif
    

    }
}
mmi_ret MCR_HandleCardPlugOut(mmi_event_struct *param)//charmenli modify2012-05-28
{   
    if (MFALSE == MCR_IsRunning())
    {
        return MMI_RET_OK;;
    }
    
    if (MFALSE == McfFile_IsStorageReady())
    {
	    U16 curScreenId = GetActiveScreenId();
		
    	MCFLOGIC_FLOW_PRINT(ALOG_INFO, MLOG_APPLICATION,__MCR_FUNCTION__":MCPlugIn");
    	MCR_ExitTencentMCare();	
    	MCR_CloseScreen();  //20111020 oyshengquan modify 
    	if (MCARE_SCREEN_HOME == curScreenId || MCARE_SCREEN_EDITOR == curScreenId)
    	{
    		McfGoBackHistory();
    	}
    }
    else
    {
        //使用的是手机磁盘，没关系滴
    }
	return MMI_RET_OK;
}


#if (MCR_MTK_VER >= MTK_VER_1112) && defined (__COSMOS_MMI_PACKAGE__)
mmi_ret MCR_HandleUsbPlugIn(mmi_event_struct *evt)
{ 
	MBOOL bInUsbMode = MFALSE;
    if( MTRUE == MCR_IsRunning())
    {
    
    	bInUsbMode = McfUsb_IsInMassStorageMode();
    	if (bInUsbMode)
    	{
    		MCFLOGIC_FLOW_PRINT(ALOG_INFO, MLOG_APPLICATION,__MCR_FUNCTION__":UsbPlugIn");
    		MCR_ExitTencentMCare();	
    	    MCR_CloseScreen();  //20111020 oyshengquan modify 
    	}
    }

    return MMI_RET_OK;

}

mmi_ret MCR_HandleUsbPlugOut(MVOID)
{
#ifdef __MMI_VUI_ENGINE__ //MTK.mtk01963
	vapp_mcare_close_warning();
#endif //MTK.mtk01963
    return MMI_RET_OK;
}
mmi_ret MCR_HandleUsbPlugOutExt(mmi_event_struct *evt)
{
#ifdef __MMI_VUI_ENGINE__ //MTK.mtk01963
	vapp_mcare_close_warning();
#endif // MTK.mtk01963
    return MMI_RET_OK;
}

extern mmi_ret MCR_HandleUsbPlugInExt(mmi_event_struct *evt)
{
    //MCR_HandleUsbPlugIn();
    //McfSetCurrExitFuncPtr(MNULL);
    //McfDisplayIdleScreenForce();
	MCR_HandleUsbPlugIn(evt);
	
    return MMI_RET_OK;
}

#else   //#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))
#if (MCR_MTK_VER>=MTK_VER_1210)
mmi_ret MCR_HandleUsbPlugIn(MVOID)
{
	MBOOL bInUsbMode = MFALSE;

    if (MFALSE == MCR_IsRunning())
    {
        return MMI_RET_OK;
    }
   
	bInUsbMode = McfUsb_IsInMassStorageMode();
	if (bInUsbMode)
	{
		MCFLOGIC_FLOW_PRINT(ALOG_INFO, MLOG_APPLICATION,__MCR_FUNCTION__":UsbPlugIn");
		MCR_ExitTencentMCare();	
	    MCR_CloseScreen();
	}
	    return MMI_RET_OK;

}

mmi_ret MCR_HandleUsbPlugOut(MVOID)
{
	//do nothing
	    return MMI_RET_OK;
}

#else
MVOID MCR_HandleUsbPlugIn(MVOID)
{
	MBOOL bInUsbMode = MFALSE;

    if (MFALSE == MCR_IsRunning())
    {
        return;
    }
   
	bInUsbMode = McfUsb_IsInMassStorageMode();
	if (bInUsbMode)
	{
		MCFLOGIC_FLOW_PRINT(ALOG_INFO, MLOG_APPLICATION,__MCR_FUNCTION__":UsbPlugIn");
		MCR_ExitTencentMCare();	
	    MCR_CloseScreen();
	}
}

MVOID MCR_HandleUsbPlugOut(MVOID)
{
    GoBackHistory();
	//do nothing
}
#endif
#endif //#if ((MCR_MTK_VER >=MTK_VER_1112) && (defined  (__COSMOS_MMI_PACKAGE__)))



void mmi_mcare_menu_init(void)
{
	McfMisc_GetImsiRequst();
#ifndef _MCR_MMI_RESOURCE_XML_GEN_
	SetHiliteHandler(MENU_ID_TENCENT_MCARE, MCR_HiliteMenu);

#ifdef __MCARE_QQBROWSER__
	SetHiliteHandler(MENU_ID_TENCENT_BROWSER, MCR_HiliteQQBrowser);
#endif

#ifdef __MCARE_QQFARM__
	SetHiliteHandler(MENU_ID_TENCENT_FARM, MCR_HiliteQQFarm);
#endif

#ifdef __MCARE_QQPASTURE__
	SetHiliteHandler(MENU_ID_TENCENT_PASTURE, MCR_HiliteQQPasture);
#endif
#endif
}

MVOID MCR_ShowFirmVersion(MVOID)
{
    U16 *pBuffer;

    __EntryScreen(SCR_ENTER_SSC, NULL, NULL, NULL,NULL);//by purple
    
    pBuffer = gui_malloc(256);
    if(pBuffer)
    {
        //fixme: change the dead codes
        extern MUINT   MHelper_GetPortingID(MVOID);
        kal_wsprintf(pBuffer, "Tencent Mcare V3.1 \n Porting ID:\n %d \n Firm Version:\n %s \n", MHelper_GetPortingID(), MCR_FIRMVERSION);
        ShowCategory7Screen(0,0,
            0,0,
            STR_GLOBAL_BACK,0,
            (U8*) pBuffer,
            NULL);
        gui_free(pBuffer);
    }
        
    SetRightSoftkeyFunction(McfGoBackHistory, KEY_EVENT_UP); //by purple
}
//maomaolin add for porting id check
extern MUINT   MHelper_GetPortingID(MVOID);
void MCareV30_StartWapBrowser(MCHAR *url);
MVOID MCR_PortingIdCheck( MVOID )
{
	MCHAR portingid_url[100];	
	MUINT portingid = MHelper_GetPortingID();
   
	McfStdC_sprintf(portingid_url,"http://fwd.3g.qq.com:8080/forward.jsp?bid=302&aid=mcp&type=3&pid=%d",portingid);
	MCareV30_StartWapBrowser(portingid_url);

}
void mcare_show_firm_version(void)
{
    MCR_ShowFirmVersion();
}
#ifdef __MCARE_SEPERATE_NET_TASK__

extern MBOOL McfSocket_TaskCreate(comptask_handler_struct **handle);
kal_bool mcare_net_task_create(comptask_handler_struct **handle)
{
	McfSocket_TaskCreate(handle);
	return KAL_TRUE;
}
#endif
MVOID MCR_HandleWebCamConn(MVOID)
{
    if (MFALSE == MCR_IsRunning())
    {
        return;
    }
    
    MCFLOGIC_FLOW_PRINT(ALOG_INFO, MLOG_APPLICATION , __MCR_FUNCTION__":WebCamConn");
	MCR_ExitTencentMCare();	
    MCR_CloseScreen();
}

/***********************************************
*MCR_HandleRotate, adapt to system rotate sense callback
*@nAngle --[in] screen rotate angle,refer to mmi_frm_screen_rotate_enum
*/
MVOID MCR_HandleRotate(MINT nAngle)
{
#if defined(__MMI_SCREEN_ROTATE__)  //by purple
    //MINT rotate =mmi_frm_get_screen_rotate();
	if(nAngle != mmi_frm_get_previous_screen_rotate())
	{
	    //MINT nAngle;
	    //mmi_frm_screen_rotate(nAngle);
	    if(nAngle ==MMI_FRM_SCREEN_ROTATE_90) nAngle =MSCREEN_ROTATE_90;
	    else if(nAngle ==MMI_FRM_SCREEN_ROTATE_180) nAngle =MSCREEN_ROTATE_180;
	    else if(nAngle ==MMI_FRM_SCREEN_ROTATE_270) nAngle =MSCREEN_ROTATE_270;
	    else nAngle = MSCREEN_ROTATE_0;
	    
		MCR_RotateTencentMCare(nAngle);
	}
#endif	
}

#if MCR_REGION_OVERSEA == __CFG_NO__
//===========================================================================
const U16 g_arTips[]=
{//MUST keep in order..
	/*ESTRID_NO_STORAGE*/STR_MCARE_STORAGE_ERROR_NOTE,
	/*ESTRID_NOT_ENOUPH_MEMORY*/STR_MCARE_NOT_ENOUGH_MEM,
	/*ESTRID_FILE_CORRUPT*/STR_MCARE_FILE_CORRUPT_ERR,
	/*ESTRID_EXEC_FAIL*/STR_MCARE_EXEC_FAIL,
	/*ESTRID_LOAD_FAIL*/STR_MCARE_LOAD_FAIL,
	/*ESTRID_NOT_ENOUPH_STORAGE*/STR_MCARE_STORAGE_NO_SPACE,
	/*ESTRID_FILE_CORRPUTED_RESTART*/STR_MCARE_FILE_CORRUPT_RESTART,
	/*ESTRID_SIM_ERROR*/STR_MCARE_SIM_ERROR,
	/*ESTRID_SIM_FLIGHTMODE*/STR_MCARE_IS_ON_FLY_MODE,
	/*ESTRID_INSERT_VALID_SIM_CARD*/STR_MCARE_INSERT_VALID_SIM,
	/*ESTRID_NET_NOT_READY*/STR_MCARE_NETWORK_NOT_READY,
	/*ESTRID_USB_ERROR*/STR_MCARE_USB_MODE,
	/*ESTRID_MAX*/STR_MCARE_LAST
};

const MWCHAR* McfRes_GetCustomWStr(MUINT nStrIdEnum)
{
	if ( STR_MCARE_USB_MODE == g_arTips[nStrIdEnum] )//add by charmenli 2012-5-29 fixed USB/MTP环境下，提示语与MTK一致
	{
		return (MWCHAR* )GetString(McfUsb_GetMassStorageModeWarningStrId());
	}
	return (MWCHAR* )GetString(g_arTips[nStrIdEnum]);
}

#endif

MINT MCR_DoSome1(MINT nType,MINT nParam)
{
    MINT nRet = 0;

    if(DOSO_SINGLE_INST == nType)
    {
        return 1;
    }

    return nRet;
}
MINT MCR_DoSome2(MINT nType,MINT nParam,MVOID *pParam)
{
    MINT nRet = 0;
    return nRet;
}

extern void MCR_StartWapBrowser(MCHAR *url); //by eason 
void MCareV30_StartWapBrowser(MCHAR *url)
{
	MCR_StartWapBrowser(url);
}

int MCR_EnterQMsgContact(unsigned     short *pName,char *pNumber)
{//lauch qmsg-contact from external
    SModeParam param = {0};
    
    if(pName)
    {
      mmi_wcsncpy((WCHAR*)param.name,(WCHAR*)pName,MPHB_NAME_LENGTH);
    }
    
    if(pNumber && *pNumber)
    {
      param.mode = 1;//start qmsg dialog
      strncpy(param.number,pNumber,MPHB_NUMBER_LENGTH);    
    }
    else
    {
      param.mode = 0;//start normal
    }
    
    MCR_EntryTencentMCareEx(0,12160000, MNULL, (MVOID*)&param, sizeof(SModeParam));
}
#else
#include "MMIDataType.h"
mmi_ret MCR_HandleUsbPlugIn(void)
{
    return MMI_RET_OK;
}

mmi_ret MCR_HandleUsbPlugOut(void)
{
    return MMI_RET_OK;
}

mmi_ret MCR_HandleCardPlugOut(void)//charmenli modify2012-05-28
{
    return MMI_RET_OK;
}    
#endif
