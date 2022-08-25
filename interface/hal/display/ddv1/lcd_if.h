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
 * lcd_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for LCD interface driver.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 31 2011 haitao.shang
 * removed!
 * .
 *
 * 09 05 2011 bin.han
 * removed!
 * .
 *
 * 08 25 2011 bin.han
 * removed!
 * .
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 08 01 2011 bin.han
 * removed!
 * .
 *
 *
 *
 *******************************************************************************/
#ifndef __LCD_IF_H__
#define __LCD_IF_H__

#ifdef FPGA
#include "lcd_feature.h"
#include "typedefs.h"
#include "hw_reg.h"
#include "lcd_if_hw.h"
#else //FPGA

//////////////////RHR-ADD//////////////////////
#include "kal_non_specific_general_types.h"
//////////////////RHR-ADD//////////////////////

#include "kal_release.h"
//#include "drv_features_display.h"
#include "drv_sw_features_display.h"
// #include "lcd_if_hw.h" //RHR left for auto tool remove
// #include "mm_power_ctrl.h" //RHR left for auto tool remove
#include "lcd_if_common.h"    ///include shared APIs between by DDV1 and DDV2
#include "lcd_if_manager.h"

#endif //FPGA

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*SW XXX*/
typedef enum
{
   LCD_LAYER0 = 0,
   LCD_LAYER1 = 1,
   LCD_LAYER2 = 2,
   LCD_LAYER3 = 3,
   LCD_LAYER4 = 4,
   LCD_LAYER5 = 5
}  LCD_LAYER_ENUM;

#define LAYER_N_ENABLE(n) (1 << (31 - n))

/*won't change according to chip*/
#define LCD_LAYER0_ENABLE     0x80000000
#define LCD_LAYER1_ENABLE     0x40000000
#define LCD_LAYER2_ENABLE     0x20000000
#define LCD_LAYER3_ENABLE     0x10000000
#define LCD_LAYER4_ENABLE     0x08000000
#define LCD_LAYER5_ENABLE     0x04000000

typedef enum
{
   LCD_LAYER_ROTATE_NORMAL = 0,
   LCD_LAYER_ROTATE_90,
   LCD_LAYER_ROTATE_180,
   LCD_LAYER_ROTATE_270,
   LCD_LAYER_MIRROR,
   LCD_LAYER_MIRROR_ROTATE_90,
   LCD_LAYER_MIRROR_ROTATE_180,
   LCD_LAYER_MIRROR_ROTATE_270,
   LCD_LAYER_MIRROR_ROTATE_NOMO
}LCD_LAYER_ROTATE_ENUM;


typedef struct
{
   kal_uint32   modules_enable_handle; //used to keep wifi/cdma modules current is enabled or not

   kal_uint32   power_handle;
   kal_uint8    handle_count;

}  Lcd_PowerHandle_struct;


//#define LCD_FMARK_G_NO_FOR_NOT_MM    0x13579024

typedef enum
{
   LCD_ROI_OUTPUT_RGB332 = 0,
   LCD_ROI_OUTPUT_RGB444,
   LCD_ROI_OUTPUT_RGB565,
   LCD_ROI_OUTPUT_RGB666,
   LCD_ROI_OUTPUT_RGB888
} LCD_ROI_OUTPUT_COLOR_FORMAT_ENUM;


#define LCD_RGB888_TO_RGB565(rgb888_data)   (((((rgb888_data>>16)&0xFF) & 0xF8)<<8)|((((rgb888_data>>8))&0xFC)<<3)|((((rgb888_data)&0xFF)&0xF8)>>3))

#if defined(DRV_LCD_4_BYTES_ALIGN)
   #define LCD_MEMORYOUT_ALIGN_BYTES 4
#elif defined(DRV_LCD_8_BYTES_ALIGN)
   #define LCD_MEMORYOUT_ALIGN_BYTES 8
#endif

typedef enum
{
    LCM_TRANSMISSIVE_TYPE = 0 ,
    LCM_TRANSFLECTIVE_TYPE
} LCM_TRANSMISSIVE_TRANSFLECTIVE_TYPE_ENUM;


