/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *     kal_adaptation_target.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file implements the adaptation layer of KTEST on target.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* this file is valid only when __KTEST__ and __MTK_TARGET__ is defined */
#if defined( __KTEST__ ) && defined( __MTK_TARGET__ )
 
#include "ktest_common.h"
#include "mmsys_pwrmgr.h"
#include "uart_sw.h"
#include "l1_interface.h"
#include "intrctrl.h"
#include "kal_release.h"
#include "reg_base.h"
#include "syscomp_config.h"
#include "dcl.h"
#include "drv_comm.h"
#include "tst_lmu_hw.h"

/******************************************************************************
 * external APIs that will be used in this file.
 *****************************************************************************/
extern void TCT_Schedule( void );
extern void TCCT_Schedule( void );
extern kal_int32 vsnprintf( kal_char *str, kal_uint32 size, const kal_char *fmt,
                            va_list ap );
extern kal_bool idle_create( comptask_handler_struct ** );

/******************************************************************************
 * permanent storage address to store the test case label.
 * Note:
 *     only the address on MT6268 is available.
 *     the address on MT6253 has not been checked since 2011/09/27.
 *     the address on MT6276 has been checked, and it is unavailable now.
 *****************************************************************************/
#ifdef MT6268
#define KTEST_EVER_STORAGE_ADDR	0x501176B0
#endif

#ifdef  MT6253
#define KTEST_EVER_STORAGE_ADDR	0x4001BFF0
#endif

#ifdef MT6276
//#define KTEST_EVER_STORAGE_ADDR 0xC8008000
#define KTEST_EVER_STORAGE_ADDR 0x018DAFE0
#endif

/******************************************************************************
 * Name:
 *     ktest_init_tc_label
 * Functionality:
 *     initialize the test case label.
 * Parameter:
 *     void.
 * Returns:
 *     if we can not read the label, return KAL_FALSE.
 *     else if the label is valid, return KAL_TRUE.
 *          else, return the result of ktest_write_tc_label.
 * Note:
 *     the test case label is valid only when the head is "KTESTz" and the tail
 *     is "jmf", so we check them when KTEST in initialization. If the label is
 *     not valid, then we will overwrite it with correct value.
 *****************************************************************************/
