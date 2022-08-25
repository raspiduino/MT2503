/*****************************************************************************
 *
 * Filename:
 * ---------
 *   iul_img_misc.h
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
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_IMG_MISC_H__
#define __IUL_IMG_MISC_H__

#include "fsal.h"

#define IUL_JPEG_ENCODE_PROCESS_BASELINE      1
#define IUL_JPEG_ENCODE_PROCESS_PROGRESSIVE   2
#define IUL_JPEG_ENCODE_PROCESS_UNRECOGNIZED  3

/**
 * Get the encode process of a JPEG image.
 *
 * @param file  STFSAL pointer to the JPEG image
 *
 * @retval IUL_JPEG_ENCODE_PROCESS_BASELINE     baseline
 * @retval IUL_JPEG_ENCODE_PROCESS_PROGRESSIVE  progressive
 * @retval IUL_JPEG_ENCODE_PROCESS_UNRECOGNIZED other unsupported encode process, such as lossless
 * @retval 0                                    file access error
 *
 * @remarks
 *    The file MUST be provided with a read buffer using the API FSAL_SetBuffer, 
 *    otherwise, an assertion will be invoked.
 */
int iul_img_get_jpeg_encode_process(STFSAL *file);

#endif /// __IUL_IMG_MISC_H__
