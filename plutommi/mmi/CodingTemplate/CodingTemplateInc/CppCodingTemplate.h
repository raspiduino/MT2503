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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
 
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  CppCodingTemplate.h
 * 
 * Project:
 * --------
 *  Fill your project name here
 * 
 * Description:
 * ------------
 *  Describe your header here
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CPP_CODING_TEMPLATE_H__
#define __CPP_CODING_TEMPLATE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "base_type.h"


/*****************************************************************************
 * Class VfxShape
 *****************************************************************************/

/*
 * VfxShape is a class that can describe an object in the screen.
 *
 * EXAMPLE
 * <code>
 *  VfxShape *shape = new VfxRectangle(0, 0, 100, 20);
 *  shape->setPos(0, 0);
 * </code>
 */
class VfxShape
{
// Constructor / Destructor
public:
    // Default constructor
    VfxShape();

    // Copy constructor
    VfxShape(const VfxShape &other);
    
    // Use a point to construct a shape
    VfxShape(
        VfxS32 x,   // [IN] x position
        VfxS32 y    // [IN] y position
    );
    
    // Use a point to construct a shape
    explicit VfxShape(
        const VfxPoint &newPoint  // [IN] point class
    );

    // Destructor
    virtual ~VfxShape();

// Method
public:
    // Get the position of this shape. 
    // RETURNS:
    //  the position of this shape
    const VfxPoint& getPos() const { return m_pos; }

    // Set the visible of this shape. 
    void setVisible(
        VfxBool isVisible  // [IN] is visible
    );

    // Get the position of this shape to 2 integers. 
    void getPos(
    	VfxS32 &x, // [OUT] output x position
    	VfxS32 &y  // [OUT] output y position
    ) const
    {
        // This is an example for inline function
        x = m_pos.x;
        y = m_pos.y;
    }
    
// Overridable
public:
    // This function can do hit test with a point.
    // RETURNS:
    //  VFX_TRUE if the point intersects with this shape
    virtual VfxBool hitTest(
        VfxS32 x,  // [IN] x position 
        VfxS32 y   // [IN] y position
    ) const = 0;
    
// Variable
protected:
    // The left top point of this shape
    VfxPoint m_pos;
    // Is this shape visible
    VfxBool m_visible;
    // The number of count of shape object.
    // Here is an example about static variable.   
    static VfxS32 s_instanceCnt;
};


/*****************************************************************************
 * Class VfxRectangle
 ****************************************************************************/

/*
 * VfxRectangle is a class that can handle an area in the screen.
 *
 * You can assign it into dc->fill_rect() or dc->set_clip() functions.
 *
 * EXAMPLE
 * <code>
 *  VfxRectangle r(0, 0, 100, 20);
 *  if (r.isIntersectWith(20, 20))
 *  {
 *  }
 * </code>
 */
class VfxRectangle : public VfxShape
{
// Declaration
public:
    // The state of rectangle
    enum StateEnum
    {
        STATE_EMPTY     = 0,    // The rectangle is empty
        STATE_INFINITE  = 1,    // The rectangle has infinite dimension
        STATE_NORMAL    = 2,    // The rectangle is normal
        STATE_END_OF_ENUM      
    };
    
    // Constants
    enum
    {
        MIN_WIDTH     = -10000,  // Minimum width
        MIN_HEIGHT    = -10000,  // Minimum height
        MAX_WIDTH     = 10000,   // Maximum width
        MAX_HEIGHT    = 10000    // Maximum height
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VfxRectangle();

    // Copy constructor
    VfxRectangle(const VfxRectangle &rect);

    // Construct with position and size
    VfxRectangle(
        VfxS32 x,  // [IN] x position
        VfxS32 y,  // [IN] y position
        VfxS32 w,  // [IN] width
        VfxS32 h   // [IN] height
    );

    // Destructor
    ~VfxRectangle();
    
// Method
public:
     // Get the size of this rectangle. 
     // RETURNS: the size of this rectangle
    const VfxSize& getSize() const;  

    // Set the size of this rectangle.
    void setSize(
        VfxS32 w,  // [IN] new width
        VfxS32 h   // [IN] new height
    )
    {
        m_size.w = w;
        m_size.h = h;
    }

    // Test whether this rectangle intersects with a point. 
    // RETURNS: VFX_TRUE if the point intersects with the rectangle
    VfxBool isIntersectWith(
        VfxS32 x,  // [IN] x position
        VfxS32 y   // [IN] y position
    ) const;

    // Calculate the area of a rectangle. 
    // RETURNS: square measure of the area
    static VfxS32 calculateArea(
		VfxS32 height, // [IN] width of area
		VfxS32 width   // [IN] height of area
    );

    // Get the rectangle state
    // RETURNS: return the retangle state
    // RETURN VALUES:
    //  STATE_EMPTY      :   This rectangle is empty
    //  STATE_INFINITE   :   This rectangle has infinite dimension
    //  STATE_NORMAL     :   This rectangle is normal
    StateEnum getState();

    // Union this rectangle with another rectangle.
    // RETURNS: Return this rectangle.
    VfxRectangle& unionWith(
        VfxS32 x,  // [IN] x position
                   //      This is the second line comment.
        VfxS32 y,  // [IN] y position
        VfxS32 w,  // [IN] width
        VfxS32 h   // [IN] height
    );
    
    // Union this rectangle with another rectangle.
    // RETURNS: Return this rectangle.
    VfxRectangle& unionWith(
        const VfxRectangle &rect   // [IN]  the union target
                                   // I am the second line comments.
    );

// Override
public:
    virtual VfxBool hitTest(VfxS32 x, VfxS32 y) const;

// Variable
protected:
    // Size of the rectangle
    VfxSize m_size;
    
// Implementation
private:     
    friend void vfx_dump_all_rectangle_info(const VfxRectangle& rect);

    // The function can get the right bottom point of this rectangle
    // RETURNS: the right bottom point
    VfxPoint getRBPoint() const;

    // Internal state
    StateEnum m_state;
};

inline VfxBool VfxRectangle::isIntersectWith(VfxS32 x, VfxS32 y) const
{
    return (x >= m_pos.x &&
            y >= m_pos.y &&
            x < m_pos.x + m_size.w &&
            y < m_pos.y + m_size.h) ? VFX_TRUE : VFX_FALSE;
}


/*****************************************************************************
 * Template VfxPtrStack
 *****************************************************************************/

/*
 * VfxPtrStack is a stack data structure template, 
 * you can use it to push and pop data.
 * EXAMPLE:
 * <code>
 *  VfxPtrStack<VfxShape, 10> stk;
 *  stk.push(shape1_ptr);
 *  stk.push(shape2_ptr);
 *  VfxShape *ptr = stk.pop(); // ptr = shape2_ptr;
 * </code>
 */
template <class _type, VfxS32 _maxSize>
class VfxPtrStack
{
// Constructor / Destructor
public:
    // Default constructor
    VfxPtrStack() : m_size(0) {}
    
    // Destructor
    ~VfxPtrStack() {}

// Method
public:
    // Test whether the stack is empty
    // RETURNS: VFX_TRUE if the stack is empty
    VfxBool isEmpty()
    {
        return m_size ? VFX_TRUE : VFX_FALSE;
    }

    // Push a pointer into the stack
    // RETURNS: VFX_TRUE if success
    VfxBool push(
        _type *ptr // [IN] the pointer to be pushed into stack
    );

    // Pop a pointer from the stack
    // RETURNS: NULL if the stack is empty; otherwise return the pointer
    _type* pop();

// Variable
protected:
    VfxS32  m_size;                // The m_stack size
    _type   *m_stack[_maxSize];    // The container contains data

};

template <class _type, VfxS32 _maxSize>
inline VfxBool VfxPtrStack<_type, _maxSize>::push(_type *ptr)
{
    if (m_size >= _maxSize)
    {
        return VFX_FALSE;
    }
    
    m_stack[m_size++] = ptr;
    return VFX_TRUE;
}

template <class _type, VfxS32 _maxSize>
inline _type* VfxPtrStack<_type, _maxSize>::pop()
{
    if (m_size == 0)
    {
        return NULL;
    }
    
    return m_stack[m_size--];
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

// Dump the debug information of all rectangles
void vfx_dump_all_rectangle_info();


#endif // __CPP_CODING_TEMPLATE_H__