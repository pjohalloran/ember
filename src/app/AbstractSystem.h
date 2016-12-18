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
			
				I32 _initPriority;
				I32 _updatePriority;
				
			protected:
			
				bool _initialized;
				
			public:
			
				AbstractSystem( int initPriority, int updatePriority ) : _initPriority( initPriority ), _updatePriority( updatePriority ), _initialized( false ) { }
				
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
				
				inline I32 InitPriority() const
				{
					return _initPriority;
				}
				
				inline I32 UpdatePriority() const
				{
					return _updatePriority;
				}
		};
	}
}

#endif
