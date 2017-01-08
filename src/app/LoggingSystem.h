#ifndef __EMBER_LOGGING_SYSTEM_H
#define __EMBER_LOGGING_SYSTEM_H

/*
 * @file LoggingSystem.h
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class LoggingSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
			public:
				LoggingSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ) { };
				virtual ~LoggingSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
		};
	}
}

#endif
