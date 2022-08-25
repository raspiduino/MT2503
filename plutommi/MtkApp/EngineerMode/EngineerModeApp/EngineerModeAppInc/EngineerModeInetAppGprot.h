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
 * EngineerModeInetAppGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This header file is for those using the service provided by Engineering mode for Internet Application. 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ENGINEER_MODE_INET_GPROT_H
#define _ENGINEER_MODE_INET_GPROT_H

/****************************************************************************** 
 * Include
 ******************************************************************************/
#include "kal_general_types.h"

/***************************************************************************** 
 * Constant
 *****************************************************************************/ 


/****************************************************************************** 
 * Custom value
 ******************************************************************************/
    

/****************************************************************************** 
 * ENUM
 ******************************************************************************/

/* This enum is to specify the type of accept header */
typedef enum{
    MMI_EM_INET_ACCEPT_HEADER_WAP_1_2_1 = 0,  /* WAP 1.2.1 */
    MMI_EM_INET_ACCEPT_HEADER_WAP_2_0,        /* WAP 2.0 */
    MMI_EM_INET_ACCEPT_HEADER_WML,            /* WML */
    MMI_EM_INET_ACCEPT_HEADER_XHTML,          /* WHTML */
    MMI_EM_INET_ACCEPT_HEADER_HTML,           /* HTML */
    MMI_EM_INET_ACCEPT_HEADER_TOTAL           /* total number of setting */
} mmi_em_inet_accept_header_enum;

/* This enum is to specify MMS version */
typedef enum{
    MMI_EM_INET_MMS_VERSION_10 = 0,     /* MMS 1.0 */
    MMI_EM_INET_MMS_VERSION_11,         /* MMS 1.1 */
    MMI_EM_INET_MMS_VERSION_12,         /* MMS 1.2 */
    MMI_EM_INET_MMS_VERSION_TOTAL       /* total number of MMS version */
} mmi_em_inet_mms_version_enum;



/****************************************************************************** 
 * Typedef
 ******************************************************************************/

/****************************************************************************** 
 * External Variable
 ******************************************************************************/


/****************************************************************************** 
 * External Function
 ******************************************************************************/

#endif /* _ENGINEER_MODE_INET_GPROT_H */