typedef enum{
  LCD_OK = 0,
  LCD_ERROR_INVALID_LCD_ID, //main_id and sub_id

  LCD_ERROR_INVALID_OFFSET,
  LCD_ERROR_INVALID_SIZE,
  LCD_ERROR_INVALID_OFFSET_SIZE,
  LCD_ERROR_INVALID_LCM_UPDATED_REGION,

  LCD_ERROR_INVALID_MEM_OUT_MODE,//continus or block
  LCD_ERROR_INVALID_MEM_OUT_BUFFER_SIZE,
  LCD_ERROR_INVALID_MEM_OUT_DST_OFFSET, //for CONT_MODE
  //LCD_ERROR_INVALID_MEM_OUT_MAIN_WINDOW_SIZE,
  LCD_ERROR_INVALID_MEM_OUT_COLOR_FORMAT,

  LCD_ERROR_INVALID_LAYER_NUMBER,
  LCD_ERROR_INVALID_LAYER_ALPHA_VALUE,
  LCD_ERROR_INVALID_LAYER_ROTATE_VALUE,
  LCD_ERROR_INVALID_LAYER_COLOR_FORMAT,
  LCD_ERROR_INVALID_LAYER_MEM_OFFSET_PITCH,
  LCD_ERROR_INVALID_LAYER_COLOR_KEY_SETTING,
  LCD_ERROR_INVALID_LAYER_MEM_OFFSET_SIZE,
  LCD_ERROR_INVALID_LAYER_DITHER_CONFIG,

  LCD_ERROR_BUFFER_SHALL_4ALIGNMENT,
  LCD_ERROR_BUFFER_SHALL_8ALIGNMENT,
  LCD_ERROR_CALLBACK_IS_NULL,
  LCD_ERROR_FLATTEN_WHEN_TV_ACTIVE,
  LCD_ERROR_INVALID_COLOR_PALETTE,
  LCD_ERROR_INVALID_UPDATED_LAYER,
  LCD_ERROR_CONFIG_HW_UPDATED_LAYER,
  LCD_CAMERA_ERROR
}LCD_STATUS_CODE_ENUM;



typedef enum
{
   LCD_IDLE_STATE=0,
   LCD_INITIAL_STATE,
   LCD_STANDBY_STATE,
   LCD_SLEEP_STATE,
   LCD_SLEEPING_STATE,
   LCD_WAKING_UP_STATE,
   LCD_SW_UPDATE_STATE,
   LCD_MEM_UPDATE_STATE,
   LCD_JPEG_VIDEO_UPDATE_STATE,
   LCD_JPEG_VIDEO_CMD_QUEUE_STATE,
   LCD_CAMERA_ACTIVE_STATE,
   LCD_CAMERA_ACTIVE_UPDATE_STATE,
   LCD_CAMERA_UPDATE_STATE,
   LCD_CAMERA_CMD_QUEUE_STATE,
   LCD_HW_UPDATE_STATE,
   LCD_DC_UPDATE_STATE,
   LCD_HW_CMD_QUEUE_STATE,
   LCD_DC_CMD_QUEUE_STATE,
   LCD_WAIT_LAST_UPDATE_STATE,
   LCD_DC_UPDATE_SLEEP_STATE,
   LCD_HW_UPDATE_SLEEP_STATE,
   LCD_DC_SLEEP_CMD_QUEUE_STATE,
   LCD_HW_SLEEP_CMD_QUEUE_STATE,
   LCD_FW_UPDATE_STATE,/*supported on MT6225 like platform*/
   LCD_FW_CMD_QUEUE_STATE,/*supported on MT6225 like platform*/
   MAX_LCD_OPERATION_STATE
}  LCD_OPERATION_STATE_ENUM;

typedef enum
{
   LCD_TO_SLEEP = 0,
   LCD_TO_WAKEUP,
   LCD_TO_NONE
}LCD_SLEEP_WAKEUP_ACTION_ENUM;


