/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  mmi_rp_res_list.h
*
* Project:
* --------
*   Resgen XML
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_CUST_RES_LIST_H
#define MMI_RP_CUST_RES_LIST_H

#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"

#include "mmi_rp_cust_template.h"  /* header file of timer resource */
///TODO: Add your resource's headher here
#include "mmi_rp_file_type.h"
#ifdef __COSMOS_MMI__
#include "mmi_rp_venus_xml.h"
#endif
#include "mmi_rp_callback_mgr.h"
#include "mmi_rp_mmi_cache.h"
#include "mmi_rp_third_rom.h"

//#if defined(__MMI_FRM_INPUT_EVT__)
//huking
#include "mmi_rp_cust_input_event.h"

mmi_rp_mgr_tag_callback g_res_tag_handlers_cust[] = {

    /*----------------------------Template tags start----------------------------*/
    /* Tag TEMPLATE callback functions*/
    {
        MMI_RP_MGR_TAG_TEMPLATE,           /* TAG Name */
        mmi_rp_template_start_handler,     /* Tag start callback */
        mmi_rp_template_end_handler,       /* Tag end callback */
        mmi_rp_template_data_handler       /* Tag data callback */
    },
    /*----------------------------Template tags End----------------------------*/


    ///TODO: Add your resource's tags here
   {
        MMI_RP_CB_MGR_SENDER_TAG,
        mmi_rp_callback_mgr_sender_start_handler,
        mmi_rp_callback_mgr_sender_end_handler,
        NULL
    },
    {
        MMI_RP_CB_MGR_RECIEVER_TAG,
        mmi_rp_callback_mgr_reciever_start_handler,
        mmi_rp_callback_mgr_reciever_end_handler,
        NULL
    },

    {
        MMI_RP_CB_MGR_RECIEVER_TAG_OLD,
        mmi_rp_callback_mgr_reciever_start_handler,
        mmi_rp_callback_mgr_reciever_end_handler,
        NULL
    },



    {MMI_RP_MGR_TAG_FILE_TYPE_BASE,
        mmi_rp_fts_start_handler,
        mmi_rp_fts_end_handler,
        NULL},
    {MMI_RP_MGR_TAG_FILE_TYPE_INC,
        mmi_rp_file_type_inc_start_handler,
        mmi_rp_file_type_inc_end_handler,
        NULL},
    {MMI_RP_MGR_TAG_FILE_GROUP_TYPE,
        mmi_rp_file_group_type_start_handler,
        mmi_rp_file_group_type_end_handler,
        NULL},
    {MMI_RP_MGR_TAG_FILE_TYPE,
        mmi_rp_file_type_start_handler,
        mmi_rp_file_type_end_handler,
        NULL},
    {MMI_RP_MGR_TAG_FILE_TYPE_DEC,
        mmi_rp_file_type_dec_start_handler,
        mmi_rp_file_type_dec_end_handler,
        NULL},
    {MMI_RP_MGR_TAG_FILE_OPTION_HDLR,
        mmi_rp_file_opt_hdlr_start_handler,
        mmi_rp_file_opt_hdlr_end_handler,
        NULL},
#ifdef __COSMOS_MMI__
    {MMI_RP_MGR_TAG_VENUS_LAYOUT,
        mmi_rp_venus_layout_start_handler,
        mmi_rp_venus_layout_end_handler,
        NULL},
#endif
    {
        MMI_RP_MMI_CACHE_TAG_CACHEDATA,
        mmi_rp_mmi_cache_start_handler,
        mmi_rp_mmi_cache_end_handler,
        NULL
    },
    {
        MMI_RP_MMI_CACHE_TAG_DEFAULT_VALUE,
        mmi_rp_mmi_cache_default_value_start_handler,
        mmi_rp_mmi_cache_default_value_end_handler,
        mmi_rp_mmi_cache_default_value_data_handler
    },
    {
        MMI_RP_MMI_CACHE_TAG_DESCRIPTION,
        mmi_rp_mmi_cache_description_start_handler,
        mmi_rp_mmi_cache_description_end_handler,
        mmi_rp_mmi_cache_description_data_handler
    },
    {
        MMI_RP_MMI_CACHE_TAG_FIELD,
        mmi_rp_mmi_cache_field_start_handler,
        mmi_rp_mmi_cache_field_end_handler,
        mmi_rp_mmi_cache_field_data_handler
    },
    {
        MMI_RP_MMI_CACHE_TAG_OPTION,
        mmi_rp_mmi_cache_option_start_handler,
        mmi_rp_mmi_cache_option_end_handler,
        mmi_rp_mmi_cache_option_data_handler
    },
    {
        MMI_RP_MMI_CACHE_TAG_MINIMUM,
        mmi_rp_mmi_cache_minimum_start_handler,
        mmi_rp_mmi_cache_minimum_end_handler,
        mmi_rp_mmi_cache_minimum_data_handler
    },
    {
        MMI_RP_MMI_CACHE_TAG_MAXIMUM,
        mmi_rp_mmi_cache_maximum_start_handler,
        mmi_rp_mmi_cache_maximum_end_handler,
        mmi_rp_mmi_cache_maximum_data_handler
    },

    {
        MMI_RP_MMI_CACHE_TAG_MORETHAN,
        mmi_rp_mmi_cache_morethan_start_handler,
        mmi_rp_mmi_cache_morethan_end_handler,
        mmi_rp_mmi_cache_morethan_data_handler
    },

    {
        MMI_RP_MMI_CACHE_TAG_LESSTHAN,
        mmi_rp_mmi_cache_lessthan_start_handler,
        mmi_rp_mmi_cache_lessthan_end_handler,
        mmi_rp_mmi_cache_lessthan_data_handler
    },

	{
		MMI_RP_THIRDROM_TAG,
		mmi_rp_thirdrom_start_handler,
		mmi_rp_thirdrom_end_handler,
		mmi_rp_thirdrom_data_handler
	},
#if defined(__MMI_FRM_INPUT_EVT__)
	//huking
	{
        MMI_RP_NOTIFY_TAG,           /* TAG Name */
        mmi_rp_notify_start_handler,     /* Tag start callback */
        mmi_rp_notify_end_handler,       /* Tag end callback */
        mmi_rp_notify_data_handler       /* Tag data callback */
    },

	{
        MMI_RP_INPUT_EVENT_TAG,           /* TAG Name */
        mmi_rp_input_event_start_handler,     /* Tag start callback */
        mmi_rp_input_event_end_handler,       /* Tag end callback */
        mmi_rp_input_event_data_handler       /* Tag data callback */
    },

	{
        MMI_RP_APP_INFO_TAG,           /* TAG Name */
        mmi_rp_app_info_start_handler,     /* Tag start callback */
        mmi_rp_app_info_end_handler,       /* Tag end callback */
        mmi_rp_app_info_data_handler       /* Tag data callback */
    },
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/		
    /*-------------------Add Res Before this line--------------------------*/
    {MMI_RP_MGR_TAG_END, NULL, NULL, NULL}
};


