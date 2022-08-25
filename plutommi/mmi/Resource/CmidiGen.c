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

/*******************************************************************************
 * Filename:
 * ---------
 *  CmidiGen.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


// Audio_Converter.cpp : Defines the entry point for the DLL application.
//
//#define LOCALSIM
#ifdef LOCALSIM
#include "..\inc\CmidiGen.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#else
#include "CmidiGen.h"
#endif

#include "CustDataProts.h"
#include "ResgenLogCAPI.h"

#define CMIDIGEN_TAG       "CMIDIGEN"
#define CMIDIGEN_LOG_D(format, args...) RES_LOG_D((CMIDIGEN_TAG), (format) , ##args)
#define CMIDIGEN_LOG_V(format, args...) RES_LOG_V((CMIDIGEN_TAG), (format) , ##args)
#define CMIDIGEN_LOG_W(format, args...) RES_LOG_W((CMIDIGEN_TAG), (format) , ##args)
#define CMIDIGEN_LOG_E(format, args...) RES_LOG_E((CMIDIGEN_TAG), (format) , ##args)

#ifdef LOCALSIM
#define TRACE1(s,t)  \
   if( ihdl->debug ) { \
      printf(s, t * ihdl->time_div );    \
   }

#define TRACE2(s,t,a)     \
   if( ihdl->debug ) { \
      printf(s, t * ihdl->time_div, a );  \
   }

#define TRACE3(s,t,a,b)    \
   if( ihdl->debug ) { \
      printf(s, t * ihdl->time_div, a, b );  \
   }

#define TRACE4(s,t,a,b,c)    \
   if( ihdl->debug ) { \
      printf(s, t * ihdl->time_div, a, b, c );  \
   }
#else    /* CMIDI_STANDALONE */
#define TRACE1(s,t) 
#define TRACE2(s,t,a)
#define TRACE3(s,t,a,b) 
#define TRACE4(s,t,a,b,c) 
#endif


#ifndef ASSERT
#define ASSERT(expr) 
#endif


#ifndef NULL
#define NULL (void*)0
#endif

typedef unsigned char            c_uint8;
typedef signed char              c_int8;
typedef unsigned short           c_uint16;
typedef signed short             c_int16;
typedef unsigned int             c_uint32;
typedef signed int               c_int32;
#define TRUE           1
#define FALSE          0

#define MAX_TRACK                32
//#define ASSERT                   assert
#define VOLUME_QUANTIZE
#define MAX_MIDI_EVENTS          19
#define BLOCK_PERIOD             18


#define ME_DTIME                 0
#define ME_NOTEON                1
#define ME_NOTEOFF               2
#define ME_KEY_PRESSURE          3
#define ME_MAINVOLUME            4
#define ME_PAN                   5
#define ME_SUSTAIN               6
#define ME_EXPRESSION            7
#define ME_PITCH_WHEEL           8
#define ME_PITCH_SENS            9
#define ME_PROGRAM               10
#define ME_CHANNEL_PRESSURE      11
#define ME_TONE_BANK_HI          12
#define ME_ALL_NOTES_OFF         13
#define ME_ALL_SOUNDS_OFF        14
#define ME_RESET_CONTROLLERS     15
#define ME_MODULATION_WHEEL      16
#define ME_TEMPO                 17
#define ME_TONE_BANK_LO          18


typedef struct {
   c_int32       ticks;
   c_int32       toberead;
   const c_uint8 *ptr;
   c_uint32      status;
   c_int8        running;
} TrkParam;

typedef struct midievent {
  c_uint8     type;
  c_uint8     ch;
  c_uint8     c1;
  c_uint8     c2;
  c_int32     dtime;
  struct midievent *next;
} MidiEvent;

