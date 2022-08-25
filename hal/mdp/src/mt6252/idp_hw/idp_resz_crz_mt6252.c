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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    idp_resz_crz_mt6252.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2014 chrono.wu
 * removed!
 * 	.
 *
 * 10 14 2013 chrono.wu
 * removed!
 * 	.
 *
 * 07 18 2013 chrono.wu
 * removed!
 * fix change buffer condition for 1 pass preview case.
 *
 * 03 25 2013 chrono.wu
 * removed!
 * MT6260 WVGA Camera features support full screen.
 *
 * 12 25 2012 peter.wang
 * removed!
 * .
 * 
 * 09 24 2012 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 *
 * 04 02 2012 peter.wang
 * removed!
 * .
 *
 * 03 22 2012 peter.wang
 * removed!
 * .
 *
 * 02 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 27 2011 peter.wang
 * removed!
 * .
 *
 * 12 07 2011 peter.wang
 * removed!
 * .
 *
 * 11 29 2011 peter.wang
 * removed!
 * .
 *
 * 11 17 2011 peter.wang
 * removed!
 * .
 *
 * 08 29 2011 peter.wang
 * removed!
 * .
 *
 * 05 23 2011 peter.wang
 * removed!
 * .
 *
 * 05 23 2011 peter.wang
 * removed!
 * .
 *
 * 05 11 2011 peter.wang
 * removed!
 * .
 *
 * 05 09 2011 peter.wang
 * removed!
 * .
 *
 * 05 02 2011 peter.wang
 * removed!
 * .
 *
 * 04 29 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 04 18 2011 peter.wang
 * removed!
 * .
 *
 * 04 15 2011 peter.wang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 18 2010 cm.huang
 * NULL
 * .
 *
 * 11 17 2010 cm.huang
 * NULL
 * .
 *
 * 11 15 2010 cm.huang
 * NULL
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
 * macros and options
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/****************************************************************************
 * include directives
 ****************************************************************************/
#include <idp_define.h>

#if defined(DRV_IDP_6252_SERIES)

#include <idp_core.h>
#include <mt6252\idp_hw\idp_resz_crz.h>
#include "img_common_enum.h"
#include "emi_sw.h" // For resizer driver to learn which memory type is used in the system

// MDP_C_MODEL is only defined when this file is used in FPGA emulation and the file is compileed on PC side based on MDP HW C models
#if defined(MDP_C_MODEL)
#include "resizer_reg.h"
#endif

/****************************************************************************
 * local macros and options
 ****************************************************************************/

/****************************************************************************
 * external symbols
 ****************************************************************************/
IDP_HW_COMMON_API_DECLARATION(resz_crz)

/****************************************************************************
 * local variables
 ****************************************************************************/
void *idp_resz_crz_done_intr_cb_param;
void (*idp_resz_crz_done_intr_cb)(void *);

void *idp_resz_crz_pass_1_start_intr_cb_param;
void (*idp_resz_crz_pass_1_start_intr_cb)(void *);

void *idp_resz_crz_pixel_dropped_intr_cb_param;
void (*idp_resz_crz_pixel_dropped_intr_cb)(void *);

void *idp_resz_crz_lock_drop_frame_intr_cb_param;
void (*idp_resz_crz_lock_drop_frame_intr_cb)(void *);


static idp_hw_owner_t owner;
/****************************************************************************
 * external function bodies
 ****************************************************************************/
void
idp_resz_crz_LISR(void)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    kal_uint32 reg;

#if !defined(MDP_C_MODEL)
    IRQMask(IRQ_RESZ_CODE);
#endif

    reg = REG_CRZ_INT;

    // Note this!!
    // we remove this checking from MT6236...
    // If MT6236 CRZ receives init signal from ISP, it will clean the interrupt bit from CRZ_INT_REG.
    // But if the interrupt is already asserted, this handler will be entered but no interrupt bit is found...
    //
    // ASSERT(0x0 != reg);

    if (reg & CRZ_INT_FEND_BIT)
    {
        if (idp_resz_crz_done_intr_cb != NULL)
        {
            idp_resz_crz_done_intr_cb(idp_resz_crz_done_intr_cb_param);
        }
    }

    if (reg & CRZ_INT_FSTART1_BIT)
    {
        if (idp_resz_crz_pass_1_start_intr_cb != NULL)
        {
            idp_resz_crz_pass_1_start_intr_cb(idp_resz_crz_pass_1_start_intr_cb_param);
        }
    }

    if (reg & CRZ_INT_LOCK_DROP_FRAME_BIT)
    {
        if (idp_resz_crz_lock_drop_frame_intr_cb != NULL)
        {
            idp_resz_crz_lock_drop_frame_intr_cb(idp_resz_crz_lock_drop_frame_intr_cb_param);
        }
    }

    if (reg & CRZ_INT_PIXEL_DROP_BIT)
    {
        if (idp_resz_crz_pixel_dropped_intr_cb != NULL)
        {
            idp_resz_crz_pixel_dropped_intr_cb(idp_resz_crz_pixel_dropped_intr_cb_param);
        }
    }

