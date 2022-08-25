/******************************************************************************
 * track_log.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        输出调试信息
 *
 * modification history
 * --------------------
 * v1.0   2012-07-25,  chengjun create this file
 *
 ******************************************************************************/
#if defined(__GPS_TRACK__)
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_log.h"
#include "uart_sw.h"
#include "dcl_uart.h"

#include "nvram_interface.h"
#include "custom_nvram_editor_data_item.h"
#include "kal_trace.h"

#include "App_datetime.h"
#include "Fs_gprot.h"

#include "C_string.h"
#include "track_cmd.h"
#include "c_RamBuffer.h"
#include "track_os_ell.h"
#include "track_cust.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#ifndef __va_rounded_size
#define __va_rounded_size(TYPE) (((sizeof(TYPE)+sizeof(int)-1)/sizeof(int))*sizeof(int))
#endif

#ifndef va_start
#define va_start(AP, LASTARG)   (AP = ((char *)& (LASTARG) + __va_rounded_size(LASTARG)))
#endif

#ifndef va_arg
#define va_arg(AP, TYPE)        (AP += __va_rounded_size(TYPE), *((TYPE *)(AP - __va_rounded_size(TYPE))))
#endif

#ifndef va_end
#define va_end(AP)              (AP = (va_list)0 )
#endif

#define _LOG_CASE__

#define Single_File_Size        (10*1024*1024)               //10M单个文件最大10M
#define LOG_DRIVER_PATH         FS_DRIVE_V_REMOVABLE     // FAT 的目标盘 FS_DRIVE_V_NORMAL       // 
#define LOG_FAT_SIZE            (512*1024*1024)         //512M
#define LOG_DIR                 ":\\tr_log\\"

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    int         iDrvLetter;
    WCHAR       wFileDir[32];
    WCHAR       wfile_name[64];
    FS_HANDLE   wfile_hd;
    kal_uint32  writen_size;

#if !defined (__REMOVE_LOG_TO_FILE__)
    c_string*   string;
#endif /* __REMOVE_LOG_TO_FILE__ */
} LOG_FILE_ST;

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static log_target_enum g_logTarget = LOG_SERIAL;
static nvram_ef_logd_struct log_setting = {0};

static  LOG_FILE_ST logfile = {0};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
nvram_sys_abnormal_data_struct      G_sys_abnormal_data = {0};
kal_bool test_test_test = 0;
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
extern kal_uint16 USB_PutBytes(kal_uint8 * out_context, kal_uint16 length);
kal_uint8 track_init_logd(void);

#ifdef _LOG_CASE__
static void test_log_hex(char * toHexstr)
{
    LOGH(L_CON, L_V4, toHexstr, strlen(toHexstr));
}
#endif /* _LOG_CASE__ */

/******************************************************************************
 *  Function    -  og_fat_CheckCapacity
 *
 *  Purpose     -  检查磁盘剩余容量，确保LOG保存空间
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-09-2011,  MagicNing  written
 * ----------------------------------------
 ******************************************************************************/
static kal_bool og_fat_CheckCapacity(void)
{
    FS_HANDLE folder_hd;
    int filesize;
    WCHAR wszFilePath[100];
    FS_DOSDirEntry file_info;
    kal_uint16 filename[VR_MAX_DB_PATH_LEN + 1];
    WCHAR wszFileLogPath[100];
    char temp[100];

    //kal_prompt_trace(TRACE_INFO, "og_fat_CheckCapacity( )");

    filesize = FS_GetFolderSize(logfile.wFileDir, FS_COUNT_IN_BYTE, NULL, 0);

    OTA_kal_prompt_trace(TRACE_INFO, "og_fat_CheckCapacity filesize  = %d " , filesize);

    if(filesize <= 0  ||  filesize < (LOG_FAT_SIZE - LOG_FAT_SIZE / 4))
    {
        return KAL_TRUE;
    }

    kal_wsprintf(wszFilePath, "%w*.dat", logfile.wFileDir);
    folder_hd = FS_FindFirst(wszFilePath, 0, 0, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) * 2);

    OTA_kal_prompt_trace(TRACE_INFO, "og_fat_CheckCapacity folder_hd  = %d " , folder_hd);

    if(folder_hd < 0)
    {
        FS_XDelete(logfile.wFileDir, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        FS_CreateDir(logfile.wFileDir);
        return KAL_TRUE;
    }

    do
    {
        /* filter out folder results */
        if(!(file_info.Attributes & FS_ATTR_DIR))
        {
            app_ucs2_strcpy((kal_int8*)wszFileLogPath, (const kal_int8*)logfile.wFileDir);
            app_ucs2_strcat((kal_int8*)wszFileLogPath, (const kal_int8*)filename);

#ifdef 1
            memset(temp, 0, 100);
            app_ucs2_str_to_asc_str(temp, (kal_int8*)wszFileLogPath);
            OTA_kal_prompt_trace(TRACE_INFO, "og_fat_CheckCapacity filename   = %s  " , temp);
#endif /* __GPS_DRIVER_DEBUG__ */

            FS_Delete(wszFileLogPath);
            memset(filename, 0, (VR_MAX_DB_PATH_LEN + 1) * 2);

            filesize = FS_GetFolderSize(logfile.wFileDir, FS_COUNT_IN_BYTE, NULL, 0);

            OTA_kal_prompt_trace(TRACE_INFO, "og_fat_CheckCapacity filesize 2 = %d " , filesize);

            if(filesize > 0 && filesize < LOG_FAT_SIZE / 2)
            {
                break;
            }
        }
    }
    while(FS_FindNext(folder_hd, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) * 2) == FS_NO_ERROR);

    FS_Close(folder_hd);

    return KAL_TRUE;

}

