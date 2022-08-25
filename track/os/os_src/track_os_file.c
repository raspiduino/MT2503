/******************************************************************************
 * track_os_file.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *       GPS文件管理
 *
 * modification history
 * --------------------
 *
 ******************************************************************************/
#if defined(__GPS_TRACK__)
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_log.h"
#include "c_RamBuffer.h"
#include "c_string.h"
#include "track_cmd.h"
#include "track_os_ell.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

#define gps_data_backup                 "gps_data_backup"

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    int         iDrvLetter;
    WCHAR       wfile_name[64];
    FS_HANDLE   wfile_hd;
    kal_uint32  writen_size;    
#if !defined (__REMOVE_LOG_TO_FILE__)
    c_string*   string;
#endif /* __REMOVE_LOG_TO_FILE__ */
    
} FAT_FILE_ST;

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/


static      FAT_FILE_ST gps_backup_file = {0};
static      FAT_FILE_ST gps_file = {0};
static  WCHAR       gps_file_name[128];//冗余 chengj
static  kal_uint8 realtime_data[4 * 1000] = {0};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
kal_uint8 realtime_disarm_tmp = 0;//获取升级前的撤防状态
kal_uint8 ota_login = 0;//固件升级后的登录

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/


static int gps_data_write_file(void* data, int length, int  Offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

//  OTA_kal_wsprintf(gps_file_name, "%w", L"%s", gps_backup_file.wfile_name);
    // gps_backup_file.wfile_hd = FS_Open(gps_file_name , FS_CREATE | FS_READ_WRITE);
    LOGD(L_DRV, L_V5, "");
    fs_seek = FS_Seek(gps_backup_file.wfile_hd, Offset, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        // FS_Close(gps_backup_file.wfile_hd);
        LOGD(L_DRV, L_V5, "FS_Seek %d", fs_seek);
        return -4;
    }

    fs_write = FS_Write(gps_backup_file.wfile_hd, (void *)data, length , &file_operate_size);
    LOGD(L_DRV, L_V1, "READ  file_operate_size%d,file_operate_size%d", file_operate_size, length);

    if(fs_write < FS_NO_ERROR)
    {
        //   FS_Close(fs_write);
        //fs_seek = FS_Delete(backup_file_name);
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -5;
    }
    FS_Commit(gps_backup_file.wfile_hd);
    return file_operate_size;
}


static int gps_data_read_file(void* data, int length, int  Offset)
{
    kal_uint32   file_operate_size;
    int fs_seek = 0, fs_write = 0;

    LOGD(L_DRV, L_V5, "");

    fs_seek = FS_Seek(gps_backup_file.wfile_hd, Offset, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        //FS_Close(gps_backup_file.wfile_hd);
        LOGD(L_DRV, L_V5, "FS_Seek %d", fs_seek);
        return -2;
    }

    fs_write = FS_Read(gps_backup_file.wfile_hd, (void *)data, length , &file_operate_size);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(fs_write);
        //fs_seek = FS_Delete(backup_file_name);
        LOGD(L_DRV, L_V5, "ret fs_write:%d fs_seek=%d", fs_write, fs_seek);
        return -3;
    }
    FS_Commit(gps_backup_file.wfile_hd);
    return file_operate_size;
}

kal_bool track_gps_data_file_check(kal_uint8* data, kal_uint32 len)
{
    if(data[0] == 0x2a && data[1] == 0)
    {
        return TRUE;
    }
    else  if(data[0] == 0x28 && data[1] == 0)
    {
        return TRUE;
    }
    else  if(data[2] == 0x78 && data[3] == 0x78)
    {
        return TRUE;
    }
	#if defined(__NF2318__)
	else  if((data[2] == 0xAA && data[3] == 0xAA) || (data[2] == 0xAA && data[3] == 0xBB))
    {
        return TRUE;
    }
	#endif
    else
    {
        return FALSE;
    }
}
/******************************************************************************
 *  Function    -  gps_data_backup_manage
 *
 *  Purpose     -  gps备份管理
 *  Description -  NULL
 *
 *  type      -  1   为读
 *                   2为写
 *                   4为关闭文件
 *                  3删除文件
 * modification history
 * ----------------------------------------
 * ----------------------------------------
 ******************************************************************************/
