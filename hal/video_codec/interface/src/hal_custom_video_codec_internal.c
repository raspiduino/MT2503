/*****************************************************************************
 * Filename: 
 * ---------
 * hal_custom_video_codec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customization of video features
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "drv_features_vcodec.h"
#include "hal_custom_video_codec_if.h"
//#include "kal_general_types.h"
#include "vcodec_if.h"
#include "hal_custom_video_codec.h"

#pragma thumb

/******************************************************************************
* customization of "A/V sync. mechanism"
******************************************************************************/
typedef struct
{    
    UINT64 cust[10];
    //cust[0]   : dynamic switch threshold for quality mode
    //cust[1]   : initial quality mode (0:lossless, ..., n: sub-sample, n+1: default)
    //cust[2]   : dynamic switch flag
    //cust[3]   : drop B (0: always not drop, 1: always drop non-ref B)
    //cust[4]   : reserved
    //cust[5]   : reserved
    //cust[6]   : reserved
    //cust[7]   : reserved
    //cust[8]   : reserved
    //cust[9]   : H.264 concealment quality mode	
    //            0: try to output the "correct" frame only
    //            1: try to output the all the "conceal" frame w   checking the frame number continuity
    //            2: try to output the all the "conceal" frame w/o checking the frame number continuity
    //            3: default
} mply_codec_custom_struct;

#if 0
/* under construction !*/
/* under construction !*/
    #if defined(MP4_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /*default setting*/
/* under construction !*/
    #endif
/* under construction !*/
    #if defined(H264_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /*default setting*/
/* under construction !*/
    #endif
/* under construction !*/
    #if defined(RM_CUSTOM_TABLE_SETTING_ENABLE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /*default setting*/
/* under construction !*/
    #endif
/* under construction !*/
    #if defined(VP8_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /*default setting*/
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
#endif

#if 1
#if defined (__MPEG4_DEC_SUPPORT__)
static mply_codec_custom_struct mply_codec_MP4CustomSetting =
    #if defined(MP4_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
    {MP4_CODEC_CUSTOM_TABLE_SETTING_0,  
     MP4_CODEC_CUSTOM_TABLE_SETTING_1,  
     MP4_CODEC_CUSTOM_TABLE_SETTING_2, 
     MP4_CODEC_CUSTOM_TABLE_SETTING_3, 
     MP4_CODEC_CUSTOM_TABLE_SETTING_4,
     0,
     MP4_CODEC_CUSTOM_TABLE_SETTING_6, 
     0, 
     0, 
     0
     }; /* MP4 */
    #else /*default setting*/
    {0x402010, 4, 1, 0x00FA7001, 151, 0x01020401, 250, 0, 0, 3}; /* MP4 */
    #endif    
#endif

#if defined (__H264_DEC_SUPPORT__)
static mply_codec_custom_struct mply_codec_H264CustomSetting =
    #if defined(H264_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
    {H264_CODEC_CUSTOM_TABLE_SETTING_0,  
     H264_CODEC_CUSTOM_TABLE_SETTING_1,  
     H264_CODEC_CUSTOM_TABLE_SETTING_2, 
     H264_CODEC_CUSTOM_TABLE_SETTING_3, 
     0,
     0,
     H264_CODEC_CUSTOM_TABLE_SETTING_6, 
     0, 
     0, 
     0
     }; /* H264 */
    #else /*default setting*/
    {0x706060, 4, 1, 0x00FA7001, 0, 0x01020401, 250, 0, 0, 3}; /* H264 */
    #endif
#endif

#if defined (__RM_DEC_SUPPORT__)
static mply_codec_custom_struct mply_codec_RMCustomSetting =
    #if defined(RM_CUSTOM_TABLE_SETTING_ENABLE)
    {RM_CODEC_CUSTOM_TABLE_SETTING_0,  
     RM_CODEC_CUSTOM_TABLE_SETTING_1,  
     RM_CODEC_CUSTOM_TABLE_SETTING_2, 
     RM_CODEC_CUSTOM_TABLE_SETTING_3, 
     0, 
     0, 
     0, 
     0, 
     0, 
     0
     }; /* RM */
    #else /*default setting*/
    {0, 16, 1, 2, 0, 0, 0, 0, 0, 0};  /* RM */
    #endif
#endif

#if defined (__VP8_DEC_SW_SUPPORT__)
static mply_codec_custom_struct mply_codec_VP8CustomSetting =
    #if defined(VP8_CODEC_CUSTOM_TABLE_SETTING_ENABLE)
    {VP8_CODEC_CUSTOM_TABLE_SETTING_0,  
     VP8_CODEC_CUSTOM_TABLE_SETTING_1,  
     VP8_CODEC_CUSTOM_TABLE_SETTING_2, 
     VP8_CODEC_CUSTOM_TABLE_SETTING_3, 
     0,
     0,
     VP8_CODEC_CUSTOM_TABLE_SETTING_6, 
     0, 
     0, 
     0
     }; /* VP8 */
    #else /*default setting*/
    {0x706060, 4, 1, 0x00FA7001, 0, 0x01020401, 250, 0, 0, 4}; /* VP8 */
    #endif    
