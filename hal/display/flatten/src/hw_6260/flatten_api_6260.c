/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    flatten_api_6260.c
 *
 * Project:
 * --------
 *    MAUI/HAL/LWF
 *
 * Description:
 * ------------
 *    This file is the body of MT6260 GOVL HW driver.
 *    This file is only for target.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 01 21 2014 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 12 04 2013 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 10 18 2013 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 12 07 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 07 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 02 2012 hung-wen.hsieh
 * removed!
 * .
 * 
 * 10 16 2012 hung-wen.hsieh
 * removed!
 * .
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(MT6260) || defined(MT6261)  || defined(MT2501) || defined(MT2502)//???sht  && !defined(MT6276_S00)
// Only MT6276 E2 chip has this GOVL HW engine...
#if defined(__MTK_TARGET__)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_hisr.h"
#include "common/owftypes.h"
#include "mm_power_ctrl.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_release.h"
#include "debug\inc\lcd_catcher_log.h"
#include "init.h"

#include "mm_power_ctrl.h"
#include "wfd\inc\hw_6260\govl_if_6260_hw.h"   //Include for govl hw micro and register define
#include "dcl.h"

#include "flatten_api.h"
#include "flatten_api_internal.h"

#include "G2d_common_api.h"
#include "G2d_enum.h"





#if defined(DRV_FEATURE__MM_INTMEM_IF)
#include "mm_intmem.h"
#endif // #if defined(DRV_FEATURE__MM_INTMEM_IF)
// Use resource manager to share ROT_DMA1...
//#include "rm.h"



