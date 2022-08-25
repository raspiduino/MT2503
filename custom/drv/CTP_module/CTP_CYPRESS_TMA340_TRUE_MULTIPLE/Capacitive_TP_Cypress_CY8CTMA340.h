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
 *   Capacitive_TP_Cypress_CY8CTMA340.h
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver header file
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
#include "dcl.h"
#include "touch_panel_custom.h"

#define CTP_SLAVE_ADDR	    0xCE

//Controller parameter getting/setting flag
#define CTP_RESOLUTION 0x1
#define CTP_THRESHOLD 0x2
#define CTP_IDLE_INTERVAL 0x4
#define CTP_SLEEP_INTERVAL 0x8
//#define CTP_DATA_MODE 0x10
//#define CTP_GESTURE_DISTANCE 0x20
//#define CTP_CHANGE_STATE_DELAY 0x40
//#define CTP_CALIBRATION 0x80

//Controller Mode
#define CTP_NORMAL_OPERATION 0x1
#define CTP_SYSTEM_INFORMATION 0x2
#define CTP_ACTIVE_MODE 0x4
#define CTP_IDLE_MODE 0x8
#define CTP_SLEEP_MODE 0x10
#define CTP_DEBUG_MODE 0x20
#define CTP_GESTURE_DETECTION_MODE 0x40
#define CTP_MULTIPLE_POINT_MODE 0x80

#define HST_MODE_ADDR 0x0
#define HST_MODE_RESET 0x1
#define HST_MODE_NORMAL 0x0
#define HST_MODE_LOW_POWER 0x4
#define HST_MODE_DEEP_SLEEP 0x2
#define HST_MODE_SYSTEM_INFORMATION 0x10
#define HST_MODE_DATA_READ_TOGGLE   0x80

#define CID_0 0x3
#define CID_1 0x4
#define CID_2 0x5
#define UID_0 0x7
#define UID_1 0x8
#define UID_2 0x9
#define UID_3 0xA
#define UID_4 0xB
#define UID_5 0xC
#define UID_6 0xD
#define UID_7 0xE
#define BL_VERH  0xF
#define BL_VERL  0x10
#define TTS_VERH 0x11
#define TTS_VERL 0x12
#define APP_IDH  0x13
#define APP_IDL  0x14
#define APP_VERH 0x15
#define APP_VERL 0x16


#define TT_MODE_ADDR 0x1
#define TT_MODE_BUFFER_INVALID 0x20

#define TT_STAT_ADDR 0x2
#define TT_STAT_NUMBER_TOUCH 0xF

#define TOUCH1_XH_ADDR 0x3
#define TOUCH1_XL_ADDR 0x4
#define TOUCH1_YH_ADDR 0x5
#define TOUCH1_YL_ADDR 0x6
#define TOUCH1_Z_ADDR  0x7

#define TOUCH2_XH_ADDR 0x9
#define TOUCH2_XL_ADDR 0xA
#define TOUCH2_YH_ADDR 0xB
#define TOUCH2_YL_ADDR 0xC
#define TOUCH2_Z_ADDR  0xD

#define TOUCH3_XH_ADDR 0x10
#define TOUCH3_XL_ADDR 0x11
#define TOUCH3_YH_ADDR 0x12
#define TOUCH3_YL_ADDR 0x13
#define TOUCH3_Z_ADDR  0x14

#define TOUCH4_XH_ADDR 0x16
#define TOUCH4_XL_ADDR 0x17
#define TOUCH4_YH_ADDR 0x18
#define TOUCH4_YL_ADDR 0x19
#define TOUCH4_Z_ADDR  0x1A


#define CTP_BL_FILE          0
#define CTP_BL_CMD           0xFF
#define CTP_BL_EXIT          0xA5
#define CTP_BL_SECUTITY_KEY1 0x0
#define CTP_BL_SECUTITY_KEY2 0x1
#define CTP_BL_SECUTITY_KEY3 0x2
#define CTP_BL_SECUTITY_KEY4 0x3
#define CTP_BL_SECUTITY_KEY5 0x4
#define CTP_BL_SECUTITY_KEY6 0x5
#define CTP_BL_SECUTITY_KEY7 0x6
#define CTP_BL_SECUTITY_KEY8 0x7

#define ACT_INTRVL_ADDR  0x1D
#define TCH_TMOUT_ADDR  0x1E


typedef struct
{   
	kal_uint32 start_offset;
	kal_uint32 write_flash_pointer;
	kal_uint32 read_flash_pointer;
	kal_uint32 value;
}CTP_firmware_struct;
