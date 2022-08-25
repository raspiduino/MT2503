/*================================================================
*
* 文 件 名：GB_SMD_View_Page.cpp
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
* 作    者：Liyong [10/11/2012]
*
================================================================*/

#include "MMI_features.h"


#ifdef __MMI_GB_WINGUO_V2__

//模块外调用的头文件
#include "vapp_phb_launch.h"
#include "mmi_rp_app_gb_winguo_def.h"
#include "Vapp_sim_setting_gprot.h"
#ifdef __MMI_SMS_COMPOSER__
    #include "vcui_sms_composer_gprot.h"
#endif

//模块内调用到的头文件
#include "inc\GB_SMD_View_Page.h"

extern "C"
{
#include "GB_SMD_Element.h"
#include "GB_SMD_ElementCallLog.h"
#include "GB_SMD_ElementPhoneNum.h"
#include "GB_SMD_ElementApp.h"
//#include "GB_WG_SMD_List.h"
#include "vcui_dialer_gprot.h"//for telephone call
#include "vfx_adp_device.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "PhbSrv.h"//  [10/22/2012 Liyong]用于获取所有电话号码
extern GB_VOID mmi_gb_winguo_app_free(GB_VOID);
extern GB_VOID mmi_gb_winguo_app_memory(GB_VOID);
extern GB_INT GB_WG_SeachString(WCH16 *pString);
extern GB_BOOL GB_WG_IsCallNum(GB_U16* callString);
extern GB_U16 GB_WG_SMD_List_Get_InputStr_Data(GB_U16 *pusInputStr);

};

VFX_IMPLEMENT_CLASS("WinguoSMDBasePageClass", WinguoSMDBasePageClass, VfxPage);
WinguoSMDBasePageClass::WinguoSMDBasePageClass():
m_listmenu(NULL),
m_toolBar(NULL),
pControl(NULL),
pusInputBuff(NULL),
m_textEditor(NULL),
m_funcBar(NULL),
store_indexid(0),
m_id(0),
title_bar(NULL)
{

};

VcpTitleBar *WinguoSMDBasePageClass::getTitleBar()
{
	if (title_bar)
	{
		return title_bar;
	}
	return NULL;
}

GB_VOID WinguoSMDBasePageClass::setTitleBar(VfxObject *obj)
{
	if (title_bar == NULL)
	{
		VFX_OBJ_CREATE(title_bar, VcpTitleBar, obj);
	}
}

VcpToolBar *WinguoSMDBasePageClass::getToolBar()
{
	if (m_toolBar)
	{
		return m_toolBar;
	}
	return NULL;
}

GB_VOID WinguoSMDBasePageClass::setToolBar(VfxObject *obj)
{
	if (m_toolBar == NULL)
	{
		VFX_OBJ_CREATE(m_toolBar, VcpToolBar, obj);
	}
}

VcpListMenu *WinguoSMDBasePageClass::getListMenu()
{
	if (m_listmenu)
	{
		return m_listmenu;
	}
	return NULL;
}

GB_VOID WinguoSMDBasePageClass::setListMenu(VfxObject *obj)
{
	if (m_listmenu == NULL)
	{
		VFX_OBJ_CREATE(m_listmenu, VcpListMenu, obj);
	}
}

VcpFunctionBar *WinguoSMDBasePageClass::getFunctionBar()
{
	if (m_funcBar)
	{
		return m_funcBar;
	}
	return NULL;
}

GB_VOID WinguoSMDBasePageClass::setFunctionBar(VfxObject *obj)
{
	if (m_funcBar == NULL)
	{
		VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, obj);
	}
}

