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
 * FactoryModeKeypad.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode keypad.
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
 ********************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_FACTORY_MODE__

/*------------------- Header Files ---------------------------*/
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
     
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */ 


#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "ps_public_struct.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "nvram_defs.h"
#include "gui.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_msg_struct.h"
#include "AlarmFrameworkProt.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "SensorSrvGport.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PixcomFontEngine.h"
#include "resource_audio.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"
#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "fmt_struct.h"
#include "mmi_rp_srv_gpio_def.h"
#include "wgui_categories.h"
#include "dcl.h"
#include "init.h"
#include "device.h"
#include "custom_em.h"
#ifdef __MMI_FM_KEYPAD_TEST__
#include "custom_fm.h"
#endif
#include "custom_equipment.h"
//#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "lcd_sw_inc.h"
#include "resource_verno.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"


#include "adc_channel.h"
#include "ShutdownSrvGprot.h"

#include "mmi_rp_app_factorymode_def.h"
#include "MenuCuiGprot.h"
#include "FactoryModeGProt.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"

#ifdef __MMI_CLIPBOARD__
#include "ImeGprot.h"
#endif /* __MMI_CLIPBOARD__ */



/*--------------------- Define ---------------------*/

/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/

/***************************************************************************** 
* global val / function
*****************************************************************************/
/* common */
extern MMI_ID g_fm_gourp_id ;
extern mmi_fm_item_cntxt_struct *g_fm_contxt;

extern testlet Tests[MAX_AUTO_TEST_ITEMS];



/*------------------------- static function ------------------------------*/
/*---------- KeyPad -------------*/
#ifdef __MMI_FM_KEYPAD_TEST__
static mmi_fm_keypad_test_context_struct *g_fm_keypad_context = NULL;
static void     mmi_fm_keypad_entry_test_screen(void);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static mmi_ret mmi_fm_keypad_test_key_proc(mmi_event_struct *evt);
static MMI_BOOL mmi_fm_keypad_is_key_pressed(U16 key_code);
#endif
static void     mmi_fm_keypad_init_keymap_data(void);
static MMI_BOOL mmi_fm_keypad_update_keymap_data(U16 key_code);
static void     mmi_fm_keypad_remove_key_text(U16 *str, U16 *key_str, U16 key_code);
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
static void     mmi_fm_keypad_get_key_group(U16 *keys, U16 *num);
static void     mmi_fm_keypad_all_key_down_handler(void);
static void     mmi_fm_keypad_all_key_up_handler(void);
#endif
static MMI_BOOL mmi_fm_keypad_test_pass(void);
static void     mmi_fm_keypad_init_key_pressed_flag(void);
static MMI_BOOL mmi_fm_keypad_is_all_key_pressed(void);
static void     mmi_fm_keypad_endkey_longpress_handler(void);

static void     mmi_fm_keypad_handle_test_pass(void);
#endif /* __MMI_FM_KEYPAD_TEST__ */

#ifdef __MMI_FM_KEYPAD_TEST__
static void FM_SendKeyEventReq(U8 status, U8 code);
#endif

