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
 *  CustMenuRes.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**********************************************************************************
   FILENAME : CustMenuRes.h

   PURPOSE     : To define Common Structures used by the UI Elements and Cutomization Tool 
              for Customizing Menus(MenuItem).

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
**********************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef _PIXCOM_CUSTMENURES_H
#define _PIXCOM_CUSTMENURES_H

#include "MMIDataType.h"
#include "GlobalMenuItems.h"
#include "CustDataProts.h"

#define MENU_ITEM_SIZE  50

#define MAX_MENUID_ENUM   128
#define MAX_HANDLER_NAME  128

#define LIST_MENU           DISP_LIST
#define MATRIX_MENU         DISP_MATRIX
#define CIRCULAR_3D_MENU    DISP_CIRCULAR_3D
#define PAGE_MENU           DISP_PAGE
#define ANI_BG_LIST_MENU    DISP_ANI_BG_LIST
#define MATRIX_MENU_EMS     DISP_MATRIX_EMS
#define ROTATE_MENU         DISP_ROTATE
#define LIST_MATRIX_MENU    DISP_LIST_MATRIX
#define MOTION_MENU         DISP_MOTION
#define MATRIX_PAGE_MENU    DISP_MATRIX_PAGE
#define MMI_MENU_TYPES      DISPATTRIBUTE

#ifdef __DEVAPP_RESOURCE_OUTPUT__
typedef struct Custom_MenuItem
{
    U16 nMenuItemId;    /* Unique Id for each MenuItem. */
    U16 nParentId;      /* ItemId of the parent if 0(zero) then no parent. */
    U16 nNumofMenuItem; /* Number of Children it has. */
    U16 nHideFlag;      /* This is a flag to mask/hide.(not sure currently) */
    U16 nMovable;       /* This is a flag for moving like 0-NotMovable Anywhere, */
    /* 1-Movable within the same parent..etc */

    U16 nDispAttribute;     /* This is a display attribute flag like 1-list,2-Circular,3-Tab..etc. */
    U16 nStrId;             /* Unique StringId of the MenuItem. */
    U16 nImageId;           /* Unique Image of the MenuItem. */
    U16 *nOrderMenuItemId;  /* ItemId of the children in Sequence */
} CUSTOM_MENU;
#else
/* The Below is the structure of the MenuItem which can be transfered to any screen. */
typedef struct Custom_MenuItem
{
    U16 nParentId;      /* ItemId of the parent if 0(zero) then no parent. */
    U16 nNumofMenuItem; /* Number of Children it has. */
    /* 1-Movable within the same parent..etc */

    U8  nFlags;
    U8  nDispAttribute;     /* This is a display style flag like 1-list,2-Circular,3-Tab..etc. */
    U16 nStrId;             /* Unique StringId of the MenuItem. */
    U16 nImageId;           /* Unique Image of the MenuItem. */
    U16 *nOrderMenuItemId;  /* ItemId of the children in Sequence */
} CUSTOM_MENU;
#endif /* __DEVAPP_RESOURCE_OUTPUT__ */

typedef struct
{
    U16 minId;
    U16 maxId;
    U16 index;
} CUSTOM_MENU_SEARCH_MAP;

typedef struct
{
    CUSTOM_MENU             *MenuRes;
    CUSTOM_MENU_SEARCH_MAP  *MenuSearchMap;
    U16                     MaxMapEntry;
} CUSTOM_MENU_RES_ENTRY;


typedef struct 
{
    U16 parent_id;
    U16 def_menu_id;
}mmi_rg_menu_default_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 index;
    U32 notify_type;
    U16 menu_id;
} mmi_event_menu_struct;

typedef void (*MenuNotifyFunc) (mmi_event_menu_struct *menu_notify);

typedef struct 
{
    U32            menu_id;
    MenuNotifyFunc notify_hdlr;
}mmi_rg_notify_hdlr_struct;

typedef struct 
{
    U16 *group_array;
}mmi_rg_menu_group_struct;

typedef enum
{
    MMI_RG_MM_IMG_LIST,
    MMI_RG_MM_IMG_MATRIX,    
    MMI_RG_MM_IMG_PAGE,
    MMI_RG_MM_IMG_VENUS1,
    MMI_RG_MM_IMG_VENUS2,
    MMI_RG_MM_IMG_MATRIX_HIGHLIGHT,
    MMI_RG_MM_IMG_MATRIX_CTRL_AREA,
    MMI_RG_MM_IMG_VENUS1_HIGHLIGHT,
    MMI_RG_MM_IMG_TITLE
}mmi_rg_menu_mainmenu_img_type;

typedef struct 
{
    U16 id;
    U16 list_img;
    U16 matrix_img;
    U16 page_img;
    U16 venus_img_1;
    U16 venus_img_2;
    U16 matrix_highlight_img;
    U16 matrix_controlled_area_img;
    U16 venus1_highlight_img;
    U16 title_img;
}mmi_rg_menu_mainmenu_img_id_struct;

/* Menuitem reduce memory, move registe hilite handlers to resgen */
/*---------------------------Only Used in Resgen------------------------------*/
typedef struct resgen_menu_hilite_handler
{
    U16 nMenuItemId;                         /* Unique Id for each MenuItem. */
    S8  MenuItemIdEnum[MAX_MENUID_ENUM];     /* MENUID Enum name */
    S8  HiliteFuncName[MAX_HANDLER_NAME];    /* Hilite Handler */
} RESGEN_MENU_HILITE_HANDLER;

typedef struct resgen_menu_hint_handler
{
    U16 nMenuItemId;                         /* Unique Id for each MenuItem. */
    S8  MenuItemIdEnum[MAX_MENUID_ENUM];     /* MENUID Enum name */
    S8  HintFuncName[MAX_HANDLER_NAME];      /* Hint Handler */
} RESGEN_MENU_HINT_HANDLER;
/*-----------------------------------End--------------------------------------*/


typedef struct
{
    U32     menu_id;
    FuncPtr hilite_hdlr;
}mmi_frm_hilite_hdlr_struct;

typedef struct
{
    U32          menu_id;
    FuncPtrShort hint_hdlr;
}mmi_frm_hint_hdlr_struct;

/* DOM-NOT_FOR_SDK-END */

extern FuncPtr mmi_res_menu_get_hilite_hdlr(U16 menu_id);
extern FuncPtrShort mmi_res_menu_get_hint_hdlr(U16 menu_id);
//extern MenuNotifyFunc mmi_res_menu_get_notify_hdlr(U16 menu_id);

/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetParentItemId
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      : [IN]        Menuitem ID
 * RETURNS
 *  Parent MenuItemId of the given MenuItemId.
 *****************************************************************************/
