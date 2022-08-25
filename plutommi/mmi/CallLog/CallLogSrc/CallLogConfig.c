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
*  CallLogConfig.c
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CallLogSrvGprot.h"
#include "CallLogConfig.h"
#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
const mmi_clog_key_struct g_mmi_clog_lsk_option = 
{
    STR_GLOBAL_OPTIONS,
    IMG_GLOBAL_OPTIONS
};
const mmi_clog_key_struct g_mmi_clog_csk_common = 
{
    0,
    IMG_GLOBAL_COMMON_CSK
};

const mmi_clog_key_struct g_mmi_clog_csk_call = 
{
    0,
    IMG_GLOBAL_OPTION_CSK//IMG_GLOBAL_CALL_CSK
};

const mmi_clog_key_struct g_mmi_clog_rsk_back = 
{
    STR_GLOBAL_BACK,
    IMG_GLOBAL_BACK
};

static const mmi_clog_lt_clt_img_struct g_mmi_clog_lt_clt_img_list[] = 
{
    /* For Gemini+, there are two icon lists, one for log type, one for SIM info */    
    {
        (mmi_sim_enum)MMI_SIM_ALL,
        SRV_CLOG_CALL_TYPE_VOICE,
        {
            {SRV_CLOG_CLT_DIALED, IMG_ID_CLOG_DIALED_CALL},
            {SRV_CLOG_CLT_MISSED, IMG_ID_CLOG_MISSED_CALL},
            {SRV_CLOG_CLT_RECVED, IMG_ID_CLOG_RECVED_CALL}
         #ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__
            ,
            {SRV_CLOG_CLT_REJED, 0}
		 #endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
        }
    },

 #ifdef __MMI_VIDEO_TELEPHONY__
    {
        (mmi_sim_enum)MMI_SIM_ALL,
        SRV_CLOG_CALL_TYPE_VIDEO,
        {
            {SRV_CLOG_CLT_DIALED, IMG_ID_CLOG_VIDEO_DIALED_CALL},
            {SRV_CLOG_CLT_MISSED, IMG_ID_CLOG_VIDEO_MISSED_CALL},
            {SRV_CLOG_CLT_RECVED, IMG_ID_CLOG_VIDEO_RECVED_CALL}
		 #ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__            
		 	,
            {SRV_CLOG_CLT_REJED, 0}
		 #endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
        }
    },
 #endif /* __MMI_VIDEO_TELEPHONY__ */ 

 #ifdef __MMI_VOIP__
    {
        (mmi_sim_enum)MMI_SIM_ALL,
        SRV_CLOG_CALL_TYPE_VOIP,
        {
            {SRV_CLOG_CLT_DIALED, IMG_ID_CLOG_VOIP_DIALED_CALL},
            {SRV_CLOG_CLT_MISSED, IMG_ID_CLOG_VOIP_MISSED_CALL},
            {SRV_CLOG_CLT_RECVED, IMG_ID_CLOG_VOIP_RECVED_CALL}
         #ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__            
		 	,
            {SRV_CLOG_CLT_REJED, 0}
		 #endif /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
        }
    }
 #endif /* __MMI_VOIP__ */ 
};

const mmi_clog_lt_img_tbl_struct g_mmi_clog_lt_img_tbl = 
{
    /* call type */
    sizeof(g_mmi_clog_lt_clt_img_list) / sizeof(mmi_clog_lt_clt_img_struct),
    g_mmi_clog_lt_clt_img_list
};

static const mmi_clog_lt_id_attr_struct g_mmi_clog_lt_id_attr_dialed_call = 
{
    MMI_CLOG_LT_ID_DIALED_CALL,
    MENU_ID_CLOG_DIALED_CALL,
    {
        SRV_CLOG_CATE_CALL,
        MMI_SIM_ALL,
        SRV_CLOG_CLT_DIALED,
        SRV_CLOG_CALL_TYPE_ALL
    }
};

static const mmi_clog_lt_id_attr_struct g_mmi_clog_lt_id_attr_missed_call = 
{
    MMI_CLOG_LT_ID_MISSED_CALL,
    MENU_ID_CLOG_MISSED_CALL,
    {
        SRV_CLOG_CATE_CALL,
        MMI_SIM_ALL,
        SRV_CLOG_CLT_MISSED,
        SRV_CLOG_CALL_TYPE_ALL
    }
};

static const mmi_clog_lt_id_attr_struct g_mmi_clog_lt_id_attr_recved_call = 
{
    MMI_CLOG_LT_ID_RECVED_CALL,
    MENU_ID_CLOG_RECVED_CALL,
    {
        SRV_CLOG_CATE_CALL,
        MMI_SIM_ALL,
        SRV_CLOG_CLT_RECVED,
        SRV_CLOG_CALL_TYPE_ALL
    }
};

static const mmi_clog_lt_id_attr_struct g_mmi_clog_lt_id_attr_all_call = 
{
    MMI_CLOG_LT_ID_ALL_CALL,
    MENU_ID_CLOG_ALL_CALL,
    {
        SRV_CLOG_CATE_CALL,
        MMI_SIM_ALL,
        SRV_CLOG_CLT_ALL,
        SRV_CLOG_CALL_TYPE_ALL
    }
};

