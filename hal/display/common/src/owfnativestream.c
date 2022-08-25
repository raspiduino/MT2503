/* Copyright (c) 2009 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 */

/*!
 * Ring buffer based Image Stream implementation for Linux.
 */



#ifdef __cplusplus
extern "C" {
#endif

#define OWF_NATIVESTREAM_HANDLE 0xAB

#include <stdlib.h>
#include <string.h>

#include "kal_release.h"

#include "common/owfnativestream.h"
#include "common/owftypes.h"

/*needed for owfNativeStreamFromWFC function */
#include "wfc/wfcplatform.h"

extern kal_uint32   SaveAndSetIRQMask( void );
extern void     RestoreIRQMask( kal_uint32 );
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_uint32 kal_query_sem_value (kal_semid ext_sem_id_ptr);
extern OWFint OWF_Image_GetStride(OWFint width, const OWF_IMAGE_FORMAT* format, OWFint minimumStride);
extern OWFint OWF_Image_GetFormatPixelSize(OWF_PIXEL_FORMAT format);

#define MAX_STREAM_COUNT              (2)
#define MAX_BUFFER_COUNT_PER_STREAM   (3)
#define MAX_OBSERVER_COUNT_PER_STREAM (1)

#define BUFFER_HANDLE_BASE            0x100
#define INVALID_INDEX_NUMBER          0xFFFFFFFF

/* stream null checks */
#define CHECK_STREAM(ns,v)     if (NULL == ns) { return v;}
#define CHECK_STREAM_NR(ns)   if (NULL == ns) { return; }

/* buffer handle sanity checks */
#define CHECK_BUFFER_NR(x)  if ((x) < BUFFER_HANDLE_BASE || \
                                (x) >= BUFFER_HANDLE_BASE + ns->bufferCount) \
                            { \
                                return; \
                            }

#define CHECK_BUFFER(x,v)   if ((x) < BUFFER_HANDLE_BASE || \
                                (x) >= BUFFER_HANDLE_BASE + ns->bufferCount) \
                            { \
                            return v; \
                            }

/**
 *  \def INDEX_TO_HANDLE
 *  \param x is buffer index, 0, 1, 2, ...
 *  The handle is the handle used to get buffer pointer via owfNativeStreamGetBufferPtr()...
 *  Adding BUFFER_HANDLE_BASE is just non-sense and a simplest hash function...
 */
#define INDEX_TO_HANDLE(x)  ((OWFNativeStreamBuffer) ((x)+BUFFER_HANDLE_BASE))

/**
 *  \def HANDLE_TO_INDEX
 *  \param buffer handle
 */
#define HANDLE_TO_INDEX(x)  ((int) ((x)-BUFFER_HANDLE_BASE))



#ifndef OWF_ASSERT
#define OWF_ASSERT(_expr_) ASSERT(_expr_)
#endif

typedef enum
{
    STATE_AVAILABLE = 0,          ///must be 0
    STATE_WRITE_OCCUPIED,           ///acquired as write buffer
    STATE_READ_OCCUPIED             ///set when release write buffer
}OWF_STREAM_BUFFER_STATE_ENUM;

typedef struct OWFBufferArray
{
    void*                          bufferAddr;
    OWF_STREAM_BUFFER_STATE_ENUM   bufferState;
}OWFBufferArray;

/*!
 * Structure for image stream.
 */
typedef struct {
    OWFNativeStreamType     handle; /**< stream handle, pointer to itself */

	OWFint                  width; /**< frame width (pixels) */
    OWFint                  height; /**< frame height (pixels) */
    OWF_IMAGE_FORMAT        colorFormat;	
    OWFint                  stride; /**< size of single row (bytes) */
	
    OWFBufferArray          bufferArray[MAX_BUFFER_COUNT_PER_STREAM];    /**< buffer array */
    OWFint                  bufferCount; /**< stream buffer count */
    OWFint                  idxRead;     /**< the read buffer index */
    
    OWFStreamCallbackData   observerArray[MAX_OBSERVER_COUNT_PER_STREAM]; /**< store callback function's information */                     
} OWF_NATIVE_STREAM;

