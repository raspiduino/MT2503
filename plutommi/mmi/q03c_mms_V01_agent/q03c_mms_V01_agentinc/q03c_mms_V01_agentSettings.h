/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  q03c_mms_V01_agentSettings.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * q03c_mms_V01_agentSettings.c
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef Q03C_MMS_V01_AGENT_SETTINGS_H
#define Q03C_MMS_V01_AGENT_SETTINGS_H

#if defined(OBIGO_Q03C_MMS_V01)

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "mea_api.h"
#include "q03c_mms_v01_adp_struct.h"

#ifdef __MMI_WAP_PROF__
#include "WAPProfileType.h"
#include "WAPprovisioningType.h"
#endif /* __MMI_WAP_PROF__ */ 

/*This Macro shoud be insync with the one defined in mea_cfg.h*/
/* if this is on, then can best slide duration option will be enabled */
#if defined(MMS_SUPPORT) && !(defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
#define MMS_BEST_SLIDE_DURATION
#endif
 /* 
 * Define
 */
/*MAX AUTO SIGNATURE LENGTH*/


/*Number of slide timing input characters*/
#define MMSV01_AGENT_MAX_DEFAULT_SLIDE_TIME_INPUT               2

/*Default Slide Duration in mili seconds*/
#define MMSV01_AGENT_DEFAULT_SLIDE_DURATION                     5000 /* /ms */

/*Min slide duration value*/
#define MMSV01_AGENT_MIN_SLIDE_DURATION                         1 /* /ms */

/*Max slide duration value*/
#define MMSV01_AGENT_MAX_SLIDE_DURATION                     99 /* /ms */

/*Default Creation Mode value*/
#define MMSV01_AGENT_DEFAULT_CREATION_MODE                      MEA_CREATION_MODE_RESTRICTED

/*Default Auto Signature Value*/
#define MMSV01_AGENT_DEFAULT_AUTO_SIGNATURE                     E_OFF

/*Default Best page duration value */
#define MMSV01_AGENT_DEFAULT_BEST_PAGE_DURATION                 E_OFF

#ifdef JPG_ENCODE
/*Default Image resizing Value*/
#define MMSV01_AGENT_DEFAULT_IMAGE_RESIZING                     MEA_IMAGE_RESIZE_160x120
#endif

/*Default value for home reterival mode*/
#define MMSV01_AGENT_DEFAULT_HOME_RETRIEVAL_MODE                MEA_RETRIEVAL_MODE_AUTOMATIC


/*Default value for roam reterival mode*/
#define MMSV01_AGENT_DEFAULT_ROAMING_RETRIEVAL_MODE             MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC

/*Default Value for Advertisement Filter*/
#define MMSV01_AGENT_DEFAULT_ADVERTISEMENT_FILTER_VALUE         E_ALLOW

/*Default Value for Anonymous Filter*/
#define MMSV01_AGENT_DEFAULT_ANONYMOUS_FILTER_VALUE             E_ALLOW

/*Default Value for Delivery Report During sending*/
#ifdef __OP01_MMS_RETRIEVE_SETTING__
/* under construction !*/
#else
#define MMSV01_AGENT_DEFAULT_DELIVERY_REPORT_DURING_SENDING     E_ON
#endif

/*Default Value for Delivery Time*/
#define MMSV01_AGENT_DEFAULT_DELIVERY_TIME                      MEA_DELIVERY_TIME_IMMEDIATE //0

#ifdef __MMI_MMS_BGSR_SUPPORT__
/*Default Value for save and send*/
#define MMSV01_AGENT_DEFAULT_SAVE_AND_SEND                      E_OFF
#endif

/*Default Value for Priority*/
#define MMSV01_AGENT_DEFAULT_PRIORITY                           MEA_PRIORITY_NORMAL

/*Default value for validity period*/
#define MMSV01_AGENT_DEFAULT_VALIDITY_PERIOD                    MEA_EXPIRY_MAX


/*Default Value for Read Report During Sending*/
#ifdef __OP01_MMS_RETRIEVE_SETTING__
/* under construction !*/
#else
#define MMSV01_AGENT_DEFAULT_READ_REPORT_DURING_SENDING         E_ON
#endif


