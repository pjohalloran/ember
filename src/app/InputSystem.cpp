/*
 * @file InputSystem.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include <EASTL/algorithm.h>

#include "InputSystem.h"

#include "app/EmberApp.h"
#include "app/WindowSystem.h"
#include "app/TimeSystem.h"

#include "input/IKeyboardListener.h"
#include "input/IMouseListener.h"
#include "input/IGamepadListener.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		//
		// GLFW Input callbacks
		//
		
		void OnGLFWKeyEvent( GLFWwindow *window, I32 key, I32 scanCode, I32 action, I32 mods )
		{
			DLOG_F( INFO, "key %i scanCode %i action %i mods %i", key, scanCode, action, mods );
			
			if ( action == GLFW_REPEAT )
			{
				return;
			}
			
			Application->Input()->TriggerKey( key, scanCode, action, mods );
		}
		
		void OnGLFWCharacterInputEvent( GLFWwindow *window, U32 codePoint, I32 mods )
		{
			DLOG_F( INFO, "codePoint %i mods %i", codePoint, mods );
			Application->Input()->TriggerCharacterInput( codePoint, mods );
		}
		
		void OnGLFWMouseButtonEvent( GLFWwindow *window, I32 button, I32 action, I32 mods )
		{
			DLOG_F( INFO, "button %i action %i mods %i", button, action, mods );
			
			if ( action == GLFW_REPEAT )
			{
				return;
			}
			
			Application->Input()->TriggerMouseButton( button, action, mods );
		}
		
		void OnGLFWMouseMovedEvent( GLFWwindow *window, F64 x, F64 y )
		{
			DLOG_F( INFO, "x %f y %f", x, y );
			Application->Input()->TriggerMouseMove( Point2( ( F32 )x, ( F32 )y ) );
		}
		
		void OnGLFWMouseScrollEvent( GLFWwindow *window, F64 xOffset, F64 yOffset )
		{
			DLOG_F( INFO, "xOffset %f yOffset %f", xOffset, yOffset );
			Application->Input()->TriggerMouseScroll( Point2( ( F32 )xOffset, ( F32 )yOffset ) );
		}
		
		void OnGLFWJoystickPluggedEvent( I32 joy, I32 event )
		{
			DLOG_F( INFO, "joy %i event %i", joy, event );
			Application->Input()->TriggerGamePadConnnection( joy, event );
		}
		
		void OnGLFWFileDropEvent( GLFWwindow *window, I32 count, const I8 **paths )
		{
			if ( count <= 0 || paths == nullptr )
			{
				return;
			}
			
			DLOG_F( INFO, "file drop # %i", count );
			Application->Input()->TriggerFileDrop( count, paths );
		}
		
		//
		// InputSystem
		//
		
		const char *InputSystem::Name = "Input";
		
		bool InputSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be intialized before the %s", "%s", Name );
			
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
		}
		
		bool InputSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when not already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be running before the %s can be shutdown", "%s", Name );
			
			glfwSetKeyCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetCharModsCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetMouseButtonCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetCursorPosCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetScrollCallback( Application->Window()->GetWindow(), nullptr );
			glfwSetJoystickCallback( nullptr );
			glfwSetDropCallback( Application->Window()->GetWindow(), nullptr );
			
			Clear();
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *InputSystem::VGetSystemName()
		{
			return Name;
		}
		
		//
		// InputSystem Trigger API
		//
		
		void InputSystem::TriggerKey( I32 key, I32 scanCode, I32 action, I32 mods )
		{
			for ( IKeyboardListener *i : _keyboardListeners )
			{
				if ( action == GLFW_PRESS )
				{
					i->VOnKeyPress( key );
				}
				else
				{
					i->VOnKeyRelease( key );
				}
			}
		}
		
		void InputSystem::TriggerCharacterInput( U32 codePoint, I32 mods )
		{
			for ( IKeyboardListener *i : _keyboardListeners )
			{
				i->VOnCharacterInput( codePoint );
			}
		}
		
		void InputSystem::TriggerMouseMove( const Point2 &position )
		{
			// GLFW uses top left for the origin but in this codebase, we use bottom left corner for screen space origin.
			F32 w, h;
			Application->Window()->GetWindowSize( w, h );
			Point2 positionCopy( position );
			positionCopy.SetY( h - positionCopy.Y() );
			
			Point2 relative;
			
			if ( Application->Time()->FrameCount() > 1 )
			{
				relative.Set( positionCopy.X() - _prevMouse.X(), positionCopy.Y() - _prevMouse.Y() );
			}
			
			for ( IMouseListener *i : _mouseListeners )
			{
				i->VOnMove( positionCopy, relative );
			}
			
			_prevMouse = positionCopy;
		}
		
		void InputSystem::TriggerMouseButton( I32 button, I32 action, I32 mods )
		{
			for ( IMouseListener *i : _mouseListeners )
			{
				if ( action == GLFW_PRESS )
				{
					i->VOnButtonPress( button );
				}
				else
				{
					i->VOnButtonRelease( button );
				}
			}
		}
		
		void InputSystem::TriggerMouseScroll( const Point2 &position )
		{
			for ( IMouseListener *i : _mouseListeners )
			{
				i->VOnScroll( position );
			}
		}
		
		void InputSystem::TriggerFileDrop( I32 count, const I8 **paths )
		{
			for ( IMouseListener *i : _mouseListeners )
			{
				i->VOnFileDrop( paths, count );
			}
		}
		
		void InputSystem::TriggerGamePadConnnection( I32 joy, I32 event )
		{
			for ( IGamepadListener *i : _gamepadListeners )
			{
				if ( event == GLFW_CONNECTED )
				{
					i->VOnConnect( joy );
				}
				else
				{
					i->VOnDisconnect( joy );
				}
			}
		}
		
		//
		// InputSystem Add/Remove callbacks API
		//
		
		template<typename T>
		bool AddListener( T *listener, eastl::vector<T *> &container )
		{
			if ( listener == nullptr )
			{
				LOG_F( WARNING, "Tried to add null pointer to Listeners" );
				return false;
			}
			
			typename eastl::vector<T *>::iterator it;
			it = eastl::find( container.begin(), container.end(), listener );
			
			if ( it != container.end() )
			{
				LOG_F( WARNING, "Tried to add duplicate pointer to Listeners (%p)", listener );
				return false;
			}
			
			container.push_back( listener );
			return true;
		}
		
		template<typename T>
		bool RemoveListener( T *listener, eastl::vector<T *> &container )
		{
			if ( listener == nullptr )
			{
				LOG_F( WARNING, "Tried to remove null pointer from Listeners" );
				return false;
			}
			
			typename eastl::vector<T *>::iterator it;
			it = eastl::remove( container.begin(), container.end(), listener );
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
