/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   rs_buffer.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   ring and sequential buffer API header
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
 
#ifndef __RS_BUFFER_H__
#define __RS_BUFFER_H__

/// This option is for WIN32/Armulator/FPGA/DVT standalone test
/// #define RS_BUFFER_STANDALONE


typedef enum {
   RSB_OP_SEQUENTIAL_BUFFER = 0,
   RSB_OP_RING_BUFFER
} RSB_OP_MODE_ENUM;


typedef enum {
   RSB_BIG_ENDIAN = 0,
   RSB_LITTLE_ENDIAN
} RSB_ENDIAN_ENUM;


typedef struct RS_BUFFER_T {
   char *head;
   char *tail;
   char *readPtr;
   char *writePtr;
   unsigned int size;
   unsigned int dataAvailable;

   RSB_ENDIAN_ENUM endian;
   RSB_OP_MODE_ENUM opMode;

} RS_BUFFER;


/**
 * Initialize the ring-sequential buffer control.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param buffer the storage for the buffer control.
 * @param size the number of bytes of the storage.
 * @param endian the endian of read/write data, should be either RSB_BIG_ENDIAN or RSB_LITTLE_ENDIAN.
 * @param opMode the operation mode, should be either RSB_OP_SEQUENTIAL_BUFFER or RSB_OP_RING_BUFFER.
 *
 * @remarks Call this function to initialize the ring-sequential buffer control.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbInit(RS_BUFFER *rsb, void *buffer, unsigned int size, RSB_ENDIAN_ENUM endian, RSB_OP_MODE_ENUM opMode);



/**
 * Purge the buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to purge the buffer.
 * Both the read/write pointers are reset.
 *
 * @return Always return 1.
 */
int rsbPurge(RS_BUFFER *rsb);


/**
 * Read data from buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the data read.
 * @param count the number of bytes to read from buffer.
 *
 * @remarks Call this function to read data from buffer.
 *
 * @return Return the actual data count read from buffer.
 */
int rsbReadBytes(RS_BUFFER *rsb, void *dst, unsigned int count);


/**
 * Read an UINT8 value from buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the read value.
 *
 * @remarks Call this function to read an UINT8 value from buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbReadUint8(RS_BUFFER *rsb, unsigned char *dst);


/**
 * Read an UINT16 value from buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the read value.
 *
 * @remarks Call this function to read an UINT16 value from buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbReadUint16(RS_BUFFER *rsb, unsigned short *dst);


/**
 * Read an UINT24 value from buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the read value.
 *
 * @remarks Call this function to read an UINT24 value from buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbReadUint24(RS_BUFFER *rsb, unsigned int *dst);


/**
 * Read an UINT32 value from buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the read value.
 *
 * @remarks Call this function to read an UINT32 value from buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbReadUint32(RS_BUFFER *rsb, unsigned int *dst);


/**
 * Peek data from buffer without changing any state of buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the data peeked.
 * @param count the number of bytes to peek from buffer.
 *
 * @remarks Call this function to peek data from buffer without changing any state of buffer.
 *
 * @return Return the actual data count peeked from buffer.
 */
int rsbPeekBytes(RS_BUFFER *rsb, void *dst, unsigned int count);


/**
 * Peek an UINT8 value from buffer without changing any state of buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the peeked value.
 *
 * @remarks Call this function to peek an UINT8 value from buffer without changing any state of buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbPeekUint8(RS_BUFFER *rsb, unsigned char *dst);


/**
 * Peek an UINT16 value from buffer without changing any state of buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the peeked value.
 *
 * @remarks Call this function to peek an UINT16 value from buffer without changing any state of buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbPeekUint16(RS_BUFFER *rsb, unsigned short *dst);


/**
 * Peek an UINT24 value from buffer without changing any state of buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the peeked value.
 *
 * @remarks Call this function to peek an UINT24 value from buffer without changing any state of buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbPeekUint24(RS_BUFFER *rsb, unsigned int *dst);


/**
 * Peek an UINT32 value from buffer without changing any state of buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param dst pointer to buffer to store the peeked value.
 *
 * @remarks Call this function to peek an UINT32 value from buffer without changing any state of buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbPeekUint32(RS_BUFFER *rsb, unsigned int *dst);



/**
 * Write data into buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param src pointer to data to write into buffer.
 * @param count the number of bytes to write into buffer.
 *
 * @remarks Call this function to write data into buffer.
 *
 * @return Return the actual data count written into buffer.
 */
int rsbWriteBytes(RS_BUFFER *rsb, void *src, unsigned int count);


/**
 * Write an UINT8 value into buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param src the value to write into buffer.
 *
 * @remarks Call this function to write an UINT8 value into buffer.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbWriteUint8(RS_BUFFER *rsb, unsigned char src);


/**
 * Write an UINT16 value into buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param src the value to write into buffer.
 *
 * @remarks Call this function to write an UINT16 value into buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbWriteUint16(RS_BUFFER *rsb, unsigned short src);


/**
 * Write an UINT24 value into buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param src the value to write into buffer.
 *
 * @remarks Call this function to write an UINT24 value into buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbWriteUint24(RS_BUFFER *rsb, unsigned int src);


/**
 * Write a UINT32 value into buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param src the value to write into buffer.
 *
 * @remarks Call this function to write a UINT32 value into buffer.
 * The endian of data depends on the setting when the buffer control is initialized.
 *
 * @return Return 1 if succeeded, return 0 if failed.
 */
