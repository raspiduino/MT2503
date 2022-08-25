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
 *  EngineerModeDM.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode device management related items, inlcudes:
 *     - DM Self register
 *     - DM add APN
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_ENGINEER_MODE__ 

#include "CommonScreens.h"
#include "wgui_categories_util.h"
#include "EngineerModeUtil.h"
#include "EngineerModeResDef.h"
#include "EngineerModeAppResDef.h"
//#include "FactoryModeDef.h"
/* DM self register */
#ifdef __MMI_EM_MISC_DM_REGISTER__
#include "nvram_common_defs.h"
#include "DmSelfRegisterGprot.h"
#include "DmSelfRegisterProt.h"
#include "mmi_rp_srv_dm_sr_def.h"
#endif

#ifdef SYNCML_DM_SUPPORT
#include "DMTypeDef.h"
#endif

/* DM add APN */
#if defined(__MMI_EM_MISC_DM_ADD_APN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_DM_ADD_APN__ */

#ifdef  __MMI_EM_MISC_DCD__
#include "custom_dcd.h"
#endif /* __MMI_EM_MISC_DCD__ */

#include "EngineerModeCommUI.h"
#include "EngineerModeDM.h"

/* inline cui */
#include "inlinecuigprot.h"
#include "mmi_rp_app_engineermode1_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef  __MMI_EM_MISC_DCD__
typedef struct
{
	S8	 apn[DCD_EM_CUST_APN_LEN*ENCODING_LENGTH];
	S8   apn_name[DCD_EM_CUST_NAME_LEN*ENCODING_LENGTH];
    U8   gateway_ip[4];
	S8   port[DCD_EM_CUST_PORT_LEN*ENCODING_LENGTH];
	S8   add_chan_url[DCD_EM_CUST_URL_LEN*ENCODING_LENGTH];
	S8   del_chan_url[DCD_EM_CUST_URL_LEN*ENCODING_LENGTH];
	S8   refresh_url[DCD_EM_CUST_URL_LEN*ENCODING_LENGTH];
	S8   help_url[DCD_EM_CUST_URL_LEN*ENCODING_LENGTH];	
} mmi_em_dcd_nw_editor_struct;
#endif /*__MMI_EM_MISC_DCD__*/
/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

/* DM self register */
#ifdef __MMI_EM_MISC_DM_REGISTER__
S8 dm_self_reg_des_number[NVRAM_EF_DM_SR_NUMBER_SIZE];
S8 dm_self_reg_manufacture_name[NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE];

S8 dm_self_reg_des_device_name[DM_SR_DEVICE_MODEL_SIZE];

static U8 ture_slected = 0;
static U16 g_em_ucs2_display_buf[MMI_EM_DISPLAY_BUF_MAX_LEN];
static U16 g_em_ucs2_display_device_name_buf[MMI_EM_DISPLAY_BUF_MAX_LEN];

#ifdef __OP02_DM__
S8 dm_self_reg_des_port_number[NVRAM_EF_DM_SR_NUMBER_SIZE];
#endif
#endif

/* DM add APN */
#if defined(__MMI_EM_MISC_DM_ADD_APN__)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_DM_ADD_APN__ */

