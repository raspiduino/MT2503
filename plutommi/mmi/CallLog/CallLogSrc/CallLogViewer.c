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
*  CallLogViewer.c
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalResDef.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "custom_phb_config.h"
#include "nvram_common_defs.h"
#include "app_datetime.h"
#include "gui_data_types.h"
#include "wgui.h"

#include "UcmGprot.h"
#include "CallLogSrvGprot.h"
#include "CallLogConfig.h"
#include "CallLogGprot.h"
#include "CallLogProt.h"
#include "CallLogViewer.h"

#ifdef __MMI_TELEPHONY_SUPPORT__

#include "mmi_rp_app_calllog_def.h"


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_VR_TEMP_BUF_LEN                        (256)
#define MMI_CLOG_VR_TEMP_BUF_SIZE                       ((MMI_CLOG_VR_TEMP_BUF_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_VR_BUF_MAX_LEN                         (SRV_CLOG_CID_MAX_LEN + SRV_CLOG_NAME_MAX_LEN + 200)
#define MMI_CLOG_VR_BUF_MAX_SIZE                        ((MMI_CLOG_VR_BUF_MAX_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_VR_FORMAT_DATA_LEN                     (sizeof("\n\n\n") - 1)

#define MMI_CLOG_VR_FLAG_SUP_MERGE                      (0x0001)
#define MMI_CLOG_VR_FLAG_CID_IS_EMPTY                   (0x0002)
#define MMI_CLOG_VR_FLAG_BUF_CHANGED                    (0x0004)

#ifdef __MMI_CLOG_FPBW__
#define MMI_CLOG_VR_MAX_ITEM                            (6)
#endif /* __MMI_CLOG_FPBW__*/
/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    MMI_MENU_ID root_menu;
    MMI_STR_ID title_str_id;
    const mmi_clog_key_tbl_struct *key_tbl;
} mmi_clog_vr_scrn_data_struct;

typedef struct
{
    U16 flags;
    mmi_clog_vr_mode_enum mode;
    mmi_clog_vr_style_enum style;
    mmi_clog_lt_type_enum lt_type;
    mmi_clog_lt_id_enum sel_lt_id;
    mmi_clog_lt_type_enum sel_type;
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    MMI_ID self_gid;
#ifdef __MMI_CLOG_FPBW__
    srv_clog_log_struct *log;
#else /*__MMI_CLOG_FPBW__*/
    WCHAR *buf;
#endif /*__MMI_CLOG_FPBW__*/
} mmi_clog_vr_inst_struct;

typedef struct
{
    U8 is_ready;
    mmi_clog_vr_inst_struct inst_tbl[MMI_CLOG_VR_INST_MAX_NUM];
} mmi_clog_vr_cntx_struct;

/*----------------------------------------------------------------------------*/
/* typedef with structure                                                     */
/*----------------------------------------------------------------------------*/
typedef S32(*MMI_CLOG_VR_FORMAT_TEXT_PARA_HDLR) (mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log,
                                                 U32 *cur_len);

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*--------------- Context Operation ------------------------------------------*/
static mmi_clog_vr_cntx_struct *mmi_clog_vr_cntx_init(void);
static mmi_clog_vr_cntx_struct *mmi_clog_vr_get_cntx(void);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static mmi_clog_vr_inst_struct *mmi_clog_vr_alloc_inst(mmi_clog_vr_cntx_struct *cntx);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
static void mmi_clog_vr_destroy_inst(mmi_clog_vr_inst_struct *inst);
static mmi_clog_vr_inst_struct *mmi_clog_vr_get_inst_by_gid(MMI_ID gid);

/*--------------- Viewer Screen ---------------------------------------------*/
static MMI_RET mmi_clog_vr_group_proc(mmi_event_struct *evt);
static MMI_RET mmi_clog_vr_scrn_proc(mmi_event_struct * evt);


static void mmi_clog_vr_close(MMI_ID gid);
static void mmi_clog_vr_show_text(mmi_clog_vr_inst_struct *inst);

/*--------------- Key Handler ---------------------------------------------*/
static void mmi_clog_vr_set_key_hdlr(mmi_clog_vr_inst_struct *inst, U32 is_pure_view);
static void mmi_clog_vr_lsk_hdlr(void);
static void mmi_clog_vr_csk_hdlr(void);
static void mmi_clog_vr_rsk_hdlr(void);
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif
static void mmi_clog_vr_send_key_hdlr(void);
static void mmi_clog_vr_make_call_hdlr(mmi_clog_key_enum from_key);

