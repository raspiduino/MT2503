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
*  mmi_rp_image.h
*
* Project:
* --------
*   Resgen XML header file of image resource
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


#ifndef RESXML_IMAGE_H
#define RESXML_IMAGE_H


#include "MMIDataType.h"


#define MMI_RP_IMG_GROUP_ID_MAX 100
#define MMI_RP_IMG_GROUP_IMG_MAX 512

#define MMI_RP_IMG_EMPTYIMAGE_PATH "..\\\\\\\\..\\\\\\\\Customer\\\\\\\\Images\\\\\\\\EmptyImage.bmp"

typedef enum
{
    MMI_RP_IMG_FORCE_TYPE_NONE,
    MMI_RP_IMG_FORCE_TYPE_AUTO,
    MMI_RP_IMG_FORCE_TYPE_ABM,
    MMI_RP_IMG_FORCE_TYPE_AB2,
    MMI_RP_IMG_FORCE_TYPE_BMP,
    MMI_RP_IMG_FORCE_TYPE_ABM_SEQUENCE,
    MMI_RP_IMG_FORCE_TYPE_JPG,
    MMI_RP_IMG_FORCE_TYPE_TOTAL
}mmi_rp_img_force_type_enum;

typedef enum
{
    MMI_RP_IMG_POPULATE_TYPE_IMG,
    MMI_RP_IMG_POPULATE_TYPE_MED,
    MMI_RP_IMG_POPULATE_TYPE_FORCE_IMG,
    MMI_RP_IMG_POPULATE_TYPE_TOTAL
}mmi_rp_img_populate_type_enum;

typedef enum
{
    MMI_RP_IMG_ENFB_TOGGLE_NONE,
    MMI_RP_IMG_ENFB_TOGGLE_SET,
    MMI_RP_IMG_ENFB_TOGGLE_RESET,
    MMI_RP_IMG_ENFB_TOGGLE_TOTAL
}mmi_rp_img_enfb_toggle_enum;

typedef enum
{
    MMI_RP_IMG_SIZE_LIMIT_QVGA,
    MMI_RP_IMG_SIZE_LIMIT_LANDSCAPE,
    MMI_RP_IMG_SIZE_LIMIT_WQVGA,
    MMI_RP_IMG_SIZE_LIMIT_HVGA,
    MMI_RP_IMG_SIZE_LIMIT_TOTAL
}mmi_rp_img_size_limit_enum;

typedef struct
{
    U8 *img_id_str;
    U8 *img_desc_str;
    U8 *format;
    U8 *size_limit[MMI_RP_IMG_SIZE_LIMIT_TOTAL];
    U8 *file_path;
    U8 *img_9slice;
    MMI_BOOL is_theme;
    MMI_BOOL filter;                            /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
    mmi_rp_flag_bin_enum flag;          /* Multi/single bin */
    mmi_rp_scope_enum scope;                    /* XML/None */
    mmi_rp_img_force_type_enum force_type;    /* "ABM" "AB2" "BMP" "ABM_SEQUENCE" */
    S32 quality;
    MMI_BOOL is_compression;
    mmi_rp_img_populate_type_enum poulate_type; 
    mmi_rp_img_enfb_toggle_enum toggle;
}mmi_rp_img_id_struct;

typedef struct
{
    U8 *group_name;
    U8 *img_ids[MMI_RP_IMG_GROUP_IMG_MAX];
    U16 img_count;
}mmi_rp_img_group_struct;

typedef struct
{
    mmi_rp_img_group_struct groups[MMI_RP_IMG_GROUP_ID_MAX];
    U16 group_count;
}mmi_rp_img_group_data_struct;

typedef struct
{
    U32 total_count;
    U32 toggle_count;
    mmi_rp_img_id_struct *images;
    S32 *toggle_index;                          /* Initialized by -1. */
    mmi_rp_img_enfb_toggle_enum last_toggle;
}mmi_rp_img_data_struct;

typedef struct
{
    mmi_rp_img_data_struct *app_img_data;
    mmi_rp_img_group_data_struct group_data;
    mmi_rp_hash_struct *id_hash;
    mmi_rp_hash_struct *file_path_hash;
    mmi_rp_hash_struct *hash_others;
}mmi_rp_img_cntx_struct;

extern void mmi_rp_img_init(void);
extern void mmi_rp_img_deinit(void);
extern void mmi_rp_img_set_app_range(void);

extern int mmi_rp_img_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_img_end_handler(void *data, const kal_char *el);
extern int mmi_rp_img_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_multi_img_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_multi_img_end_handler(void *data, const kal_char *el);
extern int mmi_rp_multi_img_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_med_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_med_end_handler(void *data, const kal_char *el);
extern int mmi_rp_med_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_enfb_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_enfb_end_handler(void *data, const kal_char *el);


extern void mmi_rp_binary3d_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern void mmi_rp_binary3d_end_handler(void *data, const kal_char *el);
extern void mmi_rp_binary3d_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);


extern MMI_BOOL mmi_rp_img_find_img_id(U8* str_img_id, U16* img_id);

extern void mmi_rp_img_filter(void);
extern void mmi_rp_med_filter(void);

extern void mmi_rp_img_output_phase1(void);
extern void mmi_rp_img_output_phase2(void);

extern void mmi_rp_med_output_phase1(void);
extern void mmi_rp_med_output_phase2(void);

#endif /* RESXML_IMAGE_H */
