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
 * OPPMMIScr.h
 *
 * Project:
 * --------
 *   MMI
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OPP_SUPPORT__

#ifndef __OPP_MMI_SCR_H__
#define __OPP_MMI_SCR_H__
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "OppSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
/* auto add by kw_check end */


#ifdef __MMI_BT_SLIM__ 
#ifndef _MMI_BT_ULTRA_SLIM_ 
#define _MMI_BT_ULTRA_SLIM_ 
#endif 
#endif

#define OPP_PUSH_IND_PROG_UPD_DUR    60000
#define OPP_REQ_TIMEOUT   15000
#define OPP_MAX_PATH_LENGTH     60
#define MAX_DEV_NAME    80

/***************************************************************************** 
* Enum Value
*****************************************************************************/
typedef enum
{
    MMI_OPP_NOTIFY_DETAIL,
    MMI_OPP_NOTIFY_RECV,
} mmi_opps_notify_enum;

typedef enum
{

    OPP_FILE_GET_NAME,  /* Extract file name */
    OPP_FILE_GET_EXT,   /* Extract file extension */
    OPP_FILE_GET_NAME_VALID,
    OPP_FILE_GET_LAST
} MMI_OPP_GET_FILE_ENUM;

/***************************************************************************** 
* MMI OPP Client/Server status
*****************************************************************************/

/***************************************************************************** 
* MMI OPP Scr Context
*****************************************************************************/
typedef struct
{
    MMI_BOOL disconn_from_cm;
    U16 obj_name[OPP_MAX_OBJ_NAME_LENGTH];
    S8 obj_mime[OPP_MAX_OBJ_MIME_LENGTH];
    U32 obj_len;
    U16 cur_recv_file_cnt;
    U16 recv_file_cnt;
    U8 recv_drv;
    U8 gid;
    U16 recv_path[OPP_MAX_PATH_LENGTH];
    void *app_callback;
    S32 srv_hd;
    S32 recv_hd;
    U32 mime;
} mmi_opps_cntx_struct;

typedef struct
{
    mmi_opps_cntx_struct opps_cntx;
} mmi_opp_struct;

extern mmi_opp_struct *mmi_opp_p;


/***************************************************************************** 
* Defination
*****************************************************************************/
#define MMI_OPP_LOG(x) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);

#define MMI_OPP_LOG1(x, x1) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);

#define MMI_OPP_LOG2(x, x1, x2) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#endif /* __OPP_MMI_SCR_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 

