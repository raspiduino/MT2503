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
 *  CallLogAdpPbapc.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)

#include "CallLogAdpPbapc.h"
#include "PhbpbapSrvGprot.h"
#include "PhbSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "Unicodexdcl.h"
#include "vcard_lib.h"
#include "vcard_utility.h"
#include "vcard_parser.h"
#include "Mmi_rp_app_calllog_def.h"
#include "MMITimer_Int.h"
#include "FileMgrSrvGprot.h"
#include "CallLogAdpProt.h"
#include "CallLogGprot.h"
#include "BtcmSrvGprot.h"
#include "CallLogProt.h"
#include "CallLogLayout.h"

mmi_clog_pbapc_cntx_struct g_mmi_clog_pbapc_cntx;
mmi_clog_pbapc_ex_inst_struct g_mmi_clog_pbapc_cntx_ex;
mmi_clog_pbapc_ex_inst_struct g_mmi_clog_pbapc_cntx_ex_cb;

mmi_clog_pbap_clog_info_cache_struct g_mmi_clog_pbapc_clog_info_cache[MMI_CLOG_PBAPC_ALL_CALL_ENTRIES];
U16 mmi_clog_pbap_current_num;

MMI_BOOL g_folder_exist = MMI_FALSE;
WCHAR des_path[20];
WCHAR des_file[40];
extern U32 g_exist_flag;
extern WCHAR path[41];
extern mmi_clog_get_last_num_struct g_mmi_clog_get_last_info;

static void mmi_clog_pbapc_copy_file(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, U8 index);
mmi_clog_pbapc_ex_inst_struct* mmi_clog_get_pbapcex_cntx();

 
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_init
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_INIT, g_mmi_clog_pbapc_cntx.phapc_op_handle, g_mmi_clog_pbapc_cntx.p_handle);
#ifdef __MULTI_VCARD_SUPPORT__ 
    if (g_mmi_clog_pbapc_cntx.p_handle)//use for bg read all , do some op in vcard file then parse file.
    {
        vcard_close_parser(g_mmi_clog_pbapc_cntx.p_handle);
        g_mmi_clog_pbapc_cntx.p_handle = NULL;
    }
#endif

    if (g_mmi_clog_pbapc_cntx.phapc_op_handle)
    {
        mmi_clog_pbapc_free_op_handle();
    }
    memset((void *)&g_mmi_clog_pbapc_cntx, 0x0, sizeof(mmi_clog_pbapc_cntx_struct));
#ifdef __MMI_BT_PBAP_CLIENT__
#else
    memset((void *)&g_mmi_clog_pbapc_clog_info_cache, 0x0, sizeof(mmi_clog_pbap_clog_info_cache_struct) * MMI_CLOG_PBAPC_ENTRIES);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_deinit
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_deinit(void)
{    
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_DEINIT);
    for(i = 0; i < mmi_clog_pbap_current_num; i++)
    {
        if(g_mmi_clog_pbapc_clog_info_cache[i].clog_info)
        {
            srv_phb_mem_free(g_mmi_clog_pbapc_clog_info_cache[i].clog_info);
            g_mmi_clog_pbapc_clog_info_cache[i].clog_info = NULL;
        }
    }
    
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_free_op_handle
 * DESCRIPTION
 *  memory free function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_free_op_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SRV_PHB_PBAPC_HANDLE temp_handle;
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_FREE_OP_HANDLE, 
                g_mmi_clog_pbapc_cntx.phapc_op_handle);
#ifdef __MULTI_VCARD_SUPPORT__
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_FREE_OP_VCARD_HANDLE, g_mmi_clog_pbapc_cntx.p_handle);

    if (g_mmi_clog_pbapc_cntx.p_handle)
    {
        vcard_close_parser(g_mmi_clog_pbapc_cntx.p_handle);
        g_mmi_clog_pbapc_cntx.p_handle = NULL;
    }