typedef struct{
   c_int32       duration;
   c_int32       active_tempo;
   c_int16       division;
   c_int32       acc_ticks;
   c_int32       acc_20ms;
   c_int32       time_div;
   c_int32       evtcount;
   c_int8        nrpn;
   c_int8        rpn_msb[16];
   c_int8        rpn_lsb[16];
   TrkParam      tracks[MAX_TRACK];
   MidiEvent     *event_head;
   MidiEvent     *event_tail;
   MidiEvent     *event_index;
   c_int8        debug;
   c_uint16      cache;
   c_uint16      bits;
   c_uint8       old_channel;
   c_uint8       old_octave;
   c_int32       total_events;
   c_int32       output_bytes;
   c_int32       statistic[MAX_MIDI_EVENTS];
}CMIDI_Handle_Int;

/* -------------------------------------------------------------------------------------- */
const static c_int8 chantype[] = {
   0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
   2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
};

/* -------------------------------------------------------------------------------------- */
static c_uint32 get32bit( const c_uint8 *s )
{
   return ((c_uint32)s[0] << 24) + ((c_uint32)s[1] << 16) + ((c_uint32)s[2] << 8) + (c_uint32)s[3];
}


static c_uint16 get16bit( const c_uint8 *s )
{
   return (c_uint16)(((c_uint16)s[0] << 8) + (c_uint16)s[1]);
}

static c_uint8 egetc( TrkParam *trk )       /* read a single character and abort on EOF */
{
   if( trk->toberead > 0 ) {
      trk->toberead--;
      return *trk->ptr++;
   }
   return -1;
}

static c_int32 getVarNum( TrkParam *trk )
{
	 {
   CMIDIGEN_LOG_V("getVarNum:  trk = %x", trk);
   CMIDIGEN_LOG_V("getVarNum:  ptr = %x,  count = %d",  trk->ptr, trk->toberead);
	 }
	 
   c_int32 value;
   c_int16 c;
   const c_uint8 *ptr = trk->ptr;
   c_int32 count = trk->toberead;
   
   if( count < 0 )  return -1;
   c = *ptr++;          count--;
   value = c & 0x7F;
   if( c & 0x80 ) {
      c = *ptr++;          count--;
      value = (value << 7) + (c & 0x7f);
      if( c & 0x80 ) {
         c = *ptr++;          count--;
         value = (value << 7) + (c & 0x7f);
         if( c & 0x80 ) {
            c = *ptr++;          count--;
            value = (value << 7) + (c & 0x7f);
         }
      }
   }
   trk->ptr = ptr;
   trk->toberead = count;
   
   CMIDIGEN_LOG_V("getVarNum: afterwards, trk->ptr = %x,  count = %d",  trk->ptr, trk->toberead); 
   
   return value;
}

static void InitSMF(c_uint8* wrkbuf, c_int32 size)
{
   c_int32 I;
   c_uint8 *ptr8;
   ptr8 = wrkbuf;
   for( I=0; I<size; I++ )
      *ptr8++ = 0;
}

static void MidiEvent_Put( CMIDI_Handle_Int *ihdl, c_uint8 type, c_uint8 ch, c_uint8 c1, c_uint8 c2 )
{
   MidiEvent *event;

   event = ihdl->event_index;
   event->type = type;
   event->ch = ch;
   event->c1 = c1;
   event->c2 = c2;
   event->next = 0;
   if( ihdl->event_head == NULL ) {
      ihdl->event_head = ihdl->event_tail = event;
   }
   else {
      ASSERT( ihdl->event_tail != NULL );
      ihdl->event_tail->next = event;
      ihdl->event_tail = event;
   }
   ihdl->event_index++;
}

static MidiEvent *MidiEvent_Get( CMIDI_Handle_Int *ihdl, MidiEvent *event )
{
   MidiEvent *temp;
   if(ihdl->event_head == NULL )
      return NULL;
   *event = *ihdl->event_head;
   temp = ihdl->event_head;
   ihdl->event_head = ihdl->event_head->next;
   if( ihdl->event_head == NULL )
      ihdl->event_tail = NULL;
   return event;
}

/* -------------------------------------------------------------------------------------- */