#ifdef __cplusplus
extern "C" {
#endif

#define GOVL_ASYNC_REQ_SUPPORT

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/

/*****************************************************************************
 *  Local variables
 ****************************************************************************/

static kal_eventgrpid	__flatten_event = KAL_NILEVENTGRP_ID;
static void   (* flattenCallback)(void *) = NULL;
static void*  flattenCBParam = NULL;
extern kal_bool system_init_status;
extern kal_bool INT_QueryExceptionStatus(void);
//#undef MTK_SLEEP_ENABLE
//#ifdef MTK_SLEEP_ENABLE //remove L1SM_SleepDsiable, in mm_enable_power will cover this
//extern kal_uint8 L1SM_GetHandle(void);

//extern void L1SM_SleepEnable(kal_uint8 HANDLE);

//extern void L1SM_SleepDisable(kal_uint8 HANDLE);

//static kal_uint8 govl_power_sleep_mode_hander;

//#endif


/*****************************************************************************
*  Local function definitions
****************************************************************************/

/** DESCRIPTION :
*    Turn on/off of GOVL power. \n
*  @param[in] turn_on Indicate turn on or off of GOVL power. KAL_TRUE means turn on, KAL_FALSE means turn off.\n
*  @return None
*  @remark
*/
__forceinline void __flatten_gOvl_PowerCtrl(kal_bool power_on)
{
    if (KAL_TRUE == power_on)
    {
        mm_enable_power(MMPWRMGR_G2D);//???sht mm_enable_power(MMPWRMGR_GOVL);
//#ifdef MTK_SLEEP_ENABLE //remove L1SM_SleepDsiable, in mm_enable_power will cover this
//        L1SM_SleepDisable(govl_power_sleep_mode_hander);
//#endif
    }
    else
    {
        while(GOVL_IS_RUNNING);
        mm_disable_power(MMPWRMGR_G2D);//???sht mm_disable_power(MMPWRMGR_GOVL);
//#ifdef MTK_SLEEP_ENABLE
//        L1SM_SleepEnable(govl_power_sleep_mode_hander);
//#endif
    }

}



/*****************************************************************************
*  API function definitions
****************************************************************************/

/*!
*  Convert Clockwise 0/90/180/270 degree to HW rotation/flip definition value.
*
*  \param device           Device handle
*  \param angle            Clockwise 0/90/180/270 degree
*  \param flip             Flip or not
*
*  \return                 HW rotation/flip definition in anti-clockwise.\n
*                          0xFFFFFFFF: means the passed paramrters are wrong\n
*
*/
// TODO: [m] This must be fixed...
__forceinline kal_uint32
__flatten_gOvl_CnvtAngleToHwDef(FLATTENRotationType angle, kal_bool flip)
{    
    switch (angle)
    {
    case FLATTEN_ROTATION_0:
        {
            return ((!flip) ? FLATTEN_GOVL_LAYER_ROTATE_NORMAL: FLATTEN_GOVL_LAYER_FLIP);
        }

    case FLATTEN_ROTATION_90:
        {
            return ((!flip) ? FLATTEN_GOVL_LAYER_ROTATE_270: FLATTEN_GOVL_LAYER_FLIP_ROTATE_270);
        }

    case FLATTEN_ROTATION_180:
        {
            return ((!flip) ? FLATTEN_GOVL_LAYER_ROTATE_180: FLATTEN_GOVL_LAYER_FLIP_ROTATE_180);
        }

    case FLATTEN_ROTATION_270:
        {
            return ((!flip) ? FLATTEN_GOVL_LAYER_ROTATE_90: FLATTEN_GOVL_LAYER_FLIP_ROTATE_90);
        }

    default:
        {
            ASSERT(0);
            return 0xffffff;
        }
    }
}

/*!
*  Convert flatten format definition to LCD HW register definition.
*
*  \param format           OWF image color format
*
*  \return                 FLATTEN_GOVL_LAYER_FORMAT_ENUM
*                          Handle to newly created stream, or OWF_INVALID_HANDLE if no
*                          stream could be created.\n
*/

__forceinline FLATTEN_GOVL_LAYER_FORMAT_ENUM
__flatten_gOvl_CnvtImgFormatToHwDef(FLATTEN_PIXEL_FORMAT format, kal_bool premultiplied)
{
    switch (format)
    {
     case FLATTEN_IMAGE_RGB565:  { return FLATTEN_GOVL_LAYER_RGB565; }

     case FLATTEN_IMAGE_ARGB8888:
        {
            if (premultiplied) { return FLATTEN_GOVL_LAYER_PARGB8888; }
            return FLATTEN_GOVL_LAYER_ARGB8888;
        }
     case FLATTEN_IMAGE_ARGB6666:
        {
            if (premultiplied) { return FLATTEN_GOVL_LAYER_PARGB6666; }
            return FLATTEN_GOVL_LAYER_ARGB6666;
        }
    case FLATTEN_IMAGE_UYVY:    { return FLATTEN_GOVL_LAYER_UYVY422; }

    case FLATTEN_IMAGE_RGB888:  { return FLATTEN_GOVL_LAYER_RGB888; }

    default:
        {
            ASSERT(0);
            return FLATTEN_GOVL_LAYER_RSVD;
        }
    }
}

/*!
*  Convert flatten Color Format to GOVL W2MWM Format HW definition.\n
*
*  \param format           Target image's format structure.\n
*
*  \return                 FLATTEN_LCD_WMEM_COLOR_FORMAT_ENUM: HW w2mem format definition value
*                          FLATTEN_LCD_WMEM_COLOR_RSVD means the input format is wrong.
*
*/


__forceinline FLATTEN_GOVL_WMEM_COLOR_FORMAT_ENUM
__flatten_gOvl_CnvtW2memFormatToHwDef(FLATTEN_PIXEL_FORMAT format, kal_bool premultiplied)
{
    switch (format)
    {
    case FLATTEN_IMAGE_RGB565:  { return FLATTEN_GOVL_WMEM_COLOR_RGB565; }
    case FLATTEN_IMAGE_ARGB8888:
        {
            if (premultiplied) { return FLATTEN_GOVL_WMEM_COLOR_ARGB8888_PIXEL_ALPHA; }
            return FLATTEN_GOVL_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA;
        }
    case FLATTEN_IMAGE_ARGB6666:
        {
            if (premultiplied) { return FLATTEN_GOVL_WMEM_COLOR_ARGB6666_PIXEL_ALPHA; }
            return FLATTEN_GOVL_WMEM_COLOR_ARGB6666_CONSTANT_ALPHA;
        }
    case FLATTEN_IMAGE_RGB888:  { return FLATTEN_GOVL_WMEM_COLOR_RGB888; }
    default:
        {
            ASSERT(0);
            return FLATTEN_GOVL_WMEM_COLOR_RSVD;
        }
    }
}

/*!
*  Execute all active event callbacks.
*
*  \param pPort             Port structure.\n
*  \param interruptStatus   The interrupt status\n
*  \return                  NA\n
*
*  \notice                  This fucntion is called in HISR and Blt function now to
*                           execute WFC's all registered callback functions.
*/
__forceinline static void
__flatten_gOvl_ExecActiveEventsCb(kal_uint32 interruptStatus)
{
    kal_uint32  triggerEvent;

    //hwEvent = FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT;
    triggerEvent = FLATTEN_GOVL_TRANSFER_COMPLETE_EVENT;

    {
        kal_set_eg_events(__flatten_event, triggerEvent, KAL_OR);
        if(flattenCallback != NULL)
        {
            flattenCallback(flattenCBParam);
            flattenCallback = NULL;  //destroy the callback pointor
        }
    }
    #if defined(FLATTEN_PERFORMANCE_PROFILING_SUPPORT)
    SLA_CustomLogging("FLH", 0);//FLH:Stop Flatten HW time profile
    #endif   
}

/** DESCRIPTION :
*    Call this function to wait specific event.\n
*  @param[in] NA
*  @return NA
*  @remark
*/
static kal_bool
__flatten_gOvlRot_WaitEvent(FlattenCtrlStruct *flatten_ctrl_config, FLATTENEventType event_type)
{
    FlattenCtrlStruct *pCtrlConfig = flatten_ctrl_config;
    //kal_bool c;
    kal_uint32 event_group;
    //kal_uint32 save_irq_mask;
    //kal_uint32 time_interval;
    //time_interval = FLATTEN_GOVL_TIMEOUT_INTERVAL; //3s


    if (FLATTEN_EVENT_DATA_TRANSFER_COMPLETE_MTK != event_type)
    {
        ASSERT(0); // for development stage debug...
    }

/*
#if !defined(GOVL_ASYNC_REQ_SUPPORT)
    c = KAL_FALSE;
#else
    c = (system_init_status == KAL_FALSE) && (!kal_if_hisr()) && (!kal_if_lisr()) && (!INT_QueryExceptionStatus());
#endif*/

    if((system_init_status == KAL_FALSE) && (!kal_if_hisr()) && (!kal_if_lisr()) && (!INT_QueryExceptionStatus()))
    {
        kal_status status = KAL_SUCCESS;
        FLATTEN_GOVL_GROT_EVENT_ENUM event;

        event = FLATTEN_GOVL_TRANSFER_COMPLETE_EVENT;		  
        if (pCtrlConfig->rotationAngle)
        {
            //using ROT to handle rotation... then wait ROT's event 
            event = FLATTEN_GROT_TRANSFER_COMPLETE_EVENT;
        }

        status = kal_retrieve_eg_events_timeout(__flatten_event, event,
            KAL_OR_CONSUME, &event_group, FLATTEN_GOVL_TIMEOUT_INTERVAL);
        if(status != KAL_SUCCESS)
        {
            ASSERT(0);
        }
    }
    else
    {
        //kal_uint32  hwEvent, triggerEvent;

        IRQMask(IRQ_GOVL_CODE);
        while(GOVL_IS_RUNNING);

        //__flatten_gRot_WaitHWIdle();
        {
            pCtrlConfig->rotationAngle = FLATTEN_ROTATION_0;
            //RestoreIRQMask(save_irq_mask);
        }
        //MT6260 share G2D,need clear INT status here, added by sht
        GOVL_CLEAR_INT_STATUS;
        //read REG to delay 4T for MT6255/56 F2S bus early return potential risk.
        REG_GOVL_IRQ;
        __flatten_gOvl_PowerCtrl(KAL_FALSE);
        __flatten_gOvl_ExecActiveEventsCb(FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT);
        IRQUnmask(IRQ_GOVL_CODE);
    }

    return KAL_TRUE;
}

/*!
*  Get desired interrupt mask setting based on active event callbacks. [Device dependent]
*
*  \param device            Device handle\n
*  \param pCfgCached        Port's cached config structure.\n
*  \return                  NA\n
*
*  \notice
*
*/
/*
__forceinline static kal_uint32
__flatten_gOvlRot_SetInterruptMask(void)
{
    kal_uint32 i;
    kal_uint32 intMask;

    {
        // at lease, DATA_TRANSFER_INT mask shall be enabled.
        // because we need it to wakeup caller
        intMask = FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT;
        REG_GOVL_INT_ENABLE = intMask;
        //IRQUnmask(IRQ_GOVL_ROT1_CODE);
        return intMask;
    }
}
*/
#if 0	//6260 GOVL share G2D HW,ISR belonge to G2D,GOVL set GOVL HISR function as call backfuntion to G2D HISR 
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
#if defined(GOVL_ASYNC_REQ_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif 


/** DESCRIPTION : [Device dependent]
*    GOVL's HISR Handler\n
*  @param[in] NA
*  @return NA
*  @remark
*/
static void
__flatten_gOvl_Hisr(void)
{
    kal_uint32 hwEvent;
    kal_uint32 interrupt_status;

    interrupt_status = FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT;// REG_GOVL_INT_STATUS;
    hwEvent = FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT;

    if (GOVL_IS_RUNNING)
    {
        ASSERT(0);
    }

    //MT6260 share G2D,need clear INT status here, added by sht
    GOVL_CLEAR_INT_STATUS;	
    //read REG to delay 4T for MT6255/56 F2S bus early return potential risk.
    REG_GOVL_IRQ;

    if (hwEvent & interrupt_status)
    {
        //Turn off power before reset busyFlag to avoid race condition.
        __flatten_gOvl_PowerCtrl(KAL_FALSE);
        //TODO: Clear BusyFlag before exec callback.

    }

    __flatten_gOvl_ExecActiveEventsCb(interrupt_status);

    IRQUnmask(IRQ_GOVL_CODE);
    return;
}

__forceinline static kal_bool
__flatten_gOvl_LayerHWConfig(FlattenLayerStruct *flatten_layer_config,FlattenCtrlStruct *flatten_ctrl_config, kal_uint8 id)
{	
    //FlattenCtrlStruct *pCtrlConfig = flatten_ctrl_config;
    FlattenLayerStruct *pLayerConfig = flatten_layer_config;

    if ( NULL == flatten_layer_config )  { return KAL_FALSE; }//no layer config structure, this layer bypass

    //configure flatten_layer_config setting to HW
    {        
        kal_uint32 layer_ctrl = 0;	//layer ctrl register
//        kal_uint32 layer_offset = 0;	//layer offset register
//        kal_uint32 layer_moffset = 0;	//layer source memory offset register
//        kal_uint32 layer_size = 0;	//layer size register
        // 1. Configure layer_ctrl
        // 1.1 source color key enable
        if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_SOURCE_COLOR_KEY)
        {
            layer_ctrl |= GOVL_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
        }
        // 1.2 alpha blending enable and setting
        if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_GLOBAL_ALPHA)
        {
            layer_ctrl |= GOVL_LAYER_CTRL_OPACITY_ENABLE_BIT;
            layer_ctrl |= ( 0xFF & pLayerConfig->globalAlpha) << GOVL_LAYER_ALPHA_VAL_OFFSET;//alpha value setting

        }

        if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_SOURCE_ALPHA)
        {
            layer_ctrl |= GOVL_LAYER_CTRL_OPACITY_ENABLE_BIT;//???sht
            if ((FLATTEN_IMAGE_ARGB8888 != pLayerConfig->image_source_format_pixelFormat) || (FLATTEN_IMAGE_ARGB6666 != pLayerConfig->image_source_format_pixelFormat))
            {
                ASSERT(0);
            }
            layer_ctrl |= 0xFF00;//alpha value setting to fixed 0xFF,to bypass global alpha,by chip to opt
        }
        // 1.3 alpha value setting
