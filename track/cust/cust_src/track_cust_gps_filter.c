/******************************************************************************
 * track_cust_gps_filter.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GPS数据过滤，包括静态漂移过滤，GPRS上传数据过滤
 *
 * modification history
 * --------------------
 * v1.0   2010-08-03,  MagicNing create this file
 *
 ******************************************************************************/
#if defined(__GPRS_SEND_FILTER__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define MAX_STATIC_DIFFDATA	    540  

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
typedef enum
{
    High_speed,     // 高速运动
    Low_speed,     // 低速运动
    Stop,                // 静止状态
} State_enum;

/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{            
    kal_int8      hour;
    kal_int8      minute;
    kal_int8      second;
    kal_int16     millisecond;
} mdi_gps_nmea_utc_time_struct;

typedef struct
{            
    kal_int8      year;
    kal_int8      month;
    kal_int8      day;
} mdi_gps_nmea_utc_date_struct;

typedef struct
{            
    double   latitude;          /*latitude*/
    double   longitude;         /*longitude*/
    float   ground_speed;       /*Speed over ground, knots*/
    float   trace_degree;       /*Track mode degrees,north is 0*/
    float   magnetic;
    mdi_gps_nmea_utc_time_struct      utc_time; /*UTC time*/
    mdi_gps_nmea_utc_date_struct      utc_date; /*UTC date*/
    kal_int8      status;       /*Status, V = Navigation receiver warning*/
    kal_int8      north_south;  /*N or S*/
    kal_int8      east_west;    /*E or W*/
    kal_int8      magnetic_e_w; /*Magnetic E or W*/
    kal_int8      cmode;        /*Mode*/
    kal_int8      nav_status;   /*navigational status*/
} mdi_gps_nmea_rmc_struct;

typedef struct
{
	kal_uint32 lat;
	kal_uint32 lon;
}static_datafilter_struct;

typedef struct
{
    kal_uint8 gps_len;
    kal_uint8 lat[4];
    kal_uint8 lon[4];
    kal_uint8 speed;
    kal_uint8 degree[2];
}GPS_DATA_STRUCT;         //GPS信息

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static c_vector* vec_gpsData = NULL;        //缓存前一周期内的GPS 数据，用于校正当前数据
static State_enum state = Stop;              // 当前终端的运动状态

static U16 index=0;


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/
U8 check_datetime[6];
U8 GpsIndex = 0;
static_datafilter_struct now_latlon_data = {0};

U8 LBSSendTimes = 0;



/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/



/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/

static double Get_AverageSpeed(void)
{
    mdi_gps_nmea_rmc_struct* data;

    double averageSpeed = 0;  
    U16 len = 0;
    U16 i = 0;

#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  Get_AverageSpeed()" );
#endif /* __GPS_FILTER_DEBUG__ */   


    len = VECTOR_Size(vec_gpsData);
    if( !len )
    {
        return 1; //  如果缓存数据为空，返回平均速度为1 ，返回0  会导致除法运算溢出
    }
    
    for( i=0; i< len ;i++ )
    {
        data = VECTOR_At(vec_gpsData, i );
        averageSpeed = averageSpeed + data->ground_speed ;
    }
       
    averageSpeed = averageSpeed / len + 0.01 ;

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  len= %d    averageSpeed = %lf ", len , averageSpeed );
#endif /* __GPS_FILTER_DEBUG__ */

    if( 0 == averageSpeed )
    {   
        return 1; // 返回平均速度为1 ，返回0  会导致除法运算溢出
    }
    else
    {
        return averageSpeed; 
    }
 }



static double Get_AverageLatitude(void)
{
    mdi_gps_nmea_rmc_struct* data;

    long double temp = 0;  
    U16 len = 0;
    U16 i = 0;

#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  Get_AverageLatitude()" );
#endif /* __GPS_FILTER_DEBUG__ */ 

    len = VECTOR_Size(vec_gpsData);
    if( !len )
    {
        return 0; //  如果缓存数据为空，返回0  
    }
    
    for( i=0; i< len ;i++ )
    {
        data = VECTOR_At(vec_gpsData, i );
        temp = temp + data->latitude;
    }

    temp = temp / len ;

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  len= %d    averageLatitude = %lf ", len , temp );
#endif /* __GPS_FILTER_DEBUG__ */

        return temp;  
    
}



