/*****************************************************************************
 *
 * Filename:
 * ---------
 *   iul_misc.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: miscellaneous APIs
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 24 2011 rey.su
 * removed!
 * Remove the include of kal_release.h and kal_non_specific_general_types.h.
 *
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 * 10 18 2010 rey.su
 * removed!
 * Rey: RHR "add" stage.
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/// Deprecation Notice: 2010.10.20
/// This file will be deprecated on 11A and later SW branches.
/// Users must use new APIs after W1112.

#ifndef __IUL_MISC_H__
#define __IUL_MISC_H__

#include "iul_img_misc.h"
#include "kal_general_types.h"

/**
 * Get the encode process of a JPEG image.
 *
 * @param file  STFSAL pointer to the JPEG image
 *
 * @return
 *    IUL_JPEG_ENCODE_PROCESS_BASELINE: baseline
 *    IUL_JPEG_ENCODE_PROCESS_PROGRESSIVE: progressive
 *    IUL_JPEG_ENCODE_PROCESS_UNRECOGNIZED: other unsupported encode process, such as lossless
 *    0: file access error
 *
 * @remarks
 *    The file MUST be provided with a read buffer using the API FSAL_SetBuffer, 
 *    otherwise, an assertion will be invoked.
 *
 * @date 2008.07.18
 */
kal_uint32 iul_get_jpeg_encode_process(STFSAL *file);

#endif /// __IUL_MISC_H__
