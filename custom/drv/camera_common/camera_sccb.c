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
 *   camera_sccb.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor SW/HW SCCB driver function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *       HISTORY
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
/* #define __CAMERA_I2C_DEBUG__ */

#include "kal_release.h"
#include "dcl.h"
#include "camera_sccb.h"
#ifdef __CAMERA_I2C_DEBUG__
#include "kal_trace.h"

#define CAMERA_SCCB_ERR_PRINT(...) kal_print_string_trace(MOD_ENG, TRACE_ERROR, __VA_ARGS__)
#else
#define CAMERA_SCCB_ERR_PRINT(...)
#endif

#define CAMERA_SET_SCCB_CLK_OUTPUT DclGPIO_Control(CameraSccbData.SccbClkPin, GPIO_CMD_SET_DIR_OUT, 0);
#define CAMERA_SET_SCCB_DATA_OUTPUT DclGPIO_Control(CameraSccbData.SccbDataPin, GPIO_CMD_SET_DIR_OUT, 0);
#define CAMERA_SET_SCCB_CLK_INPUT DclGPIO_Control(CameraSccbData.SccbClkPin, GPIO_CMD_SET_DIR_IN, 0);
#define CAMERA_SET_SCCB_DATA_INPUT DclGPIO_Control(CameraSccbData.SccbDataPin, GPIO_CMD_SET_DIR_IN, 0);
#define CAMERA_SET_SCCB_CLK_HIGH DclGPIO_Control(CameraSccbData.SccbClkPin, GPIO_CMD_WRITE_HIGH, 0);
#define CAMERA_SET_SCCB_CLK_LOW DclGPIO_Control(CameraSccbData.SccbClkPin, GPIO_CMD_WRITE_LOW, 0);
#define CAMERA_SET_SCCB_DATA_HIGH DclGPIO_Control(CameraSccbData.SccbDataPin, GPIO_CMD_WRITE_HIGH, 0);
#define CAMERA_SET_SCCB_DATA_LOW DclGPIO_Control(CameraSccbData.SccbDataPin, GPIO_CMD_WRITE_LOW, 0);
#define CAMERA_GET_SCCB_DATA_BIT (DclGPIO_Control(CameraSccbData.SccbDataPin, GPIO_CMD_READ, (DCL_CTRL_DATA_T*)&data), data.u1IOData)

typedef struct
{
  DCL_HANDLE Handle; /* HW I2C handle */
  kal_uint16 SccbSpeed;
  kal_uint8 SccbAddrLen;
  kal_uint8 SccbDataLen;
  kal_uint8 SccbWriteId;
  kal_bool SccbWREn; /* write and read support */
} CAMERA_SCCB_INFO_STRUCT, *P_CAMERA_SCCB_INFO_STRUCT;

static struct
{
  CAMERA_SCCB_MODE Mode; /* SW I2C, HW I2C */
  CAMERA_SCCB_INFO_STRUCT Info[CAMERA_SCCB_MAX];
  DCL_HANDLE SccbClkPin; /* GPIO handle */
  DCL_HANDLE SccbDataPin; /* GPIO handle */
  kal_uint16 SWSccbDelay; /* global sw sccb delay */
} CameraSccbData;

