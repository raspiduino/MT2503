/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#include "avk_conn_btcm.h"
#include "MMI_include.h"
#include "BtcmSrvGprot.h"
#include "mmi_rp_app_sdk_test_def.h"
#include "CommonScreens.h"      /* screen */
#include "CommonScreensResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "menucuigprot.h"
#include "fseditorcuigprot.h"
#include "BTMMIScrGprots.h"
//#include "tst_sdk_framework.h"
#include "inlinecuigprot.h"
#include "avk_conn_btds.h"
#include "CustMenuRes.h"
#include "wgui.h"

#define VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(a, b, c) \
    AVK_CASE_RESULT(AVK_PASS); \
     AVK_ASYN_DONE();
     //VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_EX(a, b, c, GRP_ID_VS_AVK_BTCM)
    

typedef struct
{
    S32 idx_hl;
    S32 btcm_hdl;
    U32 discovered_dev_num;
#ifdef __MMI_BT_SUPPORT__
    U32 target_idx;    
    srv_bt_cm_bt_addr target_dev_addr;
    MMI_BOOL flag_bond_b;
    U32 service_list[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE];
#endif /* __MMI_BT_SUPPORT__ */
    mmi_id group_id;
    mmi_id parent_menu_id;

}vs_btcm_ctx;

static vs_btcm_ctx sg_vs_btcm_ctx;


AVK_ADD_ITEM(AVK_CONN_BTCM_MANUAL_N, L"Manual cases", AVK_CONN_BTCM);
//AVK_ADD_ITEM(AVK_CONN_BTCM_MANUAL_E, L"Manual cases Exp", AVK_CONN_BTCM);

static void VS_CASE_BTCM_FINISHED(MMI_BOOL ret_b, vs_test_item_enum ti_e, const void * words)
{
    //U16 wszTxt[128] = {0};
    
    //vs_tfw_trace_result((U16*)words, ret_b, 0, VS_TA_BTCM);
    AVK_CASE_RESULT((0 != ret_b) ? AVK_PASS : AVK_FAIL);
    AVK_ASYN_DONE();
    /*
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

static void mmi_vs_btcm_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
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


static  void vs_btcm_entry_scr_int(void);
static void vs_btcm_exit_scr(void);

static mmi_ret vs_btcm_main_group_proc(mmi_event_struct *param);
static mmi_ret vs_btcm_menu_cui_proc(mmi_event_struct * param);
static mmi_ret vs_btcm_mydev_group_proc(mmi_event_struct* evt);
static void vs_btcm_notice_entry(void);
#ifdef __MMI_BT_SUPPORT__
static void vs_btcm_notifier_cb(U32 event, void* para);
static void vs_btcm_power_switch_off_complete_cb(void * user_data);
static void vs_btcm_power_switch_on_complete_cb(void * user_data);
static void vs_btcm_inq_result_notify_cb(void * user_data);
static void vs_btcm_inq_complete_cb(void * user_data);
static void vs_btcm_bond_result_cb(void * user_data);
static void vs_btcm_passkey_input_cb(void * user_data);
static void vs_btcm_pair_result_cb(void * user_data);
static void vs_btcm_security_user_confirm_cb(void * user_data);
static void vs_btcm_security_passkey_notify_cb(void * user_data);
static void vs_btcm_entry_security_keypress_notify_cb(void * user_data);
static void vs_btcm_authorize_ind_notify_cb(void * user_data);
static void vs_btcm_connect_complete_cb(void * user_data);
static void vs_btcm_entry_disconnect_complete_cb(void * user_data);
static void vs_btcm_release_conn_complete_cb(void * user_data);
static void vs_btcm_refresh_prof_complete_cb(void * user_data);
static void vs_btcm_unblock_complete_cb(void * user_data);
static void vs_btcm_mydev_del_complete_cb(void * user_data);
static void vs_btcm_set_authorize_complete_cb(void * user_data);
static void vs_btcm_set_vis_complete_cb(void * user_data);
static void vs_btcm_set_name_complete_cb(void * user_data);
#ifdef __MMI_BT_SHOW_AUTH_SETTING__  
static void vs_btcm_set_authentication_complete_cb(void * user_data);
#endif
static void vs_btcm_sco_ind_cb(void * user_data);
static void vs_btcm_panic_ind_pre_process(void * user_data);
static void vs_btcm_read_remote_name_cb(void * user_data);
#if defined __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
static void vs_btcm_set_limit_vis_complete_cb(void * user_data);
#endif
#ifdef __BT_AUTO_DETECT_SUPPORT__
static void vs_btcm_chip_status_ind_cb(void * user_data);
#endif

#endif /* __MMI_BT_SUPPORT__ */

static void vs_btcm_leftkey_handler_cb(void)
{
    vs_btcm_start();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_START_N, AVK_CONN_BTCM_MANUAL_N)
{

    CHAR buf[] = {"0. need two handsets that all with bt inside.\n\
    1. Make sure BT of tested one is swith off. \n\
    2. The other[destination] is swith on. \n\
    3. Use AT command to set the destination device addr [AT+EMBT=0,bt,ab8967452301]. \n\
    4. To test the case in order. \n\
    5. Press 'OK' to begin."};
    static WCHAR wbuf[512];

    mmi_asc_to_wcs(wbuf, buf);
    
    AVK_MANU_SHOW_TIPS(wbuf, vs_btcm_leftkey_handler_cb);
    
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_PWR_ON_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_switch_pwr_on();
}
AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_SWITCH_VIS_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_switch_vis();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_SET_LIMIT_VIS_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_set_limit_vis();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_SEARCH_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_search();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_PAIR_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_pair();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_SRVLIST_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_srvlist();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_RENAME_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_rename();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_AUTHORIZE_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_authorize();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_CONNECT_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_connect();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_CONN_STOP_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_conn_stop();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_SET_HOST_NAME_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_set_host_name();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_READ_REMOTE_INFO_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_read_remote_info();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_AUD_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_aud();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_DELETE_N, AVK_CONN_BTCM_MANUAL_PAIR_N)
{
    vs_btcm_delete();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_PWR_OFF_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_switch_pwr_off();
}

