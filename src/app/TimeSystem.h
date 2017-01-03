#ifndef __EMBER_TIME_SYSTEM_H
#define __EMBER_TIME_SYSTEM_H

/*
 * @file TimeSystem.h
 * @author PJ O Halloran
 * @date 18/12/2016
 */

#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
		class TimeSystem : public AbstractSystem
		{
			private:
				static const char *Name;
				
				U64 _frameCount;
				F64 _startAppTime;
				F64 _lastFrameTime;
				F64 _startFrameTime;
				
			public:
				TimeSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _startAppTime( 0.0 ), _lastFrameTime( 0.0 ), _startFrameTime( 0.0 ), _frameCount( 0 ) { };
				virtual ~TimeSystem() { }
				
				virtual bool VInitialize();
				
				virtual void VUpdate();
				
				virtual bool VShutdown();
				
				virtual const char *VGetSystemName();
				
				inline F64 GetCurrentTime() const
				{
					return glfwGetTime();
				}
				
				inline F64 TimeSinceAppStart() const
				{
					return GetCurrentTime() - _startAppTime;
				}
				
				inline F64 TimeSinceFrameStart() const
				{
					return GetCurrentTime() - _startFrameTime;
				}
				
				inline F64 LastFrameTime() const
				{
					return _lastFrameTime;
				}
				
				inline U64 FrameCount() const
				{
					return _frameCount;
				}
		};
	}
}

#endif