#if !defined(MDP_C_MODEL)
    IRQUnmask(IRQ_RESZ_CODE);
#endif

#endif // #if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
}

/** \brief Initialize the CRZ subsystem.
 *
 * \ingroup crz
 *
 * This functino will setup the interrupt for the CRZ
 * to level sensitive, and unmask all the interrupts for the
 * CRZ.
 */
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void
idp_resz_crz_init_real(void)
{
#if defined(__MTK_TARGET__) && !defined(MDP_C_MODEL)
#if defined(IDP_FULL_ISR_SUPPORT)
    IRQ_Register_LISR(IRQ_RESZ_CODE, idp_resz_crz_LISR, "IDP_RESZ_CRZ");
#endif
    IRQSensitivity(IRQ_RESZ_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_RESZ_CODE);
#endif // #if defined(__MTK_TARGET__) && !defined(MDP_C_MODEL)
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/**
 * crz_check_size_limitation.
 * Check if the source/target size is not over the limitation of MT6252 CRZ...
 *
 * @param source_width
 * @param source_height
 * @param target_width
 * @param target_height
 * @param input_src
 * @param src_yuv_color_fmt
 *
 * @return KAL_TRUE, the set of sizes is OK. KAL_FALSE, o.w.
 */
kal_bool
crz_check_size_limitation(
    kal_uint32 source_width,
    kal_uint32 source_height,
    kal_uint32 target_width,
    kal_uint32 target_height,
    idp_module_enum_t  input_src,
    MM_IMAGE_COLOR_FORMAT_ENUM  src_yuv_color_fmt)
{
    if (
        // the upper limit of size
        (0 == source_width)
         || (0 == source_height)
         || (0 == target_width)
         || (0 == target_height)
         || (2047 < source_width)
         || (2047 < source_height)
         || (1023 < target_height))  //resizer max. target height 1023
     {
         return KAL_FALSE;
     }

#if defined(MT6252H) || defined(MT6252)
     if (
         ((source_width == target_width) && (source_height == target_height) && (1023 < target_width)) // no resize
         ||((IDP_MODULE_OUTER_ISP == input_src) && (320 < target_width))  //camera input
         ||((IDP_MODULE_IMGDMA_RDMA0 == input_src) && (640 < target_width)))  //memory input
     {
         return KAL_FALSE;
     }
#endif

     // check soruce size alignment
     if (
        ((IDP_MODULE_IMGDMA_RDMA0 == input_src) && (0 != (source_width & 0x1))) //memory in format only UYVY422 YUV422 YUV 420
         ||((IDP_MODULE_IMGDMA_RDMA0 == input_src) && (MM_IMAGE_COLOR_FORMAT_YUV420 == src_yuv_color_fmt) && (0 != (source_height & 0x1))))
     {
         return KAL_FALSE;
     }

     return KAL_TRUE;
}

/**
 * Resize soft reset function.
 *
 * @param none.
 *
 * @return.
 */
static void crz_soft_reset(void)
{
    CRZ_RESET();

    // Base on datasheet, resizer itself would clear this bit to 0 when it is ready to be enable.
    {
        kal_bool  rst_done;
        kal_uint32 last_time = drv_get_current_time();

        // Check if crz reset busy, if busy over 2 tick, assert... according to Abrams, < 2us
        do
        {
            rst_done = CRZ_IS_RESET_FINISH();
        } while ((KAL_FALSE == rst_done) &&
                     (2 >= drv_get_duration_tick(last_time, drv_get_current_time())));
    }
}

void
idp_resz_crz_open_real(void)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    CRZ_POWERON();
    crz_soft_reset();
#endif
}

void
idp_resz_crz_close_real(void)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    CRZ_POWEROFF();
#endif
}


/** \brief Programmers can use this function to config CRZ.
 *
 * \ingroup crz
 *
 * Before using this function, CRZ should be turned off. In
 * MT6238, TK6516, MT6516, CRZ can only use internal memory
 * (dedicated memory).
 *
 * \param crz_struct CRZ config structure
 */