//        if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_GLOBAL_ALPHA)
//        {
//            layer_ctrl |= ( (0xFF & pLayerConfig->globalAlpha) << GOVL_LAYER_ALPHA_VAL_OFFSET);
//        }
//        else if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_SOURCE_ALPHA)
//        {
//            layer_ctrl |= (0xFF << GOVL_LAYER_ALPHA_VAL_OFFSET);
//        }
        // 1.4 constant value enable
#ifdef DRV_DISPLAY_DRIVER_CONSTANT_VALUE_SUPPORT
        if (pLayerConfig->isConstantValue)
        {
            //source_color_key and Constant Value confict with each other.
            if (pLayerConfig->transparencyType & FLATTEN_TRANSPARENCY_SOURCE_COLOR_KEY)
            { 
                ASSERT(0);  
            }
            layer_ctrl |= GOVL_LX_CON_ENABLE_RECT_BIT;
        }
#endif

        // 1.5 rotation angle
        {            
            kal_uint32 angle;
//            if (FLATTEN_ROTATION_0 != pCtrlConfig->rotationAngle)//do nothing if roi rotation
            {
                // 1. we will use ROT to perform rotation.
                // 2. set layer rotation angle to 0
                //pLayerConfig->rotationAngle = FLATTEN_ROTATION_0;
                //pLayerConfig->flip = KAL_FALSE;
//                ASSERT(0); // Not supported...
            }

            angle = __flatten_gOvl_CnvtAngleToHwDef(pLayerConfig->rotationAngle, pLayerConfig->flip);
            layer_ctrl |= (angle << GOVL_LAYER_CTRL_ROTATE_OFFSET);
        }

        // 1.6 dither enable
        //GOVL doesn't support dither.

        // 1.7 color format
        {
            FLATTEN_GOVL_LAYER_FORMAT_ENUM color_format;
            color_format = __flatten_gOvl_CnvtImgFormatToHwDef(pLayerConfig->image_source_format_pixelFormat,pLayerConfig->image_source_format_premultiplied);

            if (FLATTEN_GOVL_LAYER_RSVD == color_format)
            {
                //continue to finish this request? or return?
                ASSERT(0);
            }
            layer_ctrl |= (color_format << GOVL_LAYER_CTRL_FORMAT_OFFSET);
        }
        // 1.8 write to register
		// SET_GOVL_LAYER_CON_REG(id, layer_ctrl);//be moved to end to config together
        // 1. Configure layer_ctrl over

            
        {
        // 2. Configure layer_moffset
            //memory offset x, y
            kal_uint32 buf_addr = (kal_uint32)pLayerConfig->image_source_data;

            //From 6276E2 GOVL spec, it doesn't support layer source memory offset
            //if (SUPPORT_LAYER_OFFSET_FUNC())
            //{
            //   layer_moffset = (pLayerConfig->sourceRect_y << 16) |
            //                    pLayerConfig->sourceRect_x;
            //   SET_GOVL_LAYER_WMEM_OFFSET(id, 
            //                              pLayerConfig->sourceRect_x, 
            //                              pLayerConfig->sourceRect_y);
            //}
            //else
            //{
                buf_addr += pLayerConfig->image_source_stride * pLayerConfig->sourceRect_y + pLayerConfig->image_source_pixelSize * pLayerConfig->sourceRect_x;
            //}
        // 2. Configure layer_moffset over

        // 3. Configure layer_offset
            //layer offset x, y at roi coordinate system
            switch(pLayerConfig->rotationAngle)
            {
            case FLATTEN_ROTATION_0:
                if (pLayerConfig->flip)
                {
                    pLayerConfig->destinationRect_x += (pLayerConfig->sourceRect_width - 1);
                }
                break;

            case FLATTEN_ROTATION_90:
                pLayerConfig->destinationRect_x += (pLayerConfig->sourceRect_height - 1);
                if (pLayerConfig->flip)
                {
                    pLayerConfig->destinationRect_y += (pLayerConfig->sourceRect_width - 1);
                }
                break;

            case FLATTEN_ROTATION_180:
                if (!pLayerConfig->flip)
                {
                    pLayerConfig->destinationRect_x += (pLayerConfig->sourceRect_width - 1);
                }
                pLayerConfig->destinationRect_y += (pLayerConfig->sourceRect_height - 1);
                break;

            case FLATTEN_ROTATION_270:
                if (!pLayerConfig->flip)
                {
                    pLayerConfig->destinationRect_y += (pLayerConfig->sourceRect_width - 1);
                }
                break;

            default:
                //ASSERT(0);			  	
                break;
            }
            pLayerConfig->destinationRect_y += GOVL_ROI_COORDINATE_ORIGIN_Y;
            pLayerConfig->destinationRect_x += GOVL_ROI_COORDINATE_ORIGIN_X;
            if (pLayerConfig->destinationRect_y > GOVL_LAYER_MAX_OFFSETY)
            {
                pLayerConfig->destinationRect_y = GOVL_LAYER_MAX_OFFSETY;
            }

            if (pLayerConfig->destinationRect_x > GOVL_LAYER_MAX_OFFSETX)
            {
                pLayerConfig->destinationRect_x = GOVL_LAYER_MAX_OFFSETX;
            }

            if (pLayerConfig->destinationRect_y < GOVL_LAYER_MIN_OFFSETY)
            {
                pLayerConfig->destinationRect_y = GOVL_LAYER_MIN_OFFSETY;
            }

            if (pLayerConfig->destinationRect_x < GOVL_LAYER_MIN_OFFSETX)
            {
                pLayerConfig->destinationRect_x = GOVL_LAYER_MIN_OFFSETX;
            }

//            layer_offset = ((pLayerConfig->destinationRect_y) << 16) |
//                           (pLayerConfig->destinationRect_x);
        //    SET_GOVL_LAYER_OFFSET(id,(pLayerConfig->destinationRect_x),(pLayerConfig->destinationRect_y));

        // 3. Configure layer_offset over

        // 4. Configure layer_size
            //layer size x, y
//            layer_size = (pLayerConfig->sourceRect_height << 16) |
//                         pLayerConfig->sourceRect_width;
        //   SET_GOVL_LAYER_SIZE(id,pLayerConfig->sourceRect_width,pLayerConfig->sourceRect_height);
        // 4. Configure layer_size over
        //    SET_GOVL_LAYER_SOURCE_KEY(id, pLayerConfig->sourceColorKey);
        //    SET_GOVL_LAYER_ADDR(id, buf_addr);
        //    SET_GOVL_LAYER_PITCH(id, CONVERT_TO_GOVL_HW_PITCH_UNIT((pLayerConfig->image_source_stride), (pLayerConfig->image_source_pixelSize)));
        if (0 == id)
        {
            REG_GOVL_L0_CON = layer_ctrl;
            REG_GOVL_L0_OFFSET = (pLayerConfig->destinationRect_x)<<16 | ((pLayerConfig->destinationRect_y)&0xFFFF);//must bit mask
            REG_GOVL_L0_SIZE = (pLayerConfig->sourceRect_width) << 16 | ((pLayerConfig->sourceRect_height)&0xFFFF);
            REG_GOVL_L0_SRC_KEY = pLayerConfig->sourceColorKey;
            REG_GOVL_L0_ADDR = buf_addr;
            REG_GOVL_L0_PITCH = CONVERT_TO_GOVL_HW_PITCH_UNIT((pLayerConfig->image_source_stride), (pLayerConfig->image_source_pixelSize));
        } else if(1 == id)
        {
            REG_GOVL_L1_CON = layer_ctrl;
            REG_GOVL_L1_OFFSET = (pLayerConfig->destinationRect_x)<<16 | ((pLayerConfig->destinationRect_y)&0xFFFF);
            REG_GOVL_L1_SIZE = (pLayerConfig->sourceRect_width) << 16 | ((pLayerConfig->sourceRect_height)&0xFFFF);
            REG_GOVL_L1_SRC_KEY = pLayerConfig->sourceColorKey;
            REG_GOVL_L1_ADDR = buf_addr;
            REG_GOVL_L1_PITCH = CONVERT_TO_GOVL_HW_PITCH_UNIT((pLayerConfig->image_source_stride), (pLayerConfig->image_source_pixelSize));

        } else if(2 == id)
        {
            REG_GOVL_L2_CON = layer_ctrl;
            REG_GOVL_L2_OFFSET = (pLayerConfig->destinationRect_x)<<16 | ((pLayerConfig->destinationRect_y)&0xFFFF);
            REG_GOVL_L2_SIZE = (pLayerConfig->sourceRect_width) << 16 | ((pLayerConfig->sourceRect_height)&0xFFFF);
            REG_GOVL_L2_SRC_KEY = pLayerConfig->sourceColorKey;
            REG_GOVL_L2_ADDR = buf_addr;
            REG_GOVL_L2_PITCH = CONVERT_TO_GOVL_HW_PITCH_UNIT((pLayerConfig->image_source_stride), (pLayerConfig->image_source_pixelSize));

        } else if(3 == id)
        {
            REG_GOVL_L3_CON = layer_ctrl;
            REG_GOVL_L3_OFFSET = (pLayerConfig->destinationRect_x)<<16 | ((pLayerConfig->destinationRect_y)&0xFFFF);
            REG_GOVL_L3_SIZE = (pLayerConfig->sourceRect_width) << 16 | ((pLayerConfig->sourceRect_height)&0xFFFF);
            REG_GOVL_L3_SRC_KEY = pLayerConfig->sourceColorKey;
            REG_GOVL_L3_ADDR = buf_addr;
            REG_GOVL_L3_PITCH = CONVERT_TO_GOVL_HW_PITCH_UNIT((pLayerConfig->image_source_stride), (pLayerConfig->image_source_pixelSize));
        }else
        {
            ASSERT(0);//abnomal layer number
        }

        }
    }
	return KAL_TRUE;
}

/*!
*   Handle Blt to Memory.
*
*  \param
*  \return
*
*  \notice
*
*/

__forceinline static kal_bool
__flatten_gOvl_Blt(FlattenCtrlStruct *flatten_ctrl_config, FLATTENEventType event)
{

    FlattenCtrlStruct *pCtrlConfig = flatten_ctrl_config;

    if ( NULL == flatten_ctrl_config )  { return KAL_FALSE;  }

    kal_set_eg_events(__flatten_event, ~FLATTEN_GOVL_GROT_TRANSFER_COMPLETE_ALL, KAL_AND); //reset event.

    //Config HW registers for blt.
    {
        //kal_uint32 bpp;
        kal_uint32 w2mem_ctrl = 0;	//for roi control register
  //      kal_uint32 w2mem_offset = 0;	//for debug
  //      kal_uint32 roi_size = 0;		//for debug
  //      kal_uint32 roi_offset = 0;	//for debug
        //Clear important register becuase MT6260 will not disable power with the value reserved
        REG_GOVL_DI_CON = 0;
        if(pCtrlConfig->enableDithering)
        {
            if(pCtrlConfig->memOut_image_format_pixelFormat == FLATTEN_IMAGE_RGB565)
            REG_GOVL_DI_CON = 0x3232;
            if(pCtrlConfig->memOut_image_format_pixelFormat == FLATTEN_IMAGE_ARGB6666)
            REG_GOVL_DI_CON = 0x2222;	
        }
        // 1. config w2mem_offset
 //       w2mem_offset = (pCtrlConfig->destinationRect_y << GOVL_ROI_WMEM_OFFSETY_OFFSET) |
 //                      (pCtrlConfig->destinationRect_x << GOVL_ROI_WMEM_OFFSETX_OFFSET);
        SET_GOVL_W2M_OFFSET(pCtrlConfig->destinationRect_x, pCtrlConfig->destinationRect_y);
        // 1. config w2mem_offset over
        
        // 2. config roi_offset
 //       roi_offset = ((pCtrlConfig->roiRect_y+ GOVL_ROI_COORDINATE_ORIGIN_Y)<<16) |
 //                     (pCtrlConfig->roiRect_x+ GOVL_ROI_COORDINATE_ORIGIN_X);
        SET_GOVL_ROI_OFFSET((pCtrlConfig->roiRect_x+ GOVL_ROI_COORDINATE_ORIGIN_X), (pCtrlConfig->roiRect_y+ GOVL_ROI_COORDINATE_ORIGIN_Y));
        // 2. config roi_offset over

        // 3. config roi_size
 //       roi_size = (pCtrlConfig->roiRect_height<<GOVL_ROI_WMEM_OFFSETY_OFFSET) |
 //                  (pCtrlConfig->roiRect_width);
        SET_GOVL_ROI_SIZE(pCtrlConfig->roiRect_width, pCtrlConfig->roiRect_height);
        // 3. config roi_size over

        // 4. config w2m_ctrl
        // 4.1 config alpha value
//        w2mem_ctrl |= ((pCtrlConfig->memOut_image_alpha & GOVL_WMEM_CTRL_ALPHA_MAX) << GOVL_WMEM_CTRL_ALPHA_OFFSET);//Output alpha replace is not used
        // 4.2 config layer enable bit
//        for (i = 0; i < DRV_GOVL_LAYER_TOTAL_COUNT; i++)
        {
//            if (IS_LAYER_ENABLE(pCtrlConfig->flatten_enable_layer,i))
//            {
//                w2mem_ctrl |= GOVL_HW_LAYER_ENABLE_BIT(i);
//            }
            w2mem_ctrl = flatten_ctrl_config->flatten_enable_layer;// w2mem_ctrl default 0, so can assign directly
        }
        // 4.3 config color format
//        if (0 != pCtrlConfig->rotationAngle)   // do not response to this situation
//        {
//            ASSERT(0);
//        }
//        else
        {
            w2mem_ctrl |= (__flatten_gOvl_CnvtW2memFormatToHwDef(pCtrlConfig->memOut_image_format_pixelFormat,
                                                                 pCtrlConfig->memOut_image_format_premultiplied));
            //bpp = (pCtrlConfig->memOut_image_pixelSize);
        }

        // 4.4 config ROI_CON Register
        SET_GOVL_WMEM_CON(w2mem_ctrl);
        // 4. config w2m_ctrl over

        SET_GOVL_ROI_CON_BG_COLOR(pCtrlConfig->bgColor);
        SET_GOVL_WMEM_PITCH(CONVERT_TO_GOVL_HW_PITCH_UNIT((pCtrlConfig->memOut_image_stride),(pCtrlConfig->memOut_image_pixelSize)));
        SET_GOVL_WMEM_ADDR(((kal_uint32)pCtrlConfig->memOut_image_data));
    }


    //Handle INT Mask Here.....	
    {
//        __flatten_gOvlRot_SetInterruptMask();
        REG_GOVL_INT_ENABLE = FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT;
    }
    #if defined(FLATTEN_PERFORMANCE_PROFILING_SUPPORT)
    SLA_CustomLogging("FLS", 0);//FLS:Sop Flatten setting register time profile
    #endif 
    #if defined(FLATTEN_PERFORMANCE_PROFILING_SUPPORT)
    SLA_CustomLogging("FLH", 1);//FLH:Start Flatten HW time profile
    #endif 
    {

    { 
        /***Dong: workaround for 76/55 G2D HW bug, MAUI_03108193,
    	****ROI 1*1 with output colorformat 3Bytes/pixel flatten will lead HW BUSY status abnormal
    	****Solution: extend ROI 1*1 to ROI 2*1 then clip when write to memory
    	***/
        kal_uint32 test_color_format = 0;
        kal_uint32 test_ROI_SIZE = 0;
        kal_uint32 test_ROI_OFS = 0;
                  
        test_color_format = (REG_GOVL_ROI_CON&0x1F);
        test_ROI_SIZE = REG_GOVL_ROI_SIZE;
        test_ROI_OFS = REG_GOVL_ROI_OFFSET; 
        if((test_color_format == 0x3 || test_color_format == 0x9 || test_color_format == 0xA || test_color_format == 0xD || test_color_format == 0xE || test_color_format == 0x13) 
            && test_ROI_SIZE ==0x00010001)
            {
                REG_GOVL_ROI_SIZE = 0x00020001; //extend ROI to 2*1
                REG_GOVL_ROI_CON |= 0x00010000; //clp en
                REG_GOVL_CLP_MIN = test_ROI_OFS;
                REG_GOVL_CLP_MAX = test_ROI_OFS;
            }        
        }

        //Set G2D HW to GOVL mode,for 6260 use G2D HW do flatten
        SET_GOVL_MODE;
        //Start flatten: handle govl and rot
        START_GOVL_TRANSFER;
    }

    if (KAL_TRUE == pCtrlConfig->blocking_req)
    {
        __flatten_gOvlRot_WaitEvent(pCtrlConfig,event);
    }
	return KAL_TRUE;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void FlattenInit_6260(void)
{

//#ifdef MTK_SLEEP_ENABLE
//    govl_power_sleep_mode_hander = L1SM_GetHandle();
//#endif
    /*
    IRQ_Register_LISR(IRQ_GOVL_CODE, __flatten_gOvl_Lisr, "flatten ISR");
    IRQUnmask(IRQ_GOVL_CODE);
    DRV_Register_HISR(DRV_GOVL_HISR_ID, __flatten_gOvl_Hisr);*/

    if (NULL == __flatten_event)
    {
        __flatten_event = kal_create_event_group("flatten_govl_event");
    }
    //G2D init
    g2dInit();

}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

FlattenResultEnum FlattenStart_6260(FlattenLayerStruct *flatten_layer_config,FlattenCtrlStruct *flatten_ctrl_config)
{
    kal_int32 i;
    kal_uint32 temp = 0;
    FLATTENEventType event = FLATTEN_EVENT_DATA_TRANSFER_COMPLETE_MTK;
   	if (NULL == flatten_ctrl_config) { return FLATTEN_RESULT_ILLEGAL_ARGUMENT; }//no ctrl structure, can not flatten
  // 	savedMaskFla = SaveAndSetIRQMask();
    if (KAL_TRUE == flatten_ctrl_config->blocking_req)
    {
        //Use flattenCallback to indicate if it is a blocking or non-blocking request
        flattenCallback = NULL; //callback for HISR
    } 
    else
    {
       //When system inits or exception happens, only can use blocking mode
        if ( (KAL_TRUE == system_init_status) || (INT_QueryExceptionStatus()) ) //only non-block needs to judgy this
        {
            flatten_ctrl_config->blocking_req = KAL_TRUE;
            flattenCallback = NULL;
        }
        else
        {
            flattenCallback = flatten_ctrl_config->flatten_nonblocking_callback; //callback for HISR
            flattenCBParam = flatten_ctrl_config->cbparam;	//callback parameter for HISR        
        }
    }
//	RestoreIRQMask(savedMaskFla);

    //Open govl power
    __flatten_gOvl_PowerCtrl(KAL_TRUE);
    temp = flatten_ctrl_config->flatten_enable_layer; //to save mem access time

//    for (i = DRV_GOVL_LAYER_TOTAL_COUNT-1; i > 0; i--)
    {
//        if (IS_LAYER_ENABLE(flatten_ctrl_config->flatten_enable_layer, i))
//        {
//            __flatten_gOvl_LayerHWConfig(&flatten_layer_config[i],flatten_ctrl_config,i);
//        }

        if(FLATTEN_LAYER0 == (temp&FLATTEN_LAYER0))
        {
            __flatten_gOvl_LayerHWConfig(&flatten_layer_config[0],flatten_ctrl_config,0);
        }
        if(FLATTEN_LAYER1 == (temp&FLATTEN_LAYER1))
        {
            __flatten_gOvl_LayerHWConfig(&flatten_layer_config[1],flatten_ctrl_config,1);
        }
        if(FLATTEN_LAYER2 == (temp&FLATTEN_LAYER2))
        {
            __flatten_gOvl_LayerHWConfig(&flatten_layer_config[2],flatten_ctrl_config,2);
        }
        if(FLATTEN_LAYER3 == (temp&FLATTEN_LAYER3))
        {
            __flatten_gOvl_LayerHWConfig(&flatten_layer_config[3],flatten_ctrl_config,3);
        }
    }
    __flatten_gOvl_Blt(flatten_ctrl_config, event);
    
    return FLATTEN_RESULT_OK;

}

void FlattenHisr_6260(void)
{
	//FlattenHisr_6260 as callback function register to G2D HISR
	__flatten_gOvl_Hisr();
}

#ifdef __cplusplus
}
#endif

#endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(MT6260) 








