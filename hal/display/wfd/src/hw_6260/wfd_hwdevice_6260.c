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
 *    wfd_hwdevice_6250.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file serves as the entry point to obtain all WFD devices in MTK
 *    MT6256 series display HW devices.
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
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_display.h"
#if defined(DRV_LCD_MT6260_SERIES)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/
#define WFD_HWDEVICE_6250_LCD_ID          (0x62500000)

/*****************************************************************************
 *  Include directives
 ****************************************************************************/

#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\hw_6250\wfd_lcd_6250.h"

#ifdef __cplusplus
extern "C" {
#endif

extern WFDErrorCode wfd_lcd_initialize(WFDHWDevicePrimitivesMTK **pDevicePrimitives);
/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/

/*****************************************************************************
 *  Local variables
 ****************************************************************************/
static WFDHWDevicePrimitivesMTK* _wfd_hwdevices[1] = {0};
static WFDErrorCode _wfd_errorcode = WFD_ERROR_NONE;

/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/
static void
_wfd_hwdevice_6250_ModuleInitialize()
{
#if defined(__MTK_TARGET__) || defined(FPGA)
  if (NULL == _wfd_hwdevices[0])
  {
    if (WFD_ERROR_NONE != wfd_lcd_initialize(&_wfd_hwdevices[0]))
    {
      _wfd_hwdevices[0] = NULL;
    }
  }
#else   // #if defined(__MTK_TARGET__)
  // MoDIS
#endif  // #if defined(__MTK_TARGET__)
}

/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
WFDint
WFD_HWDevice_GetIds(
  WFDint *idsList,
  WFDint listCapacity)
{
  WFDint devCount = 0;

  if ((NULL == idsList) || (1 > listCapacity))
    return 0;

  if (NULL == _wfd_hwdevices[0])
  {
      _wfd_hwdevice_6250_ModuleInitialize();
  }

  if (NULL != _wfd_hwdevices[0]) { devCount++; }

  if ((1 <= listCapacity) &&
      (1 <= devCount))
  {
    idsList[0] = WFD_HWDEVICE_6250_LCD_ID;
  }

  return (devCount <= listCapacity) ? devCount : listCapacity;
}

WFDDevice
WFD_HWDevice_CreateDevice(
  WFDint deviceId,
  const WFDint *attribList)
{
  if ((WFD_HWDEVICE_6250_LCD_ID == deviceId) &&
      (NULL != _wfd_hwdevices[0]) &&
      (NULL != _wfd_hwdevices[0]->wfdCreateDevice))
  {
    return _wfd_hwdevices[0]->wfdCreateDevice(WFD_HWDEVICE_6250_LCD_ID, attribList);
  }

  return WFD_INVALID_HANDLE;
}

void
WFD_HWDevice_SetError(
  WFDErrorCode err)
{
  if (WFD_ERROR_NONE == _wfd_errorcode)
  {
    _wfd_errorcode = err;
  }
}

WFDErrorCode
WFD_HWDevice_GetError(void)
{
  WFDErrorCode err = _wfd_errorcode;
  _wfd_errorcode = WFD_ERROR_NONE;
  return err;
}

#ifdef __cplusplus
}
#endif

#endif  // #if defined(MT6260)

