/*
 * @file InputSystem.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "InputSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		bool InputSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize input system when already running!" );
				return true;
			}
			
			// TODO Allow input mapping for players.
			
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
				LOG_F( WARNING, "Tried to shutdown input system when not already running!" );
				return true;
			}
			
			_initialized = false;
			return true;
		}
	}
}
