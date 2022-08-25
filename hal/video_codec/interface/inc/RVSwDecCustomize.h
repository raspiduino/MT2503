

#ifndef RV_SW_DEC_CONFIG_H
#define RV_SW_DEC_CONFIG_H

#ifdef __RM_DEC_SUPPORT__
#include "rvtypes.h"
#include "decdefs.h"


#if defined(__MTK_TARGET__) 
#include "hal_custom_video_codec.h"
#include "sw_video_decode_custom.h"
#endif

#ifndef RV9_DEC_MAX_NORMAL_WIDTH 
  #define RV9_DEC_MAX_NORMAL_WIDTH 1920
#endif
#ifndef RV9_DEC_MAX_NORMAL_HEIGHT 
  #define RV9_DEC_MAX_NORMAL_HEIGHT 1088
#endif

#ifndef RV9_DEC_MAX_WIDTH 
  #define RV9_DEC_MAX_WIDTH 1920
#endif
#ifndef RV9_DEC_MAX_HEIGHT 
  #define RV9_DEC_MAX_HEIGHT 1088
#endif




#define SW_RM_SPEEDY_MODE_0		0x0  //standard decoder
#define SW_RM_SPEEDY_MODE_1		0x1  //speedy mode 1
#define SW_RM_SPEEDY_MODE_2		0x2  //speedy mode 2
#define SW_RM_SPEEDY_MODE_3		0x3  //speedy mode 3 , dynamic switch
#define SW_RM_SPEEDY_MODE_4		0x4  //speedy mode 4 , dynamic switch
#define SW_RM_SPEEDY_MODE_5		0xF  //fast decoder
#define _RV_NO_SUPPORT			0xFF 



// Max. resoultion of mode 0~4 adopt RV9_MAX_NORMAL_MODE_RESOLUTION which define in sw_video_decode_custom.h
// Max. resoultion of mode 5 adopt RV9_SUPPORT_RESOLUTION which define in sw_video_decode_custom.h
#define SW_RM_SPEEDY_BOUND_RES_5_DEFAULT (RV9_DEC_MAX_WIDTH*RV9_DEC_MAX_HEIGHT)
#ifndef SW_RM_SPEEDY_CUSTOM_ENABLE

#if defined(MT6236) || defined(MT6236B)
	#define SW_RM_SPEEDY_BOUND_RES_0_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_1_DEFAULT (848*480)
	#define SW_RM_SPEEDY_BOUND_RES_2_DEFAULT (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
	#define SW_RM_SPEEDY_BOUND_RES_3_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_4_DEFAULT 0
#elif defined(MT6235) || defined(MT6235B) || defined(MT6255)
	#define SW_RM_SPEEDY_BOUND_RES_0_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_1_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_2_DEFAULT (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
	#define SW_RM_SPEEDY_BOUND_RES_3_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_4_DEFAULT 0
#elif (defined(MT6253T)||defined(MT6253)||defined(MT6253E)||defined(MT6253L)|| defined(MT6252H) || defined(MT6252))
	#define SW_RM_SPEEDY_BOUND_RES_0_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_1_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_2_DEFAULT (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
	#define SW_RM_SPEEDY_BOUND_RES_3_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_4_DEFAULT 0
#elif defined(MT6276) || defined(MT6256)
	#define SW_RM_SPEEDY_BOUND_RES_0_DEFAULT (320*240)
	#define SW_RM_SPEEDY_BOUND_RES_1_DEFAULT (848*480)
	#define SW_RM_SPEEDY_BOUND_RES_2_DEFAULT (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
	#define SW_RM_SPEEDY_BOUND_RES_3_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_4_DEFAULT 0
#elif defined(MT6575)
#define SW_RM_SPEEDY_BOUND_RES_0_DEFAULT (1280*720)
#define SW_RM_SPEEDY_BOUND_RES_1_DEFAULT 0
#define SW_RM_SPEEDY_BOUND_RES_2_DEFAULT (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT)
	#define SW_RM_SPEEDY_BOUND_RES_3_DEFAULT 0
	#define SW_RM_SPEEDY_BOUND_RES_4_DEFAULT 0
#else
	#error not support chip!
#endif /*Support Chip */
#endif /*SW_RM_LOSSY_CUSTOM_ENABLE*/