/*--------------- Text Format ----------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__
static S32 mmi_clog_vr_prepare_text_data(mmi_clog_vr_inst_struct *inst);
static S32 mmi_clog_vr_format(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log);

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__
static S32 mmi_clog_vr_format_type(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__*/

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__
static S32 mmi_clog_vr_format_name(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__*/

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__
static S32 mmi_clog_vr_format_total_num(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__*/

static S32 mmi_clog_vr_format_number(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
static S32 mmi_clog_vr_format_time(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
//static S32 mmi_clog_vr_format_duration(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len);
static S32 mmi_clog_vr_cp_key_value(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value);
static void mmi_clog_vr_format_remove_tail(mmi_clog_vr_inst_struct *inst, U32 cur_len);
#else /*__MMI_CLOG_FPBW__*/
static S32 mmi_clog_vr_fill_item(mmi_clog_vr_inst_struct *inst, U8 **list_of_items, U8 *number_of_items);
static void mmi_clog_vr_highlight_key_hdlr(S32 item_index);
#endif /*__MMI_CLOG_FPBW__*/

static void mmi_clog_vr_inst_srv_evt_hdlr(mmi_clog_vr_inst_struct *inst, mmi_event_struct *evt);
static void mmi_clog_vr_refresh_screen(mmi_clog_vr_inst_struct *inst);

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__
static const MMI_CLOG_VR_FORMAT_TEXT_PARA_HDLR g_mmi_clog_vr_format_text_tbl[] = 
{
#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__
	mmi_clog_vr_format_type,
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__*/
#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__
    mmi_clog_vr_format_name,
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__*/
    mmi_clog_vr_format_number,

    mmi_clog_vr_format_time,
    //mmi_clog_vr_format_duration,
#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__
    mmi_clog_vr_format_total_num
#endif/*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__*/
};
#else
static const MMI_STR_ID g_mmi_clog_vr_title_str_id[] =
{
    STR_ID_CLOG_NAME_EX,
    STR_ID_CLOG_NUMBER_EX,
    STR_GLOBAL_DATE,
    STR_GLOBAL_TIME,
    STR_ID_CLOG_DURATION_EX,
    STR_ID_CLOG_TOTAL_NUM_EX
};

#endif /* __MMI_CLOG_FPBW__*/

static const mmi_clog_key_tbl_struct g_mmi_clog_vr_key_tbl = 
{
    {
        &g_mmi_clog_lsk_option,
        &g_mmi_clog_csk_call,
        &g_mmi_clog_rsk_back
    },
    {
        mmi_clog_vr_lsk_hdlr,
        mmi_clog_vr_csk_hdlr,
        mmi_clog_vr_rsk_hdlr,
        mmi_clog_vr_send_key_hdlr
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif
     }
};

static const mmi_clog_vr_scrn_data_struct g_mmi_clog_vr_scrn_data = 
{
    MAIN_MENU_CALL_LOG,
    STR_GLOBAL_VIEW,
    &g_mmi_clog_vr_key_tbl
};

static mmi_clog_vr_cntx_struct g_mmi_clog_vr_cntx;
#ifdef __MMI_CLOG_FPBW__
static U16 g_mmi_clog_vr_time[9]; /*HH:MM am*/
static U16 g_mmi_clog_vr_duration[9]; /*HH:MM:SS*/
static U16 g_mmi_clog_vr_date[11]; /*YYYY/MM/DD*/
static U16 g_mmi_clog_vr_total_num[15]; /*255 times*/
static MMI_BOOL g_mmi_clog_vr_name_empty_flag = MMI_FALSE;
static S32 g_mmi_clog_hlight_index = -1;
#endif /*# __MMI_CLOG_FPBW__*/
/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_vr_cntx_struct *mmi_clog_vr_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_clog_vr_cntx.is_ready)
        return &g_mmi_clog_vr_cntx;

    memset(&g_mmi_clog_vr_cntx, 0x0, sizeof(mmi_clog_vr_cntx_struct));
    g_mmi_clog_vr_cntx.is_ready = MMI_TRUE;
    return &g_mmi_clog_vr_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_vr_cntx_struct *mmi_clog_vr_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_clog_vr_cntx;
}


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_alloc_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_vr_inst_struct *mmi_clog_vr_alloc_inst(mmi_clog_vr_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_VR_INST_MAX_NUM == 1) /* For slim */
    {
        MMI_CLOG_SET_BIT(cntx->inst_tbl[0].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_VR);
        return &cntx->inst_tbl[0];
    }
    else
    {
        for (i = 0; i < MMI_CLOG_VR_INST_MAX_NUM; i++)
        {
            if (MMI_CLOG_CHECK_BIT(cntx->inst_tbl[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED))
                continue;
            MMI_CLOG_SET_BIT(cntx->inst_tbl[i].flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_VR);
            return &cntx->inst_tbl[i];
        }
        return NULL;
    }
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_destroy_inst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_destroy_inst(mmi_clog_vr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR))
        return;

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_VR_DESTROY_INST,
        inst->self_gid,
        inst->mode,
        inst->style,
        inst->sel_lt_id,
        inst->lt_type,
        inst->handle,
        inst->log_id,
        inst->flags));

    if (!SRV_CLOG_IS_ELM_INVALID(inst->handle) && !MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_EXT_HANDLE))
        srv_clog_destroy(inst->handle);

    memset(inst, 0x0, sizeof(mmi_clog_vr_inst_struct));
}


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_get_inst_by_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_clog_vr_inst_struct *mmi_clog_vr_get_inst_by_gid(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_vr_inst_struct *inst;
    mmi_clog_vr_inst_struct *inst_tbl = mmi_clog_vr_get_cntx()->inst_tbl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_VR_INST_MAX_NUM == 1)
    {
        inst = &inst_tbl[0];
        if (MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR) && inst->self_gid == gid)
            return inst;
        else
            return NULL;
    }
    else
    {
        for (i = 0; i < MMI_CLOG_VR_INST_MAX_NUM; i++)
        {
            inst = &inst_tbl[i];
            if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR))
                continue;
            if (inst->self_gid == gid)
                return inst;
        }
        return NULL;
    }
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]                
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_vr_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_inst_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_vr_inst_struct*) evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
        #ifndef __MMI_CLOG_FPBW__
            mmi_frm_scrmem_free(inst->buf);
            inst->buf = NULL;
        #else /*__MMI_CLOG_FPBW__*/
            mmi_frm_scrmem_free(inst->log);
            inst->log = NULL;
        #endif /*__MMI_CLOG_FPBW__*/
        }
            break;

        case EVT_ID_SCRN_ACTIVE:
            mmi_clog_vr_show_text(inst);
            break;

        default:
            break;
	}
   
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_create_and_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  create          [IN]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_clog_vr_create_and_run(MMI_ID parent_gid, mmi_clog_vr_create_struct *create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    mmi_clog_vr_cntx_struct *cntx;
    mmi_clog_vr_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_IS_GID_INVALID(parent_gid) || !create || SRV_CLOG_IS_ELM_INVALID(create->log_id))
        return GRP_ID_INVALID;

    if (create->mode >= MMI_CLOG_VR_MODE_MAX_ITEM || !MMI_CLOG_CHECK_BIT(create->style, MMI_CLOG_VR_STYLE_ALL))
        return GRP_ID_INVALID;

    cntx = mmi_clog_vr_cntx_init();

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    inst = &cntx->inst_tbl[0];
    MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_IS_USED | MMI_CLOG_INST_TYPE_VR);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst = mmi_clog_vr_alloc_inst(cntx);
    if (!inst)
    {
        MMI_CLOG_IT_ASSERT(0);
        return GRP_ID_INVALID;
    }
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

    inst->handle = create->handle;
    inst->mode = create->mode;
    inst->style = create->style;
    inst->log_id = create->log_id;
    inst->sel_lt_id = create->sel_lt_id;
    inst->lt_type = create->lt_type;
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    if (!SRV_CLOG_IS_ELM_INVALID(create->handle))
        MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_EXT_HANDLE);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    if (create->sup_merge)
        MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_VR_FLAG_SUP_MERGE);

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    gid = GRP_ID_CLOG_VIEWER;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    gid = mmi_clog_alloc_gid(MMI_CLOG_GRP_TYPE_VR);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst->self_gid = mmi_frm_group_create_ex(parent_gid, gid, mmi_clog_vr_group_proc, inst, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_VR_CREATE,
        parent_gid,
        inst->self_gid,
        inst->mode,
        inst->style,
        inst->sel_lt_id,
        inst->lt_type,
        inst->handle,
        inst->log_id,
        inst->flags));
    
	mmi_frm_scrn_create(inst->self_gid, SCR_ID_CLOG_VIEWER, mmi_clog_vr_scrn_proc, inst);
    return inst->self_gid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_set_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst                [IN]         
 *  is_pure_view        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_set_key_hdlr(mmi_clog_vr_inst_struct *inst, U32 is_pure_view)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_pure_view)
    {
        mmi_ucm_handle_sendkeys_for_call(g_mmi_clog_vr_scrn_data.key_tbl->hdlr[MMI_CLOG_KEY_SEND], KEY_EVENT_DOWN);

    #ifdef __MMI_IP_KEY__
/* under construction !*/
    #endif 

        EnableCenterSoftkey(
            g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_CSK]->str_id,
            g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_CSK]->img_id);
        SetCenterSoftkeyFunction(g_mmi_clog_vr_scrn_data.key_tbl->hdlr[MMI_CLOG_KEY_CSK], KEY_EVENT_UP);
        redraw_center_softkey();
