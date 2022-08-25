/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * Filename:
 * ---------
 * lcm_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for LCM interface driver.
 *
 * Author:
 * -------
 * -------
 *------------------------------------------------------------------------------
 * -------
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 07 17 2012 haitao.shang
 * removed!
 * .
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 01 10 2012 haitao.shang
 * removed!
 * .
 *
 * 11 29 2011 haitao.shang
 * removed!
 * .
 *
 * 08 29 2011 bin.han
 * removed!
 * .
 *
 * 07 21 2011 bin.han
 * removed!
 * .
 *
 * 07 08 2011 tianshu.qiu
 * removed!
 * .
 *
 * 06 08 2011 tianshu.qiu
 * removed!
 * .
 *
 * 05 27 2011 bin.han
 * removed!
 * .
 *
 * 03 10 2011 chelun.tsai
 * removed!
 * modify attribute.
 *
 * 03 08 2011 ct.fang
 * removed!
 * .
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * .
 *
 * 01 20 2011 sophie.chen
 * removed!
 * .
 *
 *******************************************************************************/
#ifndef __LCM_IF_H__
#define __LCM_IF_H__

#include "kal_general_types.h"


/* definition of LCM data outptu format */
#define LCM_8BIT_8_BPP_RGB332_1     0x00  /* RRRGGBB */
#define LCM_8BIT_8_BPP_RGB332_2     0x01  /* BBGGGRR */
#define LCM_8BIT_12_BPP_RGB444_1    0x08  /* RRRRGGGG, BBBBRRRR, GGGGBBBB */
#define LCM_8BIT_12_BPP_RGB444_2    0x0B  /* GGGGRRRR, RRRRBBBB, BBBBGGGG */
#define LCM_8BIT_16_BPP_RGB565_1    0x10  /* RRRRRGGG, GGGBBBBB */
#define LCM_8BIT_16_BPP_RGB565_2    0x12  /* GGGBBBBB, RRRRRGGG */
#define LCM_8BIT_16_BPP_BGR565_1    0x11  /* BBBBBGGG, GGGRRRRR */
#define LCM_8BIT_16_BPP_BGR565_2    0x13  /* GGGRRRRR, BBBBBGGG */
#define LCM_8BIT_18_BPP_RGB666_1    0x18  /* RRRRRRXX, GGGGGGXX, BBBBBBXX */
#define LCM_8BIT_18_BPP_RGB666_2    0x1C  /* XXRRRRRR, XXGGGGGG, XXBBBBBB */
#define LCM_8BIT_24_BPP_RGB888_1    0x20  /* RRRRRRRR, GGGGGGGG, BBBBBBBB */
#define LCM_16BIT_8_BPP_RGB332_1    0x40  /* RRRGGGBBRRRGGGBB, MSB first*/
#define LCM_16BIT_8_BPP_RGB332_2    0x42  /* RRRGGGBBRRRGGGBB, LSB first*/
#define LCM_16BIT_8_BPP_RGB332_3    0x41  /* BBGGGRRRBBGGGRRR, MSB first */
#define LCM_16BIT_8_BPP_RGB332_4    0x43  /* BBGGGRRRBBGGGRRR, LSB first */
#define LCM_16BIT_12_BPP_RGB444_1   0x4C  /* XXXXRRRRGGGGBBBB */
#define LCM_16BIT_12_BPP_RGB444_2   0x4D  /* XXXXBBBBGGGGRRRR */
#define LCM_16BIT_12_BPP_RGB444_3   0x48  /* RRRRGGGGBBBBXXXX */
#define LCM_16BIT_12_BPP_RGB444_4   0x49  /* BBBBGGGGRRRRXXXX */
#define LCM_16BIT_16_BPP_RGB565_1   0x50  /* RRRRRGGGGGGBBBBB */
#define LCM_16BIT_16_BPP_RGB565_2   0x52  /* GGGBBBBBRRRRRGGG */
#define LCM_16BIT_16_BPP_BGR565_1   0x51  /* BBBBBGGGGGGRRRRR */
#define LCM_16BIT_16_BPP_BGR565_2   0x53  /* GGGRRRRRBBBBBGGG */
#define LCM_16BIT_18_BPP_RGB666_1   0x5C  /* XXXXRRRRRRGGGGGG, XXXXBBBBBBRRRRRR, XXXXGGGGGGBBBBBB */
#define LCM_16BIT_18_BPP_RGB666_2   0x5F  /* XXXXGGGGGGRRRRRR, XXXXRRRRRRBBBBBB, XXXXBBBBBBGGGGGG */
#define LCM_16BIT_18_BPP_RGB666_3   0x58  /* RRRRRRGGGGGGXXXX, BBBBBBRRRRRRXXXX, GGGGGGBBBBBBXXXX */
#define LCM_16BIT_18_BPP_RGB666_4   0x5B  /* GGGGGGRRRRRRXXXX, RRRRRRBBBBBBXXXX, BBBBBBGGGGGGXXXX */
#define LCM_16BIT_24_BPP_RGB888_1   0x60  /* RRRRRRRRGGGGGGGG, BBBBBBBBRRRRRRRR, GGGGGGGGBBBBBBBB */
#define LCM_16BIT_24_BPP_RGB888_2   0x63  /* GGGGGGGGRRRRRRRR, RRRRRRRRBBBBBBBB, BBBBBBBBGGGGGGGG */

