/*
 * @file EmberApp.cpp
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "app/EmberApp.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		// Initialize the global, extern game application pointer.
		EmberApp *g_appPtr = NULL;
		
		EmberApp::EmberApp()
		{
			g_appPtr = this;
			LOG_F( INFO, "EmberApp() done" );
		}
		
		EmberApp::~EmberApp()
		{
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