extern U16 GetParentItemId(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetRootParentIndex
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId in Mainmenu
 * PARAMETERS
 *  ItemId      : [IN]        Menuitem ID
 * RETURNS
 *  Parent MenuItemId of the given MenuItemId in Mainmenu.
 *****************************************************************************/
extern U16 GetRootParentIndex(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetNumOfChild
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ItemId      : [IN]        Menuitem ID
 * RETURNS
 *  Number of Childrens of the given MenuItemId.
 *****************************************************************************/
extern U16 GetNumOfChild(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetStringIdOfItem
 * DESCRIPTION
 *  Function to get StringId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      : [IN]        Menuitem ID
 * RETURNS
 *  U16 StringId of the given MenuItemId.
 *****************************************************************************/
extern U16 GetStringIdOfItem(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetImageIdOfItem
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId.
 * PARAMETERS
 *  ItemId      : [IN]        ImageId
 * RETURNS
 *  U16 ImageId of the given MenuItemId.
 *****************************************************************************/
extern U16 GetImageIdOfItem(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetDispAttributeOfItem
 * DESCRIPTION
 *  Function to get DispAttributes of the given MenuItemId.
 *  
 *  DispAttribute are like Matrix,List,Circular,Tab..etc.
 * PARAMETERS
 *  ItemId      : [IN]        Menuitem ID
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
extern U16 GetDispAttributeOfItem(U16 ItemId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemId
 * DESCRIPTION
 *  Function to get MenuItemId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId       : [IN]        Parent Item ID
 *  Seq                : [IN]        Index of menu item
 * RETURNS
 *  MenuItemId of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
extern U16 GetSeqItemId(U16 ParentItemId, U16 Seq);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemStringId
 * DESCRIPTION
 *  Function to get StringId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]        Parent item ID
 *  Seq                 : [IN]        Index of menu item
 * RETURNS
 *  StringId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
extern U16 GetSeqItemStringId(U16 ParentItemId, U16 Seq);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemImageId
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]        Parent Item ID
 *  Seq                 : [IN]        Index of menu item
 * RETURNS
 *  ImageId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
extern U16 GetSeqItemImageId(U16 ParentItemId, U16 Seq);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceItemIds
 * DESCRIPTION
 *  Function to get all the MenuItemIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]          Parent Item ID
 *  ItemIds             : [OUT]         Item ID list pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void GetSequenceItemIds(U16 ParentItemId, U16 *ItemIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceStringIds
 * DESCRIPTION
 *  Function to get all the StringIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]        Parent Item ID
 *  StringIds           : [OUT]       Menu String list pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void GetSequenceStringIds(U16 ParentItemId, U16 *StringIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceImageIds
 * DESCRIPTION
 *  Function to get all the ImageIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]        Parent menuitem ID
 *  ImageIds            : [OUT]       Image list pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void GetSequenceImageIds(U16 ParentItemId, U16 *ImageIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetIndexOfStringId
 * DESCRIPTION
 *  Function to get the index of StringIds in the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        : [IN]        Parent Menu ID
 *  StringId            : [IN]        String ID of the menu
 * RETURNS
 *  U8                  Menu item index in the menu
 *****************************************************************************/
extern U8 GetIndexOfStringId(U16 ParentItemId, U16 StringId);


//extern S16 GetChildIndex(U16 nChildId, U16 nParentId);

/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetChildMenuIDIndexByParentMenuID
 * DESCRIPTION
 *  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem.
 *  No hide attribute consideration.
 * PARAMETERS
 *  parentMenuId        : [IN]        Parent menu id
 *  childMenuId         : [IN]        Child menu id
 * RETURNS
 *  index >= 0: child manu id is a child of parent menu id, -1: if not
 *****************************************************************************/
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_frm_test_menu_item_hide
 * DESCRIPTION
 *  test if the menuitem is hidden or not
 * PARAMETERS
 *  menu_item_id        : [IN]        Id of the menuitem
 * RETURNS
 *  MMI_BOOL MMI_TRUE if the menuitem is hidden
 *****************************************************************************/
extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_frm_hide_menu_item
 * DESCRIPTION
 *  Set the bit represented the menuitem on to hide it
 * PARAMETERS
 *  menu_item_id        : [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_hide_menu_item(U16 menu_item_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_frm_unhide_menu_item
 * DESCRIPTION
 *  Reset the bit represented the menuitem on to unhide it
 * PARAMETERS
 *  menu_item_id        : [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_unhide_menu_item(U16 menu_item_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_frm_unhide_child_menu_items
 * DESCRIPTION
 *  unhide all child menu items of a given parent menu item
 * PARAMETERS
 *  parent_menu_item_id   : [IN]        Id of the parent menuitem
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_unhide_child_menu_items(U16 parent_menu_item_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetNumOfChild_Ext
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId considering MenuItemMask.
 * PARAMETERS
 *  menu_item_id        : [IN]        Id of the menuitem
 * RETURNS
 *  U16   Number of Childrens.
 *****************************************************************************/
extern U16 GetNumOfChild_Ext(U16 menu_item_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemId_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id & index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]        Id of the parent menuitem
 *  index               : [IN]        Index of the child menuitem
 * RETURNS
 *  U16   item id
 *****************************************************************************/
extern U16 GetSeqItemId_Ext(U16 parent_item_id, U16 index);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemStringId_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]        Id of the parent menuitem
 *  index               : [IN]        Index of the child menuitem
 * RETURNS
 *  U16   string id
 *****************************************************************************/
extern U16 GetSeqItemStringId_Ext(U16 parent_item_id, U16 index);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSeqItemImageId_Ext
 * DESCRIPTION
 *  Function to get Image Id of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]        Id of the parent menuitem
 *  index               : [IN]        Index of the child menuitem
 * RETURNS
 *  U16   image id
 *****************************************************************************/
extern U16 GetSeqItemImageId_Ext(U16 parent_item_id, U16 index);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceItemIds_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]            Id of the parent menuitem
 *  ItemIds             : [IN/OUT]        Array of the child menuitem id
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
extern U16 GetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceStringIds_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]            Id of the parent menuitem
 *  StringIds           : [IN/OUT]        Array of string ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
extern U16 GetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetSequenceImageIds_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]            Id of the parent menuitem
 *  ImageIds            : [IN/OUT]        Array of image ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
extern U16 GetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetIndexOfStringId_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      : [IN]        Id of the parent menuitem
 *  StringId            : [IN]        Id of the string
 * RETURNS
 *  U8 index
 *****************************************************************************/
extern U8 GetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  GetChildMenuIDIndexByParentMenuID
 * DESCRIPTION
 *  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem.
 *  No hide attribute consideration.
 * PARAMETERS
 *  parentMenuId        : [IN]        Parent menu id
 *  childMenuId         : [IN]        Child menu id
 * RETURNS
 *  index >= 0: child manu id is a child of parent menu id, -1: if not
 *****************************************************************************/
extern S32 GetChildMenuIDIndexByParentMenuID_Ext(U16 parentMenuId, U16 childMenuId);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  SetMenuItemDimmed
 * DESCRIPTION
 *  Dims an menu item.
 * PARAMETERS
 *  menu_id       : [IN]  menu id
 *  is_dimmed     : [IN]  dimmed flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetMenuItemDimmed(U16 menu_id, MMI_BOOL is_dimmed);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  IsMenuItemDimmed
 * DESCRIPTION
 *  Checks if the menu item is dimmed.
 * PARAMETERS
 *  menu_id       : [IN]  menu id
 * RETURNS
 *  MMI_TRUE if dimmed; otherwise, MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL IsMenuItemDimmed(U16 menu_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_group_set_disable
 * DESCRIPTION
 *  Disable/Enalbe a group of menu items.
 * PARAMETERS
 *  group_id      [IN]  group id
 *  is_disable    [IN]  Disable flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_res_menu_group_set_disable(U16 group_id, MMI_BOOL is_disable);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_group_set_hide
 * DESCRIPTION
 *  Hide/Unhide a group of menu items
 * PARAMETERS
 *  group_id     [IN]  group id
 *  is_hide      [IN]  hide flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_res_menu_group_set_hide(U16 group_id, MMI_BOOL is_hide);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_group_get_menuitems
 * DESCRIPTION
 *  Get menuitems of the group
 * PARAMETERS
 *  group_id     [IN]  group id
 *  items        [OUT] Array of menuitems, end with a 0xFFFF
 * RETURNS
 *  S16          count of menuitems in the group.
 *****************************************************************************/
extern U16 mmi_res_menu_group_get_menuitems(U16 group_id, U16 **items);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_get_type
 * DESCRIPTION
 *  Function to get DispAttributes of the given MenuItemId.
 *  DispAttribute are like MMI_RG_MENU_TYPE_ORIGINAL, MMI_RG_MENU_TYPE_APP_MAIN, 
 *                         MMI_RG_MENU_TYPE_APP_SUB,   MMI_RG_MENU_TYPE_OPTION,
 * PARAMETERS
 *  menu_id      [IN]       menuitem ID 
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
extern U16 mmi_res_menu_get_type(U16 menu_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_get_flag
 * DESCRIPTION
 *  Function to get nFlags of the given MenuItemId.
 *  
 *  nFlags are like MMI_RG_MENU_FLAG_RADIO, MMI_RG_MENU_FLAG_CHECKBOX or MMI_RG_MENU_FLAG_NONE
 * PARAMETERS
 *  menu_id      [IN]        menuitem ID 
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
extern U16 mmi_res_menu_get_flag(U16 menu_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_menu_get_default_item
 * DESCRIPTION
 *  Function to get default menu ID of a menu tree
 * PARAMETERS
 *  parent_id      [IN]     parent ID of menu tree   
 * RETURNS
 *  Default menuID, if set return set value, if not set, return first menuID, considering Hide/Unhide.
 *****************************************************************************/
U16 mmi_res_menu_get_default_item(U16 parent_id);


/*****************************************************************************
 * <GROUP MENU>
 * FUNCTION
 *  mmi_res_get_mainmenu_img
 * DESCRIPTION
 *  Function to get mainmenu's image for mainmenu items.
 * PARAMETERS
 *  menu_id      [IN]     ID of menu item
 *  img_type     [IN]     Type of image to get.
 * RETURNS
 *  image ID
 *****************************************************************************/
MMI_IMG_ID mmi_res_get_mainmenu_img(MMI_MENU_ID menu_id, mmi_rg_menu_mainmenu_img_type img_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_id_by_img
 * DESCRIPTION
 *  Function to get mainmenu's ID by image ID and type
 * PARAMETERS
 *  img_id      [IN]     ID of menu item
 *  img_type     [IN]     Type of image to get.
 * RETURNS
 *  menu ID
 *****************************************************************************/
MMI_MENU_ID mmi_res_get_mainmenu_id_by_img(MMI_IMG_ID img_id, mmi_rg_menu_mainmenu_img_type img_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_3d_img_id
 * DESCRIPTION
 *  Function to get mainmenu's 3D image ID by menu ID 
 * PARAMETERS
 *  menu_id      [IN]     Menu ID of mainmenu 
 * RETURNS
 *  image ID
 *****************************************************************************/
MMI_IMG_ID mmi_res_get_mainmenu_3d_img_id(MMI_IMG_ID menu_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_launch_handler
 * DESCRIPTION
 *  Function to get mainmenu's launch handler by menu ID
 * PARAMETERS
 *  menu_id      [IN]     Menu ID of mainmenu 
 * RETURNS
 *  Function pointer
 *****************************************************************************/
FuncPtr mmi_res_get_mainmenu_launch_handler(MMI_IMG_ID menu_id);

#endif /* _PIXCOM_CUSTMENURES_H */ 

