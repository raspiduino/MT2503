extern "C"
{
  #include "AlarmSrvGprot.h"
  #include "DateTimeGprot.h"
}

typedef struct {
	kal_uint8 avk_sec;
	kal_uint8 avk_min;
	kal_uint8 avk_hour;
	kal_uint8 avk_day;
	kal_uint8 avk_mon;
	kal_uint8 avk_wday;
	kal_uint8 avk_year;
} avk_time_rtc_struct;


AVK_ADD_ITEM(AVK_SET_TIME_AUTO,L"Auto case",AVK_SET_TIME);
AVK_ADD_ITEM(AVK_SET_TIME_MANU,L"Manual case",AVK_SET_TIME);
AVK_ADD_ITEM_SPECIAL(AVK_SET_TIME_SPEC,L"Special case",AVK_SET_TIME);

void avk_setting_time_alm_reset_reminder_pass (void)
{
	srv_alm_node_type set_node;
	U8 i;
	memset(&set_node, 0xFF, NUM_OF_ALM); //0xFF is invalid number.
    for (i = 0; i < NUM_OF_ALM; i++)
        srv_alm_write(i, &set_node);
	
	AVK_LOG_FUN(srv_alm_reset_reminder, 1);
}

void avk_setting_time_alm_reset_reminder_fail (void)
{
	srv_alm_node_type set_node;
	U8 i;
	
	memset(&set_node, 0xFF, NUM_OF_ALM); //0xFF is invalid number.
    for (i = 0; i < NUM_OF_ALM; i++)
        srv_alm_write(i, &set_node);

	
	AVK_LOG_FUN(srv_alm_reset_reminder, 0);

}


AVK_MANUAL_CASE(AVK_SET_TIME_CASE_MANU,AVK_SET_TIME_MANU)
{
	MYTIME alm_time;
	//applib_time_struct set_t; 
	avk_time_rtc_struct set_t;
	mmi_event_struct evt;
	srv_alm_node_type set_node, get_node;
	U8 i;

	srv_alm_init(&evt);
	memset(&set_node, 0xFF, NUM_OF_ALM); //0xFF is invalid number.
    memset(&get_node, 0xFF, NUM_OF_ALM);
    for (i = 0; i < NUM_OF_ALM; i++)
        srv_alm_write(i, &set_node);
    
    /*srv_alm_write*/
    memset(&set_node, 0x00, NUM_OF_ALM);
    set_node.Hour = 8;
    set_node.Min = 10;
    set_node.State = 1;
    srv_alm_write(0, &set_node);
	
	/*srv_alm_reset_reminder*/
	set_t.avk_year= 38;
	set_t.avk_mon= 6;
	set_t.avk_day= 30;
	set_t.avk_hour= 8;
	set_t.avk_min= 9;
	set_t.avk_sec= 45;

	/*
	set_t.nYear = 2008;
	set_t.nMonth = 6;
	set_t.nDay = 30;
	set_t.nHour = 8;
	set_t.nMin = 9;
	set_t.nSec = 45;*/

	//GetDateTime(&t);
    SetDateTime(&set_t);
    //mmi_dt_set_rtc_dt(&set_t);
	//void mmi_dt_set_dt(const MYTIME *time, mmi_dt_set_time_res_funcptr callback, void* usr_data)
	srv_alm_reset_reminder();
    //kal_sleep_task(200);
	
	AVK_MANU_SHOW_SCR(L"Please wait 1 more minutes...if alarm wakeup, it is pass, and you must dismiss alarm",avk_setting_time_alm_reset_reminder_pass,avk_setting_time_alm_reset_reminder_fail);
}

void avk_setting_time_alm_pwr_reset(void)
{
	/*srv_alm_pwr_reset*/
    srv_alm_pwr_reset(MMI_TRUE, 10);
}
AVK_SPECIAL_CASE(AVK_SET_TIME_CASE_SPEC,AVK_SET_TIME_SPEC)
{
	AVK_MANU_SHOW_TIPS(L"If you see power on after 10 secs, it's pass",avk_setting_time_alm_pwr_reset);
}


AVK_CASE(AVK_SET_TIME_CASE_AUTO,AVK_SET_TIME_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_alm_node_type set_node, get_node;
    srv_alm_node_type *pget_node = &get_node;
    U8 alm_count, i, alm_list[NUM_OF_ALM];
    MMI_BOOL relval;
    MYTIME alm_time;
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* freq:
        typedef enum
        {
            SRV_REMINDER_REPEAT_OFF,
            SRV_REMINDER_REPEAT_ONCE,
            SRV_REMINDER_REPEAT_HOURLY,
            SRV_REMINDER_REPEAT_EVERYDAY,
            SRV_REMINDER_REPEAT_DAYS,
            SRV_REMINDER_REPEAT_WEEKLY,
            SRV_REMINDER_REPEAT_MONTHLY,
            SRV_REMINDER_REPEAT_SEASONLY,
            SRV_REMINDER_REPEAT_YEARLY,
            SRV_REMINDER_REPEAT_TITHI,
            SRV_REMINDER_REPEAT_CUSTOM,
            SRV_REMINDER_REPEAT_TOTAL
        } srv_reminder_repeat_enum;
      */
      
    /*srv_alm_init*/
	AVK_LOG(MMI_RET_OK == srv_alm_init(&evt));
   
    memset(&set_node, 0xFF, NUM_OF_ALM); //0xFF is invalid number.
    memset(&get_node, 0xFF, NUM_OF_ALM);
    for (i = 0; i < NUM_OF_ALM; i++)
        srv_alm_write(i, &set_node);
    
    /*srv_alm_write*/
    memset(&set_node, 0x00, NUM_OF_ALM);
    set_node.Hour = 8;
    set_node.Min = 10;
    set_node.State = 1;
    srv_alm_write(0, &set_node);
    
    /*srv_alm_node_type *srv_alm_read(U8 index)*/
    pget_node = srv_alm_read(0);
	AVK_LOG_FUN(srv_alm_write,((pget_node->Hour == set_node.Hour) && (pget_node->Min == set_node.Min)));
	AVK_LOG_FUN(srv_alm_read,((pget_node->Hour == set_node.Hour) && (pget_node->Min == set_node.Min)));

    /*srv_alm_active_alms*/
    alm_count = srv_alm_active_alms();
	AVK_LOG_FUN(srv_alm_active_alms,(1 == alm_count));
    

    /*srv_alm_get_alm_time*/
    relval = srv_alm_get_alm_time(&alm_time, 0, MMI_FALSE);
	AVK_LOG_FUN(srv_alm_get_alm_time,((set_node.Hour == alm_time.nHour) && (set_node.Min == alm_time.nMin)));

    /*srv_alm_sort*/  
    memset(&alm_list, 0x00, NUM_OF_ALM);
    alm_list[0] = 0;
	alm_list[1] = 1;
    
    memset(&set_node, 0x00, NUM_OF_ALM);
    set_node.Hour = 5;
    set_node.Min = 20;
    set_node.State = 1;
    srv_alm_write(1, &set_node);
    
    srv_alm_sort(alm_list, sizeof(alm_list), MMI_FALSE, NULL);
    pget_node = srv_alm_read(alm_list[0]);
    
    //kal_prompt_trace(MOD_MMI, "old time: %d:%d, new time: %d:%d\n", set_node.Hour, set_node.Min, pget_node->Hour,pget_node->Min);
    AVK_LOG_FUN(srv_alm_sort,((pget_node->Hour == set_node.Hour) && (pget_node->Min == set_node.Min)));

	/*srv_alm_search*/  
    //memset(&alm_time, 0xFF, sizeof(alm_time));
    GetDateTime(&alm_time);
    alm_time.nHour = 7;
    alm_time.nMin = 10;
    srv_alm_search(alm_list, sizeof(alm_list), &alm_count, &alm_time, NULL);
	AVK_LOG_FUN(srv_alm_search,(1 == alm_count));

    /*srv_alm_get_index*/  
    alm_count = srv_alm_get_index();
	AVK_LOG_FUN(srv_alm_get_index,(2 == alm_count));

    /*srv_alm_reset_reminder*/
    srv_alm_reset_reminder();
    SetDateTime(&alm_time);
    
    kal_sleep_task(2000);
    
}

