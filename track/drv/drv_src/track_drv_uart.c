/******************************************************************************
 * track_drv_uart.c - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        UART控制接口 
 * 
 * modification history
 * --------------------
 * v1.0   2017-07-13,  chengjun create this file
 * 
 ******************************************************************************/
 
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_timer.h"
#include "track_at.h"
#include "track_drv_uart.h"
#include "Track_drv_eint_gpio.h"

#include "gpio_hw.h"
#include "dcl_gpio.h"
#include "track_os_ell.h"
#include "track_cust.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/


#if defined __GPS_MT3333__
#define GPS_COMM_OWNER_ID           MOD_GPS
#else
#define GPS_COMM_OWNER_ID           MOD_MMI
#endif

#if defined( __BD_AT6558__)
#define GPS_POWER_GPIO              3
#else
#define GPS_POWER_GPIO              18
#endif /* __BD_AT6558__ */

#if defined( __GPS_G3333__)
#define GPS_UART_BAUD               UART_BAUD_115200
#else
#define GPS_UART_BAUD               UART_BAUD_9600
#endif /* __GPS_G3333__ */

#define AT_COMM_OWNER_ID            MOD_ATCI
#define OBD_COMM_OWNER_ID           MOD_MMI

#define GPS_REVICE_BUFF_SIZE        1600
#define GPS_REVICE_BUFF_LIMIT       GPS_REVICE_BUFF_SIZE - 31

#define SERAIL_CACHE_BUF_SIZE          5120
#define SERAIL_BACK_BUF_SIZE          2048
#define GPS_SINGLE_ITME_MAX_SIZE    200
#define GPS_DECODE_BUF_SIZE         (GPS_REVICE_BUFF_SIZE + GPS_SINGLE_ITME_MAX_SIZE * 2)

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static kal_uint8 uart_buf[GPS_DECODE_BUF_SIZE] = {0};
static kal_uint8 uart_log_mode = 0;  /*0: 初始值，待转OBD专用; 1: 已经转为OBD专用;  2: 禁止转为OBD专用*/

kal_uint8 seridata[2];
kal_uint8 serverapp = 0;

track_soc_Callback_struct cb = {0};

static kal_uint8 bmsUart = 0;//0-未初始化BMS通讯口，1 已经初始化为BSM通讯口
/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern kal_bool track_is_recv_cmd_after_boot(kal_uint8 par);
extern void track_cust_controller_data_init();

static void UART_ClrRxBuffer(UART_PORT port, module_type ownerid);
static void UART_ClrTxBuffer(UART_PORT port, module_type ownerid);
#if defined(__BMS_PHYLION__)
extern void track_cust_bms_command(void);
#endif


static DCL_HANDLE tr_at_get_handle(void)
{
    static DCL_HANDLE handle = -1;

    if(handle == -1)
    {
        handle = DclSerialPort_Open(track_get_at_port(), 0);  //MagicNing  最好在这里检查一下UART的所有者是不是ATCI
    }
    return handle;
}

void track_uart_close(DCL_DEV port, module_type owerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLOSE_T data;
    UART_CTRL_POWERON_T data2;
    DCL_STATUS dcl_ret1 = 0, dcl_ret = 0;

    UART_ClrRxBuffer(port, owerid);
    UART_ClrTxBuffer(port, owerid);

    data.u4OwenrId = owerid;
    handle = DclSerialPort_Open(port, 0);
    dcl_ret1 = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);

    data2.bFlag_Poweron = DCL_FALSE;
    handle = DclSerialPort_Open(port, 0);
    dcl_ret = DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);
    LOGD(L_DRV, L_V2, "track_uart_close ret:%d,%d", dcl_ret1, dcl_ret);
}

static DCL_UINT16 UART_CheckTxAllSentOut(DCL_DEV port)
{
    DCL_HANDLE handle;
    UART_CTRL_CHECK_TSO_T data;

    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, UART_CMD_CHECK_TX_SEND_OUT, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    return data.bFlag;
}

static void UART_ClrRxBuffer(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
}

static void UART_ClrTxBuffer(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_CLR_BUFFER_T data;
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);
}
DCL_UINT16 UART_GetBytesAvail(DCL_DEV port)
{
    DCL_HANDLE handle;
    UART_CTRL_RX_AVAIL_T data;

    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_RX_AVAIL, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    return data.u2RetSize;
}

kal_uint16 UART_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data;
//UART_CTRL_PUT_UART_BYTE_T data;
    DCL_STATUS ret;

    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    handle = DclSerialPort_Open(port, 0);
    ret = DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}

static kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_GET_BYTES_T data;
    data.u4OwenrId = ownerid;
    data.u2Length = Length;
    data.puBuffaddr = Buffaddr;
    data.pustatus = status;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
    return data.u2RetSize;
}

static void UART_TurnOnPower(UART_PORT port, kal_bool on)
{
    DCL_HANDLE handle;
    UART_CTRL_POWERON_T data;

    handle = DclSerialPort_Open(port, 0);
    data.bFlag_Poweron = on;
    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
}