void gps_data_backup_manage(kal_uint8 type , kal_uint8* data, kal_uint32  id, kal_uint32  len)
{
    WCHAR       gps_file_name[128];
    static kal_uint8 first = 0;
    int ret = 0;
    extern void track_reset_backup(void);

    LOGD(L_DRV, L_V5, "id=%d", id);
    if(id <= 0)
    {
        id = 1;
    }
    if(first == 0)
    {
        first = 1;
        OTA_kal_wsprintf(gps_file_name, "%s", "GPS_DATA_BACKUP");
        OTA_kal_wsprintf(gps_backup_file.wfile_name, "%s", "GPS_DATA_BACKUP");
        gps_backup_file.wfile_hd = FS_Open(gps_file_name , FS_CREATE | FS_READ_WRITE);
        if(gps_backup_file.wfile_hd < 0)
        {
            LOGD(L_DRV, L_V1, "ERROR %d", gps_backup_file.wfile_hd);
        }
        LOGD(L_DRV, L_V5, "wfile_hd %d", gps_backup_file.wfile_hd);

    }
    if(type == 1)
    {
        FS_GetFileSize(gps_backup_file.wfile_hd, &gps_backup_file.writen_size);
        if(gps_backup_file.writen_size >= (id - 1) * len)
        {
            ret = gps_data_read_file(data, len, (id - 1) * len);
            if(!track_gps_data_file_check(data, len))
            {
                ret = -8;
            }
        }
        else
        {
            ret = -7;
        }
    }
    else if(type == 2)
    {
        FS_GetFileSize(gps_backup_file.wfile_hd, &gps_backup_file.writen_size);
        if(gps_backup_file.writen_size < 502 * len)//1002
        {
            ret = gps_data_write_file(data, len, (id - 1) * len);
        }
        else
        {
            ret = -9;
        }
    }
    else if(type == 3)
    {
        first = 0;
        OTA_kal_wsprintf(gps_file_name, "%s", "GPS_DATA_BACKUP");
        FS_Close(gps_backup_file.wfile_hd);
        FS_Delete(gps_file_name);
    }
    else if(type == 4)
    {
        first = 0;
        FS_Close(gps_backup_file.wfile_hd);
    }
    else if(type == 5)
    {
        first = 0;
        FS_Close(gps_backup_file.wfile_hd);
        track_reset_backup();
        OTA_kal_wsprintf(gps_file_name, "%s", "GPS_DATA_BACKUP");
        FS_Delete(gps_backup_file.wfile_name);
    }
    if(ret < 0)
    {
        first = 0;
        FS_Close(gps_backup_file.wfile_hd);
        track_reset_backup();
        OTA_kal_wsprintf(gps_file_name, "%s", "GPS_DATA_BACKUP");
        FS_Delete(gps_backup_file.wfile_name);

        LOGD(L_DRV, L_V1, "ERROR ret= %d", ret);
    }
}





kal_int8 track_log_read(kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "GPS_log_level");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_log_level");
    gps_file.wfile_hd = FS_Open(gps_file_name ,  FS_READ_ONLY);
    if(gps_file.wfile_hd < FS_NO_ERROR)
    {
        return -1;

    }
    FS_GetFileSize(gps_file.wfile_hd, &gps_file.writen_size);
    if(gps_file.writen_size <= 0)
    {
        return -10;
    }

    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    fs_write = FS_Read(gps_file.wfile_hd, realtime_data, gps_file.writen_size , &file_operate_size);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -2;
    }
    CRC = realtime_data[1];
    CRC = (CRC << 8) + realtime_data[0];
    memcpy(&data_len, &realtime_data[2], 4);
    if(gps_file.writen_size - 6 == len)
    {
        if(gps_file.writen_size - 6 == data_len)
        {
            if(CRC == GetCrc16(&realtime_data[6], len))
            {
                memcpy(data, &realtime_data[6], len);
            }
            else
            {
                FS_Close(gps_file.wfile_hd);
                return -3;
            }
        }
        else
        {
            FS_Close(gps_file.wfile_hd);
            return -4;
        }
    }
    else
    {
        FS_Close(gps_file.wfile_hd);
        return -5;
    }
    FS_Commit(gps_file.wfile_hd);
    FS_Close(gps_file.wfile_hd);
    return 0;
}