kal_bool
idp_resz_crz_config_real(
    idp_resz_crz_struct * const p_crz_struct,
    kal_bool const config_to_hardware)
{
#if defined(__MTK_TARGET__)
    kal_uint16 src_width_1 = 0, src_height_1 = 0;// the src size just before internal resizer, after cropped
    kal_uint16 tar_width_1 = 0;
    kal_uint32 h_ratio;
    kal_uint32 v_ratio;
    kal_uint16 wmsz1;

    CRZ_FORCE_V_RESIZE_ENABLE();
    CRZ_FORCE_H_RESIZE_DISABLE();

    // auto restart
    if (KAL_TRUE == p_crz_struct->auto_restart)
    {
        CRZ_SET_CONT_RUN_MODE();
    }
    else
    {
        CRZ_SET_SINGLE_RUN_MODE();
    }

    //always enable double bufferd register, otherwise, will cause problem
    CRZ_DOUBLE_BUFFERD_REGISTER_ENABLE();

    // frame sync
    if (KAL_TRUE == p_crz_struct->hw_frame_sync)
    {
        CRZ_ENABLE_HW_FRAME_SYNC(); //Abrams said only set bit 2
    }
    else
    {
        CRZ_DISABLE_HW_FRAME_SYNC();
    }

    // interrupt
    if (KAL_TRUE == p_crz_struct->fend_intr_en)
    {
        CRZ_INTERRUPT_FEND_ENABLE();
        idp_resz_crz_done_intr_cb = p_crz_struct->fend_intr_cb;
        idp_resz_crz_done_intr_cb_param = p_crz_struct->fend_intr_cb_param;
    }
    else
    {
        CRZ_INTERRUPT_FEND_DISABLE();
    }

    if (KAL_TRUE == p_crz_struct->fstart1_intr_en)
    {
        CRZ_INTERRUPT_FSTART1_ENABLE();
        idp_resz_crz_pass_1_start_intr_cb = p_crz_struct->fstart1_intr_cb;
        idp_resz_crz_pass_1_start_intr_cb_param = p_crz_struct->fstart1_intr_cb_param;
    }
    else
    {
        CRZ_INTERRUPT_FSTART1_DISABLE();
    }

#if !defined(MT6260) && !defined(MT6261) && !defined(MT2501) && !defined(MT2502)
    CRZ_INTERRUPT_FSTART2_DISABLE();
#endif

    if (KAL_TRUE == p_crz_struct->pixel_dropped_intr_en)
    {
        CRZ_INTERRUPT_PXLDROP_ENABLE();
        idp_resz_crz_pixel_dropped_intr_cb = p_crz_struct->pixel_dropped_intr_cb;
        idp_resz_crz_pixel_dropped_intr_cb_param = p_crz_struct->pixel_dropped_intr_cb_param;
    }
    else
    {
        CRZ_INTERRUPT_PXLDROP_DISABLE();
    }

    CRZ_INTERRUPT_MEM_IN_DONE_DISABLE();

    if (KAL_TRUE == p_crz_struct->lock_drop_frame_intr_en)
    {
        CRZ_INTERRUPT_LOCK_DROP_FRAME_ENABLE();
        idp_resz_crz_lock_drop_frame_intr_cb = p_crz_struct->lock_drop_frame_intr_cb;
        idp_resz_crz_lock_drop_frame_intr_cb_param = p_crz_struct->lock_drop_frame_intr_cb_param;
    }
    else
    {
        CRZ_INTERRUPT_LOCK_DROP_FRAME_DISABLE();
    }


    if (1 > p_crz_struct->src_width) {return KAL_FALSE;}
    if (1 > p_crz_struct->src_height) {return KAL_FALSE;}
    if (2047 < p_crz_struct->src_width) {return KAL_FALSE;}
    if (2047 < p_crz_struct->src_height) {return KAL_FALSE;}
    if (1 > p_crz_struct->tar_width) {return KAL_FALSE;}
    if (1 > p_crz_struct->tar_height) {return KAL_FALSE;}

#if defined(MT6252H) || defined(MT6252)
    // check target width from design spec.
    if ((KAL_FALSE == p_crz_struct->crop_en1) &&
        (p_crz_struct->src_width == p_crz_struct->tar_width) &&
        (p_crz_struct->src_height == p_crz_struct->tar_height))
    {
        if (1023 < p_crz_struct->tar_width) {return KAL_FALSE;} //resizer max. target width 1023 if w/o resizing
    }
    else if ((KAL_TRUE == p_crz_struct->crop_en1) &&
            ((p_crz_struct->crop_right1 - p_crz_struct->crop_left1 + 1) == p_crz_struct->tar_width) &&
            ((p_crz_struct->crop_bottom1 - p_crz_struct->crop_top1 + 1) == p_crz_struct->tar_height))
    {
        if (1023 < p_crz_struct->tar_width) {return KAL_FALSE;} //resizer max. target width 1023 if w/o resizing
    }
    else if (IDP_MODULE_OUTER_ISP == p_crz_struct->input_src1) //camera input
    {
        if (320 < p_crz_struct->tar_width) {return KAL_FALSE;}
    }
    else if (IDP_MODULE_IMGDMA_RDMA0 == p_crz_struct->input_src1)//memory input
    {
        if (640 < p_crz_struct->tar_width) {return KAL_FALSE;}
    }
    else
    {
         return KAL_FALSE;
    }
    if (1023 < p_crz_struct->tar_height) {return KAL_FALSE;} //resizer max. target height 1023, but rotdma max source height 1023
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // check target width from design spec.
    if ((KAL_FALSE == p_crz_struct->crop_en1) &&
        (p_crz_struct->src_width == p_crz_struct->tar_width) &&
        (p_crz_struct->src_height == p_crz_struct->tar_height))
    {
        if (2047 < p_crz_struct->tar_width) {return KAL_FALSE;} //resizer max. target width 2047 if w/o resizing
    }
    else if ((KAL_TRUE == p_crz_struct->crop_en1) &&
            ((p_crz_struct->crop_right1 - p_crz_struct->crop_left1 + 1) == p_crz_struct->tar_width) &&
            ((p_crz_struct->crop_bottom1 - p_crz_struct->crop_top1 + 1) == p_crz_struct->tar_height))
    {
        if (2047 < p_crz_struct->tar_width) {return KAL_FALSE;} //resizer max. target width 2047 if w/o resizing
    }
    else if (IDP_MODULE_OUTER_ISP == p_crz_struct->input_src1) //camera input
    {
        if (800 < p_crz_struct->tar_width) {return KAL_FALSE;}
    }
    else if (IDP_MODULE_IMGDMA_RDMA0 == p_crz_struct->input_src1)//memory input
    {
        if (1600 < p_crz_struct->tar_width) {return KAL_FALSE;}
    }
    else
    {
        return KAL_FALSE;
    }
    if (2047 < p_crz_struct->tar_height) {return KAL_FALSE;} //resizer max. target height 2047, but rotdma max source height 2047
#endif

    // Digital zoom change CRZ register, use lock to protect only partial parameters be updated
    CRZ_LOCK_ENABLE();

    if (KAL_FALSE == p_crz_struct->crop_en1)
    {
        src_width_1 = p_crz_struct->src_width;
        src_height_1 = p_crz_struct->src_height;
        CRZ_SET_CROP1_DISABLE() ;
    }
    else
    {
        src_width_1 = p_crz_struct->crop_right1 - p_crz_struct->crop_left1 + 1;
        src_height_1 = p_crz_struct->crop_bottom1 - p_crz_struct->crop_top1 + 1;
        CRZ_SET_CROP_ORIG1_SIZE(p_crz_struct->src_width, p_crz_struct->src_height);
        CRZ_SET_CROP_RANGE1(p_crz_struct->crop_left1, p_crz_struct->crop_right1, p_crz_struct->crop_top1, p_crz_struct->crop_bottom1);
        CRZ_SET_CROP1_ENABLE();
    }
    CRZ_SET_SRC_SIZE(src_width_1, src_height_1);
    CRZ_SET_TARGET_SIZE(p_crz_struct->tar_width, p_crz_struct->tar_height);

    tar_width_1 = p_crz_struct->tar_width;

  #if defined(IDP_TILE_MODE_SUPPORT)
    // The ratio and residual use original frame crop width and tar width
    if (p_crz_struct->tile_mode)
    {
        src_width_1 = p_crz_struct->tile_org_frame_width;
        tar_width_1 = p_crz_struct->tile_org_tar_width;
    }
  #endif

    if (tar_width_1 < src_width_1)
    {
        // H ratio
        h_ratio = (kal_uint32)(tar_width_1-1);
        h_ratio = h_ratio * (kal_uint32)(1 << CRZ_H_RATIO_SHIFT_BITS);
        h_ratio = h_ratio / ((kal_uint32)(src_width_1-1));
    }
    else
    {
        // H ratio
        h_ratio = (kal_uint32)(src_width_1);
        h_ratio = h_ratio * (kal_uint32)(1 << CRZ_H_RATIO_SHIFT_BITS);
        h_ratio = h_ratio / ((kal_uint32)(tar_width_1));
    }
    REG_CRZ_HRATIO1 = h_ratio;

    if (p_crz_struct->tar_height < src_height_1)
    {
        // V ratio
        v_ratio = (kal_uint32)(p_crz_struct->tar_height-1);
        v_ratio = v_ratio * (kal_uint32)(1 <<CRZ_H_RATIO_SHIFT_BITS);
        v_ratio = v_ratio / ((kal_uint32)(src_height_1-1));
    }
    else
    {
        // V ratio
        v_ratio = (kal_uint32)(src_height_1);
        v_ratio = v_ratio * (kal_uint32)(1 << CRZ_H_RATIO_SHIFT_BITS);
        v_ratio = v_ratio / ((kal_uint32)(p_crz_struct->tar_height));
    }
    REG_CRZ_VRATIO1 = v_ratio;

    //Horizontal Residual
    REG_CRZ_HRES1 = src_width_1 % tar_width_1;

    //Vertical Residual
    REG_CRZ_VRES1 = src_height_1 % p_crz_struct->tar_height;

#if defined(MT6252H) || defined(MT6252)
    wmsz1 = 1280 / (((p_crz_struct->tar_width + 3)  >> 2) << 2);
    if (wmsz1 < 2)    //so WT max 640
    {
        wmsz1 = 2;
    }
    else if (wmsz1 > 31)
    {
        wmsz1 = 31;
    }
#elif defined(MT6250)
    wmsz1 = 3200 / (((p_crz_struct->tar_width + 3)  >> 2) << 2);
    if (wmsz1 < 2)    //so WT max 1600
    {
        wmsz1 = 2;
    }
    else if (wmsz1 > 63)
    {
        wmsz1 = 63;
    }
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    wmsz1 = 1920 / (((p_crz_struct->tar_width + 3)  >> 2) << 2);
    if (wmsz1 < 2)    //so WT max 960
    {
        wmsz1 = 2;
    }
    else if (wmsz1 > 63)
    {
        wmsz1 = 63;
    }
#endif

    //Set Line size
    CRZ_SET_WMSZ1(wmsz1);

    CRZ_LOCK_DISABLE();

    switch(p_crz_struct->input_src1)
    {
        case IDP_MODULE_OUTER_ISP:
            CRZ_SET_INPUT_SRC1_CAM();
            break;

        case IDP_MODULE_IMGDMA_RDMA0:
            switch(p_crz_struct->mem_in_color_fmt1)
            {
                case MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422:
                    CRZ_SET_INPUT_SRC1_MEMORY_IN_UYVY422();
                    break;

                case MM_IMAGE_COLOR_FORMAT_YUV422:
                    CRZ_SET_INPUT_SRC1_MEMORY_IN_YUV422();
                    break;

                case MM_IMAGE_COLOR_FORMAT_YUV420:
                    CRZ_SET_INPUT_SRC1_MEMORY_IN_YUV420();
                    break;

                default:
                    return KAL_FALSE;
            }
            break;

        default:
            return KAL_FALSE;
    }

    if (p_crz_struct->two_pass_resize_en)
    {
        CRZ_ENABLE_2PASS();
    }
    else
    {
        CRZ_DISABLE_2PASS();
    }

    if (!p_crz_struct->clip_en)
    {
        if (p_crz_struct->src_buff_y_addr % 4 != 0) {return KAL_FALSE;}
        if (p_crz_struct->src_buff_u_addr % 4 != 0) {return KAL_FALSE;}
        if (p_crz_struct->src_buff_v_addr % 4 != 0) {return KAL_FALSE;}
    }

    CRZ_SET_YUV_SRC_ADDRESS( p_crz_struct->src_buff_y_addr,
                             p_crz_struct->src_buff_u_addr,
                             p_crz_struct->src_buff_v_addr);

    if (p_crz_struct->clip_en)
    {
        CRZ_MEMORY_IN_CLIP_ENABLE();
        CRZ_SET_MEMORY_IN_BG_WIDTH(p_crz_struct->org_width);
    }
    else
    {
        CRZ_MEMORY_IN_CLIP_DISABLE();
    }

#if defined(IDP_TILE_MODE_SUPPORT)
    if (p_crz_struct->tile_mode)
    {
        CRZ_ENABLE_TILE_MODE();
    }
    else
    {
        CRZ_DISABLE_TILE_MODE();
    }

    if (p_crz_struct->sa_en_x)
    {
        CRZ_TILE_SA_X1_ENABLE();
    }
    else
    {
        CRZ_TILE_SA_X1_DISABLE();
    }

    if (p_crz_struct->sa_en_y)
    {
        CRZ_TILE_SA_Y1_ENABLE();
    }
    else
    {
        CRZ_TILE_SA_Y1_DISABLE();
    }

    REG_CRZ_TILE_START_POS_X1 = p_crz_struct->tile_start_pos_x;
    REG_CRZ_TILE_START_POS_Y1 = p_crz_struct->tile_start_pos_y;

    CRZ_SET_BI_TRUNC_ERR_COMP1(p_crz_struct->tile_trunc_err_comp_x, p_crz_struct->tile_trunc_err_comp_y);
    CRZ_SET_BI_INIT_RESID1(p_crz_struct->tile_resid_x, p_crz_struct->tile_resid_y);
#endif

#endif // #if defined(__MTK_TARGET__)

    return KAL_TRUE;
}

