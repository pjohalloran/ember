#ifndef __EMBER_PROFILER_SYSTEM_H
#define __EMBER_PROFILER_SYSTEM_H

/*
 * @file ProfilerSystem.h
 * @author PJ O Halloran
 * @date 19/12/2016
 */

#include <vector>

#include "app/AbstractSystem.h"

namespace ember
{
	using namespace ember::core;
	
	namespace profiler
	{
		struct CodeSample
		{
			F32 Duration;
			char *Name;
		};
		
		struct FrameStats
		{
			U32 FrameId;
			F32 Duration;
			
			U32 SamplesUsedCount;
			
			CodeSample Samples[100];
		};
		
		struct OneSecondIntervalStats
		{
			U32 FramesUsedCount;
			
			FrameStats Frames[300];
		};
	}
	
	namespace app
	{
		using namespace ember::profiler;
		
		class ProfilerSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
				std::vector<OneSecondIntervalStats *> _stats;
				bool _active;
				U32 _sampleCount;
				
			public:
				ProfilerSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ), _stats(), _active( false ), _sampleCount( 0 ) { }
				virtual ~ProfilerSystem() { }
				
				virtual bool VInitialize();
				
				virtual bool VShutdown();
				
				virtual void VUpdate();
				
				virtual const char *VGetSystemName();
				
				void Activate();
				
				void Deactivate();
				
				inline bool IsActive() const
				{
					return _active;
				}
				
				void SetMaxIntervalCount( U32 size );
				
				void BeginCodeSample( char *name );
				
				void EndCodeSample();
		};
	}
}

#endif
