#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#include "avk_conn_bthfp.h"
#include "avk_conn_btds.h"
#include "MMI_include.h"
#include "BthfSrvGprot.h"
//#include "tst_sdk_framework.h"
#include "CommonScreens.h"
#include "GlobalResDef.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "CommonScreensResDef.h"
#include "CustMenuRes.h"
#include "mmi_frm_history_gprot.h"

#define VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(a, b, c) \
    AVK_CASE_RESULT(AVK_PASS); \
     AVK_ASYN_DONE();
    //VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_EX(a, b, c, GRP_ID_VS_AVK_BTHFP)

typedef struct
{
    S32 idx_hl;
#ifdef __MMI_HFP_SUPPORT__
    BTHFHandle srv_hd;
    U32 dev_id;
    BTHFAddr ear_addr;
#endif /*__MMI_HFP_SUPPORT__ */
    MMI_ID group_id;
    WCHAR szbuf[MAX_TXT];
}vs_bthfp_ctx;

static vs_bthfp_ctx sg_vs_bthfp_ctx;

AVK_ADD_ITEM(AVK_CONN_BTHFP_MANUAL_N, L"Manual cases", AVK_CONN_BTHFP);
//AVK_ADD_ITEM(AVK_CONN_BTHFP_MANUAL_E, L"Manual cases Exp", AVK_CONN_BTHFP);


static void VS_CASE_BTHFP_FINISHED(MMI_BOOL ret_b, vs_test_item_enum ti_e, const void * words)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_CASE_RESULT((0 != ret_b) ? AVK_PASS : AVK_FAIL);
    AVK_ASYN_DONE();

 /*
    U16 wszTxt[128] = {0};
    
    vs_tfw_trace_result((U16*)words, ret_b, 0, VS_TA_BTHFP);
    if (vs_tfw_is_test_all_active(ti_e))
    {
        if (ret_b)
            vs_tfw_finish_case(ti_e);
    }
    else
    {
        kal_wstrcat(wszTxt, words);
        kal_wsprintf(&wszTxt[kal_wstrlen(wszTxt)], " ret [%d]", ret_b);
        #ifdef __MMI_SCREEN_ROTATE__
        if (ret_b)
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        else
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        #endif
    }
*/
}
static void mmi_vs_bthfp_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    mmi_popup_property_struct arg;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_get_active_id();


    mmi_popup_property_init(&arg);              
    arg.callback = NULL;       
    arg.user_tag = NULL;          
    arg.parent_id = parent_gid; 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
    mmi_popup_display(                          
        str_ptr,                                
        type,                                   
        &arg);  

}
/*
static mmi_ret vs_bthfp_main_group_proc(mmi_event_struct *param);
static mmi_ret vs_bthfp_menu_cui_proc(mmi_event_struct * param);
static void vs_bthfp_notice_entry(void);

static void vs_bthfp_option_highlight_hdlr(S32 index);
static void vs_bthfp_entry_scr_int(void);
static void vs_bthfp_exit_scr(void);
*/
#ifdef __MMI_HFP_SUPPORT__
static void vs_bthfp_entry_input_addr_scr(void);
static void vs_bthfp_entry_cfm(void* cb, void* ud, U16 StringId);
static mmi_ret vs_bthfp_entry_input_cfm_cb(mmi_alert_result_evt_struct *evt);
#if 0
/* under construction !*/
#endif
static mmi_ret vs_bthfp_entry_voice_cfm_cb(mmi_alert_result_evt_struct *evt);

static void vs_bthfp_entry_input_addr_done(void);
static S32 vs_bthfp_evt_cb(BTHFHandle srv_hd, U32 evt, U32 para);
static S32 vs_bthfp_attached_cb(U32 para);
static S32 vs_bthfp_detached_cb(U32 para);
static S32 vs_bthfp_vol_changed_cb(U32 para);
static S32 vs_bthfp_remote_attached_req_cb(U32 para);
#endif /* __MMI_HFP_SUPPORT__ */

static void vs_bthfp_leftkey_handler_cb(void)
{
    vs_bthfp_prepare();
}


