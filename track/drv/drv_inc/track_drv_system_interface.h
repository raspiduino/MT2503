/******************************************************************************
 * track_drv_system_interface.h -
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

#ifndef _TRACK_DRV_SYSTEM_INTERFACK_H
#define _TRACK_DRV_SYSTEM_INTERFACK_H

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_drv.h"
#include "nvram_editor_data_item.h"

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 flag;
} fake_cell_struct;


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

extern void track_drv_sys_power_off_req(void);

extern int32 track_drv_sys_mtk_gps_set_param (kal_uint16 key, const void* value);

extern void track_drv_sys_audio_set_volume(U8 type, U8 volume);

extern kal_uint8 track_drv_sys_aud_get_volume_level(kal_uint8 mode, kal_uint8 type);

extern kal_uint8 track_drv_sys_aud_get_active_audio_mode(void);

extern void track_drv_sys_aud_send_play_id_req(void *id_param);


#endif /* _TRACK_DRV_SYSTEM_INTERFACK_H */
