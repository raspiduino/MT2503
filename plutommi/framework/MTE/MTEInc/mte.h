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

/*******************************************************************************
 * Filename:
 * ---------
 *  mte.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MTE internal header file  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MTE_H__
#define __MTE_H__

#ifndef __MTK_TARGET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern stFontAttribute wgui_dialer_box_f1;
extern stFontAttribute wgui_dialer_box_f2;

/***************************************************************************** 
 * Define
 *****************************************************************************/
// TODO: add these into osc_enum_isr_src enum in osc_type.h
#define MTE_MMI_TO_MTE_ISR OSC_ISR_SRC_MTE_MMI_TX
#define MTE_MTE_TO_MMI_ISR OSC_ISR_SRC_MTE_MMI_RX

#if defined(__MMI_MAINLCD_96X64__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_128x128
#elif defined(__MMI_MAINLCD_128X64__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_128x128
#elif defined(__MMI_MAINLCD_128X128__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_128x128
#elif defined(__MMI_MAINLCD_128X160__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_128x160
#elif defined(__MMI_MAINLCD_176X220__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_176x220
#elif defined(__MMI_MAINLCD_240X320__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_240x320
#elif defined(__MMI_MAINLCD_240X240__)
	#define MTE_CURRENT_LCD_RES MMI_MTE_LCD_240x240
#elif defined(__MMI_MAINLCD_320X240__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_320x240
#elif defined(__MMI_MAINLCD_240X400__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_240x400
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define MTE_CURRENT_LCD_RES MMI_MTE_LCD_320x480
#else
    #error "MTE: NOT SUPPORTED RESOLUTION"    
#endif

#define MMI_MTE_MAX_PATH_LEN                1024                /* max 1024 ASCII file path length */
#define MMI_MTE_MAX_IMAGE_RESOURCE_SIZE     (4 * 1024 * 1024)   /* 4 MB buffer to store images */
#define MMI_MTE_ABM_TEMP_FILENAME           "_abm_temp.abm"     /* ABM temp file name */
#define MMI_MTE_EXAMPLE_SCREEN_BUF_SIZE     1024

#define MTE_UNUSED_PARAMETER(x)         ((void)(x))

/* invalid filter component, must be a negative number larger than the number of components */
#define MMI_MTE_INVALID_FILTER_COMPONENT           -16888

// TODO: use official IDs
#define MMI_MTE_MESSAGE_ID      MSG_ID_MTE_MMI_RPC_REQ
#define SCR_ID_MTE_EXAMPLE      16888
#define SCR_ID_MTE_EXAMPLE_STATUS_ICON      	SCR_ID_MTE_EXAMPLE + 1
#define GRP_ID_MTE_EXAMPLE      SCR_ID_MTE_EXAMPLE
#define GRP_ID_DUMMY_MTE_EXAMPLE     SCR_ID_MTE_EXAMPLE+10
#define SCRN_ID_DUMMY_MTE_EXAMPLE    SCR_ID_MTE_EXAMPLE+10

/* MTE debug macro */
#define MTE_DEBUG               /* kal_printf */

/* Chip platform */

/* 
 * MMI font names
 * 
 * Note: make sure the consistency of mmi_mte_theme_font_data_type_enum is correct.
 */
#define MMI_MTE_FONT_NAME_DECLARE(name)   #name
#define MMI_MTE_FONT_DECLARE(name)        {name, MMI_MTE_FONT_NAME_DECLARE(name)}

#define MMI_MTE_FONT_DEFAULT      &MMI_default_font
#define MMI_MTE_FONT_UI_DEFAULT   &UI_DEFAULT_FONT
#define MMI_MTE_FONT_SMALL        &MMI_small_font           
#define MMI_MTE_FONT_MEDIUM       &MMI_medium_font          
#define MMI_MTE_FONT_LARGE        &MMI_large_font           
#define MMI_MTE_FONT_VKBD         &MMI_virtual_keyboard_font
#define MMI_MTE_FONT_SUBLCD       &MMI_sublcd_font          
#define MMI_MTE_FONT_DIALER_F1    &wgui_dialer_box_f1       
#define MMI_MTE_FONT_DIALER_F2    &wgui_dialer_box_f2       
#define MMI_MTE_FONT_MEDIUM_BOLD  &MMI_medium_bold_font
#define MMI_MTE_FONT_NEW_FONT1    &newfont1
#define MMI_MTE_FONT_NEW_FONT2    &newfont2
#define MMI_MTE_FONT_NEW_FONT3    &newfont3
#define MMI_MTE_FONT_NEW_FONT4    &newfont4

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef int (*func_10_int_params_ptr)(int, int, int, int, int, int, int, int, int, int);
typedef void (*void_func_ptr)(void);

typedef enum
{
    MMI_MTE_SCREEN_FILTER_COMP_OPERATION_NONE,
    MMI_MTE_SCREEN_FILTER_COMP_OPERATION_ADD,
    MMI_MTE_SCREEN_FILTER_COMP_OPERATION_REMOVE,
    MMI_MTE_SCREEN_FILTER_COMP_OPERATION_NUM   
} mmi_mte_screen_filter_comp_operation_enum;

typedef struct
{
    U32     id;
    U8*     buf;
    U32     size;
} mmi_mte_resource_map_struct;

typedef enum
{
    MMI_MTE_LANG_ENGLISH,
    MMI_MTE_LANG_SIMPLIFIED_CHINESE,
    MMI_MTE_LANGUAGE_NUM
} mmi_mte_language_enum;

typedef struct
{
    const wchar_t **example_screen_name;
    const wchar_t **theme_component_group_name;    
    const wchar_t **theme_component_description;
} mmi_mte_language_string_struct;


typedef struct
{
    UI_font_type    ptr;
    const char      *name;
} mmi_mte_font_struct;

#if defined(__MMI_MAINLCD_128X128__)
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    13
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     9

#elif defined(__MMI_MAINLCD_128X160__)
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    13
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     9

#elif defined(__MMI_MAINLCD_176X220__)
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    13  
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     9  

#elif defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_FTE_SUPPORT__      
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    35
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     36
#else
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    20
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     20
#endif

#elif defined(__MMI_MAINLCD_320X240__)
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    20  
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     20
        
#elif defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__      
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    35
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     36
#else
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    20
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     20
#endif

#elif defined(__MMI_MAINLCD_320X480__)
#ifdef __MMI_FTE_SUPPORT__      
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    40
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     45
#else
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    32
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     32
#endif
  
#else
#define INLINE_FTE_SELECTOR_ARROW_HEIGHT    0
#define INLINE_FTE_SELECTOR_ARROW_WIDTH     0
 
#endif 

/*
 * MTE data
 */
#include "mte_data.h"

/*
 *
 * MTE RPC 
 *
 */
#define MMI_MTE_API_NEED_SYNC_NUM   14

static int mmi_mte_api_need_sync_index[MMI_MTE_API_NEED_SYNC_NUM] =
{
    7, 8, 9, 13, 17, 18, 20, 23, 30, 33, 34, 38, 40, 41
};

#if defined(__MSLT__)
/* for MSLT tool, NOT MTE-RELATED */
extern void mmi_mslt_check_string(int number_of_strings, int string_id[], char *strings[], int number_of_regions[], int *region_ids[], int ret[], char *display_strings[]);
#endif /* defined(__MSLT__) */
extern S32 mmi_mte_is_active(void);

