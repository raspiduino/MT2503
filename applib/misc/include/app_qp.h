/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * app_qp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains Quote Printable (QP) decode / encode 
 *   function prototypes.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP_QP_H
#define _APP_QP_H /* APPLIB QP Header */

#include "kal_general_types.h"

/* encode option mask */

/* Encoding option. Indicate to encode the "\r\n" into "=0D=0A" */
#define QPOPT_ENCODE_CRLF                 (1 << 0) 

/* Encoding option. Indicate to encode the SPACE(0x20) into underline(_) see rfc2047 4.2 */
#define QPOPT_ENCODE_AUTO_LINEWRAP        (1 << 1) 

/* Encoding option. Indicate to add line break when reaches one line count reaches 76 characters. that is the output encoded data are less than 77 characters. */
#define QPOPT_ENCODE_SPACE_TO_UNDERLINE   (1 << 2) 

/* decode option mask */

/* Decoding option. Decode underline character(_) into SPACE(0x20), it is the corresponding option of encoding option QPOPT_ENCODE_SPACE_TO_UNDERLINE. */
#define QPOPT_DECODE_UNDERLINE_TO_SPACE   (1 << 3) 

/* Decoding option. Skip leading SPACE after soft-line-break */
#define QPOPT_DECODE_SKIP_LEADING_SPACE   (1 << 4) 

/* 
 * Strem-style encode/decode context,
 * To implement the STREAM-STYLE encoding/decoding process, 
 * one context data structure is defined to remember some information. 
 * But this context data is used only internally.
 */
typedef struct
{
    /* private data */
    kal_uint8  opt; /* private data, All the fileds in this structure are absolutely private data, which only will be accessed by QP lib inside. So no detail information about them be here. */  
    kal_uint8  line_cnt;/* private data */ 
    kal_char   state;/* private data */ 
    kal_char   state2;/* private data */ 
    kal_char   remain;/* private data */ 
    kal_char   illege;/* private data */ 
}applib_qprint_context;

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode_basic
 * DESCRIPTION
 *  This function encodes a single piece of data into Quote-Printable format. 
 * PARAMETERS
 *  src   :      [IN]        Point to the source content buffer to be encoded.
 *  srcl  :      [IN]        Number of the size of source content buffer to be encoded.
 *  dst  :      [IN/OUT]    Point to the output buffer of encoded content.
 *                          If the parameter is NULL, the return value will be the needed output buffer size. 
 *  dstl :      [IN]        Number of the size of output buffer of encoded content.
 *                          If the [dst] parameter is NULL, this parameter will be ignored.
 *  opt   :      [IN]        The option mask for encoding. see QPOPT_ENCODE_XXX option define.
 * RETURN VALUES
 *  >=0 : If the function succeeds, and [dst] is NOT NULL, the return value is the number of bytes written to the buffer pointed by dst.
 *        If the function succeeds, and [dst] is NULL, the return value is the number of needed output buffer size. Note that the returned value is not accurate, it may larger than the indeed decoded size.
 *  -1 : If the function fails, the return value is -1.It indicates that the given output buffer size is not enough, which should be avoid.
 *****************************************************************************/
extern kal_int32 applib_qprint_encode_basic(
                    const kal_char *src,
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl,
                    kal_uint8 opt);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_decode_basic
 * DESCRIPTION
 *  This function is used to decode quoted printable string.
 * PARAMETERS
 *  src    :     [IN]        Point to the source content buffer to be decoded.
 *  srcl   :     [IN]        Number of the size of source content buffer to be decoded.
 *  dst    :     [IN/OUT]    Point to the output buffer of decoded content.
 *                          If the parameter is NULL, the return value will be the needed output buffer size. 
 *                          Note that the returned value is not accurate; it may be larger than the indeed decoded size. 
 *  dstl  :     [IN]        Number of the size of output buffer of encoded content.
 *                          If the [dst] parameter is NULL, this parameter will be ignored.
 *  opt    :     [IN]        The option mask for decoding. see QPOPT_DECODE_XXX option define.
 * RETURN VALUES
 *  >=0 : If the function succeeds, and [dst] is NOT NULL, the return value is the number of bytes written to the buffer pointed by dst.
 *        If the function succeeds, and [dst] is NULL, the return value is the number of needed output buffer size.  Note that the returned value is not accurate, it may be larger than the indeed decoded size.
 *  -1 : If the function fails, the return value is -1.
 *                 It indicates that the given output buffer size is not enough, which should be avoid.
 *****************************************************************************/
