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
 *    dcl_sim.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines structures and functions for SIM DCL interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT

#ifndef __DCL_SIM_H_STRUCT__
#define __DCL_SIM_H_STRUCT__

/*RHR*/
#include "kal_non_specific_general_types.h"
#include "dcl.h"
/*RHR*/

#define	DCL_SIM_MAX_INTERFACE	5

/*********************************************************************************************************
*followings we defines the structure used by DCL user, this is prevent DCL user from include invividual moudles' header file.
**********************************************************************************************************/
typedef DCL_UINT16 DCL_SIM_STATUS_WORD;

typedef enum
{
	DCL_ME_UNKNOW =0,
	DCL_ME_18V_30V,
	DCL_ME_30V_ONLY,
	DCL_ME_18V_ONLY
} DCL_SIM_ENV;

typedef enum{
	DCL_USIM_NO_ERROR = 0,

	/*expected status*/
	DCL_USIM_WAITING_EVENT = 1,	/* initial wait event status */
	DCL_USIM_BLOCK_REC = 2,		/* successfully received a complete block */
	DCL_USIM_POWER_OFF = 3,		/* successfully powered off */
	DCL_USIM_ATR_REC = 4,			/* successfully reveived all ATR */
	DCL_USIM_S_BLOCK_REC = 5,		/* successfully reveived S RESP */

	/* error status */
	DCL_USIM_NO_INSERT = -1,
	DCL_USIM_VOLT_NOT_SUPPORT = -2,
	DCL_USIM_NO_ATR = -3,
	DCL_USIM_TS_INVALID = -4,
	DCL_USIM_ATR_ERR = -5,
	DCL_USIM_INVALID_ATR = -6,
	DCL_USIM_PTS_FAIL = -7,
	DCL_USIM_RX_INVALID = -8,	/* EDC error or parity error */
	DCL_USIM_BWT_TIMEOUT = -9,
	DCL_USIM_DATA_ABORT = -10,
	DCL_USIM_DEACTIVATED = -11,
	DCL_USIM_S_BLOCK_FAIL = -12,
	DCL_USIM_INVALID_WRST = -13,
	DCL_USIM_GPT_TIMEOUT = -14
}DCL_SIM_STATUS;

typedef enum{
	DCL_UNKNOWN_POWER_CLASS = 0,
	DCL_CLASS_A_50V = 1,
	DCL_CLASS_B_30V = 2,
	DCL_CLASS_AB 	= 3,
	DCL_CLASS_C_18V = 4,
	DCL_ClASS_BC		= 6,
	DCL_CLASS_ABC	= 7
}DCL_SIM_POWER;

typedef DCL_UINT32 DCL_SIM_HW_CB;

typedef enum
{
	DCL_SIM_PROTOCOL,
	DCL_USIM_PROTOCOL
}DCL_SIM_APP_PROTOCOL;



typedef enum
{
	DCL_T0_PROTOCOL,
	DCL_T1_PROTOCOL,
	DCL_UNKNOWN_PROTOCOL
}DCL_SIM_PHY_PROTOCOL;

typedef enum{
	DCL_CLOCK_STOP_NOT_SUPPORT 	= 0x0,
	DCL_CLOCK_STOP_LOW 			= 0x40,
	DCL_CLOCK_STOP_HIGH 			= 0x80,
	DCL_CLOCK_STOP_ANY				= 0xc0,
	DCL_CLOCK_STOP_MSK				= 0xc0,
	DCL_CLOCK_STOP_UNKONW			= 0x0f
}DCL_SIM_CLK_STOP;

typedef enum{
	DCL_SPEED_372,
	DCL_SPEED_64,
	DCL_SPEED_32,
	DCL_SPEED_16
}DCL_SIM_CARD_SPEED;

typedef struct{
	DCL_SIM_POWER power;
	DCL_SIM_CARD_SPEED speed;
	DCL_SIM_CLK_STOP clock_stop;
	DCL_SIM_APP_PROTOCOL app_proto;
	DCL_SIM_PHY_PROTOCOL phy_proto;
	kal_bool T0_support;	// if T0 is supported
	kal_bool T1_support;	// if T1 is supported
	kal_uint8 hist_index; // index to the historical char of ATR
	kal_uint8 *ATR;
       kal_bool TAiExist; //if the first TA for T=15 is existed
    kal_uint8 ATR_length;			// length to the ATR_data
    kal_bool isSW6263; // query if status word 0x62xx 0x63xx happen
}DCL_SIM_INFO;

