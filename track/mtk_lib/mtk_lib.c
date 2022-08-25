
#include "track_os_ell.h"

/*该.c文件未参与编译，直接使用fota.a库，新加$$Sub无效       --    chengjun  2016-10-28*/

void $Sub$$GPIO_InitIO(char direction, char port)
{
    OTA_GPIO_InitIO(direction, port);
}
void $Sub$$GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
    OTA_GPIO_ModeSetup(pin, conf_dada);
}
eventid $Sub$$evshed_set_event(event_scheduler *es, kal_timer_func_ptr event_hf, void *event_hf_param, kal_uint32 elapse_time)
{
    return OTA_evshed_set_event(es, event_hf, event_hf_param, elapse_time);
}
void $Sub$$evshed_timer_handler(event_scheduler *es)
{
    OTA_evshed_timer_handler(es);
}
int $Sub$$FS_Close(FS_HANDLE FileHandle)
{
    return OTA_FS_Close(FileHandle);
}

int $Sub$$FS_Commit(FS_HANDLE FileHandle)
{
    return OTA_FS_Commit(FileHandle);
}
int $Sub$$FS_CreateDir(const WCHAR * DirName)
{
    return OTA_FS_CreateDir(DirName);
}
int $Sub$$FS_Delete(const WCHAR * FileName)
{
    return OTA_FS_Delete(FileName);
}
int $Sub$$FS_FindFirst(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength)
{
    return OTA_FS_FindFirst(NamePattern, Attr, AttrMask, FileInfo, FileName, MaxLength);

}
int $Sub$$FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength)
{
    return OTA_FS_FindNext(FileHandle, FileInfo, FileName,  MaxLength);
}

int $Sub$$FS_GetDrive(UINT Type, UINT Serial, UINT AltMask)
{
    return OTA_FS_GetDrive(Type,  Serial,  AltMask);
}

int $Sub$$FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size)
{
    return OTA_FS_GetFileSize(FileHandle, Size);
}

int $Sub$$FS_GetFolderSize(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize)
{
    return OTA_FS_GetFolderSize(FullPath,  Flag, RecursiveStack,   StackSize);
}

int $Sub$$FS_Open(const WCHAR *FileName, UINT Flag)
{
    return OTA_FS_Open(FileName,  Flag);
}

int $Sub$$FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence)
{
    return OTA_FS_Seek(FileHandle,  Offset,  Whence);
}
int $Sub$$FS_Write(FS_HANDLE FileHandle, void *DataPtr, UINT Length, UINT *Written)
{
    return OTA_FS_Write(FileHandle, DataPtr,  Length, Written);
}
int $Sub$$FS_Read(FS_HANDLE FileHandle, void *DataPtr, UINT Length, UINT *Read)
{
    return OTA_FS_Read(FileHandle, DataPtr,  Length, Read);
}
int $Sub$$FS_XDelete(const WCHAR *FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    OTA_FS_XDelete(FullPath,  Flag, RecursiveStack,  StackSize);
}
int $Sub$$FS_GeneralFormat(const WCHAR *DriveName, UINT Level, FS_FormatCallback Progress)
{
    return OTA_FS_GeneralFormat(DriveName,  Level,  Progress);
}
int $Sub$$FS_GetDiskInfo(const WCHAR *DriveName, FS_DiskInfo *DiskInfo, int Flags)
{
    return OTA_FS_GetDiskInfo(DriveName, DiskInfo,  Flags);
}
event_scheduler* $Sub$$evshed_create(kal_char *evshed_name, module_type module_id, kal_uint32 allowed_time_shift, kal_uint16 allowed_time_shift_sleep_mode)
{
    return OTA_evshed_create(evshed_name, module_id, allowed_time_shift, allowed_time_shift_sleep_mode);
}
kal_int32 $Sub$$evshed_cancel_event(event_scheduler *es, eventid *eid)
{
    return OTA_evshed_cancel_event(es, eid);
}
char $Sub$$GPIO_ReadIO(char port)
{
    return OTA_GPIO_ReadIO(port);
}
void $Sub$$GPIO_WriteIO(char data, char port)
{
    OTA_GPIO_WriteIO(data,  port);
}
DCL_STATUS $Sub$$DclPMU_Close(DCL_HANDLE handle)
{
    return OTA_DclPMU_Close(handle);
}
DCL_STATUS $Sub$$DclPMU_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return OTA_DclPMU_Control(handle,  cmd, data);
}
DCL_HANDLE $Sub$$DclPMU_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return OTA_DclPMU_Open(dev,  flags);
}
void $Sub$$EINT_Mask(kal_uint8 eintno)
{
    OTA_EINT_Mask(eintno);
}
void $Sub$$EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, \
                             void (reg_hisr)(void), kal_bool auto_umask)
{
    OTA_EINT_Registration(eintno,  Dbounce_En,  ACT_Polarity, reg_hisr,  auto_umask);
}
kal_int32 $Sub$$EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time)
{
    return OTA_EINT_SW_Debounce_Modify(eintno, debounce_time);
}
kal_uint32 $Sub$$EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{
    return OTA_EINT_Set_Sensitivity(eintno,  sens);
}
void $Sub$$EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)
{
    OTA_EINT_Set_Polarity(eintno,  ACT_Polarity);
}
void $Sub$$EINT_UnMask(kal_uint8 eintno)
{
    OTA_EINT_UnMask(eintno);
}
DCL_STATUS $Sub$$DclSerialPort_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return OTA_DclSerialPort_Control(handle,  cmd, data);
}
DCL_HANDLE $Sub$$DclSerialPort_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return OTA_DclSerialPort_Open(dev,  flags);
}
DCL_STATUS $Sub$$DclSerialPort_Close(DCL_HANDLE handle)
{
    return OTA_DclSerialPort_Close(handle);
}

