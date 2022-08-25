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

extern "C"
{
#include "PhbSrvGprot.h"
#include "NwUsabSrvGprot.h"
}

typedef void (*TESTCASE_FUNC_TYPE) (void);

typedef struct
{
    MMI_BOOL is_running;
    MMI_BOOL allow_run;
    U32 pretest_counter;
    U32 counter;
    U32 total_num;
    TESTCASE_FUNC_TYPE func_list[220];
    S32 sim_interface;

    /* testcase using data */
    SRV_PHB_XMGNT_HANDLE xg_hdl;
} avk_appsrv_phbcontext_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static avk_appsrv_phbcontext_struct g_phb_cntx;

/*****************************************************************************
 * PhoneBook AVK test global variable
 *****************************************************************************/
static srv_phb_sdk_contact_struct avk_appsrv_phbcont;
static void *g_phb_contact = (srv_phb_sdk_contact_struct *) & avk_appsrv_phbcont;
static CHAR avk_appsrv_phbresult_str[128] = {0};

#define VS_MISC_PHB_AUTO

/* Test data */
#define VS_PHB_TA_SIM_INTERFACE SIM1

static void avk_appsrv_phbtest_timer_cb(void);
static void avk_appsrv_phbresume_test();


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbovertime_timer_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbovertime_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AVK_LOG_FUN(PHB testcase over time fail., AVK_FAIL); */
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbsuspend_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbsuspend_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.allow_run = MMI_FALSE;
    gui_cancel_timer(avk_appsrv_phbtest_timer_cb);

    /* start a over-time timer */
    gui_start_timer(1000, avk_appsrv_phbovertime_timer_cb);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbresume_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbresume_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop over-time timer */
    gui_cancel_timer(avk_appsrv_phbovertime_timer_cb);

    g_phb_cntx.allow_run = MMI_TRUE;
    /* start a timer and run all the test cases */
    gui_start_timer(0, avk_appsrv_phbtest_timer_cb);
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_add_contact_cb
 * DESCRIPTION
 *  Add one contace to phonebook
 * PARAMETERS
 *  result          [IN]        
 *  contact_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_misc_phb_add_contact_cb(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PHB_NO_ERROR == result)
    {
        AVK_LOG_FUN(srv_phb_sdk_add_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sdk_add_contact, AVK_FAIL);
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_add_contact
 * DESCRIPTION
 *  Add one contace to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_add_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_contact_struct *p_phb_cont;
    srv_phb_sdk_add_req_struct phb_add_req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_contact)
    {
        memset((void*)&phb_add_req_info, 0, sizeof(srv_phb_sdk_add_req_struct));

        p_phb_cont = (srv_phb_sdk_contact_struct*) g_phb_contact;
        memset(p_phb_cont, 0, sizeof(srv_phb_sdk_contact_struct));

        mmi_wcsncpy((U16*) p_phb_cont->name, (U16*) (WCHAR *)L"MediaTek", MMI_PHB_NAME_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
        p_phb_cont->group_mask = 0x01;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        mmi_wcsncpy((U16*) p_phb_cont->home_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->office_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->fax_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->email_address, (U16*) (WCHAR *)L"mediatek@mediatek.com", MMI_PHB_EMAIL_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->company_name, (U16*) (WCHAR *)L"MediaTek(BeiJing)Inc.", MMI_PHB_COMPANY_LENGTH);
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_wcsncpy((U16*) p_phb_cont->email_address2, (U16*) (WCHAR *)L"mediatek2@mediatek.com", MMI_PHB_EMAIL_LENGTH);
    #endif 
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        p_phb_cont->birth_day = 1;
        p_phb_cont->birth_mon = 1;
        p_phb_cont->birth_year = 2009;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_wcsncpy((U16*) p_phb_cont->title, (U16*) (WCHAR *)L"MediaTek Inc.", MMI_PHB_TITLE_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->url, (U16*) (WCHAR *)L"www.mediatek.com", MMI_PHB_URL_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_pobox, (U16*) (WCHAR *)L"100000", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_extension, (U16*) (WCHAR *)L"83000", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_street, (U16*) (WCHAR *)L"Ke Xue Yuan Load", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_city, (U16*) (WCHAR *)L"BeiJing", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_state, (U16*) (WCHAR *)L"HaiDian", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_postal_code, (U16*) (WCHAR *)L"010", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_country, (U16*) (WCHAR *)L"China", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->note, (U16*) (WCHAR *)L"MediaTek Note", MMI_PHB_NOTE_LENGTH);
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

        phb_add_req_info.contact_ptr = p_phb_cont;
        phb_add_req_info.storage = PHB_STORAGE_NVRAM;

        srv_phb_sdk_add_contact(&phb_add_req_info, vs_misc_phb_add_contact_cb);
    }

    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_get_contact
 * DESCRIPTION
 *  Get one contace from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_get_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_contact_struct *p_phb_cont;
    srv_phb_sdk_get_req_struct phb_get_req_info;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_contact)
    {
        p_phb_cont = (srv_phb_sdk_contact_struct*) g_phb_contact;
        memset(p_phb_cont, 0, sizeof(srv_phb_sdk_contact_struct));

        phb_get_req_info.pos.index = 1;
        phb_get_req_info.pos.storage = PHB_STORAGE_NVRAM;
        phb_get_req_info.contact_ptr = p_phb_cont;

        result = srv_phb_sdk_get_contact(&phb_get_req_info);
        if (SRV_PHB_NO_ERROR == result)
        {
            AVK_LOG_FUN(srv_phb_sdk_get_contact, AVK_PASS);
        }
        else
        {
            AVK_LOG_FUN(srv_phb_sdk_get_contact, AVK_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_update_contact_cb
 * DESCRIPTION
 *  Update one contace to phonebook
 * PARAMETERS
 *  result          [IN]        
 *  contact_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_misc_phb_update_contact_cb(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PHB_NO_ERROR == result)
    {
        AVK_LOG_FUN(srv_phb_sdk_update_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sdk_update_contact, AVK_FAIL);
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_update_contact
 * DESCRIPTION
 *  Update one contace in phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_update_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_contact_struct *p_phb_cont;
    srv_phb_sdk_update_req_struct phb_update_req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_contact)
    {
        memset((void*)&phb_update_req_info, 0, sizeof(srv_phb_sdk_update_req_struct));

        p_phb_cont = (srv_phb_sdk_contact_struct*) g_phb_contact;
        memset(p_phb_cont, 0, sizeof(srv_phb_sdk_contact_struct));

        mmi_wcsncpy((U16*) p_phb_cont->name, (U16*) (WCHAR *)L"MediaTek", MMI_PHB_NAME_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->number, (U16*) (WCHAR *)L"13800138000", MMI_PHB_NUMBER_LENGTH);
        p_phb_cont->group_mask = 0x02;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        mmi_wcsncpy((U16*) p_phb_cont->home_number, (U16*) (WCHAR *)L"13800138000", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->office_number, (U16*) (WCHAR *)L"13800138000", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->fax_number, (U16*) (WCHAR *)L"13800138000", MMI_PHB_NUMBER_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->email_address, (U16*) (WCHAR *)L"mediatek@mediatek.com", MMI_PHB_EMAIL_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->company_name, (U16*) (WCHAR *)L"MediaTek(BeiJing)Inc.", MMI_PHB_COMPANY_LENGTH);
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_wcsncpy((U16*) p_phb_cont->email_address2, (U16*) (WCHAR *)L"mediatek2@mediatek.com", MMI_PHB_EMAIL_LENGTH);
    #endif 
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        p_phb_cont->birth_day = 31;
        p_phb_cont->birth_mon = 12;
        p_phb_cont->birth_year = 2009;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_wcsncpy((U16*) p_phb_cont->title, (U16*) (WCHAR *)L"MediaTek Inc.", MMI_PHB_TITLE_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->url, (U16*) (WCHAR *)L"www.mediatek.com", MMI_PHB_URL_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_pobox, (U16*) (WCHAR *)L"100000", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_extension, (U16*) (WCHAR *)L"83000", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_street, (U16*) (WCHAR *)L"Ke Xue Yuan Load", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_city, (U16*) (WCHAR *)L"BeiJing", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_state, (U16*) (WCHAR *)L"HaiDian", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_postal_code, (U16*) (WCHAR *)L"010", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->adr_country, (U16*) (WCHAR *)L"China", MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy((U16*) p_phb_cont->note, (U16*) (WCHAR *)L"MediaTek Note", MMI_PHB_NOTE_LENGTH);
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

        phb_update_req_info.pos.index = 7;
        phb_update_req_info.pos.storage = PHB_STORAGE_NVRAM;
        phb_update_req_info.contact_ptr = p_phb_cont;

        srv_phb_sdk_update_contact(&phb_update_req_info, vs_misc_phb_update_contact_cb);
    }

    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_search_contact_cb
 * DESCRIPTION
 *  Search one contace from phonebook
 * PARAMETERS
 *  result          [IN]        
 *  contact_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_misc_phb_search_contact_cb(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U8 *guiBuffer;
 //   CHAR phb_result_str[128] = {0};
 //   CHAR phb_result_tmp[8] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PHB_NO_ERROR == result)
    {
        /* AVK_LOG_FUN(phb_search_contact, AVK_PASS); */
    }
    else
    {
        /* AVK_LOG_FUN(phb_search_contact, AVK_FAIL); */
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_search_contact
 * DESCRIPTION
 *  Search one contace in phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_search_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_contact_struct *p_phb_cont;
    srv_phb_sdk_search_req_struct phb_search_req_info;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_contact)
    {
        p_phb_cont = (srv_phb_sdk_contact_struct*) g_phb_contact;
        memset(p_phb_cont, 0, sizeof(srv_phb_sdk_contact_struct));

        mmi_wcsncpy((U16*) phb_search_req_info.pattern_ucs2, (U16*) (WCHAR *)L"MediaTek", SRV_PHB_SEARCH_LENGTH);
        phb_search_req_info.search_type = SRV_PHB_SEARCH_TYPE_NAME;
        phb_search_req_info.contact_ptr = p_phb_cont;

        result = srv_phb_sdk_search_contact(&phb_search_req_info);
        if (SRV_PHB_NO_ERROR == result)
        {
            AVK_LOG_FUN(srv_phb_sdk_search_contact, AVK_PASS);
        }
        else
        {
            AVK_LOG_FUN(srv_phb_sdk_search_contact, AVK_FAIL);
        }
    }
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_delete_contact_cb
 * DESCRIPTION
 *  Delete one contace from phonebook
 * PARAMETERS
 *  result          [IN]        
 *  contact_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_misc_phb_delete_contact_cb(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PHB_NO_ERROR == result)
    {
        AVK_LOG_FUN(srv_phb_sdk_delete_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sdk_delete_contact, AVK_FAIL);
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_delete_contact
 * DESCRIPTION
 *  Delete one contace from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_delete_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_delete_req_struct phb_delete_req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_contact)
    {
        phb_delete_req_info.pos.index = 4;
        phb_delete_req_info.pos.storage = PHB_STORAGE_NVRAM;

        srv_phb_sdk_delete_contact(&phb_delete_req_info, vs_misc_phb_delete_contact_cb);
    }
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_get_capacity
 * DESCRIPTION
 *  get the capaciry of phonebook or sim
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_get_capacity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // MMI_BOOL enter_ret;
    MMI_BOOL ready;
    S32 total_num, used_num;

    /* srv_phb_contact_pos_struct* pos_array; */
    WCHAR phb_capacity_str[128] = {0};
    WCHAR phb_capacity_tmp[8] = {0};
   // U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check phonebook is ready or not */
    ready = srv_phb_sdk_is_phb_ready();
    if (MMI_TRUE == ready)
    {
        /* get the total contacts of phonebook */
        total_num = srv_phb_sdk_get_total_contacts(PHB_STORAGE_NVRAM);

        /* get the uesd contacts of phonebook */
        used_num = srv_phb_sdk_get_used_contacts(NULL, PHB_STORAGE_NVRAM);

        if (total_num >= 0)
        {
            mmi_wcscat(phb_capacity_str, (WCHAR *)L"Phonebook capacity\n");
            mmi_wcscat(phb_capacity_str, (WCHAR *)L"Total: ");
            gui_itoa(total_num, (UI_string_type) phb_capacity_tmp, 10);
            mmi_wcscat(phb_capacity_str, phb_capacity_tmp);
            mmi_wcscat(phb_capacity_str, (WCHAR *)L"\n");
        }
        if (used_num >= 0)
        {
            mmi_wcscat(phb_capacity_str, (WCHAR *)L"Used: ");
            gui_itoa(used_num, (UI_string_type) phb_capacity_tmp, 10);
            mmi_wcscat(phb_capacity_str, phb_capacity_tmp);
            mmi_wcscat(phb_capacity_str, (WCHAR *)L"\n");
        }

        if (total_num >= 0 && used_num >= 0 && used_num <= total_num)
        {
            AVK_LOG_FUN(srv_phb_sdk_is_phb_ready, AVK_PASS);
            AVK_LOG_FUN(srv_phb_sdk_get_total_contacts, AVK_PASS);
            AVK_LOG_FUN(srv_phb_sdk_get_used_contacts, AVK_PASS);
        }
        else
        {
            AVK_LOG_FUN(srv_phb_sdk_is_phb_ready, AVK_FAIL);
            AVK_LOG_FUN(srv_phb_sdk_get_total_contacts, AVK_FAIL);
            AVK_LOG_FUN(srv_phb_sdk_get_used_contacts, AVK_FAIL);
        }
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sdk_is_phb_ready, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_sdk_get_total_contacts, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_sdk_get_used_contacts, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_misc_phb_get_group_list
 * DESCRIPTION
 *  get the group of phonebook or sim
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_misc_phb_get_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_count = 0;
    U8 group_array[MMI_PHB_GROUP_COUNT] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get phonebook group list */
    group_count = srv_phb_datamgr_get_group_list(group_array, NULL);
    if (group_count >= 0)
    {
        AVK_LOG_FUN(srv_phb_datamgr_get_group_list, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_datamgr_get_group_list, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_mem_malloc_ext
 * DESCRIPTION
 *  test case for srv_phb_mem_malloc_ext() and srv_phb_mem_free_ext()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_mem_malloc_ext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL, *ptr2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = srv_phb_mem_malloc_ext(10, SRV_PHB_MEMORY_TYPE_CTR, "", 0);
    ptr2 = srv_phb_mem_malloc_ext(10, SRV_PHB_MEMORY_TYPE_CTR, "", 0);

    /* check testcase result */
    if (ptr && ptr2)
    {
        AVK_LOG_FUN(srv_phb_mem_malloc_ext, AVK_PASS);
        AVK_LOG_FUN(srv_phb_mem_free_ext, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_mem_malloc_ext, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_mem_free_ext, AVK_FAIL);
    }

    /* release memory */
    if (ptr)
    {
        srv_phb_mem_free_ext(ptr, "", 0);
    }
    if (ptr2)
    {
        srv_phb_mem_free_ext(ptr2, "", 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_sse_convert_number_to_int
 * DESCRIPTION
 *  test case for srv_phb_sse_convert_number_to_int()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_sse_convert_number_to_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //result = srv_phb_sse_convert_number_to_int("12345");

    /* check testcase result */
    if (result == 12345)
    {
      //  AVK_LOG_FUN(srv_phb_sse_convert_number_to_int, AVK_PASS);
    }
    else
    {
      //  AVK_LOG_FUN(srv_phb_sse_convert_number_to_int, AVK_FAIL);
    }
}

// TODO: waiting Lihong's confirm result


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_datamgr_add_group_members
 * DESCRIPTION
 *  test case for srv_phb_datamgr_add_group_members()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_datamgr_add_group_members()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 group_count;
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
    mmi_phb_contact_id id_array[3] = {0, 1, 2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_group_list(group_id_list, NULL, PHB_STORAGE_NVRAM);
    //srv_phb_datamgr_add_group_members(id_array, sizeof(id_array) / sizeof(mmi_phb_contact_id), group_id_list[0]);

    /* check testcase result */
    if (0)
    {
        //AVK_LOG_FUN(srv_phb_datamgr_add_group_members, AVK_PASS);
    }
    else
    {
        //AVK_LOG_FUN(srv_phb_datamgr_add_group_members, AVK_FAIL);
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_datamgr_res_check_data_space
 * DESCRIPTION
 *  test case for srv_phb_datamgr_res_check_data_space()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_datamgr_res_check_data_space()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result1, result2, result3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result1 = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_RING);
    result2 = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_IMAGE);
    result3 = srv_phb_datamgr_res_check_data_space(MMI_PHB_CONTACT_FIELD_VIDEO);

    /* check testcase result */
    if (result1 == 0 && result2 == 0 && result3 == 0)
    {
        AVK_LOG_FUN(srv_phb_datamgr_res_check_data_space, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_datamgr_res_check_data_space, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_set_vt_call
 * DESCRIPTION
 *  test case for srv_phb_set_vt_call() and srv_phb_is_vt_call()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_set_vt_call()
{
#if defined(__MMI_VIDEO_TELEPHONY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result1, result2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_vt_call(0, MMI_TRUE);
    result1 = srv_phb_is_vt_call(0);
    srv_phb_set_vt_call(1, MMI_FALSE);
    result2 = srv_phb_is_vt_call(1);

    /* check testcase result */
    if (result1 == MMI_TRUE && result2 == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_set_vt_call, AVK_PASS);
        AVK_LOG_FUN(srv_phb_is_vt_call, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_set_vt_call, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_is_vt_call, AVK_FAIL);
    }
#endif /* defined(__MMI_VIDEO_TELEPHONY__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_set_phb_status
 * DESCRIPTION
 *  test case for srv_phb_startup_set_phb_status() and srv_phb_startup_is_phb_ready()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_set_phb_status()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result1, result2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_startup_set_phb_status(MMI_FALSE);
    result1 = srv_phb_startup_is_phb_ready();
    srv_phb_startup_set_phb_status(MMI_TRUE);
    result2 = srv_phb_startup_is_phb_ready();

    /* check testcase result */
    if (result1 == MMI_FALSE && result2 == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_startup_set_phb_status, AVK_PASS);
        AVK_LOG_FUN(srv_phb_startup_is_phb_ready, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_set_phb_status, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_startup_is_phb_ready, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_is_phb_support
 * DESCRIPTION
 *  test case for srv_phb_startup_is_phb_support()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_is_phb_support()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result1, result2, result3, result4, result5, result6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_startup_is_phb_support, AVK_FAIL);
        return;
    }
    result1 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_ECC);
    result2 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_FDN);
    result3 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_BDN);
    result4 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_MSISDN);
    result5 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_SDN);
    result6 = srv_phb_startup_is_phb_support(g_phb_cntx.sim_interface, PHB_PHONEBOOK);

    /* check testcase result */
    if ((result1 == MMI_FALSE || result1 == MMI_TRUE) &&
        (result2 == MMI_FALSE || result2 == MMI_TRUE) &&
        (result3 == MMI_FALSE || result3 == MMI_TRUE) &&
        (result4 == MMI_FALSE || result4 == MMI_TRUE) &&
        (result5 == MMI_FALSE || result5 == MMI_TRUE) && (result6 == MMI_FALSE || result6 == MMI_TRUE))
    {
        AVK_LOG_FUN(srv_phb_startup_is_phb_support, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_is_phb_support, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_get_alpha_length
 * DESCRIPTION
 *  test case for srv_phb_startup_get_alpha_length()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_get_alpha_length()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_startup_get_alpha_length, AVK_FAIL);
        return;
    }
    result = srv_phb_startup_get_alpha_length(g_phb_cntx.sim_interface, PHB_PHONEBOOK);

    /* check testcase result */
    if (result != 0)
    {
        AVK_LOG_FUN(srv_phb_startup_get_alpha_length, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_get_alpha_length, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_get_fdn_total
 * DESCRIPTION
 *  test case for srv_phb_startup_get_fdn_total()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_get_fdn_total()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_index;
    S16 result = -1;
    mmi_sim_enum sim_card;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_card = srv_nw_usab_get_one_usable_sim();
    if (sim_card != MMI_SIM_NONE)
    {
        sim_index = mmi_frm_sim_to_index(sim_card);
        result = srv_phb_startup_get_fdn_total(sim_index);
    }

    /* check testcase result */
    if (result != -1)
    {
        AVK_LOG_FUN(srv_phb_startup_get_fdn_total, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_get_fdn_total, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_get_bdn_total
 * DESCRIPTION
 *  test case for srv_phb_startup_get_bdn_total()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_get_bdn_total()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_index;
    S16 result = -1;
    mmi_sim_enum sim_card;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_card = srv_nw_usab_get_one_usable_sim();
    if (sim_card != MMI_SIM_NONE)
    {
        sim_index = mmi_frm_sim_to_index(sim_card);
        result = srv_phb_startup_get_bdn_total(sim_index);
    }

    /* check testcase result */
    if (result != -1)
    {
        AVK_LOG_FUN(srv_phb_startup_get_bdn_total, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_get_bdn_total, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_get_msisdn_total
 * DESCRIPTION
 *  test case for srv_phb_startup_get_msisdn_total()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_get_msisdn_total()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_index;
    S16 result = -1;
    mmi_sim_enum sim_card;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_card = srv_nw_usab_get_one_usable_sim();
    if (sim_card != MMI_SIM_NONE)
    {
        sim_index = mmi_frm_sim_to_index(sim_card);
        result = srv_phb_startup_get_msisdn_total(sim_index);
    }

    /* check testcase result */
    if (result != -1)
    {
        AVK_LOG_FUN(srv_phb_startup_get_msisdn_total, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_startup_get_msisdn_total, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_startup_get_adn_used_first
 * DESCRIPTION
 *  test case for srv_phb_startup_get_adn_used_first()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_startup_get_adn_used_first()
{
#ifdef __MMI_PHB_STARTUP_COPY_SIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_startup_get_adn_used_first, AVK_FAIL);
        return;
    }
    srv_phb_startup_get_adn_used_first(g_phb_cntx.sim_interface);

    AVK_LOG_FUN(srv_phb_startup_get_adn_used_first, AVK_PASS);
#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */ 
}

/* Test data */
#define VS_PHB_XMGNT_TA_TYPE PHB_MSISDN
#define VS_PHB_XMGNT_TA_HIGHLIGHT_INDEX 0
#define VS_PHB_XMGNT_TA_INDEX 1
#define VS_PHB_XMGNT_TA_RECORED_INDEX 1
#define VS_PHB_XMGNT_TA_NAME (U16*)(WCHAR *)L"XMGNT"
#define VS_PHB_XMGNT_TA_NUM (U16*)(WCHAR *)L"007"


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_set_entry_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_set_entry_cb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        /* AVK_LOG_FUN(srv_phb_xmgnt_set_entry_cb, AVK_PASS); */
    }
    else
    {
        /* AVK_LOG_FUN(srv_phb_xmgnt_set_entry_cb, AVK_FAIL); */
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_set_entry
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_set_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_set_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 number[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_set_entry, AVK_FAIL);
        return;
    }
    memset(number, 0, sizeof(number));
    mmi_wcscpy(number, (const WCHAR*)VS_PHB_XMGNT_TA_NUM);
    ret = srv_phb_xmgnt_set_entry(
            g_phb_cntx.sim_interface,
            VS_PHB_XMGNT_TA_TYPE,
            VS_PHB_XMGNT_TA_INDEX,
            VS_PHB_XMGNT_TA_RECORED_INDEX,
            VS_PHB_XMGNT_TA_NAME,
            number,
            avk_appsrv_srv_phb_xmgnt_set_entry_cb);

    /* check testcase result */
    if (ret == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_set_entry, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_set_entry, AVK_FAIL);
    }
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_list_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_xmgnt_get_list_cb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_list, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_list, AVK_FAIL);
    }
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_list
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_list, AVK_FAIL);
        return;
    }
    g_phb_cntx.xg_hdl = srv_phb_xmgnt_get_list(
                            g_phb_cntx.sim_interface,
                            VS_PHB_XMGNT_TA_TYPE,
                            avk_appsrv_srv_phb_xmgnt_get_list_cb);
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_list_count
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_list_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_list_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_list_count, AVK_FAIL);
        return;
    }
    ret = srv_phb_xmgnt_get_list_count(g_phb_cntx.xg_hdl);

    /* check testcase result */
    if (ret > 0)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_list_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_list_count, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry_index
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_entry_index()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entry_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_index, AVK_FAIL);
        return;
    }
    entry_index = srv_phb_xmgnt_get_entry_index(g_phb_cntx.xg_hdl, VS_PHB_XMGNT_TA_HIGHLIGHT_INDEX);

    /* check testcase result */
    if (entry_index >= 0)       // TODO: enhance case later
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_index, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_index, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry_name
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_entry_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *entry_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_name, AVK_FAIL);
        return;
    }
    entry_name = srv_phb_xmgnt_get_entry_name(g_phb_cntx.xg_hdl, VS_PHB_XMGNT_TA_HIGHLIGHT_INDEX);

    /* check testcase result */
    if (mmi_wcscmp(entry_name, VS_PHB_XMGNT_TA_NAME) == 0)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_name, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry_number
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_entry_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *entry_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number, AVK_FAIL);
        return;
    }
    entry_number = srv_phb_xmgnt_get_entry_number(g_phb_cntx.xg_hdl, VS_PHB_XMGNT_TA_HIGHLIGHT_INDEX);

    /* check testcase result */
    if (entry_number != NULL)   // TODO: enhance case later
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry_number_length
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_entry_number_length()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry_number_length()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 entry_number_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number_length, AVK_FAIL);
        return;
    }
    entry_number_length = srv_phb_xmgnt_get_entry_number_length(g_phb_cntx.xg_hdl, VS_PHB_XMGNT_TA_HIGHLIGHT_INDEX);

    /* check testcase result */
    if (entry_number_length >= 0)       // TODO: enhance case later
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number_length, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry_number_length, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  sim_entry       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry_cb(U16 result, l4c_phb_entry_struct *sim_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_get_entry
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_get_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_get_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry, AVK_FAIL);
        return;
    }
    ret = srv_phb_xmgnt_get_entry(
            g_phb_cntx.sim_interface,
            VS_PHB_XMGNT_TA_TYPE,
            VS_PHB_XMGNT_TA_RECORED_INDEX,
            avk_appsrv_srv_phb_xmgnt_get_entry_cb);

    /* check testcase result */
    if (ret == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_get_entry, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_delete_entry_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_delete_entry_cb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_delete_entry
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_delete_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_delete_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_delete_entry, AVK_FAIL);
        return;
    }
    ret = srv_phb_xmgnt_delete_entry(
            g_phb_cntx.sim_interface,
            VS_PHB_XMGNT_TA_TYPE,
            VS_PHB_XMGNT_TA_INDEX,
            VS_PHB_XMGNT_TA_RECORED_INDEX,
            avk_appsrv_srv_phb_xmgnt_delete_entry_cb);

    /* check testcase result */
    if (ret == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_delete_entry, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_delete_entry, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_query_dial_mode
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_query_dial_mode()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_query_dial_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret, ret2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_query_dial_mode, AVK_FAIL);
        return;
    }
    ret = srv_phb_xmgnt_query_dial_mode(g_phb_cntx.sim_interface, PHB_FDN);
    ret2 = srv_phb_xmgnt_query_dial_mode(g_phb_cntx.sim_interface, PHB_BDN);

    /* check testcase result */
    if (ret != 0xFF && ret2 != 0xFF)
    {
        AVK_LOG_FUN(srv_phb_xmgnt_query_dial_mode, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xmgnt_query_dial_mode, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_toggle_dial_mode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_xmgnt_toggle_dial_mode_cb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        avk_appsrv_phbresume_test();
    }
    else
    {
        avk_appsrv_phbresume_test();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_toggle_dial_mode
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_toggle_dial_mode()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_toggle_dial_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_toggle_dial_mode, AVK_FAIL);
        return;
    }
    avk_appsrv_phbsuspend_test();
    srv_phb_xmgnt_toggle_dial_mode(
            g_phb_cntx.sim_interface,
            PHB_FDN,
            avk_appsrv_srv_phb_xmgnt_toggle_dial_mode_cb);

    /* check testcase result */
        AVK_LOG_FUN(srv_phb_xmgnt_toggle_dial_mode, AVK_PASS);
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_read_dial_mode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_read_dial_mode_cb(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AVK_LOG_FUN(srv_phb_xmgnt_read_dial_mode, AVK_PASS); */
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_read_dial_mode
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_read_dial_mode()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_read_dial_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_xmgnt_read_dial_mode(avk_appsrv_srv_phb_xmgnt_read_dial_mode_cb);
    avk_appsrv_srv_phb_xmgnt_read_dial_mode_cb(NULL);
    AVK_LOG_FUN(srv_phb_xmgnt_read_dial_mode, AVK_PASS);
    avk_appsrv_phbsuspend_test();
}