GB_VOID WinguoSMDBasePageClass::onInit()
{
	VfxPage::onInit();

 	mmi_gb_winguo_app_memory();//申请winguo APP内存(初始化smd引擎需要用到)
 	GB_SMD_Init();//初始化smd引擎

	setStatusBar(GB_TRUE);
	VfxFrame *m_mainFrame;
	VFX_OBJ_CREATE(m_mainFrame, VfxFrame, this);
	m_mainFrame->setPos(0, 0);
	m_mainFrame->setBounds(0, 0, getSize().width, getSize().height); 

	VfxFrame *searchFrame;
	VFX_OBJ_CREATE(searchFrame, VfxFrame, m_mainFrame);
	searchFrame->setPos(0, 0);
	searchFrame->setBounds(0, 0, getSize().width, GB_WG_LIST_HEIGHT);

	VFX_OBJ_CREATE(pControl, WinguoSMDBaseControlClass, this);

	//创建输入框和图片按钮
	VcpButton *m_imageButton;
	if (pControl)
	{
		pControl->setTextEditor(searchFrame);
		if (pControl->getTextEditor())
		{
			m_textEditor = pControl->getTextEditor();
			m_textEditor->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(pControl->TEXT_ZISE)));
			m_textEditor->setPos((getSize().width - getSize().width*4/5 - getSize().height/12)/3, getSize().height/50);
			m_textEditor->setBounds(VfxRect(0, 0, getSize().width*4/5, getSize().height/12));
			m_textEditor->setMaxLength(GB_WG_SEARCH_WEB_MAX_INPUT_LEN - 2);// 设置输入长度
			m_textEditor->m_signalTextChanged.connect(this,&WinguoSMDBasePageClass::onSearchListData);
			m_textEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
			m_textEditor->activate();
		}

		pControl->setImageButton(searchFrame);
		if (pControl->getImageButton())
		{
			m_imageButton = pControl->getImageButton();
			m_imageButton->setPos(VfxPoint((getSize().width - getSize().width*4/5 - getSize().height/12)*2/3 + getSize().width*4/5, 
				getSize().height/50));
			m_imageButton->setBounds(VfxRect(0, 0, getSize().height/12, getSize().height/12));
			m_imageButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
			m_imageButton->setImage(VcpStateImage(IMG_GB_WINGUO_SKINWHITE_SEARCH_G));
			m_imageButton->m_signalClicked.connect(this, &WinguoSMDBasePageClass::onSearchBntClicked);
		}
	}

	setListMenu(this);
	if(m_listmenu)
	{
		//开始创建列表显示数据
		m_listmenu->setPos(0,getSize().height/50 + getSize().height/12);//列表起点坐标
		m_listmenu->setBounds(VfxRect(0, 0, getSize().width,  
			getSize().height - (getSize().height/50 + getSize().height/12)));//列表长度、宽度、高度设置
		m_listmenu->setAlignParent(
			VFX_FRAME_ALIGNER_MODE_SIDE,
			VFX_FRAME_ALIGNER_MODE_SIDE,
			VFX_FRAME_ALIGNER_MODE_SIDE,
			VFX_FRAME_ALIGNER_MODE_SIDE);//  设置调整信息

		m_listmenu->setHidden(GB_FALSE);
		m_listmenu->setItemHeight(GB_WG_LIST_HEIGHT);		
		m_listmenu->m_signalItemTapped.connect(this, &WinguoSMDBasePageClass::GB_SMD_List_OnItemTaped);

	}

	setTitleBar(this);
 	if (title_bar)
 	{
		setTopBar(title_bar);
		title_bar->setTitle(VFX_WSTR_RES(STR_GB_WINGUO_SMARTSEARCH));
 	}

	//设置创建底部工具栏
	setToolBar(this);
	if (m_toolBar)
	{
		m_toolBar->addItem(GB_WG_SMD_DIAL, VFX_WSTR_RES(STR_GB_WINGUO_CALL), IMG_WG_SMD_DIALPAD);
		m_toolBar->addItem(GB_WG_SMD_SMS, VFX_WSTR_RES(STR_GB_WINGUO_MESSAGE), IMG_WG_SMD_MSG);
		m_toolBar->addItem(GB_WG_SMD_SAVE, VFX_WSTR_RES(STR_GB_WINGUO_SAVE_ITEM), IMG_WG_SMD_SAVE);
		m_toolBar->addItem(GB_WG_SMD_CANCEL, VFX_WSTR_RES(STR_GB_WINGUO_EXIT), IMG_WG_SMD_CANCEL);
		m_toolBar->m_signalButtonTap.connect(this, &WinguoSMDBasePageClass::onToolBarClick);
		m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_TRUE);//  [8/9/2012 Liyong]初始状态设为灰暗
		setBottomBar(m_toolBar);
	}
	
	//创建在虚拟键盘上可以搜索数据
	setFunctionBar(this);
	m_funcBar->addItem(GB_WG_SMD_SEARCH, VFX_WSTR_RES(STR_GB_WINGUO_SEARCH));
	m_funcBar->setItemSpecial(GB_WG_SMD_SEARCH);
	m_funcBar->m_signalButtonTap.connect(this,&WinguoSMDBasePageClass::onSearchBntClicked);
	m_textEditor->setFunctionBar(m_funcBar);  

	//给输入的字符内容分配内存
	VFX_ALLOC_MEM(pusInputBuff,GB_WG_SEARCH_WEB_MAX_INPUT_LEN*2,this);
	memset(pusInputBuff,0,GB_WG_SEARCH_WEB_MAX_INPUT_LEN*2);

	mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, WinguoSMDBasePageClass::refleshCallBtn, this); //huyuan
}

mmi_ret WinguoSMDBasePageClass::refleshCallBtn(mmi_event_struct* evt)
{
    WinguoSMDBasePageClass *obj = (WinguoSMDBasePageClass *)evt->user_data;
	
    GB_INT inputstrLen = 0;

    inputstrLen = gb_wg_wcslen(obj->m_textEditor->getText());
	
    if(srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
    	 obj->m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_TRUE);
    }
    else if(inputstrLen > 0 && GB_WG_IsCallNum(obj->pusInputBuff) == GB_TRUE && srv_sim_ctrl_get_num_of_inserted() != 0)
    {
    	 obj->m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_FALSE);
    }
    

    return MMI_RET_OK;
}

