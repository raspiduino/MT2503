#ifndef __GB_SMD_VIEW_LIST__
#define __GB_SMD_VIEW_LIST__

#include "MMI_features.h" 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_list_menu.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "GB_WG_DataTypeDef.h"

#ifdef __MMI_MAINLCD_320X480__  //HVGA
#define GB_WG_LIST_HEIGHT                 65
#define GB_WG_LIST_MARGIN                 8
#define GB_WG_LIST_MARGIN_ICONS           4
#define GB_WG_LIST_APPICON_SIZE           48
#define GB_WG_LIST_APP_NAME_HEIGHT        30
#define GB_WG_LIST_FLAG_NAME_HEIGHT       15 
#define GB_WG_LIST_APP_NAME_SIZE          20
#define GB_WG_LIST_APP_FLAG_NAME_SIZE  14

#define GB_WG_DETAIL_MARGIN               8
#define GB_WG_DETAIL_GAP                  10
#elif defined(__MMI_MAINLCD_480X800__)   //WVGA
#define GB_WG_LIST_HEIGHT                 109
#define GB_WG_LIST_MARGIN                 14
#define GB_WG_LIST_MARGIN_ICONS           8
#define GB_WG_LIST_APPICON_SIZE           72
#define GB_WG_LIST_APP_NAME_HEIGHT        45
#define GB_WG_LIST_FLAG_NAME_HEIGHT       45/2 
#define GB_WG_LIST_APP_NAME_SIZE          30
#define GB_WG_LIST_APP_FLAG_NAME_SIZE  21

#define GB_WG_DETAIL_MARGIN               14
#define GB_WG_DETAIL_GAP                  18
#elif defined(__MMI_MAINLCD_240X320__)   //QVGA
#define GB_WG_LIST_HEIGHT                 51
#define GB_WG_LIST_MARGIN                 5
#define GB_WG_LIST_MARGIN_ICONS           4
#define GB_WG_LIST_APPICON_SIZE           38
#define GB_WG_LIST_APP_NAME_HEIGHT        20
#define GB_WG_LIST_FLAG_NAME_HEIGHT       10 
#define GB_WG_LIST_APP_NAME_SIZE          16
#define GB_WG_LIST_APP_FLAG_NAME_SIZE  12

#define GB_WG_DETAIL_MARGIN               5
#define GB_WG_DETAIL_GAP                  6
#elif defined(__MMI_MAINLCD_240X400__)   //WQVGA
#define GB_WG_LIST_HEIGHT                 51
#define GB_WG_LIST_MARGIN                 5
#define GB_WG_LIST_MARGIN_ICONS           4
#define GB_WG_LIST_APPICON_SIZE           38 
#define GB_WG_LIST_APP_NAME_HEIGHT        20
#define GB_WG_LIST_FLAG_NAME_HEIGHT       10
#define GB_WG_LIST_APP_NAME_SIZE          16
#define GB_WG_LIST_APP_FLAG_NAME_SIZE  12

#define GB_WG_DETAIL_MARGIN               5
#define GB_WG_DETAIL_GAP                  6
#else //default
#define GB_WG_LIST_HEIGHT                 65
#define GB_WG_LIST_MARGIN                 8
#define GB_WG_LIST_MARGIN_ICONS           4
#define GB_WG_LIST_APPICON_SIZE           48 
#define GB_WG_LIST_APP_NAME_HEIGHT        30 
#define GB_WG_LIST_FLAG_NAME_HEIGHT       15
#define GB_WG_LIST_APP_NAME_SIZE          20
#define GB_WG_LIST_APP_FLAG_NAME_SIZE  14

#define GB_WG_DETAIL_MARGIN               8
#define GB_WG_DETAIL_GAP                  10
#endif

//color
#define GB_WG_BLUE   VRT_COLOR_MAKE(255, 30, 112, 193)
#define GB_WG_GREY   VRT_COLOR_MAKE(255, 128, 128, 128)


class WinguoSmartDialListContent : public VcpListMenuCellClientBaseFrame
{
public:
	WinguoSmartDialListContent(GB_UINT index);    
	virtual GB_VOID onCreateElements();
	virtual GB_VOID onCloseElements();
	virtual GB_VOID onLayoutElements();
	virtual GB_VOID onUpdateElements();
	GB_UINT m_index;
	VfxU8* m_icon;
private:
	VfxImageFrame* pContentIcon;
	VfxImageFrame *pContentIconFlag;
	VfxFrame* Frame;
	VfxTextFrame* m_pAppName1;
	VfxTextFrame* m_pAppName2;
	VfxTextFrame* m_pAppName3;
	VfxTextFrame* m_StringFlag1;
	VfxTextFrame* m_StringFlag2;
	VfxTextFrame* m_StringFlag3;
};


class WinguoSmartDialListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
	// Override
public:
	GB_INT    ListCount;
	GB_USHORT  *TextBuff;
	virtual VfxBool getItemText(
		GB_UINT index,                    
		VcpListMenuFieldEnum fieldType,  
		VfxWString &text,                
		VcpListMenuTextColorEnum &color  
		)
	{        
		return VFX_FALSE;
	}

	virtual VfxBool getItemImage(
		GB_UINT index,                    
		VcpListMenuFieldEnum fieldType,  
		VfxImageSrc &image              
		) 
	{
		return VFX_FALSE;
	}

	virtual GB_VOID closeItemImage(
		GB_UINT index,                    
		VcpListMenuFieldEnum fieldType, 
		VfxImageSrc Image               
		) {}

	virtual GB_UINT getCount() const
	{
		return ListCount;
	}

	virtual VcpListMenuItemStateEnum getItemState(
		GB_UINT index   
		) const { return VCP_LIST_MENU_ITEM_STATE_NONE;}


	virtual VfxBool swapItem(
		GB_UINT index1, 
		GB_UINT index2 
		) 
	{

		return VFX_TRUE;
	}

	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
		GB_UINT index,
		VfxFrame *parentFrame
		)
	{
		WinguoSmartDialListContent* pItem = NULL;

		VFX_OBJ_CREATE_EX(pItem, WinguoSmartDialListContent, parentFrame,(index));
		return (VcpListMenuCellClientBaseFrame *)pItem;
	}

	virtual GB_VOID closeItemCustomContentFrame(
		GB_UINT index,  
		VcpListMenuCellClientBaseFrame *cell 
		)
	{
		if (cell)
		{
			WinguoSmartDialListContent* pItem = (WinguoSmartDialListContent*)cell;
			VFX_OBJ_CLOSE(cell);
		}
	}

	// Get the empty text resource for the text when list menu is empty
	virtual VfxBool getMenuEmptyText(
		VfxWString &text,                // [OUT] the text resource
		VcpListMenuTextColorEnum &color  // [OUT] the text color
		);

};

#endif /*__GB_SMD_VIEW_LIST__*/