AVK_MANUAL_CASE(AVK_CONN_BTHFP_MANUAL_PREPARE_N, AVK_CONN_BTHFP_MANUAL_N)
{

    CHAR buf[] = {"1. Need a audio device of bluetooth (earphone). \n\
    2. Get the address of the earphone anyway. \n\
    3. In 'prepare' menu item, you may type the address you have gotten. \n\
    4. Make sure bluetooth is swith on & the audio dev is all so pwred on. \n\
    5. ' do' menu item is the case that ask whether you have heard any sound. \n\
    6. To press the case in order. \n\
    7. Press 'OK' to begin."};

    static WCHAR wbuf[512];

    mmi_asc_to_wcs(wbuf, buf);
    
    AVK_MANU_SHOW_TIPS(wbuf, vs_bthfp_leftkey_handler_cb);
    
}

AVK_MANUAL_CASE(AVK_CONN_BTHFP_MANUAL_START_N, AVK_CONN_BTHFP_MANUAL_PREPARE_N)
{
    vs_bthfp_start();
}

AVK_MANUAL_CASE(AVK_CONN_BTHFP_MANUAL_DO_N, AVK_CONN_BTHFP_MANUAL_PREPARE_N)
{
    vs_bthfp_do();
}

AVK_MANUAL_CASE(AVK_CONN_BTHFP_MANUAL_FINISH_N, AVK_CONN_BTHFP_MANUAL_PREPARE_N)
{
    vs_bthfp_finish();
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
#endif

void vs_bthfp_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mask = 0xFFFF; /* all the event */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    DS_OUTLOG("vs_bthfp_prepare S");
    if (0 < sg_vs_bthfp_ctx.srv_hd)
    {
        DisplayPopup((PU8)L"srv_bthf_open already", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        AVK_CASE_RESULT(AVK_PASS);
        AVK_ASYN_DONE();
        return;
    }
    
    sg_vs_bthfp_ctx.srv_hd = srv_bthf_open();
    if (!sg_vs_bthfp_ctx.srv_hd)
    {
        DS_OUTLOG("srv_bthf_open F");
        VS_CASE_BTHFP_FINISHED(MMI_FALSE, 0, L"vs_bthfp_prepare");
        return;
    }
    if (BTHF_RESULT_SUCC != srv_bthf_set_notify(sg_vs_bthfp_ctx.srv_hd, vs_bthfp_evt_cb, mask, BTHF_MOP_NEW))
    {
        DS_OUTLOG("vs_bthfp_prepare srv_bthf_set_notify ret not RE");
    }



    // entry an input scr
    vs_bthfp_entry_input_addr_scr();
    
    DS_OUTLOG("vs_bthfp_prepare E");
    
#else
    
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(L"vs_bthfp_prepare",VS_TA_BTHFP, 0);
    
#endif
}

void vs_bthfp_start(void)
{
#ifdef __MMI_HFP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dev_id = 0;
    U32 mode = BTHF_AUD_REMOTE;
    U32 m = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    DS_OUTLOG("vs_bthfp_start S");
    if (0 == (dev_id = srv_bthf_attach(sg_vs_bthfp_ctx.srv_hd, &(sg_vs_bthfp_ctx.ear_addr))))
    {
        DS_OUTLOG("srv_bthf_attach ret 0");
        VS_CASE_BTHFP_FINISHED(MMI_FALSE, 0, L"vs_bthfp_start");
        return;
    }

    sg_vs_bthfp_ctx.dev_id = dev_id;

    if (m)
        srv_bthf_reject(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id);

    
    srv_bthf_config(sg_vs_bthfp_ctx.srv_hd, BTHF_CFG_AUDIO_PATH, (void*)&mode);
    
    DS_OUTLOG("vs_bthfp_start E");
    
#else
    
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(L"vs_bthfp_start",VS_TA_BTHFP, 0);
    
#endif
}
void vs_bthfp_do(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_HFP_SUPPORT__
    DS_OUTLOG("vs_bthfp_do S");
//    vs_bthfp_entry_cfm((void*)vs_bthfp_entry_voice_cfm_cb, (void*)L"Have you heard?", STR_GLOBAL_OK);
	AVK_MANU_SHOW_SCR(L"Have you heard?", NULL, NULL);

    DS_OUTLOG("vs_bthfp_do E");

	
#else

    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(L"vs_bthfp_do",VS_TA_BTHFP, 0);

#endif
}

void vs_bthfp_abt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
        DS_OUTLOG("vs_bthfp_abt S");

    
        srv_bthf_abort(sg_vs_bthfp_ctx.srv_hd);
        
        VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_abt");
        
        DS_OUTLOG("vs_bthfp_abt E");
        
#else
        
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(L"vs_bthfp_abt",VS_TA_BTHFP, 0);
        
#endif

}