VfxBool WinguoSMDBasePageClass::onKeyInput(VfxKeyEvent &event)
{
	if (event.keyCode == VFX_KEY_CODE_SEND &&
		event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        SelectCallSimId(GB_TRUE, MMI_SIM_NONE);
        return VFX_TRUE;
    }
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        back();
        return VFX_TRUE;
    }
    
    return VfxControl::onKeyInput(event);
}

GB_VOID WinguoSMDBasePageClass::onDeinit()
{

	if (pusInputBuff)
	{
		VFX_FREE_MEM(pusInputBuff);
		pusInputBuff = NULL;
	}

	if (pControl)
	{
		pControl->onDeinit();

		VFX_OBJ_CLOSE(pControl);
		pControl = NULL;
	}

	if (m_toolBar)
	{
		VFX_OBJ_CLOSE(m_toolBar);
		m_toolBar = NULL;
	}

	if (m_listmenu)
	{
		VFX_OBJ_CLOSE(m_listmenu);
		m_listmenu = NULL;
	}

	if (title_bar)
	{
		VFX_OBJ_CLOSE(title_bar);
		title_bar = NULL;
	}

    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, WinguoSMDBasePageClass::refleshCallBtn, this);

	GB_SMD_Release();// 释放smartdial数据及引擎
	mmi_gb_winguo_app_free();//释放APP内存
	VfxPage::onDeinit();
}

GB_VOID WinguoSMDBasePageClass::onSearchBntClicked(VfxObject *obj, VfxId id)
{
	m_textEditor->deactivate();
	GB_WG_SeachString(pusInputBuff);
}

void GB_StrRTrim(GB_WCHAR  *pStr)  
{  
    GB_WCHAR *pTmp = pStr + gb_wg_wcslen(pStr)-1;  
    if(pTmp != pStr)
	{
		while (*pTmp == ' ')   
		{  
			*pTmp = '\0';  
			pTmp--;  
		}
	}  
}

GB_VOID WinguoSMDBasePageClass::onSearchListData(VcpTextEditor *editor)
{
	GB_INT inputstrLen = 0;
	inputstrLen = gb_wg_wcslen(m_textEditor->getText());
	memset(pusInputBuff, 0, GB_WG_SEARCH_WEB_MAX_INPUT_LEN * 2);//每次输入内容都要清空，重新拷贝内容。否则容易导致死机问题
	mmi_wcscpy(pusInputBuff,  m_textEditor->getText());
	GB_StrRTrim(pusInputBuff);

	WinguoSmartDialListMenuContentProvider *pProvider = NULL;
	VFX_OBJ_CREATE(pProvider,WinguoSmartDialListMenuContentProvider,this);
	pProvider->ListCount = GB_WG_SMD_List_Get_InputStr_Data(pusInputBuff);//获取列表单元个数
	pProvider->TextBuff = pusInputBuff;	
	m_listmenu->setContentProvider(pProvider);//设置列表内容
	m_listmenu->resetAllItems(GB_TRUE);//重新设置列表

	if(inputstrLen > 0 
	   && GB_WG_IsCallNum(pusInputBuff) == GB_TRUE 
	   && srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_ALL_OFF)//& storage))//srv_sim_ctrl_is_available(storage))
	{
		m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_FALSE);//  [8/9/2012 Liyong]判断有SIM卡并且输入框全是数字的时候 按钮状态(可按)
	}
	else
	{
		m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_TRUE);//  [8/9/2012 Liyong]状态
	}

	if (srv_sim_ctrl_get_num_of_inserted() == 0 || srv_mode_switch_is_network_service_available() == MMI_FALSE)
	{
		m_toolBar->setDisableItem(GB_WG_SMD_DIAL, GB_TRUE);//  [8/9/2012 Liyong]状态
	}

	if (0 == inputstrLen || GB_WG_IsCallNum(pusInputBuff) == GB_TRUE)
	{
		m_toolBar->setDisableItem(GB_WG_SMD_SAVE, GB_FALSE);
	}
	else
	{
		m_toolBar->setDisableItem(GB_WG_SMD_SAVE, GB_TRUE);
	}

}

GB_VOID WinguoSMDBasePageClass::onToolBarClick(VfxObject* obj, VfxId id)
{
	switch (id)
	{
		case WinguoSMDBasePageClass::GB_WG_SMD_DIAL:
			{
				SelectCallSimId(GB_TRUE, MMI_SIM_NONE);
				break;
			}
			
		case WinguoSMDBasePageClass::GB_WG_SMD_SMS:
			{
				toolbarNewMsg(pusInputBuff);
				break;
			}
			
		case WinguoSMDBasePageClass::GB_WG_SMD_SAVE:
			{
				GB_WG_IdleDialPadSavePhoneBook(pusInputBuff);
				break;
			}
			
		case WinguoSMDBasePageClass::GB_WG_SMD_SEARCH:
			onSearchBntClicked(this,0);
			break;
		case WinguoSMDBasePageClass::GB_WG_SMD_CANCEL:
			m_textEditor->deactivate();
			getApp()->exit();
			break;
		default:break;
	}
}

