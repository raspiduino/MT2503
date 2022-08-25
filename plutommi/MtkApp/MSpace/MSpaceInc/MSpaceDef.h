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

/*******************************************************************************
 * Filename:
 * ---------
 *  MSpaceDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MSpace header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MSPACE_DEF_H
#define MSPACE_DEF_H

#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMIDataType.h"
#include "MASSrvGprot.h"


/***************************************************************************** 
* Typedef 
*****************************************************************************/


#ifndef MSPACE_MAX_STRING
#define MSPACE_MAX_STRING SRV_AS_MAX_STRING
#endif

#ifndef MSPACE_APP_DES_MAX_STRING
#define MSPACE_APP_DES_MAX_STRING (SRV_AS_MAX_STRING * 4)
#endif


typedef enum
{
    E_MSPACE_AS_NONE,
	E_MSPACE_AS_CONNECTING,
	E_MSPACE_AS_CONNECTED,	
	E_MSPACE_AS_QUERYING, 
    E_MSPACE_AS_STARTING,
    E_MSPACE_AS_DOWNLOADING,
    E_MSPACE_AS_DOWNLOADED, 
    E_MSPACE_AS_FAIL,
    E_MSPACE_AS_INSTALL_SUCCESS,
    E_MSPACE_AS_INSTALL_FAIL,
    E_MSPACE_AS_MAX
}mspace_as_state_e;


/* MSpace context struct */
typedef struct
{
    void *dyn_mem_pool;
    KAL_ADM_ID adm_pool_id;   

	S32 app_num;

	// For category1072 get image	
	srv_as_app_node_t *get_app_static_info;	
	U8 * get_app_icon;
	U32 get_app_icon_max_size;
	
    /* highlight info */
    S32 hl_idx; /* highlighted index */
	srv_as_app_node_t *cur_app_static_info;		// For app static info
	srv_as_app_info_t *cur_app_dynamic_info;	// For app dynamic info	
	U8 *cur_app_icon;

	S32 cur_as_lis_hdl;	
	S32 cur_as_app_hdl;	
	mspace_as_state_e cur_as_status;

	mmi_id option_gid;
    mmi_id confirm_gid;

} mmi_mspace_ms_struct;

#endif /* MSPACE_DEF_H */ 

