/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 * lcd_if_manager.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for LCD interface manager.
 *
 * Author:
 * ------- 
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 14 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 03 21 2012 xiaoyong.ye
 * removed!
 * 
 * Fix driving current enum error.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 08 25 2011 bin.han
 * removed!
 * .
 *
 * 04 22 2011 zifeng.qiu
 * removed!
 * Code size shrink for IF Manager.
 *
 * 04 22 2011 bin.han
 * removed!
 * .
 *
 * 03 30 2011 chelun.tsai
 * removed!
 * lcd_if_hw.h move to HAL.
 *
 * 12 14 2010 tristan.su
 * removed!
 * .
 *
 * 12 14 2010 tristan.su
 * removed!
 * .
 *
 * 11 23 2010 chelun.tsai
 * removed!
 * .
 *
 * 11 21 2010 tristan.su
 * removed!
 * sync 10A back to MAUI including partial update tearing.
 *
 * 11 15 2010 tristan.su
 * removed!
 * .
 *
 *
 *******************************************************************************/

#ifndef __LCD_IF_MANAGER__
#define __LCD_IF_MANAGER__

#include "kal_non_specific_general_types.h"

//temporarily, wrapped by chip options here, move to drv_sw_features_xxx.h
//#if defined(MT6253E) || defined(MT6253L) || defined(MT6253) || defined(MT6253D)
//  #define DRV_LCD_INTERFACE_MANAGER_SUPPORT
//#endif

/**
 * <code>LCD_IF_USER_ENUM</code> defines known possible lcd interface user and must be specified and passed into the function call of first register or get handle.
 */
typedef enum
{
    LCD_IF_USER_UNKNOWN = 0, ///< invalid user
    LCD_IF_USER_WIFI, ///< Wifi share LCD interface
    LCD_IF_USER_HIF, ///< 76, 55 et.c AST project, TD Modem use
    LCD_IF_USER_SIM, ///< Gemini+  4 SIMs
    LCD_IF_USER_MAIN_LCD, ///< Main LCD
    LCD_IF_USER_SUB_LCD,///< Sub LCD if have
    LCD_IF_USER_MATV,///< Matv will query main lcd settings, and may change LCD interface dynamically
    LCD_IF_USER_L1,///< L1 will query main lcd settings for frequency hopping. Shold not have configure behavior
    LCD_IF_USER_FM,///< FM will query main lcd settings for frequency hopping. Shold not have configure behavior
    LCD_IF_USER_EXT1, ///< reserved for future extension
    LCD_IF_USER_EXT2, ///< reserved for future extension
    LCD_IF_USER_EXT3, ///< reserved for future extension
    LCD_IF_USER_EXT4, ///< reserved for future extension
    LCD_IF_USER_MAX_ENUM ///< reserved for future extension
}LCD_IF_USER_ENUM;


typedef enum
{
    LCD_IF_TYPE_UNKNOWN = 0, ///< invalid interface type
    LCD_IF_TYPE_DBI_PARALLEL, ///< Display bridge interface, i,e, CPU interface, parallel type
    LCD_IF_TYPE_DBI_SERIAL, ///< Display bridge interface, i,e, CPU interface, serial type
    LCD_IF_TYPE_DPI, ///< Display pixel interface, i,e, RGB interface
    LCD_IF_TYPE_DSI, ///< Display serial interface, i,e, CPU interface
    LCD_IF_TYPE_MAX_ENUM
}LCD_IF_TYPE_ENUM;

