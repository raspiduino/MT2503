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
 *  FactoryGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface for the object factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef FACTORY_GPROT_H
#define FACTORY_GPROT_H

#include "MMIDataType.h"


/* DOM-NOT_FOR_SDK-BEGIN */

/****************************************************************************
 * Define
 ****************************************************************************/

/*
 * <Factory>
 *
 * DESCRIPTION
 *  This is factory object header.
 */
#define MMI_FACTORY_OBJ_HEADER      \
    S16 type;


/****************************************************************************
 * Enum
 ****************************************************************************/

typedef enum
{
    /*
     * <Factory>
     *
     * DESCRIPTION
     *  Invalid type ID.
     *  Applications shall not use this ID for type ID.
     */
    MMI_FACTORY_TYPE_INVALID = -1
} mmi_factory_type_enum;


/****************************************************************************
 * Structure
 ****************************************************************************/

/*
 * <Factory>
 *
 * DESCRIPTION
 *  This is factory object structure.
 */
typedef struct _mmi_factory_obj_struct
{
    MMI_FACTORY_OBJ_HEADER
} mmi_factory_obj_struct;


/****************************************************************************
 * Configuration Definition
 ****************************************************************************/

/*
 * <Factory>
 *
 * DESCRIPTION
 *  decide which object needs to be created
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE when object needs to be created
 */
typedef MMI_BOOL (*mmi_factory_on_want_to_run_cb)(void);


/*
 * <Factory>
 *
 * DESCRIPTION
 *  init function after create object
 * PARAMETERS
 *  object      : [IN] object pointer
 * RETURNS
 *  NULL
 */
typedef void (*mmi_factory_on_init_cb)(void *object);


/*
 * <Factory>
 *
 * DESCRIPTION
 *  deinit function before delete object
 * PARAMETERS
 *  object      : [IN] object pointer
 * RETURNS
 *  NULL
 */
typedef void (*mmi_factory_on_deinit_cb)(void *object);


/*
 * <Factory>
 *
 * DESCRIPTION
 *  Application provides specific allocate function to allocate memory for object
 *  this funciton is in pair with mmi_factory_mfree_func_ptr
 * PARAMETERS
 *  alloc_size      : [IN] request buffer size
 * RETURNS
 *  allocated buffer(void*)
 */
typedef void* (*mmi_factory_malloc_func_ptr)(U32 alloc_size);


/*
 * <Factory>
 *
 * DESCRIPTION
 *  Application provides specific free function to free object
 *  this funciton is in pair with mmi_factory_malloc_func_ptr
 * PARAMETERS
 *  object          : [IN] object pointer
 * RETURNS
 *  allocated buffer(void*)
 */
typedef void (*mmi_factory_mfree_func_ptr)(void *object);


/*
 * <Factory>
 *
 * DESCRIPTION
 *  factory configuration table structure
 * ELEMENTS
 *  type                                    : [IN] object type ID
 *  size                                    : [IN] object size
 *  mmi_factory_on_want_to_run_cb       : [IN] want to run function
 *  mmi_factory_on_init_cb              : [IN] init function
 *  mmi_factory_on_deinit_cb            : [IN] deinit function
 */
typedef struct
{
    S16                                 type;
    U16                                 size;
    mmi_factory_on_want_to_run_cb       on_want_to_run;
    mmi_factory_on_init_cb              on_init;
    mmi_factory_on_deinit_cb            on_deinit;
} mmi_factory_cfg_struct;


/*
 * <Factory>
 *
 * DESCRIPTION
 *  MACRO to add factory configuration table item
 */
#define MMI_FACTORY_CFG_ADD(_type, _size, _on_want_to_run, _on_init, _on_deinit)   \
    {_type, _size, _on_want_to_run, _on_init, _on_deinit}


/*
 * <Factory>
 *
 * DESCRIPTION
 *  MACRO to specify the end of configuration item
 */
#define MMI_FACTORY_CFG_END()                                                      \
    MMI_FACTORY_CFG_ADD(MMI_FACTORY_TYPE_INVALID, 0, NULL, NULL, NULL)


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_factory_get_favorite_type
 * DESCRIPTION
 *  This function gets the favorite type.
 * PARAMETERS
 *  cfg_table      : [IN]       Object config table.
 * RETURNS
 *  type.
 *****************************************************************************/
extern S16 mmi_factory_get_favorite_type(
    const mmi_factory_cfg_struct *cfg_table);


/*****************************************************************************
 * FUNCTION
 *  mmi_factory_new_obj
 * DESCRIPTION
 *  This function news a object.
 * PARAMETERS
 *  cfg_table            : [IN]       Object config table.
 * RETURNS
 *  object.
 *****************************************************************************/
extern mmi_factory_obj_struct *mmi_factory_new_obj(
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_malloc_func_ptr alloc_func);


/*****************************************************************************
 * FUNCTION
 *  mmi_factory_new_obj_ex
 * DESCRIPTION
 *  This function news a specified object.
 * PARAMETERS
 *  type           : [IN]       Type
 *  cfg_table      : [IN]       Object config table.
 * RETURNS
 *  object.
 *****************************************************************************/
extern mmi_factory_obj_struct *mmi_factory_new_obj_ex(
    U16 type,
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_malloc_func_ptr alloc_func);


/*****************************************************************************
 * FUNCTION
 *  mmi_factory_delete_obj
 * DESCRIPTION
 *  This function deletes an object.
 * PARAMETERS
 *  obj           : [IN]        object
 *  cfg_table      : [IN]       Object config table.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_factory_delete_obj(
    mmi_factory_obj_struct *obj,
    const mmi_factory_cfg_struct *cfg_table,
    mmi_factory_mfree_func_ptr free_func);

/* DOM-NOT_FOR_SDK-END */

#endif /* FACTORY_GPROT_H */