AVK_MANUAL_CASE(AVK_CONN_BTCM_MANUAL_FINISH_N, AVK_CONN_BTCM_MANUAL_N)
{
    vs_btcm_finish();
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
//
//static void vs_btcm_option_highlight_hdlr(S32 index)
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
//    //UI_string_type item_text = get_item_text(index);
//
//    switch (index)
//    {
//    case VS_BTCM_ITEM_START:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_start, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    case VS_BTCM_ITEM_SWITCH_PWR_ON:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_switch_pwr_on, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    case VS_BTCM_ITEM_SWITCH_VIS:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_switch_vis, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    case VS_BTCM_ITEM_SET_LIMIT_VIS:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_set_limit_vis, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    case VS_BTCM_ITEM_SEARCH:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_search, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_SEARCH_ABT:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_search_abt, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_PAIR:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_pair, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_SRVLIST:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_srvlist, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_RENAME:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_rename, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_AUTHORIZE:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_authorize, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_CONNECT:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_connect, (MMI_key_event_type)KEY_EVENT_UP);
//        }break; 
//    case VS_BTCM_ITEM_CONN_STOP:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_conn_stop, (MMI_key_event_type)KEY_EVENT_UP);
//        }break; 
//    case VS_BTCM_ITEM_SET_HOST_NAME:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_set_host_name, (MMI_key_event_type)KEY_EVENT_UP);
//        }break; 
//    case VS_BTCM_ITEM_READ_REMOTE_INFO:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_read_remote_info, (MMI_key_event_type)KEY_EVENT_UP);
//        }break; 
//    case VS_BTCM_ITEM_AUD:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_aud, (MMI_key_event_type)KEY_EVENT_UP);
//        }break; 
//    case VS_BTCM_ITEM_DELETE:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_delete, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;      
//    case VS_BTCM_ITEM_SWITCH_PWR_OFF:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_switch_pwr_off, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;        
//    case VS_BTCM_ITEM_FINISH:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_finish, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    case VS_BTCM_ITEM_TEST_ALL:
//        {
//            SetLeftSoftkeyFunction(vs_btcm_test_all, (MMI_key_event_type)KEY_EVENT_UP);
//        }break;
//    default:
//        {
//
//        }break;
//    }
//
//    sg_vs_btcm_ctx.idx_hl = index;
//}
//
//void vs_btcm_entry_scr(void)
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
//    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VS_AVK_BTCM, vs_btcm_main_group_proc, NULL);
//    sg_vs_btcm_ctx.group_id = GRP_ID_VS_AVK_BTCM;
//    mmi_frm_group_enter(sg_vs_btcm_ctx.group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//
//    vs_btcm_notice_entry();
//
//    //vs_btcm_entry_scr_int();
//
//    DS_OUTLOG("vs_btcm_entry_scr E");
//}
//
//static void vs_btcm_entry_scr_int(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//#ifdef BT_RES_ITEM
//    U16 nitems = 0;
//#endif
//    U16 itemlist[VS_BTCM_OPTOIN_SIZE] = {0};
//    int item = 0;
//    MMI_BOOL ret = MMI_FALSE;
//    //MMI_ID group_id = 0;
//    //MMI_ID scrn_id = 0;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    
//    //mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
//    //if (SCR_ID_VS_AVK_BTCM_NOTICE == scrn_id)
//    //    mmi_frm_scrn_close(GRP_ID_VS_AVK_BTCM, SCR_ID_VS_AVK_BTCM_NOTICE);
//
//    ret = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTCM, SCR_ID_VS_AVK_BTCM, NULL, vs_btcm_entry_scr_int, MMI_FRM_FULL_SCRN);
//
//    if(ret == MMI_FALSE)
//        return;
//
//    RegisterHighlightHandler(vs_btcm_option_highlight_hdlr);
//#ifdef BT_RES_ITEM
//    nitems = GetNumOfChild_Ext(MENU_ID_VS_AVK_BTCM);
//#else
//
//#endif
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_START;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SWITCH_PWR_ON;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SWITCH_VIS;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SET_LIMIT_VIS;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SEARCH ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SEARCH_ABT ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_PAIR ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SRVLIST ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_RENAME ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_AUTHORIZE ;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_CONNECT;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_CONN_STOP;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SET_HOST_NAME;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_READ_REMOTE_INFO;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_AUD;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_DELETE;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_SWITCH_PWR_OFF;
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_FINISH;
//    
//    itemlist[item++] = (U16) STR_ID_VS_AVK_BTCM_TEST_ALL;
//
//    //itemlist[item++] = (U16) STR_ID_VS_AVK_VCARD_TEST_ALL ;
//
//    ShowCategory15Screen(
//        STR_ID_VS_AVK_BTCM,
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
//        sg_vs_btcm_ctx.idx_hl,
//        NULL);
//
//    SetRightSoftkeyFunction(vs_btcm_exit_scr, KEY_EVENT_UP);
//    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//
//    return;
//}



void vs_btcm_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__  
    U32 mask_cb = 0;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_start S");

#ifdef __BT_AUTO_DETECT_SUPPORT__    
    if (!srv_bt_chip_available())
    {
        DS_OUTLOG("vs_btcm_start srv_bt_chip_available FALSE");
        DisplayPopup((PU8) (L"srv_bt_chip_available FALSE."), IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        return;
    }
#endif

    if (0 < sg_vs_btcm_ctx.btcm_hdl)
    {
        DS_OUTLOG("vs_btcm_start sg_vs_btcm_ctx.btcm_hdl ok");
        DisplayPopup((PU8) (L"vs_btcm_start already."), IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        return;
    }


    mask_cb = SRV_BT_CM_EVENT_ACTIVATE |
             SRV_BT_CM_EVENT_DEACTIVATE  |
             SRV_BT_CM_EVENT_INQUIRY_IND |
             SRV_BT_CM_EVENT_INQUIRY_COMPLETE |
             SRV_BT_CM_EVENT_PAIR_IND |
             SRV_BT_CM_EVENT_BOND_RES|
             SRV_BT_CM_EVENT_PAIR_RES |
             SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM |
             SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY |
             SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY |
             SRV_BT_CM_EVENT_CONNECT_REQ |
             SRV_BT_CM_EVENT_CONNECT_RES |
             SRV_BT_CM_EVENT_DISCONNECT_IND |
             SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
             SRV_BT_CM_EVENT_REFRESH_PROFILE |
             SRV_BT_CM_EVENT_SET_AUTHORIZE |
             SRV_BT_CM_EVENT_UNBLOCK |
             SRV_BT_CM_EVENT_MYDEV_DEL |
             SRV_BT_CM_EVENT_SET_VISIBILITY |
             SRV_BT_CM_EVENT_SET_NAME |
             SRV_BT_CM_EVENT_SET_AUTHENTICATION |
             //SRV_BT_CM_EVENT_SET_SIMAP |
             SRV_BT_CM_EVENT_SCO_IND |
             SRV_BT_CM_EVENT_PANIC_IND |
             SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME |
             SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE |
             SRV_BT_CM_EVENT_CHIP_DETECT;
    
    sg_vs_btcm_ctx.btcm_hdl = srv_bt_cm_set_notify(vs_btcm_notifier_cb, mask_cb, NULL);
    if (0 > sg_vs_btcm_ctx.btcm_hdl)
    {
        DS_OUTLOG("srv_bt_cm_set_notify failure");
        ret_b = MMI_FALSE;
    }
    else
    {
        ret_b = MMI_TRUE;
    }

    if (srv_bt_cm_is_authentication())
    {
        DS_OUTLOG("srv_bt_cm_is_authentication ret MMI_TRUE");
        if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_set_authentication(MMI_FALSE))
        {
            DS_OUTLOG("srv_bt_cm_set_authentication ret not SRV_BT_CM_RESULT_SUCCESS");
        }
    }

    {
    srv_bt_cm_state_enum e;
    e = srv_bt_cm_get_state();
    DS_OUTLOG("srv_bt_cm_get_state 1 [%d]", e);
    }
    
    sg_vs_btcm_ctx.target_dev_addr.nap |= 0x0123;
    sg_vs_btcm_ctx.target_dev_addr.uap |= 0x45;
    sg_vs_btcm_ctx.target_dev_addr.lap |= 0X6789ab;
    
    DS_OUTLOG("vs_btcm_start:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                        ((sg_vs_btcm_ctx.target_dev_addr.nap & 0xff00) >> 8),
                        (sg_vs_btcm_ctx.target_dev_addr.nap & 0x00ff),
                        (sg_vs_btcm_ctx.target_dev_addr.uap),
                        ((sg_vs_btcm_ctx.target_dev_addr.lap & 0xff0000) >> 16),
                        ((sg_vs_btcm_ctx.target_dev_addr.lap & 0x00ff00) >> 8),
                        (sg_vs_btcm_ctx.target_dev_addr.lap & 0x0000ff));
                        
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_start");

    DS_OUTLOG("vs_btcm_start E");
    
#else
    
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_start",VS_TA_BTCM, 0);
    
#endif
    
}

void vs_btcm_switch_pwr_on(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_switch_pwr_on S");
    
    if (!srv_bt_cm_is_activated())
    {
        DS_OUTLOG("vs_btcm_switch_pwr_on");
        srv_bt_cm_switch_on();
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_switch_pwr_on");
    }
    
    DS_OUTLOG("vs_btcm_switch_pwr_on E");

    
        
#else
        
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_switch_pwr_on",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_switch_vis(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_switch_vis S");

    if (SRV_BT_CM_VISIBILITY_OFF == (srv_bt_cm_visibility_type)srv_bt_cm_get_visibility())
    {
        if (SRV_BT_CM_RESULT_SUCCESS != (srv_bt_cm_result_codes_enum)srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_ON))
        {
            ret_b = MMI_FALSE;
            VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_switch_vis");
        }
        else
        {
            DS_OUTLOG("vs_btcm_switch_vis ret SRV_BT_CM_RESULT_SUCCESS");
        }
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_switch_vis");
    }
    

    
    DS_OUTLOG("vs_btcm_switch_vis E");
    
        