void vs_bthfp_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BT_MANUAL_AUDIO_SWITCH__
    DS_OUTLOG("vs_bthfp_finish S");

    
    srv_bthf_audio_off(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id);
    if (BTHF_RESULT_SUCC != srv_bthf_detach(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id))
    {
        DS_OUTLOG("srv_bthf_detach F");
        VS_CASE_BTHFP_FINISHED(MMI_FALSE, 0, L"vs_bthfp_finish");
        return;
    }
    
    srv_bthf_abort_all();

    srv_bthf_close(sg_vs_bthfp_ctx.srv_hd);
    sg_vs_bthfp_ctx.srv_hd = NULL;

    
    DS_OUTLOG("vs_bthfp_finish E");
    
#else
    
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTHFP_EX(L"vs_bthfp_finish",VS_TA_BTHFP, 0);
    
#endif
}
//void vs_bthfp_test_all(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U16 id;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    
//    DS_OUTLOG("vs_bthfp_test_all S");
//
//    vs_tfw_set_both_auto_and_manual();
//    id = GetActiveScreenId();
//
//    vs_tfw_test_all_reset();
//    vs_tfw_test_all_screen_id(id);
//    vs_tfw_ta_scope(VS_TA_BT1, VS_TA_TOTAL);
//    vs_tfw_find_beginning(VS_TA_BTHFP);
//
//    DS_OUTLOG("vs_bthfp_test_all E");
//}
//
///*****************************************************************************
// * FUNCTION
// *  vs_bthfp_main_group_proc
// * DESCRIPTION
// *  This function is BT CM Main screen group proc function
// *  It will handle all event on the screen group
// * PARAMETERS
// *  param       [IN]        MMI event structure
// * RETURNS
// *  mmi_ret
// *****************************************************************************/
//mmi_ret vs_bthfp_main_group_proc(mmi_event_struct *param)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    //S32 i;
//    //mmi_ret ret = MMI_RET_OK;
//    //cui_menu_event_struct *evt_menu = NULL;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    ASSERT(param);
//
//    //evt_menu = (cui_menu_event_struct*)evt;
//
//    switch (param->evt_id)
//    {
//    case EVT_ID_GROUP_FIRST_ENTRY:
//        //ret = mmi_am_grp_first_entry();
//        break;
//
//    case EVT_ID_GROUP_ACTIVE:
//        //ret = mmi_am_grp_active();
//        break;
//
//    case EVT_ID_GROUP_INACTIVE:
//        //ret = mmi_am_grp_inactive();
//        break;
//
//    case EVT_ID_GROUP_DEINIT:
//
//        //ret = mmi_am_grp_deinit();
//        //mmi_am_dla_list_reload();
//        break;
//
//        /************************* Menu CUI event *****************************/
//    case EVT_ID_CUI_MENU_LIST_ENTRY:
//    case EVT_ID_CUI_MENU_LIST_EXIT:
//    case EVT_ID_CUI_MENU_ITEM_HILITE:
//    case EVT_ID_CUI_MENU_ITEM_SELECT:
//    case EVT_ID_CUI_MENU_ITEM_TAP:
//    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
//    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
//    case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
//    case EVT_ID_CUI_INLINE_SUBMIT:
//    case EVT_ID_CUI_INLINE_ABORT:
//        {
//            //cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
//            ///*ret = */mmi_am_dla_list_option_menu_cb(evt);
//            vs_bthfp_menu_cui_proc(param);
//        }
//        break;
//
//
//    }
//
//    return MMI_RET_OK;
//}
//
//
//static mmi_ret vs_bthfp_menu_cui_proc(mmi_event_struct * param)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)param;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    switch (menu_evt->evt_id)
//    {
//        case EVT_ID_CUI_MENU_LIST_ENTRY:
//            {
//                //vs_btcm_notice_entry();
//            }break;;
//        case EVT_ID_CUI_MENU_ITEM_SELECT:
//            {
//            }break;
//              
//        /* CUI Menu highlight event : send to APP by the menu cui highlight handler */            
//        case EVT_ID_CUI_MENU_ITEM_HILITE:
//            {
//                switch (menu_evt->parent_menu_id)
//                {
//                }
//            }break;
//      
//        /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
//        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
//            cui_menu_close(menu_evt->sender_id);
//            break;
//        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
//             break;
//        /* CUI Menu exit event : sent to APP on exiting list menu screen */
//        case EVT_ID_CUI_MENU_LIST_EXIT:
//            {
//            }
//            break;  
//    }
//    return MMI_RET_OK;
//
//}
//
//static void vs_bthfp_notice_entry(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U16 tmp_buf_wsz[] = {L"1. Need a audio dev of bluetooth. \n\
//    2. Get the address of the dev anyway. \n\
//    3. In 'prepare' menu item, you may type the address you have gotten. \n\
//    4. 'do' menu item is the case that ask whether you have hear any sound. \n\
//    5. Make sure bluetooth is swith on & the audio dev is all so pwred on. \n\
//    6. To press the case in order. \n\
//    7. Press 'OK' to begin."};
//    S32 size = 0;
//    U8 *gui_buffer = NULL;
//    MMI_BOOL ret_b = MMI_FALSE;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/    
//    ret_b = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTHFP, 
//                                                    SCR_ID_VS_AVK_BTHFP_NOTICE, 
//                                                    NULL, 
//                                                    vs_bthfp_notice_entry, 
//                                                    MMI_FRM_UNKNOW_SCRN);
//    if (!ret_b)
//    {
//        mmi_vs_bthfp_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
//        DS_OUTLOG("[DLA] [F] vs_bthfp_notice_entry SCR_ID_VS_AVK_BTHFP_NOTICE");
//        return;
//    }
//    ShowCategory74Screen(
//        STR_GLOBAL_DETAILS,
//        0,
//        STR_GLOBAL_OK,
//        IMG_GLOBAL_OK,
//        STR_GLOBAL_BACK, 
//        IMG_GLOBAL_BACK,
//        (PU8)tmp_buf_wsz,
//        size,
//        (PU8)gui_buffer);
//
//    SetLeftSoftkeyFunction(vs_bthfp_entry_scr_int, KEY_EVENT_UP);          
//    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
//
//}
//
//static void vs_bthfp_option_highlight_hdlr(S32 index)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    //UI_string_type item_text;
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//
////    UI_string_type item_text = get_item_text(index);
//
//    switch (index)
//    {
//    case VS_BTHFP_ITEM_PREPARE:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_prepare, KEY_EVENT_UP);
//        }break;
//    case VS_BTHFP_ITEM_START:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_start, KEY_EVENT_UP);
//        }break;
//    case VS_BTHFP_ITEM_DO:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_do, KEY_EVENT_UP);
//        }break;
//    case VS_BTHFP_ITEM_ABT:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_abt, KEY_EVENT_UP);
//        }break;
//    case VS_BTHFP_ITEM_FINISH:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_finish, KEY_EVENT_UP);
//        }break;
//    case VS_BTHFP_ITEM_TEST_ALL:
//        {
//            SetLeftSoftkeyFunction(vs_bthfp_test_all, KEY_EVENT_UP);
//        }break;
//    default:
//        {
//            ASSERT(0);
//        }break;
//    }
//
//    sg_vs_bthfp_ctx.idx_hl = index;
//}
//
//void vs_bthfp_entry_scr(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    DS_OUTLOG("vs_bthfp_entry_scr S");
//
//    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VS_AVK_BTHFP, vs_bthfp_main_group_proc, NULL);
//    sg_vs_bthfp_ctx.group_id = GRP_ID_VS_AVK_BTHFP;
//    mmi_frm_group_enter(sg_vs_bthfp_ctx.group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//
//    vs_bthfp_notice_entry();
//
//
//    DS_OUTLOG("vs_bthfp_entry_scr E");
//}
//
//static void vs_bthfp_entry_scr_int(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//#ifdef BT_RES_ITEM
//    U16 nitems = 0;
//#endif
//    U16 itemlist[VS_BTHFP_OPTOIN_SIZE] = {0};
//    int item = 0;
//    MMI_BOOL ret = MMI_FALSE;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    
//    //mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
//    //if (SCR_ID_VS_AVK_BTHFP_NOTICE == scrn_id)
//    //    mmi_frm_scrn_close(GRP_ID_VS_AVK_BTHFP, SCR_ID_VS_AVK_BTHFP_NOTICE);
//
//    ret = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTHFP, SCR_ID_VS_AVK_BTHFP, NULL, vs_bthfp_entry_scr_int, MMI_FRM_FULL_SCRN);
//
//    if(ret == MMI_FALSE)
//        return;
//
//    RegisterHighlightHandler(vs_bthfp_option_highlight_hdlr);
//#ifdef BT_RES_ITEM
//    nitems = GetNumOfChild_Ext(MENU_ID_VS_AVK_BTHFP);
//#else
//
//#endif
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_PREPARE;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_START;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_DO;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_ABT;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_FINISH;
//    
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTHFP_TEST_ALL;
//
//    //itemlist[item++] = (U16) STR_ID_VS_AVK_VCARD_TEST_ALL ;
//
//    ShowCategory15Screen(
//        STR_ID_VS_AVK_BTHFP,
//        0,
//        STR_GLOBAL_OK,
//        IMG_GLOBAL_OK,
//        STR_GLOBAL_BACK,
//        IMG_GLOBAL_BACK,
//#ifdef BT_RES_ITEM
//        nitems,
//#else                                                           // ver l4
//        item,
//#endif
//        itemlist,
//        (PU16) gIndexIconsImageList,
//        LIST_MENU,
//        sg_vs_bthfp_ctx.idx_hl,
//        NULL);
//
//    SetRightSoftkeyFunction(vs_bthfp_exit_scr, KEY_EVENT_UP);
//    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//
//    return;
//}
//
//static void vs_bthfp_exit_scr(void)
//{}

