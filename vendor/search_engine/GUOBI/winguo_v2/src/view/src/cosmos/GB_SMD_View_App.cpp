/*================================================================
*
* 文 件 名：GB_SMD_SysBase_App.cpp
*
* 
* 文件描述：创建实现page基类
* 
*
* 
*
*       
*
* 
*
* 
*
* 作    者：[Liyong] [7/30/2012]
*
================================================================*/

#include "MMI_features.h"


#ifdef __MMI_GB_WINGUO_V2__

#include "inc\GB_SMD_View_App.h"

#if !defined (__NO_HANDWRITING__) 
GB_UINT _G_nPointCount = 0; 
GB_POINT *_G_tempArry = NULL;
#endif

extern "C"
{ 
#if !defined (__NO_HANDWRITING__) 
    extern	void GB_WG_show_handwriting_by_point_data(mmi_pen_point_struct* pPointData, U32 _G_nPointCount);
	extern MMI_BOOL mmi_imc_is_connected();
	void GB_WG_Do_protocol_handler();
	GB_VOID GB_WG_send_msg();
#endif
}

#if !defined (__NO_HANDWRITING__) 
void GB_WG_Do_protocol_handler()
{
	if (_G_tempArry)
	{

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
#ifdef __MMI_TOUCH_SCREEN__
		GB_WG_show_handwriting_by_point_data((mmi_pen_point_struct*)_G_tempArry, _G_nPointCount);
#endif
#endif

		VfxBase::freeSysMemory(_G_tempArry);
		_G_tempArry = NULL;
		_G_nPointCount = 0; 
	}
}
GB_VOID GB_WG_send_msg()
{
	ilm_struct *send_ilm;

	send_ilm = allocate_ilm(MOD_MMI);
	send_ilm->src_mod_id = MOD_MMI;
	send_ilm->dest_mod_id = MOD_MMI;
	send_ilm->local_para_ptr = NULL;
	send_ilm->peer_buff_ptr = NULL;
	send_ilm->msg_id = MSG_ID_GB_WG2_MSG;
	send_ilm->sap_id = MMI_MMI_SAP;
	msg_send_ext_queue(send_ilm);
}
#endif

extern "C" void GB_WG_SMD_Search_Screen_Launch(void* args, U32 argSize)
{  
#if !defined (__NO_HANDWRITING__) 
	GB_POINT* pPointData = (GB_POINT*)args;
	_G_nPointCount = (GB_UINT)argSize;

	if (pPointData && _G_nPointCount)
	{
		if (_G_tempArry)
		{
			VfxBase::freeSysMemory(_G_tempArry);
		}
		_G_tempArry = (GB_POINT*)VfxBase::allocSysMemory(_G_nPointCount * sizeof(*pPointData));
		if (_G_tempArry)
		{
			memcpy(_G_tempArry, pPointData, _G_nPointCount * sizeof(*pPointData));
		}
	}
#endif
	VfxAppLauncher::launch( 
		APP_GB_WINGUO,
		VFX_OBJ_CLASS_INFO(WinguoSMDBaseApp),
		GRP_ID_ROOT,
		args, argSize);
#if !defined (__NO_HANDWRITING__) 
     if(!mmi_imc_is_connected())
	{
	      SetProtocolEventHandler(GB_WG_Do_protocol_handler, MSG_ID_GB_WG2_MSG);	
          GB_WG_send_msg();
	}
	else
	{
	   GB_WG_Do_protocol_handler();
	}
#endif
}

VFX_IMPLEMENT_CLASS("WinguoSMDBaseApp", WinguoSMDBaseApp, VfxApp);
void WinguoSMDBaseApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	// create and display main screen
	WinguoSMDBaseScreen *scr;
	VFX_OBJ_CREATE(scr, WinguoSMDBaseScreen, this);
	scr->show();
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/