/*
 * @file Event.cpp
 * @author PJ O Halloran
 * @date 24/01/2017
 */

#include "Event.h"

#include "app/EmberApp.h"
#include "app/TimeSystem.h"

namespace ember
{
	namespace events
	{
		using namespace ember::core;
		using namespace ember::app;
		
		Event::Event( StringHash id, U32 argCount ) : Id( id ), ArgCount( argCount ), Timestamp( 0.0F )
		{
			DCHECK_LE_F( argCount, MaxArgs, "An event can only have maximum %i args", MaxArgs );
			
			for ( U32 i = 0; i < ArgCount; ++i )
			{
				Data[i].Clear();
			}
			
			Timestamp = Application->Time()->TimeSinceAppStart();
		}
		
		Event::Event( const Event &rhs ) : Id( rhs.Id ), ArgCount( rhs.ArgCount ), Timestamp( rhs.Timestamp )
		{
			for ( U32 i = 0; i < ArgCount; ++i )
			{
				Data[i] = rhs.Data[i];
			}
		}
	}
}
