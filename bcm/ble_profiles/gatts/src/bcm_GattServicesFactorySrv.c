#ifdef __BT_GATTS_PROFILE__ 

//#include "MMI_features.h"

/****************************************************************************
* header files
****************************************************************************/
#include "Kal_debug.h"
//#include "MMIDataType.h"
//#include "CustDataRes.h"
//#include "MMI_conn_app_trc.h"
//#include "MMI_trc_Int.h"
#include "bcmadp.h"
#include "bcm_trc.h"
#include "bcm_GattServicesFactorySrv.h"
#include "bcm_GattProfileSrvDeclaration.h"
#include "fs_type.h"
#include "xml_def.h"
#ifdef __GATT_SRV_MEM_USE_ADM__
#include "kal_adm.h"
#endif

#define FACTORY_DEBUG(S) kal_prompt_trace(MOD_BT, S)    //kal_printf

#define SRV_GATT_F_TRACE_GROUP    MMI_CONN_TRC_G7_BT


//#if (SRV_STORE_IN_XML_FILE == KAL_TRUE)
#define GATTS_FACTORY_XML_ELEMENT_PROFILE       "ble_profile"
#define GATTS_FACTORY_XML_ELEMENT_ID            "id"
#define GATTS_FACTORY_XML_ELEMENT_SRV_FILE      "ble_service"
#define GATTS_FACTORY_XML_ELEMENT_NAME          "name"

#define MAX_SRV_XML_FILE_NAME_LEN           (40)
#define MAX_FILENAME_LEN                    (512)       /* This defines the maximun length customizable string can have. */

typedef struct
{
    ListEntry   node;
    U32 namelen;
    U16 filename[MAX_SRV_XML_FILE_NAME_LEN];
} gatts_factory_dep_file_struct;



#define SERVICES_DEP_FILE_PATH  (L"E:\\assets\\BleProfilesDef.xml")
#define SERVICES_XML_FOLDER     (L"E:\\assets\\services\\")

#define SERVICES_XML_FOLDER_TEST     (L"E:\\assets\\services\\AlertNotificationService.xml")
#define GATTS_FACTORY_XML_ELEMENT_SRV       "service"
#define GATTS_FACTORY_XML_ELEMENT_CHAR      "characteristic"
#define GATTS_FACTORY_XML_ELEMENT_DES       "descriptor"
#define GATTS_FACTORY_XML_ELEMENT_PROP      "property"
#define GATTS_FACTORY_XML_ELEMENT_PERM      "permission"
#define GATTS_FACTORY_XML_ELEMENT_UUID      "uuid"
#define GATTS_FACTORY_XML_ELEMENT_SRV_TYPE  "service_type"
#define GATTS_FACTORY_SRV_TYPE_PRIMARY      "Primary"
#define GATTS_FACTORY_SRV_TYPE_SENCOND      "Secondary"
#define GATTS_FACTORY_PROP_STR_BRD          "broadcast"
#define GATTS_FACTORY_PROP_STR_READ         "read"
#define GATTS_FACTORY_PROP_STR_WR_NR        "write_no_response"
#define GATTS_FACTORY_PROP_STR_WR           "write"
#define GATTS_FACTORY_PROP_STR_NOTIFY       "notify"
#define GATTS_FACTORY_PROP_STR_IND          "indicate"
#define GATTS_FACTORY_PROP_STR_SWR          "signed_write"
#define GATTS_FACTORY_PROP_STR_EXT_PROP     "extended_props"


#define GATTS_FACTORY_PERM_STR_READ         "read"
#define GATTS_FACTORY_PERM_STR_READ_EN      "read_encrypted"
#define GATTS_FACTORY_PERM_STR_READ_EN_M    "read_encrypted_mitm"
#define GATTS_FACTORY_PERM_STR_WR           "write"
#define GATTS_FACTORY_PERM_STR_WR_EN        "write_encrypted"
#define GATTS_FACTORY_PERM_STR_WR_EN_M      "write_encrypted_mitm"
#define GATTS_FACTORY_PERM_STR_WR_SIGN      "write_signed"
#define GATTS_FACTORY_PERM_STR_WR_SIGN_M    "write_signed_mitm"

#define GATTS_FACTORY_STR_YES               "yes"
#define GATTS_FACTORY_STR_NO                "no"
//#endif // (SRV_STORE_IN_XML_FILE == KAL_TRUE)


#define UUID_STR_LEN_128    (32)
#define UUID_STR_LEN_16     (8)
#define UUID_STR_LEN_2      (4)

#ifdef __GATT_SRV_MEM_USE_ADM__
#define GATTSRV_ADM_BUFFER_SIZE     (10*1024) //10KB

#define gattsrv_malloc(size)       gattsrv_adm_malloc(size)
#define gattsrv_free(p)            do{if(p){gattsrv_adm_free(p); p = NULL;}}while(0)
#else
#define gattsrv_malloc(size)       get_ctrl_buffer(size)
#define gattsrv_free(p)            do{if(p){free_ctrl_buffer(p); p = NULL;}}while(0)
#endif


/****************************************************************************
* data define
****************************************************************************/
srvs_factory_ctx_struct factory_ctx;
srvs_factory_ctx_struct* pFactoryCtx = &factory_ctx;
#ifdef MMI_SRV_CHECK_SERVICE_UUID
gatt_profile_decl_tbl    g_profile_decl_tbl_new[MAX_PROFILE_CNT];
#endif

#ifdef __GATT_SRV_MEM_USE_ADM__
static U8 gattsrv_adm_buffer_pool[GATTSRV_ADM_BUFFER_SIZE];
static KAL_ADM_ID gattsrv_adm_buffer_pool_id = NULL;
#endif

/****************************************************************************
* function define
****************************************************************************/
void srv_gatts_profile_factory_clear_services(void* reg_ctx, gatts_srvs_lst_struct* services);

#ifdef __GATT_SRV_MEM_USE_ADM__
static void *gattsrv_adm_malloc(U32 size)
{
    void *ptr = NULL;

    if (gattsrv_adm_buffer_pool_id)
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_ALLOC_SIZE, size);
        ptr = kal_adm_alloc(gattsrv_adm_buffer_pool_id, size);
    }
    else
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_ALLOC_ERR);
    }

    if (ptr)
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_ALLOC_SUCCESS, ptr, size);
    }

    return ptr;
}

static void gattsrv_adm_free(void *ptr)
{
    if (!ptr)
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_FREE_ERR1);
        return;
    }
    
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_FREE, ptr);

    if (gattsrv_adm_buffer_pool_id)
    {
        kal_adm_free(gattsrv_adm_buffer_pool_id, ptr);
    }
    else
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_FREE_ERR2);
    }
}
#endif

static factory_user_struct* srv_factory_new_user()
{
    factory_user_struct* user = NULL;
    user = (factory_user_struct*)gattsrv_malloc(sizeof(factory_user_struct));
    if (user != NULL)
    {
        kal_mem_set((U8*)user, 0x0, sizeof(factory_user_struct));
        mmi_InsertTailList(&pFactoryCtx->userList, &user->node);
    }

    return user;
}

static void srv_factory_free_user(factory_user_struct* user)
{
    if (user != NULL)
    {
        mmi_RemoveEntryList(&user->node);
        gattsrv_free(user);
        user = NULL;
    }
}

static factory_user_struct* srv_factory_find_user_by_apid(bt_uuid_struct* apid)
{
    factory_user_struct* found_user = NULL;
    factory_user_struct* user = NULL;

    if (apid != NULL)
    {
        user = (factory_user_struct*)mmi_GetHeadList(&pFactoryCtx->userList);
        while ((ListEntry*)user != &pFactoryCtx->userList)
        {
            if ((user->apid != NULL) && (kal_mem_cmp(user->apid, apid, sizeof(bt_uuid_struct)) == 0))
            {
                found_user = user;
                break;
            }
            user = (factory_user_struct*)mmi_GetNextNode(&user->node);
        }
    }

    return found_user;
}

static factory_user_struct* srv_factory_find_user_by_appctx(void* ctx)
{
    factory_user_struct* found_user = NULL;
    factory_user_struct* user = NULL;

    if (ctx != NULL)
    {
        user = (factory_user_struct*)mmi_GetHeadList(&pFactoryCtx->userList);
        while ((ListEntry*)user != &pFactoryCtx->userList)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]find_user_by_appctx ctx(%d) user_ctx(%d).", (U32)ctx, (U32)user->reg_ctx);
            //kal_prompt_trace(MOD_BT, "[gatts_f]head:(%d) user(%d)", (U32)&pFactoryCtx->userList, (U32)user);

            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_FIND_USER_BY_CTX, (U32)ctx, (U32)user->reg_ctx);
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_LIST_AND_USER, (U32)&pFactoryCtx->userList, (U32)user);
            if (user->reg_ctx == ctx)
            {
                found_user = user;
                break;
            }
            user = (factory_user_struct*)mmi_GetNextNode(&user->node);
        }
    }

    return found_user;
}


static factory_user_struct* srv_factory_find_user_by_status(gatts_factory_state_enum status)
{
    factory_user_struct* found_user = NULL;
    factory_user_struct* user = NULL;

    user = (factory_user_struct*)mmi_GetHeadList(&pFactoryCtx->userList);
    while ((ListEntry*)user != &pFactoryCtx->userList)
    {
        if (user->status == FACTORY_STS_PROCESSING)
        {
            found_user = user;
            break;
        }
        user = (factory_user_struct*)mmi_GetNextNode(&user->node);
    }

    return found_user;
}


//callback for factory to user after calling srv_gatts_profile_factory_register
static void srv_factory_user_regeistered(void* reg_ctx, OS_STATUS status, bt_uuid_struct* app_uuid)
{
    factory_user_struct* user = NULL;

    user = srv_factory_find_user_by_apid(app_uuid);

    if (user != NULL)
    {
        if (user->user_reg_cb != NULL)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]reg_cb ctx(%d)", (U32)reg_ctx);
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_CB_CTX, (U32)reg_ctx);
            user->reg_ctx = reg_ctx;
            user->user_reg_cb(reg_ctx, status, app_uuid);
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_user_regeistered:user_reg_cb is NULL.");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_CB_USER_CB_NULL);
        }
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_user_regeistered:uuid not exist.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_CB_APP_UUID_NOT_EXIST);
    }
}

static void srv_factory_user_deregeistered(void* reg_ctx, OS_STATUS status)
{
    factory_user_struct*    user = NULL;

    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEREG_CB_ENTRY);

    user = srv_factory_find_user_by_appctx(reg_ctx);
    srv_gatts_profile_factory_clear_services(reg_ctx, NULL);
    if (user != NULL)
    {
        if (user->user_dereg_cb != NULL)
        {
            user->user_dereg_cb(reg_ctx, status);
        }
    }
    srv_factory_free_user(user);

    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEREG_CB_LEAVE);
}

static void srv_factory_dep_xml_start_element_hdlr(void *data, const char *el,const char **attr, int err)
{
    U32 num = 1;
    U32 namelen = 0;
    U16 filename[MAX_SRV_XML_FILE_NAME_LEN] = {0};
    gatts_factory_dep_file_struct* file = NULL;
    factory_user_struct* user = NULL;
    
    if (!err)
    {
        if (pFactoryCtx->parser.user != NULL)
        {
            if (user->fileslst == NULL)
            {
                user = pFactoryCtx->parser.user;
                user->fileslst = (ListEntry*)gattsrv_malloc(sizeof(ListEntry));
                mmi_InitializeListHead(user->fileslst);
            }
            
            if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PROFILE, el))
            {
                if (attr[0] && !stricmp(GATTS_FACTORY_XML_ELEMENT_ID, attr[0]))
                {
                    sscanf(attr[1], "%lu", &num);
                           
                    if (num == pFactoryCtx->parser.user->profile_id )
                    {
                        pFactoryCtx->parser.state |= FACTORY_STATE_XML_PARSE_DEP_FILE;
                    }
                }

            }
            else if ((pFactoryCtx->parser.state & FACTORY_STATE_XML_PARSE_DEP_FILE) && !stricmp(GATTS_FACTORY_XML_ELEMENT_SRV_FILE, el))
            {
                if (attr[0] && !stricmp(GATTS_FACTORY_XML_ELEMENT_NAME, attr[0]))
                {

                    mmi_chset_utf8_to_ucs2_string((U8*)filename, MAX_SRV_XML_FILE_NAME_LEN*2, (U8*)attr[1]);
                    namelen = mmi_wcslen(filename);
                    // TODO: dep file list should be freed after used.
                    file = (gatts_factory_dep_file_struct*)gattsrv_malloc(sizeof(gatts_factory_dep_file_struct));
                    if (file != NULL)
                    {
                        file->namelen = namelen;
                        kal_mem_cpy((U8*)file->filename, (U8*)filename, MAX_SRV_XML_FILE_NAME_LEN*2);

                        // TODO: user->filelist should be init before.
                        mmi_InsertTailList(pFactoryCtx->parser.user->fileslst, &file->node);
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_xml_start_element_hdlr alloc file info failed.");
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_XML_S_EL_HDR_ALLOC_FAILED);
                        
                    }
                }
            }
            else
            {
                kal_prompt_trace(MOD_MMI, "[gatts_f]srv_factory_xml_start_element_hdlr el:(%s).", el);
            }
        }
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_xml_start_element_hdlr err:(%d).", err);
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_XML_S_EL_HDR_ERR, err);
    }
}

static void srv_factory_dep_xml_end_element_hdlr(void *data, const char *el, int err)
{
    U8 filename[MAX_SRV_XML_FILE_NAME_LEN] = {0};
    gatts_factory_dep_file_struct* file = NULL;
    
    if (!err)
    {
        if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PROFILE, el))
        {
            if (FACTORY_STATE_XML_PARSE_DEP_FILE & pFactoryCtx->parser.state)
            {
                pFactoryCtx->parser.state &= ~FACTORY_STATE_XML_PARSE_DEP_FILE;

                // TODO: test code to be removed
                // Dump code start
                //kal_prompt_trace(MOD_BT, "[gatts_f]DUMP dep service file profile ID:(%d).", pFactoryCtx->parser.user->profile_id);
                MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DUMP_DEP_SRV_FILE_PROFILE_ID, pFactoryCtx->parser.user->profile_id);
                file = (gatts_factory_dep_file_struct*)mmi_GetHeadList(pFactoryCtx->parser.user->fileslst);
                while ((ListEntry*)file != pFactoryCtx->parser.user->fileslst)
                {
                    mmi_chset_ucs2_to_utf8_string((U8*)filename, MAX_SRV_XML_FILE_NAME_LEN, (U8*)file->filename);
                    kal_prompt_trace(MOD_BT, "[gatts_f]DUMP dep service file:(%s).", (U8*)filename);

                    file = (gatts_factory_dep_file_struct*)mmi_GetNextNode(&file->node);
                }
                // Dump code end
            }
        }
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_xml_end_element_hdlr err:(%d).", err);
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_XML_E_EL_HDR_ERR, err);
    }    
}

static void srv_factory_dep_xml_data_hdlr(void *data, const char *el, const char *value, int len, int err)
{
}





static OS_STATUS srv_factory_parser_dep_files_xml(U16* filename)
{
    OS_STATUS ret = OS_STATUS_SUCCESS;
    XML_RESULT_ENUM result = XML_RESULT_OK;
    XML_PARSER_STRUCT* xml_parser = NULL;

    xml_parser = (XML_PARSER_STRUCT*)gattsrv_malloc(sizeof(XML_PARSER_STRUCT));
    result = xml_new_parser(xml_parser);
    if (result != XML_RESULT_OK)
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]parse dep files failed. new parser failed.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_PARSER_FAILED);
        ret= OS_STATUS_FAILED;
    }
    else
    {
        xml_register_element_handler(xml_parser, srv_factory_dep_xml_start_element_hdlr, srv_factory_dep_xml_end_element_hdlr);
        xml_register_data_handler(xml_parser, srv_factory_dep_xml_data_hdlr);
        result = xml_parse(xml_parser, filename);
        if (result != XML_RESULT_OK)
        {
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_PARSER_FAILED);
            ret= OS_STATUS_FAILED;
        }
    }

    xml_close_parser(xml_parser);
    gattsrv_free(xml_parser);
    xml_parser = NULL;

    return ret;
}