mmi_rp_mgr_cust_res_callback g_res_handlers_cust[] = {

    /* Tag Template callback functions*/
    {
        mmi_rp_template_init,
        mmi_rp_template_set_app_range,
        mmi_rp_template_filter,
        mmi_rp_template_output_phase1,
        mmi_rp_template_output_phase2
    },

    ///TODO: add your Resource callback function here
    {
        mmi_rp_file_type_init,
        mmi_rp_file_type_set_app_range,
        mmi_rp_file_type_filter,
        mmi_rp_file_type_output_phase1,
        mmi_rp_file_type_output_phase2
    },
#ifdef __COSMOS_MMI__
    {
        mmi_rp_vxml_init,
        mmi_rp_vxml_set_app_range,
        mmi_rp_vxml_filter,
        mmi_rp_vxml_output_phase1,
        mmi_rp_vxml_output_phase2
    },
#endif
    {
        mmi_rp_callback_mgr_init,
        mmi_rp_callback_mgr_set_app_range,
        mmi_rp_callback_mgr_filter,
        mmi_rp_callback_mgr_output_phase1,
        mmi_rp_callback_mgr_output_phase2
    },

    {
        mmi_rp_mmi_cache_init,
        mmi_rp_mmi_cache_set_app_range,
        mmi_rp_mmi_cache_filter,
        mmi_rp_mmi_cache_output_phase1,
        mmi_rp_mmi_cache_output_phase2
    },

	{
	    mmi_rp_thirdrom_init,
	    mmi_rp_thirdrom_set_app_range,
	    mmi_rp_thirdrom_filter,
	    mmi_rp_thirdrom_output_phase1,
	    mmi_rp_thirdrom_output_phase2
    },
#if defined(__MMI_FRM_INPUT_EVT__)    
	//huking
	{
        mmi_rp_notify_init,
        mmi_rp_notify_set_app_range,
        mmi_rp_notify_filter,
        mmi_rp_notify_output_phase1,
        mmi_rp_notify_output_phase2
    },

	{
        mmi_rp_input_event_init,
        mmi_rp_input_event_set_app_range,
        mmi_rp_input_event_filter,
        mmi_rp_input_event_output_phase1,
        mmi_rp_input_event_output_phase2
    },	

	{
        mmi_rp_app_info_init,
        mmi_rp_app_info_set_app_range,
        mmi_rp_app_info_filter,
        mmi_rp_app_info_output_phase1,
        mmi_rp_app_info_output_phase2
    },	
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/    
    /*-------------------Add Res Before this line--------------------------*/
    {mmi_rp_end_function, mmi_rp_end_function, mmi_rp_end_function, mmi_rp_end_function, mmi_rp_end_function}
};


#endif /* MMI_RP_CUST_RES_LIST_H */