kal_int8 track_log_write(kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "GPS_log_level");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_log_level");
    memset(realtime_data, 0x00, 500);
    FS_Delete(gps_file.wfile_name);
    gps_file.wfile_hd = FS_Open(gps_file_name , FS_CREATE | FS_READ_WRITE);
    if(gps_file.wfile_hd  < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -7;
    }
    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -8;
    }
    memcpy(&realtime_data[6], data, len);
    CRC = GetCrc16(&realtime_data[6], len);

    realtime_data[1] = (CRC & 0xFF00) >> 8;
    realtime_data[0] = (CRC & 0x00FF);
    memcpy(&realtime_data[2], &len, 4);


    fs_write = FS_Write(gps_file.wfile_hd, (void *)realtime_data, len + 6 , &file_operate_size);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -6;
    }
    FS_Commit(gps_file.wfile_hd);
    FS_Close(gps_file.wfile_hd);
    return 0;
}

void track_log_manage(kal_uint8 type , kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    static kal_uint8 cnt = 0;

    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0;
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_log_level");

    //  if(kal_get_systicks() <1000) return;

    if(type == 1)
    {
        ret = track_log_read(data, len);
        if(ret < 0)
        {
            memcpy(data, OTA_NVRAM_EF_LOGD_DEFAULT,  sizeof(*OTA_NVRAM_EF_LOGD_DEFAULT));
        }
    }
    else if(type == 2)
    {
        ret = track_log_write(data, len);
    }
    else if(type == 3)
    {
        track_log_manage(2, (kal_uint8*)OTA_NVRAM_EF_LOGD_DEFAULT, sizeof(*OTA_NVRAM_EF_LOGD_DEFAULT));
    }
    else if(type == 4)
    {
        FS_Close(gps_file.wfile_hd);
    }

    if(ret < 0)
    {
        cnt++;
        if(cnt < 5)
        {
            FS_Close(gps_file.wfile_hd);
            track_log_manage(3, NULL, 0);
        }
        else
        {
            FS_Close(gps_file.wfile_hd);
        }
    }
}
typedef struct
{
    kal_uint8       in_or_out[TRACK_DEFINE_FENCE_SUM];          // 电子围栏 当前是出于围栏内(1)还是围栏外(2)
    kal_uint8       lowBattery;                                 // 低电报警发送标记
    kal_uint8       lowExtBattery;                              // 外部电源低电报警发送标记
    kal_uint8       disExtBattery;                              // 外部电源断开发送标记
    kal_uint8       flag;                                       // 位移报警 标记
    float           longitude;                                  // 位移报警
    float           latitude;                                   // 位移报警
    kal_uint32      netLogControl;                              // 在线网络上报日志控制
    kal_uint8       reStartSystemCount;                         // 20分钟重启连续计数
    kal_uint8       defences_status;                            // 设防状态  1 撤防，2 预设防，3 设防
    kal_uint8       key_status;                                 // GT02D按键状态  0 关闭LED显示    1 开启LED显示
    kal_uint8       oil_status;                                 // 油电状态（0 油电正常；1 油电断开；2 请求断开，GPS未定位；3 请求断开，未发因超速延缓执行的短信；4 请求断开，已发因超速延缓执行的短信）
    kal_uint8       oil_cmd_source;                             // 断油电指令来源
    kal_uint8       acc_last_status;                            // 用于记录ACC状态，防止开机后的状态与上次关机前一致
    kal_uint8       poweroff;                                   // 低电关机报警发送标记  24byte
    kal_uint8       power_saving_mode;                          // 省电模式(0:正常模式;1:省电模式)
}realtime_data_tmp_struct;
realtime_data_tmp_struct Realtime_Data_Temp = {0};


