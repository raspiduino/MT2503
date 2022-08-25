/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * EngineerModeBacklight.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode backlight part for MT6260.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
	 
#include "mmi_features.h"
	 
#ifdef __MMI_EM_60BACKLIGHT__    /* MTK Add Robin 1001 for saperate MMI feature by project */
	 
	 /***************************************************************************** 
	  * Include 
	  *****************************************************************************/

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "uart_sw.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "wgui_inline_edit.h"
#include "l4c_common_enum.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "CustDataRes.h"
#include "wgui_categories_text_viewer.h"
#include "GpioSrvGprot.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "gui.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#ifdef __MMI_EM_DEV_USB_TETHERING__
#include "AlertScreen.h"
#include "usbacm_adap.h"
#include "shutdownSrvGprot.h"
#endif /* __MMI_EM_DEV_USB_TETHERING__ */
	 
#ifdef __MMI_EM_DEV_WLAN_EAP_MODE__
#include "EngineerModeWLAN.h"
#endif
	 
#ifdef __MMI_FILE_MANAGER__
    #include "FileMgrGProt.h"
#endif
#include "mmi_res_range_def.h"
#include "stdio.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "wgui_categories.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "ps_public_struct.h"
#ifdef __MMI_EM_DEV_MEMORY_TEST__
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#endif
#include "mmi_frm_nvram_gprot.h"
#include "nvram_data_items.h"
#include "EngineerModeAppResDef.h"
#include "stack_config.h"
#include "drv_features.h"
#include "lcd_if.h"
	 
#include "dcl.h"
#include "CharBatSrvGprot.h"
	 
#include "ProtocolEvents.h"
	 
#include "CommonScreens.h"
	 
#include "Nvram_interface.h"
#include "Custom_equipment.h"
#include "gpio_measure.h"
#include "eint_measure.h"
#include "pwm_measure.h"
#include "battery_measure.h"
#include "lcd_measure.h"
#include "device.h"
#include "custom_em.h"
#include "custom_uem.h"
#include "custom_hw_default.h"
#include "PowerOnChargerProt.h"
	 
#if defined(__MMI_EM_MISC_SOFTWARE_TRACER__)
/* under construction !*/
#endif
	 
#if defined(NAND_SUPPORT)       /* && defined(MMI_ON_HARDWARE_P) */
#include "ProfilesSrvGProt.h"
#endif 
	 
#ifdef __MTK_TARGET__
#ifdef __OTG_ENABLE__
#include "otg_if.h"
#endif 
#endif
	 
#include "FileMgrSrvGProt.h"
#include "fmt_def.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "GpioSrvGprot.h"
	 
#include "adc_channel.h"
	 
#ifdef __USB_TETHERING__
#include "usbacm_adap.h"
#endif
#include "timerevents.h"
	 
	 /* For 10A*/
#include "fseditorcuigprot.h"
#include "FileMgrCUIGProt.h"
#include "inlinecuigprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeMultimedia.h"
#include "EngineerModePMIC.h"
#include "EngineerModeDevice.h"
#include "EngineerModeGPS.h"
#include "mmi_rp_app_engineermode1_def.h" 
       
#if defined(DRV_PWM_DRV_TOOL_SUPPORT)
#include "pwm_drv.h"
#endif
#define MMI_EM_DEV_BACKLIGHT_ITEM_COUNT   4
#define MMI_EM_DEV_BACKLIGHT_BUF_LEN    3 
#define MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM  100 
#define MMI_EM_DEV_BACKLIGHT_INVALID_POPUP_TEXT_LEN 40
#define MMI_EM_DEV_BACKLIGHT_MAX_DUTY   PWM_MAX_DUTY
#define MMI_EM_DEV_BACKLIGHT_MIN_DUTY   PWM_MIN_DUTY

#define MMI_EM_CAPTION_1     CUI_INLINE_ITEM_ID_BASE+0 
#define MMI_EM_CAPTION_3     CUI_INLINE_ITEM_ID_BASE+2 
#define MMI_EM_TEXT_EDIT_2   CUI_INLINE_ITEM_ID_BASE+4 
#define MMI_EM_STR_SELECT_1  CUI_INLINE_ITEM_ID_BASE+6

