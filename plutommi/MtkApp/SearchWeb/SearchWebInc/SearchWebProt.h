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
 *  SearchWebProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface definition of search feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_SEARCH_WEB_PROT_H__
#define __MMI_SEARCH_WEB_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "Conversions.h"        /* CHSET */
#include "nvram_common_defs.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "common_nvram_editor_data_item.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM        NVRAM_EF_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM

#define MMI_SEARCH_WEB_MAX_NUM_OF_HOT_KEYS          (4)

#define MMI_SEARCH_WEB_TRACE_GROUP                  MMI_COMMON_TRC_G1_SEARCH_WEB


/****************************************************************************
 * Functions
 ****************************************************************************/

#define mmi_sweb_to_hex_char(val) (CHAR)((val) < 10 ? ('0' + (val)) : ('A' + ((val) - 10)))
#define mmi_sweb_is_alphabet(ch)  (((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z'))
#define mmi_sweb_is_digit(ch)     ((ch) >= '0' && (ch) <= '9')

extern MMI_BOOL mmi_sweb_to_hex_encoding(const U8 *raw_data, U32 data_size, CHAR *dest_str, U32 dest_buffer_size);
extern CHAR *mmi_sweb_append_url_param(CHAR *dest_url, MMI_BOOL first_param, const CHAR *param_name, const CHAR *param_val);
extern CHAR *mmi_sweb_append_url_param_int(CHAR *dest_url, MMI_BOOL first_param, const CHAR *param_name, const U32 param_val);
extern CHAR *mmi_sweb_append_url_param_ucs2(
    CHAR *dest_url,
    MMI_BOOL first_param,
    const CHAR *param_name,
    const U16 *param_val,
    mmi_chset_enum target_encoding,
    U32 url_buffer_size,
    MMI_BOOL *truncated);
extern U16 *mmi_sweb_trim(const U16 *src, U16 *dest);
extern CHAR *mmi_sweb_strcat(register CHAR *dest, register const CHAR *string);
extern MMI_BOOL mmi_sweb_read_common_history(nvram_ef_search_web_history_struct *history);
extern MMI_BOOL mmi_sweb_write_common_history(const nvram_ef_search_web_history_struct *history);
extern void mmi_sweb_put_into_history(nvram_ef_search_web_history_struct *history, const U16 *string);
extern const nvram_ef_search_web_history_entry_struct *mmi_sweb_get_history_entry(
    const nvram_ef_search_web_history_struct *history,
    U32 index);
extern void mmi_sweb_clear_history(nvram_ef_search_web_history_struct *history);
    
#endif /* __MMI_SEARCH_WEB_PROT_H__ */

