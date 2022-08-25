#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

//#include "tst_btopp.h"
//#include "tst_btds.h"
#include "avk_conn_btopp.h"
#include "avk_conn_btds.h"
#include "MMI_include.h"
#include "OppSrvGprot.h"
//#include "tst_sdk_framework.h"
#include "CommonScreens.h"
#include "GlobalResDef.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "CustMenuRes.h"
#include "CommonScreensResDef.h"
#include "app_mem.h"
#include "mmi_frm_history_gprot.h"

#ifdef __COSMOS_MMI_PACKAGE__
//#include "mmi_rp_vapp_bt_main_def.h"
//#include "vapp_bt_opp.h"
#else
//#include "BTMMIOppGprots.h"
#endif

#define VS_OPP_SRC_FILE L"vs_src_btopp.txt"
#define VS_OPP_DES_FILE L"vs_des_btopp.txt"
#define VS_OPP_SND_BUF_SIZE 1024 //OPPC_MAX_OBEX_PACKET_LENGTH
#define VS_OPP_NAME_SIZE 32

#define VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTOPP_EX(a, b, c) \
    AVK_CASE_RESULT(AVK_PASS); \
     AVK_ASYN_DONE();
    //VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_EX(a, b, c, GRP_ID_VS_AVK_BTOPP)



typedef struct
{
    S32 idx_hl;
    MMI_ID group_id;
    WCHAR szbuf[MAX_TXT];
#ifdef __MMI_OPP_SUPPORT__
    S32 srv_hd;
    S32 clt_hd;
    void * snd_buf;
    srv_bt_cm_bt_addr des_dev_addr;
    U16 path_src_wsz[OPP_MAX_OBJ_NAME_LENGTH];
    U16 path_des_wsz[OPP_MAX_OBJ_NAME_LENGTH];
    MMI_BOOL start_ok_b;
#endif    
}vs_btopp_ctx;

static vs_btopp_ctx sg_vs_btopp_ctx;

AVK_ADD_ITEM(AVK_CONN_BTOPP_MANUAL_N, L"Manual cases", AVK_CONN_BTOPP);
//AVK_ADD_ITEM(AVK_CONN_BTOPP_MANUAL_E, L"Manual cases Exp", AVK_CONN_BTOPP);

static void VS_CASE_BTOPP_FINISHED(MMI_BOOL ret_b, vs_test_item_enum ti_e, const void * words)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 wszTxt[128] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    AVK_CASE_RESULT((0 != ret_b) ? AVK_PASS : AVK_FAIL);
    AVK_ASYN_DONE();
    /*
    vs_tfw_trace_result((U16*)words, ret_b, 0, VS_TA_BTOPP);
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

static void mmi_vs_btopp_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
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


static mmi_ret vs_btopp_main_group_proc(mmi_event_struct *param);
static mmi_ret vs_btopp_menu_cui_proc(mmi_event_struct * param);
static void vs_btopp_notice_entry(void);

static void vs_btopp_option_highlight_hdlr(S32 index);
static  void vs_btopp_entry_scr_int(void);
static void vs_btopp_exit_scr(void);
#ifdef __MMI_OPP_SUPPORT__
static void vs_btopp_entry_input_addr_scr(void);
static void vs_btopp_entry_cfm(void* cb, void* ud, U16 StringId);
static mmi_ret vs_btopp_entry_input_cfm_cb(mmi_alert_result_evt_struct *evt);
static void vs_btopp_entry_input_addr_done(void);


static S32 vs_btopp_prepare_data(void);
static void vs_btoppc_send_finish(void);

static S32 vs_btopp_srv_event_cb(S32 srv_hd, U32 event_id, void *para);
static void vs_btopps_authorize_ind_cb(void *para);
static void vs_btopps_recv_ind_cb(void *para);
static void vs_btopps_disconn_ind_cb(void *para);

static S32 vs_btopp_clt_event_cb(S32 srv_hd, U32 event_id, void *para);
static void vs_btoppc_connect_ind_cb(void *para);
static void vs_btoppc_send_ind_cb(void *para);
static void vs_btoppc_disconn_ind_cb(void * para);
#endif /*__MMI_OPP_SUPPORT__ */

static void vs_btopp_leftkey_handler_cb(void)
{
    vs_btopp_prepare();
}

AVK_MANUAL_CASE(AVK_CONN_BTOPP_MANUAL_PREPARE_N, AVK_CONN_BTOPP_MANUAL_N)
{

    CHAR buf[] = {"1. Get the device address of destination device anyway. \n\
    2. In 'prepare' menu item, you may type the address you have gotten. \n\
    3. Make sure bluetooth is switch on and destination was paired. \n\
    4. To press the case in order. \n\
    5. Press 'OK' to begin"};

    static WCHAR wbuf[512];

    mmi_asc_to_wcs(wbuf, buf);

    AVK_MANU_SHOW_TIPS(wbuf, vs_btopp_leftkey_handler_cb);
}

