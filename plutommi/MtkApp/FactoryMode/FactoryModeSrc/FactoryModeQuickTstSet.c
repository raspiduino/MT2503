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
 * FactoryModeAutoTestSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is Factory Mode
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
     
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */


#include "MMI_features.h"
          
#ifdef __MMI_FACTORY_MODE__    
     
#include "MMI_features.h"
#include "MMIDataType.h"
#include "ps_public_struct.h"
#include "wgui_touch_screen.h"
#include "nvram_data_items.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#ifdef __MMI_EM_MISC_MMI_DEBUG__
#include "DebugInitDef_Int.h"
#endif
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "device.h"
#include "stack_msgs.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "custom_em.h"
#include "CustDataRes.h"
#include "wgui_include.h"
#include "mmi_frm_input_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "wgui_categories.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "CustDataProts.h"
#include "wgui_inline_edit.h"
#include "stdlib.h"
#include "ImeGprot.h"
#include "CommonScreens.h"
#include "init.h"
#include "med_api.h"
#include "CallSetSrvGprot.h"
     
#include "EngineerModeAppResDef.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
//#include "EngineerModeMisc.h"
#include "EngineerModeMultimedia.h"
#include "EngineerModeDM.h"
     
//#include "FactoryModeDef.h"
#include "FactoryModeProt.h"
#include "menucuigprot.h"
     
#ifdef __J2ME__
#include "mmi_rp_app_java_def.h"
#endif
     
//#include "mmi_rp_app_engineermode1_def.h"

#include "mmi_rp_app_factorymode_def.h"
     
#include "inlinecuigprot.h"
#if defined(__MMI_EM_MISC_TOUCH_SCREEN__)
#include "EngineerModeTouchPanel.h"
#endif /*defined(__MMI_EM_MISC_TOUCH_SCREEN__)*/
     
#ifdef __MMI_EM_MISC_MULTI_TOUCH__
#include "vadp_p2v_multi_touch_test.h"
#endif

#define NVRAMITEM_ALREADYHAS        0
#define NVRAMITEM_INSERT_SUCCESS    1

 /* Auto Testing Settings */
 S32 g_fm_PriorityValue = 0;
 S16 g_fm_AutoTestListSize = 0;
 U16 g_fm_HiliteAutoTestCurrSelIdx = 0;
 U16 g_fm_HiliteAllTestListIdx = 0;
 U16 g_fm_newPriority = 0;
 AutoTestItemArray g_fm_nvramTestItemArray;
 AutoTestResultArray g_fm_nvramTestResultArray;
 rtc_format_struct g_fm_myclocktime;
 PS8 g_fm_AutoTestSelectedItems[MAX_AUTO_TEST_ITEMS];
 
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
 static void mmi_fm_auto_test_tap_handler(mmi_tap_type_enum tap_type, S32 index);
#endif


 /* Profile */
 extern const testlet Tests[MAX_AUTO_TEST_ITEMS];




 #define FM_MISC_AUTO_TEST
