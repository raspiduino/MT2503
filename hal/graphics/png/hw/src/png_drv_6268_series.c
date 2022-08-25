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
 *    png_drv_6268_series.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG HW decoder driver
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"   // define DRV_Reg... macro, define __PNG_DECODER_6268_SERIES__

#if defined(__PNG_DECODER_6268_SERIES__)

#include "drv_features.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "png_drv_6268_series.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "png_decode_enum.h"
#include "png_info.h"
#include "string.h"
#include "png_decode_structure.h"
   
#include "intrCtrl.h"         //define IRQ_PNG_CODE
/// #include "gpt_sw.h"
/// #include "kal_release.h"      // kal_activate_hisr
#include "mm_power_ctrl.h"    /// mm power gating
//#include "config_hw.h"  // define Power-down control registers

#include "png_chunk.h"
#include "png_drv_common.h"
#include "mm_intmem.h"        /// mm internal memory management

/// For new HISR management
#include "hisr_config.h"
#include "dcl.h"
#include "drv_gfx_hisr_ctrl.h"

#if PNG_DEBUG
volatile kal_uint32 png_hw_trigger_time = 0;
volatile kal_uint32 png_hw_decode_time = 0;
#endif

void png_drv_hisr(void);
static void _png_drv_lisr(void);
static void _pngDrvTimeoutHandler(void *parameter);
static void _png_drv_start_timer(kal_uint16 timeout_msec);
static void _png_drv_stop_timer(void);
static void _addMemGuardHeader(kal_uint32 *ptr);
static void _addMemGuardFooter(kal_uint32 *ptr);
static void _checkMemGuardHeader(kal_uint32 *ptr);
static void _checkMemGuardFooter(kal_uint32 *ptr);

static kal_hisrid _png_dec_hisr_id = {0};
static callback_func_ptr _png_drv_irq_callback = NULL;
/// static kal_uint8 _png_drv_timeout_handle = 0;
static DCL_HANDLE _png_drv_timeout_handle = NULL;
static decoder_cfg_st _png_decoder_cfg = {0};

#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
kal_uint8 png_codec_sleep_mode_handler = 0xFF;
#endif

/// 2008.05.21
/// additional 2 * 4 bytes for each memory segment as memory guard header & footer
#define INT_WORK_BUFFER_SIZE     (((COLOR_TBL_MAX_SIZE+2)+(HLIT_TBL_MAX_SIZE+2)+(HDIST_TBL_MAX_SIZE+2)+(LINE_BUF_MAX_SIZE+2)+8) * 4)
#define EXT_WORK_BUFFER_SIZE     (((HCLEN_TBL_MAX_SIZE+2)+(TRNS_TBL_MAX_SIZE+2)+6+4+8 + (LZ77_BUF_MAX_SIZE+4)) * 4)

static int contrl_use_int_flag = 1;
static void
_png_drv_lisr(void)
{
   IRQMask(IRQ_PNG_CODE);

#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   drv_gfx_hisr_activate(DRV_GFX_HISR_MODULE_PNG_DECODER);
#endif   
}




void png_drv_hisr(void)
{
   kal_uint32 IRQStatus;

   // stop time out checking process
   _png_drv_stop_timer();

   if (!_png_drv_irq_callback)
   {
      IRQUnmask(IRQ_PNG_CODE);
      return ;
   }
   IRQStatus = DRV_Reg(PNG_IRQ_STATUS) & PNG_DECODER_IRQ_EN_ALL;

   if (PNG_IRQ_STATUS_IDLE == IRQStatus)
   {

      IRQUnmask(IRQ_PNG_CODE);   /// 2008.05.23
      return;
   }

   if (IRQStatus & PNG_IRQ_STATUS_IMG_COMPLETE)
   {
      #if PNG_DEBUG
      kal_get_time(&png_hw_decode_time);
      png_hw_decode_time = kal_ticks_to_milli_secs(png_hw_decode_time - png_hw_trigger_time);
      png_hw_trigger_time = 0;
      #endif
      (*_png_drv_irq_callback)(PNG_STATUS_OK);
   }
   else if (IRQStatus & PNG_IRQ_STATUS_IN_EMPTY)
   {
      (*_png_drv_irq_callback)(PNG_STATUS_DECODE_INCOMPLETE);
   }
   else
   {
      (*_png_drv_irq_callback)(PNG_STATUS_ERROR_DECODE_FAILED);
   }

   IRQUnmask(IRQ_PNG_CODE);
   return;
}



static void
 _pngDrvTimeoutHandler(void *parameter)
{
   _png_drv_stop_timer();

   // call back when times out
   if (!_png_drv_irq_callback)
   {
      return;
   }

   (*_png_drv_irq_callback)(PNG_STATUS_DECODE_TIMEOUT);
}


