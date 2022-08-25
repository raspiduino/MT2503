/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfc_internal.h
 *
 * Project:
 * --------
 *    MAUI/HAL/WFC
 *
 * Description:
 * ------------
 *    This file is the for WFC MM user
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 10 27 2011 yinli.liang
 * removed!
 * .
 *
 * 06 29 2011 bin.han
 * removed!
 * .
 *
 * 06 22 2011 bin.han
 * removed!
 * .
 *
 * 04 15 2011 bin.han
 * removed!
 * .
 *
 * 04 15 2011 bin.han
 * removed!
 * .
 *
 * 04 15 2011 bin.han
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WFC_MM_API_H__
#define __WFC_MM_API_H__

/******************************************************************************
 * Include directives
 ******************************************************************************/
#include <wfc\wfc.h>
#include <wfc\wfcext.h>

#include "common\owftypes.h"
#include "common\owfnativestream.h"
#include "common\owfimage.h"

#include "wfd\inc\wfd.h"


///for MM auto mode
typedef enum
{ WFC_COMMIT_CONTEXT                   = 0x1,
  WFC_COMMIT_ELEMENT                   = 0x2,
  WFC_COMMIT_CONTEXT_AND_ELEMENT       = (WFC_COMMIT_CONTEXT|WFC_COMMIT_ELEMENT),
  WFC_COMMIT_FORCE_32BIT               = 0x7FFFFFFF
} WFCMMCommitType;



// For MM user
WFC_API_CALL void WFC_APIENTRY
wfcMMSetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib,
                     WFCint value) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
wfcMMSetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      const WFCint *values) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
wfcMMSetElementAttribi(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib,
                     WFCint value) WFC_APIEXIT;
                     
WFC_API_CALL void WFC_APIENTRY
wfcMMSetElementAttribiv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      const WFCint *values) WFC_APIEXIT;

WFC_API_CALL WFCint WFC_APIENTRY
wfcMMGetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib)WFC_APIEXIT;

WFC_API_CALL void WFC_APIENTRY
wfcMMGetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      WFCint *values) WFC_APIEXIT;

WFC_API_CALL void WFC_APIENTRY
            wfcMMCommit(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCElement element, 
                      WFCMMCommitType commitType) WFC_APIEXIT;

WFC_API_CALL WFCboolean WFC_APIENTRY
            wfcMMCheckBusy(void) WFC_APIEXIT;
            
#endif /* __WFC_MM_API_H__ */

