/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_modem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__
#include <stdio.h>
#include "stack_msgs.h"         /* enum for message IDs */


#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"      

#include "gps_trc.h"
#include "gps_uart.h"
#include "gps_uart_hdlr.h"
#include "gps_common.h"


extern gps_uart_context_struct g_gps_cntx;
extern void gps_uart_read_one_sentence_ring_buffer(gps_uart_ring_sentence_buffer_struct *handle, kal_uint8 mod_index, kal_uint8 *buffer, kal_uint16 length,kal_uint32 *readed);


#define GPS_NMEA_CATCHER_LOGGING_FLAG       (1<<0)
#define GPS_NMEA_FILE_LOGGING_FLAG          (1<<1)
#define GPS_NMEA_AGENT_LOGGING_FLAG         (1<<2)
#define GPS_NMEA_DEBUG_INFO_FLAG            (1<<3)
#define GPS_NMEA_POWER_SAVING_FLAG          (1<<4)
#define GPS_NMEA_HOTSTILL_FLAG              (1<<5)
#define GPS_NMEA_HOTSTILL_DEBUG_FLAG        (1<<6)
#define GPS_NMEA_LOGGING_DEFAULT_FLAG       (0x01)
#define GPS_NMEA_MESSAGE_MAX_LENGTH         (100)
#define GPS_NMEA_FILENAME_LENGTH            (60)
#define GPS_NMEA_FILE_LOGGING_WRITE_TIME    (20)
#define GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME  (200)

#define GPS_RAW_DATA_PER_CB                 (256)
#define GPS_RAW_DATA_PER_EXTEND             (1024*5)

kal_int32 ret_value;


/*****************************************************************************
* FUNCTION
*  gps_send_msg_to_gps_task
* DESCRIPTION
*  send message to gps module
* PARAMETERS
*  msg_id                [IN]        message ID
*  local_param_ptr   [IN]        message local parameter pointer
*  para_size            [IN]        message local parameter size
*****************************************************************************/
void gps_send_msg_to_gps_task(msg_type msg_id,void *local_param_ptr, kal_uint32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct  *ilm_ptr;
    module_type src_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_mod = stack_get_active_module_id();
    ilm_ptr = allocate_ilm(src_mod);
    ilm_ptr->src_mod_id = src_mod;
    ilm_ptr->dest_mod_id = MOD_GPS;
    ilm_ptr->sap_id = GPS_MNL_SAP;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}

/*****************************************************************************
* FUNCTION
*  gps_power_on_req
* DESCRIPTION
*  API of gps power on request, use sending message method
* PARAMETERS
*  work_mode         [IN]        GPS work mode
*  work_mode value:
*           GPS_UART_MODE_RAW_DATA                  Just need raw data
*           GPS_UART_MODE_LOCATION                   Just need location
*           GPS_UART_MODE_LOCATION_WITH_QOP  Need AGPS data with Qop
*****************************************************************************/
void gps_power_on_req(gps_common_uart_work_mode_enum work_mode)
{   
    gps_uart_open_req_struct   *local_param_ptr;
    module_type                 module_id;
    kal_eventgrpid              eventid;
    kal_int32                  *return_val = &ret_value ;
    
    module_id =  stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_open_req_struct),TD_CTRL);
    local_param_ptr->port = GPS_Get_UART_Port();
    local_param_ptr->mode = work_mode;
    local_param_ptr->return_val = return_val;
    local_param_ptr->module_id = module_id;
    eventid = g_gps_cntx.event_id ;
    local_param_ptr->event_id = eventid;
	GPS_TRACE((TRACE_INFO, GPS_TRC_INF_UART_OPEN_INJECT_SEND_MSG));
    gps_send_msg_to_gps_task(   MSG_ID_GPS_UART_OPEN_REQ,
                                local_param_ptr,
                                sizeof(gps_uart_open_req_struct));
}

