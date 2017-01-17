/*
 * @file EventSystem.cpp
 * @author PJ O Halloran
 * @date 17/01/2017
 */

#include "EventSystem.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		
		const char *EventSystem::Name = "Event";
		
		EventSystem::EventSystem( I32 id, I32 priority ) : AbstractSystem( id, priority )
		{
		
		}
		
		bool EventSystem::VInitialize( int argc, char **argv )
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool EventSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when already running!", Name );
				return true;
			}
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *EventSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