#if defined (__REMOVE_LOG_TO_FILE__)
static void creat_new_file(void) {}
static void log_file_int(void) {}
static void write_to_file(char* ctx, int ilength) {}
static void track_log2file(char* ctx, int ilength) {}
#else
static void creat_new_file(void)
{
    FS_HANDLE folder_hd;

    applib_time_struct srtc = {0};

    OTA_kal_prompt_trace(2, "creat_new_file wFileDir = %d " , app_ucs2_strlen((kal_int8*)logfile.wFileDir));

    if(app_ucs2_strlen((kal_int8*)logfile.wFileDir) == 0)
    {
        return;
    }

    folder_hd = FS_Open(logfile.wFileDir, FS_OPEN_DIR | FS_READ_ONLY);
    OTA_kal_prompt_trace(2, "creat_new_file wFileDir folder_hd  1 = %d " , folder_hd);

    if(folder_hd < FS_NO_ERROR)
    {
        folder_hd = FS_CreateDir(logfile.wFileDir);
    }
    else
    {
        FS_Close(folder_hd);
        og_fat_CheckCapacity();
    }

    applib_dt_get_rtc_time(&srtc);
    memset(log_setting.log_file_name, 0, sizeof(log_setting.log_file_name));
    sprintf(log_setting.log_file_name, "%4d_%2d_%2d_%2d.dat", srtc.nYear, srtc.nMonth, srtc.nDay, srtc.nHour);

    OTA_kal_prompt_trace(2, "creat_new_file log_file_name = %s " , log_setting.log_file_name);

    kal_wsprintf(logfile.wfile_name, "%w%s", logfile.wFileDir, log_setting.log_file_name);

    logfile.wfile_hd = FS_Open(logfile.wfile_name , FS_CREATE | FS_READ_WRITE);
    FS_GetFileSize(logfile.wfile_hd, &logfile.writen_size);

    OTA_kal_prompt_trace(2, "creat_new_file:%d,%d,%s " , logfile.wfile_hd, logfile.writen_size, log_setting.log_file_name);
    Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);

}

static void log_file_int(void)
{
    static kal_bool init_ok = KAL_FALSE;
    char szFilePath[32];

    if(init_ok)
    {
        return;
    }
    init_ok = KAL_TRUE;

    OTA_kal_prompt_trace(2, "log_file_int");

    logfile.iDrvLetter = FS_GetDrive(LOG_DRIVER_PATH , 1, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);
    sprintf(szFilePath, "%c%s", logfile.iDrvLetter, LOG_DIR);
    kal_wsprintf(logfile.wFileDir, szFilePath);

    OTA_kal_prompt_trace(2, "log_file_int %d,szFilePath:%s", logfile.iDrvLetter, szFilePath);

    if(logfile.string == NULL)
    {
        STRING_CreateInstance(logfile.string, "", 0, -1);
    }

    if(strlen(log_setting.log_file_name))
    {
        OTA_kal_prompt_trace(2, "log_file_int:%s " , log_setting.log_file_name);
        kal_wsprintf(logfile.wfile_name, "%w", log_setting.log_file_name);
        logfile.wfile_hd = FS_Open(logfile.wfile_name , FS_CREATE | FS_READ_WRITE);
        FS_GetFileSize(logfile.wfile_hd, &logfile.writen_size);
        OTA_kal_prompt_trace(2, "log_file_int:%d,writen_size:%d ", logfile.wfile_hd, logfile.writen_size);

        if(Single_File_Size - 20480 > logfile.writen_size)/*20K*/
        {
            FS_Close(logfile.wfile_hd);
            logfile.writen_size = 0;
        }
        else
        {
            return;
        }
    }

    creat_new_file();
}

static void write_to_file(char* ctx, int ilength)
{
    applib_time_struct srtc = {0};
    static char crtc[32] = {0};
    static kal_uint8 uhour = 0, umin = 0, stringcount = 0;

    const char* content = NULL;
    kal_int32 ret = 0;
    kal_uint32 write_size = 0;

    memset(crtc, 0, 32);

    applib_dt_get_rtc_time(&srtc);
    /*请不要修改这个格式的长度,注意track_log2file中的9*/
    sprintf(crtc, "%02d:%02d:%2d>", srtc.nHour, srtc.nMin, srtc.nSec);

    if(logfile.string == NULL)
    {
        STRING_CreateInstance(logfile.string, "", 0, -1);
    }

    STRING_Append(logfile.string, crtc, 0, -1);
    STRING_Append(logfile.string, ctx, 0, ilength);
    STRING_Append(logfile.string, "\r\n", 0, 2);
    stringcount++;

    OTA_kal_prompt_trace(TRACE_INFO, "string_length:%d", STRING_Length(logfile.string));
    //if(STRING_Length(logfile.string) > 1024 || srtc.nHour - uhour != 0 || srtc.nMin - umin > 5)
    if(STRING_Length(logfile.string) > 1024 || stringcount > 0)
    {
        stringcount = 0;
        OTA_kal_prompt_trace(TRACE_INFO, " write_to_file id= %d,writen size:%d" , logfile.wfile_hd, logfile.writen_size);

        if(logfile.wfile_hd >= 0)
        {
            FS_Seek(logfile.wfile_hd, 0, FS_FILE_END);

            content = STRING_Str(logfile.string);
            ret = FS_Write(logfile.wfile_hd, (void *) content, STRING_Length(logfile.string) , &write_size);
            STRING_Erase(logfile.string, 0, write_size);
            FS_Commit(logfile.wfile_hd);
        }

        OTA_kal_prompt_trace(TRACE_INFO, "[%d,%d][%d,%d]", srtc.nHour, srtc.nMin, uhour, umin);
        //FS_Close(logfile.wfile_hd);
        uhour = srtc.nHour;
        umin = srtc.nMin;

    }

}

static void track_log2file(char* ctx, int ilength)
{

    kal_uint32 cur_size = logfile.writen_size + ilength + 9/*strlen("%2d:%2d:%2d>")*/;

    if(logfile.wfile_hd <= 0 || cur_size > Single_File_Size)
    {
        if(logfile.wfile_hd > 0)
        {
            FS_Close(logfile.wfile_hd);
        }

        logfile.writen_size = 0;
        creat_new_file();
    }

    logfile.writen_size = cur_size;

    write_to_file(ctx, ilength);

}
#endif /*__REMOVE_LOG_TO_FILE__*/

/******************************************************************************
 *  Function    -  is_catcher_mode
 *
 *  Purpose     -  判断COM1是否处于Catcher模式
 *
 *  Description -  NULL
 *
 *  Return      -  1   Catcher Mode
 *                 2   CMD Mode
 *                 0   Other Mode
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-09-2010,  Cml  written
 * v1.0  , 15-12-2013,  WangQi  written
 * ----------------------------------------
 ******************************************************************************/

log_target_enum is_catcher_mode()
{
    static log_target_enum tmp = LOG_AUTO;
    port_setting_struct port_setting = {0};
    kal_int32 ret;

    ret = Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
    if(ret)
    {
        if(port_setting.tst_port_ps == port_setting.tst_port_l1 && port_setting.tst_port_ps == gAT_PORT)
        {
            tmp = LOG_CATCHER;
        }
        else if(port_setting.ps_port == gAT_PORT || port_setting.tst_port_ps == gTST_PORT)
        {
            tmp = LOG_SERIAL;
        }
        else
        {
            tmp = LOG_AUTO;
        }
    }
    //LOGS("!ReadRecord=%d,tst=%d, ps_port=%d, l1=%d,tmp=%d", ret, port_setting.tst_port_ps, port_setting.ps_port, port_setting.tst_port_l1,tmp);

    OTA_kal_prompt_trace(MOD_TST, "!! ReadRecord tmp=%d", tmp);
    return tmp;
}

