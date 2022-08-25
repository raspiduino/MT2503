

#ifndef __ELL_OS_H__

#define __ELL_OS_H__

#include "MMIDataType.h"
#include "keypad_sw.h"
#include "dcl.h"
#include "Eint.h"
#include "gpio_sw.h"
#include "fs_gprot.h"
#include "c_RamBuffer.h"
#include "c_string.h"
#include "c_vector.h"
#include "custom_config_account.h"
#include "track_drv_sensor.h"
#include "track_drv_pmu.h"
#include "track_os_timer.h"
#include "mtk_gps_type.h"
#include "track_at_call.h"

extern void ELL_Funtion_Dummy(void);
extern void ell_fun_msg_send(kal_uint16 msg_id, void *req, module_type mod_src, module_type mod_dst);

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 flag;
} fake_cell_struct;

typedef int* (*ELL_REGISTER ) ( int* InFuntion , int InLength , int *size) ;
extern ELL_REGISTER ellregister ;


typedef void (*ELL_LOGDD)(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *fmt, ...);
extern ELL_LOGDD OTA_LOGDD  ;

typedef void (*ELL_LOGS)(const char *fmt, ...);
extern ELL_LOGS OTA_LOGS  ;

typedef void (*ELL_LOGHH)(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *text, void * buff, int size);
extern ELL_LOGHH OTA_LOGHH  ;


typedef kal_bool (*ELL_track_status_gpstc)(kal_uint8 flag);
extern ELL_track_status_gpstc OTA_track_status_gpstc ;

typedef void (*ELL_track_drv_gps_msg_epo_ready)(void);
extern ELL_track_drv_gps_msg_epo_ready OTA_track_drv_gps_msg_epo_ready ;

typedef void (*ELL_track_main)(void);
extern ELL_track_main OTA_track_main  ;

typedef void (*ELL_track_timer_init)(void);
extern ELL_track_timer_init OTA_track_timer_init  ;

typedef void (*ELL_track_drv_push_key_to_buff)(kbd_event event, kal_uint8 key);
extern ELL_track_drv_push_key_to_buff OTA_track_drv_push_key_to_buff  ;

typedef void (*ELL_track_drv_send_keypad_event)(void);
extern ELL_track_drv_send_keypad_event OTA_track_drv_send_keypad_event  ;


typedef void (*ELL_track_drv_charge_batter_status)(void *msg);
extern ELL_track_drv_charge_batter_status OTA_track_drv_charge_batter_status  ;


typedef void (*ELL_track_drv_charge_batter_status_msg_send)(module_type src_mod_id,kal_uint8 battery_status, kal_uint8 battery_level,kal_uint32 volt);
extern ELL_track_drv_charge_batter_status_msg_send OTA_track_drv_charge_batter_status_msg_send  ;

typedef kal_bool (*ELL_track_cmd_parse)(kal_uint8*cmd_name, void*full_cmd_string);
extern ELL_track_cmd_parse OTA_track_cmd_parse  ;

typedef void (*ELL_srv_cbm_app_bearer_info_ind_hdlr)(void *info) ;
extern ELL_srv_cbm_app_bearer_info_ind_hdlr OTA_srv_cbm_app_bearer_info_ind_hdlr  ;



typedef void (*ELL_tr_start_timer)(kal_uint16 timer_id, kal_uint32 delay, FuncPtr funcPtr) ;
extern ELL_tr_start_timer OTA_tr_start_timer  ;

typedef void (*ELL_tr_stop_timer)(kal_uint16 timer_id) ;
extern ELL_tr_stop_timer OTA_tr_stop_timer  ;

typedef BOOL (*ELL_track_is_timer_run)(kal_uint16 timer_id) ;
extern ELL_track_is_timer_run OTA_track_is_timer_run  ;

typedef void (*ELL_track_drv_sensor_interrupt_send_msg)(void);
extern ELL_track_drv_sensor_interrupt_send_msg OTA_track_drv_sensor_interrupt_send_msg  ;

extern track_sensor_config_data_struct* OTA_track_sensor_config_data;



typedef kal_uint8* (*ELL_track_drv_get_imsi)(kal_uint8 flag);
extern ELL_track_drv_get_imsi OTA_track_drv_get_imsi  ;

/***待移除***/
typedef void (*ELL_track_socket_set_apn)(custom_dtcnt_prof_gprs_struct *data);
extern ELL_track_socket_set_apn OTA_track_socket_set_apn;
/***********/


/* 无自动添加函数名 */
#define OTA_LOGC(module, grade, fmt, args...) OTA_LOGDD(module, grade, "", fmt, ##args)

/* 有自动添加函数名 */
#define OTA_LOGD(module, grade, fmt, args...) OTA_LOGDD(module, grade, __func__, fmt, ##args)


#define OTA_LOGH(module, grade, buff, size) OTA_LOGHH(module, grade, __func__, NULL, buff, size) 

typedef void (*ELL_GPS_MSG_NMEA_DECODE_REQ)(mtk_gps_position * pvt);
extern ELL_GPS_MSG_NMEA_DECODE_REQ OTA_GPS_MSG_NMEA_Decode_req  ;


typedef void (*ELL_track_at_send_data_rsq)(kal_uint8 type, kal_uint8 *data, U16 *len);
extern ELL_track_at_send_data_rsq OTA_track_at_send_data_rsq ;

