extern "C"
{
#include "TimerEvents.h"
#ifdef __MMI_MMS_2__
#include "Mms_sap_struct.h"
#include "MmsSrvGprot.h"
#endif
#include "UmSrvDefs.h"
#include "pmg_struct.h"
#include "SmsSrvGprot.h"
//#include "SimDetectionStruct.h"
#include "SmsSrvGProt.h"
#include "app_str.h"

}

static U8 g_avk_msg_sms_async_done;
static U16 g_vs_sms_last_action;
static U16 g_vs_sms_string[10];

typedef struct
{
    U16             msg_id;
    U32             result;
    SMS_HANDLE      handle;
    srv_sms_msg_data_struct sms_data;
    U16             content_buff[20];
    U16             query_msg_list[16];
    U16             number[41];
}avk_msg_sms_ctx;

static avk_msg_sms_ctx* g_p_msg_sms_ctx = NULL;

#define VS_APPSER_SMS_READ_CB_MASK 0x00000001
#define VS_APPSER_SMS_COPY_CB_MASK 0x00000001
#define VS_APPSER_SMS_SEND_ACTION 0x00000002
#define VS_APPSER_SMS_CHK_NUM_ACTION 0x00000004
#define ALIGN_TEST_TM_ID        MMI_TIMER_BASE
#define NON_ALIGN_TEST_TM_ID    KEY_TIMER_ID_NONE


static void avk_msg_sms_init(srv_sms_callback_struct* callback_data);
AVK_ASYN_CASE(AVK_SMS_CASE_INIT,AVK_MSG_SMS)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_p_msg_sms_ctx = (avk_msg_sms_ctx*)AVK_MALLOC(sizeof(avk_msg_sms_ctx));
    if (!g_p_msg_sms_ctx)
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
        return;
    }
    kal_wstrcpy(g_p_msg_sms_ctx->number,(const WCHAR *)L"13800138000");
    
    AVK_LOG_EX(!srv_sms_is_hide_send_sms_menu_item());
    AVK_LOG_EX(srv_sms_is_sms_ready());
    AVK_LOG_EX(!srv_sms_is_sms_busy());
	if (AVK_FAIL == AVK_GET_CASE_RESULT())
	{
		AVK_ASYN_DONE();
		return;
	}
	
    AVK_LOG(handle = srv_sms_get_save_handle());
    AVK_LOG_NORMAL(srv_sms_set_content(handle,(S8*)L"123",8));    
    AVK_LOG_NORMAL(srv_sms_set_status(handle,SRV_SMS_STATUS_UNREAD));
    
    srv_sms_save_msg(handle,avk_msg_sms_init,NULL);
}

static void avk_msg_sms_get_setting_cb(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        AVK_LOG(srv_sms_set_setting_para(
            SRV_SMS_GET_MEMORY_STATUS,
            cb->action_data,
            SRV_SMS_SIM_1,
            NULL,
            NULL));
    }
    else
    {
        AVK_LOG_FUN(srv_sms_get_setting_para,AVK_FAIL);
    }
    AVK_ASYN_DONE();
}