/*************************************************************************
* FUNCTION
*    CameraSWSccbStartTransmission
*
* DESCRIPTION
*    This function simulate I2C start transmission through GPIO
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static void CameraSWSccbStartTransmission(void)
{
  volatile kal_uint16 j;
  
  CAMERA_SET_SCCB_CLK_OUTPUT;
  CAMERA_SET_SCCB_DATA_OUTPUT;
  CAMERA_SET_SCCB_DATA_HIGH;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  CAMERA_SET_SCCB_CLK_HIGH;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  CAMERA_SET_SCCB_DATA_LOW;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  CAMERA_SET_SCCB_CLK_LOW;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
}

/*************************************************************************
* FUNCTION
*    CameraSWSccbStopTransmission
*
* DESCRIPTION
*    This function simulate I2C stop transmission through GPIO
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static void CameraSWSccbStopTransmission(void)
{ 
  volatile kal_uint16 j;
  
  CAMERA_SET_SCCB_CLK_LOW;
  CAMERA_SET_SCCB_DATA_LOW;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  CAMERA_SET_SCCB_CLK_HIGH;
  for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  CAMERA_SET_SCCB_DATA_HIGH;
}

/*************************************************************************
* FUNCTION
*    CameraSWSccbSendByte
*
* DESCRIPTION
*    This function simulate I2C send data through GPIO
*
* PARAMETERS
*    SendByte
*    Size
*
* RETURNS
*    ack: 0: send seccess, 1: send fail
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint8 CameraSWSccbSendByte(kal_uint16 SendByte, kal_uint8 Size)
{
  GPIO_CTRL_READ_T data;
  volatile kal_uint16 j;
  kal_uint8 ack = 0;
  register kal_int8 i;
  
  while (Size--)
  {
    for (i = 7; i >= 0; i--)
    {
      if (SendByte&(1 << (i + (Size << 3))))
      {
        CAMERA_SET_SCCB_DATA_HIGH;
      }
      else
      {
        CAMERA_SET_SCCB_DATA_LOW;
      }
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      CAMERA_SET_SCCB_CLK_HIGH;
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      CAMERA_SET_SCCB_DATA_OUTPUT; /* just for delay */
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      CAMERA_SET_SCCB_CLK_LOW;
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    }
    CAMERA_SET_SCCB_DATA_INPUT;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_CLK_HIGH;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    ack |= CAMERA_GET_SCCB_DATA_BIT;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_CLK_LOW;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_DATA_OUTPUT;
  }
  
  return ack;
}

/*************************************************************************
* FUNCTION
*    CameraSWSccbGetBytes
*
* DESCRIPTION
*    This function simulate I2C get bytes data through GPIO
*
* PARAMETERS
*    Size: size of byte to get
*
* RETURNS
*    data read through I2C
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint16 CameraSWSccbGetBytes(kal_uint8 Size)
{
  GPIO_CTRL_READ_T data;
  volatile kal_uint16 j;
  register kal_uint16 get_byte = 0;
  register kal_int8 i;
  
  while (Size--)
  {
    for (i = 7; i >= 0; i--)
    {
      CAMERA_SET_SCCB_DATA_INPUT;
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      CAMERA_SET_SCCB_CLK_HIGH;
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      get_byte <<= 1;
      if (CAMERA_GET_SCCB_DATA_BIT)
      {
        get_byte |= 1;
      }
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
      CAMERA_SET_SCCB_CLK_LOW;
      for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    }
    if (Size)
    {
      CAMERA_SET_SCCB_DATA_LOW; /* ACK */
    }
    else
    {
      CAMERA_SET_SCCB_DATA_HIGH; /* NACK */
    }
    CAMERA_SET_SCCB_DATA_OUTPUT;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_CLK_HIGH;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_DATA_OUTPUT; /* just for delay */
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
    CAMERA_SET_SCCB_CLK_LOW;
    for (j = CameraSccbData.SWSccbDelay; j > 0; j--);
  }
  
  return get_byte;
}

/*************************************************************************
* FUNCTION
*    CameraWriteCmosSensor
*
* DESCRIPTION
*    This function wirte data to CMOS sensor through I2C
*    MAX_SW_SCCB_FAIL_TRY_NO is the max try number. when write fail, the function retry again until
*    try times reach MAX_SW_SCCB_FAIL_TRY_NO.
*
* PARAMETERS
*    Owner
*    Addr: address of register
*    Para: value of register
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void CameraWriteCmosSensor(CAMERA_SCCB_OWNER Owner, kal_uint16 Addr, kal_uint16 Para)
{
  const P_CAMERA_SCCB_INFO_STRUCT Info = &CameraSccbData.Info[Owner];
  
  if (!Info->Handle) /* open before use */
  {
    ASSERT(0);
  }
  if (CAMERA_HW_SCCB == CameraSccbData.Mode)
  {
    I2C_CTRL_SINGLE_WRITE_T WriteData;
    DCL_STATUS rt;
    kal_uint8 WriteBuff[4];
    
    WriteData.u4DataLen = 0;
    if (2 == Info->SccbAddrLen)
    {
      WriteBuff[WriteData.u4DataLen++] = Addr >> 8;
    }
    WriteBuff[WriteData.u4DataLen++] = Addr;
    if (2 == Info->SccbDataLen)
    {
      WriteBuff[WriteData.u4DataLen++] = Para >> 8;
    }
    WriteBuff[WriteData.u4DataLen++] = Para;
    WriteData.pu1Data = WriteBuff;
    
    rt = DclSI2C_Control(Info->Handle, I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T *)&WriteData);
    if (rt != STATUS_OK)
    {
      CAMERA_SCCB_ERR_PRINT("HWI2C CAM %d write %x, %x fail: %d", Owner, Addr, Para, rt);
    }
#ifdef __CAMERA_I2C_DEBUG__    
    else
    {
      kal_print_string_trace(MOD_ENG, TRACE_INFO, "reg[%x] = %x",
        2 == Info->SccbAddrLen ? Addr : Addr&0xFF,
        2 == Info->SccbDataLen ? Para : Para&0xFF);
    }
#endif
  }
  else /* SW SCCB */
  {
    kal_uint8 FailTryNo = MAX_SW_SCCB_FAIL_TRY_NO + 1;
    
    while (--FailTryNo > 0)
    {
      CameraSWSccbStartTransmission();
      if (CameraSWSccbSendByte(Info->SccbWriteId, 1)) continue;
      if (CameraSWSccbSendByte(Addr, Info->SccbAddrLen)) continue;
      if (CameraSWSccbSendByte(Para, Info->SccbDataLen)) continue;
      break;
    }
    CameraSWSccbStopTransmission();
    if (!FailTryNo) 
    {
      CAMERA_SCCB_ERR_PRINT("SWI2C CAM %d write %x, %x fail", Owner, Addr, Para);
    }
  }
}

/*************************************************************************
* FUNCTION
*    CameraReadCmosSensor
*
* DESCRIPTION
*    This function read data from CMOS sensor through I2C.
*    MAX_SW_SCCB_FAIL_TRY_NO is the max try number. when read fail, the function retry again until
*    try times reach MAX_SW_SCCB_FAIL_TRY_NO.
*
* PARAMETERS
*    Owner
*    Addr: address of register
*
* RETURNS
*    data read through I2C
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 CameraReadCmosSensor(CAMERA_SCCB_OWNER Owner, kal_uint16 Addr)
{
  const P_CAMERA_SCCB_INFO_STRUCT Info = &CameraSccbData.Info[Owner];
  kal_uint16 GetByte = 0;
  
  if (!Info->Handle) /* open before use */
  {
    ASSERT(0);
  }
  if (CAMERA_HW_SCCB == CameraSccbData.Mode)
  {
    DCL_STATUS rt;
    kal_uint8 ReadBuff[2];
    kal_uint8 WriteBuff[2];
    
    if (2 == Info->SccbAddrLen)
    {
      WriteBuff[0] = Addr >> 8;
      WriteBuff[1] = Addr;
    }
    else
    {
      WriteBuff[0] = Addr;
    }
    if (Info->SccbWREn)
    {
      I2C_CTRL_WRITE_AND_READE_T I2cData;
      
      I2cData.pu1OutData = WriteBuff;
      I2cData.u4OutDataLen = Info->SccbAddrLen;
      I2cData.pu1InData = ReadBuff;
      I2cData.u4InDataLen = Info->SccbDataLen;
      rt = DclSI2C_Control(Info->Handle, I2C_CMD_WRITE_AND_READ, (DCL_CTRL_DATA_T *)&I2cData);
    }
    else
    {
      I2C_CTRL_SINGLE_WRITE_T WriteData;
      I2C_CTRL_SINGLE_READ_T ReadData;
      
      WriteData.pu1Data = WriteBuff;
      WriteData.u4DataLen = Info->SccbAddrLen;
      ReadData.pu1Data = ReadBuff;
      ReadData.u4DataLen = Info->SccbDataLen;
      rt = DclSI2C_Control(Info->Handle, I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T *)&WriteData);
      if (rt != STATUS_OK)
      {
        CAMERA_SCCB_ERR_PRINT("HWI2C CAM %d write %x fail: %d", Owner, Addr, rt);
      }
      rt = DclSI2C_Control(Info->Handle, I2C_CMD_SINGLE_READ, (DCL_CTRL_DATA_T *)&ReadData);
    }
    if (rt != STATUS_OK)
    {
      CAMERA_SCCB_ERR_PRINT("HWI2C CAM %d read %x fail: %d", Owner, Addr, rt);
    }
    GetByte = (2 == Info->SccbDataLen ? (ReadBuff[0] << 8)|ReadBuff[1] : ReadBuff[0]);
  }
  else /* SW SCCB */
  {
    kal_uint8 FailTryNo = MAX_SW_SCCB_FAIL_TRY_NO + 1;
    
    while (--FailTryNo > 0)
    {
      CameraSWSccbStartTransmission();
      if (CameraSWSccbSendByte(Info->SccbWriteId, 1)) continue;
      if (CameraSWSccbSendByte(Addr, Info->SccbAddrLen)) continue;
      if (!Info->SccbWREn) CameraSWSccbStopTransmission();
      CameraSWSccbStartTransmission();
      if (CameraSWSccbSendByte(Info->SccbWriteId|1, 1)) continue;
      GetByte = CameraSWSccbGetBytes(Info->SccbDataLen);
      break;
    }
    CameraSWSccbStopTransmission();
    if (!FailTryNo) 
    {
      CAMERA_SCCB_ERR_PRINT("SWI2C CAM %d read %x fail", Owner, Addr);
    }
  }
  return GetByte;
}