void_func_ptr g_mmi_mte_function_table[] =
{
    (void_func_ptr)mmi_mte_get_baseband_chip, // 0
    (void_func_ptr)mmi_mte_get_lcd_resolution, // 1
    (void_func_ptr)mmi_mte_get_theme_component_symbol_info, // 2
    (void_func_ptr)mmi_mte_translate_font_pointer, // 3
    (void_func_ptr)mmi_mte_get_font_symbol, // 4
    (void_func_ptr)mmi_mte_get_theme_component_image_info, // 5
    (void_func_ptr)mmi_mte_get_image_info_string, // 6
    (void_func_ptr)mmi_mte_get_image_dimension, // 7
    (void_func_ptr)mmi_mte_start_decode_image, // 8
    (void_func_ptr)mmi_mte_stop_decode_image, // 9
    (void_func_ptr)mmi_mte_get_theme_schema_version, // 10
    (void_func_ptr)mmi_mte_get_theme_component_num, // 11
    (void_func_ptr)mmi_mte_get_theme_component, // 12
    (void_func_ptr)mmi_mte_get_theme_components_in_current_screen, // 13
    (void_func_ptr)mmi_mte_get_component_group_num, // 14
    (void_func_ptr)mmi_mte_get_component_group_name, // 15
    (void_func_ptr)mmi_mte_get_system_theme_data, // 16
    (void_func_ptr)mmi_mte_refresh_screen, // 17
    (void_func_ptr)mmi_mte_activate_theme, // 18
    (void_func_ptr)mmi_mte_translate_theme_component_data_pointer, // 19
    (void_func_ptr)mmi_mte_register_switch_screen_callback, // 20
    (void_func_ptr)mmi_mte_get_example_screen_num, // 21
    (void_func_ptr)mmi_mte_get_example_screen_name, // 22
    (void_func_ptr)mmi_mte_show_example_screen, // 23
    (void_func_ptr)mmi_mte_set_image_source, // 24
    (void_func_ptr)mmi_mte_get_image_resource_total_size, // 25
    (void_func_ptr)mmi_mte_set_language, // 26
    (void_func_ptr)mmi_mte_get_welcome_string, // 27
    (void_func_ptr)mmi_mte_get_image_data_length, // 28
    (void_func_ptr)mmi_mte_get_image_header, // 29
    (void_func_ptr)mmi_mte_get_current_system_theme, // 30
    (void_func_ptr)mmi_mte_get_image_resource_info, // 31
    (void_func_ptr)mmi_mte_set_state, // 32
    (void_func_ptr)mmi_mte_show_example_screen_by_group, // 33    
    (void_func_ptr)mmi_mte_encode_abm_image, // 34
    (void_func_ptr)mmi_mte_get_value, // 35
    (void_func_ptr)mmi_mte_set_value, // 36
    (void_func_ptr)mmi_mte_map_theme_component_name_to_old_branch, // 37
    (void_func_ptr)mmi_mte_get_image_frame_count, // 38
    (void_func_ptr)mmi_mte_get_image_sequence_header, // 39    
#if defined(__MSLT__)
    (void_func_ptr)mmi_mslt_check_string, // 40 // This function belongs to MSLT.
#else /* defined(__MSLT__) */
    (void_func_ptr)NULL,                  // 40
#endif /* defined(__MSLT__) */
    (void_func_ptr)mmi_mte_is_controlarea_in_current_screen,  //41
	(void_func_ptr)mmi_mte_get_image_9slice_header  //42
};

static const wchar_t **g_mmi_mte_example_screen_name = g_mmi_mte_example_screen_name_EN;
static const wchar_t **g_mmi_mte_theme_component_description = g_mmi_mte_theme_component_description_EN;
static const wchar_t **g_mmi_mte_theme_component_group_name = g_mmi_mte_theme_component_group_name_EN;

static const mmi_mte_language_string_struct g_mmi_mte_language[MMI_MTE_LANGUAGE_NUM] =
{
    {g_mmi_mte_example_screen_name_EN, g_mmi_mte_theme_component_group_name_EN, g_mmi_mte_theme_component_description_EN},
    {g_mmi_mte_example_screen_name_GB, g_mmi_mte_theme_component_group_name_GB, g_mmi_mte_theme_component_description_GB},
};

#endif /* __MTK_TARGET__ */

#endif /* __MTE_H__ */


