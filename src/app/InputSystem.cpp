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
			
			_initialized = true;
			return true;
		}
		
		void InputSystem::VUpdate()
		{
			if ( !VInitialized() )
			{
				return;
			}
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
		
		void InputSystem::PollEvents()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Input system needs to be initialized before use." );
				return;
			}
			
			glfwPollEvents();
		}
	}
}