/*************************************************************************
* FUNCTION
*    CameraSccbInitInternal
*
* DESCRIPTION
*    This function init and config camera sccb by owner,
*    MUST BE called after all owner closed
*
* PARAMETERS
*    Mode: CAMERA_HW_SCCB or CAMERA_SW_SCCB
*    SccbClkPin: sccb clock pin gpio number
*    HWSccbClkPinMode
*    SccbDataPin: sccb data pin gpio number
*    HWSccbDataPinMode
*    SWSccbDelay: only use in SW sccb mode
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void CameraSccbInitInternal(CAMERA_SCCB_MODE Mode,
                        kal_uint8 SccbClkPin, kal_uint8 HWSccbClkPinMode,
                        kal_uint8 SccbDataPin, kal_uint8 HWSccbDataPinMode,
                        kal_uint16 SWSccbDelay)
{
  if ((CameraSccbData.Mode && CameraSccbData.Mode != Mode) ||
      0xFF == SccbClkPin ||
      0xFF == SccbDataPin)
  {
    ASSERT(0);
  }
  CameraSccbData.Mode = Mode;
  CameraSccbData.SWSccbDelay = SWSccbDelay;
  CameraSccbData.SccbClkPin = DclGPIO_Open(DCL_GPIO, SccbClkPin);
  CameraSccbData.SccbDataPin = DclGPIO_Open(DCL_GPIO, SccbDataPin);
  if (CAMERA_SW_SCCB == Mode) /* sw sccb pin mode */
  {
    HWSccbClkPinMode = HWSccbDataPinMode = 0;
  }
  DclGPIO_Control(CameraSccbData.SccbClkPin, HWSccbClkPinMode + GPIO_CMD_SET_MODE_0, 0);
  DclGPIO_Control(CameraSccbData.SccbDataPin, HWSccbDataPinMode + GPIO_CMD_SET_MODE_0, 0);
  if (CAMERA_SW_SCCB == Mode) /* set input mode to pull high by resistor */
  {
    CAMERA_SET_SCCB_CLK_INPUT;
    CAMERA_SET_SCCB_DATA_INPUT;
    CAMERA_SET_SCCB_CLK_HIGH; /* set default high */
    CAMERA_SET_SCCB_DATA_HIGH;
  }
  else
  {
    DclGPIO_Close(CameraSccbData.SccbClkPin);
    DclGPIO_Close(CameraSccbData.SccbDataPin);
  }
}

/*************************************************************************
* FUNCTION
*    CamWriteCmosSensor
*
* DESCRIPTION
*    This function wirte data to CMOS sensor through I2C
*
* PARAMETERS
*    Addr: address of register
*    Para: value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CamWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para)
{
  CameraWriteCmosSensor(CAMERA_SCCB_SENSOR, Addr, Para);
}

/*************************************************************************
* FUNCTION
*    CamWriteCmosSensor8
*
* DESCRIPTION
*    This function wirte data to CMOS sensor through I2C
*
* PARAMETERS
*    Addr: address of register
*    Para: 8bit value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CamWriteCmosSensor8(kal_uint16 Addr, kal_uint8 Para)
{
  const P_CAMERA_SCCB_INFO_STRUCT Info = &CameraSccbData.Info[CAMERA_SCCB_SENSOR];
  kal_uint8 SccbDataLen;
  
  SccbDataLen = Info->SccbDataLen; /* backup data len */
  Info->SccbDataLen = 1; /* 8bit data length */
  CameraWriteCmosSensor(CAMERA_SCCB_SENSOR, Addr, Para);
  Info->SccbDataLen = SccbDataLen; /* restore data len */
}

