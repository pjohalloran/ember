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
		
		EmberApp::EmberApp()
		{
			g_appPtr = this;
			
		}
		
		EmberApp::~EmberApp()
		{
			g_appPtr = nullptr;
		}
		
		bool EmberApp::Initialize()
		{
			return false;
		}
		
		void EmberApp::Run()
		{
		
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
