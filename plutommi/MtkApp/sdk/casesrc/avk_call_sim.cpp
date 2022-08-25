extern "C"
{
#include "SimAccessSrvGprot.h"
#include "SimCtrlSrvGprot.h"
}
void avk_call_sim_write_binary(void);
void avk_call_sim_read_binary(void);
void avk_call_sim_write_record(void);
void avk_call_sim_read_record(void);
void avk_call_sim_get_file_info(void);

void avk_call_sim_verify(void);
void avk_call_sim_verify_ub(void);
void avk_call_sim_change_pw(void);
void avk_call_sim_disable(void);
void avk_call_sim_done(void);



#define SRV_SMS_MAX_SIM_SIZE               176

typedef void (*tst_func)(void);

const static U8 data[SRV_SMS_MAX_SIM_SIZE]={0xaa};
static tst_func g_tst_func = 0;
static U32 g_tst_id = 0;


AVK_ADD_ITEM(AVK_CALL_SIM_AUTO,L"Auto cases",AVK_CALL_SIM);
AVK_ADD_ITEM(AVK_CALL_SIM_MANUAL,L"Manual cases",AVK_CALL_SIM);

void avk_call_sim_write_record_cb(srv_sim_cb_struct* callback_data)
{
    AVK_CASE_RESULT(callback_data->result);
    AVK_ASYN_DONE();
}

void avk_call_sim_read_record_cb(srv_sim_cb_struct* callback_data)
{
    if (!callback_data->result)
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    else
    {
        srv_sim_data_struct* pdata = (srv_sim_data_struct*)callback_data->data;
        if(memcmp(pdata->data,data,pdata->length))
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
        else
        {
            AVK_CASE_RESULT(AVK_PASS);
        }
    }
    
    AVK_ASYN_DONE();
}

void avk_call_sim_write_binary_cb(srv_sim_cb_struct* callback_data)
{
    AVK_CASE_RESULT(callback_data->result);
    AVK_ASYN_DONE();
}


void avk_call_sim_read_binary_cb(srv_sim_cb_struct* callback_data)
{
    if (!callback_data->result)
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    else
    {
        srv_sim_data_struct* pdata = (srv_sim_data_struct*)callback_data->data;
        if(memcmp(pdata->data,data,pdata->length))
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
        else
        {
            AVK_CASE_RESULT(AVK_PASS);
        }
    }
    AVK_ASYN_DONE();
}

void avk_call_sim_get_file_info_cb(srv_sim_cb_struct* callback_data)
{
    AVK_CASE_RESULT(callback_data->result);
    AVK_ASYN_DONE();
}


