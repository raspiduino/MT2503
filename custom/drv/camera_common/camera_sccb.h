/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   camera_sccb.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   CAMERA SCCB interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAMERA_SCCB_H__
#define __CAMERA_SCCB_H__

#include "kal_release.h"

#define MAX_SW_SCCB_FAIL_TRY_NO    3

typedef enum
{
  CAMERA_HW_SCCB = 1, /* 0 indicate no init */
  CAMERA_SW_SCCB
} CAMERA_SCCB_MODE;

typedef enum
{
  CAMERA_SCCB_16BIT,
  CAMERA_SCCB_8BIT
} CAMERA_SCCB_WIDTH;

typedef enum
{
  CAMERA_SCCB_SENSOR,
  CAMERA_SCCB_LENS,
  CAMERA_SCCB_EEPROM,
  CAMERA_SCCB_MATV,
  
  CAMERA_SCCB_MAX,
} CAMERA_SCCB_OWNER;

void CamWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para);
void CamWriteCmosSensor8(kal_uint16 Addr, kal_uint8 Para);
kal_uint16 CamReadCmosSensor(kal_uint16 Addr);
void LensWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para);
kal_uint16 LensReadCmosSensor(kal_uint16 Addr);
void EepromWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para);
kal_uint16 EepromReadCmosSensor(kal_uint16 Addr);
void MatvWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para);
kal_uint16 MatvReadCmosSensor(kal_uint16 Addr);


void CameraSccbInit(CAMERA_SCCB_MODE Mode,
                        kal_uint8 HWSccbClkPinMode, kal_uint8 HWSccbDataPinMode,
                        kal_uint16 SWSccbDelay);
void MatvSccbInit(CAMERA_SCCB_MODE Mode,
                        kal_uint8 HWSccbClkPinMode, kal_uint8 HWSccbDataPinMode,
                        kal_uint16 SWSccbDelay);
void CameraSccbOpen(CAMERA_SCCB_OWNER Owner,
                           kal_uint8 SccbWriteId,
                           CAMERA_SCCB_WIDTH SccbAddrWidth, CAMERA_SCCB_WIDTH SccbDataWidth,
                           kal_uint16 HWSccbSpeed);
void CameraSccbSetAddr(CAMERA_SCCB_OWNER Owner, kal_uint8 SccbWriteId);
void CameraSccbDisWR(CAMERA_SCCB_OWNER Owner);
void CameraSccbClose(CAMERA_SCCB_OWNER Owner);

#endif

