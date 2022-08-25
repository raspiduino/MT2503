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
*   AMProxy.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
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
 * removed!
 * removed!
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
//#ifdef __MRE_AM__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "AMSwitch.h"
#include "MMI_features.h"
//#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
#include "MMIDataType.h"
#include "stack_config.h"	/* TRACE_GROUP_7 */
//#include "kal_trace.h"	/* MOD_MMI */
#include "DebugInitDef_Int.h"
#include "MMI_mre_trc.h"


/* MRE Core Header File */
#include "vmenv.h"
#include "vmsys.h"
#include "vmcert.h"
#include "vmmullang.h"
#include "vmgettag.h"

#include "AMDef.h"
#include "AMProxy.h"
#include "AMUtil.h"
#include "MRESrvGProt.h"
#include "MRESrvDownloadGprot.h"

/*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static MMI_AM_SYNC_CDR_CB_T g_am_sync_cdr_cb;

/*****************************************************************************
* FUNCTION
*  mmi_am_mre_get_string_data
* DESCRIPTION
*  
* PARAMETERS
*  gifzm           [IN]        
*  data_buf        [IN]        
*  lan             [IN]        
*  str_len         [OUT]       
*  font            [OUT]       
*  data_size       [OUT]       
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_mre_get_string_data(
                                    S8 *gifzm,
                                    U8 **data_buf,
                                    MMI_AM_LANGUAGE_TYPE lan,
                                    S32 *str_len,
                                    S32 *font,
                                    S32 *data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    LANGUAGE_TYPE lan_mre;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lan)
    {
    case MMI_AM_ENG:
        lan_mre = ENG;
        break;
    case MMI_AM_CHS:
        lan_mre = CHS;
        break;
    case MMI_AM_CHT:
        lan_mre = CHT;
        break;
    default:
        lan_mre = CHS;
        break;
    }

    ret = vm_vam_get_string_data(
        (VMUINT8*) gifzm,
        (VMUINT8 **) data_buf,
        (LANGUAGE_TYPE) lan_mre,
        (VMINT*) str_len,
        (VMINT*) font,
        (VMINT*) data_size);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_measure_zimo_string
* DESCRIPTION
*  
* PARAMETERS
*  zimo_buf        [IN]        
*  str_len         [IN]        
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_mre_measure_zimo_string(S8 *zimo_buf, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 zimo_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zimo_len = vm_vam_measure_zimo_string((VMUINT8*) zimo_buf, (VMINT) str_len);
    if (zimo_len == -1)
    {
        zimo_len = 0;
    }

    return zimo_len;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_malloc
* DESCRIPTION
*  
* PARAMETERS
*  size        [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mmi_am_mre_malloc(S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_vam_malloc(size);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_free
* DESCRIPTION
*  
* PARAMETERS
*  p       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_mre_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_vam_free(p);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_sync_cdr_cb
* DESCRIPTION
*  
* PARAMETERS
*  nResult     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_mre_sync_cdr_cb(S32 nResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_sync_cdr_cb(nResult);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_sync_cdr
* DESCRIPTION
*  
* PARAMETERS
*  sync_cdr_cb     [IN]        
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_mre_sync_cdr(MMI_AM_SYNC_CDR_CB_T sync_cdr_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_sync_cdr_cb = sync_cdr_cb;
    ret = srv_mre_update_sync_cdr(mmi_am_mre_sync_cdr_cb);

    if (ret == VAM_DL_OK)
    {
        //return MMI_AM_DL_OK;
        return 0;
    }
    else
    {
        //return MMI_AM_DL_ERR;
        return 1;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_get_user_balance
* DESCRIPTION
*  
* PARAMETERS
*  user_balance        [OUT]       
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_mre_get_user_balance(U32 *user_balance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_get_user_balance(user_balance);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MRE_AM__ */ 

