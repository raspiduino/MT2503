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
*  mmi_rp_cust_input_event.h
*
* Project:
* --------
*   Template of Resgen XML header file
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
 * removed!
 *
 * removed!
 *
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_CUST_INPUT_EVENT_H
#define MMI_RP_CUST_INPUT_EVENT_H

//#if defined(__MMI_FRM_INPUT_EVT__)

/* Define your Tag here */
#define MMI_RP_NOTIFY_TAG "NOTIFY"
#define MMI_RP_INPUT_EVENT_TAG "INPUT_EVENT"
#define MMI_RP_APP_INFO_TAG "APP_INFO"

///TODO: define your tag here
/*notify data structure*/
typedef struct
{
    U8 *notify_id_str;
	U8 *notify_desc_str;
    U8 *led_id_str;
	U8 *voice_id_str;
	U8 *vib_id_str;
}mmi_rp_notify_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_notify_struct *notify_strings;
}mmi_rp_notify_data_struct;

typedef struct
{
    mmi_rp_notify_data_struct *app_notify_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_notify_cntx_struct;

/*input event*/
typedef struct
{
    U8 *grp_id_str;
	U8 *grp_desc_str;
    U8 *evt_id_str;
	U8 *evt_desc_str;
	U8 *key_code_str;
	U8 *key_type_str;
}mmi_rp_input_event_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_input_event_struct *input_event_strings;
}mmi_rp_input_event_data_struct;

typedef struct
{
    mmi_rp_input_event_data_struct *app_input_event_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_input_event_cntx_struct;

/*app info*/
typedef struct
{
    U8 *app_indx_str;
    U8 *grp_id_str;
	U8 *launch_evt_str;
}mmi_rp_app_info_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_app_info_struct *app_info_strings;
}mmi_rp_app_info_data_struct;

typedef struct
{
    mmi_rp_app_info_data_struct *app_info_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_app_info_cntx_struct;


#if defined(__MMI_FRM_INPUT_EVT__)

/*notify handler*/
extern void mmi_rp_notify_init(void);
extern void mmi_rp_notify_set_app_range(void);

extern int mmi_rp_notify_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_notify_end_handler(void *data, const kal_char *el);
extern int mmi_rp_notify_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_notify_filter(void);

extern void mmi_rp_notify_output_phase1(void);
extern void mmi_rp_notify_output_phase2(void);

/*input event handler*/
extern void mmi_rp_input_event_init(void);
extern void mmi_rp_input_event_set_app_range(void);

extern int mmi_rp_input_event_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_input_event_end_handler(void *data, const kal_char *el);
extern int mmi_rp_input_event_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_input_event_filter(void);

extern void mmi_rp_input_event_output_phase1(void);
extern void mmi_rp_input_event_output_phase2(void);

/*app info handler*/
extern void mmi_rp_app_info_init(void);
extern void mmi_rp_app_info_set_app_range(void);

extern int mmi_rp_app_info_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_app_info_end_handler(void *data, const kal_char *el);
extern int mmi_rp_app_info_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_app_info_filter(void);

extern void mmi_rp_app_info_output_phase1(void);
extern void mmi_rp_app_info_output_phase2(void);
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

#endif /* MMI_RP_CUST_TEMPLATE_H */