kal_int8 realtime_read(kal_uint8* data, kal_uint32 len)
{
	kal_uint16 realtime_size  = 0;
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0, CRC2 = 0;
    memset(realtime_data, 0, 500);
    OTA_kal_wsprintf(gps_file_name, "%s", "GPS_realtime");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_realtime");
    gps_file.wfile_hd = FS_Open(gps_file_name ,  FS_READ_ONLY);
    if(gps_file.wfile_hd < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V1, "ERROR %d", gps_file.wfile_hd);
        return -1;

    }
    FS_GetFileSize(gps_file.wfile_hd, &gps_file.writen_size);
    LOGD(L_DRV, L_V5, "size %d", gps_file.writen_size);

    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    fs_write = FS_Read(gps_file.wfile_hd, realtime_data, gps_file.writen_size , &file_operate_size);
    LOGH(L_CMD, L_V8,  &realtime_data[6], file_operate_size-6);
    LOGD(L_DRV, L_V1, "aaav READ  file_operate_size%d,len%d,ret=%d", file_operate_size, len, ret);
    if(fs_write < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -2;

        //fs_seek = FS_Delete(backup_file_name);
        LOGD(L_DRV, L_V1, "READ errror %d", fs_write);
        return;
    }
    CRC = realtime_data[1];
    CRC = (CRC << 8) + realtime_data[0];
    CRC2 = GetCrc16(&realtime_data[6], len);
    memcpy(&data_len, &realtime_data[2], 4);
    realtime_size = sizeof(realtime_data_tmp_struct);
	if((gps_file.writen_size - 6) < len && (gps_file.writen_size - 6) > realtime_size)//这种情况认为是刚升级过,且改过realtime结构
	//if((gps_file.writen_size - 6) != len && (gps_file.writen_size - 6) > realtime_size)//这种情况认为是刚升级过,且改过realtime结构
	{
		memcpy(&Realtime_Data_Temp, &realtime_data[6], sizeof(realtime_data_tmp_struct));
		realtime_disarm_tmp = Realtime_Data_Temp.defences_status;
		ota_login = 1;
		
		LOGD(L_DRV, L_V1, "disarm:%d,%d,%d,%d,%d",Realtime_Data_Temp.defences_status,Realtime_Data_Temp.acc_last_status,Realtime_Data_Temp.netLogControl,realtime_size,realtime_disarm_tmp);
		memset(&Realtime_Data_Temp, 0, sizeof(realtime_data_tmp_struct));
	}
    if(gps_file.writen_size - 6 == len)
    {
        if(gps_file.writen_size - 6 == data_len)
        {
            LOGH(L_CMD, L_V8,  &realtime_data[6], len);
            if(CRC == CRC2)
            {
                memcpy(data, &realtime_data[6], len);
            }
            else
            {
                LOGD(L_DRV, L_V1, "CRC ERROR CRC=%x,CRC2=%x,len=%d", CRC, CRC2, len);
                FS_Close(gps_file.wfile_hd);
                return -3;
            }
        }
        else
        {
            LOGD(L_DRV, L_V1, "len ERROR %d,%d,%d", gps_file.writen_size - 6, data_len, len);
            FS_Close(gps_file.wfile_hd);
            return -4;
        }
    }
    else
    {
        LOGD(L_DRV, L_V1, "len ERROR %d,%d,%d", gps_file.writen_size - 6, data_len, len);
        FS_Close(gps_file.wfile_hd);
        return -5;
    }
    FS_Close(gps_file.wfile_hd);
    return 0;
}

