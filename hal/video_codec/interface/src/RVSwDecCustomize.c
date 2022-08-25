#ifdef __RM_DEC_SUPPORT__
#include "rvtypes.h"
#include "decdefs.h"
#include "RVSwDecCustomize.h"
    #if defined(__MTK_TARGET__)
#include "hal_custom_video_codec_if.h"
    #endif

#if !defined(WIN32)
#if (defined(MT6253T)||defined(MT6253))
#pragma arm section zidata="RVDEC3_DYNAMIC_RO", code, rwdata, rodata
#elif defined(MT6236) || defined(MT6236B)
#pragma arm section zidata="RVDEC1_DYNAMIC_RO", code, rwdata, rodata
#endif
#endif

/* normal*/
const U32 RV_Factor_Rn[32] = 
{
19538, 
12254, 
7835 ,
5155 ,
3530 ,
2544 ,
1946 ,
1583 ,
1363 ,
1230 ,
1149 ,
1100 ,
1070 ,
1052 ,
1041 ,
1024 ,
1007 ,
997  ,
980  ,
954  ,
913  ,
853  ,
769  ,
662  ,
539  ,
412  ,
297  ,
203  ,
134  ,
86   ,
54   ,
33   
};
/*drop all B*/
const U32 RV_Factor_Rn1[32] = 
{
32767, 
32767, 
32767, 
32767, 
32767, 
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767,
32767 
};

/* High resolution*/
const U32 RV_Factor_Rn2[32] = 
{
32767,
32767,
32767,
32767,
32767,
32767,
32767,
31549,
19538,
12254,
7835 ,
5155 ,
3530 ,
2544 ,
1946 ,
1583 ,
1363 ,
1230 ,
1149 ,
1100 ,
1070 ,
1052 ,
1041 ,
1024 ,
1007 ,
997  ,
980  ,
954  ,
913  ,
853  ,
769  ,
662  
};
#if !defined(WIN32)
#pragma arm section zidata, code, rwdata, rodata
#endif


#if defined(MT6236) || defined(MT6236B) || defined(MT6255)
#define RM_HIGH_RESOLUTION 640*480
#elif defined(MT6235) || defined(MT6235B)
#define RM_HIGH_RESOLUTION 480*320
#elif (defined(MT6253T)||defined(MT6253)||defined(MT6253E)||defined(MT6253L)|| defined(MT6252H) || defined(MT6252))
#define RM_HIGH_RESOLUTION 176*144
#elif defined(MT6276) || defined(MT6575) || defined(MT6256)
#define RM_HIGH_RESOLUTION 848*480
#endif
const U32*  SWRMGetSkipBSetting(U32 height,U32 width,U32 Total_Buffer_Size)
{
	
	U32 size = height*width;

	if(size > RM_HIGH_RESOLUTION)
		return RV_Factor_Rn2; /* High resolution*/	
	else
	    return RV_Factor_Rn;  /* normal*/
}
I32 SWRMSetBufferTimeLimit(void)
{
	I32 time;
	time = 0; //0 ms 	
	return time;
}



/* set buffer therhold for adaptive de-blocking filter , range 0 ~ 31*/
I32 SWRMSetDBKFilterBufferTH(RV_FrameType type)
{

	switch(type)
	{
	case INTRA:
		return 8;
	case INTER:
		return 16;
	case TRUEB:
		return 24;
	default:
		return 31;
	}
	
}
/* set buffer therhold for adaptive Fast de-blocking filter , range 0 ~ 31*/
I32 SWRMSetFDBKFilterBufferTH(RV_FrameType type)
{

	switch(type)
	{
	case INTRA:
		return 16;
	case INTER:
		return 24;
	case TRUEB:
		return 31; /* NO fast de-blocking on B frame */
	default:
		return 31;
	}
	
}

U32 SWRMSetDBKFilterArea(void)
{
	U32 area;
	area = 320*240;//QVGA	
	return area;
}
U32 SWRMSetDBKFilterBitrate(U32 height,U32 width)
{
	U32 bitrate;
	bitrate = 328;//0.01*37268
	return bitrate;
}

U32 SWRMQuerySpeedyMode(U32 height,U32 width,U32 fps, U32 bitrate)
{
    U32 total_pixel = width*height;
    U32 cust;
    U32 qty;
#if defined(__MTK_TARGET__) 
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_RM,1);
#else
	cust = 0xffffffff;
#endif

	if(fps == 0 && bitrate == 0)
	{ /* only for set YUV buffer */
		if( total_pixel > RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
			return SW_RM_SPEEDY_MODE_5;
		else
			return SW_RM_SPEEDY_MODE_0;
	
	}

    qty = (U32)(cust&0xffffffff);
    if( qty > SW_RM_SPEEDY_MODE_4 && qty < SW_RM_SPEEDY_MODE_5) qty = SW_RM_SPEEDY_MODE_5;
    if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_0)
        return (qty<16) ? qty : SW_RM_SPEEDY_MODE_0;
    else if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_1)
        return (qty<16) ? qty : SW_RM_SPEEDY_MODE_1;
    else if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_2)
        return (qty<16) ? qty : SW_RM_SPEEDY_MODE_2;
    else if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_3)
        return (qty<16) ? qty : SW_RM_SPEEDY_MODE_3;
    else if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_4)
        return (qty<16) ? qty : SW_RM_SPEEDY_MODE_4;			
    else if( total_pixel <= SW_RM_SPEEDY_BOUND_RES_5_DEFAULT)		
        return SW_RM_SPEEDY_MODE_5;
    else
        return _RV_NO_SUPPORT;	
}

U32 SWRVQuerySkipScalability(void)
{
    U32 cust;
    U32 skip;
#if defined(__MTK_TARGET__)    
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_RM,3);
#else
	cust = 2;
#endif
    skip = (U32)(cust&0xffffffff);
    if(skip > 1) return 2;
    return skip;
}

#endif /* RM_SUPPORT */