/*-----------------------------------------------------------------------------*/
/*---------------------------------- Auto test --------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_FM_AUTO_TEST__


static MMI_RET mmi_fm_misc_auto_test_setting_option_proc(mmi_event_struct *evt);
static void mmi_fm_misc_auto_test_setting_entry_option(void);

static void mmi_fm_misc_entry_item_priority_scr(void);
static MMI_RET mmi_fm_misc_auto_test_confirm_proc(mmi_event_struct *evt);


extern MMI_ID g_fm_gourp_id;
MMI_ID mmi_fm_get_root_group(void)
{
    return g_fm_gourp_id;
}

CHAR name[MAX_AUTO_TEST_ITEMS][MAX_TEST_ITEM_NAME_LEN *ENCODING_LENGTH] = {0};



/*****************************************************************************
 * FUNCTION
 *  GetSelectedTestList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_fm_GetSelectedTestList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, testitem;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_ReadSettingsFromNVRAM(FM_SETTINGINFO);

    if (g_fm_AutoTestListSize > MAX_AUTO_TEST_ITEMS)
    {
        g_fm_AutoTestListSize = MAX_AUTO_TEST_ITEMS;
    }
    for (count = 0; count < g_fm_AutoTestListSize; count++, index++)
    {
        testitem = g_fm_nvramTestItemArray.priority[count];

         kal_wsprintf((WCHAR *)name[count],"%s", (CHAR*) Tests[testitem].name);

        g_fm_AutoTestSelectedItems[count] = name[count];
    }
    return count;
}


#define SET_AUTO_TEST_TIME(dest, res) \
        memcpy((dest), (rtc_format_struct*)&((res)->rtc_sec), sizeof(rtc_format_struct))
        

#define GET_AUTO_TEST_TIME(dest, res) \
        memcpy((rtc_format_struct*)&((dest)->rtc_sec), (res), sizeof(rtc_format_struct))
       

static S32 mmi_fm_misc_auto_test_update_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // nvram_ef_autotest_struct testdata;
	nvram_ef_quicktest_struct testdata2;
		
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&testdata2, 0, sizeof(testdata2));
    testdata2.testcount = g_fm_nvramTestItemArray.count;
    for (i = 0; i < testdata2.testcount; i++)
    {
        testdata2.testlist[i] = g_fm_nvramTestItemArray.priority[i];
    }
    GET_AUTO_TEST_TIME(&testdata2, &g_fm_myclocktime);
    return WriteRecordSlim(NVRAM_EF_QUICKTEST_LID, 1, &testdata2, NVRAM_EF_QUICKTEST_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  WriteTestResultToNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_WriteTestResultToNVRAM(void)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
   // nvram_ef_autotest_struct testdata;
	nvram_ef_quicktest_struct testdata2;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&testdata2, 0, sizeof(testdata2));

    testdata2.testcount = g_fm_AutoTestListSize;
    for (i = 0; i < testdata2.testcount; i++)
    {
        testdata2.testlist[i] = g_fm_nvramTestResultArray.result[i];
    }

    WriteRecordSlim(NVRAM_EF_QUICKTEST_LID, 2, &testdata2, NVRAM_EF_QUICKTEST_SIZE);

#endif /* defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ReadTimeFromNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_ReadTimeFromNVRAM(void)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  nvram_ef_autotest_struct testdata;
	nvram_ef_quicktest_struct testdata2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    memset(&testdata, 0, sizeof(testdata));
    ReadRecordSlim(NVRAM_EF_QUICKTEST_LID, 1, &testdata2, NVRAM_EF_QUICKTEST_SIZE);

    SET_AUTO_TEST_TIME(&g_fm_myclocktime, &testdata2);
#endif /* defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  WriteCurrentTimeToNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_WriteCurrentTimeToNVRAM(void)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  nvram_ef_autotest_struct testdata;
	nvram_ef_quicktest_struct testdata2;
	

    MYTIME t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    memset(&testdata, 0, sizeof(testdata));
    ReadRecordSlim(NVRAM_EF_QUICKTEST_LID, 1, &testdata2, NVRAM_EF_QUICKTEST_SIZE);

    DTGetRTCTime(&t);

    GET_AUTO_TEST_TIME(&testdata2,&t);
    
    testdata2.rtc_wday = 0;
    testdata2.rtc_year = (kal_uint8) (t.nYear - 2000);

    WriteRecordSlim(NVRAM_EF_QUICKTEST_LID, 1, &testdata2, NVRAM_EF_QUICKTEST_SIZE);
   
#endif /* ( defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ReadSettingsFromNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_ReadSettingsFromNVRAM(U8 Type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    U32 i = 1;
	nvram_ef_quicktest_struct testdata2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&testdata2, 0, sizeof(testdata2));
    if(FM_SETTINGINFO == Type)
    {
        i = 1;
    }
    else if(FM_RESULTINFO == Type)
    {
        i = 2;
    }
    else
    {
        return;
    }

    ReadRecordSlim(NVRAM_EF_QUICKTEST_LID, i, &testdata2, NVRAM_EF_QUICKTEST_SIZE);

    if(FM_SETTINGINFO == Type)
    {
        g_fm_nvramTestItemArray.count = testdata2.testcount;
        g_fm_AutoTestListSize = g_fm_nvramTestItemArray.count;
        SET_AUTO_TEST_TIME(&g_fm_myclocktime, &testdata2);
    }
    else
    {
        g_fm_nvramTestResultArray.count = testdata2.testcount;
    }

    for (i = 0; i < testdata2.testcount; i++)
    {
        if(FM_SETTINGINFO == Type)
        {
            g_fm_nvramTestItemArray.priority[i] = testdata2.testlist[i];
        }
        else if(FM_RESULTINFO == Type)
        {
             g_fm_nvramTestResultArray.result[i] =
            (FM_AUTO_TEST_RESULT_ENUM)((testdata2.testlist[i] < FM_TEST_PASSED) ? testdata2.testlist[i] : FM_TEST_PASSED);
        }       
    }
    
#endif /* (defined(__MTK_TARGET__)) */ 
}
void mmi_frm_SaveNewIntemToNVRAM_Popup(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 stringID = 0;
    mmi_event_notify_enum warningID = MMI_EVENT_DEFAULT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NVRAMITEM_ALREADYHAS == type)
    {
        stringID = STR_GLOBAL_UNFINISHED;
        warningID = MMI_EVENT_WARNING;
    }
    else if(NVRAMITEM_INSERT_SUCCESS == type)
    {
        stringID = STR_GLOBAL_DONE;
        warningID = MMI_EVENT_SUCCESS;
    }
    
    mmi_popup_display_simple_ext(stringID, warningID, mmi_fm_get_root_group(), NULL);
    mmi_frm_scrn_close(mmi_fm_get_root_group(), SCR_ID_FM_AUTO_TEST_ENTER_PRIORITY);
	if (mmi_frm_scrn_is_present(mmi_fm_get_root_group(), SCR_ID_FM_MISC_AUTO_TEST_ADD, MMI_FRM_NODE_ALL_FLAG))
	{
	    mmi_frm_scrn_close(mmi_fm_get_root_group(), SCR_ID_FM_MISC_AUTO_TEST_ADD);
	} 
}


