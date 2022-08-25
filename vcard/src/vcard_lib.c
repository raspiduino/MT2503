#ifdef __VCARD_SUPPORT__

#include "kal_general_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "conversions.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "kal_public_api.h"

#include "vcard_lib.h"
#include "vcard_utility.h"
#include "vcard_parser.h"
#include "vcard_builder.h"

#ifdef __MULTI_VCARD_SUPPORT__
#include "mmi2udx_struct.h"
#endif

#define VCARD_MAX_INSTANCE  3

typedef struct
{
    void *handle;
    kal_bool busying;
} vcard_instance_struct;

static vcard_instance_struct g_vcard_instance[VCARD_MAX_INSTANCE];

kal_bool vcard_is_busying(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VCARD_MAX_INSTANCE; i++)
    {
        if (g_vcard_instance[i].handle == handle)
        {
            return g_vcard_instance[i].busying;
        }
    }

    return KAL_FALSE;
}

kal_bool vcard_add_instance(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VCARD_MAX_INSTANCE; i++)
    {
        if (!g_vcard_instance[i].busying)
        {
            g_vcard_instance[i].handle = handle;
            g_vcard_instance[i].busying = KAL_TRUE;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

kal_bool vcard_remove_instance(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VCARD_MAX_INSTANCE; i++)
    {
        if (g_vcard_instance[i].handle == handle)
        {
            g_vcard_instance[i].handle = NULL;
            g_vcard_instance[i].busying = KAL_FALSE;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

VP_HANDLE vcard_open_parser(kal_wchar *file_name, vcard_property_enum property, kal_int32 *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE source = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    source = FS_Open(file_name, FS_READ_ONLY);
    if (source > 0)
    {
        if (error_code)
        {
            *error_code = FS_NO_ERROR;
        }

        return vcard_malloc_parser(source, property);
    }

    if (error_code)
    {
        *error_code = source;
    }

    return NULL;
}

void vcard_set_parse_charset(VP_HANDLE vp, mmi_chset_enum default_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    parser->default_charset = VCARD_CHARSET_UTF8;
}

void vcard_set_parse_mode(VP_HANDLE vp, vcard_parse_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    parser->mode = mode;
}

kal_int32 vcard_parse(VP_HANDLE vp, vcard_object_struct **object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    if (object)
    {
        *object = parser->object;
    }

    if (parser->read_offset == -1)
    {
        return vcard_parse_object(parser, -1);
    }

    return vcard_parse_next_object(parser);
}

#ifdef __MULTI_VCARD_SUPPORT__

void vcard_multi_parse(VP_HANDLE vp, vcard_parser_callback_type vp_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser && vp_callback);

    parser->vp_callback = vp_callback;
    parser->user_data = user_data;

    if (vp_callback)
    {
        mmi_udx_parse_vcard_req_struct *parse_req = NULL;

        parse_req = (mmi_udx_parse_vcard_req_struct*) construct_local_para(sizeof(mmi_udx_parse_vcard_req_struct), TD_RESET);

        parse_req->vp = vp;
        parse_req->vp_callback = vp_callback;
        parse_req->user_data = user_data;

        vcard_send_msg_to_udx(stack_get_active_module_id(), MSG_ID_MMI_UDX_PARSE_VCARD_REQ, (void*) parse_req);
    }
}

void vcard_multi_parse_ex(VP_HANDLE vp, kal_int32 *app_buffer, kal_int32 app_buffer_size, vcard_parser_callback_ex_type vp_callback_ex, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser && vp_callback_ex);

    parser->app_buffer_size = app_buffer_size;
    parser->app_buffer = app_buffer;
    parser->object_count = 0;
    parser->vp_callback_ex = vp_callback_ex;
    parser->user_data = user_data;

    if (vp_callback_ex)
    {
        mmi_udx_read_vcard_req_struct *read_req = NULL;

        read_req = (mmi_udx_read_vcard_req_struct*) construct_local_para(sizeof(mmi_udx_read_vcard_req_struct), TD_RESET);

        read_req->vp = vp;
        read_req->vp_callback_ex = vp_callback_ex;
        read_req->user_data = user_data;

        vcard_send_msg_to_udx(stack_get_active_module_id(), MSG_ID_MMI_UDX_READ_VCARD_REQ, (void*) read_req);
    }
}

kal_int32 vcard_multi_preview(VP_HANDLE vp, vcard_object_struct **object, kal_int32 object_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    if (object)
    {
        *object = parser->object;
    }

    if (parser->read_offset == -1)
    {
        return vcard_parse_object(parser, -1);
    }

    return vcard_parse_object(parser, object_offset);
}

#endif /* __MULTI_VCARD_SUPPORT__ */

vcard_version_enum vcard_get_parse_version(VP_HANDLE vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    return parser->version;
}

kal_int32 vcard_get_parse_error(VP_HANDLE vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    return parser->error_code;
}

void vcard_cancel_parse(VP_HANDLE vp, vcard_parser_callback_type vp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser && vp_callback);

    parser->vp_callback = vp_callback;
    parser->cancel = KAL_TRUE;
}

void vcard_close_parser(VP_HANDLE vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(parser);

    FS_Close(parser->source);

    vcard_free_parser(parser);
}

VB_HANDLE vcard_open_builder(kal_wchar *file_name, vcard_open_mode_enum mode, kal_int32 *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE source = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode & VCARD_OPEN_MODE_APPEND)
    {
        source = FS_Open(file_name, FS_READ_WRITE);
        if (source > 0)
        {
            FS_Seek(source, 0, FS_FILE_END);
        }
        else
        {
            if (mode & VCARD_OPEN_MODE_HIDDEN)
            {
                source = FS_Open(file_name, FS_CREATE | FS_READ_WRITE | FS_ATTR_HIDDEN);
            }
            else
            {
                source = FS_Open(file_name, FS_CREATE | FS_READ_WRITE);
            }
        }
    }
    else
    {
        if (mode & VCARD_OPEN_MODE_HIDDEN)
        {
            source = FS_Open(file_name, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_ATTR_HIDDEN);
        }
        else
        {
            source = FS_Open(file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
        }
    }

    if (source > 0)
    {
        if (error_code)
        {
            *error_code = FS_NO_ERROR;
        }

        return vcard_malloc_builder(source);
    }

    if (error_code)
    {
        *error_code = source;
    }

    return NULL;
}

void vcard_set_build_version(VB_HANDLE vb, vcard_version_enum version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder);

    builder->version = version;
}