#ifdef __MMI_SMS_COMPOSER__
mmi_ret GB_WG_NewMsg_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {    

        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct*)evt;
            vcui_sms_composer_close(ucEvt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;

}
#endif

GB_VOID WinguoSMDBasePageClass::toolbarNewMsg(GB_USHORT *pusInputBuff)
{
	GB_USHORT number[40+1];

#ifdef __MMI_UNIFIED_COMPOSER__
	VappUcEntryStruct ucEntry;

	srv_uc_addr_struct addr;
	if (!pusInputBuff)
	{
		return;
	}

	memset(&ucEntry, 0, sizeof(VappUcEntryStruct));
	ucEntry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
	ucEntry.type = SRV_UC_STATE_WRITE_NEW_MSG;

	memset(number, 0, sizeof(number));
	mmi_wcsncpy(number, pusInputBuff, sizeof(number)/sizeof(number[0])-1);
	// set address
	if (0 != mmi_wcslen(number) && GB_WG_IsCallNum(number))
	{		
		addr.next = NULL;
		addr.previous = NULL;
		addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
		addr.addr = (kal_uint8*)number;
		addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
		ucEntry.addr_num = 1;
		ucEntry.addr = &addr;

	}
	else
	{
		ucEntry.text_buffer = (U8*)number;
		ucEntry.text_num = mmi_ucs2strlen((S8*)number);
	}

	vappUcAppLauncher(&ucEntry);
#else
#ifdef __MMI_SMS_COMPOSER__

	if (!pusInputBuff)
	{
		return;
	}
    memset(number, 0, sizeof(number));
	mmi_wcsncpy(number, pusInputBuff, sizeof(number)/sizeof(number[0])-1);
    
    mmi_id smsComposerCui = 0;
    VcuiSmsComposerEntryStruct *entryData;
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

    if (0 != mmi_wcslen(number) && GB_WG_IsCallNum(number))
	{		
		VcuiSmsComposerAddrStruct address;
        address.next = NULL;
        address.previous = NULL;
        address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
        address.addr = (VfxWChar*)number;  
        entryData->addr_num = 1;
        entryData->addr = &address;

	}
	else
	{
		entryData->text_buffer = (VfxWChar *)number;
        entryData->text_num = mmi_ucs2strlen((CHAR*)number);
	}

    smsComposerCui = vcui_sms_composer_create(getApp()->getGroupId());
    if(smsComposerCui !=  GRP_ID_INVALID)
    {
        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
        mmi_frm_group_set_caller_proc(smsComposerCui, GB_WG_NewMsg_proc, NULL);
        vcui_sms_composer_run(smsComposerCui);
    }
    VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */    
#endif
}

mmi_ret GB_WG_SavePhoneBook_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	case EVT_ID_CUI_PHB_SAVE_RESULT:
		{
			vcui_phb_contact_saver_close(((vcui_phb_contact_save_result_event_struct*) evt)->sender_id);
			return MMI_RET_OK;
		}
	default:
		break;
	}

	return MMI_RET_DONT_CARE;
}

GB_VOID WinguoSMDBasePageClass::GB_WG_IdleDialPadSavePhoneBook(GB_USHORT *pusInputBuff)
{
	if (pusInputBuff == NULL)
	{
		return;
	}
	else
	{
		
		mmi_id cui_id = vcui_phb_contact_saver_create(mmi_frm_group_get_active_id());
		if (cui_id == GRP_ID_INVALID)
		{
			return;
		}
		mmi_frm_group_set_caller_proc(cui_id, GB_WG_SavePhoneBook_proc, NULL);
		vcui_phb_contact_saver_set_number(cui_id, pusInputBuff, mmi_wcslen(pusInputBuff));
		vcui_phb_contact_saver_run(cui_id);
	}
}


