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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * fm_rds.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM RDS defined structure
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef FM_RDS_H
 #define FM_RDS_H
#include "kal_general_types.h"

#define   RDS_GDBK_IND_A	(0x08)	
#define   RDS_GDBK_IND_B	(0x04)	
#define   RDS_GDBK_IND_C	(0x02)	
#define   RDS_GDBK_IND_D	(0x01)	
#define	RDS_READ_DELAY		(0x80)
#define FMR_RDS_FULL_SUPPORT 0/*0: only support PS,RT,AF,AF list, TAON event and TP/TA/textAB flag,group 1/4 disabled*/ 

typedef struct
{
   kal_bool TP[2];
   kal_bool TA;
#if FMR_RDS_FULL_SUPPORT  
   kal_bool Music;
   kal_bool Stereo;
   kal_bool Artificial_Head;
   kal_bool Compressed;
   kal_bool Dynamic_PTY;
#endif   
   kal_bool Text_AB;
   kal_uint16 flag_status;
}RDSFlag_Struct;

#if FMR_RDS_FULL_SUPPORT  
typedef struct
{
   kal_uint16 Month;
   kal_uint16 Day;
   kal_uint16 Year;
   kal_uint16 Hour;
   kal_uint16 Minute;
   kal_bool Local_Time_offset_signbit;
   kal_uint8 Local_Time_offset_half_hour;
}CT_Struct;
#endif
typedef struct
{
   kal_int16 AF[2][26];
   kal_uint8 Addr_Cnt;
   kal_bool isMethod_A;
   kal_bool isAFNum_Get;
}AF_Info;

typedef struct
{
   //kal_uint8 PSCodeNum[2];/*newly spec phase out code table*/
   kal_uint8 PS[3][8];
   kal_uint8 Addr_Cnt;
}PS_Info;

typedef struct
{
   //kal_uint8 RTCodeNum[2];/*newly spec phase out code table*/
   kal_uint8 TextData[3][64];
   kal_bool GetLength;
   kal_bool isRTDisplay;
   kal_uint8 TextLength;
   kal_bool isTypeA;
   kal_uint8 BufCnt;
   kal_uint16 Addr_Cnt;
}RT_Info;

typedef struct
{
#if FMR_RDS_FULL_SUPPORT  
	CT_Struct CT;
	kal_uint16 PI;
	kal_uint8 PTY;
	kal_uint8 Radio_Page_Code;
	kal_uint16 Program_Item_Number_Code;
	kal_uint8 Extend_Country_Code;
	kal_uint16 Language_Code;
	//kal_uint16 Block_Backup[32][4];
	//kal_bool EINT_Flag;
#endif
   RDSFlag_Struct RDSFlag;
   kal_bool Switch_TP;
   AF_Info AF_Data;
   AF_Info AFON_Data;
   PS_Info PS_Data;
   kal_uint8 PS_ON[8];   
   RT_Info RT_Data;
   kal_uint16 Group_Cnt[32];
   kal_bool RDS_Flag;
   kal_uint16 event_status;
} RDSData_Struct;
typedef enum {
   RDS_FLAG_IS_TP              	              = 0x0001, // Program is a traffic program
   RDS_FLAG_IS_TA                            = 0x0002, // Program currently broadcasts a traffic ann.
   RDS_FLAG_IS_MUSIC                     = 0x0004, // Program currently broadcasts music
   RDS_FLAG_IS_STEREO                  = 0x0008, // Program is transmitted in stereo
   RDS_FLAG_IS_ARTIFICIAL_HEAD = 0x0010, // Program is an artificial head recording
   RDS_FLAG_IS_COMPRESSED       = 0x0020, // Program content is compressed
   RDS_FLAG_IS_DYNAMIC_PTY       = 0x0040, // Program type can change 
   RDS_FLAG_TEXT_AB                      = 0x0080  // If this flag changes state, a new radio text 					 string begins
} RdsFlag;