/*----------------------------- code body -------------------------------*/
/* new */
#ifdef __MMI_FM_KEYPAD_TEST__

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_keypad_test
 * DESCRIPTION
 *  Entry of keypad test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_keypad_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear possible key events from last screen*/
    ClearKeyEvents();
    mmi_fm_keypad_init_keymap_data();
    mmi_fm_keypad_entry_test_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_entry_test_screen
 * DESCRIPTION
 *  Entry function of keypad test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_entry_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    U16 key_group[MAX_KEYS];
    U16 key_num = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_AUTO_TEST_START);
    mmi_frm_scrn_enter
       (g_fm_gourp_id, 
        SCR_ID_FM_KEYPAD_TEST, 
        NULL, 
        mmi_fm_keypad_entry_test_screen, 
        MMI_FRM_FULL_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory78Screen(STR_ID_FM_KEYPAD, 0, 0, 0, 0, 0, NULL, 
        (U8*)FM_KEYPAD_TEST_STRING, 
        (S32)((mmi_ucs2strlen((CHAR*)FM_KEYPAD_TEST_STRING) + 1) * ENCODING_LENGTH), 
        guiBuffer);

#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_disconnect();
#endif /* __MMI_CLIPBOARD__ */

    /* Set key handlers*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
    /* Do not let FRM change KEY_ENTER to KEY_LSK */
    SetKeyDownHandler(MMI_dummy_function, KEY_ENTER);
    /* All keys are handled*/
    mmi_frm_scrn_set_key_proc(GRP_ID_ROOT, SCR_ID_FM_KEYPAD_TEST, mmi_fm_keypad_test_key_proc);
#else
    /* Get keys are filled in table*/
    mmi_fm_keypad_get_key_group(key_group, &key_num);
    /* Only handle fileed keys*/
    SetGroupKeyHandler(mmi_fm_keypad_all_key_down_handler, (PU16)key_group, (U8)key_num, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_fm_keypad_all_key_up_handler, (PU16)key_group, (U8)key_num, KEY_EVENT_UP);
#endif

    /* Invalidate END key*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
#endif

    /* Long press END key to exit*/
    SetKeyLongpressHandler(mmi_fm_keypad_endkey_longpress_handler, KEY_END);
    g_fm_contxt->keypad_contxt.InkeyTestingScreen = 1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_endkey_longpress_handler
 * DESCRIPTION
 *  END key long press handler, go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_endkey_longpress_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_scrn_close_active_id();
    mmi_fm_keypad_handle_test_pass();
}
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
/*****************************************************************************
 * FUNCTION
 *  FM_SendKeyEventReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void FM_SendKeyEventReq(U8 status, U8 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_keypad_event_output_req_struct *msg_p;
    S16 drv_keycode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_keycode = mmi_kbd_reverse_code((S16) code);

    msg_p = OslConstructDataPtr(sizeof(mmi_em_keypad_event_output_req_struct));
    msg_p->keypad_status = status;
    msg_p->keypad_code = (U8) drv_keycode;

    //FM_SendMsg(MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ, msg_p, NULL);
	
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, (oslMsgType)MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ, 
                        (oslParaType*)msg_p, NULL);
}


#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__



/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_test_key_proc
 * DESCRIPTION
 *  Key handler for Qwerty keypad
 * PARAMETERS
 *  S16 key_code
 *  S16 key_type
 *  U16 ucs2_value
 *  U32 special_key_flag
 * RETURNS
 *  MMI_BOOL    MMI_TRUE if the key is handled, otherwise return MMI_FALSE
 *****************************************************************************/
