#ifdef __COSMOS_MMI_PACKAGE__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#define TST_VENUS_FW_TRC_BUFF_SIZE 1000

#define TST_VENUS_FW_TRC_RESET \
            memset(g_traceBuffer,0,TST_VENUS_FW_TRC_BUFF_SIZE)
            
#define TST_VENUS_FW_TRC(msg) \
            mmi_wcscat((WCHAR*)g_traceBuffer,(WCHAR*)msg)

#define TST_VENUS_FW_GET_TRC() \
            VFX_WSTR_MEM(g_traceBuffer)   
            
#define TST_VENUS_FW_FUN(fun,ex) \
            if (ex)\
            {\
                TST_VENUS_FW_TRC(fun);\
                TST_VENUS_FW_TRC(L" fail! \n");\
                g_tstCount++;\
            }\
            else\
            {\
                TST_VENUS_FW_TRC(fun);\
                TST_VENUS_FW_TRC(L" success! \n");\
            }
// TODO: also we could log msg to file

#define TST_VENUS_FW_SHOW_MSG(scr, msg) \
            VtstFWPage* pPage;\
            VFX_OBJ_CREATE(pPage,VtstFWPage,(scr));\
            pPage->setText(msg);\
            scr->pushPage(g_pageId++, pPage)

           
typedef void (VfxObject::*oFunc_type)();


class VtstDelayInvoke0 : public VfxObject
{
public:
    VtstDelayInvoke0():m_pTimer(NULL),m_func(NULL),m_pObj(NULL){};
    
    template <class _func_type>
    static void delayInvoke(VfxObject *obj, _func_type func,VfxMsec delay)
    {
        VtstDelayInvoke0* pthis = getSingleton();
        VFX_OBJ_CREATE(pthis->m_pTimer,VfxTimer,obj);
        pthis->m_pTimer->setStartDelay(delay);
        pthis->m_pTimer->m_signalTick.connect(pthis,&VtstDelayInvoke0::onTime);

        if (pthis->m_func && pthis->m_pObj)
        {
            pthis->m_signal.disconnect(pthis->m_pObj, pthis->m_func);
        }
        pthis->m_func = (oFunc_type)func;
        pthis->m_pObj = obj;
        pthis->m_signal.connect(obj,func);
        pthis->m_pTimer->start();
    }
    

    static VtstDelayInvoke0* getSingleton();
    static void release();
private:    
    void onTime(VfxTimer* pTimer)
    {
        if (pTimer)
        {
            pTimer->stop();
            VFX_OBJ_CLOSE(pTimer);
            m_signal.emit();
        }
    };
    
    VfxSignal0  m_signal;
    VfxTimer*   m_pTimer;
    VfxObject*  m_pObj;
    oFunc_type  m_func;
};

class VtstMainApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstMainApp);
public:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ; 
};

/////////////////////////

////////////////////////
#define TST_VENUS_FW_EVENT_ID_1   0xffaa
#define TST_VENUS_FW_EVENT_ID_2   (TST_VENUS_FW_EVENT_ID_1+1)
#define TST_VENUS_FW_EVENT_ID_3   (TST_VENUS_FW_EVENT_ID_1+2)
#define TST_VENUS_FW_EVENT_ID_4   (TST_VENUS_FW_EVENT_ID_1+3)



class VtstFWAppScr;
class VtstFWApp1 : public VfxApp
{
    VFX_DECLARE_CLASS(VtstFWApp1);
public:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ; 

    void onAfterRun();
    void onTstLaunch1();
    void onTstLaunch2();
    void onStep1();
    void onStep2();
    void onStep3();
    void onStep4(); 
    void onStep5();
    void onStep6();
    
    void onFinished();
    
    static mmi_id m_gid;
protected:
    virtual mmi_ret onGroupDeleteReq(DelReason reason);

    // application is activated
    virtual void onGroupActive();

    // application is inactivated, all belonging screens are invisible.
    virtual void onGroupInactive();

    virtual mmi_ret onProc(mmi_event_struct *evt);   

    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

    virtual VfxBool onScrBack(VfxAppScr *scr);
    
    
    VtstFWAppScr*   m_pScr1;
    VtstFWAppScr*   m_pScr2;
    VtstFWAppScr*   m_pScr3;
    VtstFWAppScr*   m_pScr4;
    mmi_id          m_id1;
    mmi_id          m_id2;
    mmi_id          m_id3;
    mmi_id          m_id4;
};

class VtstFWApp2 : public VfxApp
{
    VFX_DECLARE_CLASS(VtstFWApp2);
public:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ;  
    
};

class VtstFWApp3 : public VfxApp
{
    VFX_DECLARE_CLASS(VtstFWApp3);
public:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ;  
    
};


class VtstFWCui : public VfxCui
{
    VFX_DECLARE_CLASS(VtstFWCui);
public:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ; 
    void onStep1();
    void onStep2();
    void onStep3(); 
    void onStep4();
private:
    VtstFWAppScr*   m_pScr;
};

class VtstFWCatScr : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VtstFWCatScr);
public:
    virtual void onEntryEffectInit();
    virtual void onEntryEffectStart();
};

class VtstFWAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstFWAppScr);
public:
    virtual void onRestore(VfxArchive &ar);
    virtual VfxBool onSerialize(VfxArchive &ar);
    virtual void onBack();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxPage *onCreatePage(VfxId  id);
    virtual void on1stReady();
    virtual void on2ndReady();
    virtual VfxBool onPageBack(VfxPage* page);
    
    mmi_id  m_id;
};

class VtstFWPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstFWPage);
public:
    void setText(VfxWString str);
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual VfxBool onSerialize(VfxArchive &ar);
    virtual void onRestore(VfxArchive &ar);
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    virtual void onTransitionStop(
        VfxBool in,         // [IN] in or out
        VfxS32 direction    // [IN] direction of trasnsition, can be 1, 0, -1
    );
    virtual void onBack();
    virtual void onBarAutoHide();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    
private:
    VfxTextFrame*   m_pTextFrame;
};

class VtstFWManualPage : public VtstFWPage
{
public:
    VfxSignal0  m_signalPassOrFail;
    void setTestItem(VfxWString &str);
    
protected:
    virtual void onInit();    
    void onClick(VfxObject* pObj, VfxId id);
    VfxWString  m_strTestItem;
};


class VtstFWPageBar : public VcpToolBar
{
public:
protected:
    virtual void onSetTranslucent(
        VfxBool translucent 
    ) { VFX_UNUSED(translucent); }

    virtual void onSetRotate(
        VfxScrRotateTypeEnum rotate 
    ) { VFX_UNUSED(rotate); }        
};

class VtstFWPageTransition : public VfxPageTransition
{
    
};

#endif// __COSMOS_MMI_PACKAGE__
