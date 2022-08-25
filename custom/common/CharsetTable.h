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

/*******************************************************************************
 * Filename:
 * ---------
 * CharsetTable.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes for charset realted utilities
  *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_CHARSETS_H
#define _MMI_CHARSETS_H
#include "mmi_features.h"
#include "kal_release.h"
#include "Conversions.h"
#if !defined(NEPTUNE_MMI)
#include "kal_general_types.h"
#endif

typedef struct
{
    unsigned short start_value;
    unsigned short end_value;
    unsigned short index;
} Mapping_Struct;

//create a new mapping_struct for MSB(8 bits)
typedef struct
{
    unsigned char start_value;
    unsigned char end_value;
    unsigned short index;
} MSB_Mapping_Struct;

typedef struct
{
	unsigned short base_value;
	unsigned short end_index;
}Alphabet_Mapping_Struct;

extern const Mapping_Struct g_chset_map_ucs2_common[];
extern unsigned short mmi_chset_map_ucs2_common_size(void);

#ifdef __MMI_CHSET_ARABIC_ISO__
extern const kal_uint8 g_chset_ucs2_arabic_iso[];
extern const unsigned short g_chset_arabic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_arabic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_arabic_iso[];
extern unsigned short mmi_chset_map_ucs2_arabic_iso_size(void);
extern unsigned short mmi_chset_map_arabic_ucs2_iso_size(void);
#endif /* __MMI_CHSET_ARABIC_ISO__ */ 

#ifdef __MMI_CHSET_ARABIC_WIN__
extern const kal_uint8 g_chset_ucs2_arabic_win[];
extern const unsigned short g_chset_arabic_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_arabic_win[];
extern unsigned short mmi_chset_map_arabic_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_arabic_win_size(void);
#endif /* __MMI_CHSET_ARABIC_WIN__ */ 

#ifdef __MMI_CHSET_CYRILLIC_ISO__
extern const kal_uint8 g_chset_ucs2_cyrillic_iso[];
extern const unsigned short g_chset_cyrillic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_cyrillic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_cyrillic_iso[];
extern unsigned short mmi_chset_map_ucs2_cyrillic_iso_size(void);
extern unsigned short mmi_chset_map_cyrillic_ucs2_iso_size(void);
#endif /* __MMI_CHSET_CYRILLIC_ISO__ */ 

#ifdef __MMI_CHSET_CYRILLIC_WIN__
extern const kal_uint8 g_chset_ucs2_cyrillic_win[];
extern const unsigned short g_chset_cyrillic_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_cyrillic_win[];
extern const Mapping_Struct g_chset_map_cyrillic_ucs2_win[];
extern unsigned short mmi_chset_map_cyrillic_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_cyrillic_win_size(void);
#endif /* __MMI_CHSET_CYRILLIC_WIN__ */ 

/* PMT START PERSIAN */
#ifdef __MMI_CHSET_PERSIAN_CP1097__
extern const unsigned short g_chset_ucs2_persian_cp1097[];
extern const unsigned short g_chset_persian_ucs2_cp1097[];
extern const Mapping_Struct g_chset_map_persian_ucs2_cp1097[];
extern const Mapping_Struct g_chset_map_ucs2_persian_cp1097[];
extern unsigned short mmi_chset_map_ucs2_persian_cp1097_size(void);
extern unsigned short mmi_chset_map_persian_ucs2_cp1097_size(void);
#endif /* __MMI_CHSET_PERSIAN_CP1097__ */ 
#ifdef __MMI_CHSET_PERSIAN_CP1098__
extern const kal_uint8 g_chset_ucs2_persian_cp1098[];
extern const unsigned short g_chset_persian_ucs2_cp1098[];
extern const Mapping_Struct g_chset_map_persian_ucs2_cp1098[];
extern const Mapping_Struct g_chset_map_ucs2_persian_cp1098[];
extern unsigned short mmi_chset_map_ucs2_persian_cp1098_size(void);
extern unsigned short mmi_chset_map_persian_ucs2_cp1098_size(void);
#endif /* __MMI_CHSET_PERSIAN_CP1098__ */ 
/* PMT END PERSIAN */
#ifdef __MMI_CHSET_BALTIC_ISO__
extern const kal_uint8 g_chset_ucs2_baltic_iso[];
extern const unsigned short g_chset_baltic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_baltic_iso[];
extern const Mapping_Struct g_chset_map_baltic_ucs2_iso[];
extern unsigned short mmi_chset_map_baltic_ucs2_iso_size(void);
extern unsigned short mmi_chset_map_ucs2_baltic_iso_size(void);
#endif /* __MMI_CHSET_BALTIC_ISO__ */ 