void *$Sub$$__kal_adm_alloc(KAL_ADM_ID adm_id, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 opt, char *filename, kal_uint32 line)
{
    OTA_kal_adm_alloc_1(adm_id,  size, actual_size,  opt, filename,  line);
}
KAL_ADM_ID $Sub$$kal_adm_create2(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_uint32 flags, kal_int8 extheader_size_in_word)
{
    return OTA_kal_adm_create2(mem_addr,  size, subpool_size,  flags,  extheader_size_in_word);
}
kal_status $Sub$$kal_adm_delete(KAL_ADM_ID adm_id)
{
    return OTA_kal_adm_delete(adm_id);
}
void $Sub$$kal_adm_free(KAL_ADM_ID adm_id, void *mem_addr)
{
    OTA_kal_adm_free(adm_id, mem_addr);
}
kal_uint32 $Sub$$kal_adm_get_max_alloc_size(KAL_ADM_ID adm_id)
{
    return OTA_kal_adm_get_max_alloc_size(adm_id);
}
kal_uint32 $Sub$$kal_adm_get_total_left_size(KAL_ADM_ID adm_id)
{
    return OTA_kal_adm_get_total_left_size(adm_id);
}
kal_mutexid $Sub$$kal_create_mutex(kal_char* mutex_name_ptr)
{
    return OTA_kal_create_mutex(mutex_name_ptr);
}
void $Sub$$kal_take_mutex(kal_mutexid mutex_id)
{
    OTA_kal_take_mutex(mutex_id);
}
void $Sub$$kal_give_mutex(kal_mutexid mutex_id)
{
    OTA_kal_give_mutex(mutex_id);
}
kal_int8 $Sub$$soc_close(kal_int8 s)
{
    return OTA_soc_close(s);
}
kal_int8 $Sub$$soc_connect(kal_int8 s, sockaddr_struct *addr)
{
    return OTA_soc_connect(s, addr);
}
kal_int8 $Sub$$soc_create(kal_uint8         domain,
                          socket_type_enum  type,
                          kal_uint8         protocol,
                          module_type       mod_id,
                          kal_uint32        nwk_account_id)
{
    return OTA_soc_create(domain, type, protocol, mod_id, nwk_account_id);
}
kal_int8 $Sub$$soc_gethostbyname(kal_bool is_blocking,
                                 module_type     mod_id,
                                 kal_int32       request_id,
                                 const kal_char  *domain_name,
                                 kal_uint8       *addr,
                                 kal_uint8       *addr_len,
                                 kal_uint8       access_id,
                                 kal_uint32      nwk_account_id)
{
    return OTA_soc_gethostbyname(is_blocking, mod_id, request_id, domain_name, addr, addr_len, access_id, nwk_account_id);
}
kal_int8 $Sub$$soc_getsockopt(kal_int8   s,
                              kal_uint32 option,
                              void       *val,
                              kal_uint8  val_size)
{
    return OTA_soc_getsockopt(s, option, val, val_size);
}
kal_int32 $Sub$$soc_recv(kal_int8  s,
                         void *buf,
                         kal_int32 len,
                         kal_uint8 flags)
{
    return OTA_soc_recv(s, buf, len, flags);
}
kal_int32 $Sub$$soc_send(kal_int8	 s,
                         const void *buf,
                         kal_int32  len,
                         kal_uint8	 flags)
{
    return OTA_soc_send(s, buf, len, flags);
}
kal_int8 $Sub$$soc_setsockopt(kal_int8   s,
                              kal_uint32 option,
                              void       *val,
                              kal_uint8  val_size)
{
    return OTA_soc_setsockopt(s, option, val, val_size);
}
kal_uint32 $Sub$$cbm_encode_data_account_id(kal_uint32 acct_id, cbm_sim_id_enum sim_id,
        kal_uint8 app_id, kal_bool always_ask)
{
    return OTA_cbm_encode_data_account_id(acct_id,  sim_id, app_id,  always_ask);
}
kal_uint8  $Sub$$cbm_get_app_id(kal_uint32 acct_id)
{
    return OTA_cbm_get_app_id(acct_id);
}
kal_int8 $Sub$$cbm_register_app_id_with_app_info(cbm_app_info_struct *info,
        kal_uint8 *app_id)
{
    return OTA_cbm_register_app_id_with_app_info(info, app_id);
}
void $Sub$$kal_cancel_timer(kal_timerid timer_ptr)
{
    OTA_kal_cancel_timer(timer_ptr);
}
kal_timerid $Sub$$kal_create_timer(kal_char* timer_name)
{
    return OTA_kal_create_timer(timer_name);
}
void $Sub$$kal_set_timer(kal_timerid timer_ptr,
                         kal_timer_func_ptr handler_func_ptr, void* handler_param_ptr,
                         kal_uint32 delay, kal_uint32 reschedule_time)
{
    OTA_kal_set_timer(timer_ptr, handler_func_ptr,  handler_param_ptr, delay,  reschedule_time);
}
kal_bool $Sub$$track_net_apn_set(void)
{
    return OTA_track_net_apn_set();
}
ilm_struct* $Sub$$allocate_ilm(module_type module_id)
{
    return OTA_allocate_ilm(module_id);
}