#else
        
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_switch_vis",VS_TA_BTCM, 0);
        
#endif
}
void vs_btcm_set_limit_vis(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
    MMI_BOOL ret_b = MMI_TRUE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    DS_OUTLOG("vs_btcm_set_limit_vis S");

    
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__

    if (srv_bt_cm_is_limit_vis())
    {
        ret_b = (MMI_BOOL)srv_bt_cm_set_limit_vis(MMI_FALSE);
        DS_OUTLOG("srv_bt_cm_is_limit_vis ret MMI_TRUE");
    }
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_set_limit_vis");
    
#else

    DS_OUTLOG("__MMI_BT_LIMITED_DISCOVERY_SUPPORT__ NS");
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_set_limit_vis",VS_TA_BTCM, 0);

#endif

    
    DS_OUTLOG("vs_btcm_set_limit_vis E");
    
        
#else
        
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_set_limit_vis",VS_TA_BTCM, 0);
        
#endif
}
void vs_btcm_search(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_search S");
    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search(10, 60, 0xFFFFFFFF, MMI_TRUE))
    {
        DS_OUTLOG("vs_btcm_search ret SRV_BT_CM_RESULT_SUCCESS");
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_search");
    }
    
    DS_OUTLOG("vs_btcm_search E");
    
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_search",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_search_abt(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    U32 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_search_abt S");
    state = srv_bt_cm_get_state();
    if (SRV_BT_CM_STATE_INQUIRING == state || 
            SRV_BT_CM_STATE_INQUIR_RES_IND)
    {
        if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_search_abort())
        {
            DS_OUTLOG("vs_btcm_search_abt ret not SRV_BT_CM_RESULT_SUCCESS");
            ret_b = MMI_FALSE;
            VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_search_abt");
        }
    }
    else
    {
        DisplayPopup((PU8) (L"NOT SEARCHING"), IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);        
    }
    DS_OUTLOG("vs_btcm_search_abt E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_search_abt",VS_TA_BTCM, 0);
        
