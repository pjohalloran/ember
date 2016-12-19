#ifndef __EMBER_GAMEPAD_LISTENER_H
#define __EMBER_GAMEPAD_LISTENER_H

/*
 * @file IGamepadListener.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "IInputListener.h"

namespace ember
{
	namespace input
	{
		using namespace ember::core;
		
		class IGamepadListener : public IInputListener
		{
			public:
			
				virtual ~IGamepadListener() { }
				
				virtual void VOnConnect( I32 gamepadId ) = 0;
				
				virtual void VOnDisconnect( I32 gamepadId ) = 0;
				
				// TODO Add more events here.
		};
	}
}

#endif