#ifdef  __MMI_EM_MISC_DCD__
static mmi_em_dcd_nw_editor_struct * g_em_dcd_editor_p;
#define NW_PARAM_APN_CAPTION_ID                     (CUI_INLINE_ITEM_ID_BASE + 1)
#define NW_PARAM_APN_TEXTEDIT_ID                    (CUI_INLINE_ITEM_ID_BASE + 2)
#define NW_PARAM_GATEWAY_CAPTION_ID                 (CUI_INLINE_ITEM_ID_BASE + 3)
#define NW_PARAM_GATEWAY_IP4_ID                     (CUI_INLINE_ITEM_ID_BASE + 4)
#define NW_PARAM_PORT_CAPTION_ID                    (CUI_INLINE_ITEM_ID_BASE + 5)
#define NW_PARAM_PORT_TEXTEDIT_ID                   (CUI_INLINE_ITEM_ID_BASE + 6)
#define NW_PARAM_ADD_CHAN_CAPTION_ID                (CUI_INLINE_ITEM_ID_BASE + 7)
#define NW_PARAM_ADD_CHAN_TEXTEDIT_ID               (CUI_INLINE_ITEM_ID_BASE + 8)
#define NW_PARAM_DEL_CHAN_CAPTION_ID                (CUI_INLINE_ITEM_ID_BASE + 9)
#define NW_PARAM_DEL_TEXTEDIT_ID                    (CUI_INLINE_ITEM_ID_BASE + 10)
#define NW_PARAM_REF_URL_CAPTION_ID                 (CUI_INLINE_ITEM_ID_BASE + 11)
#define NW_PARAM_REF_URL_TEXTEDIT_ID                (CUI_INLINE_ITEM_ID_BASE + 12)
#define NW_PARAM_HEL_URL_CAPTION_ID                 (CUI_INLINE_ITEM_ID_BASE + 13)
#define NW_PARAM_HEL_URL_TEXTEDIT_ID                (CUI_INLINE_ITEM_ID_BASE + 14)
/* apn */
static const cui_inline_item_caption_struct nw_param_apn_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_APN
};
static const cui_inline_item_text_edit_struct nw_param_apn = 
{
    0,
    0,
    DCD_EM_CUST_APN_LEN,
    IMM_INPUT_TYPE_ASCII_CHAR,
    0,
    0
};
/* gateway */
static const cui_inline_item_caption_struct nw_param_gateway_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_GATEWAY
};
static const cui_inline_item_ip4_struct nw_param_gateway = 
{
    0,
    0,
    0,
    0
};
/* port */
static const cui_inline_item_caption_struct nw_param_port_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_PORT
};
static const cui_inline_item_text_edit_struct nw_param_port = 
{
    0,
    0,
    DCD_EM_CUST_PORT_LEN,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    0
};
/* add channel url */
static const cui_inline_item_caption_struct nw_param_add_chan_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_ADD_CHAN_URL
};
static const cui_inline_item_text_edit_struct nw_param_add_chan = 
{
    0,
    0,
    DCD_EM_CUST_URL_LEN,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    0
};
/* delete channel url */
static const cui_inline_item_caption_struct nw_param_del_chan_capiton = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_DEL_CHAN_URL
};
static const cui_inline_item_text_edit_struct nw_param_del_chan = 
{
    0,
    0,
    DCD_EM_CUST_URL_LEN,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    0
};
/* refresh url */
static const cui_inline_item_caption_struct nw_param_ref_url_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_REFRESH_URL
};
static const cui_inline_item_text_edit_struct nw_param_ref_url = 
{
    0,
    0,
    DCD_EM_CUST_URL_LEN,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    0
};
/* help url */
static const cui_inline_item_caption_struct nw_param_hel_caption = 
{
    STR_ID_EM_MISC_DCD_NW_PARAM_HELP_URL
};
static const cui_inline_item_text_edit_struct nw_param_hel_url = 
{
    0,
    0,
    DCD_EM_CUST_URL_LEN,
    IMM_INPUT_TYPE_ENGLISH_SENTENCE,
    0,
    0
};

/* inline items */
static const cui_inline_set_item_struct nw_param_items[] = 
{
    {NW_PARAM_APN_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&nw_param_apn_caption},
    {NW_PARAM_APN_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_apn},
    {NW_PARAM_GATEWAY_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&nw_param_gateway_caption},
    {NW_PARAM_GATEWAY_IP4_ID, CUI_INLINE_ITEM_TYPE_IP4, 0, (void*)&nw_param_gateway},
    {NW_PARAM_PORT_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&nw_param_port_caption},
    {NW_PARAM_PORT_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_port},
    {NW_PARAM_ADD_CHAN_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&nw_param_add_chan_caption},
    {NW_PARAM_ADD_CHAN_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_add_chan},
    {NW_PARAM_DEL_CHAN_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&nw_param_del_chan_capiton},
    {NW_PARAM_DEL_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_del_chan},
    {NW_PARAM_REF_URL_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&nw_param_ref_url_caption},
    {NW_PARAM_REF_URL_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_ref_url},
    {NW_PARAM_HEL_URL_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L7, (void*)&nw_param_hel_caption},
    {NW_PARAM_HEL_URL_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&nw_param_hel_url}
};
static const cui_inline_struct nw_param_inline = 
{
    sizeof(nw_param_items) / sizeof(cui_inline_set_item_struct),
    STR_ID_EM_MISC_DCD_NW_PARAM,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    nw_param_items
};
#endif /* __MMI_EM_MISC_DCD__ */
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* Display Buffer for Engineering Mode and Factory Mode */
//extern S8 EMFMUnicodeDisplayBuf[MAX_TEST_STRING_BUF * 2];


/***************************************************************************** 
 * Static function
 *****************************************************************************/