static char * format_str(kal_uint8 * base, int length)
{
    static char str[64] = {0};
    int index = 0, j = 0;

    memset(str, 0, 64);
    if(base == NULL)
    {
        return (char *)&str;
    }
    if(length > 30)
    {
        length = 30;
    }

    str[j++] = '[';
    while(index < length)
    {
        str[j++] = base[index++] + 48;
        str[j++] = ' ';
    }
    str[j] = ']';
    return (char *)&str;
}

kal_uint8 track_get_tst_port(void)
{
    static kal_uint8 tst = 0xFF;

    if(tst == 0xFF)
    {
        port_setting_struct port_setting = {0};
        kal_bool ret;
        ret = Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);

        if(ret == KAL_TRUE)
        {
            tst = port_setting.tst_port_l1;
        }

    }

    return tst;
}
/******************************************************************************
 *  Function    -  track_log_switch
 *  Purpose     -  日志输出开关
 *  Description -
 *                 请使用0XFF进行状态查询
 *  Return      -  1   开启输出存储NVRAM
 *                 2   GPS升级模式日志输出为kal_prompt_trace
                   3   临时开启输出重启后无效
 *                 0   关闭输出
 * modification history
 * ----------------------------------------
 * v1.0  , 02-09-2010,  Cml  written
 * v1.0  , 15-12-2013,  WangQi  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_log_switch(kal_uint8 onof)
{
    static kal_uint8 _switch = 0xFF;

    if(0 <= onof && onof <= 3)
    {
        _switch = onof;
    }
    if(_switch == 0xFF)
    {
        _switch = track_init_logd();
    }
    return _switch;
}
/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
void track_trace(char * fmt, int size)
{
    //kal_prompt_trace(MOD_TST, "[target:%d,%d]track_track:%d %s", g_logTarget, size, track_log_switch(0xff), fmt);
    if(LOG_AUTO == g_logTarget)
    {
        g_logTarget = is_catcher_mode();
        OTA_kal_prompt_trace(MOD_TST, "日志模式%d", g_logTarget);
    }

    if(LOG_CATCHER == g_logTarget)
    {
        OTA_kal_prompt_trace(MOD_TST, "%s", fmt);
    }
    else if(LOG_SERIAL == g_logTarget)
    {
        if(test_test_test)
        {
            //track_cust_server3_conn(fmt, size);
        }
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        if(track_log_switch(0xff) == 0)
        {
            return;
        }
#endif
        if(2 == track_log_switch(0xFF))
        {
            OTA_kal_prompt_trace(MOD_TST, "%s", fmt);
        }
        else if(4 == track_get_at_port())
        {
            USB_PutBytes((kal_uint8*)fmt, size);
            USB_PutBytes((kal_uint8*)"\r\n", 2);
        }
        else if(0 == track_get_at_port() && track_drv_uart_log_mode(99) != 1)
        {
            U_PutUARTBytes(0, (kal_uint8*)fmt, size);
            U_PutUARTBytes(0, (kal_uint8*)"\r\n", 2);
        }
        else if(1 == track_get_at_port())
        {
            U_PutUARTBytes(1, (kal_uint8*)fmt, size);
            U_PutUARTBytes(1, (kal_uint8*)"\r\n", 2);
        }
    }
    else if(LOG_2FILE == g_logTarget)
    {
        //add log to fat function
        track_log2file(fmt, size);
    }
    else
    {
        //LOGS("log target erro:logs:%s",fmt);
    }
}

#if !defined (__REMOVE_LOG_TO_FILE__)
void track_trace2(char * fmt, int size)
{
    //kal_prompt_trace(MOD_TST, "[target:%d,%d]track_track:%s", g_logTarget, size, fmt);
    if(LOG_AUTO == g_logTarget)
    {
        g_logTarget = is_catcher_mode();
        OTA_kal_prompt_trace(MOD_TST, "日志模式%d", g_logTarget);
    }

    if(LOG_CATCHER == g_logTarget)
    {
        OTA_kal_prompt_trace(MOD_TST, "%s", fmt);
    }
    else if(LOG_SERIAL == g_logTarget)
    {
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        if(track_log_switch(0xff) == 0)
        {
            return;
        }
#endif
        if(2 == track_log_switch(0xFF))
        {
            OTA_kal_prompt_trace(MOD_TST, "%s", fmt);
        }
        else if(4 == track_get_at_port())
        {
            USB_PutBytes((kal_uint8*)fmt, size);
            USB_PutBytes((kal_uint8*)"\r\n", 2);
        }
        else if(0 == track_get_at_port() && track_drv_uart_log_mode(99) != 1)
        {
            U_PutUARTBytes(0, (kal_uint8*)fmt, size);
            U_PutUARTBytes(0, (kal_uint8*)"\r\n", 2);
        }
        else if(1 == track_get_at_port())
        {
            U_PutUARTBytes(1, (kal_uint8*)fmt, size);
            U_PutUARTBytes(1, (kal_uint8*)"\r\n", 2);
        }
    }
    else if(LOG_2FILE == g_logTarget)
    {
        //add log to fat function
        track_log2file(fmt, size);
    }
    else
    {
        //LOGS("log target erro:logs:%s",fmt);
    }
}

#endif

/******************************************************************************
 * FUNCTION:  LOGC *
 * DESCRIPTION: -  *直接输出到串口
 * Input:  *
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 08-08-2012,   wangqi written
 * --------------------
 ******************************************************************************/
void LOGS(const char *fmt, ...)
{
    static char logCbuf[1024];
    va_list args;
    char *p;
    int n, m;

    memset(logCbuf, 0, 1024);
    p = logCbuf;
    m = 1020;
    va_start(args, fmt);
    n = vsnprintf(p, m, fmt, args);
    va_end(args);

    track_trace(logCbuf, n);
}


/******************************************************************************
 *  Function    -  LOGT
 *
 *  Purpose     -  用于测试模式输出
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-10-10,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LOGT(const char *fmt, ...)
{
    static char logTbuf[512];
    va_list args;
    char *p;
    int n, m;

    memset(logTbuf, 0, sizeof(logTbuf));
    p = logTbuf;
    m = 508;
    va_start(args, fmt);
    n = vsnprintf(p, m, fmt, args);
    va_end(args);

    if(track_is_testmode())
    {
        track_trace(logTbuf, n);
    }
    else if(log_setting.logd_module[1] >= 5)
    {
        track_trace(logTbuf, n);
    }
}


/******************************************************************************
 * FUNCTION:  LOGD *
 * DESCRIPTION: -  *
 * Input:  *
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 19-07-2012,    written
 * --------------------
 ******************************************************************************/
