extern "C"
{
 #include "app_datetime.h"
}

AVK_ADD_ITEM(AVK_DATE_TIME_AUTO, L"Auto case",AVK_DATE_TIME);



AVK_ASYN_CASE(AVK_DT_GET_RTC_TIME, AVK_DATE_TIME_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	applib_time_struct t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	applib_dt_get_rtc_time(&t);
	if(AVK_LOG_ASYN(applib_dt_is_valid(&t)))
	{
		AVK_CASE_RESULT(AVK_PASS);	  
		AVK_ASYN_DONE();
	}
	else
	{
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}
}


AVK_ASYN_CASE(AVK_DT_IS_LEAP_YEAR, AVK_DATE_TIME_AUTO)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	U16 leap_year[4] = {2000, 2004, 1996, 996};
	U16 normal_year[4] = {1000, 1001, 1700, 1002};
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < 4; i++)
	{
		if(AVK_LOG(!applib_dt_is_leap_year(leap_year[i])))
		{
			AVK_CASE_RESULT(AVK_FAIL);
		}
		else
		{
			AVK_CASE_RESULT(AVK_PASS);
		}
	}
	
	for(i = 0; i < 4; i++)
	{
		if(AVK_LOG(applib_dt_is_leap_year(normal_year[i])))
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

AVK_ASYN_CASE(AVK_DT_IS_LAST_DAY_OF_MON, AVK_DATE_TIME_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 g_dt_day_per_mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 12; i; i--)
	{
		if(AVK_LOG_ASYN(applib_dt_last_day_of_mon((U8)i, 2001) != g_dt_day_per_mon[i - 1]))
		{
			AVK_CASE_RESULT(AVK_FAIL);
			AVK_ASYN_DONE();
			break;
		}
	}
	if(AVK_LOG_ASYN(applib_dt_last_day_of_mon(2, 2000) != 29))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}
	else
	{
		AVK_CASE_RESULT(AVK_PASS);
		AVK_ASYN_DONE();
	}
}

AVK_ASYN_CASE(AVK_DT_UTC_TO_RTC, AVK_DATE_TIME_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	applib_time_struct t;
	applib_time_struct result;
	U32 sec;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	applib_dt_get_rtc_time(&t);
	sec = applib_dt_mytime_2_utc_sec(&t, MMI_FALSE);
	
	AVK_LOG(applib_dt_utc_sec_2_mytime(sec, &result, MMI_FALSE));
	if(!AVK_LOG_ASYN(memcmp(&t, &result, sizeof(applib_time_struct))))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}
	else
	{
		AVK_CASE_RESULT(AVK_PASS);
		AVK_ASYN_DONE();
	}
	
	sec = applib_dt_mytime_2_utc_sec(&t, MMI_TRUE);
	
	AVK_LOG(applib_dt_utc_sec_2_mytime(sec, &result, MMI_TRUE));
	
	if(AVK_LOG_ASYN(!memcmp(&t, &result, sizeof(applib_time_struct))))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		AVK_ASYN_DONE();
	}
	else
	{
		AVK_CASE_RESULT(AVK_PASS);
		AVK_ASYN_DONE();
	}
}

AVK_ASYN_CASE(AVK_DT_GET_DATE_TIME, AVK_DATE_TIME_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	applib_time_struct t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	applib_dt_get_date_time(&t);
	if(AVK_LOG_ASYN(applib_dt_is_valid(&t)))
	{
		AVK_CASE_RESULT(AVK_PASS);	  
	}
	else
	{
		AVK_CASE_RESULT(AVK_FAIL);
	}
	AVK_ASYN_DONE();
}