typedef enum
{
   LCD_IDMA_TRIGGER_SRC_IRT1=0,
   LCD_IDMA_TRIGGER_SRC_IBW1,
   LCD_IDMA_TRIGGER_SRC_IRT2,
   LCD_IDMA_TRIGGER_SRC_IBW2,
   MAX_LCD_IDMA_TRIGGER_SRC
}  LCD_IDMA_TRIGGER_SRC_ENUM;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*SW XXX*/
typedef enum
{
   LCD_UPDATE_MODULE_MMI         = 0,
   LCD_UPDATE_MODULE_MEDIA          ,
   LCD_UPDATE_MODULE_JPEG_VIDEO     ,
   LCD_UPDATE_MODULE_EXT_CAMERA     ,
   LCD_UPDATE_MODULE_LCD_FW
}  LCD_OWNER_ID_ENUM;



/*SW XXX*/
typedef enum
{
   LCD_SW_TRIGGER_MODE     =   0,     /* LCD SW trigger with frame buffer */
   LCD_HW_TRIGGER_MODE     =   1,     /* LCD HW trigger with frame buffer */
   LCD_DIRECT_COUPLE_MODE  =   2      /* LCD HW trigger without frame buffer, direct couple */
}  LCD_UPDATE_MODE_ENUM;

#if defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6270A) || defined(MT6256) || defined(MT6255)
// We will define thie enum in xxx.h
#else
typedef enum
{
   LCD_HW_TRIGGER_IBW1 =  0,
   LCD_HW_TRIGGER_IBW2 =  1,
   LCD_HW_TRIGGER_IRT1 =  2,
   LCD_HW_TRIGGER_IRT2 =  3,
   LCD_HW_TRIGGER_RESIZER =  4
}  LCD_HW_TRIGGER_SRC_ENUM;
#endif //defined(MT6236) || defined(MT6236B)


typedef enum
{
   LCD_TRANSFER_COMPLETE_EVENT =   0x00000001,
   LCD_DATA_COMPLETE_EVENT     =   0x00000002,
   LCD_CMD_COMPLETE_EVENT      =   0x00000004,
   LCD_CMD_TIMEOUT_EVENT      =   0x00000008, // add for video low frame rate on 6253
   LCD_UNKNOWN_EVENT      =   0x00004000 // add for 6253
}  LCD_EVENT_ENUM;

// mt6253
typedef enum
{
   LCD_WAIT_TRANSFER_COMPLETE_EVENT =   0x00000001,
   LCD_WAIT_DATA_COMPLETE_EVENT     =   0x00000002,
   LCD_WAIT_CMD_COMPLETE_EVENT      =   0x00000004
}  LCD_WAIT_EVENT_ENUM;
//end -- mt6253

typedef enum
{
   LCD_COLOR_PALETTE0  =  0,
   LCD_COLOR_PALETTE1  =  1
}  LCD_PALETTTE_ENUM;



typedef enum
{
   LCD_WM_CONT_MODE    =     0,
   LCD_WM_BLOCK_MODE   =     1
}  LCD_MEMORY_OUTUT_MODE_ENUM;


typedef enum
{
   LCD_CAPS_TEARING_CONTRL,  //For full screen, LCM support Vsync
   LCD_CAPS_PARTIAL_UPDATE_TEARING_CONTRL, //For partial update, LCM spport frame marker or Hsync. LCD controller must has corresponding functions
   LCD_CAPS_CABC  //Content Adaptive Brightness Control support
}LCD_CAPS_ID_E;

typedef enum
{
   LCD_CAPS_NOT_SUPPORT,
   LCD_CAPS_SUPPORT,
   LCD_CAPS_QUERY_ERR_INVALIDE_ID,
   LCD_CAPS_QUERY_ERR_NO_ARGUMENT
}LCD_CAPS_QUERY_RESULT_E;

LCD_CAPS_QUERY_RESULT_E lcd_get_device_caps(LCD_CAPS_ID_E id, kal_uint32 *p_argu);


