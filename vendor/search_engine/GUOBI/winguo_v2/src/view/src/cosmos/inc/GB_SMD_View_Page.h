#ifndef __GB_SMD_VIEW_PAGE_H__
#define __GB_SMD_VIEW_PAGE_H__

#include "GB_SMD_View_List.h"
#include "GB_SMD_View_Control.h"
#include "GB_WG_DataTypeDef.h"
#include "vapp_msg_gprot.h"
#include "UcmGProt.h"

class WinguoActionObj: public VfxObject
{
public:
	WinguoActionObj();

	static GB_VOID makeCall(kal_uint16 id, GB_USHORT *pusInputBuff, mmi_sim_enum sim);

	static GB_VOID makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);

};

class WinguoSMDBasePageClass : public VfxPage
{
	VFX_DECLARE_CLASS(WinguoSMDBasePageClass);
public:
	WinguoSMDBasePageClass();

public:
	virtual GB_VOID onInit();
	virtual GB_VOID onDeinit();
	GB_VOID GB_SMD_List_OnItemTaped(VcpListMenu *menu,GB_UINT index);// 处理点击列表事件响应
	GB_VOID onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos);
	GB_VOID onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos);
	virtual VfxBool onKeyInput(VfxKeyEvent &event);

	enum
	{
		GB_WG_SMD_DIAL,
		GB_WG_SMD_SMS,
		GB_WG_SMD_SAVE,
		GB_WG_SMD_SEARCH,
		GB_WG_SMD_CANCEL
	};

	enum
	{
		GB_WG_SELECT_SIM_CALL = 0x10,
		GB_WG_SELECT_SIM_MSG = 0x20
	};//  [8/21/2012 Liyong]

	enum
	{
		GB_WG_CONTACT_CALL1,
		GB_WG_CONTACT_CALL2,
		GB_WG_CONTACT_CALL3,
		GB_WG_CONTACT_CALL4,
		GB_WG_CONTACT_SEND_MSG1,
		GB_WG_CONTACT_SEND_MSG2,
		GB_WG_CONTACT_SEND_MSG3,
		GB_WG_CONTACT_SEND_MSG4,
		GB_WG_VIEW_CONTACT,
		GB_WG_CLOG_SAVE,
		GB_WG_CLOG_EDIT_BEFORE_CALL,
		GB_WG_CLOG_SEND_MSG
	};

private:
	VcpListMenu                          *m_listmenu;                    //list数据列表
	VcpToolBar                           *m_toolBar;				     //工具栏
	WinguoSMDBaseControlClass            *pControl;                      //控件类
	GB_USHORT						     *pusInputBuff;                  //输入框的内容
	VcpTextEditor                        *m_textEditor;
	VcpFunctionBar                       *m_funcBar;
	VcpTitleBar							 *title_bar;
	kal_uint16							 m_id;
	GB_U32                               store_indexid;
	WCHAR								 PhoneNum[200];
	WCHAR								 MorePhoneNum[200];
	WCHAR                                CalllogNum[200];//未知号码
	mmi_phb_optional_fields_struct* optional_fields_data;

	GB_VOID onSearchBntClicked(VfxObject *obj, VfxId id);
	GB_VOID onSearchListData(VcpTextEditor *editor);
	GB_VOID onToolBarClick(VfxObject* obj, VfxId id);

protected:
	VcpTitleBar *getTitleBar();
	GB_VOID setTitleBar(VfxObject *obj);
	VcpToolBar *getToolBar();
	GB_VOID setToolBar(VfxObject *obj);
	VcpListMenu *getListMenu();
	GB_VOID setListMenu(VfxObject *obj);
	VcpFunctionBar *getFunctionBar();
	GB_VOID setFunctionBar(VfxObject *obj);
	GB_VOID toolbarNewMsg(GB_USHORT *pusInputBuff);
	GB_VOID GB_WG_IdleDialPadSavePhoneBook(GB_USHORT *pusInputBuff);
	GB_VOID SelectCallSimId(VfxBool call, mmi_sim_enum sim);// 选择拨号卡SIM卡1或者2提示框
	GB_VOID SelectCallSimIdSmdList(VfxBool call, mmi_sim_enum sim);//电话本的拨号
	GB_VOID SelectMoreCallSimIdSmdList(VfxBool call, mmi_sim_enum sim);//独立一个号码的拨号
	GB_VOID SelectSim(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item);// 选择SIM号
	GB_VOID SelectSimSmdList(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item);//for PhoneBook
	GB_VOID SelectSimMoreSmdList(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item);//for SinglePhoneBook
	VfxImageSrc getCallIcon(mmi_sim_enum sim);
	VfxResId getCallIconId(mmi_sim_enum sim);
	GB_UINT getTotal(GB_VOID);
	GB_VOID onTap(VcpListMenu* pMenu, GB_UINT index);
	virtual GB_VOID onEnter(VfxBool isBackward);
	GB_VOID onCntxMenuClick(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);// 通话记录悬浮框点击
	GB_VOID onPopupButtonClicked(VfxObject* sender, VfxId btnID);
	static mmi_ret refleshCallBtn(mmi_event_struct* evt);
	
};

#endif /*__GB_SMD_VIEW_PAGE_H__*/