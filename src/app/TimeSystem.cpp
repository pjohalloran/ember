/*
 * @file TimeSystem.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "TimeSystem.h"

#include "EmberApp.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		const char *TimeSystem::Name = "Time";
		
		bool TimeSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			CHECK_WITH_INFO_F( Application != nullptr && Application->Window() != nullptr && Application->Window()->VInitialized(), "WindowSystem needs to be intialized before the %s", Name );
			
			// glfwInit was called soon before this, but just set to 0 now to reset.
			glfwSetTime( 0.0 );
			_startAppTime = GetCurrentTime();
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		void TimeSystem::VUpdate()
		{
			if ( !VInitialized() )
			{
				return;
			}
			
			++_frameCount;
			
			F64 currTime = GetCurrentTime();
			_lastFrameTime = currTime - _startFrameTime;
			_startFrameTime = currTime;
		}
		
		bool TimeSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when not already running!", Name );
				return true;
			}
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *TimeSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
