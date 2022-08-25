;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*******************************************************************************
; * Filename:
; * ---------
; *  arm_unaligned.s
; *
; * Project:
; * --------
; *  MAUI
; *
; * Description:
; * ------------
; *
; *
; * Author:
; * -------
; * -------
; *
; *==============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!

    ; make sure the following test passed:
    ;  compile by ADS1.2
    ;  compile by RVCT2.2, link 
    ;  compile by RVCT3.1, link

    CODE32
    REQUIRE8
    PRESERVE8
     
    ; retarget __aeabi_memcpy
    ; __rt_memcpy is kept for backwards compatibility with ADS
    ; _memcpy_lastbytes is kept for backwards compatibility with RVCT2.2
    ; prototype
    ;  void __aeabi_memcpy(void *dest, const void *src, size_t n);
    
    ; put memcpy in INTSRAM on ARM7 nor flash platform
    IF :DEF: MT6223 :LOR: :DEF: MT6223P :LOR: :DEF: MT6225 :LOR: :DEF: MT6253 :LOR: :DEF: MT6253D :LOR: :DEF: MT6253T
    AREA |INTSRAM_ROCODE|,CODE
    ELSE
    AREA |i.memcpy|,CODE
    ENDIF ; MT6223 || MT6223P || MT6225 || MT6253 || MT6253D || MT6253T
    EXPORT __aeabi_memcpy
    EXPORT __rt_memcpy
    ;EXPORT _memcpy_lastbytes

__aeabi_memcpy PROC
__rt_memcpy
    ; r0=dest, r1=src, r2=length
    CMP     r2, #3              ; if (length < 4) goto _memcpy_lastbytes
    BLS     _memcpy2_memcpy_lastbytes   
    ANDS    r12, r0, #3         ; if (dest % 4 == 0) goto dest_aligned
    BEQ     _memcpy2_dest_aligned        
    ;; storing to dest tail, make dest aligned
    LDRB    r3, [r1], #1
    CMP     r12, #2
    ADD     r2, r2, r12
    LDRLSB  r12, [r1], #1
    STRB    r3, [r0], #1
    LDRCCB  r3, [r1], #1
    STRLSB  r12, [r0], #1
    SUB     r2, r2, #4
    STRCCB  r3, [r0], #1
_memcpy2_dest_aligned
    ANDS    r3, r1, #3          ; if (src % 4 == 0) goto memcpy_burst
    BEQ     memcpy_burst
_memcpy2_src_not_aligned
    SUBS    r2, r2, #4          ; if (length < 4) goto _memcpy_lastbytes; because _memcpy_lastbytes just use last 2 bits, 
                                ; so we don't need to add 4 to r2 in order to restore it
    BCC     _memcpy2_memcpy_lastbytes 
    LDR     r12, [r1, -r3]!
    CMP     r3, #2              ; if (src % 4 == 1) goto src_mod4_1
    BEQ     _memcpy2_src_mod4_2          ; if (src % 4 == 2) goto src_mod4_2
    BHI     _memcpy2_src_mod4_3          ; if (src % 4 == 3) goto src_mod4_3
