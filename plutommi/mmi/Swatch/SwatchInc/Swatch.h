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
 *  Swatch.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Swatch
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_SWATCH_H_
#define _MMI_SWATCH_H_

#include "mmi_features.h"

#ifdef __MMI_WEARABLE_DEVICE__

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gui.h"
#include "swatchgprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define __RANFOW_TUNING__

#define __RANFOW_DEBUG__
#ifdef __RANFOW_DEBUG__
#ifndef __MTK_TARGET__
#define RANFOW_TRACE(format, ...) printf((format), ##__VA_ARGS__)
#else
#define RANFOW_TRACE(...) kal_prompt_trace(MOD_MMI_COMMON_APP, __VA_ARGS__)
#endif
#else
#define RANFOW_TRACE(format, ...)
#endif

#define MMI_IDLE_SWATCH_WIDTH       (240)
#define MMI_IDLE_SWATCH_HEIGHT      (240)

//preview coordinate
#define MMI_IDLE_SWATCH_PREVIEW_BG_X                    (28)
#define MMI_IDLE_SWATCH_PREVIEW_BG_Y                    (26)
#define MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH                (185)
#define MMI_IDLE_SWATCH_PREVIEW_BG_HEIGHT               (170)
#define MMI_IDLE_SWATCH_PREVIEW_ARROW_X_OFFSET          (7)
#define MMI_IDLE_SWATCH_PREVIEW_ARROW_Y_OFFSET          (97)
#define MMI_IDLE_SWATCH_PREVIEW_ARROW_WIDTH             (16)
#define MMI_IDLE_SWATCH_PREVIEW_ARROW_HEIGHT            (30)
#define MMI_IDLE_SWATCH_PREVIEW_OK_X_OFFSET             (68)
#define MMI_IDLE_SWATCH_PREVIEW_OK_Y_OFFSET             (204)
#define MMI_IDLE_SWATCH_PREVIEW_OK_WIDTH                (104)
#define MMI_IDLE_SWATCH_PREVIEW_OK_HEIGHT               (26)
#define MMI_IDLE_SWATCH_PREVIEW_OK_THRESHOLD            (10)  //set threshold for touch
#define MMI_IDLE_SWATCH_PREVIEW_CENTER_Y                (MMI_IDLE_SWATCH_PREVIEW_ARROW_Y_OFFSET+MMI_IDLE_SWATCH_PREVIEW_ARROW_HEIGHT/2)

#define MMI_IDLE_SWATCH_ABS(x)   ((x) < 0 ? -(x):(x))

#define MMI_IDLE_SWATCH_ANALOG_UPDATE_DELAY    (1000)

#define MMI_IDLE_SWATCH_AP_NUM          (2)
#define MMI_IDLE_SWATCH_AP_NAME_MAX_LEN (20)

#define MMI_IDLE_SWATCH_AP_COUNT_MAX_NUM    (100000)
#define MMI_IDLE_SWATCH_AP_COUNT_MAX_BIT    (5)


#ifdef __MMI_TOUCH_SCREEN__
#define MMI_IDLE_SWATCH_SETTING_MOVE_THRESHOLD           (20)

#define MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE            (MMI_IDLE_SWATCH_PREVIEW_BG_WIDTH)  //this value must bigger than MMI_IDLE_SWATCH_WIDTH / 2
#if (MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE < MMI_IDLE_SWATCH_WIDTH / 2)
#error "MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE must bigger than MMI_IDLE_SWATCH_WIDTH / 2"
#endif

#define MMI_IDLE_SWATCH_SETTING_START_X_IN_MOVE          ((MMI_IDLE_SWATCH_WIDTH-MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE)/2)
#define MMI_IDLE_SWATCH_SETTING_MOVE_SWITCH_THRESHOLD    (MMI_IDLE_SWATCH_SETTING_WIDTH_IN_MOVE/3)

#define MMI_IDLE_SWATCH_SETTING_FREE_RUN_DELAY           (100)
#define MMI_IDLE_SWATCH_SETTING_FREE_RUN_SPEED           (30)
#endif  //__MMI_TOUCH_SCREEN__

/***************************************************************************** 
 * Enum
 *****************************************************************************/
typedef enum
{
    MMI_IDLE_SWATCH_UPDATE_ALL,
    MMI_IDLE_SWATCH_UPDATE_AP,
    MMI_IDLE_SWATCH_UPDATE_CLOCK
} MMI_IDLE_SWATCH_UPDATE_TYPE;

typedef enum
{
    MMI_IDLE_SWATCH_AP_STEP,
    MMI_IDLE_SWATCH_AP_CALORIE,
} MMI_IDLE_SWATCH_AP_ENUM;

typedef enum
{
    MMI_IDLE_SWATCH_CLOCK_TYPE_ANALOG,
    MMI_IDLE_SWATCH_CLOCK_TYPE_DIGITAL
} MMI_IDLE_SWATCH_CLOCK_TYPE;

typedef enum
{
    MMI_IDLE_SWATCH_AP_INFO_TYPE_IMAGE,
    MMI_IDLE_SWATCH_AP_INFO_TYPE_TEXT
} MMI_IDLE_SWATCH_AP_INFO_TYPE;