int rsbWriteUint32(RS_BUFFER *rsb, unsigned int src);


/**
 * Get the available data in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the available data in buffer.
 *
 * @return Return the available data in buffer.
 */
int rsbGetDataAvailable(RS_BUFFER *rsb);


/**
 * Get the sequential data count available from the read pointer in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the sequential data count available from the read pointer in buffer.
 * For example: DDD---DDDDD
 * rsbGetDataAvailable returns 8.
 * rsbGetFirstDataAvailable returns 5.
 * rsbGetSecondDataAvailable returns 3.
 *
 * @return Return the sequential data count available from the read pointer in buffer.
 */
int rsbGetFirstDataAvailable(RS_BUFFER *rsb);


/**
 * Get the sequential data count available from the head pointer in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the sequential data count available from the head pointer in buffer.
 * For example: DDD---DDDDD
 * rsbGetDataAvailable returns 8.
 * rsbGetFirstDataAvailable returns 5.
 * rsbGetSecondDataAvailable returns 3.
 *
 * @return Return the sequential data count available from the head pointer in buffer.
 */
int rsbGetSecondDataAvailable(RS_BUFFER *rsb);


/**
 * Get the available space in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the available space in buffer.
 *
 * @return Return the available space in buffer.
 */
int rsbGetSpaceAvailable(RS_BUFFER *rsb);


/**
 * Get the sequential space count available from the write pointer in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the sequential space count available from the write pointer in buffer.
 * For example: ---DDD-----
 * rsbGetSpaceAvailable returns 8.
 * rsbGetFirstSpaceAvailable returns 5.
 * rsbGetSecondSpaceAvailable returns 3.
 *
 * @return Return the sequential space count available from the write pointer in buffer.
 */
int rsbGetFirstSpaceAvailable(RS_BUFFER *rsb);


/**
 * Get the sequential space count available from the head pointer in buffer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 *
 * @remarks Call this function to the sequential space count available from the head pointer in buffer.
 * For example: ---DDD-----
 * rsbGetSpaceAvailable returns 8.
 * rsbGetFirstSpaceAvailable returns 5.
 * rsbGetSecondSpaceAvailable returns 3.
 *
 * @return Return the sequential space count available from the head pointer in buffer.
 */
int rsbGetSecondSpaceAvailable(RS_BUFFER *rsb);


/**
 * Call this function to get the current read pointer and the sequential data count.
 * available from the read pointer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param readPtr return the current read pointer.
 *
 * @remarks Call this function to get the current read pointer and the sequential data count
 * available from the read pointer.
 *
 * @return Return the sequential read count available from the read pointer.
 */
int rsbGetReadPointer(RS_BUFFER *rsb, void **readPtr);


/**
 * Call this function to get the current write pointer and the sequential space count.
 * available from the write pointer.
 *
 * @param rsb pointer to ring-sequential buffer control.
 * @param writePtr return the current write pointer.
 *
 * @remarks Call this function to get the current write pointer and the sequential space count
 * available from the write pointer.
 *
 * @return Return the sequential space count available from the read pointer.
 */
int rsbGetWritePointer(RS_BUFFER *rsb, void **writePtr);


/**
 * Call this function to move backward or forward the read pointer.
 *
 * @param rsb Pointer to ring-sequential buffer control.
 * @param offset The offset value the read pointer to be moved.
 *
 * @remarks The offset can be either positive or negative.
 * If the offset is positive, the read pointer is to be moved backward.
 * Namely, the available data count left in buffer will be decreased.
 * If the offset is negative, the read pointer is to be moved forward.
 * Namely, the read available data count left in buffer will be increased.
 *
 * @return Return the actual offset value the read buffer is moved.
 * Notice that the return value may be not equal to the parameter offset.
 */
int rsbAdjustReadPointer(RS_BUFFER *rsb, int offset);


/**
 * Call this function to move backward or forward the write pointer.
 *
 * @param rsb Pointer to ring-sequential buffer control.
 * @param offset The offset value the write pointer to be moved.
 *
 * @remarks The offset can be either positive or negative.
 * If the offset is positive, the write pointer is to be moved backward.
 * Namely, the available data count left in buffer will be increased.
 * If the offset is negative, the write pointer is to be moved forward.
 * Namely, the read available data count left in buffer will be decreased.
 *
 * @return Return the actual offset value the write buffer is moved.
 * Notice that the return value may be not equal to the parameter offset.
 */
int rsbAdjustWritePointer(RS_BUFFER *rsb, int offset);


/**
 * Call this function to move all current data to the head of sequential buffer.
 *
 * @param rsb Pointer to ring-sequential buffer control.
 *
 * @remarks The function is valid only under sequential buffer mode.
 * Read pointer would be adjusted to the head of buffer.
 * Write pointer would be adjusted after n bytes from the head of buffer where n is the actual count of data being moved.
 *
 * @return Return the actual count of the data being moved (in byte).
 */
int rsbRearrangeBuffer(RS_BUFFER *rsb);


/**
 * Call this function to get the buffer size of ring-sequential buffer.
 *
 * @param rsb Pointer to ring-sequential buffer control.
 *
 * @return Return the buffer size of ring-sequential buffer (in byte).
 */
int rsbGetBufferSize(RS_BUFFER *rsb);

#endif

