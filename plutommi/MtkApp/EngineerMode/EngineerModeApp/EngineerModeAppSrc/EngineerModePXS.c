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
 *  EngineerModePXS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer Mode PXS sensor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

 
#include "MMI_features.h"
#ifdef __MMI_EM_DEV_PXS_SENSOR__
     
#ifdef WIN32
#include <windows.h>
#endif 

 /*****************************************************************************
 * Include
 *****************************************************************************/
#include "mmi_include.h"
#include "Fat_fs.h"     /* File System, must after "GlobalConstants.h" */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "lcd_sw_rnd.h" /* lcd */
#include "lcd_if.h"     /* lcd */
    
#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio lib */
#include "kal_release.h"        /* kal */
    
    //#include "SettingProfileEnum.h"
#include "ProfilesSrvGProt.h"
    
#include "GpioSrvGprot.h"    /* TurnOnBacklight */
    
#include "MenuCuiGprot.h"
    
#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeResDef.h"
#include "EngineerModeAppResDef.h"
    //#include "EngineerModeMotion.h"
    
#include "mmi_rp_app_engineermode1_def.h"
    
#include "FSEditorCuiGprot.h"
    
    
#include "SensorSrvGport.h"
    
#include "math.h"        /* atan */
    
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui.h"
#include "gdi_include.h"
#include "stdlib.h"
#include "gui_data_types.h"
#include "stack_config.h"
#include "gui_themes.h"
#include "kal_public_api.h"
#include "string.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"

#include "InlineCuiGprot.h"

#include "TimerEvents.h"
#include "EngineerModeCommUI.h"
#include "mmi_frm_scenario_gprot.h"

/*****************************************************************************
* Define
*****************************************************************************/
#define MAX_PXS_SENSOR_PARA_NUM     (8)


/*****************************************************************************
* Global Variable
*****************************************************************************/
U16 g_gourp_menu_id;
U16 g_gourp_inline_id;

U16 g_cui_menu_id;
U16 g_cui_inline_id;

U32 g_timer_delay = 0;

extern DCL_HANDLE g_pxs_handle;

extern MMI_BOOL srv_sensor_pxs_get_raw_data(U16 *em_param);
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);
//extern U8 mmi_frm_entry_new_screen(U16 new_scrn_id, exit_func_ptr new_exit_handler, entry_func_ptr new_entry_handler, void *flag);







typedef enum
{
    MMI_EM_PXS_INLINE_P1_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
    MMI_EM_PXS_INLINE_P1_EDITOR,
    MMI_EM_PXS_INLINE_P2_CAPTION,
    MMI_EM_PXS_INLINE_P2_EDITOR,
    MMI_EM_PXS_INLINE_P3_CAPTION,
    MMI_EM_PXS_INLINE_P3_EDITOR,
    MMI_EM_PXS_INLINE_P4_CAPTION,
    MMI_EM_PXS_INLINE_P4_EDITOR,    
    MMI_EM_PXS_INLINE_P5_CAPTION,
    MMI_EM_PXS_INLINE_P5_EDITOR,    
    MMI_EM_PXS_INLINE_P6_CAPTION,
    MMI_EM_PXS_INLINE_P6_EDITOR,    
    MMI_EM_PXS_INLINE_P7_CAPTION,
    MMI_EM_PXS_INLINE_P7_EDITOR,    
    MMI_EM_PXS_INLINE_P8_CAPTION,
    MMI_EM_PXS_INLINE_P8_EDITOR,
    MMI_EM_PXS_INLINE_TOTAL
} mmi_em_pxs_inline_item_enum;

cui_inline_item_caption_struct inline_init_str[] = 
{
    STR_ID_EM_DEV_PXS_CAPTION_P1,
    STR_ID_EM_DEV_PXS_CAPTION_P2,
    STR_ID_EM_DEV_PXS_CAPTION_P3,
    STR_ID_EM_DEV_PXS_CAPTION_P4,
    STR_ID_EM_DEV_PXS_CAPTION_P5,
    STR_ID_EM_DEV_PXS_CAPTION_P6,
    STR_ID_EM_DEV_PXS_CAPTION_P7,
    STR_ID_EM_DEV_PXS_CAPTION_P8
    
};

