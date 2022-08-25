/*****************************************************************************
 * Filename:
 * ---------
 * custom_video.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customize some video parameters.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "custom_video.h"
//#include "custom_EMI_release.h"

/* this must be sync with med_api.h */

#ifndef ASSERT
#define ASSERT(x) { if (!x)  while (1); }
#endif
/*****************************************************************************
 * FUNCTION
 *  vid_convert_quality_to_bitrate
 * DESCRIPTION
 *  This function is to convert quality to bitrate
 * PARAMETERS
 *  width               [IN]        record image width
 *  height              [IN]        record image height
 *  quality             [IN]        required encode quality
 *  bitrate_p           [?]         the pointer to output bitrate
 *  skip_frame_p        [?]         a flag to indicate skip frame
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MED_NOT_PRESENT
void vid_convert_quality_to_bitrate(
        kal_uint16 width,
        kal_uint16 height,
        kal_uint8 quality,
        kal_uint32 *bitrate_p,
        kal_uint8 *skip_frame_p)
{
#if defined(MT6235) || defined(MT6235B)
  *skip_frame_p = 0;

        switch (quality)
        {
            case VID_REC_QTY_LOW:
    *bitrate_p = 96000;
                break;
            case VID_REC_QTY_NORMAL:
    *bitrate_p = 256000;
                break;
            case VID_REC_QTY_HIGH:
    *bitrate_p = 384000;
                break;
            case VID_REC_QTY_FINE:
    *bitrate_p = 1950000;
                break;
            default:
                ASSERT(0);
    *bitrate_p = 10000000;
                break;
        }
#elif defined(MT6253)
                *skip_frame_p = 0;

	switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 64000;
                break;
            case VID_REC_QTY_NORMAL:
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
    *bitrate_p = 170000;
#else
    *bitrate_p = 384000;
#endif  // __CONTOUR_IMPROVEMENT_SUPPORT__
                break;
            case VID_REC_QTY_HIGH:
    *bitrate_p = 1950000;
                break;
            case VID_REC_QTY_FINE:
    *bitrate_p = 1300000;
                break;
            default:
                ASSERT(0);
    *bitrate_p = 10000000;
                break;
        }
#elif defined(MT6253E) || defined(MT6252H)
  *skip_frame_p = 0;

  switch (quality)
  {
  case VID_REC_QTY_LOW:
    *bitrate_p = 51200;
    break;
  case VID_REC_QTY_NORMAL:
    *bitrate_p = 307200;
    break;
  case VID_REC_QTY_HIGH:
    *bitrate_p = 1560000;
    break;
  case VID_REC_QTY_FINE:
    *bitrate_p = 1300000;
    break;
  default:
    ASSERT(0);
    *bitrate_p = 10000000;
    break;
  }
#elif defined(MT6253L) || defined(MT6252)
  *skip_frame_p = 0;

        switch (quality)
        {
            case VID_REC_QTY_LOW:
    *bitrate_p = 51200;
                break;
            case VID_REC_QTY_NORMAL:
    *bitrate_p = 307200;
                break;
            case VID_REC_QTY_HIGH:
    *bitrate_p = 1560000;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 1300000;
                break;
            default:
                ASSERT(0);
    *bitrate_p = 10000000;
                break;
        }
#elif defined(MT6236) || defined(MT6236B)
  *skip_frame_p = 0;
#ifdef __VIDEO_ENC_D1_SUPPORT__
	switch (quality)
	{
	case VID_REC_QTY_LOW:
    *bitrate_p = 96000;
		break;
	case VID_REC_QTY_NORMAL:
		*bitrate_p = 750000;
		break;
	case VID_REC_QTY_HIGH:
	  *bitrate_p = 1500000;
		break;
	case VID_REC_QTY_FINE:
		*bitrate_p = 3500000;
		break;
	default:
		ASSERT(0);
		*bitrate_p = 3500000;
		break;
	}
#elif defined(__EMI_DEVICE_MODE_BURST__)			//6236, ADMUX
  switch (quality)
  {
  case VID_REC_QTY_LOW:
    *bitrate_p = 96000;
    break;
  case VID_REC_QTY_NORMAL:
    *bitrate_p = 384000;
    break;
  case VID_REC_QTY_HIGH:
    *bitrate_p = 600000;		//12fps, QVGA
    break;
  case VID_REC_QTY_FINE:
    *bitrate_p = 1750000;		//12fps,
    break;
  default:
    ASSERT(0);
    *bitrate_p = 3500000;
    break;
  }
#else
	switch(quality)
	{
	case VID_REC_QTY_LOW:
        *bitrate_p = 96000;
		break;
	case VID_REC_QTY_NORMAL:
		*bitrate_p = 384000;
		break;
	case VID_REC_QTY_HIGH:
		*bitrate_p = 750000;
		break;
	case VID_REC_QTY_FINE:
		*bitrate_p = 3500000;
		break;
	default:
		ASSERT(0);
    *bitrate_p = 3500000;
		break;
	}
#endif
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    area = width * height;

    if (area <= 128 * 96)
    {
      switch(quality)
      {
         case VID_REC_QTY_LOW:
                *bitrate_p = 32000;
                *skip_frame_p = 1;
            break;
         case VID_REC_QTY_NORMAL:
                *bitrate_p = 64000;
                *skip_frame_p = 1;
            break;
         case VID_REC_QTY_HIGH:
                *bitrate_p = 96000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_FINE:
                *bitrate_p = 128000;
            *skip_frame_p=0;
            break;
         default:
            ASSERT(0);
                *bitrate_p = 128000;
            *skip_frame_p=0;
            break;
      }
      }
    else if (area <= 160 * 120)
      {
      switch(quality)
      {
         case VID_REC_QTY_LOW:
                *bitrate_p = 50000;
                *skip_frame_p = 1;
            break;
         case VID_REC_QTY_NORMAL:
                *bitrate_p = 100000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_HIGH:
                *bitrate_p = 150000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_FINE:
                *bitrate_p = 200000;
            *skip_frame_p=0;
            break;
         default:
            ASSERT(0);
                *bitrate_p = 200000;
            *skip_frame_p=0;
            break;
      }
    }
    else if (area <= 176 * 144)
    {
#if ( defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M))
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 64000;
                *skip_frame_p = 1;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 128000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 192000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 256000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 256000;
                *skip_frame_p = 0;
                break;
        }
#elif defined(MT6225)
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 64000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 96000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 128000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 192000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 256000;
                *skip_frame_p = 0;
                break;
        }
#else
      /*MT6228, MT6229*/
        switch (quality)
        {
            case VID_REC_QTY_LOW:
            *bitrate_p=128000;
            *skip_frame_p=1;
                break;
            case VID_REC_QTY_NORMAL:
            *bitrate_p=256000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
            *bitrate_p=384000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
            *bitrate_p=512000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
            *bitrate_p=256000;
                *skip_frame_p = 0;
                break;
        }