kal_bool ktest_init_tc_label( void )
{
    ktest_tc_label tc;

    /* firstly, we must read the test case label in permanent storage */
    if( !ktest_read_tc_label( &tc ) )
        return KAL_FALSE;

    /* if the label is not valid, overwrite it with correct value */
    if( ktest_strncmp( tc.magic, KTEST_TC_LABEL_MAGIC, KTEST_TC_MAGIC_LEN ) != 0
        || ktest_strncmp( tc.tail, KTEST_TC_LABEL_TAIL, KTEST_TC_TAIL_LEN ) != 0 )
    {
        ktest_strncpy( tc.magic, KTEST_TC_LABEL_MAGIC, KTEST_TC_MAGIC_LEN );
        tc.stage = TC_PRE_SCHEDULE;
        tc.module = 0;
        tc.index = -1;  /* should start from -1, so next_tc will add it to zero. */
        ktest_strncpy( tc.tail, KTEST_TC_LABEL_TAIL, KTEST_TC_TAIL_LEN );
        return ktest_write_tc_label( &tc );
    }

    /* if the label is valid, return KAL_TRUE */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_read_tc_label
 * Functionality:
 *     read test case label from permanent storage.
 * Parameters:
 *     tc_id: to store the value of test case label.
 * Returns:
 *     it always returns KAL_TRUE.
 * Note:
 *     as expected, this function will return KAL_FALSE when it fails to read
 *     test case label from permanent storage, but we have not implemented it.
 *****************************************************************************/
kal_bool ktest_read_tc_label( ktest_tc_label *tc_id )
{
    kal_char *inter_ram = (kal_char *) KTEST_EVER_STORAGE_ADDR;

    ktest_strncpy( tc_id->magic, inter_ram, KTEST_TC_MAGIC_LEN );
    inter_ram += KTEST_TC_MAGIC_LEN;
    tc_id->stage = *(inter_ram++);
    tc_id->module = *(inter_ram++);
    tc_id->index = *(inter_ram++);
    ktest_strncpy( tc_id->tail, inter_ram, KTEST_TC_TAIL_LEN );

    /* read test case label successfully */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_write_tc_label
 * Functionality:
 *     write the test case label to permanent storage.
 * Parameters:
 *     tc_id: pointer to the new value of test case label.
 * Returns:
 *     it always returns KAL_TRUE.
 * Note:
 *     as expected, this function will return KAL_FALSE when it fails to write
 *     the new value to permanent storage, but we have not implemented it yet.
 *****************************************************************************/
kal_bool ktest_write_tc_label( const ktest_tc_label *tc_id )
{
    kal_char *inter_ram = (kal_char *) KTEST_EVER_STORAGE_ADDR;

    /* write the new value of test case label to permanent storage */
    ktest_strncpy( inter_ram, tc_id->magic, KTEST_TC_MAGIC_LEN );
    inter_ram += KTEST_TC_MAGIC_LEN;
    *(inter_ram++) = tc_id->stage;
    *(inter_ram++) = tc_id->module;
    *(inter_ram++) = tc_id->index;
    ktest_strncpy( (kal_char *) inter_ram, tc_id->tail, KTEST_TC_TAIL_LEN );

    /* write successfully */
    return KAL_TRUE;
}

/******************************************************************************
 * handle of GPT timer.
 *****************************************************************************/
static DCL_HANDLE gpt_module;

/******************************************************************************
 * Name:
 *     ktest_GPTI_GetHandle
 * Functionality:
 *     get a handle of GPT timer.
 * Parameters:
 *     void.
 * Returns:
 *     a handle of GPT timer.
 *****************************************************************************/
static DCL_HANDLE ktest_GPTI_GetHandle( void )
{
    DCL_HANDLE gpt_handle;
	gpt_handle = DclSGPT_Open( DCL_GPT_CB, 0 );

    return gpt_handle;
}

/******************************************************************************
 * Name:
 *     ktest_GPTI_StartItem
 * Functionality:
 *     start a GPT timer.
 * Parameters:
 *     gpt_handle: the handle of GPT timer.
 *     tick: after how many ticks it will expire.
 *     gptimer_func: callback function of GPT timer.
 *     parameter: the parameter for gptimer_func.
 * Returns:
 *     if start successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_GPTI_StartItem( DCL_HANDLE gpt_handle, kal_uint16 tick,
                                      void (*gptimer_func)( void * ),
                                      void *parameter )
{
    DCL_STATUS status;
 	SGPT_CTRL_START_T start;
	start.u2Tick = tick;
	start.pfCallback = gptimer_func;
	start.vPara = parameter;
    status = DclSGPT_Control( gpt_handle, SGPT_CMD_START,
                              (DCL_CTRL_DATA_T*) &start );

    /* if start successfully, return KAL_TRUE. else return KAL_FALSE. */
	return ( STATUS_OK == status ) ? KAL_TRUE : KAL_FALSE;
}

/******************************************************************************
 * Name:
 *     ktest_GPTI_StopItem
 * Functionality:
 *     stop a GPT timer.
 * Parameters:
 *     gpt_handle: the handle of GPT timer that you want to stop.
 * Returns:
 *     void.
 *****************************************************************************/
static void ktest_GPTI_StopItem( DCL_HANDLE gpt_handle )
{
 	DclSGPT_Control( gpt_handle, SGPT_CMD_STOP, 0 );
}

/******************************************************************************
 * Name:
 *     ktest_GPTI_ReleaseHandle
 * Functionality:
 *     release a handle of GPT timer.
 * Parameters:
 *     gpt_handle_ptr: pointer to the handle of a GPT timer.
 * Returns:
 *     if close handle successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
kal_bool ktest_GPTI_ReleaseHandle( DCL_HANDLE *gpt_handle_ptr )
{
    DCL_STATUS status;
    status = DclSGPT_Close( gpt_handle_ptr );

    /* if close successfully, return KAL_TRUE. else return KAL_FALSE. */
    return ( STATUS_OK == status ) ? KAL_TRUE : KAL_FALSE;
}

/******************************************************************************
 * Name:
 *     ktest_stop_gpt_timer
 * Functionality:
 *     stop the GPT timer and release the handle of it.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_stop_gpt_timer( void )
{
    ktest_GPTI_StopItem( gpt_module );
    ktest_GPTI_ReleaseHandle( &gpt_module );
}

/******************************************************************************
 * Name:
 *     gpt_callback
 * Functionality:
 *     callback function of a GPT timer.
 * Parameters:
 *     data: not used here.
 * Returns:
 *     void.
 *****************************************************************************/
