/*******************************************************************************************
 * Filename:    
 * Author :     
 * Date :       
 * Comment:     
 ******************************************************************************************/
/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_at_sim.h"
#include "track_os_ell.h"
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern kal_uint8 const NVRAM_EF_IMEI_IMEISV_DEFAULT[];

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_sim_handle_senderbox(kal_timer_func_ptr read_callback);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  save_parameter_callback
 *
 *  Purpose     -  备份参数至SIM卡，返回的结果
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void save_parameter_callback(void * cb)
{
    LOGD(L_APP, L_V5, "%d", (kal_uint32)cb);

    if((kal_uint32)cb == 0)
    {
        //track_sim_handle_senderbox(test_read_callback);
    }
}

/******************************************************************************
 *  Function    -  track_cust_set_need_restore_data
 *
 *  Purpose     -  将备份的数据还原
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static kal_int32 restore_data(kal_uint8 *data, int size)
{
    kal_uint8 *tmp, *buf1;
    kal_uint16 datasize;
    int sum, ret;
    const int offset = 16 + 16 + 8;
    const int data_sum = NVRAM_EF_IMPORTANCE_PARAMETER_SIZE;

    if(size > data_sum + offset)
    {
        LOGD(L_APP, L_V2, "存储的参数可疑，不进行还原 %d", size);
        LOGH(L_APP, L_V2, data, size);
        return -1;
    }
    sum = data_sum * 2 + offset;
    buf1 = (U8*)Ram_Alloc(5, sum);
    if(buf1 == NULL)
    {
        LOGD(L_APP, L_V2, "Ram_Alloc error 2");
        return -2;
    }
    memset(buf1, 0, sum);
    
    memcpy(&datasize, data + offset, 2);
    if(datasize == 0 || datasize > data_sum + 2)
    {
        LOGD(L_APP, L_V2, "Ram_Alloc error 3, %d", datasize);
        return -3;
    }
    ret = compress_decode(buf1, data + offset + 2, datasize);
    if(ret != data_sum)
    {
        LOGH(L_APP, L_V2, data, size);
        LOGD(L_APP, L_V2, "SIM卡备份信息大小不匹配 %d", datasize);
        LOGH(L_APP, L_V2, buf1, ret);
        return -4;
    }
    else
    {
        nvram_ef_imei_imeisv_struct imei_data = {0};
        LOGD(L_APP, L_V6, "解码后得到的数据包");
        LOGH(L_APP, L_V6, buf1, ret);
        Track_nvram_read(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
        memcpy(imei_data.imei, data + 32, 8);
        Track_nvram_write(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
        memcpy(&G_importance_parameter_data, buf1, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        track_read_imei_data();
        if(track_soc_conn_valid()) track_soc_gprs_reconnect((void*)26);
        LOGD(L_APP, L_V5, "成功将SIM卡备份信息还原");
    }
    return 0;
}

/******************************************************************************
 *  Function    -  data_parameter_packet
 *
 *  Purpose     -  备份逻辑处理
 *
 *  Description -  
 *               备份数据包格式
 *               |芯片ID|Software Version|IMEI|(len)(dataBuf)|
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 02-03-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void data_parameter_packet(kal_uint8 *data, int datalen)
{
    kal_uint8 *p_imei, *p_chip_id, *buf_comp, *buf_dec, *buf_src;
    char *build_time;
    kal_int32 ret, buf_comp_size, buf_dec_size, buf_src_size;
    kal_bool backup_status = KAL_FALSE;
    nvram_ef_imei_imeisv_struct imei_data = {0};
    
    LOGD(L_APP, L_V5, "");
    Track_nvram_read(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
    p_chip_id = track_drv_get_chip_id();
    p_imei = imei_data.imei;
    build_time = (char*)build_date_time();
    LOGH(L_APP, L_V6, p_chip_id, 16);
    LOGD(L_APP, L_V4, "phone IMEI:%s", track_drv_get_imei(0));
    LOGH(L_APP, L_V6, p_imei, 8);
    while(1)
    {
        if(datalen == 0 || data == NULL)
        {
            backup_status = KAL_TRUE;
            break;
        }
        LOGH(L_APP, L_V6, data, datalen);
        if(memcmp(data, p_chip_id, 16) == 0)
        {
            LOGD(L_APP, L_V4, "chip_id 匹配！");
        }
        else
        {
            LOGD(L_APP, L_V4, "chip_id 不匹配");
            backup_status = KAL_TRUE;
            break;
        }
        if(memcmp(build_time, data + 16, 16) == 0)
        {
            LOGD(L_APP, L_V4, "Software Version 匹配！");
        }
        else
        {
            char tmp[17] = {0};
            memcpy(tmp, data + 16, 16);
            LOGD(L_APP, L_V4, "Software Version 不匹配！%s,%s", build_time, tmp);
            backup_status = KAL_TRUE;
            break;
        }
        if(memcmp(data + 16 + 16, p_imei, 8) == 0)
        {
            LOGD(L_APP, L_V4, "sim imei 和 phone imei 匹配！");
        }
        else
        {
            LOGD(L_APP, L_V4, "sim imei 和 phone imei 不匹配");
            if(memcmp(((nvram_ef_imei_imeisv_struct*)OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT)->imei, p_imei, 8) == 0)
            {
                LOGD(L_APP, L_V4, "phone IMEI为初始值，还原IMEI和主要参数");
                restore_data(data, datalen);
                return;
            }
            backup_status = KAL_TRUE;
            break;
        }
        break;
    }

    buf_comp_size = NVRAM_EF_IMPORTANCE_PARAMETER_SIZE + 100;
    buf_comp = (kal_uint8*)Ram_Alloc(5, buf_comp_size);
    if(buf_comp == NULL)
    {
        LOGD(L_APP, L_V2, "error 1");
        return;
    }
    memset(buf_comp, 0, buf_comp_size);

    buf_src_size = NVRAM_EF_IMPORTANCE_PARAMETER_SIZE;
    buf_src = (kal_uint8*)Ram_Alloc(5, buf_src_size);
    if(buf_src == NULL)
    {
        LOGD(L_APP, L_V2, "error 11");
        Ram_Free(buf_comp);
        return;
    }
    memcpy(buf_src, &G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    LOGD(L_APP, L_V6, "待编码的原始数据包");
    LOGH(L_APP, L_V6, buf_src, buf_src_size);
    ret = compress_encode(buf_comp, buf_src, buf_src_size);
    Ram_Free(buf_src);
    LOGD(L_APP, L_V6, "源数据长度:%d, 压缩后数据长度:%d", NVRAM_EF_IMPORTANCE_PARAMETER_SIZE, ret);
    if(ret > 0)
    {
        kal_uint16 datasize = ret;
        //LOGD(L_APP, L_V6, "编码后的数据");
        //LOGH(L_APP, L_V6, buf_comp, ret);
        buf_dec_size = 16/*chip id*/ + 16/*Software Version*/ + 8/*imei*/ + 2/*datasize*/ + ret;
        buf_dec = (kal_uint8*)Ram_Alloc(5, buf_dec_size);
        if(buf_dec == NULL)
        {
            LOGD(L_APP, L_V2, "error 2");
            Ram_Free(buf_comp);
            return;
        }
        memset(buf_dec, 0, buf_dec_size);
        
        memcpy(buf_dec, p_chip_id, 16);
        strncpy(buf_dec + 16, build_time, 16);
        memcpy(buf_dec + 16 + 16, p_imei, 8);
        memcpy(buf_dec + 16 + 16 + 8, &datasize, 2);
        memcpy(buf_dec + 16 + 16 + 8 + 2, buf_comp, ret);
        LOGD(L_APP, L_V6, "完整需要备份的数据 data size:%d", buf_dec_size);
        LOGH(L_APP, L_V6, buf_dec, buf_dec_size);
        if(!backup_status && datalen > 0 && data != NULL)
        {
            memcpy(&datasize, data + 16 + 16 + 8, 2);
            if(datasize == ret && memcmp(data + 16 + 16 + 8 + 2, buf_comp, ret) == 0)
            {
                LOGD(L_APP, L_V4, "parameter_data 匹配！");
            }
            else
            {
                LOGD(L_APP, L_V4, "parameter_data 不匹配, %d,%d", datasize, ret);
                backup_status = KAL_TRUE;
            }
        }
        if(backup_status)
        {
            LOGH(L_APP, L_V6, ((nvram_ef_imei_imeisv_struct*)OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT)->imei, 8);
            LOGH(L_APP, L_V6, p_imei, 8);
            if(memcmp(((nvram_ef_imei_imeisv_struct*)OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT)->imei, p_imei, 8) == 0)
            {
                LOGD(L_APP, L_V4, "IMEI为初始值，不备份");
            }
            else
            {
                ret = track_sim_backup_msg(buf_dec, buf_dec_size, save_parameter_callback);
                LOGD(L_APP, L_V4, "备份参数至SIM卡 %d", ret);
            }
        }
        Ram_Free(buf_dec);
    }
    Ram_Free(buf_comp);
}

