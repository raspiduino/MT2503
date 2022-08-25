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
 *   sw_video_resizer.c
 *
 *
 * Description:
 * ------------
 *   software video resizer functions
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
 *****************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "sw_video_resizer.h"

SW_VIDEO_RESIZER_STATUS_ENUM (*sw_video_resizer_put_data)(void* video_put, void* sw_video_resizer_cfg);

#if (defined(MT6235) || defined(MT6235B))
#pragma arm


/**********************************Declaration*************************************/
// for playback
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_dd_resize_rgb565(SW_VIDEO_RESIZER_PUT_STRUCT *video_put, SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// for recorder
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// for HW resizer
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_pack_uyvy422(SW_VIDEO_RESIZER_PUT_STRUCT *video_put, SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg);

SW_VIDEO_RESIZER_STATUS_ENUM sw_video_null_resize_process(SW_VIDEO_RESIZER_PUT_STRUCT *video_put, SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg);
/**********************************Global Variables*************************************/
static SW_VIDEO_RESIZER_DCB_STRUCT   _rSwResizer;



/**********************************Error Handling*************************************/
#if 0
/* under construction !*/
#else
   #define SW_VIDEO_ERROR(err_code) ASSERT(0)
#endif



/**********************************Profiling Functions*************************************/
#ifdef SW_VIDEO_RESIZER_PROFILING

SW_VIDEO_RESIZER_PROFILE_STRUCT sw_video_resizer_profile[SW_VIDEO_RESIZER_FUNC_NUM];

#define SW_VIDEO_PROFILE_RESET(func){sw_video_resizer_profile[func].total_ms=0; \
                                    sw_video_resizer_profile[func].count=0;     \
                                    sw_video_resizer_profile[func].avg_ms=0;    \
                                    sw_video_resizer_profile[func].worst_ms=0;}

#define SW_VIDEO_PROFILE_HW_START      {kal_uint32 time;                   \
                                    kal_uint32 func = 0;                    \
                                    time = video_get_current_time();

#define SW_VIDEO_PROFILE_SW_START      {kal_uint32 time;                   \
                                    kal_uint32 func = 1;                    \
                                    time = video_get_current_time();


#define SW_VIDEO_PROFILE_END    time = video_get_duration_ms(time);\
                                sw_video_resizer_profile[func].total_ms +=time;\
                                sw_video_resizer_profile[func].count++;\
                                sw_video_resizer_profile[func].avg_ms = sw_video_resizer_profile[func].total_ms/sw_video_resizer_profile[func].count;\
                                if(time > sw_video_resizer_profile[func].worst_ms)\
                                sw_video_resizer_profile[func].worst_ms = time;\
                                }
#else
      #define SW_VIDEO_PROFILE_RESET(func)   {}
      #define SW_VIDEO_PROFILE_HW_START {}
      #define SW_VIDEO_PROFILE_SW_START   {}
      #define SW_VIDEO_PROFILE_END   {}
#endif

/**********************************Memory Managment Functions*************************************/

void sw_video_resizer_deinit(void)
{
    _rSwResizer.fgBusy = KAL_FALSE;
    sw_video_resizer_put_data = (SW_VIDEO_RESIZER_STATUS_ENUM (*)(void *, void *))sw_video_null_resize_process;
}

