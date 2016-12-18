/*
 * @file LoggingSystem.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "LoggingSystem.h"

#include<loguru.hpp>

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		bool LoggingSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize logging system when already running!" );
				return true;
			}
			
			// TMP TODO replace with data driven config files.
			std::string arg0( "ember-test\0" );
			std::string arg1( "-v\0" );
			std::string arg2( "1\0" );
			I32 c = 3;
			char **args = new char *[3];
			args[0] = ( char * )arg0.c_str();
			args[1] = ( char * )arg1.c_str();
			args[2] = ( char * )arg2.c_str();
			// END TMP
			
			loguru::init( c, args );
			
			loguru::add_file( "ember_all.log", loguru::Append, loguru::Verbosity_MAX );
			loguru::add_file( "ember_last_run.log", loguru::Truncate, loguru::Verbosity_INFO );
			loguru::g_stderr_verbosity = 1;
			
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
			
			LOG_F( INFO, "logging system shutting down" );
			loguru::shutdown();
			
			_initialized = false;
			return true;
		}
	}
}