void LOGDD(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *fmt, ...)
{
    static char logBuf[1024];
    va_list args;
    char *p;
    int l, m, n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
    LOGS("LOGSDD(cur:%d,%d,setting:%d,%d,%d,nvram:%d,%d,%d)catcher:%d", module, grade,
         g_module, g_grade, (kal_uint16)module & g_module
         , log_setting.logd_module, log_setting.logd_level, log_setting.logd_target, CatcherMode);
#endif
    if(!grade || module >= L_MAX)
    {
        return;//目前只支持8个模块参见nvram结构
    }
    if(grade > log_setting.logd_module[module])
    {
        return;
    }

    memset(logBuf, 0, 1024);

    if(fun_name != NULL && strlen(fun_name) > 0)
    {
        l = sprintf(logBuf, "[%d]%s() ", module, fun_name);
    }
    else
    {
        l = sprintf(logBuf, "[%d]", module);
    }

    p = logBuf + l;
    m = 1020 - l;
    va_start(args, fmt);
    n = vsnprintf(p, m, fmt, args);
    va_end(args);

    track_trace(logBuf, l + n);
}

#if !defined (__REMOVE_LOG_TO_FILE__)
void LOGDD2(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *fmt, ...)
{
    static char logBuf[1024];
    va_list args;
    char *p;
    int l, m, n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!grade || module >= L_MAX)
    {
        return;//目前只支持8个模块参见nvram结构
    }
    if(grade > log_setting.logd_module[module])
    {
        return;
    }

    memset(logBuf, 0, 1024);

    if(fun_name != NULL && strlen(fun_name) > 0)
    {
        l = sprintf(logBuf, "[%d]%s() ", module + 10, fun_name);
    }
    else
    {
        l = sprintf(logBuf, "[%d]", module + 10);
    }

    p = logBuf + l;
    m = 1020 - l;
    va_start(args, fmt);
    n = vsnprintf(p, m, fmt, args);
    va_end(args);

    track_trace2(logBuf, l + n);
}
#endif

/******************************************************************************
 * FUNCTION:  - LOGB *
 * DESCRIPTION: -  将字符按二进制输出 *
 * Input:
 * Output:
 * Returns:
 *
 * modification history
 * --------------------
 * v1.0  , 15-10-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void LOGB(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const void * buff, int size)
{
    static char* H_TABLE[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    char str[200], *pstr, *pSrc;
    int index = 0;
    pstr = (char*)str;
    pSrc = (char*)buff;

    if((size <= 0) || (buff == NULL))
    {
        return;
    }
    if(!grade || module >= L_MAX)
    {
        return;//目前只支持8个模块参见nvram结构
    }
    if(grade > log_setting.logd_module[module])
    {
        return;
    }

    memset(str, 0, sizeof(str));
    LOGC(module, grade, "LOG BYTES:");
    while(index < size)
    {
        sprintf(pstr, "%s%s ", H_TABLE[(pSrc[index] & 0xF0) >> 4], H_TABLE[pSrc[index] & 0x0F]);
        pstr += 9;
        if((pstr - str) % 8 == 0)
        {
            track_trace(str, 72);
            memset(str, 0, sizeof(str));
            pstr = (char*)str;
        }
        pSrc++;
        index++;
    }

    if(size % 8)
    {
        track_trace(str, size % 8 * 9);
    }
}

/******************************************************************************
 *  Function    -  Print_Memory_HEX
 *
 *  Purpose     -  打印出一段内存空间十六进制的值
 *
 *  Description -  请使用LOG,7打开LOG_HEX  使用LOG,7,0关闭LOG_HEX输出
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 13-07-2010,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LOGHH(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *text, void * buff, int size)
{
    char str[200] = {0}, *ptr, *ptr1;
    int i = 0, j;

    if(grade < 0 || module >= L_MAX)
    {
        return;
    }
    if(grade > log_setting.logd_module[module])
    {
        return;
    }
    ptr = (char*)str;
    ptr1 = (char*)buff;
    if(size <= 0)
    {
        return;
    }
    if(text)
    {
        LOGS("HEX:%s() %s", fun_name, text);
    }
    else
    {
        LOGS("HEX:%s()", fun_name);
    }
    j = sprintf(str, "    ");
    ptr += j;
    while(i < size)
    {
        sprintf(ptr, "%0.2X ", *ptr1);
        ptr += 3;
        if((i + 1) % 40 == 0)
        {
            LOGS("%s", str);
            memset(str, 0, sizeof(str));
            sprintf(str, "    ");
            ptr = (char*)str + 4;
        }
        ptr1++;
        i++;
    }
    if(strlen(str) > 0)
    {
        LOGS("%s", str);
    }
}


void LOGHH3(const char *text , void * buff, int size)
{
    char str[200] = {0}, *ptr, *ptr1;
    int i = 0, j;
    ptr = (char*)str;
    ptr1 = (char*)buff;
    if(size <= 0)
    {
        return;
    }
    if(text)
    {
        LOGS("HEX:%s",  text);
    }
    else
    {
        LOGS("HEX:");
    }
    j = sprintf(str, "    ");
    ptr += j;
    while(i < size)
    {
        sprintf(ptr, "%0.2X ", *ptr1);
        ptr += 3;
        if((i + 1) % 40 == 0)
        {
            LOGS("%s", str);
            memset(str, 0, sizeof(str));
            sprintf(str, "    ");
            ptr = (char*)str + 4;
        }
        ptr1++;
        i++;
    }
    if(strlen(str) > 0)
    {
        LOGS("%s", str);
    }
}

#if 0
//没有开GB2312的支持宏无法转码
void LOG_UNI(enum_LOG_MODULE module, enum_LOG_LEVEL grade, char * unictx, int uctxlen)
{
    char gbcode[512] = {0};
    kal_int32 ret = 0;
    memset(gbcode, '\0', sizeof(gbcode));
    //ret =  mmi_chset_utf8_to_ucs2_string((kal_uint8*)addUCS2 , dest_size, (kal_uint8*)address);
    //dest_size = sizeof(address_byte);
    ret =   mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_GB2312, unictx, gbcode, uctxlen);
    LOGC(module, grade, "LOG_UNI:%d", ret);
    track_trace(gbcode, ret);
}
#endif

kal_uint8 track_init_logd(void)
{
    kal_bool ret;
    ret = Track_nvram_read(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
    OTA_kal_prompt_trace(MOD_TST, "[track_init_logd:%d,%d]", log_setting.log_sw, log_setting.logd_target);

    if(0 != log_setting.log_sw && 1 != log_setting.log_sw)
    {
        log_setting.log_sw = 0;
    }
    //track_log_switch(log_setting.log_sw);
    if(LOG_2FILE == log_setting.logd_target)
    {
        log_file_int();
    }
    else if(LOG_AUTO == log_setting.logd_target)
    {
        log_setting.logd_target = is_catcher_mode();
        Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
    }

    g_logTarget = log_setting.logd_target;

    if(log_setting.log_sw)
    {
        /*请谨慎在此函数加日志*/
        //LOGD(L_CON, L_V4, "sw:%d(%s,%d)ret:%d", log_setting.log_sw,format_str(log_setting.logd_module, L_MAX), log_setting.logd_target, ret);
    }
    return log_setting.log_sw;
}