/*****************************************************************************
* FUNCTION
*  gps_power_off_req
* DESCRIPTION
*  API of gps power off request, use sending message method
* PARAMETERS
*  work_mode         [IN]        GPS work mode
*  work_mode value:
*           GPS_UART_MODE_RAW_DATA                  Just need raw data
*           GPS_UART_MODE_LOCATION                   Just need location
*           GPS_UART_MODE_LOCATION_WITH_QOP  Need AGPS data with Qop
*****************************************************************************/
void gps_power_off_req(gps_common_uart_work_mode_enum work_mode)
{   
    gps_uart_close_req_struct  *local_param_ptr;
    module_type                 module_id;
    kal_eventgrpid              eventid;
    
    module_id =  stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_close_req_struct),TD_CTRL);
    local_param_ptr->port = GPS_Get_UART_Port();
    local_param_ptr->mode = work_mode;
    local_param_ptr->module_id = module_id;
    eventid = g_gps_cntx.event_id ;
    local_param_ptr->event_id = eventid;
	GPS_TRACE((TRACE_INFO, GPS_TRC_INF_UART_CLOSE_INJECT_SEND_MSG));
    gps_send_msg_to_gps_task(   MSG_ID_GPS_UART_CLOSE_REQ,
                                local_param_ptr,
                                sizeof(gps_uart_close_req_struct));

}
/*****************************************************************************
* FUNCTION
*  gps_uart_get_nmea_location
* DESCRIPTION
*  get NMEA data
* PARAMETERS
*  nmea_ptr [OUT]   buffer to store data
* RETURNS
*  bitmap of NMEA
*****************************************************************************/
kal_uint8 gps_uart_get_nmea_location(gps_common_nmea_info_struct *nmea_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id;
    kal_uint8   j, bitmap = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_gps_cntx.parser.mutex);
    module_id = stack_get_active_module_id();
    for (j = 0; j < GPS_UART_MAX_MOD_PER_PORT; j++)
    {
        if (g_gps_cntx.port.port_num == GPS_Get_UART_Port()&&
            g_gps_cntx.port.is_location_mode[j] == KAL_TRUE &&
            g_gps_cntx.port.mod_id[j] == module_id)
        {
            g_gps_cntx.port.is_need_location_ind[j] = KAL_TRUE;
            bitmap = g_gps_cntx.port.nmea_to_app_bit[j];
            g_gps_cntx.port.nmea_to_app_bit[j] = 0;
            break;
        }
    }
    memcpy(nmea_ptr, &g_gps_cntx.parser.nmea_to_app, sizeof(gps_common_nmea_info_struct));
    kal_give_mutex(g_gps_cntx.parser.mutex);
    return bitmap;
}

/*****************************************************************************
* FUNCTION
*  gps_uart_command_write
* DESCRIPTION
*  write data to uart port
* PARAMETERS
*  *buffer      [IN]        the data need send to UART
*  length       [IN]        data length
*  *write       [IN]        return the number of byte writen here
* RETURNS
*  MDI_RESULT
*****************************************************************************/
kal_uint32 gps_uart_command_write(void* buffer, kal_uint32 length, kal_uint32 *write)
{
    gps_uart_write_req_struct          *local_param_ptr;
    module_type                         module_id;
    kal_int32                           ret;
    ilm_struct  *ilm_ptr;

    module_id = stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_write_req_struct),TD_CTRL);
    local_param_ptr->port = GPS_Get_UART_Port();
    local_param_ptr->return_val = &ret;
    local_param_ptr->is_rawdata = KAL_TRUE;
    local_param_ptr->length = length;
    local_param_ptr->buffer = buffer;
    local_param_ptr->return_written = write;
    local_param_ptr->event_id = NULL;
    local_param_ptr->module_id = module_id;

    ilm_ptr = allocate_ilm(module_id);
    ilm_ptr->src_mod_id = module_id;
    ilm_ptr->dest_mod_id = MOD_GPS;
    ilm_ptr->sap_id = GPS_MNL_SAP;
    ilm_ptr->msg_id = MSG_ID_GPS_UART_WRITE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
    return 0;
}
 

