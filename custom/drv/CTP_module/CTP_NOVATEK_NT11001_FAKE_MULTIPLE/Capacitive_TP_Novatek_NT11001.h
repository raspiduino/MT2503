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
 *   Capacitive_TP_Novatek_NT11001.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/


#define CTP_SLAVE_ADDR	    0x02

//Novatek captouch config
#define CTP_MOVE_ID  0x10

#define CTP_ROTATE_ID  0x40
#define CTP_ROTATE_CW 0x01
#define CTP_ROTATE_CCW 0x81

//#define SLIDE_ID 0x11
//#define SLIDE_RIGHT 0x01
//#define SLIDE_LEFT 0x81
//#define SLIDE_UP 0x09
//#define SLIDE_DOWN 0x89

//#define CLICK_ID 0x12
//#define DOUBLE_CLICK_ID 0x12

#define CTP_ZOOM_ID  0x20
#define CTP_ZOOM_IN  0x01
#define CTP_ZOOM_OUT 0x81

#define ENABLE_SENSOR 1<<7
#define DISABLE_SENSOR 0<<7
#define ENABLE_DOZE  1<<6
#define DISABLE_DOZE 0<<6

#define NOVATEK_OPRE_1 0x0C
#define NOVATEK_OPRE_2 0x0D
#define NOVATEK_OPRE_3 0x0E
#define NOVATEK_SW_VERSION 0x0F

#define THRESHOLD_VALUE 0x01

#define IDLE_TIME_MASK 0x70


// Interrupt type
#define INT_INVALID			0X00
#define INT_SINGLE_TOUCH	0X01
#define INT_MULTI_TOUCH	0X02
#define INT_GESTURE		0X04


typedef struct
{   
   kal_uint32 mode;
}CTP_device_mode_struct;

typedef struct
{   
	kal_uint32 start_offset;
	kal_uint32 write_flash_pointer;
	kal_uint32 read_flash_pointer;
	kal_uint32 value;
}CTP_firmware_struct;
