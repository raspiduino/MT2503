#if defined(__NF2319__)
/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_os_paramete.h"
#include "track_project_control_mf.h"
/*****************************************************************************
* Typedef  Enum                         枚举定义
*****************************************************************************/

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
 static ctrl_data_struct  ctrl_params = {0};
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/

/*****************************************************************************
* Local variable                        局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable                       全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/

/*****************************************************************************
 *  Global Functions    - Extern        引用外部函数
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions                     本地函数
 *****************************************************************************/
 
/******************************************************************************
 *  Function    -  ecc_data
 *
 *  Purpose     -  校验和
 *
 *  Description - 和的低 8 位
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-11-01,  Cjj  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 ecc_data(kal_uint8* data, kal_uint16 len)
{
    int i,tmp=0;
    for(i=0;i<len;i++)
    {
       tmp += data[i];
    }
    tmp&=0xff;
    return tmp;
}

 void control_write_data()
{
    static U8 buf[6] = {0}, len = 0;
    static kal_uint16 ecc;
    len = 5; //目前固定长度为5
    buf[0] = 0x59;
    buf[1] = len;
    buf[2] = G_parameter.ctrl.state;
    buf[3] = G_parameter.ctrl.speed;
    buf[4] = ecc_data(&buf[1],3);
    track_drv_uart3_write_data(buf, len);
    tr_start_timer(TRACK_RROJECT_CONTROL_UART_WRITE_ID, 500, control_write_data);//间隔必须>200MS；刚上电500ms内无法接收
}

/******************************************************************************
 *  Function    -  track_ctrl_uart_rece
 *
 *  Purpose     -  接收控制器的数据处理
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-06-19,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
 void track_ctrl_uart_rece(kal_uint8* buff, kal_uint16 len)
{
    kal_uint8* p = NULL;
   // kal_uint8 speed_data[1] = {0};
    kal_uint8 data[11] = {0};
    kal_uint8 ecc;
    int speed_Tx=0;
    float speed=0,distance=0;
    ctrl_data_struct  params = {0};
    if((buff == NULL) || (len == 0))
    {
        return;
    }

    if(len > 10)
    {
        len = 10;
    }
    memcpy(data, buff, len);

    LOGH(L_APP, L_V4, data, len);
    ecc = ecc_data(&data[1],8);
    if(ecc!=data[9])
    {
      LOGD(L_APP, L_V4,"[track_ctrl_uart_rece]error:ecc %d/%d",ecc,data[9]);
      return;
    }
    //速率
   // speed_data[0] = data[3];
  //  speed_data[1] = data[2];
  //  LOGH(L_APP, L_V4, speed_data, 2);
  //  GET_UINT16_BE(speed_Tx,speed_data,0);
  speed_Tx = data[3]<<8;
  speed_Tx |=data[2];
    //速度KM/H
    LOGD(L_APP, L_V4,"速率:%d",speed_Tx);    
    //speed = (speed_Tx*7200 *(16.7*2.54/100000)*3.14)/6*20*100;
    speed =(float)speed_Tx*0.079915512;
    LOGD(L_APP, L_V4,"speed:%.06f",speed);
    speed = (int)(speed*100);//速度精度转变成0.00 KM/H
    params.speed = speed/100;
    //控制器电流
    params.iChr = data[4];
    //控制器电压
    params.vChr = data[5];
    /*
    整车状态 Status1 : 1：有故障 0 ： 无故障
    Bit 7 ： 备用
    Bit 6 ： 备用
    Bit 5 ： 备用
    Bit 4 ： 欠压报警
    Bit 3 ： 控制器故障
    Bit 2 ： 电机霍尔故障
    Bit 1 ： 刹车故障
    Bit 0 ： 转把故障
    */
    params.state1 = data[6];
    /*
   整车状态 Status2: 1：有故障 0 ： 无故障
    Bit 7 ： 备用
    Bit 6 ： 备用
    Bit 5 ： 备用
    Bit 4 ： 备用
    Bit 3 ： 备用
    Bit 2 ： 备用
    Bit 1 ： 备用
    Bit 0 ： 备用 
    */
    params.state2 = data[7];

    //计算单位时间内(500MS)的位移，单位M
    distance = (int)(params.speed/3.6 *0.5*100);
    params.distance = distance/100 + ctrl_params.distance;

    memcpy(&ctrl_params, &params, sizeof(ctrl_params));
    LOGD(L_APP, L_V4,"速度:%.02f ,电流:%d ,电压:%d ,订单里程:%.02f"
        ,ctrl_params.speed,ctrl_params.iChr,ctrl_params.vChr,ctrl_params.distance);
}

#endif/*__EL100_M03__*/
