/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the header of LCD Tearing Manager.
 *    This file is only for target.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * .
 *
 * 03 02 2011 sophie.chen
 * removed!
 * .
 *
 * 12 23 2010 sophie.chen
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __LCD_TEAR_MANAGER_H__
#define __LCD_TEAR_MANAGER_H__

#include "drv_comm.h"
#include "kal_release.h"
//#include "lcd_if_hw.h"
//#include "lcd_if.h"
#include "lcm_if.h"
#include "lcd_sw.h"
#include "lcd_if_manager.h"

typedef enum
{
  LCDTEAR_ERROR_NONE = 0,
  LCDTEAR_BAD_PARAMETER,
  LCDTEAR_NOT_SUPPORT
}lcdTearErrorCode;


typedef  kal_bool (*LCDTEAR_CALLBACK)(void* ,void* ,kal_uint32);
                                        //(WFD_DEVICE* device, WFD_PORT* port, WFDEventType event);
typedef struct
{
  //Control HW primitivies
  lcdTearErrorCode (*Init)(kal_uint32 port_id); //Init this sync mode. Call this function before use the sync mode
  lcdTearErrorCode (*Config)(kal_uint32 port_id, kal_uint32 lcm_startY, kal_uint32 roiWidth, kal_uint32 roiHeight); //Config sync mode before start LCD update
  void (*VsyncIntCallback)(kal_uint32 port_id); //LCD Vsync Signal's interrupt callback funciton. Call this function in HISR of Vsync-Int
  void (*Start)(kal_uint32 port_id, kal_bool blockingWaitVsync); //Start Sync. Call this function when you want to blt. TearManager will do Blt as a callabck function when VHsync receieved or timer expires...
}LCDTearSyncModePrimitives;

/******************************************************************
* Export APIs
*******************************************************************/
lcdTearErrorCode
lcdTear_Init(
  kal_uint32 port_id,
  LCD_Funcs* ifFuncTable,
  LCD_IOCTRL_DEVICE_IF_T *if_set);


lcdTearErrorCode
lcdTear_GetSyncPrimitives(
  kal_uint32 port_id,
  LCDTearSyncModePrimitives *pSyncPrimitives);


lcdTearErrorCode
lcdTear_UserRegisterCallback(
  kal_uint32 port_id,
  LCDTEAR_CALLBACK  lcdTearCallback,
  kal_uint32 *lcdTearCallbackPara,
  kal_uint32 lcdTearCallbackParaCnt);

kal_bool
lcdTear_IsEnableVsyncIntMask(
  kal_uint32 port_id);


#endif //__LCD_TEAR_MANAGER_H__
