/*
 * usbuser.h
 *
 * USB user mode IOCTL interface
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __USBUSER_H
#define __USBUSER_H

#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,4)

#include "ntddk.h"
#include "usb.h"
#include "usbiodef.h"


#define USBUSER_VERSION                   0x0004

#define IOCTL_USB_USER_REQUEST            USB_CTL(HCD_USER_REQUEST)

#ifndef IOCTL_USB_DIAGNOSTIC_MODE_ON
#define IOCTL_USB_DIAGNOSTIC_MODE_ON      USB_CTL(HCD_DIAGNOSTIC_MODE_ON) 
#endif
#ifndef IOCTL_USB_DIAGNOSTIC_MODE_OFF
#define IOCTL_USB_DIAGNOSTIC_MODE_OFF     USB_CTL(HCD_DIAGNOSTIC_MODE_OFF) 
#endif

#ifndef IOCTL_USB_GET_ROOT_HUB_NAME
#define IOCTL_USB_GET_ROOT_HUB_NAME       USB_CTL(HCD_GET_ROOT_HUB_NAME) 
#endif
#ifndef IOCTL_GET_HCD_DRIVERKEY_NAME
#define IOCTL_GET_HCD_DRIVERKEY_NAME      USB_CTL(HCD_GET_DRIVERKEY_NAME) 
#endif

typedef enum _USB_USER_ERROR_CODE {
	UsbUserSuccess = 0,
	UsbUserNotSupported,
	UsbUserInvalidRequestCode,
	UsbUserFeatureDisabled,
	UsbUserInvalidHeaderParameter,
	UsbUserInvalidParameter,
	UsbUserMiniportError,
	UsbUserBufferTooSmall,
	UsbUserErrorNotMapped,
	UsbUserDeviceNotStarted,
	UsbUserNoDeviceConnected
} USB_USER_ERROR_CODE;

#define USBUSER_GET_CONTROLLER_INFO_0     0x00000001
#define USBUSER_GET_CONTROLLER_DRIVER_KEY 0x00000002
#define USBUSER_PASS_THRU                 0x00000003
#define USBUSER_GET_POWER_STATE_MAP       0x00000004
#define USBUSER_GET_BANDWIDTH_INFORMATION 0x00000005
#define USBUSER_GET_BUS_STATISTICS_0      0x00000006
#define USBUSER_GET_ROOTHUB_SYMBOLIC_NAME 0x00000007
#define USBUSER_GET_USB_DRIVER_VERSION    0x00000008
#define USBUSER_GET_USB2_HW_VERSION       0x00000009
#define USBUSER_OP_SEND_ONE_PACKET        0x10000001
#define USBUSER_OP_RAW_RESET_PORT         0x20000001
#define USBUSER_OP_OPEN_RAW_DEVICE        0x20000002
#define USBUSER_OP_CLOSE_RAW_DEVICE       0x20000003
#define USBUSER_OP_SEND_RAW_COMMAND       0x20000004
#define USBUSER_INVALID_REQUEST           0xFFFFFFF0
#define USBUSER_OP_MASK_DEVONLY_API       0x10000000
#define USBUSER_OP_MASK_HCTEST_API        0x20000000

#define USB_PACKETFLAG_LOW_SPEED          0x00000001
#define USB_PACKETFLAG_FULL_SPEED         0x00000002
#define USB_PACKETFLAG_HIGH_SPEED         0x00000004
#define USB_PACKETFLAG_ASYNC_IN           0x00000008
#define USB_PACKETFLAG_ASYNC_OUT          0x00000010
#define USB_PACKETFLAG_ISO_IN             0x00000020
#define USB_PACKETFLAG_ISO_OUT            0x00000040
#define USB_PACKETFLAG_SETUP              0x00000080
#define USB_PACKETFLAG_TOGGLE0            0x00000100
#define USB_PACKETFLAG_TOGGLE1            0x00000200

typedef struct _PACKET_PARAMETERS {
	UCHAR  DeviceAddress;
	UCHAR  EndpointAddress;
	USHORT  MaximumPacketSize;
	ULONG  Timeout;
	ULONG  Flags;
	ULONG  DataLength;
	USHORT  HubDeviceAddress;
	USHORT  PortTTNumber;
	UCHAR  ErrorCount;
	UCHAR  Pad[3];
	USBD_STATUS  UsbdStatusCode;
	UCHAR  Data[4];
} PACKET_PARAMETERS, *PPACKET_PARAMETERS;

typedef struct _RAW_RESET_PORT_PARAMETERS {
	USHORT  PortNumber;
	USHORT  PortStatus;
} RAW_RESET_PORT_PARAMETERS, *PRAW_RESET_PORT_PARAMETERS;

typedef struct _USB_BANDWIDTH_INFO {
	ULONG  DeviceCount;
	ULONG  TotalBusBandwidth;
	ULONG  Total32secBandwidth;
	ULONG  AllocedBulkAndControl;
	ULONG  AllocedIso;
	ULONG  AllocedInterrupt_1ms;
	ULONG  AllocedInterrupt_2ms;
	ULONG  AllocedInterrupt_4ms;
	ULONG  AllocedInterrupt_8ms;
	ULONG  AllocedInterrupt_16ms;
	ULONG  AllocedInterrupt_32ms;
} USB_BANDWIDTH_INFO, *PUSB_BANDWIDTH_INFO;

typedef struct _USBUSER_REQUEST_HEADER {
	ULONG  UsbUserRequest;
	USB_USER_ERROR_CODE  UsbUserStatusCode;
	ULONG  RequestBufferLength;
	ULONG  ActualBufferLength;
} USBUSER_REQUEST_HEADER, *PUSBUSER_REQUEST_HEADER;

typedef struct _USBUSER_BANDWIDTH_INFO_REQUEST {
	USBUSER_REQUEST_HEADER  Header;
	USB_BANDWIDTH_INFO  BandwidthInformation;
} USBUSER_BANDWIDTH_INFO_REQUEST, *PUSBUSER_BANDWIDTH_INFO_REQUEST;

typedef struct _USB_BUS_STATISTICS_0 {
	ULONG  DeviceCount;
	LARGE_INTEGER  CurrentSystemTime;
	ULONG  CurrentUsbFrame;
	ULONG  BulkBytes;
	ULONG  IsoBytes;
	ULONG  InterruptBytes;
	ULONG  ControlDataBytes;
	ULONG  PciInterruptCount;
	ULONG  HardResetCount;
	ULONG  WorkerSignalCount;
	ULONG  CommonBufferBytes;
	ULONG  WorkerIdleTimeMs;
	BOOLEAN  RootHubEnabled;
	UCHAR  RootHubDevicePowerState;
	UCHAR  Unused;
	UCHAR  NameIndex;
} USB_BUS_STATISTICS_0, *PUSB_BUS_STATISTICS_0;

typedef struct _USBUSER_BUS_STATISTICS_0_REQUEST {
	USBUSER_REQUEST_HEADER  Header;
	USB_BUS_STATISTICS_0  BusStatistics0;
} USBUSER_BUS_STATISTICS_0_REQUEST, *PUSBUSER_BUS_STATISTICS_0_REQUEST;

/* USB_CONTROLLER_INFO_0.HcFeatureFlags constants */
#define USB_HC_FEATURE_FLAG_PORT_POWER_SWITCHING  0x00000001
#define USB_HC_FEATURE_FLAG_SEL_SUSPEND           0x00000002
#define USB_HC_FEATURE_LEGACY_BIOS                0x00000004

