/*
 * @file InputSystem.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include <algorithm>

#include "InputSystem.h"

#include "input/IKeyboardListener.h"
#include "input/IMouseListener.h"
#include "input/IGamepadListener.h"

#include "app/EmberApp.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		void OnGLFWKeyEvent( GLFWwindow *window, I32 key, I32 scanCode, I32 action, I32 mods )
		{
			LOG_F( INFO, "key %i scanCode %i action %i mods %i", key, scanCode, action, mods );
		}
		
		void OnGLFWCharacterInputEvent( GLFWwindow *window, U32 codePoint, I32 mods )
		{
			LOG_F( INFO, "codePoint %i mods %i", codePoint, mods );
		}
		
		void OnGLFWMouseButtonEvent( GLFWwindow *window, I32 button, I32 action, I32 mods )
		{
			LOG_F( INFO, "button %i action %i mods %i", button, action, mods );
		}
		
		void OnGLFWMouseMovedEvent( GLFWwindow *window, F64 x, F64 y )
		{
			LOG_F( INFO, "x %f y %f", x, y );
		}
		
		void OnGLFWMouseScrollEvent( GLFWwindow *window, double xOffset, double yOffset )
		{
			LOG_F( INFO, "xOffset %f yOffset %f", xOffset, yOffset );
		}
		
		void OnGLFWJoystickPluggedEvent( I32 joy, I32 event )
		{
			LOG_F( INFO, "joy %i event %i", joy, event );
		}
		
		void OnGLFWFileDropEvent( GLFWwindow *window, int count, const char **paths )
		{
			LOG_F( INFO, "file drop # %i", count );
		}
		
		const char *InputSystem::Name = "Input";
		
		bool InputSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be intialized before the %s", Name );
			
			glfwSetKeyCallback( Application->Window()->GetWindow(), OnGLFWKeyEvent );
			glfwSetCharModsCallback( Application->Window()->GetWindow(), OnGLFWCharacterInputEvent );
			glfwSetMouseButtonCallback( Application->Window()->GetWindow(), OnGLFWMouseButtonEvent );
			glfwSetCursorPosCallback( Application->Window()->GetWindow(), OnGLFWMouseMovedEvent );
			glfwSetScrollCallback( Application->Window()->GetWindow(), OnGLFWMouseScrollEvent );
			glfwSetJoystickCallback( OnGLFWJoystickPluggedEvent );
			glfwSetDropCallback( Application->Window()->GetWindow(), OnGLFWFileDropEvent );
			
			// TODO Allow input mapping for players.
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		void InputSystem::VUpdate()
		{
			if ( !VInitialized() )
			{
				return;
			}
			
			glfwPollEvents();
			
			// TODO better system to pass input events around the App rather than polling GLFW everywhere.
		}
		
		bool InputSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when not already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be running before the %s can be shutdown", Name );
			
			glfwSetKeyCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetCharModsCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetMouseButtonCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetCursorPosCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetScrollCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetJoystickCallback( nullptr );
			glfwSetDropCallback( Application->Window()->GetWindow(), nullptr );
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *InputSystem::VGetSystemName()
		{
			return Name;
		}
		
		template<typename T>
		bool AddListener( T *listener, std::vector<T *> &container )
		{
			if ( listener == nullptr )
			{
				LOG_F( WARNING, "Tried to add null pointer to Listeners" );
				return false;
			}
			
			typename std::vector<T *>::iterator it;
			it = std::find( container.begin(), container.end(), listener );
			
			if ( it != container.end() )
			{
				LOG_F( WARNING, "Tried to add duplicate pointer to Listeners (%p)", listener );
				return false;
			}
			
			container.push_back( listener );
			return true;
		}
		
		template<typename T>
		bool RemoveListener( T *listener, std::vector<T *> &container )
		{
			if ( listener == nullptr )
			{
				LOG_F( WARNING, "Tried to remove null pointer from Listeners" );
				return false;
			}
			
			typename std::vector<T *>::iterator it;
			it = std::remove( container.begin(), container.end(), listener );
			return it != container.end();
		}
		
		bool InputSystem::Add( IKeyboardListener *listener )
		{
			return AddListener( listener, _keyboardListeners );
		}
		
		bool InputSystem::Add( IMouseListener *listener )
		{
			return AddListener( listener, _mouseListeners );
		}
		
		bool InputSystem::Add( IGamepadListener *listener )
		{
			return AddListener( listener, _gamepadListeners );
		}
		
		bool InputSystem::Remove( IKeyboardListener *listener )
		{
			return RemoveListener( listener, _keyboardListeners );
		}
		
		bool InputSystem::Remove( IMouseListener *listener )
		{
			return RemoveListener( listener, _mouseListeners );
		}
		
		bool InputSystem::Remove( IGamepadListener *listener )
		{
			return RemoveListener( listener, _gamepadListeners );
		}
		
		void InputSystem::Clear()
		{
			_keyboardListeners.clear();
			_mouseListeners.clear();
			_gamepadListeners.clear();
		}
	}
}