#endif
    }
    else if (area <= 352 * 288)
    {
#if defined(MT6256)
        switch (quality)
        {
            case VID_REC_QTY_LOW:
            *bitrate_p=350000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
            *bitrate_p=500000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
            *bitrate_p=750000;  // 512000
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
            *bitrate_p=650000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
            *bitrate_p=600000;
                *skip_frame_p = 0;
                break;
        }
#elif defined(MT6276)      
      switch(quality)
      {
         case VID_REC_QTY_LOW:
            *bitrate_p=350000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_NORMAL:
            *bitrate_p=500000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_HIGH:
            *bitrate_p=750000;  // 512000
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_FINE:
            *bitrate_p=1500000;
            *skip_frame_p=0;
            break;
         default:
            ASSERT(0);
            *bitrate_p=600000;
            *skip_frame_p=0;
            break;
      }
#else
        switch (quality)
        {
            case VID_REC_QTY_LOW:
            *bitrate_p=350000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
            *bitrate_p=500000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
            *bitrate_p=650000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
            *bitrate_p=800000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
            *bitrate_p=600000;
                *skip_frame_p = 0;
                break;
        }
#endif
    }
#if defined(MT6256)
    else if (area <= 480*320)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 1750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 2000000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 2250000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 3500000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3400000;
                *skip_frame_p = 0;
                break;
        }
    }
#endif
#if defined(MT6256)
    else if (area <= 640 * 480)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 768000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 768000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 768000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 768000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3400000;
                *skip_frame_p = 0;
                break;
        }
    }
    else    /* larger than 640*480 */
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 384000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 384000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 384000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 384000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3000000;
                *skip_frame_p = 0;
                break;
        }
    }
#elif defined(MT6276)
    else if (area <= 640 * 480)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3000000;
                *skip_frame_p = 0;
                break;
        }
    }
    else    /* larger than 640*480 */
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 3750000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3000000;
                *skip_frame_p = 0;
                break;
        }
    }
#else
    else if (area <= 640 * 480)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 850000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 1700000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 2550000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 3400000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3400000;
                *skip_frame_p = 0;
                break;
        }
    }
    else    /* larger than 640*480 */
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 750000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 1500000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 2200000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 3000000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 3000000;
                *skip_frame_p = 0;
                break;
        }
    }
