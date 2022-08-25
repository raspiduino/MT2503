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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   avk_framework_ui.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 *Jia Luo (mtk80935)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__  
extern "C"
{
#include "mmi_features.h"
#include "GlobalResDef.h"
#include "wgui_categories.h"
#include "wgui_categories_list.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_popup.h"
#include "GpioSrvGprot.h"
#include "CommonScreens.h"
#include "mmi_rp_app_sdk_test_def.h"
}
#include "avk_framework_core.h"
#include "avk_framework_ui.h"
#include "avk_framework_log.h"

extern "C" void gui_touch_feedback_enable_tone_internal(void);
extern "C" void gui_touch_feedback_disable_tone_internal(void);
extern "C" void gui_touch_feedback_enable_vibrate_internal(void);
extern "C" void gui_touch_feedback_disable_vibrate_internal(void);





#define AVK_FRAMEWORK_SET_GOBACK SETRIGHTKEY(avk_framework_go_back)


#define AVK_FRAMEWORK_MAX_LIST_NUM    60

#define AVK_FRAMEWORK_AUTO_CASE_TIME  0xabce
#define AVK_FRAMEWORK_AUTO_CASE_TIME_DONE  0xabcf


#define AVK_FRAMEWORK_TEST_ALL_NORMAL             0
//#define AVK_FRAMEWORK_TEST_ALL_REGRESSIVE         1
#define AVK_FRAMEWORK_TEST_ALL_ABORT_REGRESSIVE   1


typedef struct
{
    U8          type;
    void*       content;
    p_test_fun  leftkey_handle;
    p_test_fun  rightkey_handle;    
}avk_manual_param;

typedef struct
{
    avk_test_case*  avk_framework_re_in_item ;
    avk_test_case*  avk_framework_test_all_item;
    U16             avk_framework_scr_id;
    U16             avk_framework_auto_scr_id;
    U8              avk_framework_foreground;
    U8              avk_framework_stop_auto_process;
    U8              avk_framework_test_all_type; //0 :normal ; 1:regressive
    U8              avk_framework_manual_hide;
    void*           avk_framework_manual_param;
}avk_framework_fw_ctx;

static avk_framework_fw_ctx g_avk_framework_fw_ctx = {NULL, NULL, GRP_ID_AVK + 1, MMI_FALSE,0,AVK_FRAMEWORK_TEST_ALL_NORMAL,0,NULL};

void avk_framework_go_back(void)
{
//    g_avk_framework_ctx.item = g_avk_framework_ctx.item->parent;
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  vs_tfw_highlight
 * DESCRIPTION
 *  test framework hightlight function
 * PARAMETERS
 *  index       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_framework_highlight(S32 index)
{
    S32 i = 0;
    avk_test_case* test_case = g_avk_framework_ctx.item->first_child;
    for(;i<index;i++)
    {
        test_case = test_case->next;
    }
    SETLEFTKEY(test_case->test_fun);
}

/*****************************************************************************
 * FUNCTION
 *  vs_tfw_leave_proc
 * DESCRIPTION
 *  test framework leave screen process
 * PARAMETERS
 *  param       [IN]                 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret avk_framework_leave_scr(mmi_event_struct *param)
{
    if (EVT_ID_SCRN_DEINIT == param->evt_id)
    {
        g_avk_framework_fw_ctx.avk_framework_scr_id--; 
//        g_avk_framework_ctx.item = g_avk_framework_ctx.item->parent;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_entry_list_scr_ext
 * DESCRIPTION
 *  test framework list screen true entry function
 * PARAMETERS
 *  data       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/

static void avk_framework_entry_list_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
    
    U16 index_num = 0;
    U8 *guiBuffer;
    U8 *itemlist[AVK_FRAMEWORK_MAX_LIST_NUM];
    avk_test_case* test_case,*item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (avk_test_case*)data->user_data;
    g_avk_framework_ctx.item = item;
    test_case = item->first_child;
    while (test_case && AVK_FRAMEWORK_IS_ITEM(test_case))
    {
        itemlist[index_num++] = (U8*)test_case->test_name;
        test_case=test_case->next;
    }

    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_list_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();        /* get current guibuffer */

    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_scr);
    
    RegisterHighlightHandler(avk_framework_highlight);    /* register highlight handler */

    
    
    /* show category */
    ShowCategory36Screen_ext(
        (U8*)item->test_name,
        0,
        (U8*)get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        (U8*)get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        index_num,
        itemlist,
        0,
        guiBuffer);

    AVK_FRAMEWORK_SET_GOBACK;
}

