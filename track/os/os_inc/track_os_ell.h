

#ifndef __TRACK_OS_ELL_H__

#define __TRACK_OS_ELL_H__
#include "kal_public_defs.h"
#include <math.h>
#include "fs_gprot.h"
#include "dcl.h"
#include "soc_api.h"
#include "rtc_sw_new.h"
#include "Conversions.h"
#include "app_datetime.h"
#include "mtk_gps_type.h"
#include "cbm_api.h"
#include "nvram_editor_data_item.h"
#include "uem_context.h"

#include "track_os_data_types.h"
#include "track_drv_sensor.h"
#include "track_os_timer.h"
#include "track_drv_pmu.h"
//#include "app_md5.h"
#include "flash_disk_internal.h"
#include "custom_config_account.h"
#include "l1audio.h"
typedef void (*ELL_LOG)(const char* fun_name, const char* message , ... );

extern ELL_LOG OTA_log2 ;

#define OTA_log(fmt, args...) OTA_log2(__func__, fmt, ##args)

typedef event_scheduler* (*ELL_evshed_create)(kal_char *evshed_name, module_type module_id,kal_uint32 allowed_time_shift, kal_uint16 allowed_time_shift_sleep_mode);
extern ELL_evshed_create OTA_evshed_create;

typedef kal_int32 (*ELL_evshed_cancel_event)(event_scheduler *es, eventid *eid);
extern ELL_evshed_cancel_event OTA_evshed_cancel_event ;

typedef eventid (*ELL_evshed_set_event)(event_scheduler *es,kal_timer_func_ptr event_hf,void *event_hf_param,kal_uint32 elapse_time);
extern ELL_evshed_set_event OTA_evshed_set_event ;

typedef void (*ELL_evshed_timer_handler)(event_scheduler *es);
extern ELL_evshed_timer_handler OTA_evshed_timer_handler ;



typedef int (*ELL_FS_Close)(FS_HANDLE File);
extern ELL_FS_Close OTA_FS_Close ;

typedef int (*ELL_FS_Commit)(FS_HANDLE File);
extern ELL_FS_Commit OTA_FS_Commit ;

typedef int (*ELL_FS_CreateDir)(const WCHAR * DirName);
extern ELL_FS_CreateDir OTA_FS_CreateDir ;

typedef int (*ELL_FS_Delete)(const WCHAR * FileName);
extern ELL_FS_Delete OTA_FS_Delete ;

typedef int (*ELL_FS_Rename)(const WCHAR * FileName, const WCHAR * NewName);
extern ELL_FS_Rename OTA_FS_Rename;

typedef int (*ELL_FS_FindFirst)(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);
extern ELL_FS_FindFirst OTA_FS_FindFirst ;

typedef int (*ELL_FS_FindNext)(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);
extern ELL_FS_FindNext OTA_FS_FindNext ;

typedef int (*ELL_FS_GetDrive)(UINT Type, UINT Serial, UINT AltMask);
extern ELL_FS_GetDrive OTA_FS_GetDrive ;

typedef int (*ELL_FS_GetFileSize)(FS_HANDLE FileHandle, kal_uint32 * Size);
extern ELL_FS_GetFileSize OTA_FS_GetFileSize ;

typedef int (*ELL_FS_GetFolderSize)(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
extern ELL_FS_GetFolderSize OTA_FS_GetFolderSize ;

typedef int (*ELL_FS_Open)(const WCHAR * FileName, UINT Flag);
extern ELL_FS_Open OTA_FS_Open ;

typedef int (*ELL_FS_Seek)(FS_HANDLE FileHandle, int Offset, int Whence);
extern ELL_FS_Seek OTA_FS_Seek ;

typedef int (*ELL_FS_Write)(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written);
extern ELL_FS_Write OTA_FS_Write ;

typedef int (*ELL_FS_Read)(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read);
extern ELL_FS_Read OTA_FS_Read ;

typedef int (*ELL_FS_XDelete)(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
extern ELL_FS_XDelete OTA_FS_XDelete ;

typedef int (*ELL_FS_GeneralFormat)(const WCHAR * DriveName, UINT Level, FS_FormatCallback Progress);
extern ELL_FS_GeneralFormat OTA_FS_GeneralFormat ;

typedef int (*ELL_FS_GetDiskInfo)(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags);
extern ELL_FS_GetDiskInfo OTA_FS_GetDiskInfo ;


typedef void ( *ELL_GPIO_InitIO )(char direction, char port);
extern ELL_GPIO_InitIO OTA_GPIO_InitIO ;

typedef void (*ELL_GPIO_ModeSetup)(kal_uint16 pin, kal_uint16 conf_dada);
extern ELL_GPIO_ModeSetup OTA_GPIO_ModeSetup ;

typedef char ( *ELL_GPIO_ReadIO )(char port);
extern ELL_GPIO_ReadIO OTA_GPIO_ReadIO ;

typedef char ( *ELL_GPIO_ReturnDout )(char port);
extern ELL_GPIO_ReturnDout OTA_GPIO_ReturnDout ;

typedef void ( *ELL_GPIO_WriteIO )(char data,char port);
extern ELL_GPIO_WriteIO OTA_GPIO_WriteIO ;

 

typedef DCL_STATUS ( *ELL_DclPMU_Close )(DCL_HANDLE handle);
extern ELL_DclPMU_Close OTA_DclPMU_Close ;

typedef DCL_STATUS ( *ELL_DclPMU_Control )(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern ELL_DclPMU_Control OTA_DclPMU_Control ;

typedef DCL_HANDLE ( *ELL_DclPMU_Open )(DCL_DEV dev, DCL_FLAGS flags);
extern ELL_DclPMU_Open OTA_DclPMU_Open ;



typedef void ( *ELL_EINT_Mask )(kal_uint8 eintno);
extern ELL_EINT_Mask OTA_EINT_Mask ;

typedef void ( *ELL_EINT_Registration )(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_lisr)(void), kal_bool auto_umask);
extern ELL_EINT_Registration OTA_EINT_Registration ;

typedef kal_int32 ( *ELL_EINT_SW_Debounce_Modify )(kal_uint8 eintno, kal_uint8 debounce_time);
extern ELL_EINT_SW_Debounce_Modify OTA_EINT_SW_Debounce_Modify ;

typedef kal_uint32 ( *ELL_EINT_Set_Sensitivity )(kal_uint8 eintno, kal_bool sens);
extern ELL_EINT_Set_Sensitivity OTA_EINT_Set_Sensitivity ;

typedef void ( *ELL_EINT_Set_Polarity )(kal_uint8 eintno, kal_bool ACT_Polarity);
extern ELL_EINT_Set_Polarity OTA_EINT_Set_Polarity ;

typedef void ( *ELL_EINT_UnMask )(kal_uint8 eintno);
extern ELL_EINT_UnMask OTA_EINT_UnMask ;



typedef DCL_STATUS ( *ELL_DclSerialPort_Control )(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern ELL_DclSerialPort_Control OTA_DclSerialPort_Control ;

typedef DCL_HANDLE ( *ELL_DclSerialPort_Open )(DCL_DEV dev, DCL_FLAGS flags);
extern ELL_DclSerialPort_Open OTA_DclSerialPort_Open ;

typedef DCL_STATUS ( *ELL_DclSerialPort_Close )(DCL_HANDLE handle);
extern ELL_DclSerialPort_Close OTA_DclSerialPort_Close ;


typedef void* ( *ELL_kal_adm_alloc_1 )(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line);
extern ELL_kal_adm_alloc_1 OTA_kal_adm_alloc_1 ;
#define kal_adm_alloc(adm_id, size) OTA_kal_adm_alloc_1((adm_id), (size), NULL, 0, __FILE__, __LINE__)

typedef KAL_ADM_ID ( *ELL_kal_adm_create2 )(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_uint32 flags, kal_int8 extheader_size_in_word);
extern ELL_kal_adm_create2 OTA_kal_adm_create2 ;
#define kal_adm_create(mem_addr, size, subpool_size, islogging) OTA_kal_adm_create2((mem_addr), (size), (subpool_size), (kal_uint32)islogging, 0)

typedef kal_status ( *ELL_kal_adm_delete )(KAL_ADM_ID adm_id);
extern ELL_kal_adm_delete OTA_kal_adm_delete ;

typedef void ( *ELL_kal_adm_free )(KAL_ADM_ID adm_id, void *mem_addr);
extern ELL_kal_adm_free OTA_kal_adm_free ;

typedef kal_uint32 ( *ELL_kal_adm_get_max_alloc_size )(KAL_ADM_ID adm_id);
extern ELL_kal_adm_get_max_alloc_size OTA_kal_adm_get_max_alloc_size ;

typedef kal_uint32 ( *ELL_kal_adm_get_total_left_size )(KAL_ADM_ID adm_id);
extern ELL_kal_adm_get_total_left_size OTA_kal_adm_get_total_left_size ;



typedef void ( *ELL_ASSERT )(int const expr);
extern ELL_ASSERT OTA_ASSERT ;


typedef kal_mutexid ( *ELL_kal_create_mutex )(kal_char* mutex_name_ptr);
extern ELL_kal_create_mutex OTA_kal_create_mutex ;

typedef void ( *ELL_kal_take_mutex )(kal_mutexid mutex_id);
extern ELL_kal_take_mutex OTA_kal_take_mutex ;

typedef void ( *ELL_kal_give_mutex )(kal_mutexid mutex_id);
extern ELL_kal_give_mutex OTA_kal_give_mutex ;



typedef kal_int8 ( *ELL_soc_close )(kal_int8 s);
extern ELL_soc_close OTA_soc_close ;
typedef kal_int8 ( *ELL_soc_connect )(kal_int8 s, sockaddr_struct *addr);
extern ELL_soc_connect OTA_soc_connect ;
typedef kal_int8 ( *ELL_soc_create )(kal_uint8 domain, socket_type_enum type, kal_uint8 protocol, module_type mod_id,kal_uint32 nwk_account_id);
extern ELL_soc_create OTA_soc_create ;
typedef kal_int8 ( *ELL_soc_gethostbyname )(kal_bool is_blocking,module_type mod_id,kal_int32 request_id,const kal_char  *domain_name,kal_uint8 *addr,kal_uint8 *addr_len,kal_uint8 access_id,kal_uint32 nwk_account_id);
extern ELL_soc_gethostbyname OTA_soc_gethostbyname ;
typedef kal_int8 ( *ELL_soc_getsockopt )(kal_int8   s,kal_uint32 option,void       *val,kal_uint8  val_size);
extern ELL_soc_getsockopt OTA_soc_getsockopt ;
typedef kal_int32 ( *ELL_soc_recv )(kal_int8  s,void *buf,kal_int32 len,kal_uint8 flags);
extern ELL_soc_recv OTA_soc_recv ;
typedef kal_int32 ( *ELL_soc_send )(kal_int8	 s,const void *buf,kal_int32  len,kal_uint8	 flags);
extern ELL_soc_send OTA_soc_send ;
typedef kal_int32 (*ELL_soc_sendto)(kal_int8 s, const void *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *addr);
extern ELL_soc_sendto OTA_soc_sendto;
typedef kal_int32 (*ELL_soc_recvfrom)(kal_int8 s, void *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *fromaddr);
extern ELL_soc_recvfrom OTA_soc_recvfrom;
typedef kal_int8 ( *ELL_soc_setsockopt )(kal_int8   s,kal_uint32 option,void       *val,kal_uint8  val_size);
extern ELL_soc_setsockopt OTA_soc_setsockopt ;
typedef kal_uint32 ( *ELL_cbm_encode_data_account_id )(kal_uint32 acct_id, cbm_sim_id_enum sim_id, kal_uint8 app_id, kal_bool always_ask);
extern ELL_cbm_encode_data_account_id OTA_cbm_encode_data_account_id ;
typedef kal_uint8 ( *ELL_cbm_get_app_id )(kal_uint32 acct_id);
extern ELL_cbm_get_app_id OTA_cbm_get_app_id ;
typedef kal_uint8 ( *ELL_cbm_register_app_id_with_app_info )(cbm_app_info_struct *info,kal_uint8 *app_id);
extern ELL_cbm_register_app_id_with_app_info OTA_cbm_register_app_id_with_app_info ;




typedef void ( *ELL_kal_cancel_timer )(kal_timerid timer_ptr);
extern ELL_kal_cancel_timer OTA_kal_cancel_timer ;
typedef kal_timerid ( *ELL_kal_create_timer )(kal_char* timer_name_ptr);
extern ELL_kal_create_timer OTA_kal_create_timer ;
typedef void ( *ELL_kal_set_timer )(kal_timerid timer_id, kal_timer_func_ptr handler_func_ptr, void* handler_param_ptr, kal_uint32 delay, kal_uint32 reschedule_time);
extern ELL_kal_set_timer OTA_kal_set_timer ;




/***´ýÉ¾³ý***/
typedef kal_bool ( *ELL_track_net_apn_set )(void);
extern ELL_track_net_apn_set OTA_track_net_apn_set ;
/***********/

typedef track_custom_gprs_apn_struct* ( *ELL_track_net_get_apn )(char *imsi);
extern ELL_track_net_get_apn OTA_track_net_get_apn ;




typedef ilm_struct* ( *ELL_allocate_ilm )(module_type module_id);
extern ELL_allocate_ilm OTA_allocate_ilm ;
typedef void* ( *ELL_construct_int_local_para_1 )(kal_uint16 local_para_size, kal_uint32 auto_reset,kal_char* file_ptr, kal_uint32 line);
extern ELL_construct_int_local_para_1 OTA_construct_int_local_para_1 ;
#define construct_local_para(local_para_size, direction) OTA_construct_int_local_para_1(local_para_size, ((kal_uint32)(direction) & (kal_uint32)TD_RESET)? 1 : 0, __FILE__, __LINE__)
typedef kal_bool ( *ELL_msg_send_ext_queue )(ilm_struct *ilm_ptr);
extern ELL_msg_send_ext_queue OTA_msg_send_ext_queue ;



typedef kal_char* ( *ELL_build_date_time )(void);
extern ELL_build_date_time OTA_build_date_time ;
typedef kal_char* ( *ELL_release_verno )(void);
extern ELL_release_verno OTA_release_verno ;
typedef void ( *ELL_U_PutUARTBytes )(UART_PORT port, kal_uint8 *data,kal_uint16 len);
extern ELL_U_PutUARTBytes OTA_U_PutUARTBytes ;
typedef kal_int32 ( *ELL_app_ucs2_strlen )(const kal_int8 *arrOut);
extern ELL_app_ucs2_strlen OTA_app_ucs2_strlen ;
typedef void ( *ELL_applib_dt_get_rtc_time )(applib_time_struct *t);
extern ELL_applib_dt_get_rtc_time OTA_applib_dt_get_rtc_time ;
typedef kal_uint32 ( *ELL_applib_get_time_difference_ext_in_second )(applib_time_struct *t1,applib_time_struct *t2);
extern ELL_applib_get_time_difference_ext_in_second OTA_applib_get_time_difference_ext_in_second ;
typedef kal_uint16 ( *ELL_app_asc_str_n_to_ucs2_str )(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len);
extern ELL_app_asc_str_n_to_ucs2_str OTA_app_asc_str_n_to_ucs2_str ;
typedef kal_uint16 ( *ELL_app_ucs2_str_n_to_asc_str )(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len);
extern ELL_app_ucs2_str_n_to_asc_str OTA_app_ucs2_str_n_to_asc_str ;
typedef kal_int32 ( *ELL_mmi_chset_convert_ex ) ( mmi_chset_enum src_type,mmi_chset_enum dest_type,char *src_buff,char *dest_buff,kal_int32 dest_size,kal_uint32 *src_end_pos);
extern ELL_mmi_chset_convert_ex OTA_mmi_chset_convert_ex ;
typedef void ( *ELL_mtk_gps_sys_storage_clear ) ( void );
extern ELL_mtk_gps_sys_storage_clear OTA_mtk_gps_sys_storage_clear ;
typedef sim_card_status_enum ( *ELL_check_sim_card_status ) ( void );
extern ELL_check_sim_card_status OTA_check_sim_card_status ;



typedef kal_int8* ( *ELL_app_ucs2_strcat )(kal_int8 *strDestination, const kal_int8 *strSource);
extern ELL_app_ucs2_strcat OTA_app_ucs2_strcat ;
typedef kal_int8* ( *ELL_app_ucs2_strcpy )(kal_int8 *strDestination, const kal_int8 *strSource);
extern ELL_app_ucs2_strcpy OTA_app_ucs2_strcpy ;
typedef void( *ELL_applib_dt_decrease_time )( applib_time_struct *timeToDecrement,applib_time_struct *decrement,applib_time_struct *Result);
extern ELL_applib_dt_decrease_time OTA_applib_dt_decrease_time ;
typedef void( *ELL_applib_dt_increase_time )(applib_time_struct *timeToIncrement,applib_time_struct *increment,applib_time_struct *Result);
extern ELL_applib_dt_increase_time OTA_applib_dt_increase_time ;
typedef void( *ELL_uem_drv_power_on )(void);
extern ELL_uem_drv_power_on OTA_uem_drv_power_on ;
typedef void( *ELL_uem_drv_power_off )(void);
extern ELL_uem_drv_power_off OTA_uem_drv_power_off ;
typedef void( *ELL_L1SM_SleepEnable )( kal_uint8 handle );
extern ELL_L1SM_SleepEnable OTA_L1SM_SleepEnable ;
typedef void( *ELL_L1SM_SleepDisable )( kal_uint8 handle );
extern ELL_L1SM_SleepDisable OTA_L1SM_SleepDisable ;
typedef mtk_int32( *ELL_mtk_gps_set_param )(mtk_gps_param key, const void* value);
extern ELL_mtk_gps_set_param OTA_mtk_gps_set_param ;
typedef mtk_int32( *ELL_mtk_gps_get_param )(mtk_gps_param key, void* value);
extern ELL_mtk_gps_get_param OTA_mtk_gps_get_param ;
typedef void( *ELL_kal_prompt_trace )(module_type mod_id, const kal_char *fmt,...);
extern ELL_kal_prompt_trace OTA_kal_prompt_trace ;


typedef void( *ELL_l4csmu_get_imsi )(kal_uint8 *imsi_data);
extern ELL_l4csmu_get_imsi OTA_l4csmu_get_imsi ;


typedef void( *ELL_track_sensor_bma250_off )(void);
extern ELL_track_sensor_bma250_off OTA_track_sensor_bma250_off ;
typedef void( *ELL_track_sensor_bma250_on )(kal_uint8 threshold , FuncPtr callback);
extern ELL_track_sensor_bma250_on OTA_track_sensor_bma250_on;
typedef kal_int8( *ELL_track_sensor_bma250_type_check )(void);
extern ELL_track_sensor_bma250_type_check OTA_track_sensor_bma250_type_check ;

typedef void( *ELL_track_sensor_kxtj31057_off )(void);
extern ELL_track_sensor_kxtj31057_off OTA_track_sensor_kxtj31057_off ;
typedef void( *ELL_track_sensor_kxtj31057_on )(kal_uint8 threshold , FuncPtr callback);
extern ELL_track_sensor_kxtj31057_on OTA_track_sensor_kxtj31057_on;
typedef kal_int8( *ELL_track_sensor_kxtj31057_type_check )(void);
extern ELL_track_sensor_kxtj31057_type_check OTA_track_sensor_kxtj31057_type_check ;

typedef void( *ELL_track_sensor_sc7a20_off )(void);
extern ELL_track_sensor_sc7a20_off OTA_track_sensor_sc7a20_off ;
typedef void( *ELL_track_sensor_sc7a20_on )(kal_uint8 threshold , FuncPtr callback);
extern ELL_track_sensor_sc7a20_on OTA_track_sensor_sc7a20_on;
typedef kal_int8( *ELL_track_sensor_sc7a20_type_check )(void);
extern ELL_track_sensor_sc7a20_type_check OTA_track_sensor_sc7a20_type_check ;

typedef void( *ELL_track_sensor_da213_off )(void);
extern ELL_track_sensor_da213_off OTA_track_sensor_da213_off ;
typedef void( *ELL_track_sensor_da213_on )(kal_uint8 threshold , FuncPtr callback);
extern ELL_track_sensor_da213_on OTA_track_sensor_da213_on;
typedef kal_int8( *ELL_track_sensor_da213_type_check )(void);
extern ELL_track_sensor_da213_type_check OTA_track_sensor_da213_type_check ;

typedef void( *ELL_RTC_GetTimeOnly )(t_rtc *rtctime);
extern ELL_RTC_GetTimeOnly OTA_RTC_GetTimeOnly ;
typedef void( *ELL_pmu_drv_bl_isink )(PMU_ISINK_LIST_ENUM isink,kal_bool enable);
extern ELL_pmu_drv_bl_isink OTA_pmu_drv_bl_isink ;
typedef DCL_STATUS( *ELL_DclSADC_Control )(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern ELL_DclSADC_Control OTA_DclSADC_Control ;
typedef DCL_HANDLE( *ELL_DclSADC_Open )(DCL_DEV dev, DCL_FLAGS flags);
extern ELL_DclSADC_Open OTA_DclSADC_Open ;
typedef kal_uint8( *ELL_L1SM_GetHandle )( void );
extern ELL_L1SM_GetHandle OTA_L1SM_GetHandle ;
typedef void( *ELL_RTC_InitTC_Time )(t_rtc *rtctime);
extern ELL_RTC_InitTC_Time OTA_RTC_InitTC_Time ;
typedef kal_bool( *ELL_SST_Get_ChipRID )(kal_char *pUid, kal_int32 buf_len);
extern ELL_SST_Get_ChipRID OTA_SST_Get_ChipRID ;
typedef kal_bool( *ELL_nvram_external_read_data )(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size);
extern ELL_nvram_external_read_data OTA_nvram_external_read_data ;
typedef kal_bool( *ELL_nvram_external_write_data )(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size);
extern ELL_nvram_external_write_data OTA_nvram_external_write_data ;


extern UART_PORT* OTA_PS_UART_PORT ;
extern nvram_gps_backup_data_param_struct* OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT ;
extern kal_uint8* OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT ;

extern kal_uint8* OTA_DEFAULT_HARDWARE_YEAR ;
extern kal_uint8* OTA_DEFAULT_HARDWARE_MON ;
extern kal_uint8* OTA_DEFAULT_HARDWARE_DAY ;



extern track_context_struct *track_context_p ;

extern port_setting_struct* OTA_NVRAM_EF_PORT_SETTING_DEFAULT;



typedef kal_uint32( *ELL_kal_ticks_to_secs )(kal_uint32 ticks);
extern ELL_kal_ticks_to_secs OTA_kal_ticks_to_secs ;
typedef kal_uint32( *ELL_kal_get_systicks )(void);
extern ELL_kal_get_systicks OTA_kal_get_systicks ;
typedef kal_uint32( *ELL_kal_secs_to_ticks )(kal_uint32 secs);
extern ELL_kal_secs_to_ticks OTA_kal_secs_to_ticks ;
typedef kal_uint32( *ELL_kal_ticks_to_milli_secs )(kal_uint32 ticks);
extern ELL_kal_ticks_to_milli_secs OTA_kal_ticks_to_milli_secs ;
 
 


typedef module_type( *ELL_kal_get_active_module_id )(void);
extern ELL_kal_get_active_module_id OTA_kal_get_active_module_id ;
typedef kal_uint8( *ELL_convert_to_general_digit )(kal_uint8 *source, kal_uint8 *dest, kal_uint8 type); 
extern ELL_convert_to_general_digit OTA_convert_to_general_digit ;
#define OTA_convert_to_digit(source, dest) OTA_convert_to_general_digit(source, dest, CONVERT_TO_DIGIT_NORMAL)
typedef void( *ELL_l4c_ConvertGSM7BitDefaultEncodingToAscii )(kal_uint8 *message,kal_uint8 *msg,kal_uint16 length,kal_uint16 *outLen);
extern ELL_l4c_ConvertGSM7BitDefaultEncodingToAscii OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii ;
typedef void( *ELL_smsal_gsm7_unpack )(kal_uint8  *packed_data, kal_uint8  *unpacked_data, kal_uint16 data_len, kal_uint16 offset);
extern ELL_smsal_gsm7_unpack OTA_smsal_gsm7_unpack ;
typedef kal_uint16( *ELL_smsal_msg_len_in_character )(kal_uint8 dcs, kal_uint16 len, kal_uint8 last_byte);
extern ELL_smsal_msg_len_in_character OTA_smsal_msg_len_in_character ;
typedef kal_int32( *ELL_applib_dt_compare_time )(applib_time_struct *referenceTime,applib_time_struct *compareTime,applib_time_struct *diff);
extern ELL_applib_dt_compare_time OTA_applib_dt_compare_time ;
typedef void( *ELL_l4cuem_power_off_req )(void);
extern ELL_l4cuem_power_off_req OTA_l4cuem_power_off_req ;
typedef void( *ELL_uem_get_bat_status )(uem_bmt_struct *bmt_status);
extern ELL_uem_get_bat_status OTA_uem_get_bat_status ;
typedef kal_uint32( *ELL_uem_get_vbat_percentage )(void);
extern ELL_uem_get_vbat_percentage OTA_uem_get_vbat_percentage ;
typedef kal_int32( *ELL_mmi_chset_utf16_strlen )(const kal_int8 *str_utf16, mmi_chset_enum utf16_type);
extern ELL_mmi_chset_utf16_strlen OTA_mmi_chset_utf16_strlen;
typedef kal_uint32( *ELL_applib_dt_mytime_2_utc_sec )(applib_time_struct *currTime, kal_bool daylightSaving);
extern ELL_applib_dt_mytime_2_utc_sec OTA_applib_dt_mytime_2_utc_sec ;
typedef kal_int64( *ELL_applib_dt_mytime_2_utc_sec_ext )(applib_time_struct *currTime, kal_bool daylightSaving);
extern ELL_applib_dt_mytime_2_utc_sec_ext OTA_applib_dt_mytime_2_utc_sec_ext ;
typedef kal_uint8 (*ELL_applib_dt_utc_sec_2_mytime)(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
extern ELL_applib_dt_utc_sec_2_mytime OTA_applib_dt_utc_sec_2_mytime ;


typedef void( *ELL_DRV_RESET )(void);
extern ELL_DRV_RESET OTA_DRV_RESET ;
extern kal_uint32* OTA_INT_MemoryDumpFlag;


typedef kal_uint8 (*ELL_track_gps_hour_to_utc)(kal_uint32 utc_sec, applib_time_struct *result);
extern ELL_track_gps_hour_to_utc OTA_track_gps_hour_to_utc ;



typedef void (*ELL_PCM2WAY_Start)(void (*pcm2way_hdlr)(void), kal_uint32 type);
extern ELL_PCM2WAY_Start OTA_PCM2WAY_Start ;
typedef void (*ELL_PCM2WAY_Stop)(kal_uint32 type);
extern ELL_PCM2WAY_Stop OTA_PCM2WAY_Stop ;
typedef void (*ELL_PCM2WAY_GetFromMic)(kal_uint16 *ul_buf);
extern ELL_PCM2WAY_GetFromMic OTA_PCM2WAY_GetFromMic ;


typedef void (*ELL_track_bmt_get_ADC_result)(charge_measure_struct *charge_measure);
extern ELL_track_bmt_get_ADC_result OTA_track_bmt_get_ADC_result ;
typedef void (*ELL_track_bmt_vol_reset_setatus)(void);
extern ELL_track_bmt_vol_reset_setatus OTA_track_bmt_vol_reset_setatus ;

typedef struct
{
    kal_uint32 i[2];        /* number of _bits_ handled mod 2^64 */
    kal_uint32 buf[4];      /* scratch buffer */
    kal_uint8 in[64];       /* input buffer */
    kal_uint8 digest[16];   /* actual digest after MD5Final call */
} applib_md5_ctx;

typedef void (*ELL_applib_md5_init)(applib_md5_ctx *mdContext);
extern ELL_applib_md5_init OTA_applib_md5_init;
typedef void (*ELL_applib_md5_update)(applib_md5_ctx *mdContext, const kal_uint8 *inBuf, kal_uint32 inLen);
extern ELL_applib_md5_update OTA_applib_md5_update;
typedef void (*ELL_applib_md5_final)(kal_uint8 hash[], applib_md5_ctx *mdContext);
extern ELL_applib_md5_final OTA_applib_md5_final;
typedef kal_int32 (*ELL_compress_decode)(kal_uint8 *dect, kal_uint8 *src, int len);
extern ELL_compress_decode OTA_compress_decode;
typedef kal_int32 (*ELL_compress_encode)(kal_uint8 *dect, kal_uint8 *src, int len);
extern ELL_compress_encode OTA_compress_encode;
typedef kal_int32 (*ELL_track_fun_decryption)(kal_uint8 *dec, kal_uint8 *src, int size);
extern ELL_track_fun_decryption OTA_track_fun_decryption;



typedef kal_bool (*ELL_l4c_sms_exe_post_msg_req)(kal_uint8 source_id,
	kal_uint8 profile,
	kal_uint16 reply_index,
	l4c_number_struct dest,
	kal_uint16 para,
	l4c_number_struct sc_addr,
	kal_uint8 vp,
	smsal_pid_enum pid,
	kal_uint8 udhi,
	smsal_dcs_enum dcs,
	kal_uint16 length,
	kal_uint8 *msg,
	kal_uint8 seq_num,
	kal_uint8 mms_mode,
	kal_uint8 tp_srr,
	kal_uint8 tp_rp);
extern ELL_l4c_sms_exe_post_msg_req OTA_l4c_sms_exe_post_msg_req;


typedef kal_bool (*ELL_l4c_sms_exe_post_pdu_req)( kal_uint8 src_id,
										  kal_uint16 reply_index,
										  kal_uint16 data_len,
										  kal_uint8 source_id,
										  kal_uint8 seq_num,
										  kal_uint8 mms_mode,
										  kal_uint16 length,
										  kal_uint8 *pdu);
extern ELL_l4c_sms_exe_post_pdu_req OTA_l4c_sms_exe_post_pdu_req;


typedef kal_bool (*ELL_l4cuem_power_reset)( kal_uint8 reset_type );
extern ELL_l4cuem_power_reset OTA_l4cuem_power_reset;


typedef void (*ELL_uem_poweron_timer_start)(kal_uint32 time_in_ms);
extern ELL_uem_poweron_timer_start OTA_uem_poweron_timer_start;



typedef void (*ELL_aud_send_play_id_req)(void *id_param);
extern ELL_aud_send_play_id_req OTA_aud_send_play_id_req;


typedef kal_status (*ELL_kal_retrieve_eg_events)(kal_eventgrpid eg_id, kal_uint32 requested_events, kal_uint8 operation,kal_uint32 *retrieved_events, kal_uint32 suspend);
extern ELL_kal_retrieve_eg_events OTA_kal_retrieve_eg_events;

typedef kal_int16 (*ELL_gps_uart_read_data_nmea)(module_type module_id, kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern ELL_gps_uart_read_data_nmea OTA_gps_uart_read_data_nmea ;

typedef kal_int16 (*ELL_gps_uart_read_data_dbg)(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);
extern ELL_gps_uart_read_data_dbg OTA_gps_uart_read_data_dbg ;

typedef void (*ELL_track_is_epo_aiding)();
extern ELL_track_is_epo_aiding OTA_track_is_epo_aiding ;

typedef kal_bool (*ELL_track_custom_fake_cell_feature_enable) (kal_uint8 enable);
extern ELL_track_custom_fake_cell_feature_enable OTA_track_custom_fake_cell_feature_enable;

 
typedef kal_eventgrpid (*ELL_kal_create_event_group)(kal_char *eventgrp_name);
extern ELL_kal_create_event_group OTA_kal_create_event_group ;

#if defined (__NF2319__) || defined (__NF2318__)
typedef kal_uint8*(*ELL_ell_play_voice)(kal_uint16 index);
extern ELL_ell_play_voice OTA_ell_play_voice ;
#else
typedef kal_uint8*(*ELL_ell_play_voice)();
extern ELL_ell_play_voice OTA_ell_play_voice ;
#endif /* __NF2319__ */

typedef void (*ELL_track_ble_bt_status)(kal_uint8 *btstatus);
extern ELL_track_ble_bt_status OTA_track_ble_bt_status;

typedef void (*ELL_track_ble_set_status)(kal_uint8 *btstatus);
extern ELL_track_ble_set_status OTA_track_ble_set_status;

typedef void (*ELL_acc_sensor_get_6bytes)(kal_uint16 *accl_x,kal_uint16 *accl_y,kal_uint16 *accl_z);
extern ELL_acc_sensor_get_6bytes OTA_acc_sensor_get_6bytes ;

typedef void (*ELL_track_sensor_kxtj31057_get_xyz)(short *accl_x,short *accl_y,short *accl_z);
extern ELL_track_sensor_kxtj31057_get_xyz OTA_track_sensor_kxtj31057_get_xyz ;

typedef void (*ELL_aud_send_play_string_req)(void *string_param);
extern ELL_aud_send_play_string_req OTA_aud_send_play_string_req;

typedef void (*ELL_aud_send_stop_string_req)(kal_uint8 src_id);
extern ELL_aud_send_stop_string_req OTA_aud_send_stop_string_req;

typedef kal_uint8 (*ELL_aud_get_active_audio_mode)(void);
extern ELL_aud_get_active_audio_mode OTA_aud_get_active_audio_mode;

typedef kal_uint8 (*ELL_aud_get_volume_level)(kal_uint8 mode, kal_uint8 type);
extern ELL_aud_get_volume_level OTA_aud_get_volume_level;

typedef void (*ELL_l4cuem_audio_get_volume_req)(kal_uint8 src_id, kal_uint8 volume_type);
extern ELL_l4cuem_audio_get_volume_req OTA_l4cuem_audio_get_volume_req;

typedef void (*ELL_l4cuem_speech_set_mode_req)(kal_bool speech_mode_onoff, kal_uint8 rat_mode);
extern ELL_l4cuem_speech_set_mode_req OTA_l4cuem_speech_set_mode_req;

typedef void (*ELL_l4cuem_audio_set_volume_req)(kal_uint8 volume_type, kal_uint8 volume_level);
extern ELL_l4cuem_audio_set_volume_req OTA_l4cuem_audio_set_volume_req;

typedef void (*ELL_l4cuem_set_audio_mode)(kal_uint8 mode);
extern ELL_l4cuem_set_audio_mode OTA_l4cuem_set_audio_mode;

typedef void (*ELL_ell_update_soc_nw_attach_ind)(void *msg);
extern ELL_ell_update_soc_nw_attach_ind OTA_ell_update_soc_nw_attach_ind;

extern PW_CTRL_POWER_ON_REASON* OTA_gps_PWRon;

typedef kal_int8 (*ELLtype_ell_update_delete_file)(void);
extern ELLtype_ell_update_delete_file OTA_ell_update_delete_file;

typedef size_t (*ELL_mbstowcs)(wchar_t* s1, const char* s2, size_t n);
extern ELL_mbstowcs OTA_mbstowcs;



typedef void (*ELL_AFE_TurnOffSpeaker)( kal_uint8 aud_func );
extern ELL_AFE_TurnOffSpeaker OTA_AFE_TurnOffSpeaker;

typedef void (*ELL_L1SP_Speech_Off)( void );
extern ELL_L1SP_Speech_Off OTA_L1SP_Speech_Off;

typedef void (*ELL_AFE_SetRefresh)( void );
extern ELL_AFE_SetRefresh OTA_AFE_SetRefresh;

typedef void (*ELL_L1SP_MuteSpeaker)( kal_bool mute );
extern ELL_L1SP_MuteSpeaker OTA_L1SP_MuteSpeaker;

typedef void (*ELL_sys_assert_reset)(void);
extern ELL_sys_assert_reset OTA_sys_assert_reset;

typedef void (*ELL_app_init_complete_callback)(void);
extern ELL_app_init_complete_callback OTA_app_init_complete_callback;

typedef kal_bool (*ELL_l4c_nw_cfun_state_req)(kal_uint8 src_id, kal_uint8 cfun_state);
extern ELL_l4c_nw_cfun_state_req OTA_l4c_nw_cfun_state_req;

typedef void* (*ELL_memcpy)(void* s1,const void* s2, size_t n );
extern ELL_memcpy OTA_memcpy;

typedef void* (*ELL_memmove)(void* s1,const void* s2, size_t n );
extern ELL_memmove OTA_memmove;

typedef char* (*ELL_strcpy)(char* s1,const char* s2 );
extern ELL_strcpy OTA_strcpy;

typedef char* (*ELL_strncpy)(char* s1,const char* s2, size_t n );
extern ELL_strncpy OTA_strncpy;

typedef char* (*ELL_strcat)(char* s1,const char* s2 );
extern ELL_strcat OTA_strcat;

typedef char* (*ELL_strncat)(char* s1,const char* s2, size_t n );
extern ELL_strncat OTA_strncat;

typedef int (*ELL_memcmp)(const void* s1,const void* s2, size_t n );
extern ELL_memcmp OTA_memcmp;

typedef int (*ELL_strcmp)(const char* s1,const char* s2 );
extern ELL_strcmp OTA_strcmp;

typedef int (*ELL_strncmp)(const char* s1,const char* s2, size_t n  );
extern ELL_strncmp OTA_strncmp;

typedef int (*ELL_strcoll)(const char* s1,const char* s2 );
extern ELL_strcoll OTA_strcoll;

typedef size_t (*ELL_strxfrm)( char* s1,const char* s2, size_t n  );
extern ELL_strxfrm OTA_strxfrm;

typedef void* (*ELL_memchr)( void* s1,int c , size_t n );
extern ELL_memchr OTA_memchr;

typedef char* (*ELL_strchr)(const char* s1, int c );
extern ELL_strchr OTA_strchr;

typedef size_t (*ELL_strcspn)(const char* s1 , const char* s2);
extern ELL_strcspn OTA_strcspn;

typedef char* (*ELL_strpbrk)(const char* s1,const char* s2 );
extern ELL_strpbrk OTA_strpbrk;

typedef char* (*ELL_strrchr)(const char* s1, int c );
extern ELL_strrchr OTA_strrchr;

typedef size_t (*ELL_strspn)(const char* s1,const char* s2 );
extern ELL_strspn OTA_strspn;

typedef char* (*ELL_strstr)(const char* s1,const char* s2 );
extern ELL_strstr OTA_strstr;

typedef void* (*ELL_memset)( void* s1,int c , size_t n );
extern ELL_memset OTA_memset;

typedef char* (*ELL_strerror)(int errnum);
extern ELL_strerror OTA_strerror;

typedef size_t (*ELL_strlen)( const char* s );
extern ELL_strlen OTA_strlen;




//---------------------------------------------------------------------------
//---------------------     rt_fp.h    ------------------------------------------
//---------------------------------------------------------------------------



typedef float (*ELL_aeabi_f_ff)(float, float);
extern ELL_aeabi_f_ff OTA_aeabi_fadd;
extern ELL_aeabi_f_ff OTA_aeabi_fsub;
extern ELL_aeabi_f_ff OTA_aeabi_frsub;
extern ELL_aeabi_f_ff OTA_aeabi_fmul;
extern ELL_aeabi_f_ff OTA_aeabi_fdiv;



typedef double (*ELL_aeabi_d_dd)(double, double);
extern ELL_aeabi_d_dd OTA_aeabi_dadd;
extern ELL_aeabi_d_dd OTA_aeabi_dsub;
extern ELL_aeabi_d_dd OTA_aeabi_drsub;
extern ELL_aeabi_d_dd OTA_aeabi_dmul;
extern ELL_aeabi_d_dd OTA_aeabi_ddiv;



typedef int (*ELL_aeabi_i_ff)(float, float);
extern ELL_aeabi_i_ff OTA_aeabi_fcmpeq;
extern ELL_aeabi_i_ff OTA_aeabi_fcmpge;
extern ELL_aeabi_i_ff OTA_aeabi_fcmpgt;
extern ELL_aeabi_i_ff OTA_aeabi_fcmple;
extern ELL_aeabi_i_ff OTA_aeabi_fcmplt;
extern ELL_aeabi_i_ff OTA_aeabi_fcmpun;

typedef void (*ELL_aeabi_ff)(float, float);
extern ELL_aeabi_ff OTA_aeabi_cfcmpeq;
extern ELL_aeabi_ff OTA_aeabi_cfcmple;
extern ELL_aeabi_ff OTA_aeabi_cfrcmple;





typedef int (*ELL_aeabi_i_dd)(double, double);
extern ELL_aeabi_i_dd OTA_aeabi_dcmpeq;
extern ELL_aeabi_i_dd OTA_aeabi_dcmpge;
extern ELL_aeabi_i_dd OTA_aeabi_dcmpgt;
extern ELL_aeabi_i_dd OTA_aeabi_dcmple;
extern ELL_aeabi_i_dd OTA_aeabi_dcmplt;
extern ELL_aeabi_i_dd OTA_aeabi_dcmpun;

typedef void (*ELL_aeabi_dd)(double, double);
extern ELL_aeabi_dd OTA_aeabi_cdcmpeq;
extern ELL_aeabi_dd OTA_aeabi_cdcmple;
extern ELL_aeabi_dd OTA_aeabi_cdrcmple;


typedef double (*ELL_aeabi_f2d)(float);
extern ELL_aeabi_f2d OTA_aeabi_f2d;
typedef float (*ELL_aeabi_d2f)(double);
extern ELL_aeabi_d2f OTA_aeabi_d2f;
typedef float (*ELL_aeabi_i2f)(int);
extern ELL_aeabi_i2f OTA_aeabi_i2f;
typedef float (*ELL_aeabi_ui2f)(unsigned int);
extern ELL_aeabi_ui2f OTA_aeabi_ui2f;
typedef double (*ELL_aeabi_i2d)(int);
extern ELL_aeabi_i2d OTA_aeabi_i2d;
typedef double (*ELL_aeabi_ui2d)(unsigned int);
extern ELL_aeabi_ui2d OTA_aeabi_ui2d;




typedef float (*ELL_aeabi_l2f)(long long);
extern ELL_aeabi_l2f OTA_aeabi_l2f;
typedef float (*ELL_aeabi_ul2f)(unsigned long long);
extern ELL_aeabi_ul2f OTA_aeabi_ul2f;
typedef double (*ELL_aeabi_l2d)(long long);
extern ELL_aeabi_l2d OTA_aeabi_l2d;
typedef double (*ELL_aeabi_ul2d)(unsigned long long);
extern ELL_aeabi_ul2d OTA_aeabi_ul2d;


typedef int (*ELL_aeabi_f2iz)(float);
extern ELL_aeabi_f2iz OTA_aeabi_f2iz;
typedef unsigned int (*ELL_aeabi_f2uiz)(float);
extern ELL_aeabi_f2uiz OTA_aeabi_f2uiz;
typedef int (*ELL_aeabi_d2iz)(double);
extern ELL_aeabi_d2iz OTA_aeabi_d2iz;
typedef unsigned int (*ELL_aeabi_d2uiz)(double);
extern ELL_aeabi_d2uiz OTA_aeabi_d2uiz;



typedef long long (*ELL_aeabi_f2lz)(float);
extern ELL_aeabi_f2lz OTA_aeabi_f2lz;
typedef unsigned long long (*ELL_aeabi_f2ulz)(float);
extern ELL_aeabi_f2ulz OTA_aeabi_f2ulz;
typedef long long (*ELL_aeabi_d2lz)(double);
extern ELL_aeabi_d2lz OTA_aeabi_d2lz;
typedef unsigned long long (*ELL_aeabi_d2ulz)(double);
extern ELL_aeabi_d2ulz OTA_aeabi_d2ulz;



typedef double (*ELL_atof)(const char* nptr );
extern ELL_atof OTA_atof;
typedef int (*ELL_atoi)(const char* nptr );
extern ELL_atoi OTA_atoi;
typedef long int (*ELL_atol)(const char* nptr );
extern ELL_atol OTA_atol;

typedef int (*ELL_abs)(int i );
extern ELL_abs OTA_abs;
typedef long int (*ELL_labs)( long int i );
extern ELL_labs OTA_labs;

typedef double (*ELL_strtod)(const char * nptr, char** endptr );
extern ELL_strtod OTA_strtod;
typedef float (*ELL_strtof)(const char * nptr, char** endptr );
extern ELL_strtof OTA_strtof;
typedef long double (*ELL_strtold)(const char * nptr, char** endptr );
extern ELL_strtold OTA_strtold;
typedef long int (*ELL_strtol)(const char * nptr, char** endptr, int base );
extern ELL_strtol OTA_strtol;
typedef unsigned long int (*ELL_strtoul)(const char * nptr, char** endptr, int base );
extern ELL_strtoul OTA_strtoul;


typedef int (*ELL_rand)(void);
extern ELL_rand OTA_rand;
typedef int (*ELL_srand)(unsigned int seed );
extern ELL_srand OTA_srand;


typedef double (*ELL_acos)(double x );
extern ELL_acos OTA_acos;
typedef double (*ELL_asin)(double x );
extern ELL_asin OTA_asin;
typedef double (*ELL_atan)(double x );
extern ELL_atan OTA_atan;
typedef double (*ELL_atan2)(double y, double x );
extern ELL_atan2 OTA_atan2;
typedef double (*ELL_cos)(double x );
extern ELL_cos OTA_cos;
typedef double (*ELL_sin)(double x );
extern ELL_sin OTA_sin;
typedef double (*ELL_tan)(double x );
extern ELL_tan OTA_tan;
typedef double (*ELL_cosh)(double x );
extern ELL_cosh OTA_cosh;
typedef double (*ELL_sinh)(double x );
extern ELL_sinh OTA_sinh;
typedef double (*ELL_tanh)(double x );
extern ELL_tanh OTA_tanh;
typedef double (*ELL_exp)(double x );
extern ELL_exp OTA_exp;
typedef double (*ELL_frexp)(double value, int* exp );
extern ELL_frexp OTA_frexp;
typedef double (*ELL_ldexp)(double x, int exp );
extern ELL_ldexp OTA_ldexp;


typedef double (*ELL_modf)(double value, double* iptr );
extern ELL_modf OTA_modf;
typedef double (*ELL_pow)(double x, double y);
extern ELL_pow OTA_pow;
typedef double (*ELL_sqrt)(double x);
extern ELL_sqrt OTA_sqrt;
typedef double (*ELL_ceil)(double x);
extern ELL_ceil OTA_ceil;

typedef double (*ELL_fabs)(double x);
extern ELL_fabs OTA_fabs;
typedef double (*ELL_floor)(double d);
extern ELL_floor OTA_floor;
typedef double (*ELL_fmod)(double x, double y);
extern ELL_fmod OTA_fmod;





//---------------------------------------------------------------------------
//---------------------     stdio.h    ------------------------------------------
//---------------------------------------------------------------------------



typedef int (*ELL_fprintf)(FILE* stream,const char* format, ...);
extern ELL_fprintf OTA_fprintf;
#define fprintf OTA_fprintf
typedef int (*ELL_printf)(const char* format, ...);
extern ELL_printf OTA_printf;
#define printf OTA_printf
typedef int (*ELL_sprintf)(char *str, const char *fmt, ...);
extern ELL_sprintf OTA_sprintf;
#define sprintf OTA_sprintf
typedef int (*ELL_snprintf)(char *str, size_t size, const char *fmt, ...);
extern ELL_snprintf OTA_snprintf;
#define snprintf OTA_snprintf
typedef int (*ELL_vfprintf)(FILE* stream,const char* format, va_list arg);
extern ELL_vfprintf OTA_vfprintf;
#define vfprintf OTA_vfprintf
typedef int (*ELL_vprintf)(const char* format, va_list arg);
extern ELL_vprintf OTA_vprintf;
#define vprintf OTA_vprintf
typedef int (*ELL_vsprintf)(char *str, const char* format, va_list arg);
extern ELL_vsprintf OTA_vsprintf;
#define vsprintf OTA_vsprintf
typedef int (*ELL_vsnprintf)( kal_char *str, kal_uint32 size, const kal_char *fmt,va_list ap );
extern ELL_vsnprintf OTA_vsnprintf;
#define vsnprintf OTA_vsnprintf



/* 
 * 16bits string operations
 */
typedef int (*ELL_kal_wstrlen)(const WCHAR *wstr);
extern ELL_kal_wstrlen OTA_kal_wstrlen;
typedef WCHAR* (*ELL_kal_wstrcpy)(WCHAR *to, const WCHAR *from);
extern ELL_kal_wstrcpy OTA_kal_wstrcpy;
typedef WCHAR* (*ELL_kal_wstrncpy)(WCHAR *to, const WCHAR *from, int n);
extern ELL_kal_wstrncpy OTA_kal_wstrncpy;
typedef int (*ELL_kal_wstrcmp)(const WCHAR *s1, const WCHAR *s2);
extern ELL_kal_wstrcmp OTA_kal_wstrcmp;
typedef int (*ELL_kal_wstrncmp)(const WCHAR *s1, const WCHAR *s2, int n);
extern ELL_kal_wstrncmp OTA_kal_wstrncmp;
typedef WCHAR* (*ELL_kal_wstrcat)(WCHAR *s1, const WCHAR *s2);
extern ELL_kal_wstrcat OTA_kal_wstrcat;
typedef WCHAR* (*ELL_kal_wstrncat)(WCHAR *s1, const WCHAR *s2, int n);
extern ELL_kal_wstrncat OTA_kal_wstrncat;
typedef WCHAR* (*ELL_kal_wstrchr)(const WCHAR *s, int c);
extern ELL_kal_wstrchr OTA_kal_wstrchr;
typedef WCHAR* (*ELL_kal_wstrrchr)(const WCHAR *str, int ch);
extern ELL_kal_wstrrchr OTA_kal_wstrrchr;


/* 
 * dual 8bits string operations
 */
typedef int (*ELL_kal_dchar_strlen)(const char *wstr);
extern ELL_kal_dchar_strlen OTA_kal_dchar_strlen;
typedef char* (*ELL_kal_dchar_strcpy)(char *to, const char *from);
extern ELL_kal_dchar_strcpy OTA_kal_dchar_strcpy;
typedef char* (*ELL_kal_dchar_strncpy)(char *to, const char *from, int n);
extern ELL_kal_dchar_strncpy OTA_kal_dchar_strncpy;
typedef int (*ELL_kal_dchar_strcmp)(const char *s1, const char *s2);
extern ELL_kal_dchar_strcmp OTA_kal_dchar_strcmp;
typedef int (*ELL_kal_dchar_strncmp)(const char *s1, const char *s2, int n);
extern ELL_kal_dchar_strncmp OTA_kal_dchar_strncmp;
typedef char* (*ELL_kal_dchar_strcat)(char *s1, const char *s2);
extern ELL_kal_dchar_strcat OTA_kal_dchar_strcat;
typedef char* (*ELL_kal_dchar_strncat)(char *s1, const char *s2, int n);
extern ELL_kal_dchar_strncat OTA_kal_dchar_strncat;
typedef char* (*ELL_kal_dchar_strchr)(const char *s, int c);
extern ELL_kal_dchar_strchr OTA_kal_dchar_strchr;
typedef char* (*ELL_kal_dchar_strrchr)(const char *str, int ch);
extern ELL_kal_dchar_strrchr OTA_kal_dchar_strrchr;
typedef void (*ELL_kal_dchar2char)(WCHAR *outstr, char* tostr);
extern ELL_kal_dchar2char OTA_kal_dchar2char;
typedef void (*ELL_kal_wsprintf)(WCHAR *outstr, char *fmt,...);
extern ELL_kal_wsprintf OTA_kal_wsprintf;




typedef struct { int quot; int rem; } idiv_return; 
typedef struct { unsigned quot; unsigned rem; } uidiv_return;

typedef idiv_return (*ELL_aeabi_idivmod)(int numerator, int denominator);
extern ELL_aeabi_idivmod OTA_aeabi_idivmod;
typedef uidiv_return (*ELL_aeabi_uidivmod)(unsigned numerator, unsigned denominator);
extern ELL_aeabi_uidivmod OTA_aeabi_uidivmod;




typedef double (*ELL_scalbln)(double x, long int n);
extern ELL_scalbln OTA_scalbln;
typedef double (*ELL_scalbn)(double x, int n);
extern ELL_scalbn OTA_scalbn;
typedef float (*ELL_scalbnf)(float x, int n);
extern ELL_scalbnf OTA_scalbnf;



typedef unsigned* (*ELL_rt_fp_status_addr)(void);
extern ELL_rt_fp_status_addr OTA_rt_fp_status_addr;



extern kal_bool* OTA_sds_update_status ;

typedef signed int (*ELL_readRawDiskData)(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len);
extern ELL_readRawDiskData OTA_readRawDiskData;

typedef signed int (*ELL_writeRawDiskData)(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len);
extern ELL_writeRawDiskData OTA_writeRawDiskData;

typedef  signed int (*ELL_eraseRawDiskBlock)(NOR_FLASH_DISK_Data *D, kal_uint32 blkIdx);
extern ELL_eraseRawDiskBlock OTA_eraseRawDiskBlock;

extern NOR_FLASH_DISK_Data* OTA_FlashDiskDriveData;


typedef  kal_bool (*ELL_Ell_Update_SDS_Data)(kal_uint8 *data, kal_uint32 data_index,kal_uint32 len,kal_uint8 *md5);
extern ELL_Ell_Update_SDS_Data OTA_Ell_Update_SDS_Data;

typedef  void (*ELL_track_GPIO_SetClkOut)(char clk_num, gpio_clk_mode mode);
extern ELL_track_GPIO_SetClkOut OTA_track_GPIO_SetClkOut;

typedef void (*ELL_Media_SetBuffer)(uint16 *buffer, uint32 buf_len);
extern ELL_Media_SetBuffer OTA_Media_SetBuffer;

typedef void (*ELL_Media_SetRBThreshold)( uint16 threshold );
extern ELL_Media_SetRBThreshold OTA_Media_SetRBThreshold;

typedef Media_Status (*ELL_Media_Record)( Media_Format format, void (*media_handler)( Media_Event event ), void *param );
extern ELL_Media_Record OTA_Media_Record;

typedef void (*ELL_Media_Stop)( void );
extern ELL_Media_Stop OTA_Media_Stop;

typedef void (*ELL_Media_GetReadBuffer)( uint16 **buffer, uint32 *buf_len );
extern ELL_Media_GetReadBuffer OTA_Media_GetReadBuffer;

typedef void (*ELL_Media_ReadDataDone)( uint32 len );
extern ELL_Media_ReadDataDone OTA_Media_ReadDataDone;

typedef kal_uint32 (*ELL_app_getcurrtime)(void);
extern ELL_app_getcurrtime OTA_app_getcurrtime;

typedef char (*ELL_ell_get_iccid)(void);
extern ELL_ell_get_iccid OTA_ell_get_iccid;

typedef kal_int32 (*ELL_media_aud_play_file)(module_type src_mod_id, void *file_param);
extern ELL_media_aud_play_file OTA_media_aud_play_file;


#endif /* __TRACK_OS_ELL_H__ */
