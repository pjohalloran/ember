#ifndef __EMBER_WINDOW_SYSTEM_H
#define __EMBER_WINDOW_SYSTEM_H

/*
 * @file WindowSystem.h
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class WindowSystem : public AbstractSystem
		{
			private:
			
				GLFWwindow *_window;
				
			public:
				WindowSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _window( nullptr ) { };
				virtual ~WindowSystem() { }
				
				virtual bool VInitialize();
				virtual bool VShutdown();
				
				virtual bool VInitialized() const
				{
					return _initialized && _window != nullptr;
				}
				
				inline GLFWwindow *GetWindow() const
				{
					return _window;
				}
				
				void PollEvents();
				
				void SwapBuffers();
		};
	}
}

#endif
