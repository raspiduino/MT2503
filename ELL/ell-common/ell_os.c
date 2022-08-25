
#include "ell_os.h"
#include "mtk_gps_type.h"


void ELL_Funtion_Dummy(void)
{
}

void ell_fun_msg_send(kal_uint16 msg_id, void *req, module_type mod_src, module_type mod_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = (ilm_struct *)allocate_ilm(mod_src);
    ilm_send->src_mod_id = mod_src;
    ilm_send->dest_mod_id = (module_type)mod_dst;
    ilm_send->sap_id = INVALID_SAP;
    ilm_send->msg_id = (msg_type) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) req;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_send);
}

ELL_REGISTER ellregister = ELL_Funtion_Dummy ;


track_sensor_config_data_struct* OTA_track_sensor_config_data = 0;


void OTA_LOGDD_dummy( enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *fmt, ...)
{
}
ELL_LOGDD OTA_LOGDD = OTA_LOGDD_dummy ;

void OTA_LOGS_dummy(const char *fmt, ...)
{
}

void OTA_LOGHH_dummy(enum_LOG_MODULE module, enum_LOG_LEVEL grade, const char *fun_name, const char *text, void * buff, int size)
{
}
ELL_LOGHH OTA_LOGHH = OTA_LOGHH_dummy ;


ELL_LOGS OTA_LOGS = OTA_LOGS_dummy ;


ELL_track_status_gpstc OTA_track_status_gpstc = ELL_Funtion_Dummy ;


ELL_track_drv_gps_msg_epo_ready OTA_track_drv_gps_msg_epo_ready = ELL_Funtion_Dummy ;

ELL_track_timer_init OTA_track_timer_init = ELL_Funtion_Dummy ;
ELL_track_main OTA_track_main = ELL_Funtion_Dummy ;


ELL_track_drv_send_keypad_event OTA_track_drv_send_keypad_event = ELL_Funtion_Dummy ;
ELL_track_drv_push_key_to_buff OTA_track_drv_push_key_to_buff = ELL_Funtion_Dummy ;




void ELL_Funtion_Dummy_Msg(ilm_struct *ilm_ptr)
{
}

ELL_track_drv_charge_batter_status OTA_track_drv_charge_batter_status = ELL_Funtion_Dummy_Msg ;


ELL_srv_cbm_app_bearer_info_ind_hdlr OTA_srv_cbm_app_bearer_info_ind_hdlr = ELL_Funtion_Dummy_Msg ;






ELL_track_drv_get_imsi OTA_track_drv_get_imsi = 0 ;
ELL_track_socket_set_apn OTA_track_socket_set_apn = 0;

ELL_track_cmd_parse OTA_track_cmd_parse = ELL_Funtion_Dummy ;



ELL_tr_start_timer OTA_tr_start_timer = ELL_Funtion_Dummy ;
ELL_tr_stop_timer OTA_tr_stop_timer = ELL_Funtion_Dummy ;
ELL_track_is_timer_run OTA_track_is_timer_run = ELL_Funtion_Dummy ;
ELL_track_drv_sensor_interrupt_send_msg OTA_track_drv_sensor_interrupt_send_msg = ELL_Funtion_Dummy ; 

void ELL_track_drv_charge_batter_status_msg_send_Dummy(module_type src_mod_id, kal_uint8 battery_status, kal_uint8 battery_level, kal_uint32 volt){}
ELL_track_drv_charge_batter_status_msg_send OTA_track_drv_charge_batter_status_msg_send = ELL_track_drv_charge_batter_status_msg_send_Dummy ;

void GPS_MSG_NMEA_Decode_req_Dummy(mtk_gps_position * pvt)
{
}
ELL_GPS_MSG_NMEA_DECODE_REQ OTA_GPS_MSG_NMEA_Decode_req = GPS_MSG_NMEA_Decode_req_Dummy ;


void ELL_Funtion_Dummy_atdata_rsq(kal_uint8 type, kal_uint8 *data, U16 *len)
{
}
ELL_track_at_send_data_rsq OTA_track_at_send_data_rsq = ELL_Funtion_Dummy_atdata_rsq ;

ELL_track_at_send_msg_ind OTA_track_at_send_msg_ind = ELL_Funtion_Dummy ;

kal_bool ELL_Funtion_Dummy_at_command_buf(kal_uint8 mode, kal_uint8 *data, kal_uint16 *len)
{
	return TRUE;
}
ELL_track_atci_at_command_buf OTA_track_atci_at_command_buf = ELL_Funtion_Dummy_at_command_buf ;


kal_bool ELL_Funtion_Dummy_epo_data(kal_uint16 leng, char* string)
{
	return TRUE;
}
ELL_track_is_epo_long_data OTA_track_is_epo_long_data = ELL_Funtion_Dummy_epo_data ;


void ELL_Funtion_Dummy_call_lind(kal_uint8 action, kal_uint8 call_id, kal_uint16 cause, kal_uint8 call_type, kal_uint8 diag)
{
}
ELL_track_l4c_sendmsg_call_disc_release_lind OTA_track_l4c_sendmsg_call_disc_release_lind = ELL_Funtion_Dummy_call_lind ;

