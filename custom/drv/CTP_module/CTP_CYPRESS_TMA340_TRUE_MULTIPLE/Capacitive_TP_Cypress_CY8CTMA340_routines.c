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
 *   Capacitive_TP_Cypress_CY8CTMA340_routines.c
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel ISSP firmware update Driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "dcl.h"
#include "Capacitive_TP_Cypress_CY8CTMA340_defs.h"
#include "Capacitive_TP_Cypress_CY8CTMA340_vectors.h"
#include "Capacitive_TP_Cypress_CY8CTMA340_directives.h"
#include "us_timer.h"
#include "drv_comm.h"
#include "fs_func.h"
#include "Capacitive_TP_trc.h"


void ctp_cypress_udelay(kal_uint32 delay)
{
}

void ctp_cypress_msleep(kal_uint32 delay)
{}

int ctp_cypress_load_program_data(FS_HANDLE fp, unsigned char bank_num, unsigned char block_num)
{return 0;}

int ctp_cypress_load_security_data(FS_HANDLE fp, unsigned char bank_num)
{return 0;}

// ============================================================================
// Description: 
// Run Clock without sending/receiving bits. Use this when transitioning from 
// write to read and read to write "num_cycles" is number of SCLK cycles, not
// number of counter cycles.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// ============================================================================
void ctp_cypress_run_clock(unsigned int num_cycles)
{}

// ============================================================================
// Clocks the SCLK pin (high-low-high) and reads the status of the SDATA pin
// after the rising edge.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// Returns:
//	 0 if SDATA was low
//	 1 if SDATA was high
// ============================================================================
unsigned char ctp_cypress_receive_bit(void)
{return 0;}		  

// ============================================================================
// Calls ReceiveBit 8 times to receive one byte.
// Returns:
//	 The 8-bit values recieved.
// ============================================================================
unsigned char ctp_cypress_receive_byte(void)
{return 0;}		  

// ============================================================================
// This routine sends up to one byte of a vector, one bit at a time.
//	bCurrByte   the byte that contains the bits to be sent.
//	bSize	   the number of bits to be sent. Valid values are 1 to 8.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
// ============================================================================
void ctp_cypress_send_byte(unsigned char curr_byte, unsigned char size)
{}

// ============================================================================
// SendVector()
// This routine sends the vector specifed. All vectors constant strings found
// in ISSP_Vectors.h.  The data line is returned to HiZ after the vector is
// sent.
//	bVect	  a pointer to the vector to be sent.
//	nNumBits   the number of bits to be sent.
//	bCurrByte  scratch var to keep the byte to be sent.
//
// There is no returned value.
// ============================================================================
void ctp_cypress_send_vector(const unsigned char* vect, unsigned int num_bits)
{}


// ============================================================================
// Waits for transition from SDATA = 1 to SDATA = 0.  Has a 100 msec timeout.
// TRANSITION_TIMEOUT is a loop counter for a 100msec timeout when waiting for
// a high-to-low transition. This is used in the polling loop of 
// fDetectHiLoTransition(). The timing of the while(1) loops can be calculated
// and the number of loops is counted, using iTimer, to determine when 100 
// msec has passed.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some 
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency 
// of SCLK should be measured as part of validation of the final program
//
// Returns:
//	 0 if successful
//	-1 if timed out.
// ============================================================================
signed char ctp_cypress_detect_hi_lo_transition(void)
{return 0;}

kal_uint32 ctp_wait_reset_stable = 10;
int ctp_cypress_initialize(void)
{return 0;}

int ctp_cypress_verify_id(void)
{return 0;}

int ctp_cypress_read_status(void)
{return 0;}

int ctp_cypress_erase_target(void)
{return 0;}

// ============================================================================
// Transfers data from array in Host to RAM buffer in the target.
// Returns the checksum of the data.
// ============================================================================
unsigned int ctp_cypress_load_target(void)
{return 0;}

// ============================================================================
// Program one block with data that has been loaded into a RAM buffer in the 
// target device.
// ============================================================================
int ctp_cypress_program_target_block(unsigned char bBankNumber, unsigned char bBlockNumber)
{return 0;}

// ============================================================================
// Reads and adds the target bank checksum to the referenced accumulator.
// ============================================================================
int ctp_cypress_target_bank_checksum(unsigned int* acc)
{return 0;}	


// ============================================================================
// After programming, the target PSoC must be reset to take it out of 
// programming mode. This routine performs a reset.
// ============================================================================
void ctp_cypress_restart_target(void)
{}

// ============================================================================
// Verify the block just written to. This can be done byte-by-byte before the
// protection bits are set.
// ============================================================================
int ctp_cypress_verify_setup(unsigned char bank_number, unsigned char block_number)
{return 0;}

// ============================================================================
// Reads the data back from Target SRAM and compares it to expected data in
// Host SRAM
// ============================================================================
int ctp_cypress_read_byte_loop(void)
{return 0;}

// ============================================================================
// Before calling, load the array, abTargetDataOUT, with the desired security
// settings using LoadArrayWithSecurityData(StartAddress,Length,SecurityType).
// The can be called multiple times with different SecurityTypes as needed for
// particular Flash Blocks. Or set them all the same using the call below:
// LoadArrayWithSecurityData(0,SECURITY_BYTES_PER_BANK, 0); 
// ============================================================================
int ctp_cypress_secure_target_flash(void)
{return 0;}

// ============================================================================
// This step is optional. Verifies that the security bits have been written correctly
// ============================================================================
int ctp_cypress_verify_security(void)
{return 0;}