static mmi_ret mmi_fm_keypad_test_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    mmi_ret ret;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
    {
        /* L4C handles this message to send a corresponding key doce to PC via UART. It is used
           to do similar key test via PC tool instead of operators in factory. */
        FM_SendKeyEventReq((U8) key_type, (U8) key_code);

		if (key_type == KEY_EVENT_DOWN &&
			key_code == KEY_END)
		{
			return MMI_RET_KEY_HANDLED;
		}

        /* Only handle KEY_EVENT_UP*/
        if (key_type != KEY_EVENT_UP && key_code != KEY_HOME )
        {
            return MMI_RET_OK;
        }

        /* KEY_RSK and KEY_END need handled by screen*/
        if (key_code == KEY_RSK ||
            (key_code == KEY_END && mmi_fm_keypad_is_key_pressed(KEY_END)))
        {
            ret = MMI_RET_OK;
        }
        else
        {
            ret = MMI_RET_KEY_HANDLED;
        }

        /* Update keypad string*/
        if (!mmi_fm_keypad_update_keymap_data((U16)key_code))
        {
            return ret;
        }

        /* Update screen*/

        mmi_frm_scrn_enter
          (g_fm_gourp_id, 
          GLOBAL_SCR_DUMMY, 
          NULL,
          NULL, 
          MMI_FRM_FULL_SCRN);

        mmi_frm_scrn_close_active_id();

        /* Exit if test pass*/
        if (mmi_fm_keypad_test_pass() == TRUE)
        {
            mmi_fm_keypad_handle_test_pass();
        }

        return ret;
    }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_init_keymap_data
 * DESCRIPTION
 *  Init test keypad string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_init_keymap_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  order_table_idx;
    U32  order_table_size;
    U32  key_table_idx;
    U32  key_table_size;
    U16  *cur_set_pos = NULL;
    U16  cur_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* alloc control buffer*/
    g_fm_keypad_context = get_ctrl_buffer(FM_KEYPAD_CONTEXT_SIZE);
    
    /* Empty string*/
    FM_KEYPAD_TEST_STRING[0] = 0;
    /* Init key pressed flags*/
    mmi_fm_keypad_init_key_pressed_flag();

    order_table_size = FM_KEYPAD_ORDER_TABLE_SIZE;
    key_table_size = FM_KEYPAD_TALBLE_SIZE;
    cur_set_pos = FM_KEYPAD_TEST_STRING;
    
    for (order_table_idx = 0; order_table_idx < order_table_size; order_table_idx++)
    {
        /* It is a key*/
        if (g_fm_keypad_order_table[order_table_idx] != KEY_INVALID)
        {
            for(key_table_idx = 0; key_table_idx < key_table_size; key_table_idx++)
            {
                if (g_fm_keypad_table[key_table_idx].key_code == g_fm_keypad_order_table[order_table_idx])
                {
                    if (mmi_frm_kbd_is_key_supported(g_fm_keypad_table[key_table_idx].key_code))
                    {
                        /* Copy his text into buffer*/
                        cur_str_len = mmi_ucs2strlen((CHAR*)g_fm_keypad_table[key_table_idx].key_show_text);
                        mmi_ucs2cpy((CHAR*) cur_set_pos, (CHAR*) g_fm_keypad_table[key_table_idx].key_show_text);
                        cur_set_pos += cur_str_len;
                        /* Add space*/
                        cur_str_len = mmi_ucs2strlen((CHAR *)FM_KEYPAD_SPACE_STR);
                        mmi_ucs2cpy((CHAR *) cur_set_pos, (CHAR *) FM_KEYPAD_SPACE_STR);
                        cur_set_pos += cur_str_len;
                    }
                    else
                    {
                        FM_KEYPAD_CLEAR_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, order_table_idx);
                    }

                    break;
                }
            }
        }
        else /* Line ends*/
        {
            if ((cur_set_pos - FM_KEYPAD_TEST_STRING) >= 1)
            {
                cur_set_pos--;
            }
            /* Copy his text into buffer*/
            cur_str_len = mmi_ucs2strlen((CHAR *)FM_KEYPAD_NEW_LINE_STR);
            mmi_ucs2cpy((CHAR*) cur_set_pos, (CHAR *) FM_KEYPAD_NEW_LINE_STR);
            cur_set_pos += cur_str_len;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_update_keymap_data
 * DESCRIPTION
 *  Update keypad string to remove pressed key
 * PARAMETERS
 *  U16 key_code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_fm_keypad_update_keymap_data(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32  order_table_idx;
    U32  order_table_size;
    U32  key_table_idx;
    U32  key_table_size;
    MMI_BOOL process = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    order_table_size = FM_KEYPAD_ORDER_TABLE_SIZE;
    key_table_size = FM_KEYPAD_TALBLE_SIZE;

    /* Loop for each key in g_fm_keypad_order_table*/
    for (order_table_idx = 0; order_table_idx < order_table_size; order_table_idx++)
    {
        if (g_fm_keypad_order_table[order_table_idx] == key_code)
        {
            /* It is pressed*/
            if (FM_KEYPAD_TEST_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, order_table_idx) == 0)
            {
                return process;
            }

            /* Not pressed, find key text in g_fm_keypad_table and remove it from total key string*/
            for(key_table_idx = 0; key_table_idx < key_table_size; key_table_idx++)
            {
                if (g_fm_keypad_table[key_table_idx].key_code == g_fm_keypad_order_table[order_table_idx])
                {
                    mmi_fm_keypad_remove_key_text(FM_KEYPAD_TEST_STRING, g_fm_keypad_table[key_table_idx].key_show_text, key_code);
                    break;
                }
            }
            /* Set its bit*/
            FM_KEYPAD_CLEAR_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, order_table_idx);
            process = MMI_TRUE;
            break;
        }
    }
    return process;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_remove_key_text
 * DESCRIPTION
 *  Remove specified key string from total keypad string
 * PARAMETERS
 *  U16 *str
 *  U16 *key_str
 *  U16 key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_remove_key_text(U16 *str, U16 *key_str, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 key_text_len;
    U16 *cur_str = NULL;
    U16 *cpy_pos = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!str || !key_str)
    {
        return;
    }

    cur_str = str;
    key_text_len = mmi_ucs2strlen((CHAR*)key_str);

    while(*cur_str != 0x0000)
    {
        /* Key text has been found, just copy char to the end of string*/
        if (cpy_pos)
        {
            *cpy_pos = *cur_str;
            cpy_pos++;
            cur_str++;
        }
        else /* To find key text*/
        {
            /* Do strcmp if the first char matches*/
            if (*cur_str == *key_str &&
                (cur_str == str || *(cur_str - 1) == FM_KEYPAD_SPACE_STR[0] || *(cur_str - 1) == FM_KEYPAD_NEW_LINE_STR[0]) &&
                mmi_ucs2ncmp((CHAR*) cur_str, (CHAR*) key_str, key_text_len) == 0)
            {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                /* If a latter key is pressed, make sure current find the letter string 
                   but not a word starts by this letter*/
                if (key_code >= KEY_A && key_code <= KEY_Z &&
                    (*(cur_str+1) != FM_KEYPAD_SPACE_STR[0] &&
                     *(cur_str+1) != FM_KEYPAD_NEW_LINE_STR[0]))
                {
                    cur_str++;
                }
                else
#endif /*__MMI_QWERTY_KEYPAD_SUPPORT__*/
                {
                    /* Save the position of found string to cover it, 
                       and the position following this word*/
                    cpy_pos = cur_str;
                    cur_str += key_text_len;
                    /* If a space char after the word, jump over it*/
                    if (*cur_str == FM_KEYPAD_SPACE_STR[0])
                    {
                        cur_str++;
                    }
                    /* If a '\n' after the word*/
                    if (*cur_str == FM_KEYPAD_NEW_LINE_STR[0])
                    {
                        /* Remove the space char before this '\n'*/
                        if (cpy_pos != str &&
                            *(cpy_pos-1) == FM_KEYPAD_SPACE_STR[0])
                        {
                            cpy_pos--;
                        }
                        /* Remove empty line*/
                        if (cpy_pos == str)
                        {
                            cur_str++;
                        }
                        else if (*(cpy_pos-1) == FM_KEYPAD_NEW_LINE_STR[0])
                        {
                            cur_str++;
                        }
                    }
                }
            }
            else
            {
                cur_str++;    
            }
        }
    }

    /* The ending '\0'*/
    if (cpy_pos)
    {
        *cpy_pos = 0x0000;
    }
}

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_get_key_group
 * DESCRIPTION
 *  Get key codes that filled in g_fm_keypad_order_table
 * PARAMETERS
 *  U16 *keys
 *  U16 *num
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_get_key_group(U16 *keys, U16 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 i;
    U16 key_num = 0;
    U16 table_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    table_size = FM_KEYPAD_ORDER_TABLE_SIZE;
    
    for (i = 0; i < table_size; i++)
    {
        /* Only valid key code are filled*/
        if (g_fm_keypad_order_table[i] != KEY_INVALID)
        {
            /* If up or down arrow is pressed, don't fill it to let category handle it*/
            if ((g_fm_keypad_order_table[i] == KEY_UP_ARROW && 
                 (FM_KEYPAD_TEST_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, i) == 0)) ||
                 (g_fm_keypad_order_table[i] == KEY_DOWN_ARROW && 
                 (FM_KEYPAD_TEST_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, i) == 0)))
            {
                continue;
            }
            keys[key_num] = g_fm_keypad_order_table[i];
            key_num++;
        }
    }

    *num = key_num;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_all_key_down_handler
 * DESCRIPTION
 *  Key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_all_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    /* L4C handles this message to send a corresponding key doce to PC via UART. It is used
       to do similar key test via PC tool instead of operators in factory. */
    FM_SendKeyEventReq((U8) Keytype, (U8) Keycode);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_all_key_up_handler
 * DESCRIPTION
 *  Key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_all_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    /* L4C handles this message to send a corresponding key doce to PC via UART. It is used
       to do similar key test via PC tool instead of operators in factory. */
    FM_SendKeyEventReq((U8) Keytype, (U8) Keycode);

    /* Update string*/
    if (!mmi_fm_keypad_update_keymap_data(Keycode))
    {
        return;
    }

    /* Update screen*/
    
    mmi_frm_scrn_enter
           (g_fm_gourp_id, 
            GLOBAL_SCR_DUMMY, 
            NULL, 
            NULL, 
            MMI_FRM_FULL_SCRN);
     mmi_frm_scrn_close_active_id();

    /* Exit if test pass*/
    if (mmi_fm_keypad_test_pass() == TRUE)
    {
        mmi_fm_keypad_handle_test_pass();
    }
}