GB_VOID WinguoSMDBasePageClass::GB_SMD_List_OnItemTaped(VcpListMenu *menu,GB_UINT index)
{

	GB_U16               Cach_Type = 0;
	//GB_U32               store_indexid = 0;
	GB_SMD_ElementShowInfoStr    ShowInfo={0};
	GB_INT				 NumCout = 0;
	GB_U32				 nId = 0;

	GB_SMD_GetCachDataByIndex(index, &Cach_Type, &nId);//获取nId
	GB_SMD_GetCachDataByIndex(index, &Cach_Type, &store_indexid);
	GB_SMD_GetCachShowDataByIndex(index, &ShowInfo);

	switch (Cach_Type)
	{
	case GBMD_CachType_App:
		GB_SMD_RunApp(store_indexid);
		break;
	case GBMD_CachType_PhoneBook:
		{
			VcpMenuPopup *cntxMenu1;
			VFX_OBJ_CREATE(cntxMenu1, VcpMenuPopup, this);

			mmi_ucs2cpy((CHAR*)PhoneNum, (CHAR*)ShowInfo.explain.InfoString);
			cntxMenu1->setTitle(VFX_WSTR_MEM(ShowInfo.subject.InfoString));

			if (GB_WG_IsCallNum(PhoneNum) == GB_TRUE)
			{
				if (GB_SMD_PhoneNumGetCountById(nId) > 1)
				{
					store_indexid = GB_SMD_PhoneNumGetRealId(store_indexid);//需要转换store_index值才获取到正确的电话簿store_index值
					optional_fields_data = (mmi_phb_optional_fields_struct*)srv_phb_get_phone_optional_field(store_indexid);

					for (GB_INT i = 0; i < GB_SMD_PhoneNumGetCountById(nId); i++)
					{
						VfxWString text1 = VFX_WSTR_RES(STR_GB_WINGUO_CALL_TO);
						GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[i].number;
						if (telNum[0])
						{
							mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
							MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
						}
						text1 += MorePhoneNum;
						cntxMenu1->addItem(GB_WG_CONTACT_CALL1 + i, text1, VfxImageSrc(IMG_WG_SMARTDAIL_CALL), VCP_MENU_POPUP_ITEM_TYPE_2);
					}

					for (GB_INT i = 0; i < GB_SMD_PhoneNumGetCountById(nId); i++)
					{
						VfxWString text2 = VFX_WSTR_RES(STR_GB_WINGUO_MASSEGE_TO);
						GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[i].number;
						if (telNum[0])
						{
							mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
							MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
						}
		
						text2 += MorePhoneNum;
						cntxMenu1->addItem(GB_WG_CONTACT_SEND_MSG1 + i, text2, VfxImageSrc(IMG_WG_SMARTDAIL_SMS), VCP_MENU_POPUP_ITEM_TYPE_2); 
					}
					cntxMenu1->addItem(GB_WG_VIEW_CONTACT, VFX_WSTR_RES(STR_GB_WINGUO_VIEWCONTACT), VfxImageSrc(IMG_WG_SMD_SEARCH2), VCP_MENU_POPUP_ITEM_TYPE_2);
				}
				else
				{
					VfxWString text3 = VFX_WSTR_RES(STR_GB_WINGUO_CALL_TO);
					VfxWString text4 = VFX_WSTR_RES(STR_GB_WINGUO_MASSEGE_TO);
					text3 += PhoneNum;
					text4 += PhoneNum;
					cntxMenu1->addItem(GB_WG_CONTACT_CALL1, text3, VfxImageSrc(IMG_WG_SMARTDAIL_CALL), VCP_MENU_POPUP_ITEM_TYPE_2);
					cntxMenu1->addItem(GB_WG_CONTACT_SEND_MSG1, text4, VfxImageSrc(IMG_WG_SMARTDAIL_SMS), VCP_MENU_POPUP_ITEM_TYPE_2); 
					cntxMenu1->addItem(GB_WG_VIEW_CONTACT, VFX_WSTR_RES(STR_GB_WINGUO_VIEWCONTACT), VfxImageSrc(IMG_WG_SMD_SEARCH2), VCP_MENU_POPUP_ITEM_TYPE_2);
				}

			}

			else
			{
				cntxMenu1->addItem(GB_WG_VIEW_CONTACT, VFX_WSTR_RES(STR_GB_WINGUO_VIEWCONTACT), VfxImageSrc(IMG_WG_SMD_SEARCH2), VCP_MENU_POPUP_ITEM_TYPE_2);
			}

			vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
			cntxMenu1->m_signalMenuCallback.connect(this, &WinguoSMDBasePageClass::onCntxMenuClick);
			cntxMenu1->show(GB_TRUE);

			break;
		}
	case GBMD_CachType_Recalled:
		{
			VcpMenuPopup *cntxMenu2;
			VFX_OBJ_CREATE(cntxMenu2, VcpMenuPopup, this);

			mmi_ucs2cpy((CHAR*)CalllogNum, (CHAR*)ShowInfo.subject.InfoString);
			cntxMenu2->setTitle(VFX_WSTR_MEM(CalllogNum));
			cntxMenu2->addItem(GB_WG_CLOG_EDIT_BEFORE_CALL, VFX_WSTR_RES(STR_GB_WINGUO_CALL), VfxImageSrc(IMG_WG_SMARTDAIL_CALL), VCP_MENU_POPUP_ITEM_TYPE_2); // enter edit before call  STR_GLOBAL_DIAL
			cntxMenu2->addItem(GB_WG_CLOG_SEND_MSG, VFX_WSTR_RES(STR_GB_WINGUO_MESSAGE), VfxImageSrc(IMG_WG_SMARTDAIL_SMS), VCP_MENU_POPUP_ITEM_TYPE_2);
			cntxMenu2->addItem(GB_WG_CLOG_SAVE, VFX_WSTR_RES(STR_GB_WINGUO_SAVE_ITEM), VfxImageSrc(IMG_WG_SMARTDAIL_SAVE), VCP_MENU_POPUP_ITEM_TYPE_2);
			vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
			cntxMenu2->m_signalMenuCallback.connect(this, &WinguoSMDBasePageClass::onCntxMenuClick);
			cntxMenu2->show(GB_TRUE);
			break;
		}
	default:
		break;
	}

}

