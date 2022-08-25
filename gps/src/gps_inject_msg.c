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
 *  gps_inject_msg.c
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
#include "kal_trace.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "tst_sap.h"
#include "dcl.h"
#include "gps_init.h"
#include "gps_uart.h"            /* uart APIs*/
#include "gps_main.h"
#include "string.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"//wjw add for test 20111206
#include "gps_meta_struct.h"//wjw add for test 20111206
#include "gps_agps_process.h"
#include "mtk_gps_type.h"
#include "gps_common.h"
#include "gps_trc.h"
#include "mtk_gps.h"

#ifdef __GPS_ADAPTOR_SUPPORT__
extern mtk_int32 mtk_gps_debug_config(mtk_gps_dbg_type DbgType, mtk_gps_dbg_level DbgLevel);
#ifndef __GPS_EPO_DOWNLOAD__
extern void epofile_download_socket(void);
//extern void epofile_download_open_test(void);
extern void mtk_epo_proc (void);
#endif
#endif

#ifdef UNIT_TEST
extern kal_uint16 gps_command_bsize;
extern kal_uint8 *gps_command_buffer;
extern mtk_bool g_gps_frame_sync_meas_req_by_ftime;
#if defined(__AGPS_SUPPORT__)
extern kal_uint8 area_event;
#endif
kal_bool is_initialization = KAL_FALSE;

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
extern void gps_frame_sync_meas_req(mtk_gps_frame_sync_type_enum application_type); 
#endif
extern void gps_uart_enable_authentication(void);
extern mtk_int32 mtk_gps_sys_frame_sync_meas_req(mtk_gps_fs_work_mode mode);
#endif        
extern kal_uint8 gps_uart_port;
extern kal_uint8 gps_sleep_enable_flag;
extern kal_uint8 gps_power_saving_mode_flag;
extern kal_uint8 gps_power_saving_mode_type;
extern gps_context_struct *gps_context_p;//jiawang add for inject command to change uart baudrate
extern void gps_set_power_saving_mode(kal_uint8 mode);
extern void gps_send_check_id(void);
void gps_inject_frame_sync_power_on_handler(void);
void gps_inject_frame_sync_power_off_handler(void);
kal_uint32 frame_sync_power_on_time, frame_sync_power_off_time, frame_sync_test_count;    
kal_bool disable_stop_power_on_off_timer_flag =KAL_FALSE;
extern kal_bool gps_meta_mode;
extern kal_bool is_inject_command_meta_test ;

#ifdef __BEE_SUPPORT__
extern kal_int32 g_bEnableRandomBEE;
extern kal_int32 g_bRandomBEENumber;
extern void MTK_BEE_Enable_Eph_Update(void);
extern void MTK_BEE_Disable_Eph_Update(void);
#endif /* __BEE_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  gps_inject_meta_mode_test_handler
 * DESCRIPTION
 *  this function is used for testing gps meta operation in normal mode.
 * inject command packet format:
 *   MOD: GPS_MOD
 *   inject_command.index: 22
 *   inject_command.string: 0 or 1 or 2 or 3,6 ....
 *   for example:
 *              power off gps:  GPS_MOD 22 "0"
 *              power on gps:  GPS_MOD 22 "1"
 *              stop test  cmd: GPS_MOD 22 "2"
 *              start test cmd: GPS_MOD 22 "3,29,15"         //3:GPS MP test ,  SV_id =29, 15:means test:TEST_INFOR&TEST_ACQ&TEST_BITSYNC&TEST_SIGNAL
 *              start test cmd: GPS_MOD 22 "3,29,1"           //3:GPS MP test ,  SV_id =29, 1:means test TEST_INFOR
 *              start test cmd: GPS_MOD 22 "4"                  //4:query bitmap,   
 *              start test cmd: GPS_MOD 22 "5"                  //5:GPS CW mode test ,   
 *              stop  test cmd: GPS_MOD 22 "6"                 //6:GPS CW mode test ,    
 *              start test cmd: GPS_MOD 22 "7,29"             //7:GPS CNR mode test , SV_id =29  
 *              stop  test cmd: GPS_MOD 22 "8"                  //8:GPS CNR mode test ,  
 *              start test cmd: GPS_MOD 22 "9"                  //7:GPS FIX mode test ,   
 *              stop  test cmd: GPS_MOD 22 "10"                //8:GPS FIX mode test ,  
 * PARAMETERS
 *  kal_char * inject_string
 * RETURNS
 *  void
 *****************************************************************************/
