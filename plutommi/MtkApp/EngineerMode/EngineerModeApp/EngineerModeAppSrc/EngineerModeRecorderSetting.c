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
 *  EngineerModeMultimedia.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode multimedia items. It includes:
 *      - Ext Camera
 *      - TVOUT
 *      - MTV setting
 *      - FM Radio
 *      - Camera AF Contshot
 *      - J2ME
 *      - Video High baudrate
 *      - Java Heap Size
 *      - Software Tracer
 *      - BCR
 *      - JUI Debug
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
* Include 
*****************************************************************************/
#if defined(__MMI_EM_MISC_RECORDER_PARAM_AJUST__)
#include "MMI_features.h"

#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */

#include "EngineerModeUtil.h"

#include "EngineerModeMultimedia.h"
#include "EngineerModeCommUI.h"
#include "med_api.h"
#include "EngineerModeCommMem.h"

#include "ProfilesSrvGprot.h"
#include "InlineCuiGprot.h"

#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "gdi_datatype.h"
#include "isp_if.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "wgui_include.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalMenuItems.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "CustMenuRes.h"
#include "kal_public_api.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "stdlib.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "device.h"
#include "ps_public_struct.h"
#include "stack_msgs.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stdio.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_file_type_def.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mmi_res_range_def.h"
#include "gdi_include.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "DebugInitDef_Int.h"
#include "gui_themes.h"
#include "ScreenRotationGprot.h"
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_features.h"
#include "GpioSrvGprot.h"

#include "PhoneSetup.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeRecorderSetting.h"

/*****************************************************************************
*	EM Recorder Setting added
*****************************************************************************/
/***************************************************************************** 
 * Define
 *****************************************************************************/


/*max input number length +1('\0') of every item*/
#define MMI_EM_RECORDER_BITRATE_MAXNUM          8
#define MMI_EM_RECORDER_MAX_INIT_QP_MAXNUM      3
#define MMI_EM_RECORDER_MAX_QP_MAXNUM           3
#define MMI_EM_RECORDER_MIN_QP_MAXNUM           3
#define MMI_EM_RECORDER_INTRA_VOP_RATE_MAXNUM   3
#define MMI_EM_RECORDER_ALGORITHM_MAXNUM        3
#define MMI_EM_RECORDER_RATE_HARD_LIMIT_MAXNUM  5
#define MMI_EM_RECORDER_RANGE_REDUCTION_MAXNUM  2

#define MMI_EM_RECORDER_SETTING_MAX_INPUT_NUM   8       /* max input number length of all items,max(MMI_EM_RECORDER_BITRATE_MAXNUM,
 
                                                       * MMI_EM_RECORDER_MAX_INIT_QP_MAXNUM,...............)*/
typedef enum
{
   MMI_EM_RECORDER_SETTING_INLINE_SELECTOR,
   MMI_EM_RECORDER_SETTING_INLINE_EDITOR, 
   
   MMI_EM_RECORDER_SETTING_INLINE_TYPE_COUNT
}MMI_EM_REC_INLINE_TYPE_ENUM;

typedef struct 
{
    MMI_EM_REC_INLINE_TYPE_ENUM type;
	const WCHAR *caption_str;
    U32         *val_addr;
    const U16   *selector;
    U32 edi_count_or_sel_count;
 
}mmi_em_recorder_setting_items_struct;

mmi_em_recorder_setting_struct g_mmi_em_recorder_setting = 
{
    MMI_EM_RECORDER_SETTING_APPLY_NO, //Apply em recorder setting 
    48000,                            //Bit_rate
    1,                                //Init_Qp
    1,                                //Max_QP
    1,                                //Min_QP
    1,                                //Intra_Vop_Rate
    3,                                //Algorithm
    128,                              //Rate_Hard_limit
    0                                 //Dynamic_Range_Reduction
};

static const U16 mmi_em_rec_apply_selector[MMI_EM_RECORDER_SETTING_APPLY_TYPE_COUNT] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};

