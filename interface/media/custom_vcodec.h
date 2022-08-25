/*****************************************************************************
 * Filename:
 * ---------
 * custom_vcodec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customize vcodec parameters.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

typedef enum
{
    VCODEC_QUALITY_IDX_FINE,
    VCODEC_QUALITY_IDX_GOOD,
    VCODEC_QUALITY_IDX_NORMAL,
    VCODEC_QUALITY_IDX_LOW
}VCODEC_QUALITY_IDX;

typedef enum
{
    VCODEC_QUALITY_LEVEL_1,   // from high to low
    VCODEC_QUALITY_LEVEL_2,
    VCODEC_QUALITY_LEVEL_3,
    VCODEC_QUALITY_LEVEL_4
}VCODEC_QUALITY_LEVEL;

typedef enum
{
    VCODEC_PERFORMANCE_LEVEL_1,  // from high to low
    VCODEC_PERFORMANCE_LEVEL_2,
    VCODEC_PERFORMANCE_LEVEL_3,
    VCODEC_PERFORMANCE_LEVEL_4,
    VCODEC_PERFORMANCE_LEVEL_5,
    VCODEC_PERFORMANCE_LEVEL_6
}VCODEC_PERFORMANCE_LEVEL;

typedef enum
{
    VCODEC_RESIZE_DEFAULT,
    VCODEC_RESIZE_BEST,
    VCODEC_RESIZE_GOOD,
    VCODEC_RESIZE_NORMAL
}VCODEC_RESIZE_METHOD;

typedef struct
{
    kal_uint32 frame_threshold[2];  // from low to high
    kal_uint32 buffer_threshold[2];  // from high to low
    VCODEC_PERFORMANCE_LEVEL performance_level[3];
    VCODEC_QUALITY_LEVEL quality_level;
}VCODEC_QUALITY_PARAM;

extern VCODEC_QUALITY_IDX vcodec_get_quality_index(kal_uint32 width, kal_uint32 height, kal_uint32 frame_rat, kal_uint32 bitrate, kal_uint32 custom_param);   
extern void vcodec_get_quality_param(VCODEC_QUALITY_IDX quality_idx, VCODEC_QUALITY_PARAM *p_param);
extern VCODEC_RESIZE_METHOD vcodec_get_resize_method(kal_uint32 width, kal_uint32 height, kal_uint32 frame_rate, kal_uint32 bitrate, kal_bool isMPEG4);

#define VCODEC_QVGA_WIDTH 320
#define VCODEC_QVGA_HEIGHT 240
#define VCODEC_30_FPS 30

extern kal_uint32 vcodec_get_reserve_time_to_mdp(kal_uint32 width, kal_uint32 height, kal_uint32 framerate, kal_uint32 bitrate);
