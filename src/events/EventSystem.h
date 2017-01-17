#pragma once
#ifndef __EMBER_EVENT_SYSTEM_H
#define __EMBER_EVENT_SYSTEM_H

/*
 * @file EventSystem.h
 * @author PJ O Halloran
 * @date 17/01/2017
 */

#include "core/Ember.h"
#include "app/AbstractSystem.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		using namespace ember::app;
		
		struct Event;
		
		class EventSystem : public AbstractSystem
		{
			private:
			
				static const char *Name;
				
			public:
				EventSystem( I32 id, I32 priority ) : AbstractSystem( id, priority ) {}
				virtual ~EventSystem() { }
				
				virtual bool VInitialize( int argc, char **argv );
				
				virtual bool VShutdown();
				
				virtual void VUpdate() { }
				
				virtual const char *VGetSystemName();
				
		};
	}
}

#endif
