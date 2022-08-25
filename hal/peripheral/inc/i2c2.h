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
 *   sccb_v2.h
 *
 *
 * Description:
 * ------------
 *   SCCB/I2C V2 Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __I2C2_H__
#define __I2C2_H__
#if defined(DRV_I2C_DUAL_I2C)
#include "i2c.h"


//I2C_18V_base
typedef enum
{
	I2C_CONTROLLER_1 = 0x11,
	I2C_CONTROLLER_2 = 0x22	
}I2C_CONTROLLER_T;

/* Register Definitions */
#define REG_I2C2_DATA_PORT             (I2C_18V_base + 0x00)
#define REG_I2C2_SLAVE_ADDR            (I2C_18V_base + 0x04)
#define REG_I2C2_INT_MASK              (I2C_18V_base + 0x08)
#define REG_I2C2_INT_STA               (I2C_18V_base + 0x0c)
#define REG_I2C2_CONTROL               (I2C_18V_base + 0x10)
#define REG_I2C2_TRANSFER_LEN          (I2C_18V_base + 0x14)
#define REG_I2C2_TRANSAC_LEN           (I2C_18V_base + 0x18)
#define REG_I2C2_DELAY_LEN             (I2C_18V_base + 0x1c)
#define REG_I2C2_TIMING                (I2C_18V_base + 0x20)
#define REG_I2C2_START                 (I2C_18V_base + 0x24)
#define REG_I2C2_FIFO_STAT             (I2C_18V_base + 0x30)
#define REG_I2C2_FIFO_THRESH           (I2C_18V_base + 0x34)
#define REG_I2C2_FIFO_ADDR_CLR         (I2C_18V_base + 0x38)
#define REG_I2C2_IO_CONFIG             (I2C_18V_base + 0x40)
#define REG_I2C2_MULTI_MASTER          (I2C_18V_base + 0x44)
#define REG_I2C2_HS_MODE               (I2C_18V_base + 0x48)
#define REG_I2C2_SOFTRESET             (I2C_18V_base + 0x50)
#define REG_I2C2_TRANSFER_LEN_AUX      (I2C_18V_base + 0x6C)     ///new from MT6256E2
#define REG_I2C2_HW_Version            (I2C_18V_base + 0x78)
#define REG_I2C2_DBG_STA               (I2C_18V_base + 0x64)     //only for debug
#define REG_I2C2_TIMEOUT_TIMING        (I2C_18V_base + 0x74)     //timeout timing reg

/* Register masks */
#define I2C2_1_BIT_MASK                0x01
#define I2C2_3_BIT_MASK                0x07
#define I2C2_4_BIT_MASK                0x0f
#define I2C2_6_BIT_MASK                0x3f
#define I2C2_8_BIT_MASK                0xff
#define I2C2_16_BIT_MASK               0xffff


#define I2C2_AUX_LEN_MASK              0x1f00
#define I2C2_AUX_LEN_SHIFT             8

#define I2C2_SAMPLE_CNT_DIV_MASK       0x0700
#define I2C2_SAMPLE_CNT_DIV_SHIFT      8
#define I2C2_DATA_READ_TIME_MASK       0x7000
#define I2C2_DATA_READ_TIME_SHIFT      12


#define I2C2_CTL_RS_STOP_BIT           0x02
#define I2C2_CTL_DMA_EN_BIT            0x04
#define I2C2_CTL_CLK_EXT_EN_BIT        0x08
#define I2C2_CTL_DIR_CHANGE_BIT        0x10
#define I2C2_CTL_ACK_ERR_DET_BIT       0x20
#define I2C2_CTL_TRANSFER_LEN_CHG_BIT  0x40

#define I2C2_DATA_READ_ADJ_BIT         0x8000

#define I2C2_SCL_MODE_BIT              0x01
#define I2C2_SDA_MODE_BIT              0x02
#define I2C2_BUS_DETECT_EN_BIT         0x04

#define I2C2_ARBITRATION_BIT           0x01
#define I2C2_CLOCK_SYNC_BIT            0x02
#define I2C2_BUS_BUSY_DET_BIT          0x04

#define I2C2_HS_EN_BIT                 0x01
#define I2C2_HS_NACK_ERR_DET_EN_BIT    0x02
#define I2C2_HS_MASTER_CODE_MASK       0x0070
#define I2C2_HS_MASTER_CODE_SHIFT      4
#define I2C2_HS_STEP_CNT_DIV_MASK      0x0700
#define I2C2_HS_STEP_CNT_DIV_SHIFT     8
#define I2C2_HS_SAMPLE_CNT_DIV_MASK    0x7000
#define I2C2_HS_SAMPLE_CNT_DIV_SHIFT   12

/****** SW definitions******/
#define I2C2_READ_BIT            0x01
#define I2C2_WRITE_BIT           0x00

#define I2C2_TRANSAC_COMPLETE    0x01
#define I2C2_TRANSAC_ACK_ERR     0x02
#define I2C2_HS_NACK_ERR         0x04
#define I2C2_TIMEOUT         	0x10

