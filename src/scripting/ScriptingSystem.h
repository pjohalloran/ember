#ifndef __EMBER_SCRIPTING_SYSTEM_H
#define __EMBER_SCRIPTING_SYSTEM_H

/*
 * @file ScriptingSystem.h
 * @author PJ O Halloran
 * @date 06/01/2017
 */

#include "app/AbstractSystem.h"

//#define SOL_USING_CXX_LUA
//#define SOL_USING_CXX_LUAJIT
#include <sol2/sol.hpp>

namespace ember
{
	namespace scripting
	{
        using namespace ember::core;
        using namespace ember::app;
        
		class ScriptingSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				sol::state *_lua;
				
				bool InitDefaultConfig();
				
			public:
				ScriptingSystem( I32 initPriority, I32 updatePriority );
				virtual ~ScriptingSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
				
				inline sol::state *Lua() const
				{
					return _lua;
				};
				
				bool RunScript( const char *configScript );
				
				bool SetConfig( const char *configScript );
				
				sol::table GetConfig( const char *name );
				
		};
	}
}

#endif
