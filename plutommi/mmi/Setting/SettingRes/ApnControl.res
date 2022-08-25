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
 * ApnControl.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 *  Mingliang Xu (mtk80021)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 20 2011 mingliang.xu
 * [MAUI_02863212] [Gemini+][Taiwan-Hsinchu][ALL] [APN]The APN function is fail
 * .
 *
 * 12 28 2010 mingliang.xu
 * [MAUI_02646062] [APNcontrol] move resource from res_setting.c
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_APN_CONTROL">

#ifdef __MMI_ACL_SUPPORT__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SECSET_ACL_MAIN"/>
    <STRING id="STR_ID_SECSET_ACL_MODE"/>
    <STRING id="STR_ID_SECSET_ACL_LIST"/>
    <STRING id="STR_ID_SECSET_ACL_LIST_CAPTION"/>
    <STRING id="STR_ID_SECSET_ACL_NAME"/>
    <STRING id="STR_ID_SECSET_ACL_IS_ON"/>
    <STRING id="STR_ID_SECSET_ACL_IS_OFF"/>
    <STRING id="STR_ID_SECSET_ACL_MEMORY_FULL"/>
    <STRING id="STR_ID_SECSET_ACL_EF_SIZE_FULL"/>
    <STRING id="STR_ID_SECSET_ACL_TRY_LATER"/>
    <STRING id="STR_ID_SECSET_ACL_ADD_DEFAULT_QUERY"/>
    <STRING id="STR_ID_SECSET_ACL_NETWORK_PROVIDED"/>
    <STRING id="STR_ID_SECSET_ACL_DELETE_ASK"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* For the detail of scope="XML" please check user manual */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    <MENU id="MENU_ID_SECSET_ACL_MAIN" type="APP_SUB" str="STR_ID_SECSET_ACL_MAIN">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_LIST</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SECSET_ACL_SIM2" type="APP_SUB" str="STR_ID_SECSET_ACL_MAIN">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_LIST</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SECSET_ACL_SIM3" type="APP_SUB" str="STR_ID_SECSET_ACL_MAIN">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_LIST</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SECSET_ACL_SIM4" type="APP_SUB" str="STR_ID_SECSET_ACL_MAIN">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_LIST</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_SECSET_ACL_MODE" str="STR_ID_SECSET_ACL_MODE"/>
    <MENUITEM id="MENU_ID_SECSET_ACL_LIST" str="STR_ID_SECSET_ACL_LIST"/>

    <MENU id="MENU_ID_SECSET_ACL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_ACL_DELETE</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_SECSET_ACL_ADD" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_SECSET_ACL_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SECSET_ACL_DELETE" str="STR_GLOBAL_DELETE"/>

    <!--Option Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */
    <MENUITEM id="MENU_ID_SECSET_ACL_SAVE" str="STR_GLOBAL_SAVE"/>

    <MENU id="MENU_ID_SECSET_ACL_INPUT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SECSET_ACL_SAVE</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->


#endif /* __MMI_ACL_SUPPORT__ */

</APP>

