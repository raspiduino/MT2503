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
 *   Capacitive_TP_Cypress_CY8CTMA340_defs.h
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel ISSP firmware update Driver
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef CAPACITIVE_TP_CYPRESS_CY8CTMA340_DEFS_H
#define CAPACITIVE_TP_CYPRESS_CY8CTMA340_DEFS_H

#include "Capacitive_TP_Cypress_CY8CTMA340_directives.h"

//#define CTP_FIRMWARE_PATH  L"c:\\ctp_firmware_rusklmeoxkwjadfjnklruo3"
#define CTP_FIRMWARE_FILE_NAME  "ctp_firmware_rusklmeoxkwjadfjnklruo3"
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;
#if defined(VICTOR56_DEMO_BB)
#define ctp_cypress_firmware_i2c_scl_pin       68 //can not define in drv_tool, because we use pin define to distingish HW I2C and SW I2C
#define ctp_cypress_firmware_i2c_sda_pin       69 //when firmware update need to change to SW I2C, define these 2 pin in firmware update code.
#else
#define ctp_cypress_firmware_i2c_scl_pin       52 //can not define in drv_tool, because we use pin define to distingish HW I2C and SW I2C
#define ctp_cypress_firmware_i2c_sda_pin       53 //when firmware update need to change to SW I2C, define these 2 pin in firmware update code.
#endif

#define PASS                        1
#define FAIL                        0

//  flash block is 128 bytes. Note Block-Verify Uses 64-Bytes of RAM
#define TARGET_DATABUFF_LEN         128  			
											
#ifdef CY8CTMA300
    #define NUM_BANKS               1
    #define BLOCKS_PER_BANK         256
    #define SECURITY_BYTES_PER_BANK 64
#endif
#ifdef CY8CTMA301D
    #define NUM_BANKS               1
    #define BLOCKS_PER_BANK         128
    #define SECURITY_BYTES_PER_BANK 64
#endif
#ifdef CY8CTMA300E
    #define NUM_BANKS               1
    #define BLOCKS_PER_BANK         256
    #define SECURITY_BYTES_PER_BANK 64
    #define ACTIVE_LOW_XRES
#endif
#ifdef CY8CTMA301E
    #define NUM_BANKS               1
    #define BLOCKS_PER_BANK         128
    #define SECURITY_BYTES_PER_BANK 64
    #define ACTIVE_LOW_XRES
#endif

// TRANSITION_TIMEOUT is a loop counter for a 100msec timeout when waiting for 
// a high-to-low transition. This is used in the polling loop of 
// fDetectHiLoTransition(). Each pass through the loop takes approximately 15
// usec. 100 msec is about 6740 loops. 200ms = 13480
#define TRANSITION_TIMEOUT          13480

#define XRES_CLK_DELAY              300

#endif //#define CAPACITIVE_TP_CYPRESS_CY8CTMA340_DEFS_H