_memcpy2_src_mod4_1
    MOV     r3, r12, LSR #8
    LDR     r12, [r1, #4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSL #24
    STR     r3, [r0], #4
    BCS     _memcpy2_src_mod4_1
    ADD     r1, r1, #1
    B       _memcpy2_memcpy_lastbytes
_memcpy2_src_mod4_2
    MOV     r3, r12, LSR #16
    LDR     r12, [r1, #4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSL #16
    STR     r3, [r0], #4
    BCS     _memcpy2_src_mod4_2
    ADD     r1, r1, #2
    B       _memcpy2_memcpy_lastbytes
_memcpy2_src_mod4_3
    MOV     r3, r12, LSR #24
    LDR     r12, [r1, #4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSL #8
    STR     r3, [r0], #4
    BCS     _memcpy2_src_mod4_3
    ADD     r1, r1, #3
    ;;;;B       _memcpy_lastbytes ;;;; directly fallback
_memcpy2_memcpy_lastbytes
    ;; copy from r0=src to r1=dest, r2=length <= 3
    MOVS     r2, r2, LSL #31     ; if (length == 1) C = 0; N = 1; if (length == 2) C = 1; N = 0; if (length == 3) C = 1; N = 1;
    LDRCSB  r3, [r1], #1    ; if (C == 1) ldrb  ; execute when length == 2 or 3
    LDRCSB  r12, [r1], #1   ; if (C == 1) ldrb  ; execute when length == 2 or 3
    LDRMIB  r2, [r1], #1    ; if (N == 1) ldrb  ; execute when length == 1 or 3
    STRCSB  r3, [r0], #1    ; if (C == 1) strb  
    STRCSB  r12, [r0], #1   ; if (C == 1) strb
    STRMIB  r2, [r0], #1    ; if (C == 1) strb
    BX lr
    ENDP
    
    EXPORT __aeabi_memcpy4
memcpy_burst PROC
__aeabi_memcpy4
    CMP     r2,#0x20            ; if (length >= 32)
    STMCSDB r13!,{r4-r8,r14}    ; push six registers
    STMCCDB r13!,{r4,r14}       ; else push two registers

    ;; long burst or short burst
    SUBS    r2,r2,#0x20
    BCC     _memcpy4_lastbytes_short
_memcpy4_burst_long
    ;; burst-8
    LDMCSIA r1!,{r3-r8,r12,r14} ; (4x8) bytes
    STMCSIA r0!,{r3-r8,r12,r14}
    SUBCSS  r2,r2,#0x20
    BCS     _memcpy4_burst_long
    
_memcpy4_lastbytes_long    
    MOVS    r12,r2,lsl #0x1C
    LDMCSIA r1!,{r3-r4,r12,r14} ; (4x4) bytes
    STMCSIA r0!,{r3-r4,r12,r14}
    LDMMIIA r1!,{r3-r4}         ; (4x2) bytes
    STMMIIA r0!,{r3-r4}
    LDMIA   r13!,{r4-r8,r14}    ; pop six registers
    MOVS    r12,r2,lsl #0x1E
    LDRCS   r3,[r1],#0x4        ; 4 bytes
    STRCS   r3,[r0],#0x4
    BXEQ    lr
    B       _memcpy_lastbytes_aligned
    
_memcpy4_lastbytes_short
    MOVS    r12,r2,lsl #0x1C
    LDMCSIA r1!,{r3-r4,r12,r14} ; (4x4) bytes
    STMCSIA r0!,{r3-r4,r12,r14}
    LDMMIIA r1!,{r3-r4}         ; (4x2) bytes
    STMMIIA r0!,{r3-r4}
    LDMIA   r13!,{r4,r14}       ; pop two registers
    MOVS    r12,r2,lsl #0x1E
    LDRCS   r3,[r1],#0x4        ; 4 bytes
    STRCS   r3,[r0],#0x4
    BXEQ    lr
    
_memcpy_lastbytes_aligned
    MOVS    r2,r2,lsl #0x1F
    LDRCSH  r3,[r1],#0x2    ; 2 bytes
    LDRMIB  r2,[r1],#0x1    ; 1 byte
    STRCSH  r3,[r0],#0x2
    STRMIB  r2,[r0],#0x1
    BX      lr
    
    ; retarget __aeabi_memmove
    ; __rt_memmove is kept for backwards compatibility with ADS
    ; __memmove_lastfew is kept for backwards compatibility with RVCT2.2
    ; prototype
    ;  void __aeabi_memmove(void *dest, const void *src, size_t n);
    
    AREA |i.memmove|,CODE
    EXPORT __aeabi_memmove
    EXPORT __rt_memmove
    ;EXPORT __memmove_lastfew
    IMPORT __memmove_aligned
__aeabi_memmove PROC
__rt_memmove
    ; r0=dest, r1=src, r2=length
    SUBS    r3, r0, r1      ; r3 = r0 - r1
    CMPCS   r2, r3          ; if (dest <= src || length <= (dest - src)) call_memcpy();
    BLS     __aeabi_memcpy 
    CMP     r2, #3
    ADD     r0, r0, r2
    ADD     r1, r1, r2
    BLS     __memmove_lastfew
memmove_make_dest_aligned
    TST     r0, #3
    LDRNEB  r3, [r1, #-1]!
    SUBNE   r2, r2, #1
    STRNEB  r3, [r0, #-1]!
    TST     r0, #3
    BNE     memmove_make_dest_aligned
memmove_dest_aligned
    ANDS    r3, r1, #3
    BEQ     __memmove_aligned
memmove_src_not_aligned
    SUBS    r2, r2, #4
    BCC     __memmove_lastfew
    LDR     r12, [r1, -r3]!
    CMP     r3, #2
    BCC     memmove_src_mod4_1
    BHI     memmove_src_mod4_3
memmove_src_mod4_2
    MOV     r3, r12, LSL #16
    LDR     r12, [r1, #-4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSR #16
    STR     r3, [r0, #-4]!
    BCS     memmove_src_mod4_2
    ADD     r1, r1, #2
    B       __memmove_lastfew
memmove_src_mod4_1
    MOV     r3, r12, LSL #24
    LDR     r12, [r1, #-4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSR #8
    STR     r3, [r0, #-4]!
    BCS     memmove_src_mod4_1
    ADD     r1, r1, #1
    B       __memmove_lastfew
memmove_src_mod4_3
    MOV     r3, r12, LSL #8
    LDR     r12, [r1, #-4]!
    SUBS    r2, r2, #4
    ORR     r3, r3, r12, LSR #24
    STR     r3, [r0, #-4]!
    BCS     memmove_src_mod4_3
    ADD     r1, r1, #3
    ;;B       __memmove_lastfew
__memmove_lastfew
    MOVS    r2, r2, LSL #31
    LDRCSB  r3, [r1, #-1]!
    LDRCSB  r12, [r1, #-1]!
    LDRMIB  r2, [r1, #-1]
    STRCSB  r3, [r0, #-1]!
    STRCSB  r12, [r0, #-1]!
    STRMIB  r2, [r0, #-1]
    BX      lr
    ENDP
    
    
    ; retarget strcmp
    ; prototype
    ;  extern _ARMABI int strcmp(const char * /*s1*/, const char * /*s2*/);
    
    AREA |i.strcmp|,CODE
    EXPORT strcmp
strcmp PROC
    ; r0=s1, r1=s2
    TST     r0, #3
    TSTEQ   r1, #3
    BNE     src_or_dest_notalign
    STMFD   sp!, {lr}           ; push lr on stack
    LDR     lr, SUBA
src_and_dest_align
strcmp_nextword1
    LDR     r2, [r0], #4
    LDR     r3, [r1], #4
    SUB     r12, r2, lr         ; r12 = hasZeroByte(v) = (v - 0x01010101) & ~v & 0x80808080
    BIC     r12, r12, r2
    ANDS    r12, r12, lr, LSL #7 ; lr, LSL #7 => 0x80808080
    CMPEQ   r2, r3              ; if (hasZeroByte(r2) == 0) then compare r2 & r3
    BNE     zero_or_inequal_detected
strcmp_nextword2
    LDR     r2, [r0], #4
    LDR     r3, [r1], #4
    SUB     r12, r2, lr         ; r12 = hasZeroByte(v) = (v - 0x01010101) & ~v & 0x80808080
    BIC     r12, r12, r2
    ANDS    r12, r12, lr, LSL #7 ; lr, LSL #7 => 0x80808080
    CMPEQ   r2, r3              ; if (hasZeroByte(r2) == 0) then compare r2 & r3
    BEQ     strcmp_nextword1
zero_or_inequal_detected
    LDMFD   sp!, {lr}           ; pop lr from stack
    ;; compare the tail
    MOV     r0, r3, LSL #24
    SUBS    r0, r0, r2, LSL #24
    TSTEQ   r12, #0xff0         ; if *s1 == 0, then r12(0xXXXXXX80) & 0xff0 = 0x80
                                ; because last 8 bits in r12 is 0x80, TST 0xff is ok? why use 0xff0 here?
                                ; because we want to clear the 'C' flag set by previous instruction
    BNE     strcmp_last0
    MOV     r0, r3, LSL #16
    SUBS    r0, r0, r2, LSL #16
    TSTEQ   r12, #0xff00        ; if *(s1 + 1) == 0, then r12 & 0xff00 = 0x80xx
    BNE     strcmp_last0
    MOV     r0, r3, LSL #8
    SUBS    r0, r0, r2, LSL #8
    TSTEQ   r12, #0xff0000      ; if *(s1 + 2) == 0, then r12 & 0xff00000 = 0x80xxxx
    SUBEQS  r0, r3, r2
strcmp_last0
    MOVNE   r0, r0, RRX
    BX      lr
SUBA
    DCD     0x01010101
src_or_dest_notalign
strcmp_next_pair
    LDRB    r2, [r0], #1    ; r2 = *s1
    LDRB    r3, [r1], #1    ; r3 = *s2
    CMP     r2, #1          ; if r2(*s1) is 0, then r2(*s2) is not equal to 1, so goto strcmp_last. (CMPCS is bypass)
    CMPCS   r2, r3          ; if r2(*s1) >= 1, then compare *s1 with *s2, if not equal goto strcmp_last
    BNE     strcmp_last
    LDRB    r2, [r0], #1
    LDRB    r3, [r1], #1
    CMP     r2, #1          ; same as above
    CMPCS   r2, r3
    BEQ     strcmp_next_pair ; if (*s1 != 0 && *s1 == *s2) goto strcmp_next_pair
strcmp_last
    SUB     r0, r2, r3
    BX      lr
    
    ENDP


; * removed!
; * removed!
; * removed!
    EXPORT memset
memset PROC
    AND     r3,r1,#0xFF
    MOV     r1,r2
    STMDB   r13!,{r0,r14}
    ORR     r2,r3,r3,lsl #0x8
    ORR     r2,r2,r2,lsl #0x10
    BL      _memset_8
    LDMIA   r13!,{r0,r14}
    BX      r14
    
    ENDP

    EXPORT __aeabi_memset
__aeabi_memset PROC
    AND     r3,r2,#0xFF
    ORR     r2,r3,r3,lsl #0x8
    ORR     r2,r2,r2,lsl #0x10
    B       _memset_8
    ENDP
    
    EXPORT __aeabi_memclr
    EXPORT __rt_memclr
__aeabi_memclr PROC
__rt_memclr    
    MOV     r2,#0x0
_memset_8                      ;r0=>Target address, r1=>size(4-byte aligned), r2=>Store value
    CMP     r1,#0x4                 
    BCC     _memset_8_last_bytes    
    ANDS    r12,r0,#0x3
    BEQ     _memset_w_8             ;If size >= 4 and address aligned 4-byte, goto memset_w
    RSB     r12,r12,#0x4            ;Else Store 1 ~ 3 bytes to make address align 4-byte
    CMP     r12,#0x2
    STRNEB  r2,[r0],#0x1
    SUB     r1,r1,r12
    STRGEH  r2,[r0],#0x2
    B       _memset_w_8             ;Finally goto memset_w
_memset_8_last_bytes                ;If size < 4, use STRB store 1 ~ 3 bytes
    MOVS    r12,r1,lsl #0x1F
    STRCSB  r2,[r0],#0x1
    STRCSB  r2,[r0],#0x1
    STRMIB  r2,[r0],#0x1
    BX      r14
    
    ENDP

; * removed!
    EXPORT __aeabi_memclr4
    EXPORT __aeabi_memclr8
    EXPORT __rt_memclr_w
__aeabi_memclr4 PROC
__aeabi_memclr8
__rt_memclr_w 
    MOV     r2,#0x0
_memset_w_8                       ;r0=>Target address, r1=>size(4-byte aligned), r2=>Store value
    STMDB   r13!,{r14}
    MOV     r3,r2
    MOV     r12,r2
    MOV     r14,r2
    SUBS    r1,r1,#0x20
    BCC     _memset_w_8_last_bytes
    STMDB   r13!,{r4-r7}            ;If size >= 32, push 4 extra registers
    MOV     r4,r2
    MOV     r5,r2
    MOV     r6,r2
    MOV     r7,r2
_memset_w_8_store_32
    STMIA   r0!,{r2-r7,r12,r14}     ;And issue STM8 (longest possible data transaction)
    SUBS    r1,r1,#0x20
    BCS     _memset_w_8_store_32
    LDMIA   r13!,{r4-r7}
_memset_w_8_last_bytes              ;Last 1 ~ 31 bytes process
    MOVS    r1,r1,lsl #0x1C
    STMCSIA r0!,{r2-r3,r12,r14}     ;Store 16bytes
    STMMIIA r0!,{r2-r3}             ;Store 8bytes
    LDMIA   r13!,{r14}
    MOVS    r1,r1,lsl #0x2          
    STRCS   r2,[r0],#0x4            ;Store 4bytes
    BXEQ    r14
    STRMIH  r2,[r0],#0x2            ;Store 2bytes
    TST     r1,#0x40000000
    STRNEB  r2,[r0],#0x1            ;Store 1byte
    BX      r14

    ENDP

; * removed!
    EXPORT  INT_set_sp
INT_set_sp
	  MOV sp,r0
	  bx lr
    END