#define LCM_9BIT_8_BPP_RGB332_1     0x80  /* RRRGGGBBX */
#define LCM_9BIT_8_BPP_RGB332_2     0x81  /* BBGGGRRRX */
#define LCM_9BIT_12_BPP_RGB444_1    0x88  /* RRRRGGGGX, BBBBRRRRX, GGGGBBBBX */
#define LCM_9BIT_12_BPP_RGB444_2    0x8B  /* GGGGRRRRX, RRRRBBBBX, BBBBGGGGX */
#define LCM_9BIT_16_BPP_RGB565_1    0x90  /* RRRRRGGGX, GGGBBBBBX */
#define LCM_9BIT_16_BPP_RGB565_2    0x93  /* GGGRRRRRX, BBBBBGGGX */
#define LCM_9BIT_18_BPP_RGB666_1    0x98  /* RRRRRRGGG, GGGBBBBBB */
#define LCM_9BIT_18_BPP_RGB666_2    0x9B  /* GGGRRRRRR, BBBBBBGGG */
#define LCM_9BIT_24_BPP_RGB888_1    0xA0  /* RRRRRRRRX, GGGGGGGGX, BBBBBBBBX */
#define LCM_18BIT_8_BPP_RGB332_1    0xC0  /* RRRGGGBBRRRGGGBBXX, MSB first */
#define LCM_18BIT_8_BPP_RGB332_2    0xC2  /* RRRGGGBBRRRGGGBBXX, LSB first */
#define LCM_18BIT_8_BPP_RGB332_3    0xC1  /* BBGGGRRRBBGGGRRRXX, MSB first */
#define LCM_18BIT_8_BPP_RGB332_4    0xC3  /* BBGGGRRRBBGGGRRRXX, LSB first */
#define LCM_18BIT_12_BPP_RGB444_1   0xCC  /* XXXXXXRRRRGGGGBBBB */
#define LCM_18BIT_12_BPP_RGB444_2   0xCD  /* XXXXXXBBBBGGGGRRRR */
#define LCM_18BIT_12_BPP_RGB444_3   0xC8  /* RRRRGGGGBBBBXXXXXX */
#define LCM_18BIT_12_BPP_RGB444_4   0xC9  /* BBBBGGGGRRRRXXXXXX */
#define LCM_18BIT_16_BPP_RGB565_1   0xD0  /* RRRRRGGGGGGBBBBBXX */
#define LCM_18BIT_16_BPP_RGB565_2   0xD1  /* BBBBBGGGGGGRRRRRXX */
#define LCM_18BIT_18_BPP_RGB666_1   0xD8  /* RRRRRRGGGGGGBBBBBB */
#define LCM_18BIT_18_BPP_RGB666_2   0xD9  /* BBBBBBGGGGGGRRRRRR */
#define LCM_18BIT_24_BPP_RGB888_1   0xE0  /* RRRRRRRRGGGGGGGGXX, BBBBBBBBRRRRRRRRXX, GGGGGGGGBBBBBBBBXX */
#define LCM_18BIT_24_BPP_RGB888_2   0xE3  /* GGGGGGGGRRRRRRRRXX, RRRRRRRRBBBBBBBBXX, BBBBBBBBGGGGGGGGXX */

///TODO for 24 bit interface

