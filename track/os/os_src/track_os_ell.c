
#include "track_os_ell.h"
#include "keypad_sw.h"
#include "custom_config_account.h"



static void OTA_log2_dummy(const char* fun_name, const char* message , ...) {}
ELL_LOG OTA_log2 = OTA_log2_dummy;

static event_scheduler* OTA_evshed_create_dummy(kal_char *evshed_name, module_type module_id, kal_uint32 allowed_time_shift, kal_uint16 allowed_time_shift_sleep_mode) {}
ELL_evshed_create OTA_evshed_create = OTA_evshed_create_dummy ;

static kal_int32 OTA_evshed_cancel_event_dummy(event_scheduler *es, eventid *eid) {}
ELL_evshed_cancel_event OTA_evshed_cancel_event = OTA_evshed_cancel_event_dummy ;

static eventid OTA_evshed_set_event_dummy(event_scheduler *es, kal_timer_func_ptr event_hf, void *event_hf_param, kal_uint32 elapse_time) {}
ELL_evshed_set_event OTA_evshed_set_event = OTA_evshed_set_event_dummy ;

static void OTA_evshed_timer_handler_dummy(event_scheduler *es) {}
ELL_evshed_timer_handler OTA_evshed_timer_handler = OTA_evshed_timer_handler_dummy ;

static void OTA_GPIO_InitIO_dummy(char direction, char port) {}
ELL_GPIO_InitIO OTA_GPIO_InitIO = OTA_GPIO_InitIO_dummy ;

static void OTA_GPIO_ModeSetup_dummy(kal_uint16 pin, kal_uint16 conf_dada) {}
ELL_GPIO_ModeSetup OTA_GPIO_ModeSetup = OTA_GPIO_ModeSetup_dummy ;

static char OTA_GPIO_ReadIO_dummy(char port) {}
ELL_GPIO_ReadIO OTA_GPIO_ReadIO = OTA_GPIO_ReadIO_dummy ;

static char OTA_GPIO_ReturnDout_dummy(char port) {}
ELL_GPIO_ReturnDout OTA_GPIO_ReturnDout = OTA_GPIO_ReturnDout_dummy ;

static void OTA_GPIO_WriteIO_dummy(char data, char port) {}
ELL_GPIO_WriteIO OTA_GPIO_WriteIO = OTA_GPIO_WriteIO_dummy ;

static DCL_STATUS OTA_DclPMU_Close_dummy(DCL_HANDLE handle) {}
ELL_DclPMU_Close OTA_DclPMU_Close = OTA_DclPMU_Close_dummy ;

static DCL_STATUS OTA_DclPMU_Control_dummy(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data) {}
ELL_DclPMU_Control OTA_DclPMU_Control = OTA_DclPMU_Control_dummy ;

static DCL_HANDLE OTA_DclPMU_Open_dummy(DCL_DEV dev, DCL_FLAGS flags) {}
ELL_DclPMU_Open OTA_DclPMU_Open = OTA_DclPMU_Open_dummy ;

static void OTA_EINT_Mask_dummy(kal_uint8 eintno) {}
ELL_EINT_Mask OTA_EINT_Mask = OTA_EINT_Mask_dummy ;

static void OTA_EINT_Registration_dummy(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_lisr)(void), kal_bool auto_umask) {}
ELL_EINT_Registration OTA_EINT_Registration = OTA_EINT_Registration_dummy ;

static kal_int32 OTA_EINT_SW_Debounce_Modify_dummy(kal_uint8 eintno, kal_uint8 debounce_time) {}
ELL_EINT_SW_Debounce_Modify OTA_EINT_SW_Debounce_Modify = OTA_EINT_SW_Debounce_Modify_dummy ;

static kal_uint32 OTA_EINT_Set_Sensitivity_dummy(kal_uint8 eintno, kal_bool sens) {}
ELL_EINT_Set_Sensitivity OTA_EINT_Set_Sensitivity = OTA_EINT_Set_Sensitivity_dummy ;

static void OTA_EINT_UnMask_dummy(kal_uint8 eintno) {}
ELL_EINT_UnMask OTA_EINT_UnMask = OTA_EINT_UnMask_dummy ;

static void OTA_EINT_Set_Polarity_dummy(kal_uint8 eintno, kal_bool ACT_Polarity) {}
ELL_EINT_Set_Polarity OTA_EINT_Set_Polarity = 0 ;

static DCL_STATUS OTA_DclSerialPort_Control_dummy(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data) {}
ELL_DclSerialPort_Control OTA_DclSerialPort_Control = OTA_DclSerialPort_Control_dummy ;

static DCL_HANDLE OTA_DclSerialPort_Open_dummy(DCL_DEV dev, DCL_FLAGS flags) {}
ELL_DclSerialPort_Open OTA_DclSerialPort_Open = OTA_DclSerialPort_Open_dummy ;

static DCL_STATUS OTA_DclSerialPort_Close_dummy(DCL_HANDLE handle) {}
ELL_DclSerialPort_Close OTA_DclSerialPort_Close = OTA_DclSerialPort_Close_dummy ;

static void OTA_track_GPIO_SetClkOut_dummy(char clk_num, gpio_clk_mode mode) {}
ELL_track_GPIO_SetClkOut OTA_track_GPIO_SetClkOut = OTA_track_GPIO_SetClkOut_dummy;

static void* OTA_kal_adm_alloc_1_dummy(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line) {}
ELL_kal_adm_alloc_1 OTA_kal_adm_alloc_1 = OTA_kal_adm_alloc_1_dummy ;

static KAL_ADM_ID OTA_kal_adm_create2_dummy(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_uint32 flags, kal_int8 extheader_size_in_word) {}
ELL_kal_adm_create2 OTA_kal_adm_create2 = OTA_kal_adm_create2_dummy ;

static kal_status OTA_kal_adm_delete_dummy(KAL_ADM_ID adm_id) {}
ELL_kal_adm_delete OTA_kal_adm_delete = OTA_kal_adm_delete_dummy ;

static void OTA_kal_adm_free_dummy(KAL_ADM_ID adm_id, void *mem_addr) {}
ELL_kal_adm_free OTA_kal_adm_free = OTA_kal_adm_free_dummy ;

static kal_uint32 OTA_kal_adm_get_max_alloc_size_dummy(KAL_ADM_ID adm_id) {}
ELL_kal_adm_get_max_alloc_size OTA_kal_adm_get_max_alloc_size = OTA_kal_adm_get_max_alloc_size_dummy ;

static kal_uint32 OTA_kal_adm_get_total_left_size_dummy(KAL_ADM_ID adm_id) {}
ELL_kal_adm_get_total_left_size OTA_kal_adm_get_total_left_size = OTA_kal_adm_get_total_left_size_dummy ;

static kal_mutexid OTA_kal_create_mutex_dummy(kal_char* mutex_name_ptr) {}
ELL_kal_create_mutex OTA_kal_create_mutex = OTA_kal_create_mutex_dummy ;

static void OTA_kal_take_mutex_dummy(kal_mutexid mutex_id) {}
ELL_kal_take_mutex OTA_kal_take_mutex = OTA_kal_take_mutex_dummy ;

static void OTA_kal_give_mutex_dummy(kal_mutexid mutex_id) {}
ELL_kal_give_mutex OTA_kal_give_mutex = OTA_kal_give_mutex_dummy ;

static kal_int8 OTA_soc_close_dummy(kal_int8 s) {}
ELL_soc_close OTA_soc_close = OTA_soc_close_dummy ;

static kal_int8 OTA_soc_connect_dummy(kal_int8 s, sockaddr_struct *addr) {}
ELL_soc_connect OTA_soc_connect = OTA_soc_connect_dummy ;

static kal_int8 OTA_soc_create_dummy(kal_uint8 domain, socket_type_enum type, kal_uint8 protocol, module_type mod_id, kal_uint32 nwk_account_id) {}
ELL_soc_create OTA_soc_create = OTA_soc_create_dummy ;

static kal_int8 OTA_soc_gethostbyname_dummy(kal_bool is_blocking, module_type mod_id, kal_int32 request_id, const kal_char  *domain_name, kal_uint8 *addr, kal_uint8 *addr_len, kal_uint8 access_id, kal_uint32 nwk_account_id) {}
ELL_soc_gethostbyname OTA_soc_gethostbyname = OTA_soc_gethostbyname_dummy ;

static kal_int8 OTA_soc_getsockopt_dummy(kal_int8   s, kal_uint32 option, void       *val, kal_uint8  val_size) {}
ELL_soc_getsockopt OTA_soc_getsockopt = OTA_soc_getsockopt_dummy ;

static kal_int32 OTA_soc_recv_dummy(kal_int8  s, void *buf, kal_int32 len, kal_uint8 flags) {}
ELL_soc_recv OTA_soc_recv = OTA_soc_recv_dummy ;

static kal_int32 OTA_soc_send_dummy(kal_int8	 s, const void *buf, kal_int32  len, kal_uint8	 flags) {}
ELL_soc_send OTA_soc_send = OTA_soc_send_dummy ;

static kal_int32 OTA_soc_sendto_dummy(kal_int8 s, const void *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *addr){return 0;}
ELL_soc_sendto OTA_soc_sendto = OTA_soc_sendto_dummy;

static kal_int32 OTA_soc_recvfrom_dummy(kal_int8 s, void *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *fromaddr){return 0;}
ELL_soc_recvfrom OTA_soc_recvfrom = OTA_soc_recvfrom_dummy;

static kal_int8 OTA_soc_setsockopt_dummy(kal_int8   s, kal_uint32 option, void       *val, kal_uint8  val_size) {}
ELL_soc_setsockopt OTA_soc_setsockopt = OTA_soc_setsockopt_dummy ;

static kal_uint32 OTA_cbm_encode_data_account_id_dummy(kal_uint32 acct_id, cbm_sim_id_enum sim_id, kal_uint8 app_id, kal_bool always_ask) {}
ELL_cbm_encode_data_account_id OTA_cbm_encode_data_account_id = OTA_cbm_encode_data_account_id_dummy ;

static kal_uint8 OTA_cbm_get_app_id_dummy(kal_uint32 acct_id) {}
ELL_cbm_get_app_id OTA_cbm_get_app_id = OTA_cbm_get_app_id_dummy ;

static kal_uint8 OTA_cbm_register_app_id_with_app_info_dummy(cbm_app_info_struct *info, kal_uint8 *app_id) {}
ELL_cbm_register_app_id_with_app_info OTA_cbm_register_app_id_with_app_info = OTA_cbm_register_app_id_with_app_info_dummy ;

static void OTA_kal_cancel_timer_dummy(kal_timerid timer_ptr) {}
ELL_kal_cancel_timer OTA_kal_cancel_timer = OTA_kal_cancel_timer_dummy ;

static kal_timerid OTA_kal_create_timer_dummy(kal_char* timer_name_ptr) {}
ELL_kal_create_timer OTA_kal_create_timer = OTA_kal_create_timer_dummy ;

static void OTA_kal_set_timer_dummy(kal_timerid timer_id, kal_timer_func_ptr handler_func_ptr, void* handler_param_ptr, kal_uint32 delay, kal_uint32 reschedule_time) {}
ELL_kal_set_timer OTA_kal_set_timer = OTA_kal_set_timer_dummy ;

/***待删除***/
static kal_bool OTA_track_net_apn_set_dummy(void) {}
ELL_track_net_apn_set OTA_track_net_apn_set = OTA_track_net_apn_set_dummy ;
/***********/

static track_custom_gprs_apn_struct *OTA_track_net_get_apn_dummy(char *imsi) {}
ELL_track_net_get_apn OTA_track_net_get_apn = OTA_track_net_get_apn_dummy ;

static ilm_struct* OTA_allocate_ilm_dummy(module_type module_id) {}
ELL_allocate_ilm OTA_allocate_ilm = OTA_allocate_ilm_dummy ;

static void* OTA_construct_int_local_para_1_dummy(kal_uint16 local_para_size, kal_uint32 auto_reset, kal_char* file_ptr, kal_uint32 line) {}
ELL_construct_int_local_para_1 OTA_construct_int_local_para_1 = OTA_construct_int_local_para_1_dummy ;

static kal_bool OTA_msg_send_ext_queue_dummy(ilm_struct *ilm_ptr) {}
ELL_msg_send_ext_queue OTA_msg_send_ext_queue = OTA_msg_send_ext_queue_dummy ;

static kal_char* OTA_build_date_time_dummy(void) {}
ELL_build_date_time OTA_build_date_time = OTA_build_date_time_dummy ;

static kal_char* OTA_release_verno_dummy(void) {}
ELL_release_verno OTA_release_verno = OTA_release_verno_dummy ;

static void OTA_U_PutUARTBytes_dummy(UART_PORT port, kal_uint8 *data, kal_uint16 len) {}
ELL_U_PutUARTBytes OTA_U_PutUARTBytes = OTA_U_PutUARTBytes_dummy ;

static kal_int32 OTA_app_ucs2_strlen_dummy(const kal_int8 *arrOut) {}
ELL_app_ucs2_strlen OTA_app_ucs2_strlen = OTA_app_ucs2_strlen_dummy ;

static void OTA_applib_dt_get_rtc_time_dummy(applib_time_struct *t) {}
ELL_applib_dt_get_rtc_time OTA_applib_dt_get_rtc_time = OTA_applib_dt_get_rtc_time_dummy ;

static kal_uint32 OTA_applib_get_time_difference_ext_in_second_dummy(applib_time_struct *t1, applib_time_struct *t2) {}
ELL_applib_get_time_difference_ext_in_second OTA_applib_get_time_difference_ext_in_second = OTA_applib_get_time_difference_ext_in_second_dummy ;

static kal_uint16 OTA_app_asc_str_n_to_ucs2_str_dummy(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len) {}
ELL_app_asc_str_n_to_ucs2_str OTA_app_asc_str_n_to_ucs2_str = OTA_app_asc_str_n_to_ucs2_str_dummy ;

static kal_uint16 OTA_app_ucs2_str_n_to_asc_str_dummy(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len) {}
ELL_app_ucs2_str_n_to_asc_str OTA_app_ucs2_str_n_to_asc_str = OTA_app_ucs2_str_n_to_asc_str_dummy ;

static kal_int32 OTA_mmi_chset_convert_ex_dummy(mmi_chset_enum src_type, mmi_chset_enum dest_type, char *src_buff, char *dest_buff, kal_int32 dest_size, kal_uint32 *src_end_pos) {}
ELL_mmi_chset_convert_ex OTA_mmi_chset_convert_ex = OTA_mmi_chset_convert_ex_dummy ;

static void OTA_mtk_gps_sys_storage_clear_dummy(void) {}
ELL_mtk_gps_sys_storage_clear OTA_mtk_gps_sys_storage_clear = OTA_mtk_gps_sys_storage_clear_dummy ;

static sim_card_status_enum OTA_check_sim_card_status_dummy(void) {}
ELL_check_sim_card_status OTA_check_sim_card_status = OTA_check_sim_card_status_dummy ;

static kal_int8* OTA_app_ucs2_strcat_dummy(kal_int8 *strDestination, const kal_int8 *strSource) {}
ELL_app_ucs2_strcat OTA_app_ucs2_strcat = OTA_app_ucs2_strcat_dummy;

