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
 *  EcompassProt.h
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**************************************************************

   FILENAME    : EcompassProt.h

   PURPOSE     : It contains the prototype declaration of internally used functions

   REMARKS     : nil

   AUTHOR      : Manpreet Singh

   DATE        : 05/01/2009

**************************************************************/
#ifndef __ECOMPASS_PROT_H__
#define __ECOMPASS_PROT_H__

#include "MMI_features.h"
#ifdef __MMI_ECOMPASS__

#include "Gui_data_types.h"
#include "MMIDataType.h"
//#include "Mmi_cb_mgr_gprot.h"

/***************************************************************************** 
* Local Function Declaration 
*****************************************************************************/
/* Init function */
extern void mmi_ecompass_init_app(void);
extern void mmi_ecompass_nvram_initialization(void);
extern void mmi_ecompass_set_protocols(void);

/* Highlight functions */
extern void HighlightEcompassMenu(void);
extern void HighlightEcompassCalibrateMenu(void);
extern void HighlightEcompassDeclinationMenu(void);
extern void HighlightEcompassLocationMenu(void);
extern void HighlightEcInputItem(S32 index);

extern void mmi_ecompass_hint_declination_menu();
extern void mmi_ecompass_hint_location_menu();
/* UI functions */
extern void mmi_ecompass_entry_clb_choice_screen(void);
extern void mmi_ecompass_entry_information_screen(void);
extern void mmi_ecompass_entry_processing_screen(void);
extern void mmi_ecompass_entry_direction_main_screen(void);
extern void mmi_ecompass_exit_from_app(void);
extern void mmi_ecompass_entry_options_screen(void);
extern void mmi_ecompass_entry_options_location_screen(void);
extern void mmi_ecompass_entry_options_declination_screen(void);
extern void mmi_ecompass_entry_options_cali_manual_screen(void);
extern void mmi_ecompass_set_hilited_item_country(void);
extern void mmi_ecompass_entry_set_city_screen(void);
extern void mmi_ecompass_current_city_index(void);
extern void mmi_ecompass_set_declination(void);
extern void mmi_ecompass_setinline_declination(void);
extern void mmi_ecompass_get_direction(void);
extern void mmi_ecompass_get_curr_city_nvram(U8 nDataItemId, U16 *pBuffer);
extern U8 mmi_ecompass_get_nearby_idx(UI_character_type inp);
extern void mmi_ecompass_multi_tap_complete_hdlr(void);
extern void mmi_ecompass_multi_tap_hdlr(UI_character_type inp);
extern void mmi_ecompass_country_idx_hilite_handler(S32 cityIndex);
extern void mmi_ecompass_construct_country_list(void);
extern pBOOL mmi_ecompass_country_async_callback(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern void mmi_ecompass_exit_set_country(void);
extern S16 mmi_ecompass_calculate_north_declination(void);
extern void mmi_ecompass_get_current_city_nvram(void);
extern void mmi_ecompass_mecca_title_string(U8 mecca_string[]);
extern void mmi_ecompass_signal_string(U8 signal[]);
extern void mmi_ecompass_exit_inline(void);
extern void mmi_ecompass_go_back_inline(void);
extern U16 GetActiveScreenId(void);
extern void set_leading_zero(U8 u8type);
extern void mmi_ecompass_entry_main_from_clb_choice(void);
extern void mmi_ecompass_cancel_cali_processing_screen(void);
extern void mmi_ecompass_cancel_cali_go_to_idle(void);
extern S32 mmi_ecompass_get_current_country_index_cat(void);
extern S32 mmi_ecompass_get_current_city_index_cat(void);
extern void mmi_ecompass_exit_app_endkey(void);
extern void mmi_ecompass_start_cali_show_processing(void);
extern void mmi_ecompass_set_cali_result(U8 cali_result);
extern pBOOL mmi_ecompass_get_cali_result(void);
/* callback */
extern void mmi_ecompass_get_calibration_status_handler(void *calMsg);
extern void mmi_ecompass_get_data_update(void *dataMsg);
extern void mmi_ecompass_toggle_sensor_backlight(void *Bcklight_msg);
extern void mmi_ecompass_deinitialize(void);

/*Prototypes for Screen group and CUI */
void mmi_ecompass_pre_entry_information_screen(void);


//mmi_ret mmi_ec_main_grp_proc(mmi_event_struct *evt);
//mmi_ret mmi_ec_options_proc(mmi_event_struct *evt);
#ifdef __MMI_BASIC_UI_STYLE__
extern S32 mmi_ecompass_country_async_callback_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif

#endif /* __MMI_ECOMPASS__ */ 
#endif /* __ECOMPASS_PROT_H__ */ 