cui_inline_item_text_edit_struct inline_editor_buff[] = 
{
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL},
    {0,0,9,IMM_INPUT_TYPE_ASCII_CHAR,0,NULL}
};


static const cui_inline_set_item_struct inline_item[] =
{
    {MMI_EM_PXS_INLINE_P1_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[0]},
    {MMI_EM_PXS_INLINE_P1_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[0]},
    {MMI_EM_PXS_INLINE_P2_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[1]},
    {MMI_EM_PXS_INLINE_P2_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[1]},
    {MMI_EM_PXS_INLINE_P3_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[2]},
    {MMI_EM_PXS_INLINE_P3_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[2]},
    {MMI_EM_PXS_INLINE_P4_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[3]},
    {MMI_EM_PXS_INLINE_P4_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[3]},
    {MMI_EM_PXS_INLINE_P5_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[4]},
    {MMI_EM_PXS_INLINE_P5_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[4]},
    {MMI_EM_PXS_INLINE_P6_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[5]},
    {MMI_EM_PXS_INLINE_P6_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[5]},
    {MMI_EM_PXS_INLINE_P7_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[6]},
    {MMI_EM_PXS_INLINE_P7_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[6]},
    {MMI_EM_PXS_INLINE_P8_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&inline_init_str[7]},
    {MMI_EM_PXS_INLINE_P8_EDITOR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&inline_editor_buff[7]}
};

static const cui_inline_struct inline_test = 
{
        16,   /* item count */
        STR_ID_EM_DEV_PXS,  /* screen title string id */
        0, /* screen title icon id */
        CUI_INLINE_SCREEN_DISABLE_DONE,  
        NULL,
        //(cui_inline_set_item_struct*)inline_item
        inline_item
};


/*****************************************************************************
 * FUNCTION
 *  mmi_em_pxs_sensor_read_param_val
 * DESCRIPTION
 *  This function is to read EM parameter
 * PARAMETERS
 *  em_param :  [OUT] EM PXS parameter. EM PXS param is U32 param[9]
 * RETURNS
 *  MMI_TRUE - read EM parameter successfully
 *  MMI_FALSE - read EM parameter fail
 *****************************************************************************/ 
MMI_BOOL mmi_em_pxs_sensor_read_param_val(void *em_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_STATUS pxs_status = STATUS_FAIL;
    PXS_CTRL_EM_PARAM_T param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pxs_handle > DCL_HANDLE_NONE)
    {
        pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_EM_READ, (DCL_CTRL_DATA_T  *) &param);
        memcpy(em_param, &param, sizeof(PXS_CTRL_EM_PARAM_T));
    }

/*
    MMI_PRINT(MOD_MMI_FW, TRACE_GROUP_3, "[SRV_SENSOR_PXS] DclPXS_Control- PXS_CMD_EM_READ, return: %d", pxs_status);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P1: %d",param.u4P1);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P2: %d",param.u4P2);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P3: %d",param.u4P3);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P4: %d",param.u4P4);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P5: %d",param.u4P5);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P6: %d",param.u4P6);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P7: %d",param.u4P7);
    kal_prompt_trace(MOD_MMI , "[SRV_SENSOR_PXS] P8: %d",param.u4P8);

  */
    
    return (pxs_status < 0)? MMI_FALSE : MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void get_raw_data()
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 raw_data;
    U8 temp_str[7] = {0};
    U8 view_str[14] = {0};
    S32 width = 0, height = 0;
    stFontAttribute     MMI_small_font = {   0,0,0,SMALL_FONT,0,1    };
    stFontAttribute debug_print_font = {0, 0, 0, DIALER_FONT, 0, 0};
    color c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    
    if (srv_sensor_pxs_get_raw_data(&raw_data))
    {
         /*update data on screen*/

         sprintf((char *)temp_str, "0x%x", raw_data);
         
         mmi_asc_n_to_ucs2((CHAR*)view_str , (CHAR*) temp_str, 6);

         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif

         /////////////////
         gui_lock_double_buffer();

        gdi_layer_push_clip();
        gdi_layer_reset_clip();

         c = gui_color(255, 255, 255);

         UI_fill_rectangle(
             0,
             40,
             MAIN_LCD_device_width-1,
             MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
             c);

         UI_set_font(&debug_print_font);
         c = gui_color(0, 0, 0);
         UI_set_text_color(c);
       
        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) view_str, &width, &height);
        gui_move_text_cursor(90, 50);
        gui_print_text((UI_string_type) view_str);


        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

        gdi_layer_pop_clip();

         /////////////////

//        kal_prompt_trace(MOD_MMI,"[SRV_SENSOR_PXS] raw data: %x",raw_data);

        

        
         
    }
	StartTimer(PXS_SENSOR_GET_RAW_DATA_TIMER, g_timer_delay, get_raw_data);
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_exit_get_raw_data_screen(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/     
         
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     StopTimer(PXS_SENSOR_GET_RAW_DATA_TIMER);
     srv_sensor_pxs_turn_off();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_get_raw_data()
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/     
     PXS_CTRL_EM_PARAM_T param = {0};
         
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     srv_sensor_pxs_turn_on();
      // mmi_frm_entry_new_screen(SCR_ID_EM_PXS_RAW_DATA, mmi_exit_get_raw_data_screen,NULL,NULL);

	if (!mmi_frm_scrn_enter(g_gourp_menu_id,
									 SCR_ID_EM_PXS_RAW_DATA, 
									 mmi_exit_get_raw_data_screen,
									 mmi_em_pxs_sensor_get_raw_data, 
									 MMI_FRM_FULL_SCRN))
	{
		return;
	}








      ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
      SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
      mmi_em_pxs_sensor_read_param_val(&param);

//      kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] PollingPeriod %d",param.u4PollingPeriod);

      g_timer_delay = param.u4PollingPeriod;
      
      StartTimer(PXS_SENSOR_GET_RAW_DATA_TIMER, g_timer_delay, get_raw_data);
//param.u4PollingPeriod
      
 }


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_obj_status_update_handle(U8 * str)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/   
    S32 width = 0, height = 0;
    stFontAttribute     MMI_small_font = {   0,0,0,DIALER_FONT,0,1    };
    stFontAttribute debug_print_font = {0, 0, 0, DIALER_FONT, 0, 0};
    
    color c;

    U8 view_str[14] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

     c = gui_color(255, 255, 255);

     UI_fill_rectangle(
         0,
         40,
         MAIN_LCD_device_width-1,
         MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
         c);

     UI_set_font(&debug_print_font);
     c = gui_color(0, 0, 0);
     UI_set_text_color(c);

    
    mmi_asc_n_to_ucs2((CHAR*)view_str , (CHAR*) str, 5);

    
    
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type) view_str, &width, &height);
    gui_move_text_cursor(90, 50);
    gui_print_text((UI_string_type) view_str);


    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_obj_close_handle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U8 temp_str[6] = {0};
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     sprintf((char *)temp_str, "CLOSE");
     
     mmi_em_pxs_sensor_obj_status_update_handle(temp_str);  

//     kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] Close EVT!");
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_obj_away_handle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U8 temp_str[6] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     sprintf((char *)temp_str, "AWAY");
     mmi_em_pxs_sensor_obj_status_update_handle(temp_str); 

//     kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] Away EVT!");
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_exit_get_obj_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE,mmi_em_pxs_sensor_obj_close_handle,NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY,mmi_em_pxs_sensor_obj_away_handle,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_get_obj_status()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // mmi_frm_entry_new_screen(SCR_ID_EM_PXS_RAW_DATA, mmi_exit_get_obj_status,NULL,NULL);



	if (!mmi_frm_scrn_enter(g_gourp_menu_id,
									 SCR_ID_EM_PXS_RAW_DATA, 
									 mmi_exit_get_obj_status,
									 mmi_em_pxs_sensor_get_obj_status, 
									 MMI_FRM_FULL_SCRN))
	{
		return;
	}

		
    ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    mmi_em_pxs_sensor_obj_away_handle();
        
   // SetProtocolEventHandler(mmi_em_pxs_sensor_obj_close_handle, EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE);
   // SetProtocolEventHandler(mmi_em_pxs_sensor_obj_away_handle, EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY);

    mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE,mmi_em_pxs_sensor_obj_close_handle,NULL);
    mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY,mmi_em_pxs_sensor_obj_away_handle,NULL);

   

}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_pxs_write_para_val
 * DESCRIPTION
 *  This function is to write EM parameter
 * PARAMETERS
 *  em_param :  [IN] EM PXS parameter. EM PXS param is U32 param[9]
 * RETURNS
 *  MMI_TRUE - write EM parameter successfully
 *  MMI_FALSE - write EM parameter fail
 *****************************************************************************/ 
MMI_BOOL mmi_em_pxs_write_para_val(void *em_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_STATUS pxs_status = STATUS_FAIL;
    PXS_CTRL_EM_PARAM_T param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pxs_handle > DCL_HANDLE_NONE)
    {
        memcpy(&param, em_param, sizeof(PXS_CTRL_EM_PARAM_T));
        pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_EM_WRITE, (DCL_CTRL_DATA_T  *) &param);
    }

//    MMI_PRINT(MOD_MMI_FW, TRACE_GROUP_3, "[SRV_SENSOR_PXS] DclPXS_Control- PXS_CMD_EM_WRITE, return: %d", pxs_status);
    return (pxs_status < 0)? MMI_FALSE : MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_em_hexstr_to_intnum(WCHAR * str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len;
    S32 i;
    U32 res = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_wcslen(str);
    for (i = len - 1; i >= 0; i-- )
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            //number
            res = res + ( str[i] - '0' ) * pow(16,len-1-i); 
        }
        else if(str[i] >= 'a' && str[i] <= 'f')
        {
            //char
            res = res + ( str[i] - 'a' + 10) * pow(16,len-1-i); 
        }
        else
        {
            res = 0;
            break;
        }
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_write_para()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 inline_buffer[MAX_PXS_SENSOR_PARA_NUM][20] = {0};
    U8 i = 0;
    U8 j = 0;
    U32 pxs_sensor_para_tmp_buff[MAX_PXS_SENSOR_PARA_NUM] = {0};
    PXS_CTRL_EM_PARAM_T pxs_sensor_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0,j=1; i<MAX_PXS_SENSOR_PARA_NUM; i++,j=j+2)
    {
        cui_inline_get_value(g_cui_inline_id, inline_item[j].item_id, inline_buffer[i]);
        pxs_sensor_para_tmp_buff[i] = mmi_em_hexstr_to_intnum((WCHAR *)inline_buffer[i]);
    }

    pxs_sensor_para.u4P1 = pxs_sensor_para_tmp_buff[0];
    pxs_sensor_para.u4P2 = pxs_sensor_para_tmp_buff[1];
    pxs_sensor_para.u4P3 = pxs_sensor_para_tmp_buff[2];
    pxs_sensor_para.u4P4 = pxs_sensor_para_tmp_buff[3];
    pxs_sensor_para.u4P5 = pxs_sensor_para_tmp_buff[4];
    pxs_sensor_para.u4P6 = pxs_sensor_para_tmp_buff[5];
    pxs_sensor_para.u4P7 = pxs_sensor_para_tmp_buff[6];
    pxs_sensor_para.u4P8 = pxs_sensor_para_tmp_buff[7];

    mmi_em_pxs_write_para_val(&pxs_sensor_para);

    
    mmi_frm_scrn_close_active_id();

     cui_inline_close(g_cui_inline_id);
    
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_em_pxs_inline_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *evt_abort = (cui_event_inline_abort_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:  
        mmi_display_popup_confirm((UI_string_type)GetString(STR_GLOBAL_YES),
        	    (PU8)GetImage(IMG_GLOBAL_YES),
        	    (UI_string_type)GetString(STR_GLOBAL_NO),
        	    (PU8)GetImage(IMG_GLOBAL_NO),
        	    (UI_string_type)GetString(IMG_GLOBAL_SAVE),
        	    MMI_EVENT_QUERY);
    	SetLeftSoftkeyFunction(mmi_em_pxs_write_para, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
     
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        
        cui_inline_close(evt_abort->sender_id);
       
        break;

    case EVT_ID_GROUP_DEINIT:
        mmi_frm_group_close(g_gourp_inline_id);
        break;

    default:
        break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_read_para(U16 str[][20])
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/     
     U8 tmp_str[MAX_PXS_SENSOR_PARA_NUM][10] = {0};
     PXS_CTRL_EM_PARAM_T em_param = {0};
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     mmi_em_pxs_sensor_read_param_val(&em_param);

     sprintf((char *)tmp_str[0], "%x" ,em_param.u4P1);
     sprintf((char *)tmp_str[1], "%x" ,em_param.u4P2);
     sprintf((char *)tmp_str[2], "%x" ,em_param.u4P3);
     sprintf((char *)tmp_str[3], "%x" ,em_param.u4P4);
     sprintf((char *)tmp_str[4], "%x" ,em_param.u4P5);
     sprintf((char *)tmp_str[5], "%x" ,em_param.u4P6);
     sprintf((char *)tmp_str[6], "%x" ,em_param.u4P7);
     sprintf((char *)tmp_str[7], "%x" ,em_param.u4P8);
     

     mmi_asc_n_to_ucs2((CHAR*)str[0] , (CHAR*) tmp_str[0], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[1] , (CHAR*) tmp_str[1], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[2] , (CHAR*) tmp_str[2], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[3] , (CHAR*) tmp_str[3], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[4] , (CHAR*) tmp_str[4], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[5] , (CHAR*) tmp_str[5], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[6] , (CHAR*) tmp_str[6], 8);
     mmi_asc_n_to_ucs2((CHAR*)str[7] , (CHAR*) tmp_str[7], 8);
     
    
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_em_pxs_sensor_enter_read_write()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/     
    U16 cui_inline_id;
    U16 pxs_sensor_read_para[8][20] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gourp_inline_id = mmi_frm_group_create(GRP_ID_ROOT,
                   GRP_ID_AUTO_GEN, mmi_em_pxs_inline_proc, NULL);

    mmi_frm_group_enter(g_gourp_inline_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);

    g_cui_inline_id = cui_inline_id = cui_inline_create(g_gourp_inline_id, &inline_test);
   
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P1_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P2_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P3_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P4_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P5_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P6_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P7_EDITOR,9);
    cui_inline_set_text_len(cui_inline_id,MMI_EM_PXS_INLINE_P8_EDITOR,9);

    mmi_em_pxs_sensor_read_para(pxs_sensor_read_para);
    
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P1_EDITOR, pxs_sensor_read_para[0]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P2_EDITOR, pxs_sensor_read_para[1]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P3_EDITOR, pxs_sensor_read_para[2]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P4_EDITOR, pxs_sensor_read_para[3]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P5_EDITOR, pxs_sensor_read_para[4]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P6_EDITOR, pxs_sensor_read_para[5]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P7_EDITOR, pxs_sensor_read_para[6]);
    cui_inline_set_value(cui_inline_id,MMI_EM_PXS_INLINE_P8_EDITOR, pxs_sensor_read_para[7]);

    

    cui_inline_run(cui_inline_id);



    
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_em_pxs_sensor_main_proc(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
	    case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
			break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            
            break;
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_EM_DEV_PXS_RAW_DATA:
                    mmi_em_pxs_sensor_get_raw_data();
                    break;
                case MENU_ID_EM_DEV_PXS_OBJ_STATUS:
                    mmi_em_pxs_sensor_get_obj_status();
                    break;
                case MENU_ID_EM_DEV_PXS_READ_WRITE_PARA:
                    mmi_em_pxs_sensor_enter_read_write();
                    break;
                default:
                    break;
            }

			break;
        case EVT_ID_GROUP_DEINIT:
            mmi_frm_group_close(g_gourp_menu_id);
            srv_sensor_pxs_turn_off();  
            break;
        default:
            break;	
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_em_enter_pxs_sensor_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_em_enter_pxs_sensor_hdlr()
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sensor_pxs_turn_on();      /*turn on the pxs sensor*/
    
    g_gourp_menu_id = mmi_frm_group_create(GRP_ID_ROOT,
		                   GRP_ID_AUTO_GEN, mmi_em_pxs_sensor_main_proc, NULL);
	mmi_frm_group_enter(g_gourp_menu_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
	g_cui_menu_id = menu_id = cui_menu_create(g_gourp_menu_id, CUI_MENU_SRC_TYPE_RESOURCE, CUI_MENU_TYPE_APPSUB,
		                    MENU_ID_EM_DEV_PXS_MAIN,
		                    MMI_TRUE, NULL);
	cui_menu_run(menu_id);
    
}


#endif /*__MMI_EM_DEV_PXS_SENSOR__*/



 