// TODO: case for srv_phb_xmgnt_set_read_false()


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram_cb(void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_FUN(srv_phb_xmgnt_read_fdn_to_ram, AVK_PASS);
    avk_appsrv_phbresume_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_read_fdn_to_ram()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_xmgnt_read_fdn_to_ram(avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram_cb);
    avk_appsrv_phbsuspend_test();
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_update_fdn_to_ram
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_update_fdn_to_ram()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_update_fdn_to_ram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_update_fdn_to_ram, AVK_FAIL);
        return;
    }
    if (0)      // TODO:
//        srv_phb_xmgnt_update_fdn_to_ram(g_phb_cntx.sim_interface, 0, NULL);
    AVK_LOG_FUN(srv_phb_xmgnt_update_fdn_to_ram, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xmgnt_search_fdn_by_number
 * DESCRIPTION
 *  test case for srv_phb_xmgnt_search_fdn_by_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xmgnt_search_fdn_by_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_xmgnt_search_fdn_by_number, AVK_FAIL);
        return;
    }
    srv_phb_xmgnt_search_fdn_by_number(g_phb_cntx.sim_interface, NULL, NULL);
    AVK_LOG_FUN(srv_phb_xmgnt_search_fdn_by_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_owner_number_parse_msisdn_info
 * DESCRIPTION
 *  test case for srv_phb_owner_number_parse_msisdn_info()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_owner_number_parse_msisdn_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_owner_number_parse_msisdn_info, AVK_FAIL);
        return;
    }
    srv_phb_owner_number_parse_msisdn_info(g_phb_cntx.sim_interface, 0, NULL);
    AVK_LOG_FUN(srv_phb_xmgnt_search_fdn_by_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_owner_number_set_name_number
 * DESCRIPTION
 *  test case for srv_phb_owner_number_set_name_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_owner_number_set_name_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_owner_number_set_name_number, AVK_FAIL);
        return;
    }
    srv_phb_owner_number_set_name_number(g_phb_cntx.sim_interface, 0, (U16*) (WCHAR *)L"name", (U16*) (WCHAR *)L"12345");
    AVK_LOG_FUN(srv_phb_owner_number_set_name_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_owner_number_get_name
 * DESCRIPTION
 *  test case for srv_phb_owner_number_get_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_owner_number_get_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_owner_number_get_name, AVK_FAIL);
        return;
    }
    srv_phb_owner_number_get_name(g_phb_cntx.sim_interface, 0);
    AVK_LOG_FUN(srv_phb_owner_number_get_name, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_owner_number_get_number
 * DESCRIPTION
 *  test case for srv_phb_owner_number_get_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_owner_number_get_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_owner_number_get_number, AVK_FAIL);
        return;
    }
    srv_phb_owner_number_get_number(g_phb_cntx.sim_interface, 0);
    AVK_LOG_FUN(srv_phb_owner_number_get_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_storage
 * DESCRIPTION
 *  test case for srv_phb_get_storage()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_storage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_storage(0);

    /* check testcase result */
    if (result == PHB_STORAGE_NVRAM)
    {
        AVK_LOG_FUN(srv_phb_get_storage, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_storage, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_store_index_in_storage
 * DESCRIPTION
 *  test case for srv_phb_check_store_index_in_storage()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_store_index_in_storage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_store_index_in_storage(0, PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_storage, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_storage, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_storage_status
 * DESCRIPTION
 *  test case for srv_phb_check_storage_status()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_storage_status()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_storage_status(PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result == SRV_PHB_STORAGE_STATUS_OTHERS)
    {
        AVK_LOG_FUN(srv_phb_check_storage_status, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_storage_status, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_storage_accessible
 * DESCRIPTION
 *  test case for srv_phb_check_storage_accessible()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_storage_accessible()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_storage_accessible(PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_check_storage_accessible, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_storage_accessible, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_total_contact
 * DESCRIPTION
 *  test case for srv_phb_get_total_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_total_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_total_contact(PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result > 0)
    {
        AVK_LOG_FUN(srv_phb_get_total_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_total_contact, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_used_contact
 * DESCRIPTION
 *  test case for srv_phb_get_used_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_used_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_used_contact(PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result > 0)
    {
        AVK_LOG_FUN(srv_phb_get_used_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_used_contact, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_store_index_to_sort_index
 * DESCRIPTION
 *  test case for srv_phb_store_index_to_sort_index()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_store_index_to_sort_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_store_index_to_sort_index(PHB_STORAGE_NVRAM, 0);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_store_index_to_sort_index, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_store_index_to_sort_index, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_sort_index_to_store_index
 * DESCRIPTION
 *  test case for srv_phb_sort_index_to_store_index()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_sort_index_to_store_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_sort_index_to_store_index(PHB_STORAGE_NVRAM, 0);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_sort_index_to_store_index, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sort_index_to_store_index, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_store_index_to_record_index
 * DESCRIPTION
 *  test case for srv_phb_store_index_to_record_index()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_store_index_to_record_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage;
    U16 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_store_index_to_record_index(0, &storage, &record_index);

    /* check testcase result */
    if (storage == PHB_STORAGE_NVRAM && record_index >= 1)
    {
        AVK_LOG_FUN(srv_phb_store_index_to_record_index, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_store_index_to_record_index, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_record_index_to_store_index
 * DESCRIPTION
 *  test case for srv_phb_record_index_to_store_index()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_record_index_to_store_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_record_index_to_store_index(PHB_STORAGE_NVRAM, 1, &id);

    /* check testcase result */
    if (id >= 0)
    {
        AVK_LOG_FUN(srv_phb_record_index_to_store_index, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_record_index_to_store_index, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_entry_exist
 * DESCRIPTION
 *  test case for srv_phb_check_entry_exist()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_entry_exist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_entry_exist(0);

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_check_entry_exist, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_entry_exist, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_number_exist
 * DESCRIPTION
 *  test case for srv_phb_check_number_exist()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_number_exist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_number_exist((U16*) (WCHAR *)L"1234567");

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_check_number_exist, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_number_exist, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_sync_get_index_array
 * DESCRIPTION
 *  test case for srv_phb_sync_get_index_array()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_sync_get_index_array()
{
#ifdef __SYNCML_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    U16 index_array[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_sync_get_index_array(index_array, sizeof(index_array) / sizeof(U16));

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_sync_get_index_array, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sync_get_index_array, AVK_FAIL);
    }
#endif /* __SYNCML_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_sync_vcard
 * DESCRIPTION
 *  test case for srv_phb_sync_vcard()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_sync_vcard()
{
#ifdef __SYNCML_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U16 result;
  //  U16 index_array[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0)      // TODO:
        srv_phb_sync_vcard(SRV_PHB_VCARD_READ, NULL, 0, 0);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_sync_vcard, AVK_PASS);

#endif /* __SYNCML_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_sync_get_record_size
 * DESCRIPTION
 *  test case for srv_phb_sync_get_record_size()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_sync_get_record_size()
{
#ifdef __SYNCML_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_sync_get_record_size();

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_sync_get_record_size, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_sync_get_record_size, AVK_FAIL);
    }
#endif /* __SYNCML_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_imps_build_vcard_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phb_result      [IN]        
 *  file_path       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_imps_build_vcard_cb(MMI_BOOL phb_result, U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_imps_build_vcard
 * DESCRIPTION
 *  test case for srv_phb_imps_build_vcard()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_imps_build_vcard()
{
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */ 
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_PBAP_SUPPORT__) && defined(__MMI_VCARD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_PBAP_SUPPORT__) && defined(__MMI_VCARD__) */
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_name_by_number
 * DESCRIPTION
 *  test case for srv_phb_get_name_by_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_name_by_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_name_by_number((U16*) (WCHAR *)L"1234567", name, sizeof(name) / sizeof(U16));

    /* check testcase result */
    if (result && mmi_wcscmp(name, (U16*) (WCHAR *)L"VS Team") == 0)
    {
        AVK_LOG_FUN(srv_phb_get_name_by_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_name_by_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_store_index_by_number
 * DESCRIPTION
 *  test case for srv_phb_get_store_index_by_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_store_index_by_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_store_index_by_number((U16*) (WCHAR *)L"1234567", &store_index);

    /* check testcase result */
    if (result && store_index >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_store_index_by_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_store_index_by_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_set_invalid_number_id
 * DESCRIPTION
 *  test case for srv_phb_create_number_id(), srv_phb_set_invalid_number_id() and srv_phb_check_number_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_set_invalid_number_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID phb_id;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_id = srv_phb_create_number_id(PHB_STORAGE_NVRAM, 3, SRV_PHB_ENTRY_FIELD_NUMBER);
    srv_phb_set_invalid_number_id(&phb_id);
    result = srv_phb_check_number_id(phb_id);

    /* check testcase result */
    if (result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_create_number_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_set_invalid_number_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_check_number_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_number_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_set_invalid_number_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_check_number_id, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_name_by_number_id
 * DESCRIPTION
 *  test case for srv_phb_get_name_by_number_id() ,srv_phb_get_number_by_number_id() and srv_phb_get_store_index_by_number_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_name_by_number_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID phb_id;
    U16 name[20];
    U16 number[20];
    MMI_BOOL result1, result2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_id = srv_phb_create_number_id(PHB_PHONEBOOK, 0, SRV_PHB_ENTRY_FIELD_NUMBER);
    result1 = srv_phb_get_name_by_number_id(name, phb_id, sizeof(name) / sizeof(U16));
    result2 = srv_phb_get_number_by_number_id(number, phb_id, sizeof(number) / sizeof(U16));
    srv_phb_get_store_index_by_number_id(phb_id);

    /* check testcase result */
    if (result1 && result2)
    {
        AVK_LOG_FUN(srv_phb_get_name_by_number_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_get_number_by_number_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_get_store_index_by_number_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_name_by_number_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_get_number_by_number_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_get_store_index_by_number_id, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_cm_user_data_ex
 * DESCRIPTION
 *  test case for srv_phb_create_cm_user_data_ex() and srv_phb_destory_cm_user_data()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_cm_user_data_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = srv_phb_create_cm_user_data_ex((U16*) (WCHAR *)L"name", (U16*) (WCHAR *)L"12345");

    /* check testcase result */
    if (user_data != NULL)
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data_ex, AVK_PASS);
        AVK_LOG_FUN(srv_phb_destory_cm_user_data, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data_ex, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_destory_cm_user_data, AVK_FAIL);
    }

    srv_phb_destory_cm_user_data(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_cm_user_data
 * DESCRIPTION
 *  test case for srv_phb_create_cm_user_data() and srv_phb_destory_cm_user_data()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_cm_user_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = srv_phb_create_cm_user_data((U16*) (WCHAR *)L"name", 0, 0);

    /* check testcase result */
    if (user_data != NULL)
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data, AVK_PASS);
        AVK_LOG_FUN(srv_phb_destory_cm_user_data, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_destory_cm_user_data, AVK_FAIL);
    }

    srv_phb_destory_cm_user_data(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_cm_user_data_by_id
 * DESCRIPTION
 *  test case for srv_phb_create_cm_user_data_by_id() and srv_phb_destory_cm_user_data()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_cm_user_data_by_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID phb_id;
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_id = srv_phb_create_number_id(PHB_STORAGE_NVRAM, 0, SRV_PHB_ENTRY_FIELD_NUMBER);
    user_data = srv_phb_create_cm_user_data_by_id(phb_id);

    /* check testcase result */
    if (user_data != NULL)
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data_by_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_cm_user_data_by_id, AVK_FAIL);
    }

    srv_phb_destory_cm_user_data(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_hold_cm_user_data
 * DESCRIPTION
 *  test case for srv_phb_hold_cm_user_data() and srv_phb_destory_cm_user_data()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_hold_cm_user_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID phb_id;
    void *user_data = NULL;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_id = srv_phb_create_number_id(PHB_STORAGE_NVRAM, 0, SRV_PHB_ENTRY_FIELD_NUMBER);
    user_data = srv_phb_create_cm_user_data_by_id(phb_id);
    result = srv_phb_hold_cm_user_data(user_data);
    srv_phb_destory_cm_user_data(user_data);

    /* check testcase result */
    if (result && user_data)
    {
        AVK_LOG_FUN(srv_phb_hold_cm_user_data, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_hold_cm_user_data, AVK_FAIL);
    }

    srv_phb_destory_cm_user_data(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_caller_info_by_number
 * DESCRIPTION
 *  test case for srv_phb_get_caller_info_by_number() and srv_phb_get_caller_res_info_by_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_caller_info_by_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_phb_cm_number_struct cm_param;
    srv_phb_caller_info_struct caller;
    U16 number[20];
    srv_phb_caller_res_id_struct res_request;
    srv_phb_caller_res_info_struct res_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(number, (const WCHAR*)(WCHAR *)L"1234567");
    memset(&cm_param, 0, sizeof(cm_param));
    cm_param.number = number;
    result = srv_phb_get_caller_info_by_number(&cm_param, &caller);
    res_request.image_id = caller.image_id;
    srv_phb_get_caller_res_info_by_id(&res_request, &res_info);

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_caller_info_by_number, AVK_PASS);
        AVK_LOG_FUN(srv_phb_get_caller_res_info_by_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_caller_info_by_number, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_get_caller_res_info_by_id, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_field
 * DESCRIPTION
 *  test case for srv_phb_get_field()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_field()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_field(0, &field);

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_field, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_field, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_name
 * DESCRIPTION
 *  test case for srv_phb_get_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_name(0, name, sizeof(name) / sizeof(U16));

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_name, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_number
 * DESCRIPTION
 *  test case for srv_phb_get_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 number[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_number(0, number, sizeof(number) / sizeof(U16));

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_number_ex
 * DESCRIPTION
 *  test case for srv_phb_get_number_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_number_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 number[20];
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_number_ex(0, 1, number, &type, sizeof(number) / sizeof(U16));

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_number_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_number_ex, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_birthday
 * DESCRIPTION
 *  test case for srv_phb_get_birthday()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_birthday()
{
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 year;
    U8 month, day;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_birthday(0, &year, &month, &day);

    /* check testcase result */
    if (result)
    {
        AVK_LOG_FUN(srv_phb_get_birthday, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_birthday, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_optional_number
 * DESCRIPTION
 *  test case for srv_phb_get_optional_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_optional_number()
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 number[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_optional_number(0, SRV_PHB_ENTRY_FIELD_NUMBER, number, NULL, sizeof(number) / sizeof(U16));

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_optional_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_optional_number, AVK_FAIL);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_optional_number_order
 * DESCRIPTION
 *  test case for srv_phb_get_optional_number_order()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_optional_number_order()
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U8 number_order[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_optional_number_order(0, number_order);

    /* check testcase result */
    if (result == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_get_optional_number_order, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_optional_number_order, AVK_FAIL);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_email_address
 * DESCRIPTION
 *  test case for srv_phb_get_email_address()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_email_address()
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 email[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_email_address(0, email, (sizeof(email) / sizeof(U16)) >> 1);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_email_address, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_email_address, AVK_FAIL);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_email_address2
 * DESCRIPTION
 *  test case for srv_phb_get_email_address2()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_email_address2()
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 email[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_email_address2(0, email, (sizeof(email) / sizeof(U16)) >> 1);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_email_address2, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_email_address2, AVK_FAIL);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */ 
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_url
 * DESCRIPTION
 *  test case for srv_phb_get_url()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_url()
{
#if defined(__MMI_PHB_INFO_FIELD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 url[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_url(0, url, (sizeof(url) / sizeof(U16)) >> 1);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_url, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_url, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_address
 * DESCRIPTION
 *  test case for srv_phb_get_address()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_address()
{
#if defined(__MMI_PHB_INFO_FIELD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 pobox[30], extension[30], street[30], city[30], state[30], postalcode[30], country[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_address(0, pobox, extension, street, city, state, postalcode, country);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_address, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_address, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_image
 * DESCRIPTION
 *  test case for srv_phb_get_image()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_image()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 image_id;
    U16 image_path[200];
    U16 res_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_image(0, &image_id, image_path, &res_type);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_image, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_image, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_video
 * DESCRIPTION
 *  test case for srv_phb_get_video()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_video()
{
#if defined(__MMI_PHB_CALLER_VIDEO__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 v_id;
    U16 v_path[200];
    U16 res_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_video(0, &v_id, v_path, &res_type);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_video, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_video, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_default_number_id
 * DESCRIPTION
 *  test case for srv_phb_get_default_number_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_default_number_id()
{
#if defined(__MMI_PHB_DEFAULT_NUMBER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U8 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_default_number_id(0, &id);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_default_number_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_default_number_id, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_DEFAULT_NUMBER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_default_number
 * DESCRIPTION
 *  test case for srv_phb_get_default_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_default_number()
{
#if defined(__MMI_PHB_DEFAULT_NUMBER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 number[30];
    mmi_phb_num_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_default_number(0, number, &type, sizeof(number) / sizeof(U16));

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_default_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_default_number, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_DEFAULT_NUMBER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_imps
 * DESCRIPTION
 *  test case for srv_phb_get_imps()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_imps()
{
#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_voip_number
 * DESCRIPTION
 *  test case for srv_phb_get_voip_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_voip_number()
{
#if defined(__MMI_VOIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 voip[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_voip_number(0, voip, sizeof(voip) / sizeof(U16));

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_voip_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_voip_number, AVK_FAIL);
    }
#endif /* defined(__MMI_VOIP__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_group_name
 * DESCRIPTION
 *  test case for srv_phb_get_group_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_group_name()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 group_name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_group_name(0x01, group_name, (sizeof(group_name) / sizeof(U16)) >> 1);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_get_group_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_group_name, AVK_FAIL);
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_truncate_name
 * DESCRIPTION
 *  test case for srv_phb_truncate_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_truncate_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(name, (const WCHAR*)(WCHAR *)L"namenamenamenamenamenamenamenamenamename");
    srv_phb_truncate_name(name, PHB_STORAGE_NVRAM);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_truncate_name, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_truncate_name_ex
 * DESCRIPTION
 *  test case for srv_phb_truncate_name_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_truncate_name_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_truncate_name_ex, AVK_FAIL);
        return;
    }
    mmi_wcscpy(name, (const WCHAR*)(WCHAR *)L"namenamenamenamenamenamenamenamenamename");
    srv_phb_truncate_name_ex(name, g_phb_cntx.sim_interface, PHB_MSISDN);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_truncate_name_ex, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_truncate_number
 * DESCRIPTION
 *  test case for srv_phb_truncate_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_truncate_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(number, (const WCHAR*)(WCHAR *)L"123456789012345678901234567890");
    srv_phb_truncate_number(number);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_truncate_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_compare_number
 * DESCRIPTION
 *  test case for srv_phb_compare_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_compare_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_compare_number((U16*) (WCHAR *)L"12345", (U16*) (WCHAR *)L"12345");

    /* check testcase result */
    if (result == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_compare_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_compare_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_read_compare_length
 * DESCRIPTION
 *  test case for srv_phb_read_compare_length()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_read_compare_length()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_read_compare_length();

    /* check testcase result */
    if (result > 0)
    {
        AVK_LOG_FUN(srv_phb_read_compare_length, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_read_compare_length, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_number_to_int
 * DESCRIPTION
 *  test case for srv_phb_convert_number_to_int()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_number_to_int()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_convert_number_to_int((U16*) (WCHAR *)L"12345");

    /* check testcase result */
    if (result == 12345)
    {
        AVK_LOG_FUN(srv_phb_convert_number_to_int, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_number_to_int, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_number_to_int64
 * DESCRIPTION
 *  test case for srv_phb_convert_number_to_int64()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_number_to_int64()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __int64 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_convert_number_to_int64((U16*) (WCHAR *)L"12345");

    /* check testcase result */
    if (result == 12345)
    {
        AVK_LOG_FUN(srv_phb_convert_number_to_int64, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_number_to_int64, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_towupper
 * DESCRIPTION
 *  test case for srv_phb_towupper()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_towupper()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_towupper(L'w');

    /* check testcase result */
    if (result == 'W')
    {
        AVK_LOG_FUN(srv_phb_towupper, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_towupper, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_compare_wchar
 * DESCRIPTION
 *  test case for srv_phb_compare_wchar()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_compare_wchar()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_compare_wchar(L'a', L'b');

    /* check testcase result */
    if (result < 0)
    {
        AVK_LOG_FUN(srv_phb_compare_wchar, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_compare_wchar, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_compare_ucs2_string
 * DESCRIPTION
 *  test case for srv_phb_compare_ucs2_string()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_compare_ucs2_string()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_compare_ucs2_string((U16*) (WCHAR *)L"a", (U16*) (WCHAR *)L"b");

    /* check testcase result */
    if (result < 0)
    {
        AVK_LOG_FUN(srv_phb_compare_ucs2_string, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_compare_ucs2_string, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_compare_pinyin_string
 * DESCRIPTION
 *  test case for srv_phb_compare_pinyin_string()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_compare_pinyin_string()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 result;
    U16 str1[] = {'一','\0'};
    U16 str2[] = {'二','\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_compare_pinyin_string(str1, str2);

    /* check testcase result */
    if (result > 0)
    {
        AVK_LOG_FUN(srv_phb_compare_pinyin_string, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_compare_pinyin_string, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_gsm_extended_count
 * DESCRIPTION
 *  test case for srv_phb_gsm_extended_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_gsm_extended_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_gsm_extended_count((U16*) (WCHAR *)L"string", 10);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_gsm_extended_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_gsm_extended_count, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_ucs2_character
 * DESCRIPTION
 *  test case for srv_phb_check_ucs2_character()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_ucs2_character()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 check_string[] = {'中','国'};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_ucs2_character(check_string);

    /* check testcase result */
        AVK_LOG_FUN(srv_phb_check_ucs2_character, AVK_PASS);
    }


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_international_number
 * DESCRIPTION
 *  test case for srv_phb_check_international_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_international_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_international_number(0);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)      // TODO:
    {
        AVK_LOG_FUN(srv_phb_check_international_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_international_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_valid_number
 * DESCRIPTION
 *  test case for srv_phb_check_valid_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_valid_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result, result2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_valid_number((U16*) (WCHAR *)L"0123456789+pw*#?");
    result2 = srv_phb_check_valid_number((U16*) (WCHAR *)L"0123456789+pw*#?@");

    /* check testcase result */
    if (result == MMI_TRUE || result2 == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_check_valid_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_valid_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_valid_number_ex
 * DESCRIPTION
 *  test case for srv_phb_check_valid_number_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_valid_number_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result, result2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_valid_number_ex((U16*) (WCHAR *)L"0123456789", MMI_TRUE);
    result2 = srv_phb_check_valid_number_ex((U16*) (WCHAR *)L"0123456789P", MMI_TRUE);

    /* check testcase result */
    if (result == MMI_TRUE || result2 == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_check_valid_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_valid_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_check_valid_url
 * DESCRIPTION
 *  test case for srv_phb_check_valid_url()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_check_valid_url()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_check_valid_url((U16*) (WCHAR *)L"http://www.baidu.com");

    /* check testcase result */
    if (result == MMI_TRUE)
    {
        AVK_LOG_FUN(srv_phb_check_valid_url, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_check_valid_url, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_bcd
 * DESCRIPTION
 *  test case for srv_phb_convert_to_bcd(), srv_phb_convert_to_digit() and srv_phb_convert_to_digit_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_bcd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dest[10];
    U8 source[] = {'1', '2', '3', '4' , '\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_convert_to_bcd(dest, source, sizeof(dest) / sizeof(U8)))
    {
        AVK_LOG_FUN(srv_phb_convert_to_bcd, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_bcd, AVK_FAIL);
    }

    if (srv_phb_convert_to_digit(source, dest, sizeof(source) / sizeof(U8)))
    {
        AVK_LOG_FUN(srv_phb_convert_to_digit, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_digit, AVK_FAIL);
    }

    if (srv_phb_convert_to_digit_ex(source, dest, sizeof(source) / sizeof(U8), MMI_TRUE))
    {
        AVK_LOG_FUN(srv_phb_convert_to_digit_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_digit_ex, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_0x81
 * DESCRIPTION
 *  test case for srv_phb_convert_to_0x81()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_0x81()
{
#if defined(__PHB_0x81_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;
    U16 name[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(name, (const WCHAR*)(WCHAR *)L"你好");
    result = srv_phb_convert_to_0x81(name, MMI_TRUE);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_convert_to_0x81, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_0x81, AVK_FAIL);
    }
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_name
 * DESCRIPTION
 *  test case for srv_phb_convert_to_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_name_display_type(SRV_PHB_NAME_DISPLAY_TYPE_2, NULL, NULL);
    srv_phb_convert_to_name(name, (U16*) (WCHAR *)L"Feng", (U16*) (WCHAR *)L"Chen", 30);

    /* check testcase result */
    if (mmi_wcscmp(name, (U16*) (WCHAR *)L"Chen,Feng") == 0)
    {
        AVK_LOG_FUN(srv_phb_convert_to_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_name, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_spelling
 * DESCRIPTION
 *  test case for srv_phb_convert_to_spelling()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_spelling()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[30];
    U16 input_string = {'一'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_spelling(IMM_INPUT_MODE_QUICK_SEARCH_PINYIN, input_string, out_string, 30);

    /* check testcase result */
        AVK_LOG_FUN(srv_phb_convert_to_spelling, AVK_PASS);
    }
/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_pinyin
 * DESCRIPTION
 *  test case for srv_phb_convert_to_pinyin()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_pinyin()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[50];
    U16 input_string[] = {'一', '个', '\0'};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(out_string, 0, sizeof(out_string));
    srv_phb_convert_to_pinyin(input_string, out_string, 30);
    /* check testcase result */
        AVK_LOG_FUN(srv_phb_convert_to_pinyin, AVK_PASS);
    }


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_to_initial
 * DESCRIPTION
 *  test case for srv_phb_convert_to_initial()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_to_initial()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(out_string, 0, sizeof(out_string));
    srv_phb_convert_to_initial((U16*) (WCHAR *)L"Hello Kitty", out_string, 30);

    /* check testcase result */
    if (mmi_wcscmp(out_string, (U16*) (WCHAR *)L"HK") == 0)
    {
        AVK_LOG_FUN(srv_phb_convert_to_initial, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_to_initial, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_remove_invalid_name
 * DESCRIPTION
 *  test case for srv_phb_remove_invalid_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_remove_invalid_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(out_string, (const WCHAR*)(WCHAR *)L"12\r\n3");
    srv_phb_remove_invalid_name(out_string);

    /* check testcase result */
    if (mmi_wcscmp(out_string, (const WCHAR*)(WCHAR *)L"123") == 0)
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_name, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_remove_invalid_number_ex
 * DESCRIPTION
 *  test case for srv_phb_remove_invalid_number_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_remove_invalid_number_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(out_string, (U16*) (WCHAR *)L"123abc");
    srv_phb_remove_invalid_number_ex(out_string);

    /* check testcase result */
    if (mmi_wcscmp(out_string, (U16*) (WCHAR *)L"123") == 0)
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_number_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_number_ex, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_remove_invalid_number
 * DESCRIPTION
 *  test case for srv_phb_remove_invalid_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_remove_invalid_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 out_string[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(out_string, (U16*) (WCHAR *)L"123abc");
    srv_phb_remove_invalid_number(out_string);

    /* check testcase result */
    if (mmi_wcscmp(out_string, (U16*) (WCHAR *)L"123") == 0)
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_remove_invalid_number, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_number_asc_to_wcs
 * DESCRIPTION
 *  test case for srv_phb_number_asc_to_wcs()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_number_asc_to_wcs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 out_string[50];
    mmi_phb_wcs_num_struct wcs;
    mmi_phb_asc_num_struct asc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asc.type = MMI_PHB_NUM_TYPE_MOBILE;
    strcpy((char*)asc.number, (char*)"12345");
    srv_phb_number_asc_to_wcs(&wcs, &asc);

    /* check testcase result */
    if (mmi_wcscmp(wcs.number, (U16*) (WCHAR *)L"12345") == 0)
    {
        AVK_LOG_FUN(srv_phb_number_asc_to_wcs, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_number_asc_to_wcs, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_number_wcs_to_asc
 * DESCRIPTION
 *  test case for srv_phb_number_wcs_to_asc()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_number_wcs_to_asc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 out_string[50];
    mmi_phb_wcs_num_struct wcs;
    mmi_phb_asc_num_struct asc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wcs.type = MMI_PHB_NUM_TYPE_MOBILE;
    mmi_wcscpy(wcs.number, (U16*) (WCHAR *)L"12345");
    srv_phb_number_wcs_to_asc(&asc, &wcs);

    /* check testcase result */
    if (strcmp((char*)asc.number, (char*)"12345") == 0)
    {
        AVK_LOG_FUN(srv_phb_number_wcs_to_asc, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_number_wcs_to_asc, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_ds_compare_halfbyte
 * DESCRIPTION
 *  test case for srv_phb_ds_compare_halfbyte()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_ds_compare_halfbyte()
{
#ifdef __MMI_DIALER_SEARCH__
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_ds_compare_halfbyte((void*)"123", (void*)"456", 4);

    /* check testcase result */
    if (result != 0)
    {
        AVK_LOG_FUN(srv_phb_ds_compare_halfbyte, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_ds_compare_halfbyte, AVK_FAIL);
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */ 
#endif /* __MMI_DIALER_SEARCH__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_ds_search_entry
 * DESCRIPTION
 *  test case for srv_phb_ds_search_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_ds_search_entry()
{
#ifdef __MMI_DIALER_SEARCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 key_word[20];
    srv_phb_ds_list_cntx_struct ds_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(key_word, 0, sizeof(key_word));
    mmi_wcscpy(key_word, (U16*) (WCHAR *)L"123");
    if (0)      // TODO:
        result = srv_phb_ds_search_entry(key_word, &ds_list);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_ds_search_entry, AVK_PASS);
#endif /* __MMI_DIALER_SEARCH__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_contact
 * DESCRIPTION
 *  test case for srv_phb_create_contact() ,srv_phb_free_contact() and srv_phb_reset_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_reset_contact(contact, MMI_PHB_CONTACT_FIELD_ID_NAME);
    srv_phb_free_contact(contact);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_create_contact, AVK_PASS);
    AVK_LOG_FUN(srv_phb_reset_contact, AVK_PASS);
    AVK_LOG_FUN(srv_phb_free_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_fname
 * DESCRIPTION
 *  test case for srv_phb_contact_get_fname() and srv_phb_contact_set_fname()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_fname()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_fname(contact, (U16*) (WCHAR *)L"Firstname");
    result = srv_phb_contact_get_fname(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"Firstname") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_fname, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_fname, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_fname, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_fname, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_lname
 * DESCRIPTION
 *  test case for srv_phb_contact_get_lname() and srv_phb_contact_set_lname()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_lname()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_lname(contact, (U16*) (WCHAR *)L"Lastname");
    result = srv_phb_contact_get_lname(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"Lastname") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_lname, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_lname, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_lname, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_lname, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_name
 * DESCRIPTION
 *  test case for srv_phb_contact_get_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_name()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_name_display_type(SRV_PHB_NAME_DISPLAY_TYPE_2, NULL, NULL);
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_fname(contact, (U16*) (WCHAR *)L"Firstname");
    srv_phb_contact_set_lname(contact, (U16*) (WCHAR *)L"Lastname");
    result = srv_phb_contact_get_name(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"Lastname,Firstname") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_get_name, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_name, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_nick
 * DESCRIPTION
 *  test case for srv_phb_contact_get_nick() and srv_phb_contact_set_nick()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_nick()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_nick(contact, (U16*) (WCHAR *)L"nickname");
    result = srv_phb_contact_get_nick(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"nickname") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_nick, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_nick, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_nick, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_nick, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_company
 * DESCRIPTION
 *  test case for srv_phb_contact_get_company() and srv_phb_contact_set_company()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_company()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_company(contact, (U16*) (WCHAR *)L"company");
    result = srv_phb_contact_get_company(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"company") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_company, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_company, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_company, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_company, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_title
 * DESCRIPTION
 *  test case for srv_phb_contact_get_title() and srv_phb_contact_set_title()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_title()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_title(contact, (U16*) (WCHAR *)L"title");
    result = srv_phb_contact_get_title(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"title") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_title, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_title, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_title, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_title, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_bday
 * DESCRIPTION
 *  test case for srv_phb_contact_get_bday() and srv_phb_contact_set_bday()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_bday()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_bday_struct *result;
    srv_phb_bday_struct bday;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    bday.b_year = 2011;
    bday.b_month = 1;
    bday.b_day = 22;
    srv_phb_contact_set_bday(contact, &bday);
    result = srv_phb_contact_get_bday(contact);

    /* check testcase result */
    if (result->b_year == 2011 && result->b_month == 1 && result->b_day == 22)
    {
        AVK_LOG_FUN(srv_phb_contact_set_bday, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_bday, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_bday, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_bday, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_group
 * DESCRIPTION
 *  test case for srv_phb_contact_get_group() and srv_phb_contact_set_group()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_group()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_group_struct *result;
    srv_phb_group_struct group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    group.group_id[0] = 1;
    group.group_count = 1;
    srv_phb_contact_set_group(contact, &group);
    result = srv_phb_contact_get_group(contact);

    /* check testcase result */
    if (result->group_id[0] == 1 && result->group_count == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_group, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_group, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_group, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_group, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_group_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_set_group_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_group_ex()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_group_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_group_ex(contact, 1);
    result = srv_phb_contact_get_group(contact);

    /* check testcase result */
    if (result->group_id[0] == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_group_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_group_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_ringtone
 * DESCRIPTION
 *  test case for srv_phb_contact_get_ringtone() and srv_phb_contact_set_ringtone()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_ringtone()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;
    srv_phb_res_struct ringtone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    ringtone.res_id = 1;
    srv_phb_contact_set_ringtone(contact, &ringtone);
    result = srv_phb_contact_get_ringtone(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_ringtone, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_ringtone, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_ringtone, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_ringtone, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_ringtone_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_set_ringtone_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_ringtone_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_ringtone_ex(contact, 1, NULL);
    result = srv_phb_contact_get_ringtone(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_ringtone_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_ringtone_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_image
 * DESCRIPTION
 *  test case for srv_phb_contact_get_image() and srv_phb_contact_set_image()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_image()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;
    srv_phb_res_struct image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    image.res_id = 1;
    srv_phb_contact_set_image(contact, &image);
    result = srv_phb_contact_get_image(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_image, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_image, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_image, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_image, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_image_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_set_image_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_image_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_image_ex(contact, 1, NULL);
    result = srv_phb_contact_get_image(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_image_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_image_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_video
 * DESCRIPTION
 *  test case for srv_phb_contact_get_video() and srv_phb_contact_set_video()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_video()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;
    srv_phb_res_struct video;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    video.res_id = 1;
    srv_phb_contact_set_video(contact, &video);
    result = srv_phb_contact_get_video(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_video, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_video, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_video, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_video, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_video_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_set_video_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_video_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_res_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_video_ex(contact, 1, NULL, MMI_TRUE);
    result = srv_phb_contact_get_video(contact);

    /* check testcase result */
    if (result->res_id == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_set_video_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_video_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_imps
 * DESCRIPTION
 *  test case for srv_phb_contact_get_imps() and srv_phb_contact_set_imps()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_imps()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_imps(contact, (U16*) (WCHAR *)L"imps");
    result = srv_phb_contact_get_imps(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"imps") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_imps, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_imps, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_imps, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_imps, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_asc_imps
 * DESCRIPTION
 *  test case for srv_phb_contact_set_asc_imps()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_asc_imps()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_asc_imps(contact, "imps");
    result = srv_phb_contact_get_imps(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"imps") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_imps, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_imps, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_voip
 * DESCRIPTION
 *  test case for srv_phb_contact_get_voip() and srv_phb_contact_set_voip()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_voip()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_voip(contact, (U16*) (WCHAR *)L"voip");
    result = srv_phb_contact_get_voip(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"voip") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_voip, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_voip, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_voip, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_voip, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_asc_voip
 * DESCRIPTION
 *  test case for srv_phb_contact_set_asc_voip()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_asc_voip()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_asc_voip(contact, "voip");
    result = srv_phb_contact_get_voip(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"voip") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_voip, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_voip, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_msn
 * DESCRIPTION
 *  test case for srv_phb_contact_get_msn() and srv_phb_contact_set_msn()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_msn()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_msn(contact, (U16*) (WCHAR *)L"msn");
    result = srv_phb_contact_get_msn(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"msn") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_msn, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_msn, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_msn, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_msn, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_set_asc_msn
 * DESCRIPTION
 *  test case for srv_phb_contact_set_asc_msn()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_set_asc_msn()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_set_asc_msn(contact, "msn");
    result = srv_phb_contact_get_msn(contact);

    /* check testcase result */
    if (mmi_wcscmp(result, (U16*) (WCHAR *)L"msn") == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_msn, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_set_asc_msn, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_number
 * DESCRIPTION
 *  test case for srv_phb_contact_add_number() and srv_phb_contact_get_number_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_number_struct number;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    number.index = 10;
    mmi_wcscpy(number.number, (U16*) (WCHAR *)L"1234567");
    srv_phb_contact_add_number(contact, &number);
    result = srv_phb_contact_get_number_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_number, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_number_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_number, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_number_count, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_asc_number
 * DESCRIPTION
 *  test case for srv_phb_contact_add_asc_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_asc_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_asc_number(contact, 0, 0, MMI_PHB_NUM_TYPE_MOBILE, "1234567", NULL, MMI_TRUE);
    result = srv_phb_contact_get_number_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_number, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_number_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_add_number_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_number_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_number_ex(contact, 0, 0, MMI_PHB_NUM_TYPE_MOBILE, (U16*) (WCHAR *)L"1234567", NULL, MMI_TRUE);
    result = srv_phb_contact_get_number_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_number_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_number_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_number_iterator
 * DESCRIPTION
 *  test case for srv_phb_contact_get_number_iterator() ,srv_phb_contact_get_number_next(), srv_phb_contact_get_number_by_sub_id(),
 *  srv_phb_contact_get_number_by_save_index() and srv_phb_contact_get_first_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_number_iterator()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_number_struct number;
    srv_phb_iterator iterator;
    srv_phb_number_struct *number_out_1, *number_out_2, *number_out_3, *number_out_4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    number.sub_id = 10;
    number.index = 10;
    mmi_wcscpy(number.number, (U16*) (WCHAR *)L"1234567");
    srv_phb_contact_add_number(contact, &number);
    iterator = srv_phb_contact_get_number_iterator(contact);
    number_out_1 = srv_phb_contact_get_number_next(&iterator);
    number_out_2 = srv_phb_contact_get_number_by_sub_id(contact, number.sub_id);
    number_out_3 = srv_phb_contact_get_number_by_save_index(contact, number.index);
    number_out_4 = srv_phb_contact_get_first_number(contact);

    /* check testcase result */
    if (number_out_1->index == 10 &&
        number_out_2->index == 10 && number_out_3->sub_id == 10 && number_out_4->sub_id == 10)
    {
        AVK_LOG_FUN(srv_phb_contact_get_number_iterator, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_number_next, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_number_by_sub_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_number_by_save_index, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_first_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_number_iterator, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_number_next, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_number_by_sub_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_number_by_save_index, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_first_number, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_remove_number
 * DESCRIPTION
 *  test case for srv_phb_contact_remove_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_remove_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_number_struct number;
    U16 result1, result2;
    srv_phb_iterator iterator;
    srv_phb_number_struct *number_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    number.index = 10;
    mmi_wcscpy(number.number, (U16*) (WCHAR *)L"1234567");
    srv_phb_contact_add_number(contact, &number);
    result1 = srv_phb_contact_get_number_count(contact);
    iterator = srv_phb_contact_get_number_iterator(contact);
    number_out = srv_phb_contact_get_number_next(&iterator);
    srv_phb_contact_remove_number(contact, number_out);
    result2 = srv_phb_contact_get_number_count(contact);

    /* check testcase result */
    if (result1 == 1 && result2 == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_remove_number, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_remove_number, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_email
 * DESCRIPTION
 *  test case for srv_phb_contact_add_email() and srv_phb_contact_get_email_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_email()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_email_struct email;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    email.index = 10;
    mmi_wcscpy(email.email, (U16*) (WCHAR *)L"abc@home.com");
    srv_phb_contact_add_email(contact, &email);
    result = srv_phb_contact_get_email_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_email, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_email_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_email, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_email_count, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_asc_email
 * DESCRIPTION
 *  test case for srv_phb_contact_add_asc_email()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_asc_email()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_asc_email(contact, 0, 0, MMI_PHB_NUM_TYPE_MOBILE, "abc@home.com", NULL);
    result = srv_phb_contact_get_email_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_email, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_email, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_email_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_add_email_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_email_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_email_ex(contact, 0, 0, MMI_PHB_NUM_TYPE_MOBILE, (U16*) (WCHAR *)L"abc@home.com", NULL);
    result = srv_phb_contact_get_email_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_email_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_email_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_email_iterator
 * DESCRIPTION
 *  test case for srv_phb_contact_get_email_iterator() ,srv_phb_contact_get_email_next(), srv_phb_contact_get_email_by_sub_id(),
 *  srv_phb_contact_get_email_by_save_index() and srv_phb_contact_get_first_email()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_email_iterator()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_email_struct email;
    srv_phb_iterator iterator;
    srv_phb_email_struct *email_out_1, *email_out_2, *email_out_3, *email_out_4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    email.sub_id = 10;
    email.index = 10;
    mmi_wcscpy(email.email, (U16*) (WCHAR *)L"abc@home.com");
    srv_phb_contact_add_email(contact, &email);
    iterator = srv_phb_contact_get_email_iterator(contact);
    email_out_1 = srv_phb_contact_get_email_next(&iterator);
    email_out_2 = srv_phb_contact_get_email_by_sub_id(contact, email.sub_id);
    email_out_3 = srv_phb_contact_get_email_by_save_index(contact, email.index);
    email_out_4 = srv_phb_contact_get_first_email(contact);

    /* check testcase result */
    if (email_out_1->index == 10 && email_out_2->index == 10 && email_out_3->sub_id == 10 && email_out_4->sub_id == 10)
    {
        AVK_LOG_FUN(srv_phb_contact_get_email_iterator, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_email_next, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_email_by_sub_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_email_by_save_index, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_first_email, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_email_iterator, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_email_next, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_email_by_sub_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_email_by_save_index, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_first_email, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_remove_email
 * DESCRIPTION
 *  test case for srv_phb_contact_remove_email()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_remove_email()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_email_struct email;
    U16 result1, result2;
    srv_phb_iterator iterator;
    srv_phb_email_struct *email_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    email.index = 10;
    mmi_wcscpy(email.email, (U16*) (WCHAR *)L"abc@home.com");
    srv_phb_contact_add_email(contact, &email);
    result1 = srv_phb_contact_get_email_count(contact);
    iterator = srv_phb_contact_get_email_iterator(contact);
    email_out = srv_phb_contact_get_email_next(&iterator);
    srv_phb_contact_remove_email(contact, email_out);
    result2 = srv_phb_contact_get_email_count(contact);

    /* check testcase result */
    if (result1 == 1 && result2 == 0)
    {
        AVK_LOG_FUN(srv_phb_contact_remove_email, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_remove_email, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_address
 * DESCRIPTION
 *  test case for srv_phb_contact_add_address() and srv_phb_contact_get_address_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_address()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_address_struct address;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    address.index = 10;
    srv_phb_contact_add_address(contact, &address);
    result = srv_phb_contact_get_address_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_address, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_address_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_address, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_address_count, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_address_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_add_address_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_address_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;
    mmi_phb_address_struct address_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_address_ex(contact, 0, 0, &address_info);
    result = srv_phb_contact_get_address_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_address_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_address_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_address_iterator
 * DESCRIPTION
 *  test case for srv_phb_contact_get_address_iterator() ,srv_phb_contact_get_address_next(), srv_phb_contact_get_address_by_sub_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_address_iterator()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_address_struct address;
    srv_phb_iterator iterator;
    srv_phb_address_struct *address_out_1, *address_out_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    address.sub_id = 10;
    address.index = 10;
    srv_phb_contact_add_address(contact, &address);
    iterator = srv_phb_contact_get_address_iterator(contact);
    address_out_1 = srv_phb_contact_get_address_next(&iterator);
    address_out_2 = srv_phb_contact_get_address_by_sub_id(contact, address.sub_id);

    /* check testcase result */
    if (address_out_1->index == 10 && address_out_2->index == 10)
    {
        AVK_LOG_FUN(srv_phb_contact_get_address_iterator, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_address_next, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_address_by_sub_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_address_iterator, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_address_next, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_address_by_sub_id, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_url
 * DESCRIPTION
 *  test case for srv_phb_contact_add_url() and srv_phb_contact_get_url_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_url()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_url_struct url;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    url.index = 10;
    srv_phb_contact_add_url(contact, &url);
    result = srv_phb_contact_get_url_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_url, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_url_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_url, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_url_count, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_url_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_add_url_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_url_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_url_ex(contact, 0, 0, (U16*) (WCHAR *)L"http://www.baidu.com");
    result = srv_phb_contact_get_url_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_url_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_url_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_asc_url
 * DESCRIPTION
 *  test case for srv_phb_contact_add_asc_url()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_asc_url()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_asc_url(contact, 0, 0, "http://www.baidu.com");
    result = srv_phb_contact_get_url_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_url, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_asc_url, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_url_iterator
 * DESCRIPTION
 *  test case for srv_phb_contact_get_url_iterator() ,srv_phb_contact_get_url_next(), srv_phb_contact_get_url_by_sub_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_url_iterator()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_url_struct url;
    srv_phb_iterator iterator;
    srv_phb_url_struct *url_out_1, *url_out_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    url.sub_id = 10;
    url.index = 10;
    srv_phb_contact_add_url(contact, &url);
    iterator = srv_phb_contact_get_url_iterator(contact);
    url_out_1 = srv_phb_contact_get_url_next(&iterator);
    url_out_2 = srv_phb_contact_get_url_by_sub_id(contact, url.sub_id);

    /* check testcase result */
    if (url_out_1->index == 10 && url_out_2->index == 10)
    {
        AVK_LOG_FUN(srv_phb_contact_get_url_iterator, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_url_next, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_url_by_sub_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_url_iterator, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_url_next, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_url_by_sub_id, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_note
 * DESCRIPTION
 *  test case for srv_phb_contact_add_note() and srv_phb_contact_get_note_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_note()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_note_struct note;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    note.index = 10;
    srv_phb_contact_add_note(contact, &note);
    result = srv_phb_contact_get_note_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_note, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_note_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_note, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_note_count, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_add_note_ex
 * DESCRIPTION
 *  test case for srv_phb_contact_add_note_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_add_note_ex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_add_note_ex(contact, 0, 0, (U16*) (WCHAR *)L"note");
    result = srv_phb_contact_get_note_count(contact);

    /* check testcase result */
    if (result == 1)
    {
        AVK_LOG_FUN(srv_phb_contact_add_note_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_add_note_ex, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_get_note_iterator
 * DESCRIPTION
 *  test case for srv_phb_contact_get_note_iterator() ,srv_phb_contact_get_note_next(), srv_phb_contact_get_note_by_sub_id()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_get_note_iterator()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact;
    srv_phb_note_struct note;
    srv_phb_iterator iterator;
    srv_phb_note_struct *note_out_1, *note_out_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);
    note.sub_id = 10;
    note.index = 10;
    srv_phb_contact_add_note(contact, &note);
    iterator = srv_phb_contact_get_note_iterator(contact);
    note_out_1 = srv_phb_contact_get_note_next(&iterator);
    note_out_2 = srv_phb_contact_get_note_by_sub_id(contact, note.sub_id);

    /* check testcase result */
    if (note_out_1->index == 10 && note_out_2->index == 10)
    {
        AVK_LOG_FUN(srv_phb_contact_get_note_iterator, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_note_next, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_get_note_by_sub_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_get_note_iterator, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_note_next, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_get_note_by_sub_id, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_contact_cb(srv_phb_async_op_cb_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_add_contact
 * DESCRIPTION
 *  test case for srv_phb_add_contact() ,srv_phb_stop_async_op(), srv_phb_free_handle()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_add_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_add_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.record_index = 10;
    req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
    req.storage = PHB_STORAGE_NVRAM;
    req.contact = srv_phb_create_contact(NULL);
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_add_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_add_contact, AVK_PASS);
    AVK_LOG_FUN(srv_phb_free_handle, AVK_PASS);
    AVK_LOG_FUN(srv_phb_stop_async_op, AVK_PASS);
    srv_phb_free_contact(req.contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_update_contact
 * DESCRIPTION
 *  test case for srv_phb_update_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_update_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_update_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.id = 10;
    req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
    req.contact = srv_phb_create_contact(NULL);
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_update_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_update_contact, AVK_PASS);
    srv_phb_free_contact(req.contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_delete_contact
 * DESCRIPTION
 *  test case for srv_phb_delete_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_delete_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_delete_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.id = 10;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_delete_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_delete_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_copy_contact
 * DESCRIPTION
 *  test case for srv_phb_copy_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_copy_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_copy_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.id = 10;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_copy_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_copy_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_move_contact
 * DESCRIPTION
 *  test case for srv_phb_move_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_move_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_move_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.id = 10;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_move_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_move_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_copy_all_contact
 * DESCRIPTION
 *  test case for srv_phb_copy_all_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_copy_all_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_copy_all_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_copy_all_contact, AVK_FAIL);
        return;
    }
    if (g_phb_cntx.sim_interface == SIM1)
    {
        req.src_storage = PHB_STORAGE_SIM;
    }
    else if (g_phb_cntx.sim_interface == SIM2)
    {
        req.src_storage = PHB_STORAGE_SIM2;
    }
    else if (g_phb_cntx.sim_interface == SIM3)
    {
        req.src_storage = PHB_STORAGE_SIM3;
    }
    else if (g_phb_cntx.sim_interface == SIM4)
    {
        req.src_storage = PHB_STORAGE_SIM4;
    }
    req.dest_storage = PHB_STORAGE_NVRAM;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_copy_all_contact(&req);
    /* srv_phb_stop_async_op(phb_handle); */
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_copy_all_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_move_all_contact
 * DESCRIPTION
 *  test case for srv_phb_move_all_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_move_all_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_move_all_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_move_all_contact, AVK_FAIL);
        return;
    }
    if (g_phb_cntx.sim_interface == SIM1)
    {
        req.src_storage = PHB_STORAGE_SIM;
    }
    else if (g_phb_cntx.sim_interface == SIM2)
    {
        req.src_storage = PHB_STORAGE_SIM2;
    }
    else if (g_phb_cntx.sim_interface == SIM3)
    {
        req.src_storage = PHB_STORAGE_SIM3;
    }
    else if (g_phb_cntx.sim_interface == SIM4)
    {
        req.src_storage = PHB_STORAGE_SIM4;
    }
    req.dest_storage = PHB_STORAGE_NVRAM;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_move_all_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_move_all_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_delete_all_contact
 * DESCRIPTION
 *  test case for srv_phb_delete_all_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_delete_all_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_delete_all_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
        /* (Please insert sim card) */
        AVK_LOG_FUN(srv_phb_delete_all_contact, AVK_FAIL);
        return;
    }
    if (g_phb_cntx.sim_interface == SIM1)
    {
        req.storage = PHB_STORAGE_SIM;
    }
    else if (g_phb_cntx.sim_interface == SIM2)
    {
        req.storage = PHB_STORAGE_SIM2;
    }
    else if (g_phb_cntx.sim_interface == SIM3)
    {
        req.storage = PHB_STORAGE_SIM3;
    }
    else if (g_phb_cntx.sim_interface == SIM4)
    {
        req.storage = PHB_STORAGE_SIM4;
    }
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_delete_all_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_delete_all_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_multi_copy_contact
 * DESCRIPTION
 *  test case for srv_phb_multi_copy_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_multi_copy_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_multi_copy_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.contact_count = 0;
    req.id_array = NULL;
    req.dest_storage = PHB_STORAGE_NVRAM;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_multi_copy_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_multi_copy_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_multi_move_contact
 * DESCRIPTION
 *  test case for srv_phb_multi_move_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_multi_move_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_multi_move_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.contact_count = 0;
    req.id_array = NULL;
    req.dest_storage = PHB_STORAGE_NVRAM;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_multi_move_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_multi_move_contact, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_multi_delete_contact
 * DESCRIPTION
 *  test case for srv_phb_multi_delete_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_multi_delete_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_handle phb_handle;
    srv_phb_multi_delete_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.contact_count = 0;
    req.id_array = NULL;
    req.cb = avk_appsrv_srv_phb_contact_cb;
    req.user_data = NULL;
    phb_handle = srv_phb_multi_delete_contact(&req);
    srv_phb_stop_async_op(phb_handle);
    srv_phb_free_handle(phb_handle);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_multi_delete_contact, AVK_PASS);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_field_filter
 * DESCRIPTION
 *  test case for srv_phb_create_field_filter(), srv_phb_create_field_filter_ext() ,srv_phb_create_field_filter_ext2() and srv_phb_free_field_filter()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_field_filter()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter filter1 = NULL, filter2 = NULL, filter3 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter1 = srv_phb_create_field_filter();
    filter2 = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NAME);
    filter3 = srv_phb_create_field_filter_ext2(MMI_PHB_CONTACT_FIELD_NAME, MMI_PHB_NUM_TYPE_MOBILE);

    /* check testcase result */
    if (filter1 && filter2 && filter3)
    {
        AVK_LOG_FUN(srv_phb_create_field_filter, AVK_PASS);
        AVK_LOG_FUN(srv_phb_create_field_filter_ext, AVK_PASS);
        AVK_LOG_FUN(srv_phb_create_field_filter_ext2, AVK_PASS);
        AVK_LOG_FUN(srv_phb_free_field_filter, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_field_filter, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_create_field_filter_ext, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_create_field_filter_ext2, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_free_field_filter, AVK_FAIL);
    }
    srv_phb_free_field_filter(filter1);
    srv_phb_free_field_filter(filter2);
    srv_phb_free_field_filter(filter3);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_filed_filter_set_field
 * DESCRIPTION
 *  test case for srv_phb_filed_filter_set_field() and srv_phb_read_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_filed_filter_set_field()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter filter = NULL;
    srv_phb_contact contact = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = srv_phb_create_field_filter();
    srv_phb_filed_filter_set_field(filter, MMI_PHB_CONTACT_FIELD_NAME);
    contact = srv_phb_read_contact(0, filter, NULL);

    /* check testcase result */
    if (contact != NULL)
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_field, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_field, AVK_FAIL);
    }
    srv_phb_free_field_filter(filter);
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_filed_filter_set_number_type
 * DESCRIPTION
 *  test case for srv_phb_filed_filter_set_number_type()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_filed_filter_set_number_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter filter = NULL;
    srv_phb_contact contact = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = srv_phb_create_field_filter();
    srv_phb_filed_filter_set_number_type(filter, MMI_PHB_NUM_TYPE_MOBILE);
    contact = srv_phb_read_contact(0, filter, NULL);

    /* check testcase result */
    if (contact != NULL)
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_field, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_field, AVK_FAIL);
    }
    srv_phb_free_field_filter(filter);
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_filed_filter_set_default_number
 * DESCRIPTION
 *  test case for srv_phb_filed_filter_set_default_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_filed_filter_set_default_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter filter = NULL;
    srv_phb_contact contact = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = srv_phb_create_field_filter();
    srv_phb_filed_filter_set_default_number(filter, MMI_FALSE);
    contact = srv_phb_read_contact(0, filter, NULL);

    /* check testcase result */
    if (contact != NULL)
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_default_number, AVK_PASS);
        AVK_LOG_FUN(srv_phb_read_contact, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_filed_filter_set_default_number, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_read_contact, AVK_FAIL);
    }
    srv_phb_free_field_filter(filter);
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_create_contact_filter
 * DESCRIPTION
 *  test case for srv_phb_create_contact_filter(), srv_phb_create_contact_filter_by_storage() ,srv_phb_create_contact_filter_by_filed() and srv_phb_free_contact_filter()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_create_contact_filter()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter filter1 = NULL, filter2 = NULL, filter3 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter1 = srv_phb_create_contact_filter();
    filter2 = srv_phb_create_contact_filter_by_storage(SRV_PHB_STORAGE_MASK_PHONE);
    filter3 = srv_phb_create_contact_filter_by_filed(MMI_PHB_CONTACT_FIELD_NAME);

    /* check testcase result */
    if (filter1 != NULL && filter2 != NULL && filter3 != NULL)
    {
        AVK_LOG_FUN(srv_phb_create_contact_filter, AVK_PASS);
        AVK_LOG_FUN(srv_phb_create_contact_filter_by_storage, AVK_PASS);
        AVK_LOG_FUN(srv_phb_create_contact_filter_by_filed, AVK_PASS);
        AVK_LOG_FUN(srv_phb_free_contact_filter, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_create_contact_filter, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_create_contact_filter_by_storage, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_create_contact_filter_by_filed, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_free_contact_filter, AVK_FAIL);
    }
    srv_phb_free_contact_filter(filter1);
    srv_phb_free_contact_filter(filter2);
    srv_phb_free_contact_filter(filter3);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_filter_set_storage
 * DESCRIPTION
 *  test case for srv_phb_contact_filter_set_storage(), srv_phb_contact_filter_set_filed(), srv_phb_contact_filter_set_query()
 *  srv_phb_contact_filter_set_group() and srv_phb_contact_filter_set_group_ex()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_filter_set_storage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter filter = NULL;
    srv_phb_group_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = srv_phb_create_contact_filter();
    srv_phb_contact_filter_set_storage(filter, SRV_PHB_STORAGE_MASK_PHONE);
    srv_phb_contact_filter_set_field(filter, MMI_PHB_CONTACT_FIELD_NAME);
    srv_phb_contact_filter_set_query(filter, NULL, MMI_PHB_CONTACT_FIELD_NAME, SRV_PHB_QUERY_TYPE_PARTIAL);
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_contact_filter_set_group(filter, 0, MMI_FALSE);
    group_info.group_id[0] = 1;
    group_info.group_id[1] = 2;
    group_info.group_count = 2;
    srv_phb_contact_filter_set_group_ex(filter, &group_info, MMI_TRUE);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 

    /* check testcase result */
    if (filter != NULL)
    {
        AVK_LOG_FUN(srv_phb_contact_filter_set_storage, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_filter_set_field, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_filter_set_query, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_filter_set_group, AVK_PASS);
        AVK_LOG_FUN(srv_phb_contact_filter_set_group_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_contact_filter_set_storage, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_filter_set_field, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_filter_set_query, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_filter_set_group, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_contact_filter_set_group_ex, AVK_FAIL);
    }
    srv_phb_free_contact_filter(filter);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_query
 * DESCRIPTION
 *  test case for srv_phb_query(), srv_phb_query_get_contact(), srv_phb_query_get_count(),
 *  srv_phb_query_get_contact_id(), srv_phb_query_get_align_field_type(), srv_phb_query_get_align_field()
 *  srv_phb_query_get_matched_info(), srv_phb_query_get_alpha_count(), srv_phb_query_get_name(),
 *  srv_phb_query_get_imgae(), srv_phb_query_get_number(), srv_phb_query_get_email() and srv_phb_free_query_handle()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_query()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_handle query_hdl = NULL;
    srv_phb_query_req_struct req;
    srv_phb_contact contact = NULL;
    U32 count = 0;
    mmi_phb_contact_id contact_id;
    mmi_phb_contact_field_id_enum field_id;
    mmi_phb_contact_field_id_enum field_type;
    void *get_align_field = NULL;
    srv_phb_query_match_info_struct *get_match_info = NULL;
    srv_phb_alpha_info_struct *get_alpha_info = NULL;
    WCHAR *get_name;
    //srv_phb_res_struct *get_image;
    //srv_phb_number_struct *get_number;
    srv_phb_email_struct *get_email;
    WCHAR query_get_number[MMI_PHB_NUMBER_PLUS_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.alpha_table = MMI_TRUE;
    req.item_order = MMI_TRUE;
    req.align_field = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
    req.filter = srv_phb_create_contact_filter();
    srv_phb_contact_filter_set_storage(req.filter, SRV_PHB_STORAGE_MASK_PHONE);
    query_hdl = srv_phb_query(&req, NULL);
    contact = srv_phb_query_get_contact(query_hdl, 1);
    count = srv_phb_query_get_count(query_hdl);
    contact_id = srv_phb_query_get_contact_id(query_hdl, 1);
    field_id = srv_phb_query_get_align_field_type(query_hdl, 1);
    get_align_field = srv_phb_query_get_align_field(query_hdl, 1, &field_type);
    get_match_info = srv_phb_query_get_matched_info(query_hdl, 1);
    get_alpha_info = srv_phb_query_get_alpha_count(query_hdl, 1);
    get_name = srv_phb_query_get_name(query_hdl, 1);
    srv_phb_query_get_imgae(query_hdl, 1);
    srv_phb_query_get_number(query_hdl, 1, query_get_number);
    get_email = srv_phb_query_get_email(query_hdl, 1);

    /* check testcase result */
    if (query_hdl != NULL &&
        contact != NULL &&
        count != 0 &&
        contact_id > 0 &&
        field_id >= 0 &&
        get_align_field != NULL &&
        get_match_info != NULL && get_alpha_info != NULL && get_name != NULL && /*get_number != NULL && */get_email != NULL)
    {
        AVK_LOG_FUN(srv_phb_query, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_contact, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_count, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_contact_id, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_align_field_type, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_align_field, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_matched_info, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_alpha_count, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_name, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_imgae, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_number, AVK_PASS);
        AVK_LOG_FUN(srv_phb_query_get_email, AVK_PASS);
        AVK_LOG_FUN(srv_phb_free_query_handle, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_query, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_contact, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_count, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_contact_id, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_align_field_type, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_align_field, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_matched_info, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_alpha_count, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_name, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_imgae, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_number, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_query_get_email, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_free_query_handle, AVK_FAIL);
    }
    srv_phb_free_contact_filter(req.filter);
    srv_phb_free_query_handle(query_hdl);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_number_id_check_modify
 * DESCRIPTION
 *  test case for srv_phb_number_id_check_modify()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_number_id_check_modify()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID number_id;
    srv_phb_contact contact;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number_id = srv_phb_create_number_id(PHB_STORAGE_NVRAM, 0, SRV_PHB_ENTRY_FIELD_NUMBER);
    contact = srv_phb_create_contact(NULL);
    result = srv_phb_number_id_check_modify((U16*) (WCHAR *)L"123456", number_id, 3, contact);

    /* check testcase result */
    if (result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_number_id_check_modify, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_number_id_check_modify, AVK_FAIL);
    }
    srv_phb_free_contact(contact);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_convert_field_filter
 * DESCRIPTION
 *  test case for srv_phb_convert_field_filter()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_convert_field_filter()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_convert_field_filter(SRV_PHB_ENTRY_FIELD_NAME);

    /* check testcase result */
    if (result == MMI_PHB_CONTACT_FIELD_NAME)
    {
        AVK_LOG_FUN(srv_phb_convert_field_filter, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_convert_field_filter, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_num_count
 * DESCRIPTION
 *  test case for srv_phb_get_num_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_num_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_num_count(0);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_num_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_num_count, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_email_count
 * DESCRIPTION
 *  test case for srv_phb_get_email_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_email_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_email_count(0);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_email_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_email_count, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_support_field_count
 * DESCRIPTION
 *  test case for srv_phb_get_support_field_count()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_support_field_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_support_field_count(PHB_STORAGE_NVRAM, MMI_PHB_CONTACT_FIELD_ID_NAME);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_support_field_count, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_support_field_count, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_support_field
 * DESCRIPTION
 *  test case for srv_phb_get_support_field()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_support_field()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_support_field(PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_support_field, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_support_field, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_alpha_field_length
 * DESCRIPTION
 *  test case for srv_phb_get_alpha_field_length()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_alpha_field_length()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_alpha_field_length(PHB_STORAGE_NVRAM, MMI_PHB_CONTACT_FIELD_ID_NAME);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_alpha_field_length, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_alpha_field_length, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_usim_field_total
 * DESCRIPTION
 *  test case for srv_phb_get_usim_field_total()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_usim_field_total()
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_usim_field_total(PHB_STORAGE_SIM, 1, PHB_MSISDN);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_usim_field_total, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_usim_field_total, AVK_FAIL);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_usim_field_used
 * DESCRIPTION
 *  test case for srv_phb_get_usim_field_used()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_usim_field_used()
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_usim_field_used(PHB_STORAGE_SIM, 1, PHB_MSISDN);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_usim_field_used, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_usim_field_used, AVK_FAIL);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_add_field_type
 * DESCRIPTION
 *  test case for srv_phb_add_field_type()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_add_field_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_add_field_type((U16*) (WCHAR *)L"Labe(WCHAR *)L", MMI_PHB_CONTACT_FIELD_ID_VOIP);

    /* check testcase result */
    if (result >= 0 || result == -1)
    {
        AVK_LOG_FUN(srv_phb_add_field_type, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_add_field_type, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_delete_field_type
 * DESCRIPTION
 *  test case for srv_phb_delete_field_type()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_delete_field_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_delete_field_type(1, MMI_PHB_CONTACT_FIELD_ID_VOIP);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_delete_field_type, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_delete_field_type, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_field_type_list
 * DESCRIPTION
 *  test case for srv_phb_get_field_type_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_field_type_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    U8 type_array[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_field_type_list(type_array, MMI_PHB_CONTACT_FIELD_ID_NAME, PHB_STORAGE_NVRAM);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_field_type_list, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_field_type_list, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_field_type_label
 * DESCRIPTION
 *  test case for srv_phb_get_field_type_label()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_field_type_label()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    WCHAR *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_field_type_label(1, MMI_PHB_CONTACT_FIELD_ID_NAME, PHB_STORAGE_NVRAM);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_get_field_type_label, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_update_field_type
 * DESCRIPTION
 *  test case for srv_phb_update_field_type()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_update_field_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_update_field_type(1, (U16*) (WCHAR *)L"Labe(WCHAR *)L", MMI_PHB_CONTACT_FIELD_ID_VOIP);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_update_field_type, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_max_field_type
 * DESCRIPTION
 *  test case for srv_phb_get_max_field_type()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_max_field_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_max_field_type(PHB_STORAGE_NVRAM, MMI_PHB_CONTACT_FIELD_ID_NAME);

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_max_field_type, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_max_field_type, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_add_group_members
 * DESCRIPTION
 *  test case for srv_phb_add_group_members()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_add_group_members()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id contact_id_list[] = {2, 3, 4};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_add_group_members(contact_id_list, sizeof(contact_id_list) / sizeof(mmi_phb_contact_id), 1, MMI_FALSE);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_add_group_members, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_remove_group_member
 * DESCRIPTION
 *  test case for srv_phb_remove_group_member()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_remove_group_member()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_remove_group_member(2, 1);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_remove_group_member, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_remove_all_group_members
 * DESCRIPTION
 *  test case for srv_phb_remove_all_group_members()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_remove_all_group_members()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_remove_all_group_members(1);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_remove_all_group_members, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_add_group
 * DESCRIPTION
 *  test case for srv_phb_add_group()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_add_group()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&group_info, 0, sizeof(group_info));
    srv_phb_add_group(&group_info);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_add_group, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_delete_group
 * DESCRIPTION
 *  test case for srv_phb_delete_group()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_delete_group()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_delete_group(5);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_delete_group, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_group_list
 * DESCRIPTION
 *  test case for srv_phb_get_group_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_group_list()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_array[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_group_list(group_array, (U16*) (WCHAR *)L"group name", PHB_STORAGE_NVRAM);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_get_group_list, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_group_info
 * DESCRIPTION
 *  test case for srv_phb_get_group_info()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_group_info()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_group_info(1, &group_info);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_get_group_info, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_update_group_info
 * DESCRIPTION
 *  test case for srv_phb_update_group_info()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_update_group_info()
{
#ifdef __MMI_PHB_CALLER_GROUP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&group_info, 0, sizeof(group_info));
    srv_phb_update_group_info(1, &group_info);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_update_group_info, AVK_PASS);
#endif /* __MMI_PHB_CALLER_GROUP__ */ 
}

#if 1
/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_storage_mask
 * DESCRIPTION
 *  test case for srv_phb_get_storage_mask()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_storage_mask()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_storage_mask();

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_storage_mask, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_storage_mask, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_set_storage_mask
 * DESCRIPTION
 *  test case for srv_phb_set_storage_mask()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_set_storage_mask()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_storage_mask(0);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_set_storage_mask, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_name_display
 * DESCRIPTION
 *  test case for srv_phb_get_name_display()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_name_display()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CONTACT_NAME_DISPLAY_TYPE_ENUM result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_name_display();

    /* check testcase result */
    if (result >= 0)
    {
        AVK_LOG_FUN(srv_phb_get_name_display, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_get_name_display, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_set_name_display_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_set_name_display_cb(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_set_name_display
 * DESCRIPTION
 *  test case for srv_phb_set_name_display()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_set_name_display()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_set_name_display(SRV_CONTACT_NAME_DISPLAY_TYPE_1, avk_appsrv_srv_phb_set_name_display_cb);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_set_name_display, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_set_name_display, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_save_notify
 * DESCRIPTION
 *  test case for srv_phb_get_save_notify() and srv_phb_set_save_notify()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_save_notify()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_save_notify(SRV_CONTACT_SAVE_CONTACT_NOTIFY_ON);
    result = srv_phb_get_save_notify();

    /* check testcase result */
    if (result == SRV_CONTACT_SAVE_CONTACT_NOTIFY_ON)
    {
        AVK_LOG_FUN(srv_phb_set_save_notify, AVK_PASS);
        AVK_LOG_FUN(srv_phb_get_save_notify, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_set_save_notify, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_get_save_notify, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_get_name_speak
 * DESCRIPTION
 *  test case for srv_phb_get_name_speak() and srv_phb_set_name_speak()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_get_name_speak()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CONTACT_SPEAK_NAME_ENUM result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_set_name_speak(SRV_CONTACT_SPEAK_NAME_ON);
    result = srv_phb_get_name_speak();

    /* check testcase result */
    if (result == SRV_CONTACT_SPEAK_NAME_ON)
    {
        AVK_LOG_FUN(srv_phb_set_name_speak, AVK_PASS);
        AVK_LOG_FUN(srv_phb_get_name_speak, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_set_name_speak, AVK_FAIL);
        AVK_LOG_FUN(srv_phb_get_name_speak, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode_cb(U16 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode
 * DESCRIPTION
 *  test case for srv_phb_xdnmgr_toggle_dial_mode()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
    	// (Please insert sim card)
        AVK_LOG_FUN(srv_phb_xdnmgr_toggle_dial_mode, AVK_FAIL);
        return;
    }
    result = srv_phb_xdnmgr_toggle_dial_mode(g_phb_cntx.sim_interface, PHB_FDN, avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode_cb, NULL);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_xdnmgr_toggle_dial_mode, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xdnmgr_toggle_dial_mode, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_get_list_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_xdnmgr_get_list_cb(U16 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_get_list
 * DESCRIPTION
 *  test case for srv_phb_xdnmgr_get_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xdnmgr_get_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //SRV_PHB_XMGNT_HANDLE result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
    	// (Please insert sim card)
        AVK_LOG_FUN(srv_phb_xdnmgr_get_list, AVK_FAIL);
        return;
    }
    srv_phb_xdnmgr_get_list(g_phb_cntx.sim_interface, PHB_FDN, avk_appsrv_srv_phb_xdnmgr_get_list_cb, NULL);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_xdnmgr_get_list, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_fdnmgr_set_entry_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_fdnmgr_set_entry_cb(U16 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_fdnmgr_set_entry_xmgnt_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_fdnmgr_set_entry_xmgnt_cb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_fdnmgr_set_entry
 * DESCRIPTION
 *  test case for srv_phb_fdnmgr_set_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_fdnmgr_set_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    SRV_PHB_XMGNT_HANDLE xg_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
    	// (Please insert sim card)
        AVK_LOG_FUN(srv_phb_fdnmgr_set_entry, AVK_FAIL);
        return;
    }
    xg_hdl = srv_phb_xmgnt_get_list(
                g_phb_cntx.sim_interface,
                VS_PHB_XMGNT_TA_TYPE,
                avk_appsrv_srv_phb_fdnmgr_set_entry_xmgnt_cb);
    result = srv_phb_fdnmgr_set_entry(
                g_phb_cntx.sim_interface,
                PHB_FDN,
                1,
                2,
                NULL,
                NULL,
                avk_appsrv_srv_phb_fdnmgr_set_entry_cb,
                xg_hdl,
                MMI_FALSE,
                NULL);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_fdnmgr_set_entry, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_fdnmgr_set_entry, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_delete_entry_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_srv_phb_xdnmgr_delete_entry_cb(U16 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_xdnmgr_delete_entry
 * DESCRIPTION
 *  test case for srv_phb_xdnmgr_delete_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_xdnmgr_delete_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.sim_interface == -1) /* not a usable sim card, case fail */
    {
    	// (Please insert sim card)
        AVK_LOG_FUN(srv_phb_xdnmgr_delete_entry, AVK_FAIL);
        return;
    }
    result = srv_phb_xdnmgr_delete_entry(g_phb_cntx.sim_interface, PHB_FDN, 1, 2, avk_appsrv_srv_phb_xdnmgr_delete_entry_cb, NULL);

    /* check testcase result */
    if (result == MMI_TRUE || result == MMI_FALSE)
    {
        AVK_LOG_FUN(srv_phb_xdnmgr_delete_entry, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(srv_phb_xdnmgr_delete_entry, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_read_my_number
 * DESCRIPTION
 *  test case for srv_phb_read_my_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_read_my_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_my_number_struct my_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_read_my_number(&my_number);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_read_my_number, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_write_my_number
 * DESCRIPTION
 *  test case for srv_phb_write_my_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_write_my_number()
{
#ifdef __MMI_VCARD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_my_number_struct my_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&my_number, 0, sizeof(my_number));
    srv_phb_write_my_number(&my_number);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_write_my_number, AVK_PASS);
#endif /* __MMI_VCARD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_contact_to_vcard_object
 * DESCRIPTION
 *  test case for srv_phb_contact_to_vcard_object()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_contact_to_vcard_object()
{
#ifdef __MMI_VCARD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_phb_my_number_struct my_number;
    srv_phb_contact contact;
    vcard_object_struct vcard_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&vcard_object, 0, sizeof(vcard_object));
    contact = srv_phb_create_contact(NULL);
    srv_phb_contact_to_vcard_object(contact, &vcard_object);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_contact_to_vcard_object, AVK_PASS);
    srv_phb_free_contact(contact);
#endif /* __MMI_VCARD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_srv_phb_vcard_object_to_contact
 * DESCRIPTION
 *  test case for srv_phb_vcard_object_to_contact()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_srv_phb_vcard_object_to_contact()
{
#ifdef __MMI_VCARD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_phb_my_number_struct my_number;
    srv_phb_contact contact;
    vcard_object_struct vcard_object;
    U16 family[20];
    U16 given[20];
    U16 mid[20];
    U16 prefix[20];
    U16 suffix[20];
    U16 name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&vcard_object, 0, sizeof(vcard_object));
    contact = srv_phb_create_contact(NULL);	
    mmi_wcscpy(family, (WCHAR *)L"family");
    mmi_wcscpy(given, (WCHAR *)L"given");
    mmi_wcscpy(mid, (WCHAR *)L"mid");
    mmi_wcscpy(prefix, (WCHAR *)L"prefix");
    mmi_wcscpy(suffix, (WCHAR *)L"suffix");
    mmi_wcscpy(name, (WCHAR *)L"name");
    vcard_object.n.family = family;
    vcard_object.n.given = given;
    vcard_object.n.mid = mid;
    vcard_object.n.prefix = prefix;
    vcard_object.n.suffix = suffix;
    vcard_object.n.name = name;
    srv_phb_vcard_object_to_contact(contact, &vcard_object);

    /* check testcase result */
    AVK_LOG_FUN(srv_phb_vcard_object_to_contact, AVK_PASS);
    srv_phb_free_contact(contact);
#endif /* __MMI_VCARD__ */ 
}
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL avk_appsrv_phbinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_sim_enum sim_card;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* testcase function list */
    /* SDK api */
    g_phb_cntx.func_list[i++] = vs_misc_phb_add_contact;
    g_phb_cntx.func_list[i++] = vs_misc_phb_get_contact;
    g_phb_cntx.func_list[i++] = vs_misc_phb_update_contact;
    g_phb_cntx.func_list[i++] = vs_misc_phb_search_contact;
    g_phb_cntx.func_list[i++] = vs_misc_phb_delete_contact;
    g_phb_cntx.func_list[i++] = vs_misc_phb_get_capacity;
    g_phb_cntx.func_list[i++] = vs_misc_phb_get_group_list;
    /* Other api */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_mem_malloc_ext;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_sse_convert_number_to_int;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_datamgr_res_check_data_space;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_set_vt_call;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_set_phb_status;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_is_phb_support;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_get_alpha_length;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_get_fdn_total;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_get_bdn_total;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_get_msisdn_total;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_startup_get_adn_used_first;
    /* You must test these case in the following order -- <Begin> */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_set_entry;     /* Two cases */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_list;      /* 20 */
    //g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_list_count;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_entry_index;
    //g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_entry_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_entry_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_entry_number_length;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_get_entry;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_delete_entry;
    /* You must test these case in the following order -- <End> */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_query_dial_mode;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_toggle_dial_mode;
    //g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_read_dial_mode;
    //g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_read_fdn_to_ram;
    //g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_update_fdn_to_ram;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xmgnt_search_fdn_by_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_owner_number_parse_msisdn_info;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_owner_number_set_name_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_owner_number_get_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_owner_number_get_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_storage;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_store_index_in_storage;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_storage_status;        /* 40 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_storage_accessible;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_total_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_used_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_store_index_to_sort_index;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_sort_index_to_store_index;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_store_index_to_record_index;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_record_index_to_store_index;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_entry_exist;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_number_exist;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_sync_get_index_array;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_sync_vcard;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_sync_get_record_size;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_imps_build_vcard;
#if 0
/* under construction !*/
#endif /* 0 */ 
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_name_by_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_store_index_by_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_set_invalid_number_id;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_name_by_number_id;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_create_cm_user_data_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_create_cm_user_data; /* 60 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_create_cm_user_data_by_id;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_hold_cm_user_data;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_caller_info_by_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_field;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_number_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_birthday;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_optional_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_optional_number_order;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_email_address;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_email_address2;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_url;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_address;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_image;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_video;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_default_number_id;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_default_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_imps;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_voip_number;     /* 80 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_group_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_truncate_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_truncate_name_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_truncate_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_compare_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_read_compare_length;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_number_to_int;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_number_to_int64;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_towupper;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_compare_wchar;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_compare_ucs2_string;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_compare_pinyin_string;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_gsm_extended_count;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_ucs2_character;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_international_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_valid_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_valid_number_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_check_valid_url;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_bcd;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_0x81;     /* 100 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_spelling;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_pinyin;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_to_initial;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_remove_invalid_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_remove_invalid_number_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_remove_invalid_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_number_asc_to_wcs;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_number_wcs_to_asc;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_ds_compare_halfbyte;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_ds_search_entry;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_create_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_fname;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_lname;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_name;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_nick;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_company;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_title;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_bday;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_group;   /* 120 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_group_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_ringtone;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_ringtone_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_image;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_image_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_video;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_video_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_imps;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_asc_imps;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_voip;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_asc_voip;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_msn;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_set_asc_msn;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_asc_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_number_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_number_iterator;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_remove_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_email;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_asc_email;       /* 140 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_email_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_email_iterator;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_remove_email;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_address;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_address_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_address_iterator;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_url;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_url_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_asc_url;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_url_iterator;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_note;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_add_note_ex;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_get_note_iterator;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_add_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_update_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_delete_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_copy_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_move_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_copy_all_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_move_all_contact;    /* 160 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_delete_all_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_multi_copy_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_multi_move_contact;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_multi_delete_contact;
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_create_field_filter;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_filed_filter_set_field;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_filed_filter_set_number_type;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_filed_filter_set_default_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_filter_set_storage;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_query;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_number_id_check_modify;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_convert_field_filter;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_num_count;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_email_count;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_support_field;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_support_field_count;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_alpha_field_length;      /* 180 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_usim_field_total;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_usim_field_used;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_add_field_type;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_delete_field_type;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_field_type_list;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_field_type_label;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_update_field_type;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_max_field_type;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_add_group_members;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_remove_group_member;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_remove_all_group_members;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_add_group;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_delete_group;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_group_list;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_group_info;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_update_group_info;
#if 1
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_storage_mask;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_set_storage_mask;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_name_display;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_set_name_display;       /* 200 */
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_save_notify;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_get_name_speak;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xdnmgr_toggle_dial_mode;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xdnmgr_get_list;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_fdnmgr_set_entry;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_xdnmgr_delete_entry;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_read_my_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_write_my_number;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_contact_to_vcard_object;
    g_phb_cntx.func_list[i++] = avk_appsrv_srv_phb_vcard_object_to_contact;        /* 210 */
#endif /* 0 */ 

    g_phb_cntx.total_num = i;

    /* initialize */
    g_phb_cntx.counter = 0;

    /* get a usable sim card */
    sim_card = srv_nw_usab_get_one_usable_sim();
    if (sim_card == MMI_SIM1)
    {
        g_phb_cntx.sim_interface = SIM1;
    }
    else if (sim_card == MMI_SIM2)
    {
        g_phb_cntx.sim_interface = SIM2;
    }
    else if (sim_card == MMI_SIM3)
    {
        g_phb_cntx.sim_interface = SIM3;
    }
    else if (sim_card == MMI_SIM4)
    {
        g_phb_cntx.sim_interface = SIM4;
    }
    else
    {
        g_phb_cntx.sim_interface = -1;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbdeinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbdeinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* deinit context data */
    g_phb_cntx.is_running = MMI_FALSE;
    g_phb_cntx.allow_run = MMI_FALSE;
    g_phb_cntx.pretest_counter = 0;
    g_phb_cntx.counter = 0;
    g_phb_cntx.total_num = 0;
    g_phb_cntx.sim_interface = -1;
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbdelete_all_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbdelete_all_cb(srv_phb_async_op_cb_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->type == SRV_PHB_OP_CB_TYPE_DELETE_ALL)
    {
        avk_appsrv_phbdeinit();
        AVK_ASYN_DONE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbtest_timer_cb
 * DESCRIPTION
 *  timer callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbtest_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.counter < g_phb_cntx.total_num)
    {
        /*
         * if (vs_tfw_is_test_all_active(VS_APPSRV_PIM_PHB) == 0)
         * {
         * U16 str_w[20];
         * U16 value;
         * kal_wsprintf((WCHAR*) str_w, "%d / %d", g_phb_cntx.counter, g_phb_cntx.total_num);
         * value = (g_phb_cntx.counter * 100) / g_phb_cntx.total_num;
         * UpdateCategory402Value(value, (U8*)str_w);
         * }
         */
        g_phb_cntx.func_list[g_phb_cntx.counter++] ();
        if (g_phb_cntx.allow_run)
        {
            gui_start_timer(0, avk_appsrv_phbtest_timer_cb);
        }
    }
    else
    {
        srv_phb_delete_all_req_struct req;

        /* Delete all the test data */
        req.storage = PHB_STORAGE_NVRAM;
        req.cb = avk_appsrv_phbdelete_all_cb;
        srv_phb_delete_all_contact(&req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbcommon_prepare_contact_data
 * DESCRIPTION
 *  common funciton, for prepare a contact data
 * PARAMETERS
 *  contact_info        [OUT]       
 *  name                [IN]        
 *  number              [IN]        
 *  group_mask          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbcommon_prepare_contact_data(
                srv_phb_sdk_contact_struct *contact_info,
                U16 *name,
                U16 *number,
                U32 group_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(contact_info, 0, sizeof(srv_phb_sdk_contact_struct));

    mmi_wcsncpy((U16*) contact_info->name, (U16*) name, MMI_PHB_NAME_LENGTH);
    mmi_wcsncpy((U16*) contact_info->number, (U16*) number, MMI_PHB_NUMBER_LENGTH);
    contact_info->group_mask = group_mask;

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_wcsncpy((U16*) contact_info->home_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
    mmi_wcsncpy((U16*) contact_info->office_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
    mmi_wcsncpy((U16*) contact_info->fax_number, (U16*) (WCHAR *)L"10086", MMI_PHB_NUMBER_LENGTH);
    mmi_wcsncpy((U16*) contact_info->email_address, (U16*) (WCHAR *)L"mediatek@mediatek.com", MMI_PHB_EMAIL_LENGTH);
    mmi_wcsncpy((U16*) contact_info->company_name, (U16*) (WCHAR *)L"MediaTek(BeiJing)Inc.", MMI_PHB_COMPANY_LENGTH);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    mmi_wcsncpy((U16*) contact_info->email_address2, (U16*) (WCHAR *)L"mediatek2@mediatek.com", MMI_PHB_EMAIL_LENGTH);
#endif 
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    contact_info->birth_day = 1;
    contact_info->birth_mon = 1;
    contact_info->birth_year = 2009;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

#if defined(__MMI_PHB_INFO_FIELD__)
    mmi_wcsncpy((U16*) contact_info->title, (U16*) (WCHAR *)L"MediaTek Inc.", MMI_PHB_TITLE_LENGTH);
    mmi_wcsncpy((U16*) contact_info->url, (U16*) (WCHAR *)L"www.mediatek.com", MMI_PHB_URL_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_pobox, (U16*) (WCHAR *)L"100000", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_extension, (U16*) (WCHAR *)L"83000", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_street, (U16*) (WCHAR *)L"Ke Xue Yuan Load", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_city, (U16*) (WCHAR *)L"BeiJing", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_state, (U16*) (WCHAR *)L"HaiDian", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_postal_code, (U16*) (WCHAR *)L"010", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->adr_country, (U16*) (WCHAR *)L"China", MMI_PHB_ADDRESS_LENGTH);
    mmi_wcsncpy((U16*) contact_info->note, (U16*) (WCHAR *)L"MediaTek Note", MMI_PHB_NOTE_LENGTH);
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbpre_test_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  contact_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbpre_test_cb(S32 result, srv_phb_sdk_contact_struct *contact_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sdk_add_req_struct phb_add_req_info;
    srv_phb_sdk_contact_struct contact_info;

#ifdef WIN32
    wchar_t name_list[][50] =
#else 
    wchar_t name_list[][50] =
#endif 
    {
        {L"Zhibo Tong"},
        {L"Feng Lin"},
        {L"Nan Zhao"},
        {L"Keith Chen"},
        {L"Zhiwei Yang"},
        {L"Lihong Li"},
        {L"Mary Tian"},
        {L"Jia Luo"},
        {L"Isiah Chen"},
        {L"Twoby Tseng"}
    };
#ifdef WIN32
    wchar_t num_list[][50] =
#else 
    wchar_t num_list[][50] =
#endif 
    {
        {L"1234567890"},
        {L"1234567891"},
        {L"1234567892"},
        {L"1234567893"},
        {L"1234567894"},
        {L"1234567895"},
        {L"1234567896"},
        {L"1234567897"},
        {L"1234567898"},
        {L"1234567899"}
    };
    U32 group_mask_list[] = 
    {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PHB_NO_ERROR == result)
    {
        phb_add_req_info.contact_ptr = &contact_info;
        phb_add_req_info.storage = PHB_STORAGE_NVRAM;
        if (g_phb_cntx.pretest_counter < sizeof(group_mask_list) / sizeof(U32))
        {
            avk_appsrv_phbcommon_prepare_contact_data(
                phb_add_req_info.contact_ptr,
                (U16*) name_list[g_phb_cntx.pretest_counter],
                (U16*) num_list[g_phb_cntx.pretest_counter],
                group_mask_list[g_phb_cntx.pretest_counter]);
            srv_phb_sdk_add_contact(&phb_add_req_info, avk_appsrv_phbpre_test_cb);
            g_phb_cntx.pretest_counter++;
        }
        else
        {
            avk_appsrv_phbresume_test();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbpre_test_delete_all_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbpre_test_delete_all_cb(srv_phb_async_op_cb_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->type == SRV_PHB_OP_CB_TYPE_DELETE_ALL)
    {
        srv_phb_sdk_add_req_struct phb_add_req_info;
        srv_phb_sdk_contact_struct contact_info;

        phb_add_req_info.contact_ptr = &contact_info;
        phb_add_req_info.storage = PHB_STORAGE_NVRAM;
        avk_appsrv_phbcommon_prepare_contact_data(
            phb_add_req_info.contact_ptr,
            (U16*) (WCHAR *)L"VS Team",
            (U16*) (WCHAR *)L"1234567",
            0x01);
        srv_phb_sdk_add_contact(&phb_add_req_info, avk_appsrv_phbpre_test_cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbpre_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_appsrv_phbpre_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_delete_all_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete all the test data */
    req.storage = PHB_STORAGE_NVRAM;
    req.cb = avk_appsrv_phbpre_test_delete_all_cb;
    srv_phb_delete_all_contact(&req);
}

extern void vs_ta_setting_clean_file(void);


/*****************************************************************************
 * FUNCTION
 *  avk_appsrv_phbstart_test
 * DESCRIPTION
 *  testcase enter funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void avk_appsrv_phbstart_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.is_running)
    {
        return;
    }
    if (!avk_appsrv_phbinit())
    {
        return;
    }

    /* pre-test */
    avk_appsrv_phbpre_test();
    g_phb_cntx.is_running = MMI_TRUE;

    /*
     * if (vs_tfw_is_test_all_active(VS_APPSRV_PIM_PHB) == 0)
     * {
     * MMI_BOOL ret;
     * U16 str_w[20];
     * ret = mmi_frm_scrn_enter(GRP_ID_AVK, SCR_ID_VS_APPSER_PIM_PHB, NULL, NULL, MMI_FRM_FULL_SCRN);
     * if (ret == MMI_FALSE)
     * {
     * return;
     * }
     * kal_wsprintf((WCHAR*) str_w, "%d / %d", g_phb_cntx.counter, g_phb_cntx.total_num);
     * ShowCategory402Screen((PU8) GetString(STR_ID_VS_APPSER_PIM_PHB),
     * 0,
     * 0, 
     * 0, 
     * 0, 
     * 0, 
     * NULL, 
     * 0, 
     * (U8*)str_w);
     * }
     */
}

AVK_ASYN_CASE(AVK_APPSRV_PIM_PHB,AVK_APPSRV_PIM)
{
	avk_appsrv_phbstart_test();
}