typedef struct _USB_CLOSE_RAW_DEVICE_PARAMETERS {
  ULONG  xxx;
} USB_CLOSE_RAW_DEVICE_PARAMETERS , *PUSB_CLOSE_RAW_DEVICE_PARAMETERS;

typedef struct _USBUSER_CLOSE_RAW_DEVICE {
	USBUSER_REQUEST_HEADER  Header;
	USB_CLOSE_RAW_DEVICE_PARAMETERS  Parameters;
} USBUSER_CLOSE_RAW_DEVICE, *PUSBUSER_CLOSE_RAW_DEVICE;

typedef struct _USB_CONTROLLER_INFO_0 {
  ULONG  PciVendorId;
  ULONG  PciDeviceId;
  ULONG  PciRevision;
  ULONG  NumberOfRootPorts;
  USB_CONTROLLER_FLAVOR  ControllerFlavor;
  ULONG  HcFeatureFlags;
} USB_CONTROLLER_INFO_0 , *PUSB_CONTROLLER_INFO_0;

typedef struct _USBUSER_CONTROLLER_INFO_0 {
  USBUSER_REQUEST_HEADER  Header;
  USB_CONTROLLER_INFO_0  Info0;    
} USBUSER_CONTROLLER_INFO_0, *PUSBUSER_CONTROLLER_INFO_0;

