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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMIResDef.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 *  This file is contains enums for screen, image and strings.
 *
 * Author:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
************************************************************************************/

#ifdef __PLUTO_MMI_PACKAGE__ 
#ifndef MMI_CERTMAN_RES_DEF_H
#define MMI_CERTMAN_RES_DEF_H

#ifdef __CERTMAN_SUPPORT__

typedef enum
{
    MMI_CERTMAN_CHILD_AUTH_CERT,
    MMI_CERTMAN_CHILD_USER_CERT,
#ifdef __OCSP_SUPPORT__
    MMI_CERTMAN_CHILD_OCSP_SUPPORT,
#endif /*__OCSP_SUPPORT__*/
    MMI_CERTMAN_CHILD_END
}mmi_certman_child_enum;

typedef enum
{
    /* Import */
    GRP_ID_CERTMAN_LAUNCH = MMI_CERTMAN_BASE + 1,
    GRP_ID_CERTMAN_SELECT,
    GRP_ID_CERTMAN_VIEW,
    GRP_ID_CERTMAN_INVALID,
    GRP_ID_CERTMAN_IMPORT,
    GRP_ID_CERTMAN_SELECT_USER,
    GRP_ID_CERTMAN_PRIV_KEY,
    SCR_ID_CERTMAN_GET_DECR_PWD,
    SCR_ID_CERTMAN_FILE_INFO,
    SCR_ID_CERTMAN_CERTIFICATE_DETAILS,
    SCR_ID_CERTMAN_CERTIFICATE_INPUTS,
    SCR_ID_CERTMAN_CERTIFICATE_KEY_USAGES,
    /* Import */

    /* Launch */

    SCR_ID_CERTMAN_CERTIFICATE_GROUPS,
    SCR_ID_CERTMAN_CERTIFICATE_LIST,
    SCR_ID_CERTMAN_CERTIFICATE_OPTIONS,
    SCR_ID_CERTMAN_CERTIFICATE_VIEW,
    SCR_ID_CERTMAN_CERTIFICATE_SET_KEY_USAGES,
    /* Launch */

    /* Select */
    SCR_ID_CERTMAN_SELECT_CERTIFICATE,
    /* private key protection */
    SCR_ID_CERTMAN_PRIVKEY_PASSWORD,
    /* View certificate contents only */
    SCR_ID_CERTMAN_VIEW_CERTIFICATE_CONTENTS,
    SCR_ID_CERTMAN_INVALID_CERT_OPTION,
    SCR_ID_CERTMAN_INVALID_CERT_LABEL,
    SCR_ID_CERTMAN_USER_CERTIFICATE_LIST_BY_ISSUER,
    SCR_ID_CERTMAN_PROGRESS_SCREEN,
    SCR_ID_CERTMAN_FULL_SCREEN_POPUP,
    SCR_ID_CERTMAN_GENERAL_POPUP_SCREEN,
    SCR_ID_CERTMAN_POPUP,
    SCR_ID_CERTMAN_CONFIRM_SCREEN,
    SCR_ID_CERTMAN_EDITOR_OPTION,
#ifdef __OCSP_SUPPORT__
    SCR_ID_CERTMAN_CERT_VALIDATION,
#endif /*__OCSP_SUPPORT__*/
    SCR_ID_CERTMAN_DUMMY_SCREEN,
    /* add new screen ID above this line */
    SCR_ID_CERTMAN_END
} MMI_CERTMAN_SCR_IDS;


#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* MMI_CERTMAN_RES_DEF_H */ 
#endif /* __PLUTO_MMI_PACKAGE__ */
