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
 *   open_api_h264_yuv_management.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements YUV buffer management functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#if defined (__VE_H264_HW_OPEN_API_SUPPORT__) || (defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_H264_DEC_HW_SUPPORT__))
#include "kal_release.h"
#include "h264_open_api_video_if.h"
#include "open_api_h264_decode.h"
#if defined (__VE_VIDEO_ARCHI_V2__)
#include "video_comm_v2.h"
#else
#include "video_comm.h"
#endif
#include "open_api_h264_yuv_management.h"
#include "vcodec_v2_trc.h"

#ifdef dbg_print
#undef dbg_print
#define dbg_print(...)
#else
#define dbg_print(...)
#endif


/*******************************************************************************
*   extern global structure
*******************************************************************************/
extern H264_DPB_list g_open_api_h264_DPB_list;
extern H264_dec_info *g_open_api_h264_dec_info_ptr;
extern H264_dpb_frame_info  g_open_api_h264_dpb_frame_info;
extern kal_bool fgDisplayOrderMode;
/*******************************************************************************
*   extern function
*******************************************************************************/
extern kal_uint32 video_get_current_time(void);
extern kal_int32 output_a_pic_normal(H264_DPB_entry *out_dpbe);

// need to replace to callbacks
extern void release_yuv_buffer(kal_uint32 addr);

/*******************************************************************************
*   DPB buffer function
*******************************************************************************/

void open_api_h264_set_next_decode_dpb(H264_DPB_entry *p_dpb)
{
	g_open_api_h264_dpb_frame_info.p_dpb_decode = p_dpb;
}

kal_bool open_api_h264_add_dpb_info(kal_uint32 frame_addr, kal_uint32 frame_length)
{
    kal_uint32 index;
    kal_bool b_found = KAL_FALSE;
    H264_dpb_frame_entry *p_frame_entry = g_open_api_h264_dpb_frame_info.frame_list;

    dbg_print("[DRV H264]open_api_h264_add_dpb_info(), frame_no:%d\n\r", g_open_api_h264_dec_info_ptr->hdr_add_frames_no);
    video_dbg_trace(H264_DEC_ADD_FRAME, g_open_api_h264_dec_info_ptr->hdr_add_frames_no);

    //Pre Check If the frame_no is exists
    for(index = 0; index < (g_open_api_h264_dpb_frame_info.max_queue_num*2); index++)
    {
        if((p_frame_entry->b_used == KAL_TRUE) && 
           (p_frame_entry->frame_no==g_open_api_h264_dec_info_ptr->hdr_add_frames_no))
        {
            //if previous decode fail is due to dpb full 
            video_dbg_trace(H264_DEC_ADD_EXIST_FRAME,g_open_api_h264_dec_info_ptr->hdr_add_frames_no);
            dbg_print("[DRV H264]open_api_h264_add_dpb_info(), frame_no:%d\n\r", g_open_api_h264_dec_info_ptr->hdr_add_frames_no);
            b_found = KAL_TRUE;
            if(p_frame_entry->p_dpb != 0)
            {
            	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
             VIDEO_ASSERT(0);
            }
             
            p_frame_entry->addr = frame_addr;
            p_frame_entry->length = frame_length;
            
            if(g_open_api_h264_dpb_frame_info.p_next_parse == NULL)
               g_open_api_h264_dpb_frame_info.p_next_parse = p_frame_entry;
            
            return KAL_TRUE;
        }
        
        p_frame_entry++;      
    }
    
    p_frame_entry = g_open_api_h264_dpb_frame_info.frame_list;
    // find empty slot from list
    for(index = 0; index < (g_open_api_h264_dpb_frame_info.max_queue_num*2); index++)
    {
        if(p_frame_entry->b_used == KAL_FALSE)
        {
            b_found = KAL_TRUE;
            break;
        }
        p_frame_entry++;
    }

   
    //if(b_found == KAL_FALSE)
        //EXT_ASSERT(0, g_open_api_h264_dpb_frame_info.max_queue_num, 0, 0);
    
    if(b_found == KAL_FALSE)
    {
    	video_dbg_trace(H264_DEC_DPB_FRAME_ENTRY_FULL,video_get_current_time());
    	dbg_print("[DRV H264]open_api_h264_add_dpb_info()\n\r");
    	return KAL_FALSE;  
    }

    // store the information into the found slot
    p_frame_entry->addr = frame_addr;
    p_frame_entry->length = frame_length;
    p_frame_entry->frame_no=g_open_api_h264_dec_info_ptr->hdr_add_frames_no;
    //p_frame_entry->b_dec_done = KAL_FALSE;
    p_frame_entry->b_used = KAL_TRUE;
    p_frame_entry->p_next_dpb = NULL;
    p_frame_entry->p_prev_dpb = NULL;
    p_frame_entry->p_dpb = NULL;


    //reconstruct the list
    if(g_open_api_h264_dpb_frame_info.p_start == NULL)
    {
        g_open_api_h264_dpb_frame_info.p_start = p_frame_entry;	
        g_open_api_h264_dpb_frame_info.p_end = p_frame_entry;
        g_open_api_h264_dpb_frame_info.p_next_parse = p_frame_entry;
    }
    else
    {
        g_open_api_h264_dpb_frame_info.p_end->p_next_dpb = p_frame_entry;
        p_frame_entry->p_prev_dpb = g_open_api_h264_dpb_frame_info.p_end;
        g_open_api_h264_dpb_frame_info.p_end = p_frame_entry;
        if(g_open_api_h264_dpb_frame_info.p_next_parse == NULL)
            g_open_api_h264_dpb_frame_info.p_next_parse = p_frame_entry;
    }

    return KAL_TRUE;
}


