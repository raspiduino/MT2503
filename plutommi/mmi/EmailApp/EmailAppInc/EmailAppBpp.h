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
 *  EmailAppBPP.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email bpp function.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EMAILAPPBPP_H__
#define __EMAILAPPBPP_H__

#include "emailsrvgprot.h"
#include "MMIDataType.h"

#define MMI_EMAIL_BPP_COMPOSE_BUF_SIZE  (2048)
#define MMI_EMAIL_BPP_ENCODE_CONT_LEN   (300)

typedef enum
{
    EMAIL_BPP_CONNECTION_LOST = -127,
    EMAIL_BPP_COMPOSE_FAILED,
    EMAIL_BPP_PRINT_CANCEL,

    EMAIL_BPP_HALF_DONE = -3,
    EMAIL_BPP_ERR_DISK_FULL = -2,
    EMAIL_BPP_ERROR = -1,
    EMAIL_BPP_SUCCESS = 0,
    EMAIL_BPP_ROTATE_PAPER,
    EMAIL_BPP_CONTINUE
} email_bpp_ret_code_enum;

typedef enum
{
    MMI_EMAIL_BPP_FROM,
    MMI_EMAIL_BPP_TIME,
    MMI_EMAIL_BPP_PRIORITY,
    MMI_EMAIL_BPP_TO,
    MMI_EMAIL_BPP_CC,
    MMI_EMAIL_BPP_BCC,
    MMI_EMAIL_BPP_SUBJECT,
    MMI_EMAIL_BPP_FIELD_TOTAL
} mmi_email_bpp_field_enum;

typedef struct
{
    EMAIL_ACCT_ID account_id;
    EMAIL_FLDR_ID folder_id;
    EMAIL_MSG_ID msg_id;
} mmi_email_bpp_mail_struct;

typedef struct
{
    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_MSG_HANDLE msg_handle;
    mmi_id bpp_group_id;
    mmi_email_bpp_mail_struct mail;
    srv_email_msg_get_basic_info_struct msg_basic_info;
} mmi_email_bpp_cntx_struct;

extern void mmi_email_bpp_print(mmi_id parent_id, mmi_email_bpp_mail_struct *p_mail_struct);

#endif /* __EMAILAPPBPP_H__ */