void ELL_Funtion_Dummy_l4c_lind(kal_uint16 index,
        kal_uint16 dest_port,
        kal_uint16 src_port,
        kal_uint8 mti,
        kal_uint8 display_type,
        kal_uint8 storage_type,
        smsal_concat_struct *concat_info,
        kal_uint16 message_len,
        void *msg_header,
        void *data)
{
}
ELL_l4c_send_2mmi_sms_new_msg_text_lind OTA_l4c_send_2mmi_sms_new_msg_text_lind = ELL_Funtion_Dummy_l4c_lind ;

void ELL_Funtion_Dummy_call1_ind(kal_uint8 call_id)
{
}
ELL_track_l4c_cc_call_accept_req_ind OTA_track_l4c_cc_call_accept_req_ind = ELL_Funtion_Dummy_call1_ind ;

void ELL_Funtion_Dummy_call_connect_lind(l4c_number_struct *num, kal_uint8 call_type, kal_uint8 call_id)
{
}
ELL_track_l4c_cc_call_connect_lind OTA_track_l4c_cc_call_connect_lind = ELL_Funtion_Dummy_call_connect_lind ;

void ELL_Funtion_Dummy_send_msg(msg_type msgtype, void * msg, void * peer_msg)
{
}
ELL_track_l4c_send_msg_track_mmi OTA_track_l4c_send_msg_track_mmi = ELL_Funtion_Dummy_send_msg ;

int ELL_Funtion_Dummy_rssi(int arg)
{
	return 0;
}
ELL_track_cust_get_rssi OTA_track_cust_get_rssi = ELL_Funtion_Dummy_rssi ;

void ELL_Funtion_Dummy_ata_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_mode)
{
}
ELL_track_l4c_cc_exe_ata_lrsp OTA_track_l4c_cc_exe_ata_lrsp = ELL_Funtion_Dummy_ata_lrsp ;

void ELL_Funtion_Dummy_setup_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_id)
{
}
ELL_track_l4c_cc_exe_call_setup_lrsp OTA_track_l4c_cc_exe_call_setup_lrsp = ELL_Funtion_Dummy_setup_lrsp;

void ELL_Funtion_Dummy_ring_ind(l4c_number_struct* number, kal_uint8 call_type, kal_uint8 call_id)
{
}
ELL_track_l4c_sendmsg_call_ring_ind OTA_track_l4c_sendmsg_call_ring_ind = ELL_Funtion_Dummy_ring_ind;

kal_uint8 ELL_Funtion_Dummy_audioMode(kal_uint8 mode){return 0;}
ELL_track_status_audio_mode OTA_track_status_audio_mode = ELL_Funtion_Dummy_audioMode;

kal_bool ELL_track_sms_send_rsp_Dummy(kal_int8 result){return 0;}
ELL_track_sms_send_rsp OTA_track_sms_send_rsp = ELL_track_sms_send_rsp_Dummy;

void track_app_main_dummy( ilm_struct *ilm_ptr ){}
ELL_track_app_main OTA_track_app_main = track_app_main_dummy ;
    

void track_cust_restart_dummy(kal_uint8 mode, kal_uint32 sec){}
ELL_track_cust_restart OTA_track_cust_restart = track_cust_restart_dummy ;

kal_uint8 track_log_switch_dummy(kal_uint8 onof){return 0;}
ELL_track_log_switch OTA_track_log_switch = track_log_switch_dummy ;

void track_drv_uart_ready_read_dummy(void *msg){}
ELL_track_drv_uart_ready_read OTA_track_drv_uart_ready_read= track_drv_uart_ready_read_dummy ;

void track_drv_gps_epo_start_dummy(void *msg){}
ELL_track_drv_gps_epo_start OTA_track_drv_gps_epo_start= track_drv_gps_epo_start_dummy ;

void track_trace_dummy(char * fmt, int size){}
ELL_track_trace OTA_track_trace= track_trace_dummy ;

//kal_uint8 track_fun_update_time_to_system_dummy(kal_uint8 app, applib_time_struct *t){}
//ELL_track_fun_update_time_to_system OTA_track_fun_update_time_to_system= track_fun_update_time_to_system_dummy ;

kal_uint8 track_get_gps_ota_dummy(kal_uint8 flag){}
ELL_track_get_gps_ota OTA_track_get_gps_ota= track_get_gps_ota_dummy ;
kal_uint8 track_drv_uart_log_mode_dummy(kal_uint8 par){}
ELL_track_drv_uart_log_mode OTA_track_drv_uart_log_mode= track_drv_uart_log_mode_dummy ;


char* track_fun_strncpy_dummy(char *dec, const char *src, int size){}
ELL_track_fun_strncpy OTA_track_fun_strncpy = track_fun_strncpy_dummy ;

void track_rsa_main_dummy( ilm_struct *ilm_ptr ){}
ELL_track_rsa_main OTA_track_rsa_main = track_rsa_main_dummy ;

