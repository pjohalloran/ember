#pragma once
#ifndef __EMBER_APP_H
#define __EMBER_APP_H

/*
 * @file EmberApp.h
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include <EASTL/vector.h>

#include "core/Ember.h"

#include "app/AbstractSystem.h"
#include "math/Random.h"

namespace ember
{
	namespace events
	{
		class EventSystem;
	}
	
	namespace app
	{
		using namespace ember::core;
		using namespace ember::math;
		
		class WindowSystem;
		class TimeSystem;
		class InputSystem;
		class FileSystem;
		class RenderSystem;
		class ScriptingSystem;
		
		class EmberApp
		{
			private:
			
				eastl::vector<AbstractSystem *> _systems;
				
				WindowSystem *_windowSystem;
				TimeSystem *_timeSystem;
				InputSystem *_inputSystem;
				FileSystem *_fileSystem;
				RenderSystem *_renderSystem;
				ScriptingSystem *_scriptSystem;
				events::EventSystem *_eventSystem;
				
				Random *_rng;
				
				void Sleep( F64 seconds );
				
			protected:
			
				virtual bool VInitializeSystems( int argc, char **argv );
				
				virtual void VUpdate();
				
				virtual void VRender();
				
			public:
			
				EmberApp();
				virtual ~EmberApp();
				
				bool Initialize( int argc, char **argv );
				
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
				
				inline FileSystem *File() const
				{
					return _fileSystem;
				}
				
				inline RenderSystem *Render() const
				{
					return _renderSystem;
				}
				
				inline ScriptingSystem *Script() const
				{
					return _scriptSystem;
				}
				
				inline events::EventSystem *Event() const
				{
					return _eventSystem;
				}
				
				inline Random *RNG() const
				{
					return _rng;
				}
		};
		
		extern EmberApp *Application;
	}
}

#endif