typedef struct _USB_DRIVER_VERSION_PARAMETERS {
	ULONG  DriverTrackingCode;
	ULONG  USBDI_Version;
	ULONG  USBUSER_Version;
	BOOLEAN  CheckedPortDriver;
	BOOLEAN  CheckedMiniportDriver;
	USHORT  USB_Version;
} USB_DRIVER_VERSION_PARAMETERS , *PUSB_DRIVER_VERSION_PARAMETERS;

typedef struct _USBUSER_GET_DRIVER_VERSION {
	USBUSER_REQUEST_HEADER  Header;
	USB_DRIVER_VERSION_PARAMETERS  Parameters;    
} USBUSER_GET_DRIVER_VERSION, *PUSBUSER_GET_DRIVER_VERSION;

typedef struct _USB_OPEN_RAW_DEVICE_PARAMETERS {
	USHORT  PortStatus;
	USHORT  MaxPacketEp0;
} USB_OPEN_RAW_DEVICE_PARAMETERS , *PUSB_OPEN_RAW_DEVICE_PARAMETERS;

typedef struct _USBUSER_OPEN_RAW_DEVICE {
	USBUSER_REQUEST_HEADER  Header;
	USB_OPEN_RAW_DEVICE_PARAMETERS  Parameters;    
} USBUSER_OPEN_RAW_DEVICE, *PUSBUSER_OPEN_RAW_DEVICE;

typedef enum _WDMUSB_POWER_STATE {
	WdmUsbPowerNotMapped = 0,
	WdmUsbPowerSystemUnspecified = 100,
	WdmUsbPowerSystemWorking,
	WdmUsbPowerSystemSleeping1,
	WdmUsbPowerSystemSleeping2,
	WdmUsbPowerSystemSleeping3,
	WdmUsbPowerSystemHibernate,
	WdmUsbPowerSystemShutdown,
	WdmUsbPowerDeviceUnspecified = 200,
	WdmUsbPowerDeviceD0,
	WdmUsbPowerDeviceD1,
	WdmUsbPowerDeviceD2,
	WdmUsbPowerDeviceD3
} WDMUSB_POWER_STATE;

typedef struct _USB_POWER_INFO {
	WDMUSB_POWER_STATE  SystemState;
	WDMUSB_POWER_STATE  HcDevicePowerState;
	WDMUSB_POWER_STATE  HcDeviceWake;
	WDMUSB_POWER_STATE  HcSystemWake; 
	WDMUSB_POWER_STATE  RhDevicePowerState;
	WDMUSB_POWER_STATE  RhDeviceWake;
	WDMUSB_POWER_STATE  RhSystemWake; 
	WDMUSB_POWER_STATE  LastSystemSleepState; 
	BOOLEAN  CanWakeup;
	BOOLEAN  IsPowered;
} USB_POWER_INFO, *PUSB_POWER_INFO;

