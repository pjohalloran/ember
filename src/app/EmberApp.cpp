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
		EmberApp *g_appPtr = NULL;
		
		EmberApp::EmberApp() : _systems()
		{
			g_appPtr = this;
			LOG_F( INFO, "EmberApp() done" );
		}
		
		EmberApp::~EmberApp()
		{
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
			
			g_appPtr = nullptr;
		}
		
		bool EmberApp::Initialize()
		{
			return VInitializeSystems();
		}
		
		void EmberApp::Run()
		{
			VPollInput();
			
			VUpdate();
			
			VRender();
		}
		
		bool EmberApp::VInitializeSystems()
		{
			AbstractSystem *loggingSystem = new LoggingSystem( 0, 1 );
			loggingSystem->VInitialize();
			_systems.push_back( loggingSystem );
			
			return false;
		}
		
		void EmberApp::VPollInput()
		{
		
		}
		
		void EmberApp::VUpdate()
		{
		
		}
		
		void EmberApp::VRender()
		{
		
		}
	}
}