static U32 srv_factory_squeeze(S8* str, S8 ch)
{
    U32 i,j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ch)
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    return j;
}

U8 chr_to_u8(char chr)
{
	U8 ret = 0;
	if(chr >= '0' && chr <= '9')
	{
		ret = chr - '0';
	}
	else if(chr >= 'a' && chr <= 'f')
	{
		ret = chr - 'a' + 10;
	}
	else if(chr >= 'A' && chr <= 'F')
	{
		ret = chr - 'A' + 10;
	}
	return ret;
}

static void srv_facotry_str_to_uuid(const U8* str, BT_UUID* uuid)
{
    U32 len = 0;
    U8* uuid_str = NULL;
    U32 uuid_len = 0;
    int i,j;
	U8 H4 = 0;
	U8 L4 = 0;

    len = strlen(str); //mmi_chset_utf8_strlen(str);
    
    // TODO: str should be free after used.
    uuid_str = (U8*)gattsrv_malloc(len + 1);
    if (uuid_str != NULL)
    {
        kal_mem_set(uuid_str, 0x0, len+1);
        kal_mem_cpy(uuid_str, str, len);
        uuid_str[len] = '\0';                
        
        uuid_len = srv_factory_squeeze(uuid_str, '-');
        
        switch (uuid_len)
        {
        case UUID_STR_LEN_128:
        case UUID_STR_LEN_16:
        case UUID_STR_LEN_2:
            {
                for (i = 0, j = uuid_len - 2; j >= 0; j -= 2)
                {
                	H4 = chr_to_u8(uuid_str[j]);
					L4 = chr_to_u8(uuid_str[j+1]);
                	uuid->uuid[i] = H4*16 + L4;
                    i++;
                }
                uuid->len = i;
            }
            break;
        default:
            kal_prompt_trace(MOD_BT, "[gatts_f]Invalid UUID:(%s)", str);
            break;
        }

        gattsrv_free(uuid_str);
        uuid_str = NULL;
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_facotry_str_to_uuid: no memory.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_STR_TO_UUID_NO_MEM);
    }
}


static GATT_PERMISSION srv_factory_parse_permission(const char *el, const char *value)
{
    GATT_PERMISSION permission = 0;

    if ((el != NULL) && (value != NULL))
    {
        if (!stricmp(GATTS_FACTORY_STR_YES, value))
        {
            if (!stricmp(GATTS_FACTORY_PERM_STR_READ, el))
            {
                permission = GATT_PERM_READ;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_READ_EN, el))
            {
                permission = GATT_PERM_READ_ENCRYPTED;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_READ_EN_M, el))
            {
                permission = GATT_PERM_READ_ENC_MITM;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_WR, el))
            {
                permission = GATT_PERM_WRITE;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_WR_EN, el))
            {
                permission = GATT_PERM_WRITE_ENCRYPTED;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_WR_EN_M, el))
            {
                permission = GATT_PERM_WRITE_ENC_MITM;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_WR_SIGN, el))
            {
                permission = GATT_PERM_WRITE_SIGNED;
            }
            else if (!stricmp(GATTS_FACTORY_PERM_STR_WR_SIGN_M, el))
            {
                permission = GATT_PERM_WRITE_SIGNED_MITM;
            }
            else
            {
                kal_prompt_trace(MOD_BT, "[gatts_f]Unknow permsssion el:(%s).", el);
            }        
        }

    }

    return permission;
}

static GATT_CHAR_PROPERTIES srv_factory_parse_property(const char *el, const char *value)
{
    GATT_CHAR_PROPERTIES prop = 0;

    if ((el != NULL) && (value != NULL))
    {
        if (!stricmp(GATTS_FACTORY_STR_YES, value))
        {
            if (!stricmp(GATTS_FACTORY_PROP_STR_BRD, el))
            {
                prop = GATT_CHAR_PROP_BROADCAST;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_READ, el))
            {
                prop = GATT_CHAR_PROP_READ;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_WR_NR, el))
            {
                prop = GATT_CHAR_PROP_WRITE_WO_RESPONSE;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_WR, el))
            {
                prop = GATT_CHAR_PROP_WRITE;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_NOTIFY, el))
            {
                prop = GATT_CHAR_PROP_NOTIFY;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_IND, el))
            {
                prop = GATT_CHAR_PROP_INDICATE;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_SWR, el))
            {
                prop = GATT_CHAR_PROP_SIGNED_WRITE;
            }
            else if (!stricmp(GATTS_FACTORY_PROP_STR_EXT_PROP, el))
            {
                prop = GATT_EXT_PROP;
            }
            else
            {
                kal_prompt_trace(MOD_BT, "[gatts_f]Unknow prop el:(%s).", el);
            }
        }
    }

    return prop;
}




static void srv_factory_srvs_xml_start_element_hdlr(void *data, const char *el,const char **attr, int err)
{
    factory_user_struct*    user = NULL;
    //gatts_service_struct*   srvnode = NULL;
    //gatts_chr_struct*       chnode = NULL;
    //gatts_des_struct*       desnode = NULL;
    gatts_service_decl_struct* declnode = NULL;
    gatts_service_decl_struct* srv_declnode = NULL;
    
    if (!err)
    {
        if (pFactoryCtx->parser.user != NULL)
        {
            user = pFactoryCtx->parser.user;
            if (!stricmp(GATTS_FACTORY_XML_ELEMENT_SRV, el))
            {
                pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_SERVICE;

                if (user->services->bInitialized != TRUE)
                {
                    mmi_InitializeListHead(&user->services->srvlist);
                    user->services->bInitialized = TRUE;
                }

                declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));

                if (declnode != NULL)
                {
                    kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                    mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);

                    declnode->handlenum++;
                    declnode->type = TYPE_SERVICE;

                    if (attr[0] && !stricmp(GATTS_FACTORY_XML_ELEMENT_UUID, attr[0]))
                    {
                        srv_facotry_str_to_uuid((U8*)attr[1], &declnode->uuid.uuid);
                    }

                    if (attr[2] && !stricmp(GATTS_FACTORY_XML_ELEMENT_SRV_TYPE, attr[2]))
                    {
                        if (attr[3] && !stricmp(GATTS_FACTORY_SRV_TYPE_PRIMARY, attr[3]))
                        {
                            declnode->isprimary= TRUE;
                        }
                        else if (attr[3] && !stricmp(GATTS_FACTORY_SRV_TYPE_SENCOND, attr[3]))
                        {
                            declnode->isprimary = FALSE;
                        }
                        else
                        {
                            //kal_prompt_trace(MOD_BT, "[gatts_f]Service type is invalid.");
                            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_SRV_TYPE_INVALID);
                        }
                    }
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]New srv node err no memory.");
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_SRV_NODE_NO_MEM);
                }   
            }
            else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_CHAR, el))
            {
                pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_CHAR;

                if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_SERVICE)
                {
                    srv_declnode = (gatts_service_decl_struct*)mmi_GetHeadList(&user->services->srvlist);
                    declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));

                    if (declnode != NULL)
                    {
                        kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                        mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);
                        srv_declnode->handlenum += 2;
                        declnode->type = TYPE_CHARACTERISTIC;
                        if (attr[0] && !stricmp(GATTS_FACTORY_XML_ELEMENT_UUID, attr[0]))
                        {
                            srv_facotry_str_to_uuid((U8*)attr[1], &declnode->uuid.uuid);
                        }
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_BT, "[gatts_f]New Char node err no memory.");
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_CHAR_NODE_NO_MEM);
                    }
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]Parse characteristic in wrong state.");
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSE_CHAR_IN_ERR_STATE);
                }                    
            }
            else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_DES, el))
            {
                pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_DES;

                if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_CHAR)
                {
                    srv_declnode = (gatts_service_decl_struct*)mmi_GetHeadList(&user->services->srvlist);

                    declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));

                    if (declnode != NULL)
                    {
                        kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                        mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);
                        srv_declnode->handlenum++;
                        declnode->type = TYPE_DESCRIPTOR;
                        if (attr[0] && !stricmp(GATTS_FACTORY_XML_ELEMENT_UUID, attr[0]))
                        {
                            srv_facotry_str_to_uuid((U8*)attr[1], &declnode->uuid.uuid);
                        }
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_BT, "[gatts_f]New Des node err no memory.");
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_DES_NODE_NO_MEM);
                    }                   
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]Parse descriptor in wrong state.");
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSE_DES_IN_WRONG_STATE);
                }
            }
            else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PROP, el))
            {
                pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_PROP;
            }
            else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PERM, el))
            {
                pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_PERMISSION;
            }
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_srvs_xml_start_element_hdlr err:user is null.");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_SRVS_XML_S_EL_HDLR_USER_NULL);
        }
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_srvs_xml_start_element_hdlr err:(%d).", err);
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_SRVS_XML_S_EL_HDLR_ERR, err);
    }
}