AVK_ASYN_CASE(AVK_CALL_SIM_WRITE_RECORD,AVK_CALL_SIM_AUTO)
{                                
    if(!AVK_LOG_ASYN(srv_sim_write_record(   FILE_SMS_IDX,
                                NULL,
                                1,
                                SRV_SMS_MAX_SIM_SIZE,
                                (U8*)data,
                                MMI_SIM1,
                                avk_call_sim_write_record_cb,
                                NULL)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }                            
}

AVK_ASYN_CASE(AVK_CALL_SIM_READ_RECORD,AVK_CALL_SIM_WRITE_RECORD)
{    
    if (!AVK_LOG_ASYN(srv_sim_read_record(   FILE_SMS_IDX,
                                NULL,
                                1,
                                SRV_SMS_MAX_SIM_SIZE,
                                MMI_SIM1,
                                avk_call_sim_read_record_cb,
                                NULL)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }                            
}

AVK_ASYN_CASE(AVK_CALL_SIM_WRITE_BINARY,AVK_CALL_SIM_AUTO)
{
    if (!AVK_LOG_ASYN(srv_sim_write_binary(  FILE_SMS_IDX,
                                NULL,
                                1,
                                SRV_SMS_MAX_SIM_SIZE,
                                (void*)data,
                                MMI_SIM1,
                                avk_call_sim_write_binary_cb,
                                NULL)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }                            
}

AVK_ASYN_CASE(AVK_CALL_SIM_READ_BINARY,AVK_CALL_SIM_WRITE_BINARY)
{
    if (!AVK_LOG_ASYN(srv_sim_read_binary(   FILE_SMS_IDX,
                                NULL,
                                1,
                                SRV_SMS_MAX_SIM_SIZE,
                                MMI_SIM1,
                                avk_call_sim_read_binary_cb,
                                NULL)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }                                
}

AVK_ASYN_CASE(AVK_CALL_SIM_GET_INFO,AVK_CALL_SIM_AUTO)
{
    if (!AVK_LOG_ASYN(srv_sim_get_file_info( FILE_SMS_IDX,
                                NULL,
                                MMI_SIM1,
                                avk_call_sim_get_file_info_cb,
                                NULL)))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }        
}

static mmi_ret avk_call_sim_callback (mmi_event_struct *param)
{
    srv_sim_ctrl_verify_result_evt_struct* result_p = (srv_sim_ctrl_verify_result_evt_struct*)param;

    tst_func fun = (tst_func)param->user_data;
    if (result_p->success)
    {
        if (fun)
        {
            (*fun)();
        }
    }
    else
    {
        AVK_MANU_SHOW_TIPS(
            L"Verify pin failed, maybe the pin code is not correct, please double check it before submit CR.",
            mmi_frm_scrn_close_active_id);
        AVK_CASE_RESULT(result_p->success);
        AVK_ASYN_DONE();
    }
    return 0;
}

static WCHAR avk_call_sim_pin[8] = {0};

void avk_call_sim_pin_test()
{
    mmi_frm_scrn_close_active_id();

    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        AVK_LOG_FUN(srv_sim_ctrl_is_available, AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }
    else
    {
        AVK_LOG_FUN(srv_sim_ctrl_is_available, AVK_PASS);
    }


    if (srv_sim_ctrl_pwd_is_blocked(MMI_SIM1,SRV_SIM_CTRL_PWD_TYPE_CHV1))
    {
        AVK_LOG_FUN(srv_sim_ctrl_pwd_is_blocked, AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }
    else
    {
        AVK_LOG_FUN(srv_sim_ctrl_pwd_is_blocked, AVK_PASS);
    }

    if (!AVK_LOG_ASYN(srv_sim_ctrl_pwd_is_enabled(MMI_SIM1,SRV_SIM_CTRL_PWD_TYPE_CHV1)))
    {
        if (AVK_LOG_ASYN(srv_sim_ctrl_set_enabled(
                            MMI_SIM1,
                            SRV_SIM_CTRL_PWD_TYPE_CHV1,
                            avk_call_sim_pin,
                            MMI_TRUE,
                            avk_call_sim_callback,
                            (void*)avk_call_sim_verify)) < 0)
        {
            AVK_CASE_RESULT(AVK_FAIL);
            AVK_ASYN_DONE();
        }
    } 
    else
    {
        avk_call_sim_disable();
    }
}

void avk_call_sim_pin_scr()
{
    U8* guiBuffer;
    
    if (!mmi_frm_scrn_enter(
            GRP_ID_AVK, 
            AVK_SCR_ID_1, 
            NULL, 
            (FuncPtr)avk_call_sim_pin_scr, 
            MMI_FRM_FULL_SCRN))
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
#ifdef UI_SMALL_PIN_EDITOR_SCREEN    
    ShowCategory112Screen(STR_GLOBAL_OK,
                              0,
                              0,
                              0,
                              (U8*)L"input PIN",
                              IMM_INPUT_TYPE_NUMERIC_PASSWORD,
                              (U8*)avk_call_sim_pin,
                              10,
                              0,
                              guiBuffer);
#else
    ShowCategory111Screen_ext(STR_GLOBAL_OK,
                              0,
                              0,
                              0,
                              (U8*)L"input PIN",
                              IMM_INPUT_TYPE_NUMERIC_PASSWORD,
                              (U8*)avk_call_sim_pin,
                              10,
                              0,
                              0,
                              guiBuffer);  
#endif    
    SETLEFTKEY(avk_call_sim_pin_test);
}

AVK_MANUAL_CASE(AVK_CALL_SIM_CTRL,AVK_CALL_SIM_MANUAL)
{
    avk_call_sim_pin_scr();
}



void avk_call_sim_verify()
{
    if (!AVK_LOG_ASYN(srv_sim_ctrl_pwd_is_verified(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV1)))
    {
        if (AVK_LOG_ASYN(srv_sim_ctrl_verify(
                            MMI_SIM1,
                            SRV_SIM_CTRL_PWD_TYPE_CHV1,
                            avk_call_sim_pin,
                            avk_call_sim_callback,
                            (void*)avk_call_sim_change_pw)) < 0)
        {
            AVK_CASE_RESULT(AVK_FAIL);
            AVK_ASYN_DONE();
        }
    }
    else
    {
        avk_call_sim_change_pw();
    }
}

void avk_call_sim_change_pw()
{
    if (AVK_LOG_ASYN(srv_sim_ctrl_change_password(
                        MMI_SIM1,
                        SRV_SIM_CTRL_PWD_TYPE_CHV1,
                        avk_call_sim_pin,
                        avk_call_sim_pin,
                        avk_call_sim_callback,
                        (void*)avk_call_sim_disable)) < 0)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        avk_call_sim_disable();
    }
}

void avk_call_sim_disable()
{
    if (AVK_LOG_ASYN(srv_sim_ctrl_set_enabled(
                        MMI_SIM1,
                        SRV_SIM_CTRL_PWD_TYPE_CHV1,
                        avk_call_sim_pin,
                        MMI_FALSE,
                        avk_call_sim_callback,
                        (void*)avk_call_sim_done)) < 0)
    {       
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

void avk_call_sim_done()
{
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
}

AVK_MANUAL_CASE(AVK_CALL_SIM_MANUAL1,AVK_CALL_SIM_MANUAL)
{    
    WCHAR tmp_buff[256]={0};
    
    if (0 == AVK_LOG_MANUAL(srv_sim_ctrl_get_one_available_sim()))
    {
        AVK_MANU_SHOW_SCR(L"No SIM Card!",NULL,NULL);
        return;
    }
    
    if (AVK_LOG_MANUAL(srv_sim_ctrl_is_available(MMI_SIM1)))
    {
        mmi_wcscat(tmp_buff,(WCHAR *)L"SIM1 OK!");
        if (AVK_LOG_MANUAL(srv_sim_ctrl_is_usim(MMI_SIM1)))
        {
            mmi_wcscat(tmp_buff,(WCHAR *)L" USIM!");
        }
    }

    AVK_LOG(srv_sim_ctrl_get_unavailable_cause(MMI_SIM1));

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    AVK_MANU_SHOW_SCR(tmp_buff,NULL,NULL);
}


AVK_MANUAL_CASE(AVK_CALL_SIM_MANUAL2,AVK_CALL_SIM_MANUAL)
{
    CHAR buf[SRV_MAX_IMSI_LEN + 1];
    WCHAR tmp_buff[256]={0};
#ifdef __R7_EHPLMN__   
    srv_sim_ctrl_plmn_list_struct plmn_list;
#endif    
    if (AVK_LOG_MANUAL(srv_sim_ctrl_get_imsi(MMI_SIM1,buf,SRV_MAX_IMSI_LEN + 1)))
    {
        mmi_wcscpy(tmp_buff,(WCHAR*)L"IMSI: ");
        mmi_asc_to_wcs(tmp_buff+mmi_wcslen(tmp_buff),buf);
        mmi_wcscat(tmp_buff,(WCHAR*)L"\n");
    }
    else
    {
        mmi_wcscat(tmp_buff,(WCHAR *)L"get imsi fail ");
    }
    
    if (AVK_LOG_MANUAL(srv_sim_ctrl_get_home_plmn(MMI_SIM1,buf,SRV_MAX_PLMN_LEN + 1)))
    {
        mmi_wcscat(tmp_buff,(WCHAR*)L"PLMN: ");
        mmi_asc_to_wcs(tmp_buff+mmi_wcslen(tmp_buff),buf);
    }
    else
    {
        mmi_wcscat(tmp_buff,(WCHAR *)L"get plmn fail ");
    }
    
#ifdef __R7_EHPLMN__    
    if (AVK_LOG_MANUAL(srv_sim_ctrl_get_eh_plmn(MMI_SIM1,&plmn_list)))
    {
        mmi_wcscat(tmp_buff,(WCHAR *)L"\n");
        mmi_wcscat(tmp_buff,(WCHAR *)L"ehplmn valid");
    }
    else
    {
        mmi_wcscat(tmp_buff,(WCHAR *)L"\n");
        mmi_wcscat(tmp_buff,(WCHAR *)L"ehplmn invalid");
    }
#else
    AVK_LOG_FUN_UNSUPPORTED(srv_sim_ctrl_get_eh_plmn);
#endif
    AVK_MANU_SHOW_SCR(tmp_buff,NULL,NULL);
}


