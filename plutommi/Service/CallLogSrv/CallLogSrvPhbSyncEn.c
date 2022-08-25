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
*  CallLogSrvStoreEn.c
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
 * -------
*                      
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
*
*
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
#include "mmi_include.h"


#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "ps_public_enum.h"

#include "custom_voip_config.h"
#include "custom_phb_config.h"
#include "custom_calllog.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#include "l4c2phb_enums.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"

#include "PhbSrvGprot.h"
#include "UcmSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_PHB_NUMBER_MAX_NUM                         (MMI_PHB_OPT_NUM_COUNT + 1)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CLOG_JOB_UPD_PHB_STATE_INIT,
    SRV_CLOG_JOB_UPD_PHB_STATE_UPDATING,
    SRV_CLOG_JOB_UPD_PHB_STATE_MAX_ITEM
} srv_clog_job_upd_phb_state_enum;

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    U8 field;
    U16 type;
} srv_clog_phb_num_type_struct;

typedef struct
{
    MMI_BOOL cid_changed;
    SRV_PHB_ID phb_id;
    WCHAR *cid;
} srv_clog_phb_num_struct;

typedef struct
{
    U16 dirty_num;
    U8 check_name;
    U8 changed_cid_num;
    U8 name_changed;
    U8 max_cid_num;
    WCHAR name[SRV_CLOG_NAME_MAX_LEN + 1];
    srv_clog_phb_num_struct num_tbl[SRV_CLOG_PHB_NUMBER_MAX_NUM];
    srv_phb_op_evt_struct *evt;
    U16 si_tbl_idx;
    U16 si_tbl_idx_min;
    SRV_PHB_ID invalid_phb_id;
} srv_clog_phb_para_struct;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifdef __SRV_CLOG_DUMP__
static void srv_clog_phb_set_dump_value(srv_clog_phb_para_struct *para);
#endif 

static S32 srv_clog_phb_is_sync_sup(U16 evt_id);
static void srv_clog_phb_handle_evt(srv_phb_op_evt_struct *evt);
static S32 srv_clog_phb_submit_phb_evt_job(srv_phb_op_evt_struct *evt);

static void srv_clog_phb_init_para(srv_clog_phb_para_struct *para);
static void srv_clog_phb_get_num_tbl(srv_clog_phb_para_struct *para, srv_phb_op_evt_struct *evt);
static S32 srv_clog_phb_is_cid_care(WCHAR *cid, U16 evt_id);

static void srv_clog_phb_handle_add(srv_clog_phb_para_struct *para);
static void srv_clog_phb_handle_delete(srv_clog_phb_para_struct *para);
static void srv_clog_phb_handle_update(srv_clog_phb_para_struct *para);

static void srv_clog_phb_update_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log);
static void srv_clog_phb_update_free_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log);
static void srv_clog_phb_update_owned_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log);
static void srv_clog_phb_update_match(srv_clog_phb_para_struct *para,srv_clog_si_struct *si_log,U32 fields,SRV_PHB_ID phb_id,MMI_BOOL changed);
static void srv_clog_phb_notify(U32 fields, srv_clog_si_struct *si_log);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifdef __SRV_CLOG_DUMP__
static srv_clog_phb_para_struct *g_srv_clog_phb_para;
#endif /* __SRV_CLOG_DUMP__ */

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_PHB_FUNC_DEFINITION

