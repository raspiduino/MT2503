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
 *   tls_const.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constants defined for TLS.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TLS_CONST_H_
#define _TLS_CONST_H_

#include "ssl_consts.h"

/******************************************************************************
 * <GROUP Constants>
 *
 * Maximum number of concurrent supported global contexts.
 * Ref. tls_new_ctx().
******************************************************************************/
#define TLS_APP_COMMON_NUM 3

#if (!(defined OBIGO_Q03C_BROWSER ) &&(defined WAP_SEC_SUPPORT))
#define TLS_APP_WAP_NUM 1
#else
#define TLS_APP_WAP_NUM 0
#endif

#ifdef __EMAIL__
#define TLS_APP_EMAIL_NUM 1
#else
#define TLS_APP_EMAIL_NUM 0
#endif
    
typedef enum
{
        TLS_APP_NUM_SPARED = TLS_APP_COMMON_NUM,                                
        TLS_WAP_APP_NUM_END =  TLS_APP_NUM_SPARED + TLS_APP_WAP_NUM,  
        TLS_EMAIL_APP_NUM_END = TLS_WAP_APP_NUM_END + TLS_APP_EMAIL_NUM,    

        TLS_MAX_GLOBAL_CTX = TLS_EMAIL_APP_NUM_END               
} tls_max_app_num_enum;


/******************************************************************************
 * <GROUP Constants>
 *
 * Maximum number of available ciphers.
 * Ref. tls_set_ciphers().
******************************************************************************/
#define TLS_MAX_CIPHERS             (MAX_CIPHER_NUM)



/******************************************************************************
 * <GROUP Constants>
 *
 * Limitation of processing certificate types in a certificate request message
 * from server.
 * Ref . app_tls_client_auth_ind_struct.
 ******************************************************************************/
#define TLS_MAX_CLIENT_AUTH         (7)



/******************************************************************************
 * <GROUP Constants>
 *
 * Special identifier to load all trusted certifictes in the system.
 * Ref. tls_set_verify().
******************************************************************************/
#define TLS_ALL_ROOT_CERTS          (0xFF)

#endif /* !_TLS_CONST_H_ */


