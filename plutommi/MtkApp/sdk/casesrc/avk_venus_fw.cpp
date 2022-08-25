#ifdef __COSMOS_MMI_PACKAGE__
#define _AVK_VENUS_FW_11A

#include "avk_Venus_FW.h"
//#include "vtst_rt_main.h"
#include "GlobalResDef.h"

mmi_id VtstFWApp1::m_gid = 0;
static VtstDelayInvoke0    g_delayInvoker;
//static VfxU32   g_tstCount = 0;
//static VfxWChar g_traceBuffer[AVK_VENUS_FW_TRC_BUFF_SIZE];
static VfxU32   g_pageId = 1;
static VfxWeakPtr<VtstFWApp1> g_pMainApp = NULL;


AVK_ASYN_CASE(AVK_VENUS_FW_AUTOCASE,AVK_VENUS_FW)
{
    VtstFWApp1::m_gid = VfxAppLauncher::launch( 
        VAPP_VENUS_TST_FW_1, 
        VFX_OBJ_CLASS_INFO(VtstFWApp1),
        GRP_ID_ROOT,
        NULL, 0);
}


VtstDelayInvoke0* VtstDelayInvoke0::getSingleton()
{
    return &g_delayInvoker;
}

void VtstDelayInvoke0::release()
{
    g_delayInvoker.m_pObj = NULL;
    g_delayInvoker.m_func = NULL;
}


VFX_IMPLEMENT_CLASS("VtstMainApp",VtstMainApp,VfxApp);

void VtstMainApp::onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    )
{
    VfxMainScr* pScr;
    VFX_OBJ_CREATE(pScr,VfxMainScr,this);  
    pScr->show();
}
//********************************************
////VfxApp relative api test
//********************************************

VFX_IMPLEMENT_CLASS("VtstFWApp1",VtstFWApp1,VfxApp);

void VtstFWApp1::onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    )
{
    g_pMainApp = this;
    
    AVK_LOG_EX(VfxApp::isRunning());
    AVK_LOG_EX(VfxApp::isActive());
    AVK_LOG_EX(!VfxApp::getHidden());
    AVK_LOG_EX(NULL != VfxApp::getContext());
    AVK_LOG_EX(0 == VfxApp::getScreenCount());  

    VfxAppCatScr::initalize();
    AVK_LOG_EX(NULL != VfxAppCatScr::getContext());
    VfxAppCatScr::deinitalize();

    VFX_OBJ_CREATE(m_pScr1,VtstFWAppScr,this);
    VFX_OBJ_CREATE(m_pScr2,VtstFWAppScr,this);
    VFX_OBJ_CREATE(m_pScr3,VtstFWAppScr,this);
    VFX_OBJ_CREATE(m_pScr4,VtstFWAppScr,this);    

    //get app
    AVK_LOG_FUN(VfxAppScr::getApp,this == (VtstFWApp1*)m_pScr1->getApp()); 

    m_id1 = m_pScr1->show();
    
	VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onAfterRun,1000);
}

void VtstFWApp1::onAfterRun()
{
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onTstLaunch1,1000);
}

void VtstFWApp1::onTstLaunch1()
{
    
    AVK_LOG_EX(this == (VtstFWApp1*)VfxAppLauncher::getObject(VtstFWApp1::m_gid));
    AVK_LOG_EX(this == (VtstFWApp1*)VfxAppLauncher::findApp(VAPP_VENUS_TST_FW_1,
                                                VFX_OBJ_CLASS_INFO(VtstFWApp1),
                                                VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG));
                                                
    VfxAppLauncher::launch(VAPP_VENUS_TST_FW_2,VFX_OBJ_CLASS_INFO(VtstFWApp2),getGroupId(),NULL,0);
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onTstLaunch2,1000);
}

void VtstFWApp1::onTstLaunch2()
{
    VfxAppLauncher::launchWithCtx(VAPP_VENUS_TST_FW_3,VFX_OBJ_CLASS_INFO(VtstFWApp3),getGroupId(),getContext(),NULL,0);
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep1,1000);
}

void VtstFWApp1::onStep1()
{
    AVK_LOG_EX(m_gid == VfxApp::getGroupId());
    AVK_LOG_EX(this == (VtstFWApp1*)VfxApp::getObject(m_gid));
    
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep2,1000);
}
//VfxApp relative api test

void VtstFWApp1::onStep2()
{
	m_id2 = m_pScr2->show();
    m_id3 = m_pScr3->show();

    AVK_LOG_EX(3 == VfxApp::getScreenCount()); 
    
    AVK_LOG_EX(m_id3 == VfxApp::getNextScreenId(m_id2)); 
    
    AVK_LOG_EX(m_id1 == VfxApp::getPrevScreenId(m_id2)); 
    
    AVK_LOG_EX(m_id3 == VfxApp::getTopScreenId()); 
    
    AVK_LOG_EX(m_id1 == VfxApp::getBottomScreenId()); 

    AVK_LOG_EX((VtstFWAppScr*)VfxApp::getScreen(m_id3));
    
    AVK_LOG_EX(m_pScr3 == (VtstFWAppScr*)VfxApp::getTopScreen());  

    closeScreen(m_id3);
    AVK_LOG_FUN(VfxApp::closeScreen, 2 == getScreenCount());

    m_pScr2 = (VtstFWAppScr*)getTopScreen();
    closeScreen(m_pScr2->getScreenId());
    m_pScr2 = (VtstFWAppScr*)getTopScreen();

    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep3,4000);
}

//********************************************
//VfxAppScr / VfxMainScr relative api test
//********************************************

void VtstFWApp1::onStep3()
{    

 //   TST_VENUS_FW_FUN(L"VfxAppScr::back()/exit()", 1 != getScreenCount());
    
    VtstFWPage* pPage1;
    VFX_OBJ_CREATE(pPage1,VtstFWPage,m_pScr2);
    pPage1->setText(VFX_WSTR("1"));
    VtstFWPage* pPage2;
    VFX_OBJ_CREATE(pPage2,VtstFWPage,m_pScr2);
    pPage1->setText(VFX_WSTR("2"));
    VtstFWPage* pPage3;
    VFX_OBJ_CREATE(pPage3,VtstFWPage,m_pScr2);
    pPage1->setText(VFX_WSTR("3"));
    VtstFWPage* pPage4;
    VFX_OBJ_CREATE(pPage4,VtstFWPage,m_pScr2);
    pPage1->setText(VFX_WSTR("4"));
    VtstFWPage* pPage5;
    VFX_OBJ_CREATE(pPage5,VtstFWPage,m_pScr2);
    pPage1->setText(VFX_WSTR("5"));
    //
    //page: 1.4.5.2.3->1.4.5
    m_pScr2 = (VtstFWAppScr*)getTopScreen();    
    VfxId id1 = m_pScr2->pushPage(g_pageId++, pPage1);
    VfxId id2 = m_pScr2->pushPage(g_pageId++, pPage2);
    VfxId id3 = m_pScr2->pushPage(g_pageId++, pPage3);
    VfxId id4 = m_pScr2->insertPage(g_pageId++, pPage4,id1);
    VfxId id5 = m_pScr2->insertPage(g_pageId++, pPage5,id4);
    m_pScr2->popPage();
    m_pScr2->closePage(id2);

    m_pScr2->setAllowDelete(VFX_FALSE);
    AVK_LOG_FUN(VfxAppScr::getAllowDelete,VFX_FALSE == m_pScr2->getAllowDelete());    
    m_pScr2->setAllowDelete(VFX_TRUE);
    AVK_LOG_FUN(VfxAppScr::getApp,this == (VtstFWApp1*)m_pScr2->getApp());  
    AVK_LOG_FUN(VfxAppScr::isShown,m_pScr2->isShown());
    AVK_LOG_FUN(VfxAppScr::getGroupId,this->getGroupId() == m_pScr2->getGroupId());
    AVK_LOG_FUN(VfxAppScr::getScreenId,m_pScr2->getScreenId());
    
    AVK_LOG_FUN(VfxMainScr::isPageIdValid ,!(m_pScr2->isPageIdValid(id2) 
                                                     || m_pScr2->isPageIdValid(id3)
                                                     || !m_pScr2->isPageIdValid(id1)));
    
    AVK_LOG_FUN(VfxMainScr::getPage,pPage1 == (VtstFWPage*)m_pScr2->getPage(id1));
    AVK_LOG_FUN(VfxMainScr::getPageId,id1 == m_pScr2->getPageId(pPage1));
    AVK_LOG_FUN(VfxMainScr::getPageCount, m_pScr2->getPageCount());
    AVK_LOG_FUN(VfxMainScr::getTopPageId,id5 == m_pScr2->getTopPageId());
    AVK_LOG_FUN(VfxMainScr::findMainScr,m_pScr2 == (VtstFWAppScr*)VfxMainScr::findMainScr((VfxFrame*)pPage1));
    //some api that not easy to test, just invoke to insure interface 
    m_pScr2->getClient(pPage1);
    m_pScr2->setAutoClose(VFX_FALSE);

    //////
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep4,1000);
}



//********************************************
////VfxPage relative api test
//********************************************
void VtstFWApp1::onStep4()
{
    VtstFWPage* pPage;
    VFX_OBJ_CREATE(pPage,VtstFWPage,m_pScr2);
    m_pScr2->pushPage(g_pageId++, pPage);
//    pPage->setText(VFX_WSTR("Bar Will Hide Automaticely"));

    AVK_LOG_FUN(VfxPage::getId,m_pScr2->getTopPageId() == pPage->getId());
    AVK_LOG_FUN(VfxPage::isActive,pPage->isActive());
    pPage->setStatusBar(VFX_TRUE);
    AVK_LOG_FUN(VfxPage::setStatusBar,pPage->hasStatusBar());
    AVK_LOG_FUN(VfxPage::getApp,this == (VtstFWApp1*)pPage->getApp());
    AVK_LOG_FUN(VfxPage::getMainScr,m_pScr2 == (VtstFWAppScr*)pPage->getMainScr());
    AVK_LOG_FUN(VfxPage::setAllowDelete,AVK_PASS);
    pPage->setAllowDelete(VFX_TRUE);
    AVK_LOG_FUN(VfxPage::getImeMode,pPage->getImeMode());
        
    VtstFWPageBar* pBar;    
    VFX_OBJ_CREATE(pBar, VtstFWPageBar, pPage);
    pPage->setTopBar(pBar);
    VFX_OBJ_CREATE(pBar, VtstFWPageBar, pPage);
    pPage->setBottomBar(pBar);

    AVK_LOG_FUN(VfxPage::getBar, pBar == (VtstFWPageBar*)pPage->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM));
    pPage->setBarAutoHide(VFX_TRUE);
    pPage->hideAllBars(VFX_FALSE);
    pPage->setTranslucent(VFX_TRUE);
    pPage->setPosZ(0);

    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep6,1000);
}

void VtstFWApp1::onStep5()
{
    VtstDelayInvoke0::delayInvoke(this,&VtstFWApp1::onStep6,1000);
}

void VtstFWApp1::onStep6()
{
    mmi_id id = VfxAppLauncher::createCui(VAPP_VENUS_TST_FW_2,VFX_OBJ_CLASS_INFO(VtstFWCui),getGroupId(),NULL,0);
    VfxAppLauncher::runCui(id);
}

mmi_ret VtstFWApp1::onGroupDeleteReq(DelReason reason)
{
    return VfxApp::onGroupDeleteReq(reason);
}

// application is activated
void VtstFWApp1::onGroupActive()
{
    VfxApp::onGroupActive();
}

// application is inactivated, all belonging screens are invisible.
void VtstFWApp1::onGroupInactive()
{
    VfxApp::onGroupInactive();
}

mmi_ret VtstFWApp1::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == TST_VENUS_FW_EVENT_ID_1)
    {
        AVK_LOG_FUN(VfxApp::onProc, AVK_PASS);
        AVK_LOG_FUN(VfxCui::sendToParent, AVK_PASS);
    }
    else if (evt->evt_id == TST_VENUS_FW_EVENT_ID_2)
    {
        AVK_LOG_FUN(VfxCui::postToParent,AVK_PASS);
    }
    else if (evt->evt_id == TST_VENUS_FW_EVENT_ID_3)
    {
        AVK_LOG_FUN(VfxCui::sendToCaller,AVK_PASS);
    }
    else if (evt->evt_id == TST_VENUS_FW_EVENT_ID_4)
    {
       AVK_LOG_FUN(VfxCui::postToCaller,AVK_PASS);
       
    }
    return VfxApp::onProc(evt);
}

