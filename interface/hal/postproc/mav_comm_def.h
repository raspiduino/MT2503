#ifndef _MAV_COMM_H_
#define _MAV_COMM_H_

#include "kal_release.h"
#include "lcd_sw_inc.h"
#include "feature_comm_def.h"

#define MAV_MAX_WIDTH						        (LCD_WIDTH)
#define MAV_MAX_HEIGHT						        (LCD_HEIGHT)

#define MAV_IMAGE_NUM						        (MAV_MAX_SUPPORT_IMAGE_NUM)                                

#define MAV_WORKING_BUFFER_SIZE				((((MAV_MAX_WIDTH*MAV_MAX_HEIGHT*12 + MAV_RECTIFY_GLOBAL_SIZE + MAV_FEATURE_GLOBAL_SIZE)+31)>>5)<<5)

#define GlobalToWorking
#ifdef GlobalToWorking
#define MAV_RECTIFY_GLOBAL_SIZE				(((10400+31)>>5)<<5)
//#define MAV_FEATURE_GLOBAL_SIZE				(((870880+31)>>5)<<5)
#define MAV_FEATURE_GLOBAL_SIZE				((((61608*MAV_IMAGE_NUM-53248)+31)>>5)<<5)
#else

#define MAV_RECTIFY_GLOBAL_SIZE				(0)
#define MAV_FEATURE_GLOBAL_SIZE				(0)

#endif

/*****************************************************************************
    Process Control 
******************************************************************************/
// MAVInit, 
// Input    : MavTuningInfo
// Output   : NONE
typedef struct tagMavTuningInfo
{
    // Extraction parameters
    kal_int32				RCWinBound;         // RC Window Bound to select points

    // Matching parameters
    kal_int32				SearchRange;        // Search Range to find the matching pair
    kal_int32				MatchRate;          // Error rate between minimum error and second minimum error

    // Rectification parameters
    kal_int32				RectErrThre;        // Pixel error threshold for self image rectification
    kal_int32				IterNum;            // Iteration number of LM method
    kal_int32				MaxAngle;           // Maximum angle for self image recitification

    // Alignment parameters
    kal_int32				ClipRatio;          // Image clip ratio after alignment (real value*256)
} MavTuningInfo;

// Jason PP
typedef struct
{
    kal_uint16      ProcImageNum;
    kal_int16      (*GlobalMotion)[2];
} MAV_PROC_PARA, *P_MAV_PROC_PARA;

typedef struct
{
    kal_int32				ClipX;              // Image Global Offset X
    kal_int32				ClipY;              // Image Global Offset Y
    float					AngleValueX;        // AngleValue
    float					AngleValueY;        // AngleValue
    float					AngleValueZ;        // AngleValue
} MavResultImage, *P_MavResultImage;

// Mav result for cb
typedef struct
{
    kal_int16               ClipWidth;          // Image Result Width
    kal_int16               ClipHeight;         // Image Result Height
    MavResultImage			Image[MAV_IMAGE_NUM];
    kal_uint32				PpImgBufAddr;		// source image address
} MAV_RESULT_STRUCT, *P_MAV_RESULT_STRUCT;


#endif	// _MAV_COMM_H_
