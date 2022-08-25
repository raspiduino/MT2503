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
 *   avk_pluto_mem.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* fw memory -s */
extern "C"
{
#include "med_utility.h"
}

AVK_ADD_ITEM(AVK_PLUTO_MEM_AUTO, L"Auto cases", AVK_PLUTO_MEM);




static void VS_CASE_MEM_FINISHED(MMI_BOOL ret_b, S32 ti_e, const void * words)
{

    AVK_ASYN_DONE();
    AVK_CASE_RESULT((0 != ret_b) ? AVK_PASS : AVK_FAIL);
/*
    U16 wszTxt[128] = {0};
    
    vs_tfw_trace_result((U16*)words, ret_b, 0, VS_TA_FW_MEM);
    if (vs_tfw_is_test_all_active(ti_e))
    {
        if (ret_b)
            vs_tfw_finish_case(ti_e);
    }
    else
    {
        kal_wstrcat(wszTxt, words);
        kal_wsprintf(&wszTxt[kal_wstrlen(wszTxt)], " ret [%d]", ret_b);
        
        #ifdef __MMI_SCREEN_ROTATE__
        if (ret_b)
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_SUCCESS, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        else
        {
            DisplayPopup((PU8) wszTxt, IMG_GLOBAL_FAIL, 0, UI_POPUP_NOTIFYDURATION_TIME, 1);
        }
        #endif
    }
*/
}

#if (defined( __COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM___))
static void mmi_fw_mem_cache_alloc_cb(void * p)
{
    
}

static mmi_ret mmi_fw_mem_asm_prepare_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_alloc_size = 0;
    U32 pool_size = 0;
    MMI_BOOL ret_b = MMI_FALSE;
    void * ptr = NULL;
    U32 cache_size = 0;
    mmi_frm_asm_property_struct p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ASM_CANCELED:
            break;
        case EVT_ID_ASM_PREPARED:
            {
               
                mmi_frm_asm_check_integrity_r();    
                VS_CASE_MEM_FINISHED(MMI_FALSE, 0, L"vs_fw_mem_01");
                return MMI_RET_OK;
            }
            
            break;
        default:
            break;
    }

    VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_01");

    return MMI_RET_OK;
}
#endif


extern void vs_fw_mem_01(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_alloc_size = 0;
    U32 pool_size = 0;
    MMI_BOOL ret_b = MMI_FALSE;
    void * ptr = NULL;
    U32 cache_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if (defined( __COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM___))
    mmi_frm_asm_prepare(GRP_ID_AVK, 0, (mmi_proc_func)mmi_fw_mem_asm_prepare_cb, NULL, (mmi_frm_asm_prepare_flag_type)0);
#else
VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_01");
#endif
}

extern void vs_fw_mem_02(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * ptr = NULL;
    U32 max_alloc_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined( __COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM___))
    max_alloc_size = mmi_frm_asm_get_max_alloc_size_r(GRP_ID_AVK);
    ptr = applib_asm_alloc_r(GRP_ID_AVK, 512);
    if (NULL == ptr)
    {
        // FALSE
        VS_CASE_MEM_FINISHED(MMI_FALSE, 0, L"vs_fw_mem_02");
        return;
    }
    applib_asm_free_r(GRP_ID_AVK, ptr);
    
    ptr = applib_asm_alloc_nc_r(GRP_ID_AVK, 512);
    if (NULL == ptr)
    {
        // FALSE
        VS_CASE_MEM_FINISHED(MMI_FALSE, 0, L"vs_fw_mem_02");
        return;
    }
    applib_asm_free_r(GRP_ID_AVK, ptr);
    
    ptr = mmi_frm_asm_alloc_r(GRP_ID_AVK, 512);
    if (NULL == ptr)
    {
        // FALSE
        VS_CASE_MEM_FINISHED(MMI_FALSE, 0, L"vs_fw_mem_02");
        return;
    }
    mmi_frm_asm_free_r(GRP_ID_AVK, ptr);
    VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_02");
#else
    VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_02");
#endif
}

extern void vs_fw_mem_03(void)
{
#if (defined( __COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM___))
        mmi_frm_asm_cancel_prepare(GRP_ID_AVK, mmi_fw_mem_asm_prepare_cb, NULL);
        
        VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_03");
#else
        VS_CASE_MEM_FINISHED(MMI_TRUE, 0, L"vs_fw_mem_03");
#endif
}

extern void vs_med_mem(void)
{
#if (defined( __COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM___))
    AVK_LOG_FUN_UNSUPPORTED(med_ext_left_size);
    AVK_LOG_FUN_UNSUPPORTED(med_alloc_ext_mem);
    AVK_LOG_FUN_UNSUPPORTED(med_alloc_ext_mem_cacheable);
    AVK_LOG_FUN_UNSUPPORTED(med_free_ext_mem);
#else
    U64 left_size = 0;
    U32 allocate_size = 0;
    void* mem_ptr_1 = NULL;
    void* mem_ptr_2 = NULL;
    
#define TEST_SIZE 100


    left_size = med_ext_left_size();
    AVK_LOG_FUN(med_ext_left_size, AVK_PASS);

    if (left_size > TEST_SIZE)
        allocate_size = TEST_SIZE;
    else
        allocate_size = left_size >> 1;

    mem_ptr_1 = med_alloc_ext_mem(allocate_size);
    AVK_LOG_FUN(med_alloc_ext_mem, (mem_ptr_1 > 0));
    if (mem_ptr_1)
    {
        med_free_ext_mem(&mem_ptr_1);
        AVK_LOG_FUN(med_free_ext_mem, (mem_ptr_1 == NULL));
    }
    else
        AVK_LOG_FUN(med_free_ext_mem, AVK_NA);        

    mem_ptr_2 = med_alloc_ext_mem_cacheable(allocate_size);
    AVK_LOG_FUN(med_alloc_ext_mem_cacheable, (mem_ptr_2 > 0));
    if (mem_ptr_2)
    {
        med_free_ext_mem(&mem_ptr_2);
        AVK_LOG_FUN(med_free_ext_mem, (mem_ptr_2 == NULL));
    }
    else
        AVK_LOG_FUN(med_free_ext_mem, AVK_NA); 

#endif
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
/* under construction !*/
#endif



AVK_ASYN_CASE(AVK_PLUTO_MEM_AUTO_01, AVK_PLUTO_MEM_AUTO)
{
    vs_fw_mem_01();
}

AVK_ASYN_CASE(AVK_PLUTO_MEM_AUTO_02, AVK_PLUTO_MEM_AUTO)
{
    vs_fw_mem_02();
}

AVK_ASYN_CASE(AVK_PLUTO_MEM_AUTO_03, AVK_PLUTO_MEM_AUTO)
{
    vs_fw_mem_03();
}


AVK_CASE(AVK_PLUTO_MEM_AUTO_04, AVK_PLUTO_MEM_AUTO)
{
    vs_med_mem();
}

/* fw memory -e */