/*****************************************************************************
* FUNCTION
*  gps_nmea_get_filename
* DESCRIPTION
*  make the file name for file logging
* PARAMETERS
* *buffer       [OUT]      the name of file
*  length       [IN]         the buffer lenght
* *ext_name [IN]         the type of file
* RETURNS
*  KAL_TRUE     get  file name ok
*  KAL_FALSE    get  file name failed
*****************************************************************************/
kal_bool gps_nmea_get_filename(kal_uint16 *buffer,kal_uint32 length, kal_char *ext_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_HANDLE          rtc_handler = 0;
    kal_int32           driver, ret;
    kal_uint16          path[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length < GPS_NMEA_FILENAME_LENGTH)
    {
        return KAL_FALSE;
    }
    memset( &rtc_time, 0, sizeof(rtc_time));
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)& rtc_time);
    DclRTC_Close(rtc_handler);
    /*get memory card driver letter*/
    driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    if (driver < FS_NO_ERROR)
    {
        /*no card we get normal driver*/
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"[debug file open]driver:%d",driver);
        if (driver < FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
    }
    kal_wsprintf(path,"%c:\\GPSlog",(kal_uint8)driver);
    FS_CreateDir(path);
    ret = FS_SetCurrentDir(path);
    if (ret != FS_NO_ERROR)
    {
        /*no card we get normal driver*/
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        kal_print_string_trace(MOD_MNL,TRACE_GROUP_3 ,"[debug file open]path:%s",path);
        if (driver < FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
        kal_wsprintf(path,"%c:\\GPSlog",(kal_uint8)driver);
        FS_CreateDir(path);
        ret = FS_SetCurrentDir(path);
        if (ret != FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
    }
    kal_wsprintf(path,"%c:\\",(kal_uint8)driver);
    FS_SetCurrentDir(path);
    kal_wsprintf(buffer,
        "%c:\\GPSlog\\%2d%2d%2d%2d%2d%2d.%s",
        (kal_uint8)driver,
        rtc_time.u1Year,
        rtc_time.u1Mon,
        rtc_time.u1Day,
        rtc_time.u1Hour,
        rtc_time.u1Min,
        rtc_time.u1Sec,
        ext_name
        );
    return KAL_TRUE;
}



/*****************************************************************************
* FUNCTION
*  gps_open_debug_log_file
* DESCRIPTION
*  process and open log file name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gps_open_debug_log_file(void)
{

    kal_bool   ret;
    kal_uint16 filename[GPS_NMEA_FILENAME_LENGTH];

    if (g_gps_cntx.logging.file_handle >= 0)
    {
        FS_Close(g_gps_cntx.logging.file_handle);
        g_gps_cntx.logging.file_handle = -1;
    }
    if (g_gps_cntx.logging.debug_info_file_handle >= 0)
    {
        FS_Close(g_gps_cntx.logging.debug_info_file_handle);
        g_gps_cntx.logging.debug_info_file_handle = -1;
    }
    g_gps_cntx.logging.file_pre_allocate_failed = KAL_FALSE;
    g_gps_cntx.logging.debug_info_file_pre_allocate_failed = KAL_FALSE;
    g_gps_cntx.logging.file_pre_allocate = 0;
    g_gps_cntx.logging.debug_info_file_pre_allocate = 0;
    if (g_gps_cntx.logging.debug_info != KAL_TRUE &&
        g_gps_cntx.logging.file_logging == KAL_TRUE)
    {
        /*construct file name and open the file in write MOD*/
        ret = gps_nmea_get_filename(filename,GPS_NMEA_FILENAME_LENGTH,"nma");
        if (ret == KAL_TRUE)
        {
            g_gps_cntx.logging.file_handle = FS_Open(filename, FS_CREATE_ALWAYS);
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"[nma file open]file handle:%d",g_gps_cntx.logging.file_handle);
            GPS_TRACE((TRACE_INFO, GPS_TRC_INF_FILE_OPEN_NMA, g_gps_cntx.logging.file_handle, FS_CREATE_ALWAYS));
        }
        else
        {
            /*make file name error, no need process now*/
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"[nma file open]open file error!");
            GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_GET_DRIVE_FAIL));
        }
    }
    else if (g_gps_cntx.logging.file_logging == KAL_TRUE &&
        g_gps_cntx.logging.debug_info == KAL_TRUE)
    {
        /*construct file name and open the file in write MOD*/
        ret = gps_nmea_get_filename(filename,GPS_NMEA_FILENAME_LENGTH,"dbg");
        if (ret == KAL_TRUE)
        {
            g_gps_cntx.logging.debug_info_file_handle = FS_Open(filename, FS_CREATE_ALWAYS);
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"[debug file open]file handle:%d",g_gps_cntx.logging.debug_info_file_handle);
            GPS_TRACE((TRACE_INFO, GPS_TRC_INF_FILE_OPEN_DBG, 
                g_gps_cntx.logging.debug_info_file_handle, FS_CREATE_ALWAYS));
        }
        else
        {
            /*make file name error, no need process now*/
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"[debug  file open]open file error!");
            GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_GET_DRIVE_FAIL));
        }
    }
}