static double Get_AverageLongitude(void)
{
    mdi_gps_nmea_rmc_struct* data;

    long double temp = 0;  
    U16 len = 0;
    U16 i = 0;

#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  Get_AverageLongitude()" );
#endif /* __GPS_FILTER_DEBUG__ */ 

    len = VECTOR_Size(vec_gpsData);
    if( !len )
    {
        return 1; //  如果缓存数据为空，返回0
    }
    
    for( i=0; i< len ;i++ )
    {
        data = VECTOR_At(vec_gpsData, i );
        temp = temp + data->longitude;   
    }
   
    temp = temp / len ;

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  len= %d    averageLongitude = %lf ", len , temp );
#endif /* __GPS_FILTER_DEBUG__ */

    return temp;  
    
}


/******************************************************************************
 *  Function    -  State_Of_Motion_Detection
 * 
 *  Purpose     -  运动状态检测
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 07-10-2011,  MagicNing  written
 * ----------------------------------------
 ******************************************************************************/
static void State_Of_Motion_Detection( void )
{
    double averageSpeed = 0;  

    averageSpeed = Get_AverageSpeed();

    if( averageSpeed <= 10 )
    {
        state = Stop ;
    }
    else if ( averageSpeed <= 30 )
    {
        state = Low_speed ;
    }
    else
    {
        state = High_speed ;
    }    
}


static void GpsData_Filter_Stop(mdi_gps_nmea_rmc_struct* data)
{
    double diffLatitude = 0;             // 当前纬度和前一个周期的差值(目前的周期为10s  )
    double diffLongitude = 0;             // 当前经度和前一个周期的差值(目前的周期为10s  )
    double diffDistance = 0 ;   // 距离差
    double ratio = 0 ;   // 距离差和平均速度的比值

    double averageSpeed = 0;  
    double averageLatitude = 0;  
    double averageLongitude = 0;  
    mdi_gps_nmea_rmc_struct* buf = NULL ;
    U8 n=0;
    
#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  GpsData_Filter_Stop() " );
#endif /* __GPS_FILTER_DEBUG__ */


    averageSpeed = Get_AverageSpeed();

    buf = VECTOR_Front(vec_gpsData);

    if( NULL == buf )
    {
        return;
    }

    averageLatitude =  Get_AverageLatitude();
    averageLongitude =  Get_AverageLongitude();
    diffLatitude  =  fabs( averageLatitude - data->latitude  );
    diffLongitude = fabs( averageLongitude -data->longitude  );  
    
#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "latitude = %lf  longitude = %lf",data->latitude,data->longitude );
    GPS_Log_Print(TRACE_INFO, "averageLatitude = %lf  averageLongitude = %lf ",averageLatitude,averageLongitude);
    GPS_Log_Print(TRACE_INFO, "diffLatitude = %lf  diffLongitude = %lf",diffLatitude,diffLongitude);
#endif /* __GPS_FILTER_DEBUG__ */

    diffDistance = sqrt( pow(diffLatitude ,2 ) + pow(diffLongitude ,2 ) );
   
#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "diffDistance = %lf ",diffDistance );
#endif /* __GPS_FILTER_DEBUG__ */

    if( averageSpeed < 5 )
    {
        ratio = ( diffDistance * 1000 * 2 ) / averageSpeed ;  
    }
    else
    {
        ratio = ( diffDistance * 1000  ) / averageSpeed ;    
    }    

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "%d    ratio = %lf ", index , ratio );
#endif /* __GPS_FILTER_DEBUG__ */

    while( ratio > 8 )
    {
        n++;
        if( n > 3 )
        {
            break;// 对一个错误数据的校正最多计算3 次
        }
        
        if( ratio <= 16  )
        {
            data->latitude = ( data->latitude + averageLatitude ) /2;
            data->longitude = ( data->longitude + averageLongitude ) /2;
        }
        else if( ratio <= 32  )
        {
            data->latitude = ( data->latitude + averageLatitude * 3  ) /4;
            data->longitude = ( data->longitude + averageLongitude * 3 ) /4;
        }
        else
        {
            data->latitude = averageLatitude;
            data->longitude = averageLongitude ;    
        }
                
        diffLatitude  =   fabs( averageLatitude - data->latitude );
        diffLongitude = fabs( averageLongitude - data->longitude );
        diffDistance = sqrt( pow(diffLatitude ,2 ) + pow(diffLongitude ,2 ) ); 
        
        if( averageSpeed < 5 )
        {
            ratio = ( diffDistance * 1000 * 2 ) / averageSpeed ;  
        }
        else
        {
            ratio = ( diffDistance * 1000 ) / averageSpeed ;    
        }
        
#ifdef __GPS_FILTER_DEBUG__
        GPS_Log_Print(TRACE_INFO, "diffLatitude %d = %lf ", n, diffLatitude );
        GPS_Log_Print(TRACE_INFO, "diffLongitude %d = %lf ", n, diffLongitude );
        GPS_Log_Print(TRACE_INFO, "diffDistance %d = %lf ", n,  diffDistance );
        GPS_Log_Print(TRACE_INFO, "ratio %d = %lf ", n, ratio );
#endif /* __GPS_FILTER_DEBUG__ */

    }
}


