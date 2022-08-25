/****************************************************************************
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
 *    mm_intmem_mt6253.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
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
 * 07 06 2011 peter.wang
 * removed!
 * .
 *
 * 04 20 2011 peter.wang
 * removed!
 * .
 *
 * 04 20 2011 peter.wang
 * removed!
 * .
 *
 * 12 03 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 17 2010 cm.huang
 * NULL
 * .
 *
 * 11 12 2010 cm.huang
 * NULL
 * .
 *
 * 11 09 2010 cm.huang
 * NULL
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "lcd_sw_inc.h"
#include "drv_features_mmsysmisc.h"

#if defined(DRV_FEATURE__MM_INTMEM_IF)

/****************************************************************************
* macro definitions
****************************************************************************/
#if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)
#define MM_INTMEM__MT6253_SYSRAM_SIZE (16*1024)   //scatter file 0x4000
#define MM_INTMEM__MT6253_SW_JPEG_SYSRAM_SIZE (38400)   //scatter file 0x9600

#define INTERNAL_MEM_START_ADDR 0x4001C000
#define SW_JPEG_INTERNAL_MEM_START_ADDR 0x4000CC70

#define IDP_VR_MAXIMUM_RESZ_WM_SIZE (400 * 2 * 4)
// Video playback max. resizer working memory size: the same as that for video recording case
#define IDP_VP_MAXIMUM_RESZ_WM_SIZE IDP_VR_MAXIMUM_RESZ_WM_SIZE
// Camera preview max. resizer working memory size: target width (320?) * 2 * 4 + buffer for alignment.
#define IDP_CP_MAXIMUM_RESZ_WM_SIZE (400 * 2 * 4)
// Camera capture max. resizer working memory size: target width (1600 max) * 2 * 4 + buffer for alignement.
#define IDP_IC_MAXIMUM_RESZ_WM_SIZE (1600 * 2 * 4)
// Webcam max. resizer working memory size: target width (640 max) * 2 * 4 + buffer for alignement.
#define IDP_WEBCAM_MAXIMUM_RESZ_WM_SIZE (640 * 2 * 4)

#if defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__)&&(LCD_WIDTH<=320)
#define LCD_ROT_MAX_INT_MEM_SIZE                  (320*2*16)
#else
#define LCD_ROT_MAX_INT_MEM_SIZE                (400*2*16)
#endif

#define SW_JPEG_DECODE_MAX_INT_MEM_SIZE                (30*1024)
#define SW_JPEG_ENCODE_MAX_INT_MEM_SIZE                (MM_INTMEM__MT6253_SW_JPEG_SYSRAM_SIZE - SW_JPEG_DECODE_MAX_INT_MEM_SIZE) //7680

#endif // #if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)

/****************************************************************************
* include directives
****************************************************************************/
#include "mm_intmem.h"
#include "kal_release.h"

/****************************************************************************
 * typedef
 ****************************************************************************/
typedef struct
{
    mm_intmem_segment_id_t  segment_id;
    kal_uint32              start_address;
    kal_uint32              size_in_bytes;
    kal_bool                allocated;
} _mm_intmem_segment_entry_t;

typedef struct
{
    _mm_intmem_segment_entry_t *sen_seg_table;
    kal_uint16                 table_size;
} _mm_intmem_scen_table_entry_t;

/****************************************************************************
* local varaiables
****************************************************************************/
#if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)

#pragma arm section rwdata = "INTERNRW3", zidata = "INTERNZI3"
__align(4) kal_uint8 _mm_intmem_sysram[MM_INTMEM__MT6253_SYSRAM_SIZE]; //0x4001C000
#pragma arm section rwdata , zidata

#pragma arm section rwdata = "INTERNRW1", zidata = "INTERNZI1"
__align(4) kal_uint8 _sw_jpeg_mm_intmem_sysram[MM_INTMEM__MT6253_SW_JPEG_SYSRAM_SIZE]; //0x4000CC70
#pragma arm section rwdata , zidata


static mm_scen_id_t _mm_intmem__curr_scen = MM_SCEN____NONE;

static kal_semid _mm_intmem__kal_semaphore = 0;
static kal_semid _mm_intmem__jpeg_encode_semaphore = 0;
static kal_semid _mm_intmem__jpeg_decode_semaphore = 0;