/*************************************************************************
* FUNCTION
*    CamReadCmosSensor
*
* DESCRIPTION
*    This function read data from CMOS sensor through I2C.
*
* PARAMETERS
*    Addr: address of register
*
* RETURNS
*    data read through I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 CamReadCmosSensor(kal_uint16 Addr)
{
  return CameraReadCmosSensor(CAMERA_SCCB_SENSOR, Addr);
}

/*************************************************************************
* FUNCTION
*    LensWriteCmosSensor
*
* DESCRIPTION
*    This function wirte data to Lens through I2C
*
* PARAMETERS
*    Addr: address of register
*    Para: value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void LensWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para)
{
  CameraWriteCmosSensor(CAMERA_SCCB_LENS, Addr, Para);
}

/*************************************************************************
* FUNCTION
*    LensReadCmosSensor
*
* DESCRIPTION
*    This function read data from lens through I2C.
*
* PARAMETERS
*    Addr: address of register
*
* RETURNS
*    data read through I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 LensReadCmosSensor(kal_uint16 Addr)
{
  return CameraReadCmosSensor(CAMERA_SCCB_LENS, Addr);
}

/*************************************************************************
* FUNCTION
*    EepromWriteCmosSensor
*
* DESCRIPTION
*    This function wirte data to eeprom through I2C
*
* PARAMETERS
*    Addr: address of register
*    Para: value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EepromWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para)
{
  CameraWriteCmosSensor(CAMERA_SCCB_EEPROM, Addr, Para);
}

/*************************************************************************
* FUNCTION
*    EepromReadCmosSensor
*
* DESCRIPTION
*    This function read data from eeprom through I2C.
*
* PARAMETERS
*    Addr: address of register
*
* RETURNS
*    data read through I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 EepromReadCmosSensor(kal_uint16 Addr)
{
  return CameraReadCmosSensor(CAMERA_SCCB_EEPROM, Addr);
}

#ifdef __ATV_SUPPORT__

/*************************************************************************
* FUNCTION
*    MatvWriteCmosSensor
*
* DESCRIPTION
*    This function wirte data  through I2C
*
* PARAMETERS
*    Addr: address of register
*    Para: value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MatvWriteCmosSensor(kal_uint16 Addr, kal_uint16 Para)
{
  CameraWriteCmosSensor(CAMERA_SCCB_MATV, Addr, Para);
}

/*************************************************************************
* FUNCTION
*    MatvReadCmosSensor
*
* DESCRIPTION
*    This function read data from I2C.
*
* PARAMETERS
*    Addr: address of register
*
* RETURNS
*    data read through I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 MatvReadCmosSensor(kal_uint16 Addr)
{
  return CameraReadCmosSensor(CAMERA_SCCB_MATV, Addr);
}


/*************************************************************************
* FUNCTION
*    MatvReadAudioRegister
*
* DESCRIPTION
*    This function read matv audio register.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void MatvReadAudioRegister()
{
      I2C_CTRL_SINGLE_WRITE_T WriteData;
	  kal_uint8 WriteBuff[2];

	  I2C_CTRL_WRITE_AND_READE_T I2cData;
	  kal_uint8 ReadBuffR;
      kal_uint8 WriteBuffR;
			
      WriteData.u4DataLen = 0;
	  WriteBuff[WriteData.u4DataLen++] = 0xff;
	  WriteBuff[WriteData.u4DataLen++] = 0x31;
	  WriteData.pu1Data = WriteBuff;
	  DclSI2C_Control(CameraSccbData.Info[CAMERA_SCCB_MATV].Handle,I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T *)&WriteData);
			
	  WriteBuffR = 0x01;
      I2cData.pu1OutData = &WriteBuffR;
      I2cData.u4OutDataLen = 1;
      I2cData.pu1InData = &ReadBuffR;
      I2cData.u4InDataLen = 1;
	  DclSI2C_Control(CameraSccbData.Info[CAMERA_SCCB_MATV].Handle, I2C_CMD_WRITE_AND_READ, (DCL_CTRL_DATA_T *)&I2cData);
}

#endif

/*************************************************************************
* FUNCTION
*    CameraSccbInit
*
* DESCRIPTION
*    This function init and config camera sccb by owner,
*    MUST BE called after all owner closed
*
* PARAMETERS
*    Mode: CAMERA_HW_SCCB or CAMERA_SW_SCCB
*    HWSccbClkPinMode
*    HWSccbDataPinMode
*    SWSccbDelay: only use in SW sccb mode
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbInit(CAMERA_SCCB_MODE Mode,
                        kal_uint8 HWSccbClkPinMode, kal_uint8 HWSccbDataPinMode,
                        kal_uint16 SWSccbDelay)
{
  extern const char gpio_sccb_serial_clk_pin;
  extern const char gpio_sccb_serial_data_pin;
  
  CameraSccbInitInternal(Mode,
    gpio_sccb_serial_clk_pin, HWSccbClkPinMode,
    gpio_sccb_serial_data_pin, HWSccbDataPinMode,
    SWSccbDelay);
}

#ifdef __ATV_SUPPORT__
/*************************************************************************
* FUNCTION
*    MatvSccbInit
*
* DESCRIPTION
*    This function init and config camera sccb by owner,
*    MUST BE called after all owner closed
*
* PARAMETERS
*    Mode: CAMERA_HW_SCCB or CAMERA_SW_SCCB
*    HWSccbClkPinMode
*    HWSccbDataPinMode
*    SWSccbDelay: only use in SW sccb mode
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MatvSccbInit(CAMERA_SCCB_MODE Mode,
                        kal_uint8 HWSccbClkPinMode, kal_uint8 HWSccbDataPinMode,
                        kal_uint16 SWSccbDelay)
{
  extern const char gpio_matv_i2c_clk_pin;
  extern const char gpio_matv_i2c_dat_pin;
  
  CameraSccbInitInternal(Mode,
    gpio_matv_i2c_clk_pin, HWSccbClkPinMode,
    gpio_matv_i2c_dat_pin, HWSccbDataPinMode,
    SWSccbDelay);
}
#endif
/*************************************************************************
* FUNCTION
*    CameraSccbOpen
*
* DESCRIPTION
*    This function open and config camera sccb by owner,
*    MUST BE called after CameraSccbInit function
*
* PARAMETERS
*    Owner
*    SccbWriteId
*    SccbAddrWidth: CAMERA_SCCB_8BIT or CAMERA_SCCB_16BIT
*    SccbDataWidth: CAMERA_SCCB_8BIT or CAMERA_SCCB_16BIT
*    HWSccbSpeed: fast speed mode: 100~400(Kbps), high speed mode: >400(Kbps)
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbOpen(CAMERA_SCCB_OWNER Owner,
                           kal_uint8 SccbWriteId,
                           CAMERA_SCCB_WIDTH SccbAddrWidth, CAMERA_SCCB_WIDTH SccbDataWidth,
                           kal_uint16 HWSccbSpeed)
{
  P_CAMERA_SCCB_INFO_STRUCT Info;
  I2C_CONFIG_T HWSccbPara;
  
  switch (Owner)
  {
  case CAMERA_SCCB_SENSOR:
    HWSccbPara.eOwner = DCL_I2C_OWNER_CAMERA;
    break;
  case CAMERA_SCCB_MATV:
  	HWSccbPara.eOwner = DCL_I2C_OWNER_MATV;
    break;
  case CAMERA_SCCB_LENS:
    HWSccbPara.eOwner = DCL_I2C_OWNER_AF;
    break;
  case CAMERA_SCCB_EEPROM:
    HWSccbPara.eOwner = DCL_I2C_OWNER_CAMERA_EEPROM;
    break;
  default:
    ASSERT(0);
  }
  Info = &CameraSccbData.Info[Owner];
  /* must not be multi opened, must be call CameraSccbInit before CameraSccbOpen */
  if (Info->Handle || !CameraSccbData.Mode)
  {
    ASSERT(0);
  }
  Info->SccbSpeed = HWSccbSpeed;
  Info->SccbAddrLen = (CAMERA_SCCB_8BIT == SccbAddrWidth) ? 1 : 2;
  Info->SccbDataLen = (CAMERA_SCCB_8BIT == SccbDataWidth) ? 1 : 2;
  Info->SccbWriteId = SccbWriteId&0xFE; /* clear write id bit0 */
  Info->SccbWREn = KAL_TRUE; /* default: support write and read */
  if (CAMERA_SW_SCCB == CameraSccbData.Mode)
  {
    Info->Handle = KAL_TRUE; /* indicate opened */
  }
  else
  {
    HWSccbPara.fgGetHandleWait = KAL_TRUE;
    HWSccbPara.u1SlaveAddress = Info->SccbWriteId;
    HWSccbPara.u1DelayLen = 0;
    if (HWSccbSpeed > 400) /* 400Kbps */
    {
      HWSccbPara.eTransactionMode = DCL_I2C_TRANSACTION_HIGH_SPEED_MODE;
    }
    else
    {
      HWSccbPara.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
    }
    HWSccbPara.u4FastModeSpeed = HWSccbPara.u4HSModeSpeed = HWSccbSpeed;
    HWSccbPara.fgEnableDMA = KAL_FALSE;
    Info->Handle = DclSI2C_Open(DCL_I2C, HWSccbPara.eOwner);
    DclSI2C_Configure(Info->Handle, (DCL_CONFIGURE_T *)&HWSccbPara);
  }
}

