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

#ifndef OWFNATIVESTREAM_H_
#define OWFNATIVESTREAM_H_

/*!
 * \brief Image stream implementation for Linux.
 *
 * WF native stream is an abstraction of image stream or
 * a content pipe that can be used to deliver image data from
 * place to another. A stream has a producer (source) and a consumer
 * (sink) as its users.
 *
 * Streams operate on buffers, whose count is fixed at creation
 * time (minimum is 1, but for non-blocking behavior values
 * greater than 1 should be used.) Streams are meant to be used
 * strictly on "point-to-point" basis, i.e. there should be only
 * one producer and one consumer for each stream.
 *
 */

// TODO: unnecessary to include here...
//#include "owfsemaphore.h"
//#include "owflinkedlist.h"
//#include "owfimage.h"

#include "owftypes.h"

#include "EGL/egl.h"
#include "EGL/eglext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    OWF_STREAM_ERROR_NONE               = 0,
    OWF_STREAM_ERROR_INVALID_STREAM     = -1,
    OWF_STREAM_ERROR_INVALID_OBSERVER   = -2,
    OWF_STREAM_ERROR_OUT_OF_MEMORY      = -3
} OWF_STREAM_ERROR;

/*!
 *  Create new off-screen image stream with external allocated frame buffers
 *
 *  \param width            Stream image buffer width
 *  \param height           Stream image buffer height
 *  \param format           Stream image buffer format
 *  \param nbufs            Number of image buffers to allocate
 *
 *  \return                 Handle to newly created stream, or OWF_INVALID_HANDLE if no
 *                          stream could be created.\n
 *
 */
OWF_PUBLIC OWFNativeStreamType
owfNativeStreamCreateImageStreamEx(OWFint width,
                                   OWFint height,
                                   const OWF_IMAGE_FORMAT* format,
                                   OWFint nbufs, 
                                   void** buffers);


/*!
 *  Destroy stream. The stream isn't necessarily immediately destroyed, but
 *  only when it's reference count reaches zero.
 *
 *  \param stream           Stream handle
 *
 */
OWF_PUBLIC void
owfNativeStreamDestroy(OWFNativeStreamType stream);


/*!
 * Get stream's image header
 *
 * \param stream            Stream handle
 * \param width             Stream width
 * \param height            Stream height
 * \param stride            Stream stride
 * \param format            Stream format
 * \param pixelSize         Stream pixelSize
 *
 * All the parameters above, except stream handle, are pointers to locations
 * where the particular value should be written to. Passing in a NULL
 * pointer means that the particular values is of no interest to the caller.
 *
 * E.g. to query only width & height one would call this function with
 * parameters (stream_handle, &width, &height, NULL, NULL, NULL);
 *
 *
 */
// TODO: After a stream is created, its header is not changed?
OWF_PUBLIC void
owfNativeStreamGetHeader(OWFNativeStreamType stream,
                         OWFint* width,
                         OWFint* height,
                         OWFint* stride,
                         OWF_IMAGE_FORMAT* format,
                         OWFint* pixelSize);

/*!
 *  Acquire read buffer from stream
 *
 *  \param stream           Stream handle
 *
 *  \return Handle to next readable (unread since last write)
 *  buffer from the stream or OWF_INVALID_HANDLE if no unread buffers
 *  are available.
 */
// TODO: This is for a consumer to get a readable buffer (latest one or the oldest unread one?)
OWF_PUBLIC OWFNativeStreamBuffer
owfNativeStreamAcquireReadBuffer(OWFNativeStreamType stream);

/*!
 *  Release read buffer.
 *
 *  \param stream           Stream handle
 *  \param buf              Buffer handle
 */
OWF_PUBLIC void
// TODO: This is for a consumer to release a readable buffer (need to follow a certain sequence? preferred not)
owfNativeStreamReleaseReadBuffer(OWFNativeStreamType stream,
                                 OWFNativeStreamBuffer buf);

/*!
 *  Acquires writable buffer from a stream. The caller has exclusive access
 *  to returned buffer until the buffer is commited to stream by
 *  calling ReleaseWriteBuffer.
 *
 *  \param stream           Stream handle
 *
 *  \return Handle to next writable buffer or OWF_INVALID_HANDLE if no such
 *  buffer is available.
 */