typedef struct
{
   kal_bool    layer_update_queue;     /* lcd layer parameter queue is full or not */
   kal_bool    source_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    color_palette_enable;   /* enable/disable color palette for specified layer */
   kal_bool    opacity_enable;         /* enable/disable opacity for specified layer */

   //LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM
   kal_uint8   source_color_format;    /* color format of the specified layer, for MT6228 and MT6229 only */

   kal_uint8   color_palette_select;   /* selection of color palette table */
   kal_uint8   opacity_value;          /* opacity value for specified layer */

   //LCD_LAYER_ROTATE_ENUM
   kal_uint8   rotate_value;           /* rotate select for specified layer */
   kal_uint16  x_offset;               /* x axis offset from main window for specified layer */
   kal_uint16  y_offset;               /* y axis offset from main widnow for specified layer */
   kal_uint16  row_number;             /* layer buffer height of specified layer */
   kal_uint16  column_number;          /* layer buffer width of specified layer */
   kal_uint32  source_key;             /* source key color in RGB565 format for specified layer */
   kal_uint32  frame_buffer_address;   /* frame buffer start address of specified layer */

   // For MT6236
   kal_bool    dst_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    lgamma_enable;      /* enable/disable source key for specified layer */
   kal_bool    dither_enable;      /* enable/disable source key for specified layer */
   kal_uint16  mem_x_offset;               /* x axis offset from mem space window for specified layer */
   kal_uint16  mem_y_offset;               /* y axis offset from mem space window for specified layer */
   kal_uint16  mem_pitch;               /* pitch of mem space window for specified layer */
} lcd_layer_struct;

#if 0
/* under construction !*/
#endif
typedef struct
{
   /// module ID that request frame buffer update
   /// LCD_UPDATE_MODULE_MMI, LCD_UPDATE_MODULE_MEDIA, LCD_UPDAET_MODULE_EXT_CAMERA, LCD_UPDATE_MODULE_JPEG_VIDEO
   kal_uint8 module_id;
   /// which lcd will be updated (MAIN_LCD or SUB_LCD)
   kal_uint8 lcd_id;
   /// block caller or not
   kal_bool block_mode_flag;
   /// callback when lcd update is done
   void (* lcd_block_mode_cb)(void);
   //// frame buffer update mode (SW_TRIGGER, HW_TRIGGER or DIRECT_COUPLE)
   kal_uint8 fb_update_mode;
   /// the starting x coordinate of LCM to be updated
   kal_uint16 lcm_start_x;
   /// the starting y coordinate of LCM to be updated
   kal_uint16 lcm_start_y;
   /// the ending x coordinate of LCM to be updated
   kal_uint16 lcm_end_x;
   /// the ending y coordinate of LCM to be updated
   kal_uint16 lcm_end_y;
   /// the ROI window offset x from main window
   kal_uint16 roi_offset_x;
   /// the ROI window offset y from main window
   kal_uint16 roi_offset_y;
   /// the layers to be updated
   kal_uint32 update_layer;
   /// which layer will be applied by hw trigger or direct couple
   kal_uint32 hw_update_layer;
   /// rotate select for hardware update layer
   kal_uint8 rotate_value;

#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
   /// background color of ROI
   kal_uint32  roi_background_color;
#endif

#if defined(DRV_LCD_MEMORY_OUTPUT)
   /// enable/disable otuput to memory and LCM simultaneously
   kal_bool    memory_output;
   /// block write out or not
   kal_uint8   block_mode;
   /// output data format to memory, LCD_WMEM_RGB565 or LCD_WMEM_RGB888 for 6228, 6229.
   /// always RGB565 for 6226,6227
   kal_uint8   memory_data_format;
   /// memory block when output to memory
   kal_uint16  memory_block_width;
   /// buffer address of memory output buffer
   kal_uint32  memory_output_buffer_address;
   /// buffer size of memory output buffer
   kal_uint32  memory_output_buffer_size;
   /// x offset of dest buffer
   kal_uint16  dest_offset_x;
   /// y offset of dest buffer
   kal_uint16  dest_offset_y;
   /// temp memory buffer
   kal_uint32  dest_temp_address;
#endif //DRV_LCD_MEMORY_OUTPUT
}  lcd_frame_update_struct;