#ifdef __SRV_CLOG_DUMP__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_set_dump_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_set_dump_value(srv_clog_phb_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_clog_phb_para = para;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_dump
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_dump(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_PHB_PARA_DUMP))
        return;

    if (!srv_clog_cntx_p || !srv_clog_is_init() || !g_srv_clog_phb_para || !g_srv_clog_phb_para->evt)
        return;

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP, 0);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP, "\n[CLogSrv]srv_clog_phb_dump(%d):-->"), 0));

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_PHB_DUMP_PARA,
        g_srv_clog_phb_para->check_name,
        g_srv_clog_phb_para->name_changed,
        g_srv_clog_phb_para->max_cid_num,
        g_srv_clog_phb_para->changed_cid_num,
        g_srv_clog_phb_para->dirty_num,
        g_srv_clog_phb_para->si_tbl_idx,
        g_srv_clog_phb_para->evt->store_index);
    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_PARA,
                   "[CLogSrv]check_name=%d,name_changed=%d,max_cid_num=%d,changed_cid_num=%d,dirty_num=%d,cur_sit_idx=%d,store_index=%d"),
                  g_srv_clog_phb_para->check_name, g_srv_clog_phb_para->name_changed, g_srv_clog_phb_para->max_cid_num,
                  g_srv_clog_phb_para->changed_cid_num, g_srv_clog_phb_para->dirty_num, g_srv_clog_phb_para->si_tbl_idx,
                  g_srv_clog_phb_para->evt->store_index));

    {
        CHAR asc_name[SRV_CLOG_NAME_MAX_LEN + 1] = {0};

        if (!SRV_CLOG_IS_STR_EMPTY(g_srv_clog_phb_para->name))
        {
            if (srv_clog_is_ascii_string(g_srv_clog_phb_para->name))
                mmi_wcs_n_to_asc((CHAR*) asc_name, (WCHAR*) g_srv_clog_phb_para->name, SRV_CLOG_NAME_MAX_LEN * ENCODING_LENGTH);
            else
                memcpy(asc_name, "ucs-name", sizeof("ucs-name"));
        }

        MMI_PRINT(MOD_MMI_COMMON_APP, SRV_CLOG_TRC_INFO, "[CLogSrv]srv_clog_phb_dump(name=%s)", asc_name);
        SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_NAME, "[CLogSrv]srv_clog_phb_dump(name=%s)"),
                      asc_name));

    }
    for (i = 0; i < SRV_CLOG_PHB_NUMBER_MAX_NUM; i++)
    {
        srv_clog_phb_dump_num(i);
    }

    SRV_CLOG_DUMP_LOG(
        g_srv_clog_phb_para->si_tbl_idx,
        srv_clog_si_tbl_index(srv_clog_cntx_p->comp->si_tbl, g_srv_clog_phb_para->si_tbl_idx));

    srv_clog_phb_dump_evt();

    MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP, 1);
    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP, "[CLogSrv]zhpb_dump(%d):-->"), 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_dump_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_dump_num(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_phb_num_struct *num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_PHB_PARA_DUMP))
        return;

    if (!g_srv_clog_phb_para)
        return;

    num = &g_srv_clog_phb_para->num_tbl[index];

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_PHB_DUMP_NUM_VALUE,
        index,
        num->phb_id,
        num->phb_id.storage_type,
        num->phb_id.number_index,
        num->phb_id.contact_index,
        num->cid_changed);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_NUM_VALUE,
                   "[CLogSrv]srv_clog_phb_dump_num(%d)--> pid=0x%x(%d:%d:%d),cid_changed=%d"), index, num->phb_id,
                  num->phb_id.storage_type, num->phb_id.number_index, num->phb_id.contact_index, num->cid_changed));

    {
        CHAR asc_cid[SRV_CLOG_CID_MAX_LEN + 1] = {0};

        if (!SRV_CLOG_IS_STR_EMPTY(num->cid))
            mmi_wcs_n_to_asc((CHAR*) asc_cid, num->cid, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);

        MMI_PRINT(
            MOD_MMI_COMMON_APP,
            SRV_CLOG_TRC_INFO,
            "[CLogSrv]srv_clog_phb_dump_num(%d)--> cid=%s",
            index,
            asc_cid);
        SRV_CLOG_TRC((SRV_CLOG_TS
                      (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_NUM_ALL,
                       "[CLogSrv]srv_clog_phb_dump_num(%d)--> cid=%s"), index, asc_cid));
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_dump_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_dump_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	WCHAR* name;
    srv_phb_number_struct *num;
    WCHAR asc_name[SRV_CLOG_NAME_MAX_LEN + 1] = {0};
    WCHAR asc_cid[SRV_CLOG_CID_MAX_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CLOG_CHECK_BIT(srv_clog_get_debug_mode(), SRV_CLOG_DEBUG_MODE_PHB_PARA_DUMP))
        return;

    if (!g_srv_clog_phb_para || !g_srv_clog_phb_para->evt || !g_srv_clog_phb_para->evt->contact)
        return;

    MMI_TRACE(
        SRV_CLOG_TRC_INFO,
        TRC_SRV_CLOG_PHB_DUMP_EVT_VALUE,
        g_srv_clog_phb_para->evt->evt_id,
        EVT_ID_PHB_ADD_CONTACT, 
        EVT_ID_PHB_UPD_CONTACT,
        EVT_ID_PHB_DEL_CONTACT,
        g_srv_clog_phb_para->evt->store_index,
        g_srv_clog_phb_para->evt->update_field,
        SRV_PHB_ENTRY_FIELD_NUMBER);

    SRV_CLOG_TRC((SRV_CLOG_TS(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_EVT_VALUE,
                              "[CLogSrv]srv_clog_phb_dump_evt(%d[a/u/d:%d-%d-%d])->store_idx=%d,fields_mask=0x%x,field=0x%x"),
                  g_srv_clog_phb_para->evt->evt_id, 
                  EVT_ID_PHB_ADD_CONTACT, 
                  EVT_ID_PHB_UPD_CONTACT,
                  EVT_ID_PHB_DEL_CONTACT,
                  g_srv_clog_phb_para->evt->store_index, g_srv_clog_phb_para->evt->update_field,
                  SRV_PHB_ENTRY_FIELD_NUMBER));

    name = srv_phb_contact_get_name(g_srv_clog_phb_para->evt->contact);
    if (!SRV_CLOG_IS_STR_EMPTY(name))
    {
        if (srv_clog_is_ascii_string(name))
            mmi_wcs_n_to_asc((CHAR*) asc_name, name, SRV_CLOG_NAME_MAX_LEN * ENCODING_LENGTH);
        else
            memcpy(asc_name, "ucs-name", sizeof("ucs-name"));
    }
	num = srv_phb_contact_get_number_by_save_index(g_srv_clog_phb_para->evt->contact, 0);
    if (num && num->number[0])
    {
        mmi_wcs_n_to_asc((CHAR*) asc_cid, num->number, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);
    }

    MMI_PRINT(
        MOD_MMI_COMMON_APP,
        SRV_CLOG_TRC_INFO,
        "[z]srv_clog_phb_dump_evt(Mobile: name=%s,cid=%s)",
        asc_name,
        asc_cid);

    SRV_CLOG_TRC((SRV_CLOG_TS
                  (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_EVT_MOBILE_NAME_CID,
                   "[z]srv_clog_phb_dump_evt(Mobile: name=%s,cid=%s)"), asc_name, asc_cid));
    
    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        num = srv_phb_contact_get_number_by_save_index(g_srv_clog_phb_para->evt->contact, i);
        if (num && num->number[0])
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_PHB_DUMP_EVT_OPT_INFO,
                i,
                num->type,
                0);
            
            SRV_CLOG_TRC((SRV_CLOG_TS
                          (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_EVT_OPT_INFO,
                           "[CLogSrv]idx=%d,type=%d,field=0x%x"), i, num->type, 0));
            
            mmi_wcs_n_to_asc((CHAR*) asc_cid, num->number, SRV_CLOG_CID_MAX_LEN * ENCODING_LENGTH);
            
            MMI_PRINT(MOD_MMI_COMMON_APP, SRV_CLOG_TRC_INFO, "[CLogSrv]srv_clog_phb_dump_evt(OP: cid=%s)", asc_cid);
            SRV_CLOG_TRC((SRV_CLOG_TS
                          (SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_DUMP_EVT_OPT_INFO_CID,
                           "[CLogSrv]srv_clog_phb_dump_evt(OP: cid=%s)"), asc_cid));


        }
    }
}

