#ifndef __EMBER_RENDER_SYSTEM_H
#define __EMBER_RENDER_SYSTEM_H

/*
 * @file RenderSystem.h
 * @author PJ O Halloran
 * @date 27/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class RenderSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
			public:
				RenderSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ) { };
				virtual ~RenderSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
				
				void Clear();
				
				void SwapBuffers();
				
				void Draw();
		};
	}
}

#endif