typedef struct
{
   kal_uint8 if_cs_no;///< chip select number
   kal_uint8 if_bus_width; ///< unit is bit
   kal_uint32 if_c2ws; ///< write setup time, unit is T
   kal_uint32 if_wst; ///< write wait state, unit is T
   kal_uint32 if_c2wh; ///< write hold time, unit is T
   kal_uint32 if_c2rs; ///< read setup time, unit is T
   kal_uint32 if_c2rh; ///< read hold time, unit is T
   kal_uint32 if_rlt; ///< read latency time, unit is T
   kal_bool if_set_common_period; ///< KAL_TRUE to set HW register as below if_period value
   kal_uint32 if_period; ///< delay between two transaction, only valid when if_set_common_period is KAL_TRUE
   kal_uint32 if_total_write_cycles; ///< total write cycles, unit is T, not register value, it's physical time on bus for one transation
   kal_uint32 if_total_read_cycles; ///< total read cycles, unit is T, not register value, it's physical time on bus for one transation

   kal_uint32 if_clk_freq; ///< unit is Hz

   kal_uint32 if_data_port_addr; ///< let interface user can write port directly and most effectively w/o any SW function call overhead
   kal_uint32 if_cmd_port_addr;///< let interface user can write port directly and most effectively w/o any SW function call overhead
   kal_uint32 add_driving_current; ///< unit is mA, driver will map to nearest low available extra driving current that chip support

   kal_uint8 if_gamma_r_lut_id; ///< gamma r enable, default is 0xFF which means disable gamma, if r,g,b must enable or disable at the same time, interface manager will just reference r enable
   kal_uint8 if_gamma_g_lut_id; ///< gamma g enable, default: 0xFF means disable gamma
   kal_uint8 if_gamma_b_lut_id; ///< gamma b enable, default: 0xFF means disable gamma
   kal_uint32 *p_if_gamma_lut_addr; ///< valid when one of r,g,b gamma is enabled, the pointer pints to LUT table register, size is if_gamma_lut_size, user must configure gamma table before really enable it
   kal_uint32 if_gamma_lut_size; ///< valid when one of r,g,b gamma is enabled, unit is word(4bytes)
   kal_uint32 if_gamma_lut_entity_bit_num; ///< valid when one of r,g,b gamma is enabled, each lut entity has how maiy bits. 6 for RGB666, 8 for RGB88 
   kal_uint32 if_gamma_lut_entity_bit_shift; ///< valid when one of r,g,b gamma is enabled, how to pack for 3 lut id in one 32bit register. \n For ex, if_gamma_lut_entity_bit_num is 6, if_gamma_lut_entity_bit_shift is 6, then AAAAAABBBBBBCCCCCC (MT6253). \n if_gamma_lut_entity_bit_num is 8, if_gamma_lut_entity_bit_shift is 8, then AAAAAAAABBBBBBBBCCCCCCCC (MT6235, MT6276, etc). \n if_gamma_lut_entity_bit_num is 6, if_gamma_lut_entity_bit_shift is 8, then AAAAAAXXBBBBBBXXCCCCCC. X is don't care (future extension)

   kal_bool __if_reg_fast_mode; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_1; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_2; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_3; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_4; ///< !!! Do NOT modify, lcd interface manager internal usage
}LCD_IOCTRL_DBI_PARALLEL_IF_T;