kal_bool $Sub$$msg_send_ext_queue(ilm_struct *ilm_ptr)
{
    return OTA_msg_send_ext_queue(ilm_ptr);
}


kal_char* $Sub$$build_date_time(void)
{
    return OTA_build_date_time();
}
kal_char* $Sub$$release_verno(void)
{
    return OTA_release_verno();
}
void $Sub$$U_PutUARTBytes(UART_PORT port, kal_uint8 *data, kal_uint16 len)
{
    OTA_U_PutUARTBytes(port, data, len);
}
kal_int32 $Sub$$app_ucs2_strlen(const kal_int8 *arrOut)
{
    return OTA_app_ucs2_strlen(arrOut);
}
void $Sub$$applib_dt_get_rtc_time(applib_time_struct *t)
{
    OTA_applib_dt_get_rtc_time(t);
}

kal_uint32 $Sub$$applib_get_time_difference_ext_in_second(
    applib_time_struct *t1,
    applib_time_struct *t2)
{
    return OTA_applib_get_time_difference_ext_in_second(t1, t2);
}
kal_uint16 $Sub$$app_asc_str_n_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    return OTA_app_asc_str_n_to_ucs2_str(pOutBuffer, pInBuffer, len);
}
kal_uint16 $Sub$$app_ucs2_str_n_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    return OTA_app_ucs2_str_n_to_asc_str(pOutBuffer, pInBuffer, len);
}
kal_int32 $Sub$$mmi_chset_convert_ex(
    mmi_chset_enum src_type,
    mmi_chset_enum dest_type,
    char *src_buff,
    char *dest_buff,
    kal_int32 dest_size,
    kal_uint32 *src_end_pos)
{
    return OTA_mmi_chset_convert_ex(src_type, dest_type, src_buff, dest_buff, dest_size, src_end_pos);
}
void $Sub$$mtk_gps_sys_storage_clear(void)
{
    OTA_mtk_gps_sys_storage_clear();
}
sim_card_status_enum $Sub$$check_sim_card_status(void)
{
    return OTA_check_sim_card_status();
}
kal_int8 *$Sub$$app_ucs2_strcat(kal_int8 *strDestination, const kal_int8 *strSource)
{
    return OTA_app_ucs2_strcat(strDestination,  strSource);
}
kal_int8 *$Sub$$app_ucs2_strcpy(kal_int8 *strDestination, const kal_int8 *strSource)
{
    return OTA_app_ucs2_strcpy(strDestination, strSource);
}
void $Sub$$applib_dt_decrease_time(
    applib_time_struct *timeToDecrement,
    applib_time_struct *decrement,
    applib_time_struct *Result)
{
    OTA_applib_dt_decrease_time(timeToDecrement, decrement, Result);
}
void $Sub$$applib_dt_increase_time(
    applib_time_struct *timeToIncrement,
    applib_time_struct *increment,
    applib_time_struct *Result)
{
    OTA_applib_dt_increase_time(timeToIncrement, increment, Result);
}
void $Sub$$uem_drv_power_on(void)
{
    OTA_uem_drv_power_on();
}
void $Sub$$uem_drv_power_off(void)
{
    OTA_uem_drv_power_off();
}
void $Sub$$L1SM_SleepEnable(kal_uint8 handle)
{
    OTA_L1SM_SleepEnable(handle);
}
void $Sub$$L1SM_SleepDisable(kal_uint8 handle)
{
    OTA_L1SM_SleepDisable(handle);
}
mtk_int32 $Sub$$mtk_gps_set_param(mtk_gps_param key, const void* value)
{
    return OTA_mtk_gps_set_param(key, value);
}
mtk_int32 $Sub$$mtk_gps_get_param(mtk_gps_param key, void* value)
{
    return OTA_mtk_gps_get_param(key, value);
}
void $Sub$$kal_prompt_trace(module_type mod_id, const char *fmt, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, fmt);
    OTA_vsnprintf(buffer, 999, fmt, MyList);
    va_end(MyList);

    OTA_kal_prompt_trace(mod_id, fmt, MyList);
}


/* ----------    MagicNing 这里                ---------*/


void $Sub$$l4csmu_get_imsi(kal_uint8 *imsi_data)
{
    OTA_l4csmu_get_imsi(imsi_data);
}
void $Sub$$RTC_GetTimeOnly(t_rtc *rtctime) // validate
{
    OTA_RTC_GetTimeOnly(rtctime);
}
void $Sub$$pmu_drv_bl_isink(PMU_ISINK_LIST_ENUM isink, kal_bool enable)
{
    OTA_pmu_drv_bl_isink(isink, enable);
}
DCL_STATUS $Sub$$DclSADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return OTA_DclSADC_Control(handle,  cmd, data);
}
DCL_HANDLE $Sub$$DclSADC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return OTA_DclSADC_Open(dev, flags);
}
kal_uint8 $Sub$$L1SM_GetHandle(void)
{
    return OTA_L1SM_GetHandle();
}
void $Sub$$RTC_InitTC_Time(t_rtc *rtctime) // validate
{
    OTA_RTC_InitTC_Time(rtctime);
}
kal_bool $Sub$$SST_Get_ChipRID(kal_char *pUid, kal_int32 buf_len)
{
    return OTA_SST_Get_ChipRID(pUid, buf_len);
}
kal_bool $Sub$$nvram_external_read_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    OTA_nvram_external_read_data(LID, rec_index, buffer, buffer_size);
}
kal_bool $Sub$$nvram_external_write_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    OTA_nvram_external_write_data(LID, rec_index, buffer, buffer_size);
}
kal_uint32 $Sub$$kal_ticks_to_secs(kal_uint32 ticks)
{
    return OTA_kal_ticks_to_secs(ticks);
}
kal_uint32 $Sub$$kal_get_systicks(void)
{
    return OTA_kal_get_systicks();
}
kal_uint32 $Sub$$kal_secs_to_ticks(kal_uint32 secs)
{
    return OTA_kal_secs_to_ticks(secs);
}
kal_uint32 $Sub$$kal_ticks_to_milli_secs(kal_uint32 ticks)
{
    return OTA_kal_ticks_to_milli_secs(ticks);
}
module_type $Sub$$kal_get_active_module_id(void)
{
    return OTA_kal_get_active_module_id();
}