static kal_int8* OTA_app_ucs2_strcpy_dummy(kal_int8 *strDestination, const kal_int8 *strSource) {}
ELL_app_ucs2_strcpy OTA_app_ucs2_strcpy = OTA_app_ucs2_strcpy_dummy ;

static void OTA_applib_dt_decrease_time_dummy(applib_time_struct *timeToDecrement, applib_time_struct *decrement, applib_time_struct *Result) {}
ELL_applib_dt_decrease_time OTA_applib_dt_decrease_time = OTA_applib_dt_decrease_time_dummy;

static void OTA_applib_dt_increase_time_dummy(applib_time_struct *timeToIncrement, applib_time_struct *increment, applib_time_struct *Result) {}
ELL_applib_dt_increase_time OTA_applib_dt_increase_time = OTA_applib_dt_increase_time_dummy;

static void OTA_uem_drv_power_on_dummy(void) {}
ELL_uem_drv_power_on OTA_uem_drv_power_on = OTA_uem_drv_power_on_dummy;

static void OTA_uem_drv_power_off_dummy(void) {}
ELL_uem_drv_power_off OTA_uem_drv_power_off = OTA_uem_drv_power_off_dummy;

static void OTA_L1SM_SleepEnable_dummy(kal_uint8 handle) {}
ELL_L1SM_SleepEnable OTA_L1SM_SleepEnable = OTA_L1SM_SleepEnable_dummy;

static void OTA_L1SM_SleepDisable_dummy(kal_uint8 handle) {}
ELL_L1SM_SleepDisable OTA_L1SM_SleepDisable = OTA_L1SM_SleepDisable_dummy;

static mtk_int32 OTA_mtk_gps_set_param_dummy(mtk_gps_param key, const void* value) {}
ELL_mtk_gps_set_param OTA_mtk_gps_set_param = OTA_mtk_gps_set_param_dummy;

static mtk_int32 OTA_mtk_gps_get_param_dummy(mtk_gps_param key, void* value) {}
ELL_mtk_gps_get_param OTA_mtk_gps_get_param = OTA_mtk_gps_get_param_dummy;

static void OTA_kal_prompt_trace_dummy(module_type mod_id, const kal_char *fmt, ...) {}
ELL_kal_prompt_trace OTA_kal_prompt_trace = OTA_kal_prompt_trace_dummy;

static void OTA_l4csmu_get_imsi_dummy(kal_uint8 *imsi_data) {}
ELL_l4csmu_get_imsi OTA_l4csmu_get_imsi = OTA_l4csmu_get_imsi_dummy ;

static void OTA_ASSERT_dummy(int expr) {}
ELL_ASSERT OTA_ASSERT = OTA_ASSERT_dummy ;


ELL_track_sensor_bma250_off OTA_track_sensor_bma250_off = 0;
ELL_track_sensor_bma250_on OTA_track_sensor_bma250_on = 0;
ELL_track_sensor_bma250_type_check OTA_track_sensor_bma250_type_check = 0;

ELL_track_sensor_kxtj31057_off OTA_track_sensor_kxtj31057_off = 0;
ELL_track_sensor_kxtj31057_on OTA_track_sensor_kxtj31057_on = 0;
ELL_track_sensor_kxtj31057_type_check OTA_track_sensor_kxtj31057_type_check = 0;

ELL_track_sensor_sc7a20_off OTA_track_sensor_sc7a20_off = 0;
ELL_track_sensor_sc7a20_on OTA_track_sensor_sc7a20_on = 0;
ELL_track_sensor_sc7a20_type_check OTA_track_sensor_sc7a20_type_check = 0;

ELL_track_sensor_da213_off OTA_track_sensor_da213_off = 0;
ELL_track_sensor_da213_on OTA_track_sensor_da213_on = 0;
ELL_track_sensor_da213_type_check OTA_track_sensor_da213_type_check = 0;


static void OTA_RTC_GetTimeOnly_dummy(t_rtc *rtctime) {}
ELL_RTC_GetTimeOnly OTA_RTC_GetTimeOnly  = OTA_RTC_GetTimeOnly_dummy;

static void OTA_pmu6250_bl_isink_dummy(PMU_ISINK_LIST_ENUM isink, kal_bool enable) {}
ELL_pmu_drv_bl_isink OTA_pmu_drv_bl_isink  = OTA_pmu6250_bl_isink_dummy;

static DCL_STATUS OTA_DclSADC_Control_dummy(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data) {}
ELL_DclSADC_Control OTA_DclSADC_Control  = OTA_DclSADC_Control_dummy;

static DCL_HANDLE OTA_DclSADC_Open_dummy(DCL_DEV dev, DCL_FLAGS flags) {}
ELL_DclSADC_Open OTA_DclSADC_Open  = OTA_DclSADC_Open_dummy;

static kal_uint8 OTA_L1SM_GetHandle_dummy(void) {}
ELL_L1SM_GetHandle OTA_L1SM_GetHandle  = OTA_L1SM_GetHandle_dummy;

static void OTA_RTC_InitTC_Time_dummy(t_rtc *rtctime) {}
ELL_RTC_InitTC_Time OTA_RTC_InitTC_Time  = OTA_RTC_InitTC_Time_dummy;

static kal_bool OTA_SST_Get_ChipRID_dummy(kal_char *pUid, kal_int32 buf_len) {}
ELL_SST_Get_ChipRID OTA_SST_Get_ChipRID  = OTA_SST_Get_ChipRID_dummy;




UART_PORT* OTA_PS_UART_PORT = NULL;
nvram_gps_backup_data_param_struct* OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT = NULL;
kal_uint8* OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT  = NULL;
kal_uint8* OTA_DEFAULT_HARDWARE_YEAR = NULL;
kal_uint8* OTA_DEFAULT_HARDWARE_MON = NULL;
kal_uint8* OTA_DEFAULT_HARDWARE_DAY = NULL;




static int OTA_FS_Close_dummy(FS_HANDLE File) {}
ELL_FS_Close OTA_FS_Close = OTA_FS_Close_dummy ;

static int OTA_FS_Commit_dummy(FS_HANDLE File) {}
ELL_FS_Commit OTA_FS_Commit = OTA_FS_Commit_dummy ;

static int OTA_FS_CreateDir_dummy(const WCHAR * DirName) {}
ELL_FS_CreateDir OTA_FS_CreateDir = OTA_FS_CreateDir_dummy ;

static int OTA_FS_Delete_dummy(const WCHAR * FileName) {}
ELL_FS_Delete OTA_FS_Delete = OTA_FS_Delete_dummy ;

static int OTA_FS_Rename_dummy(const WCHAR * FileName, const WCHAR * NewName) {return 0;}
ELL_FS_Rename OTA_FS_Rename = OTA_FS_Rename_dummy ;

static int OTA_FS_FindFirst_dummy(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength) {}
ELL_FS_FindFirst OTA_FS_FindFirst = OTA_FS_FindFirst_dummy ;

static int OTA_FS_FindNext_dummy(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength) {}
ELL_FS_FindNext OTA_FS_FindNext = OTA_FS_FindNext_dummy ;

static int OTA_FS_GetDrive_dummy(UINT Type, UINT Serial, UINT AltMask) {}
ELL_FS_GetDrive OTA_FS_GetDrive = OTA_FS_GetDrive_dummy ;

static int OTA_FS_GetFileSize_dummy(FS_HANDLE FileHandle, kal_uint32 * Size) {}
ELL_FS_GetFileSize OTA_FS_GetFileSize = OTA_FS_GetFileSize_dummy ;

static int OTA_FS_GetFolderSize_dummy(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize) {}
ELL_FS_GetFolderSize OTA_FS_GetFolderSize = OTA_FS_GetFolderSize_dummy ;

static int OTA_FS_Open_dummy(const WCHAR * FileName, UINT Flag) {}
ELL_FS_Open OTA_FS_Open = OTA_FS_Open_dummy ;

static int OTA_FS_Seek_dummy(FS_HANDLE FileHandle, int Offset, int Whence) {}
ELL_FS_Seek OTA_FS_Seek = OTA_FS_Seek_dummy ;

static int OTA_FS_Write_dummy(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written) {}
ELL_FS_Write OTA_FS_Write = OTA_FS_Write_dummy ;

static int OTA_FS_Read_dummy(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read) {}
ELL_FS_Read OTA_FS_Read = OTA_FS_Read_dummy ;

static int OTA_FS_XDelete_dummy(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize) {}
ELL_FS_XDelete OTA_FS_XDelete = OTA_FS_XDelete_dummy ;

static int OTA_FS_GeneralFormat_dummy(const WCHAR * DriveName, UINT Level, FS_FormatCallback Progress) {}
ELL_FS_GeneralFormat OTA_FS_GeneralFormat = OTA_FS_GeneralFormat_dummy ;

static int OTA_FS_GetDiskInfo_dummy(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags) {}
ELL_FS_GetDiskInfo OTA_FS_GetDiskInfo = OTA_FS_GetDiskInfo_dummy ;

static kal_bool OTA_nvram_external_read_data_dummy(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size) {}
ELL_nvram_external_read_data OTA_nvram_external_read_data  = OTA_nvram_external_read_data_dummy;

static kal_bool OTA_nvram_external_write_data_dummy(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size) {}
ELL_nvram_external_write_data OTA_nvram_external_write_data  = OTA_nvram_external_write_data_dummy ;



port_setting_struct* OTA_NVRAM_EF_PORT_SETTING_DEFAULT = NULL;

static kal_uint32 OTA_kal_ticks_to_secs_dummy(kal_uint32 ticks) {}
ELL_kal_ticks_to_secs OTA_kal_ticks_to_secs = OTA_kal_ticks_to_secs_dummy;

static kal_uint32 OTA_kal_get_systicks_dummy(void) {}
ELL_kal_get_systicks OTA_kal_get_systicks = OTA_kal_get_systicks_dummy ;

static kal_uint32 OTA_kal_secs_to_ticks_dummy(kal_uint32 secs) {}
ELL_kal_secs_to_ticks OTA_kal_secs_to_ticks = OTA_kal_secs_to_ticks_dummy ;

static kal_uint32 OTA_kal_ticks_to_milli_secs_dummy(kal_uint32 ticks) {}
ELL_kal_ticks_to_milli_secs OTA_kal_ticks_to_milli_secs = OTA_kal_ticks_to_milli_secs_dummy;

static module_type OTA_kal_get_active_module_id_dummy(void) {}
ELL_kal_get_active_module_id OTA_kal_get_active_module_id = OTA_kal_get_active_module_id_dummy;

static kal_uint8 OTA_convert_to_general_digit_dummy(kal_uint8 *source, kal_uint8 *dest, kal_uint8 type) {}
ELL_convert_to_general_digit OTA_convert_to_general_digit = OTA_convert_to_general_digit_dummy;

static void OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii_dummy(kal_uint8 *message, kal_uint8 *msg, kal_uint16 length, kal_uint16 *outLen) {}
ELL_l4c_ConvertGSM7BitDefaultEncodingToAscii OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii = OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii_dummy;

static void OTA_smsal_gsm7_unpack_dummy(kal_uint8  *packed_data, kal_uint8  *unpacked_data, kal_uint16 data_len, kal_uint16 offset) {}
ELL_smsal_gsm7_unpack OTA_smsal_gsm7_unpack = OTA_smsal_gsm7_unpack_dummy;

static kal_uint16 OTA_smsal_msg_len_in_character_dummy(kal_uint8 dcs, kal_uint16 len, kal_uint8 last_byte) {}
ELL_smsal_msg_len_in_character OTA_smsal_msg_len_in_character = OTA_smsal_msg_len_in_character_dummy;

static kal_int32 OTA_applib_dt_compare_time_dummy(applib_time_struct *referenceTime, applib_time_struct *compareTime, applib_time_struct *diff) {}
ELL_applib_dt_compare_time OTA_applib_dt_compare_time = OTA_applib_dt_compare_time_dummy;

static void OTA_l4cuem_power_off_req_dummy(void) {}
ELL_l4cuem_power_off_req OTA_l4cuem_power_off_req = OTA_l4cuem_power_off_req_dummy;

static void OTA_uem_get_bat_status_dummy(uem_bmt_struct *bmt_status) {}
ELL_uem_get_bat_status OTA_uem_get_bat_status = OTA_uem_get_bat_status_dummy;

static kal_uint32 OTA_uem_get_vbat_percentage_dummy(void) {}
ELL_uem_get_vbat_percentage OTA_uem_get_vbat_percentage = OTA_uem_get_vbat_percentage_dummy;

static kal_int32 OTA_mmi_chset_utf16_strlen_dummy(const kal_int8 *str_utf16, mmi_chset_enum utf16_type) {}
ELL_mmi_chset_utf16_strlen OTA_mmi_chset_utf16_strlen = OTA_mmi_chset_utf16_strlen_dummy;

static kal_uint32 OTA_applib_dt_mytime_2_utc_sec_dummy(applib_time_struct *currTime, kal_bool daylightSaving) {}
ELL_applib_dt_mytime_2_utc_sec OTA_applib_dt_mytime_2_utc_sec = OTA_applib_dt_mytime_2_utc_sec_dummy;

static kal_int64 OTA_applib_dt_mytime_2_utc_sec_ext_dummy(applib_time_struct *currTime, kal_bool daylightSaving) {}
ELL_applib_dt_mytime_2_utc_sec_ext OTA_applib_dt_mytime_2_utc_sec_ext = OTA_applib_dt_mytime_2_utc_sec_ext_dummy;


static void OTA_DRV_RESET_dummy(void) {}
ELL_DRV_RESET OTA_DRV_RESET = OTA_DRV_RESET_dummy;


kal_uint32* OTA_INT_MemoryDumpFlag = NULL ;

static kal_uint8 OTA_applib_dt_utc_sec_2_mytime_dummy(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving) {}
ELL_applib_dt_utc_sec_2_mytime OTA_applib_dt_utc_sec_2_mytime = OTA_applib_dt_utc_sec_2_mytime_dummy;

static kal_uint8 OTA_track_gps_hour_to_utc_dummy(kal_uint32 utc_sec, applib_time_struct *result) {}
ELL_track_gps_hour_to_utc OTA_track_gps_hour_to_utc = OTA_track_gps_hour_to_utc_dummy;


static void OTA_PCM2WAY_Start_dummy(void (*pcm2way_hdlr)(void), kal_uint32 type) {}
ELL_PCM2WAY_Start OTA_PCM2WAY_Start = OTA_PCM2WAY_Start_dummy;

static void OTA_PCM2WAY_Stop_dummy(kal_uint32 type) {}
ELL_PCM2WAY_Stop OTA_PCM2WAY_Stop = OTA_PCM2WAY_Stop_dummy;

static void OTA_PCM2WAY_GetFromMic_dummy(kal_uint16 *ul_buf) {}
ELL_PCM2WAY_GetFromMic OTA_PCM2WAY_GetFromMic = OTA_PCM2WAY_GetFromMic_dummy;

static void OTA_track_bmt_get_ADC_result_dummy(charge_measure_struct *charge_measure) {}
ELL_track_bmt_get_ADC_result OTA_track_bmt_get_ADC_result  = OTA_track_bmt_get_ADC_result_dummy;

static void OTA_track_bmt_vol_reset_setatus_dummy(void) {}
ELL_track_bmt_vol_reset_setatus OTA_track_bmt_vol_reset_setatus  = OTA_track_bmt_vol_reset_setatus_dummy;