static void srv_factory_srvs_xml_end_element_hdlr(void *data, const char *el, int err)
{
    if (!err)
    {
        if (!stricmp(GATTS_FACTORY_XML_ELEMENT_SRV, el))
        {
            pFactoryCtx->parser.state &= ~FACTORY_STATE_PARSE_SERVICE;
        }
        else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_CHAR, el))
        {
            pFactoryCtx->parser.state &= ~FACTORY_STATE_PARSE_CHAR;
        }
        else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PROP, el))
        {
            pFactoryCtx->parser.state &= ~FACTORY_STATE_PARSE_PROP;
        }
        else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_PERM, el))
        {
            pFactoryCtx->parser.state &= ~FACTORY_STATE_PARSE_PERMISSION;
        }
        else if (!stricmp(GATTS_FACTORY_XML_ELEMENT_DES, el))
        {
            pFactoryCtx->parser.state &= ~FACTORY_STATE_PARSE_DES;
        }
        
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_srvs_xml_end_element_hdlr err:(%d).", err);
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_SRVS_XML_E_EL_HDLR_ERR, err);
    }    
}

static void srv_factory_srvs_xml_data_hdlr(void *data, const char *el, const char *value, int len, int err)
{
    gatts_service_decl_struct*  declnode = NULL;
    gatts_service_decl_struct*  srv_declnode = NULL;
    
    declnode = (gatts_service_decl_struct*)GetTailList(&pFactoryCtx->parser.user->services->srvlist);
    if (declnode != NULL)
    {
        if (!err)
        {
            if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_PROP)
            {
                if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_DES)
                {
                   // No property in descriptor
                   MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ERR_NO_PROP_IN_DES);
                }
                else if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_CHAR)
                {
                    declnode->prop|= srv_factory_parse_property(el, value);
                }
                else
                {
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_PROP_IN_WRONG_STATE);
                }
            }
            else if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_PERMISSION)
            {
                if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_DES)
                {
                     declnode->permission |= srv_factory_parse_permission(el, value);
                }
                else if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_CHAR)
                {
                    declnode->permission |= srv_factory_parse_permission(el, value);
                }
                else
                {
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_PERM_IN_WRONG_STATE);
                }        
            }
            else
            {
                MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_DATA_IN_WRONG_STATE);
            }
        }
        else
        {
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_SRVS_XML_END_ELEM_HDLR_ERR, err);
        } 
    }
}

static OS_STATUS srv_factory_parser_service(U16* filename)
{
    OS_STATUS ret = OS_STATUS_SUCCESS;
    XML_RESULT_ENUM result = XML_RESULT_OK;
    XML_PARSER_STRUCT* xml_parser = NULL;

    xml_parser = (XML_PARSER_STRUCT*)gattsrv_malloc(sizeof(XML_PARSER_STRUCT));
    result = xml_new_parser(xml_parser);
    if (result != XML_RESULT_OK)
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_SRV_FAILED_NEW_PARESR_FAILED);
        ret= OS_STATUS_FAILED;
    }
    else
    {
        xml_register_element_handler(xml_parser, srv_factory_srvs_xml_start_element_hdlr, srv_factory_srvs_xml_end_element_hdlr);
        xml_register_data_handler(xml_parser, srv_factory_srvs_xml_data_hdlr);
        result = xml_parse(xml_parser, filename);
        if (result != XML_RESULT_OK)
        {
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_SRV_FAILED_XML_PARESR_FAILED);
            ret= OS_STATUS_FAILED;
        }
    }

    xml_close_parser(xml_parser);
    gattsrv_free(xml_parser);
    xml_parser = NULL;

    return ret;

}

