#ifndef __EMBER_FILE_SYSTEM_H
#define __EMBER_FILE_SYSTEM_H

/*
 * @file FileSystem.h
 * @author PJ O Halloran
 * @date 27/12/2016
 */

#include "app/AbstractSystem.h"

#include <filesystem/path.h>

namespace ember
{
	namespace app
	{
		class FileSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				filesystem::path _exePath;
				
			public:
				FileSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ), _exePath() { };
				virtual ~FileSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
				
				filesystem::path GetExePath() const
				{
					return _exePath;
				};
		};
	}
}

#endif