/* DM self register */
#ifdef __MMI_EM_MISC_DM_REGISTER__
static void EntryEmMisDMSelfRegister(void);
static void EmMiscDMSelfRegisterHandler(void);
static void mmi_em_misc_dm_self_register_main_screen(void);
static void mmi_em_misc_dm_self_register_main_device_name_screen(void);

static U16* mmi_em_get_ucs2_display_buf(void);
    #ifdef __OP02_DM__
    static void EmMisDMReadDMSMSReq(U8 index);
    static MMI_BOOL EmMisDMReadDMSMSRsp(void *inMsg);
    static void EmMisDMUpdateDMSMSReq(U8 index);
    static MMI_BOOL EmMisDMUpdateDMSMSRsp(void *inMsg);
    static void EntryEmMisDMSelfRegisterPort(void);
    static void EmMiscDMSelfRegisterPortHandler(void);
    static void mmi_em_misc_dm_self_register_port_main_screen(void);
    #endif
#endif /* __MMI_EM_MISC_DM_REGISTER__ */

/* DM add APN */
#if defined(__MMI_EM_MISC_DM_ADD_APN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_DM_ADD_APN__ */

#ifdef  __MMI_EM_MISC_DCD__
static void mmi_em_misc_dcd_nw_param_entry(void);
static mmi_ret mmi_em_misc_dcd_nw_param_proc(mmi_event_struct *evt);
static void mmi_em_misc_dcd_nw_param_enter_main_screen(void);
static void mmi_em_misc_dcd_nw_param_set_inline_cui(mmi_id inline_cui_id);
static void mmi_em_misc_dcd_nw_param_save(mmi_id inline_cui_id);
static MMI_BOOL mmi_em_misc_dcd_nw_param_string_to_uint(char *str, U32 str_len, U32 *val);
#endif /* __MMI_EM_MISC_DCD__ */

/*-----------------------------------------------------------------------------*/
/*----------------------------- DM Self register ------------------------------*/
/*-----------------------------------------------------------------------------*/

#ifdef __MMI_EM_MISC_DM_REGISTER__
static U16* mmi_em_get_ucs2_display_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)g_em_ucs2_display_buf;
}

static U16* mmi_em_get_ucs2_display_device_name_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U16*)g_em_ucs2_display_device_name_buf;
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmMisDMSelfRegister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmMisDMSelfRegister(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_EM_MISC_DM_SELF_REGISTER))
    {
        mmi_frm_group_close(GRP_ID_EM_MISC_DM_SELF_REGISTER);
    }
    root_id = mmi_em_get_root_group();
    mmi_frm_group_create(root_id, GRP_ID_EM_MISC_DM_SELF_REGISTER, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_misc_dm_self_register_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmMisDMSelfRegister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmMisDMSelfRegisterdevicename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_EM_MISC_DM_SELF_REGISTER))
    {
        mmi_frm_group_close(GRP_ID_EM_MISC_DM_SELF_REGISTER);
    }
    root_id = mmi_em_get_root_group();
    mmi_frm_group_create(root_id, GRP_ID_EM_MISC_DM_SELF_REGISTER, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_misc_dm_self_register_main_device_name_screen();
}



/**************************************************************
**	FUNCTION NAME		: EmMiscDMSelfRegisterHandler
**
**  PURPOSE				: 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmMiscDMSelfRegisterHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __OP02_DM__
    S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) dm_self_reg_des_number, (S8*) mmi_em_get_ucs2_display_buf());

    dm_self_reg_des_number[strlen(dm_self_reg_des_number)]='\0';

#ifdef __OP02_DM__
    mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_UPDATE_RSP, (PsIntFuncPtr)EmMisDMUpdateDMSMSRsp, MMI_TRUE);
    EmMisDMUpdateDMSMSReq(0);
#else
	WriteRecord(NVRAM_EF_DM_SR_NUMBER_LID, 1, &dm_self_reg_des_number, NVRAM_EF_DM_SR_NUMBER_SIZE, &error);

    if (error >= 0)
    {
        mmi_em_display_notify_popup(MMI_TRUE);
    }
    else
    {
        mmi_em_display_notify_popup(MMI_FALSE);
    }

    mmi_frm_scrn_close(GRP_ID_EM_MISC_DM_SELF_REGISTER, SCR_ID_EM_MISC_DM_SELF_REGISTER);
#endif
}

void EmMiscDMSelfRegisterdevicenameHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) dm_self_reg_des_device_name, (S8*) mmi_em_get_ucs2_display_device_name_buf());

    dm_self_reg_des_device_name[strlen(dm_self_reg_des_device_name)]='\0';
    /*check */
    
    memcpy(&dm_self_reg_manufacture_name[30], dm_self_reg_des_device_name, (sizeof(dm_self_reg_des_device_name) - 1));

    WriteRecord(NVRAM_EF_UEM_MANUFACTURE_DATA_LID, 1, &dm_self_reg_manufacture_name, NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE, &error);

    mmi_em_display_notify_popup(error >= 0);

    mmi_frm_scrn_close(GRP_ID_EM_MISC_DM_SELF_REGISTER, SCR_ID_EM_MISC_DM_SELF_REGISTER);
}