#endif

/* get value */
UINT64 mply_codec_custom_get_cust(mply_codec_custom_format_enum format, unsigned int idx)
{
    switch(format)
    {
    #if defined (__MPEG4_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_MP4:
        return mply_codec_MP4CustomSetting.cust[idx];
      //break;
    #endif
    #if defined (__H264_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_H264:
        return mply_codec_H264CustomSetting.cust[idx];
      //break;
    #endif
    #if defined (__RM_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_RM:
        return mply_codec_RMCustomSetting.cust[idx];
      //break;
    #endif
    #if defined (__VP8_DEC_SW_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_VP8:
        return mply_codec_VP8CustomSetting.cust[idx];
      //break;
    #endif
      default:
        return 0;
    }
}


/* set value */
void mply_codec_custom_set_cust(mply_codec_custom_format_enum format, unsigned int idx, UINT64 cust)
{   
    
    switch(format)
    {
    #if defined (__MPEG4_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_MP4:
        mply_codec_MP4CustomSetting.cust[idx] = cust;
      break;
    #endif
    #if defined (__H264_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_H264:
        mply_codec_H264CustomSetting.cust[idx] = cust;
      break;
    #endif
    #if defined (__RM_DEC_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_RM:
        mply_codec_RMCustomSetting.cust[idx] = cust;
      break;
    #endif
    #if defined (__VP8_DEC_SW_SUPPORT__)
      case MPLY_CODEC_CUSTOM_FORMAT_VP8:
        mply_codec_VP8CustomSetting.cust[idx] = cust;
      break;
    #endif
      default:
        return ;
    }    
}
#endif

static void ProcessQualityMode(mply_codec_custom_format_enum format)
{
    unsigned int cust;

	// set qty=0, disable dynamic switch
	mply_codec_custom_set_cust(format,1,0);
	cust = (unsigned int)(mply_codec_custom_get_cust(format,5)&0x00ffffff);
	cust |= (MPLY_CODEC_CUSTOM_PLAYBACK_MODE_QUALITY<<24);
	mply_codec_custom_set_cust(format,5,cust);
}

static void ProcessFluencyMode(mply_codec_custom_format_enum format)
{
	// set qty=fluency level, disable dynamic switch
	int fl;
    unsigned int cust;
	
	fl = (mply_codec_custom_get_cust(format,5)&0x00ff0000)>>16;
	if(fl > 0) mply_codec_custom_set_cust(format,1,fl);
	cust = (unsigned int)(mply_codec_custom_get_cust(format,5)&0x00ffffff);
	cust |= (MPLY_CODEC_CUSTOM_PLAYBACK_MODE_FLUENT<<24);
	mply_codec_custom_set_cust(format,5,cust);
}

static void ProcessBalanceMode(mply_codec_custom_format_enum format)
{
    unsigned int cust;

	// set qty=4, enable dynamic switch
	mply_codec_custom_set_cust(format,1,4);
	mply_codec_custom_set_cust(format,2,1);
	cust = (unsigned int)(mply_codec_custom_get_cust(format,5)&0x00ffffff);
	cust |= (MPLY_CODEC_CUSTOM_PLAYBACK_MODE_BALANCE<<24);
	mply_codec_custom_set_cust(format,5,cust);
}
static void ProcessSetPlaybackMode(mply_codec_custom_format_enum eFormat, unsigned int value)
{
	if(value == MPLY_CODEC_CUSTOM_PLAYBACK_MODE_QUALITY)
	{
		ProcessQualityMode(eFormat);
	}
	else if(value == MPLY_CODEC_CUSTOM_PLAYBACK_MODE_FLUENT)
	{
		ProcessFluencyMode(eFormat);
	}
	else if(value == MPLY_CODEC_CUSTOM_PLAYBACK_MODE_BALANCE)
	{
		ProcessBalanceMode(eFormat);
	}
}

static int ITEM_GET_PLAYBACK_MODE(mply_codec_custom_format_enum format)
{
        // return playback mode
        int mode;
                
        mode = ((unsigned int)(mply_codec_custom_get_cust(format,5)&0xff000000))>>24;
        if(mode>=MPLY_CODEC_CUSTOM_PLAYBACK_MODE_NUM) mode = MPLY_CODEC_CUSTOM_PLAYBACK_MODE_NUM-1;
        else if(mode < 0) mode = 0;
                return mode;
}

