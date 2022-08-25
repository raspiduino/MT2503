/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "ell_update.h"
#include "app_datetime.h"
#include "ell_fota_memory_define.h"

//#include "flash_disk_internal.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_uint8       start_flag;         // 开机标记
    kal_uint8       error_index;        // error index
    kal_uint8       errorCount;
    kal_uint8       error[20];          //
    kal_uint32      errortime[20];      //
    kal_uint32      start_count;        // 非软件逻辑调用重启的次数统计
} ell_nvram_sys_abnormal_data_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static U8 nw_status = 99;
static U8 gprs_status = 99;
static U8 run_status = 99;
static nvram_check_ota_struct g_ell_otacheck = {0};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/


/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_bool ell_analysis(void);
extern void ELL_Fota_File_Get_From_Fat();
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void ell_reset(void *arg);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/




#if 0//defined( __TRACK_DISK_NVRAM__)
#define NVRAM_EF_IMPORTANCE_PARAMETER_LID			1
extern nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER;
    #if 0//defined( __TRACK_DISK_NVRAM__)
        readRawDiskData(&FlashDiskDriveData[1], 0x103A0000 + 0x56000 + 640, (kal_uint8 *)&G_importance, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    #else
        nvram_external_read_data(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    #endif /* __TRACK_DISK_NVRAM__ */
#endif /* __TRACK_DISK_NVRAM__ */


static void ell_update_one_run(void)
{
    if(nw_status == 0 && gprs_status == 0)
    {
        run_status = 2;
        ell_update_begin2();
        ell_start_timer_ext(ELL_RESTART_TIMER_ID, 130000, ell_reset, (U32)1);
    }
}


#if 0
kal_int8 ell_get_struct_importance(void)
{
#if defined( __TRACK_DISK_NVRAM__)
    /*#define IT1_IMPORTANCE_ADD                  (IT0_PARAMETER_ADD + 1024)*/
    readRawDiskData(&FlashDiskDriveData[1], 0x103A0000 + 0x56000 + 1024, (kal_uint8 *)&G_importance, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    if(G_importance.placeholder[0] != 0x01 && G_importance.placeholder[1] != 0x01)
    {
        memcpy(&G_importance, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        OTA_LOGD(L_DRV, L_V5, "DISK1 Nvram Error!!!%d,%d", G_importance.placeholder[0],G_importance.placeholder[0]);
    }
    return 1;
#else
    return nvram_external_read_data(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
#endif /* __TRACK_DISK_NVRAM__ */
}
#endif /* 0 */

static void ell_reset_system(void)
{
    EXT_ASSERT(0, 0, 0, 0);
}

void ell_os_log_abnormal_data(kal_uint8 errorid)
{
    ell_nvram_sys_abnormal_data_struct      ell_G_sys_abnormal_data = {0};
    applib_time_struct currTime = {0};
    nvram_external_read_data(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&ell_G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
    ell_G_sys_abnormal_data.start_flag = 0;
    ell_G_sys_abnormal_data.errorCount++;
    if(ell_G_sys_abnormal_data.error[ell_G_sys_abnormal_data.error_index] != 0)
    {
        ell_G_sys_abnormal_data.error_index++;
        if(ell_G_sys_abnormal_data.error_index >= 20)
        {
            ell_G_sys_abnormal_data.error_index = 0;
        }
    }
    ell_G_sys_abnormal_data.error[ell_G_sys_abnormal_data.error_index] = errorid;
    applib_dt_get_rtc_time(&currTime);
    EllLog("%02d-%02d-%02d %02d:%02d:%02d error_index[%d]=%d", 
        currTime.nYear, currTime.nMonth, currTime.nDay, currTime.nHour, currTime.nMin, currTime.nSec,
        ell_G_sys_abnormal_data.error_index, errorid);
    ell_G_sys_abnormal_data.errortime[ell_G_sys_abnormal_data.error_index] = applib_dt_mytime_2_utc_sec(&currTime, 0);
    nvram_external_write_data(NVRAM_EF_SYS_ABNORMAL_LID, 1, (void *)&ell_G_sys_abnormal_data, NVRAM_EF_SYS_ABNORMAL_SIZE);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void ell_reset(void *arg)
{
    EllLog("%d", (U32)arg);
    ell_os_log_abnormal_data(10);
    ell_start_timer(ELL_20MIN_RESTART_TIMER_ID, 1000, ell_reset_system);
}

void ell_update_soc_nw_attach_ind(void *msg)
{
    mmi_nw_attach_ind_struct *nw_attach_ind = (mmi_nw_attach_ind_struct*)msg;
    nw_status = nw_attach_ind->status;
    gprs_status = nw_attach_ind->gprs_status;
    //EllLog ( "status:%d, %d", nw_attach_ind->status, nw_attach_ind->gprs_status);
    if(nw_attach_ind->status == 0)
    {
        ell_socket_apn_auto_set();
    }
    if(run_status == 1)
    {
        EllLog("run_status:%d, nw_status:%d, gprs_status:%d", run_status, nw_status, gprs_status);
        ell_update_one_run();
    }
}

void ell_update_main(void)
{
    int ret;

    L1SM_SleepDisable(L1SM_GetHandle());
    
    ell_watch_dog_main(1);

    pmu_drv_bl_isink(ISINK0, KAL_TRUE);
    
    ell_update_status_set(1);
    
    ell_update_socket_apn_init(); // SOC APN Initialization
    
    EllLog("nw_status:%d, gprs_status:%d", nw_status, gprs_status);
    if(run_status == 99) run_status = 1;
    ell_update_one_run();
    
    ell_start_timer_ext(ELL_RESTART_TIMER_ID, 130000, ell_reset, (U32)2);
    ell_start_timer_ext(ELL_20MIN_RESTART_TIMER_ID, 20*60*1000, ell_reset, (U32)3);
}

S8 ell_update_delete_file(void)
{
    return 0;
}

#include "flash_disk_internal.h"


extern void ELL_SDS_Main(void);
extern kal_bool sds_update_status;
#define SDS_PAGE_SIZE  4*1024

kal_bool ELL_Check_SDS_Files(char *file_path)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        return 0;
    }
    FS_Close(fp);
    EllLog("检测到FAT存在用于升级的文件!");
    return 1;
}

kal_bool ELL_Get_SDS_FilesData(char *file_name)
{
    S32 ret_data = 0, ret = 1;
    S32 i = 0, j = 0;
    WCHAR FilePath[60];
    extern char ell_ram_buf[EBUFFERLENGTH];
    
    memset(ell_ram_buf, 0, EBUFFERLENGTH);
    ret_data = ell_get_data_from_file(file_name, ell_ram_buf, EBUFFERLENGTH);
    if(ret_data <= 0)
    {
        EllLog("Error!");
        return 0;
    }
    else
    {
        i = 0;
        while(i != 1024)
        {
            if(!strcmp(file_name, "TRACK_RO"))
            {
                ret = writeRawDiskData(&FlashDiskDriveData[1], WRITE_NEW_TRACK_RO_ADRR, ell_ram_buf, ret_data);
            }
            else if(!strcmp(file_name, "TRACK_RW"))
            {
                ret = writeRawDiskData(&FlashDiskDriveData[1], WRITE_NEW_TRACK_RW_ADRR, ell_ram_buf, ret_data);
            }
            else if(!strcmp(file_name, "TRACK_NVRAM"))
            {
                ret = writeRawDiskData(&FlashDiskDriveData[1], WRITE_NEW_TRACK_NVRAM_ADRR, ell_ram_buf, ret_data);
            }
            if(ret == 0)
            {
                j = 0;
                i = 1024;
                memset(FilePath, 0, sizeof(FilePath));
                kal_wsprintf(FilePath, file_name);
                FS_Delete(FilePath);
            }
            else
            {
                j++;
                if(j > 10)
                {
                    EllLog("Error!");
                    return 0;
                }
            }
        }
        return 1;
    }
}

int ell_erase_data(char *type)
{
    int begin, end, ret = 1, j = 0;
    EllLog("");

    if(!strcmp("RO", type))
    {
        begin = ERASE_TRACK_RO_BLOCK_BEGIN;
        end = ERASE_TRACK_RO_BLOCK_END;
    }
    else if(!strcmp("RW", type))
    {
        begin = ERASE_TRACK_RW_BLOCK_BEGIN;
        end = ERASE_TRACK_RW_BLOCK_END;
    }
    else if(!strcmp("NVRAM", type))
    {
        begin = ERASE_TRACK_NVRAM_BLOCK_BEGIN;
        end = ERASE_TRACK_NVRAM_BLOCK_END;
    }
    else
    {
        return -1;
    }
    EllLog("erase:%d-%d", begin, end);
    while(begin <= end)
    {
        ret = eraseRawDiskBlock(&FlashDiskDriveData[1], begin);
        if(ret != 0)
        {
            j++;
            if(j > 10)
            {
                return -2;
            }
            EllLog("erase ret = %d", ret);
        }
        else
        {
            j = 0;
            begin++;
        }
    }
    return 0;
}

kal_bool  ELL_Erase_SDS_Data(void * arg)
{
    S32  ret = 1;
    U32 status = (U32)arg;
    S32 i = 0, j = 0;

    if(status == 1)
    {
        i = 0;
        while(i < ERASE_TRACK_BLOCK_SIZE)
        {
            ret = eraseRawDiskBlock(&FlashDiskDriveData[1], i);
            if(ret != 0)
            {
                j++;
                if(j > 10)
                {
                    return 0;
                }
                EllLog("erase ret = %d", ret);
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }
    else
    {
        return 0;
    }
    sds_update_status = 1;
    return 1;
}

void ell_reset_unconditional(void)
{
    g_ell_otacheck.unconditional = 0;
    nvram_external_write_data(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_ell_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
}

kal_bool Ell_Check_SDS_Data(void)
{
    U8 ell_file_md5[16] = {0};
    S32 ret_data = 0, ret = 0;
    S32 i = 0;
    WCHAR FilePath[60] = {0};

    if(ell_analysis())
    {
        kal_wsprintf(FilePath, FOTA_FILE_PATH);
        ret = FS_Delete(FilePath);
        EllLog("del file %s %d", FOTA_FILE_PATH, ret);
    }
    else if(ELL_Check_SDS_Files(FOTA_FILE_RO_PATH) == 1 && ELL_Check_SDS_Files(FOTA_FILE_RW_PATH) == 1)
    {
        L1SM_SleepDisable(L1SM_GetHandle());
        ell_watch_dog_main(1);
        pmu_drv_bl_isink(ISINK0, KAL_TRUE);
        ell_update_status_set(1);
        if(ELL_Erase_SDS_Data((void*)1) == 1)
        {
            ELL_Get_SDS_FilesData(FOTA_FILE_RO_PATH);
            ELL_Get_SDS_FilesData(FOTA_FILE_RW_PATH);
            ELL_Get_SDS_FilesData(FOTA_FILE_NVRAM_PATH);
            //ELL_SDS_Main();
            return 1;
        }
    }
    else
    {
        nvram_external_read_data(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_ell_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
        if(g_ell_otacheck.unconditional == 99 || g_ell_otacheck.unconditional == 98)// || g_ell_otacheck.unconditional == 97
        {
            //ell_analysis();
            /*
            if(g_ell_otacheck.unconditional == 97)
            {	
            	ell_reset_unconditional();
            	ELL_Fota_File_Get_From_Fat();
            }
			else*/
			{
            	ell_reset_unconditional();
            	ell_update_main();//此处被替换为读取FAT保存的文件
			}
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

kal_bool Ell_Update_SDS_Data(U8 *data, U32 data_index,U32 len,U8 *md5)
{
    U32 data_page = 0, ret = 99, page_start_index = 0;
    char page_buf[SDS_PAGE_SIZE] = {0};
    data_page = data_index / (SDS_PAGE_SIZE);
    page_start_index = data_page * SDS_PAGE_SIZE;

    
    ret = readRawDiskData(&FlashDiskDriveData[1], page_start_index, page_buf, SDS_PAGE_SIZE);
    EllLog("read ret:%d, page_start:%d, page:%d", ret, page_start_index, data_page);
    ret = eraseRawDiskBlock(&FlashDiskDriveData[1], data_page);
    EllLog("erase ret:%d, page_start:%d, page:%d", ret, page_start_index, data_page);
    memcpy(&page_buf[data_index-page_start_index], data, len);

    ret = writeRawDiskData(&FlashDiskDriveData[1], page_start_index, page_buf, SDS_PAGE_SIZE);
    EllLog("write ret:%d, page_start:%d, page:%d", ret, page_start_index, data_page);
 
    return 1;
}

void ELL_Fota_File_Get_From_Fat()
{
	S32 ret_data = 0;
    extern char ell_ram_buf[EBUFFERLENGTH];
    
    memset(ell_ram_buf, 0, EBUFFERLENGTH);
    ret_data = ell_get_data_from_file(FOTA_FILE_PATH, ell_ram_buf, EBUFFERLENGTH);
	ell_split_update(KAL_FALSE, ell_ram_buf, ret_data);
}