#ifdef __MMI_HFP_SUPPORT__

static void vs_bthfp_entry_input_addr_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 size = 0;
    U8 *gui_buffer = NULL;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    ret_b = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, 
                                                    AVK_SCR_ID_1, 
                                                    NULL, 
                                                    vs_bthfp_entry_input_addr_scr, 
                                                    MMI_FRM_UNKNOW_SCRN);
    if (!ret_b)
    {
        mmi_vs_bthfp_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[DLA] [F] vs_bthfp_notice_entry AVK_SCR_ID_1");
        return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory5Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMM_INPUT_TYPE_SENTENCE,
        (U8*) sg_vs_bthfp_ctx.szbuf,
        MAX_TXT - 1,
        gui_buffer);

    SetLeftSoftkeyFunction(vs_bthfp_entry_input_addr_done, KEY_EVENT_UP);          
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

static void vs_bthfp_entry_cfm(void* cb, void* ud, U16 StringId)
{
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)cb;
    arg.parent_id = AVK_MAIN_GRP_ID;
    arg.user_tag = (void*)ud;
    mmi_confirm_display((WCHAR *)GetString(StringId), MMI_EVENT_QUERY, &arg);
}

static mmi_ret vs_bthfp_entry_input_cfm_cb(mmi_alert_result_evt_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* wszbuf = (WCHAR*)(evt->user_tag);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                U8 * tmp = NULL;
                //CHAR tmp_str[3] = {0};
                CHAR buf[MAX_TXT] = {0};
                mmi_wcs_to_asc(buf, wszbuf);
                
                tmp = (U8 *)&(sg_vs_bthfp_ctx.ear_addr.lap);
                tmp[0] = vs_str2hex(&buf[10]);
                tmp[1] = vs_str2hex(&buf[8]);
                tmp[2] = vs_str2hex(&buf[6]);
                tmp = (U8 *)&(sg_vs_bthfp_ctx.ear_addr.uap);
                tmp[0] = vs_str2hex(&buf[4]);
                tmp = (U8 *)&(sg_vs_bthfp_ctx.ear_addr.nap);
                tmp[0] = vs_str2hex(&buf[2]);
                tmp[1] = vs_str2hex(&buf[0]);
        

                DS_OUTLOG("vs_bthfp_entry_input_cfm_cb:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                                    ((sg_vs_bthfp_ctx.ear_addr.nap & 0xff00) >> 8),
                                    (sg_vs_bthfp_ctx.ear_addr.nap & 0x00ff),
                                    (sg_vs_bthfp_ctx.ear_addr.uap),
                                    ((sg_vs_bthfp_ctx.ear_addr.lap & 0xff0000) >> 16),
                                    ((sg_vs_bthfp_ctx.ear_addr.lap & 0x00ff00) >> 8),
                                    (sg_vs_bthfp_ctx.ear_addr.lap & 0x0000ff));
                VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_prepare");
                mmi_frm_scrn_close(AVK_MAIN_GRP_ID, AVK_SCR_ID_1);
            }
            break;
        case MMI_ALERT_CNFM_NO:
            {

            }
            break;
        default:
            break;
        }

    }
    return MMI_RET_OK;

}