VfxAppCloseAnswerEnum VtstFWApp1::onProcessClose(VfxAppCloseOption options)
{
    return VfxApp::onProcessClose(options);
}

VfxBool VtstFWApp1::onScrBack(VfxAppScr *scr)
{
    return VfxApp::onScrBack(scr);
}

void VtstFWApp1::onFinished()
{
    VtstDelayInvoke0::release();
    VfxAppScr* pScr = getTopScreen();
    if (pScr)
    {
        pScr->exit();
    }
    AVK_ASYN_DONE();
}


//class VtstFWApp2 use to test VfxAppLauncher::launch()

VFX_IMPLEMENT_CLASS("VtstFWApp2",VtstFWApp2,VfxApp);
void VtstFWApp2::onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    )
{
    AVK_LOG_FUN(VfxAppLauncher::launch,AVK_PASS);
    exit();
}

//class VtstFWApp2 use to test VfxAppLauncher::launchWithCtx ()

VFX_IMPLEMENT_CLASS("VtstFWApp3",VtstFWApp3,VfxApp);
void VtstFWApp3::onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    )
{
    AVK_LOG_FUN(VfxAppLauncher::launchWithCtx,AVK_PASS);
    exit();
}



VFX_IMPLEMENT_CLASS("VtstFWCui",VtstFWCui,VfxCui);
void VtstFWCui::onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    )
{
    AVK_LOG_FUN(VfxAppLauncher::createCui,AVK_PASS);
    AVK_LOG_FUN(VfxAppLauncher::runCui,AVK_PASS);
    AVK_LOG_FUN(VfxCui::getParentId,VtstFWApp1::m_gid == getParentId());

    VFX_OBJ_CREATE(m_pScr,VtstFWAppScr,this);
    m_pScr->show();
    
    mmi_group_event_struct event1;
    event1.evt_id = TST_VENUS_FW_EVENT_ID_1;
    event1.sender_id = getGroupId();
    sendToParent(&event1);      
    
    VtstDelayInvoke0::delayInvoke(this,&VtstFWCui::onStep1,500);
//    exit();
}

void VtstFWCui::onStep1()
{
    mmi_group_event_struct event2;
    event2.evt_id = TST_VENUS_FW_EVENT_ID_2;
    event2.size = sizeof(event2);;
    event2.sender_id = getGroupId();  
    postToParent(&event2);
    
    VtstDelayInvoke0::delayInvoke(this,&VtstFWCui::onStep2,500);
}

void VtstFWCui::onStep2()
{
    mmi_group_event_struct event3;
    event3.evt_id = TST_VENUS_FW_EVENT_ID_3;
    event3.sender_id = getGroupId();  
    sendToCaller(&event3);
    
    VtstDelayInvoke0::delayInvoke(this,&VtstFWCui::onStep3,500);
}

void VtstFWCui::onStep3()
{
    mmi_group_event_struct event4;
    event4.evt_id = TST_VENUS_FW_EVENT_ID_4;
    event4.size = sizeof(event4);
    event4.sender_id = getGroupId();  
    postToCaller(&event4);    
    VtstDelayInvoke0::delayInvoke(this,&VtstFWCui::onStep4,500);
}

void VtstFWCui::onStep4()
{
    VtstDelayInvoke0::delayInvoke(VfxAppLauncher::getObject(VtstFWApp1::m_gid),&VtstFWApp1::onFinished,1000);
    exit();   
}

//class VtstFWCatScr

VFX_IMPLEMENT_CLASS("VtstFWCatScr",VtstFWCatScr,VfxAppCatScr);

void VtstFWCatScr::onEntryEffectInit()
{
}

void VtstFWCatScr::onEntryEffectStart()
{
}


VFX_IMPLEMENT_CLASS("VtstFWAppScr",VtstFWAppScr,VfxMainScr);

void VtstFWAppScr::onRestore(VfxArchive &ar)
{
    
}