#ifdef __MMI_CHSET_BALTIC_WIN__
extern const kal_uint8 g_chset_ucs2_baltic_win[];
extern const unsigned short g_chset_baltic_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_baltic_win[];
extern const Mapping_Struct g_chset_map_baltic_ucs2_win[];
extern unsigned short mmi_chset_map_ucs2_baltic_win_size(void);
extern unsigned short mmi_chset_map_baltic_ucs2_win_size(void);
#endif /* __MMI_CHSET_BALTIC_WIN__ */ 

#ifdef __MMI_CHSET_CEURO_ISO__
extern const kal_uint8 g_chset_ucs2_ceuro_iso[];
extern const unsigned short g_chset_ceuro_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_ceuro_iso[];
extern const Mapping_Struct g_chset_map_ceuro_ucs2_iso[];
extern unsigned short mmi_chset_map_ucs2_ceuro_iso_size(void);
extern unsigned short mmi_chset_map_ceuro_ucs2_iso_size(void);
#endif /* __MMI_CHSET_CEURO_ISO__ */ 

#ifdef __MMI_CHSET_CEURO_WIN__
extern const kal_uint8 g_chset_ucs2_ceuro_win[];
extern const unsigned short g_chset_ceuro_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_ceuro_win[];
extern const Mapping_Struct g_chset_map_ceuro_ucs2_win[];
extern unsigned short mmi_chset_map_ceuro_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_ceuro_win_size(void);
#endif /* __MMI_CHSET_CEURO_WIN__ */ 

#ifdef __MMI_CHSET_GREEK_ISO__
extern const kal_uint8 g_chset_ucs2_greek_iso[];
extern const unsigned short g_chset_greek_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_greek_iso[];
extern const Mapping_Struct g_chset_map_greek_ucs2_iso[];
extern unsigned short mmi_chset_map_ucs2_greek_iso_size(void);
extern unsigned short mmi_chset_map_greek_ucs2_iso_size(void);
#endif /* __MMI_CHSET_GREEK_ISO__ */ 

#ifdef __MMI_CHSET_GREEK_WIN__
extern const kal_uint8 g_chset_ucs2_greek_win[];
extern const unsigned short g_chset_greek_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_greek_win[];
extern const Mapping_Struct g_chset_map_greek_ucs2_win[];
extern unsigned short mmi_chset_map_greek_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_greek_win_size(void);
#endif /* __MMI_CHSET_GREEK_WIN__ */ 

#ifdef __MMI_CHSET_HEBREW_ISO__
extern const kal_uint8 g_chset_ucs2_hebrew_iso[];
extern const unsigned short g_chset_hebrew_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_hebrew_iso[];
extern const Mapping_Struct g_chset_map_hebrew_ucs2_iso[];
extern unsigned short mmi_chset_map_hebrew_ucs2_iso_size(void);
extern unsigned short mmi_chset_map_ucs2_hebrew_iso_size(void);
#endif /* __MMI_CHSET_HEBREW_ISO__ */ 

#ifdef __MMI_CHSET_EUCKR_WIN__
extern const unsigned short g_chset_ucs2_euckr_win[];
extern const unsigned short g_chset_euckr_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_euckr_win[];
extern const Mapping_Struct g_chset_map_euckr_ucs2_win[];
extern unsigned short g_chset_map_euckr_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_euckr_win_size(void);
#endif /* __MMI_CHSET_EUCKR_WIN__ */ 

#ifdef __MMI_CHSET_THAI_WINDOWS__
extern const kal_uint8 g_chset_ucs2_thai_win[];
extern const unsigned short g_chset_thai_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_thai_win[];
extern const Mapping_Struct g_chset_map_thai_ucs2_win[];
extern unsigned short g_chset_map_thai_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_thai_win_size(void);
#endif /* __MMI_CHSET_THAI_WINDOWS__ */ 

#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__
extern const kal_uint8 g_chset_ucs2_vietnamese_win[];
extern const unsigned short g_chset_vietnamese_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_vietnamese_win[];
extern const Mapping_Struct g_chset_map_vietnamese_ucs2_win[];
extern unsigned short g_chset_map_vietnamese_ucs2_win_size(void);
extern unsigned short mmi_chset_map_ucs2_vietnamese_win_size(void);
#endif /* __MMI_CHSET_VIETNAMESE_WINDOWS__ */ 

#ifdef __MMI_CHSET_HEBREW_WIN__
extern const kal_uint8 g_chset_ucs2_hebrew_win[];
extern const unsigned short g_chset_hebrew_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_hebrew_win[];
extern const Mapping_Struct g_chset_map_hebrew_ucs2_win[];
extern unsigned short mmi_chset_map_ucs2_hebrew_win_size(void);
extern unsigned short mmi_chset_map_hebrew_ucs2_win_size(void);
#endif /* __MMI_CHSET_HEBREW_WIN__ */ 