/*Default Value for Delivery Report During Reterival*/
#define MMSV01_AGENT_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL   E_OFF

/*Default Value for Read Report*/
#ifdef __OP01_MMS_RETRIEVE_SETTING__
/* under construction !*/
#else
#define MMSV01_AGENT_DEFAULT_READ_REPORT_DURING_RETRIEVAL       MEA_SEND_READ_REPORT_ON_REQUEST
#endif





/* 
 * Typedef 
 */



typedef enum
{
    E_OFF,
    E_ON,
    E_ON_OFF_TOTAL
} mmsV01_off_on_enum;

typedef enum
{
    E_ALLOW,
    E_REJECT,
    E_ALLOW_REJECT_TOTAL
} mmsV01_allow_reject_enum;


typedef enum
{
    E_COMPOSE_CREATION_MODES_CAPTION,
    E_COMPOSE_CREATION_MODES,
    
    E_COMPOSE_IMAGE_RESIZE_CAPTION,
    E_COMPOSE_IMAGE_RESIZING,

    E_COMPOSE_BEST_PAGE_DURATION_CAPTION,
    E_COMPOSE_BEST_PAGE_DURATION,

    E_COMPOSE_AUTO_SIGNATURE_CAPTION,
    E_COMPOSE_AUTO_SIGNATURE,
    E_COMPOSE_AUTO_SIGNATURE_CONTENT_CAPTION,
    E_COMPOSE_AUTO_SIGNATURE_CONTENT,

    COMPOSE_INLINE_TOTAL
} mmsv01_compose_inline_items_enum;



typedef enum
{
    E_SENDING_VALIDITY_PERIOD_CAPTION,
    E_SENDING_VALIDITY_PERIOD,

    E_SENDING_DELIVERY_REPORT_CAPTION,
    E_SENDING_DELIVERY_REPORT,

    E_SENDING_READ_REPORT_CAPTION,
    E_SENDING_READ_REPORT,

    E_SENDING_PRIORITY_CAPTION,
    E_SENDING_PRIORITY,
    
    E_SENDING_DEFAULT_SLIDE_TIME_CAPTION,
    E_SENDING_DEFAULT_SLIDE_TIME,

    E_SENDING_DELIVERY_TIME_CAPTION,
    E_SENDING_DELIVERY_TIME,

    SENDING_INLINE_TOTAL
} mmsv01_sending_inline_items_enum;



typedef enum
{

    E_RETRIEVAL_HOME_NETWORK_CAPTION,
    E_RETRIEVAL_HOME_NETWORK,
    E_RETRIEVAL_ROAMING_CAPTION,
    E_RETRIEVAL_ROAMING,
    
    E_RETRIEVAL_READ_REPORT_CAPTION,
    E_RETRIEVAL_READ_REPORT,
    E_RETRIEVAL_DELIVERY_REPORT_CAPTION,
    E_RETRIEVAL_DELIVERY_REPORT,

    RETRIEVAL_INLINE_TOTAL
} mmsv01_retrieval_inline_items_enum;


typedef enum
{

    E_FILTER_ANONYMOUS_CAPTION,
    E_FILTER_ANONYMOUS,

    E_FILTER_ADVERTISEMENT_CAPTION,
    E_FILTER_ADVERTISEMENT,

    FILTER_INLINE_TOTAL
} mmsv01_filter_inline_items_enum;



typedef enum
{
    E_ENTRY_FROM_MMS_SETTINGS,
    E_ENTRY_FROM_WRITE_MMS
} umms_send_settings_entry_control_enum;

typedef enum
{
    E_SENDING_SIZE_LIMIT_100,
    E_SENDING_SIZE_LIMIT_300,
    E_SENDING_SIZE_LIMIT_600,
    SENDING_SIZE_LIMIT_TOTAL
} umms_sending_size_limit_enum;


typedef struct
{
    U8 validity_period;
    U8 delivery_report;
    U8 read_report;
    U8 priority;
    U8 delivery_time;    
    U8 send_and_save;
    U16 default_slide_time;
} mmsV01_agent_nvram_sending_settings_struct;

/*
typedef struct
{
    U8 home_network;
    U8 roaming;
    U8 read_report;
    U8 delivery_report;
    U8 anonymous_filter;
    U8 advertisement_filter;
 } mmsV01_agent_retrieval_settings_struct;*/
/*
typedef struct
{
    U8 anonymous_filter;
    U8 advertisement_filter;
} mmsV01_agent_nvram_filter_settings_struct;*/

typedef struct
{
    S8 *allow_reject_list[E_ALLOW_REJECT_TOTAL];
    S8 *on_off_list[E_ON_OFF_TOTAL];
} mmsV01_agent_common_inline_lists_struct;

typedef struct
{
    S32 home_network;
    S32 roaming;   
    S32 read_report;
    S32 delivery_report;
    S8 *home_network_list[MEA_RETRIEVAL_MODE_TOTAL]; 
    S8 *roaming_list[MEA_RETRIEVAL_MODE_ROAMING_TOTAL];
    S8 *read_report_list[MEA_SEND_READ_REPORT_TOTAL];
} mmsV01_agent_inline_retrieval_items_struct;

typedef struct
{
    U8 defualt_slide_time_buffer[(MMSV01_AGENT_MAX_DEFAULT_SLIDE_TIME_INPUT + 1) *ENCODING_LENGTH];
    S32 validity_period;
    S32 delivery_report;
    S32 read_report;
    S32 priority;
    S32 delivery_time;
    S32 send_and_save;
    S8 *validity_period_list[MEA_EXPIRY_TOTAL];
    S8 *priority_list[MEA_PRIORITY_TOTAL];
    S8 *delivery_time_list[MEA_DELIVERY_TIME_TOTAL];    
} mmsV01_agent_inline_sending_items_struct;


typedef struct
{    
    S32 creation_mode;
    S32 image_resize_option;
    S32 best_page_duration;
    S32 auto_signature;
    S8 *creation_modes_list[MEA_CREATION_MODE_TOTAL];
    S8 *image_resize_list[MEA_IMAGE_RESIZE_TOTAL];
    U8 auto_signature_content[(MMSV01_AGENT_MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH];
} mmsV01_agent_inline_compose_items_struct;

typedef struct
{    
    S32 anonymous_filter;
    S32 advertisement_filter;   
} mmsV01_agent_inline_filter_items_struct;


typedef union
{
    mmsV01_agent_inline_compose_items_struct compose_items_list;
    mmsV01_agent_inline_sending_items_struct sending_items_list;
    mmsV01_agent_inline_retrieval_items_struct retrieval_items_list;
    mmsV01_agent_inline_filter_items_struct  filter_items_list;
} mmsV01_agent_setings_inline_items_union;



typedef struct
{
    mmsV01_agent_common_inline_lists_struct *mmsv01_inline_lists;
    mmsV01_agent_setings_inline_items_union mmsv01_inline_items;
    mmsV01_agent_compose_settings_struct nvram_compose_settings;
    mmsV01_agent_sending_settings_struct nvram_sending_settings;
    mmsV01_agent_retrieval_settings_struct nvram_retrieval_settings;
   // mmsV01_agent_nvram_filter_settings_struct nvram_filter_settings;
    U16 RSK_str_id;
    U16 body_str_id;
    U16 caption_str_id;
    U16 animation_image_id;
    U8 on_bootup;

#ifdef __MMI_MMS_DUAL_SIM__   
    U8 profile_set_for_sim1;
    U8 profile_set_for_sim2;
#endif
    mmi_wap_prof_response_funcptr_type rsp_callback;
    mmi_wap_prof_response_funcptr_type rsp_OTA_callback;

} mmsV01_agent_setting_context_struct;

/* 
 * Extern Global Variable
 */
/* 
 * Extern Global Function
 */
extern void mmi_mmsv01_agent_settings_init(void);
extern void mmi_mmsv01_agent_read_nvram_settings();
#ifdef __MMI_WAP_PROF__
extern void mmi_mmsv01_set_current_profile_req(void);
#endif /*__MMI_WAP_PROF__*/
extern void mmi_mmsv01_get_settings_req_hdlr(void);
extern void mmi_mmsv01_set_settings_req(void);
extern void mmi_mmsv01_entry_message_settings(void);
extern void mmi_mmsv01_entry_common_settings(void);
extern void mmi_mmsv01_settings_mms_enter_edit_profile(void);
extern void mmi_mmsv01_pre_entry_profile_settings(void);
extern void mmi_mmsv01_highlight_common_mms_settings(void);
extern void mmi_mmsv01_highlight_edit_profile(void);
#ifdef __MMI_MMS_DUAL_SIM__
extern void mmi_mmsv01_settings_mms_enter_edit_profile_for_sim1(void);
extern void mmi_mmsv01_settings_mms_enter_edit_profile_for_sim2(void);
extern void mmi_mmsv01_highlight_mms_setting_sim1(void);
extern void mmi_mmsv01_highlight_mms_setting_sim2(void);
extern void mmi_mmsv01_clear_profile_set_flag(void);
#endif /*__MMI_MMS_DUAL_SIM__*/
extern void mmi_mmsv01_exit_compose_settings(void);
extern void mmi_mmsv01_save_compose_settings(void);
extern void mmi_mmsv01_exit_confirm_screen(void);
extern void mmi_mmsv01_read_back_auto_sign_content(void);
extern void mmi_mmsv01_confirm_save_compose_settings(void);
extern void mmi_mmsv01_compose_settings_highlight_hdlr(S32 index);
extern void mmi_mmsv01_compose_inline_custom_func(void);
extern void mmi_mmsv01_compose_fill_inline_struct(void);
extern void mmi_mmsv01_entry_compose_settings(void);
extern void mmi_mmsv01_pre_entry_compose_settings(void);
extern void mmi_mmsv01_highlight_compose_setings(void);
extern void mmi_mmsv01_entry_sending_settings(void);
extern void mmi_mmsv01_exit_sending_settings(void);
extern void mmi_mmsv01_save_sending_settings(void);
extern void mmi_mmsv01_sending_fill_inline_struct(void);
extern void mmi_mmsv01_confirm_save_sending_settings(void);
#if 0
/* under construction !*/
#endif
extern void mmi_mmsv01_pre_entry_sending_settings(void);
extern void mmi_mmsv01_highlight_sending_setings(void);
extern void mmi_mmsv01_exit_retrieval_settings(void);
extern void mmi_mmsv01_save_retrieval_settings(void);
extern void mmi_mmsv01_retrieval_fill_inline_struct(void);
extern void mmi_mmsv01_confirm_save_retrieval_settings(void);
extern void mmi_mmsv01_retrieval_settings_highlight_hdlr(S32 index);
extern void mmi_mmsv01_entry_retrieval_settings(void);
extern void mmi_mmsv01_pre_entry_retrieval_settings(void);
extern void mmi_mmsv01_highlight_retrieval_setings(void);
extern void mmi_mmsv01_exit_filter_settings(void);
extern void mmi_mmsv01_save_filter_settings(void);
extern void mmi_mmsv01_filter_fill_inline_struct(void);
extern void mmi_mmsv01_confirm_save_filter_settings(void);
extern void mmi_mmsv01_filter_settings_highlight_hdlr(S32 index);
extern void mmi_mmsv01_entry_filter_settings(void);
extern void mmi_umms_pre_entry_filter_settings(void);
extern void mmi_mmsv01_highlight_filter_setings(void);
extern void mmi_mmsv01_entry_memory_status_screen(void);
extern void mmi_mmsv01_highlight_memory_status(void);
extern void mmi_mmsv01_set_profile_rsp_hdlr(void *p);
extern void mmi_mmsv01_deinit_settings_ui(void);
extern kal_uint8 mmi_mmsv01_get_image_resize(void);
extern kal_uint8 mmi_mmsv01_get_creation_mode(void);





#endif


#endif