void $Sub$$l4c_ConvertGSM7BitDefaultEncodingToAscii(
    kal_uint8 *message,
    kal_uint8 *msg,
    kal_uint16 length,
    kal_uint16 *outLen)
{
    OTA_l4c_ConvertGSM7BitDefaultEncodingToAscii(message, msg, length, outLen);
}
void $Sub$$smsal_gsm7_unpack(kal_uint8  *packed_data,
                             kal_uint8  *unpacked_data,
                             kal_uint16 data_len,
                             kal_uint16 offset)
{
    OTA_smsal_gsm7_unpack(packed_data, unpacked_data, data_len, offset);
}

kal_uint16 $Sub$$smsal_msg_len_in_character(kal_uint8 dcs, kal_uint16 len, kal_uint8 last_byte)
{
    return OTA_smsal_msg_len_in_character(dcs, len, last_byte);
}
kal_int32 $Sub$$applib_dt_compare_time(
    applib_time_struct *referenceTime,
    applib_time_struct *compareTime,
    applib_time_struct *diff)
{
    return OTA_applib_dt_compare_time(referenceTime, compareTime, diff);
}
void $Sub$$l4cuem_power_off_req(void)
{
    OTA_l4cuem_power_off_req();
}
void $Sub$$uem_get_bat_status(uem_bmt_struct *bmt_status)
{
    OTA_uem_get_bat_status(bmt_status);
}
kal_uint32 $Sub$$uem_get_vbat_percentage(void)
{
    return OTA_uem_get_vbat_percentage();
}
kal_int32 $Sub$$mmi_chset_utf16_strlen(const kal_int8 *str_utf16, mmi_chset_enum utf16_type)
{
    return OTA_mmi_chset_utf16_strlen(str_utf16, utf16_type);
}
kal_uint32 $Sub$$applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving)
{
    return OTA_applib_dt_mytime_2_utc_sec(currTime, daylightSaving);
}
kal_int64 $Sub$$applib_dt_mytime_2_utc_sec_ext(applib_time_struct *currTime, kal_bool daylightSaving)
{
    return OTA_applib_dt_mytime_2_utc_sec_ext(currTime, daylightSaving);
}
kal_uint8 $Sub$$applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving)
{
    return OTA_applib_dt_utc_sec_2_mytime(utc_sec, result, daylightSaving);
}
kal_uint8 $Sub$$track_gps_hour_to_utc(kal_uint32 utc_sec, applib_time_struct *result)
{
    return OTA_track_gps_hour_to_utc(utc_sec, result);
}
void $Sub$$DRV_RESET(void)
{
    OTA_DRV_RESET();
}
void $Sub$$PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type)
{
    OTA_PCM2WAY_Start(pcm2way_hdlr, type);
}
void $Sub$$PCM2WAY_Stop(uint32 type)
{
    OTA_PCM2WAY_Stop(type);
}
void $Sub$$PCM2WAY_GetFromMic(uint16 *ul_buf)
{
    OTA_PCM2WAY_GetFromMic(ul_buf);
}
void $Sub$$track_bmt_get_ADC_result(charge_measure_struct *charge_measure)
{
    OTA_track_bmt_get_ADC_result(charge_measure);
}
void $Sub$$track_bmt_vol_reset_setatus(void)
{
    OTA_track_bmt_vol_reset_setatus();
}
void $Sub$$applib_md5_init(applib_md5_ctx *mdContext)
{
    OTA_applib_md5_init(mdContext);
}
void $Sub$$applib_md5_update(applib_md5_ctx *mdContext, const kal_uint8 *inBuf, kal_uint32 inLen)
{
    OTA_applib_md5_update(mdContext,  inBuf, inLen);
}
void $Sub$$applib_md5_final(kal_uint8 hash[], applib_md5_ctx *mdContext)
{
    OTA_applib_md5_final(hash, mdContext);
}
kal_int32 $Sub$$compress_decode(kal_uint8 *dect, kal_uint8 *src, int len)
{
    return OTA_compress_decode(dect, src, len);
}
kal_int32 $Sub$$compress_encode(kal_uint8 *dect, kal_uint8 *src, int len)
{
    return OTA_compress_encode(dect, src, len);
}
kal_int32 $Sub$$track_fun_decryption(kal_uint8 *dec, kal_uint8 *src, int size)
{
    return OTA_track_fun_decryption(dec, src,  size);
}
kal_bool $Sub$$l4c_sms_exe_post_msg_req(kal_uint8 source_id,
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
                                        kal_uint8 tp_rp)
{
    return OTA_l4c_sms_exe_post_msg_req(source_id, profile, reply_index, dest, para, sc_addr, vp, pid, udhi, dcs, length, msg, seq_num, mms_mode, tp_srr, tp_rp);
}
kal_bool $Sub$$l4c_sms_exe_post_pdu_req(kal_uint8 src_id,
                                        kal_uint16 reply_index,
                                        kal_uint16 data_len,
                                        kal_uint8 source_id,
                                        kal_uint8 seq_num,
                                        kal_uint8 mms_mode,
                                        kal_uint16 length,
                                        kal_uint8 *pdu)
{
    return OTA_l4c_sms_exe_post_pdu_req(src_id, reply_index, data_len, source_id, seq_num, mms_mode, length, pdu);
}
kal_bool $Sub$$l4cuem_power_reset(
    kal_uint8 reset_type)
{
    return OTA_l4cuem_power_reset(reset_type);
}
void $Sub$$uem_poweron_timer_start(kal_uint32 time_in_ms)
{
    OTA_uem_poweron_timer_start(time_in_ms);
}
void $Sub$$aud_send_play_id_req(void *id_param)
{
    OTA_aud_send_play_id_req(id_param);
}
void $Sub$$aud_send_play_string_req(void *string_param)
{
    OTA_aud_send_play_string_req(string_param);
}
void $Sub$$aud_send_stop_string_req(kal_uint8 src_id)
{
    OTA_aud_send_stop_string_req(src_id);
}
kal_uint8 $Sub$$aud_get_active_audio_mode(void)
{
    return OTA_aud_get_active_audio_mode();
}
kal_uint8 $Sub$$aud_get_volume_level(kal_uint8 mode, kal_uint8 type)
{
    return OTA_aud_get_volume_level(mode, type);
}
void $Sub$$track_sensor_bma250_off(void)
{
    OTA_track_sensor_bma250_off();
}
void $Sub$$track_sensor_bma250_on(kal_uint8 threshold , FuncPtr callback)
{
    OTA_track_sensor_bma250_on(threshold , callback);
}
kal_int8 $Sub$$track_sensor_bma250_type_check(void)
{
    return OTA_track_sensor_bma250_type_check();
}

