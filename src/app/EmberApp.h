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
#include "app/InputSystem.h"

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
				InputSystem *_inputSystem;
				
				void Sleep( F64 seconds );
				
			protected:
			
				virtual bool VInitializeSystems();
				
				virtual void VUpdate();
				
				virtual void VRender();
				
			public:
			
				EmberApp();
				virtual ~EmberApp();
				
				bool Initialize();
				
				void Run();
				
				inline WindowSystem *Window() const
				{
					return _windowSystem;
				}
				
				inline InputSystem *Input() const
				{
					return _inputSystem;
				}
				
				inline TimeSystem *Time() const
				{
					return _timeSystem;
				}
		};
		
		extern EmberApp *Application;
	}
}

#endif
