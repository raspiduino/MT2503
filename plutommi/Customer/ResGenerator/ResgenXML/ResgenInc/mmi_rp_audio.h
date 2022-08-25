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
*  mmi_rp_audio.h
*
* Project:
* --------
*   Resgen XML header file of audio resource
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_AUDIO_H
#define RESXML_AUDIO_H


#include "MMIDataType.h"

#if defined(__MMI_FRM_INPUT_EVT__)
#define MMI_RP_MGR_ATTR_AUD_PATH "path"
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

typedef enum
{
    MMI_RP_AUD_FORCE_TYPE_NONE,
    MMI_RP_AUD_FORCE_TYPE_AUTO,
    MMI_RP_AUD_FORCE_TYPE_MIDI,
    MMI_RP_AUD_FORCE_TYPE_TOTAL
}mmi_rp_aud_force_type_enum;

typedef struct
{
    U8 *aud_id_str;
    U8 *aud_desc_str;
    U8 *format;
    U8 *file_path;
#if defined(__MMI_FRM_INPUT_EVT__)
    U8 *aud_path;//record aud real path
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/    
    MMI_BOOL is_theme;
    MMI_BOOL filter;                         /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
    mmi_rp_aud_force_type_enum force_type;   /* "AUTO_ADO_TYPE", "FORCE_ADO_MIDI" */
    mmi_rp_flag_bin_enum flag;               /* Multi/single bin */
}mmi_rp_aud_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_aud_id_struct *audios;
}mmi_rp_aud_data_struct;

typedef struct
{
    mmi_rp_aud_data_struct *app_aud_data;
    mmi_rp_hash_struct *id_hash;
    mmi_rp_hash_struct *file_path_hash;
}mmi_rp_aud_cntx_struct;

extern void mmi_rp_aud_init(void);
extern void mmi_rp_aud_deinit(void);
extern void mmi_rp_aud_set_app_range(void);

extern int mmi_rp_aud_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_aud_end_handler(void *data, const kal_char *el);
extern int mmi_rp_aud_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_aud_filter(void);

extern void mmi_rp_aud_output_phase1(void);
extern void mmi_rp_aud_output_phase2(void);

#endif /* RESXML_AUDIO_H */