#ifdef __OP02_DM__

static void EmMisDMReadDMSMSReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_req_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    read_ptr = (dm_node_op_read_req_struct*)construct_local_para(sizeof(dm_node_op_read_req_struct), TD_RESET);

    read_ptr->request_app = DM_NODE_OP_APP_EM;
    if(index == 0)
    {
        strcpy((char*)read_ptr->uri, (const char*)DM_SR_DES_NUM_URI);
    }
    else if(index == 1)
    {
        strcpy((char*)read_ptr->uri, (const char*)DM_SR_PORT_NUM_URI);
    }
    else
    {
        MMI_ASSERT(0);
    }
    MMI_SEND_MSG_TO_DM(MSG_ID_DM_NODE_OP_READ_REQ, read_ptr);

}

static MMI_BOOL EmMisDMReadDMSMSRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_rsp_struct *ptr = (dm_node_op_read_rsp_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if(ptr->request_app != DM_NODE_OP_APP_EM)
    {
        return MMI_FALSE;
    }
    else
    {
        if(strcmp((const char*)ptr->uri, (const char*)DM_SR_DES_NUM_URI)==0)
        {
            if(ptr->result != DM_RESULT_ERR_SUCC)
            {

            }
            else
            {
                if(ptr->data_type != DM_DATA_TYPE_S8)
                {
                    MMI_ASSERT(0);
                }
                else if(ptr->data_length == 0)
                {
                    MMI_ASSERT(0);
                }
                else
                {
                    strncpy((char*)dm_self_reg_des_number, (const char*)ptr->data, ptr->data_length);
                    dm_self_reg_des_number[ptr->data_length]='\0';
                    mmi_asc_to_ucs2((S8*)mmi_em_get_ucs2_display_buf(), dm_self_reg_des_number);
                    EntryEmMisDMSelfRegister();
                }
            }
        }
        else if(strcmp((const char*)ptr->uri, (const char*)DM_SR_PORT_NUM_URI)==0)
        {
            if(ptr->result != DM_RESULT_ERR_SUCC)
            {

            }
            else
            {
                if(ptr->data_type != DM_DATA_TYPE_S8)
                {
                    MMI_ASSERT(0);
                }
                else if(ptr->data_length == 0)
                {
                    MMI_ASSERT(0);
                }
                else
                {
                    strncpy((char*)dm_self_reg_des_port_number, (const char*)ptr->data, ptr->data_length);
                    dm_self_reg_des_port_number[ptr->data_length]='\0';
                    mmi_asc_to_ucs2((S8*)mmi_em_get_ucs2_display_buf(), dm_self_reg_des_port_number);
                    EntryEmMisDMSelfRegisterPort();
                }
            }
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


static void EmMisDMUpdateDMSMSReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_update_req_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    read_ptr = (dm_node_op_update_req_struct*)construct_local_para(sizeof(dm_node_op_update_req_struct), TD_RESET);

    read_ptr->request_app = DM_NODE_OP_APP_EM;
    if(index == 0)
    {
        strcpy((char*)read_ptr->uri, (const char*)DM_SR_DES_NUM_URI);
        read_ptr->data_type = DM_DATA_TYPE_S8;
        read_ptr->data_length = strlen(dm_self_reg_des_number);
        strcpy((char*)read_ptr->data, (const char*)dm_self_reg_des_number);
    } 
    else if(index == 1)
    {
        strcpy((char*)read_ptr->uri, (const char*)DM_SR_PORT_NUM_URI);
        read_ptr->data_type = DM_DATA_TYPE_S8;
        read_ptr->data_length = strlen(dm_self_reg_des_port_number);
        strcpy((char*)read_ptr->data, (const char*)dm_self_reg_des_port_number);
    }
    else
    {
        MMI_ASSERT(0);
    }
    MMI_SEND_MSG_TO_DM(MSG_ID_DM_NODE_OP_UPDATE_REQ, read_ptr);

}

static MMI_BOOL EmMisDMUpdateDMSMSRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_update_rsp_struct *ptr = (dm_node_op_update_rsp_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if(ptr->request_app != DM_NODE_OP_APP_EM)
    {
        return MMI_FALSE;
    }
    else
    {
        if(strcmp((const char*)ptr->uri, (const char*)DM_SR_DES_NUM_URI)==0)
        {
            if (ptr->result == DM_RESULT_ERR_SUCC)
            {
                mmi_em_display_notify_popup(MMI_TRUE);
            }
            else
            {
                mmi_em_display_notify_popup(MMI_FALSE);
            }

            mmi_frm_scrn_close(GRP_ID_EM_MISC_DM_SELF_REGISTER, SCR_ID_EM_MISC_DM_SELF_REGISTER);
        }
        else if(strcmp((const char*)ptr->uri, (const char*)DM_SR_PORT_NUM_URI)==0)
        {
            if (ptr->result == DM_RESULT_ERR_SUCC)
            {
                mmi_em_display_notify_popup(MMI_TRUE);
            }
            else
            {
                mmi_em_display_notify_popup(MMI_FALSE);
            }

            mmi_frm_scrn_close(GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT, SCR_ID_EM_MISC_DM_SELF_REGISTER_PORT);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

extern void EmMisDMGetSelfRegisterPort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8)dm_self_reg_des_port_number, 0, sizeof(dm_self_reg_des_port_number));
    mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_READ_RSP, (PsIntFuncPtr)EmMisDMReadDMSMSRsp, MMI_TRUE);
    EmMisDMReadDMSMSReq(1);
}

static void EntryEmMisDMSelfRegisterPort(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT))
    {
        mmi_frm_group_close(GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT);
    }
    root_id = mmi_em_get_root_group();
    mmi_frm_group_create(root_id, GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_misc_dm_self_register_port_main_screen();
    
}

static void EmMiscDMSelfRegisterPortHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) dm_self_reg_des_port_number, (S8*)mmi_em_get_ucs2_display_buf());

    dm_self_reg_des_port_number[strlen(dm_self_reg_des_port_number)]='\0';

    mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_UPDATE_RSP, (PsIntFuncPtr)EmMisDMUpdateDMSMSRsp, MMI_TRUE);
    EmMisDMUpdateDMSMSReq(1);
}

#endif

#endif /* __MMI_EM_MISC_DM_REGISTER__ */



/*-----------------------------------------------------------------------------*/
/*------------------------------- DM add APN  ---------------------------------*/
/*-----------------------------------------------------------------------------*/

#if defined(__MMI_EM_MISC_DM_ADD_APN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_DM_ADD_APN__ */


#ifdef __MMI_EM_MISC_DCD__

/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_entry
 * DESCRIPTION
 *  entry dcd network param setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_misc_dcd_nw_param_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_EM_MISC_DCD_NW_PARAM))
    {
        mmi_frm_group_close(GRP_ID_EM_MISC_DCD_NW_PARAM);
    }
    root_id = mmi_em_get_root_group();
    mmi_frm_group_create(root_id, GRP_ID_EM_MISC_DCD_NW_PARAM, mmi_em_misc_dcd_nw_param_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_DCD_NW_PARAM, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_misc_dcd_nw_param_enter_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_proc
 * DESCRIPTION
 *  event proc of dcd network param group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_misc_dcd_nw_param_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort_event = NULL;
    cui_event_inline_csk_press_struct *inline_csk_press_event = NULL;
    cui_event_inline_submit_struct *inline_submit_event = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
            inline_csk_press_event = (cui_event_inline_csk_press_struct*)evt;
            mmi_em_misc_dcd_nw_param_save(inline_csk_press_event->sender_id);
            cui_inline_close(inline_csk_press_event->sender_id);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
            inline_submit_event = (cui_event_inline_submit_struct*)evt;
            mmi_em_misc_dcd_nw_param_save(inline_submit_event->sender_id);
            cui_inline_close(inline_submit_event->sender_id);
            break;

        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            if (g_em_dcd_editor_p)
            {
                free_ctrl_buffer(g_em_dcd_editor_p);
                g_em_dcd_editor_p = NULL;
            }
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_enter_main_screen
 * DESCRIPTION
 *  enter main screen of dcd network param group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_misc_dcd_nw_param_enter_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mmi_id inline_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_cui_id = cui_inline_create(GRP_ID_EM_MISC_DCD_NW_PARAM, &nw_param_inline);
    mmi_em_misc_dcd_nw_param_set_inline_cui(inline_cui_id);
    cui_inline_run(inline_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_save
 * DESCRIPTION
 *  save dcd network param
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_misc_dcd_nw_param_set_inline_cui(mmi_id inline_cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    char *p1, *p2;
    U32 val;
    cui_inline_set_item_ip4_struct ip4_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_dcd_editor_p == NULL)
    {
        g_em_dcd_editor_p = (mmi_em_dcd_nw_editor_struct*)get_ctrl_buffer(sizeof(mmi_em_dcd_nw_editor_struct));        
        ASSERT(g_em_dcd_editor_p != NULL);
        memset(g_em_dcd_editor_p, 0, sizeof(mmi_em_dcd_nw_editor_struct));
    }
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->apn, (S8*)g_em_dcd_nw_data_p->apn);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->apn_name, (S8*)g_em_dcd_nw_data_p->apn_name);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->port, (S8*)g_em_dcd_nw_data_p->port);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->add_chan_url, (S8*)g_em_dcd_nw_data_p->add_chan_url);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->del_chan_url, (S8*)g_em_dcd_nw_data_p->del_chan_url);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->refresh_url, (S8*)g_em_dcd_nw_data_p->refresh_url);
    mmi_asc_to_ucs2((S8*)g_em_dcd_editor_p->help_url, (S8*)g_em_dcd_nw_data_p->help_url);
    p1 = (char*)g_em_dcd_nw_data_p->gate_way;
    for (i = 0; i < 4; i++)
    {
        p2 = strchr(p1, '.');
        if (p2)
        {
            mmi_em_misc_dcd_nw_param_string_to_uint(p1, p2 - p1, &val);
            g_em_dcd_editor_p->gateway_ip[i] = (U8)val;
            p1 = p2 + 1;
        } 
        else
        {
            mmi_em_misc_dcd_nw_param_string_to_uint(p1, 3, &val);
            g_em_dcd_editor_p->gateway_ip[i] = (U8)val;
            break;
        }
    }
    ip4_value.b1 = g_em_dcd_editor_p->gateway_ip[0];
    ip4_value.b2 = g_em_dcd_editor_p->gateway_ip[1];
    ip4_value.b3 = g_em_dcd_editor_p->gateway_ip[2];
    ip4_value.b4 = g_em_dcd_editor_p->gateway_ip[3];
    cui_inline_set_value(inline_cui_id, NW_PARAM_APN_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->apn);
    cui_inline_set_value(inline_cui_id, NW_PARAM_GATEWAY_IP4_ID, (void*)&ip4_value);
    cui_inline_set_value(inline_cui_id, NW_PARAM_PORT_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->port);
    cui_inline_set_value(inline_cui_id, NW_PARAM_ADD_CHAN_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->add_chan_url);
    cui_inline_set_value(inline_cui_id, NW_PARAM_DEL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->del_chan_url);
    cui_inline_set_value(inline_cui_id, NW_PARAM_REF_URL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->refresh_url);
    cui_inline_set_value(inline_cui_id, NW_PARAM_HEL_URL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->help_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_save
 * DESCRIPTION
 *  save dcd network param
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_misc_dcd_nw_param_save(mmi_id inline_cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_ip4_struct ip4_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get value from inline cui */
    cui_inline_get_value(inline_cui_id, NW_PARAM_APN_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->apn);
    cui_inline_get_value(inline_cui_id, NW_PARAM_GATEWAY_IP4_ID, (void*)&ip4_value);
    g_em_dcd_editor_p->gateway_ip[0] = ip4_value.b1;
    g_em_dcd_editor_p->gateway_ip[1] = ip4_value.b2;
    g_em_dcd_editor_p->gateway_ip[2] = ip4_value.b3;
    g_em_dcd_editor_p->gateway_ip[3] = ip4_value.b4;
    cui_inline_get_value(inline_cui_id, NW_PARAM_PORT_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->port);
    cui_inline_get_value(inline_cui_id, NW_PARAM_ADD_CHAN_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->add_chan_url);
    cui_inline_get_value(inline_cui_id, NW_PARAM_DEL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->del_chan_url);
    cui_inline_get_value(inline_cui_id, NW_PARAM_REF_URL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->refresh_url);
    cui_inline_get_value(inline_cui_id, NW_PARAM_HEL_URL_TEXTEDIT_ID, (void*)g_em_dcd_editor_p->help_url);

    /* save data */
    memset(g_em_dcd_nw_data_p, 0, sizeof(mmi_em_dcd_nw_data_struct));
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->apn,         (S8*)g_em_dcd_editor_p->apn);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->apn_name,    (S8*)g_em_dcd_editor_p->apn_name);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->port,        (S8*)g_em_dcd_editor_p->port);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->add_chan_url,(S8*)g_em_dcd_editor_p->add_chan_url);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->del_chan_url,(S8*)g_em_dcd_editor_p->del_chan_url);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->refresh_url, (S8*)g_em_dcd_editor_p->refresh_url);
    mmi_ucs2_to_asc((S8*)g_em_dcd_nw_data_p->help_url,    (S8*)g_em_dcd_editor_p->help_url);
    sprintf(
        (char*)g_em_dcd_nw_data_p->gate_way, 
        "%03d.%03d.%03d.%03d", 
        g_em_dcd_editor_p->gateway_ip[0],
        g_em_dcd_editor_p->gateway_ip[1],
        g_em_dcd_editor_p->gateway_ip[2],
        g_em_dcd_editor_p->gateway_ip[3]);
    dcd_custom_em_write_data();
    mmi_em_success_popup();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_nw_param_string_to_uint
 * DESCRIPTION
 *  convert string to u32
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_em_misc_dcd_nw_param_string_to_uint(char *str, U32 str_len, U32 *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *val = 0;
    
    for (idx = 0; idx < str_len; idx++)
    {
        if (str[idx] < '0' || str[idx] > '9')
        {
            return MMI_FALSE;
        }
        *val = *val * 10 + (str[idx] - '0');
    }
    return MMI_TRUE;
}