static void UART_SetDCBConfig(DCL_DEV port, UART_CONFIG_T *UART_Config, DCL_UINT32 ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_DCB_T data;
    DCL_STATUS dcl_ret = 0;

    data.u4OwenrId = ownerid;
    data.rUARTConfig.u4Baud = UART_Config->u4Baud;
    data.rUARTConfig.u1DataBits = UART_Config->u1DataBits;
    data.rUARTConfig.u1StopBits = UART_Config->u1StopBits;
    data.rUARTConfig.u1Parity = UART_Config->u1Parity;
    data.rUARTConfig.u1FlowControl = UART_Config->u1FlowControl;
    data.rUARTConfig.ucXonChar = UART_Config->ucXonChar;
    data.rUARTConfig.ucXoffChar = UART_Config->ucXoffChar;
    data.rUARTConfig.fgDSRCheck = UART_Config->fgDSRCheck;
    handle = DclSerialPort_Open(port, 0);
    dcl_ret = DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
    DclSerialPort_Close(handle);
    LOGD(L_DRV, L_V5, "ret:%d;ownerid =%d;u4OwenrId=%d;u4Baud =%d;u4Baud=%d", dcl_ret, ownerid, data.u4OwenrId, data.rUARTConfig.u4Baud, UART_Config->u4Baud);
}
static void UART_ReadDCBConfig(DCL_DEV port)
{
    DCL_HANDLE handle;
    UART_CTRL_DCB_T data;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_READ_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
    LOGD(L_DRV, L_V7, "id=%d;u4Baud=%d", data.u4OwenrId, data.rUARTConfig.u4Baud);
    DclSerialPort_Close(handle);
}

//STATUS_OK = 0
static DCL_INT32 UART_Open(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;
    DCL_INT32  status;

    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    status = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
    LOGD(L_DRV, L_V5, "port:%d,handle:%d,Status=%d", port, handle, status);

    return status;
}

 module_type UART_GetOwnerID(UART_PORT port)
{
    DCL_HANDLE handle;
    UART_CTRL_OWNER_T data;
    DCL_STATUS ret;
    handle = DclSerialPort_Open(port, 0);
    ret = DclSerialPort_Control(handle, SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&data);
    return (module_type)(data.u4OwenrId);
}

static void UART_SetOwner(UART_PORT port, module_type ownerid)
{
    DCL_HANDLE handle;
    UART_CTRL_OWNER_T data;
    data.u4OwenrId = ownerid;
    handle = DclSerialPort_Open(port, 0);
    DclSerialPort_Control(handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&data);

}

kal_uint16 USB_PutBytes(kal_uint8 * out_context, kal_uint16 length)
{
    return UART_PutBytes(4, out_context, length, UART_GetOwnerID(4));
}

static void track_drv_gps_enable(kal_uint8 flag)
{
    if(1 == flag)
    {
#if !defined( __BD_AT6558__)
        GPIO_ModeSetup(GPS_POWER_GPIO, 0);
        GPIO_InitIO(1, GPS_POWER_GPIO);
        GPIO_WriteIO(1, GPS_POWER_GPIO);
#endif /* __BD_AT6558__ */

        track_drv_Set_VMC(KAL_TRUE, 3);
    }
    else
    {
#if !defined( __BD_AT6558__)
        GPIO_WriteIO(0, GPS_POWER_GPIO);
#endif /* __BD_AT6558__ */
        track_drv_Set_VMC(KAL_FALSE, 0);
    }
}

static kal_uint8 drv_gps_status = 0;
void track_set_drv_gps_status(U8 op)
{
    drv_gps_status = op;
}
void track_cust_modeule_into_sleep_mode(void)
{
    track_drv_sleep_enable(SLEEP_OBD_MOD, KAL_TRUE);
}

void track_drv_write_exmode(kal_uint8 *data, int len)
{
    module_type IR_Owner_save = UART_GetOwnerID(EXT_UART_PORT);
    if(len < 2000)
    {
        LOGH(L_MCU, L_V5, data, len);
        //LOGD(L_DRV, L_V5, "UART>>%s", (char*)data);
    }
    else if(len >= 2000)
    {
        LOGH(L_MCU, L_V6, data, len);
    }

    track_drv_sleep_enable(SLEEP_OBD_MOD, KAL_FALSE);

    tr_start_timer(TRACK_CUST_EXTCHIP_SLEEP_TIMER_ID, 2000, track_cust_modeule_into_sleep_mode);
        
    UART_PutBytes(EXT_UART_PORT, data, len, IR_Owner_save);
}

/******************************************************************************
 *  Function    -  track_drv_mgps_uart_init
 *
 *  Purpose     -  外挂GPS芯片的方案，初始化串口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_drv_mgps_uart_init(void)
{
    kal_uint8 ret;
    static kal_uint32 index = 0;

    tr_stop_timer(GPS_UART2_RESET_INIT_TIME_ID);

    ret = track_drv_uart_config(GPS_UART_PORT, MOD_MMI, GPS_UART_BAUD);

    LOGD(L_DRV, L_V5, "index:%d,port=%d,ret=%d,返回值(==0)时1秒后重新初始化", index, GPS_UART_PORT, ret);
    if(ret == 0)
    {
        if(index < 5)
        {
            tr_start_timer(GPS_UART2_RESET_INIT_TIME_ID, 1000, track_drv_mgps_uart_init);
            index++;
            return;
        }
        else
        {
            ASSERT(0);
        }
    }
    index = 0;

    LOGD(L_APP, L_V5, "GPS供电开启");

    track_drv_gps_enable(1);
    //track_drv_led_vcama(1);
}


static void track_drv_uart3_init(void)
{
    kal_uint8 ret;
    static kal_uint32 index = 0;

    tr_stop_timer(GPS_UART1_RESET_INIT_TIME_ID);

    ret = track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_9600);
    LOGD(L_DRV, L_V5, "index:%d,port=%d,ret=%d,返回值(==0)时1秒后重新初始化", index, uart_port3, ret);
    if(ret == 0)
    {
        if(index < 5)
        {
            tr_start_timer(GPS_UART1_RESET_INIT_TIME_ID, 1000, track_drv_uart3_init);
            index++;
            return;
        }
    }
    index = 0;
}
void track_drv_uart_init_public(module_type Owner_set, DCL_DEV port, UART_BAUDRATE_T u4Baud)
{
    DCL_STATUS dcl_ret1 = 0, dcl_ret2 = 0, dcl_ret3 = 0, dcl_ret4 = 0;
    UART_CONFIG_T Dcb;
    module_type Owner1, Owner2;
	kal_uint8 uart3_handle = 0xff;

	uart3_handle = L1SM_GetHandle();

	L1SM_SleepDisable(uart3_handle);
/*    switch(port)
    {
        case uart_port1:
            UART_PORT1_RX;
            UART_PORT1_TX;
            break;

        case uart_port2:
            UART_PORT2_RX;
            UART_PORT2_TX;
            break;

        case uart_port3:
            UART_PORT3_RX;
            UART_PORT3_TX;
            break;

        default:
            // ERROR
            return;
    }*/ 
    if(uart_port3 == port)
    {
        GPIO_ModeSetup(0, 3);
        GPIO_ModeSetup(1, 3);
    }
	UART_TurnOnPower(uart_port3, KAL_TRUE);;
    //kal_sleep_task(44); /* 如果上面的GPIO不是默认处于串口模式，可能在开启GPIO之后需要延时 */
    Owner1 = UART_GetOwnerID(port);
	UART_Open(uart_port3, Owner1);
    if(Owner_set != Owner1)
    {
        DCL_HANDLE handle;
        UART_CTRL_CLOSE_T data;
        UART_CTRL_POWERON_T data2;
        UART_CTRL_OPEN_T data3;

        //UART_ClrBuffer(port, Owner1);  /* 似乎没有什么明显的作用 */
        handle = DclSerialPort_Open(port, 0);

        data.u4OwenrId = Owner1;
        dcl_ret1 = DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);

        data2.bFlag_Poweron = DCL_FALSE;
        dcl_ret2 = DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);
        //kal_sleep_task(10);

        data2.bFlag_Poweron = DCL_TRUE;
        dcl_ret3 = DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);

        data3.u4OwenrId = Owner_set;
        dcl_ret4 = DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data3);

        DclSerialPort_Close(handle);
    }
	UART_Open(uart_port3, Owner_set);
    Dcb.u4Baud = u4Baud;
    Dcb.u1DataBits = len_8;
    Dcb.u1StopBits = sb_1;          /*dataBits*/
    Dcb.u1Parity = pa_none;         /*stopBits*/
    Dcb.u1FlowControl = fc_none;    /*parity*/
    Dcb.ucXonChar = 0x11;           /*no flow control*/
    Dcb.ucXoffChar = 0x13;          /*xonChar*/
    Dcb.fgDSRCheck = KAL_FALSE;     /*xoffChar*/
    UART_SetDCBConfig(port, &Dcb, Owner_set);
    Owner2 = UART_GetOwnerID(port);
    LOGD(L_DRV, L_V5, "Owner:%d/%d/%d, dcl_ret:%d/%d/%d/%d", Owner1, Owner2, Owner_set, dcl_ret1, dcl_ret2, dcl_ret3, dcl_ret4);
}

#if defined(__OBD__)
/******************************************************************************
 *  Function    -  track_drv_obd_power_init
 *
 *  Purpose     -  外接OBD，初始化串口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-09-14,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_obd_power_init(void)
{
/*	GPIO_ModeSetup(OBD_POWER_GPIO, 0);
	GPIO_InitIO(1, OBD_POWER_GPIO);
	GPIO_WriteIO(1, OBD_POWER_GPIO);
	*/
	
    track_cust_obd_opendata();
	LOGD(L_DRV, L_V5, "打开OBD供电口",G_parameter.obd.sw);
}
#endif /* __OBD__ */
static void track_drv_reset_gps_cb(void)
{
    track_drv_mgps_on();
}

