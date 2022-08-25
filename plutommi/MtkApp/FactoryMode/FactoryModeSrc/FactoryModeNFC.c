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
 * FactoryModeSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode NFC
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
******************************************************************************/
#include "MMI_features.h"
	
	
#ifdef __MMI_FACTORY_MODE__
#ifdef __MMI_FM_NFC_SUPPORT__

/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "custom_events_notify.h"

#include "MenuCuiGprot.h"
#include "inlineCuiGprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_text_viewer.h"
#include "AlertScreen.h"

#include "MMI_common_app_trc.h"
#include "mmi_rp_app_factorymode_def.h"
#include "FactoryModeGProt.h"
#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"
#include "FactoryModeNFC.h"


/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/

/***************************************************************************** 
* global val / function
*****************************************************************************/
extern MMI_ID g_fm_gourp_id;

extern mmi_fm_item_cntxt_struct *g_fm_contxt;

/***************************************************************************** 
* static  function
*****************************************************************************/
typedef struct
{
    MMI_ID title_id;
    MMI_BOOL is_show_stop;
}mmi_fm_nfc_progress_param_struct;

static mmi_fm_nfc_struct g_fm_nfc;
static mmi_fm_nfc_struct *g_fm_nfc_p = &g_fm_nfc;


static MMI_RET mmi_fm_nfc_proc(mmi_event_struct *param);
static void mmi_fm_nfc_select_hdlr(cui_menu_event_struct * evt);
static void mmi_fm_nfc_show_progress(MMI_STR_ID title_id, MMI_BOOL is_show_stop);
static MMI_RET mmi_fm_nfc_show_progress_scr_proc(mmi_event_struct *param);
static void mmi_fm_nfc_genaral_test_req(U32 msg_id);
static void mmi_fm_nfc_genaral_rsp(nfc_script_response *rsp);
static void mmi_fm_nfc_tag_uid_rw_req(void);
static void mmi_fm_nfc_tag_uid_rw_rsp(void *rsp);
static void mmi_fm_nfc_stop_req(void);
static void mmi_fm_nfc_req(nfc_msg_struct *newmsg);
static U8 mmi_fm_nfc_rsp(void *param);
static void mmi_fm_nfc_int_to_hex_string(WCHAR* buf, U32 len, U16 value);
static MMI_RET mmi_fm_nfc_tag_uid_show_scrn_proc(mmi_event_struct *param);
static void mmi_fm_nfc_card_mode(void);
static MMI_RET mmi_fm_nfc_card_mode_inline_proc(mmi_event_struct *param);
static void mmi_fm_nfc_card_mode_req(U32 opt);
static void mmi_fm_nfc_rd_atenna_req(void);
static void mmi_fm_nfc_exit_fm_req(void);

/*--------------- trace config --------------------------------------------*/
#define MMI_FM_NFC_TRACE(num, p1, p2,p3)        MMI_FM_TRACE((MMI_FM_TRC_INFO,TRC_MMI_FM_NFC_PARAMS,num, p1, p2, p3))
#define MMI_FM_NFC_TRACE_0(num)                 MMI_FM_NFC_TRACE(num, 0, 0, 0)
#define MMI_FM_NFC_TRACE_1(num, p1)             MMI_FM_NFC_TRACE(num, p1, 0, 0)
#define MMI_FM_NFC_TRACE_2(num, p1,p2)          MMI_FM_NFC_TRACE(num, p1, p2, 0)
#define MMI_EM_NFC_TRACE_3                      MMI_FM_NFC_TRACE

typedef enum
{
    MMI_FM_NFC_TRC_REQ = 10000,
    MMI_FM_NFC_TRC_RSP,
    MMI_FM_NFC_TRC_TAG_UID_RSP,

    MMI_FM_NFC_TRC_NUM_MAX    
}mmi_fm_nfc_trc_num_enum;
/*---------------- trace config end --------------------------------------- */



/*only used for test by myself*/
//#define __MMI_FM_NFC_TEST__

