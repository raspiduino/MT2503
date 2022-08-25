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
*  Aud_bt_hfp.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BT hands-free profile
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef MED_NOT_PRESENT
#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)

#ifndef __AUD_BT_HFP__
#define __AUD_BT_HFP__

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "med_global.h"
#include "kal_general_types.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
 ----------------------------------------------------------------------------*/
#define AUD_BT_HFP_IS_FM_VIA_BT_SCO(mode)      ((kal_uint16)(mode) & AUD_BT_HFP_MODE_FM_VIA_BT_SCO)
#define AUD_BT_HFP_IS_ATV_VIA_BT_SCO(mode)     ((kal_uint16)(mode) & AUD_BT_HFP_MODE_ATV_VIA_BT_SCO)
#ifdef __MED_BT_HF_MOD__
#define AUD_BT_HFP_IS_BT_DIALER_SCO(mode)     ((kal_uint16)(mode) & AUD_BT_HFP_MODE_BT_DIALER_SCO)
#endif

#define AUD_BT_HFP_IS_MEGAPHONE_SCO(mode)     ((kal_uint16)(mode) & AUD_BT_HFP_MODE_MEGAPHONE_SCO)


typedef enum
{
    AUD_BT_HFP_MODE_DEFAULT_BT_SCO    = 0x00,
    AUD_BT_HFP_MODE_FM_VIA_BT_SCO     = 0x01,
    AUD_BT_HFP_MODE_ATV_VIA_BT_SCO    = 0x02,
#ifdef __MED_BT_HF_MOD__ 
    AUD_BT_HFP_MODE_BT_DIALER_SCO    = 0x04,
#endif

	AUD_BT_HFP_MODE_MEGAPHONE_SCO	 = 0x08,

    
    AUD_BT_HFP_MODE_LAST_ENTRY
} aud_bt_hfp_mode_enum;

/*-----------------------------------------------------------------------------
                    Exported API's
 ----------------------------------------------------------------------------*/
extern void aud_bt_hfp_set_sco_mode(aud_bt_hfp_mode_enum mode);
extern void aud_bt_hfp_reset_sco_mode(aud_bt_hfp_mode_enum mode);
extern void aud_bt_hfp_get_sco_mode(kal_uint16* sco_mode);

#endif /* __AUD_BT_HFP__ */
#endif /* __MED_BT_HFP_MOD__ */
#endif /* MED_NOT_PRESENT */