typedef struct
{
    U32 pwm;
    U32 max_level;
    U32 level; 
    U32 duty;
    mmi_id inline_id;
    WCHAR duty_buf[MMI_EM_DEV_BACKLIGHT_BUF_LEN + 1];
    WCHAR level_str[MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM][MMI_EM_DEV_BACKLIGHT_BUF_LEN];
    WCHAR *level_str_list[MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM];
    U32 pwm_new[20][2];
} mmi_em_dev_backlight_cntx_struct;

mmi_em_dev_backlight_cntx_struct *mmi_em_dev_backlight_cntx_p;

MMI_EM_INIT_ASM(dev_backlight, mmi_em_dev_backlight_cntx_p, 
    sizeof(mmi_em_dev_backlight_cntx_struct))

static const cui_inline_item_caption_struct g_mmi_em_backlight_level_cap = 
{
    STR_ID_EM_DEV_BACKLIGHT_LEVEL
};


static const cui_inline_item_caption_struct g_mmi_em_backlight_duty_cap = 
{
    STR_ID_EM_DEV_BACKLIGHT_DUTY,
};

static const cui_inline_item_text_edit_struct g_mmi_em_backlight_duty_edit =
{
    0, 0, MMI_EM_DEV_BACKLIGHT_BUF_LEN+1, IMM_INPUT_TYPE_NUMERIC, 0, NULL,
};

static const cui_inline_set_item_struct g_mmi_em_backlight_inline[] = 
{
    {MMI_EM_CAPTION_1,        CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_STATUS,  (void*)&g_mmi_em_backlight_level_cap},
    {MMI_EM_STR_SELECT_1,   CUI_INLINE_ITEM_TYPE_SELECT,      0,                   (void*)NULL}, //&g_mmi_em_backlight_level_select},
    {MMI_EM_CAPTION_3,        CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_STATUS,   (void*)&g_mmi_em_backlight_duty_cap},
    {MMI_EM_TEXT_EDIT_2,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,                    (void*)&g_mmi_em_backlight_duty_edit},
};

static const cui_inline_struct g_mmi_em_backlight_inline_scrn = 
{
    MMI_EM_DEV_BACKLIGHT_ITEM_COUNT,
    STR_ID_EM_DEV_BACKLIGHT,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_backlight_inline,
};

static void mmi_em_dev_enter_backlight(void);
static MMI_RET mmi_em_device_backlightl_proc(mmi_event_struct* evt);
static MMI_BOOL mmi_em_device_backlight_set_hdlr(MMI_ID parent_id);
static MMI_BOOL mmi_em_device_backlight_all_level_valid(U32 *level);
static void mmi_em_device_backlight_invalid_popup(U32 level);
static void mmi_em_device_backlight_select_notify(MMI_ID parent_id);
static void mmi_em_device_backlight_send_set_hw_level_req(void);
static void mmi_em_device_backlight_update_bl(MMI_ID parent_id);
static void mmi_em_device_backlight_abort(void);

extern void custom_pwm_configure(kal_uint8 gpio_dev_type, kal_uint32 level, kal_uint32 freq, kal_uint32 duty);

void mmi_em_dev_60backlight_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(dev_backlight);
    mmi_em_dev_enter_backlight();
}
//------------------------------------------------------------
#define emBlacklight  DCL_MAIN_LCD_BL


#ifndef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
static U32 mmi_em_dev_get_level_info(U32 pwmEnum, U32 type)
{
		U32 value;
			PWM_LEVEL_T data;
			DCL_HANDLE pwm_handle;
	pwm_handle = DclPWM_Open(pwmEnum, MOD_UEM);
	DclPWM_Control(pwm_handle, type,(DCL_CTRL_DATA_T*)&data);
	DclPWM_Close(pwm_handle);
	value = data.pwm_level;
	return value;
}

static void mmi_em_dev_get_level_data(U32 pwmEnum, U32 type, PWM_DATA_T* data)
{
		PWM_DATA_T tempData;
DCL_HANDLE pwm_handle;
DCL_UINT8  pwm_tmp_level;


pwm_tmp_level=(*data).pwm_level;   //old flow  has a bug 	   
tempData.pwm_level=pwm_tmp_level;  //added by zhanguo 

pwm_handle = DclPWM_Open(pwmEnum, MOD_UEM);
	DclPWM_Control(pwm_handle, type,(DCL_CTRL_DATA_T*)&tempData);
	DclPWM_Close(pwm_handle);
	data->pwm_duty = tempData.pwm_duty;
	data->pwm_freq = tempData.pwm_freq;
}

