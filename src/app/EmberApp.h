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
#include "app/WindowSystem.h"
#include "app/TimeSystem.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		class EmberApp
		{
			private:
			
				std::vector<AbstractSystem *> _systems;
				
				WindowSystem *_windowSystem;
				TimeSystem *_timeSystem;
				
			protected:
			
				virtual bool VInitializeSystems();
				
				virtual void VUpdate();
				
				virtual void VRender();
				
			public:
			
				EmberApp();
				virtual ~EmberApp();
				
				bool Initialize();
				
				void Run();
				
				WindowSystem *Window() const
				{
					return _windowSystem;
				}
				
				TimeSystem *Time() const
				{
					return _timeSystem;
				}
		};
		
		extern EmberApp *Application;
	}
}

#endif