void avk_framework_entry_list_scr(avk_test_case* item)
{   
    MMI_ID scr_id;

    scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, scr_id, 
                    (FuncPtr)avk_framework_entry_list_scr_ext, (void*)item);
}



static void avk_framework_auto_case_time_cb()
{
    U8 str[256];
    U16 percent;   
    MMI_ID group_id, scr_id;
    
    StopTimer(AVK_FRAMEWORK_AUTO_CASE_TIME);

    if (g_avk_framework_fw_ctx.avk_framework_stop_auto_process || !g_avk_framework_fw_ctx.avk_framework_foreground)
    {
        return;
    }

    mmi_frm_get_active_scrn_id(&group_id, &scr_id);
    if (g_avk_framework_fw_ctx.avk_framework_auto_scr_id != scr_id && GRP_ID_AVK == group_id)
    {
        return;
    }
    
    if (0 == g_avk_framework_ctx.auto_case_num)
    {
        mmi_frm_scrn_close_active_id();
        return;
    }
    
    kal_wsprintf((WCHAR*)str,"Auto cases: %d / %d",g_avk_framework_ctx.current_num,g_avk_framework_ctx.auto_case_num);
    percent = (U16)g_avk_framework_ctx.current_num*100 / g_avk_framework_ctx.auto_case_num;
    if (percent > 100)
    {
        return;
    }
    UpdateCategory402Value(percent, (U8*)str);
    StartTimer(AVK_FRAMEWORK_AUTO_CASE_TIME,200,avk_framework_auto_case_time_cb);
}


static void avk_framework_entry_auto_cases_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
//    U8 *guiBuffer;
    U8 str[256]="";
    U16 percent = 0;
    avk_test_case* item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    item = (avk_test_case*)data->user_data;
    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_auto_cases_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

//    guiBuffer = mmi_frm_scrn_get_active_gui_buf();    

    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_scr);

    if (g_avk_framework_ctx.auto_case_num > 0)
    {
        kal_wsprintf((WCHAR*)str,"Auto cases: %d / %d",g_avk_framework_ctx.current_num,g_avk_framework_ctx.auto_case_num);
        percent = (U16)g_avk_framework_ctx.current_num*100 / g_avk_framework_ctx.auto_case_num;
    }
    ShowCategory402Screen((U8*)(item)->test_name,
                            0,
                            0,
                            0,
                            0,
                            0,
                            0,
                            percent,
                            (U8*)str);

    StartTimer(AVK_FRAMEWORK_AUTO_CASE_TIME,500,avk_framework_auto_case_time_cb);   
}

void avk_framework_entry_auto_cases_scr(avk_test_case* item)
{   
    g_avk_framework_fw_ctx.avk_framework_auto_scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, g_avk_framework_fw_ctx.avk_framework_auto_scr_id, 
                    (FuncPtr)avk_framework_entry_auto_cases_scr_ext, (void*)item);
}

static void avk_framework_select_yes(void)
{
    mmi_frm_scrn_close_active_id();  
    avk_framework_invoke_cases_regression(g_avk_framework_fw_ctx.avk_framework_test_all_item,
                    AVK_FRAMEWORK_NORMAL_REGRESSION);
    
    if (!AVK_FRAMEWORK_IS_MANUAL_ITEM(g_avk_framework_fw_ctx.avk_framework_test_all_item))
    {
        //auto cases or empty case!        
        avk_framework_entry_auto_cases_scr(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    }
}

static void avk_framework_select_no(void)
{
    mmi_frm_scrn_close_active_id();  
    avk_framework_invoke_cases(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    
    if (!AVK_FRAMEWORK_IS_MANUAL_ITEM(g_avk_framework_fw_ctx.avk_framework_test_all_item))
    {
        //auto cases or empty case!        
        avk_framework_entry_auto_cases_scr(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    }
}

static void avk_framework_entry_select_test_type_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
    U8 *guiBuffer;
//    avk_test_case* item;
    UI_string_type str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_select_test_type_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();    
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_scr);

    str = (UI_string_type)L"Do you want to do regression test?";

    ShowCategory366Screen((UI_string_type)L"Select Test Type",
                            0,
                            (UI_string_type)L"Yes",
                            0,
                            (UI_string_type)L"No",
                            0,
                            str,
                            0,
                            guiBuffer);
    
    SETLEFTKEY(avk_framework_select_yes);
    SETRIGHTKEY(avk_framework_select_no);
}

void avk_framework_entry_select_test_type_scr()
{
    MMI_ID scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, scr_id, 
                    (FuncPtr)avk_framework_entry_select_test_type_scr_ext, NULL);
    
}


