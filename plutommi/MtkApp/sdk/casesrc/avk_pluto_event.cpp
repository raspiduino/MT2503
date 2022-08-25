extern "C"
{
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
}

#define VS_FW_POST_EVENT_MASK 0x00000001
#define VS_FW_POST_EVENT_EX_MASK 0x00000002
#define VS_FW_POST_EVENT_EX_RESULT_MASK 0x00000004
#define VS_FW_SEND_EVENT_MASK 0x00000008
#define VS_FW_GET_EVENT_ID_MASK 0x00000010
#define VS_FW_GET_USER_DATA_MASK 0x00000020
#define VS_FW_EVENT_CLEAR_PROTOCOL_MASK 0x00000040
//#define VS_FW_EVENT_BLK_GEN_MASK 0x00000080
//#define VS_FW_EVENT_BLK_INT_MASK 0x00000100
//#define VS_FW_EVENT_CLR_INT_MASK 0x00000200
//#define VS_FW_EVENT_KEEP_INT_MASK 0x00000400
#define VS_FW_TIMER_EXIST_MASK 0x00000800
#define VS_FW_TIMER_SUSPEND_MASK 0x00001000
#define VS_FW_TIMER_RESUME_MASK 0x00002000
#define VS_FW_TIMER_GET_TIME_MASK 0x00004000
#define VS_FW_TIMER_SET_TIME_MASK 0x00008000
#define VS_FW_TIMER_MASK_ITEM_MASK 0x00010000
#define VS_FW_TIMER_MASK_ITEM_U8_MASK 0x00020000
#define VS_FW_TIMER_MASK_STRING_MASK 0x00040000
#define VS_FW_EVENT_EMIT_MASK 0x00080000
#define VS_FW_EVENT_EMIT_POST_MASK 0x00100000
#define VS_FW_EVENT_EMIT_POST_EX_MASK 0x00200000
#define VS_FW_EVENT_HAS_REG_MASK 0x00400000
#define VS_FW_EVENT_DEREG_MASK 0x00800000 

#define VS_FW_EVENT_001_PASS_MASK 0x0000003F
#define VS_FW_EVENT_002_PASS_MASK 0x0000F840
#define VS_FW_EVENT_003_PASS_MASK 0x00E80000


#define ALIGN_TEST_TM_ID        MMI_TIMER_BASE
#define AVK_PLUTO_EVENT_TIMER_ID AVK_PLUTO_TIMER_TEST_BASE + 4


