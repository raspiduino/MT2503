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
 *  dm_common_customize.c
 *
 * Project:
 * -------- 
 *  
 *
 * Description:
 * ------------
 *  DM Customize API
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef SYNCML_DM_SUPPORT

#include "kal_release.h"
#include "dm_common_customize.h"

/* Customer is to configure this according to their allocated update
   package storage size (flash or file) */
#define PACKAGE_STORAGE_SIZE  0x400000   /* i.e. 16K to store update package */

/* Be defined by Customer */
/*#ifndef XX_SUPPORT_DL
#define XX_SUPPORT_DL
#endif  XX_SUPPORT_DL */

/*#ifndef XX_SUPPORT_UPDATE
#define XX_SUPPORT_UPDATE
#endif  XX_SUPPORT_UPDATE */

/* DL API */
/*****************************************************************************
* FUNCTION
*  dm_dl_init 
* DESCRIPTION
*  This function is to init dl module
* PARAMETERS
*  AppRef: APP reference
* RETURNS
*  kal_bool
*****************************************************************************/
kal_bool dm_init_dl(kal_int32 AppRef)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_DL
    return mvaDlMgrInitialization(AppRef);
#else
    return KAL_FALSE;
#endif /* XX_SUPPORT_DL */
}


/*****************************************************************************
* FUNCTION
*  dm_dl_init 
* DESCRIPTION
*  This function is to send notification to dl module
* PARAMETERS
*  dm_custom_mvaDlMgrEventStructTyp: be same as mvaDlMgrEventStructTyp
*  AppRef: APP reference
* RETURNS
*  kal_bool
*****************************************************************************/
kal_bool dm_send_dl_notify(dm_custom_mvaDlMgrEventStructTyp Event, kal_int32 AppRef)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_DL
    return mvaDlMgrAppNotifyEvent(Event, AppRef);
#else
    return KAL_FALSE;
#endif /* XX_SUPPORT_DL */
}


/*****************************************************************************
* FUNCTION
*  dm_get_dl_state 
* DESCRIPTION
*  This function is to get DL state
* PARAMETERS
*  void
* RETURNS
*  dm_custom_mvaDlMgrStateEnumTyp
*****************************************************************************/
dm_custom_mvaDlMgrStateEnumTyp dm_get_dl_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_DL
    return mvaDlMgrGetState();
#else
    return DM_CUSTOM_DL_MMGR_STATE_END;
#endif /* XX_SUPPORT_DL */
}


/* Update API */
/*****************************************************************************
* FUNCTION
*  dm_get_updatepackage_maxsize 
* DESCRIPTION
*  This function is to get update package max size
* PARAMETERS
*  void
* RETURNS
*  size in byte
*****************************************************************************/
kal_uint32 dm_get_updatepackage_maxsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return PACKAGE_STORAGE_SIZE;
}


/*****************************************************************************
* FUNCTION
*  dm_move_updatepackage 
* DESCRIPTION
*  This function is to call move update package to specify flash address.
* PARAMETERS
*  pszPackageFullName: UCS2 encode string
* RETURNS
*  void
*****************************************************************************/
void dm_move_updatepackage(kal_char* pszPackageFullName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef XX_SUPPORT_UPDATE
    DM_CopyDataFromFileToFlash(pszPackageFullName);
#endif /* XX_SUPPORT_UPDATE */
}


/*****************************************************************************
* FUNCTION
*  dm_set_update_flag 
* DESCRIPTION
*  This function is to set update flag.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void dm_set_update_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_UPDATE
    mvaSetTriggerFlag();
#endif /* XX_SUPPORT_UPDATE */
}


/*****************************************************************************
* FUNCTION
*  dm_get_update_flag 
* DESCRIPTION
*  This function is to get update flag.
* PARAMETERS
*  pStatus:
*  AppRef
* RETURNS
*  void
*****************************************************************************/
kal_bool dm_get_update_flag(kal_int32 *pStatus, kal_int32 AppRef)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_UPDATE
    return mvaGetUpdateState(pStatus, AppRef);
#else
    return KAL_FALSE;
#endif /* XX_SUPPORT_UPDATE */
}


/*****************************************************************************
* FUNCTION
*  dm_clear_update_flag 
* DESCRIPTION
*  This function is to clear update flag.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void dm_clear_update_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef XX_SUPPORT_UPDATE
    mvaReSetHandOffState();
#endif /* XX_SUPPORT_UPDATE */
}
#endif /* SYNCML_DM_SUPPORT */




