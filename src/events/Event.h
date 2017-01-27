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
			EmberVariant Data[MaxArgs];
			F64 Timestamp;
			
			Event( StringHash id, U32 argCount );
			
			Event( const Event &rhs );
			
			inline bool TryGet( const StringHash &hash, EmberVariant &data ) const
			{
				return TryGet( hash.hash_code(), data );
			}
			
			inline bool TryGet( const U64 handle, EmberVariant &data ) const
			{
				bool found = false;
				
				for ( U32 i = 0; ( i < ArgCount ) && !found; ++i )
				{
					if ( Data[i].handle == handle )
					{
						data = Data[i];
						found = true;
					}
				}
				
				return found;
			}
			
			inline EmberVariant &operator []( const I32 index )
			{
				DCHECK_GE_F( index, 0, "out of bounds lower" );
				DCHECK_LT_F( index, ArgCount, "out of bounds upper" );
				
				return Data[index];
			};
			
			Event *Clone()
			{
				return new Event( *this );
			};
		};
	}
}

#endif