/*****************************************************************************
 * FUNCTION
 *  SaveNewItemToNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_SaveNewItemToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 p_val = g_fm_PriorityValue - 1; /* convert to 0-based */
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_fm_AutoTestListSize; i++)
        if (g_fm_nvramTestItemArray.priority[i] == g_fm_HiliteAllTestListIdx)    /* the item is already in the list */
        {
            /* pop up warning */            
            mmi_frm_SaveNewIntemToNVRAM_Popup(NVRAMITEM_ALREADYHAS);
            return;
        }

    g_fm_AutoTestListSize += 1;
    g_fm_nvramTestItemArray.count = (U8) g_fm_AutoTestListSize;

    /* Shift the list */
    for (i = g_fm_AutoTestListSize - 1; i > p_val; i--)
    {
        g_fm_nvramTestItemArray.priority[i] = g_fm_nvramTestItemArray.priority[i - 1];
    }

    g_fm_nvramTestItemArray.priority[p_val] = (U8) g_fm_HiliteAllTestListIdx;

#if defined(__MTK_TARGET__)
    {
        mmi_fm_misc_auto_test_update_nvram();
        mmi_frm_SaveNewIntemToNVRAM_Popup(NVRAMITEM_INSERT_SUCCESS);
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}


void mmi_fm_success_popup()
{
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, mmi_fm_get_root_group(), NULL);
    mmi_frm_scrn_close(mmi_fm_get_root_group(), SCR_ID_FM_MISC_AUTO_TEST_CHANGE_PRIORITY);
}


/*****************************************************************************
 * FUNCTION
 *  SavePriorityChangeToNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_SavePriorityChangeToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 new_pri = g_fm_PriorityValue - 1;           /* convert to 0-based */
    U16 old_pri = g_fm_HiliteAutoTestCurrSelIdx;    /* 0-based */
    U16 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_pri == old_pri) /* the priority is the same */
    {
        mmi_fm_success_popup();       
        return;
    }

    /* Switch the items of new_pri and old_pri */
    temp = g_fm_nvramTestItemArray.priority[new_pri];
    g_fm_nvramTestItemArray.priority[new_pri] = g_fm_nvramTestItemArray.priority[old_pri];
    g_fm_nvramTestItemArray.priority[old_pri] = (U8) temp;

#if defined(__MTK_TARGET__)
    {
        mmi_fm_misc_auto_test_update_nvram();
        mmi_fm_success_popup();
    }
#endif /* (  defined(__MTK_TARGET__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  SaveRemoveItemToNVRAM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_SaveRemoveItemToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 p_val = g_fm_HiliteAutoTestCurrSelIdx;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_AutoTestListSize -= 1;
    g_fm_nvramTestItemArray.count = (U8) g_fm_AutoTestListSize;

    /* Shift the list */
    for (i = p_val; i < g_fm_AutoTestListSize && i < MAX_AUTO_TEST_ITEMS; i++)
    {
        g_fm_nvramTestItemArray.priority[i] = g_fm_nvramTestItemArray.priority[i + 1];
    }

#if defined(__MTK_TARGET__)
    {
        mmi_fm_misc_auto_test_update_nvram();
        //mmi_em_success_popup();
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, mmi_fm_get_root_group(), NULL);
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}

