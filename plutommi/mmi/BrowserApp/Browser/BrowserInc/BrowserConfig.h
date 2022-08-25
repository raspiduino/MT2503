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
 * BrowserConfig.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file various macros related to the Browser ASM memory configuration and
 *  for various other Browser features
 *
 * Author: Kamal Sharma
 * -------
 * -------
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

#ifndef BROWSERCONFIG_H
#define BROWSERCONFIG_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__


#ifdef OBIGO_Q05A
#include "custom_wap_config.h"
#endif /* OBIGO_Q05A */

#ifdef OBIGO_Q03C_BROWSER
    #include "wap_mem_cfg.h"
#endif /* OBIGO_Q03C_BROWSER */

#include "BrowserSrvConfig.h"

/* For the ASM pool size */
#ifdef OBIGO_Q05A
    #define BRW_SRV_POOL_SIZE WAP_CUSTOM_CFG_BROWSER_MEM_SIZE
    #define BRW_APP_POOL_SIZE SRV_BRW_APP_POOL_SIZE
    #define BROWSER_POOL_SIZE  (BRW_SRV_POOL_SIZE) + (BRW_APP_POOL_SIZE)
#endif /* OBIGO_Q05A */

#ifdef OBIGO_Q03C_BROWSER
    #define BRW_APP_POOL_SIZE SRV_BRW_APP_POOL_SIZE
    #define BRW_SRV_POOL_SIZE WAP_ASM_MEM_SIZE_TOTAL + WAP_MEM_WCACHE_SIZE
    #define BROWSER_POOL_SIZE  (BRW_SRV_POOL_SIZE + BRW_APP_POOL_SIZE)
#endif /* OBIGO_Q03C_BROWSER */


/* Stored pages macro */
#ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    #ifndef __MMI_BRW_STORED_PAGES_SUPPORT__
    #define __MMI_BRW_STORED_PAGES_SUPPORT__
    #endif
#endif

#ifdef __MMI_WAP_SPLASH_SCREEN_SUPPORT__
    #ifndef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    #define __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    #endif
#endif

/* The macros for the page size checking and the loading time checking feature */
#ifdef OBIGO_Q05A
#define __MMI_BRW_LOADING_TIME_CHECKING__
#define __MMI_BRW_PAGE_SIZE_CHECKING__
#endif /* OBIGO_Q05A */

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERCONFIG_H */ 

