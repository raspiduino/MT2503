/** 
 *
 *	@file		IGV5Animation.h	
 *
 *  @brief		Header file for animation related definition
 *
 *	@author		Charles Shih-I Yeh
 *
*/

#ifndef __IGV5ANIMATION_H
#define __IGV5ANIMATION_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!***************************************************************************
@struct		IGV5FloatKeyFrameSequence
@brief		A structure for storing keyframe data
*****************************************************************************/
typedef struct {

	unsigned m_uNumKeyFrames;		/*!< total number of keyframes in this sequence */
	unsigned m_uStride;				/*!< stride (in bytes) between each keyframe */
	unsigned m_uNumComponents;		/*!< number of components in each keyframe. each component is independent and will be animated seperately */
	float *m_pfData;				/*!< pointer to keyframe data block */
} IGV5FloatKeyFrameSequence;

/*! @def	animation is stopped */
#define IGV5ANIM_STATUS_STOP 0x00000000
/*! @def	animation is playing */
#define IGV5ANIM_STATUS_PLAY 0x00000001

/*! @def	animation will stop and reset to default value. */
#define IGV5ANIM_FILL_STOP 0x00000001
/*! @def	animation will stop right at current value. */
#define IGV5ANIM_FILL_HOLDEND 0x00000002
/*! @def	animation will repeat forever. */
#define IGV5ANIM_REPEAT_FOREVER 0x00000000

/*!***************************************************************************
@struct		IGV5FloatAnimation
@brief		A structure for processing linearly interpolated animation
*****************************************************************************/
typedef struct {

	float *m_pAnimTarget;

	IGV5FloatKeyFrameSequence *m_pKeys;

	int m_uStatus;
	int m_bBounce;
	int m_uRepeatCount;
	int m_uFillBehavior;

	float m_fCurrentTime, m_fLastKeyTime, m_fNextKeyTime;
	unsigned m_uLastKeyIdx, m_uNextKeyIdx, m_uCurrentRepeat;

	float m_fLast[16];
	float m_fNext[16];

} IGV5FloatAnimation;

/*!***********************************************************************
 @fn		IGV5FloatAnimation_Start
 @param		pA		pointer to animation object
 @return	IGV5ANIM_STATUS_PLAY 
 @brief		start an animation
*************************************************************************/
int IGV5FloatAnimation_Start(IGV5FloatAnimation *pA);

/*!***********************************************************************
 @fn		IGV5FloatKeyFrameSequence_Setup
 @param		pA						pointer to animation object
 @param		uNumKeyFrames			number of key frame
 @return	IGV5ANIM_STATUS_PLAY	
 @brief		start an animation		
*************************************************************************/
IGV5Err IGV5FloatKeyFrameSequence_Setup(IGV5FloatKeyFrameSequence *pA, unsigned uNumKeyFrames, unsigned uComponents, unsigned uStride, float *pData);

/*!***********************************************************************
 @fn		IGV5FloatAnimation_Setup
 @param		pA						pointer to animation object
 @param		pTarget					
 @param		uNumKeyFrames			number of key frame
 @return	IGV5ANIM_STATUS_PLAY	
 @brief		start an animation		
*************************************************************************/
IGV5Err IGV5FloatAnimation_Setup(IGV5FloatAnimation *pA, float *pTarget, IGV5FloatKeyFrameSequence *pKeys, int bBounce, int uRepeatCount);

/*!***********************************************************************
 @fn		IGV5FloatAnimation_Reset
 @param		pA		pointer to animation object
 @return	IGV5ANIM_STATUS_PLAY 
 @brief		start an animation
*************************************************************************/
IGV5Err IGV5FloatAnimation_Reset(IGV5FloatAnimation *pA);

/*!***********************************************************************
 @fn		IGV5FloatAnimation_Animate
 @param		pA						pointer to animation object
 @param		fFrameTime				time interval					
 @return	return IGV5ANIM_STATUS_PLAY	when animation is playing; 
			return IGV5ANIM_STATUS_STOP when animation is about to stop
			return 
 @brief		start an animation		
*************************************************************************/
int IGV5FloatAnimation_Animate(IGV5FloatAnimation *pA, float fFrameTime);

#ifdef __cplusplus
}
#endif

#endif