static c_int32 MIDI_Parse( CMIDI_Handle_Int *ihdl, const c_uint8 *mid )
{
   c_int32       I;
   c_int32       ntrks;
   TrkParam      *trk;
   c_int16       next_trk;
   c_int32       temp;
   c_int32       delta;
   TrkParam      *tracks;
   c_int8        fail = FALSE;
   c_int16       needed;
   c_uint8       type;
   c_uint8       c1, c2, ch;

   if( mid[0] == 'R' && mid[1] == 'I' && mid[2] == 'F' && mid[3] == 'F' )
      mid += 20;
   if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'h' || mid[3] != 'd' )
      return -1;

   if( get16bit( &mid[8] ) > 2 )
      return -1;
   if( (ntrks  = (c_uint32)get16bit( &mid[10] )) > MAX_TRACK )
      return -1;
   ihdl->division = get16bit( &mid[12] );
   if(ihdl->division <= 0)
      return -1;
   
   mid = (const c_uint8 *)&mid[8 + get32bit(&mid[4])];
   tracks = ihdl->tracks;

   for( I = 0 ; I < ntrks; I++ ) {
      if( mid[0] != 'M' || mid[1] != 'T' || mid[2] != 'r' || mid[3] != 'k' )
         break;
      trk            = &tracks[I];
      trk->toberead  = get32bit( &mid[4] );
      trk->ptr       = &mid[8];
      mid            = mid + 8 + trk->toberead;
      trk->ticks     = getVarNum( trk );
      trk->status    = 0;
      trk->running   = FALSE;
   }
   ntrks = I;
   
   ihdl->event_head = ihdl->event_tail = NULL;
   ihdl->duration = 0;
   ihdl->acc_ticks = 0;
   ihdl->acc_20ms = 0;
   ihdl->active_tempo = 1024 * 500 / (c_uint32)ihdl->division;
   ihdl->nrpn = FALSE;
   
   while( 1 ) {
      next_trk = MAX_TRACK;
      delta    = 0x7FFFFF;
      for( I = 0 ; I < ntrks; I++ ) {
         trk = &tracks[I];
         if( trk->toberead > 0 && trk->ticks < delta ) {
            delta    = trk->ticks;
            next_trk = I;
            if( delta == 0 )
               break;
         }
      }
      if( next_trk == MAX_TRACK )            /* No unhandled MIDI data left */
         break;
      if( delta > 0 ) {
         for( I = 0 ; I < ntrks; I++ ) {
            trk = &tracks[I];
            if( trk->toberead > 0 )
               trk->ticks -= delta;
         }
         ihdl->acc_ticks += delta;
         if( ihdl->acc_ticks * ihdl->active_tempo < ihdl->acc_ticks ) { /* overflow */
            ihdl->duration += ihdl->acc_20ms;
            ihdl->acc_ticks = delta;
            ihdl->acc_20ms = 0;
         }
         temp = ((ihdl->acc_ticks * ihdl->active_tempo >> 10) + (ihdl->time_div/2)) / ihdl->time_div;
         delta = temp - ihdl->acc_20ms;
         ihdl->acc_20ms = temp;
      }
      if( delta != 0 ) {
         MidiEvent_Put( ihdl, ME_DTIME, 0, (c_uint8)((delta>>7)&0x7F), (c_uint8)(delta&0x7F));
         ihdl->event_tail->dtime = delta;
      }
      trk = &tracks[next_trk];
      
      type = egetc( trk );
      if( type == 0xFF ) {
         type = egetc( trk );                                    /* read type */
         if( (delta = getVarNum( trk )) < 0 ) {                /* get meta event length */
            fail = TRUE;
            break;
         }
         if( type == 0x51 ) {                                    /* Set tempo */
            ihdl->duration += ihdl->acc_20ms;
            ihdl->acc_ticks = 0;
            ihdl->acc_20ms = 0;

            ihdl->active_tempo = (((c_uint32)trk->ptr[0] << 16) + ((c_uint32)trk->ptr[1] << 8) + (c_uint32)trk->ptr[2]) / 1000;
            ihdl->active_tempo = 1024 * ihdl->active_tempo / (c_uint32)ihdl->division;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = TRUE;
            break;
         }
      }
      else if( type == 0xF0 || type == 0xF7 ) {
         if( (delta = getVarNum( trk )) < 0 ) {
            fail = TRUE;
            break;
         }
         trk->ptr += delta;
         trk->toberead -= delta;
         if( trk->toberead < 0 ) {
            fail = TRUE;
            break;
         }
      }
      else {
         if( (type & 0x80) == 0 ) {       /* running status? */
            if( trk->status == 0 ){
               fail = TRUE;
               break;
            }
            trk->running = TRUE;
         }
         else {
            trk->status = (c_uint8)type;
            trk->running = FALSE;
         }
         
         needed = chantype[ (trk->status>>4) & 0xf ];
         
         if( needed ) {                /* ie. is it a channel message? */
            if ( trk->running )
               c1 = type;
            else
               c1 = egetc(trk);
            c2 = (c_uint8)((needed>1) ? egetc(trk) : 0 );
            ch = (c_uint8)(trk->status&0x0F);

            switch( trk->status & 0xf0 ) {
            case 0x80:        /* Note off */
               MidiEvent_Put( ihdl, ME_NOTEOFF, ch, c1, 0 );
               break;
            case 0x90:        /* Note on */
               if( c2 == 0 )
                  MidiEvent_Put( ihdl, ME_NOTEOFF, ch, c1, 0 );
               else {
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ihdl, ME_NOTEON, ch, c1, c2 );
               }
               break;
            case 0xa0:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
               MidiEvent_Put( ihdl, ME_KEY_PRESSURE, ch, c1, c2 );
               break;
            case 0xb0:     /* Controller message */
               switch( c1 ) {
               case 0x00:
                 MidiEvent_Put( ihdl, ME_TONE_BANK_HI, ch, c2, 0 );
                  break;
               case 0x20:
                  MidiEvent_Put( ihdl, ME_TONE_BANK_LO, ch, c2, 0 );
                  break;
               case 0x01:
                  MidiEvent_Put( ihdl, ME_MODULATION_WHEEL, ch, c2, 0 );
                  break;
               case 0x07:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ihdl, ME_MAINVOLUME, ch, c2, 0 );
                  break;
               case 0x0A:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ihdl, ME_PAN, ch, c2, 0 );
                  break;
               case 0x0B:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ihdl, ME_EXPRESSION, ch, c2, 0 );
                  break;
               case 0x40:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
                  MidiEvent_Put( ihdl, ME_SUSTAIN, ch, c2, 0 );
                  break;
                  
               case 98:    ihdl->nrpn=TRUE;  ihdl->rpn_lsb[ch] = c2;    break;
               case 99:    ihdl->nrpn=TRUE;  ihdl->rpn_msb[ch] = c2;    break;
               case 100:   ihdl->nrpn=FALSE; ihdl->rpn_lsb[ch] = c2;    break;
               case 101:   ihdl->nrpn=FALSE; ihdl->rpn_msb[ch] = c2;    break;
                  
               case 0x06:     /* RPN */
                  if( ihdl->nrpn )
                     break;
                  switch( ( (c_int16)ihdl->rpn_msb[ch] << 7 ) | (c_int16)ihdl->rpn_lsb[ch] ) {
                  case 0x0000: /* Pitch bend sensitivity */
                     MidiEvent_Put( ihdl, ME_PITCH_SENS, ch, c2, 0 );
                     break;
                  case 0x3FFF: /* RPN reset */
                     /* reset pitch bend sensitivity to 2 */
                     MidiEvent_Put( ihdl, ME_PITCH_SENS, ch, 2, 0 );
                     break;
                  }
                  break;
               }
               break;

            case 0xc0:
               MidiEvent_Put( ihdl, ME_PROGRAM, ch, c1, 0 );
               break;
            case 0xe0:
#ifdef VOLUME_QUANTIZE
                  c1 = 0;
#endif
               MidiEvent_Put( ihdl, ME_PITCH_WHEEL, ch, c1, c2 );
               break;
            case 0xd0:
#ifdef VOLUME_QUANTIZE
                  c2 &= 0xFC;
#endif
               MidiEvent_Put( ihdl, ME_CHANNEL_PRESSURE, ch, c1, 0 );
               break;

            }
         }
      }
      if( (trk->ticks = getVarNum( trk )) < 0 ) {
         fail = TRUE;
         break;
      }
   }
   ihdl->duration += ihdl->acc_20ms;

   if( fail )
      return -1;
   return ihdl->duration;
}

/* -------------------------------------------------------------------------------------- */
/*
static void MidiEvent_GroupType( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type != head->next->type ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->type == head->type ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_GroupTypeChannel( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type == head->next->type && head->ch != head->next->ch ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->type == head->type && curr->ch == head->ch ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}
*/

static void MidiEvent_GroupC1( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( (head->c1>>4) != (head->next->c1>>4) ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( (curr->c1>>4) == (head->c1>>4) ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_GroupChannel( MidiEvent *prevtail, MidiEvent **phead, MidiEvent **ptail )
{
   MidiEvent *curr, *prev;
   MidiEvent *tail = *ptail;
   MidiEvent *head = *phead;

   if( prevtail != 0 ) {
      ASSERT( prevtail->next->next == head );
      if( prevtail->ch != head->ch ) {
         for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
            if( curr->ch == prevtail->ch && (curr->c1>>4) == (prevtail->c1>>4) ) {
               prev->next = curr->next;
               curr->next = head;
               head = curr;
               prevtail->next->next = curr;
               if( curr == tail ) {
                  tail = prev;
                  curr = tail->next;
               }
               break;
            }
         }
         if( curr == tail->next ) {
            for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
               if( curr->ch == prevtail->ch ) {
                  prev->next = curr->next;
                  curr->next = head;
                  head = curr;
                  prevtail->next->next = curr;
                  if( curr == tail ) {
                     tail = prev;
                     curr = tail->next;
                  }
                  break;
               }
            }
            if( curr == tail->next ) {
               for( prev = head, curr = head->next; curr != tail->next; prev = curr, curr = curr->next ) {
                  if( (curr->c1>>4) == (prevtail->c1>>4) ) {
                     prev->next = curr->next;
                     curr->next = head;
                     head = curr;
                     prevtail->next->next = curr;
                     if( curr == tail ) {
                        tail = prev;
                        curr = tail->next;
                     }
                     break;
                  }
               }
            }
         }
      }
   }

   while( head != tail ) {
      if( head->ch != head->next->ch ) {
         for( prev = head, curr = head->next; curr != NULL; prev = curr, curr = curr->next ) {
            if( curr->ch == head->ch ) {
               prev->next = curr->next;
               curr->next = head->next;
               head->next = curr;
               if( curr == tail )
                  tail = prev;
               break;
            }
            if( curr == tail )
               break;
         }
      }
      head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_RemoveDupEvents( MidiEvent *head, MidiEvent **ptail )
{
   MidiEvent *curr, *temp;
   MidiEvent *tail = *ptail;

   while( head != tail ) {
      if( head->type == ME_MAINVOLUME ||
         head->type == ME_SUSTAIN ||
         head->type == ME_PAN ||
         head->type == ME_PITCH_WHEEL || 
         head->type == ME_PROGRAM ||
         head->type == ME_CHANNEL_PRESSURE ||
         head->type == ME_TONE_BANK_HI ||
         head->type == ME_TONE_BANK_LO ||
         head->type == ME_MODULATION_WHEEL ||
         head->type == ME_EXPRESSION ||
         head->type == ME_PITCH_SENS ) {
         for( curr = head; curr != tail;  ) {
            temp = curr->next;
            if( temp->type == head->type && temp->ch == head->ch ) {
               if( head != curr ) {
                  curr->next = temp->next;
                  temp->next = head->next;
               }
               *head = *temp;
//               free( temp );
               if( tail == temp ) {
                  tail = curr;
                  break;
               }
            }
            else {
               curr = curr->next;
            }
         }
      }
      if( head != tail )
         head = head->next;
   }
   *ptail = tail;
}

static void MidiEvent_Optimize( CMIDI_Handle_Int *ihdl )
{
   MidiEvent *head, *tail, *prevtail;

   head = tail = ihdl->event_head;
   prevtail = 0;
   while( head != NULL ) {
      if( head->type == ME_DTIME ) {
         tail = head->next;
         while( tail != NULL && tail->type == ME_DTIME ) {
            head->dtime += tail->dtime;
            head->next = tail->next;
//            free( tail );
            tail = head->next;
         }
         head = head->next;
      }
      else {
         tail = head;
         while( tail->next!= 0 && tail->next->type != ME_DTIME )
            tail = tail->next;
         MidiEvent_RemoveDupEvents( head, &tail );
//         MidiEvent_GroupType( head, &tail );
//         MidiEvent_GroupTypeChannel( head, &tail );
         MidiEvent_GroupC1( head, &tail );
         MidiEvent_GroupChannel( prevtail, &head, &tail );
         head = tail->next;
         prevtail = tail;
      }
   }
}
/* -------------------------------------------------------------------------------------- */

static void putBits( CMIDI_Handle_Int *ihdl, c_uint8 data, c_uint32 len, c_uint8 **pptr )
{
   c_uint16 mask = ((1<<len)-1);
   if( len == 0 )
      return;
   ASSERT( len <= 8 );

   ihdl->cache = ((c_uint16)data & mask) + (ihdl->cache << len );
   ihdl->bits += len;
   if( ihdl->bits >= 8 ) {
      data = (c_uint8)(ihdl->cache >> (ihdl->bits-8));
      ihdl->bits -= 8;
      ihdl->cache &= ((1<<ihdl->bits)-1);
      *(*pptr)++ = data;
      ihdl->output_bytes++;
   }
}

static void addStatistics( CMIDI_Handle_Int *ihdl, c_int32 type )
{
   ihdl->statistic[type]++;
   ihdl->total_events++;
}

static void checkChannel( CMIDI_Handle_Int *ihdl, MidiEvent *event, c_uint8 **pptr )
{
   if( event->ch != ihdl->old_channel ) {
      ihdl->old_channel = event->ch;
      addStatistics( ihdl, 2 );
      putBits( ihdl, (c_uint8)0x04, 3, pptr );
      putBits( ihdl, ihdl->old_channel, 4, pptr );
   }
}

static void checkOctave( CMIDI_Handle_Int *ihdl, MidiEvent *event, c_uint8 **pptr )
{
   if( (event->c1>>4) != ihdl->old_octave ) {
      ihdl->old_octave = (event->c1>>4);
      addStatistics( ihdl, 3 );
      putBits( ihdl, (c_uint8)0x05, 3, pptr );
      putBits( ihdl, ihdl->old_octave, 3, pptr );
   }
}

static void MidiEvent_Output( CMIDI_Handle_Int *ihdl, c_uint8 *ptr )
{
   MidiEvent event;
   c_int32 total_time = 0;
   c_int32 I;
   ihdl->bits = 0;
   ihdl->cache = 0;
   ihdl->old_channel = 0;
   ihdl->old_octave = 0;
   ihdl->total_events = 0;
   ihdl->output_bytes = 0;

   for( I = 0; I < MAX_MIDI_EVENTS; I++ )
      ihdl->statistic[I] = 0;

   while( MidiEvent_Get(ihdl,  &event ) != NULL ) {
      switch( event.type ) {
      case ME_DTIME:
         total_time += event.dtime;
         ASSERT( event.dtime != 0 );
         if( event.dtime <= 16 ) {
            addStatistics(ihdl, 4 );
            putBits( ihdl, (c_uint8)0x06, 3, &ptr );
            putBits( ihdl, (c_uint8)(event.dtime-1), 4, &ptr );
         }
         else {
            addStatistics( ihdl, 16 );
            ASSERT( event.dtime <= 1024 );
            putBits( ihdl, (c_uint8)0xF9, 8, &ptr );
            putBits( ihdl,  (c_uint8)((event.dtime-1)>>6), 4, &ptr );
            putBits( ihdl, (c_uint8)((event.dtime-1)&0x3F), 6, &ptr );
         }
#ifdef LOCALSIM
         TRACE1("time %d\n", total_time );
#endif
         break;
      case ME_NOTEOFF:
         checkChannel(ihdl,  &event, &ptr );
         checkOctave(ihdl,  &event, &ptr );
         addStatistics(ihdl,  1 );
         putBits( ihdl, (c_uint8)0x01, 2, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1&0x0F), 4, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Note off, ch=%d, pitch=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_NOTEON:
         checkChannel(ihdl,  &event, &ptr );
         checkOctave( ihdl, &event, &ptr );
         addStatistics( ihdl, 0 );
         putBits( ihdl, (c_uint8)0x00, 2, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1&0x0F), 4, &ptr );
         putBits(ihdl,  (c_uint8)(event.c2>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE4("time %d: Note on, ch=%d, pitch=%d, vel=%d\n", total_time, event.ch+1, event.c1, event.c2 );
#endif         
		 break;
      case ME_MAINVOLUME:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics(ihdl,  5 );
         putBits(ihdl,  (c_uint8)0x1C, 5, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Volume, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_PITCH_WHEEL:
         checkChannel( ihdl, &event, &ptr );
         addStatistics(ihdl,  6 );
         putBits( ihdl, (c_uint8)0x1D, 5, &ptr );
         putBits( ihdl, (c_uint8)(event.c2), 7, &ptr );
#ifdef LOCALSIM
         TRACE4("time %d: Pitch wheel, ch=%d, lsb=%d, msb=%d\n", total_time, event.ch+1, event.c1, event.c2 );
#endif
         break;
      case ME_SUSTAIN:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics(ihdl,  7 );
         putBits(ihdl,  (c_uint8)0xF0, 8, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Sustain, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_PAN:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics( ihdl, 8 );
         putBits( ihdl, (c_uint8)0xF1, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Pan, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_PROGRAM:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics( ihdl, 9 );
         putBits( ihdl, (c_uint8)0xF2, 8, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1), 7, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Program, ch=%d, prog=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_CHANNEL_PRESSURE:
         checkChannel( ihdl, &event, &ptr );
         addStatistics( ihdl, 10 );
         putBits(ihdl,  (c_uint8)0xF3, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Channel pressure, ch=%d, pressure=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;         
      case ME_KEY_PRESSURE:
         checkChannel(ihdl,  &event, &ptr );
         checkOctave(ihdl,  &event, &ptr );
         addStatistics(ihdl,  11 );
         putBits( ihdl, (c_uint8)0xF4, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1&0x0F), 4, &ptr );
         putBits( ihdl, (c_uint8)(event.c2>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE4("time %d: Key pressure, ch=%d, pitch=%d, pressure=%d\n", total_time, event.ch+1, event.c1, event.c2 );
#endif
         break;
      case ME_TONE_BANK_HI:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics(ihdl,  12 );
         putBits(ihdl,  (c_uint8)0xF5, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1), 7, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Tone bank_hi, ch=%d, bank_hi=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_TONE_BANK_LO:
         checkChannel( ihdl, &event, &ptr );
         addStatistics(ihdl,  17 );
         putBits( ihdl, (c_uint8)0xFA, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1), 7, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Tone bank_lo, ch=%d, bank_lo=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_MODULATION_WHEEL:
         checkChannel( ihdl, &event, &ptr );
         addStatistics( ihdl, 13 );
         putBits( ihdl, (c_uint8)0xF6, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1), 7, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Modulation wheel, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_EXPRESSION:
         checkChannel( ihdl, &event, &ptr );
         addStatistics(ihdl,  14 );
         putBits( ihdl, (c_uint8)0xF7, 8, &ptr );
         putBits( ihdl, (c_uint8)(event.c1>>2), 5, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Expression, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      case ME_PITCH_SENS:
         checkChannel(ihdl,  &event, &ptr );
         addStatistics( ihdl, 15 );
         putBits(ihdl,  (c_uint8)0xF8, 8, &ptr );
         putBits(ihdl,  (c_uint8)(event.c1), 7, &ptr );
#ifdef LOCALSIM
         TRACE3("time %d: Pitch sense, ch=%d, val=%d\n", total_time, event.ch+1, event.c1 );
#endif
         break;
      default:
         ASSERT(0);
         break;
      }
   }
   if( ihdl->bits > 0 ) {       /* flush the data inside the cache buffer */
      ASSERT( ihdl->bits < 8 );
      putBits( ihdl, (c_uint8)0, 8-ihdl->bits, &ptr );
   }
}

/* -------------------------------------------------------------------------------------- */
int CMIDI_Convert( CMIDI_Handle *hdl, unsigned char *wrkbuf, int *len)
{
   c_int32 hdlsize;
   CMIDI_Handle_Int *ihdl;
   c_uint8 *ptr8;

   CMIDIGEN_LOG_V("CMIDI_Convert: start");
   hdl->ihdl = (CMIDI_Handle_Int*)wrkbuf;
   hdlsize = sizeof(CMIDI_Handle_Int);
   ptr8 = (c_int8*)wrkbuf+hdlsize;
   ihdl = hdl->ihdl;
   
   CMIDIGEN_LOG_V("CMIDI_Convert: hdlsize = %d, len = %d", hdlsize, *len);
   CMIDIGEN_LOG_V("CMIDI_Convert InitSMF");
   InitSMF(wrkbuf, hdlsize);
#ifdef LOCALSIM
   ihdl->debug = TRUE;
#endif
   ihdl->event_index = (MidiEvent*)ptr8;

   ihdl->time_div = hdl->blockperiod;

   CMIDIGEN_LOG_V("CMIDI_Convert MIDI_Parse");
   if( MIDI_Parse( ihdl, hdl->midifile ) < 0 )
      return 0;
   
   CMIDIGEN_LOG_V("CMIDI_Convert MidiEvent_Optimize");
   MidiEvent_Optimize(ihdl);

   CMIDIGEN_LOG_V("CMIDI_Convert MidiEvent_Output");
   MidiEvent_Output( ihdl, (c_uint8*)hdl->midifile+8 );
   ptr8 = (c_uint8*)&hdl->midifile[0];
   *ptr8++ = 'M';
   *ptr8++ = 'T';
   *ptr8++ = 'K';
   *ptr8++ = ihdl->time_div;
   *ptr8++ = (ihdl->output_bytes>>24) & 0xFF;
   *ptr8++ = (ihdl->output_bytes>>16) & 0xFF;
   *ptr8++ = (ihdl->output_bytes>>8) & 0xFF;
   *ptr8++ = ihdl->output_bytes & 0xFF;
   *len = ihdl->output_bytes + 8;
   CMIDIGEN_LOG_V("CMIDI_Convert: End, len = %d", *len);
   return 1;
}

/* -------------------------------------------------------------------------------------- */
void CMIDI_GetBufSize( CMIDI_Handle *hdl, c_uint32 *wrksize)
{
   int ihdlsize;
   ihdlsize = sizeof(CMIDI_Handle_Int);
   *wrksize = ihdlsize+((hdl->file_len - 22)*9);
}
