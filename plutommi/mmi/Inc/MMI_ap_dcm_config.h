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
 *     MMI_dcm_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define which mmi ap DCM should on/off
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================




 ****************************************************************************/
#ifndef __MMI_AP_DCM_CONFIG__
#define __MMI_AP_DCM_CONFIG__

#include "MMIDataType.h"
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_features.h"
#include "dcmgr.h"

/* you can mark the following define to turn off same Aps using DCM */
#define __MMI_AP_DCM_CAMIMGV__
#define __MMI_AP_DCM_VDOREC__
#define __MMI_AP_DCM_CLNDR__
#define __MMI_AP_DCM_CALC__

#if !defined (__MMI_VIDEO_STREAM__) && !defined (__MMI_VIDEO_PDL__)
#define __MMI_AP_DCM_VDOPLY__
#endif

#define __MMI_AP_DCM_MATV__

#if !defined (__MMI_UCM__)
#define __MMI_AP_DCM_SNDREC__
#endif

#define __MMI_AP_DCM_PROFILE__

#define __MMI_AP_DCM_CALLSET__

#ifndef __MMI_SCREEN_LOCK_ANY_TIME__
#define __MMI_AP_DCM_SCRLOCK__
#endif

#define __MMI_AP_DCM_SECSET__
#define __MMI_AP_DCM_SETTING__

#if !defined (__MMI_CCA_SUPPORT__) && defined(__MMI_DTCNT_XML_SLIM__) 
#define __MMI_AP_DCM_DTCNT__
#endif

#if defined (__MMI_SLIM_ENGINEER_MODE__)
#define __MMI_AP_DCM_EM__
#endif

#if defined (__MMI_SLIM_FACTORY_MODE__)
#define __MMI_AP_DCM_FM__
#endif


/*for mmi ap DCM debug, you can use this define to add kal_prompt_trace */
#define __MMI_AP_DCM_DEBUG__

#endif /* __DCM_WITH_COMPRESSION_MMI_AP__ */


void mmi_ap_send_dcm_load_evt(S32 region_id);
void mmi_ap_send_dcm_unload_evt(S32 region_id);
void mmi_ap_post_dcm_unload_evt(S32 region_id);

#endif /* __MMI_AP_DCM_CONFIG__ */


