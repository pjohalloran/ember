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
			// TODO: Make data driven.
			
			AbstractSystem *loggingSystem = new LoggingSystem( 0, 1 );
			loggingSystem->VInitialize();
			_systems.push_back( loggingSystem );
			
			_windowSystem = new WindowSystem( 1, 2 );
			_windowSystem->VInitialize();
			_systems.push_back( _windowSystem );
			
			return false;
		}
		
		void EmberApp::VUpdate()
		{
		
		}
		
		void EmberApp::VRender()
		{
			glClear( GL_COLOR_BUFFER_BIT );
			
			_windowSystem->SwapBuffers();
			
			// TODO: Rendering
		}
	}
}