#ifdef __MMI_FM_NFC_TEST__
static U32 mmi_fm_nfc_ut_test(void *param)
{

    static U32 buf[100];
    nfc_msg_struct *msg_rsp = (nfc_msg_struct *)buf;
    nfc_script_response *scrip_rsp = (nfc_script_response *)(msg_rsp + 1);
    mmi_fm_nfc_rsp(msg_rsp);
    return 0;
}
#endif



#define MMI_FM_NFC_INLINE_CAP  (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_FM_NFC_INLINE_SEL  (CUI_INLINE_ITEM_ID_BASE + 2)


static const cui_inline_item_caption_struct g_mmi_fm_nfc_card_mode_opt_cap = 
{
    STR_ID_FM_NFC_CARD_MODE_OPT
};



static const U16 g_mmi_fm_nfc_card_mode_opt_str[2] = 
{
    STR_ID_FM_NFC_CARD_MODE_OPT_SWP,
    STR_ID_FM_NFC_CARD_MODE_OPT_NFC_WI
};


static const cui_inline_item_select_struct g_mmi_fm_nfc_card_mode_opt_select = 
{
    2,
    0,
    g_mmi_fm_nfc_card_mode_opt_str
};


static const cui_inline_set_item_struct g_mmi_em_nfc_card_mode_inline[2] = 
{
    {MMI_FM_NFC_INLINE_CAP, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_fm_nfc_card_mode_opt_cap},
    {MMI_FM_NFC_INLINE_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_fm_nfc_card_mode_opt_select}    
};

static const cui_inline_struct g_mmi_em_nfc_se_scrn =
{
    sizeof(g_mmi_em_nfc_card_mode_inline) / sizeof (cui_inline_set_item_struct),
    STR_ID_FM_NFC_CARD_MODE,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    (const cui_inline_set_item_struct*)g_mmi_em_nfc_card_mode_inline   
};

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_entry
 * DESCRIPTION
 *  mmi_fm_nfc_entry
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
extern mmi_fm_item_cntxt_struct *g_fm_contxt;
void mmi_fm_nfc_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID cui_id;
    mmi_fm_item_cntxt_struct *fm_context = g_fm_contxt; //mmi_fm_get_context();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FM_ASSERT(fm_context);
    g_fm_nfc_p = &(fm_context->nfc);
#ifdef __MMI_FM_NFC_TEST__
    mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, (PsIntFuncPtr)mmi_fm_nfc_ut_test, MMI_FALSE);
#else
	mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, (PsIntFuncPtr)mmi_fm_nfc_rsp, MMI_FALSE);
#endif

    if (!mmi_frm_group_is_present(GRP_ID_FM_ROOT))
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_FM_ROOT, 0, 0);
        mmi_frm_group_enter(GRP_ID_FM_ROOT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }   
    group_id = mmi_frm_group_create(GRP_ID_FM_ROOT, 
                    GRP_ID_FM_NFC,
                    mmi_fm_nfc_proc,
                    0);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_id = cui_menu_create(group_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_FM_NFC, 
                            MMI_TRUE, 
                            0);