static void gpt_callback( void *data )
{
    ktest_report( KTEST_FAIL, KTEST_TCID, "GPT alarm timeout" );
    ktest_stop_gpt_timer();
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     ktest_start_gpt_timer
 * Functionality:
 *     get the handle of a GPT timer and start the timer.
 * Parameters:
 *     time_count: time to expire ( in unit of 10ms ).
 *     gptimer_func: callback function of GPT timer.
 *                   if it is null, default callback function will be called.
 *     cb_data: parameters transferred to gptimer_func.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_start_gpt_timer( kal_uint32 time_count, void (*gptimer_func)(void *),
                            void *cb_data )
{
    kal_uint8 data;
    gpt_module = ktest_GPTI_GetHandle();
    if( NULL == gptimer_func )
    {
        /* if gptimer_func is null, default callback function will be called */
        ktest_GPTI_StartItem( gpt_module, time_count, gpt_callback, &data );
    }
    else
    {
        /* if gptimer_func is valid, call it when timer expires. */
        ktest_GPTI_StartItem( gpt_module, time_count, gptimer_func, cb_data );
    }
}

/******************************************************************************
 * Name:
 *     ktest_UART_SetDCBConfig
 * Functionality:
 *     config a UART port.
 * Parameters:
 *     port: the UART port you want to use.
 *     UART_Config: a pointer to the config information of a UART port.
 *     ownerid: id of the UART port's owner.
 * Returns:
 *     void.
 *****************************************************************************/
static void ktest_UART_SetDCBConfig( UART_PORT port, UARTDCBStruct *UART_Config,
                                     module_type ownerid )
{

	DCL_HANDLE handle;
	UART_CTRL_DCB_T data;

    /* config the UART */
	data.u4OwenrId = ownerid;
	data.rUARTConfig.u4Baud = UART_Config->baud;
	data.rUARTConfig.u1DataBits = UART_Config->dataBits;
	data.rUARTConfig.u1StopBits = UART_Config->stopBits;
	data.rUARTConfig.u1Parity = UART_Config->parity;
	data.rUARTConfig.u1FlowControl = UART_Config->flowControl;
	data.rUARTConfig.ucXonChar = UART_Config->xonChar;
	data.rUARTConfig.ucXoffChar = UART_Config->xoffChar;
	data.rUARTConfig.fgDSRCheck = UART_Config->DSRCheck;

    /* open the UART port, then setup the config information. */
	handle = DclSerialPort_Open( port, 0 );
	DclSerialPort_Control( handle, SIO_CMD_SET_DCB_CONFIG,
                           (DCL_CTRL_DATA_T*) &data );
}

/******************************************************************************
 * Name:
 *     ktest_UART_Bootup_Init
 * Functionality:
 *     bootup initialization of a UART port.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
static void ktest_UART_Bootup_Init( void )
{
    DCL_HANDLE handle;
    handle = DclSerialPort_Open( uart_port1, 0 );
    DclSerialPort_Control( handle, UART_CMD_BOOTUP_INIT, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_UART_Boot_PutUARTBytes
 * Functionality:
 *     output data through UART port.
 * Parameters:
 *     port: the UART port you want to use.
 *     data: the data you want to output.
 *     len:  the length of data you want to output.
 * Returns:
 *     void.
 *****************************************************************************/
static void ktest_UART_Boot_PutUARTBytes( UART_PORT port, kal_uint8 *data,
                                          kal_uint16 len )
{
    DCL_HANDLE handle;
    UART_CTRL_BOOT_PUTBYTES_T data1;
    data1.puBuffaddr = data;
    data1.u2Length = len;
    handle = DclSerialPort_Open( port, 0 );
    DclSerialPort_Control( handle, UART_CMD_BOOT_PUTBYTES,
                           (DCL_CTRL_DATA_T *) &data1 );
}

/******************************************************************************
 * Name:
 *     ktest_UART_GetOwnerID
 * Functionality:
 *     get the id of UART port's owner.
 * Parameters:
 *     port: the UART port that you want to query.
 * Returns:
 *     id of the owner.
 *****************************************************************************/
static module_type ktest_UART_GetOwnerID( UART_PORT port )
{

	DCL_HANDLE handle;
	UART_CTRL_OWNER_T data;

	handle = DclSerialPort_Open( port, 0 );
	DclSerialPort_Control( handle, SIO_CMD_GET_OWNER_ID,
                           (DCL_CTRL_DATA_T*) &data );
	return data.u4OwenrId;
}

/******************************************************************************
 * Name:
 *     ktest_init_uart_port
 * Functionality:
 *     initialize a UART port.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_init_uart_port( void )
{
    module_type ownerid;

    UARTDCBStruct dcb =
    {
        UART_BAUD_115200,	/*baud*/
        len_8,			/*dataBits*/
        sb_1,			/*stopBits*/
        pa_none,		/*parity*/
        fc_none, 			/*no flow control*/
        0x11,			/*xonChar*/
        0x13,			/*xoffChar*/
        KAL_FALSE
    };

    ktest_UART_Bootup_Init();
    ownerid = ktest_UART_GetOwnerID( uart_port1 );
    ktest_UART_SetDCBConfig( uart_port1, &dcb, ownerid );
}