extern kal_int32 applib_qprint_decode_basic(
                    const kal_char *src,
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl,
                    kal_uint8 opt);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part quote-printable 
 *  encode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx          :  [IN]        Point to the applib_qprint_context.
 *  max_part_size :  [IN]        The number of MAX input buffer size per-part.
 *  opt           :  [IN]        The option mask for encoding. QPOPT_ENCODE_XXX option define.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the MIN output buffer size needed for the per-parts process.
 *  -1 : If the cntx is NULL, the return value is -1. 
 *****************************************************************************/
extern kal_int32 applib_qprint_part_encode_init(
                    applib_qprint_context *cntx,
                    kal_int32 max_part_size,
                    kal_uint8 opt);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_append
 * DESCRIPTION
 *  This function accepts next part of source data; 
 *  encode them to Quote-Printable format
 * PARAMETERS
 *  cntx  :      [IN]        Point to the applib_qprint_context.
 *  src   :      [IN]        Point to the source content buffer to be encoded.
 *  srcl  :      [IN]        Number of the size of source content buffer to be encoded.
 *  dst  :      [IN/OUT]    Point to the output buffer of encoded content. 
 *                           Note that the output buffer MUST NOT overlapped with the input buffer.
 *  dstl :      [IN]        Number of the size of output buffer of encoded content.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to output buffer, and the [*srcl] indicates how many input buffer was processed.
 *        Note that, if the output buffer size is NOT LESS THAN the return value of the applib_qp_part_encode_init function, and the input size buffer is NOT LARGER THAN the [max_part_buf_size] value, the OUT [*srcl] value is always equal to the IN [*src] value, in this case you can ignore the OUT [*srcl] value safely.
 *  -1 : If the function failed, the return value is -1, it means the cntx is NULL or it was modified outsides.
 *****************************************************************************/
extern kal_int32 applib_qprint_part_encode_append(
                    applib_qprint_context *cntx,
                    const kal_char *src,
                    kal_int32 *srcl,
                    kal_char *dst,
                    kal_int32 dstl);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_finish
 * DESCRIPTION
 *  This function finishes the part-by-part encoding process; 
 *  encode the last bytes into Quote-Printable format if there are.
 * PARAMETERS
 *  cntx    :    [IN]        Point to the applib_qprint_context.
 *  dst    :    [IN/OUT]    Point to the output buffer of decoded content.
 *  dstl   :    [IN]        Number of the size of output buffer of encoded content. It must be larger than 9.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to output buffer.
 *  -1 : If the function failed, the return value is -1 it means the context data was NULL or be changed outsides or the output buffer size is too small.
 *****************************************************************************/
extern kal_int32 applib_qprint_part_encode_finish(
                    applib_qprint_context *cntx,
                    kal_char *dst,
                    kal_int32 dstl);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part quote-printable 
 *  decode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx          :  [IN]        Point to the applib_qprint_context.
 *  max_part_size :  [IN]        The number of MAX input buffer size per-part.
 *  opt           :  [IN]        The option mask for decoding, see QPOPT_DECODE_XXX option define.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the MIN output buffer size needed for the per-parts process.
 *  -1 : If the cntx is NULL, the return value is -1. 
 *****************************************************************************/
extern kal_int32 applib_qprint_part_decode_init(
                    applib_qprint_context *cntx,
                    kal_int32 max_part_size,
                    kal_uint8 opt);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_append
 * DESCRIPTION
 *  This function accepts next part of source data; 
 *  decode them from Quote-Printable format
 * PARAMETERS
 *  cntx   :     [IN]        Point to the applib_qprint_context.
 *  src    :     [IN]        Point to the source content buffer to be decoded. 
 *  srcl   :     [IN]        Point to the number of the size of source content buffer to de encoded. 
 *  dst   :     [IN/OUT]    Point to the output buffer of decoded content. Note that: the output buffer MUST NOT overlapped with the input buffer.
 *  dstl  :     [IN]        Number of the size of output buffer.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to output buffer. 
 *                 And the [*srcl] indicates how many input buffer was processed. 
 *                 Note that if the output buffer size is NOT LESS THAN the return value of the applib_qp_part_decode_init function, and the input size buffer is NOT LARGER THAN the [max_part_buf_size] value, the OUT [*srcl] value is always equal to the IN [*src] value
 *  -1 : If the function failed, the return value is -1 it means the context data was NULL or be changed outsides.
 *****************************************************************************/