kal_bool
idp_resz_crz_start_real(
    idp_resz_crz_struct const * const p_crz_struct)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    CRZ_START();
#endif
    return KAL_TRUE;
}

kal_bool
idp_resz_crz_stop_real(
    idp_resz_crz_struct const * const p_crz_struct)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    crz_soft_reset();
#endif

    return KAL_TRUE;
}

kal_bool
idp_resz_crz_is_busy_real(
    kal_bool * const p_busy,
    idp_resz_crz_struct const * const p_crz_struct)
{
#if defined(__MTK_TARGET__) || defined(MDP_C_MODEL)
    *p_busy = KAL_FALSE;
    // ctfang: do not check RUN2ST
    if ((REG_CRZ_STA & 0x17)) ///only check normal part
    {
        (*p_busy) = KAL_TRUE;
    }
#endif

    return KAL_TRUE;
}

void
idp_resz_crz_forced_reset(void)
{
#if defined(__MTK_TARGET__)
    crz_soft_reset();
    CRZ_START();
#endif
}

#if defined(__MTK_TARGET__)

kal_bool
idp_resz_crz_open(
    kal_uint32 * const key)
{
    kal_bool result;

    if (owner.key == 0)
    {
        result = idp_hw_open(&owner);
    }
    else
    {
        return KAL_FALSE;
    }

    if (KAL_TRUE == result)
    {
        idp_resz_crz_open_real();
        (*key) = owner.key;
    }
    else
    {
        (*key) = 0;
    }

    return result;
}