#endif /*__MULTI_VCARD_SUPPORT__*/

    if(g_mmi_clog_pbapc_cntx.phapc_op_handle)
    {        
        temp_handle = g_mmi_clog_pbapc_cntx.phapc_op_handle; 
        g_mmi_clog_pbapc_cntx.phapc_op_handle = NULL;
        srv_phb_pbapc_destory_handle(temp_handle);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_storage_path_to_lt
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  path         [IN]        
 * RETURNS
 *  mmi_clog_pbapc_clt_enum
 *****************************************************************************/
static mmi_clog_pbapc_clt_enum mmi_clog_pbapc_storage_path_to_lt(srv_phb_pbap_storage_enum path)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (path)
    {
        case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return MMI_CLOG_PBAPC_CLT_DIALED;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return MMI_CLOG_PBAPC_CLT_MISSED;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return MMI_CLOG_PBAPC_CLT_RECVED;
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            return MMI_CLOG_PBAPC_CLT_ALL;
        default:
            {
                EXT_ASSERT(0, 0, 0, 0);
            } 
            break;
    }
    return MMI_CLOG_PBAPC_CLT_DEFAULT;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vcard_object_to_clog
 * DESCRIPTION
 *  
 * PARAMETERS       
 *  vcard_object    [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_clog_pbapc_vcard_object_to_clog(vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_clog_pbap_info_struct *clog_info = NULL;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_ENTER, vcard_object);
    if(vcard_object == NULL)
        return -1;

    if(mmi_clog_pbap_current_num >= MMI_CLOG_PBAPC_ENTRIES)  
    {
        g_mmi_clog_pbapc_cntx.is_stoped = MMI_TRUE;
        return 0;
    }

    kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_pbapc_vcard_object_to_clog: path = %d", g_mmi_clog_pbapc_cntx.path);
    if (g_mmi_clog_pbapc_cntx.path != SRV_PHB_PBAP_STORAGE_PHONE_CCH )
    { 
        if (vcard_object->x.call_type == mmi_clog_pbapc_storage_path_to_lt(g_mmi_clog_pbapc_cntx.path))
        {
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__  
            if(g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info == NULL) 
            {
                g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info = 
                    (mmi_clog_pbap_info_struct *)srv_phb_mem_malloc(sizeof(mmi_clog_pbap_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
            }
            clog_info = g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info;
            if(clog_info == NULL)
                return -1;
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/	   
            clog_info = &g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info;
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/	   
            memset(clog_info, 0x0, sizeof(mmi_clog_pbap_info_struct));

             //log type
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CALL_TYPE, vcard_object->x.call_type);   
            //if(vcard_object->x.call_type != mmi_clog_pbapc_storage_path_to_lt(g_mmi_clog_pbapc_cntx.path))
            //    return 0;
            /* orignial code for bt dialer in modis */
            clog_info->call_type = mmi_clog_pbapc_storage_path_to_lt(g_mmi_clog_pbapc_cntx.path);

            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CALL_TYPE, clog_info->call_type);   
                   
            // name
            srv_phb_remove_invalid_name(vcard_object->n.family);
            srv_phb_remove_invalid_name(vcard_object->n.given);
            srv_phb_convert_to_name(
                    clog_info->name,
                    vcard_object->n.given,
                    vcard_object->n.family,
                    MMI_CLOG_PBAPC_NAME_MAX_LEN);
            // tel.
            srv_phb_remove_invalid_number(vcard_object->tel[0].tel);
            if (vcard_object->tel[0].tel && vcard_object->tel[0].tel[0] && srv_phb_check_valid_number(vcard_object->tel[0].tel))
            {      
                mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[0].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
            } 
            
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);
            if (clog_info->cid[0]== '\0')
            {
                srv_phb_remove_invalid_number(vcard_object->tel[1].tel);  
                if (vcard_object->tel[1].tel && vcard_object->tel[1].tel[0] && srv_phb_check_valid_number(vcard_object->tel[1].tel))
                {      
                    mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[1].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
                }
            }
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);

            if (clog_info->cid[0]== '\0')
            {
                srv_phb_remove_invalid_number(vcard_object->tel[2].tel);  
                if (vcard_object->tel[2].tel && vcard_object->tel[2].tel[0] && srv_phb_check_valid_number(vcard_object->tel[2].tel))
                {      
                    mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[2].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
                }
            }
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);

            if (clog_info->cid[0]== '\0')
            {
                srv_phb_remove_invalid_number(vcard_object->tel[3].tel);  
                if (vcard_object->tel[3].tel && vcard_object->tel[3].tel[0] && srv_phb_check_valid_number(vcard_object->tel[3].tel))
                {      
                    mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[3].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);//ENCODING_LENGTH);
                }
            }
        
            // time
            memcpy(&(clog_info->timestamp[0]), &(vcard_object->x.call_time), sizeof(applib_time_struct));

            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid);

            if(clog_info->cid[0] != '\0')
            {
                mmi_clog_pbap_current_num++;
            }
        }

    }
    else
    {
        {
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__  
        if(g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info == NULL) 
        {
            g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info = 
                (mmi_clog_pbap_info_struct *)srv_phb_mem_malloc(sizeof(mmi_clog_pbap_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        clog_info = g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info;
        if(clog_info == NULL)
            return -1;
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/	   
        clog_info = &g_mmi_clog_pbapc_clog_info_cache[mmi_clog_pbap_current_num].clog_info;
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/	   
        memset(clog_info, 0x0, sizeof(mmi_clog_pbap_info_struct));

         //log type
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CALL_TYPE, vcard_object->x.call_type);   
        //if(vcard_object->x.call_type != mmi_clog_pbapc_storage_path_to_lt(g_mmi_clog_pbapc_cntx.path))
        //    return 0;
        /* orignial code for bt dialer in modis */
        if (g_mmi_clog_pbapc_cntx.path == SRV_PHB_PBAP_STORAGE_PHONE_CCH)
        {
            clog_info->call_type = vcard_object->x.call_type;
        }
        else
        {
            clog_info->call_type = mmi_clog_pbapc_storage_path_to_lt(g_mmi_clog_pbapc_cntx.path);
        }

       // MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid);

        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CALL_TYPE, clog_info->call_type);   
               
        // name
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.given);
        srv_phb_convert_to_name(
                clog_info->name,
                vcard_object->n.given,
                vcard_object->n.family,
                MMI_CLOG_PBAPC_NAME_MAX_LEN);
        // tel.
        srv_phb_remove_invalid_number(vcard_object->tel[0].tel);

        
        if (vcard_object->tel[0].tel && vcard_object->tel[0].tel[0] && srv_phb_check_valid_number(vcard_object->tel[0].tel))
        {      
            mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[0].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
        } 
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);
        if (clog_info->cid[0]== '\0')
        {
            srv_phb_remove_invalid_number(vcard_object->tel[1].tel);  
            if (vcard_object->tel[1].tel && vcard_object->tel[1].tel[0] && srv_phb_check_valid_number(vcard_object->tel[1].tel))
            {      
                mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[1].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
            }
        }
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);

        if (clog_info->cid[0]== '\0')
        {
            srv_phb_remove_invalid_number(vcard_object->tel[2].tel);  
            if (vcard_object->tel[2].tel && vcard_object->tel[2].tel[0] && srv_phb_check_valid_number(vcard_object->tel[2].tel))
            {      
                mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[2].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
            }
        }
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);

        if (clog_info->cid[0]== '\0')
        {
            srv_phb_remove_invalid_number(vcard_object->tel[3].tel);  
            if (vcard_object->tel[3].tel && vcard_object->tel[3].tel[0] && srv_phb_check_valid_number(vcard_object->tel[3].tel))
            {      
                mmi_wcs_n_to_asc((CHAR*) clog_info->cid, vcard_object->tel[3].tel, (MMI_CLOG_PBAPC_CID_MAX_LEN+1) * ENCODING_LENGTH);
            }

        }

        // time
        memcpy(&(clog_info->timestamp[0]), &(vcard_object->x.call_time), sizeof(applib_time_struct));

        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_CID, (CHAR*) clog_info->cid[0]);

        if(clog_info->cid[0] != '\0')
        {
            mmi_clog_pbap_current_num++;
        }
        }

    }
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_VCARD_OBJECT_TO_CLOG_STOP, mmi_clog_pbap_current_num);
    return 0;
}

 MMI_BOOL mmi_clog_pbapc_is_btsc_active()
{
    MMI_ID scr_id;

    scr_id = mmi_frm_scrn_get_active_id();
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO,TRC_MMI_CLOG_PBAPC_IS_ACTIVE, scr_id, g_exist_flag);