static OWF_NATIVE_STREAM _owfNativeStreamPool[MAX_STREAM_COUNT]; /**< store all stream's information */

/*============================================================================
 * PRIVATE PARTS
 *============================================================================*/

/*!---------------------------------------------------------------------------
 *  Notify stream's observers about an event
 *
 *  \param stream           Stream
 *  \param event            Event to notify about
 *----------------------------------------------------------------------------*/
static void owfNativeStreamNotifyObservers(OWFNativeStreamType stream,
                                           OWFNativeStreamEvent event)
{

  OWFint             ii = 0;
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;

  CHECK_STREAM_NR(ns);

  for(ii=0;ii<MAX_OBSERVER_COUNT_PER_STREAM;ii++)
  {
      if(ns->observerArray[ii].callback != NULL)
      {
         ns->observerArray[ii].callback(stream, event, ns->observerArray[ii].data);
      }
  }
}

/*----------------------------------------------------------------------------
 *  Observer equality comparison
 *----------------------------------------------------------------------------*/
static OWFint
ObserversEqual(OWFStreamCallbackData* arg1, OWFStreamCallbackData* arg2)
{
  return (OWFint)( (arg1->callback == arg2->callback) && (arg1->data == arg2->data) );
}

/*============================================================================
 * PUBLIC API STARTS HERE
 *============================================================================*/

/*!----------------------------------------------------------------------------
 *  Create new native stream.
 *
 *  \param width            Stream image buffer width
 *  \param height           Stream image buffer height
 *  \param imageFormat      Stream image buffer format
 *  \param nbufs            Number of image buffers to allocate
 *
 *  \param Handle to newly created stream or OWF_INVALID_HANDLe if no
 *  stream could be created.
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWFNativeStreamType
owfNativeStreamCreateImageStreamEx(OWFint width,
                                   OWFint height,
                                   const OWF_IMAGE_FORMAT* imageFormat,
                                   OWFint nbufs, 
                                   void** buffers)
{
  OWF_NATIVE_STREAM*      ns          = NULL;
  OWFint                  ii          = 0;
  kal_uint32              savedMask;

  //parameter checking
  OWF_ASSERT(nbufs >= 1);
  OWF_ASSERT(nbufs <= MAX_BUFFER_COUNT_PER_STREAM);
  OWF_ASSERT(NULL != buffers);
  OWF_ASSERT(NULL != imageFormat);
  for (ii = 0; ii < nbufs; ii++)
  {
    if(buffers[ii] == NULL)
    return OWF_INVALID_HANDLE;
  }


  ns = NULL;
  savedMask = SaveAndSetIRQMask();          ///Bin: save IRQ to avoid race condition
  for(ii=0;ii<MAX_STREAM_COUNT;ii++)
  {
    ///find an empty pool
    if(_owfNativeStreamPool[ii].handle == 0)
    {
      _owfNativeStreamPool[ii].handle = (OWFNativeStreamType)1;  /// Bin: fill in dummy value in case race condition
      ns = &(_owfNativeStreamPool[ii]);
      break;
    }
  }
  RestoreIRQMask(savedMask);

  if(ns == NULL)
    return OWF_INVALID_HANDLE;
  
  /* initialize buffer list */
  for (ii = 0; ii < nbufs; ii++)
  {
    ns->bufferArray[ii].bufferAddr = buffers[ii];
    ns->bufferArray[ii].bufferState = STATE_AVAILABLE;     ///init all buffer can be write
  }

  ns->idxRead           = INVALID_INDEX_NUMBER;
  ns->bufferCount       = nbufs;

  ns->width             = width;
  ns->height            = height;

  kal_mem_cpy((void*) &ns->colorFormat, (void*) imageFormat, sizeof(ns->colorFormat));
  ns->stride            = OWF_Image_GetStride(width, imageFormat, 0);
  ns->handle = (OWFNativeStreamType)ns;

  return ns->handle;
}