static mdi_gps_nmea_rmc_struct GpsData_Filter(mdi_gps_nmea_rmc_struct data)
{
    mdi_gps_nmea_rmc_struct   new_data;
    U16 len = 0;

#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  GpsData_Filter()" );
#endif /* __GPS_FILTER_DEBUG__ */ 

    memcpy(&new_data , &data , sizeof(mdi_gps_nmea_rmc_struct));

    len = VECTOR_Size(vec_gpsData);

    if( len < 10 )
    {
        return new_data;  //缓存队列数据不足，无法分析，数据直接保存到队列中
    }

    switch(state)
    {
        case Stop:
            GpsData_Filter_Stop( &new_data );
            break;
                
        case Low_speed:
            break;

        case High_speed:
        default:
            // 高速运动时不需要做修正
            break;
    }
    return new_data;  
 
}


/*****************************************************************************
 *  Local Functions			全局函数
 *****************************************************************************/

/*---------------------------------------------------------------------------
 * FUNCTION			ifsendgpsdata
 *
 * DESCRIPTION		静态数据过滤
 *
 * PARAMETERS		static_datafilter_struct *last_send_data
 *
 * RETURNS			BOOL
 *
 *---------------------------------------------------------------------------*/
BOOL ifsendgpsdata(static_datafilter_struct *last_send_data)
{
    U32 cmp = 0;

    if(GpsIndex < 10)
    {
        GpsIndex++;
        return TRUE;
    }
    cmp = 0;
    if(last_send_data->lat >= now_latlon_data.lat)
        cmp = last_send_data->lat - now_latlon_data.lat;
    else
        cmp = now_latlon_data.lat - last_send_data->lat;
    
    if(last_send_data->lon >= now_latlon_data.lon)
        cmp = cmp + last_send_data->lon - now_latlon_data.lon;
    else
        cmp = cmp + now_latlon_data.lon - last_send_data->lon;
    
    if(cmp > MAX_STATIC_DIFFDATA)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/******************************************************************************
 *  Function    -  ifsameinfo
 * 
 *  Purpose     -  时间相同的数据过滤, 除开机后前十条数据外
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * 
 * ----------------------------------------
 ******************************************************************************/
BOOL ifsameinfo(U8 *time)
{
    U8 i;

    if(GpsIndex <= 10)
    {
        GpsIndex++;
        return TRUE;
    }
    for(i = 0; i < 6; i++)
    {
        if(check_datetime[i] != time[i])
            return TRUE;//时间不相同
    }
    return FALSE;//时间一样

}

/******************************************************************************
 *  Function    -  FILTER_Reset
 *
 *  Purpose     -  复位当前的GPS缓存队列
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-10-2011,  MagicNing  written
 * ----------------------------------------
 ******************************************************************************/
void FILTER_Reset(void)
{
#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  FILTER_Reset()" );
#endif /* __GPS_FILTER_DEBUG__ */ 

    if(NULL == vec_gpsData)
    {
        VECTOR_CreateInstance(vec_gpsData);
    }
    else
    {
        VECTOR_Clear(vec_gpsData);
    }
}

void FILTER_gpsData_Add2(gps_gprmc_struct* pData)
{
    gps_gprmc_struct* last_data;
    U16 len = 0;
    
#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  FILTER_gpsData_Add()" );
#endif /* __GPS_FILTER_DEBUG__ */

    if(NULL == vec_gpsData)
    {
        VECTOR_CreateInstance(vec_gpsData);
    }
     last_data = (gps_gprmc_struct*)Ram_Alloc(6, sizeof(gps_gprmc_struct));
    if(last_data)
    {
        memcpy(last_data , pData , sizeof(gps_gprmc_struct));

        VECTOR_PushBack(vec_gpsData, last_data);
        len = VECTOR_Size(vec_gpsData); 
        
#if  defined( __GPS_FILTER_DEBUG__ )
        GPS_Log_Print(TRACE_INFO, "len 1  = %d " , VECTOR_Size(vec_gpsData)  );
#endif /* __GPS_FILTER_DEBUG__ */        

        while(len > 10)     //删除多余的数据点，只保留采样周期内的数据点
        {
            last_data = VECTOR_At(vec_gpsData, 0);
            VECTOR_Erase(vec_gpsData, 0, 1);
            Ram_Free(last_data);
            len = VECTOR_Size(vec_gpsData);
#if  defined( __GPS_FILTER_DEBUG__ )
            GPS_Log_Print(TRACE_INFO, "len 2  = %d " , VECTOR_Size(vec_gpsData)  );
#endif /* __GPS_FILTER_DEBUG__ */                  
        }
    }
    else
    {   
        // 这里最好是能做一些异常处理 
    }
}

/******************************************************************************
 *  Function    -  FILTER_gpsData_Add
 *
 *  Purpose     -  添加GPS数据
 *
 *  Description -  需要检验数据的正确性和缓存数据的实效性，避免采用了错误的算法
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-10-2011,  MagicNing  written
 * ----------------------------------------
 ******************************************************************************/
void FILTER_gpsData_Add(mdi_gps_nmea_rmc_struct data)
{
    mdi_gps_nmea_rmc_struct* last_data;
    U16 len = 0;
    
#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  FILTER_gpsData_Add()" );
#endif /* __GPS_FILTER_DEBUG__ */

    last_data = (mdi_gps_nmea_rmc_struct*)Ram_Alloc(6, sizeof(mdi_gps_nmea_rmc_struct));
    if(last_data)
    {
        memcpy(last_data , &data , sizeof(mdi_gps_nmea_rmc_struct));

        VECTOR_PushBack(vec_gpsData, last_data);
        len = VECTOR_Size(vec_gpsData); 
        
#if  defined( __GPS_FILTER_DEBUG__ )
        GPS_Log_Print(TRACE_INFO, "len 1  = %d " , VECTOR_Size(vec_gpsData)  );
#endif /* __GPS_FILTER_DEBUG__ */        

        while(len > 10)     //删除多余的数据点，只保留采样周期内的数据点
        {
            last_data = VECTOR_At(vec_gpsData, 0);
            VECTOR_Erase(vec_gpsData, 0, 1);
            Ram_Free(last_data);
            len = VECTOR_Size(vec_gpsData);
#if  defined( __GPS_FILTER_DEBUG__ )
            GPS_Log_Print(TRACE_INFO, "len 2  = %d " , VECTOR_Size(vec_gpsData)  );
#endif /* __GPS_FILTER_DEBUG__ */                  
        }
    }
    else
    {   
        // 这里最好是能做一些异常处理 
    }

}



/******************************************************************************
 *  Function    -  FILTER_gpsData_Check
 * 
 *  Purpose     -  GPS 数据校准
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * 
 * ----------------------------------------
 ******************************************************************************/
void FILTER_gpsData_Check(gps_gprmc_struct* pData)
{
    extern void FILTER_gpsData_Add2(gps_gprmc_struct* pData);
 //    FILTER_gpsData_Add2(pData);   
  //   return;

   mdi_gps_nmea_rmc_struct* last_data;
    mdi_gps_nmea_rmc_struct   data,new_data;
    U64 time = 0;
    module_type ower_id;
    kal_uint8 buff[200];
#if  defined( __GPS_FILTER_DEBUG__ )
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  FILTER_gpsData_Check()" );
#endif /* __GPS_FILTER_DEBUG__ */   

    index++;

    memset(buff,0,sizeof(buff));

    data.utc_date.year = (kal_int8)pData->Date_Time.nYear-2000;
    data.utc_date.month= (kal_int8)pData->Date_Time.nMonth;
    data.utc_date.day= (kal_int8)pData->Date_Time.nDay;
    data.utc_time.hour = (kal_int8)pData->Date_Time.nHour;
    data.utc_time.minute= (kal_int8)pData->Date_Time.nMin;
    data.utc_time.second= (kal_int8)pData->Date_Time.nSec;                    

    data.latitude =pData->Latitude;
    data.longitude = pData->Longitude;
    data.ground_speed =  pData->Speed;                 

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  lat=%lf   lon =%lf  speed=%lf ",data.latitude,data.longitude,data.ground_speed);
#endif /* __GPS_FILTER_DEBUG__ */

    if( data.ground_speed > 280 )
    {
        return; // 终端速度不可能大于350km/h
    }
    
    if( data.latitude > 9000 )
    {
        return; // 纬度不会大于90
    }
    
    if( data.longitude> 18000 )
    {
        return; // 经度不会大于180
    }

    if(NULL == vec_gpsData)
    {
        VECTOR_CreateInstance(vec_gpsData);
    }
    
    if( VECTOR_Size(vec_gpsData) )
    {    
        last_data = VECTOR_Back(vec_gpsData);

        if(last_data->utc_date.year == data.utc_date.year
                &&  last_data->utc_date.month == data.utc_date.month
                &&  last_data->utc_date.day == data.utc_date.day
          )
        {
            time = (data.utc_time.hour -  last_data->utc_time.hour) * 60;   //转换分
            time = (time + data.utc_time.minute -  last_data->utc_time.minute) * 60;  //转换秒
            time = (time + data.utc_time.second -  last_data->utc_time.second);
            if(time > 60)   //如果当前GPS数据和上一个有效点之间的时间间隔小于1分钟，认为新数据和缓存数据具有连贯性
            {
                FILTER_Reset();
            }
        }
        else
        {
            FILTER_Reset();
        }
    }

    State_Of_Motion_Detection(); //判断当前的运动状态

    new_data = GpsData_Filter(data);
    
    FILTER_gpsData_Add(new_data);

    if( (data.latitude!= new_data.latitude) || (data.longitude != new_data.longitude ) )
    {
        pData->Latitude= new_data.latitude;
        pData->Longitude= new_data.longitude ;
        
#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "## NEW##   longitude = %lf   longitude = %lf",pData->Latitude,pData->Longitude);
#endif /* __GPS_FILTER_DEBUG__ */     

        /*if(GPS_Pass_state)
        {
            ower_id = UART_GetOwnerID(uart_port1);
            sprintf(buff, "\r\n$ZDA,%s,%s,\r\n",pData->Latitude,pData->Longitude);
            UART_PutBytes(uart_port1, (kal_uint8 *)buff, strlen(buff) , ower_id);
        }*/
    }    
}


/******************************************************************************
 *  Function    -  FILTER_gpsData_Check
 *
 *  Purpose     -  检查GPS数据，判断当前的过滤模式
 *
 *  Description -  需要检验数据的正确性和缓存数据的时效性，避免采用了错误的算法
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-10-2011,  MagicNing  written
 * ----------------------------------------
 ******************************************************************************/
void FILTER_gpsData_Check_2(mdi_gps_nmea_rmc_struct data)
{
    mdi_gps_nmea_rmc_struct* last_data;
    mdi_gps_nmea_rmc_struct   new_data;

    U64 time = 0;

#ifdef __GPS_FILTER_DEBUG__
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  FILTER_gpsData_Check_2()" );
    GPS_Log_Print(TRACE_INFO, "GPS_Filter.c  lat=%lf   lon =%lf  speed=%lf " , data.latitude  ,  data.longitude,  data.ground_speed );
#endif /* __GPS_FILTER_DEBUG__ */

    if( data.ground_speed > 350 )
    {
        return; // 终端速度不可能大于350km/h
    }
    
    if( data.latitude > 90 )
    {
        return; // 纬度不会大于90
    }
    
    if( data.longitude> 180 )
    {
        return; // 经度不会大于180
    }

    if(NULL == vec_gpsData)
    {
        VECTOR_CreateInstance(vec_gpsData);
    }
    
    if( VECTOR_Size(vec_gpsData) )
    {    
        last_data = VECTOR_Back(vec_gpsData);

        if(last_data->utc_date.year == data.utc_date.year
                &&  last_data->utc_date.month == data.utc_date.month
                &&  last_data->utc_date.day == data.utc_date.day
          )
        {
            time = (data.utc_time.hour -  last_data->utc_time.hour) * 60;   //转换分
            time = (time + data.utc_time.minute -  last_data->utc_time.minute) * 60;  //转换秒
            time = (time + data.utc_time.second -  last_data->utc_time.second);
            if(time > 60)   //如果当前GPS数据和上一个有效点之间的时间间隔小于1分钟，认为新数据和缓存数据具有连贯性
            {
                FILTER_Reset();
            }
        }
        else
        {
            FILTER_Reset();
        }
    }

    State_Of_Motion_Detection(); //判断当前的运动状态

    new_data = GpsData_Filter(data);
    
    FILTER_gpsData_Add(new_data);
    
}


#endif /* __GPRS_SEND_FILTER__ */