void $Sub$$l4cuem_audio_get_volume_req(kal_uint8 src_id, kal_uint8 volume_type)
{
    OTA_l4cuem_audio_get_volume_req(src_id,  volume_type);
}
void $Sub$$l4cuem_speech_set_mode_req(kal_bool speech_mode_onoff, kal_uint8 rat_mode)
{
    OTA_l4cuem_speech_set_mode_req(speech_mode_onoff,  rat_mode);
}
void $Sub$$l4cuem_audio_set_volume_req(kal_uint8 volume_type, kal_uint8 volume_level)
{
    OTA_l4cuem_audio_set_volume_req(volume_type,  volume_level);
}

void $Sub$$l4cuem_set_audio_mode(kal_uint8 mode)
{
    OTA_l4cuem_set_audio_mode(mode);
}
void $Sub$$ell_update_soc_nw_attach_ind(void *msg)
{
    OTA_ell_update_soc_nw_attach_ind(msg);
}
kal_int8 $Sub$$ell_update_delete_file(void)
{
    return OTA_ell_update_delete_file();
}


void $Sub$$AFE_TurnOffSpeaker(kal_uint8 aud_func)
{
    OTA_AFE_TurnOffSpeaker(aud_func);
}

void $Sub$$L1SP_Speech_Off(void)
{
    OTA_L1SP_Speech_Off();
}
void $Sub$$AFE_SetRefresh(void)
{
    OTA_AFE_SetRefresh();
}
void $Sub$$L1SP_MuteSpeaker(bool mute)
{
    OTA_L1SP_MuteSpeaker(mute);
}
void $Sub$$sys_assert_reset(void)
{
    OTA_sys_assert_reset();
}

void $Sub$$app_init_complete_callback(void)
{
    OTA_app_init_complete_callback();
}
kal_bool $Sub$$l4c_nw_cfun_state_req(kal_uint8 src_id, kal_uint8 cfun_state)
{
    return  OTA_l4c_nw_cfun_state_req(src_id, cfun_state);
}
void $Sub$$ELL_ASSERT(int expr)
{
    OTA_ASSERT(expr);
}




//---------------------------------------------------------------------------
//---------------------     string.h    ------------------------------------------
//---------------------------------------------------------------------------

void* $Sub$$memcpy(void* s1, const void* s2, size_t n)
{
    return OTA_memcpy(s1, s2, n);
}

void* $Sub$$memmove(void* s1, const void* s2, size_t n)
{
    return OTA_memmove(s1, s2, n);
}

char* $Sub$$strcpy(char* s1, const char* s2)
{
    return OTA_strcpy(s1, s2);
}

char* $Sub$$strncpy(char* s1, const char* s2, size_t n)
{
    return OTA_strncpy(s1, s2, n);
}

char* $Sub$$strcat(char* s1, const char* s2)
{
    return OTA_strcat(s1, s2);
}

char* $Sub$$strncat(char* s1, const char* s2, size_t n)
{
    return OTA_strncat(s1, s2, n);
}

int $Sub$$memcmp(const void* s1, const void* s2, size_t n)
{
    return OTA_memcmp(s1, s2, n);
}

int $Sub$$strcmp(const char* s1, const char* s2)
{
    return OTA_strcmp(s1, s2);
}

int $Sub$$strncmp(const char* s1, const char* s2, size_t n)
{
    return OTA_strncmp(s1, s2, n);
}