/* Register Settings */
#define SET_I2C2_SLAVE_ADDRESS(n,rw)       do{DRV_I2C_SetData16(REG_I2C2_SLAVE_ADDR, I2C2_8_BIT_MASK, (((n>>1)<<1) + rw));} while(0);

#define DISABLE_I2C2_INT                   do{DRV_I2C_WriteReg16(REG_I2C2_INT_MASK, 0);} while(0);
#define ENABLE_I2C2_INT                    do{DRV_I2C_WriteReg16(REG_I2C2_INT_MASK,I2C2_1_BIT_MASK);} while(0);

#define CLEAR_I2C2_STA                     do{DRV_I2C_WriteReg16(REG_I2C2_INT_STA, I2C2_4_BIT_MASK);} while(0);

//#define SET_I2C_FAST_SPEED_MODE	REG_I2C_CONTROL &= ~I2C_CTL_MODE_BIT;
//#define SET_I2C_HIGH_SPEED_MODE	REG_I2C_CONTROL |= I2C_CTL_MODE_BIT;

#define SET_I2C2_ST_BETWEEN_TRANSFER       do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_RS_STOP_BIT);} while(0);
#define SET_I2C2_RS_BETWEEN_TRANSFER       do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_RS_STOP_BIT);} while(0);
#define ENABLE_I2C2_DMA_TRANSFER           do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_DMA_EN_BIT);} while(0);
#define ENABLE_I2C2_CLOCK_EXTENSION        do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_CLK_EXT_EN_BIT);} while(0);
#define ENABLE_I2C2_DIR_CHANGE             do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_DIR_CHANGE_BIT);} while(0);
#define ENABLE_I2C2_ACK_ERR_DET            do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_ACK_ERR_DET_BIT);} while(0);
#define ENABLE_I2C2_TRANSFER_LEN_CHG       do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define ENABLE_I2C2_BUS_BUSY_RESET         do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, 0x80);} while(0);
#define ENABLE_I2C2_TIMEOUT                do{DRV_I2C_SetBits16(REG_I2C2_CONTROL, I2C2_TIMEOUT);} while(0); 

#define DISABLE_I2C2_DMA_TRANSFER          do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_DMA_EN_BIT);} while(0);
#define DISABLE_I2C2_CLOCK_EXTENSION       do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_CLK_EXT_EN_BIT);} while(0);
#define DISABLE_I2C2_DIR_CHANGE            do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_DIR_CHANGE_BIT);} while(0);
#define DISABLE_I2C2_ACK_ERR_DET           do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_ACK_ERR_DET_BIT);} while(0);
#define DISABLE_I2C2_TRANSFER_LEN_CHG      do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define DISABLE_I2C2_BUS_BUSY_RESET        do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, 0x80);} while(0);
#define DISABLE_I2C2_TIMEOUT               do{DRV_I2C_ClearBits16(REG_I2C2_CONTROL, I2C2_TIMEOUT);} while(0); 

#define SET_I2C2_TRANSFER_LENGTH(n)        do{DRV_I2C_SetData16(REG_I2C2_TRANSFER_LEN, I2C2_16_BIT_MASK, (n));} while(0);
#define SET_I2C2_AUX_TRANSFER_LENGTH(n)    do{DRV_I2C_SetData16(REG_I2C2_TRANSFER_LEN_AUX, I2C2_16_BIT_MASK, (n));} while(0);

#define SET_I2C2_TRANSACTION_LENGTH(n)     do{DRV_I2C_SetData16(REG_I2C2_TRANSAC_LEN, I2C2_8_BIT_MASK, (n));} while(0);
#define SET_I2C2_DELAY_LENGTH(n)           do{DRV_I2C_SetData16(REG_I2C2_DELAY_LEN, I2C2_8_BIT_MASK, (n));} while(0);

#define SET_I2C2_STEP_CNT_DIV(n)           do{DRV_I2C_SetData16(REG_I2C2_TIMING, I2C2_6_BIT_MASK, (n));} while(0);
#define SET_I2C2_SAMPLE_CNT_DIV(n)         do{DRV_I2C_SetData16(REG_I2C2_TIMING, I2C2_SAMPLE_CNT_DIV_MASK, ((n)<<I2C2_SAMPLE_CNT_DIV_SHIFT));} while(0);
#define SET_I2C2_DATA_READ_TIME(n)         do{DRV_I2C_SetData16(REG_I2C2_TIMING, I2C2_DATA_READ_TIME_MASK, ((n)<<I2C2_DATA_READ_TIME_SHIFT));} while(0);
#define ENABLE_I2C2_DATA_READ_ADJ          do{DRV_I2C_SetBits16(REG_I2C2_TIMING, I2C2_DATA_READ_ADJ_BIT);} while(0);
#define DISABLE_I2C2_DATA_READ_ADJ         do{DRV_I2C_ClearBits16(REG_I2C2_TIMING, I2C2_DATA_READ_ADJ_BIT);} while(0);

#define START_I2C2_TRANSACTION             do{DRV_I2C_WriteReg16(REG_I2C2_START, 0x01);} while(0);



