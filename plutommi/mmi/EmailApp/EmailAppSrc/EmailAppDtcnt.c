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
 *  EmailAppNetwork.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email memory management functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "Mmi_frm_mem_gprot.h"
#include "Mmi_cb_mgr_gprot.h"

#include "cbm_consts.h"
#include "cbm_api.h"
#include "DtcntSrvGprot.h"
#include "DataAccountGProt.h"
#include "SimCtrlSrvGprot.h"

#include "MMI_trc_Int.h" // MMI_TRACE
#include "mmi_inet_app_trc.h"
#include "emailsrvgprot.h"

#include "Unicodexdcl.h"
#include "CustDataRes.h"

#include "EmailAppLib.h"
#include "EmailAppDtcnt.h"
#include "EmailAppNetwork.h"

typedef struct 
{
    U16 str_id;
    U16 icon_id;
    EMAIL_ACCT_ID acct_id;
} email_app_appinfo_mapping_struct;

static
email_app_appinfo_mapping_struct
g_email_app_info_array[MMI_EMAIL_MAX_ACCTS * 2] =
{
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP1_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP2_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP3_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP4_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP5_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP6_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP7_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP8_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP9_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP10_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP11_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP12_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP13_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP14_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP15_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP16_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP17_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP18_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP19_ID, 0},
    {STR_GLOBAL_EMAIL, IMG_EMAIL_APP20_ID, 0}
};

static
MMI_BOOL 
mmi_email_datacct_get_app_info_srv(
    srv_email_app_info_query_struct *app_info_p,
    U16 *str_id,
    U16 *icon_id);

static void mmi_email_datacct_register_handler(void);
static S32 mmi_email_datacct_del_handler(mmi_event_struct* param);
static S32 mmi_email_datacct_upd_handler(mmi_event_struct* param);

static void mmi_email_dataacct_check(EMAIL_ACCT_ID acc_id);



/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dataaccount_init
 * DESCRIPTION 
 *  mmi email dataaccount init
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dataaccount_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    srv_email_result_enum srv_ret;
    EMAIL_ACCT_ID acct_id_array[MMI_EMAIL_MAX_ACCTS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATAACCOUNT_INIT, __LINE__);

    srv_ret = srv_email_acct_get_num((U32*)&count);
    if (srv_ret != SRV_EMAIL_RESULT_SUCC || count < 0)
    {
        count = 0;
    }

    if (count > 0)
    {
        srv_ret = srv_email_acct_get_acct_id(0, &count, acct_id_array);
        if (srv_ret != SRV_EMAIL_RESULT_SUCC)
        {
            count = 0;
        }
    }

    for (i = 0; i < count; i++)
    {
        g_email_app_info_array[i * 2].acct_id = acct_id_array[i];
        g_email_app_info_array[i * 2 + 1].acct_id = acct_id_array[i];

        /* Check data account vailidty */
        mmi_email_dataacct_check(acct_id_array[i]);
    }
    for (i = count; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        g_email_app_info_array[i * 2].acct_id = EMAIL_ACCT_INVALID_ID;
        g_email_app_info_array[i * 2 + 1].acct_id = EMAIL_ACCT_INVALID_ID;
    }

    mmi_email_datacct_register_handler();

    srv_email_register_app_id_query_callback(
        0,
        mmi_email_datacct_get_app_info_srv);
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dataaccount_deinit
 * DESCRIPTION 
 *  mmi email dataaccount deinit
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dataaccount_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATAACCOUNT_DEINIT, __LINE__);
    for (i = 0; i < MMI_EMAIL_MAX_ACCTS * 2; i++)
    {
        g_email_app_info_array[i].acct_id = 0;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dataaccount_map_add
 * DESCRIPTION 
 *  mmi email dataaccount map add
 * PARAMETERS 
 *  EMAIL_ACCT_ID id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dataaccount_map_add(EMAIL_ACCT_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATAACCOUNT_MAP_ADD, id);
    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_email_app_info_array[i * 2].acct_id == id)
        {
            g_email_app_info_array[i * 2].acct_id = id;
            g_email_app_info_array[i * 2 + 1].acct_id = id;
            return;
        }
    }

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_email_app_info_array[i * 2].acct_id == EMAIL_ACCT_INVALID_ID)
        {
            g_email_app_info_array[i * 2].acct_id = id;
            g_email_app_info_array[i * 2 + 1].acct_id = id;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dataaccount_map_del
 * DESCRIPTION 
 *  mmi email dataaccount map del
 * PARAMETERS 
 *  EMAIL_ACCT_ID id
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_dataaccount_map_del(EMAIL_ACCT_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATAACCOUNT_MAP_DEL, id);
    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_email_app_info_array[i * 2].acct_id == id)
        {
            g_email_app_info_array[i * 2].acct_id = EMAIL_ACCT_INVALID_ID;
            g_email_app_info_array[i * 2 + 1].acct_id = EMAIL_ACCT_INVALID_ID;
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dataacct_check
 * DESCRIPTION 
 *  mmi email dataacct check
 * PARAMETERS 
 *  EMAIL_ACCT_ID acc_id
 * RETURNS 
 *  static void 
*****************************************************************************/
static void mmi_email_dataacct_check(EMAIL_ACCT_ID acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 j;
    srv_email_result_enum result;
    EMAIL_ACCT_HANDLE acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    cbm_app_info_struct app_info = {0};
    srv_email_acct_info_struct *acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATAACCT_CHECK, acc_id);
    do
    {
        result = srv_email_acct_create(0, &acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC) break;

        result = srv_email_acct_open(acct_handle, acc_id);
        if (result != SRV_EMAIL_RESULT_SUCC) break;

        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC) break;

        result = srv_email_acct_get_permission(acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC) break;

        if (mmi_email_datacct_get_app_info(acc_id, MMI_TRUE, &(app_info.app_str_id), &(app_info.app_icon_id)))
        {
            MMI_BOOL acct_info_changed = MMI_FALSE;
            U8 app_id = 0;
            U32 nwk_data_account_id = 0;

            for (j = 0; j < MMI_SIM_TOTAL; j++)
            {
                app_info.app_type = DTCNT_APPTYPE_EMAIL;
                cbm_register_app_id_with_app_info(&app_info, &app_id);
                nwk_data_account_id = cbm_set_app_id(acct_info->in_server.data_acct[j], app_id);
                if (MMI_DTCNT_ACCT_VALID_NONE == mmi_dtcnt_acct_is_valid(nwk_data_account_id))
                {
                    acct_info->out_server.data_acct[j] = acct_info->in_server.data_acct[j] = 
                        cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)j, app_id, (kal_bool)FALSE);

                    acct_info_changed = MMI_TRUE;
                }
                cbm_deregister_app_id(app_id);
            }

            if (acct_info_changed)
            {
                srv_email_acct_edit(acct_handle, acct_info);
                result = srv_email_acct_save(acct_handle);
                if (result != SRV_EMAIL_RESULT_SUCC) break;
            }
        }
    }while(0);

    OslMfree(acct_info);

    if (acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acct_handle);
    }
}