void open_api_h264_set_dpb_decode_done(void)
{
	if (g_open_api_h264_dpb_frame_info.p_dpb_decode == NULL)//if the player is not initalized properly
	{
		VIDEO_ASSERT(0);
	}
	else
	{
		g_open_api_h264_dpb_frame_info.p_dpb_decode->b_dec_done = KAL_TRUE;
	}
}

kal_uint32 open_api_h264_get_dpb_frame_number(H264_DPB_entry *p_dpb)
{
    if (p_dpb == 0)
    {
        VIDEO_ASSERT(0);
        return 0;
    }
    return g_open_api_h264_dpb_frame_info.frame_list[p_dpb->index_to_list].frame_no;
}

/* Free dpb entry from list
 * @param p_DPB the dpb which will be removed and set as un-used from the list
 * @return None
 */
void open_api_h264_check_free_dpb(void)
{
    H264_DPB_entry *p_free_DPB;
    kal_uint32 index;
    
    /* Check previous wait_for_free list first. If any displayed frame is unused for reference, discard it!!*/
    if(g_open_api_h264_DPB_list.wait_for_free !=0)
    {
        for(index = 0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
        {
            if((g_open_api_h264_DPB_list.wait_for_free & (1<<index)) != 0)
            {
                p_free_DPB = &g_open_api_h264_DPB_list.dpbe[index];
                if(p_free_DPB->status_marked == H264_unused_ref/* ||
                   open_api_h264_get_dpb_frame_number(p_free_DPB)>g_open_api_h264_dec_info_ptr->dec_frames_no*/)
                {
                   if( p_free_DPB->status_marked != H264_unused_ref)
                   {
                   	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                   	ASSERT(0);
                   }

                  	video_dbg_trace(H264_DEC_FREE_DPB,open_api_h264_get_dpb_frame_number(p_free_DPB));
                    p_free_DPB->b_used = KAL_FALSE;
                    p_free_DPB->b_dec_done=KAL_FALSE;
                    g_open_api_h264_DPB_list.num_used--;
                    g_open_api_h264_DPB_list.wait_for_free &= (~(1<<index)); //Discard!!
                    
                }
            }
        }
    }
    
    /*Scott,If DPB is full, search for corrupted frame and discard it.*/
    if(g_open_api_h264_DPB_list.num_used == (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1))
    {
         if(g_open_api_h264_DPB_list.wait_for_free !=0)
         {
           for(index = 0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
           {
               if((g_open_api_h264_DPB_list.wait_for_free & (1<<index)) != 0)
               {
                   p_free_DPB = &g_open_api_h264_DPB_list.dpbe[index];
                   if(p_free_DPB->is_corrupted == KAL_TRUE)
                   {
                   	   video_dbg_trace(H264_DEC_FREE_CORRUPTED_DPB,p_free_DPB->frame_no);
                       p_free_DPB->b_used = KAL_FALSE;
                       p_free_DPB->b_dec_done=KAL_FALSE;
                       g_open_api_h264_DPB_list.num_used--;
                       g_open_api_h264_DPB_list.wait_for_free &= (~(1<<index)); //Discard!!
                   }
               }
           }
         }     
    }    

   /*Scott, something wrong with this condition. Free the displayed unref frame*/
   if(g_open_api_h264_dpb_frame_info.p_prev_display != NULL)
   {
         for(index = 0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
         {
               p_free_DPB = &g_open_api_h264_DPB_list.dpbe[index];
               if(p_free_DPB->b_used == KAL_TRUE &&
                  /*g_open_api_h264_dpb_frame_info.frame_list[p_free_DPB->index_to_list].time < g_open_api_h264_dpb_frame_info.frame_list[g_open_api_h264_dpb_frame_info.p_prev_display->index_to_list].time && */
                  p_free_DPB->status_marked == H264_unused_ref)
               {
                   /* We can't do this due to allegro error bit stream. PS. MAUI_00981880 */
                  #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                  #else
                    g_open_api_h264_dec_info_ptr->is_error_occur = KAL_TRUE;
                  #endif
                }
        }    
   }  

   video_dbg_trace(H264_DEC_DPB_WAIT_FREE_LIST,g_open_api_h264_DPB_list.wait_for_free);
}

/* Check whether dpb list is full or not
 * @param p_DPB: the dpb goning to be released
 * @param force_release: free the dpb regardless of it's mmco status
 * @return full or not
 */
void open_api_h264_free_dpb(H264_DPB_entry* p_DPB)
{
	H264_dpb_frame_entry *p_free_entry;
    drv_trace1(TRACE_GROUP_10,OPEN_API_UNREFERENCEFRAME,(kal_uint32)p_DPB->mem_addr);
    g_open_api_h264_dec_info_ptr->pfnSetFrameUnReferenceCallback((kal_uint32)p_DPB->mem_addr); 

	p_DPB->b_used = KAL_FALSE;
	p_DPB->status_marked = -1;
	p_DPB->b_dec_done = KAL_FALSE;
	p_DPB->is_corrupted=KAL_FALSE;
	p_DPB->top_POC = 0;
	p_DPB->bottom_POC = 0;
	p_DPB->POC = 0;
	p_DPB->isOutputed = -1;
	p_DPB->pic_num = -1;

	p_free_entry = &g_open_api_h264_dpb_frame_info.frame_list[p_DPB->index_to_list];
	// remove the display one from list 
	if (p_free_entry == g_open_api_h264_dpb_frame_info.p_start)
	{
		g_open_api_h264_dpb_frame_info.p_start = p_free_entry->p_next_dpb;
	}
	else
    {
        if (p_free_entry->p_prev_dpb != NULL)
        {   
            p_free_entry->p_prev_dpb->p_next_dpb = p_free_entry->p_next_dpb;
        }
        if (p_free_entry->p_next_dpb != NULL)
        {
        		p_free_entry->p_next_dpb->p_prev_dpb = p_free_entry->p_prev_dpb;
        	}
        }

        if (p_free_entry == g_open_api_h264_dpb_frame_info.p_end)
        {
        	g_open_api_h264_dpb_frame_info.p_end = p_free_entry->p_prev_dpb;
        }
        else
        {
            if (p_free_entry->p_next_dpb != NULL)
        	{
        	    p_free_entry->p_next_dpb->p_prev_dpb = p_free_entry->p_prev_dpb;
            }
        	if (p_free_entry->p_prev_dpb != NULL)
        	{
        		p_free_entry->p_prev_dpb->p_next_dpb = p_free_entry->p_next_dpb;
        	}
        }
        p_free_entry->b_used = KAL_FALSE;

}


// Get index of the dpbe with the smallest POC
kal_uint32 get_ind_dpbe_with_smallest_poc(kal_uint32 *Ind)
{
	H264_DPB_entry *dpb;
	kal_uint32 i = 0;
	kal_int32 minPOC;

	minPOC = maxINT;

	for (i = 0; i < (kal_uint32)g_open_api_h264_DPB_list.num_used; i++) 
	{
		dpb = &g_open_api_h264_DPB_list.dpbe[i];
		if (dpb->isOutputed==0)
		{
			if (dpb->POC < minPOC) 
			{
				minPOC = dpb->POC;
				*Ind = i;
			}
		}
	}
	return minPOC;
}



H264_DPB_entry* open_api_h264_get_empty_dpb(void)
{
    kal_uint32 index, i, Ind;
    kal_int32 minPOC;
    H264_DPB_entry *p_DPB = NULL, *dpbe;

    /*Scott, Check if there is any free dpb be marked as un-used for ref. in the ref marking process */
    open_api_h264_check_free_dpb();

    // check fullness
    if (g_open_api_h264_DPB_list.num_used == (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1))
    {
        //Needs to do bumping process here!!
        // Find the removable entry with minimal POC
        minPOC = (kal_int32)maxINT;
        Ind = 0;
        dpbe = g_open_api_h264_DPB_list.dpbe;
        for (i=0; i < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1);  i++)// find the one with smallest POC
        {
            p_DPB = dpbe++;
            if ( (p_DPB->isOutputed == 1) && (p_DPB->status_marked == H264_unused_ref) )
            {
                if (p_DPB->POC < minPOC)
                {
                    minPOC = p_DPB->POC;
					Ind = i;
				}
			}
		}
		if (minPOC != maxINT)
		{
			p_DPB = &g_open_api_h264_DPB_list.dpbe[Ind];
			//clear_rpe_by_ind(dpbe->statusMarked, Ind);
			open_api_h264_free_dpb(p_DPB);
			g_open_api_h264_DPB_list.num_used--;
			//return p_DPB;		// Move to the final
			goto GET_EMPTY_END;
		}

        // In the non-display-ordering mode, if goes here there must be something wrong...
        //
        if (fgDisplayOrderMode == KAL_FALSE)
        {
            //ASSERT(0);
            return NULL;
        }

		// Find non-outputed one with smallest POC and do bumping process.
		while (1)
		{
			minPOC = get_ind_dpbe_with_smallest_poc(&Ind);
			if (minPOC == maxINT)
			{
				video_dbg_trace(H264_DEC_FIND_SMALLEST_POC_FAIL, 0);
				dbg_print("[DRV H264]get_ind_dpbe_with_smallest_poc fails\n\r");
				return NULL;
			}

			p_DPB = &g_open_api_h264_DPB_list.dpbe[Ind];
			if (p_DPB->isOutputed == 0) 
			{
				p_DPB->isOutputed = 1;
				if (output_a_pic_normal(p_DPB) != 1)
				{
					video_dbg_trace(H264_DEC_OUTPUT_PIC_FAIL, p_DPB->frame_no);
					dbg_print("[DRV H264]output_a_pic_normal() fails, frames_no = %d\n\r", p_DPB->frame_no);
					return NULL;
				}
			}

			video_dbg_trace(H264_DEC_BUMPING_PROCESS, p_DPB->frame_no);
			dbg_print("[DRV H264]open_api_h264_get_empty_dpb() DPB Full, Bumping process remove frame: %d\n\r", p_DPB->frame_no);
			if (p_DPB->status_marked == H264_unused_ref)
			{
				open_api_h264_free_dpb(p_DPB);
				g_open_api_h264_DPB_list.num_used--;
				//return p_DPB;		// Move to the final
				break;
			}
		}
	}

	GET_EMPTY_END: 
	for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
	{
		if (g_open_api_h264_DPB_list.dpbe[index].b_used == KAL_FALSE)
		{
			g_open_api_h264_DPB_list.dpbe[index].b_used = KAL_TRUE;
			p_DPB = &g_open_api_h264_DPB_list.dpbe[index];
			g_open_api_h264_DPB_list.num_used++;
			break;
		}
	}

	return p_DPB;
}

H264_DPB_entry* open_api_h264_get_next_parse_dpb(kal_uint32 *p_frame_addr, kal_uint32 *p_frame_length)
{
    H264_dpb_frame_entry *p_dpb_entry = g_open_api_h264_dpb_frame_info.p_next_parse;
    H264_DPB_entry *p_free_dpb;
    kal_uint32 i;
    H264_DPB_entry *p_DPB = NULL, *dpbe;

    if(p_dpb_entry == NULL)
    {
    	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
    	EXT_ASSERT(0, g_open_api_h264_dpb_frame_info.max_queue_num, (kal_uint32)g_open_api_h264_dpb_frame_info.p_start, (kal_uint32)g_open_api_h264_dpb_frame_info.p_end);
        return NULL;
    }
    
    // get empty dpb and assign to it
    p_free_dpb = open_api_h264_get_empty_dpb();
    if(p_free_dpb == NULL)
    {
        // If we can't get any empty DPB
        // This is an error case
        // The decoder will mark all frame as unused for reference in DPB list.
        //
        dpbe = g_open_api_h264_DPB_list.dpbe;
		for (i=0; i < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1);  i++)// find the one with smallest POC
		{
			p_DPB = dpbe++;
			p_DPB->status_marked = H264_unused_ref;
		}
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used = 0;
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used = 0;

        // Try to get one empty DPB again
        //
        p_free_dpb = open_api_h264_get_empty_dpb();

        if (p_free_dpb == NULL)
        {
            ASSERT(0);
            return NULL;
        }
    }

    // frame information and time information
    *p_frame_addr = p_dpb_entry->addr;
    *p_frame_length = p_dpb_entry->length;
    g_open_api_h264_dpb_frame_info.p_next_parse = p_dpb_entry->p_next_dpb;

    // get empty dpb and assign to it
    p_dpb_entry->p_dpb = p_free_dpb;
    p_free_dpb ->frame_no = p_dpb_entry->frame_no;
    p_free_dpb->isOutputed = 0;		// refer to store_a_pic_into_DPB
    p_free_dpb->status_marked = -1;
    if(p_dpb_entry->p_dpb == NULL)
    {
    	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
    	EXT_ASSERT(0, 0, 0, 0);
    }
    p_dpb_entry->p_dpb->index_to_list = p_dpb_entry->index;
    p_dpb_entry->index_to_entry = p_dpb_entry->p_dpb->index;

    return p_dpb_entry->p_dpb;
}

#endif /*#ifdef __VE_H264_HW_OPEN_API_SUPPORT__*/