/*******************************************************************************
 * driver function tables exposed to DCL
 *******************************************************************************/
/*here are type definition for functions*/
/*dcl add new api : 2. define function type*/
typedef DCL_SIM_STATUS (* DCL_SIM_RST)(DCL_SIM_POWER ExpectVolt, DCL_SIM_POWER *ResultVolt, kal_bool warm, DCL_SIM_HW_CB handle);
typedef DCL_SIM_STATUS_WORD (* DCL_SIM_CMD)(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, DCL_SIM_HW_CB handle);
typedef void (* DCL_SIM_PWOFF)(DCL_SIM_HW_CB handle);
typedef void (* DCL_SIM_GET_CARD_INFO)(DCL_SIM_INFO *info, DCL_SIM_HW_CB handle);
typedef void (* DCL_SIM_SET_MAX_SPEED)(DCL_SIM_CARD_SPEED speed, DCL_SIM_HW_CB handle);
typedef void (* DCL_SIM_SET_PREFER_PROTOCOL)(DCL_SIM_PHY_PROTOCOL T, DCL_SIM_HW_CB handle);
typedef kal_bool (* DCL_SIM_SET_CLK_STOP_MODE)(DCL_SIM_CLK_STOP mode, DCL_SIM_HW_CB handle);
typedef void (* DCL_SIM_TOUT_TEST)(kal_uint32 toutValue, DCL_SIM_HW_CB handle);
typedef kal_uint32 (* DCL_SIM_ASSIGN_LOGICAL)(kal_uint32 logicalNumber);
typedef DCL_SIM_CARD_SPEED (*DCL_SIM_GAT_CARD_SPEED)(DCL_SIM_HW_CB handle);
typedef DCL_BOOL (*DCL_SIM_QUERY_GET_9000_WHEN_SELECT)(DCL_SIM_HW_CB handle);
/* For sim hot plug callback function */
typedef void (*DCL_SIM_PLUG_OUT_CALLBACK)(kal_uint32 simIf);
typedef void (*DCL_SIM_PLUG_IN_CALLBACK)(kal_uint32 simIf);
/*dcl add new api : 3. add to funtion table type*/
typedef struct
{
	DCL_SIM_RST rst;
	DCL_SIM_CMD cmd;
	DCL_SIM_PWOFF pwOff;
	DCL_SIM_GET_CARD_INFO getCardInfo;
	DCL_SIM_SET_MAX_SPEED setSpeed;
	DCL_SIM_SET_PREFER_PROTOCOL setPreferT;
	DCL_SIM_SET_CLK_STOP_MODE setClockStopMode;
	DCL_SIM_TOUT_TEST toutTest;
	DCL_SIM_ASSIGN_LOGICAL assignLogical;
	DCL_SIM_GAT_CARD_SPEED getCardSpeed;
	DCL_SIM_QUERY_GET_9000_WHEN_SELECT query9000WhenSelect;
}DCL_SIMDriver_t;

typedef enum
{
	SIM_CONFIG_AP_TYPE_PHONE1,
	SIM_CONFIG_AP_TYPE_PHONE2,
	SIM_CONFIG_AP_TYPE_CMMB_SMD,
	SIM_CONFIG_AP_TYPE_PHONE3,
	SIM_CONFIG_AP_TYPE_PHONE4
} DCL_SIM_CONFIG_AP_TYPE;

typedef struct
{
	DCL_SIM_CONFIG_AP_TYPE	apType;
    DCL_SIM_PLUG_IN_CALLBACK hotPlugInCb;
	DCL_SIM_PLUG_OUT_CALLBACK hotPlugOutCb;
} SIM_CONFIG_T;

#define SIM_CONFIGS    \
   SIM_CONFIG_T   rSimConfig;

/*******************************************************************************
 * DCL_CTRL_CMD for SIM
 *******************************************************************************/
 /*dcl add new api : 4. add to DCL_CTRL_CMD enum*/
#define SIM_CMDS    \
   SIM_CTRL_CMD_BASE, \
   SIM_CTRL_CMD_RST = 0, \
   SIM_CTRL_CMD_CMD, \
   SIM_CTRL_CMD_PWOFF, \
   SIM_CTRL_CMD_GET_CARD_INFO, \
   SIM_CTRL_CMD_SET_SPEED,  \
   SIM_CTRL_CMD_SET_PREFER_PROTOCOL, \
   SIM_CTRL_CMD_SET_CLK_STOP_MODE, \
   SIM_CTRL_CMD_TOUT_TEST, \
   SIM_CTRL_CMD_GET_SPEED, \
   SIM_CTRL_CMD_QUERY_9000_ON_SELECT, \
   SIM_CTRL_CMD_SET_SLT_RLT, \
   SIM_CTRL_CMD_MAX_VALUE, \
   SIM_CTRL_CMD_DUMMY_END = SIM_CTRL_CMD_BASE + SIM_CTRL_CMD_MAX_VALUE,



