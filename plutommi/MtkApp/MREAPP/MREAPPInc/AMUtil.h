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
*  AMUtil.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AM Utility file.
*
* Author:
* -------
 * -------
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_UTIL_H
#define AM_UTIL_H

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "AMDef.h"
#include "AMProxy.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_AM_IN_USE = 0,
    MMI_AM_OUT_OF_USE
} MMI_AM_STATES;

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern S8 mmi_am_get_home_driver(void);
extern S8 mmi_am_get_system_driver(void);
extern S8 mmi_am_get_removeable_driver(void);
extern void *mmi_am_malloc(int size);
extern void *mmi_am_calloc(int size);
extern void mmi_am_free(void *ptr);
extern U32 mmi_am_get_total_left_size(void);
extern S32 mmi_am_get_font_height(void);
extern void mmi_am_get_rom_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr);
extern MMI_BOOL mmi_am_get_zimo_string_data(U8 *source, U8 **p_str, S32 *font_size);
extern S32 mmi_am_measure_zimo(U8 *zimo_buf, S32 str_len);
extern void mmi_am_draw_zimo(
                             S32 x,
                             S32 y,
                             S32 start_idx,
                             S32 out_str_len,
                             U8 *src_buf,
                             S32 str_len,
                             S32 font,
                             gdi_color color);
extern MMI_BOOL mmi_am_is_support_wifi(void);
extern S32 mmi_am_get_sim_card_num(void);
extern MMI_BOOL mmi_am_is_network_service_available(void);
extern void mmi_am_mre_set_am_state(MMI_AM_STATES state);
extern MMI_BOOL mmi_am_is_app_downloaded(S8 *app_name, U16 *app_path);
extern MMI_BOOL mmi_am_is_appstore_in_rom(U16 *app_path);

#endif /* AM_UTIL_H */ 