typedef enum
{
    MMI_IDLE_SWATCH_SETTING_SSP_STATE_NONE,
    MMI_IDLE_SWATCH_SETTING_SSP_STATE_HOLD,
    MMI_IDLE_SWATCH_SETTING_SSP_STATE_MOVE,
    MMI_IDLE_SWATCH_SETTING_SSP_STATE_FREE_RUN,
    MMI_IDLE_SWATCH_SETTING_SSP_STATE_RECOVER
} MMI_IDLE_SWATCH_SETTING_SSP_STATE;

typedef void (*mmi_idle_swatch_ap_update)(MMI_IDLE_SWATCH_AP_ENUM app, U32* count);

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    U16 x1;
    U16 y1;
    U16 x2;
    U16 y2;
} mmi_idle_swatch_area;

typedef struct
{
    float m[9];
} mmi_idle_swatch_matrix_struct;

typedef struct
{
    U16 bg_x, bg_y;
    U16 center_x, center_y;
    MMI_ID bg_img_id, hour_hand_img_id, minute_hand_img_id, second_hand_img_id;
} mmi_idle_swatch_analog_clock;

typedef struct
{
    U16 bg_x, bg_y;
    U16 hour_x, hour_y;
    U16 minute_x, minute_y;
    U16 ampm_x, ampm_y;
    U16 hour_num_gap, minute_num_gap;
    MMI_ID bg_img_id, hour_num_0_img_id, minute_num_0_img_id, am_img_id, pm_img_id;
    MMI_BOOL add_zero;  //when num is not full of width, add zero or not
} mmi_idle_swatch_digital_clock;

typedef struct
{
    MMI_IDLE_SWATCH_CLOCK_TYPE type;
    mmi_idle_swatch_area area;
    
    union
    {
        mmi_idle_swatch_digital_clock digital;
        mmi_idle_swatch_analog_clock analog;
    } data;
} mmi_idle_swatch_clock;

typedef struct
{
    U16 x, y;
    MMI_ID text_id;
    U8 font_size;
    color font_color;
} mmi_idle_swatch_ap_text_info;

typedef struct
{
    U16 x, y;
    MMI_ID image_id;  //if count is image type, it will be num 0 image id
    U16 image_gap;  //gap of tow image number of count
} mmi_idle_swatch_ap_image_info;

typedef struct
{
    MMI_BOOL count_is_left_of_hint;  //whether count string position left of hint, if this is true, count_x must be the same as hint_x
    MMI_BOOL add_zero;  //when num is not full of width, add zero or not

    MMI_IDLE_SWATCH_AP_ENUM app;
    
    MMI_IDLE_SWATCH_AP_INFO_TYPE hint_type;
    MMI_IDLE_SWATCH_AP_INFO_TYPE count_type;

    U32 count;
    mmi_idle_swatch_ap_update update_func;
    mmi_idle_swatch_area area;

    union
    {
        mmi_idle_swatch_ap_text_info text;
        mmi_idle_swatch_ap_image_info image;
    } hint_data;
    
    union
    {
        mmi_idle_swatch_ap_text_info text;
        mmi_idle_swatch_ap_image_info image;
    } count_data;
} mmi_idle_swatch_ap;

typedef struct
{
    /* Clock */
    mmi_idle_swatch_clock clock;
    /* AP */
    U8 ap_num;
    mmi_idle_swatch_ap ap[MMI_IDLE_SWATCH_AP_NUM];
} mmi_idle_swatch_config_table;

typedef struct
{
    MMI_BOOL is_active;
    U8 swatch_index;
    U8 setting_swatch_index;
    MMI_ID group_id;
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;
    gdi_handle base_layer_handle;  //layer to draw background elements
    PU8 update_layer_buf_ptr;
    gdi_handle update_layer_handle;  //layer to update time and AP info
    PU8 status_icon_bar_layer_buf_ptr;
    gdi_handle status_icon_bar_layer_handle;  //layer to show status icon bar
    PU8 temp_layer_buf_ptr;  //temp layer to draw analog clock
    mmi_idle_swatch_pedometer_cb pedometer_cb;
    MMI_IDLE_SWATCH_UPDATE_TYPE update_type;
    #if defined(__MMI_TOUCH_SCREEN__)
    S32 moving_x;
    MMI_IDLE_SWATCH_SETTING_SSP_STATE ssp_state;
    MMI_BOOL is_selected;
    mmi_pen_point_struct setting_pre_point;
    MMI_IDLE_SWATCH_SETTING_SSP_STATE setting_ssp_state;
    S16 setting_revert_step;
    float setting_ssp_speed;
    #endif  //defined(__MMI_TOUCH_SCREEN__)
} mmi_idle_swatch_context_struct;

/***************************************************************************** 
 * Function Declare
 *****************************************************************************/
extern void mmi_idle_swatch_get_pedometer_data(MMI_IDLE_SWATCH_AP_ENUM app, U32* count);

#endif /* __MMI_WEARABLE_DEVICE__ */ 
#endif /* _MMI_SWATCH_H_ */ 

