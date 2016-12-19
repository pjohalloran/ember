#ifndef __EMBER_INPUT_SYSTEM_H
#define __EMBER_INPUT_SYSTEM_H

/*
 * @file InputSystem.h
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include <vector>

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class IKeyboardListener;
		class IMouseListener;
		class IGamepadListener;
		
		class InputSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				std::vector<IKeyboardListener *> _keyboardListeners;
				std::vector<IMouseListener *> _mouseListeners;
				std::vector<IGamepadListener *> _gamepadListeners;
				
			public:
				InputSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _keyboardListeners(), _mouseListeners(), _gamepadListeners() { };
				
				virtual ~InputSystem()
				{
					Clear();
				}
				
				virtual bool VInitialize();
				
				virtual void VUpdate();
				
				virtual bool VShutdown();
				
				virtual const char *VGetSystemName();
				
				bool Add( IKeyboardListener *listener );
				bool Add( IMouseListener *listener );
				bool Add( IGamepadListener *listener );
				
				bool Remove( IKeyboardListener *listener );
				bool Remove( IMouseListener *listener );
				bool Remove( IGamepadListener *listener );
				
				void Clear();
		};
	}
}

#endif