GB_VOID WinguoSMDBasePageClass::onCntxMenuClick(
								   VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		WinguoSMDBasePageClass::onPopupButtonClicked((VfxObject *)menu, item->getId());
	}
}

U32 getCurrentOnlySim()
{
    U32 i;
    S32 count;
    mmi_sim_enum sim;
	
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_available(sim))
        {
            return i;
        }
    }
}

GB_VOID WinguoSMDBasePageClass::onPopupButtonClicked(VfxObject* sender, VfxId btnID)
{
	VFX_UNUSED(sender);
	if (btnID<=GB_WG_CONTACT_CALL4 && srv_sim_ctrl_get_num_of_inserted() <= 1){
		switch (btnID)
		{
		case GB_WG_CONTACT_CALL1:
		case GB_WG_CONTACT_CALL2:
		case GB_WG_CONTACT_CALL3:
		case GB_WG_CONTACT_CALL4:
			{
				U32 currentSim = getCurrentOnlySim();
				WinguoActionObj::makeCall(m_id, PhoneNum, mmi_frm_index_to_sim(currentSim));
			}
			break;		
		}
		return;
	}
	
	switch (btnID)
	{
	case GB_WG_CONTACT_CALL1:
		{		
			//GB_UINT a =  WinguoSMDBasePageClass::getTotal();
	     
			SelectCallSimIdSmdList(GB_TRUE, MMI_SIM_NONE);	
			
			break;
		}

	case GB_WG_CONTACT_CALL2:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[1].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			SelectMoreCallSimIdSmdList(GB_TRUE, MMI_SIM_NONE);
			break;
		}

	case GB_WG_CONTACT_CALL3:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[2].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			SelectMoreCallSimIdSmdList(GB_TRUE, MMI_SIM_NONE);
			break;
		}

	case GB_WG_CONTACT_CALL4:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[3].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			SelectMoreCallSimIdSmdList(GB_TRUE, MMI_SIM_NONE);
			break;
		}

	case GB_WG_CONTACT_SEND_MSG1:
		{
			toolbarNewMsg((GB_USHORT *)PhoneNum);
			break;
		}

	case GB_WG_CONTACT_SEND_MSG2:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[1].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			toolbarNewMsg((GB_USHORT *)MorePhoneNum);
			break;
		}

	case GB_WG_CONTACT_SEND_MSG3:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[2].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			toolbarNewMsg((GB_USHORT *)MorePhoneNum);
			break;
		}

	case GB_WG_CONTACT_SEND_MSG4:
		{
			GB_CHAR* telNum = (GB_CHAR *)optional_fields_data->num[3].number;
			if (telNum[0])
			{
				mmi_asc_n_to_wcs(MorePhoneNum, (GB_CHAR*)telNum, sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1);
				MorePhoneNum[sizeof(MorePhoneNum)/sizeof(MorePhoneNum[0])-1] = 0;
			}
			toolbarNewMsg((GB_USHORT *)MorePhoneNum);
			break;
		}

	case GB_WG_VIEW_CONTACT:
		{
 			mmi_phb_contact_id id;
 			SRV_PHB_ID ph_id;
 			store_indexid = GB_SMD_PhoneNumGetRealId(store_indexid);//需要转换store_index值才获取到正确的电话簿store_index值
 			ph_id = srv_phb_create_number_id(PHB_PHONEBOOK, store_indexid, SRV_PHB_ENTRY_FIELD_NAME);
 			mmi_id cui_id = vcui_phb_contact_viewer_create(getApp()->getGroupId());
 
 			id = srv_phb_get_store_index_by_number_id(ph_id);
 			vcui_phb_contact_viewer_set_contact_id(cui_id, id);
 			vcui_phb_contact_viewer_run(cui_id);
 			vfxSetCuiCallerScr(cui_id, getMainScr());
			break;
		}

	case GB_WG_CLOG_SAVE:
		GB_WG_IdleDialPadSavePhoneBook((GB_USHORT *)CalllogNum);
		break;

	case GB_WG_CLOG_EDIT_BEFORE_CALL:
		{
			VfxWString str;
				
			str = VFX_WSTR_MEM(CalllogNum);//calllog->cid);
			mmi_id cui_id = vcui_dialer_create(getApp()->getGroupId());	
			vcui_dialer_set_dial_string(cui_id, str);
			vcui_dialer_run(cui_id);
			break;
		}

	case GB_WG_CLOG_SEND_MSG:
		toolbarNewMsg((GB_USHORT *)CalllogNum);
		break;

	default:
		break;
	}
}


GB_VOID WinguoSMDBasePageClass::onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
	//长时间按下列表，并且是列表是电话本联系人的时候做的处理
}


GB_UINT WinguoSMDBasePageClass::getTotal(GB_VOID)
{
	return MMI_SIM_TOTAL;
}


VfxWString gb_wg_sim_settings_get_sim_name(mmi_sim_enum sim)
{
	VfxWChar buffer[NVRAM_EF_SIM_NAME_MAX_LEN];
	if (vapp_sim_settings_get_sim_name_ext(sim, buffer, NVRAM_EF_SIM_NAME_MAX_LEN))
	{
		return VFX_WSTR_MEM(buffer);
	}
	return VFX_WSTR_NULL;
}

GB_VOID WinguoSMDBasePageClass::SelectCallSimId(VfxBool call, mmi_sim_enum sim)
{
	if(srv_mode_switch_is_network_service_available() == MMI_FALSE || srv_sim_ctrl_get_num_of_inserted() == 0)
	{
		WinguoActionObj::makeCall(m_id, pusInputBuff, MMI_SIM1);
	}
	else if (srv_sim_ctrl_get_num_of_inserted() == 1 && call)
	{
		U32 currentSim = getCurrentOnlySim();
		for (GB_UINT i = 0; i < WinguoSMDBasePageClass::getTotal(); i++)
		{
		mmi_sim_enum storage = mmi_frm_index_to_sim(i);
		if (!srv_sim_ctrl_is_inserted(storage))
		{
			continue;
		
		}
		WinguoActionObj::makeCall(m_id, pusInputBuff, storage);
		}
	}
	else if(!GB_WG_IsCallNum(pusInputBuff))
	{
		WinguoActionObj::makeCall(m_id, pusInputBuff, MMI_SIM1);

	}
	else
	{
		VcpMenuPopup *cntxMenu;
		VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
		cntxMenu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_SIM));

	for (GB_UINT i = 0; i < WinguoSMDBasePageClass::getTotal(); i++)
	{
		mmi_sim_enum storage = mmi_frm_index_to_sim(i);
		if (srv_sim_ctrl_is_inserted(storage))
		{
			if (storage == sim)
			{
				continue;
			}

			VfxId btnId = call ? GB_WG_SELECT_SIM_CALL + i : GB_WG_SELECT_SIM_MSG + i;
			VfxWString text = call ? VFX_WSTR_RES(VAPP_PHB_STR_CALL) : VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE);
			if (call)
			{
				cntxMenu->addItem(btnId, text, ContactSim::getCallIcon(storage), VCP_MENU_POPUP_ITEM_TYPE_2);
			}
			((VcpMenuPopupItemType2 *)cntxMenu->getItemById(btnId))->setHintText(gb_wg_sim_settings_get_sim_name(storage));
			if (!(srv_mode_switch_get_current_mode() & storage))
			{
				cntxMenu->getItemById(btnId)->setIsDisabled(GB_TRUE);
			}
		}
	}

	cntxMenu->m_signalMenuCallback.connect(this, &WinguoSMDBasePageClass::SelectSim);
	cntxMenu->show(GB_TRUE);
	}
}

GB_VOID WinguoSMDBasePageClass::SelectCallSimIdSmdList(VfxBool call, mmi_sim_enum sim)
{
	VcpMenuPopup *cntxMenu;
	VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
	cntxMenu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_SIM));

	for (GB_UINT i = 0; i < WinguoSMDBasePageClass::getTotal(); i++)
	{
		mmi_sim_enum storage = mmi_frm_index_to_sim(i);
		if (srv_sim_ctrl_is_inserted(storage))
		{
			if (storage == sim)
			{
				continue;
			}

			VfxId btnId = call ? GB_WG_SELECT_SIM_CALL + i : GB_WG_SELECT_SIM_MSG + i;
			VfxWString text = call ? VFX_WSTR_RES(VAPP_PHB_STR_CALL) : VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE);
			if (call)
			{
				cntxMenu->addItem(btnId, text, ContactSim::getCallIcon(storage), VCP_MENU_POPUP_ITEM_TYPE_2);
			}
			((VcpMenuPopupItemType2 *)cntxMenu->getItemById(btnId))->setHintText(gb_wg_sim_settings_get_sim_name(storage));
			if (!(srv_mode_switch_get_current_mode() & storage))
			{
				cntxMenu->getItemById(btnId)->setIsDisabled(GB_TRUE);
			}
		}
	}

	cntxMenu->m_signalMenuCallback.connect(this, &WinguoSMDBasePageClass::SelectSimSmdList);
	cntxMenu->show(GB_TRUE);
}

GB_VOID WinguoSMDBasePageClass::SelectMoreCallSimIdSmdList(VfxBool call, mmi_sim_enum sim)
{
	VcpMenuPopup *cntxMenu;
	VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
	cntxMenu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_SIM));

	for (GB_UINT i = 0; i < WinguoSMDBasePageClass::getTotal(); i++)
	{
		mmi_sim_enum storage = mmi_frm_index_to_sim(i);
		if (srv_sim_ctrl_is_inserted(storage))
		{
			if (storage == sim)
			{
				continue;
			}

			VfxId btnId = call ? GB_WG_SELECT_SIM_CALL + i : GB_WG_SELECT_SIM_MSG + i;
			VfxWString text = call ? VFX_WSTR_RES(VAPP_PHB_STR_CALL) : VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE);
			if (call)
			{
				cntxMenu->addItem(btnId, text, ContactSim::getCallIcon(storage), VCP_MENU_POPUP_ITEM_TYPE_2);
			}
			((VcpMenuPopupItemType2 *)cntxMenu->getItemById(btnId))->setHintText(gb_wg_sim_settings_get_sim_name(storage));
			if (!(srv_mode_switch_get_current_mode() & storage))
			{
				cntxMenu->getItemById(btnId)->setIsDisabled(GB_TRUE);
			}
		}
	}

	cntxMenu->m_signalMenuCallback.connect(this, &WinguoSMDBasePageClass::SelectSimMoreSmdList);
	cntxMenu->show(GB_TRUE);
}

VfxImageSrc WinguoSMDBasePageClass::getCallIcon(mmi_sim_enum sim)
{
	return VfxImageSrc(getCallIconId(sim));
}


VfxResId WinguoSMDBasePageClass::getCallIconId(mmi_sim_enum sim)
{
	if (srv_sim_ctrl_get_num_of_inserted() == 1) // hot sim plug
	{
		return IMG_COSMOS_GEMINI_SIM_CALL;
	}

	switch (sim)
	{
	case MMI_SIM1:
#if (MMI_MAX_SIM_NUM >= 2)
		return IMG_COSMOS_GEMINI_SIM1_CALL;
#else
		return IMG_COSMOS_GEMINI_SIM_CALL;
#endif

#if (MMI_MAX_SIM_NUM >= 2)
	case MMI_SIM2:
		return IMG_COSMOS_GEMINI_SIM2_CALL;
#if (MMI_MAX_SIM_NUM >= 3)
	case MMI_SIM3:
		return IMG_COSMOS_GEMINI_SIM3_CALL;
#if (MMI_MAX_SIM_NUM >= 4)
	case MMI_SIM4:
		return IMG_COSMOS_GEMINI_SIM4_CALL;
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

	default:
		VFX_ASSERT(0);
		break;
	}

	return IMG_NONE;
}


GB_VOID WinguoSMDBasePageClass::SelectSim(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{

	if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		return;
	}
	if (item->getId() >= GB_WG_SELECT_SIM_CALL)
	{
		WinguoActionObj::makeCall(m_id, pusInputBuff, mmi_frm_index_to_sim(item->getId() - GB_WG_SELECT_SIM_CALL));
	}
	
}

GB_VOID WinguoSMDBasePageClass::SelectSimSmdList(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{

	if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		return;
	}
	if (item->getId() >= GB_WG_SELECT_SIM_CALL)
	{
		WinguoActionObj::makeCall(m_id, PhoneNum, mmi_frm_index_to_sim(item->getId() - GB_WG_SELECT_SIM_CALL));
	}

}

GB_VOID WinguoSMDBasePageClass::SelectSimMoreSmdList(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{

	if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		return;
	}
	if (item->getId() >= GB_WG_SELECT_SIM_CALL)
	{
		WinguoActionObj::makeCall(m_id, MorePhoneNum, mmi_frm_index_to_sim(item->getId() - GB_WG_SELECT_SIM_CALL));
	}

}

GB_VOID WinguoActionObj::makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
 	if((make_call_cb_para != NULL) && (make_call_cb_para->user_data))
 	{
		//断开连接之后摧毁cm用户数据
		srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
	}
}


GB_VOID WinguoActionObj::makeCall(kal_uint16 id, U16 *pusInputBuffr, mmi_sim_enum sim)
{
	mmi_ucm_make_call_para_struct make_call_para;
	GB_VOID *cm_user_data;
	SRV_PHB_ID phb_id;
	U16 store_index = 0;

	mmi_ucm_init_call_para(&make_call_para);
	srv_phb_get_store_index_by_number(pusInputBuffr, &store_index);
	phb_id = srv_phb_create_number_id(PHB_STORAGE_NVRAM, store_index, SRV_PHB_ENTRY_FIELD_NUMBER);

 	if(srv_phb_check_number_id(phb_id))
 	{
 		cm_user_data = srv_phb_create_cm_user_data_by_id(phb_id);
 	}

 	else
 	{
 		cm_user_data = NULL;
 	}

	if (sim == MMI_SIM1)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
	}
	else if (sim == MMI_SIM2)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
	}
	else if (sim == MMI_SIM3)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
	}
	else if (sim == MMI_SIM4)
	{
		make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
	}
	else
	{
		make_call_para.dial_type = (srv_ucm_call_type_enum)(make_call_para.dial_type & (~SRV_UCM_VOIP_CALL_TYPE));
	}

	make_call_para.adv_para.after_callback_user_data = cm_user_data;
	make_call_para.adv_para.phb_data = cm_user_data;
	make_call_para.adv_para.after_make_call_callback = WinguoActionObj::makeCallCb;
	make_call_para.ucs2_num_uri = (U16*) pusInputBuffr;

	mmi_ucm_call_launch(0, &make_call_para);
}

GB_VOID WinguoSMDBasePageClass::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);
	//GB_SMD_Release();// 释放旧的smartdial数据及引擎
	//GB_SMD_Init();//重新初始化smd引擎
	m_textEditor->activate(GB_TRUE);
	onSearchListData(m_textEditor);
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/