static void vs_bthfp_entry_input_addr_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    vs_bthfp_entry_cfm((void*)vs_bthfp_entry_input_cfm_cb, sg_vs_bthfp_ctx.szbuf, STR_GLOBAL_SETTINGS);
    //VS_CASE_BTHFP_FINISHED(MMI_TRUE, VS_BTHFP_PREPARE, L"vs_bthfp_prepare");
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
#endif

static mmi_ret vs_bthfp_entry_voice_cfm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR* wszbuf = evt->user_tag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
            
                VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_do");                
                //mmi_frm_scrn_close(GRP_ID_VS_AVK_BTHFP, SCR_ID_VS_AVK_HEARD_QUERY);
            
            }
            break;
        case MMI_ALERT_CNFM_NO:
            {
                VS_CASE_BTHFP_FINISHED(MMI_FALSE, 0, L"vs_bthfp_do");                
            }
            break;
        default:
            break;
        }

    }
    return MMI_RET_OK;

}


static S32 vs_bthfp_evt_cb(BTHFHandle srv_hd, U32 evt, U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_bthfp_evt_cb S");
    DS_OUTLOG("vs_bthfp_evt_cb sts [%d], evt [0x%x]", srv_bthf_get_status(), evt);
    switch (evt)
    {
    case BTHF_EV_ENABLE:
    case BTHF_EV_DISABLE:
        break;

    case BTHF_EV_REQ_ATTACH:
        //mmi_hfg_auth_ind_hdlr(para);
        vs_bthfp_remote_attached_req_cb(para);
        break;

    case BTHF_EV_REQ_ABORT:
        //mmi_hfg_auth_aborted(para);
        {
            DS_OUTLOG("BTHF_EV_REQ_ABORT");
            VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_abt");
        }
        break;

    case BTHF_EV_ATTACH:
        //mmi_hfg_attach_hdlr(para);
        vs_bthfp_attached_cb(para);
        break;

    case BTHF_EV_DETACH:
        //mmi_hfg_detach_hdlr(para);
        vs_bthfp_detached_cb(para);
        break;

    case BTHF_EV_AUDIO_ON:
        {           
            DS_OUTLOG("BTHF_EV_AUDIO_ON");
            srv_bthf_change_volume(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id, 12);
            VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_start");
        }break;
    case BTHF_EV_AUDIO_OFF:
        DS_OUTLOG("BTHF_EV_AUDIO_OFF");
        break;
        
    case BTHF_EV_VOL_CHANGE:
        //mmi_hfg_vol_change_hdlr((para >> 16 & 0xFFFF));
        vs_bthfp_vol_changed_cb((para >> 16 & 0xFFFF));
        break;

    case BTHF_EV_REQ_RESULT:
        //mmi_hfg_req_result_hdlr(para);
        {
            DS_OUTLOG("BTHF_EV_REQ_RESULT param[0x%x]", para);
            
            if ((para >> 16 & 0xFFFF) != BTHF_E_NONE)
            {
                DS_OUTLOG("BTHF_EV_REQ_RESULT NOT BTHF_E_NONE");
                if ((para >> 16 & 0xFFFF) == BTHF_E_USER_ABORT)
                {
                    DS_OUTLOG("BTHF_EV_REQ_RESULT BTHF_E_USER_ABORT");
                    VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_abt");
                }
            }
            else
            {
                if ((para & 0xFFFF) == BTHF_REQ_DETACH)
                {
                    DS_OUTLOG("BTHF_EV_REQ_RESULT BTHF_REQ_DETACH");
                    VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_finish");
                }
                else if ((para & 0xFFFF) == BTHF_REQ_ATTACH)
                {
                    DS_OUTLOG("BTHF_EV_REQ_RESULT BTHF_REQ_ATTACH");
                }
                else if ((para & 0xFFFF) == BTHF_REQ_AUDIO_OFF)
                {
                    DS_OUTLOG("BTHF_EV_REQ_RESULT BTHF_REQ_AUDIO_OFF");
                }
            }
              

        }
        break;
    }

    
    DS_OUTLOG("vs_bthfp_evt_cb E");
    return 0;
}