static void avk_msg_sms_init(srv_sms_callback_struct* callback_data)
{
    srv_sms_memory_status_struct status;
    void *get_data;
    
    if (!callback_data->result)
    {
        AVK_LOG_FUN(srv_sms_save_msg,AVK_FAIL);
    }
    else
    {
        AVK_LOG_FUN(srv_sms_save_msg,AVK_PASS);
        memset(&status,0,sizeof(status));
        srv_sms_get_memory_status(SRV_SMS_SIM_1, &status);
        AVK_LOG_FUN(srv_sms_get_memory_status,
                        status.me_used + status.sim_used > 0);
        AVK_LOG_EX(srv_sms_get_list_size(SRV_SMS_BOX_INBOX) > 0);    
        AVK_LOG_EX(srv_sms_get_unread_sms_num() > 0);
        
        AVK_LOG(srv_sms_get_unread_sim_sms_num());   
        AVK_LOG(srv_sms_get_email_sc_address()); 
        AVK_LOG(srv_sms_get_mailbox_name(SRV_SMS_SIM_1, (U16 *)L"98765", (U16 *)L"ABC")); 
        AVK_LOG(srv_sms_check_r4_support());
        AVK_LOG(srv_sms_get_actived_profile_pid());
        AVK_LOG(srv_sms_is_save_sent_sms_setting(SRV_SMS_SIM_1));
        AVK_LOG(srv_sms_get_mailbox_setting(SRV_SMS_SIM_1));
        
        AVK_LOG_EX(SRV_SMS_BOX_INBOX == srv_sms_get_list_type(
                                                                    SRV_SMS_STATUS_UNREAD,
                                                                    SRV_SMS_STORAGE_ME,
                                                                    SRV_SMS_FOLDER_DEFAULT));
        srv_sms_get_setting_para(
            SRV_SMS_GET_MEMORY_STATUS,
            &get_data,
            SRV_SMS_SIM_1,
            avk_msg_sms_get_setting_cb,
            (void*)0xDEAD);        
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_008
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_008(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_FUN(srv_sms_delete_msg,
                    cb->user_data == (void*)0xDEAD&&cb->result);
    AVK_ASYN_DONE();                    
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_007
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_007(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result )
    {
        AVK_LOG_FUN(srv_sms_change_msg_status, AVK_PASS);
        srv_sms_delete_msg(
            g_p_msg_sms_ctx->msg_id,
            avk_msg_sms_cb_008,
            (void*)0xDEAD);
    }
    else
    {
        AVK_LOG_FUN(srv_sms_change_msg_status, AVK_FAIL);
        AVK_ASYN_DONE();
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

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_005
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_005(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status = SRV_SMS_STATUS_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!cb->result && cb->cause == SRV_SMS_CAUSE_OP_NOT_SUPPORTED)
    {
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_move_archive_msg);
        AVK_LOG(status = srv_sms_get_msg_status(g_p_msg_sms_ctx->msg_id));
        status = (status == SRV_SMS_STATUS_READ)?SRV_SMS_STATUS_UNREAD:SRV_SMS_STATUS_READ;
        
        srv_sms_change_msg_status(
            g_p_msg_sms_ctx->msg_id,
            status,
            avk_msg_sms_cb_007,
            (void *)0xDEAD);
    }
    else if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {        
        AVK_LOG_FUN(srv_sms_move_archive_msg, AVK_PASS);
        AVK_LOG(status = srv_sms_get_msg_status(g_p_msg_sms_ctx->msg_id));
        status = (status == SRV_SMS_STATUS_READ)?SRV_SMS_STATUS_UNREAD:SRV_SMS_STATUS_READ;
        
        srv_sms_change_msg_status(
            g_p_msg_sms_ctx->msg_id,
            status,
            avk_msg_sms_cb_007,
            (void *)0xDEAD);
    }
    else
    {
        AVK_LOG_FUN(srv_sms_move_archive_msg, AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_004
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_004(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__ 
    U16 msg_id;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cb->result && cb->cause == SRV_SMS_CAUSE_OP_NOT_SUPPORTED)
    {
        /* Not supported so short this test case */
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_move_msg_to_archive);
        cb->result = MMI_TRUE;
        avk_msg_sms_cb_005(cb);
    }
    else if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        AVK_LOG_FUN(srv_sms_move_msg_to_archive, AVK_PASS);
#ifdef __SRV_SMS_ARCHIVE__ 
        msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_ARCHIVE, 0);
        srv_sms_move_archive_msg(
            msg_id,
            (srv_sms_storage_enum)!srv_sms_get_msg_storage_type(g_p_msg_sms_ctx->msg_id),
            avk_msg_sms_cb_005,
            (void *)0xDEAD);
#else
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_move_archive_msg);
        avk_msg_sms_cb_005(cb);
#endif
    }
    else
    {
        AVK_LOG_FUN(srv_sms_move_msg_to_archive, AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_003
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_003(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        AVK_LOG_FUN(srv_sms_move_msg, AVK_PASS);
#ifdef __SRV_SMS_ARCHIVE__        
        srv_sms_move_msg_to_archive(
            g_p_msg_sms_ctx->msg_id,
            avk_msg_sms_cb_004,
            (void *)0xDEAD);
#else
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_move_msg_to_archive);
        avk_msg_sms_cb_004(cb);
#endif
    }
    else
    {
        AVK_LOG_FUN(srv_sms_move_msg, AVK_FAIL);
        AVK_ASYN_DONE();
    }
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_002
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_002(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        AVK_LOG_FUN(srv_sms_copy_msg, AVK_PASS);
       
        srv_sms_move_msg(
            g_p_msg_sms_ctx->msg_id,
            (srv_sms_storage_enum)!srv_sms_get_msg_storage_type(g_p_msg_sms_ctx->msg_id),
            avk_msg_sms_cb_003,
            (void *) 0xDEAD);
    }
    else
    {
        AVK_LOG_FUN(srv_sms_copy_msg, AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_content_cb
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL avk_msg_sms_content_cb(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_asyn_content_cb
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL avk_msg_sms_asyn_content_cb(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_avk_msg_sms_async_done == MMI_TRUE)
    {
        
        srv_sms_move_msg(
            g_p_msg_sms_ctx->msg_id,
            (srv_sms_storage_enum)!srv_sms_get_msg_storage_type(g_p_msg_sms_ctx->msg_id),
            avk_msg_sms_cb_003,
            (void *) 0xDEAD);
    }
    else
    {
        g_avk_msg_sms_async_done = MMI_TRUE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_cb_001
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_cb_001(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 buffer[SRV_UM_MAX_ADDR_LEN + 1];
    MYTIME time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        AVK_LOG_FUN(srv_sms_read_msg, AVK_PASS);

        srv_sms_copy_msg(
            g_p_msg_sms_ctx->msg_id,
            (srv_sms_storage_enum)!srv_sms_get_msg_storage_type(g_p_msg_sms_ctx->msg_id),
            avk_msg_sms_cb_002,
            (void *)0xDEAD);
            
        AVK_LOG(srv_sms_get_msg_asc_address(g_p_msg_sms_ctx->msg_id));
        AVK_LOG_NORMAL(srv_sms_get_msg_address(g_p_msg_sms_ctx->msg_id, (S8*) buffer));
        AVK_LOG_NORMAL(srv_sms_get_msg_content(g_p_msg_sms_ctx->msg_id));
        AVK_LOG_NORMAL(srv_sms_get_msg_timestamp(g_p_msg_sms_ctx->msg_id, &time));
        AVK_LOG(srv_sms_get_msg_timestamp_utc_sec(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_get_msg_pid(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_get_msg_mti(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_get_msg_sim_id(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_get_msg_size(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_get_delivery_status(g_p_msg_sms_ctx->msg_id));
        AVK_LOG(srv_sms_is_msg_complete(g_p_msg_sms_ctx->msg_id));
        g_avk_msg_sms_async_done = MMI_FALSE;
        AVK_LOG(srv_sms_get_msg_content_async(
                                                g_p_msg_sms_ctx->msg_id,
                                                NULL,
                                                (void*)0xDEAD));
    }
    else
    {
        AVK_LOG_FUN(srv_sms_read_msg, AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_001_entry
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_SMS_CASE_1,AVK_SMS_CASE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;
    MMI_BOOL bRet = MMI_FALSE;
    srv_sms_box_enum inbox = SRV_SMS_BOX_INBOX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_p_msg_sms_ctx->msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_INBOX, 0);
    AVK_LOG_FUN(srv_sms_get_msg_id,
                    SRV_SMS_INVALID_MSG_ID != g_p_msg_sms_ctx->msg_id);
    AVK_LOG(srv_sms_get_dest_module(g_p_msg_sms_ctx->msg_id));
    AVK_LOG_NORMAL(srv_sms_reg_port(0xC0DE, SRV_SMS_SIM_1, NULL, NULL));
    AVK_LOG(srv_sms_unreg_port(0xC0DE, SRV_SMS_SIM_1, NULL, NULL));
        
    msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_OUTBOX, 0);
    if (msg_id != SRV_SMS_INVALID_MSG_ID)
    {
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
        AVK_LOG_EX(srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL));
        AVK_LOG_EX(srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_FAIL);                        

        AVK_LOG_NORMAL(srv_sms_set_unsent_msg_status_ext(
                                                msg_id,
                                                SRV_SMS_SEND_FAIL,
                                                NULL,
                                                NULL));

#else
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_set_unsent_msg_status);
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_get_unsent_msg_status);
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_set_unsent_msg_status_ext);
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
        
    }

    AVK_LOG_EX(0 == srv_sms_get_msg_list_index(&inbox, g_p_msg_sms_ctx->msg_id));
    AVK_LOG(bRet = srv_sms_get_msg_recent_event_flag(g_p_msg_sms_ctx->msg_id));                    
    if (bRet)
    {
        AVK_LOG_NORMAL(srv_sms_clear_msg_recent_event_flag(g_p_msg_sms_ctx->msg_id));
    }
    else
    {
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)    
        AVK_LOG_NORMAL(srv_sms_clear_all_sms_recent_event_flag());
#else
        AVK_LOG_FUN_UNSUPPORTED(srv_sms_clear_all_sms_recent_event_flag);
#endif
    }
        
    AVK_LOG_EX(srv_sms_check_ucs2_number((S8*)L"13810728894"));
    AVK_LOG_EX(srv_sms_is_msg_exist(g_p_msg_sms_ctx->msg_id));
    
    (g_p_msg_sms_ctx->sms_data).para_flag = SRV_SMS_PARA_CONTENT_EMS;
    (g_p_msg_sms_ctx->sms_data).content_ems = srv_sms_malloc_ems_data();
    
    srv_sms_read_msg(
        g_p_msg_sms_ctx->msg_id,
        MMI_FALSE,
        &g_p_msg_sms_ctx->sms_data,
        avk_msg_sms_cb_001,
        (void *)0xDEAD);
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_save_cb_001
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_save_cb_001(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data != (void*)0xDEAD) ||
        !cb->result)
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }
    AVK_ASYN_DONE();
}
/*****************************************************************************
 * FUNCTION
 *  vs_appser_msg_sms_save_set
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_save_set(SMS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME save_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG(srv_sms_set_7bit_setting(srv_sms_is_7bit_setting(SRV_SMS_SIM_1), SRV_SMS_SIM_1));
    AVK_LOG(srv_sms_set_address(handle, (S8*)L"123456"));
    AVK_LOG_NORMAL(srv_sms_set_content(handle,(S8*)L"123", 8));
    AVK_LOG_NORMAL(srv_sms_set_pid(handle, SRV_SMS_PID_DEFAULT));
    AVK_LOG_NORMAL(srv_sms_set_content_dcs(handle, SRV_SMS_DCS_UCS2));

    AVK_LOG_NORMAL(srv_sms_set_status_report(handle, MMI_TRUE));
    AVK_LOG_NORMAL(srv_sms_set_reply_path(handle, MMI_FALSE));
    memset(&save_time, 0, sizeof(MYTIME));
    AVK_LOG_NORMAL(srv_sms_set_save_timestamp(handle, &save_time));
    AVK_LOG_NORMAL(srv_sms_set_class_type(handle, SRV_SMS_CLASS_1));
    AVK_LOG_NORMAL(srv_sms_set_status(handle, SRV_SMS_STATUS_UNREAD));
    AVK_LOG_NORMAL(srv_sms_set_storage_type(handle, SRV_SMS_STORAGE_ME));

        /* Can't test EMS */
    AVK_LOG_FUN(srv_sms_set_content_file,AVK_PASS);
    AVK_LOG_FUN(srv_sms_set_content_ems,AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_002_entry
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_SMS_CASE_2,AVK_SMS_CASE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG(g_p_msg_sms_ctx->handle = srv_sms_get_save_handle());
    avk_msg_sms_save_set(g_p_msg_sms_ctx->handle);
    AVK_LOG_FUN_ASYN(srv_sms_save_msg);
    srv_sms_save_msg(
        g_p_msg_sms_ctx->handle,
        avk_msg_sms_save_cb_001,
        (void*)0xDEAD);
}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_send_cb_004
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_send_cb_004(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD))
    {
        StopTimer(ALIGN_TEST_TM_ID);
    }
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_003_timer_cb_004
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_003_timer_cb_004(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_send_port_data_struct send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&send_data, 0, sizeof(send_data));
    app_ucs2_strcpy((kal_int8 *)g_p_msg_sms_ctx->content_buff, (const kal_int8 *)L"Hello UCS2");
    AVK_LOG_NORMAL(srv_sms_send_ucs2_text_msg(
        (S8*)g_p_msg_sms_ctx->content_buff,
        (S8*)g_p_msg_sms_ctx->number,
        SRV_SMS_SIM_1,
        avk_msg_sms_send_cb_004,
        (void *)0xDEAD));
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_send_cb_003
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_send_cb_003(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD))
    {
        StartTimer(ALIGN_TEST_TM_ID, 200, avk_msg_sms_003_timer_cb_004);
    }
	else
	{
        AVK_ASYN_DONE();
	}
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_003_timer_cb_003
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_003_timer_cb_003(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 asc_num[81];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_ucs2_str_to_asc_str((kal_int8 *)asc_num, (kal_int8 *)g_p_msg_sms_ctx->number);
    app_strlcpy((S8*)g_p_msg_sms_ctx->content_buff, "Hello", 19);
    AVK_LOG_NORMAL(srv_sms_send_asc_text_msg(
        (S8*)g_p_msg_sms_ctx->content_buff,
        (S8*)asc_num,
        SRV_SMS_SIM_1,
        avk_msg_sms_send_cb_003,
        (void *)0xDEAD));
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_send_cb_002
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_send_cb_002(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD))
    {
        StartTimer(ALIGN_TEST_TM_ID, 200, avk_msg_sms_003_timer_cb_003);
    }
    else
    {
        AVK_ASYN_DONE();;
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_003_timer_cb_002
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_003_timer_cb_002(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_send_port_data_struct send_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&send_data, 0, sizeof(send_data));
    send_data.number = (S8*)g_p_msg_sms_ctx->number;
    send_data.sim_id = SRV_SMS_SIM_1;
    send_data.content_buff = (S8*)L"ABC";
    send_data.content_size = 3;
    AVK_LOG_NORMAL(srv_sms_send_data_msg(
        &send_data,
        avk_msg_sms_send_cb_002,
        (void *)0xDEAD));

}

/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_send_cb_fail
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_send_cb_fail(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD)&&!cb->result)
	{
	    AVK_LOG_FUN(srv_sms_abort_send,AVK_PASS);
        StartTimer(ALIGN_TEST_TM_ID, 200, avk_msg_sms_003_timer_cb_002);
	}
	else
	{
	    AVK_LOG_FUN(srv_sms_abort_send,AVK_FAIL);
        AVK_ASYN_DONE();
	}
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_prepare
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME save_time;
    srv_sms_setting_struct *setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG(g_p_msg_sms_ctx->handle = srv_sms_get_send_handle());
    AVK_LOG_NORMAL(srv_sms_set_address(g_p_msg_sms_ctx->handle, (S8*)g_p_msg_sms_ctx->number));
    AVK_LOG_NORMAL(srv_sms_set_content(g_p_msg_sms_ctx->handle,(S8*)L"123", 8));
    
    AVK_LOG_NORMAL(setting = (srv_sms_setting_struct*)srv_sms_get_default_setting(SRV_SMS_SIM_1));
    AVK_LOG_NORMAL(srv_sms_set_pid(g_p_msg_sms_ctx->handle, setting->pid));
    AVK_LOG_NORMAL(srv_sms_set_content_dcs(g_p_msg_sms_ctx->handle, SRV_SMS_DCS_UCS2));
    AVK_LOG_NORMAL(srv_sms_set_status_report(g_p_msg_sms_ctx->handle, setting->status_report));
    AVK_LOG_NORMAL(srv_sms_set_reply_path(g_p_msg_sms_ctx->handle, setting->reply_path));
    AVK_LOG_NORMAL(srv_sms_set_data_port(g_p_msg_sms_ctx->handle, 100, 50));
    memset(&save_time, 0, sizeof(MYTIME));
    AVK_LOG_NORMAL(srv_sms_set_save_timestamp(g_p_msg_sms_ctx->handle, &save_time));
    AVK_LOG_NORMAL(srv_sms_set_class_type(g_p_msg_sms_ctx->handle, SRV_SMS_CLASS_1));
    AVK_LOG_NORMAL(srv_sms_set_sim_id(g_p_msg_sms_ctx->handle, SRV_SMS_SIM_1));
    AVK_LOG_NORMAL(srv_sms_set_vp(g_p_msg_sms_ctx->handle, setting->vp));
    AVK_LOG_NORMAL(srv_sms_set_reply_msg_id(g_p_msg_sms_ctx->handle, srv_sms_get_msg_id(SRV_SMS_BOX_INBOX, 0)));
    AVK_LOG_NORMAL(srv_sms_set_send_type(g_p_msg_sms_ctx->handle, SRV_SMS_BG_SEND));
    AVK_LOG_NORMAL(srv_sms_set_mms(g_p_msg_sms_ctx->handle, MMI_FALSE));
    AVK_LOG_NORMAL(srv_sms_set_not_allow_empty_sc(g_p_msg_sms_ctx->handle));
    AVK_LOG_NORMAL(srv_sms_set_no_sending_icon(g_p_msg_sms_ctx->handle));
    AVK_LOG_NORMAL(srv_sms_set_counter_without_change(g_p_msg_sms_ctx->handle));
    AVK_LOG_NORMAL(srv_sms_clear_send_callback(g_p_msg_sms_ctx->handle));
    //srv_sms_set_sc_address(g_p_msg_sms_ctx->handle, (S8*)L"98989");
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_003_timer_cb_001
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_003_timer_cb_001(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_msg_sms_prepare();
    srv_sms_send_msg(g_p_msg_sms_ctx->handle, avk_msg_sms_send_cb_fail, (void*)0xDEAD);
    srv_sms_abort_send(g_p_msg_sms_ctx->handle);
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_send_cb_001
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_send_cb_001(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD))
    {
        AVK_LOG_FUN(srv_sms_send_msg,AVK_PASS);
        StartTimer(ALIGN_TEST_TM_ID, 200, avk_msg_sms_003_timer_cb_001);
    }
    else
    {
        AVK_LOG_FUN(srv_sms_send_msg,AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_003_entry
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_SMS_CASE_3,AVK_SMS_CASE_INIT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_msg_sms_prepare();
    srv_sms_send_msg(g_p_msg_sms_ctx->handle, avk_msg_sms_send_cb_001, (void*)0xDEAD);
    
    AVK_LOG_EX(srv_sms_is_send_action_busy());
    AVK_LOG_EX(srv_sms_is_bg_send_action_busy());
    AVK_LOG_EX(srv_sms_check_send_action_pending(SRV_SMS_BG_SEND));
    
    AVK_LOG_EX(srv_sms_check_dst_number((U8 *)"+9876",5));
    AVK_LOG_EX(srv_sms_check_sc_number((U8 *)"+9876",5)); 
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_del_event_hdlr
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL avk_msg_sms_del_event_hdlr(srv_sms_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AVK_LOG_NORMAL(srv_sms_clear_interrupt_event_handler(
        EVT_ID_SRV_SMS_DEL_MSG,
        avk_msg_sms_del_event_hdlr,
        (void*)0xDEAD));
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_get_list_cb
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_get_list_cb(srv_sms_callback_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_query_msg_cb_struct *sms;
    U32 counter, max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cb->user_data == (void*)0xDEAD) &&
        cb->result)
    {
        switch(cb->action)
        {
        case SRV_SMS_ACTION_QUERY:
            sms = (srv_sms_query_msg_cb_struct*)cb->action_data;
            max_count = (sms->msg_num > 16) ? 16: sms->msg_num;
            AVK_LOG_NORMAL(srv_sms_set_interrupt_event_handler(
                EVT_ID_SRV_SMS_DEL_MSG,
                avk_msg_sms_del_event_hdlr,
                (void*) 0xDEAD));
                
            if (max_count == 0)
            {
                srv_sms_clear_interrupt_event_handler(
                    EVT_ID_SRV_SMS_DEL_MSG,
                    avk_msg_sms_del_event_hdlr,
                    (void*)0xDEAD);
                AVK_CASE_RESULT(AVK_FAIL);
                AVK_ASYN_DONE();
                return;
            }

            for (counter = 0; counter < max_count; counter++)
            {
                g_p_msg_sms_ctx->query_msg_list[counter] = sms->msg_id_list[counter];
                AVK_LOG_NORMAL(srv_sms_copy_msg_list(
                    SRV_SMS_BOX_INBOX,
                    SRV_SMS_STORAGE_ME,
                    SRV_SMS_SIM_1,
                    avk_msg_sms_get_list_cb,
                    (void*)0xDEAD));
            }
            break;
        case SRV_SMS_ACTION_COPY:
            AVK_LOG_NORMAL(srv_sms_move_msg_list(
                SRV_SMS_BOX_DRAFTS,
                SRV_SMS_STORAGE_ME,
                SRV_SMS_SIM_1,
                avk_msg_sms_get_list_cb,
                (void *)0xDEAD));
            break;
        case SRV_SMS_ACTION_MOVE:
            AVK_LOG_NORMAL(srv_sms_delete_msg_list(
                SRV_SMS_BOX_UNSENT,
                SRV_SMS_SIM_1,
                avk_msg_sms_get_list_cb,
                (void*)0xDEAD));
            break;

        case SRV_SMS_ACTION_DELETE:
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;
        }
    }
    else
    {
        AVK_CASE_RESULT(AVK_FAIL);
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_get_list
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_msg_sms_get_list(srv_sms_query_struct * query_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(query_data, 0, sizeof(srv_sms_query_struct));
    query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;

    AVK_LOG_NORMAL(srv_sms_query_msg(query_data, avk_msg_sms_get_list_cb, (void*)0xDEAD));
}


/*****************************************************************************
 * FUNCTION
 *  avk_msg_sms_004_entry
 * DESCRIPTION
 *  Simple program to test SMS API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_SMS_CASE_4,AVK_SMS_CASE_INIT) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_query_struct query_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_msg_sms_get_list(&query_data);
}

AVK_CASE(AVK_SMS_DEINIT,AVK_MSG_SMS) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_FREE(g_p_msg_sms_ctx);
	AVK_CASE_RESULT(AVK_PASS);
}


