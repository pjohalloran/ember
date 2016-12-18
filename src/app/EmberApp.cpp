/*
 * @file EmberApp.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

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
			
			AbstractSystem *loggingSystem = new LoggingSystem( 0, 1 );
			_systems.push_back( loggingSystem );
			
			_windowSystem = new WindowSystem( 1, 2 );
			_systems.push_back( _windowSystem );
			
			_timeSystem = new TimeSystem( 2, 3 );
			_systems.push_back( _timeSystem );
			
			LOG_F( INFO, "EmberApp() done" );
		}
		
		EmberApp::~EmberApp()
		{
			for ( U32 i = _systems.size() - 1; i != 0; --i )
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
		
		void EmberApp::Run()
		{
			while ( !_windowSystem->IsClosing() )
			{
				_windowSystem->PollEvents();
				
				VUpdate();
				
				VRender();
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
			
			return result;
		}
		
		void EmberApp::VUpdate()
		{
			for ( U32 i = 0, size = _systems.size(); i < size; ++i )
			{
				if ( _systems[i] != nullptr )
				{
					_systems[i]->VUpdate();
				}
			}
			
			LOG_F( INFO, "Frame Count %ul Last Frame Time %f Time Since App Start %f", Time()->FrameCount(), Time()->LastFrameTime(), Time()->TimeSinceAppStart() );
		}
		
		void EmberApp::VRender()
		{
			glClear( GL_COLOR_BUFFER_BIT );
			
			_windowSystem->SwapBuffers();
			
			// TODO: Rendering
		}
	}
}
