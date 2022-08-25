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
 *    FSL_data.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * MTK70814
 * add MOTION_SENSOR_BACK_90 for luffy76 20110210
 *
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DATA_H
#define _DATA_H

//#define ACC_DEBUG 0

#define MS_SLAVE_ADDR       0x98 //0x4C << 1 
/*MMA 7660 register List*/
#define MS_REG_XOUT  0x00
#define MS_REG_YOUT  0x01
#define MS_REG_ZOUT  0x02
#define MS_REG_TILT  0x03
#define MS_REG_SRST  0x04
#define MS_REG_SPCNT 0x05
#define MS_REG_INTSU 0x06
#define MS_REG_MODE  0x07
#define MS_REG_SR    0x08
#define MS_REG_PDET  0x09
#define MS_REG_PD    0x0a

/*Motion Sensor Mode*/
#define MS_STANDBY_MODE 0x00
#define MS_RUNNING_MODE 0x19
/*Count in Auto-Sleep Mode*/
#define MS_AS_COUNT  256

/*Auto Sleep or Auto Wake Sampling rate Status*/
#define MS_AWSRS    0x02
#define MS_AMSRS    0x01

/*Sample Rate*/
#define MS_AWM_32   0x00
#define MS_AWM_16   0x08
#define MS_AWM_8    0x10
#define MS_AWM_1    0x18

#define MS_ASM_120  0x00
#define MS_ASM_64   0x01
#define MS_ASM_32   0x02
#define MS_ASM_16   0x03
#define MS_ASM_8    0x04
#define MS_ASM_4    0x05
#define MS_ASM_2    0x06
#define MS_ASM_1    0x07

#define MS_Auto_Wake_Sample   MS_AWM_32
#define MS_Auto_Sleep_Sample  MS_ASM_64

/* acceleration 6-Bits,+/-1.5g */
#define MMA7660_RANGE       3	//+/-1.5g
#define MMA7660_RESOLUTION  6	//8-Bits


/*acceleration*/
#define ACC_0G_X      (31*2)
#define ACC_1G_X      (52*2)
#define ACC_MINUS1G_X (10*2)
#define ACC_0G_Y      (31*2)    
#define ACC_1G_Y      (52*2)
#define ACC_MINUS1G_Y (10*2)
#define ACC_0G_Z      (31*2)       
#define ACC_1G_Z      (52*2)
#define ACC_MINUS1G_Z (10*2)

//#define MS_POWER_BY_VBOOST

//extern const char gpio_ms_i2c_clk_pin;
//extern const char gpio_ms_i2c_data_pin;


//#define Motion_Sensor_Clock_Pin     gpio_ms_i2c_clk_pin               //clk pin
//#define Motion_Sensor_Data_Pin      gpio_ms_i2c_data_pin              //data pin


//#define FSL_CLK_PIN  Motion_Sensor_Clock_Pin                   //clk pin
//#define FSL_DATA_PIN Motion_Sensor_Data_Pin                    //data pin

#ifdef MS_POWER_BY_VBOOST
     extern const char gpio_ms_i2c_cs_pin;
	   #define Motion_Sensor_Power_Pin     gpio_ms_i2c_cs_pin                //power pin
#endif

#endif