typedef struct
{
   kal_uint8 if_cs_no;///< chip select number
   kal_bool if_clk_polarity;///< clock polarity
   kal_bool if_clk_phase;///< clock phase
   kal_bool if_cs_polarity;///< chip select polarity

   kal_bool   if_3wire_mode;///< For standard lcd serial interface module, 3wire means A0(LCM's register select) is included in first bit of serial transcation. non-3wire mode (4wire mode) means A0 uses another dedicated wire to LCM. \n Default is 4wire mode , i,e,  3wire mode is KAL_FALSE.  When if_non_dbi_mode is KAL_FALSE, 3wire mode means 9bits per transaction, 4wire mode means 8bits per trasaction.
   kal_bool   if_single_a0_mode;///< Newly added from MT6250, in singla A0 mode, frame data transactions only transmit A0 once, which is in the very first transaction
   kal_bool   if_2data_lane_mode;///< Newly added from MT6250, 2 data lane, means transfer data on both the LSDA and LSA0 pin
   kal_bool   if_cs_stay_low_mode;///< Newly added from MT6250, the cs is asserted only after the whole frame pixel data transmisiion completes
   kal_bool   if_start_byte_mode;///< Newly added from MT6250, every time CS goes low, serial interface transmit start byte first before sending command or data
   kal_bool   if_sdi;///< Ddefault is KAL_FALSE. When KAL_TRUE, LCD controller read data from LSDI pin, otherwise, LCD controoler will use bi-directional LSDA pin to read data.
   kal_bool   if_non_dbi_mode;///< Default is KAL_FALSE (stand DBI type-C mode). For some special serial LCM, it use non-DBI mode, can transmit more than 8bits/9 bits, for ex, 16bits/18bits
   kal_uint32 if_each_trans_length;///< unit is bit, valid when if_non_dbi_mode is KAL_TRUE, default is 8bit mode
   kal_uint32 if_2data_lane_each_trans_length;///< unit is bit, valid when if_2data_lane_mode is KAL_TRUE, default is 16bit mode,Newly added from MT6250
   kal_uint32 if_str_byte_each_trans_length;///< unit is bit, valid when if_start_byte_mode is KAL_TRUE, default is 8bit mode,Newly added from MT6250


   kal_bool if_is_set_clk_by_scl_counts;///< KAL_TRUE must set if_clk_freq, KAL_FALSE must set scl_wt/rd_low/high_count

   kal_uint32 if_clk_freq;///< unit is Hz, valid when if_is_set_clk_by_scl_counts is KAL_FALSE
   kal_uint32 if_clk_divider;///< clock divider, for ex, 4 means interface colok is if_clk_freq/4

   kal_uint32 if_css_time;  ///< chip select setup time   --- newly added from MT6256E2
   kal_uint32 if_csh_time;  ///< chip select hold time   --- newly added from MT6256E2
   kal_uint32 scl_wr_1st_count;///< unit is T, --- newly added from MT6256E2
   kal_uint32 scl_wr_2nd_count;///< unit is T, --- newly added from MT6256E2
   kal_uint32 scl_rd_1st_count;///< unit is T, --- newly added from MT6256E2
   kal_uint32 scl_rd_2nd_count;///< unit is T,--- newly added from MT6256E2
   kal_uint32 scl_wt_low_count;///< unit is T, valid when if_is_set_clk_by_scl_counts is KAL_TRUE
   kal_uint32 scl_wt_high_count;///< unit is T, valid when if_is_set_clk_by_scl_counts is KAL_TRUE
   kal_uint32 scl_rd_low_count;///< unit is T, valid when if_is_set_clk_by_scl_counts is KAL_TRUE
   kal_uint32 scl_rd_high_count;///< unit is T, valid when if_is_set_clk_by_scl_counts is KAL_TRUE

   kal_uint32 if_data_port_addr;///< let interface user can write port directly and most effectively w/o any SW function call overhead
   kal_uint32 if_cmd_port_addr;///< let interface user can write port directly and most effectively w/o any SW function call overhead
   kal_uint32 add_driving_current; ///< unit is mA, driver will map to nearest low available extra driving current that chip support

   kal_uint8 if_gamma_r_lut_id; ///< gamma r enable, default is 0xFF, means disable gamma, if r,g,b must enable or disable at the same time, interface manager will just reference r enable
   kal_uint8 if_gamma_g_lut_id; ///< gamma g enable, 0xFF means disable gamma
   kal_uint8 if_gamma_b_lut_id; ///< gamma b enable, 0xFF means disable gamma
   kal_uint32 *p_if_gamma_lut_addr; ///< valid when one of r,g,b gamma is enabled, the pointer pints to LUT table register, size is if_gamma_lut_size, user must configure gamma table before really enable it
   kal_uint32 if_gamma_lut_size; ///< valid when one of r,g,b gamma is enabled, unit is word(4bytes)
   kal_uint32 if_gamma_lut_entity_bit_num; ///< valid when one of r,g,b gamma is enabled, each lut entity has how maiy bits. 6 for RGB666, 8 for RGB88 
   kal_uint32 if_gamma_lut_entity_bit_shift; ///< valid when one of r,g,b gamma is enabled, how to pack for 3 lut id in one 32bit register. \n For ex, if_gamma_lut_entity_bit_num is 6, if_gamma_lut_entity_bit_shift is 6, then AAAAAABBBBBBCCCCCC (MT6253). \n if_gamma_lut_entity_bit_num is 8, if_gamma_lut_entity_bit_shift is 8, then AAAAAAAABBBBBBBBCCCCCCCC (MT6235, MT6276, etc). \n if_gamma_lut_entity_bit_num is 6, if_gamma_lut_entity_bit_shift is 8, then AAAAAAXXBBBBBBXXCCCCCC. X is don't care (future extension)

   kal_bool if_is_cs_ctrl_mode_configurable; ///< Not use now! Future chip may support. KAL_TRUE means chip-select control by sw or hw can be configured. Default is HW controll
   kal_bool if_config_cs_ctrl_as_sw_mode; ///< Not use now! Future chip may support. Valid when if_is_cs_ctrl_mode_configurable is KAL_TRUE.
   kal_bool if_is_sw_cs_ctrl; ///< KAL_TRUE is SW must control chip-select, otherwise, HW auto control,  for 58H/58/53EL
   kal_uint32 if_sw_cs_ctrl_reg_addr; ///< valid when if_is_sw_cs_ctrl is KAL_TRUE. You must turn on lcd power before access reg addr
   kal_uint32 if_sw_cs_ctrl_reg_bit; ///< valid when if_is_sw_cs_ctrl is KAL_TRUE. You must set or reset bit on if_sw_cs_ctrl_reg_addr

   kal_uint32 if_period; ///< delay between two transaction

   kal_bool __if_reg_fast_mode; ///< !!! Do NOT modify lcd interface manager internal usage
   kal_uint32 __if_reg_1; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_2; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_3; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_4; ///< !!! Do NOT modify, lcd interface manager internal usage
   kal_uint32 __if_reg_5; ///< !!! Do NOT modify, lcd interface manager internal usage  
   kal_uint32 __if_reg_6; ///< !!! Do NOT modify, lcd interface manager internal usage
}LCD_IOCTRL_DBI_SERIAL_IF_T;