typedef struct
{
   kal_uint8   fb_update_mode;      /* frame buffer update mode (SW_TRIGGER, HW_TRIGGER or DIRECT_COUPLE) */

   kal_uint8   block_mode;          /* block write out or not */
   kal_uint16  dest_block_width;    /* x pitch of block write operation */
   kal_uint32  dest_buffer_address; /* the start address of desination buffer for LCD memory write out */
   kal_uint32  dest_buffer_size;
   kal_uint16  roi_offset_x;        /* x offset of interest area from dest buffer */
   kal_uint16  roi_offset_y;        /* y offset of interest area from dest buffer */
   kal_uint16  roi_width;           /* dest image width */
   kal_uint16  roi_height;          /* dest image height */
   kal_uint32  update_layer;
   kal_uint32  hw_update_layer;
   /* for MT6228 and MT6229, MT6230 only */
   kal_uint8   hw_trigger_src;         /* LCD_HW_TRIGGER_IBW1 or LCD_HW_TRIGGER_IBW2 that will trigger LCD */
   kal_uint32  roi_background_color;   /* background color of memory otuput buffer */
   kal_uint8   memory_data_format;     /* output data format */
   kal_uint16  dest_offset_x;        /* x offset of dest buffer */
   kal_uint16  dest_offset_y;        /* y offset of dest buffer */
   kal_uint32  dest_temp_address;    /* temp memory buffer */

   //3 For MT6236
   kal_uint32  alpha_value; // The max value is : 0xFF
   kal_bool blocking_req; //Indicate if this is a blocking request or not
   void (* nonblocking_req_callback)(void); // callback function of non-blocking request
}  lcd_frame_update_to_mem_struct;


typedef struct
{
    kal_bool hw_update_enable; // KAL_TRUE: enter hw update, KAL_FALSE: leave hw update
    kal_uint32 hw_update_layer; // 0, 1, 2, 3, (4, 5 if hw has 6 layers)
    // may extend ...
}LCD_HW_UPDATE_CB_S;

typedef void (*lcd_hw_update_switch_cb_t)(LCD_HW_UPDATE_CB_S *);

/// Start of Variable Declaration

//extern volatile LCD_Funcs  *MainLCD;
//extern volatile LCD_Funcs  *SubLCD;

extern volatile LCD_SLEEP_WAKEUP_ACTION_ENUM lcd_sleep_wake_action;
#if 0
/* under construction !*/
#endif
/// state control

extern volatile LCD_OPERATION_STATE_ENUM main_lcd_operation_state;
extern volatile lcd_frame_update_struct main_lcd_fb_update_para;
extern volatile LCD_OPERATION_STATE_ENUM sub_lcd_operation_state;
extern volatile lcd_frame_update_struct sub_lcd_fb_update_para;

#ifdef FPGA
extern kal_uint32 lcd_event_id;
#else
extern volatile kal_eventgrpid lcd_event_id;
#endif

extern volatile kal_uint8 current_update_lcd;

extern volatile kal_uint8 lcd_dc_color_mode;
extern volatile kal_uint8 lcd_rotate_value;
extern volatile kal_uint8 lcd_hard_trigger_flag;
extern volatile kal_uint32 current_lcd_hw_update_layer;
extern volatile kal_bool lcd_window_swap_flag;
extern volatile kal_bool bLCDBufferInINTRAM;
extern volatile kal_uint32 lcd_roi_ctrl_shadow,lcd_roi_size_shadow,lcd_roi_offset_shadow;
extern volatile kal_uint32 lcd_mem_out_address_shadow,lcd_mem_out_address_shadow1, lcd_mem_out_ctrl_shadow;
extern volatile kal_uint32 lcd_frame_buffer_address;

/// HPI interface control
extern volatile kal_uint16 old_lcd_cmd_period_count;
extern volatile kal_uint16 hpi_cmd_period_count;
extern volatile kal_bool hpi_power_on;
extern volatile kal_bool lcd_is_changing_roi;
/*video editor*/
extern volatile LCD_OPERATION_STATE_ENUM temp_main_lcd_operation_state;