static U32 mmi_em_dev_get_pwm_for_bl()
{
	U32 pwm;
	PWM_CHANNEL_T data;
	DCL_HANDLE pwm_handle;
    pwm_handle = DclPWM_Open(DCL_MAIN_LCD_BL, MOD_UEM);
	DclPWM_Control(pwm_handle, PWM_CMD_GET_PWM_CHANNEL,(DCL_CTRL_DATA_T*)&data);
	DclPWM_Close(pwm_handle);
	pwm = data.pwm_channel;
 	return pwm;
}
#endif /*__MULTI_LEVEL_BACKLIGHT_SUPPORT__*/

static U32 mmi_em_dev_get_max_pwm_level(U32 pwmEnum)
{
	U32 max_level = 0;
	
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			max_level = mmi_em_dev_get_level_info(pwmEnum, PWM_CMD_GET_MAX_LEVEL);
			break;
		}
		default:
			break;
	}
	return max_level;
}

static void mmi_em_set_pwm_level(U32 pwmEnum, U32 level)
{
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			PWM_LEVEL_T tempLevel;
			DCL_HANDLE pwm_handle = DclPWM_Open(pwmEnum, MOD_UEM);
			tempLevel.pwm_level = level + 1;
			DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL,(DCL_CTRL_DATA_T*)&tempLevel);
			DclPWM_Close(pwm_handle);
			break;
		}
		default:
			break;
	}
}


static U32 mmi_em_dev_enum_to_pwm(U32 pwmEnum)
{
	U32 pwm = 0;
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			pwm = mmi_em_dev_get_pwm_for_bl() - 1;
			break;
		}
		default:
			break;
	}
	return pwm;
}

static U32 mmi_em_dev_get_current_pwm_level(U32 pwmEnum)
{
	U32 level = 0;
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			level = mmi_em_dev_get_level_info(pwmEnum, PWM_CMD_GET_CURRENT_LEVEL);
			break;
		}
		default:
			break;
	}
	return level;
}
static U32 mmi_em_dev_get_freq_by_level(U32 pwmEnum, U32 level)
{
	U32 value = 0;
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			PWM_DATA_T data;
			data.pwm_level = level;
			mmi_em_dev_get_level_data(pwmEnum, PWM_CMD_GET_FREQ_BY_LEVEL, &data);
			value = data.pwm_freq;
			break;
		}
		default:
			break;
	}
	return value;
}

static U32 mmi_em_dev_get_duty_by_level(U32 pwmEnum, U32 level)
{
	U32 value = 0;
	switch(pwmEnum)
	{
		case emBlacklight:
		{
			PWM_DATA_T data;
			data.pwm_level = level;
			mmi_em_dev_get_level_data(pwmEnum, PWM_CMD_GET_DUTY_BY_LEVEL, &data); //modify duty
			value = data.pwm_duty;
			break;
		}
		default:
			break;
	}
	return value;
}

//-------------------------------------------------------------

static void mmi_em_dev_enter_backlight(void)
{
    MMI_ID gid;
    MMI_ID inline_id;
    U32      i;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    U32 max_level;
    max_level = mmi_em_dev_get_max_pwm_level(emBlacklight);
    /* Get max levels*/
    cntx->max_level = max_level;
    /* Which PWM control backlight*/
    cntx->pwm = mmi_em_dev_enum_to_pwm(emBlacklight);

     
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                  GRP_ID_AUTO_GEN, 
                  mmi_em_device_backlightl_proc, NULL,
                  MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_backlight_inline_scrn);

    /* Get current level, from GPIO srv */
    cntx->level = mmi_em_dev_get_current_pwm_level(emBlacklight);
     
    if (cntx->level >= cntx->max_level)
    {
        cntx->level = cntx->max_level; /* modified by zhanguo */
    }
    cntx->level -=1; /* modified by zhanguo */

    /* Get current level's freq & duty, from drv*/
    for (i = 0; i < max_level; i++)
    {

        cntx->pwm_new[i][0] = mmi_em_dev_get_freq_by_level(emBlacklight, (i+1));
        cntx->pwm_new[i][1] = mmi_em_dev_get_duty_by_level(emBlacklight, (i+1));
        
        /* level text*/
        kal_wsprintf((WCHAR*)cntx->level_str[i], "%d", i+1);
        cntx->level_str_list[i] = (WCHAR*)cntx->level_str[i];
    }

    cntx->duty = cntx->pwm_new[cntx->level][1];
    
    cui_inline_set_item_select(inline_id, MMI_EM_STR_SELECT_1, cntx->max_level, (PU8*)cntx->level_str_list, cntx->level);
    kal_wsprintf((WCHAR*)cntx->duty_buf, "%d", cntx->duty);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_2, (void *) cntx->duty_buf);
    
    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_device_backlightl_proc(mmi_event_struct* evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
    cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;

    switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        if (mmi_em_device_backlight_set_hdlr(inline_evt->sender_id))
        {
            cui_inline_close(inline_evt->sender_id);
            MMI_EM_ASM_FREE_FUNC(dev_backlight);
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_em_device_backlight_abort();
        cui_inline_close(inline_evt->sender_id);
        MMI_EM_ASM_FREE_FUNC(dev_backlight);
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        switch (notify_evt->event_type)
        {
            case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:

                mmi_em_device_backlight_select_notify(inline_evt->sender_id);
                break;

            //case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
            case CUI_INLINE_NOTIFY_ITEM_CHANGED:
                mmi_em_device_backlight_update_bl(inline_evt->sender_id);
                break;
                
            default:
                break;
        }
        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        mmi_em_device_backlight_abort();
        break;
        
    default:
        break;
    }

    return MMI_RET_OK;
}