static void OTA_applib_md5_init_dummy(applib_md5_ctx *mdContext) {}
ELL_applib_md5_init OTA_applib_md5_init = OTA_applib_md5_init_dummy;

static void OTA_applib_md5_update_dummy(applib_md5_ctx *mdContext, const kal_uint8 *inBuf, kal_uint32 inLen) {}
ELL_applib_md5_update OTA_applib_md5_update = OTA_applib_md5_update_dummy;

static void OTA_applib_md5_final_dummy(kal_uint8 hash[], applib_md5_ctx *mdContext) {}
ELL_applib_md5_final OTA_applib_md5_final = OTA_applib_md5_final_dummy;

static kal_int32 OTA_compress_decode_dummy(kal_uint8 *dect, kal_uint8 *src, int len) {}
ELL_compress_decode OTA_compress_decode = OTA_compress_decode_dummy;

static kal_int32 OTA_compress_encode_dummy(kal_uint8 *dect, kal_uint8 *src, int len) {}
ELL_compress_encode OTA_compress_encode = OTA_compress_encode_dummy;

static kal_int32 OTA_track_fun_decryption_dummy(kal_uint8 *dec, kal_uint8 *src, int size) {}
ELL_track_fun_decryption OTA_track_fun_decryption = OTA_track_fun_decryption_dummy;


static kal_bool OTA_l4c_sms_exe_post_msg_req_dummy(kal_uint8 source_id,
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
        kal_uint8 tp_rp) {}
ELL_l4c_sms_exe_post_msg_req OTA_l4c_sms_exe_post_msg_req = OTA_l4c_sms_exe_post_msg_req_dummy;

static kal_bool OTA_l4c_sms_exe_post_pdu_req_dummy(kal_uint8 src_id,
        kal_uint16 reply_index,
        kal_uint16 data_len,
        kal_uint8 source_id,
        kal_uint8 seq_num,
        kal_uint8 mms_mode,
        kal_uint16 length,
        kal_uint8 *pdu) {}
ELL_l4c_sms_exe_post_pdu_req OTA_l4c_sms_exe_post_pdu_req = OTA_l4c_sms_exe_post_pdu_req_dummy;

static kal_bool OTA_l4cuem_power_reset_dummy(kal_uint8 reset_type) {}
ELL_l4cuem_power_reset OTA_l4cuem_power_reset = OTA_l4cuem_power_reset_dummy;

static void OTA_uem_poweron_timer_start_dummy(kal_uint32 time_in_ms) {}
ELL_uem_poweron_timer_start OTA_uem_poweron_timer_start = OTA_uem_poweron_timer_start_dummy;

static void OTA_aud_send_play_id_req_dummy(void *id_param) {}
ELL_aud_send_play_id_req OTA_aud_send_play_id_req = OTA_aud_send_play_id_req_dummy;

static kal_status OTA_kal_retrieve_eg_events_dummy(kal_eventgrpid eg_id, kal_uint32 requested_events, kal_uint8 operation,kal_uint32 *retrieved_events, kal_uint32 suspend) {}
ELL_kal_retrieve_eg_events OTA_kal_retrieve_eg_events = OTA_kal_retrieve_eg_events_dummy;

static kal_int16 OTA_gps_uart_read_data_nmea_dummy(module_type module_id, kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed) {}
ELL_gps_uart_read_data_nmea OTA_gps_uart_read_data_nmea = OTA_gps_uart_read_data_nmea_dummy;

static kal_int16 OTA_gps_uart_read_data_dbg_dummy(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed) {}
ELL_gps_uart_read_data_dbg OTA_gps_uart_read_data_dbg = OTA_gps_uart_read_data_dbg_dummy;

static void OTA_track_is_epo_aiding_dummy() {}
ELL_track_is_epo_aiding OTA_track_is_epo_aiding = OTA_track_is_epo_aiding_dummy;

static kal_bool track_custom_fake_cell_feature_enable_dump (kal_uint8 enable){}
ELL_track_custom_fake_cell_feature_enable OTA_track_custom_fake_cell_feature_enable = track_custom_fake_cell_feature_enable_dump ;    


static kal_eventgrpid OTA_kal_create_event_group_dummy(kal_char *eventgrp_name) {}
ELL_kal_create_event_group OTA_kal_create_event_group = OTA_kal_create_event_group_dummy;

static kal_uint8* OTA_ell_play_voice_dummy() {}
ELL_ell_play_voice OTA_ell_play_voice = OTA_ell_play_voice_dummy;

static void OTA_track_ble_bt_status_dummy(kal_uint8 * btstatus){}
ELL_track_ble_bt_status OTA_track_ble_bt_status = OTA_track_ble_bt_status_dummy;

static void OTA_track_ble_set_status_dummy(kal_uint8 * btstatus){}
ELL_track_ble_set_status OTA_track_ble_set_status = OTA_track_ble_set_status_dummy;


static void OTA_acc_sensor_get_6bytes_dummy(kal_uint16 *accl_x,kal_uint16 *accl_y,kal_uint16 *accl_z) {}
ELL_acc_sensor_get_6bytes OTA_acc_sensor_get_6bytes = OTA_acc_sensor_get_6bytes_dummy;

static void OTA_track_sensor_kxtj31057_get_xyz_dummy(short *accl_x,short *accl_y,short *accl_z){}
ELL_track_sensor_kxtj31057_get_xyz OTA_track_sensor_kxtj31057_get_xyz = OTA_track_sensor_kxtj31057_get_xyz_dummy;


static void OTA_aud_send_play_string_req_dummy(void *string_param) {}
ELL_aud_send_play_string_req OTA_aud_send_play_string_req = OTA_aud_send_play_string_req_dummy;

static void OTA_aud_send_stop_string_req_dummy(kal_uint8 src_id) {}
ELL_aud_send_stop_string_req OTA_aud_send_stop_string_req = OTA_aud_send_stop_string_req_dummy;

static kal_uint8 OTA_aud_get_active_audio_mode_dummy(void) {}
ELL_aud_get_active_audio_mode OTA_aud_get_active_audio_mode = OTA_aud_get_active_audio_mode_dummy;

static kal_uint8 OTA_aud_get_volume_level_dummy(kal_uint8 mode, kal_uint8 type) {}
ELL_aud_get_volume_level OTA_aud_get_volume_level = OTA_aud_get_volume_level_dummy;

static void OTA_l4cuem_audio_get_volume_req_dummy(kal_uint8 src_id, kal_uint8 volume_type) {}
ELL_l4cuem_audio_get_volume_req OTA_l4cuem_audio_get_volume_req = OTA_l4cuem_audio_get_volume_req_dummy;

static void OTA_l4cuem_speech_set_mode_req_dummy(kal_bool speech_mode_onoff, kal_uint8 rat_mode) {}
ELL_l4cuem_speech_set_mode_req OTA_l4cuem_speech_set_mode_req = OTA_l4cuem_speech_set_mode_req_dummy;

static void OTA_l4cuem_audio_set_volume_req_dummy(kal_uint8 volume_type, kal_uint8 volume_level) {}
ELL_l4cuem_audio_set_volume_req OTA_l4cuem_audio_set_volume_req = OTA_l4cuem_audio_set_volume_req_dummy;

static void OTA_l4cuem_set_audio_mode_dummy(kal_uint8 mode) {}
ELL_l4cuem_set_audio_mode OTA_l4cuem_set_audio_mode = OTA_l4cuem_set_audio_mode_dummy;

static void OTA_ell_update_soc_nw_attach_ind_dummy(void *msg) {}
ELL_ell_update_soc_nw_attach_ind OTA_ell_update_soc_nw_attach_ind = OTA_ell_update_soc_nw_attach_ind_dummy;

PW_CTRL_POWER_ON_REASON* OTA_gps_PWRon = NULL;

static kal_int8 OTA_ell_update_delete_file_dummy(void) {}
ELLtype_ell_update_delete_file OTA_ell_update_delete_file = OTA_ell_update_delete_file_dummy;


static void OTA_AFE_TurnOffSpeaker_dummy(kal_uint8 aud_func) {}
ELL_AFE_TurnOffSpeaker OTA_AFE_TurnOffSpeaker = OTA_AFE_TurnOffSpeaker_dummy;

static void OTA_L1SP_Speech_Off_dummy(void) {}
ELL_L1SP_Speech_Off OTA_L1SP_Speech_Off = OTA_L1SP_Speech_Off_dummy;

static void OTA_AFE_SetRefresh_dummy(void) {}
ELL_AFE_SetRefresh OTA_AFE_SetRefresh = OTA_AFE_SetRefresh_dummy;

static void OTA_L1SP_MuteSpeaker_dummy(kal_bool mute) {}
ELL_L1SP_MuteSpeaker OTA_L1SP_MuteSpeaker = OTA_L1SP_MuteSpeaker_dummy;

static void OTA_sys_assert_reset_dummy(void) {}
ELL_sys_assert_reset OTA_sys_assert_reset = OTA_sys_assert_reset_dummy;

static void OTA_app_init_complete_callback_dummy(void) {}
ELL_sys_assert_reset OTA_app_init_complete_callback = OTA_app_init_complete_callback_dummy;

kal_bool ELL_l4c_nw_cfun_state_req_dummy(kal_uint8 src_id, kal_uint8 cfun_state) {} //{return 0;}
ELL_l4c_nw_cfun_state_req OTA_l4c_nw_cfun_state_req = ELL_l4c_nw_cfun_state_req_dummy;

void OTA_Media_SetBuffer_dummy(uint16 *buffer, uint32 buf_len){}
ELL_Media_SetBuffer OTA_Media_SetBuffer = OTA_Media_SetBuffer_dummy;

void OTA_Media_SetRBThreshold_dummy( uint16 threshold ){}
ELL_Media_SetRBThreshold OTA_Media_SetRBThreshold = OTA_Media_SetRBThreshold_dummy;

Media_Status OTA_Media_Record_dummy( Media_Format format, void (*media_handler)( Media_Event event ), void *param ){}
ELL_Media_Record OTA_Media_Record = OTA_Media_Record_dummy;

void OTA_Media_Stop_dummy( void ){}
ELL_Media_Stop OTA_Media_Stop = OTA_Media_Stop_dummy;

void OTA_Media_GetReadBuffer_dummy( uint16 **buffer, uint32 *buf_len ){}
ELL_Media_GetReadBuffer OTA_Media_GetReadBuffer = OTA_Media_GetReadBuffer_dummy;

void OTA_Media_ReadDataDone_dummy( uint32 len ){}
ELL_Media_ReadDataDone OTA_Media_ReadDataDone = OTA_Media_ReadDataDone_dummy;

kal_uint32 OTA_app_getcurrtime_dummy(void){}
ELL_app_getcurrtime OTA_app_getcurrtime = OTA_app_getcurrtime_dummy;

kal_int32 OTA_media_aud_play_file_dummy(module_type src_mod_id, void *file_param){}
ELL_media_aud_play_file OTA_media_aud_play_file = OTA_media_aud_play_file_dummy;


static size_t OTA_mbstowcs_dummy(wchar_t* s1, const char* s2, size_t n)
{
    return 0;
}
ELL_mbstowcs OTA_mbstowcs = OTA_mbstowcs_dummy;


static void* OTA_memcpy_dummy(void* s1, const void* s2, size_t n)
{
    return NULL;
}
ELL_memcpy OTA_memcpy = OTA_memcpy_dummy;

static void* OTA_memmove_dummy(void* s1, const void* s2, size_t n)
{
    return NULL;
}
ELL_memmove OTA_memmove = OTA_memmove_dummy;

static char* OTA_strcpy_dummy(char* s1, const char* s2)
{
    return NULL;
}
ELL_strcpy OTA_strcpy = OTA_strcpy_dummy;

static char* OTA_strncpy_dummy(char* s1, const char* s2, size_t n)
{
    return NULL;
}
ELL_strncpy OTA_strncpy = OTA_strncpy_dummy;

static char* OTA_strcat_dummy(char* s1, const char* s2)
{
    return NULL;
}
ELL_strcat OTA_strcat = OTA_strcat_dummy;

static char* OTA_strncat_dummy(char* s1, const char* s2, size_t n)
{
    return NULL;
}
ELL_strncat OTA_strncat = OTA_strncat_dummy;

static int OTA_memcmp_dummy(const void* s1, const void* s2, size_t n)
{
    return NULL;
}
ELL_memcmp OTA_memcmp = OTA_memcmp_dummy;

static int OTA_strcmp_dummy(const char* s1, const char* s2)
{
    return NULL;
}
ELL_strcmp OTA_strcmp = OTA_strcmp_dummy;

static int OTA_strncmp_dummy(const char* s1, const char* s2, size_t n)
{
    return NULL;
}
ELL_strncmp OTA_strncmp = OTA_strncmp_dummy;

static int OTA_strcoll_dummy(const char* s1, const char* s2)
{
    return NULL;
}
ELL_strcoll OTA_strcoll = OTA_strcoll_dummy;

static size_t OTA_strxfrm_dummy(char* s1, const char* s2, size_t n)
{
    return NULL;
}
ELL_strxfrm OTA_strxfrm = OTA_strxfrm_dummy;

static void* OTA_memchr_dummy(void* s1, int c , size_t n)
{
    return NULL;
}
ELL_memchr OTA_memchr = OTA_memchr_dummy;

static char* OTA_strchr_dummy(const char* s1, int c)
{
    return NULL;
}
ELL_strchr OTA_strchr = OTA_strchr_dummy;

static size_t OTA_strcspn_dummy(const char* s1 , const char* s2)
{
    return NULL;
}
ELL_strcspn OTA_strcspn = OTA_strcspn_dummy;

static char* OTA_strpbrk_dummy(const char* s1, const char* s2)
{
    return NULL;
}
ELL_strpbrk OTA_strpbrk = OTA_strpbrk_dummy;

static char* OTA_strrchr_dummy(const char* s1, int c)
{
    return NULL;
}
ELL_strrchr OTA_strrchr = OTA_strrchr_dummy;

static size_t OTA_strspn_dummy(const char* s1, const char* s2)
{
    return NULL;
}
ELL_strspn OTA_strspn = OTA_strspn_dummy;

static char* OTA_strstr_dummy(const char* s1, const char* s2)
{
    return NULL;
}
ELL_strstr OTA_strstr = OTA_strstr_dummy;

static void* OTA_memset_dummy(void* s1, int c , size_t n)
{
    return NULL;
}
ELL_memset OTA_memset = OTA_memset_dummy;

static char* OTA_strerror_dummy(int errnum)
{
    return NULL;
}
ELL_strerror OTA_strerror = OTA_strerror_dummy;

static size_t OTA_strlen_dummy(const char* s)
{
    return NULL;
}
ELL_strlen OTA_strlen = OTA_strlen_dummy;




static float OTA_aeabi_f_dummy(float f1 , float f2)
{
    return 0;
}
ELL_aeabi_f_ff OTA_aeabi_fadd = OTA_aeabi_f_dummy;
ELL_aeabi_f_ff OTA_aeabi_fsub = OTA_aeabi_f_dummy;
ELL_aeabi_f_ff OTA_aeabi_frsub = OTA_aeabi_f_dummy;
ELL_aeabi_f_ff OTA_aeabi_fmul = OTA_aeabi_f_dummy;
ELL_aeabi_f_ff OTA_aeabi_fdiv = OTA_aeabi_f_dummy;


