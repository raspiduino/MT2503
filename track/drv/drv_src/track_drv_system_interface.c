/******************************************************************************
 * track_drv_system_interface.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        驱动层与系统工程接口
            驱动层引用系统函数
 *
 * modification history
 * --------------------
 * v1.0   2013-7-6,  wangqi create this file
 *
 ******************************************************************************/
#include "track_drv_system_interface.h"
#include "track_os_data_types.h"
#include "uem_proc_cmd.h"
#include "track_os_ell.h"
#include "l4c_common_enum.h"
#include "soc_consts.h"
#include "c_RamBuffer.h"
/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/

/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/
extern nvram_parameter_struct G_parameter;
extern nvram_realtime_struct G_realtime_data;

/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern void track_cust_search_fake_cell(void);
extern void track_cust_fake_cell_auto_enable_detect(void);

/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/
void track_drv_sys_power_off_req(void)
{
    l4cuem_power_off_req();
}

int32 track_drv_sys_mtk_gps_set_param (kal_uint16 key, const void* value)
{
#if defined __GPS_MT3333__
    return track_drv_gps_set_param(key, value);
#endif
    return 0;
}


void track_drv_sys_audio_set_volume(kal_uint8 volume_type, kal_uint8 volume_level)
{
    LOGD(L_DRV, L_V5, "type:%d, level:%d", volume_type, volume_level);
    l4cuem_audio_set_volume_req( volume_type,  volume_level);
}

void track_drv_sys_l4cuem_set_audio_mode(kal_uint8 mode)
{
    if(mode == 2)
    {
        LOGD(L_DRV, L_V2, "==mode:%d 免提模式==\r\n", mode);
    }
    else
    {
        LOGD(L_DRV, L_V2, "==mode:%d 非免提模式==\r\n", mode);
    }

    track_status_audio_mode(mode);
    l4cuem_set_audio_mode( mode);
    //aud_send_set_audio_mode_req(mode);
}

kal_uint8 track_drv_sys_aud_get_volume_level(kal_uint8 mode, kal_uint8 type)
{
    return aud_get_volume_level( mode,  type);
}

kal_uint8 track_drv_sys_aud_get_active_audio_mode(void)
{
    return aud_get_active_audio_mode();
}

void track_drv_sys_aud_send_play_id_req(void *id_param)
{
    aud_send_play_id_req(id_param);
}

void track_drv_sys_aud_send_play_string_req(void *string_param)
{
    aud_send_play_string_req(string_param);
}

void track_drv_sys_aud_send_stop_string_req(kal_uint8 src_id)
{
    aud_send_stop_string_req(src_id);
}

/*
AT+CFUN=0 turn off radio and SIM power
AT+CFUN=1,1 or AT+CFUN=4,1 can reset the target
AT+CFUN=1 cna enter normal mode
AT+CFUN=4 can enter flight mode.(supported only for module solution)
*/
void track_drv_sys_cfun(kal_uint8 opt)
{
    if(opt != 0 && opt != 1 && opt != 4) 
    {
        LOGS("error opt:%d",opt);
        return;
    }
    if(opt == 0 || opt == 4)
    {
        int i;
        for(i=0; i < MAX_IP_SOCKET_NUM; i++)
        {
            soc_close(i);
        }
    }
    l4c_nw_cfun_state_req(RMMI_SRC, opt);
}

#if defined (__CUST_FAKECELL__)
void track_drv_sys_init_fake_cell(void)
{
    if(G_parameter.fake_cell_enable != 0)
    {
        if(G_parameter.fake_cell_auto_temp == 0)
        {
            OTA_track_custom_fake_cell_feature_enable(0);
            tr_start_timer(TRACK_CUST_FAKECELL_DISABLE_AUTO_RESUME_TIMER_ID, 10000, track_cust_fake_cell_auto_enable_detect);
            LOGD(L_DRV, L_V2, "指令开防伪功能，但上次报警且静止关闭，本次关闭防伪，10秒后运动再恢复打开");
        }
        else
        {
            OTA_track_custom_fake_cell_feature_enable(1);
        }
    }
    else
    {
        OTA_track_custom_fake_cell_feature_enable(0);
    }
}

    
/******************************************************************************
 *  Function    -  track_drv_fake_cell_hdlr
 * 
 *  Purpose     -  伪基站信号变化处理
 * 
 *  Description -  搜到伪基站信息，大概2-5秒输出一次，参数arfcn为频点
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-08-31,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_fake_cell_hdlr(void *msg)
{
    kal_uint16 arfcn;
    fake_cell_struct *localBuff_p = (fake_cell_struct*)msg;
    static kal_bool first = KAL_TRUE;
    arfcn=localBuff_p->flag;
    LOGD(L_DRV, L_V2, "伪基站信息 %d",arfcn);

    //每个项目收到伪基站提示后处理不同，分别处理
    track_cust_search_fake_cell(); 
    
#if 0
    if(first)
    {
		char ams_buf[50]={0};
		sprintf(ams_buf, "(Pseudo base station)(%d) ", RUNING_TIME_SEC);
		track_cust_cache_netlink(ams_buf, strlen(ams_buf));
		first=KAL_FALSE;
	}
#endif
}

#else
void track_drv_sys_init_fake_cell(void)
{}

void track_drv_fake_cell_hdlr(void *msg)
{}
    
#endif /* __CUST_FAKECELL__ */