#ifdef __MMI_CHSET_LATIN_ISO__
extern const kal_uint8 g_chset_ucs2_latin_iso[];
extern const unsigned short g_chset_latin_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_latin_iso[];
extern const Mapping_Struct g_chset_map_latin_ucs2_iso[];
extern unsigned short mmi_chset_map_latin_ucs2_iso_size(void);
extern unsigned short mmi_chset_map_ucs2_latin_iso_size(void);
#endif /* __MMI_CHSET_LATIN_ISO__ */ 

#ifdef __MMI_CHSET_NORDIC_ISO__
extern const kal_uint8 g_chset_ucs2_nordic_iso[];
extern const unsigned short g_chset_nordic_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_nordic_iso[];
extern const Mapping_Struct g_chset_map_nordic_ucs2_iso[];
extern unsigned short mmi_chset_map_ucs2_nordic_iso_size(void);
extern unsigned short mmi_chset_map_nordic_ucs2_iso_size(void);
#endif /* __MMI_CHSET_NORDIC_ISO__ */ 

#ifdef __MMI_CHSET_SEURO_ISO__
extern const kal_uint8 g_chset_ucs2_seuro_iso[];
extern const unsigned short g_chset_seuro_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_seuro_iso[];
extern const Mapping_Struct g_chset_map_seuro_ucs2_iso[];
extern unsigned short mmi_chset_map_ucs2_seuro_iso_size(void);
extern unsigned short mmi_chset_map_seuro_ucs2_iso_size(void);
#endif /* __MMI_CHSET_SEURO_ISO__ */ 

#ifdef __MMI_CHSET_TURKISH_ISO__
extern const unsigned short g_chset_turkish_ucs2_iso[];
extern const kal_uint8 g_chset_ucs2_turkish_iso[];
extern const Mapping_Struct g_chset_map_turkish_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_turkish_iso[];
extern unsigned short mmi_chset_map_turkish_ucs2_iso_size(void);
extern unsigned short mmi_chset_map_ucs2_turkish_iso_size(void);
#endif /* __MMI_CHSET_TURKISH_ISO__ */ 

#ifdef __MMI_CHSET_TURKISH_WIN__
extern const unsigned short g_chset_turkish_ucs2_win[];
extern const kal_uint8 g_chset_ucs2_turkish_win[];
extern const Mapping_Struct g_chset_map_turkish_ucs2_win[];
extern const Mapping_Struct g_chset_map_ucs2_turkish_win[];
extern unsigned short mmi_chset_map_ucs2_turkish_win_size(void);
extern unsigned short mmi_chset_map_turkish_ucs2_win_size(void);
#endif /* __MMI_CHSET_TURKISH_WIN__ */ 

#ifdef __MMI_CHSET_WESTERN_ISO__
extern const kal_uint8 g_chset_ucs2_western_iso[];
//extern const char g_chset_western_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_western_iso[];
extern unsigned short mmi_chset_map_ucs2_western_iso_size(void);
#endif /* __MMI_CHSET_WESTERN_ISO__ */ 

#ifdef __MMI_CHSET_ARMENIAN_ISO__
extern const kal_uint8 g_chset_ucs2_armenian_iso[];
extern const unsigned short g_chset_armenian_ucs2_iso[];
extern const Mapping_Struct g_chset_map_armenian_ucs2_iso[];
extern const Mapping_Struct g_chset_map_ucs2_armenian_iso[];
extern unsigned short mmi_chset_map_armenian_ucs2_iso_size(void);
extern unsigned short mmi_chset_map_ucs2_armenian_iso_size(void);
#endif /* __MMI_CHSET_ARMENIAN_ISO__ */

#ifdef __MMI_CHSET_WESTERN_WIN__
extern const Alphabet_Mapping_Struct g_chset_ucs2_western_win[];
extern const Alphabet_Mapping_Struct g_chset_western_win_ucs2[];
extern unsigned short mmi_chset_ucs2_western_win_size(void);
extern unsigned short mmi_chset_western_win_ucs2_size(void);
extern const Mapping_Struct g_chset_map_ucs2_western_win[];
extern const Mapping_Struct g_chset_map_western_win_ucs2[];
extern unsigned short mmi_chset_map_ucs2_western_win_size(void);
extern unsigned short mmi_chset_map_western_win_ucs2_size(void);
#endif /* __MMI_CHSET_WESTERN_WIN__ */ 