U16 track_os_log_set_switch(U16 var)
{
    log_setting.logd_target = var;
}

int get_cur_logd_setting(char * msg)
{
    //track_init_logd();
    sprintf(msg, "sw:%d,module:%s,target:%d", log_setting.log_sw, format_str(log_setting.logd_module, L_MAX), log_setting.logd_target);
    //kal_prompt_trace(MOD_TST, "get_cur_logd_setting(%s)", msg);

    return strlen(msg);
}

/*****************************************************************
* FUNCTION:  - track_log_change *
* Input: module 范围[0-16,0xff]0 for close all module log output
                    1-16 for module
                    0xFF for open all module log output
                    请对应enum_LOG_MODULE使用
          grade  1范围0-原则上小于0xFFFF都可以，使用中最好对应enum_LOG_LEVEL
                 2如果此参数为非空为0,且modlue在1-16之间则关闭对应modlue模块输出
          target 请对应 枚举 log_target 使用
* Returns: 是否操作成功，主要是对nvram操作
 * modification history
 * --------------------
 * v1.0  , 03-08-2012,   wangqi written
 * --------------------
******************************************************************************/
kal_bool track_log_change(int module, int grade, int target)
{
    LOGD(L_CON, L_V7, "(module:%d,grade%d,%d,target:%d,%d)", module, grade, (kal_uint16)grade, target, (kal_uint16)target);

    if(module >= L_CON && module < L_MAX)
    {
        if(module == L_CON && grade < 0)
        {
            memset(log_setting.logd_module, 0, L_MAX);
            log_setting.log_sw = 0;
            track_log_switch(0x00);
            LOGD(L_CON, L_V5, "[mini usb plug project, ERROR, all log was closed!!]");
            return Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);

        }
        else if(grade >= 0 && grade < 0xFF)
        {
            log_setting.logd_module[module] = (kal_uint16)grade;
        }
        else
        {
            log_setting.logd_module[module] = L_V5;
        }
    }
    else if(module == 0xFF)
    {
        if(grade < 0 || grade > 0xFF)
        {
            grade = L_V5;
        }
        memset(log_setting.logd_module, grade, L_MAX);
    }
#ifdef _LOG_CASE__
    else if(module == 0x11)
    {
        test_log_hex("Hello,this is a test from log 32");
    }

#endif /* _LOG_CASE__ */

    if(target >= LOG_AUTO && target < LOG_MAX)
    {
        log_setting.logd_target = (kal_uint16)target;
        if(log_setting.logd_target == LOG_2FILE)
        {
            log_file_int();
        }
    }

    LOGD(L_CON, L_V5, "g_module:%s,%d,%d,%d", format_str(log_setting.logd_module, L_MAX), g_logTarget, log_setting.logd_target, target);

    g_logTarget = log_setting.logd_target;
    log_setting.log_sw = 1;
    track_log_switch(0x01);

    return Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
}

