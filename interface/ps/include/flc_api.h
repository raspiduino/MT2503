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
 *   flc_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the function declarations used for flow
 *   control implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLC_API_H
#define _FLC_API_H

/*************************************************************************
 * Include header files
 *************************************************************************/
#ifdef __FLC2__

#include "custom_flc_config.h"
#include "flc2_tunable_para.h"
#include "flc2_mem_mngr_config.h"
#include "flc2_config.h"
#include "flc2_ent_functions.h"

#else  /* __FLC2__ */

#include "gprs_flc_kal_data_types.h"
#include "gprs_flc_common_data_types.h"
#include "gprs_flc_kal.h"
#include "flc_tunable_para.h"

#endif /* __FLC2__ */

/*************************************************************************
 * Macro 
 *************************************************************************/

#ifdef __FLC2__
#define FLC_GET_PEER_BUFF(_pool_id_, _pdu_len_, _header_size_, _tail_size_, _data_type_, _sapi_type_, _dir_, _context_id_, is_pool_created) \
        flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_)

#define FLC_FREE_PEER_BUFF(_pool_id_, _buff_ptr_ , _data_type_, _sapi_type_, _dir_, _context_id_) \
        flc2_free_peer_buff(_pool_id_, _buff_ptr_)
#else  /* __FLC2__ */

#define FLC_GET_PEER_BUFF(_pool_id_, _pdu_len_, _header_size_, _tail_size_, _data_type_, _sapi_type_, _dir_, _context_id_, is_pool_created) \
       gprs_flc_get_peer_buff ( _data_type_, _sapi_type_, _dir_, _context_id_, _pdu_len_, _header_size_, _tail_size_, is_pool_created)\

#define FLC_FREE_PEER_BUFF(_pool_id_, _buff_ptr_, _data_type_, _sapi_type_, _dir_, _context_id_) \
        gprs_flc_free_peer_buff( _data_type_, _sapi_type_, _dir_, _context_id_, _buff_ptr_)

#endif /* __FLC2__ */


#endif /* _FLC_API_H */