static MMI_BOOL mmi_em_device_backlight_set_hdlr(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    U32 invalid_level;

    DCL_HANDLE pwm_handle;
           U32 pwm_channel;
		   
   PWM_ARRAY_T pwm_info;

		   
	kal_uint32 (*p)[2]=cntx->pwm_new;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get input buffer*/
   // cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_1, (void *)cntx->freq_buf);
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

    if (!mmi_em_device_backlight_all_level_valid(&invalid_level))
    {
        mmi_em_device_backlight_invalid_popup(invalid_level);
        return MMI_FALSE;
    }

    /* Set PWM*/
     pwm_channel = mmi_em_dev_get_pwm_for_bl(); /*get pwm channel */
	 
     pwm_info.channel=pwm_channel;
     pwm_info.pwm_array=p;

     pwm_handle =DclPWM_Open(DCL_MAIN_LCD_BL, MOD_UEM);
	 DclPWM_Control(pwm_handle, PWM_CMD_SET_PWM_ARRAY,(DCL_CTRL_DATA_T*)&pwm_info);
	 DclPWM_Close(pwm_handle);
     mmi_em_device_backlight_send_set_hw_level_req();
    /* Set backlight level*/
     mmi_em_device_backlight_abort();

    return MMI_TRUE;
}

static MMI_BOOL mmi_em_device_backlight_all_level_valid(U32 *level)
{
    U32 i;
    U32 value;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

    for (i = 0; i < cntx->max_level; i++)
    {
        /* Check duty*/
        value = cntx->pwm_new[i][1];
        if (value < MMI_EM_DEV_BACKLIGHT_MIN_DUTY ||
            value > MMI_EM_DEV_BACKLIGHT_MAX_DUTY)
        {
            if (level)
                *level = i;
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

static void mmi_em_device_backlight_invalid_popup(U32 level)
{
    WCHAR string[MMI_EM_DEV_BACKLIGHT_INVALID_POPUP_TEXT_LEN];
    WCHAR *item_string;
    item_string = get_string(STR_ID_EM_DEV_BACKLIGHT_DUTY);
    kal_wsprintf(string, "%w %w %d %w", 
        item_string, 
        get_string(STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP1), 
        level + 1, 
        get_string(STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP2));

    mmi_popup_display(string, MMI_EVENT_WARNING, NULL);
}

static void mmi_em_device_backlight_select_notify(MMI_ID parent_id)
{
    U32 new_level = 0;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

    
    cui_inline_get_value(parent_id, MMI_EM_STR_SELECT_1, (void *)&new_level);
    
	if (new_level == cntx->level)
	{
            return;
	}
	cntx->level = new_level;
    
    /* get freq&duty*/
    cntx->duty = cntx->pwm_new[cntx->level][1]; //*(pwm_tbl + 2 * cntx->level + 1);

    /* Set buffer*/
    kal_wsprintf((WCHAR*)cntx->duty_buf, "%d", cntx->duty);
    cui_inline_set_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

	mmi_em_set_pwm_level(emBlacklight, cntx->level);
}

static void mmi_em_device_backlight_update_bl(MMI_ID parent_id)
{
    U32 duty;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

    
    cui_inline_get_value(parent_id, MMI_EM_STR_SELECT_1, (void *)&cntx->level);
    
    /* Get input buffer*/
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

    /* Convert to value*/
    duty = mmi_wcs_wtoi(cntx->duty_buf);
    

    cntx->duty = duty;
    
    /* Set PWM*/
    cntx->pwm_new[cntx->level ][1] = duty;
}

static void mmi_em_device_backlight_abort(void)
{
	mmi_em_set_pwm_level(emBlacklight, mmi_em_dev_backlight_cntx_p->level);
}

static void mmi_em_device_backlight_send_set_hw_level_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_eq_set_hw_level_req_struct *set_hw_struct;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    pwm_measure_level_info_struct pwm_info;
    Battery_measure_level_info_struct batt_info;
    U32 max_level;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_hw_struct = OslConstructDataPtr(sizeof(mmi_eq_set_hw_level_req_struct));

    for (i = 0; i < 5; i++)
    {
		if(cntx->pwm == PWM_MEASURE_TYPE_PWM1)
		{
			set_hw_struct->hw_profile.PWM1_freq_Level_Info[i] = cntx->pwm_new[i][0]; 
	        set_hw_struct->hw_profile.PWM1_duty_Level_Info[i] = cntx->pwm_new[i][1]; 
		}
		else
		{		
	        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM1, i, &pwm_info);
	        set_hw_struct->hw_profile.PWM1_freq_Level_Info[i] = pwm_info.freq; //PWM1_Level_Info[i][0];
	        set_hw_struct->hw_profile.PWM1_duty_Level_Info[i] = pwm_info.duty; //PWM1_Level_Info[i][1];
		}
		if(cntx->pwm == PWM_MEASURE_TYPE_PWM2)
		{
			set_hw_struct->hw_profile.PWM2_freq_Level_Info[i] = cntx->pwm_new[i][0]; 
	        set_hw_struct->hw_profile.PWM2_duty_Level_Info[i] = cntx->pwm_new[i][1]; 
		}
		else
		{	
	        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM2, i, &pwm_info);
	        set_hw_struct->hw_profile.PWM2_freq_Level_Info[i] = pwm_info.freq; //PWM2_Level_Info[i][0];
	        set_hw_struct->hw_profile.PWM2_duty_Level_Info[i] = pwm_info.duty; //PWM2_Level_Info[i][1];
		}
		if(cntx->pwm == PWM_MEASURE_TYPE_PWM3)
		{
			set_hw_struct->hw_profile.PWM3_freq_Level_Info[i] = cntx->pwm_new[i][0]; 
	        set_hw_struct->hw_profile.PWM3_duty_Level_Info[i] = cntx->pwm_new[i][1]; 
		}
		else
		{	
	        pwm_measure_get_level_info(PWM_MEASURE_TYPE_ALTER, i, &pwm_info);
	        set_hw_struct->hw_profile.PWM3_freq_Level_Info[i] = pwm_info.freq; //Alter_Level_Info[i][0];
	        set_hw_struct->hw_profile.PWM3_duty_Level_Info[i] = pwm_info.duty; //Alter_Level_Info[i][1];
		}
    }
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_CONTRAST),
        sizeof(set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Bias_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_BIAS),
        sizeof(set_hw_struct->hw_profile.MainLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_LINERATE),
        sizeof(set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Temp_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_TEMP),
        sizeof(set_hw_struct->hw_profile.MainLCD_Temp_Level_Info));

#ifdef __MMI_SUBLCD__
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_CONTRAST),
        sizeof(set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Bias_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_BIAS),
        sizeof(set_hw_struct->hw_profile.SubLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_LINERATE),
        sizeof(set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Temp_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_TEMP),
        sizeof(set_hw_struct->hw_profile.SubLCD_Temp_Level_Info));
#endif /* __MMI_SUBLCD__ */ 

    max_level = battery_measure_get_max_level();
    for (i = 0; i < max_level; i++)
    {
        battery_measure_get_level_info(i, &batt_info);
        set_hw_struct->hw_profile.Battery_Level_Info[i] = batt_info.value;
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ, set_hw_struct, NULL);
}

#endif /* __MMI_EM_60BACKLIGHT__*/