#ifdef __MMI_OP01_DCD_V30__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_storage_switch_hdlr
 * DESCRIPTION
 *  dcd storage switch hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_misc_dcd_storage_switch_hdlr(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_EM_MISC_ON)
    {
        g_em_dcd_nw_data_p->storage_switch = 1;
    }
    else if (menu_id == MENU_ID_EM_MISC_OFF)
    {
        g_em_dcd_nw_data_p->storage_switch = 0;
    }

    dcd_custom_em_write_data();
    mmi_em_success_popup();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_dcd_get_storage_switch
 * DESCRIPTION
 *  dcd storage switch on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_em_misc_dcd_get_storage_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_em_dcd_nw_data_p->storage_switch;
}
#endif /* __MMI_OP01_DCD_V30__ */



void mmi_em_dm_menu_event_hdlr(cui_menu_event_struct *event)
{
    switch(event->highlighted_menu_id)
    {
    #ifdef __MMI_EM_MISC_DCD__
        case MENU_ID_EM_MISC_DCD_NW_PARAM:
            mmi_em_misc_dcd_nw_param_entry();
            break;
    #endif /* __MMI_EM_MISC_DCD__ */

        default:
            break;
    }
}
#endif /* __MMI_EM_MISC_DCD__ */


#ifdef __MMI_EM_MISC_DM_REGISTER__
U8 * get_highlightIndex()
{
    return &ture_slected;
}
void set_highlightIndex(U8 select_item)
{
    ture_slected = select_item;
}
static void mmi_em_misc_dm_self_register_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER, 
                            SCR_ID_EM_MISC_DM_SELF_REGISTER, 
                            NULL, 
                            mmi_em_misc_dm_self_register_main_screen, 
                            MMI_FRM_FULL_SCRN) == MMI_FALSE)    
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory5Screen(
        STR_ID_EM_MISC_DM_SELF_REGISTER_NUMBER,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        IMM_INPUT_TYPE_NUMERIC_SYMBOL,
        (U8*) mmi_em_get_ucs2_display_buf(),
        NVRAM_EF_DM_SR_NUMBER_SIZE+1,
        guiBuffer);

    SetLeftSoftkeyFunction(EmMiscDMSelfRegisterHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}

