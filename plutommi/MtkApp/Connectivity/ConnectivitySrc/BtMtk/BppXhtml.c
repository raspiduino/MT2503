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
 * BppXhtml.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BPP XHTML generation implementation.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "Conversions.h"
#include "BppXhtml.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "BppXhtmlGprot.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "kal_general_types.h"
/* auto add by kw_check end */
#ifdef __MMI_BPP_SUPPORT__
void *bpp_xhtml_open(const CHAR *version, xhtml_output_struct *output)
{
    xhtml_ctrl_block *xcb;
    CHAR *t_buff;

    if (!version || !output)
        return NULL;

    xcb = get_ctrl_buffer(sizeof(*xcb));

    xcb->out.type = output->type;
    if (xcb->out.type == XHTML_OUT_FILE)
    {
        xcb->out.u.fh = FS_Open(output->u.file, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (xcb->out.u.fh < FS_NO_ERROR)
        {
            free_ctrl_buffer(xcb);
            return NULL;
        }
    }
    else
    {
        xcb->out.u.buff.ptr = output->u.buff.ptr;
        xcb->out.u.buff.size = output->u.buff.size;
        xcb->out.u.buff.len = 0;
    }

    xcb->data_len = 0;

    t_buff = get_ctrl_buffer(strlen(XhtmlStart)+strlen(version)+1);

    sprintf(t_buff, XhtmlStart, version);
    xhtml_write(xcb, t_buff);

    free_ctrl_buffer(t_buff);

    return xcb;
}

S32 bpp_xhtml_style_begin(void *xhtml, const CHAR *type)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    CHAR t_buff[64];

    if (!type)
        type = DefaultStyleType;

    sprintf(t_buff, "<style type=%s>\r\n", type);

    return xhtml_write(xcb, t_buff) ? 1:0;
}

S32 bpp_xhtml_rule_begin(void *xhtml, const xhtml_rule_struct *rule)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    CHAR t_buff[128];
    U32 i;

    if (!xcb || !rule) return 0;

    switch (rule->type) {
    case STYLE_RULE_SYSTEM:
        sprintf(t_buff, "@%s {\r\n", rule->name);
        break;

    case STYLE_RULE_ID:
        sprintf(t_buff, "#%s {\r\n", rule->name);
        break;

    case STYLE_RULE_CLASS:
        if (rule->element)
            sprintf(t_buff, "%s.%s {\r\n", rule->element, rule->name);
        else
            sprintf(t_buff, ".%s {\r\n", rule->name);
        break;

    case STYLE_RULE_ELEMENT:
        sprintf(t_buff, "%s {\r\n", rule->name);
        break;

    default:
        return 0;
    }
    if (!xhtml_write(xcb, t_buff)) return 0;

    for (i = 0; i < rule->prop_count; i++)
    {
        sprintf(t_buff, "    %s: %s;\r\n", 
            rule->props[i].name, rule->props[i].value);
        
        if (!xhtml_write(xcb, t_buff)) return 0;
    }

    return 1;
}

S32 bpp_xhtml_rule_end(void *xhtml)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb) return 0;
    
    if (!xhtml_write(xcb, "}\r\n")) return 0;

    return 1;
}

S32 bpp_xhtml_style_rule(void *xhtml, const xhtml_rule_struct *rules, U32 count)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    U32 i;

    if (!xcb || !rules) return 0;

    for (i = 0; i < count; i++)
    {
        if (!bpp_xhtml_rule_begin(xhtml, &rules[i])) return 0;

        if (!bpp_xhtml_rule_end(xhtml)) return 0;
    }

    return 1;
}

S32 bpp_xhtml_style_end(void *xhtml)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb) return 0;

    return xhtml_write(xcb, "</style>\r\n") ? 1:0;
}

S32 bpp_xhtml_element_begin(void *xhtml, const CHAR *name, xhtml_attr_struct *attrs, U32 count)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb || !name) return 0;

    return xhtml_element_begin(xcb, name, attrs, count, 0);
}

S32 bpp_xhtml_element_data(void *xhtml, const CHAR *data)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb || !data) return 0;

    return xhtml_element_data(xcb, data);
}

S32 bpp_xhtml_element_end(void *xhtml, const CHAR *name)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb || !name) return 0;

    return xhtml_element_end(xcb, name);
}

S32 bpp_xhtml_inline_element(
        void *xhtml,
        const CHAR *name,
        xhtml_attr_struct *attrs,
        U32 count, CHAR *data)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb || !name) return 0;

    if (data)
    {
        if (!xhtml_element_begin(xcb, name, attrs, count, 0)) return 0;
        if (!xhtml_element_data(xcb, data)) return 0;
        return xhtml_element_end(xcb, name);
    }
    else
        return xhtml_element_begin(xcb, name, attrs, count, 1);
}

S32 bpp_xhtml_empty_element(void *xhtml, const CHAR *name, xhtml_attr_struct *attrs, U32 count)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;

    if (!xcb || !name) return 0;

    if (!xhtml_element_begin(xcb, name, attrs, count, 0)) return 0;

    return xhtml_element_end(xcb, name);
}


U32 bpp_xhtml_close(void *xhtml)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    U32 size;

    if (!xcb) return 0;

    xhtml_write(xcb, "\r\n</html>");

    xhtml_flush(xcb);

    if (xcb->out.type == XHTML_OUT_FILE)
    {
        FS_GetFileSize(xcb->out.u.fh, &size);
        FS_Close(xcb->out.u.fh);
    }

    free_ctrl_buffer(xcb);

    return size;
}

S32 bpp_xhtml_image_element(void *xhtml, xhtml_img_attr_struct *img)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    xhtml_attr_struct attrs[5];
    CHAR buff[64], *p_buff, *path = NULL;
    S32 i, len, count;
    
    if (!xcb || !img) return 0;

    p_buff = buff;

    for (i = 0, count = 0; i < ArrayCount(ImageAttrs); i++)
    {
        xhtml_attr_struct *attr = (xhtml_attr_struct *)&ImageAttrs[i];
        attrs[count].name = attr->name;
        if (strcmp(attr->name, XHTML_ATTR_WIDTH) == 0)
        {
            if (img->width)
                len = sprintf(p_buff, attr->value, img->width);
            else
            {
                continue;
            }
        }
        else if (strcmp(attr->name, XHTML_ATTR_HEIGHT) == 0)
        {
            if (img->height)
                len = sprintf(p_buff, attr->value, img->height);
            else
            {
                continue;
            }
        }
        else if (strcmp(attr->name, XHTML_ATTR_INLINE_SIZE) == 0)
        {
            len = sprintf(p_buff, attr->value, img->size);
        }
        else if (strcmp(attr->name, XHTML_ATTR_TYPE) == 0)
        {
            if (img->type)
                len = sprintf(p_buff, attr->value, img->type);
            else
                len = sprintf(p_buff, attr->value, "image/jpeg");
        }
        else if (strcmp(attr->name, XHTML_ATTR_SRC) == 0)
        {
            len = mmi_wcslen(img->src) * 3 + 1;
            path = get_ctrl_buffer(len);
            mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (CHAR *)img->src, path, len);
            attrs[count++].value = path;
            continue;
        }
        else
        {
            attrs[count++].value = attr->value;
            continue;
        }
        attrs[count++].value = p_buff;
        p_buff += len+1;
    }

    bpp_xhtml_inline_element(xhtml, XHTML_ELE_IMAGE, attrs, count, NULL);

    if (path)
        free_ctrl_buffer(path);

    return 1;
}

S32 bpp_xhtml_object_element(void *xhtml, xhtml_obj_attr_struct *obj)
{
    xhtml_ctrl_block *xcb = (xhtml_ctrl_block *)xhtml;
    xhtml_attr_struct attrs[3];
    CHAR buff[64], *p_buff, *path = NULL;
    S32 i, len;

    if (!xcb || !obj) return 0;

    p_buff = buff;

    for (i = 0; i < ArrayCount(ObjectAttrs); i++)
    {
        xhtml_attr_struct *attr = (xhtml_attr_struct *)&ObjectAttrs[i];
        attrs[i].name = attr->name;
        if (strcmp(attr->name, XHTML_ATTR_INLINE_SIZE) == 0)
        {
            len = sprintf(p_buff, attr->value, obj->size);
        }
        else if (strcmp(attr->name, XHTML_ATTR_TYPE) == 0)
        {
            len = sprintf(p_buff, attr->value, obj->type);
        }
        else if (strcmp(attr->name, XHTML_ATTR_SRC) == 0)
        {
            len = mmi_wcslen(obj->src) * 3 + 1;
            path = get_ctrl_buffer(len);
            mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (CHAR *)obj->src, path, len);
            attrs[i].value = path;
            continue;
        }
        else
        {
            attrs[i].value = attr->value;
            continue;
        }
        attrs[i].value = p_buff;
        p_buff += len+1;
    }

    bpp_xhtml_inline_element(xhtml, XHTML_ELE_INLINE, attrs, ArrayCount(attrs), NULL);

    if (path)
        free_ctrl_buffer(path);

    return 1;
}

static S32 xhtml_element_begin(
            xhtml_ctrl_block *xcb,
            const CHAR *name,
            xhtml_attr_struct *attrs,
            U32 count, U32 empty)
{
    CHAR t_buff[128];
    U32 i;

    sprintf(t_buff, "<%s", name);
    if (!xhtml_write(xcb, t_buff)) return 0;

    if (attrs)
    {
        for (i = 0; i < count; i++)
        {
            CHAR *value;
            U32 retval;

            sprintf(t_buff, " %s=\"", attrs[i].name);
            if (!xhtml_write(xcb, t_buff)) return 0;

            /* This attribute is for data exchange purpose, don't need escaping */
            if (strcmp(attrs[i].name, XHTML_ATTR_SRC) && 
                xhtml_escaping(NULL, 0, attrs[i].value, NULL))
            {
                CHAR * src = (CHAR *)attrs[i].value;
                value = get_ctrl_buffer(1024);
                while (!xhtml_escaping(value, 1024, src, &src))
                    xhtml_write(xcb, value);
            }
            else
            {
                value = (CHAR *)attrs[i].value;
            }

            retval = xhtml_write(xcb, value);
            if (value != attrs[i].value)
                free_ctrl_buffer(value);

            if (!retval) return 0;

            if (!xhtml_write(xcb, "\"")) return 0;
        }
    }
    if (empty)
        return xhtml_write(xcb, "/>\r\n") ? 1:0;
    else
        return xhtml_write(xcb, ">\r\n") ? 1:0;
}

static S32 xhtml_element_data(xhtml_ctrl_block *xcb, const CHAR *data)
{
    U32 len = strlen(data), retval;
    CHAR *t_buff;
    
    if (xhtml_escaping(NULL, 0, data, NULL))
    {
        CHAR *src = (CHAR *)data;
        t_buff = get_ctrl_buffer(1024);
        while (!xhtml_escaping(t_buff, 1024, src, &src))
            xhtml_write(xcb, t_buff);
    }
    else
    {
        t_buff = (CHAR *)data;
    }

    retval = xhtml_write(xcb, t_buff);

    if (t_buff != data)
        free_ctrl_buffer(t_buff);

    return retval ? 1:0;
}

static S32 xhtml_element_end(xhtml_ctrl_block *xcb, const CHAR *name)
{
    CHAR t_buff[64];

    sprintf(t_buff, "</%s>\r\n", name);

    return xhtml_write(xcb, t_buff) ? 1:0;
}

static U32 xhtml_write(xhtml_ctrl_block *xcb, const CHAR *data)
{
    U32 len = strlen(data);

    if (xcb->out.type == XHTML_OUT_FILE)
    {
        if (len + xcb->data_len > sizeof(xcb->buff))
        {
            U32 left = sizeof(xcb->buff) - xcb->data_len;
            memcpy(&xcb->buff[xcb->data_len], data, left);
            xcb->data_len += left;
            data += left;

            if (!xhtml_flush(xcb))
                return 0;

            return xhtml_write(xcb, data);
        }
        else
        {
            memcpy(&xcb->buff[xcb->data_len], data, len);
            xcb->data_len += len;
        }
    }
    else
    {
        xhtml_buff *buff = &xcb->out.u.buff;
        if (len + buff->len > buff->size)
            return 0;
        memcpy(buff->ptr, data, len);
        buff->len += len;
    }

    return len;
}

static S32 xhtml_escaping(CHAR *out, U32 size, const CHAR *in, CHAR **end)
{
    CHAR *s, *d, *p;
    U32 sl, dl;

    if (!out)
        return (strcspn(in, "&\"<>\t\r\n ") == strlen(in)) ? 0 : 1;

    /* We keep 1 byte NULL terminator in advance */
    size -= 1;

    for (s = (CHAR *)in, d = out; *s;)
    {
        if ((U8)*s < 0x80)
        {
            switch(*s) {
            case '&': 
                p = "&amp;";
                dl = strlen(p);
                break;

            case '\"': 
                p = "&quot;";
                dl = strlen(p);
                break;

            case '<': 
                p = "&lt;";
                dl = strlen(p);
                break;

            case '>': 
                p = "&gt;";
                dl = strlen(p);                
                break;

            case '\t': 
                p = "    ";
                dl = strlen(p);
                break;

            case '\r': 
                p = NULL;
                dl = 0;
                break;

            case '\n': 
                p = "<br/>";
                dl = strlen(p);
                break;

            case ' ': 
                p = "&nbsp;";
                dl = strlen(p);
                break;

            default:
                p = s;
                dl = 1;
                break;
            }
            sl = 1;
        }
        else if ((U8)*s >= 0xc0 && (U8)*s < 0xe0)
        {
            p = s;
            dl = sl = 2;
        }
        else if ((U8)*s >= 0xe0 && (U8)*s < 0xf0)
        {
            p = s;
            dl = sl = 3;
        }
        else if ((U8)*s >= 0xf0)
        {
            p = s;
            dl = sl = 4;
        }
        else
        {
            p = NULL;
            dl = 0;
            sl = 1;
        }
        if (dl)
        {
            if (size >= dl)
            {
                memcpy(d, p, dl);
                d += dl;
                size -= dl;
            }
            else
            {
                if (end) *end = s;
                *d = '\0';
                return 0;
            }
        }
        s += sl;
    }

    *d = '\0';

    return 1;
}

static MMI_BOOL xhtml_flush(xhtml_ctrl_block *xcb)
{
    FS_HANDLE fh = xcb->out.u.fh;
    U32 written;

    if (xcb->data_len > 0)
    {
        FS_Write(fh, xcb->buff, xcb->data_len, &written);
        if (written != xcb->data_len)
            return MMI_FALSE;

        xcb->data_len = 0;
    }

    return MMI_TRUE;
}

#endif /* __MMI_BPP_SUPPORT__ */

