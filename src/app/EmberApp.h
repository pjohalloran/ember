#pragma once
#ifndef __EMBER_APP_H
#define __EMBER_APP_H

/*
 * @file EmberApp.h
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include <vector>

#include "core/Ember.h"
#include "app/AbstractSystem.h"

namespace ember
{
	namespace app
	{
	
		using ember::core;
		
		class EmberApp
		{
			private:
			
				std::vector<AbstractSystem> _systems;
				
				void MainLoop();
				
			protected:
			
				virtual void InitializeSystems() { }
				
				virtual void VPollInput() { }
				
				virtual void VUpdate() { }
				
				virtual void VRender() { }
				
			public:
			
				EmberApp() { }
				virtual ~EmberApp() { }
				
				bool Initialize()
				{
					return false;
				}
				
		};
		
		extern EmberApp *g_appPtr;
	}
}

#endif