/**********************************Initialization Functions*************************************/
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_resizer_init(SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg)
{
   if (_rSwResizer.fgBusy)
   {
      SW_VIDEO_ERROR(SW_VIDEO_RESIZER_fgBusy);
   }

   _rSwResizer.fgBusy = KAL_TRUE;

   kal_mem_cpy(&_rSwResizer.cfg, sw_video_resizer_cfg, sizeof(_rSwResizer.cfg));

   sw_video_resizer_put_data = (SW_VIDEO_RESIZER_STATUS_ENUM (*)(void *, void *))sw_video_yuv420_dd_resize_rgb565;

#ifdef SW_VIDEO_RESIZER_PROFILING
   //SW_VIDEO_PROFILE_RESET(sw_video_resizer_cfg->resize_func);
#endif

    if (((sw_video_resizer_cfg->u4SrcClipX1 & 0x1) != 0)||
        ((sw_video_resizer_cfg->u4SrcClipY1 & 0x1) != 0)||
        ((sw_video_resizer_cfg->u4SrcClipX2 & 0x1) != 0)||
        ((sw_video_resizer_cfg->u4SrcClipY2 & 0x1) != 0)
        )
    {
        ASSERT(0);
    }

    _rSwResizer.u4OutputWidth = sw_video_resizer_cfg->u4SrcClipX2 - sw_video_resizer_cfg->u4SrcClipX1;
    _rSwResizer.u4OutputHeight = sw_video_resizer_cfg->u4SrcClipY2 - sw_video_resizer_cfg->u4SrcClipY1;
    _rSwResizer.image_buffer_width = _rSwResizer.cfg.tar_offset + _rSwResizer.cfg.tar_width + _rSwResizer.cfg.tar_offset;

    return SW_VIDEO_RESIZER_SUCCESS;
}

kal_bool sw_video_resizer_is_busy(
    kal_uint32 const key,
    kal_bool * const busy)
{
    *busy = (_rSwResizer.fgBusy);
    return KAL_TRUE;
}

/**********************************Resizer Functions*************************************/
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_null_resize_process(SW_VIDEO_RESIZER_PUT_STRUCT *video_put, SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg)
{
    /* Please init the resizer first*/
    ASSERT(0);
    return SW_VIDEO_RESIZER_NEED_INIT_ERROR;
}

static void sw_video_insert_black_point_UYVY422(kal_uint8* pu1Buff, kal_uint32 u4Size)
{
    #if 0
/* under construction !*/
    #else
    kal_int32 i = u4Size;
    kal_uint8* pu1Tmp = pu1Buff;

    while(i-- > 0){
        *pu1Buff++ = 0x80;
        *pu1Buff++ = 0;
        *pu1Buff++ = 0x80;
        *pu1Buff++ = 0;
    };
    #endif
}


static void sw_video_insert_black_point_RGB565(kal_uint16* pu2Buff, kal_uint32 u4Size)
{
    #if 1
    kal_mem_set((void*)pu2Buff, 0, u4Size*sizeof(*pu2Buff));
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_pack_uyvy422_2Point(
    SW_VIDEO_RESIZER_PUT_STRUCT *video_put,
    SW_VIDEO_RESIZER_CONFIG_STRUCT *prConfig
    )
{
    kal_uint32 i = 0, j = 0;
    kal_uint16 *pu2BufferY;
    kal_uint8 *pu1BufferU, *pu1BufferV;
    kal_uint32 u4SourceWidth;
    kal_uint32 u4ClipHeight, u4ClipWidth;
    kal_uint32* pu4OutputImage;
    kal_uint32* pu4TempOut;

    pu2BufferY = (kal_uint16*)(video_put->input_buffer[0] + (kal_uint32)prConfig->u4SrcClipX1);
    pu1BufferU = (kal_uint8*)(video_put->input_buffer[1] + (kal_uint32)(prConfig->u4SrcClipX1>>1));
    pu1BufferV = (kal_uint8*)(video_put->input_buffer[2] + (kal_uint32)(prConfig->u4SrcClipX1>>1));

    // source width/height should be 16x, in other words, 4x
    u4SourceWidth = prConfig->input_buff_width[0];

    // clip width/height could be an odd number
    u4ClipHeight = _rSwResizer.u4OutputHeight;
    u4ClipWidth = _rSwResizer.u4OutputWidth;

    if ((u4ClipWidth > u4SourceWidth)||
        (u4ClipHeight == 0) ||
        (u4ClipWidth == 0))
    {
        ASSERT(0);
    }

    pu4OutputImage = (kal_uint32*)video_put->output_buffer[0];

    //assume width/height are multiples of 16
    pu4TempOut = pu4OutputImage;
    for (j = (u4ClipHeight>>1); j != 0; j--)
    {
        kal_uint16* pu2NextRowY = pu2BufferY + (u4SourceWidth>>1);
        kal_uint32* pu4TempOutNextRow = pu4TempOut + (u4ClipWidth>>1) + (prConfig->tar_offset/2)*2;

        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOut, prConfig->tar_offset/2);
        pu4TempOut += prConfig->tar_offset/2;
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOutNextRow, prConfig->tar_offset/2);
        pu4TempOutNextRow += prConfig->tar_offset/2;

        for (i = (u4ClipWidth>>1); i != 0; i--)
        {
            kal_uint16 u2UnSwapY;
            kal_uint8 u1UnSwapU, u1UnSwapV;
            kal_uint8* pu1TempY;
            kal_uint8* pu1TempU;
            kal_uint8* pu1TempV;

            u1UnSwapU = *pu1BufferU++;
            u1UnSwapV = *pu1BufferV++;

            //odd row
            pu1TempY = (kal_uint8*)(&u2UnSwapY);
            pu1TempU = (kal_uint8*)(&u1UnSwapU);
            pu1TempV = (kal_uint8*)(&u1UnSwapV);

            u2UnSwapY = *pu2BufferY++;

            *pu4TempOut++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);

            //even row
            pu1TempY = (kal_uint8*)(&u2UnSwapY);
            pu1TempU = (kal_uint8*)(&u1UnSwapU);
            pu1TempV = (kal_uint8*)(&u1UnSwapV);

            u2UnSwapY = *pu2NextRowY++;

            *pu4TempOutNextRow++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);
        }
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOut, prConfig->tar_offset/2);
        pu4TempOut += prConfig->tar_offset/2;
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOutNextRow, prConfig->tar_offset/2);
        pu4TempOutNextRow += prConfig->tar_offset/2;

        pu4TempOut += (u4ClipWidth>>1) + (prConfig->tar_offset/2)*2;
        pu2BufferY += (u4SourceWidth>>1) + ((u4SourceWidth>>1) - (u4ClipWidth>>1));
        pu1BufferU += (u4SourceWidth>>1) - (u4ClipWidth>>1);
        pu1BufferV += (u4SourceWidth>>1) - (u4ClipWidth>>1);
    }

    return SW_VIDEO_RESIZER_SUCCESS;
}

static kal_uint32 _SwResizerRoundUp(kal_uint32 u4Original, kal_uint32 u4RoundUp)
{
    return (((u4Original + (u4RoundUp - 1))/u4RoundUp) * u4RoundUp);
}

SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_pack_uyvy422_4Point(
    SW_VIDEO_RESIZER_PUT_STRUCT *video_put,
    SW_VIDEO_RESIZER_CONFIG_STRUCT *prConfig
    )
{
    kal_uint32 i = 0, j = 0;
    kal_uint32 *pu4BufferY;
    kal_uint16 *pu2BufferU, *pu2BufferV;
    kal_uint32 u4SourceWidth;
    kal_uint32 u4ClipHeight, u4ClipWidth;
    kal_uint32 *pu4OutputImage;
    kal_uint32* pu4TempOut;

    pu4BufferY = (kal_uint32*)(video_put->input_buffer[0] + (kal_uint32)prConfig->u4SrcClipX1);
    pu2BufferU = (kal_uint16*)(video_put->input_buffer[1] + (kal_uint32)(prConfig->u4SrcClipX1>>1));
    pu2BufferV = (kal_uint16*)(video_put->input_buffer[2] + (kal_uint32)(prConfig->u4SrcClipX1>>1));

    // source width/height should be 16x (MB boundary), in other words, 4x should be guaranteed
    u4SourceWidth = prConfig->input_buff_width[0];

    // clip width/height could be an odd number
    u4ClipHeight = _rSwResizer.u4OutputHeight;
    u4ClipWidth = _rSwResizer.u4OutputWidth;

    if ((u4ClipWidth > u4SourceWidth)||
        (u4ClipHeight == 0) ||
        (u4ClipWidth == 0))
    {
        ASSERT(0);
    }

    pu4OutputImage = (kal_uint32*)video_put->output_buffer[0];

    pu4TempOut = pu4OutputImage;
    for (j = (u4ClipHeight>>1); j != 0; j--)
    {
        kal_uint32* pu4NextRowY = pu4BufferY + (u4SourceWidth>>2);
        kal_uint32* pu4TempOutNextRow = pu4TempOut + (u4ClipWidth>>1) + (prConfig->tar_offset/2)*2;

        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOut, prConfig->tar_offset/2);
        pu4TempOut += prConfig->tar_offset/2;
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOutNextRow, prConfig->tar_offset/2);
        pu4TempOutNextRow += prConfig->tar_offset/2;
        for (i = (u4ClipWidth>>2); i != 0; i--)
        {
            kal_uint32 u4UnSwapY;
            kal_uint16 u2UnSwapU, u2UnSwapV;
            kal_uint8* pu1TempY;
            kal_uint8* pu1TempU;
            kal_uint8* pu1TempV;

            u2UnSwapU = *pu2BufferU++;
            u2UnSwapV = *pu2BufferV++;

            //odd row
            pu1TempY = (kal_uint8*)(&u4UnSwapY);
            pu1TempU = (kal_uint8*)(&u2UnSwapU);
            pu1TempV = (kal_uint8*)(&u2UnSwapV);

            u4UnSwapY = *pu4BufferY++;

            *pu4TempOut++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);

            pu1TempY += 2;
            pu1TempU++;
            pu1TempV++;

            *pu4TempOut++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);

            //even row
            pu1TempY = (kal_uint8*)(&u4UnSwapY);
            pu1TempU = (kal_uint8*)(&u2UnSwapU);
            pu1TempV = (kal_uint8*)(&u2UnSwapV);

            u4UnSwapY = *pu4NextRowY++;

            *pu4TempOutNextRow++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);

            pu1TempY += 2;
            pu1TempU++;
            pu1TempV++;

            *pu4TempOutNextRow++ = ((kal_uint32)(*(pu1TempY+1))<<24) | ((kal_uint32)(*(pu1TempV))<<16) | ((kal_uint32)(*(pu1TempY))<<8) | ((kal_uint32)(*(pu1TempU))<<0);
        }
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOut, prConfig->tar_offset/2);
        pu4TempOut += prConfig->tar_offset/2;
        sw_video_insert_black_point_UYVY422((kal_uint8*)pu4TempOutNextRow, prConfig->tar_offset/2);
        pu4TempOutNextRow += prConfig->tar_offset/2;

        pu4TempOut += (u4ClipWidth>>1) + (prConfig->tar_offset/2)*2;
        pu4BufferY += (u4SourceWidth>>2) + ((u4SourceWidth>>2) - (u4ClipWidth>>2));
        pu2BufferU += (u4SourceWidth>>2) - (u4ClipWidth>>2);
        pu2BufferV += (u4SourceWidth>>2) - (u4ClipWidth>>2);
    }

    return SW_VIDEO_RESIZER_SUCCESS;
}

SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_pack_uyvy422(
    SW_VIDEO_RESIZER_PUT_STRUCT *video_put,
    SW_VIDEO_RESIZER_CONFIG_STRUCT *prConfig
    )
{
	SW_VIDEO_RESIZER_STATUS_ENUM eRet = SW_VIDEO_RESIZER_SUCCESS;

	SW_VIDEO_PROFILE_HW_START

    // input/output buffers should be four-byte aligned
    if( (((kal_uint32)(video_put->input_buffer[0]) & 0x3) != 0)
      ||(((kal_uint32)(video_put->input_buffer[1]) & 0x3) != 0)
      ||(((kal_uint32)(video_put->input_buffer[2]) & 0x3) != 0)
      ||(((kal_uint32)(video_put->output_buffer[0]) & 0x3) != 0)
      ||(prConfig->tar_offset & 0x1) != 0)
    {
        ASSERT(0);
    }

	switch(_rSwResizer.u4OutputWidth & 0x3)
	{
	case 0:
	case 1:
	    if ( (0 == (prConfig->u4SrcClipX1 % 4))
	       &&(0 == (prConfig->tar_offset % 4)))
	    {
		    eRet = sw_video_yuv420_pack_uyvy422_4Point(video_put, prConfig);
	    }
	    else
	    {
	        eRet = sw_video_yuv420_pack_uyvy422_2Point(video_put, prConfig);
	    }
		break;
	case 2:
	case 3:
		eRet = sw_video_yuv420_pack_uyvy422_2Point(video_put, prConfig);
		break;
	default:
		ASSERT(0);
		break;
	};

	SW_VIDEO_PROFILE_END

	return eRet;
}

SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_dd_resize_rgb565(
    SW_VIDEO_RESIZER_PUT_STRUCT *video_put,
    SW_VIDEO_RESIZER_CONFIG_STRUCT *prConfig
    )
{
    kal_int32 i,j;
    kal_uint32 u4HorizontalRatio,u4VerticalRatio;
    kal_uint32 u4SrcRowStart,u4SrcColStart;
    kal_uint32 u4PreviousSrcRow;
    SW_VIDEO_RESIZER_CONFIG_STRUCT * prCfg = prConfig;

    kal_uint8 *pu1YUVBuffer[3];
    kal_uint16 *pu2RGBOutput;

    SW_VIDEO_PROFILE_SW_START

    u4PreviousSrcRow = 0xffffffff;

    pu1YUVBuffer[0]=video_put->input_buffer[0];
    pu1YUVBuffer[1]=video_put->input_buffer[1];
    pu1YUVBuffer[2]=video_put->input_buffer[2];

    u4HorizontalRatio = ((_rSwResizer.u4OutputWidth)<<SW_VIDEO_RESIZER_SCALE_BITS)/_rSwResizer.cfg.tar_width;
    u4VerticalRatio = ((_rSwResizer.u4OutputHeight)<<SW_VIDEO_RESIZER_SCALE_BITS)/_rSwResizer.cfg.tar_height;

    u4SrcRowStart = prCfg->u4SrcClipY1 << SW_VIDEO_RESIZER_SCALE_BITS;
    pu2RGBOutput = (kal_uint16 *)video_put->output_buffer[0];

    j = _rSwResizer.cfg.tar_height;
    while (--j >= 0)
    {
        kal_uint16 *pu2Output = pu2RGBOutput;
        kal_uint8 *pu1Y, *pu1Cb, *pu1Cr, *pu1Data;
        kal_uint32 u4SrcRow,u4PreviousSrcCol,u4SrcCol;

        u4PreviousSrcCol = 0xfffffff0;//Trick to the first col
        u4SrcRow = u4SrcRowStart >> SW_VIDEO_RESIZER_SCALE_BITS;

        pu1Y = pu1YUVBuffer[0] + u4SrcRow * prCfg->input_buff_width[0];
        pu1Cb = pu1YUVBuffer[1] + (u4SrcRow>>1) * prCfg->input_buff_width[1];
        pu1Cr = pu1YUVBuffer[2] + (u4SrcRow>>1) * prCfg->input_buff_width[2];

        u4SrcColStart = prCfg->u4SrcClipX1 << SW_VIDEO_RESIZER_SCALE_BITS;

        // before resize for each row, paint tar_offset pixels with black color
        sw_video_insert_black_point_RGB565(pu2Output, prConfig->tar_offset);
        pu2Output += prConfig->tar_offset;

        if(u4PreviousSrcRow != u4SrcRow)
        {
            kal_int32 u4Y = 0, u4Cb = 0, u4Cr = 0, u4R = 0, u4G = 0, u4B = 0,u4ColGap = 0;

            i = _rSwResizer.cfg.tar_width;
            while(--i >= 0)
            {
                u4SrcCol = u4SrcColStart >> SW_VIDEO_RESIZER_SCALE_BITS;
                u4ColGap = u4SrcCol - u4PreviousSrcCol;

                if(0 != u4ColGap)//a new col
                {
                    if((u4ColGap == 1) && (u4SrcCol & 0x01)) //share the same chroma with previous pixel!
                    {
                        kal_int32 u4DiffY;

                        /* Y_Channel */
                        pu1Data = pu1Y + u4SrcCol;
                        u4DiffY = ((*pu1Data) << 10) - u4Y;

                        u4R = u4R + (u4DiffY >> 13);
                        u4B = u4B + (u4DiffY >> 13);
                        u4G = u4G + (u4DiffY >> 12);
                    }
                    else
                    {
                        /* Y_Channel */
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
                        #else
                        pu1Data = pu1Y + u4SrcCol;
                        u4Y = (*pu1Data) << 10;

                        /* U_Channel*/
                        pu1Data = pu1Cb + (u4SrcCol>>1);
                        //Cb = (*data_ptr - 128)*352;
                        u4Cb = (*pu1Data - 128);
                        u4Cb = (u4Cb<<8)+(u4Cb<<7);//384

                        /* V_Channel*/
                        pu1Data = pu1Cr + (u4SrcCol>>1);
                        //Cr = (*data_ptr - 128)*731;
                        u4Cr = (*pu1Data - 128);
                        u4Cr = (u4Cr<<9)+(u4Cr<<8);//768

                        u4R = (u4Y + (u4Cr<<1)) >> 13;
                        u4B = (u4Y + u4Cb+(u4Cb<<2)) >> 13;
                        u4G = (u4Y - u4Cb - u4Cr) >> 12;
                        #endif
                    }

                    u4R = CLIP31(u4R);
                    u4G = CLIP63(u4G);
                    u4B = CLIP31(u4B);

                    *pu2Output++ = ((u4R << 11) | (u4G << 5) | u4B);
                }
                else//The same position as previous line
                {
                    *pu2Output++ = *(pu2Output - 1);
                }

                u4PreviousSrcCol = u4SrcCol;
                u4SrcColStart += u4HorizontalRatio;
            }//end of while

            // after resize for each row, paint tar_offset pixels with black color
            sw_video_insert_black_point_RGB565(pu2Output, prConfig->tar_offset);
            pu2Output += prConfig->tar_offset;
        }
        else
        {
            kal_uint8 *pu1Output = (kal_uint8*)pu2RGBOutput;
            kal_uint32 u4CopySize = _rSwResizer.image_buffer_width<<1;

            kal_mem_cpy(pu1Output, pu1Output - u4CopySize, u4CopySize);
        }


        pu2RGBOutput += _rSwResizer.image_buffer_width;
        u4PreviousSrcRow = u4SrcRow;
        u4SrcRowStart += u4VerticalRatio;
    }

    SW_VIDEO_PROFILE_END

    return SW_VIDEO_RESIZER_SUCCESS;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
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
                   #else
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
#else //(defined(MT6235) || defined(MT6235B))

void sw_video_resizer_deinit(void){}
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_nothing_resize_nothing(SW_VIDEO_RESIZER_PUT_STRUCT *video_put, SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg)
{
    return SW_VIDEO_RESIZER_SUCCESS;
}
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_resizer_init(SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg)
{
    sw_video_resizer_put_data = (SW_VIDEO_RESIZER_STATUS_ENUM (*)(void *, void *))sw_video_nothing_resize_nothing;

    return SW_VIDEO_RESIZER_SUCCESS;
}
kal_uint32 get_sw_video_ip_buffer_size( kal_uint32 max_width, kal_uint32 max_height)
{
    return 0;
}
kal_bool sw_video_resizer_is_busy(
  kal_uint32 const key,
  kal_bool * const busy)
{
  return KAL_TRUE;
}

#endif

