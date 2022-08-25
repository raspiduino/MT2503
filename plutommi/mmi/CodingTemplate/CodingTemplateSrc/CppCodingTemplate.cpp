/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CppCodingTemplate.cpp
 *
 * Project:
 * --------
 *  Fill your project name here
 *
 * Description:
 * ------------
 *  Describe your source file here
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CppCodingTemplate.h"


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

// Dump the debug information of a rectangles
static void vfx_dump_rectangle_info(
	const VfxRectangle& rect   // [IN] the dumped rectangle 
)
{
    kal_printf("Rect: (%d, %d)-(%d, %d)\n", 
        rect.m_pos.x, rect.m_pos.y, rect.m_size.w, rect.m_size.h);
}

	

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void vfx_dump_all_rectangle_info()
{
    // Call Get First to start list all rectangles
    VfxRectangle* rect_ptr = vfxDebugGetFirstRectangle();
    while (rect_ptr)
    {
        vfxDumpRectangleInfo(rect_ptr);
        
        // Call Get Next to get next rectangle
        rect_ptr = vfxDebugGetNextRectangle();
    };

}


/*****************************************************************************
 * Class VfxShape
 *****************************************************************************/

VfxS32 VfxShape::s_instanceCnt = 0;

VfxShape::VfxShape() : m_pos(0, 0), m_visible(VFX_TRUE)
{
    s_instanceCnt++;
}


VfxShape::VfxShape(VfxS32 x, VfxS32 y) : 
    m_pos(x, y), 
    m_visible(VFX_TRUE)
{
    s_instanceCnt++;
}


VfxShape::VfxShape(const VfxPoint &pt) : 
    m_pos(pt), m_visible(VFX_TRUE)
{
    s_instanceCnt++;
}


VfxShape::~VfxShape()
{
    s_instanceCnt--;
}


/*****************************************************************************
 * Class VfxRectangle
 *****************************************************************************/

VfxRectangle::VfxRectangle() : m_size(0, 0)
{
}


VfxRectangle::VfxRectangle(const VfxRectangle &rect) : 
    VfxShape(rect.m_pos), 
    m_size(rect.m_size)
{
}


VfxRectangle::VfxRectangle(VfxS32 x, VfxS32 y, VfxS32 w, VfxS32 h) : 
    VfxShape(x, y), m_size(w, h)
{
}


VfxRectangle::~VfxRectangle()
{
}


VfxBool VfxRectangle::hitTest(VfxS32 x, VfxS32 y) const 
{
    return isIntersectWith(x, y);
}


VfxPoint VfxRectangle::getRBPoint() const
{
    VfxPoint pt(m_pos);
    pt.x += m_size.w - 1;
    pt.y += m_size.h - 1;
    return pt;
}