static S32 vs_bthfp_attached_cb(U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bthf_dev_info_struct info;
    U32 dev_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_bthfp_attached_cb S");
    
    DS_OUTLOG("srv_bthf_list_device S");
    srv_bthf_list_device(&dev_id, 1);
    DS_OUTLOG("dev_id [%d]", dev_id);
    DS_OUTLOG("srv_bthf_list_device E");
    DS_OUTLOG("srv_bthf_get_device_info S");
    srv_bthf_get_device_info(dev_id, &info);
    DS_OUTLOG("srv_bthf_get_device_info E");
    DS_OUTLOG("vs_bthfp_attached_cb:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                    ((info.addr.nap & 0xff00) >> 8),
                    (info.addr.nap & 0x00ff),
                    (info.addr.uap),
                    ((info.addr.lap & 0xff0000) >> 16),
                    ((info.addr.lap & 0x00ff00) >> 8),
                    (info.addr.lap & 0x0000ff));
#ifdef __BT_MANUAL_AUDIO_SWITCH__

    DS_OUTLOG("srv_bthf_audio_on S");
    srv_bthf_audio_on(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id);
    DS_OUTLOG("srv_bthf_audio_on E");
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_bthf_audio_on);
#endif
    DS_OUTLOG("vs_bthfp_attached_cb E");
    VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_start");

    return 0;
}

