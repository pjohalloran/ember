/*
 * @file EmberApp.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include <algorithm>
#include <chrono>
#include <thread>

#include "core/EmberTimer.h"

#include "app/EmberApp.h"
#include "app/LoggingSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		// Initialize the global, extern game application pointer.
		EmberApp *Application = NULL;
		
		EmberApp::EmberApp() : _systems(), _windowSystem( nullptr )
		{
			Application = this;
			
			// TODO: Make system setup order and whats used/needed data driven.
			
			AbstractSystem *loggingSystem = new LoggingSystem( 1, 0 );
			_systems.push_back( loggingSystem );
			
			_windowSystem = new WindowSystem( 2, 0 );
			_systems.push_back( _windowSystem );
			
			_inputSystem = new InputSystem( 3, 2 );
			_systems.push_back( _inputSystem );
			
			_timeSystem = new TimeSystem( 4, 1 );
			_systems.push_back( _timeSystem );
			
			LOG_F( INFO, "EmberApp() done" );
		}
		
		EmberApp::~EmberApp()
		{
			// Reverse sort of init priority
			std::sort( _systems.begin(), _systems.end(),
			           []( const AbstractSystem * a, const AbstractSystem * b ) -> bool
			{
				return a != nullptr && b != nullptr && ( a->GetInitPriority() > b->GetInitPriority() );
			} );
			
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
			
			Application = nullptr;
		}
		
		bool EmberApp::Initialize()
		{
			return VInitializeSystems();
		}
		
		void EmberApp::Sleep( F64 seconds )
		{
			std::this_thread::sleep_for( std::chrono::duration<F64>( seconds ) );
			LOG_F( INFO, "App Sleep for %f s on frame %ul", seconds, Time()->FrameCount() );
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
			// Sort in order of increasing init priority.
			std::sort( _systems.begin(), _systems.end(),
			           []( const AbstractSystem * a, const AbstractSystem * b ) -> bool
			{
				return a != nullptr && b != nullptr && ( a->GetInitPriority() < b->GetInitPriority() );
			} );
			
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
				// Sort using desired priority for update.
				std::sort( _systems.begin(), _systems.end(),
				           []( const AbstractSystem * a, const AbstractSystem * b ) -> bool
				{
					return a != nullptr && b != nullptr && ( a->GetUpdatePriority() < b->GetUpdatePriority() );
				} );
			}
			
			return result;
		}
		
		void EmberApp::VUpdate()
		{
			EmberTimer timer;
			timer.Start();
			
			for ( U32 i = 0, size = _systems.size(); i < size; ++i )
			{
				if ( _systems[i] != nullptr )
				{
					_systems[i]->VUpdate();
				}
			}
			
			timer.Stop();
			
			if ( timer.Duration() > 0.0 )
			{
				LOG_F( INFO, "App Update took %f s on frame %ul", timer.Duration(), Time()->FrameCount() );
			}
		}
		
		void EmberApp::VRender()
		{
			EmberTimer timer;
			timer.Start();
			
			glClear( GL_COLOR_BUFFER_BIT );
			
			_windowSystem->SwapBuffers();
			
			// TODO: Rendering
			
			timer.Stop();
			
			if ( timer.Duration() > 0.0 )
			{
				LOG_F( INFO, "App Render took %f s on frame %ul", timer.Duration(), Time()->FrameCount() );
			}
		}
	}
}
