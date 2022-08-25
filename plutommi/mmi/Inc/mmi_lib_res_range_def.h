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
 *  mmi_lib_res_range_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for MMI App Resource Define that will be released as library
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*******************************************************************************/

/****************************************************************************
* WAP module
*****************************************************************************/
MMI_RES_DECLARE(APP_WAP, 1500, "")
#define WAP_BASE                  ((U16) GET_RESOURCE_BASE(APP_WAP))
#define WAP_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_WAP))


/****************************************************************************
* MRE module
*****************************************************************************/
MMI_RES_DECLARE(APP_MRE, 100, "..\\mre\\res\\")
#define MRE_BASE                  ((U16) GET_RESOURCE_BASE(APP_MRE))
#define MRE_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_MRE))

MMI_RES_DECLARE(APP_MRE_BG, 10, "..\\mre\\res\\")
#define MRE_BG_BASE                  ((U16) GET_RESOURCE_BASE(APP_MRE_BG))
#define MRE_BG_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_MRE_BG))

/****************************************************************************
* SNS module
*****************************************************************************/
MMI_RES_DECLARE(VAPP_SNS, 200, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_BASE                     ((U16) GET_RESOURCE_BASE(VAPP_SNS))
#define COSMOS_SNS_BASE_MAX                 ((U16) GET_RESOURCE_MAX(VAPP_SNS))

MMI_RES_DECLARE(VAPP_SNS_PLUGIN, 5, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_PLUGIN_BASE              ((U16) GET_RESOURCE_BASE(VAPP_SNS_PLUGIN))
#define COSMOS_SNS_PLUGIN_BASE_MAX          ((U16) GET_RESOURCE_MAX(VAPP_SNS_PLUGIN))

MMI_RES_DECLARE(VAPP_SNS_BG, 5, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_BG_BASE                  ((U16) GET_RESOURCE_BASE(VAPP_SNS_BG))
#define COSMOS_SNS_BG_BASE_MAX              ((U16) GET_RESOURCE_MAX(VAPP_SNS_BG))

MMI_RES_DECLARE(VCUI_SNS_UPLOAD_PIC, 20, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_UPLOAD_PIC_BASE          ((U16) GET_RESOURCE_BASE(VCUI_SNS_UPLOAD_PIC))
#define COSMOS_SNS_UPLOAD_PIC_MAX           ((U16) GET_RESOURCE_MAX(VCUI_SNS_UPLOAD_PIC))

MMI_RES_DECLARE(VCUI_SNS_SLIM_UPLOAD_PIC, 10, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_SLIM_UPLOAD_PIC_BASE     ((U16) GET_RESOURCE_BASE(VCUI_SNS_SLIM_UPLOAD_PIC))
#define COSMOS_SNS_SLIM_UPLOAD_PIC_MAX      ((U16) GET_RESOURCE_MAX(VCUI_SNS_SLIM_UPLOAD_PIC))

MMI_RES_DECLARE(VCUI_SNS_CONTACTS_PICKER, 20, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_CONTACTS_PICKER_BASE     ((U16) GET_RESOURCE_BASE(VCUI_SNS_CONTACTS_PICKER))
#define COSMOS_SNS_CONTACTS_PICKER_MAX      ((U16) GET_RESOURCE_MAX(VCUI_SNS_CONTACTS_PICKER))

MMI_RES_DECLARE(VCUI_SNS_MSG_COMPOSER, 10, "..\\venusmmi\\app\\Cosmos\\SNS\\res\\")
#define COSMOS_SNS_MSG_COMPOSER_BASE        ((U16) GET_RESOURCE_BASE(VCUI_SNS_MSG_COMPOSER))
#define COSMOS_SNS_MSG_COMPOSER_MAX         ((U16) GET_RESOURCE_MAX(VCUI_SNS_MSG_COMPOSER))

MMI_RES_DECLARE(VAPP_WIDGET_SNS_COSMOS, 20, "..\\venusmmi\\app\\Cosmos\\SNS\\Widget\\res\\")
#define COSMOS_SNS_WIDGET_BASE        ((U16) GET_RESOURCE_BASE(VAPP_WIDGET_SNS_COSMOS))
#define COSMOS_SNS_WIDGET_MAX         ((U16) GET_RESOURCE_MAX(VAPP_WIDGET_SNS_COSMOS))

MMI_RES_DECLARE(VAPP_WIDGET_SNS_DUMMY, 10, "..\\venusmmi\\app\\Cosmos\\SNS\\Widget\\res\\")
#define COSMOS_SNS_WIDGET_DUMMY_BASE        ((U16) GET_RESOURCE_BASE(VAPP_WIDGET_SNS_DUMMY))
#define COSMOS_SNS_WIDGET_DUMMY_MAX         ((U16) GET_RESOURCE_MAX(VAPP_WIDGET_SNS_DUMMY))

/****************************************************************************
* SNS Service
******************************************************************************/
MMI_RES_DECLARE(SRV_SNS, 16, ".\\Service\\SnsSrv\\")
#define SNS_SRV_BASE              ((U16) GET_RESOURCE_BASE(SRV_SNS))
#define SNS_SRV_BASE_MAX          ((U16) GET_RESOURCE_MAX(SRV_SNS))

/****************************************************************************
* SSO Service
******************************************************************************/
MMI_RES_DECLARE(SRV_SSO, 8, ".\\Service\\SsoSrv\\")
#define SSO_SRV_BASE              ((U16) GET_RESOURCE_BASE(SRV_SSO))
#define SSO_SRV_BASE_MAX          ((U16) GET_RESOURCE_MAX(SRV_SSO))

/******************************************************************************
* Cloud Service
*******************************************************************************/
MMI_RES_DECLARE(SRV_BACKUP_RESTORE, 100, ".\\Service\\CloudSrv\\res\\")
#define SRV_BACKUP_RESTORE_BASE             ((U16) GET_RESOURCE_BASE(SRV_BACKUP_RESTORE))
#define SRV_BACKUP_RESTORE_MAX              ((U16) GET_RESOURCE_MAX(SRV_BACKUP_RESTORE))

/******************************************************************************
* Google Search
*******************************************************************************/
MMI_RES_DECLARE(VAPP_GOOGLE_SEARCH, 10, "..\\venusmmi\\app\\Cosmos\\WidgetGoogleSearch\\res\\")

