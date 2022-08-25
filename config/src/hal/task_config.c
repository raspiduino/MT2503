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
 *   task_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the source code for configuring the
 *   data structures that hold task configuration info.
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
	(C) _____ (year of first publication) Sasken communication
	Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

/*************************************************************************
* Include Statements
 *************************************************************************/
#include "app_ltlcom.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "dcl.h"
#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#include "fctycomp_config.h"
#ifdef __USB_ENABLE__
#include "usbmscomp_config.h"
#endif
#endif /* __MULTI_BOOT__ */
#include "system_inc.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
/*************************************************************************
* Definitions Of Exported Globals
 *************************************************************************/
task_info_struct *task_info_g;
module_info_struct module_info_g[ MAX_MULTIMOD_TASK_NUM ];
kal_uint32  KALTotalTasks;
kal_uint32  KALTotalModules;

#ifdef SPLIT_SYS
extern const kal_uint8 tst_routing_table[];
/* Tasks created on target side */
kal_uint32 utontarget_task_mask_g[2];
/* Tasks created on PC side */
kal_uint32 utonmnt_task_mask_g[2];
#endif /* SPLIT_SYS */

extern const comptask_info_struct sys_comp_config_tbl[];

#ifdef __MULTI_BOOT__
#ifdef __USB_ENABLE__
kal_uint8 usb_mode_enable = KAL_FALSE;
#endif /*__USB_ENABLE__*/
#endif /* __MULTI_BOOT__ */

/*******************************************************************************
 * Internal Globals
 * these global array is used in kal files
 * they should be defined in config file since config internal macro is used as array size
 *******************************************************************************/
#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif /* __MTK_TARGET__ */

kal_uint32 ilm_allocate_mask_g[RPS_MASK_ARRAY_SIZE] = {0, 0, 0, 0};

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

ilm_struct module_ilm_g[RPS_TOTAL_STACK_MODULES];

kal_uint32 tst_ilm_allocate_mask_g[RPS_MASK_ARRAY_SIZE] = {0,0};
ilm_struct tst_module_ilm_g[LAST_MOD_ID + 1];
module_type task_active_module_g[ RPS_TOTAL_STACK_TASKS ];
#if defined(__MTK_TARGET__) && defined(__KAL_STACK_SHARING__)
extern const kal_uint8 Non_sharing_tasks_g[];
extern kal_uint8 Non_sharing_tasks_size_g;
#endif
/*************************************************************************
* Declarations Of Imported functions
 *************************************************************************/
extern void remap_mod_task_g(void);

extern void *kal_sys_mem_alloc(kal_uint32 size);

#ifdef __MULTI_BOOT__
extern kal_uint16 INT_BootMode(void);

#ifdef __USB_ENABLE__
kal_bool INT_USBBoot(void) 
{
	PW_CTRL_IS_USB_BOOT CtrlVal;
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);
	return (kal_bool)CtrlVal.val;
}
#endif /*__USB_ENABLE__*/

#endif   /* __MULTI_BOOT__ */

/*************************************************************************
* FUNCTION
*  stack_init_comp_info
*
* DESCRIPTION
*   This function configures the information related with
*   inidividual tasks in an array.
*   The configuration is based on following:
*    1. The task configuration information passed.
*    2. compile time flags.
*
*   The configiration information for tasks not present are set
*   to default values.
*
*
* PARAMETERS
*  Input only: TAsk configuration information.
*
* RETURNS
*  KAL_TRUE on success, else KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

kal_bool
stack_init_comp_info(void)
{
   kal_uint32 task_indx, module_id;
   kal_uint8 boot_flag;

   kal_bool result = KAL_TRUE;
   comptask_handler_struct *comp_handler = NULL;
#ifdef SPLIT_SYS
   kal_uint8 mask_offset;
   kal_uint8 mask_pos;
   kal_uint32 i;
#endif /* SPLIT_SYS */
   
   KALTotalTasks = RPS_TOTAL_STACK_TASKS;
   KALTotalModules = RPS_TOTAL_STACK_MODULES;
   
   task_info_g = (task_info_struct *)kal_sys_mem_alloc(sizeof(task_info_struct) * KALTotalTasks);
   ASSERT(task_info_g != NULL);
   
   /* Initialize global task info structure array */

   for (task_indx = 0; task_indx < KALTotalTasks; task_indx++)
   {

      task_info_g[ task_indx ].task_name_ptr   =  RPS_NO_TASK_NAME;
      task_info_g[ task_indx ].task_qname_ptr  =  RPS_QNAME_NIL;
      task_info_g[ task_indx ].task_priority   = RPS_TASK_PRIORITY_NIL;
      task_info_g[ task_indx ].task_stack_size = RPS_STACK_SIZE_NIL;
      task_info_g[ task_indx ].task_id         = KAL_NILTASK_ID;
      task_info_g[ task_indx ].task_ext_qid    = KAL_NILQ_ID;
      task_info_g[ task_indx ].task_int_qid_ptr= NULL;
      task_info_g[ task_indx ].task_entry_func = NULL;
      task_info_g[ task_indx ].task_init_func  = NULL;
      task_info_g[ task_indx ].task_ext_qsize  = RPS_QSIZE_NIL;
   }

   /* assume that the normal mode is the default setting */

