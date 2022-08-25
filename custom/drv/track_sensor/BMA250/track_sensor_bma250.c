/**************************************************************************************************/
/*  $Date: March-1-20111
 *   $Revision: 1.01$
 *
 */

/**************************************************************************************************
* Copyright (C) 2011 Bosch Sensortec GmbH
*
* BOSCH algorithm API
*
* Usage:		BOSCH portrait landscape and skake snap algorithm
*
* Author:       yongsheng.gao@bosch-sensortec.com
**************************************************************************************************/
/*  Disclaimer
*
* Common:
* Bosch Sensortec products are developed for the consumer goods industry. They may only be used
* within the parameters of the respective valid product data sheet.  Bosch Sensortec products are
* provided with the express understanding that there is no warranty of fitness for a particular purpose.
* They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device
* that may lead to bodily harm or property damage if the system or device malfunctions. In addition,
* Bosch Sensortec products are not fit for use in products which interact with motor vehicle systems.
* The resale and/or use of products are at the purchaser抯 own risk and his own responsibility. The
* examination of fitness for the intended use is the sole responsibility of the Purchaser.
*
* The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for
* incidental, or consequential damages, arising from any product use not covered by the parameters of
* the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch
* Sensortec for all costs in connection with such claims.
*
* The purchaser must monitor the market for the purchased products, particularly with regard to
* product safety and inform Bosch Sensortec without delay of all security relevant incidents.
*
* Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid
* technical specifications of the product series. They are therefore not intended or fit for resale to third
* parties or for use in end products. Their sole purpose is internal client testing. The testing of an
* engineering sample may in no way replace the testing of a product series. Bosch Sensortec
* assumes no liability for the use of engineering samples. By accepting the engineering samples, the
* Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering
* samples.
*
* Special:
* This software module (hereinafter called "Software") and any information on application-sheets
* (hereinafter called "Information") is provided free of charge for the sole purpose to support your
* application work. The Software and Information is subject to the following terms and conditions:
*
* The Software is specifically designed for the exclusive use for Bosch Sensortec products by
* personnel who have special experience and training. Do not use this Software if you do not have the
* proper experience or training.
*
* This Software package is provided `` as is `` and without any expressed or implied warranties,
* including without limitation, the implied warranties of merchantability and fitness for a particular
* purpose.
*
* Bosch Sensortec and their representatives and agents deny any liability for the functional impairment
* of this Software in terms of fitness, performance and safety. Bosch Sensortec and their
* representatives and agents shall not be liable for any direct or indirect damages or injury, except as
* otherwise stipulated in mandatory applicable law.
*
* The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no
* responsibility for the consequences of use of such Information nor for any infringement of patents or
* other rights of third parties which may result from its use. No license is granted by implication or
* otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are
* subject to change without notice.
*
* It is not allowed to deliver the source code of the Software to any third party without permission of
* Bosch Sensortec.
*/
/*************************************************************************************************/
#ifdef __BOSCH_BMA250__

#include "kal_release.h"
#include "gpio_sw.h"
#include "MMI_features.h"
#include "gpio_hw.h"
#include "motion_sensor.h"
#include "Bma250.h"
#include "track_sensor_bma250.h"
#include "TimerEvents.h"
#include "NVRAMType.h"  /* NVRAM data type */
#include "NVRAMEnum.h"  /* NVRAM ID define */
#include "track_os_timer.h"
#include "track_drv_sensor.h"
#include "stdlib.h"
#include <math.h>
#if defined (__GPS_TRACK__)
#include "ell_os.h"
#endif /* __GPS_TRACK__ */

#define i2c_delay   0

#if defined (MCU_52M)
   #define delay_short 5
   #define delay_long  10
#elif defined (MCU_104M)
   #define delay_short 10
   #define delay_long  20
#elif defined (MCU_208M)
   #define delay_short 20
   #define delay_long  40
#elif defined (MCU_260M)
   #define delay_short 25
   #define delay_long  50
#elif defined (MCU_364M)
   #define delay_short 35
   #define delay_long  70
#else
#error not support
//与系统时钟有关
#endif


#define INSTRUCTION_CLK_NUM 4

#if defined (MCU_13M)
    #define MCU_CLK_HZ 13000
#elif defined(MCU_26M)
    #define MCU_CLK_HZ 26000
