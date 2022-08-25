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
 * applib_asn_uper_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is header file for UPER Common function.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined _UPER_COMMON_H_
#define _UPER_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif



#include "applib_asn_common.h"
//#include "applib_asn_memory.h"
#include "applib_mtkasn_global.h"

///changshun add for RHR
#include "kal_general_types.h"
///


extern   void   applib_UperEncodeOID(applib_AsnContext *pContext,  applib_OID *pOid);
extern   void   applib_UperDecodeOID(applib_AsnContext *pContext,  applib_OID *pOid);
extern   void	applib_UperEncodeOpenType(applib_AsnContext *pContext,  U8 * pData, U32 uSize);
extern   U32	applib_UperDecodeOpenTypeLength(applib_AsnContext *pContext);
extern   U32	applib_UperDecodeOpenType(applib_AsnContext *pContext,  U8 * pData, U32 uSize);

extern   void   applib_UperPutNonConstraintNumber(applib_AsnContext *pContext,  S32 uNum);
extern   S32    applib_UperGetNonConstraintNumber(applib_AsnContext *pContext);

extern   U32    applib_UperPutLengthValue(applib_AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen);
extern   U32	applib_UperGetLengthValue(applib_AsnContext *pContext, U32 lBound, U32 uBound);

extern   void   applib_UperPutSmallNumber(applib_AsnContext *pContext, U32 uNum);
extern   U32	applib_UperGetSmallNumber(applib_AsnContext *pContext);

extern   void   applib_UperPutSemiConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uNum);
extern   S32	applib_UperGetSemiConstraintNumber(applib_AsnContext *pContext, S32 lBound);

extern   void   applib_UperPutWholeConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum);
extern   U32    applib_UperGetWholeConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uBound);

extern   void applib_UperEncodeGeneralString(applib_AsnContext *pContext,  applib_asn_GeneralString *pStr);
extern   void applib_UperEncodeBMPString(applib_AsnContext *pContext,  applib_asn_BMPString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet  *pAlphabet);
extern   void applib_UperEncodeNumericString(applib_AsnContext *pContext,  applib_asn_NumericString *pStr, U32 minSize, U32 maxSize, applib_ASN_OneByteAlphabet  *pAlphabet);
extern   void applib_UperDecodeNumericStringA(applib_AsnContext *pContext,  applib_asn_NumericString *pStr, U32 minSize, U32 maxSize, applib_ASN_OneByteAlphabet  *pAlphabet);
extern   void applib_UperDecodeBMPStringA(applib_AsnContext *pContext,  applib_asn_BMPString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet  *pAlphabet);
extern   void applib_UperDecodeGeneralStringA(applib_AsnContext *pContext,  applib_asn_GeneralString *pStr);
extern   void applib_UperDecodeChoiceUnKnowItem(applib_AsnContext *pContext, applib_ChoiceUnKnow *pUnKnowItem);
extern   void applib_UperDecodeSequcenceUnKnowItem(applib_AsnContext* pContext,  applib_UnKnowExtensionItemArray *pArray, U32	uSize, Bool  *pIsItemExist);

#ifdef __cplusplus  
}
#endif

#endif //_UPER_COMMON_H_