static kal_uint32 lcd_have_get_buffer = KAL_FALSE;
static kal_uint32 sw_jpeg_decode_have_get_buffer = KAL_FALSE;
static kal_uint32 sw_jpeg_encode_have_get_buffer = KAL_FALSE;
static kal_uint32 sw_video_have_get_buffer = KAL_FALSE;

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_CP---------------------------------------------------------
#define MT6253_CP_MM_INTMEM_SEG__LCD_SIZE  LCD_ROT_MAX_INT_MEM_SIZE
#define MT6253_CP_MM_INTMEM_SEG__CRZ_SIZE  IDP_CP_MAXIMUM_RESZ_WM_SIZE
#define MT6253_CP_MM_INTMEM_SEG__LCD_ADDR  INTERNAL_MEM_START_ADDR
#define MT6253_CP_MM_INTMEM_SEG__CRZ_ADDR  INTERNAL_MEM_START_ADDR + MT6253_CP_MM_INTMEM_SEG__LCD_SIZE

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_IC---------------------------------------------------------
#define MT6253_IC_MM_INTMEM_SEG__LCD_SIZE  LCD_ROT_MAX_INT_MEM_SIZE
#define MT6253_IC_MM_INTMEM_SEG__CRZ_SIZE  IDP_IC_MAXIMUM_RESZ_WM_SIZE
#define MT6253_IC_MM_INTMEM_SEG__LCD_ADDR  INTERNAL_MEM_START_ADDR
#define MT6253_IC_MM_INTMEM_SEG__CRZ_ADDR  INTERNAL_MEM_START_ADDR

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_WEBCAM---------------------------------------------------------
#define MT6253_WEBCAM_MM_INTMEM_SEG__LCD_SIZE  LCD_ROT_MAX_INT_MEM_SIZE
#define MT6253_WEBCAM_MM_INTMEM_SEG__CRZ_SIZE  IDP_IC_MAXIMUM_RESZ_WM_SIZE
#define MT6253_WEBCAM_MM_INTMEM_SEG__LCD_ADDR  INTERNAL_MEM_START_ADDR
#define MT6253_WEBCAM_MM_INTMEM_SEG__CRZ_ADDR  INTERNAL_MEM_START_ADDR + MT6253_WEBCAM_MM_INTMEM_SEG__LCD_SIZE

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_JD---------------------------------------------------------
#define MT6253_JD_MM_INTMEM_SEG__SW_JPEG_DECODE_SIZE  SW_JPEG_DECODE_MAX_INT_MEM_SIZE
#define MT6253_JD_MM_INTMEM_SEG__SW_JPEG_DECODE_ADDR  SW_JPEG_INTERNAL_MEM_START_ADDR

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_JE---------------------------------------------------------
#define MT6253_JE_MM_INTMEM_SEG__SW_JPEG_ENCODE_SIZE  SW_JPEG_ENCODE_MAX_INT_MEM_SIZE
#define MT6253_JE_MM_INTMEM_SEG__SW_JPEG_ENCODE_ADDR  SW_JPEG_INTERNAL_MEM_START_ADDR+SW_JPEG_DECODE_MAX_INT_MEM_SIZE

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_VR---------------------------------------------------------
#define MT6253_VR_MM_INTMEM_SEG__LCD_SIZE  LCD_ROT_MAX_INT_MEM_SIZE
#define MT6253_VR_MM_INTMEM_SEG__CRZ_SIZE  IDP_VR_MAXIMUM_RESZ_WM_SIZE
#define MT6253_VR_MM_INTMEM_SEG__LCD_ADDR  INTERNAL_MEM_START_ADDR
#define MT6253_VR_MM_INTMEM_SEG__CRZ_ADDR  INTERNAL_MEM_START_ADDR + MT6253_VR_MM_INTMEM_SEG__LCD_SIZE

//----------------------------------------------------------------------------------------------------------
//--------------------------------MT6253_VP---------------------------------------------------------
#define MT6253_VP_MM_INTMEM_SEG__LCD_SIZE  LCD_ROT_MAX_INT_MEM_SIZE
#define MT6253_VP_MM_INTMEM_SEG__CRZ_SIZE  IDP_VP_MAXIMUM_RESZ_WM_SIZE
#define MT6253_VP_MM_INTMEM_SEG__LCD_ADDR  INTERNAL_MEM_START_ADDR
#define MT6253_VP_MM_INTMEM_SEG__CRZ_ADDR  INTERNAL_MEM_START_ADDR + MT6253_VP_MM_INTMEM_SEG__LCD_SIZE

#endif // #if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)
/****************************************************************************
 * external function bodies
 ****************************************************************************/
#if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)
kal_bool
mm_intmem_get(
    mm_scen_id_t const scen_id,
    mm_intmem_segment_id_t const segment_id,
    kal_uint32 *address,
    kal_uint32 *size)
{

    kal_bool result = KAL_TRUE;
    *address = 0;
    *size = 0;

    if (0 == _mm_intmem__kal_semaphore)
    {
#if 1   // for debugging
        kal_mem_set(&_mm_intmem_sysram[0], 0xAF, 256);
#endif

        _mm_intmem__kal_semaphore = kal_create_sem("MM_INT_MEM", 1);

        _mm_intmem__jpeg_decode_semaphore = kal_create_sem("MM_INT_MEM_JEPG_DECODE", 1);
        _mm_intmem__jpeg_encode_semaphore = kal_create_sem("MM_INT_MEM_JEPG_ENCODE", 1);
    }

    // assume only invoked in NU+ task thread, protect by semaphore
    kal_take_sem(_mm_intmem__kal_semaphore, KAL_INFINITE_WAIT);

    if (MM_INTMEM_SEG__LCD == segment_id)
    {
        //for camera capture, lcd and crz can't use internal memory simultaneously due to internal memory is not enough
        if ((KAL_FALSE != lcd_have_get_buffer) ||
            (MM_SCEN__CAMERA_CAPTURE_JPEG == _mm_intmem__curr_scen)) 
        {
            result = KAL_FALSE;
            goto EXIT_1;
        }
        
        *address = INTERNAL_MEM_START_ADDR;
        *size = LCD_ROT_MAX_INT_MEM_SIZE;
        lcd_have_get_buffer = KAL_TRUE;
    }
    else if (MM_INTMEM_SEG__CRZ == segment_id)
    {
        switch(scen_id)
        {
            case MM_SCEN__CAMERA_PREVIEW:
                *address = MT6253_CP_MM_INTMEM_SEG__CRZ_ADDR;
                *size = MT6253_CP_MM_INTMEM_SEG__CRZ_SIZE;
            break;

            case MM_SCEN__CAMERA_CAPTURE_JPEG:
                //for camera capture, lcd and crz can't use internal memory simultaneously due to internal memory is not enough
                if (KAL_TRUE == lcd_have_get_buffer)
                {
                    result = KAL_FALSE;
                    goto EXIT_1;
                }
                *address = MT6253_IC_MM_INTMEM_SEG__CRZ_ADDR;
                *size = MT6253_IC_MM_INTMEM_SEG__CRZ_SIZE;
            break;

            case MM_SCEN__WEBCAM:
                *address = MT6253_WEBCAM_MM_INTMEM_SEG__CRZ_ADDR;
                *size = MT6253_WEBCAM_MM_INTMEM_SEG__CRZ_SIZE;
            break;

            case MM_SCEN__VIDEO_RECORD:
                *address = MT6253_VR_MM_INTMEM_SEG__CRZ_ADDR;
                *size = MT6253_VR_MM_INTMEM_SEG__CRZ_SIZE;
            break;

            case MM_SCEN__VIDEO_DECODE:
                *address = MT6253_VP_MM_INTMEM_SEG__CRZ_ADDR;
                *size = MT6253_VP_MM_INTMEM_SEG__CRZ_SIZE;
            break;

            default:
                result = KAL_FALSE;
                goto EXIT_1;
                //break;
        }
        _mm_intmem__curr_scen = scen_id;
    }
    else if (MM_INTMEM_SEG__JPEG_DEC == segment_id)  //don't care which scenario, SW_JPEG use the same with SW_VIDEO int. memory
    {
        if ((MM_SCEN__JPEG_DECODE != scen_id) ||                // scenario wrong
            (KAL_FALSE != sw_jpeg_decode_have_get_buffer) ||    // jpeg decode have already get
            (KAL_FALSE != sw_video_have_get_buffer))            // sw video have already get
        {
            result = KAL_FALSE;
            goto EXIT_1;
        }

        *address = (kal_uint32)&_sw_jpeg_mm_intmem_sysram[0];
        *size = MT6253_JD_MM_INTMEM_SEG__SW_JPEG_DECODE_SIZE;

        sw_jpeg_decode_have_get_buffer = KAL_TRUE;
        kal_take_sem(_mm_intmem__jpeg_decode_semaphore, KAL_INFINITE_WAIT);
    }
    else if (MM_INTMEM_SEG__JPEG_ENC == segment_id)  //don't care which scenario, SW_JPEG use the same with SW_VIDEO int. memory
    {
        if ((MM_SCEN__JPEG_ENCODE != scen_id) ||                // scenario wrong 
            (KAL_FALSE != sw_jpeg_encode_have_get_buffer) ||    // jpeg encode have already get
            (KAL_FALSE != sw_video_have_get_buffer))            // sw video have already get
        {
            result = KAL_FALSE;
            goto EXIT_1;
        }

        *address = MT6253_JE_MM_INTMEM_SEG__SW_JPEG_ENCODE_ADDR;
        *size = MT6253_JE_MM_INTMEM_SEG__SW_JPEG_ENCODE_SIZE;

        sw_jpeg_encode_have_get_buffer = KAL_TRUE;
        kal_take_sem(_mm_intmem__jpeg_encode_semaphore, KAL_INFINITE_WAIT);
    }
    else if (MM_INTMEM_SEG__SW_VIDEO == segment_id)  //don't care which scenario, SW_VIDEO use the same with SW_JPEG int. memory
    {
        if ((MM_SCEN__VIDEO_PLAYBACK != scen_id) ||
            (KAL_FALSE != sw_video_have_get_buffer))
        {
            result = KAL_FALSE;
            goto EXIT_1;
        }

        *address = (kal_uint32)&_sw_jpeg_mm_intmem_sysram[0];
        *size = MM_INTMEM__MT6253_SW_JPEG_SYSRAM_SIZE;

        sw_video_have_get_buffer = KAL_TRUE;
        kal_take_sem(_mm_intmem__jpeg_decode_semaphore, KAL_INFINITE_WAIT);
        kal_take_sem(_mm_intmem__jpeg_encode_semaphore, KAL_INFINITE_WAIT);
    }
    else
    {
        result = KAL_FALSE;
    }


EXIT_1:

    kal_give_sem(_mm_intmem__kal_semaphore);

    return result;
}