#elif defined(MCU_39M)
    #define MCU_CLK_HZ 39000
#elif defined(MCU_52M)
    #define MCU_CLK_HZ 52000
#elif defined(MCU_104M)
    #define MCU_CLK_HZ 104000
#elif defined(MCU_208M)
    #define MCU_CLK_HZ 208000
#elif defined(MCU_260M)
    #define MCU_CLK_HZ 260000
#elif defined (MCU_364M)
    #define MCU_CLK_HZ 364000
#else
#error not support
//与系统时钟有关
#endif



#define EDGE_SENSITIVE           	KAL_TRUE
#define LEVEL_SENSITIVE          	KAL_FALSE

#define SET_I2C_CLK_OUTPUT 		GPIO_InitIO(OUTPUT,ACC_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_OUTPUT		GPIO_InitIO(OUTPUT,ACC_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_INPUT		GPIO_InitIO(INPUT,ACC_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_HIGH		GPIO_WriteIO(1,ACC_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_LOW			GPIO_WriteIO(0,ACC_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_HIGH		GPIO_WriteIO(1,ACC_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_LOW		GPIO_WriteIO(0,ACC_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define GET_I2C_DATA_BIT		GPIO_ReadIO(ACC_SENSOR_SDA)

//defination only for MTK platform compiler
#define ACC_0G_X		(2059)
#define ACC_1G_X		(2059+128)
#define ACC_MINUS1G_X	(2059+128)

#define ACC_0G_Y		(2059)
#define ACC_1G_Y		(2059+128)
#define ACC_MINUS1G_Y	(2059+128)

#define ACC_0G_Z		(2059)
#define ACC_1G_Z		(2059+128)
#define ACC_MINUS1G_Z	(2059+128)


extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);
extern void EINT_Mask(kal_uint8 eintno);
extern void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask);
extern kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens);

static  char i_cnt=0;
static U8 bma250_chip_id=0XFF;
static bma250_t t_bma250;

static void acc_sensor_interrput_disable(void)
{
	unsigned char i;
	bma250_set_mode(0x00);

	for (i=0; i<11; i++)
	{
		bma250_set_Int_Enable(i, 0);
	}

	bma250_reset_interrupt();
}

static void acc_sensor_write_1byte(kal_int8 add, kal_int8 data)
{
   kal_int32 i, j;

   //Start
   SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_OUTPUT;
   SET_I2C_DATA_HIGH;
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_LOW;

   //First step--Send write command
   for (i = 7; i >= 0; i--)
   {
      if (BMA250_I2C_SLAVE_WRITE_ADDR &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //Second step -- Send register address
   for (i = 7; i >= 0; i--)
   {
      if (add &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //Third step -- Send the data
   for (i = 7; i >= 0; i--)
   {
      if (data &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //STOP
   //SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_HIGH;
}

//In fact in this version's driver, only support 1 byte write
//If needed multi bytes write, must modify this function
char acc_sensor_write_bytes(kal_uint8 dev_addr, kal_uint8 reg_addr,kal_uint8 *reg_data, kal_uint8 wr_len)
{
   int i = 0;
   for (i = 0; i < wr_len; i++)
   {
      acc_sensor_write_1byte((reg_addr + i), *(reg_data + i));
   }

   return 1;
}

char acc_sensor_read_bytes(kal_uint8 dev_addr, kal_uint8 reg_addr, kal_uint8 *reg_data, kal_uint8 r_len)
{
   kal_int32 i, j, k;

   for (k = 0; k < r_len; k++)
   {
      *(reg_data + k) = 0;
   }

   //START
   SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_OUTPUT;
   SET_I2C_DATA_HIGH;
   SET_I2C_CLK_HIGH;
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_LOW;

   //Need to confirm this delay
   for (j = 0; j < delay_long; j++);

   //First step--Send write command
   for (i = 7; i >= 0; i--)
   {
      if (BMA250_I2C_SLAVE_WRITE_ADDR &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      for (j = 0; j < delay_short; j++);
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //Second step -- Send register address
   for (i = 7; i >= 0; i--)
   {
      if ((reg_addr) &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //write stop
   SET_I2C_DATA_LOW;
   SET_I2C_CLK_LOW;
   for(j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for(j = 0; j < delay_short; j++);
   SET_I2C_DATA_HIGH;
   for(j = 0; j < delay_short; j++);

   //read start
   //SET_I2C_DATA_HIGH;
   //SET_I2C_CLK_HIGH;
   SET_I2C_DATA_LOW;
   for(j = 0; j < delay_short; j++);
   SET_I2C_CLK_LOW;

   //Third step -- Send read command
   for (i = 7; i >= 0; i--)
   {
      if ((BMA250_I2C_SLAVE_READ_ADDR) &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   for (k = 0; k < r_len; k++)
   {
      //----- Read data out now --------
      // Read  data
      SET_I2C_DATA_INPUT;

      for (i = 7; i >= 0; i--)
      {
         SET_I2C_CLK_HIGH;
         for (j = 0; j < delay_long; j++);
         if (GET_I2C_DATA_BIT)
         {
            *(reg_data + k) |= (1 << i);
         }
         SET_I2C_CLK_LOW;
         for (j = 0; j < delay_long; j++);
      }

	//Check if this is the last byte or not
	//if yes, send ACK, data=0
	//if no, send NACK, data=1
      if (k != r_len - 1)
      {
         //ACK
         SET_I2C_DATA_OUTPUT;
         SET_I2C_DATA_LOW;
         for (j = 0; j < delay_short; j++);
         SET_I2C_CLK_HIGH;
         for (j = 0; j < delay_long; j++);
         SET_I2C_CLK_LOW;
      }
      else
      {
         //NACK
         SET_I2C_DATA_OUTPUT;
         SET_I2C_DATA_HIGH;
         for (j = 0; j < delay_short; j++);
         SET_I2C_CLK_HIGH;
         for (j = 0; j < delay_long; j++);
         SET_I2C_CLK_LOW;
      }
   }


   //STOP
   SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_HIGH;

   return 1;
} /* I2C_send_byte() */

static void System_Delay_1ms(kal_uint8 delay_count)
{
   kal_uint32 x;
   volatile kal_uint32 delay;

   for (delay = 0; delay < delay_count; delay++)
   {
      for (x = 0; x < (MCU_CLK_HZ / INSTRUCTION_CLK_NUM); x++){}
   }
}

static void acc_sensor_pwr_up(void)
{
   bma250_set_mode(bma250_MODE_NORMAL);
   System_Delay_1ms(1);
}

static void acc_sensor_pwr_down(void)
{
   bma250_set_mode(bma250_MODE_SUSPEND);
}

static void acc_sensor_init(void)
{   
   static kal_uint8 p_flag = 0;
   
   GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);
   GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);

   if (p_flag == 0)
   {
      p_flag=1;

      bma250_init(&t_bma250);
   }
   acc_sensor_pwr_up();

   acc_sensor_interrput_disable();

   bma250_set_range(bma250_RANGE_2G);
   bma250_set_bandwidth(bma250_BW_125HZ);
}

static void sensor_bma250_init_with_interrupt(void)
{
   static kal_uint8 p_flag = 0;

   GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);
   GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);
   //kal_prompt_trace(MOD_TST, "sensor_bma250_init_with_interrupt");

   if (p_flag == 0)
   {
      p_flag=1;

      bma250_init(&t_bma250);
      bma250_chip_id=t_bma250.chip_id;

   }
   acc_sensor_pwr_up();

   acc_sensor_interrput_disable();

   // normal settings
#if defined(__DROP_ALM__) //开启跌倒报警，注意测试震动报警
   bma250_set_range(bma250_RANGE_8G);
#else
   bma250_set_range(bma250_RANGE_2G);
#endif
   bma250_set_bandwidth(bma250_BW_125HZ);

   // set interrupt latch duration.
   bma250_set_Int_Mode(0x03);	
   //5-latch 4S   ---  SENSOR_BMA250_SW_DEBOUNCE_TIME = 250
   //3-latch 1S   ---  SENSOR_BMA250_SW_DEBOUNCE_TIME = 80
   //必须和SENSOR_SW_DEBOUNCE_TIME 配对修改
   //同步track_acc_sensor_data_self_test 参数自检
   /*震动检测中断响应速度       --    chengjun  2012-12-01*/

   // map all interrupt to INT1
   bma250_set_int_data_sel(0);	// map new data interrupt to INT1.
   bma250_set_int1_pad_sel(0);	// low G 		--> INT1
   bma250_set_int1_pad_sel(1);	// high G 		--> INT1
   bma250_set_int1_pad_sel(2);	// slope 		--> INT1
   bma250_set_int1_pad_sel(3);	// double tap 	--> INT1
   bma250_set_int1_pad_sel(4);	// single tap 	--> INT1
   bma250_set_int1_pad_sel(5);	// orient 		--> INT1
   bma250_set_int1_pad_sel(6);	// flat 		--> INT1
   //bma250_set_int2_pad_sel();

   // set INT1 trigger level, push pull and open drive
   bma250_set_int_set(0, 1);	// INT1 level high
   bma250_set_int_set(1, 0);	// INT1 push pull(0), open drive(1)
   bma250_set_int_set(2, 1);	// INT2 level high
   bma250_set_int_set(3, 0);	// INT2 push pull(0), open drive(1)
   //bma250_set_int_src();

   // example, set slope(any motion) interrupt
   bma250_set_slope_duration(1);
   bma250_set_slope_threshold(OTA_track_sensor_config_data->sensor_threshold);
   bma250_set_enable_slope_interrupt(3);
   bma250_reset_interrupt();

    track_sensor_bma250_interrput_configuration();

}
//This function only for MTK platfrom compiler
void acc_sensor_get_6bytes(kal_uint16 *accl_x,kal_uint16 *accl_y,kal_uint16 *accl_z)
{
   bma250acc_t accl;

   bma250_read_accel_xyz(&accl);

   *accl_x=accl.x;
   *accl_y=accl.y;
   *accl_z=accl.z;
}


#if defined (__TRACK_SENSOR__)

/******************************************************************************
 *   
 *     Sensor 自定义部分
 *
 ******************************************************************************/
 
/******************************************************************************
 *  Function    -  track_sensor_bma250_data_self_test
 * 
 *  Purpose     -  sensor 工作异常监测
 * 
 *  Description - 定时参数自检，若异常则重置
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 07-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_bma250_data_self_test(void)
{
    unsigned char bw=0;
    unsigned char range=0;
    unsigned char mode=0;
    unsigned char threshold=0;
    
    bma250_get_bandwidth(&bw);
    bma250_get_range(&range );//读出的参数与设置值不同
    bma250_get_Int_Mode(&mode );
    bma250_get_slope_threshold(&threshold);
        
    if ((bw!=bma250_BW_125HZ )||(range!=3)||(mode!=3)||(threshold != OTA_track_sensor_config_data->sensor_threshold))
    {
        kal_prompt_trace(MOD_TST,"track_sensor_bma250_data_self_test Sensor data error (%d-%d-%d-%d) !=[12-3-3-%d]",bw,range,mode,threshold,OTA_track_sensor_config_data->sensor_threshold);
        OTA_tr_stop_timer(MOTION_SENSOR_DATA_TIMER_ID);
        OTA_tr_start_timer(MOTION_SENSOR_RESET_TIMER_ID,  3000, track_sensor_bma250_reset);
    }
    OTA_tr_start_timer(MOTION_SENSOR_DATA_TIMER_ID, 60000, track_sensor_bma250_data_self_test);
}

/******************************************************************************
 *  Function    -  track_sensor_bma250_reset
 *
 *  Purpose     -  sensor 复位
 *
 *  Description - 
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_bma250_reset(void)
{
    //kal_prompt_trace(MOD_TST, "track_sensor_bma250_reset sensor bma250/E reset");
    acc_sensor_pwr_down();
    OTA_tr_start_timer(MOTION_SENSOR_RESET_TIMER_ID,  10000,sensor_bma250_init_with_interrupt);
}


/******************************************************************************
 *  Function    -  track_sensor_bma250_interrput_configuration
 * 
 *  Purpose     -  注册高电平(  震动) 响应
 * 
 *  Description -
 *  
 * 1、自动清标志
 * 2、软件防抖200ms 
           (sensor BMA250 单次震动触发高脉冲宽280ms  左右)
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 07-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_bma250_interrput_configuration(void)
{
    //kal_prompt_trace(MOD_TST, "track_sensor_bma250_interrput_configuration  reg H");
    EINT_Mask(MOTION_SENSOR_EINT_NO);   
    EINT_Registration(MOTION_SENSOR_EINT_NO, KAL_TRUE, ACT_HIGH,track_sensor_bma250_eint_hisr, KAL_TRUE);
    EINT_Set_Sensitivity(MOTION_SENSOR_EINT_NO, LEVEL_SENSITIVE);
    EINT_SW_Debounce_Modify(MOTION_SENSOR_EINT_NO,SENSOR_BMA250_SW_DEBOUNCE_TIME);
    EINT_UnMask(MOTION_SENSOR_EINT_NO);   
    OTA_LOGD(L_DRV,L_V6,"%d",MOTION_SENSOR_EINT_NO);
    if (!OTA_track_is_timer_run(MOTION_SENSOR_DATA_TIMER_ID))
    {
        OTA_tr_start_timer(MOTION_SENSOR_DATA_TIMER_ID, 10000, track_sensor_bma250_data_self_test);
    }
}


/******************************************************************************
 *  Function    -  track_sensor_bma250_eint_hisr
 * 
 *  Purpose     -  震动高电平响应
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 07-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_bma250_eint_hisr(void)
{
    kal_uint32 savedMask;

    if(OTA_track_sensor_config_data->sensor_callback!=NULL)
    {
        OTA_track_drv_sensor_interrupt_send_msg();
    }
    //kal_prompt_trace(MOD_TST, "track_sensor_bma250_eint_hisr sensor bma250/E 震动 "); 
}


/******************************************************************************
 *  Function    -  track_get_sensor_bma250_id
 * 
 *  Purpose     -  读取sensor ID
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 21-10-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_get_sensor_bma250_id(void)
{
    return bma250_chip_id;
}


/******************************************************************************
 *  Function    -  track_sensor_bma250_on
 * 
 *  Purpose     -  开启sensor 检测
 * 
 *  Description -  motion_threshold  [in] : sensor 检测灵敏度 
 *                       FuncPtr  [in] : sensor 触发回调函数
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_bma250_on(kal_uint8 threshold , FuncPtr callback)
{
    kal_prompt_trace(MOD_TST, "track_sensor_bma250_on threshold=%d", threshold);
    //kal_prompt_trace(MOD_TST, "track_sensor_bma250_on SCK:%d,SDA:%d,EINT:%d",ACC_SENSOR_SCK,ACC_SENSOR_SDA,MOTION_SENSOR_EINT_NO);
    //kal_prompt_trace(MOD_TST,"delay short:%d,long:%d,clk_num,mcu_CLK_HZ:%d",
    //                                        delay_short,delay_long,INSTRUCTION_CLK_NUM,MCU_CLK_HZ);

    if((threshold <= 0) || (callback == NULL))
    {
        return;
    }

    OTA_track_sensor_config_data->sensor_threshold = threshold;
    OTA_track_sensor_config_data->sensor_callback = callback;

    sensor_bma250_init_with_interrupt();
}

/******************************************************************************
 *  Function    -  track_sensor_bma250_off
 * 
 *  Purpose     -  关闭sensor 检测
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_bma250_off(void)
{
    EINT_Mask(MOTION_SENSOR_EINT_NO);   //wq20150205

    OTA_tr_stop_timer(MOTION_SENSOR_DATA_TIMER_ID);
    OTA_tr_stop_timer(MOTION_SENSOR_RESET_TIMER_ID);    
    acc_sensor_pwr_down();
    
    //kal_prompt_trace(MOD_TST, "track_sensor_bma250_off threshold=%d");

}

/******************************************************************************
 *  Function    -  track_sensor_bma250_type_check
 * 
 *  Purpose     -  是否为BMA250/E
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 26-02-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_sensor_bma250_type_check(void)
{
    GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);
    GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);

    bma250_init(&t_bma250);
    /*顺便初始化结构体指针，避免后续直接操作跑飞重启 --   chengjun  2017-05-15*/
            
    if (t_bma250.chip_id==0x03) //BMA250
    {
        return 1;
    }
    else if (t_bma250.chip_id==0xF9) //BMA250E
    {
        return 2;
    }
    else if (t_bma250.chip_id==0xFA) //BMA253
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

#endif /* __TRACK_SENSOR__ */

#endif /* __BOSCH_BMA250__ */