MMI_BOOL mmi_email_datacct_get_app_info_srv(
                    srv_email_app_info_query_struct *app_info_p,
                    U16 *str_id,
                    U16 *icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct app_info;
    U8 app_id = CBM_INVALID_APP_ID;
    S8 ret = 0;
    U32 nwk_acct_id = 0;
    mmi_dtcnt_acct_valid_type_enum valid_type = MMI_DTCNT_ACCT_VALID_NONE;
    MMI_BOOL retval = MMI_FALSE;
    srv_dtcnt_sim_type_enum dtcnt_pre_sim = (srv_dtcnt_sim_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO_SRV, 0);

    retval = mmi_email_datacct_get_app_info(
                app_info_p->acct_id,
                app_info_p->is_incoming,
                &app_info.app_str_id,
                &app_info.app_icon_id);

    if (retval)
    {
        if(app_info_p->app_id == 0)
        {
            app_info.app_type = DTCNT_APPTYPE_EMAIL;
            ret = cbm_register_app_id_with_app_info(&app_info, &app_id);
            if (ret != CBM_OK)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO_SRV, -1);
                return MMI_FALSE;
            }

            nwk_acct_id = cbm_set_app_id(app_info_p->dataacct_id, app_id);
            valid_type = mmi_dtcnt_acct_is_valid(nwk_acct_id);

            if (valid_type == MMI_DTCNT_ACCT_VALID_NONE)
            {
                /* get prefer SIM whichu used by EMAIL SERVICE */
                srv_dtcnt_get_sim_preference(&dtcnt_pre_sim);

                /* Set to automatic */
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO_SRV, -2);
                app_info_p->dataacct_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)(dtcnt_pre_sim - 1), app_id, (kal_bool)FALSE);
            }

            nwk_acct_id = cbm_set_app_id(app_info_p->dataacct_id, app_id);
            valid_type = mmi_dtcnt_acct_is_valid(nwk_acct_id);

            cbm_deregister_app_id(app_id);
            if (valid_type == MMI_DTCNT_ACCT_VALID_NONE)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO_SRV, -3);
                return MMI_FALSE;
            }
        }

        *str_id = app_info.app_str_id;
        *icon_id = app_info.app_icon_id;
        /* *same = TRUE; */
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO_SRV, 4);
    return retval;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_datacct_get_app_info
 * DESCRIPTION 
 *  mmi email datacct get app info
 * PARAMETERS 
 *               EMAIL_ACCT_ID acct_id
 *  MMI_BOOL is_incoming
 *  U16 *str_id
 *  U16 *icon_id
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_email_datacct_get_app_info(
            EMAIL_ACCT_ID acct_id,
            MMI_BOOL is_incoming,
            U16 *str_id,
            U16 *icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO, 0);

    for (; index < MMI_EMAIL_MAX_ACCTS * 2; index += 2)
    {   // double for {receiving} & {sending}
        if (g_email_app_info_array[index].acct_id == acct_id)
        {
            if (is_incoming)
            {
                *str_id = g_email_app_info_array[index].str_id;
                *icon_id = g_email_app_info_array[index].icon_id;
                return MMI_TRUE;
            }
            else
            {
                *str_id = g_email_app_info_array[index + 1].str_id;
                *icon_id = g_email_app_info_array[index + 1].icon_id;
                return MMI_TRUE;
            }
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_GET_APP_INFO, -1);
    return MMI_FALSE;
}

/* regeister data account callback */

/*****************************************************************************
 * FUNCTION 
 *  mmi_email_datacct_register_handler
 * DESCRIPTION 
 *  mmi email datacct register handler
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void mmi_email_datacct_register_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL has_register_data_acct_handler = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_REGISTER_HANDLER, 0);
    if (!has_register_data_acct_handler)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_REGISTER_HANDLER, 1);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, mmi_email_datacct_del_handler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, mmi_email_datacct_upd_handler, NULL);

        has_register_data_acct_handler = MMI_TRUE;
    }
}



/*****************************************************************************
 * FUNCTION 
 *  mmi_email_datacct_del_handler
 * DESCRIPTION 
 *  mmi email datacct del handler
 * PARAMETERS 
 *  mmi_event_struct* param
 * RETURNS 
 *  S32 
*****************************************************************************/
S32 mmi_email_datacct_del_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_acct_update_ind_evt_struct *dt_acct;
    U32 count;
    U32 i,j;
    cbm_app_info_struct app_info;
    EMAIL_ACCT_HANDLE acct_handle;
    srv_email_result_enum result;
    srv_email_acct_info_struct *acct_info;
    EMAIL_ACCT_ID acct_id_array[MMI_EMAIL_MAX_ACCTS] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_DEL_HANDLER, 0);

    dt_acct = (srv_dtcnt_acct_update_ind_evt_struct *)param;
    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_DEL_HANDLER, -1);
        return MMI_RET_OK;
    }

    if (dt_acct->cause != 1)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_DEL_HANDLER, -2);
        return MMI_RET_OK;
    }

    count = 0;
    srv_email_acct_get_num(&count);
    srv_email_acct_get_acct_id(0, (S32*)(&count), acct_id_array);
    
    acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    for (i = 0; i < count; ++i) 
    {
        MMI_BOOL acct_info_changed = MMI_FALSE;
        acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        result = srv_email_acct_create(0, &acct_handle);
        result = srv_email_acct_open(acct_handle, acct_id_array[i]);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_get_permission(acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }

        if (mmi_email_datacct_get_app_info(acct_id_array[i], MMI_TRUE, &(app_info.app_str_id), &(app_info.app_icon_id)))
        {
            cbm_account_info_struct acctInfo;

            for (j = 0; j < MMI_SIM_TOTAL; j++)
            {
                cbm_decode_data_account_id_ext(acct_info->in_server.data_acct[j], &acctInfo);

                if (acctInfo.acct_num == 2)
                {
                    if (acctInfo.account[0].account_id == dt_acct->acc_id)
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[0].account_id = acctInfo.account[1].account_id;
                        acctInfo.account[0].is_always_ask = acctInfo.account[1].is_always_ask;
                        acctInfo.account[0].sim_id = acctInfo.account[1].sim_id;

                        acctInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
                        acctInfo.account[1].is_always_ask = (kal_bool)0;
                    }
                    if (acctInfo.account[1].account_id == dt_acct->acc_id)
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
                        acctInfo.account[1].is_always_ask = (kal_bool)0;
                    }
                }
                else if (acctInfo.acct_num == 1)
                {
                    if (acctInfo.account[0].account_id == dt_acct->acc_id)
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                        acctInfo.account[0].is_always_ask = (kal_bool)0;
                    }
                }

                if (acct_info_changed)
                {
                    cbm_encode_data_account_id_ext(
                        acct_info->in_server.data_acct[j],
                        &(acct_info->in_server.data_acct[j]),
                        &acctInfo);
                    acct_info->out_server.data_acct[j] = acct_info->in_server.data_acct[j];
                }
            }// for (j = 0; j < MMI_SIM_TOTAL; j++)

            if (acct_info_changed)
            {
                srv_email_acct_edit(acct_handle, acct_info);
                srv_email_acct_save(acct_handle);
            }
        }
        srv_email_acct_destroy(acct_handle);
    }
    OslMfree(acct_info);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_DEL_HANDLER, 1);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_datacct_upd_handler
 * DESCRIPTION 
 *  mmi email datacct upd handler
 * PARAMETERS 
 *  mmi_event_struct* param
 * RETURNS 
 *  S32 