/******************************************************************************
 * Name:
 *     internal_print
 * Functionality:
 *     output some messages to UART port.
 * Parameters:
 *     fmt: a formatted string.
 *     ap:  variable argument list.
 * Returns:
 *     it always return 0.
 * Note:
 *     I think we should use different return values to indicate different
 *     situations, eg. 0 means send successfully, -1 means error.
 *****************************************************************************/
kal_uint32 internal_print( kal_char *fmt, va_list ap )
{

    kal_int32 rc;
    kal_char buf[1024];

    rc = vsnprintf( buf, sizeof (buf), fmt, ap );
    if( rc < sizeof(buf) )
    {
        ktest_UART_Boot_PutUARTBytes( uart_port1, (kal_uint8 *) buf, rc );
    }
    else
    {
        /* we should add overflow handler here. */
    }

    return 0;
}

/******************************************************************************
 * Name:
 *     ktest_flush
 * Functionality:
 *     flush test result to log file.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_flush( void )
{
    return;
}

/******************************************************************************
 * Name:
 *     ktest_report
 * Functionality:
 *     report test result to log file through UART port.
 * Parameters:
 *     res: a value of KTEST_PASS, KTEST_FAIL or KTEST_DEP_FAIL.
 *     tc_name: function name of a test case.
 *     fmt: description of the test case, it supports variable argument list.
 *     ...: the real arguments used in fmt.
 * Returns:
 *     if successful, return KAL_TRUE.
 *     else, return KAL_FALSE.
 * Note:
 *     1. the buffer size after fmt should not exceed 1KB.
 *     2. is it possible that return the number of characters outputed instead
 *        of KAL_TURE ?
 *****************************************************************************/
kal_uint32 ktest_report( ktest_res res, const kal_char* tc_name,
                         kal_char *fmt, ...)
{

    UART_PORT ktest_tx_port = uart_port1;
    kal_uint32 len;
    va_list ap;

    /* check if tc_name is valid. */
    len = strlen( tc_name );
    if( len == 0 )
    {
        return 0;
    }

    /* output the name of test case. */
    ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "^^", 2 );
    ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) tc_name, len );
    ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "::", 2 );

    /* output the result of test case. */
    if ( KTEST_PASS == res )
    {
        ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "Pass", 4 );
    }
    else if(KTEST_FAIL == res)
    {
        ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "Fail", 4 );
    }
    else if(KTEST_DEP_FAIL == res)
    {
        ktest_UART_Boot_PutUARTBytes( ktest_tx_port,
                                      (kal_uint8 *) "Dep Fail", 8 );
    }else {
        return KAL_FALSE;
    }

    /* output the brief part of test case. */
    if( NULL != KTEST_BRIEF )
    {

        ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "::", 2 );
        len = ktest_strlen( KTEST_BRIEF );
        ktest_UART_Boot_PutUARTBytes( ktest_tx_port,
                                      (kal_uint8 *) KTEST_BRIEF, len );
    }

    /* output the description of test case. */
    if( NULL != fmt )
    {
        ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "::", 2 );
        va_start( ap, fmt );
        internal_print( fmt, ap );
        va_end( ap );
    }

    /* output the tail of a test case result. */
    ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "&&", 2 );
    ktest_UART_Boot_PutUARTBytes( ktest_tx_port, (kal_uint8 *) "\r\n", 2 );

    /* we have output a test result successfully */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_reset_target
 * Functionality:
 *     reset the target.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_reset_target( void )
{
    DCL_HANDLE dcl_wdt_handle;

    dcl_wdt_handle = DclWDT_Open( DCL_WDT, 0 );
	DclWDT_Control( dcl_wdt_handle, WDT_CMD_DRV_RESET, 0 );
}