/*************************************************************************
* FUNCTION
*    CameraSccbSetAddr
*
* DESCRIPTION
*    This function config camera sccb slave address by owner,
*    MUST BE called after CameraSccbOpen function
*
* PARAMETERS
*    Owner
*    SccbWriteId
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbSetAddr(CAMERA_SCCB_OWNER Owner, kal_uint8 SccbWriteId)
{
  P_CAMERA_SCCB_INFO_STRUCT Info;
  I2C_CTRL_SET_SLAVE_ADDRESS_T SlaveAddr;
  
  if (Owner >= CAMERA_SCCB_MAX) /* error check */
  {
    ASSERT(0);
  }
  Info = &CameraSccbData.Info[Owner];
  if (!Info->Handle) /* open before set */
  {
    ASSERT(0);
  }
  Info->SccbWriteId = SccbWriteId&0xFE; /* clear write id bit0 */
  if (CAMERA_HW_SCCB == CameraSccbData.Mode)
  {
    SlaveAddr.u1SlaveAddress = Info->SccbWriteId;
    DclSI2C_Control(Info->Handle, I2C_CMD_SET_SLAVE_ADDRESS, (DCL_CTRL_DATA_T *)&SlaveAddr);
  }
}

/*************************************************************************
* FUNCTION
*    CameraSccbDisWR
*
* DESCRIPTION
*    This function disable camera sccb write and read feature by owner,
*    MUST BE called after CameraSccbOpen function
*
* PARAMETERS
*    Owner
*    SccbWriteId
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbDisWR(CAMERA_SCCB_OWNER Owner)
{
  P_CAMERA_SCCB_INFO_STRUCT Info;
  
  if (Owner >= CAMERA_SCCB_MAX) /* error check */
  {
    ASSERT(0);
  }
  Info = &CameraSccbData.Info[Owner];
  if (!Info->Handle) /* open before set */
  {
    ASSERT(0);
  }
  Info->SccbWREn = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*    CameraSccbClose
