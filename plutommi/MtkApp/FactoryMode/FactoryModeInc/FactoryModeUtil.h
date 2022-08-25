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
 *  EngineerModeUtil.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode util header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FM_UTIL_H
#define MMI_FM_UTIL_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "MMIDataType.h"

 /***************************************************************************** 
 * Define
 *****************************************************************************/
 
 /***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#ifdef __DCM_WITH_COMPRESSION_MMI_POOL_A__ 
#define COSMOS_FM_DCM_TIMERID 100
#define COSMOS_FM_DCM_TIMERDURATION 1
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__  */

#ifdef __MMI_FM_MERGE_AUTO_TEST__
    #ifndef __MMI_FM_PLUTO_6261_SLIM__
    #define __MMI_FM_PLUTO_6261_SLIM__
    #endif /* __MMI_FM_PLUTO_6261_SLIM__ */
#endif /* __MMI_FM_MERGE_AUTO_TEST__ */
//#define __SUPPORT_LED_FEATURE__
 
 /***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
extern MMI_ID g_fm_root_group_id;
 
 /***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void DeinitFactoryModeEvent(void);

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
extern void mmi_fm_send_dcm_unload_process(void);
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */


#if defined(__MMI_AP_DCM_FM__)
#define MMI_FM_DCM_LOAD_INTERNAL()    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_FM)
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#define MMI_FM_DCM_LOAD_INTERNAL()  if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_FM)== KAL_FALSE) \
                         { \
                               DCM_Load(DYNAMIC_CODE_COMPRESS_COSMOS_FM, 0,0); \
                         }
#else
#define MMI_FM_DCM_LOAD_INTERNAL()  
#endif /* __MMI_AP_DCM_FM__ */


#if defined(__MMI_AP_DCM_FM__)
#define MMI_FM_DCM_SEND_UNLOAD_INTERNAL()    if(MMI_FALSE == mmi_frm_app_is_launched(g_fm_gourp_id)) \
                                  { \
                                      mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_FM); \
                                  }
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#define MMI_FM_DCM_SEND_UNLOAD_INTERNAL()    if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_FM)== KAL_TRUE) \
                                  { \
                                      DCM_Unload(DYNAMIC_CODE_COMPRESS_COSMOS_FM); \
                                  }
#else
#define MMI_FM_DCM_SEND_UNLOAD_INTERNAL()  
#endif /* __MMI_AP_DCM_FM__ */


#if defined(__MMI_AP_DCM_FM__)
#define MMI_FM_DCM_POST_UNLOAD_INTERNAL()   DeinitFactoryModeEvent(); \
                                            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_FM)
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#define MMI_FM_DCM_POST_UNLOAD_INTERNAL()   DeinitFactoryModeEvent(); \
                                            StartTimer(COSMOS_FM_DCM_TIMERID, COSMOS_FM_DCM_TIMERDURATION, mmi_fm_send_dcm_unload_process)
#else
#define MMI_FM_DCM_POST_UNLOAD_INTERNAL()  
#endif /* __MMI_AP_DCM_FM__ */



#define MMI_FM_DCM_LOAD()           MMI_FM_DCM_LOAD_INTERNAL()
#define MMI_FM_DCM_SEND_UNLOAD()    MMI_FM_DCM_SEND_UNLOAD_INTERNAL()
#define MMI_FM_DCM_POST_UNLOAD()    MMI_FM_DCM_POST_UNLOAD_INTERNAL()


#endif /* MMI_FM_UTIL_H */
