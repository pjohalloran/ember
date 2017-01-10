/*
 * @file LoggingSystem.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include <string>

#include "LoggingSystem.h"

#define LOGURU_IMPLEMENTATION 1
#include <loguru.hpp>

#include <sol.hpp>

#include "app/EmberApp.h"
#include "app/ScriptingSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		const char *LoggingSystem::Name = "Logging";
		
		bool LoggingSystem::VInitialize( int argc, char **argv )
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			loguru::init( argc, argv );
			
			sol::table logConfig = Application->Script()->GetConfig( Name );
			sol::table logFiles = logConfig["files"];
			
			logFiles.for_each( [&]( std::pair<sol::object, sol::object> pair )
			{
				sol::table logFileConfig = pair.second.as<sol::table>();
				
				if ( logFileConfig.valid() )
				{
					std::string name = logFileConfig["name"];
					int type = logFileConfig["type"];
					int level = logFileConfig["level"];
					loguru::add_file( name.c_str(), ( loguru::FileMode )type, ( loguru::Verbosity )level );
				}
			} );
			
			loguru::g_stderr_verbosity = logConfig["error_level"];
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool LoggingSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				// no logging system to log warning to in this case.
				return true;
			}
			
			LOG_F( INFO, "%s shutting down", Name );
			loguru::shutdown();
			
			_initialized = false;
			return true;
		}
		
		const char *LoggingSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
