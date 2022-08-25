/*================================================================
*
* 文 件 名：GB_SMD_View_Screen.cpp
*
* 
* 文件描述：创建实现screen基类
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
* 作    者：Liyong [10/11/2012]
*
================================================================*/

#include "MMI_features.h"


#ifdef __MMI_GB_WINGUO_V2__

#include "inc\GB_SMD_View_Screen.h"

VFX_IMPLEMENT_CLASS("WinguoSMDBaseScreen", WinguoSMDBaseScreen, VfxMainScr);

void WinguoSMDBaseScreen::on1stReady()
{
	VfxMainScr::on1stReady();
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

	// create and display first page
	WinguoSMDBasePageClass *page;
	VFX_OBJ_CREATE(page, WinguoSMDBasePageClass, this);
	pushPage(0, page);
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/