U32 avk_pluto_event_result = 0;
MMI_BOOL g_avk_pluto_dereg_done;
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_callback
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_001_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_EX(mmi_frm_get_evt_id(evt) == 0xFFEE);
    AVK_LOG_EX(mmi_frm_get_evt_user_data(evt) == (void*)0xABCD);
    avk_pluto_event_result |= VS_FW_POST_EVENT_MASK;
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_cb_2
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_001_cb_2(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_POST_EVENT_EX_MASK;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_proc_cb_3
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_001_proc_cb_3(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_SEND_EVENT_MASK;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_result_cb
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_001_result_cb(mmi_post_result_event_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_POST_EVENT_EX_RESULT_MASK;
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_timer_cb
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_001_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_FUN(MMI_FRM_POST_EVENT,avk_pluto_event_result & VS_FW_POST_EVENT_MASK);
    AVK_LOG_FUN(MMI_FRM_POST_EVENT_EX,(avk_pluto_event_result & VS_FW_POST_EVENT_MASK)&&
                avk_pluto_event_result & VS_FW_POST_EVENT_EX_RESULT_MASK);
    AVK_LOG_FUN(MMI_FRM_SEND_EVENT,avk_pluto_event_result & VS_FW_SEND_EVENT_MASK);
    StopTimer(0x1234);
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_001_entry
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_EVENT_AUTO_001,AVK_PLUTO_EVENT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result = 0;
    MMI_FRM_INIT_EVENT(&evt, 0);
    evt.evt_id = 0xFFEE;
    MMI_FRM_POST_EVENT(&evt, avk_pluto_event_001_callback, (void*)0xABCD);
    
    
    MMI_FRM_INIT_EVENT(&evt, 0);
    MMI_FRM_POST_EVENT_EX(&evt,
                          avk_pluto_event_001_cb_2,
                          (void*)0xC0DE,
                          avk_pluto_event_001_result_cb,
                          (void*)0xDEAD);       
    
    MMI_FRM_SEND_EVENT(&evt, avk_pluto_event_001_proc_cb_3, NULL); 
    
    StartTimer(0x1234, 500, avk_pluto_event_001_timer_cb);
                          
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_pluto_event_002_msg_hdlr
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 avk_pluto_pluto_event_002_msg_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    avk_pluto_event_result &= ~VS_FW_EVENT_CLEAR_PROTOCOL_MASK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_send_msg_to_mmi
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_send_msg_to_mmi(U16 eventID, void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type)eventID;
    ilm_ptr->local_para_ptr = (local_para_struct *)buff;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_pluto_event_gpio_srv
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_pluto_event_gpio_srv(MMI_BOOL is_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct *gpioDetectInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpioDetectInd = (mmi_eq_gpio_detect_ind_struct*)
        construct_local_para(sizeof(mmi_eq_gpio_detect_ind_struct), TD_CTRL);

    gpioDetectInd->gpio_device = EXT_DEV_EARPHONE;
    gpioDetectInd->on_off = is_in;
    avk_pluto_send_msg_to_mmi(MSG_ID_MMI_EQ_GPIO_DETECT_IND, (void*)gpioDetectInd);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb_7
 * DESCRIPTION
 *  Simple program to test Timer API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (avk_pluto_event_result == VS_FW_EVENT_002_PASS_MASK)
    //{
        AVK_CASE_RESULT(AVK_PASS);
    //}
    /*else
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }*/
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_pluto_get_time_cb_2
 * DESCRIPTION
 *  Simple program to test Timer API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_pluto_get_time_cb_2(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_TIMER_SET_TIME_MASK;
}

extern "C" void L4SetClock(rtc_format_struct datetime, oslTaskFuncPtr FuncRspPtr);

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_pluto_get_time_cb
 * DESCRIPTION
 *  Simple program to test Timer API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_pluto_get_time_cb(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rtc_format_struct datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    datetime.rtc_day = 16;
    datetime.rtc_mon = 11;
    datetime.rtc_year = 100;
    datetime.rtc_hour = 0;
    datetime.rtc_min = 0;
    datetime.rtc_min = 0;
    datetime.rtc_sec = 0;
    datetime.rtc_wday = 0;

    avk_pluto_event_result |= VS_FW_TIMER_GET_TIME_MASK;
    L4SetClock(datetime, avk_pluto_pluto_get_time_cb_2);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb_5
 * DESCRIPTION
 *  Simple program to test Timer API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_TIMER_RESUME_MASK;
    L4GetClockTime(avk_pluto_pluto_get_time_cb);
    StartTimer(ALIGN_TEST_TM_ID, 1000, avk_pluto_event_002_timer_cb_7);
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb_3
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AVK_PLUTO_EVENT_TIMER_ID);
    mmi_frm_resume_timers(TIMER_IS_ALIGNMENT);
    StartTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_002_timer_cb_5);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb_6
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result &= ~VS_FW_TIMER_SUSPEND_MASK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb_2
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(AVK_PLUTO_EVENT_TIMER_ID, 50, avk_pluto_event_002_timer_cb_6);
    avk_pluto_event_result |= VS_FW_TIMER_SUSPEND_MASK;
    StartNonAlignTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_002_timer_cb_3);
    mmi_frm_suspend_timers(TIMER_IS_ALIGNMENT);

}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_pluto_event_002_msg_hdlr_2
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 avk_pluto_pluto_event_002_msg_hdlr_2(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_DUAL_SIM__) && defined (__MMI_DUAL_SIM_BACKWARD_COMPATIBILE__)
/* under construction !*/
/* under construction !*/
#else
    AVK_LOG_FUN_UNSUPPORTED(mmi_frm_clear_slave_protocol_event_handler);
#endif 

    StartTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_002_timer_cb_2);
    if (IsMyTimerExist(ALIGN_TEST_TM_ID))
    {
        avk_pluto_event_result |= VS_FW_TIMER_EXIST_MASK;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_timer_cb
 * DESCRIPTION
 *  Simple program to test Screen API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_DUAL_SIM__) && defined (__MMI_DUAL_SIM_BACKWARD_COMPATIBILE__)