#endif
#endif
}

void vid_convert_quality_to_bitrate_in_phone(
        kal_uint16 width,
        kal_uint16 height,
        kal_uint8 quality,
        kal_uint32 *bitrate_p,
        kal_uint8 *skip_frame_p)
{
  vid_convert_quality_to_bitrate(width, height, quality, bitrate_p, skip_frame_p);
}

void vid_convert_quality_to_record_setting(
                MP4SwEncRecordSetting *rec_set,
                MP4SwEncQualityLevel  quality)
{
  rec_set->rate_balance_interval    = 60;

  switch(quality)
  {
#if defined(MT6235) || defined(MT6235B)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 96000;
    rec_set->algorithm_select = 2;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 30;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 256000;
    rec_set->algorithm_select = 2;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 384000;
    rec_set->algorithm_select = 2;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 10000000;
    rec_set->algorithm_select = 2;
    rec_set->frame_rate       = 15;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
#elif defined(MT6253)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 64000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 90;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
    rec_set->bit_rate         = 170000;
#else
    rec_set->bit_rate         = 384000;
#endif  // __CONTOUR_IMPROVEMENT_SUPPORT__
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 30;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 1950000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 1300000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 10;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
#elif defined(MT6253E) || defined(MT6252H)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 51200;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 72;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 307200;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 24;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 1560000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 1300000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 10;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
#elif defined(MT6253L) || defined(MT6252)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 51200;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 72;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 307200;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 24;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 1560000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 1300000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 10;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 4;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
#elif defined(MT6236) || defined(MT6236B)
#ifdef __VIDEO_ENC_D1_SUPPORT__
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 96000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 30;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 750000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 1500000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 480;
    rec_set->height           = 320;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 2;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 1024;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 3500000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 720;
    rec_set->height           = 480;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 2304;
    rec_set->rate_balance_interval    = 60;
    break;
#else
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 96000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 30;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 384000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 750000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 5;
    rec_set->qp_min           = 2;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 3500000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 12;
    rec_set->width            = 480;
    rec_set->height           = 320;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 3;
    rec_set->qp_min           = 3;
    rec_set->qp_max           = 15;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
#endif
#elif defined(MT6256)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 768000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 768000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 768000;
    rec_set->algorithm_select = 1;
    rec_set->frame_rate       = 15;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 5;
    rec_set->qp_min           = 2;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 768000;
    rec_set->algorithm_select = 0;
    rec_set->frame_rate       = 15;
    rec_set->width            = 640;
    rec_set->height           = 360;
    rec_set->intra_vop_rate   = 1;
    rec_set->qp_init          = 5;
    rec_set->qp_min           = 4;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
#elif defined(MT6276)
  case MP4SWENC_QUALITY_LOW:
    rec_set->bit_rate         = 256000;
    rec_set->algorithm_select = 3;
    rec_set->frame_rate       = 30;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate   = 90;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 256;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_NORMAL:
    rec_set->bit_rate         = 256000;
    rec_set->algorithm_select = 6;
    rec_set->frame_rate       = 30;
    rec_set->width            = 320;
    rec_set->height           = 240;
    rec_set->intra_vop_rate   = 30;
    rec_set->qp_init          = 10;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 768;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_GOOD:
    rec_set->bit_rate         = 3750000;
    rec_set->algorithm_select = 10;
    rec_set->frame_rate       = 20;
    rec_set->width            = 640;
    rec_set->height           = 368;
    rec_set->intra_vop_rate   = 25;
    rec_set->qp_init          = 5;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 800;
    rec_set->rate_balance_interval    = 60;
    break;
  case MP4SWENC_QUALITY_FINE:
    rec_set->bit_rate         = 3750000;
    rec_set->algorithm_select = 6;
    rec_set->frame_rate       = 15;
    rec_set->width            = 800;
    rec_set->height           = 480;
    rec_set->intra_vop_rate   = 15;
    rec_set->qp_init          = 5;
    rec_set->qp_min           = 3;
    rec_set->qp_max           = 31;
    rec_set->rate_hard_limit_multiple = 1886;
    rec_set->rate_balance_interval    = 60;
    break;
#endif
  case MP4SWENC_QUALITY_VT:
    rec_set->bit_rate         = 48000;
    rec_set->algorithm_select = 3;
    rec_set->frame_rate      = 10;
    rec_set->width            = 176;
    rec_set->height           = 144;
    rec_set->intra_vop_rate  = 40;
    rec_set->qp_init          = 18;
    rec_set->qp_min           = 1;
    rec_set->qp_max           = 31;
	rec_set->rate_hard_limit_multiple = 256;
  rec_set->rate_balance_interval    = 60;
	break;
  default:
    ASSERT(0);
    break;
  }
}

void vid_convert_quality_to_bitrate_for_matv(
        kal_uint16 width,
        kal_uint16 height,
        kal_uint8 quality,
        kal_uint32 is_ntsc,
        kal_uint32 *bitrate_p,
        kal_uint8 *skip_frame_p)
{
#if defined(MT6236) || defined(MT6236B)
  *skip_frame_p = 0;

  switch (quality)
  {
    case VID_REC_QTY_LOW:
      *bitrate_p = 96000;
      break;
    case VID_REC_QTY_NORMAL:
      *bitrate_p = 384000;
      break;
    case VID_REC_QTY_HIGH:
      *bitrate_p = 750000;
      break;
    case VID_REC_QTY_FINE:
      *bitrate_p = 3000000;
      break;
    default:
      ASSERT(0);
      *bitrate_p = 3500000;
      break;
  }
#elif ( defined(MT6235) || defined(MT6235B))
  *skip_frame_p = 0;

  switch (quality)
  {
    case VID_REC_QTY_LOW:
      *bitrate_p = 96000;
      break;
    case VID_REC_QTY_NORMAL:
      *bitrate_p = 256000;
      break;
    case VID_REC_QTY_HIGH:
      *bitrate_p = 384000;
      break;
    case VID_REC_QTY_FINE:
      *bitrate_p = 1950000;
      break;
    default:
      ASSERT(0);
      *bitrate_p = 1950000;
      break;
  }
#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
  *skip_frame_p = 0;

  switch (quality)
  {
    case VID_REC_QTY_LOW:
      *bitrate_p = 64000;
      break;
    case VID_REC_QTY_NORMAL:
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
      *bitrate_p = 170000;
#else
      *bitrate_p = 256000;
#endif  // __CONTOUR_IMPROVEMENT_SUPPORT__
      break;
    case VID_REC_QTY_HIGH:
      *bitrate_p = 1950000;
      break;
    case VID_REC_QTY_FINE:
      *bitrate_p = 1300000;
      break;
    default:
      ASSERT(0);
      *bitrate_p = 1300000;
      break;
  }
#else
  vid_convert_quality_to_bitrate(width, height, quality, bitrate_p, skip_frame_p);
#endif
}


#if defined(MT6252) || defined(MT6252H)
/******************************************************************************
* This is the non-HAL frame rate table.
******************************************************************************/
static VIDEO_RECORD_FRAME_RATE_TABLE_T _rFrameRateTable[] =
{
    {176, 144, {120, 75}},
    {320, 240, {100, 75}}
};


/******************************************************************************
* This is the non-HAL frame rate table implementation.
*
* Context:
*
* Side effect:
******************************************************************************/
MEDIA_STATUS_CODE video_recorder_get_frame_rate(kal_uint16 u2Width,
        kal_uint16 u2Height, VIDEO_RECORDER_FRAME_RATE_T *prFrameRate)
{
    kal_uint32 u4Idx;
    kal_uint32 u4Entries = sizeof(_rFrameRateTable) / sizeof(_rFrameRateTable[0]);

    ASSERT(prFrameRate != NULL);
    for (u4Idx = 0; u4Idx < u4Entries; u4Idx++)
    {
        if ((u2Width == _rFrameRateTable[u4Idx].u2Width) &&
            (u2Height == _rFrameRateTable[u4Idx].u2Height))
        {
            prFrameRate->u2FrameRate = _rFrameRateTable[u4Idx].rFrameRate.u2FrameRate;
            prFrameRate->u2NightModeFrameRate = _rFrameRateTable[u4Idx].rFrameRate.u2NightModeFrameRate;
            break;
        }
    }

    if (u4Idx == u4Entries)
    {
        kal_mem_set((void*)prFrameRate, 0, sizeof(*prFrameRate));
        return VIDEO_ERROR;
    }

    return MEDIA_STATUS_OK;
}
#else
/******************************************************************************
* This is the non-HAL frame rate table implementation.
*
* Context:
*
* Side effect:
******************************************************************************/
MEDIA_STATUS_CODE video_recorder_get_frame_rate(kal_uint16 u2Width,
        kal_uint16 u2Height, VIDEO_RECORDER_FRAME_RATE_T *prFrameRate)
{
    ASSERT(prFrameRate != NULL);
    kal_mem_set((void*)prFrameRate, 0, sizeof(*prFrameRate));
    return VIDEO_ERROR;
}
#endif  // defined(MT6252) || defined(MT6252H)


#endif  // MED_NOT_PRESENT


