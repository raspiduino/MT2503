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
*  mmi_rp_theme.h
*
* Project:
* --------
*   Resgen XML header file of theme resource
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_THEME_H
#define RESXML_THEME_H


#include "MMIDataType.h"


typedef struct
{
    U8 *id_str;
    U8 *desc_str;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_theme_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_theme_id_struct *theme;
}mmi_rp_theme_data_struct;

typedef struct
{
    U8 *id_str;
    U8 *desc_str;
    U8 *opaque;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_color_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_color_id_struct *color;
}mmi_rp_color_data_struct;

typedef struct
{
    U8 *id_str;
    U8 *desc_str;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_fontstyle_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_fontstyle_id_struct *fontstyle;
}mmi_rp_fontstyle_data_struct;

typedef struct
{
    U8 *id_str;
    U8 *desc_str;
    U8 *min;
    U8 *max;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_integer_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_integer_id_struct *integer;
}mmi_rp_integer_data_struct;

typedef struct
{
    U8 *id_str;
    U8 *desc_str;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_binary_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_binary_id_struct *binary;
}mmi_rp_binary_data_struct;

typedef struct
{
    mmi_rp_theme_data_struct     *app_theme_data;
    
    mmi_rp_color_data_struct     *app_color_data;
    mmi_rp_hash_struct *hash_color;

    mmi_rp_fontstyle_data_struct *app_fontstyle_data;
    mmi_rp_hash_struct *hash_fontstyle;

    mmi_rp_integer_data_struct   *app_integer_data;
    mmi_rp_hash_struct *hash_integer;

    mmi_rp_binary_data_struct    *app_binary_data;
    mmi_rp_hash_struct *hash_binary;
    
}mmi_rp_theme_cntx_struct;

extern void mmi_rp_theme_init(void);
extern void mmi_rp_theme_deinit(void);
extern void mmi_rp_theme_set_app_range(void);

extern int mmi_rp_theme_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_theme_end_handler(void *data, const kal_char *el);
extern int mmi_rp_theme_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_color_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_color_end_handler(void *data, const kal_char *el);

extern int mmi_rp_fontstyle_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_fontstyle_end_handler(void *data, const kal_char *el);

extern int mmi_rp_binary_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_binary_end_handler(void *data, const kal_char *el);

extern int mmi_rp_integer_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_integer_end_handler(void *data, const kal_char *el);


extern void mmi_rp_theme_filter(void);

extern void mmi_rp_theme_output_phase1(void);
extern void mmi_rp_theme_output_phase2(void);

extern MMI_BOOL g_mmi_rp_is_theme;

#endif /* RESXML_THEME_H */