AVK_MANUAL_CASE(AVK_CONN_BTOPP_MANUAL_START_N, AVK_CONN_BTOPP_MANUAL_PREPARE_N)
{
    vs_btopp_start();
}

AVK_MANUAL_CASE(AVK_CONN_BTOPP_MANUAL_FINISH_N, AVK_CONN_BTOPP_MANUAL_PREPARE_N)
{
    vs_btopp_finish();
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
#endif

extern "C" void vapp_opp_deinit(void *param);
extern "C" void mmi_bt_opp_deinit(void);
extern "C" kal_bool mmi_usb_is_in_mass_storage_mode(void);

void vs_btopp_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;
    //MMI_BOOL ret_b = MMI_FALSE;
    S32 ret_n = -4;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OPP_SUPPORT__
    DS_OUTLOG("vs_btopp_prepare S");

//#ifndef WIN32 
#ifdef __COSMOS_MMI_PACKAGE__
            DS_OUTLOG("vapp_opp_deinit S");
            {
            
            vapp_opp_deinit(0);
            }
            DS_OUTLOG("vapp_opp_deinit E");
#else
            DS_OUTLOG("mmi_bt_opp_deinit S");
            {
            
            mmi_bt_opp_deinit();
            }
            DS_OUTLOG("mmi_bt_opp_deinit E");
#endif
//#endif   
    

    if (0 != sg_vs_btopp_ctx.srv_hd)
    {
        if (SRV_OPP_RESULT_INVALID_HANDLE != sg_vs_btopp_ctx.srv_hd)
        {            
            DisplayPopup((PU8)L"vs_btopp_prepare srv_clt already", IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        else
        {
            DisplayPopup((PU8)L"vs_btopp_prepare srv_clt failure", IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        return;
    }

    if (0 != sg_vs_btopp_ctx.clt_hd)
    {
        if (SRV_OPP_RESULT_INVALID_HANDLE != sg_vs_btopp_ctx.clt_hd)
        {            
            DisplayPopup((PU8)L"vs_btopp_prepare clt_hd already", IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        else
        {
            DisplayPopup((PU8)L"vs_btopp_prepare clt_hd failure", IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        return;
    }
    
    sg_vs_btopp_ctx.srv_hd = srv_opp_open((U8)SRV_OPP_ROLE_SERVER);
    if (SRV_OPP_RESULT_INVALID_HANDLE == sg_vs_btopp_ctx.srv_hd)
    {
        DS_OUTLOG("srv_opp_open SRV_OPP_ROLE_SERVER F");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_prepare");
        return;
    }
    event_mask = SRV_OPP_EVENT_START |
        SRV_OPP_EVENT_STOP |
        SRV_OPP_EVENT_AUTHORIZE_NOTIFY |
        SRV_OPP_EVENT_CONN_NOTIFY | SRV_OPP_EVENT_DISCONN_NOTIFY | SRV_OPP_EVENT_RECV_NOTIFY;
    if (SRV_OPP_RESULT_OK != srv_opp_set_notify(sg_vs_btopp_ctx.srv_hd, event_mask, (bt_notify) vs_btopp_srv_event_cb))
    {
        DS_OUTLOG("srv_opp_set_notify srv F");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_prepare");
        return;
    }
    
    sg_vs_btopp_ctx.clt_hd = srv_opp_open((U8)SRV_OPP_ROLE_CLIENT);
    if (SRV_OPP_RESULT_INVALID_HANDLE == sg_vs_btopp_ctx.clt_hd)
    {
        DS_OUTLOG("srv_opp_open SRV_OPP_ROLE_CLIENT F");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_prepare");
        return;
    }
    event_mask = SRV_OPP_EVENT_CONN_NOTIFY | SRV_OPP_EVENT_SND_NOTIFY | SRV_OPP_EVENT_DISCONN_NOTIFY;
    if (SRV_OPP_RESULT_OK != srv_opp_set_notify(sg_vs_btopp_ctx.clt_hd, event_mask, (bt_notify) vs_btopp_clt_event_cb))
    {
        DS_OUTLOG("srv_opp_set_notify clt F");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_prepare");
        return;
    }

    
    ret_n = vs_btopp_prepare_data();
    if (0 != ret_n)
    {
        DS_OUTLOG("vs_btopp_prepare_data ret_n [%d]", ret_n);
        return;
    }

    sg_vs_btopp_ctx.des_dev_addr.nap |= 0x0123;
    sg_vs_btopp_ctx.des_dev_addr.uap |= 0x45;
    sg_vs_btopp_ctx.des_dev_addr.lap |= 0X6789ab;
    
    DS_OUTLOG("vs_btopp_prepare:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                        ((sg_vs_btopp_ctx.des_dev_addr.nap & 0xff00) >> 8),
                        (sg_vs_btopp_ctx.des_dev_addr.nap & 0x00ff),
                        (sg_vs_btopp_ctx.des_dev_addr.uap),
                        ((sg_vs_btopp_ctx.des_dev_addr.lap & 0xff0000) >> 16),
                        ((sg_vs_btopp_ctx.des_dev_addr.lap & 0x00ff00) >> 8),
                        (sg_vs_btopp_ctx.des_dev_addr.lap & 0x0000ff));
                        
    //VS_CASE_BTOPP_FINISHED(MMI_TRUE, VS_BTOPP_PREPARE, L"vs_btopp_prepare");

    vs_btopp_entry_input_addr_scr();

    DS_OUTLOG("vs_btopp_prepare E");

#else
    
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTOPP_EX(L"vs_btopp_prepare",VS_TA_BTOPP, 0);
    
#endif

}
void vs_btopp_start(void)
{
#ifdef __MMI_OPP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_n = -1;
    //U16 * obj_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    DS_OUTLOG("vs_btopp_start S");
    sg_vs_btopp_ctx.snd_buf = get_ctrl_buffer(VS_OPP_SND_BUF_SIZE);
    if (NULL == sg_vs_btopp_ctx.snd_buf)
    {
        DisplayPopup((PU8)L"adm buf failure.", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        return;
    }
    
    ret_n = srv_oppc_send_begin(sg_vs_btopp_ctx.clt_hd, &(sg_vs_btopp_ctx.des_dev_addr), (U8*)sg_vs_btopp_ctx.snd_buf, VS_OPP_SND_BUF_SIZE);
    if (SRV_OPP_RESULT_STATE_BUSY == ret_n)
    {
        free_ctrl_buffer(sg_vs_btopp_ctx.snd_buf);
        sg_vs_btopp_ctx.snd_buf = NULL;
        DisplayPopup((PU8)L"busy", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        AVK_CASE_RESULT(AVK_PASS);
        AVK_ASYN_DONE();
        return;
    }
    
    if (SRV_OPP_RESULT_OK != ret_n)
    {
        DS_OUTLOG("srv_oppc_send_begin ret [%d]", ret_n);
        free_ctrl_buffer(sg_vs_btopp_ctx.snd_buf);
        sg_vs_btopp_ctx.snd_buf = NULL;
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_start");
        return;
    }

    
    
    DS_OUTLOG("vs_btopp_start E");
    
    
#else
        
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTOPP_EX(L"vs_btopp_start",VS_TA_BTOPP, 0);
        
#endif
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

void vs_btopp_abt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OPP_SUPPORT__
    DS_OUTLOG("vs_btopp_abt S");
    if (srv_opps_is_accepted())
    {
        DS_OUTLOG("srv_opps_is_accepted TRUE");
        if (SRV_OPP_RESULT_OK != srv_opps_disconn_client(sg_vs_btopp_ctx.srv_hd))
        {
            DS_OUTLOG("vs_btopp_abt S");
            VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_abt");
        }
    }
    else
    {
        DisplayPopup((PU8)L"not accepted!", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
    }
    DS_OUTLOG("vs_btopp_abt E");

    // TODO:
    VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_abt");
    
#else
        
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTOPP_EX(L"vs_btopp_abt",VS_TA_BTOPP, 0);
        
#endif

}

void vs_btopp_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OPP_SUPPORT__
    DS_OUTLOG("srv_oppc_send_end S");

    srv_oppc_is_idle();
    srv_oppc_is_sending();
    srv_oppc_is_aborting();
    srv_oppc_is_disconncting();
    srv_opps_is_idle();
    srv_opps_is_receiving();
    
    if (sg_vs_btopp_ctx.start_ok_b)
    {
        if (SRV_OPP_RESULT_OK != srv_oppc_send_end(sg_vs_btopp_ctx.clt_hd))
        {
            DS_OUTLOG("srv_oppc_send_end F");
        }
        sg_vs_btopp_ctx.start_ok_b = MMI_FALSE;
    }
    else
    {
        DS_OUTLOG("vs_btopp_finish start_ok_b [FALSE] ");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_finish");
    }
    

    VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_finish");
    if (sg_vs_btopp_ctx.srv_hd)
    {
        srv_opp_close(sg_vs_btopp_ctx.srv_hd);
        sg_vs_btopp_ctx.srv_hd = NULL;
    }
    if (sg_vs_btopp_ctx.clt_hd)
    {
        srv_opp_close(sg_vs_btopp_ctx.clt_hd);
        sg_vs_btopp_ctx.clt_hd = NULL;
    }
    DS_OUTLOG("srv_oppc_send_end E");
#else
        
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTOPP_EX(L"vs_btopp_finish",VS_TA_BTOPP, 0);
        
#endif

}
//void vs_btopp_test_all(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U16 id;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    
//    DS_OUTLOG("vs_btopp_test_all S");
//
//    vs_tfw_set_both_auto_and_manual();
//    id = GetActiveScreenId();
//
//    vs_tfw_test_all_reset();
//    vs_tfw_test_all_screen_id(id);
//    vs_tfw_ta_scope(VS_TA_BT0, VS_TA_TOTAL);
//    vs_tfw_find_beginning(VS_TA_BTOPP);
//
//    DS_OUTLOG("vs_btopp_test_all E");
//}

///*****************************************************************************
// * FUNCTION
// *  vs_btopp_main_group_proc
// * DESCRIPTION
// *  This function is BT CM Main screen group proc function
// *  It will handle all event on the screen group
// * PARAMETERS
// *  param       [IN]        MMI event structure
// * RETURNS
// *  mmi_ret
// *****************************************************************************/
//mmi_ret vs_btopp_main_group_proc(mmi_event_struct *param)
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
//            vs_btopp_menu_cui_proc(param);
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
//static mmi_ret vs_btopp_menu_cui_proc(mmi_event_struct * param)
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
//static void vs_btopp_notice_entry(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U16 tmp_buf_wsz[] = {L"1. Get the address of des dev anyway. \n\
//    2. In 'prepare' menu item, you may type the address you have gotten. \n\
//    3. Make sure bluetooth is swith on and destination was paired. \n\
//    4. To press the case in order. \n\
//    5. Press 'OK' to begin"};
//    S32 size = 0;
//    U8 *gui_buffer = NULL;
//    MMI_BOOL ret_b = MMI_FALSE;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/    
//    ret_b = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTOPP, 
//                                                    SCR_ID_VS_AVK_BTOPP_NOTICE, 
//                                                    NULL, 
//                                                    vs_btopp_notice_entry, 
//                                                    MMI_FRM_UNKNOW_SCRN);
//    if (!ret_b)
//    {
//        mmi_vs_btopp_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
//        DS_OUTLOG("[DLA] [F] vs_btopp_notice_entry SCR_ID_VS_AVK_BTOPP_NOTICE");
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
//    SetLeftSoftkeyFunction(vs_btopp_entry_scr_int, KEY_EVENT_UP);          
//    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
//
//}
//
//
//static void vs_btopp_option_highlight_hdlr(S32 index)
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
//    case VS_BTOPP_ITEM_PREPARE:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_prepare, KEY_EVENT_UP);
//        }break;
//    case VS_BTOPP_ITEM_START:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_start, KEY_EVENT_UP);
//        }break;
//    #if 0
//    case VS_BTOPP_ITEM_ABT:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_abt, KEY_EVENT_UP);
//        }break;
//    #endif
//    #if 0
//    case VS_BTOPP_ITEM_DO:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_do, KEY_EVENT_UP);
//        }break;
//    #endif
//    case VS_BTOPP_ITEM_FINISH:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_finish, KEY_EVENT_UP);
//        }break;
//    case VS_BTOPP_ITEM_TEST_ALL:
//        {
//            SetLeftSoftkeyFunction(vs_btopp_test_all, KEY_EVENT_UP);
//        }break;
//    default:
//        {
//            ASSERT(0);
//        }break;
//    }
//
//    sg_vs_btopp_ctx.idx_hl = index;
//}
//
//void vs_btopp_entry_scr(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    DS_OUTLOG("vs_btcm_entry_scr S");
//
//    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VS_AVK_BTOPP, vs_btopp_main_group_proc, NULL);
//    sg_vs_btopp_ctx.group_id = GRP_ID_VS_AVK_BTOPP;
//    mmi_frm_group_enter(sg_vs_btopp_ctx.group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//
//    vs_btopp_notice_entry();
//
//
//    DS_OUTLOG("vs_btcm_entry_scr E");
//}
//
//static  void vs_btopp_entry_scr_int(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//#ifdef BT_RES_ITEM
//    U16 nitems = 0;
//#endif
//    U16 itemlist[VS_BTOPP_OPTOIN_SIZE] = {0};
//    int item = 0;
//    MMI_BOOL ret = MMI_FALSE;
//    //MMI_ID group_id = 0;
//    //MMI_ID scrn_id = 0;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    
//    //mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
//    //if (SCR_ID_VS_AVK_BTOPP_NOTICE == scrn_id)
//    //    mmi_frm_scrn_close(GRP_ID_VS_AVK_BTOPP, SCR_ID_VS_AVK_BTOPP_NOTICE);
//
//    ret = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTOPP, SCR_ID_VS_AVK_BTOPP, NULL, vs_btopp_entry_scr_int, MMI_FRM_FULL_SCRN);
//
//    if(ret == MMI_FALSE)
//        return;
//
//    RegisterHighlightHandler(vs_btopp_option_highlight_hdlr);
//#ifdef BT_RES_ITEM
//    nitems = GetNumOfChild_Ext(MENU_ID_VS_AVK_BTOPP);
//#else
//
//#endif
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_PREPARE;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_START;
//    //itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_DO;
//    //itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_ABT;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_FINISH;
//    
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTOPP_TEST_ALL;
//
//    //itemlist[item++] = (U16) STR_ID_VS_AVK_VCARD_TEST_ALL ;
//
//    ShowCategory15Screen(
//        STR_ID_VS_AVK_BTOPP,
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
//        sg_vs_btopp_ctx.idx_hl,
//        NULL);
//
//    SetRightSoftkeyFunction(vs_btopp_exit_scr, KEY_EVENT_UP);
//    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//
//
//    return;
//}
//
//static void vs_btopp_exit_scr(void)
//{}

#ifdef __MMI_OPP_SUPPORT__

static void vs_btopp_entry_input_addr_scr(void)
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
                                                    vs_btopp_entry_input_addr_scr, 
                                                    MMI_FRM_UNKNOW_SCRN);
    if (!ret_b)
    {
        mmi_vs_btopp_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[DLA] [F] vs_btopp_entry_input_addr_scr SCR_ID_VS_AVK_BTOPP_INPUT_ADDR");
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
        (U8*) sg_vs_btopp_ctx.szbuf,
        MAX_TXT - 1,
        gui_buffer);

    SetLeftSoftkeyFunction(vs_btopp_entry_input_addr_done, KEY_EVENT_UP);          
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

static void vs_btopp_entry_cfm(void* cb, void* ud, U16 StringId)
{
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)cb;
    arg.parent_id = AVK_MAIN_GRP_ID;
    arg.user_tag = (void*)ud;
    mmi_confirm_display((WCHAR *)GetString(StringId), MMI_EVENT_QUERY, &arg);
}

static mmi_ret vs_btopp_entry_input_cfm_cb(mmi_alert_result_evt_struct *evt)
{
#ifdef __MMI_OPP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* wszbuf = (WCHAR*)evt->user_tag;
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
                
                tmp = (U8 *)&(sg_vs_btopp_ctx.des_dev_addr.lap);
                tmp[0] = vs_str2hex(&buf[10]);
                tmp[1] = vs_str2hex(&buf[8]);
                tmp[2] = vs_str2hex(&buf[6]);
                tmp = (U8 *)&(sg_vs_btopp_ctx.des_dev_addr.uap);
                tmp[0] = vs_str2hex(&buf[4]);
                tmp = (U8 *)&(sg_vs_btopp_ctx.des_dev_addr.nap);
                tmp[0] = vs_str2hex(&buf[2]);
                tmp[1] = vs_str2hex(&buf[0]);
        

                DS_OUTLOG("vs_btopp_entry_input_cfm_cb:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                                    ((sg_vs_btopp_ctx.des_dev_addr.nap & 0xff00) >> 8),
                                    (sg_vs_btopp_ctx.des_dev_addr.nap & 0x00ff),
                                    (sg_vs_btopp_ctx.des_dev_addr.uap),
                                    ((sg_vs_btopp_ctx.des_dev_addr.lap & 0xff0000) >> 16),
                                    ((sg_vs_btopp_ctx.des_dev_addr.lap & 0x00ff00) >> 8),
                                    (sg_vs_btopp_ctx.des_dev_addr.lap & 0x0000ff));
                VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_prepare");
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
#endif /* __MMI_OPP_SUPPORT__ */
    return MMI_RET_OK;

}

static void vs_btopp_entry_input_addr_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    vs_btopp_entry_cfm((void*)vs_btopp_entry_input_cfm_cb, sg_vs_btopp_ctx.szbuf, STR_GLOBAL_SETTINGS);
    //VS_CASE_BTOPP_FINISHED(MMI_TRUE, VS_BTOPP_PREPARE, L"vs_btopp_prepare");
}


static S32 vs_btopp_prepare_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[DS_BUF_SIZE] = {"this is file of VS AVK BTOPP"};
    DS_U16 wszBuf[DS_BUF_SIZE] = {0};
    FS_HANDLE file_hdl = -1;
    DS_S32 drv = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    mmi_asc_n_to_wcs(wszBuf, buf, DS_BUF_SIZE);

    file_hdl = vs_bt_ds_fileopen((DS_U16*)VS_OPP_SRC_FILE);
    if (-1 == file_hdl)
    {
        return -1;
    }

    if (!vs_bt_ds_filewrite(file_hdl, wszBuf, 2*kal_wstrlen(wszBuf) + 2))
    {
        return -2;
    }

    if (0 > vs_bt_ds_fileclose(file_hdl))
    {
        return -3;
    }

    
    drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);

    if (FS_NO_ERROR > drv)
    {
        return -4;
    }
    //kal_wsprintf(sg_vs_btopp_ctx.path_src_wsz, "%c:\\%s%s", drv, LOG_FOLDER, VS_OPP_SRC_FILE);
    kal_wsprintf(sg_vs_btopp_ctx.path_src_wsz, "%c:\\", drv);
    mmi_wcscat(&sg_vs_btopp_ctx.path_src_wsz[mmi_wcslen(sg_vs_btopp_ctx.path_src_wsz)], (WCHAR*)LOG_FOLDER);
    mmi_wcscat(&sg_vs_btopp_ctx.path_src_wsz[mmi_wcslen(sg_vs_btopp_ctx.path_src_wsz)], (WCHAR*)VS_OPP_SRC_FILE);
    //kal_wsprintf(sg_vs_btopp_ctx.path_des_wsz, "%c:\\%s%s", drv, LOG_FOLDER, VS_OPP_DES_FILE);
    kal_wsprintf(sg_vs_btopp_ctx.path_des_wsz, "%c:\\", drv);
    mmi_wcscat(&sg_vs_btopp_ctx.path_des_wsz[mmi_wcslen(sg_vs_btopp_ctx.path_des_wsz)], (WCHAR*)LOG_FOLDER);
    mmi_wcscat(&sg_vs_btopp_ctx.path_des_wsz[mmi_wcslen(sg_vs_btopp_ctx.path_des_wsz)], (WCHAR*)VS_OPP_DES_FILE);

    return 0;

}

/*****************************************************************************
 * FUNCTION
 *  vs_btoppc_send_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//#include "BTMMIOppGprots.h"
static void vs_btoppc_send_finish()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    mmi_oppc_free_buffer(mmi_oppc_p->buffer);
    mmi_oppc_p->buffer = NULL;

#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif 
    srv_opp_close(mmi_oppc_p->srv_hd);

    mmi_oppc_p->srv_hd = 0;
    */
    //mmi_bt_close();


    DS_OUTLOG("vs_btoppc_send_finish S");

    if (sg_vs_btopp_ctx.snd_buf)
    {
        free_ctrl_buffer(sg_vs_btopp_ctx.snd_buf);
        sg_vs_btopp_ctx.snd_buf = NULL;
        DS_OUTLOG("free_ctrl_buffer");
    }

    //DS_OUTLOG("mmi_opp_get_path [%s]", mmi_opp_get_path());
    DS_OUTLOG("vs_btoppc_send_finish E");

}


/*****************************************************************************
 * FUNCTION
 *  vs_btopp_event_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_id        [IN]        
 *  para            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 vs_btopp_srv_event_cb(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btopp_srv_event_cb S");
    if (srv_hd <= 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    DS_OUTLOG("vs_btopp_srv_event_cb [0x%x]", event_id);
    if (srv_hd == sg_vs_btopp_ctx.srv_hd)
    {
        switch (event_id)
        {
            case SRV_OPP_EVENT_START:
                {
                    DS_OUTLOG("srv_opps_is_active() ret [%d]", srv_opps_is_active());
                }
                break;

            case SRV_OPP_EVENT_STOP:
                {
                    DS_OUTLOG("srv_opps_is_active() ret [%d]", srv_opps_is_active());
                }
                break;

            case SRV_OPP_EVENT_AUTHORIZE_NOTIFY:
                //mmi_opps_authorize_ind_handle(para);
                {
                    vs_btopps_authorize_ind_cb(para);
                }
                break;

            case SRV_OPP_EVENT_CONN_NOTIFY:
                break;

            case SRV_OPP_EVENT_RECV_NOTIFY:
                //mmi_opps_recv_ind_handle(para);
                vs_btopps_recv_ind_cb(para);
                break;

            case SRV_OPP_EVENT_DISCONN_NOTIFY:
                //mmi_opps_disconn_ind_handle(para);
                {
                    vs_btopps_disconn_ind_cb(para);
                    srv_opp_close_temp_obj();
                    
                    if (SRV_OPP_RESULT_OK != srv_opp_close(sg_vs_btopp_ctx.srv_hd))
                    {
                        DS_OUTLOG("srv_opp_close F");
                        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_finish");
                        return SRV_OPP_RESULT_INVALID_HANDLE;
                    }
                    sg_vs_btopp_ctx.srv_hd = NULL;
                    
                    VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_abt");

                    
                }
                break;

            default:
                return SRV_OPP_RESULT_INVALID_PARAM;
        }
        DS_OUTLOG("vs_btopp_srv_event_cb E");

        return SRV_OPP_RESULT_OK;
    }
    return SRV_OPP_RESULT_INVALID_HANDLE;
}

static void vs_btopps_authorize_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_opp_authorize_notify_struct *auth_notify = (srv_opp_authorize_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btopps_authorize_ind_cb S");
    #if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    {
    
    if (mmi_usb_is_in_mass_storage_mode())
    {
        srv_opps_reject(sg_vs_btopp_ctx.srv_hd);
        DisplayPopup((PU8)L"in usb mode [srv_opps_reject]", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        return;
    }
    }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

    {
        CHAR szTst[128] = {0};
        mmi_wcs_to_asc(szTst, sg_vs_btopp_ctx.path_des_wsz);
        DS_OUTLOG("srv_opps_accept [%s]", szTst);
    }
    if (SRV_OPP_RESULT_OK != srv_opps_accept(sg_vs_btopp_ctx.srv_hd, (U16*) sg_vs_btopp_ctx.path_des_wsz))
    {
        DisplayPopup((PU8)L"srv_opps_accept F", IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
    }
    
    DS_OUTLOG("vs_btopps_authorize_ind_cb E");
}



/*****************************************************************************
 * FUNCTION
 *  vs_btopps_recv_ind_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_btopps_recv_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_recv_notify_struct *recv_notify = (srv_opp_recv_notify_struct*) para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btopps_recv_ind_cb S");
    DS_OUTLOG("vs_btopps_recv_ind_cb type [%d]", recv_notify->type);
    switch (recv_notify->type)
    {
        case SRV_OPP_RECV_READY:
            {   
            }
            break;
            
        case SRV_OPP_RECV_BEGIN:
            {}break;
        case SRV_OPP_RECV_SUCCESS:
            {}
            break;

        case SRV_OPP_RECV_FAIL:
            break;
        default:
            break;
    }
    DS_OUTLOG("vs_btopps_recv_ind_cb E");

}


/*****************************************************************************
 * FUNCTION
 *  vs_btopps_disconn_ind_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_btopps_disconn_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_opp_disconn_notify_struct *disconn_notify = (srv_opp_disconn_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_event_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_id        [IN]        
 *  para            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 vs_btopp_clt_event_cb(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btopp_clt_event_cb S");
    if (srv_hd <= 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;
    DS_OUTLOG("vs_btopp_clt_event_cb [0x%x]", event_id);

    if (srv_hd == sg_vs_btopp_ctx.clt_hd)
    {
        switch (event_id)
        {
            case SRV_OPP_EVENT_CONN_NOTIFY:
                vs_btoppc_connect_ind_cb(para);
                break;

            case SRV_OPP_EVENT_SND_NOTIFY:
                vs_btoppc_send_ind_cb(para);
                break;

            case SRV_OPP_EVENT_DISCONN_NOTIFY:
                vs_btoppc_disconn_ind_cb(para);
                
                if (SRV_OPP_RESULT_OK != srv_opp_close(sg_vs_btopp_ctx.clt_hd))
                {
                    DS_OUTLOG("srv_opp_close F");
                    VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_finish");
                    return SRV_OPP_RESULT_INVALID_HANDLE;
                }
                sg_vs_btopp_ctx.clt_hd = NULL;
                
                VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_finish");
                break;

            default:
                return SRV_OPP_RESULT_INVALID_PARAM;
        }
        DS_OUTLOG("vs_btopp_clt_event_cb E");
        return SRV_OPP_RESULT_OK;
    }

    return SRV_OPP_RESULT_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  vs_btoppc_send_ind_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_btoppc_send_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_snd_notify_struct *snd_result = (srv_opp_snd_notify_struct*) para;
    S32 ret_n = 0;
    U16 * obj_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DS_OUTLOG("vs_btoppc_send_ind_cb S");
    
    DS_OUTLOG("vs_btoppc_send_ind_cb type [%d]", snd_result->type);
    
    switch (snd_result->type)
    {    
        case SRV_OPP_SND_READY:
            {                
                obj_name = (U16*)get_ctrl_buffer(OPP_MAX_OBJ_NAME_LENGTH);
                mmi_wcscpy(obj_name, (WCHAR*)VS_OPP_DES_FILE);
                DS_OUTLOG("srv_oppc_send_obj S");
                {
                CHAR szTst[128] = {0};
                mmi_wcs_to_asc(szTst, sg_vs_btopp_ctx.path_src_wsz);
                DS_OUTLOG("srv_oppc_send_obj [%s]", szTst);
                }
                if (SRV_OPP_RESULT_OK != (ret_n = srv_oppc_send_obj(sg_vs_btopp_ctx.clt_hd, sg_vs_btopp_ctx.path_src_wsz, obj_name)))
                {
                    DS_OUTLOG("srv_oppc_send_obj ret [%d]", ret_n);
                }
                DS_OUTLOG("srv_oppc_send_obj E");
                free_ctrl_buffer(obj_name);
            }
            break;

        case SRV_OPP_SND_SUCC:
            {
                srv_opp_obj_info_struct obj_info;
                srv_oppc_get_obj_info(&obj_info);
                sg_vs_btopp_ctx.start_ok_b = MMI_TRUE;
                DS_OUTLOG("SRV_OPP_SND_SUCC %d/%d", obj_info.remain_put_len, obj_info.total_obj_len);
                VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_start");   
            }
            break;
        case SRV_OPP_SND_FAIL:
            {

            }
            break;
        case SRV_OPP_SND_FAIL_BY_SERVER:
            {
                
                if (SRV_OPP_RESULT_OK != srv_oppc_send_end(sg_vs_btopp_ctx.clt_hd))
                {
                    DS_OUTLOG("SRV_OPP_SND_FAIL_BY_SERVER AND srv_oppc_send_end F");
                }
            }
            break;
        case SRV_OPP_SND_PERSENT:
            {
                DS_OUTLOG("PRESENT %d/%d", snd_result->info.remain_put_len, snd_result->info.total_obj_len);
            }
            break;
        case SRV_OPP_SND_DONE:
            {
                // after send done
                //VS_CASE_BTOPP_FINISHED(MMI_TRUE, VS_BTOPP_DO, L"vs_btopp_do");
                vs_btoppc_send_finish();
            }
            break;

        default:
            break;

    }

    DS_OUTLOG("srv_oppc_is_sending ret %d", srv_oppc_is_sending());
    
    DS_OUTLOG("vs_btoppc_send_ind_cb E");

}




/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_disconn_result_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_btoppc_disconn_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_opp_disconn_notify_struct *disconn_notify = (srv_opp_disconn_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    mmi_bt_reject_passkey_ind(
        disconn_notify->bt_addr.lap,
        disconn_notify->bt_addr.uap,
        disconn_notify->bt_addr.nap);
    */
    DS_OUTLOG("vs_btoppc_disconn_ind_cb S");
    DS_OUTLOG("srv_oppc_is_aborting() ret [%d]", srv_oppc_is_aborting());
    DS_OUTLOG("srv_oppc_is_disconncting() ret [%d]", srv_oppc_is_disconncting());
    DS_OUTLOG("vs_btoppc_disconn_ind_cb E");
    
    
    VS_CASE_BTOPP_FINISHED(MMI_TRUE, 0, L"vs_btopp_finish");   
}

/*****************************************************************************
 * FUNCTION
 *  vs_btoppc_connect_ind_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_btoppc_connect_ind_cb(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_conn_notify_struct * conn_notify = (srv_opp_conn_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btoppc_connect_ind_cb S");
    DS_OUTLOG("vs_btoppc_connect_ind_cb [%d]", conn_notify->type);
    if (SRV_OPP_CONN_FAILED == conn_notify->type)
    {
        sg_vs_btopp_ctx.start_ok_b = MMI_FALSE;
        DS_OUTLOG("vs_btoppc_connect_ind_cb SRV_OPP_CONN_FAILED");
        VS_CASE_BTOPP_FINISHED(MMI_FALSE, 0, L"vs_btopp_start");   
        return;
    }
    DS_OUTLOG("srv_oppc_is_idle() ret %d", srv_oppc_is_idle());
    //VS_CASE_BTOPP_FINISHED(MMI_TRUE, VS_BTOPP_START, L"vs_btopp_start");   
    DS_OUTLOG("vs_btoppc_connect_ind_cb E");

}

#endif /*__MMI_OPP_SUPPORT__ */


#endif /* __MAUI_SDK_TEST__ */