int $Sub$$strcoll(const char* s1, const char* s2)
{
    return OTA_strcoll(s1, s2);
}

size_t $Sub$$strxfrm(char* s1, const char* s2, size_t n)
{
    return OTA_strxfrm(s1, s2, n);
}

void* $Sub$$memchr(void* s1, int c , size_t n)
{
    return OTA_memchr(s1, c, n);
}


char* $Sub$$strchr(const char* s1, int c)
{
    return OTA_strchr(s1, c);
}

size_t $Sub$$strcspn(const char* s1 , const char* s2)
{
    return OTA_strcspn(s1, s2);
}

const char* $Sub$$strpbrk(const char* s1, const char* s2)
{
    return OTA_strpbrk(s1, s2);
}

const char* $Sub$$strrchr(const char* s1, int c)
{
    return OTA_strrchr(s1, c);
}

size_t $Sub$$strspn(const char* s1, const char* s2)
{
    return OTA_strspn(s1, s2);
}

const char* $Sub$$strstr(const char* s1, const char* s2)
{
    return OTA_strstr(s1, s2);
}

void* $Sub$$memset(void* s1, int c , size_t n)
{
    return OTA_memset(s1, c, n);
}

char* $Sub$$strerror(int errnum)
{
    return OTA_strerror(errnum);
}

size_t $Sub$$strlen(const char* s)
{
    return OTA_strlen(s);
}





//---------------------------------------------------------------------------
//---------------------     rt_fp.h    ------------------------------------------
//---------------------------------------------------------------------------


float $Sub$$__aeabi_fadd(float f1, float f2)
{
    return OTA_aeabi_fadd(f1, f2);
}
float $Sub$$__aeabi_fsub(float f1, float f2)
{
    return OTA_aeabi_fsub(f1, f2);
}
float $Sub$$__aeabi_frsub(float f1, float f2)
{
    return OTA_aeabi_frsub(f1, f2);
}
float $Sub$$__aeabi_fmul(float f1, float f2)
{
    return OTA_aeabi_fmul(f1, f2);
}
float $Sub$$__aeabi_fdiv(float f1, float f2)
{
    return OTA_aeabi_fdiv(f1, f2);
}


double $Sub$$__aeabi_dadd(double d1, double d2)
{
    return OTA_aeabi_dadd(d1, d2);
}
double $Sub$$__aeabi_dsub(double d1, double d2)
{
    return OTA_aeabi_dsub(d1, d2);
}
double $Sub$$__aeabi_drsub(double d1, double d2)
{
    return OTA_aeabi_drsub(d1, d2);
}
double $Sub$$__aeabi_dmul(double d1, double d2)
{
    return OTA_aeabi_dmul(d1, d2);
}
double $Sub$$__aeabi_ddiv(double d1, double d2)
{
    return OTA_aeabi_ddiv(d1, d2);
}


int $Sub$$__aeabi_fcmpeq(float f1, float f2)
{
    return OTA_aeabi_fcmpeq(f1, f2);
}
int $Sub$$__aeabi_fcmpge(float f1, float f2)
{
    return OTA_aeabi_fcmpge(f1, f2);
}
int $Sub$$__aeabi_fcmpgt(float f1, float f2)
{
    return OTA_aeabi_fcmpgt(f1, f2);
}
int $Sub$$__aeabi_fcmple(float f1, float f2)
{
    return OTA_aeabi_fcmple(f1, f2);
}
int $Sub$$__aeabi_fcmplt(float f1, float f2)
{
    return OTA_aeabi_fcmplt(f1, f2);
}
int $Sub$$__aeabi_fcmpun(float f1, float f2)
{
    return OTA_aeabi_fcmpun(f1, f2);
}


void $Sub$$__aeabi_cfcmpeq(float f1, float f2)
{
    OTA_aeabi_cfcmpeq(f1, f2);
}
void $Sub$$__aeabi_cfcmple(float f1, float f2)
{
    OTA_aeabi_cfcmple(f1, f2);
}
void $Sub$$__aeabi_cfrcmple(float f1, float f2)
{
    OTA_aeabi_cfrcmple(f1, f2);
}


int $Sub$$__aeabi_dcmpeq(double d1, double d2)
{
    return OTA_aeabi_dcmpeq(d1, d2);
}
int $Sub$$__aeabi_dcmpge(double d1, double d2)
{
    return OTA_aeabi_dcmpge(d1, d2);
}
int $Sub$$__aeabi_dcmpgt(double d1, double d2)
{
    return OTA_aeabi_dcmpgt(d1, d2);
}
int $Sub$$__aeabi_dcmple(double d1, double d2)
{
    return OTA_aeabi_dcmple(d1, d2);
}
int $Sub$$__aeabi_dcmplt(double d1, double d2)
{
    return OTA_aeabi_dcmplt(d1, d2);
}
int $Sub$$__aeabi_dcmpun(double d1, double d2)
{
    return OTA_aeabi_dcmpun(d1, d2);
}

void $Sub$$__aeabi_cdcmpeq(double d1, double d2)
{
    OTA_aeabi_cdcmpeq(d1, d2);
}
void $Sub$$__aeabi_cdcmple(double d1, double d2)
{
    OTA_aeabi_cdcmple(d1, d2);
}
void $Sub$$__aeabi_cdrcmple(double d1, double d2)
{
    OTA_aeabi_cdrcmple(d1, d2);
}