#endif
}
void vs_btcm_pair(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    S32 i = 0;
    srv_bt_cm_dev_struct * dev_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    DS_OUTLOG("vs_btcm_pair S");
    if (0 >= sg_vs_btcm_ctx.discovered_dev_num)
    {
        DisplayPopup((PU8) (L"no targets"), IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        DS_OUTLOG("vs_btcm_pair S");
        return;
    }
    
    DS_OUTLOG("vs_btcm_pair target_dev_addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                    ((sg_vs_btcm_ctx.target_dev_addr.nap & 0xff00) >> 8),
                    (sg_vs_btcm_ctx.target_dev_addr.nap & 0x00ff),
                    (sg_vs_btcm_ctx.target_dev_addr.uap),
                    ((sg_vs_btcm_ctx.target_dev_addr.lap & 0xff0000) >> 16),
                    ((sg_vs_btcm_ctx.target_dev_addr.lap & 0x00ff00) >> 8),
                    (sg_vs_btcm_ctx.target_dev_addr.lap & 0x0000ff));
    for (i = 0; i < srv_bt_cm_get_searched_dev_num(); i++)
    {
        DS_OUTLOG("srv_bt_cm_get_searched_dev_info S");
        dev_info_p = srv_bt_cm_get_searched_dev_info(i);
        DS_OUTLOG("srv_bt_cm_get_searched_dev_info E");
        if (dev_info_p)
        {
        
            DS_OUTLOG("dev_info_p->bd_addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                        ((dev_info_p->bd_addr.nap & 0xff00) >> 8),
                        (dev_info_p->bd_addr.nap & 0x00ff),
                        (dev_info_p->bd_addr.uap),
                        ((dev_info_p->bd_addr.lap & 0xff0000) >> 16),
                        ((dev_info_p->bd_addr.lap & 0x00ff00) >> 8),
                        (dev_info_p->bd_addr.lap & 0x0000ff));
            if ((dev_info_p->bd_addr.nap == sg_vs_btcm_ctx.target_dev_addr.nap) &&
                    (dev_info_p->bd_addr.uap == sg_vs_btcm_ctx.target_dev_addr.uap) &&
                    (dev_info_p->bd_addr.lap == sg_vs_btcm_ctx.target_dev_addr.lap))
            {
                ret_b = MMI_TRUE;
                DS_OUTLOG("ret_b = MMI_TRUE ok");
                break;
            }
            
        }
        DS_OUTLOG("i [%d]", i);
    }
    if (!ret_b)
    {
        //VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_pair");
        DisplayPopup((PU8) (L"NOT FIND TARGET"), IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }
    sg_vs_btcm_ctx.target_idx = i;
    DS_OUTLOG("sg_vs_btcm_ctx.target_idx [%d]", sg_vs_btcm_ctx.target_idx);
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_bond(sg_vs_btcm_ctx.target_idx))
    {
        DS_OUTLOG("vs_btcm_pair ret not SRV_BT_CM_RESULT_SUCCESS");        
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_pair");
    }


    
    DS_OUTLOG("vs_btcm_pair E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_pair",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_srvlist(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_srvlist S");
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_refresh_service_list(&(sg_vs_btcm_ctx.target_dev_addr)))
    {
        DS_OUTLOG("vs_btcm_srvlist Addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                            ((sg_vs_btcm_ctx.target_dev_addr.nap & 0xff00) >> 8),
                            (sg_vs_btcm_ctx.target_dev_addr.nap & 0x00ff),
                            (sg_vs_btcm_ctx.target_dev_addr.uap),
                            ((sg_vs_btcm_ctx.target_dev_addr.lap & 0xff0000) >> 16),
                            ((sg_vs_btcm_ctx.target_dev_addr.lap & 0x00ff00) >> 8),
                            (sg_vs_btcm_ctx.target_dev_addr.lap & 0x0000ff));
         VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_srvlist");
    }
    DS_OUTLOG("vs_btcm_srvlist E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_srvlist",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_rename(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buf[32] = {"vs_btcm_tst1"};
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    DS_OUTLOG("vs_btcm_rename S");
    srv_bt_cm_get_dev_name(&(sg_vs_btcm_ctx.target_dev_addr), 32, buf);
    if (0 == buf[0])
    {
        DS_OUTLOG("vs_btcm_rename srv_bt_cm_get_dev_name F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_rename");
        return;
    }

    i = strlen((CHAR*)buf);

    buf[i] = 86;
    buf[i + 1] = 82;
    buf[i + 2] = 0;
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_set_dev_name(&(sg_vs_btcm_ctx.target_dev_addr), buf))
    {
        DS_OUTLOG("vs_btcm_rename Addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                            ((sg_vs_btcm_ctx.target_dev_addr.nap & 0xff00) >> 8),
                            (sg_vs_btcm_ctx.target_dev_addr.nap & 0x00ff),
                            (sg_vs_btcm_ctx.target_dev_addr.uap),
                            ((sg_vs_btcm_ctx.target_dev_addr.lap & 0xff0000) >> 16),
                            ((sg_vs_btcm_ctx.target_dev_addr.lap & 0x00ff00) >> 8),
                            (sg_vs_btcm_ctx.target_dev_addr.lap & 0x0000ff));
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_rename");
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_rename");
    }
    DS_OUTLOG("vs_btcm_rename E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_rename",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_authorize(void)
{
#if defined(__MMI_BT_AUTHORIZE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_bt_cm_authorize_type a_type = SRV_BT_CM_AUTHORIZE_TOTAL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_authorize S");
    /*a_type = */srv_bt_cm_get_authorize(&(sg_vs_btcm_ctx.target_dev_addr));
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_set_authorize(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT))
    {
        DS_OUTLOG("vs_btcm_authorize not SRV_BT_CM_RESULT_SUCCESS");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_authorize");
    }
    DS_OUTLOG("vs_btcm_authorize E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_authorize",VS_TA_BTCM, 0);
        
#endif
}


void vs_btcm_connect(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_connect S");
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; i++)
    {
        if (SRV_BT_CM_OBEX_FILE_TRANSFER_UUID == sg_vs_btcm_ctx.service_list[i])
        {
            ret_b = MMI_TRUE;
            break;
        }
    }

    if (ret_b)
    {
        S32 conn_id = 0;
        DS_OUTLOG("vs_btcm_connect TRUE");
        conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_OBEX_FILE_TRANSFER_UUID, &(sg_vs_btcm_ctx.target_dev_addr), NULL);
        if (0 < conn_id)
        {
            VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_connect");
        }
        else
        {
            VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_connect");
        }
    }
    else
    {
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_connect",VS_TA_BTCM, 0);
        //VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_connect");
    }
    DS_OUTLOG("vs_btcm_connect E");

    
#else
    
        VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_connect",VS_TA_BTCM, 0);
    
#endif
}

void vs_btcm_conn_stop(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    srv_bt_cm_stop_conn(SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);
    VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_conn_stop");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_conn_stop",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_set_host_name(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct * host_dev_p = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    DS_OUTLOG("vs_btcm_set_host_name S");
    host_dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_host_dev_info();
    if (NULL == host_dev_p)
    {
        DS_OUTLOG("srv_bt_cm_get_host_dev_info F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_set_host_name");
        return;
    }
    len = strlen((CHAR*)(host_dev_p->name));
    host_dev_p->name[len] = 'V';
    host_dev_p->name[len + 1] = 'S';
    host_dev_p->name[len + 2] = 0;
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_set_host_dev_name(host_dev_p->name))
    {
        DS_OUTLOG("srv_bt_cm_set_host_dev_name F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_set_host_name");
        return;
    }
        
    DS_OUTLOG("vs_btcm_set_host_name E");
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_set_host_name",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_read_remote_info(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0xFFFFFFFF;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_read_remote_info S");
    
    if (NULL == srv_bt_cm_get_dev_info_by_addr(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_ALL_DEV))
    {
        DS_OUTLOG("srv_bt_cm_get_dev_info_by_addr F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_read_remote_name");
        return;
    }
    {
    i = 0xFFFFFFFF;
    if (0xFFFFFFFF == (i = srv_bt_cm_get_dev_index(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_ALL_DEV)))
    {
        DS_OUTLOG("srv_bt_cm_get_dev_index F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_read_remote_name");
        return;
    }
    DS_OUTLOG("srv_bt_cm_get_dev_index [%i]", i);
    }

    if (NULL == srv_bt_cm_get_dev_info_by_index(i, SRV_BT_CM_ALL_DEV))
    {
        DS_OUTLOG("srv_bt_cm_get_dev_info_by_index F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_read_remote_name");
        return;
    }

    
    {
    MMI_BOOL ret_t = srv_bt_cm_dev_property_check(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_DEV_PROPERTY_TOTAL);
    DS_OUTLOG("srv_bt_cm_dev_property_check ret_t[%d]", ret_t);
    }

    {
    MMI_BOOL ret_t = srv_bt_cm_check_dev_profile_support_status(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);
    DS_OUTLOG("srv_bt_cm_check_dev_profile_support_status ret_t[%d]", ret_t);
    }

    {
        U32 total = srv_bt_cm_get_dev_num(SRV_BT_CM_DISCOVERED_DEV);
        DS_OUTLOG("SRV_BT_CM_DISCOVERED_DEV [%d]", total);
        total = srv_bt_cm_get_dev_num(SRV_BT_CM_RECENT_USED_DEV);
        DS_OUTLOG("SRV_BT_CM_RECENT_USED_DEV [%d]", total);
        total = srv_bt_cm_get_dev_num(SRV_BT_CM_PAIRED_DEV);
        DS_OUTLOG("SRV_BT_CM_PAIRED_DEV [%d]", total);
        total = srv_bt_cm_get_dev_num(SRV_BT_CM_ALL_DEV);
        DS_OUTLOG("SRV_BT_CM_ALL_DEV [%d]", total);
        total = srv_bt_cm_get_dev_num(SRV_BT_CM_DEV_TYPE_TOTAL);
        DS_OUTLOG("SRV_BT_CM_DEV_TYPE_TOTAL [%d]", total);
    }
    
    if (SRV_BT_CM_RESULT_SUCCESS != (srv_bt_cm_result_codes_enum)srv_bt_cm_read_remote_dev_name(&(sg_vs_btcm_ctx.target_dev_addr)))
    {
        DS_OUTLOG("srv_bt_cm_read_remote_dev_name F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_read_remote_name");
        return;
    }
    DS_OUTLOG("vs_btcm_read_remote_info E");

    
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_read_remote_info",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_aud(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    DS_OUTLOG("vs_btcm_aud S");
    srv_bt_cm_is_audio_path_to_headset();
    srv_bt_cm_is_incall_aud_swap2bt();
    srv_bt_cm_is_audio_link_on();
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_aud");
    DS_OUTLOG("vs_btcm_aud E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_aud",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_delete(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    S32 ret_n = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_delete S");
    ret_b = srv_bt_cm_get_sco_status();
    DS_OUTLOG("vs_btcm_delete sco sts [%d]", ret_b);

    //srv_bt_cm_debond(U32 index)
    if (srv_bt_cm_is_dev_conn_active(&(sg_vs_btcm_ctx.target_dev_addr)))
    {
        DS_OUTLOG("srv_bt_cm_is_dev_conn_active TRUE");
        ret_n = srv_bt_cm_release_dev_conn(&(sg_vs_btcm_ctx.target_dev_addr));
        if (SRV_BT_CM_RESULT_SUCCESS != ret_n)
        {
            DS_OUTLOG("srv_bt_cm_release_dev_conn F");
            ret_n = srv_bt_cm_release_profile(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_OBEX_FILE_TRANSFER_UUID);
            if (SRV_BT_CM_RESULT_SUCCESS != ret_n)
            {
                DS_OUTLOG("srv_bt_cm_release_profile F");
                ret_n = srv_bt_cm_release_all_conn();
                if (SRV_BT_CM_RESULT_SUCCESS != ret_n)
                {
                    DS_OUTLOG("srv_bt_cm_release_all_conn F");
                    VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_delete");
                    return;
                }
            }
             
        }
    }

    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_dev_del(&(sg_vs_btcm_ctx.target_dev_addr)))
    {
        DS_OUTLOG("srv_bt_cm_dev_del F");
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_delete");
        return;
    }
    
    
    srv_bt_cm_dev_del_all();

    DS_OUTLOG("vs_btcm_delete E");
        
#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_delete",VS_TA_BTCM, 0);
        
#endif
}



static void vs_btcm_exit_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
}

void vs_btcm_switch_pwr_off(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_switch_pwr_off S");
    
    if (srv_bt_cm_is_activated())
    {
        DS_OUTLOG("vs_btcm_switch_pwr_off");
        srv_bt_cm_switch_off();
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_switch_pwr_off");
    }
    
    DS_OUTLOG("vs_btcm_switch_pwr_off E");

#else
        
            VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_switch_pwr_off",VS_TA_BTCM, 0);
        
#endif
}

void vs_btcm_finish(void)
{
#ifdef __MMI_BT_SUPPORT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

    DS_OUTLOG("vs_btcm_finish S");
    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_reset_notify(sg_vs_btcm_ctx.btcm_hdl))
    {    
        ret_b = MMI_TRUE;
        memset(&sg_vs_btcm_ctx, 0, sizeof(sg_vs_btcm_ctx));
        DS_OUTLOG("vs_btcm_finish SUCC");
    }

    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_finish");
    DS_OUTLOG("vs_btcm_finish E");
    
#else
            
    VS_TFW_SHOW_PLATFORM_NOT_SUPPORT_BTCM_EX(L"vs_btcm_finish",VS_TA_BTCM, 0);
            
#endif
}

