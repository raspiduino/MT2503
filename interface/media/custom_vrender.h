/*****************************************************************************
 * Filename:
 * ---------
 * custom_vrender.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customizable video renderer parameter header.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#include "kal_release.h"
#include "kal_non_specific_general_types.h"

typedef enum
{
  VDO_RNDR_REDRAW_DISABLE = 0,
  VDO_RNDR_REDRAW_FRM_PERIOD_AVOID,
  VDO_RNDR_REDRAW_CUST_FIXED_INTERVAL
} VRNDR_REDRAW_MODE;

#define VA2_COMP_VR_DSPL_REDRAW_DURATION_LONG         (140)//ms
#define VA2_COMP_VR_DSPL_REDRAW_DURATION_MEDIUM       (110)//ms
#define VA2_COMP_VR_DSPL_REDRAW_DURATION_SHORT        (80) //ms

extern VRNDR_REDRAW_MODE VdoRndrGetRedrawMode(kal_uint32* pu4FixedRedrawInterval);