void gps_inject_meta_mode_test_handler(kal_char * inject_string)
{
    kal_uint32 operate_type;
    kal_uint32 sv_id;
    kal_uint32 bitmap;
    ilm_struct  *ilm_ptr;
    meta_gps_op_req_struct *local_param_ptr; 

    kal_print_string_trace(MOD_GPS,TRACE_FUNC,"[GPS_INJECT]meta mode test string:%s",inject_string);    
    sscanf(inject_string,"%d,%d,%d",&operate_type,&sv_id,&bitmap); 
    
   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (meta_gps_op_req_struct *)construct_local_para(sizeof(meta_gps_op_req_struct), TD_CTRL);

    if (0 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_CLOSE ; 
        gps_meta_mode = KAL_FALSE;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_CLOSE)); 
    }
    else if(1 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_OPEN; 
        gps_meta_mode = KAL_TRUE;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_OPEN)); 
    }
    else if(2 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_STOP_MP_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    } 
    else if(3 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_START_MP_TEST;
        local_param_ptr->cmd.SV_id =sv_id;
        local_param_ptr->cmd.cmd_bitmap = bitmap&0x0f;
        GPS_TRACE((TRACE_FUNC,GPS_INJECT_TRC_OPERATE_AND_CMD,META_GPS_OP_WRITE_CMD,sv_id,bitmap)); 
    }
    else if(4 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_QUERY_CMD_BITMAP;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    }
    else if(5 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_START_CW_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    } 
    else if(6 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_STOP_CW_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    }
    else if(7 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_START_CNR_TEST;
        local_param_ptr->cmd.SV_id =sv_id;
        local_param_ptr->cmd.cmd_bitmap = 0x00;
        GPS_TRACE((TRACE_FUNC,GPS_INJECT_TRC_OPERATE_AND_CMD,META_GPS_OP_WRITE_CMD,sv_id,bitmap)); 
    }
    else if(8 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_STOP_CNR_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    }
    else if(9 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_START_FIX_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    } 
    else if(10 == operate_type)
    {
        local_param_ptr->op_type = META_GPS_OP_WRITE_CMD; 
        local_param_ptr->cmd.cmd_type =META_GPS_OP_STOP_FIX_TEST;
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_OP_TYPE,META_GPS_OP_WRITE_CMD)); 
    }
    else
    {
        GPS_TRACE((TRACE_FUNC,GPS_META_TRC_INALID_OP_TYPE,operate_type)); 
        return;
    }
    is_inject_command_meta_test  = KAL_TRUE ;
    ilm_ptr = allocate_ilm(MOD_GPS);
    ilm_ptr->src_mod_id = MOD_GPS;
    ilm_ptr->dest_mod_id = MOD_GPS;
    ilm_ptr->msg_id = MSG_ID_META_GPS_OP_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);        
}
/*****************************************************************************
 * FUNCTION
 *  gps_power_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_power_test_handler(kal_char * inject_string)
{
    kal_uint32 power_flag;
	sscanf(inject_string, "%d", &power_flag); 
    if (1 == power_flag)
    {
        GPS_Init(NULL);
#ifndef __MNL_SUPPORT__
        kal_sleep_task(100);
        gps_send_check_id();
#endif
    }
#ifdef __GPS_ADAPTOR_SUPPORT__
    else if(11 == power_flag)
    {		
    	gps_debug_info_enable();               //  open raw data to debug log file
       mtk_gps_debug_config(10 , MTK_DBG_INFO);	 // this timing test pass
    	kal_print_string_trace(MOD_GPSADAPTOR, TRACE_FUNC, "GPS Debug Log Opne");
    }				
    else if(12 == power_flag)
    {		
    	gps_debug_info_disable();               //  close raw data to debug log file
       mtk_gps_debug_config(10 , MTK_DBG_DISABLE);	 // this timing test pass
    	kal_print_string_trace(MOD_GPSADAPTOR, TRACE_FUNC, "GPS Debug Log close");
    }	
#endif
    else
    {
        GPS_Shutdown();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_send_command_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_send_command_handler(kal_char * inject_string)
{
    kal_uint8 checksum, inject_command[128]={0}, gps_command[128]={0};
    kal_uint32 i, length;

    /* klocwork issue fix 20121021
     * Max length of inject_string may reach 128, 
     * but length >= 122 will cause buffer overflow
     */
    if(strlen(inject_string) >= 122)
    {
        GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_INJECT_ILLEGAL_STRING));
        return;
    }

    /* [Klocwork] two "122" below just for clearing klocwork issue */
    sscanf(inject_string, "%122s", (char *)&inject_command);
    length = strlen((const char *)inject_command);
    if(length >= 122) return;
    
    checksum = 0;
    for (i = 0; i < length; i++)
    {
        checksum ^= inject_command[i];
        gps_command[i + 1] = inject_command[i];
    }
    gps_command[0] = '$';
    gps_command[length + 1] = '*'; 
    if((checksum >> 4) > 9)
    {
        gps_command[length + 2] = (checksum >> 4) - 10  + 'A' ;
    }
    else
    {
        gps_command[length + 2] = (checksum >> 4) + '0';
    }
    if((checksum & 0xf) > 9)
    {
        gps_command[length + 3] = (checksum & 0xf) - 10 + 'A'; 
    }
    else
    {
        gps_command[length + 3] = (checksum & 0xf) + '0';
    }
    gps_command[length + 4] = 0x0D;
    gps_command[length + 5] = 0x0A;

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);