/*!---------------------------------------------------------------------------
 *  Destroy stream. The stream isn't necessarily immediately destroyed
 *
 *  \param stream           Stream handle
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC void
owfNativeStreamDestroy(OWFNativeStreamType stream)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;

  if(stream == NULL)
    return;
    
  kal_mem_set((void*) ns, 0x0, sizeof(OWF_NATIVE_STREAM));
  ns->idxRead           = INVALID_INDEX_NUMBER;     ///Bin: invalid the read index
}

/*!---------------------------------------------------------------------------
 *  Acquire read buffer from stream
 *
 *  \param stream           Stream handle
 *
 *  \return Handle to next readable (unread since last write)
 *  buffer from the stream or OWF_INVALID_HANDLE if no unread buffers
 *  are available.
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWFNativeStreamBuffer
owfNativeStreamAcquireReadBuffer(OWFNativeStreamType stream)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;

  CHECK_STREAM(ns,OWF_INVALID_HANDLE);

  ///for the only one buffer case
  if(ns->bufferCount == 1)
    return INDEX_TO_HANDLE(0); 

  if(ns->idxRead == INVALID_INDEX_NUMBER)
  {
    return OWF_INVALID_HANDLE;
  }

  if(ns->bufferArray[ns->idxRead].bufferState == STATE_AVAILABLE)
  {
    ns->bufferArray[ns->idxRead].bufferState = STATE_READ_OCCUPIED;
    return INDEX_TO_HANDLE(ns->idxRead);
  }
  else if(ns->bufferArray[ns->idxRead].bufferState == STATE_READ_OCCUPIED)
  {
    return INDEX_TO_HANDLE(ns->idxRead);
  }
  else
  {
    /// the buffer is acquired as write buffer,  weird
    ASSERT(0);
    return OWF_INVALID_HANDLE;
  } 
}

/*!---------------------------------------------------------------------------
 *  Release read buffer.
 *
 *  \param stream           Stream handle
 *  \param buf              Buffer handle
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC void
owfNativeStreamReleaseReadBuffer(OWFNativeStreamType stream,
                                 OWFNativeStreamBuffer buf)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;
  OWFint ii = HANDLE_TO_INDEX(buf);

  CHECK_STREAM_NR(ns);

  ///for the one buffer and double buffer case
  ///for the double buffer case, we did not release the READ_OCCUPIED state, since the state change happens in owfNativeStreamReleaseWriteBuffer
  if(ns->bufferCount == 1 || ns->bufferCount == 2)
    return;

  if(ns->bufferArray[ii].bufferState == STATE_READ_OCCUPIED)
  {
    ns->bufferArray[ii].bufferState = STATE_AVAILABLE;   
    ///Bin: in this case, the latest write buffer is corrupt and this buffer will be used as latest buffer
    if(ns->idxRead == INVALID_INDEX_NUMBER)
    {
      ns->idxRead = ii;
    }
  }

  return;
}

/*!---------------------------------------------------------------------------
 *  Acquires writable buffer from a stream. The caller has exclusive access
 *  to returned buffer until the buffer is commited to stream by
 *  calling ReleaseWriteBuffer.
 *
 *  \param stream           Stream handle
 *
 *  \return Handle to next writable buffer or OWF_INVALID_HANDLE if no such
 *  buffer is available.
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWFNativeStreamBuffer
owfNativeStreamAcquireWriteBuffer(OWFNativeStreamType stream)
{
  OWFint  ii;
  OWFint  tmpIdxRead;
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;
  
  CHECK_STREAM(ns,OWF_INVALID_HANDLE);

  ///for the single buffer case
  if(ns->bufferCount == 1)
    return INDEX_TO_HANDLE(0);      

  
  tmpIdxRead = ns->idxRead;
  if(tmpIdxRead == INVALID_INDEX_NUMBER)
    tmpIdxRead = -1;   ///Bin: in order to search from the buffer array index 0

  /// search the buffer after read index 
  for(ii=(tmpIdxRead + 1);ii<ns->bufferCount;ii++)
  {
    if(ns->bufferArray[ii].bufferState == STATE_AVAILABLE)
    {
      ns->bufferArray[ii].bufferState = STATE_WRITE_OCCUPIED;      
      return INDEX_TO_HANDLE(ii);
    }
  }

  /// search the buffer before the read index
  for(ii=0;ii<tmpIdxRead;ii++)
  {
    if(ns->bufferArray[ii].bufferState == STATE_AVAILABLE)
    {
      ns->bufferArray[ii].bufferState = STATE_WRITE_OCCUPIED;      
      return INDEX_TO_HANDLE(ii);
    }
  }

  if(tmpIdxRead < 0)
    ASSERT(0);
  
  ///only the idxRead buffer can be used...
  if(ns->bufferArray[tmpIdxRead].bufferState == STATE_AVAILABLE)
  {
    ns->bufferArray[tmpIdxRead].bufferState = STATE_WRITE_OCCUPIED;  

    ///Bin: if the buffer with latest content is acuired as write buffer, we do not know which buffer can be give to WFC to display
    //        Since the next release write buffer will update the idxRead, before that WFC can not get read buffer ~~~
    ns->idxRead = INVALID_INDEX_NUMBER;
    return INDEX_TO_HANDLE(tmpIdxRead);
  }

  return OWF_INVALID_HANDLE;
}

/*!---------------------------------------------------------------------------
 *  Commit write buffer to stream.
 *
 *  \param stream           Stream handle
 *  \param buf              Buffer handle
 *  \param sync             EGLSync object which is signalled when
 *                          release buffer gets consumed or dropped
 *----------------------------------------------------------------------------*/
