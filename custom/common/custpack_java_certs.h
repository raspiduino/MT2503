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
 *   custpack_java_certs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating JAVA preinstalled root certs
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CUSTPACK_JAVA_CERTS_H
#define CUSTPACK_JAVA_CERTS_H

#include "custpack_certs.h"

/* Number of system default java root ca certs */
#define NUMBER_OF_JAVA_ROOT_CA_CERTS    (4)

/* Tha maximum number of preinstall java root ca certs */
#define CUSTPACK_CFG_MAX_JAVA_CERTS_NUM (10)

#define CUSTPACK_MAX_DOMAIN_NAME        (64)

#define MAX_TCK_CERTS_NUM    (3)

/* Java current support domain name */
/* Third party domain name */
#define CUSTPACK_J2ME_CA_3RD_DOMAIN "3rd-dmn"

/* operator domain name (trusted) */
#define CUSTPACK_J2ME_CA_OPERATOR_DOMAIN "trusted"

/* manufacturer domain name */
#define CUSTPACK_J2ME_CA_MANUFACTURER_DOMAIN "manufacturer"

/* java custpack root ca certs struct */
typedef struct custpack_java_root_ca_header_st
{
    unsigned int num_certs;         /* the number of preinstall certs in java certs custpack */
    certificate_struct certs[NUMBER_OF_JAVA_ROOT_CA_CERTS]; /* preinstall certs array */
} custpack_java_root_ca_header_struct;

/* default java root ca certs array */
extern const custpack_java_root_ca_header_struct custpack_java_root_ca;

#ifndef EMPTY_MMI
/* reference of custpack java root ca certs array */
extern custpack_java_root_ca_header_struct* resource_java_root_ca;
#else
/* reference of custpack java root ca certs array */
extern const custpack_java_root_ca_header_struct* resource_java_root_ca;
#endif

extern unsigned int certman_cfg_get_max_java_certs_num(void);

#endif /* CUSTPACK_JAVA_CERTS_H */