#define CLEAR_I2C2_FIFO                    do{DRV_I2C_WriteReg16(REG_I2C2_FIFO_ADDR_CLR, 0x01);} while(0);

#define SET_I2C2_SCL_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C2_IO_CONFIG, I2C2_SCL_MODE_BIT);} while(0);
#define SET_I2C2_SCL_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C2_IO_CONFIG, I2C2_SCL_MODE_BIT);} while(0);
#define SET_I2C2_SDA_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C2_IO_CONFIG, I2C2_SDA_MODE_BIT);} while(0);
#define SET_I2C2_SDA_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C2_IO_CONFIG, I2C2_SDA_MODE_BIT);} while(0);
#define ENABLE_I2C2_BUS_DETECT             do{DRV_I2C_SetBits16(REG_I2C2_IO_CONFIG, I2C2_BUS_DETECT_EN_BIT);} while(0);
#define DISABLE_I2C2_BUS_DETECT            do{DRV_I2C_ClearBits16(REG_I2C2_IO_CONFIG, I2C2_BUS_DETECT_EN_BIT);} while(0);

#define ENABLE_I2C2_CLOCK_SYNC             do{DRV_I2C_SetBits16(REG_I2C2_MULTI_MASTER, I2C2_ARBITRATION_BIT);} while(0);
#define ENABLE_I2C2_BUS_BUSY_DET           do{DRV_I2C_SetBits16(REG_I2C2_MULTI_MASTER, I2C2_BUS_BUSY_DET_BIT);} while(0);
#define DISABLE_I2C2_CLOCK_SYNC            do{DRV_I2C_ClearBits16(REG_I2C2_MULTI_MASTER, I2C2_ARBITRATION_BIT);} while(0);
#define DISABLE_I2C2_BUS_BUSY_DET          do{DRV_I2C_ClearBits16(REG_I2C2_MULTI_MASTER, I2C2_BUS_BUSY_DET_BIT);} while(0);

#define SET_I2C2_HIGH_SPEED_MODE_800KB     do{DRV_I2C_WriteReg16(REG_I2C2_HS_MODE, 0x0703);} while(0);
#define SET_I2C2_HIGH_SPEED_MODE_1000KB    do{DRV_I2C_WriteReg16(REG_I2C2_HS_MODE, 0x0503);} while(0);

#define SET_I2C2_FAST_MODE                 do{DRV_I2C_ClearBits16(REG_I2C2_HS_MODE, I2C2_HS_EN_BIT);} while(0);
#define SET_I2C2_HS_MODE                   do{DRV_I2C_SetBits16(REG_I2C2_HS_MODE, I2C2_HS_EN_BIT);} while(0);
#define ENABLE_I2C2_NAKERR_DET             do{DRV_I2C_SetBits16(REG_I2C2_HS_MODE, I2C2_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define DISABLE_I2C2_NAKERR_DET            do{DRV_I2C_ClearBits16(REG_I2C2_HS_MODE, I2C2_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define SET_I2C2_HS_MASTER_CODE(n)         do{DRV_I2C_SetData16(REG_I2C2_HS_MODE, I2C2_HS_MASTER_CODE_MASK, ((n)<<I2C2_HS_MASTER_CODE_SHIFT));} while(0);

#define SET_I2C2_HS_STEP_CNT_DIV(n)        do{DRV_I2C_SetData16(REG_I2C2_HS_MODE, I2C2_HS_STEP_CNT_DIV_MASK, ((n)<<I2C2_HS_STEP_CNT_DIV_SHIFT));} while(0);
#define SET_I2C2_HS_SAMPLE_CNT_DIV(n)      do{DRV_I2C_SetData16(REG_I2C2_HS_MODE, I2C2_HS_SAMPLE_CNT_DIV_MASK, ((n)<<I2C2_HS_SAMPLE_CNT_DIV_SHIFT));} while(0);

#define RESET_I2C2                         do{DRV_I2C_WriteReg16(REG_I2C2_SOFTRESET, 0x01);} while(0);


#define I2C2_POWER_OFF() do{PDN_SET(PDN_I2C_18V);}while(0);	/* Power off I2C */
#define I2C2_POWER_ON()	do{PDN_CLR(PDN_I2C_18V);}while(0);	/* Power on I2C */	

void dcl_i2c2_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num);
void dcl_i2c2_lisr(void);
void dcl_i2c_lisr(void);
void i2c2_init(void);
void i2c_init(void);
void dcl_dual_i2c_hw_cfg (kal_uint8 controller,DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num);
void dcl_dual_i2c_status_handler(kal_uint8 current_controller,i2c_status_struct *i2c_status,kal_uint32 sta);
kal_uint32 dcl_dual_i2c_wait_transaction_complete_and_lock(i2c_status_struct *i2c_status,DCL_I2C_OWNER owner);
void dcl_dual_i2c_wait_transaction_complete(kal_uint8 current_controller,i2c_status_struct *i2c_status,kal_uint32 savedMask);

#endif
#endif // #ifndef __I2C_H__

