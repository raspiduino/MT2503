/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   custpack_certs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating Obigo preinstalled root certs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CUSTPACK_CERTS_H
#define CUSTPACK_CERTS_H

#include "kal_general_types.h"

#ifdef __OP11_PRESET_ROOT_CERTS__
/* under construction !*/
#elif defined (__OP12_PRESET_ROOT_CERTS__)
#define NUMBER_OF_CERTIFICATES 13
#elif !defined (WAP_SEC_SUPPORT) && !defined(__CERTMAN_SUPPORT__)
#define NUMBER_OF_CERTIFICATES 0
#else
#ifndef WAP2_HTTP
#define NUMBER_OF_CERTIFICATES 10
#else
#define NUMBER_OF_CERTIFICATES 5
#endif
#endif /* __OP1X_PRESET_ROOT_CERTS__ */

#define CERT_FORMAT_X509            (0)
#define CERT_FORMAT_WTLS            (1)

#define CERT_DOMAIN_MANUFACTURE     (0)
#define CERT_DOMAIN_OPERATOR        (1)
#define CERT_DOMAIN_3RD_PARTY       (2)

#define CERT_READ_ONLY_OFF          (0)
#define CERT_READ_ONLY_ON           (1)

#define CUSTPACK_CFG_MAX_CERTS_NUM  (30)

#define CUSTPACK_CFG_CERTMAN_WAIT_BOOTUP  2000

#define CERTMAN_NUM_CERT_IN_DATABASE    (CUSTPACK_CFG_MAX_CERTS_NUM + CUSTPACK_CFG_MAX_JAVA_CERTS_NUM + 10)	/* max number of certificates in certman database */

extern unsigned int certman_cfg_get_max_certs_num(void);


typedef struct certificate_st
{
    const unsigned char *cert;
    unsigned long cert_len;
    unsigned char format;
    unsigned char domain;
    unsigned char read_only;
} certificate_struct;

typedef struct custpack_root_ca_header_st
{
    unsigned int num_certs;
#if NUMBER_OF_CERTIFICATES == 0
    certificate_struct certs[1];
#else
    certificate_struct certs[NUMBER_OF_CERTIFICATES];
#endif
} custpack_root_ca_header_struct;


extern const custpack_root_ca_header_struct custpack_root_ca;

#ifndef EMPTY_MMI
extern custpack_root_ca_header_struct* resource_root_ca;
#else
extern const custpack_root_ca_header_struct* resource_root_ca;
#endif

extern kal_wchar* certman_get_java_tck_folder(void);
extern kal_wchar* certman_get_java_tck_verify_path(void);

extern int is_java_available(void);
extern int is_java_slim_support_on(void);
extern int certman_cfg_get_bootup_wait_time(void);

#endif /* CUSTPACK_CERTS_H */