typedef struct
{
   LCD_IF_TYPE_ENUM if_type; ///<   DBI parallel, DBI serial, DPI, DSI, or ...
   kal_uint32 if_cs_no; ///<   chip-select number for DBI interface
   union
   {
      LCD_IOCTRL_DBI_PARALLEL_IF_T  dbi_parallel_if;
      LCD_IOCTRL_DBI_SERIAL_IF_T     dbi_serial_if;
      void * dpi_if;
      void * dsi_if;
   }if_settings;///< according to if_type, user must use collect union member.  DPI, DSI is reserved for future expansion
}LCD_IOCTRL_DEVICE_IF_T;


typedef struct
{
   kal_uint32 lcm_width; ///< LCD Module's width
   kal_uint32 lcm_height; ///< LCD Module's height
   LCD_IOCTRL_DEVICE_IF_T lcd_if_setting; ///< LCD device interface settings
   kal_bool l_ui_on_p_lcm; ///< landscape ui on portrait lcm
}LCD_IOCTRL_LCD_SETTING_T;


typedef enum 
{
   // query
   LCD_IOCTRL_QUERY_MAIN_LCD_IF,  ///< use LCD_IOCTRL_LCD_SETTING_T* as p_argu and its size
   LCD_IOCTRL_QUERY_SUB_LCD_IF, ///< use LCD_IOCTRL_LCD_SETTING_T* as p_argu and its size

   LCD_IOCTRL_QUERY_DEVICE_IF, ///< use LCD_IOCTRL_DEVICE_IF_T* as p_argu and its size

   LCD_IOCTRL_QUERY_TOTAL_MOUNTED_DEVICE_NUMBER, ///< use kal_uint32* as p_argu and its size

   //config
   LCD_IOCTRL_CONFIG_MAIN_LCD_IF,  ///< use LCD_IOCTRL_LCD_SETTING_T* as p_argu and its size
   LCD_IOCTRL_CONFIG_SUB_LCD_IF, ///< use LCD_IOCTRL_LCD_SETTING_T* as p_argu and its size

   LCD_IOCTRL_CONFIG_DEVICE_IF,///< use LCD_IOCTRL_DEVICE_IF_T* as p_argu and its size

   LCD_IOCTRL_ACTION_MAX_ENUM
}LCD_IOCTRL_IF_ACTION_E;