//void vs_btcm_test_all(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                                                 */
//    /*----------------------------------------------------------------*/
//    U16 id;
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                                                       */
//    /*----------------------------------------------------------------*/
//
//
//    
//    DS_OUTLOG("vs_btcm_test_all S");
//
//    vs_tfw_set_both_auto_and_manual();
//    id = GetActiveScreenId();
//
//    vs_tfw_test_all_reset();
//    vs_tfw_test_all_screen_id(id);
//    vs_tfw_ta_scope(VS_TA_BT, VS_TA_TOTAL);
//    vs_tfw_find_beginning(VS_TA_BT);
//    
//
//    
//    
//    DS_OUTLOG("vs_btcm_test_all E");
//
//}


///*****************************************************************************
// * FUNCTION
// *  vs_btcm_main_group_proc
// * DESCRIPTION
// *  This function is BT CM Main screen group proc function
// *  It will handle all event on the screen group
// * PARAMETERS
// *  param       [IN]        MMI event structure
// * RETURNS
// *  mmi_ret
// *****************************************************************************/
//mmi_ret vs_btcm_main_group_proc(mmi_event_struct *param)
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
//            vs_btcm_menu_cui_proc(param);
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
//static mmi_ret vs_btcm_menu_cui_proc(mmi_event_struct * param)
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
//                switch (menu_evt->parent_menu_id)
//                {
//
//                    case SCR_ID_VS_AVK_BTCM_MYDEV:                    
//                        return vs_btcm_mydev_group_proc(param);
//                        
//                    default:
//                        return MMI_RET_OK;
//                }
//            }break;
//              
//        /* CUI Menu highlight event : send to APP by the menu cui highlight handler */            
//        case EVT_ID_CUI_MENU_ITEM_HILITE:
//            {
//                switch (menu_evt->parent_menu_id)
//                {
//                    case SCR_ID_VS_AVK_BTCM_MYDEV:                    
//                        return vs_btcm_mydev_group_proc(param);
//                        
//                    default:
//                        return MMI_RET_OK;  
//                }
//            }break;
//      
//        /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
//        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
//            switch (sg_vs_btcm_ctx.parent_menu_id)
//            {   
//                case SCR_ID_VS_AVK_BTCM_MYDEV:                    
//                    vs_btcm_mydev_group_proc(param);
//                    break;
//            }
//            cui_menu_close(menu_evt->sender_id);
//            break;
//        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
//             vs_btcm_mydev_group_proc(param);
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

