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
				
			protected:
			
				bool _initialized;
				
			public:
			
				AbstractSystem( int id, int priority ) : _id( id ), _priority( priority ), _initialized( false ) { }
				
				virtual ~AbstractSystem()
				{
					if ( VInitialized() )
					{
						VShutdown();
					}
				}
				
				virtual bool VInitialize() = 0;
				virtual void VUpdate() = 0;
				virtual bool VShutdown() = 0;
				
				virtual bool VInitialized() const
				{
					return _initialized;
				}
				
				inline I32 GetPriority() const
				{
					return _priority;
				}
				
				inline I32 GetId() const
				{
					return _id;
				}
		};
	}
}

#endif