/// Engineering mode
typedef enum {
   lcd_Bais_func,
   lcd_Bias_func = lcd_Bais_func,       ///for spell correction
   lcd_Contrast_func,
   lcd_LineRate_func,
   lcd_Temperature_Compensation_func
} lcd_func_type;

typedef enum
{
   LCM_IOCTRL_OK,
   LCM_IOCTRL_FAIL,
   LCM_IOCTRL_NOT_SUPPORT
}LCM_IOCTRL_STATUS_ENUM;

typedef enum
{
   LCM_TE_RAISING_EDGE = 0,
   LCM_TE_FAILING_EDGE = 1,
   
   LCM_TE_RISING_EDGE = 0,  ///for spell correction
   LCM_TE_FALLING_EDGE = 1
}LCM_TE_ATTRIB_ENUM;


typedef enum
{
  LCM_TE_NONE = 0,
  LCM_TE_VSYNC_MODE = 1,
  LCM_TE_VHSYNC_MODE = 2,
  LCM_TE_RESERVERD_FOR_32BIT = 0x7FFFFFFF
}LCM_TE_SYNC_MODE;

typedef enum
{
   LCM_IOCTRL_QUERY__FRAME_RATE, /**< Storage type: kal_uint32
                                      This attribute is mandatory.
                                      Query the frame rate of LCM HW.
                                      Return status: LCM_IOCTRL_OK: when support.
                                                     LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                      */

  LCM_IOCTRL_SET__FRAME_RATE,   /**< Storage type: kal_uint32
                                      This attribute is optional.
                                      Set the frame rate of LCM HW.
                                      Return status: LCM_IOCTRL_OK: when support.
                                                     LCM_IOCTRL_NOT_SUPPORT: when not support.
                                      */

   LCM_IOCTRL_QUERY__FRAME_MARKER, /**< Storage type: kal_uint32
                                      This attribute is mandatory.
                                      Query the curremt frame marker of LCM HW.
                                      Return status: LCM_IOCTRL_OK: when support.
                                                     LCM_IOCTRL_NOT_SUPPORT: when not support.
                                      */

   LCM_IOCTRL_SET__FRAME_MARKER,   /**< Storage type: kal_uint32
                                      This attribute is mandatory when frame marker mode is support.
                                      Set the frame marker of LCM HW.
                                      Return status: LCM_IOCTRL_OK: when support.
                                                     LCM_IOCTRL_NOT_SUPPORT: when not support.
                                      */

   LCM_IOCTRL_QUERY__SUPPORT_H_V_SIGNAL_FUNC, /**< Storage type: kal_uint32
                                                 This attribute is mandatory.
                                                 Query the capability of VH-Sync signal for LCM HW.
                                                 Return status: LCM_IOCTRL_OK: when support.
                                                                LCM_IOCTRL_NOT_SUPPORT: when not support.
                                                 */


   LCM_IOCTRL_QUERY__SUPPORT_V_PULSE_WIDTH, /**< Storage type: kal_uint32
                                                 This attribute is mandatory when VH-Sync signal is support.
                                                 Query the V-Sync pulse width in unit:us of LCM HW.
                                                 Return status: LCM_IOCTRL_OK: when support.
                                                                LCM_IOCTRL_NOT_SUPPORT: when not support.
                                                 */

   LCM_IOCTRL_QUERY__SUPPORT_H_PULSE_WIDTH, /**< Storage type: kal_uint32
                                                 This attribute is optional.
                                                 Query the H-Sync pulse width in unit:us of LCM HW.
                                                 Return status: LCM_IOCTRL_OK: when support.
                                                                LCM_IOCTRL_NOT_SUPPORT: when not support.

                                                 */

   LCM_IOCTRL_QUERY__BACK_PORCH,  /**< Storage type: kal_uint32
                                       This attribute is mandatory.
                                       Query the back porch of LCM HW.
                                       Return status: LCM_IOCTRL_OK: when support.
                                                      LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                       */

   LCM_IOCTRL_QUERY__FRONT_PORCH, /**< Storage type: kal_uint32
                                       This attribute is optional.
                                       Query the front porch of LCM HW.
                                       Return status: LCM_IOCTRL_OK: when support.
                                                      LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                       */

   LCM_IOCTRL_SET__BACK_PORCH,  /**< Storage type: kal_uint32
                                     This attribute is optional.
                                     Set the back porch of LCM HW.
                                     Return status: LCM_IOCTRL_OK: when support.
                                                    LCM_IOCTRL_NOT_SUPPORT: when not support.
                                     */

   LCM_IOCTRL_SET__FRONT_PORCH, /**< Storage type: kal_uint32
                                     This attribute is optional.
                                     Set the front porch of LCM HW.
                                     Return status: LCM_IOCTRL_OK: when support.
                                                    LCM_IOCTRL_NOT_SUPPORT: when not support.
                                     */

   LCM_IOCTRL_QUERY__TE_EDGE_ATTRIB, /**< Storage type: LCM_TE_ATTRIB_ENUM
                                          This attribute is mandatory.
                                          Query the detect edge <raising/falling> of Vsync signal.
                                          Return status: LCM_IOCTRL_OK: when support.
                                                         LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                          */

   LCM_IOCTRL_QUERY__SUPPORT_READBACK_FUNC, /**< Storage type: NA
                                                 This attribute is optional.
                                                 Query the capability of LCM readback function.
                                                 Return status: LCM_IOCTRL_OK: when support.
                                                                LCM_IOCTRL_NOT_SUPPORT: when not support.
                                                 */

   LCM_IOCTRL_QUERY__SCANLINE_REG,  /**< Storage type: NA
                                         This attribute is optional.
                                         Query the capability of LCM scanline register.
                                         Return status: LCM_IOCTRL_OK: when support.
                                                       LCM_IOCTRL_NOT_SUPPORT: when not support.
                                         */

   LCM_IOCTRL_QUERY__IF_CS_NUMBER, /**< Storage type: LCD_IF_ENUM
                                        This attribute is mandatory.
                                        Query the chip select occupied by the LCM.
                                        Return status: LCM_IOCTRL_OK: when support.
                                                       LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                        */

   LCM_IOCTRL_QUERY__IF_CS_NUMBER_OF_SUBLCD, /**< Storage type: LCD_IF_ENUM
                                                  This attribute is mandatory.
                                                  Query the chip select occupied by the Sub-LCM.
                                                  Return status: LCM_IOCTRL_OK: when support.
                                                                 LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                                  */

   LCM_IOCTRL_QUERY__LCM_MODE_COUNT, /**< Storage type: kal_uint32
                                          This attribute is optional.
                                          Query the support mode count of the LCM.
                                          Return status: LCM_IOCTRL_OK: when support.
                                                         LCM_IOCTRL_NOT_SUPPORT: when not support.
                                          */

   LCM_IOCTRL_QUERY__LCM_MODE, /**< Storage type: WFD_PORT_MODE[count]
                                    This attribute is optional.
                                    Query the support modes of the LCM.
                                    Return status: LCM_IOCTRL_OK: when support.
                                                   LCM_IOCTRL_NOT_SUPPORT: when not support.
                                    */

   LCM_IOCTRL_QUERY__LCM_WIDTH, /**< Storage type: kal_uint32
                                     This attribute is mandatory.
                                     Query the real LCM width.
                                     Return status: LCM_IOCTRL_OK: when support.
                                                    LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                     */

   LCM_IOCTRL_QUERY__LCM_HEIGHT,/**< Storage type: kal_uint32
                                     This attribute is mandatory.
                                     Query the real LCM height.
                                     Return status: LCM_IOCTRL_OK: when support.
                                                    LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                     */

   LCM_IOCTRL_QUERY__FLIP_MIRROR, /**< Storage type: kal_uint32
                                     This attribute is optional.
                                     Query the capability of LCM flip and mirror.
                                     Return status: LCM_IOCTRL_OK: when support.
                                                    LCM_IOCTRL_NOT_SUPPORT: when not support.
                                     */

   LCM_IOCTRL_QUERY__ROTATION, /**< Storage type: kal_uint32
                                    This attribute is optional.
                                    Query the capability of LCM rotation.
                                    Return status: LCM_IOCTRL_OK: when support.
                                                   LCM_IOCTRL_NOT_SUPPORT: when not support.
                                    */

   LCM_IOCTRL_QUERY__SYNC_MODE, /**< Storage type: LCM_TE_SYNC_MODE
                                    This attribute is mandatory.
                                    Query the capability of LCM current sync mode.
                                    Return status: LCM_IOCTRL_OK: when support.
                                                   LCM_IOCTRL_NOT_SUPPORT: shall not happen.
                                    */

   LCM_IOCTRL_QUERY__DATA_TIMEING_SETTING, /**< Storage type: LCD_IF_TIME_PARA_T
                                                This attribute is optional.
                                                Query the timing setting for data transision.
                                                Return status: LCM_IOCTRL_OK: when support.
                                                LCM_IOCTRL_NOT_SUPPORT: LCD driver will use
                                                the timing setting after calling init_lcd_interface(~).
                                           */

   LCM_IOCTRL_QUERY__CMD_TIMEING_SETTING, /**< Storage type: LCD_IF_TIME_PARA_T
                                                This attribute is optional.
                                                Query the timing setting for command transision.
                                                Return status: LCM_IOCTRL_OK: when support.
                                                LCM_IOCTRL_NOT_SUPPORT: LCD driver will use
                                                the timing setting after calling init_lcd_interface(~).
                                           */

   LCM_IOCTRL_QUERY__LCD_PPI, /**< storage type: kal_uint32
                                   This attribute is mandatory. 
                                   Query the PPI (pixel per inch) of LCD panel. 
                                   Return status: LCM_IOCTRL_OK: when support. 
                                                  LCM_IOCTRL_NOT_SUPPORT: shall not happen. 
                               */
   LCM_IOCTRL_CABC, /**< storage type: LCM_CABC_INFO_STRUCT*
                         LCM CABC feature control.
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */
   LCM_IOCTRL_QUERY_TEAR_CONTROL_FOR_ONE_TE_MODE, /**< storage type: NULL
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */                               
   LCM_IOCTRL_CABC__SET_BRIGHTNESS,

   LCM_IOCTL_ESD_CHECK, /**< storage type: LCM_ESD_INFO_STRUCT*
                         LCM ESD feature control.
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */
   
   LCM_IOCTL_ESD_RESET,/**< storage type: NONE
                         LCM ESD feature control.
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */
   LCM_IOCTRL_QUERY_DATA_TRANSFER_COMPLETE_CALLBACK,/**< storage type: NONE
			    This attribute is optional.
                         QUERY_DATA_TRANSFER_COMPLETE_CALLBACK for LCM.
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */
   LCM_IOCTRL_EXECUTE_DATA_TRANSFER_COMPLETE_CALLBACK,/**< storage type: LCD_IF_ENUM
			    This attribute is optional.
                         EXECUTE_DATA_TRANSFER_COMPLETE_CALLBACK for LCM.
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */                               
#ifdef DRV_LCD_3D_MODE_SUPPORT
   LCM_IOCTRL_SET_3D_PANEL_WORKING_MODE, /**< storage type: NULL
                         Return status: LCM_IOCTRL_OK: Operation success
                                        Others: Operation fail
                               */   	
#endif
   LCM_IOCTRL_RSVD = 0xFF
}LCM_IOCTRL_ID_ENUM;
#ifdef DRV_LCD_3D_MODE_SUPPORT
typedef enum
{
    LCM_3D_MODE_OFF = 0,//meas:set LCM as 2D normal mode
    LCM_3D_MODE_PORTRAIT,//means:set LCM as 3D portrait mode
    LCM_3D_MODE_LANDSCAPE,//means:set LCM as 3D landscape mode
    LCM_3D_MODE_INVALID
} LCM_3D_Mode_Enum;
#endif


