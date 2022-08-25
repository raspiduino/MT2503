/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   Capacitive_TP_Goodix_GT818.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#define CTP_SLAVE_ADDR            0xBA
#define CTP_CONFIG_REG_BASE       0x6A2
#define CTP_CONFIG_FPS_REG        0x6DB
#define CTP_TOUCH_INFO_REG_BASE   0x712
#define CTP_POINT_INFO_REG_BASE   0x722
#define CTP_VERSION_INFO_REG      0x713
#define CTP_POWER_MODE_REG        0x692
#define CTP_HANDSHAKING_START_REG 0xFFF
#define CTP_HANDSHAKING_END_REG   0x8000
#define CTP_SOFT_RESET_MODE       0x01
#define CTP_POINT_INFO_LEN        8
#define TPD_MAX_POINTS            5
#define MAX_TRANSACTION_LENGTH    8
#define I2C_DEVICE_ADDRESS_LEN    2
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

#define TPD_PROXIMITY_WORK_REG_BASE   0x920
#define TPD_PROXIMITY_SAMPLE_REG      0xA88
#define TPD_PROXIMITY_BASE_REG        0xAD8
#define TPD_LARGE_OBJECT_DETECT_REG   0x71D
#define CTP_STAT_NUMBER_TOUCH     0xF
#define GPIO_CTP_INT_PIN          gpio_ctp_eint_pin
#define GPIO_CTP_SHUTDN_PIN       gpio_ctp_reset_pin
#define GPIO_CTP_EINT_NO          4

typedef struct 
{
    kal_uint8 vendor_id_1;
    kal_uint8 vendor_id_2;
    kal_uint8 product_id_1;
    kal_uint8 product_id_2;
    kal_uint8 version_1;
    kal_uint8 version_2;
} ctp_info_t;