#if SRV_PBAPC_LINK_NUM >= 2
#ifdef __MMI_PHB_PBAPC_SYNC_CONTACT__
    if (scr_id == SCR_ID_CLOG_LAYOUT && g_exist_flag)
#else
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ 
    if ((scr_id == GRP_ID_CLOG_SUB_BT_DEVICE || scr_id == SCR_ID_CLOG_SUB_BT_DEVICE_V3) && g_exist_flag)
#else
    if (scr_id == SCR_ID_CLOG_LAYOUT && g_exist_flag)
#endif/*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
#endif
#else
#ifndef __MMI_TELEPHONY_SUPPORT__
    if (scr_id == SCR_ID_CLOG_LAYOUT && g_exist_flag)
#endif/*__MMI_TELEPHONY_SUPPORT__*/

#endif

    {
        return MMI_TRUE;
    }
    return MMI_FALSE;

}

/*****************************************************************************
* FUNCTION
*  mmi_clog_pbapc_op_done
* DESCRIPTION
*  
* PARAMETERS
*  S32          [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_clog_pbapc_op_done(S32 error_code, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    MMI_BOOL is_active;
    S32 ret;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;

    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_OP_DONE, error_code, g_mmi_clog_pbapc_cntx.is_canceled);
   
    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    mmi_clog_pbapc_free_op_handle();

    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_CB_ACTVIE, index, g_mmi_clog_pbapc_cntx.is_read, clog_pbapc_cntx->only_update[index]);
    if (g_mmi_clog_get_last_info.is_get_num)
    {
        mmi_clog_bt_compare_log_by_timestamp(error_code);

        return;
    }
    mmi_clog_pbapc_processing_abort();

    if(error_code < 0 || g_mmi_clog_pbapc_cntx.is_canceled)
    {
        mmi_clog_pbapc_deinit();
        if (error_code < 0 && !clog_pbapc_cntx->only_update[index])
        {
            is_active = mmi_clog_pbapc_is_btsc_active();
	    kal_wsprintf(path,"%s%d%s",SRV_PHB_PBAPC_FOLDER_PATH_FIX, index, SRV_PHB_PBAPC_FILE);
	    ret = srv_fmgr_fs_path_exist(path);
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_COPY_DONE, ret);
            if (ret >= 0)
            {
                ret = FS_Delete(path);
            }

            MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_CURR_ACTIVE, is_active, g_exist_flag, ret);
            if (is_active)
            {
                mmi_clog_pbapc_show_category(error_code, NULL);
            }
            else
            {
                return;
                
            }
        }
        clog_pbapc_cntx->only_update[index] = MMI_FALSE;
    }
    
    if (!g_mmi_clog_pbapc_cntx.is_canceled)
    {
        g_mmi_clog_pbapc_cntx.is_canceled = MMI_TRUE;
        if (g_mmi_clog_pbapc_cntx.cb && error_code >= 0)
        {    
            g_mmi_clog_pbapc_cntx.cb(error_code);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_parse_file_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_pbapc_parse_file_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_PARSE_FILE_CB_ENTER, ret, percentage);

    if (percentage <= 100 && ret == VCARD_NO_ERROR)
    {
        if (g_mmi_clog_pbapc_cntx.is_stoped == MMI_FALSE && g_mmi_clog_pbapc_cntx.is_canceled == MMI_FALSE)
        {          
            ret = mmi_clog_pbapc_vcard_object_to_clog(object);
            
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_PARSE_FILE_CB, ret, percentage);

            if(percentage == 100)
            {
                g_mmi_clog_pbapc_cntx.is_stoped = MMI_TRUE;
            }
            else if (g_mmi_clog_pbapc_cntx.is_stoped == MMI_FALSE && g_mmi_clog_pbapc_cntx.is_canceled == MMI_FALSE)
            {
            #ifdef __MULTI_VCARD_SUPPORT__
            if (g_mmi_clog_pbapc_cntx.p_handle)
            {
                vcard_multi_parse(g_mmi_clog_pbapc_cntx.p_handle, mmi_clog_pbapc_parse_file_cb, NULL);
            }
            #endif /*__MULTI_VCARD_SUPPORT__*/
                return;
            } 
        }
    }
    mmi_clog_pbapc_op_done(ret, g_mmi_clog_pbapc_cntx_ex.index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_parse_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
//static S32 mmi_clog_pbapc_parse_file(U16 *path)//for other use
S32 mmi_clog_pbapc_parse_file(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_PARSE_FILE, path);
#ifdef __MULTI_VCARD_SUPPORT__
    if (g_mmi_clog_pbapc_cntx.is_stoped == MMI_FALSE && g_mmi_clog_pbapc_cntx.is_canceled == MMI_FALSE)
    {
        g_mmi_clog_pbapc_cntx.p_handle = vcard_open_parser(path, VCARD_PROPERTY_N|VCARD_PROPERTY_TEL|VCARD_PROPERTY_X, &error_code);
            
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_PARSE_FILE_1, error_code);
            
        if (g_mmi_clog_pbapc_cntx.p_handle)
        {
            vcard_multi_parse(g_mmi_clog_pbapc_cntx.p_handle, mmi_clog_pbapc_parse_file_cb, NULL);               
            return error_code;
        }
    }    
#else /*__MULTI_VCARD_SUPPORT__*/
    error_code = -1;    
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_PARSE_FILE_2, error_code);
#endif /*__MULTI_VCARD_SUPPORT__*/

    return error_code;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_read_folder_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_rsp     [IN]
 *  user_data     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_clog_pbapc_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    S32 fs_ret = -1;
    S32 ret = folder_rsp->ret;
    mmi_clog_pbapc_ex_inst_struct *cb_pbapc_cntx = NULL;
    mmi_clog_pbapc_ex_inst_struct *pbapc_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER_CB, ret);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_NEED_CREATE_FOLDER,g_folder_exist, 0);

    mmi_clog_pbapc_free_op_handle();


    pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
#ifdef __MTK_TARGET__
    cb_pbapc_cntx = (mmi_clog_pbapc_ex_inst_struct *)user_data;
    index = cb_pbapc_cntx->index;  
#else
    index = 0;  
#endif 
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER_CB0, index, pbapc_cntx->index);

    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &pbapc_cntx->addr[index]))
    {
        if (!g_folder_exist)
        {
             kal_wsprintf(des_path, "%s", SRV_PHB_PBAPC_FOLDER_PATH_FIX);
             fs_ret = srv_fmgr_fs_path_exist(des_path);
             if (fs_ret < 0)
             {
                fs_ret = srv_fmgr_fs_create_folder(des_path);
                if(fs_ret >= 0)
                {
                    g_folder_exist = MMI_TRUE;
                }
             }
             else
             {
                g_folder_exist = MMI_TRUE;
             }
             MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_RSP_END_CALL, g_only_update_data);                        
             if (g_only_update_data)
             {
                MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_RSP_END_CALL_CP);                        
                mmi_clog_pbapc_copy_file(folder_rsp,index);
                return ;
             }
        }
        else
        {
            MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_RSP_NORMAL_CP);                 
            mmi_clog_pbapc_copy_file(folder_rsp, index);
            return;
        }
    }
 

    if (index !=  pbapc_cntx->index)
    {
        mmi_clog_pbapc_processing_abort();

        return;
    }
    if (ret == 0)
    {
    #ifdef __MTK_TARGET__
        ret= mmi_clog_pbapc_parse_file(folder_rsp->folder_path);
    #else
        ret = mmi_clog_pbapc_parse_file(SRV_PHB_PBAPC_FOLDER_PATH);// MODIFY
    #endif
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER_CB_PARSE_RET, ret);
        if(ret < 0)
        {
            if(ret == FS_FILE_NOT_FOUND || ret == FS_PATH_NOT_FOUND)
                ret = 0;
            mmi_clog_pbapc_op_done(ret, index);
        }
    }
    else
    {
       ret = -1;
       mmi_clog_pbapc_op_done(ret, index);
    }  

    return ret;
}