typedef enum
{
   LCD_IF_PARALLEL_0 = 0,
   LCD_IF_PARALLEL_1,
   LCD_IF_PARALLEL_2,
   LCD_IF_SERIAL_0,
   LCD_IF_SERIAL_1,
   LCD_IF_SERIAL_2
}LCD_IF_ENUM;


typedef struct
{
  kal_uint32 rd_hold_time;
  kal_uint32 rd_setup_time;
  kal_uint32 rd_latency_time;
  kal_uint32 wt_hold_time;
  kal_uint32 wt_setup_time;
  kal_uint32 wt_wait_time;
  kal_uint32 if_period;
  kal_uint32 __if_reg_1; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_2; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_3; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_4; ///< !!! Do NOT modify, lcd interface manager internal usage
}LCD_PARALLEL_IF_TIME_PARA_T;


typedef struct
{
  kal_uint32 rd_low;
  kal_uint32 rd_high;
  kal_uint32 wt_low;
  kal_uint32 wt_high;
  kal_uint32 if_period;

  kal_uint32 __if_reg_1; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_2; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_3; ///< !!! Do NOT modify, lcd interface manager internal usage
  kal_uint32 __if_reg_4; ///< !!! Do NOT modify, lcd interface manager internal usage
}LCD_SERIAL_IF_TIME_PARA_T;


typedef struct
{
   kal_bool parallel_if; ///<   DBI parallel, or DBI serial ...
   kal_uint32 if_cs_no; ///<   chip-select number for DBI interface
   union
   {
      LCD_PARALLEL_IF_TIME_PARA_T  dbi_parallel_if;
      LCD_SERIAL_IF_TIME_PARA_T    dbi_serial_if;
   }u;///< according to if_type, user must use collect union member.  DPI, DSI is reserved for future expansion
}LCD_IF_TIME_PARA_T;

typedef enum
{
    LCM_CABC_MODE_OFF = 0,
    LCM_CABC_MODE_UI,
    LCM_CABC_MODE_STILL,
    LCM_CABC_MODE_MOVING,
    LCM_CABC_MODE_INVALID
} LCM_CABC_MODE_ENUM;

typedef enum
{
    LCM_CABC_TYPE__NONE = 0,
    LCM_CABC_TYPE__QUERY_SUPPORT,
    LCM_CABC_TYPE__QUERY_MODE,
    LCM_CABC_TYPE__SET_MODE_OFF,
    LCM_CABC_TYPE__SET_MODE_UI,
    LCM_CABC_TYPE__SET_MODE_STILL,
    LCM_CABC_TYPE__SET_MODE_MOVING,
    LCM_CABC_TYPE__MAX
} LCM_CABC_TYPE_ENUM;