/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
/* FOR SIM_CTRL_CMD_RST control command. */
typedef struct
{
	DCL_SIM_POWER ExpectVolt;
	DCL_SIM_POWER *ResultVolt;
	kal_bool warm;
	DCL_SIM_STATUS rstResult;
} SIM_CTRL_RST_T;

/* FOR SIM_CTRL_CMD_CMD control command. */
typedef struct
{
	kal_uint8  *txData;
	kal_uint32  *txSize;
	kal_uint8  *rxData;
	kal_uint32  *rxSize;
	kal_uint16 *statusWord;
} SIM_CTRL_CMD_T;

/*dcl add new api : 4. new ctrl data type*/

/* FOR SIM_CTRL_CMD_GET_CARD_INFO control command. */
typedef struct
{
	DCL_SIM_INFO *info;
} SIM_CTRL_GET_CARD_INFO_T;

/* FOR SIM_CTRL_CMD_SET_SPEED control command. */
typedef struct
{
	DCL_SIM_CARD_SPEED speed;
} SIM_CTRL_SET_MAX_SPEED_T;

/* FOR SIM_CTRL_CMD_SET_PREFER_PROTOCOL control command. */
typedef struct
{
	DCL_SIM_PHY_PROTOCOL T;
} SIM_CTRL_SET_PREFER_PROTOCOL_T;

/* FOR SIM_CTRL_CMD_SET_CLK_STOP_MODE control command. */
typedef struct
{
	DCL_SIM_CLK_STOP mode;
} SIM_CTRL_SET_CLK_STOP_MODE_T;

/* FOR SIM_CTRL_CMD_TOUT_TEST control command. */
typedef struct
{
	DCL_UINT32 toutValue;
} SIM_CTRL_TOUT_TEST_T;

/* FOR SIM_CTRL_CMD_GET_SPEED control command. */
typedef struct
{
	DCL_SIM_CARD_SPEED *speed; //return the card's speed to SIM task
} SIM_CTRL_GET_SPEED_T;

/* FOR SIM_CTRL_CMD_QUERY_9000_ON_SELECT control command. */
typedef struct
{
	DCL_BOOL *got9000; //return the information whether we encounter 9000 in select command
} SIM_CTRL_QUERY_9000_T;

/* FOR SIM_SLT_SET_RLT control command. */
typedef struct
{
	DCL_BOOL rlt; 
} SIM_CTRL_SET_SLT_RLT_T;

/*dcl add new api : 5. add to DCL_CTRL_DATA enum*/
#define SIM_CTRLS \
   SIM_CTRL_RST_T		rSIMRst; \
   SIM_CTRL_CMD_T		rSIMCmd; \
   SIM_CTRL_GET_CARD_INFO_T	rSIMGetCardInfo;\
   SIM_CTRL_SET_MAX_SPEED_T	rSIMSetMaxSpeed; \
   SIM_CTRL_SET_PREFER_PROTOCOL_T	rSIMSetPreferProtocol; \
   SIM_CTRL_SET_CLK_STOP_MODE_T		rSIMSetClkStopMode; \
   SIM_CTRL_TOUT_TEST_T		rSIMToutTest; \
   SIM_CTRL_GET_SPEED_T		rSIMGetSpeed; \
   SIM_CTRL_QUERY_9000_T		rSIMQuery9000; \
   SIM_CTRL_SET_SLT_RLT_T		rSIMSetSltRlt;   
#endif /*__DCL_SIM_H_STRUCT__*/

#endif /*DCL_DEFINITION_STRUCT*/

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_SIM_H_PROTOTYPE__
#define __DCL_SIM_H_PROTOTYPE__
DCL_HANDLE DclSIM_Open(DCL_DEV dev, DCL_FLAGS flags);
DCL_STATUS DclSIM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
DCL_STATUS DclSIM_Close(DCL_HANDLE handle);
DCL_STATUS DclSIM_Initialize(void);
#endif /*__DCL_SIM_H_PROTOTYPE__*/
#endif //DCL_DEFINITION_PROTOTYPE

