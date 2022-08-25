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
 *  CustThemesRes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : CustThemesRes.h

      PURPOSE     : To define Common Structures used by the UI Elements and Cutomization Tool 
              for Customizing Themes

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : 01thSept 2003.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
*************************************************************/

#ifndef _PIXCOM_CUSTTHEMESRES_H
#define _PIXCOM_CUSTTHEMESRES_H

/* JL #include "MMIDataType.h" */
#include "MMI_features.h"

#include "gui_data_types.h"

#define MAX_COMPONENTS    1000
#define MAX_THEME_COMP_NAME_SIZE 55

typedef enum
{
    THEME_COMP_FA,
    THEME_COMP_COLOR,
    THEME_COMP_GRADIENT_COLOR
} THEME_COMP_TYPE;

typedef struct _gradient_color
{
    color *c;   /* List of colors in the gradient   */
    U8 *p;      /* Percentage of each color      */
    U8 n;       /* Number of colors in the list  */
} gradient_color;

typedef struct _UI_filled_area
{
    U32 flags;
    PU8 b;
    gradient_color *gc;
    color c;
    color ac;   /* alternate color used for hatch fills   */
    color border_color;
    color shadow_color;
    UI_transparent_color_type transparent_color;
} UI_filled_area;

typedef struct _MMI_theme
{
    /* Editor area theme */
    UI_filled_area  *inputbox_filler;

    /* Back ground filler of scrollbar */
    UI_filled_area  *scrollbar_background_filler;
    /* Indicator filler of scrollbar */
    UI_filled_area  *scrollbar_indicator_filler;

    /* Back ground filler of title */
    UI_filled_area  *title_filler;

    /* List menu background filler */
    UI_filled_area  *list_background_filler;
    /* Normal list menu item background filler */
    UI_filled_area  *list_normal_item_filler;
    /* Highlighted list menu item background filler */
    UI_filled_area  *list_selected_item_filler;
    /* Disabled list menu item background filler */
    UI_filled_area  *list_disabled_item_filler;
    /* Highlighted matrix menu item background filler */
    UI_filled_area  *matrix_selected_item_filler;

 //   UI_filled_area  *formatted_inputbox_normal_filler;
 //   UI_filled_area  *formatted_inputbox_selected_filler;

    /* Normal list main menu item background filler */
    UI_filled_area  *list_main_menu_normal_item_filler;
    /* Highlighted list main menu item background filler */
    UI_filled_area  *list_main_menu_selected_item_filler;
    /* Disabled list main menu item background filler */
    UI_filled_area  *list_main_menu_disabled_item_filler;

    /* Highlighted matrix main menu item background filler */
    UI_filled_area  *matrix_main_menu_selected_item_filler;

    /* General background filler, background of text and picture, usually is transparent color. 
    preview just an example. */
    UI_filled_area  *general_background_filler;

    UI_filled_area  *popup_description_background_filler;

    /* The theme for memu list seted by Inline Screen. It's the similar to the list filler, 
    such as list_background_filler */
    UI_filled_area  *inline_list_normal_item_filler;
    UI_filled_area  *inline_list_selected_item_filler;
    UI_filled_area  *inline_list_disabled_item_filler;

    /* The filler for inline singleline editor without border. At current, no one use it. */
    UI_filled_area  *inline_edit_focussed_filler;
    UI_filled_area  *inline_edit_unfocussed_filler;
    UI_filled_area  *inline_edit_noboundary_filler;

    /* Pin input editor filler */
    UI_filled_area  *PIN_inputbox_background_filler;
    UI_filled_area  *PIN_screen_background_filler;
    /* Data time background */
    UI_filled_area  *network_screen_background_filler;
    /* Background filler of call manager screen */
    UI_filled_area  *CM_screen_background_filler;
    /* The dialer input box background filler */
    UI_filled_area  *dialer_inputbox_background_filler;

    /* background filler of key when it is selected. */
    UI_filled_area  *virtual_keyboard_key_down_filler;

    /* Menu background filler of small list screen */
    UI_filled_area  *small_list_menu_normal_filler;
    /* Border filler of small list screen */
    UI_filled_area  *small_list_screen_border_filler;

    color           *lite_disp_scr_bg_color;

    /* Text color of normal left softkey */
    color           *LSK_up_text_color;
    /* Text color of down left softkey */
    color           *LSK_down_text_color;
    /* Text color of disabled left softkey */
    color           *LSK_disabled_text_color;

    /* Editor area theme */
    color           *inputbox_normal_text_color;
    color           *inputbox_selected_text_color;
    color           *inputbox_selector_color;
    color           *inputbox_cursor_color;

    /* Text color in title */
    color           *title_text_color;
    /* Text border color in title */
    color           *title_text_border_color;
    /* Text color of shortcut */
    color           *title_shortcut_text_color;

    /* Text color of the normal (unhighlited) list menu item */
    color           *list_normal_text_color;
    /* Text color of the highlighted list menu item */
    color           *list_selected_text_color;
    /* Text color of the disabled list menu item */
    color           *list_disabled_text_color;

    /* Text color of the normal (unhighlited) matrix menu item */
    color           *matrix_normal_text_color;
    /* Text color of the highlighted matrix menu item */
    color           *matrix_selected_text_color;
    /* Text color of the disabled matrix menu item */
    color           *matrix_disabled_text_color;

  //  color           *formatted_inputbox_cursor_color;

    /* Text color of the normal (unhighlited) list menu item for category 14*/
    color           *list_main_menu_normal_text_color;
    /* Text color of the highlighted list menu item for category 14 */
    color           *list_main_menu_selected_text_color;
    /* Text color of the disabled list menu item for category 14 */
    color           *list_main_menu_disabled_text_color;

    /* Text color of the normal (unhighlited) matrix menu item for category 14 */
    color           *matrix_main_menu_normal_text_color;
    /* Text color of the highlighted matrix menu item for category 14 */
    color           *matrix_main_menu_selected_text_color;
    /* Text color of the disabled matrix menu item for category 14 */
    color           *matrix_main_menu_disabled_text_color;


    color           *popup_description_text_color;

    /* Call manager screen text color */
    color           *CM_screen_text_color;

    /* Call manager screen data Time background */
    color           *datetime_bar_background_color;
    color           *datetime_bar_duration_background_color;
    color           *datetime_bar_date_text_color;
    color           *datetime_bar_time_text_color;
    color           *datetime_bar_duration_text_color;
    /* AOC text color */
    color           *datetime_bar_AOC_text_color;

    /* UCE information bar color */
    color           *information_bar_color;
    color           *input_method_text_color;
    /* The message remaining length text color */
    color           *remaining_length_text_color;

    /* Inline single line editor text color */
    color           *inline_edit_focussed_text_color;
    /* Not used */
    color           *inline_edit_unfocussed_text_color;
    /* Inline single line editor selected text color */
    color           *inline_edit_selected_text_color;
    /* Inline single line editor selector color */
    color           *inline_edit_selector_color;
    /* Inline single line editor cursor color */
    color           *inline_edit_cursor_color;

    color           *inline_list_normal_text_color;
    color           *inline_list_selected_text_color;
    color           *inline_list_disabled_text_color;

    /* Pin input editor text color */
    color           *PIN_inputbox_normal_text_color;
    /* Pin input editor selected text color	 */
    color           *PIN_inputbox_selected_text_color;
    /* Pin input editor selector color */
    color           *PIN_inputbox_selector_color;
    /* Pin input editor cursor color */
    color           *PIN_inputbox_cursor_color;

    /* The dialer input box text color */
    color           *dialer_inputbox_normal_text_color;
    /* The dialer input box selected text color */
    color           *dialer_inputbox_selected_text_color;
    /* The dialer input box selector color */
    color           *dialer_inputbox_selector_color;
    /* The dialer input box corsor color */
    color           *dialer_inputbox_cursor_color;

    /* text color of key when it is selected */
    color           *virtual_keyboard_key_down_text_color;
    /* text color of key when it is not selected */
    color           *virtual_keyboard_key_up_text_color;
    /* text color of dead key when it is selected */
    color           *virtual_keyboard_dead_key_down_text_color;
    /* text color of dead key when it is not selected */
    color           *virtual_keyboard_dead_key_up_text_color;
    /* text color of display area */
    color           *virtual_keyboard_disp_area_text_color;

    /* Data color */
    color           *idle_scr_date_color; 
    /* Time color */
    color           *idle_scr_time_color;
    /* Data border color */
    color           *idle_scr_date_border_color; 
    /* Time border color */
    color           *idle_scr_time_border_color;
    /* Network name color */
    color           *idle_scr_network_name_color; 
    /* Network name border color */
    color           *idle_scr_network_name_border_color; 
    /* Network status color */
    color           *idle_scr_network_status_color; 
    /* Network status border color */
    color           *idle_scr_network_status_border_color; 
    /* Network extra color */
    color           *idle_scr_network_extra_color; 
    /* Net work extra border color */
    color           *idle_scr_network_extra_border_color; 

    /* width of vertical scroll bar or height of horizontal scroll bar */
    S32             scrollbar_size;

    /* Full opacity of screen */
    S32             bg_opacity_full;
    /* High opacity of screen (Not used) */
    S32             bg_opacity_high;
    /* Medium opacity of screen */
  //  S32             bg_opacity_medium;
    /* Low opacity of screen */
    S32             bg_opacity_low;

    /* highlight fillers */
    /*
     * Highlight dimension for menu items
     *
     * HIGHLIGHT WIDTH = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP
     * HIGHLIGT HEIGHT: 
     *      Single-line     = MMI_MENUITEM_HEIGHT
     *      Two-line        = MMI_MENUITEM_HEIGHT * 2
     *      Multi-row       = MMI_MULTIROW_MENUITEM_HEIGHT
     *      Thick           = MMI_THICK_MENUITEM_HEIGHT = CAT425_MENUITEM_HEIGHT
     *      Thick with tab  = CAT425_MENUITEM_HEIGHT_NO_TAB
     *
     * If the menu item dimension does not fit perfectly, the highlight filler will be list_selected_item_filler.
     */
     /* Single-line highlighted menu item background filler */
    UI_filled_area  *menuitem_single_line_highlight_filler;
    /* Two-line highlighted menu item background filler */
    UI_filled_area  *menuitem_two_line_highlight_filler;
    /* Multi-row highlighted menu item background filler */
    UI_filled_area  *menuitem_multirow_highlight_filler;
    /* Thick highlighted menu item background filler */
    UI_filled_area  *menuitem_thick_highlight_filler;
    /* Thick with tab menu item background filler (Category 425 only)*/
    UI_filled_area  *menuitem_thick_with_tab_highlight_filler;
    /* Symbol picker highlight filler (Category 22 only)*/
    UI_filled_area  *symbol_picker_highlight_filler;
    /* Not used */
    UI_filled_area  *matrix_highlight_filler;

    /* full-screen background */
    /* Main menu background filler */
    UI_filled_area  *main_menu_bkg_filler;
    /* Sub menu background filler */
    UI_filled_area  *sub_menu_bkg_filler;
    /* Idle background filler */
    UI_filled_area  *idle_bkg_filler;

    /* popup background*/
    color           *popup_text_color;

    /* weekday in idle */
    color           *idle_scr_weekday_color;
    color           *idle_scr_weekday_border_color;

    /* clock */    
    /* Clock component: text color of date text for digital clock in main lcd */
    color           *date_text_color;
    /* Clock component: text border color of date text for digital clock in main lcd */
    color           *date_text_border_color;
    /* Clock component: text color of time text for digital clock in main lcd */
    color           *time_text_color;
    /* Clock component: text border color of time text for digital clock in main lcd */
    color           *time_text_border_color;
    /* Clock component: hour hand color of analog clock in main lcd */
    color           *analog_hand_hour_color;
    /* Clock component: minute hand color of analog clock in main lcd */
    color           *analog_hand_min_color;
    /* Clock component: Not used */
    color           *analog_axis_color;

    /* softkey */
    /* Text border color softkey((0, 0, 255)means no border) */
    color           *softkey_text_border_color;
    /* Back ground filler of softkey bar
                            128x128     128x160     176x220     240x320
    Wdith of softkey            50          50          70          74
    Height of softkey           18          19          20          36
    */
    UI_filled_area  *softkey_bar_bkg_filler;

    /* tab title */
    /* Filler of tab title */
    UI_filled_area  *tab_title_filler;
    /* Text color of tab title */
    color           *tab_title_text_color;
    /* Text border color of tab title */
    color           *tab_title_text_border_color;
    /* Shortcut color of tab title */
    color           *tab_title_shortcut_text_color;


    /* calendar */
    /* text color of title */
    color           *calendar_title_text_color;
    /* text color of year select */
    color           *calendar_horizontal_text_color;
    /* text border color of year select */
    color           *calendar_horizontal_border_color;
    /* text color of week number */
    color           *calendar_vertical_text_color;
    /* text color of month select */
    color           *calendar_horizontal_string_text_color;
    /* cell background color of one task state */
    color           *calendar_one_task_color;
    /* cell background color of more tasks state */
    color           *calendar_more_task_color;
    /* cell background color of menstrual state */
    color           *calendar_menstrual_color;
    /* cell background color of PP state */
    color           *calendar_PP_color;
    /* cell background color of danger state */
    color           *calendar_danger_color;
    /* cell background color of invalid state */
    color           *calendar_invalid_color;
    /* text color of cell valid state */
    color           *calendar_valid_text_color;
    /* text color of cell invalid state */
    color           *calendar_invalid_text_color;
    /* cell background color of highlight state */
    color           *calendar_highlight_color;
    /* background color of info box */
    color           *calendar_infobox_bg_color;
    /* background color of info box item */
    color           *calendar_infobox_entry_bg_color;
    /* text color of info box */
    color           *calendar_infobox_text_color;
    
    /* Status icon bar */
    /* Back ground filler of status icon bar */
    UI_filled_area  *status_icon_bar_filler;

    /* thick title */
    /* thick title back gournd filler */
    UI_filled_area  *thick_title_filler;
    /* text color of thick title */
    color           *thick_title_text_color;
    /* text border of thick title */
    color           *thick_title_text_border_color;
    /* shortcut color of thick title */
    color           *thick_title_shortcut_text_color;

    /* rotated screen */
    /* back ground filler of rotate screen*/
    UI_filled_area  *rotated_bkg_filler;
    /* filler of title in rotate screen */
    UI_filled_area  *rotated_title_filler;

    /* small screen */    
    /* filler of title in small screen */
    UI_filled_area  *small_screen_title_filler;

    /* tab bar */
    /* normal image for tab bar */
    UI_filled_area  *tab_normal_tab_filler;
    /* focused image for tab bar */
    UI_filled_area  *tab_highlight_tab_filler;
    /* focused image for tab bar */
    UI_filled_area  *tab_blink_tab_filler;

    /* main menu */
    /* high light filler of bidegree main menu */
    UI_filled_area  *main_menu_bidegree_tab_highlight_filler;
    /* high light image of matrix main menu */
    PU8             matrix_main_menu_highlight_image;
    /* background filler of bidegree main menu */
    UI_filled_area  *main_menu_bidegree_tab_background_filler;

    /* list menu */
    /* separator color in list menu */
 //   color           *list_separator_color;

    /* cascade menu */
    /* separator color of cascade menu */
    color           *cascade_menu_separator_color;
    /* normal text color of cascade menu */
    color           *cascade_menu_normal_text_color;
    /* selected text color of cascade menu */
    color           *cascade_menu_selected_text_color;
    /* disabled text color of cascade menu */
    color           *cascade_menu_disabled_text_color;
    /* border color of cascade menu */
    color           *cascade_menu_border_color;
    /* back ground filler of cascade menu */
    UI_filled_area  *cascade_menu_background_filler;
    /* high light filler of cascade menu */
    UI_filled_area  *cascade_menu_highlight_filler;
    /* left arrow image of cascade submenu */
    PU8             cascade_menu_submenu_left_arrow_image;
    /* right arrow image of cascade submenu */
    PU8             cascade_menu_submenu_right_arrow_image;

    /* check & radio */
    /* selected image for check */
    PU8             list_check_selected_image;
    /* unselected image for check */
    PU8             list_check_unselected_image;
    /* selected image for radio */
    PU8             list_radio_selected_image;
    /* unselected image for radio */
    PU8             list_radio_unselected_image;
	
  
/*list menuite auto number icons*/
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img1;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img2;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img3;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img4; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img5;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img6;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img7;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img8; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img9;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img10;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img11;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img12; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img13;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img14;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img15;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img16; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img17;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img18;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img19;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img20; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img21;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img22;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img23;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img24; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img25;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img26;   
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img27;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img28; 
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img29;
	/*list menuite auto number icon 1*/
	PU8 			list_menuitem_auto_number_img30;   

    /* Inline edit */
    /* left arrow image in inline edit */
    PU8             inline_edit_left_arrow_image;
    /* right arrow image in inline edit */
    PU8             inline_edit_right_arrow_image;

    /* inputbox */
    /* color of base line in inputbox */
    color           *inputbox_base_line_color;
    /* color of control character base line in ems */
    color           *inputbox_ems_cr_base_line_color;
    
    /* dialing */
    /* text color in dialer inputbox */
    color           *dialer_inputbox_text_color;
    /* border color in dialer inputbox */
    color           *dialer_inputbox_text_border_color;
        
    /* reserved for the future */
    /* left softkey down filler */
    UI_filled_area  *softkey_lsk_down_filler;
    /* left softkey up filler */
    UI_filled_area  *softkey_lsk_up_filler;       
    /* right softkey down filler */
   // UI_filled_area  *softkey_rsk_down_filler;        
    /* right softkey up filler */
    //UI_filled_area  *softkey_rsk_up_filler; 
    
    /* color of title background rect */
    color           *calendar_title_bg_color;
    /* color of horizontal_string background rect */
    color           *calendar_horizontal_string_bg_color;
    /* color of vertical_select background rect */
    color           *calendar_vertical_select_bg_color;
    /* color of cell_array background rect */
    color           *calendar_cell_array_bg_color;
    /* color of frame_line */
    color           *calendar_frame_line_color;
    /* color of cell frame line */
    color           *calendar_cell_line_color;
    /* text color of cell's current */   
    color           *calendar_cell_current_text_color;
    /* text color of popup */   
    color           *calendar_popup_text_color;
    /* color of popup background rect */
    color           *calendar_popup_bg_color;
    /* color of popup border */
    color           *calendar_popup_border_color;    
    /* alpha value of infobox's background */
    S32             calendar_infobox_bg_alpha;
    /* alpha value of title's background */
    S32             calendar_title_bg_alpha;
    /* alpha value of horizontal_string's background */
    S32             calendar_horizontal_string_bg_alpha;
    /* alpha value of vertical_select's background */
    S32             calendar_vertical_select_bg_alpha;
    /* alpha value of cell_array's background */
    S32             calendar_cell_array_bg_alpha;
    /* alpha value of frame line */
    S32             calendar_frame_line_alpha;   
    /* text color of title for static calendar on idle screen */
    color           *calendar_horizontal_string_text_for_idle_color;
    /* color of title background rect for static calendar on idle screen */
    color           *calendar_horizontal_string_bg_for_idle_color;
    /* text color of cell valid date for static calendar on idle screen */
    color           *calendar_cell_valid_text_for_idle_color;
    /* text color of cell invalid date for static calendar on idle screen */
    color           *calendar_cell_invalid_text_for_idle_color;
    /* color of cell array background rect for static calendar on idle screen */
    color           *calendar_cell_array_bg_for_idle_color;
    /* text of cell current date for static calendar on idle screen */
    color           *calendar_cell_current_text_for_idle_color;
    /* color of cell current date's rect border for static calendar on idle screen */
    color           *calendar_cell_highlight_for_idle_color;
    /* color of frame line for static calendar on idle screen */
    color           *calendar_frame_line_for_idle_color;
    /* color of cell line for static calendar on idle screen */
    color           *calendar_cell_line_for_idle_color;    
    /* alpha value of title rect background for static calendar on idle screen */
    S32             calendar_horizontal_string_bg_for_idle_alpha;
    /* alpha value of cell array rect background for static calendar on idle screen */
    S32             calendar_cell_array_bg_for_idle_alpha;
    /* alpha value of current date's rect background for static calendar on idle screen */
    S32             calendar_cell_current_bg_for_idle_alpha;
    /* alpha value of cell current date's border for static calendar on idle screen */
    S32             calendar_cell_highlight_for_idle_alpha;
    /* alpha value of frame line for static calendar on idle screen */
    S32             calendar_frame_line_for_idle_alpha;
    /* alpha value of cell line for static calendar on idle screen */
    S32             calendar_cell_line_for_idle_alpha;
    
    /* arrow indication color */
    color           *arrow_indication_color;
    /* arrow indication border color */
    color           *arrow_indication_border_color;
    
    /* idle back ground filler for dcd */
    UI_filled_area  *dcd_idle_bkg_filler;
    /* read text color for dcd */
    color           *dcd_idle_read_text_color;
    /* unread text color for dcd */
    color           *dcd_idle_unread_text_color;
    /* highlight filler for dcd channel list */
    UI_filled_area  *dcd_channel_list_highlight_filler;
    /* text color for dcd story view */
    color           *dcd_story_text_color;
    /* visited color for dcd story view */
    color           *dcd_story_visited_text_color;
    /* unvisited color for dcd story view */
    color           *dcd_story_unvisited_text_color;
    /* highlight bar color for dcd story view */
    color           *dcd_story_highlight_bar_color;

    /* SIM2 network name color */
    color           *idle_scr_sim2_network_name_color;
    /* SIM2 network name border color */
    color           *idle_scr_sim2_network_name_border_color;
    /* SIM2 network status color */
    color           *idle_scr_sim2_network_status_color;
    /* SIM2 network status border color */
    color           *idle_scr_sim2_network_status_border_color ;

    /* bakc ground filler for full height popup */
    UI_filled_area  *popup_full_height_screen_bg_filler;
    /* content text color for popup */
 //   color           *popup_content_text_color;

    /* text color for main menu */
    color           *main_menu_title_color;
    /* text border color for main menu */
    color           *main_menu_title_border_color;

    /* Under line color */
    color           *ime_underline_color;
    /* Indicator color */
    color           *ime_indicator_color;
    /* Focused area background filler */
    UI_filled_area  *ime_focused_background_filler;
    /* Non-focused area background filler */
    UI_filled_area  *ime_background_filler;
    /* Focused area border color */
    color           *ime_focused_border_color;
    /* Non-focused area background color */
    color           *ime_border_color;
    /* separator width */
    S32             ime_separator_width;
    /* separator color */
    color           *ime_separator_normal_color;
    /* focused separator color */
    color           *ime_focused_separator_color;
    /* text space */
    S32             ime_text_space;
    /* Label color */
    color           *ime_label_color;
    /* Cursor color */
    color           *ime_cursor_color;
    /* Arrow disabled color */
    color           *ime_arrow_disable_color;
    /* Arrow down color */
    color           *ime_arrow_down_color;
    /* Arrow up color */
    color           *ime_arrow_up_color;
    /* cand text color */
    color           *ime_cand_text_color;
    /* cand highlight text color */
    color           *ime_cand_highlighted_text_color;
    /* cand highlight color */
    color           *ime_cand_highlight_color;
    /* comp text color */
    color           *ime_comp_text_color;
    /* comp highlight text color */
    color           *ime_comp_highlighted_text_color;
    /* comp highlight color */
    color           *ime_comp_highlight_color;
    /* input text color */
    color           *ime_input_text_color;
    /* input highlight text color */
    color           *ime_input_highlighted_text_color;
    /* input highlight color */
    color           *ime_input_highlight_color;
    /* stroke color */
    color           *ime_stroke_color;
    /* highlighted stroke color */
    color           *ime_highlighted_stroke_color;
    /* stroke highlight color */
    color           *ime_stroke_highlight_color;
    /* tab special filler */
    UI_filled_area  *tab_special_filler;
    /* mini indicator background color */
  //  color           *mini_indicator_bg_color;
    /* mini indicator normal color */
   // color           *mini_indicator_normal_color;
    /* mini indicator tab color */
   // color           *mini_indicator_tab_color;
    /* media player content text color */
    color           *media_player_content_text_color;
    /* media player content border color */
    color           *media_player_content_text_border_color;
    /* first line text color in two line list */
   // color           *two_line_first_line_text_color;
    /* first line highlight text color in two line list */
   // color           *two_line_first_line_highlight_text_color;
    /* second line text color in two line list */
    color           *two_line_second_line_text_color;
    /* second line highlight text color in two line list */
    color           *two_line_second_line_highlight_text_color;
    /* two line second line selector filler */
//    UI_filled_area  *two_line_second_line_selector_filler;
    /* two line second line selector text color*/
//    color           *two_line_second_line_selector_text_color;
    /* first line text color in multirow*/
//    color           *multirow_first_line_text_color;
    /* first line highlight text color in multirow*/
//    color           *multirow_first_line_highlight_text_color;
    /* second line text color in multirow*/
//    color           *multirow_second_line_text_color;
    /* second line highlight text color in multirow*/
//    color           *multirow_second_line_highlight_text_color;
    /* third line text color in multirow*/
    color           *multirow_third_line_text_color;
    /* third line highlight text color in multirow*/
    color           *multirow_third_line_highlight_text_color;
    /* grid line color in list */
    color           *list_grid_line_color;
    /* alpha of grid line in list */
    S32             list_grid_line_alpha;
    /* highlight filler without scroll bar for single line */
//    UI_filled_area  *menuitem_single_line_highlight_without_scroll_filler;
    /* highlight filler without scroll bar for two line */
//    UI_filled_area  *menuitem_two_line_highlight_without_scroll_filler;
    /* highlight filler without scroll bar for multirow */
//    UI_filled_area  *menuitem_multirow_highlight_without_scroll_filler;
    /* highlight filler without scroll bar for thick line */
//    UI_filled_area  *menuitem_thick_highlight_without_scroll_filler;
    /* highlight filler without scroll bar for thick with tab */
//    UI_filled_area  *menuitem_thick_with_tab_highlight_without_scroll_filler;
    /* back ground image for dialing screen */
    PU8             dialing_screen_bg_image;
    /* small key up image for dialing screen */
    PU8             dialing_screen_skey_up_image;
    /* small key down image for dialing screen */
    PU8             dialing_screen_skey_down_image;
    /* large key up image for dialing screen */
    PU8             dialing_screen_lkey_up_image;
    /* large key down image for dialing screen */
    PU8             dialing_screen_lkey_down_image;
    /* editor text color in void dialer */
    color           *voip_dialer_editor_text_color;
    /* text color in header bar and information bar */
    color           *header_information_text_color;
    /* back ground image for popup call screen */
    PU8             CM_screen_popup_bkg_image;
    /* left softkey up filler in popup */
    UI_filled_area  *popup_embedded_lsk_normal_up_filler;
    /* left softkey down filler in popup */
    UI_filled_area  *popup_embedded_lsk_normal_down_filler;
    /* right softkey up filler in popup */
    UI_filled_area  *popup_embedded_rsk_normal_up_filler;
    /* right softkey down filler in popup */
    UI_filled_area  *popup_embedded_rsk_normal_down_filler;
    /* softkey text color in popup */
    color           *popup_embedded_softkey_text_color;
    /* softkey text border color in popup */
    color           *popup_embedded_softkey_text_border_color;
    /* softkey bar filler for popup screen */
    UI_filled_area  *popup_softkey_bar_filler;
    /* highlight filler in small list */
    UI_filled_area  *small_list_menu_highlight_filler;
    /* small list highlight text color*/
    color           *small_list_menu_highlight_text_color;
    /* small list text color */
    color           *small_list_menu_text_color;
    /* large current day text color in idle calendar */
    color           *calendar_idle_large_current_day_text_color;
    /* large current date text color in idle calendar */
    color           *calendar_idle_large_current_date_text_color;
    /* entry alpha in calendar */
    S32             calendar_infobox_entry_alpha;
    /* calendar idle background image */
    PU8             calendar_idle_bg_image;
    /* icon bar hint text color */
    color           *icon_bar_hint_text_color;
    /* hint filler for icon bar */
    UI_filled_area  *icon_bar_hint_filler;
    /* alphabet bar highlight color */
 //   color           *alphabet_bar_highlight_color;
    /* alphabet bar highlight alpha */
 //   S32             alphabet_bar_highlight_alpha;  
    /* virtual_keyboard_key_disabled_bg_color */
    color           *virtual_keyboard_key_disabled_bg_color;
    /* virtual_keyboard_key_disabled_bg_alpha */ 
    S32             virtual_keyboard_key_disabled_bg_alpha;
    /* virtual keyboard key disabled text color */
    color           *virtual_keyboard_key_disabled_text_color;
    /* virtual keyboard key large left icon image */
    PU8             virtual_keyboard_key_large_icon_left_image;    
    /* virtual keyboard key large right icon image */
    PU8             virtual_keyboard_key_large_icon_right_image;
    /* alpha for information bar */
    S32             information_bar_alpha;
    /* back ground filler for special screen */
    UI_filled_area  *special_screen_bkg_filler;
    /* highlight filler without scroll bar for small screen */
//    UI_filled_area  *small_list_menu_highlight_without_scrollbar_filler;
    /* back ground color for virtual keyboard */
//    color           *virtual_keyboard_bg_color;
    /* alpha for virtual keyboard */
//    S32             virtual_keyboard_bg_alpha;
    /* back gournd color for key in virtual keyboard */
//    color           *virtual_keyboard_key_bg_color;
    /* alpha for key in virtual keyboard */
//    S32             virtual_keyboard_key_bg_alpha;
    /* border color for key in virtual keyboard */
//    color           *virtual_keyboard_key_border_color;
    /*border alpha for key in virtual keyboard */
//    S32             virtual_keyboard_key_border_alpha;
    /* color for disabled key in virtual keyboard */
//    color           *virtual_keyboard_key_disable_color;
    /* alpha for disabled key in virtual keyboard */
//    S32             virtual_keyboard_key_disable_alpha;
    /* border color for disabled key in virtual keyboard */
//    color           *virtual_keyboard_key_disable_border_color;
    /* border alpha for disabled key in virtual keyboard */
//    S32             virtual_keyboard_key_disable_border_alpha;
    /* color for highlight key in virtual keyboard */
//    color           *virtual_keyboard_key_highlight_bg_color;
    /* alpha for highlight key in virtual keyboard */
//    S32             virtual_keyboard_key_highlight_bg_alpha;
    /* border color for highlight key in virtual keyboard */
//    color           *virtual_keyboard_key_highlight_border_color;
    /* border alpha for highlight key in virtual keyboard */
//    S32             virtual_keyboard_key_highlight_border_alpha;
    /* text color for popup hint key in virtual keyboard */
//    color           *virtual_keyboard_key_popup_hint_text_color;
    /* dialing screen large key disabled image*/
    PU8             dialing_screen_lkey_disable_image;
    /* back ground filler for ime information bar */
    UI_filled_area  *ime_information_bar_background_filler;
    /* focussed filler for inline datatime */
    UI_filled_area  *inline_datatime_focussed_filler;
    /* unfocussed filler for inline datatime */
    UI_filled_area  *inline_datatime_unfocussed_filler;
    /* cascading menu highlight left arrow*/
    PU8             cascade_menu_submenu_highlight_left_arrow_image;
    /* cascading menu highlight left arrow*/
    PU8             cascade_menu_submenu_highlight_right_arrow_image;
    /* color for subject in UCE */
    color           *uce_screen_subject_color;
    /* alpha for the background of readonly inline multiline */
    S32             inline_multiline_readonly_bg_alpha;
    /* color for the background of readonly inline multiline */
    color           *inline_multiline_readonly_bg_color;
    /* disabled left arrow image for cascading menu */
    PU8             cascade_menu_submenu_disabled_left_arrow_image;
    /* disabled right arrow image for cascading menu */
    PU8             cascade_menu_submenu_disabled_right_arrow_image;
    /* the image of pre button in UCE screen */
    PU8             UCE_screen_pre_button_image;
    /* the disabled image of pre button in UCE screen */
    PU8             UCE_screen_pre_button_disabled_image;
    /* the image of next button in UCE screen */
    PU8             UCE_screen_next_button_image;
    /* the disabled image of next button in UCE screen */
    PU8             UCE_screen_next_button_disabled_image;
    /* left area filler for normal tab */
//    UI_filled_area  *tab_normal_l_tab_filler;
    /* right area filler for normal tab */
//    UI_filled_area  *tab_normal_r_tab_filler;
    /* left area filler for highlight tab */
//    UI_filled_area  *tab_highlight_l_tab_filler;
    /* right area filler for highlight tab */
//    UI_filled_area  *tab_highlight_r_tab_filler;
    /* left area filler for blink tab */
//    UI_filled_area  *tab_blink_l_tab_filler;
    /* right area filler for blink tab */
//    UI_filled_area  *tab_blink_r_tab_filler;
    /* color for the icon bar item's text in its normal state */
    color           *icon_bar_item_text_normal_color;
    /* color for the icon bar item's text in its disabled state */
    color           *icon_bar_item_text_disable_color;
    /* the image of icon bar item left background in its normal up state */
    PU8             icon_bar_item_normal_left_background;
    /* the image of icon bar item left background in its press down state */
    PU8             icon_bar_item_pressed_left_background;
    /* the image of icon bar item right background in its normal up state */
    PU8             icon_bar_item_normal_right_background;
    /* the image of icon bar item right background in its press down state */
    PU8             icon_bar_item_pressed_right_background;
    /* the image of icon bar item left-right background in its normal up state */
    PU8             icon_bar_item_normal_left_right_background;
    /* the image of icon bar item left-right background in its press down state */
    PU8             icon_bar_item_pressed_left_right_background;
    /* the image of icon bar item center background in its normal up state */
    PU8             icon_bar_item_normal_center_background;
    /* the image of icon bar item center background in its press down state */
    PU8             icon_bar_item_pressed_center_background;
    /* The title text color of idle calendar */
    color           *calendar_title_text_color_for_idle;
    /* Idle calendar's cell text color for those cells that have event.  */
    color           *calendar_cell_event_text_color_for_idle;
    /* the area filler of DOW disabled background */
    UI_filled_area  *DOW_normal_background_filler;
    /* the area filler of DOW normal background */
    UI_filled_area  *DOW_highlight_background_filler;
    /* the area filler of DOW highlight background */
    UI_filled_area  *DOW_cell_normal_selected_filler;
    /* the area filler of DOW cell normal background */
    UI_filled_area  *DOW_cell_focus_selected_filler;
    /* the area filler of DOW cell highlight background */
    UI_filled_area  *DOW_cell_highlight_filler;    
    /* The background image for vk large icon. */
    PU8             popup_cell_normal_background;
    /* image of selected index of color select item */
    PU8             inline_item_color_select_highlighted_index_image;
    /* background image of color select item when it is highlighted */
    PU8             inline_item_color_select_highlighted_bg_image;
    /* background image of color select item when it is unhighlighted */
    PU8             inline_item_color_select_unhighlighted_bg_image;
    /* left arrow image when it is pushed down */
    PU8             inline_item_select_left_arrow_push_image;
    /* right arrow image when it is pushed down */
    PU8             inline_item_select_right_arrow_push_image;    
    /* The candidate box background of small size */
    PU8             ime_cand_background_small;
    /* The candidate box background of medium size */
    PU8             ime_cand_background_medium;
    /* The candidate box background of large size */
    PU8             ime_cand_background_large;
    /* The candidate box focus frame of small size */
    PU8             ime_cand_focus_frame_small;
    /* The candidate box focus frame of medium size */
    PU8             ime_cand_focus_frame_medium;
    /* The candidate box focus frame of large size */
    PU8             ime_cand_focus_frame_large;
    /* The candidates separator line of small size */
    PU8             ime_cand_separator_small;
    /* The candidates separator line of medium size */
    PU8             ime_cand_separator_medium;
    /* The candidates separator line of large size */
    PU8             ime_cand_separator_large;
    /* The pressed left arrow of small size */
    PU8             ime_cand_left_arrow_down_small;
    /* The pressed left arrow of medium size */
    PU8             ime_cand_left_arrow_down_medium;
    /* The pressed left arrow of large size */
    PU8             ime_cand_left_arrow_down_large;
    /* The normal left arrow of small size */
    PU8             ime_cand_left_arrow_up_small;
    /* The normal left arrow of medium size */
    PU8             ime_cand_left_arrow_up_medium;
    /* The normal left arrow of large size */
    PU8             ime_cand_left_arrow_up_large;
    /* The disabled left arrow of small size */
    PU8             ime_cand_left_arrow_disable_small;
    /* The disabled left arrow of medium size */
    PU8             ime_cand_left_arrow_disable_medium;
    /* The disabled left arrow of large size */
    PU8             ime_cand_left_arrow_disable_large;
    /* The pressed right arrow of small size */
    PU8             ime_cand_right_arrow_down_small;
    /* The pressed right arrow of medium size */
    PU8             ime_cand_right_arrow_down_medium;
    /* The pressed right arrow of large size */
    PU8             ime_cand_right_arrow_down_large;
    /* The normal right arrow of small size */
    PU8             ime_cand_right_arrow_up_small;
    /* The normal right arrow of medium size */
    PU8             ime_cand_right_arrow_up_medium;
    /* The normal right arrow of large size */
    PU8             ime_cand_right_arrow_up_large;
    /* The disabled right arrow of small size */
    PU8             ime_cand_right_arrow_disable_small;
    /* The disabled right arrow of medium size */
    PU8             ime_cand_right_arrow_disable_medium;
    /* The disabled right arrow of large size */
    PU8             ime_cand_right_arrow_disable_large;
    /* The focused candidate highlight background of small size */
    PU8             ime_cand_highlight_small;
    /* The focused candidate highlight background of medium size */
    PU8             ime_cand_highlight_medium;
    /* The focused candidate highlight background of large size */
    PU8             ime_cand_highlight_large;
    /* The unfocused candidate highlight background of small size */
    PU8             ime_cand_dull_highlight_small;
    /* The unfocused candidate highlight background of medium size */
    PU8             ime_cand_dull_highlight_medium;
    /* The unfocused candidate highlight background of large size */
    PU8             ime_cand_dull_highlight_large;
    /* The input box background of small size */
    PU8             ime_input_background_small;
    /* The input box background of medium size */
    PU8             ime_input_background_medium;
    /* The input box background of large size */
    PU8             ime_input_background_large;
    /* thin vertical scrollbar image */
    PU8             scrollbar_v_scroll_button_image;
    /* thin horizontal scrollbar image */
    PU8             scrollbar_h_scroll_button_image;
    /* wider vertical scrollbar top button image */
    PU8             wider_scrollbar_v_top_button_image;
    /* wider vertical scrollbar top clicked button image */
    PU8             wider_scrollbar_v_top_clicked_button_image;
    /* wider vertical scrollbar bottom button image */
    PU8             wider_scrollbar_v_bottom_button_image;
    /* wider vertical scrollbar bottom clicked button image */
    PU8             wider_scrollbar_v_bottom_clicked_button_image;
    /* wider vertical scrollbar middle background image */
    PU8             wider_scrollbar_v_background_button_image;
    /* wider vertical scrollbar scroll button image */
    PU8             wider_scrollbar_v_scroll_button_image;
    /* wider vertical scrollbar scroll clicked button image */
    PU8             wider_scrollbar_v_scroll_clicked_button_image;
    /* wider horizontal scrollbar left button image */
    PU8             wider_scrollbar_h_left_button_image;
    /* wider horizontal scrollbar left clicked button image */
    PU8             wider_scrollbar_h_left_clicked_button_image;
    /* wider horizontal scrollbar right button image */
    PU8             wider_scrollbar_h_right_button_image;
    /* wider horizontal scrollbar right clicked button image */
    PU8             wider_scrollbar_h_right_clicked_button_image;
    /* wider horizontal scrollbar middle background image */
    PU8             wider_scrollbar_h_background_button_image;
    /* wider horizontal scrollbar scroll button image */
    PU8             wider_scrollbar_h_scroll_button_image;
    /* wider horizontal scrollbar scroll clicked button image */
    PU8             wider_scrollbar_h_scroll_clicked_button_image;    
    /* slide bar background image */
    PU8             slide_bar_background_image;
    /* slide bar indicator image */
    PU8             slide_bar_indicator_image;    
    /* tab bar left button image */
    PU8             tab_bar_left_indicator_image;
    /* tab bar right button image */
    PU8             tab_bar_right_indicator_image;    
    /* All Editor default text color */
    color           *inputbox_default_text_color;
    /* Clipboard floating menu 1 button normal image normal background(Unpressed)  */
    PU8             clipboard_floating_menu_1_menu_button_normal_bg;
    /* Clipboard floating menu 1 button normal image press down background */
    PU8             clipboard_floating_menu_1_menu_button_pressed_bg;
    /* Clipboard floating menu left button of 2 button normal image background (Unpressed) */
    PU8             clipboard_floating_menu_2_menu_left_button_normal_bg;
    /* Clipboard floating menu left button of 2 button pressed down image background */
    PU8             clipboard_floating_menu_2_menu_left_button_pressed_bg;
    /* Clipboard floating menu right button of 2 button normal image background (Unpressed) */
    PU8             clipboard_floating_menu_2_menu_right_button_normal_bg;
    /* Clipboard floating menu right button of 2 button pressed down image background */
    PU8             clipboard_floating_menu_2_menu_right_button_pressed_bg;
    /* Clipboard floating menu middle button of 3 button normal image background (Unpressed) */
    PU8             clipboard_floating_menu_3_menu_middle_button_normal_bg;
    /* Clipboard floating menu middle button of 3 button pressed down image background */
    PU8             clipboard_floating_menu_3_menu_middle_button_pressed_bg;
    /* Clipboard floating menu arrow normal image background */
    PU8             clipboard_floating_menu_down_arrow_button_normal_bg_image;
    /* Clipboard floating menu arrow pressed down image background */
    PU8             clipboard_floating_menu_down_arrow_button_pressed_bg_image;
    /* clipboard floating menu text color */
    color           *clipboard_floating_menu_text_color;
    /* Editor remaining counter background */
    PU8             inputbox_remaining_counter_bg;
    /* All Editor highlighter alpha */
    S32             inputbox_highlighter_alpha;
    /* Color for the icon bar item's text border in its normal state */
    color           *icon_bar_item_text_border_normal_color;
    /* Color for the icon bar item's text border in its disabled state */
    color           *icon_bar_item_text_border_disable_color;
    /* Text border color of down softkey */
    color           *softkey_down_text_border_color;
    /* Text border color of disabled softkey */
    color           *softkey_disabled_text_border_color;
    /* Call manager screen text border color */
    color           *CM_screen_text_border_color;
    /* The text color of the highlight item of the unfocused candidate box */
   // color           *ime_cand_dull_highlighted_text_color;
    /* slide bar's background image in focused state */
    PU8             slide_bar_focused_bg_image;
    /* slide bar's indicator image in focused state */
    PU8             slide_bar_focused_indicator_image;
    /* horizontal select background filler */
    UI_filled_area  *horizontal_select_bg_filler;
    /* horizontal select focused background filler */
    UI_filled_area  *horizontal_select_focused_bg_filler;
    
    UI_filled_area  *inline_item_progress_bar_highlight_bg_filler;
    
    UI_filled_area  *inline_item_progress_bar_unhighlight_bg_filler;
    
    UI_filled_area  *inline_item_progress_bar_gradient_progress_filler;
    
    UI_filled_area  *inline_item_progress_bar_normal_progress_filler;
    
    UI_filled_area  *inline_item_progress_bar_step_filler;
    
    UI_filled_area  *inline_item_progress_bar_button_pressed_filler;
    
    UI_filled_area  *inline_item_progress_bar_button_normal_filler;
    
    color           *inline_item_progress_bar_text_color;
    
    UI_filled_area  *inline_item_displayonly_rdonly_style_bg_filler;
    /* button filler showed when buttion item is highlight and is pushed down */
    UI_filled_area  *inline_item_button_highlighted_pressed_bg_filler;
    /* button filler showed when buttion item is highlight and is normal */
    UI_filled_area  *inline_item_button_highlighted_normal_bg_filler;
    /* button filler showed when buttion item is not highlight and is pushed down */
    UI_filled_area  *inline_item_button_unhighlighted_pressed_bg_filler;
    /* button filler showed when buttion item is not highlight and is normal */
    UI_filled_area  *inline_item_button_unhighlighted_normal_bg_filler;
    /* text edit background showed when text edit item is highlight */
    UI_filled_area  *inline_item_textedit_highlighted_bg_filler;
     /* text edit background showed when text edit item is unhighlight */
    UI_filled_area  *inline_item_textedit_unhighlighted_bg_filler;
    /* Clipboard floating menu up arrow normal image background */
    PU8             clipboard_floating_menu_up_arrow_button_normal_bg_image;
    /* Clipboard floating menu up arrow presses image background */
    PU8             clipboard_floating_menu_up_arrow_button_pressed_bg_image;
    /* calendar current date background filler */
    UI_filled_area  *calendar_current_bg_filler;
    /* idle calendar current date background filler */
    UI_filled_area  *calendar_current_bg_for_idle_filler;
    /* Popup background filler */
    UI_filled_area  *popup_screen_bg_filler;
    /* background filler of rotate popup screen */
    UI_filled_area  *rotated_popup_screen_bg_filler;

    /* Small screen editor border color. */
    color           *editor_small_screen_border_color;
    /* In the message editor screen, the background color of the add recipient button. */
    PU8             editor_recipient_button_image;
    /* In the message editor screen, the text color of the add recipient button. */
    color           *editor_recipient_button_text_color;
    /* singleline editor background color. */
    UI_filled_area  *singleline_editor_bg_filler;
    /* In the stopwatch screen, the active timer text color. */
    color           *stopwatch_active_timer_text_color;
    /* In the stopwatch screen, the inactive timer text color. */
    color           *stopwatch_inactive_timer_text_color;
    /* Progress bar to show the slide progress. */
    PU8             mms_viewer_progress_bar_img;
} MMI_theme;

typedef struct __ThemesCompInfo
{
    void *themeComponent;
    U8 type;
    U8 themeCompName[MAX_THEME_COMP_NAME_SIZE];

} THEMES_COMPONENT_INFO;
typedef struct
{
#ifdef __MMI_DLT_CACHE_SUPPORT__
    U8 image_type;
#endif 
    U16 image_id;
    U32 image_offset;
#ifdef __MMI_DLT_CACHE_SUPPORT__
    PU8 image_cache_ptr;
#endif 
} theme_image_detail_struct;

typedef struct
{
    MMI_theme *theme;
    theme_image_detail_struct *theme_image_details_list;
    U8 **system_image_list;
} theme_details_struct;

/* __CUSTPACK_MULTIBIN */
typedef struct CustPack_Theme_Header
{
    S32 n_themes;
#ifdef __MMI_THEMES_V2_SUPPORT__
    theme_details_struct *mmi_themes;
#else 
    MMI_theme **mmi_themes;
#endif
    char * theme_model;
} CUSTPACK_THEME_HEADER;

#endif /* _PIXCOM_CUSTTHEMESRES_H */ 