static mmi_ret vs_btcm_mydev_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    //cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    //srv_bt_cm_dev_struct * dev_p;
    //S32 j = 0, nItems = 0;
    //U8 paired_dev_num;
    //U32 action_item;
    //U8 act_con_num;
    //vs_btcm_connection_icon_type conn_icon_type;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    
    return MMI_RET_OK;
}

//static void vs_btcm_notice_entry(void)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U16 tmp_buf_wsz[] = {L"0. need two handsets that all with bt inside.\n\
//    1. Make sure BT of tested one is swith off. \n\
//    2. The other[DEST] is swith on. \n\
//    3. Use AT command to set the DEST BT addr [AT+EMBT=0,bt,ab8967452301]. \n\
//    4. To test the case in order. \n\
//    5. Press 'OK' to begin."};
//    S32 size = 0;
//    U8 *gui_buffer = NULL;
//    MMI_BOOL ret_b = MMI_FALSE;
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/    
//    ret_b = mmi_frm_scrn_enter(GRP_ID_VS_AVK_BTCM, 
//                                                    SCR_ID_VS_AVK_BTCM_NOTICE, 
//                                                    NULL, 
//                                                    vs_btcm_notice_entry, 
//                                                    MMI_FRM_UNKNOW_SCRN);
//    if (!ret_b)
//    {
//        mmi_vs_btcm_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
//        DS_OUTLOG("[DLA] [F] vs_btcm_notice_entry GRP_ID_VS_AVK_BTCM_NOTICE");
//        return;
//    }
//        
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
//    SetLeftSoftkeyFunction(vs_btcm_entry_scr_int, KEY_EVENT_UP);          
//    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
//
//}

#ifdef __MMI_BT_SUPPORT__

static void vs_btcm_notifier_cb(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 srv_hd = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DS_OUTLOG("vs_btcm_notifier_cb S");
    srv_hd = *((S32*)para);
    if (srv_hd == sg_vs_btcm_ctx.btcm_hdl)
    {
        DS_OUTLOG("vs_btcm_notifier_cb [0x%x]", event);
        switch (event)
        {
            case SRV_BT_CM_EVENT_ACTIVATE:
                vs_btcm_power_switch_on_complete_cb(para);
                break;
            case SRV_BT_CM_EVENT_DEACTIVATE:
                vs_btcm_power_switch_off_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_INQUIRY_IND:
                vs_btcm_inq_result_notify_cb(para);
                break;

            case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
                vs_btcm_inq_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_PAIR_IND:
                vs_btcm_passkey_input_cb(para);
                break;

            case SRV_BT_CM_EVENT_PAIR_RES:
                vs_btcm_pair_result_cb(para);
                break;

            case SRV_BT_CM_EVENT_BOND_RES:
                vs_btcm_bond_result_cb(para);
                break;
#ifdef __MMI_BT_SIMPLE_PAIR__
            case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
                vs_btcm_security_user_confirm_cb(para);
                break;

            case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
                vs_btcm_security_passkey_notify_cb(para);
                break;

            case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
                vs_btcm_entry_security_keypress_notify_cb(para);
                break;
#endif
            case SRV_BT_CM_EVENT_CONNECT_REQ:
                vs_btcm_authorize_ind_notify_cb(para);
                break;

            case SRV_BT_CM_EVENT_CONNECT_RES:
                vs_btcm_connect_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_DISCONNECT_IND:
                vs_btcm_entry_disconnect_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
                vs_btcm_release_conn_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_REFRESH_PROFILE:
                vs_btcm_refresh_prof_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_MYDEV_DEL:
                vs_btcm_mydev_del_complete_cb(para);
                break;

#ifdef __MMI_BT_AUTHORIZE__
            case SRV_BT_CM_EVENT_SET_AUTHORIZE:
                vs_btcm_set_authorize_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_UNBLOCK:
                vs_btcm_unblock_complete_cb(para);
                break;
#endif
            case SRV_BT_CM_EVENT_SET_VISIBILITY:
                vs_btcm_set_vis_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_SET_NAME:
                vs_btcm_set_name_complete_cb(para);
                break;

            case SRV_BT_CM_EVENT_SET_AUTHENTICATION:
#ifdef __MMI_BT_SHOW_AUTH_SETTING__  
                vs_btcm_set_authentication_complete_cb(para);
#endif                
                break;

            case SRV_BT_CM_EVENT_SCO_IND:
                vs_btcm_sco_ind_cb(para);
                break;

            case SRV_BT_CM_EVENT_PANIC_IND:
                vs_btcm_panic_ind_pre_process(para);
                break;

            case SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME:
                vs_btcm_read_remote_name_cb(para);
                break;

#if defined __MMI_BT_LIMITED_DISCOVERY_SUPPORT__

            case SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE:
                vs_btcm_set_limit_vis_complete_cb(para);
                break;
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
            case SRV_BT_CM_EVENT_CHIP_DETECT:
                 vs_btcm_chip_status_ind_cb(para);
                 break;
#endif

            default:
                break;
        }
        
        DS_OUTLOG("vs_btcm_notifier_cb E");
    }
}


static void vs_btcm_power_switch_off_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_deactivate_struct * data = (srv_bt_cm_deactivate_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    DS_OUTLOG("vs_btcm_power_switch_off_complete_cb S");
#if defined(__MMI_BT_AUTHORIZE__)
    srv_bt_cm_unblock(&(sg_vs_btcm_ctx.target_dev_addr));
#endif /* (__MMI_BT_AUTHORIZE__) */
    VS_CASE_BTCM_FINISHED(data->result, 0, L"vs_btcm_switch_pwr_off");
    
    DS_OUTLOG("vs_btcm_power_switch_off_complete_cb E");
    
}


