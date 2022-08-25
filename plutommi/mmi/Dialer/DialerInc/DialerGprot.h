/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the dialer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DIALER_GPROT_H
#define DIALER_GPROT_H

/****************************************************************************
 * Header
 ****************************************************************************/

#include "DialerCuiGprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_handle_dialer_change_type
 * DESCRIPTION
 *  This function handles the dialer change type event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#if (defined(__MMI_VOIP__) || defined(__MMI_DIALER_SEARCH__))
extern mmi_ret mmi_dialer_handle_dialer_change_type(mmi_event_struct *event);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch
 * DESCRIPTION
 *  This function launches the dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_launch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_ex
 * DESCRIPTION
 *  This function launches the dialer of the specified type.
 * PARAMETERS
 *  type                    : [IN]      Dialer type
 * RETURNS
 *  Dialer group ID.
 *****************************************************************************/
#ifndef __MMI_DIALER_SLIM__
extern mmi_id mmi_dialer_launch_ex(cui_dialer_type_enum type);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_string
 * DESCRIPTION
 *  This function launches the dialer with the dialing string.
 * PARAMETERS
 *  dial_string             : [IN]      Dialing string
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_launch_by_string(const WCHAR *dial_string);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_string_ex
 * DESCRIPTION
 *  This function launches the dialer with the dialing string. Dialer type can
 *  also be indicated by this API.
 * PARAMETERS
 *  type                    : [IN]      Dialer type
 *  dial_string             : [IN]      Dialing string
 * RETURNS
 *  Dialer group ID.
 *****************************************************************************/
extern mmi_id mmi_dialer_launch_by_string_ex(
    cui_dialer_type_enum type,
    const WCHAR *dial_string);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_key
 * DESCRIPTION
 *  This function launches the dialer with the key code.
 * PARAMETERS
 *  key_code                : [IN]      Key code
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_launch_by_key(U16 key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_key_ex
 * DESCRIPTION
 *  This function launches the dialer with the key code. The dialer type can
 *  also be indicated by this API.
 * PARAMETERS
 *  type                    : [IN]      Dialer type
 *  key_code                : [IN]      Key code
 * RETURNS
 *  Dialer group ID.
 *****************************************************************************/
extern mmi_id mmi_dialer_launch_by_key_ex(
    cui_dialer_type_enum type,
    U16 key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_translate_key
 * DESCRIPTION
 *  This function launches the dialer with the translate key.
 * PARAMETERS
 *  key_code                : [IN]      Key code
 *  key_type                : [IN]      key type
 *  ucs2_value              : [IN]      UCS2 value
 *  key_flag                : [IN]      Key flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_launch_by_translate_key(
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_launch_by_translate_key_ex
 * DESCRIPTION
 *  This function launches the dialer with the translate key. The dialer type
 *  can also be indicated by this API.
 * PARAMETERS
 *  type                    : [IN]      Dialer type
 *  key_code                : [IN]      Key code
 *  key_type                : [IN]      Key type
 *  ucs2_value              : [IN]      UCS2 value
 *  key_flag                : [IN]      Key flag
 * RETURNS
 *  Dialer group ID.
 *****************************************************************************/
extern mmi_id mmi_dialer_launch_by_translate_key_ex(
    cui_dialer_type_enum type,
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_is_active
 * DESCRIPTION
 *  This function checks if there is any dialer active.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_dialer_is_active(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_get_dial_string
 * DESCRIPTION
 *  This function gets the dial string if there is any dialer active.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern const WCHAR *mmi_dialer_get_dial_string(void);


#if defined(__MMI_DIALER_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_search_is_enable
 * DESCRIPTION
 *  This function checks whether the dialer search is on or off.
 * PARAMETERS
 *  void
 * RETURNS
 *  If dialer search is on, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_dialer_search_is_enable(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_search_set_enable
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  enable           : [IN]         enable or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_search_set_enable(MMI_BOOL is_enable);


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_search_entry_setting
 * DESCRIPTION
 *  This function shows the dialer search setting screen.
 * PARAMETERS
 *  group_id     [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dialer_search_entry_setting(MMI_ID group_id);

#endif /* defined(__MMI_DIALER_SEARCH__) */

/* DOM-NOT_FOR_SDK-END */

#endif /* DIALER_GPROT_H */