void mmi_fm_display_confirm(MMI_STR_ID title_id, MMI_ID group_id, mmi_event_notify_enum event_type, mmi_proc_func callback)
{
    
    mmi_confirm_property_struct arg;

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = callback;
    arg.parent_id = group_id;
    arg.f_auto_map_empty_softkey =  MMI_FALSE;

    mmi_confirm_display_ext(title_id, event_type, &arg);
}


static MMI_RET mmi_fm_misc_auto_test_confirm_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
    if(MMI_ALERT_CNFM_YES == alert->result)
    {
        mmi_fm_SaveRemoveItemToNVRAM();
    }
    return MMI_RET_OK;
}

static MMI_RET mmi_fm_misc_auto_test_entry_item_priority_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            PU8 guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_fm_get_root_group(),
                                     SCR_ID_FM_AUTO_TEST_ENTER_PRIORITY);
            g_fm_PriorityValue = g_fm_AutoTestListSize + 1;
            ShowCategory87Screen(
                                STR_ID_FM_AUTO_TEST_ENTER_PRIORITY,
                                ///EM_AUTO_TEST_ENTER_PRIORITY_ICON,
                                0,
                                STR_GLOBAL_OK,
                                IMG_GLOBAL_OK,
                                STR_GLOBAL_BACK,
                                IMG_GLOBAL_BACK,
                                1,
                                (S32) (g_fm_AutoTestListSize + 1),
                                (S32*) & g_fm_PriorityValue,
                                guiBuffer);
            break;
        }

        case EVT_ID_WGUI_LSK_CLICK:
            mmi_fm_SaveNewItemToNVRAM();
            return MMI_RET_KEY_HANDLED;

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_misc_entry_item_priority_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_misc_entry_item_priority_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_fm_get_root_group(),
                SCR_ID_FM_AUTO_TEST_ENTER_PRIORITY,
                mmi_fm_misc_auto_test_entry_item_priority_proc,
                NULL);
}



static MMI_RET mmi_fm_misc_auto_test_change_item_priority_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            PU8 guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_fm_get_root_group(), 
                                                    SCR_ID_FM_MISC_AUTO_TEST_CHANGE_PRIORITY);                
            g_fm_PriorityValue = g_fm_HiliteAutoTestCurrSelIdx + 1;
            ShowCategory87Screen(
                                STR_ID_FM_AUTO_TEST_ENTER_PRIORITY,
                                //EM_AUTO_TEST_ENTER_PRIORITY_ICON,
                                0,
                                STR_GLOBAL_OK,
                                IMG_GLOBAL_OK,
                                STR_GLOBAL_BACK,
                                IMG_GLOBAL_BACK,
                                1,
                                (S32) g_fm_AutoTestListSize,
                                (S32*) & g_fm_PriorityValue,
                                guiBuffer);            
            break;
        }

        case EVT_ID_WGUI_LSK_CLICK:
            mmi_fm_SavePriorityChangeToNVRAM();
            return MMI_RET_KEY_HANDLED;

        default:
            break;
    }
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_auto_test_get_all_test_item_list_scrn_proc
 * DESCRIPTION
 *  mmi_em_misc_auto_test_get_all_test_item_list_scrn_proc
 * PARAMETERS
 *  param       [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_fm_misc_auto_test_get_all_test_item_list_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                PS8 testItemList[MAX_AUTO_TEST_ITEMS];
                U32 index;
                mmi_frm_scrn_active_evt_struct *evt = (mmi_frm_scrn_active_evt_struct *)param;
                for (index = 0; index < MAX_AUTO_TEST_ITEMS; index++)
                {
                    kal_wsprintf((WCHAR *)name[index],"%s", (CHAR*) Tests[index].name);
                    testItemList[index] = name[index];
                }
                ShowCategory6Screen(
                    STR_ID_FM_AUTO_TEST_ADD,
                    0,
                    STR_GLOBAL_OK,
                    IMG_GLOBAL_OK,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    MAX_AUTO_TEST_ITEMS,
                    (U8**)testItemList,
                    NULL,
                    0,
                    evt->gui_buffer);
                break;
            }         
            

        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
            {
                cat_evt_struct *evt = (cat_evt_struct *)param;
                g_fm_HiliteAllTestListIdx = (U16)(evt->item_index);            
                break;
            }
        
        case EVT_ID_WGUI_LSK_CLICK:
            mmi_fm_misc_entry_item_priority_scr();
            return MMI_RET_KEY_HANDLED;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_auto_test_setting_proc
 * DESCRIPTION
 *  mmi_em_misc_auto_test_setting_proc
 * PARAMETERS
 *  param       [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_fm_misc_auto_test_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            PU8 guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_fm_get_root_group(), 
                                            SCR_ID_FM_MISC_AUTO_TEST_SETTING);
            mmi_fm_GetSelectedTestList();
    
            if (!g_fm_AutoTestListSize)
            {
                g_fm_AutoTestSelectedItems[0] = GetString(STR_GLOBAL_EMPTY);
            }	
        	ShowCategory6Screen(
        		STR_ID_FM_MISC_AUTO_TEST_SETTING,
        		0,
        		STR_GLOBAL_OPTIONS,
        		IMG_GLOBAL_OPTIONS,
        		STR_GLOBAL_BACK,
        		IMG_GLOBAL_BACK,
        		g_fm_AutoTestListSize,
        		(U8**)g_fm_AutoTestSelectedItems,
        		NULL,
        		0,
        		guiBuffer);
        #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
            wgui_register_tap_callback(mmi_fm_auto_test_tap_handler);
        #endif            
            break;
        }

        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *evt = (cat_evt_struct *)param;
            g_fm_HiliteAutoTestCurrSelIdx = (U16)evt->item_index;
            break;
        }            

        case EVT_ID_WGUI_LSK_CLICK:
            mmi_fm_misc_auto_test_setting_entry_option();
            return MMI_RET_KEY_HANDLED;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmAutoTestSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_auto_test_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_fm_get_root_group(), 
                       SCR_ID_FM_MISC_AUTO_TEST_SETTING,
		               mmi_fm_misc_auto_test_setting_proc,
		                NULL);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_em_auto_test_tap_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
