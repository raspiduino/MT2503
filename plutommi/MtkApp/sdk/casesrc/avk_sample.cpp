


AVK_ADD_ITEM(AVK_RES_AUTO,L"Auto cases",AVK_PLUTO_RES);
AVK_ADD_ITEM(AVK_RES_MANU,L"Manual cases",AVK_PLUTO_RES);

MMI_BOOL avk_sample_test_function_pass(void)
{
    return MMI_TRUE;
}

MMI_BOOL avk_sample_test_function_fail(void)
{
    return MMI_FALSE;
}

AVK_CASE(AVK_RES_AUTO_CASE1,AVK_RES_AUTO)
{
    AVK_LOG_FUN(avk_sample_test_function_pass,
                    MMI_TRUE == avk_sample_test_function_pass());
}

AVK_CASE(AVK_RES_AUTO_CASE1_1,AVK_RES_AUTO_CASE1)
{
    AVK_LOG_EX(avk_sample_test_function_pass);
    AVK_LOG_EX(avk_sample_test_function_fail);
}

AVK_CASE(AVK_RES_AUTO_CASE1_1_1,AVK_RES_AUTO_CASE1_1)
{
    AVK_LOG_FUN(avk_sample_test_function_fail,AVK_FAIL);
    AVK_LOG_FUN(avk_sample_test_function_pass,AVK_PASS);
}

AVK_CASE(AVK_RES_AUTO_CASE1_1_1_1,AVK_RES_AUTO_CASE1_1_1)
{
    AVK_LOG_FUN(not_run,AVK_PASS);
}

AVK_CASE(AVK_RES_AUTO_CASE2,AVK_RES_AUTO)
{
    AVK_LOG_FUN(avk_sample_test_function_fail,AVK_FAIL);
}

void avk_sample_test_function_void(void)
{
    //do nothing
}

U32 avk_sample_test_function_u32(U32 param)
{
    return param;
}


AVK_CASE(AVK_RES_AUTO_CASE3,AVK_RES_AUTO)
{
    U32 param, res;
    
    AVK_LOG_NORMAL(avk_sample_test_function_void());
    AVK_LOG(res = avk_sample_test_function_u32(param));
    
    AVK_LOG_FUN(avk_sample_test_function_pass,AVK_PASS);
}

void avk_sample_test_function_async(void (*callback)(void) )
{
    StartTimer(123,1000,callback);
}

void avk_sample_cb_pass()
{
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}

AVK_ASYN_CASE(AVK_RES_AUTO_CASE4,AVK_RES_AUTO)
{
    //
    //  invoke test functions
    //
    AVK_LOG_FUN(avk_sample_test_function_pass,AVK_PASS);
    AVK_LOG_FUN(avk_sample_test_function_fail,AVK_FAIL);

    avk_sample_test_function_async(avk_sample_cb_pass);
    AVK_LOG_FUN_ASYN(avk_sample_test_function_async);
}

void avk_sample_cb_fail()
{
    AVK_CASE_RESULT(AVK_FAIL);
    AVK_ASYN_DONE();
}

AVK_ASYN_CASE(AVK_RES_AUTO_CASE5,AVK_RES_AUTO)
{
    //
    //  invoke test functions
    //
    AVK_LOG_FUN(avk_sample_test_function_pass,AVK_PASS);
    AVK_LOG_FUN(avk_sample_test_function_fail,AVK_FAIL);

    AVK_LOG_ASYN(avk_sample_test_function_async(avk_sample_cb_fail));
}

AVK_ASYN_CASE(AVK_RES_AUTO_CASE6,AVK_RES_AUTO)
{
    //this is a abort case
    int a = 0;
    int b = 10/a;
    AVK_ASYN_DONE();
}

AVK_ASYN_CASE(AVK_RES_AUTO_CASE7,AVK_RES_AUTO)
{
    //this is a "abort" case
    AVK_LOG_FUN_ASYN(asyn_unknow);
}


void avk_sample_test_manual_left_cb()
{
    AVK_LOG_FUN_MANUAL(manual_fun1);
    AVK_LOG_FUN_MANUAL(manual_fun2);
    AVK_LOG_FUN_MANUAL(manual_fun3);
    AVK_LOG_FUN_MANUAL(manual_fun4);
    AVK_LOG_FUN_MANUAL(manual_fun5);
    AVK_LOG_FUN_MANUAL(manual_fun6);
    AVK_LOG_FUN_MANUAL(manual_fun7);
    
    AVK_MANU_SHOW_SCR(L"you decide pass or fail!",NULL,NULL);
}

AVK_MANUAL_CASE(AVK_RES_MANU_CASE1, AVK_RES_MANU)
{
    AVK_MANU_SHOW_TIPS(L"this is a manual test!",avk_sample_test_manual_left_cb);
}

AVK_MANUAL_CASE(AVK_RES_MANU_CASE2,  AVK_RES_MANU)
{
    //
    //  invoke test functions
    //
    AVK_LOG_FUN_MANUAL(manual_fun1);
    AVK_LOG_FUN_MANUAL(manual_fun2);
    
    AVK_LOG_MANUAL(avk_sample_test_function_void());
    
    AVK_MANU_SHOW_SCR(L"you decide pass or fail!",NULL,NULL);
}

void avk_sample_test_entry_manual_scr()
{
    mmi_frm_scrn_enter(AVK_MAIN_GRP_ID,AVK_SCR_ID_1,NULL,
            avk_sample_test_entry_manual_scr,MMI_FRM_FULL_SCRN);
    //
    //show category, do something
    //
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);    
}

AVK_MANUAL_CASE(mtest3, AVK_RES_MANU)
{
    AVK_LOG_FUN_MANUAL(manual_fun1);
    AVK_LOG_FUN_MANUAL(manual_fun2);
    //
    // do something
    //
    avk_sample_test_entry_manual_scr();
}