/*****************************************************************************
* FUNCTION
*  gps_close_debug_log_file
* DESCRIPTION
*  close log file
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gps_close_debug_log_file(void)
{
    if (g_gps_cntx.logging.file_handle >= 0)
    {
        GPS_TRACE((TRACE_INFO,GPS_TRC_INF_FILE_CLOSE_NMA, g_gps_cntx.logging.file_handle));
        FS_Close(g_gps_cntx.logging.file_handle);
        g_gps_cntx.logging.file_handle = -1;
    }
    if (g_gps_cntx.logging.debug_info_file_handle >= 0)
    {
        GPS_TRACE((TRACE_INFO,GPS_TRC_INF_FILE_CLOSE_DBG, g_gps_cntx.logging.debug_info_file_handle));
        FS_Close(g_gps_cntx.logging.debug_info_file_handle);
        g_gps_cntx.logging.debug_info_file_handle = -1;
    }
}


/*****************************************************************************
* FUNCTION
*  gps_logging_file_pre_allocate
* DESCRIPTION
*  pre-allocate file space
* PARAMETERS
*  handle           [IN]        file handle
*  num_allocated    [IN/OUT]    in still left and out the number after allocated
* RETURNS
*  KAL_FALSE    allocate failed, maybe disk full
*  KAL_TRUE     allocate OK
*****************************************************************************/
 kal_bool gps_logging_file_pre_allocate(FS_HANDLE handle, kal_uint32* num_allocated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0)
    {
        return KAL_FALSE;
    }
    if (*num_allocated <= GPS_RAW_DATA_PER_CB)
    {
        ret_code = FS_Extend(handle, GPS_RAW_DATA_PER_EXTEND);        
        kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"file pre-allocate. handle:%d. num_allocated:%d",handle,*num_allocated);
        if (ret_code < 0)
        {
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"file pre-allocate.ret_code:%d.",ret_code);
            return KAL_FALSE;
        }
        else
        {
            *num_allocated += GPS_RAW_DATA_PER_EXTEND;
            kal_print_string_trace(MOD_GPS,TRACE_GROUP_3 ,"file pre-allocate new. handle:%d. num_allocated:%d",handle,*num_allocated);
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*  gps_write_debug_info_log_file
* DESCRIPTION
*  the message proccess function of debug infor raw data 
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/

void gps_write_debug_info_log_file(kal_uint16 port)
{

    kal_uint8       raw_buffer[GPS_RAW_DATA_PER_CB + 1];
    module_type     module_id;
    kal_uint32      written;
    kal_uint32      readed;
    kal_bool        ok_to_write = KAL_FALSE;
    int             result;

    module_id = stack_get_active_module_id();
    gps_uart_read_data_dbg(port,raw_buffer,GPS_RAW_DATA_PER_CB,&readed);
    ASSERT(readed<=GPS_RAW_DATA_PER_CB);
    if (g_gps_cntx.logging.debug_info_file_pre_allocate_failed == KAL_FALSE)
    {
        ok_to_write = gps_logging_file_pre_allocate(
            g_gps_cntx.logging.debug_info_file_handle,
            &g_gps_cntx.logging.debug_info_file_pre_allocate);
        if (ok_to_write == KAL_FALSE)
        {
            g_gps_cntx.logging.debug_info_file_pre_allocate_failed = KAL_TRUE;
            GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_PRE_ALLOC_FAIL));
        }
    }
    if (readed > 0)
    {
        if (g_gps_cntx.logging.file_logging == KAL_TRUE &&
            module_id == MOD_GPS &&
            ok_to_write == KAL_TRUE)
        {
            result = FS_Write(
                g_gps_cntx.logging.debug_info_file_handle,
                raw_buffer,
                readed,
                &written);
            
            if(0 != result)
            {
                GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_WRITE_DBG_FAIL));
            }
            g_gps_cntx.logging.debug_info_file_pre_allocate -= written;
            g_gps_cntx.logging.debug_info_file_write_count++;
            if (g_gps_cntx.logging.debug_info_file_write_count> GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME)
            {
                FS_Commit(g_gps_cntx.logging.debug_info_file_handle);
                g_gps_cntx.logging.debug_info_file_write_count = 0;
            }
        }
    }
    while (readed == GPS_RAW_DATA_PER_CB)
    {
        gps_uart_read_data_dbg(port,raw_buffer,GPS_RAW_DATA_PER_CB,&readed);
        ASSERT(readed<=GPS_RAW_DATA_PER_CB);
        if (g_gps_cntx.logging.file_logging == KAL_TRUE &&
            module_id == MOD_GPS &&
            ok_to_write == KAL_TRUE)
        {
            result = FS_Write(
                g_gps_cntx.logging.debug_info_file_handle,
                raw_buffer,
                readed,
                &written);

            if(0 != result)
            {
                GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_WRITE_DBG_FAIL));
            }
            g_gps_cntx.logging.debug_info_file_pre_allocate -= written;
            g_gps_cntx.logging.debug_info_file_write_count++;
            if (g_gps_cntx.logging.debug_info_file_write_count> GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME)
            {
                FS_Commit(g_gps_cntx.logging.debug_info_file_handle);
                g_gps_cntx.logging.debug_info_file_write_count = 0;
            }
        }
    }
}
/*****************************************************************************
* FUNCTION
*  gps_write_log_file
* DESCRIPTION
*  callback app according to the message mdi get
* PARAMETERS
*  type        [IN]        callback type
*  port        [IN]        port number
*  *buffer     [IN]        data buffer
*  length      [IN]        data length
* RETURNS
*  void
*****************************************************************************/
void gps_write_log_file( gps_common_parser_info_enum type, kal_uint16 port, void *buffer, kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  written;
    kal_bool    ok_to_write = KAL_FALSE;
    int         result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (type == GPS_PARSER_RAW_DATA &&
        g_gps_cntx.logging.file_logging == KAL_TRUE &&
        g_gps_cntx.logging.debug_info == KAL_FALSE )
    {

        if (g_gps_cntx.logging.file_pre_allocate_failed == KAL_FALSE)
        {
            ok_to_write = gps_logging_file_pre_allocate(
                g_gps_cntx.logging.file_handle,
                &g_gps_cntx.logging.file_pre_allocate);
            if (ok_to_write == KAL_FALSE)
            {
                g_gps_cntx.logging.file_pre_allocate_failed = KAL_TRUE;
                GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_PRE_ALLOC_FAIL));
            }
        }
        if (ok_to_write == KAL_TRUE)
        {
            result = FS_Write(
                g_gps_cntx.logging.file_handle,
                buffer,
                length,
                &written);
            
            if(0 != result)
            {
                GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_FILE_WRITE_NMA_FAIL));
            }
            g_gps_cntx.logging.file_pre_allocate -= written;
            g_gps_cntx.logging.file_write_count++;
            if (g_gps_cntx.logging.file_write_count > GPS_NMEA_FILE_LOGGING_WRITE_TIME)
            {
                FS_Commit(g_gps_cntx.logging.file_handle);
                g_gps_cntx.logging.file_write_count = 0;
            }
        }
    }
}

/*****************************************************************************
* FUNCTION
*  gps_write_nmea_raw_data_log_file
* DESCRIPTION
*  the message proccess function of raw data ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
void gps_write_nmea_raw_data_log_file(kal_uint16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8      raw_buffer[GPS_RAW_DATA_PER_CB + 1];
    kal_uint8      j;
    kal_uint32     readed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* klocwork issue fix 20121021
     * Initialize "readed = 0" to deal with the scenario 
     * it isn't assigned by "if", which may cause unexpected assert.
     */
    readed = 0;
    
    if( g_gps_cntx.port.port_num == port){
        for(j = 0 ; j < GPS_UART_MAX_MOD_PER_PORT; j++){
            if (g_gps_cntx.port.mod_id[j] != MOD_NIL) {
                gps_uart_read_one_sentence_ring_buffer(&(g_gps_cntx.port.nmea_ring),j,raw_buffer,GPS_RAW_DATA_PER_CB,&readed);
                break;
            }
        }
    }
    else
    {
        GPS_TRACE((TRACE_WARNING, 
            GPS_TRC_WRN_UART_READ_SEND_ERR_PORT, port, g_gps_cntx.port.port_num));
        return;
    }
    
    ASSERT(readed<=GPS_RAW_DATA_PER_CB);
    raw_buffer[readed] = 0;
    if (readed > 0)
    {
        gps_write_log_file( GPS_PARSER_RAW_DATA,
                            port,
                            raw_buffer,
                            readed);
    }
    while (readed > 0)
    {
        if( g_gps_cntx.port.port_num == port){
            for(j = 0 ; j < GPS_UART_MAX_MOD_PER_PORT; j++){
                if (g_gps_cntx.port.mod_id[j] != MOD_NIL) {
                    gps_uart_read_one_sentence_ring_buffer(&(g_gps_cntx.port.nmea_ring),j,raw_buffer,GPS_RAW_DATA_PER_CB,&readed);
                    break;
                }
            }
        }
        ASSERT(readed<=GPS_RAW_DATA_PER_CB);
        raw_buffer[readed] = 0;
        if (readed > 0)
        {
            gps_write_log_file( GPS_PARSER_RAW_DATA,
                                port,
                                raw_buffer,
                                readed);
        }
    }
}

#endif /* __GPS_SUPPORT__ */
