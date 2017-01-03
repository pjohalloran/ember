/*
 * @file EmberApp.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include <chrono>
#include <thread>

#include <EASTL/sort.h>

#include "EmberApp.h"

#include "core/EmberTimer.h"

#include "app/WindowSystem.h"
#include "app/TimeSystem.h"
#include "app/InputSystem.h"
#include "app/LoggingSystem.h"
#include "app/FileSystem.h"
#include "app/RenderSystem.h"
#include "app/ProfilerSystem.h"

#include "Remotery/Remotery.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		using namespace ember::math;
		
		//
		// Sub System execution order sorting
		//
		
		bool SortForInit( AbstractSystem *a, AbstractSystem *b )
		{
			return a != nullptr && b != nullptr && ( a->GetInitPriority() < b->GetInitPriority() );
		}
		
		bool SortForUpdate( AbstractSystem *a, AbstractSystem *b )
		{
			return a != nullptr && b != nullptr && ( a->GetUpdatePriority() < b->GetUpdatePriority() );
		}
		
		bool SortForShutdown( AbstractSystem *a, AbstractSystem *b )
		{
			return a != nullptr && b != nullptr && ( a->GetInitPriority() > b->GetInitPriority() );
		}
		
		//
		// EmberApp
		//
		
		// Initialize the global, extern game application pointer.
		EmberApp *Application = NULL;
		
		EmberApp::EmberApp() : _systems(), _windowSystem( nullptr )
		{
			Application = this;
			
			_rng = new Random();
			_rng->Randomize();
			
			// TODO: Make system setup order and whats used/needed data driven.
			
			AbstractSystem *loggingSystem = new LoggingSystem( 1, 0 );
			_systems.push_back( loggingSystem );
			
			AbstractSystem *profilerSystem = new ProfilerSystem( 2, 0 );
			_systems.push_back( profilerSystem );
			
			_fileSystem = new FileSystem( 3, 0 );
			_systems.push_back( _fileSystem );
			
			_windowSystem = new WindowSystem( 4, 0 );
			_systems.push_back( _windowSystem );
			
			_renderSystem = new RenderSystem( 5, 0 );
			_systems.push_back( _renderSystem );
			
			_timeSystem = new TimeSystem( 6, 1 );
			_systems.push_back( _timeSystem );
			
			_inputSystem = new InputSystem( 7, 2 );
			_systems.push_back( _inputSystem );
			
			eastl::sort( _systems.begin(), _systems.end(), SortForInit );
			
			DLOG_F( INFO, "EmberApp() done" );
		}
		
		EmberApp::~EmberApp()
		{
			eastl::sort( _systems.begin(), _systems.end(), SortForShutdown );
			
			for ( U32 i = 0, size = _systems.size(); i < size; ++i )
			{
				if ( _systems[i] != nullptr )
				{
					_systems[i]->VShutdown();
					delete _systems[i];
					_systems[i] = nullptr;
				}
			}
			
			_systems.clear();
			
			Delete( _rng );
			
			Application = nullptr;
		}
		
		bool EmberApp::Initialize()
		{
			return VInitializeSystems();
		}
		
		void EmberApp::Sleep( F64 seconds )
		{
			std::this_thread::sleep_for( std::chrono::duration<F64>( seconds ) );
			DLOG_F( INFO, "App Sleep for %f s on frame %lu", seconds, Time()->FrameCount() );
		}
		
		void EmberApp::Run()
		{
			F64 targetFrameRateTime = 1.0 / 30; // TMP
			
			while ( !_windowSystem->IsClosing() )
			{
				VUpdate();
				
				VRender();
				
				F64 timeToSleep = targetFrameRateTime - Time()->TimeSinceFrameStart();
				
				if ( timeToSleep > 0.0 )
				{
					Sleep( timeToSleep );
				}
			}
		}
		
		bool EmberApp::VInitializeSystems()
		{
			bool result = true;
			
			for ( U32 i = 0, size = _systems.size(); ( result && i < size ); ++i )
			{
				if ( _systems[i] != nullptr )
				{
					result = _systems[i]->VInitialize();
				}
			}
			
			if ( result )
			{
				eastl::sort( _systems.begin(), _systems.end(), SortForUpdate );
			}
			
			return result;
		}
		
		void EmberApp::VUpdate()
		{
			EmberTimer timer;
			timer.Start();
			
			rmt_BeginCPUSample( VUpdate, 0 );
			
			for ( U32 i = 0, size = _systems.size(); i < size; ++i )
			{
				if ( _systems[i] != nullptr )
				{
					_systems[i]->VUpdate();
				}
			}
			
			rmt_EndCPUSample();
			
			timer.Stop();
			
			if ( timer.Duration() > 0.0 )
			{
				DLOG_F( INFO, "App Update took %f s on frame %lu", timer.Duration(), Time()->FrameCount() );
			}
		}
		
		void EmberApp::VRender()
		{
			EmberTimer timer;
			timer.Start();
			
			//rmt_BeginOpenGLSample( VRender );
			rmt_BeginCPUSample( VRender, 0 );
			
			_renderSystem->Clear();
			_renderSystem->SwapBuffers();
			_renderSystem->Draw();
			
			
			rmt_EndCPUSample();
			//rmt_EndOpenGLSample();
			
			timer.Stop();
			
			if ( timer.Duration() > 0.0 )
			{
				DLOG_F( INFO, "App Render took %f s on frame %lu", timer.Duration(), Time()->FrameCount() );
			}
		}
	}
}