#ifndef __MMI_CLOG_FPBW__
        SetLeftSoftkeyFunction(g_mmi_clog_vr_scrn_data.key_tbl->hdlr[MMI_CLOG_KEY_LSK], KEY_EVENT_UP);
#else /*__MMI_CLOG_FPBW__*/
        RegisterHighlightHandler(mmi_clog_vr_highlight_key_hdlr);
#endif /*__MMI_CLOG_FPBW__*/
    }

    SetRightSoftkeyFunction(g_mmi_clog_vr_scrn_data.key_tbl->hdlr[MMI_CLOG_KEY_RSK], KEY_EVENT_UP);

#ifdef __MMI_CLOG_SIM_SYNC_TEST__
    {
        extern void srv_clog_sim_pwon_test(void);
        extern void srv_clog_sim_pwoff_test(void);
        extern void srv_clog_sim_sat_refresh_test(void);

        SetKeyHandler(srv_clog_sim_pwon_test, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(srv_clog_sim_pwoff_test, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(srv_clog_sim_sat_refresh_test, KEY_CAMERA, KEY_EVENT_UP);

        SetKeyHandler(srv_clog_sim_pwon_test, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(srv_clog_sim_pwoff_test, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(srv_clog_sim_sat_refresh_test, KEY_0, KEY_EVENT_UP);
    }
#endif /* __MMI_CLOG_SIM_SYNC_TEST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_show_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_show_text(mmi_clog_vr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *gui_buf = NULL;
    S32 is_pur_view = MMI_FALSE;
#ifdef __MMI_CLOG_FPBW__
    U8 *str_list[MMI_CLOG_VR_MAX_ITEM];
    U8 item_count = 0 ;
#endif /*__MMI_CLOG_FPBW__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_FPBW__
    ret = mmi_clog_vr_prepare_text_data(inst);
#else /*__MMI_CLOG_FPBW__*/   
    ret = mmi_clog_vr_fill_item(inst, str_list, &item_count);
#endif /*__MMI_CLOG_FPBW__*/
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_frm_group_close(inst->self_gid);
        return;
    }
#ifndef __MMI_CLOG_FPBW__
    if (MMI_CLOG_CHECK_BIT(inst->style, MMI_CLOG_VR_STYLE_PURE_VIEW) ||
        MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_VR_FLAG_CID_IS_EMPTY))
        is_pur_view = MMI_TRUE;
#endif /*__MMI_CLOG_FPBW__*/

    if (!mmi_is_redrawing_bk_screens())
    {
        if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_VR_FLAG_BUF_CHANGED))
        {
            gui_buf = NULL;
            MMI_CLOG_CLEAR_BIT(inst->flags, MMI_CLOG_VR_FLAG_BUF_CHANGED);
#ifdef __MMI_CLOG_FPBW__
            if(g_mmi_clog_vr_name_empty_flag)
                g_mmi_clog_hlight_index = 1;
            else
                g_mmi_clog_hlight_index = 0;
#endif /*__MMI_CLOG_FPBW__*/
        }
        else
        {
            gui_buf = mmi_frm_scrn_get_gui_buf(inst->self_gid, SCR_ID_CLOG_VIEWER);
        }
    }
