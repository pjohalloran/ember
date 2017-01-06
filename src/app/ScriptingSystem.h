#ifndef __EMBER_SCRIPTING_SYSTEM_H
#define __EMBER_SCRIPTING_SYSTEM_H

/*
 * @file ScriptingSystem.h
 * @author PJ O Halloran
 * @date 06/01/2017
 */

#include "app/AbstractSystem.h"

#include <sol.hpp>

namespace ember
{
	namespace app
	{
		class ScriptingSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				sol::state *lua;
				
			public:
				ScriptingSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), lua( nullptr ) { };
				virtual ~ScriptingSystem() { }
				
				virtual bool VInitialize();
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
		};
	}
}

#endif
