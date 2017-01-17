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
			
				static const F32 DPI;
				static const char *Name;
				
				GLFWwindow *_window;
				
			public:
				WindowSystem( I32 initPriority, I32 updatePriority ) : AbstractSystem( initPriority, updatePriority ), _window( nullptr ) { };
				virtual ~WindowSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual void VUpdate() { }
				
				virtual bool VShutdown();
				
				virtual const char *VGetSystemName();
				
				virtual bool VInitialized() const
				{
					return _initialized && _window != nullptr;
				}
				
				inline GLFWwindow *GetWindow() const
				{
					return _window;
				}
				
				bool IsClosing() const;
				
				bool GetWindowSize( F32 &width, F32 &height ) const;
				
				bool GetFrameBufferSize( F32 &width, F32 &height ) const;
				
				bool GetDpi( int &dpi ) const;
		};
	}
}

#endif
