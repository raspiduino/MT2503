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
 *
 * Filename:
 * ---------
 * customer_email_num.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the E-mail maximum message number.
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _CUSTOMER_EMAIL_NUM_H_
#define _CUSTOMER_EMAIL_NUM_H_
#include "kal_general_types.h"

/* The max email address length. It should not less than SRV_SSO_NAME_SIZE
 * (defined in plutommi\service\inc\SsoSrvGprot.h) when __MMI_SSO__ is turned on.
 */
#define MMI_EMAIL_MAX_ADDR_LEN      (64)

/* Attachments related config */
/* Maximum message size could receive, 14014KB is 10MB attachments' encoded size */
#define MMI_EMAIL_MAX_MSG_SIZE              (14014 * 1024)
#define MMI_EMAIL_MIN_MSG_SIZE              (0.5 * 1024)
/* Maximum message size could send */
#define MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE     (10240 * 1024)

#define MMI_EMAIL_MAX_REMOTE_FOLDER_NUM     (20)

#define MMI_EMAIL_MAX_ADDR_NUM              (30)

#ifdef __FLAVOR_EMAIL_ATTACHMENT_LIST__
#define MMI_EMAIL_MAX_ATTACH_NUMBER         (60)         /* The MAX of MAX is 60 */
#elif defined __FLAVOR_VF_LIVE_EMAIL_ATTACHMENT_LIST__
#define MMI_EMAIL_MAX_ATTACH_NUMBER         (60)         /* The MAX of MAX is 60 */
#else
#define MMI_EMAIL_MAX_ATTACH_NUMBER         (10)         /* The MAX of MAX is 60 */
#endif

#define MMI_EMAIL_MAX_ACCTS         (10)  /* Max number of accounts */
#define MMI_EMAIL_MAX_PUSH_ACCTS            (2)   /* Max number of push accounts */


#ifdef __MTK_INTERNAL__
    #ifdef __LOW_COST_SUPPORT_COMMON__
/* under construction !*/
    #else
/* under construction !*/
    #endif
#else
#define MMI_EMAIL_MAX_CONT_LEN_BY_K         (2)
#endif


/* this micro is determined by VcpViewer. Any revise, please contact FW's owner to double check */
#define MMI_EMAIL_MAX_CONT_MEM_SIZE         (MMI_EMAIL_MAX_CONT_LEN_BY_K * (2 + 32) * 1024)

kal_bool custom_email_using_card_memory(void);


#endif /* _CUSTOMER_EMAIL_NUM_H_ */