/******************************************************************************
 * Name:
 *     ktest_schedule
 * Functionality:
 *     call this API in pre-scheduling stage can run the task already created.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 * Notes:
 *     the interrupt is not open.
 *****************************************************************************/
void ktest_schedule( void )
{
#if defined( __NUCLEUS_VERSION_2__ )
    TCCT_Schedule();
#else
    TCT_Schedule();
#endif
}

/******************************************************************************
 * Name:
 *     ktest_sw_intr_handler
 * Functionality:
 *     register interrupt handler.
 * Parameters:
 *     reg_lisr: the interrupt handler.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_sw_intr_handler( void (*reg_lisr)( void ) )
{
    IRQ_Register_LISR( IRQ_SW_LISR1_CODE, reg_lisr, "20" );
    IRQUnmask( IRQ_SW_LISR1_CODE );
}

/******************************************************************************
 * Name:
 *     ktest_active_sw_handler
 * Functionality:
 *     activate a lisr.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_active_sw_handler( void )
{
    Activate_LISR( SW_TRIGGER_CODE1 );
}

/******************************************************************************
 * Name:
 *     ktest_deactive_sw_handler
 * Functionality:
 *     de-activate a lisr.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_deactive_sw_handler( void )
{
    Deactivate_LISR( SW_TRIGGER_CODE1 );
}

/******************************************************************************
 * Name:
 *     ktest_mask_interrupt
 * Functionality:
 *     mask interrupts except OS timer and GPT timer.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 * Note:
 *     only OS timer and GPT timer interrupt can come.
 *****************************************************************************/
static void ktest_mask_interrupt( void )
{
    IRQ_MASK_VALUE_T mask_val;

    /* mask all interrupts except OS timer and GPT timer interrupts.*/
    CTIRQ1_2_MaskAll( &mask_val );

    IRQUnmask( IRQ_GPT_CODE );
#if defined( __EVENT_BASED_TIMER__ )
    IRQUnmask( IRQ_OSTIMER_ARM_CODE );
#endif
}

/******************************************************************************
 * Name:
 *     ktest_get_sys_tick
 * Functionality:
 *     get the system ticks now.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
kal_uint32 ktest_get_sys_tick( void )
{
    kal_uint32 i;
#if defined( KAL_ON_NUCLEUS )
    kal_get_time( &i );
    return i;
#elif
    return 0;
#endif
}

/******************************************************************************
 * Name:
 *     ktest_set_sys_tick
 * Functionality:
 *     set the system ticks now.
 * Parameters:
 *     new_tick: the new value of system ticks.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_set_sys_tick( kal_uint32 new_tick )
{
#if defined( KAL_ON_NUCLEUS )
    NU_Set_Clock( new_tick );
    return;
#elif
    return;
#endif
}

/******************************************************************************
 * Name:
 *     ktest_init_env
 * Functionality:
 *     initialize the environment of KTEST framework.
 * Parameters:
 *     void.
 * Returns:
 *     it always return 0.
 * Notes:
 *     we should add different return values in different situations, eg. if we
 *     encounter an error, the KTEST framework should not continue to run, so
 *     we'd better use a different return value to indicate this case.
 *****************************************************************************/
kal_uint32 ktest_init_env( void )
{
    /* there is no MMPWRMGR_SYSRAM symbol in MT6253 */
#if defined( __MAUI_BASIC__ ) && defined( MT6268 )
    /* On Maui basic load, internal ram need power on */
    mm_enable_power( MMPWRMGR_SYSRAM );
#endif

    /* initialize the UART port */
    ktest_init_uart_port();

#ifdef __TST_LMU_LOGGING__
    LMU_Config_Enable(1);
    LMU_Config_Flush_Enable(1);
#endif

    /* add an idle task. */
    task_info_g[INDX_IDLE].task_entry_func = idle_create;

    /* should this be on oscar ? */
    ktest_mask_interrupt();

    /* initialization ends successfully */
    return 0;
}

#endif      /*__KTEST__*/
