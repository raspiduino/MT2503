/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   pxs_cm3623.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of CM3623 proximity sensor driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__PXS_CM3623__)
#include "eint.h"
#include "intrCtrl.h"


#define CM3623_POWER_ON_DELAY  1   // Unit: 32k tick


#define CM3623_INTR_SENE_TYPE   LEVEL_SENSITIVE     // LEVEL_SENSITIVE, EDGE_SENSITIVE

#define CM3623_INTR_ACTIVE_LEVEL   LEVEL_LOW   // LEVEL_LOW, LEVEL_HIGH

#define CM3623_EINT_DEBOUNCE    0  // Uinit: 10ms

#define CM3623_EM_POLLING_PERIOD    100  // Unit: 1ms


#define INVALID_INTR_ADDR   0xFF  // Indicate there is no intr event occur

//#define ALS_CMD_ADDR        0x20
//#define ALS_DATA_MSB_ADDR   0x21
//#define ALS_DATA_LSB_ADDR   0x23
//#define PS_CMD_ADDR         0xB0
//#define PS_THD_ADDR         0xB2
//#define PS_DATA_ADDR        0xB1
//#define PS_INIT_ADDR        0x22
//#define ARA_ADDR            0x19

#define ALS_CMD_ADDR        0x90
#define ALS_DATA_MSB_ADDR   0x91
#define ALS_DATA_LSB_ADDR   0x93
#define PS_CMD_ADDR         0xF0
#define PS_THD_ADDR         0xF2
#define PS_DATA_ADDR        0xF1
#define PS_INIT_ADDR        0x92
#define ARA_ADDR            0x19



// PS_CMD_ADDR
  #define SD_PS_MASK        0x01
  #define SD_PS_SHIFT       0
  #define INT_PS_MASK       0x04
  #define INT_PS_SHIFT      2
  #define INT_ALS_MASK      0x08
  #define INT_ALS_SHIFT     3
  #define IT_PS_MASK        0x30
  #define IT_PS_SHIFT       4
  #define DR_PS_MASK        0xC0
  #define DR_PS_SHIFT       6

// PS_THD_ADDR
  #define THD_PS_MASK       0xFF
  #define THD_PS_SHIFT      0

// PS_DATA_ADDR
  #define DATA_PS_MASK      0xFF
  #define DATA_PS_SHIFT     0

// PS_INIT_ADDR
  #define INT_INIT_MASK        0x10
  #define INT_INIT_SHIFT       4
  #define PS_HILO_INIT_MASK    0x20
  #define PS_HILO_INIT_SHIFT   5




typedef enum
{
	ALS_CMD = 0,
	ALS_DATA_MSB,
	ALS_DATA_LSB,
	PS_CMD,
	PS_DATA,
	PS_THD,
	INIT,
	ARA,
	CM3623_REG_NUM
}CM3623_REG_ENUM;

typedef struct
{
	kal_uint8 reg;
	kal_uint8 val;
} CM3623_REG_VAL_STRUCT;

extern CM3623_REG_VAL_STRUCT cm3623_reg_val[CM3623_REG_NUM];


#define COMM_RETRY_TIMES    1

extern kal_bool cm3623_comm_init(void);
extern kal_bool cm3623_reg_write(kal_uint8 addr, kal_uint8 val);
extern kal_bool cm3623_reg_read(kal_uint8 addr, kal_uint8 *val);




#endif // #if defined(__PXS_CM3623__)