static int ITEM_GET_PREVIOUS_MODE(mply_codec_custom_format_enum format)
{
        // return last used mode
        int speed,dynamic;
        unsigned int cust;
                
        cust = (unsigned int)(mply_codec_custom_get_cust(format,5)&0x0000ffff);
        speed = cust>>8;
        dynamic = cust&0xff;
        if(speed>3 && dynamic>0) return 4;
        return (speed > 3) ? 0 : speed;
}

static void ITEM_SET_FLUENCY_LEVEL(mply_codec_custom_format_enum format, unsigned int value)
{
	      unsigned int cust;
	      
        if(value > 0) 
        {
            int mode;
                    
            cust = (unsigned int)(mply_codec_custom_get_cust(format,5)&0xff00ffff);
            mode = cust>>24;
            if(mode==MPLY_CODEC_CUSTOM_PLAYBACK_MODE_FLUENT) mply_codec_custom_set_cust(format,1,value);
            cust |= ((value&0xff)<<16);
            mply_codec_custom_set_cust(format,5,cust);
        }

}


int mply_codec_custom_query(mply_codec_custom_format_enum format, mply_codec_custom_item_enum item, unsigned int value)
{
    unsigned int cust;
         
    if(format == MPLY_CODEC_CUSTOM_FORMAT_MP4)
    {
        switch(item)
        {
        case MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE:
			#if 1
			ProcessSetPlaybackMode(format, value);
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
/* under construction !*/
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
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE:
		    #if 1
			{
                // return playback mode
                int mode;
				
			    mode =ITEM_GET_PLAYBACK_MODE(MPLY_CODEC_CUSTOM_FORMAT_MP4);				
				return mode;
		    }
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PREVIOUS_MODE:
		    #if 1
			{
                // return last used mode
                int speed;
				
				speed =ITEM_GET_PREVIOUS_MODE(MPLY_CODEC_CUSTOM_FORMAT_MP4);
				return speed;				
			}
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_SET_FLUENCY_LEVEL:
		    #if 1
			    ITEM_SET_FLUENCY_LEVEL(MPLY_CODEC_CUSTOM_FORMAT_MP4,value);
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
			#endif
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_FLUENCY_LEVEL:
            {
                int level;
                
                level = ((unsigned int)(mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5)&0x00ff0000))>>16;
                return level;
            }
            //break;
        default: break;
        }
    }
    else if(format == MPLY_CODEC_CUSTOM_FORMAT_H264)
    {
        switch(item)
        {
        case MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE:
			#if 1
			ProcessSetPlaybackMode(format, value);
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
/* under construction !*/
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
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE:
		    #if 1
			{
                // return playback mode
                int mode;
				
			    mode =ITEM_GET_PLAYBACK_MODE(MPLY_CODEC_CUSTOM_FORMAT_H264);				
				return mode;
		    }			
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PREVIOUS_MODE:
		    #if 1
			{
                // return last used mode
                int speed;
				
				speed =ITEM_GET_PREVIOUS_MODE(MPLY_CODEC_CUSTOM_FORMAT_H264);
				return speed;				
			}			
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_SET_FLUENCY_LEVEL:
		    #if 1
			    ITEM_SET_FLUENCY_LEVEL(MPLY_CODEC_CUSTOM_FORMAT_H264,value);			
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
			#endif
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_FLUENCY_LEVEL:
            {
                int level;
                
                level = ((unsigned int)(mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5)&0x00ff0000))>>16;
                return level;
            }
            //break;
        default: break;
        }	
    }
    else if(format == MPLY_CODEC_CUSTOM_FORMAT_RM)
    {
    }
    else if(format == MPLY_CODEC_CUSTOM_FORMAT_VP8)
    {
        switch(item)
        {
        case MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE:
			#if 1
			ProcessSetPlaybackMode(format, value);
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
/* under construction !*/
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
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE:
			#if 1
			{
                // return playback mode
                int mode;
				
			    mode =ITEM_GET_PLAYBACK_MODE(MPLY_CODEC_CUSTOM_FORMAT_VP8);				
				return mode;
		    }			
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_PREVIOUS_MODE:
			#if 1
			{
                // return last used mode
                int speed;
				
				speed =ITEM_GET_PREVIOUS_MODE(MPLY_CODEC_CUSTOM_FORMAT_VP8);
				return speed;				
			}			
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
			#endif
            //break;
        case MPLY_CODEC_CUSTOM_ITEM_SET_FLUENCY_LEVEL:
		    #if 1
			    ITEM_SET_FLUENCY_LEVEL(MPLY_CODEC_CUSTOM_FORMAT_VP8,value);			
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
			#endif
            break;
        case MPLY_CODEC_CUSTOM_ITEM_GET_FLUENCY_LEVEL:
            {
                int level;
                
                level = ((unsigned int)(mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,5)&0x00ff0000))>>16;
                return level;
            }
            //break;
        default: break;
        }	
    }    
    
    return 0;
}
#pragma arm
