#pragma once
#ifndef __EMBER_ABSTRACT_SYSTEM_H
#define __EMBER_ABSTRACT_SYSTEM_H

/*
 * @file AbstractSystem.h
 * @author PJ O Halloran
 * @date 17/12/2016
 */

#include "core/Ember.h"

namespace ember
{
	namespace app
	{
		using namespace ember::core;
		
		class AbstractSystem
		{
			private:
			
				I32 _id;
				I32 _priority;
				bool _initialized;
				
			public:
			
				AbstractSystem( int id, int priority ) : _id( id ), _priority( priority )
				{
					_initialized = false;
				}
				
				virtual ~AbstractSystem() {};
				
				virtual bool VInitialize() = 0;
				virtual bool VShutdown() = 0;
				
				bool Initialized() const
				{
					return _initialized;
				}
				
				I32 GetPriority() const
				{
					return _priority;
				}
				
				I32 GetId() const
				{
					return _id;
				}
		};
	}
}

#endif