static void vs_btcm_power_switch_on_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_activate_struct * data = (srv_bt_cm_activate_struct *)user_data;
    srv_bt_cm_power_status_enum sts_e;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    DS_OUTLOG("vs_btcm_power_switch_on_complete_cb S");
    //srv_bt_cm_activate_profile();
    sts_e =  srv_bt_cm_get_power_status();
    DS_OUTLOG("vs_btcm_power_switch_on_complete_cb sts[%d]", sts_e);
    VS_CASE_BTCM_FINISHED(data->result, 0, L"vs_btcm_switch_pwr_on");
    
    DS_OUTLOG("vs_btcm_power_switch_on_complete_cb E");
    
}


static void vs_btcm_inq_result_notify_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_inquiry_indication_struct *data = (srv_bt_cm_inquiry_indication_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    DS_OUTLOG("vs_btcm_inq_result_notify_cb S");

    sg_vs_btcm_ctx.discovered_dev_num = data->discovered_dev_num;
    {
    srv_bt_cm_state_enum e;
    e = srv_bt_cm_get_state();
    DS_OUTLOG("srv_bt_cm_get_state 2 [%d]", e);
    }
    DS_OUTLOG("vs_btcm_inq_result_notify_cb searched dev num [%d]", data->discovered_dev_num);
    
    DS_OUTLOG("vs_btcm_inq_result_notify_cb E");
}

static void vs_btcm_inq_complete_cb(void * user_data)   /* discov cfm or discov-cancel cfm */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_inquiry_complete_struct * data = (srv_bt_cm_inquiry_complete_struct *)user_data;
    U8 discovered_dev_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DS_OUTLOG("vs_btcm_inq_complete_cb S");
    
    discovered_dev_num = srv_bt_cm_get_searched_dev_num();
    DS_OUTLOG("vs_btcm_inq_complete_cb discovered_dev_num [%d]", discovered_dev_num);
    sg_vs_btcm_ctx.discovered_dev_num = discovered_dev_num;

    // TODO: list the dis dev num.
    
    if (SRV_BT_CM_RESULT_SUCCESS == data->result)
    {
        if (data->is_cancelled)
        {
            VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_search_abt");
        }
        else
        {
            VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_search");
        }
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_search");
    }
    
    DS_OUTLOG("vs_btcm_inq_complete_cb E");
}
// pairing 1
static void vs_btcm_bond_result_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pin_key[12] = {0};
    srv_bt_cm_bond_res_struct * data = (srv_bt_cm_bond_res_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    
    DS_OUTLOG("vs_btcm_bond_result_cb S");
    if (SRV_BT_CM_RESULT_SUCCESS == data->result)
    {
        DS_OUTLOG("vs_btcm_bond_result_cb OK");
        
        //sg_vs_btcm_ctx.target_dev_addr = data->dev_addr;
        //VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_pair");
        sg_vs_btcm_ctx.flag_bond_b = MMI_TRUE;
        strcpy((CHAR*)pin_key, "123");
        if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_send_passkey(&(sg_vs_btcm_ctx.target_dev_addr), pin_key, MMI_TRUE))
        {
            DS_OUTLOG("vs_btcm_pair srv_bt_cm_send_passkey not SRV_BT_CM_RESULT_SUCCESS");        
            VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_pair");
            return;
        }
    }
    else
    {
        sg_vs_btcm_ctx.flag_bond_b = MMI_FALSE;
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_pair");
    }
    
    DS_OUTLOG("vs_btcm_bond_result_cb E");
}
static void vs_btcm_passkey_input_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_ind_struct * data = (srv_bt_cm_pair_ind_struct *)user_data;
    U8 pin_key[12] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    
    DS_OUTLOG("vs_btcm_passkey_input_cb S");        
    strcpy((CHAR*)pin_key, "123");
    if (SRV_BT_CM_RESULT_SUCCESS != srv_bt_cm_send_passkey(&(data->dev_addr), pin_key, MMI_TRUE))
    {
        DS_OUTLOG("vs_btcm_pair srv_bt_cm_send_passkey not SRV_BT_CM_RESULT_SUCCESS");        
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_pair");
        return;
    }
    DS_OUTLOG("vs_btcm_passkey_input_cb E");        
    // type the key 123 as the pair pin-code
}
// pairing 2
static void vs_btcm_pair_result_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_res_struct *data = (srv_bt_cm_pair_res_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    DS_OUTLOG("vs_btcm_pair_result_cb S");        
    DS_OUTLOG("vs_btcm_pair_result_cb data->result [%d]", data->result);        
    if (SRV_BT_CM_RESULT_SUCCESS == data->result)
    {
        U8 n = srv_bt_cm_get_paired_dev_num();
        DS_OUTLOG("vs_btcm_pair_result_cb paired num[%d]", n);
        if (0 < n)
        {
            S32 i = 0;
            for (i = 0; i < n; i++)
            {
                srv_bt_cm_dev_struct * dev_paired_p = NULL;
                dev_paired_p = srv_bt_cm_get_paired_dev_info(i);
                if (dev_paired_p)
                    DS_OUTLOG("vs_btcm_pair_result_cb Addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                                    ((dev_paired_p->bd_addr.nap & 0xff00) >> 8),
                                    (dev_paired_p->bd_addr.nap & 0x00ff),
                                    (dev_paired_p->bd_addr.uap),
                                    ((dev_paired_p->bd_addr.lap & 0xff0000) >> 16),
                                    ((dev_paired_p->bd_addr.lap & 0x00ff00) >> 8),
                                    (dev_paired_p->bd_addr.lap & 0x0000ff));
            }
        }
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_pair");
    }
    
    DS_OUTLOG("vs_btcm_pair_result_cb E");        
}
static void vs_btcm_security_user_confirm_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_security_passkey_notify_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_entry_security_keypress_notify_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_authorize_ind_notify_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_connect_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    srv_bt_cm_conn_res_struct * data  = (srv_bt_cm_conn_res_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DS_OUTLOG("vs_btcm_connect_complete_cb S");
    if (SRV_BT_CM_RESULT_SUCCESS != data->result)
    {
        ret_b = MMI_FALSE;
        DS_OUTLOG("vs_btcm_connect_complete_cb rsp not SRV_BT_CM_RESULT_SUCCESS");
    }
    else
    {
        ret_b = MMI_TRUE;
    }

    DS_OUTLOG("is dev conn [%d]", srv_bt_cm_is_dev_conn_active(&(sg_vs_btcm_ctx.target_dev_addr)));
    DS_OUTLOG("is profile conn [%d]", srv_bt_cm_is_profile_connected(SRV_BT_CM_OPPC_CONNECTION));
    {
    srv_bt_cm_connection_type conn_e;
    U8 conn_num = 0;
    S32 i = 0;
    srv_bt_cm_connect_struct * conn_p = NULL;
    U32 idx = 0;
    conn_num = srv_bt_cm_get_existed_conn_num();
    idx = srv_bt_cm_get_dev_index(&(sg_vs_btcm_ctx.target_dev_addr), SRV_BT_CM_ALL_DEV);
    DS_OUTLOG("vs_btcm_connect_complete_cb conn_num[%d], idx[%d]", conn_num, idx);
    for (i = 0; i < conn_num; i++)
    {
        conn_p = srv_bt_cm_get_existed_conn_info((U16)i);
        if (idx == conn_p->index_of_dev_list)
        {
            conn_e = srv_bt_cm_get_conn_type(conn_p->profile_id);
            
            DS_OUTLOG("vs_btcm_connect_complete_cb profile_id[%d], conn_e[%d]", conn_p->profile_id, conn_e);
        }
    }
    }
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_connect");
    DS_OUTLOG("vs_btcm_connect_complete_cb E");
}
static void vs_btcm_entry_disconnect_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_bt_cm_disconnect_ind_struct * data = (srv_bt_cm_disconnect_ind_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_entry_disconnect_complete_cb S");

    VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_delete");
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_entry_disconnect_complete_cb E");
}
static void vs_btcm_release_conn_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_release_conn_complete_cb S");
    VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_delete");
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_release_conn_complete_cb E");
}
static void vs_btcm_refresh_prof_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_refresh_service_list_struct * data = (srv_bt_cm_refresh_service_list_struct *)user_data;
    srv_bt_cm_dev_struct * dev_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_refresh_prof_complete_cb S");
    
    if (SRV_BT_CM_RESULT_SUCCESS == data->result)
    {
        dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&(sg_vs_btcm_ctx.target_dev_addr));
        if (NULL == dev_p)
        {
            DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_refresh_prof_complete_cb [srv_bt_cm_get_dev_info NULL]");
            VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_srvlist");
            return;
        }

        DS_OUTLOG("vs_btcm_refresh_prof_complete_cb listnum[%d]", dev_p->service_list_num);
        if (0 < dev_p->service_list_num)
        {
            U32 i = 0;
            memset(sg_vs_btcm_ctx.service_list, 0, sizeof(sg_vs_btcm_ctx.service_list));
            for (i = 0; i < dev_p->service_list_num; i++)
            {
                DS_OUTLOG("vs_btcm_refresh_prof_complete_cb [0x%u]", dev_p->service_list[i]);
                sg_vs_btcm_ctx.service_list[i] = dev_p->service_list[i];
            }
        }
        DS_OUTLOG("vs_btcm_refresh_prof_complete_cb Addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                            ((dev_p->bd_addr.nap & 0xff00) >> 8),
                            (dev_p->bd_addr.nap & 0x00ff),
                            (dev_p->bd_addr.uap),
                            ((dev_p->bd_addr.lap & 0xff0000) >> 16),
                            ((dev_p->bd_addr.lap & 0x00ff00) >> 8),
                            (dev_p->bd_addr.lap & 0x0000ff));
        
        
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_srvlist");
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_srvlist");
    }
    
    DS_OUTLOG("vs_btcm_srvlist 2 vs_btcm_refresh_prof_complete_cb E");
}

