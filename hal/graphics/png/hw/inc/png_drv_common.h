/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    png_drv_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG HW decoder driver comm API and data structure header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PNG_DRV_COMMMON_H__
#define __PNG_DRV_COMMMON_H__

/// #include "drv_comm.h"

#include "drv_features_png.h"

#if defined(USE_HW_PNG_DECODER)

#include "png_info.h"
/// #include "png_status.h"

#include "kal_general_types.h"
#include "png_decode_structure.h"
    
//----------------target dependent header files are added here-----------------
/// #include "png_drv_6238_series.h"
/// #include "png_drv_6268_series.h"
/// #include "png_drv_6276_series.h"
//-----------------------------------------------------------------------------
#include "png_decode_enum.h"

#define png_memcmp memcmp
#define png_memcpy memcpy
#define png_memset memset

typedef void (*callback_func_ptr)(PNG_STATUS_ENUM);

// to chek dependency of hw configuration
typedef struct decoder_cfg 
{
   kal_uint8 user_alpha_is_set;        // check when blending mode ==  PNG_BLEND_USER_ASSIGNED

   //trans
   kal_uint8 trans_enable;             // enable if file alpha exists
   kal_uint8 trans_tbl_enable;         // if tRNS exist and png color type is palette
   kal_uint8 trans_key_enable;         // if transparent color is a single value specified by RGB or Grey
   kal_uint8 bk_color_disable;         // replace transparent color with background color specified in bKGD

   //alpha
   kal_uint8 a_en;

   //color replacing
   kal_uint8 color_replace_enable;

} decoder_cfg_st;


/** 
 *  @brief check the intersection of canvas, clipping window, output window \n
 *  @param hwcfg the configuation about canvas, clipping window and output window \n
 *  @return -1 if the intersection is null set      
 *  @return  0 if the intersection is valid
 */
kal_int32 png_drv_intersect_region(PNG_HW_INFO *hwcfg);

/** 
 *  @brief invoked when target boot \n
 */
void png_drv_init_when_boot(void);

/** 
 *  @brief the function is invoked to reset hardware \n
 */
PNG_STATUS_ENUM png_drv_reset(void);

/** 
 *  @brief register a callback function which is invoked when hardware png decoder raises an interrupt 
 *  @param png_irq_callback a function pointer with parameter of PNG_STATUS_ENUM type and return void
 */
void png_drv_hook_irq_callback(callback_func_ptr png_irq_callback);

/** 
 *  @brief power on hardware png decoder
 */
PNG_STATUS_ENUM png_drv_poweron(void);

/** 
 *  @brief power off hw png decoder after no using hw png decoder
 */
PNG_STATUS_ENUM png_drv_poweroff(void);

/** 
 *  @brief call this function to set the internal/external working buffer of hardware png decoder 
 *  @param internalBuf pointer to a continuous internal memory for working buffer
 *  @param externalBuf pointer to a continuous external memory for working buffer
 *  @param hwcfg pointer to a hw_info structure which return the configuration of working buffers
 */
PNG_STATUS_ENUM png_drv_set_working_buffer (kal_uint32 *internalBuf, kal_uint32 *externalBuf, PNG_HW_INFO *hwcfg);     

/** 
 *  @brief Fill the given palette data to the the address of color table
 *  @param paltbl_start_adr palette (color table) start address 
 *  @param palette_data in the format of RGBRGBRGB...
 *  @param sz_byte palette data size (uint = byte)
 */   
PNG_STATUS_ENUM png_drv_fill_palette(kal_uint32* paltbl_start_adr, kal_uint8* palette_data, kal_uint32 sz_byte);

/** 
 *  @brief Fill the given alpha data to the the address of alpha/transparency table if indexed color and tRNS is encountered
 *  @param alphatbl_start_adr alpha table start address 
 *  @param alpha_data alpha data to be filled
 *  @param sz_byte alpha data size (unit = byte)
 */   
PNG_STATUS_ENUM png_drv_fill_alpha_table(kal_uint32* alphatbl_start_adr, kal_uint8* alpha_data, kal_uint32 sz_byte, kal_uint32 plt_num);

/** 
 *  @brief Get RGB value of specified palette entry  
 *  @param paltbl_start_adr palette table start address 
 *  @param pal_idx palette index for required entry
 *  @param entry a pointer to an entry which contains the returned RGB value 
 */   
PNG_STATUS_ENUM png_drv_get_plt_entry(kal_uint32 *paltbl_start_adr, kal_uint8 pal_idx, png_color_16* entry);

PNG_STATUS_ENUM png_drv_set_source_data(kal_uint32 src_start_adr, kal_uint32 src_sz_byte, kal_bool is_last_part);
PNG_STATUS_ENUM png_drv_set_output_window(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png);                                 
PNG_STATUS_ENUM png_drv_set_canvas(PNG_HW_INFO *hwcfg);                                                          
PNG_STATUS_ENUM png_drv_set_clip_window(PNG_HW_INFO *hwcfg);                                                     
PNG_STATUS_ENUM png_drv_set_replace_color(PNG_HW_INFO *hwcfg);                                                   
PNG_STATUS_ENUM png_drv_set_blending_buffer(void *blend_buf_adr);                                                
PNG_STATUS_ENUM png_drv_set_alpha_value(kal_int32 userAlpha);                                                    
PNG_STATUS_ENUM png_drv_set_blending_mode(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png_ptr);                             
PNG_STATUS_ENUM png_drv_decode_start(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png);                                      
PNG_STATUS_ENUM png_drv_decode_resume(PNG_HW_INFO *hwcfg);                                                       
PNG_STATUS_ENUM png_drv_get_working_buffer_size(kal_uint32 *internal_mem_sz, kal_uint32 *external_mem_sz);       
PNG_STATUS_ENUM png_drv_get_comsumed_bytes(kal_uint32 *count);                                                   
PNG_STATUS_ENUM png_drv_set_bg_color_out(MY_PNG_INFO *png);                                                      
void png_drv_get_decode_status(kal_int32 *status_code);

// -------internal use--------------------
void png_drv_get_hw_cfg (decoder_cfg_st** my_drv_cfg);

#endif //   #if defined(USE_HW_PNG_DECODER)
#endif //   __PNG_DRV_COMMMON_H__