static double OTA_aeabi_d_dd_dummy(double d1 , double d2)
{
    return 0;
}
ELL_aeabi_d_dd OTA_aeabi_dadd = OTA_aeabi_d_dd_dummy;
ELL_aeabi_d_dd OTA_aeabi_dsub = OTA_aeabi_d_dd_dummy;
ELL_aeabi_d_dd OTA_aeabi_drsub = OTA_aeabi_d_dd_dummy;
ELL_aeabi_d_dd OTA_aeabi_dmul = OTA_aeabi_d_dd_dummy;
ELL_aeabi_d_dd OTA_aeabi_ddiv = OTA_aeabi_d_dd_dummy;


static int OTA_aeabi_i_ff_dummy(float f1 , float f2)
{
    return 0;
}
ELL_aeabi_i_ff OTA_aeabi_fcmpeq = OTA_aeabi_i_ff_dummy;
ELL_aeabi_i_ff OTA_aeabi_fcmpge = OTA_aeabi_i_ff_dummy;
ELL_aeabi_i_ff OTA_aeabi_fcmpgt = OTA_aeabi_i_ff_dummy;
ELL_aeabi_i_ff OTA_aeabi_fcmple = OTA_aeabi_i_ff_dummy;
ELL_aeabi_i_ff OTA_aeabi_fcmplt = OTA_aeabi_i_ff_dummy;
ELL_aeabi_i_ff OTA_aeabi_fcmpun = OTA_aeabi_i_ff_dummy;


static void OTA_aeabi_ff_dummy(float f1 , float f2) { }
ELL_aeabi_ff OTA_aeabi_cfcmpeq = OTA_aeabi_ff_dummy;
ELL_aeabi_ff OTA_aeabi_cfcmple = OTA_aeabi_ff_dummy;
ELL_aeabi_ff OTA_aeabi_cfrcmple = OTA_aeabi_ff_dummy;


static int OTA_aeabi_i_dd_dummy(double d1 , double d2)
{
    return 0;
}
ELL_aeabi_i_dd OTA_aeabi_dcmpeq = OTA_aeabi_i_dd_dummy;
ELL_aeabi_i_dd OTA_aeabi_dcmpge = OTA_aeabi_i_dd_dummy;
ELL_aeabi_i_dd OTA_aeabi_dcmpgt = OTA_aeabi_i_dd_dummy;
ELL_aeabi_i_dd OTA_aeabi_dcmple = OTA_aeabi_i_dd_dummy;
ELL_aeabi_i_dd OTA_aeabi_dcmplt = OTA_aeabi_i_dd_dummy;
ELL_aeabi_i_dd OTA_aeabi_dcmpun = OTA_aeabi_i_dd_dummy;


static void OTA_aeabi_dd_dummy(double d1 , double d2) { }
ELL_aeabi_dd OTA_aeabi_cdcmpeq = OTA_aeabi_dd_dummy;
ELL_aeabi_dd OTA_aeabi_cdcmple = OTA_aeabi_dd_dummy;
ELL_aeabi_dd OTA_aeabi_cdrcmple = OTA_aeabi_dd_dummy;



static double OTA_aeabi_f2d_dummy(float f)
{
    return 0;
}
ELL_aeabi_f2d OTA_aeabi_f2d;
static float OTA_aeabi_d2f_dummy(double d)
{
    return 0;
}
ELL_aeabi_d2f OTA_aeabi_d2f = OTA_aeabi_d2f_dummy;
static float OTA_aeabi_i2f_dummy(int i)
{
    return 0;
}
ELL_aeabi_i2f OTA_aeabi_i2f = OTA_aeabi_i2f_dummy;
static float OTA_aeabi_ui2f_dummy(unsigned int i)
{
    return 0;
}
ELL_aeabi_ui2f OTA_aeabi_ui2f = OTA_aeabi_ui2f_dummy;
static double OTA_aeabi_i2d_dummy(int i)
{
    return 0;
}
ELL_aeabi_i2d OTA_aeabi_i2d = OTA_aeabi_i2d_dummy;
static double OTA_aeabi_ui2d_dummy(unsigned int i)
{
    return 0;
}
ELL_aeabi_ui2d OTA_aeabi_ui2d = OTA_aeabi_ui2d_dummy;



static float OTA_aeabi_l2f_dummy(long long l)
{
    return 0;
}
ELL_aeabi_l2f OTA_aeabi_l2f = OTA_aeabi_ui2d_dummy;
static float OTA_aeabi_ul2f_dummy(unsigned long long l)
{
    return 0;
}
ELL_aeabi_ul2f OTA_aeabi_ul2f = OTA_aeabi_ul2f_dummy;
static double OTA_aeabi_l2d_dummy(long long l)
{
    return 0;
}
ELL_aeabi_l2d OTA_aeabi_l2d = OTA_aeabi_l2d_dummy;
static double OTA_aeabi_ul2d_dummy(unsigned long long l)
{
    return 0;
}
ELL_aeabi_ul2d OTA_aeabi_ul2d = OTA_aeabi_ul2d_dummy;



static int OTA_aeabi_f2iz_dummy(float f)
{
    return 0;
}
ELL_aeabi_f2iz OTA_aeabi_f2iz = OTA_aeabi_f2iz_dummy;
static unsigned int OTA_aeabi_f2uiz_dummy(float f)
{
    return 0;
}
ELL_aeabi_f2uiz OTA_aeabi_f2uiz = OTA_aeabi_f2uiz_dummy;
static int OTA_aeabi_d2iz_dummy(double d)
{
    return 0;
}
ELL_aeabi_d2iz OTA_aeabi_d2iz = OTA_aeabi_d2iz_dummy;
static unsigned int OTA_aeabi_d2uiz_dummy(double d)
{
    return 0;
}
ELL_aeabi_d2uiz OTA_aeabi_d2uiz = OTA_aeabi_d2uiz_dummy;


static long long OTA_aeabi_f2lz_dummy(float f)
{
    return 0;
}
ELL_aeabi_f2lz OTA_aeabi_f2lz = OTA_aeabi_f2lz_dummy;
static unsigned long long OTA_aeabi_f2ulz_dummy(float f)
{
    return 0;
}
ELL_aeabi_f2ulz OTA_aeabi_f2ulz = OTA_aeabi_f2ulz_dummy;
static long long OTA_aeabi_d2lz_dummy(double d)
{
    return 0;
}
ELL_aeabi_d2lz OTA_aeabi_d2lz = OTA_aeabi_d2lz_dummy;
static unsigned long long OTA_aeabi_d2ulz_dummy(double d)
{
    return 0;
}
ELL_aeabi_d2ulz OTA_aeabi_d2ulz = OTA_aeabi_d2ulz_dummy;







static double OTA_atof_dummy(const char* nptr)
{
    return 0;
}
ELL_atof OTA_atof = OTA_atof_dummy;
static int OTA_atoi_dummy(const char* nptr)
{
    return 0;
}
ELL_atoi OTA_atoi = OTA_atoi_dummy;
static long int OTA_atol_dummy(const char* nptr)
{
    return 0;
}
ELL_atol OTA_atol = OTA_atol_dummy;

static int OTA_abs_dummy(int i)
{
    return 0;
}
ELL_abs OTA_abs = OTA_abs_dummy;
static long int OTA_labs_dummy(long int i)
{
    return 0;
}
ELL_labs OTA_labs = OTA_labs_dummy;

static double OTA_strtod_dummy(const char * nptr, char** endptr)
{
    return 0;
}
ELL_strtod OTA_strtod = OTA_strtod_dummy;
static float OTA_strtof_dummy(const char * nptr, char** endptr)
{
    return 0;
}
ELL_strtof OTA_strtof = OTA_strtof_dummy;
static long double OTA_strtold_dummy(const char * nptr, char** endptr)
{
    return 0;
}
ELL_strtold OTA_strtold = OTA_strtold_dummy;
static long int OTA_strtol_dummy(const char * nptr, char** endptr, int base)
{
    return 0;
}
ELL_strtol OTA_strtol = OTA_strtol_dummy;
static unsigned long int OTA_strtoul_dummy(const char * nptr, char** endptr, int base)
{
    return 0;
}
ELL_strtoul OTA_strtoul = OTA_strtoul_dummy;


static int OTA_rand_dummy(void)
{
    return 0;
}
ELL_rand OTA_rand = OTA_rand_dummy;
static int OTA_srand_dummy(unsigned int seed)
{
    return 0;
}
ELL_srand OTA_srand = OTA_srand_dummy;

static double OTA_acos_d_d_dummy(double x)
{
    return 0;
}
ELL_acos OTA_acos = OTA_acos_d_d_dummy;
ELL_asin OTA_asin = OTA_acos_d_d_dummy;
ELL_atan OTA_atan = OTA_acos_d_d_dummy;
ELL_cos OTA_cos   = OTA_acos_d_d_dummy;
ELL_sin OTA_sin   = OTA_acos_d_d_dummy;
ELL_tan OTA_tan   = OTA_acos_d_d_dummy;
ELL_cosh OTA_cosh = OTA_acos_d_d_dummy;
ELL_sinh OTA_sinh = OTA_acos_d_d_dummy;
ELL_tanh OTA_tanh = OTA_acos_d_d_dummy;
ELL_exp OTA_exp   = OTA_acos_d_d_dummy;
ELL_sqrt OTA_sqrt = OTA_acos_d_d_dummy;
ELL_ceil OTA_ceil = OTA_acos_d_d_dummy;
ELL_fabs OTA_fabs = OTA_acos_d_d_dummy;
ELL_floor OTA_floor = OTA_acos_d_d_dummy;


static double OTA_atan2_dummy(double y, double x)
{
    return 0;
}
ELL_atan2 OTA_atan2 = OTA_atan2_dummy;
static double OTA_frexp_dummy(double value, int* exp)
{
    return 0;
}
ELL_frexp OTA_frexp = OTA_frexp_dummy;
static double OTA_ldexp_dummy(double x, int exp)
{
    return 0;
}
ELL_ldexp OTA_ldexp = OTA_ldexp_dummy;
static double OTA_modf_dummy(double value, double* iptr)
{
    return 0;
}
ELL_modf OTA_modf = OTA_modf_dummy;

static double OTA_pow_dummy(double x, double y)
{
    return 0;
}
ELL_pow OTA_pow = OTA_pow_dummy;
static double OTA_fmod_dummy(double x, double y)
{
    return 0;
}
ELL_fmod OTA_fmod = OTA_fmod_dummy;




static int OTA_fprintf_dummy(FILE* stream, const char* format, ...)
{
    return 0;
}
ELL_fprintf OTA_fprintf = OTA_fprintf_dummy;
static int OTA_printf_dummy(const char* format, ...)
{
    return 0;
}
ELL_printf OTA_printf = OTA_printf_dummy;
static int OTA_sprintf_dummy(char *str, const char *fmt, ...)
{
    return 0;
}
ELL_sprintf OTA_sprintf = OTA_sprintf_dummy;
static int OTA_snprintf_dummy(char *str, size_t size, const char *fmt, ...)
{
    return 0;
}
ELL_snprintf OTA_snprintf = OTA_snprintf_dummy;
static int OTA_vfprintf_dummy(FILE* stream, const char* format, va_list arg)
{
    return 0;
}
ELL_vfprintf OTA_vfprintf = OTA_vfprintf_dummy;
static int OTA_vprintf_dummy(const char* format, va_list arg)
{
    return 0;
}
ELL_vprintf OTA_vprintf = OTA_vprintf_dummy;
static int OTA_vsprintf_dummy(char *str, const char* format, va_list arg)
{
    return 0;
}
ELL_vsprintf OTA_vsprintf = OTA_vsprintf_dummy;
static int OTA_vsnprintf_dummy(kal_char *str, kal_uint32 size, const kal_char *fmt, va_list ap)
{
    return 0;
}
ELL_vsnprintf OTA_vsnprintf = OTA_vsnprintf_dummy;




/*
 * 16bits string operations
 */
static int OTA_kal_wstrlen_dummy(const WCHAR *wstr)
{
    return 0;
}
ELL_kal_wstrlen OTA_kal_wstrlen = OTA_kal_wstrlen_dummy ;
static WCHAR* OTA_kal_wstrcpy_dummy(WCHAR *to, const WCHAR *from)
{
    return NULL;
}
ELL_kal_wstrcpy OTA_kal_wstrcpy = OTA_kal_wstrcpy_dummy ;
static WCHAR* OTA_kal_wstrncpy_dummy(WCHAR *to, const WCHAR *from, int n)
{
    return NULL;
}
ELL_kal_wstrncpy OTA_kal_wstrncpy = OTA_kal_wstrncpy_dummy ;
static int OTA_kal_wstrcmp_dummy(const WCHAR *s1, const WCHAR *s2)
{
    return NULL;
}
ELL_kal_wstrcmp OTA_kal_wstrcmp = OTA_kal_wstrcmp_dummy ;
static int OTA_kal_wstrncmp_dummy(const WCHAR *s1, const WCHAR *s2, int n)
{
    return NULL;
}
ELL_kal_wstrncmp OTA_kal_wstrncmp = OTA_kal_wstrncmp_dummy ;
static WCHAR* OTA_kal_wstrcat_dummy(WCHAR *s1, const WCHAR *s2)
{
    return NULL;
}
ELL_kal_wstrcat OTA_kal_wstrcat = OTA_kal_wstrcat_dummy ;
static WCHAR* OTA_kal_wstrncat_dummy(WCHAR *s1, const WCHAR *s2, int n)
{
    return NULL;
}
ELL_kal_wstrncat OTA_kal_wstrncat = OTA_kal_wstrncat_dummy ;
static WCHAR* OTA_kal_wstrchr_dummy(const WCHAR *s, int c)
{
    return NULL;
}
ELL_kal_wstrchr OTA_kal_wstrchr = OTA_kal_wstrchr_dummy ;
static WCHAR* OTA_kal_wstrrchr_dummy(const WCHAR *str, int ch)
{
    return NULL;
}
ELL_kal_wstrrchr OTA_kal_wstrrchr = OTA_kal_wstrrchr_dummy ;






/*
 * dual 8bits string operations
 */