/******************************************************************************
 *  Function    -  track_cust_sim_read_callback
 *
 *  Purpose     -  读取备份参数短信，回调函数
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void track_cust_sim_read_callback(void * cb)
{
    static kal_uint8 count = 0;
    read_msg_struct *back_ind = (read_msg_struct*)cb;

    LOGD(L_APP, L_V6, "从SIM卡备份数据中读取数据 %d", back_ind->error_msg);

    LOGH(L_APP, L_V6, back_ind->msg_ctx, back_ind->msg_len);
    if(back_ind->error_msg == 0)
    {
        data_parameter_packet(back_ind->msg_ctx, back_ind->msg_len);
        count = 0;
    }
    else if(back_ind->error_msg == -1)
    {
        data_parameter_packet(NULL, 0);
        count = 0;
    }
    else if(back_ind->error_msg == -2)
    {
        count++;
        if(count < 3)
        {
            track_sim_handle_senderbox(track_cust_sim_read_callback);
        }
        else
        {
            data_parameter_packet(NULL, 0);
            count = 0;
        }
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
/******************************************************************************
 *  Function    -  track_cust_sim_backup_for_parameter
 *
 *  Purpose     -  读取备份参数判断是否需要更新
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 20140111,  WangQi  modify
 * ----------------------------------------
*******************************************************************************/
void track_cust_sim_backup_for_parameter(void)
{
#if defined(__NVRAM_BACKUP_PARTITION__)
//不用备份到SIM，使用SDS进行备份
#else
    track_stop_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER);
    track_sim_handle_senderbox(track_cust_sim_read_callback);
#endif
    //track_sim_clean_allsms();//清空收件箱
}

/******************************************************************************
 *  Function    -  track_cust_write_sim_backup_for_parameter
 *
 *  Purpose     -  忽略已经备份的参数，写入新的参数至SIM卡
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 20140111,  WangQi  modify
 * ----------------------------------------
*******************************************************************************/
void track_cust_write_sim_backup_for_parameter(void)
{
#if defined(__NVRAM_BACKUP_PARTITION__)
    tr_start_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER, 5000, track_cust_write_sim_backup_for_parameter);
    track_cmd_send_to_nvram(NVRAM_SDS_ACCESS_BACKUP);
#else
    ///track_stop_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER);
   /// data_parameter_packet(NULL, 0);
#endif
}

