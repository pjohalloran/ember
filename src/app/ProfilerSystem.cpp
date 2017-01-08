/*
 * @file ProfilerSystem.cpp
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "ProfilerSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		const char *ProfilerSystem::Name = "Profiler";
		
		bool ProfilerSystem::VInitialize( int argc, char **argv )
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			rmt_CreateGlobalInstance( &_remotery );
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool ProfilerSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				// no logging system to log warning to in this case.
				return true;
			}
			
			rmt_DestroyGlobalInstance( _remotery );
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *ProfilerSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