double $Sub$$__aeabi_f2d(float f)
{
    return OTA_aeabi_f2d(f);
}
float $Sub$$__aeabi_d2f(double d)
{
    return OTA_aeabi_d2f(d);
}
float $Sub$$__aeabi_i2f(int i)
{
    return OTA_aeabi_i2f(i);
}
float $Sub$$__aeabi_ui2f(unsigned int i)
{
    return OTA_aeabi_ui2f(i);
}
double $Sub$$__aeabi_i2d(int i)
{
    return OTA_aeabi_i2d(i);
}
double $Sub$$__aeabi_ui2d(unsigned int i)
{
    return OTA_aeabi_ui2d(i);
}


float $Sub$$__aeabi_l2f(long long l)
{
    return OTA_aeabi_l2f(l);
}
float $Sub$$__aeabi_ul2f(unsigned long long l)
{
    return OTA_aeabi_ul2f(l);
}
double $Sub$$__aeabi_l2d(long long l)
{
    return OTA_aeabi_l2d(l);
}
double $Sub$$__aeabi_ul2d(unsigned long long l)
{
    return OTA_aeabi_ul2d(l);
}


int $Sub$$__aeabi_f2iz(float f)
{
    return OTA_aeabi_f2iz(f);
}
unsigned int $Sub$$__aeabi_f2uiz(float f)
{
    return OTA_aeabi_f2uiz(f);
}
int $Sub$$__aeabi_d2iz(double d)
{
    return OTA_aeabi_d2iz(d);
}
unsigned int $Sub$$__aeabi_d2uiz(double d)
{
    return OTA_aeabi_d2uiz(d);
}



long long $Sub$$__aeabi_f2lz(float f)
{
    return OTA_aeabi_f2lz(f);
}
unsigned long long $Sub$$__aeabi_f2ulz(float f)
{
    return OTA_aeabi_f2ulz(f);
}
long long $Sub$$__aeabi_d2lz(double d)
{
    return OTA_aeabi_d2lz(d);
}
unsigned long long $Sub$$__aeabi_d2ulz(double d)
{
    return OTA_aeabi_d2ulz(d);
}




double $Sub$$atof(const char* nptr)
{
    return OTA_atof(nptr);
}
int $Sub$$atoi(const char* nptr)
{
    return OTA_atoi(nptr);
}
long int $Sub$$atol(const char* nptr)
{
    return OTA_atol(nptr);
}
int $Sub$$abs(int i)
{
    return OTA_abs(i);
}
long int $Sub$$labs(long int i)
{
    return OTA_labs(i);
}

double $Sub$$strtod(const char * nptr, char** endptr)
{
    return OTA_strtod(nptr, endptr);
}
float $Sub$$strtof(const char * nptr, char** endptr)
{
    return OTA_strtof(nptr, endptr);
}
long double $Sub$$strtold(const char * nptr, char** endptr)
{
    return OTA_strtold(nptr, endptr);
}
long int $Sub$$strtol(const char * nptr, char** endptr, int base)
{
    return OTA_strtol(nptr, endptr, base);
}
unsigned long int $Sub$$strtoul(const char * nptr, char** endptr, int base)
{
    return OTA_strtoul(nptr, endptr, base);
}

int $Sub$$rand(void)
{
    return OTA_rand();
}
int $Sub$$srand(unsigned int seed)
{
    return OTA_srand(seed);
}
double $Sub$$acos(double d)
{
    return OTA_acos(d);
}
double $Sub$$asin(double d)
{
    return OTA_asin(d);
}
double $Sub$$atan(double d)
{
    return OTA_atan(d);
}
double $Sub$$cos(double d)
{
    return OTA_cos(d);
}
double $Sub$$sin(double d)
{
    return OTA_sin(d);
}
double $Sub$$tan(double d)
{
    return OTA_tan(d);
}
double $Sub$$cosh(double d)
{
    return OTA_cosh(d);
}
double $Sub$$sinh(double d)
{
    return OTA_sinh(d);
}
double $Sub$$tanh(double d)
{
    return OTA_tanh(d);
}
double $Sub$$exp(double d)
{
    return OTA_exp(d);
}

double $Sub$$sqrt(double d)
{
    return OTA_sqrt(d);
}
double $Sub$$ceil(double d)
{
    return OTA_ceil(d);
}
double $Sub$$fabs(double d)
{
    return OTA_fabs(d);
}
double $Sub$$floor(double d)
{
    return OTA_floor(d);
}
double $Sub$$atan2(double y, double x)
{
    return OTA_atan2(y, x);
}
double $Sub$$frexp(double value, int* exp)
{
    return OTA_frexp(value, exp);
}
double $Sub$$ldexp(double x, int exp)
{
    return OTA_ldexp(x, exp);
}
double $Sub$$modf(double value, double* iptr)
{
    return OTA_modf(value, iptr);
}
double $Sub$$pow(double x, double y)
{
    return OTA_pow(x, y);
}
double $Sub$$fmod(double x, double y)
{
    return OTA_fmod(x, y);
}

size_t $Sub$$mbstowcs(wchar_t* s1, const char* s2, size_t n)
{
	return OTA_mbstowcs(s1, s2, n);
}



//---------------------------------------------------------------------------
//---------------------     stdio.h    ------------------------------------------
//---------------------------------------------------------------------------
int $Sub$$fprintf(FILE* stream, const char* format, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, format);
    OTA_vsnprintf(buffer, 999, format, MyList);
    va_end(MyList);

    return OTA_fprintf(stream, format, MyList);
}
int $Sub$$printf(const char* format, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, format);
    OTA_vsnprintf(buffer, 999, format, MyList);
    va_end(MyList);

    return OTA_printf(format, MyList);
}

