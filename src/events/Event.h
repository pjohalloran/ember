#pragma once
#ifndef __EMBER_EVENT_DATA_H
#define __EMBER_EVENT_DATA_H

/*
 * @file Event.h
 * @author PJ O Halloran
 * @date 4/01/2017
 */

#include "core/Ember.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		
		struct Event
		{
			static constexpr U32 MaxArgs = 8;
			
			StringHash Id;
			U32 ArgCount;
			U64 Keys[MaxArgs];
			EmberVariant Data[MaxArgs];
			
			Event( StringHash id, U32 argCount ) : Id( id )
			{
				DCHECK_LE_F( argCount, MaxArgs, "An event can only have maximum %i args", MaxArgs );
				
				ArgCount = argCount;
				memset( Keys, 0, sizeof( U64 ) * ArgCount );
				memset( Data, 0, sizeof( EmberVariant ) * ArgCount );
			}
			
			Event *Clone()
			{
				// return deep copy of event
				return nullptr;
			};
		};
	}
}

#endif