typedef void (*ELL_track_at_send_msg_ind)(void);
extern ELL_track_at_send_msg_ind OTA_track_at_send_msg_ind ;

typedef kal_bool (*ELL_track_atci_at_command_buf)(kal_uint8 mode, kal_uint8 *data, kal_uint16 *len);
extern ELL_track_atci_at_command_buf OTA_track_atci_at_command_buf;

 
typedef kal_bool (*ELL_track_is_epo_long_data)(kal_uint16 leng, char* string);
extern ELL_track_is_epo_long_data OTA_track_is_epo_long_data ;

typedef void (*ELL_track_l4c_sendmsg_call_disc_release_lind)(kal_uint8 action, kal_uint8 call_id, kal_uint16 cause, kal_uint8 call_type, kal_uint8 diag);
extern ELL_track_l4c_sendmsg_call_disc_release_lind OTA_track_l4c_sendmsg_call_disc_release_lind ;


typedef void (*ELL_l4c_send_2mmi_sms_new_msg_text_lind)(kal_uint16 index,
        kal_uint16 dest_port,
        kal_uint16 src_port,
        kal_uint8 mti,
        kal_uint8 display_type,
        kal_uint8 storage_type,
        smsal_concat_struct *concat_info,
        kal_uint16 message_len,
        void *msg_header,
        void *data);
extern ELL_l4c_send_2mmi_sms_new_msg_text_lind OTA_l4c_send_2mmi_sms_new_msg_text_lind ;

typedef void (*ELL_track_l4c_cc_call_accept_req_ind)(kal_uint8 call_id);
extern ELL_track_l4c_cc_call_accept_req_ind OTA_track_l4c_cc_call_accept_req_ind ;

typedef void (*ELL_track_l4c_cc_call_connect_lind)(l4c_number_struct *num, kal_uint8 call_type, kal_uint8 call_id);
extern ELL_track_l4c_cc_call_connect_lind OTA_track_l4c_cc_call_connect_lind ;

typedef void (*ELL_track_l4c_send_msg_track_mmi)(msg_type msgtype, void * msg, void * peer_msg);
extern ELL_track_l4c_send_msg_track_mmi OTA_track_l4c_send_msg_track_mmi ;
 
typedef int (*ELL_track_cust_get_rssi)(int arg);
extern ELL_track_cust_get_rssi OTA_track_cust_get_rssi ;

typedef void (*ELL_track_l4c_cc_exe_ata_lrsp)(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_mode);
extern ELL_track_l4c_cc_exe_ata_lrsp OTA_track_l4c_cc_exe_ata_lrsp ;

typedef void (*ELL_track_l4c_cc_exe_call_setup_lrsp)(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_id);
extern ELL_track_l4c_cc_exe_call_setup_lrsp OTA_track_l4c_cc_exe_call_setup_lrsp ;

typedef void (*ELL_track_l4c_sendmsg_call_ring_ind)(l4c_number_struct* number, kal_uint8 call_type, kal_uint8 call_id);
extern ELL_track_l4c_sendmsg_call_ring_ind OTA_track_l4c_sendmsg_call_ring_ind ;

typedef kal_uint8 (*ELL_track_status_audio_mode)(kal_uint8 mode);
extern ELL_track_status_audio_mode OTA_track_status_audio_mode ;


typedef kal_bool (*ELL_track_sms_send_rsp)(kal_int8 result);
extern ELL_track_sms_send_rsp OTA_track_sms_send_rsp ;


typedef void (*ELL_track_app_main)( ilm_struct *ilm_ptr );
extern ELL_track_app_main OTA_track_app_main ;

typedef void (*ELL_track_cust_restart)(kal_uint8 mode, kal_uint32 sec);
extern ELL_track_cust_restart OTA_track_cust_restart ;

typedef kal_uint8 (*ELL_track_log_switch)(kal_uint8 onof);
extern ELL_track_log_switch OTA_track_log_switch  ;

typedef void (*ELL_track_drv_uart_ready_read)(void* msg);
extern ELL_track_drv_uart_ready_read OTA_track_drv_uart_ready_read  ;

typedef void (*ELL_track_drv_gps_epo_start)();
extern ELL_track_drv_gps_epo_start OTA_track_drv_gps_epo_start  ;

typedef void (*ELL_track_trace)(char * fmt, int size);
extern ELL_track_trace OTA_track_trace  ;

//typedef kal_uint8 (*ELL_track_fun_update_time_to_system)(kal_uint8 app, applib_time_struct *t);
//extern ELL_track_fun_update_time_to_system OTA_track_fun_update_time_to_system  ;

typedef kal_uint8 (*ELL_track_get_gps_ota)(kal_uint8 flag);
extern ELL_track_get_gps_ota OTA_track_get_gps_ota  ;
typedef kal_uint8 (*ELL_track_drv_uart_log_mode)(kal_uint8 par);
extern ELL_track_drv_uart_log_mode OTA_track_drv_uart_log_mode  ;

typedef char* (*ELL_track_fun_strncpy)(char *dec, const char *src, int size);
extern ELL_track_fun_strncpy OTA_track_fun_strncpy  ;
  
#endif

typedef void (*ELL_track_rsa_main)( ilm_struct *ilm_ptr );
extern ELL_track_rsa_main OTA_track_rsa_main ;