static void
_png_drv_start_timer(kal_uint16 timeout_msec)
{
   SGPT_CTRL_START_T start;
   DCL_STATUS result;

   // the unit of GPT timer is 10ms
   if (0 == timeout_msec)
   {
      timeout_msec = 300;  ///<  default set 3 sec, over 3 sec, time out fail.
   }

   if (NULL == _png_drv_timeout_handle)
   {
      return;
   }

   start.u2Tick    =  timeout_msec;
   start.pfCallback= _pngDrvTimeoutHandler;
   start.vPara     =  NULL;

   if (STATUS_OK != DclSGPT_Control(_png_drv_timeout_handle,SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start))
   {
      ///
   	  DclSGPT_Control(_png_drv_timeout_handle, SGPT_CMD_STOP, 0);
      result = DclSGPT_Control(_png_drv_timeout_handle,SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
      ASSERT(STATUS_OK == result);
   }
}



static void
_png_drv_stop_timer(void)
{
   if (DCL_HANDLE_INVALID == _png_drv_timeout_handle)
   {
      return;
   }

   DclSGPT_Control(_png_drv_timeout_handle, SGPT_CMD_STOP, 0);
}



static void _checkMemGuardHeader(kal_uint32 *ptr)
{
   if (0xbbbbcccc != *ptr)
   {
      ASSERT(0);
   }
}


static void _checkMemGuardFooter(kal_uint32 *ptr)
{
   if (0xccccbbbb != *ptr)
   {
      ASSERT(0);
   }
}



static void _addMemGuardHeader(kal_uint32 *ptr)
{
   /// header pattern
  *ptr = 0xbbbbcccc;
}



static void _addMemGuardFooter(kal_uint32 *ptr)
{
   /// footer pattern
  *ptr = 0xccccbbbb;
}



kal_int32
png_drv_intersect_region(PNG_HW_INFO *hwcfg)
{
   kal_int32 canvas_x1, canvas_x2, canvas_y1, canvas_y2;

   canvas_x1 = canvas_y1 = 0;
   canvas_x2 = canvas_x1 + hwcfg->canvas_width - 1;
   canvas_y2 = canvas_y1 + hwcfg->canvas_height - 1;

   // check whether canvas is in clipping window or not
   // canvas, clipping window is null set
   if (hwcfg->clipWindow_dr_x < canvas_x1 ||
       hwcfg->clipWindow_ul_x > canvas_x2 ||
       hwcfg->clipWindow_dr_y < canvas_y1 ||
       hwcfg->clipWindow_ul_y > canvas_y2)
   {
      return -1;
   }

   // compute intersection of clipping window and canvas
   if (hwcfg->clipWindow_ul_x < canvas_x1)
   {
      hwcfg->clipWindow_ul_x = canvas_x1;
   }
   if (hwcfg->clipWindow_dr_x > canvas_x2)
   {
      hwcfg->clipWindow_dr_x = canvas_x2;
   }
   if (hwcfg->clipWindow_ul_y < canvas_y1)
   {
      hwcfg->clipWindow_ul_y = canvas_y1;
   }
   if (hwcfg->clipWindow_dr_y > canvas_y2)
   {
      hwcfg->clipWindow_dr_y = canvas_y2;
   }

   // check destination/output window is in clipping window or not
   if ((hwcfg->outputWindow_x + hwcfg->outputWindowWidth - 1) < hwcfg->clipWindow_ul_x ||
        hwcfg->outputWindow_x > hwcfg->clipWindow_dr_x ||
       (hwcfg->outputWindow_y + hwcfg->outputWindowHeight -1) < hwcfg->clipWindow_ul_y ||
        hwcfg->outputWindow_y > hwcfg->clipWindow_dr_y)
   {
      return -1;
   }

   return 0;  // intersection of canvas, clipping window, and output window is not null set
}



// internal use for test
void
png_drv_get_hw_cfg (decoder_cfg_st **my_drv_cfg)
{
   if (!my_drv_cfg)
   {
      ASSERT(0);
   }

   *my_drv_cfg = &_png_decoder_cfg;

   return;
}



PNG_STATUS_ENUM
png_drv_get_comsumed_bytes(kal_uint32 *count)
{
   *count = (DRV_Reg32(PNG_IN_CONSUMED_BITS) & 0x00FFFFFF) >> 3;
   *count = (*count & 0xFFFFFFFC);

   return PNG_STATUS_OK;
}



void
png_drv_init_when_boot(void)
{
   kal_uint8 ret;

   /// register PNG HW decoder LISR
   IRQ_Register_LISR(IRQ_PNG_CODE, _png_drv_lisr, "PNG LISR");

#ifdef EDGE_SENSITIVE
   IRQSensitivity(IRQ_PNG_CODE, EDGE_SENSITIVE);
#else
   IRQSensitivity(IRQ_PNG_CODE, LEVEL_SENSITIVE);
#endif

   IRQUnmask(IRQ_PNG_CODE);


   /// create PNG HW decoder HISR
   if (!_png_dec_hisr_id)
   {
#if 0   
	   #if defined(__KAL_OLD_HISR_API__)
/* under construction !*/
	   #else
/* under construction !*/
	   #endif
#else
      drv_gfx_hisr_hook_callback(DRV_GFX_HISR_MODULE_PNG_DECODER, png_drv_hisr);
#endif
   }   

   // get time out handle
   if(NULL == _png_drv_timeout_handle)
   {
      /// ret = GPTI_GetHandle(&_png_drv_timeout_handle);
       _png_drv_timeout_handle = DclSGPT_Open(DCL_GPT_CB, 0);

      if (DCL_HANDLE_INVALID == _png_drv_timeout_handle)
      {
         ASSERT(0);
      }
   }
   // get sleep mode control handel
   #ifdef MTK_SLEEP_ENABLE
   if (0xFF == png_codec_sleep_mode_handler)
   {
      png_codec_sleep_mode_handler = L1SM_GetHandle();
      ASSERT(0xFF != png_codec_sleep_mode_handler);
   }
   #endif   // MTK_SLEEP_ENABLE
}



PNG_STATUS_ENUM
png_drv_reset(void)
{
   // Reset PNG HW
   DRV_WriteReg8(PNG_CLR_EN,0x01);
   DRV_WriteReg8(PNG_CLR_EN,0x00);

   // enable all PNG IRQ
   DRV_WriteReg8(PNG_IRQ_EN, PNG_DECODER_IRQ_EN_ALL );

   // init png driver internal data
   _png_drv_irq_callback = NULL;
   // _png_drv_timeout_handle is not required to be reset,
   // since handle is got when boot
   memset(&_png_decoder_cfg, 0, sizeof(decoder_cfg_st));


   return PNG_STATUS_OK;
}



void
png_drv_hook_irq_callback(callback_func_ptr png_irq_callback)
{
   _png_drv_irq_callback = png_irq_callback;
}



PNG_STATUS_ENUM
png_drv_poweron(void)
{
   png_drv_init_when_boot();

   // clear clock gating of PNG HW
   /// 2008.05.26 should write 32 bits instead of 8 bits since MMCG_CON0_PNG is 0x200 (more than 8 bits)
   /// DRV_WriteReg32(MMCG_CLR0, MMCG_CON0_PNG);
   //mm_enable_power(MMCG_CON0_PNG);
   mm_enable_power(MMPWRMGR_PNG);

   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepDisable(png_codec_sleep_mode_handler);
   #endif   // MTK_SLEEP_ENABLE

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_poweroff(void)
{
   DCL_STATUS ret;

   if (DCL_HANDLE_INVALID != _png_drv_timeout_handle)
   {
      // release non-zero handle
      ret = DclSGPT_Close(&_png_drv_timeout_handle);
      ASSERT (STATUS_OK == ret);
      _png_drv_timeout_handle = NULL;
   }

   // set clock gating of PNG HW
   /// DRV_WriteReg32(MMCG_SET0, MMCG_CON0_PNG);
   //mm_disable_power(MMCG_CON0_PNG);
   mm_disable_power(MMPWRMGR_PNG);

   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepEnable(png_codec_sleep_mode_handler);
   #endif   // MTK_SLEEP_ENABLE

#if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6268)
    if (1 == contrl_use_int_flag)
    {
        mm_intmem_free(MM_SCEN__PURE_MMI, MM_INTMEM_SEG__PNG);
    }
#endif
   return PNG_STATUS_OK;
}
PNG_STATUS_ENUM
png_drv_set_working_buffer (kal_uint32 *internalBuf, kal_uint32 *externalBuf, PNG_HW_INFO *hwcfg)
{
   /// On MT6268(after W1049 HAL), the internal memory will not be reserved by GDI,
   /// Internal memory (MM Sys. RAM) is controlled by MDP,
   /// We request the internal memory first,
   /// if not have available size, use the pre-reserved external
   /// check if the scenario is under multimedia-scenario
   kal_uint32 internalBufAddr = 0;
   kal_uint32 internal_size = 0;

   /// TODO: Use external memory temporarily, due to use internal memory might lead some alpha image decode failed
   ///       Still under checking.
   #if defined (DRV_FEATURE__MM_INTMEM_IMPL_MT6268)
   if ((KAL_TRUE == mm_intmem_query_non_multimedia()) && (1 == contrl_use_int_flag))
   {
       mm_intmem_get(MM_SCEN__PURE_MMI, MM_INTMEM_SEG__PNG,&internalBufAddr,&internal_size);
       internalBuf = (kal_uint32 *) ((internalBufAddr + 4) & ~4);
       memset((void *)internalBuf, 0x00, internal_size);
   }
   else
   #endif
   {
       internalBuf = (kal_uint32 *)(((kal_uint32)((kal_uint8 *)externalBuf + EXT_WORK_BUFFER_SIZE) + 3) & ~3);
   }


   if((((kal_uint32)internalBuf & 0x03) != 0) || (((kal_uint32)externalBuf & 0x03) != 0))
   {
      ASSERT(0);
      return PNG_STATUS_ERROR_INVALID_BUFFER;
   }

   /// 2008.05.21
   _addMemGuardHeader(internalBuf);
   internalBuf++;
   // color table need internal memory 256x4 bytes
   hwcfg->colorTableStartAddr = internalBuf;     // must word aligned
   if (((kal_uint32)hwcfg->colorTableStartAddr & 0x3) != 0)
   {
      ASSERT(0);
   }
   internalBuf += COLOR_TBL_MAX_SIZE;
   _addMemGuardFooter(internalBuf);
   internalBuf++;

   _addMemGuardHeader(externalBuf);
   externalBuf++;
   // Huffman HCLEN table need external memory 128k bytes
   hwcfg->HCLENStartAddr = externalBuf;          //must word aligned
   if (((kal_uint32)hwcfg->HCLENStartAddr & 0x3) != 0)
   {
      ASSERT(0);
   }
   externalBuf += HCLEN_TBL_MAX_SIZE;
   _addMemGuardFooter(externalBuf);
   externalBuf++;

   _addMemGuardHeader(internalBuf);
   internalBuf++;
   // Huffman HLIT table need internal memory 572 bytes
   hwcfg->HLITStartAddr = internalBuf;           // must word aligned
   if (((kal_uint32)hwcfg->HLITStartAddr & 0x3) != 0)
   {
      ASSERT(0);
   }
   internalBuf += HLIT_TBL_MAX_SIZE;
   _addMemGuardFooter(internalBuf);
   internalBuf++;

   _addMemGuardHeader(internalBuf);
   internalBuf++;
   // Huffman HDIST table need internal memory 60 bytes
   hwcfg->HDISTStartAddr = internalBuf;          // must word aligned
   if (((kal_uint32)hwcfg->HDISTStartAddr & 0x3) != 0)
   {
      ASSERT(0);
   }
   internalBuf += HDIST_TBL_MAX_SIZE;
   _addMemGuardFooter(internalBuf);
   internalBuf++;

   _addMemGuardHeader(internalBuf);
   internalBuf++;
   // Line buffer need internal memory LINE_BUF_MAX_SIZE x 4 bytes
   hwcfg->lineBuff0StartAddr = internalBuf;      // must word aligned
   if (((kal_uint32)hwcfg->lineBuff0StartAddr & 0x3) != 0)
   {
      ASSERT(0);
   }
   internalBuf += LINE_BUF_MAX_SIZE;
   _addMemGuardFooter(internalBuf);
   internalBuf++;

   _addMemGuardHeader(externalBuf);
   externalBuf++;
   // LZ77 buffer need external memory 32k bytes
   hwcfg->lz77StartAddr = externalBuf;          //must word aligned
   externalBuf += LZ77_BUF_MAX_SIZE;
   _addMemGuardFooter(externalBuf);
   externalBuf++;

   _addMemGuardHeader(externalBuf);
   externalBuf++;
   // transparant table max size is 256 bytes
   hwcfg->trnsTableAddr = externalBuf;         // must word aligned
   externalBuf += TRNS_TBL_MAX_SIZE;
   _addMemGuardFooter(externalBuf);
   externalBuf++;

   // set working buffer address
   DRV_WriteReg32(PNG_COLOR_TBL_START, (kal_uint32)hwcfg->colorTableStartAddr );
   DRV_WriteReg32(PNG_HCLEN_START, (kal_uint32)hwcfg->HCLENStartAddr);
   DRV_WriteReg32(PNG_HLIT_START, (kal_uint32)hwcfg->HLITStartAddr);
   DRV_WriteReg32(PNG_HDIST_START, (kal_uint32)hwcfg->HDISTStartAddr);
   DRV_WriteReg32(PNG_BUFF0_START, (kal_uint32)hwcfg->lineBuff0StartAddr);
   DRV_WriteReg32(PNG_LZ77_START, (kal_uint32)hwcfg->lz77StartAddr);
   DRV_WriteReg32(PNG_TRAN_TBL_START, (kal_uint32)hwcfg->trnsTableAddr);

   return PNG_STATUS_OK;
}




PNG_STATUS_ENUM
png_drv_fill_palette(kal_uint32 *paltbl_start_adr,
                  kal_uint8 *palette_data,
                  kal_uint32 sz_byte)
{
   // palette_data is in the fom of RGBRGB...
   kal_uint32 i;
   kal_uint8 *byte_ptr;

   byte_ptr = (kal_uint8 *)paltbl_start_adr;

   // hw required palette format: each entry is a word  in a form [31:0] = {8'b0,R,G,B} -> BGR0
   for (i = 0; i < sz_byte; i += 3, byte_ptr += 4)
   {
       *(byte_ptr) = *(palette_data + i + 2);             //B
       *(byte_ptr + 1) = *(palette_data + i + 1);         //G
       *(byte_ptr + 2) = *(palette_data + i );            //R
       *(byte_ptr + 3) = 0;
   }

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_fill_alpha_table(kal_uint32 *alphatbl_start_adr,
                     kal_uint8 *alpha_data,
                     kal_uint32 sz_byte,
                     kal_uint32 plt_num)
{
   // alpha_data is in the fom of ..AAAA... (each alpha is 1 byte)
   kal_int32 i;
   kal_uint8 *byte_ptr;

   byte_ptr = (kal_uint8 *)alphatbl_start_adr;

   // hw required alpha table format: each entry is a word  in a form {AAAA}
   for (i = 0; i < sz_byte; i++)
   {
      *(byte_ptr + i) = *(alpha_data + i);
   }

   // tRNS chunk may contain fewer values than there are palette entries.
   // In this case, the alpha value for all remaining palette entries is assumed to be 255
   for (; i < plt_num; i++)
   {
      *(byte_ptr + i) = 0xFF;  // 255
   }

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_get_plt_entry(kal_uint32 *paltbl_start_adr,
                  kal_uint8 pal_idx,
                  png_color_16 *entry)
{
   kal_uint8 *byte_ptr;
   byte_ptr = (kal_uint8 *)paltbl_start_adr;

   // palette table format [31:0] = {8'b0,R,G,B} -> [0:31] = BGR0, each entry is 4 byte
   byte_ptr += pal_idx * 4;

   (*entry).blue = *byte_ptr;
   (*entry).green = *(byte_ptr + 1);
   (*entry).red = *(byte_ptr + 2);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_source_data(kal_uint32 src_start_adr, kal_uint32 src_sz_byte, kal_bool is_src_end){

   kal_uint32 end_adr;

   // assumed the source start address is 4-byte aligned
   // to fix hw issue!!!, soure limit must preserve 8 bytes for CRC (crc reads faster than image decoder)
   if (is_src_end)
   {
      end_adr = (src_start_adr + src_sz_byte - 1);
   }
   else
   {
      ASSERT(src_sz_byte >= 9);   // last part of source must have size more than 9
      end_adr = (src_start_adr + src_sz_byte - 1 - 8);
   }
   DRV_WriteReg32(PNG_IN_START, src_start_adr);
   DRV_WriteReg32(PNG_IN_END, end_adr);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_canvas(PNG_HW_INFO *hwcfg)
{
   kal_uint32 sz_byte;
   kal_uint32 adr_value;
   kal_uint16 height = hwcfg->canvas_height;
   kal_uint16 width = hwcfg->canvas_width;

   // canvas (png lcd display buffer) start addres and end address must be word aligned
   if(( 0 != (((kal_uint32)(hwcfg->canvasStartAddr)) & 0x03)))
   {
      ASSERT(0);
      return PNG_STATUS_ERROR_INVALID_BUFFER;
   }

   switch (hwcfg->canvasColorFormat)
   {
       case PNG_FORMAT_RGB565:
          sz_byte = 2 * width * height;
          DRV_WriteReg32(PNG_OUT_FROMAT, 1);
          break;

       case PNG_FORMAT_RGB888:
          sz_byte = 3 * width * height;
          DRV_WriteReg32(PNG_OUT_FROMAT, 2);
          break;

       case PNG_FORMAT_ARGB8888:
          sz_byte = 4 * width * height;
          DRV_WriteReg32(PNG_OUT_FROMAT, 3);
          break;

       default:
          // default setting is RGB565
          sz_byte = 2 * width * height;
          DRV_WriteReg32(PNG_OUT_FROMAT, 1);
          hwcfg->canvasColorFormat = PNG_FORMAT_RGB565;
          break;
   }

   adr_value = ((kal_uint32)(hwcfg->canvasStartAddr) + sz_byte);
   // forward 4-byte aligned
   adr_value += 4 - (adr_value % 4) ;

   DRV_WriteReg32(PNG_OUT_START, (kal_uint32)(hwcfg->canvasStartAddr));    // must be word aligned
   DRV_WriteReg32(PNG_OUT_END, adr_value);                                 // must be word aligned
   DRV_WriteReg32(PNG_OUT_WH, width << 16 | height);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_output_window(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png)
{
   kal_uint16 src_w, src_h, dst_w, dst_h;

   src_w = png->width;
   src_h = png->height;
   dst_w = hwcfg->outputWindowWidth;
   dst_h = hwcfg->outputWindowHeight;

   // set output window (destination image) position
   DRV_WriteReg32(PNG_DST_POS, ((hwcfg->outputWindow_x & 0xFFFF) << 16) | (hwcfg->outputWindow_y & 0xFFFF));

   // compute resizing ration
   DRV_WriteReg32(PNG_RATIO_W1, ((    dst_w / src_w) << 16) | ((    dst_w % src_w) & 0xFFFF)) ;
   DRV_WriteReg32(PNG_RATIO_W2, ((2 * dst_w / src_w) << 16) | ((2 * dst_w % src_w) & 0xFFFF));
   DRV_WriteReg32(PNG_RATIO_W4, ((4 * dst_w / src_w) << 16) | ((4 * dst_w % src_w) & 0xFFFF));
   DRV_WriteReg32(PNG_RATIO_W8, ((8 * dst_w / src_w) << 16) | ((8 * dst_w % src_w) & 0xFFFF));

   DRV_WriteReg32(PNG_RATIO_H1, ((    dst_h / src_h) << 16) | ((    dst_h % src_h) & 0xFFFF));
   DRV_WriteReg32(PNG_RATIO_H2, ((2 * dst_h / src_h) << 16) | ((2 * dst_h % src_h) & 0xFFFF));
   DRV_WriteReg32(PNG_RATIO_H4, ((4 * dst_h / src_h) << 16) | ((4 * dst_h % src_h) & 0xFFFF));
   DRV_WriteReg32(PNG_RATIO_H8, ((8 * dst_h / src_h) << 16) | ((8 * dst_h % src_h) & 0xFFFF));

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_clip_window(PNG_HW_INFO *hwcfg)
{
   // set default clipWindow if clipping window is not set
   if (KAL_FALSE == hwcfg->ifSetClipWindow)
   {
      hwcfg->clipWindow_ul_x = 0;
      hwcfg->clipWindow_ul_y = 0;
      hwcfg->clipWindow_dr_x = hwcfg->canvas_width -1;
      hwcfg->clipWindow_dr_y = hwcfg->canvas_height -1;
   }

   DRV_WriteReg32(PNG_CLIP_POS_UL, hwcfg->clipWindow_ul_x << 16 |  hwcfg->clipWindow_ul_y);
   DRV_WriteReg32(PNG_CLIP_POS_DR, hwcfg->clipWindow_dr_x << 16 | hwcfg->clipWindow_dr_y);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_replace_color(PNG_HW_INFO *hwcfg)
{
   kal_uint32 orgColor, newColor;

   if (!hwcfg->ifSetColorReplacing)
   {
      DRV_WriteReg32(PNG_REPLACED_COLOR, 0);
      DRV_WriteReg32(PNG_REPLACE_AS_COLOR, 0);
      hwcfg->orgReplacedColor.red = 0;
      hwcfg->orgReplacedColor.green = 0;
      hwcfg->orgReplacedColor.blue = 0;
      hwcfg->newReplaceColor.red = 0;
      hwcfg->newReplaceColor.green = 0;
      hwcfg->newReplaceColor.blue = 0;
      _png_decoder_cfg.color_replace_enable = 0;

      return PNG_STATUS_OK;
   }

   switch (hwcfg->canvasColorFormat)
   {
      case PNG_FORMAT_RGB565:
         orgColor = (hwcfg->orgReplacedColor.red & 0x1F) << 11 |
                        (hwcfg->orgReplacedColor.green & 0x3F) << 5 |
                        (hwcfg->orgReplacedColor.blue & 0x1F);

         newColor = (hwcfg->newReplaceColor.red & 0x1F) << 11 |
                         (hwcfg->newReplaceColor.green & 0x3F) << 5 |
                         (hwcfg->newReplaceColor.blue & 0x1F);

         orgColor &= 0xFFFF;
         orgColor |= 1 << 24;    // enable color replacing

         newColor &= 0xFFFF;

         DRV_WriteReg32(PNG_REPLACED_COLOR, orgColor);  // set enable bit , 16 bits RGB for replaced color
         DRV_WriteReg32(PNG_REPLACE_AS_COLOR, newColor);  // 16 bits RGB for new replace color
         _png_decoder_cfg.color_replace_enable = 1;
         break;

      case PNG_FORMAT_RGB888:
         orgColor = hwcfg->orgReplacedColor.red << 16 | hwcfg->orgReplacedColor.green << 8 | hwcfg->orgReplacedColor.blue;
         newColor = hwcfg->newReplaceColor.red << 16 | hwcfg->newReplaceColor.green <<8 | hwcfg->newReplaceColor.blue;

         orgColor &= 0xFFFFFF;
         orgColor |= 1 << 24;    // enable color replacing

         newColor &= 0xFFFFFF;

         DRV_WriteReg32(PNG_REPLACED_COLOR, orgColor);  // set enable bit , 24 bits RGB for replaced color
         DRV_WriteReg32(PNG_REPLACE_AS_COLOR, newColor);  //24 bits RGB for new replace color
         _png_decoder_cfg.color_replace_enable = 1;
         break;

      //when output color format is ARGB888, replaced color functionality should not be enabled
      default:
         DRV_WriteReg32(PNG_REPLACED_COLOR, 0);
         hwcfg->orgReplacedColor.red = 0;
         hwcfg->orgReplacedColor.green = 0;
         hwcfg->orgReplacedColor.blue = 0;
         hwcfg->newReplaceColor.red = 0;
         hwcfg->newReplaceColor.green = 0;
         hwcfg->newReplaceColor.blue = 0;

         _png_decoder_cfg.color_replace_enable = 0;
         break;
   }

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_blending_buffer(void *blend_buf_adr)
{
   DRV_WriteReg32(PNG_B_STAR_ADDR, (kal_uint32)blend_buf_adr);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_alpha_value(kal_int32 userAlpha)
{
   kal_uint32 tmp_reg32;

   tmp_reg32 = DRV_Reg32(PNG_A_VALUE);
   DRV_WriteReg32(PNG_A_VALUE, tmp_reg32 & 0xFFFFFF00 | userAlpha);

   _png_decoder_cfg.user_alpha_is_set = 1;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_blending_mode(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png_ptr)
{
   PNG_BLEND_MODE_ENUM mode;
   PNG_DECODE_COLOR_FORMAT_ENUM color_format;

   if (!hwcfg->blendingBufferStartAddr)
   {
      // blending buffer start address is not set
      hwcfg->blendingMode = PNG_BLEND_NONE;
   }

   mode = hwcfg->blendingMode;
   color_format = hwcfg->blend_buf_format;

   switch (mode)
   {
      case PNG_BLEND_NONE:
         DRV_WriteReg32(PNG_ALPHA_BLEND, 0);
         break;

      case PNG_BLEND_FILE_ALPHA:
         if (0 == _png_decoder_cfg.trans_enable)
         {
            DRV_WriteReg32(PNG_ALPHA_BLEND, 0);  // no blending
            hwcfg->blendingMode = PNG_BLEND_NONE;
         }
         else
         {
            DRV_WriteReg32(PNG_ALPHA_BLEND, 1);
         }
         break;

      case PNG_BLEND_BUFFER:
         // this mode only works when blending buffer is ARGB mode
         if (PNG_FORMAT_ARGB8888 != color_format)
         {
            DRV_WriteReg32(PNG_ALPHA_BLEND, 0);  // no blending
            hwcfg->blendingMode = PNG_BLEND_NONE;
         }
         else
         {
            DRV_WriteReg32(PNG_ALPHA_BLEND, 2);
         }
         break;

      case PNG_BLEND_USER_ASSIGNED:
         if (0 == _png_decoder_cfg.user_alpha_is_set)
         {
            DRV_WriteReg32(PNG_ALPHA_BLEND, 0);    // no blending
            hwcfg->blendingMode = PNG_BLEND_NONE;
         }
         DRV_WriteReg32(PNG_ALPHA_BLEND, 3);
         break;

      default:
         // default blending mode is none
         DRV_WriteReg32(PNG_ALPHA_BLEND, 0);
         hwcfg->blendingMode = PNG_BLEND_NONE;
         break;
   }

   switch (color_format)
   {
      case PNG_FORMAT_RGB565:
         DRV_WriteReg32(PNG_B_FORMAT, 1);
         break;

      case PNG_FORMAT_RGB888:
         DRV_WriteReg32(PNG_B_FORMAT, 2);
         break;

      case PNG_FORMAT_ARGB8888:
         DRV_WriteReg32(PNG_B_FORMAT, 3);
         break;

      default:
         // default blending mode is RGB565
         DRV_WriteReg32(PNG_B_FORMAT, 1);
         hwcfg->blend_buf_format = PNG_FORMAT_RGB565;
         break;
   }

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_decode_start(PNG_HW_INFO *hwcfg, MY_PNG_INFO *png)
{
   kal_uint32 tmp_reg32;
   kal_uint32 ret;
   kal_uint32 bytes_per_pixel = 0;

   // ---------------------mandatory-----------------
   // pngDrvSetWorkingbuffer() has been invoked
   // png_drv_set_source_data() has been invoked
   // png_drv_hook_irq_callback() has been invoked

   //------------------check supported image size--------------------
   switch(png->color_type)
   {
      case PNG_COLOR_TYPE_GRAY:
      case PNG_COLOR_TYPE_PALETTE:
         bytes_per_pixel = 1;
         break;
      case PNG_COLOR_TYPE_RGB:
         bytes_per_pixel = 3;
         break;
      case PNG_COLOR_TYPE_GA:
         bytes_per_pixel = 2;
      case PNG_COLOR_TYPE_RGBA:
         bytes_per_pixel = 4;
         break;
      default:
         ASSERT(0);
         break;
   }

   if (png->width > PNG_SRC_MAX_W || png->height > PNG_SRC_MAX_H)
   {
      return PNG_STATUS_ERROR_UNSUPPORTED_FILE_DIMENSION;
   }
   else if ((png->height * (png->width * bytes_per_pixel + 1)) >= (1 << 23)) /// HW limitation
   {
      return PNG_STATUS_ERROR_UNSUPPORTED_FILE_DIMENSION;
   }

   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

   // --------------set source image width/height in pixels-----------------------
   tmp_reg32 = (png->width << 16) | (png->height & 0xFFFF);
   DRV_WriteReg32(PNG_SRC_WH, tmp_reg32);

   // set source image pixel count
   DRV_WriteReg32(PNG_SRC_PXL_CNT, png->width * png->height);

   // set interlace control
   DRV_WriteReg32(PNG_INTERLACE_CTRL, png->interlace_method);

   // -------------setting info from png image header ---------------
   //source color type
   tmp_reg32 = ((png->bit_depth & 0x1F) << 3) | (png->color_type & 0x07);
   DRV_WriteReg32(PNG_COLOR_TYPE, tmp_reg32);

   // --------------set background color---------------------------
   if (png->valid & PNG_INFO_bKGD)     // bKGD is parsed
   {
      switch (png->color_type)
      {
         case PNG_COLOR_TYPE_PALETTE:
         // background color of palette-type has been looked up upon bKGD chunk is parsed
         case PNG_COLOR_TYPE_RGB:
         case PNG_COLOR_TYPE_RGBA:
         {
            kal_uint32 bk_r, bk_g, bk_b;

            bk_r = png->background.red;
            bk_g = png->background.green;
            bk_b = png->background.blue;
            if (png->bit_depth > 8)
            {
               bk_r = bk_r >> (png->bit_depth - 8);
               bk_g = bk_g >> (png->bit_depth - 8);
               bk_b = bk_b >> (png->bit_depth - 8);

            }

            tmp_reg32 = ((bk_r & 0xFF) << 16)  |
                              ((bk_g & 0xFF) << 8) |
                              ((bk_b & 0xFF));
            DRV_WriteReg32(PNG_BK_COLOR, tmp_reg32);

            break;
         }

         case PNG_COLOR_TYPE_GRAY:
         case PNG_COLOR_TYPE_GA:
         {
            kal_uint32 bk_gray;

            bk_gray = png->background.gray;
            if (png->bit_depth > 8)
            {
               bk_gray = bk_gray >> (png->bit_depth - 8);
            }
            DRV_WriteReg32(PNG_BK_COLOR, (bk_gray & 0xFF) << 24);

            break;
         }

         default:
            break;

      }

   }


   // -----------set palette entry number & transparency table entry number-----------------
   if (!(png->valid & PNG_INFO_PLTE))
   {
      png->num_palette = 0;
   }
   if (!(png->valid & PNG_INFO_tRNS))
   {
      png->num_trans = 0;
   }

   /// loreal 2008.05.19, fix hw behavior when num_trans = 1
   if ((1 == png->num_trans) && (PNG_COLOR_TYPE_PALETTE == png->color_type) && (0 != *(kal_uint8 *)hwcfg->trnsTableAddr))
   {
      DRV_WriteReg32(PNG_ENTRY_NUM, (png->num_palette << 16) | 0x2);
   }
   else
   {
      DRV_WriteReg32(PNG_ENTRY_NUM, (png->num_palette << 16) | png->num_trans);
   }

   // ----------------------------------set alpha value -----------------------------

   tmp_reg32 = DRV_Reg32(PNG_A_VALUE);

   if (png->num_trans > 0 ||
       png->color_type == PNG_COLOR_TYPE_GA ||
       png->color_type == PNG_COLOR_TYPE_RGBA)
   {
      _png_decoder_cfg.a_en = 0;  // use file alpha

      tmp_reg32 &=  0xFFFF;
      if ((hwcfg->blendingMode != PNG_BLEND_NONE) &&
          (hwcfg->canvasColorFormat == PNG_FORMAT_ARGB8888))
      {
          tmp_reg32 |= (1 << 16);    /// use dst_a_value
          {
             tmp_reg32 |= (0xFF << 8); /// use 0xFF as output alpha
          }
      }
      DRV_WriteReg32(PNG_A_VALUE, tmp_reg32);
   }
   else
   {
      _png_decoder_cfg.a_en = 1;  // use dst_a_value

      tmp_reg32 &= 0xFFFF;
      tmp_reg32 |= (1 << 16);    /// use dst_a_value
      tmp_reg32 |= (0xFF << 8);  /// set default alpha as 255
      DRV_WriteReg32(PNG_A_VALUE, tmp_reg32);
   }

 // ---------------------set transparency control -----------------------------

   if (png->valid & PNG_INFO_tRNS)
   {
      _png_decoder_cfg.trans_enable = 1;
      _png_decoder_cfg.bk_color_disable = 0;

      switch(png->color_type)
      {
         case PNG_COLOR_TYPE_PALETTE:
            _png_decoder_cfg.trans_tbl_enable = 1;
            /// loreal 2008.05.19, fix hw behavior when num_trans = 1
            if ((1 == png->num_trans) && (0 == *(kal_uint8 *)hwcfg->trnsTableAddr))
            {
               _png_decoder_cfg.bk_color_disable = 1;
            }
            break;

         case PNG_COLOR_TYPE_GRAY:
         case PNG_COLOR_TYPE_RGB:
            _png_decoder_cfg.trans_key_enable = 1;
            DRV_WriteReg32(PNG_TRAN_KEY1, (png->trans.gray & 0xFFFF) << 16 | (png->trans.red & 0xFFFF));
            DRV_WriteReg32(PNG_TRAN_KEY2, (png->trans.green & 0xFFFF) << 16 | (png->trans.blue & 0xFFFF));
            /// loreal 2008.05.19, fix hw behavior when num_trans = 1
            if (1 == png->num_trans)
            {
               _png_decoder_cfg.bk_color_disable = 1;
            }
            break;

         default:
             _png_decoder_cfg.trans_tbl_enable = 0;
             _png_decoder_cfg.trans_key_enable = 0;
            break;
      }
   }
   else if ((PNG_COLOR_TYPE_GA == png->color_type) ||
           (PNG_COLOR_TYPE_RGBA == png->color_type))
   {
      _png_decoder_cfg.trans_enable = 1;
      _png_decoder_cfg.trans_tbl_enable = 0;
      _png_decoder_cfg.trans_key_enable = 0;
   }
   else
   {
      _png_decoder_cfg.trans_enable = 0;
      _png_decoder_cfg.trans_tbl_enable = 0;
      _png_decoder_cfg.trans_key_enable = 0;
   }

   /// 2008.05.19
   #if 1
   if (PNG_FORMAT_ARGB8888 == hwcfg->canvasColorFormat)
   {
      /// when transparent key hits, A=0, RGB would be bk color is noout is disabled, even if bKGD does not exist
      _png_decoder_cfg.bk_color_disable = 0;
   }
   #endif

   tmp_reg32 = _png_decoder_cfg.trans_key_enable << 3 |
               _png_decoder_cfg.trans_tbl_enable << 2 |
               _png_decoder_cfg.bk_color_disable << 1 |
               _png_decoder_cfg.trans_enable;

   DRV_WriteReg32(PNG_TRAN_CON, tmp_reg32 & 0xF);

   // ----------------setting hw config. from GDI -----------------------------

   ret = png_drv_set_canvas(hwcfg);
   if (ret != PNG_STATUS_OK)
   {
      return ret;
   }

   png_drv_set_output_window(hwcfg, png);
   png_drv_set_clip_window(hwcfg);

   if (-1 == png_drv_intersect_region(hwcfg))
   {
      // intersection is null set, so skipping hw decoding directly
      return PNG_STATUS_ERROR_NULL_OUTPUT_WINDOW;
   }

   png_drv_set_alpha_value(hwcfg->userSetAlphaValue);
   png_drv_set_blending_buffer(hwcfg->blendingBufferStartAddr);
   png_drv_set_blending_mode(hwcfg, png);
   png_drv_set_replace_color(hwcfg);

   // ------------------trigger hw decoder------------------------------
   png_drv_decode_resume(hwcfg);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_decode_resume(PNG_HW_INFO *hwcfg)
{
   kal_uint32 *ptr;

   /// 2008.05.21 check memory guard pattern
   ptr = (kal_uint32 *)hwcfg->colorTableStartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += COLOR_TBL_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->HCLENStartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += HCLEN_TBL_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->HLITStartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += HLIT_TBL_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->HDISTStartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += HDIST_TBL_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->lineBuff0StartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += LINE_BUF_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->lz77StartAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += LZ77_BUF_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   ptr = (kal_uint32 *)hwcfg->trnsTableAddr;
   _checkMemGuardHeader(ptr - 1);
   ptr += TRNS_TBL_MAX_SIZE;
   _checkMemGuardFooter(ptr);

   // start timer to handle hw processing timeout
   _png_drv_start_timer(hwcfg->timeoutMsec);

   DRV_WriteReg8(PNG_IRQ_STATUS, 0);   // clear previous irq status
   DRV_WriteReg32(PNG_IN_CONSUMED_BITS, 0);
   #if PNG_DEBUG
   if (0 == png_hw_trigger_time)
   {
      kal_get_time(&png_hw_trigger_time);
   }
   #endif
   DRV_WriteReg8(PNG_DECODE_CTRL, 1);  // enable png decoder

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_get_working_buffer_size(kal_uint32 *internal_mem_sz, kal_uint32 *external_mem_sz)
{
   *internal_mem_sz = (kal_uint32)0;

   /// the more INT_WORK_BUFFER_SIZE size is to be reserved by GDI,
   /// We might not have enough internal memory.
   /// When situation occur, we use the external instead of internal memory
   *external_mem_sz = (kal_uint32)(EXT_WORK_BUFFER_SIZE + INT_WORK_BUFFER_SIZE);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
png_drv_set_bg_color_out(MY_PNG_INFO *png)
{
   if (png->valid & PNG_INFO_bKGD)
   {
         // file built-in bg color is available
         _png_decoder_cfg.bk_color_disable = 0;
   }
   else
   {
      _png_decoder_cfg.bk_color_disable = 1;
   }

   return PNG_STATUS_OK;
}



void
png_drv_get_decode_status(kal_int32 *status_code)
{
   kal_int32 current_status;

   current_status = DRV_Reg(PNG_IRQ_STATUS) & PNG_DECODER_IRQ_EN_ALL;

   if (PNG_IRQ_STATUS_IDLE == current_status)
   {
      *status_code = PNG_STATUS_IN_DECODING;
      return;
   }
   else if (PNG_IRQ_STATUS_IN_EMPTY == current_status)
   {
      *status_code = PNG_STATUS_DECODE_INCOMPLETE;
      return;
   }
   else if (PNG_IRQ_STATUS_IMG_COMPLETE == current_status)
   {
      *status_code = PNG_STATUS_OK;
      return;
   }
   else
   {
      *status_code = PNG_STATUS_ERROR_DECODE_FAILED;
      return;
   }
}



#endif   /// #if defined(__PNG_DECODER_6268_SERIES__)