OWF_PUBLIC void
owfNativeStreamReleaseWriteBuffer(OWFNativeStreamType stream,
                                  OWFNativeStreamBuffer buf,
                                  EGLDisplay dpy,
                                  EGLSyncKHR sync)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;
  OWFint ii = HANDLE_TO_INDEX(buf);
  kal_uint32              savedMask;

  CHECK_STREAM_NR(ns);
  CHECK_BUFFER_NR(buf);

  ///for the only one buffer case
  if(ns->bufferCount == 1)
  {
    ;  /// do nothing
  }
  else
  {
    if(ns->bufferArray[ii].bufferState == STATE_WRITE_OCCUPIED)
    {
      savedMask = SaveAndSetIRQMask();          ///Bin: save IRQ to avoid race condition
      if(ns->bufferCount == 2)
      {
        ///Double buffer case
        ///1. release the previous read buffer (make sure MDP can get this buffer)
        ///2. Occupy the new read buffer
        if(ns->idxRead != INVALID_INDEX_NUMBER)
        {
          ns->bufferArray[ns->idxRead].bufferState = STATE_AVAILABLE;
        }
        ns->bufferArray[ii].bufferState = STATE_READ_OCCUPIED;
      }
      else
      {
        ///Multi buffer case, release the buffer to available state
        ns->bufferArray[ii].bufferState = STATE_AVAILABLE;
      }
      /// set new read buffer
      ns->idxRead = ii;                         ///update the latest read index
      RestoreIRQMask(savedMask);    
    }
    else
    {
      return;     ///invalid buffer state
    }
  }

  owfNativeStreamNotifyObservers(stream, OWF_STREAM_UPDATED);
}

/*!---------------------------------------------------------------------------
 *  Register stream content observer. The observer will receive buffer
 *  modification event from the stream whenever a buffer is committed.
 *
 *  \param stream           Stream handle
 *  \param observer         Stream observer
 *  \param data             Optional data to pass to observer callback
 *                          function when event is dispatched.
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWF_STREAM_ERROR
owfNativeStreamAddObserver(OWFNativeStreamType stream,
                           OWFStreamCallback observer,
                           void* data)
{
  kal_uint32              i = 0;
  OWF_NATIVE_STREAM*      ns = (OWF_NATIVE_STREAM*)stream;

  if(stream == NULL)
    return OWF_STREAM_ERROR_INVALID_STREAM;

  // KeTing: If the observer was added, don't add again
  {
    OWFStreamCallbackData tmp;
    tmp.callback = observer;
    tmp.data = data;
    
    for(i=0;i<MAX_OBSERVER_COUNT_PER_STREAM;i++)
    {
      if (ObserversEqual(&tmp, &(ns->observerArray[i])))
      {
        return OWF_STREAM_ERROR_NONE;
      }
    }
  }

  /* new observer. find an empty slot to store the callback data. */
  for (i=0; i < MAX_OBSERVER_COUNT_PER_STREAM; i++)
  {
    if (NULL == ns->observerArray[i].callback)
    {
      ns->observerArray[i].callback = observer;
      ns->observerArray[i].data = data;
      return OWF_STREAM_ERROR_NONE;
    }
  }

  ///run here, means can not find an empty slot
  return OWF_STREAM_ERROR_OUT_OF_MEMORY;
}

