/******************************************************************************
 * track_gps_drive.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GPS 驱动
 *
 * modification history
 * --------------------
 * v1.0   2012-07-27,  chengjun create this file
 *
 ******************************************************************************/
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_drv_gps_drive.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "app_datetime.h"
#include "Track_os_log.h"
#include "track_drv_uart.h"
#include "track_drv_system_interface.h"
#include "track_drv_gps_decode.h"
#include "track_os_ell.h"
#include "track_cust.h"
#include "../gps/inc/gps_common.h"
#include "gps_struct.h"
#include "../gps/inc/gps_uart_hdlr.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static kal_bool  assist_data_ready = KAL_TRUE;
//KAL_TRUE = 允许EPO 数据注入MNL 辅助定位
static kal_bool  allow_data_injection = KAL_TRUE;   //允许EPO 数据注入MNL 辅助定位
static U8     drv_gps_decode_status = 1;
/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/
typedef enum
{
    TIME_UPDATE_STATE_NONE,
    TIME_UPDATE_STATE_NTP,
    TIME_UPDATE_STATE_NITZ,
    TIME_UPDATE_STATE_GPS,
} track_time_update_state;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 curr_sec;
    track_time_update_state state;
} track_gps_time_update_struct;

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/

/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
void track_gps_power_on_req(gps_common_uart_work_mode_enum work_mode);
void track_gps_power_off_req(gps_common_uart_work_mode_enum work_mode);

kal_uint8 track_drv_decode_status()
{
    return drv_gps_decode_status;
}

static unsigned char calc_nmea_checksum(const char* sentence)
{
    unsigned char checksum = 0;
    while(*sentence)
    {
        checksum ^= (unsigned char) * sentence++;
    }
    return  checksum;
}

