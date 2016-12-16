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
		using ember::core;
		
		class AbstractSystem
		{
			private:
			
				I32 _id;
				I32 _priority;
				
			public:
			
				AbstractSystem( int id, int priority ) : _id( id ), _priority( priority ) { }
				
				virtual void VInitialize() = 0;
				
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