static S32 vs_bthfp_detached_cb(U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mode = BTHF_AUD_LOCAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_bthfp_detached_cb S");
    srv_bthf_config(sg_vs_bthfp_ctx.srv_hd, BTHF_CFG_AUDIO_PATH, (void*)&mode);
    srv_bthf_close(sg_vs_bthfp_ctx.srv_hd);
    sg_vs_bthfp_ctx.srv_hd = NULL;

    
    VS_CASE_BTHFP_FINISHED(MMI_TRUE, 0, L"vs_bthfp_finish");
    
    DS_OUTLOG("vs_bthfp_detached_cb E");
    return 0;
}

static S32 vs_bthfp_vol_changed_cb(U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 n = 6;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_bthfp_vol_changed_cb S");
    
    if (6 == n)
        n = 12;
    else
        n = 6;
    //DS_OUTLOG("vs_bthfp_vol_changed_cb vol [%d]", n);
    //srv_bthf_change_volume(sg_vs_bthfp_ctx.srv_hd, sg_vs_bthfp_ctx.dev_id, n);
    DS_OUTLOG("vs_bthfp_vol_changed_cb E");
    return 0;
}

static S32 vs_bthfp_remote_attached_req_cb(U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //static U8 n = 6;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DS_OUTLOG("vs_bthfp_vol_changed_cb S");
    
    srv_bthf_accept(sg_vs_bthfp_ctx.srv_hd, para);
    
    DS_OUTLOG("vs_bthfp_vol_changed_cb E");

    return 0;
}

#endif /* __MMI_HFP_SUPPORT__ */


#endif /* __MAUI_SDK_TEST__ */

