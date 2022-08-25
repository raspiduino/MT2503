/*****************************************************************************
 * Filename:
 * ---------
 * custom_vrender.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customer to change video renderer redraw mode and period
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "kal_release.h"
#include "custom_vrender.h"
#include "kal_non_specific_general_types.h"

static VRNDR_REDRAW_MODE _u4Renderer_Redraw_Mode = VDO_RNDR_REDRAW_FRM_PERIOD_AVOID;

VRNDR_REDRAW_MODE VdoRndrGetRedrawMode(kal_uint32* pu4FixedRedrawInterval)
{
  if(_u4Renderer_Redraw_Mode == VDO_RNDR_REDRAW_CUST_FIXED_INTERVAL)
  {
    *pu4FixedRedrawInterval = VA2_COMP_VR_DSPL_REDRAW_DURATION_MEDIUM;
  }
  else
  {
    *pu4FixedRedrawInterval = 0xFFFFFFFF;
  }
  return _u4Renderer_Redraw_Mode;
}

