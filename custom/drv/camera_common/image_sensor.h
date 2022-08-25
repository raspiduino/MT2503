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
 *   image_sensor.h
 *
 * Project:
 * --------
 *   MT6228
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 ****************************************************************************/
#ifndef _IMAGE_SENSOR_H
#define _IMAGE_SENSOR_H

#include "drv_features.h"
#include "image_sensor_nvram.h"
#include "sensor_comm_def.h"

#if (defined(MT9P012_RAW))
#include "image_sensor_MT9P012.h"
#endif
#if (defined(MT9P012_MIPI_RAW))
#include "image_sensor_MT9P012_MIPI.h"
#endif
#if (defined(MT9P013_RAW))
#include "image_sensor_MT9P013.h"
#endif
#if (defined(MT9P015_RAW))
#include "image_sensor_MT9P015.h"
#endif
#if (defined(MT9T013_RAW))
#include "image_sensor_MT9T013.h"
#endif
#if (defined(MT9D113_YUV))
#include "image_sensor_MT9D113.h"
#endif
#if (defined(MT9D115_YUV))
#include "image_sensor_MT9D115.h"
#endif
#if (defined(MT9P111_YUV))
#include "image_sensor_MT9P111.h"
#endif
#if (defined(BF3703_YUV))
#include "image_sensor_BF3703.h"
#endif
#if (defined(MT9D112_YUV))
#include "image_sensor_MT9D112.h"
#endif
#if (defined(OV5642_RAW) || defined(OV5642_YUV))
#include "image_sensor_OV5642.h"
#endif
#if (defined(OV5642_MIPI_RAW))
#include "image_sensor_OV5642_MIPI.h"
#endif  
#if (defined(OV5650_RAW))
#include "image_sensor_OV5650.h"
#endif
#if (defined(OV5650_MIPI_RAW))
#include "image_sensor_OV5650_MIPI.h"
#endif
#if (defined(OV5640_YUV))
#include "image_sensor_OV5640.h"
#endif
#if (defined(OV3640_RAW) || defined(OV3640_YUV) || defined(OV3640VGA_YUV))
#include "image_sensor_OV3640.h"
#endif
#if (defined(OV3647_RAW))
#include "image_sensor_OV3647.h"
#endif
#if (defined(OV2659_YUV))
#include "image_sensor_OV2659.h"
#endif
#if (defined(OV2655_RAW) || defined(OV2655_YUV))
#include "image_sensor_OV2655.h"
#endif
#if (defined(OV2650_RAW) || defined(OV2650_YUV))
#include "image_sensor_OV2650.h"
#endif
#if (defined(OV2640_RAW) || defined(OV2640_YUV))
#include "image_sensor_OV2640.h"
#endif
#if (defined(OV7670_YUV))
#include "image_sensor_OV7670.h"
#endif
#if (defined(OV7675_YUV))
#include "image_sensor_OV7675.h"
#endif
#if (defined(OV7690_YUV))
#include "image_sensor_OV7690.h"
#endif
#if (defined(MT9T113_YUV))
#include "image_sensor_MT9T113.h"
#endif
#if (defined(S5K3E2FX_RAW))
#include "image_sensor_S5K3E2FX.h"
#endif
#if (defined(S5K5BAFX_YUV))
#include "image_sensor_S5K5BAFX.h"
#endif
#if (defined(S5KA3DFX_YUV))
#include "image_sensor_S5KA3DFX.h"
#endif
#if (defined(S5K5CAGA_YUV))
#include "image_sensor_S5K5CAGA.h"
#endif
#if (defined(S5K4ECGX_YUV))
#include "image_sensor_S5K4ECGX.h"
#endif

#if (defined(SID020A_RAW))
#include "image_sensor_SID020A.h"
#endif
#if (defined(SID130B_YUV))
#include "image_sensor_SID130B.h"
#endif
#if (defined(SIM120C_YUV))
#include "image_sensor_SIM120C.h"
#endif
#if (defined(SIV120B_YUV))
#include "image_sensor_SIV120B.h"
#endif
#if (defined(SIV121D_YUV))
#include "image_sensor_SIV121D.h"
#endif
#if (defined(SIV100B_YUV))
#include "image_sensor_SIV100B.h"
#endif
#if (defined(SIC110A_YUV))
#include "image_sensor_SIC110A.h"
#endif
#if (defined(NOON200PC51_RAW))
#include "image_sensor_NOON200PC51.h"
#endif
#if (defined(NOON010PC30_YUV))
#include "image_sensor_NOON010PC30.h"
#endif
#if (defined(T8ET2_YUV))
#include "image_sensor_T8ET2.h"
#endif
#if (defined(GC0308_YUV))
#include "image_sensor_GC0308.h"
#endif
#if (defined(GC0307_YUV))
#include "image_sensor_GC0307.h"
#endif
#if (defined(GC0329_YUV))
#include "image_sensor_GC0329.h"
#endif
#if (defined(HI251_YUV))
#include "image_sensor_HI251.h"
#endif
#if (defined(HI253_YUV))
#include "image_sensor_HI253.h"
#endif
#if (defined(GT2005_YUV))
#include "image_sensor_GT2005.h"
#endif

#if (defined(HI704_YUV))
#include "image_sensor_HI704.h"
#endif
#if (defined(PAS6327_YUV))
#include "image_sensor_PAS6327.h"
#endif
#if (defined(MC501CB_YUV))
#include "image_sensor_MC501CB.h"
#endif

#if (defined(SIC320A_SERIAL_YUV))
#include "image_sensor_SIC320A_SERIAL.h"
#endif	

#if (defined(GC6113_SERIAL_YUV))
#include "image_sensor_GC6113_SERIAL.h"
#endif	

#if (defined(GC6123_SERIAL_YUV))
#include "image_sensor_GC6123_SERIAL.h"
#endif

#if (defined(GC0310_SERIAL_YUV))
#include "image_sensor_GC0310_SERIAL.h"
#endif

#if (defined(HM0155_SERIAL_YUV))
#include "image_sensor_HM0155_SERIAL.h"
#endif	

#if (defined(PAS6180_SERIAL_YUV))
#include "image_sensor_PAS6180_SERIAL.h"
#endif	

#if (defined(HIQD1_SERIAL_YUV))
#include "image_sensor_HIQD1_SERIAL.h"
#endif	


#if (defined(__ATV_SUPPORT__))
#include "matv_hostdrv.h"
#endif
#if (defined(ET8EV3_MIPI_RAW))
#include "image_sensor_ET8EV3_MIPI.h"
#endif

#define CCT_END_ADDR FACTORY_END_ADDR

/* SENSOR CHIP VERSION */
#define MC501CB_SENSOR_ID                       0x0062
#define MC501CC_SENSOR_ID                       0x0074
#define MC501CA_SENSOR_ID                       0x0011

#define MT9P012_SENSOR_ID                       0x2801
#define MT9P012_MIPI_SENSOR_ID                  0x2801
#define MT9P013_SENSOR_ID                       0x2803
#define MT9P015_SENSOR_ID                       0x2803
#define MT9T013_SENSOR_ID                       0x2600
#define MT9D112_SENSOR_ID                       0x1580
#define MT9D113_SENSOR_ID                       0x2580
#define MT9T113_SENSOR_ID						0x4680
#define MT9P111_SENSOR_ID                       0x2880
#define BF3703_SENSOR_ID                        0x3703
#define NOON200PC51_SENSOR_ID                   0x006C
#define NOON010PC30_SENSOR_ID                   0x0086

#define OV5642_MIPI_SENSOR_ID                   0x5642
#define OV5642_SENSOR_ID                        0x5642
#define OV5640_SENSOR_ID                        0x5640
#define OV5650_SENSOR_ID                        0x5651
#define OV5650_MIPI_SENSOR_ID                        0x5651
#define OV3640_SENSOR_ID                        0x364C
#define OV3647_SENSOR_ID                        0x364A
#define OV2659_SENSOR_ID                        0x2656
#define OV2655_SENSOR_ID                        0x2656
#define OV2650_SENSOR_ID                        0x2652
#define OV2640_SENSOR_ID                        0x2642
#define OV9665_SENSOR_ID                        0x9663
#define OV7675_SENSOR_ID                        0x7673
#define OV7670_SENSOR_ID                        0x7673
#define OV7690_SENSOR_ID                        0x7691

#define SID020A_SENSOR_ID                       0x12B4
#define SIV100B_SENSOR_ID                       0x0C11
#define SIV120B_SENSOR_ID                       0x0012
#define SIM120C_SENSOR_ID                       0x0012
#define SID130B_SENSOR_ID                       0x001b
#define SIC110A_SENSOR_ID                       0x000D

#define S5KA3DFX_SENSOR_ID                      0x00AB
#define S5K5BAFX_SENSOR_ID                      0x05BA
#define S5K3E2FX_SENSOR_ID                      0x3E2F
#define S5K5CAGA_SENSOR_ID                      0x05CA

#define HI251_SENSOR_ID                         0x0084
#define HI253_SENSOR_ID                         0x0086
#define GT2005_SENSOR_ID                         0x5138

#define GC0308_SENSOR_ID                        0x009B
#define GC0307_SENSOR_ID                        0x0099
#define GC0329_SENSOR_ID                        0x00C0
#define MT9D115_SENSOR_ID                       0x2580
#define HI704_SENSOR_ID                         0x0096
#define PAS6327_SENSOR_ID						0x6325
#define SIV121D_SENSOR_ID                       0x00DE

/* Serial Sensor (SPI Interface) */
#define SIC320A_SERIAL_SENSOR_ID				0x0011
#define GC6113_SERIAL_SENSOR_ID					0x00B8
#define GC6123_SERIAL_SENSOR_ID					0x00B9
#define GC0310_SERIAL_SENSOR_ID					0xA310
#define HM0155_SERIAL_SENSOR_ID					0x1055
#define PAS6180_SERIAL_SENSOR_ID				0x6179
#define HIQD1_SERIAL_SENSOR_ID					0x00B2
#define ET8EV3_MIPI_SENSOR_ID						0x1000