/******************************************************************************
 *  Function    -  track_agps_epo_time
 *
 *  Purpose     -  注入参考时间
 *
 *  Description -  UTC (GMT0)
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_agps_epo_time(applib_time_struct utcTime)
{
    mtk_param_epo_time_cfg epo_time_cfg;

    epo_time_cfg.u2YEAR = utcTime.nYear; //UTC time: year in 4 digits
    epo_time_cfg.u1MONTH = utcTime.nMonth; //UTC time: month
    epo_time_cfg.u1DAY = utcTime.nDay;//UTC time: day
    epo_time_cfg.u1HOUR = utcTime.nHour;//UTC time: hour
    epo_time_cfg.u1MIN = utcTime.nMin;//UTC time: minute
    epo_time_cfg.u1SEC = utcTime.nSec;//UTC time: second

    track_drv_sys_mtk_gps_set_param(MTK_PARAM_CMD_CONFIG_EPO_TIME, &epo_time_cfg);
}

/******************************************************************************
 *  Function    -  track_agps_epo_pos
 *
 *  Purpose     -  注入参考位置
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_agps_epo_pos(track_gps_epo_struct * gps_data)
{
    mtk_param_epo_pos_cfg epo_pos_cfg;

    //WGS84 geodetic latitude(Degree). Minus: south; Plus: north
    if(gps_data->gprmc.NS == 'N')
    {
        epo_pos_cfg.dfLAT = gps_data->gprmc.Latitude;
    }
    else
    {
        epo_pos_cfg.dfLAT = -gps_data->gprmc.Latitude;
    }


    //WGS84 geodetic longitude(Degree). Minus: west; Plus: east
    if(gps_data->gprmc.EW == 'E')
    {
        epo_pos_cfg.dfLON = gps_data->gprmc.Longitude;
    }
    else
    {
        epo_pos_cfg.dfLON = -gps_data->gprmc.Longitude;
    }

    epo_pos_cfg.dfALT = gps_data->altitude; //WGS84 ellipsoidal altitude(m).
    epo_pos_cfg.u2YEAR = gps_data->gprmc.Date_Time.nYear; // Reference UTC time: year in 4 digits
    epo_pos_cfg.u1MONTH = gps_data->gprmc.Date_Time.nMonth; // Reference UTC time: month
    epo_pos_cfg.u1DAY = gps_data->gprmc.Date_Time.nDay;// Reference UTC time: day
    epo_pos_cfg.u1HOUR = gps_data->gprmc.Date_Time.nHour;// Reference UTC time: hour
    epo_pos_cfg.u1MIN = gps_data->gprmc.Date_Time.nMin; // Reference UTC time: minute
    epo_pos_cfg.u1SEC = gps_data->gprmc.Date_Time.nSec; // Reference UTC time: second

    track_drv_sys_mtk_gps_set_param(MTK_PARAM_CMD_CONFIG_EPO_POS, &epo_pos_cfg);
}



/******************************************************************************
 *  Function    -  track_utc_to_gps_hour
 *
 *  Purpose     -  translate UTC to GPS_Hour
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
int track_utc_to_gps_hour(int iYr, int iMo, int iDay, int iHr)
{
    int iYearsElapsed;     // Years since 1980
    int iDaysElapsed;      // Days elapsed since Jan 6, 1980
    int iLeapDays;         // Leap days since Jan 6, 1980
    int i;

    // Number of days into the year at the start of each month (ignoring leap years)
    const unsigned short doy[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    iYearsElapsed = iYr - 1980;
    i = 0;
    iLeapDays = 0;

    while(i <= iYearsElapsed)
    {
        if((i % 100) == 20)
        {
            if((i % 400) == 20)
            {
                iLeapDays++;
            }
        }
        else if((i % 4) == 0)
        {
            iLeapDays++;
        }
        i++;
    }

    if((iYearsElapsed % 100) == 20)
    {
        if(((iYearsElapsed % 400) == 20) && (iMo <= 2))
        {
            iLeapDays--;
        }
    }
    else if(((iYearsElapsed % 4) == 0) && (iMo <= 2))
    {
        iLeapDays--;
    }

    iDaysElapsed = iYearsElapsed * 365 + (int)doy[iMo - 1] + iDay + iLeapDays - 6;

    // Convert time to GPS weeks and seconds
    iHr = iHr / 6 * 6;
    return (iDaysElapsed * 24 + iHr);

}

/******************************************************************************
 *  Function    -  track_epo_delete_file
 *
 *  Purpose     -  删除已存的EPO文件
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_epo_delete_file(void)
{
    WCHAR FilePath[60] = {0};
    kal_wsprintf(FilePath, MTKEPO_FILE_PATH);
    return FS_Delete(FilePath);
}

kal_int32 track_file_check(kal_uint8 *reference_md5, char *file_path)
{
    kal_uint8 ell_file_md5[16] = {0};
    kal_bool ret;

    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 filelen, readsize;
    int fs_result, len;
    kal_uint8 *data, *buf;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        return fp;
    }
    FS_GetFileSize(fp, &filelen);
    LOGD(L_APP, L_V5, "filelen:%d", filelen);
    if(filelen >= 500000)
    {
        FS_Close(fp);
        return -4;
    }
    buf = (U8*)Ram_Alloc(5, filelen + 10);
    if(!buf)
    {
        return -5;
    }
    data = buf;
    len = filelen;
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Read(fp, data, 50000, &readsize);
        }
        else
        {
            fs_result = FS_Read(fp, data, len, &readsize);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            //EllLog("fs_result:%d, %d, %d", fs_result, readsize, len);
            return fs_result;
        }
        len -= readsize;
        data += readsize;
    }
    FS_Close(fp);
    ret = IsDataMd5ext(buf, filelen, reference_md5);
    if(buf != NULL)
    {
        Ram_Free(buf);
    }
    if(ret)
        return 1;
    return 0;
}

kal_bool track_file_epo_dele()
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 filelen, readsize;
    int fs_result, len;
    kal_uint8 *data, *buf;

    kal_wsprintf(FilePath, MTKEPO_FILE2_PATH);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        FS_Close(fp);
        return KAL_FALSE;
    }
    FS_Close(fp);
    FS_Delete(FilePath);
    return KAL_TRUE;
}

kal_bool track_file_epo_exitence()
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 filelen, readsize;
    int fs_result, len;
    kal_uint8 *data, *buf;

    kal_wsprintf(FilePath, MTKEPO_FILE2_PATH);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        kal_wsprintf(FilePath, MTKEPO_FILE3_PATH);
        fp =  FS_Open(FilePath, FS_READ_ONLY);
        if(fp < 0)
        {
            return KAL_FALSE;
        }
    }
    FS_GetFileSize(fp, &filelen);
    FS_Close(fp);
    return KAL_TRUE;
}

kal_int32 track_md5_file_check(kal_uint8 *reference_md5, char *file_path)
{
    kal_uint8 ell_file_md5[16] = {0};
    kal_bool ret = 0;

    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 filelen, readsize;
    int fs_result, len;
    kal_uint8 *data, *buf;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        return fp;
    }
    FS_GetFileSize(fp, &filelen);
    LOGD(L_APP, L_V5, "filelen:%d", filelen);
    if(filelen >= 500000)
    {
        FS_Close(fp);
        return -4;
    }
    buf = (U8*)Ram_Alloc(5, filelen + 10);
    if(!buf)
    {
        return -5;
    }
    data = buf;
    len = filelen;
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Read(fp, data, 50000, &readsize);
        }
        else
        {
            fs_result = FS_Read(fp, data, len, &readsize);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            //EllLog("fs_result:%d, %d, %d", fs_result, readsize, len);
            return fs_result;
        }
        len -= readsize;
        data += readsize;
    }
    FS_Close(fp);
    if(buf != NULL)
    {
        if(!memcmp(buf, reference_md5, 16))
        {
            ret = 1;
        }
        Ram_Free(buf);
    }
    if(ret)
    {
        return 1;
    }
    return 0;
}
/******************************************************************************
 *  Function    -  track_epo_write_file
 *
 *  Purpose     -  写入EPO文件
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int32 track_write_file(char *filepath, kal_uint8 *data, kal_uint32 _len)
{
    FS_HANDLE fp = NULL;
    WCHAR _FilePath[60] = {0};
    kal_uint32 writelen, len = _len;
    int fs_result;

    LOGD(L_DRV, L_V4, "\"%s\" 需要写入%dB", filepath, _len);
    OTA_kal_wsprintf(_FilePath, "%s", filepath);
    OTA_FS_Delete(_FilePath);
    fp = OTA_FS_Open(_FilePath, FS_READ_WRITE | FS_CREATE);
    if(fp < 0)
    {
        LOGD(L_DRV, L_V4, "fp:%d", fp);
        OTA_FS_Close(fp);
        return -3;
    }
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        return -4;
    }
    while(len > 0)
    {
        if(len > 10000)
        {
            fs_result = FS_Write(fp, data, 10000, &writelen);
        }
        else
        {
            fs_result = FS_Write(fp, data, len, &writelen);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            LOGD(L_DRV, L_V4, "fs_result:%d, %d(%d), %d", fs_result, len, _len - len, writelen);
            return -5;
        }
        FS_Commit(fp);
        len -= writelen;
        if(len > 0)
        {
            data += writelen;
        }
    }
    FS_GetFileSize(fp, &writelen);
    LOGD(L_DRV, L_V4, "\"%s\" 文件写入FAT大小:%d", filepath, writelen);
    FS_Close(fp);
    return writelen;
}

kal_int32 track_epo_write_file(kal_uint8 *data, kal_uint32 len)
{
    return track_write_file(MTKEPO_FILE_PATH, data, len);
}

void track_epo_file_size(void)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 writelen;

    kal_wsprintf(FilePath, MTKEPO_FILE_PATH);
    fp = FS_Open(FilePath, FS_READ_WRITE | FS_CREATE);
    FS_GetFileSize(fp, &writelen);
    LOGS("EPO文件写入FAT大小:%d", writelen);
    FS_Close(fp);
}

/******************************************************************************
 *  Function    -  track_gps_hour_to_utc_view
 *
 *  Purpose     -  根据AGPS的GPS HOUR转换成UTC
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_gps_hour_to_utc_view(char *out)
{
    applib_time_struct result1 = {0}, result2 = {0};
    FS_HANDLE fp = NULL;
    int segment, epo_gps_hour1 = 0, epo_gps_hour2 = 0;
    WCHAR FilePath[60] = {0};
    kal_uint32 read, filesize, segments;
    int fs_result, ret = 0;

    kal_wsprintf(FilePath, MTKEPO_FILE_PATH);
    do
    {
        fp = FS_Open(FilePath, FS_READ_ONLY);
        if(fp < 0)
        {
            snprintf(out, 200, "ERROR: EPO file open error, if the file does not exist?");
            ret = -1;
            break;
        }
        fs_result = FS_GetFileSize(fp, &filesize);
        segments = filesize / (MTKEPO_RECORD_SIZE) / (MTKEPO_SV_NUMBER);
        if(segments <= 0)
        {
            snprintf(out, 200, "ERROR: filesize=%d, segments=%d", filesize, segments);
            ret = -2;
            break;
        }
        if(segments *(MTKEPO_RECORD_SIZE) *(MTKEPO_SV_NUMBER) != filesize)
        {
            snprintf(out, 200, "ERROR: EPO file size is incorrect, segments=%d, filesize=%d", segments, filesize);
            ret = -3;
            break;
        }

        fs_result = FS_Read(fp, &epo_gps_hour1, 4, &read);
        if(read != 4)
        {
            snprintf(out, 200, "ERROR: Error reading EPO file header.");
            ret = -5;
            break;
        }
        if(FS_NO_ERROR > FS_Seek(fp, filesize - MTKEPO_RECORD_SIZE, FS_FILE_BEGIN))
        {
            snprintf(out, 200, "ERROR: Move the EPO file to read the current coordinate error.");
            ret = -6;
            break;
        }
        fs_result = FS_Read(fp, &epo_gps_hour2, 4, &read);
        if(read != 4)
        {
            snprintf(out, 200, "ERROR: end of EPO file read error");
            ret = -7;
            break;
        }
        epo_gps_hour1 &= 0x00FFFFFF;
        epo_gps_hour2 &= 0x00FFFFFF;
        track_gps_hour_to_utc(epo_gps_hour1, &result1);
        track_gps_hour_to_utc(epo_gps_hour2, &result2);
        track_cust_agps_time_add_6hour(&result2);
        snprintf(out, 200, "EPO file validity: %d-%0.2d-%0.2d %0.2d:00:00 ～ %d-%0.2d-%0.2d %0.2d:00:00",
                 result1.nYear, result1.nMonth, result1.nDay, result1.nHour,
                 result2.nYear, result2.nMonth, result2.nDay, result2.nHour);
    }
    while(0);
    FS_Close(fp);
    return ret;
}

/******************************************************************************
 *  Function    -  track_send_assistance_data
 *
 *  Purpose     -  根据时间判断是否采用EPO数据
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_send_assistance_data(kal_bool ischeck, kal_uint16 iYr, kal_uint8 iMo, kal_uint8 iDay, kal_uint8 iHr)
{
    FS_HANDLE fp = NULL;
    int i, current_gps_hour/*当前系统时间换算成hour值*/;
    int epo_gps_hour/*EPO文件的第一段hour值*/, segment/*EPO文件有效剩余段数*/;
    mtk_param_epo_data_cfg epo_data;
    WCHAR FilePath[60] = {0};
    kal_uint32 read, filesize, segments/*已存在的EPO文件共分几段*/;
    int fs_result;
    kal_int8 ret = 1;

    // open EPO file and read the header (assume EPO file has passed integrity check)
    kal_wsprintf(FilePath, MTKEPO_FILE_PATH);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        FS_Close(fp);
        return -1;
    }
    fs_result = FS_GetFileSize(fp, &filesize);
    segments = filesize / (MTKEPO_RECORD_SIZE) / (MTKEPO_SV_NUMBER);
    if(segments <= 0)
    {
        FS_Close(fp);
        track_epo_delete_file();
        return -2;
    }
    if(segments *(MTKEPO_RECORD_SIZE) *(MTKEPO_SV_NUMBER) != filesize)
    {
        FS_Close(fp);
        track_epo_delete_file();
        return -3;
    }

    fs_result = FS_Read(fp, &epo_gps_hour, 4, &read);
    if(read != 4)
    {
        FS_Close(fp);
        track_epo_delete_file();
        return -5;
    }
    epo_gps_hour &= 0x00FFFFFF;

    // determine the segment to use
    current_gps_hour = track_utc_to_gps_hour(iYr, iMo, iDay, iHr);
    segment = (current_gps_hour - epo_gps_hour) / 6;
    LOGD(L_DRV, L_V5, "segment:%d(%d), current_gps_hour:%d, epo_gps_hour:%d", segment, segments, current_gps_hour, epo_gps_hour);
    if((segment < 0) || (segment >= segments/*MTKEPO_SEGMENT_NUM*/))
    {
        FS_Close(fp);
        track_epo_delete_file();
        return -6;
    }
    ret = segments - segment;
    if(!ischeck)
    {
        // seek to the begining of the segment that will be used.
        fs_result = FS_Seek(fp, segment * (MTKEPO_RECORD_SIZE) * (MTKEPO_SV_NUMBER), FS_FILE_BEGIN);

        // Read one segment of SV1 ~ SV32 satellite EPO data and send to MNL
        for(i = 0; i < MTKEPO_SV_NUMBER; i++)
        {
            epo_data.u1SatID = (i + 1);

            // Read one satellite EPO data
            fs_result = FS_Read(fp, epo_data.u4EPOWORD, MTKEPO_RECORD_SIZE, &read);
            if(read != MTKEPO_RECORD_SIZE)
            {
                LOGH(L_DRV, L_V1, epo_data.u4EPOWORD, read);
                LOGD(L_DRV, L_V1, "实际读出长度与请求读取长度不一致%d", read);
                break;
            }
            // Send one satellite EPO data to MNL
            track_drv_sys_mtk_gps_set_param(MTK_PARAM_CMD_CONFIG_EPO_DATA, &epo_data);
        }
        LOGD(L_APP, L_V4, "GPS使用EPO辅助定位");
    }
    FS_Close(fp);

    return ret;

}