typedef enum {
   RDS_EVENT_FLAGS          = 0x0001, // One of the RDS flags has changed state
   RDS_EVENT_PI_CODE        = 0x0002, // The program identification code has changed
   RDS_EVENT_PTY_CODE       = 0x0004, // The program type code has changed
   RDS_EVENT_PROGRAMNAME    = 0x0008, // The program name has changed
   RDS_EVENT_UTCDATETIME    = 0x0010, // A new UTC date/time is available
   RDS_EVENT_LOCDATETIME    = 0x0020, // A new local date/time is available
   RDS_EVENT_LAST_RADIOTEXT = 0x0040, // A radio text string was completed
   RDS_EVENT_AF                   = 0x0080, // Current Channel RF signal strength too weak, need do AF switch  
   RDS_EVENT_AF_LIST        = 0x0100, // An alternative frequency list is ready
   RDS_EVENT_AFON_LIST        = 0x0200, // An alternative frequency list is ready
   RDS_EVENT_TAON        = 0x0400,  // Other Network traffic announcement start
   RDS_EVENT_TAON_OFF        = 0x0800, // Other Network traffic announcement finished.
   RDS_EVENT_RDS        = 0x2000, // RDS Interrupt had arrived durint timer period  
   RDS_EVENT_NO_RDS        = 0x4000, // RDS Interrupt not arrived durint timer period  
   RDS_EVENT_RDS_TIMER        = 0x8000 // Timer for RDS Bler Check.
} RdsEvent;

typedef enum {
  RDS_CMD_NONE = 0,   // No command. This is usually an error.
  RDS_CMD_PI_CODE,
  RDS_CMD_PTY_CODE,
  RDS_CMD_PROGRAMNAME,
  RDS_CMD_LOCDATETIME,
  RDS_CMD_UTCDATETIME,
  RDS_CMD_LAST_RADIOTEXT,
  RDS_CMD_AF,
  RDS_CMD_AF_LIST,  
  RDS_CMD_AFON,
  RDS_CMD_TAON,
  RDS_CMD_TAON_OFF
} RdsCmd;

/*typedef struct{
   void (*callback)(RdsEvent event);
}RDS_Hdlr;*/
typedef void (*RDS_CallBack)(RdsEvent event);
/* RDS Driver API */
void FMDrv_RDS_Reset(void);
void FMDrv_RDS_Disable(void);
void FMDrv_RDS_Enable(void);
kal_uint16 FMDrv_RDS_Get_BKValue(kal_uint16 *block, kal_uint8 offset);
void FMDrv_RDS_GetData(kal_uint16 *data);
void FMDrv_RDS_INTR_OnOff(kal_bool isOn);
kal_uint16 FMDrv_RDS_Read_BKCnt(kal_bool Val);
void FMDrv_RDS_Reset(void);
void FMDrv_RDS_Reset_BKCnt(void);

/* RDS Driver API */
void RDS_Enable(void);
void RDS_Disable(void);
void RDS_Init_Data(void);
void RDS_Eint_Handler(void);
void RDS_EventGet(void);
kal_uint16 RDS_Read_Block_Counter(kal_bool Val);
void RDS_Reset_Block_Counter(void);
//kal_bool RDS_RegChk(void);
void RDS_INTR_Enable(void);
void RDS_INTR_Disable(void);

/* FMR RDS API */
void FMR_RDS_OnOff(kal_bool On_Off);
//void FMR_RDS_Open( void (*callback)(RdsEvent event));
void FMR_RDS_Open(RDS_CallBack callback);
void FMR_RDS_GetInfo(RdsCmd Cmd, kal_uint16 *buffer, kal_uint8 *bufsize);
void FMR_RDS_GetStatus(RdsFlag *flag, kal_uint16 *buffer);
kal_uint16 FMR_RDS_Get_GoodBlock_Counter(void);
kal_uint16 FMR_RDS_Get_BadBlock_Counter(void);
kal_uint16 FMR_RDS_Get_BadBlock_Ratio(void);
void FMR_RDS_Reset_Block_Counter(void);
void FMR_RDS_Read_Group_Counter(kal_uint16 *pstGroupCnt);
void FMR_RDS_Reset_Group_Counter(void);
void FMDrv_HCI_Event_Hdlr(kal_bool isReadyRead);
void FMR_RDS_BlerCheck(void * param);
void FMR_RDS_EnableAF(kal_bool b_AFON);
void FMR_RDS_EnableTP(kal_bool b_TPON);
#endif
