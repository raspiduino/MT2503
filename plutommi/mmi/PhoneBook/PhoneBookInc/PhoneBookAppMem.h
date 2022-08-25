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
 *  PhoneBookAppMem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Phonebook memory management functions.
 *
 * Author:
 * -------
 *  
 *
 *
 *  
 * 
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PHONEBOOK_APP_MEM_H__
#define __PHONEBOOK_APP_MEM_H__

#include "kal_public_defs.h"
#include "MMIDataType.h"
#include "PhbSrvGprot.h"

#ifndef __MMI_PHONEBOOK_MEM_SLIM__
#define __MMI_PHONEBOOK_MEM_SLIM__
#endif


#define  MMI_PHONEBOOK_MEM_POOL_SIZE                        (MMI_PHB_EDIT_MEM + MMI_PHB_LIST_MEM + MMI_PHB_OTHER_MEM) 

extern BOOL g_phonebook_is_asm_created_by_others;
extern void *g_phonebook_memory_pool_ptr ;
extern void *g_phonebook_view_memory_pool_ptr ;


typedef struct
{
    void *mem_ptr;
    KAL_ADM_ID mem_adm_id;
} mmi_phonebook_app_mem_cntx_struct;


extern void mmi_phonebook_app_mem_init(void);
extern void *mmi_phonebook_app_mem_pool_malloc(U32 size);
extern void mmi_phonebook_app_mem_pool_free(void *ptr);
extern void *mmi_phonebook_app_mem_malloc(U32 size,srv_phb_memory_type_enum type);
extern void mmi_phonebook_app_mem_free(void *ptr);
extern void *mmi_phonebook_app_mem_get_ptr(void);
/*
extern void *mmi_phoneboook_select_contact_asm_create(void (*caller)(void));
extern void mmi_phoneboook_select_contact_asm_destroy(void);
*/


#ifdef __MMI_PHONEBOOK_MEM_SLIM__

#define mmi_phb_mem_malloc(size, type)          mmi_phonebook_app_mem_malloc(size,type)
#define mmi_phb_mem_free(memblock)              mmi_phonebook_app_mem_free(memblock)

#else

#define mmi_phb_mem_malloc(size, type)          srv_phb_mem_malloc(size, type)
#define mmi_phb_mem_free(memblock)              srv_phb_mem_free(memblock)

#endif


/*

extern void* srv_phb_mem_malloc_ext(S32 size, srv_phb_memory_type_enum type, const char* file, int line);


extern void srv_phb_mem_free_ext(void* memblock, const char* file, int line);
*/

#endif /* __PHONEBOOK_APP_MEM_H__ */