#ifndef __MMI_CLOG_FPBW__
    ShowCategory74Screen(
        g_mmi_clog_vr_scrn_data.title_str_id,
        GetRootTitleIcon(g_mmi_clog_vr_scrn_data.root_menu),
        (U16) (is_pur_view == MMI_TRUE ? 0 : g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_LSK]->str_id),
        (U16) (is_pur_view == MMI_TRUE ? 0 : g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_LSK]->img_id),
        g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_RSK]->str_id,
        g_mmi_clog_vr_scrn_data.key_tbl->softkey[MMI_CLOG_KEY_RSK]->img_id,
        (U8*) inst->buf,
        (S32) (mmi_wcslen(inst->buf) + 1),
        gui_buf);
#else /*__MMI_CLOG_FPBW__*/ 

    ShowCategory84Screen(
        g_mmi_clog_vr_title_str_id[g_mmi_clog_hlight_index],
        GetRootTitleIcon(g_mmi_clog_vr_scrn_data.root_menu),
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        item_count,
        str_list,
        NULL,
        0,
        0,
        gui_buf);
#endif /*__MMI_CLOG_FPBW__*/
    mmi_clog_vr_set_key_hdlr(inst, is_pur_view);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_clog_vr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_vr_inst_struct*) evt->user_data;

    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        mmi_clog_vr_destroy_inst(inst);
#ifdef __MMI_CLOG_FPBW__
		g_mmi_clog_hlight_index = -1;
