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
 * app_html.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for html related operations.
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
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_HTML_H
#define _APP_HTML_H

/****************************************************************************** 
 * Include
 ******************************************************************************/
#include "kal_general_types.h"

/****************************************************************************** 
 * Constant
 ******************************************************************************/

/* 10 = "BLOCKQUOTE"; 1 = '/'; 1 = '>'; */
#define APPLIB_HTML_MAX_TAG_CHECK_LENGTH             (10 + 1 + 1)

/* 10 = "&thetasym;" */
#define APPLIB_HTML_MAX_CHARACTER_ENTITY_NAME_LENGTH (10)

#define APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR           (4)

/****************************************************************************** 
 * ENUM
 ******************************************************************************/
typedef enum
{
    APPLIB_HTML_COMMENT_ENUM,
    APPLIB_HTML_SCRIPT_ENUM,
    APPLIB_HTML_STYLE_ENUM,
    APPLIB_HTML_BLOCK_ELEMENT_ENUM,
    APPLIB_HTML_TAG_END_OF_ENUM
} applib_html_tag_enum;

typedef struct applib_html_plaintext_context_st
{
    kal_uint32 pos;
    kal_uint32 incomplete_size;
    kal_uint8  open_bracket;
    kal_uint8  open_entity;
    kal_uint8  open_tag[APPLIB_HTML_TAG_END_OF_ENUM];
    kal_uint8  linefeed;
    kal_uint8  space;
    kal_uint8  incomplete_buf[APPLIB_HTML_MAX_TAG_CHECK_LENGTH];
} applib_html_plaintext_context_struct;

/****************************************************************************** 
 * External Function
 ******************************************************************************/

extern void applib_html_extract_plaintext_init(
                    applib_html_plaintext_context_struct *context);

extern kal_bool applib_html_extract_plaintext_parse(
                    applib_html_plaintext_context_struct *context,
                    kal_uint8 is_final,
                    kal_uint8 *input_data,
                    kal_uint32 input_size,
                    kal_uint8 *output_buf,
                    kal_uint32 *output_size,
                    kal_uint32 *read_size);

extern kal_bool applib_html_cvt_char_ref(
                    const kal_char *input,
                    const kal_int32 input_size,
                    kal_char *output,
                    kal_int32 *output_size);

#endif /* _APP_HTML_H */ 