VfxBool VtstFWAppScr::onSerialize(VfxArchive &ar)
{
    return VFX_TRUE;
}

void VtstFWAppScr::onBack()
{
    
}

mmi_ret VtstFWAppScr::onProc(mmi_event_struct *evt)
{
    return 0;
}

VfxPage *VtstFWAppScr::onCreatePage(VfxId  id)
{
    return NULL;
}

void VtstFWAppScr::on1stReady()
{
    
}

void VtstFWAppScr::on2ndReady()
{
    
}

VfxBool VtstFWAppScr::onPageBack(VfxPage* page)
{
    return VFX_TRUE;
}   


//class VtstFWPage
VFX_IMPLEMENT_CLASS("VtstFWPage",VtstFWPage,VfxPage);

void VtstFWPage::onInit()
{
    VfxPage::onInit();
    setBgColor(VRT_COLOR_WHITE);
    VFX_OBJ_CREATE(m_pTextFrame,VfxTextFrame,this);
    m_pTextFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_pTextFrame->setColor(VRT_COLOR_BLACK);      
}

void VtstFWPage::setText(VfxWString str)
{
    m_pTextFrame->setString(str); 
    m_pTextFrame->setBounds(0,0,getSize().width,getSize().height);
}


void VtstFWPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
};

void VtstFWPage::onEntered()
{
    VfxPage::onEntered();
};

void VtstFWPage::onExit(VfxBool isBackward)
{
    VfxPage::onExit(isBackward);
};

void VtstFWPage::onExited()
{
    VfxPage::onExited();
};


VfxBool VtstFWPage::onSerialize(VfxArchive &ar)
{
    return VfxPage::onSerialize(ar);
};

void VtstFWPage::onRestore(VfxArchive &ar)
{
    return VfxPage::onRestore(ar);
};

void VtstFWPage::onQueryRotateEx(
    VfxScreenRotateParam &param // The parameter to rotate
)
{
    VfxPage::onQueryRotateEx(param);
};

void VtstFWPage::onRotate(
    const VfxScreenRotateParam &param // The parameter to rotate
)
{
    VfxPage::onRotate(param);
};

void VtstFWPage::onTransitionStop(
    VfxBool in,         // [IN] in or out
    VfxS32 direction    // [IN] direction of trasnsition, can be 1, 0, -1
)
{
    VfxPage::onTransitionStop(in,direction);
};

void VtstFWPage::onBack()
{
    VfxPage::onBack();
};

void VtstFWPage::onBarAutoHide()
{
    VfxPage::onBarAutoHide();
};

mmi_ret VtstFWPage::onProc(mmi_event_struct *evt)
{
    return VfxPage::onProc(evt);
};




void VtstFWManualPage::onInit()
{
    VtstFWPage::onInit();

    VfxSize size = getSize();
    
    VcpButton* pButton;
    VFX_OBJ_CREATE(pButton, VcpButton, this);
    pButton->setId(1);
    pButton->setText(VFX_WSTR("Pass"));
    pButton->setAnchor(0.5,0.5);
    pButton->setPos(size.width/2,size.height*2/3);
    pButton->m_signalClicked.connect(this,&VtstFWManualPage::onClick);
    
    VFX_OBJ_CREATE(pButton, VcpButton, this);
    pButton->setId(2);
    pButton->setText(VFX_WSTR("Fail"));
    pButton->setAnchor(0.5,0.5);
    pButton->setPos(size.width/2,size.height*2/3+pButton->getSize().height);
    pButton->m_signalClicked.connect(this,&VtstFWManualPage::onClick);   
}

void VtstFWManualPage::setTestItem(VfxWString &str)
{
    m_strTestItem = str;
}

void VtstFWManualPage::onClick(VfxObject* pObj, VfxId id)
{
    if (1 == id)
    {
        m_strTestItem += VFX_WSTR(" success!");
//        TST_VENUS_FW_TRC(m_strTestItem.getBuf());
    }
    else
    {
        m_strTestItem += VFX_WSTR(" fail!");
//        TST_VENUS_FW_TRC(m_strTestItem.getBuf());
    }
    
    m_signalPassOrFail.emit();
    exit();
}
#endif //__COSMOS_MMI_PACKAGE__    