/* sensor id definition */
#define OV7660_OMNIVISION       { 101, CMOS_SENSOR }
#define OV9650_OMNIVISION       { 102, CMOS_SENSOR }
#define MT9MX11_MICRON          { 103, CMOS_SENSOR }
#define S5K3AAEA_SAMSUNG        { 104, CMOS_SENSOR }
#define PO3030K_PIXELPLUS       { 105, CMOS_SENSOR }
#define PO3130D_PIXELPLUS       { 106, CMOS_SENSOR }
#define HV7131RP_HYNIX          { 107, CMOS_SENSOR }
#define NOON130PC20_SILICONFILE { 108, CMOS_SENSOR }
#define MT9D011_MICRON          { 109, CMOS_SENSOR }
#define S5K3BAFB_SAMSUNG        { 110, CMOS_SENSOR }
#define OV2630_OMNIVISION       { 111, CMOS_SENSOR }
#define NOON200PC11_SILICONFILE { 112, CMOS_SENSOR }
#define S5K83AFX_SAMSUNG        { 113, CMOS_SENSOR }
#define OM6802_PHILIPS          { 114, CMOS_SENSOR }
#define S5K53BEX_SAMSUNG        { 115, CMOS_SENSOR }
#define OV7670_OMNIVISION       { 116, CMOS_SENSOR }
#define OV9655_OMNIVISION       { 117, CMOS_SENSOR }
#define OV3630_OMNIVISION       { 118, CMOS_SENSOR }
#define NOON200PC20_SILICONFILE { 119, CMOS_SENSOR }
#define OV2640_OMNIVISION       { 120, CMOS_SENSOR }
#define MC501CA_MAGNACHIP       { 121, CMOS_SENSOR }
#define MT9T012_MICRON          { 122, CMOS_SENSOR }
#define MT9V112_MICRON          { 123, CMOS_SENSOR }
#define ET8EF2_TOSHIBA          { 124, CMOS_SENSOR }
#define ET8EE6_TOSHIBA          { 125, CMOS_SENSOR }
#define S5K4BAFX_SAMSUNG        { 126, CMOS_SENSOR }
#define OV3640_OMNIVISION       { 127, CMOS_SENSOR }
#define MT9P012_MICRON          { 128, CMOS_SENSOR }
#define OV2650_OMNIVISION       { 129, CMOS_SENSOR }
#define RJ53S1BA0C_SHARP        { 130, CMOS_SENSOR }
#define MT9T013_MICRON          { 131, CMOS_SENSOR }
#define SID020A_SET             { 132, CMOS_SENSOR }
#define MO4020_MOBIEN           { 133, CMOS_SENSOR }
#define OV3647_OMNIVISION       { 134, CMOS_SENSOR }
#define S5K3E2FX_SAMSUNG        { 135, CMOS_SENSOR }
#define MT9DX12_MICRON          { 136, CMOS_SENSOR }
#define MT9M113_MICRON          { 137, CMOS_SENSOR }
#define PO6030K_PIXELPLUS       { 138, CMOS_SENSOR }
#define PS6200K_PIXELPLUS       { 139, CMOS_SENSOR }
#define NOON200PC51_SILICONFILE { 140, CMOS_SENSOR }
#define NOON200PC40_SILICONFILE { 141, CMOS_SENSOR }
#define S5K4B2FX_SAMSUNG        { 142, CMOS_SENSOR }
#define OV5630_OMNIVISION       { 143, CMOS_SENSOR }
#define IMX058_SONY             { 144, CMOS_SENSOR }
#define OV2655_OMNIVISION       { 145, CMOS_SENSOR }
#define MT9P013_MICRON          { 146, CMOS_SENSOR }
#define MT9P015_MICRON          { 147, CMOS_SENSOR }
#define OV5642_OMNIVISION       { 148, CMOS_SENSOR } 
#define ET8EV3_MICRON           { 149, CMOS_SENSOR } // danbo add for ET8EV3
#define OV5650_OMNIVISION       { 150, CMOS_SENSOR } 
#define OV5650_MIPI_OMNIVISION  { 151, CMOS_SENSOR } 
#define SIV121D_SET                 { 152, CMOS_SENSOR } 

#define ADD_SENSOR(id, prefix_name, SensorIdx)\
{\
  id,\
  ##prefix_name##SensorFunc,\
  SensorIdx,\
}

extern IMAGE_SENSOR_LIST_STRUCT SensorList[MAX_SENSOR_SUPPORT_NUMBER + 1];

MM_ERROR_CODE_ENUM GetSensorInitFunc(P_IMAGE_SENSOR_LIST_STRUCT *pSensorList);

/* ------------------------ Camera HW API ------------------------ */
void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
void CamGetHWInfo(IMAGE_SENSOR_INDEX_ENUM Idx, P_IMAGE_SENSOR_HW_DEPENDENT_STRUCT Info);
void CisModulePowerOn(IMAGE_SENSOR_INDEX_ENUM Idx, kal_bool On);
void FlashlightPowerOn(IMAGE_SENSOR_INDEX_ENUM Idx, kal_bool On);


#endif /* _IMAGE_SENSOR_H */

