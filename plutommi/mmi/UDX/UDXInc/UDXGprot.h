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
 *  UDXGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX Agent interface.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _UDX_GPROT_H
#define _UDX_GPROT_H

#include "mmi_features.h"

#ifdef __MMI_UDX_SUPPORT__

#include "MMIDataType.h"
#include "mmi2udx_struct.h"
#include "filemgrsrvgprot.h"

/* udx support type now */
typedef enum
{
#ifdef __MMI_UDX_VCARD_SUPPORT__
    MMI_UDX_TYPE_VCARD,    
#endif

    /* add new type befor this line */
    MMI_UDX_TYPE_TOTAL
} mmi_udx_type_support_enum;


/* udx data use way */
typedef enum
{
    MMI_UDX_DATA_USE_ADD,
    MMI_UDX_DATA_USE_REPLACE,
    
    MMI_UDX_DATA_USE_TOTAL
} mmi_udx_data_use_way_enum;


/* App should provide the api below */
typedef void (*mmi_udx_func_ptr_show_select_scr) (void);                             
typedef void (*mmi_udx_func_ptr_get_data) (void*, U16);   
typedef void (*mmi_udx_func_ptr_store_data) (void*);


/* Global Function */
extern void mmi_udx_init(void);
extern MMI_BOOL mmi_udx_is_busy(MMI_BOOL pop_up);
extern MMI_BOOL mmi_udx_is_reentry(MMI_BOOL popup);
extern void mmi_udx_parsing_launch(mmi_id caller_id, CHAR *path);
extern void mmi_udx_building_launch(mmi_id caller_id, void* index_hdlr, U16 count, U8 data_type);
extern void mmi_udx_delete_fmgr_service_screen(void);
extern mmi_ret mmi_udx_driver_plug_out_event_hdlr(mmi_event_struct *param);
extern MMI_BOOL mmi_udx_phb_is_processing(MMI_BOOL is_popup);
extern void mmi_udx_fmgr_to_udx_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
extern void mmi_udx_entry_group_main_menu(void);

#endif /* __MMI_UDX_SUPPORT__ */
#endif /* _UDX_GPROT_H */