const mmi_clog_lt_id_attr_tbl_struct g_mmi_clog_lt_id_attr_tbl = 
{
    4,
    {
        &g_mmi_clog_lt_id_attr_dialed_call,
        &g_mmi_clog_lt_id_attr_missed_call,
        &g_mmi_clog_lt_id_attr_recved_call,
        &g_mmi_clog_lt_id_attr_all_call
    }
};

const mmi_clog_lt_enb_ids_struct g_mmi_clog_lt_enb_ids = 
{
    4,
    {
        MMI_CLOG_LT_ID_ALL_CALL,
        MMI_CLOG_LT_ID_DIALED_CALL,
        MMI_CLOG_LT_ID_MISSED_CALL,
        MMI_CLOG_LT_ID_RECVED_CALL
    }
};

#ifdef __MMI_BT_PBAP_CLIENT__
const mmi_clog_bt_tab_id_struct g_mmi_clog_bt_link_tab_id = 
{
#if SRV_PBAPC_LINK_NUM >= 2
#ifndef __MMI_TELEPHONY_SUPPORT__
    2,
    {
        MMI_CLOG_LT_ID_BT,
        MMI_CLOG_LT_ID_BT_V3
    }
#else
    3,
    {
    
        MMI_CLOG_LT_ID_LOCAL,
        MMI_CLOG_LT_ID_BT,
        MMI_CLOG_LT_ID_BT_V3
    }
#endif
#else
    2,
    {
#ifdef __MMI_TELEPHONY_SUPPORT__
        MMI_CLOG_LT_ID_LOCAL,
#endif
        MMI_CLOG_LT_ID_BT
    }
#endif

};
#endif

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_check_cfg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_check_cfg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_ASSERT(g_mmi_clog_lt_id_attr_tbl.total_num <= MMI_CLOG_LT_ID_MAX_NUM &&
               g_mmi_clog_lt_id_attr_tbl.attrs[g_mmi_clog_lt_id_attr_tbl.total_num - 1] &&
               (g_mmi_clog_lt_id_attr_tbl.total_num == MMI_CLOG_LT_ID_MAX_NUM ||
                g_mmi_clog_lt_id_attr_tbl.total_num < MMI_CLOG_LT_ID_MAX_NUM &&
                !g_mmi_clog_lt_id_attr_tbl.attrs[g_mmi_clog_lt_id_attr_tbl.total_num]));

    MMI_CLOG_IT_ASSERT(g_mmi_clog_lt_enb_ids.total_num <= MMI_CLOG_LT_ID_MAX_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_log_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_IMG_ID mmi_clog_get_log_icon(const srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clog_get_image(idt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_IMG_ID mmi_clog_get_image(const srv_clog_log_identity_struct *idt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    const mmi_clog_lt_clt_img_struct *img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_clog_lt_img_tbl.img_list)
        return 0;

    for (i = 0; i < g_mmi_clog_lt_img_tbl.total_num; i++)
    {
        img = &g_mmi_clog_lt_img_tbl.img_list[i];
        if (!img || !MMI_CLOG_CHECK_BIT(img->sim_id, idt->sim_id) || !MMI_CLOG_CHECK_BIT(img->call_type, idt->sub_type))
            continue;

        for (j = 0; j < MMI_CLOG_LT_CLT_IMG_MAX_NUM; j++)
        {
            if (img->img_map[j].clt_type != idt->log_type)
                continue;
            return img->img_map[j].img_id;
        }
    }
    // MMI_CLOG_ASSERT(!"Wrong idt");    /*  show wrong icon instead of ASSERT */
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_attr_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lt_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const mmi_clog_lt_id_attr_struct *mmi_clog_get_attr_by_lt_id(mmi_clog_lt_id_enum lt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__

    U32 i;
#endif  /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((U32) lt_id < g_mmi_clog_lt_id_attr_tbl.total_num &&
        g_mmi_clog_lt_id_attr_tbl.attrs[lt_id] && g_mmi_clog_lt_id_attr_tbl.attrs[lt_id]->lt_id == lt_id)
    {
        return g_mmi_clog_lt_id_attr_tbl.attrs[lt_id];
    }
#ifndef __MMI_CLOG_COMPUND_ACTION_REJECT_CALL__
    for (i = 0; i < g_mmi_clog_lt_id_attr_tbl.total_num; i++)
    {
        if (g_mmi_clog_lt_id_attr_tbl.attrs[i] && g_mmi_clog_lt_id_attr_tbl.attrs[i]->lt_id == lt_id)
        {
            return g_mmi_clog_lt_id_attr_tbl.attrs[i];
        }
    }
#endif  /*__MMI_CLOG_COMPUND_ACTION_REJECT_CALL__*/
    MMI_CLOG_IT_ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_attr_by_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const mmi_clog_lt_id_attr_struct *mmi_clog_get_attr_by_menu_id(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_clog_lt_id_attr_tbl.total_num; i++)
    {
        if (g_mmi_clog_lt_id_attr_tbl.attrs[i] && g_mmi_clog_lt_id_attr_tbl.attrs[i]->menu_id == menu_id)
        {
            return g_mmi_clog_lt_id_attr_tbl.attrs[i];
        }
    }
    return NULL;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */

