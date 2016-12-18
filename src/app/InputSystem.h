#ifndef __EMBER_INPUT_SYSTEM_H
#define __EMBER_INPUT_SYSTEM_H

/*
 * @file InputSystem.h
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class InputSystem : public AbstractSystem
		{
			private:
			
			public:
				InputSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ) { };
				virtual ~InputSystem() { }
				
				virtual bool VInitialize();
				virtual void VUpdate();
				virtual bool VShutdown();
		};
	}
}

#endif
