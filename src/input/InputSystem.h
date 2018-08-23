#ifndef __EMBER_INPUT_SYSTEM_H
#define __EMBER_INPUT_SYSTEM_H

/*
 * @file InputSystem.h
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include <EASTL/vector.h>

#include "app/AbstractSystem.h"

#include "math/Point2.h"

namespace ember
{
	namespace input
	{
		using namespace ember::app;
		using namespace ember::math;
        
        class IKeyboardListener;
        class IMouseListener;
        class IGamepadListener;
		
		class InputSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				eastl::vector<IKeyboardListener *> _keyboardListeners;
				eastl::vector<IMouseListener *> _mouseListeners;
				eastl::vector<IGamepadListener *> _gamepadListeners;
				
				Point2 _prevMouse;
				
			public:
				InputSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ), _keyboardListeners(), _mouseListeners(), _gamepadListeners(), _prevMouse() { };
				
				virtual ~InputSystem()
				{
					Clear();
				}
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual void VUpdate();
				
				virtual bool VShutdown();
				
				virtual const char *VGetSystemName();
				
				void TriggerKey( I32 key, I32 scanCode, I32 action, I32 mods );
				
				void TriggerCharacterInput( U32 codePoint, I32 mods );
				
				void TriggerMouseMove( const Point2 &position );
				
				void TriggerMouseButton( I32 button, I32 action, I32 mods );
				
				void TriggerMouseScroll( const Point2 &position );
				
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