typedef struct
{
    kal_uint32 Value;
} LCM_COMM_DATA_STRUCT, *P_LCM_COMM_DATA_STRUCT;

typedef struct
{
    LCM_CABC_TYPE_ENUM Type;
    void* FeatureValue;
} LCM_CABC_INFO_STRUCT, *P_LCM_CABC_INFO_STRUCT;

typedef struct
{
    kal_bool bEsdHappened;
} LCM_ESD_INFO_STRUCT, *P_LCM_ESD_INFO_STRUCT;


typedef struct
{
   void (* Init)(kal_uint32 background, void **buf_addr);
   void (* TurnOnPower)(kal_bool on);
   void (* SetBrightLevel)(kal_uint8 level);
   void (* TurnOnScreen)(kal_bool on);
   void (* BlockWrite)(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy);
   void (* GetSize)(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height);
   void (* EnterSleepMode)(void);
   void (* ExitSleepMode)(void);
   void (* TurnOnPartialDisplay) (kal_uint16 start_page,kal_uint16 end_page);
   void (* TurnOffPartialDisplay) (void);
   kal_uint8 (*GetPartialDisplayAlignment) (void);
   /*Engineering mode*/
   kal_uint8 (* GetEngineeringModeParamNumber)(lcd_func_type type);
   void (* SetBias)(kal_uint8 *bias);
   void (* SetContrast)(kal_uint8 *contrast);
   void (* SetLineRate)(kal_uint8 *linerate);
   void (* SetTemperatureCompensate)(kal_uint8 *compensate);
#ifdef __LCD_ESD_RECOVERY__
   kal_bool (* CheckESD)(void);
#endif
#ifdef LCM_ROTATE_SUPPORT
   void (* SetRotation)(kal_uint8 rotate_value);
#endif
#if (defined(__DIRECT_SENSOR_SUPPORT__))
   void (* IssueUpdateCMD)(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy);
#endif
#ifdef LQT_SUPPORT
   void (*LCD_gamma_test)(kal_uint8 level, kal_uint8 color);
   void (*LCD_flicker_test)(kal_uint8 level);
#endif
   void (* SetFrameMarker)(kal_uint32 frame_marker);
   LCM_IOCTRL_STATUS_ENUM (*IOCTRL)(LCM_IOCTRL_ID_ENUM ID, void* Parameters);

}LCD_Funcs;

// for em only
kal_uint8 lcd_get_parameter(kal_uint8 lcd_id,lcd_func_type type);

extern volatile LCD_Funcs  *MainLCD;
extern volatile LCD_Funcs  *SubLCD;

#endif