*****************************************************************************/
S32 mmi_email_datacct_upd_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    U32 i,j;
    cbm_app_info_struct app_info;
    EMAIL_ACCT_HANDLE acct_handle;
    srv_email_result_enum result;
    srv_email_acct_info_struct *acct_info;
    EMAIL_ACCT_ID acct_id_array[MMI_EMAIL_MAX_ACCTS] = {0};
    srv_dtcnt_acct_delete_ind_evt_struct *dt_acct = (srv_dtcnt_acct_delete_ind_evt_struct*)(param);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_UPD_HANDLER, 0);

    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DATACCT_UPD_HANDLER, -1);
        return MMI_RET_OK;
    }

    count = 0;
    srv_email_acct_get_num(&count);
    srv_email_acct_get_acct_id(0, (S32*)(&count), acct_id_array);
    
    acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    for (i = 0; i < count; ++i) 
    {
        MMI_BOOL acct_info_changed = MMI_FALSE;
        acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        result = srv_email_acct_create(0, &acct_handle);
        result = srv_email_acct_open(acct_handle, acct_id_array[i]);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }
        result = srv_email_acct_get_permission(acct_handle);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_destroy(acct_handle);
            continue;
        }

        if (mmi_email_datacct_get_app_info(acct_id_array[i], MMI_TRUE, &(app_info.app_str_id), &(app_info.app_icon_id)))
        {
            cbm_account_info_struct acctInfo;
            
            for (j = 0; j < MMI_SIM_TOTAL; j++)
            {
                cbm_decode_data_account_id_ext(acct_info->in_server.data_acct[j], &acctInfo);

                if (acctInfo.acct_num == 2)
                {
                if (acctInfo.account[0].account_id == dt_acct->acc_id[0])
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[0].account_id = acctInfo.account[1].account_id;
                        acctInfo.account[0].is_always_ask = acctInfo.account[1].is_always_ask;
                        acctInfo.account[0].sim_id = acctInfo.account[1].sim_id;

                        acctInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
                        acctInfo.account[1].is_always_ask = (kal_bool)0;
                    }
                if (acctInfo.account[1].account_id == dt_acct->acc_id[0])
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
                        acctInfo.account[1].is_always_ask = (kal_bool)0;
                    }
                }
                else if (acctInfo.acct_num == 1)
                {
                if (acctInfo.account[0].account_id == dt_acct->acc_id[0])
                    {
                        acct_info_changed = MMI_TRUE;
                        acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                        acctInfo.account[0].is_always_ask = (kal_bool)0;
                    }
                }

                if (acct_info_changed)
                {
                    cbm_encode_data_account_id_ext(
                        acct_info->in_server.data_acct[j],
                        &(acct_info->in_server.data_acct[j]),
                        &acctInfo);
                    acct_info->out_server.data_acct[j] = acct_info->in_server.data_acct[j];
}
            } // for (j = 0; j < MMI_SIM_TOTAL; j++)

            if (acct_info_changed)
            {
                srv_email_acct_edit(acct_handle, acct_info);
                srv_email_acct_save(acct_handle);
            }
        }


        srv_email_acct_destroy(acct_handle);
    }
    OslMfree(acct_info);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  mmi_email_dtcnt_is_conflict_ext
 * DESCRIPTION 
 *  mmi email dtcnt is conflict ext
 * PARAMETERS 
 *  EMAIL_ACCT_ID acct_id
 * RETURNS 
 *  MMI_BOOL 
*****************************************************************************/
MMI_BOOL mmi_email_dtcnt_is_conflict_ext(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_conflict = MMI_FALSE;

    U32 j;
    MMI_BOOL is_changed;
    EMAIL_ACCT_HANDLE acct_handle;
    srv_email_result_enum result;
    srv_email_acct_info_struct *acct_info;
    cbm_account_info_struct dtcntInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DTCNT_IS_CONFLICT_EXT, 0);

    result = srv_email_acct_create(0, &acct_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DTCNT_IS_CONFLICT_EXT, -1);
        return MMI_FALSE;
    }

    is_changed = MMI_FALSE;
    acct_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    do
    {
        result = srv_email_acct_open(acct_handle, acct_id);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        result = srv_email_acct_read(acct_handle, acct_info);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        for (j = 0; j < MMI_SIM_TOTAL; j++)
        {
            is_conflict = mmi_email_dtcnt_is_conflict(acct_info->in_server.data_acct[j]);
            if (!is_conflict)
            {
                continue;
            }

            // Set it as DEFAULT
            cbm_decode_data_account_id_ext(acct_info->in_server.data_acct[j], &dtcntInfo);

            // Set as DEFAULT
            dtcntInfo.acct_num = 1;
            dtcntInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
            dtcntInfo.account[0].is_always_ask = (kal_bool)0;
            dtcntInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
            dtcntInfo.account[1].is_always_ask = (kal_bool)0;

            cbm_encode_data_account_id_ext(
                acct_info->in_server.data_acct[j],
                &(acct_info->in_server.data_acct[j]),
                &dtcntInfo);
            acct_info->out_server.data_acct[j] = acct_info->in_server.data_acct[j];
            is_changed = MMI_TRUE;
        }
    }while(0);

    if (is_changed)
    {
        // Disconnect it if connected
        mmi_email_app_nwk_user_disconnect(acct_id);

        result = srv_email_acct_get_permission(acct_handle);
        if (result == SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_acct_edit(acct_handle, acct_info);
            srv_email_acct_save(acct_handle);;
        }
    }

    OslMfree(acct_info);
    srv_email_acct_destroy(acct_handle);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DTCNT_IS_CONFLICT_EXT, is_conflict);
    return is_changed;
}

MMI_BOOL mmi_email_dtcnt_is_any_conflict(U32 dtcnt_id[])
{
    U32 j;

    for (j = 0; j < MMI_SIM_TOTAL; j++)
    {
        if (mmi_email_dtcnt_is_conflict(dtcnt_id[j]))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

MMI_BOOL mmi_email_dtcnt_is_conflict(U32 dtcnt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct cbm_info;
    MMI_BOOL reset = MMI_FALSE;
    cbm_bearer_enum bearer_type = CBM_BEARER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DTCNT_IS_CONFLICT, 0);

    if (CBM_OK == cbm_get_bearer_type(dtcnt_id, &bearer_type))
    {
        if (CBM_CSD == bearer_type)
        {
            reset = MMI_TRUE;
        }
    }
    if (CBM_OK == cbm_decode_data_account_id_ext(dtcnt_id, &cbm_info))
    {
        if (cbm_info.acct_num > 1)
        {
            reset = MMI_TRUE;
        }
        else
        {
            if (KAL_TRUE == cbm_is_always_ask_account(dtcnt_id))
            {
                reset = MMI_TRUE;
            }
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DTCNT_IS_CONFLICT, reset);
    return reset;
}


U8 mmi_email_dtcnt_get_temp_appid(void)
{
    static U8 app_id = 0;
    cbm_app_info_struct app_info = {0};

    if (app_id != 0)
    {
        return app_id;
    }

    app_info.app_str_id = STR_GLOBAL_EMAIL;
    app_info.app_icon_id = 0;
    app_info.app_type = DTCNT_APPTYPE_EMAIL;
    cbm_register_app_id_with_app_info(&app_info, &app_id);

    return app_id;
}



void mmi_email_dtcnt_get_showname(WCHAR name[], U32 dtcnt_id[])
{
#if 1

    mmi_wcsncpy(name, (WCHAR*)GetString(STR_EMAIL_DTCNT_SELECT_MENU_TO_MODIFY), MAX_DATA_ACCOUNT_NAME_LEN);
    name[MAX_DATA_ACCOUNT_NAME_LEN] = 0;

#else
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
}

#endif /* #ifdef __MMI_EMAIL__ */
