/*******************************************************************************************
 * Filename:Track_cust_fall_down.c
 * Author :   liwen
 * Date :      2017/4/7
 * Comment:
 ******************************************************************************************/
#if defined __DROP_ALM__
/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
//#define FALL_DEBUG                                                  //正式软件请关闭
//#define SECOND_CRASH_CHECK                            //是否加入二次撞击检测


#define BMA250_G_RANGE_8G             

#if defined(BMA250_G_RANGE_8G)//根据直杆下落模拟跌倒数据调教的参数

#define FALL_THRESHOLD_VALUE              2100       //判断为下落的三轴平方和阈值
#define CRASH_THRESHOLD_VALUE           70000   //判断为撞击的三轴平方和阈值
#define STATIC_MIN                                   3000     //撞击后静止阈值范围
#define STATIC_MAX                                  6000     //
#define FALL_MIN                                       1100     //下落时波谷需低于此值
#define BARRIERS_TO_FALL                        450000//撞击大于此值则直接进入检静止状态
#define SECOND_CRASH                             8000     //第二次撞击值
#define TROUGH                                          2000    //撞击后的波谷值
#define POSTURE_OFFET                              2000    //跌倒前后姿态变化需超过此值
#define POSTURE_MIN                                 3700     //符合姿态获取阈值
#define POSTURE_MAX                                 4600     //
#define FREE_FALL                                       350       //用于过滤上抛平抛和自由落体
#define FREE_FALL2                                     100      //用于过滤上抛平抛和自由落体

#define FREE_FALL_PROPORTION                 0.6        //用于过滤上抛平抛和自由落体
#define FREE_FALL_PROPORTION2                 0.4       //用于过滤上抛平抛和自由落体

#endif

#define min(a,b) ((a) > (b) ? (b) : (a))
#define FALL_CONFIRM                               9         //下落确认计数
#if defined(SECOND_CRASH_CHECK)
#define CHECK_CRASH_TIME                      60        //确认下落后检测碰撞的时间范围(单位SAMPLE_INTERVAL  ms)
#else
#define CHECK_CRASH_TIME                      30      
#endif
#define FORBID_TIME                                 100       //静默时间(单位SAMPLE_INTERVAL  ms)
#define SAMPLE_INTERVAL                         10         //采样间隔ms
#define CHECK_STATIAC_COUNT               30         // 检到撞击后需检到连续20*SAMPLE_INTERVAL  ms的静止状态
#define CHECK_STATIAC_TIME                   100         //检静止超时时间



#define GET_XYZ                                        OTA_acc_sensor_get_6bytes
/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_bool get_fall_min=FALSE,try_check_crash=FALSE,try_check_static=FALSE;
static kal_uint8 fall_count;
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
void track_cust_fall_down(kal_uint8 arg);

/******************************************************************************
 *  Function    -  track_cust_send_fall_alm_msg
 *
 *  Purpose     -  跌倒报警触发
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-04-2017,  xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_send_fall_alm_msg()
{
	static kal_uint32 tick=0,cur_tick=0;
	if(cur_tick==0)
	{
		cur_tick = kal_get_systicks();
	}
	else
	{
		tick = kal_get_systicks();
		if(tick - cur_tick > KAL_TICKS_1_SEC*2)
        {
            cur_tick = 0;
        }
		else
		{
			LOGD(L_APP,L_V7,"跌倒报警静默时间内!!");
			return;
		}
	}
	LOGD(L_APP,L_V3,"跌倒报警触发，发送消息通知应用");
	track_fun_msg_send(MSG_ID_DROP_ALM_IND, NULL, MOD_MMI, MOD_MMI);
}
static char *str_dropalm_en = "Attention! Fall Alarm!"; /*Attention! The door is open!*/
static char str_dropalm_cn[] =/*注意！摔倒报警！*/
{
    0x6C,0xE8,0x61,0x0F,0x00,0x21,0x00,0x20,0x64,0x54,0x50,0x12,0x62,0xA5,0x8B,0x66,0x00,0x21
};

void drop_sms()
{
    struct_msg_send g_msg = {0};
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_dropalm_en);
    g_msg.msg_cn_len = sizeof(str_dropalm_cn);
    memcpy(g_msg.msg_cn, str_dropalm_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
}
/******************************************************************************
 *  Function    -  track_cust_send_fall_alm_msg
 *
 *  Purpose     -  跌倒报警处理
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-04-2017,  xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_drop_alm()
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, "");

    if(G_parameter.drop_alm.sw == 0)
    {
        return;
    }

    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_DROP_ALM, KAL_FALSE, 0);
    }
    if(G_parameter.drop_alm.alarm_type == 1||G_parameter.door_alarm.alarm_type == 2)
    {
        drop_sms();
    }
    if(G_parameter.door_alarm.alarm_type == 2||G_parameter.door_alarm.alarm_type == 3)
    {
        track_start_timer(TRACK_CUST_ALARM_DOOR_Call_TIMER,30*1000, track_cust_make_call, (void*)1);
    }
}


/******************************************************************************
 *  Function    -  track_cust_fall_down
 *
 *  Purpose     -  跌倒检测
 *
 *  Description -  1停止并查询;2开启检测;
 *
 *  modification history
 * ----------------------------------------
 * v1.3  , 10-04-2017,  liwen  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_fall_down(kal_uint8 arg)
{
#if defined(FALL_DEBUG)
    static kal_uint32 data[2000]={0};
    static kal_int16 record_x[10]={0},record_y[10]={0},record_z[10]={0},record_xx[10]={0},record_yy[10]={0},record_zz[10]={0};
    static kal_uint16 i;
    static kal_uint8 count;
#endif
#if defined(SECOND_CRASH_CHECK) 
    static kal_uint8 try_check_2crash,check_2high;
#endif
    static kal_bool forbid_fall=FALSE,valid=FALSE,get_fall_min=FALSE,try_check_crash=FALSE,try_check_static=FALSE;
    static kal_int16 x,y,z,XX,YY,ZZ;
    static kal_uint32 sum;
    static kal_uint8 check_static,fall_count,free_fall,free_fall2,Gcount;
    static kal_uint16 fall_down_fail,fall_down_alarm_count,free_fall_count2,free_fall_count,check_static_overtime;
    
    if(arg==0)
    {
        if(forbid_fall==FALSE)
        {
            GET_XYZ(&x,&y,&z);
            sum=x*x+y*y+z*z;
#if defined(FALL_DEBUG)
            if(i<1999) 
            {
                data[i]=sum;
                i++;
                if(sum>STATIC_MIN&&sum<STATIC_MAX)
                {
                    count++;
                    if(count==10)
                    {
                        i-=10;
                        if(i)
                        {
                            if(data[i-1]>8)
                            {
                                data[i++]=0;
                            }
                            else
                            {
                                data[i-1]+=1;
                            }
                        }
                        count=0;
                    }
                }
                else
                {
                    count=0;
                }
            }
#endif
            //跌倒检测
            if(sum<FALL_THRESHOLD_VALUE&&try_check_crash==FALSE&&try_check_static==FALSE)
            {
                fall_count++;
                if(fall_count==1)
                {
                    get_fall_min=FALSE;
                    free_fall=0;
                    free_fall2=0;
                    Gcount=0;
                }
                if(sum<FALL_MIN)
               {
                    get_fall_min=TRUE;
                    if(sum<FREE_FALL)
                    {
                        free_fall++;
                    }
                    if(sum<FREE_FALL2)
                    {
                        free_fall2++;
                    }
                }
                if(fall_count>=FALL_CONFIRM)
                {
                    if(get_fall_min==TRUE)
                    {
                        try_check_crash=TRUE;
                        fall_count=0;
                        get_fall_min=FALSE;
                    }
                    else
                    {
                        fall_count=FALL_CONFIRM-1;
                    }
                }
            }
            else if(try_check_crash==TRUE)
            {
                fall_count++;
                if(fall_count>=CHECK_CRASH_TIME)
                {
                    try_check_crash=FALSE;
                    fall_count=0;
#if defined(SECOND_CRASH_CHECK) 
                    try_check_2crash=0;
#endif
                }
                else
                {
#if defined(SECOND_CRASH_CHECK) 
                    if(sum>BARRIERS_TO_FALL||(try_check_2crash==2&&sum>SECOND_CRASH&&(fall_count-check_2high)>3))
                    {
                        fall_count=0;
                        try_check_2crash=0;
                        try_check_crash=FALSE; 
                        try_check_static=TRUE;
                    }
                    else
                    {
                        if(try_check_2crash==0&&sum>CRASH_THRESHOLD_VALUE)
                        {
                            try_check_2crash=1; 
                            check_2high=fall_count;
                        }
                        else if(try_check_2crash==1&&sum<TROUGH)
                        {
                            try_check_2crash=2; 
                        }
                    }
#else
                   if(sum>CRASH_THRESHOLD_VALUE)
                   {
                        if((float)free_fall/(fall_count+FALL_CONFIRM-1)>FREE_FALL_PROPORTION||(float)free_fall2/(fall_count+FALL_CONFIRM-1)>FREE_FALL_PROPORTION2)
                        {
                            free_fall_count2++;//记录因波谷不符合被过滤的次数
                            forbid_fall=TRUE;
                            fall_count=80;
                        }
                        else
                        {
                            try_check_static=TRUE;
                            Gcount=0;
                            fall_count=0;
                        }
                        try_check_crash=FALSE;
                   }
                   else if(sum<FREE_FALL)
                   {
                       if(sum<FREE_FALL2)
                       {
                            free_fall2++;
                       }
                       free_fall++;
                   }
                   else if(sum>3000)
                   {
                        Gcount++;
                        if(Gcount>=3)
                        {
                            free_fall_count++;
                            try_check_crash=FALSE;
                            fall_count=0;
                        }
                   }
#endif                    
                }
            }
            else if(try_check_static==TRUE)
            {
                fall_count++;
                if(fall_count<=CHECK_STATIAC_TIME)
                {
                    if(sum>STATIC_MIN&&sum<STATIC_MAX)
                    {
                        check_static++;
                        if(check_static>=CHECK_STATIAC_COUNT)
                        {
                                if((x-XX)*(x-XX)+(y-YY)*(y-YY)+(z-ZZ)*(z-ZZ)>POSTURE_OFFET)
                                {
                                    //检测到跌倒
                                    fall_down_alarm_count++;
                                    //forbid_fall=TRUE;
                                    track_cust_send_fall_alm_msg();
                                }
                                else
                                {
                                    fall_down_fail++;//记录因姿态不符合被过滤的次数
#if defined(FALL_DEBUG)
                                    if(fall_down_fail<=10)
                                    {
                                        record_x[fall_down_fail-1]=x;
                                        record_y[fall_down_fail-1]=y;
                                        record_z[fall_down_fail-1]=z;
                                        record_xx[fall_down_fail-1]=XX;
                                        record_yy[fall_down_fail-1]=YY;
                                        record_zz[fall_down_fail-1]=ZZ;
                                    }
#endif                                    
                                }
                            try_check_static=FALSE;
                            fall_count=0;
                            check_static=0;
                        }
                    }
                    else
                    {
                        check_static=0;
                    }
                }
                else
                {
                    try_check_static=FALSE;
                    fall_count=0;
                    check_static=0;
                    check_static_overtime++;//记录因静止不满足被过滤的次数
                }
                
            }
            else
            {
                fall_count=0;
                if(sum>POSTURE_MIN&&sum<POSTURE_MAX)
                {
                    XX=x;
                    YY=y;
                    ZZ=z;
                }
            }
        }
        else
        {
           fall_count++;
            if(fall_count>=FORBID_TIME)
            {
                forbid_fall=FALSE;
                fall_count=0;
                get_fall_min=FALSE;
            }
        }
        track_start_timer(TRACK_CUST_FALL_TIMER_ID,SAMPLE_INTERVAL,track_cust_fall_down, (void *) arg);
    }
    else
    {
        track_stop_timer(TRACK_CUST_FALL_TIMER_ID);
        try_check_crash=FALSE;
        try_check_static=FALSE;
        forbid_fall=FALSE;
        get_fall_min=FALSE;
        fall_count=0;
        free_fall=0;
        free_fall2=0;
        Gcount=0;
        check_static=0;
#if defined(SECOND_CRASH_CHECK) 
        try_check_2crash=0;
#endif
        if(arg==1)
        {
#if defined(FALL_DEBUG)
            U16 j;
            for(j=0;j<=i;j++)
            {
                LOGS("%d",data[j]);
            }
            for(j=0;j<min(fall_down_fail,10);j++)
            {
                LOGS("(%d,%d,%d)(%d,%d,%d)",record_xx[j],record_yy[j],record_zz[j],record_x[j],record_y[j],record_z[j]);
            }
#endif
            LOGD(L_APP,L_V6,"跌倒次数:%d;被过滤:[(姿态)%d,(波谷)%d+%d,(静止)%d];是否有效:%d",fall_down_alarm_count,fall_down_fail,free_fall_count2,free_fall_count,check_static_overtime,valid);
            valid=FALSE;
            LOGD(L_APP,L_V6,"[检测结束]");
        }
        else
        {
#if defined(FALL_DEBUG)
           i=0;
           count=0;
#endif
           fall_down_alarm_count=0;
           fall_down_fail=0;
           free_fall_count2=0;
           free_fall_count=0;
           check_static_overtime=0;
           valid=TRUE;
           track_cust_fall_down(0);
           LOGD(L_APP,L_V6,"[开启跌倒检测]");
        }
    }
}
#endif