#ifdef SPLIT_SYS
   /* Transfer tst routing table module id to task id */
   for (i=MOD_NIL+1; i<LAST_MOD_ID; i++)
   {
      mask_offset = i / 8;
      mask_pos = i % 8;

      if (tst_routing_table[mask_offset] & (0x1 << mask_pos)) {
         /* On MNT PC side */
         mask_offset = mod_task_g[i] / 32;
         mask_pos = mod_task_g[i] % 32;

         utonmnt_task_mask_g[mask_offset] |= (0x1 << mask_pos);
      } else {
         /* On Target side */
         mask_offset = mod_task_g[i] / 32;
         mask_pos = mod_task_g[i] % 32;

         utontarget_task_mask_g[mask_offset] |= (0x1 << mask_pos);
      }
   }

   /* Both MNT, Target side need TST/TST Reader Tasks */
   i = INDX_TST;
   mask_offset = mod_task_g[i] / 32;
   mask_pos = mod_task_g[i] % 32;
   utonmnt_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);
   utontarget_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);

   i = INDX_TST_READER;
   mask_offset = mod_task_g[i] / 32;
   mask_pos = mod_task_g[i] % 32;
   utonmnt_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);
   utontarget_task_mask_g[mask_offset] &= ~(0x1 << mask_pos);

#ifdef __MTK_TARGET__
   redirect_task_mask_g = (kal_uint32*)&utonmnt_task_mask_g;
#else
   redirect_task_mask_g = (kal_uint32*)&utontarget_task_mask_g;
#endif /* __MTK_TARGET__ */

#endif /* SPLIT_SYS */

   /* Initialize global task info structure array according to component info */
   for (task_indx = 0; task_indx < KALTotalTasks; task_indx++)
   {
	   task_info_g[ task_indx ].task_name_ptr   = sys_comp_config_tbl[task_indx].comp_name_ptr;
	   task_info_g[ task_indx ].task_qname_ptr  = sys_comp_config_tbl[task_indx].comp_qname_ptr;
	   task_info_g[ task_indx ].task_priority   = sys_comp_config_tbl[task_indx].comp_priority;
	   task_info_g[ task_indx ].task_stack_size = sys_comp_config_tbl[task_indx].comp_stack_size;
#ifdef __SYS_INTERN_RAM__
	   task_info_g[ task_indx ].task_internal_ram_stack = sys_comp_config_tbl[task_indx].comp_internal_ram_stack;
#endif /* __SYS_INTERN_RAM__ */

	   task_info_g[ task_indx ].task_stack_size = sys_comp_config_tbl[task_indx].comp_stack_size;
           task_info_g[ task_indx].task_ext_qsize = sys_comp_config_tbl[task_indx].comp_ext_qsize;

	   task_info_g[ task_indx ].task_int_qsize = sys_comp_config_tbl[task_indx].comp_int_qsize;

       /*Check whether the task should be created or mis-configured*/
	   if ((sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)TASK_NO_CREATE_PATTERN ) 
#ifdef SPLIT_SYS
			   || (*(redirect_task_mask_g + (task_indx >> 5)) & (0x1 << (task_indx & 31)))
#endif /* SPLIT_SYS */
	      )
	   {
		   continue; 
	   }
	   else if((sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)KAL_FALSE) ||
               (sys_comp_config_tbl[task_indx].comp_create_func == (kal_create_func_ptr)KAL_TRUE))
       {/*
           This is task mis-configured case. This occurs code like 
            #ifdef xxx
                task_create_function(yyy)
            #endif
           missing the null_task_create_entry as the else branch.
         
           The assumption is that task_stack_internalRAM(KAL_FALSE or KAL_TRUE)
           following task create function
       */
            kal_fatal_error_handler(KAL_ERROR_KALINIT_INIT_FAILED, task_indx);
       }
       else if (sys_comp_config_tbl[task_indx].comp_create_func(&comp_handler) != KAL_TRUE)
	   {
		   continue;
	   }

	   /* component task entry function */
	   /*Null task_entry_func indicates the task will not create*/
	   task_info_g[ task_indx ].task_entry_func =
		   comp_handler->comp_entry_func;

	   /* component task initialization handler */
	   task_info_g[ task_indx ].task_init_func =
		   comp_handler->comp_init_func;

	   /* component task configuration handler */
	   task_info_g[ task_indx ].task_cfg_func =
		   comp_handler->comp_cfg_func;

	   /* component task reset handler */
	   task_info_g[ task_indx ].task_reset_func =
		   comp_handler->comp_reset_func;

	   /* component task termination handler */
	   task_info_g[ task_indx ].task_end_func =
		   comp_handler->comp_end_func;