static void avk_framework_test_all_ok()
{
    U32 res = 0;
    
    g_avk_framework_fw_ctx.avk_framework_stop_auto_process = MMI_FALSE;
    mmi_frm_scrn_close_active_id();     

    if (AVK_FRAMEWORK_IS_TYPE(g_avk_framework_fw_ctx.avk_framework_test_all_item,AVK_ITEM_ITEM_SPECIAL))
    {
        avk_framework_invoke_cases_special(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    }
    else if (AVK_FRAMEWORK_TEST_ALL_NORMAL == g_avk_framework_fw_ctx.avk_framework_test_all_type)
    {
        if (avk_framework_log_is_log_exist(g_avk_framework_fw_ctx.avk_framework_test_all_item))
        {
            avk_framework_entry_select_test_type_scr();
            return ;
        }
        res = avk_framework_invoke_cases(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    }
//    else if (AVK_FRAMEWORK_TEST_ALL_REGRESSIVE == g_avk_framework_fw_ctx.avk_framework_test_all_type)
//    {
//        res = avk_framework_invoke_cases_regression(g_avk_framework_fw_ctx.avk_framework_test_all_item,AVK_FRAMEWORK_NORMAL_REGRESSION);
//    }
    else if (AVK_FRAMEWORK_TEST_ALL_ABORT_REGRESSIVE == g_avk_framework_fw_ctx.avk_framework_test_all_type)
    {
        res = avk_framework_invoke_cases_regression(g_avk_framework_fw_ctx.avk_framework_test_all_item,AVK_FRAMEWORK_ABORT_REGRESSION);
    }

    if ((U32)-1 == res)
    {
        mmi_display_popup((UI_string_type)L"No Log File!",MMI_EVENT_FAILURE);        
        return;
    }
    
    if (!AVK_FRAMEWORK_IS_MANUAL_ITEM(g_avk_framework_fw_ctx.avk_framework_test_all_item))
    {
        //auto cases or empty case!        
        avk_framework_entry_auto_cases_scr(g_avk_framework_fw_ctx.avk_framework_test_all_item);
    }
          
}


static void avk_framework_entry_test_all_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
    U8 *guiBuffer;
    avk_test_case* item;
    UI_string_type str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    item = (avk_test_case*)data->user_data;
    g_avk_framework_fw_ctx.avk_framework_test_all_item = item;
    
    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_test_all_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();    
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_scr);

    switch (g_avk_framework_fw_ctx.avk_framework_test_all_type)
    {
    case AVK_FRAMEWORK_TEST_ALL_NORMAL:
        str = (UI_string_type)L"Ready to test?";
        break;
//    case AVK_FRAMEWORK_TEST_ALL_REGRESSIVE:
//        str = (UI_string_type)L"Ready to regression test?";
//        break;
    case AVK_FRAMEWORK_TEST_ALL_ABORT_REGRESSIVE:
        str = (UI_string_type)L"Ready to abort regression test?";
        break;
    default:
        break;
    }

    ShowCategory366Screen((UI_string_type)item->test_name,
                            0,
                            (UI_string_type)L"OK",
                            0,
                            (UI_string_type)L"Cancel",
                            0,
                            str,
                            0,
                            guiBuffer);
    
    SETLEFTKEY(avk_framework_test_all_ok);
    SETRIGHTKEY(mmi_frm_scrn_close_active_id);
}

void avk_framework_entry_test_all_scr(U32 item_id)
{
    MMI_ID scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AVK_FRAMEWORK_INVALID_CASE_ID == item_id)
    {
        return;
    }
    //for re in running cases
    g_avk_framework_fw_ctx.avk_framework_re_in_item = AVK_GET_CASE_BY_ID(item_id);
 //   srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, scr_id, 
                    (FuncPtr)avk_framework_entry_test_all_scr_ext, (void*)AVK_GET_CASE_BY_ID(item_id));
    
}

void avk_framework_pass(void)
{
    if (g_avk_framework_ctx.leftkey_handle)
    {
        (*g_avk_framework_ctx.leftkey_handle)();
    }
    mmi_frm_scrn_close_active_id();
    
    g_avk_framework_ctx.b_current_result = AVK_PASS;
    avk_framework_asyn_invoke_next_case(0);
}

void avk_framework_fail(void)
{
    if (g_avk_framework_ctx.rightkey_handle)
    {
        (*g_avk_framework_ctx.rightkey_handle)();
    }
    mmi_frm_scrn_close_active_id();
    g_avk_framework_ctx.b_current_result = AVK_FAIL;
    avk_framework_asyn_invoke_next_case(0);
}

static void avk_framework_leftkey_handle(void)
{
    mmi_frm_scrn_close_active_id();
    if (g_avk_framework_ctx.leftkey_handle)
    {
        (*g_avk_framework_ctx.leftkey_handle)();
    }
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
#endif
static mmi_ret avk_framework_leave_manual_scr(mmi_event_struct *param)
{
    if (EVT_ID_SCRN_DEINIT == param->evt_id)
    {
        avk_framework_free(param->user_data);
        g_avk_framework_fw_ctx.avk_framework_scr_id--; 
    }
    return MMI_RET_OK;
}

static void avk_framework_entry_manual_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
    U8 *guiBuffer;
    avk_manual_param* param;
    WCHAR name_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    param = (avk_manual_param*)data->user_data;
    
    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_manual_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();    
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_manual_scr);

    g_avk_framework_ctx.leftkey_handle = param->leftkey_handle;
    g_avk_framework_ctx.rightkey_handle = param->rightkey_handle;

    mmi_asc_to_ucs2((CHAR *)name_buf,(CHAR *)g_avk_framework_ctx.current_case->test_name);
    
    if (AVK_FRAMEWORK_MANUAL_TIPS_SCR == param->type) 
    {
        ShowCategory79Screen((UI_string_type)name_buf,
    						0,
    						(UI_string_type)L"OK",
                            0,
                            (UI_string_type)L"",
                            0,
                            MMI_TRUE,
                            MMI_TRUE,
                            (UI_buffer_type)param->content,
                            2*mmi_wcslen((WCHAR*)param->content)+2,
                            guiBuffer);

		
/*        ShowCategory366Screen((UI_string_type)name_buf,
                            0,
                            (UI_string_type)L"OK",
                            0,
                            (UI_string_type)L"",
                            0,
                            (UI_string_type)param->content,
                            0,
                            guiBuffer);*/

        SETLEFTKEY(avk_framework_leftkey_handle);
    }
    else if (AVK_FRAMEWORK_MANUAL_PASS_FAIL_SCR == param->type)
    {
    	ShowCategory79Screen((UI_string_type)name_buf,
    						0,
    						(UI_string_type)L"Pass",
                            0,
                            (UI_string_type)L"Fail",
                            0,
                            MMI_TRUE,
                            MMI_TRUE,
                            (UI_buffer_type)param->content,
                            2*mmi_wcslen((WCHAR*)param->content)+2,
                            guiBuffer);

 /*       ShowCategory366Screen((UI_string_type)name_buf,
                            0,
                            (UI_string_type)L"Pass",
                            0,
                            (UI_string_type)L"Fail",
                            0,
                            (UI_string_type)param->content,
                            0,
                            guiBuffer);*/
        
        SETLEFTKEY(avk_framework_pass);
        SETRIGHTKEY(avk_framework_fail);                            
    }
}

void avk_framework_entry_manual_scr(U8 type, void* content, void* leftkey_handle, void* rightkey_handle)
{
    MMI_ID scr_id;
    avk_manual_param* param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    
    param = (avk_manual_param*)avk_framework_malloc(sizeof(avk_manual_param));
    if (!param)
    {
        return;
    }
    param->type = type;
    param->content = content;
    param->leftkey_handle = (p_test_fun)leftkey_handle;
    param->rightkey_handle = (p_test_fun)rightkey_handle;

    if (!g_avk_framework_fw_ctx.avk_framework_foreground)
    {
        //backgroud running, do not show screen!!
        g_avk_framework_fw_ctx.avk_framework_manual_hide = MMI_TRUE;
        g_avk_framework_fw_ctx.avk_framework_manual_param = param;
        return;
    }

    g_avk_framework_fw_ctx.avk_framework_manual_hide = MMI_FALSE;
    
    scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, scr_id, 
                    (FuncPtr)avk_framework_entry_manual_scr_ext, (void*)param);
    
}

static void avk_framework_setting_normal(void)
{
    g_avk_framework_fw_ctx.avk_framework_test_all_type = AVK_FRAMEWORK_TEST_ALL_NORMAL;
    mmi_frm_scrn_close_active_id();
}

/*
static void avk_framework_setting_regressive(void)
{
    g_avk_framework_fw_ctx.avk_framework_test_all_type = AVK_FRAMEWORK_TEST_ALL_REGRESSIVE;  
    mmi_frm_scrn_close_active_id();
}
*/
static void avk_framework_setting_abort_regressive(void)
{
    g_avk_framework_fw_ctx.avk_framework_test_all_type = AVK_FRAMEWORK_TEST_ALL_ABORT_REGRESSIVE;  
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  vs_tfw_highlight
 * DESCRIPTION
 *  test framework hightlight function
 * PARAMETERS
 *  index       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_framework_setting_highlight(S32 index)
{

    switch (index)
    {
    case 0:
        SETLEFTKEY(avk_framework_setting_normal);
        break;
//    case 1:
//        SETLEFTKEY(avk_framework_setting_regressive);
        break;
    case 1:
        SETLEFTKEY(avk_framework_setting_abort_regressive);
        break;        
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_framework_entry_list_scr_ext
 * DESCRIPTION
 *  test framework list screen true entry function
 * PARAMETERS
 *  data       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_framework_entry_setting_scr_ext(mmi_scrn_essential_struct* data)
{
    MMI_BOOL enter_ret;
    
    U16 index_num = 0;
    U8 *guiBuffer;
    U8 *itemlist[AVK_FRAMEWORK_MAX_LIST_NUM];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    itemlist[index_num++] = (U8*)L"test normal";
//    itemlist[index_num++] = (U8*)L"test regressive";
    itemlist[index_num++] = (U8*)L"test abort case";
    
    enter_ret = mmi_frm_scrn_enter(GRP_ID_AVK, data->scrn_id, 
                    (FuncPtr)NULL, (FuncPtr)avk_framework_entry_setting_scr_ext, MMI_FRM_FULL_SCRN);

    if (enter_ret == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();        /* get current guibuffer */

    mmi_frm_scrn_set_leave_proc(GRP_ID_AVK, data->scrn_id, avk_framework_leave_scr);
    
    RegisterHighlightHandler(avk_framework_setting_highlight);    /* register highlight handler */    
    
    /* show category */
    ShowCategory36Screen_ext(
        (U8*)L"Settings",
        0,
        (U8*)get_string(STR_GLOBAL_OK),
        get_image(IMG_GLOBAL_OK),
        (U8*)get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        index_num,
        itemlist,
        g_avk_framework_fw_ctx.avk_framework_test_all_type,
        guiBuffer);

    AVK_FRAMEWORK_SET_GOBACK;
}

void avk_framework_entry_setting_scr(void)
{   
    MMI_ID scr_id;

    scr_id = g_avk_framework_fw_ctx.avk_framework_scr_id++;
    mmi_frm_scrn_first_enter(GRP_ID_AVK, scr_id, 
                    (FuncPtr)avk_framework_entry_setting_scr_ext, (void*)NULL);
}


static void avk_framework_test_done(void)
{
    g_avk_framework_ctx.b_running = MMI_FALSE;
 //   srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}

static void avk_framework_auto_test_done_cb(void)
{
    StopTimer(AVK_FRAMEWORK_AUTO_CASE_TIME_DONE);
    mmi_frm_scrn_close(GRP_ID_AVK,g_avk_framework_fw_ctx.avk_framework_auto_scr_id);
}
static void avk_framework_auto_test_done(void)
{
    g_avk_framework_fw_ctx.avk_framework_stop_auto_process = MMI_TRUE;
    if (g_avk_framework_fw_ctx.avk_framework_foreground)
    {
        StopTimer(AVK_FRAMEWORK_AUTO_CASE_TIME_DONE);
        StartTimer(AVK_FRAMEWORK_AUTO_CASE_TIME_DONE,0,avk_framework_auto_test_done_cb);        
    }        
}

/*****************************************************************************
 * FUNCTION
 *  vs_tfw_entry_list_scr
 * DESCRIPTION
 *  test framework list screen entry function
 * PARAMETERS
 *  scn_id       [IN] : screen id
 * RETURNS
 *  void
 *****************************************************************************/
void avk_framework_entry_scr(U32 item_id)
{
    avk_test_case* item = AVK_GET_CASE_BY_ID(item_id);
    
    if (AVK_FRAMEWORK_IS_UI_ITEM(item))
    {
        avk_framework_entry_list_scr(item);
    }
    else
    {
        avk_framework_entry_test_all_scr(item_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret avk_framework_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            g_avk_framework_fw_ctx.avk_framework_foreground = MMI_TRUE;
            if (g_avk_framework_fw_ctx.avk_framework_manual_hide)
            {
                mmi_frm_scrn_first_enter(GRP_ID_AVK, ++g_avk_framework_fw_ctx.avk_framework_scr_id, 
                        (FuncPtr)avk_framework_entry_manual_scr_ext, 
                        (void*)g_avk_framework_fw_ctx.avk_framework_manual_param);
            }
            break;
        case EVT_ID_GROUP_INACTIVE:
            g_avk_framework_fw_ctx.avk_framework_foreground = MMI_FALSE;
            break;
        case EVT_ID_GROUP_DEINIT:            
            g_avk_framework_fw_ctx.avk_framework_stop_auto_process = MMI_TRUE;
            if (!g_avk_framework_ctx.b_running)
            {
                avk_framework_core_deinit();
            }
            gui_touch_feedback_enable_tone_internal();
            gui_touch_feedback_enable_vibrate_internal();
            break;
    }
    return ret;
}

void vak_framework_entry_main_asm_callback()
{
    avk_framework_core_init(vak_framework_entry_main_asm_callback);
    avk_framework_log_init();
    
    avk_framework_entry_scr((U32)g_avk_framework_ctx.root);    
}
void avk_framework_entry_main()
{  
    g_avk_framework_ctx.auto_case_done_handle = avk_framework_auto_test_done;
    g_avk_framework_ctx.all_case_done_handle = avk_framework_test_done;

    g_avk_framework_fw_ctx.avk_framework_foreground = MMI_TRUE;
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AVK, avk_framework_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_AVK, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //if test all is running ,we will re in
    if (g_avk_framework_ctx.b_running)
    {
        avk_test_case* tmp_item[AVK_FRAMEWORK_MAX_ITEM_DEEP];
        avk_test_case* item;
        S32 i = 0;
        item = g_avk_framework_fw_ctx.avk_framework_re_in_item;
        ASSERT(g_avk_framework_fw_ctx.avk_framework_re_in_item);
        do
        {
            tmp_item[i++] = item;
            item = item->parent;
        }while (item && item != g_avk_framework_ctx.root);
        

        avk_framework_entry_scr((U32)g_avk_framework_ctx.root);
        for (;i>0;i--)
        {
            avk_framework_entry_scr((U32)tmp_item[i-1]);
        }
                
        if (AVK_FRAMEWORK_IS_AUTO_CASE(g_avk_framework_ctx.current_case))
        {
            //if auto cases is running
            avk_framework_entry_auto_cases_scr(tmp_item[0]);
        }
        else
        {
            //manual cases
            avk_framework_re_invoke_case();
        }
    }
    else
    {
        //disable touch feedback
        gui_touch_feedback_disable_tone_internal();
        gui_touch_feedback_disable_vibrate_internal();
        //
        if (1 == avk_framework_core_init(vak_framework_entry_main_asm_callback))
        {
            return;
        };
        avk_framework_log_init();
        
        avk_framework_entry_scr((U32)g_avk_framework_ctx.root);
    }
}

extern "C"
{
/*
#include "syscomp_config.h"

kal_bool vs_sys_task_001_create(comptask_handler_struct **handle)
{
    return (kal_bool)0;
}
*/
void mmi_entry_sdk_test_scr(void)
{
    avk_framework_entry_main();
}
}

void avk_framework_draw_title(WCHAR* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, str_w, str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 0, LCD_WIDTH, AVK_FRAMEWORK_SOFTKEY_HEIGHT, GDI_COLOR_BLACK);

    gui_set_font(&MMI_medium_font);
    gui_set_text_color(gui_color(255, 255, 255));
    gui_measure_string((PU16)title, &str_w, &str_h);
    x = (LCD_WIDTH - str_w)/2;
    y = (AVK_FRAMEWORK_SOFTKEY_HEIGHT - str_h)/2;
    gui_move_text_cursor(x, y);
    gui_print_text((PU16)title);

}

/*****************************************************************************
* FUNCTION
*  mmi_vs_framework_pen_down_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void avk_framework_pen_down_hdlr(mmi_pen_point_struct pos)
{
		/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*lsk*/
    if ((pos.x < AVK_FRAMEWORK_SOFTKEY_WIDTH) &&(pos.x > 0)
    	&&(pos.y > LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
    {
//		ptr =GetKeyHandler(KEY_LSK, KEY_EVENT_UP);
		execute_softkey_function(1,MMI_LEFT_SOFTKEY);
//		if(ptr != NULL)
//		ptr();
        return;
    }
    
    /*rsk*/
    if ((pos.x < LCD_WIDTH)&& (pos.x > LCD_WIDTH - AVK_FRAMEWORK_SOFTKEY_WIDTH)&&
    	(pos.y >LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT)&&(pos.y <LCD_HEIGHT))
    {
        execute_softkey_function(1,MMI_RIGHT_SOFTKEY);
//		ptr =GetKeyHandler(KEY_RSK, KEY_EVENT_UP);
//		if(ptr != NULL)
//		ptr();
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_tfw_draw_softkey
 * DESCRIPTION
 *  find the first case
 * PARAMETERS
 *  key_type        [IN]        
 *  key_content     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_framework_draw_softkey(U16 key_type, U16 key_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x =0 , y, str_w, str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(gui_color(255, 255, 255));
    gui_measure_string((PU16) GetString(key_content), &str_w, &str_h);
    y = LCD_HEIGHT - (AVK_FRAMEWORK_SOFTKEY_HEIGHT - str_h/2);
    if (key_type == KEY_LSK)
    {
        x = (AVK_FRAMEWORK_SOFTKEY_WIDTH - str_w)/2;
        gdi_draw_solid_rect(0, LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT, AVK_FRAMEWORK_SOFTKEY_WIDTH, LCD_HEIGHT, GDI_COLOR_BLACK);
    }
    else if (key_type == KEY_RSK)
    {
        x = LCD_WIDTH - (AVK_FRAMEWORK_SOFTKEY_WIDTH + str_w)/2;
        gdi_draw_solid_rect(
            LCD_WIDTH - AVK_FRAMEWORK_SOFTKEY_WIDTH,
            LCD_HEIGHT - AVK_FRAMEWORK_SOFTKEY_HEIGHT,
            LCD_WIDTH,
            LCD_HEIGHT,
            GDI_COLOR_BLACK);
    }
    
    gui_move_text_cursor(x, y);
    gui_print_bordered_text((PU16) GetString(key_content));
#ifdef __MMI_TOUCH_SCREEN__    
	mmi_pen_register_down_handler(avk_framework_pen_down_hdlr);
#endif	    
}

#include "avk_framework_cases.cpp"
#endif
