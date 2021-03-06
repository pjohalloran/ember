#ifndef __EMBER_PROFILER_SYSTEM_H
#define __EMBER_PROFILER_SYSTEM_H

/*
 * @file ProfilerSystem.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	using namespace ember::core;
	
	namespace app
	{
		class ProfilerSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				Remotery *_remotery;
				
			public:
				ProfilerSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ), _remotery( nullptr ) { }
				virtual ~ProfilerSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() {}
				
				virtual const char *VGetSystemName();
		};
	}
}

#endif