#ifdef UNIT_TEST
    memcpy (&gps_command_buffer, &gps_command, length + 6);
    gps_command_bsize = length + 6;
#else
    GPS_UART_Write(gps_uart_port, gps_command, length + 6);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  gps_rx_limit_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_rx_limit_test_handler(kal_char * inject_string)
{
    kal_uint8 checksum, gps_command[256]={0};
    char command[]= "PMTK999,83,00,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82";
    kal_uint32 i, length, count;
    
    /* klocwork issue fix 20121021
     * May reference uninitialized variable "count",
     * so need to ensure "count" to be assigned by "sscanf"
     */
    count = 0;
    if( 1 != sscanf(inject_string, "%d", &count) )
    {
        GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_INJECT_ILLEGAL_STRING));
        return; 
    }
    /* [Klocwork] limit range of count */
    if(count > 0x7FFFFFFF) count = 0x7FFFFFFF;
    
    length = strlen((const char *)command);
    checksum = 0;
    for (i = 0; i < length; i++)
    {
        checksum ^= command[i];
        gps_command[i + 1] = command[i];
    }
    gps_command[0] = '$';
    gps_command[length + 1] = '*'; 
    if((checksum >> 4) > 9)
    {
        gps_command[length + 2] = (checksum >> 4) - 10 + 'A';
    }
    else
    {
        gps_command[length + 2] = (checksum >> 4) + '0';
    }
    if((checksum & 0xf) > 9)
    {
        gps_command[length + 3] = (checksum & 0xf) - 10 + 'A'; 
    }
    else
    {
        gps_command[length + 3] = (checksum & 0xf) + '0';
    }
    gps_command[length + 4] = 0x0D;
    gps_command[length + 5] = 0x0A;

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);
    
    for (i = 0; i < count; i++)
    {
        GPS_UART_Write(gps_uart_port, gps_command, length + 6);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_uart_change_baudrate_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_uart_change_baudrate_handler(kal_char * inject_string)
{
    kal_uint8 checksum, gps_command[128]={0};
    kal_uint32 i, length, baudrate;

    sscanf(inject_string, "%d", &baudrate); 
    if (gps_context_p->gps_state == GPS_POWERON_STATE)
    {
            
        if (1 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0060*");
        }
        else if (2 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0360*");
        }
        else if (3 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0260*");
        }
        else if (4 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0160*");
        }
        else
        {
            //jiawang add for deal with the fatal error(When command ==invalid)
            GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_UART_BAUDRATE_SETTING_INVALID));
            return;        
        }
    
    length = strlen((const char *)gps_command);

    /* [Klocwork]should not be a problem, 
     * but just for clearing klocwork issue */
    if(length >= 120) return;

    checksum = 0;
    for (i = 1; i < length - 1; i++)
    {
        checksum ^= gps_command[i];        
    }

        if((checksum >> 4) > 9)
        {
            gps_command[length] = (checksum >> 4) - 10 + 'A';
        }
        else
        {
            gps_command[length] = (checksum >> 4) + '0';
        }
        if((checksum & 0xf) > 9)
        {
            gps_command[length + 1] = (checksum & 0xf) - 10 + 'A'; 
        }
        else
        {
            gps_command[length + 1] = (checksum & 0xf) + '0';
        }
        gps_command[length + 2] = 0x0D;
        gps_command[length + 3] = 0x0A;

        GPS_UART_Write(gps_uart_port, gps_command, length + 4); 
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);
        kal_sleep_task(10);
        
    if (1 == baudrate)
    {
        GPS_SetUART(UART_BAUD_115200, FC_NONE);
    }
    else if (2 == baudrate)
    {
        GPS_SetUART(UART_BAUD_230400, FC_NONE);
    }
    else if (3 == baudrate)
    {
        GPS_SetUART(UART_BAUD_460800, FC_NONE);
    }
    else if (4 == baudrate)
    {
        GPS_SetUART(UART_BAUD_921600, FC_NONE);
        }
        else
        {
            //jiawang add for deal with the fatal error(When command ==invalid)
            return;        
        }
    }
    else{
        GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_OPEN_NOTIFY));
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gps_set_misc_variable
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_misc_variable(kal_char * inject_string)
{
    kal_uint32 variable, value;
    sscanf(inject_string, "%d,%d", &variable, &value); 
    if (1 == variable)
    {
    	GPS_TRACE((TRACE_INFO, GPS_TRC_INF_STATE_CHANGE_SlEEP_FLAG, 
			gps_sleep_enable_flag, value));
        gps_sleep_enable_flag = value;
    }
    else if (2 == variable)
    {
    	GPS_TRACE((TRACE_INFO, GPS_TRC_INF_STATE_CHANGE_POWER_FLAG, 
			gps_power_saving_mode_flag, value));
        gps_power_saving_mode_flag = value;
    }
    else if (3 == variable)
    {
    	GPS_TRACE((TRACE_INFO, GPS_TRC_INF_STATE_CHANGE_POWER_TYPE, 
			gps_power_saving_mode_type, value));
        gps_power_saving_mode_type = value;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_set_misc_variable
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_power_saving_mode_handler(kal_char * inject_string)
{
    // kal_int32 mode;
    /* [Klocwork] kal_int32 -> int */
    int mode = 0;
    sscanf(inject_string, "%d", &mode);
    GPS_TRACE((TRACE_INFO, GPS_TRC_INF_SLEEP_INJECT_SET_POWER_SAVING, mode));
#ifdef __MNL_SUPPORT__    
    gps_set_power_saving_mode(mode);    
#endif /* __MNL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_power_on_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_inject_frame_sync_power_on_handler(void)
{
    GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_OPEN_GPS,frame_sync_test_count));
    GPS_Init(NULL);    
    gps_start_timer(GPS_POWER_ON_OFF_TIMER, frame_sync_power_on_time, (kal_timer_func_ptr)gps_inject_frame_sync_power_off_handler, 0);                 
    
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_power_off_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_inject_frame_sync_power_off_handler(void)
{
    if (frame_sync_test_count > 0)    
    {
        GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_CLOSE_GPS,frame_sync_test_count));
        if (frame_sync_test_count ==1){
            GPS_Shutdown(); 
         }
        else{
            disable_stop_power_on_off_timer_flag =KAL_TRUE;
            GPS_Shutdown(); 
            gps_start_timer(GPS_POWER_ON_OFF_TIMER, frame_sync_power_off_time, (kal_timer_func_ptr)gps_inject_frame_sync_power_on_handler, 0);                 
        }
        frame_sync_test_count--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_frame_sync_test_handler(kal_char * inject_string)
{
    sscanf(inject_string, " %d , %d , %d ", &frame_sync_test_count, &frame_sync_power_on_time, &frame_sync_power_off_time);
	GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_COUNT,frame_sync_test_count,frame_sync_power_on_time,frame_sync_power_off_time));
    gps_inject_frame_sync_power_on_handler();// modify from power off handler to power on handler 
    
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_bee_test_handler(kal_char * inject_string)
{
#ifdef __BEE_SUPPORT__	
    kal_uint32 mode;
    sscanf(inject_string, "%d", &mode); 
    if (0 == mode)
    {
        MTK_BEE_Disable_Eph_Update();
    }
    else
    {
        MTK_BEE_Enable_Eph_Update();        
    }
#endif /* __BEE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_bee_radom_sv_test_handler(kal_char * inject_string)
{
#ifdef  __BEE_SUPPORT__
    kal_uint32 mode, value;
    sscanf(inject_string, "%d,%d", &mode, &value); 
    if (0 == mode)
    {
        g_bEnableRandomBEE = 0;
    }
    else
    {
        g_bEnableRandomBEE = 1;        
    }
    if (value < 4)
    {
        g_bRandomBEENumber = 4;
    }
    else
    {
        g_bRandomBEENumber = value;
    }
#endif /* __BEE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_set_pos_report_deley_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_pos_report_deley_handler(kal_char * inject_string)
{
/* only support in AGPS */
#if defined(__AGPS_SUPPORT__)
    kal_uint32 enable, delay_count;
    sscanf(inject_string, "%d,%d", &enable, &delay_count); 
	if (enable)
	{
		gps_agps_set_pos_report_deley(KAL_TRUE, delay_count);
	}
	else
	{
		gps_agps_set_pos_report_deley(KAL_FALSE, delay_count);
	}
#endif
}
/****
gps_inject_modem_power_on_off_test_handler
modem load GPS power on/off test
***/
void gps_inject_modem_power_on_off_test_handler(kal_char * inject_string)
{
    kal_uint32 power_flag;
    kal_uint32 gps_work_mode;

    sscanf(inject_string,"%d,%d",&power_flag,&gps_work_mode); 
    kal_print_string_trace(MOD_GPS, TRACE_GROUP_4, "gps_work_mode:%d",gps_work_mode);

    if(gps_work_mode > GPS_UART_MODE_LOCATION_WITH_QOP)
    {
        return;
    }
    if (1 == power_flag)
    {
        gps_power_on_req((gps_common_uart_work_mode_enum)gps_work_mode);
    }
    else
    {
        gps_power_off_req((gps_common_uart_work_mode_enum)gps_work_mode );
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_tst_inject_string_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_tst_inject_string_handler( ilm_struct *ilm_ptr )
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;
    if (1 == tst_inject->index)
    {
        gps_inject_power_test_handler((kal_char *)tst_inject->string);
    }
    else if (2 == tst_inject->index)
    {
        gps_inject_send_command_handler((kal_char *)tst_inject->string);        
    }
    else if (3 == tst_inject->index)
    {
        gps_inject_rx_limit_test_handler((kal_char *)tst_inject->string);    
    }
    else if (4 == tst_inject->index)
    {
        gps_inject_uart_change_baudrate_handler((kal_char *)tst_inject->string);    
    }
    else if (5 == tst_inject->index)
    {
        gps_inject_set_misc_variable((kal_char *)tst_inject->string);    
    }
    else if (6 == tst_inject->index)
    {
        gps_inject_set_power_saving_mode_handler((kal_char *)tst_inject->string);
    }
    else if (7 == tst_inject->index)
    {
        gps_inject_frame_sync_test_handler((kal_char *)tst_inject->string);
    }
    else if (8 == tst_inject->index)
    {
        gps_inject_bee_test_handler((kal_char *)tst_inject->string);
    }
    else if (9 == tst_inject->index)
    {
        gps_inject_bee_radom_sv_test_handler((kal_char *)tst_inject->string);
    }
	else if (10 == tst_inject->index)
    {
        gps_inject_set_pos_report_deley_handler((kal_char *)tst_inject->string);
    }
#ifdef UNIT_TEST
    else if (11 == tst_inject->index)
    {
        if(is_initialization == KAL_FALSE)
        {
            gps_uart_state_init();
            is_initialization = KAL_TRUE;
        }
    }
    else if (12 == tst_inject->index)
    {
        gps_inject_send_command_handler((kal_char *)tst_inject->string);
        gps_uart_ready_to_read_ind(NULL);
    }
#endif
    else if (13 == tst_inject->index)
	{
        if (tst_inject->string[0] == '1')
            gps_debug_info_enable();
        else if(tst_inject->string[0] == '2')
            gps_debug_info_disable();

        if (tst_inject->string[1] == '1')
            gps_power_saving_mode_enable();
        else if(tst_inject->string[1] == '2')
            gps_power_saving_mode_disable(); 

        if (tst_inject->string[2] == '1')
            gps_enable_parser();
        else if(tst_inject->string[2] == '2')
            gps_disable_parser();

        if (tst_inject->string[3] == '1')
            gps_logging_agent_enable();
        else if(tst_inject->string[3] == '2')
            gps_logging_agent_disable();

        if (tst_inject->string[4] == '1')
            gps_logging_catcher_enable();
        else if(tst_inject->string[4] == '2')
            gps_logging_catcher_disable();

        if (tst_inject->string[5] == '1')
            gps_nmea_eng_sentence_enable();
        else if(tst_inject->string[5] == '2')
            gps_nmea_eng_sentence_disable();
        if (tst_inject->string[6] == '1')
            gps_set_hotstill_debug_mode(KAL_TRUE); //enable
        else if (tst_inject->string[6] == '2')
            gps_set_hotstill_debug_mode(KAL_FALSE); //disable

        if (tst_inject->string[7] == '1')
            gps_set_hotstill_shutdown_mode(KAL_TRUE); //shutdown
        else if (tst_inject->string[7] == '2')
            gps_set_hotstill_shutdown_mode(KAL_FALSE); //resume

        if (tst_inject->string[8] == '1')
	          gps_uart_enable_authentication(); //shutdown
	          
        if (tst_inject->string[9] == '1')
            gps_logging_file_enable();
        else if(tst_inject->string[9] == '2')
            gps_logging_file_disable();

        if (tst_inject->string[10] == '1')
            gps_mnl_debug_info_enable();
        else if(tst_inject->string[10] == '2')
            gps_mnl_debug_info_disable();
    }
#ifdef UNIT_TEST
    else if (14 == tst_inject->index)
	{
        gps_common_nmea_info_struct nmea_ptr;
		
        gps_get_nmea_location(tst_inject->string[0], &nmea_ptr);
    }
    else if (15 == tst_inject->index)
	{
        kal_uint8 buffer[257];
		kal_uint32 readed;

        gps_uart_read_data_dbg(tst_inject->string[0], buffer, 256, &readed);
		
    }
#if defined(__AGPS_SUPPORT__)
    else if (16 == tst_inject->index) //verify gps_agps_set_history_pos & gps_agps_get_history_pos
    {
        gps_pos_result_struct history_pos; 
        kal_uint16 bitmap;
        if(tst_inject->string[0] == 0)
        {
            gps_pos_qop_struct qop;
            gps_agps_get_history_pos(&qop,&history_pos, &bitmap);
        }
        else
        {
            gps_agps_set_pos_struct qop;
            memcpy(&qop, tst_inject->string, sizeof(gps_agps_set_pos_struct));
            gps_agps_set_history_pos(&qop);
        }
    }
#endif

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
    else if (17 == tst_inject->index) //send a frame sync meas request to issue a frame pulse
    {
        switch(tst_inject->string[0])
        {
            case 1:
                g_gps_frame_sync_meas_req_by_ftime = KAL_TRUE;
                gps_frame_sync_meas_req(0);
                break;
            case 2:
                g_gps_frame_sync_meas_req_by_ftime = KAL_FALSE;
                gps_frame_sync_meas_req(1);
                break;
            case 3:
                mtk_gps_sys_frame_sync_meas_req(tst_inject->string[1]); //MTK_GPS_FS_WORK_MODE_AIDING
                break;
            default:
                break;
        }
    }
#endif
	else if (18 == tst_inject->index) //simulate MDI callback function: gps_uart_read_data_nmea
	{
	    kal_uint8 buffer[257];
		kal_uint32 readed;
		
		gps_uart_read_data_nmea(MOD_MMI, tst_inject->string[0], buffer, 256, &readed);
	}
	else if (19 == tst_inject->index)  //simulate MDI gps_uart_write_gps_cmd
	{
	    gps_uart_write_gps_cmd(0, tst_inject->string[0], NULL);
	}
#if defined(__AGPS_SUPPORT__)
	else if (20 == tst_inject->index)  //AREA Event: shape and direction
	{
	   area_event = tst_inject->string[0];	   
	}
#endif
	else if (21 == tst_inject->index)  //send from MMI to GPS, GPS_UART_OPEN_SWITCH_REQ
	{
	   gps_uart_clear_on_broad_gps_nvram();   
	}
#endif
    else if (22 == tst_inject->index)  /*testing gps meta operation in normal mode*/
    {
        gps_inject_meta_mode_test_handler((kal_char *)tst_inject->string);
    }
    else if (23 == tst_inject->index)
    {
        gps_inject_modem_power_on_off_test_handler((kal_char *)tst_inject->string);
    }
#if defined(__GPS_ADAPTOR_SUPPORT__) && !defined(__GPS_EPO_DOWNLOAD__)
    else if (24 == tst_inject->index)
    {
        //epofile_download_socket();
    }
    else if (25 == tst_inject->index)
    {
        //epofile_download_open_test();
    }
    else if(26 == tst_inject->index)
    {
    	mtk_epo_proc();

	}
#endif
#ifdef __GPS_EPO_DOWNLOAD__
    else if(27 == tst_inject->index)
    {
        epo_download_3_day();
    }
    else if(28 == tst_inject->index)
    {
        epo_qepo_download();
    }
#endif
	else
	{
		GPS_TRACE((TRACE_WARNING, GPS_TRC_WRN_INJECT_ILLEGAL_CMD, tst_inject->index));
	}

}

#endif /* __GPS_SUPPORT__ */