/* under construction !*/
#else
    avk_pluto_pluto_event_002_msg_hdlr_2(NULL);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_entry
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_002_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_INJECT_STRING_RSP, avk_pluto_pluto_event_002_msg_hdlr, MMI_FALSE);
    AVK_LOG_FUN(mmi_frm_set_protocol_event_handler,AVK_PASS);


    avk_pluto_send_msg_to_mmi(MSG_ID_MMI_INJECT_STRING_RSP, NULL);
    StartTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_002_timer_cb);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_002_pre_entry
 * DESCRIPTION
 *  Simple program to test Event API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_EVENT_AUTO_002,AVK_PLUTO_EVENT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result = VS_FW_EVENT_CLEAR_PROTOCOL_MASK;
//    avk_pluto_clear_int_done = MMI_FALSE;
    avk_pluto_event_002_entry();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_check_1
 * DESCRIPTION
 *  Simple program to test Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_check_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    if (avk_pluto_event_result == VS_FW_TIMER_MASK_ITEM_MASK)
    {
        avk_pluto_event_result |= VS_FW_TIMER_MASK_ITEM_U8_MASK;
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_check_1
 * DESCRIPTION
 *  Simple program to test Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_check_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    if (avk_pluto_event_result == 0)
    {
        avk_pluto_event_result = VS_FW_TIMER_MASK_ITEM_MASK;
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_check_1
 * DESCRIPTION
 *  Simple program to test Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_check_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    if (avk_pluto_event_result & VS_FW_TIMER_MASK_ITEM_U8_MASK)
    {
        avk_pluto_event_result |= VS_FW_TIMER_MASK_STRING_MASK;
    }*/
}

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event_cb
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_003_post_event_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avk_pluto_event_result |= VS_FW_EVENT_EMIT_MASK;
    if (!g_avk_pluto_dereg_done)
    {
        avk_pluto_event_result |= VS_FW_EVENT_DEREG_MASK;
    }
    else
    {
        avk_pluto_event_result &= ~VS_FW_EVENT_DEREG_MASK;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event_cb_2
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_003_post_event_cb_2(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->user_data == (void*)0xDEAD)
    {
        avk_pluto_event_result |= VS_FW_EVENT_EMIT_POST_MASK;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event_timer_cb
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_post_event_timer_cb_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, EVT_ID_GPIO_EARPHONE_PLUG_OUT);
    mmi_frm_cb_emit_event(&event);
   // if (VS_FW_EVENT_003_PASS_MASK == avk_pluto_event_result)
  //  {
        AVK_CASE_RESULT(AVK_PASS);
  //  }
    /*else
    {
        AVK_CASE_RESULT(AVK_FAIL);
    }*/
    AVK_ASYN_DONE();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event_timer_cb
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_post_event_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct event1, event2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event1, EVT_ID_GPIO_EARPHONE_PLUG_OUT);
    MMI_FRM_CB_EMIT_EVENT(&event1);
    MMI_FRM_INIT_EVENT(&event2, EVT_ID_GPIO_EARPHONE_PLUG_IN);
    MMI_FRM_CB_EMIT_POST_EVENT(&event2);
//    MMI_FRM_CB_EMIT_EVENT(&event2);
    g_avk_pluto_dereg_done = MMI_TRUE;
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_EARPHONE_PLUG_OUT,
                           avk_pluto_event_003_post_event_cb,
                           (void*)0xDEAD);
    StartTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_003_post_event_timer_cb_2);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event_result_cb
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret avk_pluto_event_003_post_event_result_cb(mmi_post_result_event_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (arg->user_data == (void*)0xC0DE)
    {
        avk_pluto_event_result |= VS_FW_EVENT_EMIT_POST_EX_MASK;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_post_event
 * DESCRIPTION
 *  Simple program to test emit/post Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_pluto_event_003_post_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG(mmi_frm_cb_reg_event(EVT_ID_GPIO_EARPHONE_PLUG_OUT,
                         avk_pluto_event_003_post_event_cb,
                         (void*)0xDEAD));
    mmi_frm_cb_reg_event(EVT_ID_GPIO_EARPHONE_PLUG_IN,
                         avk_pluto_event_003_post_event_cb_2,
                         (void*) 0xDEAD);
    if (AVK_LOG_EX(mmi_frm_cb_has_event_reg(EVT_ID_GPIO_EARPHONE_PLUG_IN,
                             avk_pluto_event_003_post_event_cb_2,
                             (void*)0xDEAD)))
    {
        avk_pluto_event_result |= VS_FW_EVENT_HAS_REG_MASK;
    }
//    MMI_FRM_INIT_EVENT(&event, EVT_ID_GPIO_EARPHONE_PLUG_IN);
    MMI_FRM_INIT_EVENT(&event, EVT_ID_GPIO_EARPHONE_PLUG_OUT);
    AVK_LOG_NORMAL(MMI_FRM_CB_EMIT_POST_EVENT_EX(
        &event,
        avk_pluto_event_003_post_event_result_cb,
        (void *)0xC0DE));
        
    StartTimer(ALIGN_TEST_TM_ID, 100, avk_pluto_event_003_post_event_timer_cb);    
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_event_003_entry
 * DESCRIPTION
 *  Simple program to test Events API's
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_EVENT_AUTO_003,AVK_PLUTO_EVENT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*    U8 item_count;
    U32 mask_word;
    FuncPtr array[]={avk_pluto_event_003_check_1,
                     avk_pluto_event_003_check_2,
                     avk_pluto_event_003_check_3};
    U16 index[]={0,1,2};
    U8 U8_index[] = {0, 1, 2};
    U32 loop_index;
    U8 str_1[] = "0";
    U8 str_2[] = "1";
    U8 str_3[] = "2";
    U8 *string_index[3];
 */
    KAL_ADM_ID adm_id;
    void *buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    mmi_frm_entry_new_screen(
        SCR_ID_VS_FW_PLUTO_EVENTS_002,
        NULL,
        NULL,
        NULL);*/
    avk_pluto_event_result = 0;
    g_avk_pluto_dereg_done = MMI_FALSE;
/*    string_index[0] = str_1;
    string_index[1] = str_2;
    string_index[2] = str_3;
    mask_word = 0x0002;
    item_count = MaskItems(index, 3, mask_word);
    for (loop_index = 0; loop_index < item_count; loop_index++)
    {
        if (array[index[loop_index]])
        {
            array[index[loop_index]]();
        }
    }
    mask_word = 0x0001;
    item_count = MaskItemsU8(U8_index, 3, mask_word);
    for (loop_index = 0; loop_index < item_count; loop_index++)
    {
        if (array[U8_index[loop_index]])
        {
            array[U8_index[loop_index]]();
        }
    }
    mask_word = 0x0004;
    item_count = MaskStringItems(string_index, 3, mask_word);
    for (loop_index = 0; loop_index < item_count; loop_index++)
    {
        U8 *str = string_index[loop_index];
        U8 count = str[0] - '0';
        if (array[count])
        {
            array[count]();
        }
    }

    adm_id = kal_adm_create((void*)g_avk_pluto_buffer_pool, 512, NULL, MMI_FALSE);
    buff_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(adm_id, 16);
    if (buff_ptr)
    {
        avk_pluto_event_result |= VS_FW_EVENT_ADM_MASK;
    }
    kal_adm_free(adm_id, buff_ptr);
    kal_adm_delete(adm_id);
    */

    avk_pluto_event_003_post_event();
}