static void mmi_clog_pbapc_copy_file(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, U8 index)
{
    S32 ret;
    kal_wsprintf(des_file,"%s", SRV_PHB_PBAPC_FOLDER_PATH_FILE);
    kal_wsprintf(path,"%s%d%s",SRV_PHB_PBAPC_FOLDER_PATH_FIX, index, SRV_PHB_PBAPC_FILE);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_FILE_EXIST,srv_fmgr_fs_path_exist(des_file), g_only_update_data,index);
    ret = srv_fmgr_fs_path_exist(path);
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_COPY_DONE, ret);
    if (ret >= 0)
    {
        ret = FS_Delete(path);
    }
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_COPY_DONE, ret);
    ret = srv_fmgr_fs_path_exist(des_file);
    if (ret >= 0)
    {
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_COPY_DONE, ret);
        ret = FS_Delete(des_file);

    }
    ret = srv_fmgr_fs_path_exist(folder_rsp->folder_path);
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_PATH_EXIST, ret, 0);
    ret = FS_Move(folder_rsp->folder_path,des_file,FS_MOVE_COPY,NULL,NULL, NULL);
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_PATH_EXIST, ret,1);
    ret = FS_Rename(des_file, path);
    g_mmi_clog_pbapc_cntx_ex.only_update[index] = MMI_FALSE;
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_PATH_EXIST, ret, 2);

    if (g_only_update_data)
    {
        mmi_clog_pbapc_processing_abort();
    }
    g_only_update_data = MMI_FALSE;

    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_PATH_EXIST, ret, 2);

    if (g_mmi_clog_get_last_info.is_get_num)
    {
        mmi_clog_pbapc_parse_file(path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_read_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_read_folder(srv_phb_pbap_storage_enum path)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    U8 index;
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;
    mmi_clog_pbapc_cntx_struct * pbapc_cntx = NULL;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    pbapc_cntx = mmi_clog_get_pbapc_cntx();

    mmi_clog_pbap_current_num = 0;
    g_mmi_clog_pbapc_cntx.path = path;
    if (g_mmi_clog_get_last_info.is_get_num)
    {
        index = g_mmi_clog_get_last_info.index;/* bt no screen which is given by other*/
        clog_pbapc_cntx->index = index;
    }
    else
    {
        index =  clog_pbapc_cntx->index;

    }

    
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER_0, clog_pbapc_cntx->flag[index], index);
    if (pbapc_cntx->phapc_op_handle == NULL)
    {
        pbapc_cntx->phapc_op_handle = srv_phb_pbapc_create_handle(&ret);
    }

    
    MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER, ret, pbapc_cntx->path, pbapc_cntx->phapc_op_handle);

    if (ret == SRV_PHB_PBAPC_RET_OK)  
    {
    
        clog_pbapc_cntx->flag[index] = 1;
        /* Req head */
        folder_req.handle = pbapc_cntx->phapc_op_handle;
        folder_req.storage = path;
        memset(&g_mmi_clog_pbapc_cntx_ex_cb,0x00,sizeof (mmi_clog_pbapc_ex_inst_struct));
        memcpy(&g_mmi_clog_pbapc_cntx_ex_cb, &g_mmi_clog_pbapc_cntx_ex, sizeof (mmi_clog_pbapc_ex_inst_struct));
        folder_req.user_data = (void *)&g_mmi_clog_pbapc_cntx_ex_cb;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N|SRV_PHB_PBAP_VCARD_FILTER_TEL|SRV_PHB_PBAP_VCARD_FILTER_FN|SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP;
        if (path == SRV_PHB_PBAP_STORAGE_PHONE_CCH)
        {
            folder_req.list_count = MMI_CLOG_PBAPC_ALL_CALL_ENTRIES;
        }
        else
        {
            folder_req.list_count = MMI_CLOG_PBAPC_ENTRIES;
        }
        
        folder_req.list_offset = 0; 
        folder_req.bt_index = index;
        ret = srv_phb_pbapc_read_pse_folder(&folder_req, mmi_clog_pbapc_read_folder_cb);
       
        MMI_TRACE(MMI_CLOG_PBAPC_TRC_INFO, TRC_MMI_CLOG_PBAPC_READ_FOLDER_1, ret);
    }  
    if(ret < SRV_PHB_PBAPC_RET_OK)
    {
        if (ret == SRV_PHB_PBAPC_RET_HD_FULL) // wait release handle evt
        {
           // kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_pbapc_read_pse_list(wait handle release)\n");
        }
        mmi_clog_pbapc_op_done(ret, index);
    }
    /* MODIFY START*/
#else
    srv_phb_pbapc_read_folder_rsp_struct folder_rsp = {SRV_PHB_PBAPC_FOLDER_PATH, 0};
	g_mmi_clog_pbapc_cntx_ex.flag[0] = 1;
    mmi_clog_pbapc_read_folder_cb(&folder_rsp, NULL);
#endif
/*MODIFY END*/
}


mmi_clog_pbapc_cntx_struct* mmi_clog_get_pbapc_cntx()
{
    return &g_mmi_clog_pbapc_cntx;
}

mmi_clog_pbapc_ex_inst_struct* mmi_clog_get_pbapc_cntx_ex()
{
    return &g_mmi_clog_pbapc_cntx_ex;
}

#endif /*__MMI_BT_PBAP_CLIENT__*/