static void track_drv_reset_gps(void)
{
    LOGD(L_DRV, L_V5, "");

    tr_stop_timer(GPS_UART2_RESET_INIT_TIME_ID);
    track_drv_mgps_off();
    tr_start_timer(GPS_DATA_UPDATA_TIMER_ID, 1000, track_drv_reset_gps_cb);
}


void track_drv_mgps_off(void)
{
    module_type IR_Owner_save;
    LOGD(L_DRV, L_V5, "",);

    //GPIO_WriteIO(0, GPS_POWER_GPIO);
    // track_drv_Set_VMC(KAL_FALSE, 0);
    track_drv_gps_enable(0);
#if defined( __BD_AT6558__)
    track_drv_led_vcama(KAL_FALSE);
#endif /* __BD_AT6558__ */
    IR_Owner_save = UART_GetOwnerID(GPS_UART_PORT);
    LOGD(L_APP, L_V5, "关闭GPS IR_Owner_save=%d", IR_Owner_save);
    track_uart_close(GPS_UART_PORT, IR_Owner_save);
    drv_gps_status = 0;
    tr_stop_timer(GPS_DATA_UPDATA_TIMER_ID);

#if defined( __BD_AT6558__)
    GPIO_ModeSetup(U_TX, 0);
    GPIO_ModeSetup(U_RX, 0);
#endif /* __BD_AT6558__ */

}

void track_drv_mgps_on(void)
{
    LOGD(L_DRV, L_V5, "");

    drv_gps_status = 1;

    tr_start_timer(GPS_DATA_UPDATA_TIMER_ID, 10000, track_drv_reset_gps);/*TEMPEEEEEWANGQI*/

#if defined( __GPS_G3333__)||defined( __BD_AT6558__)
    OTA_track_GPIO_SetClkOut(1, 0x82/*mode_f32k_ck*/);//输出32K CLK
#endif
#if defined( __BD_AT6558__)
    //track_drv_led_vcama(KAL_TRUE);
    track_drv_set_vcama(KAL_TRUE, 2800000);

#endif /* __BD_AT6558__ */
    track_drv_mgps_uart_init();

}


kal_uint8 track_drv_uart_log_mode(kal_uint8 par)
{
    if(par != 99)
    {
        uart_log_mode = par;
    }
    return uart_log_mode;
}


/******************************************************************************
 *  Function    -  track_drv_uart1_mode
 *  Purpose     -  串口1工作模式
 *  Description -
 *                 请使用0XFF进行状态查询
 *  Return      -  1   SOS模式
 *                 0   串口模式
                    0xff 为默认模式
 * modification history
 * ----------------------------------------
 * v1.0  , 20141230  WangQi  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_uart1_mode(kal_uint8 mode)
{
    static kal_uint8 u_m = 0xff;
	if(mode != 0xff)
	{
		u_m = mode;
	}
    return u_m;
}
#if defined(__BMS_PHYLION__)
kal_uint8 get_BmsUart(void)
{
	return bmsUart;
}

void track_cust_bms_uart_init()
{
	extern kal_bool track_log_change(int module, int grade, int target);
	//track_log_change(0,-1,-1);
	extern kal_bool track_os_log5_status(void);
	static port_setting_struct port_setting = {0};
#if defined(__NETWORK_LICENSE__)
	return;
#endif
	if(G_parameter.BMSOC == 1)
	{
		LOGD(L_APP, L_V1, "谁把BMS的开关关了:%d",G_parameter.BMSOC);
		return;
	}
    Track_nvram_read(NVRAM_EF_PORT_SETTING_LID, 1, (void *)&port_setting, NVRAM_EF_PORT_SETTING_SIZE);
	LOGD(L_APP, L_V5, "竟然能进来初始化");
	if(track_is_testmode() || (track_os_log5_status() && port_setting.ps_port != 4) || is_catcher_mode() == 2)
	{
		return;//我测试的时候直接初始化，必须用usb
	}
	if(port_setting.ps_port != 4)
	{
		track_log_change(0,-1,-1);
	}
	bmsUart = 1;
	track_drv_uart1_mode(1);
	track_drv_sleep_enable(SLEEP_OBD_MOD, FALSE);
	track_drv_uart_config(uart_port1, MOD_MMI, UART_BAUD_9600);
	track_cust_bms_command();
}
void track_drv_bms_uart_test()
{
	//if(track_is_testmode())
	{
		track_drv_uart_config(uart_port1, MOD_MMI, UART_BAUD_115200);
	}
}
#endif
/******************************************************************************
 *  Function    -  track_drv_uart_init
 *
 *  Purpose     -  UART初始化
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-08-30,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_uart_init(void)
{
    LOGD(L_DRV, L_V5, "");

#if defined( __GPS_G3333__)
    OTA_track_GPIO_SetClkOut(1, 0x82/*mode_f32k_ck*/);//输出32K
#endif

#if defined(__TEST_DEVICE__)
    if(track_rid_given())
    {
        track_drv_sleep_enable(SLEEP_OBD_MOD, FALSE);
    }
#endif /* __TEST_DEVICE__ */

#if defined(__GPS_UART__)
    track_drv_mgps_on();
#endif /* __GPS_UART__ */
#if 0//defined(__NT55__)
	LOGD(L_DRV, L_V5, "OBD 开关 %d",G_parameter.obd.sw);
	GPIO_ModeSetup(OBD_POWER_GPIO, 0);
	GPIO_InitIO(1, OBD_POWER_GPIO);
	GPIO_WriteIO(1, OBD_POWER_GPIO);
	
#if defined(__BMS_PHYLION__)
	track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_9600);
	tr_start_timer(TRACK_CUST_BMS_CMD_TIMER_ID, 2000, track_cust_bms_command);
	return;
#endif
#if defined(__ATECH__)
	track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_115200);
#else
	track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_9600);
#endif
#if defined(__OBD__)
	if(G_parameter.obd.sw == 1)
	{
		tr_start_timer(DEALY_INIT_OBD_TIMER_ID, 1000, track_drv_obd_power_init);
	}
#endif
#endif
#if defined(__NF2318__)
		track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_9600);
		//track_drv_uart_init_public(MOD_MMI, 2, UART_BAUD_9600);
		
		//track_cust_controller_data_init();//暂时去掉开机初始化后就下发指令，放在开锁后
#endif
#if defined(__BMS_PHYLION__)
	tr_start_timer(TRACK_CUST_BMS_INIT_TIMER_ID, 10*1000,track_cust_bms_uart_init);
#endif
    if(track_project_uart_init() == 0)
    {
        return;
    }

}


/**
 case TelephonyManager.SIM_STATE_ABSENT :sb.append("无卡");break;
 case TelephonyManager.SIM_STATE_UNKNOWN :sb.append("未知状态");break;
 case TelephonyManager.SIM_STATE_NETWORK_LOCKED :sb.append("需要NetworkPIN解锁");break;
 case TelephonyManager.SIM_STATE_PIN_REQUIRED :sb.append("需要PIN解锁");break;
 case TelephonyManager.SIM_STATE_PUK_REQUIRED :sb.append("需要PUK解锁");break;
 case TelephonyManager.SIM_STATE_READY :sb.append("良好");break;
 **/

/******************************************************************************
 *  Function    -  track_drv_gps_read_uart
 *
 *  Purpose     -  这个处理非MTK平台的GPS透传数据
 *
 *  Description -   MT2503不用
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gps_read_uart(void)
{
    kal_uint16 readTotal = 0, avail = 0, readSize = 0 , index = 0, iEnd = 0, tCous = 0;
    kal_uint8 status;
    char *pIndex = NULL, *p77 = NULL;
    static kal_uint8 buf[GPS_REVICE_BUFF_SIZE] = {0};
    static kal_uint16 jIdx = 0;
    module_type IR_Owner_save;

    memset(&buf, 0, GPS_REVICE_BUFF_SIZE);
    IR_Owner_save = UART_GetOwnerID(GPS_UART_PORT);
    avail = UART_GetBytesAvail(GPS_UART_PORT);
    LOGD(L_DRV, L_V7, "port:%d,owner=%d,gps_status:%d,avail:%d", GPS_UART_PORT, IR_Owner_save, drv_gps_status, avail);
    readTotal = 0;

    while(avail)
    {
        readSize  = UART_GetBytes(GPS_UART_PORT, (kal_uint8*)&buf[readTotal], 30, &status, IR_Owner_save);
        readTotal += readSize;
        if(readTotal == 0)
        {
            break;
        }
        else if(readTotal > GPS_REVICE_BUFF_LIMIT || readSize != 30)
        {
            LOGD(L_DRV, L_V9, "11status:%d,size=%d,buf:%s", status, readTotal, buf);

            if(track_status_gpstc(2))
            {
                track_trace((kal_uint8*)buf, readTotal);
            }
            else if(drv_gps_status) //GPS关闭时不解码
            {
                //track_uart_decode(buf, readTotal);
            }

            readTotal = 0;
            if(readSize != 30)
            {
                break;
            }
        }
    }
    readSize = strlen((char*) buf);
    if(readSize > 10 && track_is_timer_run(GPS_DATA_UPDATA_TIMER_ID))
    {
        track_stop_timer(GPS_DATA_UPDATA_TIMER_ID);
    }
    LOGD(L_DRV, L_V9, "readSize:%d,status:%d,%d", readSize, status, drv_gps_status);
    LOGH(L_DRV, L_V7, buf, 10);
}


#if defined (__OIL_DETECTION__)
void track_cust_recv_ultrasonic_data(kal_uint8* data, kal_uint16 len)
{
    static kal_uint8  buf[2000] = {0};
    static kal_uint16 flag = 0;
    static kal_uint32 tick = 0;
    static int last_len = 0;
    kal_uint8 *start = NULL, *end = NULL;
    const char* findindex = NULL;
    int tmp = 0;

    int j = 0, x;


    if(len <= 0 || (len == 1 && (*data == 0 || *data == 0xFF))) return;

    if(tick >= 0 && OTA_kal_get_systicks() - tick > 8 * KAL_TICKS_1_SEC)
    {
        flag = 0;
    }

    tick = OTA_kal_get_systicks();

    if(flag + len < 1999)
    {
        for(j = 0; j < len; j++)
        {
            if(data[j] > 0 && data[j] <= 128)
            {
                buf[flag++] = data[j];
            }
        }
        buf[flag] = 0;
    }
    else
    {
        if(len > 1999)
        {
            LOGD(L_DRV, L_V1, "ERROR : Data too long!");
            return;
        }
        for(j = 0, flag = 0; j < len; j++)
        {
            if(data[j] > 0 && data[j] <= 126)
            {
                buf[flag++] = data[j];
            }
        }
        buf[flag] = 0;
    }
    LOGD(L_DRV, L_V5, "[recv](%d,%d,%d): %s", strlen(buf), flag, len, data);
    LOGH(L_DRV, 6, buf, flag);

    if(flag <= 0) return;
    buf[flag] = 0;
    for(j = 0; j < flag - 5; j++)
    {
        if(buf[j] == '!' && buf[j+1] == 'A' && buf[j+2] == 'I' && buf[j+3] == 'O' && buf[j+4] == 'I')
        {
            start = &buf[j];
            end = strstr(start, "\r\n");
            if(end != NULL)
            {
                flag = 0;
                findindex = strchr(start, '\r');
                tmp = findindex - start;
                LOGD(L_DRV, L_V1, "%d", tmp);
                if(G_realtime_data.netLogControl == 512)
                {
                    cust_packet_log_data_ext2(8, "[start]", start, tmp);
                }
                track_cust_oil_data_to_server(start, tmp);
            }
        }
    }

}
#endif

/******************************************************************************
 *  Function    -  track_uart_decode
 *
 *  Purpose     -  NMEA 数据接收后分包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_uart_decode(char* buf, kal_uint16 len)
{
    char buf2[200] = {0};
    char buf_tmp[200] = {0};
    char *p_start = NULL, *p_end;
    int buf_length, item_length = 0;

    if(GPS_DECODE_BUF_SIZE < len)
    {
        len = GPS_DECODE_BUF_SIZE - 1;
    }
    //LOGH(L_OS, L_V6, buf, len);

    strncat(uart_buf, buf, GPS_DECODE_BUF_SIZE);
    buf_length = strlen(uart_buf);

    if(buf_length > 0 || buf_length <= GPS_REVICE_BUFF_SIZE + GPS_SINGLE_ITME_MAX_SIZE)
    {
        p_start = strstr(uart_buf, "$");
        if(p_start != NULL)
        {
            while(1)
            {
                item_length = 0;
                p_end = strstr(p_start, "\r\n");
                if(p_end != NULL)
                {
                    memset(buf2, 0, GPS_SINGLE_ITME_MAX_SIZE);
                    item_length = p_end - p_start + 2;
                    if(item_length < GPS_SINGLE_ITME_MAX_SIZE)
                    {
                        memcpy(buf2, p_start, item_length);
                        GPS_Data_Decode2(buf2, strlen(buf2));
                    }
                    else
                    {
                        LOGC(L_DRV, L_V5, "single packet legth error");
                    }
                    p_start = p_end + 2;
                }
                else
                {
                    item_length = strlen(p_start);
                    if(item_length > GPS_SINGLE_ITME_MAX_SIZE)
                    {
                        LOGD(L_DRV, L_V5, "解码异常(%d > 200)", item_length);
                        memset(uart_buf, 0x00, GPS_DECODE_BUF_SIZE);
                        break;
                    }
                    memset(buf_tmp, 0x00, GPS_SINGLE_ITME_MAX_SIZE);
                    strncpy(buf_tmp, p_start, GPS_SINGLE_ITME_MAX_SIZE);
                    memset(uart_buf, 0x00, GPS_DECODE_BUF_SIZE);
                    strncpy(uart_buf, buf_tmp, GPS_SINGLE_ITME_MAX_SIZE);
                    break;
                }

            }/*end while*/
        }
        else
        {
            memset(uart_buf, 0x00, GPS_DECODE_BUF_SIZE);
        }

    }
    else
    {
        LOGD(L_DRV, L_V6, "超长或零数据:%d", buf_length);
        memset(uart_buf, 0x00, GPS_DECODE_BUF_SIZE);
    }

}

void track_cust_gps_factory(void)
{
#if defined( __BD_AT6558__)
    char coldstart[] = "$PCAS10,3*1F\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 14);
#endif /* __BD_AT6558__ */
}
void track_cust_gps_firware(void)
{
#if defined( __GPS_G3333__)||defined(__GPS_MT3333__)
    char coldstart[] = "$PMTK605*31\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, sizeof(coldstart));

#endif /* __GPS_MT3337__ */
}

void track_cust_ubxcold(void)
{
#if defined( __GPS_G3333__)||defined(__GPS_MT3333__)
    char coldstart[] = "$PMTK103*30\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 13);
#elif defined( __BD_AT6558__)
    char coldstart[] = "$PCAS10,2*1E\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 14);
#else
    char ubxColdStart[] = {0xB5, 0x62 , 0x06 , 0x04 , 0x04 , 0x00 , 0xFF , 0x07 , 0x02 , 0x00 , 0x16 , 0x79}; // UBX Message to force a coldstart
    U_PutUARTBytes(GPS_UART_PORT, ubxColdStart, 12);
#endif /* __GPS_MT3337__ */
}

void track_cust_exgps_warm(void)
{
#if defined( __GPS_G3333__)||defined(__GPS_MT3333__)
    char coldstart[] = "$PMTK102*31\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 13);
#elif defined( __BD_AT6558__)
    char coldstart[] = "$PCAS10,1*1D\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 14);
#else
    LOGS("cant support!");
#endif
}

void track_cust_ubxhot(void)
{
#if defined( __GPS_G3333__)||defined(__GPS_MT3333__)
    char coldstart[] = "$PMTK101*32\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 13);
#elif defined( __BD_AT6558__)
    char coldstart[] = "$PCAS10,0*1C\r\n";
    U_PutUARTBytes(GPS_UART_PORT, coldstart, 14);
#else
    char ubxColdStart[] = {0xB5, 0x62 , 0x06 , 0x04 , 0x04 , 0x00 , 0xFF , 0x07 , 0x02 , 0x00 , 0x16 , 0x79}; // UBX Message to force a coldstart
    LOGS("can not support this function!");
    U_PutUARTBytes(GPS_UART_PORT, ubxColdStart, 12);
#endif /* __GPS_MT3337__ */
}

kal_uint8 track_get_gps_ota(kal_uint8 flag) //for OTA interface
{
    static kal_uint8 gps_ota = 0;
    if(flag == 1 || flag == 0 || flag == 2)
    {
        gps_ota = flag;
    }
    return gps_ota;
}


/******************************************************************************
 *  Function    -  track_drv_uart_read_data
 * 
 *  Purpose     -  串口消息通知接收数据拼包
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_drv_uart_read_data(UART_PORT port)
{
    kal_uint16 readTotal = 0, avail = 0, readSize = 0;
    kal_uint8 status;
    static kal_uint8 buf[1024];
    module_type IR_Owner_save;

    memset(buf, 0, 1024);
    IR_Owner_save = UART_GetOwnerID(port);
    avail = UART_GetBytesAvail(port);
    LOGD(L_DRV, L_V7, "port=%d,owner=%d,avail:%d", port, IR_Owner_save, avail);

    while(avail)
    {
        readSize  = UART_GetBytes(port, (kal_uint8*)&buf[readTotal], 60, &status, IR_Owner_save);
        readTotal += readSize;
        LOGD(L_DRV, L_V7, "readTotal %d,%d", readTotal, readSize);
        if(readTotal == 0)
        {
            break;
        }
        else if(readTotal > 1024 - 61 || readSize != 60 || (readTotal > 0 && readSize == 0))
        {
            track_drv_uart_receice_data_notify(port, buf, readTotal);
			if(readSize != 60)
			{
            	break;
			}
			readTotal = 0;
        }

        
    }
	//readTotal = 0;
}

/******************************************************************************
 *  Function    -  track_drv_uart_ready_read
 *
 *  Purpose     -  UART数据接收
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-08-30,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_uart_ready_read(void* msg)
{
    uart_ready_to_read_ind_struct *tmp = (uart_ready_to_read_ind_struct*)msg;
    track_drv_uart_read_data(tmp->port);
}


static void track_drv_uart_to_sleep(void)
{
    track_drv_sleep_enable(SLEEP_EXT_UART_MOD, KAL_TRUE);
}

/******************************************************************************
 *  Function    -  track_drv_uart_config
 *
 *  Purpose     -  串口初始化唯一接口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_uart_config(UART_PORT port, module_type ownerid, UART_baudrate uart_baud)
{
    DCL_INT32 status;
    UART_CONFIG_T Dcb;
    module_type IR_Owner_save;

    //对UART TX RX对应的GPIO进行配置MT2503
    //端口与平台相关 chengj
    if(uart_port1 == port)
    {
        GPIO_ModeSetup(10, 1);
        GPIO_ModeSetup(11, 1);
    }
    else if(uart_port2 == port)
    {
        LOGD(L_DRV, L_V1, "error:this for GPS");
        return 0;
        //GPIO_ModeSetup(12, 2);
        //GPIO_ModeSetup(17, 2);
    }
    else if(uart_port3 == port)
    {
        GPIO_ModeSetup(0, 3);
        GPIO_ModeSetup(1, 3);
    }

    //防止需要使用的uart port被其他模块所打开，
    //故使用如下函数将当前的owner id注册到该uart port
    IR_Owner_save = UART_GetOwnerID(port);
    if(ownerid != IR_Owner_save)
    {
        LOGD(L_DRV, L_V1, "UART %d has been used", port);
        track_uart_close(port, IR_Owner_save);
    }

    //开启uart power
    UART_TurnOnPower(port, KAL_TRUE);
    UART_SetOwner(port, ownerid);

    status = UART_Open(port, ownerid);
    LOGD(L_DRV, L_V5, "port=%d,statu=%d", port,status);
    if(status != STATUS_OK)
    {
        return 0;
    }

    Dcb.u4Baud = uart_baud;
    Dcb.u1DataBits = len_8;
    Dcb.u1StopBits = sb_1;			/*dataBits*/
    Dcb.u1Parity = pa_none;/*stopBits*/
    Dcb.u1FlowControl = fc_none;		/*parity*/
    Dcb.ucXonChar = 0x11; 			/*no flow control*/
    Dcb.ucXoffChar = 0x13;			/*xonChar*/
    Dcb.fgDSRCheck = KAL_FALSE;			/*xoffChar*/
    //设定波特率等信息，注意在调用此函数之前需要先初始化Dcb结构体
    UART_SetDCBConfig(port, &Dcb, MOD_MMI);
    return 1;
}

void track_drv_uart_close(DCL_DEV port)
{
    module_type IR_Owner_save;
    IR_Owner_save = UART_GetOwnerID(port);
    track_uart_close(port, IR_Owner_save);
}


/******************************************************************************
 *  Function    -  track_drv_uart_write
 * 
 *  Purpose     -  统一串口写接口
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-10-10,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_uart_write(UART_PORT port, kal_uint8 *data, kal_uint16 len)
{
    module_type IR_Owner_save = UART_GetOwnerID(port);
    if(len < 2000)
    {
        LOGH(L_DRV, L_V6, data, len);
        LOGD(L_DRV, L_V5, "UART>>%s", (char*)data);
    }

    track_drv_sleep_enable(SLEEP_EXT_UART_MOD, KAL_FALSE);
    tr_start_timer(TRACK_CUST_EXTCHIP_SLEEP_TIMER_ID, 2000, track_drv_uart_to_sleep);

#if defined (__MCU_SW_UPDATE__)
    if(track_is_in_update_bootload_cmd())
    {
        if(track_is_timer_run(TRACK_CUST_EXTCHIP_SLEEP_TIMER_ID))
        {
            track_stop_timer(TRACK_CUST_EXTCHIP_SLEEP_TIMER_ID);
        }

        if(strstr(data, "AT^GT_CM=") != NULL)
        {
            LOGD(L_DRV, L_V1, "MCU升级中禁止发 AT^GT_CM=");
            return 0;
        }
    }
#endif /* __MCU_SW_UPDATE__ */

    UART_PutBytes(port, data, len, IR_Owner_save);

    return 1;
}


/******************************************************************************
 *  Function    -  track_drv_uart_receice_data_notify
 * 
 *  Purpose     -  统一串口接收，各项目单独处理
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-10-10,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_uart_receice_data_notify(UART_PORT port, kal_uint8* data, kal_uint16 len)
{
    if(track_project_uart_receice_data_notify(port, data, len) == 0)
    {
        return;
    }
}

void track_drv_uart1_write_data(kal_uint8 *data, kal_uint16 len)
{
    track_drv_uart_write(uart_port1, data, len);
}

void track_drv_uart2_write_data(kal_uint8 *data, kal_uint16 len)
{
    track_drv_uart_write(uart_port2, data, len);
}
void track_drv_uart3_write_data(kal_uint8 *data, kal_uint16 len)
{
    track_drv_uart_write(uart_port3, data, len);
}
/******************************************************************************
 *  Function    -  track_cust_wakeup_external_reinit
 *
 *  Purpose     -  休眠后唤醒后重新初始化外部设备串口
 *
 *  Description -  track_cust_wakeup_external_reinit
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-06-27,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_wakeup_external_reinit()
{
	tr_stop_timer(TRACK_CUST_CONTROLLER_DATA_TIMER_ID);
	//初始化BMS
	tr_stop_timer(TRACK_CUST_BMS_CMD_TIMER_ID);
	tr_start_timer(TRACK_CUST_BMS_INIT_TIMER_ID, 1000,track_cust_bms_uart_init);
	//初始化控制器
	tr_stop_timer(TRACK_CUST_CONTROLLER_DATA_TIMER_ID);
	track_drv_uart_config(uart_port3, MOD_MMI, UART_BAUD_9600);
	tr_start_timer(TRACK_CUST_CONTROLLER_DATA_TIMER_ID, 1000, track_cust_controller_data_init);
}