/******************************************************************************
 *  Function    -  track_agps_epo_enable
 *
 *  Purpose     -  EPO 使能检查
 *
 *  Description -  数据不完整时，不得强行下载，脏数据反而影响定位速度
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 track_agps_epo_enable(void)
{
    kal_int8 ret = 0;
    t_rtc rtcTime = {0};
    track_gps_epo_struct * gps_data = NULL;

    RTC_GetTimeOnly(&rtcTime);
    //首次开机过早读取，该值为随机值
    if((rtcTime.rtc_year == *OTA_DEFAULT_HARDWARE_YEAR) && (rtcTime.rtc_mon == *OTA_DEFAULT_HARDWARE_MON)\
            && (rtcTime.rtc_day == *OTA_DEFAULT_HARDWARE_DAY))   //开机默认日期
    {
        LOGD(L_DRV, L_V5, "error %d-%d-%d", *OTA_DEFAULT_HARDWARE_YEAR, *OTA_DEFAULT_HARDWARE_MON, *OTA_DEFAULT_HARDWARE_DAY);
        ret |= 1;
    }
    gps_data = track_drv_get_gps_epo();
    if(!gps_data || !gps_data->valid)
    {
        ret |= 2;
    }
    return ret;
}

/******************************************************************************
 *  Function    -  track_gps_on
 *
 *  Purpose     -  向GPS  task 发送开启消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_gps_on(void)
{
    ilm_struct *send_ilm;
    LOGD(L_DRV, L_V5, "");
    allow_data_injection = KAL_TRUE;
    track_cust_gps_location_time(1);
    track_drv_cal_secset(1);
    track_drv_sleep_enable(SLEEP_DRV_MOD, FALSE);
#if defined __GPS_MT3333__
    drv_gps_decode_status = 1;
    track_gps_power_on_req(GPS_UART_MODE_DEBUG_RAW_DATA);
    LOGD(L_DRV, L_V5, "__GPS_MT3333__");
#elif defined(__GPS_UART__)
    track_drv_mgps_on();
#else
#error  "track_gps_on"
#endif
}


/******************************************************************************
 *  Function    -  track_gps_off
 *
 *  Purpose     -  向GPS  task 发送关闭消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_gps_off(void)
{
    ilm_struct *send_ilm;

#if defined __GPS_MT3333__
    drv_gps_decode_status = 0;
    track_gps_power_off_req(GPS_UART_MODE_DEBUG_RAW_DATA);
#elif  defined(__GPS_UART__)
    track_drv_mgps_off();
#else
#error  "track_gps_off"
#endif
    track_gps_data_clean();
    LOGD(L_DRV, L_V1, "");
    track_drv_sleep_enable(SLEEP_DRV_MOD, TRUE);
}

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
extern gps_uart_context_struct g_gps_cntx;
extern kal_uint8 GPS_Get_UART_Port(void);
//extern kal_int32 ret_value;

kal_eventgrpid g_gps_cmd_event_id = 0;
kal_mutexid g_gps_cmd_mutex = 0;

void track_send_msg_to_gps_task(msg_type msg_id, void *local_param_ptr, kal_uint32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    module_type src_mod;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    src_mod = MOD_MMI;//stack_get_active_module_id();
    ilm_ptr = allocate_ilm(src_mod);
    ilm_ptr->src_mod_id = src_mod;
    ilm_ptr->dest_mod_id = MOD_GPS;
    ilm_ptr->sap_id = GPS_MNL_SAP;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

void track_gps_power_off_req(gps_common_uart_work_mode_enum work_mode)
{
    gps_uart_open_req_struct *local_param_ptr;
    module_type                         module_id;
    kal_uint32 event_group;
    kal_eventgrpid event_id;
    kal_int32 ret = 0;

    if(g_gps_cmd_event_id == 0)
        g_gps_cmd_event_id = OTA_kal_create_event_group((kal_char*)"gps_uart");
    if(g_gps_cmd_mutex == 0)
        g_gps_cmd_mutex = kal_create_mutex((kal_char*)"gps_uart_mutex");

    module_id = MOD_MMI;
    local_param_ptr = construct_local_para(sizeof(gps_uart_open_req_struct), TD_CTRL);
    local_param_ptr->port = (kal_uint16)GPS_UART_PORT;
    local_param_ptr->mode = work_mode;
    local_param_ptr->return_val = &ret;
    local_param_ptr->module_id = module_id;
    event_id = g_gps_cmd_event_id;
    local_param_ptr->event_id = event_id;

    kal_take_mutex(g_gps_cmd_mutex);
    track_send_msg_to_gps_task(MSG_ID_GPS_UART_CLOSE_REQ ,
                               local_param_ptr,
                               sizeof(gps_uart_open_req_struct));

    //l4c_send_msg(MOD_GPS, MSG_ID_GPS_UART_OPEN_REQ, 0, local_param_ptr, NULL);
    OTA_kal_retrieve_eg_events(
        event_id,
        GPS_UART_CLOSE_FINISH_EVENT,
        KAL_OR_CONSUME,
        &event_group,
        KAL_SUSPEND);
    kal_give_mutex(g_gps_cmd_mutex);

}

void track_gps_power_on_req(gps_common_uart_work_mode_enum work_mode)
{
    gps_uart_open_req_struct *local_param_ptr;
    module_type                         module_id;
    kal_uint32 event_group;
    kal_eventgrpid event_id;
    kal_int32 ret = 0;
    if(g_gps_cmd_event_id == 0)
        g_gps_cmd_event_id = OTA_kal_create_event_group((kal_char*)"gps_uart");

    if(g_gps_cmd_mutex == 0)
        g_gps_cmd_mutex = kal_create_mutex((kal_char*)"gps_uart_mutex");

    module_id = MOD_MMI;
    local_param_ptr = construct_local_para(sizeof(gps_uart_open_req_struct), TD_CTRL);
    local_param_ptr->port = (kal_uint16)GPS_UART_PORT;
    local_param_ptr->mode = work_mode;
    local_param_ptr->return_val = &ret;
    local_param_ptr->module_id = module_id;
    event_id = g_gps_cmd_event_id;
    local_param_ptr->event_id = event_id;

    kal_take_mutex(g_gps_cmd_mutex);
    track_send_msg_to_gps_task(MSG_ID_GPS_UART_OPEN_REQ,	local_param_ptr, sizeof(gps_uart_open_req_struct));

#if 1
    OTA_kal_retrieve_eg_events(
        event_id,
        GPS_UART_OPEN_FINISH_EVENT,
        KAL_OR_CONSUME,
        &event_group,
        KAL_SUSPEND);
#endif
    kal_give_mutex(g_gps_cmd_mutex);

}

//屏蔽只是为减少代码空间，不要删除  chengj
#if 0
void track_gpstc_data_write_to_file(char * string, int len)
{
    static int file_hd;
    int size;
    char* name = "gpstc.txt";
    WCHAR gpstc_file[32] = {0};
    static kal_uint16 count = 0;

    if(count == 0)
    {
        kal_wsprintf(gpstc_file, name);
        file_hd = FS_Open(gpstc_file, FS_READ_ONLY);
        if(file_hd >= FS_NO_ERROR)
        {
            FS_Close(file_hd);
            FS_Delete(gpstc_file);
        }
        file_hd = FS_Open(gpstc_file, FS_READ_WRITE | FS_CREATE);
        if(file_hd < FS_NO_ERROR)
        {
            return;
        }
        LOGS("GPSTC写文件c:/gpstc.txt");
    }

    if(len == 0)
    {
        return;
    }

    if(count >= 370)
    {
        return;
    }

    count++;

    if(count == 370)
    {
        LOGS("GPSTC写文件6分钟，不写了");
        FS_Close(file_hd);
        count++;
        return;
    }

    FS_Write(file_hd, (void *)string, len, &size);
    FS_Commit(file_hd);
}
#endif

void gps_raw_data_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    gps_uart_debug_raw_data_struct* uart_raw_data_ind = (gps_uart_debug_raw_data_struct*)msg;
    kal_int8 gps_raw_buffer[1024] = {0};
    kal_uint32 readed;
    kal_uint32 readleng = 0;
    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    OTA_gps_uart_read_data_dbg(uart_raw_data_ind->port, gps_raw_buffer, 256, &readed);
    readleng += readed;
    OTA_kal_prompt_trace(MOD_GPS, "[buffer1]%s\n", &gps_raw_buffer[0]);

    ASSERT(readed <= 256);
    gps_raw_buffer[readleng] = 0;
    while(readed == 256)
    {
        OTA_gps_uart_read_data_dbg(uart_raw_data_ind->port, &gps_raw_buffer[readleng], 256, &readed);
        readleng += readed;
        OTA_kal_prompt_trace(MOD_GPS, "[buffer2]%s\n", &gps_raw_buffer[0]);
        ASSERT(readed <= 256);
        gps_raw_buffer[readleng] = 0;
    }

    if(track_status_gpstc(2))
    {
        //透传数据存FAT  chengj
        //track_gpstc_data_write_to_file((char*)gps_raw_buffer, strlen((char*)gps_raw_buffer));

        track_trace((char*)gps_raw_buffer, strlen((char*)gps_raw_buffer));
    }

    if(drv_gps_decode_status) //GPS关闭时不解码
    {
        track_uart_decode((char*)gps_raw_buffer, strlen((char*)gps_raw_buffer));
    }
}



/******************************************************************************
 *  Function    -  track_drv_get_epo_stage
 *
 *  Purpose     -  查询EPO 辅助数据是否有效
 *
 *  Description -
 *      0x00EE = 0000 0000 1110 1110
 *      有效的EPO SV号码是2, 3, 4, 6, 7, 8.
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
mtk_param_epo_stage_cfg track_drv_get_epo_stage(void)
{
    mtk_param_epo_stage_cfg epo_stage_cfg = {0};
    return epo_stage_cfg;
}

/******************************************************************************
 *  Function    -  track_drv_gps_msg_epo_ready
 *
 *  Purpose     -  通知MMI  可以注入EPO 辅助数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_msg_epo_ready(void)
{
    ilm_struct *send_ilm;
    send_ilm = (ilm_struct *)allocate_ilm(MOD_MNL);
    send_ilm->src_mod_id = MOD_MNL;
    send_ilm->dest_mod_id = MOD_MMI;
    send_ilm->msg_id = MSG_ID_GPS_EPO_READY;
    msg_send_ext_queue(send_ilm);
}

/******************************************************************************
 *  Function    -  track_drv_gps_epo_start
 *
 *  Purpose     -  开始注入辅助数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_epo_start(void)
{
    kal_int8 ret = 1;
    applib_time_struct  rtc, gmt0;

}

/******************************************************************************
 *  Function    -  track_drv_gps_cold_restart
 *
 *  Purpose     -  GPS重新冷启动
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_cold_restart(void)
{
    mtk_param_restart cfg;

    track_drv_gps_claer_eph();
#if defined(__GPS_UART__) ||defined(__GPS_MT3333__)
    //track_drv_gps_set_param(MTK_MSG_REQ_ASSIST, NULL);//wangqi
    track_cust_ubxcold();
    track_gps_data_clean();
#else
#error "track_drv_gps_cold_restart"
#endif
    //track_drv_gps_switch(1);
}

/******************************************************************************
 *  Function    -  track_drv_gps_cold_restart
 *
 *  Purpose     -  GPS重新冷启动
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20140806,    written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_warm_restart(void)
{
    mtk_param_restart cfg;

    //track_drv_gps_claer_eph();
#if defined(__GPS_UART__)
    //track_drv_gps_set_param(MTK_MSG_REQ_ASSIST, NULL);//wangqi
    track_cust_exgps_warm();
    track_gps_data_clean();
#elif defined(__GPS_MT3333__)
#else
#error "track_drv_gps_cold_restart"
#endif
    //track_drv_gps_switch(1);
}

void track_drv_gps_hot_restart(void)
{
    mtk_param_restart cfg;
    LOGD(L_DRV, L_V5, "");
#if defined(__GPS_UART__)||defined(__GPS_MT3333__)
    track_cust_ubxhot();
    track_gps_data_clean();
#elif defined(__GPS_MT3333__)//??

#else
#error "track_drv_gps_cold_restart"
#endif

}
/******************************************************************************
 *  Function    -  track_drv_gps_claer_eph
 *
 *  Purpose     -  清除GPS星历
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_claer_eph(void)
{
}

/******************************************************************************
 *  Function    -  track_drv_gps_switch
 *
 *  Purpose     -  GPS 开关
 *
 *  Description -   EPO>Hot>Cold
 *     0=关闭
 *     1=优先EPO
 *     2=优先热启动
 *     3=冷启动
 *
 * Return
 *     0=关/1=本次为热启动/2=本次为冷启动/3=强制再次开启
 *     error:  -1=本次操作和先前相同不执行/-2= 传入参数错误
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_gps_switch(U32 status)
{
    static U8 pre_status = 0xFF;
    kal_int8 exe;

    LOGD(L_DRV, L_V5, "%d", status);

    if(status == 1 || status == 3)
    {
        assist_data_ready = KAL_TRUE;
        track_gps_on();
        pre_status = 1;
        return 1;
    }
    else if(status == 2)
    {
        assist_data_ready = KAL_FALSE;
        track_gps_on();
        pre_status = 2;
        return 2;
    }
    else if(status == 0)
    {
        track_stop_timer(GPS_RESET_TIMER_ID);
        if(track_is_timer_run(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID))
        {
            track_stop_timer(TRACK_CUST_PERIODIC_RESTART_GPS_TIMER_ID);
        }
        track_gps_off();
        pre_status = 0;
        return 0;
    }
    else
    {
        return -2;
    }
}

kal_int8 track_drv_gps_reset(kal_uint8 delay)
{
    LOGD(L_DRV, L_V5, "(%d)", delay);
    track_drv_gps_switch(0);
    if(delay == 0)
    {
        delay = 2;
    }
    track_start_timer(GPS_RESET_TIMER_ID, delay * 1000, track_drv_gps_switch, (void*)1);
}


#if defined(__GPS_G3333__)
#define GPS_DEFAULT_MODE GN
#define EHP_MODE_NUMBER  3
#elif defined( __BD_AT6558__)
#define GPS_DEFAULT_MODE GN
#define EHP_MODE_NUMBER  3
#else
#define GPS_DEFAULT_MODE GPS
#define EHP_MODE_NUMBER  3
#endif

#if  defined( __BD_AT6558__)
static char * GB[] = {"$PCAS04,2*1B\r\n", "$PCAS04,1*18\r\n", "$PCAS04,3*1A\r\n"
                     };
#else
static char * GB[] = {"$PMTK353,0,0,0,0,1*2A\r\n", "$PMTK353,1,0,0,0,0*2A\r\n", "$PMTK353,1,0,0,0,1*2B\r\n", "$PMTK353,1,0,0,0,1*2A\r\n"};
#endif
kal_uint16 track_cust_set_gps_mode(int g_mode)
{
    kal_uint8 length ;

    static enum_gps_mode gps_mode = GPS_DEFAULT_MODE;

    if(0 <= g_mode && g_mode <= EHP_MODE_NUMBER)
    {
        length = strlen((char*)GB[g_mode]);
        //track_uart_write(GPS_UART_PORT, GB[g_mode], strlen((char*)GB[g_mode]));
        U_PutUARTBytes(GPS_UART_PORT, GB[g_mode], length);
        gps_mode = g_mode;
        LOGD(L_DRV, L_V9, "%s,%d", GB[g_mode], length);

    }

    LOGD(L_DRV, L_V9, "mode:%d, %d", gps_mode, g_mode);
    return gps_mode;
}

int track_drv_gps_set_param(kal_uint16 key, const void* value)
{
    char tmp[200] = {0}, out[200] = {0};
    int len = 0;
    switch(key)
    {
        case MTK_PARAM_CMD_CONFIG_EPO_TIME:
            {
                mtk_param_epo_time_cfg *epo_time_cfg = (mtk_param_epo_time_cfg*)value;
                snprintf(tmp, 200, "PMTK740,%d,%d,%d,%d,%d,%d",
                         epo_time_cfg->u2YEAR, epo_time_cfg->u1MONTH, epo_time_cfg->u1DAY,
                         epo_time_cfg->u1HOUR, epo_time_cfg->u1MIN, epo_time_cfg->u1SEC);
                len = snprintf(out, 200, "$%s*%02X\r\n", tmp, calc_nmea_checksum(tmp));
                break;
            }
        case MTK_PARAM_CMD_CONFIG_EPO_POS:
            {
                mtk_param_epo_pos_cfg *epo_pos_cfg = (mtk_param_epo_pos_cfg*)value;
                snprintf(tmp, 200, "PMTK741,%2.6f,%2.6f,%2.6f,%d,%d,%d,%d,%d,%d",
                         epo_pos_cfg->dfLAT, epo_pos_cfg->dfLON, epo_pos_cfg->dfALT,
                         epo_pos_cfg->u2YEAR, epo_pos_cfg->u1MONTH, epo_pos_cfg->u1DAY,
                         epo_pos_cfg->u1HOUR, epo_pos_cfg->u1MIN, epo_pos_cfg->u1SEC);
                len = snprintf(out, 200, "$%s*%02X\r\n", tmp, calc_nmea_checksum(tmp));
                break;
            }
        case MTK_PARAM_CMD_CONFIG_EPO_DATA:
            {
                mtk_param_epo_data_cfg *epo_data = (mtk_param_epo_data_cfg*)value;
                snprintf(tmp, 200, "PMTK721,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X,%X",
                         epo_data->u1SatID,
                         epo_data->u4EPOWORD[0], epo_data->u4EPOWORD[1], epo_data->u4EPOWORD[2],
                         epo_data->u4EPOWORD[3], epo_data->u4EPOWORD[4], epo_data->u4EPOWORD[5],
                         epo_data->u4EPOWORD[6], epo_data->u4EPOWORD[7], epo_data->u4EPOWORD[8],
                         epo_data->u4EPOWORD[9], epo_data->u4EPOWORD[10], epo_data->u4EPOWORD[11],
                         epo_data->u4EPOWORD[12], epo_data->u4EPOWORD[13], epo_data->u4EPOWORD[14],
                         epo_data->u4EPOWORD[15], epo_data->u4EPOWORD[16], epo_data->u4EPOWORD[17]);
                len = snprintf(out, 200, "$%s*%02X\r\n", tmp, calc_nmea_checksum(tmp));
                break;
            }
        case MTK_MSG_REQ_ASSIST:
            {
                /*GPS冷启动*/
                len = snprintf(out, 200, "$PMTK103*30\r\n");
                break;
            }
    }
    if(len > 0)
    {
        //LOGD(L_DRV, L_V5, "%s", out);
        U_PutUARTBytes(uart_port2, out, len);
    }
    return 0;
}

