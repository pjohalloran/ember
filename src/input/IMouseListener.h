#ifndef __EMBER_MOUSE_LISTENER_H
#define __EMBER_MOUSE_LISTENER_H

/*
 * @file IMouseListener.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "IInputListener.h"

#include "math/Point2.h"

namespace ember
{
	namespace input
	{
		using namespace ember::core;
		using namespace ember::math;
		
		class IMouseListener : public IInputListener
		{
			public:
			
				virtual ~IMouseListener() { }
				
				virtual void VOnButtonPress( I32 button ) = 0;
				
				virtual void VOnButtonRelease( I32 button ) = 0;
				
				virtual void VOnMove( const Point2 &position, const Point2 &relative ) = 0;
				
				virtual void VOnScroll( const Point2 &position ) = 0;
				
				// TODO might be better to put this in a Window listener
				virtual void VOnFileDrop( const char **paths, int count ) = 0;
		};
	}
}

#endif
