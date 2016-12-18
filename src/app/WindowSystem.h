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
	// TMP for WindowSystem to have near final API - until i import my math lib.
	namespace math
	{
		using namespace ember::core;
		
		struct Vector2
		{
			public:
				F32 x;
				F32 y;
		};
	}
	
	namespace app
	{
		using namespace ember::math;
		
		class WindowSystem : public AbstractSystem
		{
			private:
			
				GLFWwindow *_window;
				
			public:
				WindowSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _window( nullptr ) { };
				virtual ~WindowSystem() { }
				
				virtual bool VInitialize();
				
				virtual void VUpdate() { }
				
				virtual bool VShutdown();
				
				virtual bool VInitialized() const
				{
					return _initialized && _window != nullptr;
				}
				
				bool IsClosing() const;
				
				bool GetWindowSize( Vector2 &dim ) const;
				
				bool GetFrameBufferSize( Vector2 &dim ) const;
				
				bool GetDpi( int &dpi ) const;
				
				void PollEvents();
				
				void SwapBuffers();
		};
	}
}

#endif
