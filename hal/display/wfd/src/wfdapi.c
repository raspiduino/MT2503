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

/*! \ingroup wfd
 *  \file wfdapi.c
 *  \brief OpenWF Display SI, API implementation.
 *
 *  For function documentations, see OpenWF Display specification 1.0
 *
 *  The general layout of an API function is:
 *  - grab API mutex (lock API)
 *  - check parameter validity
 *  - invoke implementation function (WFD_...)
 *  - unlock API
 *  - return
 *
 */

#ifdef __cplusplus
extern "C" {
#endif


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <wfd/inc/wfd.h>
#include <wfd/inc/wfdext.h>
#include <egl/egl.h>
#include <egl/eglext.h>

#include "wfd/inc/wfd_hwdevice.h"
#include "drv_features_display.h"
//#define __WFD_API_PARAMETER_CHECKING__

//#if 0
//#include "wfdstructs.h"
//#include "wfdhandle.h"
//#include "wfddevice.h"
//#include "wfdevent.h"
//#include "wfdport.h"
//#include "wfdpipeline.h"
//#include "wfdimageprovider.h"
//#include "wfdutils.h"
//#include "wfddebug.h"
//#endif

//#if 0
//#include "owfimage.h"
//#include "owfmemory.h"
//#include "owfscreen.h"
//#endif

// TODO: fix this one...
#define DPRINT(x) 
/* =================================================================== */
/*                         3.  D e v i c e s                           */
/* =================================================================== */

/**
 *  \status Not finished
 */
WFD_API_CALL WFDint WFD_APIENTRY
wfdEnumerateDevices(WFDint *deviceIds,
                    WFDint deviceIdsCount,
                    const WFDint *filterList) WFD_APIEXIT
{
    WFDint i = 0;

    DPRINT(("wfdEnumerateDevices(%p,%d, %p)", deviceIds, deviceIdsCount, filterList));

    if ((NULL != deviceIds) && (deviceIdsCount <= 0))
    {
        return 0; /* failure - zero or negative device count */
    }

    if (NULL == filterList || filterList[0] == WFD_NONE)
    {
        /* nothing to filter */
        return WFD_HWDevice_GetIds(deviceIds, deviceIdsCount);
    }

    /* check the filter list, only WFD_DEVICE_FILTER_PORT_ID accepted */
    for (i = 0; filterList[i] != WFD_NONE; i += 2)
    {
        if (filterList[i] != WFD_DEVICE_FILTER_PORT_ID)
            return 0;

        /* return all ids if port id has value WFD_INVALID_HANDLE */
        if (filterList[i+1] == WFD_INVALID_HANDLE)
        {
            return WFD_HWDevice_GetIds(deviceIds, deviceIdsCount);
        }
    }

    // TODO: Filter port IDs, we don't support it right now for easy development...
    return WFD_HWDevice_GetIds(deviceIds, deviceIdsCount);
}


WFD_API_CALL WFDDevice WFD_APIENTRY
wfdCreateDevice (WFDint deviceId, const WFDint *attribList)
{
    WFDDevice device;

    DPRINT(("wfdCreateDevice(%d,%p)", deviceId, attribList));

#ifdef __WFD_API_PARAMETER_CHECKING__
    if (attribList != NULL && *attribList != WFD_NONE)
    {
        DPRINT(("  no attributes allowed\n"));
        return WFD_ERROR_BAD_ATTRIBUTE;
    }
#endif  // 0

    device = WFD_HWDevice_CreateDevice(deviceId, attribList);

    DPRINT(("  Device creation done\n"));

    return device;
}

WFD_API_CALL WFDErrorCode WFD_APIENTRY
wfdDestroyDevice(WFDDevice device) WFD_APIEXIT
{
    WFDHWDevicePrimitivesMTK* pDevice = &((WFD_DEVICE*) device)->primitivesTable;

    DPRINT(("wfdDestroyDevice(0x%08x)", device));

#ifdef __WFD_API_PARAMETER_CHECKING__
    if (WFD_INVALID_HANDLE == device)
    {
      return WFD_ERROR_BAD_DEVICE;
    }

    if (NULL != pDevice)
    {
#endif
      pDevice->wfdDestroyDevice(device);
#ifdef __WFD_API_PARAMETER_CHECKING__
    }
    else
    {
      return WFD_ERROR_BAD_DEVICE;
    }
#endif

    return WFD_ERROR_NONE;
}


WFD_API_CALL void WFD_APIENTRY
 wfdDeviceCommit(WFDDevice device,
        WFDCommitType type,
        WFDHandle handle) WFD_APIEXIT
{
    /* check preconditions */
    WFDHWDevicePrimitivesMTK* pDevice = &((WFD_DEVICE*) device)->primitivesTable;

    DPRINT(("wfdDeviceCommit(%08x,%08x,%08x)\n", device, type, handle));

#ifdef __WFD_API_PARAMETER_CHECKING__
    if (NULL != pDevice)
    {
#endif
        pDevice->wfdDeviceCommit(device, type, handle);
#ifdef __WFD_API_PARAMETER_CHECKING__
    }
    else
    {
        WFD_HWDevice_SetError(WFD_ERROR_BAD_DEVICE);
    }
#endif
}


#ifdef __cplusplus
}
#endif