#ifdef __MULTI_BOOT__
	   if (INT_BootMode() == MTK_FACTORY_MODE)
	   {
		      boot_flag = sys_comp_config_tbl[task_indx].comp_boot_mode & FACTORY_M;
		      if(0 == boot_flag)
		      {
			      task_info_g[ task_indx ].task_entry_func = NULL;
			      for(module_id = 0; module_id < KALTotalModules; module_id++)
			      {
				    if(task_indx == mod_task_g[module_id])
				    {
					    mod_task_g[module_id] = INDX_NIL;
				    }
			      }
		      }
	   }
#ifdef __USB_ENABLE__
	   else if( INT_USBBoot() )
	   {
		   boot_flag = sys_comp_config_tbl[task_indx].comp_boot_mode & USB_M;
		   if(0 == boot_flag)
		   {
			   task_info_g[ task_indx ].task_entry_func = NULL;
			   for(module_id = 0; module_id < KALTotalModules; module_id++)
			   {
				   if(task_indx == mod_task_g[module_id])
				   {
					   mod_task_g[module_id] = INDX_NIL;
				   }
			   }
		   }
	   }
#endif /* __MULTI_BOOT__ */
	  else 
#endif /* __USB_ENABLE__ */
	   {
		   boot_flag = sys_comp_config_tbl[task_indx].comp_boot_mode & NORMAL_M;
		   if(boot_flag == 0)
		   {
			   task_info_g[ task_indx ].task_entry_func = NULL;
			   for(module_id = 0; module_id < KALTotalModules; module_id++)
			   {
				   if(task_indx == mod_task_g[module_id])
				   {
					   mod_task_g[module_id] = INDX_NIL;
				   }
			   }
		   }
	   }
	   /*
	   mask_offset = task_indx / 32;
	   mask_pos = task_indx % 32;    */
   }
	  
   result = stack_init_module_info();

   return result;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  stack_init_module_info
*
* DESCRIPTION
*  The function implements component task's modules information including
*  initialization, configuration, reset, termination handler.
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE on success, else KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
stack_init_module_info( void )
{
   /* According to feature customization,
      remap mod_task_g to overwrite internal configuration */
   remap_mod_task_g();

   return KAL_TRUE;
}

/*******************************************************************************
 * FUNCTION
 *  kal_get_task_total_number
 * DESCRIPTION
 *  query total task index number.
 * PARAMETERS
 *  NA.
 * RETURNS
 *  Return total task index number. 
 * GLOBALS AFFECTED
 *
 ******************************************************************************/
kal_uint32 kal_get_task_total_number(void)
{
    return (kal_uint32)RPS_TOTAL_STACK_TASKS;
}

/*******************************************************************************
 * FUNCTION
 *  kal_get_send_msg_module_id_total_number
 * DESCRIPTION
 *  query total module id number that can send message.
 * PARAMETERS
 *  NA.
 * RETURNS
 *  Return total module id number that can send message.
 * GLOBALS AFFECTED
 *
 ******************************************************************************/
kal_uint32 kal_get_send_msg_module_id_total_number(void)
{
    return (kal_uint32)RPS_TOTAL_STACK_MODULES;
}

#if defined(__MTK_TARGET__) && defined(__KAL_STACK_SHARING__)

kal_bool kal_is_task_stack_nonshareable(kal_uint32 task_index)
{
	kal_uint8 i=0;

	if( (task_index >= INDX_MTKTASKEND) || (task_info_g[task_index].task_stack_size >= KAL_STACK_MAX_SHARING_SIZE) )
	{
		return KAL_TRUE; /* CUSTOM TASK will not be involved in stack sharing. */
	}
	for(i=0; i< Non_sharing_tasks_size_g; i++)
	{
		if(task_index == Non_sharing_tasks_g[i])
		{
			return KAL_TRUE;
		}
	}
	return KAL_FALSE;	
}

#endif
