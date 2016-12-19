#ifndef __EMBER_KEYBOARD_LISTENER_H
#define __EMBER_KEYBOARD_LISTENER_H

/*
 * @file IKeyboardListener.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "IInputListener.h"

namespace ember
{
	namespace input
	{
		using namespace ember::core;
		
		class IKeyboardListener : public IInputListener
		{
			public:
			
				virtual ~IKeyboardListener() { }
				
				virtual void VOnKeyPress( I32 key ) = 0;
				
				virtual void VOnKeyRelease( I32 key ) = 0;
		};
	}
}

#endif
