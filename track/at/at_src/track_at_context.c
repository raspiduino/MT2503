/******************************************************************************
 * track_context.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        
 *
 * modification history
 * --------------------
 * v1.0   2013-01-11,  WangQi create this file
 *
 ******************************************************************************/
#include "as2l4c_struct.h"

#include "track_os_data_types.h"

#include "track_at_context.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/

#define  TRACK_AUDIO_MODE_DEFAULT   2   //免提通道

/************************************************************************
************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static gps_runtime_evn_struct GRE = {0};
/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
kal_bool track_status_gpstctest(kal_uint8 flag)
{
    if(flag == 0 || flag == 1)
    {
        GRE.GPS_Pass_state = (kal_bool)flag;
    }
    return GRE.GPS_Pass_state;
}
kal_bool track_status_gpstc(kal_uint8 flag)
{
    if(flag == 0 || flag == 1)
    {
        GRE.GPS_Pass_state = (kal_bool)flag;
    }

    return  GRE.GPS_Pass_state;
}

kal_bool track_status_test(kal_uint8 flag)
{
    if(flag == 0 || flag == 1)
    {
        GRE.PhoneTestMode = (kal_bool)flag;
    }
    return  GRE.PhoneTestMode;
}

kal_bool track_status_notquit(kal_uint8 flag)
{
    if(flag == 0 || flag == 1)
    {
        GRE.notquit = (kal_bool)flag;
    }
    return  GRE.notquit;
}
kal_bool track_is_notquit(void)
{
    return track_status_notquit(2);
}
kal_uint8 track_status_audio_mode(kal_uint8 mode)
{
    char ear_status = 0;
    if( mode < 3 )
    {
        GRE.audio_mode = mode;
    }
    else if(GRE.audio_mode > 2 || mode == 0xFE)
    {
#if defined(__NT36__)
        ear_status = GPIO_ReadIO(52);//AUX Eint23
        LOGD(L_DRV, L_V5, "Ear Status:%d", ear_status);
        if(ear_status == 0)
            return 1;
        else
            return 2;
#endif /* __GT06FF__ */
        return (kal_uint8) TRACK_AUDIO_MODE_DEFAULT;
    }
     
    return GRE.audio_mode;
}

void track_set_rssi_by_l4_ind(void * msg)
{
    l4cps_gas_cell_power_level_ind_struct *ptr = (l4cps_gas_cell_power_level_ind_struct *) msg;
    LOGD(L_CMD, L_V5, "===rssi_in_qdbm:%d, current_band:%d, ber:%d", ptr->rssi_in_qdbm, ptr->current_band, ptr->ber);
    track_cust_get_rssi(ptr->rssi_in_qdbm);
    
#if defined( __OLED__)
    track_cust_lcd_updata_gsm(track_translate_gsm_4level(ptr->rssi_in_qdbm));
#endif /* __OLED__ */
}