kal_bool
mm_intmem_free(
    mm_scen_id_t const scen_id,
    mm_intmem_segment_id_t const segment_id)
{
    kal_bool result = KAL_TRUE;

    if (0 == _mm_intmem__kal_semaphore)
    {
#if 1   // for debugging
        kal_mem_set(&_mm_intmem_sysram[0], 0xAF, 256);
        //kal_mem_set(&_mm_intmem_mm_dtcm[0], 0x7F, 256);
#endif

        _mm_intmem__kal_semaphore = kal_create_sem("MM_INT_MEM", 1);

        _mm_intmem__jpeg_decode_semaphore = kal_create_sem("MM_INT_MEM_JEPG_DECODE", 1);
        _mm_intmem__jpeg_encode_semaphore = kal_create_sem("MM_INT_MEM_JEPG_ENCODE", 1);
    }

    // assume only invoked in NU+ task thread, protect by semaphore
    kal_take_sem(_mm_intmem__kal_semaphore, KAL_INFINITE_WAIT);

    if (MM_INTMEM_SEG__LCD == segment_id)
    {
        lcd_have_get_buffer = KAL_FALSE;
    }
    else if(MM_INTMEM_SEG__CRZ == segment_id)
    {
        _mm_intmem__curr_scen = MM_SCEN____NONE;
    }
    else if (MM_INTMEM_SEG__JPEG_DEC == segment_id)
    {
        sw_jpeg_decode_have_get_buffer = KAL_FALSE;
        kal_give_sem(_mm_intmem__jpeg_decode_semaphore);
    }
    else if (MM_INTMEM_SEG__JPEG_ENC == segment_id)
    {
        sw_jpeg_encode_have_get_buffer = KAL_FALSE;
        kal_give_sem(_mm_intmem__jpeg_encode_semaphore);
    }
    else if (MM_INTMEM_SEG__SW_VIDEO == segment_id)
    {
        sw_video_have_get_buffer = KAL_FALSE;
        kal_give_sem(_mm_intmem__jpeg_decode_semaphore);
        kal_give_sem(_mm_intmem__jpeg_encode_semaphore);
    }
    else
    {
        result = KAL_FALSE;
    }

    kal_give_sem(_mm_intmem__kal_semaphore);

    return result;
}

#endif // #if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6253)

#endif // #if defined(DRV_FEATURE__MM_INTMEM_IF)