static void mmi_em_misc_dm_self_register_main_device_name_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER, 
                            SCR_ID_EM_MISC_DM_SELF_REGISTER, 
                            NULL, 
                            mmi_em_misc_dm_self_register_main_device_name_screen, 
                            MMI_FRM_FULL_SCRN) == MMI_FALSE)    
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory5Screen(
        STR_ID_EM_MISC_DM_SELF_REGISTER_DEVICE_NAME,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        IMM_INPUT_TYPE_ASCII_CHAR,
        (U8*) mmi_em_get_ucs2_display_device_name_buf(),
        DM_SR_DEVICE_MODEL_SIZE+1,
        guiBuffer);

    SetLeftSoftkeyFunction(EmMiscDMSelfRegisterdevicenameHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}

#ifdef __OP02_DM__
static void mmi_em_misc_dm_self_register_port_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_scrn_enter(GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT, 
                            SCR_ID_EM_MISC_DM_SELF_REGISTER_PORT, 
                            NULL, 
                            mmi_em_misc_dm_self_register_port_main_screen, 
                            MMI_FRM_FULL_SCRN) == MMI_FALSE)    
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory5Screen(
        STR_ID_EM_MISC_DM_SELF_REGISTER_PORT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        IMM_INPUT_TYPE_ENGLISH_SENTENCE,
        (U8*) mmi_em_get_ucs2_display_buf(),
        NVRAM_EF_DM_SR_NUMBER_SIZE+1,
        guiBuffer);

    SetLeftSoftkeyFunction(EmMiscDMSelfRegisterPortHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}