#endif /*__MMI_CLOG_FPBW__*/
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_close(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_vr_cntx_struct *cntx;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_vr_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    cntx = mmi_clog_vr_get_cntx();
    inst = &cntx->inst_tbl[0];
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    inst = mmi_clog_vr_get_inst_by_gid(gid);
    if (!inst)
        return;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    MMI_CLOG_CLEAR_BIT(inst->flags, MMI_CLOG_CMN_INST_FLAG_IS_USED);
    inst->handle = 0;   /* not create now */
    mmi_frm_group_close(inst->self_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_inst_struct *inst;
    mmi_clog_op_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_vr_inst_struct*) mmi_clog_get_inst_by_act_gid();

	para.flags = 0;
    if (inst->lt_type == MMI_CLOG_LT_TYPE_LIST)
        para.type = MMI_CLOG_OP_TYPE_LIST_VIEWER;

#ifdef __MMI_CLOG_TAB_SUPPORT__
    else if (inst->lt_type == MMI_CLOG_LT_TYPE_TAB)
        para.type = MMI_CLOG_OP_TYPE_TAB_VIEWER;
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
    else
    {
        MMI_CLOG_IT_ASSERT(0);
    }
    para.sel_lt_id = inst->sel_lt_id;
    para.handle = inst->handle;
    para.log_id = inst->log_id;
    mmi_clog_op_enter(inst->self_gid, &para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_clog_vr_make_call_hdlr(MMI_CLOG_KEY_CSK);
    mmi_clog_vr_lsk_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_vr_inst_struct*) mmi_clog_get_inst_by_act_gid();
    mmi_clog_vr_close(inst->self_gid);
    /* mmi_frm_scrn_close_active_id(); */
}


#ifdef __MMI_IP_KEY__
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
#endif /* __MMI_IP_KEY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_make_call_hdlr(MMI_CLOG_KEY_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_make_call_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  from_key        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_make_call_hdlr(mmi_clog_key_enum from_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_vr_inst_struct *inst;
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_para_struct para;
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_para_struct para;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (mmi_clog_vr_inst_struct*) mmi_clog_get_inst_by_act_gid();

    MMI_CLOG_ASSERT(MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR));

    para.flags = 0;
    para.handle = inst->handle;
    para.log_id = inst->log_id;
    para.op_mid = MMI_CLOG_OP_MID_MAKE_CALL;
    para.sel_lt_id = inst->sel_lt_id;
    
    if (from_key == MMI_CLOG_KEY_SEND)
        MMI_CLOG_SET_BIT(para.flags, MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY);
#ifdef __MMI_IP_KEY__
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_op_run(inst->self_gid, &para);
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_act_proc(inst->self_gid, &para);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
}
#ifndef __MMI_CLOG_FPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_prepare_text_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_prepare_text_data(mmi_clog_vr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_log_struct log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->buf = mmi_frm_scrmem_alloc(MMI_CLOG_VR_BUF_MAX_SIZE);
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
    if (ret != SRV_CLOG_RET_OK)
        return ret;
    
    if (mmi_clog_is_cid_empty(&log))
        MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_VR_FLAG_CID_IS_EMPTY);
    mmi_clog_vr_format(inst, &log);
    return SRV_CLOG_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 cur_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_vr_format_text_tbl) / sizeof(MMI_CLOG_VR_FORMAT_TEXT_PARA_HDLR); i++)
    {
        ret = (g_mmi_clog_vr_format_text_tbl[i]) (inst, log, &cur_len);
        if (!ret)
        {
            mmi_clog_vr_format_remove_tail(inst, cur_len);
            return ret;
        }
    }
    mmi_clog_vr_format_remove_tail(inst, cur_len);
    MMI_CLOG_ASSERT(ret <= MMI_CLOG_VR_BUF_MAX_LEN);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_remove_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]         
 *  cur_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_format_remove_tail(mmi_clog_vr_inst_struct *inst, U32 cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ASSERT(cur_len >= MMI_CLOG_VR_FORMAT_DATA_LEN);
    inst->buf[cur_len - 2] = '\0';
}

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format_type(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_clog_get_clt_str_id((srv_clog_clt_enum)log->data.call_log.log_type);
    return mmi_clog_vr_cp_key_value(inst->buf, MMI_CLOG_VR_BUF_MAX_LEN, cur_len, STR_ID_CLOG_TYPE, get_string(str_id));
}
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TYPE__*/

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format_name(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* name */
    if (mmi_clog_is_name_empty(log))
        return MMI_TRUE;
    return mmi_clog_vr_cp_key_value(
            inst->buf,
            MMI_CLOG_VR_BUF_MAX_LEN,
            cur_len,
            STR_ID_CLOG_NAME,
            log->data.call_log.name);
}