static void vs_btcm_unblock_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_mydev_del_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DS_OUTLOG("vs_btcm_mydev_del_complete_cb S");
    VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_delete");
    DS_OUTLOG("vs_btcm_mydev_del_complete_cb E");
}


static void vs_btcm_set_authorize_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DS_OUTLOG("vs_btcm_mydev_del_complete_cb S");
    VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_authorize");
    DS_OUTLOG("vs_btcm_mydev_del_complete_cb E");
}

static void vs_btcm_set_vis_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_visibility_struct *data = (srv_bt_cm_set_visibility_struct *)user_data;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    DS_OUTLOG("vs_btcm_set_vis_complete_cb S");

    ret_b = data->result ? MMI_TRUE : MMI_FALSE;
    
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_switch_vis");

    DS_OUTLOG("vs_btcm_set_vis_complete_cb E");

}
static void vs_btcm_set_name_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;
    srv_bt_cm_set_name_struct * data = (srv_bt_cm_set_name_struct *)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (SRV_BT_CM_RESULT_SUCCESS == data->result)
    {
        ret_b = MMI_TRUE;
    }
    
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_set_host_name");
}
#ifdef __MMI_BT_SHOW_AUTH_SETTING__  
static void vs_btcm_set_authentication_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
#endif
static void vs_btcm_sco_ind_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
static void vs_btcm_panic_ind_pre_process(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}

static void vs_btcm_read_remote_name_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_read_remote_dev_name_struct * remote_dev_name_p = (srv_bt_cm_read_remote_dev_name_struct * )user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DS_OUTLOG("vs_btcm_read_remote_name_cb S");
    if (remote_dev_name_p->dev_addr)
    {
        DS_OUTLOG("vs_btcm_read_remote_name_cb Addr:0x%02x:%02x:%02x:%02x:%02x:%02x", 
                        ((remote_dev_name_p->dev_addr->nap & 0xff00) >> 8),
                        (remote_dev_name_p->dev_addr->nap & 0x00ff),
                        (remote_dev_name_p->dev_addr->uap),
                        ((remote_dev_name_p->dev_addr->lap & 0xff0000) >> 16),
                        ((remote_dev_name_p->dev_addr->lap & 0x00ff00) >> 8),
                        (remote_dev_name_p->dev_addr->lap & 0x0000ff));
        VS_CASE_BTCM_FINISHED(MMI_TRUE, 0, L"vs_btcm_read_remote_name");
    }
    else
    {
        VS_CASE_BTCM_FINISHED(MMI_FALSE, 0, L"vs_btcm_read_remote_name");
    }
    DS_OUTLOG("vs_btcm_read_remote_name_cb E");
}

#if defined __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
static void vs_btcm_set_limit_vis_complete_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_limit_discoverable_mode_struct * limit_p = (srv_bt_cm_set_limit_discoverable_mode_struct *)user_data;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    
    DS_OUTLOG("vs_btcm_set_limit_vis_complete_cb S");
    if (SRV_BT_CM_RESULT_SUCCESS == limit_p->result)
    {
        ret_b = MMI_TRUE;
    }
    else
    {
        ret_b = MMI_FALSE;
    }
    
    VS_CASE_BTCM_FINISHED(ret_b, 0, L"vs_btcm_set_limit_vis");
    DS_OUTLOG("vs_btcm_set_limit_vis_complete_cb E");
}
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
static void vs_btcm_chip_status_ind_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
}
#endif

#endif /* __MMI_BT_SUPPORT__ */

#endif 