static int OTA_kal_dchar_strlen_dummy(const char *wstr)
{
    return 0;
}
ELL_kal_dchar_strlen OTA_kal_dchar_strlen = OTA_kal_dchar_strlen_dummy ;
static char* OTA_kal_dchar_strcpy_dummy(char *to, const char *from)
{
    return NULL;
}
ELL_kal_dchar_strcpy OTA_kal_dchar_strcpy = OTA_kal_dchar_strlen_dummy ;
static char* OTA_kal_dchar_strncpy_dummy(char *to, const char *from, int n)
{
    return NULL;
}
ELL_kal_dchar_strncpy OTA_kal_dchar_strncpy = OTA_kal_dchar_strncpy_dummy ;
static int OTA_kal_dchar_strcmp_dummy(const char *s1, const char *s2)
{
    return 0;
}
ELL_kal_dchar_strcmp OTA_kal_dchar_strcmp = OTA_kal_dchar_strcmp_dummy ;
static int OTA_kal_dchar_strncmp_dummy(const char *s1, const char *s2, int n)
{
    return 0;
}
ELL_kal_dchar_strncmp OTA_kal_dchar_strncmp = OTA_kal_dchar_strncmp_dummy ;
static char* OTA_kal_dchar_strcat_dummy(char *s1, const char *s2)
{
    return NULL;
}
ELL_kal_dchar_strcat OTA_kal_dchar_strcat = OTA_kal_dchar_strcat_dummy ;
static char* OTA_kal_dchar_strncat_dummy(char *s1, const char *s2, int n)
{
    return NULL;
}
ELL_kal_dchar_strncat OTA_kal_dchar_strncat = OTA_kal_dchar_strncat_dummy ;
static char* OTA_kal_dchar_strchr_dummy(const char *s, int c)
{
    return NULL;
}
ELL_kal_dchar_strchr OTA_kal_dchar_strchr = OTA_kal_dchar_strchr_dummy ;
static char* OTA_kal_dchar_strrchr_dummy(const char *str, int ch)
{
    return NULL;
}
ELL_kal_dchar_strrchr OTA_kal_dchar_strrchr = OTA_kal_dchar_strrchr_dummy ;
static void OTA_kal_dchar2char_dummy(WCHAR *outstr, char* tostr) {}
ELL_kal_dchar2char OTA_kal_dchar2char = OTA_kal_dchar2char_dummy ;
static void OTA_kal_wsprintf_dummy(WCHAR *outstr, char *fmt, ...) {}
ELL_kal_wsprintf OTA_kal_wsprintf = OTA_kal_wsprintf_dummy ;



static idiv_return OTA_aeabi_idivmod_dummy(int numerator, int denominator)
{
    idiv_return value = { 0, 0 };
    return value;
}
ELL_aeabi_idivmod OTA_aeabi_idivmod = OTA_aeabi_idivmod_dummy ;
static uidiv_return OTA_aeabi_uidivmod_dummy(unsigned numerator, unsigned denominator)
{
    uidiv_return value = { 0, 0 };
    return value;
}
ELL_aeabi_uidivmod OTA_aeabi_uidivmod = OTA_aeabi_uidivmod_dummy ;


static double OTA_scalbln_dummy(double x, long int n)
{
    return 0;
}
ELL_scalbln OTA_scalbln = OTA_scalbln_dummy;
static double OTA_scalbn_dummy(double x, int n)
{
    return 0;
}
ELL_scalbn OTA_scalbn = OTA_scalbn_dummy;
static float OTA_scalbnf_dummy(float x, int n)
{
    return 0;
}
ELL_scalbnf OTA_scalbnf = OTA_scalbnf_dummy;

static unsigned* OTA_rt_fp_status_addr_dummy(void)
{
    return NULL;
}
ELL_rt_fp_status_addr OTA_rt_fp_status_addr = OTA_rt_fp_status_addr_dummy;

kal_bool * OTA_sds_update_status = NULL;

static signed int ELL_readRawDiskData_dummy(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len) {}
ELL_readRawDiskData OTA_readRawDiskData = ELL_readRawDiskData_dummy;

static signed int ELL_writeRawDiskData_dummy(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len) {}
ELL_writeRawDiskData OTA_writeRawDiskData = ELL_writeRawDiskData_dummy;

static signed int ELL_eraseRawDiskBlock_dummy(NOR_FLASH_DISK_Data *D, kal_uint32 blkIdx) {}
ELL_eraseRawDiskBlock OTA_eraseRawDiskBlock = ELL_eraseRawDiskBlock_dummy;

NOR_FLASH_DISK_Data* OTA_FlashDiskDriveData = NULL;

static  kal_bool ELL_Ell_Update_SDS_Data_dummy(kal_uint8 *data, kal_uint32 data_index,kal_uint32 len,kal_uint8 *md5){}
ELL_Ell_Update_SDS_Data OTA_Ell_Update_SDS_Data = ELL_Ell_Update_SDS_Data_dummy;

static char *ELL_ell_get_iccid_dummy(void){return "";}
ELL_ell_get_iccid OTA_ell_get_iccid = ELL_ell_get_iccid_dummy;



extern void track_main(void);
extern kal_bool track_status_gpstc(kal_uint8 flag);
extern void track_drv_gps_msg_epo_ready(void);
extern void track_drv_push_key_to_buff(kbd_event event, kal_uint8 key);
extern void track_drv_send_keypad_event(void);
extern void track_drv_charge_batter_status(void *msg);
extern void track_drv_charge_batter_status_msg_send(module_type src_mod_id, kal_uint8 battery_status, kal_uint8 battery_level, kal_uint32 volt);
extern kal_bool track_cmd_parse(kal_uint8*cmd_name, void * full_cmd_string);
extern void srv_cbm_app_bearer_info_ind_hdlr(void *info) ;
extern void track_drv_sensor_interrupt_send_msg(void);
extern track_sensor_config_data_struct  track_sensor_config_data;
extern kal_uint8* track_drv_get_imei(kal_uint8 flag);
extern kal_uint8* track_drv_get_imsi(kal_uint8 flag);
extern void track_l4c_cc_call_accept_req_ind(kal_uint8 call_id);
extern void track_l4c_cc_call_connect_lind(l4c_number_struct *num, kal_uint8 call_type, kal_uint8 call_id);

extern void track_l4c_send_msg_track_mmi(msg_type msgtype, void * msg, void * peer_msg);

extern int track_cust_get_rssi(int arg);
extern void track_l4c_cc_exe_ata_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_mode);

extern void track_l4c_cc_exe_call_setup_lrsp(kal_uint8 flag , kal_uint16 cause, kal_uint8 call_id);

extern void track_l4c_sendmsg_call_ring_ind(l4c_number_struct* number, kal_uint8 call_type, kal_uint8 call_id);


extern kal_uint8 track_status_audio_mode(kal_uint8 mode);
extern kal_bool track_sms_send_rsp(kal_int8 result);

extern void track_app_main(ilm_struct *ilm_ptr);
extern void track_rsa_main(ilm_struct * ilm_ptr);

extern void GPS_MSG_NMEA_Decode_req(mtk_gps_position * pvt);

extern void track_at_send_data_rsq(kal_uint8 type, kal_uint8 *data, U16 *len);
extern void track_at_send_msg_ind(void);
extern kal_bool track_atci_at_command_buf(kal_uint8 mode, kal_uint8 *data, kal_uint16 *len);
extern kal_bool track_is_epo_long_data(kal_uint16 leng, char* string);
extern void track_l4c_sendmsg_call_disc_release_lind(kal_uint8 action, kal_uint8 call_id, kal_uint16 cause, kal_uint8 call_type, kal_uint8 diag);
extern void l4c_send_2mmi_sms_new_msg_text_lind(kal_uint16 index,
        kal_uint16 dest_port,
        kal_uint16 src_port,
        kal_uint8 mti,
        kal_uint8 display_type,
        kal_uint8 storage_type,
        smsal_concat_struct *concat_info,
        kal_uint16 message_len,
        void *msg_header,
        void *data);

extern void track_cust_restart(kal_uint8 mode, kal_uint32 sec);

extern char *track_fun_strncpy(char *dec, const char *src, int size);

extern kal_uint8 track_log_switch(kal_uint8 onof);

extern void track_drv_uart_ready_read(void* msg);

extern void track_drv_gps_epo_start(void);

extern void track_trace(char * fmt, int size);
extern kal_uint8 track_get_gps_ota(kal_uint8 flag);
extern kal_uint8 track_drv_uart_log_mode(kal_uint8 par);

int FunAddress[] =
{
    (int)LOGDD,
    (int)LOGS,
    (int)LOGHH,

    (int)track_main,
    (int)track_timer_init,

    (int)track_status_gpstc,
    (int)track_drv_gps_msg_epo_ready,
    (int)track_drv_push_key_to_buff,
    (int)track_drv_send_keypad_event,
    (int)track_drv_charge_batter_status,
    (int)track_drv_charge_batter_status_msg_send,
    (int)track_cmd_parse,
    (int)srv_cbm_app_bearer_info_ind_hdlr,
    (int)tr_start_timer,
    (int)tr_stop_timer,
    (int)track_is_timer_run,
    (int)track_drv_sensor_interrupt_send_msg,
    (int)&track_sensor_config_data,


    (int)track_drv_get_imsi,
    (int)track_l4c_cc_call_accept_req_ind,
    (int)track_l4c_cc_call_connect_lind,
    (int)track_l4c_send_msg_track_mmi,
    (int)track_cust_get_rssi,



    (int)track_l4c_cc_exe_ata_lrsp,
    (int)track_l4c_cc_exe_call_setup_lrsp,
    (int)track_l4c_sendmsg_call_ring_ind,
    (int)track_status_audio_mode,
    (int)track_sms_send_rsp,
    (int)track_app_main,


    (int)GPS_MSG_NMEA_Decode_req,
    (int)track_at_send_data_rsq,
    (int)track_at_send_msg_ind,
    (int)track_atci_at_command_buf,
    (int)track_is_epo_long_data,
    (int)track_l4c_sendmsg_call_disc_release_lind,
    (int)l4c_send_2mmi_sms_new_msg_text_lind,

    (int)track_cust_restart,
    (int)track_log_switch,
    (int)track_drv_uart_ready_read,
    (int)track_drv_gps_epo_start,
    (int)track_trace,
    (int)track_get_gps_ota,
    (int)track_drv_uart_log_mode,
    (int)track_fun_strncpy,
    (int)track_rsa_main,

};




#pragma arm section code = "TRACK_F_CODE"


/*


特别注意----- 不能在本文件内添加功能函数 ，否则将导致OTA APP编译失败

因为要缩小OTA APP的大小，加快加载速度，必须把symtab和strtab节区删除，导致track_os_ell.obj的EllRegister函数在APP的首地址 。
track_os_ell.obj内不能包含其他功能函数代码



MagicNing 2013-11-20


*/

