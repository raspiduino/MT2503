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
 *  Swatch.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the idle Swatch screen application.
 *
 * Author:
 * -------
 *  Renxiao Zeng (mtk71448)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

#if defined(__MMI_WEARABLE_DEVICE__)

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_IDLE_SWATCH" name="STR_ID_IDLE_SWATCH">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>
    
#ifdef __CUI_SWATCH_SUPPORT__
    <MEMORY heap="MMI_IDLE_SWATCH_MEM_SIZE" inc="IdleMemCfg.h" />


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_CUI_SWATCH" />
    <SCREEN id="SCR_ID_CUI_SWATCH" />
#endif  //__CUI_SWATCH_SUPPORT__
    <SCREEN id="GRP_ID_SWATCH_SETTING" />
    <SCREEN id="SCR_ID_SWATCH_SETTING" />



    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_IDLE_SWATCH"/>
    <STRING id="STR_ID_IDLE_SWATCH_STEP"/>
    <STRING id="STR_ID_IDLE_SWATCH_CALORIE"/>    



    <!-- Image Resource Area--------------------------------------------------->
    #define IDLE_SWATCH_ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Swatch\\\\"
    <!-- Analog 1 -->
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_CLOCK_BG">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\clock_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_HOUR_HAND">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\hour_hand.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_MINUTE_HAND">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\minute_hand.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_SECOND_HAND">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\second_hand.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_CALORIES">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\calories.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_ANALOG_1_STEPS">IDLE_SWATCH_ROOT_PATH"\\\\analog_1\\\\steps.png"</IMAGE>

    
    <!-- Digital 1 -->
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_CLOCK_BG">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\clock_bg.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_AM">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\am.png"</IMAGE>    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_AM_CN">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\am_cn.png"</IMAGE>   
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_PM">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\pm.png"</IMAGE>    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_PM_CN">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\pm_cn.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_HOUR_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\hour_num_9.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_MINUTE_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\minute_num_9.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_1_COUNT_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_1\\\\count_num_9.png"</IMAGE>
        
        
    <!-- Digital 2 -->
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_CLOCK_BG">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\clock_bg.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_AM">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\am.png"</IMAGE>    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_AM_CN">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\am_cn.png"</IMAGE>   
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_PM">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\pm.png"</IMAGE>    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_PM_CN">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\pm_cn.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_HOUR_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\hour_num_9.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_MINUTE_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\minute_num_9.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_0">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_1">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_2">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_3">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_4">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_5">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_6">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_7">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_8">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_DIGITAL_2_COUNT_NUM_9">IDLE_SWATCH_ROOT_PATH"\\\\digital_2\\\\count_num_9.png"</IMAGE>

    
    <!-- Preview -->
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_BG">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_LEFT">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_left.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_RIGHT">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_right.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_OK">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_ok.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_OK_DOWN">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_ok_down.png"</IMAGE>
    
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_1">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_1.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_2">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_2.png"</IMAGE>
    <IMAGE id="IMG_ID_IDLE_SWATCH_PREVIEW_3">IDLE_SWATCH_ROOT_PATH"\\\\preview\\\\preview_3.png"</IMAGE>

    
    
    <!----- Timer Resource Area ---- ------------------------------------------>
    <TIMER id = "IDLE_SWATCH_UPDATE_TIMER" />


    <CACHEDATA type="byte" id="NVRAM_IDLE_SWATCH_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Swatch index </DESCRIPTION>
    </CACHEDATA>

    
    <!----- Receiver Resource Area ---- ------------------------------------------>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_idle_swatch_event_handler"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_idle_swatch_event_handler"/>
    
</APP>
        
#endif  //defined(__MMI_WEARABLE_DEVICE__)

