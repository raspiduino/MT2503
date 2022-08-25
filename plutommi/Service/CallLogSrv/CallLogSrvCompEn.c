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
*  CallLogSrvCompEn.c
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
#include "mmi_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "lcd_cqueue.h"

#include "custom_calllog.h"
#include "nvram_common_defs.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"
#include "CallLogSrvComp.h"
#include "CallLogSrvProt.h"

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

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/* Component initialization */
static void srv_clog_comp_reset(srv_clog_comp_struct *comp);
static S32 srv_clog_stl_is_bit_style(U32 type, U32 *grp);


/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_COMP_COMP


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_new_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job             [?]         
 *  para_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_clog_comp_new_para(U32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para_size == 0)
        return NULL;
    
    para = SRV_CLOG_MALLOC(SRV_CLOG_MEM_TYPE_TEMP, para_size);
    memset(para, 0x0, para_size);
    return para;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 *  cntx            [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_comp_struct *srv_clog_comp_create(U32 mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_comp_struct *comp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = SRV_CLOG_TALLOC(mem_type, srv_clog_comp_struct);
    srv_clog_comp_reset(comp);
    
    return comp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  comp        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_comp_destroy(srv_clog_comp_struct *comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_SYS, comp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  comp        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_comp_reset(srv_clog_comp_struct *comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp->style_mgr = NULL;
    comp->si_tbl = NULL;
    comp->idx_tbl = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_comp_create_elments
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type            [IN]        
 *  comp                [?]         
 *  st_user_data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_comp_create_elments(U32 mem_type, srv_clog_comp_struct *comp, void *st_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init style manager */
    comp->style_mgr = srv_clog_stl_create(mem_type);

    /* Init sort info table */
    comp->si_tbl = srv_clog_si_tbl_create(SRV_CLOG_MEM_TYPE_SYS);

    /* Init index info table */
    comp->idx_tbl = srv_clog_idx_create(SRV_CLOG_MEM_TYPE_SYS, comp->si_tbl, comp->style_mgr);
}


/*----------------------------------------------------------------------------*/
/* Style Manager                                                              */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_COMP_STYLE


/*****************************************************************************
 * FUNCTION
 *  srv_clog_set_def_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  style       [IN]        
 *  data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_set_def_style(U32 type, U32 style, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(SRV_CLOG_RET_OK != srv_clog_stl_valid(type, style, data, MMI_FALSE), SRV_CLOG_RET_INVALID_PARAM);

    /* Should first to init the service module */
    SRV_CLOG_PARAM_CHECK (!srv_clog_is_init(), SRV_CLOG_RET_NOT_INIT);

    if (srv_clog_is_ready())
        return SRV_CLOG_RET_NOT_AVAILABLE;

    ret = srv_clog_stl_set_style(srv_clog_cntx_p->comp->style_mgr, type, style, data);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_SET_DEF_STYLE, type, style, data == NULL ? 0 : (U32) data, ret));
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_get_def_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  style       [?]         
 *  data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_get_def_style(U32 type, U32 *style, void **data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(type >= SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM && type < SRV_CLOG_STYLE_TYPE_BASE ||
        type >= SRV_CLOG_STYLE_TYPE_MAX_ITEM || !style, SRV_CLOG_RET_INVALID_PARAM);

    /* Should first to init the service module */
    SRV_CLOG_PARAM_CHECK (!srv_clog_is_init(), SRV_CLOG_RET_NOT_INIT);

    ret = srv_clog_stl_get_style(srv_clog_cntx_p->comp->style_mgr, type, style, data);

    SRV_CLOG_IT_TRACE((SRV_CLOG_TRC_INFO, TRC_SRV_CLOG_GET_DEF_STYLE, type, *style));
    return ret;
}

/* once set its style, should set all style to it. */


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_stl_mgr_struct *srv_clog_stl_create(U32 mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_stl_mgr_struct *stl_mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stl_mgr = SRV_CLOG_TALLOC(mem_type, srv_clog_stl_mgr_struct);
    memset(stl_mgr, 0x0, sizeof(srv_clog_stl_mgr_struct));
    return stl_mgr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_stl_destroy(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_SYS, style_mgr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_set_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]         
 *  type            [IN]        
 *  style           [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_set_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 style, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    U32 grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = srv_clog_stl_is_bit_style(type, &grp);
    if (idx >= 0)
    {
        if (style)
            SRV_CLOG_SET_BIT(style_mgr->bit_styles[idx], style);
        else
            SRV_CLOG_CLEAR_BIT(style_mgr->bit_styles[idx], grp);
        return SRV_CLOG_RET_OK;
    }
    return SRV_CLOG_RET_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_get_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]         
 *  type            [IN]        
 *  style           [?]         
 *  data            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_get_style(srv_clog_stl_mgr_struct *style_mgr, U32 type, U32 *style, void **data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    U32 grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!style, SRV_CLOG_RET_INVALID_PARAM);
    
    idx = srv_clog_stl_is_bit_style(type, &grp);
    if (idx >= 0)
    {
        *style = SRV_CLOG_GET_BIT(style_mgr->bit_styles[idx], grp);
        if (data)
            *data = NULL;
        return SRV_CLOG_RET_OK;
    }
    *style = 0;
    return SRV_CLOG_RET_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  style           [IN]        
 *  data            [?]         
 *  is_special      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_valid(U32 type, U32 style, void *data, S32 is_special)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_PARAM_CHECK(!(type < SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM ||
          type >= SRV_CLOG_STYLE_TYPE_BASE && type < SRV_CLOG_STYLE_TYPE_MAX_ITEM),
          SRV_CLOG_RET_INVALID_PARAM);

    if (is_special)
    {
        if (type < SRV_CLOG_STYLE_TYPE_DEF_MAX_ITEM)
            return SRV_CLOG_RET_NOT_SUPPORT;    /* not support handle's style now */
    }
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_is_bit_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  grp         [?]         
 * RETURNS
 *  The index of the style array which has this style
 *****************************************************************************/
static S32 srv_clog_stl_is_bit_style(U32 type, U32 *grp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    static const U8 bit_styles_1[] = 
    {
        SRV_CLOG_STYLE_TYPE_MERGE,
        SRV_CLOG_STYLE_TYPE_NUM,
        
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        SRV_CLOG_STYLE_TYPE_SIM_SYNC,
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        SRV_CLOG_STYLE_TYPE_PHB_SYNC,
#endif
    };

    static const U32 bit_style_grp_1[] = 
    {
        SRV_CLOG_STYLE_MERGE_GRP,
        SRV_CLOG_STYLE_NUM_GRP,
        
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
        SRV_CLOG_STYLE_SIM_SYNC_GRP,
#endif

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
        SRV_CLOG_STYLE_PHB_SYNC_GRP,
#endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(bit_styles_1) / sizeof(U8); i++)
    {
        if (type == bit_styles_1[i])
        {
            if (grp)
                *grp = bit_style_grp_1[i];
            return 0; /* Only one element in style array */
        }
    }
    /* TODO: continue to check next bit group */

    return -1;
}


#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_sim_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_sim_sync(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sync_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_SIM_SYNC, &sync_style, NULL);
    if (SRV_CLOG_CHECK_BIT(sync_style, SRV_CLOG_STYLE_SIM_SYNC_READ | SRV_CLOG_STYLE_SIM_SYNC_WRITE))
        return MMI_TRUE;
    return MMI_FALSE;
}
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */


#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_phb_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_phb_sync(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sync_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_PHB_SYNC, &sync_style, NULL);
    if (sync_style)
        return MMI_TRUE;
    return MMI_FALSE;
}
#endif //0

/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_merge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_merge(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 merge_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);
    if (merge_style)
        return MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_stl_support_thread
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style_mgr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_clog_stl_support_thread(srv_clog_stl_mgr_struct *style_mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 merge_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_clog_stl_get_style(style_mgr, SRV_CLOG_STYLE_TYPE_MERGE, &merge_style, NULL);

    if (SRV_CLOG_CHECK_BIT(merge_style, SRV_CLOG_STYLE_MERGE_THREAD))
        return MMI_TRUE;
    return MMI_FALSE;
}

