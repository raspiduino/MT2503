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
 *   DevApp_ReadRes.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "string.h"
#include "GlobalMenuItems.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "FontDcl.h"
#ifdef __POPULATE_ENGINE_
#include "ExportMMIFunc.h"
#endif 


#include "CustResDef.h"
#include "Gui_Setting.h"
#include "PopulateRes.h"
#include "PlmnEnum.h"
#include "CustDataProts.h"
#include "taskinit.h"
#include "stdafx.h"
#include "buildcfg.h"
#include "fontdcl.h"
#include "SSCStringHandle.h"

extern U16 gCurrLangIndex;
extern const StringResList DevApp_gStringList[];
extern unsigned short DevApp_CurrMaxSearchImageId;
extern const CUSTOM_IMAGE_SEARCH_MAP DevApp_ImageIdSearchMap[];
extern const CUSTOM_IMAGE DevApp_nCustImageNames[];
extern const CUSTOM_IMAGE_MAP DevApp_ImageIdMap[];
extern unsigned short DevApp_CurrMaxSearchAudioId;
extern CUSTOM_AUDIO_SEARCH_MAP DevApp_AudioIdSearchMap[];
extern const CUSTOM_AUDIO DevApp_nCustAudioNames[];
extern const CUSTOM_AUDIO_MAP DevApp_AudioIdMap[];
extern const CUSTOM_MENU      DevApp_nCustMenus[];


#ifndef MMI_ASSERT
#define MMI_ASSERT(expr)      ASSERT(expr)
#endif /*MMI_ASSERT*/

#if defined(__DEVAPP_RESOURCE_OUTPUT__)

/*****************************************************************************
 * FUNCTION
 *  DevAppGetDevIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  StringId        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 DevAppGetDevIndex(U16 MenuId)
{
    if (DEVAPP_BASE < MenuId && MenuId < DEVAPP_BASE_MAX)
        return ((MenuId - DEVAPP_BASE - 1) + (MAX_MENU_ITEMS_VALUE - MENU_ID_DEVAPP_START + 1)); /* Index + offset */
    else if (AVK_BASE < MenuId && MenuId < AVK_BASE_MAX)
        return ((MenuId - AVK_BASE - 1) + (MAX_MENU_ITEMS_VALUE - MENU_ID_DEVAPP_START + 1) + (DEVAPP_BASE_MAX - DEVAPP_BASE)); /* Index + offset */
    else
        return (MenuId - MENU_ID_DEVAPP_START);
}

#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */



/*****************************************************************************
 * FUNCTION
 *  DevAppGetString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  StringId        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetString(U16 StringId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 nFirst = 0;
    S32 nLast = DevApp_gStringList[gCurrLangIndex].nTotalStrMapSearch;
    S32 nMid;
    CUSTOM_STRMAP_SEARCH *pStrMapSearch;
    CUSTOM_STRING *pStringRes;
    CUSTOM_STRING_MAP *pStringMapRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pStringRes = DevApp_gStringList[gCurrLangIndex].pStringRes;
    pStringMapRes = DevApp_gStringList[gCurrLangIndex].pStringMap;
    pStrMapSearch = DevApp_gStringList[gCurrLangIndex].pStrMapSearch;

    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((pStrMapSearch[nMid].nMinStrId <= StringId) && (pStrMapSearch[nMid].nMaxStrId >= StringId))
        {
            return (S8*) &pStringRes[(pStringMapRes
                            [((pStrMapSearch[nMid].nMapIndex) + (StringId) - (pStrMapSearch[nMid].nMinStrId))]) << 1];
        }
        if (StringId > pStrMapSearch[nMid].nMinStrId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return (S8*) "";
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetImage(U16 ImageId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = DevApp_CurrMaxSearchImageId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((DevApp_ImageIdSearchMap[nMid].minImageId <= ImageId) &&
            (DevApp_ImageIdSearchMap[nMid].maxImageId >= ImageId))
        {

            return (S8*)
                DevApp_nCustImageNames[DevApp_ImageIdMap
                                       [(DevApp_ImageIdSearchMap[nMid].index) + (ImageId) -
                                        (DevApp_ImageIdSearchMap[nMid].minImageId)].nImageNum].pImage;
        }
        if (ImageId > DevApp_ImageIdSearchMap[nMid].minImageId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetAudio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  AudioId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetAudio(U16 AudioId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = DevApp_CurrMaxSearchAudioId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((DevApp_AudioIdSearchMap[nMid].minAudioId <= AudioId) &&
            (DevApp_AudioIdSearchMap[nMid].maxAudioId >= AudioId))
        {
            return (S8*)
                DevApp_nCustAudioNames[DevApp_AudioIdMap
                                       [(DevApp_AudioIdSearchMap[nMid].index) + (AudioId) -
                                        (DevApp_AudioIdSearchMap[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > DevApp_AudioIdSearchMap[nMid].minAudioId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }
#endif /* #if defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return NULL;
}

/* under construction */


/*****************************************************************************
 * FUNCTION
 *  DevAppGetParentItemId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetParentItemId(U16 ItemId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nParentId;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetNumOfChild
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetNumOfChild(U16 ItemId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nNumofMenuItem;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetStringIdOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetStringIdOfItem(U16 ItemId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nStrId;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetImageIdOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetImageIdOfItem(U16 ItemId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nImageId;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetDispAttributeOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetDispAttributeOfItem(U16 ItemId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nDispAttribute;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemId(U16 ParentItemId, U16 Seq)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[Seq];
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemStringId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemStringId(U16 ParentItemId, U16 Seq)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevAppGetStringIdOfItem((U16)(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[Seq] + MENU_ID_DEVAPP_START));
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemImageId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemImageId(U16 ParentItemId, U16 Seq)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetImageIdOfItem((U16)(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[Seq] + MENU_ID_DEVAPP_START));
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceItemIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ItemIds             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceItemIds(U16 ParentItemId, U16 *ItemIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        ItemIds[j] = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceStringIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringIds           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceStringIds(U16 ParentItemId, U16 *StringIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        StringIds[j] = GetStringIdOfItem(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j]);
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetIndexOfStringId
 * DESCRIPTION
 *  Function used to get MenuID by the given parent_item_id and String Id
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringId            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 DevAppGetIndexOfStringId(U16 ParentItemId, U16 StringId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        if (StringId == DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j])
        {
            return (U8) j;
        }
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceImageIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ImageIds            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceImageIds(U16 ParentItemId, U16 *ImageIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;
    U16 DevMenuID = DevAppGetDevIndex(ParentItemId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        ImageIds[j] = GetImageIdOfItem((U16)(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j] + MENU_ID_DEVAPP_START));
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************************
 ************************ New functions support hide and dim *****************************
 *****************************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  DevAppGetNumOfChild_Ext
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId considering MenuItemMask.
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  U16   Number of Childrens.
 *****************************************************************************/
U16 DevAppGetNumOfChild_Ext(U16 menu_item_id)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0, num_child;
    U8 i = 0;
    U16 DevMenuID = DevAppGetDevIndex(menu_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_child = DevApp_nCustMenus[DevMenuID].nNumofMenuItem;

    for (i = 0; i < num_child; i++)
    {
        if (!mmi_frm_test_menu_item_hide(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[i]))
        {
            count++;
        }
    }

    return count;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemId_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id & index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   item id
 *****************************************************************************/
U16 DevAppGetSeqItemId_Ext(U16 parent_item_id, U16 index)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, idx = 0;
    U16 item_id = 0;
    U8 child_count;
    U16 DevMenuID = DevAppGetDevIndex(parent_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    child_count = (U8) DevApp_nCustMenus[DevMenuID].nNumofMenuItem;

    for (i = 0; i < child_count; i++)
    {
        item_id = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[i];
        if (!mmi_frm_test_menu_item_hide(item_id))  /* the item is not hidden */
        {
            if (idx == index)
            {
                break;
            }
            else
            {
                idx++;
            }
        }
    }
    MMI_ASSERT(i < child_count);    /* all children are hidden */
    return item_id;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceItemIds_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ItemIds             [IN/OUT]        Array of the child menuitem id
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 DevAppGetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;
    U16 DevMenuID = DevAppGetDevIndex(parent_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        U16 item_id = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ItemIds[ret_idx++] = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];
        }
    }
    return ret_idx;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceStringIds_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  StringIds           [IN/OUT]        Array of string ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 DevAppGetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;
    U16 DevMenuID = DevAppGetDevIndex(parent_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        U16 item_id = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            StringIds[ret_idx++] = DevAppGetStringIdOfItem(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceImageIds_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ImageIds            [IN/OUT]        Array of image ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 DevAppGetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;
    U16 DevMenuID = DevAppGetDevIndex(parent_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        U16 item_id = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ImageIds[ret_idx++] = DevAppGetImageIdOfItem(DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
#else /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return 0;
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetIndexOfStringId_Ext
 * DESCRIPTION
 *  Function used to get MenuID by the given parent_item_id and String Id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  StringId            [IN]        Id of the string
 * RETURNS
 *  U8 index
 *****************************************************************************/
U8 DevAppGetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;
    U16 DevMenuID = DevAppGetDevIndex(parent_item_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[DevMenuID].nNumofMenuItem; j++)
    {
        U16 item_id = DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            if (StringId == DevApp_nCustMenus[DevMenuID].nOrderMenuItemId[j])
            {
                return (U8) ret_idx;
            }
            ret_idx++;
        }
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return (U8) 0;
}


/*****************************************************************************
* FUNCTION
*  GetChildMenuIDIndexByParentMenuID_Ext
* DESCRIPTION
*  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem, considering MenuItemMask.
* PARAMETERS
*  parentMenuId        [IN]    parent menu ID
*  childMenuId         [IN]    child menu ID
* RETURNS
*  index >= 0: child manu id is a child of parent menu id, -1: if not
*****************************************************************************/
S32 DevAppGetChildMenuIDIndexByParentMenuID_Ext(U16 parentMenuId, U16 childMenuId)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U16 nMenuItemList[MAX_SUB_MENUS];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numItems = DevAppGetNumOfChild_Ext(parentMenuId);

    DevAppGetSequenceItemIds_Ext(parentMenuId, nMenuItemList);
    
    for (index = 0; index < numItems; index++)
    {
        if (nMenuItemList[index] == childMenuId)
        {
            return index;
        }
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return -1;
}


#if defined(__DEVAPP_RESOURCE_OUTPUT__)
#define TOTAL_MENU_DEVAPP (DEVAPP_BASE_MAX - DEVAPP_BASE + 1) + (AVK_BASE_MAX - AVK_BASE + 1) + (MAX_MENU_ITEMS_VALUE - MENU_ID_DEVAPP_START + 1)
U8 DevappMenuItemMask[((TOTAL_MENU_DEVAPP) / 8) + 1];
#endif

/*****************************************************************************
 * FUNCTION
 *  devapp_test_menu_item_hide
 * DESCRIPTION
 *  test if the menuitem is hidden or not
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  MMI_BOOL MMI_TRUE if the menuitem is hidden
 *****************************************************************************/
MMI_BOOL devapp_test_menu_item_hide(U16 menu_item_id)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_id = DevAppGetDevIndex(menu_item_id);
    ASSERT(item_id < TOTAL_MENU_DEVAPP);

    if (item_id < TOTAL_MENU_DEVAPP)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        if ((DevappMenuItemMask[idx] >> (7 - reminding)) & 1)
        {
            return MMI_TRUE;
        }
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  devapp_hide_menu_item
 * DESCRIPTION
 *  Set the bit represented the menuitem on to hide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void devapp_hide_menu_item(U16 menu_item_id)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    item_id = GetMenuItemIndex(menu_item_id);
    ASSERT(item_id < TOTAL_MENU_DEVAPP);
    
    if (item_id < TOTAL_MENU_DEVAPP)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        DevappMenuItemMask[idx] |= (1 << (7 - reminding));
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
	return;
}


/*****************************************************************************
 * FUNCTION
 *  devapp_unhide_menu_item
 * DESCRIPTION
 *  Reset the bit represented the menuitem on to unhide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void devapp_unhide_menu_item(U16 menu_item_id)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_id = GetMenuItemIndex(menu_item_id);
    ASSERT(item_id < TOTAL_MENU_DEVAPP);
    
    if (item_id < TOTAL_MENU_DEVAPP)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        DevappMenuItemMask[idx] &= ~(1 << (7 - reminding));
    }
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
	return;
}


mmi_ret mmi_res_devapp_hide_dim_menu_init(void)
{
#if defined(__DEVAPP_RESOURCE_OUTPUT__)    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(DevappMenuItemMask, 0, (((TOTAL_MENU_DEVAPP) / 8) + 1));
#endif /* defined(__DEVAPP_RESOURCE_OUTPUT__) */
    return MMI_RET_OK;
}
