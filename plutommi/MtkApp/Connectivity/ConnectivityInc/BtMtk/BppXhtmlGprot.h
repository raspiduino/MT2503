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
* BppXhtmlGprot.h
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   This file is for Bluetooth BPP XHTML module external interface declaration.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef BPP_XHTML_GPROT_H
#define BPP_XHTML_GPROT_H
#include "MMI_features.h"

#ifdef __MMI_BPP_SUPPORT__
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR add end */
/***************************************************************************** 
* Constant definition
*****************************************************************************/
enum {
    XHTML_OUT_FILE,
    XHTML_OUT_BUFF,
    XHTML_OUT_END
};

typedef U32 XhtmlRuleType;
enum {
    STYLE_RULE_SYSTEM,
    STYLE_RULE_ID,
    STYLE_RULE_CLASS,
    STYLE_RULE_ELEMENT,
    STYLE_RULE_END
};

typedef struct {
    CHAR *name;
    CHAR *value;
} xhtml_prop_struct;

typedef struct {
    const CHAR *name;
    const CHAR *element;
    XhtmlRuleType type;
    const xhtml_prop_struct *props;
    U32 prop_count;
} xhtml_rule_struct;

typedef struct {
    const CHAR *name;
    const CHAR *value;
} xhtml_attr_struct;

typedef struct {
	xhtml_attr_struct *attrs;
	U32 count;
} xhtml_attr_list_struct;

typedef struct {
    CHAR *name;
    xhtml_attr_list_struct *attr_list;
} xhtml_element_struct;

typedef struct {
    CHAR *ptr;
    U32 size;
} xhtml_buff_struct;

typedef struct {
    U32 type;
    union {
        xhtml_buff_struct buff;
        WCHAR *file;
    } u;
} xhtml_output_struct;

typedef struct {
    U32 width;
    U32 height;
    U32 size;
    WCHAR *src;
    CHAR *type;
} xhtml_img_attr_struct;

typedef struct {
    U32 size;
    WCHAR *src;
    CHAR *type;
} xhtml_obj_attr_struct;

#define XHTML_VER_100                "1.0"
#define XHTML_VER_095                "0.95"

#define XHTML_STYLE_PAGE            "page"
#define XHTML_STYLE_TOP             "top"
#define XHTML_STYLE_BOTTOM          "bottom"

#define XHTML_PROP_SIZE             "size"
#define XHTML_PROP_COUNTER          "counter-increment"
#define XHTML_PROP_MARGIN_TOP       "margin-top"
#define XHTML_PROP_MARGIN_BOTTOM    "margin-bottom"
#define XHTML_PROP_MARGIN_LEFT      "margin-left"
#define XHTML_PROP_MARGIN_RIGHT     "margin-right"

#define XHTML_PROP_COLOR            "color"
#define XHTML_PROP_BK_COLOR         "background-color"
#define XHTML_PROP_WIDTH            "width"
#define XHTML_PROP_BORDER_LEFT      "border-left"
#define XHTML_PROP_BORDER_RIGHT     "border-right"
#define XHTML_PROP_BORDER_TOP       "border-top"
#define XHTML_PROP_BORDER_BOTTOM    "border-bottom"
#define XHTML_PROP_BORDER_COLLAPSE  "border-collapse"
#define XHTML_PROP_BORDER_SPACE     "border-spacing"
#define XHTML_PROP_BORDER_WIDTH     "border-width"
#define XHTML_PROP_TEXT_ALIGN       "text-align"
#define XHTML_PROP_VERTICAL_ALIGN   "vertical-align"
#define XHTML_PROP_CONTENT          "content"
#define XHTML_PROP_LINE_HEIGHT      "line-height"
#define XHTML_PROP_FONT_SIZE        "font-size"
#define XHTML_PROP_FONT_WEIGHT      "font-weight"
#define XHTML_PROP_FONT_STYLE       "font-style"
#define XHTML_PROP_TEXT_DECORATION  "text-decoration"

#define XHTML_PROP_PADDING          "padding"
#define XHTML_PROP_PADDING_LEFT     "padding-left"
#define XHTML_PROP_PADDING_RIGHT    "padding-right"

#define XHTML_ELE_HEAD              "head"
#define XHTML_ELE_BODY              "body"
#define XHTML_ELE_TITLE             "title"
#define XHTML_ELE_CAPTION           "caption"
#define XHTML_ELE_DIV               "div"
#define XHTML_ELE_PARA              "p"
#define XHTML_ELE_SPAN              "span"
#define XHTML_ELE_TABLE             "table"
#define XHTML_ELE_TABLE_ROW         "tr"
#define XHTML_ELE_TABLE_CELL        "td"
#define XHTML_ELE_IMAGE             "img"
#define XHTML_ELE_INLINE            "bpp-inline"

#define XHTML_ATTR_WIDTH            "width"
#define XHTML_ATTR_HEIGHT           "height"
#define XHTML_ATTR_CLASS            "class"
#define XHTML_ATTR_ALIGN            "align"
#define XHTML_ATTR_SRC              "src"
#define XHTML_ATTR_INLINE_SIZE      "inline-size"
#define XHTML_ATTR_TYPE             "type"

#define XHTML_LEFT                  "left"
#define XHTML_RIGHT                 "right"
#define XHTML_CENTER                "center"
#define XHTML_TOP                   "top"
#define XHTML_BOTTOM                "bottom"

/***************************************************************************** 
* External interface declaration
*****************************************************************************/
void *bpp_xhtml_open(const CHAR *version, xhtml_output_struct *output);
U32 bpp_xhtml_close(void *xhtml);

S32 bpp_xhtml_style_begin(void *xhtml, const CHAR *type);
S32 bpp_xhtml_style_rule(void *xhtml, const xhtml_rule_struct *rules, U32 count);
S32 bpp_xhtml_rule_begin(void *xhtml, const xhtml_rule_struct *rule);
S32 bpp_xhtml_rule_end(void *xhtml);
S32 bpp_xhtml_style_end(void *xhtml);

S32 bpp_xhtml_element_begin(void *xhtml, const CHAR *name, xhtml_attr_struct *attrs, U32 count);
S32 bpp_xhtml_element_data(void *xhtml, const CHAR *data);
S32 bpp_xhtml_element_end(void *xhtml, const CHAR *name);

S32 bpp_xhtml_image_element(void *xhtml, xhtml_img_attr_struct *attr);
S32 bpp_xhtml_object_element(void *xhtml, xhtml_obj_attr_struct *attr);

S32 bpp_xhtml_inline_element(void *, const CHAR *, xhtml_attr_struct *, U32, CHAR *);
S32 bpp_xhtml_empty_element(void *xhtml, const CHAR *name, xhtml_attr_struct *attrs, U32 count);

#endif /* __MMI_BPP_SUPPORT__ */

#endif /* BPP_XHTML_GPROT_H */

