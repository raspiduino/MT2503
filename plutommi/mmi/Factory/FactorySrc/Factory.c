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
 *  Factory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the object factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "FactoryGprot.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_factory_get_next_cfg
 * DESCRIPTION
 *  This function gets the next config of the object.
 * PARAMETERS
 *  cfg           : [IN]      Object config.
 * RETURNS
 *  Object config.
 *****************************************************************************/
static const mmi_factory_cfg_struct *mmi_factory_get_next_cfg(
    const mmi_factory_cfg_struct *cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cfg || cfg[1].type == MMI_FACTORY_TYPE_INVALID)
    {
        return NULL;
    }

    return &(cfg[1]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_factory_get_cfg
 * DESCRIPTION
 *  This function gets a specified object config.
 * PARAMETERS
 *  type           : [IN]      Type
 * RETURNS
 *  Object config.
 *****************************************************************************/
const mmi_factory_cfg_struct *mmi_factory_get_cfg(
    U16 type,
    const mmi_factory_cfg_struct *cfg_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_factory_cfg_struct *cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cfg = &cfg_table[0]; cfg; cfg = mmi_factory_get_next_cfg(cfg))
    {
        if (cfg->type == type)
        {
            return cfg;
        }
    }

    return NULL;
}


/* For the detail information, please refer to the FactoryGprot.h */
S16 mmi_factory_get_favorite_type(
    const mmi_factory_cfg_struct *cfg_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_factory_cfg_struct *cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cfg = &cfg_table[0]; cfg; cfg = mmi_factory_get_next_cfg(cfg))
    {
        if (cfg->on_want_to_run && cfg->on_want_to_run())
        {
            return cfg->type;
        }
    }

    return MMI_FACTORY_TYPE_INVALID;
}


/* For the detail information, please refer to the FactoryGprot.h */
mmi_factory_obj_struct *mmi_factory_new_obj_ex(
    U16 type,
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_malloc_func_ptr alloc_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_factory_cfg_struct *cfg;
    mmi_factory_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfg = mmi_factory_get_cfg(type, cfg_table);
    if (!cfg)
    {
        return NULL;
    }

    obj = (mmi_factory_obj_struct *)alloc_func(cfg->size);

    kal_mem_set(obj, 0, cfg->size);

    obj->type = type;

    if (cfg->on_init)
    {
        cfg->on_init(obj);
    }

    return obj;
}


/* For the detail information, please refer to the FactoryGprot.h */
mmi_factory_obj_struct *mmi_factory_new_obj(
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_malloc_func_ptr alloc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_factory_get_favorite_type(cfg_table);

    if (type == MMI_FACTORY_TYPE_INVALID)
    {
        return NULL;
    }

    return mmi_factory_new_obj_ex(type, cfg_table, alloc);
}


/* For the detail information, please refer to the FactoryGprot.h */
void mmi_factory_delete_obj(
    mmi_factory_obj_struct *obj,
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_mfree_func_ptr free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_factory_cfg_struct *cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    cfg = mmi_factory_get_cfg(obj->type, cfg_table);

    MMI_ASSERT(cfg);

    if (cfg->on_deinit)
    {
        cfg->on_deinit(obj);
    }

    free_func(obj);
}