// Services store as coding binary.
#ifdef MMI_SRV_CHECK_SERVICE_UUID
static OS_STATUS srv_factory_get_services_by_profile_id(S32 id)
#else
static OS_STATUS srv_factory_get_services_by_profile_id(gatt_profile_id_enum id)
#endif
{
    OS_STATUS status = OS_STATUS_SUCCESS;
    gatts_profile_srv_decl_struct* srv_decl = NULL;
    gatts_profile_srv_decl_struct* parse_decl = NULL;
    factory_user_struct*    user = NULL;
    gatts_service_decl_struct* declnode = NULL;
    gatts_service_decl_struct* srv_declnode = NULL;
    gatts_service_decl_struct* lastSrvNode = NULL;
    U32 decl_num = 0;
    U32 tbl_size = 0;
    U32 index = 0;

    U32 size1 = 0;
    U32 size2 = 0;

#ifdef MMI_SRV_CHECK_SERVICE_UUID
    tbl_size = MAX_PROFILE_CNT;
#else
    size1 = sizeof(g_profile_decl_tbl);
    size2 = sizeof(g_profile_decl_tbl[0]);

    tbl_size = sizeof(g_profile_decl_tbl)/sizeof(g_profile_decl_tbl[0]);
#endif

    //pFactoryCtx->parser.user = (factory_user_struct*)gattsrv_malloc(sizeof(factory_user_struct));

    //pFactoryCtx->parser.user->services = (gatts_srvs_lst_struct*)gattsrv_malloc(sizeof(gatts_srvs_lst_struct));

    if (pFactoryCtx->parser.user != NULL)
    {
        user = pFactoryCtx->parser.user;
        
        for (index = 0; index < tbl_size; index++)
        {
#ifdef MMI_SRV_CHECK_SERVICE_UUID
            if (g_profile_decl_tbl_new[index].id == id)
            {
                srv_decl = g_profile_decl_tbl_new[index].profile_decl;
                decl_num = g_profile_decl_tbl_new[index].decl_num;
            }
#else
            if (g_profile_decl_tbl[index].id == id)
            {
                srv_decl = g_profile_decl_tbl[index].profile_decl;
                decl_num = g_profile_decl_tbl[index].decl_num;
            }
#endif
        }

        // Parse flle one by one and file Service structure.
        if (srv_decl != NULL)
        {
            for (index = 0; index < decl_num; index++)
            {
                parse_decl = &srv_decl[index];

                declnode = NULL;
                srv_declnode = NULL;

                if (parse_decl->type == TYPE_SERVICE)
                {
                    pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_SERVICE;
                    
                     if (user->services->bInitialized != TRUE)
                     {
                         mmi_InitializeListHead(&user->services->srvlist);
                         user->services->bInitialized = TRUE;
                     }
                    
                     declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));         
                     if (declnode != NULL)
                     {
                         kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                         mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);
                    
                         declnode->handlenum++;
                         declnode->type = TYPE_SERVICE;
                    
                         if (parse_decl->uuid != NULL)
                         {
                             srv_facotry_str_to_uuid(parse_decl->uuid, &declnode->uuid.uuid);
                         }

                         declnode->isprimary = parse_decl->isprimary;
                         lastSrvNode = declnode;
                     }
                     else
                     {
                         //kal_prompt_trace(MOD_BT, "[gatts_f]New srv node err no memory.");
                         MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_SRV_NODE_NO_MEM);
                     }
                }
                else if (parse_decl->type == TYPE_CHARACTERISTIC)
                {
                    pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_CHAR;

                    if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_SERVICE)
                    {
                        declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));

                        if (declnode != NULL)
                        {
                            kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                            mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);
                            lastSrvNode->handlenum += 2;
                            declnode->type = TYPE_CHARACTERISTIC;
                            if (parse_decl->uuid != NULL)
                            {
                                srv_facotry_str_to_uuid(parse_decl->uuid, &declnode->uuid.uuid);
                            }
                            declnode->prop = parse_decl->prop;
                            declnode->permission = parse_decl->permission;
                        }
                        else
                        {
                            //kal_prompt_trace(MOD_BT, "[gatts_f]New Char node err no memory.");
                            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_CHAR_NODE_NO_MEM);
                        }
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_BT, "[gatts_f]Parse characteristic in wrong state.");
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSE_CHAR_IN_ERR_STATE);
                    }                    
                }
                else if (parse_decl->type == TYPE_DESCRIPTOR)
                {
                    pFactoryCtx->parser.state |= FACTORY_STATE_PARSE_DES;

                    if (pFactoryCtx->parser.state & FACTORY_STATE_PARSE_CHAR)
                    {
                        declnode = (gatts_service_decl_struct*)gattsrv_malloc(sizeof(gatts_service_decl_struct));

                        if (declnode != NULL)
                        {
                            kal_mem_set(declnode, 0x0, sizeof(gatts_service_decl_struct));
                            mmi_InsertTailList(&user->services->srvlist, &declnode->declnode);
                            lastSrvNode->handlenum++;
                            declnode->type = TYPE_DESCRIPTOR;
                            if (parse_decl->uuid != NULL)
                            {
                                srv_facotry_str_to_uuid(parse_decl->uuid, &declnode->uuid.uuid);
                            }
                            declnode->prop = parse_decl->prop;
                            declnode->permission = parse_decl->permission;
                        }
                        else
                        {
                            //kal_prompt_trace(MOD_BT, "[gatts_f]New Des node err no memory.");
                            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_NEW_DES_NODE_NO_MEM);
                        }                   
                    }
                    else
                    {
                        //kal_prompt_trace(MOD_BT, "[gatts_f]Parse descriptor in wrong state.");
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSE_DES_IN_WRONG_STATE);
                    }
                }
                else if (parse_decl->type == TYPE_INCLUDE_SRV)
                {
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]Unknow decl type:(%d).", parse_decl->type);
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_UNKNOW_DECL_TYPE, parse_decl->type);
                }
                
            }

            pFactoryCtx->parser.state = 0;
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]Can't find profile ID:(%d) srvs.", id);
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_CAN_NOT_FIND_ID_SRV, id);
        }

    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]parse services failed user no exist");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSE_FAILED_USER_NO_EXIST);
        status = OS_STATUS_FAILED;
    }

    return status;    
}

// Services store as XML files.
#ifdef MMI_SRV_CHECK_SERVICE_UUID
static OS_STATUS srv_factory_get_services_files_by_profile_id(S32 id)
#else
static OS_STATUS srv_factory_get_services_files_by_profile_id(gatt_profile_id_enum id)
#endif
{
    OS_STATUS status = OS_STATUS_SUCCESS;
    ListEntry*  filelist = NULL;
    gatts_factory_dep_file_struct* filenode = NULL;
    U16 servicefile[MAX_FILENAME_LEN];

    if (pFactoryCtx->parser.user != NULL)
    {
    
        status = srv_factory_parser_dep_files_xml(SERVICES_DEP_FILE_PATH);

        filelist = pFactoryCtx->parser.user->fileslst;

        // Parse flle one by one and file Service structure.
        if (status == OS_STATUS_SUCCESS)
        {
            filenode = (gatts_factory_dep_file_struct*)mmi_GetHeadList(filelist);
            
            while ((ListEntry*)filenode != filelist)
            {
                kal_mem_set(servicefile, 0x0, MAX_SRV_XML_FILE_NAME_LEN*sizeof(U16));
                mmi_wcsncpy(servicefile, SERVICES_XML_FOLDER, MAX_FILENAME_LEN);
                mmi_wcsncat(servicefile, filenode->filename, (MAX_FILENAME_LEN - mmi_wcslen(SERVICES_XML_FOLDER)));
                
                status = srv_factory_parser_service(servicefile);
                
                filenode = (gatts_factory_dep_file_struct*)mmi_GetNextNode(&filenode->node);
            }
        }
        else
        {
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_DEP_FILES_FAILED);
        }

        // free file list
        if (filelist != NULL)
        {
            while (!mmi_IsListEmpty(filelist))
            {
                filenode = (gatts_factory_dep_file_struct*)mmi_RemoveHeadList(filelist);
                gattsrv_free(filenode);
                filenode = NULL;
            }
            gattsrv_free(filelist);
            pFactoryCtx->parser.user->fileslst = NULL;
        }
    }
    else
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_PARSER_DEP_FILES_FAILED_USER_NULL);
        status = OS_STATUS_FAILED;
    }

    return status;    
}

static void srv_factory_service_continue_add_declaration(factory_user_struct *user, ATT_HANDLE srvc_handle, OS_STATUS status)
{
    gatts_service_decl_struct*      srvnode = NULL;
    GATT_SVC_UUID   gatt_uuid;
    
	//kal_prompt_trace(MOD_BT, "[gatts_f] srv_factory_service_continue_add_declaration enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_CONITUE_FUN_ENTRY);
    if (user != NULL)
    {
        if ((user->services != NULL) && (user->services->bInitialized == TRUE))
        {
            srvnode = (gatts_service_decl_struct*)mmi_GetNextNode(&user->srvsoper.srvnode->declnode);

            if ((ListEntry*)srvnode != &user->services->srvlist)
            {
                user->srvsoper.srvnode = srvnode;
                
                if (srvnode != NULL)
                {
                    switch (srvnode->type)
                    {
                    case TYPE_SERVICE:
                        {
                            kal_mem_set(&gatt_uuid, 0x0, sizeof(GATT_SVC_UUID));
                            gatt_uuid.is_primary = srvnode->isprimary;
                            kal_mem_cpy(&gatt_uuid.uuid, &srvnode->uuid, sizeof(ATT_UUID));
                            srv_gatts_add_service(user->reg_ctx, &gatt_uuid, srvnode->handlenum);
                        }
                        break;
                    case TYPE_CHARACTERISTIC:
                        {
                            srv_gatts_add_characteristic(user->reg_ctx, srvc_handle, &srvnode->uuid, srvnode->prop, srvnode->permission);
                        }
                        break;
                    case TYPE_DESCRIPTOR:
                        {
                            srv_gatts_add_descriptor(user->reg_ctx, srvc_handle, &srvnode->uuid, srvnode->permission);
                        }
                        break;
                    default:
                        //kal_prompt_trace(MOD_BT, "[gatts_f]add_declaration, unknow type(%d)", srvnode->type);
                        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_DECLARATION_UNKNOW_TYPE, srvnode->type);
                        break;
                    }
                }
            }
            else
            {
                user->srvsoper.state = FACTORY_SRVS_OPER_STATE_IDLE;
                if (user->factory_cb != NULL && user->factory_cb->factory_srvs_added_cb != NULL)
                {
                    user->factory_cb->factory_srvs_added_cb(status, user->reg_ctx);
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_service_continue_add_declaration:user_reg_cb is NULL");
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_CONITUE_REG_CB_NULL);
                }
                // TODO: continue handle pending request ?
            }

        }
    }
}

static void srv_factory_service_added_callback(OS_STATUS status, void *reg_ctx, GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle)
{
    factory_user_struct*    user = NULL;

    user = srv_factory_find_user_by_appctx(reg_ctx);

    if ((user != NULL) && (user->srvsoper.srvnode != NULL))
    {
        user->srvsoper.srvnode->handle = srvc_handle;
        srv_factory_service_continue_add_declaration(user, srvc_handle, status);
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_service_added_callback, user or srv node is null.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_CB_NODE_NULL);
    }
}

static void srv_factory_charac_added_callback(OS_STATUS status, void *reg_ctx, ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle)
{
    factory_user_struct*    user = NULL;

    user = srv_factory_find_user_by_appctx(reg_ctx);

    if ((user != NULL) && (user->srvsoper.srvnode != NULL))
    {
        user->srvsoper.srvnode->handle = char_handle;
        user->srvsoper.srvnode->srvhandle = srvc_handle;
        user->srvsoper.lastchhdl = char_handle;
        srv_factory_service_continue_add_declaration(user, srvc_handle, status);
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_charac_added_callback, user or srv node is null.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_CHAR_CB_NODE_NULL);
        
    }
}

static void srv_factory_des_added_callback(OS_STATUS status, void *reg_ctx, ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle)
{
    factory_user_struct*    user = NULL;

    user = srv_factory_find_user_by_appctx(reg_ctx);

    if ((user != NULL) && (user->srvsoper.srvnode != NULL))
    {
        user->srvsoper.srvnode->handle = char_handle;
        user->srvsoper.srvnode->srvhandle = srvc_handle;
        user->srvsoper.srvnode->charhandle = user->srvsoper.lastchhdl;
        srv_factory_service_continue_add_declaration(user, srvc_handle, status);
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_des_added_callback, user or srv node is null.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_DES_CB_NODE_NULL);
    }

}

static void srv_factory_srv_del_callback(OS_STATUS status, void *reg_ctx, ATT_HANDLE srvc_handle)
{
    factory_user_struct*    user = NULL;

    user = srv_factory_find_user_by_appctx(reg_ctx);


    if (user != NULL)
    {
        user->srvsoper.state = FACTORY_SRVS_OPER_STATE_IDLE;
        if (user->factory_cb != NULL && user->factory_cb->factory_srvs_deleted_cb != NULL)
        {
            user->factory_cb->factory_srvs_deleted_cb(status, user->reg_ctx);
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_srv_del_callback:user_reg_cb is NULL.");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_CB_REG_CB_NULL);
        }

    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_srv_del_callback, user or srv node is null.");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_CB_NODE_NULL);
    }


}

void srv_gatts_profile_factory_init()
{
#ifdef MMI_SRV_CHECK_SERVICE_UUID
    U32 tbl_size = 0;
    U32 i = 0;
#endif

    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_INIT_ENTER);
    kal_mem_set(&factory_ctx, 0x0, sizeof(srvs_factory_ctx_struct));
    mmi_InitializeListHead(&pFactoryCtx->userList);
    pFactoryCtx->bInitialized = TRUE;
    //kal_prompt_trace(MOD_BT, "[gatts_f]gatt_profile_factory_init leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_INIT_LEAVE);
    
#ifdef MMI_SRV_CHECK_SERVICE_UUID    
    memset(g_profile_decl_tbl_new, 0, sizeof(g_profile_decl_tbl_new));
    for (i = 0; i < MAX_PROFILE_CNT ; i ++)
    {
        g_profile_decl_tbl_new[i].id = DEFAULT_PROFILE_ID;
    }
    
    tbl_size = sizeof(g_profile_decl_tbl)/sizeof(g_profile_decl_tbl[0]);
    for (i = 0; i < tbl_size ; i ++)
    {
        g_profile_decl_tbl_new[i].id = g_profile_decl_tbl[i].id;
        g_profile_decl_tbl_new[i].profile_decl = g_profile_decl_tbl[i].profile_decl;
        g_profile_decl_tbl_new[i].decl_num = g_profile_decl_tbl[i].decl_num;
    }
#endif
    
#ifdef __GATT_SRV_MEM_USE_ADM__
    gattsrv_adm_buffer_pool_id = kal_adm_create((void *)gattsrv_adm_buffer_pool, sizeof(gattsrv_adm_buffer_pool), NULL, KAL_FALSE);
    if (!gattsrv_adm_buffer_pool_id) //create failed
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_CREATE_FAIL);
    }
    else //create success
    {
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_MEM_CREATE_SUCCESS);
    }
#endif

    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_INIT_LEAVE);
}

void srv_gatts_profile_factory_deinit()
{
    factory_user_struct* user = NULL;

    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_deinit enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEINIT_ENTER);

    while (!mmi_IsListEmpty(&pFactoryCtx->userList) && pFactoryCtx->bInitialized == TRUE)
    {
        user = (factory_user_struct*)mmi_RemoveHeadList(&pFactoryCtx->userList);

        if (user != NULL)
        {
            srv_gatts_profile_factory_deregister(user->reg_ctx);
            if (user != NULL)
            {
                gattsrv_free(user);
                user = NULL;
            }
        }
}

    kal_mem_set(&factory_ctx, 0x0, sizeof(srvs_factory_ctx_struct));
    mmi_InitializeListHead(&pFactoryCtx->userList);
    pFactoryCtx->bInitialized = FALSE;
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_deinit leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEINIT_LEAVE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_register
 * DESCRIPTION
 *  Register gatts profile callback. Callback functions about add-services will be replaced by this register function.
 * PARAMETERS
 * uuid          [IN]
 * factory_cb [IN]
 * gatts_cb    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_profile_factory_register(bt_uuid_struct* uuid, gatts_callback_struct* gatts_cb, 
                                                                    gatts_factory_callback_struct* factory_cb)
{
    factory_user_struct* factory_user = NULL;
    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_register enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_ENTER);

    //srv_factory_get_services_by_profile_id(3);
    if (pFactoryCtx->bInitialized != TRUE)
    {
        srv_gatts_profile_factory_init();
    }

    //  check if the same uuid exists on userlist.
    if ((uuid != NULL) && srv_factory_find_user_by_apid(uuid) == NULL)
    {
        // TODO: Add mutex protection.   
        factory_user = srv_factory_new_user();

        if (factory_user != NULL)
        {
            kal_mem_cpy(&factory_user->gatts_cb, gatts_cb, sizeof(gatts_callback_struct));
            factory_user->user_reg_cb = gatts_cb->register_server_cb;
            factory_user->user_dereg_cb = gatts_cb->deregister_server_cb;
            factory_user->factory_cb = factory_cb;
            factory_user->reg_ctx = NULL;
            factory_user->apid = uuid;

            // TODO: replace add services related function in gatts_callback
            if (gatts_cb != NULL)
            {
                factory_user->gatts_cb.register_server_cb = srv_factory_user_regeistered;
                factory_user->gatts_cb.service_added_cb = srv_factory_service_added_callback;
                factory_user->gatts_cb.included_service_added_cb = NULL;
                factory_user->gatts_cb.characteristic_added_cb = srv_factory_charac_added_callback;
                factory_user->gatts_cb.descriptor_added_cb = srv_factory_des_added_callback;
                factory_user->gatts_cb.service_deleted_cb = srv_factory_srv_del_callback;
                factory_user->gatts_cb.deregister_server_cb = srv_factory_user_deregeistered;
            }
            // TODO: Remove mutex protection.       
            srv_gatts_register(uuid, &factory_user->gatts_cb);          
        }
        else
        {
            // TODO: Remove mutex protection.       
            //kal_prompt_trace(MOD_BT, "[gatts_f]regist failed. user is NULL");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_FAILED_USER_NULL);
            if ((gatts_cb != NULL) && (gatts_cb->register_server_cb != NULL))
            {     
                //gatts_cb->register_server_cb(NULL, OS_STATUS_FAILED, uuid);
            }
            else
            {
                //kal_prompt_trace(MOD_BT, "[gatts_f]regist failed. callback is NULL");
                MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_FAILED_CB_NULL);
            }
        }
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]regist failed. userid is NULL or registered already");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_FAILED_UID_NULL_OR_REG_ALREADY);
        if ((gatts_cb != NULL) && (gatts_cb->register_server_cb != NULL))
        {

            //gatts_cb->register_server_cb(NULL, OS_STATUS_FAILED, uuid);
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]regist failed. callback is NULL");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_FAILED_CB_NULL);
        }    
    }
    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_register leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_REG_LEAVE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_deregister
 * DESCRIPTION
 * Deregister a server application from the stack..
 * PARAMETERS
 * reg_ctx    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_profile_factory_deregister(void* reg_ctx)
{
    factory_user_struct* user = NULL;
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_deregister enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEREG_ENTER);
    srv_gatts_deregister(reg_ctx);

    // FInd user with reg_ctx.  Remove the entry from userlist and free the user.
    // TODO: Add mutex protection.   
    //user = srv_factory_find_user_by_appctx(reg_ctx);
    //srv_gatts_profile_factory_clear_services(reg_ctx, NULL);
    //srv_factory_free_user(user);
    // TODO: Remove mutex protection.   
    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_deregister leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEREG_LEAVE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_get_services
 * DESCRIPTION
 * Get gatts profile services by profile id. gatts_services_struct fill be filled without handle.
 * PARAMETERS
 * reg_ctx      [IN]
 * id              [IN]
 * services     [IN]
 * RETURNS
 *  OS_STATUS
 *****************************************************************************/
#ifdef MMI_SRV_CHECK_SERVICE_UUID
OS_STATUS srv_gatts_profile_factory_get_services(void* reg_ctx, S32 id, gatts_srvs_lst_struct* services)
#else
OS_STATUS srv_gatts_profile_factory_get_services(void* reg_ctx, gatt_profile_id_enum id, gatts_srvs_lst_struct* services)
#endif
{
    factory_user_struct* user = NULL;
    OS_STATUS ret = OS_STATUS_FAILED;
    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_get_services enter ctx(%d)", (U32)reg_ctx);
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_GET_SRV_FUN_ENTER, (U32)reg_ctx);
    // TODO: Add mutex protection.
    user = srv_factory_find_user_by_appctx(reg_ctx);
    if ((user != NULL) && (services != NULL))
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]get_services user state:(%d)", user->status);  
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_GET_SRV_IN_STATE, user->status);
        switch (user->status)
        {
        case FACTORY_STS_IDLE:
            {
                user->services = services;
                //user->status = FACTORY_STS_PENDING;
                user->profile_id = id;
                // TODO: check if there's pending request. If no exists, parse the xml.
                pFactoryCtx->parser.user = user;
                ret = srv_factory_get_services_by_profile_id(id);
            }
            break;
        case FACTORY_STS_PROCESSING:
            {
            }
            break;
        case FACTORY_STS_PENDING:
            {
            }
            break;    
        case FACTORY_STS_SRVS_GOT:
            {
            }
            break;
        default:
            break;
        }        
    }
    else
    {
        //kal_prompt_trace(MOD_BT, "[gatts_f]Get services fiald reg_ctx or services is NULL");
        MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_GET_SRV_FAILED_CTX_NULL);
    }
    // TODO: Remove mutex protection.    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_get_services leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_GET_SRV_FUN_LEAVE);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_clear_services
 * DESCRIPTION
 * Clear used resource in profile factory. If this function is called, the parameter service structure will be set to empty.
 * PARAMETERS
 * reg_ctx       [IN]
 * services      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_profile_factory_clear_services(void* reg_ctx, gatts_srvs_lst_struct* services)
{
    factory_user_struct*    user = NULL;
    gatts_service_decl_struct*   srvnode = NULL;


    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_clear_services enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_CLR_SRV_FUN_ENTER);
    // TODO: Add mutex protection.
    user = srv_factory_find_user_by_appctx(reg_ctx);

    if (user != NULL)
    {
        while (!mmi_IsListEmpty(&user->services->srvlist) && (user->services->bInitialized == TRUE))
        {
            srvnode = (gatts_service_decl_struct*)mmi_RemoveHeadList(&user->services->srvlist);

            if (srvnode != NULL)
            {
                gattsrv_free(srvnode);
                srvnode = NULL;
            }
        }
    }

    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_clear_services leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_CLR_SRV_FUN_LEAVE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_add_services
 * DESCRIPTION
 * Add gatts profile services  to gatt stack.
 * PARAMETERS
 * reg_ctx       [IN]
 * services      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_profile_factory_add_services(void* reg_ctx, gatts_srvs_lst_struct* services)
{
    factory_user_struct*    user = NULL;

    gatts_service_decl_struct* declnode = NULL;
    gatts_service_decl_struct* headnode = NULL;
    ListEntry* head = NULL;
    GATT_SVC_UUID   gatt_uuid;

    OS_STATUS status = OS_STATUS_FAILED;

    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_add_services enter");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FUN_ENTER);
    // TODO: Add mutex protection.
    user = srv_factory_find_user_by_appctx(reg_ctx);

    if (user != NULL && (user->srvsoper.state == FACTORY_SRVS_OPER_STATE_IDLE))
    {
        if ((user->services != NULL) && (user->services->bInitialized == TRUE))
        {
            if (!mmi_IsListEmpty((ListEntry*)&user->services->srvlist))
            {
                declnode = (gatts_service_decl_struct*)mmi_GetHeadList((ListEntry*)&user->services->srvlist);
                user->srvsoper.srvnode = declnode;
                
                if (declnode->type == TYPE_SERVICE)
                {
                    user->srvsoper.state = FACTORY_SRVS_OPER_STATE_ADDING;
                    
                    kal_mem_set(&gatt_uuid, 0x0, sizeof(GATT_SVC_UUID));
                    gatt_uuid.is_primary = declnode->isprimary;
                    kal_mem_cpy(&gatt_uuid.uuid, &declnode->uuid, sizeof(ATT_UUID));
                    srv_gatts_add_service(user->reg_ctx, &gatt_uuid, declnode->handlenum);
                    
                    status = OS_STATUS_SUCCESS;
                }
                else
                {
                    //kal_prompt_trace(MOD_BT, "[gatts_f]add services failed Head node is not srv."); 
                    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_HEAD_NOT_SRV);
                }
            }
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]add services failed Service sate is wrong");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_STATE_IS_WRONG);
        }
    }
    else
    {
        if (user == NULL)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]add services failed User is null");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_USER_NULL);
        }
        else if (user->srvsoper.state != FACTORY_SRVS_OPER_STATE_IDLE)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]add services failed state is not idle (%d)", user->srvsoper.state); 
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_NOT_IDLE, user->srvsoper.state);
        }
    }

    if (status != OS_STATUS_SUCCESS)
    {
        if (user != NULL)
        {
            if (user->factory_cb != NULL && user->factory_cb->factory_srvs_added_cb != NULL)
            {
                //user->factory_cb->factory_srvs_added_cb(status, reg_ctx);
            }
            else
            {
                //kal_prompt_trace(MOD_BT, "[gatts_f]Add srv failed:user_reg_cb is NULL");
                MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_REG_CB_NULL);
            }

        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]srv_factory_service_add srv.  user or srv node is null");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_FAILED_NODE_NULL);
        }
    }
    
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_add_services leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_ADD_SRV_LEAVE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_profile_factory_delete_services
 * DESCRIPTION
 * Delete gatts profile services from gatt stack.
 * PARAMETERS
 * reg_ctx       [IN]
 * services      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_profile_factory_delete_services(void* reg_ctx, gatts_srvs_lst_struct* services)
{
    factory_user_struct*    user = NULL;

    gatts_service_decl_struct* declnode = NULL;
    gatts_service_decl_struct* headnode = NULL;

    OS_STATUS status = OS_STATUS_FAILED;
    

    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_del_services enter");    
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FUN_ENTER);
    // TODO: Add mutex protection.
    user = srv_factory_find_user_by_appctx(reg_ctx);

    if (user != NULL && (user->srvsoper.state == FACTORY_SRVS_OPER_STATE_IDLE))
    {
        if ((user->services != NULL) && (user->services->bInitialized == TRUE))
        {
            declnode = (gatts_service_decl_struct*)mmi_GetHeadList(&user->services->srvlist);
            user->srvsoper.srvnode = declnode;

       /* user = (factory_user_struct*)mmi_GetHeadList(&pFactoryCtx->userList);
        while ((ListEntry*)user != &pFactoryCtx->userList)
        {
            if (user->reg_ctx == ctx)
            {
                found_user = user;
                break;
            }
            user = (factory_user_struct*)GetNextNode(&user->node);
        }*/
            while ((ListEntry*)declnode != &user->services->srvlist)
            {
                if (declnode->type == TYPE_SERVICE)
                {
                    user->srvsoper.state = FACTORY_SRVS_OPER_STATE_DELETING;
                    srv_gatts_delete_service(user->reg_ctx, declnode->handle);
                    user->srvsoper.state = FACTORY_SRVS_OPER_STATE_IDLE;
                    status = OS_STATUS_SUCCESS;
                }

                declnode = (gatts_service_decl_struct*)mmi_GetNextNode(&declnode->declnode);
            }
        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]del services failed Service init sate or srv is wrong");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FAILED_INIT_STATE_ERR);
        }
    }
    else
    {
        if (user == NULL)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]del services failed User is null");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FAILED_USER_NULL);
        }
        else if (user->srvsoper.state != FACTORY_SRVS_OPER_STATE_IDLE)
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]del services failed state is not idle (%d)", user->srvsoper.state); 
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FAILED_NOT_IDLE,  user->srvsoper.state);
        }
    }

    if (status != OS_STATUS_SUCCESS)
    {
        if (user != NULL)
        {
            if (user->factory_cb != NULL && user->factory_cb->factory_srvs_deleted_cb != NULL)
            {
                //user->factory_cb->factory_srvs_deleted_cb(status, reg_ctx);
            }
            else
            {
                //kal_prompt_trace(MOD_BT, "[gatts_f]del srv fialed callback is NULL");
                MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FAILED_CB_NULL);
            }

        }
        else
        {
            //kal_prompt_trace(MOD_BT, "[gatts_f]delete srv failed. user or srv node is null");
            MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FAILED_SRV_NODE_NULL);
        }
    }
    //kal_prompt_trace(MOD_BT, "[gatts_f]srv_gatts_profile_factory_del_services leave");
    MMI_TRACE(SRV_GATT_F_TRACE_GROUP, TRC_SRV_GATT_F_DEL_SRV_FUN_LEAVE);

}

#ifdef MMI_SRV_CHECK_SERVICE_UUID
static BOOL srv_gatts_profile_factory_chk_service(U32 table_pos, gatts_profile_srv_decl_struct *srv_list, U32 decl_num)
{
    U32 i = 0, j = 0, decl_num_temp = 0;
    BOOL fgExist = FALSE;
    
	kal_prompt_trace(MOD_BT, "[srv_gatts_profile_factory_chk_service] ==>, decl_num:%d \n", decl_num);

    decl_num_temp = g_profile_decl_tbl_new[table_pos].decl_num;
    for (i = 0; i < decl_num_temp; i ++)
    {
        if (g_profile_decl_tbl_new[table_pos].profile_decl[i].type == TYPE_SERVICE) //check service UUID
        {
            for (j = 0; j < decl_num; j ++)
            {
                if (srv_list[j].type == TYPE_SERVICE)
                {
                    if (!memcmp(g_profile_decl_tbl_new[table_pos].profile_decl[i].uuid, srv_list[j].uuid, strlen(PROFILE_BASE_UUID)))
                    {
                        kal_prompt_trace(MOD_BT, "[ERROR] Find the same service UUID in g_profile_decl_tbl_new[] table!!! \n");
                        kal_prompt_trace(MOD_BT, "[ERROR] UUID: 0x%x,0x%x,0x%x,0x%x \n", srv_list[j].uuid[0], srv_list[j].uuid[1], 
                            srv_list[j].uuid[2], srv_list[j].uuid[3]);

                        fgExist = TRUE;
                        break;
                    }
                }
            }
        }

        if (fgExist)
        {
            break;
        }
    }

	kal_prompt_trace(MOD_BT, "[srv_gatts_profile_factory_chk_service] <==>, fgExist:%d \n", fgExist);
    
    return fgExist;
}
#endif

S32 srv_gatts_profile_factory_create_srv_list(gatts_profile_srv_decl_struct *srv_list, U32 decl_num)
{
#ifdef MMI_SRV_CHECK_SERVICE_UUID
    S32 profile_id = DEFAULT_PROFILE_ID;
    U32 i = 0, valid_pos = 0;
    BOOL fgExist = FALSE;

	kal_prompt_trace(MOD_BT, "[srv_gatts_profile_factory_create_srv_list] ==>, decl_num:%d \n", decl_num);

    for (i = 0; i < MAX_PROFILE_CNT; i ++)
    {
        if (g_profile_decl_tbl_new[i].id == DEFAULT_PROFILE_ID)
        {
            valid_pos = i;
            break;
        }
        else
        {
            if (profile_id < g_profile_decl_tbl_new[i].id)
            {
                profile_id = g_profile_decl_tbl_new[i].id; //save profile id
            }
            
            fgExist = srv_gatts_profile_factory_chk_service(i, srv_list, decl_num);
            if (fgExist)
            {
                valid_pos = MAX_PROFILE_CNT;
                break;
            }
        }
    }
    
	kal_prompt_trace(MOD_BT, "valid_pos:%d \n", valid_pos);

    if (valid_pos < (MAX_PROFILE_CNT - 1))
    {
        profile_id += 1; //last valid profile id + 1
        g_profile_decl_tbl_new[valid_pos].id = profile_id;
        g_profile_decl_tbl_new[valid_pos].decl_num = decl_num;
        g_profile_decl_tbl_new[valid_pos].profile_decl = srv_list;
    }
    else
    {
        profile_id = DEFAULT_PROFILE_ID;
        kal_prompt_trace(MOD_BT, "[ERROR] No valid pos in g_profile_decl_tbl_new[] table!!! \n");
    }
    
    return profile_id;
#else //MMI_SRV_CHECK_SERVICE_UUID
    return -1;
#endif //MMI_SRV_CHECK_SERVICE_UUID
}

OS_STATUS srv_gatts_profile_factory_delete_srv_list(S32 profile_id)
{
#ifdef MMI_SRV_CHECK_SERVICE_UUID
    OS_STATUS status = OS_STATUS_FAILED;
    U32 i = 0;
    
    kal_prompt_trace(MOD_BT, "[srv_gatts_profile_factory_delete_srv_list] ==>, profile_id:%d \n", profile_id);
    
    for (i = 0; i < MAX_PROFILE_CNT; i ++)
    {
        if (g_profile_decl_tbl_new[i].id == profile_id)
        {
            kal_prompt_trace(MOD_BT, "[ERROR] Find!!! \n");
            
            g_profile_decl_tbl_new[i].id = DEFAULT_PROFILE_ID; //restore to default value
            g_profile_decl_tbl_new[i].profile_decl = NULL;
            g_profile_decl_tbl_new[i].decl_num = 0;
            
            status = OS_STATUS_SUCCESS;
        }
    }
    
    kal_prompt_trace(MOD_BT, "[srv_gatts_profile_factory_delete_srv_list] <==, status:%d \n", status);
    
    return status;
#else //MMI_SRV_CHECK_SERVICE_UUID
    return OS_STATUS_FAILED;
#endif //MMI_SRV_CHECK_SERVICE_UUID
}

#endif