extern volatile kal_uint8  lcd_sleep_mode_handler;

#if 0
/* under construction !*/
#endif

extern volatile kal_uint8 lcd_transfer_complete;
extern volatile kal_uint16 lcd_cmd_period_count;

extern volatile kal_uint8 lcd_output_mode;
extern volatile kal_uint8 main_lcd_hw_trigger_output_mode;
extern volatile kal_uint8 sub_lcd_hw_trigger_output_mode;
extern volatile kal_bool bWaitForLCDUpdate;
extern volatile kal_uint8 lcd_hw_trigger_flag;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/// Start of Function Declaration



/// For Driver Internal
kal_bool INT_QueryExceptionStatus(void);
void lcd_busy_waiting(void);



/// ISR handler
void lcd_LISR(void);
void lcd_HISR(void);



/// For System Service



/// For Media Task



/// For MMI

#ifdef __LCD_ESD_RECOVERY__
   kal_bool lcd_ESD_check(void);
#endif


kal_bool lcd_is_busy(void);
void hpi_power_ctrl(kal_bool bTurnOnClock);
void set_hpi_low_period_count(kal_uint8 low_period);
void lcd_layer_swap_width_height(kal_uint32 swap_layer);
void set_lcd_layer_roate(kal_uint32 rotate_layer,kal_uint8 rotate_value);
void resume_lcd_layer_rotate(void);

LCD_STATUS_CODE_ENUM config_lcd_layer_window(kal_uint8 lcd_layer,lcd_layer_struct *layer_data);
void _config_lcd_layer_window_queue(void);
void config_lcd_layer_window_queue(void);
kal_bool config_lcd_roi_window(kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint16 roi_column,
                               kal_uint16 roi_row);

#if defined(MT6251)
void set_lcd_color_palette(kal_uint8 color_palette_select,kal_uint16 *color_palette_addr_ptr,
                           kal_uint8 start_index, kal_uint32 number_of_color);
#else
void set_lcd_color_palette(kal_uint8 color_palette_select,kal_uint16 *color_palette_addr_ptr,
                           kal_uint8 start_index, kal_uint8 number_of_color);
#endif

void config_lcd_layer_offset(kal_uint8 lcd_layer, kal_uint16 layer_offset_x, kal_uint16 layer_offset_y);
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color);
void config_lcd_output(kal_bool lcd_output);
LCD_STATUS_CODE_ENUM lcd_fb_update(lcd_frame_update_struct *lcd_para);
LCD_STATUS_CODE_ENUM lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *lcd_para);
void set_lcd_dc_layer_format(kal_uint32 hw_update_layer,kal_bool direct_couple);
void lcd_stop_hw_update(kal_uint8 lcd_id);
void config_lcd_hw_layer(kal_uint32 hw_layer,kal_uint16 layer_offset_x,kal_uint16 layer_offset_y,
                         kal_uint16 layer_width, kal_uint16 layer_height);
kal_uint8 get_lcd_hw_layer_rotate_value(kal_uint32 hw_layer);

kal_uint32 get_lcd_frame_buffer_address(void);
void reset_lcd_if(void);
void assert_lcd_fb_update(kal_uint8 lcd_id, kal_uint16 start_x, kal_uint16 start_y, kal_uint16 end_x,
                          kal_uint16 end_y,kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint32 update_layer);
void lcd_dma_slow_down(kal_uint8 level);
void lcd_dma_recovery(void);
kal_uint32 lcd_wait_command_latch(void);//return type change to kal_uint32 of retrieved event
void lcd_get_event_timer_handle(void);

void lcd_enable_rotation_speed_up(kal_uint32 layer);
void lcd_disable_rotation_speed_up(kal_uint32 layer);

/*for GAMMA interface*/
void lcd_set_gamma_table(kal_uint8 lcd_id, /*MAIN_LCD, SUB_LCD*/
                         kal_uint8 r_table, /*0~2*/
                         kal_uint8 g_table, /*0~2*/
                         kal_uint8 b_table);/*0~2*/