int $Sub$$sprintf(char *str, const char *fmt, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, fmt);
    OTA_vsnprintf(buffer, 999, fmt, MyList);
    va_end(MyList);

    return OTA_sprintf(str, fmt, MyList);
}

int $Sub$$__1sprintf(char *str, const char *fmt, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, fmt);
    OTA_vsnprintf(buffer, 999, fmt, MyList);
    va_end(MyList);

    return OTA_sprintf(str, fmt, MyList);
}

int $Sub$$snprintf(char *str, size_t size, const char *fmt, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, fmt);
    OTA_vsnprintf(buffer, 999, fmt, MyList);
    va_end(MyList);

    return OTA_snprintf(str, size, fmt, MyList);
}
int $Sub$$vfprintf(FILE* stream, const char* format, va_list arg)
{
    return OTA_vfprintf(stream, format, arg);
}
int $Sub$$vprintf(const char* format, va_list arg)
{
    return OTA_vprintf(format, arg);
}
int $Sub$$vsprintf(char *str, const char* format, va_list arg)
{
    return OTA_vsprintf(str, format, arg);
}
int $Sub$$vsnprintf(kal_char *str, kal_uint32 size, const kal_char *fmt, va_list ap)
{
    return OTA_vsnprintf(str, size, fmt, ap);
}


/*
 * 16bits string operations
 */
int $Sub$$kal_wstrlen(const WCHAR *wstr)
{
    return OTA_kal_wstrlen(wstr);
}
WCHAR* $Sub$$kal_wstrcpy(WCHAR *to, const WCHAR *from)
{
    return OTA_kal_wstrcpy(to, from);
}
WCHAR* $Sub$$kal_wstrncpy(WCHAR *to, const WCHAR *from, int n)
{
    return OTA_kal_wstrncpy(to, from, n);
}
int $Sub$$kal_wstrcmp(const WCHAR *s1, const WCHAR *s2)
{
    return OTA_kal_wstrcmp(s1, s2);
}
int $Sub$$kal_wstrncmp(const WCHAR *s1, const WCHAR *s2, int n)
{
    return OTA_kal_wstrncmp(s1, s2, n);
}
WCHAR* $Sub$$kal_wstrcat(WCHAR *s1, const WCHAR *s2)
{
    return OTA_kal_wstrcat(s1, s2);
}
WCHAR* $Sub$$kal_wstrncat(WCHAR *s1, const WCHAR *s2, int n)
{
    return OTA_kal_wstrncat(s1, s2 , n);
}
WCHAR* $Sub$$kal_wstrchr(const WCHAR *s, int c)
{
    return OTA_kal_wstrchr(s, c);
}
WCHAR* $Sub$$kal_wstrrchr(const WCHAR *str, int ch)
{
    return OTA_kal_wstrrchr(str, ch);
}



/*
 * dual 8bits string operations
 */
int $Sub$$kal_dchar_strlen(const char *wstr)
{
    return OTA_kal_dchar_strlen(wstr);
}
char* $Sub$$kal_dchar_strcpy(char *to, const char *from)
{
    return OTA_kal_dchar_strcpy(to, from);
}
char* $Sub$$kal_dchar_strncpy(char *to, const char *from, int n)
{
    return OTA_kal_dchar_strncpy(to, from, n);
}
int $Sub$$kal_dchar_strcmp(const char *s1, const char *s2)
{
    return OTA_kal_dchar_strcmp(s1, s2);
}
int $Sub$$kal_dchar_strncmp(const char *s1, const char *s2, int n)
{
    return OTA_kal_dchar_strncmp(s1, s2, n);
}
char* $Sub$$kal_dchar_strcat(char *s1, const char *s2)
{
    return OTA_kal_dchar_strcat(s1, s2);
}
char* $Sub$$kal_dchar_strncat(char *s1, const char *s2, int n)
{
    return OTA_kal_dchar_strncat(s1, s2, n);
}
char* $Sub$$kal_dchar_strchr(const char *s, int c)
{
    return OTA_kal_dchar_strchr(s, c);
}
char* $Sub$$kal_dchar_strrchr(const char *str, int ch)
{
    return OTA_kal_dchar_strrchr(str, ch);
}
void $Sub$$kal_dchar2char(WCHAR *outstr, char* tostr)
{
    OTA_kal_dchar2char(outstr, tostr);
}
void $Sub$$kal_wsprintf(WCHAR *outstr, char *fmt, ...)
{
    va_list MyList;
    char buffer[1000];

    va_start(MyList, fmt);
    OTA_vsnprintf(buffer, 999, fmt, MyList);
    va_end(MyList);

    OTA_kal_wsprintf(outstr, fmt, MyList);
}







idiv_return $Sub$$__aeabi_idivmod(int numerator, int denominator)
{
    return OTA_aeabi_idivmod(numerator, denominator);
}
uidiv_return $Sub$$__aeabi_uidivmod(unsigned numerator, unsigned denominator)
{
    return OTA_aeabi_uidivmod(numerator, denominator);
}




double $Sub$$__ARM_scalbln(double x, long int n)
{

    return OTA_scalbln(x, n);
}
double $Sub$$__ARM_scalbn(double x, int n)
{

    return OTA_scalbn(x, n);
}
float $Sub$$__ARM_scalbnf(float x, int n)
{

    return OTA_scalbnf(x, n);
}






