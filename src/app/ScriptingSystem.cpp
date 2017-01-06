/*
 * @file ScriptingSystem.cpp
 * @author PJ O Halloran
 * @date 06/01/2017
 */

#include "ScriptingSystem.h"

#include <sol.hpp>

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		const char *ScriptingSystem::Name = "Scripting";
		
		bool ScriptingSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			lua = new sol::state();
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool ScriptingSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when already running!", Name );
				return true;
			}
			
			delete lua;
			lua = nullptr;
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *ScriptingSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