typedef struct _USBUSER_POWER_INFO_REQUEST {
	USBUSER_REQUEST_HEADER  Header;
	USB_POWER_INFO  PowerInformation;
} USBUSER_POWER_INFO_REQUEST, *PUSBUSER_POWER_INFO_REQUEST;

typedef struct _USB_UNICODE_NAME {
	ULONG  Length;
	WCHAR  String[1];
} USB_UNICODE_NAME, *PUSB_UNICODE_NAME;

typedef struct _USBUSER_CONTROLLER_UNICODE_NAME {
	USBUSER_REQUEST_HEADER  Header;
  USB_UNICODE_NAME  UnicodeName;
} USBUSER_CONTROLLER_UNICODE_NAME, *PUSBUSER_CONTROLLER_UNICODE_NAME;

typedef struct _USB_PASS_THRU_PARAMETERS {
	GUID  FunctionGUID;
	ULONG  ParameterLength;
	UCHAR  Parameters[4];
} USB_PASS_THRU_PARAMETERS, *PUSB_PASS_THRU_PARAMETERS;

typedef struct _USBUSER_PASS_THRU_REQUEST {
	USBUSER_REQUEST_HEADER  Header;
	USB_PASS_THRU_PARAMETERS  PassThru;
} USBUSER_PASS_THRU_REQUEST, *PUSBUSER_PASS_THRU_REQUEST;

typedef struct _USBUSER_RAW_RESET_ROOT_PORT {
	USBUSER_REQUEST_HEADER  Header;
	RAW_RESET_PORT_PARAMETERS  Parameters;
} USBUSER_RAW_RESET_ROOT_PORT, *PUSBUSER_RAW_RESET_ROOT_PORT;

typedef struct _USBUSER_SEND_ONE_PACKET {
	USBUSER_REQUEST_HEADER  Header;
	PACKET_PARAMETERS  PacketParameters;
} USBUSER_SEND_ONE_PACKET, *PUSBUSER_SEND_ONE_PACKET;

typedef struct _USB_SEND_RAW_COMMAND_PARAMETERS {
	UCHAR  Usb_bmRequest;
	UCHAR  Usb_bRequest;
	USHORT  Usb_wVlaue;
	USHORT  Usb_wIndex;
	USHORT  Usb_wLength;
	USHORT  DeviceAddress;
	USHORT  MaximumPacketSize;
	ULONG  Timeout;
	ULONG  DataLength;
	USBD_STATUS  UsbdStatusCode;
	UCHAR  Data[4];
} USB_SEND_RAW_COMMAND_PARAMETERS, *PUSB_SEND_RAW_COMMAND_PARAMETERS;

typedef struct _USBUSER_SEND_RAW_COMMAND {
	USBUSER_REQUEST_HEADER  Header;
	USB_SEND_RAW_COMMAND_PARAMETERS  Parameters;
} USBUSER_SEND_RAW_COMMAND, *PUSBUSER_SEND_RAW_COMMAND;

/* USB_USB2HW_VERSION_PARAMETERS.Usb2HwRevision constants */
#define USB2HW_UNKNOWN                    0x00
#define USB2HW_A0                         0xA0
#define USB2HW_A1                         0xA1
#define USB2HW_B0                         0xB0

typedef struct _USB_USB2HW_VERSION_PARAMETERS {
  UCHAR  Usb2HwRevision;
} USB_USB2HW_VERSION_PARAMETERS, *PUSB_USB2HW_VERSION_PARAMETERS;

typedef struct _USBUSER_GET_USB2HW_VERSION {
	USBUSER_REQUEST_HEADER  Header;
	USB_USB2HW_VERSION_PARAMETERS  Parameters;
} USBUSER_GET_USB2HW_VERSION, *PUSBUSER_GET_USB2HW_VERSION;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* __USBUSER_H */