static void mmi_fm_auto_test_tap_handler(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        g_fm_HiliteAutoTestCurrSelIdx = (U16) index;
    }    
    else if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_fm_misc_auto_test_setting_entry_option();
    }
}
#endif

static void mmi_fm_misc_auto_test_setting_entry_option(void)
{
    MMI_ID gid;

    gid = mmi_frm_group_create_ex(mmi_fm_get_root_group(),
                                GRP_ID_AUTO_GEN,
                                mmi_fm_misc_auto_test_setting_option_proc,
                                NULL,
                                MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_menu_create_and_run(gid, CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_FM_AUTO_TEST_OPTIONS,
        MMI_TRUE,
        NULL);
}

static MMI_RET mmi_fm_misc_auto_test_setting_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    mmi_ret ret = MMI_RET_OK;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)evt;
    if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)
	{
	    switch(menu_evt->highlighted_menu_id)
		{
		case MENU_ID_FM_AUTO_TEST_ADD:		
            mmi_frm_scrn_create(mmi_fm_get_root_group(),
                        SCR_ID_FM_MISC_AUTO_TEST_ADD,
                        mmi_fm_misc_auto_test_get_all_test_item_list_scrn_proc,
                        NULL);   
			break;

		case MENU_ID_FM_AUTO_TEST_CHANGE_PRIORITY:
			mmi_frm_scrn_create(mmi_fm_get_root_group(), 
		                SCR_ID_FM_MISC_AUTO_TEST_CHANGE_PRIORITY, 
		                mmi_fm_misc_auto_test_change_item_priority_proc,
		                NULL);
			break;

		case MENU_ID_FM_AUTO_TEST_REMOVE:
            mmi_fm_display_confirm(STR_GLOBAL_DELETE, mmi_fm_get_root_group(),
                        MMI_EVENT_WARNING,
                        mmi_fm_misc_auto_test_confirm_proc);
			break;
			
		default:
			break;
		}
	}	
    else if (EVT_ID_CUI_MENU_CLOSE_REQUEST == menu_evt->evt_id)
    {
        cui_menu_close(menu_evt->sender_id);
    }    
    else if (EVT_ID_CUI_MENU_LIST_ENTRY == menu_evt->evt_id)
    {
        if (0 == g_fm_AutoTestListSize)
        {
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_FM_AUTO_TEST_REMOVE, MMI_TRUE);
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_FM_AUTO_TEST_CHANGE_PRIORITY, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_FM_AUTO_TEST_REMOVE, MMI_FALSE);
            cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_FM_AUTO_TEST_CHANGE_PRIORITY, MMI_FALSE);
        }
    }
	return MMI_RET_OK;	
}
#endif /*__MMI_FM_AUTO_TEST__*/


#endif

#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */

