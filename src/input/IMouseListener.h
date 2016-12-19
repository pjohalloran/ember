#ifndef __EMBER_MOUSE_LISTENER_H
#define __EMBER_MOUSE_LISTENER_H

/*
 * @file IMouseListener.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "IInputListener.h"

namespace ember
{
	namespace input
	{
		using namespace ember::core;
		
		class IMouseListener : public IInputListener
		{
			public:
			
				virtual ~IMouseListener() { }
				
				virtual void VOnButtonPress( I32 button ) = 0;
				
				virtual void VOnButtonRelease( I32 button ) = 0;
				
				// TODO Replace with math structures
				virtual void VOnMove( F64 x, F64 y, F64 xRelative, F64 yRelative ) = 0;
				
				// TODO Replace with math structures
				virtual void VOnScroll( F64 x, F64 y ) = 0;
		};
	}
}

#endif