#if defined(__COSMOS_MMI_PACKAGE__)
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif /*__COSMOS_MMI_PACKAGE__*/
    cui_menu_run(cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_proc
 * DESCRIPTION
 *  mmi_fm_nfc_proc
 * PARAMETERS
 *  param     [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_fm_nfc_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_fm_nfc_select_hdlr(evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_fm_nfc_exit_fm_req();
            mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, NULL, MMI_FALSE);
            g_fm_nfc_p = 0;
            break;

        default:
            break;        
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_select_hdlr
 * DESCRIPTION
 *  mmi_fm_nfc_select_hdlr
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_select_hdlr(cui_menu_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->highlighted_menu_id)
    {            
        case MENU_ID_FM_NFC_SWP_SELF_TEST:
            mmi_fm_nfc_genaral_test_req(MSG_ID_NFC_SWP_SELF_TEST_REQ);
            break;

        case MENU_ID_FM_NFC_CANT_TEST:
            mmi_fm_nfc_rd_atenna_req();
//            mmi_fm_nfc_genaral_test_req(MSG_ID_NFC_ANTENNA_SELF_TEST_REQ);
            break;

        case MENU_ID_FM_NFC_TAG_UID_RW:
            mmi_fm_nfc_tag_uid_rw_req();
            break;

        case MENU_ID_FM_NFC_CARD_MODE:
            mmi_fm_nfc_card_mode();
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_show_progress
 * DESCRIPTION
 *  mmi_fm_nfc_show_progress
 * PARAMETERS
 *  str_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_show_progress(MMI_STR_ID title_id, MMI_BOOL is_show_stop)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_nfc_progress_param_struct *params;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params = OslMalloc(sizeof(mmi_fm_nfc_progress_param_struct));
    params->is_show_stop = is_show_stop;
    params->title_id = title_id;
    mmi_frm_scrn_create(GRP_ID_FM_NFC, SCR_ID_FM_NFC_SHOW_PROGRESS,mmi_fm_nfc_show_progress_scr_proc, (void*)params);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_show_progress_scr_proc
 * DESCRIPTION
 *  mmi_fm_nfc_show_progress_scr_proc
 * PARAMETERS
 *  param     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_fm_nfc_show_progress_scr_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fm_nfc_progress_param_struct *pp = (mmi_fm_nfc_progress_param_struct *)(param->user_data);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_INIT:
            mmi_frm_scrn_set_attribute(GRP_ID_FM_NFC, SCR_ID_FM_NFC_SHOW_PROGRESS, MMI_SCRN_ATTRIB_SMALL_SCRN);
            break;

        case EVT_ID_SCRN_DEINIT:
            if (pp)
            {
                OslMfree(pp);    
            }
            break;            
            
        case EVT_ID_SCRN_ACTIVE:
        {              
            ShowCategory66Screen(
                (U16)pp->title_id,
                0,
                0,
                0,
                (pp->is_show_stop ? STR_GLOBAL_STOP : 0),
                0,
                (PU8) get_string(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
            break;
        }

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            return MMI_RET_KEY_HANDLED;
        
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if (pp->is_show_stop)
            {
                mmi_fm_nfc_stop_req();    
            }            
            return MMI_RET_KEY_HANDLED;
        }
        default:
            break;
    }
    return MMI_RET_OK;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_genaral_test_req
 * DESCRIPTION
 *  mmi_fm_nfc_genaral_test_req
 * PARAMETERS
 *  msg_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_genaral_test_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_script_request *nfc_script;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_script_request));    
    newmsg->msg_type = msg_id;
    newmsg->msg_length = sizeof(nfc_script_request);

    nfc_script = (nfc_script_request *)((U8*)&(newmsg->msg_length) + 4);
    nfc_script->type = 1;
    nfc_script->action = 1;    
    mmi_fm_nfc_req(newmsg);
    mmi_fm_nfc_show_progress(STR_ID_FM_NFC_TESTING, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_genaral_rsp
 * DESCRIPTION
 *  mmi_fm_nfc_genaral_rsp
 * PARAMETERS
 *  rsp     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_genaral_rsp(nfc_script_response *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == MTK_NFC_SUCCESS)
    {
        /*success*/
        mmi_popup_display_ext(STR_ID_FM_NFC_PASS, MMI_EVENT_SUCCESS,  NULL);
    }
    else
    {
        mmi_popup_display_ext(STR_ID_FM_NFC_FAILED, MMI_EVENT_FAILURE, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_tag_uid_rw_req
 * DESCRIPTION
 *  mmi_fm_nfc_tag_uid_rw_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_tag_uid_rw_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_script_uid_request *uid_script;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_script_uid_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_UID_RW_REQ;
    newmsg->msg_length = sizeof(nfc_script_uid_request);

    uid_script = (nfc_script_uid_request *)((U8*)&(newmsg->msg_length) + 4);   
    uid_script->type = 1;
    uid_script->action = 1;
    uid_script ->uid_length = 0;
    uid_script->data[0] = 0;
    mmi_fm_nfc_req(newmsg);
    mmi_fm_nfc_show_progress(STR_ID_FM_NFC_TESTING, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_tag_uid_rw_rsp
 * DESCRIPTION
 *  mmi_fm_nfc_tag_uid_rw_rsp
 * PARAMETERS
 *  rsp         [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_tag_uid_rw_rsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_uid_response * uid_rsp = (nfc_script_uid_response *)rsp;
    U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FM_NFC_TRACE_2(MMI_FM_NFC_TRC_TAG_UID_RSP, uid_rsp->result, uid_rsp->uid_length);
    if (uid_rsp->result == MTK_NFC_SUCCESS)
    {
        /*success*/
        memset(g_fm_nfc_p->buf, 0, sizeof(g_fm_nfc_p->buf));
        g_fm_nfc_p->buf[0] = '0';
        g_fm_nfc_p->buf[1] = 'X';
        
        for ( i = 0; i < uid_rsp->uid_length && i < MAX_UID_DATA_LEN; i++)
        {
            mmi_fm_nfc_int_to_hex_string(g_fm_nfc_p->buf + 2 + i * MMI_FM_NFC_UID_ELEMENT_LEN, 
                                        MMI_FM_NFC_UID_ELEMENT_LEN, 
                                        uid_rsp->data[i]);
        }
        mmi_frm_scrn_create(GRP_ID_FM_NFC,
                                SCR_ID_FM_NFC_SHOW_UID,
                                mmi_fm_nfc_tag_uid_show_scrn_proc,
                                g_fm_nfc_p);
    }
    else
    {
        mmi_popup_display_ext(STR_ID_FM_NFC_FAILED, MMI_EVENT_FAILURE,  NULL);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_stop_req
 * DESCRIPTION
 *  tell MOD_NFC_APP to Stop Test
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct));    
    newmsg->msg_type = MSG_ID_NFC_STOP_TEST_REQ;
    newmsg->msg_length = 0;
    mmi_fm_nfc_req(newmsg);
    mmi_frm_scrn_close(GRP_ID_FM_NFC,SCR_ID_FM_NFC_SHOW_PROGRESS);
    mmi_fm_nfc_show_progress(STR_ID_FM_NFC_STOPING, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_int_to_hex_string
 * DESCRIPTION
 *  translate a int number to hex string
 * PARAMETERS
 *  buf   [IN]  where to save string
 *  len   [IN]  the length of buf, if buflen < string len, only save the buflen
 *  value [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_int_to_hex_string(WCHAR* buf, U32 len, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, temp;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i< len; i++)
    {
        temp = value % 16;
        if (temp < 10)
        {
            buf[len - i - 1] = temp + '0';    
        }
        else
        {
            buf[len - i - 1] = temp - 10 + 'A';
        }
        value /= 16; 
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_tag_uid_show_scrn_proc
 * DESCRIPTION
 *  show uid screen proc function
 * PARAMETERS
 *  param   [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_fm_nfc_tag_uid_show_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            nfc_script_uid_response *rsp = (nfc_script_uid_response *)param->user_data;
            mmi_frm_scrn_active_evt_struct *evt = (mmi_frm_scrn_active_evt_struct *)param;
            ShowCategory78Screen(STR_ID_FM_NFC_TAG_UID_RW, 
                                    0,
                                    0,
                                    0,
                                    STR_GLOBAL_BACK,
                                    0,
                                    0,
                                    (U8*)g_fm_nfc_p->buf,
                                    (S32)UID_DATA_LEN * 5,
                                    evt->gui_buffer);
            break;
        }

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:

            break;
        default:
            break;
    }
    return MMI_RET_OK;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_req
 * DESCRIPTION
 *  send nfc request to MOD_NFC_APP
 * PARAMETERS
 *  newmsg   [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_req(nfc_msg_struct * newmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FM_NFC_TRACE_1(MMI_FM_NFC_TRC_REQ, newmsg->msg_type);
	mmi_frm_send_ilm(MOD_NFC, MSG_ID_NFC_TEST_REQ, (oslParaType*)newmsg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_card_mode
 * DESCRIPTION
 *  entry nfc card mode test
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static void mmi_fm_nfc_card_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID inline_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(GRP_ID_FM_NFC,
                                            GRP_ID_AUTO_GEN,
                                            mmi_fm_nfc_card_mode_inline_proc,
                                            0,
                                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(group_id, &g_mmi_em_nfc_se_scrn);
    cui_inline_run(inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_card_mode_inline_proc
 * DESCRIPTION
 *  nfc card mode inline cui proc
 * PARAMETERS
 *  param
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_fm_nfc_card_mode_inline_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct *evt = (cui_event_inline_common_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(evt->sender_id);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            U32 opt = 0;
            cui_inline_get_value(evt->sender_id, MMI_FM_NFC_INLINE_SEL, &opt);
            mmi_fm_nfc_card_mode_req(opt + 1);
            cui_inline_close(evt->sender_id);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_card_mode_req
 * DESCRIPTION
 *  nfc card mode req
 * PARAMETERS
 *  opt [IN] 1 ->"SWP", 2 -> "NFC-WI"
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_card_mode_req(U32 opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_script_request *nfc_script;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_script_request));    
    newmsg->msg_type = MSG_ID_NFC_CARD_MODE_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_script_request);

    nfc_script = (nfc_script_request *)(newmsg + 1);
    nfc_script->type = opt;
    nfc_script->action = 1;    
    mmi_fm_nfc_req(newmsg);
    mmi_fm_nfc_show_progress(STR_ID_FM_NFC_TESTING, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_rd_atenna_req
 * DESCRIPTION
 *  nfc atenna request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_rd_atenna_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_antenna_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_antenna_request));    
    newmsg->msg_type = MSG_ID_NFC_ANTENNA_SELF_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_antenna_request);

    req = (nfc_antenna_request *)((newmsg + 1));
    req->action = 1;    
    mmi_fm_nfc_req(newmsg);
    mmi_fm_nfc_show_progress(STR_ID_FM_NFC_TESTING, MMI_FALSE);    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_rsp
 * DESCRIPTION
 *  nfc response handler
 * PARAMETERS
 *  param   [IN]         
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_fm_nfc_rsp(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *rsp = (nfc_msg_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (rsp)
    {
        MMI_FM_NFC_TRACE_2(MMI_FM_NFC_TRC_RSP, MMI_TRUE, rsp->msg_type);
		switch (rsp->msg_type)
		{
            case MSG_ID_NFC_P2P_MODE_TEST_RSP:
			case MSG_ID_NFC_SWP_SELF_TEST_RSP:
			case MSG_ID_NFC_ANTENNA_SELF_TEST_RSP:
            case MSG_ID_NFC_CARD_MODE_TEST_RSP:
				mmi_fm_nfc_genaral_rsp((nfc_script_response *)(rsp + 1));
                mmi_frm_scrn_close(GRP_ID_FM_NFC,SCR_ID_FM_NFC_SHOW_PROGRESS);
				break;

			case MSG_ID_NFC_TAG_UID_RW_RSP:
				mmi_fm_nfc_tag_uid_rw_rsp((nfc_script_uid_response*)(rsp+1));
                mmi_frm_scrn_close(GRP_ID_FM_NFC,SCR_ID_FM_NFC_SHOW_PROGRESS);
				break;

            case MSG_ID_NFC_STOP_TEST_RSP:
                mmi_frm_scrn_close(GRP_ID_FM_NFC,SCR_ID_FM_NFC_SHOW_PROGRESS);
                break;

			default:
				break;
		}		
    }
    else
    {
        MMI_FM_NFC_TRACE_1(MMI_FM_NFC_TRC_RSP, MMI_FALSE);
		mmi_popup_display_ext(STR_ID_FM_NFC_FAILED, MMI_EVENT_FAILURE, NULL);
    }    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_nfc_exit_fm_req
 * DESCRIPTION
 *  when fm nfc exit, send exit message to NFC driver
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_nfc_exit_fm_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_exit_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_exit_request));    
    newmsg->msg_type = MSG_ID_NFC_EXIT_EMFM;
    newmsg->msg_length = sizeof(nfc_exit_request);

    req = (nfc_exit_request *)((newmsg + 1));
    req->type = 2;
    mmi_fm_nfc_req(newmsg);
}

#endif /*__MMI_FM_NFC_SUPPORT__*/
#endif  /* __MMI_FACTORY_MODE__ */