void track_log_output_mode(char *msg, kal_uint8 part, char *par1, char *par2, char *par3)
{
    kal_bool ret;
    int len = 0;
    static port_setting_struct port_setting = {0};
    ret = Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
    if(!ret)
    {
        sprintf(msg, "ReadRecord Error!");
        return;
    }
    if(part == 3)
    {
        if(!strcmp(par1, "1") || !strcmp(par1, "UART1"))
        {
            port_setting.ps_port = 0;
        }
        else if(!strcmp(par1, "2") || !strcmp(par1, "UART2"))
        {
            port_setting.ps_port = 1;
        }
        else if(!strcmp(par1, "3") || !strcmp(par1, "UART3"))
        {
            port_setting.ps_port = 2;
        }
        else if(!strcmp(par1, "USB"))
        {
            port_setting.ps_port = 4;
        }
        else
        {
            port_setting.ps_port = 99;
        }
        if(!strcmp(par2, "1") || !strcmp(par2, "UART1"))
        {
            port_setting.tst_port_l1 = 0;
            port_setting.tst_port_ps = 0;
        }
        else if(!strcmp(par2, "2") || !strcmp(par2, "UART2"))
        {
            port_setting.tst_port_l1 = 1;
            port_setting.tst_port_ps = 1;
        }
        else if(!strcmp(par2, "3") || !strcmp(par2, "UART3"))
        {
            port_setting.tst_port_l1 = 2;
            port_setting.tst_port_ps = 2;
        }
        else if(!strcmp(par2, "USB"))
        {
            port_setting.tst_port_l1 = 4;
            port_setting.tst_port_ps = 4;
        }
        else
        {
            port_setting.tst_port_l1 = 99;
            port_setting.tst_port_ps = 99;
        }
        if(port_setting.ps_port == port_setting.tst_port_l1 && port_setting.tst_port_l1 != 99)
        {
            sprintf(msg, "Error: Parameters one and parameter two can not be the same.");
            return;
        }
        if(!strcmp(par3, "AT"))
        {
            log_setting.logd_target = LOG_SERIAL;
        }
        else if(!strcmp(par3, "CATCHER"))
        {
            log_setting.logd_target = LOG_CATCHER;
        }
        else
        {
            sprintf(msg, "Error: The third parameter values ??can only take \"AT\" or \"CATCHER\".");
            return;
        }
        Track_nvram_write(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
        Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
    }
    if(port_setting.ps_port == 0)
        len = sprintf(msg, "AT:Uart1");
    else if(port_setting.ps_port == 1)
        len = sprintf(msg, "AT:Uart2");
    else if(port_setting.ps_port == 2)
        len = sprintf(msg, "AT:Uart3");
    else if(port_setting.ps_port == 4)
        len = sprintf(msg, "AT:USB");
    else
        len = sprintf(msg, "AT:(NONE)");
    msg += len;
    if(port_setting.tst_port_l1 == 0)
        len = sprintf(msg, ", CATCHER:Uart1");
    else if(port_setting.tst_port_l1 == 1)
        len = sprintf(msg, ", CATCHER:Uart2");
    else if(port_setting.tst_port_l1 == 2)
        len = sprintf(msg, ", CATCHER:Uart3");
    else if(port_setting.tst_port_l1 == 4)
        len = sprintf(msg, ", CATCHER:USB");
    else
        len = sprintf(msg, ", CATCHER:(NONE)");
    msg += len;
    if(log_setting.logd_target == LOG_SERIAL)
        len = sprintf(msg, ", LOG:AT");
    else if(log_setting.logd_target == LOG_CATCHER)
        len = sprintf(msg, ", LOG:CATCHER");
    else if(log_setting.logd_target == LOG_AUTO)
        len = sprintf(msg, ", LOG:AUTO");
    else if(log_setting.logd_target == LOG_2FILE)
        len = sprintf(msg, ", LOG:FILE");
    else
        len = sprintf(msg, ", LOG:(ERROR)");
    if(part > 0)
    {
        msg += len;
        len = sprintf(msg, "\r\nPlease manually reboot the device, so the changed parameter can take effect.");
    }
}

void track_log_ChangeCatcherMode(int port, char * msg)
{
    static port_setting_struct port_setting = {0};
    kal_bool ret;
    LOGD(L_CON, L_V5, "port:%d", port);
    if(port == 0 || port == 1 || port == 4)
    {
        ret = Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);

        if(ret == KAL_FALSE)
        {
            sprintf(msg, "ReadRecord Error!");
            return;
        }
    }
    if((port == 1 || port == 4) && (port_setting.tst_port_ps != 0 || port_setting.tst_port_l1 != 0))  // CMD -> Catcher
    {
        /*0 for uart 1,4 for usb*/
        port_setting.tst_port_l1 = (port == 1 ? 0 : 4);
        port_setting.tst_port_ps = port_setting.tst_port_l1;
        /*如果使用串口1看日志就直接用串口3发虚拟AT指令,如果是USB就直接使用串口1发虚拟AT*/
#if defined(__NT36__)
        port_setting.ps_port = (port == 1 ? 3 : 0);
#else
        port_setting.ps_port = (port == 1 ? 4 : 0);
#endif

        ret = Track_nvram_write(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
        sprintf(msg, "CMD->Catcher  WriteRecord %s!", (ret ? "OK" : "Error"));

        log_setting.logd_target = LOG_CATCHER;
#if defined(__NF2318__)
		track_log_change(0,-1,-1);
#else
        Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
#endif
    }
    else if(port == 0 && (port_setting.ps_port != 0 || port_setting.tst_port_ps != 99))   // Catcher -> CMD
    {
        port_setting.tst_port_ps = 99;
        port_setting.ps_port = 0;
        port_setting.tst_port_l1 = 99;
        ret = Track_nvram_write(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
        sprintf(msg, "Catcher->CMD  WriteRecord %s!", (ret ? "OK" : "Error"));

        log_setting.logd_target = LOG_AUTO;
		
#if defined(__NF2318__)
		track_log_change(0,-1,-1);
#else
        Track_nvram_write(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
#endif

    }
    else
    {
        sprintf(msg, "No operation. AT^GT_CM=CA[,0/1/4]!");
    }

    if(ret)
    {
        if(port_setting.ps_port == 99)
        {
            strcat(msg, " CMD:Closed;");
        }
        else if(port_setting.ps_port == 0)
        {
            strcat(msg, " CMD:Uart 1;");
        }
        else if(port_setting.ps_port == 2)
        {
            strcat(msg, " CMD:Uart 3;");
        }

        if(port_setting.tst_port_ps == 99)
        {
            strcat(msg, "Catcher:Closed;");
        }
        else if(port_setting.tst_port_ps == 0)
        {
            strcat(msg, "Catcher:Uart 1;");
        }
        else if(port_setting.tst_port_ps == 4)
        {
            strcat(msg, "Catcher:USB 4;");
        }

    }
}

void track_temp_set_log(kal_uint16 module, kal_uint16 grade)
{
    if(module >= L_CON && module < L_MAX && grade < 0xFF)
    {
        log_setting.logd_module[module] = grade;
    }
}

void track_os_log_abnormal_data(kal_uint8 errorid)
{
    applib_time_struct currTime = {0};
    G_sys_abnormal_data.start_flag = 0;
    G_sys_abnormal_data.errorCount++;
    if(G_sys_abnormal_data.error[G_sys_abnormal_data.error_index] != 0)
    {
        G_sys_abnormal_data.error_index++;
        if(G_sys_abnormal_data.error_index >= 20)
        {
            G_sys_abnormal_data.error_index = 0;
        }
    }
    G_sys_abnormal_data.error[G_sys_abnormal_data.error_index] = errorid;
    applib_dt_get_rtc_time(&currTime);
    G_sys_abnormal_data.errortime[G_sys_abnormal_data.error_index] = applib_dt_mytime_2_utc_sec(&currTime, 0);
    Track_nvram_write(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
}
void track_os_log_abnormal_net_error_set(void)
{
    if(G_sys_abnormal_data.error[G_sys_abnormal_data.error_index] == 28)
    {
        G_sys_abnormal_data.error[G_sys_abnormal_data.error_index] = 128;
    }
    Track_nvram_write(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);

}
kal_bool track_os_log_abnormal_is_net_error(void)
{
    if(G_sys_abnormal_data.error[G_sys_abnormal_data.error_index] == 28)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void track_os_log_abnormal_data_view(char *out)
{
    applib_time_struct time = {0};
    int ret, i, j, max;
    kal_uint8 *buf, *p;
    buf = (kal_uint8 *)Ram_Alloc(5, 2000);
    if(buf == NULL)
    {
        return;
    }
    p = buf;
    ret = sprintf(p, "\r\nAbnormal number of restarts:%d\r\n", G_sys_abnormal_data.start_count);
    p += ret;
    if(G_sys_abnormal_data.errorCount > 0)
    {
        max = G_sys_abnormal_data.errorCount;
        if(max > 20) max = 20;
        j = G_sys_abnormal_data.error_index;
        ret = sprintf(p, "Recorded the cause of the restart list:\r\n");
        p += ret;
        for(i = 0; i < max; i++)
        {
            j--;
            if(j < 0) j = 19;
            applib_dt_utc_sec_2_mytime(G_sys_abnormal_data.errortime[j], &time, 0);
            ret = sprintf(p, "%d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d %d;\r\n",
                          time.nYear, time.nMonth, time.nDay, time.nHour, time.nMin, time.nSec,
                          G_sys_abnormal_data.error[j]);
            p += ret;
        }
    }
    ret = strlen(buf);
    if(ret < CM_PARAM_LONG_LEN_MAX)
    {
        memcpy(out, buf, ret + 1);
    }
    else
    {
        memcpy(out, buf, CM_PARAM_LONG_LEN_MAX);
        out[CM_PARAM_LONG_LEN_MAX - 1] = 0;
    }
    Ram_Free(buf);
}

void track_os_log_abnormal_data_init(void)
{
    Track_nvram_read(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
    if(G_sys_abnormal_data.start_flag == 1)
    {
        G_sys_abnormal_data.start_count++;
    }
    else
    {
        G_sys_abnormal_data.start_flag = 1;
    }
    Track_nvram_write(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
}

kal_bool track_os_log5_status(void)
{
    if(log_setting.logd_module[L_APP] > 0)
        return KAL_TRUE;
    else return KAL_FALSE;
}

void track_os_log_abnormal_data_reset(void)
{
    memset(&G_sys_abnormal_data, 0, sizeof(G_sys_abnormal_data));
    Track_nvram_write(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
}

kal_bool track_os_uart1_at_mode(void)
{
    static port_setting_struct port_setting = {0};
    kal_bool ret;
    ret = Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
    if(!ret)
    {
        LOGD(L_APP, L_V1, "ERROR!");
        return KAL_TRUE;
    }
    if(port_setting.ps_port == 0)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

#if defined(__AMS_HEX_LOG__)
/*
类型 类型2                                                参数（8个字节）
————————————————————————————————————————————————————————————————————————————————————————————————————
0x01 0x01（开机）                                         时间
0x01 0x02（SIM卡状态）                                    sim_card_status_enum
0x01 0x03（GSM网络状态）
0x01 0x04（GSM信号）
0x01 0x05（主动重启）                                     主动重启原因代码
0x01 0x06（异常重启）                                     无
0x01 0x07（域名解析请求）                                 无
0x01 0x08（IP地址连接请求）                               请求连接的IP地址
0x01 0x09（域名解析得到）                                 解析得到的IP地址
0x01 0x0A（连接成功）                                     无
0x01 0x0B（连接被迫断开）                                 本次连接持续的秒数
0x01 0x0C（连接主动断开）                                 本次连接持续的秒数
0x01 0x0D（GPS状态）                                      0 关，1 开，2 搜星，3 2D定位，4 3D定位
0x01 0x0E（电池电压）                                     （电池电压）

0x02 0x01（MQTT连接断开）                                 （参数为LBS位置）
0x02 0x02（MQTT连接断开）                                 （参数为GPS位置）
0x02 0x03（MQTT连接成功）                                 （参数为LBS位置）
0x02 0x04（MQTT连接成功）                                 （参数为GPS位置）
0x02 0x05（收到蓝牙地址）                                 （参数为LBS位置）
0x02 0x06（收到蓝牙地址）                                 （参数为GPS位置）
0x02 0x07（开锁）                                         （参数为LBS位置）
0x02 0x08（开锁）                                         （参数为GPS位置）
0x02 0x09（关锁）                                         （参数为LBS位置）
0x02 0x0A（关锁）                                         （参数为GPS位置）
0x02 0x0B（尝试多次无法开锁，失败（3 次））               （参数为LBS位置）
0x02 0x0C（尝试多次无法开锁，失败（3 次））               （参数为GPS位置）
0x02 0x0D（电机运转超时，停止转动）                       （参数为LBS位置）
0x02 0x0E（电机运转超时，停止转动）                       （参数为GPS位置）
0x02 0x0F（异常开锁）                                     （参数为LBS位置）
0x02 0x10（异常开锁）                                     （参数为GPS位置）
0x02 0x10（震动提示）                                     （参数为LBS位置）
0x02 0x10（震动提示）                                     （参数为GPS位置）
0x02 0x11（GPS定位，2D）                                  （参数为GPS位置）
0x02 0x12（GPS定位，3D）                                  （参数为GPS位置）
*/

typedef struct
{
    LOCAL_PARA_HDR
    U8              type;
    U8              type2;
    U8              par[8];
} OsFileLog_struct;

static U32 log_block_max  = 1000;
static FS_HANDLE file_hd = -1;

U32 track_os_file_log_get_block(void)
{
    if(G_realtime_data.logBlocksEnd >= G_realtime_data.logBlocksBegin)
        return G_realtime_data.logBlocksEnd - G_realtime_data.logBlocksBegin;
    else
        return G_realtime_data.logBlocksEnd + log_block_max - G_realtime_data.logBlocksBegin;
}

void track_os_file_log(U8 type, U8 type2, U8 *par)
{
    OsFileLog_struct *myMsgPtr = NULL;

    myMsgPtr = (OsFileLog_struct*) construct_local_para(sizeof(OsFileLog_struct), TD_RESET);
    if(myMsgPtr == NULL)
    {
        track_cust_restart(54, 0);
    }
    myMsgPtr->type = type;
    myMsgPtr->type2 = type2;
    if(par != NULL)
        memcpy(myMsgPtr->par, par, 8);
    track_fun_msg_send(MSG_ID_OSFILELOG_ID, myMsgPtr, kal_get_active_module_id(), MOD_MMI);
}

void track_os_file_log_expiry(void *local_para_ptr)
{
    static kal_bool init_ok = KAL_TRUE, init_time = 0, thefirst = 0;
    static S32 offsetBegin = -1, offsetEnd = -1;
    static U32 tick = 0, count = 0;
    U32 filesize = 0, timep = OTA_app_getcurrtime();/*获得当前时间的秒数*/
    S32 ret;
    U8 b[20] = {0};
    OsFileLog_struct *myMsgPtr = (OsFileLog_struct *)local_para_ptr;
    count++;
    if(tick == 0) tick = OTA_kal_get_systicks();
    LOGS("tick:%d, count:%d", tick, count);
    LOGD(L_APP, L_V5, "已经存储%d条log数据", track_os_file_log_get_block());


    if(OTA_kal_get_systicks() < KAL_TICKS_1_SEC) return;

    b[0] = 0xFE;
    PUT_UINT32_BE(timep, b, 1);
    b[5] = myMsgPtr->type;
    b[6] = myMsgPtr->type2;
    if(myMsgPtr->par != NULL)
        memcpy(&b[7], myMsgPtr->par, 8);

    if(init_ok)
    {
        init_ok = KAL_FALSE;
        Track_nvram_read(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    //if(offsetEnd < 0)
    {
        if(G_realtime_data.logBlocksBegin >= log_block_max || G_realtime_data.logBlocksEnd >= log_block_max)
        {
            offsetBegin = 0;
            offsetEnd = 0;
        }
        else
        {
            offsetBegin = G_realtime_data.logBlocksBegin;
            offsetEnd = G_realtime_data.logBlocksEnd;
        }
    }
    if(FS_NO_ERROR > (S32)file_hd)
    {
        file_hd = FS_Open(L"log.txt", FS_CREATE | FS_READ_WRITE);
        if(FS_NO_ERROR > file_hd)
        {
            LOGD(L_APP, L_V1, "ERROR:文件未打开");
            return;
        }
    }
    ret = FS_Seek(file_hd, offsetEnd * 15, FS_FILE_BEGIN);
    if(FS_NO_ERROR > ret)
    {
        FS_Close(file_hd);
        file_hd = -1;
        return;
    }
    ret = FS_Write(file_hd, (void *)b, 15, &filesize);
    if(FS_NO_ERROR > ret)
    {
        FS_Close(file_hd);
        file_hd = -1;
        return;
    }
    FS_Commit(file_hd);
    if(offsetEnd < offsetBegin)
    {
        offsetEnd++;
        if(offsetEnd == offsetBegin)
        {
            offsetBegin++;
            if(offsetBegin >= log_block_max)
            {
                offsetBegin = 0;
            }
        }
    }
    else
    {
        offsetEnd++;
        if(offsetEnd >= log_block_max)
        {
            offsetEnd = 0;
            if(offsetBegin == 0) offsetBegin++;
        }
    }
    G_realtime_data.logBlocksEnd = offsetEnd;
    G_realtime_data.logBlocksBegin = offsetBegin;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}

U32 track_os_file_log_view()
{
    U32 end, size;
    int filelen;
    if(FS_NO_ERROR > (S32)file_hd)
    {
        file_hd = FS_Open(L"log.txt", FS_CREATE | FS_READ_WRITE);
        if(FS_NO_ERROR > file_hd)
        {
            LOGD(L_APP, L_V1, "ERROR:文件未打开");
            return;
        }
    }
    FS_GetFileSize(file_hd, &filelen);
    if(G_realtime_data.logBlocksEnd == 0)
        end = log_block_max - 1;
    else
        end = G_realtime_data.logBlocksEnd - 1;
    if(G_realtime_data.logBlocksEnd >= G_realtime_data.logBlocksBegin)
        size = G_realtime_data.logBlocksEnd - G_realtime_data.logBlocksBegin;
    else
        size = G_realtime_data.logBlocksEnd + log_block_max - G_realtime_data.logBlocksBegin;
    //LOGD(L_APP, L_V5, "size: %d, block:%d, begin:%d, end:%d", filelen, size, G_realtime_data.logBlocksBegin, end);
    LOGS("FileSize: %d, block:%d, begin:%d, end:%d", filelen, size, G_realtime_data.logBlocksBegin, end);
    return size;
}

//0为还未上传amslog，1为正在上传ams log数据
kal_uint8 track_cust_ams_updata(kal_uint8 data)
{
    static kal_uint8 is_ams_up = 0;
    if(data == 0xff)
    {
        return is_ams_up;
    }
    else
    {
        is_ams_up = data;
    }
}

void track_os_file_log_send()
{
    U32 readsize, size = track_os_file_log_get_block();
    track_cust_ams_updata(1);
    while(size > 0)
    {
        int ret, len, i = 0;
        U8 *d = (U8*)Ram_Alloc(5, 2000);
        if(size > 60) size = 60;
        if(FS_NO_ERROR > (S32)file_hd)
        {
            file_hd = FS_Open(L"log.txt", FS_CREATE | FS_READ_WRITE);
            if(FS_NO_ERROR > file_hd)
            {
                LOGD(L_APP, L_V1, "ERROR:文件未打开");
                break;
            }
        }
        ret = FS_Seek(file_hd, G_realtime_data.logBlocksBegin * 15, FS_FILE_BEGIN);
        if(FS_NO_ERROR > ret)
        {
            FS_Close(file_hd);
            file_hd = -1;
            break;
        }
        if(G_realtime_data.logBlocksBegin + size >= log_block_max)
        {
            len = log_block_max - G_realtime_data.logBlocksBegin;
            ret = FS_Read(file_hd, (void *)d, len * 15, &readsize);
            if(FS_NO_ERROR > ret)
            {
                FS_Close(file_hd);
                file_hd = -1;
                break;
            }
            ret = FS_Seek(file_hd, 0, FS_FILE_BEGIN);
            if(FS_NO_ERROR > ret)
            {
                FS_Close(file_hd);
                file_hd = -1;
                break;
            }
            len = size - len;
            ret = FS_Read(file_hd, d + readsize, len * 15, &readsize);
            if(FS_NO_ERROR > ret)
            {
                FS_Close(file_hd);
                file_hd = -1;
                break;
            }
            G_realtime_data.logBlocksBegin = len;
        }
        else
        {
            len = size;
            ret = FS_Read(file_hd, (void *)d, len * 15, &readsize);
            if(FS_NO_ERROR > ret)
            {
                FS_Close(file_hd);
                file_hd = -1;
                break;
            }
            G_realtime_data.logBlocksBegin += len;
        }
        if(G_realtime_data.logBlocksBegin == G_realtime_data.logBlocksEnd && G_realtime_data.AMS_HEX_sw_log == 2)
        {
            G_realtime_data.AMS_HEX_sw_log = 1;
            //Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        AMS_HEXlog_upload(d, size * 15);
        /*while(i < size)
        {
            LOGH(L_APP, L_V5, d + i * 10, 10);
            i++;
        }*/
        Ram_Free(d);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        break;
    }
}

void track_os_file_log_change_par(U32 arg)
{
    log_block_max = arg;
    LOGS("log_block_max:%d", log_block_max);
}

void track_os_file_log_test(U32 arg)
{
    int i;
    U8 tmp[8];
    for(i = 0; i < arg; i++)
    {
        tmp[0] = i;
        track_os_file_log(10, 01, tmp);
        /*track_os_file_log(4, 0);
        track_os_file_log(5, 0);
        track_os_file_log(3, OTA_kal_get_systicks());
        track_os_file_log(1, 0);
        track_os_file_log(2, OTA_kal_get_systicks());
        track_os_file_log(6, 0);
        track_os_file_log(9, OTA_kal_get_systicks());
        track_os_file_log(7, i);
        track_os_file_log(8, 0);*/
    }
    LOGS("track_os_file_log write count %d", arg);
    track_os_file_log_view();
}
#endif /* __AMS_HEX_LOG__ */


#endif/*__GPS_TRACK__*/