// TODO: This is for a provider to get a writable buffer...
OWF_PUBLIC OWFNativeStreamBuffer
owfNativeStreamAcquireWriteBuffer(OWFNativeStreamType stream);

/*!
 *  \brief Commit write buffer to stream.
 *
 * If sync object is specified, the handle to sync object is
 * associated with the buffer. The sync object is signalled
 * when the image/buffer has been either:
 * - composed into the target stream
 * - dropped (ignored) due to it being superceded by a newer
 *   image/buffer before the compositor had a chance to read it
 *
 * Sync object is signalled exactly once. The caller is responsible
 * of destroying the object.
 *
 *  \param stream           Stream handle
 *  \param buf              Buffer handle
 *  \param dpy              Optional EGLDisplay
 *  \param sync             Optional EGLSync object which is signaled when
 *                          the buffer is consumed or dropped.
 */
// TODO: This is for a provider to commit a written buffer to the stream.
// TODO: the buffer should be obtained via owfNativeStreamAcquireWriteBuffer() or anything else? anything else will be easier to use.
// TODO: We may abandon the usage of EGL sync object since it is not easy to use...TBD
// TODO: The sync object is used to detect if a buffer is consumed or discarded by consumer...
OWF_PUBLIC void
owfNativeStreamReleaseWriteBuffer(OWFNativeStreamType stream,
                                  OWFNativeStreamBuffer buf,
                                  EGLDisplay dpy,
                                  EGLSyncKHR sync);

/*!
 *  Register stream content observer (append to chain). The observer will
 *  receive buffer modification event from the stream whenever a buffer is
 *  committed.
 *
 *  \param stream           Stream handle
 *  \param observer         Stream observer
 *  \param data             Optional data to pass to observer callback
 *                          function when event is dispatched.
 */
// TODO: This seems to be used by consumer to learn any new frame buffer is commited by provider to the stream...
// TODO: This is used to implement sync to provider mode. But if we only care about sync to consumer mode, DDv2 does not need to learn this event but just queries if any new buffer when the time is right...
OWF_PUBLIC OWF_STREAM_ERROR
owfNativeStreamAddObserver(OWFNativeStreamType stream,
                           OWFStreamCallback observer,
                           void* data);

/*!
 *  Remove stream content observer.
 *
 *  \param stream           Stream handle
 *  \param observer         Observer to remove
 *  \param clientdata       Data passed when observer registered to remove
 *
 *  \return Zero if the observer was removed successfully, otherwise non-zero
 *  (OWF_STREAM_ERROR_INVALID_STREAM if the stream is invalid;
 *   OWF_STREAM_ERROR_INVALID_OBSERVER if the observer is invalid.)
 *
 *   NOTE (khronos bugzilla #5188): "Because the parameter is the observer
 *   function, it is likely that the wrong context could be removed if
 *   two contexts sharing the same implementation code are observing the
 *   same stream, and then one removes its observer. Ideally, both the
 *   function and the client void* should be passed as parameters
 *   to uniquely identify the observer."
 *
 *   The issue can be fixed by adding sync object handle into the interface
 *   of this function. Sync object must be passed to the static comparison
 *   function (ObserversEqual). Implementator must take into account that
 *   when the stream is destroyed, all observers of that stream must be destroyed.
 *
 */
// TODO: Remove observation...
OWF_PUBLIC OWF_STREAM_ERROR
owfNativeStreamRemoveObserver(OWFNativeStreamType stream,
                              OWFStreamCallback observer,
                              void* clientdata);

/*!
 *  Return pointer to stream buffer's pixel data. The buffer must be
 *  a valid read/write buffer.
 *
 *  \param stream           Stream handle
 *  \param buffer           Buffer handle
 *
 *  \return Pointer to buffers pixel data.
 */
// TODO: in case any struct type is changed...
OWF_PUBLIC void*
owfNativeStreamGetBufferPtr(OWFNativeStreamType stream,
                            OWFNativeStreamBuffer buffer);

#ifdef __cplusplus
}
#endif


#endif

