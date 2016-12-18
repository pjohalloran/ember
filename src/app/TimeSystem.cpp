/*
 * @file TimeSystem.cpp
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "TimeSystem.h"

#include<loguru.hpp>

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		bool TimeSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize time system when already running!" );
				return true;
			}
			
			// glfwInit was called soon before this, but just set to 0 now to reset.
			glfwSetTime( 0.0 );
			_startAppTime = GetCurrentTime();
			
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
				LOG_F( WARNING, "Tried to shutdown time system when not already running!" );
				return true;
			}
			
			_initialized = false;
			return true;
		}
	}
}
