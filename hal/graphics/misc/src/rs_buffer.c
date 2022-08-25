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
 *   rs_buffer.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   ring and sequential buffer API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "rs_buffer.h"
#include "kal_general_types.h"
#include "string.h"

#if defined(RS_BUFFER_STANDALONE) || !defined(__MTK_TARGET__)
   #ifdef WIN32
      #ifndef ASSERT
         #include "assert.h"
         #define ASSERT assert
      #endif
   #else
      #ifndef ASSERT
         #define ASSERT(I) while(!(I)) {};
      #endif
   #endif
#else
   #include "kal_public_api.h"
#endif



int rsbInit(RS_BUFFER *rsb, void *buffer, unsigned int size, RSB_ENDIAN_ENUM endian, RSB_OP_MODE_ENUM opMode)
{
   ASSERT(rsb);

   if (!buffer || !size) {
      return 0;
   }

   rsb->head = (char *)buffer;
   rsb->readPtr = (char *)buffer;
   rsb->writePtr = (char *)buffer;
   rsb->tail = rsb->head + size - 1;
   rsb->size = size;
   rsb->dataAvailable = 0;
   rsb->endian = endian;
   rsb->opMode = opMode;

   return 1;
}



int rsbPurge(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   rsb->readPtr = rsb->head;
   rsb->writePtr = rsb->head;
   rsb->dataAvailable = 0;

   return 1;
}



int rsbReadBytes(RS_BUFFER *rsb, void *dst, unsigned int count)
{
   const int dataAvailable1 = rsbGetFirstDataAvailable(rsb);

   ASSERT(rsb);

   if (dataAvailable1 >= (int)count) {
      memcpy(dst, rsb->readPtr, count);
      
      rsb->dataAvailable -= count;
      if (rsb->dataAvailable) {
         /// there's data left in buffer
         rsb->readPtr += count;
         if (rsb->readPtr > rsb->tail) {
            rsb->readPtr = rsb->head;
         }
      } else {
         /// in this case, the buffer is empty, call rsbFlush
         rsbPurge(rsb);
      }

      return count;

   } else {
      const int dataAvailable2 = rsbGetSecondDataAvailable(rsb);

      if (dataAvailable2) {
         if ((dataAvailable1 + dataAvailable2) >= (int)count) {
            memcpy(dst, rsb->readPtr, dataAvailable1);
            memcpy((char *)dst + dataAvailable1, rsb->head, (count - dataAvailable1));
            rsb->readPtr = rsb->head + (count - dataAvailable1);
            rsb->dataAvailable -= count;
            return count;
         } else {
            memcpy(dst, rsb->readPtr, dataAvailable1);
            memcpy((char *)dst + dataAvailable1, rsb->head, dataAvailable2);
            /// in this case, the buffer is empty, call rsbFlush
            rsbPurge(rsb);
            return (dataAvailable1 + dataAvailable2);
         }
      } else {
         memcpy(dst, rsb->readPtr, dataAvailable1);
         /// in this case, the buffer is empty, call rsbFlush
         rsbPurge(rsb);
         return dataAvailable1;
      }
   }
}



int rsbReadUint8(RS_BUFFER *rsb, unsigned char *dst)
{
   ASSERT(rsb);

   if (0 == rsb->dataAvailable) {
      return 0;
   } else {
      rsbReadBytes(rsb, dst, 1);

      return 1;
   }
}



int rsbReadUint16(RS_BUFFER *rsb, unsigned short *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (2 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[2];
      
      rsbReadBytes(rsb, data, 2);
      *dst = (data[0] << 8) | data[1];
   } else {
      rsbReadBytes(rsb, dst, 2);
   }

   return 1;
}



int rsbReadUint24(RS_BUFFER *rsb, unsigned int *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (3 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[3];
      
      rsbReadBytes(rsb, data, 3);
      *dst = (data[0] << 16) | (data[1] << 8) | data[2];
   } else {
      rsbReadBytes(rsb, dst, 3);
   }

   return 1;
}



int rsbReadUint32(RS_BUFFER *rsb, unsigned int *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (4 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[4];
      
      rsbReadBytes(rsb, data, 4);
      *dst = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
   } else {
      rsbReadBytes(rsb, dst, 4);
   }

   return 1;
}