/*!---------------------------------------------------------------------------
 *  Remove stream content observer.
 *  Observer or Data can be NULL indicating search only checks for other member.
 *  Both must not be NULL.
 *  \param stream           Stream handle
 *  \param observer         Observer to remove
 *  \param data             Identifying client data
 *
 *  \return Zero if the observer was removed successfully, otherwise non-zero
 *  (OWF_STREAM_ERROR_INVALID_STREAM if the stream is invalid;
 *   OWF_STREAM_ERROR_INVALID_OBSERVER if the observer is invalid.)
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWF_STREAM_ERROR 
owfNativeStreamRemoveObserver(OWFNativeStreamType stream,
                              OWFStreamCallback observer,
                              void* data)
{
  OWFStreamCallbackData   tmp;

  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;
  kal_uint32         i = 0;

  CHECK_STREAM(ns,OWF_STREAM_ERROR_INVALID_STREAM);

  tmp.callback = observer;
  tmp.data = data;

  for (i=0; i < MAX_OBSERVER_COUNT_PER_STREAM; i++)
  {
    if (ObserversEqual(&tmp, &(ns->observerArray[i])))
    {
      ns->observerArray[i].callback = NULL;
      ns->observerArray[i].data = NULL;
      return OWF_STREAM_ERROR_NONE;
    }
  }

  ///run here, means can not find the observer
  return OWF_STREAM_ERROR_INVALID_OBSERVER;
}


/*!---------------------------------------------------------------------------
 *  Return pointer to stream buffer's pixel data. The buffer must be
 *  a valid read/write buffer.
 *
 *  \param stream           Stream handle
 *  \param buffer           Buffer handle
 *
 *  \return Pointer to buffers pixel data.
 *----------------------------------------------------------------------------*/
OWF_PUBLIC void*
owfNativeStreamGetBufferPtr(OWFNativeStreamType stream,
                            OWFNativeStreamBuffer buffer)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;
  OWFint ii = HANDLE_TO_INDEX(buffer);
  CHECK_STREAM(ns,NULL);

  if(ii >= ns->bufferCount)
    return NULL;
  else
    return ns->bufferArray[ii].bufferAddr;
}

/*!---------------------------------------------------------------------------
 *  Get stream's image header
 *
 *  \param stream            Stream handle
 *  \param width             Stream width
 *  \param height            Stream height
 *  \param stride            Stream stride
 *  \param format            Stream format
 *  \param pixelSize         Stream pixelSize
 *
 *  All the parameters above, except stream handle, are pointers to locations
 *  where the particular value should be written to. Passing in a NULL
 *  pointer means that the particular values is of no interest to the caller.
 *
 *  E.g. to query only width & height one would call this function with
 *  parameters (stream_handle, &width, &height, NULL, NULL, NULL);
 *  
 *  \status OK
 *----------------------------------------------------------------------------*/
OWF_PUBLIC void
owfNativeStreamGetHeader(OWFNativeStreamType stream,
                         OWFint* width,
                         OWFint* height,
                         OWFint* stride,
                         OWF_IMAGE_FORMAT* format,
                         OWFint* pixelSize)
{
  OWF_NATIVE_STREAM* ns = (OWF_NATIVE_STREAM*)stream;

  CHECK_STREAM_NR(ns);
    
  if (width)
  {
      *width  = ns->width;
  }
  if (height)
  {
      *height = ns->height;
  }
  if (stride)
  {
      *stride = ns->stride;
  }
  if (format)
  {
      kal_mem_cpy((void*) format, (void*) &ns->colorFormat, sizeof(*format));
  }
  if (pixelSize)
  {
      *pixelSize = OWF_Image_GetFormatPixelSize(ns->colorFormat.pixelFormat);
  }
}

#ifdef __cplusplus
}

#endif

