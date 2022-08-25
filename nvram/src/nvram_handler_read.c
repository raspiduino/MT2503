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
 * nvram_handler_read.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is read handler function of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "nvram_main.h"

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__) || !defined(__NVRAM_SECRET_DATA__)
#include "fctycomp_config.h"  /* MOD_FT */
#endif

/*****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  nvram_read_confirm
 * DESCRIPTION
 *  This is nvram_read_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]
 *  result              [IN]
 *  nvram_read_req      [?]
 *  size                [IN]
 *  peer_buf_ptr        [?]
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
/** Could not be static because the nvram should send a read_confirm
 *  Message to L1 at nvram init, that will call this function
 */
void nvram_read_confirm(module_type dest_id, nvram_errno_enum result, nvram_read_req_struct *nvram_read_req, kal_uint16 size, peer_buff_struct *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *nvram_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_READ_CNF, result, nvram_read_req->file_idx, nvram_read_req->para);

    nvram_read_cnf = (nvram_read_cnf_struct*) construct_local_para(sizeof(nvram_read_cnf_struct), TD_CTRL);

    nvram_read_cnf->result = result;
    nvram_read_cnf->file_idx = nvram_read_req->file_idx;
    nvram_read_cnf->para = nvram_read_req->para;
    nvram_read_cnf->length = size;
    nvram_read_cnf->access_id = nvram_read_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_READ_CNF, nvram_read_cnf, peer_buf_ptr);

    return;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_read_handler
 * DESCRIPTION
 *  This is nvram_read_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_read_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *nvram_read_req = (nvram_read_req_struct*) ilm_ptr->local_para_ptr;
    nvram_ltable_entry_struct *ldi;
    peer_buff_struct *peer_buf_ptr = NULL;
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;

    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;
    kal_uint32 size         = NVRAM_INVALID_VALUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(nvram_read_req != NULL);

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_READ);


    do
    {

        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);
            /*
            nvram_read_confirm(
                ilm_ptr->src_mod_id,
                NVRAM_ERRNO_NOT_READY,
                nvram_read_req,
                (kal_uint16) NVRAM_INVALID_VALUE,
                NULL);
            return;
            */
            result = NVRAM_ERRNO_NOT_READY;
            break;
        }

        /**
        * Invalid input paramters.
        * file_idx / LID : 1 ~ (total_LID - 1)
        * para / section: 1 ~ total_records
        */
        if (!NVRAM_IS_LID_VALID(nvram_read_req->file_idx))
        {
            //nvram_read_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_LID, nvram_read_req, (kal_uint16) NVRAM_INVALID_VALUE, NULL);     /* nvram_read_confirm */
            //return;
            result = NVRAM_IO_ERRNO_INVALID_LID;
            break;
        }

        nvram_util_get_data_item(&ldi, nvram_read_req->file_idx);

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__) || !defined(__NVRAM_SECRET_DATA__)
        if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) ||
            NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category) ||
            NVRAM_IS_CATEGORY_SECUPACK(ldi->category))
        {
            if (FACTORY_BOOT == stack_query_boot_mode() && ilm_ptr->src_mod_id == MOD_FT)
            {
                //nvram_read_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_ACCESS_DENIED, nvram_read_req, (kal_uint16) NVRAM_INVALID_VALUE, NULL);     /* nvram_read_confirm */
                //return;
                result = NVRAM_IO_ERRNO_ACCESS_DENIED;
                break;
            }
        }
#endif

        if ((nvram_read_req->para < 1) ||
            (nvram_read_req->para > ldi->total_records))
        {
            //nvram_read_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_RECORD, nvram_read_req, (kal_uint16) NVRAM_INVALID_VALUE, NULL);     /* nvram_read_confirm */
            //return;
            result = NVRAM_IO_ERRNO_INVALID_RECORD;
            break;
        }

        if (!(ldi->attr & NVRAM_ATTR_MULTIREC_READ) ||
#ifdef __MULTI_BOOT__
            (FACTORY_BOOT == stack_query_boot_mode()) ||    /* META won't multi-read */
#endif
            (ilm_ptr->src_mod_id == MOD_NVRAM)  /* TST handler */
            )
		{
            nvram_read_req->rec_amount = 1;
		}
        else
        {

            if (nvram_read_req->para + nvram_read_req->rec_amount -1 > ldi->total_records)
            {
                nvram_read_req->rec_amount = ldi->total_records - nvram_read_req->para + 1;
            }

            if (nvram_read_req->rec_amount * (ldi->size + NVRAM_CHKSUM_SIZE) > MAX_NVRAM_RECORD_SIZE)
            {
                nvram_read_req->rec_amount = MAX_NVRAM_RECORD_SIZE / (ldi->size + NVRAM_CHKSUM_SIZE + 1);
            }
        }
        
		pdu_length = ldi->size * nvram_read_req->rec_amount;
				
        peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

        pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

        /*
        nvram_read_confirm(
            ilm_ptr->src_mod_id,
            nvram_read_data_item(ldi, nvram_read_req->para, nvram_read_req->rec_amount, pdu_ptr, pdu_length),
            nvram_read_req,
            (kal_uint16) (ldi->size * nvram_read_req->rec_amount),
            peer_buf_ptr);
            */

        result = nvram_read_data_item(ldi, nvram_read_req->para, nvram_read_req->rec_amount, pdu_ptr, pdu_length);
        size = (ldi->size * nvram_read_req->rec_amount);
    } while(0);

    nvram_read_confirm(ilm_ptr->src_mod_id, result, nvram_read_req, (kal_uint16)size, peer_buf_ptr);
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
#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MULTI_BOOT__
/* under construction !*/
#endif
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


