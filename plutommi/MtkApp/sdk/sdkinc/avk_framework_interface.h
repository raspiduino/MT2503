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
 *   avk_framework_interface.h
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

/*****************************************************************************
 * FUNCTION
 * AVK_ADD_ROOT
 * DESCRIPTION
 *  Framework internal use
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/ 
#define AVK_ADD_ROOT(root_id, root_name) \
    extern const U32 g_avk_framework_##root_id;\
    void avk_framework_##root_id##_entry_scr()\
    {\
        avk_framework_entry_scr(g_avk_framework_##root_id);\
    }\
    const U32 g_avk_framework_##root_id = avk_framework_add_test(AVK_ITEM_ITEM,(void*)avk_framework_##root_id##_entry_scr,(WCHAR*)root_name,0) ;

/*****************************************************************************
 * FUNCTION
 * AVK_SETTING
 * DESCRIPTION
 *  Framework internal use
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_SETTING(parent_id) \
    extern const U32 g_avk_framework_setting_##parent_id;\
    const U32 g_avk_framework_setting_##parent_id = avk_framework_add_test(AVK_ITEM_ITEM,(void*)avk_framework_entry_setting_scr,(WCHAR*)L"Settings", g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_ADD_ITEM_EX
 * DESCRIPTION
 *  Add a test item in UI, function list will classify by this. Mainly Framework uses
 * PARAMETERS
 *  item_id         :   [IN]        item id
 *  item_name    :   [IN]        item_name, UCS2
 *  parent_id      :   [IN]        parent item id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ADD_ITEM_SPECIAL_ROOT(item_id, item_name, parent_id) \
        extern const U32 g_avk_framework_##item_id;\
        void avk_framework_##item_id##_entry_scr()\
        {\
            avk_framework_entry_scr(g_avk_framework_##item_id);\
        }\
        const U32 g_avk_framework_##item_id = avk_framework_add_test(AVK_ITEM_ITEM_SP_ROOT,(void*)avk_framework_##item_id##_entry_scr,(WCHAR*)item_name, g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_TEST_ALL
 * DESCRIPTION
 *  Add a test all item
 * PARAMETERS
 *  parent_id      :   [IN]        parent item id
 * RETURNS
 *  
 *****************************************************************************/    
#define AVK_TEST_ALL(parent_id) \
    extern const U32 g_avk_framework_test_all_##parent_id;\
    void avk_framework_test_all_##parent_id()\
    {\
        avk_framework_entry_test_all_scr(g_avk_framework_##parent_id);\
    }\
    const U32 g_avk_framework_test_all_##parent_id = avk_framework_add_test(AVK_ITEM_ITEM,(void*)avk_framework_test_all_##parent_id,(WCHAR*)L"Test all", g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_ADD_ITEM
 * DESCRIPTION
 *  Add a test item in UI
 * PARAMETERS
 *  item_id         :   [IN]        item id
 *  item_name    :   [IN]        item_name, UCS2
 *  parent_id      :   [IN]        parent item id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ADD_ITEM(item_id, item_name, parent_id) \
    extern const U32 g_avk_framework_##item_id;\
    void avk_framework_##item_id##_entry_scr()\
    {\
        avk_framework_entry_scr(g_avk_framework_##item_id);\
    }\
    const U32 g_avk_framework_##item_id = avk_framework_add_test(AVK_ITEM,(void*)avk_framework_##item_id##_entry_scr,(WCHAR*)item_name, g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_ADD_ITEM_EX
 * DESCRIPTION
 *  Add a test item in UI, function list will classify by this. Mainly Framework uses
 * PARAMETERS
 *  item_id         :   [IN]        item id
 *  item_name    :   [IN]        item_name, UCS2
 *  parent_id      :   [IN]        parent item id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ADD_ITEM_EX(item_id, item_name, parent_id) \
    extern const U32 g_avk_framework_##item_id;\
    void avk_framework_##item_id##_entry_scr()\
    {\
        avk_framework_entry_scr(g_avk_framework_##item_id);\
    }\
    const U32 g_avk_framework_##item_id = avk_framework_add_test(AVK_ITEM_ITEM_EX,(void*)avk_framework_##item_id##_entry_scr,(WCHAR*)item_name, g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_ADD_ITEM_EX
 * DESCRIPTION
 *  Add a test item in UI, function list will classify by this. Mainly Framework uses
 * PARAMETERS
 *  item_id         :   [IN]        item id
 *  item_name    :   [IN]        item_name, UCS2
 *  parent_id      :   [IN]        parent item id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ADD_ITEM_SPECIAL(item_id, item_name, parent_id) \
        extern const U32 g_avk_framework_##item_id;\
        void avk_framework_##item_id##_entry_scr()\
        {\
            avk_framework_entry_scr(g_avk_framework_##item_id);\
        }\
        const U32 g_avk_framework_##item_id = avk_framework_add_test(AVK_ITEM_ITEM_SPECIAL,(void*)avk_framework_##item_id##_entry_scr,(WCHAR*)item_name, g_avk_framework_##parent_id) ;

/*****************************************************************************
 * FUNCTION
 * AVK_CASE
 * DESCRIPTION
 *  Add a auto test case
 * PARAMETERS
 *  case_id         :   [IN]        case id
 *  parent_id      :   [IN]        parent id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_CASE(case_id, parent_id) \
    void avk_framework_##case_id(void);\
    const U32 g_avk_framework_##case_id = avk_framework_add_test(AVK_CASE_AUTO,(void*)avk_framework_##case_id,(WCHAR*)#case_id, g_avk_framework_##parent_id) ;\
    void avk_framework_##case_id()

/*****************************************************************************
 * FUNCTION
 * AVK_ASYN_CASE
 * DESCRIPTION
 *  Add a asynchronous auto case
 * PARAMETERS
 *  case_id         :   [IN]        case id
 *  parent_id      :   [IN]        parent id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ASYN_CASE(case_id, parent_id) \
    void avk_framework_##case_id(void);\
    const U32 g_avk_framework_##case_id = avk_framework_add_test(AVK_CASE_AUTO_ASYN,(void*)avk_framework_##case_id,(WCHAR*)#case_id, g_avk_framework_##parent_id) ;\
    void avk_framework_##case_id()  

/*****************************************************************************
 * FUNCTION
 * AVK_MANUAL_CASE
 * DESCRIPTION
 *  Add a manual case
 * PARAMETERS
 *  case_id         :   [IN]        case id
 *  parent_id      :   [IN]        parent id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_MANUAL_CASE(case_id, parent_id) \
    void avk_framework_##case_id(void);\
    extern const U32 g_avk_framework_##case_id;\
    const U32 g_avk_framework_##case_id = avk_framework_add_test(AVK_CASE_MANUAL,(void*)avk_framework_##case_id,(WCHAR*)#case_id, g_avk_framework_##parent_id) ;\
    void avk_framework_##case_id()

/*****************************************************************************
 * FUNCTION
 * AVK_MANUAL_CASE
 * DESCRIPTION
 *  Add a manual case
 * PARAMETERS
 *  case_id         :   [IN]        case id
 *  parent_id      :   [IN]        parent id 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_SPECIAL_CASE(case_id, parent_id) \
    void avk_framework_##case_id(void);\
    extern const U32 g_avk_framework_##case_id;\
    const U32 g_avk_framework_##case_id = avk_framework_add_test(AVK_CASE_SPECIAL,(void*)avk_framework_##case_id,(WCHAR*)#case_id, g_avk_framework_##parent_id) ;\
    extern const U32 g_avk_framework_##case_id##_spcial_item;\
    void avk_framework_##case_id##_entry_scr()\
    {\
        avk_framework_entry_scr(g_avk_framework_##case_id##_spcial_item);\
    }\
    const U32 g_avk_framework_##case_id##_spcial_item = avk_framework_add_test(AVK_ITEM_ITEM_SPECIAL,(void*)avk_framework_##case_id##_entry_scr,\
                                                            (WCHAR*)((avk_test_case*)g_avk_framework_##case_id)->parent->test_name, (U32)g_avk_framework_ctx.root_special) ;\
    const U32 g_avk_framework_##case_id##_sp = avk_framework_add_test(AVK_CASE_SPECIAL,(void*)avk_framework_##case_id,(WCHAR*)#case_id,\
                                                                        g_avk_framework_##case_id##_spcial_item);\
    void avk_framework_##case_id()

/*****************************************************************************
 *
 * Below API are used in cases
 *  
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 * AVK_ASYN_DONE
 * DESCRIPTION
 *  MUST use this when asyn case  finish to invoke next case
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_ASYN_DONE() \
        avk_framework_asyn_invoke_next_case(0)

/*****************************************************************************
 * FUNCTION
 * AVK_CASE_RESULT
 * DESCRIPTION
 *  Set case result
 * PARAMETERS
 *  exp      :   [IN]        a expression to present pass or fail 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_CASE_RESULT(exp) \
        g_avk_framework_ctx.b_current_result = exp?AVK_PASS:AVK_FAIL

/*****************************************************************************
 * FUNCTION
 * AVK_GET_CASE_RESULT
 * DESCRIPTION
 *  Get case result
 * PARAMETERS
 * 
 * RETURNS
 *  result
 *****************************************************************************/       
#define AVK_GET_CASE_RESULT() \
                g_avk_framework_ctx.b_current_result

/*****************************************************************************
 * FUNCTION
 * AVK_DRAW_TITLE
 * DESCRIPTION
 *  Draw title on empty screen,
 * PARAMETERS
 *  title_str         :   [IN]        title string(UCS2)
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_DRAW_TITLE(title_str) \
                avk_framework_draw_title(title_str)
                
/*****************************************************************************
 * FUNCTION
 * AVK_DRAW_SOFTKEY
 * DESCRIPTION
 *  Draw softkey on empty screen, and will set pen handler as the key handler
 * PARAMETERS
 *  key_type         :   [IN]        key type :KEY_LSK or KEY_RSK
 *  key_content     :   [IN]        content to show : e.g.AVK_STR_PASS 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_DRAW_SOFTKEY(key_type, key_content) \
                avk_framework_draw_softkey(key_type, key_content);
/*****************************************************************************
 * FUNCTION
 * AVK_SET_PASSKEY
 * DESCRIPTION
 *  Set manual case passkey(rightkey),only use when showing category by yourself
 * PARAMETERS
 *  func         :   [IN]        extra hanler,e.g. free memory
 * RETURNS
 *  
 *****************************************************************************/ 
#define AVK_SET_PASSKEY(func) \
    g_avk_framework_ctx.leftkey_handle = func;\
    SETLEFTKEY(avk_framework_pass)

/*****************************************************************************
 * FUNCTION
 * AVK_SET_PASSKEY
 * DESCRIPTION
 *  Set manual case failkey(leftkey),only use when showing category by yourself
 * PARAMETERS
 *  func         :   [IN]        extra hanler,e.g. free memory
 * RETURNS
 *  
 *****************************************************************************/    
#define AVK_SET_FAILKEY(func) \
    g_avk_framework_ctx.rightkey_handle = func;\
    SETRIGHTKEY(avk_framework_fail)

/*****************************************************************************
 * FUNCTION
 * AVK_MANU_SHOW_TIPS
 * DESCRIPTION
 *  Show a tip
 * PARAMETERS
 *  content             :   [IN]        content to show, UCS2
 *  leftkey_handle   :   [IN]        leftkey_handle, invoke when user click OK
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_MANU_SHOW_TIPS(content, leftkey_handle) \
            avk_framework_entry_manual_scr(AVK_FRAMEWORK_MANUAL_TIPS_SCR,(void*)content,(void*)leftkey_handle,(void*)NULL)

/*****************************************************************************
 * FUNCTION
 * AVK_MANU_SHOW_SCR
 * DESCRIPTION
 *  Show normal manual screen
 * PARAMETERS
 *  content             :   [IN]        content to show, UCS2
 *  leftkey_handle   :   [IN]        extra hanler,e.g. free memory
 *  leftkey_handle   :   [IN]        extra hanler,e.g. free memory
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_MANU_SHOW_SCR(content, leftkey_handle, rightkey_handle) \
            avk_framework_entry_manual_scr(AVK_FRAMEWORK_MANUAL_PASS_FAIL_SCR,(void*)content,(void*)leftkey_handle,(void*)rightkey_handle)
            


/*****************************************************       
*Log API        
*****************************************************/
/*****************************************************************************
 * FUNCTION
 * AVK_LOG
 * DESCRIPTION
 *  Log the function in exp, does not care about the value of exp, alway mark function pass, exp can NOT return void
 *  e.g.  to log test_funcion in if( 1 == test_funcion()){...}; could code like: if(AVK_LOG(1 == test_function()){...};
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG(exp) \
        (avk_framework_log_fun(avk_framework_log_parser(#exp),AVK_PASS)?((exp)):0)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_EX
 * DESCRIPTION
 *  Log functions. Can log functions return void.
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_NORMAL(exp) \
        exp;\
        avk_framework_log_fun(avk_framework_log_parser(#exp),AVK_PASS)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_EX
 * DESCRIPTION
 *  Log the function in exp,  care about the value of exp,  mark function pass when exp is true; exp can not return void
 *  e.g.  hope test_funcion return 0, could code like: AVK_LOG_EX(0 == test_function());
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_EX(exp) \
        avk_framework_log_fun(avk_framework_log_parser(#exp),(exp)?AVK_PASS:AVK_FAIL)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_ASYN
 * DESCRIPTION
 *  Log the function in exp, use in auto case,log pass or fail depend on case result when case finish
 *  e.g.  to log test_funcion in if( 1 == test_funcion()){...}; could code like: if(1 == AVK_LOG_ASYN(test_function()){...};
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_ASYN(exp) \
        (avk_framework_insert_fun(avk_framework_log_parser(#exp))?((exp)):0)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_MANUAL
 * DESCRIPTION
 *  Log the function in exp,  use in manual case,log pass or fail depend on case result when case finish
 *  e.g.  to log test_funcion in if( 1 == test_funcion()){...}; could code like: if(1 == AVK_LOG_MANUAL(test_function()){...};
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function
 * RETURNS
 *  
 *****************************************************************************/        
#define AVK_LOG_MANUAL(exp) \
        (avk_framework_insert_fun(avk_framework_log_parser(#exp))?((int)(exp)):0) 

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_EX
 * DESCRIPTION
 *   Log the function in exp, use in auto case,log pass or fail depend on case result when case finish.
 *   Can log functions return void.
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_ASYN_NORMAL(exp) \
        exp;\
        avk_framework_insert_fun(avk_framework_log_parser(#exp))

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_EX
 * DESCRIPTION
 *   Log the function in exp, use in manual case,log pass or fail depend on case result when case finish.
 *   Can log functions return void.
 * PARAMETERS
 *  exp         :   [IN]        expression, contain test function 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_MANUAL_NORMAL(exp) \
        exp;\
        avk_framework_insert_fun(avk_framework_log_parser(#exp))

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_FUN
 * DESCRIPTION
 *  Log the fun, according value of exp,exp can not return void
 *  e.g.  to log test_funcion could code like: AVK_LOG_FUN(test_funcion,AVK_PASS);
 * PARAMETERS
 *  fun         :   [IN]        function name 
 *  exp         :   [IN]        expression, contain test function
 * RETURNS
 *  
 *****************************************************************************/        
#define AVK_LOG_FUN(fun, exp) \
        avk_framework_log_fun(#fun, (exp)?AVK_PASS:AVK_FAIL)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_FUN_ASYN
 * DESCRIPTION
 *  Log the fun, use in asyn case,log pass or fail depend on case result when case finish
 * PARAMETERS
 *  fun         :   [IN]        function name 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_FUN_ASYN(fun)  \
        avk_framework_insert_fun(#fun)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_FUN_MANUAL
 * DESCRIPTION
 *  Log the fun, use in manual case,log pass or fail depend on case result when case finish
 * PARAMETERS
 *  fun         :   [IN]        function name 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_FUN_MANUAL(fun)  \
        avk_framework_insert_fun(#fun)

/*****************************************************************************
 * FUNCTION
 * AVK_LOG_FUN_UNSUPPORTED
 * DESCRIPTION
 *  Log the fun, use in when the function unsupport
 * PARAMETERS
 *  fun         :   [IN]        function name 
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_LOG_FUN_UNSUPPORTED(fun) \
        avk_framework_log_fun(#fun, AVK_UNSUPPORT)

/*****************************************************
*memory interface
*****************************************************/

/*****************************************************************************
 * FUNCTION
 * AVK_MALLOC
 * DESCRIPTION
 *  malloc , 100K at most
 * PARAMETERS
 *  size         :   [IN]        memory size
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_MALLOC(size) \
        avk_framework_malloc(size)

/*****************************************************************************
 * FUNCTION
 * AVK_FREE
 * DESCRIPTION
 *  free 
 * PARAMETERS
 *  p         :   [IN]        memory to be freed
 * RETURNS
 *  
 *****************************************************************************/
#define AVK_FREE(p) \
        avk_framework_free(p)

/*****************************************************
*UI relative
*****************************************************/
#define AVK_MAIN_GRP_ID GRP_ID_AVK

#define AVK_GRP_ID_1 GRP_ID_1
#define AVK_GRP_ID_2 GRP_ID_2


#define AVK_SCR_ID_1 SCR_ID_AVK_SCN_10
#define AVK_SCR_ID_2 SCR_ID_AVK_SCN_11
#define AVK_SCR_ID_3 SCR_ID_AVK_SCN_12
#define AVK_SCR_ID_4 SCR_ID_AVK_SCN_13
#define AVK_SCR_ID_5 SCR_ID_AVK_SCN_14

#define AVK_STR_PASS STR_ID_AVK_PASS
#define AVK_STR_FAIL STR_ID_AVK_FAIL

/*****************************************************
*test file path
*UCS2 codec , just like : D:\AVK\test file\
*****************************************************/

#define AVK_TEST_FILE_PATH avk_framework_testfile_path


