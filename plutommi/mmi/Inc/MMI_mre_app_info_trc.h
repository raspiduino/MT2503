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
 *  MMI_mre_app_info_trc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_MRE_APP_INFO_TRC_H_
#define _MMI_MRE_APP_INFO_TRC_H_

/* for generate PS trace definition */
#include "kal_trace.h"


#define MMI_MRE_APP_TRC_FUNC           TRACE_FUNC
#define MMI_MRE_APP_TRC_STATE          TRACE_STATE
#define MMI_MRE_APP_TRC_INFO           TRACE_INFO
#define MMI_MRE_APP_TRC_WARNING        TRACE_WARNING
#define MMI_MRE_APP_TRC_ERROR          TRACE_ERROR

#define MMI_MRE_APP_TRC_G1         TRACE_GROUP_1
#define MMI_MRE_APP_TRC_G2         TRACE_GROUP_2
#define MMI_MRE_APP_TRC_G3         TRACE_GROUP_3
#define MMI_MRE_APP_TRC_G4      	TRACE_GROUP_4
#define MMI_MRE_APP_TRC_G5         TRACE_GROUP_5
#define MMI_MRE_APP_TRC_G6  		TRACE_GROUP_6
#define MMI_MRE_APP_TRC_G7	      	TRACE_GROUP_7
#define MMI_MRE_APP_TRC_G8        	TRACE_GROUP_8
#define MMI_MRE_APP_TRC_G9    		TRACE_GROUP_9
#define MMI_MRE_APP_TRC_G10       	TRACE_GROUP_10
#define MAX_MRE_APP_TRACE_LOG_TYPE	(MMI_MRE_TRC_G10+1)


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "MMI_mre_app_info_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

/* For MOD_MRE_APP_INFO */
BEGIN_TRACE_MAP(MOD_MRE_APP_INFO)

   /*****************************************************************************************************************
     * MMI MRE APP INFO trace
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_MRE_APP_INFO, "%d:%d:%d:%d:%d")
   

END_TRACE_MAP(MOD_MRE_APP_INFO)

#endif /* _MMI_MRE_APP_INFO_TRC_H_ */