#ifdef __MMI_CHSET_KOI8_R__
extern const kal_uint8 g_chset_ucs2_koi8_r[];
extern const Mapping_Struct g_chset_map_ucs2_koi8_r[];
extern const unsigned short g_chset_koi8_r_ucs2[];
extern const Mapping_Struct g_chset_map_koi8_r_ucs2[];
extern unsigned short mmi_chset_map_ucs2_koi8_r_size(void);
extern unsigned short mmi_chset_map_koi8_r_ucs2_size(void);  
#endif /* __MMI_CHSET_KOI8_R__ */

#ifdef __MMI_CHSET_TIS_620__
extern const kal_uint8 g_chset_ucs2_tis_620[];
extern const Mapping_Struct g_chset_map_ucs2_tis_620[];
extern const unsigned short g_chset_tis_620_ucs2[];
extern const Mapping_Struct g_chset_map_tis_620_ucs2[];
extern unsigned short mmi_chset_map_ucs2_tis_620_size(void);
extern unsigned short mmi_chset_map_tis_620_ucs2_size(void);  
#endif /* __MMI_CHSET_TIS_620__ */


#ifdef __MMI_CHSET_BIG5__
extern const key_index_t g_chset_ucs2_to_big5_key_LSB_index[];
extern const key_index_t g_chset_big5_to_ucs2_key_LSB_index[];
extern const unsigned char g_chset_ucs2_to_big5_key_MSB[];
extern const unsigned char g_chset_big5_to_ucs2_key_MSB[];
extern const unsigned short g_chset_ucs2_to_big5_table[];
extern const unsigned short g_chset_big5_to_ucs2_table[];
#endif /* __MMI_CHSET_BIG5__ */ 

#ifdef __MMI_CHSET_GB2312__
extern const key_index_t g_chset_ucs2_to_gb2312_key_LSB_index[];
extern const key_index_t g_chset_gb2312_to_ucs2_key_LSB_index[];
extern const unsigned char g_chset_ucs2_to_gb2312_key_MSB[];
extern const MSB_Mapping_Struct g_chset_gb2312_to_ucs2_key_MSB[];
extern const unsigned short g_chset_ucs2_to_gb2312_table[];
extern const unsigned short g_chset_gb2312_to_ucs2_table[];
extern unsigned short mmi_chset_gb2312_to_ucs2_MSB_size(void);
#endif /* __MMI_CHSET_GB2312__ */ 

#ifdef __MMI_CHSET_HKSCS__
extern const key_index_t g_chset_ucs2_to_hkscs_key_LSB_index[];
extern const key_index_t g_chset_hkscs_to_ucs2_key_LSB_index[];
extern const unsigned char g_chset_ucs2_to_hkscs_key_MSB[];
extern const unsigned char g_chset_hkscs_to_ucs2_key_MSB[];
extern const unsigned short g_chset_ucs2_to_hkscs_table[];
extern const unsigned short g_chset_hkscs_to_ucs2_table[];
#endif /* __MMI_CHSET_HKSCS__ */ 

#ifdef __MMI_CHSET_GB18030__
typedef struct
{
    kal_uint16 gb_code;
    kal_uint16 ucs2_code;
} mmi_chset_gb18030_ucs2_2_byte_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

typedef struct
{
    kal_uint16 gb_code_high;
    kal_uint16 gb_code_low;
    kal_uint16 ucs2_code;
} mmi_chset_gb18030_ucs2_4_byte_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

extern const mmi_chset_gb18030_ucs2_2_byte_struct g_chset_gb18030_to_ucs2_2_byte_tbl[];
extern const mmi_chset_gb18030_ucs2_4_byte_struct g_chset_gb18030_to_ucs2_4_byte_tbl[];
extern const mmi_chset_gb18030_ucs2_2_byte_struct g_chset_ucs2_to_gb18030_2_byte_tbl[];

extern kal_uint32 mmi_chset_gb18030_ucs2_2byte_size(void);
extern kal_uint32 mmi_chset_gb18030_ucs2_4byte_size(void);
extern kal_uint32 mmi_chset_ucs2_gb18030_2byte_size(void);

#endif /* __MMI_CHSET_GB18030__ */ 

#ifdef __MMI_CHSET_SJIS__
extern const key_index_t g_chset_ucs2_to_sjis_key_LSB_index[];
extern const key_index_t g_chset_sjis_to_ucs2_key_LSB_index[];
extern const unsigned char g_chset_ucs2_to_sjis_key_MSB[];
extern const unsigned char g_chset_sjis_to_ucs2_key_MSB[];
extern const unsigned short g_chset_ucs2_to_sjis_table[];
extern const unsigned short g_chset_sjis_to_ucs2_table[];
#endif /* __MMI_CHSET_SJIS__ */

#endif /* _MMI_CHARSETS_H */ // #ifndef _MMI_CHARSETS_H