kal_bool
idp_resz_crz_close(
    kal_uint32 const key,
    idp_resz_crz_struct const * const config)
{
    kal_bool result;

    result = idp_resz_crz_stop_real(config);

    idp_resz_crz_close_real();

    result = idp_hw_close(&owner, key);

    return result;
}

kal_bool
idp_resz_crz_config(
    kal_uint32 const key,
    idp_resz_crz_struct * const config,
    kal_bool const config_to_hardware)
{
    return idp_resz_crz_config_real(config, config_to_hardware);
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

kal_bool
idp_resz_crz_init(void)
{
    memset(&owner, 0, sizeof(owner));
    owner.sem = kal_create_sem("IDP", 1);

    idp_resz_crz_init_real();

    return KAL_TRUE;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

kal_bool
idp_resz_crz_start(
    kal_uint32 const key,
    idp_resz_crz_struct const * const config)
{
    return idp_resz_crz_start_real(config);
}

kal_bool
idp_resz_crz_stop(
    kal_uint32 const key,
    idp_resz_crz_struct const * const config)
{
    return idp_resz_crz_stop_real(config);
}

kal_bool
idp_resz_crz_is_busy(
    kal_uint32 const key,
    kal_bool * const busy,
    idp_resz_crz_struct const * const config)
{
    return idp_resz_crz_is_busy_real(busy, config);
}

kal_bool
idp_resz_crz_is_in_use(void)
{
    return ((KAL_TRUE == idp_hw_can_be_used(&owner, 0)) ? KAL_FALSE : KAL_TRUE);
}

#else
IDP_HW_COMMON_API_DEFINITION(resz_crz)
#endif // (__MTK_TARGET__)



#endif // #if defined(DRV_IDP_6252_SERIES)