#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_NAME__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format_number(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;
    WCHAR *value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_cid_empty(log))
    {
		value = log->data.call_log.cid;
    }
    else
    {
        if (log->data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
            str_id = STR_ID_CLOG_ANON_URI;
        else
            str_id = STR_GLOBAL_NO_NUMBER;

        value = get_string(str_id); 
    }
    return mmi_clog_vr_cp_key_value(
        inst->buf,
        MMI_CLOG_VR_BUF_MAX_LEN,
        cur_len,
        STR_ID_CLOG_NUMBER,
        value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_get_call_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [IN]     
 *  buf_max_len         [IN]     
 *  key_str_id          [IN] 
 *  value               [IN] 
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_get_call_time(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    //WCHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //str = get_string(key_str_id);
    len = mmi_wcslen(value) + MMI_CLOG_VR_FORMAT_DATA_LEN;

    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;

    kal_wsprintf(buf + *cur_len, "%w%w",  value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format_time(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_FALSE;
    U32 len;
    WCHAR *str_buf;
    applib_time_struct app_time;

    U32 i = 0;
    WCHAR *str;
    U32 hour;
    U32 min;
    U32 sec;

	WCHAR call_dur[40]={0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (!log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX])
     //   return MMI_TRUE;

	str = get_string(STR_ID_CLOG_TIMESTAMP);
	kal_wsprintf(inst->buf + *cur_len, "%w%w", str, L"\n");
	*cur_len = mmi_wcslen(inst->buf);
	 
	for (i=0; i<log->data.call_log.total_num && i < SRV_CLOG_TIME_DETAIL_MAX_NUM; i++)
	{
		
    str_buf = OslMalloc(MMI_CLOG_VR_TEMP_BUF_SIZE);

	 /*get time*/
	 if (log->data.call_log.timestamp[i] == 0)
     {
	 	/* unknown data */
		kal_wsprintf(str_buf, "%w",GetString(STR_ID_CLOG_VIEW_UNKNOWN));
		//kal_wsprintf(call_dur, "   %w",GetString(STR_ID_CLOG_VIEW_UNKNOWN));
	 	//mmi_wcscat(str_buf,call_dur);
	 	ret = mmi_clog_vr_cp_key_value(inst->buf, MMI_CLOG_VR_BUF_MAX_LEN, cur_len, 0, str_buf);
	    OslMfree(str_buf);
		continue;
	 }
	 else
	 {
	 	mmi_clog_time_utc2app(log->data.call_log.timestamp[i], &app_time);
		date_string((UI_time*) & app_time, (UI_string_type) str_buf, DT_IDLE_SCREEN);
		mmi_wcscat(str_buf, L" ");
		len = mmi_wcslen((const WCHAR*)str_buf);
		time_string((UI_time*) & app_time, (UI_string_type) (str_buf + len), DT_IDLE_SCREEN);
	 }

#ifndef __OP01_3G__

		 /*get call duration*/
		 if(SRV_CLOG_CLT_MISSED != log->data.call_log.log_type)
		 {			 
			 if ((log->data.call_log.duration[i])!= 0)
			 {
			 	mmi_clog_duration_val2app(log->data.call_log.duration[i], &hour, &min, &sec);
			 }
			 else 
			 {
			 	hour = 0;
				min = 0;
				sec = 0;
			 }
			 kal_wsprintf(call_dur, "  %02d:%02d:%02d", hour, min, sec);
			 mmi_wcscat(str_buf,call_dur);
		 }
		 /* Missed call or Ring once */
		else 
#else  /*__OP01_3G__*/
		if(SRV_CLOG_CLT_MISSED == log->data.call_log.log_type)
#endif  /*__OP01_3G__*/
		{
			 S8 *strtmp;
			 if (log->data.call_log.duration[i] > 3)
			 {
			 	strtmp = GetString(STR_ID_CLOG_VIEW_MISSED_CALL);
			 }
			 else 
			 {
				strtmp = GetString(STR_ID_CLOG_VIEW_RING_ONES);
			 }
		  	kal_wsprintf(call_dur, " %w", strtmp);
    	 	mmi_wcscat(str_buf, call_dur);
		}
		 /*get string*/
		 ret = mmi_clog_vr_cp_key_value(inst->buf, MMI_CLOG_VR_BUF_MAX_LEN, cur_len, 0, str_buf);
    	 OslMfree(str_buf);
	}
	kal_wsprintf(inst->buf + *cur_len, "%w",L"\n");
	*cur_len = mmi_wcslen(inst->buf);
	 
    return ret;
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
#ifdef __OP01_3G__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __OP01_3G__ */
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
#endif /* __OP01_3G__ */
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_format_total_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_format_total_num(mmi_clog_vr_inst_struct *inst, srv_clog_log_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *str_buf;
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_VR_FLAG_SUP_MERGE))
        return MMI_TRUE;

    str_buf = (WCHAR*) OslMalloc(MMI_CLOG_VR_TEMP_BUF_SIZE);
    if (log->data.call_log.total_num > 1)
        str_id = STR_ID_CLOG_TIMES;
    else
        str_id = STR_ID_CLOG_TIME;
    kal_wsprintf(str_buf, "%d %w", log->data.call_log.total_num, get_string(str_id));
    ret = mmi_clog_vr_cp_key_value(inst->buf, MMI_CLOG_VR_BUF_MAX_LEN, cur_len, STR_ID_CLOG_TOTAL_NUM, str_buf);
    OslMfree(str_buf);
    return ret;
}
#endif /*__MMI_CLOG_COMPUND_ACTION_VIWE_CLOG_TOTAL_NUM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_cp_key_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [IN/OUT]         
 *  buf_max_len     [IN]        
 *  cur_len         [IN/OUT]         
 *  key_str_id      [IN]        
 *  value           [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_cp_key_value(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    WCHAR *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(key_str_id)
	{
		str = get_string(key_str_id);
    	len = mmi_wcslen(str);
    }

	len += (mmi_wcslen(value) + MMI_CLOG_VR_FORMAT_DATA_LEN);
	
    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;
	
	if(key_str_id)
    	kal_wsprintf(buf + *cur_len, "%w%w%w%w", str, L"\n", value, L"\n\n");
	else
		kal_wsprintf(buf + *cur_len, "%w%w", value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}
#else /*__MMI_CLOG_FPBW__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_fill_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_of_items        [IN]
 *  number_of_items      [OUT]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_vr_fill_item(mmi_clog_vr_inst_struct *inst, U8 **list_of_items, U8 *number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_CLOG_RET_OK;
    MMI_STR_ID str_id;
    U32 hour, min, sec;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->log = mmi_frm_scrmem_alloc(sizeof(srv_clog_log_struct));
    ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, inst->log);
    if (ret != SRV_CLOG_RET_OK)
        return ret;
        
    /* name */
    if (!mmi_clog_is_name_empty(inst->log))
    {
        list_of_items[(*number_of_items)++] = (U8 *)inst->log->data.call_log.name;
        g_mmi_clog_vr_name_empty_flag = MMI_FALSE;
        if(g_mmi_clog_hlight_index < 0)
            g_mmi_clog_hlight_index = 0;
    }
    else
    {
        g_mmi_clog_vr_name_empty_flag = MMI_TRUE;
        if(g_mmi_clog_hlight_index < 0)
            g_mmi_clog_hlight_index = 1;
    }
    
    /* number */
    if (!mmi_clog_is_cid_empty(inst->log))
    {
        list_of_items[(*number_of_items)++] = (U8 *)inst->log->data.call_log.cid;
    }
    else
    {
        if (inst->log->data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
            str_id = STR_ID_CLOG_ANON_URI;
        else
            str_id = STR_GLOBAL_NO_NUMBER;

        list_of_items[(*number_of_items)++] = (U8 *)get_string(str_id); 
    }
    
    /* Date & Time*/ 
    if (inst->log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX] == 0)
    {	 	
        /* Date */
        list_of_items[(*number_of_items)++] = (U8 *)get_string(STR_ID_CLOG_VIEW_UNKNOWN); 
        /* Time */
        list_of_items[(*number_of_items)++] = (U8 *)get_string(STR_ID_CLOG_VIEW_UNKNOWN); 
	 }
	 else
	 {
	    applib_time_struct app_time;
	 	mmi_clog_time_utc2app(inst->log->data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX], &app_time);
         /* Date */
		date_string((UI_time*) & app_time, (UI_string_type)g_mmi_clog_vr_date, DT_IDLE_SCREEN);        
        list_of_items[(*number_of_items)++] = (U8 *)g_mmi_clog_vr_date; 
        /* Time */
        time_string((UI_time*) & app_time, (UI_string_type)g_mmi_clog_vr_time, DT_IDLE_SCREEN);        
        list_of_items[(*number_of_items)++] = (U8 *)g_mmi_clog_vr_time; 
	 }
   
    /* Duration */
    if ((!inst->log->data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX]) 
        || (SRV_CLOG_CLT_MISSED == inst->log->data.call_log.log_type))
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    else
    {
        mmi_clog_duration_val2app(inst->log->data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX], &hour, &min, &sec);
    }    
    kal_wsprintf(g_mmi_clog_vr_duration, "%02d:%02d:%02d", hour, min, sec);
    list_of_items[(*number_of_items)++] = (U8 *)g_mmi_clog_vr_duration; 
    
    /* Times */
    if (inst->log->data.call_log.total_num > 1)
        str_id = STR_ID_CLOG_TIMES;
    else
        str_id = STR_ID_CLOG_TIME;
    kal_wsprintf(g_mmi_clog_vr_total_num, "%d %w", inst->log->data.call_log.total_num, get_string(str_id));

    list_of_items[(*number_of_items)++] = (U8 *)g_mmi_clog_vr_total_num;

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_highlight_key_hdlr
 * DESCRIPTION
 *  view entry highlight handler. 
 * PARAMETERS
 * index       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_highlight_key_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_clog_vr_name_empty_flag)
        index++;
    ChangeTitleString((U8 *)get_string(g_mmi_clog_vr_title_str_id[index]));
    draw_title();
    g_mmi_clog_hlight_index = index;
    
}
#endif /*__MMI_CLOG_FPBW__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_srv_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_vr_srv_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_clog_vr_inst_struct *inst;
    mmi_clog_vr_cntx_struct *cntx = mmi_clog_vr_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_CLOG_VR_INST_MAX_NUM == 1)
    {
        inst = &cntx->inst_tbl[0];
        if (MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR) && 
            inst->handle != ((srv_clog_evt_log_op_struct*) evt)->handle)
        {
            mmi_clog_vr_inst_srv_evt_hdlr(inst, evt);
        }
    }
    else
    {
        for (i = 0; i < MMI_CLOG_VR_INST_MAX_NUM; i++)
        {
            inst = &cntx->inst_tbl[i];

            if (!MMI_CLOG_IS_INST_VALID(inst, MMI_CLOG_INST_TYPE_VR))
                continue;

            if (inst->handle == ((srv_clog_evt_log_op_struct*) evt)->handle)
                continue;

            mmi_clog_vr_inst_srv_evt_hdlr(inst, evt);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_inst_srv_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 *  evt         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_inst_srv_evt_hdlr(mmi_clog_vr_inst_struct *inst, mmi_event_struct *srv_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_evt->evt_id)
    {
        case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *evt = (srv_clog_evt_add_log_struct*) srv_evt;
            if (inst->log_id != evt->old_idf.log_id)
                return;
            if (evt->add_ret == SRV_CLOG_ADD_LOG_RET_PURE_MERGE)
            {
                /* Pure merge case, update the new log_id as log_id is changed but log is the same one with new time/num info */
                inst->log_id = evt->new_idf.log_id;
            }
            mmi_clog_vr_refresh_screen(inst);
            break;
        }
    #ifdef __MMI_CLOG_EVENT_REFRESH_SUPPORT__
        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *evt =  (srv_clog_evt_del_log_struct*) srv_evt;
            if (inst->log_id != evt->idf.log_id)
                return;
            mmi_clog_vr_close(inst->self_gid);
            break;
        }

        case EVT_ID_SRV_CLOG_DEL_ALL:
        {
            S32 ret;
            srv_clog_log_struct log;
            
            ret = srv_clog_get_log_by_id(inst->handle, inst->log_id, 0, &log);
            if (ret == SRV_CLOG_RET_NOT_FOUND)
            {
                mmi_clog_vr_close(inst->self_gid);
            }
            break;
        }

        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        {
            srv_clog_evt_update_log_struct *evt =  (srv_clog_evt_update_log_struct*) srv_evt;
            
            if (inst->log_id != evt->log.data.call_log.log_id)
                return;
            mmi_clog_vr_refresh_screen(inst);
            break;
        }
    #endif /* __MMI_CLOG_EVENT_REFRESH_SUPPORT__ */
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_refresh_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_vr_refresh_screen(mmi_clog_vr_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_FPBW__
    U8 *str_list[MMI_CLOG_VR_MAX_ITEM];
    U8 item_count = 0;
#endif /*__MMI_CLOG_FPBW__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_scrn_in_active(inst->self_gid, SCR_ID_CLOG_VIEWER))
    {
        MMI_CLOG_SET_BIT(inst->flags, MMI_CLOG_VR_FLAG_BUF_CHANGED);
        return;
    }
 #ifndef __MMI_CLOG_FPBW__
    mmi_frm_scrmem_free(inst->buf);
    mmi_clog_vr_prepare_text_data(inst);   
    ChangeCategory79MessageString((U8*) inst->buf, mmi_wcslen(inst->buf), MMI_TRUE, MMI_TRUE, MMI_FALSE);
 #else /*__MMI_CLOG_FPBW__*/
    mmi_frm_scrmem_free(inst->log);
    g_mmi_clog_hlight_index = -1;
    mmi_clog_vr_fill_item(inst, str_list, &item_count);
	RedrawCategoryFunction();
 #endif /*__MMI_CLOG_FPBW__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_vr_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  create      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_vr_init_para(mmi_clog_vr_create_struct *create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!create)
        return MMI_RET_ERR;

    memset(create, 0x0, sizeof(mmi_clog_vr_create_struct));
    return MMI_RET_OK;
}

#else 

MMI_RET mmi_clog_vr_srv_evt_hdlr(mmi_event_struct *evt)
{

}
MMI_ID mmi_clog_vr_create_and_run(MMI_ID parent_gid, mmi_clog_vr_create_struct *create)
{

}

#endif /* __MMI_TELEPHONY_SUPPORT__ */
