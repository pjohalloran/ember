/*
 * @file ScriptingSystem.cpp
 * @author PJ O Halloran
 * @date 06/01/2017
 */

#include "ScriptingSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		const char *ScriptingSystem::Name = "Scripting";
		
		bool ScriptingSystem::InitDefaultConfig()
		{
			// Raw string literal for easy multiline
			return RunScript( R"(
                        Render = {
                        }
                        Time = {
                        }
                        Window = {
                            gl_major = 4,
                            gl_minor = 1,
                            gl_debug = false
                        }
                        Logging = {
                            files = {
                                [0] = {
                                    name = "all.log",
                                    type = 1,
                                    level = 9
                                },
                                [1] = {
                                    name = "last_run.log",
                                    type = 0,
                                    level = 0
                                }
                            },
                            error_level = 1
                        }
                        File = {
                        }
                        Input = {
                        }
                        Profiler = {
                        })"
			                );
		}
		
		ScriptingSystem::ScriptingSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ), _lua( nullptr )
		{
			// This system needs to get setup and running before everything else as it provides config
			// data for all other sub systems in the engine.
			_lua = new sol::state();
			
			if ( _lua == nullptr )
			{
				printf( "Failed to create the sol2 Lua context." );
				return;
			}
			
			_lua->open_libraries( sol::lib::base,
			                      sol::lib::package,
			                      sol::lib::coroutine,
			                      sol::lib::string,
			                      sol::lib::os,
			                      sol::lib::math,
			                      sol::lib::table,
			                      sol::lib::debug,
			                      sol::lib::bit32,
			                      sol::lib::io,
			                      sol::lib::ffi,
			                      sol::lib::jit );
			                      
			if ( !InitDefaultConfig() )
			{
				printf( "Failed to initialize the default config script" );
				return;
			}
			
			_initialized = true;
		}
		
		bool ScriptingSystem::VInitialize( int argc, char **argv )
		{
			return true;
		}
		
		bool ScriptingSystem::VShutdown()
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "Tried to shutdown %s when already running!", Name );
				return true;
			}
			
			delete _lua;
			_lua = nullptr;
			
			LOG_F( INFO, "%s shutdown", Name );
			_initialized = false;
			return true;
		}
		
		const char *ScriptingSystem::VGetSystemName()
		{
			return Name;
		}
		
		bool ScriptingSystem::RunScript( const char *scriptData )
		{
			if ( _lua == nullptr )
			{
				LOG_F( WARNING, "sol::state is not yet ready!" );
				return false;
			}
			
			sol::function_result result = _lua->script( scriptData );
			CHECK_WITH_INFO_F( result.valid(), "Failed to execute the script (%s)", "%s", scriptData );
			return result.valid();
		}
		
		bool ScriptingSystem::SetConfig( const char *configScript )
		{
			return RunScript( configScript );
		}
		
		sol::table ScriptingSystem::GetConfig( const char *name )
		{
			if ( !VInitialized() )
			{
				LOG_F( WARNING, "%s is not yet Running!", Name );
				return nullptr;
			}
			
			if ( name == nullptr || strlen( name ) == 0 )
			{
				LOG_F( WARNING, "invalid parameters" );
				return nullptr;
			}
			
			return ( *_lua )[name];
		}
	}
}