kal_int8 realtime_write(kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "GPS_realtime");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_realtime");
    memset(realtime_data, 0x00, 500);
    FS_Delete(gps_file.wfile_name);
    gps_file.wfile_hd = FS_Open(gps_file_name , FS_CREATE | FS_READ_WRITE);
    if(gps_file.wfile_hd  < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        LOGD(L_DRV, L_V1, "FS_Open errror %d", gps_file.wfile_hd);
        return -7;
    }
    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        LOGD(L_DRV, L_V1, "fs_seek errror %d,len", fs_seek, len);
        return -8;
    }
    memcpy(&realtime_data[6], data, len);
    LOGH(L_CMD, L_V8,  &realtime_data[6], len);

    CRC = GetCrc16(&realtime_data[6], len);
    LOGD(L_DRV, L_V1, "tempCRC  0x%X,len=%d", CRC, len);

    realtime_data[1] = (CRC & 0xFF00) >> 8;
    realtime_data[0] = (CRC & 0x00FF);
    memcpy(&realtime_data[2], &len, 4);

    LOGD(L_DRV, L_V1, "CRC  0x%X", CRC);

    fs_write = FS_Write(gps_file.wfile_hd, (void *)realtime_data, len + 6 , &file_operate_size);
    LOGD(L_DRV, L_V1, "WRITE  %d", fs_write);
    if(fs_write < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V1, "WRITE errror %d", fs_write);
        FS_Close(gps_file.wfile_hd);
        return -6;
    }
    FS_Commit(gps_file.wfile_hd);
    FS_Close(gps_file.wfile_hd);
    return 0;
}

void track_realtime_manage(kal_uint8 type , kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    static kal_uint8 cnt = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint8    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "GPS_realtime");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "GPS_realtime");
    if(type == 1)
    {
        ret = realtime_read(data, len);
        if(ret < 0)
        {
            memcpy(data, OTA_NVRAM_EF_REALTIME_DEFAULT,  sizeof(*OTA_NVRAM_EF_REALTIME_DEFAULT));
            LOGD(L_DRV, L_V1, "REALTIME 数据恢复");
        }
    }
    else if(type == 2)
    {
        ret = realtime_write(data, len);
    }
    else if(type == 3)
    {
        track_realtime_manage(2, (kal_uint8*)OTA_NVRAM_EF_REALTIME_DEFAULT, sizeof(*OTA_NVRAM_EF_REALTIME_DEFAULT));
    }
    else if(type == 4)
    {
        FS_Close(gps_file.wfile_hd);
    }


    if(ret < 0)
    {
        cnt++;
        if(cnt < 5)
        {
            LOGD(L_DRV, L_V1, "REALTIME 数据恢复%d,cnt=%d", ret, cnt);
            FS_Close(gps_file.wfile_hd);
            track_realtime_manage(3, NULL, 0);
        }
        else
        {
            LOGD(L_DRV, L_V1, "REALTIME 数据恢复%d,cnt=%d", ret, cnt);
            FS_Close(gps_file.wfile_hd);
        }
    }
}


kal_int8 track_imp_param_read(kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_read = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0, CRC2 = 0;
    memset(realtime_data, 0, 4 * 1000);
    OTA_kal_wsprintf(gps_file_name, "%s", "imp_param");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "imp_param");
    gps_file.wfile_hd = FS_Open(gps_file_name ,  FS_READ_ONLY);
    if(gps_file.wfile_hd < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V1, "ERROR %d", gps_file.wfile_hd);
        return -1;

    }
    FS_GetFileSize(gps_file.wfile_hd, &gps_file.writen_size);
    LOGD(L_DRV, L_V5, "size %d", gps_file.writen_size);

    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    fs_read = FS_Read(gps_file.wfile_hd, realtime_data, gps_file.writen_size , &file_operate_size);
    LOGH(L_CMD, L_V8,  &realtime_data[6], file_operate_size - 6);
    LOGD(L_DRV, L_V1, "aaav READ  file_operate_size%d,len%d,ret=%d", file_operate_size, len, ret);
    if(fs_read < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        return -2;

        //fs_seek = FS_Delete(backup_file_name);
        LOGD(L_DRV, L_V1, "READ errror %d", fs_read);
        return;
    }
    memcpy(&data_len, &realtime_data[2], 4);
    CRC = realtime_data[1];
    CRC = (CRC << 8) + realtime_data[0];
    CRC2 = GetCrc16(&realtime_data[6], data_len);
    if(gps_file.writen_size - 6 == len || len == 0)
    {
        if(gps_file.writen_size - 6 == data_len)
        {
            LOGH(L_CMD, L_V8,  &realtime_data[6], data_len);
            if(CRC == CRC2)
            {
                memcpy(data, &realtime_data[6], data_len);
            }
            else
            {
                LOGD(L_DRV, L_V1, "CRC ERROR CRC=%x,CRC2=%x,len=%d", CRC, CRC2, len);
                FS_Close(gps_file.wfile_hd);
                return -3;
            }
        }
        else
        {
            LOGD(L_DRV, L_V1, "len ERROR %d,%d,%d", gps_file.writen_size - 6, data_len, len);
            FS_Close(gps_file.wfile_hd);
            return -4;
        }
    }
    else
    {
        LOGD(L_DRV, L_V1, "len ERROR %d,%d,%d", gps_file.writen_size - 6, data_len, len);
        FS_Close(gps_file.wfile_hd);
        return -5;
    }
    FS_Close(gps_file.wfile_hd);
    return fs_read;
}

