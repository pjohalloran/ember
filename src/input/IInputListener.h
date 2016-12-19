#ifndef __EMBER_INPUT_LISTENER_H
#define __EMBER_INPUT_LISTENER_H

/*
 * @file IInputListener.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "core/EmberTypes.h"

namespace ember
{
	namespace input
	{
		using namespace ember::core;
		
		class IInputListener
		{
			public:
			
				virtual ~IInputListener() { }
				
				virtual I32 VGetPriority() const = 0;
		};
	}
}

#endif