#endif /* __SRV_CLOG_DUMP__ */ 

#define SRV_CLOG_PHB_EVT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_sync_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET srv_clog_phb_sync_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *phb_evt = (srv_phb_op_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clog_is_init())
        return MMI_RET_OK;

    if (!srv_clog_phb_is_sync_sup(evt->evt_id))
        return MMI_RET_OK;

    if (!srv_clog_is_ready())
        return MMI_RET_OK;

    srv_clog_phb_handle_evt(phb_evt);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_is_sync_sup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]         
 *  evt_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_phb_is_sync_sup(U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 is_sup = MMI_FALSE;
    U32 sync_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(srv_clog_cntx_p->comp->style_mgr, SRV_CLOG_STYLE_TYPE_PHB_SYNC, &sync_style, NULL);
    if (!sync_style)
        return MMI_FALSE;

    switch (evt_id)
    {
        case EVT_ID_PHB_ADD_CONTACT:
            if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_PHB_SYNC_ADD))
                is_sup = MMI_TRUE;
            break;

        case EVT_ID_PHB_DEL_CONTACT:
            if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_PHB_SYNC_DELETE))
                is_sup = MMI_TRUE;
            break;

        case EVT_ID_PHB_UPD_CONTACT:
            if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_PHB_SYNC_UPDATE))
                is_sup = MMI_TRUE;
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }
    return is_sup;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_handle_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_handle_evt(srv_phb_op_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_phb_para_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_phb_init_para(&para);
    srv_clog_phb_get_num_tbl(&para, evt);

#ifdef __SRV_CLOG_DUMP__
    srv_clog_phb_set_dump_value(&para);
#endif

    SRV_CLOG_DUMP(SRV_CLOG_DUMP_TYPE_PHB_SYNC | SRV_CLOG_DUMP_TYPE_SI_IDX);

    if (para.max_cid_num == 0 && !para.name_changed)
    {
    #ifdef __SRV_CLOG_DUMP__
        srv_clog_phb_set_dump_value(NULL);
    #endif 
        return;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_PHB_ADD_CONTACT:
            srv_clog_phb_handle_add(&para);
            break;

        case EVT_ID_PHB_DEL_CONTACT:
            srv_clog_phb_handle_delete(&para);
            break;

        case EVT_ID_PHB_UPD_CONTACT:
            srv_clog_phb_handle_update(&para);
            break;

        default:
            SRV_CLOG_ASSERT(0);
            break;
    }

    if (para.dirty_num == 0)
    {
    #ifdef __SRV_CLOG_DUMP__
        srv_clog_phb_set_dump_value(NULL);
    #endif 
        return;
    }

    srv_clog_si_flash(srv_clog_cntx_p->comp->si_tbl, para.si_tbl_idx_min, para.si_tbl_idx);

#ifdef __SRV_CLOG_DUMP__
    srv_clog_phb_set_dump_value(NULL);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_submit_phb_evt_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_phb_submit_phb_evt_job(srv_phb_op_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to do */
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_init_para(srv_clog_phb_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(para, 0x0, sizeof(srv_clog_phb_para_struct));
    para->si_tbl_idx = 0;
    para->si_tbl_idx_min = SRV_CLOG_LOG_MAX_NUM;
    for (i = 0; i < SRV_CLOG_PHB_NUMBER_MAX_NUM; i++)
    {
        SRV_CLOG_SET_INVALID_PHB_ID(para->num_tbl[i].phb_id);
    }
    SRV_CLOG_SET_INVALID_PHB_ID(para->invalid_phb_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_get_num_tbl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 *  evt         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_get_num_tbl(srv_clog_phb_para_struct *para, srv_phb_op_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j = 0;
    srv_phb_number_struct* number;

    static const U8 g_srv_clog_phb_opt_num_field_tbl[] = 
    {
        SRV_PHB_ENTRY_FIELD_NUMBER,
        SRV_PHB_ENTRY_FIELD_OPT_NUM_1,
        SRV_PHB_ENTRY_FIELD_OPT_NUM_2,
        SRV_PHB_ENTRY_FIELD_OPT_NUM_3
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For delete event, only need store_index now */
    if (evt->evt_id == EVT_ID_PHB_DEL_CONTACT)
    {
        para->evt = evt;
        para->name_changed = MMI_TRUE;
        return;
    }

    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        number = srv_phb_contact_get_number_by_save_index(evt->contact, i);
        if (SRV_CLOG_CHECK_BIT(evt->update_field, MMI_PHB_CONTACT_FIELD_NUMBER))
        {
            if (number && srv_clog_phb_is_cid_care(number->number, evt->evt_id))
            {
                CHAR ascii_cid[SRV_CLOG_CID_MAX_LEN + 1];
                mmi_wcs_to_asc(ascii_cid, number->number);
                if(srv_ucm_is_emergency_number(SRV_UCM_CALL_TYPE_ALL, (U8 *)ascii_cid))
                    continue; /* can't sync ECC log with Contact, it is UX defined*/
                
                para->num_tbl[j].cid_changed = MMI_TRUE;
                para->num_tbl[j].cid = number->number;
                para->num_tbl[j].phb_id = srv_phb_create_number_id(
                                                 PHB_PHONEBOOK,
                                                 evt->id,
                                                 g_srv_clog_phb_opt_num_field_tbl[i]);
                j++;
            }
        }
    }

    para->max_cid_num = j;
    para->changed_cid_num = j;
    para->evt = evt;
    if (para->max_cid_num > 0 && SRV_CLOG_CHECK_BIT(evt->update_field, MMI_PHB_CONTACT_FIELD_NAME))
    {
        /* get name if find cared number and has name field */
        srv_phb_get_name(evt->id, para->name, SRV_CLOG_NAME_MAX_LEN);
        para->name_changed = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_is_cid_care
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid         [?]         
 *  evt_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_clog_phb_is_cid_care(WCHAR *cid, U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CLOG_IS_STR_EMPTY(cid) && (evt_id == EVT_ID_PHB_ADD_CONTACT || evt_id == EVT_ID_PHB_DEL_CONTACT))
        return MMI_FALSE;
    return MMI_TRUE;
}


#define SRV_CLOG_PHB_ACT


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_handle_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_handle_add(srv_clog_phb_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 count;
    U32 total_num;
    srv_clog_si_struct *si_log;
    SRV_PHB_ID phb_id;
    SRV_PHB_ID invalid_phb_id;
    srv_clog_phb_num_struct *num_tbl;
    U16 store_index;
    srv_clog_si_tbl_struct *si_tbl;
    kal_uint8 call_number[SRV_CLOG_CID_MAX_LEN + 1];
    WCHAR cur_w_cid[SRV_CLOG_CID_MAX_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    si_tbl = srv_clog_cntx_p->comp->si_tbl;
    total_num = srv_clog_si_tbl_total_num(si_tbl);
    num_tbl = para->num_tbl;
    store_index = para->evt->store_index;
    SRV_CLOG_SET_INVALID_PHB_ID(invalid_phb_id);

    for (i = 0, count = 0; i < SRV_CLOG_LOG_MAX_NUM && count < total_num; i++)
    {
        si_log = srv_clog_si_tbl_index(si_tbl, i);
        if (!srv_clog_si_log_is_valid(si_log))
            continue;
        count++;
        para->si_tbl_idx = i;
        para->si_tbl_idx_min = para->si_tbl_idx_min>i?i:para->si_tbl_idx_min;

        phb_id = SRV_CLOG_SILOG_GET_PHB_ID(si_log);
        if (SRV_CLOG_IS_PHB_ID_VALID(phb_id))
        {
            /* The PHB id should be a new one, only check first now */
            //    SRV_CLOG_ASSERT(!SRV_CLOG_IS_SAME_PHB_ID(phb_id, num_tbl[0].phb_id));

            /* If PHB_id is same, it means the related phb number should be damaged abnormally, such as may be deleted 
                    by test tool or in another phone before back to this target, in these case, calllog is not notified,
                    here to clear the phb_id to remove the improper link relation as an temp error handling */
            if (SRV_CLOG_IS_SAME_PHB_ID(phb_id, num_tbl[0].phb_id))
            {
                MMI_TRACE(
                        SRV_CLOG_TRC_INFO,
                        TRC_SRV_CLOG_PHB_HANDLE_ADD_ABNORMAL_PHB_ID,
                        i,
                        SRV_CLOG_SILOG_GET_LOG_ID(si_log),
                        SRV_CLOG_SILOG_GET_TYPE_ID(si_log),
                        phb_id,
                        para->changed_cid_num,
                        para->name_changed);

                SRV_CLOG_DUMP_LOG(i, si_log);

                srv_clog_phb_update_match(
                    para,
                    si_log,
                    SRV_CLOG_LOG_FIELD_PHB_ID,
                    invalid_phb_id,
                    MMI_TRUE);
            }            
            continue;
        }
        
        /* Find a log without PHB ID, check if matched */

        srv_clog_si_log_get_cid(si_log, call_number, SRV_CLOG_CID_MAX_LEN);
        if (SRV_CLOG_IS_STR_EMPTY(call_number))
            continue;

        mmi_asc_n_to_ucs2((CHAR*) cur_w_cid, call_number, SRV_CLOG_CID_MAX_LEN);
        for (j = 0; j < para->max_cid_num; j++)
        {
            if (MMI_FALSE == srv_phb_compare_number(num_tbl[j].cid, cur_w_cid))
                continue;
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_PHB_HANDLE_ADD,
                j,
                phb_id,
                store_index,
                i,
                SRV_CLOG_SILOG_GET_TYPE_ID(si_log));

            srv_clog_phb_update_match(
                para,
                si_log,
                SRV_CLOG_LOG_FIELD_PHB_ID,
                num_tbl[j].phb_id,
                MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_handle_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_handle_delete(srv_clog_phb_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 count;
    U32 total_num;
    srv_clog_si_struct *si_log;
    SRV_PHB_ID phb_id;
    U16 store_index;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = srv_clog_si_tbl_total_num(si_tbl);
    store_index = para->evt->store_index;

    for (i = 0, count = 0; i < SRV_CLOG_LOG_MAX_NUM && count < total_num; i++)
    {
        si_log = srv_clog_si_tbl_index(si_tbl, i);
        if (!srv_clog_si_log_is_valid(si_log))
            continue;

        count++;
        para->si_tbl_idx = i;
        para->si_tbl_idx_min = para->si_tbl_idx_min>i?i:para->si_tbl_idx_min;

        phb_id = SRV_CLOG_SILOG_GET_PHB_ID(si_log);

        /* check if store_index matched, if so, should break the link as this PHB entry is deleted */
        if (SRV_CLOG_PHB_ID2IDX(phb_id) != store_index)
            continue;
        /* Please note: phb_id is already invalid now as the number related with it already be deleted,
           but the store index is valid and still can still tell use which store_index is deleted */
        MMI_TRACE(SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_PHB_HANDLE_DELETE, i, phb_id, SRV_CLOG_SILOG_GET_TYPE_ID(si_log));

        srv_clog_phb_update_match(
            para,
            si_log,
            SRV_CLOG_LOG_FIELD_PHB_ID,
            para->invalid_phb_id,
            MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_handle_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [?]     
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_phb_handle_update(srv_clog_phb_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 total_num;
    srv_clog_si_struct *si_log;
    srv_clog_si_tbl_struct *si_tbl = srv_clog_cntx_p->comp->si_tbl;
    CHAR i_cid[SRV_CLOG_CID_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = srv_clog_si_tbl_total_num(si_tbl);

    for (i = 0, j = 0; i < SRV_CLOG_LOG_MAX_NUM && j < total_num; i++)
    {
        si_log = srv_clog_si_tbl_index(si_tbl, i);
        if (!srv_clog_si_log_is_valid(si_log))
            continue;
        j++;

        srv_clog_si_log_get_cid(si_log, i_cid, SRV_CLOG_CID_MAX_LEN);

        if (SRV_CLOG_IS_STR_EMPTY(i_cid))
            continue;

        para->si_tbl_idx = i;
        para->si_tbl_idx_min = para->si_tbl_idx_min>i?i:para->si_tbl_idx_min;

        srv_clog_phb_update_log(para, si_log);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_update_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 *  si_log      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_update_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID phb_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_id = SRV_CLOG_SILOG_GET_PHB_ID(si_log);
    if (!SRV_CLOG_IS_PHB_ID_VALID(phb_id))
        srv_clog_phb_update_free_log(para, si_log);
    else
        srv_clog_phb_update_owned_log(para, si_log);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_update_free_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 *  si_log      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_update_free_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    CHAR i_cid[SRV_CLOG_CID_MAX_LEN + 1];
    WCHAR w_cid[SRV_CLOG_CID_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * check if phb_id is invalid just because of the related number is deleted
     * Please note: phb_id is already invalid now as the number related with it already be deleted,
     * but the store index is valid and still can still tell use which store_index is deleted
     */
    if (SRV_CLOG_PHB_ID2IDX(SRV_CLOG_SILOG_GET_PHB_ID(si_log)) == para->evt->store_index)
    {
        srv_clog_phb_update_match(
            para,
            si_log,
            SRV_CLOG_LOG_FIELD_PHB_ID,
            para->invalid_phb_id,
            MMI_TRUE);
        return;
    }

    srv_clog_si_log_get_cid(si_log, i_cid, SRV_CLOG_CID_MAX_LEN);
    mmi_asc_n_to_wcs(w_cid, i_cid, SRV_CLOG_CID_MAX_LEN);

    for (i = 0; i < para->max_cid_num; i++)
    {
        ret = srv_phb_compare_number(w_cid, para->num_tbl[i].cid);
        if (!ret)
            continue;
        srv_clog_phb_update_match(
            para,
            si_log,
            SRV_CLOG_LOG_FIELD_PHB_ID,
            para->num_tbl[i].phb_id,
            MMI_TRUE);
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_update_owned_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 *  si_log      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_update_owned_log(srv_clog_phb_para_struct *para, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    S32 ret;
    MMI_BOOL phb_id_changed = MMI_FALSE;
    CHAR i_cid[SRV_CLOG_CID_MAX_LEN + 1];
    WCHAR w_cid[SRV_CLOG_CID_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if store index matched */
    if (SRV_CLOG_PHB_ID2IDX(SRV_CLOG_SILOG_GET_PHB_ID(si_log)) != para->evt->store_index)
        return;

    srv_clog_si_log_get_cid(si_log, i_cid, SRV_CLOG_CID_MAX_LEN);
    mmi_asc_n_to_wcs(w_cid, i_cid, SRV_CLOG_CID_MAX_LEN);

    for (i = 0; i < para->max_cid_num; i++)
    {
        /* Check if phb_id is matched */
        if (!SRV_CLOG_IS_SAME_PHB_ID(SRV_CLOG_SILOG_GET_PHB_ID(si_log), para->num_tbl[i].phb_id))
            continue;

        /* check if checked and not changed when matching some previous logs */
        if (!para->num_tbl[i].cid_changed)
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_PHB_UPDATE_OWNED_LOG_UPDATE_NAME_ONLY,
                i,
                para->num_tbl[i].phb_id,
                para->changed_cid_num,
                para->name_changed,
                SRV_CLOG_SILOG_GET_PHB_ID(si_log));
            phb_id_changed = MMI_TRUE;
            break;
        }

        /* check if number changed */
        ret = srv_phb_number_id_check_modify(
                w_cid,
                SRV_CLOG_SILOG_GET_PHB_ID(si_log),
                para->evt->id,
                para->evt->contact);
        /* number is not changed, just to check name only */
        if (!ret)
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_PHB_UPDATE_OWNED_LOG_UPDATE_SAME_CID,
                i,
                para->num_tbl[i].phb_id,
                para->changed_cid_num,
                para->name_changed,
                SRV_CLOG_SILOG_GET_PHB_ID(si_log));

            para->num_tbl[i].cid_changed = MMI_FALSE;
            para->changed_cid_num--;
            break;
        }

        /* Number is changed, should remove current PHB_ID and try to link another one of this PHB entry */
        for (j = 0; j < para->max_cid_num; j++)
        {
            if (j == i) /* skip current one */
                continue;

            ret = srv_phb_compare_number(w_cid, para->num_tbl[j].cid);
            if (!ret)
                continue;

            /* find a matched phb_id, link to it */
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_PHB_UPDATE_OWNED_LOG_UPDATE_NAME_CID,
                i,
                j,
                para->num_tbl[i].phb_id,
                para->changed_cid_num,
                para->name_changed,
                SRV_CLOG_SILOG_GET_PHB_ID(si_log));

            phb_id_changed = MMI_TRUE;
            break;
        }

        break;
    }

    srv_clog_phb_update_match(
                para,
                si_log,
                SRV_CLOG_LOG_FIELD_PHB_ID,
                para->invalid_phb_id,
                phb_id_changed);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_update_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 *  si_log      [?]     
 *  fields      [IN]        
 *  phb_id      [IN]        
 *  name        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_update_match(
                srv_clog_phb_para_struct *para,
                srv_clog_si_struct *si_log,
                U32 fields,
                SRV_PHB_ID phb_id,
                MMI_BOOL changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(changed)
    {
        srv_clog_si_update_phb_info(si_log, fields, phb_id, NULL);
        para->dirty_num++;
    }

    srv_clog_phb_notify(fields, si_log);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_phb_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]         
 *  fields      [IN]        
 *  si_log      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_phb_notify(U32 fields, srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_emit_update_log_event(fields, si_log);

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
    srv_clog_at_notify_update(SRV_CLOG_AT_UPDATE_UPD, srv_clog_cntx_p, SRV_CLOG_SILOG_GET_TYPE_ID(si_log), NULL, si_log);
#endif

}
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */



