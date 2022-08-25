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
 *    pki_struct.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    PKI exported services
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef PKI_STRUCT_H
#define PKI_STRUCT_H

#include "pki_defs.h"

#if !defined(OSSL_PKI_INT_INCLUDES_H) && !defined(PKI_INT_INCLUDES_H)
/* This is a dummy pki context for application to use the PKI service */
typedef struct pki_context_struct pki_context_struct;

/* This is a dummy pki x509 operation context for application to use the PKI service */
typedef struct pki_x509_struct pki_x509_struct;

/* This is a dummy pki PKCS7 decoding context for application to use the PKI service */
typedef struct pki_pkcs7dec_struct pki_pkcs7dec_struct;

/* This is a dummy pki PKCS8 key operation context for application to use the PKI service */
typedef struct pki_pkcs8key_struct pki_pkcs8key_struct;

/* This is a dummy pki encrypted PKCS8 key operation context for application to use the PKI service */
typedef struct pki_pkcs8enckey_struct pki_pkcs8enckey_struct;

/* This is a dummy pki PKCS12 decoding context for application to use the PKI service */
typedef struct pki_pkcs12dec_struct pki_pkcs12dec_struct;

/* This is a dummy pki safe content structure defined in PKCS12 spec for application to use the PKI service */
typedef struct pki_safecntdec_struct pki_safecntdec_struct;

/* This is a dummy pki safe bag structure defined in PKCS12 spec for application to use the PKI service */
typedef struct pki_safebagdec_struct pki_safebagdec_struct;

/* This is a dummy pki public key structure for application to use the PKI service */
typedef struct pki_pubkey_struct pki_pubkey_struct;

/* This is a dummy pki private key structure for application to use the PKI service */
typedef struct pki_privkey_struct pki_privkey_struct;

/* This is a dummy pki certificate chain validation operation context for application to use the PKI service */
typedef struct pki_validate_struct pki_validate_struct;

#ifdef PKI_PKCS_EXORT
typedef struct pki_pkcs7enc_struct pki_pkcs7enc_struct;
typedef struct pki_pkcs12enc_struct pki_pkcs12enc_struct;
typedef struct pki_safecntenc_struct pki_safecntenc_struct;
typedef struct pki_safebagenc_struct pki_safebagenc_struct;
#endif /* PKI_PKCS_EXORT */

#endif  /* ! OSSL_PKI_INT_INCLUDES_H || PKI_INT_INCLUDES_H */

/* This is a x509 name structure in PKI adaptation layer */
typedef struct
{
    void            *der;               /* the DER raw data in specified certificate */
    kal_uint32      size;               /* the name der length */
    char            *names[PKI_NAMETYPE_TOTAL]; /* the parsed name string pointer array */
    pki_dcs_enum    dcs[PKI_NAMETYPE_TOTAL];    /* corresponding encoding scheme of each name string */
} pki_name_struct;

#endif  /* PKI_STRUCT_H */