extern kal_int32 applib_qprint_part_decode_append(
                    applib_qprint_context *cntx,
                    const kal_char *src,
                    kal_int32 *srcl,
                    kal_char *dst,
                    kal_int32 dstl);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_finish
 * DESCRIPTION
 *  This function finishes the part-by-part decoding process.
 * PARAMETERS
 *  cntx        :    [IN]        Point to the applib_qprint_context
 *  illegal_format : [IN/OUT]    Point to the illegal format flag, if you can ignore this safely, you can set it as NULL.
 * RETURN VALUES
 *  0 : If the function succeeds, the return value is 0. If illegal character or invalid pad character was found during the process, and the [illegal_format] is NOT NULL, the [illegal_format] will be set as TRUE.
 *  -1 : If the function failed, the return value is -1 it means the context data was NULL or be changed outsides.
 *****************************************************************************/
extern kal_int32 applib_qprint_part_decode_finish(
                    applib_qprint_context *cntx,
                    kal_bool *illegal_format);


/* DOM-NOT_FOR_SDK-BEGIN */
/* 
 * NOTE:
 * the APIs below will be obsoleted
 * them are here only for compatible with old code 
 */

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_decode_basic
 * DESCRIPTION
 *  This function is used to decode quoted printable string.
 *  Note: This function will be obsolete. The applib_ qprint _decode_basic function should be used instead.
 * PARAMETERS
 *  src   :      [IN]        pointer to the buffer containing encoded data
 *  srcl  :      [IN]        length of the encoded data
 *  dest  :      [IN/OUT]    pointer to the destination buffer
 *  destl :      [IN]        length of destination buffer
 *  opt   :      [IN]        decode option
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to the buffer pointed by dst. Not include the null terminator.
 *  -1 : If the function fails, the return value is -1.It indicates that the given output buffer size is not enough.
 *****************************************************************************/
extern kal_int32 applib_qprint_decode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl);

/*****************************************************************************
 * FUNCTION
 *  applib_find_qprint_boundary
 * DESCRIPTION
 *  This function finds the boundary in the qprint encoded text.
 * PARAMETERS
 *  ptr  :   [IN]        Point to content which are qprint encoded.
 *  len  :   [IN]        The input content size in bytes.
 * RETURNS
 *  number of bytes shall be skipped.
 *****************************************************************************/
extern kal_uint16 applib_find_qprint_boundary(kal_char *ptr, kal_int32 len);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode
 * DESCRIPTION
 *  This function is used to encode given string into QP encoded string.
 * PARAMETERS
 *  src      :       [IN]            Point to the source content buffer to be encoded.
 *  srcl     :       [IN]            Number of the size of source content buffer to be encoded.
 *  dest     :       [IN/OUT]        Point to the output buffer of encoded content.
 *  destl    :       [IN]            Number of the size of output buffer of encoded content.
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to the buffer pointed by dst. not include null character
 *  -1 : If the function fails, the return value is -1.It indicates that the given output buffer size is not enough.
 *****************************************************************************/
extern kal_int32 applib_qprint_encode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl);

/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode_ext
 * DESCRIPTION
 *  This function is used to encode given string into QP encoded string.
 * PARAMETERS
 *  src     :        [IN]            Point to the source content buffer to be encoded.
 *  srcl    :        [IN]            Number of the size of source content buffer to be encoded.
 *  dest    :        [IN/OUT]        Point to the output buffer of encoded content.
 *  destl   :        [IN]            Number of the size of output buffer of encoded content.
 *  encode_crlf  :   [IN]            TRUE:  "\r\n" ==> "=0D=0A", FALSE: "\r\n" ==> "\r\n"
 * RETURN VALUES
 *  >=0 : If the function succeeds, the return value is the number of bytes written to the buffer pointed by dst. not include null character
 *  -1 : If the function fails, the return value is -1.It indicates that the given output buffer size is not enough.
 *****************************************************************************/
extern
    kal_int32 applib_qprint_encode_ext(
                kal_char *src,
                kal_uint32 srcl,
                kal_char *dest,
                kal_uint32 destl,
                kal_bool encode_crlf);
/* DOM-NOT_FOR_SDK-END */

#endif /* _APP_QP_H */ 

