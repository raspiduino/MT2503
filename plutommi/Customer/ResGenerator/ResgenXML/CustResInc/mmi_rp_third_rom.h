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
*  mmi_rp_third_rom.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Resgen XML header file of 3rd ROM resource
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
 *
 * removed!
 *
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_THIRD_ROM_H
#define MMI_RP_THIRD_ROM_H

/* Define your Tag here */
#define MMI_RP_THIRDROM_TAG "ThirdROMBIN"
#define MMI_RP_THIRD_ROM_MAX_STRING_LEN   512

///TODO: define your tag here


typedef struct
{
    U8 *third_rom_id_str;
    U8 *third_rom_bin_path;                 
}mmi_rp_third_rom_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_third_rom_id_struct *third_rom_strings;
}mmi_rp_third_rom_data_struct;

typedef struct
{
    mmi_rp_third_rom_data_struct *app_third_rom_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_third_rom_cntx_struct;



extern void mmi_rp_thirdrom_init(void);
extern void mmi_rp_thirdrom_set_app_range(void);

extern int mmi_rp_thirdrom_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_thirdrom_end_handler(void *data, const kal_char *el);
extern int mmi_rp_thirdrom_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_thirdrom_filter(void);

extern void mmi_rp_thirdrom_output_phase1(void);
extern void mmi_rp_thirdrom_output_phase2(void);
extern void mmi_rp_thirdrom_output_phase2_app_c_file(U32 app_index, FILE *p_file);


#endif /* MMI_RP_THIRD_ROM_H */
