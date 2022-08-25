#ifndef _MAVCAP_COMM_DEF_H_
#define _MAVCAP_COMM_DEF_H_

#include "kal_release.h"

/****************************************************************************
 *          General Purpose Usage Macro & Variable
 ****************************************************************************/
#define CAMERA_MAVCAP_IMAGE_BYTES 		(2)
#define MAVCAP_IMAGE_XS				(160)
#define MAVCAP_IMAGE_YS				(120)

#if(defined(MAVCAP_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
	#if ((LCD_WIDTH*LCD_HEIGHT*2)>(MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*CAMERA_MAVCAP_IMAGE_BYTES+MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS))
		#define MAVCAP_CAP_BUFFER_SIZE 	 ((((LCD_WIDTH*LCD_HEIGHT*2)+31)>>5)<<5)
	#else
#define MAVCAP_CAP_BUFFER_SIZE			((((MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*CAMERA_MAVCAP_IMAGE_BYTES+MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS)+31)>>5)<<5)
	#endif									
#else
#define MAVCAP_CAP_BUFFER_SIZE			((((MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*CAMERA_MAVCAP_IMAGE_BYTES+MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS)+31)>>5)<<5)
#endif

//#define MAVCAP_LOG_DEBUG_INFO
#ifdef MAVCAP_LOG_DEBUG_INFO
#define MAVCAP_LOG_BUFFER_SIZE			((((768+MAVCAP_IMAGE_XS*MAVCAP_IMAGE_YS*CAMERA_MAVCAP_IMAGE_BYTES)+31)>>5)<<5) //Prz + Log	
#else
#define MAVCAP_LOG_BUFFER_SIZE				(0) //BYTES
#endif


/********* MAV Motion ***********/
// MavMotion Working Buffer size
#define MAVCAP_MOTION_BUFFER_SIZE		((((((MOTION_TOTAL_BN*2*4+2)*4))+31)>>5)<<5)  //mv+tv+tv_cnt+acc_mv+tmp_mv
#define MOTION_TOTAL_BN                 (16)                        // EIS bin number

#define MAVCAP_WORKING_BUFFER_SIZE		(MAVCAP_CAP_BUFFER_SIZE + MAVCAP_MOTION_BUFFER_SIZE)

/****************************************************************************
 *          MAVCAP ENUM
 ****************************************************************************/
typedef enum
{   
    MAVCAP_DIR_RIGHT=0,
    MAVCAP_DIR_LEFT,
    MAVCAP_DIR_UP,
    MAVCAP_DIR_DOWN,
    MAVCAP_DIR_NO,
} MAVCAP_DIRECTION_ENUM;

typedef enum
{   
    MAVCAP_HINT_DIR_RIGHT=0,
    MAVCAP_HINT_DIR_RIGHT_DOWN,
    MAVCAP_HINT_DIR_DOWN,
    MAVCAP_HINT_DIR_LEFT_DOWN,
    MAVCAP_HINT_DIR_LEFT,
    MAVCAP_HINT_DIR_LEFT_UP,
    MAVCAP_HINT_DIR_UP,
    MAVCAP_HINT_DIR_RIGHT_UP,
    MAVCAP_HINT_DIR_NO,
} MAVCAP_HINT_DIRECTION_ENUM;



typedef struct
{
	// Tuning Parameter for AutoCap
    kal_uint32 tolerance_x; //x direction tolerance for capture, currently, not be used just for extension in the future  (default: 8) 7~9
    kal_uint32 tolerance_y; //y direction tolerance for capture, currently, not be used just for extension in the future  (default: 8) 7~9

	// Tuning Parameter for MavMotion
    kal_int32  MaxMV;                      // maximum motion vertor        (default: 8) 7~9
    kal_int32  StepLB;                     // upper bound of frame step    (default: 3) 2~4
    kal_int32  StepUB;                     // lower bound of frame step    (default: 8) 7~9  
} MAVCAP_TUNING_PARA_STRUCT, *P_MAVCAP_TUNING_PARA_STRUCT;

// Results
typedef struct 
{
    kal_int16      MV_X;                // accumulated x motion vector 
    kal_int16      MV_Y;                // accumulated y motion vector  
    kal_uint16     ImageWidth;          // processed image width in core algorithm
    kal_uint16     ImageHeight;         // processed image height in core algorithm
    kal_uint32     OverlapRatio;        // overlap ratio (base = 64, OVLP_RATIO = 16=>16/64=1/4, OVLP_RATIO= 32=> 32/64=1/2, OVLP_RATIO = 21=>21/64~=1/3)
    kal_bool       ReadyToShot;         // ready to shot flag
    MAVCAP_DIRECTION_ENUM Direction;   // detected motion direction
    MAVCAP_HINT_DIRECTION_ENUM HintDirection; // hint to user direction
    kal_uint8	   ErrPattern;             // returned error/warning bit pattern 
                                        // bit 0: low trust value (set if warning)
                                        // bit 1: large motion vector (set if warning)
                                        // bit 2: vertical shake (set if warning)
	kal_uint16		FrameCount;
}MAVCAP_RESULT_STRUCT, *P_MAVCAP_RESULT_STRUCT;



#endif /* _MAVCAP_COMM_DEF_H_ */