void lcd_config_gamma_table(kal_uint8 start_index,/*0~255*/
                            kal_uint8 size,       /*0~255*/
                            kal_uint8 *data,
                            kal_uint8 table_id);/*0,1,2*/
void lcd_enable_gamma(kal_uint8 lcd_id, kal_bool enable);

void LCD_config_fw_layer_address(kal_uint32 addr);

/*for mjpeg*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void LCD_recode_preview(kal_uint32 layer, kal_uint32 buffer);
void LCD_preview(kal_uint32 layer, kal_uint32 buffer1, kal_uint32 buffer2 );
void lcd_reset_preview(void);

void LCD_enable_TE(kal_bool enable);
kal_uint8 lcd_get_lcm_rotate_value(LCD_TYPE_ENUM lcd_id);//MAIN_LCD, SUB_LCD
kal_bool lcd_is_in_standby_mode(void);
// for mt6253
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* for power gating*/
kal_uint8 lcd_get_power_handle( void );
void lcd_clk_enable( kal_uint8 handle );
void lcd_clk_disable( kal_uint8 handle );

#ifdef MP4_DECODE
  void LCD_video_decode_display(kal_uint32 buffer);
#endif

#ifdef __FUE__
  void lcd_fue_init(kal_uint16 background_color);
  kal_bool lcd_fue_config_layer_window(kal_uint8 lcd_layer,lcd_layer_struct *layer_data);
  void lcd_fue_fb_update(lcd_frame_update_struct *lcd_para);
#endif

kal_uint32 disable_paralle_if_gamma(void);
void rollback_paralle_if_gamma(kal_uint32 reg_val);

void _lcd_prepare_update_para(lcd_frame_update_struct *lcd_para);
kal_bool lcd_jpeg_video_handle_mmi_request(lcd_frame_update_struct *lcd_para);


kal_bool _check_mem_out_dst_offset(kal_uint32 mode, kal_uint32 offx, kal_uint32 offy);
kal_bool _check_roi_size_and_offset(kal_uint32 width, kal_uint32 height, kal_uint32 offx, kal_uint32 offy);
kal_bool _check_layer_size_and_offset(kal_uint32 width, kal_uint32 height, kal_uint32 offx, kal_uint32 offy);
kal_bool _check_lcm_start_end_position(kal_uint32 lcd_id, kal_uint32 startx, kal_uint32 starty, kal_uint32 endx, kal_uint32 endy);
kal_bool lcd_wait_to_leave_sleeping_waking(void);

void lcd_wait_te_signal(void);
kal_uint32 lcd_enable_te_in_sw_trigger(kal_bool enable);

kal_uint8 lcd_get_te_ctrl_handle(void);
kal_bool lcd_te_ctrl_push(kal_bool on_Noff, kal_uint8 handle);
kal_bool lcd_te_ctrl_pop(kal_uint8 handle);

#if (defined(MT6236) ||defined(MT6236B))
LCD_STATUS_CODE_ENUM _lcd_config_dither(void);
#endif

void _lcd_set_gmc_throttle(lcd_layer_struct* layer_data, lcd_frame_update_struct *lcd_para);

#ifdef FPGA
extern kal_uint32 mem_out_pitch;
void lcd_test(void);
#endif


void lcd_config_tearing(lcd_frame_update_struct *lcd_para);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void lcd_enable_partial_update(kal_bool flag);
#if defined(MT6235) || defined(MT6235B) || defined(MT6253)
kal_bool lcd_set_mm_layer_attrib(kal_uint32 enabled_layer, kal_uint32 vdo_buff_addr);
#endif

LCD_CAPS_QUERY_RESULT_E lcd_get_device_caps(LCD_CAPS_ID_E id, kal_uint32 *p_argu);
kal_bool lcd_is_flatten_ready(void);
extern void lcd_display_enable(kal_bool enable);
#if 0
/* under construction !*/
#endif 

#endif /* __LCD_IF_H__ */


