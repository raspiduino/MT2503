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
 *   widget_editor_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements editor UI for widget
 *
 * Author:
 * -------
 * -------
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

//#include "mmi_include.h"

#include "MMI_features.h" 

#ifdef __MMI_GADGET_SUPPORT__

#include "conversions.h"
#include "widget_adp_struct.h"
#include "widget_api.h"
#include "mmi_rp_app_widget_delegator_def.h"
//#include "mmi_rp_app_wgtmgr_def.h"
#include "fseditorcuigprot.h"
#include "idlegprot.h"

#include "kal_general_types.h"    
#include "MMIDataType.h"    
#include "GlobalResDef.h"    
#include "mmi_frm_mem_gprot.h"    
#include "kal_public_api.h"    
#include "ImeGprot.h"    
#include "string.h"    
#include "mmi_frm_scenario_gprot.h"    
#include "wgui_categories_inputs.h"

typedef struct widget_editor_context_st
{
    int instance_id;
    int buffer_length;
    kal_uint8 *text_input_buffer;
    void *text_view_handle;
    mmi_id editor_id;
    short password_field;
} widget_editor_context_struct;

widget_editor_context_struct *g_widget_editor_cntx = NULL;


/*************************************************************************
    Local Functions
 *************************************************************************/
static mmi_ret mmi_widget_editor_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
			if (evt->evt_id == EVT_ID_CUI_FSEDITOR_SUBMMIT)
			{
                cui_fseditor_get_text(g_widget_editor_cntx->editor_id, (WCHAR *)g_widget_editor_cntx->text_input_buffer, MAX_STRING_LEN);
				widget_handle_enter_text_response(g_widget_editor_cntx->text_view_handle, TRUE, g_widget_editor_cntx->text_input_buffer);
			}
			cui_fseditor_close(g_widget_editor_cntx->editor_id);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(g_widget_editor_cntx->text_input_buffer);
            OslMfree(g_widget_editor_cntx);
            g_widget_editor_cntx = NULL;
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;

}

U32 widget_transform_input_method_to_mmi_method(int type, short pwd)
{
    U32 mmi_method = IMM_INPUT_TYPE_SENTENCE;

    if (pwd)
    {
        if (type == 0)
        {
            mmi_method = IMM_INPUT_TYPE_NUMERIC_PASSWORD;
        }
        else
        {
            mmi_method = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        }
    }
    else
    {
        switch(type)
        {
            case 0:
                mmi_method = IMM_INPUT_TYPE_KEYPAD_NUMERIC;
                break;
            case 1:
                mmi_method = IMM_INPUT_TYPE_SENTENCE;
                break;
            case 2:
                mmi_method = IMM_INPUT_TYPE_EMAIL;
                break;
            default:
                mmi_method = IMM_INPUT_TYPE_SENTENCE;
                break;
        }
    }
    return mmi_method;
}

/*************************************************************************
    Exported Functions
 *************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  widget_handle_enter_text_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  param              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void widget_handle_enter_text_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_enter_text_ind_struct *p = (widget_enter_text_ind_struct*)param;

    int buffer_length;
    kal_uint8 *text_input_buffer;
    mmi_id editor_id;
    U32 input_method;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (g_widget_editor_cntx != NULL)
	{
        return;
	}

    g_widget_editor_cntx = (widget_editor_context_struct *)OslMalloc(sizeof(widget_editor_context_struct));

    ASSERT(g_widget_editor_cntx);

    buffer_length = ((2 * p->length + 1) > MAX_STRING_LEN) ? MAX_STRING_LEN : (2 * p->length + 1);

    text_input_buffer = (kal_uint8*)OslMalloc(MAX_STRING_LEN);
    ASSERT(text_input_buffer);
    memset(text_input_buffer, 0, MAX_STRING_LEN);

    if (p->length)
    {
        memcpy((kal_uint8 *)text_input_buffer, (kal_uint8*)p->text, buffer_length);
    }

    g_widget_editor_cntx->instance_id = p->instance_id;
    g_widget_editor_cntx->text_input_buffer = text_input_buffer;
    g_widget_editor_cntx->password_field = p->password_field;
    g_widget_editor_cntx->buffer_length = buffer_length;

    mmi_frm_group_create(
        (mmi_frm_group_is_present(GRP_ID_WIDGET_VIEW)) ? GRP_ID_WIDGET_VIEW : mmi_idle_get_group_id(),
        GRP_ID_WIDGET_EDITOR,
        mmi_widget_editor_event_handler_proc,
        g_widget_editor_cntx);
    mmi_frm_group_enter(GRP_ID_WIDGET_EDITOR, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    editor_id = cui_fseditor_create(GRP_ID_WIDGET_EDITOR);

    ASSERT(editor_id);

    g_widget_editor_cntx->editor_id = editor_id;

    input_method = widget_transform_input_method_to_mmi_method(p->type, p->password_field);

    cui_fseditor_set_title(editor_id, STR_ID_WIDGET_EDIT_TEXT, 0);
    cui_fseditor_set_text(editor_id, (WCHAR *)text_input_buffer, buffer_length, buffer_length / ENCODING_LENGTH);

    if (p->multiline)
    {
        cui_fseditor_set_input_method(editor_id, input_method, 0, 0);
    }
    else
    {
        cui_fseditor_set_input_method(editor_id, input_method, 0, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    }
	
    cui_fseditor_run(editor_id);

}


int widget_close_editor_by_id(int instance_id)
{
    if (!g_widget_editor_cntx || g_widget_editor_cntx->instance_id != instance_id)
    {
        return 0;
    }

    cui_fseditor_close(g_widget_editor_cntx->editor_id);
}
#endif /* __MMI_GADGET_SUPPORT__ */
