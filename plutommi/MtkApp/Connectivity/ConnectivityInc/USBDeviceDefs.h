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
 * USBDeviceDefs.h
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

#ifndef MMI_USBDEVICE_DEFS_H
#define MMI_USBDEVICE_DEFS_H

#include "MMI_features.h"

#ifdef __MMI_USB_SUPPORT__

    
    #include "MMIDataType.h"
    #include "kal_general_types.h"

/***************************************************************************** 
* Definations
*****************************************************************************/

/* Number of menu items in usb config page */
#define MAX_USB_MENUITEM   2    /* 3 */


/***************************************************************************** 
* Enumation
*****************************************************************************/

/*****************************/
/* MMI Usb config menu items */
/*****************************/
typedef enum
{
#ifdef __USB_MASS_STORAGE_ENABLE__        
    MMI_USB_CONFIG_MENU_MS = 0,
#endif
    
#ifdef __MMI_WEBCAM__
    MMI_USB_CONFIG_MENU_WEBCAM,
#endif 

#ifdef __USB_COM_PORT_ENABLE__
    MMI_USB_CONFIG_MENU_CDCACM,
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    MMI_USB_CONFIG_MENU_PICTBRIGE,
#endif

#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
    MMI_USB_CONFIG_MENU_JAVA_CONNECTION,
#endif

#ifdef __MTP_ENABLE__
    MMI_USB_CONFIG_MENU_MTP,
#endif

#ifdef __USB_DATA_CONNECTION__
    MMI_USB_CONFIG_MENU_CDROM,
#endif

    MMI_USB_CONFIG_MENU_RESERVED,

    MMI_USB_CONFIG_MENU_END
} MMI_USB_CONFIG_MENU;

typedef enum
{
//    MMI_USB_POWERON_CHARGING_NONE,
    MMI_USB_POWERON_CHARGING_ENABLE,
    MMI_USB_POWERON_CHARGING_DISABLE
} MMI_USB_POWERON_CHARGING_STATE;

/***************************************************************************** 
* Structure
*****************************************************************************/

/********************/
/* MMI Usb context * */
/********************/

typedef struct
{
    /*   Usb config screen might interrupt every screen, if user press END key at usb    */
    /* config screen, shall distory config screen itself and execute the END key handler */
    /* register by original screen                                                       */
    //FuncPtr EndKeyFuncPtr;

    /*
     * Bit 0: Before Power on Flag
     * Bit 1: Pending Timer Flag
     * Bit 2: Usb plug out during switch port
     */


    MMI_USB_POWERON_CHARGING_STATE still_image;

} MMI_USB_CONTEXT;

extern void mmi_usb_boot_pwrnon_then_poweron(void);
extern void UsbDetectScrLskHdlr(void);
extern void UsbDetectScrRskHdlr(void);
extern void UsbDetectScrENDKeyHdlr(void);
extern void UsbConfigFirstPage(U8 mode);
extern void mmi_usb_close_power_off_screen(void);



#ifdef __USB_IN_NORMAL_MODE__
extern MMI_BOOL mmi_usb_is_any_exported_drive(void);
#endif /* #ifdef __USB_IN_NORMAL_MODE__ */

extern BOOL mmi_usb_is_network_services_available(void);

/* extern void PendingUsbDetectionAtPowerOnHdlr(void); */

#endif /* __MMI_USB_SUPPORT__ */ 

#endif /* MMI_USBDEVICE_DEFS_H */ 