int rsbPeekBytes(RS_BUFFER *rsb, void *dst, unsigned int count)
{
   const int dataAvailable1 = rsbGetFirstDataAvailable(rsb);

   ASSERT(rsb);

   if (dataAvailable1 >= (int)count) {
      memcpy(dst, rsb->readPtr, count);
      return count;
   } else {
      const int dataAvailable2 = rsbGetSecondDataAvailable(rsb);

      if (dataAvailable2) {
         if ((dataAvailable1 + dataAvailable2) >= (int)count) {
            memcpy(dst, rsb->readPtr, dataAvailable1);
            memcpy((char *)dst + dataAvailable1, rsb->head, (count - dataAvailable1));
            return count;
         } else {
            memcpy(dst, rsb->readPtr, dataAvailable1);
            memcpy((char *)dst + dataAvailable1, rsb->head, dataAvailable2);
            return (dataAvailable1 + dataAvailable2);
         }
      } else {
         memcpy(dst, rsb->readPtr, dataAvailable1);
         return dataAvailable1;
      }
   }
}



int rsbPeekUint8(RS_BUFFER *rsb, unsigned char *dst)
{
   ASSERT(rsb);

   if (0 == rsb->dataAvailable) {
      return 0;
   } else {
      *(char *)dst = *rsb->readPtr;
      return 1;
   }
}



int rsbPeekUint16(RS_BUFFER *rsb, unsigned short *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (2 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[2];
      
      rsbPeekBytes(rsb, data, 2);
      *dst = (data[0] << 8) | data[1];
   } else {
      rsbPeekBytes(rsb, dst, 2);
   }

   return 1;
}



int rsbPeekUint24(RS_BUFFER *rsb, unsigned int *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (3 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[3];
      
      rsbPeekBytes(rsb, data, 3);
      *dst = (data[0] << 16) | (data[1] << 8) | data[2];
   } else {
      rsbPeekBytes(rsb, dst, 3);
   }

   return 1;
}



int rsbPeekUint32(RS_BUFFER *rsb, unsigned int *dst)
{
   ASSERT(rsb);
   ASSERT(dst);

   if (4 > rsbGetDataAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      unsigned char data[4];
      
      rsbPeekBytes(rsb, data, 4);
      *dst = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
   } else {
      rsbPeekBytes(rsb, dst, 4);
   }

   return 1;
}



int rsbWriteBytes(RS_BUFFER *rsb, void *src, unsigned int count)
{
   const int spaceAvailable1 = rsbGetFirstSpaceAvailable(rsb);

   ASSERT(rsb);

   if (spaceAvailable1 >= (int)count) {
      memcpy(rsb->writePtr, src, count);
      rsb->writePtr += count;
      rsb->dataAvailable += count;

      if (rsb->writePtr > rsb->tail) {
         rsb->writePtr = rsb->head;
      }
      return count;

   } else {
      int spaceAvailable2;

      if (RSB_OP_RING_BUFFER == rsb->opMode) {
         spaceAvailable2 = rsbGetSecondSpaceAvailable(rsb);
      } else {
         spaceAvailable2 = 0;
      }

      if (spaceAvailable2) {
         if ((spaceAvailable1 + spaceAvailable2) >= (int)count) {
            memcpy(rsb->writePtr, src, spaceAvailable1);
            memcpy(rsb->head, (char *)src + spaceAvailable1, (count - spaceAvailable1));
            rsb->writePtr = rsb->head + (count - spaceAvailable1);
            rsb->dataAvailable += count;
            return count;
         } else {
            memcpy(rsb->writePtr, src, spaceAvailable1);
            memcpy(rsb->head, (char *)src + spaceAvailable1, spaceAvailable2);
            /// in this case, the buffer is full
            rsb->writePtr = rsb->readPtr;
            rsb->dataAvailable = rsb->size;
            return (spaceAvailable1 + spaceAvailable2);
         }
      } else {
         memcpy(rsb->writePtr, src, spaceAvailable1);
         /// in this case, the buffer is full   
         if (RSB_OP_RING_BUFFER == rsb->opMode) {
            rsb->writePtr = rsb->readPtr;
            rsb->dataAvailable = rsb->size;
         } else {
            rsb->writePtr = rsb->head;
            rsb->dataAvailable += spaceAvailable1;
         }
         return spaceAvailable1;
      }
   }
}



int rsbWriteUint8(RS_BUFFER *rsb, unsigned char src)
{
   ASSERT(rsb);

   if (0 == rsbGetSpaceAvailable(rsb)) {
      return 0;
   } else {
      const unsigned char val = src;
      
      rsbWriteBytes(rsb, (void *)&val, 1);

      return 1;
   }
}



int rsbWriteUint16(RS_BUFFER *rsb, unsigned short src)
{
   ASSERT(rsb);

   if (2 > rsbGetSpaceAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      const unsigned short val = ((src & 0xFF) << 8) | ((src & 0xFF00) >> 8);

      rsbWriteBytes(rsb, (void *)&val, 2);
   } else {
      const unsigned short val = src;
      
      rsbWriteBytes(rsb, (void *)&val, 2);
   }
   return 1;
}



int rsbWriteUint24(RS_BUFFER *rsb, unsigned int src)
{
   ASSERT(rsb);

   if (3 > rsbGetSpaceAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      const unsigned int val = ((src & 0xFF) << 16) | (src & 0x00FF00) | ((src & 0xFF0000) >> 16);

      rsbWriteBytes(rsb, (void *)&val, 3);
   } else {
      const unsigned int val = src;
      
      rsbWriteBytes(rsb, (void *)&val, 3);
   }
   return 1;
}



int rsbWriteUint32(RS_BUFFER *rsb, unsigned int src)
{
   ASSERT(rsb);

   if (4 > rsbGetSpaceAvailable(rsb)) {
      return 0;
   }

   if (RSB_BIG_ENDIAN == rsb->endian) {
      const unsigned int val = ((src & 0xFF) << 24) | ((src & 0xFF00) << 8) | 
                               ((src & 0xFF0000) >> 8) | ((src & 0xFF000000) >> 24);

      rsbWriteBytes(rsb, (void *)&val, 4);
   } else {
      const unsigned int val = src;
      
      rsbWriteBytes(rsb, (void *)&val, 4);
   }
   return 1;
}



int rsbGetDataAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   return (int)(rsb->dataAvailable);
}



int rsbGetFirstDataAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (0 == rsb->dataAvailable) {
      return 0;
   } else {
      if (rsb->readPtr >= rsb->writePtr) {
         return (int)rsb->head + rsb->size - (int)rsb->readPtr;
      } else {
         return (int)rsb->writePtr - (int)rsb->readPtr;
      }
   }
}



int rsbGetSecondDataAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (0 == rsb->dataAvailable ||
       RSB_OP_SEQUENTIAL_BUFFER == rsb->opMode) {
      return 0;
   } else {
      if (rsb->readPtr >= rsb->writePtr) {
         return (int)rsb->writePtr - (int)rsb->head;
      } else {
         return 0;
      }
   }
}



int rsbGetSpaceAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (RSB_OP_RING_BUFFER == rsb->opMode) {
      return (int)(rsb->size - rsb->dataAvailable);

   } else {
      if (rsb->writePtr < rsb->readPtr) {
         ASSERT(rsb->writePtr == rsb->head);
         return 0;
      } else if (rsb->writePtr > rsb->readPtr) {
         return (int)(rsb->tail - rsb->writePtr + 1);
      } else {
         if (rsb->dataAvailable) {
            /// buffer is full
            ASSERT(rsb->dataAvailable == rsb->size);
            return 0;
         } else {
            /// buffer is empty
            ASSERT(0 == rsb->dataAvailable);
            return rsb->size;
         }
      }
   }
}



int rsbGetFirstSpaceAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (rsb->size == rsb->dataAvailable) {
      return 0;
   } else {
      if (rsb->readPtr > rsb->writePtr) {
         if (RSB_OP_RING_BUFFER == rsb->opMode) {
            return (int)rsb->readPtr - (int)rsb->writePtr;
         } else {
            return 0;
         }
      } else {
         return (int)rsb->head + rsb->size - (int)rsb->writePtr;
      }
   }
}



int rsbGetSecondSpaceAvailable(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (rsb->size == rsb->dataAvailable ||
       RSB_OP_SEQUENTIAL_BUFFER == rsb->opMode) {
      return 0;
   } else {
      if (rsb->readPtr > rsb->writePtr) {
         return 0;
      } else {
         return (int)rsb->readPtr - (int)rsb->head;
      }
   }
}



int rsbGetReadPointer(RS_BUFFER *rsb, void **readPtr)
{
   ASSERT(rsb);
   ASSERT(readPtr);

   *readPtr = rsb->readPtr;

   return rsbGetFirstDataAvailable(rsb);
}



int rsbGetWritePointer(RS_BUFFER *rsb, void **writePtr)
{
   ASSERT(rsb);
   ASSERT(writePtr);

   *writePtr = rsb->writePtr;

   return rsbGetFirstSpaceAvailable(rsb);
}



int rsbAdjustReadPointer(RS_BUFFER *rsb, int offset)
{
   ASSERT(rsb);

   if (offset >= 0) {
      /// move the read pointer backward
      const int dataAvailable = rsbGetDataAvailable(rsb);

      if (offset > dataAvailable) {
         rsbPurge(rsb);
         return dataAvailable;
      }

      rsb->readPtr += offset;
      if (rsb->readPtr > rsb->tail) {
         rsb->readPtr -= rsb->size;
      }

      rsb->dataAvailable -= offset;
      return offset;
   } else {
      /// move the read pointer forward
      int spaceAvailable;

      if (RSB_OP_RING_BUFFER == rsb->opMode) {
         spaceAvailable = rsbGetSpaceAvailable(rsb);
      } else {
         spaceAvailable = (rsb->readPtr - rsb->head);
      }

      if (spaceAvailable) {
         offset = -offset;
         if (offset > spaceAvailable) {
            offset = spaceAvailable;
         }
   
         rsb->readPtr -= offset;
         if (rsb->readPtr < rsb->head) {
            rsb->readPtr += rsb->size;
         }
   
         rsb->dataAvailable += offset;
         return (-offset);
      } else {
         return 0;
      }
   }
}



int rsbAdjustWritePointer(RS_BUFFER *rsb, int offset)
{
   ASSERT(rsb);

   if (offset >= 0) {
      int spaceAvailable;
      
      /// move the write pointer backward
      if (RSB_OP_RING_BUFFER == rsb->opMode) {
         spaceAvailable = rsbGetSpaceAvailable(rsb);
      } else {
         spaceAvailable = rsbGetFirstSpaceAvailable(rsb);
      }

      if (spaceAvailable) {
         if (offset > spaceAvailable) {
            offset = spaceAvailable;
         }
      
         rsb->writePtr += offset;
         if (rsb->writePtr > rsb->tail) {
            rsb->writePtr -= rsb->size;
         }
      
         rsb->dataAvailable += offset;
         return offset;
      } else {
         return 0;
      }
   } else {
      /// move the write pointer forward
      const int dataAvailable = rsbGetDataAvailable(rsb);

      offset = -offset;

      if (offset > dataAvailable) {
         rsbPurge(rsb);
         return (-dataAvailable);
      }

      rsb->writePtr -= offset;
      if (rsb->writePtr < rsb->head) {
         rsb->writePtr += rsb->size;
      }

      rsb->dataAvailable -= offset;
      return (-offset);
   }
}



int rsbRearrangeBuffer(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   if (RSB_OP_RING_BUFFER == rsb->opMode) {
      /// ring buffer does not support this function
      return 0;
   } else {
      register char *dst = rsb->head;
      register char *src = rsb->readPtr;

      if (dst != src) {
         register int count = rsbGetDataAvailable(rsb);

         rsbPurge(rsb);
         rsbAdjustWritePointer(rsb, count);

         while (--count >= 0) {
            *dst++ = *src++;
         }
         return rsbGetDataAvailable(rsb);
      } else {
         return 0;
      }
   }
}



int rsbGetBufferSize(RS_BUFFER *rsb)
{
   ASSERT(rsb);

   return rsb->size;
}


