/*******************************************************************************
 * 
 * Filename:
 * ---------
 *	btdrv_config.h
 *
 * Project:
 * --------
 *   MAUI MTK Bluetooth Chip
 *
 * Description:
 * ------------
 *   This file contains defined configures which are both used in bt driver and bt stack
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 * 				HISTORY
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef BTDRV_CONFIG_H
#define BTDRV_CONFIG_H


/*****************************************************************/
/*******************        config.h       *******************************/
/*****************************************************************/

#define XA_DISABLED 0   /* Disable the feature */
#define XA_ENABLED  1   /* Enable the feature */

#ifndef XA_INTEGER_SIZE
/*---------------------------------------------------------------------------
 * XA_INTEGER_SIZE constant
 *
 *     Defines the preferred width of counter variables. In some systems,
 *     accesses to 2- or 4-byte variables is more time efficient than other
 *     sizes, even though they may take up more RAM. The stack attempts to
 *     honor this preference, except where a greater size is required.
 *
 *     For instance, if XA_INTEGER_SIZE is defined as 2, 8-bit and 16-bit
 *     counters will both be defined as 16-bit variables.
 *
 *     XA_INTEGER_SIZE may be 1, 2, or 4 and will affect the definition
 *     of I8, I16 types used internally by the stack. By default, 2-byte
 *     integers are preferred.
 */
#define XA_INTEGER_SIZE    2
#endif /* XA_INTEGER_SIZE */

#ifndef XA_DEBUG
#if defined(XADEBUG) || defined(_DEBUG)
/*---------------------------------------------------------------------------
 * XA_DEBUG constant
 *
 *     When XA_DEBUG is enabled, debugging code is enabled throughout the
 *     stack, including OS_Report and OS_Assert calls and other code
 *     that verifies the proper behavior of the stack at run-time.
 *
 *     When XA_DEBUG is disabled, debugging code is not compiled into the
 *     stack. Asserts and diagnostic output are removed. This results
 *     in a significant code size savings.
 *
 *     You can specify the XA_DEBUG setting in the overide.h file. If it is
 *     not specified there, XA_DEBUG depends on the XADEBUG or _DEBUG
 *     constants defined at compile time. If XADEBUG or _DEBUG constants are
 *     defined, XA_DEBUG will be enabled. If the constants are not defined,
 *     XA_DEBUG will be disabled.
 */
#define XA_DEBUG XA_DISABLED
#else /* defined(XADEBUG) || defined(_DEBUG) */
#define XA_DEBUG XA_DISABLED
#endif /* defined(XADEBUG) || defined(_DEBUG) */
#endif /* XA_DEBUG */

#ifndef XA_STATISTICS
/*---------------------------------------------------------------------------
 * XA_STATISTICS constant
 *
 *     Controls internal statistics-gathering macros. When enabled,
 *     certain stack components keep track of resource usage and timing.
 *     To extract this information, a module in your system must include
 *     /inc/sys/btstats.h and call BTSTAT_Report, which will send a
 *     set of statistics to debug output.
 *
 *     For more information about the meaning of each statistic, see
 *     the Blue SDK Implementer's Guide.
 *
 *     By default, statistics-gathering is disabled to save code size.
 *     
 * Requires:
 *     XA_DEBUG enabled.
 */
#define XA_STATISTICS   XA_DISABLED
#endif /* XA_STATISTICS */ 

#if XA_DEBUG == XA_DISABLED
#undef XA_STATISTICS
#define XA_STATISTICS   XA_DISABLED
#endif /* XA_DEBUG == XA_DISABLED */ 



/*****************************************************************/
/***********************  btconfig.h  *******************************/
/*****************************************************************/

/*---------------------------------------------------------------------------
 * L2CAP_FLOW_CONTROL constant
 *
 *     Enables support for L2CAP Flow Control and Retransmission modes as
 *     introduced in Bluetooth v1.2. When enabled, an L2CAP user is able to
 *     configure L2CAP connections to include support for retransmission
 *     of lost frames, SDU segmentation and reassembly and the detection of
 *     errored frames.
 *
 *     By default this option is disabled, which results in a code size 
 *     savings. This option should be enabled if L2CAP based protocols or 
 *     profiles are used which depend on this feature.
 */
 
#ifndef L2CAP_FLOW_NON_BASIC_MODE
#define L2CAP_FLOW_NON_BASIC_MODE      XA_ENABLED
#endif
    


/*---------------------------------------------------------------------------
 * BT_PACKET_HEADER_LEN constant
 *
 *     The BT_PACKET_HEADER_LEN constant is the size of the BtPacket header.
 *     The default size is the max(L2CAP) header size (8 bytes), plus the
 *     max(RFCOMM,SDP,TCS) header size (6 bytes). If BNEP is used, you must
 *     increase the BT_PACKET_HEADER_LEN by 5 bytes: (8+6+5) in your config
 *     overide file.
 */


#ifndef BT_PACKET_HEADER_LEN

#ifdef __BT_BNEP__
#define BT_PACKET_HEADER_LEN (8+6+5)
#elif defined(__BT_4_0_BLE__)
#define BT_PACKET_HEADER_LEN (12+6)
#elif L2CAP_FLOW_NON_BASIC_MODE== XA_DISABLED
#define BT_PACKET_HEADER_LEN (8+6)
#else
#define BT_PACKET_HEADER_LEN (8+6+2)
#endif

#endif

#if BT_PACKET_HEADER_LEN < 14 || BT_PACKET_HEADER_LEN > 255
#error BT_PACKET_HEADER_LEN must be greater than 13 and less than 256
#endif 




/*---------------------------------------------------------------------------
 * HCI_CMD_PARM_LEN constant
 *
 *     Represents the largest size allowed for HCI command parameters.
 *
 *     The default command parameter length is 248.
 */
#ifndef HCI_CMD_PARM_LEN
#define HCI_CMD_PARM_LEN 248
#endif 

/*
 * The longest known HCI command is 248 bytes at this time.
 */
#if HCI_CMD_PARM_LEN < 248
#error HCI_CMD_PARM_LEN must be at least 248
#endif 

#if 1
#define MTK_BT_DEBUG_TRACE
#endif 


#endif //BTDRV_CONFIG_H
 