typedef enum 
{
   LCD_IOCTRL_OK, ///< success
   LCD_IOCTRL_ERR_DEVICE_IF_NOT_SUPPORTED, ///< could be chip not support, or there is no this device mounted
   LCD_IOCTRL_ERR_PARA_CONFIG_NOT_SUPPORT,  ///< some paras user want to config is chip not supported
   LCD_IOCTRL_ERR_DEVICE_CS_NOT_SUPPORT,  ///< chip select not support
   LCD_IOCTRL_ERR_INVALID_HANDLE,  ///< invalid user handle
   LCD_IOCTRL_ERR_INVALID_ACTION, ///< invalide action enum id
   LCD_IOCTRL_ERR_NULL_ARGU_PTR, ///< NULL argument pointer
   LCD_IOCTRL_ERR_NOT_ENOUGH_ARGU_SIZE, ///< not enough argument size
   LCD_IOCTRL_ERR_MANAGER_INTERNAL, ///< error of lcd interface manager internal
   LCD_IOCTRL_ERR_NOT_IMPLEMENT, ///< error of not implement yet
   LCD_IOCTRL_ERR_OTHERS ///< error of unexpected by driver
}LCD_IOCTRL_RESULT_E;

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef enum
{
   LCD_DRIVING_4MA = 0,
   LCD_DRIVING_8MA = 1,
   LCD_DRIVING_12MA = 2,
   LCD_DRIVING_16MA = 3
}  LCD_DRIVING_CURRENT_ENUM;
#else
typedef enum
{
   LCD_DRIVING_2MA = 0,
   LCD_DRIVING_4MA = 1,
   LCD_DRIVING_6MA = 2,
   LCD_DRIVING_8MA = 3,
   LCD_DRIVING_10MA = 4,
   LCD_DRIVING_12MA = 5,
   LCD_DRIVING_14MA = 6,
   LCD_DRIVING_16MA = 7
}  LCD_DRIVING_CURRENT_ENUM;
#endif

void set_lcd_driving_current(kal_uint8 current);
void set_lcd_driving_current_serial0_1v8(kal_uint8 current);
void set_lcd_driving_current_serial0_2v8(kal_uint8 current);
void set_lcd_driving_current_serial1_1v8(kal_uint8 current);
void set_lcd_driving_current_serial1_2v8(kal_uint8 current);

/**
 * @brief            Get lcd ioctrl device interface handle for furthur ioctrl function calls.
 * @param user       The lcd interface user ID enum
 * @return           The ioctrl handle. 
 * @remarks          Non-zero values mean success. Zero means failure.
 */
kal_uint32 lcd_get_ioctrl_device_if_handle(LCD_IF_USER_ENUM user);


/**
 * @brief            Query or configure device interface setting which the device uses for sharing lcd interface
 * @param handle     The handle got from API call of lcd_get_ioctrl_device_if_handle.
 * @param action     The action of ioctrl. Query or configure the exact external device interface besides LCDs, or just want to know MAIN or SUB LCD w/o specific interface type or chip select number
 * @param p_argu     The pointer to input/output data structure.
 * @param argu_size  The exact size of argu passed into this function call.
 * @return           The result of this call. LCD_IOCTRL_OK means success, otherwise, it means different error code.
 * @remarks          This fuction call will check the argu_size according to the action passed in. If there is not enough size, assertion check failed. \n
 *                   LCD_IOCTRL_QUERY/CONFIG_MAIN/SUB_LCD_IF use LCD_IOCTRL_LCD_SETTING_T * as p_argu and sizeof(LCD_IOCTRL_LCD_SETTING_T) as argu_size. \n
 *                   LCD_IOCTRL_QUERY/CONFIG_DEVICE_IF use LCD_IOCTRL_DEVICE_IF_T * as p_argu and sizeof(LCD_IOCTRL_DEVICE_IF_T) as argu_size. \n
 *                   LCD_IOCTRL_QUERY_TOTAL_MOUNTED_DEVICE_NUMBER use kal_uint32 * as p_argu and sizeof(kal_uint32) as argu_size. 
 * @sa               lcd_get_ioctrl_device_if_handle
 */
LCD_IOCTRL_RESULT_E lcd_ioctrl_device_if_settings(kal_uint32 handle, LCD_IOCTRL_IF_ACTION_E action, void *p_argu, kal_uint32 argu_size);



/// @{

/// \page Application_Notes
///< Two examples of query and configure LCD settings or specific device settings which deivice shares external LCD interface.
/// \par
/// \note
/// Before calling the API of lcd_ioctrl_device_if_settings(~),  <b> interface user must turn on LCD controller clock or power via lcd power manager or tranditional mm power control APIs </b> \n Otherwise, LCD IO control will fail !!! \n
/// \n
/// \remark
/// Specially <b> notices the member \e if_is_set_clk_by_scl_counts , \e if_is_set_clk_by_scl_counts , or other \e if_is_xxxx_yyyy member variable in structure </b> because you must judge this if_is_xxxx_yyyy variable to configure different other variables for different chip designs. \n Check below SIM example\n
/// \n
/// \li Query or configure MAIN LCD without knowning which interface type or chip-select of MAIN LCD in advance.
/// \n \n
/// \{// declaration \} \n
/// kal_uint32 main_lcd_if_handle; \n
/// LCD_IOCTRL_LCD_SETTING_T main_lcd_setting; \n
/// \n
/// \{// get handle \} \n
/// main_lcd_if_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_MAIN_LCD); \n
/// \n
/// \{// query the main lcd if settings \} \n
/// err = lcd_ioctrl_device_if_settings(main_lcd_if_handle, LCD_IOCTRL_QUERY_MAIN_LCD_IF, & main_lcd_setting, sizeof(LCD_IOCTRL_DEVICE_IF_T); \n
///  \{// do error handling if(err != LCD_IOCTRL_OK); \} \n
/// \n
/// \{// modify the necessary part only \} \n
/// if(main_lcd_setting.lcd_if_setting.if_type == LCD_IF_TYPE_DBI_PARALLEL) \n
/// { \n
///     main_lcd_setting.lcd_if_setting.parallel_if.if_c2ws = 3; \n
///     main_lcd_setting.lcd_if_setting.parallel_if.if_wst = 1; \n
///     ............ \n
/// } \n 
/// else \n
/// { \n
///     ............ \n
/// } \n 
/// \n
/// \{// re-configure modified settings \} \n
/// err = lcd_ioctrl_device_if_settings(main_lcd_if_handle, LCD_IOCTRL_CONFIG_MAIN_LCD_IF, & main_lcd_setting, sizeof(LCD_IOCTRL_DEVICE_IF_T); \n
///  \{// do error handling if(err != LCD_IOCTRL_OK); \} \n
/// \line
/// \par
/// \li  Query or configure some specific device which shares external LCD interface and user knows the interface type or chip-select in advance. \n   For example, SIM driver uses lcd serial interface. Wifi uses lcd parallel interface. \n User must understand how to configure different chip's LCD controller registers which may differ evolutionary. \n
/// \n\n
/// \{// ===== MT6253 ===== \} \n
/// \{// declaration \} \n
/// kal_uint32 _lcd_if_mgr_serial_handle; \n
/// LCD_IOCTRL_DEVICE_IF_T _lcd_if_mgr_serial_setting; \n
/// \n
/// \{// get handle \} \n
/// _lcd_if_mgr_serial_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_SIM); \n
/// \n
/// \{// query the main lcd if settings \} \n
///  _lcd_if_mgr_serial_setting.if_type = LCD_IF_TYPE_DBI_SERIAL; \{ // according to real HW layout \}   \n
///  _lcd_if_mgr_serial_setting.if_cs_no = 0; \{ // according to real HW layout \}   \n
///  err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_QUERY_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting)); \n
///  \{// do error handling  if(err != LCD_IOCTRL_OK); \} \n
/// \n
/// \{ //  \}let interface user can write port directly and most effectively w/o any SW function call overhead.  \n 
/// \{ //  \} port address are as below  \n
/// \{ //  \} _lcd_if_mgr_serial_setting.dbi_serial_if.if_cmd_port_addr  \n
/// \{ //  \}_lcd_if_mgr_serial_setting.dbi_serial_if.if_data_port_addr  \n
/// \n
/// \{// modify the necessary part only \} \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_each_trans_length = 8; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_3wire_mode = KAL_FALSE; \n 
/// \{ //  \} target is 26MHz/4  \n
/// if(_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_set_clk_by_scl_counts) \n
/// {  \n
/// \{ //  \} 52MHz/8 = 26MHz/4 \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_low_count = 8; \n 
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_high_count = 8; \n 
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_low_count = 8; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_high_count = 8; \n
/// }  \n
/// else \n
/// { \n
/// \{ //  \} MT6253 run here \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_freq = 26*1000*1000; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_divider = 4; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_polarity = KAL_FALSE; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_cs_polarity = KAL_FALSE; \n
/// } \n
/// \n
/// \{// re-configure modified settings \} \n
/// err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_CONFIG_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting)); \n
///  \{// do error handling if(err != LCD_IOCTRL_OK); \} \n
/// \n
/// \{// ===== MT6258 ===== \} \n
/// \{// declaration \} \n
/// kal_uint32 _lcd_if_mgr_serial_handle; \n
/// LCD_IOCTRL_DEVICE_IF_T _lcd_if_mgr_serial_setting; \n
/// \n
/// \{// get handle \} \n
/// _lcd_if_mgr_serial_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_SIM); \n
/// \n
/// \{// query the device interface settings \} \n
///  _lcd_if_mgr_serial_setting.if_type = LCD_IF_TYPE_DBI_SERIAL; \{ // according to real HW layout \}   \n
///  _lcd_if_mgr_serial_setting.if_cs_no = 0;  \{ // according to real HW layout \} \n
///  err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_QUERY_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting)); \n
///  \{// do error handling  if(err != LCD_IOCTRL_OK); \} \n
/// \n
/// \{ //  \}let interface user can write port directly and most effectively w/o any SW function call overhead. \n
/// \{ //  \} port address are as below  \n
/// \{ //  \} _lcd_if_mgr_serial_setting.dbi_serial_if.if_cmd_port_addr  \n
/// \{ //  \}_lcd_if_mgr_serial_setting.dbi_serial_if.if_data_port_addr  \n
/// \n
/// \{// modify the necessary part only \} \n
/// \{// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_set_clk_by_scl_counts is KAL_TRUE on MT6258/H chips \} \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_each_trans_length = 8; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_3wire_mode = KAL_FALSE; \n 
/// \{ //  \} target is 26MHz/4 \n
/// if(_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_set_clk_by_scl_counts) \n
/// {  \n
/// \{ //  \} 52MHz/8 = 26MHz/4 \n
/// \{ //  \} MT6258H/58 run here \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_low_count = 8; \n 
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_wt_high_count = 8; \n 
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_low_count = 8; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.scl_rd_high_count = 8; \n
/// }  \n
/// else \n
/// { \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_freq = 26*1000*1000; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_divider = 4; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_clk_polarity = KAL_FALSE; \n
/// _lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_cs_polarity = KAL_FALSE; \n
/// } \n
/// \n
/// if(_lcd_if_mgr_serial_setting.if_settings.dbi_serial_if.if_is_sw_cs_ctrl) \n
/// { \n
/// \{ //  \} MT6258H/58 run here \n
/// \{ //  \}if_sw_cs_ctrl_reg_addr;  \{ //  \} valid when if_is_sw_cs_ctrl is KAL_TRUE. You must turn on lcd power before access reg addr \n
/// \{ //  \}if_sw_cs_ctrl_reg_bit;  \{ //  \}valid when if_is_sw_cs_ctrl is KAL_TRUE. You must set or reset bit on if_sw_cs_ctrl_reg_addr \n 
/// \{ //  \} just set or reset bit on register address of if_sw_cs_ctrl_reg_addr to HIGH or LOW external lcd chip select pin \n
/// } \n
/// \n
/// \{// re-configure modified settings \} \n
/// err = lcd_ioctrl_device_if_settings(_lcd_if_mgr_serial_handle, LCD_IOCTRL_CONFIG_DEVICE_IF, &_lcd_if_mgr_serial_setting, sizeof(_lcd_if_mgr_serial_setting)); \n
///  \{// do error handling if(err != LCD_IOCTRL_OK); \} \n

/// @}


#endif // __LCD_IF_MANAGER__