void vcard_set_build_mode(VB_HANDLE vb, vcard_build_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder);

    builder->mode = mode;
}

kal_int32 vcard_build(VB_HANDLE vb, vcard_object_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder && object);

    builder->object = object;

    if (builder->write_length == -1)
    {
        builder->write_length = 0;
        return vcard_build_object(builder);
    }

    return vcard_build_next_object(builder);
}

#ifdef __MULTI_VCARD_SUPPORT__

void vcard_multi_build(VB_HANDLE vb, vcard_object_struct *object, vcard_builder_callback_type vb_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder && object && vb_callback);

    builder->object = object;
    builder->vb_callback = vb_callback;
    builder->user_data = user_data;

    if (vb_callback)
    {
        mmi_udx_build_vcard_req_struct *build_req = NULL;

        build_req = (mmi_udx_build_vcard_req_struct*) construct_local_para(sizeof(mmi_udx_build_vcard_req_struct), TD_RESET);

        build_req->vb = vb;
        build_req->object = object;
        build_req->vb_callback = vb_callback;
        build_req->user_data = user_data;

        vcard_send_msg_to_udx(stack_get_active_module_id(), MSG_ID_MMI_UDX_BUILD_VCARD_REQ, (void*) build_req);
    }
}

#endif /* __MULTI_VCARD_SUPPORT__ */

kal_int32 vcard_get_build_error(VB_HANDLE vb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder);

    return builder->error_code;
}

void vcard_cancel_build(VB_HANDLE vb, vcard_builder_callback_type vb_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder && vb_callback);

    builder->vb_callback = vb_callback;
    builder->cancel = KAL_TRUE;
}

void vcard_close_builder(VB_HANDLE vb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(builder);

    FS_Close(builder->source);

    vcard_free_builder(builder);
}

#ifdef __MULTI_VCARD_SUPPORT__

void vcard_app_common_hdlr(void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = (ilm_struct*) ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_UDX_BUILD_VCARD_RSP:
            {
                mmi_udx_build_vcard_rsp_struct *build_rsp = (mmi_udx_build_vcard_rsp_struct*) ilm_ptr->local_para_ptr;
                if (!vcard_is_busying(build_rsp->handle))
                {
                    return;
                }
                ASSERT(build_rsp->vb_callback);
                build_rsp->vb_callback(build_rsp->error_code, build_rsp->user_data);
            }
            break;

        case MSG_ID_MMI_UDX_PARSE_VCARD_RSP:
            {
                mmi_udx_parse_vcard_rsp_struct *parse_rsp = (mmi_udx_parse_vcard_rsp_struct*) ilm_ptr->local_para_ptr;
                if (!vcard_is_busying(parse_rsp->handle))
                {
                    return;
                }
                ASSERT(parse_rsp->vp_callback);
                parse_rsp->vp_callback(parse_rsp->error_code, parse_rsp->percentage, parse_rsp->object, parse_rsp->user_data);
            }
            break;

        case MSG_ID_MMI_UDX_READ_VCARD_RSP:
            {
                mmi_udx_read_vcard_rsp_struct *read_rsp = (mmi_udx_read_vcard_rsp_struct*) ilm_ptr->local_para_ptr;
                vcard_parser_struct *parser = (vcard_parser_struct *)read_rsp->handle;
                if((parser->object_count < parser->app_buffer_size) && (parser->percentage < 100) && (parser->error_code == VCARD_NO_ERROR))
                {
                    mmi_udx_read_vcard_req_struct *read_req = NULL;
                    
                    read_req = (mmi_udx_read_vcard_req_struct*) construct_local_para(sizeof(mmi_udx_read_vcard_req_struct), TD_RESET);
                    read_req->vp = read_rsp->handle;
                    read_req->vp_callback_ex = read_rsp->vp_callback_ex;
                    read_req->user_data = read_rsp->user_data;
                
                    vcard_send_msg_to_udx(stack_get_active_module_id(), MSG_ID_MMI_UDX_READ_VCARD_REQ, (void*) read_req);
                }
                else
                {    
                    if (!vcard_is_busying(read_rsp->handle))
                    {
                        return;
                    }
                    ASSERT(read_rsp->vp_callback_ex);
                read_rsp->vp_callback_ex(read_rsp->error_code, read_rsp->object_count, read_rsp->object_offset_list, read_rsp->user_data);
                }
            }
            break;

        default:
            break;
    }
}

#endif /* __MULTI_VCARD_SUPPORT__ */

#endif /* __VCARD_SUPPORT__ */