#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_test_pass
 * DESCRIPTION
 *  Check if all key are pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_fm_keypad_test_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_fm_keypad_is_all_key_pressed();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_init_key_pressed_flag
 * DESCRIPTION
 *  Init key_pressed_flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_init_key_pressed_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 i;
    U32 key_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(FM_KEYPAD_KEY_PRESSED_FLAG, 0, sizeof(FM_KEYPAD_KEY_PRESSED_FLAG));
    
    /* Initial all bits are 1*/
    key_num = FM_KEYPAD_ORDER_TABLE_SIZE;
    for(i = 0; i < key_num; i++)
    {
        if (g_fm_keypad_order_table[i] == KEY_INVALID)
        {
            FM_KEYPAD_CLEAR_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, i);
        }
        else
        {
            FM_KEYPAD_SET_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, i);
        }
    }
}

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_is_key_pressed
 * DESCRIPTION
 *  Check if the key is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_fm_keypad_is_key_pressed(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    U32 i;
    U32 key_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_num = FM_KEYPAD_ORDER_TABLE_SIZE;
    for(i = 0; i < key_num; i++)
    {
        if (g_fm_keypad_order_table[i] == key_code)
        {
            return (MMI_BOOL)(FM_KEYPAD_TEST_BIT(FM_KEYPAD_KEY_PRESSED_FLAG, i) == 0);
        }
    }
    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_is_all_key_pressed
 * DESCRIPTION
 *  Check if all key is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_fm_keypad_is_all_key_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Test if all U32 value are 0*/
    for (i = 0; i < FM_KEYPAD_KEY_PRESSED_FLAG_LEN; i++)
    {
        if (FM_KEYPAD_KEY_PRESSED_FLAG[i] != 0)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_keypad_handle_test_pass
 * DESCRIPTION
 *  Go to next step after keypad test pass. If in auto test mode, show test 
 *  result and wait user confirm. If in factory test mode, show result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_keypad_handle_test_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For keypad test, exit test screen*/
    if (g_fm_contxt->common_contxt.autoTestMode == 0)
    {

		/* Pass */
		mmi_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_DONE), 
            MMI_EVENT_SUCCESS);

		mmi_frm_scrn_close(g_fm_gourp_id,SCR_ID_FM_KEYPAD_TEST);
    }
    else /* Show test result for auto test*/
    {
        
        mmi_frm_scrn_close(g_fm_gourp_id, SCR_ID_FM_KEYPAD_TEST);        
        mmi_frm_scrn_enter
           (g_fm_gourp_id, 
            SCR_ID_FM_AUTO_TEST_START,//SCR_ID_FM_KEYPAD_TEST_RESULT, 
            NULL, 
            mmi_fm_keypad_handle_test_pass, 
            MMI_FRM_FULL_SCRN);
        FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_KEYPAD].name);
        ShowCategory7Screen(
            STR_ID_FM_AUTO_TEST_ROOT,
            NULL,//IMG_ID_FM_AUTO_TEST_ROOT,
            STR_ID_FM_AUTO_TEST_PASS,
            IMG_GLOBAL_OK,
            STR_ID_FM_AUTO_TEST_FAIL,
            IMG_GLOBAL_BACK,
            (PU8) g_fm_contxt->common_contxt.EMFMUnicodeDisplayBuf,
            NULL);

        FM_Autotest_set_key_handlers(1);
       // DeleteScreenIfPresent(SCR_ID_FM_KEYPAD_TEST);
    }
}

#endif /* __MMI_FM_KEYPAD_TEST__ */



#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */

#endif /* __MMI_FACTORY_MODE__ */

 