#endif


void mmi_em_misc_dm_self_register_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __OP02_DM__
    S16 error;    
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8)dm_self_reg_des_number, 0, sizeof(dm_self_reg_des_number));

#ifdef __OP02_DM__
        mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_READ_RSP, (PsIntFuncPtr)EmMisDMReadDMSMSRsp, MMI_TRUE);
        EmMisDMReadDMSMSReq(0);
#else
    ReadRecord(NVRAM_EF_DM_SR_NUMBER_LID, 1, &dm_self_reg_des_number, NVRAM_EF_DM_SR_NUMBER_SIZE, &error);
    mmi_asc_to_ucs2((S8*)mmi_em_get_ucs2_display_buf(), dm_self_reg_des_number);
    
    EntryEmMisDMSelfRegister();
#endif
    
}


void mmi_em_misc_dm_self_register_device_name_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8)dm_self_reg_des_device_name, 0, sizeof(dm_self_reg_des_device_name));

    ReadRecord(NVRAM_EF_UEM_MANUFACTURE_DATA_LID, 1, &dm_self_reg_manufacture_name, NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE, &error);
    memcpy(dm_self_reg_des_device_name, &dm_self_reg_manufacture_name[30], (sizeof(dm_self_reg_des_device_name) - 1));
    mmi_asc_to_ucs2((S8*)mmi_em_get_ucs2_display_device_name_buf(), dm_self_reg_des_device_name);
    
    EntryEmMisDMSelfRegisterdevicename();
    
}



U8 mmi_em_misc_dm_self_register_get_result(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_self_reg_succuss;
	S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ReadValue(NVRAM_DM_SELF_REGISTER_RESULT, 
              &is_self_reg_succuss, 
			  DS_BYTE, 
			  &error);
    
    if (is_self_reg_succuss != TRUE)
    {
        is_self_reg_succuss = FALSE;
    }
    return is_self_reg_succuss;
}

U8 mmi_em_misc_dm_self_register_get_master_swicth_result(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_self_reg_succuss;
	S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*SKYFYX add the NVRAM*/
	ReadValue(NVRAM_DM_SELF_REGISTER_MASTER_SWITCH, 
              &is_self_reg_succuss, 
			  DS_BYTE, 
			  &error);
    
    if (is_self_reg_succuss != TRUE)
    {
        is_self_reg_succuss = FALSE;
    }
    return is_self_reg_succuss;
}

void mmi_em_misc_dm_self_register_result_select(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;
    U8 *true_selected = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    true_selected = get_highlightIndex();
    
	WriteValue(NVRAM_DM_SELF_REGISTER_RESULT, 
				true_selected, 
				DS_BYTE, 
				&error);
    
    if (error == NVRAM_WRITE_SUCCESS)
    {
    	mmi_em_display_notify_popup(MMI_TRUE);
    }
    else
    {
    	mmi_em_display_notify_popup(MMI_FALSE);
    }
}

void mmi_em_misc_dm_self_register_master_switch_select(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;
    U8 *true_selected = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    true_selected = get_highlightIndex();
    /*SKYFYX add the NVRAM*/
	WriteValue(NVRAM_DM_SELF_REGISTER_MASTER_SWITCH, 
				true_selected, 
				DS_BYTE, 
				&error);

	mmi_em_display_notify_popup(error == NVRAM_WRITE_SUCCESS);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__*/
#endif /*__MMI_EM_MISC_DM_REGISTER__*/


#endif /* __MMI_ENGINEER_MODE__ */