int* EllRegister(int* address , int InLength, int *size)
{
    int i = 0;

    OTA_log2 = (ELL_LOG)(address[i++]) ;
    OTA_GPIO_InitIO = (ELL_GPIO_InitIO)(address[i++]) ;
//    OTA_log ( "OTA_GPIO_InitIO %x \n" , OTA_GPIO_InitIO ) ;


    OTA_GPIO_ModeSetup = (ELL_GPIO_ModeSetup)(address[i++]) ;
//    OTA_log ( "OTA_GPIO_ModeSetup %x \n" , OTA_GPIO_ModeSetup ) ;
    OTA_evshed_set_event = (ELL_evshed_set_event)(address[i++]) ;
//    OTA_log ( "OTA_evshed_set_event %x \n" , OTA_evshed_set_event ) ;
    OTA_evshed_timer_handler = (ELL_evshed_timer_handler)(address[i++]) ;
//    OTA_log ( "OTA_evshed_timer_handler %x \n" , OTA_evshed_timer_handler ) ;
    OTA_FS_Close = (ELL_FS_Close)(address[i++]) ;
//    OTA_log ( "OTA_FS_Close %x \n" , OTA_FS_Close ) ;
    OTA_FS_Commit = (ELL_FS_Commit)(address[i++]) ;
//    OTA_log ( "OTA_FS_Commit %x \n" , OTA_FS_Commit ) ;
    OTA_FS_CreateDir = (ELL_FS_CreateDir)(address[i++]) ;
//    OTA_log ( "OTA_FS_CreateDir %x \n" , OTA_FS_CreateDir ) ;
    OTA_FS_Delete = (ELL_FS_Delete)(address[i++]) ;
//    OTA_log ( "OTA_FS_Delete %x \n" , OTA_FS_Delete ) ;
    OTA_FS_FindFirst = (ELL_FS_FindFirst)(address[i++]) ;
//    OTA_log ( "OTA_FS_FindFirst %x \n" , OTA_FS_FindFirst ) ;



    OTA_FS_FindNext = (ELL_FS_FindNext)(address[i++]) ;
//    OTA_log ( "OTA_FS_FindNext %x \n" , OTA_FS_FindNext ) ;
    OTA_FS_GetDrive = (ELL_FS_GetDrive)(address[i++]) ;
//    OTA_log ( "OTA_FS_GetDrive %x \n" , OTA_FS_GetDrive ) ;
    OTA_FS_GetFileSize = (ELL_FS_GetFileSize)(address[i++]) ;
//    OTA_log ( "OTA_FS_GetFileSize %x \n" , OTA_FS_GetFileSize ) ;
    OTA_FS_GetFolderSize = (ELL_FS_GetFolderSize)(address[i++]) ;
//    OTA_log ( "OTA_FS_GetFolderSize %x \n" , OTA_FS_GetFolderSize ) ;
    OTA_FS_Open = (ELL_FS_Open)(address[i++]) ;
//    OTA_log ( "OTA_FS_Open %x \n" , OTA_FS_Open ) ;
    OTA_FS_Seek = (ELL_FS_Seek)(address[i++]) ;
//    OTA_log ( "OTA_FS_Seek %x \n" , OTA_FS_Seek ) ;
    OTA_FS_Write = (ELL_FS_Write)(address[i++]) ;
//    OTA_log ( "OTA_FS_Write %x \n" , OTA_FS_Write ) ;
    OTA_FS_Read = (ELL_FS_Read)(address[i++]) ;
//    OTA_log ( "OTA_FS_Read %x \n" , OTA_FS_Read ) ;
    OTA_FS_XDelete = (ELL_FS_XDelete)(address[i++]) ;
//    OTA_log ( "OTA_FS_XDelete %x \n" , OTA_FS_XDelete ) ;
    OTA_FS_GeneralFormat = (ELL_FS_GeneralFormat)(address[i++]) ;
//    OTA_log ( "OTA_FS_GeneralFormat %x \n" , OTA_FS_GeneralFormat ) ;



    OTA_FS_GetDiskInfo = (ELL_FS_GetDiskInfo)(address[i++]) ;
//    OTA_log ( "OTA_FS_GetDiskInfo %x \n" , OTA_FS_GetDiskInfo ) ;
    OTA_evshed_create = (ELL_evshed_create)(address[i++]) ;
//    OTA_log ( "OTA_evshed_create %x \n" , OTA_evshed_create ) ;
    OTA_evshed_cancel_event = (ELL_evshed_cancel_event)(address[i++]) ;
//    OTA_log ( "OTA_evshed_cancel_event %x \n" , OTA_evshed_cancel_event ) ;
    OTA_GPIO_ReadIO = (ELL_GPIO_ReadIO)(address[i++]) ;
    OTA_GPIO_ReturnDout = (ELL_GPIO_ReturnDout)(address[i++]) ;

//    OTA_log ( "OTA_GPIO_ReadIO %x \n" , OTA_GPIO_ReadIO ) ;
    OTA_GPIO_WriteIO = (ELL_GPIO_WriteIO)(address[i++]) ;
//    OTA_log ( "OTA_GPIO_WriteIO %x \n" , OTA_GPIO_WriteIO ) ;
    OTA_DclPMU_Close = (ELL_DclPMU_Close)(address[i++]) ;
//    OTA_log ( "OTA_DclPMU_Close %x \n" , OTA_DclPMU_Close ) ;
    OTA_DclPMU_Control = (ELL_DclPMU_Control)(address[i++]) ;
//    OTA_log ( "OTA_DclPMU_Control %x \n" , OTA_DclPMU_Control ) ;
    OTA_DclPMU_Open = (ELL_DclPMU_Open)(address[i++]) ;
//    OTA_log ( "OTA_DclPMU_Open %x \n" , OTA_DclPMU_Open ) ;
    OTA_EINT_Mask = (ELL_EINT_Mask)(address[i++]) ;
//    OTA_log ( "OTA_EINT_Mask %x \n" , OTA_EINT_Mask ) ;
    OTA_EINT_Registration = (ELL_EINT_Registration)(address[i++]) ;
//    OTA_log ( "OTA_EINT_Registration %x \n" , OTA_EINT_Registration ) ;




    OTA_EINT_SW_Debounce_Modify = (ELL_EINT_SW_Debounce_Modify)(address[i++]) ;
//    OTA_log ( "OTA_EINT_SW_Debounce_Modify %x \n" , OTA_EINT_SW_Debounce_Modify ) ;
    OTA_EINT_Set_Sensitivity = (ELL_EINT_Set_Sensitivity)(address[i++]) ;
//    OTA_log ( "OTA_EINT_Set_Sensitivity %x \n" , OTA_EINT_Set_Sensitivity ) ;
    OTA_EINT_Set_Polarity = (ELL_EINT_Set_Polarity)(address[i++]) ;
//    OTA_log ( "OTA_EINT_Set_Polarity %x \n" , OTA_EINT_Set_Polarity ) ;
    OTA_EINT_UnMask = (ELL_EINT_UnMask)(address[i++]) ;
//    OTA_log ( "OTA_EINT_UnMask %x \n" , OTA_EINT_UnMask ) ;
    OTA_DclSerialPort_Control = (ELL_DclSerialPort_Control)(address[i++]) ;
//    OTA_log ( "OTA_DclSerialPort_Control %x \n" , OTA_DclSerialPort_Control ) ;
    OTA_DclSerialPort_Open = (ELL_DclSerialPort_Open)(address[i++]) ;
//    OTA_log ( "OTA_DclSerialPort_Open %x \n" , OTA_DclSerialPort_Open ) ;
    OTA_DclSerialPort_Close = (ELL_DclSerialPort_Close)(address[i++]) ;
//    OTA_log ( "OTA_DclSerialPort_Close %x \n" , OTA_DclSerialPort_Close ) ;

    OTA_kal_adm_alloc_1 = (ELL_kal_adm_alloc_1)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_alloc_1 %x \n" , OTA_kal_adm_alloc_1 ) ;
    OTA_kal_adm_create2 = (ELL_kal_adm_create2)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_create2 %x \n" , OTA_kal_adm_create2 ) ;
    OTA_kal_adm_delete = (ELL_kal_adm_delete)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_delete %x \n" , OTA_kal_adm_delete ) ;
    OTA_kal_adm_free = (ELL_kal_adm_free)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_free %x \n" , OTA_kal_adm_free ) ;
    OTA_kal_adm_get_max_alloc_size = (ELL_kal_adm_get_max_alloc_size)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_get_max_alloc_size %x \n" , OTA_kal_adm_get_max_alloc_size ) ;



    OTA_kal_adm_get_total_left_size = (ELL_kal_adm_get_total_left_size)(address[i++]) ;
//    OTA_log ( "OTA_kal_adm_get_total_left_size %x \n" , OTA_kal_adm_get_total_left_size ) ;


    OTA_kal_create_mutex = (ELL_kal_create_mutex)(address[i++]) ;
//    OTA_log ( "OTA_kal_create_mutex %x \n" , OTA_kal_create_mutex ) ;
    OTA_kal_take_mutex = (ELL_kal_take_mutex)(address[i++]) ;
//    OTA_log ( "OTA_kal_take_mutex %x \n" , OTA_kal_take_mutex ) ;
    OTA_kal_give_mutex = (ELL_kal_give_mutex)(address[i++]) ;
//    OTA_log ( "OTA_kal_give_mutex %x \n" , OTA_kal_give_mutex ) ;
    OTA_soc_close = (ELL_soc_close)(address[i++]) ;
//    OTA_log ( "OTA_soc_close %x \n" , OTA_soc_close ) ;
    OTA_soc_connect = (ELL_soc_connect)(address[i++]) ;
//    OTA_log ( "OTA_soc_connect %x \n" , OTA_soc_connect ) ;
    OTA_soc_create = (ELL_soc_create)(address[i++]) ;
//    OTA_log ( "OTA_soc_create %x \n" , OTA_soc_create ) ;
    OTA_soc_gethostbyname = (ELL_soc_gethostbyname)(address[i++]) ;
//    OTA_log ( "OTA_soc_gethostbyname %x \n" , OTA_soc_gethostbyname ) ;



    OTA_soc_getsockopt = (ELL_soc_getsockopt)(address[i++]) ;
//    OTA_log ( "OTA_soc_getsockopt %x \n" , OTA_soc_getsockopt ) ;
    OTA_soc_recv = (ELL_soc_recv)(address[i++]) ;
//    OTA_log ( "OTA_soc_recv %x \n" , OTA_soc_recv ) ;
    OTA_soc_send = (ELL_soc_send)(address[i++]) ;
//    OTA_log ( "OTA_soc_send %x \n" , OTA_soc_send ) ;
    OTA_soc_setsockopt = (ELL_soc_setsockopt)(address[i++]) ;
//    OTA_log ( "OTA_soc_setsockopt %x \n" , OTA_soc_setsockopt ) ;
    OTA_cbm_encode_data_account_id = (ELL_cbm_encode_data_account_id)(address[i++]) ;
//    OTA_log ( "OTA_cbm_encode_data_account_id %x \n" , OTA_cbm_encode_data_account_id ) ;
    OTA_cbm_get_app_id = (ELL_cbm_get_app_id)(address[i++]) ;
//    OTA_log ( "OTA_cbm_get_app_id %x \n" , OTA_cbm_get_app_id ) ;
    OTA_cbm_register_app_id_with_app_info = (ELL_cbm_register_app_id_with_app_info)(address[i++]) ;
//    OTA_log ( "OTA_cbm_register_app_id_with_app_info %x \n" , OTA_cbm_register_app_id_with_app_info ) ;
    OTA_kal_cancel_timer = (ELL_kal_cancel_timer)(address[i++]) ;
//    OTA_log ( "OTA_kal_cancel_timer %x \n" , OTA_kal_cancel_timer ) ;
    OTA_kal_create_timer = (ELL_kal_create_timer)(address[i++]) ;
//    OTA_log ( "OTA_kal_create_timer %x \n" , OTA_kal_create_timer ) ;
    OTA_kal_set_timer = (ELL_kal_set_timer)(address[i++]) ;
//    OTA_log ( "OTA_kal_set_timer %x \n" , OTA_kal_set_timer ) ;



    OTA_track_net_get_apn = (ELL_track_net_get_apn)(address[i++]) ;
//    OTA_log ( "OTA_track_net_get_apn %x \n" , OTA_track_net_get_apn ) ;
//    OTA_track_bmt_adc_measure_req = (ELL_track_bmt_adc_measure_req ) (address[i++]) ;
//    OTA_log ( "OTA_track_bmt_adc_measure_req %x \n" , OTA_track_bmt_adc_measure_req ) ;
//    OTA_track_chr_adc_temp_count = (ELL_track_chr_adc_temp_count ) (address[i++]) ;
//    OTA_log ( "OTA_track_chr_adc_temp_count %x \n" , OTA_track_chr_adc_temp_count ) ;
//    OTA_track_get_adc_data = (ELL_track_get_adc_data ) (address[i++]) ;
//    OTA_log ( "OTA_track_get_adc_data %x \n" , OTA_track_get_adc_data ) ;
    OTA_allocate_ilm = (ELL_allocate_ilm)(address[i++]) ;
//    OTA_log ( "OTA_allocate_ilm %x \n" , OTA_allocate_ilm ) ;
    OTA_construct_int_local_para_1 = (ELL_construct_int_local_para_1)(address[i++]) ;
//    OTA_log ( "OTA_construct_int_local_para_1 %x \n" , OTA_construct_int_local_para_1 ) ;
    OTA_msg_send_ext_queue = (ELL_msg_send_ext_queue)(address[i++]) ;
//    OTA_log ( "OTA_msg_send_ext_queue %x \n" , OTA_msg_send_ext_queue ) ;

    OTA_build_date_time = (ELL_build_date_time)(address[i++]) ;
//    OTA_log ( "OTA_build_date_time %x \n" , OTA_build_date_time ) ;

    OTA_release_verno = (ELL_release_verno)(address[i++]) ;
//    OTA_log ( "OTA_release_verno %x \n" , OTA_release_verno ) ;
    OTA_U_PutUARTBytes = (ELL_U_PutUARTBytes)(address[i++]) ;
//    OTA_log ( "OTA_U_PutUARTBytes %x \n" , OTA_U_PutUARTBytes ) ;
    OTA_app_ucs2_strlen = (ELL_app_ucs2_strlen)(address[i++]) ;
//    OTA_log ( "OTA_app_ucs2_strlen %x \n" , OTA_app_ucs2_strlen ) ;
    OTA_applib_dt_get_rtc_time = (ELL_applib_dt_get_rtc_time)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_get_rtc_time %x \n" , OTA_applib_dt_get_rtc_time ) ;
    OTA_applib_get_time_difference_ext_in_second = (ELL_applib_get_time_difference_ext_in_second)(address[i++]) ;
//    OTA_log ( "OTA_applib_get_time_difference_ext_in_second %x \n" , OTA_applib_get_time_difference_ext_in_second ) ;
    OTA_app_asc_str_n_to_ucs2_str = (ELL_app_asc_str_n_to_ucs2_str)(address[i++]) ;
//    OTA_log ( "OTA_app_asc_str_n_to_ucs2_str %x \n" , OTA_app_asc_str_n_to_ucs2_str ) ;
    OTA_app_ucs2_str_n_to_asc_str = (ELL_app_ucs2_str_n_to_asc_str)(address[i++]) ;
//    OTA_log ( "OTA_app_ucs2_str_n_to_asc_str %x \n" , OTA_app_ucs2_str_n_to_asc_str ) ;
    OTA_mmi_chset_convert_ex = (ELL_mmi_chset_convert_ex)(address[i++]) ;
//    OTA_log ( "OTA_mmi_chset_convert_ex %x \n" , OTA_mmi_chset_convert_ex ) ;
    OTA_mtk_gps_sys_storage_clear = (ELL_mtk_gps_sys_storage_clear)(address[i++]) ;
//    OTA_log ( "OTA_mtk_gps_sys_storage_clear %x \n" , OTA_mtk_gps_sys_storage_clear ) ;
    OTA_check_sim_card_status = (ELL_check_sim_card_status)(address[i++]) ;
//    OTA_log ( "OTA_check_sim_card_status %x \n" , OTA_check_sim_card_status ) ;



    OTA_app_ucs2_strcat = (ELL_app_ucs2_strcat)(address[i++]) ;
//    OTA_log ( "OTA_app_ucs2_strcat %x \n" , OTA_app_ucs2_strcat ) ;
    OTA_app_ucs2_strcpy = (ELL_app_ucs2_strcpy)(address[i++]) ;
//    OTA_log ( "OTA_app_ucs2_strcpy %x \n" , OTA_app_ucs2_strcpy ) ;
    OTA_applib_dt_decrease_time = (ELL_applib_dt_decrease_time)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_decrease_time %x \n" , OTA_applib_dt_decrease_time ) ;
    OTA_applib_dt_increase_time = (ELL_applib_dt_increase_time)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_increase_time %x \n" , OTA_applib_dt_increase_time ) ;
    OTA_uem_drv_power_on = (ELL_uem_drv_power_on)(address[i++]) ;
//    OTA_log ( "OTA_uem_drv_power_on %x \n" , OTA_uem_drv_power_on ) ;
    OTA_uem_drv_power_off = (ELL_uem_drv_power_off)(address[i++]) ;
//    OTA_log ( "OTA_uem_drv_power_off %x \n" , OTA_uem_drv_power_off ) ;
    OTA_L1SM_SleepEnable = (ELL_L1SM_SleepEnable)(address[i++]) ;
//    OTA_log ( "OTA_L1SM_SleepEnable %x \n" , OTA_L1SM_SleepEnable ) ;
    OTA_L1SM_SleepDisable = (ELL_L1SM_SleepDisable)(address[i++]) ;
//    OTA_log ( "OTA_L1SM_SleepDisable %x \n" , OTA_L1SM_SleepDisable ) ;
    OTA_mtk_gps_set_param = (ELL_mtk_gps_set_param)(address[i++]) ;
//    OTA_log ( "OTA_mtk_gps_set_param %x \n" , OTA_mtk_gps_set_param ) ;
    OTA_mtk_gps_get_param = (ELL_mtk_gps_get_param)(address[i++]) ;
//    OTA_log ( "OTA_mtk_gps_get_param %x \n" , OTA_mtk_gps_get_param ) ;



    OTA_kal_prompt_trace = (ELL_kal_prompt_trace)(address[i++]) ;
//    OTA_log ( "OTA_kal_prompt_trace %x \n" , OTA_kal_prompt_trace ) ;
    OTA_l4csmu_get_imsi = (ELL_l4csmu_get_imsi)(address[i++]) ;
//    OTA_log ( "OTA_l4csmu_get_imsi %x \n" , OTA_l4csmu_get_imsi ) ;

    OTA_track_sensor_bma250_off = (ELL_track_sensor_bma250_off)(address[i++]) ;
//    OTA_log ( "OTA_track_sensor_bma250_off %x \n" , OTA_track_sensor_bma250_off ) ;
    OTA_track_sensor_bma250_on = (ELL_track_sensor_bma250_on)(address[i++]) ;
//    OTA_log ( "OTA_track_sensor_bma250_on %x \n" , OTA_track_sensor_bma250_on ) ;
    OTA_track_sensor_bma250_type_check = (ELL_track_sensor_bma250_type_check)(address[i++]) ;
//    OTA_log ( "OTA_track_sensor_bma250_type_check %x \n" , OTA_track_sensor_bma250_type_check ) ;

    OTA_track_sensor_kxtj31057_off = (ELL_track_sensor_kxtj31057_off)(address[i++]) ;
    OTA_track_sensor_kxtj31057_on = (ELL_track_sensor_kxtj31057_on)(address[i++]) ;
    OTA_track_sensor_kxtj31057_type_check = (ELL_track_sensor_kxtj31057_type_check)(address[i++]) ;

    OTA_track_sensor_sc7a20_off = (ELL_track_sensor_sc7a20_off)(address[i++]) ;
    OTA_track_sensor_sc7a20_on = (ELL_track_sensor_sc7a20_on)(address[i++]) ;
    OTA_track_sensor_sc7a20_type_check = (ELL_track_sensor_sc7a20_type_check)(address[i++]) ;

    OTA_track_sensor_da213_off = (ELL_track_sensor_da213_off)(address[i++]) ;
    OTA_track_sensor_da213_on = (ELL_track_sensor_da213_on)(address[i++]) ;
    OTA_track_sensor_da213_type_check = (ELL_track_sensor_da213_type_check)(address[i++]) ;
    
    OTA_RTC_GetTimeOnly = (ELL_RTC_GetTimeOnly)(address[i++]) ;
//    OTA_log ( "OTA_RTC_GetTimeOnly %x \n" , OTA_RTC_GetTimeOnly ) ;
    OTA_pmu_drv_bl_isink = (ELL_pmu_drv_bl_isink)(address[i++]) ;
//    OTA_log ( "OTA_pmu6250_bl_isink %x \n" , OTA_pmu6250_bl_isink ) ;
    OTA_DclSADC_Control = (ELL_DclSADC_Control)(address[i++]) ;
//    OTA_log ( "OTA_DclSADC_Control %x \n" , OTA_DclSADC_Control ) ;
    OTA_DclSADC_Open = (ELL_DclSADC_Open)(address[i++]) ;
//    OTA_log ( "OTA_DclSADC_Open %x \n" , OTA_DclSADC_Open ) ;
    OTA_L1SM_GetHandle  = (ELL_L1SM_GetHandle)(address[i++]) ;
//    OTA_log ( "OTA_L1SM_GetHandle %x \n" , OTA_L1SM_GetHandle ) ;
    OTA_RTC_InitTC_Time  = (ELL_RTC_InitTC_Time)(address[i++]) ;
//    OTA_log ( "OTA_RTC_InitTC_Time %x \n" , OTA_RTC_InitTC_Time ) ;



    OTA_SST_Get_ChipRID  = (ELL_SST_Get_ChipRID)(address[i++]) ;
//    OTA_log ( "OTA_SST_Get_ChipRID %x \n" , OTA_SST_Get_ChipRID ) ;
    OTA_nvram_external_read_data  = (ELL_nvram_external_read_data)(address[i++]) ;
//    OTA_log ( "OTA_nvram_external_read_data %x \n" , OTA_nvram_external_read_data ) ;
    OTA_nvram_external_write_data  = (ELL_nvram_external_write_data)(address[i++]) ;
//    OTA_log ( "OTA_nvram_external_write_data %x \n" , OTA_nvram_external_write_data ) ;
    OTA_PS_UART_PORT = (UART_PORT*)(address[i++]) ;
//    OTA_log ( "OTA_PS_UART_PORT %x \n" , OTA_PS_UART_PORT ) ;
//    OTA_log ( "OTA_NVRAM_EF_PARAMETER_DEFAULT %x \n" , OTA_NVRAM_EF_PARAMETER_DEFAULT ) ;
    OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT = (nvram_gps_backup_data_param_struct*)(address[i++]) ;
//    OTA_log ( "OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT %x \n" , OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT ) ;
//    OTA_log ( "OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT %x \n" , OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT ) ;
//    OTA_log ( "OTA_NVRAM_EF_REALTIME_DEFAULT %x \n" , OTA_NVRAM_EF_REALTIME_DEFAULT ) ;
    OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT = (kal_uint8*)(address[i++]) ;
//    OTA_log ( "OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT %x \n" , OTA_NVRAM_EF_IMEI_IMEISV_DEFAULT ) ;
    OTA_DEFAULT_HARDWARE_YEAR = (kal_uint8*)(address[i++]) ;
//    OTA_log ( "OTA_DEFAULT_HARDWARE_YEAR %x \n" , OTA_DEFAULT_HARDWARE_YEAR ) ;



    OTA_DEFAULT_HARDWARE_MON = (kal_uint8*)(address[i++]) ;
//    OTA_log ( "OTA_DEFAULT_HARDWARE_MON %x \n" , OTA_DEFAULT_HARDWARE_MON ) ;
    OTA_DEFAULT_HARDWARE_DAY = (kal_uint8*)(address[i++]) ;
//    OTA_log ( "OTA_DEFAULT_HARDWARE_DAY %x \n" , OTA_DEFAULT_HARDWARE_DAY ) ;


    OTA_NVRAM_EF_PORT_SETTING_DEFAULT = (port_setting_struct*)(address[i++]) ;
//    OTA_log ( "OTA_NVRAM_EF_PORT_SETTING_DEFAULT %x \n" , OTA_NVRAM_EF_PORT_SETTING_DEFAULT ) ;
//    OTA_log ( "OTA_NVRAM_EF_PHONE_NUMBER_DEFAULT %x \n" , OTA_NVRAM_EF_PHONE_NUMBER_DEFAULT ) ;
//    OTA_log ( "OTA_NVRAM_EF_LOGD_DEFAULT %x \n" , OTA_NVRAM_EF_LOGD_DEFAULT ) ;


    OTA_kal_ticks_to_secs = (ELL_kal_ticks_to_secs)(address[i++]) ;
//    OTA_log ( "OTA_kal_ticks_to_secs %x \n" , OTA_kal_ticks_to_secs ) ;
    OTA_kal_get_systicks = (ELL_kal_get_systicks)(address[i++]) ;
//    OTA_log ( "OTA_kal_get_systicks %x \n" , OTA_kal_get_systicks ) ;
    OTA_kal_secs_to_ticks = (ELL_kal_secs_to_ticks)(address[i++]) ;
//    OTA_log ( "OTA_kal_secs_to_ticks %x \n" , OTA_kal_secs_to_ticks ) ;
    OTA_kal_ticks_to_milli_secs = (ELL_kal_ticks_to_milli_secs)(address[i++]) ;
//    OTA_log ( "OTA_kal_ticks_to_milli_secs %x \n" , OTA_kal_ticks_to_milli_secs ) ;


    OTA_kal_get_active_module_id = (ELL_kal_get_active_module_id)(address[i++]) ;
//    OTA_log ( "OTA_kal_get_active_module_id %x \n" , OTA_kal_get_active_module_id ) ;
    OTA_convert_to_general_digit = (ELL_convert_to_general_digit)(address[i++]) ;
//    OTA_log ( "OTA_convert_to_general_digit %x \n" , OTA_convert_to_general_digit ) ;
    OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii = (ELL_l4c_ConvertGSM7BitDefaultEncodingToAscii)(address[i++]) ;
//    OTA_log ( "OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii %x \n" , OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii ) ;
    OTA_smsal_gsm7_unpack = (ELL_smsal_gsm7_unpack)(address[i++]) ;
//    OTA_log ( "OTA_smsal_gsm7_unpack %x \n" , OTA_smsal_gsm7_unpack ) ;
    OTA_smsal_msg_len_in_character = (ELL_smsal_msg_len_in_character)(address[i++]) ;
//    OTA_log ( "OTA_smsal_msg_len_in_character %x \n" , OTA_smsal_msg_len_in_character ) ;
    OTA_applib_dt_compare_time = (ELL_applib_dt_compare_time)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_compare_time %x \n" , OTA_applib_dt_compare_time ) ;
    OTA_l4cuem_power_off_req = (ELL_l4cuem_power_off_req)(address[i++]) ;
//    OTA_log ( "OTA_l4cuem_power_off_req %x \n" , OTA_l4cuem_power_off_req ) ;
    OTA_uem_get_bat_status = (ELL_uem_get_bat_status)(address[i++]) ;
//    OTA_log ( "OTA_uem_get_bat_status %x \n" , OTA_uem_get_bat_status ) ;
    OTA_uem_get_vbat_percentage = (ELL_uem_get_vbat_percentage)(address[i++]) ;
//    OTA_log ( "OTA_uem_get_vbat_percentage %x \n" , OTA_uem_get_vbat_percentage ) ;
    OTA_mmi_chset_utf16_strlen = (ELL_mmi_chset_utf16_strlen)(address[i++]) ;
//    OTA_log ( "OTA_mmi_chset_utf16_strlen %x \n" , OTA_mmi_chset_utf16_strlen ) ;
    OTA_applib_dt_mytime_2_utc_sec = (ELL_applib_dt_mytime_2_utc_sec)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_mytime_2_utc_sec %x \n" , OTA_applib_dt_mytime_2_utc_sec ) ;
    OTA_applib_dt_mytime_2_utc_sec_ext = (ELL_applib_dt_mytime_2_utc_sec_ext)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_mytime_2_utc_sec_ext %x \n" , OTA_applib_dt_mytime_2_utc_sec_ext ) ;
    OTA_applib_dt_utc_sec_2_mytime = (ELL_applib_dt_utc_sec_2_mytime)(address[i++]) ;
//    OTA_log ( "OTA_applib_dt_utc_sec_2_mytime %x \n" , OTA_applib_dt_utc_sec_2_mytime ) ;
    OTA_track_gps_hour_to_utc = (ELL_track_gps_hour_to_utc)(address[i++]) ;
//    OTA_log ( "OTA_track_gps_hour_to_utc %x \n" , OTA_track_gps_hour_to_utc ) ;



    OTA_DRV_RESET = (ELL_DRV_RESET)(address[i++]) ;
//    OTA_log ( "OTA_DRV_RESET %x \n" , OTA_DRV_RESET ) ;
    OTA_INT_MemoryDumpFlag = (kal_uint32*)(address[i++]) ;
//    OTA_log ( "OTA_INT_MemoryDumpFlag %x \n" , OTA_INT_MemoryDumpFlag ) ;


    OTA_PCM2WAY_Start = (ELL_PCM2WAY_Start)(address[i++]) ;
//    OTA_log ( "OTA_PCM2WAY_Start %x \n" , OTA_PCM2WAY_Start ) ;
    OTA_PCM2WAY_Stop = (ELL_PCM2WAY_Stop)(address[i++]) ;
//    OTA_log ( "OTA_PCM2WAY_Stop %x \n" , OTA_PCM2WAY_Stop ) ;
    OTA_PCM2WAY_GetFromMic = (ELL_PCM2WAY_GetFromMic)(address[i++]) ;
//    OTA_log ( "OTA_PCM2WAY_GetFromMic %x \n" , OTA_PCM2WAY_GetFromMic ) ;


    OTA_track_bmt_get_ADC_result = (ELL_track_bmt_get_ADC_result)(address[i++]) ;
//    OTA_log ( "OTA_track_bmt_get_ADC_result %x \n" , OTA_track_bmt_get_ADC_result ) ;
    OTA_track_bmt_vol_reset_setatus = (ELL_track_bmt_vol_reset_setatus)(address[i++]) ;
//    OTA_log ( "OTA_track_bmt_vol_reset_setatus %x \n" , OTA_track_bmt_vol_reset_setatus ) ;


    OTA_applib_md5_init = (ELL_applib_md5_init)(address[i++]);
//    OTA_log ( "OTA_applib_md5_init %x \n" , OTA_applib_md5_init ) ;
    OTA_applib_md5_update = (ELL_applib_md5_update)(address[i++]);
//    OTA_log ( "OTA_applib_md5_update %x \n" , OTA_applib_md5_update ) ;
    OTA_applib_md5_final = (ELL_applib_md5_final)(address[i++]);
//    OTA_log ( "OTA_applib_md5_final %x \n" , OTA_applib_md5_final ) ;
    OTA_compress_decode = (ELL_compress_decode)(address[i++]);
//    OTA_log ( "OTA_compress_decode %x \n" , OTA_compress_decode ) ;
    OTA_compress_encode = (ELL_compress_encode)(address[i++]);
//    OTA_log ( "OTA_compress_encode %x \n" , OTA_compress_encode ) ;
    OTA_track_fun_decryption = (ELL_track_fun_decryption)(address[i++]);
//    OTA_log ( "OTA_track_fun_decryption %x \n" , OTA_track_fun_decryption ) ;


    OTA_l4c_sms_exe_post_msg_req = (ELL_l4c_sms_exe_post_msg_req)(address[i++]);
//    OTA_log ( "OTA_l4c_sms_exe_post_msg_req %x \n" , OTA_l4c_sms_exe_post_msg_req ) ;
    OTA_l4c_sms_exe_post_pdu_req = (ELL_l4c_sms_exe_post_pdu_req)(address[i++]);
//    OTA_log ( "OTA_l4c_sms_exe_post_pdu_req %x \n" , OTA_l4c_sms_exe_post_pdu_req ) ;
    OTA_l4cuem_power_reset = (ELL_l4cuem_power_reset)(address[i++]);
//    OTA_log ( "OTA_l4cuem_power_reset %x \n" , OTA_l4cuem_power_reset ) ;
    OTA_uem_poweron_timer_start = (ELL_uem_poweron_timer_start)(address[i++]);
//    OTA_log ( "OTA_uem_poweron_timer_start %x \n" , OTA_uem_poweron_timer_start ) ;



    OTA_aud_send_play_id_req = (ELL_aud_send_play_id_req)(address[i++]);
//    OTA_log ( "OTA_aud_send_play_id_req %x \n" , OTA_aud_send_play_id_req ) ;
    OTA_aud_send_play_string_req = (ELL_aud_send_play_string_req)(address[i++]);
//    OTA_log ( "OTA_aud_send_play_string_req %x \n" , OTA_aud_send_play_string_req ) ;
    OTA_aud_send_stop_string_req = (ELL_aud_send_stop_string_req)(address[i++]);
//    OTA_log ( "OTA_aud_send_stop_string_req %x \n" , OTA_aud_send_stop_string_req ) ;
    OTA_aud_get_active_audio_mode = (ELL_aud_get_active_audio_mode)(address[i++]);
//    OTA_log ( "OTA_aud_get_active_audio_mode %x \n" , OTA_aud_get_active_audio_mode ) ;
    OTA_aud_get_volume_level = (ELL_aud_get_volume_level)(address[i++]);
//    OTA_log ( "OTA_aud_get_volume_level %x \n" , OTA_aud_get_volume_level ) ;
    OTA_l4cuem_audio_get_volume_req = (ELL_l4cuem_audio_get_volume_req)(address[i++]);
//    OTA_log ( "OTA_l4cuem_audio_get_volume_req %x \n" , OTA_l4cuem_audio_get_volume_req ) ;
    OTA_l4cuem_speech_set_mode_req = (ELL_l4cuem_speech_set_mode_req)(address[i++]);
//    OTA_log ( "OTA_l4cuem_speech_set_mode_req %x \n" , OTA_l4cuem_speech_set_mode_req ) ;
    OTA_l4cuem_audio_set_volume_req = (ELL_l4cuem_audio_set_volume_req)(address[i++]);
//    OTA_log ( "OTA_l4cuem_audio_set_volume_req %x \n" , OTA_l4cuem_audio_set_volume_req ) ;
    OTA_l4cuem_set_audio_mode = (ELL_l4cuem_set_audio_mode)(address[i++]);
//    OTA_log ( "OTA_l4cuem_set_audio_mode %x \n" , OTA_l4cuem_set_audio_mode ) ;

    OTA_ell_update_soc_nw_attach_ind = (ELL_ell_update_soc_nw_attach_ind)(address[i++]);
//    OTA_log ( "OTA_ell_update_soc_nw_attach_ind %x \n" , OTA_ell_update_soc_nw_attach_ind ) ;

    OTA_gps_PWRon = (PW_CTRL_POWER_ON_REASON*)(address[i++]);
//    OTA_log ( "OTA_gps_PWRon %x \n" , OTA_gps_PWRon ) ;

    OTA_ell_update_delete_file = (ELLtype_ell_update_delete_file)(address[i++]);
//    OTA_log ( "OTA_ell_update_soc_nw_attach_ind %x \n" , OTA_ell_update_soc_nw_attach_ind ) ;



    OTA_AFE_TurnOffSpeaker = (ELL_AFE_TurnOffSpeaker)(address[i++]);
//    OTA_log ( "OTA_AFE_TurnOffSpeaker %x \n" , OTA_AFE_TurnOffSpeaker ) ;
    OTA_L1SP_Speech_Off = (ELL_L1SP_Speech_Off)(address[i++]);
//    OTA_log ( "OTA_L1SP_Speech_Off %x \n" , OTA_L1SP_Speech_Off ) ;
    OTA_AFE_SetRefresh = (ELL_AFE_SetRefresh)(address[i++]);
//    OTA_log ( "OTA_AFE_SetRefresh %x \n" , OTA_AFE_SetRefresh ) ;
    OTA_L1SP_MuteSpeaker = (ELL_L1SP_MuteSpeaker)(address[i++]);
//    OTA_log ( "OTA_L1SP_MuteSpeaker %x \n" , OTA_L1SP_MuteSpeaker ) ;

    OTA_sys_assert_reset = (ELL_sys_assert_reset)(address[i++]);
//    OTA_log ( "OTA_sys_assert_reset %x \n" , OTA_sys_assert_reset ) ;

    OTA_app_init_complete_callback = (ELL_sys_assert_reset)(address[i++]);
//    OTA_log ( "OTA_app_init_complete_callback %x \n" , OTA_app_init_complete_callback ) ;

    OTA_l4c_nw_cfun_state_req = (ELL_l4c_nw_cfun_state_req)address[i++];
//        EllLog ( "OTA_l4c_nw_cfun_state_req %x \n" , OTA_l4c_nw_cfun_state_req ) ;

    OTA_ASSERT = (ELL_ASSERT)address[i++];
//        EllLog ( "OTA_ASSERT %x \n" , OTA_ASSERT ) ;

    OTA_memcpy = (ELL_memcpy)address[i++];
    OTA_memmove = (ELL_memmove)address[i++];
    OTA_strcpy = (ELL_strcpy)address[i++];
    OTA_strncpy = (ELL_strncpy)address[i++];
    OTA_strcat = (ELL_strcat)address[i++];
    OTA_strncat = (ELL_strncat)address[i++];
    OTA_memcmp = (ELL_memcmp)address[i++];
    OTA_strcmp = (ELL_strcmp)address[i++];
    OTA_strncmp = (ELL_strncmp)address[i++];
    OTA_strcoll = (ELL_strcoll)address[i++];
    OTA_strxfrm = (ELL_strxfrm)address[i++];
    OTA_memchr = (ELL_memchr)address[i++];
    OTA_strchr = (ELL_strchr)address[i++];
    OTA_strcspn = (ELL_strcspn)address[i++];
    OTA_strpbrk = (ELL_strpbrk)address[i++];
    OTA_strrchr = (ELL_strrchr)address[i++];
    OTA_strspn = (ELL_strspn)address[i++];
    OTA_strstr = (ELL_strstr)address[i++];
    OTA_memset = (ELL_memset)address[i++];
    OTA_strerror = (ELL_strerror)address[i++];
    OTA_strlen = (ELL_strlen)address[i++];


    OTA_aeabi_fadd = (ELL_aeabi_f_ff)address[i++];
    OTA_aeabi_fsub = (ELL_aeabi_f_ff)address[i++];
    OTA_aeabi_frsub = (ELL_aeabi_f_ff)address[i++];
    OTA_aeabi_fmul = (ELL_aeabi_f_ff)address[i++];
    OTA_aeabi_fdiv = (ELL_aeabi_f_ff)address[i++];


    OTA_aeabi_dadd = (ELL_aeabi_d_dd)address[i++];
    OTA_aeabi_dsub = (ELL_aeabi_d_dd)address[i++];
    OTA_aeabi_drsub = (ELL_aeabi_d_dd)address[i++];
    OTA_aeabi_dmul = (ELL_aeabi_d_dd)address[i++];
    OTA_aeabi_ddiv = (ELL_aeabi_d_dd)address[i++];


    OTA_aeabi_fcmpeq = (ELL_aeabi_i_ff)address[i++];
    OTA_aeabi_fcmpge = (ELL_aeabi_i_ff)address[i++];
    OTA_aeabi_fcmpgt = (ELL_aeabi_i_ff)address[i++];
    OTA_aeabi_fcmple = (ELL_aeabi_i_ff)address[i++];
    OTA_aeabi_fcmplt = (ELL_aeabi_i_ff)address[i++];
    OTA_aeabi_fcmpun = (ELL_aeabi_i_ff)address[i++];


    OTA_aeabi_cfcmpeq = (ELL_aeabi_ff)address[i++];
    OTA_aeabi_cfcmple = (ELL_aeabi_ff)address[i++];
    OTA_aeabi_cfrcmple = (ELL_aeabi_ff)address[i++];


    OTA_aeabi_dcmpeq = (ELL_aeabi_i_dd)address[i++];
    OTA_aeabi_dcmpge = (ELL_aeabi_i_dd)address[i++];
    OTA_aeabi_dcmpgt = (ELL_aeabi_i_dd)address[i++];
    OTA_aeabi_dcmple = (ELL_aeabi_i_dd)address[i++];
    OTA_aeabi_dcmplt = (ELL_aeabi_i_dd)address[i++];
    OTA_aeabi_dcmpun = (ELL_aeabi_i_dd)address[i++];


    OTA_aeabi_cdcmpeq = (ELL_aeabi_dd)address[i++];
    OTA_aeabi_cdcmple = (ELL_aeabi_dd)address[i++];
    OTA_aeabi_cdrcmple = (ELL_aeabi_dd)address[i++];


    OTA_aeabi_f2d = (ELL_aeabi_f2d)address[i++];
    OTA_aeabi_d2f = (ELL_aeabi_d2f)address[i++];
    OTA_aeabi_i2f = (ELL_aeabi_i2f)address[i++];
    OTA_aeabi_ui2f = (ELL_aeabi_ui2f)address[i++];
    OTA_aeabi_i2d = (ELL_aeabi_i2d)address[i++];
    OTA_aeabi_ui2d = (ELL_aeabi_ui2d)address[i++];



    OTA_aeabi_l2f = (ELL_aeabi_l2f)address[i++];
    OTA_aeabi_ul2f = (ELL_aeabi_ul2f)address[i++];
    OTA_aeabi_l2d = (ELL_aeabi_l2d)address[i++];
    OTA_aeabi_ul2d = (ELL_aeabi_ul2d)address[i++];


    OTA_aeabi_f2iz = (ELL_aeabi_f2iz)address[i++];
    OTA_aeabi_f2uiz = (ELL_aeabi_f2uiz)address[i++];
    OTA_aeabi_d2iz = (ELL_aeabi_d2iz)address[i++];
    OTA_aeabi_d2uiz = (ELL_aeabi_d2uiz)address[i++];

    OTA_aeabi_f2lz = (ELL_aeabi_f2lz)address[i++];
    OTA_aeabi_f2ulz = (ELL_aeabi_f2ulz)address[i++];
    OTA_aeabi_d2lz = (ELL_aeabi_d2lz)address[i++];
    OTA_aeabi_d2ulz = (ELL_aeabi_d2ulz)address[i++];




    OTA_atof = (ELL_atof)address[i++];
    OTA_atoi = (ELL_atoi)address[i++];
    OTA_atol = (ELL_atol)address[i++];
    OTA_abs = (ELL_abs)address[i++];
    OTA_labs = (ELL_labs)address[i++];

    OTA_strtod = (ELL_strtod)address[i++];
    OTA_strtof = (ELL_strtof)address[i++];
    OTA_strtold = (ELL_strtold)address[i++];
    OTA_strtol = (ELL_strtol)address[i++];
    OTA_strtoul = (ELL_strtoul)address[i++];

    OTA_rand = (ELL_rand)address[i++];
    OTA_srand = (ELL_srand)address[i++];
    OTA_acos = (ELL_acos)address[i++];
    OTA_asin = (ELL_asin)address[i++];
    OTA_atan = (ELL_atan)address[i++];
    OTA_atan2 = (ELL_atan2)address[i++];
    OTA_cos = (ELL_cos)address[i++];
    OTA_sin = (ELL_sin)address[i++];
    OTA_tan = (ELL_tan)address[i++];
    OTA_cosh = (ELL_cosh)address[i++];
    OTA_sinh = (ELL_sinh)address[i++];
    OTA_tanh = (ELL_tanh)address[i++];
    OTA_exp = (ELL_exp)address[i++];
    OTA_frexp = (ELL_frexp)address[i++];
    OTA_ldexp = (ELL_ldexp)address[i++];


    OTA_modf = (ELL_modf)address[i++];
    OTA_pow = (ELL_pow)address[i++];
    OTA_sqrt = (ELL_sqrt)address[i++];
    OTA_ceil = (ELL_ceil)address[i++];
    OTA_fabs = (ELL_fabs)address[i++];
    OTA_floor = (ELL_floor)address[i++];
    OTA_fmod = (ELL_fmod)address[i++];


    OTA_fprintf = (ELL_fprintf)address[i++];
    OTA_printf = (ELL_printf)address[i++];
    OTA_sprintf = (ELL_sprintf)address[i++];
    OTA_snprintf = (ELL_snprintf)address[i++];
    OTA_vfprintf = (ELL_vfprintf)address[i++];
    OTA_vprintf = (ELL_vprintf)address[i++];
    OTA_vsprintf = (ELL_vsprintf)address[i++];
    OTA_vsnprintf = (ELL_vsnprintf)address[i++];



    /*
     * 16bits string operations
     */
    OTA_kal_wstrlen = (ELL_kal_wstrlen)(address[i++]) ;
    OTA_kal_wstrcpy = (ELL_kal_wstrcpy)(address[i++]) ;
    OTA_kal_wstrncpy = (ELL_kal_wstrncpy)(address[i++]) ;
    OTA_kal_wstrcmp = (ELL_kal_wstrcmp)(address[i++]) ;
    OTA_kal_wstrncmp = (ELL_kal_wstrncmp)(address[i++]) ;
    OTA_kal_wstrcat = (ELL_kal_wstrcat)(address[i++]) ;
    OTA_kal_wstrncat = (ELL_kal_wstrncat)(address[i++]) ;
    OTA_kal_wstrchr = (ELL_kal_wstrchr)(address[i++]) ;
    OTA_kal_wstrrchr = (ELL_kal_wstrrchr)(address[i++]) ;


    /*
     * dual 8bits string operations
     */
    OTA_kal_dchar_strlen = (ELL_kal_dchar_strlen)(address[i++]) ;
    OTA_kal_dchar_strcpy = (ELL_kal_dchar_strcpy)(address[i++]) ;
    OTA_kal_dchar_strncpy = (ELL_kal_dchar_strncpy)(address[i++]) ;
    OTA_kal_dchar_strcmp = (ELL_kal_dchar_strcmp)(address[i++]) ;
    OTA_kal_dchar_strncmp = (ELL_kal_dchar_strncmp)(address[i++]) ;
    OTA_kal_dchar_strcat = (ELL_kal_dchar_strcat)(address[i++]) ;
    OTA_kal_dchar_strncat = (ELL_kal_dchar_strncat)(address[i++]) ;
    OTA_kal_dchar_strchr = (ELL_kal_dchar_strchr)(address[i++]) ;
    OTA_kal_dchar_strrchr = (ELL_kal_dchar_strrchr)(address[i++]) ;
    OTA_kal_dchar2char = (ELL_kal_dchar2char)(address[i++]) ;
    OTA_kal_wsprintf = (ELL_kal_wsprintf)(address[i++]) ;


    OTA_aeabi_idivmod = (ELL_aeabi_idivmod)(address[i++]) ;
    OTA_aeabi_uidivmod = (ELL_aeabi_uidivmod)(address[i++]) ;



    OTA_scalbln = (ELL_scalbln)(address[i++]) ;
    OTA_scalbn = (ELL_scalbn)(address[i++]) ;
    OTA_scalbnf = (ELL_scalbnf)(address[i++]) ;

    OTA_rt_fp_status_addr = (ELL_rt_fp_status_addr)(address[i++]) ;

    OTA_sds_update_status = (kal_bool*)(address[i++]);

    OTA_readRawDiskData = (ELL_readRawDiskData)address[i++];
    OTA_writeRawDiskData = (ELL_writeRawDiskData)address[i++];
    OTA_eraseRawDiskBlock = (ELL_eraseRawDiskBlock)address[i++];
    OTA_FlashDiskDriveData = (NOR_FLASH_DISK_Data*)(address[i++]);

    OTA_Ell_Update_SDS_Data= (ELL_Ell_Update_SDS_Data)address[i++];

    OTA_track_GPIO_SetClkOut= (ELL_track_GPIO_SetClkOut)address[i++];
    
    OTA_Media_SetBuffer = (ELL_Media_SetBuffer)address[i++];
    OTA_Media_SetRBThreshold = (ELL_Media_SetRBThreshold)address[i++];

    OTA_Media_Record = (ELL_Media_Record)address[i++];

    OTA_Media_Stop = (ELL_Media_Stop)address[i++];

    OTA_Media_GetReadBuffer = (ELL_Media_GetReadBuffer)address[i++];

    OTA_Media_ReadDataDone = (ELL_Media_ReadDataDone)address[i++];
    
    if(i < InLength) OTA_app_getcurrtime = (ELL_app_getcurrtime)address[i++];
    if(i < InLength) OTA_ell_get_iccid = (ELL_ell_get_iccid)address[i++];
	
	if(i < InLength) OTA_kal_retrieve_eg_events = (ELL_kal_retrieve_eg_events)address[i++];
	//        EllLog ( "OTA_kal_retrieve_eg_events %x \n" , OTA_kal_retrieve_eg_events ) ;
	if(i < InLength) OTA_gps_uart_read_data_nmea = (ELL_gps_uart_read_data_nmea)address[i++];
	if(i < InLength) OTA_kal_create_event_group = (ELL_kal_create_event_group)address[i++];
	if(i < InLength) OTA_ell_play_voice = (ELL_ell_play_voice)address[i++];
    if(i < InLength) OTA_gps_uart_read_data_dbg = (ELL_gps_uart_read_data_dbg)address[i++];
     if(i < InLength) OTA_track_is_epo_aiding = (ELL_track_is_epo_aiding)address[i++];
     if(i < InLength) OTA_track_custom_fake_cell_feature_enable = (ELL_track_custom_fake_cell_feature_enable)address[i++];
	if(i < InLength) OTA_acc_sensor_get_6bytes = (ELL_acc_sensor_get_6bytes)address[i++];
	if(i < InLength) OTA_track_ble_bt_status = (ELL_track_ble_bt_status)address[i++];
	if(i < InLength) OTA_track_ble_set_status = (ELL_track_ble_set_status)address[i++];
	if(i < InLength) OTA_track_sensor_kxtj31057_get_xyz = (ELL_track_sensor_kxtj31057_get_xyz)address[i++];
	if(i < InLength) OTA_media_aud_play_file = (ELL_media_aud_play_file)address[i++];
	if(i < InLength) OTA_mbstowcs = (ELL_mbstowcs)address[i++];
	if(i < InLength) OTA_FS_Rename = (ELL_FS_Rename)address[i++];
    LOGS("OS开放给APP的接口数量:%d, 实际注册的数量:%d", InLength, i);
    *size = sizeof(FunAddress) / sizeof(int);
    return &FunAddress[0];

}

#pragma arm section code