const mmi_em_recorder_setting_items_struct mmi_em_rec_setting_items[]=
{
    //apply_em_setting
    {
        MMI_EM_RECORDER_SETTING_INLINE_SELECTOR,
        L"Apply em setting",
        (U32*)&(g_mmi_em_recorder_setting.apply_em_setting),
        mmi_em_rec_apply_selector,
        MMI_EM_RECORDER_SETTING_APPLY_TYPE_COUNT
    },
    //bit_rate
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Bit rate",
        &(g_mmi_em_recorder_setting.bit_rate),
        NULL,
        MMI_EM_RECORDER_BITRATE_MAXNUM
    },
    //init_qp
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Init qp",
        &(g_mmi_em_recorder_setting.init_qp),
        NULL,
        MMI_EM_RECORDER_MAX_INIT_QP_MAXNUM
    },
    //max_qp
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Max qp",
        &(g_mmi_em_recorder_setting.max_qp),
        NULL,
        MMI_EM_RECORDER_MAX_QP_MAXNUM
    },
    //min_qp
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Min qp",
        &(g_mmi_em_recorder_setting.min_qp),
        NULL,
        MMI_EM_RECORDER_MIN_QP_MAXNUM
    },
    //intra_vop_rate
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Intra vop rate",
        &(g_mmi_em_recorder_setting.intra_vop_rate),
        NULL,
        MMI_EM_RECORDER_INTRA_VOP_RATE_MAXNUM
    },
    //algorithm
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Algorithm",
        &(g_mmi_em_recorder_setting.algorithm),
        NULL,
        MMI_EM_RECORDER_ALGORITHM_MAXNUM
    },
    //rate_hard_limit
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Rate hard limit",
        &(g_mmi_em_recorder_setting.rate_hard_limit),
        NULL,
        MMI_EM_RECORDER_RATE_HARD_LIMIT_MAXNUM
    },
    //dyn_range_reduction
    {
        MMI_EM_RECORDER_SETTING_INLINE_EDITOR,
        L"Range reduction",
        &(g_mmi_em_recorder_setting.dyn_range_reduction),
        NULL,
        MMI_EM_RECORDER_RANGE_REDUCTION_MAXNUM
    },
    
    /*If adding a new item,plz add it above this line-----------------*/
};


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_rec_setting_set_data
 * DESCRIPTION
 *  set default values to every inline item
 * PARAMETERS
 *  data:[in] inline item data
 *  inline_gid:[in] inline group id
 *  item_id:[in] inline item id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_misc_rec_setting_set_data(const mmi_em_recorder_setting_items_struct *data,mmi_id inline_gid,U16 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR   set_data_buffer[MMI_EM_RECORDER_SETTING_MAX_INPUT_NUM]= {'\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_wsprintf(set_data_buffer, "%d", *(data->val_addr));
    cui_inline_set_value(inline_gid, item_id, (void *)set_data_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_rec_setting_entry_param_ajust_scr
 * DESCRIPTION
 *  entry recorder param ajust screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_em_misc_rec_setting_entry_param_ajust_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    cui_inline_struct                   mmi_em_recorder_setting_inline;
    cui_inline_set_item_struct          mmi_em_set_item_inline;
    cui_inline_item_caption_struct      mmi_em_set_item_caption_inline;
    cui_inline_item_select_struct       mmi_em_set_item_selector_inline;
    cui_inline_item_text_edit_struct    mmi_em_set_item_editor_inline;
    mmi_id                              mmi_em_rec_setting_inline_gid;
    U16 item_id = CUI_INLINE_ITEM_ID_BASE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_em_recorder_setting_inline, 0, sizeof(mmi_em_recorder_setting_inline));
    mmi_em_recorder_setting_inline.title = STR_ID_EM_MISC_RECORDER_SETTING_PARAM_AJUST;
    mmi_em_recorder_setting_inline.screen_flag = CUI_INLINE_SCREEN_LOOP;
    
    mmi_em_rec_setting_inline_gid = cui_inline_create(
                   GRP_ID_EM_MISC_RECORDER_SETTING,
                   &mmi_em_recorder_setting_inline);

    while(i != (sizeof(mmi_em_rec_setting_items)/sizeof(mmi_em_rec_setting_items[0])))
    {
    
        //mmi_em_set_item_caption_inline.string_id = mmi_em_rec_setting_items[i].caption_str_id;
		mmi_em_set_item_caption_inline.string_id = 0;
        mmi_em_set_item_inline.item_id = item_id++;
        mmi_em_set_item_inline.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_CENTER_JUSTIFY;
        mmi_em_set_item_inline.item_data = (void*)(&mmi_em_set_item_caption_inline);
        mmi_em_set_item_inline.image_id = 0;
        cui_inline_insert_item(mmi_em_rec_setting_inline_gid, CUI_INLINE_INSERT_TAIL, &mmi_em_set_item_inline);
		cui_inline_set_value(mmi_em_rec_setting_inline_gid, mmi_em_set_item_inline.item_id, (void *)mmi_em_rec_setting_items[i].caption_str);

        if(mmi_em_rec_setting_items[i].type == MMI_EM_RECORDER_SETTING_INLINE_SELECTOR)
        {
            mmi_em_set_item_selector_inline.n_items = mmi_em_rec_setting_items[i].edi_count_or_sel_count;
            mmi_em_set_item_selector_inline.highlighted_item = (U8)(*(mmi_em_rec_setting_items[i].val_addr));
            mmi_em_set_item_selector_inline.list_of_item_id = mmi_em_rec_setting_items[i].selector;
        
            mmi_em_set_item_inline.item_id = item_id++;
            mmi_em_set_item_inline.item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY;
            mmi_em_set_item_inline.item_data = (void*)(&mmi_em_set_item_selector_inline);
            cui_inline_insert_item(mmi_em_rec_setting_inline_gid, CUI_INLINE_INSERT_TAIL, &mmi_em_set_item_inline);
        }
        else
        {
            mmi_em_set_item_editor_inline.string_id = 0;
            mmi_em_set_item_editor_inline.default_text_id = 0;
            mmi_em_set_item_editor_inline.input_extended_type = NULL;
            mmi_em_set_item_editor_inline.required_input_mode_set = NULL;
            mmi_em_set_item_editor_inline.buffer_size = mmi_em_rec_setting_items[i].edi_count_or_sel_count;
            mmi_em_set_item_editor_inline.input_type = IMM_INPUT_TYPE_NUMERIC;
            
            mmi_em_set_item_inline.item_id = item_id++;
            mmi_em_set_item_inline.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY;
            mmi_em_set_item_inline.item_data = (void*)(&mmi_em_set_item_editor_inline);
            //mmi_em_misc_rec_setting_set_data(&(mmi_em_rec_setting_items[i]),mmi_em_rec_setting_inline_gid,mmi_em_set_item_inline.item_id);
            cui_inline_insert_item(mmi_em_rec_setting_inline_gid, CUI_INLINE_INSERT_TAIL, &mmi_em_set_item_inline);
            mmi_em_misc_rec_setting_set_data(&(mmi_em_rec_setting_items[i]),mmi_em_rec_setting_inline_gid,mmi_em_set_item_inline.item_id);
        }
		i++;
    }
    
    cui_inline_set_highlight_item(mmi_em_rec_setting_inline_gid, CUI_INLINE_ITEM_ID_BASE);
    cui_inline_run(mmi_em_rec_setting_inline_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_rec_setting_str_to_int
 * DESCRIPTION
 *  string value trans to int value
 * PARAMETERS
 *  data: [in]string value
 * RETURNS
 *  U32: [out]int value
 *****************************************************************************/
static U32 mmi_em_misc_rec_setting_str_to_int(WCHAR * data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp[MMI_EM_RECORDER_SETTING_MAX_INPUT_NUM] = {NULL};
    U32 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_to_asc(temp, data);
    value = atoi((CHAR*)temp);
    return value;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_rec_setting_store_data
 * DESCRIPTION
 *  store input value to the global variable g_mmi_em_recorder_setting
 * PARAMETERS
 *  evt: [in] inline event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_em_misc_rec_setting_store_data(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 value;
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct*)evt;
    WCHAR store_buffer[MMI_EM_RECORDER_SETTING_MAX_INPUT_NUM]= {NULL};
    MMI_ID inline_gid;
    U16 item_id = CUI_INLINE_ITEM_ID_BASE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    inline_gid = inline_evt->sender_id;

    while(i != (sizeof(mmi_em_rec_setting_items)/sizeof(mmi_em_rec_setting_items[0])))
    {
        if(mmi_em_rec_setting_items[i].type == MMI_EM_RECORDER_SETTING_INLINE_SELECTOR)
        {
            cui_inline_get_value(
                         inline_gid,
                         item_id + 2*i + 1,
                         (void*)(mmi_em_rec_setting_items[i].val_addr));
        }
        else
        {
            cui_inline_get_value(
                         inline_gid,
                         item_id + 2*i + 1,
                         (void*)(store_buffer));
            value = mmi_em_misc_rec_setting_str_to_int(store_buffer);
            *(mmi_em_rec_setting_items[i].val_addr) = value;
        }
  
		i++;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_rec_setting_set_item_caption
 * DESCRIPTION
 *  set caption to every inline item
 * PARAMETERS
 *  inline_gid:[in] inline group id
 *  item_id:[in] inline item id
 * RETURNS
 *  void
 *****************************************************************************/
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
/*****************************************************************************
*	EM Recorder Setting added end
*****************************************************************************/

#endif /*__MMI_EM_MISC_RECORDER_PARAM_AJUST__*/



