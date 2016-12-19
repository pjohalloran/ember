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
	namespace input
	{
		class IKeyboardListener;
		class IMouseListener;
		class IGamepadListener;
	}
	
	namespace app
	{
		using namespace ember::input;
		
		class InputSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				std::vector<IKeyboardListener *> _keyboardListeners;
				std::vector<IMouseListener *> _mouseListeners;
				std::vector<IGamepadListener *> _gamepadListeners;
				
				F64 _prevMouseX;
				F64 _prevMouseY;
				
			public:
				InputSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _keyboardListeners(), _mouseListeners(), _gamepadListeners(), _prevMouseX( 0.0 ), _prevMouseY( 0.0 ) { };
				
				virtual ~InputSystem()
				{
					Clear();
				}
				
				virtual bool VInitialize();
				
				virtual void VUpdate();
				
				virtual bool VShutdown();
				
				virtual const char *VGetSystemName();
				
				void TriggerKey( I32 key, I32 scanCode, I32 action, I32 mods );
				
				void TriggerCharacterInput( U32 codePoint, I32 mods );
				
				void TriggerMouseMove( F64 x, F64 y );
				
				void TriggerMouseButton( I32 button, I32 action, I32 mods );
				
				void TriggerMouseScroll( F64 x, F64 y );
				
				void TriggerFileDrop( I32 count, const I8 **paths );
				
				void TriggerGamePadConnnection( I32 joy, I32 event );
				
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