#if defined(SW_RM_SPEEDY_BOUND_RES_0_CUSTOM)
	#define SW_RM_SPEEDY_BOUND_RES_0 SW_RM_SPEEDY_BOUND_RES_0_CUSTOM
#else
	#define SW_RM_SPEEDY_BOUND_RES_0 SW_RM_SPEEDY_BOUND_RES_0_DEFAULT
#endif/*SW_RM_SPEEDY_BOUND_RES_0_CUSTOM*/

#if defined(SW_RM_SPEEDY_BOUND_RES_1_CUSTOM)
	#define SW_RM_SPEEDY_BOUND_RES_1 SW_RM_SPEEDY_BOUND_RES_1_CUSTOM
#else
	#define SW_RM_SPEEDY_BOUND_RES_1 SW_RM_SPEEDY_BOUND_RES_1_DEFAULT
#endif/*SW_RM_SPEEDY_BOUND_RES_1_CUSTOM*/

#if defined(SW_RM_SPEEDY_BOUND_RES_2_CUSTOM)
	#define SW_RM_SPEEDY_BOUND_RES_2 SW_RM_SPEEDY_BOUND_RES_2_CUSTOM
#else
	#define SW_RM_SPEEDY_BOUND_RES_2 SW_RM_SPEEDY_BOUND_RES_2_DEFAULT
#endif/*SW_RM_SPEEDY_BOUND_RES_2_CUSTOM*/

#if defined(SW_RM_SPEEDY_BOUND_RES_3_CUSTOM)
	#define SW_RM_SPEEDY_BOUND_RES_3 SW_RM_SPEEDY_BOUND_RES_3_CUSTOM
#else
	#define SW_RM_SPEEDY_BOUND_RES_3 SW_RM_SPEEDY_BOUND_RES_3_DEFAULT
#endif/*SW_RM_SPEEDY_BOUND_RES_3_CUSTOM*/

#if defined(SW_RM_SPEEDY_BOUND_RES_4_CUSTOM)
	#define SW_RM_SPEEDY_BOUND_RES_4 SW_RM_SPEEDY_BOUND_RES_4_CUSTOM
#else
	#define SW_RM_SPEEDY_BOUND_RES_4 SW_RM_SPEEDY_BOUND_RES_4_DEFAULT
#endif/*SW_RM_SPEEDY_BOUND_RES_4_CUSTOM*/



#if (SW_RM_SPEEDY_BOUND_RES_0 > (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT))
	#error "Invalid SW_RM_SPEEDY_BOUND_RES_0"
#endif
#if (SW_RM_SPEEDY_BOUND_RES_1 > (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT))
#	error "Invalid SW_RM_SPEEDY_BOUND_RES_1"
#endif
#if (SW_RM_SPEEDY_BOUND_RES_2 > (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT))
	#error "Invalid SW_RM_SPEEDY_BOUND_RES_2"
#endif
#if (SW_RM_SPEEDY_BOUND_RES_3 > (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT))
	#error "Invalid SW_RM_SPEEDY_BOUND_RES_3"
#endif
#if (SW_RM_SPEEDY_BOUND_RES_4 > (RV9_DEC_MAX_NORMAL_WIDTH*RV9_DEC_MAX_NORMAL_HEIGHT))
	#error "Invalid SW_RM_SPEEDY_BOUND_RES_4"
#endif
typedef enum 
{
	INTRA	= 0,
	INTER	= 1,
	TRUEB	= 2,	
}RV_FrameType;
extern U32 SWRMQuerySpeedyMode(U32 height,U32 width,U32 fps, U32 bitrate);
extern U32 SWRVQuerySkipScalability(void);
extern I32 SWRMSetBufferTimeLimit(void);
extern I32 SWRMSetDBKFilterBufferTH(RV_FrameType type);
extern I32 SWRMSetFDBKFilterBufferTH(RV_FrameType type);
extern const U32* SWRMGetSkipBSetting(U32 height,U32 width,U32 Total_Buffer_Size);
extern U32 SWRMSetDBKFilterArea(void);
extern U32 SWRMSetDBKFilterBitrate(U32 height,U32 width);

#endif/*__RM_DEC_SUPPORT__*/
#endif/*RV_SW_DEC_CONFIG_H*/
