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
 *   ResCacheUtil.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   helpers for resource compression.
 *
 * 
 *
 * Author:
 * -------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "ResCacheUtil.h"

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
#include "simple_memory_manager.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "GlobalConstants.h"

#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
#include "ResCache.h"
#endif //#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__


// DEMO and UT only: SIMPLY CACHE IMPLEMENTATION
#ifdef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
static RES_CACHE_HANDLE_T SimpleCreateResObjectCache(U32 sizeInBytes);
static S8 * SimpleRetriveResObjectFromCache(RES_CACHE_HANDLE_T cachePool, U16 objectId);
static S8 * SimplePrepareResObjectInCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, U32 objectSize);
static MMI_BOOL SimpleSaveResObjectToCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, S8 * objectData, U32 objectSize);
static MMI_BOOL SimpleSetObjectFlushable(RES_CACHE_HANDLE_T cachePool, U16 objectId, BOOL isFlushable);
static MMI_BOOL SimpleFlushCacheForce(RES_CACHE_HANDLE_T cachePool);
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__

RES_CACHE_HANDLE_T CreateResObjectCache(U32 sizeInBytes)
{
#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    return RscCreateResObjectCache(sizeInBytes);
#else
    return SimpleCreateResObjectCache(sizeInBytes); // UT only
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__

}

S8 * RetriveResObjectFromCache(RES_CACHE_HANDLE_T cachePool, U16 objectId)
{

#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    U32 returnAddr = (U32)(RscRetrieveResObjectFromCache(cachePool, objectId));
    if(returnAddr == NULL){
        return NULL;
    }else{
        // All object is 4 byte aligned
        returnAddr = ((returnAddr + 4) /4) * 4;
        return (S8 *)returnAddr;
    }
#else
    U32 returnAddr = (U32)SimpleRetriveResObjectFromCache(cachePool, objectId);
    // All object is 4 byte aligned
    if(returnAddr == NULL){
        return NULL;
    }else{
        returnAddr = ((returnAddr + 4) /4) * 4;
        return (S8 *)returnAddr;
    }
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
}

S8 * PrepareResObjectInCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, U32 objectSize)
{
    U32 returnAddr = NULL;
#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    returnAddr = (U32)RscPrepareResObjectInCache(cachePool, objectId, objectSize + 4 );
#else
    returnAddr =  (U32)SimplePrepareResObjectInCache(cachePool, objectId, objectSize + 4);
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    // All object is 4 byte aligned
    if(returnAddr == NULL){
        return NULL;
    }else{
        returnAddr = ((returnAddr + 4) /4) * 4;
        return (S8 *)returnAddr;
    }
}

MMI_BOOL SaveResObjectToCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, S8 * objectData, U32 objectSize)
{
#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    return (MMI_BOOL)RscSaveResObjectToCache(cachePool, objectId, objectData, objectSize);
#else
    return SimpleSaveResObjectToCache(cachePool,objectId,objectData, objectSize);
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
}


MMI_BOOL SetObjectFlushable(RES_CACHE_HANDLE_T cachePool, U16 objectId, MMI_BOOL isFlushable)
{
#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    return (MMI_BOOL)RscSetObjectFlushable(cachePool, objectId, isFlushable);
#else
    return SimpleSetObjectFlushable(cachePool, objectId, isFlushable);
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
}

MMI_BOOL FlushCacheForce(RES_CACHE_HANDLE_T cachePool)
{
#ifndef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
    return (MMI_BOOL)RscFlushCacheForce(cachePool);
#else
    return SimpleFlushCacheForce(cachePool);
#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
}



// DEMO and UT only: SIMPLY CACHE IMPLEMENTATION
// -- Simple Cache APIs, objectId is simply the group id
#ifdef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__
extern const unsigned short mtk_CurrMaxGroupsNum;
extern const CUSTOM_IMAGE mtk_nCustGroupCacheNames[];

RES_CACHE_HANDLE_T SimpleCreateResObjectCache(U32 sizeInBytes)
{
    U16 i = 0;
    for(i=0; i<mtk_CurrMaxGroupsNum; i++)
    {
        U8 * marker = mtk_nCustGroupCacheNames[i].pImage;
        *marker = 0xFF;
        *(marker+1) = 0xFF;
        *(marker+2) = 0xFF;
        *(marker+3) = 0xFF;
    }
    return 0;
}


S8 * SimpleRetriveResObjectFromCache(RES_CACHE_HANDLE_T cachePool, U16 objectId)
{
    U8 * marker = mtk_nCustGroupCacheNames[objectId].pImage;
    if(*marker == 0xFF && *(marker+1) == 0xFF && *(marker+2) == 0xFF && *(marker+3) == 0xFF){
        return NULL;
    }else{
        return marker;
    }
}

S8 * SimplePrepareResObjectInCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, U32 objectSize)
{

    return (S8 *)mtk_nCustGroupCacheNames[objectId].pImage;
}

MMI_BOOL SimpleSaveResObjectToCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, S8 * objectData, U32 objectSize)
{
    U8 * marker = mtk_nCustGroupCacheNames[objectId].pImage;
    memcpy((void*)marker, (void*)objectData,objectSize);
    return MMI_TRUE;

}


MMI_BOOL SimpleSetObjectFlushable(RES_CACHE_HANDLE_T cachePtr, U16 objectId, BOOL isFlushable)
{
    return MMI_TRUE;

}

MMI_BOOL SimpleFlushCacheForce(RES_CACHE_HANDLE_T cachePtr)
{
    return MMI_TRUE;
}

#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__


#endif //__MMI_IMAGE_GROUP_COMPRESS__
