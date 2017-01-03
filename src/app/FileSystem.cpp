/*
 * @file FileSystem.cpp
 * @author PJ O Halloran
 * @date 27/12/2016
 */

#include "FileSystem.h"

#include <path.h>

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		using namespace filesystem;
		
		const char *FileSystem::Name = "File";
		
		bool FileSystem::VInitialize()
		{
			if ( VInitialized() )
			{
				LOG_F( WARNING, "Tried to intialize %s when already running!", Name );
				return true;
			}
			
			_exePath = path::getcwd();
			DLOG_F( INFO, "FileSystem using ExePath = %s", _exePath.str().c_str() );
			
			LOG_F( INFO, "%s initialized", Name );
			_initialized = true;
			return true;
		}
		
		bool FileSystem::VShutdown()
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
		
		const char *FileSystem::VGetSystemName()
		{
			return Name;
		}
	}
}