*
* DESCRIPTION
*    This function close camera sccb by owner
*
* PARAMETERS
*    Owner
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbClose(CAMERA_SCCB_OWNER Owner)
{
  P_CAMERA_SCCB_INFO_STRUCT Info;
  kal_int16 i;
  
  if (Owner >= CAMERA_SCCB_MAX) /* error check */
  {
    ASSERT(0);
  }
  Info = &CameraSccbData.Info[Owner];
  if (CAMERA_HW_SCCB == CameraSccbData.Mode && Info->Handle)
  {
    DclSI2C_Close(Info->Handle);
  }
  Info->Handle = NULL;
  for (i = CAMERA_SCCB_MAX - 1; i >= 0 && !CameraSccbData.Info[i].Handle; i--);
  if (i < 0) /* if all closed then set input mode to avoid electric leakage */
  {
    if (CAMERA_SW_SCCB == CameraSccbData.Mode)
    {
      CAMERA_SET_SCCB_CLK_INPUT;
      CAMERA_SET_SCCB_DATA_INPUT;
      DclGPIO_Close(CameraSccbData.SccbClkPin);
      DclGPIO_Close(CameraSccbData.SccbDataPin);
    }
    CameraSccbData.Mode = (CAMERA_SCCB_MODE)0; /* clear Mode */
  }
}

