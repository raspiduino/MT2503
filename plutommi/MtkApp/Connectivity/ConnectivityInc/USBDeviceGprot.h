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
 * USBDeviceGprot.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_USBDEVICE_GPROT_H
#define MMI_USBDEVICE_GPROT_H

#ifdef __MMI_USB_SUPPORT__

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _CUSTOM_EVENTS_NOTIFY_H
#include "custom_events_notify.h"
#endif

#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "USBSrvGProt.h"

/****************************************************************************
* Setting
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Typedef                                                            
*****************************************************************************/
/* 
 * USB state used to keep the USB current status
 */
typedef enum
{

    MMI_USBSTATUS_UNKNOW = 0,           /* Unknow, initial state */
    MMI_USBSTATUS_PLUGIN,               /* Usb device pluged in */
    MMI_USBSTATUS_CONF_PAGE,            /* Usb device pluged in and MMI Screen is usb configure page */
    MMI_USBSTATUS_IGNORED,              /* Usb device pluged in, user ignore the configuration */
    MMI_USBSTATUS_PLUGOUT,              /* Usb device pluged out */
    MMI_USBSTATUS_MS_PROC,              /* Usb device is configuring as mass storage */
    MMI_USBSTATUS_MS,                   /* Usb device is in mass storage mode */
    MMI_USBSTATUS_CDCACM_PROC,          /* Usb device is configuring as com port emulator */
    MMI_USBSTATUS_CDCACM,               /* Usb device is in com port emulator mode */
    MMI_USBSTATUS_WEBCAM,               /* Usb device is configuring as webcam */
    MMI_USBSTATUS_PICTBRIGE,            /* Usb device is configuring as pictbrige */
    MMI_USBSTATUS_JAVA_CONNECT,         /* Usb device is configuring as java connection */
    MMI_USBSTATUS_CDROM,
    MMI_USBSTATUS_ENUM_END              /* Last state, shall not modify this value */
} MMI_USB_STATUS;

/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitMMIUsbContext
 * DESCRIPTION
 *  This function is to initialize the mmi usb context
 *  This is called by InitializeAll() 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void InitMMIUsbContext(void);

/*****************************************************************************
 * FUNCTION
 *  InitializeUsbScr
 * DESCRIPTION
 *  This function is initial function for usb boot mode,
 *  and show the USB power-on screen
 *  This is called by MMI_task()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void InitializeUsbScr(void);

/*****************************************************************************
 * FUNCTION
 *  UsbDetectIndHdlr
 * DESCRIPTION
 *  This function is usb detect indication event handler
  *  This is called by InitEventHandlersBeforePowerOn()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//extern void UsbDetectIndHdlr(void *info);

#ifdef __USB_IN_NORMAL_MODE__

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_app_unavailable_popup
 * DESCRIPTION
 *  to show a warning popup screen if the app is disable in MS mode.
 *  if input string id = 0, it will use default string of USB
 * PARAMETERS
 *  stringId   : [IN] path for query
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_usb_app_unavailable_popup(U16 stringId);

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
extern MMI_STR_ID mmi_usb_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_shutdown_handler
 * DESCRIPTION
 *  to shutdown USB mass storage before phone power-off handler
 *  This function is called by shutdown application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//extern mmi_ret mmi_usb_shutdown_handler(mmi_event_struct *evt);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __MMI_WEBCAM__
/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_entry_app_scr
 * DESCRIPTION
 *  to display WEBCAM screen
 *  This function is called by EntryIdleScreen()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_usb_webcam_entry_app_scr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_webcam_is_active
 * DESCRIPTION
 *  to query if if USB WEBCAM is active
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if yes, FALSE if no
 *****************************************************************************/
extern MMI_BOOL mmi_usb_webcam_is_active(void);
#endif /* __MMI_WEBCAM__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_set_background_still
 * DESCRIPTION
 *  to set USB power on image for USB power on mode screen
 *  if the input is TRUE, means the screen is with still image (no charing)
 *  otherwise it means the screen is with charging animation (charging)
 * PARAMETERS
 *  isStill: TRUE for using still image, FALSE for using animation image
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_usb_set_background_still(MMI_BOOL isStill);


#endif /* __MMI_USB_SUPPORT__ */ 
#endif /* MMI_USBDEVICE_GPROT_H */ 