kal_int8 track_imp_param_write(kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint16    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "imp_param");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "imp_param");
    memset(realtime_data, 0, 4 * 1000);
    FS_Delete(gps_file.wfile_name);
    gps_file.wfile_hd = FS_Open(gps_file_name , FS_CREATE | FS_READ_WRITE);
    if(gps_file.wfile_hd  < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        LOGD(L_DRV, L_V1, "FS_Open errror %d", gps_file.wfile_hd);
        return -7;
    }
    fs_seek = FS_Seek(gps_file.wfile_hd, 0, FS_FILE_BEGIN);
    if(fs_seek < FS_NO_ERROR)
    {
        FS_Close(gps_file.wfile_hd);
        LOGD(L_DRV, L_V1, "fs_seek errror %d,len", fs_seek, len);
        return -8;
    }
    memcpy(&realtime_data[6], data, len);
    LOGH(L_CMD, L_V8,  &realtime_data[6], len);

    CRC = GetCrc16(&realtime_data[6], len);
    LOGD(L_DRV, L_V1, "ttttCRC  %X,len=%d", CRC, len);

    realtime_data[1] = (CRC & 0xFF00) >> 8;
    realtime_data[0] = (CRC & 0x00FF);
    memcpy(&realtime_data[2], &len, 4);

    LOGD(L_DRV, L_V1, "CRC  %d", CRC);

    fs_write = FS_Write(gps_file.wfile_hd, (void *)realtime_data, len + 6 , &file_operate_size);
    LOGD(L_DRV, L_V1, "WRITE  %d", fs_write);
    if(fs_write < FS_NO_ERROR)
    {
        LOGD(L_DRV, L_V1, "WRITE errror %d", fs_write);
        FS_Close(gps_file.wfile_hd);
        return -6;
    }
    FS_Commit(gps_file.wfile_hd);
    FS_Close(gps_file.wfile_hd);
    return fs_write;
}

kal_uint32 track_imp_param_manage(kal_uint8 type , kal_uint8* data, kal_uint32 len)
{
    static kal_uint8 first = 0;
    static kal_uint8 cnt = 0;

    int ret = 0;
    int fs_seek = 0, fs_write = 0;
    kal_uint32   file_operate_size, data_len;
    kal_uint8    CRC = 0;
    OTA_kal_wsprintf(gps_file_name, "%s", "imp_param");
    OTA_kal_wsprintf(gps_file.wfile_name, "%s", "imp_param");
    if(type == 1)
    {
        ret = track_imp_param_read(data, len);
    }
    else if(type == 2)
    {
        ret = track_imp_param_write(data, len);
    }
    else if(type == 3)
    {
        FS_Delete(gps_file.wfile_name);
    }
    else if(type == 4)
    {
        FS_Close(gps_file.wfile_hd);
    }


    if(ret < 0)
    {
        LOGD(L_DRV, L_V1, "imp_param 错乱，或者无文件%d", ret);
        cnt++;
        if(cnt < 5)
        {
            FS_Close(gps_file.wfile_hd);
            FS_Delete(gps_file.wfile_name);
        }
        else
        {
            FS_Close(gps_file.wfile_hd);
        }
        return 0;
    }
    else
    {
        return ret;
    }
}

#endif
